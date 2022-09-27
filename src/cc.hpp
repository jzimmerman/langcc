#pragma once

#include "langcc_util.hpp"

#include "cc__gen.hpp"

enum struct HeaderMode {
    N,
    Y,
};

using namespace lang;
using namespace lang_rt;


inline void pr(ostream& os, FmtFlags flags, lang::cc::Node_T x) {
    x->write(os, flags);
}


using IdBase = string;
using GenName = Vec_T<IdBase>;


inline GenName name_lit(const vector<string>& init) {
    auto ret = make_rc<Vec<IdBase>>();
    for (const auto& x : init) {
        ret->push(x);
    }
    return ret;
}


inline GenName name_ns_cons(const GenName& ns, const IdBase& name_base) {
    return ns->clone_rc()->with_append_rc(name_base);
}


inline pair<GenName, IdBase> name_ns_decons(const GenName& name) {
    AT(name->length() > 0);
    auto ret_ns = name->slice(0, name->length() - 1);
    auto ret_base = (*name)[name->length() - 1];
    return make_pair(ret_ns, ret_base);
}


using NodeR = const cc::Node_T&;
using NodeRM = const Option_T<cc::Node_T>&;
using NodeV = const Vec_T<cc::Node_T>&;


inline Vec_T<cc::Node_T> NodeV_empty() {
    return make_rc<Vec<cc::Node_T>>();
}


inline Vec_T<cc::Node_T> NodeV_singleton(const cc::Node_T& x) {
    auto ret = make_rc<Vec<cc::Node_T>>();
    ret->push_back(x);
    return ret;
}


struct CppGenContext {
    cc::LangDesc_T L_cc_;
    cc::QuoteEnv_T Q_;

    Vec_T<cc::Node_T> dst_decls_;
    Vec_T<cc::Node_T> dst_defs_;

    Set<GenName> all_gen_names_env_;

    inline IdBase gen_id_fresh(GenName ns, string id_hint) {
        auto ret = id_hint;
        Int c = 0;
        while (all_gen_names_env_.contains(ns->with_append_rc(ret))) {
            ++c;
            ret = id_hint + fmt_str("{}", c);
        }
        all_gen_names_env_.insert(ns->with_append_rc(ret));
        return ret;
    }

    inline CppGenContext() {
        L_cc_ = lang::cc::init();
        Q_ = L_cc_->quote_env();
        dst_decls_ = make_rc<Vec<cc::Node_T>>();
        dst_defs_ = make_rc<Vec<cc::Node_T>>();
    }

    inline void gen_cpp_template_params_acc(LexOutput_T& dst, NodeV cpp_template_params);
    inline void gen_cpp_template_args_acc(LexOutput_T& dst, NodeV cpp_template_params);

    inline cc::Node_T gen_cpp_id_with_template_args_acc(NodeR id, NodeV cpp_template_params);

    inline cc::Node_T gen_cpp_decl_struct(GenName decl_name, NodeV cpp_fields,
        NodeV cpp_base_classes, NodeV cpp_template_params);
    inline cc::Node_T gen_cpp_decl_struct_fwd(GenName decl_name, NodeV cpp_template_params);
    inline cc::Node_T gen_cpp_decl_using(GenName decl_name, NodeR val, NodeV cpp_template_params);
    inline cc::Node_T gen_cpp_decl_enum(GenName decl_name, NodeV cpp_cases);

    template<typename Ret, typename... Args>
    inline cc::Node_T gen_cpp_decl_var_init(Vec_T<cc::Node_T>& dst,
        GenName ns, Ret ret_ty, string name_hint, const Args&... init_args);

    inline void gen_cpp_fun_proto_acc(LexOutput_T& dst,
        NodeV mods, NodeRM ret, NodeR fun_name, NodeV params);
    inline cc::Node_T gen_cpp_fun_proto_decl(
        NodeV cpp_template_params, NodeV mods, NodeRM ret, const GenName& decl_name, NodeV params);
    inline cc::Node_T gen_cpp_fun_proto_entry(
        NodeV mods, NodeRM ret, NodeR fun_name, NodeV params);
    inline cc::Node_T gen_cpp_fun_call(NodeR f, NodeV args);
    inline cc::Node_T gen_cpp_fun_body(NodeV cpp_template_params,
        NodeV mods, NodeRM ret, NodeR fun_name, NodeV params, NodeV init_exprs, NodeV body,
        bool const_post = false);

    template<typename Ty>
    inline cc::Node_T gen_cpp_param_acc(Vec_T<cc::Node_T>& dst,
        const GenName& ns, const Ty& type, const string& name_hint);

    inline cc::Node_T gen_cpp_decl_ns_wrap(GenName decl_ns, NodeR decl);

    inline cc::Node_T gen_cpp_rc_ptr(const cc::Node_T& val);
    inline cc::Node_T gen_cpp_id_base(const IdBase& id_base);
    inline cc::Node_T gen_cpp_ret(NodeR x);

    inline cc::Node_T gen_cpp_init_list_u16(const Vec_T<Int>& v);

    template<typename ...Ts>
    inline cc::Node_T qq(const Ts&... args) {
        return Q_->qq(args...);
    }

    template<typename ...Ts>
    inline cc::Node_T qq_expr(const Ts&... args) {
        return Q_->qq_ext(Some<string>("Expr"), args...);
    }

    template<typename ...Ts>
    inline cc::Node_T qq_switch_case(const Ts&... args) {
        return Q_->qq_ext(Some<string>("SwitchCase"), args...);
    }

    template<typename ...Ts>
    inline cc::Node_T qq_stmt(const Ts&... args) {
        return Q_->qq_ext(Some<string>("Stmt"), args...);
    }

    template<typename ...Ts>
    inline cc::Node_T qq_stmt_acc(Vec_T<cc::Node_T>& dst, const Ts&... args) {
        auto ret = this->qq_stmt(args...);
        dst->push_back(ret);
        return ret;
    }

    inline void push_def(NodeV cpp_template_params, cc::Node::Decl_T def) {
        if (cpp_template_params->length() > 0) {
            dst_decls_->push_back(def);
        } else {
            dst_defs_->push_back(def);
        }
    }

    inline pair<Option_T<lang::cc::Node_T>, Option_T<lang::cc::Node_T>> extract_mods(
        HeaderMode header_mode) {

        if (header_mode == HeaderMode::Y) {
            auto hpp_mod = None<lang::cc::Node_T>();
            auto dst_all = make_rc<Vec<lang::cc::Node_T>>();
            dst_all->extend(dst_decls_);
            dst_all->extend(dst_defs_);
            if (dst_all->length() > 0) {
                hpp_mod = Some<lang::cc::Node_T>(Q_->qq_ext(Some<string>("Module"), *dst_all));
            }
            auto cpp_mod = None<lang::cc::Node_T>();
            return make_pair(hpp_mod, cpp_mod);

        } else {
            auto hpp_mod = None<lang::cc::Node_T>();
            if (dst_decls_->length() > 0) {
                hpp_mod = Some<lang::cc::Node_T>(Q_->qq_ext(Some<string>("Module"), *dst_decls_));
            }
            auto cpp_mod = None<lang::cc::Node_T>();
            if (dst_defs_->length() > 0) {
                cpp_mod = Some<lang::cc::Node_T>(Q_->qq_ext(Some<string>("Module"), *dst_defs_));
            }
            return make_pair(hpp_mod, cpp_mod);
        }
    }
};


inline cc::Node::Expr_T name_to_cpp_direct(const GenName& name, CppGenContext& ctx) {
    AT(name->length() > 0);
    auto ret = ctx.Q_->qq_ext(Some<string>("Expr"), (*name)[0]);

    for (Int i = 1; i < name->length(); i++) {
        ret = ctx.Q_->qq_ext(Some<string>("Expr"), ret, "::", (*name)[i]);
    }
    return ret->as_Expr();
}


inline cc::Node_T cpp_name_with_append(CppGenContext& ctx, cc::Node_T node, string name) {
    return ctx.Q_->qq("Expr", node, "::", name);
}


inline cc::Node_T CppGenContext::gen_cpp_decl_struct(
    GenName decl_name, NodeV cpp_fields, NodeV cpp_base_classes,
    NodeV cpp_template_params) {
    auto [decl_ns, decl_name_base] = name_ns_decons(decl_name);

    auto lex_args = Q_->make_lex_builder();

    this->gen_cpp_template_params_acc(lex_args, cpp_template_params);

    Q_->qq_args_acc(lex_args, "struct", decl_name_base);

    if (cpp_base_classes->length() > 0) {
        Q_->qq_args_acc(lex_args, ":");
        bool fresh = true;
        for (const auto& cpp_base_class : *cpp_base_classes) {
            if (!fresh) {
                Q_->qq_args_acc(lex_args, ",");
            }
            fresh = false;
            Q_->qq_args_acc(lex_args, cpp_base_class);
        }
    }

    Q_->qq_args_acc(lex_args, "{");
    for (const auto& cpp_field : *cpp_fields) {
        Q_->qq_args_acc(lex_args, cpp_field);
    }
    Q_->qq_args_acc(lex_args, "};");

    auto decl = Q_->qq_inner(Some<string>("Decl"), lex_args);
    return this->gen_cpp_decl_ns_wrap(decl_ns, decl);
}


inline cc::Node_T CppGenContext::gen_cpp_decl_struct_fwd(
    GenName decl_name, NodeV cpp_template_params) {

    auto [decl_ns, decl_name_base] = name_ns_decons(decl_name);
    auto lex_args = Q_->make_lex_builder();
    this->gen_cpp_template_params_acc(lex_args, cpp_template_params);
    Q_->qq_args_acc(lex_args, "struct", decl_name_base, ";");
    auto decl = Q_->qq_inner(Some<string>("Decl"), lex_args);
    return this->gen_cpp_decl_ns_wrap(decl_ns, decl);
}


inline cc::Node_T CppGenContext::gen_cpp_decl_using(GenName decl_name, const cc::Node_T& val,
    NodeV cpp_template_params) {

    auto [decl_ns, decl_name_base] = name_ns_decons(decl_name);
    auto lex_args = Q_->make_lex_builder();
    this->gen_cpp_template_params_acc(lex_args, cpp_template_params);
    Q_->qq_args_acc(lex_args, "using", decl_name_base, "=", val);
    Q_->qq_args_acc(lex_args, ";");
    auto decl = Q_->qq_inner(Some<string>("Decl"), lex_args);
    return this->gen_cpp_decl_ns_wrap(decl_ns, decl);
}


inline cc::Node_T CppGenContext::gen_cpp_decl_enum(
    GenName decl_name, const Vec_T<cc::Node_T>& cpp_cases) {

    auto [decl_ns, decl_name_base] = name_ns_decons(decl_name);

    auto lex_args = Q_->make_lex_builder();
    Q_->qq_args_acc(lex_args, "enum struct", decl_name_base, "{");
    for (const auto& cpp_case : *cpp_cases) {
        Q_->qq_args_acc(lex_args, cpp_case);
        Q_->qq_args_acc(lex_args, ",");
    }
    Q_->qq_args_acc(lex_args, "};");
    auto decl = Q_->qq_inner(Some<string>("Decl"), lex_args);
    return this->gen_cpp_decl_ns_wrap(decl_ns, decl);
}


template<typename Ret, typename... Args>
inline cc::Node_T CppGenContext::gen_cpp_decl_var_init(Vec_T<cc::Node_T>& dst,
    GenName ns, Ret ret_ty, string id_hint, const Args&... init_args) {

    auto id = this->gen_id_fresh(ns, id_hint);
    auto cpp_id = this->gen_cpp_id_base(id);
    auto decl = Q_->qq_ext(Some<string>("Stmt"), ret_ty, cpp_id, " = ", init_args..., ";");
    dst->push_back(decl);
    return cpp_id;
}


inline cc::Node_T CppGenContext::gen_cpp_fun_call(NodeR f, NodeV args) {
    auto lex_args = Q_->make_lex_builder();
    Q_->qq_args_acc(lex_args, f, "(");
    bool loop_fresh = true;
    for (const auto& arg : *args) {
        if (!loop_fresh) {
            Q_->qq_args_acc(lex_args, ",");
        }
        loop_fresh = false;
        Q_->qq_args_acc(lex_args, arg);
    }
    Q_->qq_args_acc(lex_args, ")");
    try {
        return Q_->qq_inner(Some<string>("Expr"), lex_args);
    } catch (const string& err) {
        fmt(cerr, "Input sequence: {}", lex_args);
        fmt(cerr, "{}\n", err);
        throw;
    }
}


inline void CppGenContext::gen_cpp_fun_proto_acc(LexOutput_T& lex_args,
    NodeV mods, NodeRM ret, NodeR fun_name, NodeV params) {

    for (auto mod : *mods) {
        Q_->qq_args_acc(lex_args, mod);
    }
    if (ret.is_some()) {
        Q_->qq_args_acc(lex_args, ret.as_some());
    }
    Q_->qq_args_acc(lex_args, fun_name, "(");
    bool loop_fresh = true;
    for (const auto& param : *params) {
        if (!loop_fresh) {
            Q_->qq_args_acc(lex_args, ",");
        }
        loop_fresh = false;
        Q_->qq_args_acc(lex_args, param);
    }
    Q_->qq_args_acc(lex_args, ")");
}


inline cc::Node_T CppGenContext::gen_cpp_fun_proto_entry(
    NodeV mods, NodeRM ret, NodeR fun_name, NodeV params) {

    auto lex_args = Q_->make_lex_builder();
    this->gen_cpp_fun_proto_acc(lex_args, mods, ret, fun_name, params);
    Q_->qq_args_acc(lex_args, ";");
    return Q_->qq_inner(Some<string>("Entry"), lex_args);
}


inline cc::Node_T CppGenContext::gen_cpp_fun_proto_decl(
    NodeV cpp_template_params,
    NodeV mods, NodeRM ret, const GenName& decl_name, NodeV params) {

    auto [decl_ns, decl_name_base] = name_ns_decons(decl_name);

    auto fun_name = name_to_cpp_direct(name_lit({decl_name_base,}), *this);

    auto lex_args = Q_->make_lex_builder();
    this->gen_cpp_template_params_acc(lex_args, cpp_template_params);
    this->gen_cpp_fun_proto_acc(lex_args, mods, ret, fun_name, params);
    Q_->qq_args_acc(lex_args, ";");
    auto decl = Q_->qq_inner(Some<string>("Decl"), lex_args);

    return this->gen_cpp_decl_ns_wrap(decl_ns, decl);
}


inline void CppGenContext::gen_cpp_template_params_acc(
    LexOutput_T& dst, NodeV cpp_template_params) {

    if (cpp_template_params->length() > 0) {
        Q_->qq_args_acc(dst, "template <");
        bool fresh = true;
        for (auto param : *cpp_template_params) {
            if (!fresh) {
                Q_->qq_args_acc(dst, ",");
            }
            fresh = false;
            Q_->qq_args_acc(dst, "typename", param);
        }
        Q_->qq_args_acc(dst, ">");
    }
}


inline void CppGenContext::gen_cpp_template_args_acc(LexOutput_T& dst, NodeV cpp_template_params) {
    if (cpp_template_params->length() > 0) {
        Q_->qq_args_acc(dst, "<");
        bool fresh = true;
        for (auto param : *cpp_template_params) {
            if (!fresh) {
                Q_->qq_args_acc(dst, ",");
            }
            fresh = false;
            Q_->qq_args_acc(dst, param);
        }
        Q_->qq_args_acc(dst, ">");
    }
}


inline cc::Node_T CppGenContext::gen_cpp_id_with_template_args_acc(
    NodeR id, NodeV cpp_template_params) {

    auto lex_args = Q_->make_lex_builder();
    Q_->qq_args_acc(lex_args, id);
    this->gen_cpp_template_args_acc(lex_args, cpp_template_params);
    return Q_->qq_inner(Some<string>("Expr"), lex_args);
}


inline cc::Node_T CppGenContext::gen_cpp_fun_body(
    NodeV cpp_template_params, NodeV mods, NodeRM ret, NodeR fun_name, NodeV params,
    NodeV init_exprs, NodeV body, bool const_post) {

    auto lex_args = Q_->make_lex_builder();

    this->gen_cpp_template_params_acc(lex_args, cpp_template_params);

    this->gen_cpp_fun_proto_acc(lex_args, mods, ret, fun_name, params);
    if (init_exprs->length() > 0) {
        Q_->qq_args_acc(lex_args, ":");
        bool fresh = true;
        for (const auto& init_expr : *init_exprs) {
            if (!fresh) {
                Q_->qq_args_acc(lex_args, ",");
            }
            fresh = false;
            Q_->qq_args_acc(lex_args, init_expr);
        }
    }

    if (const_post) {
        Q_->qq_args_acc(lex_args, "const");
    }

    Q_->qq_args_acc(lex_args, "{");
    for (const auto& stmt : *body) {
        Q_->qq_args_acc(lex_args, stmt);
    }
    Q_->qq_args_acc(lex_args, "}");
    return Q_->qq_inner(Some<string>("Decl"), lex_args);
}


template<typename Ty>
inline cc::Node_T CppGenContext::gen_cpp_param_acc(Vec_T<cc::Node_T>& dst,
    const GenName& ns, const Ty& type, const string& name_hint) {

    auto id_param = this->gen_id_fresh(ns, name_hint);
    auto cpp_param_var = this->gen_cpp_id_base(id_param);
    auto cpp_param = this->qq("Param", type, cpp_param_var);
    dst->push_back(cpp_param);
    return cpp_param_var;
}



inline cc::Node_T CppGenContext::gen_cpp_ret(NodeR x) {
    return Q_->qq_ext(Some<string>("Stmt"), "return", x, ";");
}


inline cc::Node_T CppGenContext::gen_cpp_init_list_u16(const Vec_T<Int>& v) {
    auto lex_args = Q_->make_lex_builder();

    Q_->qq_args_acc(lex_args, "{");
    bool fresh = true;
    for (auto vi : *v) {
        if (!fresh) {
            Q_->qq_args_acc(lex_args, ",");
        }
        fresh = false;
        AT(vi <= 0xffff);
        AT(vi >= 0);
        string s = "0x";
        s += hex_byte_display(static_cast<u8>((vi & 0xff00) >> 8));
        s += hex_byte_display(static_cast<u8>(vi & 0xff));
        Q_->qq_args_acc(lex_args, s);
    }
    Q_->qq_args_acc(lex_args, "}");

    return Q_->qq_inner(Some<string>("Expr"), lex_args);
}


inline cc::Node_T CppGenContext::gen_cpp_decl_ns_wrap(GenName decl_ns, const cc::Node_T& decl) {
    auto ret = decl;
    if (decl_ns->length() > 0) {
        auto cpp_decl_ns = name_to_cpp_direct(decl_ns, *this);
        ret = Q_->qq_ext(Some<string>("Decl"), "namespace", cpp_decl_ns, " { ", decl, " } ");
    }
    return ret;
}


inline cc::Node_T CppGenContext::gen_cpp_rc_ptr(const cc::Node_T& val) {
    return Q_->qq_ext(Some<string>("Expr"), "rc_ptr<", val, ">");
}


inline cc::Node_T CppGenContext::gen_cpp_id_base(const IdBase& id_base) {
    return Q_->qq_ext(Some<string>("Expr"), id_base);    
}
