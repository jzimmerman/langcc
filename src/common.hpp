#pragma once

#include "common__data_gen.hpp"

#include "cc.hpp"
#include "data.hpp"

#include "meta__gen.hpp"

namespace langcc {

using namespace lang;

inline void pr(std::ostream &os, FmtFlags flags, lang::meta::Node_T x) {
  x->write(os, flags);
}

namespace Ident {
inline bool is_base(Ident_T x) { return x->xs_->length() == 1; }

inline Ident_T trunc_to_base(Ident_T x) {
  AT(x->xs_->length() >= 1);
  auto xs_new = make_rc<Vec<IdentBase_T>>();
  xs_new->push_back(x->xs_->operator[](0));
  return Ident::make(xs_new);
}

inline IdentBase_T extract_base(Ident_T x) {
  AT(x->xs_->length() >= 1);
  return x->xs_->operator[](0);
}

inline IdentBase_T extract_base_strict(Ident_T x) {
  AT(is_base(x));
  return extract_base(x);
}

inline Ident_T without_last(Ident_T x) {
  AT(x->xs_->length() >= 1);
  auto xs_new = make_rc<Vec<IdentBase_T>>();
  for (Int i = 0; i < x->xs_->length() - 1; i++) {
    xs_new->push_back(x->xs_->operator[](i));
  }
  return Ident::make(xs_new);
}

inline std::pair<Ident_T, IdentBase_T> split_last(Ident_T x) {
  AT(x->xs_->length() >= 1);
  auto xs_new = make_rc<Vec<IdentBase_T>>();
  for (Int i = 0; i < x->xs_->length() - 1; i++) {
    xs_new->push_back(x->xs_->operator[](i));
  }
  auto ret_proper = Ident::make(xs_new);
  return std::make_pair(ret_proper, x->xs_->operator[](x->xs_->length() - 1));
}

inline IdentBase_T last(Ident_T x) {
  AT(x->xs_->length() >= 1);
  return x->xs_->operator[](x->xs_->length() - 1);
}

inline Ident_T with_sub(Ident_T x, IdentBase_T x_sub) {
  auto xs_new = make_rc<Vec<IdentBase_T>>();
  for (auto xi : *x->xs_) {
    xs_new->push_back(xi);
  }
  xs_new->push_back(x_sub);
  return Ident::make(xs_new);
}

inline Ident_T with_extend(Ident_T x, Ident_T x_sub) {
  auto xs_new = make_rc<Vec<IdentBase_T>>();
  for (auto xi : *x->xs_) {
    xs_new->push_back(xi);
  }
  for (auto xi : *x_sub->xs_) {
    xs_new->push_back(xi);
  }
  return Ident::make(xs_new);
}

inline bool starts_with(Ident_T x, Ident_T prefix) {
  if (x->xs_->length() < prefix->xs_->length()) {
    return false;
  }
  for (Int i = 0; i < prefix->xs_->length(); i++) {
    if (val_hash(x->xs_->operator[](i)) !=
        val_hash(prefix->xs_->operator[](i))) {
      return false;
    }
  }
  return true;
}

inline Ident_T empty() { return Ident::make(make_rc<Vec<IdentBase_T>>()); }
} // namespace Ident

inline Ident_T ident_with_prepend(Ident_T id, IdentBase_T x) {
  auto ret_items = make_rc<Vec<IdentBase_T>>();
  ret_items->push_back(x);
  for (auto y : *id->xs_) {
    ret_items->push_back(y);
  }
  return Ident::make(ret_items);
}

inline Ident_T ident_with_append(Ident_T id, IdentBase_T x) {
  auto ret_items = make_rc<Vec<IdentBase_T>>();
  for (auto y : *id->xs_) {
    ret_items->push_back(y);
  }
  ret_items->push_back(x);
  return Ident::make(ret_items);
}

inline IdentBase_T ident_base_from_string(std::string s) {
  return IdentBase::User::make(s);
}

inline Ident_T ident_singleton_from_string(std::string s) {
  auto xs = make_rc<Vec<IdentBase_T>>();
  xs->push_back(ident_base_from_string(s));
  return Ident::make(xs);
}

inline SymStr_T sym_str_empty() {
  return SymStr::make(make_rc<Vec<LRSym_T>>());
}

template <typename Repr>
StringSet_T<Repr> string_set_empty(Int k, bool strict_eq) {
  auto m = make_rc<Map<SymStr_T, Repr>>();
  return StringSet::make<Repr>(m, k, strict_eq);
}

template <typename Repr>
StringSet_T<Repr> string_set_single(SymStr_T x, Repr v, Int k, bool strict_eq) {
  auto m = make_rc<Map<SymStr_T, Repr>>();
  m->insert_strict(x, v);
  return StringSet::make<Repr>(m, k, strict_eq);
}

inline StringSet_T<SymStr_T> string_set_single_empty(Int k, bool strict_eq) {
  auto eps = sym_str_empty();
  if (strict_eq) {
    AT(k == 0);
  }
  return string_set_single(eps, eps, k, strict_eq);
}

template <typename Repr>
StringSet_T<Unit> string_set_repr_stripped(StringSet_T<Repr> s) {
  auto m = make_rc<Map<SymStr_T, Unit>>();
  for (auto p : *s->items_) {
    m->insert(p.first, Unit{});
  }
  return StringSet::make<Unit>(m, s->k_, s->strict_eq_);
}

inline StringSet_T<Unit> string_set_single_empty_unit(Int k, bool strict_eq) {
  return string_set_repr_stripped(string_set_single_empty(k, strict_eq));
}

template <typename Repr>
SymStr_T string_set_min_len_element(StringSet_T<Repr> x) {
  Option_T<SymStr_T> ret;
  AT(x->items_->length() > 0);
  for (auto xi : *x->items_) {
    if (ret.is_none() || xi.first->v_->length() < ret.as_some()->v_->length()) {
      ret = Some<SymStr_T>(xi.second);
    }
  }
  return ret.as_some();
}

inline void pr(std::ostream &os, FmtFlags flags, IdentBase_T x) {
  if (x->is_User()) {
    pr(os, flags, x->as_User()->name_);
  } else if (x->is_Ordinal()) {
    fmt(os, "_v{}", x->as_Ordinal()->i_);
  } else if (x->is_ItemInner()) {
    fmt(os, "item");
  } else {
    AX();
  }
}

inline void pr(std::ostream &os, FmtFlags flags, Ident_T x) {
  if (x->xs_->length() == 0) {
    os << "<empty_id>";
    return;
  }

  for (Int i = 0; i < x->xs_->length(); i++) {
    if (i > 0) {
      os << ".";
    }
    pr(os, flags, x->xs_->operator[](i));
  }
}

inline void pr(std::ostream &os, FmtFlags flags, GenType_T x) {
  pr_debug(os, flags, x);
}

inline void pr(std::ostream &os, FmtFlags flags, WriteInstr_T x) {
  pr_debug(os, flags, x);
}

inline void pr(std::ostream &os, FmtFlags flags, UnwindInstr_T x) {
  pr_debug(os, flags, x);
}

inline void pr(std::ostream &os, FmtFlags flags, ParseExpr_Base_T x) {
  if (x->src_.is_none()) {
    if (x->tok_->is_Special()) {
      pr_debug(os, flags, x->tok_->as_Special()->w_);
    } else if (x->tok_->is_LitStr()) {
      auto cs = x->tok_->as_LitStr()->cs_;
      AR_eq(cs->length(), 1);
      fmt(os, "{}", char_display(x->tok_->as_LitStr()->cs_->operator[](0)));
    } else {
      AX();
    }
  } else {
    pr(os, flags, x->src_.as_some());
  }
}

inline std::string str_short(Sym_T x) {
  if (x->is_Term()) {
    return fmt_str("{}", x);
  } else if (x->is_Start()) {
    return fmt_str("{}", x);
  } else if (x->is_Defined()) {
    return fmt_str("{}", x);
  } else if (x->is_Direct()) {
    return fmt_str("X{}", x->as_Direct()->gen_id_);
  } else if (x->is_GenCPS()) {
    return fmt_str("@{}:{}", x->as_GenCPS()->uniq_ind_, x->as_GenCPS()->sym_);
  } else if (x->is_TermStartMarker()) {
    return fmt_str("{}", x);
  } else if (x->is_Iter()) {
    return fmt_str("Iter({})", x->as_Iter()->e_);
  } else {
    AX();
  }
}

inline void pr(std::ostream &os, FmtFlags flags, Sym_T x) {
  if (x->is_Term()) {
    fmt(os, "{}", x->as_Term()->tok_);
  } else if (x->is_Start()) {
    fmt(os, "&&");
  } else if (x->is_Defined()) {
    fmt(os, "{}", x->as_Defined()->name_);
  } else if (x->is_Direct()) {
    fmt(os, "X{}=({})", x->as_Direct()->gen_id_, x->as_Direct()->e_);
  } else if (x->is_GenCPS()) {
    fmt(os, "@{}:{}", x->as_GenCPS()->uniq_ind_, x->as_GenCPS()->sym_);
  } else if (x->is_TermStartMarker()) {
    fmt(os, "&{}", x->as_TermStartMarker()->name_);
  } else if (x->is_Iter()) {
    fmt(os, "Iter({})", x->as_Iter()->e_);
  } else {
    AX();
  }
}

inline void pr(std::ostream &os, FmtFlags flags, ProdId_T x) {
  if (x->is_Start()) {
    fmt(os, "ProdId(&&.{})", x->as_Start()->sym_);
  } else if (x->is_Explicit()) {
    fmt(os, "ProdId({}.{})", x->as_Explicit()->rule_ind_,
        x->as_Explicit()->sub_);
  } else if (x->is_GenCPS()) {
    auto cc = x->as_GenCPS();
    if (cc->uniq_ind_ == 0) {
      fmt(os, "{}", cc->orig_);
    } else {
      fmt(os, "@{}:{}", cc->uniq_ind_, cc->orig_);
    }
  } else {
    AX();
  }
}

inline void pr(std::ostream &os, FmtFlags flags, Prod_T prod) {
  std::string ret = fmt_str("{} -> ", str_short(prod->lhs_));
  if (prod->rhs_->length() == 0) {
    ret += "eps";
    fmt(os, "{}", ret);
    return;
  }
  for (Int j = 0; j < prod->rhs_->length(); j++) {
    if (j > 0) {
      ret += " ";
    }
    ret += str_short(prod->rhs_->operator[](j));
  }
  fmt(os, "{}", ret);
}

inline void pr(std::ostream &os, FmtFlags flags, DottedProd_T prod) {
  std::string ret = fmt_str("{} -> ", str_short(prod->prod_->lhs_));
  for (Int j = 0; j < prod->prod_->rhs_->length(); j++) {
    if (j > 0) {
      ret += " ";
    }
    if (prod->dot_ == j) {
      ret += ". ";
    }
    ret += str_short(prod->prod_->rhs_->operator[](j));
  }
  if (prod->dot_ == prod->prod_->rhs_->length()) {
    if (prod->prod_->rhs_->length() > 0) {
      ret += " ";
    }
    ret += ".";
  }
  fmt(os, "{}", ret);
}

inline void pr(std::ostream &os, FmtFlags flags, AttrKey_T x) {
  std::string suffix = "";
  if (x->loc_.is_some()) {
    auto loc = x->loc_.as_some();
    if (loc == ProdConstrRhsLoc::All) {
      suffix = "_A";
    } else if (loc == ProdConstrRhsLoc::Begin) {
      suffix = "_B";
    } else if (loc == ProdConstrRhsLoc::NBegin) {
      suffix = "_NB";
    } else if (loc == ProdConstrRhsLoc::Mid) {
      suffix = "_M";
    } else if (loc == ProdConstrRhsLoc::End) {
      suffix = "_E";
    } else if (loc == ProdConstrRhsLoc::NEnd) {
      suffix = "_NE";
    } else {
      AX();
    }
  }

  if (x->is_Id()) {
    fmt(os, "{}{}", x->as_Id()->name_, suffix);
  } else if (x->is_Prec()) {
    if (x->as_Prec()->dir_ == PrecDir::Left) {
      fmt(os, "prL{}", suffix);
    } else {
      fmt(os, "prR{}", suffix);
    }
  } else {
    AX();
  }
}

inline void pr(std::ostream &os, FmtFlags flags, AttrType_T x) {
  if (x->is_Bool()) {
    fmt(os, "bool");
  } else if (x->is_Range()) {
    fmt(os, "range({})", x->as_Range()->n_);
  } else {
    AX();
  }
}

inline void pr(std::ostream &os, FmtFlags flags, ProdConstrRhsLoc loc) {
  if (loc == ProdConstrRhsLoc::All) {
    fmt(os, "rhs");
  } else if (loc == ProdConstrRhsLoc::Begin) {
    fmt(os, "rhs_begin");
  } else if (loc == ProdConstrRhsLoc::End) {
    fmt(os, "rhs_end");
  } else if (loc == ProdConstrRhsLoc::Mid) {
    fmt(os, "rhs_mid");
  } else {
    AX();
  }
}

inline void pr(std::ostream &os, FmtFlags flags, ProdConstr_T ce) {
  if (ce->is_LhsLeq()) {
    if (ce->as_LhsLeq()->v_->is_Bool()) {
      fmt(os, "!lhs[{}]", ce->as_LhsLeq()->k_);
    } else if (ce->as_LhsLeq()->v_->is_Int_()) {
      fmt(os, "lhs[{}] <= {}", ce->as_LhsLeq()->k_, ce->as_LhsLeq()->v_);
    } else {
      AX();
    }
  } else if (ce->is_Implies()) {
    if (ce->as_Implies()->kl_->is_Id()) {
      fmt(os, "lhs[{}] -> {}[{}]", ce->as_Implies()->kl_,
          ce->as_Implies()->loc_, ce->as_Implies()->kr_);
    } else if (ce->as_Implies()->kl_->is_Prec()) {
      fmt(os, "lhs[{}] <= {}[{}]", ce->as_Implies()->kl_,
          ce->as_Implies()->loc_, ce->as_Implies()->kr_);
    } else {
      AX();
    }
  } else if (ce->is_RhsGeq()) {
    if (ce->as_RhsGeq()->v_->is_Bool()) {
      fmt(os, "{}[{}]", ce->as_RhsGeq()->loc_, ce->as_RhsGeq()->k_);
    } else if (ce->as_RhsGeq()->v_->is_Int_()) {
      fmt(os, "{}[{}] >= {}", ce->as_RhsGeq()->loc_, ce->as_RhsGeq()->k_,
          ce->as_RhsGeq()->v_);
    } else {
      AX();
    }
  } else {
    AX();
  }
}

inline void pr(std::ostream &os, FmtFlags flags, ProdConstrFlat_T ce) {
  if (ce->is_LhsLeq()) {
    if (ce->as_LhsLeq()->v_->is_Bool()) {
      fmt(os, "!lhs[{}]", ce->as_LhsLeq()->k_);
    } else if (ce->as_LhsLeq()->v_->is_Int_()) {
      fmt(os, "lhs[{}] <= {}", ce->as_LhsLeq()->k_, ce->as_LhsLeq()->v_);
    } else {
      AX();
    }
  } else if (ce->is_Implies()) {
    if (ce->as_Implies()->kl_->is_Id()) {
      fmt(os, "lhs[{}] -> rhs.{}[{}]", ce->as_Implies()->kl_,
          ce->as_Implies()->i_, ce->as_Implies()->kr_);
    } else if (ce->as_Implies()->kl_->is_Prec()) {
      fmt(os, "lhs[{}] <= rhs.{}[{}]", ce->as_Implies()->kl_,
          ce->as_Implies()->i_, ce->as_Implies()->kr_);
    } else {
      AX();
    }
  } else if (ce->is_RhsGeq()) {
    if (ce->as_RhsGeq()->v_->is_Bool()) {
      fmt(os, "rhs.{}[{}]", ce->as_RhsGeq()->i_, ce->as_RhsGeq()->k_);
    } else if (ce->as_RhsGeq()->v_->is_Int_()) {
      fmt(os, "rhs.{}[{}] >= {}", ce->as_RhsGeq()->i_, ce->as_RhsGeq()->k_,
          ce->as_RhsGeq()->v_);
    } else {
      AX();
    }
  } else {
    AX();
  }
}

inline void pr(std::ostream &os, FmtFlags flags, LRSym_T x) {
  if (x->is_Base()) {
    fmt(os, "{}", x->as_Base()->sym_);
  } else if (x->is_EndMarker()) {
    fmt(os, "$$");
  } else if (x->is_RecurStep()) {
    fmt(os, "RecurStep({})", x->as_RecurStep()->sym_);
  } else {
    AX();
  }
}

inline void pr(std::ostream &os, FmtFlags flags, SymStr_T x) {
  if (x->v_->length() == 0) {
    fmt(os, "eps");
    return;
  }

  bool fresh = true;
  for (auto xi : *x->v_) {
    if (!fresh) {
      fmt(os, " ");
    }
    fmt(os, "{}", xi);
    fresh = false;
  }
}

inline void pr(std::ostream &os, FmtFlags flags, StringSet_T<SymStr_T> x) {
  fmt(os, "{{");
  bool fresh = true;
  for (auto si : *x->items_) {
    if (!fresh) {
      fmt(os, ", ");
    }
    fmt(os, "{}", si);
    fresh = false;
  }
  fmt(os, "}}");
}

inline void pr(std::ostream &os, FmtFlags flags, StringSet_T<Unit> x) {
  fmt(os, "{{");
  bool fresh = true;
  for (auto si : *x->items_) {
    if (!fresh) {
      fmt(os, ", ");
    }
    fmt(os, "{}", si.first);
    fresh = false;
  }
  fmt(os, "}}");
}

inline void pr(std::ostream &os, FmtFlags flags, LRLabel_T x) {
  if (x->is_Eps()) {
    fmt(os, "eps");
  } else if (x->is_Sym_()) {
    std::string attr_str = "";
    if (x->as_Sym_()->attr_->m_->length() > 0) {
      attr_str = fmt_str("[{}]", x->as_Sym_()->attr_);
    }
    fmt(os, "{}{}", x->as_Sym_()->sym_, attr_str);
  } else {
    AX();
  }
}

inline void pr(std::ostream &os, FmtFlags flags, LRAction_T x) {
  if (x->is_Shift()) {
    fmt(os, "Shift");
  } else if (x->is_Reduce()) {
    fmt(os, "Reduce({})", x->as_Reduce()->prod_);
  } else if (x->is_Ret()) {
    fmt(os, "Ret({})", x->as_Ret()->sym_);
  } else if (x->is_Recur()) {
    fmt(os, "Recur({})", x->as_Recur()->sym_);
  } else {
    AX();
  }
}

inline void pr(std::ostream &os, FmtFlags flags, LRLookAction_T x) {
  fmt(os, "{} -> {}", x->la_, x->acc_);
}

inline void pr(std::ostream &os, FmtFlags flags, LRVertex_T x) {
  auto la_str = fmt_str(" :: {}", x->la_);
  if (x->la_->k_ == 0) {
    la_str = "";
  }

  auto bounds_str = fmt_str(" | {}", x->bounds_);
  if (x->bounds_->m_->length() == 0) {
    bounds_str = "";
  }

  if (x->is_RecStart()) {
    fmt(os, "[ #R -> . {}{}{} ]", x->as_RecStart()->sym_, bounds_str, la_str);
  } else if (x->is_RecEnd()) {
    fmt(os, "[ #R -> {} .{}{} ]", x->as_RecEnd()->sym_, bounds_str, la_str);
  } else if (x->is_Prod()) {
    fmt(os, "[ {}{}{} ]", x->as_Prod()->prod_, bounds_str, la_str);
  } else {
    AX();
  }
}

inline void pr(std::ostream &os, FmtFlags flags, AttrVal_T x) {
  if (x->is_Bool()) {
    fmt(os, "{}", static_cast<Int>(x->as_Bool()->v_));
  } else if (x->is_Int_()) {
    fmt(os, "{}", x->as_Int_()->v_);
  } else {
    AX();
  }
}

inline void pr(std::ostream &os, FmtFlags flags, AttrSet_T x) {
  bool fresh = true;
  for (auto xi : *x->m_) {
    if (!fresh) {
      fmt(os, ",");
    }
    fmt(os, "{}={}", xi.first, xi.second);
    fresh = false;
  }
}

inline void pr(std::ostream &os, FmtFlags flags, AttrBoundSet_T x) {
  bool fresh = true;
  for (auto xi : *x->m_) {
    if (!fresh) {
      fmt(os, ",");
    }
    fmt(os, "{}>={}", xi.first, xi.second->lo_);
    fresh = false;
  }
}

inline void pr(std::ostream &os, FmtFlags flags, LangCompileResult::Error_T x) {
  if (x->is_LRConf()) {
    Int conf_i = 0;
    for (auto conf : *x->as_LRConf()->conflict_) {
      fmt(os, " ===== LR conflict {} of {}\n\n{}\n\n", conf_i + 1,
          x->as_LRConf()->conflict_->length(), conf);
      ++conf_i;
    }
  } else if (x->is_SymUnreach()) {
    fmt(os, " ===== Unreachable symbols (add `prop {{ allow_unreach; }}` to "
            "parser stanza to override):\n");
    for (auto sym : *x->as_SymUnreach()->syms_) {
      fmt(os, "  - {}\n", sym);
    }
  } else if (x->is_LexUnreach()) {
    fmt(os, " ===== Unreachable symbols (add `prop {{ allow_unreach; }}` to "
            "parser stanza to override):\n");
    for (auto id : *x->as_LexUnreach()->ids_) {
      fmt(os, "  - {}\n", id);
    }
  } else if (x->is_Other()) {
    fmt(os, "Lang compilation error: {}", x->as_Other()->desc_);
  } else {
    AX();
  }
}

inline void pr(std::ostream &os, FmtFlags flags, SwitchTable_T x) {
  pr_debug(os, flags, x);
}

inline Option_T<LRSym_T> lr_label_get_sym_maybe(LRLabel_T lbl) {
  if (lbl->is_Sym_()) {
    return Some<LRSym_T>(lbl->as_Sym_()->sym_);
  } else {
    return None<LRSym_T>();
  }
}

inline Option_T<AttrSet_T> lr_label_get_attr_maybe(LRLabel_T lbl) {
  if (lbl->is_Sym_()) {
    return Some<AttrSet_T>(lbl->as_Sym_()->attr_);
  } else {
    return None<AttrSet_T>();
  }
}

inline Int attr_val_to_int(AttrVal_T x) {
  if (x->is_Bool()) {
    return static_cast<Int>(x->as_Bool()->v_);
  } else if (x->is_Int_()) {
    return x->as_Int_()->v_;
  } else {
    AX();
  }
}

inline Int attr_type_val_max(AttrType_T x) {
  if (x->is_Bool()) {
    return 1;
  } else if (x->is_Range()) {
    return x->as_Range()->n_ - 1;
  } else {
    AX();
  }
}

inline bool dotted_prod_is_start(DottedProd_T dp) { return dp->dot_ == 0; }

inline bool dotted_prod_is_end(DottedProd_T dp) {
  return dp->dot_ == dp->prod_->rhs_->length();
}

inline DottedProd_T dotted_prod_with_step(DottedProd_T dp) {
  AT(!dotted_prod_is_end(dp));
  return DottedProd::make(dp->prod_, dp->dot_ + 1);
}

inline Sym_T dotted_prod_cursor(DottedProd_T dp) {
  AT(!dotted_prod_is_end(dp));
  return dp->prod_->rhs_->operator[](dp->dot_);
}

inline LRVertex_T lr_vertex_without_lookahead(LRVertex_T v) {
  auto la_trivial = string_set_single_empty_unit(0, true);

  if (v->is_Prod()) {
    return LRVertex::Prod::make(v->as_Prod()->bounds_, la_trivial,
                                v->as_Prod()->prod_, v->as_Prod()->left_rec_);
  } else if (v->is_RecStart()) {
    return LRVertex::RecStart::make(v->as_RecStart()->bounds_, la_trivial,
                                    v->as_RecStart()->sym_);
  } else if (v->is_RecEnd()) {
    return LRVertex::RecEnd::make(v->as_RecEnd()->bounds_, la_trivial,
                                  v->as_RecEnd()->sym_);
  } else {
    AX();
  }
}

inline Sym_T lr_vertex_cursor(LRVertex_T v) {
  if (v->is_Prod()) {
    return dotted_prod_cursor(v->as_Prod()->prod_);
  } else if (v->is_RecStart()) {
    return v->as_RecStart()->sym_;
  } else {
    AX();
  }
}

inline void pr(std::ostream &os, FmtFlags flags, LRStringExemplar_T x) {
  fmt(os, "{}=[{}]", LRLabel::Sym_::make(x->sym_, x->attr_), x->contents_);
}

inline void pr(std::ostream &os, FmtFlags flags, LRStringExemplarBounded_T x) {
  fmt(os, "{}[{}]", x->sym_, x->bounds_);
}

inline void pr(std::ostream &os, FmtFlags flags, LRStringExemplarBidir_T x) {
  pr(os, flags, x->pre_);
  os << " . ";
  pr(os, flags, x->post_);
}

void pr(std::ostream &os, FmtFlags flags, LRConflict_T conf);

inline SymStr_T sym_str_trunc(SymStr_T s, Int k) {
  auto v = make_rc<Vec<LRSym_T>>();
  for (Int i = 0; i < std::min(k, s->v_->length()); i++) {
    v->push_back(s->v_->operator[](i));
  }
  return SymStr::make(v);
}

inline SymStr_T sym_str_concat(SymStr_T x, SymStr_T y) {
  auto v = make_rc<Vec<LRSym_T>>();
  for (auto xi : *x->v_) {
    v->push_back(xi);
  }
  for (auto yi : *y->v_) {
    v->push_back(yi);
  }
  return SymStr::make(v);
}

inline Unit string_set_repr_concat(Unit x, Unit y) { return Unit{}; }

inline Unit string_set_repr_select(Unit x, Unit y) { return Unit{}; }

inline SymStr_T string_set_repr_concat(SymStr_T x, SymStr_T y) {
  return sym_str_concat(x, y);
}

inline SymStr_T string_set_repr_select(SymStr_T x, SymStr_T y) {
  if (y->v_->length() < x->v_->length()) {
    return y;
  } else {
    return x;
  }
}

template <typename Repr>
StringSet_T<Repr> string_set_union(StringSet_T<Repr> x, StringSet_T<Repr> y) {
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
      auto zr = string_set_repr_select(xr, yr);
      ret->insert(yi.first, zr);
    } else {
      ret->insert(yi.first, yi.second);
    }
  }
  return StringSet::make(ret, x->k_, x->strict_eq_);
}

template <typename Repr>
StringSet_T<Repr> string_set_union_multi(Set_T<StringSet_T<Repr>> xs) {
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
    ret = string_set_union(ret, x);
  }
  return ret;
}

template <typename Repr>
StringSet_T<Repr> string_set_intersection(StringSet_T<Repr> x,
                                          StringSet_T<Repr> y) {
  AT(x->k_ == y->k_);
  AT(x->strict_eq_ == y->strict_eq_);
  auto ret = make_rc<Map<SymStr_T, Repr>>();
  for (auto xi : *x->items_) {
    if (y->items_->contains_key(xi.first)) {
      auto xr = xi.second;
      auto yr = y->items_->operator[](xi.first);
      auto zr = string_set_repr_select(xr, yr);
      ret->insert(xi.first, zr);
    }
  }
  return StringSet::make(ret, x->k_, x->strict_eq_);
}

inline RhsPos_T parser_rhs_pos_with_update(RhsPos_T rhs_pos, Int i, Int n) {
  auto ret = RhsPos::make(rhs_pos->begin_, rhs_pos->end_);
  if (i > 0) {
    ret->begin_ = false;
  }
  if (i < n - 1) {
    ret->end_ = false;
  }
  return ret;
}

inline bool parser_rhs_pos_matches_loc(RhsPos_T rhs_pos, ProdConstrRhsLoc loc) {
  if (loc == ProdConstrRhsLoc::All) {
    return true;
  } else if (loc == ProdConstrRhsLoc::Begin) {
    return rhs_pos->begin_;
  } else if (loc == ProdConstrRhsLoc::End) {
    return rhs_pos->end_;
  } else if (loc == ProdConstrRhsLoc::Mid) {
    return !rhs_pos->begin_ && !rhs_pos->end_;
  } else {
    AX();
  }
}

inline AttrVal_T attr_val_max(AttrType_T attr_ty) {
  if (attr_ty->is_Bool()) {
    return AttrVal::Bool::make(attr_ty, true);
  } else if (attr_ty->is_Range()) {
    return AttrVal::Int_::make(attr_ty, attr_ty->as_Range()->n_ - 1);
  } else {
    AX();
  }
}

inline AttrVal_T attr_val_minimum(AttrVal_T x, AttrVal_T y) {
  AT(val_hash(x->ty_) == val_hash(y->ty_));

  if (x->is_Bool()) {
    return AttrVal::Bool::make(x->ty_, x->as_Bool()->v_ && y->as_Bool()->v_);
  } else if (x->is_Int_()) {
    auto vx = x->as_Int_()->v_;
    auto vy = y->as_Int_()->v_;
    return AttrVal::Int_::make(x->ty_, std::min(vx, vy));
  } else {
    AX();
  }
}

inline AttrVal_T attr_val_maximum(AttrVal_T x, AttrVal_T y) {
  AT(val_hash(x->ty_) == val_hash(y->ty_));

  if (x->is_Bool()) {
    return AttrVal::Bool::make(x->ty_, x->as_Bool()->v_ || y->as_Bool()->v_);
  } else if (x->is_Int_()) {
    auto vx = x->as_Int_()->v_;
    auto vy = y->as_Int_()->v_;
    return AttrVal::Int_::make(x->ty_, std::max(vx, vy));
  } else {
    AX();
  }
}

inline bool attr_val_less_than(AttrVal_T x, AttrVal_T y) {
  if (val_hash(x->ty_) != val_hash(y->ty_)) {
    LG_ERR("Type mismatch: {} != {}", x->ty_, y->ty_);
    AX();
  }

  if (x->is_Bool()) {
    return !x->as_Bool()->v_ && y->as_Bool()->v_;
  } else if (x->is_Int_()) {
    auto vx = x->as_Int_()->v_;
    auto vy = y->as_Int_()->v_;
    return vx < vy;
  } else {
    AX();
  }
}

inline AttrSet_T attr_set_empty() {
  return AttrSet::make(make_rc<Map<AttrKey_T, AttrVal_T>>());
}

inline AttrBoundSet_T attr_bound_set_empty() {
  auto ret = make_rc<Map<AttrKey_T, AttrBound_T>>();
  return AttrBoundSet::make(ret);
}

inline bool attr_set_meets_bounds(AttrSet_T s, AttrBoundSet_T bounds) {
  for (auto p : *bounds->m_) {
    if (!(s->m_->contains_key(p.first))) {
      LG_ERR("Not found: {}\nmap: {}\n", p.first, s->m_);
      AX();
    }
    if (attr_val_less_than(s->m_->operator[](p.first), p.second->lo_)) {
      return false;
    }
  }
  return true;
}

inline bool attr_set_meets_bounds_relaxed(AttrSet_T s, AttrBoundSet_T bounds) {
  for (auto p : *bounds->m_) {
    if (!(s->m_->contains_key(p.first))) {
      continue;
    }
    if (attr_val_less_than(s->m_->operator[](p.first), p.second->lo_)) {
      return false;
    }
  }
  return true;
}

using GrammarProdConstrs_T = Map_T<Prod_T, VecUniq_T<ProdConstrFlat_T>>;

using GrammarSymConstrGen_T =
    Map_T<Sym_T, Map_T<AttrSet_T, StringSet_T<SymStr_T>>>;
using GrammarProdConstrGen_T =
    Map_T<DottedProd_T, Map_T<AttrSet_T, StringSet_T<SymStr_T>>>;

inline std::string data_gen_id_base_to_string(IdentBase_T x) {
  if (x->is_User()) {
    return x->as_User()->name_;
  } else if (x->is_ItemInner()) {
    return "item";
  } else if (x->is_Ordinal()) {
    return fmt_str("_v{}", x->as_Ordinal()->i_);
  } else {
    AX();
  }
}

inline data::Node_T data_gen_id_string_to_node(DataGenContext data,
                                               std::string name) {
  auto ret_items = make_rc<Vec<std::string>>();
  ret_items->push_back(name);
  return data.Q_->qq_ext(Some<std::string>("Id"), *ret_items);
}

inline data::Node_T data_gen_id_to_node(DataGenContext data, Ident_T id) {
  auto ret_items = make_rc<Vec<std::string>>();
  bool fresh = true;
  for (auto x : *id->xs_) {
    if (!fresh) {
      ret_items->push_back("::");
    }
    fresh = false;
    ret_items->push_back(data_gen_id_base_to_string(x));
  }
  return data.Q_->qq_ext(Some<std::string>("Id"), *ret_items);
}

inline data::Node_T data_gen_sum_id_to_node(DataGenContext data, Ident_T id) {
  auto ret_items = make_rc<Vec<std::string>>();
  bool fresh = true;
  for (auto x : *id->xs_) {
    if (!fresh) {
      ret_items->push_back(".");
    }
    fresh = false;
    ret_items->push_back(data_gen_id_base_to_string(x));
  }
  return data.Q_->qq_ext(Some<std::string>("SumId"), *ret_items);
}

inline LangCompileResult::Error_T
lang_compile_error(LangCompileResult::Error_T err) {
  return err;
}

} // namespace langcc
