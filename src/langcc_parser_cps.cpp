
#include "langcc_common.hpp"

namespace langcc {

void ctx_Gr_cps_init(LangCompileContext &ctx) {
  ctx.Gr_cps_ = Grammar::empty();
  ctx.Gr_cps_prod_constrs_ =
      make_rc<Map<Prod_T, VecUniq_T<ProdConstrFlat_T>>>();
  ctx.cps_prod_map_rev_ = make_rc<Map<Prod_T, Prod_T>>();

  ctx.parser_sym_to_cps_uniq_inds_ = make_rc<Map<Sym_T, Map_T<Sym_T, Int>>>();
  ctx.parser_prod_id_to_cps_uniq_inds_ = make_rc<Map<ProdId_T, Int>>();

  ctx.Gr_cps_lhs_flatten_leaves_ = make_rc<Map<Prod_T, Option_T<AttrLeaf_T>>>();
  ctx.Gr_cps_rhs_flatten_leaves_ =
      make_rc<Map<Prod_T, Vec_T<Option_T<AttrLeaf_T>>>>();
}

void parser_Gr_cps_add_prod(LangCompileContext &ctx, const Sym_T &lhs,
                            const Option_T<AttrLeaf_T> &lhs_leaf,
                            const Vec_T<SymFlattenResultCPS_T> &rhs,
                            const Vec_T<Option_T<AttrLeaf_T>> &rhs_leaves,
                            Prod_T orig_flat) {

  auto [rhs_sym, rhs_unfold] = sym_flatten_result_extract_vec(rhs);

  auto prod_id_flat = orig_flat->prod_id_;
  Int uniq_ind = 0;
  if (!ctx.parser_prod_id_to_cps_uniq_inds_->contains_key(prod_id_flat)) {
    ctx.parser_prod_id_to_cps_uniq_inds_->insert(prod_id_flat, 1);
  } else {
    uniq_ind = ctx.parser_prod_id_to_cps_uniq_inds_->operator[](prod_id_flat);
    ctx.parser_prod_id_to_cps_uniq_inds_->operator[](prod_id_flat) += 1;
  }

  auto prod_id = ProdId::GenCPS::make(prod_id_flat, uniq_ind);

  auto [prod, is_new] =
      Grammar::add_prod(ctx.Gr_cps_, lhs, rhs_sym, prod_id, rhs_unfold);
  AT(is_new);

  ctx.Gr_cps_lhs_flatten_leaves_->insert_strict(prod, lhs_leaf);
  ctx.Gr_cps_rhs_flatten_leaves_->insert_strict(prod, rhs_leaves);

  ctx.cps_prod_map_rev_->insert_strict(prod, orig_flat);
}

bool parser_grammar_sym_triggers_cps(Sym_T sym, LangCompileContext &ctx) {
  if (sym->is_Defined() || sym->is_Start() || sym->is_TermStartMarker() ||
      sym->is_Term()) {
    return false;
  } else if (sym->is_Direct() || sym->is_Iter()) {
    return ctx.cps_triggers_filter_.is_none() ||
           ctx.cps_triggers_filter_.as_some()->contains(sym);
  } else {
    LG_ERR("{}", sym);
    AX();
  }
}

Sym_T parser_grammar_sym_to_cps(const Sym_T &sym,
                                const Vec_T<SymFlattenResultCPS_T> &tail,
                                const Vec_T<Option_T<AttrLeaf_T>> &tail_leaves,
                                LangCompileContext &ctx);

void parser_grammar_prod_to_cps(const Sym_T &lhs_cps, DottedProd_T prod,
                                const Option_T<AttrLeaf_T> &lhs_leaf,
                                Vec_T<SymFlattenResultCPS_T> tail,
                                Vec_T<Option_T<AttrLeaf_T>> tail_leaves,
                                LangCompileContext &ctx) {

  Grammar::add_nonterm(ctx.Gr_cps_, lhs_cps);

  if (prod->dot_ == 0) {
    parser_Gr_cps_add_prod(ctx, lhs_cps, lhs_leaf, tail, tail_leaves,
                           prod->prod_);
    return;
  }

  auto rhs_curr = prod->prod_->rhs_->operator[](prod->dot_ - 1);
  auto unfold_curr = prod->prod_->unfold_mask_->operator[](prod->dot_ - 1);
  auto leaf_curr = None<AttrLeaf_T>();
  if (ctx.Gr_flat_rhs_flatten_leaves_->contains_key(prod->prod_)) {
    leaf_curr = ctx.Gr_flat_rhs_flatten_leaves_->operator[](prod->prod_)
                    ->
                    operator[](prod->dot_ - 1);
  } else {
    AT(prod->prod_->lhs_->is_Start());
  }

  if (!parser_grammar_sym_triggers_cps(rhs_curr, ctx)) {
    auto tail_new = make_rc<Vec<SymFlattenResultCPS_T>>();
    tail_new->push_back(SymFlattenResultCPS::make(rhs_curr, unfold_curr));
    for (const auto &x : *tail) {
      tail_new->push_back(x);
    }

    auto tail_leaves_new = make_rc<Vec<Option_T<AttrLeaf_T>>>();
    tail_leaves_new->push_back(leaf_curr);
    for (const auto &x : *tail_leaves) {
      tail_leaves_new->push_back(x);
    }

    parser_grammar_prod_to_cps(lhs_cps, prod->with_dot(prod->dot_ - 1),
                               lhs_leaf, tail_new, tail_leaves_new, ctx);

  } else if (prod->prod_->lhs_->is_Iter() &&
             prod->dot_ == prod->prod_->rhs_->length() &&
             prod->prod_->rhs_->operator[](prod->prod_->rhs_->length() - 1)
                 ->is_Iter()) {

    auto tail_new = make_rc<Vec<SymFlattenResultCPS_T>>();
    tail_new->push_back(SymFlattenResultCPS::make(lhs_cps, true));
    auto tail_leaves_new = make_rc<Vec<Option_T<AttrLeaf_T>>>();
    tail_leaves_new->push_back(None<AttrLeaf_T>());
    parser_grammar_prod_to_cps(lhs_cps, prod->with_dot(prod->dot_ - 1),
                               lhs_leaf, tail_new, tail_leaves_new, ctx);

  } else {
    auto rhs_cps = parser_grammar_sym_to_cps(rhs_curr, tail, tail_leaves, ctx);
    auto tail_new = make_rc<Vec<SymFlattenResultCPS_T>>();
    tail_new->push_back(SymFlattenResultCPS::make(rhs_cps, true));
    auto tail_leaves_new = make_rc<Vec<Option_T<AttrLeaf_T>>>();
    tail_leaves_new->push_back(None<AttrLeaf_T>());

    parser_grammar_prod_to_cps(lhs_cps, prod->with_dot(prod->dot_ - 1),
                               lhs_leaf, tail_new, tail_leaves_new, ctx);
  }
}

void pr(std::ostream &os, FmtFlags /*flags*/, SymFlattenResultCPS_T x) {
  std::string prefix;
  if (x->unfold_) {
    prefix = "~";
  }
  fmt(os, "{}{}", prefix, x->sym_);
}

Sym_T parser_grammar_sym_to_cps(const Sym_T &sym,
                                const Vec_T<SymFlattenResultCPS_T> &tail,
                                const Vec_T<Option_T<AttrLeaf_T>> &tail_leaves,
                                LangCompileContext &ctx) {

  Sym_T lhs_cps = sym;
  bool hit = false;
  if (parser_grammar_sym_triggers_cps(sym, ctx)) {
    Int uniq_ind = 0;

    lhs_cps = Sym::GenCPS::make(sym, tail, 0);
    if (!ctx.parser_sym_to_cps_uniq_inds_->contains_key(sym)) {
      ctx.parser_sym_to_cps_uniq_inds_->insert(sym, make_rc<Map<Sym_T, Int>>());
      ctx.parser_sym_to_cps_uniq_inds_->operator[](sym)->insert(lhs_cps, 0);
    } else if (ctx.parser_sym_to_cps_uniq_inds_->operator[](sym)->contains_key(
                   lhs_cps)) {
      hit = true;
      uniq_ind = ctx.parser_sym_to_cps_uniq_inds_->operator[](sym)->operator[](
          lhs_cps);
    } else {
      uniq_ind = ctx.parser_sym_to_cps_uniq_inds_->operator[](sym)->length();
      ctx.parser_sym_to_cps_uniq_inds_->operator[](sym)->insert(lhs_cps,
                                                                uniq_ind);
    }
    lhs_cps = Sym::GenCPS::make(sym, tail, uniq_ind);
  }

  if (hit) {
    return lhs_cps;
  }

  for (const auto &prod : *ctx.Gr_flat_->prods_by_nonterm_->operator[](sym)) {
    auto prod_end = DottedProd::make(prod, prod->rhs_->length());
    auto lhs_leaf = ctx.Gr_flat_lhs_flatten_leaves_->operator[](prod);

    parser_grammar_prod_to_cps(lhs_cps, prod_end, lhs_leaf, tail, tail_leaves,
                               ctx);
  }

  return lhs_cps;
}

void parser_grammar_to_cps(LangCompileContext &ctx) {
  for (const auto &sym : *ctx.Gr_flat_->term_) {
    ctx.Gr_cps_->term_->insert_strict(sym);
  }

  for (const auto &sym : *ctx.Gr_flat_->nonterm_) {
    auto sym_triggers = parser_grammar_sym_triggers_cps(sym, ctx);
    if (!sym_triggers) {
      parser_grammar_sym_to_cps(sym, make_rc<Vec<SymFlattenResultCPS_T>>(),
                                make_rc<Vec<Option_T<AttrLeaf_T>>>(), ctx);
    }
  }
}

} // namespace langcc
