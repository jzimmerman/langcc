#pragma once

#include "langcc_util.hpp"

#include "cc.hpp"
#include "data.hpp"
#include "meta.hpp"

#include "common.hpp"

#include "langcc.hpp"
#include "datacc.hpp"

#include "grammar.hpp"
#include "nfa.hpp"

using namespace common;
using namespace lang;

#define LR_NFA_Args LRVertex_T, LRLabel_T, LRLookAction_T

using LR_NFA_T = NFA_T<LR_NFA_Args>;

#define LR_DFA_Args Set_T<LRVertex_T>, LRLabel_T, LRLookAction_T

using LR_DFA_T = NFA_T<LR_DFA_Args>;

struct LangCompileContext {
    lang::meta::Node::Lang_T src_;
    Gensym_T gen_meta_;

    CppGenContext cc_;
    CppGenContext cc_test_;
    CppGenContext cc_debug_;

    DataGenContext data_;

    string src_base_name_;
    string dst_path_;

    string hpp_name_;
    string hpp_path_;
    string cpp_path_;
    string cpp_test_path_;
    string cpp_debug_path_;

    Int lr_k_;

    lang::meta::Node::Stanza::Tokens_T tokens_;
    lang::meta::Node::Stanza::Lexer_T lexer_;
    lang::meta::Node::Stanza::Parser_T parser_;

    // Lexer metadata
    Vec<meta::Node::LexerDecl::Mode_T> lexer_modes_;
    Map<string, Int> lexer_modes_ind_;
    Int lexer_main_mode_ind_;
    Map<Ident_T, meta::Node::TokenDecl_T> tokens_def_;
    Map_T<ParseExpr_Base_T, Vec_T<meta::Node::LexerInstr_T>> tokens_top_init_src_;
    Map<ParseExpr_Base_T, ParseExpr_Base_T> tokens_top_traversal_alias_parent_;
    map<Int, Int> char_thresholds_;
    Vec<IntPair> char_ranges_;
    Vec<ParseExpr_Base_T> tokens_top_by_id_;
    Map<ParseExpr_Base_T, Int> tokens_top_by_id_rev_;

    // Parser metadata
    ParseExprPropsMap_T parse_expr_props_;
    bool parser_name_strict_;
    VecUniq_T<Ident_T> parser_syms_top_;
    Option_T<string> parser_sym_top_main_;
    Map_T<Ident_T, Rule_T> parser_rules_;
    Map_T<Ident_T, Int> parser_rule_inds_;
    Vec_T<AttrClause_T> parser_attr_clauses_;
    Option_T<lang::meta::Node::ParserDecl::Prec_T> parser_prec_;
    Int parser_prec_n_;
    Map_T<Sym_T, Map_T<AttrKey_T, AttrType_T>> parser_attr_domains_;
    Map_T<Ident_T, Vec_T<ProdConstr_T>> parser_attr_constr_by_rule_;
    Set_T<Ident_T> parser_rule_explicit_def_ids_;
    Set_T<Ident_T> parser_rule_all_ids_;
    Set_T<Ident_T> parser_rule_non_alias_ids_;
    Map_T<IdentBase_T, Sym_T> Nm_;
    Map_T<Ident_T, Sym_T> Np_;

    Grammar_T Gr_flat_;
    Gensym_T Gr_flat_nonterm_gensym_;
    Map_T<Int, Gensym_T> Gr_flat_prod_gensyms_;
    Map_T<Prod_T, Option_T<AttrLeaf_T>> Gr_flat_lhs_flatten_leaves_;
    Map_T<Prod_T, Vec_T<Option_T<AttrLeaf_T>>> Gr_flat_rhs_flatten_leaves_;
    Gensym_T parser_attr_gensym_;
    Map_T<Prod_T, VecUniq_T<ProdConstrFlat_T>> Gr_flat_prod_constrs_;
    Option_T<Set_T<Sym_T>> cps_triggers_filter_;
    Map_T<Sym_T, Map_T<Sym_T, Int>> parser_sym_to_cps_uniq_inds_;
    Map_T<ProdId_T, Int> parser_prod_id_to_cps_uniq_inds_;
    Map_T<Prod_T, Option_T<AttrLeaf_T>> Gr_cps_lhs_flatten_leaves_;
    Map_T<Prod_T, Vec_T<Option_T<AttrLeaf_T>>> Gr_cps_rhs_flatten_leaves_;
    Int cps_flat_diff_max_;

    LR_NFA_T parser_nfa_final_;
    LR_DFA_T parser_dfa_final_;

    Grammar_T Gr_cps_;
    GrammarProdConstrs_T Gr_cps_prod_constrs_;
    Map_T<Prod_T, Prod_T> cps_prod_map_rev_;

    Map_T<Ident_T, GenType_T> gen_dt_map_;
    Map_T<Ident_T, WriteInstr_T> gen_wr_map_;
    Map_T<Prod_T, UnwindInstr_T> gen_rd_map_;
    Map_T<Ident_T, pair<Ident_T, IdentBase_T>> gen_dt_parent_mapping_;

    LexOutput_T lex_res_;

    LangCompileContext() = delete;
    LangCompileContext(LangCompileContext&) = delete;
    LangCompileContext(LangCompileContext&&) = delete;
    LangCompileContext& operator=(LangCompileContext&) = delete;

    inline LangCompileContext(lang::meta::Node::Lang_T src, Gensym_T gen_meta,
        LexOutput_T lex_res, string src_base_name, string dst_path, Int k)
        : src_(src), gen_meta_(gen_meta), lex_res_(lex_res),
          src_base_name_(src_base_name), dst_path_(dst_path), lr_k_(k) {

        hpp_name_ = fmt_str("{}__gen.hpp", src_base_name);
        hpp_path_ = fmt_str("{}/{}__gen.hpp", dst_path, src_base_name);
        cpp_path_ = fmt_str("{}/{}__gen.cpp", dst_path, src_base_name);
        cpp_test_path_ = fmt_str("{}/{}__gen_test.cpp", dst_path, src_base_name);
        cpp_debug_path_ = fmt_str("{}/{}__gen_debug.cpp", dst_path, src_base_name);
    }

    inline void error(meta::Node_T x, string msg) {
        auto err_desc = fmt_str("Error: {}\nExpression: {}\n\n{}", msg, x,
            this->lex_res_->location_fmt_str(x->bounds_));
        auto err = LangCompileResult::Error::Other::make(err_desc);
        throw lang_compile_error(err);
    }
};


// Normalization/validation
void lang_init_validate(LangCompileContext& ctx);
void lang_init_validate_tabulate_lexer_instr_emit_rec(
    meta::Node::LexerInstr_T instr, meta::Node::ParseExpr_T case_pat,
    LangCompileContext& ctx);
void parser_Gr_flat_tabulate_defined_nonterm(LangCompileContext& ctx, IdentBase_T ident);
bool lang_name_is_lower_reserved(string x);
meta::Node::Lang_T xform_lang_normalize(
    Gensym_T gen,
    ParseExprPropsMap_T& dst_props,
    meta::Node::Lang_T L,
    LangCompileContext& ctx);
meta::Node::ParseExpr_T xform_parse_expr_normalize(
    meta::Node::ParseExpr_T e,
    ParseExprPropsMap_T& dst_props,
    Gensym_T gen,
    Map_T<Ident_T, ParseExpr_T> parser_aliases_by_ident,
    LangCompileContext& ctx);


// Lexer
void lexer_extract_alias_toks_sub_acc(
    Vec<ParseExpr_Base_T>& dst, meta::Node::ParseExpr_T x, ParseExpr_Base_T root,
    LangCompileContext& ctx);
using LexerInstrs = Vec_T<meta::Node::LexerInstr_T>;
struct LexerModeTrivial_T {
    Vec_T<pair<Option_T<Vec_T<Ch>>, LexerInstrs>> cases_;
};
Option_T<LexerModeTrivial_T> lexer_extract_trivial_maybe(meta::Node::LexerDecl::Mode_T mode);
using Lexer_NFAVertex = Int;
struct Lexer_TopTokenInd {
    Int ind_;
    ParseExpr_Base_T src_;

    static inline Lexer_TopTokenInd make(Int ind, ParseExpr_Base_T src) {
        Lexer_TopTokenInd ret;
        ret.ind_ = ind;
        ret.src_ = src;
        return ret;
    }
};
struct Lexer_NFAAcc {
    Int case_id_;
    Option_T<Lexer_TopTokenInd> arg_top_id_;

    static inline Lexer_NFAAcc no_emit_match(Int case_id) {
        Lexer_NFAAcc ret;
        ret.case_id_ = case_id;
        ret.arg_top_id_ = None<Lexer_TopTokenInd>();
        return ret;
    }

    static inline Lexer_NFAAcc emit_match(Int case_id, Lexer_TopTokenInd arg_top_id) {
        Lexer_NFAAcc ret;
        ret.case_id_ = case_id;
        ret.arg_top_id_ = Some<Lexer_TopTokenInd>(arg_top_id);
        return ret;
    }
};
#define LexerNFA_Args Lexer_NFAVertex, Lexer_NFALabel_T, Lexer_NFAAcc
using LexerNFA_T = NFA_T<LexerNFA_Args>;
#define LexerNFASub_Args Lexer_NFAVertex, Lexer_NFALabel_T, Unit
using LexerNFASub_T = NFA_T<LexerNFASub_Args>;
void lexer_step_exec_compile_instr_acc(
    Vec_T<cc::Node_T>& dst, meta::Node::LexerInstr_T instr, meta::Node::LexerDecl::Mode_T mode,
    GenName fun_ns, CppGenContext& cc, LangCompileContext& ctx);
Vec_T<Lexer_TopTokenInd> lexer_token_inds_emit_reachable(
    ParseExpr_Base_T e, LangCompileContext& ctx);
Map_T<meta::Node::LexerDecl::Mode_T, LexerNFA_T> lexer_compile_dfas(
    LangCompileContext& ctx);


// Flattening
pair<Vec_T<Sym_T>, Vec_T<bool>> sym_flatten_result_extract_vec(
    Vec_T<SymFlattenResult_T> rhs);
pair<Vec_T<Sym_T>, Vec_T<bool>> sym_flatten_result_extract_vec(
    Vec_T<SymFlattenResultCPS_T> rhs);
pair<Sym_T, SymFlattenResult_T> parser_flatten_gen_nonterm(
    LangCompileContext& ctx, Sym_T sym, Rule_T rule_ctx, bool unfold,
    Option_T<ParseExpr_T> src);
void parser_Gr_flat_add_prod(
    LangCompileContext& ctx,
    Sym_T lhs,
    Option_T<AttrLeaf_T> lhs_leaf,
    Vec_T<SymFlattenResult_T> rhs,
    meta::Node::ParserDecl::Rule_T rule_ctx,
    UnwindInstr_T rd_instr);
void parser_flatten_grammar_rules(LangCompileContext& ctx);
void parser_tabulate_syms_top(LangCompileContext& ctx);


// Attribute analysis
void parser_attr_propagate_flattened(LangCompileContext& ctx);
void parser_prod_constr_cps_refine_domains(LangCompileContext& ctx);
void parser_infer_attrs_top(LangCompileContext& ctx);


// CPS
void ctx_Gr_cps_init(LangCompileContext& ctx);
void parser_grammar_to_cps(LangCompileContext& ctx);
void parser_Gr_cps_add_prod(
    LangCompileContext& ctx,
    Sym_T lhs,
    Option_T<AttrLeaf_T> lhs_leaf,
    Vec_T<SymFlattenResultCPS_T> rhs,
    Vec_T<Option_T<AttrLeaf_T>> rhs_leaves,
    Prod_T orig_flat);


// LR analysis
LRVertex_T lr_vertex_without_lookahead(LRVertex_T v);
void pr(ostream& os, FmtFlags flags, GrammarSymConstrGen_T G_gen);
Int lr_conflict_exemplar_length_total(LRStringExemplarBidir_T exr);
Int lr_conflict_exemplar_length_pre(LRStringExemplarBidirBounded_T exr);
LRStringExemplar_T lr_conflict_extract_exemplar_sym(LRSym_T sym, AttrSet_T attr,
    GrammarSymConstrGen_T G_gen);
Vec_T<LRStringExemplarBounded_T> lr_conflict_extract_exemplars_tail(
    LRVertex_T v, bool proper,
    GrammarSymConstrGen_T G_gen, GrammarProdConstrs_T G_constrs);
StringSet_T<Unit> lr_sym_constr_gen(
    Sym_T sym,
    AttrBoundSet_T bounds_sym,
    GrammarSymConstrGen_T G_gen,
    Int k,
    GrammarProdConstrs_T G_constrs);
StringSet_T<Unit> lr_prod_comp_constr_gen(
    Prod_T prod,
    Int i,
    AttrBoundSet_T bounds,
    GrammarSymConstrGen_T G_gen,
    Int k,
    GrammarProdConstrs_T G_constrs);
StringSet_T<Unit> lr_prod_tail_constr_gen(
    DottedProd_T dp,
    AttrBoundSet_T bounds,
    StringSet_T<Unit> la_end,
    GrammarSymConstrGen_T G_gen,
    Int k,
    GrammarProdConstrs_T G_constrs);
GrammarSymConstrGen_T parser_lr_gen_inhabitants(Grammar_T G, Int k, LangCompileContext& ctx);
Map_T<SymStr_T, Map_T<LRAction_T, Set_T<LRVertex_T>>> lr_tabulate_nfa_acc(
    LR_NFA_T N, Set_T<LRVertex_T> vs);
Vec_T<LRConflict_T> parser_lr_analysis(LangCompileContext& ctx);


// Encoding
Int trunc_u16_s2u(Int x);
pair<Int, Int> trunc_u16_s2u_x2(Int x);
void switch_table_encode_acc_u16(Vec_T<Int>& dst, SwitchTable_T& tt);
Vec_T<Int> switch_table_encode_u16(SwitchTable_T& tt);
SwitchTable_T lexer_dfa_to_switch_table(const LexerNFA_T& D, LangCompileContext& ctx);
Int attr_key_to_index(Sym_T sym, AttrKey_T k, LangCompileContext& ctx);
SwitchTable_T parser_lr_vertex_dfa_step_impl_table_rec(
    LRSym_T sym, Map_T<Map_T<AttrKey_T, Int>, Int> table, LangCompileContext& ctx);
SwitchTable_T parser_lr_vertex_dfa_step_impl_table(LangCompileContext& ctx, LR_DFA_T D);
IntPair parser_lr_action_dfa_acc_to_indices(LRAction_T acc, LangCompileContext& ctx);
SwitchTable_T parser_lr_action_by_vertex_impl_table_rec(
    VecUniq_T<pair<SymStr_T, LRAction_T>> part_table_filt,
    Option_T<LRAction_T> acc_default,
    Vec_T<LRSym_T> buf,
    Int k,
    LangCompileContext& ctx);
VecUniq_T<LRSym_T> grammar_all_lr_syms(Grammar_T G);
Int grammar_sym_to_ind_flat(LangCompileContext& ctx, LRSym_T sym);
SwitchTable_T parser_lr_action_by_vertex_impl_table_basic(
    LangCompileContext& ctx, LR_DFA_T D, Int k);
pair<Vec_T<Int>, Vec_T<Int>> parser_lr_action_by_vertex_impl_table_opt(
    LangCompileContext& ctx, LR_NFA_T N, LR_DFA_T D, Int k);


// Code generation
void lang_emit_preambles(LangCompileContext& ctx);
void lang_emit_datatype_defs(LangCompileContext& ctx);
void lang_emit_writer_defs(LangCompileContext& ctx);
void lang_emit_parser_defs(LangCompileContext& ctx);
void lang_emit_global_defs(LangCompileContext& ctx);
void lang_emit_test_defs(LangCompileContext& ctx);
void lang_emit_debug_defs(LangCompileContext& ctx);
void lang_emit_extract_final(LangCompileContext& ctx);
data::Node_T data_gen_type_to_node(DataGenContext data, common::GenType_T ty);
void data_gen_dtype_acc(
    DataGenContext data, common::Ident_T id, common::GenDatatype_T dt,
    common::Ident_T parent);
Vec_T<string> lower_name_ident_struct(common::Ident_T id);
void lexer_gen_cpp_defs(
    LangCompileContext& ctx, CppGenContext& cc, string src_base_name,
    Map_T<meta::Node::LexerDecl::Mode_T, LexerNFA_T> lexer_mode_dfas);
void parser_lr_write_impl_gen_cpp_instr(Vec_T<cc::Node_T>& dst, WriteInstr_T wr,
    cc::Node_T curr, GenName fun_ns,
    string src_base_name, CppGenContext& cc, LangCompileContext& ctx);
cc::Node_T parser_lr_unwind_impl_gen_cpp(
    CppGenContext& cc, Prod_T prod_cps, Prod_T prod_flat, LangCompileContext& ctx,
    string src_base_name);
