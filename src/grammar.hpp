#pragma once

#include "langcc_util.hpp"

#include "common__data_gen.hpp"

#include "meta.hpp"

namespace langcc {

inline void pr(std::ostream &os, FmtFlags flags, const Grammar_T &G) {
  fmt(os, "===== Grammar =====\n\n");

  Int N = G->nonterm_->length();
  Int T = G->term_->length();
  Int M = G->prods_->length();

  fmt(os, "    Nonterminals:\n\n");
  {
    std::vector<std::tuple<Int, Align>> aligns = {{6, Align::RIGHT},
                                                  {2, Align::LEFT}};
    auto td = PrintTable::make(aligns);
    for (const auto &v_sym : *G->nonterm_) {
      td->push_blank_item();
      td->push(fmt_str("{}", v_sym));
    }
    fmt(os, "{}\n", td);
  }

  fmt(os, "    Terminals:\n\n");
  {
    std::vector<std::tuple<Int, Align>> aligns = {{6, Align::RIGHT},
                                                  {2, Align::LEFT}};
    auto td = PrintTable::make(aligns);
    for (const auto &v_sym : *G->term_) {
      td->push_blank_item();
      td->push(fmt_str("{}", v_sym));
    }
    fmt(os, "{}\n", td);
  }

  fmt(os, "    Productions:\n\n");
  {
    std::vector<std::tuple<Int, Align>> aligns = {{6, Align::RIGHT},
                                                  {2, Align::RIGHT},
                                                  {1, Align::LEFT},
                                                  {4, Align::LEFT}};
    auto td = PrintTable::make(aligns);
    for (auto prod : *G->prods_) {
      td->push(fmt_str("{}:", prod->prod_id_));
      td->push(fmt_str("{} ->", str_short(prod->lhs_)));
      std::string rhs_str;
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
  } else if (sym->is_Defined() || sym->is_Direct() || sym->is_GenCPS() ||
             sym->is_Iter() || sym->is_Start()) {
    return false;
  } else {
    AX();
  }
}

inline bool sym_is_nonterm(const Sym_T &sym) { return !sym_is_term(sym); }

inline bool sym_is_nonterm_gen(Sym_T sym) {
  if (sym->is_Direct() || sym->is_GenCPS() || sym->is_Iter()) {
    return true;
  } else if (sym->is_Defined() || sym->is_Start() || sym->is_Term() ||
             sym->is_TermStartMarker()) {
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

inline void add_term(Grammar_T &G, const Sym_T &sym) {
  AT(sym_is_term(sym));
  G->term_->insert(sym);
  G->prods_by_nonterm_rhs_->at_create_shared<Set<DottedProd_T>>(sym);
}

inline void add_nonterm(Grammar_T &G, const Sym_T &sym) {
  AT(sym_is_nonterm(sym));
  G->nonterm_->insert(sym);
  G->prods_by_nonterm_rhs_->at_create_shared<Set<DottedProd_T>>(sym);
}

inline void check_sym_present(Grammar_T &G, const Sym_T &sym) {
  AT(G->term_->contains(sym) ^ G->nonterm_->contains(sym));
}

inline std::pair<Prod_T, bool> add_prod(Grammar_T &G, const Sym_T &lhs,
                                        Vec_T<Sym_T> rhs,
                                        const ProdId_T &prod_id,
                                        const Vec_T<bool> &unfold_mask) {

  check_sym_present(G, lhs);
  auto prod = Prod::make(lhs, rhs, prod_id, unfold_mask);
  auto is_new = !G->prods_->contains(prod);
  G->prods_->insert(prod);
  G->prods_by_nonterm_->at_create_shared<Set<Prod_T>>(lhs)->insert(prod);
  if (G->prods_by_id_->contains_key(prod_id)) {
    LG_ERR("Already present: {} -> {} (insert: {} -> {})", prod_id,
           G->prods_by_id_->operator[](prod_id), prod_id, prod);
  }
  G->prods_by_id_->insert_strict(prod_id, prod);
  for (Int i = 0; i < rhs->length(); i++) {
    G->prods_by_nonterm_rhs_
        ->at_create_shared<Set<DottedProd_T>>(rhs->operator[](i))
        ->insert(DottedProd::make(prod, i));
  }
  return std::make_pair(prod, is_new);
}
} // namespace Grammar

} // namespace langcc
