
#include "langcc_common.hpp"

ProdConstrRhsLoc parser_prod_constr_loc_from_attr_clause_expr(
    LangCompileContext& ctx, lang::meta::Node::AttrClauseExprRhsLoc_T loc) {

    if (loc->is_All()) {
        return ProdConstrRhsLoc::All;
    } else if (loc->is_Begin()) {
        return ProdConstrRhsLoc::Begin;
    } else if (loc->is_End()) {
        return ProdConstrRhsLoc::End;
    } else if (loc->is_Mid()) {
        return ProdConstrRhsLoc::Mid;
    } else {
        AX();
    }
}


ProdConstr_T parser_prod_constr_from_attr_clause_expr(LangCompileContext& ctx, AttrClauseExpr_T e) {
    if (e->is_LhsGeq()) {
        auto id = ident_singleton_from_string(e->as_LhsGeq()->k_.to_std_string());
        auto ak = AttrKey::Id::make(None<ProdConstrRhsLoc>(), id);
        return ProdConstr::LhsGeq::make(ak, AttrVal::Bool::make(AttrType::Bool::make(), false));
    } else if (e->is_RhsGeq()) {
        auto id = ident_singleton_from_string(e->as_RhsGeq()->k_.to_std_string());
        auto ak = AttrKey::Id::make(None<ProdConstrRhsLoc>(), id);
        auto loc = parser_prod_constr_loc_from_attr_clause_expr(ctx, e->as_RhsGeq()->loc_);
        return ProdConstr::RhsGeq::make(loc, ak, AttrVal::Bool::make(AttrType::Bool::make(), true));
    } else if (e->is_Implies()) {
        auto id_lhs = ident_singleton_from_string(e->as_Implies()->kl_.to_std_string());
        auto ak_lhs = AttrKey::Id::make(None<ProdConstrRhsLoc>(), id_lhs);
        auto id_rhs = ident_singleton_from_string(e->as_Implies()->kr_.to_std_string());
        auto ak_rhs = AttrKey::Id::make(None<ProdConstrRhsLoc>(), id_rhs);
        auto loc = parser_prod_constr_loc_from_attr_clause_expr(ctx, e->as_Implies()->loc_);
        return ProdConstr::Implies::make(ak_lhs, loc, ak_rhs, AttrType::Bool::make());
    } else {
        AX();
    }
}


void parser_infer_attrs_top_clause_acc(
    LangCompileContext& ctx,
    Vec_T<ProdConstr_T>& dst_constr,
    Sym_T sym, Ident_T id_ctx, Ident_T match_curr, AttrClause_T clause) {

    if (clause->is_Match()) {
        auto cc = clause->as_Match();

        bool found = false;

        for (Int i = 0; i < cc->cases_->length(); i++) {
            auto case_ = cc->cases_->operator[](i);
            if (case_->pat_->is_Wildcard()) {
                if (i < cc->cases_->length() - 1) {
                    ctx.error(case_, "Wildcard may only appear in final position in match clause");
                }

                if (!found) {
                    parser_infer_attrs_top_clause_acc(
                        ctx, dst_constr, sym, id_ctx, match_curr, case_->clause_);
                    found = true;
                }
            } else if (case_->pat_->is_Alt()) {
                auto pc = case_->pat_->as_Alt();
                for (auto pat_id : *pc->items_) {
                    auto match_cand = Ident::with_extend(
                        match_curr, parse_expr_id_to_ident(pat_id));
                    if (Ident::starts_with(id_ctx, match_cand)) {
                        if (found) {
                            ctx.error(case_, fmt_str("Ambiguous match on rule: {}", id_ctx));
                        }
                        found = true;
                        parser_infer_attrs_top_clause_acc(
                            ctx, dst_constr, sym, id_ctx, match_cand, case_->clause_);
                    }
                }
            } else {
                AX();
            }
        }
    } else if (clause->is_Block()) {
        auto cc = clause->as_Block();
        for (auto clause_sub : *cc->items_) {
            parser_infer_attrs_top_clause_acc(
                ctx, dst_constr, sym, id_ctx, match_curr, clause_sub);
        }
    } else if (clause->is_Expr()) {
        auto cc = clause->as_Expr();
        dst_constr->push(parser_prod_constr_from_attr_clause_expr(ctx, cc->e_));
        auto ak = None<AttrKey_T>();
        if (cc->e_->is_LhsGeq()) {
            auto id = ident_singleton_from_string(cc->e_->as_LhsGeq()->k_.to_std_string());
            ak = Some<AttrKey_T>(AttrKey::Id::make(None<ProdConstrRhsLoc>(), id));
        } else if (cc->e_->is_RhsGeq()) {
            // pass
        } else if (cc->e_->is_Implies()) {
            auto id = ident_singleton_from_string(cc->e_->as_Implies()->kl_.to_std_string());
            ak = Some<AttrKey_T>(AttrKey::Id::make(None<ProdConstrRhsLoc>(), id));
        } else {
            AX();
        }
        if (ak.is_some()) {
            ctx.parser_attr_domains_->operator[](sym)->insert(
                ak.as_some(), AttrType::Bool::make());
        }
    } else {
        AX();
    }
}


void parser_infer_attrs_top(LangCompileContext& ctx) {
    // First pass: compute attr domains.
    // This must be done separately since different rules may share the same lhs symbol.
    auto sym_has_prec = make_rc<Map<Sym_T, bool>>();
    auto ident_has_prec = make_rc<Set<Ident_T>>();
    auto ident_prec_level = make_rc<Map<Ident_T, Int>>();
    auto ident_prec_assoc = make_rc<Map<Ident_T, Option_T<meta::Node::PrecAssoc_T>>>();
    for (auto [_, sym] : *ctx.Np_) {
        sym_has_prec->insert(sym, false);
    }
    if (ctx.parser_prec_.is_some()) {
        ctx.parser_prec_n_ = ctx.parser_prec_.as_some()->items_->length();
        Int prec_level_curr = 0;
        for (auto item : *ctx.parser_prec_.as_some()->items_) {
            for (auto id : *item->ids_) {
                auto ident = parse_expr_id_to_ident(id);
                if (!ctx.Np_->contains_key(ident)) {
                    ctx.error(item, fmt_str("Attr constrained identifier not found: {}", ident));
                }
                auto sym = ctx.Np_->operator[](ident);
                sym_has_prec->insert(sym, true);
                if (ident_has_prec->contains(ident)) {
                    ctx.error(item, fmt_str("Duplicate precedence clause for ident: {}", ident));
                }
                ident_has_prec->insert(ident);
                ident_prec_level->insert(ident, prec_level_curr);
                ident_prec_assoc->insert(ident, item->assoc_);
            }
            ++prec_level_curr;
        }
        for (auto p : *ctx.parser_rule_inds_) {
            auto rule = ctx.parser_rules_->operator[](p.first);
            if (rule->op_->is_DEF_ALIAS()) {
                continue;
            }
            auto ident = parse_expr_id_to_ident(rule->name_);
            auto sym = ctx.Np_->operator[](ident);
            if (sym_has_prec->operator[](sym) && !ident_has_prec->contains(ident)) {
                ctx.error(rule,
                    fmt_str("Rule's symbol has precedence, but rule not in prec stanza"));
            }
        }
    }
    for (auto p : *ctx.parser_rule_inds_) {
        auto rule = ctx.parser_rules_->operator[](p.first);
        if (rule->op_->is_DEF_ALIAS()) {
            continue;
        }
        auto ident = parse_expr_id_to_ident(rule->name_);
        auto sym = ctx.Np_->operator[](ident);
        if (!ctx.parser_attr_domains_->contains_key(sym)) {
            ctx.parser_attr_domains_->insert(sym, make_rc<Map<AttrKey_T, AttrType_T>>());
        }
        if (sym_has_prec->operator[](sym)) {
            ctx.parser_attr_domains_->operator[](sym)->insert(
                AttrKey::Prec::make(None<ProdConstrRhsLoc>(), PrecDir::Left),
                AttrType::Range::make(ctx.parser_prec_n_));
            ctx.parser_attr_domains_->operator[](sym)->insert(
                AttrKey::Prec::make(None<ProdConstrRhsLoc>(), PrecDir::Right),
                AttrType::Range::make(ctx.parser_prec_n_));
        }

        auto attr_constr_unused = make_rc<Vec<ProdConstr_T>>();

        if (rule->lhs_attrs_.is_some()) {
            for (auto attr : *rule->lhs_attrs_.as_some()) {
                if (attr->is_PrecStar()) {
                    ctx.error(rule, "Lhs attr req cannot specify pr=*");
                } else if (attr->is_Base()) {
                    auto id = ident_singleton_from_string(attr->as_Base()->k_.to_std_string());
                    auto ak = AttrKey::Id::make(None<ProdConstrRhsLoc>(), id);
                    ctx.parser_attr_domains_->operator[](sym)->insert(ak, AttrType::Bool::make());
                } else {
                    AX();
                }
            }
        }

        for (auto clause : *ctx.parser_attr_clauses_) {
            parser_infer_attrs_top_clause_acc(
                ctx, attr_constr_unused, sym,
                parse_expr_id_to_ident(rule->name_), Ident::empty(), clause);
        }


    }

    // Second pass: compute attr exprs by rule.
    for (auto p : *ctx.parser_rule_inds_) {
        auto rule = ctx.parser_rules_->operator[](p.first);
        if (rule->op_->is_DEF_ALIAS()) {
            continue;
        }

        auto ident = parse_expr_id_to_ident(rule->name_);
        auto sym = ctx.Np_->operator[](ident);

        auto attr_constr = make_rc<Vec<ProdConstr_T>>();

        for (auto clause : *ctx.parser_attr_clauses_) {
            parser_infer_attrs_top_clause_acc(
                ctx, attr_constr, sym, ident, Ident::empty(), clause);
        }

        if (rule->lhs_attrs_.is_some()) {
            for (auto attr : *rule->lhs_attrs_.as_some()) {
                if (attr->is_Base()) {
                    auto id = ident_singleton_from_string(attr->as_Base()->k_.to_std_string());
                    auto ak = AttrKey::Id::make(None<ProdConstrRhsLoc>(), id);
                    attr_constr->push_back(
                        ProdConstr::LhsGeq::make(
                            ak, AttrVal::Bool::make(AttrType::Bool::make(), true)));
                } else {
                    AX();
                }
            }
        }

        auto attr_constr_extend = make_rc<Vec<ProdConstr_T>>();

        // NOTE: Implicit !lhs clauses:
        //   If an attr is in the domain of a given rule's lhs symbol, but is neither
        //   guaranteed by an LhsGeq or annotation nor mentioned in an applicable Implies clause,
        //   then it is constrained to be false.
        //   This avoids cumbersome annotations such as "this is not a type expression",
        //   when we really mean "this is a value expression", and vice versa.
        for (auto p : *ctx.parser_attr_domains_->operator[](sym)) {
            if (p.first->is_Prec()) {
                continue;
            }
            AT(p.second->is_Bool());
            bool has_implies = false;
            bool has_uncond = false;
            for (auto constr : *attr_constr) {
                if (constr->is_Implies() &&
                    val_hash(constr->as_Implies()->kl_) == val_hash(p.first)) {
                    has_implies = true;
                }
                if (constr->is_LhsGeq() &&
                    val_hash(constr->as_LhsGeq()->k_) == val_hash(p.first)) {
                    has_uncond = true;
                }
            }
            if (has_implies && has_uncond) {
                ctx.error(rule,
                    fmt_str("Attribute key {} has both Implies and LhsGeq clauses", p.first));
            }
            if (!has_implies && !has_uncond) {
                attr_constr_extend->push_back(
                    ProdConstr::LhsLeq::make(
                        p.first, AttrVal::Bool::make(AttrType::Bool::make(), false)));
            }
        }

        auto attr_constr_new = make_rc<Vec<ProdConstr_T>>();
        for (auto constr : *attr_constr) {
            if (constr->is_RhsGeq() || constr->is_Implies()) {
                attr_constr_new->push_back(constr);
            } else if (constr->is_LhsGeq()) {
                // pass
            } else {
                AX();
            }
        }

        for (auto constr : *attr_constr_extend) {
            attr_constr_new->push_back(constr);
        }

        attr_constr = attr_constr_new;

        if (sym_has_prec->operator[](sym)) {
            AT(ident_prec_level->contains_key(ident));
            auto level = ident_prec_level->operator[](ident);
            auto assoc = ident_prec_assoc->operator[](ident);
            auto attr_key_left = AttrKey::Prec::make(None<ProdConstrRhsLoc>(), PrecDir::Left);
            auto attr_key_right = AttrKey::Prec::make(None<ProdConstrRhsLoc>(), PrecDir::Right);
            auto prec_ty = AttrType::Range::make(ctx.parser_prec_n_);
            auto lhs_level = AttrVal::Int_::make(prec_ty, level);
            auto lhs_level_inc = AttrVal::Int_::make(prec_ty, level+1);

            if (assoc.is_none() || (
                assoc.is_some() && (assoc.as_some()->is_Left() || assoc.as_some()->is_Right()))) {
                attr_constr->push(ProdConstr::LhsLeq::make(attr_key_left, lhs_level));
                attr_constr->push(ProdConstr::LhsLeq::make(attr_key_right, lhs_level));
            } else if (assoc.is_some() && assoc.as_some()->is_Prefix()) {
                attr_constr->push(ProdConstr::LhsLeq::make(attr_key_right, lhs_level));
            } else if (assoc.is_some() && assoc.as_some()->is_Postfix()) {
                attr_constr->push(ProdConstr::LhsLeq::make(attr_key_left, lhs_level));
            } else {
                AX();
            }

            if (assoc.is_none()) {
                attr_constr->push(
                    ProdConstr::RhsGeq::make(
                        ProdConstrRhsLoc::All, attr_key_left, lhs_level_inc));
                attr_constr->push(
                    ProdConstr::RhsGeq::make(
                        ProdConstrRhsLoc::All, attr_key_right, lhs_level_inc));

            } else {
                if (assoc.as_some()->is_Left()) {
                    attr_constr->push(ProdConstr::RhsGeq::make(
                        ProdConstrRhsLoc::Begin, attr_key_right, lhs_level));
                    attr_constr->push(ProdConstr::RhsGeq::make(
                        ProdConstrRhsLoc::Mid, attr_key_left, lhs_level_inc));
                    attr_constr->push(ProdConstr::RhsGeq::make(
                        ProdConstrRhsLoc::Mid, attr_key_right, lhs_level_inc));
                    attr_constr->push(ProdConstr::RhsGeq::make(
                        ProdConstrRhsLoc::End, attr_key_left, lhs_level_inc));

                    attr_constr->push(ProdConstr::Implies::make(
                        attr_key_left, ProdConstrRhsLoc::Begin, attr_key_left, prec_ty));
                    attr_constr->push(ProdConstr::Implies::make(
                        attr_key_right, ProdConstrRhsLoc::End, attr_key_right, prec_ty));

                } else if (assoc.as_some()->is_Right()) {
                    attr_constr->push(ProdConstr::RhsGeq::make(
                        ProdConstrRhsLoc::Begin, attr_key_right, lhs_level_inc));
                    attr_constr->push(ProdConstr::RhsGeq::make(
                        ProdConstrRhsLoc::Mid, attr_key_left, lhs_level_inc));
                    attr_constr->push(ProdConstr::RhsGeq::make(
                        ProdConstrRhsLoc::Mid, attr_key_right, lhs_level_inc));
                    attr_constr->push(ProdConstr::RhsGeq::make(
                        ProdConstrRhsLoc::End, attr_key_left, lhs_level));

                    attr_constr->push(ProdConstr::Implies::make(
                        attr_key_left, ProdConstrRhsLoc::Begin, attr_key_left, prec_ty));
                    attr_constr->push(ProdConstr::Implies::make(
                        attr_key_right, ProdConstrRhsLoc::End, attr_key_right, prec_ty));

                } else if (assoc.as_some()->is_Prefix()) {
                    attr_constr->push(ProdConstr::RhsGeq::make(
                        ProdConstrRhsLoc::Mid, attr_key_left, lhs_level_inc));
                    attr_constr->push(ProdConstr::RhsGeq::make(
                        ProdConstrRhsLoc::Mid, attr_key_right, lhs_level_inc));
                    attr_constr->push(ProdConstr::RhsGeq::make(
                        ProdConstrRhsLoc::End, attr_key_left, lhs_level_inc));

                    attr_constr->push(ProdConstr::Implies::make(
                        attr_key_right, ProdConstrRhsLoc::All, attr_key_right, prec_ty));

                } else if (assoc.as_some()->is_Postfix()) {
                    attr_constr->push(ProdConstr::RhsGeq::make(
                        ProdConstrRhsLoc::Begin, attr_key_right, lhs_level_inc));
                    attr_constr->push(ProdConstr::RhsGeq::make(
                        ProdConstrRhsLoc::Mid, attr_key_left, lhs_level_inc));
                    attr_constr->push(ProdConstr::RhsGeq::make(
                        ProdConstrRhsLoc::Mid, attr_key_right, lhs_level_inc));

                    attr_constr->push(ProdConstr::Implies::make(
                        attr_key_left, ProdConstrRhsLoc::All, attr_key_left, prec_ty));

                } else {
                    AX();
                }
            }
        }

        ctx.parser_attr_constr_by_rule_->insert_strict(
            parse_expr_id_to_ident(rule->name_), attr_constr);
    }
}


inline AttrKey_T attr_key_lift_loc(AttrKey_T k, Option_T<ProdConstrRhsLoc> loc) {
    AT(k->loc_.is_none());
    if (k->is_Id()) {
        return AttrKey::Id::make(loc, k->as_Id()->name_);
    } else if (k->is_Prec()) {
        return AttrKey::Prec::make(loc, k->as_Prec()->dir_);
    } else {
        AX();
    }
}


void parser_attr_propagate_flattened_prod_rec(
    Vec_T<ProdConstr_T> rule_constrs,
    Prod_T prod,
    bool is_rule_lhs,
    Set_T<Sym_T> vis,
    LangCompileContext& ctx);


void parser_attr_propagate_flattened_sym_rec(
    Vec_T<ProdConstr_T> rule_constrs,
    Sym_T sym,
    Set_T<Sym_T> vis,
    LangCompileContext& ctx) {

    if (!Grammar::sym_is_nonterm_gen(sym)) {
        return;
    }

    if (vis->contains(sym)) {
        return;
    }
    vis->insert(sym);

    for (auto prod : *ctx.Gr_cps_->prods_by_nonterm_->operator[](sym)) {
        parser_attr_propagate_flattened_prod_rec(rule_constrs, prod, false, vis, ctx);
    }
}


void parser_attr_propagate_flattened_prod_rec_inner_implies(
    VecUniq_T<ProdConstrFlat_T>& dst,
    Prod_T prod,
    ProdConstr::Implies_T cc,
    AttrKey_T kl,
    AttrKey_T kr,
    AttrType_T ty,
    Int i_lo,
    Int i_hi,
    ProdConstrRhsLoc loc_base_lhs,
    ProdConstrRhsLoc loc_base_rhs,
    bool is_rule_lhs,
    Vec_T<ProdConstr_T> rule_constrs,
    Set_T<Sym_T> vis,
    LangCompileContext& ctx) {

    for (Int i = i_lo; i < i_hi; i++) {
        if (i < 0 || i >= prod->rhs_->length()) {
            continue;
        }
        auto ri = prod->rhs_->operator[](i);

        auto loc_lhs = Some<ProdConstrRhsLoc>(loc_base_lhs);
        if (is_rule_lhs) {
            loc_lhs = None<ProdConstrRhsLoc>();
        }
        if (is_rule_lhs != !Grammar::sym_is_nonterm_gen(prod->lhs_)) {
            LG_ERR("prod: {}", prod);
            AX();
        }
        auto loc_rhs = Some<ProdConstrRhsLoc>(loc_base_rhs);
        if (!Grammar::sym_is_nonterm_gen(ri)) {
            loc_rhs = None<ProdConstrRhsLoc>();
        }

        if (is_rule_lhs && loc_base_lhs != cc->loc_) {
            continue;
        }

        if (!Grammar::sym_is_nonterm_gen(ri) &&
            (loc_base_rhs == ProdConstrRhsLoc::Mid ||
             loc_base_rhs == ProdConstrRhsLoc::NBegin ||
             loc_base_rhs == ProdConstrRhsLoc::NEnd)) {
            continue;
        }

        auto kl_lift = attr_key_lift_loc(kl, loc_lhs);
        auto kr_lift = attr_key_lift_loc(kr, loc_rhs);

        dst->insert(ProdConstrFlat::Implies::make(kl_lift, i, kr_lift, ty));

        parser_attr_propagate_flattened_sym_rec(rule_constrs, ri, vis, ctx);
    }
}


void parser_attr_propagate_flattened_prod_rec_inner_rhs(
    VecUniq_T<ProdConstrFlat_T>& dst,
    Prod_T prod,
    AttrKey_T kr,
    AttrVal_T v,
    Int i_lo,
    Int i_hi,
    ProdConstrRhsLoc loc_base_rhs,
    bool is_rule_lhs,
    Vec_T<ProdConstr_T> rule_constrs,
    Set_T<Sym_T> vis,
    LangCompileContext& ctx) {

    for (Int i = i_lo; i < i_hi; i++) {
        if (i < 0 || i >= prod->rhs_->length()) {
            continue;
        }
        auto ri = prod->rhs_->operator[](i);

        auto loc_rhs = Some<ProdConstrRhsLoc>(loc_base_rhs);
        if (!Grammar::sym_is_nonterm_gen(ri)) {
            loc_rhs = None<ProdConstrRhsLoc>();
        }

        if (!Grammar::sym_is_nonterm_gen(ri) &&
            (loc_base_rhs == ProdConstrRhsLoc::Mid ||
             loc_base_rhs == ProdConstrRhsLoc::NBegin ||
             loc_base_rhs == ProdConstrRhsLoc::NEnd)) {
            continue;
        }

        auto kr_lift = attr_key_lift_loc(kr, loc_rhs);

        dst->insert(ProdConstrFlat::RhsGeq::make(i, kr_lift, v));

        parser_attr_propagate_flattened_sym_rec(rule_constrs, ri, vis, ctx);
    }
}


void parser_attr_propagate_flattened_prod_rec(
    Vec_T<ProdConstr_T> rule_constrs,
    Prod_T prod,
    bool is_rule_lhs,
    Set_T<Sym_T> vis,
    LangCompileContext& ctx) {

    Int n = prod->rhs_->length();

    auto rhs_leaves = ctx.Gr_cps_rhs_flatten_leaves_->operator[](prod);
    if (!ctx.Gr_cps_prod_constrs_->contains_key(prod)) {
        ctx.Gr_cps_prod_constrs_->insert(prod, make_rc<VecUniq<ProdConstrFlat_T>>());
    }
    auto dst = ctx.Gr_cps_prod_constrs_->operator[](prod);

    for (auto constr : *rule_constrs) {
        if (constr->is_LhsLeq()) {
            auto cc = constr->as_LhsLeq();
            if (is_rule_lhs) {
                dst->insert(ProdConstrFlat::LhsLeq::make(cc->k_, cc->v_));
            }

        } else if (constr->is_LhsGeq()) {
            AX();

        } else if (constr->is_Implies()) {
            auto cc = constr->as_Implies();
            auto kl = cc->kl_;
            auto kr = cc->kr_;
            if (!is_rule_lhs) {
                kl = kr;
            }
            auto ty = cc->ty_;

            // All
            parser_attr_propagate_flattened_prod_rec_inner_implies(
                dst, prod, cc, kl, kr, ty, 0, n,
                ProdConstrRhsLoc::All, ProdConstrRhsLoc::All,
                is_rule_lhs, rule_constrs, vis, ctx);

            // Begin
            parser_attr_propagate_flattened_prod_rec_inner_implies(
                dst, prod, cc, kl, kr, ty, 0, 1,
                ProdConstrRhsLoc::Begin, ProdConstrRhsLoc::Begin,
                is_rule_lhs, rule_constrs, vis, ctx);

            // End
            parser_attr_propagate_flattened_prod_rec_inner_implies(
                dst, prod, cc, kl, kr, ty, n-1, n,
                ProdConstrRhsLoc::End, ProdConstrRhsLoc::End,
                is_rule_lhs, rule_constrs, vis, ctx);

            // Mid
            parser_attr_propagate_flattened_prod_rec_inner_implies(
                dst, prod, cc, kl, kr, ty, 1, n-1,
                ProdConstrRhsLoc::Mid, ProdConstrRhsLoc::All,
                is_rule_lhs, rule_constrs, vis, ctx);

            if (n <= 1) {
                parser_attr_propagate_flattened_prod_rec_inner_implies(
                    dst, prod, cc, kl, kr, ty, 0, 1,
                    ProdConstrRhsLoc::Mid, ProdConstrRhsLoc::Mid,
                    is_rule_lhs, rule_constrs, vis, ctx);
            } else {
                parser_attr_propagate_flattened_prod_rec_inner_implies(
                    dst, prod, cc, kl, kr, ty, 0, 1,
                    ProdConstrRhsLoc::Mid, ProdConstrRhsLoc::NBegin,
                    is_rule_lhs, rule_constrs, vis, ctx);

                parser_attr_propagate_flattened_prod_rec_inner_implies(
                    dst, prod, cc, kl, kr, ty, n-1, n,
                    ProdConstrRhsLoc::Mid, ProdConstrRhsLoc::NEnd,
                    is_rule_lhs, rule_constrs, vis, ctx);
            }

            // NBegin
            parser_attr_propagate_flattened_prod_rec_inner_implies(
                dst, prod, cc, kl, kr, ty, 1, n,
                ProdConstrRhsLoc::NBegin, ProdConstrRhsLoc::All,
                is_rule_lhs, rule_constrs, vis, ctx);

            parser_attr_propagate_flattened_prod_rec_inner_implies(
                dst, prod, cc, kl, kr, ty, 0, 1,
                ProdConstrRhsLoc::NBegin, ProdConstrRhsLoc::NBegin,
                is_rule_lhs, rule_constrs, vis, ctx);

            // NEnd
            parser_attr_propagate_flattened_prod_rec_inner_implies(
                dst, prod, cc, kl, kr, ty, 0, n-1,
                ProdConstrRhsLoc::NEnd, ProdConstrRhsLoc::All,
                is_rule_lhs, rule_constrs, vis, ctx);

            parser_attr_propagate_flattened_prod_rec_inner_implies(
                dst, prod, cc, kl, kr, ty, n-1, n,
                ProdConstrRhsLoc::NEnd, ProdConstrRhsLoc::NEnd,
                is_rule_lhs, rule_constrs, vis, ctx);

        } else if (constr->is_RhsGeq()) {
            auto cc = constr->as_RhsGeq();
            auto kr = cc->k_;
            auto v = cc->v_;

            if (cc->loc_ == ProdConstrRhsLoc::Begin) {
                parser_attr_propagate_flattened_prod_rec_inner_rhs(
                    dst, prod, kr, v, 0, 1, ProdConstrRhsLoc::Begin,
                    is_rule_lhs, rule_constrs, vis, ctx);

            } else if (cc->loc_ == ProdConstrRhsLoc::End) {
                parser_attr_propagate_flattened_prod_rec_inner_rhs(
                    dst, prod, kr, v, n-1, n, ProdConstrRhsLoc::End,
                    is_rule_lhs, rule_constrs, vis, ctx);

            } else if (cc->loc_ == ProdConstrRhsLoc::Mid) {
                parser_attr_propagate_flattened_prod_rec_inner_rhs(
                    dst, prod, kr, v, 1, n-1, ProdConstrRhsLoc::All,
                    is_rule_lhs, rule_constrs, vis, ctx);

                if (n <= 1) {
                    parser_attr_propagate_flattened_prod_rec_inner_rhs(
                        dst, prod, kr, v, 0, 1, ProdConstrRhsLoc::Mid,
                        is_rule_lhs, rule_constrs, vis, ctx);
                } else {
                    parser_attr_propagate_flattened_prod_rec_inner_rhs(
                        dst, prod, kr, v, 0, 1, ProdConstrRhsLoc::NBegin,
                        is_rule_lhs, rule_constrs, vis, ctx);

                    parser_attr_propagate_flattened_prod_rec_inner_rhs(
                        dst, prod, kr, v, n-1, n, ProdConstrRhsLoc::NEnd,
                        is_rule_lhs, rule_constrs, vis, ctx);
                }

            } else if (cc->loc_ == ProdConstrRhsLoc::All) {
                parser_attr_propagate_flattened_prod_rec_inner_rhs(
                    dst, prod, kr, v, 0, n, ProdConstrRhsLoc::All,
                    is_rule_lhs, rule_constrs, vis, ctx);

            } else {
                AX();
            }

        } else {
            AX();
        }
    }
}


Int prod_id_extract_rule_ind(ProdId_T prod_id) {
    if (prod_id->is_Start()) {
        AX();
    } else if (prod_id->is_Explicit()) {
        return prod_id->as_Explicit()->rule_ind_;
    } else if (prod_id->is_GenCPS()) {
        return prod_id_extract_rule_ind(prod_id->as_GenCPS()->orig_);
    } else {
        AX();
    }
}


void parser_attr_propagate_flattened(LangCompileContext& ctx) {
    auto vis = make_rc<Set<Sym_T>>();

    for (auto [rule_id, rule_constrs] : *ctx.parser_attr_constr_by_rule_) {
        auto sym = ctx.Np_->operator[](rule_id);
        vis->insert(sym);
    }

    for (auto [rule_id, rule_constrs] : *ctx.parser_attr_constr_by_rule_) {
        auto rule_ind = ctx.parser_rule_inds_->operator[](rule_id);

        auto sym = ctx.Np_->operator[](rule_id);

        for (auto prod : *ctx.Gr_cps_->prods_by_nonterm_->operator[](sym)) {
            if (prod_id_extract_rule_ind(prod->prod_id_) != rule_ind) {
                continue;
            }

            auto prod_lhs_leaf = ctx.Gr_cps_lhs_flatten_leaves_->operator[](prod);
            if (prod_lhs_leaf.is_none()) {
                continue;
            }
            AT(prod_lhs_leaf.as_some()->is_Lhs());
            parser_attr_propagate_flattened_prod_rec(rule_constrs, prod, true, vis, ctx);
        }
    }

    for (auto prod : *ctx.Gr_cps_->prods_) {
        if (!ctx.Gr_cps_prod_constrs_->contains_key(prod)) {
            ctx.Gr_cps_prod_constrs_->insert(prod, make_rc<VecUniq<ProdConstrFlat_T>>());
        }
    }

    // Inline attr reqs
    auto prec_exempt = make_rc<Vec<pair<Prod_T, Int>>>();
    for (auto prod : *ctx.Gr_cps_->prods_) {
        auto dst = ctx.Gr_cps_prod_constrs_->operator[](prod);

        if (!ctx.Gr_cps_rhs_flatten_leaves_->contains_key(prod)) {
            AT(prod->lhs_->is_Start());
            continue;
        }
        auto leaves = ctx.Gr_cps_rhs_flatten_leaves_->operator[](prod);

        for (Int i = 0; i < prod->rhs_->length(); i++) {
            auto ri = prod->rhs_->operator[](i);
            auto li = leaves->operator[](i);

            if (li.is_some() && li.as_some()->is_Id()) {
                auto props = ctx.parse_expr_props_->operator[](li.as_some()->as_Id()->e_->id_);
                if (props->attr_req_.is_some()) {
                    for (auto ar : *props->attr_req_.as_some()) {
                        if (ar->is_Base()) {
                            auto k_names = make_rc<Vec<common::IdentBase_T>>();
                            k_names->push_back(
                                IdentBase::User::make(ar->as_Base()->k_.to_std_string()));
                            auto k_id = common::Ident::make(k_names);
                            auto k = AttrKey::Id::make(None<ProdConstrRhsLoc>(), k_id);
                            dst->insert(ProdConstrFlat::RhsGeq::make(
                                i, k, AttrVal::Bool::make(AttrType::Bool::make(), true)));
                        } else if (ar->is_PrecStar()) {
                            prec_exempt->push_back(make_pair(prod, i));
                        } else {
                            AX();
                        }
                    }
                }
            }
        }
    }

    for (auto [prod, i] : *prec_exempt) {
        auto curr_new = make_rc<VecUniq<ProdConstrFlat_T>>();
        for (auto constr : *ctx.Gr_cps_prod_constrs_->operator[](prod)) {
            bool retain = true;
            if (constr->is_RhsGeq()) {
                auto cc = constr->as_RhsGeq();
                if (cc->i_ == i && cc->k_->is_Prec()) {
                    retain = false;
                }
            } else if (constr->is_LhsLeq()) {
                // pass
            } else if (constr->is_Implies()) {
                auto cc = constr->as_Implies();
                if (cc->i_ == i && cc->kr_->is_Prec()) {
                    retain = false;
                }
            } else {
                AX();
            }
            if (retain) {
                curr_new->insert(constr);
            }
        }
        ctx.Gr_cps_prod_constrs_->insert(prod, curr_new);
    }
}


void parser_prod_constr_cps_refine_domains(LangCompileContext& ctx) {
    ctx.parser_attr_domains_ = make_rc<Map<Sym_T, Map_T<AttrKey_T, AttrType_T>>>();
    ctx.parser_attr_domains_->insert(Sym::Start::make(), make_rc<Map<AttrKey_T, AttrType_T>>());

    for (auto prod : *ctx.Gr_cps_->prods_) {
        if (!ctx.parser_attr_domains_->contains_key(prod->lhs_)) {
            ctx.parser_attr_domains_->insert(prod->lhs_, make_rc<Map<AttrKey_T, AttrType_T>>());
        }
        for (auto sym : *prod->rhs_) {
            if (!ctx.parser_attr_domains_->contains_key(sym)) {
                ctx.parser_attr_domains_->insert(sym, make_rc<Map<AttrKey_T, AttrType_T>>());
            }
        }
    }

    while (true) {
        bool pruned = false;

        auto has_lower = make_rc<Map<Sym_T, Map_T<AttrKey_T, AttrType_T>>>();
        auto has_upper = make_rc<Map<Sym_T, Map_T<AttrKey_T, AttrType_T>>>();

        for (auto prod : *ctx.Gr_cps_->prods_) {
            has_lower->insert(prod->lhs_, make_rc<Map<AttrKey_T, AttrType_T>>());
            has_upper->insert(prod->lhs_, make_rc<Map<AttrKey_T, AttrType_T>>());

            for (auto sym : *prod->rhs_) {
                has_lower->insert(sym, make_rc<Map<AttrKey_T, AttrType_T>>());
                has_upper->insert(sym, make_rc<Map<AttrKey_T, AttrType_T>>());
            }
        }

        while (true) {
            bool updated = false;

            for (auto [prod, constrs] : *ctx.Gr_cps_prod_constrs_) {
                for (auto constr : *constrs) {
                    if (constr->is_LhsLeq()) {
                        auto cc = constr->as_LhsLeq();
                        if (!has_upper->operator[](prod->lhs_)->contains_key(cc->k_)) {
                            updated = true;
                            has_upper->operator[](prod->lhs_)->insert(cc->k_, cc->v_->ty_);
                        }

                    } else if (constr->is_Implies()) {
                        auto cc = constr->as_Implies();
                        auto ri = prod->rhs_->operator[](cc->i_);
                        if (has_lower->operator[](prod->lhs_)->contains_key(cc->kl_)) {
                            if (!has_lower->operator[](ri)->contains_key(cc->kr_)) {
                                updated = true;
                                has_lower->operator[](ri)->insert(cc->kr_, cc->ty_);
                            }
                        }
                        if (has_upper->operator[](ri)->contains_key(cc->kr_)) {
                            if (!has_upper->operator[](prod->lhs_)->contains_key(cc->kl_)) {
                                updated = true;
                                has_upper->operator[](prod->lhs_)->insert(cc->kl_, cc->ty_);
                            }
                        }

                    } else if (constr->is_RhsGeq()) {
                        auto cc = constr->as_RhsGeq();
                        auto ri = prod->rhs_->operator[](cc->i_);
                        if (!has_lower->operator[](ri)->contains_key(cc->k_)) {
                            updated = true;
                            has_lower->operator[](ri)->insert(cc->k_, cc->v_->ty_);
                        }

                    } else {
                        AX();
                    }
                }
            }

            if (!updated) {
                break;
            }
        }

        for (auto [sym, attrs_lower] : *has_lower) {
            for (auto [attr_k, attr_ty] : *attrs_lower) {
                if (has_upper->operator[](sym)->contains_key(attr_k)) {
                    ctx.parser_attr_domains_->operator[](sym)->insert(attr_k, attr_ty);
                }
            }
        }

        auto Gr_cps_prod_constrs_new = make_rc<Map<Prod_T, VecUniq_T<ProdConstrFlat_T>>>();

        for (auto prod : *ctx.Gr_cps_->prods_) {
            Gr_cps_prod_constrs_new->insert(prod, make_rc<VecUniq<ProdConstrFlat_T>>());
        }

        for (auto [prod, constrs] : *ctx.Gr_cps_prod_constrs_) {
            auto curr_constrs_new = make_rc<VecUniq<ProdConstrFlat_T>>();

            for (auto constr : *constrs) {
                bool ok = true;

                if (constr->is_LhsLeq()) {
                    auto cc = constr->as_LhsLeq();
                    if (!ctx.parser_attr_domains_->operator[](prod->lhs_)->contains_key(cc->k_)) {
                        ok = false;
                    }
                } else if (constr->is_Implies()) {
                    auto cc = constr->as_Implies();
                    if (!ctx.parser_attr_domains_->operator[](prod->lhs_)->contains_key(cc->kl_)) {
                        ok = false;
                    }
                    if (!ctx.parser_attr_domains_->operator[](prod->rhs_->operator[](cc->i_))
                        ->contains_key(cc->kr_)) {
                        ok = false;
                    }
                } else if (constr->is_RhsGeq()) {
                    auto cc = constr->as_RhsGeq();
                    if (!ctx.parser_attr_domains_->operator[](prod->rhs_->operator[](cc->i_))
                        ->contains_key(cc->k_)) {
                        ok = false;
                    }
                } else {
                    AX();
                }

                if (ok) {
                    curr_constrs_new->insert(constr);
                } else {
                    pruned = true;
                }
            }

            Gr_cps_prod_constrs_new->insert(prod, curr_constrs_new);
        }

        ctx.Gr_cps_prod_constrs_ = Gr_cps_prod_constrs_new;

        if (!pruned) {
            break;
        }
    }
}
