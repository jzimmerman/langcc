
#include "langcc_common.hpp"

namespace common::NameMaybeBase {
    inline IdentBase_T force(NameMaybeBase_T nm, LangCompileContext& ctx) {
        if (nm->is_Name()) {
            return nm->as_Name()->id_;
        } else if (nm->is_Blame()) {
            ctx.error(nm->as_Blame()->e_, "Expression must have a name");
            AX();
        } else {
            AX();
        }
    }
}


namespace common::NameMaybe {
    inline NameMaybe_T from_ident(Ident_T id) {
        auto items = make_rc<Vec<NameMaybeBase_T>>();
        for (auto id_i : *id->xs_) {
            items->push_back(NameMaybeBase::Name::make(id_i));
        }
        return NameMaybe::make(items);
    }

    inline NameMaybe_T singleton(NameMaybeBase_T item) {
        auto items = make_rc<Vec<NameMaybeBase_T>>();
        items->push_back(item);
        return NameMaybe::make(items);
    }

    inline NameMaybe_T with_sub(
        NameMaybe_T nm, NameMaybeBase_T item, Option_T<IdentBase_T> item_default,
        LangCompileContext& ctx) {

        auto ret_items = make_rc<Vec<NameMaybeBase_T>>();
        for (auto item_i : *nm->items_) {
            ret_items->push_back(item_i);
        }
        bool default_ok = false;
        if (item_default.is_some()) {
            if (!ctx.parser_name_strict_ || item_default.as_some()->is_ItemInner()) {
                default_ok = true;
            }
        }

        if (item->is_Name()) {
            ret_items->push_back(item);
        } else if (default_ok) {
            ret_items->push_back(NameMaybeBase::Name::make(item_default.as_some()));
        } else {
            ret_items->push_back(item);
        }

        return NameMaybe::make(ret_items);
    }

    inline Ident_T force(NameMaybe_T nm, LangCompileContext& ctx) {
        auto ret_items = make_rc<Vec<IdentBase_T>>();
        for (auto nm_i : *nm->items_) {
            ret_items->push_back(NameMaybeBase::force(nm_i, ctx));
        }
        return Ident::make(ret_items);
    }
}


pair<Vec_T<Sym_T>, Vec_T<bool>> sym_flatten_result_extract_vec(
    Vec_T<SymFlattenResult_T> rhs) {

    auto ret_sym = make_rc<Vec<Sym_T>>();
    auto ret_unfold = make_rc<Vec<bool>>();
    for (auto xi : *rhs) {
        ret_sym->push_back(xi->sym_);
        ret_unfold->push_back(xi->unfold_);
    }
    return make_pair(ret_sym, ret_unfold);
}


pair<Vec_T<Sym_T>, Vec_T<bool>> sym_flatten_result_extract_vec(
    Vec_T<SymFlattenResultCPS_T> rhs) {

    auto ret_sym = make_rc<Vec<Sym_T>>();
    auto ret_unfold = make_rc<Vec<bool>>();
    for (auto xi : *rhs) {
        ret_sym->push_back(xi->sym_);
        ret_unfold->push_back(xi->unfold_);
    }
    return make_pair(ret_sym, ret_unfold);
}


pair<Sym_T, SymFlattenResult_T> parser_flatten_gen_nonterm(
    LangCompileContext& ctx, Sym_T sym, Rule_T rule_ctx, bool unfold,
    Option_T<ParseExpr_T> src) {

    auto rule_ident = parse_expr_id_to_ident(rule_ctx->name_);

    auto lhs_sym = ctx.Np_->operator[](rule_ident);
    auto dom_lhs = ctx.parser_attr_domains_->operator[](lhs_sym);

    AT(!ctx.Gr_flat_->nonterm_->contains(sym));
    Grammar::add_nonterm(ctx.Gr_flat_, sym);

    auto ret = SymFlattenResult::make(sym, unfold, attr_leaf_lift_expr(src));
    return make_pair(sym, ret);
}


void parser_Gr_flat_add_prod(
    LangCompileContext& ctx,
    Sym_T lhs,
    Option_T<AttrLeaf_T> lhs_leaf,
    Vec_T<SymFlattenResult_T> rhs,
    meta::Node::ParserDecl::Rule_T rule_ctx,
    UnwindInstr_T rd_instr) {

    auto [rhs_sym, rhs_unfold] = sym_flatten_result_extract_vec(rhs);

    auto rule_name = parse_expr_id_to_ident(rule_ctx->name_);
    auto rule_ind = ctx.parser_rule_inds_->operator[](rule_name);
    if (!ctx.Gr_flat_prod_gensyms_->contains_key(rule_ind)) {
        ctx.Gr_flat_prod_gensyms_->insert(rule_ind, make_rc<Gensym>());
    }
    auto sub_ind = ctx.Gr_flat_prod_gensyms_->operator[](rule_ind)->gen();

    auto prod_id = ProdId::Explicit::make(rule_ind, sub_ind);

    auto [prod, is_new] = Grammar::add_prod(ctx.Gr_flat_, lhs, rhs_sym, prod_id, rhs_unfold);
    AT(is_new);

    auto rhs_leaves = make_rc<Vec<Option_T<AttrLeaf_T>>>();
    for (auto xi : *rhs) {
        rhs_leaves->push_back(xi->attr_leaf_);
    }

    ctx.Gr_flat_lhs_flatten_leaves_->insert_strict(prod, lhs_leaf);
    ctx.Gr_flat_rhs_flatten_leaves_->insert_strict(prod, rhs_leaves);

    ctx.gen_rd_map_->insert_strict(prod, rd_instr);
}


inline SymFlattenResult_T parser_resolve_base(LangCompileContext& ctx, ParseExpr_Base_T xb) {
    bool is_term = ctx.tokens_top_by_id_rev_.contains_key(xb);
    bool is_nonterm = false;

    if (xb->tok_->is_Id()) {
        is_nonterm = ctx.Np_->contains_key(
            parse_expr_id_to_ident(xb->src_.as_some()->as_Id()->id__));
    }

    if (is_term && is_nonterm) {
        ctx.error(xb->src_.as_some(),
            "Parser rule case cannot duplicate a top-level lexer token");
    }

    if (!is_term && !is_nonterm) {
        ctx.error(xb->src_.as_some(),
            "Leaf expression not found (must be either a parser rule or a top-level lexer token)");
    }

    if (is_term) {
        auto term_sym = Sym::Term::make(xb);
        Grammar::add_term(ctx.Gr_flat_, term_sym);
        bool unfold = false;
        return SymFlattenResult::make(term_sym, unfold, attr_leaf_lift_expr(xb->src_));
    } else if (is_nonterm) {
        auto e_id = parse_expr_id_to_ident(xb->src_.as_some()->as_Id()->id__);
        auto r = ctx.Np_->operator[](e_id);
        AT(ctx.Gr_flat_->nonterm_->contains(r));
        bool unfold = ctx.parse_expr_props_->operator[](xb->src_.as_some()->id_)->unfold_;
        auto xe = xb->src_.as_some();
        return SymFlattenResult::make(r, unfold, attr_leaf_lift_expr(xb->src_));
    } else {
        AX();
    }
}


inline NameMaybeBase_T parser_flatten_lookup_name(
    ParseExpr_T x, LangCompileContext& ctx) {

    while (x->is_Paren()) {
        x = x->as_Paren()->x_;
    }

    auto props = ctx.parse_expr_props_->operator[](x->id_);
    if (props->name_.is_some()) {
        return NameMaybeBase::Name::make(props->name_.as_some());
    } else {
        return NameMaybeBase::Blame::make(x);
    }
}


inline tuple<WriteInstr_T, GenType_T, IsOwnDatatype> parser_flatten_expr_acc_new(
    ParseExpr_T x,
    Sym_T dst,
    Option_T<AttrLeaf_T> lhs_leaf,
    NameMaybe_T id,
    bool owns_id,
    meta::Node::ParserDecl::Rule_T rule_ctx,
    LangCompileContext& ctx);


inline tuple<
    SymFlattenResult_T, WriteInstr_T, GenType_T, IsOwnDatatype> parser_flatten_expr_base_new(
    ParseExpr_Base_T xb,
    NameMaybe_T id,
    meta::Node::ParserDecl::Rule_T rule_ctx,
    LangCompileContext& ctx) {

    auto ret_fl = parser_resolve_base(ctx, xb);
    WriteInstr_T ret_wr;
    GenType_T x_ty;

    if (xb->tok_->is_Id()) {
        auto id = parse_expr_id_to_ident(xb->src_.as_some()->as_Id()->id__);
        if (ctx.tokens_top_by_id_rev_.contains_key(xb)) {
            if (parse_expr_is_parse_phase_const(xb->src_.as_some())) {
                x_ty = GenType::Nil::make();
                auto x_str = parse_expr_extract_write_phase_const(xb->src_.as_some());
                ret_wr = WriteInstr::String::make(x_str);
                return make_tuple(ret_fl, ret_wr, x_ty, IsOwnDatatype::N);
            } else {
                x_ty = GenType::String::make();
                ret_wr = WriteInstr::Prim::make();
                return make_tuple(ret_fl, ret_wr, x_ty, IsOwnDatatype::N);
            }
        } else {
            x_ty = GenType::Named::make(id);
            ret_wr = WriteInstr::Rec::make(id);
            return make_tuple(ret_fl, ret_wr, x_ty, IsOwnDatatype::N);
        }
    } else if (xb->tok_->is_LitStr()) {
        auto xc = xb->tok_->as_LitStr();
        string s;
        for (auto c : *xc->cs_) {
            s += utf8_encode(c);
        }
        ret_wr = WriteInstr::String::make(s);
        x_ty = GenType::Nil::make();
        return make_tuple(ret_fl, ret_wr, x_ty, IsOwnDatatype::N);
    } else if (xb->tok_->is_Special()) {
        auto xc = xb->tok_->as_Special();
        if (xb->tok_->as_Special()->w_ == TokenBaseSpecial::Newline) {
            ret_wr = WriteInstr::Newline::make();
        } else if (xb->tok_->as_Special()->w_ == TokenBaseSpecial::Indent) {
            ret_wr = WriteInstr::Indent::make();
        } else if (xb->tok_->as_Special()->w_ == TokenBaseSpecial::Dedent) {
            ret_wr = WriteInstr::Dedent::make();
        } else {
            ret_wr = WriteInstr::Pass::make();
        }
        x_ty = GenType::Nil::make();
        return make_tuple(ret_fl, ret_wr, x_ty, IsOwnDatatype::N);
    } else {
        AX();
    }
}


inline tuple<SymFlattenResult_T, WriteInstr_T, GenType_T, IsOwnDatatype> parser_flatten_expr_new(
    ParseExpr_T x,
    NameMaybe_T id,
    bool owns_id,
    meta::Node::ParserDecl::Rule_T rule_ctx,
    LangCompileContext& ctx) {

    while (x->is_Paren()) {
        x = x->as_Paren()->x_;
    }

    // Optimization: Avoid generating an additional nonterminal if we are at a base case.
    auto xbm = parse_expr_to_base_maybe(x);
    if (xbm.is_some()) {
        auto xb = xbm.as_some();
        return parser_flatten_expr_base_new(xb, id, rule_ctx, ctx);
    } else {
        auto id_gensym = ctx.Gr_flat_nonterm_gensym_->gen();
        auto [r_sym, r_fl] = parser_flatten_gen_nonterm(
            ctx, Sym::Direct::make(x, id_gensym), rule_ctx, true, Some<ParseExpr_T>(x));
        auto [r_wr, r_ty, is_dt] = parser_flatten_expr_acc_new(
            x, r_sym, None<AttrLeaf_T>(), id, owns_id, rule_ctx, ctx);
        return make_tuple(r_fl, r_wr, r_ty, is_dt);
    }
}


inline void parse_expr_squash_concat_rec_acc(
    Vec_T<ParseExpr_T>& dst, ParseExpr_T x, LangCompileContext& ctx) {

    if (x->is_Concat()) {
        auto x_nm = ctx.parse_expr_props_->operator[](x->id_)->name_;
        if (x_nm.is_some()) {
            dst->push_back(x);
        } else {
            for (auto y : *x->as_Concat()->xs_) {
                parse_expr_squash_concat_rec_acc(dst, y, ctx);
            }
        }
    } else if (x->is_Paren()) {
        parse_expr_squash_concat_rec_acc(dst, x->as_Paren()->x_, ctx);
    } else {
        dst->push_back(x);
    }
}


inline Vec_T<ParseExpr_T> parse_expr_squash_concat_rec(
    Vec_T<ParseExpr_T> xs, LangCompileContext& ctx) {

    auto ret = make_rc<Vec<ParseExpr_T>>();
    for (auto x : *xs) {
        parse_expr_squash_concat_rec_acc(ret, x, ctx);
    }
    return ret;
}

inline pair<bool, bool> parser_flatten_expr_concat_acc_extract_spec(
    Vec_T<ParseExpr_T> ys, bool allow_passthrough, LangCompileContext& ctx);

// Conservative approximation
inline bool parser_flatten_predict_is_dt_conservative(
    ParseExpr_T x, LangCompileContext& ctx) {

    if (x->is_Paren()) {
        return parser_flatten_predict_is_dt_conservative(x->as_Paren()->x_, ctx);
    } else if (x->is_Alt()) {
        return true;
    } else if (x->is_Concat()) {
        auto ys = x->as_Concat()->xs_;
        ys = parse_expr_squash_concat_rec(ys, ctx);
            // Spurious nested concats may arise from alias expansion.
        auto [is_empty, is_singleton] =
            parser_flatten_expr_concat_acc_extract_spec(ys, true, ctx);
        return !is_empty && !is_singleton;
    } else {
        return false;
    }
}


inline pair<bool, bool> parser_flatten_expr_concat_acc_extract_spec(
    Vec_T<ParseExpr_T> ys, bool allow_passthrough, LangCompileContext& ctx) {

    bool is_empty = false;
    bool is_singleton = false;

    auto nontrivial_inds = make_rc<Vec<Int>>();
    for (Int i = 0; i < ys->length(); i++) {
        if (!parse_expr_is_parse_phase_const(ys->operator[](i))) {
            nontrivial_inds->push_back(i);
        }
    }

    if (nontrivial_inds->length() == 1) {
        auto i_nt = nontrivial_inds->operator[](0);
        auto yi_nt = ys->operator[](i_nt);
        auto yi_nm = ctx.parse_expr_props_->operator[](yi_nt->id_)->name_;
        if (yi_nm.is_none()) {
            is_singleton = true;
        }
        if (!allow_passthrough && !parser_flatten_predict_is_dt_conservative(yi_nt, ctx)) {
            is_singleton = false;
        }
    } else if (nontrivial_inds->length() == 0) {
        is_empty = true;
    }

    if (!allow_passthrough) {
        is_empty = false;
    }

    return make_pair(is_empty, is_singleton);
}


inline tuple<WriteInstr_T, GenType_T, IsOwnDatatype> parser_flatten_expr_concat_acc_new(
    Vec_T<ParseExpr_T> xs,
    Sym_T dst,
    Option_T<AttrLeaf_T> lhs_leaf,
    NameMaybe_T id,
    bool owns_id,
    meta::Node::ParserDecl::Rule_T rule_ctx,
    bool allow_passthrough,
    LangCompileContext& ctx);


inline tuple<WriteInstr_T, GenType_T, IsOwnDatatype> parser_flatten_expr_alt_acc_new(
    ParseExpr_T x,
    Sym_T dst,
    Option_T<AttrLeaf_T> lhs_leaf,
    NameMaybe_T id,
    bool owns_id,
    meta::Node::ParserDecl::Rule_T rule_ctx,
    LangCompileContext& ctx) {

    auto ys = x->as_Alt()->xs_;

    auto ret_wr_cases = make_rc<Map<IdentBase_T, WriteInstr_T>>();
    auto ret_dt_cases = make_rc<Map<IdentBase_T, GenType_T>>();

    auto id_f = NameMaybe::force(id, ctx);

    for (Int i = 0; i < ys->length(); i++) {
        auto yi = ys->operator[](i);
        auto id_sub_yi = NameMaybe::with_sub(
            id, parser_flatten_lookup_name(yi, ctx),
            Some<IdentBase_T>(IdentBase::Ordinal::make(i)), ctx);
        auto id_gensym = ctx.Gr_flat_nonterm_gensym_->gen();
        auto [ri_sym, ri_fl] = parser_flatten_gen_nonterm(
            ctx, Sym::Direct::make(yi, id_gensym), rule_ctx, true,
            Some<ParseExpr_T>(yi));

        auto yi_is_dt_pred = parser_flatten_predict_is_dt_conservative(yi, ctx);

        WriteInstr_T yi_wr;
        GenType_T yi_ty;
        IsOwnDatatype yi_is_dt;
        if (!yi_is_dt_pred) {
            auto yi_vec = make_rc<Vec<ParseExpr_T>>();
            yi_vec->push_back(yi);
            auto [yi_wr_inner, yi_ty_inner, yi_is_dt_inner] = parser_flatten_expr_concat_acc_new(
                yi_vec, ri_sym, None<AttrLeaf_T>(), id_sub_yi, true, rule_ctx, false, ctx);
            yi_wr = yi_wr_inner; yi_ty = yi_ty_inner; yi_is_dt = yi_is_dt_inner;
        } else {
            auto [yi_wr_inner, yi_ty_inner, yi_is_dt_inner] = parser_flatten_expr_acc_new(
                yi, ri_sym, None<AttrLeaf_T>(), id_sub_yi, true, rule_ctx, ctx);
            yi_wr = yi_wr_inner; yi_ty = yi_ty_inner; yi_is_dt = yi_is_dt_inner;
        }

        auto id_sub_yi_f = NameMaybe::force(id_sub_yi, ctx);
        auto [id_f, yi_nm_f] = Ident::split_last(id_sub_yi_f);

        auto yi_wr_final = yi_wr;
        if (ctx.gen_dt_map_->contains_key(id_sub_yi_f)) {
            yi_wr_final = WriteInstr::Rec::make(id_sub_yi_f);
        }

        UnwindInstr_T rd_instr = UnwindInstr::SumCons::make(id_f, yi_nm_f);

        auto ri_fl_v = make_rc<Vec<SymFlattenResult_T>>();
        ri_fl_v->push_back(ri_fl);

        auto yi_v = make_rc<Vec<Option_T<ParseExpr_T>>>();
        yi_v->push_back(None<ParseExpr_T>());

        parser_Gr_flat_add_prod(ctx, dst, lhs_leaf, ri_fl_v, rule_ctx, rd_instr);

        ret_wr_cases->insert(yi_nm_f, yi_wr_final);
        ret_dt_cases->insert(yi_nm_f, yi_ty);

        ctx.gen_dt_parent_mapping_->insert(id_sub_yi_f, make_pair(id_f, yi_nm_f));
    }

    WriteInstr_T ret_wr = WriteInstr::WithSumCase::make(id_f, ret_wr_cases);

    auto ret_dt_fields = make_rc<Map<IdentBase_T, GenType_T>>();
    auto ret_dt = GenDatatype::make(
        ret_dt_fields, Some<Map_T<IdentBase_T, GenType_T>>(ret_dt_cases));
    GenType_T ret_ty = GenType::Datatype::make(id_f, ret_dt);

    if (owns_id) {
        ctx.gen_wr_map_->insert_strict(id_f, ret_wr);
        ctx.gen_dt_map_->insert_strict(id_f, ret_ty);
        ret_ty = GenType::Named::make(id_f);
        ret_wr = WriteInstr::Rec::make(id_f);
    }

    return make_tuple(ret_wr, ret_ty, IsOwnDatatype::Y);
}


inline tuple<WriteInstr_T, GenType_T, IsOwnDatatype> parser_flatten_expr_optional_acc_new(
    ParseExpr_T x,
    Sym_T dst,
    Option_T<AttrLeaf_T> lhs_leaf,
    NameMaybe_T id,
    bool owns_id,
    meta::Node::ParserDecl::Rule_T rule_ctx,
    LangCompileContext& ctx) {

    auto y = x->as_Optional()->x_;

    auto id_sub_y = id;
    // Do not introduce new name domain, as generated type is Option_T or bool (not named).

    auto [y_fl, y_wr, y_ty, y_is_dt] = parser_flatten_expr_new(
        y, id_sub_y, owns_id, rule_ctx, ctx);

    GenType_T ret_ty;
    WriteInstr_T ret_wr;

    auto id_f = NameMaybe::force(id, ctx);

    if (y_ty->is_Nil()) {
        ret_ty = GenType::Bool::make();
        ret_wr = WriteInstr::WithOptBool::make(id_f, y_wr);
    } else {
        ret_ty = GenType::Optional::make(y_ty);
        ret_wr = WriteInstr::WithOpt::make(id_f, y_wr);
    }

    auto rd_instr_some = UnwindInstr::OptSome::make(id_f, y_ty);
    auto rd_instr_none = UnwindInstr::OptNone::make(id_f, y_ty);
    auto rd_instr_true = UnwindInstr::True::make(y_ty);
    auto rd_instr_false = UnwindInstr::False::make();

    UnwindInstr_T rd_instr_0, rd_instr_1;
    if (y_ty->is_Nil()) {
        rd_instr_0 = rd_instr_false;
        rd_instr_1 = rd_instr_true;
    } else {
        rd_instr_0 = rd_instr_none;
        rd_instr_1 = rd_instr_some;
    }

    // y? -> y
    {
        auto y_fl_v = make_rc<Vec<SymFlattenResult_T>>();
        y_fl_v->push_back(y_fl);
        parser_Gr_flat_add_prod(ctx, dst, lhs_leaf, y_fl_v, rule_ctx, rd_instr_1);
    }

    // y? -> eps
    {
        auto y_v = make_rc<Vec<Option_T<ParseExpr_T>>>();
        auto y_fl_v = make_rc<Vec<SymFlattenResult_T>>();
        parser_Gr_flat_add_prod(ctx, dst, lhs_leaf, y_fl_v, rule_ctx, rd_instr_0);
    }

    return make_tuple(ret_wr, ret_ty, IsOwnDatatype::N);
}


inline tuple<WriteInstr_T, GenType_T, IsOwnDatatype> parser_flatten_expr_concat_acc_new(
    Vec_T<ParseExpr_T> ys,
    Sym_T dst,
    Option_T<AttrLeaf_T> lhs_leaf,
    NameMaybe_T id,
    bool owns_id,
    meta::Node::ParserDecl::Rule_T rule_ctx,
    bool allow_passthrough,
    LangCompileContext& ctx) {

    ys = parse_expr_squash_concat_rec(ys, ctx);
    // Spurious nested concats may arise from alias expansion.

    auto ret_fl_items = make_rc<Vec<SymFlattenResult_T>>();
    auto ret_wr_items = make_rc<Vec<WriteInstr_T>>();
    auto ret_dt_items = make_rc<Map<IdentBase_T, GenType_T>>();
    auto ret_args_ind_map = make_rc<Map<IdentBase_T, Int>>();

    auto [is_empty, is_singleton] = parser_flatten_expr_concat_acc_extract_spec(
        ys, allow_passthrough, ctx);

    Int i_nonempty = 0;
    Int i_name_gen = 0;

    GenType_T ret_ty_singleton = GenType::String::make();
    auto ret_i_nonempty_singleton = None<Int>();

    auto rhs_tys = make_rc<Vec<GenType_T>>();

    auto ret_expr_items = make_rc<Vec<Option_T<ParseExpr_T>>>();

    auto yi_is_dt_any = IsOwnDatatype::N;

    for (Int i = 0; i < ys->length(); i++) {
        auto yi = ys->operator[](i);

        if (parse_expr_is_parse_phase_empty_base(yi)) {
            ret_wr_items->push_back(
                WriteInstr::String::make(parse_expr_extract_write_phase_const(yi)));
            continue;
        }

        Option_T<IdentBase_T> yi_nm_default = None<IdentBase_T>();
        if (!parse_expr_is_parse_phase_const(yi)) {
            yi_nm_default = Some<IdentBase_T>(IdentBase::Ordinal::make(i_name_gen));
            ++i_name_gen;
        }

        auto id_sub_yi = id;
        bool owns_id_sub = owns_id;
        if (!is_singleton) {
            id_sub_yi = NameMaybe::with_sub(
                id, parser_flatten_lookup_name(yi, ctx), yi_nm_default, ctx);
        } else {
            owns_id_sub = false;
        }

        auto [yi_fl, yi_wr, yi_ty, yi_is_dt] = parser_flatten_expr_new(
            yi, id_sub_yi, owns_id_sub, rule_ctx, ctx);

        if (yi_is_dt == IsOwnDatatype::Y) {
            yi_is_dt_any = IsOwnDatatype::Y;
        }

        if (!parse_expr_is_parse_phase_empty_base(yi)) {
            ret_expr_items->push_back(Some<ParseExpr_T>(yi));
            ret_fl_items->push_back(yi_fl);
            rhs_tys->push_back(yi_ty);
        }

        if (!parse_expr_is_parse_phase_const(yi)) {
            if (!is_singleton) {
                auto [_, yi_nm_f] = Ident::split_last(NameMaybe::force(id_sub_yi, ctx));
                ret_args_ind_map->insert_strict(yi_nm_f, i_nonempty);
                ret_wr_items->push_back(WriteInstr::WithField::make(yi_nm_f, yi_wr));
                ret_dt_items->insert_strict(yi_nm_f, yi_ty);
            } else {
                ret_i_nonempty_singleton = Some<Int>(i_nonempty);
                ret_ty_singleton = yi_ty;
                ret_wr_items->push_back(yi_wr);
            }
        } else if (yi->is_Newline()) {
            ret_wr_items->push_back(WriteInstr::Newline::make());
        } else if (yi->is_Indent()) {
            ret_wr_items->push_back(WriteInstr::Indent::make());
        } else if (yi->is_Dedent()) {
            ret_wr_items->push_back(WriteInstr::Dedent::make());
        } else {
            auto yi_const_str = parse_expr_extract_write_phase_const(yi);
            ret_wr_items->push_back(WriteInstr::String::make(yi_const_str));
        }

        ++i_nonempty;
    }

    UnwindInstr_T rd_instr;
    GenType_T ret_ty;

    auto is_own_dt = IsOwnDatatype::N;
    if (is_empty) {
        rd_instr = UnwindInstr::Nil::make(rhs_tys);
        ret_ty = GenType::Nil::make();
    } else if (is_singleton) {
        rd_instr = UnwindInstr::SelectIndex::make(ret_i_nonempty_singleton.as_some(), rhs_tys);
        ret_ty = ret_ty_singleton;
        if (yi_is_dt_any == IsOwnDatatype::Y) {
            is_own_dt = IsOwnDatatype::Y;
        }
    } else {
        auto id_f = NameMaybe::force(id, ctx);
        rd_instr = UnwindInstr::ProdCons::make(id_f, ret_args_ind_map, rhs_tys);
        auto ret_dt = GenDatatype::make(ret_dt_items, None<Map_T<IdentBase_T, GenType_T>>());
        ret_ty = GenType::Datatype::make(id_f, ret_dt);
        is_own_dt = IsOwnDatatype::Y;
    }

    parser_Gr_flat_add_prod(ctx, dst, lhs_leaf, ret_fl_items, rule_ctx, rd_instr);

    WriteInstr_T ret_wr = WriteInstr::Seq::make(ret_wr_items);

    if (owns_id && is_own_dt == IsOwnDatatype::Y) {
        auto id_f = NameMaybe::force(id, ctx);
        ctx.gen_wr_map_->insert_strict(id_f, ret_wr);
        ctx.gen_dt_map_->insert_strict(id_f, ret_ty);
        ret_ty = GenType::Named::make(id_f);
        ret_wr = WriteInstr::Rec::make(id_f);
    }

    return make_tuple(ret_wr, ret_ty, is_own_dt);
}


inline tuple<WriteInstr_T, GenType_T, IsOwnDatatype> parser_flatten_expr_iter_acc_new(
    ParseExpr_T x,
    Sym_T dst,
    Option_T<AttrLeaf_T> lhs_leaf,
    NameMaybe_T id,
    bool owns_id,
    meta::Node::ParserDecl::Rule_T rule_ctx,
    LangCompileContext& ctx) {

    meta::Node::ParseExpr_T y_raw;
    if (x->is_Rep()) {
        y_raw = x->as_Rep()->x_;
    } else if (x->is_RepNonzero()) {
        y_raw = x->as_RepNonzero()->x_;
    } else if (x->is_List()) {
        y_raw = x->as_List()->elem_;
    } else {
        AX();
    }

    auto y = y_raw;

    auto y_name_default = IdentBase::ItemInner::make();
    auto id_sub_y = NameMaybe::with_sub(
        id, parser_flatten_lookup_name(y, ctx),
        Some<IdentBase_T>(IdentBase::ItemInner::make()), ctx);

    auto rd_instr_id = UnwindInstr::Identity::make();

    auto [y_fl, y_wr, y_ty, y_is_dt] = parser_flatten_expr_new(
        y, id_sub_y, true, rule_ctx, ctx);

    auto id_gensym = ctx.Gr_flat_nonterm_gensym_->gen();
    auto [yl_sym, yl_fl] = parser_flatten_gen_nonterm(
        ctx, Sym::Iter::make(y, id_gensym), rule_ctx, true, None<ParseExpr_T>());

    auto id_f = NameMaybe::force(id, ctx);

    WriteInstr_T ret_wr;
    GenType_T ret_ty;

    if (x->is_Rep() || x->is_RepNonzero()) {
        if (x->is_Rep()) {
            // dst -> eps
            {
                auto rhs_fl_v = make_rc<Vec<SymFlattenResult_T>>();
                parser_Gr_flat_add_prod(ctx, dst, lhs_leaf, rhs_fl_v, rule_ctx,
                    UnwindInstr::VecEmpty::make(id_f, y_ty));
            }
        }

        // dst -> yl
        {
            auto rhs_fl_v = make_rc<Vec<SymFlattenResult_T>>();
            rhs_fl_v->push_back(yl_fl);
            parser_Gr_flat_add_prod(ctx, dst, lhs_leaf, rhs_fl_v, rule_ctx,
                UnwindInstr::Identity::make());
        }

        // yl -> y yl
        {
            auto rhs_fl_v = make_rc<Vec<SymFlattenResult_T>>();
            rhs_fl_v->push_back(y_fl);
            rhs_fl_v->push_back(yl_fl);
            parser_Gr_flat_add_prod(
                ctx, yl_sym, None<AttrLeaf_T>(), rhs_fl_v, rule_ctx,
                    UnwindInstr::VecCons::make(id_f, y_ty));
        }

        // yl -> y
        {
            auto rhs_fl_v = make_rc<Vec<SymFlattenResult_T>>();
            rhs_fl_v->push_back(y_fl);
            parser_Gr_flat_add_prod(
                ctx, yl_sym, None<AttrLeaf_T>(), rhs_fl_v, rule_ctx,
                    UnwindInstr::VecSingle::make(id_f, y_ty));
        }

        ret_wr = WriteInstr::RecList::make(
            y_wr, ListFormat::Inline::make(), None<WriteInstr_T>(), HasFinalDelim::N::make());

    } else if (x->is_List()) {
        auto xc = x->as_List();
        Int n_min = 0;
        if (xc->num_->is_Ge0()) {
            n_min = 0;
        } else if (xc->num_->is_Ge1()) {
            n_min = 1;
        } else if (xc->num_->is_Ge2()) {
            n_min = 2;
        } else {
            AX();
        }
        bool allow_empty = n_min == 0;

        HasFinalDelim_T has_final;
        if (xc->end_delim_->is_SOME()) {
            has_final = HasFinalDelim::Y::make();
        } else if (xc->end_delim_->is_OPTIONAL()) {
            has_final = HasFinalDelim::M::make();
        } else if (xc->end_delim_->is_NONE()) {
            has_final = HasFinalDelim::N::make();
        } else {
            AX();
        }

        if (parse_expr_is_parse_phase_empty_base(xc->delim_)) {
            if (n_min == 0) {
                // dst -> eps
                {
                    auto rhs_fl_v = make_rc<Vec<SymFlattenResult_T>>();
                    parser_Gr_flat_add_prod(ctx, dst, lhs_leaf, rhs_fl_v, rule_ctx,
                        UnwindInstr::VecEmpty::make(id_f, y_ty));
                }
            }

            if (n_min == 0 || n_min == 1) {
                // dst -> yl
                {
                    auto rhs_fl_v = make_rc<Vec<SymFlattenResult_T>>();
                    rhs_fl_v->push_back(yl_fl);
                    parser_Gr_flat_add_prod(ctx, dst, lhs_leaf, rhs_fl_v, rule_ctx,
                        UnwindInstr::Identity::make());
                }
            }

            if (n_min == 2) {
                // dst -> y yl
                {
                    auto rhs_fl_v = make_rc<Vec<SymFlattenResult_T>>();
                    rhs_fl_v->push_back(y_fl);
                    rhs_fl_v->push_back(yl_fl);
                    parser_Gr_flat_add_prod(ctx, dst, lhs_leaf, rhs_fl_v, rule_ctx,
                        UnwindInstr::VecCons::make(id_f, y_ty));
                }
            }

            // yl -> y yl
            {
                auto rhs_fl_v = make_rc<Vec<SymFlattenResult_T>>();
                rhs_fl_v->push_back(y_fl);
                rhs_fl_v->push_back(yl_fl);
                parser_Gr_flat_add_prod(
                    ctx, yl_sym, None<AttrLeaf_T>(), rhs_fl_v, rule_ctx,
                        UnwindInstr::VecCons::make(id_f, y_ty));
            }

            // yl -> y
            {
                auto rhs_fl_v = make_rc<Vec<SymFlattenResult_T>>();
                rhs_fl_v->push_back(y_fl);
                parser_Gr_flat_add_prod(
                    ctx, yl_sym, None<AttrLeaf_T>(), rhs_fl_v, rule_ctx,
                        UnwindInstr::VecSingle::make(id_f, y_ty));
            }

        } else {
            if (!parse_expr_is_parse_phase_const(xc->delim_)) {
                ctx.error(xc->delim_, "Delimiter must be a constant expression");
            }

            auto delim = xc->delim_;

            auto id_sub_delim = NameMaybe::with_sub(
                id, parser_flatten_lookup_name(delim, ctx), None<IdentBase_T>(), ctx);
            auto [delim_fl, delim_wr, delim_ty, delim_is_dt] = parser_flatten_expr_new(
                delim, id_sub_delim, true, rule_ctx, ctx);

            if (n_min == 0) {
                // dst -> eps
                {
                    auto rhs_fl_v = make_rc<Vec<SymFlattenResult_T>>();
                    parser_Gr_flat_add_prod(ctx, dst, lhs_leaf, rhs_fl_v, rule_ctx,
                        UnwindInstr::VecEmpty::make(id_f, y_ty));
                }
            }

            if (n_min == 0 || n_min == 1) {
                // dst -> yl
                {
                    auto rhs_fl_v = make_rc<Vec<SymFlattenResult_T>>();
                    rhs_fl_v->push_back(yl_fl);
                    parser_Gr_flat_add_prod(ctx, dst, lhs_leaf, rhs_fl_v, rule_ctx,
                        UnwindInstr::Identity::make());
                }
            }

            if (n_min == 2) {
                // dst -> y d yl
                {
                    auto rhs_fl_v = make_rc<Vec<SymFlattenResult_T>>();
                    rhs_fl_v->push_back(y_fl);
                    rhs_fl_v->push_back(delim_fl);
                    rhs_fl_v->push_back(yl_fl);
                    parser_Gr_flat_add_prod(ctx, dst, lhs_leaf, rhs_fl_v, rule_ctx,
                        UnwindInstr::VecConsDelim::make(id_f, y_ty, delim_ty));
                }
            }

            // yl -> y d yl
            {
                auto rhs_fl_v = make_rc<Vec<SymFlattenResult_T>>();
                rhs_fl_v->push_back(y_fl);
                rhs_fl_v->push_back(delim_fl);
                rhs_fl_v->push_back(yl_fl);
                parser_Gr_flat_add_prod(
                    ctx, yl_sym, None<AttrLeaf_T>(), rhs_fl_v, rule_ctx,
                        UnwindInstr::VecConsDelim::make(id_f, y_ty, delim_ty));
            }

            if (has_final->is_Y() || has_final->is_M()) {
                // yl -> y d
                {
                    auto rhs_fl_v = make_rc<Vec<SymFlattenResult_T>>();
                    rhs_fl_v->push_back(y_fl);
                    rhs_fl_v->push_back(delim_fl);
                    auto rhs_tys = make_rc<Vec<GenType_T>>();
                    rhs_tys->push_back(y_ty);
                    rhs_tys->push_back(delim_ty);
                    parser_Gr_flat_add_prod(
                        ctx, yl_sym, None<AttrLeaf_T>(), rhs_fl_v, rule_ctx,
                            UnwindInstr::VecSingleDelim::make(id_f, y_ty, delim_ty));
                }
            }

            if (has_final->is_M() || has_final->is_N()) {
                // yl -> y
                {
                    auto rhs_fl_v = make_rc<Vec<SymFlattenResult_T>>();
                    rhs_fl_v->push_back(y_fl);
                    parser_Gr_flat_add_prod(
                        ctx, yl_sym, None<AttrLeaf_T>(), rhs_fl_v, rule_ctx,
                            UnwindInstr::VecSingle::make(id_f, y_ty));
                }
            }
        }

        ListFormat_T list_format;
        if (xc->ty_->is_List()) {
            list_format = ListFormat::Inline::make();
        } else if (xc->ty_->is_Block()) {
            list_format = ListFormat::Block::make();
        } else if (xc->ty_->is_Block2()) {
            list_format = ListFormat::Block2::make();
        } else if (xc->ty_->is_Top()) {
            list_format = ListFormat::Top::make();
        } else if (xc->ty_->is_Top2()) {
            list_format = ListFormat::Top2::make();
        } else {
            AX();
        }

        WriteInstr_T delim_instr = WriteInstr::Newline::make();
        if (!xc->delim_->is_Newline()) {
            auto delim_str = parse_expr_extract_write_phase_const(xc->delim_);
            delim_instr = WriteInstr::String::make(delim_str);
        }

        ret_wr = WriteInstr::RecList::make(
            y_wr, list_format, Some<WriteInstr_T>(delim_instr), has_final);

    } else {
        AX();
    }

    auto elem_ty = y_ty;

    ret_ty = GenType::Vector::make(elem_ty);

    AT(!!ret_wr.v_);
    AT(!!ret_ty.v_);

    return make_tuple(ret_wr, ret_ty, IsOwnDatatype::N);
}


inline tuple<WriteInstr_T, GenType_T, IsOwnDatatype> parser_flatten_expr_acc_new(
    ParseExpr_T x,
    Sym_T dst,
    Option_T<AttrLeaf_T> lhs_leaf,
    NameMaybe_T id,
    bool owns_id,
    meta::Node::ParserDecl::Rule_T rule_ctx,
    LangCompileContext& ctx) {

    while (x->is_Paren()) {
        x = x->as_Paren()->x_;
    }

    if (x->is_Alt()) {
        return parser_flatten_expr_alt_acc_new(x, dst, lhs_leaf, id, owns_id, rule_ctx, ctx);

    } else if (x->is_Optional()) {
        return parser_flatten_expr_optional_acc_new(x, dst, lhs_leaf, id, owns_id, rule_ctx, ctx);

    } else if (x->is_Concat()) {
        auto ret = parser_flatten_expr_concat_acc_new(
            x->as_Concat()->xs_, dst, lhs_leaf, id, owns_id, rule_ctx, true, ctx);
        return ret;

    } else if (x->is_List() || x->is_Rep() || x->is_RepNonzero()) {
        return parser_flatten_expr_iter_acc_new(x, dst, lhs_leaf, id, owns_id, rule_ctx, ctx);

    } else if (x->is_Pass() || x->is_Underscore()) {
        auto rd_instr = UnwindInstr::Nil::make(make_rc<Vec<GenType_T>>());
        parser_Gr_flat_add_prod(
            ctx, dst, lhs_leaf, make_rc<Vec<SymFlattenResult_T>>(), rule_ctx, rd_instr);
        auto e_sub_str = parse_expr_extract_write_phase_const(x);
        auto e_sub_wr = WriteInstr::String::make(e_sub_str);
        return make_tuple(e_sub_wr, GenType::Nil::make(), IsOwnDatatype::N);

    } else if (parse_expr_to_base_maybe(x).is_some()) {
        auto xb = parse_expr_to_base_maybe(x).as_some();
        auto x_v = make_rc<Vec<Option_T<ParseExpr_T>>>();
        auto rhs_fl = make_rc<Vec<SymFlattenResult_T>>();
        x_v->push_back(Some<ParseExpr_T>(x));
        auto [x_fl, x_wr, x_ty, x_is_dt] = parser_flatten_expr_base_new(xb, id, rule_ctx, ctx);
        rhs_fl->push_back(x_fl);
        auto rd_instr = UnwindInstr::Identity::make();
        parser_Gr_flat_add_prod(ctx, dst, lhs_leaf, rhs_fl, rule_ctx, rd_instr);
        return make_tuple(x_wr, x_ty, x_is_dt);

    } else {
        LG_ERR("{}", x);
        AX();
    }
}


inline void parser_flatten_grammar_rule_acc(
    LangCompileContext& ctx, meta::Node::ParserDecl::Rule_T rule) {

    auto rule_id = parse_expr_id_to_ident(rule->name_);
    auto rule_id_ctx_init = Some<Ident_T>(rule_id);
    auto dst_sym = ctx.Np_->operator[](rule_id);
    auto dst_sym_outer = dst_sym;

    SymFlattenResult_T s_fl;

    auto y = rule->e_;

    bool y_is_dt_pred = parser_flatten_predict_is_dt_conservative(y, ctx);

    if (!y_is_dt_pred) {
        // Must enforce that the result of the rule is a named datatype,
        // since it becomes an implicit sum case (either of its ident parent,
        // or of the top-level Node).
        auto y_vec = make_rc<Vec<ParseExpr_T>>();
        y_vec->push_back(y);
        parser_flatten_expr_concat_acc_new(
            y_vec, dst_sym, Some<AttrLeaf_T>(AttrLeaf::Lhs::make()),
            NameMaybe::from_ident(rule_id), true, rule, false, ctx);
    } else {
        parser_flatten_expr_acc_new(
            y, dst_sym, Some<AttrLeaf_T>(AttrLeaf::Lhs::make()),
            NameMaybe::from_ident(rule_id), true, rule, ctx);
    }
}


inline void parser_flatten_gen_inline_sum_cases(
    Ident_T id, Map_T<IdentBase_T, Ident_T> ids_sub, LangCompileContext& ctx) {

    auto wr_ids_sub = make_rc<Map<IdentBase_T, WriteInstr_T>>();
    for (auto [id_case, id_sub] : *ids_sub) {
        wr_ids_sub->insert_strict(id_case, WriteInstr::Rec::make(Ident::with_sub(id, id_case)));
    }

    auto wr_sub = WriteInstr::WithSumCase::make(id, wr_ids_sub);
    ctx.gen_wr_map_->insert_strict(id, wr_sub);

    auto dt_cases = make_rc<Map<IdentBase_T, GenType_T>>();
    for (auto [id_case, id_sub] : *ids_sub) {
        dt_cases->insert(id_case, GenType::Named::make(id_sub));
    }
    auto dt_fields = make_rc<Map<IdentBase_T, GenType_T>>();
    auto dt = GenDatatype::make(dt_fields, Some<Map_T<IdentBase_T, GenType_T>>(dt_cases));
    auto ty = GenType::Datatype::make(id, dt);
    ctx.gen_dt_map_->insert_strict(id, ty);
}


void parser_tabulate_syms_top(LangCompileContext& ctx) {
    for (auto tok : ctx.tokens_top_by_id_) {
        auto tok_sym = Sym::Term::make(tok);
        Grammar::add_term(ctx.Gr_flat_, tok_sym);
    }

    auto start = Sym::Start::make();
    Grammar::add_nonterm(ctx.Gr_flat_, start);
    ctx.Gr_flat_->start_ = Some<Sym_T>(start);

    for (auto sym_top : *ctx.parser_syms_top_) {
        auto sym_top_base = Ident::extract_base_strict(sym_top);
        if (!ctx.Nm_->contains_key(sym_top_base)) {
            ctx.error(ctx.parser_,
                fmt_str(
                    "Definition not found for top-level parseable symbol: {}", sym_top_base));
        }
        auto sym_nonterm = ctx.Nm_->operator[](sym_top_base);
        auto sym_term_marker = Sym::TermStartMarker::make(sym_top_base);
        Grammar::add_term(ctx.Gr_flat_, sym_term_marker);
        auto prod_rhs = make_rc<Vec<Sym_T>>();
        prod_rhs->push_back(sym_term_marker);
        prod_rhs->push_back(sym_nonterm);
        auto prod_unfold_mask = make_rc<Vec<bool>>();
        prod_unfold_mask->push_back(false);
        prod_unfold_mask->push_back(false);
        auto prod_id = ProdId::Start::make(sym_nonterm);
        auto [prod, is_new] = Grammar::add_prod(
            ctx.Gr_flat_, start, prod_rhs, prod_id, prod_unfold_mask);
        AT(is_new);
        ctx.Gr_flat_lhs_flatten_leaves_->insert_strict(
            prod, Some<AttrLeaf_T>(AttrLeaf::Lhs::make()));
        auto rhs_leaves = make_rc<Vec<Option_T<AttrLeaf_T>>>();
        rhs_leaves->push_back(None<AttrLeaf_T>());
        rhs_leaves->push_back(None<AttrLeaf_T>());
        ctx.Gr_flat_rhs_flatten_leaves_->insert_strict(prod, rhs_leaves);
    }

    for (auto id : *ctx.parser_rule_non_alias_ids_) {
        auto sym_def = ctx.Nm_->operator[](Ident::extract_base(id));
        ctx.Np_->insert(id, sym_def);
    }
}


void parser_flatten_grammar_rules(LangCompileContext& ctx) {
    for (auto p : *ctx.parser_rule_inds_) {
        auto rule = ctx.parser_rules_->operator[](p.first);
        auto i = p.second;
        if (rule->op_->is_DEF_ALIAS()) {
            continue;
        }
        parser_flatten_grammar_rule_acc(ctx, rule);
    }

    auto wr_inline_cases = make_rc<Map<Ident_T, Map_T<IdentBase_T, Ident_T>>>();
    auto rule_ids = make_rc<Set<Ident_T>>();
    auto id_top = Ident::make(make_rc<Vec<IdentBase_T>>());

    for (auto p : *ctx.parser_rule_inds_) {
        auto rule = ctx.parser_rules_->operator[](p.first);
        auto i = p.second;

        if (rule->op_->is_DEF_ALIAS()) {
            continue;
        }

        auto rule_id = parse_expr_id_to_ident(rule->name_);
        rule_ids->insert(rule_id);

        auto id_acc = id_top;
        for (auto name : *rule_id->xs_) {
            auto id_acc_sub = Ident::with_sub(id_acc, name);
            if (!wr_inline_cases->contains_key(id_acc)) {
                wr_inline_cases->insert(id_acc, make_rc<Map<IdentBase_T, Ident_T>>());
            }
            ctx.gen_dt_parent_mapping_->insert(id_acc_sub, make_pair(id_acc, name));
            wr_inline_cases->operator[](id_acc)->insert(name, id_acc_sub);
            id_acc = id_acc_sub;
        }
    }

    for (auto [id, ids_sub] : *wr_inline_cases) {
        if (val_hash(id) == val_hash(id_top)) {
            continue;  // Deferred to below
        }
        parser_flatten_gen_inline_sum_cases(id, ids_sub, ctx);
    }

    // Orphan nodes (whose parent is not a sum type) are given id_top as their parent.
    for (auto [id, ty] : *ctx.gen_dt_map_) {
        if (ty->is_Datatype() && !ctx.gen_dt_parent_mapping_->contains_key(id)) {
            string id_str;
            bool fresh = true;
            for (auto id_i : *id->xs_) {
                if (!fresh) {
                    id_str += "__";
                }
                fresh = false;
                id_str += fmt_str("{}", id_i);
            }
            auto child_id_flat = IdentBase::User::make(id_str);
            ctx.gen_dt_parent_mapping_->insert(id, make_pair(id_top, child_id_flat));
            wr_inline_cases->operator[](id_top)->insert_strict(child_id_flat, id);
        }
    }

    auto wr_ids_sub_top = wr_inline_cases->operator[](id_top);
    parser_flatten_gen_inline_sum_cases(id_top, wr_ids_sub_top, ctx);

    for (auto sym : *ctx.Gr_flat_->nonterm_) {
        if (!ctx.parser_attr_domains_->contains_key(sym)) {
            ctx.parser_attr_domains_->insert(sym, make_rc<Map<AttrKey_T, AttrType_T>>());
        }
    }
}
