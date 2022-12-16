#pragma once

#include "langcc_util.hpp"

#include "common__data_gen.hpp"

#include "meta.hpp"

namespace langcc {

inline void pr(ostream& os, FmtFlags flags, const Grammar_T& G) {
    fmt(os, "===== Grammar =====\n\n");

    Int N = G->nonterm_->length();
    Int T = G->term_->length();
    Int M = G->prods_->length();

    fmt(os, "    Nonterminals:\n\n");
    {
        vector<tuple<Int, Align>> aligns = {{6, Align::RIGHT}, {2, Align::LEFT}};
        auto td = PrintTable::make(aligns);
        for (auto v_sym : *G->nonterm_) {
            td->push_blank_item();
            td->push(fmt_str("{}", v_sym));
        }
        fmt(os, "{}\n", td);
    }

    fmt(os, "    Terminals:\n\n");
    {
        vector<tuple<Int, Align>> aligns = {{6, Align::RIGHT}, {2, Align::LEFT}};
        auto td = PrintTable::make(aligns);
        for (auto v_sym : *G->term_) {
            td->push_blank_item();
            td->push(fmt_str("{}", v_sym));
        }
        fmt(os, "{}\n", td);
    }

    fmt(os, "    Productions:\n\n");
    {
        vector<tuple<Int, Align>> aligns = {
            {6, Align::RIGHT}, {2, Align::RIGHT}, {1, Align::LEFT}, {4, Align::LEFT}};
        auto td = PrintTable::make(aligns);
        for (auto prod : *G->prods_) {
            td->push(fmt_str("{}:", prod->prod_id_));
            td->push(fmt_str("{} ->", str_short(prod->lhs_)));
            string rhs_str = "";
            for (Int j = 0; j < prod->rhs_->length(); j++) {
                if (j > 0) {
                    rhs_str += " ";
                }
                rhs_str += str_short(prod->rhs_->operator[](j));
            }
            td->push(rhs_str);
            td->push_blank_item();
        }
        fmt(os, "{}\n", td);
    }
}


namespace Grammar {
    inline Grammar_T empty() {
        auto ret = make_rc<Grammar::_T>();
        ret->term_ = make_rc<VecUniq<Sym_T>>();
        ret->nonterm_ = make_rc<VecUniq<Sym_T>>();
        ret->start_ = None<Sym_T>();
        ret->prods_ = make_rc<VecUniq<Prod_T>>();
        ret->prods_by_nonterm_ = make_rc<Map<Sym_T, Set_T<Prod_T>>>();
        ret->prods_by_nonterm_rhs_ = make_rc<Map<Sym_T, Set_T<DottedProd_T>>>();
        ret->prods_by_id_ = make_rc<Map<ProdId_T, Prod_T>>();
        return ret;
    }

    inline bool sym_is_term(Sym_T sym) {
        if (sym->is_Term() || sym->is_TermStartMarker()) {
            return true;
        } else if (sym->is_Defined() || sym->is_Direct() ||
            sym->is_GenCPS() || sym->is_Iter() || sym->is_Start()) {
            return false;
        } else {
            AX();
        }
    }

    inline bool sym_is_nonterm(Sym_T sym) {
        return !sym_is_term(sym);
    }

    inline bool sym_is_nonterm_gen(Sym_T sym) {
        if (sym->is_Direct() || sym->is_GenCPS() || sym->is_Iter()) {
            return true;
        } else if (sym->is_Defined() || sym->is_Start()
            || sym->is_Term() || sym->is_TermStartMarker()) {
            return false;
        } else {
            AX();
        }
    }

    inline bool sym_is_cps_eligible(Sym_T sym) {
        if (sym->is_GenCPS()) {
            return false;
        } else if (sym->is_Term() || sym->is_TermStartMarker()) {
            return false;
        } else if (sym->is_Defined() || sym->is_Start()) {
            return false;
        } else if (sym->is_Direct() || sym->is_Iter()) {
            return true;
        } else {
            AX();
        }
    }

    inline void add_term(Grammar_T& G, Sym_T sym) {
        AT(sym_is_term(sym));
        G->term_->insert(sym);
        G->prods_by_nonterm_rhs_->at_create_shared<Set<DottedProd_T>>(sym);
    }

    inline void add_nonterm(Grammar_T& G, Sym_T sym) {
        AT(sym_is_nonterm(sym));
        G->nonterm_->insert(sym);
        G->prods_by_nonterm_rhs_->at_create_shared<Set<DottedProd_T>>(sym);
    }

    inline void check_sym_present(Grammar_T& G, Sym_T sym) {
        AT(G->term_->contains(sym) ^ G->nonterm_->contains(sym));
    }

    inline pair<Prod_T, bool> add_prod(
        Grammar_T& G, Sym_T lhs, Vec_T<Sym_T> rhs, ProdId_T prod_id, Vec_T<bool> unfold_mask) {

        check_sym_present(G, lhs);
        auto prod = Prod::make(lhs, rhs, prod_id, unfold_mask);
        auto is_new = !G->prods_->contains(prod);
        G->prods_->insert(prod);
        G->prods_by_nonterm_->at_create_shared<Set<Prod_T>>(lhs)->insert(prod);
        if (G->prods_by_id_->contains_key(prod_id)) {
            LG_ERR("Already present: {} -> {} (insert: {} -> {})",
                prod_id, G->prods_by_id_->operator[](prod_id),
                prod_id, prod);
        }
        G->prods_by_id_->insert_strict(prod_id, prod);
        for (Int i = 0; i < rhs->length(); i++) {
            G->prods_by_nonterm_rhs_->at_create_shared<Set<DottedProd_T>>(
                rhs->operator[](i))->insert(DottedProd::make(prod, i));
        }
        return make_pair(prod, is_new);
    }
}


inline Int cmp(Sym_T x, Sym_T y, Grammar_T G) {
    auto xn = Grammar::sym_is_term(x);
    auto yn = Grammar::sym_is_term(y);
    if (xn < yn) {
        return -1;
    } else if (xn > yn) {
        return 1;
    }
    if (xn) {
        auto xi = G->term_->index_of_maybe(x).as_some();
        auto yi = G->term_->index_of_maybe(y).as_some();
        return cmp(xi, yi);
    } else {
        auto xi = G->nonterm_->index_of_maybe(x).as_some();
        auto yi = G->nonterm_->index_of_maybe(y).as_some();
        return cmp(xi, yi);
    }
}


inline Int cmp(LRSym_T x, LRSym_T y, Grammar_T G) {
    if (x->w_ < y->w_) {
        return -1;
    }
    if (y->w_ < x->w_) {
        return 1;
    }
    switch (x->w_) {
        case LRSym::_W::Base: {
            auto xc = x->as_Base();
            auto yc = y->as_Base();
            return cmp(xc->sym_, yc->sym_, G);
        }
        case LRSym::_W::RecurStep: {
            auto xc = x->as_RecurStep();
            auto yc = y->as_RecurStep();
            return cmp(xc->sym_, yc->sym_, G);
        }
        case LRSym::_W::EndMarker: {
            return 0;
        }
    }
}


inline Int cmp(SymStr_T x, SymStr_T y, Grammar_T G) {
    Int xn = x->v_->length();
    Int yn = y->v_->length();
    for (Int i = 0; i < min(xn, yn); i++) {
        auto vi = cmp(x->v_->operator[](i), y->v_->operator[](i), G);
        if (vi == -1) {
            return -1;
        } else if (vi == 1) {
            return 1;
        }
    }
    if (xn < yn) {
        return -1;
    }
    if (xn > yn) {
        return 1;
    }
    return 0;
}


inline Int cmp(std::pair<SymStr_T, SymStr_T> x,
    std::pair<SymStr_T, SymStr_T> y, Grammar_T G) {

    auto v = cmp(x.first, y.first, G);
    if (v == -1) {
        return -1;
    } else if (v == 1) {
        return 1;
    } else {
        return cmp(x.second, y.second, G);
    }
}


inline Unit string_set_repr_select(Unit x, Unit y, Grammar_T G) {
    return Unit{};
}


inline SymStr_T string_set_repr_concat(SymStr_T x, SymStr_T y) {
    return sym_str_concat(x, y);
}


inline Int cmp(SymStr_T x, SymStr_T y, Grammar_T G);

inline SymStr_T string_set_repr_select(SymStr_T x, SymStr_T y, Grammar_T G) {
    if (y->v_->length() < x->v_->length()) {
        return y;
    } else if (x->v_->length() < y->v_->length()) {
        return x;
    } else {
        auto v = cmp(x, y, G);
        if (v < 1) {
            return x;
        } else {
            return y;
        }
    }
}


template<typename Repr>
StringSet_T<Repr> string_set_union(StringSet_T<Repr> x, StringSet_T<Repr> y, Grammar_T G) {
    AT(x->k_ == y->k_);
    AT(x->strict_eq_ == y->strict_eq_);
    auto ret = make_rc<Map<SymStr_T, Repr>>();
    for (auto xi : *x->items_) {
        ret->insert(xi.first, xi.second);
    }
    for (auto yi : *y->items_) {
        auto yr = yi.second;
        if (ret->contains_key(yi.first)) {
            auto xr = ret->operator[](yi.first);
            auto zr = string_set_repr_select(xr, yr, G);
            ret->insert(yi.first, zr);
        } else {
            ret->insert(yi.first, yi.second);
        }
    }
    return StringSet::make(ret, x->k_, x->strict_eq_);
}


template<typename Repr>
StringSet_T<Repr> string_set_union_multi(Set_T<StringSet_T<Repr>> xs, Grammar_T G) {
    AT(xs->length() > 0);
    Int k;
    bool strict_eq;
    for (auto x : *xs) {
        k = x->k_;
        strict_eq = x->strict_eq_;
        break;
    }

    auto ret = string_set_empty<Repr>(k, strict_eq);
    for (auto x : *xs) {
        ret = string_set_union(ret, x, G);
    }
    return ret;
}


template<typename Repr>
StringSet_T<Repr> string_set_intersection(
    StringSet_T<Repr> x, StringSet_T<Repr> y, Grammar_T G) {

    AT(x->k_ == y->k_);
    AT(x->strict_eq_ == y->strict_eq_);
    auto ret = make_rc<Map<SymStr_T, Repr>>();
    for (auto xi : *x->items_) {
        if (y->items_->contains_key(xi.first)) {
            auto xr = xi.second;
            auto yr = y->items_->operator[](xi.first);
            auto zr = string_set_repr_select(xr, yr, G);
            ret->insert(xi.first, zr);
        }
    }
    return StringSet::make(ret, x->k_, x->strict_eq_);
}

}
