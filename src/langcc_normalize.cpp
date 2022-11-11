
#include "langcc_common.hpp"

namespace langcc {

void parser_Gr_flat_tabulate_defined_nonterm(LangCompileContext &ctx,
                                             IdentBase_T ident) {
  if (ctx.Nm_->contains_key(ident)) {
    return;
  }

  Sym_T v = Sym::Defined::make(ident);
  Grammar::add_nonterm(ctx.Gr_flat_, v);
  ctx.Nm_->insert_strict(ident, v);
}

void lang_init_validate(LangCompileContext &ctx) {
  ctx.parse_expr_props_ = make_rc<Map<Int, ParseExprProps_T>>();

  ctx.src_ =
      xform_lang_normalize(ctx.gen_meta_, ctx.parse_expr_props_, ctx.src_, ctx);

  ctx.tokens_ = lang_get_tokens_stanza(ctx.src_);
  ctx.lexer_ = lang_get_lexer_stanza(ctx.src_);
  ctx.parser_ = lang_get_parser_stanza(ctx.src_);

  // Tabulate token defs
  for (auto &decl : *ctx.tokens_->decls_) {
    auto name = ident_singleton_from_string(decl->name_.to_std_string());
    if (ctx.tokens_def_.contains_key(name)) {
      ctx.error(decl, "Duplicate token definition");
    }
    ctx.tokens_def_.insert_strict(name, decl);
  }

  // Tabulate lexer modes
  for (auto &mode : *ctx.lexer_->decls_) {
    if (mode->is_Mode()) {
      auto name = mode->as_Mode()->name_.to_std_string();
      if (ctx.lexer_modes_ind_.contains_key(name)) {
        ctx.error(mode, "Duplicate mode definition");
      }
      ctx.lexer_modes_ind_.insert_strict(name, ctx.lexer_modes_.length());
      ctx.lexer_modes_.push_back(mode->as_Mode());
    }
  }

  bool lexer_main_mode_init = false;
  for (auto &main : *ctx.lexer_->decls_) {
    if (main->is_Main()) {
      if (lexer_main_mode_init) {
        ctx.error(main, "Duplicate main mode");
      }
      if (!ctx.lexer_modes_ind_.contains_key(
              main->as_Main()->name_.to_std_string())) {
        ctx.error(main, "Main mode not found in lexer");
      }
      ctx.lexer_main_mode_ind_ = ctx.lexer_modes_ind_.operator[](
          main->as_Main()->name_.to_std_string());
      lexer_main_mode_init = true;
    }
  }
  if (!lexer_main_mode_init) {
    ctx.error(ctx.lexer_, "No main mode in lexer");
  }

  auto m_token_refs_rev =
      make_rc<Map<Ident_T, Set_T<std::pair<bool, Ident_T>>>>();

  for (auto &decl : *ctx.tokens_->decls_) {
    visit_lang_meta_Node(decl->def__, [&](lang::meta::Node_T node) {
      if (node->is_Id()) {
        auto name_id = ident_singleton_from_string(decl->name_.to_std_string());
        auto node_id = parse_expr_id_to_ident(node->as_Id());
        if (!m_token_refs_rev->contains_key(node_id)) {
          m_token_refs_rev->insert(node_id,
                                   make_rc<Set<std::pair<bool, Ident_T>>>());
        }
        m_token_refs_rev->operator[](node_id)->insert(
            std::make_pair(decl->op_->is_DEF(), name_id));
        return;
      }

      if (!node->is_ParseExpr()) {
        ctx.error(node, "Not permitted in token definition");
      }

      auto e = node->as_ParseExpr();
      if (e->is_Id()) {
        auto ident = parse_expr_id_to_ident(e->as_Id()->id__);
        if (ident->xs_->length() > 1) {
          ctx.error(e, "Compound identifiers not supported in lexer tokens");
        }
        if (!ctx.tokens_def_.contains_key(ident)) {
          ctx.error(e, "Identifier not bound in lexer tokens");
        }
      } else if (e->is_Eof()) {
        ctx.error(e, "Eof not permitted in lexer token definitions");
      } else if (e->is_False() || e->is_Eps() || e->is_UnicodeAny() ||
                 e->is_AsciiBaseAny() || e->is_Alt() || e->is_AltExplicit() ||
                 e->is_Minus() || e->is_Concat() || e->is_Optional() ||
                 e->is_Rep() || e->is_RepNonzero() || e->is_RepCount() ||
                 e->is_CharRange() || e->is_StrLit() || e->is_Paren()) {
        // pass
      } else if (e->is_Indent() || e->is_Dedent() || e->is_Newline()) {
        ctx.error(e,
                  "Whitespace tokens not permitted in lexer token definitions");
      } else if (e->is_Underscore() || e->is_Pass()) {
        ctx.error(e, "Pass tokens not permitted in lexer token definitions");
      } else if (e->is_List()) {
        ctx.error(e, "Lists not permitted in lexer token definitions");
      } else if (e->is_Unfold()) {
        ctx.error(e, "Unfold not permitted in lexer token definitions");
      } else if (e->is_AttrReq()) {
        ctx.error(e,
                  "Attr requirements not permitted in lexer token definitions");
      } else {
        ctx.error(e, "Not permitted in token definition");
      }
    });
  }

  // Search for nested structure.
  {
    auto m_nested_vis = make_rc<Set<std::pair<Ident_T, Int>>>();
    auto Q = make_rc<Vec<std::pair<Ident_T, Int>>>();
    for (auto decl : *ctx.tokens_->decls_) {
      auto id = ident_singleton_from_string(decl->name_.to_std_string());
      auto p = std::make_pair(id, decl->op_->is_DEF() ? 1 : 0);
      Q->push_back(p);
      m_nested_vis->insert(p);
    }
    while (!Q->empty()) {
      auto [curr, d] = Q->pop_front_val();
      if (!m_token_refs_rev->contains_key(curr)) {
        continue;
      }
      auto ids_ref = m_token_refs_rev->operator[](curr);
      for (auto [is_def, id_ref] : *ids_ref) {
        auto d_new = d + (is_def ? 1 : 0);
        if (d_new >= 2) {
          for (auto [is_def, id_ref] : *ids_ref) {
            ctx.error(ctx.tokens_,
                      fmt_str("Lexer tokens contain nested structure: {} -> {}",
                              id_ref, curr));
          }
        }

        auto p_new = std::make_pair(id_ref, d_new);
        if (!m_nested_vis->contains(p_new)) {
          Q->push_back(p_new);
          m_nested_vis->insert(p_new);
        }
      }
    }
  }

  // Search for cycles.
  {
    auto m_cycle_vis = make_rc<Set<Ident_T>>();
    auto S = make_rc<Vec<Ident_T>>();
    auto S_set = make_rc<Set<Ident_T>>();
    for (auto decl : *ctx.tokens_->decls_) {
      auto id = ident_singleton_from_string(decl->name_.to_std_string());
      if (!m_cycle_vis->contains(id)) {
        S->push(id);
        S_set->insert(id);

        while (!S->empty()) {
          auto curr = S->back();
          bool pushed = false;
          if (m_token_refs_rev->contains_key(curr)) {
            auto ids_ref = m_token_refs_rev->operator[](curr);
            for (auto [_, id_ref] : *ids_ref) {
              if (S_set->contains(id_ref)) {
                ctx.error(ctx.tokens_,
                          fmt_str("Lexer tokens contain cycle: {} -> {}",
                                  id_ref, id_ref));
              }
              if (!m_cycle_vis->contains(id_ref)) {
                m_cycle_vis->insert(id_ref);
                S->push(id_ref);
                S_set->insert(id_ref);
                pushed = true;
                break;
              }
            }
          }
          if (!pushed) {
            S->pop_back();
            S_set->remove(curr);
          }
        }
      }
    }
  }

  ctx.tokens_top_init_src_ =
      make_rc<Map<ParseExpr_Base_T, Vec_T<meta::Node::LexerInstr_T>>>();

  // Populate tokens_top_init_src_ with immediately-emitted exprs (note: used to
  // initialize search for top-level tokens, but may not be top-level tokens
  // themselves).
  for (auto &decl : *ctx.lexer_->decls_) {
    if (decl->is_Mode()) {
      for (auto &mode_case : *decl->as_Mode()->cases_) {
        auto case_pat = mode_case->tok_;
        for (auto &instr : *mode_case->instrs_) {
          lang_init_validate_tabulate_lexer_instr_emit_rec(instr, case_pat,
                                                           ctx);
        }
      }
    }
  }

  bool any_ws = false;
  for (auto &decl : *ctx.lexer_->decls_) {
    if (decl->is_Mode()) {
      if (decl->as_Mode()->ws_sig__.is_some()) {
        any_ws = true;
      }
    }
  }

  // Tabulate top-level tokens
  Vec<ParseExpr_Base_T> Q_tokens_top_traversal;
  for (auto &[tok, _] : *ctx.tokens_top_init_src_) {
    Q_tokens_top_traversal.push_back(tok);
    ctx.tokens_top_traversal_alias_parent_.insert_strict(tok, tok);
  }
  while (!Q_tokens_top_traversal.empty()) {
    auto tok = Q_tokens_top_traversal.pop_front_val();
    if (tok->tok_->is_Id()) {
      auto decl = ctx.tokens_def_[tok->tok_->as_Id()->name_];
      if (decl->op_->is_DEF_ALIAS()) {
        Vec<ParseExpr_Base_T> toks_sub;
        lexer_extract_alias_toks_sub_acc(toks_sub, decl->def__, tok, ctx);
        for (auto tok_sub : toks_sub) {
          if (!ctx.tokens_top_traversal_alias_parent_.contains_key(tok_sub)) {
            ctx.tokens_top_traversal_alias_parent_.insert_strict(tok_sub, tok);
            Q_tokens_top_traversal.push_back(tok_sub);
          }
        }
      } else if (decl->op_->is_DEF()) {
        if (!ctx.tokens_top_by_id_rev_.contains_key(tok)) {
          ctx.tokens_top_by_id_rev_.insert(tok, ctx.tokens_top_by_id_.length());
          ctx.tokens_top_by_id_.push(tok);
        }
      } else {
        AX();
      }
    } else if (tok->tok_->is_LitStr()) {
      if (!ctx.tokens_top_by_id_rev_.contains_key(tok)) {
        ctx.tokens_top_by_id_rev_.insert(tok, ctx.tokens_top_by_id_.length());
        ctx.tokens_top_by_id_.push(tok);
      }
    } else {
      AX();
    }
  }

  if (any_ws) {
    auto ws_toks = make_rc<Vec<TokenBase_T>>();
    ws_toks->push_back(TokenBase::Special::make(TokenBaseSpecial::Indent));
    ws_toks->push_back(TokenBase::Special::make(TokenBaseSpecial::Dedent));
    ws_toks->push_back(TokenBase::Special::make(TokenBaseSpecial::Newline));
    ws_toks->push_back(
        TokenBase::Special::make(TokenBaseSpecial::ErrMixedIndent));
    ws_toks->push_back(
        TokenBase::Special::make(TokenBaseSpecial::ErrTextAfterLC));
    ws_toks->push_back(
        TokenBase::Special::make(TokenBaseSpecial::ErrDelimMismatch));

    for (auto tok : *ws_toks) {
      auto tok_expr = parse_expr_base_from_token(tok);
      if (!ctx.tokens_top_by_id_rev_.contains_key(tok_expr)) {
        ctx.tokens_top_by_id_rev_.insert(tok_expr,
                                         ctx.tokens_top_by_id_.length());
        ctx.tokens_top_by_id_.push(tok_expr);
      }
    }
  }

  LOG(2, "Top-level lexer tokens: {}", ctx.tokens_top_by_id_);

  // Tabulate char thresholds
  std::set<Int> char_thresholds_s;
  Vec<IntPair> char_ranges;
  Vec<meta::Node::ParseExpr_T> Q_tabulate_chars;
  for (auto decl : *ctx.tokens_->decls_) {
    Q_tabulate_chars.push_back(decl->def__);
  }
  for (auto mode : ctx.lexer_modes_) {
    for (auto mode_case : *mode->as_Mode()->cases_) {
      auto case_pat = mode_case->tok_;
      Q_tabulate_chars.push_back(case_pat);
    }
  }
  while (!Q_tabulate_chars.empty()) {
    auto e = Q_tabulate_chars.pop_front_val();
    if (e->is_Id()) {
      // pass
    } else if (e->is_Underscore()) {
      char_ranges.push_back(std::make_pair(0, 0x110000));
      char_thresholds_s.insert(0);
      char_thresholds_s.insert(0x110000);
    } else if (e->is_Alt()) {
      for (auto x : *e->as_Alt()->xs_) {
        Q_tabulate_chars.push_back(x);
      }
    } else if (e->is_AltExplicit()) {
      Q_tabulate_chars.push_back(e->as_AltExplicit()->e_);
    } else if (e->is_Concat()) {
      for (auto x : *e->as_Concat()->xs_) {
        Q_tabulate_chars.push_back(x);
      }
    } else if (e->is_Optional()) {
      Q_tabulate_chars.push_back(e->as_Optional()->x_);
    } else if (e->is_Rep()) {
      Q_tabulate_chars.push_back(e->as_Rep()->x_);
    } else if (e->is_RepNonzero()) {
      Q_tabulate_chars.push_back(e->as_RepNonzero()->x_);
    } else if (e->is_RepCount()) {
      Q_tabulate_chars.push_back(e->as_RepCount()->x_);
    } else if (e->is_Minus()) {
      Q_tabulate_chars.push_back(e->as_Minus()->x_);
      Q_tabulate_chars.push_back(e->as_Minus()->y_);
    } else if (e->is_Paren()) {
      Q_tabulate_chars.push_back(e->as_Paren()->x_);
    } else if (e->is_StrLit()) {
      auto cc = e->as_StrLit();
      auto s = cc->s_.to_std_string();
      Option_T<std::vector<Ch>> chs = string_extract_lang_char_seq(s);
      if (chs.is_none()) {
        ctx.error(e, "Invalid std::string literal");
      }
      for (auto ch : chs.as_some()) {
        char_ranges.push_back(std::make_pair(ch, ch + 1));
        char_thresholds_s.insert(ch);
        char_thresholds_s.insert(ch + 1);
      }
    } else if (e->is_CharRange()) {
      auto cc = e->as_CharRange();
      auto chs_min = string_extract_lang_char_seq(cc->min__.to_std_string());
      auto chs_max = string_extract_lang_char_seq(cc->max__.to_std_string());
      if (chs_min.is_none() || chs_max.is_none() ||
          chs_min.as_some().size() != 1 || chs_max.as_some().size() != 1) {
        ctx.error(e, "Invalid character range");
      }
      char_ranges.push_back(
          std::make_pair(chs_min.as_some()[0], chs_max.as_some()[0] + 1));
      char_thresholds_s.insert(chs_min.as_some()[0]);
      char_thresholds_s.insert(chs_max.as_some()[0] + 1);
    } else if (e->is_False()) {
      // pass
    } else if (e->is_Eof()) {
      // pass
    } else if (e->is_UnicodeAny()) {
      char_ranges.push_back(std::make_pair(0, 0x110000));
      char_thresholds_s.insert(0);
      char_thresholds_s.insert(0x110000);
    } else if (e->is_AsciiBaseAny()) {
      char_ranges.push_back(std::make_pair(0, 0x80));
      char_thresholds_s.insert(0);
      char_thresholds_s.insert(0x80);
    } else {
      ctx.error(e, "Not supported in lexer tokens");
    }
  }

  Int j_naive = 0;
  Int k_naive = 0;
  Vec<Int> char_thresholds_naive;
  Map<Int, Int> char_thresholds_naive_r;
  char_thresholds_naive.push(k_naive);
  char_thresholds_naive_r.insert(k_naive, j_naive);
  ++j_naive;
  for (auto ch : char_thresholds_s) {
    if (ch == k_naive) {
      continue;
    }
    k_naive = ch;
    char_thresholds_naive.push(k_naive);
    char_thresholds_naive_r.insert(k_naive, j_naive);
    ++j_naive;
  }
  char_thresholds_naive.push(0x110000);
  char_thresholds_naive_r.insert(0x110000, j_naive);
  ++j_naive;

  auto char_intervals_hit = Vec<bool>::repeat(false, j_naive - 1);
  for (auto r : char_ranges) {
    AT(char_thresholds_naive_r.contains_key(r.first));
    AT(char_thresholds_naive_r.contains_key(r.second));
    for (Int i = char_thresholds_naive_r[r.first];
         i < char_thresholds_naive_r[r.second]; i++) {
      char_intervals_hit->operator[](i) = true;
    }
  }

  Int j_hit = 1; // 0 is EOF
  bool active = false;
  for (Int j = 0; j < j_naive; j++) {
    if (j < j_naive - 1 && char_intervals_hit->operator[](j)) {
      ctx.char_thresholds_.insert(
          std::make_pair(char_thresholds_naive[j], j_hit));
      ++j_hit;
      active = true;
    } else {
      if (active) {
        ctx.char_thresholds_.insert(
            std::make_pair(char_thresholds_naive[j], -1));
        active = false;
      }
    }
  }

  Option_T<IntPair> buf = None<IntPair>();
  for (auto p : ctx.char_thresholds_) {
    if (buf.is_some() && buf.as_some().second != -1) {
      ctx.char_ranges_.push_back(std::make_pair(buf.as_some().first, p.first));
    }
    buf = Some<IntPair>(p);
  }
  AT(buf.is_some() &&
     (buf.as_some().second == -1 || buf.as_some().first == 0x110000));

  // Tabulate parser metadata and rules
  ctx.parser_name_strict_ = false;
  ctx.parser_syms_top_ = make_rc<VecUniq<Ident_T>>();
  ctx.parser_rules_ = make_rc<Map<Ident_T, Rule_T>>();
  ctx.parser_rule_inds_ = make_rc<Map<Ident_T, Int>>();
  ctx.parser_attr_clauses_ = make_rc<Vec<AttrClause_T>>();
  ctx.parser_attr_domains_ =
      make_rc<Map<Sym_T, Map_T<AttrKey_T, AttrType_T>>>();
  ctx.parser_attr_constr_by_rule_ =
      make_rc<Map<Ident_T, Vec_T<ProdConstr_T>>>();
  ctx.parser_rule_explicit_def_ids_ = make_rc<Set<Ident_T>>();
  ctx.parser_rule_all_ids_ = make_rc<Set<Ident_T>>();
  ctx.parser_rule_non_alias_ids_ = make_rc<Set<Ident_T>>();
  ctx.parser_prec_n_ = -1;
  ctx.Nm_ = make_rc<Map<IdentBase_T, Sym_T>>();
  ctx.Np_ = make_rc<Map<Ident_T, Sym_T>>();
  ctx.Gr_flat_ = Grammar::empty();
  ctx.Gr_flat_prod_constrs_ =
      make_rc<Map<Prod_T, VecUniq_T<ProdConstrFlat_T>>>();
  ctx.Gr_flat_nonterm_gensym_ = make_rc<Gensym>();
  ctx.Gr_flat_prod_gensyms_ = make_rc<Map<Int, Gensym_T>>();
  ctx.Gr_flat_lhs_flatten_leaves_ =
      make_rc<Map<Prod_T, Option_T<AttrLeaf_T>>>();
  ctx.Gr_flat_rhs_flatten_leaves_ =
      make_rc<Map<Prod_T, Vec_T<Option_T<AttrLeaf_T>>>>();
  ctx.parser_attr_gensym_ = make_rc<Gensym>();
  ctx.gen_dt_map_ = make_rc<Map<Ident_T, GenType_T>>();
  ctx.gen_wr_map_ = make_rc<Map<Ident_T, WriteInstr_T>>();
  ctx.gen_rd_map_ = make_rc<Map<Prod_T, UnwindInstr_T>>();
  ctx.gen_dt_parent_mapping_ =
      make_rc<Map<Ident_T, std::pair<Ident_T, IdentBase_T>>>();

  bool found_main = false;
  bool found_attr = false;
  bool found_prec = false;

  for (auto decl : *ctx.parser_->decls_) {
    if (decl->is_Rule()) {
      auto rule = decl->as_Rule();
      if (rule->op_->is_DEF_ALIAS()) {
        AX();
      }
      auto name = parse_expr_id_to_ident(rule->name_);
      ctx.parser_rule_inds_->insert_strict(name, ctx.parser_rules_->length());
      ctx.parser_rules_->insert_strict(name, decl->as_Rule());

    } else if (decl->is_Main()) {
      if (found_main) {
        ctx.error(decl, "Multiple main stanzas in parser");
      }
      found_main = true;
      auto dc = decl->as_Main();
      for (auto name : *dc->names_) {
        if (ctx.parser_sym_top_main_.is_none()) {
          ctx.parser_sym_top_main_ = Some<std::string>(name.to_std_string());
        }
        auto name_top = ident_singleton_from_string(name.to_std_string());
        if (ctx.parser_syms_top_->contains(name_top)) {
          ctx.error(dc, fmt_str("Duplicate name {} in main stanza",
                                name.to_std_string()));
        }
        ctx.parser_syms_top_->insert_strict(name_top);
      }
      if (ctx.parser_sym_top_main_.is_none()) {
        ctx.error(decl, "Parser main stanza requires at least one symbol");
      }

    } else if (decl->is_Prop()) {
      for (auto prop : *decl->as_Prop()->props_) {
        if (prop->is_NameStrict()) {
          ctx.parser_name_strict_ = true;
        } else if (prop->is_AllowUnreach()) {
          ctx.parser_allow_unreach_ = true;
        }
      }

    } else if (decl->is_Prec()) {
      if (found_prec) {
        ctx.error(decl, "Multiple prec stanzas in parser");
      }
      found_prec = true;
      ctx.parser_prec_ = Some<meta::Node::ParserDecl::Prec_T>(decl->as_Prec());

    } else if (decl->is_Attr()) {
      if (found_attr) {
        ctx.error(decl, "Multiple attr stanzas in parser");
      }
      found_attr = true;
      auto dc = decl->as_Attr();
      for (auto clause : *dc->clauses_) {
        ctx.parser_attr_clauses_->push_back(clause);
      }

    } else {
      AX();
    }
  }

  if (!found_main) {
    ctx.error(ctx.parser_, "Parser definition requires a main stanza");
  }

  for (auto p : *ctx.parser_rule_inds_) {
    auto rule = ctx.parser_rules_->operator[](p.first);
    auto i = p.second;

    auto curr = parse_expr_id_to_ident(rule->name_);
    if (ctx.parser_rule_explicit_def_ids_->contains(curr)) {
      ctx.error(rule, "Duplicate rule id");
    }
    ctx.parser_rule_explicit_def_ids_->insert_strict(curr);
    while (true) {
      ctx.parser_rule_all_ids_->insert(curr);
      if (!rule->op_->is_DEF_ALIAS()) {
        ctx.parser_rule_non_alias_ids_->insert(curr);
      }
      if (Ident::is_base(curr)) {
        break;
      }
      curr = Ident::without_last(curr);
    }
    if (!rule->op_->is_DEF_ALIAS()) {
      parser_Gr_flat_tabulate_defined_nonterm(
          ctx, Ident::extract_base(parse_expr_id_to_ident(rule->name_)));
    }
  }

  for (auto p : *ctx.parser_rule_inds_) {
    auto rule = ctx.parser_rules_->operator[](p.first);
    auto i = p.second;

    auto curr = parse_expr_id_to_ident(rule->name_);
    while (true) {
      if (Ident::is_base(curr)) {
        break;
      }
      curr = Ident::without_last(curr);
      if (ctx.parser_rule_explicit_def_ids_->contains(curr)) {
        ctx.error(rule, fmt_str("Parser rule {} overridden by {}",
                                parse_expr_id_to_ident(rule->name_), curr));
      }
    }
  }
}

bool lang_name_is_lower_reserved(std::string x) {
  auto res = make_rc<Set<std::string>>();
  res->insert("__attribute__");
  res->insert("_LT_");
  res->insert("_GT_");
  res->insert("break");
  res->insert("case");
  res->insert("class");
  res->insert("const");
  res->insert("continue");
  res->insert("def");
  res->insert("default");
  res->insert("delete");
  res->insert("else");
  res->insert("enum");
  res->insert("float");
  res->insert("for");
  res->insert("id");
  res->insert("if");
  res->insert("inline");
  res->insert("int");
  res->insert("Int");
  res->insert("Map");
  res->insert("mut");
  res->insert("namespace");
  res->insert("new");
  res->insert("no_hash");
  res->insert("not");
  res->insert("Option");
  res->insert("or");
  res->insert("Ptr");
  res->insert("Ref");
  res->insert("return");
  res->insert("static");
  res->insert("string");
  res->insert("Set");
  res->insert("Str");
  res->insert("string");
  res->insert("struct");
  res->insert("switch");
  res->insert("template");
  res->insert("Type");
  res->insert("typename");
  res->insert("using");
  res->insert("Vec");
  res->insert("VecUniq");
  res->insert("virtual");
  res->insert("visit");
  res->insert("which");
  res->insert("xform");
  res->insert("xformT");
  res->insert("xor");
  return res->contains(x);
}

meta::Node::ParseExpr_T
xform_parse_expr_normalize(meta::Node::ParseExpr_T e,
                           ParseExprPropsMap_T &dst_props, Gensym_T gen,
                           Map_T<Ident_T, ParseExpr_T> parser_aliases_by_ident,
                           LangCompileContext &ctx) {

  auto e_init = e;

  auto props = ParseExprProps::empty();

  bool do_paren = false;

  while (true) {
    if (e->is_Unfold()) {
      if (props->unfold_) {
        ctx.error(e, "Expression cannot be unfolded multiple times");
      }
      props->unfold_ = true;
      e = e->as_Unfold()->e_;
      continue;

    } else if (e->is_Name()) {
      if (props->name_.is_some()) {
        ctx.error(e, "Expression cannot be named multiple times");
      }
      auto e_nm = e->as_Name()->name_.to_std_string();
      if (lang_name_is_lower_reserved(e_nm)) {
        ctx.error(e, fmt_str("Name `{}` is a reserved keyword in some language",
                             e_nm));
      }
      props->name_ = Some<IdentBase_T>(ident_base_from_string(e_nm));
      e = e->as_Name()->e_;
      continue;

    } else if (e->is_AttrReq()) {
      if (props->attr_req_.is_some()) {
        ctx.error(e,
                  "Expression cannot have multiple attr requirement clauses");
      }
      if (!e->as_AttrReq()->e_->is_Id()) {
        ctx.error(e, "Only Id expressions can carry attr requirement clauses");
      }
      props->attr_req_ =
          Some<Vec_T<meta::Node::AttrReq_T>>(e->as_AttrReq()->attrs_);
      e = e->as_AttrReq()->e_;
      continue;

    } else if (e->is_Id()) {
      auto orig_bounds = e->bounds_;
      auto ident = parse_expr_id_to_ident(e->as_Id()->id__);

      if (ident->xs_->length() > 1) {
        ctx.error(e,
                  "Compound identifiers not supported in parser expressions");
      }

      if (parser_aliases_by_ident->contains_key(ident)) {
        e = parser_aliases_by_ident->operator[](ident);
        e = xform_parse_expr_freshen_rec(e, gen, orig_bounds);
        e = meta::Node::ParseExpr::Paren::make(gen->gen(), e->bounds_,
                                               e->is_top_, e->sym_, e->attr_,
                                               e->first_k_, e);
        continue;
      } else {
        break;
      }

    } else if (e->is_Eps()) {
      break;

    } else if (e->is_Pass() || e->is_Underscore()) {
      // Leave underscores in for readability.
      break;

    } else if (e->is_AltExplicit()) {
      auto v = make_rc<Vec<ParseExpr_T>>();
      v->push_back(e->as_AltExplicit()->e_);
      e = meta::Node::ParseExpr::Alt::make(gen->gen(), e->bounds_, e->is_top_,
                                           e->sym_, e->attr_, e->first_k_, v);

    } else if (e->is_Alt()) {
      auto cc = e->as_Alt();
      auto ys = make_rc<Vec<ParseExpr_T>>();
      for (const auto &x : *cc->xs_) {
        ys->push_back(xform_parse_expr_normalize(x, dst_props, gen,
                                                 parser_aliases_by_ident, ctx));
      }
      e = meta::Node::ParseExpr::Alt::make(gen->gen(), e->bounds_, e->is_top_,
                                           e->sym_, e->attr_, e->first_k_, ys);
      break;

    } else if (e->is_Concat()) {
      auto cc = e->as_Concat();
      auto ys = make_rc<Vec<ParseExpr_T>>();
      for (const auto &x : *cc->xs_) {
        ys->push_back(xform_parse_expr_normalize(x, dst_props, gen,
                                                 parser_aliases_by_ident, ctx));
      }
      e = meta::Node::ParseExpr::Concat::make(gen->gen(), e->bounds_,
                                              e->is_top_, e->sym_, e->attr_,
                                              e->first_k_, ys);
      break;

    } else if (e->is_Optional()) {
      auto cc = e->as_Optional();
      auto y = xform_parse_expr_normalize(cc->x_, dst_props, gen,
                                          parser_aliases_by_ident, ctx);
      e = meta::Node::ParseExpr::Optional::make(gen->gen(), e->bounds_,
                                                e->is_top_, e->sym_, e->attr_,
                                                e->first_k_, y);
      break;

    } else if (e->is_List()) {
      auto cc = e->as_List();
      auto elem_y = xform_parse_expr_normalize(cc->elem_, dst_props, gen,
                                               parser_aliases_by_ident, ctx);
      auto delim_y = xform_parse_expr_normalize(cc->delim_, dst_props, gen,
                                                parser_aliases_by_ident, ctx);
      e = meta::Node::ParseExpr::List::make(
          gen->gen(), e->bounds_, e->is_top_, e->sym_, e->attr_, e->first_k_,
          cc->ty_, elem_y, cc->num_, delim_y, cc->end_delim_);
      break;

    } else if (e->is_Rep()) {
      auto cc = e->as_Rep();
      auto elem_y = xform_parse_expr_normalize(cc->x_, dst_props, gen,
                                               parser_aliases_by_ident, ctx);
      e = meta::Node::ParseExpr::Rep::make(gen->gen(), e->bounds_, e->is_top_,
                                           e->sym_, e->attr_, e->first_k_,
                                           elem_y);
      break;

    } else if (e->is_RepNonzero()) {
      auto cc = e->as_RepNonzero();
      auto elem_y = xform_parse_expr_normalize(cc->x_, dst_props, gen,
                                               parser_aliases_by_ident, ctx);
      e = meta::Node::ParseExpr::RepNonzero::make(gen->gen(), e->bounds_,
                                                  e->is_top_, e->sym_, e->attr_,
                                                  e->first_k_, elem_y);
      break;

    } else if (e->is_Paren()) {
      e = e->as_Paren()->x_;
      do_paren = true;
      continue;

    } else if (parse_expr_to_base_maybe(e).is_some()) {
      break;

    } else {
      ctx.error(e, "Expression not supported in parser definitions");
    }
  }

  dst_props->insert(e->id_, props);

  if (do_paren) {
    // Reinsert parens to avoid confusing expression renderings that lose
    // precedence.
    auto ep = meta::Node::ParseExpr::Paren::make(
        gen->gen(), e->bounds_, e->is_top_, e->sym_, e->attr_, e->first_k_, e);
    dst_props->insert_strict(ep->id_, ParseExprProps::empty());
    return ep;
  } else {
    return e;
  }
}

meta::Node::Lang_T xform_lang_normalize(Gensym_T gen,
                                        ParseExprPropsMap_T &dst_props,
                                        meta::Node::Lang_T L,
                                        LangCompileContext &ctx) {

  auto parser_aliases_by_ident = make_rc<Map<Ident_T, ParseExpr_T>>();
  auto parser = lang_get_parser_stanza(L);
  for (auto decl : *parser->decls_) {
    if (decl->is_Rule()) {
      auto rule = decl->as_Rule();
      if (rule->op_->is_DEF_ALIAS()) {
        if (rule->name_->names_->length() != 1) {
          ctx.error(rule, "Alias rule with compound identifier");
        }
        auto rule_id = parse_expr_id_to_ident(rule->name_);
        if (parser_aliases_by_ident->contains_key(rule_id)) {
          ctx.error(rule, "Duplicate rule id");
        }
        parser_aliases_by_ident->insert_strict(rule_id, rule->e_);
      }
    }
  }

  // Check for alias cycles
  auto m_alias_refs = make_rc<Map<Ident_T, Set_T<Ident_T>>>();
  for (auto decl : *parser->decls_) {
    if (decl->is_Rule()) {
      auto rule = decl->as_Rule();
      if (rule->op_->is_DEF_ALIAS()) {
        visit_lang_meta_Node(rule->e_, [&](lang::meta::Node_T node) {
          auto name_ident = parse_expr_id_to_ident(rule->name_);
          if (!m_alias_refs->contains_key(name_ident)) {
            m_alias_refs->insert(name_ident, make_rc<Set<Ident_T>>());
          }
          if (node->is_Id()) {
            auto node_ident = parse_expr_id_to_ident(node->as_Id());
            m_alias_refs->operator[](name_ident)->insert(node_ident);
          }
        });
      }
    }
  }
  auto vis_alias_search = make_rc<Set<Ident_T>>();
  auto S = make_rc<Vec<Ident_T>>();
  auto S_set = make_rc<Set<Ident_T>>();
  for (auto decl : *parser->decls_) {
    if (decl->is_Rule()) {
      auto rule = decl->as_Rule();
      if (rule->op_->is_DEF_ALIAS()) {
        auto name_ident = parse_expr_id_to_ident(rule->name_);
        if (!vis_alias_search->contains(name_ident)) {
          S->push(name_ident);
          S_set->insert(name_ident);
          vis_alias_search->insert(name_ident);

          while (!S->empty()) {
            auto curr = S->back();
            bool pushed = false;
            if (m_alias_refs->contains_key(curr)) {
              for (const auto &next : *m_alias_refs->operator[](curr)) {
                if (S_set->contains(next)) {
                  ctx.error(rule, fmt_str("Parser alias cycle on {} -> {} {}",
                                          next, next, m_alias_refs));
                }
                if (!vis_alias_search->contains(next)) {
                  S->push_back(next);
                  S_set->insert(next);
                  vis_alias_search->insert(next);
                  pushed = true;
                  break;
                }
              }
            }

            if (!pushed) {
              S->pop();
              S_set->remove(curr);
            }
          }
        }
      }
    }
  }

  auto stanzas_new = make_rc<Vec<meta::Node::Stanza_T>>();
  for (auto xi : *L->as_Lang()->stanzas_) {
    auto xi_new = xi;
    if (xi->is_Parser()) {
      auto cc = xi->as_Parser();
      auto decls_new = make_rc<Vec<meta::Node::ParserDecl_T>>();
      for (auto decl : *cc->decls_) {
        if (decl->is_Main() || decl->is_Prop() || decl->is_Prec() ||
            decl->is_Attr()) {
          decls_new->push_back(decl);
        } else if (decl->is_Rule()) {
          auto dc = decl->as_Rule();
          if (dc->op_->is_DEF_ALIAS()) {
            continue;
          }
          for (auto nm : *dc->name_->names_) {
            if (lang_name_is_lower_reserved(nm.to_std_string())) {
              ctx.error(
                  dc,
                  fmt_str("Name `{}` is a reserved keyword in some language",
                          nm.to_std_string()));
            }
          }
          auto e_new = xform_parse_expr_normalize(dc->e_, dst_props, gen,
                                                  parser_aliases_by_ident, ctx)
                           ->as_ParseExpr();
          auto dc_new = dc->with_e(e_new)->with_id(gen->gen());
          decls_new->push_back(dc_new);
        } else {
          AX();
        }
      }
      auto xi_new = meta::Node::Stanza::Parser::make(
          gen->gen(), xi->bounds_, xi->is_top_, xi->sym_, xi->attr_,
          xi->first_k_, decls_new);
      stanzas_new->push_back(xi_new);
    }
    stanzas_new->push_back(xi_new);
  }

  return meta::Node::Lang::make(gen->gen(), L->bounds_, L->is_top_, L->sym_,
                                L->attr_, L->first_k_, stanzas_new);
}

} // namespace langcc
