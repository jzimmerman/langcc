
#include "langcc_common.hpp"

#include "meta.hpp"

namespace langcc {

inline void pr(ostream& os, FmtFlags flags, Lexer_TopTokenInd x) {
    fmt(os, "Tok({}, {})", x.ind_, x.src_);
}


inline void hash_ser(SerBuf& buf, const Lexer_TopTokenInd& x) {
    hash_ser(buf, x.ind_);  // NOTE: not src
}


inline void hash_ser(SerBuf& buf, const Lexer_NFAAcc& x) {
    hash_ser(buf, x.case_id_);
    hash_ser(buf, x.arg_top_id_);
}


inline HashVal val_hash(const Lexer_NFAAcc& x) {
    return val_hash_base(x);
}


inline void pr(ostream& os, FmtFlags flags, Lexer_NFALabel_T x) {
    if (x->is_Eps()) {
        os << "eps";
    } else if (x->is_Eof()) {
        os << "eof";
    } else if (x->is_CharRange()) {
        auto x_min = x->as_CharRange()->char_min_;
        auto x_max = x->as_CharRange()->char_max_;
        os << char_display(static_cast<Ch>(x_min));
        if (x_max != x_min + 1) {
            os << "..";
            os << char_display(static_cast<Ch>(x_max));
        }
        os << fmt_str(" [ind={}]", x->as_CharRange()->ind_);
    } else {
        AX();
    }
}


inline void pr(ostream& os, FmtFlags flags, Lexer_NFAAcc x) {
    fmt(os, "Lexer_NFAAcc({}, {})", x.case_id_, x.arg_top_id_);
}


inline bool acc_set_has_conflicts(Set_T<Lexer_NFAAcc> s) {
    return s->length() > 1;
}


void lang_init_validate_tabulate_lexer_instr_emit_rec(
    meta::Node::LexerInstr_T instr, meta::Node::ParseExpr_T case_pat,
    LangCompileContext& ctx) {

    if (instr->is_Emit() || instr->is_PopEmit()) {
        Vec<ParseExpr_Base_T> emit_toks;

        Option_T<lang::meta::Node::ParseExpr_T> arg;
        if (instr->is_Emit()) {
            arg = instr->as_Emit()->arg_;
        } else if (instr->is_PopEmit()) {
            arg = Some<lang::meta::Node::ParseExpr_T>(instr->as_PopEmit()->arg_);
        } else {
            AX();
        }

        if (arg.is_some()) {
            auto ec = parse_expr_to_base_maybe(arg.as_some());
            if (ec.is_none()) {
                ctx.error(arg.as_some(), "Cannot emit non-base expression");
            }
            emit_toks.push(ec.as_some());
        } else {
            if (case_pat->is_Underscore()) {
                ctx.error(case_pat, "Cannot emit wildcard token");
            } else {
                auto ec = parse_expr_to_base_maybe(case_pat);
                if (ec.is_none()) {
                    ctx.error(case_pat, "Cannot emit non-base expression");
                }
                emit_toks.push(ec.as_some());
            }
        }
        for (auto emit_tok : emit_toks) {
            if (emit_tok->tok_->is_Id() || emit_tok->tok_->is_LitStr()) {
                if (!ctx.tokens_top_init_src_->contains_key(emit_tok)) {
                    ctx.tokens_top_init_src_->insert(
                        emit_tok, make_rc<Vec<meta::Node::LexerInstr_T>>());
                }
                ctx.tokens_top_init_src_->operator[](emit_tok)->push(instr);
            } else {
                ctx.error(instr, "Emitted token must be id or string literal");
            }
        }
    } else if (instr->is_Pass() || instr->is_Push() || instr->is_Pop() ||
        instr->is_PopExtract()) {
        // pass
    } else if (instr->is_MatchHistory()) {
        for (auto case_sub : *instr->as_MatchHistory()->cases_) {
            for (auto instr_sub : *case_sub->instrs_) {
                lang_init_validate_tabulate_lexer_instr_emit_rec(instr_sub, case_pat, ctx);
            }
        }
    } else {
        AX();
    }
}


void lexer_check_all_reach_visit_instr(
    lang::meta::Node::LexerInstr_T instr, Map_T<Ident_T, ParseExpr_T>& id_reach,
    Vec_T<Ident_T>& Q) {

    if (instr->is_Emit()) {
        auto cc = instr->as_Emit();
        if (cc->arg_.is_some()) {
            auto x = cc->arg_.as_some();
            if (x->is_Id()) {
                auto x_id = parse_expr_id_to_ident(x->as_Id()->id__);
                if (!id_reach->contains_key(x_id)) {
                    id_reach->insert(x_id, x);
                    Q->push_back(x_id);
                }
            }
        }
    } else if (instr->is_Pass() || instr->is_Push() || instr->is_Pop() || instr->is_PopExtract()) {
        // pass
    } else if (instr->is_PopEmit()) {
        auto cc = instr->as_PopEmit();
        auto x = cc->arg_;
        if (x->is_Id()) {
            auto x_id = parse_expr_id_to_ident(x->as_Id()->id__);
            if (!id_reach->contains_key(x_id)) {
                id_reach->insert(x_id, x);
                Q->push_back(x_id);
            }
        }
    } else if (instr->is_MatchHistory()) {
        for (auto case_sub : *instr->as_MatchHistory()->cases_) {
            for (auto instr_sub : *case_sub->instrs_) {
                lexer_check_all_reach_visit_instr(instr_sub, id_reach, Q);
            }
        }
    } else {
        AX();
    }
}


Option_T<LangCompileResult::Error::LexUnreach_T> lexer_check_all_reach(LangCompileContext& ctx) {
    auto id_reach = make_rc<Map<Ident_T, ParseExpr_T>>();
    auto Q = make_rc<Vec<Ident_T>>();

    for (auto mode : ctx.lexer_modes_) {
        for (auto case_ : *mode->cases_) {
            if (case_->tok_->is_Id()) {
                auto x_id = parse_expr_id_to_ident(case_->tok_->as_Id()->id__);
                if (!id_reach->contains_key(x_id)) {
                    id_reach->insert(x_id, case_->tok_);
                    Q->push_back(x_id);
                }
            } else if (case_->tok_->is_Alt()) {
                for (auto x : *case_->tok_->as_Alt()->xs_) {
                    if (x->is_Id()) {
                        auto x_id = parse_expr_id_to_ident(x->as_Id()->id__);
                        if (!id_reach->contains_key(x_id)) {
                            id_reach->insert(x_id, x);
                            Q->push_back(x_id);
                        }
                    }
                }
            }

            for (auto instr : *case_->instrs_) {
                lexer_check_all_reach_visit_instr(instr, id_reach, Q);
            }
        }
    }

    while (!Q->empty()) {
        auto curr = Q->pop_front_val();
        if (!ctx.tokens_def_.contains_key(curr)) {
            ctx.error(id_reach->operator[](curr), "Identifier not found in lexer tokens");
        }
        visit_lang_meta_Node(ctx.tokens_def_[curr], [&](lang::meta::Node_T sub) {
            if (sub->is_ParseExpr() && sub->as_ParseExpr()->is_Id()) {
                auto sub_id = parse_expr_id_to_ident(sub->as_ParseExpr()->as_Id()->id__);
                if (!id_reach->contains_key(sub_id)) {
                    id_reach->insert(sub_id, sub->as_ParseExpr());
                    Q->push_back(sub_id);
                }
            }
        });
    }

    auto ret = make_rc<Vec<Ident_T>>();
    for (auto def : ctx.tokens_def_) {
        if (!id_reach->contains_key(def.first)) {
            ret->push(def.first);
        }
    }

    if (ret->length() > 0) {
        return Some<LangCompileResult::Error::LexUnreach_T>(
            LangCompileResult::Error::LexUnreach::make(ret));
    }

    return None<LangCompileResult::Error::LexUnreach_T>();
}



void lexer_extract_alias_toks_sub_acc(
    Vec<ParseExpr_Base_T>& dst, meta::Node::ParseExpr_T x, ParseExpr_Base_T root,
    LangCompileContext& ctx) {

    auto xb = parse_expr_to_base_maybe(x);

    if (xb.is_some()) {
        if (xb.as_some()->tok_->is_Id()) {
            auto id = xb.as_some()->tok_->as_Id()->name_;
            auto decl = ctx.tokens_def_[id];
            if (decl->op_->is_DEF_ALIAS()) {
                lexer_extract_alias_toks_sub_acc(dst, decl->def__, root, ctx);
                return;
            }
        }
        dst.push(xb.as_some());

    } else if (x->is_Alt()) {
        auto cc = x->as_Alt();
        for (auto y : *cc->xs_) {
            lexer_extract_alias_toks_sub_acc(dst, y, root, ctx);
        }

    } else {
        ctx.error(x, fmt_str("Emitted token must be simple; emitted via {}", root));
    }
}


Vec_T<Lexer_TopTokenInd> lexer_token_inds_emit_reachable(
    ParseExpr_Base_T e, LangCompileContext& ctx) {

    auto ret = make_rc<Vec<Lexer_TopTokenInd>>();
    Set<Int> vis;
    Vec<ParseExpr_Base_T> Q;
    Q.push_back(e);
    while (!Q.empty()) {
        auto tok = Q.pop_front_val();
        if (ctx.tokens_top_by_id_rev_.contains_key(tok)) {
            if (!vis.contains(ctx.tokens_top_by_id_rev_[tok])) {
                vis.insert(ctx.tokens_top_by_id_rev_[tok]);
                Q.push_back(tok);
                auto tok_ind = Lexer_TopTokenInd::make(ctx.tokens_top_by_id_rev_[tok], tok);
                ret->push_back(tok_ind);
            }
        } else if (tok->tok_->is_Id()) {
            auto decl = ctx.tokens_def_[tok->tok_->as_Id()->name_];
            if (decl->op_->is_DEF_ALIAS()) {
                Vec<ParseExpr_Base_T> toks_sub;
                lexer_extract_alias_toks_sub_acc(toks_sub, decl->def__, tok, ctx);
                for (auto tok_sub : toks_sub) {
                    if (!ctx.tokens_top_by_id_rev_.contains_key(tok_sub)) {
                        LG_ERR("Not found: {}", tok_sub);
                        AX();
                    }
                    if (!vis.contains(ctx.tokens_top_by_id_rev_[tok_sub])) {
                        vis.insert(ctx.tokens_top_by_id_rev_[tok_sub]);
                        Q.push_back(tok_sub);
                        auto tok_ind = Lexer_TopTokenInd::make(
                            ctx.tokens_top_by_id_rev_[tok_sub], tok_sub);
                        ret->push_back(tok_ind);
                    }
                }
            } else {
                AX();
            }
        } else {
            AX();
        }
    }
    return ret;
}


LexerNFASub_T lexer_nfa_compile_sub(meta::Node::ParseExpr_T x, LangCompileContext& ctx);


template<typename N> void lexer_nfa_item_compile(
    meta::Node::ParseExpr_T src, N& nfa, Lexer_NFAVertex v_src, Lexer_NFAVertex v_dst,
    Option_T<meta::Node::ParseExpr_T> src_wildcard, LangCompileContext& ctx) {

    Lexer_NFALabel_T eps = Lexer_NFALabel::Eps::make();

    if (src->is_Alt()) {
        for (auto y : *src->as_Alt()->xs_) {
            lexer_nfa_item_compile(y, nfa, v_src, v_dst, src_wildcard, ctx);
        }

    } else if (src->is_AltExplicit()) {
        lexer_nfa_item_compile(
            src->as_AltExplicit()->e_, nfa, v_src, v_dst, src_wildcard, ctx);

    } else if (src->is_Id()) {
        auto id = parse_expr_to_base_maybe(src).as_some()->tok_->as_Id()->name_;
        if (!ctx.tokens_def_.contains_key(id)) {
            LG_ERR("Not found: {}", src);
            AX();
        }
        auto def = ctx.tokens_def_[id]->def__;
        lexer_nfa_item_compile(def, nfa, v_src, v_dst, src_wildcard, ctx);

    } else if (src->is_CharRange()) {
        auto cc = parse_expr_to_base_maybe(src).as_some()->tok_->as_LitCharRange();
        for (Int ri = 0; ri < ctx.char_ranges_.length(); ri++) {
            auto p = ctx.char_ranges_[ri];
            if (p.first >= cc->min__ && p.second <= cc->max__ + 1) {
                Lexer_NFALabel_T lbl = Lexer_NFALabel::CharRange::make(ri, p.first, p.second);
                NFA::add_edge(nfa, v_src, lbl, v_dst);
            }
        }

    } else if (src->is_UnicodeAny()) {
        for (Int ri = 0; ri < ctx.char_ranges_.length(); ri++) {
            auto p = ctx.char_ranges_[ri];
            Lexer_NFALabel_T lbl = Lexer_NFALabel::CharRange::make(ri, p.first, p.second);
            NFA::add_edge(nfa, v_src, lbl, v_dst);
        }

    } else if (src->is_AsciiBaseAny()) {
        for (Int ri = 0; ri < ctx.char_ranges_.length(); ri++) {
            auto p = ctx.char_ranges_[ri];
            if (p.second <= 0x80) {
                Lexer_NFALabel_T lbl = Lexer_NFALabel::CharRange::make(ri, p.first, p.second);
                NFA::add_edge(nfa, v_src, lbl, v_dst);
            }
        }

    } else if (src->is_StrLit()) {
        auto cc = parse_expr_to_base_maybe(src).as_some()->tok_->as_LitStr();
        auto v_curr = v_src;
        for (auto c : *cc->cs_) {
            auto v_next = NFA::gen_vertex(nfa);
            Option_T<Lexer_NFALabel_T> lbl = None<Lexer_NFALabel_T>();
            for (Int ri = 0; ri < ctx.char_ranges_.length(); ri++) {
                auto p = ctx.char_ranges_[ri];
                if (c >= p.first && c < p.second) {
                    lbl = Some<Lexer_NFALabel_T>(
                        Lexer_NFALabel::CharRange::make(ri, p.first, p.second));
                    break;
                }
            }
            NFA::add_edge(nfa, v_curr, lbl.as_some(), v_next);
            v_curr = v_next;
        }
        NFA::add_edge(nfa, v_curr, eps, v_dst);

    } else if (src->is_Concat()) {
        auto v_curr = v_src;
        for (auto y : *src->as_Concat()->xs_) {
            auto v_next = NFA::gen_vertex(nfa);
            lexer_nfa_item_compile(y, nfa, v_curr, v_next, src_wildcard, ctx);
            v_curr = v_next;
        }
        NFA::add_edge(nfa, v_curr, eps, v_dst);

    } else if (src->is_Minus()) {
        auto cc = src->as_Minus();
        auto dfa_lhs = lexer_nfa_compile_sub(cc->x_, ctx);
        auto dfa_rhs = lexer_nfa_compile_sub(cc->y_, ctx);
        auto labels_lhs = NFA::all_labels(dfa_lhs);
        auto labels_rhs = NFA::all_labels(dfa_rhs);
        auto all_labels = labels_lhs->with_union(labels_rhs);

        LOG(4, "Lexer DFA minus: LHS:\n{}\n", dfa_lhs);
        LOG(4, "Lexer DFA minus: RHS:\n{}\n", dfa_rhs);

        auto dfa_rhs_neg = NFA::dfa_negated(dfa_rhs, all_labels);

        LOG(4, "Lexer DFA minus: RHS neg:\n{}\n", dfa_rhs_neg);

        auto dfa_res_raw = NFA::dfa_product(dfa_lhs, dfa_rhs_neg);

        LOG(4, "Lexer DFA minus: res:\n{}\n", dfa_res_raw);

        auto dfa_res = NFA::vertex_stripped(dfa_res_raw);

        auto w_src = NFA::gen_vertex(nfa);
        auto w_dst = NFA::gen_vertex(nfa);
        NFA::splice_in(nfa, dfa_res, w_src, w_dst, eps);
        NFA::add_edge(nfa, v_src, eps, w_src);
        NFA::add_edge(nfa, w_dst, eps, v_dst);

    } else if (src->is_Optional()) {
        auto cc = src->as_Optional();
        lexer_nfa_item_compile(cc->x_, nfa, v_src, v_dst, src_wildcard, ctx);
        NFA::add_edge(nfa, v_src, eps, v_dst);

    } else if (src->is_Rep() || src->is_RepNonzero()) {
        meta::Node::ParseExpr_T x;
        if (src->is_Rep()) {
            x = src->as_Rep()->x_;
        } else {
            x = src->as_RepNonzero()->x_;
        }

        auto r0 = NFA::gen_vertex(nfa);
        auto r1 = NFA::gen_vertex(nfa);
        NFA::add_edge(nfa, v_src, eps, r0);
        NFA::add_edge(nfa, r1, eps, v_dst);

        auto w0 = NFA::gen_vertex(nfa);
        auto w1 = NFA::gen_vertex(nfa);
        NFA::add_edge(nfa, r0, eps, w0);
        NFA::add_edge(nfa, w1, eps, r1);

        lexer_nfa_item_compile(x, nfa, w0, w1, src_wildcard, ctx);

        NFA::add_edge(nfa, r1, eps, r0);
        if (src->is_Rep()) {
            NFA::add_edge(nfa, r0, eps, r1);
        }

    } else if (src->is_RepCount()) {
        auto cc = src->as_RepCount();
        auto v_curr = v_src;
        for (Int i = 0; i < string_to_int(cc->count_.to_std_string()).as_some(); i++) {
            auto v_next = NFA::gen_vertex(nfa);
            lexer_nfa_item_compile(cc->x_, nfa, v_curr, v_next, src_wildcard, ctx);
            v_curr = v_next;
        }
        NFA::add_edge(nfa, v_curr, eps, v_dst);

    } else if (src->is_Underscore()) {
        lexer_nfa_item_compile(
            src_wildcard.as_some(), nfa, v_src, v_dst, src_wildcard, ctx);

    } else if (src->is_False()) {
        // pass

    } else if (src->is_Eof()) {
        Lexer_NFALabel_T lbl = Lexer_NFALabel::Eof::make();
        NFA::add_edge(nfa, v_src, lbl, v_dst);

    } else if (src->is_Paren()) {
        lexer_nfa_item_compile(
            src->as_Paren()->x_, nfa, v_src, v_dst, src_wildcard, ctx);

    } else {
        ctx.error(src, "Not supported in lexer");
    }
}


LexerNFASub_T lexer_nfa_compile_sub(meta::Node::ParseExpr_T x, LangCompileContext& ctx) {
    auto nfa_sub = NFA::empty<Lexer_NFAVertex, Lexer_NFALabel_T, Unit>();
    auto start_sub = NFA::gen_vertex_start(nfa_sub);
    auto end_sub = NFA::gen_vertex_acc(nfa_sub, Unit{});

    lexer_nfa_item_compile(
        x, nfa_sub, start_sub, end_sub, None<meta::Node::ParseExpr_T>(), ctx);

    auto dfa_sub = NFA::nfa_subset_constr(nfa_sub);
    // Note: no conflicts since Acc = Unit

    auto ret = NFA::vertex_stripped(dfa_sub);
    return ret;
}


SwitchTable_T lexer_dfa_to_switch_table(const LexerNFA_T& D, LangCompileContext& ctx) {
    Int N = Graph::N(D->G_);
    Int M = ctx.char_ranges_.length();

    auto vs = make_rc<Vec<SwitchTable_T>>();

    for (Int i = 0; i < N; i++) {
        auto vs_i = make_rc<Vec<SwitchTable_T>>();

        Vec<Int> inds_i;
        for (Int j = 0; j < M + 1; j++) {  // 0 is eof
            inds_i.push(-1);
        }

        for (Int li = 0; li < D->G_->fwd_.EL_.at(i).size(); li++) {
            auto lbl_ind = D->G_->fwd_.EL_.at(i).at(li);
            const auto& nbr_inds = D->G_->fwd_.EV_.at(i).at(li);
            auto lbl = D->G_->L_->operator[](lbl_ind);
            AT(nbr_inds.size() == 1);
            if (lbl->is_Eof()) {
                inds_i[0] = nbr_inds[0];
            } else if (lbl->is_CharRange()) {
                inds_i[lbl->as_CharRange()->ind_ + 1] = nbr_inds[0];
            } else {
                AX();
            }
        }

        for (Int j = 0; j < M + 1; j++) {  // 0 is eof
            auto vij_base = make_rc<Vec<Int>>();
            vij_base->push_back(inds_i[j]);
            auto vij = SwitchTable::Base::make(vij_base);
            vs_i->push_back(vij);
        }

        vs->push_back(SwitchTable::IterMat::make(1, vs_i));
    }

    auto ret = SwitchTable::IterMat::make(0, vs);

    return ret;
}


void lexer_step_exec_compile_instr_acc(
    Vec_T<cc::Node_T>& dst, meta::Node::LexerInstr_T instr, meta::Node::LexerDecl::Mode_T mode,
    GenName fun_ns, CppGenContext& cc, LangCompileContext& ctx) {

    auto cpp_advance_instr = cc.qq("Stmt", "in_i = tok_hi;");
    auto cpp_consume_instr = cc.qq("Stmt", "cc_nop();");
    if (mode->ws_sig__.is_some()) {
        cpp_consume_instr = cc.qq("Stmt",
            "if (!mode_switch) { ws_state->consume(tok_lo, tok_hi, emit_dst); }");
    }
    auto cpp_non_ws_token_instr = cc.qq("Stmt", "cc_nop();");
    if (mode->ws_sig__.is_some()) {
        cpp_non_ws_token_instr = cc.qq("Stmt",
            "if (!mode_switch) { ws_state->non_ws_token(emit_dst); }");
    }
    auto cpp_pop_instr = cc.qq("Stmt", "ret = std::make_pair(langcc::DFATable::NEW_MODE_POP, -1);");
    auto cpp_mode_switch_instr = cc.qq("Stmt", "mode_switch = true;");

    if (instr->is_Emit()) {
        auto ic = instr->as_Emit();
        auto cpp_tok_emit = cc.qq("Expr", "tok");
        if (ic->arg_.is_some()) {
            auto arg = parse_expr_to_base_maybe(ic->arg_.as_some()).as_some();
            Int arg_id = ctx.tokens_top_by_id_rev_[arg];
            cpp_tok_emit = cc.qq("Expr", fmt_str("{}", arg_id));
        }
        if (mode->ws_sig__.is_some()) {
            dst->push_back(cpp_non_ws_token_instr);
        }
        dst->push_back(cc.qq("Stmt",
            "st->enqueue_emit_ext(emit_dst, ws_state, ",
            cpp_tok_emit, ", tok_lo, tok_hi, true);"));
        dst->push_back(cpp_advance_instr);
        if (mode->ws_sig__.is_some() && ic->arg_.is_none()) {
            dst->push_back(cpp_consume_instr);
        }

    } else if (instr->is_Pass()) {
        dst->push_back(cpp_advance_instr);
        if (mode->ws_sig__.is_some()) {
            dst->push_back(cpp_consume_instr);
        }

    } else if (instr->is_Push()) {
        auto ic = instr->as_Push();
        auto mode_name = ic->name_.to_std_string();
        auto mode_ind = ctx.lexer_modes_ind_[mode_name];
        dst->push_back(cc.qq("Stmt", "ret = std::make_pair(", fmt_str("{}", mode_ind), ", in_i);"));
        dst->push_back(cpp_mode_switch_instr);

    } else if (instr->is_Pop()) {
        dst->push_back(cpp_pop_instr);
        dst->push_back(cpp_mode_switch_instr);

    } else if (instr->is_PopExtract()) {
        dst->push_back(
            cc.qq("Stmt", "ret = std::make_pair(langcc::DFATable::NEW_MODE_POP_EXTRACT, -1);"));
        dst->push_back(cpp_mode_switch_instr);

    } else if (instr->is_PopEmit()) {
        auto ic = instr->as_PopEmit();
        auto arg = parse_expr_to_base_maybe(ic->arg_).as_some();
        Int arg_id = ctx.tokens_top_by_id_rev_[arg];
        dst->push_back(cc.qq("Stmt", "ret = std::make_pair(langcc::DFATable::NEW_MODE_POP_EMIT,",
            fmt_str("{}", arg_id), ");"));
        dst->push_back(cpp_mode_switch_instr);

    } else if (instr->is_MatchHistory()) {
        auto ic = instr->as_MatchHistory();
        auto cc_cases = make_rc<Vec<cc::Node_T>>();
        auto tok = cc.qq_expr(cc.gen_id_fresh(fun_ns, "last_tok"));
        dst->push_back(cc.qq("Stmt", "auto", tok, "=", "st->last_tok();"));
        bool has_default = false;
        for (Int i = 0; i < ic->cases_->length(); i++) {
            auto case_ = ic->cases_->operator[](i);
            Option_T<Vec_T<Int>> arg_ids;
            if (case_->tok_->is_Underscore()) {
                if (i != ic->cases_->length() - 1) {
                    ctx.error(case_, "Wildcard case must appear as last item in block");
                }
                arg_ids = None<Vec_T<Int>>();
            } else if (case_->tok_->is_Alt()) {
                auto toks_alt = case_->tok_->as_Alt()->xs_;
                auto arg_ids_alt = make_rc<Vec<Int>>();
                for (auto tok_alt : *toks_alt) {
                    auto arg_m = parse_expr_to_base_maybe(tok_alt);
                    if (arg_m.is_none()) {
                        ctx.error(case_, "Case pattern must be a base token or underscore");
                    }
                    auto arg = arg_m.as_some();
                    if (!ctx.tokens_top_by_id_rev_.contains_key(arg)) {
                        ctx.error(case_,
                            "Case pattern token not found in emitted tokens of lexer");
                    }
                    auto arg_id = ctx.tokens_top_by_id_rev_[arg];
                    arg_ids_alt->push_back(arg_id);
                }
                arg_ids = Some<Vec_T<Int>>(arg_ids_alt);
            } else {
                auto arg_m = parse_expr_to_base_maybe(case_->tok_);
                if (arg_m.is_none()) {
                    ctx.error(case_, "Case pattern must be a base token or underscore");
                }
                auto arg = arg_m.as_some();
                if (!ctx.tokens_top_by_id_rev_.contains_key(arg)) {
                    ctx.error(case_, "Case pattern token not found in emitted tokens of lexer");
                }
                auto arg_ids_singleton = make_rc<Vec<Int>>();
                auto arg_id = ctx.tokens_top_by_id_rev_[arg];
                arg_ids_singleton->push_back(arg_id);
                arg_ids = Some<Vec_T<Int>>(arg_ids_singleton);
            }

            auto cc_case_body = make_rc<Vec<cc::Node_T>>();
            for (auto instr_sub : *case_->instrs_) {
                lexer_step_exec_compile_instr_acc(cc_case_body, instr_sub, mode, fun_ns, cc, ctx);
            }
            cc.qq_stmt_acc(cc_case_body, "break;");

            if (arg_ids.is_none()) {
                auto cc_case = cc.qq_switch_case("default: {", *cc_case_body, "}");
                cc_cases->push_back(cc_case);
                has_default = true;
            } else {
                for (auto arg_id : *arg_ids.as_some()) {
                    auto cc_case = cc.qq_switch_case("case", fmt_str("{}", arg_id),
                        ": {", *cc_case_body, "}");
                    cc_cases->push_back(cc_case);
                }
            }
        }
        if (!has_default) {
            cc_cases->push_back(
                cc.qq_switch_case("default: { st->error_here_match_history(in_i); }"));
        }
        dst->push_back(cc.qq("Stmt", "switch (", tok, ") {", *cc_cases, "}"));

    } else {
        LG_ERR("{}", instr);
        AX();
    }
}


Map_T<meta::Node::LexerDecl::Mode_T, LexerNFA_T> lexer_compile_dfas(LangCompileContext& ctx) {
    auto ret = make_rc<Map<meta::Node::LexerDecl::Mode_T, LexerNFA_T>>();

    for (auto mode : ctx.lexer_modes_) {
        auto nfa = NFA::empty<Lexer_NFAVertex, Lexer_NFALabel_T, Lexer_NFAAcc>();
        auto v_start = NFA::gen_vertex_start(nfa);

        for (Int case_id = 0; case_id < mode->cases_->length(); case_id++) {
            auto case_ = mode->cases_->operator[](case_id);
            auto pat = case_->tok_;

            auto src_wildcard = None<meta::Node::ParseExpr_T>();
            if (pat->is_Underscore()) {
                if (case_id != mode->cases_->length() - 1) {
                    ctx.error(case_, "Wildcard in non-final position");
                }
                auto alt_args = make_rc<Vec<meta::Node::ParseExpr_T>>();
                for (Int j = 0; j < case_id; j++) {
                    alt_args->push_back(mode->cases_->operator[](j)->tok_);
                }
                auto bounds = pat->bounds_;
                auto w = meta::Node::ParseExpr::Minus::make(ctx.gen_meta_->gen(),
                    bounds, false, -1, attr_mask_trivial(), parser_lookahead_trivial(),
                        meta::Node::ParseExpr::UnicodeAny::make(
                            ctx.gen_meta_->gen(),
                            bounds, false, -1, attr_mask_trivial(), parser_lookahead_trivial()),
                        meta::Node::ParseExpr::Alt::make(
                            ctx.gen_meta_->gen(), bounds, false, -1, attr_mask_trivial(),
                            parser_lookahead_trivial(), alt_args));
                src_wildcard = Some<meta::Node::ParseExpr_T>(w);
            }

            if (lexer_instrs_has_emit_match(case_->instrs_)) {
                if (src_wildcard.is_some()) {
                    ctx.error(case_, "Cannot emit wildcard as lexer token");
                }
                auto pat_base = parse_expr_to_base_maybe(pat).as_some();
                auto emit_ids = lexer_token_inds_emit_reachable(pat_base, ctx);
                for (auto emit_id : *emit_ids) {
                    auto acc = Lexer_NFAAcc::emit_match(case_id, emit_id);
                    auto v_dst = NFA::gen_vertex_acc(nfa, acc);
                    auto emit_expr = ctx.tokens_top_by_id_[emit_id.ind_];
                    auto v_src_curr = NFA::gen_vertex(nfa);
                    Lexer_NFALabel_T eps = Lexer_NFALabel::Eps::make();
                    NFA::add_edge(nfa, v_start, eps, v_src_curr);

                    lexer_nfa_item_compile(
                        emit_expr->src_.as_some(), nfa, v_src_curr, v_dst, src_wildcard, ctx);
                }
            } else {
                auto acc = Lexer_NFAAcc::no_emit_match(case_id);
                auto v_dst = NFA::gen_vertex_acc(nfa, acc);
                lexer_nfa_item_compile(pat, nfa, v_start, v_dst, src_wildcard, ctx);
            }
        }

        LOG(3, "Lexer NFA ({}):\n{}\n\n", mode, nfa);

        auto dfa_res = NFA::nfa_subset_constr(nfa);

        LOG(3, "Lexer DFA full ({}):\n{}\n\n", mode, dfa_res);

        if (NFA::has_conflicts(dfa_res)) {
            for (auto vs : *dfa_res->G_->V_) {
                auto vsi = dfa_res->G_->V_->index_of_maybe(vs).as_some();
                auto acc_i = dfa_res->acc_->operator[](vsi);
                if (acc_i->length() > 1) {
                    auto Q = make_rc<Vec<Set_T<Int>>>();
                    auto v_start = dfa_res->G_->V_->operator[](dfa_res->start_.as_some());
                    Q->push_back(v_start);
                    auto m = make_rc<
                        Map<Set_T<Int>, Option_T<pair<Lexer_NFALabel_T, Set_T<Int>>>>>();
                    m->insert(v_start, None<pair<Lexer_NFALabel_T, Set_T<Int>>>());
                    while (!Q->empty()) {
                        auto curr = Q->pop_front_val();
                        auto es = NFA::outgoing_edges(dfa_res, curr);
                        for (auto [lbl, nbrs] : *es) {
                            for (auto nbr : *nbrs) {
                                if (!m->contains_key(nbr)) {
                                    m->insert(nbr, Some<pair<Lexer_NFALabel_T, Set_T<Int>>>(
                                        make_pair(lbl, curr)));
                                    Q->push_back(nbr);
                                }
                            }
                        }
                    }
                    auto conflict_lbl_seq = make_rc<Vec<Lexer_NFALabel_T>>();
                    auto curr = vs;
                    while (m->operator[](curr).is_some()) {
                        auto p = m->operator[](curr).as_some();
                        conflict_lbl_seq->push_back(p.first);
                        curr = p.second;
                    }
                    conflict_lbl_seq->reverse();
                    LangCompileResult::Error_T err = LangCompileResult::Error::Other::make(
                        fmt_str("Lexer conflict: {}", conflict_lbl_seq));
                    throw err;
                }
            }
        }
        auto dfa = NFA::vertex_stripped(dfa_res);

        AT(dfa->start_.as_some() == 0);  // Hardcoded in lexer_proc_mode_loop

        ret->insert(mode, dfa);

        LOG(3, "Lexer DFA final ({}):\n{}\n\n", mode, dfa);
    }

    return ret;
}


Option_T<LexerModeTrivial_T> lexer_extract_trivial_maybe(meta::Node::LexerDecl::Mode_T mode) {
    LexerModeTrivial_T ret;
    bool has_default = false;
    ret.cases_ = make_rc<Vec<pair<Option_T<Vec_T<Ch>>, LexerInstrs>>>();


    if (mode->ws_sig__.is_some()) {
        return None<LexerModeTrivial_T>();
    }

    for (auto case_ : *mode->cases_) {
        if (case_->tok_->is_Underscore()) {
            AT(!has_default);
            if (case_->instrs_->length() != 1 || !case_->instrs_->only()->is_Pass()) {
                return None<LexerModeTrivial_T>();
            }
            has_default = true;
            continue;
        }

        auto xb = parse_expr_to_base_maybe(case_->tok_);
        if (xb.is_none()) {
            return None<LexerModeTrivial_T>();
        }
        auto tok = xb.as_some()->tok_;

        Option_T<Vec_T<Ch>> cs;

        if (tok->is_Id() || tok->is_Special()) {
            return None<LexerModeTrivial_T>();
        } else if (tok->is_LitEps()) {
            AX();
        } else if (tok->is_LitEof()) {
            cs = None<Vec_T<Ch>>();
        } else if (tok->is_LitCharRange()) {
            AX();
        } else if (tok->is_LitStr()) {
            auto cc = tok->as_LitStr();
            cs = Some<Vec_T<Ch>>(cc->cs_);
        } else {
            AX();
        }

        ret.cases_->push_back(make_pair(cs, case_->instrs_));
    }

    if (!has_default) {
       return None<LexerModeTrivial_T>();
    }

    return Some<LexerModeTrivial_T>(ret);
}

}
