#include "langcc_common.hpp"

#include "nfa.hpp"

namespace langcc {

Int trunc_u16_s2u(Int x) {
  AT(x < 0x7fff); // Leave one for sentinel
  AT(x > -0x7fff);
  return static_cast<u16>(x & 0xffff);
}

pair<Int, Int> trunc_u16_s2u_x2(Int x) {
  AT(x < 0x7fffffffL); // Leave one for sentinel
  AT(x > -0x7fffffffL);
  return std::make_pair(static_cast<u16>(x & 0xffff),
                        static_cast<u16>((x >> 16) & 0xffff));
}

void switch_table_encode_acc_u16(Vec_T<Int> &dst, SwitchTable_T &tt) {
  if (tt->is_Base()) {
    dst->push_back(trunc_u16_s2u(0));
    auto cc = tt->as_Base();
    for (auto x : *cc->v_) {
      dst->push_back(trunc_u16_s2u(x));
    }
  } else if (tt->is_IterList()) {
    auto cc = tt->as_IterList();
    dst->push_back(trunc_u16_s2u(1));
    dst->push_back(trunc_u16_s2u(cc->id_));
    dst->push_back(trunc_u16_s2u(cc->cases_->length()));
    auto dst_subs = make_rc<Vec<Vec_T<Int>>>();
    Int offset = 2 * cc->cases_->length() + 1;
    for (auto entry : *cc->cases_) {
      dst->push_back(trunc_u16_s2u(entry->case_val_));
    }
    for (auto entry : *cc->cases_) {
      auto dst_sub = make_rc<Vec<Int>>();
      switch_table_encode_acc_u16(dst_sub, entry->case__);
      dst_subs->push_back(dst_sub);
      auto dst_sub_len = dst_sub->length();
      dst->push_back(trunc_u16_s2u(offset));
      offset += dst_sub_len;
    }
    auto dst_default = make_rc<Vec<Int>>();
    switch_table_encode_acc_u16(dst_default, cc->default__);
    dst_subs->push_back(dst_default);
    auto dst_default_len = dst_default->length();
    dst->push_back(trunc_u16_s2u(offset));
    for (auto dst_sub : *dst_subs) {
      for (auto n : *dst_sub) {
        dst->push_back(n);
      }
    }
  } else if (tt->is_IterMat()) {
    auto cc = tt->as_IterMat();
    dst->push_back(trunc_u16_s2u(2));
    dst->push_back(trunc_u16_s2u(cc->id_));
    dst->push_back(trunc_u16_s2u(cc->cases_->length()));
    auto dst_subs = make_rc<Vec<Vec_T<Int>>>();
    Int offset = cc->cases_->length() * 2;
    Int i = 0;
    while (i < cc->cases_->length()) {
      auto dst_sub = make_rc<Vec<Int>>();
      switch_table_encode_acc_u16(dst_sub, cc->cases_->operator[](i));
      dst_subs->push(dst_sub);
      Int dst_sub_len = dst_sub->length();
      auto [off_p, off_q] = trunc_u16_s2u_x2(offset);
      dst->push(off_p);
      dst->push(off_q);
      offset += dst_sub_len;
      ++i;
    }
    for (auto dst_sub : *dst_subs) {
      for (Int n : *dst_sub) {
        dst->push(n);
      }
    }
  } else {
    AX();
  }
}

Vec_T<Int> switch_table_encode_u16(SwitchTable_T &tt) {
  auto ret = make_rc<Vec<Int>>();
  switch_table_encode_acc_u16(ret, tt);
  return ret;
}

VecUniq_T<LRSym_T> grammar_all_lr_syms(Grammar_T G) {
  auto ret = make_rc<VecUniq<LRSym_T>>();
  ret->insert(LRSym::EndMarker::make());
  // NOTE: EndMarker must be index 0 (used, e.g., in LexOutput::first_k)
  ret->insert(LRSym::Base::make(Sym::Start::make()));
  for (auto sym : *G->term_) {
    ret->insert(LRSym::Base::make(sym));
  }
  for (auto sym : *G->nonterm_) {
    ret->insert(LRSym::Base::make(sym));
  }
  for (auto sym : *G->nonterm_) {
    ret->insert(LRSym::RecurStep::make(sym));
  }
  return ret;
}

Int grammar_sym_to_ind_flat(LangCompileContext &ctx, LRSym_T sym) {
  auto v = grammar_all_lr_syms(ctx.Gr_cps_);
  return v->index_of_maybe(sym).as_some();
}

template <typename K, typename V, typename W>
K table_keys_select_branch(Set_T<K> ks, Map_T<Map_T<K, V>, W> tt) {
  Option_T<K> k_max = None<K>();
  Int n_part_max = 0;

  for (auto k : *ks) {
    auto part_k = make_rc<Set<V>>();
    for (auto [m, _] : *tt) {
      part_k->insert(m->operator[](k));
    }
    if (part_k->length() > n_part_max) {
      n_part_max = part_k->length();
      k_max = Some<K>(k);
    }
  }

  return k_max.as_some();
}

template <typename K, typename V, typename W>
pair<Set_T<K>, Map_T<Map_T<K, V>, W>>
table_keys_minimal_partition(Map_T<Map_T<K, V>, W> table) {

  auto ks = make_rc<Set<K>>();
  for (auto [kvs, w] : *table) {
    for (auto [k, _] : *kvs) {
      ks->insert(k);
    }
  }

  auto ret_curr = ks->clone_rc();
  auto table_curr = table->clone_rc();

  while (true) {
    auto to_prune = None<K>();
    auto table_pruned_outer = None<Map_T<Map_T<K, V>, W>>();

    for (auto ret_i : *ret_curr) {
      bool prune_ok = true;
      auto table_pruned = make_rc<Map<Map_T<K, V>, W>>();

      for (auto [kvs, w] : *table_curr) {
        auto kvs_pruned = kvs->clone_rc();
        kvs_pruned->remove(ret_i);
        if (table_pruned->contains_key(kvs_pruned) &&
            val_hash(table_pruned->operator[](kvs_pruned)) != val_hash(w)) {

          prune_ok = false;
          break;
        }
        table_pruned->insert(kvs_pruned, w);
      }

      if (prune_ok) {
        to_prune = Some<K>(ret_i);
        table_pruned_outer = Some<Map_T<Map_T<K, V>, W>>(table_pruned);
        break;
      }
    }

    if (to_prune.is_none()) {
      return std::make_pair(ret_curr, table_curr);
    } else {
      ret_curr->remove(to_prune.as_some());
      table_curr = table_pruned_outer.as_some()->clone_rc();
    }
  }
}

Int attr_key_to_index(Sym_T sym, AttrKey_T k, LangCompileContext &ctx) {
  auto dom = ctx.parser_attr_domains_->operator[](sym);
  Int i = 0;
  for (auto [ki, _] : *dom) {
    if (val_hash(ki) == val_hash(k)) {
      return i;
    }
    ++i;
  }
  LG_ERR("attr key not found in domain: {}\n{}\n", k, dom);
  AX();
}

SwitchTable_T parser_lr_vertex_dfa_step_impl_table_rec(
    LRSym_T sym, Map_T<Map_T<AttrKey_T, Int>, Int> table,
    LangCompileContext &ctx) {

  auto vr = make_rc<Vec<Int>>();
  vr->push_back(-1);
  auto table_default = SwitchTable::Base::make(vr);

  AT(table->length() > 0);
  if (table->length() == 1) {
    for (auto [k, v] : *table) {
      auto vr = make_rc<Vec<Int>>();
      vr->push_back(v);
      return SwitchTable::Base::make(vr);
    }
  }

  // RecurStep symbols have no attributes, and EndMarker symbols cannot be
  // labels.
  auto sym_base = sym->as_Base()->sym_;

  if (!ctx.parser_attr_domains_->contains_key(sym_base)) {
    LG_ERR("Not found: {}", sym_base);
    AX();
  }

  auto n_attr = ctx.parser_attr_domains_->operator[](sym_base)->length();

  auto table_keys = make_rc<Set<AttrKey_T>>();
  for (auto [kvs, _] : *table) {
    for (auto [k, _] : *kvs) {
      table_keys->insert(k);
    }
    break;
  }
  auto part_key = table_keys_select_branch(table_keys, table);
  auto part_key_ind = attr_key_to_index(sym_base, part_key, ctx);

  auto part_vals = make_rc<Set<Int>>();
  for (auto [kvs, w] : *table) {
    auto v = kvs->operator[](part_key);
    part_vals->insert(v);
  }

  auto tables_sub = make_rc<Vec<SwitchTable_IterListEntry_T>>();

  for (auto part_val : *part_vals) {
    auto table_filtered = make_rc<Map<Map_T<AttrKey_T, Int>, Int>>();
    for (auto [kvs, w] : *table) {
      if (val_hash(kvs->operator[](part_key)) != val_hash(part_val)) {
        continue;
      }
      auto kvs_filtered = kvs->clone_rc();
      kvs_filtered->remove(part_key);
      table_filtered->insert(kvs_filtered, w);
    }

    auto table_sub =
        parser_lr_vertex_dfa_step_impl_table_rec(sym, table_filtered, ctx);
    tables_sub->push_back(SwitchTable_IterListEntry::make(part_val, table_sub));
  }

  return SwitchTable::IterList::make(2 + part_key_ind, tables_sub,
                                     table_default);
}

SwitchTable_T parser_lr_vertex_dfa_step_impl_table(LangCompileContext &ctx,
                                                   LR_DFA_T D) {
  auto vr = make_rc<Vec<Int>>();
  vr->push_back(-1);
  auto table_default = SwitchTable::Base::make(vr);

  Int n = D->G_->V_->length();

  if (n > 32767) {
    AX("LR DFAs larger than 32767 nodes not supported due to encoding "
       "limitations");
  }

  auto tables_sub_v = make_rc<Vec<SwitchTable_T>>();

  for (Int i = 0; i < n; i++) {
    auto vsi = D->G_->V_->operator[](i);
    auto vsi_es = NFA::outgoing_edges(D, vsi);

    auto label_syms = make_rc<Set<LRSym_T>>();
    for (auto [lbl, nbrs] : *vsi_es) {
      label_syms->insert(lr_label_get_sym_maybe(lbl).as_some());
    }

    auto tables_sub_sym = make_rc<Vec<SwitchTable_IterListEntry_T>>();

    for (auto sym : *label_syms) {
      auto sym_ind = grammar_sym_to_ind_flat(ctx, sym);
      auto table = make_rc<Map<Map_T<AttrKey_T, Int>, Int>>();

      auto es = NFA::outgoing_edges(D, vsi);
      for (auto [lbl, nbrs] : *vsi_es) {
        if (val_hash(lr_label_get_sym_maybe(lbl).as_some()) != val_hash(sym)) {
          continue;
        }

        auto nbr = nbrs->only();
        auto nbr_ind = D->G_->V_->index_of_maybe(nbr).as_some();

        auto attr_kvs = make_rc<Map<AttrKey_T, Int>>();

        auto lbl_attr = lr_label_get_attr_maybe(lbl).as_some();
        for (auto [k, v] : *lbl_attr->m_) {
          attr_kvs->insert(k, attr_val_to_int(v));
        }
        table->insert(attr_kvs, nbr_ind);
      }

      auto [ks, table_pruned] =
          table_keys_minimal_partition<AttrKey_T, Int, Int>(table);

      auto table_sub_sym =
          parser_lr_vertex_dfa_step_impl_table_rec(sym, table_pruned, ctx);

      tables_sub_sym->push_back(
          SwitchTable_IterListEntry::make(sym_ind, table_sub_sym));
    }

    auto table_sub_v =
        SwitchTable::IterList::make(1, tables_sub_sym, table_default);
    tables_sub_v->push_back(table_sub_v);
  }

  SwitchTable_T tt = SwitchTable::IterMat::make(0, tables_sub_v);

  return tt;
}

IntPair parser_lr_action_dfa_acc_to_indices(LRAction_T acc,
                                            LangCompileContext &ctx) {
  if (acc->is_Reduce()) {
    auto prod_ind =
        ctx.Gr_cps_->prods_->index_of_maybe(acc->as_Reduce()->prod_).as_some();
    return std::make_pair(static_cast<Int>(ParserActionData_W::REDUCE),
                          prod_ind);
  } else if (acc->is_Recur()) {
    auto sym_ind =
        grammar_sym_to_ind_flat(ctx, LRSym::Base::make(acc->as_Recur()->sym_));
    return std::make_pair(static_cast<Int>(ParserActionData_W::RECUR), sym_ind);
  } else if (acc->is_Ret()) {
    auto sym_ind =
        grammar_sym_to_ind_flat(ctx, LRSym::Base::make(acc->as_Ret()->sym_));
    return std::make_pair(static_cast<Int>(ParserActionData_W::RET), sym_ind);
  } else if (acc->is_Shift()) {
    return std::make_pair(static_cast<Int>(ParserActionData_W::SHIFT), 0);
  } else {
    AX();
  }
}

SwitchTable_T parser_lr_action_by_vertex_impl_table_rec(
    VecUniq_T<std::pair<SymStr_T, LRAction_T>> part_table_filt,
    Option_T<LRAction_T> acc_default, Vec_T<LRSym_T> buf, Int k,
    LangCompileContext &ctx) {

  AR_eq(static_cast<Int>(ParserActionData_W::SHIFT), 4);
  auto [acc_ind_default, arg_ind_default] = IntPair(std::make_pair(4, 0));
  if (acc_default.is_some()) {
    auto p = parser_lr_action_dfa_acc_to_indices(acc_default.as_some(), ctx);
    acc_ind_default = p.first;
    arg_ind_default = p.second;
  } else if (part_table_filt->length() > 0) {
    auto p = parser_lr_action_dfa_acc_to_indices(
        part_table_filt->operator[](0).second, ctx);
    acc_ind_default = p.first;
    arg_ind_default = p.second;
  }

  if (buf->length() == k) {
    if (part_table_filt->length() > 0) {
      AT(part_table_filt->length() == 1);
      for (auto [la, acc] : *part_table_filt) {
        auto [acc_i, arg_i] = parser_lr_action_dfa_acc_to_indices(acc, ctx);
        auto vr = make_rc<Vec<Int>>();
        vr->push_back(acc_i);
        vr->push_back(arg_i);
        return SwitchTable::Base::make(vr);
      }
    } else {
      auto vr = make_rc<Vec<Int>>();
      vr->push_back(acc_ind_default);
      vr->push_back(arg_ind_default);
      return SwitchTable::Base::make(vr);
    }
  }

  Int j = buf->length();

  auto la_syms_by_ind_j =
      make_rc<Map<LRSym_T, VecUniq_T<std::pair<SymStr_T, LRAction_T>>>>();

  for (auto [la, acc] : *part_table_filt) {
    auto la_j = la->v_->operator[](j);
    if (!la_syms_by_ind_j->contains_key(la_j)) {
      la_syms_by_ind_j->insert(
          la_j, make_rc<VecUniq<std::pair<SymStr_T, LRAction_T>>>());
    }
    la_syms_by_ind_j->operator[](la_j)->insert(std::make_pair(la, acc));
  }

  auto tables_sub = make_rc<Vec<SwitchTable_IterListEntry_T>>();

  for (auto [la_j, part_table_filt_sub] : *la_syms_by_ind_j) {
    auto la_j_flat = grammar_sym_to_ind_flat(ctx, la_j);

    auto buf_sub = make_rc<Vec<LRSym_T>>();
    for (auto x : *buf) {
      buf_sub->push_back(x);
    }
    buf_sub->push_back(la_j);

    auto table_sub = parser_lr_action_by_vertex_impl_table_rec(
        part_table_filt_sub, acc_default, buf_sub, k, ctx);
    tables_sub->push_back(
        SwitchTable_IterListEntry::make(la_j_flat, table_sub));
  }

  auto vr = make_rc<Vec<Int>>();
  vr->push_back(acc_ind_default);
  vr->push_back(arg_ind_default);
  return SwitchTable::IterList::make(1 + j, tables_sub,
                                     SwitchTable::Base::make(vr));
}

SwitchTable_T
parser_lr_action_by_vertex_impl_table_basic(LangCompileContext &ctx, LR_DFA_T D,
                                            Int k) {

  Int n = D->G_->V_->length();

  auto tables_sub = make_rc<Vec<SwitchTable_T>>();

  for (Int i = 0; i < n; i++) {
    auto vsi = D->G_->V_->operator[](i);

    auto m = D->acc_->operator[](i);
    auto la_max = None<StringSet_T<Unit>>();
    for (auto ll : *m) {
      if (la_max.is_none() ||
          ll->la_->items_->length() > la_max.as_some()->items_->length()) {
        la_max = Some<StringSet_T<Unit>>(ll->la_);
      }
    }

    Option_T<LRAction_T> acc_default = None<LRAction_T>();
    auto v = make_rc<VecUniq<std::pair<SymStr_T, LRAction_T>>>();
    for (auto ll : *m) {
      if (k <= 1 && la_max.is_some() &&
          val_hash(ll->la_) == val_hash(la_max.as_some())) {
        // Note: k <= 1 since lookaheads k > 1 admit partial matches (``best
        // match'')
        acc_default = Some<LRAction_T>(ll->acc_);
      } else {
        for (auto [s, _] : *ll->la_->items_) {
          v->insert(std::make_pair(s, ll->acc_));
        }
      }
    }

    auto table_sub = parser_lr_action_by_vertex_impl_table_rec(
        v, acc_default, make_rc<Vec<LRSym_T>>(), k, ctx);

    tables_sub->push_back(table_sub);
  }

  SwitchTable_T table = SwitchTable::IterMat::make(0, tables_sub);
  return table;
}

pair<Vec_T<Int>, Vec_T<Int>>
parser_lr_action_by_vertex_impl_table_opt(LangCompileContext &ctx, LR_NFA_T N,
                                          LR_DFA_T D, Int k) {

  Int n = D->G_->V_->length();
  Int m = 2 + ctx.Gr_cps_->term_->length(); // EndMarker, Start
  Int vl = ((m * n / 2) + 1) * 2;

  AR_eq(static_cast<Int>(ParserActionData_W::SHIFT), 4);
  auto tt_acc = make_rc<Vec<u8>>(vl, vl, _Vec_constr_internal{}, u8(4));
  auto tt_arg = make_rc<Vec<Int>>(vl, vl, _Vec_constr_internal{}, 0);

  for (Int i = 0; i < n; i++) {
    auto vsi = D->G_->V_->operator[](i);
    auto mm = lr_tabulate_nfa_acc(N, vsi);
    for (auto [la, accs] : *mm) {
      if (accs->length() > 1) {
        LG_ERR("Conflict remains after compilation");
        AX();
      }
      LRAction_T acc = accs->items_to_vec()->only().first;
      auto term_ind = grammar_sym_to_ind_flat(ctx, la->v_->only());
      AR_ge(term_ind, 0);
      AR_lt(term_ind, m);
      auto [acc_i, arg_i] = parser_lr_action_dfa_acc_to_indices(acc, ctx);
      AR_ge(acc_i, 0);
      AR_lt(acc_i, 256);
      AR_ge(arg_i, 0);
      AR_lt(arg_i, 65536);
      tt_acc->operator[](term_ind * n + i) = acc_i;
      tt_arg->operator[](term_ind * n + i) = arg_i;
    }
  }

  AT(vl % 2 == 0);
  auto tt_acc_base = reinterpret_cast<u16 *>(&tt_acc->at_unchecked(0));
  auto tt_acc_norm = make_rc<Vec<Int>>();
  for (Int r = 0; r < vl / 2; r++) {
    tt_acc_norm->push_back(static_cast<Int>(tt_acc_base[r]));
  }

  return std::make_pair(tt_acc_norm, tt_arg);
}

} // namespace langcc
