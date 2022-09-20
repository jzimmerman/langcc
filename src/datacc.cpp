#include "datacc.hpp"

#include "data.hpp"
#include "cc.hpp"

struct DataCompileContext {
    CppGenContext cc_;

    Map_T<GenName, Map_T<IdBase, GenName>> sum_cases_;
    Map_T<GenName, pair<GenName, IdBase>> sum_cases_rev_;
    Map_T<GenName, data::Node::Decl::Data_T> data_leaves_;
    Map_T<GenName, data::Node::Decl::Enum_T> enum_leaves_;
    Map_T<GenName, GenName> ns_defs_;
    Map_T<GenName, GenName> param_src_;

    Vec_T<string> includes_;

    inline DataCompileContext() {
        sum_cases_ = make_rc<Map<GenName, Map_T<IdBase, GenName>>>();
        sum_cases_rev_ = make_rc<Map<GenName, pair<GenName, IdBase>>>();
        data_leaves_ = make_rc<Map<GenName, data::Node::Decl::Data_T>>();
        enum_leaves_ = make_rc<Map<GenName, data::Node::Decl::Enum_T>>();
        ns_defs_ = make_rc<Map<GenName, GenName>>();
        param_src_ = make_rc<Map<GenName, GenName>>();
        includes_ = make_rc<Vec<string>>();
    }

    DataCompileContext(const DataCompileContext&) = delete;
    DataCompileContext(DataCompileContext&&) = delete;
    DataCompileContext& operator=(const DataCompileContext&) = delete;

    inline Vec_T<cc::Node_T> cpp_tabulate_template_params(lang::data::Node::Decl::Data_T ty);

    inline Vec_T<pair<GenName, Option_T<IdBase>>> dt_ancestors(const GenName& dt) {
        GenName dt_curr = dt;
        auto ret = make_rc<Vec<pair<GenName, Option_T<IdBase>>>>();
        auto sel = None<IdBase>();

        while (true) {
            if (!data_leaves_->contains_key(dt_curr)) {
                LG_ERR("Not found: {}", dt_curr);
                AX();
            }

            ret->push(make_pair(dt_curr, sel));
            if (!sum_cases_rev_->contains_key(dt_curr)) {
                break;
            }
            sel = Some<IdBase>(sum_cases_rev_->operator[](dt_curr).second);
            dt_curr = sum_cases_rev_->operator[](dt_curr).first;
        }
        ret->reverse();
        return ret;
    }

    inline Option_T<Vec_T<IdBase>> resolve_ancestor_sel(GenName a, GenName x) {
        auto ret = make_rc<Vec<IdBase>>();
        bool active = false;
        auto anc = this->dt_ancestors(x);
        for (auto [nm, sel] : *anc) {
            if (val_hash(nm) == val_hash(a)) {
                active = true;
            }
            if (active && sel.is_some()) {
                ret->push(sel.as_some());
            }
        }
        if (active) {
            return Some<Vec_T<IdBase>>(ret);
        }
        return None<Vec_T<IdBase>>();
    }

    inline bool is_ancestor(GenName a, GenName x) {
        return resolve_ancestor_sel(a, x).is_some();
    }
};


cc::Node_T lower_name_cpp(LowerTy lt, const GenName& name, DataCompileContext& ctx,
    Option_T<GenName> name_aux = None<GenName>(),
    Option_T<Vec_T<cc::Node_T>> cpp_template_params = None<Vec_T<cc::Node_T>>());

inline Vec_T<cc::Node_T> DataCompileContext::cpp_tabulate_template_params(
    lang::data::Node::Decl::Data_T ty) {

    auto ret = make_rc<Vec<cc::Node_T>>();
    if (ty->params_.is_some()) {
        for (const auto& param : *ty->params_.as_some()) {
            ret->push_back(cc_.Q_->qq("Expr", param->name_.to_std_string()));
        }
    }
    return ret;
}


GenName data_id_to_name(const Vec_T<StrSlice>& items) {
    auto ret = make_rc<Vec<IdBase>>();
    for (auto id_base : *items) {
        ret->push(id_base.to_std_string());
    }
    return ret;
}


inline bool has_mod_mut(data::Node::Decl::Data_T x) {
    for (auto mod : *x->mods_) {
        if (mod->is_Mut()) {
            return true;
        }
    }
    return false;
}


inline bool has_mod_xform(data::Node::Decl::Data_T x) {
    for (auto mod : *x->mods_) {
        if (mod->is_Xform()) {
            return true;
        }
    }
    return false;
}


inline bool has_mod_visit(data::Node::Decl::Data_T x) {
    for (auto mod : *x->mods_) {
        if (mod->is_Visit()) {
            return true;
        }
    }
    return false;
}


inline bool data_id_is_vec(data::Node::Id_T x) {
    return val_hash(data_id_to_name(x->items_)) == val_hash(name_lit({"Vec"}));
}


inline bool data_id_is_option(data::Node::Id_T x) {
    return val_hash(data_id_to_name(x->items_)) == val_hash(name_lit({"Option"}));
}


void tabulate_data_decl_acc(
    data::Node_T src, const GenName& ns, DataCompileContext& ctx) {

    auto decl = src->as_Decl();

    if (decl->is_Include()) {
        ctx.includes_->push_back(decl->as_Include()->path_.to_std_string());

    } else if (decl->is_Namespace()) {
        auto ns_new = ns->with_extend(data_id_to_name(decl->as_Namespace()->name_->items_));
        for (auto decl : *decl->as_Namespace()->body_) {
            tabulate_data_decl_acc(decl, ns_new, ctx);
        }

    } else if (decl->is_Data()) {
        auto dd = decl->as_Data();

        Int n = dd->name_->items_->length();
        AT(n >= 1);
        auto is_sum_case = n >= 2;
        auto id_base = dd->name_->items_->slice(0, 1);
        auto id_sel = dd->name_->items_->slice(1, n);

        auto dd_name = ns->with_extend(data_id_to_name(id_base));
        auto dd_name_full = dd_name->with_extend(data_id_to_name(id_sel));
        auto [dd_name_full_sum, dd_name_full_base] = name_ns_decons(dd_name_full);

        if (dd->base_.is_some()) {
            dd_name_full_sum = ns->with_extend(data_id_to_name(dd->base_.as_some()->items_));
            AT(dd_name_full->length() > dd_name_full_sum->length());
            for (Int i = 0; i < dd_name_full_sum->length(); i++) {
                if (val_hash(dd_name_full_sum->operator[](i)) !=
                    val_hash(dd_name_full->operator[](i))) {
                    LG_ERR("Explicit sum base type must be a proper prefix:\n  got {} for {}",
                        dd_name_full_sum, dd_name_full);
                    AX();
                }
            }
            auto base_str = string("");
            bool fresh = true;
            for (Int i = dd_name_full_sum->length(); i < dd_name_full->length(); i++) {
                if (!fresh) {
                    base_str += "__";
                }
                fresh = false;
                base_str += dd_name_full->operator[](i);
            }
            dd_name_full_base = base_str;
        }

        if (dd->params_.is_some()) {
            for (const auto& param : *dd->params_.as_some()) {
                ctx.param_src_->insert_strict(
                    dd_name_full->with_append_rc(param->name_.to_std_string()),
                    dd_name_full);
            }
        }

        if (is_sum_case) {
            if (!ctx.sum_cases_->contains_key(dd_name_full_sum)) {
                ctx.sum_cases_->insert_strict(
                    dd_name_full_sum->clone_rc(), make_rc<Map<IdBase, GenName>>());
            }
            auto& cases_i = ctx.sum_cases_->operator[](dd_name_full_sum->clone_rc());
            cases_i->insert(dd_name_full_base, dd_name_full);
            ctx.sum_cases_rev_->insert_strict(
                dd_name_full->clone_rc(),
                make_pair(dd_name_full_sum->clone_rc(), dd_name_full_base));
        }

        ctx.data_leaves_->insert_strict(dd_name_full->clone_rc(), dd);
        ctx.ns_defs_->insert_strict(dd_name_full->clone_rc(), ns->clone_rc());

    } else if (decl->is_Enum()) {
        auto dd = decl->as_Enum();
        auto dd_name = ns->with_extend(data_id_to_name(dd->name_->items_));
        ctx.enum_leaves_->insert_strict(dd_name->clone_rc(), dd);
        ctx.ns_defs_->insert_strict(dd_name->clone_rc(), ns->clone_rc());

    } else {
        AX("{}", decl);
    }
}


Option_T<pair<GenName, bool>> ns_resolve(
    const GenName& ns, const GenName& name, DataCompileContext& ctx) {

    for (Int i = ns->length(); i >= 0; i--) {
        auto name_cand = ns->slice(0, i)->with_extend(name);
        if (ctx.sum_cases_->contains_key(name_cand)) {
            return Some(make_pair(name_cand, true));
        } else if (ctx.enum_leaves_->contains_key(name_cand)) {
            return Some(make_pair(name_cand, false));
        } else if (ctx.data_leaves_->contains_key(name_cand)) {
            auto is_indirect = true;
            return Some(make_pair(name_cand, is_indirect));
        } else if (name->length() == 1 && ctx.param_src_->contains_key(name_cand)) {
            auto name_s = make_rc<Vec<string>>();
            name_s->push_back(name->only());
            return Some(make_pair(name_s, false));
        }
    }

    return None<pair<GenName, bool>>();
}


inline IdBase name_sep_to_join(const GenName& name, const string& delim) {
    bool fresh = true;
    string ret;
    for (const auto& id : *name) {
        if (!fresh) {
            ret += delim;
        }
        fresh = false;
        ret += id;
    }
    return ret;
}



inline IdBase name_sep_to_underscores(const GenName& name) {
    return name_sep_to_join(name, "_");
}


GenName lower_name(LowerTy lt, const GenName& name, Option_T<GenName> name_aux) {
    if (lt == LowerTy::DIRECT) {
        return name;
    } else if (lt == LowerTy::STRUCT) {
        return name->with_append_rc("_T");
    } else if (lt == LowerTy::WHICH_ENUM) {
        return name->with_append_rc("_W");
    } else if (lt == LowerTy::STRUCT_RC_ALIAS) {
        auto [name_ns, name_base] = name_ns_decons(name);
        return name_ns_cons(name_ns, name_base + "_T");
    } else if (lt == LowerTy::CTOR_FULL) {
        return name_ns_cons(name_ns_cons(name, "_T"), "_T");
    } else if (lt == LowerTy::CTOR_BASE) {
        return name_lit({"_T"});
    } else if (lt == LowerTy::MAKE_FULL) {
        return name_ns_cons(name, "make");
    } else if (lt == LowerTy::MAKE_EXT_FULL) {
        return name_ns_cons(name, "make_ext");
    } else if (lt == LowerTy::WITH_FULL) {
        return name_ns_cons(
            name->with_append_rc("_T"), fmt_str("with_{}", name_aux.as_some()->only()));
    } else if (lt == LowerTy::WITH_BASE) {
        auto ret = make_rc<Vec<IdBase>>();
        ret->push(fmt_str("with_{}", name_aux.as_some()->only()));
        return ret;
    } else if (lt == LowerTy::SUM_IS_FULL) {
        return name_ns_cons(
            name->with_append_rc("_T"), fmt_str("is_{}", name_aux.as_some()->only()));
    } else if (lt == LowerTy::SUM_IS_BASE) {
        auto ret = make_rc<Vec<IdBase>>();
        ret->push(fmt_str("is_{}", name_aux.as_some()->only()));
        return ret;
    } else if (lt == LowerTy::SUM_AS_FULL) {
        return name_ns_cons(
            name->with_append_rc("_T"), fmt_str("as_{}", name_aux.as_some()->only()));
    } else if (lt == LowerTy::SUM_AS_BASE) {
        auto ret = make_rc<Vec<IdBase>>();
        ret->push(fmt_str("as_{}", name_aux.as_some()->only()));
        return ret;
    } else if (lt == LowerTy::HASH_SER_ACC_INST_FULL) {
        return name_ns_cons(
            name->with_append_rc("_T"),
            fmt_str("hash_ser_acc_{}", name_sep_to_underscores(name)));
    } else if (lt == LowerTy::HASH_SER_ACC_INST_BASE) {
        auto ret = make_rc<Vec<IdBase>>();
        ret->push(fmt_str("hash_ser_acc_{}", name_sep_to_underscores(name)));
        return ret;
    } else if (lt == LowerTy::HASH_SER_ACC_FULL) {
        return name_ns_cons(name->with_append_rc("_T"), "hash_ser_acc");
    } else if (lt == LowerTy::HASH_SER_ACC_BASE) {
        auto ret = make_rc<Vec<IdBase>>();
        ret->push("hash_ser_acc");
        return ret;
    } else if (lt == LowerTy::WRITE_BASE) {
        auto ret = make_rc<Vec<IdBase>>();
        ret->push(fmt_str("write"));
        return ret;
    } else {
        AX();
    }
}


cc::Node_T lower_name_cpp(LowerTy lt, const GenName& name, DataCompileContext& ctx,
    Option_T<GenName> name_aux,
    Option_T<Vec_T<cc::Node_T>> cpp_template_params) {

    auto name_low = lower_name(lt, name, name_aux);
    if (cpp_template_params.is_some()) {
        cc::Node_T ret = name_to_cpp_direct(
            name_low->slice(0, name_low->length()-1), ctx.cc_);
        if (cpp_template_params.is_some()) {
            ret = ctx.cc_.gen_cpp_id_with_template_args_acc(ret, cpp_template_params.as_some());
        }
        ret = cpp_name_with_append(ctx.cc_, ret, name_low->operator[](name_low->length()-1));
        return ret;
    } else {
        return name_to_cpp_direct(name_low, ctx.cc_);
    }
}


Map<GenName, GenName>& builtins_cpp() {
    static bool _init = false;
    static Map<GenName, GenName> ret;
    if (_init) {
        return ret;
    }
    ret.insert(name_lit({"bool"}), name_lit({"bool"}));
    ret.insert(name_lit({"Int"}), name_lit({"Int"}));
    ret.insert(name_lit({"u32"}), name_lit({"u32"}));
    ret.insert(name_lit({"IntPair"}), name_lit({"IntPair"}));
    ret.insert(name_lit({"Str"}), name_lit({"string"}));
    ret.insert(name_lit({"StrSlice"}), name_lit({"StrSlice"}));
    ret.insert(name_lit({"Char"}), name_lit({"Ch"}));
    ret.insert(name_lit({"Unit"}), name_lit({"Unit"}));
    ret.insert(name_lit({"Vec"}), name_lit({"Vec_T"}));
    ret.insert(name_lit({"Set"}), name_lit({"Set_T"}));
    ret.insert(name_lit({"Map"}), name_lit({"Map_T"}));
    ret.insert(name_lit({"VecUniq"}), name_lit({"VecUniq_T"}));
    ret.insert(name_lit({"Option"}), name_lit({"Option_T"}));
    _init = true;
    return ret;
}


GenName resolve_builtin_cpp(const GenName& name) {
    for (const auto& builtin : builtins_cpp()) {
        if (val_hash(name) == val_hash(builtin.first)) {
            return builtin.second;
        }
    }
    LG_ERR("GenName not found: {}", name);
    AX();
}


cc::Node_T data_type_expr_to_cpp(
    data::Node::Expr_T x, const GenName& ns, DataCompileContext& ctx) {

    if (x->is_Id()) {
        auto xc = x->as_Id()->x_;
        auto name = data_id_to_name(xc->items_);

        auto name_full_pair = ns_resolve(ns, name, ctx);
        if (name_full_pair.is_some()) {
            auto& name_full = name_full_pair.as_some().first;
            auto is_indirect = name_full_pair.as_some().second;
            if (is_indirect) {
                return lower_name_cpp(LowerTy::STRUCT_RC_ALIAS, name_full, ctx);
            } else {
                return lower_name_cpp(LowerTy::DIRECT, name_full, ctx);
            }
        } else {
            auto name_res = name;
            if (!x->as_Id()->ext_) {
                name_res = resolve_builtin_cpp(name);
            }
            auto ret = name_to_cpp_direct(name_res, ctx.cc_);
            return ret;
        }

    } else if (x->is_App()) {
        auto xc = x->as_App();

        auto lex_args = ctx.cc_.Q_->make_lex_builder();

        auto cpp_f = data_type_expr_to_cpp(xc->f_, ns, ctx);
        ctx.cc_.Q_->qq_args_acc(lex_args, cpp_f, "<");
        bool fresh = true;
        for (auto arg : *xc->args_) {
            if (!fresh) {
                ctx.cc_.Q_->qq_args_acc(lex_args, ",");
            }
            auto cpp_arg = data_type_expr_to_cpp(arg, ns, ctx);
            ctx.cc_.Q_->qq_args_acc(lex_args, cpp_arg);
            fresh = false;
        }
        ctx.cc_.Q_->qq_args_acc(lex_args, ">");
        return ctx.cc_.Q_->qq_inner(Some<string>("Expr"), lex_args);

    } else {
        AX("{}", x);
    }
}


pair<
    Vec_T<pair<IdBase, data::Node::Field_T>>,
    Vec_T<pair<IdBase, data::Node::Field_T>>>
dt_extract_def_fields_full(GenName curr, DataCompileContext& ctx) {

    auto dt = ctx.data_leaves_->operator[](curr);
    auto fields_full = make_rc<Vec<pair<IdBase, data::Node::Field_T>>>();
    auto fields_proper = make_rc<Vec<pair<IdBase, data::Node::Field_T>>>();
    auto fields_full_s = make_rc<Set<IdBase>>();
    auto anc = ctx.dt_ancestors(curr);
    AR_ge(anc->length(), 1);
    for (const auto& [q, _] : *anc) {
        auto q_dt = ctx.data_leaves_->operator[](q);
        for (const auto& data_field : *q_dt->fields_) {
            auto data_field_name = data_field->name_.to_std_string();
            if (fields_full_s->contains(data_field_name)) {
                LG_ERR("Field {} is shadowed by datatype {}\n",
                    data_field_name, name_sep_to_underscores(curr));
                AX();
            }
            fields_full_s->insert(data_field_name);
            fields_full->push_back(make_pair(data_field_name, data_field));
        }
    }
    for (const auto& data_field : *dt->fields_) {
        auto data_field_name = data_field->name_.to_std_string();
        fields_proper->push_back(make_pair(data_field_name, data_field));
    }
    return make_pair(fields_full, fields_proper);
}


enum struct XformTy {
    Xform,
    Visit,
};


IdBase xform_ty_gen_cpp_fn_name(XformTy xform_ty, GenName star, bool top_ty) {
    if (xform_ty == XformTy::Xform) {
        if (top_ty) {
            return fmt_str("xformT_{}", name_sep_to_underscores(star));
        } else {
            return fmt_str("xform_{}", name_sep_to_underscores(star));
        }
    } else if (xform_ty == XformTy::Visit) {
        return fmt_str("visit_{}", name_sep_to_underscores(star));
    } else {
        AX();
    }
}


void data_gen_xform_fn(
    XformTy xform_ty,
    GenName star,
    GenName curr,
    Set_T<GenName>& vis,
    DataCompileContext& ctx);

Option_T<cc::Node_T> lower_xform_field_entry(
    XformTy xform_ty,
    GenName star, GenName curr, Set_T<GenName> vis,
    Vec_T<cc::Node_T>& dst, cc::Node_T src, cc::Node_T src_f,
    data::Node::Expr_T ty, const GenName& src_ns, const GenName& gen_ns,
    DataCompileContext& ctx) {

    if (ty->is_Id()) {
        auto xc = ty->as_Id()->x_;
        auto name = data_id_to_name(xc->items_);

        auto name_full_pair = ns_resolve(src_ns, name, ctx);
        if (name_full_pair.is_some()) {
            auto& name_full = name_full_pair.as_some().first;
            auto is_indirect = name_full_pair.as_some().second;

            if (is_indirect) {
                data_gen_xform_fn(xform_ty, star, name_full, vis, ctx);
                auto top_ty = !ctx.is_ancestor(star, name_full);
                if (xform_ty == XformTy::Xform) {
                    auto ret = ctx.cc_.gen_cpp_decl_var_init(
                        dst, gen_ns, lower_name_cpp(LowerTy::STRUCT_RC_ALIAS, name_full, ctx),
                        "y", xform_ty_gen_cpp_fn_name(xform_ty, star, top_ty),
                        "(", src, ",", src_f, ")");
                    return Some<cc::Node_T>(ret);
                } else {
                    ctx.cc_.qq_stmt_acc(dst, xform_ty_gen_cpp_fn_name(xform_ty, star, top_ty),
                        "(", src, ",", src_f, ");");
                    return None<cc::Node_T>();
                }

            } else {
                return Some<cc::Node_T>(src);
            }
        } else {
            if (!ty->as_Id()->ext_) {
                resolve_builtin_cpp(name);
            }
            return Some<cc::Node_T>(src);
        }

    } else if (ty->is_App()) {
        auto xc = ty->as_App();
        if (!xc->f_->is_Id()) {
            LG_ERR("Multiple template invocations not supported"); AX();
        }
        auto f = data_id_to_name(xc->f_->as_Id()->x_->items_);

        if (val_hash(f) == val_hash(name_lit({"Vec"}))) {
            if (xc->args_->length() != 1) {
                LG_ERR("Template constructor `Vec` takes exactly one argument"); AX();
            }
            auto arg = xc->args_->operator[](0);
            auto arg_ty = data_type_expr_to_cpp(arg, src_ns, ctx);

            auto ret = None<cc::Node_T>();
            if (xform_ty == XformTy::Xform) {
                ret = Some<cc::Node_T>(ctx.cc_.gen_cpp_decl_var_init(
                    dst, gen_ns, "auto", "ret", "make_rc<Vec<", arg_ty, ">>()"));
            }

            auto loop_ind = ctx.cc_.gen_cpp_decl_var_init(dst, gen_ns, "Int", "i", "0");
            auto loop_body = make_rc<Vec<cc::Node_T>>();
            auto ret_i = lower_xform_field_entry(xform_ty, star, curr, vis, loop_body,
                ctx.cc_.qq("Expr", src, "->at_unchecked(", loop_ind, ")"), src_f, arg,
                src_ns, gen_ns, ctx);

            if (xform_ty == XformTy::Xform) {
                loop_body->push_back(ctx.cc_.qq("Stmt", ret.as_some(), "->push_back(",
                    ret_i.as_some(), ");"));
            }

            auto loop = ctx.cc_.qq("Stmt",           
                "for (", loop_ind, "= 0; ", loop_ind, "_LT_", src, "->length(); ",
                loop_ind, "++) {",
                *loop_body, "}");
            dst->push_back(loop);
            return ret;

        } else if (val_hash(f) == val_hash(name_lit({"Option"}))) {
            if (xc->args_->length() != 1) {
                LG_ERR("Template constructor `Option` takes exactly one argument"); AX();
            }
            auto arg = xc->args_->operator[](0);
            auto arg_ty = data_type_expr_to_cpp(arg, src_ns, ctx);

            auto ret = None<cc::Node_T>();
            if (xform_ty == XformTy::Xform) {
                ret = Some<cc::Node_T>(ctx.cc_.gen_cpp_decl_var_init(
                    dst, gen_ns, "auto", "ret", "None<", arg_ty, ">()"));
            }

            auto if_body = make_rc<Vec<cc::Node_T>>();

            auto ret_i = lower_xform_field_entry(xform_ty, star, curr, vis, if_body,
                ctx.cc_.qq("Expr", src, ".as_some()"), src_f, arg, src_ns, gen_ns, ctx);

            if (xform_ty == XformTy::Xform) {
                if_body->push_back(
                    ctx.cc_.qq("Stmt", ret.as_some(), "= Some<", arg_ty, ">(",
                    ret_i.as_some(), ");"));
            }

            dst->push_back(ctx.cc_.qq("Stmt", "if (", src, ".is_some()) {", *if_body, "}"));
            return ret;

        } else {
            LG_ERR("Template name not supported in lower_xform_field_entry: {}",
                name_sep_to_join(f, "::")); AX();
        }

    } else {
        AX("{}", ty);
    }
}


void data_gen_xform_fn(
    XformTy xform_ty,
    GenName star,
    GenName curr,
    Set_T<GenName>& vis,
    DataCompileContext& ctx) {

    if (vis->contains(curr)) {
        return;
    }
    vis->insert(curr);

    auto star_dt = ctx.data_leaves_->operator[](star);
    auto curr_dt = ctx.data_leaves_->operator[](curr);

    if (curr_dt->params_.is_some() || star_dt->params_.is_some()) {
        AX("Type parameters on xform types not supported");
    }

    auto is_sum = ctx.sum_cases_->contains_key(curr);

    auto cpp_struct_decl_ptr_name_star = lower_name_cpp(LowerTy::STRUCT_RC_ALIAS, star, ctx);
    auto cpp_struct_decl_ptr_name_curr = lower_name_cpp(LowerTy::STRUCT_RC_ALIAS, curr, ctx);

    auto id_xform_fun_ns = name_lit({ctx.cc_.gen_id_fresh(name_lit({}), "__anon__"),});
    auto id_xform_name_full = name_lit({xform_ty_gen_cpp_fn_name(xform_ty, star, true)});
    auto cpp_xform_name_full = name_to_cpp_direct(id_xform_name_full, ctx.cc_);
    auto cpp_xform_params = make_rc<Vec<cc::Node_T>>();
    auto cpp_xform_body = make_rc<Vec<cc::Node_T>>();
    auto cpp_xform_param_x_var = ctx.cc_.gen_cpp_param_acc<cc::Node_T>(
        cpp_xform_params, id_xform_fun_ns, cpp_struct_decl_ptr_name_curr, "x");

    auto cpp_xform_param_f_ty = ctx.cc_.qq("Expr", "function<", cpp_struct_decl_ptr_name_star, "(",
        cpp_struct_decl_ptr_name_star, ")>");
    if (xform_ty == XformTy::Visit) {
        cpp_xform_param_f_ty = ctx.cc_.qq_expr(
            "function<void(", cpp_struct_decl_ptr_name_star, ")>");
    }
    auto cpp_xform_param_f_var = ctx.cc_.gen_cpp_param_acc<cc::Node_T>(
        cpp_xform_params, id_xform_fun_ns, cpp_xform_param_f_ty, "f");

    if (is_sum) {
        auto cpp_switch_cases = make_rc<Vec<cc::Node_T>>();
        for (const auto& [sum_case, sum_case_name] : *ctx.sum_cases_->operator[](curr)) {
            data_gen_xform_fn(xform_ty, star, sum_case_name, vis, ctx);
            auto switch_case_body = make_rc<Vec<cc::Node_T>>();

            cc::Node_T cpp_v;
            if (xform_ty == XformTy::Xform) {
                cpp_v = ctx.cc_.gen_cpp_decl_var_init(
                    switch_case_body, id_xform_fun_ns, ctx.cc_.qq_expr("auto"), "ret",
                    xform_ty_gen_cpp_fn_name(xform_ty, star, true),
                    "(", cpp_xform_param_x_var,
                    "->", lower_name_cpp(LowerTy::SUM_AS_BASE, curr, ctx,
                    Some(name_lit({sum_case,}))), "()",
                    ",", cpp_xform_param_f_var, ")");
            } else if (xform_ty == XformTy::Visit) {
                ctx.cc_.qq_stmt_acc(switch_case_body,
                    xform_ty_gen_cpp_fn_name(xform_ty, star, true),
                    "(", cpp_xform_param_x_var,
                    "->", lower_name_cpp(
                        LowerTy::SUM_AS_BASE, curr, ctx, Some(name_lit({sum_case,}))), "()",
                    ",", cpp_xform_param_f_var, ");");
                cpp_v = cpp_xform_param_x_var;
            } else {
                AX();
            }
            if (xform_ty == XformTy::Xform) {
                ctx.cc_.qq_stmt_acc(switch_case_body, "return", cpp_v, ";");
            }
            cpp_switch_cases->push_back(
                ctx.cc_.qq("SwitchCase", "case", lower_name_cpp(LowerTy::WHICH_ENUM, curr, ctx),
                    "::", sum_case, ": {", *switch_case_body, "break; }")->as_SwitchCase());
        }
        cpp_switch_cases->push_back(ctx.cc_.qq("SwitchCase", "default: { AX(); }"));
        cpp_xform_body->push_back(
            ctx.cc_.qq("Stmt", "switch (", cpp_xform_param_x_var, "->w_", ") {",
                *cpp_switch_cases, "}"));

    } else {
        auto cpp_make_args = make_rc<Vec<cc::Node_T>>();
        auto [fields_full, _] = dt_extract_def_fields_full(curr, ctx);
        for (const auto& [__, q] : *fields_full) {
            auto field_name = q->name_;
            auto cpp_field_proj = ctx.cc_.qq(
                "Expr", cpp_xform_param_x_var, "->", fmt_str("{}_", field_name));
            auto field_type = q->type__;
            auto cpp_field_item = lower_xform_field_entry(
                xform_ty, star, curr, vis, cpp_xform_body, cpp_field_proj,
                cpp_xform_param_f_var, field_type, curr, id_xform_fun_ns, ctx);

            if (xform_ty == XformTy::Xform) {
                cpp_make_args->push_back(cpp_field_item.as_some());
            }
        }

        cc::Node_T cpp_v;
        if (xform_ty == XformTy::Xform) {
            auto cpp_make_call = ctx.cc_.gen_cpp_fun_call(
                lower_name_cpp(LowerTy::MAKE_FULL, curr, ctx), cpp_make_args);
            cpp_v = ctx.cc_.gen_cpp_decl_var_init(
                cpp_xform_body, id_xform_fun_ns, cpp_struct_decl_ptr_name_curr, "z",
                cpp_make_call);
        } else if (xform_ty == XformTy::Visit) {
            cpp_v = cpp_xform_param_x_var;
        }
        if (ctx.is_ancestor(star, curr)) {
            if (xform_ty == XformTy::Xform) {
                cpp_v = ctx.cc_.qq_expr(cpp_xform_param_f_var, "(", cpp_v, ")");
            } else if (xform_ty == XformTy::Visit) {
                ctx.cc_.qq_stmt_acc(cpp_xform_body, cpp_xform_param_f_var, "(", cpp_v, ");");
            } else {
                AX();
            }
        }
        if (xform_ty == XformTy::Xform) {
            cpp_xform_body->push_back(ctx.cc_.qq("Stmt", "return", cpp_v, ";"));
        }
    }

    auto cpp_template_params = make_rc<Vec<cc::Node_T>>();

    auto ret_ty = Some<cc::Node_T>(cpp_struct_decl_ptr_name_curr);
    if (ctx.is_ancestor(star, curr)) {
        ret_ty = Some<cc::Node_T>(cpp_struct_decl_ptr_name_star);
    }
    if (xform_ty == XformTy::Visit) {
        ret_ty = Some<cc::Node_T>(ctx.cc_.qq_expr("void"));
    }

    ctx.cc_.dst_decls_->push_back(
        ctx.cc_.gen_cpp_fun_proto_decl(
            cpp_template_params,
            NodeV_empty(),
            ret_ty,
            id_xform_name_full,
            cpp_xform_params)->as_Decl());

    ctx.cc_.push_def(cpp_template_params,
        ctx.cc_.gen_cpp_fun_body(
            cpp_template_params,
            NodeV_empty(),
            ret_ty,
            cpp_xform_name_full,
            cpp_xform_params,
            NodeV_empty(),
            cpp_xform_body)->as_Decl());
}


void data_gen_xform_id_fn(
    GenName star,
    GenName curr,
    DataCompileContext& ctx) {

    auto star_dt = ctx.data_leaves_->operator[](star);
    auto curr_dt = ctx.data_leaves_->operator[](curr);

    if (curr_dt->params_.is_some() || star_dt->params_.is_some()) {
        AX("Type parameters on xform types not supported");
    }

    auto cpp_struct_decl_ptr_name_star = lower_name_cpp(LowerTy::STRUCT_RC_ALIAS, star, ctx);
    auto cpp_struct_decl_ptr_name_curr = lower_name_cpp(LowerTy::STRUCT_RC_ALIAS, curr, ctx);

    auto cpp_template_params = make_rc<Vec<cc::Node_T>>();

    auto ret_ty = cpp_struct_decl_ptr_name_curr;

    auto id_xform_fun_ns = name_lit({ctx.cc_.gen_id_fresh(name_lit({}), "__anon__"),});
    auto id_xform_name_full = name_lit({xform_ty_gen_cpp_fn_name(XformTy::Xform, star, false),});
    auto cpp_xform_name_full = name_to_cpp_direct(id_xform_name_full, ctx.cc_);
    auto cpp_xform_params = make_rc<Vec<cc::Node_T>>();
    auto cpp_xform_body = make_rc<Vec<cc::Node_T>>();
    auto cpp_xform_param_x_var = ctx.cc_.gen_cpp_param_acc<cc::Node_T>(
        cpp_xform_params, id_xform_fun_ns, cpp_struct_decl_ptr_name_curr, "x");
    auto cpp_xform_param_f_ty = ctx.cc_.qq("Expr", "function<", cpp_struct_decl_ptr_name_star, "(",
        cpp_struct_decl_ptr_name_star, ")>");
    auto cpp_xform_param_f_var = ctx.cc_.gen_cpp_param_acc<cc::Node_T>(
        cpp_xform_params, id_xform_fun_ns, cpp_xform_param_f_ty, "f");

    auto ret = ctx.cc_.gen_cpp_decl_var_init(
        cpp_xform_body, id_xform_fun_ns, cpp_struct_decl_ptr_name_star, "ret",
        xform_ty_gen_cpp_fn_name(XformTy::Xform, star, true),
        "(", cpp_xform_param_x_var, ",", cpp_xform_param_f_var, ")");

    auto sel_m = ctx.resolve_ancestor_sel(star, curr);
    AT(sel_m.is_some());
    auto sel = sel_m.as_some();
    for (auto sel_i : *sel) {
        ret = ctx.cc_.qq_expr(ret, "->", fmt_str("as_{}", sel_i), "()");
    }

    ctx.cc_.qq_stmt_acc(cpp_xform_body, "return", ret, ";");

    ctx.cc_.dst_decls_->push_back(
        ctx.cc_.gen_cpp_fun_proto_decl(
            cpp_template_params,
            NodeV_empty(),
            Some<cc::Node_T>(ret_ty),
            id_xform_name_full,
            cpp_xform_params)->as_Decl());

    ctx.cc_.push_def(cpp_template_params,
        ctx.cc_.gen_cpp_fun_body(
            cpp_template_params,
            NodeV_empty(),
            Some<cc::Node_T>(ret_ty),
            cpp_xform_name_full,
            cpp_xform_params,
            NodeV_empty(),
            cpp_xform_body)->as_Decl());
}


DataDefsResult compile_data_defs(
    lang::data::Node_T src, Option_T<string> header_name, bool gen_write_proto) {

    DataCompileContext ctx;

    auto ns_top = make_rc<Vec<IdBase>>();
    for (auto src_decl : *src->as_Module()->decls_) {
        tabulate_data_decl_acc(src_decl, ns_top, ctx);
    }

    ctx.cc_.dst_decls_->push_back(
        ctx.cc_.Q_->qq_ext(Some<string>("Decl"), "#pragma once")->as_Decl());

    ctx.cc_.dst_decls_->push_back(ctx.cc_.Q_->qq_ext(Some<string>("Decl"),
        "#include", "\"langcc_util.hpp\"")->as_Decl());

    for (auto path : *ctx.includes_) {
        ctx.cc_.dst_decls_->push_back(ctx.cc_.Q_->qq_ext(Some<string>("Decl"),
            "#include", path)->as_Decl());
    }

    if (header_name.is_some()) {
        ctx.cc_.dst_defs_->push_back(ctx.cc_.Q_->qq_ext(Some<string>("Decl"),
            "#include", fmt_str("\"{}\"", header_name.as_some()))->as_Decl());
    }

    for (const auto& p : *ctx.enum_leaves_) {
        auto name_full = p.first;

        auto cpp_enum_cases = make_rc<Vec<cc::Node_T>>();
        for (const auto& data_case : *p.second->cases_) {
            cpp_enum_cases->push_back(ctx.cc_.gen_cpp_id_base(data_case.to_std_string()));
        }

        // enum struct E {...}
        ctx.cc_.dst_decls_->push_back(
            ctx.cc_.gen_cpp_decl_enum(name_full, cpp_enum_cases)->as_Decl());

        // hash_ser()
        auto id_hash_ser_fun_ns = name_lit({ctx.cc_.gen_id_fresh(name_lit({}), "__anon__"),});
        auto id_hash_ser_name_full = name_lit({"hash_ser",});
        auto cpp_hash_ser_name_full = name_to_cpp_direct(id_hash_ser_name_full, ctx.cc_);
        auto cpp_hash_ser_params = make_rc<Vec<cc::Node_T>>();
        auto cpp_hash_ser_body = make_rc<Vec<cc::Node_T>>();
        auto id_hash_ser_param_buf = ctx.cc_.gen_id_fresh(id_hash_ser_fun_ns, "buf");
        auto cpp_hash_ser_param_buf_var = ctx.cc_.gen_cpp_id_base(id_hash_ser_param_buf);
        auto cpp_hash_ser_param_buf = ctx.cc_.Q_->qq_ext(
            Some<string>("Param"), "SerBuf&", cpp_hash_ser_param_buf_var);
        cpp_hash_ser_params->push_back(cpp_hash_ser_param_buf);
        auto id_hash_ser_param_x = ctx.cc_.gen_id_fresh(id_hash_ser_fun_ns, "x");
        auto cpp_hash_ser_param_x_var = ctx.cc_.gen_cpp_id_base(id_hash_ser_param_x);
        auto cpp_hash_ser_param_x = ctx.cc_.Q_->qq_ext(Some<string>("Param"),
            name_to_cpp_direct(name_full, ctx.cc_), cpp_hash_ser_param_x_var);
        cpp_hash_ser_params->push_back(cpp_hash_ser_param_x);
        cpp_hash_ser_body->push_back(
            ctx.cc_.Q_->qq_ext(Some<string>("Stmt"), "hash_ser(", cpp_hash_ser_param_buf_var, ",",
                "static_cast<Int>(", cpp_hash_ser_param_x_var, "));"));

        ctx.cc_.dst_decls_->push_back(
            ctx.cc_.gen_cpp_fun_proto_decl(
                NodeV_empty(),
                NodeV_empty(),
                Some(ctx.cc_.gen_cpp_id_base("void")),
                id_hash_ser_name_full,
                cpp_hash_ser_params)->as_Decl());

        ctx.cc_.dst_defs_->push_back(
            ctx.cc_.gen_cpp_fun_body(
                NodeV_empty(),
                NodeV_empty(),
                Some(ctx.cc_.gen_cpp_id_base("void")),
                cpp_hash_ser_name_full,
                cpp_hash_ser_params,
                NodeV_empty(),
                cpp_hash_ser_body)->as_Decl());


        // pr_debug()
        auto id_pr_debug_fun_ns = name_lit({ctx.cc_.gen_id_fresh(name_lit({}), "__anon__"),});
        auto id_pr_debug_name_full = name_lit({"pr_debug",});
        auto cpp_pr_debug_name_full = name_to_cpp_direct(id_pr_debug_name_full, ctx.cc_);
        auto cpp_pr_debug_params = make_rc<Vec<cc::Node_T>>();
        auto cpp_pr_debug_body = make_rc<Vec<cc::Node_T>>();
        auto cpp_pr_debug_param_os_var = ctx.cc_.gen_cpp_param_acc<string>(
            cpp_pr_debug_params, id_pr_debug_fun_ns, "ostream&", "os");
        auto cpp_pr_debug_param_flags_var = ctx.cc_.gen_cpp_param_acc<string>(
            cpp_pr_debug_params, id_pr_debug_fun_ns, "FmtFlags", "flags");
        auto cpp_pr_debug_param_x_var = ctx.cc_.gen_cpp_param_acc<cc::Node_T>(
            cpp_pr_debug_params, id_pr_debug_fun_ns, name_to_cpp_direct(name_full, ctx.cc_), "x");
        auto cpp_switch_cases = make_rc<Vec<cc::Node_T>>();
        for (const auto& data_case : *p.second->cases_) {
            cpp_switch_cases->push_back(
                ctx.cc_.qq("SwitchCase", "case", name_to_cpp_direct(name_full, ctx.cc_), "::",
                    data_case.to_std_string(), ": {",
                    "os << ", fmt_str("\"{}\"", data_case.to_std_string()), ";",
                    "break; }")->as_SwitchCase());
        }
        cpp_switch_cases->push_back(ctx.cc_.qq("SwitchCase", "default: { AX(); }"));
        cpp_pr_debug_body->push_back(
            ctx.cc_.qq("Stmt", "switch (", cpp_pr_debug_param_x_var, ") {",
                *cpp_switch_cases, "}"));

        ctx.cc_.dst_decls_->push_back(
            ctx.cc_.gen_cpp_fun_proto_decl(
                NodeV_empty(),
                NodeV_empty(),
                Some(ctx.cc_.gen_cpp_id_base("void")),
                id_pr_debug_name_full,
                cpp_pr_debug_params)->as_Decl());

        ctx.cc_.dst_defs_->push_back(
            ctx.cc_.gen_cpp_fun_body(
                NodeV_empty(),
                NodeV_empty(),
                Some(ctx.cc_.gen_cpp_id_base("void")),
                cpp_pr_debug_name_full,
                cpp_pr_debug_params,
                NodeV_empty(),
                cpp_pr_debug_body)->as_Decl());
    }

    for (const auto& p : *ctx.data_leaves_) {
        auto name_full = p.first;

        auto struct_decl_name = lower_name(LowerTy::STRUCT, name_full);
        auto cpp_struct_decl_name = lower_name_cpp(LowerTy::STRUCT, name_full, ctx);

        auto cpp_template_params = ctx.cpp_tabulate_template_params(p.second);

        auto cpp_struct_decl_name_tmpl = ctx.cc_.gen_cpp_id_with_template_args_acc(
            cpp_struct_decl_name, cpp_template_params);

        // struct E;
        ctx.cc_.dst_decls_->push_back(
            ctx.cc_.gen_cpp_decl_struct_fwd(struct_decl_name, cpp_template_params)->as_Decl());

        // using E_T = rc_ptr<E>;
        ctx.cc_.dst_decls_->push_back(ctx.cc_.gen_cpp_decl_using(
            lower_name(LowerTy::STRUCT_RC_ALIAS, name_full),
            ctx.cc_.gen_cpp_rc_ptr(cpp_struct_decl_name_tmpl),
            cpp_template_params)->as_Decl());
    }

    auto data_leaves_vec = make_rc<Vec<pair<GenName, data::Node::Decl::Data_T>>>();
    for (const auto& p : *ctx.data_leaves_) {
        data_leaves_vec->push_back(p);
    }
    vector<IntPair> data_leaves_inds;
    for (Int i = 0; i < data_leaves_vec->length(); i++) {
        auto len_i = data_leaves_vec->operator[](i).first->length();
        data_leaves_inds.push_back(make_pair(len_i, i));
    }
    std::sort(data_leaves_inds.begin(), data_leaves_inds.end());

    for (auto [_, i] : data_leaves_inds) {
        auto p = data_leaves_vec->operator[](i);

        auto name_full = p.first;

        auto struct_decl_name = lower_name(LowerTy::STRUCT, name_full);
        auto cpp_struct_decl_name = lower_name_cpp(LowerTy::STRUCT, name_full, ctx);
        auto cpp_struct_decl_ptr_name = lower_name_cpp(LowerTy::STRUCT_RC_ALIAS, name_full, ctx);

        auto cpp_template_params = ctx.cpp_tabulate_template_params(p.second);

        auto cpp_struct_decl_name_tmpl = ctx.cc_.gen_cpp_id_with_template_args_acc(
            cpp_struct_decl_name, cpp_template_params);

        bool is_sum = ctx.sum_cases_->contains_key(name_full);

        // ===== Generate decls =====

        auto cpp_fields = make_rc<Vec<cc::Node_T>>();

        auto [fields_full, fields_proper] = dt_extract_def_fields_full(p.first, ctx);

        // constructor
        auto cpp_ctor_name_full = lower_name(LowerTy::CTOR_FULL, name_full);
        auto cpp_ctor_params = make_rc<Vec<cc::Node_T>>();
        auto cpp_ctor_body = make_rc<Vec<cc::Node_T>>();
        auto cpp_ctor_init_exprs = make_rc<Vec<cc::Node_T>>();
        if (is_sum) {
            auto id_ctor_param = ctx.cc_.gen_id_fresh(cpp_ctor_name_full, "w");
            auto cpp_ctor_param_var = ctx.cc_.gen_cpp_id_base(id_ctor_param);
            auto cpp_type = lower_name_cpp(LowerTy::WHICH_ENUM, name_full, ctx);
            auto cpp_ctor_param = ctx.cc_.Q_->qq_ext(
                Some<string>("Param"), cpp_type, cpp_ctor_param_var);
            cpp_ctor_params->push_back(cpp_ctor_param);
            cpp_ctor_body->push_back(ctx.cc_.Q_->qq_ext(Some<string>("Stmt"),
                "w_ = ", cpp_ctor_param_var, ";"));
        }
        if (ctx.sum_cases_rev_->contains_key(name_full)) {
            auto [parent_name_full, sum_case_which] = ctx.sum_cases_rev_->operator[](name_full);
            auto cpp_parent_which_enum = lower_name_cpp(
                LowerTy::WHICH_ENUM, parent_name_full, ctx);
            auto cpp_parent_struct = lower_name_cpp(LowerTy::STRUCT, parent_name_full, ctx);
            cpp_ctor_init_exprs->push_back(ctx.cc_.qq("Expr", cpp_parent_struct,
                "(", cpp_parent_which_enum, "::", sum_case_which, ")"));
        }

        // make()
        auto cpp_make_name_full = lower_name(LowerTy::MAKE_FULL, name_full);
        auto cpp_make_params = make_rc<Vec<cc::Node_T>>();
        auto cpp_make_body = make_rc<Vec<cc::Node_T>>();
        auto cpp_make_ret = ctx.cc_.gen_cpp_decl_var_init(
            cpp_make_body, cpp_make_name_full, "auto", "ret", "make_rc<",
            cpp_struct_decl_name_tmpl, ">()");

        // make_ext()
        auto id_make_ext_fun_ns = name_lit({ctx.cc_.gen_id_fresh(name_lit({}), "__anon__"),});
        auto cpp_make_ext_name_full = lower_name(LowerTy::MAKE_EXT_FULL, name_full);
        auto cpp_make_ext_params = make_rc<Vec<cc::Node_T>>();
        auto cpp_make_ext_param_arena_var = ctx.cc_.gen_cpp_param_acc<string>(
            cpp_make_ext_params, id_make_ext_fun_ns, "ArenaPtr", "arena");
        auto cpp_make_ext_body = make_rc<Vec<cc::Node_T>>();
        auto cpp_make_ext_ret = ctx.cc_.gen_cpp_decl_var_init(
            cpp_make_ext_body, cpp_make_name_full,
            "auto", "ret", "make_rc_ext<", cpp_struct_decl_name_tmpl, ">(",
            cpp_make_ext_param_arena_var, ")");

        // with_X()
        Map<IdBase, GenName> cpp_with_name_full;
        Map<IdBase, Vec_T<cc::Node_T>> cpp_with_params;
        Map<IdBase, Vec_T<cc::Node_T>> cpp_with_param_vars;
        Map<IdBase, Vec_T<cc::Node_T>> cpp_with_body;
        Map<IdBase, cc::Node_T> cpp_with_ret;
        for (auto q : *fields_full) {
            auto field_name = q.first;
            cpp_with_name_full.insert(field_name,
                lower_name(LowerTy::WITH_FULL, name_full, Some(name_lit({field_name,}))));
            cpp_with_params.insert(field_name, make_rc<Vec<cc::Node_T>>());
            cpp_with_param_vars.insert(field_name, make_rc<Vec<cc::Node_T>>());
            cpp_with_body.insert(field_name, make_rc<Vec<cc::Node_T>>());
            cpp_with_ret.insert(field_name,
                ctx.cc_.gen_cpp_decl_var_init(
                    cpp_with_body[field_name],
                    cpp_with_name_full[field_name],
                    "auto", "ret", "make_rc<", cpp_struct_decl_name_tmpl, ">()"));
        }

        // is_X()
        Map<IdBase, GenName> cpp_sum_is_name_full;
        Map<IdBase, Vec_T<cc::Node_T>> cpp_sum_is_body;
        Map<IdBase, Vec_T<cc::Node_T>> cpp_sum_is_params;
        if (is_sum) {
            for (const auto& [sum_case, _] : *ctx.sum_cases_->operator[](name_full)) {
                cpp_sum_is_name_full.insert(sum_case,
                    lower_name(LowerTy::SUM_IS_FULL, name_full, Some(name_lit({sum_case,}))));
                cpp_sum_is_body.insert(sum_case, make_rc<Vec<cc::Node_T>>());
                cpp_sum_is_params.insert(sum_case, make_rc<Vec<cc::Node_T>>());
            }
        }

        // as_X()
        Map<IdBase, GenName> cpp_sum_as_name_full;
        Map<IdBase, Vec_T<cc::Node_T>> cpp_sum_as_body;
        Map<IdBase, Vec_T<cc::Node_T>> cpp_sum_as_params;
        if (is_sum) {
            for (const auto& [sum_case, _] : *ctx.sum_cases_->operator[](name_full)) {
                cpp_sum_as_name_full.insert(sum_case,
                    lower_name(LowerTy::SUM_AS_FULL, name_full, Some(name_lit({sum_case,}))));
                cpp_sum_as_body.insert(sum_case, make_rc<Vec<cc::Node_T>>());
                cpp_sum_as_params.insert(sum_case, make_rc<Vec<cc::Node_T>>());
            }
        }

        // pr_debug()
        auto id_pr_debug_fun_ns = name_lit({ctx.cc_.gen_id_fresh(name_lit({}), "__anon__"),});
        auto id_pr_debug_name_full = name_lit({"pr_debug",});
        auto cpp_pr_debug_name_full = name_to_cpp_direct(id_pr_debug_name_full, ctx.cc_);
        auto cpp_pr_debug_params = make_rc<Vec<cc::Node_T>>();
        auto cpp_pr_debug_body = make_rc<Vec<cc::Node_T>>();
        auto cpp_pr_debug_param_os_var = ctx.cc_.gen_cpp_param_acc<string>(
            cpp_pr_debug_params, id_pr_debug_fun_ns, "ostream&", "os");
        auto cpp_pr_debug_param_flags_var = ctx.cc_.gen_cpp_param_acc<string>(
            cpp_pr_debug_params, id_pr_debug_fun_ns, "FmtFlags", "flags");
        auto cpp_pr_debug_param_x_var = ctx.cc_.gen_cpp_param_acc<cc::Node_T>(
            cpp_pr_debug_params, id_pr_debug_fun_ns,
            ctx.cc_.gen_cpp_id_with_template_args_acc(
                lower_name_cpp(LowerTy::STRUCT_RC_ALIAS, name_full, ctx), cpp_template_params),
            "x");

        if (is_sum) {
            auto cpp_switch_cases = make_rc<Vec<cc::Node_T>>();
            for (const auto& [sum_case, _] : *ctx.sum_cases_->operator[](name_full)) {
                cpp_switch_cases->push_back(
                    ctx.cc_.qq("SwitchCase", "case",
                        lower_name_cpp(LowerTy::WHICH_ENUM, name_full, ctx),
                        "::", sum_case, ": {",
                        "pr_debug(", cpp_pr_debug_param_os_var, ",", cpp_pr_debug_param_flags_var,
                        ",", cpp_pr_debug_param_x_var, "->",
                        lower_name_cpp(
                            LowerTy::SUM_AS_BASE, name_full, ctx, Some(name_lit({sum_case,}))),
                        "());",
                        "break; }")->as_SwitchCase());
            }
            cpp_switch_cases->push_back(ctx.cc_.qq("SwitchCase", "default: { AX(); }"));
            cpp_pr_debug_body->push_back(
                ctx.cc_.qq("Stmt", "switch (", cpp_pr_debug_param_x_var, "->w_", ") {",
                    *cpp_switch_cases, "}"));
        } else {
            cpp_pr_debug_body->push_back(
                ctx.cc_.qq(
                    "Stmt", "os << ",
                    fmt_str("\"{} {{\"", name_sep_to_join(name_full, "::")), ";"));
            if (fields_full->length() == 0) {
                cpp_pr_debug_body->push_back(ctx.cc_.qq("Stmt", "os << \"}\";"));
            } else {
                auto flags_sub = ctx.cc_.qq("Expr", cpp_pr_debug_param_flags_var, ".sub_lo()");
                for (const auto& q : *fields_full) {
                    auto field_name = q.first;
                    cpp_pr_debug_body->push_back(
                        ctx.cc_.qq("Stmt", flags_sub, ".advance_lines(1, ",
                            cpp_pr_debug_param_os_var, ");"));
                    cpp_pr_debug_body->push_back(
                        ctx.cc_.qq("Stmt", cpp_pr_debug_param_os_var, "<<",
                            fmt_str("\"{}: \"", field_name), ";"));
                    cpp_pr_debug_body->push_back(
                        ctx.cc_.qq("Stmt", "pr_debug(", cpp_pr_debug_param_os_var,
                            ",", flags_sub, ",",
                            cpp_pr_debug_param_x_var, "->",
                            fmt_str("{}_", field_name), ");"));
                    cpp_pr_debug_body->push_back(ctx.cc_.qq("Stmt", "os << \",\";"));
                }
                cpp_pr_debug_body->push_back(
                    ctx.cc_.qq("Stmt", cpp_pr_debug_param_flags_var, ".advance_lines(1, ",
                        cpp_pr_debug_param_os_var, ");"));
                cpp_pr_debug_body->push_back(ctx.cc_.qq("Stmt", "os << \"}\";"));
            }
        }

        ctx.cc_.dst_decls_->push_back(
            ctx.cc_.gen_cpp_fun_proto_decl(
                cpp_template_params,
                NodeV_empty(),
                Some(ctx.cc_.gen_cpp_id_base("void")),
                id_pr_debug_name_full,
                cpp_pr_debug_params)->as_Decl());

        ctx.cc_.push_def(cpp_template_params,
            ctx.cc_.gen_cpp_fun_body(
                cpp_template_params,
                NodeV_empty(),
                Some(ctx.cc_.gen_cpp_id_base("void")),
                cpp_pr_debug_name_full,
                cpp_pr_debug_params,
                NodeV_empty(),
                cpp_pr_debug_body)->as_Decl());

        // write() prototype
        if (gen_write_proto) {
            auto id_write_fun_ns = name_lit({ctx.cc_.gen_id_fresh(name_lit({}), "__anon__"),});
            auto cpp_write_name = lower_name_cpp(LowerTy::WRITE_BASE, name_full, ctx);
            auto cpp_write_params = make_rc<Vec<cc::Node_T>>();
            auto cpp_write_param_os_var = ctx.cc_.gen_cpp_param_acc<cc::Node_T>(
                cpp_write_params, id_write_fun_ns, ctx.cc_.Q_->qq("Expr", "ostream&"), "os");
            auto cpp_write_param_flags_var = ctx.cc_.gen_cpp_param_acc<cc::Node_T>(
                cpp_write_params, id_write_fun_ns, ctx.cc_.Q_->qq("Expr", "FmtFlags"), "flags");
            cpp_fields->push_back(
                ctx.cc_.qq("Entry", "void", cpp_write_name,
                    "(ostream& ", cpp_write_param_os_var, ", FmtFlags",
                    cpp_write_param_flags_var, ");"));
        }

        // hash_ser_acc()
        auto id_hash_ser_acc_fun_ns = name_lit({ctx.cc_.gen_id_fresh(name_lit({}), "__anon__"),});
        auto hash_ser_acc_name_full = lower_name(LowerTy::HASH_SER_ACC_FULL, name_full);
        auto cpp_hash_ser_acc_name_base = lower_name_cpp(
            LowerTy::HASH_SER_ACC_BASE, name_full, ctx);
        auto cpp_hash_ser_acc_name_full = lower_name_cpp(
            LowerTy::HASH_SER_ACC_FULL, name_full, ctx);
        auto cpp_hash_ser_acc_body = make_rc<Vec<cc::Node_T>>();
        auto cpp_hash_ser_acc_params = make_rc<Vec<cc::Node_T>>();
        auto cpp_hash_ser_acc_param_buf_var = ctx.cc_.gen_cpp_param_acc<cc::Node_T>(
            cpp_hash_ser_acc_params, id_hash_ser_acc_fun_ns,
            ctx.cc_.Q_->qq("Expr", "SerBuf&"), "buf");

        auto id_hash_ser_acc_inst_fun_ns = name_lit(
            {ctx.cc_.gen_id_fresh(name_lit({}), "__anon__"),});
        auto hash_ser_acc_inst_name_full = lower_name(LowerTy::HASH_SER_ACC_INST_FULL, name_full);
        auto cpp_hash_ser_acc_inst_name_base = lower_name_cpp(
            LowerTy::HASH_SER_ACC_INST_BASE, name_full, ctx);
        auto cpp_hash_ser_acc_inst_name_full = lower_name_cpp(
            LowerTy::HASH_SER_ACC_INST_FULL, name_full, ctx);
        auto cpp_hash_ser_acc_inst_name_full_tmpl = lower_name_cpp(
            LowerTy::HASH_SER_ACC_INST_FULL, name_full, ctx,
            None<GenName>(), Some<Vec_T<cc::Node_T>>(cpp_template_params));
        auto cpp_hash_ser_acc_inst_body = make_rc<Vec<cc::Node_T>>();
        auto cpp_hash_ser_acc_inst_params = make_rc<Vec<cc::Node_T>>();
        auto cpp_hash_ser_acc_inst_param_buf_var = ctx.cc_.gen_cpp_param_acc<cc::Node_T>(
            cpp_hash_ser_acc_inst_params, id_hash_ser_acc_inst_fun_ns,
            ctx.cc_.Q_->qq("Expr", "SerBuf&"), "buf");

        if (is_sum) {
            // _W
            auto cpp_enum_cases = make_rc<Vec<cc::Node_T>>();
            for (const auto& [sum_case, _] : *ctx.sum_cases_->operator[](name_full)) {
                cpp_enum_cases->push_back(ctx.cc_.gen_cpp_id_base(sum_case));
            }
            ctx.cc_.dst_decls_->push_back(ctx.cc_.gen_cpp_decl_enum(
                lower_name(LowerTy::WHICH_ENUM, name_full), cpp_enum_cases)->as_Decl());

            // w_
            auto cpp_which_enum = lower_name_cpp(LowerTy::WHICH_ENUM, name_full, ctx);
            cpp_fields->push_back(
                ctx.cc_.Q_->qq_ext(Some<string>("Entry"), cpp_which_enum, "w_", ";"));

            // is_X
            for (const auto& [sum_case, _] : *ctx.sum_cases_->operator[](name_full)) {
                cpp_sum_is_body[sum_case]->push_back(
                    ctx.cc_.gen_cpp_ret(
                        ctx.cc_.Q_->qq_ext(Some<string>("Expr"), "w_ == ",
                        cpp_which_enum, "::", sum_case)));
            }

            // as_X
            for (const auto& [sum_case, sub_name_full] : *ctx.sum_cases_->operator[](name_full)) {
                auto cpp_sub_name_full = lower_name_cpp(LowerTy::STRUCT, sub_name_full, ctx);
                auto cpp_sum_is_method_name = lower_name_cpp(
                    LowerTy::SUM_IS_BASE, name_full, ctx, Some(name_lit({sum_case,})));
                cpp_sum_as_body[sum_case]->push_back(
                    ctx.cc_.Q_->qq_ext(Some<string>("Stmt"), "AT(this->", cpp_sum_is_method_name,
                        "());"));
                cpp_sum_as_body[sum_case]->push_back(
                    ctx.cc_.qq_stmt("return this->rc_from_this_poly<", cpp_sub_name_full, ">();"));
            }

            // virtual dtor
            cpp_fields->push_back(ctx.cc_.qq("Entry", "virtual ~_T();"));
        }

        if (!has_mod_mut(p.second)) {
            // hash_ser_acc_E()
            if (ctx.sum_cases_rev_->contains_key(name_full)) {
                auto [parent_name_full, _] = ctx.sum_cases_rev_->operator[](name_full);
                auto cpp_hash_ser_acc_inst_parent_name_base = lower_name_cpp(
                    LowerTy::HASH_SER_ACC_INST_BASE, parent_name_full, ctx);

                cpp_hash_ser_acc_inst_body->push_back(
                    ctx.cc_.Q_->qq_ext(Some<string>("Stmt"),
                        "this->", cpp_hash_ser_acc_inst_parent_name_base, "(",
                        cpp_hash_ser_acc_inst_param_buf_var, ");"));
            }
            if (is_sum) {
                cpp_hash_ser_acc_inst_body->push_back(
                    ctx.cc_.Q_->qq_ext(Some<string>("Stmt"),
                        "hash_ser(", cpp_hash_ser_acc_inst_param_buf_var,
                        ", static_cast<Int>(w_));"));
            }

            // hash_ser_acc()
            if (!is_sum) {
                cpp_hash_ser_acc_body->push_back(
                    ctx.cc_.Q_->qq_ext(Some<string>("Stmt"),
                        "this->", cpp_hash_ser_acc_inst_name_full_tmpl, "(",
                        cpp_hash_ser_acc_param_buf_var, ");"));
            }
        }

        for (const auto& q : *fields_proper) {
            auto data_field_name = q.first;
            auto data_field_type = q.second;
            auto def_ns = name_full;
            auto cpp_type = data_type_expr_to_cpp(data_field_type->type__, def_ns, ctx);
            auto cpp_field_name = ctx.cc_.gen_cpp_id_base(data_field_name + "_");

            cpp_fields->push_back(
                ctx.cc_.Q_->qq_ext(Some<string>("Entry"), cpp_type, cpp_field_name, ";"));
        }

        for (const auto& q : *fields_full) {
            auto data_field_name = q.first;
            auto data_field_type = q.second;
            auto def_ns = name_full;
            auto cpp_type = data_type_expr_to_cpp(data_field_type->type__, def_ns, ctx);
            auto cpp_field_name = ctx.cc_.gen_cpp_id_base(data_field_name + "_");

            // make()
            auto id_make_param = ctx.cc_.gen_id_fresh(cpp_make_name_full, data_field_name);
            auto cpp_make_param_var = ctx.cc_.gen_cpp_id_base(id_make_param);
            auto cpp_make_param = ctx.cc_.Q_->qq_ext(
                Some<string>("Param"), cpp_type, cpp_make_param_var);
            cpp_make_params->push_back(cpp_make_param);
            cpp_make_body->push_back(ctx.cc_.Q_->qq_ext(Some<string>("Stmt"),
                cpp_make_ret, "->", cpp_field_name, " = ", cpp_make_param_var, ";"));

            // make_ext()
            auto id_make_ext_param = ctx.cc_.gen_id_fresh(cpp_make_ext_name_full, data_field_name);
            auto cpp_make_ext_param_var = ctx.cc_.gen_cpp_id_base(id_make_ext_param);
            auto cpp_make_ext_param = ctx.cc_.Q_->qq_ext(
                Some<string>("Param"), cpp_type, cpp_make_ext_param_var);
            cpp_make_ext_params->push_back(cpp_make_ext_param);
            cpp_make_ext_body->push_back(ctx.cc_.Q_->qq_ext(Some<string>("Stmt"),
                cpp_make_ext_ret, "->", cpp_field_name, " = ", cpp_make_ext_param_var, ";"));

            // with_X()
            auto id_with_param = ctx.cc_.gen_id_fresh(
                cpp_with_name_full[data_field_name], data_field_name);
            auto cpp_with_param_var = ctx.cc_.gen_cpp_id_base(id_make_param);
            auto cpp_with_param = ctx.cc_.Q_->qq_ext(
                Some<string>("Param"), cpp_type, cpp_with_param_var);
            cpp_with_param_vars[data_field_name]->push_back(cpp_with_param_var);
            cpp_with_params[data_field_name]->push_back(cpp_with_param);
            for (auto data_field_with_rem : *fields_full) {
                auto data_field_with_rem_name = data_field_with_rem.first;
                auto cpp_field_with_rem_name = ctx.cc_.gen_cpp_id_base(
                    data_field_with_rem_name + "_");
                if (data_field_with_rem_name == data_field_name) {
                    cpp_with_body[data_field_name]->push_back(
                        ctx.cc_.Q_->qq_ext(Some<string>("Stmt"),
                            cpp_with_ret[data_field_name], "->", cpp_field_with_rem_name,
                            " = ", cpp_with_param_vars[data_field_name]->only(), ";"));
                } else {
                    cpp_with_body[data_field_name]->push_back(
                        ctx.cc_.Q_->qq_ext(Some<string>("Stmt"),
                            cpp_with_ret[data_field_name], "->", cpp_field_with_rem_name,
                            " = this->", cpp_field_with_rem_name, ";"));
                }
            }
            cpp_with_body[data_field_name]->push_back(
                ctx.cc_.gen_cpp_ret(cpp_with_ret[data_field_name]));

            if (!has_mod_mut(p.second) && !q.second->no_hash__) {
                // hash_ser_acc_E()
                cpp_hash_ser_acc_inst_body->push_back(ctx.cc_.Q_->qq_ext(Some<string>("Stmt"),
                    "hash_ser(", cpp_hash_ser_acc_param_buf_var, ", ", cpp_field_name, ");"));
            }
        }

        cpp_make_body->push_back(ctx.cc_.gen_cpp_ret(cpp_make_ret));
        cpp_make_ext_body->push_back(ctx.cc_.gen_cpp_ret(cpp_make_ext_ret));


        // ===== Emit decls =====

        // constructor
        cpp_fields->push_back(
            ctx.cc_.gen_cpp_fun_proto_entry(
                NodeV_empty(),
                None<cc::Node_T>(),
                ctx.cc_.gen_cpp_id_with_template_args_acc(
                    lower_name_cpp(LowerTy::CTOR_BASE, name_full, ctx),
                    cpp_template_params),
                cpp_ctor_params));

        if (!is_sum) {
            auto mods = make_rc<Vec<cc::Node_T>>();
            mods->push_back(ctx.cc_.qq("Mod", "__attribute__((always_inline))"));

            // make()
            ctx.cc_.dst_decls_->push_back(
                ctx.cc_.gen_cpp_fun_proto_decl(
                    cpp_template_params,
                    mods,
                    Some(
                        ctx.cc_.gen_cpp_id_with_template_args_acc(
                            lower_name_cpp(LowerTy::STRUCT_RC_ALIAS, name_full, ctx),
                            cpp_template_params)),
                    lower_name(LowerTy::MAKE_FULL, name_full),
                    cpp_make_params)->as_Decl());

            // make_ext()
            ctx.cc_.dst_decls_->push_back(
                ctx.cc_.gen_cpp_fun_proto_decl(
                    cpp_template_params,
                    mods,
                    Some(
                        ctx.cc_.gen_cpp_id_with_template_args_acc(
                            lower_name_cpp(LowerTy::STRUCT_RC_ALIAS, name_full, ctx),
                            cpp_template_params)),
                    lower_name(LowerTy::MAKE_EXT_FULL, name_full),
                    cpp_make_ext_params)->as_Decl());

            // with_X()
            for (auto data_field : *fields_full) {
                auto data_field_name = data_field.first;
                cpp_fields->push_back(
                    ctx.cc_.gen_cpp_fun_proto_entry(
                        NodeV_empty(),
                        Some(
                            ctx.cc_.gen_cpp_id_with_template_args_acc(
                                lower_name_cpp(LowerTy::STRUCT_RC_ALIAS, name_full, ctx),
                                cpp_template_params)),
                        lower_name_cpp(LowerTy::WITH_BASE, name_full, ctx,
                            Some(name_lit({data_field_name,}))),
                        cpp_with_params[data_field_name]));
            }
        }

        if (is_sum) {
            // is_X()
            for (const auto& [sum_case, _] : *ctx.sum_cases_->operator[](name_full)) {
                cpp_fields->push_back(
                    ctx.cc_.gen_cpp_fun_proto_entry(
                        NodeV_empty(),
                        Some(ctx.cc_.gen_cpp_id_base("bool")),
                        lower_name_cpp(LowerTy::SUM_IS_BASE, name_full, ctx,
                            Some(name_lit({sum_case,}))),
                        cpp_sum_is_params[sum_case]));
            }

            // as_X()
            for (const auto& [sum_case, sub_name_full] : *ctx.sum_cases_->operator[](name_full)) {
                auto cpp_sub_name_full_ptr = lower_name_cpp(
                    LowerTy::STRUCT_RC_ALIAS, sub_name_full, ctx);
                cpp_fields->push_back(
                    ctx.cc_.gen_cpp_fun_proto_entry(
                        NodeV_empty(),
                        Some<cc::Node_T>(cpp_sub_name_full_ptr),
                        lower_name_cpp(LowerTy::SUM_AS_BASE, name_full, ctx,
                            Some(name_lit({sum_case,}))),
                        cpp_sum_as_params[sum_case]));
            }
        }

        if (is_sum) {
            // virtual dtor
            ctx.cc_.dst_defs_->push_back(ctx.cc_.qq("Decl",
                lower_name_cpp(LowerTy::STRUCT, name_full, ctx),
                "::~_T() {}")->as_Decl());
        }

        if (!has_mod_mut(p.second)) {
            // hash_ser_acc_E()
            cpp_fields->push_back(
                ctx.cc_.qq("Entry", "void",
                    lower_name_cpp(LowerTy::HASH_SER_ACC_INST_BASE, name_full, ctx),
                    "(SerBuf& ", cpp_hash_ser_acc_inst_param_buf_var, ") const;"));

            // hash_ser_acc()
            if (!is_sum) {
                cpp_fields->push_back(
                    ctx.cc_.qq("Entry", "virtual void hash_ser_acc(SerBuf& ",
                        cpp_hash_ser_acc_param_buf_var, ") const;"));
            } else {
                cpp_fields->push_back(ctx.cc_.Q_->qq_ext(Some<string>("Entry"),
                    "virtual void hash_ser_acc(SerBuf& ",
                    cpp_hash_ser_acc_param_buf_var, ") const = 0;"));
            }
        }

        // struct E : base_classes {...}
        auto cpp_base_classes = make_rc<Vec<cc::Node_T>>();
        if (ctx.sum_cases_rev_->contains_key(name_full)) {
            auto [parent_name_full, _] = ctx.sum_cases_rev_->operator[](name_full);
            auto cpp_parent = lower_name_cpp(LowerTy::STRUCT, parent_name_full, ctx);
            cpp_base_classes->push_back(cpp_parent);
        }
        if (!ctx.sum_cases_rev_->contains_key(name_full)) {
            cpp_base_classes->push_back(ctx.cc_.gen_cpp_id_base("hash_obj"));
            cpp_base_classes->push_back(ctx.cc_.gen_cpp_id_base("enable_rc_from_this_poly"));
        }

        ctx.cc_.dst_decls_->push_back(
            ctx.cc_.gen_cpp_decl_struct(
                struct_decl_name, cpp_fields, cpp_base_classes, cpp_template_params)->as_Decl());

        // constructor
        ctx.cc_.push_def(cpp_template_params,
            ctx.cc_.gen_cpp_fun_body(
                cpp_template_params,
                NodeV_empty(),
                None<cc::Node_T>(),
                cpp_name_with_append(ctx.cc_,
                    ctx.cc_.gen_cpp_id_with_template_args_acc(
                        cpp_name_with_append(
                            ctx.cc_, name_to_cpp_direct(name_full, ctx.cc_), "_T"),
                        cpp_template_params),
                    "_T"),
                cpp_ctor_params,
                cpp_ctor_init_exprs,
                cpp_ctor_body)->as_Decl());

        if (!is_sum) {
            auto mods = make_rc<Vec<cc::Node_T>>();
            mods->push_back(ctx.cc_.qq("Mod", "__attribute__((always_inline))"));

            // make()
            ctx.cc_.push_def(cpp_template_params,
                ctx.cc_.gen_cpp_fun_body(
                    cpp_template_params,
                    mods,
                    Some(
                        ctx.cc_.gen_cpp_id_with_template_args_acc(
                            lower_name_cpp(LowerTy::STRUCT_RC_ALIAS, name_full, ctx),
                            cpp_template_params)),
                    lower_name_cpp(LowerTy::MAKE_FULL, name_full, ctx),
                    cpp_make_params,
                    NodeV_empty(),
                    cpp_make_body)->as_Decl());

            // make_ext()
            ctx.cc_.push_def(cpp_template_params,
                ctx.cc_.gen_cpp_fun_body(
                    cpp_template_params,
                    mods,
                    Some(
                        ctx.cc_.gen_cpp_id_with_template_args_acc(
                            lower_name_cpp(LowerTy::STRUCT_RC_ALIAS, name_full, ctx),
                            cpp_template_params)),
                    lower_name_cpp(LowerTy::MAKE_EXT_FULL, name_full, ctx),
                    cpp_make_ext_params,
                    NodeV_empty(),
                    cpp_make_ext_body)->as_Decl());

            // with_X()
            for (auto data_field : *fields_full) {
                auto data_field_name = data_field.first;
                ctx.cc_.push_def(cpp_template_params,
                    ctx.cc_.gen_cpp_fun_body(
                        cpp_template_params,
                        NodeV_empty(),
                        Some(
                            ctx.cc_.gen_cpp_id_with_template_args_acc(
                                lower_name_cpp(LowerTy::STRUCT_RC_ALIAS, name_full, ctx),
                                cpp_template_params)),
                            cpp_name_with_append(ctx.cc_,
                                ctx.cc_.gen_cpp_id_with_template_args_acc(
                                    cpp_name_with_append(
                                        ctx.cc_,
                                        name_to_cpp_direct(name_full, ctx.cc_), "_T"),
                                    cpp_template_params),
                                fmt_str("with_{}", data_field_name)),
                        cpp_with_params[data_field_name],
                        NodeV_empty(),
                        cpp_with_body[data_field_name])->as_Decl());
            }
        }

        if (is_sum) {
            // is_X()
            for (const auto& [sum_case, _] : *ctx.sum_cases_->operator[](name_full)) {
                ctx.cc_.push_def(cpp_template_params,
                    ctx.cc_.gen_cpp_fun_body(
                        cpp_template_params,
                        NodeV_empty(),
                        Some(ctx.cc_.gen_cpp_id_base("bool")),
                        lower_name_cpp(
                            LowerTy::SUM_IS_FULL, name_full, ctx, Some(name_lit({sum_case,}))),
                        cpp_sum_is_params[sum_case],
                        NodeV_empty(),
                        cpp_sum_is_body[sum_case])->as_Decl());
            }

            // as_X()
            for (const auto& [sum_case, sub_name_full] : *ctx.sum_cases_->operator[](name_full)) {
                auto cpp_sub_name_full_ptr = lower_name_cpp(
                    LowerTy::STRUCT_RC_ALIAS, sub_name_full, ctx);
                ctx.cc_.push_def(cpp_template_params,
                    ctx.cc_.gen_cpp_fun_body(
                        cpp_template_params,
                        NodeV_empty(),
                        Some<cc::Node_T>(cpp_sub_name_full_ptr),
                        lower_name_cpp(LowerTy::SUM_AS_FULL, name_full, ctx,
                            Some(name_lit({sum_case,}))),
                        cpp_sum_as_params[sum_case],
                        NodeV_empty(),
                        cpp_sum_as_body[sum_case])->as_Decl());
            }
        }

        if (!has_mod_mut(p.second)) {
            // hash_ser_acc_E()
            ctx.cc_.push_def(cpp_template_params,
                ctx.cc_.gen_cpp_fun_body(
                    cpp_template_params,
                    NodeV_empty(),
                    Some<cc::Node_T>(name_to_cpp_direct(name_lit({"void"}), ctx.cc_)),
                    lower_name_cpp(LowerTy::HASH_SER_ACC_INST_FULL, name_full, ctx,
                        None<GenName>(), Some<Vec_T<cc::Node_T>>(cpp_template_params)),
                    cpp_hash_ser_acc_inst_params,
                    NodeV_empty(),
                    cpp_hash_ser_acc_inst_body,
                    true)->as_Decl());

            // hash_ser_acc()
            if (!is_sum) {
                ctx.cc_.push_def(cpp_template_params,
                    ctx.cc_.gen_cpp_fun_body(
                        cpp_template_params,
                        NodeV_empty(),
                        Some<cc::Node_T>(name_to_cpp_direct(name_lit({"void"}), ctx.cc_)),
                        lower_name_cpp(LowerTy::HASH_SER_ACC_FULL, name_full, ctx,
                            None<GenName>(), Some<Vec_T<cc::Node_T>>(cpp_template_params)),
                        cpp_hash_ser_acc_params,
                        NodeV_empty(),
                        cpp_hash_ser_acc_body,
                        true)->as_Decl());
            }
        }
    }

    for (auto [_, i] : data_leaves_inds) {
        auto p = data_leaves_vec->operator[](i);

        if (has_mod_visit(p.second)) {
            auto vis = make_rc<Set<GenName>>();
            data_gen_xform_fn(XformTy::Visit, p.first, p.first, vis, ctx);
        }

        if (has_mod_xform(p.second)) {
            auto vis = make_rc<Set<GenName>>();
            data_gen_xform_fn(XformTy::Xform, p.first, p.first, vis, ctx);

            for (auto vis_i : *vis) {
                if (ctx.is_ancestor(p.first, vis_i)) {
                    data_gen_xform_id_fn(p.first, vis_i, ctx);
                }
            }
        }
    }

    auto [hpp_mod, cpp_mod] = ctx.cc_.extract_mods();

    DataDefsResult ret;
    ret.hpp_decls = hpp_mod;
    ret.cpp_decls = cpp_mod;
    return ret;
}
