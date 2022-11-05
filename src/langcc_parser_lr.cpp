
#include "langcc_common.hpp"

namespace langcc {

AttrSet_T prod_lhs_attr_init(Prod_T prod, LangCompileContext& ctx) {
    auto m = make_rc<Map<AttrKey_T, AttrVal_T>>();
    auto lhs = prod->lhs_;

    if (!ctx.parser_attr_domains_->contains_key(lhs)) {
        LG_ERR("{}", lhs);
        AX();
    }

    for (auto [attr_k, attr_ty] : *ctx.parser_attr_domains_->operator[](lhs)) {
        m->insert_strict(attr_k, attr_val_max(attr_ty));
    }

    for (auto constr : *ctx.Gr_cps_prod_constrs_->operator[](prod)) {
        if (constr->is_LhsLeq()) {
            auto cc = constr->as_LhsLeq();
            if (!m->contains_key(cc->k_)) {
                LG_ERR("Not found: {} {} {}", prod, constr, cc->k_);
                AX();
            }
            auto v_lhs_prev = m->operator[](cc->k_);
            auto v_lhs_new = attr_val_minimum(v_lhs_prev, cc->v_);
            m->insert(cc->k_, v_lhs_new);
        }
    }

    return AttrSet::make(m);
}


Option_T<AttrSet_T> prod_lhs_apply_constrs_incremental(
    DottedProd_T dq, AttrSet_T dq_attr, AttrSet_T item_attr, LangCompileContext& ctx) {

    auto ret = make_rc<Map<AttrKey_T, AttrVal_T>>();
    for (auto [k, v] : *dq_attr->m_) {
        ret->insert(k, v);
    }

    for (auto constr : *ctx.Gr_cps_prod_constrs_->operator[](dq->prod_)) {
        if (constr->is_LhsLeq()) {
            // pass

        } else if (constr->is_Implies()) {
            auto cc = constr->as_Implies();
            if (cc->i_ != dq->dot_) {
                continue;
            }
            if (!ret->contains_key(cc->kl_)) {
                LG_ERR("Not found: {} {}", cc->kl_, dq);
                AX();
            }
            auto v_lhs_prev = ret->operator[](cc->kl_);
            auto v_rhs = item_attr->m_->operator[](cc->kr_);
            auto v_lhs_new = attr_val_minimum(v_lhs_prev, v_rhs);
            ret->insert(cc->kl_, v_lhs_new);

        } else if (constr->is_RhsGeq()) {
            auto cc = constr->as_RhsGeq();
            if (cc->i_ != dq->dot_) {
                continue;
            }
            auto v_rhs = item_attr->m_->operator[](cc->k_);
            if (attr_val_less_than(v_rhs, cc->v_)) {
                return None<AttrSet_T>();
            }

        } else {
            AX();
        }
    }

    return Some<AttrSet_T>(AttrSet::make(ret));
}


template<typename Repr>
void string_set_concat_inner_acc(
    Map_T<SymStr_T, Repr>& dst, Int k, StringSet_T<Repr> x, StringSet_T<Repr> y) {

    for (auto [xi, rxi] : *x->items_) {
        for (auto [yi, ryi] : *y->items_) {
            auto zi_full = sym_str_concat(xi, yi);
            auto zi = sym_str_trunc(zi_full, k);
            auto rzi = string_set_repr_concat(rxi, ryi);
            dst->insert(zi, rzi);
        }
    }
}


template<typename Repr>
StringSet_T<Repr> string_set_concat(StringSet_T<Repr> x, StringSet_T<Repr> y) {
    auto ret_k = x->k_;
    if (!x->strict_eq_ && !y->strict_eq_) {
        AT(x->k_ == y->k_);
        ret_k = x->k_;
    } else if (x->strict_eq_ && !y->strict_eq_) {
        ret_k = x->k_;
    } else if (y->strict_eq_ && !x->strict_eq_) {
        ret_k = y->k_;
    } else {
        AX();
    }
    bool ret_strict_eq = x->strict_eq_ || y->strict_eq_;
    auto ret = make_rc<Map<SymStr_T, Repr>>();
    string_set_concat_inner_acc(ret, ret_k, x, y);
    return StringSet::make(ret, ret_k, ret_strict_eq);
}


void pr(ostream& os, FmtFlags flags, GrammarSymConstrGen_T G_gen) {
    fmt(os, "GrammarSymConstrGen {{\n");
    for (auto p : *G_gen) {
        auto sym = p.first;
        for (auto q : *p.second) {
            auto attr = q.first;
            fmt(os, "    {}", sym);
            auto attr_str = fmt_str("{}", attr);
            if (attr_str.length() > 0) {
                fmt(os, "[{}]", attr_str);
            }
            auto sym_gen = q.second;
            fmt(os, ": {},\n", sym_gen);
        }
    }
    fmt(os, "}}");
}


bool prod_constr_gen_extend_inplace(
    GrammarProdConstrGen_T& prod_gen,
    DottedProd_T dqt,
    AttrSet_T dqt_attr_new,
    StringSet_T<SymStr_T> dqt_str_gen_incr,
    LangCompileContext& ctx) {

    bool fresh = false;
    if (!prod_gen->contains_key(dqt)) {
        prod_gen->insert_strict(dqt, make_rc<Map<AttrSet_T, StringSet_T<SymStr_T>>>());
    }
    if (!prod_gen->operator[](dqt)->contains_key(dqt_attr_new)) {
        prod_gen->operator[](dqt)->insert_strict(dqt_attr_new, dqt_str_gen_incr);
        fresh = true;
    }

    auto dqt_str_gen_prev = prod_gen->operator[](dqt)->operator[](dqt_attr_new);
    auto dqt_str_gen_new = string_set_union(dqt_str_gen_prev, dqt_str_gen_incr);
    if (dqt_str_gen_new->items_->length() != dqt_str_gen_prev->items_->length()) {
        fresh = true;
    }
    prod_gen->operator[](dqt)->insert(dqt_attr_new, dqt_str_gen_new);

    return fresh;
}


GrammarSymConstrGen_T parser_lr_gen_inhabitants(Grammar_T G, Int k, LangCompileContext& ctx) {
    auto sym_gen = make_rc<Map<Sym_T, Map_T<AttrSet_T, StringSet_T<SymStr_T>>>>();
    auto prod_gen = make_rc<Map<DottedProd_T, Map_T<AttrSet_T, StringSet_T<SymStr_T>>>>();

    for (auto sym : *G->nonterm_) {
        sym_gen->insert(sym, make_rc<Map<AttrSet_T, StringSet_T<SymStr_T>>>());
    }

    for (auto sym : *G->term_) {
        auto sym_v = make_rc<Vec<LRSym_T>>();
        sym_v->push_back(LRSym::Base::make(sym));
        auto sym_str = SymStr::make(sym_v);
        auto sym_str_set = string_set_single(sym_str_trunc(sym_str, k), sym_str, k, false);
        sym_gen->insert_strict(sym, make_rc<Map<AttrSet_T, StringSet_T<SymStr_T>>>());
        sym_gen->operator[](sym)->insert(attr_set_empty(), sym_str_set);
    }

    auto Q = make_rc<Vec<pair<DottedProd_T, AttrSet_T>>>();

    for (auto prod : *G->prods_) {
        for (Int dot = 0; dot <= prod->rhs_->length(); dot++) {
            auto dp = DottedProd::make(prod, dot);
            prod_gen->insert_strict(dp, make_rc<Map<AttrSet_T, StringSet_T<SymStr_T>>>());
            if (dot == 0) {
                auto attr_init = prod_lhs_attr_init(prod, ctx);
                auto str_gen_init = string_set_single_empty(k, false);
                prod_gen->operator[](dp)->insert(attr_init, str_gen_init);
                Q->push_back(make_pair(dp, attr_init));
            }
        }
    }

    while (!Q->empty()) {
        auto [dp, dp_attr] = Q->pop_front_val();
        auto dp_str_gen = prod_gen->operator[](dp)->operator[](dp_attr);

        if (dotted_prod_is_end(dp)) {
            auto sym = dp->prod_->lhs_;

            if (!sym_gen->contains_key(sym)) {
                sym_gen->insert(sym, make_rc<Map<AttrSet_T, StringSet_T<SymStr_T>>>());
            }
            if (!sym_gen->operator[](sym)->contains_key(dp_attr)) {
                sym_gen->operator[](sym)->insert(dp_attr, dp_str_gen);
            } else {
                auto str_gen_new = string_set_union(
                    sym_gen->operator[](sym)->operator[](dp_attr), dp_str_gen);
                sym_gen->operator[](sym)->insert(dp_attr, str_gen_new);
            }

            for (auto dq : *G->prods_by_nonterm_rhs_->operator[](sym)) {
                auto dqt = dotted_prod_with_step(dq);

                for (auto [dq_attr, dq_str_gen] : *prod_gen->operator[](dq)) {
                    auto dqt_attr_new_m = prod_lhs_apply_constrs_incremental(
                        dq, dq_attr, dp_attr, ctx);
                    if (dqt_attr_new_m.is_none()) {
                        continue;
                    }
                    auto dqt_attr_new = dqt_attr_new_m.as_some();
                    auto dqt_str_gen_incr = string_set_concat(dq_str_gen, dp_str_gen);
                    bool fresh = prod_constr_gen_extend_inplace(
                        prod_gen, dqt, dqt_attr_new, dqt_str_gen_incr, ctx);
                    if (fresh) {
                        Q->push_back(make_pair(dqt, dqt_attr_new));
                    }
                }
            }

        } else {
            auto dpt = dotted_prod_with_step(dp);

            if (!sym_gen->contains_key(dotted_prod_cursor(dp))) {
                LG_ERR("Prod: {}", dp);
                LG_ERR("Cursor: {}", dotted_prod_cursor(dp));
                LG_ERR("Not found: {}\n{}\n\n", dotted_prod_cursor(dp), sym_gen);
                AX();
            }

            for (auto [cur_attr, cur_str_gen] : *sym_gen->operator[](dotted_prod_cursor(dp))) {
                auto dpt_attr_new_m = prod_lhs_apply_constrs_incremental(
                    dp, dp_attr, cur_attr, ctx);
                if (dpt_attr_new_m.is_none()) {
                    continue;
                }
                auto dpt_attr_new = dpt_attr_new_m.as_some();
                auto dpt_str_gen_incr = string_set_concat(dp_str_gen, cur_str_gen);
                bool fresh = prod_constr_gen_extend_inplace(
                    prod_gen, dpt, dpt_attr_new, dpt_str_gen_incr, ctx);
                if (fresh) {
                    Q->push_back(make_pair(dpt, dpt_attr_new));
                }
            }
        }
    }

    return sym_gen;
}


SymStr_T sym_str_sentinel(Int k) {
    auto ret = make_rc<Vec<LRSym_T>>();
    for (Int i = 0; i < k; i++) {
        ret->push_back(LRSym::EndMarker::make());
    }
    return SymStr::make(ret);
}


StringSet_T<Unit> lookahead_sentinel(Int k) {
    SymStr_T s = sym_str_sentinel(k);
    return string_set_single<Unit>(s, Unit{}, k, true);
}


Option_T<LRVertex_T> lr_vertex_with_bounds_pruned(
    LRVertex_T v,
    GrammarSymConstrGen_T G_gen,
    GrammarProdConstrs_T G_constrs) {

    if (v->is_RecStart()) {
        return Some<LRVertex_T>(v);

    } else if (v->is_RecEnd()) {
        auto ret = LRVertex::RecEnd::make(attr_bound_set_empty(), v->la_, v->as_RecEnd()->sym_);
        return Some<LRVertex_T>(ret);

    } else if (v->is_Prod()) {
        auto dp = v->as_Prod()->prod_;
        if (!G_constrs->contains_key(dp->prod_)) {
            auto ret = LRVertex::Prod::make(
                attr_bound_set_empty(), v->la_, dp, v->as_Prod()->left_rec_);
            return Some<LRVertex_T>(ret);
        }
        auto rhs_models = make_rc<Vec<Set_T<AttrSet_T>>>();
        for (Int i = 0; i < dp->prod_->rhs_->length(); i++) {
            auto rhs_models_i = make_rc<Set<AttrSet_T>>();
            for (auto [attr, _] : *G_gen->operator[](dp->prod_->rhs_->operator[](i))) {
                bool model_ok = true;
                for (auto constr : *G_constrs->operator[](dp->prod_)) {
                    if (constr->is_RhsGeq()) {
                        auto cc = constr->as_RhsGeq();
                        if (cc->i_ == i && attr->m_->contains_key(cc->k_) &&
                            attr_val_less_than(attr->m_->operator[](cc->k_), cc->v_)) {
                            model_ok = false;
                            break;
                        }
                    }
                }
                if (model_ok) {
                    rhs_models_i->insert(attr);
                }
            }
            if (rhs_models_i->length() == 0) {
                return None<LRVertex_T>();
            }
            rhs_models->push_back(rhs_models_i);
        }
        auto ret_bounds = attr_bound_set_empty();
        for (auto [attr_k, attr_bound] : *v->bounds_->m_) {
            bool trivial = true;
            for (auto constr : *G_constrs->operator[](dp->prod_)) {
                if (constr->is_Implies()) {
                    auto cc = constr->as_Implies();
                    if (val_hash(cc->kl_) == val_hash(attr_k) && cc->i_ >= dp->dot_) {
                        for (auto gen_attr : *rhs_models->operator[](cc->i_)) {
                            if (!gen_attr->m_->contains_key(cc->kr_)) {
                                continue;
                            }
                            auto gen_val_rhs = gen_attr->m_->operator[](cc->kr_);
                            if (attr_val_less_than(gen_val_rhs, attr_bound->lo_)) {
                                trivial = false;
                                break;
                            }
                        }
                    }
                } else if (constr->is_LhsLeq()) {
                    auto cc = constr->as_LhsLeq();
                    if (val_hash(cc->k_) == val_hash(attr_k)) {
                        if (attr_val_less_than(cc->v_, attr_bound->lo_)) {
                            return None<LRVertex_T>();
                        }
                    }
                } else if (constr->is_RhsGeq()) {
                    // pass
                } else {
                    AX();
                }
            }
            if (!trivial) {
                ret_bounds->m_->insert(attr_k, attr_bound);
            }
        }
        auto ret = LRVertex::Prod::make(ret_bounds, v->la_, dp, v->as_Prod()->left_rec_);
        return Some<LRVertex_T>(ret);
    } else {
        AX();
    }
}


using LookaheadPartFlat = Set_T<StringSet_T<Unit>>;
using LookaheadPartsFlat = Map_T<LRVertex_T, LookaheadPartFlat>;

struct LookaheadPartNested {
    LookaheadPartFlat univ_;
    Set_T<Set_T<StringSet_T<Unit>>> part_;

    inline LookaheadPartFlat flatten() {
        auto ret = make_rc<Set<StringSet_T<Unit>>>();
        for (auto s : *part_) {
            auto s_flat = string_set_union_multi(s);
            ret->insert(s_flat);
        }
        return ret;
    }

    inline static LookaheadPartNested raise_single(LookaheadPartFlat part) {
        LookaheadPartNested ret;
        ret.univ_ = make_rc<Set<StringSet_T<Unit>>>();
        ret.part_ = make_rc<Set<Set_T<StringSet_T<Unit>>>>();
        for (auto s : *part) {
            auto part_s = make_rc<Set<StringSet_T<Unit>>>();
            for (auto [la, _] : *s->items_) {
                auto la_s = string_set_single<Unit>(la, Unit{}, s->k_, s->strict_eq_);
                ret.univ_->insert(la_s);
                part_s->insert(la_s);
            }
            ret.part_->insert(part_s);
        }
        return ret;
    }

    inline static LookaheadPartNested raise_join_coarse(LookaheadPartFlat part) {
        LookaheadPartNested ret;
        ret.univ_ = part;
        ret.part_ = make_rc<Set<Set_T<StringSet_T<Unit>>>>();
        ret.part_->insert(ret.univ_);
        return ret;
    }
};


using LookaheadPartsNested = Map_T<LRVertex_T, LookaheadPartNested>;


inline LookaheadPartsFlat lookahead_parts_flatten(LookaheadPartsNested parts) {
    auto ret = make_rc<Map<LRVertex_T, LookaheadPartFlat>>();
    for (auto [v, part] : *parts) {
        ret->insert(v, part.flatten());
    }
    return ret;
}


inline LookaheadPartsNested lookahead_parts_raise_single(LookaheadPartsFlat parts) {
    auto ret = make_rc<Map<LRVertex_T, LookaheadPartNested>>();
    for (auto [v, part] : *parts) {
        ret->insert(v, LookaheadPartNested::raise_single(part));
    }
    return ret;
}


inline LookaheadPartsNested lookahead_parts_raise_join_coarse(LookaheadPartsFlat parts) {
    auto ret = make_rc<Map<LRVertex_T, LookaheadPartNested>>();
    for (auto [v, part] : *parts) {
        ret->insert(v, LookaheadPartNested::raise_join_coarse(part));
    }
    return ret;
}


inline void pr(ostream& os, FmtFlags flags, LookaheadPartNested part) {
    pr(os, flags, part.part_);
}


LookaheadPartFlat lookahead_part_trivial() {
    auto ret = make_rc<Set<StringSet_T<Unit>>>();
    ret->insert(string_set_single_empty_unit(0, true));
    return ret;
}


AttrBoundSet_T lr_prod_bounds_pred(
    DottedProd_T dp, AttrBoundSet_T lhs_bounds, GrammarProdConstrs_T G_constrs) {

    auto ret = make_rc<Map<AttrKey_T, AttrBound_T>>();

    for (auto constr : *G_constrs->operator[](dp->prod_)) {
        if (constr->is_LhsLeq()) {
            // pass
        } else if (constr->is_RhsGeq()) {
            auto cc = constr->as_RhsGeq();
            if (cc->i_ == dp->dot_) {
                auto lo = cc->v_;
                if (ret->contains_key(cc->k_)) {
                    lo = attr_val_maximum(lo, ret->operator[](cc->k_)->lo_);
                }
                ret->insert(cc->k_, AttrBound::make(lo));
            }
        } else if (constr->is_Implies()) {
            auto cc = constr->as_Implies();
            if (cc->i_ == dp->dot_) {
                if (lhs_bounds->m_->contains_key(cc->kl_)) {
                    auto lo = lhs_bounds->m_->operator[](cc->kl_)->lo_;
                    if (ret->contains_key(cc->kr_)) {
                        lo = attr_val_maximum(lo, ret->operator[](cc->kr_)->lo_);
                    }
                    ret->insert(cc->kr_, AttrBound::make(lo));
                }
            }
        } else {
            AX();
        }
    }

    return AttrBoundSet::make(ret);
}


AttrBoundSet_T lr_vertex_bounds_pred(LRVertex_T v, GrammarProdConstrs_T G_constrs) {
    if (v->is_RecStart()) {
        return v->bounds_;
    }
    AT(v->is_Prod());
    auto dp = v->as_Prod()->prod_;
    return lr_prod_bounds_pred(dp, v->bounds_, G_constrs);
}


bool lr_cursor_unfold_naive(DottedProd_T dp, Grammar_T G) {
    AT(!dotted_prod_is_end(dp));
    return dp->prod_->unfold_mask_->operator[](dp->dot_);
}


bool lr_cursor_unfold(LRVertex_T v, Grammar_T G) {
    if (v->is_RecStart()) {
        return true;
    } else if (v->is_RecEnd()) {
        AX();
    } else if (v->is_Prod()) {
        auto dp = v->as_Prod()->prod_;
        bool ret = lr_cursor_unfold_naive(dp, G);
        if (v->as_Prod()->left_rec_.is_some() &&
            val_hash(v->as_Prod()->left_rec_.as_some()) == val_hash(dotted_prod_cursor(dp))) {
            ret = true;
        }
        return ret;
    } else {
        AX();
    }
}


bool lr_lookahead_pred_compat(
    LRVertex_T v, LRVertex_T w, Int k, Grammar_T G, GrammarSymConstrGen_T G_gen,
    GrammarProdConstrs_T G_constrs) {

    if (k == 0) {
        return true;
    }

    if (v->is_Prod()) {
        auto la_v_tail = lr_prod_tail_constr_gen(
            dotted_prod_with_step(v->as_Prod()->prod_),
            v->bounds_,
            v->la_,
            G_gen,
            k,
            G_constrs);
        return string_set_intersection(la_v_tail, w->la_)->items_->length() != 0;
    } else if (v->is_RecStart()) {
        return string_set_intersection(v->la_, w->la_)->items_->length() != 0;
    } else {
        AX();
    }
}


StringSet_T<Unit> lr_sym_constr_gen(
    Sym_T sym,
    AttrBoundSet_T bounds_sym,
    GrammarSymConstrGen_T G_gen,
    Int k,
    GrammarProdConstrs_T G_constrs) {

    auto ret = string_set_empty<Unit>(k, false);
    for (auto [attr, gen_set] : *G_gen->operator[](sym)) {
        if (!attr_set_meets_bounds(attr, bounds_sym)) {
            continue;
        }
        ret = string_set_union<Unit>(ret, string_set_repr_stripped(gen_set));
    }
    return ret;
}


StringSet_T<Unit> lr_prod_comp_constr_gen(
    Prod_T prod,
    Int i,
    AttrBoundSet_T bounds,
    GrammarSymConstrGen_T G_gen,
    Int k,
    GrammarProdConstrs_T G_constrs) {

    auto dp = DottedProd::make(prod, i);
    auto cur = dotted_prod_cursor(dp);
    auto bounds_pred = lr_prod_bounds_pred(dp, bounds, G_constrs);
    return lr_sym_constr_gen(cur, bounds_pred, G_gen, k, G_constrs);
}


StringSet_T<Unit> lr_prod_tail_constr_gen(
    DottedProd_T dp,
    AttrBoundSet_T bounds,
    StringSet_T<Unit> la_end,
    GrammarSymConstrGen_T G_gen,
    Int k,
    GrammarProdConstrs_T G_constrs) {

    auto ret = la_end;
    for (Int i = dp->prod_->rhs_->length() - 1; i >= dp->dot_; i--) {
        auto gen_i = lr_prod_comp_constr_gen(dp->prod_, i, bounds, G_gen, k, G_constrs);
        ret = string_set_concat(gen_i, ret);
    }
    return ret;
}


StringSet_T<Unit> lr_vertex_cur_look_set(
    LRVertex_T w,
    GrammarSymConstrGen_T G_gen,
    Int k,
    GrammarProdConstrs_T G_constrs) {

    if (w->is_RecStart()) {
        auto ret = lr_sym_constr_gen(w->as_RecStart()->sym_,
            w->as_RecStart()->bounds_, G_gen, k, G_constrs);
        return string_set_concat(ret, w->la_);

    } else if (w->is_RecEnd()) {
        return w->la_;

    } else if (w->is_Prod()) {
        if (dotted_prod_is_end(w->as_Prod()->prod_)) {
            return w->la_;
        } else {
            auto dp = w->as_Prod()->prod_;
            auto la = lr_prod_tail_constr_gen(dp, w->bounds_, w->la_, G_gen, k, G_constrs);
            return la;
        }

    } else {
        AX();
    }
}


void lr_nfa_ensure_vertex_acc(
    LRVertex_T w,
    Vec_T<LRVertex_T>& Q,
    LR_NFA_T& N,
    Grammar_T G,
    GrammarSymConstrGen_T G_gen,
    Int k,
    GrammarProdConstrs_T G_constrs) {

    auto [_, fresh] = NFA::ensure_vertex(N, w);

    if (w->is_RecStart()) {
        // pass
    } else if (w->is_RecEnd()) {
        auto acc = LRLookAction::make(w->la_, LRAction::Ret::make(w->as_RecEnd()->sym_));
        NFA::add_action(N, w, acc);
    } else if (w->is_Prod()) {
        if (dotted_prod_is_end(w->as_Prod()->prod_)) {
            auto acc = LRLookAction::make(
                w->la_, LRAction::Reduce::make(w->as_Prod()->prod_->prod_));
            NFA::add_action(N, w, acc);
        } else {
            auto dp = w->as_Prod()->prod_;
            auto la = lr_prod_tail_constr_gen(dp, w->bounds_, w->la_, G_gen, k, G_constrs);
            auto cur = dotted_prod_cursor(dp);

            if (Grammar::sym_is_term(cur)) {
                auto acc = LRLookAction::make(la, LRAction::Shift::make());
                NFA::add_action(N, w, acc);
            } else if (!lr_cursor_unfold(w, G)) {
                auto acc = LRLookAction::make(la, LRAction::Recur::make(cur));
                NFA::add_action(N, w, acc);
            } else {
                // pass
            }
        }
    } else {
        AX();
    }

    if (fresh) {
        Q->push_back(w);
    }
}


void parser_lr_nfa_add_pred_edges(
    Vec_T<LRVertex_T>& Q,
    LR_NFA_T& N,
    LRVertex_T v,
    Grammar_T G,
    GrammarSymConstrGen_T G_gen,
    GrammarSymConstrGen_T G_gen0,
    Option_T<LookaheadPartsFlat> la_part,
    Int k,
    GrammarProdConstrs_T G_constrs) {

    auto sym = lr_vertex_cursor(v);

    auto v_pr_test = lr_vertex_with_bounds_pruned(v, G_gen, G_constrs);
    if (v_pr_test.is_none() || val_hash(v) != val_hash(v_pr_test.as_some())) {
        LG_ERR("{}\n{}\n", v, v_pr_test);
        AX();
    }

    for (auto prod : *G->prods_) {
        if (val_hash(prod->lhs_) != val_hash(sym)) {
            continue;
        }

        auto bounds_pred = lr_vertex_bounds_pred(v, G_constrs);

        Option_T<Sym_T> w_left_rec = None<Sym_T>();
        if (v->is_RecStart()) {
            w_left_rec = Some<Sym_T>(v->as_RecStart()->sym_);
        } else if (v->is_Prod() && v->as_Prod()->prod_->dot_ == 0) {
            w_left_rec = v->as_Prod()->left_rec_;
        } else {
            w_left_rec = None<Sym_T>();
        }

        LRVertex_T w_k0 = LRVertex::Prod::make(
            bounds_pred, string_set_single_empty_unit(0, true), DottedProd::make(prod, 0),
            w_left_rec);
        auto wr_k0 = lr_vertex_with_bounds_pruned(w_k0, G_gen0, G_constrs);
        if (wr_k0.is_none()) {
            continue;
        }
        w_k0 = wr_k0.as_some();
        auto la_part_curr = lookahead_part_trivial();
        if (k != 0) {
            la_part_curr = la_part.as_some()->operator[](w_k0);
        }

        for (auto la : *la_part_curr) {
            LRVertex_T w = LRVertex::Prod::make(
                bounds_pred, la, DottedProd::make(prod, 0), w_left_rec);
            auto wr = lr_vertex_with_bounds_pruned(w, G_gen, G_constrs);
            if (wr.is_none()) {
                continue;
            }
            w = wr.as_some();

            if (!lr_lookahead_pred_compat(v, w, k, G, G_gen, G_constrs)) {
                continue;
            }

            lr_nfa_ensure_vertex_acc(w, Q, N, G, G_gen, k, G_constrs);
            LRLabel_T label = LRLabel::Eps::make();
            NFA::add_edge(N, v, label, w);
        }
    }
}


void parser_lr_nfa_add_rec_edges(
    Vec_T<LRVertex_T>& Q,
    LR_NFA_T& N,
    LRVertex_T v,
    Grammar_T G,
    GrammarSymConstrGen_T G_gen,
    GrammarSymConstrGen_T G_gen0,
    Option_T<LookaheadPartsFlat> la_part,
    Int k,
    GrammarProdConstrs_T G_constrs) {

    auto sym = lr_vertex_cursor(v);

    auto bounds_pred = lr_vertex_bounds_pred(v, G_constrs);

    LRVertex_T w_k0 = LRVertex::RecStart::make(
        bounds_pred, string_set_single_empty_unit(0, true), sym);
    auto wr_k0 = lr_vertex_with_bounds_pruned(w_k0, G_gen0, G_constrs);
    w_k0 = wr_k0.as_some();
    auto la_part_curr = lookahead_part_trivial();
    if (k != 0) {
        la_part_curr = la_part.as_some()->operator[](w_k0);
    }

    for (auto la : *la_part_curr) {
        LRVertex_T w = LRVertex::RecStart::make(bounds_pred, la, sym);
        auto wr = lr_vertex_with_bounds_pruned(w, G_gen, G_constrs);
        if (wr.is_none()) {
            continue;
        }
        w = wr.as_some();

        if (!lr_lookahead_pred_compat(v, w, k, G, G_gen, G_constrs)) {
            continue;
        }

        lr_nfa_ensure_vertex_acc(w, Q, N, G, G_gen, k, G_constrs);
        LRLabel_T label = LRLabel::Sym_::make(LRSym::RecurStep::make(sym), attr_set_empty());
        NFA::add_edge(N, v, label, w);
    }
}


LR_NFA_T parser_lr_construct_nfa(
    Grammar_T G,
    GrammarSymConstrGen_T G_gen,
    GrammarSymConstrGen_T G_gen0,
    Option_T<LookaheadPartsFlat> la_part,
    Int k,
    GrammarProdConstrs_T G_constrs) {

    auto N = NFA::empty<LRVertex_T, LRLabel_T, LRLookAction_T>();

    LRVertex_T v0 = LRVertex::RecStart::make(
        attr_bound_set_empty(), lookahead_sentinel(k), Sym::Start::make());
    auto i0 = NFA::add_vertex(N, v0);
    N->start_ = Some<Int>(i0);

    auto Q = make_rc<Vec<LRVertex_T>>();
    Q->push_back(v0);

    while (!Q->empty()) {
        auto v = Q->pop_front_val();

        if (v->is_RecStart()) {
            auto sym = v->as_RecStart()->sym_;
            LRVertex_T v_end = LRVertex::RecEnd::make(v->bounds_, v->la_, sym);
            auto vr_end = lr_vertex_with_bounds_pruned(v_end, G_gen, G_constrs);
            if (vr_end.is_none()) {
                continue;
            }
            v_end = vr_end.as_some();
            lr_nfa_ensure_vertex_acc(v_end, Q, N, G, G_gen, k, G_constrs);
            for (auto p : *G_gen->operator[](sym)) {
                if (attr_set_meets_bounds(p.first, v->bounds_)) {
                    LRLabel_T label = LRLabel::Sym_::make(LRSym::Base::make(sym), p.first);
                    NFA::add_edge(N, v, label, v_end);
                }
            }
            parser_lr_nfa_add_pred_edges(Q, N, v, G, G_gen, G_gen0, la_part, k, G_constrs);
            continue;
        } else if (v->is_RecEnd()) {
            continue;
        }
        AT(v->is_Prod());

        auto dp = v->as_Prod()->prod_;
        if (dotted_prod_is_end(dp)) {
            continue;
        }
        auto cur = lr_vertex_cursor(v);

        // Step edges
        for (auto p : *G_gen->operator[](cur)) {
            if (attr_set_meets_bounds(p.first, lr_vertex_bounds_pred(v, G_constrs))) {
                LRLabel_T label = LRLabel::Sym_::make(LRSym::Base::make(cur), p.first);

                LRVertex_T v_next = LRVertex::Prod::make(
                    v->bounds_, v->la_, dotted_prod_with_step(v->as_Prod()->prod_), None<Sym_T>());
                auto vr_next = lr_vertex_with_bounds_pruned(v_next, G_gen, G_constrs);
                AT(vr_next.is_some());
                v_next = vr_next.as_some();
                lr_nfa_ensure_vertex_acc(v_next, Q, N, G, G_gen, k, G_constrs);

                NFA::add_edge(N, v, label, v_next);
            }
        }

        if (Grammar::sym_is_nonterm(cur)) {
            // Prediction/recursion edges
            if (!lr_cursor_unfold(v, G)) {
                parser_lr_nfa_add_rec_edges(Q, N, v, G, G_gen, G_gen0, la_part, k, G_constrs);
            } else {
                parser_lr_nfa_add_pred_edges(Q, N, v, G, G_gen, G_gen0, la_part, k, G_constrs);
            }
        }
    }

    N->finalized_ = true;

    return N;
}


using LRFollowSets_T = Map_T<LRVertex_T, StringSet_T<Unit>>;

LRFollowSets_T lr_nfa_compute_follows(
    LR_NFA_T N0,
    Grammar_T G,
    GrammarSymConstrGen_T G_gen,
    Int k,
    GrammarProdConstrs_T G_constrs) {

    auto ret = make_rc<Map<LRVertex_T, StringSet_T<Unit>>>();

    auto Q = make_rc<Vec<LRVertex_T>>();

    auto v0 = N0->G_->V_->operator[](N0->start_.as_some());
    auto la0 = lookahead_sentinel(k);
    ret->insert(v0, la0);
    Q->push_back(v0);

    while (!Q->empty()) {
        auto v = Q->pop_front_val();
        auto la = ret->operator[](v);

        auto es = NFA::outgoing_edges(N0, v);
        for (auto [lbl, nbrs] : *es) {
            for (auto nbr : *nbrs) {
                bool updated = false;
                if (!ret->contains_key(nbr)) {
                    ret->insert(nbr, string_set_empty<Unit>(k, true));
                    updated = true;
                }

                auto la_incr = la;

                if (lbl->is_Eps() || (lbl->is_Sym_() && lbl->as_Sym_()->sym_->is_RecurStep())) {
                    if (v->is_Prod()) {
                        la_incr = lr_prod_tail_constr_gen(
                            dotted_prod_with_step(v->as_Prod()->prod_),
                            v->bounds_,
                            la,
                            G_gen,
                            k,
                            G_constrs);
                    } else if (v->is_RecStart()) {
                        la_incr = la;
                    } else {
                        AX();
                    }
                } else {
                    la_incr = la;
                }

                auto la_prev = ret->operator[](nbr);
                auto la_new = string_set_union(la_prev, la_incr);
                if (la_new->items_->length() > la_prev->items_->length()) {
                    updated = true;
                }
                ret->insert(nbr, la_new);

                if (updated) {
                    Q->push_back(nbr);
                }
            }
        }
    }

    return ret;
}


LookaheadPartsFlat lr_extract_slr_partitions(LRFollowSets_T fol) {
    auto ret = make_rc<Map<LRVertex_T, LookaheadPartFlat>>();
    for (auto [v, v_fol] : *fol) {
        auto v_part = make_rc<Set<StringSet_T<Unit>>>();
        v_part->insert(v_fol);
        ret->insert(v, v_part);
    }
    return ret;
}


Map_T<SymStr_T, Map_T<LRAction_T, Set_T<LRVertex_T>>> lr_tabulate_nfa_acc(
    LR_NFA_T N, Set_T<LRVertex_T> vs) {

    auto ret = make_rc<Map<SymStr_T, Map_T<LRAction_T, Set_T<LRVertex_T>>>>();
    for (auto v : *vs) {
        auto vi = N->G_->V_->index_of_maybe(v).as_some();
        for (auto x : *N->acc_->operator[](vi)) {
            for (auto [la_str, _] : *x->la_->items_) {
                if (!ret->contains_key(la_str)) {
                    ret->insert(la_str, make_rc<Map<LRAction_T, Set_T<LRVertex_T>>>());
                }
                if (!ret->operator[](la_str)->contains_key(x->acc_)) {
                    ret->operator[](la_str)->insert(x->acc_, make_rc<Set<LRVertex_T>>());
                }
                ret->operator[](la_str)->operator[](x->acc_)->insert(v);
            }
        }
    }
    return ret;
}


Map_T<SymStr_T, Map_T<LRAction_T, Set_T<LRVertex_T>>> lr_tabulate_nfa_acc_single(
    LR_NFA_T N, LRVertex_T v) {

    auto vs = make_rc<Set<LRVertex_T>>();
    vs->insert(v);
    return lr_tabulate_nfa_acc(N, vs);
}


Set_T<Sym_T> lr_extract_slr_sym_cps_conf(Grammar_T G, LR_DFA_T Ds, LR_NFA_T Ns) {
    auto ret = make_rc<Set<Sym_T>>();

    for (auto vs : *Ds->G_->V_) {
        auto acc_table = lr_tabulate_nfa_acc(Ns, vs);
        for (auto p : *acc_table) {
            if (p.second->length() > 1) {
                for (auto x : *p.second) {
                    if (x.first->is_Reduce()) {
                        auto sym = x.first->as_Reduce()->prod_->lhs_;
                        if (Grammar::sym_is_cps_eligible(sym)) {
                            ret->insert(sym);
                        }
                    } else if (x.first->is_Recur()) {
                        auto sym = x.first->as_Recur()->sym_;
                        if (Grammar::sym_is_cps_eligible(sym)) {
                            ret->insert(sym);
                        }
                    }
                }
            }
        }
    }

    // Close set
    auto Q = make_rc<Vec<Sym_T>>();
    for (auto x : *ret) {
        Q->push_back(x);
    }
    while (!Q->empty()) {
        auto curr = Q->pop_front_val();
        for (auto prod : *G->prods_by_nonterm_rhs_->operator[](curr)) {
            auto next = prod->prod_->lhs_;
            if (Grammar::sym_is_cps_eligible(next) && !ret->contains(next)) {
                ret->insert(next);
                Q->push_back(next);
            }
        }
    }

    return ret;
}


LRVertex_T lr_vertex_with_lookahead(LRVertex_T v, StringSet_T<Unit> la) {
    if (v->is_Prod()) {
        return LRVertex::Prod::make(v->bounds_, la, v->as_Prod()->prod_, v->as_Prod()->left_rec_);
    } else if (v->is_RecStart()) {
        return LRVertex::RecStart::make(v->bounds_, la, v->as_RecStart()->sym_);
    } else if (v->is_RecEnd()) {
        return LRVertex::RecEnd::make(v->bounds_, la, v->as_RecEnd()->sym_);
    } else {
        AX();
    }
}


LookaheadPartsFlat lr_extract_immed_conf_part(
    LR_DFA_T Ds, LR_NFA_T Ns, LookaheadPartsFlat la_part_slr,
    GrammarSymConstrGen_T G_gen, Int k, GrammarProdConstrs_T G_constrs) {

    auto la_conf = make_rc<Map<LRVertex_T, Set_T<StringSet_T<Unit>>>>();

    for (auto [v0, v_part] : *la_part_slr) {
        auto v0_la_conf_init = make_rc<Set<StringSet_T<Unit>>>();
        v0_la_conf_init->insert(v_part->only());
        la_conf->insert(v0, v0_la_conf_init);
    }

    for (auto vs : *Ds->G_->V_) {
        auto acc_table = lr_tabulate_nfa_acc(Ns, vs);

        for (auto p : *acc_table) {
            if (p.second->length() > 1) {
                for (auto q : *p.second) {
                    for (auto v : *q.second) {
                        auto v0 = lr_vertex_with_lookahead(
                            v, string_set_single_empty_unit(0, true));

                        auto la_matching = string_set_empty<Unit>(k, true);
                        auto la_non_matching = string_set_empty<Unit>(k, true);

                        for (auto [la, _] : *la_part_slr->operator[](v0)->only()->items_) {
                            auto la_single = string_set_single(la, Unit{}, k, true);
                            auto v_la = lr_vertex_with_lookahead(v, la_single);
                            auto v_cur = lr_vertex_cur_look_set(v_la, G_gen, k, G_constrs);
                            if (v_cur->items_->contains_key(p.first)) {
                                la_matching->items_->insert(la, Unit{});
                            } else {
                                la_non_matching->items_->insert(la, Unit{});
                            }
                        }

                        LOG(3, "v: {}", v);
                        LOG(3, "la_matching: {}", la_matching);

                        auto v0_la_conf_new = make_rc<Set<StringSet_T<Unit>>>();
                        for (auto s_curr : *la_conf->operator[](v0)) {
                            auto s_in = string_set_intersection(s_curr, la_matching);
                            auto s_out = string_set_intersection(s_curr, la_non_matching);
                            if (s_in->items_->length() > 0) {
                                v0_la_conf_new->insert(s_in);
                            }
                            if (s_out->items_->length() > 0) {
                                v0_la_conf_new->insert(s_out);
                            }
                        }
                        la_conf->insert(v0, v0_la_conf_new);
                    }
                }
            }
        }
    }

    LOG(3, " === Conflicting lookaheads:\n{}\n\n", la_conf);

    return la_conf;
}


enum struct LookaheadPartDir {
    BWD,
    FWD,
};


LookaheadPartsNested lr_prop_part(
    LookaheadPartDir dir,
    LookaheadPartsNested lr_part_init,
    LR_NFA_T N0,
    Grammar_T G,
    GrammarSymConstrGen_T G_gen,
    Int k,
    GrammarProdConstrs_T G_constrs) {

    auto ret = make_rc<Map<LRVertex_T, LookaheadPartNested>>();

    auto Q = make_rc<Vec<LRVertex_T>>();
    auto Qs = make_rc<Set<LRVertex_T>>();
    for (auto v : *lr_part_init) {
        ret->insert(v.first, v.second);
        Q->push_back(v.first);
        Qs->insert(v.first);
    }

    while (!Q->empty()) {
        auto curr = Q->pop_front_val();
        Qs->remove(curr);


        Map_T<LRLabel_T, Vec_T<LRVertex_T>> m;
        if (dir == LookaheadPartDir::BWD) {
            m = NFA::incoming_edges(N0, curr);
        } else if (dir == LookaheadPartDir::FWD) {
            m = NFA::outgoing_edges(N0, curr);
        } else {
            AX();
        }

        for (auto [lbl, nbrs] : *m) {
            for (auto nbr : *nbrs) {
                auto sigs = make_rc<Vec<Vec_T<Int>>>();

                auto nbr_la_vec = make_rc<Vec<StringSet_T<Unit>>>();

                Int si = 0;
                if (!ret->contains_key(nbr)) {
                    LG_ERR("Not found: {} (curr: {})", nbr, curr);
                    AX();
                }
                auto ret_nbr = ret->operator[](nbr);
                for (auto s : *ret_nbr.part_) {
                    for (auto la_s : *s) {
                        nbr_la_vec->push_back(la_s);

                        auto sig = make_rc<Vec<Int>>();
                        sig->push_back(si);

                        auto nbr_full = lr_vertex_with_lookahead(nbr, la_s);

                        for (auto t : *ret->operator[](curr).part_) {
                            auto la_t = string_set_union_multi(t);
                            auto curr_full = lr_vertex_with_lookahead(curr, la_t);
                            bool r;
                            if (lbl->is_Eps() ||
                                (lbl->is_Sym_() && lbl->as_Sym_()->sym_->is_RecurStep())) {
                                if (dir == LookaheadPartDir::BWD) {
                                    r = lr_lookahead_pred_compat(
                                        nbr_full, curr_full, k, G, G_gen, G_constrs);
                                } else if (dir == LookaheadPartDir::FWD) {
                                    r = lr_lookahead_pred_compat(
                                        curr_full, nbr_full, k, G, G_gen, G_constrs);
                                } else {
                                    AX();
                                }
                            } else if (lbl->is_Sym_()) {
                                r = string_set_intersection(la_t, la_s)->items_->length() != 0;
                            } else {
                                AX();
                            }
                            sig->push_back(static_cast<Int>(r));
                        }

                        sigs->push_back(sig);
                    }
                    ++si;
                }

                Int R = nbr_la_vec->length();
                AT(sigs->length() == R);

                auto sig_map = make_rc<Map<Vec_T<Int>, Vec_T<Int>>>();
                for (Int r = 0; r < R; r++) {
                    sig_map->at_create_shared<Vec<Int>>(sigs->operator[](r))->push_back(r);
                }

                auto ret_nbr_part_new = make_rc<Set<Set_T<StringSet_T<Unit>>>>();

                for (auto [_, la_ind_set] : *sig_map) {
                    auto items = make_rc<Set<StringSet_T<Unit>>>();
                    for (auto i : *la_ind_set) {
                        items->insert(nbr_la_vec->operator[](i));
                    }
                    ret_nbr_part_new->insert(items);
                }

                if (val_hash(ret_nbr_part_new) != val_hash(ret->operator[](nbr).part_) &&
                    !Qs->contains(nbr)) {
                    Q->push_back(nbr);
                    Qs->insert(nbr);
                }

                LookaheadPartNested ret_nbr_new;
                ret_nbr_new.univ_ = ret->operator[](nbr).univ_;
                ret_nbr_new.part_ = ret_nbr_part_new;
                ret->insert(nbr, ret_nbr_new);
            }
        }
    }

    return ret;
}


LRStringExemplar_T lr_conflict_extract_exemplar_sym(LRSym_T sym, AttrSet_T attr,
    GrammarSymConstrGen_T G_gen) {

    SymStr_T contents;
    if (sym->is_RecurStep()) {
        auto contents_items = make_rc<Vec<LRSym_T>>();
        contents_items->push_back(sym);
        contents = SymStr::make(contents_items);
    } else {
        contents = string_set_min_len_element(
            G_gen->operator[](sym->as_Base()->sym_)->operator[](attr));
    }
    auto ret = LRStringExemplar::make(sym, attr, contents);
    return ret;
}


Vec_T<LRStringExemplarBounded_T> lr_conflict_extract_exemplars_tail(
    LRVertex_T v, bool proper,
    GrammarSymConstrGen_T G_gen, GrammarProdConstrs_T G_constrs) {

    if (v->is_Prod()) {
        auto ret = make_rc<Vec<LRStringExemplarBounded_T>>();
        auto dp = v->as_Prod()->prod_;
        Int i0 = dp->dot_;
        if (proper) {
            AT(!dotted_prod_is_end(dp));
            i0 = dp->dot_ + 1;
        }
        for (Int i = i0; i < dp->prod_->rhs_->length(); i++) {
            auto sym_i = dp->prod_->rhs_->operator[](i);
            auto bounds_i = lr_prod_bounds_pred(
                dp, v->as_Prod()->bounds_, G_constrs);
            LRStringExemplarBounded_T exr =
                LRStringExemplarBounded::make(LRSym::Base::make(sym_i), bounds_i);
            ret->push_back(exr);
        }
        return ret;
    } else if (v->is_RecStart()) {
        // RecStart NFA vertices have no actions, hence cannot be called
        // with !proper (this would imply they are at the end of a path).
        AT(proper, "lr_conflict_extract_exemplars_tail proper");
        return make_rc<Vec<LRStringExemplarBounded_T>>();
    } else if (v->is_RecEnd()) {
        AT(!proper, "lr_conflict_extract_exemplars_tail !proper");
        return make_rc<Vec<LRStringExemplarBounded_T>>();
    } else {
        LG_ERR("lr_conflict_extract_exemplars_tail unknown: {}", v);
        AX();
    }
}


Int lr_conflict_nfa_search_post_buffer_len_heuristic(
    Vec_T<LRStringExemplarBounded_T> buf, GrammarSymConstrGen_T G_gen) {

    Int ret = 0;
    for (auto x : *buf) {
        Option_T<Int> x_len_min = None<Int>();
        for (auto [q_attr, qss] : *G_gen->operator[](x->sym_->as_Base()->sym_)) {
            if (!attr_set_meets_bounds_relaxed(q_attr, x->bounds_)) {
                continue;
            }
            for (auto [_, qss_str] : *qss->items_) {
                if (x_len_min.is_none() || qss_str->v_->length() < x_len_min.as_some()) {
                    x_len_min = Some<Int>(qss_str->v_->length());
                }
            }
        }
        ret += x_len_min.as_some();
    }
    return ret;
}


template<typename T, typename U> pair<T, U> pair_neg(pair<T, U> x) {
    return make_pair(- x.first, - x.second);
}


template<typename T, typename U> pair<T, U> pair_fst_add(pair<T, U> x, T inc) {
    return make_pair(x.first + inc, x.second);
}


template<typename T, typename U> pair<T, U> pair_snd_add(pair<T, U> x, U inc) {
    return make_pair(x.first, x.second + inc);
}


Vec_T<LRStringExemplar_T> lr_conflict_nfa_search_post(
    LR_NFA_T N, LRVertex_T w, Vec_T<LRLabel_T> pre, SymStr_T la, GrammarSymConstrGen_T G_gen,
    GrammarProdConstrs_T G_constrs) {

    Int k = la->v_->length();

    using Len = IntPair;  // (length in symbols, number of eps/RS-edges)
    using LookaheadIndex = Int;
    using PrePathIndex = Int;
    using SearchVertex_T = tuple<
        LRVertex_T, PrePathIndex, LookaheadIndex, Vec_T<LRStringExemplarBounded_T>>;
    auto tail_init = lr_conflict_extract_exemplars_tail(w, false, G_gen, G_constrs);
    SearchVertex_T v0 = make_tuple(w, pre->length(), 0, tail_init);
    auto vis_len = make_rc<Map<SearchVertex_T, Len>>();
    using BackEdge_T = pair<Option_T<LRStringExemplar_T>, SearchVertex_T>;
    auto vis_pred = make_rc<Map<SearchVertex_T, Option_T<BackEdge_T>>>();
    vis_len->insert(v0, make_pair(0, 0));
    vis_pred->insert(v0, None<BackEdge_T>());
    auto vs = make_rc<VecUniq<SearchVertex_T>>();
    Int vi0 = vs->insert(v0);
    priority_queue<pair<Len, Int>> Q;
    Len len0 = make_pair(lr_conflict_nfa_search_post_buffer_len_heuristic(tail_init, G_gen), 0);
    Q.push(make_pair(pair_neg(len0), vi0));

    auto N_start = N->G_->V_->operator[](N->start_.as_some());
    auto vs_tgt = make_rc<Vec<SearchVertex_T>>();
    Int k_tgt = k;
    while (k_tgt > 0) {
        if (!la->v_->operator[](k_tgt - 1)->is_EndMarker()) {
            break;
        }
        --k_tgt;
    }
    SearchVertex_T v_tgt = make_tuple(
        N_start, 0, k_tgt, make_rc<Vec<LRStringExemplarBounded_T>>());

    while (!Q.empty()) {
        auto [len_bound_curr, vi_curr] = Q.top();
        Q.pop();
        len_bound_curr = make_pair(- len_bound_curr.first, - len_bound_curr.second);

        if (vis_len->contains_key(v_tgt) && vis_len->operator[](v_tgt) <= len_bound_curr) {
            break;
        }

        auto v_curr = vs->operator[](vi_curr);
        auto len_curr = vis_len->operator[](v_curr);
        auto [x, pre_ind, la_ind, buf] = v_curr;

        LOG(4, "lr_conflict_nfa_search_post: search v_curr = {}", v_curr);

        if (buf->length() > 0) {
            auto fst = buf->operator[](0);
            for (auto [q_attr, qss] : *G_gen->operator[](fst->sym_->as_Base()->sym_)) {
                if (!attr_set_meets_bounds_relaxed(q_attr, fst->bounds_)) {
                    continue;
                }

                for (auto [_, qss_str] : *qss->items_) {
                    bool ok = true;
                    Int match_len = min<Int>(
                        k - la_ind, qss_str->v_->length());
                    for (Int j = 0; j < match_len; j++) {
                        if (val_hash(qss_str->v_->operator[](j)) !=
                            val_hash(la->v_->operator[](la_ind + j))) {
                            ok = false;
                            break;
                        }
                    }
                    if (!ok) {
                        continue;
                    }

                    auto buf_nbr = buf->slice(1, buf->length());
                    auto x_nbr = make_tuple(x, pre_ind, la_ind + match_len, buf_nbr);
                    auto vi_nbr = vs->insert(x_nbr);
                    auto len_nbr = make_pair(
                        len_curr.first + qss_str->v_->length(), len_curr.second);
                    auto str_exr = LRStringExemplar::make(fst->sym_, q_attr, qss_str);
                    BackEdge_T v_curr_be = make_pair(Some<LRStringExemplar_T>(str_exr), v_curr);
                    if (!vis_len->contains_key(x_nbr) || vis_len->operator[](x_nbr) > len_nbr) {
                        vis_len->insert(x_nbr, len_nbr);
                        vis_pred->insert(x_nbr, Some<BackEdge_T>(v_curr_be));
                        auto tail_len_h = lr_conflict_nfa_search_post_buffer_len_heuristic(
                            buf_nbr, G_gen);
                        Q.push(make_pair(pair_neg(pair_fst_add(len_nbr, tail_len_h)), vi_nbr));
                    }
                }
            }

        } else {  // buf->length() == 0
            auto es = NFA::incoming_edges(N, x);
            for (auto [lbl, ys] : *es) {
                for (auto y : *ys) {
                    bool is_recurstep = lbl->is_Sym_() && lbl->as_Sym_()->sym_->is_RecurStep();

                    if (lbl->is_Eps() || is_recurstep) {
                        if (is_recurstep) {
                            if (pre_ind == 0) {
                                continue;
                            }
                            if (val_hash(lbl) != val_hash(pre->operator[](pre_ind - 1))) {
                                continue;
                            }
                        }

                        auto buf_nbr = lr_conflict_extract_exemplars_tail(y, true, G_gen, G_constrs);
                        auto x_nbr = make_tuple(
                            y, pre_ind - (is_recurstep ? 1 : 0), la_ind, buf_nbr);
                        auto vi_nbr = vs->insert(x_nbr);
                        auto len_nbr = pair_snd_add(len_curr, Int(1));
                        BackEdge_T v_curr_be = make_pair(None<LRStringExemplar_T>(), v_curr);

                        if (!vis_len->contains_key(x_nbr) || vis_len->operator[](x_nbr) > len_nbr) {
                            vis_len->insert(x_nbr, len_nbr);
                            vis_pred->insert(x_nbr, Some<BackEdge_T>(v_curr_be));
                            auto tail_len_h = lr_conflict_nfa_search_post_buffer_len_heuristic(
                                buf_nbr, G_gen);
                            Q.push(make_pair(pair_neg(pair_fst_add(len_nbr, tail_len_h)), vi_nbr));
                        }

                    } else {
                        if (pre_ind == 0) {
                            continue;
                        }
                        if (val_hash(lbl) != val_hash(pre->operator[](pre_ind - 1))) {
                            continue;
                        }

                        auto buf_nbr = make_rc<Vec<LRStringExemplarBounded_T>>();
                        auto x_nbr = make_tuple(y, pre_ind - 1, la_ind, buf_nbr);
                        auto vi_nbr = vs->insert(x_nbr);
                        auto len_nbr = len_curr;
                        BackEdge_T v_curr_be = make_pair(None<LRStringExemplar_T>(), v_curr);

                        if (!vis_len->contains_key(x_nbr) || vis_len->operator[](x_nbr) > len_nbr) {
                            vis_len->insert(x_nbr, len_nbr);
                            vis_pred->insert(x_nbr, Some<BackEdge_T>(v_curr_be));
                            auto tail_len_h = lr_conflict_nfa_search_post_buffer_len_heuristic(
                                buf_nbr, G_gen);
                            Q.push(make_pair(pair_neg(pair_fst_add(len_nbr, tail_len_h)), vi_nbr));
                        }
                    }
                }
            }

        }
    }

    auto ret = make_rc<Vec<LRStringExemplar_T>>();

    if (!vis_pred->contains_key(v_tgt)) {
        LG_ERR("Conflict search failed: {}", v_tgt);
        AX();
    }

    auto v_curr = v_tgt;
    while (true) {
        auto be = vis_pred->operator[](v_curr);
        if (be.is_none()) {
            break;
        }
        if (be.as_some().first.is_some()) {
            ret->push(be.as_some().first.as_some());
        }
        v_curr = be.as_some().second;
    }
    ret->reverse();

    return ret;
}


void pr(ostream& os, FmtFlags flags, LRConflict_T conf) {
    vector<tuple<Int, Align>> aligns;
    aligns.push_back(make_pair(4, Align::RIGHT));
    aligns.push_back(make_pair(4, Align::RIGHT));
    for (Int i = 1; i < conf->items_->length(); i++) {
        aligns.push_back(make_pair(4, Align::LEFT));
    }
    auto td = PrintTable::make(aligns);

    auto exr0 = conf->items_->operator[](0)->exr_;
    for (auto item : *exr0->pre_) {
        Int ii = 0;

        for (auto x : *item->contents_->v_) {
            if (ii == 0 && !item->sym_->is_RecurStep()) {
                td->push(fmt_str("{}", item->sym_));
            } else {
                td->push_blank_item();
            }
            td->push(fmt_str("{}", x));

            for (Int i = 1; i < conf->items_->length(); i++) {
                td->push_blank_item();
            }
            ++ii;
        }
    }

    td->push_blank_line();

    for (Int i = 0; i < conf->items_->length(); i++) {
        if (i == 0) {
            td->push_blank_item();
        }
        td->push(fmt_str("{}", conf->items_->operator[](i)->acc_));
    }

    td->push_blank_line();

    auto full_traces = make_rc<Vec<Vec_T<LRSym_T>>>();
    for (Int i = 0; i < conf->items_->length(); i++) {
        auto full_trace_i = make_rc<Vec<LRSym_T>>();
        for (auto item : *conf->items_->operator[](i)->exr_->post_) {
            for (auto x : *item->contents_->v_) {
                full_trace_i->push_back(x);
            }
        }
        full_traces->push_back(full_trace_i);
    }
    Int j = 0;
    while (true) {
        bool any_active = false;
        td->push_blank_item();
        for (Int i = 0; i < full_traces->length(); i++) {
            if (j >= full_traces->operator[](i)->length()) {
                td->push_blank_item();
            } else {
                any_active = true;
                td->push(fmt_str("{}", full_traces->operator[](i)->operator[](j)));
            }
        }
        ++j;
        if (!any_active) {
            break;
        }
    }

    fmt(os, "{}", td);
}


Set_T<LRVertex_T> lr_dfa_vertex_without_lookahead(Set_T<LRVertex_T> vs) {
    auto ret = make_rc<Set<LRVertex_T>>();
    for (auto v : *vs) {
        ret->insert(lr_vertex_without_lookahead(v));
    }
    return ret;
}


Int lr_exemplar_bidir_len_total(LRStringExemplarBidir_T x) {
    Int ret = 0;
    for (auto str_exr : *x->pre_) {
        ret += str_exr->contents_->v_->length();
    }
    for (auto str_exr : *x->post_) {
        ret += str_exr->contents_->v_->length();
    }
    return ret;
}


Int lr_conflict_len_total(LRConflict_T confl) {
    Int ret = 0;
    for (auto exr : *confl->items_) {
        ret += lr_exemplar_bidir_len_total(exr->exr_);
    }
    return ret;
}


Option_T<LangCompileResult::Error::SymUnreach_T> parser_check_all_reach(LangCompileContext& ctx) {
    auto sym_reach = make_rc<Set<Sym_T>>();

    sym_reach->insert(ctx.Gr_flat_->start_.as_some());
    auto Q = make_rc<Vec<Sym_T>>();
    Q->push_back(ctx.Gr_flat_->start_.as_some());

    while (!Q->empty()) {
        auto curr = Q->pop_front_val();
        if (!Grammar::sym_is_nonterm(curr)) {
            continue;
        }
        for (auto prod : *ctx.Gr_flat_->prods_by_nonterm_->operator[](curr)) {
            for (auto next : *prod->rhs_) {
                if (!sym_reach->contains(next)) {
                    sym_reach->insert(next);
                    Q->push_back(next);
                }
            }
        }
    }

    auto ret = make_rc<Vec<Sym_T>>();
    for (auto sym : *ctx.Gr_flat_->nonterm_) {
        if (!sym_reach->contains(sym)) {
            ret->push(sym);
        }
    }
    for (auto sym : *ctx.Gr_flat_->term_) {
        if (!sym_reach->contains(sym)) {
            if (sym->is_Term() && sym->as_Term()->tok_->tok_->is_Special()) {
                continue;
            }
            ret->push(sym);
        }
    }

    if (ret->length() > 0) {
        return Some<LangCompileResult::Error::SymUnreach_T>(
            LangCompileResult::Error::SymUnreach::make(ret));
    }

    return None<LangCompileResult::Error::SymUnreach_T>();
}


Vec_T<LRConflict_T> parser_lr_analysis(LangCompileContext& ctx) {
    Int k = ctx.lr_k_;

    auto cps_triggers_conf = make_rc<Set<Sym_T>>();

    ctx.cps_triggers_filter_ = Some<Set_T<Sym_T>>(cps_triggers_conf);

    Int n_iter = 0;

    GrammarSymConstrGen_T G_gen0, G_gen;
    LR_NFA_T N0, Ns;
    LR_DFA_T Ds;
    LookaheadPartsFlat la_part_slr;

    // Iteratively determine CPS triggers by SLR conflicts.
    while (true) {
        string suffix = fmt_str(" ({} triggers)", ctx.cps_triggers_filter_.as_some()->length());

        LOG(1, "Compiling parser: symbol iteration {}{}", n_iter+1, suffix);

        ctx_Gr_cps_init(ctx);
        parser_grammar_to_cps(ctx);

        LOG(3, " === CPS grammar:\n\n{}\n\n", ctx.Gr_cps_);

        parser_attr_propagate_flattened(ctx);

        LOG(3, " === Init CPS constrs by prod:\n{}\n\n", ctx.Gr_cps_prod_constrs_);

        parser_prod_constr_cps_refine_domains(ctx);

        LOG(3, " === Prod attr domains:\n{}\n\n", ctx.parser_attr_domains_);

        LOG(2, " === Pruned CPS constrs by prod:\n{}\n\n", ctx.Gr_cps_prod_constrs_);

        Int k0 = 0;

        G_gen0 = parser_lr_gen_inhabitants(ctx.Gr_cps_, k0, ctx);

        LOG(3, " === Gen inhabitants (k=0):\n{}\n\n", G_gen0);

        N0 = parser_lr_construct_nfa(
            ctx.Gr_cps_,
            G_gen0,
            G_gen0,
            None<LookaheadPartsFlat>(), 
            k0,
            ctx.Gr_cps_prod_constrs_);

        LOG(4, " === LR(0) NFA:\n{}\n\n", N0);

        G_gen = parser_lr_gen_inhabitants(ctx.Gr_cps_, k, ctx);

        LOG(3, " === Gen inhabitants (k={}):\n{}\n\n", k, G_gen);

        auto fol = lr_nfa_compute_follows(N0, ctx.Gr_cps_, G_gen, k, ctx.Gr_cps_prod_constrs_);    

        LOG(3, " === LR(0) NFA follow sets:\n{}\n\n", fol);

        la_part_slr = lr_extract_slr_partitions(fol);

        Ns = parser_lr_construct_nfa(
            ctx.Gr_cps_,
            G_gen,
            G_gen0,
            Some<LookaheadPartsFlat>(la_part_slr),
            k,
            ctx.Gr_cps_prod_constrs_);

        LOG(1, "SLR({}) NFA: {} vertices, {} edges", k, Ns->G_->V_->length(), Ns->G_->num_edges_);

        LOG(4, " === SLR({}) NFA:\n{}\n\n", k, Ns);

        Ds = NFA::nfa_subset_constr(Ns);

        LOG(4, " === SLR({}) subset NFA:\n{}\n\n", k, Ds);

        LOG(1, "SLR({}) subset NFA: {} vertices, {} edges",
            k, Ds->G_->V_->length(), Ds->G_->num_edges_);

        cps_triggers_conf = lr_extract_slr_sym_cps_conf(ctx.Gr_cps_, Ds, Ns);

        bool ok = true;
        for (auto sym : *cps_triggers_conf) {
            if (sym->is_GenCPS()) {
                AX();
            }
            if (!ctx.cps_triggers_filter_.as_some()->contains(sym)) {
                ctx.cps_triggers_filter_.as_some()->insert(sym);
                ok = false;
            }
        }

        LOG(3, " === CPS triggers (iteration {}):\n{}\n\n",
            n_iter+1, ctx.cps_triggers_filter_);

        ++n_iter;
        if (!ok) {
            continue;
        } else {
            break;
        }
    }

    LOG(3, " === CPS grammar:\n\n{}\n\n", ctx.Gr_cps_);

    LOG(3, " === CPS constrs by prod:\n{}\n\n", ctx.Gr_cps_prod_constrs_);

    Int k0 = 0;

    auto la_part_init = lr_extract_immed_conf_part(
        Ds, Ns, la_part_slr, G_gen, k, ctx.Gr_cps_prod_constrs_);

    LOG(3, " === Immediately conflicting lookahead partition:\n{}\n\n", la_part_init);

    auto la_part_init_nested = lookahead_parts_raise_single(la_part_init);

    LOG(1, "Compiling parser: final lookaheads");

    auto la_part_bwd = lr_prop_part(
        LookaheadPartDir::BWD,
        la_part_init_nested, N0, ctx.Gr_cps_, G_gen, k, ctx.Gr_cps_prod_constrs_);

    auto la_part_bwd_flat = lookahead_parts_flatten(la_part_bwd);

    LOG(3, " === Backward-propagated lookahead partition:\n{}\n\n", la_part_bwd_flat);

    auto la_part_fwd_init = lookahead_parts_raise_join_coarse(la_part_bwd_flat);

    auto la_part_fwd = lr_prop_part(
        LookaheadPartDir::FWD,
        la_part_fwd_init, N0, ctx.Gr_cps_, G_gen, k, ctx.Gr_cps_prod_constrs_);

    LOG(3, " === Forward-propagated lookahead partition:\n{}\n\n", la_part_fwd);

    auto la_part_final = la_part_fwd;

    auto la_part_final_flat = lookahead_parts_flatten(la_part_final);

    LOG(1, "Compiling parser: constructing LR NFA");

    auto N = parser_lr_construct_nfa(
        ctx.Gr_cps_,
        G_gen,
        G_gen0,
        Some<LookaheadPartsFlat>(la_part_final_flat),
        k,
        ctx.Gr_cps_prod_constrs_);

    LOG(4, " === LR({}) NFA:\n{}\n\n", k, N);

    LOG(1, "Compiling parser: LR NFA subset construction");

    auto D = NFA::nfa_subset_constr(N);

    LOG(4, " === LR({}) subset NFA:\n{}\n\n", k, D);

    auto lr_conflict_vs = make_rc<Set<
        tuple<Set_T<LRVertex_T>, SymStr_T, Map_T<LRAction_T, Set_T<LRVertex_T>>>>>();
        // DFA vertex, lookahead, map from action to NFA vertices

    for (auto vs : *D->G_->V_) {
        auto vsi = D->G_->V_->index_of_maybe(vs).as_some();
        auto mm = lr_tabulate_nfa_acc(N, vs);
        for (auto [la, ma] : *mm) {
            if (ma->length() > 1) {
                lr_conflict_vs->insert(make_tuple(vs, la, ma));
            }
        }
    }

    if (lr_conflict_vs->length() == 0) {
        LOG(1, "Compiling parser: no LR conflicts");
        LOG(1, "LR NFA: {} vertices, {} edges", N->G_->V_->length(), N->G_->num_edges_);
        LOG(1, "LR DFA: {} vertices, {} edges", D->G_->V_->length(), D->G_->num_edges_);
    } else {
        LOG(1, "Compiling parser: detected LR conflicts; searching for traces")
    }

    using DFAVertex_T = Set_T<LRVertex_T>;
    using BackEdge_T = pair<DFAVertex_T, LRLabel_T>;
    auto m_pred = make_rc<Map<DFAVertex_T, pair<Int, Option_T<BackEdge_T>>>>();
    {
        priority_queue<IntPair> Q;
        auto hit = make_rc<Set<Int>>();
        auto vsi_start = D->start_.as_some();
        auto vs_start = D->G_->V_->operator[](vsi_start);
        m_pred->insert(vs_start, make_pair(0, None<BackEdge_T>()));
        Q.push(make_pair(0, vsi_start));
        while (!Q.empty()) {
            auto [curr_len, curr_ind] = Q.top();
            curr_len = - curr_len;

            Q.pop();
            if (hit->contains(curr_ind)) {
                continue;
            }
            hit->insert(curr_ind);

            auto curr_vs = D->G_->V_->operator[](curr_ind);
            auto es = NFA::outgoing_edges(D, curr_vs);
            for (auto [lbl, nbrs] : *es) {
                auto nbr = nbrs->only();
                auto lbl_sym = lbl->as_Sym_()->sym_;
                Int lbl_len;
                if (lbl_sym->is_RecurStep()) {
                    lbl_len = 1;
                } else if (lbl_sym->is_Base()) {
                    lbl_len = string_set_min_len_element(G_gen->operator[](
                        lbl_sym->as_Base()->sym_)->operator[](
                            lbl->as_Sym_()->attr_))->v_->length();
                } else {
                    AX();
                }

                if (!m_pred->contains_key(nbr) ||
                    m_pred->operator[](nbr).first > curr_len + lbl_len) {
                    m_pred->insert(
                        nbr, make_pair(
                            curr_len + lbl_len, Some<BackEdge_T>(make_pair(curr_vs, lbl))));
                    Q.push(make_pair(
                        - (curr_len + lbl_len), D->G_->V_->index_of_maybe(nbr).as_some()));
                }
            }
        }
    }

    LOG(3, "lr_conflict_vs:\n{}\n\n", lr_conflict_vs);

    if (lr_conflict_vs->length() > 0) {
        LOG(1, "Compiling parser: tabulating conflicts");
    }

    auto lr_conflict_cand = make_rc<Map<Set_T<LRAction_T>, Vec_T<LRConflict_T>>>();

    for (auto [vs, la, mm] : *lr_conflict_vs) {
        auto pre = make_rc<Vec<LRStringExemplar_T>>();
        auto vs_curr = vs;
        auto buf = make_rc<Vec<LRLabel_T>>();
        while (true) {
            auto [_, back_curr] = m_pred->operator[](vs_curr);
            if (back_curr.is_none()) {
                break;
            }
            auto [vs_next, label_curr] = back_curr.as_some();
            buf->push_back(label_curr);
            vs_curr = vs_next;
        }
        buf->reverse();
        for (auto lbl : *buf) {
            auto exr = lr_conflict_extract_exemplar_sym(
                lbl->as_Sym_()->sym_, lbl->as_Sym_()->attr_, G_gen);
            pre->push(exr);
        }

        auto confl_items = make_rc<Vec<LRConflictExemplar_T>>();
        auto accs = make_rc<Set<LRAction_T>>();
        for (auto [acc, ws] : *mm) {
            accs->insert(acc);
            auto len_min = None<Int>();
            auto exr_min = None<LRConflictExemplar_T>();
            for (auto w : *ws) {
                auto post = lr_conflict_nfa_search_post(
                    N, w, buf, la, G_gen, ctx.Gr_cps_prod_constrs_);
                auto exr = LRStringExemplarBidir::make(pre, post);
                if (len_min.is_none() || lr_exemplar_bidir_len_total(exr) < len_min.as_some()) {
                    len_min = Some<Int>(lr_exemplar_bidir_len_total(exr));
                    exr_min = Some<LRConflictExemplar_T>(LRConflictExemplar::make(exr, la, acc));
                }
            }
            confl_items->push(exr_min.as_some());
        }
        auto confl = LRConflict::make(confl_items);
        if (!lr_conflict_cand->contains_key(accs)) {
            lr_conflict_cand->insert(accs, make_rc<Vec<LRConflict_T>>());
        }
        lr_conflict_cand->operator[](accs)->push(confl);
    }

    LOG(3, "lr_conflict_cand:\n{}\n\n", lr_conflict_cand);

    auto lr_conflicts_pre = make_rc<Vec<LRConflict_T>>();

    for (auto [accs, cand] : *lr_conflict_cand) {
        auto len_min = None<Int>();
        auto confl_sel = None<LRConflict_T>();

        for (auto confl : *cand) {
            auto confl_len = lr_conflict_len_total(confl);
            if (len_min.is_none() || confl_len < len_min.as_some()) {
                len_min = Some<Int>(confl_len);
                confl_sel = Some<LRConflict_T>(confl);
            }
        }

        lr_conflicts_pre->push(confl_sel.as_some());
    }

    vector<IntPair> inds;
    for (Int i = 0; i < lr_conflicts_pre->length(); i++) {
        inds.push_back(
            make_pair(lr_conflict_len_total(lr_conflicts_pre->operator[](i)), i));
    }
    std::sort(inds.begin(), inds.end());

    auto lr_conflicts = make_rc<Vec<LRConflict_T>>();

    for (auto [_, ii] : inds) {
        lr_conflicts->push(lr_conflicts_pre->operator[](ii));
    }

    ctx.parser_nfa_final_ = N;
    ctx.parser_dfa_final_ = D;

    return lr_conflicts;
}

}
