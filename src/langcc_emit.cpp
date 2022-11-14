
#include "langcc_common.hpp"

namespace langcc {

void lang_emit_preambles(LangCompileContext &ctx) {
  ctx.cc_.dst_decls_->push_back(
      ctx.cc_.Q_->qq_ext(Some<std::string>("Decl"), "#pragma once")->as_Decl());

  ctx.cc_.dst_decls_->push_back(
      ctx.cc_.Q_->qq_ext(Some<std::string>("Decl"), "#include <langcc_rt.hpp>")
          ->as_Decl());

  ctx.cc_.dst_defs_->push_back(
      ctx.cc_.Q_
          ->qq_ext(Some<std::string>("Decl"),
                   fmt_str("#include \"{}\"", ctx.hpp_name_))
          ->as_Decl());

  ctx.cc_test_.dst_defs_->push_back(
      ctx.cc_.Q_
          ->qq_ext(Some<std::string>("Decl"),
                   fmt_str("#include \"{}\"", ctx.hpp_name_))
          ->as_Decl());

  ctx.cc_debug_.dst_defs_->push_back(
      ctx.cc_.Q_
          ->qq_ext(Some<std::string>("Decl"),
                   fmt_str("#include \"{}\"", ctx.hpp_name_))
          ->as_Decl());
}

Int lexer_instrs_num_stack_changes_max(
    Vec_T<lang::meta::Node::LexerInstr_T> instrs);

Int lexer_instr_num_stack_changes_max(lang::meta::Node::LexerInstr_T instr) {
  if (instr->is_Push() || instr->is_Pop() || instr->is_PopEmit() ||
      instr->is_PopExtract()) {
    return 1;
  } else if (instr->is_Pass() || instr->is_Emit()) {
    return 0;
  } else if (instr->is_MatchHistory()) {
    auto cc = instr->as_MatchHistory();
    Int ret = 0;
    for (const auto &case_ : *cc->cases_) {
      auto ret_i = lexer_instrs_num_stack_changes_max(case_->instrs_);
      if (ret_i > ret) {
        ret = ret_i;
      }
    }
    return ret;
  } else {
    LG_ERR("{}", instr);
    AX();
  }
}

Int lexer_instrs_num_stack_changes_max(
    Vec_T<lang::meta::Node::LexerInstr_T> instrs) {
  Int ret = 0;
  for (const auto &instr : *instrs) {
    ret += lexer_instr_num_stack_changes_max(instr);
  }
  return ret;
}

Int lexer_instrs_num_emit_match_max(
    Vec_T<lang::meta::Node::LexerInstr_T> instrs);

Int lexer_instr_num_emit_match_max(lang::meta::Node::LexerInstr_T instr) {
  if (instr->is_Push() || instr->is_Pop() || instr->is_PopEmit() ||
      instr->is_PopExtract() || instr->is_Pass()) {
    return 0;
  } else if (instr->is_Emit()) {
    auto cc = instr->as_Emit();
    if (cc->arg_.is_none()) {
      return 1;
    } else {
      return 0;
    }
  } else if (instr->is_MatchHistory()) {
    auto cc = instr->as_MatchHistory();
    Int ret = 0;
    for (const auto &case_ : *cc->cases_) {
      auto ret_i = lexer_instrs_num_emit_match_max(case_->instrs_);
      if (ret_i > ret) {
        ret = ret_i;
      }
    }
    return ret;
  } else {
    LG_ERR("{}", instr);
    AX();
  }
}

Int lexer_instrs_num_emit_match_max(
    Vec_T<lang::meta::Node::LexerInstr_T> instrs) {
  Int ret = 0;
  for (const auto &instr : *instrs) {
    ret += lexer_instr_num_emit_match_max(instr);
  }
  return ret;
}

void lexer_gen_cpp_defs(
    LangCompileContext &ctx, CppGenContext &cc,
    const std::string &src_base_name,
    Map_T<meta::Node::LexerDecl::Mode_T, LexerNFA_T> lexer_mode_dfas) {

  // ===== Label ids =====

  ctx.cc_.dst_decls_->push_back(
      ctx.cc_
          .qq("Decl", "namespace lang::", src_base_name, "::lexer {",
              "langcc::rc_ptr<langcc::DFALabelIdVec> label_ids_ascii();"
              "langcc::rc_ptr<langcc::DFALabelIdMap> label_ids_unicode();"
              "}")
          ->as_Decl());

  Vec<lang::cc::Node_T> cpp_label_ids_ascii_inits;
  Int ch_curr = 0;
  Int ind_curr = -1;
  for (const auto &p : ctx.char_thresholds_) {
    while (ch_curr < p.first && ch_curr < 128) {
      if (ind_curr != -1) {
        cpp_label_ids_ascii_inits.push_back(
            ctx.cc_.qq("Stmt", "ret->at_unchecked(", fmt_str("{}", ch_curr),
                       ") = ", fmt_str("{}", ind_curr), ";"));
      }
      ++ch_curr;
    }
    ind_curr = p.second;
    if (ch_curr >= 128) {
      break;
    }
  }

  ctx.cc_.dst_defs_->push_back(
      ctx.cc_
          .qq("Decl", "namespace lang::", src_base_name, "::lexer {",
              "langcc::rc_ptr<langcc::DFALabelIdVec> label_ids_ascii() {"
              "auto ret = "
              "langcc::Vec<langcc::DFALabelId>::repeat(langcc::DFATable::NO_"
              "LABEL, 128);",
              cpp_label_ids_ascii_inits, "return ret;", "}", "}")
          ->as_Decl());

  Vec<lang::cc::Node_T> cpp_label_ids_unicode_inits;
  Int ch_curr_unicode = 128;
  Int ind_curr_unicode = -1;
  for (const auto &p : ctx.char_thresholds_) {
    if (p.first < ch_curr_unicode) {
      ind_curr_unicode = p.second;
      continue;
    }
    if (ch_curr_unicode < p.first) {
      auto cpp_ind_curr_unicode = ctx.cc_.qq(
          "Expr", ind_curr_unicode == -1 ? "langcc::DFATable::NO_LABEL"
                                         : fmt_str("{}", ind_curr_unicode));
      cpp_label_ids_unicode_inits.push_back(ctx.cc_.qq(
          "Stmt", "ret->insert(std::make_pair(", fmt_str("{}", ch_curr_unicode),
          ",", cpp_ind_curr_unicode, "));"));
    }
    ch_curr_unicode = p.first;
    ind_curr_unicode = p.second;
  }
  auto cpp_ind_curr_unicode = ctx.cc_.qq(
      "Expr", ind_curr_unicode == -1 ? "langcc::DFATable::NO_LABEL"
                                     : fmt_str("{}", ind_curr_unicode));
  cpp_label_ids_unicode_inits.push_back(ctx.cc_.qq(
      "Stmt", "ret->insert(std::make_pair(", fmt_str("{}", ch_curr_unicode),
      ",", cpp_ind_curr_unicode, "));"));

  ctx.cc_.dst_defs_->push_back(
      ctx.cc_
          .qq("Decl", "namespace lang::", src_base_name, "::lexer {",
              "langcc::rc_ptr<langcc::DFALabelIdMap> label_ids_unicode() {"
              "auto ret = langcc::make_rc<langcc::DFALabelIdMap>();",
              cpp_label_ids_unicode_inits, "return ret;", "}", "}")
          ->as_Decl());

  for (const auto &[mode, dfa] : *lexer_mode_dfas) {
    auto name = mode->name_.to_std_string();

    ctx.cc_.dst_decls_->push_back(
        ctx.cc_
            .qq("Decl", "namespace lang::", src_base_name, "::lexer::", name,
                "{",
                "langcc::DFAVertexId step(langcc::DFAVertexId v, "
                "langcc::DFALabelId lbl);",
                "[[always_inlines]] inline "
                "langcc::DFAActionWithToken",
                "acc(langcc::DFAVertexId v);",
                "[[always_inlines]] inline langcc::IntPair "
                "step_exec(",
                "langcc::Ptr<langcc::LexerState> st,",
                "langcc::Ptr<langcc::SymItemVec> emit_dst,",
                "langcc::Ptr<langcc::LexWhitespaceState> ws_state,",
                "langcc::DFAActionId acc,", "langcc::TokenId tok,",
                "langcc::Int& in_i,", "langcc::Int& tok_lo,",
                "langcc::Int& tok_hi);", "langcc::Int proc_mode_loop(",
                "langcc::Ptr<langcc::LexerState> st,",
                "langcc::Ptr<langcc::SymItemVec> emit_dst,",
                "langcc::Int mode_start_pos,", "langcc::Int mode_buf_pos);",
                "}")
            ->as_Decl());

    // ===== lexer::step

    auto tt = lexer_dfa_to_switch_table(dfa, ctx);

    Int n = tt->as_IterMat()->cases_->length();
    Int m =
        tt->as_IterMat()->cases_->operator[](0)->as_IterMat()->cases_->length();

    if (n > 32767) {
      ctx.error(mode, "Lexer DFA too large; only 32767 states supported");
    }

    auto dfa_flat_elems = make_rc<Vec<Int>>();
    for (Int i = 0; i < n; i++) {
      auto ci = tt->as_IterMat()->cases_->operator[](i);
      for (Int j = 0; j < m; j++) {
        auto r = ci->as_IterMat()->cases_->operator[](j)->as_Base()->v_->only();
        dfa_flat_elems->push_back(trunc_u16_s2u(r));
      }
    }
    auto cpp_dfa_init_list = ctx.cc_.gen_cpp_init_list_u16(dfa_flat_elems);

    ctx.cc_.dst_defs_->push_back(
        ctx.cc_
            .qq("Decl", "namespace lang::", src_base_name, "::lexer::", name,
                "{",
                "langcc::DFAVertexId step(langcc::DFAVertexId v, "
                "langcc::DFALabelId lbl) {",
                "static const langcc::u16_array tt = ", cpp_dfa_init_list, ";",
                "return static_cast<langcc::i16>(tt[v * ", fmt_str("{}", m),
                "+ lbl]);", "}", "}")
            ->as_Decl());

    // ===== lexer::acc

    auto cpp_dfa_acc_switch_cases = make_rc<Vec<cc::Node_T>>();
    std::string cpp_acc_action_default = "langcc::DFATable::NO_ACTION";
    std::string cpp_acc_token_default = "langcc::NO_TOKEN";
    for (Int i = 0; i < Graph::N(dfa->G_); i++) {
      std::string cpp_switch_arg = fmt_str("{}", i);
      std::string cpp_acc_action = cpp_acc_action_default;
      std::string cpp_acc_token = cpp_acc_token_default;
      auto acc = dfa->acc_->operator[](i);
      if (acc->length() == 1) {
        cpp_acc_action = fmt_str("{}", acc->only().case_id_);
        if (acc->only().arg_top_id_.is_some()) {
          auto arg = acc->only().arg_top_id_.as_some();
          cpp_acc_token = fmt_str("{}", arg.ind_);
        }
      } else if (acc->length() > 1) {
        AX("Lexer conflict remains"); // conflict
      } else {
        // pass
      }
      cpp_dfa_acc_switch_cases->push_back(ctx.cc_.qq(
          "SwitchCase", "case", cpp_switch_arg, ": {", "return std::make_pair(",
          cpp_acc_action, ",", cpp_acc_token, ");", "}"));
    }

    cpp_dfa_acc_switch_cases->push_back(ctx.cc_.qq(
        "SwitchCase", "default: {", "return std::make_pair(",
        cpp_acc_action_default, ",", cpp_acc_token_default, ");", "}"));

    ctx.cc_.dst_defs_->push_back(
        ctx.cc_
            .qq("Decl", "namespace lang::", src_base_name, "::lexer::", name,
                "{",
                "[[always_inlines]] inline "
                "langcc::DFAActionWithToken",
                "acc(langcc::DFAVertexId v) {", "switch (v) {",
                *cpp_dfa_acc_switch_cases, "}", "}", "}")
            ->as_Decl());

    // ===== lexer::step_exec

    auto fun_ns = make_rc<Vec<std::string>>();
    fun_ns->push_back("lang");
    fun_ns->push_back(src_base_name);
    fun_ns->push_back("lexer");
    fun_ns->push_back(name);
    fun_ns->push_back("step_exec");

    auto cpp_step_exec_switch_cases = make_rc<Vec<cc::Node_T>>();

    for (Int case_id = 0; case_id < mode->cases_->length(); case_id++) {
      auto cpp_case_body = make_rc<Vec<cc::Node_T>>();
      auto case_ = mode->cases_->operator[](case_id);
      if (lexer_instrs_num_stack_changes_max(case_->instrs_) > 1) {
        ctx.error(case_, "Multiple stack changes in lexer instruction");
      }
      if (lexer_instrs_num_emit_match_max(case_->instrs_) > 1) {
        ctx.error(case_, "Multiple emits in lexer instruction");
      }
      for (const auto &instr : *case_->instrs_) {
        lexer_step_exec_compile_instr_acc(cpp_case_body, instr, mode, fun_ns,
                                          cc, ctx);
      }
      cpp_case_body->push_back(ctx.cc_.qq("Stmt", "break;"));
      auto cpp_case = ctx.cc_.qq("SwitchCase", "case", fmt_str("{}", case_id),
                                 ": {", *cpp_case_body, "}");
      cpp_step_exec_switch_cases->push_back(cpp_case);
    }
    cpp_step_exec_switch_cases->push_back(
        ctx.cc_.qq("SwitchCase", "default: { langcc::AX(); }"));

    ctx.cc_.dst_defs_->push_back(
        ctx.cc_
            .qq("Decl", "namespace lang::", src_base_name, "::lexer::", name,
                "{",
                "[[always_inlines]] inline langcc::IntPair "
                "step_exec(",
                "langcc::Ptr<langcc::LexerState> st,",
                "langcc::Ptr<langcc::SymItemVec> emit_dst,",
                "langcc::Ptr<langcc::LexWhitespaceState> ws_state,",
                "langcc::DFAActionId acc,", "langcc::TokenId tok,",
                "langcc::Int& in_i,", "langcc::Int& tok_lo,",
                "langcc::Int& tok_hi) {",

                "auto ret = std::make_pair(-1, -1);",
                "bool mode_switch = false;", "switch (acc) {",
                *cpp_step_exec_switch_cases, "}", "return ret;", "}", "}")
            ->as_Decl());
  }
}

data::Node_T data_gen_type_to_node(DataGenContext data, GenType_T ty) {
  if (ty->is_Bool()) {
    return data_gen_id_string_to_node(data, "bool");
  } else if (ty->is_Int_()) {
    return data_gen_id_string_to_node(data, "Int");
  } else if (ty->is_Nil()) {
    return data_gen_id_string_to_node(data, "Unit");
  } else if (ty->is_String()) {
    return data_gen_id_string_to_node(data, "StrSlice");
  } else if (ty->is_Vector()) {
    auto tc = ty->as_Vector();
    auto node_sub = data_gen_type_to_node(data, tc->elem_ty_);
    return data.Q_->qq_ext(Some<std::string>("Expr"), "Vec(", node_sub, ")");
  } else if (ty->is_Named()) {
    auto id =
        ident_with_prepend(ty->as_Named()->id_, IdentBase::User::make("Node"));
    return data_gen_id_to_node(data, id);
  } else if (ty->is_Optional()) {
    auto tc = ty->as_Optional();
    auto node_sub = data_gen_type_to_node(data, tc->item_ty_);
    return data.Q_->qq_ext(Some<std::string>("Expr"), "Option(", node_sub, ")");
  } else if (ty->is_Datatype() || ty->is_Builtin()) {
    AX();
  } else {
    AX();
  }
}

void data_gen_dtype_acc(DataGenContext data, Ident_T id, GenDatatype_T dt,
                        Ident_T parent) {

  bool override_parent = false;
  if (parent->xs_->length() < id->xs_->length() - 1) {
    AT(parent->xs_->length() == 0);
    override_parent = true;
  }

  bool is_top = false;
  if (id->xs_->length() == 0) {
    is_top = true;
  }

  if (dt->cases_.is_some()) {
    AT(dt->fields_->length() == 0);
  }

  id = ident_with_prepend(id, IdentBase::User::make("Node"));
  auto data_sum_id = data_gen_sum_id_to_node(data, id);

  auto data_fields = make_rc<Vec<data::Node_T>>();

  if (is_top) {
    data_fields->push_back(
        data.Q_->qq_ext(Some<std::string>("Entry"), "id no_hash: Int;"));
    data_fields->push_back(data.Q_->qq_ext(
        Some<std::string>("Entry"), "bounds no_hash: ^langcc::TokenBounds;"));
    data_fields->push_back(
        data.Q_->qq_ext(Some<std::string>("Entry"), "is_top: bool;"));

    // NOTE: following are undefined if is_top is false
    data_fields->push_back(data.Q_->qq_ext(Some<std::string>("Entry"),
                                           "sym: ^langcc::ParserSymId;"));
    data_fields->push_back(data.Q_->qq_ext(Some<std::string>("Entry"),
                                           "attr: ^langcc::ParserAttrMask;"));
    data_fields->push_back(data.Q_->qq_ext(
        Some<std::string>("Entry"), "first_k: ^langcc::ParserLookahead;"));
  }

  for (const auto &[field_id, field_ty] : *dt->fields_) {
    data_fields->push_back(data.Q_->qq_ext(
        Some<std::string>("Entry"), data_gen_id_base_to_string(field_id), ":",
        data_gen_type_to_node(data, field_ty), ";"));
  }

  data_fields->push_back(data.Q_->qq_ext(
      Some<std::string>("Entry"),
      "method write(os: Ref(^std::ostream), flags: ^langcc::FmtFlags): void;"));

  data_fields->push_back(
      data.Q_->qq_ext(Some<std::string>("Entry"),
                      "method write(pb: Ref(^langcc::PrBufStream_T)): void;"));

  if (!override_parent) {
    if (is_top) {
      data.dst_->push_back(data.Q_
                               ->qq_ext(Some<std::string>("Decl"), "def",
                                        data_sum_id, "visit xform {",
                                        *data_fields, "}")
                               ->as_Decl());
    } else {
      data.dst_->push_back(data.Q_
                               ->qq_ext(Some<std::string>("Decl"), "def",
                                        data_sum_id, "{", *data_fields, "}")
                               ->as_Decl());
    }
  } else {
    AT(!is_top);
    data.dst_->push_back(data.Q_
                             ->qq_ext(Some<std::string>("Decl"), "def",
                                      data_sum_id, "<: Node {", *data_fields,
                                      "}")
                             ->as_Decl());
  }
}

void lang_emit_datatype_defs(LangCompileContext &ctx, HeaderMode header_mode) {
  for (const auto &[id, dt] : *ctx.gen_dt_map_) {
    auto parent = id;
    if (id->xs_->length() > 0) {
      parent = ctx.gen_dt_parent_mapping_->operator[](id).first;
    }
    data_gen_dtype_acc(ctx.data_, id, dt->as_Datatype()->dt_, parent);
  }

  auto data_sym = make_rc<Gensym>();

  auto data_mod = ctx.data_.Q_->qq_ext(Some<std::string>("Module"),
                                       "namespace lang::", ctx.src_base_name_,
                                       "{", *ctx.data_.dst_, "}");

  LOG(2, " === Datatype decl module:\n{}\n\n", data_mod);

  auto data_res = compile_data_defs(data_mod, None<std::string>(), header_mode);

  if (data_res.hpp_decls.is_some()) {
    for (const auto &decl :
         *data_res.hpp_decls.as_some()->as_Module()->decls_) {
      ctx.cc_.dst_decls_->push_back(decl);
    }
  }

  if (data_res.cpp_decls.is_some()) {
    for (const auto &decl :
         *data_res.cpp_decls.as_some()->as_Module()->decls_) {
      ctx.cc_.dst_defs_->push_back(decl);
    }
  }
}

void lang_emit_writer_defs(LangCompileContext &ctx) {
  for (const auto &[id, wr] : *ctx.gen_wr_map_) {
    auto id_nm = lower_name_ident_struct(id);

    auto cpp_write_stmts = make_rc<Vec<cc::Node_T>>();

    auto fun_ns = make_rc<Vec<std::string>>();
    fun_ns->push_back("lang");
    fun_ns->push_back(ctx.src_base_name_);
    fun_ns->extend(id_nm);
    fun_ns->push_back("write");

    parser_lr_write_impl_gen_cpp_instr(cpp_write_stmts, wr,
                                       ctx.cc_.qq_expr("x"), fun_ns,
                                       ctx.src_base_name_, ctx.cc_, ctx);

    ctx.cc_.dst_defs_->push_back(
        ctx.cc_.Q_
            ->qq_ext(
                Some<std::string>("Decl"), "void lang::", ctx.src_base_name_,
                "::", *id_nm, "::write(langcc::PrBufStream_T& pb) {",
                "auto x = this->rc_from_this_poly<lang::", ctx.src_base_name_,
                "::", *id_nm, ">();", *cpp_write_stmts, "}")
            ->as_Decl());

    ctx.cc_.dst_defs_->push_back(
        ctx.cc_.Q_
            ->qq_ext(
                Some<std::string>("Decl"), "void lang::", ctx.src_base_name_,
                "::", *id_nm,
                "::write(std::ostream& os, langcc::FmtFlags flags) {",
                "auto pb = langcc::PrBufStream::make(",
                "langcc::make_rc<langcc::Vec<langcc::PrBufStreamItem_T>>());",
                "this->write(pb);",
                "pb->distill(os, flags);"
                "}")
            ->as_Decl());
  }
}

std::string parser_lr_impl_id_gen_cpp(CppGenContext &cc, ProdId_T prod_id,
                                      LangCompileContext &ctx) {

  if (prod_id->is_Start()) {
    auto lr_sym = LRSym::Base::make(prod_id->as_Start()->sym_);
    return fmt_str("_parse_proc_start_{}",
                   grammar_sym_to_ind_flat(ctx, lr_sym));
  } else if (prod_id->is_Explicit()) {
    auto cc = prod_id->as_Explicit();
    return fmt_str("_parse_proc_{}_{}", cc->rule_ind_, cc->sub_);
  } else if (prod_id->is_GenCPS()) {
    auto pc = prod_id->as_GenCPS();
    auto r = parser_lr_impl_id_gen_cpp(cc, pc->orig_, ctx);
    return fmt_str("{}_{}", r, pc->uniq_ind_);
  } else {
    AX();
  }
}

void parser_lr_unwind_impl_gen_cpp_push_res_fwd(Vec_T<cc::Node_T> &cpp_dst_proc,
                                                const cc::Node_T &v_res,
                                                CppGenContext &cc) {

  cc.qq_stmt_acc(cpp_dst_proc, "st->Sr_addr_[sr_len] = ", v_res, ";");
  cc.qq_stmt_acc(cpp_dst_proc, "++sr_len;");
}

void parser_lr_unwind_impl_gen_cpp_push_res_rev(Vec_T<cc::Node_T> &cpp_dst_proc,
                                                const cc::Node_T &v_res,
                                                CppGenContext &cc) {

  cc.qq_stmt_acc(cpp_dst_proc, "st->Sb_addr_[sb_len] = ", v_res, ";");
  cc.qq_stmt_acc(cpp_dst_proc, "++sb_len;");
}

std::pair<cc::Node_T, cc::Node_T> parser_lr_unwind_impl_gen_name_to_cpp_struct(
    Ident_T id, const std::string &src_base_name, CppGenContext &cc) {

  auto ret_struct = make_rc<Vec<std::string>>();
  ret_struct->push_back("lang");
  ret_struct->push_back(src_base_name);
  ret_struct->push_back("Node");
  for (const auto &x : *id->xs_) {
    ret_struct->push_back(fmt_str("{}", x));
  }
  auto ret_ns = ret_struct->clone_rc();
  ret_struct->push_back("_T");
  return std::make_pair(name_to_cpp_direct(ret_ns, cc),
                        name_to_cpp_direct(ret_struct, cc));
}

cc::Node_T parser_lr_unwind_type_to_cpp(CppGenContext &cc, bool is_top,
                                        GenType_T ty,
                                        const std::string &src_base_name,
                                        LangCompileContext &ctx) {

  if (ty->is_Named()) {
    AT(!is_top);
    auto [cpp_prod_ns, cpp_prod_struct_ty] =
        parser_lr_unwind_impl_gen_name_to_cpp_struct(ty->as_Named()->id_,
                                                     src_base_name, cc);
    return cc.qq_expr("langcc::rc_ptr<", cpp_prod_struct_ty, ">");
  } else if (ty->is_Vector()) {
    auto ret_elem_ty = parser_lr_unwind_type_to_cpp(
        cc, false, ty->as_Vector()->elem_ty_, src_base_name, ctx);
    if (is_top) {
      return cc.qq_expr("langcc::Vec<", ret_elem_ty, ">");
    } else {
      return cc.qq_expr("langcc::Vec_T<", ret_elem_ty, ">");
    }
  } else if (ty->is_Bool()) {
    return cc.qq_expr("bool");
  } else if (ty->is_String()) {
    return cc.qq_expr("langcc::StrSlice");
  } else if (ty->is_Optional()) {
    auto ret_item_ty = parser_lr_unwind_type_to_cpp(
        cc, false, ty->as_Optional()->item_ty_, src_base_name, ctx);
    return cc.qq_expr("langcc::Option_T<", ret_item_ty, ">");
  } else if (ty->is_Nil()) {
    return cc.qq_expr("langcc::Unit");
  } else {
    AX();
  }
}

cc::Node_T parser_lr_unwind_impl_gen_cpp_acc_type_rec(
    Vec_T<cc::Node_T> &cpp_dst_unwind, const cc::Node_T &val, bool do_take,
    GenType_T ty, const GenName &fun_ns, const std::string &src_base_name,
    CppGenContext &cc, LangCompileContext &ctx) {

  if (ty->is_Named()) {
    auto [_, cpp_prod_struct_ty] = parser_lr_unwind_impl_gen_name_to_cpp_struct(
        ty->as_Named()->id_, src_base_name, cc);
    auto res_ptr = cc.qq_expr("reinterpret_cast<langcc::Ptr<",
                              cpp_prod_struct_ty, ">>(", val, ".v_)");
    auto res_init = res_ptr;
    if (do_take) {
      res_init = cc.qq_expr(res_init, "->rc_from_this_poly<",
                            cpp_prod_struct_ty, ">()");
    }
    auto res = cc.qq_expr(cc.gen_id_fresh(fun_ns, "x"));
    cc.qq_stmt_acc(cpp_dst_unwind, "auto", res, "=", res_init, ";");
    if (do_take) {
      cc.qq_stmt_acc(cpp_dst_unwind, res, ".decref();");
    }
    return res;

  } else if (ty->is_String()) {
    auto res_site_init =
        cc.qq_expr("langcc::result_decode_token_bounds(", val, ")");
    auto res_site = cc.qq_expr(cc.gen_id_fresh(fun_ns, "x_site"));
    cc.qq_stmt_acc(cpp_dst_unwind, "auto", res_site, "=", res_site_init, ";");
    auto res_init = cc.qq_expr("st->fetch_token(", res_site, ".lo_)");
    auto res = cc.qq_expr(cc.gen_id_fresh(fun_ns, "x"));
    cc.qq_stmt_acc(cpp_dst_unwind, "auto", res, "=", res_init, ";");
    return res;

  } else if (ty->is_Optional()) {
    auto cpp_item_ty = parser_lr_unwind_type_to_cpp(
        cc, false, ty->as_Optional()->item_ty_, src_base_name, ctx);
    auto cpp_ret_ty = cc.qq_expr("langcc::Option_T<", cpp_item_ty, ">");

    auto res_ptr = cc.qq_expr("reinterpret_cast<langcc::Ptr<", cpp_ret_ty,
                              ">>(", val, ".v_)");
    auto res_init = res_ptr;
    if (do_take) {
      res_init = cc.qq_expr("langcc::rc_from_ptr_ext_take<", cpp_ret_ty, ">(",
                            res_ptr, ", st->unw_arena_)");
    }
    auto res = cc.qq_expr(cc.gen_id_fresh(fun_ns, "x"));
    cc.qq_stmt_acc(cpp_dst_unwind, "auto", res, "=", res_init, ";");
    return res;

  } else if (ty->is_Vector()) {
    auto cpp_elem_ty = parser_lr_unwind_type_to_cpp(
        cc, false, ty->as_Vector()->elem_ty_, src_base_name, ctx);
    auto cpp_ret_ty = cc.qq_expr("langcc::Vec<", cpp_elem_ty, ">");

    auto res_ptr = cc.qq_expr("reinterpret_cast<langcc::Ptr<", cpp_ret_ty,
                              ">>(", val, ".v_)");
    auto res_init = res_ptr;
    if (do_take) {
      res_init = cc.qq_expr("langcc::rc_from_ptr_ext<", cpp_ret_ty, ">(",
                            res_ptr, ", st->unw_arena_)");
    }
    auto res = cc.qq_expr(cc.gen_id_fresh(fun_ns, "x"));
    cc.qq_stmt_acc(cpp_dst_unwind, "auto", res, "=", res_init, ";");
    if (do_take) {
      cc.qq_stmt_acc(cpp_dst_unwind, res, ".decref();");
    }
    return res;

  } else if (ty->is_Bool()) {
    auto res_ptr =
        cc.qq_expr("reinterpret_cast<langcc::Ptr<bool>>(", val, ".v_)");
    auto res_init = res_ptr;
    if (do_take) {
      res_init = cc.qq_expr("langcc::rc_from_ptr_ext_take<bool>(", res_ptr,
                            ", st->unw_arena_)");
    }
    auto res = cc.qq_expr(cc.gen_id_fresh(fun_ns, "x"));
    cc.qq_stmt_acc(cpp_dst_unwind, "auto", res, "=", res_init, ";");
    return res;

  } else if (ty->is_Nil()) {
    auto res = cc.qq_expr(cc.gen_id_fresh(fun_ns, "x"));
    cc.qq_stmt_acc(cpp_dst_unwind, "auto", res, "= langcc::Unit();");
    return res;

  } else {
    LG_ERR(" >> ty: {}", ty);
    AX();
  }
}

void parser_lr_unwind_impl_gen_cpp_acc_type_rec_dummy(
    Vec_T<cc::Node_T> &cpp_dst_unwind, const cc::Node_T &val, bool do_take,
    GenType_T ty, const GenName &fun_ns, const std::string &src_base_name,
    CppGenContext &cc, LangCompileContext &ctx) {

  if (ty->is_String() || ty->is_Nil()) {
    // pass (not allocated on the heap)
  } else {
    parser_lr_unwind_impl_gen_cpp_acc_type_rec(cpp_dst_unwind, val, do_take, ty,
                                               fun_ns, src_base_name, cc, ctx);
  }
}

void parser_lr_unwind_impl_gen_cpp_push_res_cons_fwd(
    Vec_T<cc::Node_T> &cpp_dst_unwind, const cc::Node_T &ret,
    const cc::Node_T &bounds, CppGenContext &cc) {

  auto res_item = cc.qq_expr("res_item");
  cc.qq_stmt_acc(cpp_dst_unwind, "auto res_item = langcc::Result_T(", ret, ",",
                 bounds, ");");

  cc.qq_stmt_acc(cpp_dst_unwind, "st->Sr_addr_[sr_len] = res_item;");
  cc.qq_stmt_acc(cpp_dst_unwind, "++sr_len;");
}

Vec_T<cc::Node_T>
parser_lr_unwind_impl_gen_cpp_make_args(const cc::Node_T &cpp_bounds,
                                        CppGenContext &cc) {

  auto ret = make_rc<Vec<cc::Node_T>>();
  ret->push_back(cc.qq_expr("st->unw_arena_"));
  ret->push_back(cc.qq_expr("st->gen()->gen()"));
  ret->push_back(cpp_bounds);
  ret->push_back(cc.qq_expr("false"));                     // is_top
  ret->push_back(cc.qq_expr("-1"));                        // sym
  ret->push_back(cc.qq_expr("langcc::ParserAttrMask()"));  // attr
  ret->push_back(cc.qq_expr("langcc::ParserLookahead()")); // first_k
  return ret;
}

void parser_lr_unwind_impl_gen_cpp_acc(Vec_T<cc::Node_T> &cpp_dst_proc,
                                       CppGenContext &cc, Prod_T prod_cps,
                                       Prod_T prod_flat, UnwindInstr_T instr,
                                       const GenName &fun_ns,
                                       const std::string &src_base_name,
                                       LangCompileContext &ctx) {

  auto nonterm_ind =
      grammar_sym_to_ind_flat(ctx, LRSym::Base::make(prod_cps->lhs_));

  Int N_cps = prod_cps->rhs_->length();
  Int N_flat = prod_flat->rhs_->length();

  cc.qq_stmt_acc(cpp_dst_proc, "langcc::Int ss_len = st->Ss_len_;");
  cc.qq_stmt_acc(cpp_dst_proc, "langcc::Int sr_len = st->Sr_len_;");
  cc.qq_stmt_acc(cpp_dst_proc, "langcc::Int sb_len = st->Sb_len_;");
  cc.qq_stmt_acc(cpp_dst_proc, "langcc::Int sv_len = st->Sv_len_;");

  cc.qq_stmt_acc(cpp_dst_proc, "sv_len = sv_len - ", fmt_str("{}", N_cps), ";");

  cc.qq_stmt_acc(cpp_dst_proc,
                 "langcc::Int start_pos = st->Sv_addr_[sv_len - 1].pos_;");

  auto cpp_rhs_sym = make_rc<Vec<cc::Node_T>>();
  for (Int i = 0; i < N_cps; i++) {
    auto name_i = fmt_str("sym{}", i);
    cc.qq_stmt_acc(cpp_dst_proc, "auto", name_i, "= st->Ss_addr_[ss_len - ",
                   fmt_str("{}", i + 1), "];");
    cpp_rhs_sym->push_front(cc.qq_expr(name_i));
  }
  cc.qq_stmt_acc(cpp_dst_proc, "ss_len = ss_len - ", fmt_str("{}", N_cps), ";");

  auto cpp_rhs_res = make_rc<Vec<cc::Node_T>>();
  for (Int i = 0; i < N_cps; i++) {
    auto name_i = fmt_str("res{}", i);
    cc.qq_stmt_acc(cpp_dst_proc, "auto", name_i, "= st->Sr_addr_[sr_len - ",
                   fmt_str("{}", i + 1), "];");
    cpp_rhs_res->push_front(cc.qq_expr(name_i));
  }
  cc.qq_stmt_acc(cpp_dst_proc, "sr_len = sr_len - ", fmt_str("{}", N_cps), ";");

  for (Int i = N_cps; i < N_flat; i++) {
    auto name_i = fmt_str("res{}", i);
    cc.qq_stmt_acc(cpp_dst_proc, "auto", name_i, "= st->Sb_addr_[sb_len - ",
                   fmt_str("{}", (i - N_cps) + 1), "];");
    cpp_rhs_res->push_back(cc.qq_expr(name_i));
  }
  if (N_flat > N_cps) {
    cc.qq_stmt_acc(cpp_dst_proc, "sb_len = sb_len - ",
                   fmt_str("{}", N_flat - N_cps), ";");
  }

  AT(cpp_rhs_res->length() >= N_flat);

  if (prod_flat->lhs_->is_Start()) {
    AT(prod_flat->rhs_->length() == 2);
    cc.qq_stmt_acc(cpp_dst_proc, "st->enroll_final_sym(",
                   cpp_rhs_sym->operator[](1), ");");
  }

  auto cpp_bounds_hi = cc.qq_expr("start_pos");
  if (N_flat > 0) {
    cpp_bounds_hi = cc.qq_expr(
        cpp_rhs_res->operator[](cpp_rhs_res->length() - 1), ".bounds_.hi_");
  }
  auto cpp_bounds =
      cc.qq_expr("langcc::TokenBounds(start_pos,", cpp_bounds_hi, ")");

  if (instr->is_Identity()) {
    auto v_res = cpp_rhs_res->operator[](0);
    parser_lr_unwind_impl_gen_cpp_push_res_fwd(cpp_dst_proc, v_res, cc);

  } else if (instr->is_ItemCons()) {
    AR_eq(N_flat, 1);
    auto src_val = cpp_rhs_res->operator[](0);

    auto item_ty = instr->as_ItemCons()->item_ty_;

    auto ret_val = parser_lr_unwind_impl_gen_cpp_acc_type_rec(
        cpp_dst_proc, src_val, true, item_ty, fun_ns, src_base_name, cc, ctx);

    auto cpp_make_args =
        parser_lr_unwind_impl_gen_cpp_make_args(cpp_bounds, ctx.cc_);
    cpp_make_args->push_back(ret_val);

    auto ret = cc.qq_expr("ret");
    auto [cpp_prod_ns, cpp_prod_struct_ty] =
        parser_lr_unwind_impl_gen_name_to_cpp_struct(instr->as_ItemCons()->id_,
                                                     src_base_name, cc);
    auto cpp_make_call = cc.gen_cpp_fun_call(
        cc.qq_expr(cpp_prod_ns, "::make_ext"), cpp_make_args);
    cc.qq_stmt_acc(cpp_dst_proc, "auto ret =", cpp_make_call, ";");
    cc.qq_stmt_acc(cpp_dst_proc, "ret.incref();");

    auto ret_raw = cc.qq_expr(ret, ".get()");

    parser_lr_unwind_impl_gen_cpp_push_res_cons_fwd(cpp_dst_proc, ret_raw,
                                                    cpp_bounds, cc);

  } else if (instr->is_Nil()) {
    auto v_res = cc.qq_expr("nullptr");
    parser_lr_unwind_impl_gen_cpp_push_res_cons_fwd(cpp_dst_proc, v_res,
                                                    cpp_bounds, cc);

  } else if (instr->is_SelectIndex()) {
    auto ic = instr->as_SelectIndex();
    AT(ic->rhs_tys_->length() == N_flat);
    auto v_res = cpp_rhs_res->operator[](ic->i_);
    for (Int i = 0; i < ic->rhs_tys_->length(); i++) {
      if (i == ic->i_) {
        continue;
      }
      parser_lr_unwind_impl_gen_cpp_acc_type_rec_dummy(
          cpp_dst_proc, cpp_rhs_res->operator[](i), true,
          ic->rhs_tys_->operator[](i), fun_ns, src_base_name, cc, ctx);
    }
    parser_lr_unwind_impl_gen_cpp_push_res_fwd(cpp_dst_proc, v_res, cc);

  } else if (instr->is_SumCons()) {
    AR_eq(N_flat, 1);
    auto v_res = cpp_rhs_res->operator[](0);
    parser_lr_unwind_impl_gen_cpp_push_res_fwd(cpp_dst_proc, v_res, cc);

  } else if (instr->is_SumConsItem()) {
    AR_eq(N_flat, 1);
    auto src_val = cpp_rhs_res->operator[](0);

    auto item_ty = instr->as_SumConsItem()->item_ty_;

    auto ret_val = parser_lr_unwind_impl_gen_cpp_acc_type_rec(
        cpp_dst_proc, src_val, true, item_ty, fun_ns, src_base_name, cc, ctx);

    auto cpp_make_args =
        parser_lr_unwind_impl_gen_cpp_make_args(cpp_bounds, ctx.cc_);
    cpp_make_args->push_back(ret_val);

    auto ret = cc.qq_expr("ret");
    auto [cpp_prod_ns, cpp_prod_struct_ty] =
        parser_lr_unwind_impl_gen_name_to_cpp_struct(
            ident_with_append(instr->as_SumConsItem()->id_,
                              instr->as_SumConsItem()->case_id_),
            src_base_name, cc);
    auto cpp_make_call = cc.gen_cpp_fun_call(
        cc.qq_expr(cpp_prod_ns, "::make_ext"), cpp_make_args);
    cc.qq_stmt_acc(cpp_dst_proc, "auto ret =", cpp_make_call, ";");
    cc.qq_stmt_acc(cpp_dst_proc, "ret.incref();");

    auto ret_raw = cc.qq_expr(ret, ".get()");

    parser_lr_unwind_impl_gen_cpp_push_res_cons_fwd(cpp_dst_proc, ret_raw,
                                                    cpp_bounds, cc);

  } else if (instr->is_True()) {
    auto ic = instr->as_True();
    AR_eq(N_flat, 1);
    auto ret = cc.qq_expr("ret");
    parser_lr_unwind_impl_gen_cpp_acc_type_rec_dummy(
        cpp_dst_proc, cpp_rhs_res->operator[](0), true, ic->rhs_ty_, fun_ns,
        src_base_name, cc, ctx);
    cc.qq_stmt_acc(
        cpp_dst_proc,
        "auto ret = langcc::make_rc_inc_ext<bool>(st->unw_arena_, true);");
    parser_lr_unwind_impl_gen_cpp_push_res_cons_fwd(cpp_dst_proc, ret,
                                                    cpp_bounds, cc);

  } else if (instr->is_False()) {
    AR_eq(N_flat, 0);
    auto ret = cc.qq_expr("ret");
    cc.qq_stmt_acc(
        cpp_dst_proc,
        "auto ret = langcc::make_rc_inc_ext<bool>(st->unw_arena_, false);");
    parser_lr_unwind_impl_gen_cpp_push_res_cons_fwd(cpp_dst_proc, ret,
                                                    cpp_bounds, cc);

  } else if (instr->is_OptSome()) {
    auto ic = instr->as_OptSome();
    AR_eq(N_flat, 1);
    auto cpp_item_ty = parser_lr_unwind_type_to_cpp(cc, false, ic->item_ty_,
                                                    src_base_name, ctx);
    auto cpp_ret_ty = parser_lr_unwind_type_to_cpp(
        cc, false, GenType::Optional::make(ic->item_ty_), src_base_name, ctx);
    auto v_raw = cpp_rhs_res->operator[](0);
    auto v = parser_lr_unwind_impl_gen_cpp_acc_type_rec(
        cpp_dst_proc, v_raw, true, ic->item_ty_, fun_ns, src_base_name, cc,
        ctx);
    auto ret = cc.qq_expr("ret");
    auto ret_val = cc.qq_expr("langcc::Some<", cpp_item_ty, ">(", v, ")");
    cc.qq_stmt_acc(cpp_dst_proc, "auto ret = langcc::make_rc_inc_ext<",
                   cpp_ret_ty, ">(st->unw_arena_,", ret_val, ");");
    parser_lr_unwind_impl_gen_cpp_push_res_cons_fwd(cpp_dst_proc, ret,
                                                    cpp_bounds, cc);

  } else if (instr->is_OptNone()) {
    auto ic = instr->as_OptNone();
    auto cpp_item_ty = parser_lr_unwind_type_to_cpp(cc, false, ic->item_ty_,
                                                    src_base_name, ctx);
    auto cpp_ret_ty = parser_lr_unwind_type_to_cpp(
        cc, false, GenType::Optional::make(ic->item_ty_), src_base_name, ctx);
    auto ret = cc.qq_expr("ret");
    auto ret_val = cc.qq_expr("langcc::None<", cpp_item_ty, ">()");
    cc.qq_stmt_acc(cpp_dst_proc, "auto ret = langcc::make_rc_inc_ext<",
                   cpp_ret_ty, ">(st->unw_arena_,", ret_val, ");");
    parser_lr_unwind_impl_gen_cpp_push_res_cons_fwd(cpp_dst_proc, ret,
                                                    cpp_bounds, cc);

  } else if (instr->is_ProdCons()) {
    auto ic = instr->as_ProdCons();
    AT(ic->rhs_tys_->length() == N_flat);
    auto fields_map_rev = key_value_rev(ic->args_map_);
    auto vs_fields = make_rc<Map<IdentBase_T, cc::Node_T>>();

    for (Int i = 0; i < N_flat; i++) {
      if (fields_map_rev->contains_key(i)) {
        auto field_name = fields_map_rev->operator[](i)->only();
        auto v_res = cpp_rhs_res->operator[](i);
        vs_fields->insert(field_name, v_res);
      } else {
        parser_lr_unwind_impl_gen_cpp_acc_type_rec_dummy(
            cpp_dst_proc, cpp_rhs_res->operator[](i), true,
            ic->rhs_tys_->operator[](i), fun_ns, src_base_name, cc, ctx);
      }
    }

    auto ret_type = ctx.gen_dt_map_->operator[](ic->id_)->as_Datatype();

    auto cpp_make_args =
        parser_lr_unwind_impl_gen_cpp_make_args(cpp_bounds, ctx.cc_);
    for (const auto &[field_name, _] : *ic->args_map_) {
      auto field_type = ret_type->dt_->fields_->operator[](field_name);
      auto src_val = vs_fields->operator[](field_name);
      auto ret_val = parser_lr_unwind_impl_gen_cpp_acc_type_rec(
          cpp_dst_proc, src_val, true, field_type, fun_ns, src_base_name, cc,
          ctx);
      cpp_make_args->push_back(ret_val);
    }

    auto ret = cc.qq_expr("ret");
    auto [cpp_prod_ns, cpp_prod_struct_ty] =
        parser_lr_unwind_impl_gen_name_to_cpp_struct(ic->id_, src_base_name,
                                                     cc);
    auto cpp_make_call = cc.gen_cpp_fun_call(
        cc.qq_expr(cpp_prod_ns, "::make_ext"), cpp_make_args);
    cc.qq_stmt_acc(cpp_dst_proc, "auto ret =", cpp_make_call, ";");
    cc.qq_stmt_acc(cpp_dst_proc, "ret.incref();");

    auto ret_raw = cc.qq_expr(ret, ".get()");

    parser_lr_unwind_impl_gen_cpp_push_res_cons_fwd(cpp_dst_proc, ret_raw,
                                                    cpp_bounds, cc);

  } else if (instr->is_VecCons() || instr->is_VecConsDelim()) {
    Ident_T ident;
    GenType_T elem_ty;
    cc::Node_T vs;

    if (instr->is_VecCons()) {
      // y yl
      ident = instr->as_VecCons()->id_;
      elem_ty = instr->as_VecCons()->elem_ty_;
      auto item0 = parser_lr_unwind_impl_gen_cpp_acc_type_rec(
          cpp_dst_proc, cpp_rhs_res->operator[](0), true, elem_ty, fun_ns,
          src_base_name, cc, ctx);
      vs = parser_lr_unwind_impl_gen_cpp_acc_type_rec(
          cpp_dst_proc, cpp_rhs_res->operator[](1), false,
          GenType::Vector::make(elem_ty), fun_ns, src_base_name, cc, ctx);
      cc.qq_stmt_acc(cpp_dst_proc, vs, "->push_front(", item0, ");");

    } else if (instr->is_VecConsDelim()) {
      // y d yl
      auto ic = instr->as_VecConsDelim();
      ident = instr->as_VecConsDelim()->id_;
      elem_ty = instr->as_VecConsDelim()->elem_ty_;
      auto item0 = parser_lr_unwind_impl_gen_cpp_acc_type_rec(
          cpp_dst_proc, cpp_rhs_res->operator[](0), true, elem_ty, fun_ns,
          src_base_name, cc, ctx);
      parser_lr_unwind_impl_gen_cpp_acc_type_rec_dummy(
          cpp_dst_proc, cpp_rhs_res->operator[](1), true, ic->delim_ty_, fun_ns,
          src_base_name, cc, ctx);
      vs = parser_lr_unwind_impl_gen_cpp_acc_type_rec(
          cpp_dst_proc, cpp_rhs_res->operator[](2), false,
          GenType::Vector::make(elem_ty), fun_ns, src_base_name, cc, ctx);
      cc.qq_stmt_acc(cpp_dst_proc, vs, "->push_front(", item0, ");");

    } else {
      AX();
    }

    parser_lr_unwind_impl_gen_cpp_push_res_cons_fwd(cpp_dst_proc, vs,
                                                    cpp_bounds, cc);

  } else if (instr->is_VecEmpty() || instr->is_VecSingle() ||
             instr->is_VecSingleDelim()) {
    Ident_T ident;
    GenType_T elem_ty;

    if (instr->is_VecEmpty()) {
      ident = instr->as_VecEmpty()->id_;
      elem_ty = instr->as_VecEmpty()->elem_ty_;
    } else if (instr->is_VecSingle()) {
      ident = instr->as_VecSingle()->id_;
      elem_ty = instr->as_VecSingle()->elem_ty_;
    } else if (instr->is_VecSingleDelim()) {
      ident = instr->as_VecSingleDelim()->id_;
      elem_ty = instr->as_VecSingleDelim()->elem_ty_;
    } else {
      AX();
    }

    auto cpp_vs_type = parser_lr_unwind_type_to_cpp(
        cc, true, GenType::Vector::make(elem_ty), src_base_name, ctx);
    auto vs_init = cc.qq_expr("langcc::make_rc_inc_ext<", cpp_vs_type,
                              ">(st->unw_arena_, st->unw_arena_, 0, 1, "
                              "langcc::_Vec_constr_internal())");
    auto vs = cc.qq_expr(cc.gen_id_fresh(fun_ns, "vs"));
    cc.qq_stmt_acc(cpp_dst_proc, "auto", vs, "=", vs_init, ";");

    if (instr->is_VecEmpty()) {
      // pass

    } else if (instr->is_VecSingle()) {
      auto item_raw = cpp_rhs_res->operator[](0);
      auto item = parser_lr_unwind_impl_gen_cpp_acc_type_rec(
          cpp_dst_proc, item_raw, true, elem_ty, fun_ns, src_base_name, cc,
          ctx);
      cc.qq_stmt_acc(cpp_dst_proc, vs, "->push_back(", item, ");");

    } else if (instr->is_VecSingleDelim()) {
      auto ic = instr->as_VecSingleDelim();
      {
        auto item_raw = cpp_rhs_res->operator[](0);
        auto item = parser_lr_unwind_impl_gen_cpp_acc_type_rec(
            cpp_dst_proc, item_raw, true, elem_ty, fun_ns, src_base_name, cc,
            ctx);
        cc.qq_stmt_acc(cpp_dst_proc, vs, "->push_back(", item, ");");
      }
      parser_lr_unwind_impl_gen_cpp_acc_type_rec_dummy(
          cpp_dst_proc, cpp_rhs_res->operator[](1), true, ic->delim_ty_, fun_ns,
          src_base_name, cc, ctx);

    } else {
      AX();
    }

    parser_lr_unwind_impl_gen_cpp_push_res_cons_fwd(cpp_dst_proc, vs,
                                                    cpp_bounds, cc);

  } else {
    LG_ERR(" >> instr: {}", instr);
    AX();
  }

  Int i = N_cps - 1;
  while (i >= N_flat) {
    // Note: fwd pushes at most once, but rev pushes up to cps_flat_diff_max
    // times. Must allocate space in parse_rt accordingly.
    parser_lr_unwind_impl_gen_cpp_push_res_rev(cpp_dst_proc,
                                               cpp_rhs_res->operator[](i), cc);
    --i;
  }

  auto dom = ctx.parser_attr_domains_->operator[](prod_cps->lhs_);
  auto attr_keys = make_rc<Vec<AttrKey_T>>();
  for (const auto &[k, _] : *dom) {
    attr_keys->push_back(k);
  }
  auto n_attr = attr_keys->length();
  AT(n_attr <= 16); // We use u8[16] in the generated code

  auto cpp_ret_sym_init =
      cc.qq_expr("{", cc.qq_expr(fmt_str("{}", nonterm_ind)), ", start_pos}");
  auto cpp_ret_sym = cc.qq_expr("ret_sym");
  cc.qq_stmt_acc(cpp_dst_proc, "langcc::SymItem", cpp_ret_sym, "=",
                 cpp_ret_sym_init, ";");

  auto cpp_ret_attr = cc.qq_expr(cpp_ret_sym, ".attr_");

  for (Int i = 0; i < n_attr; i++) {
    auto attr_key = attr_keys->operator[](i);
    auto attr_type = dom->operator[](attr_key);
    auto attr_val_max = attr_type_val_max(attr_type);
    AT(attr_val_max < 256); // We use u8 in the generated code

    auto cpp_val_lhs = cc.qq_expr(cpp_ret_attr, "[", fmt_str("{}", i), "]");
    cc.qq_stmt_acc(cpp_dst_proc, cpp_val_lhs, "=", fmt_str("{}", attr_val_max),
                   ";");

    for (const auto &constr : *ctx.Gr_cps_prod_constrs_->operator[](prod_cps)) {
      if (constr->is_LhsLeq()) {
        auto vc = constr->as_LhsLeq();
        if (val_hash(vc->k_) != val_hash(attr_key)) {
          continue;
        }
        auto cpp_val_bound = cc.qq_expr(fmt_str("{}", attr_val_to_int(vc->v_)));
        auto cpp_val_new = cc.qq_expr("std::min<langcc::Int>(", cpp_val_lhs,
                                      ",", cpp_val_bound, ")");
        cc.qq_stmt_acc(cpp_dst_proc, cpp_val_lhs, "=", cpp_val_new, ";");

      } else if (constr->is_Implies()) {
        auto vc = constr->as_Implies();
        if (val_hash(vc->kl_) != val_hash(attr_key)) {
          continue;
        }
        auto sym_i = prod_cps->rhs_->operator[](vc->i_);
        auto k_rhs_ind = attr_key_to_index(sym_i, vc->kr_, ctx);
        auto cpp_val_rhs = cc.qq_expr(cpp_rhs_sym->operator[](vc->i_),
                                      ".attr_[", fmt_str("{}", k_rhs_ind), "]");
        auto cpp_val_new = cc.qq_expr("std::min<langcc::Int>(", cpp_val_lhs,
                                      ",", cpp_val_rhs, ")");
        cc.qq_stmt_acc(cpp_dst_proc, cpp_val_lhs, "=", cpp_val_new, ";");

      } else if (constr->is_RhsGeq()) {
        // pass

      } else {
        AX();
      }
    }
  }

  cc.qq_stmt_acc(cpp_dst_proc, "st->Ss_len_ = ss_len;");
  cc.qq_stmt_acc(cpp_dst_proc, "st->Sr_len_ = sr_len;");
  cc.qq_stmt_acc(cpp_dst_proc, "st->Sb_len_ = sb_len;");
  cc.qq_stmt_acc(cpp_dst_proc, "st->Sv_len_ = sv_len;");

  cc.qq_stmt_acc(cpp_dst_proc, "return", cpp_ret_sym, ";");
}

cc::Node_T parser_lr_unwind_impl_gen_cpp(CppGenContext &cc, Prod_T prod_cps,
                                         Prod_T prod_flat,
                                         LangCompileContext &ctx,
                                         const std::string &src_base_name) {

  auto proc_name = parser_lr_impl_id_gen_cpp(cc, prod_cps->prod_id_, ctx);

  UnwindInstr_T instr;
  if (prod_flat->prod_id_->is_Start()) {
    auto rhs_tys = make_rc<Vec<GenType_T>>();
    rhs_tys->push_back(GenType::Nil::make());
    rhs_tys->push_back(GenType::Nil::make()); // (not used)
    instr = UnwindInstr::SelectIndex::make(1, rhs_tys);
  } else if (prod_flat->prod_id_->is_Explicit()) {
    AT(ctx.gen_rd_map_->contains_key(prod_flat));
    instr = ctx.gen_rd_map_->operator[](prod_flat);
  } else {
    AX();
  }

  auto fun_ns = make_rc<Vec<std::string>>();
  fun_ns->push_back(proc_name);

  auto cpp_proc_body = make_rc<Vec<cc::Node_T>>();
  parser_lr_unwind_impl_gen_cpp_acc(cpp_proc_body, cc, prod_cps, prod_flat,
                                    instr, fun_ns, src_base_name, ctx);

  cc.dst_defs_->push_back(
      cc.Q_
          ->qq_ext(Some<std::string>("Decl"), "namespace lang::", src_base_name,
                   "::parser {", "[[noinlines]] langcc::SymItem", proc_name,
                   "(langcc::ParserProcStatePtr st) {", *cpp_proc_body, "}",
                   "}")
          ->as_Decl());

  return cc.Q_->qq_ext(Some<std::string>("Expr"), proc_name);
}

void parser_lr_write_impl_gen_cpp_instr(Vec_T<cc::Node_T> &dst, WriteInstr_T wr,
                                        const cc::Node_T &curr,
                                        const GenName &fun_ns,
                                        const std::string &src_base_name,
                                        CppGenContext &cc,
                                        LangCompileContext &ctx) {

  if (wr->is_Pass()) {
    // pass

  } else if (wr->is_String()) {
    auto wc = wr->as_String();
    auto str_lit = fmt_str("\"{}\"", escape_string(wc->s_));
    cc.qq_stmt_acc(dst, "pb->push_string(", str_lit, ");");

  } else if (wr->is_Seq()) {
    auto wc = wr->as_Seq();
    for (const auto &instr : *wc->instrs_) {
      parser_lr_write_impl_gen_cpp_instr(dst, instr, curr, fun_ns,
                                         src_base_name, cc, ctx);
    }

  } else if (wr->is_WithSumCase()) {
    auto wc = wr->as_WithSumCase();
    auto switch_cases = make_rc<Vec<cc::Node_T>>();
    for (const auto &[case_id, case_instr] : *wc->cases_map_) {
      auto case_body = make_rc<Vec<cc::Node_T>>();
      auto case_str = fmt_str("{}", case_id);
      auto [src_ns, _] = parser_lr_unwind_impl_gen_name_to_cpp_struct(
          wc->sum_id_, src_base_name, cc);
      auto cpp_case_str_long = cc.qq_expr(src_ns, "::_W::", case_str);
      auto curr_new = cc.qq_expr(curr, fmt_str("->as_{}()", case_str));
      parser_lr_write_impl_gen_cpp_instr(case_body, case_instr, curr_new,
                                         fun_ns, src_base_name, cc, ctx);
      switch_cases->push_back(cc.qq_switch_case("case", cpp_case_str_long,
                                                ": {", *case_body, "break; }"));
    }
    cc.qq_stmt_acc(dst, "switch (", curr, "->w_) {", *switch_cases,
                   "default: { langcc::AX(); }}");

  } else if (wr->is_WithItem()) {
    auto x_sub = cc.qq_expr(curr, "->item_");
    parser_lr_write_impl_gen_cpp_instr(dst, wr->as_WithItem()->body_, x_sub,
                                       fun_ns, src_base_name, cc, ctx);

  } else if (wr->is_WithOpt() || wr->is_WithOptBool()) {
    auto x_cond = curr;
    if (wr->is_WithOpt()) {
      x_cond = cc.qq_expr(curr, ".is_some()");
    }
    WriteInstr_T w_sub;
    if (wr->is_WithOpt()) {
      w_sub = wr->as_WithOpt()->body_;
    } else if (wr->is_WithOptBool()) {
      w_sub = wr->as_WithOptBool()->body_;
    } else {
      AX();
    }
    auto x_sub = cc.qq_expr(curr, ".as_some()");
    auto if_body = make_rc<Vec<cc::Node_T>>();
    parser_lr_write_impl_gen_cpp_instr(if_body, w_sub, x_sub, fun_ns,
                                       src_base_name, cc, ctx);
    cc.qq_stmt_acc(dst, "if (", x_cond, ") {", *if_body, "}");

  } else if (wr->is_RecList()) {
    auto wc = wr->as_RecList();
    auto ret_body = make_rc<Vec<cc::Node_T>>();

    Int nl_init = 0;
    Int nl_delim = 0;
    Int nl_final = 0;
    Int indent_inner = 0;
    if (wc->format_->is_Inline()) {
      nl_init = 0;
      nl_delim = 0;
      nl_final = 0;
      indent_inner = 0;
    } else if (wc->format_->is_Block()) {
      nl_init = 1;
      nl_delim = 1;
      nl_final = 1;
      indent_inner = 1;
    } else if (wc->format_->is_Block2()) {
      nl_init = 1;
      nl_delim = 2;
      nl_final = 1;
      indent_inner = 1;
    } else if (wc->format_->is_Top()) {
      nl_init = 0;
      nl_delim = 1;
      nl_final = 0;
      indent_inner = 0;
    } else if (wc->format_->is_Top2()) {
      nl_init = 0;
      nl_delim = 2;
      nl_final = 1;
      indent_inner = 0;
    } else {
      AX();
    }

    auto x_ind = cc.qq_expr(cc.gen_id_fresh(fun_ns, "i"));
    auto x_sub = cc.qq_expr(cc.gen_id_fresh(fun_ns, "xi"));
    auto x_iter = cc.qq_expr(cc.gen_id_fresh(fun_ns, "is_iter"));
    auto x_true = cc.qq_expr("true");
    auto x_false = cc.qq_expr("false");
    auto x_indented = cc.qq_expr(cc.gen_id_fresh(fun_ns, "indented"));

    cc.qq_stmt_acc(ret_body, "langcc::Int", x_ind, ";");
    cc.qq_stmt_acc(ret_body, "bool", x_iter, "= false;");
    cc.qq_stmt_acc(ret_body, "bool", x_indented, "= false;");

    auto loop_body = make_rc<Vec<cc::Node_T>>();
    {
      cc.qq_stmt_acc(loop_body, "auto&", x_sub, "=", curr, "->at_unchecked(",
                     x_ind, ");");

      auto if_body1 = make_rc<Vec<cc::Node_T>>();
      {
        if (wc->delim_.is_some()) {
          parser_lr_write_impl_gen_cpp_instr(if_body1, wc->delim_.as_some(),
                                             x_sub, fun_ns, src_base_name, cc,
                                             ctx);
        }
        if (nl_delim > 0) {
          cc.qq_stmt_acc(if_body1, "pb->push_newlines(",
                         fmt_str("{}", nl_delim), ");");
        }
      }
      if (if_body1->length() > 0) {
        cc.qq_stmt_acc(loop_body, "if (", x_iter, ") {", *if_body1, "}");
      }

      auto if_body2 = make_rc<Vec<cc::Node_T>>();
      {
        if (nl_init > 0) {
          cc.qq_stmt_acc(if_body2, "pb->push_newlines(", fmt_str("{}", nl_init),
                         ");");
        }
        for (Int k = 0; k < indent_inner; k++) {
          cc.qq_stmt_acc(if_body2, "pb->push_indent();");
        }
        cc.qq_stmt_acc(if_body2, x_indented, "= true;");
      }
      if (if_body2->length() > 0) {
        cc.qq_stmt_acc(loop_body, "if (!", x_iter, ") {", *if_body2, "}");
      }

      cc.qq_stmt_acc(loop_body, x_iter, "= true;");
      parser_lr_write_impl_gen_cpp_instr(loop_body, wc->body_, x_sub, fun_ns,
                                         src_base_name, cc, ctx);
    }

    cc.qq_stmt_acc(ret_body, "for (", x_ind, "= 0;", x_ind, "_LT_ len(", curr,
                   ");", x_ind, "++) {", *loop_body, "}");

    if (wc->has_final_->is_Y()) {
      AT(wc->delim_.is_some());
      auto if_body4 = make_rc<Vec<cc::Node_T>>();
      parser_lr_write_impl_gen_cpp_instr(if_body4, wc->delim_.as_some(), x_sub,
                                         fun_ns, src_base_name, cc, ctx);
      cc.qq_stmt_acc(ret_body, "if (", x_iter, ") {", *if_body4, "}");
    }

    if (nl_final > 0) {
      cc.qq_stmt_acc(ret_body, "pb->push_newlines(", fmt_str("{}", nl_final),
                     ");");
    }

    if (indent_inner > 0) {
      auto if_body3 = make_rc<Vec<cc::Node_T>>();
      for (Int k = 0; k < indent_inner; k++) {
        cc.qq_stmt_acc(if_body3, "pb->push_dedent();");
      }
      cc.qq_stmt_acc(ret_body, "if (", x_indented, ") {", *if_body3, "}");
    }

    cc.qq_stmt_acc(dst, "{", *ret_body, "}");

  } else if (wr->is_WithField()) {
    auto wc = wr->as_WithField();
    auto name_cpp = cc.qq_expr(fmt_str("{}_", wc->field_name_));
    auto curr_new = cc.qq_expr(curr, "->", name_cpp);
    parser_lr_write_impl_gen_cpp_instr(dst, wc->body_, curr_new, fun_ns,
                                       src_base_name, cc, ctx);

  } else if (wr->is_Rec()) {
    cc.qq_stmt_acc(dst, curr, "->write(pb);");

  } else if (wr->is_Prim()) {
    cc.qq_stmt_acc(dst, "pb->push_string(fmt_str(\"{}\",", curr, "));");

  } else if (wr->is_Newline()) {
    cc.qq_stmt_acc(dst, "pb->push_newline();");

  } else if (wr->is_Indent()) {
    cc.qq_stmt_acc(dst, "pb->push_indent();");

  } else if (wr->is_Dedent()) {
    cc.qq_stmt_acc(dst, "pb->push_dedent();");

  } else {
    LG_ERR(" >>> wr: {}", wr);
    AX();
  }
}

Vec_T<std::string> lower_name_ident_struct(Ident_T id) {
  auto name = make_rc<Vec<IdBase>>();
  name->push_back("Node");
  for (const auto &x : *id->xs_) {
    name->push_back(data_gen_id_base_to_string(x));
  }
  auto v = lower_name(LowerTy::STRUCT, name, None<GenName>());
  auto ret = make_rc<Vec<std::string>>();
  bool fresh = true;
  for (const auto &x : *v) {
    if (!fresh) {
      ret->push_back("::");
    }
    fresh = false;
    ret->push_back(x);
  }
  return ret;
}

void lang_emit_parser_defs(LangCompileContext &ctx) {
  Int k = ctx.lr_k_;
  auto N = ctx.parser_nfa_final_;
  auto D = ctx.parser_dfa_final_;

  ctx.cc_.dst_decls_->push_back(
      ctx.cc_.Q_
          ->qq_ext(
              Some<std::string>("Decl"), "namespace lang::", ctx.src_base_name_,
              "::parser {", "langcc::IntPair action_by_vertex(",
              "langcc::ParserVertexId v, langcc::ParserLookahead la);", "}")
          ->as_Decl());

  Int n_sym = grammar_all_lr_syms(ctx.Gr_cps_)->length();

  if (k != 1 || ctx.Gr_cps_->prods_->length() > 65535 || n_sym > 65535) {
    // Note: optimized version uses 16 bits to encode arg

    auto table = parser_lr_action_by_vertex_impl_table_basic(ctx, D, k);
    auto table_init_list = switch_table_encode_u16(table);
    auto cpp_table_init_list = ctx.cc_.gen_cpp_init_list_u16(table_init_list);

    ctx.cc_.dst_defs_->push_back(
        ctx.cc_.Q_
            ->qq_ext(Some<std::string>("Decl"), "langcc::IntPair lang::",
                     ctx.src_base_name_, "::parser::action_by_vertex(",
                     "langcc::ParserVertexId v, langcc::ParserLookahead la) {",
                     "static const langcc::u16_array tt = ",
                     cpp_table_init_list, ";",
                     "return "
                     "langcc::table_decode_r1_vec_pair<langcc::i16,langcc::u16>"
                     "(tt, v, la);"
                     "}")
            ->as_Decl());

  } else {
    auto [tt_acc_norm, tt_arg] =
        parser_lr_action_by_vertex_impl_table_opt(ctx, N, D, k);
    auto tt_acc_init_list = ctx.cc_.gen_cpp_init_list_u16(tt_acc_norm);
    auto tt_arg_init_list = ctx.cc_.gen_cpp_init_list_u16(tt_arg);

    AR_eq(static_cast<Int>(ParserActionData_W::SHIFT), 4);
    ctx.cc_.dst_defs_->push_back(
        ctx.cc_.Q_
            ->qq_ext(Some<std::string>("Decl"),
                     "langcc::IntPair lang::", ctx.src_base_name_,
                     "::parser::action_by_vertex(langcc::ParserVertexId v,",
                     "langcc::ParserLookahead la) {",
                     "static const langcc::u16_array tt_acc_raw = ",
                     tt_acc_init_list, ";",
                     "static const langcc::u16_array tt_arg = ",
                     tt_arg_init_list, ";",
                     "auto tt_acc = "
                     "langcc::table_u16_array_as_u8_array(tt_acc_raw);",
                     "langcc::Int ind = la[0] * ",
                     fmt_str("{}", D->G_->V_->length()), " + v;",
                     "langcc::Int ret_acc = tt_acc[ind];",
                     "langcc::Int ret_arg = tt_arg[ind];",
                     "return std::make_pair(ret_acc, ret_arg);", "}")
            ->as_Decl());
  }

  ctx.cc_.dst_decls_->push_back(
      ctx.cc_.Q_
          ->qq_ext(Some<std::string>("Decl"),
                   "namespace lang::", ctx.src_base_name_, "::parser {",
                   "langcc::ParserVertexId vertex_dfa_step(",
                   "langcc::ParserVertexId v, langcc::ParserSymId sym,",
                   "langcc::ParserAttrMask attr);", "}")
          ->as_Decl());

  {
    auto tt = parser_lr_vertex_dfa_step_impl_table(ctx, D);
    auto table_init_list = switch_table_encode_u16(tt);
    auto cpp_table_init_list = ctx.cc_.gen_cpp_init_list_u16(table_init_list);

    ctx.cc_.dst_defs_->push_back(
        ctx.cc_.Q_
            ->qq_ext(Some<std::string>("Decl"),
                     "langcc::ParserVertexId lang::", ctx.src_base_name_,
                     "::parser::vertex_dfa_step(langcc::ParserVertexId v, "
                     "langcc::ParserSymId sym,",
                     "langcc::ParserAttrMask attr) {",
                     "static const langcc::u16_array tt = ",
                     cpp_table_init_list, ";",
                     "return "
                     "langcc::table_decode_r2_vec<langcc::i16,langcc::u16>(tt, "
                     "v, sym, attr);"
                     "}")
            ->as_Decl());
  }

  auto proc_xforms = make_rc<Vec<cc::Node_T>>();
  auto proc_xform_by_prod_id_elem_stmts = make_rc<Vec<cc::Node_T>>();

  // To allocate appropriate buffer space when unwind ops are called from
  // parse_rt
  ctx.cps_flat_diff_max_ = 0;

  for (const auto &prod_cps : *ctx.Gr_cps_->prods_) {
    auto prod_flat = ctx.cps_prod_map_rev_->operator[](prod_cps);
    auto cps_flat_diff =
        std::max<Int>(0, prod_cps->rhs_->length() - prod_flat->rhs_->length());
    if (cps_flat_diff > ctx.cps_flat_diff_max_) {
      ctx.cps_flat_diff_max_ = cps_flat_diff;
    }
    auto proc_xform = parser_lr_unwind_impl_gen_cpp(
        ctx.cc_, prod_cps, prod_flat, ctx, ctx.src_base_name_);
    proc_xforms->push_back(proc_xform);
    proc_xform_by_prod_id_elem_stmts->push_back(
        ctx.cc_.qq_stmt("ret->push_back(", proc_xform, ");"));
  }

  ctx.cc_.dst_decls_->push_back(
      ctx.cc_.Q_
          ->qq_ext(Some<std::string>("Decl"),
                   "namespace lang::", ctx.src_base_name_, "::parser {",
                   "langcc::ParserProcXforms proc_xform_by_prod_id();", "}")
          ->as_Decl());

  ctx.cc_.dst_defs_->push_back(
      ctx.cc_.Q_
          ->qq_ext(Some<std::string>("Decl"), "langcc::ParserProcXforms lang::",
                   ctx.src_base_name_, "::parser::proc_xform_by_prod_id() {",
                   "auto ret = "
                   "langcc::make_rc<langcc::Vec<langcc::ParserProcXform>>();",
                   *proc_xform_by_prod_id_elem_stmts, "return ret;", "}")
          ->as_Decl());

  ctx.cc_.dst_decls_->push_back(
      ctx.cc_.Q_
          ->qq_ext(Some<std::string>("Decl"),
                   "namespace lang::", ctx.src_base_name_, "::parser {",
                   "langcc::ParserSymByName start_marker_by_name();", "}")
          ->as_Decl());

  auto start_marker_by_name_entries = make_rc<Vec<cc::Node_T>>();
  for (const auto &ident : *ctx.parser_syms_top_) {
    auto marker =
        LRSym::Base::make(Sym::TermStartMarker::make(ident->xs_->only()));
    auto marker_name = ident->xs_->only()->as_User()->name_;
    auto marker_ind = grammar_sym_to_ind_flat(ctx, marker);
    start_marker_by_name_entries->push_back(ctx.cc_.Q_->qq_ext(
        Some<std::string>("Stmt"), "ret.insert(std::make_pair(",
        fmt_str("\"{}\"", escape_string(marker_name)), ",",
        fmt_str("{}", marker_ind), "));"));
  }
  ctx.cc_.dst_defs_->push_back(
      ctx.cc_.Q_
          ->qq_ext(Some<std::string>("Decl"), "langcc::ParserSymByName lang::",
                   ctx.src_base_name_, "::parser::start_marker_by_name() {",
                   "langcc::ParserSymByName ret;",
                   *start_marker_by_name_entries,
                   "return ret;"
                   "}")
          ->as_Decl());

  ctx.cc_.dst_decls_->push_back(
      ctx.cc_.Q_
          ->qq_ext(Some<std::string>("Decl"),
                   "namespace lang::", ctx.src_base_name_, "::parser {",
                   "langcc::ParserSymId term_tok_to_sym(langcc::TokenId tok);",
                   "}")
          ->as_Decl());

  auto term_tok_to_sym_cases = make_rc<Vec<cc::Node_T>>();
  for (const auto &sym : *ctx.Gr_cps_->term_) {
    if (sym->is_TermStartMarker()) {
      // pass
    } else if (sym->is_Term()) {
      auto expr_base = sym->as_Term()->tok_;
      auto tok_ind = ctx.tokens_top_by_id_rev_.operator[](expr_base);
      auto sym_ind = grammar_sym_to_ind_flat(ctx, LRSym::Base::make(sym));
      term_tok_to_sym_cases->push_back(ctx.cc_.Q_->qq_ext(
          Some<std::string>("SwitchCase"), "case", fmt_str("{}", tok_ind),
          ": {", "return", fmt_str("{}", sym_ind), "; }"));
    } else {
      AX();
    }
  }
  ctx.cc_.dst_defs_->push_back(
      ctx.cc_.Q_
          ->qq_ext(Some<std::string>("Decl"),
                   "langcc::ParserSymId lang::", ctx.src_base_name_,
                   "::parser::term_tok_to_sym(langcc::TokenId tok) {",
                   "switch (tok) {", *term_tok_to_sym_cases,
                   "default: { langcc::AX(); }", "}", "}")
          ->as_Decl());

  ctx.cc_.dst_decls_->push_back(
      ctx.cc_.Q_
          ->qq_ext(
              Some<std::string>("Decl"), "namespace lang::", ctx.src_base_name_,
              "::parser {",
              "langcc::ParserSymId sym_to_recur_step(langcc::ParserSymId sym);",
              "}")
          ->as_Decl());

  {
    auto sym_to_recur_step_cases = make_rc<Vec<cc::Node_T>>();
    for (const auto &sym : *ctx.Gr_cps_->nonterm_) {
      auto sym_ind = grammar_sym_to_ind_flat(ctx, LRSym::Base::make(sym));
      auto rec_ind = grammar_sym_to_ind_flat(ctx, LRSym::RecurStep::make(sym));
      sym_to_recur_step_cases->push_back(ctx.cc_.Q_->qq_ext(
          Some<std::string>("SwitchCase"), "case", fmt_str("{}", sym_ind),
          ": {", "return", fmt_str("{}", rec_ind), "; }"));
    }
    ctx.cc_.dst_defs_->push_back(
        ctx.cc_.Q_
            ->qq_ext(Some<std::string>("Decl"),
                     "langcc::ParserSymId lang::", ctx.src_base_name_,
                     "::parser::sym_to_recur_step(langcc::ParserSymId sym) {",
                     "switch (sym) {", *sym_to_recur_step_cases,
                     "default: { langcc::AX(); }", "}", "}")
            ->as_Decl());
  }

  ctx.cc_.dst_decls_->push_back(
      ctx.cc_.Q_
          ->qq_ext(Some<std::string>("Decl"),
                   "namespace lang::", ctx.src_base_name_, "::parser {",
                   "std::string sym_to_debug_string(langcc::ParserSymId sym);",
                   "}")
          ->as_Decl());

  {
    auto sym_to_str_cases = make_rc<Vec<cc::Node_T>>();

    auto sym_all = grammar_all_lr_syms(ctx.Gr_cps_);
    Int sym_ind = 0;
    for (const auto &sym : *sym_all) {
      auto sym_ret = fmt_str("{}", sym);
      sym_to_str_cases->push_back(ctx.cc_.qq_switch_case(
          "case", fmt_str("{}", sym_ind), ": { return",
          fmt_str("\"{}\"", escape_string(sym_ret)), "; }"));
      ++sym_ind;
    }

    ctx.cc_.dst_defs_->push_back(
        ctx.cc_.Q_
            ->qq_ext(Some<std::string>("Decl"),
                     "std::string lang::", ctx.src_base_name_,
                     "::parser::sym_to_debug_string(langcc::ParserSymId sym) {",
                     "switch (sym) {", *sym_to_str_cases,
                     "default: { langcc::AX(); }", "}", "}")
            ->as_Decl());
  }

  ctx.cc_.dst_decls_->push_back(
      ctx.cc_.Q_
          ->qq_ext(Some<std::string>("Decl"),
                   "namespace lang::", ctx.src_base_name_, "::parser {",
                   "langcc::Int sym_to_num_attrs(langcc::ParserSymId sym);",
                   "}")
          ->as_Decl());

  {
    auto sym_to_n_attr_cases = make_rc<Vec<cc::Node_T>>();

    auto sym_all = grammar_all_lr_syms(ctx.Gr_cps_);
    Int sym_ind = 0;
    for (const auto &sym : *sym_all) {
      if (!sym->is_Base()) {
        ++sym_ind;
        continue;
      }

      Int dom_len = 0;
      if (ctx.parser_attr_domains_->contains_key(sym->as_Base()->sym_)) {
        auto dom = ctx.parser_attr_domains_->operator[](sym->as_Base()->sym_);
        dom_len = dom->length();
      }
      auto sym_ret = fmt_str("{}", dom_len);

      sym_to_n_attr_cases->push_back(ctx.cc_.qq_switch_case(
          "case", fmt_str("{}", sym_ind), ": { return", sym_ret, "; }"));
      ++sym_ind;
    }

    ctx.cc_.dst_defs_->push_back(
        ctx.cc_.Q_
            ->qq_ext(Some<std::string>("Decl"),
                     "langcc::Int lang::", ctx.src_base_name_,
                     "::parser::sym_to_num_attrs(langcc::ParserSymId sym) {",
                     "switch (sym) {", *sym_to_n_attr_cases,
                     "default: { langcc::AX(); }", "}", "}")
            ->as_Decl());
  }

  ctx.cc_.dst_decls_->push_back(
      ctx.cc_.Q_
          ->qq_ext(Some<std::string>("Decl"),
                   "namespace lang::", ctx.src_base_name_, "::parser {",
                   "std::string attr_to_debug_string(langcc::ParserSymId sym,",
                   "langcc::Int attr_ind);", "}")
          ->as_Decl());

  {
    auto attr_to_str_cases = make_rc<Vec<cc::Node_T>>();

    auto sym_all = grammar_all_lr_syms(ctx.Gr_cps_);
    Int sym_ind = 0;
    for (const auto &sym : *sym_all) {
      if (!sym->is_Base() ||
          !ctx.parser_attr_domains_->contains_key(sym->as_Base()->sym_)) {
        ++sym_ind;
        continue;
      }

      auto attr_to_str_cases_sub_sym = make_rc<Vec<cc::Node_T>>();
      auto dom = ctx.parser_attr_domains_->operator[](sym->as_Base()->sym_);
      Int attr_ind = 0;
      for (const auto &[ki, _] : *dom) {
        auto attr_ret = fmt_str("{}", ki);
        attr_to_str_cases_sub_sym->push_back(ctx.cc_.qq_switch_case(
            "case", fmt_str("{}", attr_ind), ": { return",
            fmt_str("\"{}\"", escape_string(attr_ret)), ";}"));
        ++attr_ind;
      }

      attr_to_str_cases->push_back(ctx.cc_.qq_switch_case(
          "case", fmt_str("{}", sym_ind), ": {", "switch (attr_ind) {",
          *attr_to_str_cases_sub_sym,
          "default: { langcc::AX(\"Not found: {}, {}\", sym, attr_ind); }", "}",
          "break;"
          "}"));

      ++sym_ind;
    }

    ctx.cc_.dst_defs_->push_back(
        ctx.cc_.Q_
            ->qq_ext(Some<std::string>("Decl"), "std::string lang::",
                     ctx.src_base_name_, "::parser::attr_to_debug_string(",
                     "langcc::ParserSymId sym, langcc::Int attr_ind) {",
                     "switch (sym) {", *attr_to_str_cases,
                     "default: { langcc::AX(); }", "}", "}")
            ->as_Decl());
  }
}

inline Ch string_extract_lang_char_seq_single(std::string s_raw,
                                              const lang::meta::Node_T &e,
                                              LangCompileContext &ctx) {
  auto chs = string_extract_lang_char_seq(std::move(s_raw));
  if (chs.is_none() || chs.as_some().size() != 1) {
    ctx.error(e, "Invalid character range");
  }
  return chs.as_some()[0];
}

void lang_emit_global_defs(LangCompileContext &ctx) {
  ctx.cc_.dst_decls_->push_back(
      ctx.cc_.Q_
          ->qq_ext(Some<std::string>("Decl"),
                   "namespace lang::", ctx.src_base_name_, "{",
                   "using LangDesc = langcc::LangDesc<Node::_T,",
                   "parser::action_by_vertex, parser::vertex_dfa_step>;", "}")
          ->as_Decl());

  ctx.cc_.dst_decls_->push_back(
      ctx.cc_.Q_
          ->qq_ext(Some<std::string>("Decl"),
                   "namespace lang::", ctx.src_base_name_, "{",
                   "using LangDesc_T = langcc::LangDesc_T<Node::_T,",
                   "parser::action_by_vertex, parser::vertex_dfa_step>;", "}")
          ->as_Decl());

  ctx.cc_.dst_decls_->push_back(
      ctx.cc_.Q_
          ->qq_ext(Some<std::string>("Decl"),
                   "namespace lang::", ctx.src_base_name_, "{",
                   "using QuoteEnv = langcc::QuoteEnv<Node::_T,",
                   "parser::action_by_vertex, parser::vertex_dfa_step>;", "}")
          ->as_Decl());

  ctx.cc_.dst_decls_->push_back(
      ctx.cc_.Q_
          ->qq_ext(Some<std::string>("Decl"),
                   "namespace lang::", ctx.src_base_name_, "{",
                   "using QuoteEnv_T = langcc::QuoteEnv_T<Node::_T,",
                   "parser::action_by_vertex, parser::vertex_dfa_step>;", "}")
          ->as_Decl());

  ctx.cc_.dst_decls_->push_back(
      ctx.cc_.Q_
          ->qq_ext(Some<std::string>("Decl"),
                   "namespace lang::", ctx.src_base_name_, "{",
                   "lang::", ctx.src_base_name_, "::LangDesc_T init();", "}")
          ->as_Decl());

  auto lexer_mode_descs = make_rc<Vec<cc::Node_T>>();

  for (const auto &mode : ctx.lexer_modes_) {
    auto tr_m = lexer_extract_trivial_maybe(mode);

    lexer_mode_descs->push_back(ctx.cc_.Q_->qq_ext(
        Some<std::string>("Stmt"), "auto", mode->name_.to_std_string(),
        "= langcc::make_rc<langcc::LexerModeDesc>();"));
    lexer_mode_descs->push_back(ctx.cc_.Q_->qq_ext(
        Some<std::string>("Stmt"), mode->name_.to_std_string(),
        "->step_fn_ = lexer::", mode->name_.to_std_string(), "::step;"));
    lexer_mode_descs->push_back(ctx.cc_.Q_->qq_ext(
        Some<std::string>("Stmt"), mode->name_.to_std_string(),
        "->acc_fn_ = lexer::", mode->name_.to_std_string(), "::acc;"));
    lexer_mode_descs->push_back(ctx.cc_.Q_->qq_ext(
        Some<std::string>("Stmt"), mode->name_.to_std_string(),
        "->step_exec_fn_ = lexer::", mode->name_.to_std_string(),
        "::step_exec;"));

    if (tr_m.is_some()) {
      auto tr = tr_m.as_some();

      auto tr_cases_blocks = make_rc<Vec<cc::Node_T>>();
      Int case_i = 0;
      Option_T<cc::Node_T> eof_block = None<cc::Node_T>();
      for (const auto &[case_cs_m, case_instrs] : *tr.cases_) {
        cc::Node_T tr_case_block;
        if (case_cs_m.is_none()) {
          AT(eof_block.is_none());
          eof_block = Some(
              ctx.cc_.qq_stmt("{", "tok_lo = in_i;", "tok_hi = in_i;",
                              "best_act = ", fmt_str("{}", case_i), ";",
                              "best_tok = langcc::NO_TOKEN;", "break;", "}"));
        } else {
          auto case_cs = case_cs_m.as_some();
          tr_case_block =
              ctx.cc_.qq_stmt("{", "tok_lo = in_i;", "tok_hi = in_i + ",
                              fmt_str("{}", case_cs->length()), ";",
                              "best_act = ", fmt_str("{}", case_i), ";",
                              "best_tok = langcc::NO_TOKEN;", "break;", "}");
          for (Int j = case_cs->length() - 1; j >= 0; j--) {
            if (j == 0) {
              tr_case_block =
                  ctx.cc_.qq_stmt("if (__builtin_expect(curr == ",
                                  fmt_str("{}", case_cs->operator[](j)),
                                  ", 0)) {", tr_case_block, "}");
            } else {
              tr_case_block = ctx.cc_.qq_stmt(
                  "if (__builtin_expect(in_i + ", fmt_str("{}", j),
                  " _LT_ in_data_len && ", "in_data[in_i+", fmt_str("{}", j),
                  "] == ", fmt_str("{}", case_cs->operator[](j)), ", 0)) {",
                  tr_case_block, "}");
            }
          }
          tr_cases_blocks->push_back(tr_case_block);
        }

        ++case_i;
      }
      if (eof_block.is_none()) {
        eof_block =
            Some(ctx.cc_.qq_stmt("{ lexer_raise_unexpected_eof(st, in_i); }"));
      }
      cc::Node_T eof_block_final = eof_block.as_some();

      auto tr_fun = ctx.cc_.Q_->qq_ext(
          Some<std::string>("Decl"),
          "[[always_inlines]] inline langcc::Int lang::", ctx.src_base_name_,
          "::lexer::", mode->name_.to_std_string(), "::proc_mode_loop_opt(",
          "    langcc::Ptr<langcc::LexerModeDesc> mode, "
          "langcc::Ptr<langcc::LexerState> st,",
          "    langcc::Ptr<langcc::SymItemVec> emit_dst,",
          "    langcc::Int mode_start_pos, langcc::Int mode_buf_pos) {",

          "langcc::SymItemVec emit_dst_sub;",
          "langcc::Int in_i = mode_start_pos;",
          "langcc::Ptr<langcc::Ch> in_data = st->in_->data_.begin();",
          "langcc::Int in_data_len = st->in_->data_len_;",
          "langcc::Int tok_lo;", "langcc::Int tok_hi;",
          "langcc::Ptr<langcc::LexWhitespaceState> ws_state = nullptr;",

          "for (langcc::cc_nop(); true; langcc::cc_nop()) {",
          "    tok_lo = in_i;",
          "    langcc::DFAActionId best_act = langcc::DFATable::NO_ACTION;",
          "    langcc::TokenId best_tok;"
          "    for (langcc::cc_nop(); true; langcc::cc_nop()) {",
          "        langcc::Ch curr = -1;",
          "        if (__builtin_expect(in_i == in_data_len, 0)) {",
          eof_block_final, "        } else {",
          "            curr = in_data[in_i];", "        }", *tr_cases_blocks,
          "        ++in_i;", "    }",
          "    langcc::IntPair new_mode_dir = mode->step_exec_fn_(",
          "        st, emit_dst, ws_state, best_act, best_tok, in_i, tok_lo, "
          "tok_hi);",
          "    if (__builtin_expect(",
          "        new_mode_dir.first == langcc::DFATable::NEW_MODE_POP_EMIT, "
          "0)) {",
          "        st->enqueue_emit_ext(",
          "            emit_dst, ws_state, new_mode_dir.second, mode_buf_pos, "
          "in_i,",
          "            true);", "        return in_i;", "    }",
          "    if (__builtin_expect(",
          "        new_mode_dir.first == "
          "langcc::DFATable::NEW_MODE_POP_EXTRACT, 0)) {",
          "        st->extract_comment(mode_buf_pos, in_i);",
          "        return in_i;", "    }", "    if (__builtin_expect(",
          "        new_mode_dir.first == langcc::DFATable::NEW_MODE_POP, 0)) {",
          "        return in_i;", "    }",
          "    if (__builtin_expect(new_mode_dir.first >= 0, 0)) {",
          "        auto desc_new = "
          "st->mode_descs_->operator[](new_mode_dir.first);",
          "        in_i = lexer_proc_mode_loop(",
          "            desc_new.get(), st, &emit_dst_sub, in_i, "
          "new_mode_dir.second);",
          "        langcc::lex_queue_pull_sub(st, emit_dst, &emit_dst_sub, "
          "ws_state);",
          "    }", "}", "}");

      ctx.cc_.dst_decls_->push_back(
          ctx.cc_
              .qq("Decl", "namespace lang::", ctx.src_base_name_,
                  "::lexer::", mode->name_.to_std_string(), "{",
                  "[[always_inlines]] inline langcc::Int "
                  "proc_mode_loop_opt(",
                  "langcc::Ptr<langcc::LexerModeDesc> mode, "
                  "langcc::Ptr<langcc::LexerState> st,",
                  "langcc::Ptr<langcc::SymItemVec> emit_dst,",
                  "langcc::Int mode_start_pos, langcc::Int mode_buf_pos);", "}")
              ->as_Decl());

      ctx.cc_.dst_defs_->push_back(tr_fun->as_Decl());

      lexer_mode_descs->push_back(ctx.cc_.Q_->qq_ext(
          Some<std::string>("Stmt"), mode->name_.to_std_string(),
          "->proc_mode_loop_opt_fn_ = lexer::", mode->name_.to_std_string(),
          "::proc_mode_loop_opt;"));

    } else {
      auto loop_fun = ctx.cc_.Q_->qq_ext(
          Some<std::string>("Decl"),
          "[[always_inlines]] inline langcc::Int lang::", ctx.src_base_name_,
          "::lexer::", mode->name_.to_std_string(), "::proc_mode_loop_opt(",
          "    langcc::Ptr<langcc::LexerModeDesc> mode, "
          "langcc::Ptr<langcc::LexerState> st,",
          "    langcc::Ptr<langcc::SymItemVec> emit_dst,",
          "    langcc::Int mode_start_pos, langcc::Int mode_buf_pos) {",

          "    langcc::SymItemVec emit_dst_sub;", "    bool read_eof = false;",
          "    langcc::Int in_i = mode_start_pos;",
          "    langcc::Ptr<langcc::Ch> in_data = st->in_->data_.begin();",
          "    langcc::Int in_data_len = st->in_->data_len_;",
          "    auto label_ids_ascii = st->label_ids_ascii_->begin();",
          "    langcc::Int tok_lo;", "    langcc::Int tok_hi;",
          "    langcc::rc_ptr<langcc::LexWhitespaceState> ws_state_rc;",
          "    langcc::LexWhitespaceState* ws_state = nullptr;",
          "    if (mode->ws_sig_.is_some()) {",
          "        ws_state_rc = "
          "langcc::make_rc<langcc::LexWhitespaceState>(st,",
          "            st->tok_to_sym_, mode_buf_pos, in_data,",
          "            mode->ws_newline_ind_, mode->ws_indent_ind_, "
          "mode->ws_dedent_ind_,",
          "            mode->ws_err_mixed_indent_ind_, "
          "mode->ws_err_text_after_lc_ind_,",
          "            mode->ws_err_delim_mismatch_ind_, "
          "mode->ws_sig_.as_some());",
          "        ws_state = ws_state_rc.get();", "    }",
          "    for (langcc::cc_nop(); true; langcc::cc_nop()) {",
          "        tok_lo = in_i;", "        langcc::DFAVertexId v = 0;",
          "        langcc::DFAActionId best_act = langcc::DFATable::NO_ACTION;",
          "        langcc::TokenId best_tok;"
          "        for (langcc::cc_nop(); true; langcc::cc_nop()) {",
          "            langcc::TokenId cl = langcc::lexer_char_to_label(",
          "                in_data, in_i, in_data_len, label_ids_ascii, st);",
          "            v = step(v, cl);",
          "            if (__builtin_expect(v == langcc::DFATable::NO_VERTEX, "
          "0)) {",
          "                break;", "            }",
          "            if (__builtin_expect(cl == langcc::DFATable::EOF_LABEL, "
          "0)) {",
          "                read_eof = true;", "            }",
          "            if (__builtin_expect(!read_eof, 1)) {",
          "                in_i++;", "            }",
          "            auto acc_tok = acc(v);",
          "            if (acc_tok.first != langcc::DFATable::NO_ACTION) {",
          "                tok_hi = in_i;",
          "                best_act = acc_tok.first;",
          "                best_tok = acc_tok.second;", "            }",
          "        }", "        in_i = tok_lo;",
          "        langcc::lexer_state_proc_update_pre(",
          "            best_act, best_tok, tok_lo, tok_hi, in_i, read_eof, "
          "st);",
          "        langcc::IntPair new_mode_dir = step_exec(",
          "            st, emit_dst, ws_state, best_act, best_tok, in_i, "
          "tok_lo, tok_hi);",
          "        if (__builtin_expect(",
          "            new_mode_dir.first == "
          "langcc::DFATable::NEW_MODE_POP_EMIT, 0)) {",
          "            st->enqueue_emit_ext(",
          "                emit_dst, ws_state, new_mode_dir.second, "
          "mode_buf_pos, in_i,",
          "                true);", "            if (!!ws_state) {",
          "                ws_state->finish(tok_hi, emit_dst);",
          "            }", "            return in_i;", "        }",
          "        if (__builtin_expect(",
          "                new_mode_dir.first ==",
          "                langcc::DFATable::NEW_MODE_POP_EXTRACT, 0)) {",
          "            st->extract_comment(mode_buf_pos, in_i);",
          "            if (!!ws_state) {",
          "                ws_state->finish(tok_hi, emit_dst);",
          "            }", "            return in_i;", "        }",
          "        if (__builtin_expect(",
          "                new_mode_dir.first == "
          "langcc::DFATable::NEW_MODE_POP, 0)) {",
          "            if (!!ws_state) {",
          "                ws_state->finish(tok_hi, emit_dst);",
          "            }", "            return in_i;", "        }",
          "        if (__builtin_expect(new_mode_dir.first >= 0, 0)) {",
          "            auto desc_new = "
          "st->mode_descs_->operator[](new_mode_dir.first);",
          "            in_i = lexer_proc_mode_loop(",
          "                desc_new.get(), st, &emit_dst_sub, in_i, "
          "new_mode_dir.second);",
          "            langcc::lex_queue_pull_sub(st, emit_dst, &emit_dst_sub, "
          "ws_state);",
          "        }", "        if (__builtin_expect(read_eof, 0)) {",
          "            langcc::lexer_raise_nonempty_mode_stack(st, in_i);",
          "        }", "    }", "}");

      ctx.cc_.dst_decls_->push_back(
          ctx.cc_
              .qq("Decl", "namespace lang::", ctx.src_base_name_,
                  "::lexer::", mode->name_.to_std_string(), "{",
                  "[[always_inlines]] inline langcc::Int "
                  "proc_mode_loop_opt(",
                  "langcc::Ptr<langcc::LexerModeDesc> mode, "
                  "langcc::Ptr<langcc::LexerState> st,",
                  "langcc::Ptr<langcc::SymItemVec> emit_dst,",
                  "langcc::Int mode_start_pos, langcc::Int mode_buf_pos);", "}")
              ->as_Decl());

      ctx.cc_.dst_defs_->push_back(loop_fun->as_Decl());

      lexer_mode_descs->push_back(ctx.cc_.Q_->qq_ext(
          Some<std::string>("Stmt"), mode->name_.to_std_string(),
          "->proc_mode_loop_opt_fn_ = lexer::", mode->name_.to_std_string(),
          "::proc_mode_loop_opt;"));
    }

    lexer_mode_descs->push_back(ctx.cc_.Q_->qq_ext(
        Some<std::string>("Stmt"), "ret->lexer_mode_descs_->push(",
        mode->name_.to_std_string(), ");"));

    if (mode->ws_sig__.is_some()) {
      auto ws = mode->ws_sig__.as_some();
      cc::Node_T cc_lc;
      cc::Node_T cc_delim;
      if (ws->spec_.is_some()) {
        auto sp = ws->spec_.as_some();
        cc_lc = ctx.cc_.qq_expr("langcc::None<langcc::Ch>()");
        if (sp->lc_.is_some()) {
          auto v_lc = string_extract_lang_char_seq_single(
              sp->lc_.as_some().to_std_string(), mode->ws_sig__.as_some(), ctx);
          cc_lc = ctx.cc_.qq_expr("langcc::Some<langcc::Ch>(",
                                  fmt_str("{}", v_lc), ")");
        }
        {
          auto lex_args = ctx.cc_.Q_->make_lex_builder();
          ctx.cc_.Q_->qq_args_acc(lex_args, "{");
          if (sp->delims_->length() % 2 != 0) {
            ctx.error(mode->ws_sig__.as_some(),
                      "Delimiters must come in sequential matching pairs");
            AX();
          }
          for (Int k = 0; k < sp->delims_->length(); k += 2) {
            auto v_delim0 = string_extract_lang_char_seq_single(
                sp->delims_->operator[](k).to_std_string(),
                mode->ws_sig__.as_some(), ctx);
            auto v_delim1 = string_extract_lang_char_seq_single(
                sp->delims_->operator[](k + 1).to_std_string(),
                mode->ws_sig__.as_some(), ctx);
            if (v_delim0 == v_delim1) {
              ctx.error(mode->ws_sig__.as_some(),
                        "Opening and closing delimiters must be distinct");
            }
            if (k > 0) {
              ctx.cc_.Q_->qq_args_acc(lex_args, ",");
            }
            ctx.cc_.Q_->qq_args_acc(lex_args, "{");
            ctx.cc_.Q_->qq_args_acc(
                lex_args,
                fmt_str("{}", static_cast<Int>(static_cast<Ch>(v_delim0))));
            ctx.cc_.Q_->qq_args_acc(lex_args, ",");
            ctx.cc_.Q_->qq_args_acc(
                lex_args,
                fmt_str("{}", static_cast<Int>(static_cast<Ch>(v_delim1))));
            ctx.cc_.Q_->qq_args_acc(lex_args, "}");
          }
          ctx.cc_.Q_->qq_args_acc(lex_args, "}");
          cc_delim = ctx.cc_.Q_->qq_inner(Some<std::string>("Expr"), lex_args);
        }
      } else {
        cc_lc = ctx.cc_.qq_expr(
            "langcc::Some<langcc::Ch>(",
            fmt_str("{}", static_cast<Int>(static_cast<Ch>('\\'))), ")");
        cc_delim = ctx.cc_.qq_expr(
            "{", "{", fmt_str("{}", static_cast<Int>(static_cast<Ch>('['))),
            ",", fmt_str("{}", static_cast<Int>(static_cast<Ch>(']'))),
            "},"
            "{",
            fmt_str("{}", static_cast<Int>(static_cast<Ch>('{'))), ",",
            fmt_str("{}", static_cast<Int>(static_cast<Ch>('}'))),
            "},"
            "{",
            fmt_str("{}", static_cast<Int>(static_cast<Ch>('('))), ",",
            fmt_str("{}", static_cast<Int>(static_cast<Ch>(')'))),
            "}"
            "}");
      }
      auto cc_spec =
          ctx.cc_.qq_expr("langcc::WsSigSpec(", cc_lc, ",", cc_delim, ")");
      ctx.cc_.qq_stmt_acc(lexer_mode_descs, mode->name_.to_std_string(),
                          "->ws_sig_ = langcc::Some<langcc::WsSigSpec>(",
                          cc_spec, ");");
    } else {
      ctx.cc_.qq_stmt_acc(lexer_mode_descs, mode->name_.to_std_string(),
                          "->ws_sig_ = langcc::None<langcc::WsSigSpec>();");
    }

    bool any_ws = false;
    for (const auto &decl : *ctx.lexer_->decls_) {
      if (decl->is_Mode()) {
        if (decl->as_Mode()->ws_sig__.is_some()) {
          any_ws = true;
        }
      }
    }

    if (any_ws) {
      ctx.cc_.qq_stmt_acc(
          lexer_mode_descs, mode->name_.to_std_string(), "->ws_newline_ind_ = ",
          fmt_str("{}", ctx.tokens_top_by_id_rev_.operator[](
                            parse_expr_base_from_token(TokenBase::Special::make(
                                TokenBaseSpecial::Newline)))),
          ";");

      ctx.cc_.qq_stmt_acc(
          lexer_mode_descs, mode->name_.to_std_string(), "->ws_indent_ind_ = ",
          fmt_str("{}", ctx.tokens_top_by_id_rev_.operator[](
                            parse_expr_base_from_token(TokenBase::Special::make(
                                TokenBaseSpecial::Indent)))),
          ";");

      ctx.cc_.qq_stmt_acc(
          lexer_mode_descs, mode->name_.to_std_string(), "->ws_dedent_ind_ = ",
          fmt_str("{}", ctx.tokens_top_by_id_rev_.operator[](
                            parse_expr_base_from_token(TokenBase::Special::make(
                                TokenBaseSpecial::Dedent)))),
          ";");

      ctx.cc_.qq_stmt_acc(
          lexer_mode_descs, mode->name_.to_std_string(),
          "->ws_err_mixed_indent_ind_ = ",
          fmt_str("{}", ctx.tokens_top_by_id_rev_.operator[](
                            parse_expr_base_from_token(TokenBase::Special::make(
                                TokenBaseSpecial::ErrMixedIndent)))),
          ";");

      ctx.cc_.qq_stmt_acc(
          lexer_mode_descs, mode->name_.to_std_string(),
          "->ws_err_text_after_lc_ind_ = ",
          fmt_str("{}", ctx.tokens_top_by_id_rev_.operator[](
                            parse_expr_base_from_token(TokenBase::Special::make(
                                TokenBaseSpecial::ErrTextAfterLC)))),
          ";");

      ctx.cc_.qq_stmt_acc(
          lexer_mode_descs, mode->name_.to_std_string(),
          "->ws_err_delim_mismatch_ind_ = ",
          fmt_str("{}", ctx.tokens_top_by_id_rev_.operator[](
                            parse_expr_base_from_token(TokenBase::Special::make(
                                TokenBaseSpecial::ErrDelimMismatch)))),
          ";");
    }
  }

  auto sym_top_main_str =
      fmt_str("\"{}\"", escape_string(ctx.parser_sym_top_main_.as_some()));

  ctx.cc_.dst_defs_->push_back(
      ctx.cc_.Q_
          ->qq_ext(
              Some<std::string>("Decl"), "lang::", ctx.src_base_name_,
              "::LangDesc_T", "lang::", ctx.src_base_name_, "::init() {",
              "auto ret = langcc::make_rc<lang::", ctx.src_base_name_,
              "::LangDesc>();",
              "ret->lexer_mode_descs_ = "
              "langcc::make_rc<langcc::Vec<langcc::LexerModeDesc_T>>();",
              *lexer_mode_descs,
              "ret->label_ids_ascii_ = lexer::label_ids_ascii();",
              "ret->label_ids_unicode_ = lexer::label_ids_unicode();",
              "ret->lexer_main_mode_ = ",
              fmt_str("{}", ctx.lexer_main_mode_ind_), ";",
              "ret->parser_desc_ = langcc::make_rc<langcc::ParserDesc>();",
              "ret->parser_desc_->start_vertex_ = ",
              fmt_str("{}", ctx.parser_nfa_final_->start_.as_some()), ";",
              "ret->parser_desc_->main_sym_ = ", sym_top_main_str, ";",
              "ret->parser_desc_->start_full_sym_ = ",
              fmt_str("{}", grammar_sym_to_ind_flat(
                                ctx, LRSym::Base::make(Sym::Start::make()))),
              ";", "ret->parser_desc_->right_end_marker_ = ",
              fmt_str("{}",
                      grammar_sym_to_ind_flat(ctx, LRSym::EndMarker::make())),
              ";", "ret->parser_desc_->lr_k_ = ", fmt_str("{}", ctx.lr_k_), ";",
              "ret->parser_desc_->term_tok_to_sym_ = parser::term_tok_to_sym;",
              "ret->parser_desc_->sym_to_recur_step_ = "
              "parser::sym_to_recur_step;",
              "ret->parser_desc_->start_marker_by_name_ = "
              "parser::start_marker_by_name();",
              "ret->parser_desc_->proc_xform_by_prod_id_ = "
              "parser::proc_xform_by_prod_id();",
              "ret->parser_desc_->sym_to_debug_string_ = "
              "parser::sym_to_debug_string;",
              "ret->parser_desc_->sym_to_num_attrs_ = "
              "parser::sym_to_num_attrs;",
              "ret->parser_desc_->attr_to_debug_string_ = "
              "parser::attr_to_debug_string;",
              "ret->parser_desc_->cps_flat_diff_max_ = ",
              fmt_str("{}", ctx.cps_flat_diff_max_), ";", "return ret;", "}")
          ->as_Decl());
}

void lang_emit_test_defs(LangCompileContext &ctx) {
  auto main_decls = make_rc<Vec<cc::Node_T>>();

  main_decls->push_back(ctx.cc_.qq("Stmt", "langcc::global_init();"));
  main_decls->push_back(ctx.cc_.qq("Stmt", "bool ok = true;"));
  main_decls->push_back(
      ctx.cc_.qq("Stmt", "auto L = lang::", ctx.src_base_name_, "::init();"));
  auto test_stanza = lang_get_test_stanza(ctx.src_);
  if (test_stanza.is_some()) {
    for (const auto &test_case : *test_stanza.as_some()->items_) {
      std::string test_text = test_case->text_.to_std_string();
      AT(test_text.length() >= 2 && test_text[0] == '`' &&
         test_text[test_text.length() - 1] == '`');
      auto chs_raw = string_extract_lang_char_seq(test_text).as_some();
      std::vector<Ch> chs;
      Option_T<Int> test_error_pos = None<Int>();
      Int i = 0;
      while (i < chs_raw.size()) {
        if (chs_raw[i] == '#' && i + 1 < chs_raw.size() &&
            chs_raw[i + 1] == '#') {
          if (test_error_pos.is_some()) {
            LG_ERR("Multiple failure markers in string: {}", test_text);
            AX();
          }
          test_error_pos = Some<Int>(i);
          i += 2;
        } else {
          chs.push_back(chs_raw[i]);
          ++i;
        }
      }
      std::string test_sym = "langcc::None<std::string>()";
      if (test_case->sym__.is_some()) {
        test_sym =
            fmt_str("langcc::Some<std::string>(\"{}\")",
                    escape_string(test_case->sym__.as_some().to_std_string()));
      }
      bool test_write = !test_case->print_exempt_;

      auto test_str_lit = fmt_str("\"{}\"", escape_string_chars(chs));

      main_decls->push_back(ctx.cc_.qq(
          "Stmt", "ok = ok && L->test_example(", test_sym, ",", test_str_lit,
          ",",
          fmt_str("{}",
                  (test_error_pos.is_none() ? -1 : test_error_pos.as_some())),
          ",", fmt_str("{}", test_write), ");"));
    }
  }
  main_decls->push_back(ctx.cc_.qq("Stmt", "return !ok;"));

  ctx.cc_test_.push_def(
      false,
      ctx.cc_test_.qq("Decl", "int main() {", *main_decls, "}")->as_Decl());
}

void lang_emit_debug_defs(LangCompileContext &ctx) {
  auto debug_decls = make_rc<Vec<cc::Node_T>>();

  debug_decls->push_back(ctx.cc_.qq("Stmt", "langcc::global_init();"));
  debug_decls->push_back(
      ctx.cc_.qq("Stmt", "auto L = lang::", ctx.src_base_name_, "::init();"));
  debug_decls->push_back(ctx.cc_.qq(
      "Stmt", "{",
      "std::string sym_name = "
      "langcc::string_ws_strip(langcc::stdin_readline().as_some());",
      "std::string body;", "for (langcc::cc_nop(); true; langcc::cc_nop()) {",
      "auto si = langcc::stdin_readline();", "if (si.is_none()) {",
      "    break;", "}", "body += si.as_some();", "}",
      "L->debug_example(sym_name, body);", "return 0;", "}"));

  ctx.cc_debug_.push_def(
      false,
      ctx.cc_debug_.qq("Decl", "int main() {", *debug_decls, "}")->as_Decl());
}

void lang_emit_extract_final(LangCompileContext &ctx, HeaderMode header_mode) {
  auto cc_res = ctx.cc_.extract_mods(header_mode);
  auto cc_hpp_mod = cc_res.first;
  auto cc_cpp_mod = cc_res.second;

  auto cc_test_res = ctx.cc_test_.extract_mods(HeaderMode::N);
  auto cc_test_cpp_mod = cc_test_res.second;

  auto cc_debug_res = ctx.cc_debug_.extract_mods(HeaderMode::N);
  auto cc_debug_cpp_mod = cc_debug_res.second;

  if (cc_hpp_mod.is_some()) {
    write_file(ctx.hpp_path_, fmt_str("{}", cc_hpp_mod.as_some()));
  } else {
    write_file(ctx.hpp_path_, "");
  }

  if (cc_cpp_mod.is_some()) {
    write_file(ctx.cpp_path_, fmt_str("{}", cc_cpp_mod.as_some()));
  } else {
    write_file(ctx.cpp_path_, "");
  }

  if (cc_test_cpp_mod.is_some()) {
    write_file(ctx.cpp_test_path_, fmt_str("{}", cc_test_cpp_mod.as_some()));
  } else {
    write_file(ctx.cpp_test_path_, "");
  }

  if (cc_debug_cpp_mod.is_some()) {
    write_file(ctx.cpp_debug_path_, fmt_str("{}", cc_debug_cpp_mod.as_some()));
  } else {
    write_file(ctx.cpp_debug_path_, "");
  }
}

} // namespace langcc
