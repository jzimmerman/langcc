#pragma once

#include <langcc_rt.hpp>

namespace lang::meta::lexer {
    langcc::rc_ptr<langcc::DFALabelIdVec> label_ids_ascii();

    langcc::rc_ptr<langcc::DFALabelIdMap> label_ids_unicode();
}

namespace lang::meta::lexer::body {
    langcc::DFAVertexId step(langcc::DFAVertexId v, langcc::DFALabelId lbl);

    __attribute__((always_inline)) langcc::DFAActionWithToken acc(langcc::DFAVertexId v);

    __attribute__((always_inline)) langcc::IntPair step_exec(langcc::Ptr<langcc::LexerState> st, langcc::Ptr<langcc::SymItemVec> emit_dst, langcc::Ptr<langcc::LexWhitespaceState> ws_state, langcc::DFAActionId acc, langcc::TokenId tok, langcc::Int& in_i, langcc::Int& tok_lo, langcc::Int& tok_hi);

    langcc::Int proc_mode_loop(langcc::Ptr<langcc::LexerState> st, langcc::Ptr<langcc::SymItemVec> emit_dst, langcc::Int mode_start_pos, langcc::Int mode_buf_pos);
}

namespace lang::meta::lexer::comment_single {
    langcc::DFAVertexId step(langcc::DFAVertexId v, langcc::DFALabelId lbl);

    __attribute__((always_inline)) langcc::DFAActionWithToken acc(langcc::DFAVertexId v);

    __attribute__((always_inline)) langcc::IntPair step_exec(langcc::Ptr<langcc::LexerState> st, langcc::Ptr<langcc::SymItemVec> emit_dst, langcc::Ptr<langcc::LexWhitespaceState> ws_state, langcc::DFAActionId acc, langcc::TokenId tok, langcc::Int& in_i, langcc::Int& tok_lo, langcc::Int& tok_hi);

    langcc::Int proc_mode_loop(langcc::Ptr<langcc::LexerState> st, langcc::Ptr<langcc::SymItemVec> emit_dst, langcc::Int mode_start_pos, langcc::Int mode_buf_pos);
}

#pragma once

#include <langcc_util.hpp>

namespace lang::meta::Node {
    struct _T;
}

namespace lang::meta {
    using Node_T = langcc::rc_ptr<lang::meta::Node::_T>;
}

namespace lang::meta::Node::Lang {
    struct _T;
}

namespace lang::meta::Node {
    using Lang_T = langcc::rc_ptr<lang::meta::Node::Lang::_T>;
}

namespace lang::meta::Node::Decl {
    struct _T;
}

namespace lang::meta::Node {
    using Decl_T = langcc::rc_ptr<lang::meta::Node::Decl::_T>;
}

namespace lang::meta::Node::Decl::Include {
    struct _T;
}

namespace lang::meta::Node::Decl {
    using Include_T = langcc::rc_ptr<lang::meta::Node::Decl::Include::_T>;
}

namespace lang::meta::Node::Decl::IncludePost {
    struct _T;
}

namespace lang::meta::Node::Decl {
    using IncludePost_T = langcc::rc_ptr<lang::meta::Node::Decl::IncludePost::_T>;
}

namespace lang::meta::Node::Stanza {
    struct _T;
}

namespace lang::meta::Node {
    using Stanza_T = langcc::rc_ptr<lang::meta::Node::Stanza::_T>;
}

namespace lang::meta::Node::Stanza::Tokens {
    struct _T;
}

namespace lang::meta::Node::Stanza {
    using Tokens_T = langcc::rc_ptr<lang::meta::Node::Stanza::Tokens::_T>;
}

namespace lang::meta::Node::Stanza::Lexer {
    struct _T;
}

namespace lang::meta::Node::Stanza {
    using Lexer_T = langcc::rc_ptr<lang::meta::Node::Stanza::Lexer::_T>;
}

namespace lang::meta::Node::Stanza::Parser {
    struct _T;
}

namespace lang::meta::Node::Stanza {
    using Parser_T = langcc::rc_ptr<lang::meta::Node::Stanza::Parser::_T>;
}

namespace lang::meta::Node::Stanza::Test {
    struct _T;
}

namespace lang::meta::Node::Stanza {
    using Test_T = langcc::rc_ptr<lang::meta::Node::Stanza::Test::_T>;
}

namespace lang::meta::Node::Stanza::CompileTest {
    struct _T;
}

namespace lang::meta::Node::Stanza {
    using CompileTest_T = langcc::rc_ptr<lang::meta::Node::Stanza::CompileTest::_T>;
}

namespace lang::meta::Node::TokenDecl {
    struct _T;
}

namespace lang::meta::Node {
    using TokenDecl_T = langcc::rc_ptr<lang::meta::Node::TokenDecl::_T>;
}

namespace lang::meta::Node::TokenDecl::op {
    struct _T;
}

namespace lang::meta::Node::TokenDecl {
    using op_T = langcc::rc_ptr<lang::meta::Node::TokenDecl::op::_T>;
}

namespace lang::meta::Node::TokenDecl::op::DEF {
    struct _T;
}

namespace lang::meta::Node::TokenDecl::op {
    using DEF_T = langcc::rc_ptr<lang::meta::Node::TokenDecl::op::DEF::_T>;
}

namespace lang::meta::Node::TokenDecl::op::DEF_ALIAS {
    struct _T;
}

namespace lang::meta::Node::TokenDecl::op {
    using DEF_ALIAS_T = langcc::rc_ptr<lang::meta::Node::TokenDecl::op::DEF_ALIAS::_T>;
}

namespace lang::meta::Node::LexerDecl {
    struct _T;
}

namespace lang::meta::Node {
    using LexerDecl_T = langcc::rc_ptr<lang::meta::Node::LexerDecl::_T>;
}

namespace lang::meta::Node::LexerDecl::Main {
    struct _T;
}

namespace lang::meta::Node::LexerDecl {
    using Main_T = langcc::rc_ptr<lang::meta::Node::LexerDecl::Main::_T>;
}

namespace lang::meta::Node::LexerDecl::Mode {
    struct _T;
}

namespace lang::meta::Node::LexerDecl {
    using Mode_T = langcc::rc_ptr<lang::meta::Node::LexerDecl::Mode::_T>;
}

namespace lang::meta::Node::LexerDecl::Mode::ws_sig_ {
    struct _T;
}

namespace lang::meta::Node::LexerDecl::Mode {
    using ws_sig__T = langcc::rc_ptr<lang::meta::Node::LexerDecl::Mode::ws_sig_::_T>;
}

namespace lang::meta::Node::LexerDecl::Mode::ws_sig_::spec {
    struct _T;
}

namespace lang::meta::Node::LexerDecl::Mode::ws_sig_ {
    using spec_T = langcc::rc_ptr<lang::meta::Node::LexerDecl::Mode::ws_sig_::spec::_T>;
}

namespace lang::meta::Node::LexerModeCase {
    struct _T;
}

namespace lang::meta::Node {
    using LexerModeCase_T = langcc::rc_ptr<lang::meta::Node::LexerModeCase::_T>;
}

namespace lang::meta::Node::LexerInstr {
    struct _T;
}

namespace lang::meta::Node {
    using LexerInstr_T = langcc::rc_ptr<lang::meta::Node::LexerInstr::_T>;
}

namespace lang::meta::Node::LexerInstr::Emit {
    struct _T;
}

namespace lang::meta::Node::LexerInstr {
    using Emit_T = langcc::rc_ptr<lang::meta::Node::LexerInstr::Emit::_T>;
}

namespace lang::meta::Node::LexerInstr::Pass {
    struct _T;
}

namespace lang::meta::Node::LexerInstr {
    using Pass_T = langcc::rc_ptr<lang::meta::Node::LexerInstr::Pass::_T>;
}

namespace lang::meta::Node::LexerInstr::Push {
    struct _T;
}

namespace lang::meta::Node::LexerInstr {
    using Push_T = langcc::rc_ptr<lang::meta::Node::LexerInstr::Push::_T>;
}

namespace lang::meta::Node::LexerInstr::Pop {
    struct _T;
}

namespace lang::meta::Node::LexerInstr {
    using Pop_T = langcc::rc_ptr<lang::meta::Node::LexerInstr::Pop::_T>;
}

namespace lang::meta::Node::LexerInstr::PopExtract {
    struct _T;
}

namespace lang::meta::Node::LexerInstr {
    using PopExtract_T = langcc::rc_ptr<lang::meta::Node::LexerInstr::PopExtract::_T>;
}

namespace lang::meta::Node::LexerInstr::PopEmit {
    struct _T;
}

namespace lang::meta::Node::LexerInstr {
    using PopEmit_T = langcc::rc_ptr<lang::meta::Node::LexerInstr::PopEmit::_T>;
}

namespace lang::meta::Node::LexerInstr::MatchHistory {
    struct _T;
}

namespace lang::meta::Node::LexerInstr {
    using MatchHistory_T = langcc::rc_ptr<lang::meta::Node::LexerInstr::MatchHistory::_T>;
}

namespace lang::meta::Node::ParserDecl {
    struct _T;
}

namespace lang::meta::Node {
    using ParserDecl_T = langcc::rc_ptr<lang::meta::Node::ParserDecl::_T>;
}

namespace lang::meta::Node::ParserDecl::Main {
    struct _T;
}

namespace lang::meta::Node::ParserDecl {
    using Main_T = langcc::rc_ptr<lang::meta::Node::ParserDecl::Main::_T>;
}

namespace lang::meta::Node::ParserDecl::Prop {
    struct _T;
}

namespace lang::meta::Node::ParserDecl {
    using Prop_T = langcc::rc_ptr<lang::meta::Node::ParserDecl::Prop::_T>;
}

namespace lang::meta::Node::ParserDecl::Prec {
    struct _T;
}

namespace lang::meta::Node::ParserDecl {
    using Prec_T = langcc::rc_ptr<lang::meta::Node::ParserDecl::Prec::_T>;
}

namespace lang::meta::Node::ParserDecl::Attr {
    struct _T;
}

namespace lang::meta::Node::ParserDecl {
    using Attr_T = langcc::rc_ptr<lang::meta::Node::ParserDecl::Attr::_T>;
}

namespace lang::meta::Node::ParserDecl::Rule {
    struct _T;
}

namespace lang::meta::Node::ParserDecl {
    using Rule_T = langcc::rc_ptr<lang::meta::Node::ParserDecl::Rule::_T>;
}

namespace lang::meta::Node::ParserDecl::Rule::op {
    struct _T;
}

namespace lang::meta::Node::ParserDecl::Rule {
    using op_T = langcc::rc_ptr<lang::meta::Node::ParserDecl::Rule::op::_T>;
}

namespace lang::meta::Node::ParserDecl::Rule::op::DEF {
    struct _T;
}

namespace lang::meta::Node::ParserDecl::Rule::op {
    using DEF_T = langcc::rc_ptr<lang::meta::Node::ParserDecl::Rule::op::DEF::_T>;
}

namespace lang::meta::Node::ParserDecl::Rule::op::DEF_ALIAS {
    struct _T;
}

namespace lang::meta::Node::ParserDecl::Rule::op {
    using DEF_ALIAS_T = langcc::rc_ptr<lang::meta::Node::ParserDecl::Rule::op::DEF_ALIAS::_T>;
}

namespace lang::meta::Node::ParserProp {
    struct _T;
}

namespace lang::meta::Node {
    using ParserProp_T = langcc::rc_ptr<lang::meta::Node::ParserProp::_T>;
}

namespace lang::meta::Node::ParserProp::NameStrict {
    struct _T;
}

namespace lang::meta::Node::ParserProp {
    using NameStrict_T = langcc::rc_ptr<lang::meta::Node::ParserProp::NameStrict::_T>;
}

namespace lang::meta::Node::ParserProp::AllowUnreach {
    struct _T;
}

namespace lang::meta::Node::ParserProp {
    using AllowUnreach_T = langcc::rc_ptr<lang::meta::Node::ParserProp::AllowUnreach::_T>;
}

namespace lang::meta::Node::ParserProp::ASTExtraData {
    struct _T;
}

namespace lang::meta::Node::ParserProp {
    using ASTExtraData_T = langcc::rc_ptr<lang::meta::Node::ParserProp::ASTExtraData::_T>;
}

namespace lang::meta::Node::ParserProp::LRSpec {
    struct _T;
}

namespace lang::meta::Node::ParserProp {
    using LRSpec_T = langcc::rc_ptr<lang::meta::Node::ParserProp::LRSpec::_T>;
}

namespace lang::meta::Node::ParserProp::Err_ {
    struct _T;
}

namespace lang::meta::Node::ParserProp {
    using Err__T = langcc::rc_ptr<lang::meta::Node::ParserProp::Err_::_T>;
}

namespace lang::meta::Node::PrecItem {
    struct _T;
}

namespace lang::meta::Node {
    using PrecItem_T = langcc::rc_ptr<lang::meta::Node::PrecItem::_T>;
}

namespace lang::meta::Node::PrecAssoc {
    struct _T;
}

namespace lang::meta::Node {
    using PrecAssoc_T = langcc::rc_ptr<lang::meta::Node::PrecAssoc::_T>;
}

namespace lang::meta::Node::PrecAssoc::Left {
    struct _T;
}

namespace lang::meta::Node::PrecAssoc {
    using Left_T = langcc::rc_ptr<lang::meta::Node::PrecAssoc::Left::_T>;
}

namespace lang::meta::Node::PrecAssoc::Right {
    struct _T;
}

namespace lang::meta::Node::PrecAssoc {
    using Right_T = langcc::rc_ptr<lang::meta::Node::PrecAssoc::Right::_T>;
}

namespace lang::meta::Node::PrecAssoc::Prefix {
    struct _T;
}

namespace lang::meta::Node::PrecAssoc {
    using Prefix_T = langcc::rc_ptr<lang::meta::Node::PrecAssoc::Prefix::_T>;
}

namespace lang::meta::Node::PrecAssoc::Postfix {
    struct _T;
}

namespace lang::meta::Node::PrecAssoc {
    using Postfix_T = langcc::rc_ptr<lang::meta::Node::PrecAssoc::Postfix::_T>;
}

namespace lang::meta::Node::AttrClause {
    struct _T;
}

namespace lang::meta::Node {
    using AttrClause_T = langcc::rc_ptr<lang::meta::Node::AttrClause::_T>;
}

namespace lang::meta::Node::AttrClause::Expr {
    struct _T;
}

namespace lang::meta::Node::AttrClause {
    using Expr_T = langcc::rc_ptr<lang::meta::Node::AttrClause::Expr::_T>;
}

namespace lang::meta::Node::AttrClause::Block {
    struct _T;
}

namespace lang::meta::Node::AttrClause {
    using Block_T = langcc::rc_ptr<lang::meta::Node::AttrClause::Block::_T>;
}

namespace lang::meta::Node::AttrClause::Match {
    struct _T;
}

namespace lang::meta::Node::AttrClause {
    using Match_T = langcc::rc_ptr<lang::meta::Node::AttrClause::Match::_T>;
}

namespace lang::meta::Node::AttrMatchCase {
    struct _T;
}

namespace lang::meta::Node {
    using AttrMatchCase_T = langcc::rc_ptr<lang::meta::Node::AttrMatchCase::_T>;
}

namespace lang::meta::Node::AttrMatchCasePattern {
    struct _T;
}

namespace lang::meta::Node {
    using AttrMatchCasePattern_T = langcc::rc_ptr<lang::meta::Node::AttrMatchCasePattern::_T>;
}

namespace lang::meta::Node::AttrMatchCasePattern::Alt {
    struct _T;
}

namespace lang::meta::Node::AttrMatchCasePattern {
    using Alt_T = langcc::rc_ptr<lang::meta::Node::AttrMatchCasePattern::Alt::_T>;
}

namespace lang::meta::Node::AttrMatchCasePattern::Wildcard {
    struct _T;
}

namespace lang::meta::Node::AttrMatchCasePattern {
    using Wildcard_T = langcc::rc_ptr<lang::meta::Node::AttrMatchCasePattern::Wildcard::_T>;
}

namespace lang::meta::Node::AttrClauseExpr {
    struct _T;
}

namespace lang::meta::Node {
    using AttrClauseExpr_T = langcc::rc_ptr<lang::meta::Node::AttrClauseExpr::_T>;
}

namespace lang::meta::Node::AttrClauseExpr::LhsGeq {
    struct _T;
}

namespace lang::meta::Node::AttrClauseExpr {
    using LhsGeq_T = langcc::rc_ptr<lang::meta::Node::AttrClauseExpr::LhsGeq::_T>;
}

namespace lang::meta::Node::AttrClauseExpr::RhsGeq {
    struct _T;
}

namespace lang::meta::Node::AttrClauseExpr {
    using RhsGeq_T = langcc::rc_ptr<lang::meta::Node::AttrClauseExpr::RhsGeq::_T>;
}

namespace lang::meta::Node::AttrClauseExpr::Implies {
    struct _T;
}

namespace lang::meta::Node::AttrClauseExpr {
    using Implies_T = langcc::rc_ptr<lang::meta::Node::AttrClauseExpr::Implies::_T>;
}

namespace lang::meta::Node::AttrClauseExprRhsLoc {
    struct _T;
}

namespace lang::meta::Node {
    using AttrClauseExprRhsLoc_T = langcc::rc_ptr<lang::meta::Node::AttrClauseExprRhsLoc::_T>;
}

namespace lang::meta::Node::AttrClauseExprRhsLoc::All {
    struct _T;
}

namespace lang::meta::Node::AttrClauseExprRhsLoc {
    using All_T = langcc::rc_ptr<lang::meta::Node::AttrClauseExprRhsLoc::All::_T>;
}

namespace lang::meta::Node::AttrClauseExprRhsLoc::Begin {
    struct _T;
}

namespace lang::meta::Node::AttrClauseExprRhsLoc {
    using Begin_T = langcc::rc_ptr<lang::meta::Node::AttrClauseExprRhsLoc::Begin::_T>;
}

namespace lang::meta::Node::AttrClauseExprRhsLoc::Mid {
    struct _T;
}

namespace lang::meta::Node::AttrClauseExprRhsLoc {
    using Mid_T = langcc::rc_ptr<lang::meta::Node::AttrClauseExprRhsLoc::Mid::_T>;
}

namespace lang::meta::Node::AttrClauseExprRhsLoc::End {
    struct _T;
}

namespace lang::meta::Node::AttrClauseExprRhsLoc {
    using End_T = langcc::rc_ptr<lang::meta::Node::AttrClauseExprRhsLoc::End::_T>;
}

namespace lang::meta::Node::TestCase {
    struct _T;
}

namespace lang::meta::Node {
    using TestCase_T = langcc::rc_ptr<lang::meta::Node::TestCase::_T>;
}

namespace lang::meta::Node::CompileTestCase {
    struct _T;
}

namespace lang::meta::Node {
    using CompileTestCase_T = langcc::rc_ptr<lang::meta::Node::CompileTestCase::_T>;
}

namespace lang::meta::Node::ParseExpr {
    struct _T;
}

namespace lang::meta::Node {
    using ParseExpr_T = langcc::rc_ptr<lang::meta::Node::ParseExpr::_T>;
}

namespace lang::meta::Node::ParseExpr::Id {
    struct _T;
}

namespace lang::meta::Node::ParseExpr {
    using Id_T = langcc::rc_ptr<lang::meta::Node::ParseExpr::Id::_T>;
}

namespace lang::meta::Node::ParseExpr::Eof {
    struct _T;
}

namespace lang::meta::Node::ParseExpr {
    using Eof_T = langcc::rc_ptr<lang::meta::Node::ParseExpr::Eof::_T>;
}

namespace lang::meta::Node::ParseExpr::False {
    struct _T;
}

namespace lang::meta::Node::ParseExpr {
    using False_T = langcc::rc_ptr<lang::meta::Node::ParseExpr::False::_T>;
}

namespace lang::meta::Node::ParseExpr::Eps {
    struct _T;
}

namespace lang::meta::Node::ParseExpr {
    using Eps_T = langcc::rc_ptr<lang::meta::Node::ParseExpr::Eps::_T>;
}

namespace lang::meta::Node::ParseExpr::Indent {
    struct _T;
}

namespace lang::meta::Node::ParseExpr {
    using Indent_T = langcc::rc_ptr<lang::meta::Node::ParseExpr::Indent::_T>;
}

namespace lang::meta::Node::ParseExpr::Dedent {
    struct _T;
}

namespace lang::meta::Node::ParseExpr {
    using Dedent_T = langcc::rc_ptr<lang::meta::Node::ParseExpr::Dedent::_T>;
}

namespace lang::meta::Node::ParseExpr::Newline {
    struct _T;
}

namespace lang::meta::Node::ParseExpr {
    using Newline_T = langcc::rc_ptr<lang::meta::Node::ParseExpr::Newline::_T>;
}

namespace lang::meta::Node::ParseExpr::UnicodeAny {
    struct _T;
}

namespace lang::meta::Node::ParseExpr {
    using UnicodeAny_T = langcc::rc_ptr<lang::meta::Node::ParseExpr::UnicodeAny::_T>;
}

namespace lang::meta::Node::ParseExpr::AsciiBaseAny {
    struct _T;
}

namespace lang::meta::Node::ParseExpr {
    using AsciiBaseAny_T = langcc::rc_ptr<lang::meta::Node::ParseExpr::AsciiBaseAny::_T>;
}

namespace lang::meta::Node::ParseExpr::Alt {
    struct _T;
}

namespace lang::meta::Node::ParseExpr {
    using Alt_T = langcc::rc_ptr<lang::meta::Node::ParseExpr::Alt::_T>;
}

namespace lang::meta::Node::ParseExpr::AltExplicit {
    struct _T;
}

namespace lang::meta::Node::ParseExpr {
    using AltExplicit_T = langcc::rc_ptr<lang::meta::Node::ParseExpr::AltExplicit::_T>;
}

namespace lang::meta::Node::ParseExpr::Minus {
    struct _T;
}

namespace lang::meta::Node::ParseExpr {
    using Minus_T = langcc::rc_ptr<lang::meta::Node::ParseExpr::Minus::_T>;
}

namespace lang::meta::Node::ParseExpr::Concat {
    struct _T;
}

namespace lang::meta::Node::ParseExpr {
    using Concat_T = langcc::rc_ptr<lang::meta::Node::ParseExpr::Concat::_T>;
}

namespace lang::meta::Node::ParseExpr::Optional {
    struct _T;
}

namespace lang::meta::Node::ParseExpr {
    using Optional_T = langcc::rc_ptr<lang::meta::Node::ParseExpr::Optional::_T>;
}

namespace lang::meta::Node::ParseExpr::Rep {
    struct _T;
}

namespace lang::meta::Node::ParseExpr {
    using Rep_T = langcc::rc_ptr<lang::meta::Node::ParseExpr::Rep::_T>;
}

namespace lang::meta::Node::ParseExpr::RepNonzero {
    struct _T;
}

namespace lang::meta::Node::ParseExpr {
    using RepNonzero_T = langcc::rc_ptr<lang::meta::Node::ParseExpr::RepNonzero::_T>;
}

namespace lang::meta::Node::ParseExpr::RepCount {
    struct _T;
}

namespace lang::meta::Node::ParseExpr {
    using RepCount_T = langcc::rc_ptr<lang::meta::Node::ParseExpr::RepCount::_T>;
}

namespace lang::meta::Node::ParseExpr::CharRange {
    struct _T;
}

namespace lang::meta::Node::ParseExpr {
    using CharRange_T = langcc::rc_ptr<lang::meta::Node::ParseExpr::CharRange::_T>;
}

namespace lang::meta::Node::ParseExpr::StrLit {
    struct _T;
}

namespace lang::meta::Node::ParseExpr {
    using StrLit_T = langcc::rc_ptr<lang::meta::Node::ParseExpr::StrLit::_T>;
}

namespace lang::meta::Node::ParseExpr::Underscore {
    struct _T;
}

namespace lang::meta::Node::ParseExpr {
    using Underscore_T = langcc::rc_ptr<lang::meta::Node::ParseExpr::Underscore::_T>;
}

namespace lang::meta::Node::ParseExpr::Pass {
    struct _T;
}

namespace lang::meta::Node::ParseExpr {
    using Pass_T = langcc::rc_ptr<lang::meta::Node::ParseExpr::Pass::_T>;
}

namespace lang::meta::Node::ParseExpr::Paren {
    struct _T;
}

namespace lang::meta::Node::ParseExpr {
    using Paren_T = langcc::rc_ptr<lang::meta::Node::ParseExpr::Paren::_T>;
}

namespace lang::meta::Node::ParseExpr::Name {
    struct _T;
}

namespace lang::meta::Node::ParseExpr {
    using Name_T = langcc::rc_ptr<lang::meta::Node::ParseExpr::Name::_T>;
}

namespace lang::meta::Node::ParseExpr::List {
    struct _T;
}

namespace lang::meta::Node::ParseExpr {
    using List_T = langcc::rc_ptr<lang::meta::Node::ParseExpr::List::_T>;
}

namespace lang::meta::Node::ParseExpr::List::end_delim {
    struct _T;
}

namespace lang::meta::Node::ParseExpr::List {
    using end_delim_T = langcc::rc_ptr<lang::meta::Node::ParseExpr::List::end_delim::_T>;
}

namespace lang::meta::Node::ParseExpr::List::end_delim::NONE {
    struct _T;
}

namespace lang::meta::Node::ParseExpr::List::end_delim {
    using NONE_T = langcc::rc_ptr<lang::meta::Node::ParseExpr::List::end_delim::NONE::_T>;
}

namespace lang::meta::Node::ParseExpr::List::end_delim::OPTIONAL {
    struct _T;
}

namespace lang::meta::Node::ParseExpr::List::end_delim {
    using OPTIONAL_T = langcc::rc_ptr<lang::meta::Node::ParseExpr::List::end_delim::OPTIONAL::_T>;
}

namespace lang::meta::Node::ParseExpr::List::end_delim::SOME {
    struct _T;
}

namespace lang::meta::Node::ParseExpr::List::end_delim {
    using SOME_T = langcc::rc_ptr<lang::meta::Node::ParseExpr::List::end_delim::SOME::_T>;
}

namespace lang::meta::Node::ParseExpr::Unfold {
    struct _T;
}

namespace lang::meta::Node::ParseExpr {
    using Unfold_T = langcc::rc_ptr<lang::meta::Node::ParseExpr::Unfold::_T>;
}

namespace lang::meta::Node::ParseExpr::AttrReq {
    struct _T;
}

namespace lang::meta::Node::ParseExpr {
    using AttrReq_T = langcc::rc_ptr<lang::meta::Node::ParseExpr::AttrReq::_T>;
}

namespace lang::meta::Node::AttrReq {
    struct _T;
}

namespace lang::meta::Node {
    using AttrReq_T = langcc::rc_ptr<lang::meta::Node::AttrReq::_T>;
}

namespace lang::meta::Node::AttrReq::Base {
    struct _T;
}

namespace lang::meta::Node::AttrReq {
    using Base_T = langcc::rc_ptr<lang::meta::Node::AttrReq::Base::_T>;
}

namespace lang::meta::Node::AttrReq::PrecStar {
    struct _T;
}

namespace lang::meta::Node::AttrReq {
    using PrecStar_T = langcc::rc_ptr<lang::meta::Node::AttrReq::PrecStar::_T>;
}

namespace lang::meta::Node::ParseExprListType {
    struct _T;
}

namespace lang::meta::Node {
    using ParseExprListType_T = langcc::rc_ptr<lang::meta::Node::ParseExprListType::_T>;
}

namespace lang::meta::Node::ParseExprListType::List {
    struct _T;
}

namespace lang::meta::Node::ParseExprListType {
    using List_T = langcc::rc_ptr<lang::meta::Node::ParseExprListType::List::_T>;
}

namespace lang::meta::Node::ParseExprListType::Block {
    struct _T;
}

namespace lang::meta::Node::ParseExprListType {
    using Block_T = langcc::rc_ptr<lang::meta::Node::ParseExprListType::Block::_T>;
}

namespace lang::meta::Node::ParseExprListType::Block2 {
    struct _T;
}

namespace lang::meta::Node::ParseExprListType {
    using Block2_T = langcc::rc_ptr<lang::meta::Node::ParseExprListType::Block2::_T>;
}

namespace lang::meta::Node::ParseExprListType::Top {
    struct _T;
}

namespace lang::meta::Node::ParseExprListType {
    using Top_T = langcc::rc_ptr<lang::meta::Node::ParseExprListType::Top::_T>;
}

namespace lang::meta::Node::ParseExprListType::Top2 {
    struct _T;
}

namespace lang::meta::Node::ParseExprListType {
    using Top2_T = langcc::rc_ptr<lang::meta::Node::ParseExprListType::Top2::_T>;
}

namespace lang::meta::Node::ParseExprListNum {
    struct _T;
}

namespace lang::meta::Node {
    using ParseExprListNum_T = langcc::rc_ptr<lang::meta::Node::ParseExprListNum::_T>;
}

namespace lang::meta::Node::ParseExprListNum::Ge0 {
    struct _T;
}

namespace lang::meta::Node::ParseExprListNum {
    using Ge0_T = langcc::rc_ptr<lang::meta::Node::ParseExprListNum::Ge0::_T>;
}

namespace lang::meta::Node::ParseExprListNum::Ge1 {
    struct _T;
}

namespace lang::meta::Node::ParseExprListNum {
    using Ge1_T = langcc::rc_ptr<lang::meta::Node::ParseExprListNum::Ge1::_T>;
}

namespace lang::meta::Node::ParseExprListNum::Ge2 {
    struct _T;
}

namespace lang::meta::Node::ParseExprListNum {
    using Ge2_T = langcc::rc_ptr<lang::meta::Node::ParseExprListNum::Ge2::_T>;
}

namespace lang::meta::Node::Id {
    struct _T;
}

namespace lang::meta::Node {
    using Id_T = langcc::rc_ptr<lang::meta::Node::Id::_T>;
}

namespace langcc {
    void pr_debug(ostream& os, FmtFlags flags, lang::meta::Node_T x);
}

namespace lang::meta::Node {
    enum struct _W {
        Lang,
        Decl,
        Stanza,
        TokenDecl,
        TokenDecl__op,
        LexerDecl,
        LexerDecl__Mode__ws_sig_,
        LexerDecl__Mode__ws_sig___spec,
        LexerModeCase,
        LexerInstr,
        ParserDecl,
        ParserDecl__Rule__op,
        ParserProp,
        PrecItem,
        PrecAssoc,
        AttrClause,
        AttrMatchCase,
        AttrMatchCasePattern,
        AttrClauseExpr,
        AttrClauseExprRhsLoc,
        TestCase,
        CompileTestCase,
        ParseExpr,
        ParseExpr__List__end_delim,
        AttrReq,
        ParseExprListType,
        ParseExprListNum,
        Id,
    };
}

namespace lang::meta::Node {
    struct _T: langcc::hash_obj, langcc::enable_rc_from_this_poly {
        void write(langcc::Ref<std::ostream> os, langcc::FmtFlags flags);
        void write(langcc::Ref<langcc::PrBufStream_T> pb);
        lang::meta::Node::_W w_;
        virtual ~_T();
        langcc::Int id_;
        langcc::TokenBounds bounds_;
        bool is_top_;
        langcc::ParserSymId sym_;
        langcc::ParserAttrMask attr_;
        langcc::ParserLookahead first_k_;
        _T(lang::meta::Node::_W w);
        bool is_Lang();
        bool is_Decl();
        bool is_Stanza();
        bool is_TokenDecl();
        bool is_TokenDecl__op();
        bool is_LexerDecl();
        bool is_LexerDecl__Mode__ws_sig_();
        bool is_LexerDecl__Mode__ws_sig___spec();
        bool is_LexerModeCase();
        bool is_LexerInstr();
        bool is_ParserDecl();
        bool is_ParserDecl__Rule__op();
        bool is_ParserProp();
        bool is_PrecItem();
        bool is_PrecAssoc();
        bool is_AttrClause();
        bool is_AttrMatchCase();
        bool is_AttrMatchCasePattern();
        bool is_AttrClauseExpr();
        bool is_AttrClauseExprRhsLoc();
        bool is_TestCase();
        bool is_CompileTestCase();
        bool is_ParseExpr();
        bool is_ParseExpr__List__end_delim();
        bool is_AttrReq();
        bool is_ParseExprListType();
        bool is_ParseExprListNum();
        bool is_Id();
        lang::meta::Node::Lang_T as_Lang();
        lang::meta::Node::Decl_T as_Decl();
        lang::meta::Node::Stanza_T as_Stanza();
        lang::meta::Node::TokenDecl_T as_TokenDecl();
        lang::meta::Node::TokenDecl::op_T as_TokenDecl__op();
        lang::meta::Node::LexerDecl_T as_LexerDecl();
        lang::meta::Node::LexerDecl::Mode::ws_sig__T as_LexerDecl__Mode__ws_sig_();
        lang::meta::Node::LexerDecl::Mode::ws_sig_::spec_T as_LexerDecl__Mode__ws_sig___spec();
        lang::meta::Node::LexerModeCase_T as_LexerModeCase();
        lang::meta::Node::LexerInstr_T as_LexerInstr();
        lang::meta::Node::ParserDecl_T as_ParserDecl();
        lang::meta::Node::ParserDecl::Rule::op_T as_ParserDecl__Rule__op();
        lang::meta::Node::ParserProp_T as_ParserProp();
        lang::meta::Node::PrecItem_T as_PrecItem();
        lang::meta::Node::PrecAssoc_T as_PrecAssoc();
        lang::meta::Node::AttrClause_T as_AttrClause();
        lang::meta::Node::AttrMatchCase_T as_AttrMatchCase();
        lang::meta::Node::AttrMatchCasePattern_T as_AttrMatchCasePattern();
        lang::meta::Node::AttrClauseExpr_T as_AttrClauseExpr();
        lang::meta::Node::AttrClauseExprRhsLoc_T as_AttrClauseExprRhsLoc();
        lang::meta::Node::TestCase_T as_TestCase();
        lang::meta::Node::CompileTestCase_T as_CompileTestCase();
        lang::meta::Node::ParseExpr_T as_ParseExpr();
        lang::meta::Node::ParseExpr::List::end_delim_T as_ParseExpr__List__end_delim();
        lang::meta::Node::AttrReq_T as_AttrReq();
        lang::meta::Node::ParseExprListType_T as_ParseExprListType();
        lang::meta::Node::ParseExprListNum_T as_ParseExprListNum();
        lang::meta::Node::Id_T as_Id();
        langcc::Ptr<lang::meta::Node::Lang::_T> as_Lang_unchecked();
        langcc::Ptr<lang::meta::Node::Decl::_T> as_Decl_unchecked();
        langcc::Ptr<lang::meta::Node::Stanza::_T> as_Stanza_unchecked();
        langcc::Ptr<lang::meta::Node::TokenDecl::_T> as_TokenDecl_unchecked();
        langcc::Ptr<lang::meta::Node::TokenDecl::op::_T> as_TokenDecl__op_unchecked();
        langcc::Ptr<lang::meta::Node::LexerDecl::_T> as_LexerDecl_unchecked();
        langcc::Ptr<lang::meta::Node::LexerDecl::Mode::ws_sig_::_T> as_LexerDecl__Mode__ws_sig__unchecked();
        langcc::Ptr<lang::meta::Node::LexerDecl::Mode::ws_sig_::spec::_T> as_LexerDecl__Mode__ws_sig___spec_unchecked();
        langcc::Ptr<lang::meta::Node::LexerModeCase::_T> as_LexerModeCase_unchecked();
        langcc::Ptr<lang::meta::Node::LexerInstr::_T> as_LexerInstr_unchecked();
        langcc::Ptr<lang::meta::Node::ParserDecl::_T> as_ParserDecl_unchecked();
        langcc::Ptr<lang::meta::Node::ParserDecl::Rule::op::_T> as_ParserDecl__Rule__op_unchecked();
        langcc::Ptr<lang::meta::Node::ParserProp::_T> as_ParserProp_unchecked();
        langcc::Ptr<lang::meta::Node::PrecItem::_T> as_PrecItem_unchecked();
        langcc::Ptr<lang::meta::Node::PrecAssoc::_T> as_PrecAssoc_unchecked();
        langcc::Ptr<lang::meta::Node::AttrClause::_T> as_AttrClause_unchecked();
        langcc::Ptr<lang::meta::Node::AttrMatchCase::_T> as_AttrMatchCase_unchecked();
        langcc::Ptr<lang::meta::Node::AttrMatchCasePattern::_T> as_AttrMatchCasePattern_unchecked();
        langcc::Ptr<lang::meta::Node::AttrClauseExpr::_T> as_AttrClauseExpr_unchecked();
        langcc::Ptr<lang::meta::Node::AttrClauseExprRhsLoc::_T> as_AttrClauseExprRhsLoc_unchecked();
        langcc::Ptr<lang::meta::Node::TestCase::_T> as_TestCase_unchecked();
        langcc::Ptr<lang::meta::Node::CompileTestCase::_T> as_CompileTestCase_unchecked();
        langcc::Ptr<lang::meta::Node::ParseExpr::_T> as_ParseExpr_unchecked();
        langcc::Ptr<lang::meta::Node::ParseExpr::List::end_delim::_T> as_ParseExpr__List__end_delim_unchecked();
        langcc::Ptr<lang::meta::Node::AttrReq::_T> as_AttrReq_unchecked();
        langcc::Ptr<lang::meta::Node::ParseExprListType::_T> as_ParseExprListType_unchecked();
        langcc::Ptr<lang::meta::Node::ParseExprListNum::_T> as_ParseExprListNum_unchecked();
        langcc::Ptr<lang::meta::Node::Id::_T> as_Id_unchecked();
        void match(std::function<void(lang::meta::Node::Lang_T)> f_Lang, std::function<void(lang::meta::Node::Decl_T)> f_Decl, std::function<void(lang::meta::Node::Stanza_T)> f_Stanza, std::function<void(lang::meta::Node::TokenDecl_T)> f_TokenDecl, std::function<void(lang::meta::Node::TokenDecl::op_T)> f_TokenDecl__op, std::function<void(lang::meta::Node::LexerDecl_T)> f_LexerDecl, std::function<void(lang::meta::Node::LexerDecl::Mode::ws_sig__T)> f_LexerDecl__Mode__ws_sig_, std::function<void(lang::meta::Node::LexerDecl::Mode::ws_sig_::spec_T)> f_LexerDecl__Mode__ws_sig___spec, std::function<void(lang::meta::Node::LexerModeCase_T)> f_LexerModeCase, std::function<void(lang::meta::Node::LexerInstr_T)> f_LexerInstr, std::function<void(lang::meta::Node::ParserDecl_T)> f_ParserDecl, std::function<void(lang::meta::Node::ParserDecl::Rule::op_T)> f_ParserDecl__Rule__op, std::function<void(lang::meta::Node::ParserProp_T)> f_ParserProp, std::function<void(lang::meta::Node::PrecItem_T)> f_PrecItem, std::function<void(lang::meta::Node::PrecAssoc_T)> f_PrecAssoc, std::function<void(lang::meta::Node::AttrClause_T)> f_AttrClause, std::function<void(lang::meta::Node::AttrMatchCase_T)> f_AttrMatchCase, std::function<void(lang::meta::Node::AttrMatchCasePattern_T)> f_AttrMatchCasePattern, std::function<void(lang::meta::Node::AttrClauseExpr_T)> f_AttrClauseExpr, std::function<void(lang::meta::Node::AttrClauseExprRhsLoc_T)> f_AttrClauseExprRhsLoc, std::function<void(lang::meta::Node::TestCase_T)> f_TestCase, std::function<void(lang::meta::Node::CompileTestCase_T)> f_CompileTestCase, std::function<void(lang::meta::Node::ParseExpr_T)> f_ParseExpr, std::function<void(lang::meta::Node::ParseExpr::List::end_delim_T)> f_ParseExpr__List__end_delim, std::function<void(lang::meta::Node::AttrReq_T)> f_AttrReq, std::function<void(lang::meta::Node::ParseExprListType_T)> f_ParseExprListType, std::function<void(lang::meta::Node::ParseExprListNum_T)> f_ParseExprListNum, std::function<void(lang::meta::Node::Id_T)> f_Id);
        template<typename RetT> RetT match_expr(std::function<RetT(lang::meta::Node::Lang_T)> f_Lang, std::function<RetT(lang::meta::Node::Decl_T)> f_Decl, std::function<RetT(lang::meta::Node::Stanza_T)> f_Stanza, std::function<RetT(lang::meta::Node::TokenDecl_T)> f_TokenDecl, std::function<RetT(lang::meta::Node::TokenDecl::op_T)> f_TokenDecl__op, std::function<RetT(lang::meta::Node::LexerDecl_T)> f_LexerDecl, std::function<RetT(lang::meta::Node::LexerDecl::Mode::ws_sig__T)> f_LexerDecl__Mode__ws_sig_, std::function<RetT(lang::meta::Node::LexerDecl::Mode::ws_sig_::spec_T)> f_LexerDecl__Mode__ws_sig___spec, std::function<RetT(lang::meta::Node::LexerModeCase_T)> f_LexerModeCase, std::function<RetT(lang::meta::Node::LexerInstr_T)> f_LexerInstr, std::function<RetT(lang::meta::Node::ParserDecl_T)> f_ParserDecl, std::function<RetT(lang::meta::Node::ParserDecl::Rule::op_T)> f_ParserDecl__Rule__op, std::function<RetT(lang::meta::Node::ParserProp_T)> f_ParserProp, std::function<RetT(lang::meta::Node::PrecItem_T)> f_PrecItem, std::function<RetT(lang::meta::Node::PrecAssoc_T)> f_PrecAssoc, std::function<RetT(lang::meta::Node::AttrClause_T)> f_AttrClause, std::function<RetT(lang::meta::Node::AttrMatchCase_T)> f_AttrMatchCase, std::function<RetT(lang::meta::Node::AttrMatchCasePattern_T)> f_AttrMatchCasePattern, std::function<RetT(lang::meta::Node::AttrClauseExpr_T)> f_AttrClauseExpr, std::function<RetT(lang::meta::Node::AttrClauseExprRhsLoc_T)> f_AttrClauseExprRhsLoc, std::function<RetT(lang::meta::Node::TestCase_T)> f_TestCase, std::function<RetT(lang::meta::Node::CompileTestCase_T)> f_CompileTestCase, std::function<RetT(lang::meta::Node::ParseExpr_T)> f_ParseExpr, std::function<RetT(lang::meta::Node::ParseExpr::List::end_delim_T)> f_ParseExpr__List__end_delim, std::function<RetT(lang::meta::Node::AttrReq_T)> f_AttrReq, std::function<RetT(lang::meta::Node::ParseExprListType_T)> f_ParseExprListType, std::function<RetT(lang::meta::Node::ParseExprListNum_T)> f_ParseExprListNum, std::function<RetT(lang::meta::Node::Id_T)> f_Id);
        void hash_ser_acc_lang_meta_Node(langcc::SerBuf& buf) const;
        virtual void hash_ser_acc(langcc::SerBuf& buf) const = 0;
    };
}

template<typename RetT> RetT lang::meta::Node::_T::match_expr(std::function<RetT(lang::meta::Node::Lang_T)> f_Lang, std::function<RetT(lang::meta::Node::Decl_T)> f_Decl, std::function<RetT(lang::meta::Node::Stanza_T)> f_Stanza, std::function<RetT(lang::meta::Node::TokenDecl_T)> f_TokenDecl, std::function<RetT(lang::meta::Node::TokenDecl::op_T)> f_TokenDecl__op, std::function<RetT(lang::meta::Node::LexerDecl_T)> f_LexerDecl, std::function<RetT(lang::meta::Node::LexerDecl::Mode::ws_sig__T)> f_LexerDecl__Mode__ws_sig_, std::function<RetT(lang::meta::Node::LexerDecl::Mode::ws_sig_::spec_T)> f_LexerDecl__Mode__ws_sig___spec, std::function<RetT(lang::meta::Node::LexerModeCase_T)> f_LexerModeCase, std::function<RetT(lang::meta::Node::LexerInstr_T)> f_LexerInstr, std::function<RetT(lang::meta::Node::ParserDecl_T)> f_ParserDecl, std::function<RetT(lang::meta::Node::ParserDecl::Rule::op_T)> f_ParserDecl__Rule__op, std::function<RetT(lang::meta::Node::ParserProp_T)> f_ParserProp, std::function<RetT(lang::meta::Node::PrecItem_T)> f_PrecItem, std::function<RetT(lang::meta::Node::PrecAssoc_T)> f_PrecAssoc, std::function<RetT(lang::meta::Node::AttrClause_T)> f_AttrClause, std::function<RetT(lang::meta::Node::AttrMatchCase_T)> f_AttrMatchCase, std::function<RetT(lang::meta::Node::AttrMatchCasePattern_T)> f_AttrMatchCasePattern, std::function<RetT(lang::meta::Node::AttrClauseExpr_T)> f_AttrClauseExpr, std::function<RetT(lang::meta::Node::AttrClauseExprRhsLoc_T)> f_AttrClauseExprRhsLoc, std::function<RetT(lang::meta::Node::TestCase_T)> f_TestCase, std::function<RetT(lang::meta::Node::CompileTestCase_T)> f_CompileTestCase, std::function<RetT(lang::meta::Node::ParseExpr_T)> f_ParseExpr, std::function<RetT(lang::meta::Node::ParseExpr::List::end_delim_T)> f_ParseExpr__List__end_delim, std::function<RetT(lang::meta::Node::AttrReq_T)> f_AttrReq, std::function<RetT(lang::meta::Node::ParseExprListType_T)> f_ParseExprListType, std::function<RetT(lang::meta::Node::ParseExprListNum_T)> f_ParseExprListNum, std::function<RetT(lang::meta::Node::Id_T)> f_Id) {
    switch (this->w_) {
        case lang::meta::Node::_W::Lang: {
            return f_Lang(this->as_Lang());
            break;
        }
        case lang::meta::Node::_W::Decl: {
            return f_Decl(this->as_Decl());
            break;
        }
        case lang::meta::Node::_W::Stanza: {
            return f_Stanza(this->as_Stanza());
            break;
        }
        case lang::meta::Node::_W::TokenDecl: {
            return f_TokenDecl(this->as_TokenDecl());
            break;
        }
        case lang::meta::Node::_W::TokenDecl__op: {
            return f_TokenDecl__op(this->as_TokenDecl__op());
            break;
        }
        case lang::meta::Node::_W::LexerDecl: {
            return f_LexerDecl(this->as_LexerDecl());
            break;
        }
        case lang::meta::Node::_W::LexerDecl__Mode__ws_sig_: {
            return f_LexerDecl__Mode__ws_sig_(this->as_LexerDecl__Mode__ws_sig_());
            break;
        }
        case lang::meta::Node::_W::LexerDecl__Mode__ws_sig___spec: {
            return f_LexerDecl__Mode__ws_sig___spec(this->as_LexerDecl__Mode__ws_sig___spec());
            break;
        }
        case lang::meta::Node::_W::LexerModeCase: {
            return f_LexerModeCase(this->as_LexerModeCase());
            break;
        }
        case lang::meta::Node::_W::LexerInstr: {
            return f_LexerInstr(this->as_LexerInstr());
            break;
        }
        case lang::meta::Node::_W::ParserDecl: {
            return f_ParserDecl(this->as_ParserDecl());
            break;
        }
        case lang::meta::Node::_W::ParserDecl__Rule__op: {
            return f_ParserDecl__Rule__op(this->as_ParserDecl__Rule__op());
            break;
        }
        case lang::meta::Node::_W::ParserProp: {
            return f_ParserProp(this->as_ParserProp());
            break;
        }
        case lang::meta::Node::_W::PrecItem: {
            return f_PrecItem(this->as_PrecItem());
            break;
        }
        case lang::meta::Node::_W::PrecAssoc: {
            return f_PrecAssoc(this->as_PrecAssoc());
            break;
        }
        case lang::meta::Node::_W::AttrClause: {
            return f_AttrClause(this->as_AttrClause());
            break;
        }
        case lang::meta::Node::_W::AttrMatchCase: {
            return f_AttrMatchCase(this->as_AttrMatchCase());
            break;
        }
        case lang::meta::Node::_W::AttrMatchCasePattern: {
            return f_AttrMatchCasePattern(this->as_AttrMatchCasePattern());
            break;
        }
        case lang::meta::Node::_W::AttrClauseExpr: {
            return f_AttrClauseExpr(this->as_AttrClauseExpr());
            break;
        }
        case lang::meta::Node::_W::AttrClauseExprRhsLoc: {
            return f_AttrClauseExprRhsLoc(this->as_AttrClauseExprRhsLoc());
            break;
        }
        case lang::meta::Node::_W::TestCase: {
            return f_TestCase(this->as_TestCase());
            break;
        }
        case lang::meta::Node::_W::CompileTestCase: {
            return f_CompileTestCase(this->as_CompileTestCase());
            break;
        }
        case lang::meta::Node::_W::ParseExpr: {
            return f_ParseExpr(this->as_ParseExpr());
            break;
        }
        case lang::meta::Node::_W::ParseExpr__List__end_delim: {
            return f_ParseExpr__List__end_delim(this->as_ParseExpr__List__end_delim());
            break;
        }
        case lang::meta::Node::_W::AttrReq: {
            return f_AttrReq(this->as_AttrReq());
            break;
        }
        case lang::meta::Node::_W::ParseExprListType: {
            return f_ParseExprListType(this->as_ParseExprListType());
            break;
        }
        case lang::meta::Node::_W::ParseExprListNum: {
            return f_ParseExprListNum(this->as_ParseExprListNum());
            break;
        }
        case lang::meta::Node::_W::Id: {
            return f_Id(this->as_Id());
            break;
        }
        default: {
            langcc::AX();
        }
    }
}

namespace langcc {
    void pr_debug(ostream& os, FmtFlags flags, lang::meta::Node::Lang_T x);
}

namespace lang::meta::Node::Lang {
    lang::meta::Node::Lang_T make(langcc::Int id, langcc::TokenBounds bounds, bool is_top, langcc::ParserSymId sym, langcc::ParserAttrMask attr, langcc::ParserLookahead first_k, langcc::Vec_T<lang::meta::Node::Decl_T> decls, langcc::Vec_T<lang::meta::Node::Stanza_T> stanzas);
}

namespace lang::meta::Node::Lang {
    lang::meta::Node::Lang_T make_ext(langcc::ArenaPtr arena, langcc::Int id, langcc::TokenBounds bounds, bool is_top, langcc::ParserSymId sym, langcc::ParserAttrMask attr, langcc::ParserLookahead first_k, langcc::Vec_T<lang::meta::Node::Decl_T> decls, langcc::Vec_T<lang::meta::Node::Stanza_T> stanzas);
}

namespace lang::meta::Node::Lang {
    struct _T: lang::meta::Node::_T {
        void write(langcc::Ref<std::ostream> os, langcc::FmtFlags flags);
        void write(langcc::Ref<langcc::PrBufStream_T> pb);
        langcc::Vec_T<lang::meta::Node::Decl_T> decls_;
        langcc::Vec_T<lang::meta::Node::Stanza_T> stanzas_;
        _T();
        lang::meta::Node::Lang_T with_id(langcc::Int id);
        lang::meta::Node::Lang_T with_bounds(langcc::TokenBounds bounds);
        lang::meta::Node::Lang_T with_is_top(bool is_top);
        lang::meta::Node::Lang_T with_sym(langcc::ParserSymId sym);
        lang::meta::Node::Lang_T with_attr(langcc::ParserAttrMask attr);
        lang::meta::Node::Lang_T with_first_k(langcc::ParserLookahead first_k);
        lang::meta::Node::Lang_T with_decls(langcc::Vec_T<lang::meta::Node::Decl_T> decls);
        lang::meta::Node::Lang_T with_stanzas(langcc::Vec_T<lang::meta::Node::Stanza_T> stanzas);
        void hash_ser_acc_lang_meta_Node_Lang(langcc::SerBuf& buf) const;
        virtual void hash_ser_acc(langcc::SerBuf& buf) const;
    };
}

namespace langcc {
    void pr_debug(ostream& os, FmtFlags flags, lang::meta::Node::Decl_T x);
}

namespace lang::meta::Node::Decl {
    enum struct _W {
        Include,
        IncludePost,
    };
}

namespace lang::meta::Node::Decl {
    struct _T: lang::meta::Node::_T {
        void write(langcc::Ref<std::ostream> os, langcc::FmtFlags flags);
        void write(langcc::Ref<langcc::PrBufStream_T> pb);
        lang::meta::Node::Decl::_W w_;
        virtual ~_T();
        _T(lang::meta::Node::Decl::_W w);
        bool is_Include();
        bool is_IncludePost();
        lang::meta::Node::Decl::Include_T as_Include();
        lang::meta::Node::Decl::IncludePost_T as_IncludePost();
        langcc::Ptr<lang::meta::Node::Decl::Include::_T> as_Include_unchecked();
        langcc::Ptr<lang::meta::Node::Decl::IncludePost::_T> as_IncludePost_unchecked();
        void match(std::function<void(lang::meta::Node::Decl::Include_T)> f_Include, std::function<void(lang::meta::Node::Decl::IncludePost_T)> f_IncludePost);
        template<typename RetT> RetT match_expr(std::function<RetT(lang::meta::Node::Decl::Include_T)> f_Include, std::function<RetT(lang::meta::Node::Decl::IncludePost_T)> f_IncludePost);
        void hash_ser_acc_lang_meta_Node_Decl(langcc::SerBuf& buf) const;
        virtual void hash_ser_acc(langcc::SerBuf& buf) const = 0;
    };
}

template<typename RetT> RetT lang::meta::Node::Decl::_T::match_expr(std::function<RetT(lang::meta::Node::Decl::Include_T)> f_Include, std::function<RetT(lang::meta::Node::Decl::IncludePost_T)> f_IncludePost) {
    switch (this->w_) {
        case lang::meta::Node::Decl::_W::Include: {
            return f_Include(this->as_Include());
            break;
        }
        case lang::meta::Node::Decl::_W::IncludePost: {
            return f_IncludePost(this->as_IncludePost());
            break;
        }
        default: {
            langcc::AX();
        }
    }
}

namespace langcc {
    void pr_debug(ostream& os, FmtFlags flags, lang::meta::Node::Stanza_T x);
}

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
        void write(langcc::Ref<std::ostream> os, langcc::FmtFlags flags);
        void write(langcc::Ref<langcc::PrBufStream_T> pb);
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
        langcc::Ptr<lang::meta::Node::Stanza::Tokens::_T> as_Tokens_unchecked();
        langcc::Ptr<lang::meta::Node::Stanza::Lexer::_T> as_Lexer_unchecked();
        langcc::Ptr<lang::meta::Node::Stanza::Parser::_T> as_Parser_unchecked();
        langcc::Ptr<lang::meta::Node::Stanza::Test::_T> as_Test_unchecked();
        langcc::Ptr<lang::meta::Node::Stanza::CompileTest::_T> as_CompileTest_unchecked();
        void match(std::function<void(lang::meta::Node::Stanza::Tokens_T)> f_Tokens, std::function<void(lang::meta::Node::Stanza::Lexer_T)> f_Lexer, std::function<void(lang::meta::Node::Stanza::Parser_T)> f_Parser, std::function<void(lang::meta::Node::Stanza::Test_T)> f_Test, std::function<void(lang::meta::Node::Stanza::CompileTest_T)> f_CompileTest);
        template<typename RetT> RetT match_expr(std::function<RetT(lang::meta::Node::Stanza::Tokens_T)> f_Tokens, std::function<RetT(lang::meta::Node::Stanza::Lexer_T)> f_Lexer, std::function<RetT(lang::meta::Node::Stanza::Parser_T)> f_Parser, std::function<RetT(lang::meta::Node::Stanza::Test_T)> f_Test, std::function<RetT(lang::meta::Node::Stanza::CompileTest_T)> f_CompileTest);
        void hash_ser_acc_lang_meta_Node_Stanza(langcc::SerBuf& buf) const;
        virtual void hash_ser_acc(langcc::SerBuf& buf) const = 0;
    };
}

template<typename RetT> RetT lang::meta::Node::Stanza::_T::match_expr(std::function<RetT(lang::meta::Node::Stanza::Tokens_T)> f_Tokens, std::function<RetT(lang::meta::Node::Stanza::Lexer_T)> f_Lexer, std::function<RetT(lang::meta::Node::Stanza::Parser_T)> f_Parser, std::function<RetT(lang::meta::Node::Stanza::Test_T)> f_Test, std::function<RetT(lang::meta::Node::Stanza::CompileTest_T)> f_CompileTest) {
    switch (this->w_) {
        case lang::meta::Node::Stanza::_W::Tokens: {
            return f_Tokens(this->as_Tokens());
            break;
        }
        case lang::meta::Node::Stanza::_W::Lexer: {
            return f_Lexer(this->as_Lexer());
            break;
        }
        case lang::meta::Node::Stanza::_W::Parser: {
            return f_Parser(this->as_Parser());
            break;
        }
        case lang::meta::Node::Stanza::_W::Test: {
            return f_Test(this->as_Test());
            break;
        }
        case lang::meta::Node::Stanza::_W::CompileTest: {
            return f_CompileTest(this->as_CompileTest());
            break;
        }
        default: {
            langcc::AX();
        }
    }
}

namespace langcc {
    void pr_debug(ostream& os, FmtFlags flags, lang::meta::Node::TokenDecl_T x);
}

namespace lang::meta::Node::TokenDecl {
    lang::meta::Node::TokenDecl_T make(langcc::Int id, langcc::TokenBounds bounds, bool is_top, langcc::ParserSymId sym, langcc::ParserAttrMask attr, langcc::ParserLookahead first_k, langcc::StrSlice name, lang::meta::Node::TokenDecl::op_T op, lang::meta::Node::ParseExpr_T def_);
}

namespace lang::meta::Node::TokenDecl {
    lang::meta::Node::TokenDecl_T make_ext(langcc::ArenaPtr arena, langcc::Int id, langcc::TokenBounds bounds, bool is_top, langcc::ParserSymId sym, langcc::ParserAttrMask attr, langcc::ParserLookahead first_k, langcc::StrSlice name, lang::meta::Node::TokenDecl::op_T op, lang::meta::Node::ParseExpr_T def_);
}

namespace lang::meta::Node::TokenDecl {
    struct _T: lang::meta::Node::_T {
        void write(langcc::Ref<std::ostream> os, langcc::FmtFlags flags);
        void write(langcc::Ref<langcc::PrBufStream_T> pb);
        langcc::StrSlice name_;
        lang::meta::Node::TokenDecl::op_T op_;
        lang::meta::Node::ParseExpr_T def__;
        _T();
        lang::meta::Node::TokenDecl_T with_id(langcc::Int id);
        lang::meta::Node::TokenDecl_T with_bounds(langcc::TokenBounds bounds);
        lang::meta::Node::TokenDecl_T with_is_top(bool is_top);
        lang::meta::Node::TokenDecl_T with_sym(langcc::ParserSymId sym);
        lang::meta::Node::TokenDecl_T with_attr(langcc::ParserAttrMask attr);
        lang::meta::Node::TokenDecl_T with_first_k(langcc::ParserLookahead first_k);
        lang::meta::Node::TokenDecl_T with_name(langcc::StrSlice name);
        lang::meta::Node::TokenDecl_T with_op(lang::meta::Node::TokenDecl::op_T op);
        lang::meta::Node::TokenDecl_T with_def_(lang::meta::Node::ParseExpr_T def_);
        void hash_ser_acc_lang_meta_Node_TokenDecl(langcc::SerBuf& buf) const;
        virtual void hash_ser_acc(langcc::SerBuf& buf) const;
    };
}

namespace langcc {
    void pr_debug(ostream& os, FmtFlags flags, lang::meta::Node::LexerDecl_T x);
}

namespace lang::meta::Node::LexerDecl {
    enum struct _W {
        Main,
        Mode,
    };
}

namespace lang::meta::Node::LexerDecl {
    struct _T: lang::meta::Node::_T {
        void write(langcc::Ref<std::ostream> os, langcc::FmtFlags flags);
        void write(langcc::Ref<langcc::PrBufStream_T> pb);
        lang::meta::Node::LexerDecl::_W w_;
        virtual ~_T();
        _T(lang::meta::Node::LexerDecl::_W w);
        bool is_Main();
        bool is_Mode();
        lang::meta::Node::LexerDecl::Main_T as_Main();
        lang::meta::Node::LexerDecl::Mode_T as_Mode();
        langcc::Ptr<lang::meta::Node::LexerDecl::Main::_T> as_Main_unchecked();
        langcc::Ptr<lang::meta::Node::LexerDecl::Mode::_T> as_Mode_unchecked();
        void match(std::function<void(lang::meta::Node::LexerDecl::Main_T)> f_Main, std::function<void(lang::meta::Node::LexerDecl::Mode_T)> f_Mode);
        template<typename RetT> RetT match_expr(std::function<RetT(lang::meta::Node::LexerDecl::Main_T)> f_Main, std::function<RetT(lang::meta::Node::LexerDecl::Mode_T)> f_Mode);
        void hash_ser_acc_lang_meta_Node_LexerDecl(langcc::SerBuf& buf) const;
        virtual void hash_ser_acc(langcc::SerBuf& buf) const = 0;
    };
}

template<typename RetT> RetT lang::meta::Node::LexerDecl::_T::match_expr(std::function<RetT(lang::meta::Node::LexerDecl::Main_T)> f_Main, std::function<RetT(lang::meta::Node::LexerDecl::Mode_T)> f_Mode) {
    switch (this->w_) {
        case lang::meta::Node::LexerDecl::_W::Main: {
            return f_Main(this->as_Main());
            break;
        }
        case lang::meta::Node::LexerDecl::_W::Mode: {
            return f_Mode(this->as_Mode());
            break;
        }
        default: {
            langcc::AX();
        }
    }
}

namespace langcc {
    void pr_debug(ostream& os, FmtFlags flags, lang::meta::Node::LexerModeCase_T x);
}

namespace lang::meta::Node::LexerModeCase {
    lang::meta::Node::LexerModeCase_T make(langcc::Int id, langcc::TokenBounds bounds, bool is_top, langcc::ParserSymId sym, langcc::ParserAttrMask attr, langcc::ParserLookahead first_k, lang::meta::Node::ParseExpr_T tok, langcc::Vec_T<lang::meta::Node::LexerInstr_T> instrs);
}

namespace lang::meta::Node::LexerModeCase {
    lang::meta::Node::LexerModeCase_T make_ext(langcc::ArenaPtr arena, langcc::Int id, langcc::TokenBounds bounds, bool is_top, langcc::ParserSymId sym, langcc::ParserAttrMask attr, langcc::ParserLookahead first_k, lang::meta::Node::ParseExpr_T tok, langcc::Vec_T<lang::meta::Node::LexerInstr_T> instrs);
}

namespace lang::meta::Node::LexerModeCase {
    struct _T: lang::meta::Node::_T {
        void write(langcc::Ref<std::ostream> os, langcc::FmtFlags flags);
        void write(langcc::Ref<langcc::PrBufStream_T> pb);
        lang::meta::Node::ParseExpr_T tok_;
        langcc::Vec_T<lang::meta::Node::LexerInstr_T> instrs_;
        _T();
        lang::meta::Node::LexerModeCase_T with_id(langcc::Int id);
        lang::meta::Node::LexerModeCase_T with_bounds(langcc::TokenBounds bounds);
        lang::meta::Node::LexerModeCase_T with_is_top(bool is_top);
        lang::meta::Node::LexerModeCase_T with_sym(langcc::ParserSymId sym);
        lang::meta::Node::LexerModeCase_T with_attr(langcc::ParserAttrMask attr);
        lang::meta::Node::LexerModeCase_T with_first_k(langcc::ParserLookahead first_k);
        lang::meta::Node::LexerModeCase_T with_tok(lang::meta::Node::ParseExpr_T tok);
        lang::meta::Node::LexerModeCase_T with_instrs(langcc::Vec_T<lang::meta::Node::LexerInstr_T> instrs);
        void hash_ser_acc_lang_meta_Node_LexerModeCase(langcc::SerBuf& buf) const;
        virtual void hash_ser_acc(langcc::SerBuf& buf) const;
    };
}

namespace langcc {
    void pr_debug(ostream& os, FmtFlags flags, lang::meta::Node::LexerInstr_T x);
}

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
        void write(langcc::Ref<std::ostream> os, langcc::FmtFlags flags);
        void write(langcc::Ref<langcc::PrBufStream_T> pb);
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
        langcc::Ptr<lang::meta::Node::LexerInstr::Emit::_T> as_Emit_unchecked();
        langcc::Ptr<lang::meta::Node::LexerInstr::Pass::_T> as_Pass_unchecked();
        langcc::Ptr<lang::meta::Node::LexerInstr::Push::_T> as_Push_unchecked();
        langcc::Ptr<lang::meta::Node::LexerInstr::Pop::_T> as_Pop_unchecked();
        langcc::Ptr<lang::meta::Node::LexerInstr::PopExtract::_T> as_PopExtract_unchecked();
        langcc::Ptr<lang::meta::Node::LexerInstr::PopEmit::_T> as_PopEmit_unchecked();
        langcc::Ptr<lang::meta::Node::LexerInstr::MatchHistory::_T> as_MatchHistory_unchecked();
        void match(std::function<void(lang::meta::Node::LexerInstr::Emit_T)> f_Emit, std::function<void(lang::meta::Node::LexerInstr::Pass_T)> f_Pass, std::function<void(lang::meta::Node::LexerInstr::Push_T)> f_Push, std::function<void(lang::meta::Node::LexerInstr::Pop_T)> f_Pop, std::function<void(lang::meta::Node::LexerInstr::PopExtract_T)> f_PopExtract, std::function<void(lang::meta::Node::LexerInstr::PopEmit_T)> f_PopEmit, std::function<void(lang::meta::Node::LexerInstr::MatchHistory_T)> f_MatchHistory);
        template<typename RetT> RetT match_expr(std::function<RetT(lang::meta::Node::LexerInstr::Emit_T)> f_Emit, std::function<RetT(lang::meta::Node::LexerInstr::Pass_T)> f_Pass, std::function<RetT(lang::meta::Node::LexerInstr::Push_T)> f_Push, std::function<RetT(lang::meta::Node::LexerInstr::Pop_T)> f_Pop, std::function<RetT(lang::meta::Node::LexerInstr::PopExtract_T)> f_PopExtract, std::function<RetT(lang::meta::Node::LexerInstr::PopEmit_T)> f_PopEmit, std::function<RetT(lang::meta::Node::LexerInstr::MatchHistory_T)> f_MatchHistory);
        void hash_ser_acc_lang_meta_Node_LexerInstr(langcc::SerBuf& buf) const;
        virtual void hash_ser_acc(langcc::SerBuf& buf) const = 0;
    };
}

template<typename RetT> RetT lang::meta::Node::LexerInstr::_T::match_expr(std::function<RetT(lang::meta::Node::LexerInstr::Emit_T)> f_Emit, std::function<RetT(lang::meta::Node::LexerInstr::Pass_T)> f_Pass, std::function<RetT(lang::meta::Node::LexerInstr::Push_T)> f_Push, std::function<RetT(lang::meta::Node::LexerInstr::Pop_T)> f_Pop, std::function<RetT(lang::meta::Node::LexerInstr::PopExtract_T)> f_PopExtract, std::function<RetT(lang::meta::Node::LexerInstr::PopEmit_T)> f_PopEmit, std::function<RetT(lang::meta::Node::LexerInstr::MatchHistory_T)> f_MatchHistory) {
    switch (this->w_) {
        case lang::meta::Node::LexerInstr::_W::Emit: {
            return f_Emit(this->as_Emit());
            break;
        }
        case lang::meta::Node::LexerInstr::_W::Pass: {
            return f_Pass(this->as_Pass());
            break;
        }
        case lang::meta::Node::LexerInstr::_W::Push: {
            return f_Push(this->as_Push());
            break;
        }
        case lang::meta::Node::LexerInstr::_W::Pop: {
            return f_Pop(this->as_Pop());
            break;
        }
        case lang::meta::Node::LexerInstr::_W::PopExtract: {
            return f_PopExtract(this->as_PopExtract());
            break;
        }
        case lang::meta::Node::LexerInstr::_W::PopEmit: {
            return f_PopEmit(this->as_PopEmit());
            break;
        }
        case lang::meta::Node::LexerInstr::_W::MatchHistory: {
            return f_MatchHistory(this->as_MatchHistory());
            break;
        }
        default: {
            langcc::AX();
        }
    }
}

namespace langcc {
    void pr_debug(ostream& os, FmtFlags flags, lang::meta::Node::ParserDecl_T x);
}

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
        void write(langcc::Ref<std::ostream> os, langcc::FmtFlags flags);
        void write(langcc::Ref<langcc::PrBufStream_T> pb);
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
        langcc::Ptr<lang::meta::Node::ParserDecl::Main::_T> as_Main_unchecked();
        langcc::Ptr<lang::meta::Node::ParserDecl::Prop::_T> as_Prop_unchecked();
        langcc::Ptr<lang::meta::Node::ParserDecl::Prec::_T> as_Prec_unchecked();
        langcc::Ptr<lang::meta::Node::ParserDecl::Attr::_T> as_Attr_unchecked();
        langcc::Ptr<lang::meta::Node::ParserDecl::Rule::_T> as_Rule_unchecked();
        void match(std::function<void(lang::meta::Node::ParserDecl::Main_T)> f_Main, std::function<void(lang::meta::Node::ParserDecl::Prop_T)> f_Prop, std::function<void(lang::meta::Node::ParserDecl::Prec_T)> f_Prec, std::function<void(lang::meta::Node::ParserDecl::Attr_T)> f_Attr, std::function<void(lang::meta::Node::ParserDecl::Rule_T)> f_Rule);
        template<typename RetT> RetT match_expr(std::function<RetT(lang::meta::Node::ParserDecl::Main_T)> f_Main, std::function<RetT(lang::meta::Node::ParserDecl::Prop_T)> f_Prop, std::function<RetT(lang::meta::Node::ParserDecl::Prec_T)> f_Prec, std::function<RetT(lang::meta::Node::ParserDecl::Attr_T)> f_Attr, std::function<RetT(lang::meta::Node::ParserDecl::Rule_T)> f_Rule);
        void hash_ser_acc_lang_meta_Node_ParserDecl(langcc::SerBuf& buf) const;
        virtual void hash_ser_acc(langcc::SerBuf& buf) const = 0;
    };
}

template<typename RetT> RetT lang::meta::Node::ParserDecl::_T::match_expr(std::function<RetT(lang::meta::Node::ParserDecl::Main_T)> f_Main, std::function<RetT(lang::meta::Node::ParserDecl::Prop_T)> f_Prop, std::function<RetT(lang::meta::Node::ParserDecl::Prec_T)> f_Prec, std::function<RetT(lang::meta::Node::ParserDecl::Attr_T)> f_Attr, std::function<RetT(lang::meta::Node::ParserDecl::Rule_T)> f_Rule) {
    switch (this->w_) {
        case lang::meta::Node::ParserDecl::_W::Main: {
            return f_Main(this->as_Main());
            break;
        }
        case lang::meta::Node::ParserDecl::_W::Prop: {
            return f_Prop(this->as_Prop());
            break;
        }
        case lang::meta::Node::ParserDecl::_W::Prec: {
            return f_Prec(this->as_Prec());
            break;
        }
        case lang::meta::Node::ParserDecl::_W::Attr: {
            return f_Attr(this->as_Attr());
            break;
        }
        case lang::meta::Node::ParserDecl::_W::Rule: {
            return f_Rule(this->as_Rule());
            break;
        }
        default: {
            langcc::AX();
        }
    }
}

namespace langcc {
    void pr_debug(ostream& os, FmtFlags flags, lang::meta::Node::ParserProp_T x);
}

namespace lang::meta::Node::ParserProp {
    enum struct _W {
        NameStrict,
        AllowUnreach,
        ASTExtraData,
        LRSpec,
        Err_,
    };
}

namespace lang::meta::Node::ParserProp {
    struct _T: lang::meta::Node::_T {
        void write(langcc::Ref<std::ostream> os, langcc::FmtFlags flags);
        void write(langcc::Ref<langcc::PrBufStream_T> pb);
        lang::meta::Node::ParserProp::_W w_;
        virtual ~_T();
        _T(lang::meta::Node::ParserProp::_W w);
        bool is_NameStrict();
        bool is_AllowUnreach();
        bool is_ASTExtraData();
        bool is_LRSpec();
        bool is_Err_();
        lang::meta::Node::ParserProp::NameStrict_T as_NameStrict();
        lang::meta::Node::ParserProp::AllowUnreach_T as_AllowUnreach();
        lang::meta::Node::ParserProp::ASTExtraData_T as_ASTExtraData();
        lang::meta::Node::ParserProp::LRSpec_T as_LRSpec();
        lang::meta::Node::ParserProp::Err__T as_Err_();
        langcc::Ptr<lang::meta::Node::ParserProp::NameStrict::_T> as_NameStrict_unchecked();
        langcc::Ptr<lang::meta::Node::ParserProp::AllowUnreach::_T> as_AllowUnreach_unchecked();
        langcc::Ptr<lang::meta::Node::ParserProp::ASTExtraData::_T> as_ASTExtraData_unchecked();
        langcc::Ptr<lang::meta::Node::ParserProp::LRSpec::_T> as_LRSpec_unchecked();
        langcc::Ptr<lang::meta::Node::ParserProp::Err_::_T> as_Err__unchecked();
        void match(std::function<void(lang::meta::Node::ParserProp::NameStrict_T)> f_NameStrict, std::function<void(lang::meta::Node::ParserProp::AllowUnreach_T)> f_AllowUnreach, std::function<void(lang::meta::Node::ParserProp::ASTExtraData_T)> f_ASTExtraData, std::function<void(lang::meta::Node::ParserProp::LRSpec_T)> f_LRSpec, std::function<void(lang::meta::Node::ParserProp::Err__T)> f_Err_);
        template<typename RetT> RetT match_expr(std::function<RetT(lang::meta::Node::ParserProp::NameStrict_T)> f_NameStrict, std::function<RetT(lang::meta::Node::ParserProp::AllowUnreach_T)> f_AllowUnreach, std::function<RetT(lang::meta::Node::ParserProp::ASTExtraData_T)> f_ASTExtraData, std::function<RetT(lang::meta::Node::ParserProp::LRSpec_T)> f_LRSpec, std::function<RetT(lang::meta::Node::ParserProp::Err__T)> f_Err_);
        void hash_ser_acc_lang_meta_Node_ParserProp(langcc::SerBuf& buf) const;
        virtual void hash_ser_acc(langcc::SerBuf& buf) const = 0;
    };
}

template<typename RetT> RetT lang::meta::Node::ParserProp::_T::match_expr(std::function<RetT(lang::meta::Node::ParserProp::NameStrict_T)> f_NameStrict, std::function<RetT(lang::meta::Node::ParserProp::AllowUnreach_T)> f_AllowUnreach, std::function<RetT(lang::meta::Node::ParserProp::ASTExtraData_T)> f_ASTExtraData, std::function<RetT(lang::meta::Node::ParserProp::LRSpec_T)> f_LRSpec, std::function<RetT(lang::meta::Node::ParserProp::Err__T)> f_Err_) {
    switch (this->w_) {
        case lang::meta::Node::ParserProp::_W::NameStrict: {
            return f_NameStrict(this->as_NameStrict());
            break;
        }
        case lang::meta::Node::ParserProp::_W::AllowUnreach: {
            return f_AllowUnreach(this->as_AllowUnreach());
            break;
        }
        case lang::meta::Node::ParserProp::_W::ASTExtraData: {
            return f_ASTExtraData(this->as_ASTExtraData());
            break;
        }
        case lang::meta::Node::ParserProp::_W::LRSpec: {
            return f_LRSpec(this->as_LRSpec());
            break;
        }
        case lang::meta::Node::ParserProp::_W::Err_: {
            return f_Err_(this->as_Err_());
            break;
        }
        default: {
            langcc::AX();
        }
    }
}

namespace langcc {
    void pr_debug(ostream& os, FmtFlags flags, lang::meta::Node::PrecItem_T x);
}

namespace lang::meta::Node::PrecItem {
    lang::meta::Node::PrecItem_T make(langcc::Int id, langcc::TokenBounds bounds, bool is_top, langcc::ParserSymId sym, langcc::ParserAttrMask attr, langcc::ParserLookahead first_k, langcc::Vec_T<lang::meta::Node::Id_T> ids, langcc::Option_T<lang::meta::Node::PrecAssoc_T> assoc);
}

namespace lang::meta::Node::PrecItem {
    lang::meta::Node::PrecItem_T make_ext(langcc::ArenaPtr arena, langcc::Int id, langcc::TokenBounds bounds, bool is_top, langcc::ParserSymId sym, langcc::ParserAttrMask attr, langcc::ParserLookahead first_k, langcc::Vec_T<lang::meta::Node::Id_T> ids, langcc::Option_T<lang::meta::Node::PrecAssoc_T> assoc);
}

namespace lang::meta::Node::PrecItem {
    struct _T: lang::meta::Node::_T {
        void write(langcc::Ref<std::ostream> os, langcc::FmtFlags flags);
        void write(langcc::Ref<langcc::PrBufStream_T> pb);
        langcc::Vec_T<lang::meta::Node::Id_T> ids_;
        langcc::Option_T<lang::meta::Node::PrecAssoc_T> assoc_;
        _T();
        lang::meta::Node::PrecItem_T with_id(langcc::Int id);
        lang::meta::Node::PrecItem_T with_bounds(langcc::TokenBounds bounds);
        lang::meta::Node::PrecItem_T with_is_top(bool is_top);
        lang::meta::Node::PrecItem_T with_sym(langcc::ParserSymId sym);
        lang::meta::Node::PrecItem_T with_attr(langcc::ParserAttrMask attr);
        lang::meta::Node::PrecItem_T with_first_k(langcc::ParserLookahead first_k);
        lang::meta::Node::PrecItem_T with_ids(langcc::Vec_T<lang::meta::Node::Id_T> ids);
        lang::meta::Node::PrecItem_T with_assoc(langcc::Option_T<lang::meta::Node::PrecAssoc_T> assoc);
        void hash_ser_acc_lang_meta_Node_PrecItem(langcc::SerBuf& buf) const;
        virtual void hash_ser_acc(langcc::SerBuf& buf) const;
    };
}

namespace langcc {
    void pr_debug(ostream& os, FmtFlags flags, lang::meta::Node::PrecAssoc_T x);
}

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
        void write(langcc::Ref<std::ostream> os, langcc::FmtFlags flags);
        void write(langcc::Ref<langcc::PrBufStream_T> pb);
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
        langcc::Ptr<lang::meta::Node::PrecAssoc::Left::_T> as_Left_unchecked();
        langcc::Ptr<lang::meta::Node::PrecAssoc::Right::_T> as_Right_unchecked();
        langcc::Ptr<lang::meta::Node::PrecAssoc::Prefix::_T> as_Prefix_unchecked();
        langcc::Ptr<lang::meta::Node::PrecAssoc::Postfix::_T> as_Postfix_unchecked();
        void match(std::function<void(lang::meta::Node::PrecAssoc::Left_T)> f_Left, std::function<void(lang::meta::Node::PrecAssoc::Right_T)> f_Right, std::function<void(lang::meta::Node::PrecAssoc::Prefix_T)> f_Prefix, std::function<void(lang::meta::Node::PrecAssoc::Postfix_T)> f_Postfix);
        template<typename RetT> RetT match_expr(std::function<RetT(lang::meta::Node::PrecAssoc::Left_T)> f_Left, std::function<RetT(lang::meta::Node::PrecAssoc::Right_T)> f_Right, std::function<RetT(lang::meta::Node::PrecAssoc::Prefix_T)> f_Prefix, std::function<RetT(lang::meta::Node::PrecAssoc::Postfix_T)> f_Postfix);
        void hash_ser_acc_lang_meta_Node_PrecAssoc(langcc::SerBuf& buf) const;
        virtual void hash_ser_acc(langcc::SerBuf& buf) const = 0;
    };
}

template<typename RetT> RetT lang::meta::Node::PrecAssoc::_T::match_expr(std::function<RetT(lang::meta::Node::PrecAssoc::Left_T)> f_Left, std::function<RetT(lang::meta::Node::PrecAssoc::Right_T)> f_Right, std::function<RetT(lang::meta::Node::PrecAssoc::Prefix_T)> f_Prefix, std::function<RetT(lang::meta::Node::PrecAssoc::Postfix_T)> f_Postfix) {
    switch (this->w_) {
        case lang::meta::Node::PrecAssoc::_W::Left: {
            return f_Left(this->as_Left());
            break;
        }
        case lang::meta::Node::PrecAssoc::_W::Right: {
            return f_Right(this->as_Right());
            break;
        }
        case lang::meta::Node::PrecAssoc::_W::Prefix: {
            return f_Prefix(this->as_Prefix());
            break;
        }
        case lang::meta::Node::PrecAssoc::_W::Postfix: {
            return f_Postfix(this->as_Postfix());
            break;
        }
        default: {
            langcc::AX();
        }
    }
}

namespace langcc {
    void pr_debug(ostream& os, FmtFlags flags, lang::meta::Node::AttrClause_T x);
}

namespace lang::meta::Node::AttrClause {
    enum struct _W {
        Expr,
        Block,
        Match,
    };
}

namespace lang::meta::Node::AttrClause {
    struct _T: lang::meta::Node::_T {
        void write(langcc::Ref<std::ostream> os, langcc::FmtFlags flags);
        void write(langcc::Ref<langcc::PrBufStream_T> pb);
        lang::meta::Node::AttrClause::_W w_;
        virtual ~_T();
        _T(lang::meta::Node::AttrClause::_W w);
        bool is_Expr();
        bool is_Block();
        bool is_Match();
        lang::meta::Node::AttrClause::Expr_T as_Expr();
        lang::meta::Node::AttrClause::Block_T as_Block();
        lang::meta::Node::AttrClause::Match_T as_Match();
        langcc::Ptr<lang::meta::Node::AttrClause::Expr::_T> as_Expr_unchecked();
        langcc::Ptr<lang::meta::Node::AttrClause::Block::_T> as_Block_unchecked();
        langcc::Ptr<lang::meta::Node::AttrClause::Match::_T> as_Match_unchecked();
        void match(std::function<void(lang::meta::Node::AttrClause::Expr_T)> f_Expr, std::function<void(lang::meta::Node::AttrClause::Block_T)> f_Block, std::function<void(lang::meta::Node::AttrClause::Match_T)> f_Match);
        template<typename RetT> RetT match_expr(std::function<RetT(lang::meta::Node::AttrClause::Expr_T)> f_Expr, std::function<RetT(lang::meta::Node::AttrClause::Block_T)> f_Block, std::function<RetT(lang::meta::Node::AttrClause::Match_T)> f_Match);
        void hash_ser_acc_lang_meta_Node_AttrClause(langcc::SerBuf& buf) const;
        virtual void hash_ser_acc(langcc::SerBuf& buf) const = 0;
    };
}

template<typename RetT> RetT lang::meta::Node::AttrClause::_T::match_expr(std::function<RetT(lang::meta::Node::AttrClause::Expr_T)> f_Expr, std::function<RetT(lang::meta::Node::AttrClause::Block_T)> f_Block, std::function<RetT(lang::meta::Node::AttrClause::Match_T)> f_Match) {
    switch (this->w_) {
        case lang::meta::Node::AttrClause::_W::Expr: {
            return f_Expr(this->as_Expr());
            break;
        }
        case lang::meta::Node::AttrClause::_W::Block: {
            return f_Block(this->as_Block());
            break;
        }
        case lang::meta::Node::AttrClause::_W::Match: {
            return f_Match(this->as_Match());
            break;
        }
        default: {
            langcc::AX();
        }
    }
}

namespace langcc {
    void pr_debug(ostream& os, FmtFlags flags, lang::meta::Node::AttrMatchCase_T x);
}

namespace lang::meta::Node::AttrMatchCase {
    lang::meta::Node::AttrMatchCase_T make(langcc::Int id, langcc::TokenBounds bounds, bool is_top, langcc::ParserSymId sym, langcc::ParserAttrMask attr, langcc::ParserLookahead first_k, lang::meta::Node::AttrMatchCasePattern_T pat, lang::meta::Node::AttrClause_T clause);
}

namespace lang::meta::Node::AttrMatchCase {
    lang::meta::Node::AttrMatchCase_T make_ext(langcc::ArenaPtr arena, langcc::Int id, langcc::TokenBounds bounds, bool is_top, langcc::ParserSymId sym, langcc::ParserAttrMask attr, langcc::ParserLookahead first_k, lang::meta::Node::AttrMatchCasePattern_T pat, lang::meta::Node::AttrClause_T clause);
}

namespace lang::meta::Node::AttrMatchCase {
    struct _T: lang::meta::Node::_T {
        void write(langcc::Ref<std::ostream> os, langcc::FmtFlags flags);
        void write(langcc::Ref<langcc::PrBufStream_T> pb);
        lang::meta::Node::AttrMatchCasePattern_T pat_;
        lang::meta::Node::AttrClause_T clause_;
        _T();
        lang::meta::Node::AttrMatchCase_T with_id(langcc::Int id);
        lang::meta::Node::AttrMatchCase_T with_bounds(langcc::TokenBounds bounds);
        lang::meta::Node::AttrMatchCase_T with_is_top(bool is_top);
        lang::meta::Node::AttrMatchCase_T with_sym(langcc::ParserSymId sym);
        lang::meta::Node::AttrMatchCase_T with_attr(langcc::ParserAttrMask attr);
        lang::meta::Node::AttrMatchCase_T with_first_k(langcc::ParserLookahead first_k);
        lang::meta::Node::AttrMatchCase_T with_pat(lang::meta::Node::AttrMatchCasePattern_T pat);
        lang::meta::Node::AttrMatchCase_T with_clause(lang::meta::Node::AttrClause_T clause);
        void hash_ser_acc_lang_meta_Node_AttrMatchCase(langcc::SerBuf& buf) const;
        virtual void hash_ser_acc(langcc::SerBuf& buf) const;
    };
}

namespace langcc {
    void pr_debug(ostream& os, FmtFlags flags, lang::meta::Node::AttrMatchCasePattern_T x);
}

namespace lang::meta::Node::AttrMatchCasePattern {
    enum struct _W {
        Alt,
        Wildcard,
    };
}

namespace lang::meta::Node::AttrMatchCasePattern {
    struct _T: lang::meta::Node::_T {
        void write(langcc::Ref<std::ostream> os, langcc::FmtFlags flags);
        void write(langcc::Ref<langcc::PrBufStream_T> pb);
        lang::meta::Node::AttrMatchCasePattern::_W w_;
        virtual ~_T();
        _T(lang::meta::Node::AttrMatchCasePattern::_W w);
        bool is_Alt();
        bool is_Wildcard();
        lang::meta::Node::AttrMatchCasePattern::Alt_T as_Alt();
        lang::meta::Node::AttrMatchCasePattern::Wildcard_T as_Wildcard();
        langcc::Ptr<lang::meta::Node::AttrMatchCasePattern::Alt::_T> as_Alt_unchecked();
        langcc::Ptr<lang::meta::Node::AttrMatchCasePattern::Wildcard::_T> as_Wildcard_unchecked();
        void match(std::function<void(lang::meta::Node::AttrMatchCasePattern::Alt_T)> f_Alt, std::function<void(lang::meta::Node::AttrMatchCasePattern::Wildcard_T)> f_Wildcard);
        template<typename RetT> RetT match_expr(std::function<RetT(lang::meta::Node::AttrMatchCasePattern::Alt_T)> f_Alt, std::function<RetT(lang::meta::Node::AttrMatchCasePattern::Wildcard_T)> f_Wildcard);
        void hash_ser_acc_lang_meta_Node_AttrMatchCasePattern(langcc::SerBuf& buf) const;
        virtual void hash_ser_acc(langcc::SerBuf& buf) const = 0;
    };
}

template<typename RetT> RetT lang::meta::Node::AttrMatchCasePattern::_T::match_expr(std::function<RetT(lang::meta::Node::AttrMatchCasePattern::Alt_T)> f_Alt, std::function<RetT(lang::meta::Node::AttrMatchCasePattern::Wildcard_T)> f_Wildcard) {
    switch (this->w_) {
        case lang::meta::Node::AttrMatchCasePattern::_W::Alt: {
            return f_Alt(this->as_Alt());
            break;
        }
        case lang::meta::Node::AttrMatchCasePattern::_W::Wildcard: {
            return f_Wildcard(this->as_Wildcard());
            break;
        }
        default: {
            langcc::AX();
        }
    }
}

namespace langcc {
    void pr_debug(ostream& os, FmtFlags flags, lang::meta::Node::AttrClauseExpr_T x);
}

namespace lang::meta::Node::AttrClauseExpr {
    enum struct _W {
        LhsGeq,
        RhsGeq,
        Implies,
    };
}

namespace lang::meta::Node::AttrClauseExpr {
    struct _T: lang::meta::Node::_T {
        void write(langcc::Ref<std::ostream> os, langcc::FmtFlags flags);
        void write(langcc::Ref<langcc::PrBufStream_T> pb);
        lang::meta::Node::AttrClauseExpr::_W w_;
        virtual ~_T();
        _T(lang::meta::Node::AttrClauseExpr::_W w);
        bool is_LhsGeq();
        bool is_RhsGeq();
        bool is_Implies();
        lang::meta::Node::AttrClauseExpr::LhsGeq_T as_LhsGeq();
        lang::meta::Node::AttrClauseExpr::RhsGeq_T as_RhsGeq();
        lang::meta::Node::AttrClauseExpr::Implies_T as_Implies();
        langcc::Ptr<lang::meta::Node::AttrClauseExpr::LhsGeq::_T> as_LhsGeq_unchecked();
        langcc::Ptr<lang::meta::Node::AttrClauseExpr::RhsGeq::_T> as_RhsGeq_unchecked();
        langcc::Ptr<lang::meta::Node::AttrClauseExpr::Implies::_T> as_Implies_unchecked();
        void match(std::function<void(lang::meta::Node::AttrClauseExpr::LhsGeq_T)> f_LhsGeq, std::function<void(lang::meta::Node::AttrClauseExpr::RhsGeq_T)> f_RhsGeq, std::function<void(lang::meta::Node::AttrClauseExpr::Implies_T)> f_Implies);
        template<typename RetT> RetT match_expr(std::function<RetT(lang::meta::Node::AttrClauseExpr::LhsGeq_T)> f_LhsGeq, std::function<RetT(lang::meta::Node::AttrClauseExpr::RhsGeq_T)> f_RhsGeq, std::function<RetT(lang::meta::Node::AttrClauseExpr::Implies_T)> f_Implies);
        void hash_ser_acc_lang_meta_Node_AttrClauseExpr(langcc::SerBuf& buf) const;
        virtual void hash_ser_acc(langcc::SerBuf& buf) const = 0;
    };
}

template<typename RetT> RetT lang::meta::Node::AttrClauseExpr::_T::match_expr(std::function<RetT(lang::meta::Node::AttrClauseExpr::LhsGeq_T)> f_LhsGeq, std::function<RetT(lang::meta::Node::AttrClauseExpr::RhsGeq_T)> f_RhsGeq, std::function<RetT(lang::meta::Node::AttrClauseExpr::Implies_T)> f_Implies) {
    switch (this->w_) {
        case lang::meta::Node::AttrClauseExpr::_W::LhsGeq: {
            return f_LhsGeq(this->as_LhsGeq());
            break;
        }
        case lang::meta::Node::AttrClauseExpr::_W::RhsGeq: {
            return f_RhsGeq(this->as_RhsGeq());
            break;
        }
        case lang::meta::Node::AttrClauseExpr::_W::Implies: {
            return f_Implies(this->as_Implies());
            break;
        }
        default: {
            langcc::AX();
        }
    }
}

namespace langcc {
    void pr_debug(ostream& os, FmtFlags flags, lang::meta::Node::AttrClauseExprRhsLoc_T x);
}

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
        void write(langcc::Ref<std::ostream> os, langcc::FmtFlags flags);
        void write(langcc::Ref<langcc::PrBufStream_T> pb);
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
        langcc::Ptr<lang::meta::Node::AttrClauseExprRhsLoc::All::_T> as_All_unchecked();
        langcc::Ptr<lang::meta::Node::AttrClauseExprRhsLoc::Begin::_T> as_Begin_unchecked();
        langcc::Ptr<lang::meta::Node::AttrClauseExprRhsLoc::Mid::_T> as_Mid_unchecked();
        langcc::Ptr<lang::meta::Node::AttrClauseExprRhsLoc::End::_T> as_End_unchecked();
        void match(std::function<void(lang::meta::Node::AttrClauseExprRhsLoc::All_T)> f_All, std::function<void(lang::meta::Node::AttrClauseExprRhsLoc::Begin_T)> f_Begin, std::function<void(lang::meta::Node::AttrClauseExprRhsLoc::Mid_T)> f_Mid, std::function<void(lang::meta::Node::AttrClauseExprRhsLoc::End_T)> f_End);
        template<typename RetT> RetT match_expr(std::function<RetT(lang::meta::Node::AttrClauseExprRhsLoc::All_T)> f_All, std::function<RetT(lang::meta::Node::AttrClauseExprRhsLoc::Begin_T)> f_Begin, std::function<RetT(lang::meta::Node::AttrClauseExprRhsLoc::Mid_T)> f_Mid, std::function<RetT(lang::meta::Node::AttrClauseExprRhsLoc::End_T)> f_End);
        void hash_ser_acc_lang_meta_Node_AttrClauseExprRhsLoc(langcc::SerBuf& buf) const;
        virtual void hash_ser_acc(langcc::SerBuf& buf) const = 0;
    };
}

template<typename RetT> RetT lang::meta::Node::AttrClauseExprRhsLoc::_T::match_expr(std::function<RetT(lang::meta::Node::AttrClauseExprRhsLoc::All_T)> f_All, std::function<RetT(lang::meta::Node::AttrClauseExprRhsLoc::Begin_T)> f_Begin, std::function<RetT(lang::meta::Node::AttrClauseExprRhsLoc::Mid_T)> f_Mid, std::function<RetT(lang::meta::Node::AttrClauseExprRhsLoc::End_T)> f_End) {
    switch (this->w_) {
        case lang::meta::Node::AttrClauseExprRhsLoc::_W::All: {
            return f_All(this->as_All());
            break;
        }
        case lang::meta::Node::AttrClauseExprRhsLoc::_W::Begin: {
            return f_Begin(this->as_Begin());
            break;
        }
        case lang::meta::Node::AttrClauseExprRhsLoc::_W::Mid: {
            return f_Mid(this->as_Mid());
            break;
        }
        case lang::meta::Node::AttrClauseExprRhsLoc::_W::End: {
            return f_End(this->as_End());
            break;
        }
        default: {
            langcc::AX();
        }
    }
}

namespace langcc {
    void pr_debug(ostream& os, FmtFlags flags, lang::meta::Node::TestCase_T x);
}

namespace lang::meta::Node::TestCase {
    lang::meta::Node::TestCase_T make(langcc::Int id, langcc::TokenBounds bounds, bool is_top, langcc::ParserSymId sym, langcc::ParserAttrMask attr, langcc::ParserLookahead first_k, langcc::StrSlice text, langcc::Option_T<langcc::StrSlice> sym_, bool print_exempt);
}

namespace lang::meta::Node::TestCase {
    lang::meta::Node::TestCase_T make_ext(langcc::ArenaPtr arena, langcc::Int id, langcc::TokenBounds bounds, bool is_top, langcc::ParserSymId sym, langcc::ParserAttrMask attr, langcc::ParserLookahead first_k, langcc::StrSlice text, langcc::Option_T<langcc::StrSlice> sym_, bool print_exempt);
}

namespace lang::meta::Node::TestCase {
    struct _T: lang::meta::Node::_T {
        void write(langcc::Ref<std::ostream> os, langcc::FmtFlags flags);
        void write(langcc::Ref<langcc::PrBufStream_T> pb);
        langcc::StrSlice text_;
        langcc::Option_T<langcc::StrSlice> sym__;
        bool print_exempt_;
        _T();
        lang::meta::Node::TestCase_T with_id(langcc::Int id);
        lang::meta::Node::TestCase_T with_bounds(langcc::TokenBounds bounds);
        lang::meta::Node::TestCase_T with_is_top(bool is_top);
        lang::meta::Node::TestCase_T with_sym(langcc::ParserSymId sym);
        lang::meta::Node::TestCase_T with_attr(langcc::ParserAttrMask attr);
        lang::meta::Node::TestCase_T with_first_k(langcc::ParserLookahead first_k);
        lang::meta::Node::TestCase_T with_text(langcc::StrSlice text);
        lang::meta::Node::TestCase_T with_sym_(langcc::Option_T<langcc::StrSlice> sym_);
        lang::meta::Node::TestCase_T with_print_exempt(bool print_exempt);
        void hash_ser_acc_lang_meta_Node_TestCase(langcc::SerBuf& buf) const;
        virtual void hash_ser_acc(langcc::SerBuf& buf) const;
    };
}

namespace langcc {
    void pr_debug(ostream& os, FmtFlags flags, lang::meta::Node::CompileTestCase_T x);
}

namespace lang::meta::Node::CompileTestCase {
    lang::meta::Node::CompileTestCase_T make(langcc::Int id, langcc::TokenBounds bounds, bool is_top, langcc::ParserSymId sym, langcc::ParserAttrMask attr, langcc::ParserLookahead first_k, bool neg, langcc::StrSlice k);
}

namespace lang::meta::Node::CompileTestCase {
    lang::meta::Node::CompileTestCase_T make_ext(langcc::ArenaPtr arena, langcc::Int id, langcc::TokenBounds bounds, bool is_top, langcc::ParserSymId sym, langcc::ParserAttrMask attr, langcc::ParserLookahead first_k, bool neg, langcc::StrSlice k);
}

namespace lang::meta::Node::CompileTestCase {
    struct _T: lang::meta::Node::_T {
        void write(langcc::Ref<std::ostream> os, langcc::FmtFlags flags);
        void write(langcc::Ref<langcc::PrBufStream_T> pb);
        bool neg_;
        langcc::StrSlice k_;
        _T();
        lang::meta::Node::CompileTestCase_T with_id(langcc::Int id);
        lang::meta::Node::CompileTestCase_T with_bounds(langcc::TokenBounds bounds);
        lang::meta::Node::CompileTestCase_T with_is_top(bool is_top);
        lang::meta::Node::CompileTestCase_T with_sym(langcc::ParserSymId sym);
        lang::meta::Node::CompileTestCase_T with_attr(langcc::ParserAttrMask attr);
        lang::meta::Node::CompileTestCase_T with_first_k(langcc::ParserLookahead first_k);
        lang::meta::Node::CompileTestCase_T with_neg(bool neg);
        lang::meta::Node::CompileTestCase_T with_k(langcc::StrSlice k);
        void hash_ser_acc_lang_meta_Node_CompileTestCase(langcc::SerBuf& buf) const;
        virtual void hash_ser_acc(langcc::SerBuf& buf) const;
    };
}

namespace langcc {
    void pr_debug(ostream& os, FmtFlags flags, lang::meta::Node::ParseExpr_T x);
}

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
        void write(langcc::Ref<std::ostream> os, langcc::FmtFlags flags);
        void write(langcc::Ref<langcc::PrBufStream_T> pb);
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
        langcc::Ptr<lang::meta::Node::ParseExpr::Id::_T> as_Id_unchecked();
        langcc::Ptr<lang::meta::Node::ParseExpr::Eof::_T> as_Eof_unchecked();
        langcc::Ptr<lang::meta::Node::ParseExpr::False::_T> as_False_unchecked();
        langcc::Ptr<lang::meta::Node::ParseExpr::Eps::_T> as_Eps_unchecked();
        langcc::Ptr<lang::meta::Node::ParseExpr::Indent::_T> as_Indent_unchecked();
        langcc::Ptr<lang::meta::Node::ParseExpr::Dedent::_T> as_Dedent_unchecked();
        langcc::Ptr<lang::meta::Node::ParseExpr::Newline::_T> as_Newline_unchecked();
        langcc::Ptr<lang::meta::Node::ParseExpr::UnicodeAny::_T> as_UnicodeAny_unchecked();
        langcc::Ptr<lang::meta::Node::ParseExpr::AsciiBaseAny::_T> as_AsciiBaseAny_unchecked();
        langcc::Ptr<lang::meta::Node::ParseExpr::Alt::_T> as_Alt_unchecked();
        langcc::Ptr<lang::meta::Node::ParseExpr::AltExplicit::_T> as_AltExplicit_unchecked();
        langcc::Ptr<lang::meta::Node::ParseExpr::Minus::_T> as_Minus_unchecked();
        langcc::Ptr<lang::meta::Node::ParseExpr::Concat::_T> as_Concat_unchecked();
        langcc::Ptr<lang::meta::Node::ParseExpr::Optional::_T> as_Optional_unchecked();
        langcc::Ptr<lang::meta::Node::ParseExpr::Rep::_T> as_Rep_unchecked();
        langcc::Ptr<lang::meta::Node::ParseExpr::RepNonzero::_T> as_RepNonzero_unchecked();
        langcc::Ptr<lang::meta::Node::ParseExpr::RepCount::_T> as_RepCount_unchecked();
        langcc::Ptr<lang::meta::Node::ParseExpr::CharRange::_T> as_CharRange_unchecked();
        langcc::Ptr<lang::meta::Node::ParseExpr::StrLit::_T> as_StrLit_unchecked();
        langcc::Ptr<lang::meta::Node::ParseExpr::Underscore::_T> as_Underscore_unchecked();
        langcc::Ptr<lang::meta::Node::ParseExpr::Pass::_T> as_Pass_unchecked();
        langcc::Ptr<lang::meta::Node::ParseExpr::Paren::_T> as_Paren_unchecked();
        langcc::Ptr<lang::meta::Node::ParseExpr::Name::_T> as_Name_unchecked();
        langcc::Ptr<lang::meta::Node::ParseExpr::List::_T> as_List_unchecked();
        langcc::Ptr<lang::meta::Node::ParseExpr::Unfold::_T> as_Unfold_unchecked();
        langcc::Ptr<lang::meta::Node::ParseExpr::AttrReq::_T> as_AttrReq_unchecked();
        void match(std::function<void(lang::meta::Node::ParseExpr::Id_T)> f_Id, std::function<void(lang::meta::Node::ParseExpr::Eof_T)> f_Eof, std::function<void(lang::meta::Node::ParseExpr::False_T)> f_False, std::function<void(lang::meta::Node::ParseExpr::Eps_T)> f_Eps, std::function<void(lang::meta::Node::ParseExpr::Indent_T)> f_Indent, std::function<void(lang::meta::Node::ParseExpr::Dedent_T)> f_Dedent, std::function<void(lang::meta::Node::ParseExpr::Newline_T)> f_Newline, std::function<void(lang::meta::Node::ParseExpr::UnicodeAny_T)> f_UnicodeAny, std::function<void(lang::meta::Node::ParseExpr::AsciiBaseAny_T)> f_AsciiBaseAny, std::function<void(lang::meta::Node::ParseExpr::Alt_T)> f_Alt, std::function<void(lang::meta::Node::ParseExpr::AltExplicit_T)> f_AltExplicit, std::function<void(lang::meta::Node::ParseExpr::Minus_T)> f_Minus, std::function<void(lang::meta::Node::ParseExpr::Concat_T)> f_Concat, std::function<void(lang::meta::Node::ParseExpr::Optional_T)> f_Optional, std::function<void(lang::meta::Node::ParseExpr::Rep_T)> f_Rep, std::function<void(lang::meta::Node::ParseExpr::RepNonzero_T)> f_RepNonzero, std::function<void(lang::meta::Node::ParseExpr::RepCount_T)> f_RepCount, std::function<void(lang::meta::Node::ParseExpr::CharRange_T)> f_CharRange, std::function<void(lang::meta::Node::ParseExpr::StrLit_T)> f_StrLit, std::function<void(lang::meta::Node::ParseExpr::Underscore_T)> f_Underscore, std::function<void(lang::meta::Node::ParseExpr::Pass_T)> f_Pass, std::function<void(lang::meta::Node::ParseExpr::Paren_T)> f_Paren, std::function<void(lang::meta::Node::ParseExpr::Name_T)> f_Name, std::function<void(lang::meta::Node::ParseExpr::List_T)> f_List, std::function<void(lang::meta::Node::ParseExpr::Unfold_T)> f_Unfold, std::function<void(lang::meta::Node::ParseExpr::AttrReq_T)> f_AttrReq);
        template<typename RetT> RetT match_expr(std::function<RetT(lang::meta::Node::ParseExpr::Id_T)> f_Id, std::function<RetT(lang::meta::Node::ParseExpr::Eof_T)> f_Eof, std::function<RetT(lang::meta::Node::ParseExpr::False_T)> f_False, std::function<RetT(lang::meta::Node::ParseExpr::Eps_T)> f_Eps, std::function<RetT(lang::meta::Node::ParseExpr::Indent_T)> f_Indent, std::function<RetT(lang::meta::Node::ParseExpr::Dedent_T)> f_Dedent, std::function<RetT(lang::meta::Node::ParseExpr::Newline_T)> f_Newline, std::function<RetT(lang::meta::Node::ParseExpr::UnicodeAny_T)> f_UnicodeAny, std::function<RetT(lang::meta::Node::ParseExpr::AsciiBaseAny_T)> f_AsciiBaseAny, std::function<RetT(lang::meta::Node::ParseExpr::Alt_T)> f_Alt, std::function<RetT(lang::meta::Node::ParseExpr::AltExplicit_T)> f_AltExplicit, std::function<RetT(lang::meta::Node::ParseExpr::Minus_T)> f_Minus, std::function<RetT(lang::meta::Node::ParseExpr::Concat_T)> f_Concat, std::function<RetT(lang::meta::Node::ParseExpr::Optional_T)> f_Optional, std::function<RetT(lang::meta::Node::ParseExpr::Rep_T)> f_Rep, std::function<RetT(lang::meta::Node::ParseExpr::RepNonzero_T)> f_RepNonzero, std::function<RetT(lang::meta::Node::ParseExpr::RepCount_T)> f_RepCount, std::function<RetT(lang::meta::Node::ParseExpr::CharRange_T)> f_CharRange, std::function<RetT(lang::meta::Node::ParseExpr::StrLit_T)> f_StrLit, std::function<RetT(lang::meta::Node::ParseExpr::Underscore_T)> f_Underscore, std::function<RetT(lang::meta::Node::ParseExpr::Pass_T)> f_Pass, std::function<RetT(lang::meta::Node::ParseExpr::Paren_T)> f_Paren, std::function<RetT(lang::meta::Node::ParseExpr::Name_T)> f_Name, std::function<RetT(lang::meta::Node::ParseExpr::List_T)> f_List, std::function<RetT(lang::meta::Node::ParseExpr::Unfold_T)> f_Unfold, std::function<RetT(lang::meta::Node::ParseExpr::AttrReq_T)> f_AttrReq);
        void hash_ser_acc_lang_meta_Node_ParseExpr(langcc::SerBuf& buf) const;
        virtual void hash_ser_acc(langcc::SerBuf& buf) const = 0;
    };
}

template<typename RetT> RetT lang::meta::Node::ParseExpr::_T::match_expr(std::function<RetT(lang::meta::Node::ParseExpr::Id_T)> f_Id, std::function<RetT(lang::meta::Node::ParseExpr::Eof_T)> f_Eof, std::function<RetT(lang::meta::Node::ParseExpr::False_T)> f_False, std::function<RetT(lang::meta::Node::ParseExpr::Eps_T)> f_Eps, std::function<RetT(lang::meta::Node::ParseExpr::Indent_T)> f_Indent, std::function<RetT(lang::meta::Node::ParseExpr::Dedent_T)> f_Dedent, std::function<RetT(lang::meta::Node::ParseExpr::Newline_T)> f_Newline, std::function<RetT(lang::meta::Node::ParseExpr::UnicodeAny_T)> f_UnicodeAny, std::function<RetT(lang::meta::Node::ParseExpr::AsciiBaseAny_T)> f_AsciiBaseAny, std::function<RetT(lang::meta::Node::ParseExpr::Alt_T)> f_Alt, std::function<RetT(lang::meta::Node::ParseExpr::AltExplicit_T)> f_AltExplicit, std::function<RetT(lang::meta::Node::ParseExpr::Minus_T)> f_Minus, std::function<RetT(lang::meta::Node::ParseExpr::Concat_T)> f_Concat, std::function<RetT(lang::meta::Node::ParseExpr::Optional_T)> f_Optional, std::function<RetT(lang::meta::Node::ParseExpr::Rep_T)> f_Rep, std::function<RetT(lang::meta::Node::ParseExpr::RepNonzero_T)> f_RepNonzero, std::function<RetT(lang::meta::Node::ParseExpr::RepCount_T)> f_RepCount, std::function<RetT(lang::meta::Node::ParseExpr::CharRange_T)> f_CharRange, std::function<RetT(lang::meta::Node::ParseExpr::StrLit_T)> f_StrLit, std::function<RetT(lang::meta::Node::ParseExpr::Underscore_T)> f_Underscore, std::function<RetT(lang::meta::Node::ParseExpr::Pass_T)> f_Pass, std::function<RetT(lang::meta::Node::ParseExpr::Paren_T)> f_Paren, std::function<RetT(lang::meta::Node::ParseExpr::Name_T)> f_Name, std::function<RetT(lang::meta::Node::ParseExpr::List_T)> f_List, std::function<RetT(lang::meta::Node::ParseExpr::Unfold_T)> f_Unfold, std::function<RetT(lang::meta::Node::ParseExpr::AttrReq_T)> f_AttrReq) {
    switch (this->w_) {
        case lang::meta::Node::ParseExpr::_W::Id: {
            return f_Id(this->as_Id());
            break;
        }
        case lang::meta::Node::ParseExpr::_W::Eof: {
            return f_Eof(this->as_Eof());
            break;
        }
        case lang::meta::Node::ParseExpr::_W::False: {
            return f_False(this->as_False());
            break;
        }
        case lang::meta::Node::ParseExpr::_W::Eps: {
            return f_Eps(this->as_Eps());
            break;
        }
        case lang::meta::Node::ParseExpr::_W::Indent: {
            return f_Indent(this->as_Indent());
            break;
        }
        case lang::meta::Node::ParseExpr::_W::Dedent: {
            return f_Dedent(this->as_Dedent());
            break;
        }
        case lang::meta::Node::ParseExpr::_W::Newline: {
            return f_Newline(this->as_Newline());
            break;
        }
        case lang::meta::Node::ParseExpr::_W::UnicodeAny: {
            return f_UnicodeAny(this->as_UnicodeAny());
            break;
        }
        case lang::meta::Node::ParseExpr::_W::AsciiBaseAny: {
            return f_AsciiBaseAny(this->as_AsciiBaseAny());
            break;
        }
        case lang::meta::Node::ParseExpr::_W::Alt: {
            return f_Alt(this->as_Alt());
            break;
        }
        case lang::meta::Node::ParseExpr::_W::AltExplicit: {
            return f_AltExplicit(this->as_AltExplicit());
            break;
        }
        case lang::meta::Node::ParseExpr::_W::Minus: {
            return f_Minus(this->as_Minus());
            break;
        }
        case lang::meta::Node::ParseExpr::_W::Concat: {
            return f_Concat(this->as_Concat());
            break;
        }
        case lang::meta::Node::ParseExpr::_W::Optional: {
            return f_Optional(this->as_Optional());
            break;
        }
        case lang::meta::Node::ParseExpr::_W::Rep: {
            return f_Rep(this->as_Rep());
            break;
        }
        case lang::meta::Node::ParseExpr::_W::RepNonzero: {
            return f_RepNonzero(this->as_RepNonzero());
            break;
        }
        case lang::meta::Node::ParseExpr::_W::RepCount: {
            return f_RepCount(this->as_RepCount());
            break;
        }
        case lang::meta::Node::ParseExpr::_W::CharRange: {
            return f_CharRange(this->as_CharRange());
            break;
        }
        case lang::meta::Node::ParseExpr::_W::StrLit: {
            return f_StrLit(this->as_StrLit());
            break;
        }
        case lang::meta::Node::ParseExpr::_W::Underscore: {
            return f_Underscore(this->as_Underscore());
            break;
        }
        case lang::meta::Node::ParseExpr::_W::Pass: {
            return f_Pass(this->as_Pass());
            break;
        }
        case lang::meta::Node::ParseExpr::_W::Paren: {
            return f_Paren(this->as_Paren());
            break;
        }
        case lang::meta::Node::ParseExpr::_W::Name: {
            return f_Name(this->as_Name());
            break;
        }
        case lang::meta::Node::ParseExpr::_W::List: {
            return f_List(this->as_List());
            break;
        }
        case lang::meta::Node::ParseExpr::_W::Unfold: {
            return f_Unfold(this->as_Unfold());
            break;
        }
        case lang::meta::Node::ParseExpr::_W::AttrReq: {
            return f_AttrReq(this->as_AttrReq());
            break;
        }
        default: {
            langcc::AX();
        }
    }
}

namespace langcc {
    void pr_debug(ostream& os, FmtFlags flags, lang::meta::Node::AttrReq_T x);
}

namespace lang::meta::Node::AttrReq {
    enum struct _W {
        Base,
        PrecStar,
    };
}

namespace lang::meta::Node::AttrReq {
    struct _T: lang::meta::Node::_T {
        void write(langcc::Ref<std::ostream> os, langcc::FmtFlags flags);
        void write(langcc::Ref<langcc::PrBufStream_T> pb);
        lang::meta::Node::AttrReq::_W w_;
        virtual ~_T();
        _T(lang::meta::Node::AttrReq::_W w);
        bool is_Base();
        bool is_PrecStar();
        lang::meta::Node::AttrReq::Base_T as_Base();
        lang::meta::Node::AttrReq::PrecStar_T as_PrecStar();
        langcc::Ptr<lang::meta::Node::AttrReq::Base::_T> as_Base_unchecked();
        langcc::Ptr<lang::meta::Node::AttrReq::PrecStar::_T> as_PrecStar_unchecked();
        void match(std::function<void(lang::meta::Node::AttrReq::Base_T)> f_Base, std::function<void(lang::meta::Node::AttrReq::PrecStar_T)> f_PrecStar);
        template<typename RetT> RetT match_expr(std::function<RetT(lang::meta::Node::AttrReq::Base_T)> f_Base, std::function<RetT(lang::meta::Node::AttrReq::PrecStar_T)> f_PrecStar);
        void hash_ser_acc_lang_meta_Node_AttrReq(langcc::SerBuf& buf) const;
        virtual void hash_ser_acc(langcc::SerBuf& buf) const = 0;
    };
}

template<typename RetT> RetT lang::meta::Node::AttrReq::_T::match_expr(std::function<RetT(lang::meta::Node::AttrReq::Base_T)> f_Base, std::function<RetT(lang::meta::Node::AttrReq::PrecStar_T)> f_PrecStar) {
    switch (this->w_) {
        case lang::meta::Node::AttrReq::_W::Base: {
            return f_Base(this->as_Base());
            break;
        }
        case lang::meta::Node::AttrReq::_W::PrecStar: {
            return f_PrecStar(this->as_PrecStar());
            break;
        }
        default: {
            langcc::AX();
        }
    }
}

namespace langcc {
    void pr_debug(ostream& os, FmtFlags flags, lang::meta::Node::ParseExprListType_T x);
}

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
        void write(langcc::Ref<std::ostream> os, langcc::FmtFlags flags);
        void write(langcc::Ref<langcc::PrBufStream_T> pb);
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
        langcc::Ptr<lang::meta::Node::ParseExprListType::List::_T> as_List_unchecked();
        langcc::Ptr<lang::meta::Node::ParseExprListType::Block::_T> as_Block_unchecked();
        langcc::Ptr<lang::meta::Node::ParseExprListType::Block2::_T> as_Block2_unchecked();
        langcc::Ptr<lang::meta::Node::ParseExprListType::Top::_T> as_Top_unchecked();
        langcc::Ptr<lang::meta::Node::ParseExprListType::Top2::_T> as_Top2_unchecked();
        void match(std::function<void(lang::meta::Node::ParseExprListType::List_T)> f_List, std::function<void(lang::meta::Node::ParseExprListType::Block_T)> f_Block, std::function<void(lang::meta::Node::ParseExprListType::Block2_T)> f_Block2, std::function<void(lang::meta::Node::ParseExprListType::Top_T)> f_Top, std::function<void(lang::meta::Node::ParseExprListType::Top2_T)> f_Top2);
        template<typename RetT> RetT match_expr(std::function<RetT(lang::meta::Node::ParseExprListType::List_T)> f_List, std::function<RetT(lang::meta::Node::ParseExprListType::Block_T)> f_Block, std::function<RetT(lang::meta::Node::ParseExprListType::Block2_T)> f_Block2, std::function<RetT(lang::meta::Node::ParseExprListType::Top_T)> f_Top, std::function<RetT(lang::meta::Node::ParseExprListType::Top2_T)> f_Top2);
        void hash_ser_acc_lang_meta_Node_ParseExprListType(langcc::SerBuf& buf) const;
        virtual void hash_ser_acc(langcc::SerBuf& buf) const = 0;
    };
}

template<typename RetT> RetT lang::meta::Node::ParseExprListType::_T::match_expr(std::function<RetT(lang::meta::Node::ParseExprListType::List_T)> f_List, std::function<RetT(lang::meta::Node::ParseExprListType::Block_T)> f_Block, std::function<RetT(lang::meta::Node::ParseExprListType::Block2_T)> f_Block2, std::function<RetT(lang::meta::Node::ParseExprListType::Top_T)> f_Top, std::function<RetT(lang::meta::Node::ParseExprListType::Top2_T)> f_Top2) {
    switch (this->w_) {
        case lang::meta::Node::ParseExprListType::_W::List: {
            return f_List(this->as_List());
            break;
        }
        case lang::meta::Node::ParseExprListType::_W::Block: {
            return f_Block(this->as_Block());
            break;
        }
        case lang::meta::Node::ParseExprListType::_W::Block2: {
            return f_Block2(this->as_Block2());
            break;
        }
        case lang::meta::Node::ParseExprListType::_W::Top: {
            return f_Top(this->as_Top());
            break;
        }
        case lang::meta::Node::ParseExprListType::_W::Top2: {
            return f_Top2(this->as_Top2());
            break;
        }
        default: {
            langcc::AX();
        }
    }
}

namespace langcc {
    void pr_debug(ostream& os, FmtFlags flags, lang::meta::Node::ParseExprListNum_T x);
}

namespace lang::meta::Node::ParseExprListNum {
    enum struct _W {
        Ge0,
        Ge1,
        Ge2,
    };
}

namespace lang::meta::Node::ParseExprListNum {
    struct _T: lang::meta::Node::_T {
        void write(langcc::Ref<std::ostream> os, langcc::FmtFlags flags);
        void write(langcc::Ref<langcc::PrBufStream_T> pb);
        lang::meta::Node::ParseExprListNum::_W w_;
        virtual ~_T();
        _T(lang::meta::Node::ParseExprListNum::_W w);
        bool is_Ge0();
        bool is_Ge1();
        bool is_Ge2();
        lang::meta::Node::ParseExprListNum::Ge0_T as_Ge0();
        lang::meta::Node::ParseExprListNum::Ge1_T as_Ge1();
        lang::meta::Node::ParseExprListNum::Ge2_T as_Ge2();
        langcc::Ptr<lang::meta::Node::ParseExprListNum::Ge0::_T> as_Ge0_unchecked();
        langcc::Ptr<lang::meta::Node::ParseExprListNum::Ge1::_T> as_Ge1_unchecked();
        langcc::Ptr<lang::meta::Node::ParseExprListNum::Ge2::_T> as_Ge2_unchecked();
        void match(std::function<void(lang::meta::Node::ParseExprListNum::Ge0_T)> f_Ge0, std::function<void(lang::meta::Node::ParseExprListNum::Ge1_T)> f_Ge1, std::function<void(lang::meta::Node::ParseExprListNum::Ge2_T)> f_Ge2);
        template<typename RetT> RetT match_expr(std::function<RetT(lang::meta::Node::ParseExprListNum::Ge0_T)> f_Ge0, std::function<RetT(lang::meta::Node::ParseExprListNum::Ge1_T)> f_Ge1, std::function<RetT(lang::meta::Node::ParseExprListNum::Ge2_T)> f_Ge2);
        void hash_ser_acc_lang_meta_Node_ParseExprListNum(langcc::SerBuf& buf) const;
        virtual void hash_ser_acc(langcc::SerBuf& buf) const = 0;
    };
}

template<typename RetT> RetT lang::meta::Node::ParseExprListNum::_T::match_expr(std::function<RetT(lang::meta::Node::ParseExprListNum::Ge0_T)> f_Ge0, std::function<RetT(lang::meta::Node::ParseExprListNum::Ge1_T)> f_Ge1, std::function<RetT(lang::meta::Node::ParseExprListNum::Ge2_T)> f_Ge2) {
    switch (this->w_) {
        case lang::meta::Node::ParseExprListNum::_W::Ge0: {
            return f_Ge0(this->as_Ge0());
            break;
        }
        case lang::meta::Node::ParseExprListNum::_W::Ge1: {
            return f_Ge1(this->as_Ge1());
            break;
        }
        case lang::meta::Node::ParseExprListNum::_W::Ge2: {
            return f_Ge2(this->as_Ge2());
            break;
        }
        default: {
            langcc::AX();
        }
    }
}

namespace langcc {
    void pr_debug(ostream& os, FmtFlags flags, lang::meta::Node::Id_T x);
}

namespace lang::meta::Node::Id {
    lang::meta::Node::Id_T make(langcc::Int id, langcc::TokenBounds bounds, bool is_top, langcc::ParserSymId sym, langcc::ParserAttrMask attr, langcc::ParserLookahead first_k, langcc::Vec_T<langcc::StrSlice> names);
}

namespace lang::meta::Node::Id {
    lang::meta::Node::Id_T make_ext(langcc::ArenaPtr arena, langcc::Int id, langcc::TokenBounds bounds, bool is_top, langcc::ParserSymId sym, langcc::ParserAttrMask attr, langcc::ParserLookahead first_k, langcc::Vec_T<langcc::StrSlice> names);
}

namespace lang::meta::Node::Id {
    struct _T: lang::meta::Node::_T {
        void write(langcc::Ref<std::ostream> os, langcc::FmtFlags flags);
        void write(langcc::Ref<langcc::PrBufStream_T> pb);
        langcc::Vec_T<langcc::StrSlice> names_;
        _T();
        lang::meta::Node::Id_T with_id(langcc::Int id);
        lang::meta::Node::Id_T with_bounds(langcc::TokenBounds bounds);
        lang::meta::Node::Id_T with_is_top(bool is_top);
        lang::meta::Node::Id_T with_sym(langcc::ParserSymId sym);
        lang::meta::Node::Id_T with_attr(langcc::ParserAttrMask attr);
        lang::meta::Node::Id_T with_first_k(langcc::ParserLookahead first_k);
        lang::meta::Node::Id_T with_names(langcc::Vec_T<langcc::StrSlice> names);
        void hash_ser_acc_lang_meta_Node_Id(langcc::SerBuf& buf) const;
        virtual void hash_ser_acc(langcc::SerBuf& buf) const;
    };
}

namespace langcc {
    void pr_debug(ostream& os, FmtFlags flags, lang::meta::Node::Decl::Include_T x);
}

namespace lang::meta::Node::Decl::Include {
    lang::meta::Node::Decl::Include_T make(langcc::Int id, langcc::TokenBounds bounds, bool is_top, langcc::ParserSymId sym, langcc::ParserAttrMask attr, langcc::ParserLookahead first_k, langcc::StrSlice path);
}

namespace lang::meta::Node::Decl::Include {
    lang::meta::Node::Decl::Include_T make_ext(langcc::ArenaPtr arena, langcc::Int id, langcc::TokenBounds bounds, bool is_top, langcc::ParserSymId sym, langcc::ParserAttrMask attr, langcc::ParserLookahead first_k, langcc::StrSlice path);
}

namespace lang::meta::Node::Decl::Include {
    struct _T: lang::meta::Node::Decl::_T {
        void write(langcc::Ref<std::ostream> os, langcc::FmtFlags flags);
        void write(langcc::Ref<langcc::PrBufStream_T> pb);
        langcc::StrSlice path_;
        _T();
        lang::meta::Node::Decl::Include_T with_id(langcc::Int id);
        lang::meta::Node::Decl::Include_T with_bounds(langcc::TokenBounds bounds);
        lang::meta::Node::Decl::Include_T with_is_top(bool is_top);
        lang::meta::Node::Decl::Include_T with_sym(langcc::ParserSymId sym);
        lang::meta::Node::Decl::Include_T with_attr(langcc::ParserAttrMask attr);
        lang::meta::Node::Decl::Include_T with_first_k(langcc::ParserLookahead first_k);
        lang::meta::Node::Decl::Include_T with_path(langcc::StrSlice path);
        void hash_ser_acc_lang_meta_Node_Decl_Include(langcc::SerBuf& buf) const;
        virtual void hash_ser_acc(langcc::SerBuf& buf) const;
    };
}

namespace langcc {
    void pr_debug(ostream& os, FmtFlags flags, lang::meta::Node::Decl::IncludePost_T x);
}

namespace lang::meta::Node::Decl::IncludePost {
    lang::meta::Node::Decl::IncludePost_T make(langcc::Int id, langcc::TokenBounds bounds, bool is_top, langcc::ParserSymId sym, langcc::ParserAttrMask attr, langcc::ParserLookahead first_k, langcc::StrSlice path);
}

namespace lang::meta::Node::Decl::IncludePost {
    lang::meta::Node::Decl::IncludePost_T make_ext(langcc::ArenaPtr arena, langcc::Int id, langcc::TokenBounds bounds, bool is_top, langcc::ParserSymId sym, langcc::ParserAttrMask attr, langcc::ParserLookahead first_k, langcc::StrSlice path);
}

namespace lang::meta::Node::Decl::IncludePost {
    struct _T: lang::meta::Node::Decl::_T {
        void write(langcc::Ref<std::ostream> os, langcc::FmtFlags flags);
        void write(langcc::Ref<langcc::PrBufStream_T> pb);
        langcc::StrSlice path_;
        _T();
        lang::meta::Node::Decl::IncludePost_T with_id(langcc::Int id);
        lang::meta::Node::Decl::IncludePost_T with_bounds(langcc::TokenBounds bounds);
        lang::meta::Node::Decl::IncludePost_T with_is_top(bool is_top);
        lang::meta::Node::Decl::IncludePost_T with_sym(langcc::ParserSymId sym);
        lang::meta::Node::Decl::IncludePost_T with_attr(langcc::ParserAttrMask attr);
        lang::meta::Node::Decl::IncludePost_T with_first_k(langcc::ParserLookahead first_k);
        lang::meta::Node::Decl::IncludePost_T with_path(langcc::StrSlice path);
        void hash_ser_acc_lang_meta_Node_Decl_IncludePost(langcc::SerBuf& buf) const;
        virtual void hash_ser_acc(langcc::SerBuf& buf) const;
    };
}

namespace langcc {
    void pr_debug(ostream& os, FmtFlags flags, lang::meta::Node::Stanza::Tokens_T x);
}

namespace lang::meta::Node::Stanza::Tokens {
    lang::meta::Node::Stanza::Tokens_T make(langcc::Int id, langcc::TokenBounds bounds, bool is_top, langcc::ParserSymId sym, langcc::ParserAttrMask attr, langcc::ParserLookahead first_k, langcc::Vec_T<lang::meta::Node::TokenDecl_T> decls);
}

namespace lang::meta::Node::Stanza::Tokens {
    lang::meta::Node::Stanza::Tokens_T make_ext(langcc::ArenaPtr arena, langcc::Int id, langcc::TokenBounds bounds, bool is_top, langcc::ParserSymId sym, langcc::ParserAttrMask attr, langcc::ParserLookahead first_k, langcc::Vec_T<lang::meta::Node::TokenDecl_T> decls);
}

namespace lang::meta::Node::Stanza::Tokens {
    struct _T: lang::meta::Node::Stanza::_T {
        void write(langcc::Ref<std::ostream> os, langcc::FmtFlags flags);
        void write(langcc::Ref<langcc::PrBufStream_T> pb);
        langcc::Vec_T<lang::meta::Node::TokenDecl_T> decls_;
        _T();
        lang::meta::Node::Stanza::Tokens_T with_id(langcc::Int id);
        lang::meta::Node::Stanza::Tokens_T with_bounds(langcc::TokenBounds bounds);
        lang::meta::Node::Stanza::Tokens_T with_is_top(bool is_top);
        lang::meta::Node::Stanza::Tokens_T with_sym(langcc::ParserSymId sym);
        lang::meta::Node::Stanza::Tokens_T with_attr(langcc::ParserAttrMask attr);
        lang::meta::Node::Stanza::Tokens_T with_first_k(langcc::ParserLookahead first_k);
        lang::meta::Node::Stanza::Tokens_T with_decls(langcc::Vec_T<lang::meta::Node::TokenDecl_T> decls);
        void hash_ser_acc_lang_meta_Node_Stanza_Tokens(langcc::SerBuf& buf) const;
        virtual void hash_ser_acc(langcc::SerBuf& buf) const;
    };
}

namespace langcc {
    void pr_debug(ostream& os, FmtFlags flags, lang::meta::Node::Stanza::Lexer_T x);
}

namespace lang::meta::Node::Stanza::Lexer {
    lang::meta::Node::Stanza::Lexer_T make(langcc::Int id, langcc::TokenBounds bounds, bool is_top, langcc::ParserSymId sym, langcc::ParserAttrMask attr, langcc::ParserLookahead first_k, langcc::Vec_T<lang::meta::Node::LexerDecl_T> decls);
}

namespace lang::meta::Node::Stanza::Lexer {
    lang::meta::Node::Stanza::Lexer_T make_ext(langcc::ArenaPtr arena, langcc::Int id, langcc::TokenBounds bounds, bool is_top, langcc::ParserSymId sym, langcc::ParserAttrMask attr, langcc::ParserLookahead first_k, langcc::Vec_T<lang::meta::Node::LexerDecl_T> decls);
}

namespace lang::meta::Node::Stanza::Lexer {
    struct _T: lang::meta::Node::Stanza::_T {
        void write(langcc::Ref<std::ostream> os, langcc::FmtFlags flags);
        void write(langcc::Ref<langcc::PrBufStream_T> pb);
        langcc::Vec_T<lang::meta::Node::LexerDecl_T> decls_;
        _T();
        lang::meta::Node::Stanza::Lexer_T with_id(langcc::Int id);
        lang::meta::Node::Stanza::Lexer_T with_bounds(langcc::TokenBounds bounds);
        lang::meta::Node::Stanza::Lexer_T with_is_top(bool is_top);
        lang::meta::Node::Stanza::Lexer_T with_sym(langcc::ParserSymId sym);
        lang::meta::Node::Stanza::Lexer_T with_attr(langcc::ParserAttrMask attr);
        lang::meta::Node::Stanza::Lexer_T with_first_k(langcc::ParserLookahead first_k);
        lang::meta::Node::Stanza::Lexer_T with_decls(langcc::Vec_T<lang::meta::Node::LexerDecl_T> decls);
        void hash_ser_acc_lang_meta_Node_Stanza_Lexer(langcc::SerBuf& buf) const;
        virtual void hash_ser_acc(langcc::SerBuf& buf) const;
    };
}

namespace langcc {
    void pr_debug(ostream& os, FmtFlags flags, lang::meta::Node::Stanza::Parser_T x);
}

namespace lang::meta::Node::Stanza::Parser {
    lang::meta::Node::Stanza::Parser_T make(langcc::Int id, langcc::TokenBounds bounds, bool is_top, langcc::ParserSymId sym, langcc::ParserAttrMask attr, langcc::ParserLookahead first_k, langcc::Vec_T<lang::meta::Node::ParserDecl_T> decls);
}

namespace lang::meta::Node::Stanza::Parser {
    lang::meta::Node::Stanza::Parser_T make_ext(langcc::ArenaPtr arena, langcc::Int id, langcc::TokenBounds bounds, bool is_top, langcc::ParserSymId sym, langcc::ParserAttrMask attr, langcc::ParserLookahead first_k, langcc::Vec_T<lang::meta::Node::ParserDecl_T> decls);
}

namespace lang::meta::Node::Stanza::Parser {
    struct _T: lang::meta::Node::Stanza::_T {
        void write(langcc::Ref<std::ostream> os, langcc::FmtFlags flags);
        void write(langcc::Ref<langcc::PrBufStream_T> pb);
        langcc::Vec_T<lang::meta::Node::ParserDecl_T> decls_;
        _T();
        lang::meta::Node::Stanza::Parser_T with_id(langcc::Int id);
        lang::meta::Node::Stanza::Parser_T with_bounds(langcc::TokenBounds bounds);
        lang::meta::Node::Stanza::Parser_T with_is_top(bool is_top);
        lang::meta::Node::Stanza::Parser_T with_sym(langcc::ParserSymId sym);
        lang::meta::Node::Stanza::Parser_T with_attr(langcc::ParserAttrMask attr);
        lang::meta::Node::Stanza::Parser_T with_first_k(langcc::ParserLookahead first_k);
        lang::meta::Node::Stanza::Parser_T with_decls(langcc::Vec_T<lang::meta::Node::ParserDecl_T> decls);
        void hash_ser_acc_lang_meta_Node_Stanza_Parser(langcc::SerBuf& buf) const;
        virtual void hash_ser_acc(langcc::SerBuf& buf) const;
    };
}

namespace langcc {
    void pr_debug(ostream& os, FmtFlags flags, lang::meta::Node::Stanza::Test_T x);
}

namespace lang::meta::Node::Stanza::Test {
    lang::meta::Node::Stanza::Test_T make(langcc::Int id, langcc::TokenBounds bounds, bool is_top, langcc::ParserSymId sym, langcc::ParserAttrMask attr, langcc::ParserLookahead first_k, langcc::Vec_T<lang::meta::Node::TestCase_T> items);
}

namespace lang::meta::Node::Stanza::Test {
    lang::meta::Node::Stanza::Test_T make_ext(langcc::ArenaPtr arena, langcc::Int id, langcc::TokenBounds bounds, bool is_top, langcc::ParserSymId sym, langcc::ParserAttrMask attr, langcc::ParserLookahead first_k, langcc::Vec_T<lang::meta::Node::TestCase_T> items);
}

namespace lang::meta::Node::Stanza::Test {
    struct _T: lang::meta::Node::Stanza::_T {
        void write(langcc::Ref<std::ostream> os, langcc::FmtFlags flags);
        void write(langcc::Ref<langcc::PrBufStream_T> pb);
        langcc::Vec_T<lang::meta::Node::TestCase_T> items_;
        _T();
        lang::meta::Node::Stanza::Test_T with_id(langcc::Int id);
        lang::meta::Node::Stanza::Test_T with_bounds(langcc::TokenBounds bounds);
        lang::meta::Node::Stanza::Test_T with_is_top(bool is_top);
        lang::meta::Node::Stanza::Test_T with_sym(langcc::ParserSymId sym);
        lang::meta::Node::Stanza::Test_T with_attr(langcc::ParserAttrMask attr);
        lang::meta::Node::Stanza::Test_T with_first_k(langcc::ParserLookahead first_k);
        lang::meta::Node::Stanza::Test_T with_items(langcc::Vec_T<lang::meta::Node::TestCase_T> items);
        void hash_ser_acc_lang_meta_Node_Stanza_Test(langcc::SerBuf& buf) const;
        virtual void hash_ser_acc(langcc::SerBuf& buf) const;
    };
}

namespace langcc {
    void pr_debug(ostream& os, FmtFlags flags, lang::meta::Node::Stanza::CompileTest_T x);
}

namespace lang::meta::Node::Stanza::CompileTest {
    lang::meta::Node::Stanza::CompileTest_T make(langcc::Int id, langcc::TokenBounds bounds, bool is_top, langcc::ParserSymId sym, langcc::ParserAttrMask attr, langcc::ParserLookahead first_k, langcc::Vec_T<lang::meta::Node::CompileTestCase_T> items);
}

namespace lang::meta::Node::Stanza::CompileTest {
    lang::meta::Node::Stanza::CompileTest_T make_ext(langcc::ArenaPtr arena, langcc::Int id, langcc::TokenBounds bounds, bool is_top, langcc::ParserSymId sym, langcc::ParserAttrMask attr, langcc::ParserLookahead first_k, langcc::Vec_T<lang::meta::Node::CompileTestCase_T> items);
}

namespace lang::meta::Node::Stanza::CompileTest {
    struct _T: lang::meta::Node::Stanza::_T {
        void write(langcc::Ref<std::ostream> os, langcc::FmtFlags flags);
        void write(langcc::Ref<langcc::PrBufStream_T> pb);
        langcc::Vec_T<lang::meta::Node::CompileTestCase_T> items_;
        _T();
        lang::meta::Node::Stanza::CompileTest_T with_id(langcc::Int id);
        lang::meta::Node::Stanza::CompileTest_T with_bounds(langcc::TokenBounds bounds);
        lang::meta::Node::Stanza::CompileTest_T with_is_top(bool is_top);
        lang::meta::Node::Stanza::CompileTest_T with_sym(langcc::ParserSymId sym);
        lang::meta::Node::Stanza::CompileTest_T with_attr(langcc::ParserAttrMask attr);
        lang::meta::Node::Stanza::CompileTest_T with_first_k(langcc::ParserLookahead first_k);
        lang::meta::Node::Stanza::CompileTest_T with_items(langcc::Vec_T<lang::meta::Node::CompileTestCase_T> items);
        void hash_ser_acc_lang_meta_Node_Stanza_CompileTest(langcc::SerBuf& buf) const;
        virtual void hash_ser_acc(langcc::SerBuf& buf) const;
    };
}

namespace langcc {
    void pr_debug(ostream& os, FmtFlags flags, lang::meta::Node::TokenDecl::op_T x);
}

namespace lang::meta::Node::TokenDecl::op {
    enum struct _W {
        DEF,
        DEF_ALIAS,
    };
}

namespace lang::meta::Node::TokenDecl::op {
    struct _T: lang::meta::Node::_T {
        void write(langcc::Ref<std::ostream> os, langcc::FmtFlags flags);
        void write(langcc::Ref<langcc::PrBufStream_T> pb);
        lang::meta::Node::TokenDecl::op::_W w_;
        virtual ~_T();
        _T(lang::meta::Node::TokenDecl::op::_W w);
        bool is_DEF();
        bool is_DEF_ALIAS();
        lang::meta::Node::TokenDecl::op::DEF_T as_DEF();
        lang::meta::Node::TokenDecl::op::DEF_ALIAS_T as_DEF_ALIAS();
        langcc::Ptr<lang::meta::Node::TokenDecl::op::DEF::_T> as_DEF_unchecked();
        langcc::Ptr<lang::meta::Node::TokenDecl::op::DEF_ALIAS::_T> as_DEF_ALIAS_unchecked();
        void match(std::function<void(lang::meta::Node::TokenDecl::op::DEF_T)> f_DEF, std::function<void(lang::meta::Node::TokenDecl::op::DEF_ALIAS_T)> f_DEF_ALIAS);
        template<typename RetT> RetT match_expr(std::function<RetT(lang::meta::Node::TokenDecl::op::DEF_T)> f_DEF, std::function<RetT(lang::meta::Node::TokenDecl::op::DEF_ALIAS_T)> f_DEF_ALIAS);
        void hash_ser_acc_lang_meta_Node_TokenDecl_op(langcc::SerBuf& buf) const;
        virtual void hash_ser_acc(langcc::SerBuf& buf) const = 0;
    };
}

template<typename RetT> RetT lang::meta::Node::TokenDecl::op::_T::match_expr(std::function<RetT(lang::meta::Node::TokenDecl::op::DEF_T)> f_DEF, std::function<RetT(lang::meta::Node::TokenDecl::op::DEF_ALIAS_T)> f_DEF_ALIAS) {
    switch (this->w_) {
        case lang::meta::Node::TokenDecl::op::_W::DEF: {
            return f_DEF(this->as_DEF());
            break;
        }
        case lang::meta::Node::TokenDecl::op::_W::DEF_ALIAS: {
            return f_DEF_ALIAS(this->as_DEF_ALIAS());
            break;
        }
        default: {
            langcc::AX();
        }
    }
}

namespace langcc {
    void pr_debug(ostream& os, FmtFlags flags, lang::meta::Node::LexerDecl::Main_T x);
}

namespace lang::meta::Node::LexerDecl::Main {
    lang::meta::Node::LexerDecl::Main_T make(langcc::Int id, langcc::TokenBounds bounds, bool is_top, langcc::ParserSymId sym, langcc::ParserAttrMask attr, langcc::ParserLookahead first_k, langcc::StrSlice name);
}

namespace lang::meta::Node::LexerDecl::Main {
    lang::meta::Node::LexerDecl::Main_T make_ext(langcc::ArenaPtr arena, langcc::Int id, langcc::TokenBounds bounds, bool is_top, langcc::ParserSymId sym, langcc::ParserAttrMask attr, langcc::ParserLookahead first_k, langcc::StrSlice name);
}

namespace lang::meta::Node::LexerDecl::Main {
    struct _T: lang::meta::Node::LexerDecl::_T {
        void write(langcc::Ref<std::ostream> os, langcc::FmtFlags flags);
        void write(langcc::Ref<langcc::PrBufStream_T> pb);
        langcc::StrSlice name_;
        _T();
        lang::meta::Node::LexerDecl::Main_T with_id(langcc::Int id);
        lang::meta::Node::LexerDecl::Main_T with_bounds(langcc::TokenBounds bounds);
        lang::meta::Node::LexerDecl::Main_T with_is_top(bool is_top);
        lang::meta::Node::LexerDecl::Main_T with_sym(langcc::ParserSymId sym);
        lang::meta::Node::LexerDecl::Main_T with_attr(langcc::ParserAttrMask attr);
        lang::meta::Node::LexerDecl::Main_T with_first_k(langcc::ParserLookahead first_k);
        lang::meta::Node::LexerDecl::Main_T with_name(langcc::StrSlice name);
        void hash_ser_acc_lang_meta_Node_LexerDecl_Main(langcc::SerBuf& buf) const;
        virtual void hash_ser_acc(langcc::SerBuf& buf) const;
    };
}

namespace langcc {
    void pr_debug(ostream& os, FmtFlags flags, lang::meta::Node::LexerDecl::Mode_T x);
}

namespace lang::meta::Node::LexerDecl::Mode {
    lang::meta::Node::LexerDecl::Mode_T make(langcc::Int id, langcc::TokenBounds bounds, bool is_top, langcc::ParserSymId sym, langcc::ParserAttrMask attr, langcc::ParserLookahead first_k, langcc::StrSlice name, langcc::Option_T<lang::meta::Node::LexerDecl::Mode::ws_sig__T> ws_sig_, langcc::Vec_T<lang::meta::Node::LexerModeCase_T> cases);
}

namespace lang::meta::Node::LexerDecl::Mode {
    lang::meta::Node::LexerDecl::Mode_T make_ext(langcc::ArenaPtr arena, langcc::Int id, langcc::TokenBounds bounds, bool is_top, langcc::ParserSymId sym, langcc::ParserAttrMask attr, langcc::ParserLookahead first_k, langcc::StrSlice name, langcc::Option_T<lang::meta::Node::LexerDecl::Mode::ws_sig__T> ws_sig_, langcc::Vec_T<lang::meta::Node::LexerModeCase_T> cases);
}

namespace lang::meta::Node::LexerDecl::Mode {
    struct _T: lang::meta::Node::LexerDecl::_T {
        void write(langcc::Ref<std::ostream> os, langcc::FmtFlags flags);
        void write(langcc::Ref<langcc::PrBufStream_T> pb);
        langcc::StrSlice name_;
        langcc::Option_T<lang::meta::Node::LexerDecl::Mode::ws_sig__T> ws_sig__;
        langcc::Vec_T<lang::meta::Node::LexerModeCase_T> cases_;
        _T();
        lang::meta::Node::LexerDecl::Mode_T with_id(langcc::Int id);
        lang::meta::Node::LexerDecl::Mode_T with_bounds(langcc::TokenBounds bounds);
        lang::meta::Node::LexerDecl::Mode_T with_is_top(bool is_top);
        lang::meta::Node::LexerDecl::Mode_T with_sym(langcc::ParserSymId sym);
        lang::meta::Node::LexerDecl::Mode_T with_attr(langcc::ParserAttrMask attr);
        lang::meta::Node::LexerDecl::Mode_T with_first_k(langcc::ParserLookahead first_k);
        lang::meta::Node::LexerDecl::Mode_T with_name(langcc::StrSlice name);
        lang::meta::Node::LexerDecl::Mode_T with_ws_sig_(langcc::Option_T<lang::meta::Node::LexerDecl::Mode::ws_sig__T> ws_sig_);
        lang::meta::Node::LexerDecl::Mode_T with_cases(langcc::Vec_T<lang::meta::Node::LexerModeCase_T> cases);
        void hash_ser_acc_lang_meta_Node_LexerDecl_Mode(langcc::SerBuf& buf) const;
        virtual void hash_ser_acc(langcc::SerBuf& buf) const;
    };
}

namespace langcc {
    void pr_debug(ostream& os, FmtFlags flags, lang::meta::Node::LexerInstr::Emit_T x);
}

namespace lang::meta::Node::LexerInstr::Emit {
    lang::meta::Node::LexerInstr::Emit_T make(langcc::Int id, langcc::TokenBounds bounds, bool is_top, langcc::ParserSymId sym, langcc::ParserAttrMask attr, langcc::ParserLookahead first_k, langcc::Option_T<lang::meta::Node::ParseExpr_T> arg);
}

namespace lang::meta::Node::LexerInstr::Emit {
    lang::meta::Node::LexerInstr::Emit_T make_ext(langcc::ArenaPtr arena, langcc::Int id, langcc::TokenBounds bounds, bool is_top, langcc::ParserSymId sym, langcc::ParserAttrMask attr, langcc::ParserLookahead first_k, langcc::Option_T<lang::meta::Node::ParseExpr_T> arg);
}

namespace lang::meta::Node::LexerInstr::Emit {
    struct _T: lang::meta::Node::LexerInstr::_T {
        void write(langcc::Ref<std::ostream> os, langcc::FmtFlags flags);
        void write(langcc::Ref<langcc::PrBufStream_T> pb);
        langcc::Option_T<lang::meta::Node::ParseExpr_T> arg_;
        _T();
        lang::meta::Node::LexerInstr::Emit_T with_id(langcc::Int id);
        lang::meta::Node::LexerInstr::Emit_T with_bounds(langcc::TokenBounds bounds);
        lang::meta::Node::LexerInstr::Emit_T with_is_top(bool is_top);
        lang::meta::Node::LexerInstr::Emit_T with_sym(langcc::ParserSymId sym);
        lang::meta::Node::LexerInstr::Emit_T with_attr(langcc::ParserAttrMask attr);
        lang::meta::Node::LexerInstr::Emit_T with_first_k(langcc::ParserLookahead first_k);
        lang::meta::Node::LexerInstr::Emit_T with_arg(langcc::Option_T<lang::meta::Node::ParseExpr_T> arg);
        void hash_ser_acc_lang_meta_Node_LexerInstr_Emit(langcc::SerBuf& buf) const;
        virtual void hash_ser_acc(langcc::SerBuf& buf) const;
    };
}

namespace langcc {
    void pr_debug(ostream& os, FmtFlags flags, lang::meta::Node::LexerInstr::Pass_T x);
}

namespace lang::meta::Node::LexerInstr::Pass {
    lang::meta::Node::LexerInstr::Pass_T make(langcc::Int id, langcc::TokenBounds bounds, bool is_top, langcc::ParserSymId sym, langcc::ParserAttrMask attr, langcc::ParserLookahead first_k);
}

namespace lang::meta::Node::LexerInstr::Pass {
    lang::meta::Node::LexerInstr::Pass_T make_ext(langcc::ArenaPtr arena, langcc::Int id, langcc::TokenBounds bounds, bool is_top, langcc::ParserSymId sym, langcc::ParserAttrMask attr, langcc::ParserLookahead first_k);
}

namespace lang::meta::Node::LexerInstr::Pass {
    struct _T: lang::meta::Node::LexerInstr::_T {
        void write(langcc::Ref<std::ostream> os, langcc::FmtFlags flags);
        void write(langcc::Ref<langcc::PrBufStream_T> pb);
        _T();
        lang::meta::Node::LexerInstr::Pass_T with_id(langcc::Int id);
        lang::meta::Node::LexerInstr::Pass_T with_bounds(langcc::TokenBounds bounds);
        lang::meta::Node::LexerInstr::Pass_T with_is_top(bool is_top);
        lang::meta::Node::LexerInstr::Pass_T with_sym(langcc::ParserSymId sym);
        lang::meta::Node::LexerInstr::Pass_T with_attr(langcc::ParserAttrMask attr);
        lang::meta::Node::LexerInstr::Pass_T with_first_k(langcc::ParserLookahead first_k);
        void hash_ser_acc_lang_meta_Node_LexerInstr_Pass(langcc::SerBuf& buf) const;
        virtual void hash_ser_acc(langcc::SerBuf& buf) const;
    };
}

namespace langcc {
    void pr_debug(ostream& os, FmtFlags flags, lang::meta::Node::LexerInstr::Push_T x);
}

namespace lang::meta::Node::LexerInstr::Push {
    lang::meta::Node::LexerInstr::Push_T make(langcc::Int id, langcc::TokenBounds bounds, bool is_top, langcc::ParserSymId sym, langcc::ParserAttrMask attr, langcc::ParserLookahead first_k, langcc::StrSlice name);
}

namespace lang::meta::Node::LexerInstr::Push {
    lang::meta::Node::LexerInstr::Push_T make_ext(langcc::ArenaPtr arena, langcc::Int id, langcc::TokenBounds bounds, bool is_top, langcc::ParserSymId sym, langcc::ParserAttrMask attr, langcc::ParserLookahead first_k, langcc::StrSlice name);
}

namespace lang::meta::Node::LexerInstr::Push {
    struct _T: lang::meta::Node::LexerInstr::_T {
        void write(langcc::Ref<std::ostream> os, langcc::FmtFlags flags);
        void write(langcc::Ref<langcc::PrBufStream_T> pb);
        langcc::StrSlice name_;
        _T();
        lang::meta::Node::LexerInstr::Push_T with_id(langcc::Int id);
        lang::meta::Node::LexerInstr::Push_T with_bounds(langcc::TokenBounds bounds);
        lang::meta::Node::LexerInstr::Push_T with_is_top(bool is_top);
        lang::meta::Node::LexerInstr::Push_T with_sym(langcc::ParserSymId sym);
        lang::meta::Node::LexerInstr::Push_T with_attr(langcc::ParserAttrMask attr);
        lang::meta::Node::LexerInstr::Push_T with_first_k(langcc::ParserLookahead first_k);
        lang::meta::Node::LexerInstr::Push_T with_name(langcc::StrSlice name);
        void hash_ser_acc_lang_meta_Node_LexerInstr_Push(langcc::SerBuf& buf) const;
        virtual void hash_ser_acc(langcc::SerBuf& buf) const;
    };
}

namespace langcc {
    void pr_debug(ostream& os, FmtFlags flags, lang::meta::Node::LexerInstr::Pop_T x);
}

namespace lang::meta::Node::LexerInstr::Pop {
    lang::meta::Node::LexerInstr::Pop_T make(langcc::Int id, langcc::TokenBounds bounds, bool is_top, langcc::ParserSymId sym, langcc::ParserAttrMask attr, langcc::ParserLookahead first_k);
}

namespace lang::meta::Node::LexerInstr::Pop {
    lang::meta::Node::LexerInstr::Pop_T make_ext(langcc::ArenaPtr arena, langcc::Int id, langcc::TokenBounds bounds, bool is_top, langcc::ParserSymId sym, langcc::ParserAttrMask attr, langcc::ParserLookahead first_k);
}

namespace lang::meta::Node::LexerInstr::Pop {
    struct _T: lang::meta::Node::LexerInstr::_T {
        void write(langcc::Ref<std::ostream> os, langcc::FmtFlags flags);
        void write(langcc::Ref<langcc::PrBufStream_T> pb);
        _T();
        lang::meta::Node::LexerInstr::Pop_T with_id(langcc::Int id);
        lang::meta::Node::LexerInstr::Pop_T with_bounds(langcc::TokenBounds bounds);
        lang::meta::Node::LexerInstr::Pop_T with_is_top(bool is_top);
        lang::meta::Node::LexerInstr::Pop_T with_sym(langcc::ParserSymId sym);
        lang::meta::Node::LexerInstr::Pop_T with_attr(langcc::ParserAttrMask attr);
        lang::meta::Node::LexerInstr::Pop_T with_first_k(langcc::ParserLookahead first_k);
        void hash_ser_acc_lang_meta_Node_LexerInstr_Pop(langcc::SerBuf& buf) const;
        virtual void hash_ser_acc(langcc::SerBuf& buf) const;
    };
}

namespace langcc {
    void pr_debug(ostream& os, FmtFlags flags, lang::meta::Node::LexerInstr::PopExtract_T x);
}

namespace lang::meta::Node::LexerInstr::PopExtract {
    lang::meta::Node::LexerInstr::PopExtract_T make(langcc::Int id, langcc::TokenBounds bounds, bool is_top, langcc::ParserSymId sym, langcc::ParserAttrMask attr, langcc::ParserLookahead first_k);
}

namespace lang::meta::Node::LexerInstr::PopExtract {
    lang::meta::Node::LexerInstr::PopExtract_T make_ext(langcc::ArenaPtr arena, langcc::Int id, langcc::TokenBounds bounds, bool is_top, langcc::ParserSymId sym, langcc::ParserAttrMask attr, langcc::ParserLookahead first_k);
}

namespace lang::meta::Node::LexerInstr::PopExtract {
    struct _T: lang::meta::Node::LexerInstr::_T {
        void write(langcc::Ref<std::ostream> os, langcc::FmtFlags flags);
        void write(langcc::Ref<langcc::PrBufStream_T> pb);
        _T();
        lang::meta::Node::LexerInstr::PopExtract_T with_id(langcc::Int id);
        lang::meta::Node::LexerInstr::PopExtract_T with_bounds(langcc::TokenBounds bounds);
        lang::meta::Node::LexerInstr::PopExtract_T with_is_top(bool is_top);
        lang::meta::Node::LexerInstr::PopExtract_T with_sym(langcc::ParserSymId sym);
        lang::meta::Node::LexerInstr::PopExtract_T with_attr(langcc::ParserAttrMask attr);
        lang::meta::Node::LexerInstr::PopExtract_T with_first_k(langcc::ParserLookahead first_k);
        void hash_ser_acc_lang_meta_Node_LexerInstr_PopExtract(langcc::SerBuf& buf) const;
        virtual void hash_ser_acc(langcc::SerBuf& buf) const;
    };
}

namespace langcc {
    void pr_debug(ostream& os, FmtFlags flags, lang::meta::Node::LexerInstr::PopEmit_T x);
}

namespace lang::meta::Node::LexerInstr::PopEmit {
    lang::meta::Node::LexerInstr::PopEmit_T make(langcc::Int id, langcc::TokenBounds bounds, bool is_top, langcc::ParserSymId sym, langcc::ParserAttrMask attr, langcc::ParserLookahead first_k, lang::meta::Node::ParseExpr_T arg);
}

namespace lang::meta::Node::LexerInstr::PopEmit {
    lang::meta::Node::LexerInstr::PopEmit_T make_ext(langcc::ArenaPtr arena, langcc::Int id, langcc::TokenBounds bounds, bool is_top, langcc::ParserSymId sym, langcc::ParserAttrMask attr, langcc::ParserLookahead first_k, lang::meta::Node::ParseExpr_T arg);
}

namespace lang::meta::Node::LexerInstr::PopEmit {
    struct _T: lang::meta::Node::LexerInstr::_T {
        void write(langcc::Ref<std::ostream> os, langcc::FmtFlags flags);
        void write(langcc::Ref<langcc::PrBufStream_T> pb);
        lang::meta::Node::ParseExpr_T arg_;
        _T();
        lang::meta::Node::LexerInstr::PopEmit_T with_id(langcc::Int id);
        lang::meta::Node::LexerInstr::PopEmit_T with_bounds(langcc::TokenBounds bounds);
        lang::meta::Node::LexerInstr::PopEmit_T with_is_top(bool is_top);
        lang::meta::Node::LexerInstr::PopEmit_T with_sym(langcc::ParserSymId sym);
        lang::meta::Node::LexerInstr::PopEmit_T with_attr(langcc::ParserAttrMask attr);
        lang::meta::Node::LexerInstr::PopEmit_T with_first_k(langcc::ParserLookahead first_k);
        lang::meta::Node::LexerInstr::PopEmit_T with_arg(lang::meta::Node::ParseExpr_T arg);
        void hash_ser_acc_lang_meta_Node_LexerInstr_PopEmit(langcc::SerBuf& buf) const;
        virtual void hash_ser_acc(langcc::SerBuf& buf) const;
    };
}

namespace langcc {
    void pr_debug(ostream& os, FmtFlags flags, lang::meta::Node::LexerInstr::MatchHistory_T x);
}

namespace lang::meta::Node::LexerInstr::MatchHistory {
    lang::meta::Node::LexerInstr::MatchHistory_T make(langcc::Int id, langcc::TokenBounds bounds, bool is_top, langcc::ParserSymId sym, langcc::ParserAttrMask attr, langcc::ParserLookahead first_k, langcc::Vec_T<lang::meta::Node::LexerModeCase_T> cases);
}

namespace lang::meta::Node::LexerInstr::MatchHistory {
    lang::meta::Node::LexerInstr::MatchHistory_T make_ext(langcc::ArenaPtr arena, langcc::Int id, langcc::TokenBounds bounds, bool is_top, langcc::ParserSymId sym, langcc::ParserAttrMask attr, langcc::ParserLookahead first_k, langcc::Vec_T<lang::meta::Node::LexerModeCase_T> cases);
}

namespace lang::meta::Node::LexerInstr::MatchHistory {
    struct _T: lang::meta::Node::LexerInstr::_T {
        void write(langcc::Ref<std::ostream> os, langcc::FmtFlags flags);
        void write(langcc::Ref<langcc::PrBufStream_T> pb);
        langcc::Vec_T<lang::meta::Node::LexerModeCase_T> cases_;
        _T();
        lang::meta::Node::LexerInstr::MatchHistory_T with_id(langcc::Int id);
        lang::meta::Node::LexerInstr::MatchHistory_T with_bounds(langcc::TokenBounds bounds);
        lang::meta::Node::LexerInstr::MatchHistory_T with_is_top(bool is_top);
        lang::meta::Node::LexerInstr::MatchHistory_T with_sym(langcc::ParserSymId sym);
        lang::meta::Node::LexerInstr::MatchHistory_T with_attr(langcc::ParserAttrMask attr);
        lang::meta::Node::LexerInstr::MatchHistory_T with_first_k(langcc::ParserLookahead first_k);
        lang::meta::Node::LexerInstr::MatchHistory_T with_cases(langcc::Vec_T<lang::meta::Node::LexerModeCase_T> cases);
        void hash_ser_acc_lang_meta_Node_LexerInstr_MatchHistory(langcc::SerBuf& buf) const;
        virtual void hash_ser_acc(langcc::SerBuf& buf) const;
    };
}

namespace langcc {
    void pr_debug(ostream& os, FmtFlags flags, lang::meta::Node::ParserDecl::Main_T x);
}

namespace lang::meta::Node::ParserDecl::Main {
    lang::meta::Node::ParserDecl::Main_T make(langcc::Int id, langcc::TokenBounds bounds, bool is_top, langcc::ParserSymId sym, langcc::ParserAttrMask attr, langcc::ParserLookahead first_k, langcc::Vec_T<langcc::StrSlice> names);
}

namespace lang::meta::Node::ParserDecl::Main {
    lang::meta::Node::ParserDecl::Main_T make_ext(langcc::ArenaPtr arena, langcc::Int id, langcc::TokenBounds bounds, bool is_top, langcc::ParserSymId sym, langcc::ParserAttrMask attr, langcc::ParserLookahead first_k, langcc::Vec_T<langcc::StrSlice> names);
}

namespace lang::meta::Node::ParserDecl::Main {
    struct _T: lang::meta::Node::ParserDecl::_T {
        void write(langcc::Ref<std::ostream> os, langcc::FmtFlags flags);
        void write(langcc::Ref<langcc::PrBufStream_T> pb);
        langcc::Vec_T<langcc::StrSlice> names_;
        _T();
        lang::meta::Node::ParserDecl::Main_T with_id(langcc::Int id);
        lang::meta::Node::ParserDecl::Main_T with_bounds(langcc::TokenBounds bounds);
        lang::meta::Node::ParserDecl::Main_T with_is_top(bool is_top);
        lang::meta::Node::ParserDecl::Main_T with_sym(langcc::ParserSymId sym);
        lang::meta::Node::ParserDecl::Main_T with_attr(langcc::ParserAttrMask attr);
        lang::meta::Node::ParserDecl::Main_T with_first_k(langcc::ParserLookahead first_k);
        lang::meta::Node::ParserDecl::Main_T with_names(langcc::Vec_T<langcc::StrSlice> names);
        void hash_ser_acc_lang_meta_Node_ParserDecl_Main(langcc::SerBuf& buf) const;
        virtual void hash_ser_acc(langcc::SerBuf& buf) const;
    };
}

namespace langcc {
    void pr_debug(ostream& os, FmtFlags flags, lang::meta::Node::ParserDecl::Prop_T x);
}

namespace lang::meta::Node::ParserDecl::Prop {
    lang::meta::Node::ParserDecl::Prop_T make(langcc::Int id, langcc::TokenBounds bounds, bool is_top, langcc::ParserSymId sym, langcc::ParserAttrMask attr, langcc::ParserLookahead first_k, langcc::Vec_T<lang::meta::Node::ParserProp_T> props);
}

namespace lang::meta::Node::ParserDecl::Prop {
    lang::meta::Node::ParserDecl::Prop_T make_ext(langcc::ArenaPtr arena, langcc::Int id, langcc::TokenBounds bounds, bool is_top, langcc::ParserSymId sym, langcc::ParserAttrMask attr, langcc::ParserLookahead first_k, langcc::Vec_T<lang::meta::Node::ParserProp_T> props);
}

namespace lang::meta::Node::ParserDecl::Prop {
    struct _T: lang::meta::Node::ParserDecl::_T {
        void write(langcc::Ref<std::ostream> os, langcc::FmtFlags flags);
        void write(langcc::Ref<langcc::PrBufStream_T> pb);
        langcc::Vec_T<lang::meta::Node::ParserProp_T> props_;
        _T();
        lang::meta::Node::ParserDecl::Prop_T with_id(langcc::Int id);
        lang::meta::Node::ParserDecl::Prop_T with_bounds(langcc::TokenBounds bounds);
        lang::meta::Node::ParserDecl::Prop_T with_is_top(bool is_top);
        lang::meta::Node::ParserDecl::Prop_T with_sym(langcc::ParserSymId sym);
        lang::meta::Node::ParserDecl::Prop_T with_attr(langcc::ParserAttrMask attr);
        lang::meta::Node::ParserDecl::Prop_T with_first_k(langcc::ParserLookahead first_k);
        lang::meta::Node::ParserDecl::Prop_T with_props(langcc::Vec_T<lang::meta::Node::ParserProp_T> props);
        void hash_ser_acc_lang_meta_Node_ParserDecl_Prop(langcc::SerBuf& buf) const;
        virtual void hash_ser_acc(langcc::SerBuf& buf) const;
    };
}

namespace langcc {
    void pr_debug(ostream& os, FmtFlags flags, lang::meta::Node::ParserDecl::Prec_T x);
}

namespace lang::meta::Node::ParserDecl::Prec {
    lang::meta::Node::ParserDecl::Prec_T make(langcc::Int id, langcc::TokenBounds bounds, bool is_top, langcc::ParserSymId sym, langcc::ParserAttrMask attr, langcc::ParserLookahead first_k, langcc::Vec_T<lang::meta::Node::PrecItem_T> items);
}

namespace lang::meta::Node::ParserDecl::Prec {
    lang::meta::Node::ParserDecl::Prec_T make_ext(langcc::ArenaPtr arena, langcc::Int id, langcc::TokenBounds bounds, bool is_top, langcc::ParserSymId sym, langcc::ParserAttrMask attr, langcc::ParserLookahead first_k, langcc::Vec_T<lang::meta::Node::PrecItem_T> items);
}

namespace lang::meta::Node::ParserDecl::Prec {
    struct _T: lang::meta::Node::ParserDecl::_T {
        void write(langcc::Ref<std::ostream> os, langcc::FmtFlags flags);
        void write(langcc::Ref<langcc::PrBufStream_T> pb);
        langcc::Vec_T<lang::meta::Node::PrecItem_T> items_;
        _T();
        lang::meta::Node::ParserDecl::Prec_T with_id(langcc::Int id);
        lang::meta::Node::ParserDecl::Prec_T with_bounds(langcc::TokenBounds bounds);
        lang::meta::Node::ParserDecl::Prec_T with_is_top(bool is_top);
        lang::meta::Node::ParserDecl::Prec_T with_sym(langcc::ParserSymId sym);
        lang::meta::Node::ParserDecl::Prec_T with_attr(langcc::ParserAttrMask attr);
        lang::meta::Node::ParserDecl::Prec_T with_first_k(langcc::ParserLookahead first_k);
        lang::meta::Node::ParserDecl::Prec_T with_items(langcc::Vec_T<lang::meta::Node::PrecItem_T> items);
        void hash_ser_acc_lang_meta_Node_ParserDecl_Prec(langcc::SerBuf& buf) const;
        virtual void hash_ser_acc(langcc::SerBuf& buf) const;
    };
}

namespace langcc {
    void pr_debug(ostream& os, FmtFlags flags, lang::meta::Node::ParserDecl::Attr_T x);
}

namespace lang::meta::Node::ParserDecl::Attr {
    lang::meta::Node::ParserDecl::Attr_T make(langcc::Int id, langcc::TokenBounds bounds, bool is_top, langcc::ParserSymId sym, langcc::ParserAttrMask attr, langcc::ParserLookahead first_k, langcc::Vec_T<lang::meta::Node::AttrClause_T> clauses);
}

namespace lang::meta::Node::ParserDecl::Attr {
    lang::meta::Node::ParserDecl::Attr_T make_ext(langcc::ArenaPtr arena, langcc::Int id, langcc::TokenBounds bounds, bool is_top, langcc::ParserSymId sym, langcc::ParserAttrMask attr, langcc::ParserLookahead first_k, langcc::Vec_T<lang::meta::Node::AttrClause_T> clauses);
}

namespace lang::meta::Node::ParserDecl::Attr {
    struct _T: lang::meta::Node::ParserDecl::_T {
        void write(langcc::Ref<std::ostream> os, langcc::FmtFlags flags);
        void write(langcc::Ref<langcc::PrBufStream_T> pb);
        langcc::Vec_T<lang::meta::Node::AttrClause_T> clauses_;
        _T();
        lang::meta::Node::ParserDecl::Attr_T with_id(langcc::Int id);
        lang::meta::Node::ParserDecl::Attr_T with_bounds(langcc::TokenBounds bounds);
        lang::meta::Node::ParserDecl::Attr_T with_is_top(bool is_top);
        lang::meta::Node::ParserDecl::Attr_T with_sym(langcc::ParserSymId sym);
        lang::meta::Node::ParserDecl::Attr_T with_attr(langcc::ParserAttrMask attr);
        lang::meta::Node::ParserDecl::Attr_T with_first_k(langcc::ParserLookahead first_k);
        lang::meta::Node::ParserDecl::Attr_T with_clauses(langcc::Vec_T<lang::meta::Node::AttrClause_T> clauses);
        void hash_ser_acc_lang_meta_Node_ParserDecl_Attr(langcc::SerBuf& buf) const;
        virtual void hash_ser_acc(langcc::SerBuf& buf) const;
    };
}

namespace langcc {
    void pr_debug(ostream& os, FmtFlags flags, lang::meta::Node::ParserDecl::Rule_T x);
}

namespace lang::meta::Node::ParserDecl::Rule {
    lang::meta::Node::ParserDecl::Rule_T make(langcc::Int id, langcc::TokenBounds bounds, bool is_top, langcc::ParserSymId sym, langcc::ParserAttrMask attr, langcc::ParserLookahead first_k, lang::meta::Node::Id_T name, langcc::Option_T<langcc::Vec_T<lang::meta::Node::AttrReq_T>> lhs_attrs, lang::meta::Node::ParserDecl::Rule::op_T op, lang::meta::Node::ParseExpr_T e);
}

namespace lang::meta::Node::ParserDecl::Rule {
    lang::meta::Node::ParserDecl::Rule_T make_ext(langcc::ArenaPtr arena, langcc::Int id, langcc::TokenBounds bounds, bool is_top, langcc::ParserSymId sym, langcc::ParserAttrMask attr, langcc::ParserLookahead first_k, lang::meta::Node::Id_T name, langcc::Option_T<langcc::Vec_T<lang::meta::Node::AttrReq_T>> lhs_attrs, lang::meta::Node::ParserDecl::Rule::op_T op, lang::meta::Node::ParseExpr_T e);
}

namespace lang::meta::Node::ParserDecl::Rule {
    struct _T: lang::meta::Node::ParserDecl::_T {
        void write(langcc::Ref<std::ostream> os, langcc::FmtFlags flags);
        void write(langcc::Ref<langcc::PrBufStream_T> pb);
        lang::meta::Node::Id_T name_;
        langcc::Option_T<langcc::Vec_T<lang::meta::Node::AttrReq_T>> lhs_attrs_;
        lang::meta::Node::ParserDecl::Rule::op_T op_;
        lang::meta::Node::ParseExpr_T e_;
        _T();
        lang::meta::Node::ParserDecl::Rule_T with_id(langcc::Int id);
        lang::meta::Node::ParserDecl::Rule_T with_bounds(langcc::TokenBounds bounds);
        lang::meta::Node::ParserDecl::Rule_T with_is_top(bool is_top);
        lang::meta::Node::ParserDecl::Rule_T with_sym(langcc::ParserSymId sym);
        lang::meta::Node::ParserDecl::Rule_T with_attr(langcc::ParserAttrMask attr);
        lang::meta::Node::ParserDecl::Rule_T with_first_k(langcc::ParserLookahead first_k);
        lang::meta::Node::ParserDecl::Rule_T with_name(lang::meta::Node::Id_T name);
        lang::meta::Node::ParserDecl::Rule_T with_lhs_attrs(langcc::Option_T<langcc::Vec_T<lang::meta::Node::AttrReq_T>> lhs_attrs);
        lang::meta::Node::ParserDecl::Rule_T with_op(lang::meta::Node::ParserDecl::Rule::op_T op);
        lang::meta::Node::ParserDecl::Rule_T with_e(lang::meta::Node::ParseExpr_T e);
        void hash_ser_acc_lang_meta_Node_ParserDecl_Rule(langcc::SerBuf& buf) const;
        virtual void hash_ser_acc(langcc::SerBuf& buf) const;
    };
}

namespace langcc {
    void pr_debug(ostream& os, FmtFlags flags, lang::meta::Node::ParserProp::NameStrict_T x);
}

namespace lang::meta::Node::ParserProp::NameStrict {
    lang::meta::Node::ParserProp::NameStrict_T make(langcc::Int id, langcc::TokenBounds bounds, bool is_top, langcc::ParserSymId sym, langcc::ParserAttrMask attr, langcc::ParserLookahead first_k);
}

namespace lang::meta::Node::ParserProp::NameStrict {
    lang::meta::Node::ParserProp::NameStrict_T make_ext(langcc::ArenaPtr arena, langcc::Int id, langcc::TokenBounds bounds, bool is_top, langcc::ParserSymId sym, langcc::ParserAttrMask attr, langcc::ParserLookahead first_k);
}

namespace lang::meta::Node::ParserProp::NameStrict {
    struct _T: lang::meta::Node::ParserProp::_T {
        void write(langcc::Ref<std::ostream> os, langcc::FmtFlags flags);
        void write(langcc::Ref<langcc::PrBufStream_T> pb);
        _T();
        lang::meta::Node::ParserProp::NameStrict_T with_id(langcc::Int id);
        lang::meta::Node::ParserProp::NameStrict_T with_bounds(langcc::TokenBounds bounds);
        lang::meta::Node::ParserProp::NameStrict_T with_is_top(bool is_top);
        lang::meta::Node::ParserProp::NameStrict_T with_sym(langcc::ParserSymId sym);
        lang::meta::Node::ParserProp::NameStrict_T with_attr(langcc::ParserAttrMask attr);
        lang::meta::Node::ParserProp::NameStrict_T with_first_k(langcc::ParserLookahead first_k);
        void hash_ser_acc_lang_meta_Node_ParserProp_NameStrict(langcc::SerBuf& buf) const;
        virtual void hash_ser_acc(langcc::SerBuf& buf) const;
    };
}

namespace langcc {
    void pr_debug(ostream& os, FmtFlags flags, lang::meta::Node::ParserProp::AllowUnreach_T x);
}

namespace lang::meta::Node::ParserProp::AllowUnreach {
    lang::meta::Node::ParserProp::AllowUnreach_T make(langcc::Int id, langcc::TokenBounds bounds, bool is_top, langcc::ParserSymId sym, langcc::ParserAttrMask attr, langcc::ParserLookahead first_k);
}

namespace lang::meta::Node::ParserProp::AllowUnreach {
    lang::meta::Node::ParserProp::AllowUnreach_T make_ext(langcc::ArenaPtr arena, langcc::Int id, langcc::TokenBounds bounds, bool is_top, langcc::ParserSymId sym, langcc::ParserAttrMask attr, langcc::ParserLookahead first_k);
}

namespace lang::meta::Node::ParserProp::AllowUnreach {
    struct _T: lang::meta::Node::ParserProp::_T {
        void write(langcc::Ref<std::ostream> os, langcc::FmtFlags flags);
        void write(langcc::Ref<langcc::PrBufStream_T> pb);
        _T();
        lang::meta::Node::ParserProp::AllowUnreach_T with_id(langcc::Int id);
        lang::meta::Node::ParserProp::AllowUnreach_T with_bounds(langcc::TokenBounds bounds);
        lang::meta::Node::ParserProp::AllowUnreach_T with_is_top(bool is_top);
        lang::meta::Node::ParserProp::AllowUnreach_T with_sym(langcc::ParserSymId sym);
        lang::meta::Node::ParserProp::AllowUnreach_T with_attr(langcc::ParserAttrMask attr);
        lang::meta::Node::ParserProp::AllowUnreach_T with_first_k(langcc::ParserLookahead first_k);
        void hash_ser_acc_lang_meta_Node_ParserProp_AllowUnreach(langcc::SerBuf& buf) const;
        virtual void hash_ser_acc(langcc::SerBuf& buf) const;
    };
}

namespace langcc {
    void pr_debug(ostream& os, FmtFlags flags, lang::meta::Node::ParserProp::ASTExtraData_T x);
}

namespace lang::meta::Node::ParserProp::ASTExtraData {
    lang::meta::Node::ParserProp::ASTExtraData_T make(langcc::Int id, langcc::TokenBounds bounds, bool is_top, langcc::ParserSymId sym, langcc::ParserAttrMask attr, langcc::ParserLookahead first_k, langcc::StrSlice name);
}

namespace lang::meta::Node::ParserProp::ASTExtraData {
    lang::meta::Node::ParserProp::ASTExtraData_T make_ext(langcc::ArenaPtr arena, langcc::Int id, langcc::TokenBounds bounds, bool is_top, langcc::ParserSymId sym, langcc::ParserAttrMask attr, langcc::ParserLookahead first_k, langcc::StrSlice name);
}

namespace lang::meta::Node::ParserProp::ASTExtraData {
    struct _T: lang::meta::Node::ParserProp::_T {
        void write(langcc::Ref<std::ostream> os, langcc::FmtFlags flags);
        void write(langcc::Ref<langcc::PrBufStream_T> pb);
        langcc::StrSlice name_;
        _T();
        lang::meta::Node::ParserProp::ASTExtraData_T with_id(langcc::Int id);
        lang::meta::Node::ParserProp::ASTExtraData_T with_bounds(langcc::TokenBounds bounds);
        lang::meta::Node::ParserProp::ASTExtraData_T with_is_top(bool is_top);
        lang::meta::Node::ParserProp::ASTExtraData_T with_sym(langcc::ParserSymId sym);
        lang::meta::Node::ParserProp::ASTExtraData_T with_attr(langcc::ParserAttrMask attr);
        lang::meta::Node::ParserProp::ASTExtraData_T with_first_k(langcc::ParserLookahead first_k);
        lang::meta::Node::ParserProp::ASTExtraData_T with_name(langcc::StrSlice name);
        void hash_ser_acc_lang_meta_Node_ParserProp_ASTExtraData(langcc::SerBuf& buf) const;
        virtual void hash_ser_acc(langcc::SerBuf& buf) const;
    };
}

namespace langcc {
    void pr_debug(ostream& os, FmtFlags flags, lang::meta::Node::ParserProp::LRSpec_T x);
}

namespace lang::meta::Node::ParserProp::LRSpec {
    lang::meta::Node::ParserProp::LRSpec_T make(langcc::Int id, langcc::TokenBounds bounds, bool is_top, langcc::ParserSymId sym, langcc::ParserAttrMask attr, langcc::ParserLookahead first_k, langcc::StrSlice k);
}

namespace lang::meta::Node::ParserProp::LRSpec {
    lang::meta::Node::ParserProp::LRSpec_T make_ext(langcc::ArenaPtr arena, langcc::Int id, langcc::TokenBounds bounds, bool is_top, langcc::ParserSymId sym, langcc::ParserAttrMask attr, langcc::ParserLookahead first_k, langcc::StrSlice k);
}

namespace lang::meta::Node::ParserProp::LRSpec {
    struct _T: lang::meta::Node::ParserProp::_T {
        void write(langcc::Ref<std::ostream> os, langcc::FmtFlags flags);
        void write(langcc::Ref<langcc::PrBufStream_T> pb);
        langcc::StrSlice k_;
        _T();
        lang::meta::Node::ParserProp::LRSpec_T with_id(langcc::Int id);
        lang::meta::Node::ParserProp::LRSpec_T with_bounds(langcc::TokenBounds bounds);
        lang::meta::Node::ParserProp::LRSpec_T with_is_top(bool is_top);
        lang::meta::Node::ParserProp::LRSpec_T with_sym(langcc::ParserSymId sym);
        lang::meta::Node::ParserProp::LRSpec_T with_attr(langcc::ParserAttrMask attr);
        lang::meta::Node::ParserProp::LRSpec_T with_first_k(langcc::ParserLookahead first_k);
        lang::meta::Node::ParserProp::LRSpec_T with_k(langcc::StrSlice k);
        void hash_ser_acc_lang_meta_Node_ParserProp_LRSpec(langcc::SerBuf& buf) const;
        virtual void hash_ser_acc(langcc::SerBuf& buf) const;
    };
}

namespace langcc {
    void pr_debug(ostream& os, FmtFlags flags, lang::meta::Node::ParserProp::Err__T x);
}

namespace lang::meta::Node::ParserProp::Err_ {
    lang::meta::Node::ParserProp::Err__T make(langcc::Int id, langcc::TokenBounds bounds, bool is_top, langcc::ParserSymId sym, langcc::ParserAttrMask attr, langcc::ParserLookahead first_k);
}

namespace lang::meta::Node::ParserProp::Err_ {
    lang::meta::Node::ParserProp::Err__T make_ext(langcc::ArenaPtr arena, langcc::Int id, langcc::TokenBounds bounds, bool is_top, langcc::ParserSymId sym, langcc::ParserAttrMask attr, langcc::ParserLookahead first_k);
}

namespace lang::meta::Node::ParserProp::Err_ {
    struct _T: lang::meta::Node::ParserProp::_T {
        void write(langcc::Ref<std::ostream> os, langcc::FmtFlags flags);
        void write(langcc::Ref<langcc::PrBufStream_T> pb);
        _T();
        lang::meta::Node::ParserProp::Err__T with_id(langcc::Int id);
        lang::meta::Node::ParserProp::Err__T with_bounds(langcc::TokenBounds bounds);
        lang::meta::Node::ParserProp::Err__T with_is_top(bool is_top);
        lang::meta::Node::ParserProp::Err__T with_sym(langcc::ParserSymId sym);
        lang::meta::Node::ParserProp::Err__T with_attr(langcc::ParserAttrMask attr);
        lang::meta::Node::ParserProp::Err__T with_first_k(langcc::ParserLookahead first_k);
        void hash_ser_acc_lang_meta_Node_ParserProp_Err_(langcc::SerBuf& buf) const;
        virtual void hash_ser_acc(langcc::SerBuf& buf) const;
    };
}

namespace langcc {
    void pr_debug(ostream& os, FmtFlags flags, lang::meta::Node::PrecAssoc::Left_T x);
}

namespace lang::meta::Node::PrecAssoc::Left {
    lang::meta::Node::PrecAssoc::Left_T make(langcc::Int id, langcc::TokenBounds bounds, bool is_top, langcc::ParserSymId sym, langcc::ParserAttrMask attr, langcc::ParserLookahead first_k);
}

namespace lang::meta::Node::PrecAssoc::Left {
    lang::meta::Node::PrecAssoc::Left_T make_ext(langcc::ArenaPtr arena, langcc::Int id, langcc::TokenBounds bounds, bool is_top, langcc::ParserSymId sym, langcc::ParserAttrMask attr, langcc::ParserLookahead first_k);
}

namespace lang::meta::Node::PrecAssoc::Left {
    struct _T: lang::meta::Node::PrecAssoc::_T {
        void write(langcc::Ref<std::ostream> os, langcc::FmtFlags flags);
        void write(langcc::Ref<langcc::PrBufStream_T> pb);
        _T();
        lang::meta::Node::PrecAssoc::Left_T with_id(langcc::Int id);
        lang::meta::Node::PrecAssoc::Left_T with_bounds(langcc::TokenBounds bounds);
        lang::meta::Node::PrecAssoc::Left_T with_is_top(bool is_top);
        lang::meta::Node::PrecAssoc::Left_T with_sym(langcc::ParserSymId sym);
        lang::meta::Node::PrecAssoc::Left_T with_attr(langcc::ParserAttrMask attr);
        lang::meta::Node::PrecAssoc::Left_T with_first_k(langcc::ParserLookahead first_k);
        void hash_ser_acc_lang_meta_Node_PrecAssoc_Left(langcc::SerBuf& buf) const;
        virtual void hash_ser_acc(langcc::SerBuf& buf) const;
    };
}

namespace langcc {
    void pr_debug(ostream& os, FmtFlags flags, lang::meta::Node::PrecAssoc::Right_T x);
}

namespace lang::meta::Node::PrecAssoc::Right {
    lang::meta::Node::PrecAssoc::Right_T make(langcc::Int id, langcc::TokenBounds bounds, bool is_top, langcc::ParserSymId sym, langcc::ParserAttrMask attr, langcc::ParserLookahead first_k);
}

namespace lang::meta::Node::PrecAssoc::Right {
    lang::meta::Node::PrecAssoc::Right_T make_ext(langcc::ArenaPtr arena, langcc::Int id, langcc::TokenBounds bounds, bool is_top, langcc::ParserSymId sym, langcc::ParserAttrMask attr, langcc::ParserLookahead first_k);
}

namespace lang::meta::Node::PrecAssoc::Right {
    struct _T: lang::meta::Node::PrecAssoc::_T {
        void write(langcc::Ref<std::ostream> os, langcc::FmtFlags flags);
        void write(langcc::Ref<langcc::PrBufStream_T> pb);
        _T();
        lang::meta::Node::PrecAssoc::Right_T with_id(langcc::Int id);
        lang::meta::Node::PrecAssoc::Right_T with_bounds(langcc::TokenBounds bounds);
        lang::meta::Node::PrecAssoc::Right_T with_is_top(bool is_top);
        lang::meta::Node::PrecAssoc::Right_T with_sym(langcc::ParserSymId sym);
        lang::meta::Node::PrecAssoc::Right_T with_attr(langcc::ParserAttrMask attr);
        lang::meta::Node::PrecAssoc::Right_T with_first_k(langcc::ParserLookahead first_k);
        void hash_ser_acc_lang_meta_Node_PrecAssoc_Right(langcc::SerBuf& buf) const;
        virtual void hash_ser_acc(langcc::SerBuf& buf) const;
    };
}

namespace langcc {
    void pr_debug(ostream& os, FmtFlags flags, lang::meta::Node::PrecAssoc::Prefix_T x);
}

namespace lang::meta::Node::PrecAssoc::Prefix {
    lang::meta::Node::PrecAssoc::Prefix_T make(langcc::Int id, langcc::TokenBounds bounds, bool is_top, langcc::ParserSymId sym, langcc::ParserAttrMask attr, langcc::ParserLookahead first_k);
}

namespace lang::meta::Node::PrecAssoc::Prefix {
    lang::meta::Node::PrecAssoc::Prefix_T make_ext(langcc::ArenaPtr arena, langcc::Int id, langcc::TokenBounds bounds, bool is_top, langcc::ParserSymId sym, langcc::ParserAttrMask attr, langcc::ParserLookahead first_k);
}

namespace lang::meta::Node::PrecAssoc::Prefix {
    struct _T: lang::meta::Node::PrecAssoc::_T {
        void write(langcc::Ref<std::ostream> os, langcc::FmtFlags flags);
        void write(langcc::Ref<langcc::PrBufStream_T> pb);
        _T();
        lang::meta::Node::PrecAssoc::Prefix_T with_id(langcc::Int id);
        lang::meta::Node::PrecAssoc::Prefix_T with_bounds(langcc::TokenBounds bounds);
        lang::meta::Node::PrecAssoc::Prefix_T with_is_top(bool is_top);
        lang::meta::Node::PrecAssoc::Prefix_T with_sym(langcc::ParserSymId sym);
        lang::meta::Node::PrecAssoc::Prefix_T with_attr(langcc::ParserAttrMask attr);
        lang::meta::Node::PrecAssoc::Prefix_T with_first_k(langcc::ParserLookahead first_k);
        void hash_ser_acc_lang_meta_Node_PrecAssoc_Prefix(langcc::SerBuf& buf) const;
        virtual void hash_ser_acc(langcc::SerBuf& buf) const;
    };
}

namespace langcc {
    void pr_debug(ostream& os, FmtFlags flags, lang::meta::Node::PrecAssoc::Postfix_T x);
}

namespace lang::meta::Node::PrecAssoc::Postfix {
    lang::meta::Node::PrecAssoc::Postfix_T make(langcc::Int id, langcc::TokenBounds bounds, bool is_top, langcc::ParserSymId sym, langcc::ParserAttrMask attr, langcc::ParserLookahead first_k);
}

namespace lang::meta::Node::PrecAssoc::Postfix {
    lang::meta::Node::PrecAssoc::Postfix_T make_ext(langcc::ArenaPtr arena, langcc::Int id, langcc::TokenBounds bounds, bool is_top, langcc::ParserSymId sym, langcc::ParserAttrMask attr, langcc::ParserLookahead first_k);
}

namespace lang::meta::Node::PrecAssoc::Postfix {
    struct _T: lang::meta::Node::PrecAssoc::_T {
        void write(langcc::Ref<std::ostream> os, langcc::FmtFlags flags);
        void write(langcc::Ref<langcc::PrBufStream_T> pb);
        _T();
        lang::meta::Node::PrecAssoc::Postfix_T with_id(langcc::Int id);
        lang::meta::Node::PrecAssoc::Postfix_T with_bounds(langcc::TokenBounds bounds);
        lang::meta::Node::PrecAssoc::Postfix_T with_is_top(bool is_top);
        lang::meta::Node::PrecAssoc::Postfix_T with_sym(langcc::ParserSymId sym);
        lang::meta::Node::PrecAssoc::Postfix_T with_attr(langcc::ParserAttrMask attr);
        lang::meta::Node::PrecAssoc::Postfix_T with_first_k(langcc::ParserLookahead first_k);
        void hash_ser_acc_lang_meta_Node_PrecAssoc_Postfix(langcc::SerBuf& buf) const;
        virtual void hash_ser_acc(langcc::SerBuf& buf) const;
    };
}

namespace langcc {
    void pr_debug(ostream& os, FmtFlags flags, lang::meta::Node::AttrClause::Expr_T x);
}

namespace lang::meta::Node::AttrClause::Expr {
    lang::meta::Node::AttrClause::Expr_T make(langcc::Int id, langcc::TokenBounds bounds, bool is_top, langcc::ParserSymId sym, langcc::ParserAttrMask attr, langcc::ParserLookahead first_k, lang::meta::Node::AttrClauseExpr_T e);
}

namespace lang::meta::Node::AttrClause::Expr {
    lang::meta::Node::AttrClause::Expr_T make_ext(langcc::ArenaPtr arena, langcc::Int id, langcc::TokenBounds bounds, bool is_top, langcc::ParserSymId sym, langcc::ParserAttrMask attr, langcc::ParserLookahead first_k, lang::meta::Node::AttrClauseExpr_T e);
}

namespace lang::meta::Node::AttrClause::Expr {
    struct _T: lang::meta::Node::AttrClause::_T {
        void write(langcc::Ref<std::ostream> os, langcc::FmtFlags flags);
        void write(langcc::Ref<langcc::PrBufStream_T> pb);
        lang::meta::Node::AttrClauseExpr_T e_;
        _T();
        lang::meta::Node::AttrClause::Expr_T with_id(langcc::Int id);
        lang::meta::Node::AttrClause::Expr_T with_bounds(langcc::TokenBounds bounds);
        lang::meta::Node::AttrClause::Expr_T with_is_top(bool is_top);
        lang::meta::Node::AttrClause::Expr_T with_sym(langcc::ParserSymId sym);
        lang::meta::Node::AttrClause::Expr_T with_attr(langcc::ParserAttrMask attr);
        lang::meta::Node::AttrClause::Expr_T with_first_k(langcc::ParserLookahead first_k);
        lang::meta::Node::AttrClause::Expr_T with_e(lang::meta::Node::AttrClauseExpr_T e);
        void hash_ser_acc_lang_meta_Node_AttrClause_Expr(langcc::SerBuf& buf) const;
        virtual void hash_ser_acc(langcc::SerBuf& buf) const;
    };
}

namespace langcc {
    void pr_debug(ostream& os, FmtFlags flags, lang::meta::Node::AttrClause::Block_T x);
}

namespace lang::meta::Node::AttrClause::Block {
    lang::meta::Node::AttrClause::Block_T make(langcc::Int id, langcc::TokenBounds bounds, bool is_top, langcc::ParserSymId sym, langcc::ParserAttrMask attr, langcc::ParserLookahead first_k, langcc::Vec_T<lang::meta::Node::AttrClause_T> items);
}

namespace lang::meta::Node::AttrClause::Block {
    lang::meta::Node::AttrClause::Block_T make_ext(langcc::ArenaPtr arena, langcc::Int id, langcc::TokenBounds bounds, bool is_top, langcc::ParserSymId sym, langcc::ParserAttrMask attr, langcc::ParserLookahead first_k, langcc::Vec_T<lang::meta::Node::AttrClause_T> items);
}

namespace lang::meta::Node::AttrClause::Block {
    struct _T: lang::meta::Node::AttrClause::_T {
        void write(langcc::Ref<std::ostream> os, langcc::FmtFlags flags);
        void write(langcc::Ref<langcc::PrBufStream_T> pb);
        langcc::Vec_T<lang::meta::Node::AttrClause_T> items_;
        _T();
        lang::meta::Node::AttrClause::Block_T with_id(langcc::Int id);
        lang::meta::Node::AttrClause::Block_T with_bounds(langcc::TokenBounds bounds);
        lang::meta::Node::AttrClause::Block_T with_is_top(bool is_top);
        lang::meta::Node::AttrClause::Block_T with_sym(langcc::ParserSymId sym);
        lang::meta::Node::AttrClause::Block_T with_attr(langcc::ParserAttrMask attr);
        lang::meta::Node::AttrClause::Block_T with_first_k(langcc::ParserLookahead first_k);
        lang::meta::Node::AttrClause::Block_T with_items(langcc::Vec_T<lang::meta::Node::AttrClause_T> items);
        void hash_ser_acc_lang_meta_Node_AttrClause_Block(langcc::SerBuf& buf) const;
        virtual void hash_ser_acc(langcc::SerBuf& buf) const;
    };
}

namespace langcc {
    void pr_debug(ostream& os, FmtFlags flags, lang::meta::Node::AttrClause::Match_T x);
}

namespace lang::meta::Node::AttrClause::Match {
    lang::meta::Node::AttrClause::Match_T make(langcc::Int id, langcc::TokenBounds bounds, bool is_top, langcc::ParserSymId sym, langcc::ParserAttrMask attr, langcc::ParserLookahead first_k, langcc::Vec_T<lang::meta::Node::AttrMatchCase_T> cases);
}

namespace lang::meta::Node::AttrClause::Match {
    lang::meta::Node::AttrClause::Match_T make_ext(langcc::ArenaPtr arena, langcc::Int id, langcc::TokenBounds bounds, bool is_top, langcc::ParserSymId sym, langcc::ParserAttrMask attr, langcc::ParserLookahead first_k, langcc::Vec_T<lang::meta::Node::AttrMatchCase_T> cases);
}

namespace lang::meta::Node::AttrClause::Match {
    struct _T: lang::meta::Node::AttrClause::_T {
        void write(langcc::Ref<std::ostream> os, langcc::FmtFlags flags);
        void write(langcc::Ref<langcc::PrBufStream_T> pb);
        langcc::Vec_T<lang::meta::Node::AttrMatchCase_T> cases_;
        _T();
        lang::meta::Node::AttrClause::Match_T with_id(langcc::Int id);
        lang::meta::Node::AttrClause::Match_T with_bounds(langcc::TokenBounds bounds);
        lang::meta::Node::AttrClause::Match_T with_is_top(bool is_top);
        lang::meta::Node::AttrClause::Match_T with_sym(langcc::ParserSymId sym);
        lang::meta::Node::AttrClause::Match_T with_attr(langcc::ParserAttrMask attr);
        lang::meta::Node::AttrClause::Match_T with_first_k(langcc::ParserLookahead first_k);
        lang::meta::Node::AttrClause::Match_T with_cases(langcc::Vec_T<lang::meta::Node::AttrMatchCase_T> cases);
        void hash_ser_acc_lang_meta_Node_AttrClause_Match(langcc::SerBuf& buf) const;
        virtual void hash_ser_acc(langcc::SerBuf& buf) const;
    };
}

namespace langcc {
    void pr_debug(ostream& os, FmtFlags flags, lang::meta::Node::AttrMatchCasePattern::Alt_T x);
}

namespace lang::meta::Node::AttrMatchCasePattern::Alt {
    lang::meta::Node::AttrMatchCasePattern::Alt_T make(langcc::Int id, langcc::TokenBounds bounds, bool is_top, langcc::ParserSymId sym, langcc::ParserAttrMask attr, langcc::ParserLookahead first_k, langcc::Vec_T<lang::meta::Node::Id_T> items);
}

namespace lang::meta::Node::AttrMatchCasePattern::Alt {
    lang::meta::Node::AttrMatchCasePattern::Alt_T make_ext(langcc::ArenaPtr arena, langcc::Int id, langcc::TokenBounds bounds, bool is_top, langcc::ParserSymId sym, langcc::ParserAttrMask attr, langcc::ParserLookahead first_k, langcc::Vec_T<lang::meta::Node::Id_T> items);
}

namespace lang::meta::Node::AttrMatchCasePattern::Alt {
    struct _T: lang::meta::Node::AttrMatchCasePattern::_T {
        void write(langcc::Ref<std::ostream> os, langcc::FmtFlags flags);
        void write(langcc::Ref<langcc::PrBufStream_T> pb);
        langcc::Vec_T<lang::meta::Node::Id_T> items_;
        _T();
        lang::meta::Node::AttrMatchCasePattern::Alt_T with_id(langcc::Int id);
        lang::meta::Node::AttrMatchCasePattern::Alt_T with_bounds(langcc::TokenBounds bounds);
        lang::meta::Node::AttrMatchCasePattern::Alt_T with_is_top(bool is_top);
        lang::meta::Node::AttrMatchCasePattern::Alt_T with_sym(langcc::ParserSymId sym);
        lang::meta::Node::AttrMatchCasePattern::Alt_T with_attr(langcc::ParserAttrMask attr);
        lang::meta::Node::AttrMatchCasePattern::Alt_T with_first_k(langcc::ParserLookahead first_k);
        lang::meta::Node::AttrMatchCasePattern::Alt_T with_items(langcc::Vec_T<lang::meta::Node::Id_T> items);
        void hash_ser_acc_lang_meta_Node_AttrMatchCasePattern_Alt(langcc::SerBuf& buf) const;
        virtual void hash_ser_acc(langcc::SerBuf& buf) const;
    };
}

namespace langcc {
    void pr_debug(ostream& os, FmtFlags flags, lang::meta::Node::AttrMatchCasePattern::Wildcard_T x);
}

namespace lang::meta::Node::AttrMatchCasePattern::Wildcard {
    lang::meta::Node::AttrMatchCasePattern::Wildcard_T make(langcc::Int id, langcc::TokenBounds bounds, bool is_top, langcc::ParserSymId sym, langcc::ParserAttrMask attr, langcc::ParserLookahead first_k);
}

namespace lang::meta::Node::AttrMatchCasePattern::Wildcard {
    lang::meta::Node::AttrMatchCasePattern::Wildcard_T make_ext(langcc::ArenaPtr arena, langcc::Int id, langcc::TokenBounds bounds, bool is_top, langcc::ParserSymId sym, langcc::ParserAttrMask attr, langcc::ParserLookahead first_k);
}

namespace lang::meta::Node::AttrMatchCasePattern::Wildcard {
    struct _T: lang::meta::Node::AttrMatchCasePattern::_T {
        void write(langcc::Ref<std::ostream> os, langcc::FmtFlags flags);
        void write(langcc::Ref<langcc::PrBufStream_T> pb);
        _T();
        lang::meta::Node::AttrMatchCasePattern::Wildcard_T with_id(langcc::Int id);
        lang::meta::Node::AttrMatchCasePattern::Wildcard_T with_bounds(langcc::TokenBounds bounds);
        lang::meta::Node::AttrMatchCasePattern::Wildcard_T with_is_top(bool is_top);
        lang::meta::Node::AttrMatchCasePattern::Wildcard_T with_sym(langcc::ParserSymId sym);
        lang::meta::Node::AttrMatchCasePattern::Wildcard_T with_attr(langcc::ParserAttrMask attr);
        lang::meta::Node::AttrMatchCasePattern::Wildcard_T with_first_k(langcc::ParserLookahead first_k);
        void hash_ser_acc_lang_meta_Node_AttrMatchCasePattern_Wildcard(langcc::SerBuf& buf) const;
        virtual void hash_ser_acc(langcc::SerBuf& buf) const;
    };
}

namespace langcc {
    void pr_debug(ostream& os, FmtFlags flags, lang::meta::Node::AttrClauseExpr::LhsGeq_T x);
}

namespace lang::meta::Node::AttrClauseExpr::LhsGeq {
    lang::meta::Node::AttrClauseExpr::LhsGeq_T make(langcc::Int id, langcc::TokenBounds bounds, bool is_top, langcc::ParserSymId sym, langcc::ParserAttrMask attr, langcc::ParserLookahead first_k, langcc::StrSlice k);
}

namespace lang::meta::Node::AttrClauseExpr::LhsGeq {
    lang::meta::Node::AttrClauseExpr::LhsGeq_T make_ext(langcc::ArenaPtr arena, langcc::Int id, langcc::TokenBounds bounds, bool is_top, langcc::ParserSymId sym, langcc::ParserAttrMask attr, langcc::ParserLookahead first_k, langcc::StrSlice k);
}

namespace lang::meta::Node::AttrClauseExpr::LhsGeq {
    struct _T: lang::meta::Node::AttrClauseExpr::_T {
        void write(langcc::Ref<std::ostream> os, langcc::FmtFlags flags);
        void write(langcc::Ref<langcc::PrBufStream_T> pb);
        langcc::StrSlice k_;
        _T();
        lang::meta::Node::AttrClauseExpr::LhsGeq_T with_id(langcc::Int id);
        lang::meta::Node::AttrClauseExpr::LhsGeq_T with_bounds(langcc::TokenBounds bounds);
        lang::meta::Node::AttrClauseExpr::LhsGeq_T with_is_top(bool is_top);
        lang::meta::Node::AttrClauseExpr::LhsGeq_T with_sym(langcc::ParserSymId sym);
        lang::meta::Node::AttrClauseExpr::LhsGeq_T with_attr(langcc::ParserAttrMask attr);
        lang::meta::Node::AttrClauseExpr::LhsGeq_T with_first_k(langcc::ParserLookahead first_k);
        lang::meta::Node::AttrClauseExpr::LhsGeq_T with_k(langcc::StrSlice k);
        void hash_ser_acc_lang_meta_Node_AttrClauseExpr_LhsGeq(langcc::SerBuf& buf) const;
        virtual void hash_ser_acc(langcc::SerBuf& buf) const;
    };
}

namespace langcc {
    void pr_debug(ostream& os, FmtFlags flags, lang::meta::Node::AttrClauseExpr::RhsGeq_T x);
}

namespace lang::meta::Node::AttrClauseExpr::RhsGeq {
    lang::meta::Node::AttrClauseExpr::RhsGeq_T make(langcc::Int id, langcc::TokenBounds bounds, bool is_top, langcc::ParserSymId sym, langcc::ParserAttrMask attr, langcc::ParserLookahead first_k, lang::meta::Node::AttrClauseExprRhsLoc_T loc, langcc::StrSlice k);
}

namespace lang::meta::Node::AttrClauseExpr::RhsGeq {
    lang::meta::Node::AttrClauseExpr::RhsGeq_T make_ext(langcc::ArenaPtr arena, langcc::Int id, langcc::TokenBounds bounds, bool is_top, langcc::ParserSymId sym, langcc::ParserAttrMask attr, langcc::ParserLookahead first_k, lang::meta::Node::AttrClauseExprRhsLoc_T loc, langcc::StrSlice k);
}

namespace lang::meta::Node::AttrClauseExpr::RhsGeq {
    struct _T: lang::meta::Node::AttrClauseExpr::_T {
        void write(langcc::Ref<std::ostream> os, langcc::FmtFlags flags);
        void write(langcc::Ref<langcc::PrBufStream_T> pb);
        lang::meta::Node::AttrClauseExprRhsLoc_T loc_;
        langcc::StrSlice k_;
        _T();
        lang::meta::Node::AttrClauseExpr::RhsGeq_T with_id(langcc::Int id);
        lang::meta::Node::AttrClauseExpr::RhsGeq_T with_bounds(langcc::TokenBounds bounds);
        lang::meta::Node::AttrClauseExpr::RhsGeq_T with_is_top(bool is_top);
        lang::meta::Node::AttrClauseExpr::RhsGeq_T with_sym(langcc::ParserSymId sym);
        lang::meta::Node::AttrClauseExpr::RhsGeq_T with_attr(langcc::ParserAttrMask attr);
        lang::meta::Node::AttrClauseExpr::RhsGeq_T with_first_k(langcc::ParserLookahead first_k);
        lang::meta::Node::AttrClauseExpr::RhsGeq_T with_loc(lang::meta::Node::AttrClauseExprRhsLoc_T loc);
        lang::meta::Node::AttrClauseExpr::RhsGeq_T with_k(langcc::StrSlice k);
        void hash_ser_acc_lang_meta_Node_AttrClauseExpr_RhsGeq(langcc::SerBuf& buf) const;
        virtual void hash_ser_acc(langcc::SerBuf& buf) const;
    };
}

namespace langcc {
    void pr_debug(ostream& os, FmtFlags flags, lang::meta::Node::AttrClauseExpr::Implies_T x);
}

namespace lang::meta::Node::AttrClauseExpr::Implies {
    lang::meta::Node::AttrClauseExpr::Implies_T make(langcc::Int id, langcc::TokenBounds bounds, bool is_top, langcc::ParserSymId sym, langcc::ParserAttrMask attr, langcc::ParserLookahead first_k, langcc::StrSlice kl, lang::meta::Node::AttrClauseExprRhsLoc_T loc, langcc::StrSlice kr);
}

namespace lang::meta::Node::AttrClauseExpr::Implies {
    lang::meta::Node::AttrClauseExpr::Implies_T make_ext(langcc::ArenaPtr arena, langcc::Int id, langcc::TokenBounds bounds, bool is_top, langcc::ParserSymId sym, langcc::ParserAttrMask attr, langcc::ParserLookahead first_k, langcc::StrSlice kl, lang::meta::Node::AttrClauseExprRhsLoc_T loc, langcc::StrSlice kr);
}

namespace lang::meta::Node::AttrClauseExpr::Implies {
    struct _T: lang::meta::Node::AttrClauseExpr::_T {
        void write(langcc::Ref<std::ostream> os, langcc::FmtFlags flags);
        void write(langcc::Ref<langcc::PrBufStream_T> pb);
        langcc::StrSlice kl_;
        lang::meta::Node::AttrClauseExprRhsLoc_T loc_;
        langcc::StrSlice kr_;
        _T();
        lang::meta::Node::AttrClauseExpr::Implies_T with_id(langcc::Int id);
        lang::meta::Node::AttrClauseExpr::Implies_T with_bounds(langcc::TokenBounds bounds);
        lang::meta::Node::AttrClauseExpr::Implies_T with_is_top(bool is_top);
        lang::meta::Node::AttrClauseExpr::Implies_T with_sym(langcc::ParserSymId sym);
        lang::meta::Node::AttrClauseExpr::Implies_T with_attr(langcc::ParserAttrMask attr);
        lang::meta::Node::AttrClauseExpr::Implies_T with_first_k(langcc::ParserLookahead first_k);
        lang::meta::Node::AttrClauseExpr::Implies_T with_kl(langcc::StrSlice kl);
        lang::meta::Node::AttrClauseExpr::Implies_T with_loc(lang::meta::Node::AttrClauseExprRhsLoc_T loc);
        lang::meta::Node::AttrClauseExpr::Implies_T with_kr(langcc::StrSlice kr);
        void hash_ser_acc_lang_meta_Node_AttrClauseExpr_Implies(langcc::SerBuf& buf) const;
        virtual void hash_ser_acc(langcc::SerBuf& buf) const;
    };
}

namespace langcc {
    void pr_debug(ostream& os, FmtFlags flags, lang::meta::Node::AttrClauseExprRhsLoc::All_T x);
}

namespace lang::meta::Node::AttrClauseExprRhsLoc::All {
    lang::meta::Node::AttrClauseExprRhsLoc::All_T make(langcc::Int id, langcc::TokenBounds bounds, bool is_top, langcc::ParserSymId sym, langcc::ParserAttrMask attr, langcc::ParserLookahead first_k);
}

namespace lang::meta::Node::AttrClauseExprRhsLoc::All {
    lang::meta::Node::AttrClauseExprRhsLoc::All_T make_ext(langcc::ArenaPtr arena, langcc::Int id, langcc::TokenBounds bounds, bool is_top, langcc::ParserSymId sym, langcc::ParserAttrMask attr, langcc::ParserLookahead first_k);
}

namespace lang::meta::Node::AttrClauseExprRhsLoc::All {
    struct _T: lang::meta::Node::AttrClauseExprRhsLoc::_T {
        void write(langcc::Ref<std::ostream> os, langcc::FmtFlags flags);
        void write(langcc::Ref<langcc::PrBufStream_T> pb);
        _T();
        lang::meta::Node::AttrClauseExprRhsLoc::All_T with_id(langcc::Int id);
        lang::meta::Node::AttrClauseExprRhsLoc::All_T with_bounds(langcc::TokenBounds bounds);
        lang::meta::Node::AttrClauseExprRhsLoc::All_T with_is_top(bool is_top);
        lang::meta::Node::AttrClauseExprRhsLoc::All_T with_sym(langcc::ParserSymId sym);
        lang::meta::Node::AttrClauseExprRhsLoc::All_T with_attr(langcc::ParserAttrMask attr);
        lang::meta::Node::AttrClauseExprRhsLoc::All_T with_first_k(langcc::ParserLookahead first_k);
        void hash_ser_acc_lang_meta_Node_AttrClauseExprRhsLoc_All(langcc::SerBuf& buf) const;
        virtual void hash_ser_acc(langcc::SerBuf& buf) const;
    };
}

namespace langcc {
    void pr_debug(ostream& os, FmtFlags flags, lang::meta::Node::AttrClauseExprRhsLoc::Begin_T x);
}

namespace lang::meta::Node::AttrClauseExprRhsLoc::Begin {
    lang::meta::Node::AttrClauseExprRhsLoc::Begin_T make(langcc::Int id, langcc::TokenBounds bounds, bool is_top, langcc::ParserSymId sym, langcc::ParserAttrMask attr, langcc::ParserLookahead first_k);
}

namespace lang::meta::Node::AttrClauseExprRhsLoc::Begin {
    lang::meta::Node::AttrClauseExprRhsLoc::Begin_T make_ext(langcc::ArenaPtr arena, langcc::Int id, langcc::TokenBounds bounds, bool is_top, langcc::ParserSymId sym, langcc::ParserAttrMask attr, langcc::ParserLookahead first_k);
}

namespace lang::meta::Node::AttrClauseExprRhsLoc::Begin {
    struct _T: lang::meta::Node::AttrClauseExprRhsLoc::_T {
        void write(langcc::Ref<std::ostream> os, langcc::FmtFlags flags);
        void write(langcc::Ref<langcc::PrBufStream_T> pb);
        _T();
        lang::meta::Node::AttrClauseExprRhsLoc::Begin_T with_id(langcc::Int id);
        lang::meta::Node::AttrClauseExprRhsLoc::Begin_T with_bounds(langcc::TokenBounds bounds);
        lang::meta::Node::AttrClauseExprRhsLoc::Begin_T with_is_top(bool is_top);
        lang::meta::Node::AttrClauseExprRhsLoc::Begin_T with_sym(langcc::ParserSymId sym);
        lang::meta::Node::AttrClauseExprRhsLoc::Begin_T with_attr(langcc::ParserAttrMask attr);
        lang::meta::Node::AttrClauseExprRhsLoc::Begin_T with_first_k(langcc::ParserLookahead first_k);
        void hash_ser_acc_lang_meta_Node_AttrClauseExprRhsLoc_Begin(langcc::SerBuf& buf) const;
        virtual void hash_ser_acc(langcc::SerBuf& buf) const;
    };
}

namespace langcc {
    void pr_debug(ostream& os, FmtFlags flags, lang::meta::Node::AttrClauseExprRhsLoc::Mid_T x);
}

namespace lang::meta::Node::AttrClauseExprRhsLoc::Mid {
    lang::meta::Node::AttrClauseExprRhsLoc::Mid_T make(langcc::Int id, langcc::TokenBounds bounds, bool is_top, langcc::ParserSymId sym, langcc::ParserAttrMask attr, langcc::ParserLookahead first_k);
}

namespace lang::meta::Node::AttrClauseExprRhsLoc::Mid {
    lang::meta::Node::AttrClauseExprRhsLoc::Mid_T make_ext(langcc::ArenaPtr arena, langcc::Int id, langcc::TokenBounds bounds, bool is_top, langcc::ParserSymId sym, langcc::ParserAttrMask attr, langcc::ParserLookahead first_k);
}

namespace lang::meta::Node::AttrClauseExprRhsLoc::Mid {
    struct _T: lang::meta::Node::AttrClauseExprRhsLoc::_T {
        void write(langcc::Ref<std::ostream> os, langcc::FmtFlags flags);
        void write(langcc::Ref<langcc::PrBufStream_T> pb);
        _T();
        lang::meta::Node::AttrClauseExprRhsLoc::Mid_T with_id(langcc::Int id);
        lang::meta::Node::AttrClauseExprRhsLoc::Mid_T with_bounds(langcc::TokenBounds bounds);
        lang::meta::Node::AttrClauseExprRhsLoc::Mid_T with_is_top(bool is_top);
        lang::meta::Node::AttrClauseExprRhsLoc::Mid_T with_sym(langcc::ParserSymId sym);
        lang::meta::Node::AttrClauseExprRhsLoc::Mid_T with_attr(langcc::ParserAttrMask attr);
        lang::meta::Node::AttrClauseExprRhsLoc::Mid_T with_first_k(langcc::ParserLookahead first_k);
        void hash_ser_acc_lang_meta_Node_AttrClauseExprRhsLoc_Mid(langcc::SerBuf& buf) const;
        virtual void hash_ser_acc(langcc::SerBuf& buf) const;
    };
}

namespace langcc {
    void pr_debug(ostream& os, FmtFlags flags, lang::meta::Node::AttrClauseExprRhsLoc::End_T x);
}

namespace lang::meta::Node::AttrClauseExprRhsLoc::End {
    lang::meta::Node::AttrClauseExprRhsLoc::End_T make(langcc::Int id, langcc::TokenBounds bounds, bool is_top, langcc::ParserSymId sym, langcc::ParserAttrMask attr, langcc::ParserLookahead first_k);
}

namespace lang::meta::Node::AttrClauseExprRhsLoc::End {
    lang::meta::Node::AttrClauseExprRhsLoc::End_T make_ext(langcc::ArenaPtr arena, langcc::Int id, langcc::TokenBounds bounds, bool is_top, langcc::ParserSymId sym, langcc::ParserAttrMask attr, langcc::ParserLookahead first_k);
}

namespace lang::meta::Node::AttrClauseExprRhsLoc::End {
    struct _T: lang::meta::Node::AttrClauseExprRhsLoc::_T {
        void write(langcc::Ref<std::ostream> os, langcc::FmtFlags flags);
        void write(langcc::Ref<langcc::PrBufStream_T> pb);
        _T();
        lang::meta::Node::AttrClauseExprRhsLoc::End_T with_id(langcc::Int id);
        lang::meta::Node::AttrClauseExprRhsLoc::End_T with_bounds(langcc::TokenBounds bounds);
        lang::meta::Node::AttrClauseExprRhsLoc::End_T with_is_top(bool is_top);
        lang::meta::Node::AttrClauseExprRhsLoc::End_T with_sym(langcc::ParserSymId sym);
        lang::meta::Node::AttrClauseExprRhsLoc::End_T with_attr(langcc::ParserAttrMask attr);
        lang::meta::Node::AttrClauseExprRhsLoc::End_T with_first_k(langcc::ParserLookahead first_k);
        void hash_ser_acc_lang_meta_Node_AttrClauseExprRhsLoc_End(langcc::SerBuf& buf) const;
        virtual void hash_ser_acc(langcc::SerBuf& buf) const;
    };
}

namespace langcc {
    void pr_debug(ostream& os, FmtFlags flags, lang::meta::Node::ParseExpr::Id_T x);
}

namespace lang::meta::Node::ParseExpr::Id {
    lang::meta::Node::ParseExpr::Id_T make(langcc::Int id, langcc::TokenBounds bounds, bool is_top, langcc::ParserSymId sym, langcc::ParserAttrMask attr, langcc::ParserLookahead first_k, lang::meta::Node::Id_T id_);
}

namespace lang::meta::Node::ParseExpr::Id {
    lang::meta::Node::ParseExpr::Id_T make_ext(langcc::ArenaPtr arena, langcc::Int id, langcc::TokenBounds bounds, bool is_top, langcc::ParserSymId sym, langcc::ParserAttrMask attr, langcc::ParserLookahead first_k, lang::meta::Node::Id_T id_);
}

namespace lang::meta::Node::ParseExpr::Id {
    struct _T: lang::meta::Node::ParseExpr::_T {
        void write(langcc::Ref<std::ostream> os, langcc::FmtFlags flags);
        void write(langcc::Ref<langcc::PrBufStream_T> pb);
        lang::meta::Node::Id_T id__;
        _T();
        lang::meta::Node::ParseExpr::Id_T with_id(langcc::Int id);
        lang::meta::Node::ParseExpr::Id_T with_bounds(langcc::TokenBounds bounds);
        lang::meta::Node::ParseExpr::Id_T with_is_top(bool is_top);
        lang::meta::Node::ParseExpr::Id_T with_sym(langcc::ParserSymId sym);
        lang::meta::Node::ParseExpr::Id_T with_attr(langcc::ParserAttrMask attr);
        lang::meta::Node::ParseExpr::Id_T with_first_k(langcc::ParserLookahead first_k);
        lang::meta::Node::ParseExpr::Id_T with_id_(lang::meta::Node::Id_T id_);
        void hash_ser_acc_lang_meta_Node_ParseExpr_Id(langcc::SerBuf& buf) const;
        virtual void hash_ser_acc(langcc::SerBuf& buf) const;
    };
}

namespace langcc {
    void pr_debug(ostream& os, FmtFlags flags, lang::meta::Node::ParseExpr::Eof_T x);
}

namespace lang::meta::Node::ParseExpr::Eof {
    lang::meta::Node::ParseExpr::Eof_T make(langcc::Int id, langcc::TokenBounds bounds, bool is_top, langcc::ParserSymId sym, langcc::ParserAttrMask attr, langcc::ParserLookahead first_k);
}

namespace lang::meta::Node::ParseExpr::Eof {
    lang::meta::Node::ParseExpr::Eof_T make_ext(langcc::ArenaPtr arena, langcc::Int id, langcc::TokenBounds bounds, bool is_top, langcc::ParserSymId sym, langcc::ParserAttrMask attr, langcc::ParserLookahead first_k);
}

namespace lang::meta::Node::ParseExpr::Eof {
    struct _T: lang::meta::Node::ParseExpr::_T {
        void write(langcc::Ref<std::ostream> os, langcc::FmtFlags flags);
        void write(langcc::Ref<langcc::PrBufStream_T> pb);
        _T();
        lang::meta::Node::ParseExpr::Eof_T with_id(langcc::Int id);
        lang::meta::Node::ParseExpr::Eof_T with_bounds(langcc::TokenBounds bounds);
        lang::meta::Node::ParseExpr::Eof_T with_is_top(bool is_top);
        lang::meta::Node::ParseExpr::Eof_T with_sym(langcc::ParserSymId sym);
        lang::meta::Node::ParseExpr::Eof_T with_attr(langcc::ParserAttrMask attr);
        lang::meta::Node::ParseExpr::Eof_T with_first_k(langcc::ParserLookahead first_k);
        void hash_ser_acc_lang_meta_Node_ParseExpr_Eof(langcc::SerBuf& buf) const;
        virtual void hash_ser_acc(langcc::SerBuf& buf) const;
    };
}

namespace langcc {
    void pr_debug(ostream& os, FmtFlags flags, lang::meta::Node::ParseExpr::False_T x);
}

namespace lang::meta::Node::ParseExpr::False {
    lang::meta::Node::ParseExpr::False_T make(langcc::Int id, langcc::TokenBounds bounds, bool is_top, langcc::ParserSymId sym, langcc::ParserAttrMask attr, langcc::ParserLookahead first_k);
}

namespace lang::meta::Node::ParseExpr::False {
    lang::meta::Node::ParseExpr::False_T make_ext(langcc::ArenaPtr arena, langcc::Int id, langcc::TokenBounds bounds, bool is_top, langcc::ParserSymId sym, langcc::ParserAttrMask attr, langcc::ParserLookahead first_k);
}

namespace lang::meta::Node::ParseExpr::False {
    struct _T: lang::meta::Node::ParseExpr::_T {
        void write(langcc::Ref<std::ostream> os, langcc::FmtFlags flags);
        void write(langcc::Ref<langcc::PrBufStream_T> pb);
        _T();
        lang::meta::Node::ParseExpr::False_T with_id(langcc::Int id);
        lang::meta::Node::ParseExpr::False_T with_bounds(langcc::TokenBounds bounds);
        lang::meta::Node::ParseExpr::False_T with_is_top(bool is_top);
        lang::meta::Node::ParseExpr::False_T with_sym(langcc::ParserSymId sym);
        lang::meta::Node::ParseExpr::False_T with_attr(langcc::ParserAttrMask attr);
        lang::meta::Node::ParseExpr::False_T with_first_k(langcc::ParserLookahead first_k);
        void hash_ser_acc_lang_meta_Node_ParseExpr_False(langcc::SerBuf& buf) const;
        virtual void hash_ser_acc(langcc::SerBuf& buf) const;
    };
}

namespace langcc {
    void pr_debug(ostream& os, FmtFlags flags, lang::meta::Node::ParseExpr::Eps_T x);
}

namespace lang::meta::Node::ParseExpr::Eps {
    lang::meta::Node::ParseExpr::Eps_T make(langcc::Int id, langcc::TokenBounds bounds, bool is_top, langcc::ParserSymId sym, langcc::ParserAttrMask attr, langcc::ParserLookahead first_k);
}

namespace lang::meta::Node::ParseExpr::Eps {
    lang::meta::Node::ParseExpr::Eps_T make_ext(langcc::ArenaPtr arena, langcc::Int id, langcc::TokenBounds bounds, bool is_top, langcc::ParserSymId sym, langcc::ParserAttrMask attr, langcc::ParserLookahead first_k);
}

namespace lang::meta::Node::ParseExpr::Eps {
    struct _T: lang::meta::Node::ParseExpr::_T {
        void write(langcc::Ref<std::ostream> os, langcc::FmtFlags flags);
        void write(langcc::Ref<langcc::PrBufStream_T> pb);
        _T();
        lang::meta::Node::ParseExpr::Eps_T with_id(langcc::Int id);
        lang::meta::Node::ParseExpr::Eps_T with_bounds(langcc::TokenBounds bounds);
        lang::meta::Node::ParseExpr::Eps_T with_is_top(bool is_top);
        lang::meta::Node::ParseExpr::Eps_T with_sym(langcc::ParserSymId sym);
        lang::meta::Node::ParseExpr::Eps_T with_attr(langcc::ParserAttrMask attr);
        lang::meta::Node::ParseExpr::Eps_T with_first_k(langcc::ParserLookahead first_k);
        void hash_ser_acc_lang_meta_Node_ParseExpr_Eps(langcc::SerBuf& buf) const;
        virtual void hash_ser_acc(langcc::SerBuf& buf) const;
    };
}

namespace langcc {
    void pr_debug(ostream& os, FmtFlags flags, lang::meta::Node::ParseExpr::Indent_T x);
}

namespace lang::meta::Node::ParseExpr::Indent {
    lang::meta::Node::ParseExpr::Indent_T make(langcc::Int id, langcc::TokenBounds bounds, bool is_top, langcc::ParserSymId sym, langcc::ParserAttrMask attr, langcc::ParserLookahead first_k);
}

namespace lang::meta::Node::ParseExpr::Indent {
    lang::meta::Node::ParseExpr::Indent_T make_ext(langcc::ArenaPtr arena, langcc::Int id, langcc::TokenBounds bounds, bool is_top, langcc::ParserSymId sym, langcc::ParserAttrMask attr, langcc::ParserLookahead first_k);
}

namespace lang::meta::Node::ParseExpr::Indent {
    struct _T: lang::meta::Node::ParseExpr::_T {
        void write(langcc::Ref<std::ostream> os, langcc::FmtFlags flags);
        void write(langcc::Ref<langcc::PrBufStream_T> pb);
        _T();
        lang::meta::Node::ParseExpr::Indent_T with_id(langcc::Int id);
        lang::meta::Node::ParseExpr::Indent_T with_bounds(langcc::TokenBounds bounds);
        lang::meta::Node::ParseExpr::Indent_T with_is_top(bool is_top);
        lang::meta::Node::ParseExpr::Indent_T with_sym(langcc::ParserSymId sym);
        lang::meta::Node::ParseExpr::Indent_T with_attr(langcc::ParserAttrMask attr);
        lang::meta::Node::ParseExpr::Indent_T with_first_k(langcc::ParserLookahead first_k);
        void hash_ser_acc_lang_meta_Node_ParseExpr_Indent(langcc::SerBuf& buf) const;
        virtual void hash_ser_acc(langcc::SerBuf& buf) const;
    };
}

namespace langcc {
    void pr_debug(ostream& os, FmtFlags flags, lang::meta::Node::ParseExpr::Dedent_T x);
}

namespace lang::meta::Node::ParseExpr::Dedent {
    lang::meta::Node::ParseExpr::Dedent_T make(langcc::Int id, langcc::TokenBounds bounds, bool is_top, langcc::ParserSymId sym, langcc::ParserAttrMask attr, langcc::ParserLookahead first_k);
}

namespace lang::meta::Node::ParseExpr::Dedent {
    lang::meta::Node::ParseExpr::Dedent_T make_ext(langcc::ArenaPtr arena, langcc::Int id, langcc::TokenBounds bounds, bool is_top, langcc::ParserSymId sym, langcc::ParserAttrMask attr, langcc::ParserLookahead first_k);
}

namespace lang::meta::Node::ParseExpr::Dedent {
    struct _T: lang::meta::Node::ParseExpr::_T {
        void write(langcc::Ref<std::ostream> os, langcc::FmtFlags flags);
        void write(langcc::Ref<langcc::PrBufStream_T> pb);
        _T();
        lang::meta::Node::ParseExpr::Dedent_T with_id(langcc::Int id);
        lang::meta::Node::ParseExpr::Dedent_T with_bounds(langcc::TokenBounds bounds);
        lang::meta::Node::ParseExpr::Dedent_T with_is_top(bool is_top);
        lang::meta::Node::ParseExpr::Dedent_T with_sym(langcc::ParserSymId sym);
        lang::meta::Node::ParseExpr::Dedent_T with_attr(langcc::ParserAttrMask attr);
        lang::meta::Node::ParseExpr::Dedent_T with_first_k(langcc::ParserLookahead first_k);
        void hash_ser_acc_lang_meta_Node_ParseExpr_Dedent(langcc::SerBuf& buf) const;
        virtual void hash_ser_acc(langcc::SerBuf& buf) const;
    };
}

namespace langcc {
    void pr_debug(ostream& os, FmtFlags flags, lang::meta::Node::ParseExpr::Newline_T x);
}

namespace lang::meta::Node::ParseExpr::Newline {
    lang::meta::Node::ParseExpr::Newline_T make(langcc::Int id, langcc::TokenBounds bounds, bool is_top, langcc::ParserSymId sym, langcc::ParserAttrMask attr, langcc::ParserLookahead first_k);
}

namespace lang::meta::Node::ParseExpr::Newline {
    lang::meta::Node::ParseExpr::Newline_T make_ext(langcc::ArenaPtr arena, langcc::Int id, langcc::TokenBounds bounds, bool is_top, langcc::ParserSymId sym, langcc::ParserAttrMask attr, langcc::ParserLookahead first_k);
}

namespace lang::meta::Node::ParseExpr::Newline {
    struct _T: lang::meta::Node::ParseExpr::_T {
        void write(langcc::Ref<std::ostream> os, langcc::FmtFlags flags);
        void write(langcc::Ref<langcc::PrBufStream_T> pb);
        _T();
        lang::meta::Node::ParseExpr::Newline_T with_id(langcc::Int id);
        lang::meta::Node::ParseExpr::Newline_T with_bounds(langcc::TokenBounds bounds);
        lang::meta::Node::ParseExpr::Newline_T with_is_top(bool is_top);
        lang::meta::Node::ParseExpr::Newline_T with_sym(langcc::ParserSymId sym);
        lang::meta::Node::ParseExpr::Newline_T with_attr(langcc::ParserAttrMask attr);
        lang::meta::Node::ParseExpr::Newline_T with_first_k(langcc::ParserLookahead first_k);
        void hash_ser_acc_lang_meta_Node_ParseExpr_Newline(langcc::SerBuf& buf) const;
        virtual void hash_ser_acc(langcc::SerBuf& buf) const;
    };
}

namespace langcc {
    void pr_debug(ostream& os, FmtFlags flags, lang::meta::Node::ParseExpr::UnicodeAny_T x);
}

namespace lang::meta::Node::ParseExpr::UnicodeAny {
    lang::meta::Node::ParseExpr::UnicodeAny_T make(langcc::Int id, langcc::TokenBounds bounds, bool is_top, langcc::ParserSymId sym, langcc::ParserAttrMask attr, langcc::ParserLookahead first_k);
}

namespace lang::meta::Node::ParseExpr::UnicodeAny {
    lang::meta::Node::ParseExpr::UnicodeAny_T make_ext(langcc::ArenaPtr arena, langcc::Int id, langcc::TokenBounds bounds, bool is_top, langcc::ParserSymId sym, langcc::ParserAttrMask attr, langcc::ParserLookahead first_k);
}

namespace lang::meta::Node::ParseExpr::UnicodeAny {
    struct _T: lang::meta::Node::ParseExpr::_T {
        void write(langcc::Ref<std::ostream> os, langcc::FmtFlags flags);
        void write(langcc::Ref<langcc::PrBufStream_T> pb);
        _T();
        lang::meta::Node::ParseExpr::UnicodeAny_T with_id(langcc::Int id);
        lang::meta::Node::ParseExpr::UnicodeAny_T with_bounds(langcc::TokenBounds bounds);
        lang::meta::Node::ParseExpr::UnicodeAny_T with_is_top(bool is_top);
        lang::meta::Node::ParseExpr::UnicodeAny_T with_sym(langcc::ParserSymId sym);
        lang::meta::Node::ParseExpr::UnicodeAny_T with_attr(langcc::ParserAttrMask attr);
        lang::meta::Node::ParseExpr::UnicodeAny_T with_first_k(langcc::ParserLookahead first_k);
        void hash_ser_acc_lang_meta_Node_ParseExpr_UnicodeAny(langcc::SerBuf& buf) const;
        virtual void hash_ser_acc(langcc::SerBuf& buf) const;
    };
}

namespace langcc {
    void pr_debug(ostream& os, FmtFlags flags, lang::meta::Node::ParseExpr::AsciiBaseAny_T x);
}

namespace lang::meta::Node::ParseExpr::AsciiBaseAny {
    lang::meta::Node::ParseExpr::AsciiBaseAny_T make(langcc::Int id, langcc::TokenBounds bounds, bool is_top, langcc::ParserSymId sym, langcc::ParserAttrMask attr, langcc::ParserLookahead first_k);
}

namespace lang::meta::Node::ParseExpr::AsciiBaseAny {
    lang::meta::Node::ParseExpr::AsciiBaseAny_T make_ext(langcc::ArenaPtr arena, langcc::Int id, langcc::TokenBounds bounds, bool is_top, langcc::ParserSymId sym, langcc::ParserAttrMask attr, langcc::ParserLookahead first_k);
}

namespace lang::meta::Node::ParseExpr::AsciiBaseAny {
    struct _T: lang::meta::Node::ParseExpr::_T {
        void write(langcc::Ref<std::ostream> os, langcc::FmtFlags flags);
        void write(langcc::Ref<langcc::PrBufStream_T> pb);
        _T();
        lang::meta::Node::ParseExpr::AsciiBaseAny_T with_id(langcc::Int id);
        lang::meta::Node::ParseExpr::AsciiBaseAny_T with_bounds(langcc::TokenBounds bounds);
        lang::meta::Node::ParseExpr::AsciiBaseAny_T with_is_top(bool is_top);
        lang::meta::Node::ParseExpr::AsciiBaseAny_T with_sym(langcc::ParserSymId sym);
        lang::meta::Node::ParseExpr::AsciiBaseAny_T with_attr(langcc::ParserAttrMask attr);
        lang::meta::Node::ParseExpr::AsciiBaseAny_T with_first_k(langcc::ParserLookahead first_k);
        void hash_ser_acc_lang_meta_Node_ParseExpr_AsciiBaseAny(langcc::SerBuf& buf) const;
        virtual void hash_ser_acc(langcc::SerBuf& buf) const;
    };
}

namespace langcc {
    void pr_debug(ostream& os, FmtFlags flags, lang::meta::Node::ParseExpr::Alt_T x);
}

namespace lang::meta::Node::ParseExpr::Alt {
    lang::meta::Node::ParseExpr::Alt_T make(langcc::Int id, langcc::TokenBounds bounds, bool is_top, langcc::ParserSymId sym, langcc::ParserAttrMask attr, langcc::ParserLookahead first_k, langcc::Vec_T<lang::meta::Node::ParseExpr_T> xs);
}

namespace lang::meta::Node::ParseExpr::Alt {
    lang::meta::Node::ParseExpr::Alt_T make_ext(langcc::ArenaPtr arena, langcc::Int id, langcc::TokenBounds bounds, bool is_top, langcc::ParserSymId sym, langcc::ParserAttrMask attr, langcc::ParserLookahead first_k, langcc::Vec_T<lang::meta::Node::ParseExpr_T> xs);
}

namespace lang::meta::Node::ParseExpr::Alt {
    struct _T: lang::meta::Node::ParseExpr::_T {
        void write(langcc::Ref<std::ostream> os, langcc::FmtFlags flags);
        void write(langcc::Ref<langcc::PrBufStream_T> pb);
        langcc::Vec_T<lang::meta::Node::ParseExpr_T> xs_;
        _T();
        lang::meta::Node::ParseExpr::Alt_T with_id(langcc::Int id);
        lang::meta::Node::ParseExpr::Alt_T with_bounds(langcc::TokenBounds bounds);
        lang::meta::Node::ParseExpr::Alt_T with_is_top(bool is_top);
        lang::meta::Node::ParseExpr::Alt_T with_sym(langcc::ParserSymId sym);
        lang::meta::Node::ParseExpr::Alt_T with_attr(langcc::ParserAttrMask attr);
        lang::meta::Node::ParseExpr::Alt_T with_first_k(langcc::ParserLookahead first_k);
        lang::meta::Node::ParseExpr::Alt_T with_xs(langcc::Vec_T<lang::meta::Node::ParseExpr_T> xs);
        void hash_ser_acc_lang_meta_Node_ParseExpr_Alt(langcc::SerBuf& buf) const;
        virtual void hash_ser_acc(langcc::SerBuf& buf) const;
    };
}

namespace langcc {
    void pr_debug(ostream& os, FmtFlags flags, lang::meta::Node::ParseExpr::AltExplicit_T x);
}

namespace lang::meta::Node::ParseExpr::AltExplicit {
    lang::meta::Node::ParseExpr::AltExplicit_T make(langcc::Int id, langcc::TokenBounds bounds, bool is_top, langcc::ParserSymId sym, langcc::ParserAttrMask attr, langcc::ParserLookahead first_k, lang::meta::Node::ParseExpr_T e);
}

namespace lang::meta::Node::ParseExpr::AltExplicit {
    lang::meta::Node::ParseExpr::AltExplicit_T make_ext(langcc::ArenaPtr arena, langcc::Int id, langcc::TokenBounds bounds, bool is_top, langcc::ParserSymId sym, langcc::ParserAttrMask attr, langcc::ParserLookahead first_k, lang::meta::Node::ParseExpr_T e);
}

namespace lang::meta::Node::ParseExpr::AltExplicit {
    struct _T: lang::meta::Node::ParseExpr::_T {
        void write(langcc::Ref<std::ostream> os, langcc::FmtFlags flags);
        void write(langcc::Ref<langcc::PrBufStream_T> pb);
        lang::meta::Node::ParseExpr_T e_;
        _T();
        lang::meta::Node::ParseExpr::AltExplicit_T with_id(langcc::Int id);
        lang::meta::Node::ParseExpr::AltExplicit_T with_bounds(langcc::TokenBounds bounds);
        lang::meta::Node::ParseExpr::AltExplicit_T with_is_top(bool is_top);
        lang::meta::Node::ParseExpr::AltExplicit_T with_sym(langcc::ParserSymId sym);
        lang::meta::Node::ParseExpr::AltExplicit_T with_attr(langcc::ParserAttrMask attr);
        lang::meta::Node::ParseExpr::AltExplicit_T with_first_k(langcc::ParserLookahead first_k);
        lang::meta::Node::ParseExpr::AltExplicit_T with_e(lang::meta::Node::ParseExpr_T e);
        void hash_ser_acc_lang_meta_Node_ParseExpr_AltExplicit(langcc::SerBuf& buf) const;
        virtual void hash_ser_acc(langcc::SerBuf& buf) const;
    };
}

namespace langcc {
    void pr_debug(ostream& os, FmtFlags flags, lang::meta::Node::ParseExpr::Minus_T x);
}

namespace lang::meta::Node::ParseExpr::Minus {
    lang::meta::Node::ParseExpr::Minus_T make(langcc::Int id, langcc::TokenBounds bounds, bool is_top, langcc::ParserSymId sym, langcc::ParserAttrMask attr, langcc::ParserLookahead first_k, lang::meta::Node::ParseExpr_T x, lang::meta::Node::ParseExpr_T y);
}

namespace lang::meta::Node::ParseExpr::Minus {
    lang::meta::Node::ParseExpr::Minus_T make_ext(langcc::ArenaPtr arena, langcc::Int id, langcc::TokenBounds bounds, bool is_top, langcc::ParserSymId sym, langcc::ParserAttrMask attr, langcc::ParserLookahead first_k, lang::meta::Node::ParseExpr_T x, lang::meta::Node::ParseExpr_T y);
}

namespace lang::meta::Node::ParseExpr::Minus {
    struct _T: lang::meta::Node::ParseExpr::_T {
        void write(langcc::Ref<std::ostream> os, langcc::FmtFlags flags);
        void write(langcc::Ref<langcc::PrBufStream_T> pb);
        lang::meta::Node::ParseExpr_T x_;
        lang::meta::Node::ParseExpr_T y_;
        _T();
        lang::meta::Node::ParseExpr::Minus_T with_id(langcc::Int id);
        lang::meta::Node::ParseExpr::Minus_T with_bounds(langcc::TokenBounds bounds);
        lang::meta::Node::ParseExpr::Minus_T with_is_top(bool is_top);
        lang::meta::Node::ParseExpr::Minus_T with_sym(langcc::ParserSymId sym);
        lang::meta::Node::ParseExpr::Minus_T with_attr(langcc::ParserAttrMask attr);
        lang::meta::Node::ParseExpr::Minus_T with_first_k(langcc::ParserLookahead first_k);
        lang::meta::Node::ParseExpr::Minus_T with_x(lang::meta::Node::ParseExpr_T x);
        lang::meta::Node::ParseExpr::Minus_T with_y(lang::meta::Node::ParseExpr_T y);
        void hash_ser_acc_lang_meta_Node_ParseExpr_Minus(langcc::SerBuf& buf) const;
        virtual void hash_ser_acc(langcc::SerBuf& buf) const;
    };
}

namespace langcc {
    void pr_debug(ostream& os, FmtFlags flags, lang::meta::Node::ParseExpr::Concat_T x);
}

namespace lang::meta::Node::ParseExpr::Concat {
    lang::meta::Node::ParseExpr::Concat_T make(langcc::Int id, langcc::TokenBounds bounds, bool is_top, langcc::ParserSymId sym, langcc::ParserAttrMask attr, langcc::ParserLookahead first_k, langcc::Vec_T<lang::meta::Node::ParseExpr_T> xs);
}

namespace lang::meta::Node::ParseExpr::Concat {
    lang::meta::Node::ParseExpr::Concat_T make_ext(langcc::ArenaPtr arena, langcc::Int id, langcc::TokenBounds bounds, bool is_top, langcc::ParserSymId sym, langcc::ParserAttrMask attr, langcc::ParserLookahead first_k, langcc::Vec_T<lang::meta::Node::ParseExpr_T> xs);
}

namespace lang::meta::Node::ParseExpr::Concat {
    struct _T: lang::meta::Node::ParseExpr::_T {
        void write(langcc::Ref<std::ostream> os, langcc::FmtFlags flags);
        void write(langcc::Ref<langcc::PrBufStream_T> pb);
        langcc::Vec_T<lang::meta::Node::ParseExpr_T> xs_;
        _T();
        lang::meta::Node::ParseExpr::Concat_T with_id(langcc::Int id);
        lang::meta::Node::ParseExpr::Concat_T with_bounds(langcc::TokenBounds bounds);
        lang::meta::Node::ParseExpr::Concat_T with_is_top(bool is_top);
        lang::meta::Node::ParseExpr::Concat_T with_sym(langcc::ParserSymId sym);
        lang::meta::Node::ParseExpr::Concat_T with_attr(langcc::ParserAttrMask attr);
        lang::meta::Node::ParseExpr::Concat_T with_first_k(langcc::ParserLookahead first_k);
        lang::meta::Node::ParseExpr::Concat_T with_xs(langcc::Vec_T<lang::meta::Node::ParseExpr_T> xs);
        void hash_ser_acc_lang_meta_Node_ParseExpr_Concat(langcc::SerBuf& buf) const;
        virtual void hash_ser_acc(langcc::SerBuf& buf) const;
    };
}

namespace langcc {
    void pr_debug(ostream& os, FmtFlags flags, lang::meta::Node::ParseExpr::Optional_T x);
}

namespace lang::meta::Node::ParseExpr::Optional {
    lang::meta::Node::ParseExpr::Optional_T make(langcc::Int id, langcc::TokenBounds bounds, bool is_top, langcc::ParserSymId sym, langcc::ParserAttrMask attr, langcc::ParserLookahead first_k, lang::meta::Node::ParseExpr_T x);
}

namespace lang::meta::Node::ParseExpr::Optional {
    lang::meta::Node::ParseExpr::Optional_T make_ext(langcc::ArenaPtr arena, langcc::Int id, langcc::TokenBounds bounds, bool is_top, langcc::ParserSymId sym, langcc::ParserAttrMask attr, langcc::ParserLookahead first_k, lang::meta::Node::ParseExpr_T x);
}

namespace lang::meta::Node::ParseExpr::Optional {
    struct _T: lang::meta::Node::ParseExpr::_T {
        void write(langcc::Ref<std::ostream> os, langcc::FmtFlags flags);
        void write(langcc::Ref<langcc::PrBufStream_T> pb);
        lang::meta::Node::ParseExpr_T x_;
        _T();
        lang::meta::Node::ParseExpr::Optional_T with_id(langcc::Int id);
        lang::meta::Node::ParseExpr::Optional_T with_bounds(langcc::TokenBounds bounds);
        lang::meta::Node::ParseExpr::Optional_T with_is_top(bool is_top);
        lang::meta::Node::ParseExpr::Optional_T with_sym(langcc::ParserSymId sym);
        lang::meta::Node::ParseExpr::Optional_T with_attr(langcc::ParserAttrMask attr);
        lang::meta::Node::ParseExpr::Optional_T with_first_k(langcc::ParserLookahead first_k);
        lang::meta::Node::ParseExpr::Optional_T with_x(lang::meta::Node::ParseExpr_T x);
        void hash_ser_acc_lang_meta_Node_ParseExpr_Optional(langcc::SerBuf& buf) const;
        virtual void hash_ser_acc(langcc::SerBuf& buf) const;
    };
}

namespace langcc {
    void pr_debug(ostream& os, FmtFlags flags, lang::meta::Node::ParseExpr::Rep_T x);
}

namespace lang::meta::Node::ParseExpr::Rep {
    lang::meta::Node::ParseExpr::Rep_T make(langcc::Int id, langcc::TokenBounds bounds, bool is_top, langcc::ParserSymId sym, langcc::ParserAttrMask attr, langcc::ParserLookahead first_k, lang::meta::Node::ParseExpr_T x);
}

namespace lang::meta::Node::ParseExpr::Rep {
    lang::meta::Node::ParseExpr::Rep_T make_ext(langcc::ArenaPtr arena, langcc::Int id, langcc::TokenBounds bounds, bool is_top, langcc::ParserSymId sym, langcc::ParserAttrMask attr, langcc::ParserLookahead first_k, lang::meta::Node::ParseExpr_T x);
}

namespace lang::meta::Node::ParseExpr::Rep {
    struct _T: lang::meta::Node::ParseExpr::_T {
        void write(langcc::Ref<std::ostream> os, langcc::FmtFlags flags);
        void write(langcc::Ref<langcc::PrBufStream_T> pb);
        lang::meta::Node::ParseExpr_T x_;
        _T();
        lang::meta::Node::ParseExpr::Rep_T with_id(langcc::Int id);
        lang::meta::Node::ParseExpr::Rep_T with_bounds(langcc::TokenBounds bounds);
        lang::meta::Node::ParseExpr::Rep_T with_is_top(bool is_top);
        lang::meta::Node::ParseExpr::Rep_T with_sym(langcc::ParserSymId sym);
        lang::meta::Node::ParseExpr::Rep_T with_attr(langcc::ParserAttrMask attr);
        lang::meta::Node::ParseExpr::Rep_T with_first_k(langcc::ParserLookahead first_k);
        lang::meta::Node::ParseExpr::Rep_T with_x(lang::meta::Node::ParseExpr_T x);
        void hash_ser_acc_lang_meta_Node_ParseExpr_Rep(langcc::SerBuf& buf) const;
        virtual void hash_ser_acc(langcc::SerBuf& buf) const;
    };
}

namespace langcc {
    void pr_debug(ostream& os, FmtFlags flags, lang::meta::Node::ParseExpr::RepNonzero_T x);
}

namespace lang::meta::Node::ParseExpr::RepNonzero {
    lang::meta::Node::ParseExpr::RepNonzero_T make(langcc::Int id, langcc::TokenBounds bounds, bool is_top, langcc::ParserSymId sym, langcc::ParserAttrMask attr, langcc::ParserLookahead first_k, lang::meta::Node::ParseExpr_T x);
}

namespace lang::meta::Node::ParseExpr::RepNonzero {
    lang::meta::Node::ParseExpr::RepNonzero_T make_ext(langcc::ArenaPtr arena, langcc::Int id, langcc::TokenBounds bounds, bool is_top, langcc::ParserSymId sym, langcc::ParserAttrMask attr, langcc::ParserLookahead first_k, lang::meta::Node::ParseExpr_T x);
}

namespace lang::meta::Node::ParseExpr::RepNonzero {
    struct _T: lang::meta::Node::ParseExpr::_T {
        void write(langcc::Ref<std::ostream> os, langcc::FmtFlags flags);
        void write(langcc::Ref<langcc::PrBufStream_T> pb);
        lang::meta::Node::ParseExpr_T x_;
        _T();
        lang::meta::Node::ParseExpr::RepNonzero_T with_id(langcc::Int id);
        lang::meta::Node::ParseExpr::RepNonzero_T with_bounds(langcc::TokenBounds bounds);
        lang::meta::Node::ParseExpr::RepNonzero_T with_is_top(bool is_top);
        lang::meta::Node::ParseExpr::RepNonzero_T with_sym(langcc::ParserSymId sym);
        lang::meta::Node::ParseExpr::RepNonzero_T with_attr(langcc::ParserAttrMask attr);
        lang::meta::Node::ParseExpr::RepNonzero_T with_first_k(langcc::ParserLookahead first_k);
        lang::meta::Node::ParseExpr::RepNonzero_T with_x(lang::meta::Node::ParseExpr_T x);
        void hash_ser_acc_lang_meta_Node_ParseExpr_RepNonzero(langcc::SerBuf& buf) const;
        virtual void hash_ser_acc(langcc::SerBuf& buf) const;
    };
}

namespace langcc {
    void pr_debug(ostream& os, FmtFlags flags, lang::meta::Node::ParseExpr::RepCount_T x);
}

namespace lang::meta::Node::ParseExpr::RepCount {
    lang::meta::Node::ParseExpr::RepCount_T make(langcc::Int id, langcc::TokenBounds bounds, bool is_top, langcc::ParserSymId sym, langcc::ParserAttrMask attr, langcc::ParserLookahead first_k, lang::meta::Node::ParseExpr_T x, langcc::StrSlice count);
}

namespace lang::meta::Node::ParseExpr::RepCount {
    lang::meta::Node::ParseExpr::RepCount_T make_ext(langcc::ArenaPtr arena, langcc::Int id, langcc::TokenBounds bounds, bool is_top, langcc::ParserSymId sym, langcc::ParserAttrMask attr, langcc::ParserLookahead first_k, lang::meta::Node::ParseExpr_T x, langcc::StrSlice count);
}

namespace lang::meta::Node::ParseExpr::RepCount {
    struct _T: lang::meta::Node::ParseExpr::_T {
        void write(langcc::Ref<std::ostream> os, langcc::FmtFlags flags);
        void write(langcc::Ref<langcc::PrBufStream_T> pb);
        lang::meta::Node::ParseExpr_T x_;
        langcc::StrSlice count_;
        _T();
        lang::meta::Node::ParseExpr::RepCount_T with_id(langcc::Int id);
        lang::meta::Node::ParseExpr::RepCount_T with_bounds(langcc::TokenBounds bounds);
        lang::meta::Node::ParseExpr::RepCount_T with_is_top(bool is_top);
        lang::meta::Node::ParseExpr::RepCount_T with_sym(langcc::ParserSymId sym);
        lang::meta::Node::ParseExpr::RepCount_T with_attr(langcc::ParserAttrMask attr);
        lang::meta::Node::ParseExpr::RepCount_T with_first_k(langcc::ParserLookahead first_k);
        lang::meta::Node::ParseExpr::RepCount_T with_x(lang::meta::Node::ParseExpr_T x);
        lang::meta::Node::ParseExpr::RepCount_T with_count(langcc::StrSlice count);
        void hash_ser_acc_lang_meta_Node_ParseExpr_RepCount(langcc::SerBuf& buf) const;
        virtual void hash_ser_acc(langcc::SerBuf& buf) const;
    };
}

namespace langcc {
    void pr_debug(ostream& os, FmtFlags flags, lang::meta::Node::ParseExpr::CharRange_T x);
}

namespace lang::meta::Node::ParseExpr::CharRange {
    lang::meta::Node::ParseExpr::CharRange_T make(langcc::Int id, langcc::TokenBounds bounds, bool is_top, langcc::ParserSymId sym, langcc::ParserAttrMask attr, langcc::ParserLookahead first_k, langcc::StrSlice min_, langcc::StrSlice max_);
}

namespace lang::meta::Node::ParseExpr::CharRange {
    lang::meta::Node::ParseExpr::CharRange_T make_ext(langcc::ArenaPtr arena, langcc::Int id, langcc::TokenBounds bounds, bool is_top, langcc::ParserSymId sym, langcc::ParserAttrMask attr, langcc::ParserLookahead first_k, langcc::StrSlice min_, langcc::StrSlice max_);
}

namespace lang::meta::Node::ParseExpr::CharRange {
    struct _T: lang::meta::Node::ParseExpr::_T {
        void write(langcc::Ref<std::ostream> os, langcc::FmtFlags flags);
        void write(langcc::Ref<langcc::PrBufStream_T> pb);
        langcc::StrSlice min__;
        langcc::StrSlice max__;
        _T();
        lang::meta::Node::ParseExpr::CharRange_T with_id(langcc::Int id);
        lang::meta::Node::ParseExpr::CharRange_T with_bounds(langcc::TokenBounds bounds);
        lang::meta::Node::ParseExpr::CharRange_T with_is_top(bool is_top);
        lang::meta::Node::ParseExpr::CharRange_T with_sym(langcc::ParserSymId sym);
        lang::meta::Node::ParseExpr::CharRange_T with_attr(langcc::ParserAttrMask attr);
        lang::meta::Node::ParseExpr::CharRange_T with_first_k(langcc::ParserLookahead first_k);
        lang::meta::Node::ParseExpr::CharRange_T with_min_(langcc::StrSlice min_);
        lang::meta::Node::ParseExpr::CharRange_T with_max_(langcc::StrSlice max_);
        void hash_ser_acc_lang_meta_Node_ParseExpr_CharRange(langcc::SerBuf& buf) const;
        virtual void hash_ser_acc(langcc::SerBuf& buf) const;
    };
}

namespace langcc {
    void pr_debug(ostream& os, FmtFlags flags, lang::meta::Node::ParseExpr::StrLit_T x);
}

namespace lang::meta::Node::ParseExpr::StrLit {
    lang::meta::Node::ParseExpr::StrLit_T make(langcc::Int id, langcc::TokenBounds bounds, bool is_top, langcc::ParserSymId sym, langcc::ParserAttrMask attr, langcc::ParserLookahead first_k, langcc::StrSlice s);
}

namespace lang::meta::Node::ParseExpr::StrLit {
    lang::meta::Node::ParseExpr::StrLit_T make_ext(langcc::ArenaPtr arena, langcc::Int id, langcc::TokenBounds bounds, bool is_top, langcc::ParserSymId sym, langcc::ParserAttrMask attr, langcc::ParserLookahead first_k, langcc::StrSlice s);
}

namespace lang::meta::Node::ParseExpr::StrLit {
    struct _T: lang::meta::Node::ParseExpr::_T {
        void write(langcc::Ref<std::ostream> os, langcc::FmtFlags flags);
        void write(langcc::Ref<langcc::PrBufStream_T> pb);
        langcc::StrSlice s_;
        _T();
        lang::meta::Node::ParseExpr::StrLit_T with_id(langcc::Int id);
        lang::meta::Node::ParseExpr::StrLit_T with_bounds(langcc::TokenBounds bounds);
        lang::meta::Node::ParseExpr::StrLit_T with_is_top(bool is_top);
        lang::meta::Node::ParseExpr::StrLit_T with_sym(langcc::ParserSymId sym);
        lang::meta::Node::ParseExpr::StrLit_T with_attr(langcc::ParserAttrMask attr);
        lang::meta::Node::ParseExpr::StrLit_T with_first_k(langcc::ParserLookahead first_k);
        lang::meta::Node::ParseExpr::StrLit_T with_s(langcc::StrSlice s);
        void hash_ser_acc_lang_meta_Node_ParseExpr_StrLit(langcc::SerBuf& buf) const;
        virtual void hash_ser_acc(langcc::SerBuf& buf) const;
    };
}

namespace langcc {
    void pr_debug(ostream& os, FmtFlags flags, lang::meta::Node::ParseExpr::Underscore_T x);
}

namespace lang::meta::Node::ParseExpr::Underscore {
    lang::meta::Node::ParseExpr::Underscore_T make(langcc::Int id, langcc::TokenBounds bounds, bool is_top, langcc::ParserSymId sym, langcc::ParserAttrMask attr, langcc::ParserLookahead first_k);
}

namespace lang::meta::Node::ParseExpr::Underscore {
    lang::meta::Node::ParseExpr::Underscore_T make_ext(langcc::ArenaPtr arena, langcc::Int id, langcc::TokenBounds bounds, bool is_top, langcc::ParserSymId sym, langcc::ParserAttrMask attr, langcc::ParserLookahead first_k);
}

namespace lang::meta::Node::ParseExpr::Underscore {
    struct _T: lang::meta::Node::ParseExpr::_T {
        void write(langcc::Ref<std::ostream> os, langcc::FmtFlags flags);
        void write(langcc::Ref<langcc::PrBufStream_T> pb);
        _T();
        lang::meta::Node::ParseExpr::Underscore_T with_id(langcc::Int id);
        lang::meta::Node::ParseExpr::Underscore_T with_bounds(langcc::TokenBounds bounds);
        lang::meta::Node::ParseExpr::Underscore_T with_is_top(bool is_top);
        lang::meta::Node::ParseExpr::Underscore_T with_sym(langcc::ParserSymId sym);
        lang::meta::Node::ParseExpr::Underscore_T with_attr(langcc::ParserAttrMask attr);
        lang::meta::Node::ParseExpr::Underscore_T with_first_k(langcc::ParserLookahead first_k);
        void hash_ser_acc_lang_meta_Node_ParseExpr_Underscore(langcc::SerBuf& buf) const;
        virtual void hash_ser_acc(langcc::SerBuf& buf) const;
    };
}

namespace langcc {
    void pr_debug(ostream& os, FmtFlags flags, lang::meta::Node::ParseExpr::Pass_T x);
}

namespace lang::meta::Node::ParseExpr::Pass {
    lang::meta::Node::ParseExpr::Pass_T make(langcc::Int id, langcc::TokenBounds bounds, bool is_top, langcc::ParserSymId sym, langcc::ParserAttrMask attr, langcc::ParserLookahead first_k, langcc::StrSlice s);
}

namespace lang::meta::Node::ParseExpr::Pass {
    lang::meta::Node::ParseExpr::Pass_T make_ext(langcc::ArenaPtr arena, langcc::Int id, langcc::TokenBounds bounds, bool is_top, langcc::ParserSymId sym, langcc::ParserAttrMask attr, langcc::ParserLookahead first_k, langcc::StrSlice s);
}

namespace lang::meta::Node::ParseExpr::Pass {
    struct _T: lang::meta::Node::ParseExpr::_T {
        void write(langcc::Ref<std::ostream> os, langcc::FmtFlags flags);
        void write(langcc::Ref<langcc::PrBufStream_T> pb);
        langcc::StrSlice s_;
        _T();
        lang::meta::Node::ParseExpr::Pass_T with_id(langcc::Int id);
        lang::meta::Node::ParseExpr::Pass_T with_bounds(langcc::TokenBounds bounds);
        lang::meta::Node::ParseExpr::Pass_T with_is_top(bool is_top);
        lang::meta::Node::ParseExpr::Pass_T with_sym(langcc::ParserSymId sym);
        lang::meta::Node::ParseExpr::Pass_T with_attr(langcc::ParserAttrMask attr);
        lang::meta::Node::ParseExpr::Pass_T with_first_k(langcc::ParserLookahead first_k);
        lang::meta::Node::ParseExpr::Pass_T with_s(langcc::StrSlice s);
        void hash_ser_acc_lang_meta_Node_ParseExpr_Pass(langcc::SerBuf& buf) const;
        virtual void hash_ser_acc(langcc::SerBuf& buf) const;
    };
}

namespace langcc {
    void pr_debug(ostream& os, FmtFlags flags, lang::meta::Node::ParseExpr::Paren_T x);
}

namespace lang::meta::Node::ParseExpr::Paren {
    lang::meta::Node::ParseExpr::Paren_T make(langcc::Int id, langcc::TokenBounds bounds, bool is_top, langcc::ParserSymId sym, langcc::ParserAttrMask attr, langcc::ParserLookahead first_k, lang::meta::Node::ParseExpr_T x);
}

namespace lang::meta::Node::ParseExpr::Paren {
    lang::meta::Node::ParseExpr::Paren_T make_ext(langcc::ArenaPtr arena, langcc::Int id, langcc::TokenBounds bounds, bool is_top, langcc::ParserSymId sym, langcc::ParserAttrMask attr, langcc::ParserLookahead first_k, lang::meta::Node::ParseExpr_T x);
}

namespace lang::meta::Node::ParseExpr::Paren {
    struct _T: lang::meta::Node::ParseExpr::_T {
        void write(langcc::Ref<std::ostream> os, langcc::FmtFlags flags);
        void write(langcc::Ref<langcc::PrBufStream_T> pb);
        lang::meta::Node::ParseExpr_T x_;
        _T();
        lang::meta::Node::ParseExpr::Paren_T with_id(langcc::Int id);
        lang::meta::Node::ParseExpr::Paren_T with_bounds(langcc::TokenBounds bounds);
        lang::meta::Node::ParseExpr::Paren_T with_is_top(bool is_top);
        lang::meta::Node::ParseExpr::Paren_T with_sym(langcc::ParserSymId sym);
        lang::meta::Node::ParseExpr::Paren_T with_attr(langcc::ParserAttrMask attr);
        lang::meta::Node::ParseExpr::Paren_T with_first_k(langcc::ParserLookahead first_k);
        lang::meta::Node::ParseExpr::Paren_T with_x(lang::meta::Node::ParseExpr_T x);
        void hash_ser_acc_lang_meta_Node_ParseExpr_Paren(langcc::SerBuf& buf) const;
        virtual void hash_ser_acc(langcc::SerBuf& buf) const;
    };
}

namespace langcc {
    void pr_debug(ostream& os, FmtFlags flags, lang::meta::Node::ParseExpr::Name_T x);
}

namespace lang::meta::Node::ParseExpr::Name {
    lang::meta::Node::ParseExpr::Name_T make(langcc::Int id, langcc::TokenBounds bounds, bool is_top, langcc::ParserSymId sym, langcc::ParserAttrMask attr, langcc::ParserLookahead first_k, langcc::StrSlice name, lang::meta::Node::ParseExpr_T e);
}

namespace lang::meta::Node::ParseExpr::Name {
    lang::meta::Node::ParseExpr::Name_T make_ext(langcc::ArenaPtr arena, langcc::Int id, langcc::TokenBounds bounds, bool is_top, langcc::ParserSymId sym, langcc::ParserAttrMask attr, langcc::ParserLookahead first_k, langcc::StrSlice name, lang::meta::Node::ParseExpr_T e);
}

namespace lang::meta::Node::ParseExpr::Name {
    struct _T: lang::meta::Node::ParseExpr::_T {
        void write(langcc::Ref<std::ostream> os, langcc::FmtFlags flags);
        void write(langcc::Ref<langcc::PrBufStream_T> pb);
        langcc::StrSlice name_;
        lang::meta::Node::ParseExpr_T e_;
        _T();
        lang::meta::Node::ParseExpr::Name_T with_id(langcc::Int id);
        lang::meta::Node::ParseExpr::Name_T with_bounds(langcc::TokenBounds bounds);
        lang::meta::Node::ParseExpr::Name_T with_is_top(bool is_top);
        lang::meta::Node::ParseExpr::Name_T with_sym(langcc::ParserSymId sym);
        lang::meta::Node::ParseExpr::Name_T with_attr(langcc::ParserAttrMask attr);
        lang::meta::Node::ParseExpr::Name_T with_first_k(langcc::ParserLookahead first_k);
        lang::meta::Node::ParseExpr::Name_T with_name(langcc::StrSlice name);
        lang::meta::Node::ParseExpr::Name_T with_e(lang::meta::Node::ParseExpr_T e);
        void hash_ser_acc_lang_meta_Node_ParseExpr_Name(langcc::SerBuf& buf) const;
        virtual void hash_ser_acc(langcc::SerBuf& buf) const;
    };
}

namespace langcc {
    void pr_debug(ostream& os, FmtFlags flags, lang::meta::Node::ParseExpr::List_T x);
}

namespace lang::meta::Node::ParseExpr::List {
    lang::meta::Node::ParseExpr::List_T make(langcc::Int id, langcc::TokenBounds bounds, bool is_top, langcc::ParserSymId sym, langcc::ParserAttrMask attr, langcc::ParserLookahead first_k, lang::meta::Node::ParseExprListType_T ty, lang::meta::Node::ParseExpr_T elem, lang::meta::Node::ParseExprListNum_T num, lang::meta::Node::ParseExpr_T delim, lang::meta::Node::ParseExpr::List::end_delim_T end_delim);
}

namespace lang::meta::Node::ParseExpr::List {
    lang::meta::Node::ParseExpr::List_T make_ext(langcc::ArenaPtr arena, langcc::Int id, langcc::TokenBounds bounds, bool is_top, langcc::ParserSymId sym, langcc::ParserAttrMask attr, langcc::ParserLookahead first_k, lang::meta::Node::ParseExprListType_T ty, lang::meta::Node::ParseExpr_T elem, lang::meta::Node::ParseExprListNum_T num, lang::meta::Node::ParseExpr_T delim, lang::meta::Node::ParseExpr::List::end_delim_T end_delim);
}

namespace lang::meta::Node::ParseExpr::List {
    struct _T: lang::meta::Node::ParseExpr::_T {
        void write(langcc::Ref<std::ostream> os, langcc::FmtFlags flags);
        void write(langcc::Ref<langcc::PrBufStream_T> pb);
        lang::meta::Node::ParseExprListType_T ty_;
        lang::meta::Node::ParseExpr_T elem_;
        lang::meta::Node::ParseExprListNum_T num_;
        lang::meta::Node::ParseExpr_T delim_;
        lang::meta::Node::ParseExpr::List::end_delim_T end_delim_;
        _T();
        lang::meta::Node::ParseExpr::List_T with_id(langcc::Int id);
        lang::meta::Node::ParseExpr::List_T with_bounds(langcc::TokenBounds bounds);
        lang::meta::Node::ParseExpr::List_T with_is_top(bool is_top);
        lang::meta::Node::ParseExpr::List_T with_sym(langcc::ParserSymId sym);
        lang::meta::Node::ParseExpr::List_T with_attr(langcc::ParserAttrMask attr);
        lang::meta::Node::ParseExpr::List_T with_first_k(langcc::ParserLookahead first_k);
        lang::meta::Node::ParseExpr::List_T with_ty(lang::meta::Node::ParseExprListType_T ty);
        lang::meta::Node::ParseExpr::List_T with_elem(lang::meta::Node::ParseExpr_T elem);
        lang::meta::Node::ParseExpr::List_T with_num(lang::meta::Node::ParseExprListNum_T num);
        lang::meta::Node::ParseExpr::List_T with_delim(lang::meta::Node::ParseExpr_T delim);
        lang::meta::Node::ParseExpr::List_T with_end_delim(lang::meta::Node::ParseExpr::List::end_delim_T end_delim);
        void hash_ser_acc_lang_meta_Node_ParseExpr_List(langcc::SerBuf& buf) const;
        virtual void hash_ser_acc(langcc::SerBuf& buf) const;
    };
}

namespace langcc {
    void pr_debug(ostream& os, FmtFlags flags, lang::meta::Node::ParseExpr::Unfold_T x);
}

namespace lang::meta::Node::ParseExpr::Unfold {
    lang::meta::Node::ParseExpr::Unfold_T make(langcc::Int id, langcc::TokenBounds bounds, bool is_top, langcc::ParserSymId sym, langcc::ParserAttrMask attr, langcc::ParserLookahead first_k, lang::meta::Node::ParseExpr_T e);
}

namespace lang::meta::Node::ParseExpr::Unfold {
    lang::meta::Node::ParseExpr::Unfold_T make_ext(langcc::ArenaPtr arena, langcc::Int id, langcc::TokenBounds bounds, bool is_top, langcc::ParserSymId sym, langcc::ParserAttrMask attr, langcc::ParserLookahead first_k, lang::meta::Node::ParseExpr_T e);
}

namespace lang::meta::Node::ParseExpr::Unfold {
    struct _T: lang::meta::Node::ParseExpr::_T {
        void write(langcc::Ref<std::ostream> os, langcc::FmtFlags flags);
        void write(langcc::Ref<langcc::PrBufStream_T> pb);
        lang::meta::Node::ParseExpr_T e_;
        _T();
        lang::meta::Node::ParseExpr::Unfold_T with_id(langcc::Int id);
        lang::meta::Node::ParseExpr::Unfold_T with_bounds(langcc::TokenBounds bounds);
        lang::meta::Node::ParseExpr::Unfold_T with_is_top(bool is_top);
        lang::meta::Node::ParseExpr::Unfold_T with_sym(langcc::ParserSymId sym);
        lang::meta::Node::ParseExpr::Unfold_T with_attr(langcc::ParserAttrMask attr);
        lang::meta::Node::ParseExpr::Unfold_T with_first_k(langcc::ParserLookahead first_k);
        lang::meta::Node::ParseExpr::Unfold_T with_e(lang::meta::Node::ParseExpr_T e);
        void hash_ser_acc_lang_meta_Node_ParseExpr_Unfold(langcc::SerBuf& buf) const;
        virtual void hash_ser_acc(langcc::SerBuf& buf) const;
    };
}

namespace langcc {
    void pr_debug(ostream& os, FmtFlags flags, lang::meta::Node::ParseExpr::AttrReq_T x);
}

namespace lang::meta::Node::ParseExpr::AttrReq {
    lang::meta::Node::ParseExpr::AttrReq_T make(langcc::Int id, langcc::TokenBounds bounds, bool is_top, langcc::ParserSymId sym, langcc::ParserAttrMask attr, langcc::ParserLookahead first_k, lang::meta::Node::ParseExpr_T e, langcc::Vec_T<lang::meta::Node::AttrReq_T> attrs);
}

namespace lang::meta::Node::ParseExpr::AttrReq {
    lang::meta::Node::ParseExpr::AttrReq_T make_ext(langcc::ArenaPtr arena, langcc::Int id, langcc::TokenBounds bounds, bool is_top, langcc::ParserSymId sym, langcc::ParserAttrMask attr, langcc::ParserLookahead first_k, lang::meta::Node::ParseExpr_T e, langcc::Vec_T<lang::meta::Node::AttrReq_T> attrs);
}

namespace lang::meta::Node::ParseExpr::AttrReq {
    struct _T: lang::meta::Node::ParseExpr::_T {
        void write(langcc::Ref<std::ostream> os, langcc::FmtFlags flags);
        void write(langcc::Ref<langcc::PrBufStream_T> pb);
        lang::meta::Node::ParseExpr_T e_;
        langcc::Vec_T<lang::meta::Node::AttrReq_T> attrs_;
        _T();
        lang::meta::Node::ParseExpr::AttrReq_T with_id(langcc::Int id);
        lang::meta::Node::ParseExpr::AttrReq_T with_bounds(langcc::TokenBounds bounds);
        lang::meta::Node::ParseExpr::AttrReq_T with_is_top(bool is_top);
        lang::meta::Node::ParseExpr::AttrReq_T with_sym(langcc::ParserSymId sym);
        lang::meta::Node::ParseExpr::AttrReq_T with_attr(langcc::ParserAttrMask attr);
        lang::meta::Node::ParseExpr::AttrReq_T with_first_k(langcc::ParserLookahead first_k);
        lang::meta::Node::ParseExpr::AttrReq_T with_e(lang::meta::Node::ParseExpr_T e);
        lang::meta::Node::ParseExpr::AttrReq_T with_attrs(langcc::Vec_T<lang::meta::Node::AttrReq_T> attrs);
        void hash_ser_acc_lang_meta_Node_ParseExpr_AttrReq(langcc::SerBuf& buf) const;
        virtual void hash_ser_acc(langcc::SerBuf& buf) const;
    };
}

namespace langcc {
    void pr_debug(ostream& os, FmtFlags flags, lang::meta::Node::AttrReq::Base_T x);
}

namespace lang::meta::Node::AttrReq::Base {
    lang::meta::Node::AttrReq::Base_T make(langcc::Int id, langcc::TokenBounds bounds, bool is_top, langcc::ParserSymId sym, langcc::ParserAttrMask attr, langcc::ParserLookahead first_k, langcc::StrSlice k);
}

namespace lang::meta::Node::AttrReq::Base {
    lang::meta::Node::AttrReq::Base_T make_ext(langcc::ArenaPtr arena, langcc::Int id, langcc::TokenBounds bounds, bool is_top, langcc::ParserSymId sym, langcc::ParserAttrMask attr, langcc::ParserLookahead first_k, langcc::StrSlice k);
}

namespace lang::meta::Node::AttrReq::Base {
    struct _T: lang::meta::Node::AttrReq::_T {
        void write(langcc::Ref<std::ostream> os, langcc::FmtFlags flags);
        void write(langcc::Ref<langcc::PrBufStream_T> pb);
        langcc::StrSlice k_;
        _T();
        lang::meta::Node::AttrReq::Base_T with_id(langcc::Int id);
        lang::meta::Node::AttrReq::Base_T with_bounds(langcc::TokenBounds bounds);
        lang::meta::Node::AttrReq::Base_T with_is_top(bool is_top);
        lang::meta::Node::AttrReq::Base_T with_sym(langcc::ParserSymId sym);
        lang::meta::Node::AttrReq::Base_T with_attr(langcc::ParserAttrMask attr);
        lang::meta::Node::AttrReq::Base_T with_first_k(langcc::ParserLookahead first_k);
        lang::meta::Node::AttrReq::Base_T with_k(langcc::StrSlice k);
        void hash_ser_acc_lang_meta_Node_AttrReq_Base(langcc::SerBuf& buf) const;
        virtual void hash_ser_acc(langcc::SerBuf& buf) const;
    };
}

namespace langcc {
    void pr_debug(ostream& os, FmtFlags flags, lang::meta::Node::AttrReq::PrecStar_T x);
}

namespace lang::meta::Node::AttrReq::PrecStar {
    lang::meta::Node::AttrReq::PrecStar_T make(langcc::Int id, langcc::TokenBounds bounds, bool is_top, langcc::ParserSymId sym, langcc::ParserAttrMask attr, langcc::ParserLookahead first_k);
}

namespace lang::meta::Node::AttrReq::PrecStar {
    lang::meta::Node::AttrReq::PrecStar_T make_ext(langcc::ArenaPtr arena, langcc::Int id, langcc::TokenBounds bounds, bool is_top, langcc::ParserSymId sym, langcc::ParserAttrMask attr, langcc::ParserLookahead first_k);
}

namespace lang::meta::Node::AttrReq::PrecStar {
    struct _T: lang::meta::Node::AttrReq::_T {
        void write(langcc::Ref<std::ostream> os, langcc::FmtFlags flags);
        void write(langcc::Ref<langcc::PrBufStream_T> pb);
        _T();
        lang::meta::Node::AttrReq::PrecStar_T with_id(langcc::Int id);
        lang::meta::Node::AttrReq::PrecStar_T with_bounds(langcc::TokenBounds bounds);
        lang::meta::Node::AttrReq::PrecStar_T with_is_top(bool is_top);
        lang::meta::Node::AttrReq::PrecStar_T with_sym(langcc::ParserSymId sym);
        lang::meta::Node::AttrReq::PrecStar_T with_attr(langcc::ParserAttrMask attr);
        lang::meta::Node::AttrReq::PrecStar_T with_first_k(langcc::ParserLookahead first_k);
        void hash_ser_acc_lang_meta_Node_AttrReq_PrecStar(langcc::SerBuf& buf) const;
        virtual void hash_ser_acc(langcc::SerBuf& buf) const;
    };
}

namespace langcc {
    void pr_debug(ostream& os, FmtFlags flags, lang::meta::Node::ParseExprListType::List_T x);
}

namespace lang::meta::Node::ParseExprListType::List {
    lang::meta::Node::ParseExprListType::List_T make(langcc::Int id, langcc::TokenBounds bounds, bool is_top, langcc::ParserSymId sym, langcc::ParserAttrMask attr, langcc::ParserLookahead first_k);
}

namespace lang::meta::Node::ParseExprListType::List {
    lang::meta::Node::ParseExprListType::List_T make_ext(langcc::ArenaPtr arena, langcc::Int id, langcc::TokenBounds bounds, bool is_top, langcc::ParserSymId sym, langcc::ParserAttrMask attr, langcc::ParserLookahead first_k);
}

namespace lang::meta::Node::ParseExprListType::List {
    struct _T: lang::meta::Node::ParseExprListType::_T {
        void write(langcc::Ref<std::ostream> os, langcc::FmtFlags flags);
        void write(langcc::Ref<langcc::PrBufStream_T> pb);
        _T();
        lang::meta::Node::ParseExprListType::List_T with_id(langcc::Int id);
        lang::meta::Node::ParseExprListType::List_T with_bounds(langcc::TokenBounds bounds);
        lang::meta::Node::ParseExprListType::List_T with_is_top(bool is_top);
        lang::meta::Node::ParseExprListType::List_T with_sym(langcc::ParserSymId sym);
        lang::meta::Node::ParseExprListType::List_T with_attr(langcc::ParserAttrMask attr);
        lang::meta::Node::ParseExprListType::List_T with_first_k(langcc::ParserLookahead first_k);
        void hash_ser_acc_lang_meta_Node_ParseExprListType_List(langcc::SerBuf& buf) const;
        virtual void hash_ser_acc(langcc::SerBuf& buf) const;
    };
}

namespace langcc {
    void pr_debug(ostream& os, FmtFlags flags, lang::meta::Node::ParseExprListType::Block_T x);
}

namespace lang::meta::Node::ParseExprListType::Block {
    lang::meta::Node::ParseExprListType::Block_T make(langcc::Int id, langcc::TokenBounds bounds, bool is_top, langcc::ParserSymId sym, langcc::ParserAttrMask attr, langcc::ParserLookahead first_k);
}

namespace lang::meta::Node::ParseExprListType::Block {
    lang::meta::Node::ParseExprListType::Block_T make_ext(langcc::ArenaPtr arena, langcc::Int id, langcc::TokenBounds bounds, bool is_top, langcc::ParserSymId sym, langcc::ParserAttrMask attr, langcc::ParserLookahead first_k);
}

namespace lang::meta::Node::ParseExprListType::Block {
    struct _T: lang::meta::Node::ParseExprListType::_T {
        void write(langcc::Ref<std::ostream> os, langcc::FmtFlags flags);
        void write(langcc::Ref<langcc::PrBufStream_T> pb);
        _T();
        lang::meta::Node::ParseExprListType::Block_T with_id(langcc::Int id);
        lang::meta::Node::ParseExprListType::Block_T with_bounds(langcc::TokenBounds bounds);
        lang::meta::Node::ParseExprListType::Block_T with_is_top(bool is_top);
        lang::meta::Node::ParseExprListType::Block_T with_sym(langcc::ParserSymId sym);
        lang::meta::Node::ParseExprListType::Block_T with_attr(langcc::ParserAttrMask attr);
        lang::meta::Node::ParseExprListType::Block_T with_first_k(langcc::ParserLookahead first_k);
        void hash_ser_acc_lang_meta_Node_ParseExprListType_Block(langcc::SerBuf& buf) const;
        virtual void hash_ser_acc(langcc::SerBuf& buf) const;
    };
}

namespace langcc {
    void pr_debug(ostream& os, FmtFlags flags, lang::meta::Node::ParseExprListType::Block2_T x);
}

namespace lang::meta::Node::ParseExprListType::Block2 {
    lang::meta::Node::ParseExprListType::Block2_T make(langcc::Int id, langcc::TokenBounds bounds, bool is_top, langcc::ParserSymId sym, langcc::ParserAttrMask attr, langcc::ParserLookahead first_k);
}

namespace lang::meta::Node::ParseExprListType::Block2 {
    lang::meta::Node::ParseExprListType::Block2_T make_ext(langcc::ArenaPtr arena, langcc::Int id, langcc::TokenBounds bounds, bool is_top, langcc::ParserSymId sym, langcc::ParserAttrMask attr, langcc::ParserLookahead first_k);
}

namespace lang::meta::Node::ParseExprListType::Block2 {
    struct _T: lang::meta::Node::ParseExprListType::_T {
        void write(langcc::Ref<std::ostream> os, langcc::FmtFlags flags);
        void write(langcc::Ref<langcc::PrBufStream_T> pb);
        _T();
        lang::meta::Node::ParseExprListType::Block2_T with_id(langcc::Int id);
        lang::meta::Node::ParseExprListType::Block2_T with_bounds(langcc::TokenBounds bounds);
        lang::meta::Node::ParseExprListType::Block2_T with_is_top(bool is_top);
        lang::meta::Node::ParseExprListType::Block2_T with_sym(langcc::ParserSymId sym);
        lang::meta::Node::ParseExprListType::Block2_T with_attr(langcc::ParserAttrMask attr);
        lang::meta::Node::ParseExprListType::Block2_T with_first_k(langcc::ParserLookahead first_k);
        void hash_ser_acc_lang_meta_Node_ParseExprListType_Block2(langcc::SerBuf& buf) const;
        virtual void hash_ser_acc(langcc::SerBuf& buf) const;
    };
}

namespace langcc {
    void pr_debug(ostream& os, FmtFlags flags, lang::meta::Node::ParseExprListType::Top_T x);
}

namespace lang::meta::Node::ParseExprListType::Top {
    lang::meta::Node::ParseExprListType::Top_T make(langcc::Int id, langcc::TokenBounds bounds, bool is_top, langcc::ParserSymId sym, langcc::ParserAttrMask attr, langcc::ParserLookahead first_k);
}

namespace lang::meta::Node::ParseExprListType::Top {
    lang::meta::Node::ParseExprListType::Top_T make_ext(langcc::ArenaPtr arena, langcc::Int id, langcc::TokenBounds bounds, bool is_top, langcc::ParserSymId sym, langcc::ParserAttrMask attr, langcc::ParserLookahead first_k);
}

namespace lang::meta::Node::ParseExprListType::Top {
    struct _T: lang::meta::Node::ParseExprListType::_T {
        void write(langcc::Ref<std::ostream> os, langcc::FmtFlags flags);
        void write(langcc::Ref<langcc::PrBufStream_T> pb);
        _T();
        lang::meta::Node::ParseExprListType::Top_T with_id(langcc::Int id);
        lang::meta::Node::ParseExprListType::Top_T with_bounds(langcc::TokenBounds bounds);
        lang::meta::Node::ParseExprListType::Top_T with_is_top(bool is_top);
        lang::meta::Node::ParseExprListType::Top_T with_sym(langcc::ParserSymId sym);
        lang::meta::Node::ParseExprListType::Top_T with_attr(langcc::ParserAttrMask attr);
        lang::meta::Node::ParseExprListType::Top_T with_first_k(langcc::ParserLookahead first_k);
        void hash_ser_acc_lang_meta_Node_ParseExprListType_Top(langcc::SerBuf& buf) const;
        virtual void hash_ser_acc(langcc::SerBuf& buf) const;
    };
}

namespace langcc {
    void pr_debug(ostream& os, FmtFlags flags, lang::meta::Node::ParseExprListType::Top2_T x);
}

namespace lang::meta::Node::ParseExprListType::Top2 {
    lang::meta::Node::ParseExprListType::Top2_T make(langcc::Int id, langcc::TokenBounds bounds, bool is_top, langcc::ParserSymId sym, langcc::ParserAttrMask attr, langcc::ParserLookahead first_k);
}

namespace lang::meta::Node::ParseExprListType::Top2 {
    lang::meta::Node::ParseExprListType::Top2_T make_ext(langcc::ArenaPtr arena, langcc::Int id, langcc::TokenBounds bounds, bool is_top, langcc::ParserSymId sym, langcc::ParserAttrMask attr, langcc::ParserLookahead first_k);
}

namespace lang::meta::Node::ParseExprListType::Top2 {
    struct _T: lang::meta::Node::ParseExprListType::_T {
        void write(langcc::Ref<std::ostream> os, langcc::FmtFlags flags);
        void write(langcc::Ref<langcc::PrBufStream_T> pb);
        _T();
        lang::meta::Node::ParseExprListType::Top2_T with_id(langcc::Int id);
        lang::meta::Node::ParseExprListType::Top2_T with_bounds(langcc::TokenBounds bounds);
        lang::meta::Node::ParseExprListType::Top2_T with_is_top(bool is_top);
        lang::meta::Node::ParseExprListType::Top2_T with_sym(langcc::ParserSymId sym);
        lang::meta::Node::ParseExprListType::Top2_T with_attr(langcc::ParserAttrMask attr);
        lang::meta::Node::ParseExprListType::Top2_T with_first_k(langcc::ParserLookahead first_k);
        void hash_ser_acc_lang_meta_Node_ParseExprListType_Top2(langcc::SerBuf& buf) const;
        virtual void hash_ser_acc(langcc::SerBuf& buf) const;
    };
}

namespace langcc {
    void pr_debug(ostream& os, FmtFlags flags, lang::meta::Node::ParseExprListNum::Ge0_T x);
}

namespace lang::meta::Node::ParseExprListNum::Ge0 {
    lang::meta::Node::ParseExprListNum::Ge0_T make(langcc::Int id, langcc::TokenBounds bounds, bool is_top, langcc::ParserSymId sym, langcc::ParserAttrMask attr, langcc::ParserLookahead first_k);
}

namespace lang::meta::Node::ParseExprListNum::Ge0 {
    lang::meta::Node::ParseExprListNum::Ge0_T make_ext(langcc::ArenaPtr arena, langcc::Int id, langcc::TokenBounds bounds, bool is_top, langcc::ParserSymId sym, langcc::ParserAttrMask attr, langcc::ParserLookahead first_k);
}

namespace lang::meta::Node::ParseExprListNum::Ge0 {
    struct _T: lang::meta::Node::ParseExprListNum::_T {
        void write(langcc::Ref<std::ostream> os, langcc::FmtFlags flags);
        void write(langcc::Ref<langcc::PrBufStream_T> pb);
        _T();
        lang::meta::Node::ParseExprListNum::Ge0_T with_id(langcc::Int id);
        lang::meta::Node::ParseExprListNum::Ge0_T with_bounds(langcc::TokenBounds bounds);
        lang::meta::Node::ParseExprListNum::Ge0_T with_is_top(bool is_top);
        lang::meta::Node::ParseExprListNum::Ge0_T with_sym(langcc::ParserSymId sym);
        lang::meta::Node::ParseExprListNum::Ge0_T with_attr(langcc::ParserAttrMask attr);
        lang::meta::Node::ParseExprListNum::Ge0_T with_first_k(langcc::ParserLookahead first_k);
        void hash_ser_acc_lang_meta_Node_ParseExprListNum_Ge0(langcc::SerBuf& buf) const;
        virtual void hash_ser_acc(langcc::SerBuf& buf) const;
    };
}

namespace langcc {
    void pr_debug(ostream& os, FmtFlags flags, lang::meta::Node::ParseExprListNum::Ge1_T x);
}

namespace lang::meta::Node::ParseExprListNum::Ge1 {
    lang::meta::Node::ParseExprListNum::Ge1_T make(langcc::Int id, langcc::TokenBounds bounds, bool is_top, langcc::ParserSymId sym, langcc::ParserAttrMask attr, langcc::ParserLookahead first_k);
}

namespace lang::meta::Node::ParseExprListNum::Ge1 {
    lang::meta::Node::ParseExprListNum::Ge1_T make_ext(langcc::ArenaPtr arena, langcc::Int id, langcc::TokenBounds bounds, bool is_top, langcc::ParserSymId sym, langcc::ParserAttrMask attr, langcc::ParserLookahead first_k);
}

namespace lang::meta::Node::ParseExprListNum::Ge1 {
    struct _T: lang::meta::Node::ParseExprListNum::_T {
        void write(langcc::Ref<std::ostream> os, langcc::FmtFlags flags);
        void write(langcc::Ref<langcc::PrBufStream_T> pb);
        _T();
        lang::meta::Node::ParseExprListNum::Ge1_T with_id(langcc::Int id);
        lang::meta::Node::ParseExprListNum::Ge1_T with_bounds(langcc::TokenBounds bounds);
        lang::meta::Node::ParseExprListNum::Ge1_T with_is_top(bool is_top);
        lang::meta::Node::ParseExprListNum::Ge1_T with_sym(langcc::ParserSymId sym);
        lang::meta::Node::ParseExprListNum::Ge1_T with_attr(langcc::ParserAttrMask attr);
        lang::meta::Node::ParseExprListNum::Ge1_T with_first_k(langcc::ParserLookahead first_k);
        void hash_ser_acc_lang_meta_Node_ParseExprListNum_Ge1(langcc::SerBuf& buf) const;
        virtual void hash_ser_acc(langcc::SerBuf& buf) const;
    };
}

namespace langcc {
    void pr_debug(ostream& os, FmtFlags flags, lang::meta::Node::ParseExprListNum::Ge2_T x);
}

namespace lang::meta::Node::ParseExprListNum::Ge2 {
    lang::meta::Node::ParseExprListNum::Ge2_T make(langcc::Int id, langcc::TokenBounds bounds, bool is_top, langcc::ParserSymId sym, langcc::ParserAttrMask attr, langcc::ParserLookahead first_k);
}

namespace lang::meta::Node::ParseExprListNum::Ge2 {
    lang::meta::Node::ParseExprListNum::Ge2_T make_ext(langcc::ArenaPtr arena, langcc::Int id, langcc::TokenBounds bounds, bool is_top, langcc::ParserSymId sym, langcc::ParserAttrMask attr, langcc::ParserLookahead first_k);
}

namespace lang::meta::Node::ParseExprListNum::Ge2 {
    struct _T: lang::meta::Node::ParseExprListNum::_T {
        void write(langcc::Ref<std::ostream> os, langcc::FmtFlags flags);
        void write(langcc::Ref<langcc::PrBufStream_T> pb);
        _T();
        lang::meta::Node::ParseExprListNum::Ge2_T with_id(langcc::Int id);
        lang::meta::Node::ParseExprListNum::Ge2_T with_bounds(langcc::TokenBounds bounds);
        lang::meta::Node::ParseExprListNum::Ge2_T with_is_top(bool is_top);
        lang::meta::Node::ParseExprListNum::Ge2_T with_sym(langcc::ParserSymId sym);
        lang::meta::Node::ParseExprListNum::Ge2_T with_attr(langcc::ParserAttrMask attr);
        lang::meta::Node::ParseExprListNum::Ge2_T with_first_k(langcc::ParserLookahead first_k);
        void hash_ser_acc_lang_meta_Node_ParseExprListNum_Ge2(langcc::SerBuf& buf) const;
        virtual void hash_ser_acc(langcc::SerBuf& buf) const;
    };
}

namespace langcc {
    void pr_debug(ostream& os, FmtFlags flags, lang::meta::Node::TokenDecl::op::DEF_T x);
}

namespace lang::meta::Node::TokenDecl::op::DEF {
    lang::meta::Node::TokenDecl::op::DEF_T make(langcc::Int id, langcc::TokenBounds bounds, bool is_top, langcc::ParserSymId sym, langcc::ParserAttrMask attr, langcc::ParserLookahead first_k);
}

namespace lang::meta::Node::TokenDecl::op::DEF {
    lang::meta::Node::TokenDecl::op::DEF_T make_ext(langcc::ArenaPtr arena, langcc::Int id, langcc::TokenBounds bounds, bool is_top, langcc::ParserSymId sym, langcc::ParserAttrMask attr, langcc::ParserLookahead first_k);
}

namespace lang::meta::Node::TokenDecl::op::DEF {
    struct _T: lang::meta::Node::TokenDecl::op::_T {
        void write(langcc::Ref<std::ostream> os, langcc::FmtFlags flags);
        void write(langcc::Ref<langcc::PrBufStream_T> pb);
        _T();
        lang::meta::Node::TokenDecl::op::DEF_T with_id(langcc::Int id);
        lang::meta::Node::TokenDecl::op::DEF_T with_bounds(langcc::TokenBounds bounds);
        lang::meta::Node::TokenDecl::op::DEF_T with_is_top(bool is_top);
        lang::meta::Node::TokenDecl::op::DEF_T with_sym(langcc::ParserSymId sym);
        lang::meta::Node::TokenDecl::op::DEF_T with_attr(langcc::ParserAttrMask attr);
        lang::meta::Node::TokenDecl::op::DEF_T with_first_k(langcc::ParserLookahead first_k);
        void hash_ser_acc_lang_meta_Node_TokenDecl_op_DEF(langcc::SerBuf& buf) const;
        virtual void hash_ser_acc(langcc::SerBuf& buf) const;
    };
}

namespace langcc {
    void pr_debug(ostream& os, FmtFlags flags, lang::meta::Node::TokenDecl::op::DEF_ALIAS_T x);
}

namespace lang::meta::Node::TokenDecl::op::DEF_ALIAS {
    lang::meta::Node::TokenDecl::op::DEF_ALIAS_T make(langcc::Int id, langcc::TokenBounds bounds, bool is_top, langcc::ParserSymId sym, langcc::ParserAttrMask attr, langcc::ParserLookahead first_k);
}

namespace lang::meta::Node::TokenDecl::op::DEF_ALIAS {
    lang::meta::Node::TokenDecl::op::DEF_ALIAS_T make_ext(langcc::ArenaPtr arena, langcc::Int id, langcc::TokenBounds bounds, bool is_top, langcc::ParserSymId sym, langcc::ParserAttrMask attr, langcc::ParserLookahead first_k);
}

namespace lang::meta::Node::TokenDecl::op::DEF_ALIAS {
    struct _T: lang::meta::Node::TokenDecl::op::_T {
        void write(langcc::Ref<std::ostream> os, langcc::FmtFlags flags);
        void write(langcc::Ref<langcc::PrBufStream_T> pb);
        _T();
        lang::meta::Node::TokenDecl::op::DEF_ALIAS_T with_id(langcc::Int id);
        lang::meta::Node::TokenDecl::op::DEF_ALIAS_T with_bounds(langcc::TokenBounds bounds);
        lang::meta::Node::TokenDecl::op::DEF_ALIAS_T with_is_top(bool is_top);
        lang::meta::Node::TokenDecl::op::DEF_ALIAS_T with_sym(langcc::ParserSymId sym);
        lang::meta::Node::TokenDecl::op::DEF_ALIAS_T with_attr(langcc::ParserAttrMask attr);
        lang::meta::Node::TokenDecl::op::DEF_ALIAS_T with_first_k(langcc::ParserLookahead first_k);
        void hash_ser_acc_lang_meta_Node_TokenDecl_op_DEF_ALIAS(langcc::SerBuf& buf) const;
        virtual void hash_ser_acc(langcc::SerBuf& buf) const;
    };
}

namespace langcc {
    void pr_debug(ostream& os, FmtFlags flags, lang::meta::Node::LexerDecl::Mode::ws_sig__T x);
}

namespace lang::meta::Node::LexerDecl::Mode::ws_sig_ {
    lang::meta::Node::LexerDecl::Mode::ws_sig__T make(langcc::Int id, langcc::TokenBounds bounds, bool is_top, langcc::ParserSymId sym, langcc::ParserAttrMask attr, langcc::ParserLookahead first_k, langcc::Option_T<lang::meta::Node::LexerDecl::Mode::ws_sig_::spec_T> spec);
}

namespace lang::meta::Node::LexerDecl::Mode::ws_sig_ {
    lang::meta::Node::LexerDecl::Mode::ws_sig__T make_ext(langcc::ArenaPtr arena, langcc::Int id, langcc::TokenBounds bounds, bool is_top, langcc::ParserSymId sym, langcc::ParserAttrMask attr, langcc::ParserLookahead first_k, langcc::Option_T<lang::meta::Node::LexerDecl::Mode::ws_sig_::spec_T> spec);
}

namespace lang::meta::Node::LexerDecl::Mode::ws_sig_ {
    struct _T: lang::meta::Node::_T {
        void write(langcc::Ref<std::ostream> os, langcc::FmtFlags flags);
        void write(langcc::Ref<langcc::PrBufStream_T> pb);
        langcc::Option_T<lang::meta::Node::LexerDecl::Mode::ws_sig_::spec_T> spec_;
        _T();
        lang::meta::Node::LexerDecl::Mode::ws_sig__T with_id(langcc::Int id);
        lang::meta::Node::LexerDecl::Mode::ws_sig__T with_bounds(langcc::TokenBounds bounds);
        lang::meta::Node::LexerDecl::Mode::ws_sig__T with_is_top(bool is_top);
        lang::meta::Node::LexerDecl::Mode::ws_sig__T with_sym(langcc::ParserSymId sym);
        lang::meta::Node::LexerDecl::Mode::ws_sig__T with_attr(langcc::ParserAttrMask attr);
        lang::meta::Node::LexerDecl::Mode::ws_sig__T with_first_k(langcc::ParserLookahead first_k);
        lang::meta::Node::LexerDecl::Mode::ws_sig__T with_spec(langcc::Option_T<lang::meta::Node::LexerDecl::Mode::ws_sig_::spec_T> spec);
        void hash_ser_acc_lang_meta_Node_LexerDecl_Mode_ws_sig_(langcc::SerBuf& buf) const;
        virtual void hash_ser_acc(langcc::SerBuf& buf) const;
    };
}

namespace langcc {
    void pr_debug(ostream& os, FmtFlags flags, lang::meta::Node::ParserDecl::Rule::op_T x);
}

namespace lang::meta::Node::ParserDecl::Rule::op {
    enum struct _W {
        DEF,
        DEF_ALIAS,
    };
}

namespace lang::meta::Node::ParserDecl::Rule::op {
    struct _T: lang::meta::Node::_T {
        void write(langcc::Ref<std::ostream> os, langcc::FmtFlags flags);
        void write(langcc::Ref<langcc::PrBufStream_T> pb);
        lang::meta::Node::ParserDecl::Rule::op::_W w_;
        virtual ~_T();
        _T(lang::meta::Node::ParserDecl::Rule::op::_W w);
        bool is_DEF();
        bool is_DEF_ALIAS();
        lang::meta::Node::ParserDecl::Rule::op::DEF_T as_DEF();
        lang::meta::Node::ParserDecl::Rule::op::DEF_ALIAS_T as_DEF_ALIAS();
        langcc::Ptr<lang::meta::Node::ParserDecl::Rule::op::DEF::_T> as_DEF_unchecked();
        langcc::Ptr<lang::meta::Node::ParserDecl::Rule::op::DEF_ALIAS::_T> as_DEF_ALIAS_unchecked();
        void match(std::function<void(lang::meta::Node::ParserDecl::Rule::op::DEF_T)> f_DEF, std::function<void(lang::meta::Node::ParserDecl::Rule::op::DEF_ALIAS_T)> f_DEF_ALIAS);
        template<typename RetT> RetT match_expr(std::function<RetT(lang::meta::Node::ParserDecl::Rule::op::DEF_T)> f_DEF, std::function<RetT(lang::meta::Node::ParserDecl::Rule::op::DEF_ALIAS_T)> f_DEF_ALIAS);
        void hash_ser_acc_lang_meta_Node_ParserDecl_Rule_op(langcc::SerBuf& buf) const;
        virtual void hash_ser_acc(langcc::SerBuf& buf) const = 0;
    };
}

template<typename RetT> RetT lang::meta::Node::ParserDecl::Rule::op::_T::match_expr(std::function<RetT(lang::meta::Node::ParserDecl::Rule::op::DEF_T)> f_DEF, std::function<RetT(lang::meta::Node::ParserDecl::Rule::op::DEF_ALIAS_T)> f_DEF_ALIAS) {
    switch (this->w_) {
        case lang::meta::Node::ParserDecl::Rule::op::_W::DEF: {
            return f_DEF(this->as_DEF());
            break;
        }
        case lang::meta::Node::ParserDecl::Rule::op::_W::DEF_ALIAS: {
            return f_DEF_ALIAS(this->as_DEF_ALIAS());
            break;
        }
        default: {
            langcc::AX();
        }
    }
}

namespace langcc {
    void pr_debug(ostream& os, FmtFlags flags, lang::meta::Node::ParseExpr::List::end_delim_T x);
}

namespace lang::meta::Node::ParseExpr::List::end_delim {
    enum struct _W {
        NONE,
        OPTIONAL,
        SOME,
    };
}

namespace lang::meta::Node::ParseExpr::List::end_delim {
    struct _T: lang::meta::Node::_T {
        void write(langcc::Ref<std::ostream> os, langcc::FmtFlags flags);
        void write(langcc::Ref<langcc::PrBufStream_T> pb);
        lang::meta::Node::ParseExpr::List::end_delim::_W w_;
        virtual ~_T();
        _T(lang::meta::Node::ParseExpr::List::end_delim::_W w);
        bool is_NONE();
        bool is_OPTIONAL();
        bool is_SOME();
        lang::meta::Node::ParseExpr::List::end_delim::NONE_T as_NONE();
        lang::meta::Node::ParseExpr::List::end_delim::OPTIONAL_T as_OPTIONAL();
        lang::meta::Node::ParseExpr::List::end_delim::SOME_T as_SOME();
        langcc::Ptr<lang::meta::Node::ParseExpr::List::end_delim::NONE::_T> as_NONE_unchecked();
        langcc::Ptr<lang::meta::Node::ParseExpr::List::end_delim::OPTIONAL::_T> as_OPTIONAL_unchecked();
        langcc::Ptr<lang::meta::Node::ParseExpr::List::end_delim::SOME::_T> as_SOME_unchecked();
        void match(std::function<void(lang::meta::Node::ParseExpr::List::end_delim::NONE_T)> f_NONE, std::function<void(lang::meta::Node::ParseExpr::List::end_delim::OPTIONAL_T)> f_OPTIONAL, std::function<void(lang::meta::Node::ParseExpr::List::end_delim::SOME_T)> f_SOME);
        template<typename RetT> RetT match_expr(std::function<RetT(lang::meta::Node::ParseExpr::List::end_delim::NONE_T)> f_NONE, std::function<RetT(lang::meta::Node::ParseExpr::List::end_delim::OPTIONAL_T)> f_OPTIONAL, std::function<RetT(lang::meta::Node::ParseExpr::List::end_delim::SOME_T)> f_SOME);
        void hash_ser_acc_lang_meta_Node_ParseExpr_List_end_delim(langcc::SerBuf& buf) const;
        virtual void hash_ser_acc(langcc::SerBuf& buf) const = 0;
    };
}

template<typename RetT> RetT lang::meta::Node::ParseExpr::List::end_delim::_T::match_expr(std::function<RetT(lang::meta::Node::ParseExpr::List::end_delim::NONE_T)> f_NONE, std::function<RetT(lang::meta::Node::ParseExpr::List::end_delim::OPTIONAL_T)> f_OPTIONAL, std::function<RetT(lang::meta::Node::ParseExpr::List::end_delim::SOME_T)> f_SOME) {
    switch (this->w_) {
        case lang::meta::Node::ParseExpr::List::end_delim::_W::NONE: {
            return f_NONE(this->as_NONE());
            break;
        }
        case lang::meta::Node::ParseExpr::List::end_delim::_W::OPTIONAL: {
            return f_OPTIONAL(this->as_OPTIONAL());
            break;
        }
        case lang::meta::Node::ParseExpr::List::end_delim::_W::SOME: {
            return f_SOME(this->as_SOME());
            break;
        }
        default: {
            langcc::AX();
        }
    }
}

namespace langcc {
    void pr_debug(ostream& os, FmtFlags flags, lang::meta::Node::LexerDecl::Mode::ws_sig_::spec_T x);
}

namespace lang::meta::Node::LexerDecl::Mode::ws_sig_::spec {
    lang::meta::Node::LexerDecl::Mode::ws_sig_::spec_T make(langcc::Int id, langcc::TokenBounds bounds, bool is_top, langcc::ParserSymId sym, langcc::ParserAttrMask attr, langcc::ParserLookahead first_k, langcc::Option_T<langcc::StrSlice> lc, langcc::Vec_T<langcc::StrSlice> delims);
}

namespace lang::meta::Node::LexerDecl::Mode::ws_sig_::spec {
    lang::meta::Node::LexerDecl::Mode::ws_sig_::spec_T make_ext(langcc::ArenaPtr arena, langcc::Int id, langcc::TokenBounds bounds, bool is_top, langcc::ParserSymId sym, langcc::ParserAttrMask attr, langcc::ParserLookahead first_k, langcc::Option_T<langcc::StrSlice> lc, langcc::Vec_T<langcc::StrSlice> delims);
}

namespace lang::meta::Node::LexerDecl::Mode::ws_sig_::spec {
    struct _T: lang::meta::Node::_T {
        void write(langcc::Ref<std::ostream> os, langcc::FmtFlags flags);
        void write(langcc::Ref<langcc::PrBufStream_T> pb);
        langcc::Option_T<langcc::StrSlice> lc_;
        langcc::Vec_T<langcc::StrSlice> delims_;
        _T();
        lang::meta::Node::LexerDecl::Mode::ws_sig_::spec_T with_id(langcc::Int id);
        lang::meta::Node::LexerDecl::Mode::ws_sig_::spec_T with_bounds(langcc::TokenBounds bounds);
        lang::meta::Node::LexerDecl::Mode::ws_sig_::spec_T with_is_top(bool is_top);
        lang::meta::Node::LexerDecl::Mode::ws_sig_::spec_T with_sym(langcc::ParserSymId sym);
        lang::meta::Node::LexerDecl::Mode::ws_sig_::spec_T with_attr(langcc::ParserAttrMask attr);
        lang::meta::Node::LexerDecl::Mode::ws_sig_::spec_T with_first_k(langcc::ParserLookahead first_k);
        lang::meta::Node::LexerDecl::Mode::ws_sig_::spec_T with_lc(langcc::Option_T<langcc::StrSlice> lc);
        lang::meta::Node::LexerDecl::Mode::ws_sig_::spec_T with_delims(langcc::Vec_T<langcc::StrSlice> delims);
        void hash_ser_acc_lang_meta_Node_LexerDecl_Mode_ws_sig__spec(langcc::SerBuf& buf) const;
        virtual void hash_ser_acc(langcc::SerBuf& buf) const;
    };
}

namespace langcc {
    void pr_debug(ostream& os, FmtFlags flags, lang::meta::Node::ParserDecl::Rule::op::DEF_T x);
}

namespace lang::meta::Node::ParserDecl::Rule::op::DEF {
    lang::meta::Node::ParserDecl::Rule::op::DEF_T make(langcc::Int id, langcc::TokenBounds bounds, bool is_top, langcc::ParserSymId sym, langcc::ParserAttrMask attr, langcc::ParserLookahead first_k);
}

namespace lang::meta::Node::ParserDecl::Rule::op::DEF {
    lang::meta::Node::ParserDecl::Rule::op::DEF_T make_ext(langcc::ArenaPtr arena, langcc::Int id, langcc::TokenBounds bounds, bool is_top, langcc::ParserSymId sym, langcc::ParserAttrMask attr, langcc::ParserLookahead first_k);
}

namespace lang::meta::Node::ParserDecl::Rule::op::DEF {
    struct _T: lang::meta::Node::ParserDecl::Rule::op::_T {
        void write(langcc::Ref<std::ostream> os, langcc::FmtFlags flags);
        void write(langcc::Ref<langcc::PrBufStream_T> pb);
        _T();
        lang::meta::Node::ParserDecl::Rule::op::DEF_T with_id(langcc::Int id);
        lang::meta::Node::ParserDecl::Rule::op::DEF_T with_bounds(langcc::TokenBounds bounds);
        lang::meta::Node::ParserDecl::Rule::op::DEF_T with_is_top(bool is_top);
        lang::meta::Node::ParserDecl::Rule::op::DEF_T with_sym(langcc::ParserSymId sym);
        lang::meta::Node::ParserDecl::Rule::op::DEF_T with_attr(langcc::ParserAttrMask attr);
        lang::meta::Node::ParserDecl::Rule::op::DEF_T with_first_k(langcc::ParserLookahead first_k);
        void hash_ser_acc_lang_meta_Node_ParserDecl_Rule_op_DEF(langcc::SerBuf& buf) const;
        virtual void hash_ser_acc(langcc::SerBuf& buf) const;
    };
}

namespace langcc {
    void pr_debug(ostream& os, FmtFlags flags, lang::meta::Node::ParserDecl::Rule::op::DEF_ALIAS_T x);
}

namespace lang::meta::Node::ParserDecl::Rule::op::DEF_ALIAS {
    lang::meta::Node::ParserDecl::Rule::op::DEF_ALIAS_T make(langcc::Int id, langcc::TokenBounds bounds, bool is_top, langcc::ParserSymId sym, langcc::ParserAttrMask attr, langcc::ParserLookahead first_k);
}

namespace lang::meta::Node::ParserDecl::Rule::op::DEF_ALIAS {
    lang::meta::Node::ParserDecl::Rule::op::DEF_ALIAS_T make_ext(langcc::ArenaPtr arena, langcc::Int id, langcc::TokenBounds bounds, bool is_top, langcc::ParserSymId sym, langcc::ParserAttrMask attr, langcc::ParserLookahead first_k);
}

namespace lang::meta::Node::ParserDecl::Rule::op::DEF_ALIAS {
    struct _T: lang::meta::Node::ParserDecl::Rule::op::_T {
        void write(langcc::Ref<std::ostream> os, langcc::FmtFlags flags);
        void write(langcc::Ref<langcc::PrBufStream_T> pb);
        _T();
        lang::meta::Node::ParserDecl::Rule::op::DEF_ALIAS_T with_id(langcc::Int id);
        lang::meta::Node::ParserDecl::Rule::op::DEF_ALIAS_T with_bounds(langcc::TokenBounds bounds);
        lang::meta::Node::ParserDecl::Rule::op::DEF_ALIAS_T with_is_top(bool is_top);
        lang::meta::Node::ParserDecl::Rule::op::DEF_ALIAS_T with_sym(langcc::ParserSymId sym);
        lang::meta::Node::ParserDecl::Rule::op::DEF_ALIAS_T with_attr(langcc::ParserAttrMask attr);
        lang::meta::Node::ParserDecl::Rule::op::DEF_ALIAS_T with_first_k(langcc::ParserLookahead first_k);
        void hash_ser_acc_lang_meta_Node_ParserDecl_Rule_op_DEF_ALIAS(langcc::SerBuf& buf) const;
        virtual void hash_ser_acc(langcc::SerBuf& buf) const;
    };
}

namespace langcc {
    void pr_debug(ostream& os, FmtFlags flags, lang::meta::Node::ParseExpr::List::end_delim::NONE_T x);
}

namespace lang::meta::Node::ParseExpr::List::end_delim::NONE {
    lang::meta::Node::ParseExpr::List::end_delim::NONE_T make(langcc::Int id, langcc::TokenBounds bounds, bool is_top, langcc::ParserSymId sym, langcc::ParserAttrMask attr, langcc::ParserLookahead first_k);
}

namespace lang::meta::Node::ParseExpr::List::end_delim::NONE {
    lang::meta::Node::ParseExpr::List::end_delim::NONE_T make_ext(langcc::ArenaPtr arena, langcc::Int id, langcc::TokenBounds bounds, bool is_top, langcc::ParserSymId sym, langcc::ParserAttrMask attr, langcc::ParserLookahead first_k);
}

namespace lang::meta::Node::ParseExpr::List::end_delim::NONE {
    struct _T: lang::meta::Node::ParseExpr::List::end_delim::_T {
        void write(langcc::Ref<std::ostream> os, langcc::FmtFlags flags);
        void write(langcc::Ref<langcc::PrBufStream_T> pb);
        _T();
        lang::meta::Node::ParseExpr::List::end_delim::NONE_T with_id(langcc::Int id);
        lang::meta::Node::ParseExpr::List::end_delim::NONE_T with_bounds(langcc::TokenBounds bounds);
        lang::meta::Node::ParseExpr::List::end_delim::NONE_T with_is_top(bool is_top);
        lang::meta::Node::ParseExpr::List::end_delim::NONE_T with_sym(langcc::ParserSymId sym);
        lang::meta::Node::ParseExpr::List::end_delim::NONE_T with_attr(langcc::ParserAttrMask attr);
        lang::meta::Node::ParseExpr::List::end_delim::NONE_T with_first_k(langcc::ParserLookahead first_k);
        void hash_ser_acc_lang_meta_Node_ParseExpr_List_end_delim_NONE(langcc::SerBuf& buf) const;
        virtual void hash_ser_acc(langcc::SerBuf& buf) const;
    };
}

namespace langcc {
    void pr_debug(ostream& os, FmtFlags flags, lang::meta::Node::ParseExpr::List::end_delim::OPTIONAL_T x);
}

namespace lang::meta::Node::ParseExpr::List::end_delim::OPTIONAL {
    lang::meta::Node::ParseExpr::List::end_delim::OPTIONAL_T make(langcc::Int id, langcc::TokenBounds bounds, bool is_top, langcc::ParserSymId sym, langcc::ParserAttrMask attr, langcc::ParserLookahead first_k);
}

namespace lang::meta::Node::ParseExpr::List::end_delim::OPTIONAL {
    lang::meta::Node::ParseExpr::List::end_delim::OPTIONAL_T make_ext(langcc::ArenaPtr arena, langcc::Int id, langcc::TokenBounds bounds, bool is_top, langcc::ParserSymId sym, langcc::ParserAttrMask attr, langcc::ParserLookahead first_k);
}

namespace lang::meta::Node::ParseExpr::List::end_delim::OPTIONAL {
    struct _T: lang::meta::Node::ParseExpr::List::end_delim::_T {
        void write(langcc::Ref<std::ostream> os, langcc::FmtFlags flags);
        void write(langcc::Ref<langcc::PrBufStream_T> pb);
        _T();
        lang::meta::Node::ParseExpr::List::end_delim::OPTIONAL_T with_id(langcc::Int id);
        lang::meta::Node::ParseExpr::List::end_delim::OPTIONAL_T with_bounds(langcc::TokenBounds bounds);
        lang::meta::Node::ParseExpr::List::end_delim::OPTIONAL_T with_is_top(bool is_top);
        lang::meta::Node::ParseExpr::List::end_delim::OPTIONAL_T with_sym(langcc::ParserSymId sym);
        lang::meta::Node::ParseExpr::List::end_delim::OPTIONAL_T with_attr(langcc::ParserAttrMask attr);
        lang::meta::Node::ParseExpr::List::end_delim::OPTIONAL_T with_first_k(langcc::ParserLookahead first_k);
        void hash_ser_acc_lang_meta_Node_ParseExpr_List_end_delim_OPTIONAL(langcc::SerBuf& buf) const;
        virtual void hash_ser_acc(langcc::SerBuf& buf) const;
    };
}

namespace langcc {
    void pr_debug(ostream& os, FmtFlags flags, lang::meta::Node::ParseExpr::List::end_delim::SOME_T x);
}

namespace lang::meta::Node::ParseExpr::List::end_delim::SOME {
    lang::meta::Node::ParseExpr::List::end_delim::SOME_T make(langcc::Int id, langcc::TokenBounds bounds, bool is_top, langcc::ParserSymId sym, langcc::ParserAttrMask attr, langcc::ParserLookahead first_k);
}

namespace lang::meta::Node::ParseExpr::List::end_delim::SOME {
    lang::meta::Node::ParseExpr::List::end_delim::SOME_T make_ext(langcc::ArenaPtr arena, langcc::Int id, langcc::TokenBounds bounds, bool is_top, langcc::ParserSymId sym, langcc::ParserAttrMask attr, langcc::ParserLookahead first_k);
}

namespace lang::meta::Node::ParseExpr::List::end_delim::SOME {
    struct _T: lang::meta::Node::ParseExpr::List::end_delim::_T {
        void write(langcc::Ref<std::ostream> os, langcc::FmtFlags flags);
        void write(langcc::Ref<langcc::PrBufStream_T> pb);
        _T();
        lang::meta::Node::ParseExpr::List::end_delim::SOME_T with_id(langcc::Int id);
        lang::meta::Node::ParseExpr::List::end_delim::SOME_T with_bounds(langcc::TokenBounds bounds);
        lang::meta::Node::ParseExpr::List::end_delim::SOME_T with_is_top(bool is_top);
        lang::meta::Node::ParseExpr::List::end_delim::SOME_T with_sym(langcc::ParserSymId sym);
        lang::meta::Node::ParseExpr::List::end_delim::SOME_T with_attr(langcc::ParserAttrMask attr);
        lang::meta::Node::ParseExpr::List::end_delim::SOME_T with_first_k(langcc::ParserLookahead first_k);
        void hash_ser_acc_lang_meta_Node_ParseExpr_List_end_delim_SOME(langcc::SerBuf& buf) const;
        virtual void hash_ser_acc(langcc::SerBuf& buf) const;
    };
}

void visit_lang_meta_Node(lang::meta::Node::Decl::Include_T x, std::function<void(lang::meta::Node_T)> f);

void visit_lang_meta_Node(lang::meta::Node::Decl::IncludePost_T x, std::function<void(lang::meta::Node_T)> f);

void visit_lang_meta_Node(lang::meta::Node::Decl_T x, std::function<void(lang::meta::Node_T)> f);

void visit_lang_meta_Node(lang::meta::Node::TokenDecl::op::DEF_T x, std::function<void(lang::meta::Node_T)> f);

void visit_lang_meta_Node(lang::meta::Node::TokenDecl::op::DEF_ALIAS_T x, std::function<void(lang::meta::Node_T)> f);

void visit_lang_meta_Node(lang::meta::Node::TokenDecl::op_T x, std::function<void(lang::meta::Node_T)> f);

void visit_lang_meta_Node(lang::meta::Node::Id_T x, std::function<void(lang::meta::Node_T)> f);

void visit_lang_meta_Node(lang::meta::Node::ParseExpr::Id_T x, std::function<void(lang::meta::Node_T)> f);

void visit_lang_meta_Node(lang::meta::Node::ParseExpr::Eof_T x, std::function<void(lang::meta::Node_T)> f);

void visit_lang_meta_Node(lang::meta::Node::ParseExpr::False_T x, std::function<void(lang::meta::Node_T)> f);

void visit_lang_meta_Node(lang::meta::Node::ParseExpr::Eps_T x, std::function<void(lang::meta::Node_T)> f);

void visit_lang_meta_Node(lang::meta::Node::ParseExpr::Indent_T x, std::function<void(lang::meta::Node_T)> f);

void visit_lang_meta_Node(lang::meta::Node::ParseExpr::Dedent_T x, std::function<void(lang::meta::Node_T)> f);

void visit_lang_meta_Node(lang::meta::Node::ParseExpr::Newline_T x, std::function<void(lang::meta::Node_T)> f);

void visit_lang_meta_Node(lang::meta::Node::ParseExpr::UnicodeAny_T x, std::function<void(lang::meta::Node_T)> f);

void visit_lang_meta_Node(lang::meta::Node::ParseExpr::AsciiBaseAny_T x, std::function<void(lang::meta::Node_T)> f);

void visit_lang_meta_Node(lang::meta::Node::ParseExpr::Alt_T x, std::function<void(lang::meta::Node_T)> f);

void visit_lang_meta_Node(lang::meta::Node::ParseExpr::AltExplicit_T x, std::function<void(lang::meta::Node_T)> f);

void visit_lang_meta_Node(lang::meta::Node::ParseExpr::Minus_T x, std::function<void(lang::meta::Node_T)> f);

void visit_lang_meta_Node(lang::meta::Node::ParseExpr::Concat_T x, std::function<void(lang::meta::Node_T)> f);

void visit_lang_meta_Node(lang::meta::Node::ParseExpr::Optional_T x, std::function<void(lang::meta::Node_T)> f);

void visit_lang_meta_Node(lang::meta::Node::ParseExpr::Rep_T x, std::function<void(lang::meta::Node_T)> f);

void visit_lang_meta_Node(lang::meta::Node::ParseExpr::RepNonzero_T x, std::function<void(lang::meta::Node_T)> f);

void visit_lang_meta_Node(lang::meta::Node::ParseExpr::RepCount_T x, std::function<void(lang::meta::Node_T)> f);

void visit_lang_meta_Node(lang::meta::Node::ParseExpr::CharRange_T x, std::function<void(lang::meta::Node_T)> f);

void visit_lang_meta_Node(lang::meta::Node::ParseExpr::StrLit_T x, std::function<void(lang::meta::Node_T)> f);

void visit_lang_meta_Node(lang::meta::Node::ParseExpr::Underscore_T x, std::function<void(lang::meta::Node_T)> f);

void visit_lang_meta_Node(lang::meta::Node::ParseExpr::Pass_T x, std::function<void(lang::meta::Node_T)> f);

void visit_lang_meta_Node(lang::meta::Node::ParseExpr::Paren_T x, std::function<void(lang::meta::Node_T)> f);

void visit_lang_meta_Node(lang::meta::Node::ParseExpr::Name_T x, std::function<void(lang::meta::Node_T)> f);

void visit_lang_meta_Node(lang::meta::Node::ParseExprListType::List_T x, std::function<void(lang::meta::Node_T)> f);

void visit_lang_meta_Node(lang::meta::Node::ParseExprListType::Block_T x, std::function<void(lang::meta::Node_T)> f);

void visit_lang_meta_Node(lang::meta::Node::ParseExprListType::Block2_T x, std::function<void(lang::meta::Node_T)> f);

void visit_lang_meta_Node(lang::meta::Node::ParseExprListType::Top_T x, std::function<void(lang::meta::Node_T)> f);

void visit_lang_meta_Node(lang::meta::Node::ParseExprListType::Top2_T x, std::function<void(lang::meta::Node_T)> f);

void visit_lang_meta_Node(lang::meta::Node::ParseExprListType_T x, std::function<void(lang::meta::Node_T)> f);

void visit_lang_meta_Node(lang::meta::Node::ParseExprListNum::Ge0_T x, std::function<void(lang::meta::Node_T)> f);

void visit_lang_meta_Node(lang::meta::Node::ParseExprListNum::Ge1_T x, std::function<void(lang::meta::Node_T)> f);

void visit_lang_meta_Node(lang::meta::Node::ParseExprListNum::Ge2_T x, std::function<void(lang::meta::Node_T)> f);

void visit_lang_meta_Node(lang::meta::Node::ParseExprListNum_T x, std::function<void(lang::meta::Node_T)> f);

void visit_lang_meta_Node(lang::meta::Node::ParseExpr::List::end_delim::NONE_T x, std::function<void(lang::meta::Node_T)> f);

void visit_lang_meta_Node(lang::meta::Node::ParseExpr::List::end_delim::OPTIONAL_T x, std::function<void(lang::meta::Node_T)> f);

void visit_lang_meta_Node(lang::meta::Node::ParseExpr::List::end_delim::SOME_T x, std::function<void(lang::meta::Node_T)> f);

void visit_lang_meta_Node(lang::meta::Node::ParseExpr::List::end_delim_T x, std::function<void(lang::meta::Node_T)> f);

void visit_lang_meta_Node(lang::meta::Node::ParseExpr::List_T x, std::function<void(lang::meta::Node_T)> f);

void visit_lang_meta_Node(lang::meta::Node::ParseExpr::Unfold_T x, std::function<void(lang::meta::Node_T)> f);

void visit_lang_meta_Node(lang::meta::Node::AttrReq::Base_T x, std::function<void(lang::meta::Node_T)> f);

void visit_lang_meta_Node(lang::meta::Node::AttrReq::PrecStar_T x, std::function<void(lang::meta::Node_T)> f);

void visit_lang_meta_Node(lang::meta::Node::AttrReq_T x, std::function<void(lang::meta::Node_T)> f);

void visit_lang_meta_Node(lang::meta::Node::ParseExpr::AttrReq_T x, std::function<void(lang::meta::Node_T)> f);

void visit_lang_meta_Node(lang::meta::Node::ParseExpr_T x, std::function<void(lang::meta::Node_T)> f);

void visit_lang_meta_Node(lang::meta::Node::TokenDecl_T x, std::function<void(lang::meta::Node_T)> f);

void visit_lang_meta_Node(lang::meta::Node::Stanza::Tokens_T x, std::function<void(lang::meta::Node_T)> f);

void visit_lang_meta_Node(lang::meta::Node::LexerDecl::Main_T x, std::function<void(lang::meta::Node_T)> f);

void visit_lang_meta_Node(lang::meta::Node::LexerDecl::Mode::ws_sig_::spec_T x, std::function<void(lang::meta::Node_T)> f);

void visit_lang_meta_Node(lang::meta::Node::LexerDecl::Mode::ws_sig__T x, std::function<void(lang::meta::Node_T)> f);

void visit_lang_meta_Node(lang::meta::Node::LexerInstr::Emit_T x, std::function<void(lang::meta::Node_T)> f);

void visit_lang_meta_Node(lang::meta::Node::LexerInstr::Pass_T x, std::function<void(lang::meta::Node_T)> f);

void visit_lang_meta_Node(lang::meta::Node::LexerInstr::Push_T x, std::function<void(lang::meta::Node_T)> f);

void visit_lang_meta_Node(lang::meta::Node::LexerInstr::Pop_T x, std::function<void(lang::meta::Node_T)> f);

void visit_lang_meta_Node(lang::meta::Node::LexerInstr::PopExtract_T x, std::function<void(lang::meta::Node_T)> f);

void visit_lang_meta_Node(lang::meta::Node::LexerInstr::PopEmit_T x, std::function<void(lang::meta::Node_T)> f);

void visit_lang_meta_Node(lang::meta::Node::LexerInstr::MatchHistory_T x, std::function<void(lang::meta::Node_T)> f);

void visit_lang_meta_Node(lang::meta::Node::LexerInstr_T x, std::function<void(lang::meta::Node_T)> f);

void visit_lang_meta_Node(lang::meta::Node::LexerModeCase_T x, std::function<void(lang::meta::Node_T)> f);

void visit_lang_meta_Node(lang::meta::Node::LexerDecl::Mode_T x, std::function<void(lang::meta::Node_T)> f);

void visit_lang_meta_Node(lang::meta::Node::LexerDecl_T x, std::function<void(lang::meta::Node_T)> f);

void visit_lang_meta_Node(lang::meta::Node::Stanza::Lexer_T x, std::function<void(lang::meta::Node_T)> f);

void visit_lang_meta_Node(lang::meta::Node::ParserDecl::Main_T x, std::function<void(lang::meta::Node_T)> f);

void visit_lang_meta_Node(lang::meta::Node::ParserProp::NameStrict_T x, std::function<void(lang::meta::Node_T)> f);

void visit_lang_meta_Node(lang::meta::Node::ParserProp::AllowUnreach_T x, std::function<void(lang::meta::Node_T)> f);

void visit_lang_meta_Node(lang::meta::Node::ParserProp::ASTExtraData_T x, std::function<void(lang::meta::Node_T)> f);

void visit_lang_meta_Node(lang::meta::Node::ParserProp::LRSpec_T x, std::function<void(lang::meta::Node_T)> f);

void visit_lang_meta_Node(lang::meta::Node::ParserProp::Err__T x, std::function<void(lang::meta::Node_T)> f);

void visit_lang_meta_Node(lang::meta::Node::ParserProp_T x, std::function<void(lang::meta::Node_T)> f);

void visit_lang_meta_Node(lang::meta::Node::ParserDecl::Prop_T x, std::function<void(lang::meta::Node_T)> f);

void visit_lang_meta_Node(lang::meta::Node::PrecAssoc::Left_T x, std::function<void(lang::meta::Node_T)> f);

void visit_lang_meta_Node(lang::meta::Node::PrecAssoc::Right_T x, std::function<void(lang::meta::Node_T)> f);

void visit_lang_meta_Node(lang::meta::Node::PrecAssoc::Prefix_T x, std::function<void(lang::meta::Node_T)> f);

void visit_lang_meta_Node(lang::meta::Node::PrecAssoc::Postfix_T x, std::function<void(lang::meta::Node_T)> f);

void visit_lang_meta_Node(lang::meta::Node::PrecAssoc_T x, std::function<void(lang::meta::Node_T)> f);

void visit_lang_meta_Node(lang::meta::Node::PrecItem_T x, std::function<void(lang::meta::Node_T)> f);

void visit_lang_meta_Node(lang::meta::Node::ParserDecl::Prec_T x, std::function<void(lang::meta::Node_T)> f);

void visit_lang_meta_Node(lang::meta::Node::AttrClauseExpr::LhsGeq_T x, std::function<void(lang::meta::Node_T)> f);

void visit_lang_meta_Node(lang::meta::Node::AttrClauseExprRhsLoc::All_T x, std::function<void(lang::meta::Node_T)> f);

void visit_lang_meta_Node(lang::meta::Node::AttrClauseExprRhsLoc::Begin_T x, std::function<void(lang::meta::Node_T)> f);

void visit_lang_meta_Node(lang::meta::Node::AttrClauseExprRhsLoc::Mid_T x, std::function<void(lang::meta::Node_T)> f);

void visit_lang_meta_Node(lang::meta::Node::AttrClauseExprRhsLoc::End_T x, std::function<void(lang::meta::Node_T)> f);

void visit_lang_meta_Node(lang::meta::Node::AttrClauseExprRhsLoc_T x, std::function<void(lang::meta::Node_T)> f);

void visit_lang_meta_Node(lang::meta::Node::AttrClauseExpr::RhsGeq_T x, std::function<void(lang::meta::Node_T)> f);

void visit_lang_meta_Node(lang::meta::Node::AttrClauseExpr::Implies_T x, std::function<void(lang::meta::Node_T)> f);

void visit_lang_meta_Node(lang::meta::Node::AttrClauseExpr_T x, std::function<void(lang::meta::Node_T)> f);

void visit_lang_meta_Node(lang::meta::Node::AttrClause::Expr_T x, std::function<void(lang::meta::Node_T)> f);

void visit_lang_meta_Node(lang::meta::Node::AttrClause::Block_T x, std::function<void(lang::meta::Node_T)> f);

void visit_lang_meta_Node(lang::meta::Node::AttrMatchCasePattern::Alt_T x, std::function<void(lang::meta::Node_T)> f);

void visit_lang_meta_Node(lang::meta::Node::AttrMatchCasePattern::Wildcard_T x, std::function<void(lang::meta::Node_T)> f);

void visit_lang_meta_Node(lang::meta::Node::AttrMatchCasePattern_T x, std::function<void(lang::meta::Node_T)> f);

void visit_lang_meta_Node(lang::meta::Node::AttrMatchCase_T x, std::function<void(lang::meta::Node_T)> f);

void visit_lang_meta_Node(lang::meta::Node::AttrClause::Match_T x, std::function<void(lang::meta::Node_T)> f);

void visit_lang_meta_Node(lang::meta::Node::AttrClause_T x, std::function<void(lang::meta::Node_T)> f);

void visit_lang_meta_Node(lang::meta::Node::ParserDecl::Attr_T x, std::function<void(lang::meta::Node_T)> f);

void visit_lang_meta_Node(lang::meta::Node::ParserDecl::Rule::op::DEF_T x, std::function<void(lang::meta::Node_T)> f);

void visit_lang_meta_Node(lang::meta::Node::ParserDecl::Rule::op::DEF_ALIAS_T x, std::function<void(lang::meta::Node_T)> f);

void visit_lang_meta_Node(lang::meta::Node::ParserDecl::Rule::op_T x, std::function<void(lang::meta::Node_T)> f);

void visit_lang_meta_Node(lang::meta::Node::ParserDecl::Rule_T x, std::function<void(lang::meta::Node_T)> f);

void visit_lang_meta_Node(lang::meta::Node::ParserDecl_T x, std::function<void(lang::meta::Node_T)> f);

void visit_lang_meta_Node(lang::meta::Node::Stanza::Parser_T x, std::function<void(lang::meta::Node_T)> f);

void visit_lang_meta_Node(lang::meta::Node::TestCase_T x, std::function<void(lang::meta::Node_T)> f);

void visit_lang_meta_Node(lang::meta::Node::Stanza::Test_T x, std::function<void(lang::meta::Node_T)> f);

void visit_lang_meta_Node(lang::meta::Node::CompileTestCase_T x, std::function<void(lang::meta::Node_T)> f);

void visit_lang_meta_Node(lang::meta::Node::Stanza::CompileTest_T x, std::function<void(lang::meta::Node_T)> f);

void visit_lang_meta_Node(lang::meta::Node::Stanza_T x, std::function<void(lang::meta::Node_T)> f);

void visit_lang_meta_Node(lang::meta::Node::Lang_T x, std::function<void(lang::meta::Node_T)> f);

void visit_lang_meta_Node(lang::meta::Node_T x, std::function<void(lang::meta::Node_T)> f);

lang::meta::Node_T xformT_lang_meta_Node(lang::meta::Node::Decl::Include_T x, std::function<lang::meta::Node_T(lang::meta::Node_T)> f);

lang::meta::Node_T xformT_lang_meta_Node(lang::meta::Node::Decl::IncludePost_T x, std::function<lang::meta::Node_T(lang::meta::Node_T)> f);

lang::meta::Node_T xformT_lang_meta_Node(lang::meta::Node::Decl_T x, std::function<lang::meta::Node_T(lang::meta::Node_T)> f);

lang::meta::Node_T xformT_lang_meta_Node(lang::meta::Node::TokenDecl::op::DEF_T x, std::function<lang::meta::Node_T(lang::meta::Node_T)> f);

lang::meta::Node_T xformT_lang_meta_Node(lang::meta::Node::TokenDecl::op::DEF_ALIAS_T x, std::function<lang::meta::Node_T(lang::meta::Node_T)> f);

lang::meta::Node_T xformT_lang_meta_Node(lang::meta::Node::TokenDecl::op_T x, std::function<lang::meta::Node_T(lang::meta::Node_T)> f);

lang::meta::Node_T xformT_lang_meta_Node(lang::meta::Node::Id_T x, std::function<lang::meta::Node_T(lang::meta::Node_T)> f);

lang::meta::Node_T xformT_lang_meta_Node(lang::meta::Node::ParseExpr::Id_T x, std::function<lang::meta::Node_T(lang::meta::Node_T)> f);

lang::meta::Node_T xformT_lang_meta_Node(lang::meta::Node::ParseExpr::Eof_T x, std::function<lang::meta::Node_T(lang::meta::Node_T)> f);

lang::meta::Node_T xformT_lang_meta_Node(lang::meta::Node::ParseExpr::False_T x, std::function<lang::meta::Node_T(lang::meta::Node_T)> f);

lang::meta::Node_T xformT_lang_meta_Node(lang::meta::Node::ParseExpr::Eps_T x, std::function<lang::meta::Node_T(lang::meta::Node_T)> f);

lang::meta::Node_T xformT_lang_meta_Node(lang::meta::Node::ParseExpr::Indent_T x, std::function<lang::meta::Node_T(lang::meta::Node_T)> f);

lang::meta::Node_T xformT_lang_meta_Node(lang::meta::Node::ParseExpr::Dedent_T x, std::function<lang::meta::Node_T(lang::meta::Node_T)> f);

lang::meta::Node_T xformT_lang_meta_Node(lang::meta::Node::ParseExpr::Newline_T x, std::function<lang::meta::Node_T(lang::meta::Node_T)> f);

lang::meta::Node_T xformT_lang_meta_Node(lang::meta::Node::ParseExpr::UnicodeAny_T x, std::function<lang::meta::Node_T(lang::meta::Node_T)> f);

lang::meta::Node_T xformT_lang_meta_Node(lang::meta::Node::ParseExpr::AsciiBaseAny_T x, std::function<lang::meta::Node_T(lang::meta::Node_T)> f);

lang::meta::Node_T xformT_lang_meta_Node(lang::meta::Node::ParseExpr::Alt_T x, std::function<lang::meta::Node_T(lang::meta::Node_T)> f);

lang::meta::Node_T xformT_lang_meta_Node(lang::meta::Node::ParseExpr::AltExplicit_T x, std::function<lang::meta::Node_T(lang::meta::Node_T)> f);

lang::meta::Node_T xformT_lang_meta_Node(lang::meta::Node::ParseExpr::Minus_T x, std::function<lang::meta::Node_T(lang::meta::Node_T)> f);

lang::meta::Node_T xformT_lang_meta_Node(lang::meta::Node::ParseExpr::Concat_T x, std::function<lang::meta::Node_T(lang::meta::Node_T)> f);

lang::meta::Node_T xformT_lang_meta_Node(lang::meta::Node::ParseExpr::Optional_T x, std::function<lang::meta::Node_T(lang::meta::Node_T)> f);

lang::meta::Node_T xformT_lang_meta_Node(lang::meta::Node::ParseExpr::Rep_T x, std::function<lang::meta::Node_T(lang::meta::Node_T)> f);

lang::meta::Node_T xformT_lang_meta_Node(lang::meta::Node::ParseExpr::RepNonzero_T x, std::function<lang::meta::Node_T(lang::meta::Node_T)> f);

lang::meta::Node_T xformT_lang_meta_Node(lang::meta::Node::ParseExpr::RepCount_T x, std::function<lang::meta::Node_T(lang::meta::Node_T)> f);

lang::meta::Node_T xformT_lang_meta_Node(lang::meta::Node::ParseExpr::CharRange_T x, std::function<lang::meta::Node_T(lang::meta::Node_T)> f);

lang::meta::Node_T xformT_lang_meta_Node(lang::meta::Node::ParseExpr::StrLit_T x, std::function<lang::meta::Node_T(lang::meta::Node_T)> f);

lang::meta::Node_T xformT_lang_meta_Node(lang::meta::Node::ParseExpr::Underscore_T x, std::function<lang::meta::Node_T(lang::meta::Node_T)> f);

lang::meta::Node_T xformT_lang_meta_Node(lang::meta::Node::ParseExpr::Pass_T x, std::function<lang::meta::Node_T(lang::meta::Node_T)> f);

lang::meta::Node_T xformT_lang_meta_Node(lang::meta::Node::ParseExpr::Paren_T x, std::function<lang::meta::Node_T(lang::meta::Node_T)> f);

lang::meta::Node_T xformT_lang_meta_Node(lang::meta::Node::ParseExpr::Name_T x, std::function<lang::meta::Node_T(lang::meta::Node_T)> f);

lang::meta::Node_T xformT_lang_meta_Node(lang::meta::Node::ParseExprListType::List_T x, std::function<lang::meta::Node_T(lang::meta::Node_T)> f);

lang::meta::Node_T xformT_lang_meta_Node(lang::meta::Node::ParseExprListType::Block_T x, std::function<lang::meta::Node_T(lang::meta::Node_T)> f);

lang::meta::Node_T xformT_lang_meta_Node(lang::meta::Node::ParseExprListType::Block2_T x, std::function<lang::meta::Node_T(lang::meta::Node_T)> f);

lang::meta::Node_T xformT_lang_meta_Node(lang::meta::Node::ParseExprListType::Top_T x, std::function<lang::meta::Node_T(lang::meta::Node_T)> f);

lang::meta::Node_T xformT_lang_meta_Node(lang::meta::Node::ParseExprListType::Top2_T x, std::function<lang::meta::Node_T(lang::meta::Node_T)> f);

lang::meta::Node_T xformT_lang_meta_Node(lang::meta::Node::ParseExprListType_T x, std::function<lang::meta::Node_T(lang::meta::Node_T)> f);

lang::meta::Node_T xformT_lang_meta_Node(lang::meta::Node::ParseExprListNum::Ge0_T x, std::function<lang::meta::Node_T(lang::meta::Node_T)> f);

lang::meta::Node_T xformT_lang_meta_Node(lang::meta::Node::ParseExprListNum::Ge1_T x, std::function<lang::meta::Node_T(lang::meta::Node_T)> f);

lang::meta::Node_T xformT_lang_meta_Node(lang::meta::Node::ParseExprListNum::Ge2_T x, std::function<lang::meta::Node_T(lang::meta::Node_T)> f);

lang::meta::Node_T xformT_lang_meta_Node(lang::meta::Node::ParseExprListNum_T x, std::function<lang::meta::Node_T(lang::meta::Node_T)> f);

lang::meta::Node_T xformT_lang_meta_Node(lang::meta::Node::ParseExpr::List::end_delim::NONE_T x, std::function<lang::meta::Node_T(lang::meta::Node_T)> f);

lang::meta::Node_T xformT_lang_meta_Node(lang::meta::Node::ParseExpr::List::end_delim::OPTIONAL_T x, std::function<lang::meta::Node_T(lang::meta::Node_T)> f);

lang::meta::Node_T xformT_lang_meta_Node(lang::meta::Node::ParseExpr::List::end_delim::SOME_T x, std::function<lang::meta::Node_T(lang::meta::Node_T)> f);

lang::meta::Node_T xformT_lang_meta_Node(lang::meta::Node::ParseExpr::List::end_delim_T x, std::function<lang::meta::Node_T(lang::meta::Node_T)> f);

lang::meta::Node_T xformT_lang_meta_Node(lang::meta::Node::ParseExpr::List_T x, std::function<lang::meta::Node_T(lang::meta::Node_T)> f);

lang::meta::Node_T xformT_lang_meta_Node(lang::meta::Node::ParseExpr::Unfold_T x, std::function<lang::meta::Node_T(lang::meta::Node_T)> f);

lang::meta::Node_T xformT_lang_meta_Node(lang::meta::Node::AttrReq::Base_T x, std::function<lang::meta::Node_T(lang::meta::Node_T)> f);

lang::meta::Node_T xformT_lang_meta_Node(lang::meta::Node::AttrReq::PrecStar_T x, std::function<lang::meta::Node_T(lang::meta::Node_T)> f);

lang::meta::Node_T xformT_lang_meta_Node(lang::meta::Node::AttrReq_T x, std::function<lang::meta::Node_T(lang::meta::Node_T)> f);

lang::meta::Node_T xformT_lang_meta_Node(lang::meta::Node::ParseExpr::AttrReq_T x, std::function<lang::meta::Node_T(lang::meta::Node_T)> f);

lang::meta::Node_T xformT_lang_meta_Node(lang::meta::Node::ParseExpr_T x, std::function<lang::meta::Node_T(lang::meta::Node_T)> f);

lang::meta::Node_T xformT_lang_meta_Node(lang::meta::Node::TokenDecl_T x, std::function<lang::meta::Node_T(lang::meta::Node_T)> f);

lang::meta::Node_T xformT_lang_meta_Node(lang::meta::Node::Stanza::Tokens_T x, std::function<lang::meta::Node_T(lang::meta::Node_T)> f);

lang::meta::Node_T xformT_lang_meta_Node(lang::meta::Node::LexerDecl::Main_T x, std::function<lang::meta::Node_T(lang::meta::Node_T)> f);

lang::meta::Node_T xformT_lang_meta_Node(lang::meta::Node::LexerDecl::Mode::ws_sig_::spec_T x, std::function<lang::meta::Node_T(lang::meta::Node_T)> f);

lang::meta::Node_T xformT_lang_meta_Node(lang::meta::Node::LexerDecl::Mode::ws_sig__T x, std::function<lang::meta::Node_T(lang::meta::Node_T)> f);

lang::meta::Node_T xformT_lang_meta_Node(lang::meta::Node::LexerInstr::Emit_T x, std::function<lang::meta::Node_T(lang::meta::Node_T)> f);

lang::meta::Node_T xformT_lang_meta_Node(lang::meta::Node::LexerInstr::Pass_T x, std::function<lang::meta::Node_T(lang::meta::Node_T)> f);

lang::meta::Node_T xformT_lang_meta_Node(lang::meta::Node::LexerInstr::Push_T x, std::function<lang::meta::Node_T(lang::meta::Node_T)> f);

lang::meta::Node_T xformT_lang_meta_Node(lang::meta::Node::LexerInstr::Pop_T x, std::function<lang::meta::Node_T(lang::meta::Node_T)> f);

lang::meta::Node_T xformT_lang_meta_Node(lang::meta::Node::LexerInstr::PopExtract_T x, std::function<lang::meta::Node_T(lang::meta::Node_T)> f);

lang::meta::Node_T xformT_lang_meta_Node(lang::meta::Node::LexerInstr::PopEmit_T x, std::function<lang::meta::Node_T(lang::meta::Node_T)> f);

lang::meta::Node_T xformT_lang_meta_Node(lang::meta::Node::LexerInstr::MatchHistory_T x, std::function<lang::meta::Node_T(lang::meta::Node_T)> f);

lang::meta::Node_T xformT_lang_meta_Node(lang::meta::Node::LexerInstr_T x, std::function<lang::meta::Node_T(lang::meta::Node_T)> f);

lang::meta::Node_T xformT_lang_meta_Node(lang::meta::Node::LexerModeCase_T x, std::function<lang::meta::Node_T(lang::meta::Node_T)> f);

lang::meta::Node_T xformT_lang_meta_Node(lang::meta::Node::LexerDecl::Mode_T x, std::function<lang::meta::Node_T(lang::meta::Node_T)> f);

lang::meta::Node_T xformT_lang_meta_Node(lang::meta::Node::LexerDecl_T x, std::function<lang::meta::Node_T(lang::meta::Node_T)> f);

lang::meta::Node_T xformT_lang_meta_Node(lang::meta::Node::Stanza::Lexer_T x, std::function<lang::meta::Node_T(lang::meta::Node_T)> f);

lang::meta::Node_T xformT_lang_meta_Node(lang::meta::Node::ParserDecl::Main_T x, std::function<lang::meta::Node_T(lang::meta::Node_T)> f);

lang::meta::Node_T xformT_lang_meta_Node(lang::meta::Node::ParserProp::NameStrict_T x, std::function<lang::meta::Node_T(lang::meta::Node_T)> f);

lang::meta::Node_T xformT_lang_meta_Node(lang::meta::Node::ParserProp::AllowUnreach_T x, std::function<lang::meta::Node_T(lang::meta::Node_T)> f);

lang::meta::Node_T xformT_lang_meta_Node(lang::meta::Node::ParserProp::ASTExtraData_T x, std::function<lang::meta::Node_T(lang::meta::Node_T)> f);

lang::meta::Node_T xformT_lang_meta_Node(lang::meta::Node::ParserProp::LRSpec_T x, std::function<lang::meta::Node_T(lang::meta::Node_T)> f);

lang::meta::Node_T xformT_lang_meta_Node(lang::meta::Node::ParserProp::Err__T x, std::function<lang::meta::Node_T(lang::meta::Node_T)> f);

lang::meta::Node_T xformT_lang_meta_Node(lang::meta::Node::ParserProp_T x, std::function<lang::meta::Node_T(lang::meta::Node_T)> f);

lang::meta::Node_T xformT_lang_meta_Node(lang::meta::Node::ParserDecl::Prop_T x, std::function<lang::meta::Node_T(lang::meta::Node_T)> f);

lang::meta::Node_T xformT_lang_meta_Node(lang::meta::Node::PrecAssoc::Left_T x, std::function<lang::meta::Node_T(lang::meta::Node_T)> f);

lang::meta::Node_T xformT_lang_meta_Node(lang::meta::Node::PrecAssoc::Right_T x, std::function<lang::meta::Node_T(lang::meta::Node_T)> f);

lang::meta::Node_T xformT_lang_meta_Node(lang::meta::Node::PrecAssoc::Prefix_T x, std::function<lang::meta::Node_T(lang::meta::Node_T)> f);

lang::meta::Node_T xformT_lang_meta_Node(lang::meta::Node::PrecAssoc::Postfix_T x, std::function<lang::meta::Node_T(lang::meta::Node_T)> f);

lang::meta::Node_T xformT_lang_meta_Node(lang::meta::Node::PrecAssoc_T x, std::function<lang::meta::Node_T(lang::meta::Node_T)> f);

lang::meta::Node_T xformT_lang_meta_Node(lang::meta::Node::PrecItem_T x, std::function<lang::meta::Node_T(lang::meta::Node_T)> f);

lang::meta::Node_T xformT_lang_meta_Node(lang::meta::Node::ParserDecl::Prec_T x, std::function<lang::meta::Node_T(lang::meta::Node_T)> f);

lang::meta::Node_T xformT_lang_meta_Node(lang::meta::Node::AttrClauseExpr::LhsGeq_T x, std::function<lang::meta::Node_T(lang::meta::Node_T)> f);

lang::meta::Node_T xformT_lang_meta_Node(lang::meta::Node::AttrClauseExprRhsLoc::All_T x, std::function<lang::meta::Node_T(lang::meta::Node_T)> f);

lang::meta::Node_T xformT_lang_meta_Node(lang::meta::Node::AttrClauseExprRhsLoc::Begin_T x, std::function<lang::meta::Node_T(lang::meta::Node_T)> f);

lang::meta::Node_T xformT_lang_meta_Node(lang::meta::Node::AttrClauseExprRhsLoc::Mid_T x, std::function<lang::meta::Node_T(lang::meta::Node_T)> f);

lang::meta::Node_T xformT_lang_meta_Node(lang::meta::Node::AttrClauseExprRhsLoc::End_T x, std::function<lang::meta::Node_T(lang::meta::Node_T)> f);

lang::meta::Node_T xformT_lang_meta_Node(lang::meta::Node::AttrClauseExprRhsLoc_T x, std::function<lang::meta::Node_T(lang::meta::Node_T)> f);

lang::meta::Node_T xformT_lang_meta_Node(lang::meta::Node::AttrClauseExpr::RhsGeq_T x, std::function<lang::meta::Node_T(lang::meta::Node_T)> f);

lang::meta::Node_T xformT_lang_meta_Node(lang::meta::Node::AttrClauseExpr::Implies_T x, std::function<lang::meta::Node_T(lang::meta::Node_T)> f);

lang::meta::Node_T xformT_lang_meta_Node(lang::meta::Node::AttrClauseExpr_T x, std::function<lang::meta::Node_T(lang::meta::Node_T)> f);

lang::meta::Node_T xformT_lang_meta_Node(lang::meta::Node::AttrClause::Expr_T x, std::function<lang::meta::Node_T(lang::meta::Node_T)> f);

lang::meta::Node_T xformT_lang_meta_Node(lang::meta::Node::AttrClause::Block_T x, std::function<lang::meta::Node_T(lang::meta::Node_T)> f);

lang::meta::Node_T xformT_lang_meta_Node(lang::meta::Node::AttrMatchCasePattern::Alt_T x, std::function<lang::meta::Node_T(lang::meta::Node_T)> f);

lang::meta::Node_T xformT_lang_meta_Node(lang::meta::Node::AttrMatchCasePattern::Wildcard_T x, std::function<lang::meta::Node_T(lang::meta::Node_T)> f);

lang::meta::Node_T xformT_lang_meta_Node(lang::meta::Node::AttrMatchCasePattern_T x, std::function<lang::meta::Node_T(lang::meta::Node_T)> f);

lang::meta::Node_T xformT_lang_meta_Node(lang::meta::Node::AttrMatchCase_T x, std::function<lang::meta::Node_T(lang::meta::Node_T)> f);

lang::meta::Node_T xformT_lang_meta_Node(lang::meta::Node::AttrClause::Match_T x, std::function<lang::meta::Node_T(lang::meta::Node_T)> f);

lang::meta::Node_T xformT_lang_meta_Node(lang::meta::Node::AttrClause_T x, std::function<lang::meta::Node_T(lang::meta::Node_T)> f);

lang::meta::Node_T xformT_lang_meta_Node(lang::meta::Node::ParserDecl::Attr_T x, std::function<lang::meta::Node_T(lang::meta::Node_T)> f);

lang::meta::Node_T xformT_lang_meta_Node(lang::meta::Node::ParserDecl::Rule::op::DEF_T x, std::function<lang::meta::Node_T(lang::meta::Node_T)> f);

lang::meta::Node_T xformT_lang_meta_Node(lang::meta::Node::ParserDecl::Rule::op::DEF_ALIAS_T x, std::function<lang::meta::Node_T(lang::meta::Node_T)> f);

lang::meta::Node_T xformT_lang_meta_Node(lang::meta::Node::ParserDecl::Rule::op_T x, std::function<lang::meta::Node_T(lang::meta::Node_T)> f);

lang::meta::Node_T xformT_lang_meta_Node(lang::meta::Node::ParserDecl::Rule_T x, std::function<lang::meta::Node_T(lang::meta::Node_T)> f);

lang::meta::Node_T xformT_lang_meta_Node(lang::meta::Node::ParserDecl_T x, std::function<lang::meta::Node_T(lang::meta::Node_T)> f);

lang::meta::Node_T xformT_lang_meta_Node(lang::meta::Node::Stanza::Parser_T x, std::function<lang::meta::Node_T(lang::meta::Node_T)> f);

lang::meta::Node_T xformT_lang_meta_Node(lang::meta::Node::TestCase_T x, std::function<lang::meta::Node_T(lang::meta::Node_T)> f);

lang::meta::Node_T xformT_lang_meta_Node(lang::meta::Node::Stanza::Test_T x, std::function<lang::meta::Node_T(lang::meta::Node_T)> f);

lang::meta::Node_T xformT_lang_meta_Node(lang::meta::Node::CompileTestCase_T x, std::function<lang::meta::Node_T(lang::meta::Node_T)> f);

lang::meta::Node_T xformT_lang_meta_Node(lang::meta::Node::Stanza::CompileTest_T x, std::function<lang::meta::Node_T(lang::meta::Node_T)> f);

lang::meta::Node_T xformT_lang_meta_Node(lang::meta::Node::Stanza_T x, std::function<lang::meta::Node_T(lang::meta::Node_T)> f);

lang::meta::Node_T xformT_lang_meta_Node(lang::meta::Node::Lang_T x, std::function<lang::meta::Node_T(lang::meta::Node_T)> f);

lang::meta::Node_T xformT_lang_meta_Node(lang::meta::Node_T x, std::function<lang::meta::Node_T(lang::meta::Node_T)> f);

lang::meta::Node_T xform_lang_meta_Node(lang::meta::Node_T x, std::function<lang::meta::Node_T(lang::meta::Node_T)> f);

lang::meta::Node::Lang_T xform_lang_meta_Node(lang::meta::Node::Lang_T x, std::function<lang::meta::Node_T(lang::meta::Node_T)> f);

lang::meta::Node::Decl_T xform_lang_meta_Node(lang::meta::Node::Decl_T x, std::function<lang::meta::Node_T(lang::meta::Node_T)> f);

lang::meta::Node::Decl::Include_T xform_lang_meta_Node(lang::meta::Node::Decl::Include_T x, std::function<lang::meta::Node_T(lang::meta::Node_T)> f);

lang::meta::Node::Decl::IncludePost_T xform_lang_meta_Node(lang::meta::Node::Decl::IncludePost_T x, std::function<lang::meta::Node_T(lang::meta::Node_T)> f);

lang::meta::Node::Stanza_T xform_lang_meta_Node(lang::meta::Node::Stanza_T x, std::function<lang::meta::Node_T(lang::meta::Node_T)> f);

lang::meta::Node::Stanza::Tokens_T xform_lang_meta_Node(lang::meta::Node::Stanza::Tokens_T x, std::function<lang::meta::Node_T(lang::meta::Node_T)> f);

lang::meta::Node::TokenDecl_T xform_lang_meta_Node(lang::meta::Node::TokenDecl_T x, std::function<lang::meta::Node_T(lang::meta::Node_T)> f);

lang::meta::Node::TokenDecl::op_T xform_lang_meta_Node(lang::meta::Node::TokenDecl::op_T x, std::function<lang::meta::Node_T(lang::meta::Node_T)> f);

lang::meta::Node::TokenDecl::op::DEF_T xform_lang_meta_Node(lang::meta::Node::TokenDecl::op::DEF_T x, std::function<lang::meta::Node_T(lang::meta::Node_T)> f);

lang::meta::Node::TokenDecl::op::DEF_ALIAS_T xform_lang_meta_Node(lang::meta::Node::TokenDecl::op::DEF_ALIAS_T x, std::function<lang::meta::Node_T(lang::meta::Node_T)> f);

lang::meta::Node::ParseExpr_T xform_lang_meta_Node(lang::meta::Node::ParseExpr_T x, std::function<lang::meta::Node_T(lang::meta::Node_T)> f);

lang::meta::Node::ParseExpr::Id_T xform_lang_meta_Node(lang::meta::Node::ParseExpr::Id_T x, std::function<lang::meta::Node_T(lang::meta::Node_T)> f);

lang::meta::Node::Id_T xform_lang_meta_Node(lang::meta::Node::Id_T x, std::function<lang::meta::Node_T(lang::meta::Node_T)> f);

lang::meta::Node::ParseExpr::Eof_T xform_lang_meta_Node(lang::meta::Node::ParseExpr::Eof_T x, std::function<lang::meta::Node_T(lang::meta::Node_T)> f);

lang::meta::Node::ParseExpr::False_T xform_lang_meta_Node(lang::meta::Node::ParseExpr::False_T x, std::function<lang::meta::Node_T(lang::meta::Node_T)> f);

lang::meta::Node::ParseExpr::Eps_T xform_lang_meta_Node(lang::meta::Node::ParseExpr::Eps_T x, std::function<lang::meta::Node_T(lang::meta::Node_T)> f);

lang::meta::Node::ParseExpr::Indent_T xform_lang_meta_Node(lang::meta::Node::ParseExpr::Indent_T x, std::function<lang::meta::Node_T(lang::meta::Node_T)> f);

lang::meta::Node::ParseExpr::Dedent_T xform_lang_meta_Node(lang::meta::Node::ParseExpr::Dedent_T x, std::function<lang::meta::Node_T(lang::meta::Node_T)> f);

lang::meta::Node::ParseExpr::Newline_T xform_lang_meta_Node(lang::meta::Node::ParseExpr::Newline_T x, std::function<lang::meta::Node_T(lang::meta::Node_T)> f);

lang::meta::Node::ParseExpr::UnicodeAny_T xform_lang_meta_Node(lang::meta::Node::ParseExpr::UnicodeAny_T x, std::function<lang::meta::Node_T(lang::meta::Node_T)> f);

lang::meta::Node::ParseExpr::AsciiBaseAny_T xform_lang_meta_Node(lang::meta::Node::ParseExpr::AsciiBaseAny_T x, std::function<lang::meta::Node_T(lang::meta::Node_T)> f);

lang::meta::Node::ParseExpr::Alt_T xform_lang_meta_Node(lang::meta::Node::ParseExpr::Alt_T x, std::function<lang::meta::Node_T(lang::meta::Node_T)> f);

lang::meta::Node::ParseExpr::AltExplicit_T xform_lang_meta_Node(lang::meta::Node::ParseExpr::AltExplicit_T x, std::function<lang::meta::Node_T(lang::meta::Node_T)> f);

lang::meta::Node::ParseExpr::Minus_T xform_lang_meta_Node(lang::meta::Node::ParseExpr::Minus_T x, std::function<lang::meta::Node_T(lang::meta::Node_T)> f);

lang::meta::Node::ParseExpr::Concat_T xform_lang_meta_Node(lang::meta::Node::ParseExpr::Concat_T x, std::function<lang::meta::Node_T(lang::meta::Node_T)> f);

lang::meta::Node::ParseExpr::Optional_T xform_lang_meta_Node(lang::meta::Node::ParseExpr::Optional_T x, std::function<lang::meta::Node_T(lang::meta::Node_T)> f);

lang::meta::Node::ParseExpr::Rep_T xform_lang_meta_Node(lang::meta::Node::ParseExpr::Rep_T x, std::function<lang::meta::Node_T(lang::meta::Node_T)> f);

lang::meta::Node::ParseExpr::RepNonzero_T xform_lang_meta_Node(lang::meta::Node::ParseExpr::RepNonzero_T x, std::function<lang::meta::Node_T(lang::meta::Node_T)> f);

lang::meta::Node::ParseExpr::RepCount_T xform_lang_meta_Node(lang::meta::Node::ParseExpr::RepCount_T x, std::function<lang::meta::Node_T(lang::meta::Node_T)> f);

lang::meta::Node::ParseExpr::CharRange_T xform_lang_meta_Node(lang::meta::Node::ParseExpr::CharRange_T x, std::function<lang::meta::Node_T(lang::meta::Node_T)> f);

lang::meta::Node::ParseExpr::StrLit_T xform_lang_meta_Node(lang::meta::Node::ParseExpr::StrLit_T x, std::function<lang::meta::Node_T(lang::meta::Node_T)> f);

lang::meta::Node::ParseExpr::Underscore_T xform_lang_meta_Node(lang::meta::Node::ParseExpr::Underscore_T x, std::function<lang::meta::Node_T(lang::meta::Node_T)> f);

lang::meta::Node::ParseExpr::Pass_T xform_lang_meta_Node(lang::meta::Node::ParseExpr::Pass_T x, std::function<lang::meta::Node_T(lang::meta::Node_T)> f);

lang::meta::Node::ParseExpr::Paren_T xform_lang_meta_Node(lang::meta::Node::ParseExpr::Paren_T x, std::function<lang::meta::Node_T(lang::meta::Node_T)> f);

lang::meta::Node::ParseExpr::Name_T xform_lang_meta_Node(lang::meta::Node::ParseExpr::Name_T x, std::function<lang::meta::Node_T(lang::meta::Node_T)> f);

lang::meta::Node::ParseExpr::List_T xform_lang_meta_Node(lang::meta::Node::ParseExpr::List_T x, std::function<lang::meta::Node_T(lang::meta::Node_T)> f);

lang::meta::Node::ParseExprListType_T xform_lang_meta_Node(lang::meta::Node::ParseExprListType_T x, std::function<lang::meta::Node_T(lang::meta::Node_T)> f);

lang::meta::Node::ParseExprListType::List_T xform_lang_meta_Node(lang::meta::Node::ParseExprListType::List_T x, std::function<lang::meta::Node_T(lang::meta::Node_T)> f);

lang::meta::Node::ParseExprListType::Block_T xform_lang_meta_Node(lang::meta::Node::ParseExprListType::Block_T x, std::function<lang::meta::Node_T(lang::meta::Node_T)> f);

lang::meta::Node::ParseExprListType::Block2_T xform_lang_meta_Node(lang::meta::Node::ParseExprListType::Block2_T x, std::function<lang::meta::Node_T(lang::meta::Node_T)> f);

lang::meta::Node::ParseExprListType::Top_T xform_lang_meta_Node(lang::meta::Node::ParseExprListType::Top_T x, std::function<lang::meta::Node_T(lang::meta::Node_T)> f);

lang::meta::Node::ParseExprListType::Top2_T xform_lang_meta_Node(lang::meta::Node::ParseExprListType::Top2_T x, std::function<lang::meta::Node_T(lang::meta::Node_T)> f);

lang::meta::Node::ParseExprListNum_T xform_lang_meta_Node(lang::meta::Node::ParseExprListNum_T x, std::function<lang::meta::Node_T(lang::meta::Node_T)> f);

lang::meta::Node::ParseExprListNum::Ge0_T xform_lang_meta_Node(lang::meta::Node::ParseExprListNum::Ge0_T x, std::function<lang::meta::Node_T(lang::meta::Node_T)> f);

lang::meta::Node::ParseExprListNum::Ge1_T xform_lang_meta_Node(lang::meta::Node::ParseExprListNum::Ge1_T x, std::function<lang::meta::Node_T(lang::meta::Node_T)> f);

lang::meta::Node::ParseExprListNum::Ge2_T xform_lang_meta_Node(lang::meta::Node::ParseExprListNum::Ge2_T x, std::function<lang::meta::Node_T(lang::meta::Node_T)> f);

lang::meta::Node::ParseExpr::List::end_delim_T xform_lang_meta_Node(lang::meta::Node::ParseExpr::List::end_delim_T x, std::function<lang::meta::Node_T(lang::meta::Node_T)> f);

lang::meta::Node::ParseExpr::List::end_delim::NONE_T xform_lang_meta_Node(lang::meta::Node::ParseExpr::List::end_delim::NONE_T x, std::function<lang::meta::Node_T(lang::meta::Node_T)> f);

lang::meta::Node::ParseExpr::List::end_delim::OPTIONAL_T xform_lang_meta_Node(lang::meta::Node::ParseExpr::List::end_delim::OPTIONAL_T x, std::function<lang::meta::Node_T(lang::meta::Node_T)> f);

lang::meta::Node::ParseExpr::List::end_delim::SOME_T xform_lang_meta_Node(lang::meta::Node::ParseExpr::List::end_delim::SOME_T x, std::function<lang::meta::Node_T(lang::meta::Node_T)> f);

lang::meta::Node::ParseExpr::Unfold_T xform_lang_meta_Node(lang::meta::Node::ParseExpr::Unfold_T x, std::function<lang::meta::Node_T(lang::meta::Node_T)> f);

lang::meta::Node::ParseExpr::AttrReq_T xform_lang_meta_Node(lang::meta::Node::ParseExpr::AttrReq_T x, std::function<lang::meta::Node_T(lang::meta::Node_T)> f);

lang::meta::Node::AttrReq_T xform_lang_meta_Node(lang::meta::Node::AttrReq_T x, std::function<lang::meta::Node_T(lang::meta::Node_T)> f);

lang::meta::Node::AttrReq::Base_T xform_lang_meta_Node(lang::meta::Node::AttrReq::Base_T x, std::function<lang::meta::Node_T(lang::meta::Node_T)> f);

lang::meta::Node::AttrReq::PrecStar_T xform_lang_meta_Node(lang::meta::Node::AttrReq::PrecStar_T x, std::function<lang::meta::Node_T(lang::meta::Node_T)> f);

lang::meta::Node::Stanza::Lexer_T xform_lang_meta_Node(lang::meta::Node::Stanza::Lexer_T x, std::function<lang::meta::Node_T(lang::meta::Node_T)> f);

lang::meta::Node::LexerDecl_T xform_lang_meta_Node(lang::meta::Node::LexerDecl_T x, std::function<lang::meta::Node_T(lang::meta::Node_T)> f);

lang::meta::Node::LexerDecl::Main_T xform_lang_meta_Node(lang::meta::Node::LexerDecl::Main_T x, std::function<lang::meta::Node_T(lang::meta::Node_T)> f);

lang::meta::Node::LexerDecl::Mode_T xform_lang_meta_Node(lang::meta::Node::LexerDecl::Mode_T x, std::function<lang::meta::Node_T(lang::meta::Node_T)> f);

lang::meta::Node::LexerDecl::Mode::ws_sig__T xform_lang_meta_Node(lang::meta::Node::LexerDecl::Mode::ws_sig__T x, std::function<lang::meta::Node_T(lang::meta::Node_T)> f);

lang::meta::Node::LexerDecl::Mode::ws_sig_::spec_T xform_lang_meta_Node(lang::meta::Node::LexerDecl::Mode::ws_sig_::spec_T x, std::function<lang::meta::Node_T(lang::meta::Node_T)> f);

lang::meta::Node::LexerModeCase_T xform_lang_meta_Node(lang::meta::Node::LexerModeCase_T x, std::function<lang::meta::Node_T(lang::meta::Node_T)> f);

lang::meta::Node::LexerInstr_T xform_lang_meta_Node(lang::meta::Node::LexerInstr_T x, std::function<lang::meta::Node_T(lang::meta::Node_T)> f);

lang::meta::Node::LexerInstr::Emit_T xform_lang_meta_Node(lang::meta::Node::LexerInstr::Emit_T x, std::function<lang::meta::Node_T(lang::meta::Node_T)> f);

lang::meta::Node::LexerInstr::Pass_T xform_lang_meta_Node(lang::meta::Node::LexerInstr::Pass_T x, std::function<lang::meta::Node_T(lang::meta::Node_T)> f);

lang::meta::Node::LexerInstr::Push_T xform_lang_meta_Node(lang::meta::Node::LexerInstr::Push_T x, std::function<lang::meta::Node_T(lang::meta::Node_T)> f);

lang::meta::Node::LexerInstr::Pop_T xform_lang_meta_Node(lang::meta::Node::LexerInstr::Pop_T x, std::function<lang::meta::Node_T(lang::meta::Node_T)> f);

lang::meta::Node::LexerInstr::PopExtract_T xform_lang_meta_Node(lang::meta::Node::LexerInstr::PopExtract_T x, std::function<lang::meta::Node_T(lang::meta::Node_T)> f);

lang::meta::Node::LexerInstr::PopEmit_T xform_lang_meta_Node(lang::meta::Node::LexerInstr::PopEmit_T x, std::function<lang::meta::Node_T(lang::meta::Node_T)> f);

lang::meta::Node::LexerInstr::MatchHistory_T xform_lang_meta_Node(lang::meta::Node::LexerInstr::MatchHistory_T x, std::function<lang::meta::Node_T(lang::meta::Node_T)> f);

lang::meta::Node::Stanza::Parser_T xform_lang_meta_Node(lang::meta::Node::Stanza::Parser_T x, std::function<lang::meta::Node_T(lang::meta::Node_T)> f);

lang::meta::Node::ParserDecl_T xform_lang_meta_Node(lang::meta::Node::ParserDecl_T x, std::function<lang::meta::Node_T(lang::meta::Node_T)> f);

lang::meta::Node::ParserDecl::Main_T xform_lang_meta_Node(lang::meta::Node::ParserDecl::Main_T x, std::function<lang::meta::Node_T(lang::meta::Node_T)> f);

lang::meta::Node::ParserDecl::Prop_T xform_lang_meta_Node(lang::meta::Node::ParserDecl::Prop_T x, std::function<lang::meta::Node_T(lang::meta::Node_T)> f);

lang::meta::Node::ParserProp_T xform_lang_meta_Node(lang::meta::Node::ParserProp_T x, std::function<lang::meta::Node_T(lang::meta::Node_T)> f);

lang::meta::Node::ParserProp::NameStrict_T xform_lang_meta_Node(lang::meta::Node::ParserProp::NameStrict_T x, std::function<lang::meta::Node_T(lang::meta::Node_T)> f);

lang::meta::Node::ParserProp::AllowUnreach_T xform_lang_meta_Node(lang::meta::Node::ParserProp::AllowUnreach_T x, std::function<lang::meta::Node_T(lang::meta::Node_T)> f);

lang::meta::Node::ParserProp::ASTExtraData_T xform_lang_meta_Node(lang::meta::Node::ParserProp::ASTExtraData_T x, std::function<lang::meta::Node_T(lang::meta::Node_T)> f);

lang::meta::Node::ParserProp::LRSpec_T xform_lang_meta_Node(lang::meta::Node::ParserProp::LRSpec_T x, std::function<lang::meta::Node_T(lang::meta::Node_T)> f);

lang::meta::Node::ParserProp::Err__T xform_lang_meta_Node(lang::meta::Node::ParserProp::Err__T x, std::function<lang::meta::Node_T(lang::meta::Node_T)> f);

lang::meta::Node::ParserDecl::Prec_T xform_lang_meta_Node(lang::meta::Node::ParserDecl::Prec_T x, std::function<lang::meta::Node_T(lang::meta::Node_T)> f);

lang::meta::Node::PrecItem_T xform_lang_meta_Node(lang::meta::Node::PrecItem_T x, std::function<lang::meta::Node_T(lang::meta::Node_T)> f);

lang::meta::Node::PrecAssoc_T xform_lang_meta_Node(lang::meta::Node::PrecAssoc_T x, std::function<lang::meta::Node_T(lang::meta::Node_T)> f);

lang::meta::Node::PrecAssoc::Left_T xform_lang_meta_Node(lang::meta::Node::PrecAssoc::Left_T x, std::function<lang::meta::Node_T(lang::meta::Node_T)> f);

lang::meta::Node::PrecAssoc::Right_T xform_lang_meta_Node(lang::meta::Node::PrecAssoc::Right_T x, std::function<lang::meta::Node_T(lang::meta::Node_T)> f);

lang::meta::Node::PrecAssoc::Prefix_T xform_lang_meta_Node(lang::meta::Node::PrecAssoc::Prefix_T x, std::function<lang::meta::Node_T(lang::meta::Node_T)> f);

lang::meta::Node::PrecAssoc::Postfix_T xform_lang_meta_Node(lang::meta::Node::PrecAssoc::Postfix_T x, std::function<lang::meta::Node_T(lang::meta::Node_T)> f);

lang::meta::Node::ParserDecl::Attr_T xform_lang_meta_Node(lang::meta::Node::ParserDecl::Attr_T x, std::function<lang::meta::Node_T(lang::meta::Node_T)> f);

lang::meta::Node::AttrClause_T xform_lang_meta_Node(lang::meta::Node::AttrClause_T x, std::function<lang::meta::Node_T(lang::meta::Node_T)> f);

lang::meta::Node::AttrClause::Expr_T xform_lang_meta_Node(lang::meta::Node::AttrClause::Expr_T x, std::function<lang::meta::Node_T(lang::meta::Node_T)> f);

lang::meta::Node::AttrClauseExpr_T xform_lang_meta_Node(lang::meta::Node::AttrClauseExpr_T x, std::function<lang::meta::Node_T(lang::meta::Node_T)> f);

lang::meta::Node::AttrClauseExpr::LhsGeq_T xform_lang_meta_Node(lang::meta::Node::AttrClauseExpr::LhsGeq_T x, std::function<lang::meta::Node_T(lang::meta::Node_T)> f);

lang::meta::Node::AttrClauseExpr::RhsGeq_T xform_lang_meta_Node(lang::meta::Node::AttrClauseExpr::RhsGeq_T x, std::function<lang::meta::Node_T(lang::meta::Node_T)> f);

lang::meta::Node::AttrClauseExprRhsLoc_T xform_lang_meta_Node(lang::meta::Node::AttrClauseExprRhsLoc_T x, std::function<lang::meta::Node_T(lang::meta::Node_T)> f);

lang::meta::Node::AttrClauseExprRhsLoc::All_T xform_lang_meta_Node(lang::meta::Node::AttrClauseExprRhsLoc::All_T x, std::function<lang::meta::Node_T(lang::meta::Node_T)> f);

lang::meta::Node::AttrClauseExprRhsLoc::Begin_T xform_lang_meta_Node(lang::meta::Node::AttrClauseExprRhsLoc::Begin_T x, std::function<lang::meta::Node_T(lang::meta::Node_T)> f);

lang::meta::Node::AttrClauseExprRhsLoc::Mid_T xform_lang_meta_Node(lang::meta::Node::AttrClauseExprRhsLoc::Mid_T x, std::function<lang::meta::Node_T(lang::meta::Node_T)> f);

lang::meta::Node::AttrClauseExprRhsLoc::End_T xform_lang_meta_Node(lang::meta::Node::AttrClauseExprRhsLoc::End_T x, std::function<lang::meta::Node_T(lang::meta::Node_T)> f);

lang::meta::Node::AttrClauseExpr::Implies_T xform_lang_meta_Node(lang::meta::Node::AttrClauseExpr::Implies_T x, std::function<lang::meta::Node_T(lang::meta::Node_T)> f);

lang::meta::Node::AttrClause::Block_T xform_lang_meta_Node(lang::meta::Node::AttrClause::Block_T x, std::function<lang::meta::Node_T(lang::meta::Node_T)> f);

lang::meta::Node::AttrClause::Match_T xform_lang_meta_Node(lang::meta::Node::AttrClause::Match_T x, std::function<lang::meta::Node_T(lang::meta::Node_T)> f);

lang::meta::Node::AttrMatchCase_T xform_lang_meta_Node(lang::meta::Node::AttrMatchCase_T x, std::function<lang::meta::Node_T(lang::meta::Node_T)> f);

lang::meta::Node::AttrMatchCasePattern_T xform_lang_meta_Node(lang::meta::Node::AttrMatchCasePattern_T x, std::function<lang::meta::Node_T(lang::meta::Node_T)> f);

lang::meta::Node::AttrMatchCasePattern::Alt_T xform_lang_meta_Node(lang::meta::Node::AttrMatchCasePattern::Alt_T x, std::function<lang::meta::Node_T(lang::meta::Node_T)> f);

lang::meta::Node::AttrMatchCasePattern::Wildcard_T xform_lang_meta_Node(lang::meta::Node::AttrMatchCasePattern::Wildcard_T x, std::function<lang::meta::Node_T(lang::meta::Node_T)> f);

lang::meta::Node::ParserDecl::Rule_T xform_lang_meta_Node(lang::meta::Node::ParserDecl::Rule_T x, std::function<lang::meta::Node_T(lang::meta::Node_T)> f);

lang::meta::Node::ParserDecl::Rule::op_T xform_lang_meta_Node(lang::meta::Node::ParserDecl::Rule::op_T x, std::function<lang::meta::Node_T(lang::meta::Node_T)> f);

lang::meta::Node::ParserDecl::Rule::op::DEF_T xform_lang_meta_Node(lang::meta::Node::ParserDecl::Rule::op::DEF_T x, std::function<lang::meta::Node_T(lang::meta::Node_T)> f);

lang::meta::Node::ParserDecl::Rule::op::DEF_ALIAS_T xform_lang_meta_Node(lang::meta::Node::ParserDecl::Rule::op::DEF_ALIAS_T x, std::function<lang::meta::Node_T(lang::meta::Node_T)> f);

lang::meta::Node::Stanza::Test_T xform_lang_meta_Node(lang::meta::Node::Stanza::Test_T x, std::function<lang::meta::Node_T(lang::meta::Node_T)> f);

lang::meta::Node::TestCase_T xform_lang_meta_Node(lang::meta::Node::TestCase_T x, std::function<lang::meta::Node_T(lang::meta::Node_T)> f);

lang::meta::Node::Stanza::CompileTest_T xform_lang_meta_Node(lang::meta::Node::Stanza::CompileTest_T x, std::function<lang::meta::Node_T(lang::meta::Node_T)> f);

lang::meta::Node::CompileTestCase_T xform_lang_meta_Node(lang::meta::Node::CompileTestCase_T x, std::function<lang::meta::Node_T(lang::meta::Node_T)> f);

namespace lang::meta::parser {
    langcc::IntPair action_by_vertex(langcc::ParserVertexId v, langcc::ParserLookahead la);
}

namespace lang::meta::parser {
    langcc::ParserVertexId vertex_dfa_step(langcc::ParserVertexId v, langcc::ParserSymId sym, langcc::ParserAttrMask attr);
}

namespace lang::meta::parser {
    langcc::ParserProcXforms proc_xform_by_prod_id();
}

namespace lang::meta::parser {
    langcc::ParserSymByName start_marker_by_name();
}

namespace lang::meta::parser {
    langcc::ParserSymId term_tok_to_sym(langcc::TokenId tok);
}

namespace lang::meta::parser {
    langcc::ParserSymId sym_to_recur_step(langcc::ParserSymId sym);
}

namespace lang::meta::parser {
    std::string sym_to_debug_string(langcc::ParserSymId sym);
}

namespace lang::meta::parser {
    langcc::Int sym_to_num_attrs(langcc::ParserSymId sym);
}

namespace lang::meta::parser {
    std::string attr_to_debug_string(langcc::ParserSymId sym, langcc::Int attr_ind);
}

namespace lang::meta {
    using LangDesc = langcc::LangDesc<Node::_T, parser::action_by_vertex, parser::vertex_dfa_step>;
}

namespace lang::meta {
    using LangDesc_T = langcc::LangDesc_T<Node::_T, parser::action_by_vertex, parser::vertex_dfa_step>;
}

namespace lang::meta {
    using QuoteEnv = langcc::QuoteEnv<Node::_T, parser::action_by_vertex, parser::vertex_dfa_step>;
}

namespace lang::meta {
    using QuoteEnv_T = langcc::QuoteEnv_T<Node::_T, parser::action_by_vertex, parser::vertex_dfa_step>;
}

namespace lang::meta {
    lang::meta::LangDesc_T init();
}

namespace lang::meta::lexer::body {
    inline __attribute__((always_inline)) langcc::Int proc_mode_loop_opt(langcc::Ptr<langcc::LexerModeDesc> mode, langcc::Ptr<langcc::LexerState> st, langcc::Ptr<langcc::SymItemVec> emit_dst, langcc::Int mode_start_pos, langcc::Int mode_buf_pos);
}

namespace lang::meta::lexer::comment_single {
    inline __attribute__((always_inline)) langcc::Int proc_mode_loop_opt(langcc::Ptr<langcc::LexerModeDesc> mode, langcc::Ptr<langcc::LexerState> st, langcc::Ptr<langcc::SymItemVec> emit_dst, langcc::Int mode_start_pos, langcc::Int mode_buf_pos);
}
