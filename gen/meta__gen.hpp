#pragma once

#include <langcc_rt.hpp>

namespace lang::meta::lexer {
    rc_ptr<lang_rt::DFALabelIdVec> label_ids_ascii();

    rc_ptr<lang_rt::DFALabelIdMap> label_ids_unicode();
}

namespace lang::meta::lexer::body {
    lang_rt::DFAVertexId step(lang_rt::DFAVertexId v, lang_rt::DFALabelId lbl);

    __attribute__((always_inline)) lang_rt::DFAActionWithToken acc(lang_rt::DFAVertexId v);

    __attribute__((always_inline)) IntPair step_exec(ptr<lang_rt::LexerState> st, ptr<lang_rt::SymItemVec> emit_dst, ptr<lang_rt::LexWhitespaceState> ws_state, lang_rt::DFAActionId acc, lang_rt::TokenId tok, Int& in_i, Int& tok_lo, Int& tok_hi);

    Int proc_mode_loop(ptr<lang_rt::LexerState> st, ptr<lang_rt::SymItemVec> emit_dst, Int mode_start_pos, Int mode_buf_pos);
}

namespace lang::meta::lexer::comment_single {
    lang_rt::DFAVertexId step(lang_rt::DFAVertexId v, lang_rt::DFALabelId lbl);

    __attribute__((always_inline)) lang_rt::DFAActionWithToken acc(lang_rt::DFAVertexId v);

    __attribute__((always_inline)) IntPair step_exec(ptr<lang_rt::LexerState> st, ptr<lang_rt::SymItemVec> emit_dst, ptr<lang_rt::LexWhitespaceState> ws_state, lang_rt::DFAActionId acc, lang_rt::TokenId tok, Int& in_i, Int& tok_lo, Int& tok_hi);

    Int proc_mode_loop(ptr<lang_rt::LexerState> st, ptr<lang_rt::SymItemVec> emit_dst, Int mode_start_pos, Int mode_buf_pos);
}

#pragma once

#include <langcc_util.hpp>

namespace lang::meta::Node::Lang {
    struct _T;
}

namespace lang::meta::Node {
    using Lang_T = rc_ptr<lang::meta::Node::Lang::_T>;
}

namespace lang::meta::Node::Stanza::Tokens {
    struct _T;
}

namespace lang::meta::Node::Stanza {
    using Tokens_T = rc_ptr<lang::meta::Node::Stanza::Tokens::_T>;
}

namespace lang::meta::Node::Stanza::Lexer {
    struct _T;
}

namespace lang::meta::Node::Stanza {
    using Lexer_T = rc_ptr<lang::meta::Node::Stanza::Lexer::_T>;
}

namespace lang::meta::Node::Stanza::Parser {
    struct _T;
}

namespace lang::meta::Node::Stanza {
    using Parser_T = rc_ptr<lang::meta::Node::Stanza::Parser::_T>;
}

namespace lang::meta::Node::Stanza::Test {
    struct _T;
}

namespace lang::meta::Node::Stanza {
    using Test_T = rc_ptr<lang::meta::Node::Stanza::Test::_T>;
}

namespace lang::meta::Node::Stanza::CompileTest {
    struct _T;
}

namespace lang::meta::Node::Stanza {
    using CompileTest_T = rc_ptr<lang::meta::Node::Stanza::CompileTest::_T>;
}

namespace lang::meta::Node::TokenDecl::op::DEF {
    struct _T;
}

namespace lang::meta::Node::TokenDecl::op {
    using DEF_T = rc_ptr<lang::meta::Node::TokenDecl::op::DEF::_T>;
}

namespace lang::meta::Node::TokenDecl::op::DEF_ALIAS {
    struct _T;
}

namespace lang::meta::Node::TokenDecl::op {
    using DEF_ALIAS_T = rc_ptr<lang::meta::Node::TokenDecl::op::DEF_ALIAS::_T>;
}

namespace lang::meta::Node::TokenDecl::op {
    struct _T;
}

namespace lang::meta::Node::TokenDecl {
    using op_T = rc_ptr<lang::meta::Node::TokenDecl::op::_T>;
}

namespace lang::meta::Node::TokenDecl {
    struct _T;
}

namespace lang::meta::Node {
    using TokenDecl_T = rc_ptr<lang::meta::Node::TokenDecl::_T>;
}

namespace lang::meta::Node::LexerDecl::Main {
    struct _T;
}

namespace lang::meta::Node::LexerDecl {
    using Main_T = rc_ptr<lang::meta::Node::LexerDecl::Main::_T>;
}

namespace lang::meta::Node::LexerDecl::Mode {
    struct _T;
}

namespace lang::meta::Node::LexerDecl {
    using Mode_T = rc_ptr<lang::meta::Node::LexerDecl::Mode::_T>;
}

namespace lang::meta::Node::LexerModeCase {
    struct _T;
}

namespace lang::meta::Node {
    using LexerModeCase_T = rc_ptr<lang::meta::Node::LexerModeCase::_T>;
}

namespace lang::meta::Node::LexerInstr::Emit {
    struct _T;
}

namespace lang::meta::Node::LexerInstr {
    using Emit_T = rc_ptr<lang::meta::Node::LexerInstr::Emit::_T>;
}

namespace lang::meta::Node::LexerInstr::Pass {
    struct _T;
}

namespace lang::meta::Node::LexerInstr {
    using Pass_T = rc_ptr<lang::meta::Node::LexerInstr::Pass::_T>;
}

namespace lang::meta::Node::LexerInstr::Push {
    struct _T;
}

namespace lang::meta::Node::LexerInstr {
    using Push_T = rc_ptr<lang::meta::Node::LexerInstr::Push::_T>;
}

namespace lang::meta::Node::LexerInstr::Pop {
    struct _T;
}

namespace lang::meta::Node::LexerInstr {
    using Pop_T = rc_ptr<lang::meta::Node::LexerInstr::Pop::_T>;
}

namespace lang::meta::Node::LexerInstr::PopExtract {
    struct _T;
}

namespace lang::meta::Node::LexerInstr {
    using PopExtract_T = rc_ptr<lang::meta::Node::LexerInstr::PopExtract::_T>;
}

namespace lang::meta::Node::LexerInstr::PopEmit {
    struct _T;
}

namespace lang::meta::Node::LexerInstr {
    using PopEmit_T = rc_ptr<lang::meta::Node::LexerInstr::PopEmit::_T>;
}

namespace lang::meta::Node::LexerInstr::MatchHistory {
    struct _T;
}

namespace lang::meta::Node::LexerInstr {
    using MatchHistory_T = rc_ptr<lang::meta::Node::LexerInstr::MatchHistory::_T>;
}

namespace lang::meta::Node::ParserDecl::Main {
    struct _T;
}

namespace lang::meta::Node::ParserDecl {
    using Main_T = rc_ptr<lang::meta::Node::ParserDecl::Main::_T>;
}

namespace lang::meta::Node::ParserDecl::Prop {
    struct _T;
}

namespace lang::meta::Node::ParserDecl {
    using Prop_T = rc_ptr<lang::meta::Node::ParserDecl::Prop::_T>;
}

namespace lang::meta::Node::ParserDecl::Prec {
    struct _T;
}

namespace lang::meta::Node::ParserDecl {
    using Prec_T = rc_ptr<lang::meta::Node::ParserDecl::Prec::_T>;
}

namespace lang::meta::Node::ParserDecl::Attr {
    struct _T;
}

namespace lang::meta::Node::ParserDecl {
    using Attr_T = rc_ptr<lang::meta::Node::ParserDecl::Attr::_T>;
}

namespace lang::meta::Node::ParserDecl::Rule::op::DEF {
    struct _T;
}

namespace lang::meta::Node::ParserDecl::Rule::op {
    using DEF_T = rc_ptr<lang::meta::Node::ParserDecl::Rule::op::DEF::_T>;
}

namespace lang::meta::Node::ParserDecl::Rule::op::DEF_ALIAS {
    struct _T;
}

namespace lang::meta::Node::ParserDecl::Rule::op {
    using DEF_ALIAS_T = rc_ptr<lang::meta::Node::ParserDecl::Rule::op::DEF_ALIAS::_T>;
}

namespace lang::meta::Node::ParserDecl::Rule::op {
    struct _T;
}

namespace lang::meta::Node::ParserDecl::Rule {
    using op_T = rc_ptr<lang::meta::Node::ParserDecl::Rule::op::_T>;
}

namespace lang::meta::Node::ParserDecl::Rule {
    struct _T;
}

namespace lang::meta::Node::ParserDecl {
    using Rule_T = rc_ptr<lang::meta::Node::ParserDecl::Rule::_T>;
}

namespace lang::meta::Node::ParserProp::NameStrict {
    struct _T;
}

namespace lang::meta::Node::ParserProp {
    using NameStrict_T = rc_ptr<lang::meta::Node::ParserProp::NameStrict::_T>;
}

namespace lang::meta::Node::ParserProp::LRSpec {
    struct _T;
}

namespace lang::meta::Node::ParserProp {
    using LRSpec_T = rc_ptr<lang::meta::Node::ParserProp::LRSpec::_T>;
}

namespace lang::meta::Node::ParserProp::Err_ {
    struct _T;
}

namespace lang::meta::Node::ParserProp {
    using Err__T = rc_ptr<lang::meta::Node::ParserProp::Err_::_T>;
}

namespace lang::meta::Node::PrecItem {
    struct _T;
}

namespace lang::meta::Node {
    using PrecItem_T = rc_ptr<lang::meta::Node::PrecItem::_T>;
}

namespace lang::meta::Node::PrecAssoc::Left {
    struct _T;
}

namespace lang::meta::Node::PrecAssoc {
    using Left_T = rc_ptr<lang::meta::Node::PrecAssoc::Left::_T>;
}

namespace lang::meta::Node::PrecAssoc::Right {
    struct _T;
}

namespace lang::meta::Node::PrecAssoc {
    using Right_T = rc_ptr<lang::meta::Node::PrecAssoc::Right::_T>;
}

namespace lang::meta::Node::PrecAssoc::Prefix {
    struct _T;
}

namespace lang::meta::Node::PrecAssoc {
    using Prefix_T = rc_ptr<lang::meta::Node::PrecAssoc::Prefix::_T>;
}

namespace lang::meta::Node::PrecAssoc::Postfix {
    struct _T;
}

namespace lang::meta::Node::PrecAssoc {
    using Postfix_T = rc_ptr<lang::meta::Node::PrecAssoc::Postfix::_T>;
}

namespace lang::meta::Node::AttrClause::Expr {
    struct _T;
}

namespace lang::meta::Node::AttrClause {
    using Expr_T = rc_ptr<lang::meta::Node::AttrClause::Expr::_T>;
}

namespace lang::meta::Node::AttrClause::Block {
    struct _T;
}

namespace lang::meta::Node::AttrClause {
    using Block_T = rc_ptr<lang::meta::Node::AttrClause::Block::_T>;
}

namespace lang::meta::Node::AttrClause::Match {
    struct _T;
}

namespace lang::meta::Node::AttrClause {
    using Match_T = rc_ptr<lang::meta::Node::AttrClause::Match::_T>;
}

namespace lang::meta::Node::AttrMatchCase {
    struct _T;
}

namespace lang::meta::Node {
    using AttrMatchCase_T = rc_ptr<lang::meta::Node::AttrMatchCase::_T>;
}

namespace lang::meta::Node::AttrMatchCasePattern::Alt {
    struct _T;
}

namespace lang::meta::Node::AttrMatchCasePattern {
    using Alt_T = rc_ptr<lang::meta::Node::AttrMatchCasePattern::Alt::_T>;
}

namespace lang::meta::Node::AttrMatchCasePattern::Wildcard {
    struct _T;
}

namespace lang::meta::Node::AttrMatchCasePattern {
    using Wildcard_T = rc_ptr<lang::meta::Node::AttrMatchCasePattern::Wildcard::_T>;
}

namespace lang::meta::Node::AttrClauseExpr::LhsGeq {
    struct _T;
}

namespace lang::meta::Node::AttrClauseExpr {
    using LhsGeq_T = rc_ptr<lang::meta::Node::AttrClauseExpr::LhsGeq::_T>;
}

namespace lang::meta::Node::AttrClauseExpr::RhsGeq {
    struct _T;
}

namespace lang::meta::Node::AttrClauseExpr {
    using RhsGeq_T = rc_ptr<lang::meta::Node::AttrClauseExpr::RhsGeq::_T>;
}

namespace lang::meta::Node::AttrClauseExpr::Implies {
    struct _T;
}

namespace lang::meta::Node::AttrClauseExpr {
    using Implies_T = rc_ptr<lang::meta::Node::AttrClauseExpr::Implies::_T>;
}

namespace lang::meta::Node::AttrClauseExprRhsLoc::All {
    struct _T;
}

namespace lang::meta::Node::AttrClauseExprRhsLoc {
    using All_T = rc_ptr<lang::meta::Node::AttrClauseExprRhsLoc::All::_T>;
}

namespace lang::meta::Node::AttrClauseExprRhsLoc::Begin {
    struct _T;
}

namespace lang::meta::Node::AttrClauseExprRhsLoc {
    using Begin_T = rc_ptr<lang::meta::Node::AttrClauseExprRhsLoc::Begin::_T>;
}

namespace lang::meta::Node::AttrClauseExprRhsLoc::Mid {
    struct _T;
}

namespace lang::meta::Node::AttrClauseExprRhsLoc {
    using Mid_T = rc_ptr<lang::meta::Node::AttrClauseExprRhsLoc::Mid::_T>;
}

namespace lang::meta::Node::AttrClauseExprRhsLoc::End {
    struct _T;
}

namespace lang::meta::Node::AttrClauseExprRhsLoc {
    using End_T = rc_ptr<lang::meta::Node::AttrClauseExprRhsLoc::End::_T>;
}

namespace lang::meta::Node::TestCase {
    struct _T;
}

namespace lang::meta::Node {
    using TestCase_T = rc_ptr<lang::meta::Node::TestCase::_T>;
}

namespace lang::meta::Node::CompileTestCase {
    struct _T;
}

namespace lang::meta::Node {
    using CompileTestCase_T = rc_ptr<lang::meta::Node::CompileTestCase::_T>;
}

namespace lang::meta::Node::ParseExpr::Id {
    struct _T;
}

namespace lang::meta::Node::ParseExpr {
    using Id_T = rc_ptr<lang::meta::Node::ParseExpr::Id::_T>;
}

namespace lang::meta::Node::ParseExpr::Eof {
    struct _T;
}

namespace lang::meta::Node::ParseExpr {
    using Eof_T = rc_ptr<lang::meta::Node::ParseExpr::Eof::_T>;
}

namespace lang::meta::Node::ParseExpr::False {
    struct _T;
}

namespace lang::meta::Node::ParseExpr {
    using False_T = rc_ptr<lang::meta::Node::ParseExpr::False::_T>;
}

namespace lang::meta::Node::ParseExpr::Eps {
    struct _T;
}

namespace lang::meta::Node::ParseExpr {
    using Eps_T = rc_ptr<lang::meta::Node::ParseExpr::Eps::_T>;
}

namespace lang::meta::Node::ParseExpr::Indent {
    struct _T;
}

namespace lang::meta::Node::ParseExpr {
    using Indent_T = rc_ptr<lang::meta::Node::ParseExpr::Indent::_T>;
}

namespace lang::meta::Node::ParseExpr::Dedent {
    struct _T;
}

namespace lang::meta::Node::ParseExpr {
    using Dedent_T = rc_ptr<lang::meta::Node::ParseExpr::Dedent::_T>;
}

namespace lang::meta::Node::ParseExpr::Newline {
    struct _T;
}

namespace lang::meta::Node::ParseExpr {
    using Newline_T = rc_ptr<lang::meta::Node::ParseExpr::Newline::_T>;
}

namespace lang::meta::Node::ParseExpr::UnicodeAny {
    struct _T;
}

namespace lang::meta::Node::ParseExpr {
    using UnicodeAny_T = rc_ptr<lang::meta::Node::ParseExpr::UnicodeAny::_T>;
}

namespace lang::meta::Node::ParseExpr::AsciiBaseAny {
    struct _T;
}

namespace lang::meta::Node::ParseExpr {
    using AsciiBaseAny_T = rc_ptr<lang::meta::Node::ParseExpr::AsciiBaseAny::_T>;
}

namespace lang::meta::Node::ParseExpr::Alt {
    struct _T;
}

namespace lang::meta::Node::ParseExpr {
    using Alt_T = rc_ptr<lang::meta::Node::ParseExpr::Alt::_T>;
}

namespace lang::meta::Node::ParseExpr::AltExplicit {
    struct _T;
}

namespace lang::meta::Node::ParseExpr {
    using AltExplicit_T = rc_ptr<lang::meta::Node::ParseExpr::AltExplicit::_T>;
}

namespace lang::meta::Node::ParseExpr::Minus {
    struct _T;
}

namespace lang::meta::Node::ParseExpr {
    using Minus_T = rc_ptr<lang::meta::Node::ParseExpr::Minus::_T>;
}

namespace lang::meta::Node::ParseExpr::Concat {
    struct _T;
}

namespace lang::meta::Node::ParseExpr {
    using Concat_T = rc_ptr<lang::meta::Node::ParseExpr::Concat::_T>;
}

namespace lang::meta::Node::ParseExpr::Optional {
    struct _T;
}

namespace lang::meta::Node::ParseExpr {
    using Optional_T = rc_ptr<lang::meta::Node::ParseExpr::Optional::_T>;
}

namespace lang::meta::Node::ParseExpr::Rep {
    struct _T;
}

namespace lang::meta::Node::ParseExpr {
    using Rep_T = rc_ptr<lang::meta::Node::ParseExpr::Rep::_T>;
}

namespace lang::meta::Node::ParseExpr::RepNonzero {
    struct _T;
}

namespace lang::meta::Node::ParseExpr {
    using RepNonzero_T = rc_ptr<lang::meta::Node::ParseExpr::RepNonzero::_T>;
}

namespace lang::meta::Node::ParseExpr::RepCount {
    struct _T;
}

namespace lang::meta::Node::ParseExpr {
    using RepCount_T = rc_ptr<lang::meta::Node::ParseExpr::RepCount::_T>;
}

namespace lang::meta::Node::ParseExpr::CharRange {
    struct _T;
}

namespace lang::meta::Node::ParseExpr {
    using CharRange_T = rc_ptr<lang::meta::Node::ParseExpr::CharRange::_T>;
}

namespace lang::meta::Node::ParseExpr::StrLit {
    struct _T;
}

namespace lang::meta::Node::ParseExpr {
    using StrLit_T = rc_ptr<lang::meta::Node::ParseExpr::StrLit::_T>;
}

namespace lang::meta::Node::ParseExpr::Underscore {
    struct _T;
}

namespace lang::meta::Node::ParseExpr {
    using Underscore_T = rc_ptr<lang::meta::Node::ParseExpr::Underscore::_T>;
}

namespace lang::meta::Node::ParseExpr::Pass {
    struct _T;
}

namespace lang::meta::Node::ParseExpr {
    using Pass_T = rc_ptr<lang::meta::Node::ParseExpr::Pass::_T>;
}

namespace lang::meta::Node::ParseExpr::Paren {
    struct _T;
}

namespace lang::meta::Node::ParseExpr {
    using Paren_T = rc_ptr<lang::meta::Node::ParseExpr::Paren::_T>;
}

namespace lang::meta::Node::ParseExpr::Name {
    struct _T;
}

namespace lang::meta::Node::ParseExpr {
    using Name_T = rc_ptr<lang::meta::Node::ParseExpr::Name::_T>;
}

namespace lang::meta::Node::ParseExpr::List::end_delim::NONE {
    struct _T;
}

namespace lang::meta::Node::ParseExpr::List::end_delim {
    using NONE_T = rc_ptr<lang::meta::Node::ParseExpr::List::end_delim::NONE::_T>;
}

namespace lang::meta::Node::ParseExpr::List::end_delim::OPTIONAL {
    struct _T;
}

namespace lang::meta::Node::ParseExpr::List::end_delim {
    using OPTIONAL_T = rc_ptr<lang::meta::Node::ParseExpr::List::end_delim::OPTIONAL::_T>;
}

namespace lang::meta::Node::ParseExpr::List::end_delim::SOME {
    struct _T;
}

namespace lang::meta::Node::ParseExpr::List::end_delim {
    using SOME_T = rc_ptr<lang::meta::Node::ParseExpr::List::end_delim::SOME::_T>;
}

namespace lang::meta::Node::ParseExpr::List::end_delim {
    struct _T;
}

namespace lang::meta::Node::ParseExpr::List {
    using end_delim_T = rc_ptr<lang::meta::Node::ParseExpr::List::end_delim::_T>;
}

namespace lang::meta::Node::ParseExpr::List {
    struct _T;
}

namespace lang::meta::Node::ParseExpr {
    using List_T = rc_ptr<lang::meta::Node::ParseExpr::List::_T>;
}

namespace lang::meta::Node::ParseExpr::Unfold {
    struct _T;
}

namespace lang::meta::Node::ParseExpr {
    using Unfold_T = rc_ptr<lang::meta::Node::ParseExpr::Unfold::_T>;
}

namespace lang::meta::Node::ParseExpr::AttrReq {
    struct _T;
}

namespace lang::meta::Node::ParseExpr {
    using AttrReq_T = rc_ptr<lang::meta::Node::ParseExpr::AttrReq::_T>;
}

namespace lang::meta::Node::AttrReq::Base {
    struct _T;
}

namespace lang::meta::Node::AttrReq {
    using Base_T = rc_ptr<lang::meta::Node::AttrReq::Base::_T>;
}

namespace lang::meta::Node::AttrReq::PrecStar {
    struct _T;
}

namespace lang::meta::Node::AttrReq {
    using PrecStar_T = rc_ptr<lang::meta::Node::AttrReq::PrecStar::_T>;
}

namespace lang::meta::Node::ParseExprListType::List {
    struct _T;
}

namespace lang::meta::Node::ParseExprListType {
    using List_T = rc_ptr<lang::meta::Node::ParseExprListType::List::_T>;
}

namespace lang::meta::Node::ParseExprListType::Block {
    struct _T;
}

namespace lang::meta::Node::ParseExprListType {
    using Block_T = rc_ptr<lang::meta::Node::ParseExprListType::Block::_T>;
}

namespace lang::meta::Node::ParseExprListType::Block2 {
    struct _T;
}

namespace lang::meta::Node::ParseExprListType {
    using Block2_T = rc_ptr<lang::meta::Node::ParseExprListType::Block2::_T>;
}

namespace lang::meta::Node::ParseExprListType::Top {
    struct _T;
}

namespace lang::meta::Node::ParseExprListType {
    using Top_T = rc_ptr<lang::meta::Node::ParseExprListType::Top::_T>;
}

namespace lang::meta::Node::ParseExprListType::Top2 {
    struct _T;
}

namespace lang::meta::Node::ParseExprListType {
    using Top2_T = rc_ptr<lang::meta::Node::ParseExprListType::Top2::_T>;
}

namespace lang::meta::Node::ParseExprListNum::Ge0 {
    struct _T;
}

namespace lang::meta::Node::ParseExprListNum {
    using Ge0_T = rc_ptr<lang::meta::Node::ParseExprListNum::Ge0::_T>;
}

namespace lang::meta::Node::ParseExprListNum::Ge1 {
    struct _T;
}

namespace lang::meta::Node::ParseExprListNum {
    using Ge1_T = rc_ptr<lang::meta::Node::ParseExprListNum::Ge1::_T>;
}

namespace lang::meta::Node::ParseExprListNum::Ge2 {
    struct _T;
}

namespace lang::meta::Node::ParseExprListNum {
    using Ge2_T = rc_ptr<lang::meta::Node::ParseExprListNum::Ge2::_T>;
}

namespace lang::meta::Node::Id {
    struct _T;
}

namespace lang::meta::Node {
    using Id_T = rc_ptr<lang::meta::Node::Id::_T>;
}

namespace lang::meta::Node::Stanza {
    struct _T;
}

namespace lang::meta::Node {
    using Stanza_T = rc_ptr<lang::meta::Node::Stanza::_T>;
}

namespace lang::meta::Node::LexerDecl {
    struct _T;
}

namespace lang::meta::Node {
    using LexerDecl_T = rc_ptr<lang::meta::Node::LexerDecl::_T>;
}

namespace lang::meta::Node::LexerInstr {
    struct _T;
}

namespace lang::meta::Node {
    using LexerInstr_T = rc_ptr<lang::meta::Node::LexerInstr::_T>;
}

namespace lang::meta::Node::ParserDecl {
    struct _T;
}

namespace lang::meta::Node {
    using ParserDecl_T = rc_ptr<lang::meta::Node::ParserDecl::_T>;
}

namespace lang::meta::Node::ParserProp {
    struct _T;
}

namespace lang::meta::Node {
    using ParserProp_T = rc_ptr<lang::meta::Node::ParserProp::_T>;
}

namespace lang::meta::Node::PrecAssoc {
    struct _T;
}

namespace lang::meta::Node {
    using PrecAssoc_T = rc_ptr<lang::meta::Node::PrecAssoc::_T>;
}

namespace lang::meta::Node::AttrClause {
    struct _T;
}

namespace lang::meta::Node {
    using AttrClause_T = rc_ptr<lang::meta::Node::AttrClause::_T>;
}

namespace lang::meta::Node::AttrMatchCasePattern {
    struct _T;
}

namespace lang::meta::Node {
    using AttrMatchCasePattern_T = rc_ptr<lang::meta::Node::AttrMatchCasePattern::_T>;
}

namespace lang::meta::Node::AttrClauseExpr {
    struct _T;
}

namespace lang::meta::Node {
    using AttrClauseExpr_T = rc_ptr<lang::meta::Node::AttrClauseExpr::_T>;
}

namespace lang::meta::Node::AttrClauseExprRhsLoc {
    struct _T;
}

namespace lang::meta::Node {
    using AttrClauseExprRhsLoc_T = rc_ptr<lang::meta::Node::AttrClauseExprRhsLoc::_T>;
}

namespace lang::meta::Node::ParseExpr {
    struct _T;
}

namespace lang::meta::Node {
    using ParseExpr_T = rc_ptr<lang::meta::Node::ParseExpr::_T>;
}

namespace lang::meta::Node::AttrReq {
    struct _T;
}

namespace lang::meta::Node {
    using AttrReq_T = rc_ptr<lang::meta::Node::AttrReq::_T>;
}

namespace lang::meta::Node::ParseExprListType {
    struct _T;
}

namespace lang::meta::Node {
    using ParseExprListType_T = rc_ptr<lang::meta::Node::ParseExprListType::_T>;
}

namespace lang::meta::Node::ParseExprListNum {
    struct _T;
}

namespace lang::meta::Node {
    using ParseExprListNum_T = rc_ptr<lang::meta::Node::ParseExprListNum::_T>;
}

namespace lang::meta::Node {
    struct _T;
}

namespace lang::meta {
    using Node_T = rc_ptr<lang::meta::Node::_T>;
}

void pr_debug(ostream& os, FmtFlags flags, lang::meta::Node_T x);

namespace lang::meta::Node {
    enum struct _W {
        Lang,
        TokenDecl__op,
        TokenDecl,
        LexerModeCase,
        ParserDecl__Rule__op,
        PrecItem,
        AttrMatchCase,
        TestCase,
        CompileTestCase,
        ParseExpr__List__end_delim,
        Id,
        Stanza,
        LexerDecl,
        LexerInstr,
        ParserDecl,
        ParserProp,
        PrecAssoc,
        AttrClause,
        AttrMatchCasePattern,
        AttrClauseExpr,
        AttrClauseExprRhsLoc,
        ParseExpr,
        AttrReq,
        ParseExprListType,
        ParseExprListNum,
    };
}

namespace lang::meta::Node {
    struct _T: hash_obj, enable_rc_from_this_poly {
        void write(ostream& os, FmtFlags flags);
        lang::meta::Node::_W w_;
        virtual ~_T();
        Int id_;
        lang_rt::TokenBounds bounds_;
        bool is_top_;
        lang_rt::ParserSymId sym_;
        lang_rt::ParserAttrMask attr_;
        lang_rt::ParserLookahead first_k_;
        _T(lang::meta::Node::_W w);
        bool is_Lang();
        bool is_TokenDecl__op();
        bool is_TokenDecl();
        bool is_LexerModeCase();
        bool is_ParserDecl__Rule__op();
        bool is_PrecItem();
        bool is_AttrMatchCase();
        bool is_TestCase();
        bool is_CompileTestCase();
        bool is_ParseExpr__List__end_delim();
        bool is_Id();
        bool is_Stanza();
        bool is_LexerDecl();
        bool is_LexerInstr();
        bool is_ParserDecl();
        bool is_ParserProp();
        bool is_PrecAssoc();
        bool is_AttrClause();
        bool is_AttrMatchCasePattern();
        bool is_AttrClauseExpr();
        bool is_AttrClauseExprRhsLoc();
        bool is_ParseExpr();
        bool is_AttrReq();
        bool is_ParseExprListType();
        bool is_ParseExprListNum();
        lang::meta::Node::Lang_T as_Lang();
        lang::meta::Node::TokenDecl::op_T as_TokenDecl__op();
        lang::meta::Node::TokenDecl_T as_TokenDecl();
        lang::meta::Node::LexerModeCase_T as_LexerModeCase();
        lang::meta::Node::ParserDecl::Rule::op_T as_ParserDecl__Rule__op();
        lang::meta::Node::PrecItem_T as_PrecItem();
        lang::meta::Node::AttrMatchCase_T as_AttrMatchCase();
        lang::meta::Node::TestCase_T as_TestCase();
        lang::meta::Node::CompileTestCase_T as_CompileTestCase();
        lang::meta::Node::ParseExpr::List::end_delim_T as_ParseExpr__List__end_delim();
        lang::meta::Node::Id_T as_Id();
        lang::meta::Node::Stanza_T as_Stanza();
        lang::meta::Node::LexerDecl_T as_LexerDecl();
        lang::meta::Node::LexerInstr_T as_LexerInstr();
        lang::meta::Node::ParserDecl_T as_ParserDecl();
        lang::meta::Node::ParserProp_T as_ParserProp();
        lang::meta::Node::PrecAssoc_T as_PrecAssoc();
        lang::meta::Node::AttrClause_T as_AttrClause();
        lang::meta::Node::AttrMatchCasePattern_T as_AttrMatchCasePattern();
        lang::meta::Node::AttrClauseExpr_T as_AttrClauseExpr();
        lang::meta::Node::AttrClauseExprRhsLoc_T as_AttrClauseExprRhsLoc();
        lang::meta::Node::ParseExpr_T as_ParseExpr();
        lang::meta::Node::AttrReq_T as_AttrReq();
        lang::meta::Node::ParseExprListType_T as_ParseExprListType();
        lang::meta::Node::ParseExprListNum_T as_ParseExprListNum();
        void hash_ser_acc_lang_meta_Node(SerBuf& buf) const;
        virtual void hash_ser_acc(SerBuf& buf) const = 0;
    };
}

void pr_debug(ostream& os, FmtFlags flags, lang::meta::Node::Lang_T x);

namespace lang::meta::Node::Lang {
    __attribute__((always_inline)) lang::meta::Node::Lang_T make(Int id, lang_rt::TokenBounds bounds, bool is_top, lang_rt::ParserSymId sym, lang_rt::ParserAttrMask attr, lang_rt::ParserLookahead first_k, Vec_T<lang::meta::Node::Stanza_T> stanzas);
}

namespace lang::meta::Node::Lang {
    __attribute__((always_inline)) lang::meta::Node::Lang_T make_ext(ArenaPtr arena, Int id, lang_rt::TokenBounds bounds, bool is_top, lang_rt::ParserSymId sym, lang_rt::ParserAttrMask attr, lang_rt::ParserLookahead first_k, Vec_T<lang::meta::Node::Stanza_T> stanzas);
}

namespace lang::meta::Node::Lang {
    struct _T: lang::meta::Node::_T {
        void write(ostream& os, FmtFlags flags);
        Vec_T<lang::meta::Node::Stanza_T> stanzas_;
        _T();
        lang::meta::Node::Lang_T with_id(Int id);
        lang::meta::Node::Lang_T with_bounds(lang_rt::TokenBounds bounds);
        lang::meta::Node::Lang_T with_is_top(bool is_top);
        lang::meta::Node::Lang_T with_sym(lang_rt::ParserSymId sym);
        lang::meta::Node::Lang_T with_attr(lang_rt::ParserAttrMask attr);
        lang::meta::Node::Lang_T with_first_k(lang_rt::ParserLookahead first_k);
        lang::meta::Node::Lang_T with_stanzas(Vec_T<lang::meta::Node::Stanza_T> stanzas);
        void hash_ser_acc_lang_meta_Node_Lang(SerBuf& buf) const;
        virtual void hash_ser_acc(SerBuf& buf) const;
    };
}

void pr_debug(ostream& os, FmtFlags flags, lang::meta::Node::TokenDecl_T x);

namespace lang::meta::Node::TokenDecl {
    __attribute__((always_inline)) lang::meta::Node::TokenDecl_T make(Int id, lang_rt::TokenBounds bounds, bool is_top, lang_rt::ParserSymId sym, lang_rt::ParserAttrMask attr, lang_rt::ParserLookahead first_k, StrSlice name, lang::meta::Node::TokenDecl::op_T op, lang::meta::Node::ParseExpr_T def_);
}

namespace lang::meta::Node::TokenDecl {
    __attribute__((always_inline)) lang::meta::Node::TokenDecl_T make_ext(ArenaPtr arena, Int id, lang_rt::TokenBounds bounds, bool is_top, lang_rt::ParserSymId sym, lang_rt::ParserAttrMask attr, lang_rt::ParserLookahead first_k, StrSlice name, lang::meta::Node::TokenDecl::op_T op, lang::meta::Node::ParseExpr_T def_);
}

namespace lang::meta::Node::TokenDecl {
    struct _T: lang::meta::Node::_T {
        void write(ostream& os, FmtFlags flags);
        StrSlice name_;
        lang::meta::Node::TokenDecl::op_T op_;
        lang::meta::Node::ParseExpr_T def__;
        _T();
        lang::meta::Node::TokenDecl_T with_id(Int id);
        lang::meta::Node::TokenDecl_T with_bounds(lang_rt::TokenBounds bounds);
        lang::meta::Node::TokenDecl_T with_is_top(bool is_top);
        lang::meta::Node::TokenDecl_T with_sym(lang_rt::ParserSymId sym);
        lang::meta::Node::TokenDecl_T with_attr(lang_rt::ParserAttrMask attr);
        lang::meta::Node::TokenDecl_T with_first_k(lang_rt::ParserLookahead first_k);
        lang::meta::Node::TokenDecl_T with_name(StrSlice name);
        lang::meta::Node::TokenDecl_T with_op(lang::meta::Node::TokenDecl::op_T op);
        lang::meta::Node::TokenDecl_T with_def_(lang::meta::Node::ParseExpr_T def_);
        void hash_ser_acc_lang_meta_Node_TokenDecl(SerBuf& buf) const;
        virtual void hash_ser_acc(SerBuf& buf) const;
    };
}

void pr_debug(ostream& os, FmtFlags flags, lang::meta::Node::LexerModeCase_T x);

namespace lang::meta::Node::LexerModeCase {
    __attribute__((always_inline)) lang::meta::Node::LexerModeCase_T make(Int id, lang_rt::TokenBounds bounds, bool is_top, lang_rt::ParserSymId sym, lang_rt::ParserAttrMask attr, lang_rt::ParserLookahead first_k, lang::meta::Node::ParseExpr_T tok, Vec_T<lang::meta::Node::LexerInstr_T> instrs);
}

namespace lang::meta::Node::LexerModeCase {
    __attribute__((always_inline)) lang::meta::Node::LexerModeCase_T make_ext(ArenaPtr arena, Int id, lang_rt::TokenBounds bounds, bool is_top, lang_rt::ParserSymId sym, lang_rt::ParserAttrMask attr, lang_rt::ParserLookahead first_k, lang::meta::Node::ParseExpr_T tok, Vec_T<lang::meta::Node::LexerInstr_T> instrs);
}

namespace lang::meta::Node::LexerModeCase {
    struct _T: lang::meta::Node::_T {
        void write(ostream& os, FmtFlags flags);
        lang::meta::Node::ParseExpr_T tok_;
        Vec_T<lang::meta::Node::LexerInstr_T> instrs_;
        _T();
        lang::meta::Node::LexerModeCase_T with_id(Int id);
        lang::meta::Node::LexerModeCase_T with_bounds(lang_rt::TokenBounds bounds);
        lang::meta::Node::LexerModeCase_T with_is_top(bool is_top);
        lang::meta::Node::LexerModeCase_T with_sym(lang_rt::ParserSymId sym);
        lang::meta::Node::LexerModeCase_T with_attr(lang_rt::ParserAttrMask attr);
        lang::meta::Node::LexerModeCase_T with_first_k(lang_rt::ParserLookahead first_k);
        lang::meta::Node::LexerModeCase_T with_tok(lang::meta::Node::ParseExpr_T tok);
        lang::meta::Node::LexerModeCase_T with_instrs(Vec_T<lang::meta::Node::LexerInstr_T> instrs);
        void hash_ser_acc_lang_meta_Node_LexerModeCase(SerBuf& buf) const;
        virtual void hash_ser_acc(SerBuf& buf) const;
    };
}

void pr_debug(ostream& os, FmtFlags flags, lang::meta::Node::PrecItem_T x);

namespace lang::meta::Node::PrecItem {
    __attribute__((always_inline)) lang::meta::Node::PrecItem_T make(Int id, lang_rt::TokenBounds bounds, bool is_top, lang_rt::ParserSymId sym, lang_rt::ParserAttrMask attr, lang_rt::ParserLookahead first_k, Vec_T<lang::meta::Node::Id_T> ids, Option_T<lang::meta::Node::PrecAssoc_T> assoc);
}

namespace lang::meta::Node::PrecItem {
    __attribute__((always_inline)) lang::meta::Node::PrecItem_T make_ext(ArenaPtr arena, Int id, lang_rt::TokenBounds bounds, bool is_top, lang_rt::ParserSymId sym, lang_rt::ParserAttrMask attr, lang_rt::ParserLookahead first_k, Vec_T<lang::meta::Node::Id_T> ids, Option_T<lang::meta::Node::PrecAssoc_T> assoc);
}

namespace lang::meta::Node::PrecItem {
    struct _T: lang::meta::Node::_T {
        void write(ostream& os, FmtFlags flags);
        Vec_T<lang::meta::Node::Id_T> ids_;
        Option_T<lang::meta::Node::PrecAssoc_T> assoc_;
        _T();
        lang::meta::Node::PrecItem_T with_id(Int id);
        lang::meta::Node::PrecItem_T with_bounds(lang_rt::TokenBounds bounds);
        lang::meta::Node::PrecItem_T with_is_top(bool is_top);
        lang::meta::Node::PrecItem_T with_sym(lang_rt::ParserSymId sym);
        lang::meta::Node::PrecItem_T with_attr(lang_rt::ParserAttrMask attr);
        lang::meta::Node::PrecItem_T with_first_k(lang_rt::ParserLookahead first_k);
        lang::meta::Node::PrecItem_T with_ids(Vec_T<lang::meta::Node::Id_T> ids);
        lang::meta::Node::PrecItem_T with_assoc(Option_T<lang::meta::Node::PrecAssoc_T> assoc);
        void hash_ser_acc_lang_meta_Node_PrecItem(SerBuf& buf) const;
        virtual void hash_ser_acc(SerBuf& buf) const;
    };
}

void pr_debug(ostream& os, FmtFlags flags, lang::meta::Node::AttrMatchCase_T x);

namespace lang::meta::Node::AttrMatchCase {
    __attribute__((always_inline)) lang::meta::Node::AttrMatchCase_T make(Int id, lang_rt::TokenBounds bounds, bool is_top, lang_rt::ParserSymId sym, lang_rt::ParserAttrMask attr, lang_rt::ParserLookahead first_k, lang::meta::Node::AttrMatchCasePattern_T pat, lang::meta::Node::AttrClause_T clause);
}

namespace lang::meta::Node::AttrMatchCase {
    __attribute__((always_inline)) lang::meta::Node::AttrMatchCase_T make_ext(ArenaPtr arena, Int id, lang_rt::TokenBounds bounds, bool is_top, lang_rt::ParserSymId sym, lang_rt::ParserAttrMask attr, lang_rt::ParserLookahead first_k, lang::meta::Node::AttrMatchCasePattern_T pat, lang::meta::Node::AttrClause_T clause);
}

namespace lang::meta::Node::AttrMatchCase {
    struct _T: lang::meta::Node::_T {
        void write(ostream& os, FmtFlags flags);
        lang::meta::Node::AttrMatchCasePattern_T pat_;
        lang::meta::Node::AttrClause_T clause_;
        _T();
        lang::meta::Node::AttrMatchCase_T with_id(Int id);
        lang::meta::Node::AttrMatchCase_T with_bounds(lang_rt::TokenBounds bounds);
        lang::meta::Node::AttrMatchCase_T with_is_top(bool is_top);
        lang::meta::Node::AttrMatchCase_T with_sym(lang_rt::ParserSymId sym);
        lang::meta::Node::AttrMatchCase_T with_attr(lang_rt::ParserAttrMask attr);
        lang::meta::Node::AttrMatchCase_T with_first_k(lang_rt::ParserLookahead first_k);
        lang::meta::Node::AttrMatchCase_T with_pat(lang::meta::Node::AttrMatchCasePattern_T pat);
        lang::meta::Node::AttrMatchCase_T with_clause(lang::meta::Node::AttrClause_T clause);
        void hash_ser_acc_lang_meta_Node_AttrMatchCase(SerBuf& buf) const;
        virtual void hash_ser_acc(SerBuf& buf) const;
    };
}

void pr_debug(ostream& os, FmtFlags flags, lang::meta::Node::TestCase_T x);

namespace lang::meta::Node::TestCase {
    __attribute__((always_inline)) lang::meta::Node::TestCase_T make(Int id, lang_rt::TokenBounds bounds, bool is_top, lang_rt::ParserSymId sym, lang_rt::ParserAttrMask attr, lang_rt::ParserLookahead first_k, StrSlice text, Option_T<StrSlice> sym_, bool print_exempt);
}

namespace lang::meta::Node::TestCase {
    __attribute__((always_inline)) lang::meta::Node::TestCase_T make_ext(ArenaPtr arena, Int id, lang_rt::TokenBounds bounds, bool is_top, lang_rt::ParserSymId sym, lang_rt::ParserAttrMask attr, lang_rt::ParserLookahead first_k, StrSlice text, Option_T<StrSlice> sym_, bool print_exempt);
}

namespace lang::meta::Node::TestCase {
    struct _T: lang::meta::Node::_T {
        void write(ostream& os, FmtFlags flags);
        StrSlice text_;
        Option_T<StrSlice> sym__;
        bool print_exempt_;
        _T();
        lang::meta::Node::TestCase_T with_id(Int id);
        lang::meta::Node::TestCase_T with_bounds(lang_rt::TokenBounds bounds);
        lang::meta::Node::TestCase_T with_is_top(bool is_top);
        lang::meta::Node::TestCase_T with_sym(lang_rt::ParserSymId sym);
        lang::meta::Node::TestCase_T with_attr(lang_rt::ParserAttrMask attr);
        lang::meta::Node::TestCase_T with_first_k(lang_rt::ParserLookahead first_k);
        lang::meta::Node::TestCase_T with_text(StrSlice text);
        lang::meta::Node::TestCase_T with_sym_(Option_T<StrSlice> sym_);
        lang::meta::Node::TestCase_T with_print_exempt(bool print_exempt);
        void hash_ser_acc_lang_meta_Node_TestCase(SerBuf& buf) const;
        virtual void hash_ser_acc(SerBuf& buf) const;
    };
}

void pr_debug(ostream& os, FmtFlags flags, lang::meta::Node::CompileTestCase_T x);

namespace lang::meta::Node::CompileTestCase {
    __attribute__((always_inline)) lang::meta::Node::CompileTestCase_T make(Int id, lang_rt::TokenBounds bounds, bool is_top, lang_rt::ParserSymId sym, lang_rt::ParserAttrMask attr, lang_rt::ParserLookahead first_k, bool neg, StrSlice k);
}

namespace lang::meta::Node::CompileTestCase {
    __attribute__((always_inline)) lang::meta::Node::CompileTestCase_T make_ext(ArenaPtr arena, Int id, lang_rt::TokenBounds bounds, bool is_top, lang_rt::ParserSymId sym, lang_rt::ParserAttrMask attr, lang_rt::ParserLookahead first_k, bool neg, StrSlice k);
}

namespace lang::meta::Node::CompileTestCase {
    struct _T: lang::meta::Node::_T {
        void write(ostream& os, FmtFlags flags);
        bool neg_;
        StrSlice k_;
        _T();
        lang::meta::Node::CompileTestCase_T with_id(Int id);
        lang::meta::Node::CompileTestCase_T with_bounds(lang_rt::TokenBounds bounds);
        lang::meta::Node::CompileTestCase_T with_is_top(bool is_top);
        lang::meta::Node::CompileTestCase_T with_sym(lang_rt::ParserSymId sym);
        lang::meta::Node::CompileTestCase_T with_attr(lang_rt::ParserAttrMask attr);
        lang::meta::Node::CompileTestCase_T with_first_k(lang_rt::ParserLookahead first_k);
        lang::meta::Node::CompileTestCase_T with_neg(bool neg);
        lang::meta::Node::CompileTestCase_T with_k(StrSlice k);
        void hash_ser_acc_lang_meta_Node_CompileTestCase(SerBuf& buf) const;
        virtual void hash_ser_acc(SerBuf& buf) const;
    };
}

void pr_debug(ostream& os, FmtFlags flags, lang::meta::Node::Id_T x);

namespace lang::meta::Node::Id {
    __attribute__((always_inline)) lang::meta::Node::Id_T make(Int id, lang_rt::TokenBounds bounds, bool is_top, lang_rt::ParserSymId sym, lang_rt::ParserAttrMask attr, lang_rt::ParserLookahead first_k, Vec_T<StrSlice> names);
}

namespace lang::meta::Node::Id {
    __attribute__((always_inline)) lang::meta::Node::Id_T make_ext(ArenaPtr arena, Int id, lang_rt::TokenBounds bounds, bool is_top, lang_rt::ParserSymId sym, lang_rt::ParserAttrMask attr, lang_rt::ParserLookahead first_k, Vec_T<StrSlice> names);
}

namespace lang::meta::Node::Id {
    struct _T: lang::meta::Node::_T {
        void write(ostream& os, FmtFlags flags);
        Vec_T<StrSlice> names_;
        _T();
        lang::meta::Node::Id_T with_id(Int id);
        lang::meta::Node::Id_T with_bounds(lang_rt::TokenBounds bounds);
        lang::meta::Node::Id_T with_is_top(bool is_top);
        lang::meta::Node::Id_T with_sym(lang_rt::ParserSymId sym);
        lang::meta::Node::Id_T with_attr(lang_rt::ParserAttrMask attr);
        lang::meta::Node::Id_T with_first_k(lang_rt::ParserLookahead first_k);
        lang::meta::Node::Id_T with_names(Vec_T<StrSlice> names);
        void hash_ser_acc_lang_meta_Node_Id(SerBuf& buf) const;
        virtual void hash_ser_acc(SerBuf& buf) const;
    };
}

void pr_debug(ostream& os, FmtFlags flags, lang::meta::Node::Stanza_T x);

namespace lang::meta::Node::Stanza {
    enum struct _W {
        Tokens,
        Lexer,
        Parser,
        Test,
        CompileTest,
    };
}

namespace lang::meta::Node::Stanza {
    struct _T: lang::meta::Node::_T {
        void write(ostream& os, FmtFlags flags);
        lang::meta::Node::Stanza::_W w_;
        virtual ~_T();
        _T(lang::meta::Node::Stanza::_W w);
        bool is_Tokens();
        bool is_Lexer();
        bool is_Parser();
        bool is_Test();
        bool is_CompileTest();
        lang::meta::Node::Stanza::Tokens_T as_Tokens();
        lang::meta::Node::Stanza::Lexer_T as_Lexer();
        lang::meta::Node::Stanza::Parser_T as_Parser();
        lang::meta::Node::Stanza::Test_T as_Test();
        lang::meta::Node::Stanza::CompileTest_T as_CompileTest();
        void hash_ser_acc_lang_meta_Node_Stanza(SerBuf& buf) const;
        virtual void hash_ser_acc(SerBuf& buf) const = 0;
    };
}

void pr_debug(ostream& os, FmtFlags flags, lang::meta::Node::LexerDecl_T x);

namespace lang::meta::Node::LexerDecl {
    enum struct _W {
        Main,
        Mode,
    };
}

namespace lang::meta::Node::LexerDecl {
    struct _T: lang::meta::Node::_T {
        void write(ostream& os, FmtFlags flags);
        lang::meta::Node::LexerDecl::_W w_;
        virtual ~_T();
        _T(lang::meta::Node::LexerDecl::_W w);
        bool is_Main();
        bool is_Mode();
        lang::meta::Node::LexerDecl::Main_T as_Main();
        lang::meta::Node::LexerDecl::Mode_T as_Mode();
        void hash_ser_acc_lang_meta_Node_LexerDecl(SerBuf& buf) const;
        virtual void hash_ser_acc(SerBuf& buf) const = 0;
    };
}

void pr_debug(ostream& os, FmtFlags flags, lang::meta::Node::LexerInstr_T x);

namespace lang::meta::Node::LexerInstr {
    enum struct _W {
        Emit,
        Pass,
        Push,
        Pop,
        PopExtract,
        PopEmit,
        MatchHistory,
    };
}

namespace lang::meta::Node::LexerInstr {
    struct _T: lang::meta::Node::_T {
        void write(ostream& os, FmtFlags flags);
        lang::meta::Node::LexerInstr::_W w_;
        virtual ~_T();
        _T(lang::meta::Node::LexerInstr::_W w);
        bool is_Emit();
        bool is_Pass();
        bool is_Push();
        bool is_Pop();
        bool is_PopExtract();
        bool is_PopEmit();
        bool is_MatchHistory();
        lang::meta::Node::LexerInstr::Emit_T as_Emit();
        lang::meta::Node::LexerInstr::Pass_T as_Pass();
        lang::meta::Node::LexerInstr::Push_T as_Push();
        lang::meta::Node::LexerInstr::Pop_T as_Pop();
        lang::meta::Node::LexerInstr::PopExtract_T as_PopExtract();
        lang::meta::Node::LexerInstr::PopEmit_T as_PopEmit();
        lang::meta::Node::LexerInstr::MatchHistory_T as_MatchHistory();
        void hash_ser_acc_lang_meta_Node_LexerInstr(SerBuf& buf) const;
        virtual void hash_ser_acc(SerBuf& buf) const = 0;
    };
}

void pr_debug(ostream& os, FmtFlags flags, lang::meta::Node::ParserDecl_T x);

namespace lang::meta::Node::ParserDecl {
    enum struct _W {
        Main,
        Prop,
        Prec,
        Attr,
        Rule,
    };
}

namespace lang::meta::Node::ParserDecl {
    struct _T: lang::meta::Node::_T {
        void write(ostream& os, FmtFlags flags);
        lang::meta::Node::ParserDecl::_W w_;
        virtual ~_T();
        _T(lang::meta::Node::ParserDecl::_W w);
        bool is_Main();
        bool is_Prop();
        bool is_Prec();
        bool is_Attr();
        bool is_Rule();
        lang::meta::Node::ParserDecl::Main_T as_Main();
        lang::meta::Node::ParserDecl::Prop_T as_Prop();
        lang::meta::Node::ParserDecl::Prec_T as_Prec();
        lang::meta::Node::ParserDecl::Attr_T as_Attr();
        lang::meta::Node::ParserDecl::Rule_T as_Rule();
        void hash_ser_acc_lang_meta_Node_ParserDecl(SerBuf& buf) const;
        virtual void hash_ser_acc(SerBuf& buf) const = 0;
    };
}

void pr_debug(ostream& os, FmtFlags flags, lang::meta::Node::ParserProp_T x);

namespace lang::meta::Node::ParserProp {
    enum struct _W {
        NameStrict,
        LRSpec,
        Err_,
    };
}

namespace lang::meta::Node::ParserProp {
    struct _T: lang::meta::Node::_T {
        void write(ostream& os, FmtFlags flags);
        lang::meta::Node::ParserProp::_W w_;
        virtual ~_T();
        _T(lang::meta::Node::ParserProp::_W w);
        bool is_NameStrict();
        bool is_LRSpec();
        bool is_Err_();
        lang::meta::Node::ParserProp::NameStrict_T as_NameStrict();
        lang::meta::Node::ParserProp::LRSpec_T as_LRSpec();
        lang::meta::Node::ParserProp::Err__T as_Err_();
        void hash_ser_acc_lang_meta_Node_ParserProp(SerBuf& buf) const;
        virtual void hash_ser_acc(SerBuf& buf) const = 0;
    };
}

void pr_debug(ostream& os, FmtFlags flags, lang::meta::Node::PrecAssoc_T x);

namespace lang::meta::Node::PrecAssoc {
    enum struct _W {
        Left,
        Right,
        Prefix,
        Postfix,
    };
}

namespace lang::meta::Node::PrecAssoc {
    struct _T: lang::meta::Node::_T {
        void write(ostream& os, FmtFlags flags);
        lang::meta::Node::PrecAssoc::_W w_;
        virtual ~_T();
        _T(lang::meta::Node::PrecAssoc::_W w);
        bool is_Left();
        bool is_Right();
        bool is_Prefix();
        bool is_Postfix();
        lang::meta::Node::PrecAssoc::Left_T as_Left();
        lang::meta::Node::PrecAssoc::Right_T as_Right();
        lang::meta::Node::PrecAssoc::Prefix_T as_Prefix();
        lang::meta::Node::PrecAssoc::Postfix_T as_Postfix();
        void hash_ser_acc_lang_meta_Node_PrecAssoc(SerBuf& buf) const;
        virtual void hash_ser_acc(SerBuf& buf) const = 0;
    };
}

void pr_debug(ostream& os, FmtFlags flags, lang::meta::Node::AttrClause_T x);

namespace lang::meta::Node::AttrClause {
    enum struct _W {
        Expr,
        Block,
        Match,
    };
}

namespace lang::meta::Node::AttrClause {
    struct _T: lang::meta::Node::_T {
        void write(ostream& os, FmtFlags flags);
        lang::meta::Node::AttrClause::_W w_;
        virtual ~_T();
        _T(lang::meta::Node::AttrClause::_W w);
        bool is_Expr();
        bool is_Block();
        bool is_Match();
        lang::meta::Node::AttrClause::Expr_T as_Expr();
        lang::meta::Node::AttrClause::Block_T as_Block();
        lang::meta::Node::AttrClause::Match_T as_Match();
        void hash_ser_acc_lang_meta_Node_AttrClause(SerBuf& buf) const;
        virtual void hash_ser_acc(SerBuf& buf) const = 0;
    };
}

void pr_debug(ostream& os, FmtFlags flags, lang::meta::Node::AttrMatchCasePattern_T x);

namespace lang::meta::Node::AttrMatchCasePattern {
    enum struct _W {
        Alt,
        Wildcard,
    };
}

namespace lang::meta::Node::AttrMatchCasePattern {
    struct _T: lang::meta::Node::_T {
        void write(ostream& os, FmtFlags flags);
        lang::meta::Node::AttrMatchCasePattern::_W w_;
        virtual ~_T();
        _T(lang::meta::Node::AttrMatchCasePattern::_W w);
        bool is_Alt();
        bool is_Wildcard();
        lang::meta::Node::AttrMatchCasePattern::Alt_T as_Alt();
        lang::meta::Node::AttrMatchCasePattern::Wildcard_T as_Wildcard();
        void hash_ser_acc_lang_meta_Node_AttrMatchCasePattern(SerBuf& buf) const;
        virtual void hash_ser_acc(SerBuf& buf) const = 0;
    };
}

void pr_debug(ostream& os, FmtFlags flags, lang::meta::Node::AttrClauseExpr_T x);

namespace lang::meta::Node::AttrClauseExpr {
    enum struct _W {
        LhsGeq,
        RhsGeq,
        Implies,
    };
}

namespace lang::meta::Node::AttrClauseExpr {
    struct _T: lang::meta::Node::_T {
        void write(ostream& os, FmtFlags flags);
        lang::meta::Node::AttrClauseExpr::_W w_;
        virtual ~_T();
        _T(lang::meta::Node::AttrClauseExpr::_W w);
        bool is_LhsGeq();
        bool is_RhsGeq();
        bool is_Implies();
        lang::meta::Node::AttrClauseExpr::LhsGeq_T as_LhsGeq();
        lang::meta::Node::AttrClauseExpr::RhsGeq_T as_RhsGeq();
        lang::meta::Node::AttrClauseExpr::Implies_T as_Implies();
        void hash_ser_acc_lang_meta_Node_AttrClauseExpr(SerBuf& buf) const;
        virtual void hash_ser_acc(SerBuf& buf) const = 0;
    };
}

void pr_debug(ostream& os, FmtFlags flags, lang::meta::Node::AttrClauseExprRhsLoc_T x);

namespace lang::meta::Node::AttrClauseExprRhsLoc {
    enum struct _W {
        All,
        Begin,
        Mid,
        End,
    };
}

namespace lang::meta::Node::AttrClauseExprRhsLoc {
    struct _T: lang::meta::Node::_T {
        void write(ostream& os, FmtFlags flags);
        lang::meta::Node::AttrClauseExprRhsLoc::_W w_;
        virtual ~_T();
        _T(lang::meta::Node::AttrClauseExprRhsLoc::_W w);
        bool is_All();
        bool is_Begin();
        bool is_Mid();
        bool is_End();
        lang::meta::Node::AttrClauseExprRhsLoc::All_T as_All();
        lang::meta::Node::AttrClauseExprRhsLoc::Begin_T as_Begin();
        lang::meta::Node::AttrClauseExprRhsLoc::Mid_T as_Mid();
        lang::meta::Node::AttrClauseExprRhsLoc::End_T as_End();
        void hash_ser_acc_lang_meta_Node_AttrClauseExprRhsLoc(SerBuf& buf) const;
        virtual void hash_ser_acc(SerBuf& buf) const = 0;
    };
}

void pr_debug(ostream& os, FmtFlags flags, lang::meta::Node::ParseExpr_T x);

namespace lang::meta::Node::ParseExpr {
    enum struct _W {
        Id,
        Eof,
        False,
        Eps,
        Indent,
        Dedent,
        Newline,
        UnicodeAny,
        AsciiBaseAny,
        Alt,
        AltExplicit,
        Minus,
        Concat,
        Optional,
        Rep,
        RepNonzero,
        RepCount,
        CharRange,
        StrLit,
        Underscore,
        Pass,
        Paren,
        Name,
        List,
        Unfold,
        AttrReq,
    };
}

namespace lang::meta::Node::ParseExpr {
    struct _T: lang::meta::Node::_T {
        void write(ostream& os, FmtFlags flags);
        lang::meta::Node::ParseExpr::_W w_;
        virtual ~_T();
        _T(lang::meta::Node::ParseExpr::_W w);
        bool is_Id();
        bool is_Eof();
        bool is_False();
        bool is_Eps();
        bool is_Indent();
        bool is_Dedent();
        bool is_Newline();
        bool is_UnicodeAny();
        bool is_AsciiBaseAny();
        bool is_Alt();
        bool is_AltExplicit();
        bool is_Minus();
        bool is_Concat();
        bool is_Optional();
        bool is_Rep();
        bool is_RepNonzero();
        bool is_RepCount();
        bool is_CharRange();
        bool is_StrLit();
        bool is_Underscore();
        bool is_Pass();
        bool is_Paren();
        bool is_Name();
        bool is_List();
        bool is_Unfold();
        bool is_AttrReq();
        lang::meta::Node::ParseExpr::Id_T as_Id();
        lang::meta::Node::ParseExpr::Eof_T as_Eof();
        lang::meta::Node::ParseExpr::False_T as_False();
        lang::meta::Node::ParseExpr::Eps_T as_Eps();
        lang::meta::Node::ParseExpr::Indent_T as_Indent();
        lang::meta::Node::ParseExpr::Dedent_T as_Dedent();
        lang::meta::Node::ParseExpr::Newline_T as_Newline();
        lang::meta::Node::ParseExpr::UnicodeAny_T as_UnicodeAny();
        lang::meta::Node::ParseExpr::AsciiBaseAny_T as_AsciiBaseAny();
        lang::meta::Node::ParseExpr::Alt_T as_Alt();
        lang::meta::Node::ParseExpr::AltExplicit_T as_AltExplicit();
        lang::meta::Node::ParseExpr::Minus_T as_Minus();
        lang::meta::Node::ParseExpr::Concat_T as_Concat();
        lang::meta::Node::ParseExpr::Optional_T as_Optional();
        lang::meta::Node::ParseExpr::Rep_T as_Rep();
        lang::meta::Node::ParseExpr::RepNonzero_T as_RepNonzero();
        lang::meta::Node::ParseExpr::RepCount_T as_RepCount();
        lang::meta::Node::ParseExpr::CharRange_T as_CharRange();
        lang::meta::Node::ParseExpr::StrLit_T as_StrLit();
        lang::meta::Node::ParseExpr::Underscore_T as_Underscore();
        lang::meta::Node::ParseExpr::Pass_T as_Pass();
        lang::meta::Node::ParseExpr::Paren_T as_Paren();
        lang::meta::Node::ParseExpr::Name_T as_Name();
        lang::meta::Node::ParseExpr::List_T as_List();
        lang::meta::Node::ParseExpr::Unfold_T as_Unfold();
        lang::meta::Node::ParseExpr::AttrReq_T as_AttrReq();
        void hash_ser_acc_lang_meta_Node_ParseExpr(SerBuf& buf) const;
        virtual void hash_ser_acc(SerBuf& buf) const = 0;
    };
}

void pr_debug(ostream& os, FmtFlags flags, lang::meta::Node::AttrReq_T x);

namespace lang::meta::Node::AttrReq {
    enum struct _W {
        Base,
        PrecStar,
    };
}

namespace lang::meta::Node::AttrReq {
    struct _T: lang::meta::Node::_T {
        void write(ostream& os, FmtFlags flags);
        lang::meta::Node::AttrReq::_W w_;
        virtual ~_T();
        _T(lang::meta::Node::AttrReq::_W w);
        bool is_Base();
        bool is_PrecStar();
        lang::meta::Node::AttrReq::Base_T as_Base();
        lang::meta::Node::AttrReq::PrecStar_T as_PrecStar();
        void hash_ser_acc_lang_meta_Node_AttrReq(SerBuf& buf) const;
        virtual void hash_ser_acc(SerBuf& buf) const = 0;
    };
}

void pr_debug(ostream& os, FmtFlags flags, lang::meta::Node::ParseExprListType_T x);

namespace lang::meta::Node::ParseExprListType {
    enum struct _W {
        List,
        Block,
        Block2,
        Top,
        Top2,
    };
}

namespace lang::meta::Node::ParseExprListType {
    struct _T: lang::meta::Node::_T {
        void write(ostream& os, FmtFlags flags);
        lang::meta::Node::ParseExprListType::_W w_;
        virtual ~_T();
        _T(lang::meta::Node::ParseExprListType::_W w);
        bool is_List();
        bool is_Block();
        bool is_Block2();
        bool is_Top();
        bool is_Top2();
        lang::meta::Node::ParseExprListType::List_T as_List();
        lang::meta::Node::ParseExprListType::Block_T as_Block();
        lang::meta::Node::ParseExprListType::Block2_T as_Block2();
        lang::meta::Node::ParseExprListType::Top_T as_Top();
        lang::meta::Node::ParseExprListType::Top2_T as_Top2();
        void hash_ser_acc_lang_meta_Node_ParseExprListType(SerBuf& buf) const;
        virtual void hash_ser_acc(SerBuf& buf) const = 0;
    };
}

void pr_debug(ostream& os, FmtFlags flags, lang::meta::Node::ParseExprListNum_T x);

namespace lang::meta::Node::ParseExprListNum {
    enum struct _W {
        Ge0,
        Ge1,
        Ge2,
    };
}

namespace lang::meta::Node::ParseExprListNum {
    struct _T: lang::meta::Node::_T {
        void write(ostream& os, FmtFlags flags);
        lang::meta::Node::ParseExprListNum::_W w_;
        virtual ~_T();
        _T(lang::meta::Node::ParseExprListNum::_W w);
        bool is_Ge0();
        bool is_Ge1();
        bool is_Ge2();
        lang::meta::Node::ParseExprListNum::Ge0_T as_Ge0();
        lang::meta::Node::ParseExprListNum::Ge1_T as_Ge1();
        lang::meta::Node::ParseExprListNum::Ge2_T as_Ge2();
        void hash_ser_acc_lang_meta_Node_ParseExprListNum(SerBuf& buf) const;
        virtual void hash_ser_acc(SerBuf& buf) const = 0;
    };
}

void pr_debug(ostream& os, FmtFlags flags, lang::meta::Node::Stanza::Tokens_T x);

namespace lang::meta::Node::Stanza::Tokens {
    __attribute__((always_inline)) lang::meta::Node::Stanza::Tokens_T make(Int id, lang_rt::TokenBounds bounds, bool is_top, lang_rt::ParserSymId sym, lang_rt::ParserAttrMask attr, lang_rt::ParserLookahead first_k, Vec_T<lang::meta::Node::TokenDecl_T> decls);
}

namespace lang::meta::Node::Stanza::Tokens {
    __attribute__((always_inline)) lang::meta::Node::Stanza::Tokens_T make_ext(ArenaPtr arena, Int id, lang_rt::TokenBounds bounds, bool is_top, lang_rt::ParserSymId sym, lang_rt::ParserAttrMask attr, lang_rt::ParserLookahead first_k, Vec_T<lang::meta::Node::TokenDecl_T> decls);
}

namespace lang::meta::Node::Stanza::Tokens {
    struct _T: lang::meta::Node::Stanza::_T {
        void write(ostream& os, FmtFlags flags);
        Vec_T<lang::meta::Node::TokenDecl_T> decls_;
        _T();
        lang::meta::Node::Stanza::Tokens_T with_id(Int id);
        lang::meta::Node::Stanza::Tokens_T with_bounds(lang_rt::TokenBounds bounds);
        lang::meta::Node::Stanza::Tokens_T with_is_top(bool is_top);
        lang::meta::Node::Stanza::Tokens_T with_sym(lang_rt::ParserSymId sym);
        lang::meta::Node::Stanza::Tokens_T with_attr(lang_rt::ParserAttrMask attr);
        lang::meta::Node::Stanza::Tokens_T with_first_k(lang_rt::ParserLookahead first_k);
        lang::meta::Node::Stanza::Tokens_T with_decls(Vec_T<lang::meta::Node::TokenDecl_T> decls);
        void hash_ser_acc_lang_meta_Node_Stanza_Tokens(SerBuf& buf) const;
        virtual void hash_ser_acc(SerBuf& buf) const;
    };
}

void pr_debug(ostream& os, FmtFlags flags, lang::meta::Node::Stanza::Lexer_T x);

namespace lang::meta::Node::Stanza::Lexer {
    __attribute__((always_inline)) lang::meta::Node::Stanza::Lexer_T make(Int id, lang_rt::TokenBounds bounds, bool is_top, lang_rt::ParserSymId sym, lang_rt::ParserAttrMask attr, lang_rt::ParserLookahead first_k, Vec_T<lang::meta::Node::LexerDecl_T> decls);
}

namespace lang::meta::Node::Stanza::Lexer {
    __attribute__((always_inline)) lang::meta::Node::Stanza::Lexer_T make_ext(ArenaPtr arena, Int id, lang_rt::TokenBounds bounds, bool is_top, lang_rt::ParserSymId sym, lang_rt::ParserAttrMask attr, lang_rt::ParserLookahead first_k, Vec_T<lang::meta::Node::LexerDecl_T> decls);
}

namespace lang::meta::Node::Stanza::Lexer {
    struct _T: lang::meta::Node::Stanza::_T {
        void write(ostream& os, FmtFlags flags);
        Vec_T<lang::meta::Node::LexerDecl_T> decls_;
        _T();
        lang::meta::Node::Stanza::Lexer_T with_id(Int id);
        lang::meta::Node::Stanza::Lexer_T with_bounds(lang_rt::TokenBounds bounds);
        lang::meta::Node::Stanza::Lexer_T with_is_top(bool is_top);
        lang::meta::Node::Stanza::Lexer_T with_sym(lang_rt::ParserSymId sym);
        lang::meta::Node::Stanza::Lexer_T with_attr(lang_rt::ParserAttrMask attr);
        lang::meta::Node::Stanza::Lexer_T with_first_k(lang_rt::ParserLookahead first_k);
        lang::meta::Node::Stanza::Lexer_T with_decls(Vec_T<lang::meta::Node::LexerDecl_T> decls);
        void hash_ser_acc_lang_meta_Node_Stanza_Lexer(SerBuf& buf) const;
        virtual void hash_ser_acc(SerBuf& buf) const;
    };
}

void pr_debug(ostream& os, FmtFlags flags, lang::meta::Node::Stanza::Parser_T x);

namespace lang::meta::Node::Stanza::Parser {
    __attribute__((always_inline)) lang::meta::Node::Stanza::Parser_T make(Int id, lang_rt::TokenBounds bounds, bool is_top, lang_rt::ParserSymId sym, lang_rt::ParserAttrMask attr, lang_rt::ParserLookahead first_k, Vec_T<lang::meta::Node::ParserDecl_T> decls);
}

namespace lang::meta::Node::Stanza::Parser {
    __attribute__((always_inline)) lang::meta::Node::Stanza::Parser_T make_ext(ArenaPtr arena, Int id, lang_rt::TokenBounds bounds, bool is_top, lang_rt::ParserSymId sym, lang_rt::ParserAttrMask attr, lang_rt::ParserLookahead first_k, Vec_T<lang::meta::Node::ParserDecl_T> decls);
}

namespace lang::meta::Node::Stanza::Parser {
    struct _T: lang::meta::Node::Stanza::_T {
        void write(ostream& os, FmtFlags flags);
        Vec_T<lang::meta::Node::ParserDecl_T> decls_;
        _T();
        lang::meta::Node::Stanza::Parser_T with_id(Int id);
        lang::meta::Node::Stanza::Parser_T with_bounds(lang_rt::TokenBounds bounds);
        lang::meta::Node::Stanza::Parser_T with_is_top(bool is_top);
        lang::meta::Node::Stanza::Parser_T with_sym(lang_rt::ParserSymId sym);
        lang::meta::Node::Stanza::Parser_T with_attr(lang_rt::ParserAttrMask attr);
        lang::meta::Node::Stanza::Parser_T with_first_k(lang_rt::ParserLookahead first_k);
        lang::meta::Node::Stanza::Parser_T with_decls(Vec_T<lang::meta::Node::ParserDecl_T> decls);
        void hash_ser_acc_lang_meta_Node_Stanza_Parser(SerBuf& buf) const;
        virtual void hash_ser_acc(SerBuf& buf) const;
    };
}

void pr_debug(ostream& os, FmtFlags flags, lang::meta::Node::Stanza::Test_T x);

namespace lang::meta::Node::Stanza::Test {
    __attribute__((always_inline)) lang::meta::Node::Stanza::Test_T make(Int id, lang_rt::TokenBounds bounds, bool is_top, lang_rt::ParserSymId sym, lang_rt::ParserAttrMask attr, lang_rt::ParserLookahead first_k, Vec_T<lang::meta::Node::TestCase_T> items);
}

namespace lang::meta::Node::Stanza::Test {
    __attribute__((always_inline)) lang::meta::Node::Stanza::Test_T make_ext(ArenaPtr arena, Int id, lang_rt::TokenBounds bounds, bool is_top, lang_rt::ParserSymId sym, lang_rt::ParserAttrMask attr, lang_rt::ParserLookahead first_k, Vec_T<lang::meta::Node::TestCase_T> items);
}

namespace lang::meta::Node::Stanza::Test {
    struct _T: lang::meta::Node::Stanza::_T {
        void write(ostream& os, FmtFlags flags);
        Vec_T<lang::meta::Node::TestCase_T> items_;
        _T();
        lang::meta::Node::Stanza::Test_T with_id(Int id);
        lang::meta::Node::Stanza::Test_T with_bounds(lang_rt::TokenBounds bounds);
        lang::meta::Node::Stanza::Test_T with_is_top(bool is_top);
        lang::meta::Node::Stanza::Test_T with_sym(lang_rt::ParserSymId sym);
        lang::meta::Node::Stanza::Test_T with_attr(lang_rt::ParserAttrMask attr);
        lang::meta::Node::Stanza::Test_T with_first_k(lang_rt::ParserLookahead first_k);
        lang::meta::Node::Stanza::Test_T with_items(Vec_T<lang::meta::Node::TestCase_T> items);
        void hash_ser_acc_lang_meta_Node_Stanza_Test(SerBuf& buf) const;
        virtual void hash_ser_acc(SerBuf& buf) const;
    };
}

void pr_debug(ostream& os, FmtFlags flags, lang::meta::Node::Stanza::CompileTest_T x);

namespace lang::meta::Node::Stanza::CompileTest {
    __attribute__((always_inline)) lang::meta::Node::Stanza::CompileTest_T make(Int id, lang_rt::TokenBounds bounds, bool is_top, lang_rt::ParserSymId sym, lang_rt::ParserAttrMask attr, lang_rt::ParserLookahead first_k, Vec_T<lang::meta::Node::CompileTestCase_T> items);
}

namespace lang::meta::Node::Stanza::CompileTest {
    __attribute__((always_inline)) lang::meta::Node::Stanza::CompileTest_T make_ext(ArenaPtr arena, Int id, lang_rt::TokenBounds bounds, bool is_top, lang_rt::ParserSymId sym, lang_rt::ParserAttrMask attr, lang_rt::ParserLookahead first_k, Vec_T<lang::meta::Node::CompileTestCase_T> items);
}

namespace lang::meta::Node::Stanza::CompileTest {
    struct _T: lang::meta::Node::Stanza::_T {
        void write(ostream& os, FmtFlags flags);
        Vec_T<lang::meta::Node::CompileTestCase_T> items_;
        _T();
        lang::meta::Node::Stanza::CompileTest_T with_id(Int id);
        lang::meta::Node::Stanza::CompileTest_T with_bounds(lang_rt::TokenBounds bounds);
        lang::meta::Node::Stanza::CompileTest_T with_is_top(bool is_top);
        lang::meta::Node::Stanza::CompileTest_T with_sym(lang_rt::ParserSymId sym);
        lang::meta::Node::Stanza::CompileTest_T with_attr(lang_rt::ParserAttrMask attr);
        lang::meta::Node::Stanza::CompileTest_T with_first_k(lang_rt::ParserLookahead first_k);
        lang::meta::Node::Stanza::CompileTest_T with_items(Vec_T<lang::meta::Node::CompileTestCase_T> items);
        void hash_ser_acc_lang_meta_Node_Stanza_CompileTest(SerBuf& buf) const;
        virtual void hash_ser_acc(SerBuf& buf) const;
    };
}

void pr_debug(ostream& os, FmtFlags flags, lang::meta::Node::TokenDecl::op_T x);

namespace lang::meta::Node::TokenDecl::op {
    enum struct _W {
        DEF,
        DEF_ALIAS,
    };
}

namespace lang::meta::Node::TokenDecl::op {
    struct _T: lang::meta::Node::_T {
        void write(ostream& os, FmtFlags flags);
        lang::meta::Node::TokenDecl::op::_W w_;
        virtual ~_T();
        _T(lang::meta::Node::TokenDecl::op::_W w);
        bool is_DEF();
        bool is_DEF_ALIAS();
        lang::meta::Node::TokenDecl::op::DEF_T as_DEF();
        lang::meta::Node::TokenDecl::op::DEF_ALIAS_T as_DEF_ALIAS();
        void hash_ser_acc_lang_meta_Node_TokenDecl_op(SerBuf& buf) const;
        virtual void hash_ser_acc(SerBuf& buf) const = 0;
    };
}

void pr_debug(ostream& os, FmtFlags flags, lang::meta::Node::LexerDecl::Main_T x);

namespace lang::meta::Node::LexerDecl::Main {
    __attribute__((always_inline)) lang::meta::Node::LexerDecl::Main_T make(Int id, lang_rt::TokenBounds bounds, bool is_top, lang_rt::ParserSymId sym, lang_rt::ParserAttrMask attr, lang_rt::ParserLookahead first_k, StrSlice name);
}

namespace lang::meta::Node::LexerDecl::Main {
    __attribute__((always_inline)) lang::meta::Node::LexerDecl::Main_T make_ext(ArenaPtr arena, Int id, lang_rt::TokenBounds bounds, bool is_top, lang_rt::ParserSymId sym, lang_rt::ParserAttrMask attr, lang_rt::ParserLookahead first_k, StrSlice name);
}

namespace lang::meta::Node::LexerDecl::Main {
    struct _T: lang::meta::Node::LexerDecl::_T {
        void write(ostream& os, FmtFlags flags);
        StrSlice name_;
        _T();
        lang::meta::Node::LexerDecl::Main_T with_id(Int id);
        lang::meta::Node::LexerDecl::Main_T with_bounds(lang_rt::TokenBounds bounds);
        lang::meta::Node::LexerDecl::Main_T with_is_top(bool is_top);
        lang::meta::Node::LexerDecl::Main_T with_sym(lang_rt::ParserSymId sym);
        lang::meta::Node::LexerDecl::Main_T with_attr(lang_rt::ParserAttrMask attr);
        lang::meta::Node::LexerDecl::Main_T with_first_k(lang_rt::ParserLookahead first_k);
        lang::meta::Node::LexerDecl::Main_T with_name(StrSlice name);
        void hash_ser_acc_lang_meta_Node_LexerDecl_Main(SerBuf& buf) const;
        virtual void hash_ser_acc(SerBuf& buf) const;
    };
}

void pr_debug(ostream& os, FmtFlags flags, lang::meta::Node::LexerDecl::Mode_T x);

namespace lang::meta::Node::LexerDecl::Mode {
    __attribute__((always_inline)) lang::meta::Node::LexerDecl::Mode_T make(Int id, lang_rt::TokenBounds bounds, bool is_top, lang_rt::ParserSymId sym, lang_rt::ParserAttrMask attr, lang_rt::ParserLookahead first_k, StrSlice name, bool ws_sig_, Vec_T<lang::meta::Node::LexerModeCase_T> cases);
}

namespace lang::meta::Node::LexerDecl::Mode {
    __attribute__((always_inline)) lang::meta::Node::LexerDecl::Mode_T make_ext(ArenaPtr arena, Int id, lang_rt::TokenBounds bounds, bool is_top, lang_rt::ParserSymId sym, lang_rt::ParserAttrMask attr, lang_rt::ParserLookahead first_k, StrSlice name, bool ws_sig_, Vec_T<lang::meta::Node::LexerModeCase_T> cases);
}

namespace lang::meta::Node::LexerDecl::Mode {
    struct _T: lang::meta::Node::LexerDecl::_T {
        void write(ostream& os, FmtFlags flags);
        StrSlice name_;
        bool ws_sig__;
        Vec_T<lang::meta::Node::LexerModeCase_T> cases_;
        _T();
        lang::meta::Node::LexerDecl::Mode_T with_id(Int id);
        lang::meta::Node::LexerDecl::Mode_T with_bounds(lang_rt::TokenBounds bounds);
        lang::meta::Node::LexerDecl::Mode_T with_is_top(bool is_top);
        lang::meta::Node::LexerDecl::Mode_T with_sym(lang_rt::ParserSymId sym);
        lang::meta::Node::LexerDecl::Mode_T with_attr(lang_rt::ParserAttrMask attr);
        lang::meta::Node::LexerDecl::Mode_T with_first_k(lang_rt::ParserLookahead first_k);
        lang::meta::Node::LexerDecl::Mode_T with_name(StrSlice name);
        lang::meta::Node::LexerDecl::Mode_T with_ws_sig_(bool ws_sig_);
        lang::meta::Node::LexerDecl::Mode_T with_cases(Vec_T<lang::meta::Node::LexerModeCase_T> cases);
        void hash_ser_acc_lang_meta_Node_LexerDecl_Mode(SerBuf& buf) const;
        virtual void hash_ser_acc(SerBuf& buf) const;
    };
}

void pr_debug(ostream& os, FmtFlags flags, lang::meta::Node::LexerInstr::Emit_T x);

namespace lang::meta::Node::LexerInstr::Emit {
    __attribute__((always_inline)) lang::meta::Node::LexerInstr::Emit_T make(Int id, lang_rt::TokenBounds bounds, bool is_top, lang_rt::ParserSymId sym, lang_rt::ParserAttrMask attr, lang_rt::ParserLookahead first_k, Option_T<lang::meta::Node::ParseExpr_T> arg);
}

namespace lang::meta::Node::LexerInstr::Emit {
    __attribute__((always_inline)) lang::meta::Node::LexerInstr::Emit_T make_ext(ArenaPtr arena, Int id, lang_rt::TokenBounds bounds, bool is_top, lang_rt::ParserSymId sym, lang_rt::ParserAttrMask attr, lang_rt::ParserLookahead first_k, Option_T<lang::meta::Node::ParseExpr_T> arg);
}

namespace lang::meta::Node::LexerInstr::Emit {
    struct _T: lang::meta::Node::LexerInstr::_T {
        void write(ostream& os, FmtFlags flags);
        Option_T<lang::meta::Node::ParseExpr_T> arg_;
        _T();
        lang::meta::Node::LexerInstr::Emit_T with_id(Int id);
        lang::meta::Node::LexerInstr::Emit_T with_bounds(lang_rt::TokenBounds bounds);
        lang::meta::Node::LexerInstr::Emit_T with_is_top(bool is_top);
        lang::meta::Node::LexerInstr::Emit_T with_sym(lang_rt::ParserSymId sym);
        lang::meta::Node::LexerInstr::Emit_T with_attr(lang_rt::ParserAttrMask attr);
        lang::meta::Node::LexerInstr::Emit_T with_first_k(lang_rt::ParserLookahead first_k);
        lang::meta::Node::LexerInstr::Emit_T with_arg(Option_T<lang::meta::Node::ParseExpr_T> arg);
        void hash_ser_acc_lang_meta_Node_LexerInstr_Emit(SerBuf& buf) const;
        virtual void hash_ser_acc(SerBuf& buf) const;
    };
}

void pr_debug(ostream& os, FmtFlags flags, lang::meta::Node::LexerInstr::Pass_T x);

namespace lang::meta::Node::LexerInstr::Pass {
    __attribute__((always_inline)) lang::meta::Node::LexerInstr::Pass_T make(Int id, lang_rt::TokenBounds bounds, bool is_top, lang_rt::ParserSymId sym, lang_rt::ParserAttrMask attr, lang_rt::ParserLookahead first_k);
}

namespace lang::meta::Node::LexerInstr::Pass {
    __attribute__((always_inline)) lang::meta::Node::LexerInstr::Pass_T make_ext(ArenaPtr arena, Int id, lang_rt::TokenBounds bounds, bool is_top, lang_rt::ParserSymId sym, lang_rt::ParserAttrMask attr, lang_rt::ParserLookahead first_k);
}

namespace lang::meta::Node::LexerInstr::Pass {
    struct _T: lang::meta::Node::LexerInstr::_T {
        void write(ostream& os, FmtFlags flags);
        _T();
        lang::meta::Node::LexerInstr::Pass_T with_id(Int id);
        lang::meta::Node::LexerInstr::Pass_T with_bounds(lang_rt::TokenBounds bounds);
        lang::meta::Node::LexerInstr::Pass_T with_is_top(bool is_top);
        lang::meta::Node::LexerInstr::Pass_T with_sym(lang_rt::ParserSymId sym);
        lang::meta::Node::LexerInstr::Pass_T with_attr(lang_rt::ParserAttrMask attr);
        lang::meta::Node::LexerInstr::Pass_T with_first_k(lang_rt::ParserLookahead first_k);
        void hash_ser_acc_lang_meta_Node_LexerInstr_Pass(SerBuf& buf) const;
        virtual void hash_ser_acc(SerBuf& buf) const;
    };
}

void pr_debug(ostream& os, FmtFlags flags, lang::meta::Node::LexerInstr::Push_T x);

namespace lang::meta::Node::LexerInstr::Push {
    __attribute__((always_inline)) lang::meta::Node::LexerInstr::Push_T make(Int id, lang_rt::TokenBounds bounds, bool is_top, lang_rt::ParserSymId sym, lang_rt::ParserAttrMask attr, lang_rt::ParserLookahead first_k, StrSlice name);
}

namespace lang::meta::Node::LexerInstr::Push {
    __attribute__((always_inline)) lang::meta::Node::LexerInstr::Push_T make_ext(ArenaPtr arena, Int id, lang_rt::TokenBounds bounds, bool is_top, lang_rt::ParserSymId sym, lang_rt::ParserAttrMask attr, lang_rt::ParserLookahead first_k, StrSlice name);
}

namespace lang::meta::Node::LexerInstr::Push {
    struct _T: lang::meta::Node::LexerInstr::_T {
        void write(ostream& os, FmtFlags flags);
        StrSlice name_;
        _T();
        lang::meta::Node::LexerInstr::Push_T with_id(Int id);
        lang::meta::Node::LexerInstr::Push_T with_bounds(lang_rt::TokenBounds bounds);
        lang::meta::Node::LexerInstr::Push_T with_is_top(bool is_top);
        lang::meta::Node::LexerInstr::Push_T with_sym(lang_rt::ParserSymId sym);
        lang::meta::Node::LexerInstr::Push_T with_attr(lang_rt::ParserAttrMask attr);
        lang::meta::Node::LexerInstr::Push_T with_first_k(lang_rt::ParserLookahead first_k);
        lang::meta::Node::LexerInstr::Push_T with_name(StrSlice name);
        void hash_ser_acc_lang_meta_Node_LexerInstr_Push(SerBuf& buf) const;
        virtual void hash_ser_acc(SerBuf& buf) const;
    };
}

void pr_debug(ostream& os, FmtFlags flags, lang::meta::Node::LexerInstr::Pop_T x);

namespace lang::meta::Node::LexerInstr::Pop {
    __attribute__((always_inline)) lang::meta::Node::LexerInstr::Pop_T make(Int id, lang_rt::TokenBounds bounds, bool is_top, lang_rt::ParserSymId sym, lang_rt::ParserAttrMask attr, lang_rt::ParserLookahead first_k);
}

namespace lang::meta::Node::LexerInstr::Pop {
    __attribute__((always_inline)) lang::meta::Node::LexerInstr::Pop_T make_ext(ArenaPtr arena, Int id, lang_rt::TokenBounds bounds, bool is_top, lang_rt::ParserSymId sym, lang_rt::ParserAttrMask attr, lang_rt::ParserLookahead first_k);
}

namespace lang::meta::Node::LexerInstr::Pop {
    struct _T: lang::meta::Node::LexerInstr::_T {
        void write(ostream& os, FmtFlags flags);
        _T();
        lang::meta::Node::LexerInstr::Pop_T with_id(Int id);
        lang::meta::Node::LexerInstr::Pop_T with_bounds(lang_rt::TokenBounds bounds);
        lang::meta::Node::LexerInstr::Pop_T with_is_top(bool is_top);
        lang::meta::Node::LexerInstr::Pop_T with_sym(lang_rt::ParserSymId sym);
        lang::meta::Node::LexerInstr::Pop_T with_attr(lang_rt::ParserAttrMask attr);
        lang::meta::Node::LexerInstr::Pop_T with_first_k(lang_rt::ParserLookahead first_k);
        void hash_ser_acc_lang_meta_Node_LexerInstr_Pop(SerBuf& buf) const;
        virtual void hash_ser_acc(SerBuf& buf) const;
    };
}

void pr_debug(ostream& os, FmtFlags flags, lang::meta::Node::LexerInstr::PopExtract_T x);

namespace lang::meta::Node::LexerInstr::PopExtract {
    __attribute__((always_inline)) lang::meta::Node::LexerInstr::PopExtract_T make(Int id, lang_rt::TokenBounds bounds, bool is_top, lang_rt::ParserSymId sym, lang_rt::ParserAttrMask attr, lang_rt::ParserLookahead first_k);
}

namespace lang::meta::Node::LexerInstr::PopExtract {
    __attribute__((always_inline)) lang::meta::Node::LexerInstr::PopExtract_T make_ext(ArenaPtr arena, Int id, lang_rt::TokenBounds bounds, bool is_top, lang_rt::ParserSymId sym, lang_rt::ParserAttrMask attr, lang_rt::ParserLookahead first_k);
}

namespace lang::meta::Node::LexerInstr::PopExtract {
    struct _T: lang::meta::Node::LexerInstr::_T {
        void write(ostream& os, FmtFlags flags);
        _T();
        lang::meta::Node::LexerInstr::PopExtract_T with_id(Int id);
        lang::meta::Node::LexerInstr::PopExtract_T with_bounds(lang_rt::TokenBounds bounds);
        lang::meta::Node::LexerInstr::PopExtract_T with_is_top(bool is_top);
        lang::meta::Node::LexerInstr::PopExtract_T with_sym(lang_rt::ParserSymId sym);
        lang::meta::Node::LexerInstr::PopExtract_T with_attr(lang_rt::ParserAttrMask attr);
        lang::meta::Node::LexerInstr::PopExtract_T with_first_k(lang_rt::ParserLookahead first_k);
        void hash_ser_acc_lang_meta_Node_LexerInstr_PopExtract(SerBuf& buf) const;
        virtual void hash_ser_acc(SerBuf& buf) const;
    };
}

void pr_debug(ostream& os, FmtFlags flags, lang::meta::Node::LexerInstr::PopEmit_T x);

namespace lang::meta::Node::LexerInstr::PopEmit {
    __attribute__((always_inline)) lang::meta::Node::LexerInstr::PopEmit_T make(Int id, lang_rt::TokenBounds bounds, bool is_top, lang_rt::ParserSymId sym, lang_rt::ParserAttrMask attr, lang_rt::ParserLookahead first_k, lang::meta::Node::ParseExpr_T arg);
}

namespace lang::meta::Node::LexerInstr::PopEmit {
    __attribute__((always_inline)) lang::meta::Node::LexerInstr::PopEmit_T make_ext(ArenaPtr arena, Int id, lang_rt::TokenBounds bounds, bool is_top, lang_rt::ParserSymId sym, lang_rt::ParserAttrMask attr, lang_rt::ParserLookahead first_k, lang::meta::Node::ParseExpr_T arg);
}

namespace lang::meta::Node::LexerInstr::PopEmit {
    struct _T: lang::meta::Node::LexerInstr::_T {
        void write(ostream& os, FmtFlags flags);
        lang::meta::Node::ParseExpr_T arg_;
        _T();
        lang::meta::Node::LexerInstr::PopEmit_T with_id(Int id);
        lang::meta::Node::LexerInstr::PopEmit_T with_bounds(lang_rt::TokenBounds bounds);
        lang::meta::Node::LexerInstr::PopEmit_T with_is_top(bool is_top);
        lang::meta::Node::LexerInstr::PopEmit_T with_sym(lang_rt::ParserSymId sym);
        lang::meta::Node::LexerInstr::PopEmit_T with_attr(lang_rt::ParserAttrMask attr);
        lang::meta::Node::LexerInstr::PopEmit_T with_first_k(lang_rt::ParserLookahead first_k);
        lang::meta::Node::LexerInstr::PopEmit_T with_arg(lang::meta::Node::ParseExpr_T arg);
        void hash_ser_acc_lang_meta_Node_LexerInstr_PopEmit(SerBuf& buf) const;
        virtual void hash_ser_acc(SerBuf& buf) const;
    };
}

void pr_debug(ostream& os, FmtFlags flags, lang::meta::Node::LexerInstr::MatchHistory_T x);

namespace lang::meta::Node::LexerInstr::MatchHistory {
    __attribute__((always_inline)) lang::meta::Node::LexerInstr::MatchHistory_T make(Int id, lang_rt::TokenBounds bounds, bool is_top, lang_rt::ParserSymId sym, lang_rt::ParserAttrMask attr, lang_rt::ParserLookahead first_k, Vec_T<lang::meta::Node::LexerModeCase_T> cases);
}

namespace lang::meta::Node::LexerInstr::MatchHistory {
    __attribute__((always_inline)) lang::meta::Node::LexerInstr::MatchHistory_T make_ext(ArenaPtr arena, Int id, lang_rt::TokenBounds bounds, bool is_top, lang_rt::ParserSymId sym, lang_rt::ParserAttrMask attr, lang_rt::ParserLookahead first_k, Vec_T<lang::meta::Node::LexerModeCase_T> cases);
}

namespace lang::meta::Node::LexerInstr::MatchHistory {
    struct _T: lang::meta::Node::LexerInstr::_T {
        void write(ostream& os, FmtFlags flags);
        Vec_T<lang::meta::Node::LexerModeCase_T> cases_;
        _T();
        lang::meta::Node::LexerInstr::MatchHistory_T with_id(Int id);
        lang::meta::Node::LexerInstr::MatchHistory_T with_bounds(lang_rt::TokenBounds bounds);
        lang::meta::Node::LexerInstr::MatchHistory_T with_is_top(bool is_top);
        lang::meta::Node::LexerInstr::MatchHistory_T with_sym(lang_rt::ParserSymId sym);
        lang::meta::Node::LexerInstr::MatchHistory_T with_attr(lang_rt::ParserAttrMask attr);
        lang::meta::Node::LexerInstr::MatchHistory_T with_first_k(lang_rt::ParserLookahead first_k);
        lang::meta::Node::LexerInstr::MatchHistory_T with_cases(Vec_T<lang::meta::Node::LexerModeCase_T> cases);
        void hash_ser_acc_lang_meta_Node_LexerInstr_MatchHistory(SerBuf& buf) const;
        virtual void hash_ser_acc(SerBuf& buf) const;
    };
}

void pr_debug(ostream& os, FmtFlags flags, lang::meta::Node::ParserDecl::Main_T x);

namespace lang::meta::Node::ParserDecl::Main {
    __attribute__((always_inline)) lang::meta::Node::ParserDecl::Main_T make(Int id, lang_rt::TokenBounds bounds, bool is_top, lang_rt::ParserSymId sym, lang_rt::ParserAttrMask attr, lang_rt::ParserLookahead first_k, Vec_T<StrSlice> names);
}

namespace lang::meta::Node::ParserDecl::Main {
    __attribute__((always_inline)) lang::meta::Node::ParserDecl::Main_T make_ext(ArenaPtr arena, Int id, lang_rt::TokenBounds bounds, bool is_top, lang_rt::ParserSymId sym, lang_rt::ParserAttrMask attr, lang_rt::ParserLookahead first_k, Vec_T<StrSlice> names);
}

namespace lang::meta::Node::ParserDecl::Main {
    struct _T: lang::meta::Node::ParserDecl::_T {
        void write(ostream& os, FmtFlags flags);
        Vec_T<StrSlice> names_;
        _T();
        lang::meta::Node::ParserDecl::Main_T with_id(Int id);
        lang::meta::Node::ParserDecl::Main_T with_bounds(lang_rt::TokenBounds bounds);
        lang::meta::Node::ParserDecl::Main_T with_is_top(bool is_top);
        lang::meta::Node::ParserDecl::Main_T with_sym(lang_rt::ParserSymId sym);
        lang::meta::Node::ParserDecl::Main_T with_attr(lang_rt::ParserAttrMask attr);
        lang::meta::Node::ParserDecl::Main_T with_first_k(lang_rt::ParserLookahead first_k);
        lang::meta::Node::ParserDecl::Main_T with_names(Vec_T<StrSlice> names);
        void hash_ser_acc_lang_meta_Node_ParserDecl_Main(SerBuf& buf) const;
        virtual void hash_ser_acc(SerBuf& buf) const;
    };
}

void pr_debug(ostream& os, FmtFlags flags, lang::meta::Node::ParserDecl::Prop_T x);

namespace lang::meta::Node::ParserDecl::Prop {
    __attribute__((always_inline)) lang::meta::Node::ParserDecl::Prop_T make(Int id, lang_rt::TokenBounds bounds, bool is_top, lang_rt::ParserSymId sym, lang_rt::ParserAttrMask attr, lang_rt::ParserLookahead first_k, Vec_T<lang::meta::Node::ParserProp_T> props);
}

namespace lang::meta::Node::ParserDecl::Prop {
    __attribute__((always_inline)) lang::meta::Node::ParserDecl::Prop_T make_ext(ArenaPtr arena, Int id, lang_rt::TokenBounds bounds, bool is_top, lang_rt::ParserSymId sym, lang_rt::ParserAttrMask attr, lang_rt::ParserLookahead first_k, Vec_T<lang::meta::Node::ParserProp_T> props);
}

namespace lang::meta::Node::ParserDecl::Prop {
    struct _T: lang::meta::Node::ParserDecl::_T {
        void write(ostream& os, FmtFlags flags);
        Vec_T<lang::meta::Node::ParserProp_T> props_;
        _T();
        lang::meta::Node::ParserDecl::Prop_T with_id(Int id);
        lang::meta::Node::ParserDecl::Prop_T with_bounds(lang_rt::TokenBounds bounds);
        lang::meta::Node::ParserDecl::Prop_T with_is_top(bool is_top);
        lang::meta::Node::ParserDecl::Prop_T with_sym(lang_rt::ParserSymId sym);
        lang::meta::Node::ParserDecl::Prop_T with_attr(lang_rt::ParserAttrMask attr);
        lang::meta::Node::ParserDecl::Prop_T with_first_k(lang_rt::ParserLookahead first_k);
        lang::meta::Node::ParserDecl::Prop_T with_props(Vec_T<lang::meta::Node::ParserProp_T> props);
        void hash_ser_acc_lang_meta_Node_ParserDecl_Prop(SerBuf& buf) const;
        virtual void hash_ser_acc(SerBuf& buf) const;
    };
}

void pr_debug(ostream& os, FmtFlags flags, lang::meta::Node::ParserDecl::Prec_T x);

namespace lang::meta::Node::ParserDecl::Prec {
    __attribute__((always_inline)) lang::meta::Node::ParserDecl::Prec_T make(Int id, lang_rt::TokenBounds bounds, bool is_top, lang_rt::ParserSymId sym, lang_rt::ParserAttrMask attr, lang_rt::ParserLookahead first_k, Vec_T<lang::meta::Node::PrecItem_T> items);
}

namespace lang::meta::Node::ParserDecl::Prec {
    __attribute__((always_inline)) lang::meta::Node::ParserDecl::Prec_T make_ext(ArenaPtr arena, Int id, lang_rt::TokenBounds bounds, bool is_top, lang_rt::ParserSymId sym, lang_rt::ParserAttrMask attr, lang_rt::ParserLookahead first_k, Vec_T<lang::meta::Node::PrecItem_T> items);
}

namespace lang::meta::Node::ParserDecl::Prec {
    struct _T: lang::meta::Node::ParserDecl::_T {
        void write(ostream& os, FmtFlags flags);
        Vec_T<lang::meta::Node::PrecItem_T> items_;
        _T();
        lang::meta::Node::ParserDecl::Prec_T with_id(Int id);
        lang::meta::Node::ParserDecl::Prec_T with_bounds(lang_rt::TokenBounds bounds);
        lang::meta::Node::ParserDecl::Prec_T with_is_top(bool is_top);
        lang::meta::Node::ParserDecl::Prec_T with_sym(lang_rt::ParserSymId sym);
        lang::meta::Node::ParserDecl::Prec_T with_attr(lang_rt::ParserAttrMask attr);
        lang::meta::Node::ParserDecl::Prec_T with_first_k(lang_rt::ParserLookahead first_k);
        lang::meta::Node::ParserDecl::Prec_T with_items(Vec_T<lang::meta::Node::PrecItem_T> items);
        void hash_ser_acc_lang_meta_Node_ParserDecl_Prec(SerBuf& buf) const;
        virtual void hash_ser_acc(SerBuf& buf) const;
    };
}

void pr_debug(ostream& os, FmtFlags flags, lang::meta::Node::ParserDecl::Attr_T x);

namespace lang::meta::Node::ParserDecl::Attr {
    __attribute__((always_inline)) lang::meta::Node::ParserDecl::Attr_T make(Int id, lang_rt::TokenBounds bounds, bool is_top, lang_rt::ParserSymId sym, lang_rt::ParserAttrMask attr, lang_rt::ParserLookahead first_k, Vec_T<lang::meta::Node::AttrClause_T> clauses);
}

namespace lang::meta::Node::ParserDecl::Attr {
    __attribute__((always_inline)) lang::meta::Node::ParserDecl::Attr_T make_ext(ArenaPtr arena, Int id, lang_rt::TokenBounds bounds, bool is_top, lang_rt::ParserSymId sym, lang_rt::ParserAttrMask attr, lang_rt::ParserLookahead first_k, Vec_T<lang::meta::Node::AttrClause_T> clauses);
}

namespace lang::meta::Node::ParserDecl::Attr {
    struct _T: lang::meta::Node::ParserDecl::_T {
        void write(ostream& os, FmtFlags flags);
        Vec_T<lang::meta::Node::AttrClause_T> clauses_;
        _T();
        lang::meta::Node::ParserDecl::Attr_T with_id(Int id);
        lang::meta::Node::ParserDecl::Attr_T with_bounds(lang_rt::TokenBounds bounds);
        lang::meta::Node::ParserDecl::Attr_T with_is_top(bool is_top);
        lang::meta::Node::ParserDecl::Attr_T with_sym(lang_rt::ParserSymId sym);
        lang::meta::Node::ParserDecl::Attr_T with_attr(lang_rt::ParserAttrMask attr);
        lang::meta::Node::ParserDecl::Attr_T with_first_k(lang_rt::ParserLookahead first_k);
        lang::meta::Node::ParserDecl::Attr_T with_clauses(Vec_T<lang::meta::Node::AttrClause_T> clauses);
        void hash_ser_acc_lang_meta_Node_ParserDecl_Attr(SerBuf& buf) const;
        virtual void hash_ser_acc(SerBuf& buf) const;
    };
}

void pr_debug(ostream& os, FmtFlags flags, lang::meta::Node::ParserDecl::Rule_T x);

namespace lang::meta::Node::ParserDecl::Rule {
    __attribute__((always_inline)) lang::meta::Node::ParserDecl::Rule_T make(Int id, lang_rt::TokenBounds bounds, bool is_top, lang_rt::ParserSymId sym, lang_rt::ParserAttrMask attr, lang_rt::ParserLookahead first_k, lang::meta::Node::Id_T name, Option_T<Vec_T<lang::meta::Node::AttrReq_T>> lhs_attrs, lang::meta::Node::ParserDecl::Rule::op_T op, lang::meta::Node::ParseExpr_T e);
}

namespace lang::meta::Node::ParserDecl::Rule {
    __attribute__((always_inline)) lang::meta::Node::ParserDecl::Rule_T make_ext(ArenaPtr arena, Int id, lang_rt::TokenBounds bounds, bool is_top, lang_rt::ParserSymId sym, lang_rt::ParserAttrMask attr, lang_rt::ParserLookahead first_k, lang::meta::Node::Id_T name, Option_T<Vec_T<lang::meta::Node::AttrReq_T>> lhs_attrs, lang::meta::Node::ParserDecl::Rule::op_T op, lang::meta::Node::ParseExpr_T e);
}

namespace lang::meta::Node::ParserDecl::Rule {
    struct _T: lang::meta::Node::ParserDecl::_T {
        void write(ostream& os, FmtFlags flags);
        lang::meta::Node::Id_T name_;
        Option_T<Vec_T<lang::meta::Node::AttrReq_T>> lhs_attrs_;
        lang::meta::Node::ParserDecl::Rule::op_T op_;
        lang::meta::Node::ParseExpr_T e_;
        _T();
        lang::meta::Node::ParserDecl::Rule_T with_id(Int id);
        lang::meta::Node::ParserDecl::Rule_T with_bounds(lang_rt::TokenBounds bounds);
        lang::meta::Node::ParserDecl::Rule_T with_is_top(bool is_top);
        lang::meta::Node::ParserDecl::Rule_T with_sym(lang_rt::ParserSymId sym);
        lang::meta::Node::ParserDecl::Rule_T with_attr(lang_rt::ParserAttrMask attr);
        lang::meta::Node::ParserDecl::Rule_T with_first_k(lang_rt::ParserLookahead first_k);
        lang::meta::Node::ParserDecl::Rule_T with_name(lang::meta::Node::Id_T name);
        lang::meta::Node::ParserDecl::Rule_T with_lhs_attrs(Option_T<Vec_T<lang::meta::Node::AttrReq_T>> lhs_attrs);
        lang::meta::Node::ParserDecl::Rule_T with_op(lang::meta::Node::ParserDecl::Rule::op_T op);
        lang::meta::Node::ParserDecl::Rule_T with_e(lang::meta::Node::ParseExpr_T e);
        void hash_ser_acc_lang_meta_Node_ParserDecl_Rule(SerBuf& buf) const;
        virtual void hash_ser_acc(SerBuf& buf) const;
    };
}

void pr_debug(ostream& os, FmtFlags flags, lang::meta::Node::ParserProp::NameStrict_T x);

namespace lang::meta::Node::ParserProp::NameStrict {
    __attribute__((always_inline)) lang::meta::Node::ParserProp::NameStrict_T make(Int id, lang_rt::TokenBounds bounds, bool is_top, lang_rt::ParserSymId sym, lang_rt::ParserAttrMask attr, lang_rt::ParserLookahead first_k);
}

namespace lang::meta::Node::ParserProp::NameStrict {
    __attribute__((always_inline)) lang::meta::Node::ParserProp::NameStrict_T make_ext(ArenaPtr arena, Int id, lang_rt::TokenBounds bounds, bool is_top, lang_rt::ParserSymId sym, lang_rt::ParserAttrMask attr, lang_rt::ParserLookahead first_k);
}

namespace lang::meta::Node::ParserProp::NameStrict {
    struct _T: lang::meta::Node::ParserProp::_T {
        void write(ostream& os, FmtFlags flags);
        _T();
        lang::meta::Node::ParserProp::NameStrict_T with_id(Int id);
        lang::meta::Node::ParserProp::NameStrict_T with_bounds(lang_rt::TokenBounds bounds);
        lang::meta::Node::ParserProp::NameStrict_T with_is_top(bool is_top);
        lang::meta::Node::ParserProp::NameStrict_T with_sym(lang_rt::ParserSymId sym);
        lang::meta::Node::ParserProp::NameStrict_T with_attr(lang_rt::ParserAttrMask attr);
        lang::meta::Node::ParserProp::NameStrict_T with_first_k(lang_rt::ParserLookahead first_k);
        void hash_ser_acc_lang_meta_Node_ParserProp_NameStrict(SerBuf& buf) const;
        virtual void hash_ser_acc(SerBuf& buf) const;
    };
}

void pr_debug(ostream& os, FmtFlags flags, lang::meta::Node::ParserProp::LRSpec_T x);

namespace lang::meta::Node::ParserProp::LRSpec {
    __attribute__((always_inline)) lang::meta::Node::ParserProp::LRSpec_T make(Int id, lang_rt::TokenBounds bounds, bool is_top, lang_rt::ParserSymId sym, lang_rt::ParserAttrMask attr, lang_rt::ParserLookahead first_k, StrSlice k);
}

namespace lang::meta::Node::ParserProp::LRSpec {
    __attribute__((always_inline)) lang::meta::Node::ParserProp::LRSpec_T make_ext(ArenaPtr arena, Int id, lang_rt::TokenBounds bounds, bool is_top, lang_rt::ParserSymId sym, lang_rt::ParserAttrMask attr, lang_rt::ParserLookahead first_k, StrSlice k);
}

namespace lang::meta::Node::ParserProp::LRSpec {
    struct _T: lang::meta::Node::ParserProp::_T {
        void write(ostream& os, FmtFlags flags);
        StrSlice k_;
        _T();
        lang::meta::Node::ParserProp::LRSpec_T with_id(Int id);
        lang::meta::Node::ParserProp::LRSpec_T with_bounds(lang_rt::TokenBounds bounds);
        lang::meta::Node::ParserProp::LRSpec_T with_is_top(bool is_top);
        lang::meta::Node::ParserProp::LRSpec_T with_sym(lang_rt::ParserSymId sym);
        lang::meta::Node::ParserProp::LRSpec_T with_attr(lang_rt::ParserAttrMask attr);
        lang::meta::Node::ParserProp::LRSpec_T with_first_k(lang_rt::ParserLookahead first_k);
        lang::meta::Node::ParserProp::LRSpec_T with_k(StrSlice k);
        void hash_ser_acc_lang_meta_Node_ParserProp_LRSpec(SerBuf& buf) const;
        virtual void hash_ser_acc(SerBuf& buf) const;
    };
}

void pr_debug(ostream& os, FmtFlags flags, lang::meta::Node::ParserProp::Err__T x);

namespace lang::meta::Node::ParserProp::Err_ {
    __attribute__((always_inline)) lang::meta::Node::ParserProp::Err__T make(Int id, lang_rt::TokenBounds bounds, bool is_top, lang_rt::ParserSymId sym, lang_rt::ParserAttrMask attr, lang_rt::ParserLookahead first_k);
}

namespace lang::meta::Node::ParserProp::Err_ {
    __attribute__((always_inline)) lang::meta::Node::ParserProp::Err__T make_ext(ArenaPtr arena, Int id, lang_rt::TokenBounds bounds, bool is_top, lang_rt::ParserSymId sym, lang_rt::ParserAttrMask attr, lang_rt::ParserLookahead first_k);
}

namespace lang::meta::Node::ParserProp::Err_ {
    struct _T: lang::meta::Node::ParserProp::_T {
        void write(ostream& os, FmtFlags flags);
        _T();
        lang::meta::Node::ParserProp::Err__T with_id(Int id);
        lang::meta::Node::ParserProp::Err__T with_bounds(lang_rt::TokenBounds bounds);
        lang::meta::Node::ParserProp::Err__T with_is_top(bool is_top);
        lang::meta::Node::ParserProp::Err__T with_sym(lang_rt::ParserSymId sym);
        lang::meta::Node::ParserProp::Err__T with_attr(lang_rt::ParserAttrMask attr);
        lang::meta::Node::ParserProp::Err__T with_first_k(lang_rt::ParserLookahead first_k);
        void hash_ser_acc_lang_meta_Node_ParserProp_Err_(SerBuf& buf) const;
        virtual void hash_ser_acc(SerBuf& buf) const;
    };
}

void pr_debug(ostream& os, FmtFlags flags, lang::meta::Node::PrecAssoc::Left_T x);

namespace lang::meta::Node::PrecAssoc::Left {
    __attribute__((always_inline)) lang::meta::Node::PrecAssoc::Left_T make(Int id, lang_rt::TokenBounds bounds, bool is_top, lang_rt::ParserSymId sym, lang_rt::ParserAttrMask attr, lang_rt::ParserLookahead first_k);
}

namespace lang::meta::Node::PrecAssoc::Left {
    __attribute__((always_inline)) lang::meta::Node::PrecAssoc::Left_T make_ext(ArenaPtr arena, Int id, lang_rt::TokenBounds bounds, bool is_top, lang_rt::ParserSymId sym, lang_rt::ParserAttrMask attr, lang_rt::ParserLookahead first_k);
}

namespace lang::meta::Node::PrecAssoc::Left {
    struct _T: lang::meta::Node::PrecAssoc::_T {
        void write(ostream& os, FmtFlags flags);
        _T();
        lang::meta::Node::PrecAssoc::Left_T with_id(Int id);
        lang::meta::Node::PrecAssoc::Left_T with_bounds(lang_rt::TokenBounds bounds);
        lang::meta::Node::PrecAssoc::Left_T with_is_top(bool is_top);
        lang::meta::Node::PrecAssoc::Left_T with_sym(lang_rt::ParserSymId sym);
        lang::meta::Node::PrecAssoc::Left_T with_attr(lang_rt::ParserAttrMask attr);
        lang::meta::Node::PrecAssoc::Left_T with_first_k(lang_rt::ParserLookahead first_k);
        void hash_ser_acc_lang_meta_Node_PrecAssoc_Left(SerBuf& buf) const;
        virtual void hash_ser_acc(SerBuf& buf) const;
    };
}

void pr_debug(ostream& os, FmtFlags flags, lang::meta::Node::PrecAssoc::Right_T x);

namespace lang::meta::Node::PrecAssoc::Right {
    __attribute__((always_inline)) lang::meta::Node::PrecAssoc::Right_T make(Int id, lang_rt::TokenBounds bounds, bool is_top, lang_rt::ParserSymId sym, lang_rt::ParserAttrMask attr, lang_rt::ParserLookahead first_k);
}

namespace lang::meta::Node::PrecAssoc::Right {
    __attribute__((always_inline)) lang::meta::Node::PrecAssoc::Right_T make_ext(ArenaPtr arena, Int id, lang_rt::TokenBounds bounds, bool is_top, lang_rt::ParserSymId sym, lang_rt::ParserAttrMask attr, lang_rt::ParserLookahead first_k);
}

namespace lang::meta::Node::PrecAssoc::Right {
    struct _T: lang::meta::Node::PrecAssoc::_T {
        void write(ostream& os, FmtFlags flags);
        _T();
        lang::meta::Node::PrecAssoc::Right_T with_id(Int id);
        lang::meta::Node::PrecAssoc::Right_T with_bounds(lang_rt::TokenBounds bounds);
        lang::meta::Node::PrecAssoc::Right_T with_is_top(bool is_top);
        lang::meta::Node::PrecAssoc::Right_T with_sym(lang_rt::ParserSymId sym);
        lang::meta::Node::PrecAssoc::Right_T with_attr(lang_rt::ParserAttrMask attr);
        lang::meta::Node::PrecAssoc::Right_T with_first_k(lang_rt::ParserLookahead first_k);
        void hash_ser_acc_lang_meta_Node_PrecAssoc_Right(SerBuf& buf) const;
        virtual void hash_ser_acc(SerBuf& buf) const;
    };
}

void pr_debug(ostream& os, FmtFlags flags, lang::meta::Node::PrecAssoc::Prefix_T x);

namespace lang::meta::Node::PrecAssoc::Prefix {
    __attribute__((always_inline)) lang::meta::Node::PrecAssoc::Prefix_T make(Int id, lang_rt::TokenBounds bounds, bool is_top, lang_rt::ParserSymId sym, lang_rt::ParserAttrMask attr, lang_rt::ParserLookahead first_k);
}

namespace lang::meta::Node::PrecAssoc::Prefix {
    __attribute__((always_inline)) lang::meta::Node::PrecAssoc::Prefix_T make_ext(ArenaPtr arena, Int id, lang_rt::TokenBounds bounds, bool is_top, lang_rt::ParserSymId sym, lang_rt::ParserAttrMask attr, lang_rt::ParserLookahead first_k);
}

namespace lang::meta::Node::PrecAssoc::Prefix {
    struct _T: lang::meta::Node::PrecAssoc::_T {
        void write(ostream& os, FmtFlags flags);
        _T();
        lang::meta::Node::PrecAssoc::Prefix_T with_id(Int id);
        lang::meta::Node::PrecAssoc::Prefix_T with_bounds(lang_rt::TokenBounds bounds);
        lang::meta::Node::PrecAssoc::Prefix_T with_is_top(bool is_top);
        lang::meta::Node::PrecAssoc::Prefix_T with_sym(lang_rt::ParserSymId sym);
        lang::meta::Node::PrecAssoc::Prefix_T with_attr(lang_rt::ParserAttrMask attr);
        lang::meta::Node::PrecAssoc::Prefix_T with_first_k(lang_rt::ParserLookahead first_k);
        void hash_ser_acc_lang_meta_Node_PrecAssoc_Prefix(SerBuf& buf) const;
        virtual void hash_ser_acc(SerBuf& buf) const;
    };
}

void pr_debug(ostream& os, FmtFlags flags, lang::meta::Node::PrecAssoc::Postfix_T x);

namespace lang::meta::Node::PrecAssoc::Postfix {
    __attribute__((always_inline)) lang::meta::Node::PrecAssoc::Postfix_T make(Int id, lang_rt::TokenBounds bounds, bool is_top, lang_rt::ParserSymId sym, lang_rt::ParserAttrMask attr, lang_rt::ParserLookahead first_k);
}

namespace lang::meta::Node::PrecAssoc::Postfix {
    __attribute__((always_inline)) lang::meta::Node::PrecAssoc::Postfix_T make_ext(ArenaPtr arena, Int id, lang_rt::TokenBounds bounds, bool is_top, lang_rt::ParserSymId sym, lang_rt::ParserAttrMask attr, lang_rt::ParserLookahead first_k);
}

namespace lang::meta::Node::PrecAssoc::Postfix {
    struct _T: lang::meta::Node::PrecAssoc::_T {
        void write(ostream& os, FmtFlags flags);
        _T();
        lang::meta::Node::PrecAssoc::Postfix_T with_id(Int id);
        lang::meta::Node::PrecAssoc::Postfix_T with_bounds(lang_rt::TokenBounds bounds);
        lang::meta::Node::PrecAssoc::Postfix_T with_is_top(bool is_top);
        lang::meta::Node::PrecAssoc::Postfix_T with_sym(lang_rt::ParserSymId sym);
        lang::meta::Node::PrecAssoc::Postfix_T with_attr(lang_rt::ParserAttrMask attr);
        lang::meta::Node::PrecAssoc::Postfix_T with_first_k(lang_rt::ParserLookahead first_k);
        void hash_ser_acc_lang_meta_Node_PrecAssoc_Postfix(SerBuf& buf) const;
        virtual void hash_ser_acc(SerBuf& buf) const;
    };
}

void pr_debug(ostream& os, FmtFlags flags, lang::meta::Node::AttrClause::Expr_T x);

namespace lang::meta::Node::AttrClause::Expr {
    __attribute__((always_inline)) lang::meta::Node::AttrClause::Expr_T make(Int id, lang_rt::TokenBounds bounds, bool is_top, lang_rt::ParserSymId sym, lang_rt::ParserAttrMask attr, lang_rt::ParserLookahead first_k, lang::meta::Node::AttrClauseExpr_T e);
}

namespace lang::meta::Node::AttrClause::Expr {
    __attribute__((always_inline)) lang::meta::Node::AttrClause::Expr_T make_ext(ArenaPtr arena, Int id, lang_rt::TokenBounds bounds, bool is_top, lang_rt::ParserSymId sym, lang_rt::ParserAttrMask attr, lang_rt::ParserLookahead first_k, lang::meta::Node::AttrClauseExpr_T e);
}

namespace lang::meta::Node::AttrClause::Expr {
    struct _T: lang::meta::Node::AttrClause::_T {
        void write(ostream& os, FmtFlags flags);
        lang::meta::Node::AttrClauseExpr_T e_;
        _T();
        lang::meta::Node::AttrClause::Expr_T with_id(Int id);
        lang::meta::Node::AttrClause::Expr_T with_bounds(lang_rt::TokenBounds bounds);
        lang::meta::Node::AttrClause::Expr_T with_is_top(bool is_top);
        lang::meta::Node::AttrClause::Expr_T with_sym(lang_rt::ParserSymId sym);
        lang::meta::Node::AttrClause::Expr_T with_attr(lang_rt::ParserAttrMask attr);
        lang::meta::Node::AttrClause::Expr_T with_first_k(lang_rt::ParserLookahead first_k);
        lang::meta::Node::AttrClause::Expr_T with_e(lang::meta::Node::AttrClauseExpr_T e);
        void hash_ser_acc_lang_meta_Node_AttrClause_Expr(SerBuf& buf) const;
        virtual void hash_ser_acc(SerBuf& buf) const;
    };
}

void pr_debug(ostream& os, FmtFlags flags, lang::meta::Node::AttrClause::Block_T x);

namespace lang::meta::Node::AttrClause::Block {
    __attribute__((always_inline)) lang::meta::Node::AttrClause::Block_T make(Int id, lang_rt::TokenBounds bounds, bool is_top, lang_rt::ParserSymId sym, lang_rt::ParserAttrMask attr, lang_rt::ParserLookahead first_k, Vec_T<lang::meta::Node::AttrClause_T> items);
}

namespace lang::meta::Node::AttrClause::Block {
    __attribute__((always_inline)) lang::meta::Node::AttrClause::Block_T make_ext(ArenaPtr arena, Int id, lang_rt::TokenBounds bounds, bool is_top, lang_rt::ParserSymId sym, lang_rt::ParserAttrMask attr, lang_rt::ParserLookahead first_k, Vec_T<lang::meta::Node::AttrClause_T> items);
}

namespace lang::meta::Node::AttrClause::Block {
    struct _T: lang::meta::Node::AttrClause::_T {
        void write(ostream& os, FmtFlags flags);
        Vec_T<lang::meta::Node::AttrClause_T> items_;
        _T();
        lang::meta::Node::AttrClause::Block_T with_id(Int id);
        lang::meta::Node::AttrClause::Block_T with_bounds(lang_rt::TokenBounds bounds);
        lang::meta::Node::AttrClause::Block_T with_is_top(bool is_top);
        lang::meta::Node::AttrClause::Block_T with_sym(lang_rt::ParserSymId sym);
        lang::meta::Node::AttrClause::Block_T with_attr(lang_rt::ParserAttrMask attr);
        lang::meta::Node::AttrClause::Block_T with_first_k(lang_rt::ParserLookahead first_k);
        lang::meta::Node::AttrClause::Block_T with_items(Vec_T<lang::meta::Node::AttrClause_T> items);
        void hash_ser_acc_lang_meta_Node_AttrClause_Block(SerBuf& buf) const;
        virtual void hash_ser_acc(SerBuf& buf) const;
    };
}

void pr_debug(ostream& os, FmtFlags flags, lang::meta::Node::AttrClause::Match_T x);

namespace lang::meta::Node::AttrClause::Match {
    __attribute__((always_inline)) lang::meta::Node::AttrClause::Match_T make(Int id, lang_rt::TokenBounds bounds, bool is_top, lang_rt::ParserSymId sym, lang_rt::ParserAttrMask attr, lang_rt::ParserLookahead first_k, Vec_T<lang::meta::Node::AttrMatchCase_T> cases);
}

namespace lang::meta::Node::AttrClause::Match {
    __attribute__((always_inline)) lang::meta::Node::AttrClause::Match_T make_ext(ArenaPtr arena, Int id, lang_rt::TokenBounds bounds, bool is_top, lang_rt::ParserSymId sym, lang_rt::ParserAttrMask attr, lang_rt::ParserLookahead first_k, Vec_T<lang::meta::Node::AttrMatchCase_T> cases);
}

namespace lang::meta::Node::AttrClause::Match {
    struct _T: lang::meta::Node::AttrClause::_T {
        void write(ostream& os, FmtFlags flags);
        Vec_T<lang::meta::Node::AttrMatchCase_T> cases_;
        _T();
        lang::meta::Node::AttrClause::Match_T with_id(Int id);
        lang::meta::Node::AttrClause::Match_T with_bounds(lang_rt::TokenBounds bounds);
        lang::meta::Node::AttrClause::Match_T with_is_top(bool is_top);
        lang::meta::Node::AttrClause::Match_T with_sym(lang_rt::ParserSymId sym);
        lang::meta::Node::AttrClause::Match_T with_attr(lang_rt::ParserAttrMask attr);
        lang::meta::Node::AttrClause::Match_T with_first_k(lang_rt::ParserLookahead first_k);
        lang::meta::Node::AttrClause::Match_T with_cases(Vec_T<lang::meta::Node::AttrMatchCase_T> cases);
        void hash_ser_acc_lang_meta_Node_AttrClause_Match(SerBuf& buf) const;
        virtual void hash_ser_acc(SerBuf& buf) const;
    };
}

void pr_debug(ostream& os, FmtFlags flags, lang::meta::Node::AttrMatchCasePattern::Alt_T x);

namespace lang::meta::Node::AttrMatchCasePattern::Alt {
    __attribute__((always_inline)) lang::meta::Node::AttrMatchCasePattern::Alt_T make(Int id, lang_rt::TokenBounds bounds, bool is_top, lang_rt::ParserSymId sym, lang_rt::ParserAttrMask attr, lang_rt::ParserLookahead first_k, Vec_T<lang::meta::Node::Id_T> items);
}

namespace lang::meta::Node::AttrMatchCasePattern::Alt {
    __attribute__((always_inline)) lang::meta::Node::AttrMatchCasePattern::Alt_T make_ext(ArenaPtr arena, Int id, lang_rt::TokenBounds bounds, bool is_top, lang_rt::ParserSymId sym, lang_rt::ParserAttrMask attr, lang_rt::ParserLookahead first_k, Vec_T<lang::meta::Node::Id_T> items);
}

namespace lang::meta::Node::AttrMatchCasePattern::Alt {
    struct _T: lang::meta::Node::AttrMatchCasePattern::_T {
        void write(ostream& os, FmtFlags flags);
        Vec_T<lang::meta::Node::Id_T> items_;
        _T();
        lang::meta::Node::AttrMatchCasePattern::Alt_T with_id(Int id);
        lang::meta::Node::AttrMatchCasePattern::Alt_T with_bounds(lang_rt::TokenBounds bounds);
        lang::meta::Node::AttrMatchCasePattern::Alt_T with_is_top(bool is_top);
        lang::meta::Node::AttrMatchCasePattern::Alt_T with_sym(lang_rt::ParserSymId sym);
        lang::meta::Node::AttrMatchCasePattern::Alt_T with_attr(lang_rt::ParserAttrMask attr);
        lang::meta::Node::AttrMatchCasePattern::Alt_T with_first_k(lang_rt::ParserLookahead first_k);
        lang::meta::Node::AttrMatchCasePattern::Alt_T with_items(Vec_T<lang::meta::Node::Id_T> items);
        void hash_ser_acc_lang_meta_Node_AttrMatchCasePattern_Alt(SerBuf& buf) const;
        virtual void hash_ser_acc(SerBuf& buf) const;
    };
}

void pr_debug(ostream& os, FmtFlags flags, lang::meta::Node::AttrMatchCasePattern::Wildcard_T x);

namespace lang::meta::Node::AttrMatchCasePattern::Wildcard {
    __attribute__((always_inline)) lang::meta::Node::AttrMatchCasePattern::Wildcard_T make(Int id, lang_rt::TokenBounds bounds, bool is_top, lang_rt::ParserSymId sym, lang_rt::ParserAttrMask attr, lang_rt::ParserLookahead first_k);
}

namespace lang::meta::Node::AttrMatchCasePattern::Wildcard {
    __attribute__((always_inline)) lang::meta::Node::AttrMatchCasePattern::Wildcard_T make_ext(ArenaPtr arena, Int id, lang_rt::TokenBounds bounds, bool is_top, lang_rt::ParserSymId sym, lang_rt::ParserAttrMask attr, lang_rt::ParserLookahead first_k);
}

namespace lang::meta::Node::AttrMatchCasePattern::Wildcard {
    struct _T: lang::meta::Node::AttrMatchCasePattern::_T {
        void write(ostream& os, FmtFlags flags);
        _T();
        lang::meta::Node::AttrMatchCasePattern::Wildcard_T with_id(Int id);
        lang::meta::Node::AttrMatchCasePattern::Wildcard_T with_bounds(lang_rt::TokenBounds bounds);
        lang::meta::Node::AttrMatchCasePattern::Wildcard_T with_is_top(bool is_top);
        lang::meta::Node::AttrMatchCasePattern::Wildcard_T with_sym(lang_rt::ParserSymId sym);
        lang::meta::Node::AttrMatchCasePattern::Wildcard_T with_attr(lang_rt::ParserAttrMask attr);
        lang::meta::Node::AttrMatchCasePattern::Wildcard_T with_first_k(lang_rt::ParserLookahead first_k);
        void hash_ser_acc_lang_meta_Node_AttrMatchCasePattern_Wildcard(SerBuf& buf) const;
        virtual void hash_ser_acc(SerBuf& buf) const;
    };
}

void pr_debug(ostream& os, FmtFlags flags, lang::meta::Node::AttrClauseExpr::LhsGeq_T x);

namespace lang::meta::Node::AttrClauseExpr::LhsGeq {
    __attribute__((always_inline)) lang::meta::Node::AttrClauseExpr::LhsGeq_T make(Int id, lang_rt::TokenBounds bounds, bool is_top, lang_rt::ParserSymId sym, lang_rt::ParserAttrMask attr, lang_rt::ParserLookahead first_k, StrSlice k);
}

namespace lang::meta::Node::AttrClauseExpr::LhsGeq {
    __attribute__((always_inline)) lang::meta::Node::AttrClauseExpr::LhsGeq_T make_ext(ArenaPtr arena, Int id, lang_rt::TokenBounds bounds, bool is_top, lang_rt::ParserSymId sym, lang_rt::ParserAttrMask attr, lang_rt::ParserLookahead first_k, StrSlice k);
}

namespace lang::meta::Node::AttrClauseExpr::LhsGeq {
    struct _T: lang::meta::Node::AttrClauseExpr::_T {
        void write(ostream& os, FmtFlags flags);
        StrSlice k_;
        _T();
        lang::meta::Node::AttrClauseExpr::LhsGeq_T with_id(Int id);
        lang::meta::Node::AttrClauseExpr::LhsGeq_T with_bounds(lang_rt::TokenBounds bounds);
        lang::meta::Node::AttrClauseExpr::LhsGeq_T with_is_top(bool is_top);
        lang::meta::Node::AttrClauseExpr::LhsGeq_T with_sym(lang_rt::ParserSymId sym);
        lang::meta::Node::AttrClauseExpr::LhsGeq_T with_attr(lang_rt::ParserAttrMask attr);
        lang::meta::Node::AttrClauseExpr::LhsGeq_T with_first_k(lang_rt::ParserLookahead first_k);
        lang::meta::Node::AttrClauseExpr::LhsGeq_T with_k(StrSlice k);
        void hash_ser_acc_lang_meta_Node_AttrClauseExpr_LhsGeq(SerBuf& buf) const;
        virtual void hash_ser_acc(SerBuf& buf) const;
    };
}

void pr_debug(ostream& os, FmtFlags flags, lang::meta::Node::AttrClauseExpr::RhsGeq_T x);

namespace lang::meta::Node::AttrClauseExpr::RhsGeq {
    __attribute__((always_inline)) lang::meta::Node::AttrClauseExpr::RhsGeq_T make(Int id, lang_rt::TokenBounds bounds, bool is_top, lang_rt::ParserSymId sym, lang_rt::ParserAttrMask attr, lang_rt::ParserLookahead first_k, lang::meta::Node::AttrClauseExprRhsLoc_T loc, StrSlice k);
}

namespace lang::meta::Node::AttrClauseExpr::RhsGeq {
    __attribute__((always_inline)) lang::meta::Node::AttrClauseExpr::RhsGeq_T make_ext(ArenaPtr arena, Int id, lang_rt::TokenBounds bounds, bool is_top, lang_rt::ParserSymId sym, lang_rt::ParserAttrMask attr, lang_rt::ParserLookahead first_k, lang::meta::Node::AttrClauseExprRhsLoc_T loc, StrSlice k);
}

namespace lang::meta::Node::AttrClauseExpr::RhsGeq {
    struct _T: lang::meta::Node::AttrClauseExpr::_T {
        void write(ostream& os, FmtFlags flags);
        lang::meta::Node::AttrClauseExprRhsLoc_T loc_;
        StrSlice k_;
        _T();
        lang::meta::Node::AttrClauseExpr::RhsGeq_T with_id(Int id);
        lang::meta::Node::AttrClauseExpr::RhsGeq_T with_bounds(lang_rt::TokenBounds bounds);
        lang::meta::Node::AttrClauseExpr::RhsGeq_T with_is_top(bool is_top);
        lang::meta::Node::AttrClauseExpr::RhsGeq_T with_sym(lang_rt::ParserSymId sym);
        lang::meta::Node::AttrClauseExpr::RhsGeq_T with_attr(lang_rt::ParserAttrMask attr);
        lang::meta::Node::AttrClauseExpr::RhsGeq_T with_first_k(lang_rt::ParserLookahead first_k);
        lang::meta::Node::AttrClauseExpr::RhsGeq_T with_loc(lang::meta::Node::AttrClauseExprRhsLoc_T loc);
        lang::meta::Node::AttrClauseExpr::RhsGeq_T with_k(StrSlice k);
        void hash_ser_acc_lang_meta_Node_AttrClauseExpr_RhsGeq(SerBuf& buf) const;
        virtual void hash_ser_acc(SerBuf& buf) const;
    };
}

void pr_debug(ostream& os, FmtFlags flags, lang::meta::Node::AttrClauseExpr::Implies_T x);

namespace lang::meta::Node::AttrClauseExpr::Implies {
    __attribute__((always_inline)) lang::meta::Node::AttrClauseExpr::Implies_T make(Int id, lang_rt::TokenBounds bounds, bool is_top, lang_rt::ParserSymId sym, lang_rt::ParserAttrMask attr, lang_rt::ParserLookahead first_k, StrSlice kl, lang::meta::Node::AttrClauseExprRhsLoc_T loc, StrSlice kr);
}

namespace lang::meta::Node::AttrClauseExpr::Implies {
    __attribute__((always_inline)) lang::meta::Node::AttrClauseExpr::Implies_T make_ext(ArenaPtr arena, Int id, lang_rt::TokenBounds bounds, bool is_top, lang_rt::ParserSymId sym, lang_rt::ParserAttrMask attr, lang_rt::ParserLookahead first_k, StrSlice kl, lang::meta::Node::AttrClauseExprRhsLoc_T loc, StrSlice kr);
}

namespace lang::meta::Node::AttrClauseExpr::Implies {
    struct _T: lang::meta::Node::AttrClauseExpr::_T {
        void write(ostream& os, FmtFlags flags);
        StrSlice kl_;
        lang::meta::Node::AttrClauseExprRhsLoc_T loc_;
        StrSlice kr_;
        _T();
        lang::meta::Node::AttrClauseExpr::Implies_T with_id(Int id);
        lang::meta::Node::AttrClauseExpr::Implies_T with_bounds(lang_rt::TokenBounds bounds);
        lang::meta::Node::AttrClauseExpr::Implies_T with_is_top(bool is_top);
        lang::meta::Node::AttrClauseExpr::Implies_T with_sym(lang_rt::ParserSymId sym);
        lang::meta::Node::AttrClauseExpr::Implies_T with_attr(lang_rt::ParserAttrMask attr);
        lang::meta::Node::AttrClauseExpr::Implies_T with_first_k(lang_rt::ParserLookahead first_k);
        lang::meta::Node::AttrClauseExpr::Implies_T with_kl(StrSlice kl);
        lang::meta::Node::AttrClauseExpr::Implies_T with_loc(lang::meta::Node::AttrClauseExprRhsLoc_T loc);
        lang::meta::Node::AttrClauseExpr::Implies_T with_kr(StrSlice kr);
        void hash_ser_acc_lang_meta_Node_AttrClauseExpr_Implies(SerBuf& buf) const;
        virtual void hash_ser_acc(SerBuf& buf) const;
    };
}

void pr_debug(ostream& os, FmtFlags flags, lang::meta::Node::AttrClauseExprRhsLoc::All_T x);

namespace lang::meta::Node::AttrClauseExprRhsLoc::All {
    __attribute__((always_inline)) lang::meta::Node::AttrClauseExprRhsLoc::All_T make(Int id, lang_rt::TokenBounds bounds, bool is_top, lang_rt::ParserSymId sym, lang_rt::ParserAttrMask attr, lang_rt::ParserLookahead first_k);
}

namespace lang::meta::Node::AttrClauseExprRhsLoc::All {
    __attribute__((always_inline)) lang::meta::Node::AttrClauseExprRhsLoc::All_T make_ext(ArenaPtr arena, Int id, lang_rt::TokenBounds bounds, bool is_top, lang_rt::ParserSymId sym, lang_rt::ParserAttrMask attr, lang_rt::ParserLookahead first_k);
}

namespace lang::meta::Node::AttrClauseExprRhsLoc::All {
    struct _T: lang::meta::Node::AttrClauseExprRhsLoc::_T {
        void write(ostream& os, FmtFlags flags);
        _T();
        lang::meta::Node::AttrClauseExprRhsLoc::All_T with_id(Int id);
        lang::meta::Node::AttrClauseExprRhsLoc::All_T with_bounds(lang_rt::TokenBounds bounds);
        lang::meta::Node::AttrClauseExprRhsLoc::All_T with_is_top(bool is_top);
        lang::meta::Node::AttrClauseExprRhsLoc::All_T with_sym(lang_rt::ParserSymId sym);
        lang::meta::Node::AttrClauseExprRhsLoc::All_T with_attr(lang_rt::ParserAttrMask attr);
        lang::meta::Node::AttrClauseExprRhsLoc::All_T with_first_k(lang_rt::ParserLookahead first_k);
        void hash_ser_acc_lang_meta_Node_AttrClauseExprRhsLoc_All(SerBuf& buf) const;
        virtual void hash_ser_acc(SerBuf& buf) const;
    };
}

void pr_debug(ostream& os, FmtFlags flags, lang::meta::Node::AttrClauseExprRhsLoc::Begin_T x);

namespace lang::meta::Node::AttrClauseExprRhsLoc::Begin {
    __attribute__((always_inline)) lang::meta::Node::AttrClauseExprRhsLoc::Begin_T make(Int id, lang_rt::TokenBounds bounds, bool is_top, lang_rt::ParserSymId sym, lang_rt::ParserAttrMask attr, lang_rt::ParserLookahead first_k);
}

namespace lang::meta::Node::AttrClauseExprRhsLoc::Begin {
    __attribute__((always_inline)) lang::meta::Node::AttrClauseExprRhsLoc::Begin_T make_ext(ArenaPtr arena, Int id, lang_rt::TokenBounds bounds, bool is_top, lang_rt::ParserSymId sym, lang_rt::ParserAttrMask attr, lang_rt::ParserLookahead first_k);
}

namespace lang::meta::Node::AttrClauseExprRhsLoc::Begin {
    struct _T: lang::meta::Node::AttrClauseExprRhsLoc::_T {
        void write(ostream& os, FmtFlags flags);
        _T();
        lang::meta::Node::AttrClauseExprRhsLoc::Begin_T with_id(Int id);
        lang::meta::Node::AttrClauseExprRhsLoc::Begin_T with_bounds(lang_rt::TokenBounds bounds);
        lang::meta::Node::AttrClauseExprRhsLoc::Begin_T with_is_top(bool is_top);
        lang::meta::Node::AttrClauseExprRhsLoc::Begin_T with_sym(lang_rt::ParserSymId sym);
        lang::meta::Node::AttrClauseExprRhsLoc::Begin_T with_attr(lang_rt::ParserAttrMask attr);
        lang::meta::Node::AttrClauseExprRhsLoc::Begin_T with_first_k(lang_rt::ParserLookahead first_k);
        void hash_ser_acc_lang_meta_Node_AttrClauseExprRhsLoc_Begin(SerBuf& buf) const;
        virtual void hash_ser_acc(SerBuf& buf) const;
    };
}

void pr_debug(ostream& os, FmtFlags flags, lang::meta::Node::AttrClauseExprRhsLoc::Mid_T x);

namespace lang::meta::Node::AttrClauseExprRhsLoc::Mid {
    __attribute__((always_inline)) lang::meta::Node::AttrClauseExprRhsLoc::Mid_T make(Int id, lang_rt::TokenBounds bounds, bool is_top, lang_rt::ParserSymId sym, lang_rt::ParserAttrMask attr, lang_rt::ParserLookahead first_k);
}

namespace lang::meta::Node::AttrClauseExprRhsLoc::Mid {
    __attribute__((always_inline)) lang::meta::Node::AttrClauseExprRhsLoc::Mid_T make_ext(ArenaPtr arena, Int id, lang_rt::TokenBounds bounds, bool is_top, lang_rt::ParserSymId sym, lang_rt::ParserAttrMask attr, lang_rt::ParserLookahead first_k);
}

namespace lang::meta::Node::AttrClauseExprRhsLoc::Mid {
    struct _T: lang::meta::Node::AttrClauseExprRhsLoc::_T {
        void write(ostream& os, FmtFlags flags);
        _T();
        lang::meta::Node::AttrClauseExprRhsLoc::Mid_T with_id(Int id);
        lang::meta::Node::AttrClauseExprRhsLoc::Mid_T with_bounds(lang_rt::TokenBounds bounds);
        lang::meta::Node::AttrClauseExprRhsLoc::Mid_T with_is_top(bool is_top);
        lang::meta::Node::AttrClauseExprRhsLoc::Mid_T with_sym(lang_rt::ParserSymId sym);
        lang::meta::Node::AttrClauseExprRhsLoc::Mid_T with_attr(lang_rt::ParserAttrMask attr);
        lang::meta::Node::AttrClauseExprRhsLoc::Mid_T with_first_k(lang_rt::ParserLookahead first_k);
        void hash_ser_acc_lang_meta_Node_AttrClauseExprRhsLoc_Mid(SerBuf& buf) const;
        virtual void hash_ser_acc(SerBuf& buf) const;
    };
}

void pr_debug(ostream& os, FmtFlags flags, lang::meta::Node::AttrClauseExprRhsLoc::End_T x);

namespace lang::meta::Node::AttrClauseExprRhsLoc::End {
    __attribute__((always_inline)) lang::meta::Node::AttrClauseExprRhsLoc::End_T make(Int id, lang_rt::TokenBounds bounds, bool is_top, lang_rt::ParserSymId sym, lang_rt::ParserAttrMask attr, lang_rt::ParserLookahead first_k);
}

namespace lang::meta::Node::AttrClauseExprRhsLoc::End {
    __attribute__((always_inline)) lang::meta::Node::AttrClauseExprRhsLoc::End_T make_ext(ArenaPtr arena, Int id, lang_rt::TokenBounds bounds, bool is_top, lang_rt::ParserSymId sym, lang_rt::ParserAttrMask attr, lang_rt::ParserLookahead first_k);
}

namespace lang::meta::Node::AttrClauseExprRhsLoc::End {
    struct _T: lang::meta::Node::AttrClauseExprRhsLoc::_T {
        void write(ostream& os, FmtFlags flags);
        _T();
        lang::meta::Node::AttrClauseExprRhsLoc::End_T with_id(Int id);
        lang::meta::Node::AttrClauseExprRhsLoc::End_T with_bounds(lang_rt::TokenBounds bounds);
        lang::meta::Node::AttrClauseExprRhsLoc::End_T with_is_top(bool is_top);
        lang::meta::Node::AttrClauseExprRhsLoc::End_T with_sym(lang_rt::ParserSymId sym);
        lang::meta::Node::AttrClauseExprRhsLoc::End_T with_attr(lang_rt::ParserAttrMask attr);
        lang::meta::Node::AttrClauseExprRhsLoc::End_T with_first_k(lang_rt::ParserLookahead first_k);
        void hash_ser_acc_lang_meta_Node_AttrClauseExprRhsLoc_End(SerBuf& buf) const;
        virtual void hash_ser_acc(SerBuf& buf) const;
    };
}

void pr_debug(ostream& os, FmtFlags flags, lang::meta::Node::ParseExpr::Id_T x);

namespace lang::meta::Node::ParseExpr::Id {
    __attribute__((always_inline)) lang::meta::Node::ParseExpr::Id_T make(Int id, lang_rt::TokenBounds bounds, bool is_top, lang_rt::ParserSymId sym, lang_rt::ParserAttrMask attr, lang_rt::ParserLookahead first_k, lang::meta::Node::Id_T id_);
}

namespace lang::meta::Node::ParseExpr::Id {
    __attribute__((always_inline)) lang::meta::Node::ParseExpr::Id_T make_ext(ArenaPtr arena, Int id, lang_rt::TokenBounds bounds, bool is_top, lang_rt::ParserSymId sym, lang_rt::ParserAttrMask attr, lang_rt::ParserLookahead first_k, lang::meta::Node::Id_T id_);
}

namespace lang::meta::Node::ParseExpr::Id {
    struct _T: lang::meta::Node::ParseExpr::_T {
        void write(ostream& os, FmtFlags flags);
        lang::meta::Node::Id_T id__;
        _T();
        lang::meta::Node::ParseExpr::Id_T with_id(Int id);
        lang::meta::Node::ParseExpr::Id_T with_bounds(lang_rt::TokenBounds bounds);
        lang::meta::Node::ParseExpr::Id_T with_is_top(bool is_top);
        lang::meta::Node::ParseExpr::Id_T with_sym(lang_rt::ParserSymId sym);
        lang::meta::Node::ParseExpr::Id_T with_attr(lang_rt::ParserAttrMask attr);
        lang::meta::Node::ParseExpr::Id_T with_first_k(lang_rt::ParserLookahead first_k);
        lang::meta::Node::ParseExpr::Id_T with_id_(lang::meta::Node::Id_T id_);
        void hash_ser_acc_lang_meta_Node_ParseExpr_Id(SerBuf& buf) const;
        virtual void hash_ser_acc(SerBuf& buf) const;
    };
}

void pr_debug(ostream& os, FmtFlags flags, lang::meta::Node::ParseExpr::Eof_T x);

namespace lang::meta::Node::ParseExpr::Eof {
    __attribute__((always_inline)) lang::meta::Node::ParseExpr::Eof_T make(Int id, lang_rt::TokenBounds bounds, bool is_top, lang_rt::ParserSymId sym, lang_rt::ParserAttrMask attr, lang_rt::ParserLookahead first_k);
}

namespace lang::meta::Node::ParseExpr::Eof {
    __attribute__((always_inline)) lang::meta::Node::ParseExpr::Eof_T make_ext(ArenaPtr arena, Int id, lang_rt::TokenBounds bounds, bool is_top, lang_rt::ParserSymId sym, lang_rt::ParserAttrMask attr, lang_rt::ParserLookahead first_k);
}

namespace lang::meta::Node::ParseExpr::Eof {
    struct _T: lang::meta::Node::ParseExpr::_T {
        void write(ostream& os, FmtFlags flags);
        _T();
        lang::meta::Node::ParseExpr::Eof_T with_id(Int id);
        lang::meta::Node::ParseExpr::Eof_T with_bounds(lang_rt::TokenBounds bounds);
        lang::meta::Node::ParseExpr::Eof_T with_is_top(bool is_top);
        lang::meta::Node::ParseExpr::Eof_T with_sym(lang_rt::ParserSymId sym);
        lang::meta::Node::ParseExpr::Eof_T with_attr(lang_rt::ParserAttrMask attr);
        lang::meta::Node::ParseExpr::Eof_T with_first_k(lang_rt::ParserLookahead first_k);
        void hash_ser_acc_lang_meta_Node_ParseExpr_Eof(SerBuf& buf) const;
        virtual void hash_ser_acc(SerBuf& buf) const;
    };
}

void pr_debug(ostream& os, FmtFlags flags, lang::meta::Node::ParseExpr::False_T x);

namespace lang::meta::Node::ParseExpr::False {
    __attribute__((always_inline)) lang::meta::Node::ParseExpr::False_T make(Int id, lang_rt::TokenBounds bounds, bool is_top, lang_rt::ParserSymId sym, lang_rt::ParserAttrMask attr, lang_rt::ParserLookahead first_k);
}

namespace lang::meta::Node::ParseExpr::False {
    __attribute__((always_inline)) lang::meta::Node::ParseExpr::False_T make_ext(ArenaPtr arena, Int id, lang_rt::TokenBounds bounds, bool is_top, lang_rt::ParserSymId sym, lang_rt::ParserAttrMask attr, lang_rt::ParserLookahead first_k);
}

namespace lang::meta::Node::ParseExpr::False {
    struct _T: lang::meta::Node::ParseExpr::_T {
        void write(ostream& os, FmtFlags flags);
        _T();
        lang::meta::Node::ParseExpr::False_T with_id(Int id);
        lang::meta::Node::ParseExpr::False_T with_bounds(lang_rt::TokenBounds bounds);
        lang::meta::Node::ParseExpr::False_T with_is_top(bool is_top);
        lang::meta::Node::ParseExpr::False_T with_sym(lang_rt::ParserSymId sym);
        lang::meta::Node::ParseExpr::False_T with_attr(lang_rt::ParserAttrMask attr);
        lang::meta::Node::ParseExpr::False_T with_first_k(lang_rt::ParserLookahead first_k);
        void hash_ser_acc_lang_meta_Node_ParseExpr_False(SerBuf& buf) const;
        virtual void hash_ser_acc(SerBuf& buf) const;
    };
}

void pr_debug(ostream& os, FmtFlags flags, lang::meta::Node::ParseExpr::Eps_T x);

namespace lang::meta::Node::ParseExpr::Eps {
    __attribute__((always_inline)) lang::meta::Node::ParseExpr::Eps_T make(Int id, lang_rt::TokenBounds bounds, bool is_top, lang_rt::ParserSymId sym, lang_rt::ParserAttrMask attr, lang_rt::ParserLookahead first_k);
}

namespace lang::meta::Node::ParseExpr::Eps {
    __attribute__((always_inline)) lang::meta::Node::ParseExpr::Eps_T make_ext(ArenaPtr arena, Int id, lang_rt::TokenBounds bounds, bool is_top, lang_rt::ParserSymId sym, lang_rt::ParserAttrMask attr, lang_rt::ParserLookahead first_k);
}

namespace lang::meta::Node::ParseExpr::Eps {
    struct _T: lang::meta::Node::ParseExpr::_T {
        void write(ostream& os, FmtFlags flags);
        _T();
        lang::meta::Node::ParseExpr::Eps_T with_id(Int id);
        lang::meta::Node::ParseExpr::Eps_T with_bounds(lang_rt::TokenBounds bounds);
        lang::meta::Node::ParseExpr::Eps_T with_is_top(bool is_top);
        lang::meta::Node::ParseExpr::Eps_T with_sym(lang_rt::ParserSymId sym);
        lang::meta::Node::ParseExpr::Eps_T with_attr(lang_rt::ParserAttrMask attr);
        lang::meta::Node::ParseExpr::Eps_T with_first_k(lang_rt::ParserLookahead first_k);
        void hash_ser_acc_lang_meta_Node_ParseExpr_Eps(SerBuf& buf) const;
        virtual void hash_ser_acc(SerBuf& buf) const;
    };
}

void pr_debug(ostream& os, FmtFlags flags, lang::meta::Node::ParseExpr::Indent_T x);

namespace lang::meta::Node::ParseExpr::Indent {
    __attribute__((always_inline)) lang::meta::Node::ParseExpr::Indent_T make(Int id, lang_rt::TokenBounds bounds, bool is_top, lang_rt::ParserSymId sym, lang_rt::ParserAttrMask attr, lang_rt::ParserLookahead first_k);
}

namespace lang::meta::Node::ParseExpr::Indent {
    __attribute__((always_inline)) lang::meta::Node::ParseExpr::Indent_T make_ext(ArenaPtr arena, Int id, lang_rt::TokenBounds bounds, bool is_top, lang_rt::ParserSymId sym, lang_rt::ParserAttrMask attr, lang_rt::ParserLookahead first_k);
}

namespace lang::meta::Node::ParseExpr::Indent {
    struct _T: lang::meta::Node::ParseExpr::_T {
        void write(ostream& os, FmtFlags flags);
        _T();
        lang::meta::Node::ParseExpr::Indent_T with_id(Int id);
        lang::meta::Node::ParseExpr::Indent_T with_bounds(lang_rt::TokenBounds bounds);
        lang::meta::Node::ParseExpr::Indent_T with_is_top(bool is_top);
        lang::meta::Node::ParseExpr::Indent_T with_sym(lang_rt::ParserSymId sym);
        lang::meta::Node::ParseExpr::Indent_T with_attr(lang_rt::ParserAttrMask attr);
        lang::meta::Node::ParseExpr::Indent_T with_first_k(lang_rt::ParserLookahead first_k);
        void hash_ser_acc_lang_meta_Node_ParseExpr_Indent(SerBuf& buf) const;
        virtual void hash_ser_acc(SerBuf& buf) const;
    };
}

void pr_debug(ostream& os, FmtFlags flags, lang::meta::Node::ParseExpr::Dedent_T x);

namespace lang::meta::Node::ParseExpr::Dedent {
    __attribute__((always_inline)) lang::meta::Node::ParseExpr::Dedent_T make(Int id, lang_rt::TokenBounds bounds, bool is_top, lang_rt::ParserSymId sym, lang_rt::ParserAttrMask attr, lang_rt::ParserLookahead first_k);
}

namespace lang::meta::Node::ParseExpr::Dedent {
    __attribute__((always_inline)) lang::meta::Node::ParseExpr::Dedent_T make_ext(ArenaPtr arena, Int id, lang_rt::TokenBounds bounds, bool is_top, lang_rt::ParserSymId sym, lang_rt::ParserAttrMask attr, lang_rt::ParserLookahead first_k);
}

namespace lang::meta::Node::ParseExpr::Dedent {
    struct _T: lang::meta::Node::ParseExpr::_T {
        void write(ostream& os, FmtFlags flags);
        _T();
        lang::meta::Node::ParseExpr::Dedent_T with_id(Int id);
        lang::meta::Node::ParseExpr::Dedent_T with_bounds(lang_rt::TokenBounds bounds);
        lang::meta::Node::ParseExpr::Dedent_T with_is_top(bool is_top);
        lang::meta::Node::ParseExpr::Dedent_T with_sym(lang_rt::ParserSymId sym);
        lang::meta::Node::ParseExpr::Dedent_T with_attr(lang_rt::ParserAttrMask attr);
        lang::meta::Node::ParseExpr::Dedent_T with_first_k(lang_rt::ParserLookahead first_k);
        void hash_ser_acc_lang_meta_Node_ParseExpr_Dedent(SerBuf& buf) const;
        virtual void hash_ser_acc(SerBuf& buf) const;
    };
}

void pr_debug(ostream& os, FmtFlags flags, lang::meta::Node::ParseExpr::Newline_T x);

namespace lang::meta::Node::ParseExpr::Newline {
    __attribute__((always_inline)) lang::meta::Node::ParseExpr::Newline_T make(Int id, lang_rt::TokenBounds bounds, bool is_top, lang_rt::ParserSymId sym, lang_rt::ParserAttrMask attr, lang_rt::ParserLookahead first_k);
}

namespace lang::meta::Node::ParseExpr::Newline {
    __attribute__((always_inline)) lang::meta::Node::ParseExpr::Newline_T make_ext(ArenaPtr arena, Int id, lang_rt::TokenBounds bounds, bool is_top, lang_rt::ParserSymId sym, lang_rt::ParserAttrMask attr, lang_rt::ParserLookahead first_k);
}

namespace lang::meta::Node::ParseExpr::Newline {
    struct _T: lang::meta::Node::ParseExpr::_T {
        void write(ostream& os, FmtFlags flags);
        _T();
        lang::meta::Node::ParseExpr::Newline_T with_id(Int id);
        lang::meta::Node::ParseExpr::Newline_T with_bounds(lang_rt::TokenBounds bounds);
        lang::meta::Node::ParseExpr::Newline_T with_is_top(bool is_top);
        lang::meta::Node::ParseExpr::Newline_T with_sym(lang_rt::ParserSymId sym);
        lang::meta::Node::ParseExpr::Newline_T with_attr(lang_rt::ParserAttrMask attr);
        lang::meta::Node::ParseExpr::Newline_T with_first_k(lang_rt::ParserLookahead first_k);
        void hash_ser_acc_lang_meta_Node_ParseExpr_Newline(SerBuf& buf) const;
        virtual void hash_ser_acc(SerBuf& buf) const;
    };
}

void pr_debug(ostream& os, FmtFlags flags, lang::meta::Node::ParseExpr::UnicodeAny_T x);

namespace lang::meta::Node::ParseExpr::UnicodeAny {
    __attribute__((always_inline)) lang::meta::Node::ParseExpr::UnicodeAny_T make(Int id, lang_rt::TokenBounds bounds, bool is_top, lang_rt::ParserSymId sym, lang_rt::ParserAttrMask attr, lang_rt::ParserLookahead first_k);
}

namespace lang::meta::Node::ParseExpr::UnicodeAny {
    __attribute__((always_inline)) lang::meta::Node::ParseExpr::UnicodeAny_T make_ext(ArenaPtr arena, Int id, lang_rt::TokenBounds bounds, bool is_top, lang_rt::ParserSymId sym, lang_rt::ParserAttrMask attr, lang_rt::ParserLookahead first_k);
}

namespace lang::meta::Node::ParseExpr::UnicodeAny {
    struct _T: lang::meta::Node::ParseExpr::_T {
        void write(ostream& os, FmtFlags flags);
        _T();
        lang::meta::Node::ParseExpr::UnicodeAny_T with_id(Int id);
        lang::meta::Node::ParseExpr::UnicodeAny_T with_bounds(lang_rt::TokenBounds bounds);
        lang::meta::Node::ParseExpr::UnicodeAny_T with_is_top(bool is_top);
        lang::meta::Node::ParseExpr::UnicodeAny_T with_sym(lang_rt::ParserSymId sym);
        lang::meta::Node::ParseExpr::UnicodeAny_T with_attr(lang_rt::ParserAttrMask attr);
        lang::meta::Node::ParseExpr::UnicodeAny_T with_first_k(lang_rt::ParserLookahead first_k);
        void hash_ser_acc_lang_meta_Node_ParseExpr_UnicodeAny(SerBuf& buf) const;
        virtual void hash_ser_acc(SerBuf& buf) const;
    };
}

void pr_debug(ostream& os, FmtFlags flags, lang::meta::Node::ParseExpr::AsciiBaseAny_T x);

namespace lang::meta::Node::ParseExpr::AsciiBaseAny {
    __attribute__((always_inline)) lang::meta::Node::ParseExpr::AsciiBaseAny_T make(Int id, lang_rt::TokenBounds bounds, bool is_top, lang_rt::ParserSymId sym, lang_rt::ParserAttrMask attr, lang_rt::ParserLookahead first_k);
}

namespace lang::meta::Node::ParseExpr::AsciiBaseAny {
    __attribute__((always_inline)) lang::meta::Node::ParseExpr::AsciiBaseAny_T make_ext(ArenaPtr arena, Int id, lang_rt::TokenBounds bounds, bool is_top, lang_rt::ParserSymId sym, lang_rt::ParserAttrMask attr, lang_rt::ParserLookahead first_k);
}

namespace lang::meta::Node::ParseExpr::AsciiBaseAny {
    struct _T: lang::meta::Node::ParseExpr::_T {
        void write(ostream& os, FmtFlags flags);
        _T();
        lang::meta::Node::ParseExpr::AsciiBaseAny_T with_id(Int id);
        lang::meta::Node::ParseExpr::AsciiBaseAny_T with_bounds(lang_rt::TokenBounds bounds);
        lang::meta::Node::ParseExpr::AsciiBaseAny_T with_is_top(bool is_top);
        lang::meta::Node::ParseExpr::AsciiBaseAny_T with_sym(lang_rt::ParserSymId sym);
        lang::meta::Node::ParseExpr::AsciiBaseAny_T with_attr(lang_rt::ParserAttrMask attr);
        lang::meta::Node::ParseExpr::AsciiBaseAny_T with_first_k(lang_rt::ParserLookahead first_k);
        void hash_ser_acc_lang_meta_Node_ParseExpr_AsciiBaseAny(SerBuf& buf) const;
        virtual void hash_ser_acc(SerBuf& buf) const;
    };
}

void pr_debug(ostream& os, FmtFlags flags, lang::meta::Node::ParseExpr::Alt_T x);

namespace lang::meta::Node::ParseExpr::Alt {
    __attribute__((always_inline)) lang::meta::Node::ParseExpr::Alt_T make(Int id, lang_rt::TokenBounds bounds, bool is_top, lang_rt::ParserSymId sym, lang_rt::ParserAttrMask attr, lang_rt::ParserLookahead first_k, Vec_T<lang::meta::Node::ParseExpr_T> xs);
}

namespace lang::meta::Node::ParseExpr::Alt {
    __attribute__((always_inline)) lang::meta::Node::ParseExpr::Alt_T make_ext(ArenaPtr arena, Int id, lang_rt::TokenBounds bounds, bool is_top, lang_rt::ParserSymId sym, lang_rt::ParserAttrMask attr, lang_rt::ParserLookahead first_k, Vec_T<lang::meta::Node::ParseExpr_T> xs);
}

namespace lang::meta::Node::ParseExpr::Alt {
    struct _T: lang::meta::Node::ParseExpr::_T {
        void write(ostream& os, FmtFlags flags);
        Vec_T<lang::meta::Node::ParseExpr_T> xs_;
        _T();
        lang::meta::Node::ParseExpr::Alt_T with_id(Int id);
        lang::meta::Node::ParseExpr::Alt_T with_bounds(lang_rt::TokenBounds bounds);
        lang::meta::Node::ParseExpr::Alt_T with_is_top(bool is_top);
        lang::meta::Node::ParseExpr::Alt_T with_sym(lang_rt::ParserSymId sym);
        lang::meta::Node::ParseExpr::Alt_T with_attr(lang_rt::ParserAttrMask attr);
        lang::meta::Node::ParseExpr::Alt_T with_first_k(lang_rt::ParserLookahead first_k);
        lang::meta::Node::ParseExpr::Alt_T with_xs(Vec_T<lang::meta::Node::ParseExpr_T> xs);
        void hash_ser_acc_lang_meta_Node_ParseExpr_Alt(SerBuf& buf) const;
        virtual void hash_ser_acc(SerBuf& buf) const;
    };
}

void pr_debug(ostream& os, FmtFlags flags, lang::meta::Node::ParseExpr::AltExplicit_T x);

namespace lang::meta::Node::ParseExpr::AltExplicit {
    __attribute__((always_inline)) lang::meta::Node::ParseExpr::AltExplicit_T make(Int id, lang_rt::TokenBounds bounds, bool is_top, lang_rt::ParserSymId sym, lang_rt::ParserAttrMask attr, lang_rt::ParserLookahead first_k, lang::meta::Node::ParseExpr_T e);
}

namespace lang::meta::Node::ParseExpr::AltExplicit {
    __attribute__((always_inline)) lang::meta::Node::ParseExpr::AltExplicit_T make_ext(ArenaPtr arena, Int id, lang_rt::TokenBounds bounds, bool is_top, lang_rt::ParserSymId sym, lang_rt::ParserAttrMask attr, lang_rt::ParserLookahead first_k, lang::meta::Node::ParseExpr_T e);
}

namespace lang::meta::Node::ParseExpr::AltExplicit {
    struct _T: lang::meta::Node::ParseExpr::_T {
        void write(ostream& os, FmtFlags flags);
        lang::meta::Node::ParseExpr_T e_;
        _T();
        lang::meta::Node::ParseExpr::AltExplicit_T with_id(Int id);
        lang::meta::Node::ParseExpr::AltExplicit_T with_bounds(lang_rt::TokenBounds bounds);
        lang::meta::Node::ParseExpr::AltExplicit_T with_is_top(bool is_top);
        lang::meta::Node::ParseExpr::AltExplicit_T with_sym(lang_rt::ParserSymId sym);
        lang::meta::Node::ParseExpr::AltExplicit_T with_attr(lang_rt::ParserAttrMask attr);
        lang::meta::Node::ParseExpr::AltExplicit_T with_first_k(lang_rt::ParserLookahead first_k);
        lang::meta::Node::ParseExpr::AltExplicit_T with_e(lang::meta::Node::ParseExpr_T e);
        void hash_ser_acc_lang_meta_Node_ParseExpr_AltExplicit(SerBuf& buf) const;
        virtual void hash_ser_acc(SerBuf& buf) const;
    };
}

void pr_debug(ostream& os, FmtFlags flags, lang::meta::Node::ParseExpr::Minus_T x);

namespace lang::meta::Node::ParseExpr::Minus {
    __attribute__((always_inline)) lang::meta::Node::ParseExpr::Minus_T make(Int id, lang_rt::TokenBounds bounds, bool is_top, lang_rt::ParserSymId sym, lang_rt::ParserAttrMask attr, lang_rt::ParserLookahead first_k, lang::meta::Node::ParseExpr_T x, lang::meta::Node::ParseExpr_T y);
}

namespace lang::meta::Node::ParseExpr::Minus {
    __attribute__((always_inline)) lang::meta::Node::ParseExpr::Minus_T make_ext(ArenaPtr arena, Int id, lang_rt::TokenBounds bounds, bool is_top, lang_rt::ParserSymId sym, lang_rt::ParserAttrMask attr, lang_rt::ParserLookahead first_k, lang::meta::Node::ParseExpr_T x, lang::meta::Node::ParseExpr_T y);
}

namespace lang::meta::Node::ParseExpr::Minus {
    struct _T: lang::meta::Node::ParseExpr::_T {
        void write(ostream& os, FmtFlags flags);
        lang::meta::Node::ParseExpr_T x_;
        lang::meta::Node::ParseExpr_T y_;
        _T();
        lang::meta::Node::ParseExpr::Minus_T with_id(Int id);
        lang::meta::Node::ParseExpr::Minus_T with_bounds(lang_rt::TokenBounds bounds);
        lang::meta::Node::ParseExpr::Minus_T with_is_top(bool is_top);
        lang::meta::Node::ParseExpr::Minus_T with_sym(lang_rt::ParserSymId sym);
        lang::meta::Node::ParseExpr::Minus_T with_attr(lang_rt::ParserAttrMask attr);
        lang::meta::Node::ParseExpr::Minus_T with_first_k(lang_rt::ParserLookahead first_k);
        lang::meta::Node::ParseExpr::Minus_T with_x(lang::meta::Node::ParseExpr_T x);
        lang::meta::Node::ParseExpr::Minus_T with_y(lang::meta::Node::ParseExpr_T y);
        void hash_ser_acc_lang_meta_Node_ParseExpr_Minus(SerBuf& buf) const;
        virtual void hash_ser_acc(SerBuf& buf) const;
    };
}

void pr_debug(ostream& os, FmtFlags flags, lang::meta::Node::ParseExpr::Concat_T x);

namespace lang::meta::Node::ParseExpr::Concat {
    __attribute__((always_inline)) lang::meta::Node::ParseExpr::Concat_T make(Int id, lang_rt::TokenBounds bounds, bool is_top, lang_rt::ParserSymId sym, lang_rt::ParserAttrMask attr, lang_rt::ParserLookahead first_k, Vec_T<lang::meta::Node::ParseExpr_T> xs);
}

namespace lang::meta::Node::ParseExpr::Concat {
    __attribute__((always_inline)) lang::meta::Node::ParseExpr::Concat_T make_ext(ArenaPtr arena, Int id, lang_rt::TokenBounds bounds, bool is_top, lang_rt::ParserSymId sym, lang_rt::ParserAttrMask attr, lang_rt::ParserLookahead first_k, Vec_T<lang::meta::Node::ParseExpr_T> xs);
}

namespace lang::meta::Node::ParseExpr::Concat {
    struct _T: lang::meta::Node::ParseExpr::_T {
        void write(ostream& os, FmtFlags flags);
        Vec_T<lang::meta::Node::ParseExpr_T> xs_;
        _T();
        lang::meta::Node::ParseExpr::Concat_T with_id(Int id);
        lang::meta::Node::ParseExpr::Concat_T with_bounds(lang_rt::TokenBounds bounds);
        lang::meta::Node::ParseExpr::Concat_T with_is_top(bool is_top);
        lang::meta::Node::ParseExpr::Concat_T with_sym(lang_rt::ParserSymId sym);
        lang::meta::Node::ParseExpr::Concat_T with_attr(lang_rt::ParserAttrMask attr);
        lang::meta::Node::ParseExpr::Concat_T with_first_k(lang_rt::ParserLookahead first_k);
        lang::meta::Node::ParseExpr::Concat_T with_xs(Vec_T<lang::meta::Node::ParseExpr_T> xs);
        void hash_ser_acc_lang_meta_Node_ParseExpr_Concat(SerBuf& buf) const;
        virtual void hash_ser_acc(SerBuf& buf) const;
    };
}

void pr_debug(ostream& os, FmtFlags flags, lang::meta::Node::ParseExpr::Optional_T x);

namespace lang::meta::Node::ParseExpr::Optional {
    __attribute__((always_inline)) lang::meta::Node::ParseExpr::Optional_T make(Int id, lang_rt::TokenBounds bounds, bool is_top, lang_rt::ParserSymId sym, lang_rt::ParserAttrMask attr, lang_rt::ParserLookahead first_k, lang::meta::Node::ParseExpr_T x);
}

namespace lang::meta::Node::ParseExpr::Optional {
    __attribute__((always_inline)) lang::meta::Node::ParseExpr::Optional_T make_ext(ArenaPtr arena, Int id, lang_rt::TokenBounds bounds, bool is_top, lang_rt::ParserSymId sym, lang_rt::ParserAttrMask attr, lang_rt::ParserLookahead first_k, lang::meta::Node::ParseExpr_T x);
}

namespace lang::meta::Node::ParseExpr::Optional {
    struct _T: lang::meta::Node::ParseExpr::_T {
        void write(ostream& os, FmtFlags flags);
        lang::meta::Node::ParseExpr_T x_;
        _T();
        lang::meta::Node::ParseExpr::Optional_T with_id(Int id);
        lang::meta::Node::ParseExpr::Optional_T with_bounds(lang_rt::TokenBounds bounds);
        lang::meta::Node::ParseExpr::Optional_T with_is_top(bool is_top);
        lang::meta::Node::ParseExpr::Optional_T with_sym(lang_rt::ParserSymId sym);
        lang::meta::Node::ParseExpr::Optional_T with_attr(lang_rt::ParserAttrMask attr);
        lang::meta::Node::ParseExpr::Optional_T with_first_k(lang_rt::ParserLookahead first_k);
        lang::meta::Node::ParseExpr::Optional_T with_x(lang::meta::Node::ParseExpr_T x);
        void hash_ser_acc_lang_meta_Node_ParseExpr_Optional(SerBuf& buf) const;
        virtual void hash_ser_acc(SerBuf& buf) const;
    };
}

void pr_debug(ostream& os, FmtFlags flags, lang::meta::Node::ParseExpr::Rep_T x);

namespace lang::meta::Node::ParseExpr::Rep {
    __attribute__((always_inline)) lang::meta::Node::ParseExpr::Rep_T make(Int id, lang_rt::TokenBounds bounds, bool is_top, lang_rt::ParserSymId sym, lang_rt::ParserAttrMask attr, lang_rt::ParserLookahead first_k, lang::meta::Node::ParseExpr_T x);
}

namespace lang::meta::Node::ParseExpr::Rep {
    __attribute__((always_inline)) lang::meta::Node::ParseExpr::Rep_T make_ext(ArenaPtr arena, Int id, lang_rt::TokenBounds bounds, bool is_top, lang_rt::ParserSymId sym, lang_rt::ParserAttrMask attr, lang_rt::ParserLookahead first_k, lang::meta::Node::ParseExpr_T x);
}

namespace lang::meta::Node::ParseExpr::Rep {
    struct _T: lang::meta::Node::ParseExpr::_T {
        void write(ostream& os, FmtFlags flags);
        lang::meta::Node::ParseExpr_T x_;
        _T();
        lang::meta::Node::ParseExpr::Rep_T with_id(Int id);
        lang::meta::Node::ParseExpr::Rep_T with_bounds(lang_rt::TokenBounds bounds);
        lang::meta::Node::ParseExpr::Rep_T with_is_top(bool is_top);
        lang::meta::Node::ParseExpr::Rep_T with_sym(lang_rt::ParserSymId sym);
        lang::meta::Node::ParseExpr::Rep_T with_attr(lang_rt::ParserAttrMask attr);
        lang::meta::Node::ParseExpr::Rep_T with_first_k(lang_rt::ParserLookahead first_k);
        lang::meta::Node::ParseExpr::Rep_T with_x(lang::meta::Node::ParseExpr_T x);
        void hash_ser_acc_lang_meta_Node_ParseExpr_Rep(SerBuf& buf) const;
        virtual void hash_ser_acc(SerBuf& buf) const;
    };
}

void pr_debug(ostream& os, FmtFlags flags, lang::meta::Node::ParseExpr::RepNonzero_T x);

namespace lang::meta::Node::ParseExpr::RepNonzero {
    __attribute__((always_inline)) lang::meta::Node::ParseExpr::RepNonzero_T make(Int id, lang_rt::TokenBounds bounds, bool is_top, lang_rt::ParserSymId sym, lang_rt::ParserAttrMask attr, lang_rt::ParserLookahead first_k, lang::meta::Node::ParseExpr_T x);
}

namespace lang::meta::Node::ParseExpr::RepNonzero {
    __attribute__((always_inline)) lang::meta::Node::ParseExpr::RepNonzero_T make_ext(ArenaPtr arena, Int id, lang_rt::TokenBounds bounds, bool is_top, lang_rt::ParserSymId sym, lang_rt::ParserAttrMask attr, lang_rt::ParserLookahead first_k, lang::meta::Node::ParseExpr_T x);
}

namespace lang::meta::Node::ParseExpr::RepNonzero {
    struct _T: lang::meta::Node::ParseExpr::_T {
        void write(ostream& os, FmtFlags flags);
        lang::meta::Node::ParseExpr_T x_;
        _T();
        lang::meta::Node::ParseExpr::RepNonzero_T with_id(Int id);
        lang::meta::Node::ParseExpr::RepNonzero_T with_bounds(lang_rt::TokenBounds bounds);
        lang::meta::Node::ParseExpr::RepNonzero_T with_is_top(bool is_top);
        lang::meta::Node::ParseExpr::RepNonzero_T with_sym(lang_rt::ParserSymId sym);
        lang::meta::Node::ParseExpr::RepNonzero_T with_attr(lang_rt::ParserAttrMask attr);
        lang::meta::Node::ParseExpr::RepNonzero_T with_first_k(lang_rt::ParserLookahead first_k);
        lang::meta::Node::ParseExpr::RepNonzero_T with_x(lang::meta::Node::ParseExpr_T x);
        void hash_ser_acc_lang_meta_Node_ParseExpr_RepNonzero(SerBuf& buf) const;
        virtual void hash_ser_acc(SerBuf& buf) const;
    };
}

void pr_debug(ostream& os, FmtFlags flags, lang::meta::Node::ParseExpr::RepCount_T x);

namespace lang::meta::Node::ParseExpr::RepCount {
    __attribute__((always_inline)) lang::meta::Node::ParseExpr::RepCount_T make(Int id, lang_rt::TokenBounds bounds, bool is_top, lang_rt::ParserSymId sym, lang_rt::ParserAttrMask attr, lang_rt::ParserLookahead first_k, lang::meta::Node::ParseExpr_T x, StrSlice count);
}

namespace lang::meta::Node::ParseExpr::RepCount {
    __attribute__((always_inline)) lang::meta::Node::ParseExpr::RepCount_T make_ext(ArenaPtr arena, Int id, lang_rt::TokenBounds bounds, bool is_top, lang_rt::ParserSymId sym, lang_rt::ParserAttrMask attr, lang_rt::ParserLookahead first_k, lang::meta::Node::ParseExpr_T x, StrSlice count);
}

namespace lang::meta::Node::ParseExpr::RepCount {
    struct _T: lang::meta::Node::ParseExpr::_T {
        void write(ostream& os, FmtFlags flags);
        lang::meta::Node::ParseExpr_T x_;
        StrSlice count_;
        _T();
        lang::meta::Node::ParseExpr::RepCount_T with_id(Int id);
        lang::meta::Node::ParseExpr::RepCount_T with_bounds(lang_rt::TokenBounds bounds);
        lang::meta::Node::ParseExpr::RepCount_T with_is_top(bool is_top);
        lang::meta::Node::ParseExpr::RepCount_T with_sym(lang_rt::ParserSymId sym);
        lang::meta::Node::ParseExpr::RepCount_T with_attr(lang_rt::ParserAttrMask attr);
        lang::meta::Node::ParseExpr::RepCount_T with_first_k(lang_rt::ParserLookahead first_k);
        lang::meta::Node::ParseExpr::RepCount_T with_x(lang::meta::Node::ParseExpr_T x);
        lang::meta::Node::ParseExpr::RepCount_T with_count(StrSlice count);
        void hash_ser_acc_lang_meta_Node_ParseExpr_RepCount(SerBuf& buf) const;
        virtual void hash_ser_acc(SerBuf& buf) const;
    };
}

void pr_debug(ostream& os, FmtFlags flags, lang::meta::Node::ParseExpr::CharRange_T x);

namespace lang::meta::Node::ParseExpr::CharRange {
    __attribute__((always_inline)) lang::meta::Node::ParseExpr::CharRange_T make(Int id, lang_rt::TokenBounds bounds, bool is_top, lang_rt::ParserSymId sym, lang_rt::ParserAttrMask attr, lang_rt::ParserLookahead first_k, StrSlice min_, StrSlice max_);
}

namespace lang::meta::Node::ParseExpr::CharRange {
    __attribute__((always_inline)) lang::meta::Node::ParseExpr::CharRange_T make_ext(ArenaPtr arena, Int id, lang_rt::TokenBounds bounds, bool is_top, lang_rt::ParserSymId sym, lang_rt::ParserAttrMask attr, lang_rt::ParserLookahead first_k, StrSlice min_, StrSlice max_);
}

namespace lang::meta::Node::ParseExpr::CharRange {
    struct _T: lang::meta::Node::ParseExpr::_T {
        void write(ostream& os, FmtFlags flags);
        StrSlice min__;
        StrSlice max__;
        _T();
        lang::meta::Node::ParseExpr::CharRange_T with_id(Int id);
        lang::meta::Node::ParseExpr::CharRange_T with_bounds(lang_rt::TokenBounds bounds);
        lang::meta::Node::ParseExpr::CharRange_T with_is_top(bool is_top);
        lang::meta::Node::ParseExpr::CharRange_T with_sym(lang_rt::ParserSymId sym);
        lang::meta::Node::ParseExpr::CharRange_T with_attr(lang_rt::ParserAttrMask attr);
        lang::meta::Node::ParseExpr::CharRange_T with_first_k(lang_rt::ParserLookahead first_k);
        lang::meta::Node::ParseExpr::CharRange_T with_min_(StrSlice min_);
        lang::meta::Node::ParseExpr::CharRange_T with_max_(StrSlice max_);
        void hash_ser_acc_lang_meta_Node_ParseExpr_CharRange(SerBuf& buf) const;
        virtual void hash_ser_acc(SerBuf& buf) const;
    };
}

void pr_debug(ostream& os, FmtFlags flags, lang::meta::Node::ParseExpr::StrLit_T x);

namespace lang::meta::Node::ParseExpr::StrLit {
    __attribute__((always_inline)) lang::meta::Node::ParseExpr::StrLit_T make(Int id, lang_rt::TokenBounds bounds, bool is_top, lang_rt::ParserSymId sym, lang_rt::ParserAttrMask attr, lang_rt::ParserLookahead first_k, StrSlice s);
}

namespace lang::meta::Node::ParseExpr::StrLit {
    __attribute__((always_inline)) lang::meta::Node::ParseExpr::StrLit_T make_ext(ArenaPtr arena, Int id, lang_rt::TokenBounds bounds, bool is_top, lang_rt::ParserSymId sym, lang_rt::ParserAttrMask attr, lang_rt::ParserLookahead first_k, StrSlice s);
}

namespace lang::meta::Node::ParseExpr::StrLit {
    struct _T: lang::meta::Node::ParseExpr::_T {
        void write(ostream& os, FmtFlags flags);
        StrSlice s_;
        _T();
        lang::meta::Node::ParseExpr::StrLit_T with_id(Int id);
        lang::meta::Node::ParseExpr::StrLit_T with_bounds(lang_rt::TokenBounds bounds);
        lang::meta::Node::ParseExpr::StrLit_T with_is_top(bool is_top);
        lang::meta::Node::ParseExpr::StrLit_T with_sym(lang_rt::ParserSymId sym);
        lang::meta::Node::ParseExpr::StrLit_T with_attr(lang_rt::ParserAttrMask attr);
        lang::meta::Node::ParseExpr::StrLit_T with_first_k(lang_rt::ParserLookahead first_k);
        lang::meta::Node::ParseExpr::StrLit_T with_s(StrSlice s);
        void hash_ser_acc_lang_meta_Node_ParseExpr_StrLit(SerBuf& buf) const;
        virtual void hash_ser_acc(SerBuf& buf) const;
    };
}

void pr_debug(ostream& os, FmtFlags flags, lang::meta::Node::ParseExpr::Underscore_T x);

namespace lang::meta::Node::ParseExpr::Underscore {
    __attribute__((always_inline)) lang::meta::Node::ParseExpr::Underscore_T make(Int id, lang_rt::TokenBounds bounds, bool is_top, lang_rt::ParserSymId sym, lang_rt::ParserAttrMask attr, lang_rt::ParserLookahead first_k);
}

namespace lang::meta::Node::ParseExpr::Underscore {
    __attribute__((always_inline)) lang::meta::Node::ParseExpr::Underscore_T make_ext(ArenaPtr arena, Int id, lang_rt::TokenBounds bounds, bool is_top, lang_rt::ParserSymId sym, lang_rt::ParserAttrMask attr, lang_rt::ParserLookahead first_k);
}

namespace lang::meta::Node::ParseExpr::Underscore {
    struct _T: lang::meta::Node::ParseExpr::_T {
        void write(ostream& os, FmtFlags flags);
        _T();
        lang::meta::Node::ParseExpr::Underscore_T with_id(Int id);
        lang::meta::Node::ParseExpr::Underscore_T with_bounds(lang_rt::TokenBounds bounds);
        lang::meta::Node::ParseExpr::Underscore_T with_is_top(bool is_top);
        lang::meta::Node::ParseExpr::Underscore_T with_sym(lang_rt::ParserSymId sym);
        lang::meta::Node::ParseExpr::Underscore_T with_attr(lang_rt::ParserAttrMask attr);
        lang::meta::Node::ParseExpr::Underscore_T with_first_k(lang_rt::ParserLookahead first_k);
        void hash_ser_acc_lang_meta_Node_ParseExpr_Underscore(SerBuf& buf) const;
        virtual void hash_ser_acc(SerBuf& buf) const;
    };
}

void pr_debug(ostream& os, FmtFlags flags, lang::meta::Node::ParseExpr::Pass_T x);

namespace lang::meta::Node::ParseExpr::Pass {
    __attribute__((always_inline)) lang::meta::Node::ParseExpr::Pass_T make(Int id, lang_rt::TokenBounds bounds, bool is_top, lang_rt::ParserSymId sym, lang_rt::ParserAttrMask attr, lang_rt::ParserLookahead first_k, StrSlice s);
}

namespace lang::meta::Node::ParseExpr::Pass {
    __attribute__((always_inline)) lang::meta::Node::ParseExpr::Pass_T make_ext(ArenaPtr arena, Int id, lang_rt::TokenBounds bounds, bool is_top, lang_rt::ParserSymId sym, lang_rt::ParserAttrMask attr, lang_rt::ParserLookahead first_k, StrSlice s);
}

namespace lang::meta::Node::ParseExpr::Pass {
    struct _T: lang::meta::Node::ParseExpr::_T {
        void write(ostream& os, FmtFlags flags);
        StrSlice s_;
        _T();
        lang::meta::Node::ParseExpr::Pass_T with_id(Int id);
        lang::meta::Node::ParseExpr::Pass_T with_bounds(lang_rt::TokenBounds bounds);
        lang::meta::Node::ParseExpr::Pass_T with_is_top(bool is_top);
        lang::meta::Node::ParseExpr::Pass_T with_sym(lang_rt::ParserSymId sym);
        lang::meta::Node::ParseExpr::Pass_T with_attr(lang_rt::ParserAttrMask attr);
        lang::meta::Node::ParseExpr::Pass_T with_first_k(lang_rt::ParserLookahead first_k);
        lang::meta::Node::ParseExpr::Pass_T with_s(StrSlice s);
        void hash_ser_acc_lang_meta_Node_ParseExpr_Pass(SerBuf& buf) const;
        virtual void hash_ser_acc(SerBuf& buf) const;
    };
}

void pr_debug(ostream& os, FmtFlags flags, lang::meta::Node::ParseExpr::Paren_T x);

namespace lang::meta::Node::ParseExpr::Paren {
    __attribute__((always_inline)) lang::meta::Node::ParseExpr::Paren_T make(Int id, lang_rt::TokenBounds bounds, bool is_top, lang_rt::ParserSymId sym, lang_rt::ParserAttrMask attr, lang_rt::ParserLookahead first_k, lang::meta::Node::ParseExpr_T x);
}

namespace lang::meta::Node::ParseExpr::Paren {
    __attribute__((always_inline)) lang::meta::Node::ParseExpr::Paren_T make_ext(ArenaPtr arena, Int id, lang_rt::TokenBounds bounds, bool is_top, lang_rt::ParserSymId sym, lang_rt::ParserAttrMask attr, lang_rt::ParserLookahead first_k, lang::meta::Node::ParseExpr_T x);
}

namespace lang::meta::Node::ParseExpr::Paren {
    struct _T: lang::meta::Node::ParseExpr::_T {
        void write(ostream& os, FmtFlags flags);
        lang::meta::Node::ParseExpr_T x_;
        _T();
        lang::meta::Node::ParseExpr::Paren_T with_id(Int id);
        lang::meta::Node::ParseExpr::Paren_T with_bounds(lang_rt::TokenBounds bounds);
        lang::meta::Node::ParseExpr::Paren_T with_is_top(bool is_top);
        lang::meta::Node::ParseExpr::Paren_T with_sym(lang_rt::ParserSymId sym);
        lang::meta::Node::ParseExpr::Paren_T with_attr(lang_rt::ParserAttrMask attr);
        lang::meta::Node::ParseExpr::Paren_T with_first_k(lang_rt::ParserLookahead first_k);
        lang::meta::Node::ParseExpr::Paren_T with_x(lang::meta::Node::ParseExpr_T x);
        void hash_ser_acc_lang_meta_Node_ParseExpr_Paren(SerBuf& buf) const;
        virtual void hash_ser_acc(SerBuf& buf) const;
    };
}

void pr_debug(ostream& os, FmtFlags flags, lang::meta::Node::ParseExpr::Name_T x);

namespace lang::meta::Node::ParseExpr::Name {
    __attribute__((always_inline)) lang::meta::Node::ParseExpr::Name_T make(Int id, lang_rt::TokenBounds bounds, bool is_top, lang_rt::ParserSymId sym, lang_rt::ParserAttrMask attr, lang_rt::ParserLookahead first_k, StrSlice name, lang::meta::Node::ParseExpr_T e);
}

namespace lang::meta::Node::ParseExpr::Name {
    __attribute__((always_inline)) lang::meta::Node::ParseExpr::Name_T make_ext(ArenaPtr arena, Int id, lang_rt::TokenBounds bounds, bool is_top, lang_rt::ParserSymId sym, lang_rt::ParserAttrMask attr, lang_rt::ParserLookahead first_k, StrSlice name, lang::meta::Node::ParseExpr_T e);
}

namespace lang::meta::Node::ParseExpr::Name {
    struct _T: lang::meta::Node::ParseExpr::_T {
        void write(ostream& os, FmtFlags flags);
        StrSlice name_;
        lang::meta::Node::ParseExpr_T e_;
        _T();
        lang::meta::Node::ParseExpr::Name_T with_id(Int id);
        lang::meta::Node::ParseExpr::Name_T with_bounds(lang_rt::TokenBounds bounds);
        lang::meta::Node::ParseExpr::Name_T with_is_top(bool is_top);
        lang::meta::Node::ParseExpr::Name_T with_sym(lang_rt::ParserSymId sym);
        lang::meta::Node::ParseExpr::Name_T with_attr(lang_rt::ParserAttrMask attr);
        lang::meta::Node::ParseExpr::Name_T with_first_k(lang_rt::ParserLookahead first_k);
        lang::meta::Node::ParseExpr::Name_T with_name(StrSlice name);
        lang::meta::Node::ParseExpr::Name_T with_e(lang::meta::Node::ParseExpr_T e);
        void hash_ser_acc_lang_meta_Node_ParseExpr_Name(SerBuf& buf) const;
        virtual void hash_ser_acc(SerBuf& buf) const;
    };
}

void pr_debug(ostream& os, FmtFlags flags, lang::meta::Node::ParseExpr::List_T x);

namespace lang::meta::Node::ParseExpr::List {
    __attribute__((always_inline)) lang::meta::Node::ParseExpr::List_T make(Int id, lang_rt::TokenBounds bounds, bool is_top, lang_rt::ParserSymId sym, lang_rt::ParserAttrMask attr, lang_rt::ParserLookahead first_k, lang::meta::Node::ParseExprListType_T ty, lang::meta::Node::ParseExpr_T elem, lang::meta::Node::ParseExprListNum_T num, lang::meta::Node::ParseExpr_T delim, lang::meta::Node::ParseExpr::List::end_delim_T end_delim);
}

namespace lang::meta::Node::ParseExpr::List {
    __attribute__((always_inline)) lang::meta::Node::ParseExpr::List_T make_ext(ArenaPtr arena, Int id, lang_rt::TokenBounds bounds, bool is_top, lang_rt::ParserSymId sym, lang_rt::ParserAttrMask attr, lang_rt::ParserLookahead first_k, lang::meta::Node::ParseExprListType_T ty, lang::meta::Node::ParseExpr_T elem, lang::meta::Node::ParseExprListNum_T num, lang::meta::Node::ParseExpr_T delim, lang::meta::Node::ParseExpr::List::end_delim_T end_delim);
}

namespace lang::meta::Node::ParseExpr::List {
    struct _T: lang::meta::Node::ParseExpr::_T {
        void write(ostream& os, FmtFlags flags);
        lang::meta::Node::ParseExprListType_T ty_;
        lang::meta::Node::ParseExpr_T elem_;
        lang::meta::Node::ParseExprListNum_T num_;
        lang::meta::Node::ParseExpr_T delim_;
        lang::meta::Node::ParseExpr::List::end_delim_T end_delim_;
        _T();
        lang::meta::Node::ParseExpr::List_T with_id(Int id);
        lang::meta::Node::ParseExpr::List_T with_bounds(lang_rt::TokenBounds bounds);
        lang::meta::Node::ParseExpr::List_T with_is_top(bool is_top);
        lang::meta::Node::ParseExpr::List_T with_sym(lang_rt::ParserSymId sym);
        lang::meta::Node::ParseExpr::List_T with_attr(lang_rt::ParserAttrMask attr);
        lang::meta::Node::ParseExpr::List_T with_first_k(lang_rt::ParserLookahead first_k);
        lang::meta::Node::ParseExpr::List_T with_ty(lang::meta::Node::ParseExprListType_T ty);
        lang::meta::Node::ParseExpr::List_T with_elem(lang::meta::Node::ParseExpr_T elem);
        lang::meta::Node::ParseExpr::List_T with_num(lang::meta::Node::ParseExprListNum_T num);
        lang::meta::Node::ParseExpr::List_T with_delim(lang::meta::Node::ParseExpr_T delim);
        lang::meta::Node::ParseExpr::List_T with_end_delim(lang::meta::Node::ParseExpr::List::end_delim_T end_delim);
        void hash_ser_acc_lang_meta_Node_ParseExpr_List(SerBuf& buf) const;
        virtual void hash_ser_acc(SerBuf& buf) const;
    };
}

void pr_debug(ostream& os, FmtFlags flags, lang::meta::Node::ParseExpr::Unfold_T x);

namespace lang::meta::Node::ParseExpr::Unfold {
    __attribute__((always_inline)) lang::meta::Node::ParseExpr::Unfold_T make(Int id, lang_rt::TokenBounds bounds, bool is_top, lang_rt::ParserSymId sym, lang_rt::ParserAttrMask attr, lang_rt::ParserLookahead first_k, lang::meta::Node::ParseExpr_T e);
}

namespace lang::meta::Node::ParseExpr::Unfold {
    __attribute__((always_inline)) lang::meta::Node::ParseExpr::Unfold_T make_ext(ArenaPtr arena, Int id, lang_rt::TokenBounds bounds, bool is_top, lang_rt::ParserSymId sym, lang_rt::ParserAttrMask attr, lang_rt::ParserLookahead first_k, lang::meta::Node::ParseExpr_T e);
}

namespace lang::meta::Node::ParseExpr::Unfold {
    struct _T: lang::meta::Node::ParseExpr::_T {
        void write(ostream& os, FmtFlags flags);
        lang::meta::Node::ParseExpr_T e_;
        _T();
        lang::meta::Node::ParseExpr::Unfold_T with_id(Int id);
        lang::meta::Node::ParseExpr::Unfold_T with_bounds(lang_rt::TokenBounds bounds);
        lang::meta::Node::ParseExpr::Unfold_T with_is_top(bool is_top);
        lang::meta::Node::ParseExpr::Unfold_T with_sym(lang_rt::ParserSymId sym);
        lang::meta::Node::ParseExpr::Unfold_T with_attr(lang_rt::ParserAttrMask attr);
        lang::meta::Node::ParseExpr::Unfold_T with_first_k(lang_rt::ParserLookahead first_k);
        lang::meta::Node::ParseExpr::Unfold_T with_e(lang::meta::Node::ParseExpr_T e);
        void hash_ser_acc_lang_meta_Node_ParseExpr_Unfold(SerBuf& buf) const;
        virtual void hash_ser_acc(SerBuf& buf) const;
    };
}

void pr_debug(ostream& os, FmtFlags flags, lang::meta::Node::ParseExpr::AttrReq_T x);

namespace lang::meta::Node::ParseExpr::AttrReq {
    __attribute__((always_inline)) lang::meta::Node::ParseExpr::AttrReq_T make(Int id, lang_rt::TokenBounds bounds, bool is_top, lang_rt::ParserSymId sym, lang_rt::ParserAttrMask attr, lang_rt::ParserLookahead first_k, lang::meta::Node::ParseExpr_T e, Vec_T<lang::meta::Node::AttrReq_T> attrs);
}

namespace lang::meta::Node::ParseExpr::AttrReq {
    __attribute__((always_inline)) lang::meta::Node::ParseExpr::AttrReq_T make_ext(ArenaPtr arena, Int id, lang_rt::TokenBounds bounds, bool is_top, lang_rt::ParserSymId sym, lang_rt::ParserAttrMask attr, lang_rt::ParserLookahead first_k, lang::meta::Node::ParseExpr_T e, Vec_T<lang::meta::Node::AttrReq_T> attrs);
}

namespace lang::meta::Node::ParseExpr::AttrReq {
    struct _T: lang::meta::Node::ParseExpr::_T {
        void write(ostream& os, FmtFlags flags);
        lang::meta::Node::ParseExpr_T e_;
        Vec_T<lang::meta::Node::AttrReq_T> attrs_;
        _T();
        lang::meta::Node::ParseExpr::AttrReq_T with_id(Int id);
        lang::meta::Node::ParseExpr::AttrReq_T with_bounds(lang_rt::TokenBounds bounds);
        lang::meta::Node::ParseExpr::AttrReq_T with_is_top(bool is_top);
        lang::meta::Node::ParseExpr::AttrReq_T with_sym(lang_rt::ParserSymId sym);
        lang::meta::Node::ParseExpr::AttrReq_T with_attr(lang_rt::ParserAttrMask attr);
        lang::meta::Node::ParseExpr::AttrReq_T with_first_k(lang_rt::ParserLookahead first_k);
        lang::meta::Node::ParseExpr::AttrReq_T with_e(lang::meta::Node::ParseExpr_T e);
        lang::meta::Node::ParseExpr::AttrReq_T with_attrs(Vec_T<lang::meta::Node::AttrReq_T> attrs);
        void hash_ser_acc_lang_meta_Node_ParseExpr_AttrReq(SerBuf& buf) const;
        virtual void hash_ser_acc(SerBuf& buf) const;
    };
}

void pr_debug(ostream& os, FmtFlags flags, lang::meta::Node::AttrReq::Base_T x);

namespace lang::meta::Node::AttrReq::Base {
    __attribute__((always_inline)) lang::meta::Node::AttrReq::Base_T make(Int id, lang_rt::TokenBounds bounds, bool is_top, lang_rt::ParserSymId sym, lang_rt::ParserAttrMask attr, lang_rt::ParserLookahead first_k, StrSlice k);
}

namespace lang::meta::Node::AttrReq::Base {
    __attribute__((always_inline)) lang::meta::Node::AttrReq::Base_T make_ext(ArenaPtr arena, Int id, lang_rt::TokenBounds bounds, bool is_top, lang_rt::ParserSymId sym, lang_rt::ParserAttrMask attr, lang_rt::ParserLookahead first_k, StrSlice k);
}

namespace lang::meta::Node::AttrReq::Base {
    struct _T: lang::meta::Node::AttrReq::_T {
        void write(ostream& os, FmtFlags flags);
        StrSlice k_;
        _T();
        lang::meta::Node::AttrReq::Base_T with_id(Int id);
        lang::meta::Node::AttrReq::Base_T with_bounds(lang_rt::TokenBounds bounds);
        lang::meta::Node::AttrReq::Base_T with_is_top(bool is_top);
        lang::meta::Node::AttrReq::Base_T with_sym(lang_rt::ParserSymId sym);
        lang::meta::Node::AttrReq::Base_T with_attr(lang_rt::ParserAttrMask attr);
        lang::meta::Node::AttrReq::Base_T with_first_k(lang_rt::ParserLookahead first_k);
        lang::meta::Node::AttrReq::Base_T with_k(StrSlice k);
        void hash_ser_acc_lang_meta_Node_AttrReq_Base(SerBuf& buf) const;
        virtual void hash_ser_acc(SerBuf& buf) const;
    };
}

void pr_debug(ostream& os, FmtFlags flags, lang::meta::Node::AttrReq::PrecStar_T x);

namespace lang::meta::Node::AttrReq::PrecStar {
    __attribute__((always_inline)) lang::meta::Node::AttrReq::PrecStar_T make(Int id, lang_rt::TokenBounds bounds, bool is_top, lang_rt::ParserSymId sym, lang_rt::ParserAttrMask attr, lang_rt::ParserLookahead first_k);
}

namespace lang::meta::Node::AttrReq::PrecStar {
    __attribute__((always_inline)) lang::meta::Node::AttrReq::PrecStar_T make_ext(ArenaPtr arena, Int id, lang_rt::TokenBounds bounds, bool is_top, lang_rt::ParserSymId sym, lang_rt::ParserAttrMask attr, lang_rt::ParserLookahead first_k);
}

namespace lang::meta::Node::AttrReq::PrecStar {
    struct _T: lang::meta::Node::AttrReq::_T {
        void write(ostream& os, FmtFlags flags);
        _T();
        lang::meta::Node::AttrReq::PrecStar_T with_id(Int id);
        lang::meta::Node::AttrReq::PrecStar_T with_bounds(lang_rt::TokenBounds bounds);
        lang::meta::Node::AttrReq::PrecStar_T with_is_top(bool is_top);
        lang::meta::Node::AttrReq::PrecStar_T with_sym(lang_rt::ParserSymId sym);
        lang::meta::Node::AttrReq::PrecStar_T with_attr(lang_rt::ParserAttrMask attr);
        lang::meta::Node::AttrReq::PrecStar_T with_first_k(lang_rt::ParserLookahead first_k);
        void hash_ser_acc_lang_meta_Node_AttrReq_PrecStar(SerBuf& buf) const;
        virtual void hash_ser_acc(SerBuf& buf) const;
    };
}

void pr_debug(ostream& os, FmtFlags flags, lang::meta::Node::ParseExprListType::List_T x);

namespace lang::meta::Node::ParseExprListType::List {
    __attribute__((always_inline)) lang::meta::Node::ParseExprListType::List_T make(Int id, lang_rt::TokenBounds bounds, bool is_top, lang_rt::ParserSymId sym, lang_rt::ParserAttrMask attr, lang_rt::ParserLookahead first_k);
}

namespace lang::meta::Node::ParseExprListType::List {
    __attribute__((always_inline)) lang::meta::Node::ParseExprListType::List_T make_ext(ArenaPtr arena, Int id, lang_rt::TokenBounds bounds, bool is_top, lang_rt::ParserSymId sym, lang_rt::ParserAttrMask attr, lang_rt::ParserLookahead first_k);
}

namespace lang::meta::Node::ParseExprListType::List {
    struct _T: lang::meta::Node::ParseExprListType::_T {
        void write(ostream& os, FmtFlags flags);
        _T();
        lang::meta::Node::ParseExprListType::List_T with_id(Int id);
        lang::meta::Node::ParseExprListType::List_T with_bounds(lang_rt::TokenBounds bounds);
        lang::meta::Node::ParseExprListType::List_T with_is_top(bool is_top);
        lang::meta::Node::ParseExprListType::List_T with_sym(lang_rt::ParserSymId sym);
        lang::meta::Node::ParseExprListType::List_T with_attr(lang_rt::ParserAttrMask attr);
        lang::meta::Node::ParseExprListType::List_T with_first_k(lang_rt::ParserLookahead first_k);
        void hash_ser_acc_lang_meta_Node_ParseExprListType_List(SerBuf& buf) const;
        virtual void hash_ser_acc(SerBuf& buf) const;
    };
}

void pr_debug(ostream& os, FmtFlags flags, lang::meta::Node::ParseExprListType::Block_T x);

namespace lang::meta::Node::ParseExprListType::Block {
    __attribute__((always_inline)) lang::meta::Node::ParseExprListType::Block_T make(Int id, lang_rt::TokenBounds bounds, bool is_top, lang_rt::ParserSymId sym, lang_rt::ParserAttrMask attr, lang_rt::ParserLookahead first_k);
}

namespace lang::meta::Node::ParseExprListType::Block {
    __attribute__((always_inline)) lang::meta::Node::ParseExprListType::Block_T make_ext(ArenaPtr arena, Int id, lang_rt::TokenBounds bounds, bool is_top, lang_rt::ParserSymId sym, lang_rt::ParserAttrMask attr, lang_rt::ParserLookahead first_k);
}

namespace lang::meta::Node::ParseExprListType::Block {
    struct _T: lang::meta::Node::ParseExprListType::_T {
        void write(ostream& os, FmtFlags flags);
        _T();
        lang::meta::Node::ParseExprListType::Block_T with_id(Int id);
        lang::meta::Node::ParseExprListType::Block_T with_bounds(lang_rt::TokenBounds bounds);
        lang::meta::Node::ParseExprListType::Block_T with_is_top(bool is_top);
        lang::meta::Node::ParseExprListType::Block_T with_sym(lang_rt::ParserSymId sym);
        lang::meta::Node::ParseExprListType::Block_T with_attr(lang_rt::ParserAttrMask attr);
        lang::meta::Node::ParseExprListType::Block_T with_first_k(lang_rt::ParserLookahead first_k);
        void hash_ser_acc_lang_meta_Node_ParseExprListType_Block(SerBuf& buf) const;
        virtual void hash_ser_acc(SerBuf& buf) const;
    };
}

void pr_debug(ostream& os, FmtFlags flags, lang::meta::Node::ParseExprListType::Block2_T x);

namespace lang::meta::Node::ParseExprListType::Block2 {
    __attribute__((always_inline)) lang::meta::Node::ParseExprListType::Block2_T make(Int id, lang_rt::TokenBounds bounds, bool is_top, lang_rt::ParserSymId sym, lang_rt::ParserAttrMask attr, lang_rt::ParserLookahead first_k);
}

namespace lang::meta::Node::ParseExprListType::Block2 {
    __attribute__((always_inline)) lang::meta::Node::ParseExprListType::Block2_T make_ext(ArenaPtr arena, Int id, lang_rt::TokenBounds bounds, bool is_top, lang_rt::ParserSymId sym, lang_rt::ParserAttrMask attr, lang_rt::ParserLookahead first_k);
}

namespace lang::meta::Node::ParseExprListType::Block2 {
    struct _T: lang::meta::Node::ParseExprListType::_T {
        void write(ostream& os, FmtFlags flags);
        _T();
        lang::meta::Node::ParseExprListType::Block2_T with_id(Int id);
        lang::meta::Node::ParseExprListType::Block2_T with_bounds(lang_rt::TokenBounds bounds);
        lang::meta::Node::ParseExprListType::Block2_T with_is_top(bool is_top);
        lang::meta::Node::ParseExprListType::Block2_T with_sym(lang_rt::ParserSymId sym);
        lang::meta::Node::ParseExprListType::Block2_T with_attr(lang_rt::ParserAttrMask attr);
        lang::meta::Node::ParseExprListType::Block2_T with_first_k(lang_rt::ParserLookahead first_k);
        void hash_ser_acc_lang_meta_Node_ParseExprListType_Block2(SerBuf& buf) const;
        virtual void hash_ser_acc(SerBuf& buf) const;
    };
}

void pr_debug(ostream& os, FmtFlags flags, lang::meta::Node::ParseExprListType::Top_T x);

namespace lang::meta::Node::ParseExprListType::Top {
    __attribute__((always_inline)) lang::meta::Node::ParseExprListType::Top_T make(Int id, lang_rt::TokenBounds bounds, bool is_top, lang_rt::ParserSymId sym, lang_rt::ParserAttrMask attr, lang_rt::ParserLookahead first_k);
}

namespace lang::meta::Node::ParseExprListType::Top {
    __attribute__((always_inline)) lang::meta::Node::ParseExprListType::Top_T make_ext(ArenaPtr arena, Int id, lang_rt::TokenBounds bounds, bool is_top, lang_rt::ParserSymId sym, lang_rt::ParserAttrMask attr, lang_rt::ParserLookahead first_k);
}

namespace lang::meta::Node::ParseExprListType::Top {
    struct _T: lang::meta::Node::ParseExprListType::_T {
        void write(ostream& os, FmtFlags flags);
        _T();
        lang::meta::Node::ParseExprListType::Top_T with_id(Int id);
        lang::meta::Node::ParseExprListType::Top_T with_bounds(lang_rt::TokenBounds bounds);
        lang::meta::Node::ParseExprListType::Top_T with_is_top(bool is_top);
        lang::meta::Node::ParseExprListType::Top_T with_sym(lang_rt::ParserSymId sym);
        lang::meta::Node::ParseExprListType::Top_T with_attr(lang_rt::ParserAttrMask attr);
        lang::meta::Node::ParseExprListType::Top_T with_first_k(lang_rt::ParserLookahead first_k);
        void hash_ser_acc_lang_meta_Node_ParseExprListType_Top(SerBuf& buf) const;
        virtual void hash_ser_acc(SerBuf& buf) const;
    };
}

void pr_debug(ostream& os, FmtFlags flags, lang::meta::Node::ParseExprListType::Top2_T x);

namespace lang::meta::Node::ParseExprListType::Top2 {
    __attribute__((always_inline)) lang::meta::Node::ParseExprListType::Top2_T make(Int id, lang_rt::TokenBounds bounds, bool is_top, lang_rt::ParserSymId sym, lang_rt::ParserAttrMask attr, lang_rt::ParserLookahead first_k);
}

namespace lang::meta::Node::ParseExprListType::Top2 {
    __attribute__((always_inline)) lang::meta::Node::ParseExprListType::Top2_T make_ext(ArenaPtr arena, Int id, lang_rt::TokenBounds bounds, bool is_top, lang_rt::ParserSymId sym, lang_rt::ParserAttrMask attr, lang_rt::ParserLookahead first_k);
}

namespace lang::meta::Node::ParseExprListType::Top2 {
    struct _T: lang::meta::Node::ParseExprListType::_T {
        void write(ostream& os, FmtFlags flags);
        _T();
        lang::meta::Node::ParseExprListType::Top2_T with_id(Int id);
        lang::meta::Node::ParseExprListType::Top2_T with_bounds(lang_rt::TokenBounds bounds);
        lang::meta::Node::ParseExprListType::Top2_T with_is_top(bool is_top);
        lang::meta::Node::ParseExprListType::Top2_T with_sym(lang_rt::ParserSymId sym);
        lang::meta::Node::ParseExprListType::Top2_T with_attr(lang_rt::ParserAttrMask attr);
        lang::meta::Node::ParseExprListType::Top2_T with_first_k(lang_rt::ParserLookahead first_k);
        void hash_ser_acc_lang_meta_Node_ParseExprListType_Top2(SerBuf& buf) const;
        virtual void hash_ser_acc(SerBuf& buf) const;
    };
}

void pr_debug(ostream& os, FmtFlags flags, lang::meta::Node::ParseExprListNum::Ge0_T x);

namespace lang::meta::Node::ParseExprListNum::Ge0 {
    __attribute__((always_inline)) lang::meta::Node::ParseExprListNum::Ge0_T make(Int id, lang_rt::TokenBounds bounds, bool is_top, lang_rt::ParserSymId sym, lang_rt::ParserAttrMask attr, lang_rt::ParserLookahead first_k);
}

namespace lang::meta::Node::ParseExprListNum::Ge0 {
    __attribute__((always_inline)) lang::meta::Node::ParseExprListNum::Ge0_T make_ext(ArenaPtr arena, Int id, lang_rt::TokenBounds bounds, bool is_top, lang_rt::ParserSymId sym, lang_rt::ParserAttrMask attr, lang_rt::ParserLookahead first_k);
}

namespace lang::meta::Node::ParseExprListNum::Ge0 {
    struct _T: lang::meta::Node::ParseExprListNum::_T {
        void write(ostream& os, FmtFlags flags);
        _T();
        lang::meta::Node::ParseExprListNum::Ge0_T with_id(Int id);
        lang::meta::Node::ParseExprListNum::Ge0_T with_bounds(lang_rt::TokenBounds bounds);
        lang::meta::Node::ParseExprListNum::Ge0_T with_is_top(bool is_top);
        lang::meta::Node::ParseExprListNum::Ge0_T with_sym(lang_rt::ParserSymId sym);
        lang::meta::Node::ParseExprListNum::Ge0_T with_attr(lang_rt::ParserAttrMask attr);
        lang::meta::Node::ParseExprListNum::Ge0_T with_first_k(lang_rt::ParserLookahead first_k);
        void hash_ser_acc_lang_meta_Node_ParseExprListNum_Ge0(SerBuf& buf) const;
        virtual void hash_ser_acc(SerBuf& buf) const;
    };
}

void pr_debug(ostream& os, FmtFlags flags, lang::meta::Node::ParseExprListNum::Ge1_T x);

namespace lang::meta::Node::ParseExprListNum::Ge1 {
    __attribute__((always_inline)) lang::meta::Node::ParseExprListNum::Ge1_T make(Int id, lang_rt::TokenBounds bounds, bool is_top, lang_rt::ParserSymId sym, lang_rt::ParserAttrMask attr, lang_rt::ParserLookahead first_k);
}

namespace lang::meta::Node::ParseExprListNum::Ge1 {
    __attribute__((always_inline)) lang::meta::Node::ParseExprListNum::Ge1_T make_ext(ArenaPtr arena, Int id, lang_rt::TokenBounds bounds, bool is_top, lang_rt::ParserSymId sym, lang_rt::ParserAttrMask attr, lang_rt::ParserLookahead first_k);
}

namespace lang::meta::Node::ParseExprListNum::Ge1 {
    struct _T: lang::meta::Node::ParseExprListNum::_T {
        void write(ostream& os, FmtFlags flags);
        _T();
        lang::meta::Node::ParseExprListNum::Ge1_T with_id(Int id);
        lang::meta::Node::ParseExprListNum::Ge1_T with_bounds(lang_rt::TokenBounds bounds);
        lang::meta::Node::ParseExprListNum::Ge1_T with_is_top(bool is_top);
        lang::meta::Node::ParseExprListNum::Ge1_T with_sym(lang_rt::ParserSymId sym);
        lang::meta::Node::ParseExprListNum::Ge1_T with_attr(lang_rt::ParserAttrMask attr);
        lang::meta::Node::ParseExprListNum::Ge1_T with_first_k(lang_rt::ParserLookahead first_k);
        void hash_ser_acc_lang_meta_Node_ParseExprListNum_Ge1(SerBuf& buf) const;
        virtual void hash_ser_acc(SerBuf& buf) const;
    };
}

void pr_debug(ostream& os, FmtFlags flags, lang::meta::Node::ParseExprListNum::Ge2_T x);

namespace lang::meta::Node::ParseExprListNum::Ge2 {
    __attribute__((always_inline)) lang::meta::Node::ParseExprListNum::Ge2_T make(Int id, lang_rt::TokenBounds bounds, bool is_top, lang_rt::ParserSymId sym, lang_rt::ParserAttrMask attr, lang_rt::ParserLookahead first_k);
}

namespace lang::meta::Node::ParseExprListNum::Ge2 {
    __attribute__((always_inline)) lang::meta::Node::ParseExprListNum::Ge2_T make_ext(ArenaPtr arena, Int id, lang_rt::TokenBounds bounds, bool is_top, lang_rt::ParserSymId sym, lang_rt::ParserAttrMask attr, lang_rt::ParserLookahead first_k);
}

namespace lang::meta::Node::ParseExprListNum::Ge2 {
    struct _T: lang::meta::Node::ParseExprListNum::_T {
        void write(ostream& os, FmtFlags flags);
        _T();
        lang::meta::Node::ParseExprListNum::Ge2_T with_id(Int id);
        lang::meta::Node::ParseExprListNum::Ge2_T with_bounds(lang_rt::TokenBounds bounds);
        lang::meta::Node::ParseExprListNum::Ge2_T with_is_top(bool is_top);
        lang::meta::Node::ParseExprListNum::Ge2_T with_sym(lang_rt::ParserSymId sym);
        lang::meta::Node::ParseExprListNum::Ge2_T with_attr(lang_rt::ParserAttrMask attr);
        lang::meta::Node::ParseExprListNum::Ge2_T with_first_k(lang_rt::ParserLookahead first_k);
        void hash_ser_acc_lang_meta_Node_ParseExprListNum_Ge2(SerBuf& buf) const;
        virtual void hash_ser_acc(SerBuf& buf) const;
    };
}

void pr_debug(ostream& os, FmtFlags flags, lang::meta::Node::TokenDecl::op::DEF_T x);

namespace lang::meta::Node::TokenDecl::op::DEF {
    __attribute__((always_inline)) lang::meta::Node::TokenDecl::op::DEF_T make(Int id, lang_rt::TokenBounds bounds, bool is_top, lang_rt::ParserSymId sym, lang_rt::ParserAttrMask attr, lang_rt::ParserLookahead first_k);
}

namespace lang::meta::Node::TokenDecl::op::DEF {
    __attribute__((always_inline)) lang::meta::Node::TokenDecl::op::DEF_T make_ext(ArenaPtr arena, Int id, lang_rt::TokenBounds bounds, bool is_top, lang_rt::ParserSymId sym, lang_rt::ParserAttrMask attr, lang_rt::ParserLookahead first_k);
}

namespace lang::meta::Node::TokenDecl::op::DEF {
    struct _T: lang::meta::Node::TokenDecl::op::_T {
        void write(ostream& os, FmtFlags flags);
        _T();
        lang::meta::Node::TokenDecl::op::DEF_T with_id(Int id);
        lang::meta::Node::TokenDecl::op::DEF_T with_bounds(lang_rt::TokenBounds bounds);
        lang::meta::Node::TokenDecl::op::DEF_T with_is_top(bool is_top);
        lang::meta::Node::TokenDecl::op::DEF_T with_sym(lang_rt::ParserSymId sym);
        lang::meta::Node::TokenDecl::op::DEF_T with_attr(lang_rt::ParserAttrMask attr);
        lang::meta::Node::TokenDecl::op::DEF_T with_first_k(lang_rt::ParserLookahead first_k);
        void hash_ser_acc_lang_meta_Node_TokenDecl_op_DEF(SerBuf& buf) const;
        virtual void hash_ser_acc(SerBuf& buf) const;
    };
}

void pr_debug(ostream& os, FmtFlags flags, lang::meta::Node::TokenDecl::op::DEF_ALIAS_T x);

namespace lang::meta::Node::TokenDecl::op::DEF_ALIAS {
    __attribute__((always_inline)) lang::meta::Node::TokenDecl::op::DEF_ALIAS_T make(Int id, lang_rt::TokenBounds bounds, bool is_top, lang_rt::ParserSymId sym, lang_rt::ParserAttrMask attr, lang_rt::ParserLookahead first_k);
}

namespace lang::meta::Node::TokenDecl::op::DEF_ALIAS {
    __attribute__((always_inline)) lang::meta::Node::TokenDecl::op::DEF_ALIAS_T make_ext(ArenaPtr arena, Int id, lang_rt::TokenBounds bounds, bool is_top, lang_rt::ParserSymId sym, lang_rt::ParserAttrMask attr, lang_rt::ParserLookahead first_k);
}

namespace lang::meta::Node::TokenDecl::op::DEF_ALIAS {
    struct _T: lang::meta::Node::TokenDecl::op::_T {
        void write(ostream& os, FmtFlags flags);
        _T();
        lang::meta::Node::TokenDecl::op::DEF_ALIAS_T with_id(Int id);
        lang::meta::Node::TokenDecl::op::DEF_ALIAS_T with_bounds(lang_rt::TokenBounds bounds);
        lang::meta::Node::TokenDecl::op::DEF_ALIAS_T with_is_top(bool is_top);
        lang::meta::Node::TokenDecl::op::DEF_ALIAS_T with_sym(lang_rt::ParserSymId sym);
        lang::meta::Node::TokenDecl::op::DEF_ALIAS_T with_attr(lang_rt::ParserAttrMask attr);
        lang::meta::Node::TokenDecl::op::DEF_ALIAS_T with_first_k(lang_rt::ParserLookahead first_k);
        void hash_ser_acc_lang_meta_Node_TokenDecl_op_DEF_ALIAS(SerBuf& buf) const;
        virtual void hash_ser_acc(SerBuf& buf) const;
    };
}

void pr_debug(ostream& os, FmtFlags flags, lang::meta::Node::ParserDecl::Rule::op_T x);

namespace lang::meta::Node::ParserDecl::Rule::op {
    enum struct _W {
        DEF,
        DEF_ALIAS,
    };
}

namespace lang::meta::Node::ParserDecl::Rule::op {
    struct _T: lang::meta::Node::_T {
        void write(ostream& os, FmtFlags flags);
        lang::meta::Node::ParserDecl::Rule::op::_W w_;
        virtual ~_T();
        _T(lang::meta::Node::ParserDecl::Rule::op::_W w);
        bool is_DEF();
        bool is_DEF_ALIAS();
        lang::meta::Node::ParserDecl::Rule::op::DEF_T as_DEF();
        lang::meta::Node::ParserDecl::Rule::op::DEF_ALIAS_T as_DEF_ALIAS();
        void hash_ser_acc_lang_meta_Node_ParserDecl_Rule_op(SerBuf& buf) const;
        virtual void hash_ser_acc(SerBuf& buf) const = 0;
    };
}

void pr_debug(ostream& os, FmtFlags flags, lang::meta::Node::ParseExpr::List::end_delim_T x);

namespace lang::meta::Node::ParseExpr::List::end_delim {
    enum struct _W {
        NONE,
        OPTIONAL,
        SOME,
    };
}

namespace lang::meta::Node::ParseExpr::List::end_delim {
    struct _T: lang::meta::Node::_T {
        void write(ostream& os, FmtFlags flags);
        lang::meta::Node::ParseExpr::List::end_delim::_W w_;
        virtual ~_T();
        _T(lang::meta::Node::ParseExpr::List::end_delim::_W w);
        bool is_NONE();
        bool is_OPTIONAL();
        bool is_SOME();
        lang::meta::Node::ParseExpr::List::end_delim::NONE_T as_NONE();
        lang::meta::Node::ParseExpr::List::end_delim::OPTIONAL_T as_OPTIONAL();
        lang::meta::Node::ParseExpr::List::end_delim::SOME_T as_SOME();
        void hash_ser_acc_lang_meta_Node_ParseExpr_List_end_delim(SerBuf& buf) const;
        virtual void hash_ser_acc(SerBuf& buf) const = 0;
    };
}

void pr_debug(ostream& os, FmtFlags flags, lang::meta::Node::ParserDecl::Rule::op::DEF_T x);

namespace lang::meta::Node::ParserDecl::Rule::op::DEF {
    __attribute__((always_inline)) lang::meta::Node::ParserDecl::Rule::op::DEF_T make(Int id, lang_rt::TokenBounds bounds, bool is_top, lang_rt::ParserSymId sym, lang_rt::ParserAttrMask attr, lang_rt::ParserLookahead first_k);
}

namespace lang::meta::Node::ParserDecl::Rule::op::DEF {
    __attribute__((always_inline)) lang::meta::Node::ParserDecl::Rule::op::DEF_T make_ext(ArenaPtr arena, Int id, lang_rt::TokenBounds bounds, bool is_top, lang_rt::ParserSymId sym, lang_rt::ParserAttrMask attr, lang_rt::ParserLookahead first_k);
}

namespace lang::meta::Node::ParserDecl::Rule::op::DEF {
    struct _T: lang::meta::Node::ParserDecl::Rule::op::_T {
        void write(ostream& os, FmtFlags flags);
        _T();
        lang::meta::Node::ParserDecl::Rule::op::DEF_T with_id(Int id);
        lang::meta::Node::ParserDecl::Rule::op::DEF_T with_bounds(lang_rt::TokenBounds bounds);
        lang::meta::Node::ParserDecl::Rule::op::DEF_T with_is_top(bool is_top);
        lang::meta::Node::ParserDecl::Rule::op::DEF_T with_sym(lang_rt::ParserSymId sym);
        lang::meta::Node::ParserDecl::Rule::op::DEF_T with_attr(lang_rt::ParserAttrMask attr);
        lang::meta::Node::ParserDecl::Rule::op::DEF_T with_first_k(lang_rt::ParserLookahead first_k);
        void hash_ser_acc_lang_meta_Node_ParserDecl_Rule_op_DEF(SerBuf& buf) const;
        virtual void hash_ser_acc(SerBuf& buf) const;
    };
}

void pr_debug(ostream& os, FmtFlags flags, lang::meta::Node::ParserDecl::Rule::op::DEF_ALIAS_T x);

namespace lang::meta::Node::ParserDecl::Rule::op::DEF_ALIAS {
    __attribute__((always_inline)) lang::meta::Node::ParserDecl::Rule::op::DEF_ALIAS_T make(Int id, lang_rt::TokenBounds bounds, bool is_top, lang_rt::ParserSymId sym, lang_rt::ParserAttrMask attr, lang_rt::ParserLookahead first_k);
}

namespace lang::meta::Node::ParserDecl::Rule::op::DEF_ALIAS {
    __attribute__((always_inline)) lang::meta::Node::ParserDecl::Rule::op::DEF_ALIAS_T make_ext(ArenaPtr arena, Int id, lang_rt::TokenBounds bounds, bool is_top, lang_rt::ParserSymId sym, lang_rt::ParserAttrMask attr, lang_rt::ParserLookahead first_k);
}

namespace lang::meta::Node::ParserDecl::Rule::op::DEF_ALIAS {
    struct _T: lang::meta::Node::ParserDecl::Rule::op::_T {
        void write(ostream& os, FmtFlags flags);
        _T();
        lang::meta::Node::ParserDecl::Rule::op::DEF_ALIAS_T with_id(Int id);
        lang::meta::Node::ParserDecl::Rule::op::DEF_ALIAS_T with_bounds(lang_rt::TokenBounds bounds);
        lang::meta::Node::ParserDecl::Rule::op::DEF_ALIAS_T with_is_top(bool is_top);
        lang::meta::Node::ParserDecl::Rule::op::DEF_ALIAS_T with_sym(lang_rt::ParserSymId sym);
        lang::meta::Node::ParserDecl::Rule::op::DEF_ALIAS_T with_attr(lang_rt::ParserAttrMask attr);
        lang::meta::Node::ParserDecl::Rule::op::DEF_ALIAS_T with_first_k(lang_rt::ParserLookahead first_k);
        void hash_ser_acc_lang_meta_Node_ParserDecl_Rule_op_DEF_ALIAS(SerBuf& buf) const;
        virtual void hash_ser_acc(SerBuf& buf) const;
    };
}

void pr_debug(ostream& os, FmtFlags flags, lang::meta::Node::ParseExpr::List::end_delim::NONE_T x);

namespace lang::meta::Node::ParseExpr::List::end_delim::NONE {
    __attribute__((always_inline)) lang::meta::Node::ParseExpr::List::end_delim::NONE_T make(Int id, lang_rt::TokenBounds bounds, bool is_top, lang_rt::ParserSymId sym, lang_rt::ParserAttrMask attr, lang_rt::ParserLookahead first_k);
}

namespace lang::meta::Node::ParseExpr::List::end_delim::NONE {
    __attribute__((always_inline)) lang::meta::Node::ParseExpr::List::end_delim::NONE_T make_ext(ArenaPtr arena, Int id, lang_rt::TokenBounds bounds, bool is_top, lang_rt::ParserSymId sym, lang_rt::ParserAttrMask attr, lang_rt::ParserLookahead first_k);
}

namespace lang::meta::Node::ParseExpr::List::end_delim::NONE {
    struct _T: lang::meta::Node::ParseExpr::List::end_delim::_T {
        void write(ostream& os, FmtFlags flags);
        _T();
        lang::meta::Node::ParseExpr::List::end_delim::NONE_T with_id(Int id);
        lang::meta::Node::ParseExpr::List::end_delim::NONE_T with_bounds(lang_rt::TokenBounds bounds);
        lang::meta::Node::ParseExpr::List::end_delim::NONE_T with_is_top(bool is_top);
        lang::meta::Node::ParseExpr::List::end_delim::NONE_T with_sym(lang_rt::ParserSymId sym);
        lang::meta::Node::ParseExpr::List::end_delim::NONE_T with_attr(lang_rt::ParserAttrMask attr);
        lang::meta::Node::ParseExpr::List::end_delim::NONE_T with_first_k(lang_rt::ParserLookahead first_k);
        void hash_ser_acc_lang_meta_Node_ParseExpr_List_end_delim_NONE(SerBuf& buf) const;
        virtual void hash_ser_acc(SerBuf& buf) const;
    };
}

void pr_debug(ostream& os, FmtFlags flags, lang::meta::Node::ParseExpr::List::end_delim::OPTIONAL_T x);

namespace lang::meta::Node::ParseExpr::List::end_delim::OPTIONAL {
    __attribute__((always_inline)) lang::meta::Node::ParseExpr::List::end_delim::OPTIONAL_T make(Int id, lang_rt::TokenBounds bounds, bool is_top, lang_rt::ParserSymId sym, lang_rt::ParserAttrMask attr, lang_rt::ParserLookahead first_k);
}

namespace lang::meta::Node::ParseExpr::List::end_delim::OPTIONAL {
    __attribute__((always_inline)) lang::meta::Node::ParseExpr::List::end_delim::OPTIONAL_T make_ext(ArenaPtr arena, Int id, lang_rt::TokenBounds bounds, bool is_top, lang_rt::ParserSymId sym, lang_rt::ParserAttrMask attr, lang_rt::ParserLookahead first_k);
}

namespace lang::meta::Node::ParseExpr::List::end_delim::OPTIONAL {
    struct _T: lang::meta::Node::ParseExpr::List::end_delim::_T {
        void write(ostream& os, FmtFlags flags);
        _T();
        lang::meta::Node::ParseExpr::List::end_delim::OPTIONAL_T with_id(Int id);
        lang::meta::Node::ParseExpr::List::end_delim::OPTIONAL_T with_bounds(lang_rt::TokenBounds bounds);
        lang::meta::Node::ParseExpr::List::end_delim::OPTIONAL_T with_is_top(bool is_top);
        lang::meta::Node::ParseExpr::List::end_delim::OPTIONAL_T with_sym(lang_rt::ParserSymId sym);
        lang::meta::Node::ParseExpr::List::end_delim::OPTIONAL_T with_attr(lang_rt::ParserAttrMask attr);
        lang::meta::Node::ParseExpr::List::end_delim::OPTIONAL_T with_first_k(lang_rt::ParserLookahead first_k);
        void hash_ser_acc_lang_meta_Node_ParseExpr_List_end_delim_OPTIONAL(SerBuf& buf) const;
        virtual void hash_ser_acc(SerBuf& buf) const;
    };
}

void pr_debug(ostream& os, FmtFlags flags, lang::meta::Node::ParseExpr::List::end_delim::SOME_T x);

namespace lang::meta::Node::ParseExpr::List::end_delim::SOME {
    __attribute__((always_inline)) lang::meta::Node::ParseExpr::List::end_delim::SOME_T make(Int id, lang_rt::TokenBounds bounds, bool is_top, lang_rt::ParserSymId sym, lang_rt::ParserAttrMask attr, lang_rt::ParserLookahead first_k);
}

namespace lang::meta::Node::ParseExpr::List::end_delim::SOME {
    __attribute__((always_inline)) lang::meta::Node::ParseExpr::List::end_delim::SOME_T make_ext(ArenaPtr arena, Int id, lang_rt::TokenBounds bounds, bool is_top, lang_rt::ParserSymId sym, lang_rt::ParserAttrMask attr, lang_rt::ParserLookahead first_k);
}

namespace lang::meta::Node::ParseExpr::List::end_delim::SOME {
    struct _T: lang::meta::Node::ParseExpr::List::end_delim::_T {
        void write(ostream& os, FmtFlags flags);
        _T();
        lang::meta::Node::ParseExpr::List::end_delim::SOME_T with_id(Int id);
        lang::meta::Node::ParseExpr::List::end_delim::SOME_T with_bounds(lang_rt::TokenBounds bounds);
        lang::meta::Node::ParseExpr::List::end_delim::SOME_T with_is_top(bool is_top);
        lang::meta::Node::ParseExpr::List::end_delim::SOME_T with_sym(lang_rt::ParserSymId sym);
        lang::meta::Node::ParseExpr::List::end_delim::SOME_T with_attr(lang_rt::ParserAttrMask attr);
        lang::meta::Node::ParseExpr::List::end_delim::SOME_T with_first_k(lang_rt::ParserLookahead first_k);
        void hash_ser_acc_lang_meta_Node_ParseExpr_List_end_delim_SOME(SerBuf& buf) const;
        virtual void hash_ser_acc(SerBuf& buf) const;
    };
}

void visit_lang_meta_Node(lang::meta::Node::TokenDecl::op::DEF_T x, function<void(lang::meta::Node_T)> f);

void visit_lang_meta_Node(lang::meta::Node::TokenDecl::op::DEF_ALIAS_T x, function<void(lang::meta::Node_T)> f);

void visit_lang_meta_Node(lang::meta::Node::TokenDecl::op_T x, function<void(lang::meta::Node_T)> f);

void visit_lang_meta_Node(lang::meta::Node::Id_T x, function<void(lang::meta::Node_T)> f);

void visit_lang_meta_Node(lang::meta::Node::ParseExpr::Id_T x, function<void(lang::meta::Node_T)> f);

void visit_lang_meta_Node(lang::meta::Node::ParseExpr::Eof_T x, function<void(lang::meta::Node_T)> f);

void visit_lang_meta_Node(lang::meta::Node::ParseExpr::False_T x, function<void(lang::meta::Node_T)> f);

void visit_lang_meta_Node(lang::meta::Node::ParseExpr::Eps_T x, function<void(lang::meta::Node_T)> f);

void visit_lang_meta_Node(lang::meta::Node::ParseExpr::Indent_T x, function<void(lang::meta::Node_T)> f);

void visit_lang_meta_Node(lang::meta::Node::ParseExpr::Dedent_T x, function<void(lang::meta::Node_T)> f);

void visit_lang_meta_Node(lang::meta::Node::ParseExpr::Newline_T x, function<void(lang::meta::Node_T)> f);

void visit_lang_meta_Node(lang::meta::Node::ParseExpr::UnicodeAny_T x, function<void(lang::meta::Node_T)> f);

void visit_lang_meta_Node(lang::meta::Node::ParseExpr::AsciiBaseAny_T x, function<void(lang::meta::Node_T)> f);

void visit_lang_meta_Node(lang::meta::Node::ParseExpr::Alt_T x, function<void(lang::meta::Node_T)> f);

void visit_lang_meta_Node(lang::meta::Node::ParseExpr::AltExplicit_T x, function<void(lang::meta::Node_T)> f);

void visit_lang_meta_Node(lang::meta::Node::ParseExpr::Minus_T x, function<void(lang::meta::Node_T)> f);

void visit_lang_meta_Node(lang::meta::Node::ParseExpr::Concat_T x, function<void(lang::meta::Node_T)> f);

void visit_lang_meta_Node(lang::meta::Node::ParseExpr::Optional_T x, function<void(lang::meta::Node_T)> f);

void visit_lang_meta_Node(lang::meta::Node::ParseExpr::Rep_T x, function<void(lang::meta::Node_T)> f);

void visit_lang_meta_Node(lang::meta::Node::ParseExpr::RepNonzero_T x, function<void(lang::meta::Node_T)> f);

void visit_lang_meta_Node(lang::meta::Node::ParseExpr::RepCount_T x, function<void(lang::meta::Node_T)> f);

void visit_lang_meta_Node(lang::meta::Node::ParseExpr::CharRange_T x, function<void(lang::meta::Node_T)> f);

void visit_lang_meta_Node(lang::meta::Node::ParseExpr::StrLit_T x, function<void(lang::meta::Node_T)> f);

void visit_lang_meta_Node(lang::meta::Node::ParseExpr::Underscore_T x, function<void(lang::meta::Node_T)> f);

void visit_lang_meta_Node(lang::meta::Node::ParseExpr::Pass_T x, function<void(lang::meta::Node_T)> f);

void visit_lang_meta_Node(lang::meta::Node::ParseExpr::Paren_T x, function<void(lang::meta::Node_T)> f);

void visit_lang_meta_Node(lang::meta::Node::ParseExpr::Name_T x, function<void(lang::meta::Node_T)> f);

void visit_lang_meta_Node(lang::meta::Node::ParseExprListType::List_T x, function<void(lang::meta::Node_T)> f);

void visit_lang_meta_Node(lang::meta::Node::ParseExprListType::Block_T x, function<void(lang::meta::Node_T)> f);

void visit_lang_meta_Node(lang::meta::Node::ParseExprListType::Block2_T x, function<void(lang::meta::Node_T)> f);

void visit_lang_meta_Node(lang::meta::Node::ParseExprListType::Top_T x, function<void(lang::meta::Node_T)> f);

void visit_lang_meta_Node(lang::meta::Node::ParseExprListType::Top2_T x, function<void(lang::meta::Node_T)> f);

void visit_lang_meta_Node(lang::meta::Node::ParseExprListType_T x, function<void(lang::meta::Node_T)> f);

void visit_lang_meta_Node(lang::meta::Node::ParseExprListNum::Ge0_T x, function<void(lang::meta::Node_T)> f);

void visit_lang_meta_Node(lang::meta::Node::ParseExprListNum::Ge1_T x, function<void(lang::meta::Node_T)> f);

void visit_lang_meta_Node(lang::meta::Node::ParseExprListNum::Ge2_T x, function<void(lang::meta::Node_T)> f);

void visit_lang_meta_Node(lang::meta::Node::ParseExprListNum_T x, function<void(lang::meta::Node_T)> f);

void visit_lang_meta_Node(lang::meta::Node::ParseExpr::List::end_delim::NONE_T x, function<void(lang::meta::Node_T)> f);

void visit_lang_meta_Node(lang::meta::Node::ParseExpr::List::end_delim::OPTIONAL_T x, function<void(lang::meta::Node_T)> f);

void visit_lang_meta_Node(lang::meta::Node::ParseExpr::List::end_delim::SOME_T x, function<void(lang::meta::Node_T)> f);

void visit_lang_meta_Node(lang::meta::Node::ParseExpr::List::end_delim_T x, function<void(lang::meta::Node_T)> f);

void visit_lang_meta_Node(lang::meta::Node::ParseExpr::List_T x, function<void(lang::meta::Node_T)> f);

void visit_lang_meta_Node(lang::meta::Node::ParseExpr::Unfold_T x, function<void(lang::meta::Node_T)> f);

void visit_lang_meta_Node(lang::meta::Node::AttrReq::Base_T x, function<void(lang::meta::Node_T)> f);

void visit_lang_meta_Node(lang::meta::Node::AttrReq::PrecStar_T x, function<void(lang::meta::Node_T)> f);

void visit_lang_meta_Node(lang::meta::Node::AttrReq_T x, function<void(lang::meta::Node_T)> f);

void visit_lang_meta_Node(lang::meta::Node::ParseExpr::AttrReq_T x, function<void(lang::meta::Node_T)> f);

void visit_lang_meta_Node(lang::meta::Node::ParseExpr_T x, function<void(lang::meta::Node_T)> f);

void visit_lang_meta_Node(lang::meta::Node::TokenDecl_T x, function<void(lang::meta::Node_T)> f);

void visit_lang_meta_Node(lang::meta::Node::Stanza::Tokens_T x, function<void(lang::meta::Node_T)> f);

void visit_lang_meta_Node(lang::meta::Node::LexerDecl::Main_T x, function<void(lang::meta::Node_T)> f);

void visit_lang_meta_Node(lang::meta::Node::LexerInstr::Emit_T x, function<void(lang::meta::Node_T)> f);

void visit_lang_meta_Node(lang::meta::Node::LexerInstr::Pass_T x, function<void(lang::meta::Node_T)> f);

void visit_lang_meta_Node(lang::meta::Node::LexerInstr::Push_T x, function<void(lang::meta::Node_T)> f);

void visit_lang_meta_Node(lang::meta::Node::LexerInstr::Pop_T x, function<void(lang::meta::Node_T)> f);

void visit_lang_meta_Node(lang::meta::Node::LexerInstr::PopExtract_T x, function<void(lang::meta::Node_T)> f);

void visit_lang_meta_Node(lang::meta::Node::LexerInstr::PopEmit_T x, function<void(lang::meta::Node_T)> f);

void visit_lang_meta_Node(lang::meta::Node::LexerInstr::MatchHistory_T x, function<void(lang::meta::Node_T)> f);

void visit_lang_meta_Node(lang::meta::Node::LexerInstr_T x, function<void(lang::meta::Node_T)> f);

void visit_lang_meta_Node(lang::meta::Node::LexerModeCase_T x, function<void(lang::meta::Node_T)> f);

void visit_lang_meta_Node(lang::meta::Node::LexerDecl::Mode_T x, function<void(lang::meta::Node_T)> f);

void visit_lang_meta_Node(lang::meta::Node::LexerDecl_T x, function<void(lang::meta::Node_T)> f);

void visit_lang_meta_Node(lang::meta::Node::Stanza::Lexer_T x, function<void(lang::meta::Node_T)> f);

void visit_lang_meta_Node(lang::meta::Node::ParserDecl::Main_T x, function<void(lang::meta::Node_T)> f);

void visit_lang_meta_Node(lang::meta::Node::ParserProp::NameStrict_T x, function<void(lang::meta::Node_T)> f);

void visit_lang_meta_Node(lang::meta::Node::ParserProp::LRSpec_T x, function<void(lang::meta::Node_T)> f);

void visit_lang_meta_Node(lang::meta::Node::ParserProp::Err__T x, function<void(lang::meta::Node_T)> f);

void visit_lang_meta_Node(lang::meta::Node::ParserProp_T x, function<void(lang::meta::Node_T)> f);

void visit_lang_meta_Node(lang::meta::Node::ParserDecl::Prop_T x, function<void(lang::meta::Node_T)> f);

void visit_lang_meta_Node(lang::meta::Node::PrecAssoc::Left_T x, function<void(lang::meta::Node_T)> f);

void visit_lang_meta_Node(lang::meta::Node::PrecAssoc::Right_T x, function<void(lang::meta::Node_T)> f);

void visit_lang_meta_Node(lang::meta::Node::PrecAssoc::Prefix_T x, function<void(lang::meta::Node_T)> f);

void visit_lang_meta_Node(lang::meta::Node::PrecAssoc::Postfix_T x, function<void(lang::meta::Node_T)> f);

void visit_lang_meta_Node(lang::meta::Node::PrecAssoc_T x, function<void(lang::meta::Node_T)> f);

void visit_lang_meta_Node(lang::meta::Node::PrecItem_T x, function<void(lang::meta::Node_T)> f);

void visit_lang_meta_Node(lang::meta::Node::ParserDecl::Prec_T x, function<void(lang::meta::Node_T)> f);

void visit_lang_meta_Node(lang::meta::Node::AttrClauseExpr::LhsGeq_T x, function<void(lang::meta::Node_T)> f);

void visit_lang_meta_Node(lang::meta::Node::AttrClauseExprRhsLoc::All_T x, function<void(lang::meta::Node_T)> f);

void visit_lang_meta_Node(lang::meta::Node::AttrClauseExprRhsLoc::Begin_T x, function<void(lang::meta::Node_T)> f);

void visit_lang_meta_Node(lang::meta::Node::AttrClauseExprRhsLoc::Mid_T x, function<void(lang::meta::Node_T)> f);

void visit_lang_meta_Node(lang::meta::Node::AttrClauseExprRhsLoc::End_T x, function<void(lang::meta::Node_T)> f);

void visit_lang_meta_Node(lang::meta::Node::AttrClauseExprRhsLoc_T x, function<void(lang::meta::Node_T)> f);

void visit_lang_meta_Node(lang::meta::Node::AttrClauseExpr::RhsGeq_T x, function<void(lang::meta::Node_T)> f);

void visit_lang_meta_Node(lang::meta::Node::AttrClauseExpr::Implies_T x, function<void(lang::meta::Node_T)> f);

void visit_lang_meta_Node(lang::meta::Node::AttrClauseExpr_T x, function<void(lang::meta::Node_T)> f);

void visit_lang_meta_Node(lang::meta::Node::AttrClause::Expr_T x, function<void(lang::meta::Node_T)> f);

void visit_lang_meta_Node(lang::meta::Node::AttrClause::Block_T x, function<void(lang::meta::Node_T)> f);

void visit_lang_meta_Node(lang::meta::Node::AttrMatchCasePattern::Alt_T x, function<void(lang::meta::Node_T)> f);

void visit_lang_meta_Node(lang::meta::Node::AttrMatchCasePattern::Wildcard_T x, function<void(lang::meta::Node_T)> f);

void visit_lang_meta_Node(lang::meta::Node::AttrMatchCasePattern_T x, function<void(lang::meta::Node_T)> f);

void visit_lang_meta_Node(lang::meta::Node::AttrMatchCase_T x, function<void(lang::meta::Node_T)> f);

void visit_lang_meta_Node(lang::meta::Node::AttrClause::Match_T x, function<void(lang::meta::Node_T)> f);

void visit_lang_meta_Node(lang::meta::Node::AttrClause_T x, function<void(lang::meta::Node_T)> f);

void visit_lang_meta_Node(lang::meta::Node::ParserDecl::Attr_T x, function<void(lang::meta::Node_T)> f);

void visit_lang_meta_Node(lang::meta::Node::ParserDecl::Rule::op::DEF_T x, function<void(lang::meta::Node_T)> f);

void visit_lang_meta_Node(lang::meta::Node::ParserDecl::Rule::op::DEF_ALIAS_T x, function<void(lang::meta::Node_T)> f);

void visit_lang_meta_Node(lang::meta::Node::ParserDecl::Rule::op_T x, function<void(lang::meta::Node_T)> f);

void visit_lang_meta_Node(lang::meta::Node::ParserDecl::Rule_T x, function<void(lang::meta::Node_T)> f);

void visit_lang_meta_Node(lang::meta::Node::ParserDecl_T x, function<void(lang::meta::Node_T)> f);

void visit_lang_meta_Node(lang::meta::Node::Stanza::Parser_T x, function<void(lang::meta::Node_T)> f);

void visit_lang_meta_Node(lang::meta::Node::TestCase_T x, function<void(lang::meta::Node_T)> f);

void visit_lang_meta_Node(lang::meta::Node::Stanza::Test_T x, function<void(lang::meta::Node_T)> f);

void visit_lang_meta_Node(lang::meta::Node::CompileTestCase_T x, function<void(lang::meta::Node_T)> f);

void visit_lang_meta_Node(lang::meta::Node::Stanza::CompileTest_T x, function<void(lang::meta::Node_T)> f);

void visit_lang_meta_Node(lang::meta::Node::Stanza_T x, function<void(lang::meta::Node_T)> f);

void visit_lang_meta_Node(lang::meta::Node::Lang_T x, function<void(lang::meta::Node_T)> f);

void visit_lang_meta_Node(lang::meta::Node_T x, function<void(lang::meta::Node_T)> f);

lang::meta::Node_T xformT_lang_meta_Node(lang::meta::Node::TokenDecl::op::DEF_T x, function<lang::meta::Node_T(lang::meta::Node_T)> f);

lang::meta::Node_T xformT_lang_meta_Node(lang::meta::Node::TokenDecl::op::DEF_ALIAS_T x, function<lang::meta::Node_T(lang::meta::Node_T)> f);

lang::meta::Node_T xformT_lang_meta_Node(lang::meta::Node::TokenDecl::op_T x, function<lang::meta::Node_T(lang::meta::Node_T)> f);

lang::meta::Node_T xformT_lang_meta_Node(lang::meta::Node::Id_T x, function<lang::meta::Node_T(lang::meta::Node_T)> f);

lang::meta::Node_T xformT_lang_meta_Node(lang::meta::Node::ParseExpr::Id_T x, function<lang::meta::Node_T(lang::meta::Node_T)> f);

lang::meta::Node_T xformT_lang_meta_Node(lang::meta::Node::ParseExpr::Eof_T x, function<lang::meta::Node_T(lang::meta::Node_T)> f);

lang::meta::Node_T xformT_lang_meta_Node(lang::meta::Node::ParseExpr::False_T x, function<lang::meta::Node_T(lang::meta::Node_T)> f);

lang::meta::Node_T xformT_lang_meta_Node(lang::meta::Node::ParseExpr::Eps_T x, function<lang::meta::Node_T(lang::meta::Node_T)> f);

lang::meta::Node_T xformT_lang_meta_Node(lang::meta::Node::ParseExpr::Indent_T x, function<lang::meta::Node_T(lang::meta::Node_T)> f);

lang::meta::Node_T xformT_lang_meta_Node(lang::meta::Node::ParseExpr::Dedent_T x, function<lang::meta::Node_T(lang::meta::Node_T)> f);

lang::meta::Node_T xformT_lang_meta_Node(lang::meta::Node::ParseExpr::Newline_T x, function<lang::meta::Node_T(lang::meta::Node_T)> f);

lang::meta::Node_T xformT_lang_meta_Node(lang::meta::Node::ParseExpr::UnicodeAny_T x, function<lang::meta::Node_T(lang::meta::Node_T)> f);

lang::meta::Node_T xformT_lang_meta_Node(lang::meta::Node::ParseExpr::AsciiBaseAny_T x, function<lang::meta::Node_T(lang::meta::Node_T)> f);

lang::meta::Node_T xformT_lang_meta_Node(lang::meta::Node::ParseExpr::Alt_T x, function<lang::meta::Node_T(lang::meta::Node_T)> f);

lang::meta::Node_T xformT_lang_meta_Node(lang::meta::Node::ParseExpr::AltExplicit_T x, function<lang::meta::Node_T(lang::meta::Node_T)> f);

lang::meta::Node_T xformT_lang_meta_Node(lang::meta::Node::ParseExpr::Minus_T x, function<lang::meta::Node_T(lang::meta::Node_T)> f);

lang::meta::Node_T xformT_lang_meta_Node(lang::meta::Node::ParseExpr::Concat_T x, function<lang::meta::Node_T(lang::meta::Node_T)> f);

lang::meta::Node_T xformT_lang_meta_Node(lang::meta::Node::ParseExpr::Optional_T x, function<lang::meta::Node_T(lang::meta::Node_T)> f);

lang::meta::Node_T xformT_lang_meta_Node(lang::meta::Node::ParseExpr::Rep_T x, function<lang::meta::Node_T(lang::meta::Node_T)> f);

lang::meta::Node_T xformT_lang_meta_Node(lang::meta::Node::ParseExpr::RepNonzero_T x, function<lang::meta::Node_T(lang::meta::Node_T)> f);

lang::meta::Node_T xformT_lang_meta_Node(lang::meta::Node::ParseExpr::RepCount_T x, function<lang::meta::Node_T(lang::meta::Node_T)> f);

lang::meta::Node_T xformT_lang_meta_Node(lang::meta::Node::ParseExpr::CharRange_T x, function<lang::meta::Node_T(lang::meta::Node_T)> f);

lang::meta::Node_T xformT_lang_meta_Node(lang::meta::Node::ParseExpr::StrLit_T x, function<lang::meta::Node_T(lang::meta::Node_T)> f);

lang::meta::Node_T xformT_lang_meta_Node(lang::meta::Node::ParseExpr::Underscore_T x, function<lang::meta::Node_T(lang::meta::Node_T)> f);

lang::meta::Node_T xformT_lang_meta_Node(lang::meta::Node::ParseExpr::Pass_T x, function<lang::meta::Node_T(lang::meta::Node_T)> f);

lang::meta::Node_T xformT_lang_meta_Node(lang::meta::Node::ParseExpr::Paren_T x, function<lang::meta::Node_T(lang::meta::Node_T)> f);

lang::meta::Node_T xformT_lang_meta_Node(lang::meta::Node::ParseExpr::Name_T x, function<lang::meta::Node_T(lang::meta::Node_T)> f);

lang::meta::Node_T xformT_lang_meta_Node(lang::meta::Node::ParseExprListType::List_T x, function<lang::meta::Node_T(lang::meta::Node_T)> f);

lang::meta::Node_T xformT_lang_meta_Node(lang::meta::Node::ParseExprListType::Block_T x, function<lang::meta::Node_T(lang::meta::Node_T)> f);

lang::meta::Node_T xformT_lang_meta_Node(lang::meta::Node::ParseExprListType::Block2_T x, function<lang::meta::Node_T(lang::meta::Node_T)> f);

lang::meta::Node_T xformT_lang_meta_Node(lang::meta::Node::ParseExprListType::Top_T x, function<lang::meta::Node_T(lang::meta::Node_T)> f);

lang::meta::Node_T xformT_lang_meta_Node(lang::meta::Node::ParseExprListType::Top2_T x, function<lang::meta::Node_T(lang::meta::Node_T)> f);

lang::meta::Node_T xformT_lang_meta_Node(lang::meta::Node::ParseExprListType_T x, function<lang::meta::Node_T(lang::meta::Node_T)> f);

lang::meta::Node_T xformT_lang_meta_Node(lang::meta::Node::ParseExprListNum::Ge0_T x, function<lang::meta::Node_T(lang::meta::Node_T)> f);

lang::meta::Node_T xformT_lang_meta_Node(lang::meta::Node::ParseExprListNum::Ge1_T x, function<lang::meta::Node_T(lang::meta::Node_T)> f);

lang::meta::Node_T xformT_lang_meta_Node(lang::meta::Node::ParseExprListNum::Ge2_T x, function<lang::meta::Node_T(lang::meta::Node_T)> f);

lang::meta::Node_T xformT_lang_meta_Node(lang::meta::Node::ParseExprListNum_T x, function<lang::meta::Node_T(lang::meta::Node_T)> f);

lang::meta::Node_T xformT_lang_meta_Node(lang::meta::Node::ParseExpr::List::end_delim::NONE_T x, function<lang::meta::Node_T(lang::meta::Node_T)> f);

lang::meta::Node_T xformT_lang_meta_Node(lang::meta::Node::ParseExpr::List::end_delim::OPTIONAL_T x, function<lang::meta::Node_T(lang::meta::Node_T)> f);

lang::meta::Node_T xformT_lang_meta_Node(lang::meta::Node::ParseExpr::List::end_delim::SOME_T x, function<lang::meta::Node_T(lang::meta::Node_T)> f);

lang::meta::Node_T xformT_lang_meta_Node(lang::meta::Node::ParseExpr::List::end_delim_T x, function<lang::meta::Node_T(lang::meta::Node_T)> f);

lang::meta::Node_T xformT_lang_meta_Node(lang::meta::Node::ParseExpr::List_T x, function<lang::meta::Node_T(lang::meta::Node_T)> f);

lang::meta::Node_T xformT_lang_meta_Node(lang::meta::Node::ParseExpr::Unfold_T x, function<lang::meta::Node_T(lang::meta::Node_T)> f);

lang::meta::Node_T xformT_lang_meta_Node(lang::meta::Node::AttrReq::Base_T x, function<lang::meta::Node_T(lang::meta::Node_T)> f);

lang::meta::Node_T xformT_lang_meta_Node(lang::meta::Node::AttrReq::PrecStar_T x, function<lang::meta::Node_T(lang::meta::Node_T)> f);

lang::meta::Node_T xformT_lang_meta_Node(lang::meta::Node::AttrReq_T x, function<lang::meta::Node_T(lang::meta::Node_T)> f);

lang::meta::Node_T xformT_lang_meta_Node(lang::meta::Node::ParseExpr::AttrReq_T x, function<lang::meta::Node_T(lang::meta::Node_T)> f);

lang::meta::Node_T xformT_lang_meta_Node(lang::meta::Node::ParseExpr_T x, function<lang::meta::Node_T(lang::meta::Node_T)> f);

lang::meta::Node_T xformT_lang_meta_Node(lang::meta::Node::TokenDecl_T x, function<lang::meta::Node_T(lang::meta::Node_T)> f);

lang::meta::Node_T xformT_lang_meta_Node(lang::meta::Node::Stanza::Tokens_T x, function<lang::meta::Node_T(lang::meta::Node_T)> f);

lang::meta::Node_T xformT_lang_meta_Node(lang::meta::Node::LexerDecl::Main_T x, function<lang::meta::Node_T(lang::meta::Node_T)> f);

lang::meta::Node_T xformT_lang_meta_Node(lang::meta::Node::LexerInstr::Emit_T x, function<lang::meta::Node_T(lang::meta::Node_T)> f);

lang::meta::Node_T xformT_lang_meta_Node(lang::meta::Node::LexerInstr::Pass_T x, function<lang::meta::Node_T(lang::meta::Node_T)> f);

lang::meta::Node_T xformT_lang_meta_Node(lang::meta::Node::LexerInstr::Push_T x, function<lang::meta::Node_T(lang::meta::Node_T)> f);

lang::meta::Node_T xformT_lang_meta_Node(lang::meta::Node::LexerInstr::Pop_T x, function<lang::meta::Node_T(lang::meta::Node_T)> f);

lang::meta::Node_T xformT_lang_meta_Node(lang::meta::Node::LexerInstr::PopExtract_T x, function<lang::meta::Node_T(lang::meta::Node_T)> f);

lang::meta::Node_T xformT_lang_meta_Node(lang::meta::Node::LexerInstr::PopEmit_T x, function<lang::meta::Node_T(lang::meta::Node_T)> f);

lang::meta::Node_T xformT_lang_meta_Node(lang::meta::Node::LexerInstr::MatchHistory_T x, function<lang::meta::Node_T(lang::meta::Node_T)> f);

lang::meta::Node_T xformT_lang_meta_Node(lang::meta::Node::LexerInstr_T x, function<lang::meta::Node_T(lang::meta::Node_T)> f);

lang::meta::Node_T xformT_lang_meta_Node(lang::meta::Node::LexerModeCase_T x, function<lang::meta::Node_T(lang::meta::Node_T)> f);

lang::meta::Node_T xformT_lang_meta_Node(lang::meta::Node::LexerDecl::Mode_T x, function<lang::meta::Node_T(lang::meta::Node_T)> f);

lang::meta::Node_T xformT_lang_meta_Node(lang::meta::Node::LexerDecl_T x, function<lang::meta::Node_T(lang::meta::Node_T)> f);

lang::meta::Node_T xformT_lang_meta_Node(lang::meta::Node::Stanza::Lexer_T x, function<lang::meta::Node_T(lang::meta::Node_T)> f);

lang::meta::Node_T xformT_lang_meta_Node(lang::meta::Node::ParserDecl::Main_T x, function<lang::meta::Node_T(lang::meta::Node_T)> f);

lang::meta::Node_T xformT_lang_meta_Node(lang::meta::Node::ParserProp::NameStrict_T x, function<lang::meta::Node_T(lang::meta::Node_T)> f);

lang::meta::Node_T xformT_lang_meta_Node(lang::meta::Node::ParserProp::LRSpec_T x, function<lang::meta::Node_T(lang::meta::Node_T)> f);

lang::meta::Node_T xformT_lang_meta_Node(lang::meta::Node::ParserProp::Err__T x, function<lang::meta::Node_T(lang::meta::Node_T)> f);

lang::meta::Node_T xformT_lang_meta_Node(lang::meta::Node::ParserProp_T x, function<lang::meta::Node_T(lang::meta::Node_T)> f);

lang::meta::Node_T xformT_lang_meta_Node(lang::meta::Node::ParserDecl::Prop_T x, function<lang::meta::Node_T(lang::meta::Node_T)> f);

lang::meta::Node_T xformT_lang_meta_Node(lang::meta::Node::PrecAssoc::Left_T x, function<lang::meta::Node_T(lang::meta::Node_T)> f);

lang::meta::Node_T xformT_lang_meta_Node(lang::meta::Node::PrecAssoc::Right_T x, function<lang::meta::Node_T(lang::meta::Node_T)> f);

lang::meta::Node_T xformT_lang_meta_Node(lang::meta::Node::PrecAssoc::Prefix_T x, function<lang::meta::Node_T(lang::meta::Node_T)> f);

lang::meta::Node_T xformT_lang_meta_Node(lang::meta::Node::PrecAssoc::Postfix_T x, function<lang::meta::Node_T(lang::meta::Node_T)> f);

lang::meta::Node_T xformT_lang_meta_Node(lang::meta::Node::PrecAssoc_T x, function<lang::meta::Node_T(lang::meta::Node_T)> f);

lang::meta::Node_T xformT_lang_meta_Node(lang::meta::Node::PrecItem_T x, function<lang::meta::Node_T(lang::meta::Node_T)> f);

lang::meta::Node_T xformT_lang_meta_Node(lang::meta::Node::ParserDecl::Prec_T x, function<lang::meta::Node_T(lang::meta::Node_T)> f);

lang::meta::Node_T xformT_lang_meta_Node(lang::meta::Node::AttrClauseExpr::LhsGeq_T x, function<lang::meta::Node_T(lang::meta::Node_T)> f);

lang::meta::Node_T xformT_lang_meta_Node(lang::meta::Node::AttrClauseExprRhsLoc::All_T x, function<lang::meta::Node_T(lang::meta::Node_T)> f);

lang::meta::Node_T xformT_lang_meta_Node(lang::meta::Node::AttrClauseExprRhsLoc::Begin_T x, function<lang::meta::Node_T(lang::meta::Node_T)> f);

lang::meta::Node_T xformT_lang_meta_Node(lang::meta::Node::AttrClauseExprRhsLoc::Mid_T x, function<lang::meta::Node_T(lang::meta::Node_T)> f);

lang::meta::Node_T xformT_lang_meta_Node(lang::meta::Node::AttrClauseExprRhsLoc::End_T x, function<lang::meta::Node_T(lang::meta::Node_T)> f);

lang::meta::Node_T xformT_lang_meta_Node(lang::meta::Node::AttrClauseExprRhsLoc_T x, function<lang::meta::Node_T(lang::meta::Node_T)> f);

lang::meta::Node_T xformT_lang_meta_Node(lang::meta::Node::AttrClauseExpr::RhsGeq_T x, function<lang::meta::Node_T(lang::meta::Node_T)> f);

lang::meta::Node_T xformT_lang_meta_Node(lang::meta::Node::AttrClauseExpr::Implies_T x, function<lang::meta::Node_T(lang::meta::Node_T)> f);

lang::meta::Node_T xformT_lang_meta_Node(lang::meta::Node::AttrClauseExpr_T x, function<lang::meta::Node_T(lang::meta::Node_T)> f);

lang::meta::Node_T xformT_lang_meta_Node(lang::meta::Node::AttrClause::Expr_T x, function<lang::meta::Node_T(lang::meta::Node_T)> f);

lang::meta::Node_T xformT_lang_meta_Node(lang::meta::Node::AttrClause::Block_T x, function<lang::meta::Node_T(lang::meta::Node_T)> f);

lang::meta::Node_T xformT_lang_meta_Node(lang::meta::Node::AttrMatchCasePattern::Alt_T x, function<lang::meta::Node_T(lang::meta::Node_T)> f);

lang::meta::Node_T xformT_lang_meta_Node(lang::meta::Node::AttrMatchCasePattern::Wildcard_T x, function<lang::meta::Node_T(lang::meta::Node_T)> f);

lang::meta::Node_T xformT_lang_meta_Node(lang::meta::Node::AttrMatchCasePattern_T x, function<lang::meta::Node_T(lang::meta::Node_T)> f);

lang::meta::Node_T xformT_lang_meta_Node(lang::meta::Node::AttrMatchCase_T x, function<lang::meta::Node_T(lang::meta::Node_T)> f);

lang::meta::Node_T xformT_lang_meta_Node(lang::meta::Node::AttrClause::Match_T x, function<lang::meta::Node_T(lang::meta::Node_T)> f);

lang::meta::Node_T xformT_lang_meta_Node(lang::meta::Node::AttrClause_T x, function<lang::meta::Node_T(lang::meta::Node_T)> f);

lang::meta::Node_T xformT_lang_meta_Node(lang::meta::Node::ParserDecl::Attr_T x, function<lang::meta::Node_T(lang::meta::Node_T)> f);

lang::meta::Node_T xformT_lang_meta_Node(lang::meta::Node::ParserDecl::Rule::op::DEF_T x, function<lang::meta::Node_T(lang::meta::Node_T)> f);

lang::meta::Node_T xformT_lang_meta_Node(lang::meta::Node::ParserDecl::Rule::op::DEF_ALIAS_T x, function<lang::meta::Node_T(lang::meta::Node_T)> f);

lang::meta::Node_T xformT_lang_meta_Node(lang::meta::Node::ParserDecl::Rule::op_T x, function<lang::meta::Node_T(lang::meta::Node_T)> f);

lang::meta::Node_T xformT_lang_meta_Node(lang::meta::Node::ParserDecl::Rule_T x, function<lang::meta::Node_T(lang::meta::Node_T)> f);

lang::meta::Node_T xformT_lang_meta_Node(lang::meta::Node::ParserDecl_T x, function<lang::meta::Node_T(lang::meta::Node_T)> f);

lang::meta::Node_T xformT_lang_meta_Node(lang::meta::Node::Stanza::Parser_T x, function<lang::meta::Node_T(lang::meta::Node_T)> f);

lang::meta::Node_T xformT_lang_meta_Node(lang::meta::Node::TestCase_T x, function<lang::meta::Node_T(lang::meta::Node_T)> f);

lang::meta::Node_T xformT_lang_meta_Node(lang::meta::Node::Stanza::Test_T x, function<lang::meta::Node_T(lang::meta::Node_T)> f);

lang::meta::Node_T xformT_lang_meta_Node(lang::meta::Node::CompileTestCase_T x, function<lang::meta::Node_T(lang::meta::Node_T)> f);

lang::meta::Node_T xformT_lang_meta_Node(lang::meta::Node::Stanza::CompileTest_T x, function<lang::meta::Node_T(lang::meta::Node_T)> f);

lang::meta::Node_T xformT_lang_meta_Node(lang::meta::Node::Stanza_T x, function<lang::meta::Node_T(lang::meta::Node_T)> f);

lang::meta::Node_T xformT_lang_meta_Node(lang::meta::Node::Lang_T x, function<lang::meta::Node_T(lang::meta::Node_T)> f);

lang::meta::Node_T xformT_lang_meta_Node(lang::meta::Node_T x, function<lang::meta::Node_T(lang::meta::Node_T)> f);

lang::meta::Node_T xform_lang_meta_Node(lang::meta::Node_T x, function<lang::meta::Node_T(lang::meta::Node_T)> f);

lang::meta::Node::Lang_T xform_lang_meta_Node(lang::meta::Node::Lang_T x, function<lang::meta::Node_T(lang::meta::Node_T)> f);

lang::meta::Node::Stanza_T xform_lang_meta_Node(lang::meta::Node::Stanza_T x, function<lang::meta::Node_T(lang::meta::Node_T)> f);

lang::meta::Node::Stanza::Tokens_T xform_lang_meta_Node(lang::meta::Node::Stanza::Tokens_T x, function<lang::meta::Node_T(lang::meta::Node_T)> f);

lang::meta::Node::TokenDecl_T xform_lang_meta_Node(lang::meta::Node::TokenDecl_T x, function<lang::meta::Node_T(lang::meta::Node_T)> f);

lang::meta::Node::TokenDecl::op_T xform_lang_meta_Node(lang::meta::Node::TokenDecl::op_T x, function<lang::meta::Node_T(lang::meta::Node_T)> f);

lang::meta::Node::TokenDecl::op::DEF_T xform_lang_meta_Node(lang::meta::Node::TokenDecl::op::DEF_T x, function<lang::meta::Node_T(lang::meta::Node_T)> f);

lang::meta::Node::TokenDecl::op::DEF_ALIAS_T xform_lang_meta_Node(lang::meta::Node::TokenDecl::op::DEF_ALIAS_T x, function<lang::meta::Node_T(lang::meta::Node_T)> f);

lang::meta::Node::ParseExpr_T xform_lang_meta_Node(lang::meta::Node::ParseExpr_T x, function<lang::meta::Node_T(lang::meta::Node_T)> f);

lang::meta::Node::ParseExpr::Id_T xform_lang_meta_Node(lang::meta::Node::ParseExpr::Id_T x, function<lang::meta::Node_T(lang::meta::Node_T)> f);

lang::meta::Node::Id_T xform_lang_meta_Node(lang::meta::Node::Id_T x, function<lang::meta::Node_T(lang::meta::Node_T)> f);

lang::meta::Node::ParseExpr::Eof_T xform_lang_meta_Node(lang::meta::Node::ParseExpr::Eof_T x, function<lang::meta::Node_T(lang::meta::Node_T)> f);

lang::meta::Node::ParseExpr::False_T xform_lang_meta_Node(lang::meta::Node::ParseExpr::False_T x, function<lang::meta::Node_T(lang::meta::Node_T)> f);

lang::meta::Node::ParseExpr::Eps_T xform_lang_meta_Node(lang::meta::Node::ParseExpr::Eps_T x, function<lang::meta::Node_T(lang::meta::Node_T)> f);

lang::meta::Node::ParseExpr::Indent_T xform_lang_meta_Node(lang::meta::Node::ParseExpr::Indent_T x, function<lang::meta::Node_T(lang::meta::Node_T)> f);

lang::meta::Node::ParseExpr::Dedent_T xform_lang_meta_Node(lang::meta::Node::ParseExpr::Dedent_T x, function<lang::meta::Node_T(lang::meta::Node_T)> f);

lang::meta::Node::ParseExpr::Newline_T xform_lang_meta_Node(lang::meta::Node::ParseExpr::Newline_T x, function<lang::meta::Node_T(lang::meta::Node_T)> f);

lang::meta::Node::ParseExpr::UnicodeAny_T xform_lang_meta_Node(lang::meta::Node::ParseExpr::UnicodeAny_T x, function<lang::meta::Node_T(lang::meta::Node_T)> f);

lang::meta::Node::ParseExpr::AsciiBaseAny_T xform_lang_meta_Node(lang::meta::Node::ParseExpr::AsciiBaseAny_T x, function<lang::meta::Node_T(lang::meta::Node_T)> f);

lang::meta::Node::ParseExpr::Alt_T xform_lang_meta_Node(lang::meta::Node::ParseExpr::Alt_T x, function<lang::meta::Node_T(lang::meta::Node_T)> f);

lang::meta::Node::ParseExpr::AltExplicit_T xform_lang_meta_Node(lang::meta::Node::ParseExpr::AltExplicit_T x, function<lang::meta::Node_T(lang::meta::Node_T)> f);

lang::meta::Node::ParseExpr::Minus_T xform_lang_meta_Node(lang::meta::Node::ParseExpr::Minus_T x, function<lang::meta::Node_T(lang::meta::Node_T)> f);

lang::meta::Node::ParseExpr::Concat_T xform_lang_meta_Node(lang::meta::Node::ParseExpr::Concat_T x, function<lang::meta::Node_T(lang::meta::Node_T)> f);

lang::meta::Node::ParseExpr::Optional_T xform_lang_meta_Node(lang::meta::Node::ParseExpr::Optional_T x, function<lang::meta::Node_T(lang::meta::Node_T)> f);

lang::meta::Node::ParseExpr::Rep_T xform_lang_meta_Node(lang::meta::Node::ParseExpr::Rep_T x, function<lang::meta::Node_T(lang::meta::Node_T)> f);

lang::meta::Node::ParseExpr::RepNonzero_T xform_lang_meta_Node(lang::meta::Node::ParseExpr::RepNonzero_T x, function<lang::meta::Node_T(lang::meta::Node_T)> f);

lang::meta::Node::ParseExpr::RepCount_T xform_lang_meta_Node(lang::meta::Node::ParseExpr::RepCount_T x, function<lang::meta::Node_T(lang::meta::Node_T)> f);

lang::meta::Node::ParseExpr::CharRange_T xform_lang_meta_Node(lang::meta::Node::ParseExpr::CharRange_T x, function<lang::meta::Node_T(lang::meta::Node_T)> f);

lang::meta::Node::ParseExpr::StrLit_T xform_lang_meta_Node(lang::meta::Node::ParseExpr::StrLit_T x, function<lang::meta::Node_T(lang::meta::Node_T)> f);

lang::meta::Node::ParseExpr::Underscore_T xform_lang_meta_Node(lang::meta::Node::ParseExpr::Underscore_T x, function<lang::meta::Node_T(lang::meta::Node_T)> f);

lang::meta::Node::ParseExpr::Pass_T xform_lang_meta_Node(lang::meta::Node::ParseExpr::Pass_T x, function<lang::meta::Node_T(lang::meta::Node_T)> f);

lang::meta::Node::ParseExpr::Paren_T xform_lang_meta_Node(lang::meta::Node::ParseExpr::Paren_T x, function<lang::meta::Node_T(lang::meta::Node_T)> f);

lang::meta::Node::ParseExpr::Name_T xform_lang_meta_Node(lang::meta::Node::ParseExpr::Name_T x, function<lang::meta::Node_T(lang::meta::Node_T)> f);

lang::meta::Node::ParseExpr::List_T xform_lang_meta_Node(lang::meta::Node::ParseExpr::List_T x, function<lang::meta::Node_T(lang::meta::Node_T)> f);

lang::meta::Node::ParseExprListType_T xform_lang_meta_Node(lang::meta::Node::ParseExprListType_T x, function<lang::meta::Node_T(lang::meta::Node_T)> f);

lang::meta::Node::ParseExprListType::List_T xform_lang_meta_Node(lang::meta::Node::ParseExprListType::List_T x, function<lang::meta::Node_T(lang::meta::Node_T)> f);

lang::meta::Node::ParseExprListType::Block_T xform_lang_meta_Node(lang::meta::Node::ParseExprListType::Block_T x, function<lang::meta::Node_T(lang::meta::Node_T)> f);

lang::meta::Node::ParseExprListType::Block2_T xform_lang_meta_Node(lang::meta::Node::ParseExprListType::Block2_T x, function<lang::meta::Node_T(lang::meta::Node_T)> f);

lang::meta::Node::ParseExprListType::Top_T xform_lang_meta_Node(lang::meta::Node::ParseExprListType::Top_T x, function<lang::meta::Node_T(lang::meta::Node_T)> f);

lang::meta::Node::ParseExprListType::Top2_T xform_lang_meta_Node(lang::meta::Node::ParseExprListType::Top2_T x, function<lang::meta::Node_T(lang::meta::Node_T)> f);

lang::meta::Node::ParseExprListNum_T xform_lang_meta_Node(lang::meta::Node::ParseExprListNum_T x, function<lang::meta::Node_T(lang::meta::Node_T)> f);

lang::meta::Node::ParseExprListNum::Ge0_T xform_lang_meta_Node(lang::meta::Node::ParseExprListNum::Ge0_T x, function<lang::meta::Node_T(lang::meta::Node_T)> f);

lang::meta::Node::ParseExprListNum::Ge1_T xform_lang_meta_Node(lang::meta::Node::ParseExprListNum::Ge1_T x, function<lang::meta::Node_T(lang::meta::Node_T)> f);

lang::meta::Node::ParseExprListNum::Ge2_T xform_lang_meta_Node(lang::meta::Node::ParseExprListNum::Ge2_T x, function<lang::meta::Node_T(lang::meta::Node_T)> f);

lang::meta::Node::ParseExpr::List::end_delim_T xform_lang_meta_Node(lang::meta::Node::ParseExpr::List::end_delim_T x, function<lang::meta::Node_T(lang::meta::Node_T)> f);

lang::meta::Node::ParseExpr::List::end_delim::NONE_T xform_lang_meta_Node(lang::meta::Node::ParseExpr::List::end_delim::NONE_T x, function<lang::meta::Node_T(lang::meta::Node_T)> f);

lang::meta::Node::ParseExpr::List::end_delim::OPTIONAL_T xform_lang_meta_Node(lang::meta::Node::ParseExpr::List::end_delim::OPTIONAL_T x, function<lang::meta::Node_T(lang::meta::Node_T)> f);

lang::meta::Node::ParseExpr::List::end_delim::SOME_T xform_lang_meta_Node(lang::meta::Node::ParseExpr::List::end_delim::SOME_T x, function<lang::meta::Node_T(lang::meta::Node_T)> f);

lang::meta::Node::ParseExpr::Unfold_T xform_lang_meta_Node(lang::meta::Node::ParseExpr::Unfold_T x, function<lang::meta::Node_T(lang::meta::Node_T)> f);

lang::meta::Node::ParseExpr::AttrReq_T xform_lang_meta_Node(lang::meta::Node::ParseExpr::AttrReq_T x, function<lang::meta::Node_T(lang::meta::Node_T)> f);

lang::meta::Node::AttrReq_T xform_lang_meta_Node(lang::meta::Node::AttrReq_T x, function<lang::meta::Node_T(lang::meta::Node_T)> f);

lang::meta::Node::AttrReq::Base_T xform_lang_meta_Node(lang::meta::Node::AttrReq::Base_T x, function<lang::meta::Node_T(lang::meta::Node_T)> f);

lang::meta::Node::AttrReq::PrecStar_T xform_lang_meta_Node(lang::meta::Node::AttrReq::PrecStar_T x, function<lang::meta::Node_T(lang::meta::Node_T)> f);

lang::meta::Node::Stanza::Lexer_T xform_lang_meta_Node(lang::meta::Node::Stanza::Lexer_T x, function<lang::meta::Node_T(lang::meta::Node_T)> f);

lang::meta::Node::LexerDecl_T xform_lang_meta_Node(lang::meta::Node::LexerDecl_T x, function<lang::meta::Node_T(lang::meta::Node_T)> f);

lang::meta::Node::LexerDecl::Main_T xform_lang_meta_Node(lang::meta::Node::LexerDecl::Main_T x, function<lang::meta::Node_T(lang::meta::Node_T)> f);

lang::meta::Node::LexerDecl::Mode_T xform_lang_meta_Node(lang::meta::Node::LexerDecl::Mode_T x, function<lang::meta::Node_T(lang::meta::Node_T)> f);

lang::meta::Node::LexerModeCase_T xform_lang_meta_Node(lang::meta::Node::LexerModeCase_T x, function<lang::meta::Node_T(lang::meta::Node_T)> f);

lang::meta::Node::LexerInstr_T xform_lang_meta_Node(lang::meta::Node::LexerInstr_T x, function<lang::meta::Node_T(lang::meta::Node_T)> f);

lang::meta::Node::LexerInstr::Emit_T xform_lang_meta_Node(lang::meta::Node::LexerInstr::Emit_T x, function<lang::meta::Node_T(lang::meta::Node_T)> f);

lang::meta::Node::LexerInstr::Pass_T xform_lang_meta_Node(lang::meta::Node::LexerInstr::Pass_T x, function<lang::meta::Node_T(lang::meta::Node_T)> f);

lang::meta::Node::LexerInstr::Push_T xform_lang_meta_Node(lang::meta::Node::LexerInstr::Push_T x, function<lang::meta::Node_T(lang::meta::Node_T)> f);

lang::meta::Node::LexerInstr::Pop_T xform_lang_meta_Node(lang::meta::Node::LexerInstr::Pop_T x, function<lang::meta::Node_T(lang::meta::Node_T)> f);

lang::meta::Node::LexerInstr::PopExtract_T xform_lang_meta_Node(lang::meta::Node::LexerInstr::PopExtract_T x, function<lang::meta::Node_T(lang::meta::Node_T)> f);

lang::meta::Node::LexerInstr::PopEmit_T xform_lang_meta_Node(lang::meta::Node::LexerInstr::PopEmit_T x, function<lang::meta::Node_T(lang::meta::Node_T)> f);

lang::meta::Node::LexerInstr::MatchHistory_T xform_lang_meta_Node(lang::meta::Node::LexerInstr::MatchHistory_T x, function<lang::meta::Node_T(lang::meta::Node_T)> f);

lang::meta::Node::Stanza::Parser_T xform_lang_meta_Node(lang::meta::Node::Stanza::Parser_T x, function<lang::meta::Node_T(lang::meta::Node_T)> f);

lang::meta::Node::ParserDecl_T xform_lang_meta_Node(lang::meta::Node::ParserDecl_T x, function<lang::meta::Node_T(lang::meta::Node_T)> f);

lang::meta::Node::ParserDecl::Main_T xform_lang_meta_Node(lang::meta::Node::ParserDecl::Main_T x, function<lang::meta::Node_T(lang::meta::Node_T)> f);

lang::meta::Node::ParserDecl::Prop_T xform_lang_meta_Node(lang::meta::Node::ParserDecl::Prop_T x, function<lang::meta::Node_T(lang::meta::Node_T)> f);

lang::meta::Node::ParserProp_T xform_lang_meta_Node(lang::meta::Node::ParserProp_T x, function<lang::meta::Node_T(lang::meta::Node_T)> f);

lang::meta::Node::ParserProp::NameStrict_T xform_lang_meta_Node(lang::meta::Node::ParserProp::NameStrict_T x, function<lang::meta::Node_T(lang::meta::Node_T)> f);

lang::meta::Node::ParserProp::LRSpec_T xform_lang_meta_Node(lang::meta::Node::ParserProp::LRSpec_T x, function<lang::meta::Node_T(lang::meta::Node_T)> f);

lang::meta::Node::ParserProp::Err__T xform_lang_meta_Node(lang::meta::Node::ParserProp::Err__T x, function<lang::meta::Node_T(lang::meta::Node_T)> f);

lang::meta::Node::ParserDecl::Prec_T xform_lang_meta_Node(lang::meta::Node::ParserDecl::Prec_T x, function<lang::meta::Node_T(lang::meta::Node_T)> f);

lang::meta::Node::PrecItem_T xform_lang_meta_Node(lang::meta::Node::PrecItem_T x, function<lang::meta::Node_T(lang::meta::Node_T)> f);

lang::meta::Node::PrecAssoc_T xform_lang_meta_Node(lang::meta::Node::PrecAssoc_T x, function<lang::meta::Node_T(lang::meta::Node_T)> f);

lang::meta::Node::PrecAssoc::Left_T xform_lang_meta_Node(lang::meta::Node::PrecAssoc::Left_T x, function<lang::meta::Node_T(lang::meta::Node_T)> f);

lang::meta::Node::PrecAssoc::Right_T xform_lang_meta_Node(lang::meta::Node::PrecAssoc::Right_T x, function<lang::meta::Node_T(lang::meta::Node_T)> f);

lang::meta::Node::PrecAssoc::Prefix_T xform_lang_meta_Node(lang::meta::Node::PrecAssoc::Prefix_T x, function<lang::meta::Node_T(lang::meta::Node_T)> f);

lang::meta::Node::PrecAssoc::Postfix_T xform_lang_meta_Node(lang::meta::Node::PrecAssoc::Postfix_T x, function<lang::meta::Node_T(lang::meta::Node_T)> f);

lang::meta::Node::ParserDecl::Attr_T xform_lang_meta_Node(lang::meta::Node::ParserDecl::Attr_T x, function<lang::meta::Node_T(lang::meta::Node_T)> f);

lang::meta::Node::AttrClause_T xform_lang_meta_Node(lang::meta::Node::AttrClause_T x, function<lang::meta::Node_T(lang::meta::Node_T)> f);

lang::meta::Node::AttrClause::Expr_T xform_lang_meta_Node(lang::meta::Node::AttrClause::Expr_T x, function<lang::meta::Node_T(lang::meta::Node_T)> f);

lang::meta::Node::AttrClauseExpr_T xform_lang_meta_Node(lang::meta::Node::AttrClauseExpr_T x, function<lang::meta::Node_T(lang::meta::Node_T)> f);

lang::meta::Node::AttrClauseExpr::LhsGeq_T xform_lang_meta_Node(lang::meta::Node::AttrClauseExpr::LhsGeq_T x, function<lang::meta::Node_T(lang::meta::Node_T)> f);

lang::meta::Node::AttrClauseExpr::RhsGeq_T xform_lang_meta_Node(lang::meta::Node::AttrClauseExpr::RhsGeq_T x, function<lang::meta::Node_T(lang::meta::Node_T)> f);

lang::meta::Node::AttrClauseExprRhsLoc_T xform_lang_meta_Node(lang::meta::Node::AttrClauseExprRhsLoc_T x, function<lang::meta::Node_T(lang::meta::Node_T)> f);

lang::meta::Node::AttrClauseExprRhsLoc::All_T xform_lang_meta_Node(lang::meta::Node::AttrClauseExprRhsLoc::All_T x, function<lang::meta::Node_T(lang::meta::Node_T)> f);

lang::meta::Node::AttrClauseExprRhsLoc::Begin_T xform_lang_meta_Node(lang::meta::Node::AttrClauseExprRhsLoc::Begin_T x, function<lang::meta::Node_T(lang::meta::Node_T)> f);

lang::meta::Node::AttrClauseExprRhsLoc::Mid_T xform_lang_meta_Node(lang::meta::Node::AttrClauseExprRhsLoc::Mid_T x, function<lang::meta::Node_T(lang::meta::Node_T)> f);

lang::meta::Node::AttrClauseExprRhsLoc::End_T xform_lang_meta_Node(lang::meta::Node::AttrClauseExprRhsLoc::End_T x, function<lang::meta::Node_T(lang::meta::Node_T)> f);

lang::meta::Node::AttrClauseExpr::Implies_T xform_lang_meta_Node(lang::meta::Node::AttrClauseExpr::Implies_T x, function<lang::meta::Node_T(lang::meta::Node_T)> f);

lang::meta::Node::AttrClause::Block_T xform_lang_meta_Node(lang::meta::Node::AttrClause::Block_T x, function<lang::meta::Node_T(lang::meta::Node_T)> f);

lang::meta::Node::AttrClause::Match_T xform_lang_meta_Node(lang::meta::Node::AttrClause::Match_T x, function<lang::meta::Node_T(lang::meta::Node_T)> f);

lang::meta::Node::AttrMatchCase_T xform_lang_meta_Node(lang::meta::Node::AttrMatchCase_T x, function<lang::meta::Node_T(lang::meta::Node_T)> f);

lang::meta::Node::AttrMatchCasePattern_T xform_lang_meta_Node(lang::meta::Node::AttrMatchCasePattern_T x, function<lang::meta::Node_T(lang::meta::Node_T)> f);

lang::meta::Node::AttrMatchCasePattern::Alt_T xform_lang_meta_Node(lang::meta::Node::AttrMatchCasePattern::Alt_T x, function<lang::meta::Node_T(lang::meta::Node_T)> f);

lang::meta::Node::AttrMatchCasePattern::Wildcard_T xform_lang_meta_Node(lang::meta::Node::AttrMatchCasePattern::Wildcard_T x, function<lang::meta::Node_T(lang::meta::Node_T)> f);

lang::meta::Node::ParserDecl::Rule_T xform_lang_meta_Node(lang::meta::Node::ParserDecl::Rule_T x, function<lang::meta::Node_T(lang::meta::Node_T)> f);

lang::meta::Node::ParserDecl::Rule::op_T xform_lang_meta_Node(lang::meta::Node::ParserDecl::Rule::op_T x, function<lang::meta::Node_T(lang::meta::Node_T)> f);

lang::meta::Node::ParserDecl::Rule::op::DEF_T xform_lang_meta_Node(lang::meta::Node::ParserDecl::Rule::op::DEF_T x, function<lang::meta::Node_T(lang::meta::Node_T)> f);

lang::meta::Node::ParserDecl::Rule::op::DEF_ALIAS_T xform_lang_meta_Node(lang::meta::Node::ParserDecl::Rule::op::DEF_ALIAS_T x, function<lang::meta::Node_T(lang::meta::Node_T)> f);

lang::meta::Node::Stanza::Test_T xform_lang_meta_Node(lang::meta::Node::Stanza::Test_T x, function<lang::meta::Node_T(lang::meta::Node_T)> f);

lang::meta::Node::TestCase_T xform_lang_meta_Node(lang::meta::Node::TestCase_T x, function<lang::meta::Node_T(lang::meta::Node_T)> f);

lang::meta::Node::Stanza::CompileTest_T xform_lang_meta_Node(lang::meta::Node::Stanza::CompileTest_T x, function<lang::meta::Node_T(lang::meta::Node_T)> f);

lang::meta::Node::CompileTestCase_T xform_lang_meta_Node(lang::meta::Node::CompileTestCase_T x, function<lang::meta::Node_T(lang::meta::Node_T)> f);

namespace lang::meta::parser {
    __attribute__((always_inline)) IntPair action_by_vertex(lang_rt::ParserVertexId v, lang_rt::ParserLookahead la);
}

namespace lang::meta::parser {
    __attribute__((always_inline)) lang_rt::ParserVertexId vertex_dfa_step(lang_rt::ParserVertexId v, lang_rt::ParserSymId sym, lang_rt::ParserAttrMask attr);
}

namespace lang::meta::parser {
    lang_rt::ParserProcXforms proc_xform_by_prod_id();
}

namespace lang::meta::parser {
    lang_rt::ParserSymByName start_marker_by_name();
}

namespace lang::meta::parser {
    lang_rt::ParserSymId term_tok_to_sym(lang_rt::TokenId tok);
}

namespace lang::meta::parser {
    lang_rt::ParserSymId sym_to_recur_step(lang_rt::ParserSymId sym);
}

namespace lang::meta::parser {
    string sym_to_debug_string(lang_rt::ParserSymId sym);
}

namespace lang::meta::parser {
    Int sym_to_num_attrs(lang_rt::ParserSymId sym);
}

namespace lang::meta::parser {
    string attr_to_debug_string(lang_rt::ParserSymId sym, Int attr_ind);
}

namespace lang::meta {
    using LangDesc = lang_rt::LangDesc<Node::_T, parser::action_by_vertex, parser::vertex_dfa_step>;
}

namespace lang::meta {
    using LangDesc_T = lang_rt::LangDesc_T<Node::_T, parser::action_by_vertex, parser::vertex_dfa_step>;
}

namespace lang::meta {
    using QuoteEnv = lang_rt::QuoteEnv<Node::_T, parser::action_by_vertex, parser::vertex_dfa_step>;
}

namespace lang::meta {
    using QuoteEnv_T = lang_rt::QuoteEnv_T<Node::_T, parser::action_by_vertex, parser::vertex_dfa_step>;
}

namespace lang::meta {
    lang::meta::LangDesc_T init();
}

namespace lang::meta::lexer::body {
    inline __attribute__((always_inline)) Int proc_mode_loop_opt(ptr<lang_rt::LexerModeDesc> mode, ptr<lang_rt::LexerState> st, ptr<lang_rt::SymItemVec> emit_dst, Int mode_start_pos, Int mode_buf_pos);
}

namespace lang::meta::lexer::comment_single {
    inline __attribute__((always_inline)) Int proc_mode_loop_opt(ptr<lang_rt::LexerModeDesc> mode, ptr<lang_rt::LexerState> st, ptr<lang_rt::SymItemVec> emit_dst, Int mode_start_pos, Int mode_buf_pos);
}
