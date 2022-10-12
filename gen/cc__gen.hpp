#pragma once

#include <langcc_rt.hpp>

namespace lang::cc::lexer {
    rc_ptr<lang_rt::DFALabelIdVec> label_ids_ascii();

    rc_ptr<lang_rt::DFALabelIdMap> label_ids_unicode();
}

namespace lang::cc::lexer::body {
    lang_rt::DFAVertexId step(lang_rt::DFAVertexId v, lang_rt::DFALabelId lbl);

    __attribute__((always_inline)) lang_rt::DFAActionWithToken acc(lang_rt::DFAVertexId v);

    __attribute__((always_inline)) IntPair step_exec(Ptr<lang_rt::LexerState> st, Ptr<lang_rt::SymItemVec> emit_dst, Ptr<lang_rt::LexWhitespaceState> ws_state, lang_rt::DFAActionId acc, lang_rt::TokenId tok, Int& in_i, Int& tok_lo, Int& tok_hi);

    Int proc_mode_loop(Ptr<lang_rt::LexerState> st, Ptr<lang_rt::SymItemVec> emit_dst, Int mode_start_pos, Int mode_buf_pos);
}

namespace lang::cc::lexer::comment_single {
    lang_rt::DFAVertexId step(lang_rt::DFAVertexId v, lang_rt::DFALabelId lbl);

    __attribute__((always_inline)) lang_rt::DFAActionWithToken acc(lang_rt::DFAVertexId v);

    __attribute__((always_inline)) IntPair step_exec(Ptr<lang_rt::LexerState> st, Ptr<lang_rt::SymItemVec> emit_dst, Ptr<lang_rt::LexWhitespaceState> ws_state, lang_rt::DFAActionId acc, lang_rt::TokenId tok, Int& in_i, Int& tok_lo, Int& tok_hi);

    Int proc_mode_loop(Ptr<lang_rt::LexerState> st, Ptr<lang_rt::SymItemVec> emit_dst, Int mode_start_pos, Int mode_buf_pos);
}

#pragma once

#include <langcc_util.hpp>

namespace lang::cc::Node::Module {
    struct _T;
}

namespace lang::cc::Node {
    using Module_T = rc_ptr<lang::cc::Node::Module::_T>;
}

namespace lang::cc::Node::Decl::Struct::tmpl::args::item {
    struct _T;
}

namespace lang::cc::Node::Decl::Struct::tmpl::args {
    using item_T = rc_ptr<lang::cc::Node::Decl::Struct::tmpl::args::item::_T>;
}

namespace lang::cc::Node::Decl::Struct::tmpl {
    struct _T;
}

namespace lang::cc::Node::Decl::Struct {
    using tmpl_T = rc_ptr<lang::cc::Node::Decl::Struct::tmpl::_T>;
}

namespace lang::cc::Node::Decl::Struct {
    struct _T;
}

namespace lang::cc::Node::Decl {
    using Struct_T = rc_ptr<lang::cc::Node::Decl::Struct::_T>;
}

namespace lang::cc::Node::StructDeclDef::Decl {
    struct _T;
}

namespace lang::cc::Node::StructDeclDef {
    using Decl_T = rc_ptr<lang::cc::Node::StructDeclDef::Decl::_T>;
}

namespace lang::cc::Node::StructDeclDef::Def {
    struct _T;
}

namespace lang::cc::Node::StructDeclDef {
    using Def_T = rc_ptr<lang::cc::Node::StructDeclDef::Def::_T>;
}

namespace lang::cc::Node::Entry::Field {
    struct _T;
}

namespace lang::cc::Node::Entry {
    using Field_T = rc_ptr<lang::cc::Node::Entry::Field::_T>;
}

namespace lang::cc::Node::Entry::Fun::tmpl::args::item {
    struct _T;
}

namespace lang::cc::Node::Entry::Fun::tmpl::args {
    using item_T = rc_ptr<lang::cc::Node::Entry::Fun::tmpl::args::item::_T>;
}

namespace lang::cc::Node::Entry::Fun::tmpl {
    struct _T;
}

namespace lang::cc::Node::Entry::Fun {
    using tmpl_T = rc_ptr<lang::cc::Node::Entry::Fun::tmpl::_T>;
}

namespace lang::cc::Node::Entry::Fun {
    struct _T;
}

namespace lang::cc::Node::Entry {
    using Fun_T = rc_ptr<lang::cc::Node::Entry::Fun::_T>;
}

namespace lang::cc::Node::Param::val {
    struct _T;
}

namespace lang::cc::Node::Param {
    using val_T = rc_ptr<lang::cc::Node::Param::val::_T>;
}

namespace lang::cc::Node::Param {
    struct _T;
}

namespace lang::cc::Node {
    using Param_T = rc_ptr<lang::cc::Node::Param::_T>;
}

namespace lang::cc::Node::FunDeclDef::Decl {
    struct _T;
}

namespace lang::cc::Node::FunDeclDef {
    using Decl_T = rc_ptr<lang::cc::Node::FunDeclDef::Decl::_T>;
}

namespace lang::cc::Node::FunDeclDef::Def {
    struct _T;
}

namespace lang::cc::Node::FunDeclDef {
    using Def_T = rc_ptr<lang::cc::Node::FunDeclDef::Def::_T>;
}

namespace lang::cc::Node::FunDeclDef::Del {
    struct _T;
}

namespace lang::cc::Node::FunDeclDef {
    using Del_T = rc_ptr<lang::cc::Node::FunDeclDef::Del::_T>;
}

namespace lang::cc::Node::FunDeclDef::Zero {
    struct _T;
}

namespace lang::cc::Node::FunDeclDef {
    using Zero_T = rc_ptr<lang::cc::Node::FunDeclDef::Zero::_T>;
}

namespace lang::cc::Node::Decl::EnumStruct {
    struct _T;
}

namespace lang::cc::Node::Decl {
    using EnumStruct_T = rc_ptr<lang::cc::Node::Decl::EnumStruct::_T>;
}

namespace lang::cc::Node::Decl::Fun::tmpl::args::item {
    struct _T;
}

namespace lang::cc::Node::Decl::Fun::tmpl::args {
    using item_T = rc_ptr<lang::cc::Node::Decl::Fun::tmpl::args::item::_T>;
}

namespace lang::cc::Node::Decl::Fun::tmpl {
    struct _T;
}

namespace lang::cc::Node::Decl::Fun {
    using tmpl_T = rc_ptr<lang::cc::Node::Decl::Fun::tmpl::_T>;
}

namespace lang::cc::Node::Decl::Fun {
    struct _T;
}

namespace lang::cc::Node::Decl {
    using Fun_T = rc_ptr<lang::cc::Node::Decl::Fun::_T>;
}

namespace lang::cc::Node::Mod::Const {
    struct _T;
}

namespace lang::cc::Node::Mod {
    using Const_T = rc_ptr<lang::cc::Node::Mod::Const::_T>;
}

namespace lang::cc::Node::Mod::Inline {
    struct _T;
}

namespace lang::cc::Node::Mod {
    using Inline_T = rc_ptr<lang::cc::Node::Mod::Inline::_T>;
}

namespace lang::cc::Node::Mod::Static {
    struct _T;
}

namespace lang::cc::Node::Mod {
    using Static_T = rc_ptr<lang::cc::Node::Mod::Static::_T>;
}

namespace lang::cc::Node::Mod::Virtual {
    struct _T;
}

namespace lang::cc::Node::Mod {
    using Virtual_T = rc_ptr<lang::cc::Node::Mod::Virtual::_T>;
}

namespace lang::cc::Node::Mod::NoInline {
    struct _T;
}

namespace lang::cc::Node::Mod {
    using NoInline_T = rc_ptr<lang::cc::Node::Mod::NoInline::_T>;
}

namespace lang::cc::Node::Mod::AlwaysInline {
    struct _T;
}

namespace lang::cc::Node::Mod {
    using AlwaysInline_T = rc_ptr<lang::cc::Node::Mod::AlwaysInline::_T>;
}

namespace lang::cc::Node::Decl::Namespace {
    struct _T;
}

namespace lang::cc::Node::Decl {
    using Namespace_T = rc_ptr<lang::cc::Node::Decl::Namespace::_T>;
}

namespace lang::cc::Node::Decl::UsingAlias::tmpl::args::item {
    struct _T;
}

namespace lang::cc::Node::Decl::UsingAlias::tmpl::args {
    using item_T = rc_ptr<lang::cc::Node::Decl::UsingAlias::tmpl::args::item::_T>;
}

namespace lang::cc::Node::Decl::UsingAlias::tmpl {
    struct _T;
}

namespace lang::cc::Node::Decl::UsingAlias {
    using tmpl_T = rc_ptr<lang::cc::Node::Decl::UsingAlias::tmpl::_T>;
}

namespace lang::cc::Node::Decl::UsingAlias {
    struct _T;
}

namespace lang::cc::Node::Decl {
    using UsingAlias_T = rc_ptr<lang::cc::Node::Decl::UsingAlias::_T>;
}

namespace lang::cc::Node::Decl::UsingNamespace {
    struct _T;
}

namespace lang::cc::Node::Decl {
    using UsingNamespace_T = rc_ptr<lang::cc::Node::Decl::UsingNamespace::_T>;
}

namespace lang::cc::Node::Decl::Include {
    struct _T;
}

namespace lang::cc::Node::Decl {
    using Include_T = rc_ptr<lang::cc::Node::Decl::Include::_T>;
}

namespace lang::cc::Node::Decl::PragmaOnce {
    struct _T;
}

namespace lang::cc::Node::Decl {
    using PragmaOnce_T = rc_ptr<lang::cc::Node::Decl::PragmaOnce::_T>;
}

namespace lang::cc::Node::Block {
    struct _T;
}

namespace lang::cc::Node {
    using Block_T = rc_ptr<lang::cc::Node::Block::_T>;
}

namespace lang::cc::Node::Stmt::Decl {
    struct _T;
}

namespace lang::cc::Node::Stmt {
    using Decl_T = rc_ptr<lang::cc::Node::Stmt::Decl::_T>;
}

namespace lang::cc::Node::TypedDecl::vars::item::val {
    struct _T;
}

namespace lang::cc::Node::TypedDecl::vars::item {
    using val_T = rc_ptr<lang::cc::Node::TypedDecl::vars::item::val::_T>;
}

namespace lang::cc::Node::TypedDecl::vars::item {
    struct _T;
}

namespace lang::cc::Node::TypedDecl::vars {
    using item_T = rc_ptr<lang::cc::Node::TypedDecl::vars::item::_T>;
}

namespace lang::cc::Node::TypedDecl {
    struct _T;
}

namespace lang::cc::Node {
    using TypedDecl_T = rc_ptr<lang::cc::Node::TypedDecl::_T>;
}

namespace lang::cc::Node::Stmt::Expr {
    struct _T;
}

namespace lang::cc::Node::Stmt {
    using Expr_T = rc_ptr<lang::cc::Node::Stmt::Expr::_T>;
}

namespace lang::cc::Node::Stmt::Block {
    struct _T;
}

namespace lang::cc::Node::Stmt {
    using Block_T = rc_ptr<lang::cc::Node::Stmt::Block::_T>;
}

namespace lang::cc::Node::Stmt::If {
    struct _T;
}

namespace lang::cc::Node::Stmt {
    using If_T = rc_ptr<lang::cc::Node::Stmt::If::_T>;
}

namespace lang::cc::Node::Stmt::IfElse {
    struct _T;
}

namespace lang::cc::Node::Stmt {
    using IfElse_T = rc_ptr<lang::cc::Node::Stmt::IfElse::_T>;
}

namespace lang::cc::Node::Stmt::For {
    struct _T;
}

namespace lang::cc::Node::Stmt {
    using For_T = rc_ptr<lang::cc::Node::Stmt::For::_T>;
}

namespace lang::cc::Node::ExprExt::Expr {
    struct _T;
}

namespace lang::cc::Node::ExprExt {
    using Expr_T = rc_ptr<lang::cc::Node::ExprExt::Expr::_T>;
}

namespace lang::cc::Node::ExprExt::Decl {
    struct _T;
}

namespace lang::cc::Node::ExprExt {
    using Decl_T = rc_ptr<lang::cc::Node::ExprExt::Decl::_T>;
}

namespace lang::cc::Node::Stmt::Switch {
    struct _T;
}

namespace lang::cc::Node::Stmt {
    using Switch_T = rc_ptr<lang::cc::Node::Stmt::Switch::_T>;
}

namespace lang::cc::Node::SwitchCase::Case {
    struct _T;
}

namespace lang::cc::Node::SwitchCase {
    using Case_T = rc_ptr<lang::cc::Node::SwitchCase::Case::_T>;
}

namespace lang::cc::Node::SwitchCase::Default {
    struct _T;
}

namespace lang::cc::Node::SwitchCase {
    using Default_T = rc_ptr<lang::cc::Node::SwitchCase::Default::_T>;
}

namespace lang::cc::Node::Stmt::Break {
    struct _T;
}

namespace lang::cc::Node::Stmt {
    using Break_T = rc_ptr<lang::cc::Node::Stmt::Break::_T>;
}

namespace lang::cc::Node::Stmt::Continue {
    struct _T;
}

namespace lang::cc::Node::Stmt {
    using Continue_T = rc_ptr<lang::cc::Node::Stmt::Continue::_T>;
}

namespace lang::cc::Node::Stmt::Return {
    struct _T;
}

namespace lang::cc::Node::Stmt {
    using Return_T = rc_ptr<lang::cc::Node::Stmt::Return::_T>;
}

namespace lang::cc::Node::Expr::Paren {
    struct _T;
}

namespace lang::cc::Node::Expr {
    using Paren_T = rc_ptr<lang::cc::Node::Expr::Paren::_T>;
}

namespace lang::cc::Node::Expr::Call {
    struct _T;
}

namespace lang::cc::Node::Expr {
    using Call_T = rc_ptr<lang::cc::Node::Expr::Call::_T>;
}

namespace lang::cc::Node::Expr::Index {
    struct _T;
}

namespace lang::cc::Node::Expr {
    using Index_T = rc_ptr<lang::cc::Node::Expr::Index::_T>;
}

namespace lang::cc::Node::Expr::IndexEmpty {
    struct _T;
}

namespace lang::cc::Node::Expr {
    using IndexEmpty_T = rc_ptr<lang::cc::Node::Expr::IndexEmpty::_T>;
}

namespace lang::cc::Node::Expr::Dot {
    struct _T;
}

namespace lang::cc::Node::Expr {
    using Dot_T = rc_ptr<lang::cc::Node::Expr::Dot::_T>;
}

namespace lang::cc::Node::Expr::Arrow {
    struct _T;
}

namespace lang::cc::Node::Expr {
    using Arrow_T = rc_ptr<lang::cc::Node::Expr::Arrow::_T>;
}

namespace lang::cc::Node::Expr::Ref_ {
    struct _T;
}

namespace lang::cc::Node::Expr {
    using Ref__T = rc_ptr<lang::cc::Node::Expr::Ref_::_T>;
}

namespace lang::cc::Node::Expr::AddrOf {
    struct _T;
}

namespace lang::cc::Node::Expr {
    using AddrOf_T = rc_ptr<lang::cc::Node::Expr::AddrOf::_T>;
}

namespace lang::cc::Node::Expr::Deref {
    struct _T;
}

namespace lang::cc::Node::Expr {
    using Deref_T = rc_ptr<lang::cc::Node::Expr::Deref::_T>;
}

namespace lang::cc::Node::Expr::UnaryPre::op::NOT {
    struct _T;
}

namespace lang::cc::Node::Expr::UnaryPre::op {
    using NOT_T = rc_ptr<lang::cc::Node::Expr::UnaryPre::op::NOT::_T>;
}

namespace lang::cc::Node::Expr::UnaryPre::op::NEG {
    struct _T;
}

namespace lang::cc::Node::Expr::UnaryPre::op {
    using NEG_T = rc_ptr<lang::cc::Node::Expr::UnaryPre::op::NEG::_T>;
}

namespace lang::cc::Node::Expr::UnaryPre::op {
    struct _T;
}

namespace lang::cc::Node::Expr::UnaryPre {
    using op_T = rc_ptr<lang::cc::Node::Expr::UnaryPre::op::_T>;
}

namespace lang::cc::Node::Expr::UnaryPre {
    struct _T;
}

namespace lang::cc::Node::Expr {
    using UnaryPre_T = rc_ptr<lang::cc::Node::Expr::UnaryPre::_T>;
}

namespace lang::cc::Node::Expr::IncDecPre::op::INC {
    struct _T;
}

namespace lang::cc::Node::Expr::IncDecPre::op {
    using INC_T = rc_ptr<lang::cc::Node::Expr::IncDecPre::op::INC::_T>;
}

namespace lang::cc::Node::Expr::IncDecPre::op::DEC {
    struct _T;
}

namespace lang::cc::Node::Expr::IncDecPre::op {
    using DEC_T = rc_ptr<lang::cc::Node::Expr::IncDecPre::op::DEC::_T>;
}

namespace lang::cc::Node::Expr::IncDecPre::op {
    struct _T;
}

namespace lang::cc::Node::Expr::IncDecPre {
    using op_T = rc_ptr<lang::cc::Node::Expr::IncDecPre::op::_T>;
}

namespace lang::cc::Node::Expr::IncDecPre {
    struct _T;
}

namespace lang::cc::Node::Expr {
    using IncDecPre_T = rc_ptr<lang::cc::Node::Expr::IncDecPre::_T>;
}

namespace lang::cc::Node::Expr::IncDecPost::op::INC {
    struct _T;
}

namespace lang::cc::Node::Expr::IncDecPost::op {
    using INC_T = rc_ptr<lang::cc::Node::Expr::IncDecPost::op::INC::_T>;
}

namespace lang::cc::Node::Expr::IncDecPost::op::DEC {
    struct _T;
}

namespace lang::cc::Node::Expr::IncDecPost::op {
    using DEC_T = rc_ptr<lang::cc::Node::Expr::IncDecPost::op::DEC::_T>;
}

namespace lang::cc::Node::Expr::IncDecPost::op {
    struct _T;
}

namespace lang::cc::Node::Expr::IncDecPost {
    using op_T = rc_ptr<lang::cc::Node::Expr::IncDecPost::op::_T>;
}

namespace lang::cc::Node::Expr::IncDecPost {
    struct _T;
}

namespace lang::cc::Node::Expr {
    using IncDecPost_T = rc_ptr<lang::cc::Node::Expr::IncDecPost::_T>;
}

namespace lang::cc::Node::Expr::Assign {
    struct _T;
}

namespace lang::cc::Node::Expr {
    using Assign_T = rc_ptr<lang::cc::Node::Expr::Assign::_T>;
}

namespace lang::cc::Node::Expr::Bin1::op::LOR {
    struct _T;
}

namespace lang::cc::Node::Expr::Bin1::op {
    using LOR_T = rc_ptr<lang::cc::Node::Expr::Bin1::op::LOR::_T>;
}

namespace lang::cc::Node::Expr::Bin1::op {
    struct _T;
}

namespace lang::cc::Node::Expr::Bin1 {
    using op_T = rc_ptr<lang::cc::Node::Expr::Bin1::op::_T>;
}

namespace lang::cc::Node::Expr::Bin1 {
    struct _T;
}

namespace lang::cc::Node::Expr {
    using Bin1_T = rc_ptr<lang::cc::Node::Expr::Bin1::_T>;
}

namespace lang::cc::Node::Expr::Bin2::op::LAND {
    struct _T;
}

namespace lang::cc::Node::Expr::Bin2::op {
    using LAND_T = rc_ptr<lang::cc::Node::Expr::Bin2::op::LAND::_T>;
}

namespace lang::cc::Node::Expr::Bin2::op {
    struct _T;
}

namespace lang::cc::Node::Expr::Bin2 {
    using op_T = rc_ptr<lang::cc::Node::Expr::Bin2::op::_T>;
}

namespace lang::cc::Node::Expr::Bin2 {
    struct _T;
}

namespace lang::cc::Node::Expr {
    using Bin2_T = rc_ptr<lang::cc::Node::Expr::Bin2::_T>;
}

namespace lang::cc::Node::Expr::Bin3::op::EQ {
    struct _T;
}

namespace lang::cc::Node::Expr::Bin3::op {
    using EQ_T = rc_ptr<lang::cc::Node::Expr::Bin3::op::EQ::_T>;
}

namespace lang::cc::Node::Expr::Bin3::op::NE {
    struct _T;
}

namespace lang::cc::Node::Expr::Bin3::op {
    using NE_T = rc_ptr<lang::cc::Node::Expr::Bin3::op::NE::_T>;
}

namespace lang::cc::Node::Expr::Bin3::op::LE {
    struct _T;
}

namespace lang::cc::Node::Expr::Bin3::op {
    using LE_T = rc_ptr<lang::cc::Node::Expr::Bin3::op::LE::_T>;
}

namespace lang::cc::Node::Expr::Bin3::op::GE {
    struct _T;
}

namespace lang::cc::Node::Expr::Bin3::op {
    using GE_T = rc_ptr<lang::cc::Node::Expr::Bin3::op::GE::_T>;
}

namespace lang::cc::Node::Expr::Bin3::op::LT {
    struct _T;
}

namespace lang::cc::Node::Expr::Bin3::op {
    using LT_T = rc_ptr<lang::cc::Node::Expr::Bin3::op::LT::_T>;
}

namespace lang::cc::Node::Expr::Bin3::op::GT {
    struct _T;
}

namespace lang::cc::Node::Expr::Bin3::op {
    using GT_T = rc_ptr<lang::cc::Node::Expr::Bin3::op::GT::_T>;
}

namespace lang::cc::Node::Expr::Bin3::op {
    struct _T;
}

namespace lang::cc::Node::Expr::Bin3 {
    using op_T = rc_ptr<lang::cc::Node::Expr::Bin3::op::_T>;
}

namespace lang::cc::Node::Expr::Bin3 {
    struct _T;
}

namespace lang::cc::Node::Expr {
    using Bin3_T = rc_ptr<lang::cc::Node::Expr::Bin3::_T>;
}

namespace lang::cc::Node::Expr::Bin4::op::SHL {
    struct _T;
}

namespace lang::cc::Node::Expr::Bin4::op {
    using SHL_T = rc_ptr<lang::cc::Node::Expr::Bin4::op::SHL::_T>;
}

namespace lang::cc::Node::Expr::Bin4::op {
    struct _T;
}

namespace lang::cc::Node::Expr::Bin4 {
    using op_T = rc_ptr<lang::cc::Node::Expr::Bin4::op::_T>;
}

namespace lang::cc::Node::Expr::Bin4 {
    struct _T;
}

namespace lang::cc::Node::Expr {
    using Bin4_T = rc_ptr<lang::cc::Node::Expr::Bin4::_T>;
}

namespace lang::cc::Node::Expr::Bin5::op::PLUS {
    struct _T;
}

namespace lang::cc::Node::Expr::Bin5::op {
    using PLUS_T = rc_ptr<lang::cc::Node::Expr::Bin5::op::PLUS::_T>;
}

namespace lang::cc::Node::Expr::Bin5::op::MINUS {
    struct _T;
}

namespace lang::cc::Node::Expr::Bin5::op {
    using MINUS_T = rc_ptr<lang::cc::Node::Expr::Bin5::op::MINUS::_T>;
}

namespace lang::cc::Node::Expr::Bin5::op {
    struct _T;
}

namespace lang::cc::Node::Expr::Bin5 {
    using op_T = rc_ptr<lang::cc::Node::Expr::Bin5::op::_T>;
}

namespace lang::cc::Node::Expr::Bin5 {
    struct _T;
}

namespace lang::cc::Node::Expr {
    using Bin5_T = rc_ptr<lang::cc::Node::Expr::Bin5::_T>;
}

namespace lang::cc::Node::Expr::Bin6::op::TIMES {
    struct _T;
}

namespace lang::cc::Node::Expr::Bin6::op {
    using TIMES_T = rc_ptr<lang::cc::Node::Expr::Bin6::op::TIMES::_T>;
}

namespace lang::cc::Node::Expr::Bin6::op::DIVIDE {
    struct _T;
}

namespace lang::cc::Node::Expr::Bin6::op {
    using DIVIDE_T = rc_ptr<lang::cc::Node::Expr::Bin6::op::DIVIDE::_T>;
}

namespace lang::cc::Node::Expr::Bin6::op::MODULO {
    struct _T;
}

namespace lang::cc::Node::Expr::Bin6::op {
    using MODULO_T = rc_ptr<lang::cc::Node::Expr::Bin6::op::MODULO::_T>;
}

namespace lang::cc::Node::Expr::Bin6::op {
    struct _T;
}

namespace lang::cc::Node::Expr::Bin6 {
    using op_T = rc_ptr<lang::cc::Node::Expr::Bin6::op::_T>;
}

namespace lang::cc::Node::Expr::Bin6 {
    struct _T;
}

namespace lang::cc::Node::Expr {
    using Bin6_T = rc_ptr<lang::cc::Node::Expr::Bin6::_T>;
}

namespace lang::cc::Node::Expr::Template {
    struct _T;
}

namespace lang::cc::Node::Expr {
    using Template_T = rc_ptr<lang::cc::Node::Expr::Template::_T>;
}

namespace lang::cc::Node::Expr::New {
    struct _T;
}

namespace lang::cc::Node::Expr {
    using New_T = rc_ptr<lang::cc::Node::Expr::New::_T>;
}

namespace lang::cc::Node::Expr::Delete {
    struct _T;
}

namespace lang::cc::Node::Expr {
    using Delete_T = rc_ptr<lang::cc::Node::Expr::Delete::_T>;
}

namespace lang::cc::Node::Expr::Ellipsis {
    struct _T;
}

namespace lang::cc::Node::Expr {
    using Ellipsis_T = rc_ptr<lang::cc::Node::Expr::Ellipsis::_T>;
}

namespace lang::cc::Node::Expr::Tilde {
    struct _T;
}

namespace lang::cc::Node::Expr {
    using Tilde_T = rc_ptr<lang::cc::Node::Expr::Tilde::_T>;
}

namespace lang::cc::Node::Expr::Namespace {
    struct _T;
}

namespace lang::cc::Node::Expr {
    using Namespace_T = rc_ptr<lang::cc::Node::Expr::Namespace::_T>;
}

namespace lang::cc::Node::Expr::Id {
    struct _T;
}

namespace lang::cc::Node::Expr {
    using Id_T = rc_ptr<lang::cc::Node::Expr::Id::_T>;
}

namespace lang::cc::Node::Expr::Lit::Integer {
    struct _T;
}

namespace lang::cc::Node::Expr::Lit {
    using Integer_T = rc_ptr<lang::cc::Node::Expr::Lit::Integer::_T>;
}

namespace lang::cc::Node::Expr::Lit::Str_ {
    struct _T;
}

namespace lang::cc::Node::Expr::Lit {
    using Str__T = rc_ptr<lang::cc::Node::Expr::Lit::Str_::_T>;
}

namespace lang::cc::Node::Expr::Lit::Array {
    struct _T;
}

namespace lang::cc::Node::Expr::Lit {
    using Array_T = rc_ptr<lang::cc::Node::Expr::Lit::Array::_T>;
}

namespace lang::cc::Node::Decl {
    struct _T;
}

namespace lang::cc::Node {
    using Decl_T = rc_ptr<lang::cc::Node::Decl::_T>;
}

namespace lang::cc::Node::StructDeclDef {
    struct _T;
}

namespace lang::cc::Node {
    using StructDeclDef_T = rc_ptr<lang::cc::Node::StructDeclDef::_T>;
}

namespace lang::cc::Node::Entry {
    struct _T;
}

namespace lang::cc::Node {
    using Entry_T = rc_ptr<lang::cc::Node::Entry::_T>;
}

namespace lang::cc::Node::FunDeclDef {
    struct _T;
}

namespace lang::cc::Node {
    using FunDeclDef_T = rc_ptr<lang::cc::Node::FunDeclDef::_T>;
}

namespace lang::cc::Node::Mod {
    struct _T;
}

namespace lang::cc::Node {
    using Mod_T = rc_ptr<lang::cc::Node::Mod::_T>;
}

namespace lang::cc::Node::Stmt {
    struct _T;
}

namespace lang::cc::Node {
    using Stmt_T = rc_ptr<lang::cc::Node::Stmt::_T>;
}

namespace lang::cc::Node::ExprExt {
    struct _T;
}

namespace lang::cc::Node {
    using ExprExt_T = rc_ptr<lang::cc::Node::ExprExt::_T>;
}

namespace lang::cc::Node::SwitchCase {
    struct _T;
}

namespace lang::cc::Node {
    using SwitchCase_T = rc_ptr<lang::cc::Node::SwitchCase::_T>;
}

namespace lang::cc::Node::Expr {
    struct _T;
}

namespace lang::cc::Node {
    using Expr_T = rc_ptr<lang::cc::Node::Expr::_T>;
}

namespace lang::cc::Node::Expr::Lit {
    struct _T;
}

namespace lang::cc::Node::Expr {
    using Lit_T = rc_ptr<lang::cc::Node::Expr::Lit::_T>;
}

namespace lang::cc::Node {
    struct _T;
}

namespace lang::cc {
    using Node_T = rc_ptr<lang::cc::Node::_T>;
}

void pr_debug(ostream& os, FmtFlags flags, lang::cc::Node_T x);

namespace lang::cc::Node {
    enum struct _W {
        Module,
        Decl__Struct__tmpl__args__item,
        Decl__Struct__tmpl,
        Entry__Fun__tmpl__args__item,
        Entry__Fun__tmpl,
        Param__val,
        Param,
        Decl__Fun__tmpl__args__item,
        Decl__Fun__tmpl,
        Decl__UsingAlias__tmpl__args__item,
        Decl__UsingAlias__tmpl,
        Block,
        TypedDecl__vars__item__val,
        TypedDecl__vars__item,
        TypedDecl,
        Expr__UnaryPre__op,
        Expr__IncDecPre__op,
        Expr__IncDecPost__op,
        Expr__Bin1__op,
        Expr__Bin2__op,
        Expr__Bin3__op,
        Expr__Bin4__op,
        Expr__Bin5__op,
        Expr__Bin6__op,
        Decl,
        StructDeclDef,
        Entry,
        FunDeclDef,
        Mod,
        Stmt,
        ExprExt,
        SwitchCase,
        Expr,
    };
}

namespace lang::cc::Node {
    struct _T: hash_obj, enable_rc_from_this_poly {
        void write(Ref<ostream> os, FmtFlags flags);
        void write(Ref<lang_rt::PrBufStream_T> pb);
        lang::cc::Node::_W w_;
        virtual ~_T();
        Int id_;
        lang_rt::TokenBounds bounds_;
        bool is_top_;
        lang_rt::ParserSymId sym_;
        lang_rt::ParserAttrMask attr_;
        lang_rt::ParserLookahead first_k_;
        _T(lang::cc::Node::_W w);
        bool is_Module();
        bool is_Decl__Struct__tmpl__args__item();
        bool is_Decl__Struct__tmpl();
        bool is_Entry__Fun__tmpl__args__item();
        bool is_Entry__Fun__tmpl();
        bool is_Param__val();
        bool is_Param();
        bool is_Decl__Fun__tmpl__args__item();
        bool is_Decl__Fun__tmpl();
        bool is_Decl__UsingAlias__tmpl__args__item();
        bool is_Decl__UsingAlias__tmpl();
        bool is_Block();
        bool is_TypedDecl__vars__item__val();
        bool is_TypedDecl__vars__item();
        bool is_TypedDecl();
        bool is_Expr__UnaryPre__op();
        bool is_Expr__IncDecPre__op();
        bool is_Expr__IncDecPost__op();
        bool is_Expr__Bin1__op();
        bool is_Expr__Bin2__op();
        bool is_Expr__Bin3__op();
        bool is_Expr__Bin4__op();
        bool is_Expr__Bin5__op();
        bool is_Expr__Bin6__op();
        bool is_Decl();
        bool is_StructDeclDef();
        bool is_Entry();
        bool is_FunDeclDef();
        bool is_Mod();
        bool is_Stmt();
        bool is_ExprExt();
        bool is_SwitchCase();
        bool is_Expr();
        lang::cc::Node::Module_T as_Module();
        lang::cc::Node::Decl::Struct::tmpl::args::item_T as_Decl__Struct__tmpl__args__item();
        lang::cc::Node::Decl::Struct::tmpl_T as_Decl__Struct__tmpl();
        lang::cc::Node::Entry::Fun::tmpl::args::item_T as_Entry__Fun__tmpl__args__item();
        lang::cc::Node::Entry::Fun::tmpl_T as_Entry__Fun__tmpl();
        lang::cc::Node::Param::val_T as_Param__val();
        lang::cc::Node::Param_T as_Param();
        lang::cc::Node::Decl::Fun::tmpl::args::item_T as_Decl__Fun__tmpl__args__item();
        lang::cc::Node::Decl::Fun::tmpl_T as_Decl__Fun__tmpl();
        lang::cc::Node::Decl::UsingAlias::tmpl::args::item_T as_Decl__UsingAlias__tmpl__args__item();
        lang::cc::Node::Decl::UsingAlias::tmpl_T as_Decl__UsingAlias__tmpl();
        lang::cc::Node::Block_T as_Block();
        lang::cc::Node::TypedDecl::vars::item::val_T as_TypedDecl__vars__item__val();
        lang::cc::Node::TypedDecl::vars::item_T as_TypedDecl__vars__item();
        lang::cc::Node::TypedDecl_T as_TypedDecl();
        lang::cc::Node::Expr::UnaryPre::op_T as_Expr__UnaryPre__op();
        lang::cc::Node::Expr::IncDecPre::op_T as_Expr__IncDecPre__op();
        lang::cc::Node::Expr::IncDecPost::op_T as_Expr__IncDecPost__op();
        lang::cc::Node::Expr::Bin1::op_T as_Expr__Bin1__op();
        lang::cc::Node::Expr::Bin2::op_T as_Expr__Bin2__op();
        lang::cc::Node::Expr::Bin3::op_T as_Expr__Bin3__op();
        lang::cc::Node::Expr::Bin4::op_T as_Expr__Bin4__op();
        lang::cc::Node::Expr::Bin5::op_T as_Expr__Bin5__op();
        lang::cc::Node::Expr::Bin6::op_T as_Expr__Bin6__op();
        lang::cc::Node::Decl_T as_Decl();
        lang::cc::Node::StructDeclDef_T as_StructDeclDef();
        lang::cc::Node::Entry_T as_Entry();
        lang::cc::Node::FunDeclDef_T as_FunDeclDef();
        lang::cc::Node::Mod_T as_Mod();
        lang::cc::Node::Stmt_T as_Stmt();
        lang::cc::Node::ExprExt_T as_ExprExt();
        lang::cc::Node::SwitchCase_T as_SwitchCase();
        lang::cc::Node::Expr_T as_Expr();
        void match(function<void(lang::cc::Node::Module_T)> f_Module, function<void(lang::cc::Node::Decl::Struct::tmpl::args::item_T)> f_Decl__Struct__tmpl__args__item, function<void(lang::cc::Node::Decl::Struct::tmpl_T)> f_Decl__Struct__tmpl, function<void(lang::cc::Node::Entry::Fun::tmpl::args::item_T)> f_Entry__Fun__tmpl__args__item, function<void(lang::cc::Node::Entry::Fun::tmpl_T)> f_Entry__Fun__tmpl, function<void(lang::cc::Node::Param::val_T)> f_Param__val, function<void(lang::cc::Node::Param_T)> f_Param, function<void(lang::cc::Node::Decl::Fun::tmpl::args::item_T)> f_Decl__Fun__tmpl__args__item, function<void(lang::cc::Node::Decl::Fun::tmpl_T)> f_Decl__Fun__tmpl, function<void(lang::cc::Node::Decl::UsingAlias::tmpl::args::item_T)> f_Decl__UsingAlias__tmpl__args__item, function<void(lang::cc::Node::Decl::UsingAlias::tmpl_T)> f_Decl__UsingAlias__tmpl, function<void(lang::cc::Node::Block_T)> f_Block, function<void(lang::cc::Node::TypedDecl::vars::item::val_T)> f_TypedDecl__vars__item__val, function<void(lang::cc::Node::TypedDecl::vars::item_T)> f_TypedDecl__vars__item, function<void(lang::cc::Node::TypedDecl_T)> f_TypedDecl, function<void(lang::cc::Node::Expr::UnaryPre::op_T)> f_Expr__UnaryPre__op, function<void(lang::cc::Node::Expr::IncDecPre::op_T)> f_Expr__IncDecPre__op, function<void(lang::cc::Node::Expr::IncDecPost::op_T)> f_Expr__IncDecPost__op, function<void(lang::cc::Node::Expr::Bin1::op_T)> f_Expr__Bin1__op, function<void(lang::cc::Node::Expr::Bin2::op_T)> f_Expr__Bin2__op, function<void(lang::cc::Node::Expr::Bin3::op_T)> f_Expr__Bin3__op, function<void(lang::cc::Node::Expr::Bin4::op_T)> f_Expr__Bin4__op, function<void(lang::cc::Node::Expr::Bin5::op_T)> f_Expr__Bin5__op, function<void(lang::cc::Node::Expr::Bin6::op_T)> f_Expr__Bin6__op, function<void(lang::cc::Node::Decl_T)> f_Decl, function<void(lang::cc::Node::StructDeclDef_T)> f_StructDeclDef, function<void(lang::cc::Node::Entry_T)> f_Entry, function<void(lang::cc::Node::FunDeclDef_T)> f_FunDeclDef, function<void(lang::cc::Node::Mod_T)> f_Mod, function<void(lang::cc::Node::Stmt_T)> f_Stmt, function<void(lang::cc::Node::ExprExt_T)> f_ExprExt, function<void(lang::cc::Node::SwitchCase_T)> f_SwitchCase, function<void(lang::cc::Node::Expr_T)> f_Expr);
        template<typename RetT> RetT match_expr(function<RetT(lang::cc::Node::Module_T)> f_Module, function<RetT(lang::cc::Node::Decl::Struct::tmpl::args::item_T)> f_Decl__Struct__tmpl__args__item, function<RetT(lang::cc::Node::Decl::Struct::tmpl_T)> f_Decl__Struct__tmpl, function<RetT(lang::cc::Node::Entry::Fun::tmpl::args::item_T)> f_Entry__Fun__tmpl__args__item, function<RetT(lang::cc::Node::Entry::Fun::tmpl_T)> f_Entry__Fun__tmpl, function<RetT(lang::cc::Node::Param::val_T)> f_Param__val, function<RetT(lang::cc::Node::Param_T)> f_Param, function<RetT(lang::cc::Node::Decl::Fun::tmpl::args::item_T)> f_Decl__Fun__tmpl__args__item, function<RetT(lang::cc::Node::Decl::Fun::tmpl_T)> f_Decl__Fun__tmpl, function<RetT(lang::cc::Node::Decl::UsingAlias::tmpl::args::item_T)> f_Decl__UsingAlias__tmpl__args__item, function<RetT(lang::cc::Node::Decl::UsingAlias::tmpl_T)> f_Decl__UsingAlias__tmpl, function<RetT(lang::cc::Node::Block_T)> f_Block, function<RetT(lang::cc::Node::TypedDecl::vars::item::val_T)> f_TypedDecl__vars__item__val, function<RetT(lang::cc::Node::TypedDecl::vars::item_T)> f_TypedDecl__vars__item, function<RetT(lang::cc::Node::TypedDecl_T)> f_TypedDecl, function<RetT(lang::cc::Node::Expr::UnaryPre::op_T)> f_Expr__UnaryPre__op, function<RetT(lang::cc::Node::Expr::IncDecPre::op_T)> f_Expr__IncDecPre__op, function<RetT(lang::cc::Node::Expr::IncDecPost::op_T)> f_Expr__IncDecPost__op, function<RetT(lang::cc::Node::Expr::Bin1::op_T)> f_Expr__Bin1__op, function<RetT(lang::cc::Node::Expr::Bin2::op_T)> f_Expr__Bin2__op, function<RetT(lang::cc::Node::Expr::Bin3::op_T)> f_Expr__Bin3__op, function<RetT(lang::cc::Node::Expr::Bin4::op_T)> f_Expr__Bin4__op, function<RetT(lang::cc::Node::Expr::Bin5::op_T)> f_Expr__Bin5__op, function<RetT(lang::cc::Node::Expr::Bin6::op_T)> f_Expr__Bin6__op, function<RetT(lang::cc::Node::Decl_T)> f_Decl, function<RetT(lang::cc::Node::StructDeclDef_T)> f_StructDeclDef, function<RetT(lang::cc::Node::Entry_T)> f_Entry, function<RetT(lang::cc::Node::FunDeclDef_T)> f_FunDeclDef, function<RetT(lang::cc::Node::Mod_T)> f_Mod, function<RetT(lang::cc::Node::Stmt_T)> f_Stmt, function<RetT(lang::cc::Node::ExprExt_T)> f_ExprExt, function<RetT(lang::cc::Node::SwitchCase_T)> f_SwitchCase, function<RetT(lang::cc::Node::Expr_T)> f_Expr);
        void hash_ser_acc_lang_cc_Node(SerBuf& buf) const;
        virtual void hash_ser_acc(SerBuf& buf) const = 0;
    };
}

template<typename RetT> RetT lang::cc::Node::_T::match_expr(function<RetT(lang::cc::Node::Module_T)> f_Module, function<RetT(lang::cc::Node::Decl::Struct::tmpl::args::item_T)> f_Decl__Struct__tmpl__args__item, function<RetT(lang::cc::Node::Decl::Struct::tmpl_T)> f_Decl__Struct__tmpl, function<RetT(lang::cc::Node::Entry::Fun::tmpl::args::item_T)> f_Entry__Fun__tmpl__args__item, function<RetT(lang::cc::Node::Entry::Fun::tmpl_T)> f_Entry__Fun__tmpl, function<RetT(lang::cc::Node::Param::val_T)> f_Param__val, function<RetT(lang::cc::Node::Param_T)> f_Param, function<RetT(lang::cc::Node::Decl::Fun::tmpl::args::item_T)> f_Decl__Fun__tmpl__args__item, function<RetT(lang::cc::Node::Decl::Fun::tmpl_T)> f_Decl__Fun__tmpl, function<RetT(lang::cc::Node::Decl::UsingAlias::tmpl::args::item_T)> f_Decl__UsingAlias__tmpl__args__item, function<RetT(lang::cc::Node::Decl::UsingAlias::tmpl_T)> f_Decl__UsingAlias__tmpl, function<RetT(lang::cc::Node::Block_T)> f_Block, function<RetT(lang::cc::Node::TypedDecl::vars::item::val_T)> f_TypedDecl__vars__item__val, function<RetT(lang::cc::Node::TypedDecl::vars::item_T)> f_TypedDecl__vars__item, function<RetT(lang::cc::Node::TypedDecl_T)> f_TypedDecl, function<RetT(lang::cc::Node::Expr::UnaryPre::op_T)> f_Expr__UnaryPre__op, function<RetT(lang::cc::Node::Expr::IncDecPre::op_T)> f_Expr__IncDecPre__op, function<RetT(lang::cc::Node::Expr::IncDecPost::op_T)> f_Expr__IncDecPost__op, function<RetT(lang::cc::Node::Expr::Bin1::op_T)> f_Expr__Bin1__op, function<RetT(lang::cc::Node::Expr::Bin2::op_T)> f_Expr__Bin2__op, function<RetT(lang::cc::Node::Expr::Bin3::op_T)> f_Expr__Bin3__op, function<RetT(lang::cc::Node::Expr::Bin4::op_T)> f_Expr__Bin4__op, function<RetT(lang::cc::Node::Expr::Bin5::op_T)> f_Expr__Bin5__op, function<RetT(lang::cc::Node::Expr::Bin6::op_T)> f_Expr__Bin6__op, function<RetT(lang::cc::Node::Decl_T)> f_Decl, function<RetT(lang::cc::Node::StructDeclDef_T)> f_StructDeclDef, function<RetT(lang::cc::Node::Entry_T)> f_Entry, function<RetT(lang::cc::Node::FunDeclDef_T)> f_FunDeclDef, function<RetT(lang::cc::Node::Mod_T)> f_Mod, function<RetT(lang::cc::Node::Stmt_T)> f_Stmt, function<RetT(lang::cc::Node::ExprExt_T)> f_ExprExt, function<RetT(lang::cc::Node::SwitchCase_T)> f_SwitchCase, function<RetT(lang::cc::Node::Expr_T)> f_Expr) {
    switch (this->w_) {
        case lang::cc::Node::_W::Module: {
            return f_Module(this->as_Module());
            break;
        }
        case lang::cc::Node::_W::Decl__Struct__tmpl__args__item: {
            return f_Decl__Struct__tmpl__args__item(this->as_Decl__Struct__tmpl__args__item());
            break;
        }
        case lang::cc::Node::_W::Decl__Struct__tmpl: {
            return f_Decl__Struct__tmpl(this->as_Decl__Struct__tmpl());
            break;
        }
        case lang::cc::Node::_W::Entry__Fun__tmpl__args__item: {
            return f_Entry__Fun__tmpl__args__item(this->as_Entry__Fun__tmpl__args__item());
            break;
        }
        case lang::cc::Node::_W::Entry__Fun__tmpl: {
            return f_Entry__Fun__tmpl(this->as_Entry__Fun__tmpl());
            break;
        }
        case lang::cc::Node::_W::Param__val: {
            return f_Param__val(this->as_Param__val());
            break;
        }
        case lang::cc::Node::_W::Param: {
            return f_Param(this->as_Param());
            break;
        }
        case lang::cc::Node::_W::Decl__Fun__tmpl__args__item: {
            return f_Decl__Fun__tmpl__args__item(this->as_Decl__Fun__tmpl__args__item());
            break;
        }
        case lang::cc::Node::_W::Decl__Fun__tmpl: {
            return f_Decl__Fun__tmpl(this->as_Decl__Fun__tmpl());
            break;
        }
        case lang::cc::Node::_W::Decl__UsingAlias__tmpl__args__item: {
            return f_Decl__UsingAlias__tmpl__args__item(this->as_Decl__UsingAlias__tmpl__args__item());
            break;
        }
        case lang::cc::Node::_W::Decl__UsingAlias__tmpl: {
            return f_Decl__UsingAlias__tmpl(this->as_Decl__UsingAlias__tmpl());
            break;
        }
        case lang::cc::Node::_W::Block: {
            return f_Block(this->as_Block());
            break;
        }
        case lang::cc::Node::_W::TypedDecl__vars__item__val: {
            return f_TypedDecl__vars__item__val(this->as_TypedDecl__vars__item__val());
            break;
        }
        case lang::cc::Node::_W::TypedDecl__vars__item: {
            return f_TypedDecl__vars__item(this->as_TypedDecl__vars__item());
            break;
        }
        case lang::cc::Node::_W::TypedDecl: {
            return f_TypedDecl(this->as_TypedDecl());
            break;
        }
        case lang::cc::Node::_W::Expr__UnaryPre__op: {
            return f_Expr__UnaryPre__op(this->as_Expr__UnaryPre__op());
            break;
        }
        case lang::cc::Node::_W::Expr__IncDecPre__op: {
            return f_Expr__IncDecPre__op(this->as_Expr__IncDecPre__op());
            break;
        }
        case lang::cc::Node::_W::Expr__IncDecPost__op: {
            return f_Expr__IncDecPost__op(this->as_Expr__IncDecPost__op());
            break;
        }
        case lang::cc::Node::_W::Expr__Bin1__op: {
            return f_Expr__Bin1__op(this->as_Expr__Bin1__op());
            break;
        }
        case lang::cc::Node::_W::Expr__Bin2__op: {
            return f_Expr__Bin2__op(this->as_Expr__Bin2__op());
            break;
        }
        case lang::cc::Node::_W::Expr__Bin3__op: {
            return f_Expr__Bin3__op(this->as_Expr__Bin3__op());
            break;
        }
        case lang::cc::Node::_W::Expr__Bin4__op: {
            return f_Expr__Bin4__op(this->as_Expr__Bin4__op());
            break;
        }
        case lang::cc::Node::_W::Expr__Bin5__op: {
            return f_Expr__Bin5__op(this->as_Expr__Bin5__op());
            break;
        }
        case lang::cc::Node::_W::Expr__Bin6__op: {
            return f_Expr__Bin6__op(this->as_Expr__Bin6__op());
            break;
        }
        case lang::cc::Node::_W::Decl: {
            return f_Decl(this->as_Decl());
            break;
        }
        case lang::cc::Node::_W::StructDeclDef: {
            return f_StructDeclDef(this->as_StructDeclDef());
            break;
        }
        case lang::cc::Node::_W::Entry: {
            return f_Entry(this->as_Entry());
            break;
        }
        case lang::cc::Node::_W::FunDeclDef: {
            return f_FunDeclDef(this->as_FunDeclDef());
            break;
        }
        case lang::cc::Node::_W::Mod: {
            return f_Mod(this->as_Mod());
            break;
        }
        case lang::cc::Node::_W::Stmt: {
            return f_Stmt(this->as_Stmt());
            break;
        }
        case lang::cc::Node::_W::ExprExt: {
            return f_ExprExt(this->as_ExprExt());
            break;
        }
        case lang::cc::Node::_W::SwitchCase: {
            return f_SwitchCase(this->as_SwitchCase());
            break;
        }
        case lang::cc::Node::_W::Expr: {
            return f_Expr(this->as_Expr());
            break;
        }
        default: {
            AX();
        }
    }
}

void pr_debug(ostream& os, FmtFlags flags, lang::cc::Node::Module_T x);

namespace lang::cc::Node::Module {
    lang::cc::Node::Module_T make(Int id, lang_rt::TokenBounds bounds, bool is_top, lang_rt::ParserSymId sym, lang_rt::ParserAttrMask attr, lang_rt::ParserLookahead first_k, Vec_T<lang::cc::Node::Decl_T> decls);
}

namespace lang::cc::Node::Module {
    lang::cc::Node::Module_T make_ext(ArenaPtr arena, Int id, lang_rt::TokenBounds bounds, bool is_top, lang_rt::ParserSymId sym, lang_rt::ParserAttrMask attr, lang_rt::ParserLookahead first_k, Vec_T<lang::cc::Node::Decl_T> decls);
}

namespace lang::cc::Node::Module {
    struct _T: lang::cc::Node::_T {
        void write(Ref<ostream> os, FmtFlags flags);
        void write(Ref<lang_rt::PrBufStream_T> pb);
        Vec_T<lang::cc::Node::Decl_T> decls_;
        _T();
        lang::cc::Node::Module_T with_id(Int id);
        lang::cc::Node::Module_T with_bounds(lang_rt::TokenBounds bounds);
        lang::cc::Node::Module_T with_is_top(bool is_top);
        lang::cc::Node::Module_T with_sym(lang_rt::ParserSymId sym);
        lang::cc::Node::Module_T with_attr(lang_rt::ParserAttrMask attr);
        lang::cc::Node::Module_T with_first_k(lang_rt::ParserLookahead first_k);
        lang::cc::Node::Module_T with_decls(Vec_T<lang::cc::Node::Decl_T> decls);
        void hash_ser_acc_lang_cc_Node_Module(SerBuf& buf) const;
        virtual void hash_ser_acc(SerBuf& buf) const;
    };
}

void pr_debug(ostream& os, FmtFlags flags, lang::cc::Node::Param_T x);

namespace lang::cc::Node::Param {
    lang::cc::Node::Param_T make(Int id, lang_rt::TokenBounds bounds, bool is_top, lang_rt::ParserSymId sym, lang_rt::ParserAttrMask attr, lang_rt::ParserLookahead first_k, Vec_T<lang::cc::Node::Mod_T> mods, lang::cc::Node::Expr_T type_, lang::cc::Node::Expr_T name, Option_T<lang::cc::Node::Param::val_T> val);
}

namespace lang::cc::Node::Param {
    lang::cc::Node::Param_T make_ext(ArenaPtr arena, Int id, lang_rt::TokenBounds bounds, bool is_top, lang_rt::ParserSymId sym, lang_rt::ParserAttrMask attr, lang_rt::ParserLookahead first_k, Vec_T<lang::cc::Node::Mod_T> mods, lang::cc::Node::Expr_T type_, lang::cc::Node::Expr_T name, Option_T<lang::cc::Node::Param::val_T> val);
}

namespace lang::cc::Node::Param {
    struct _T: lang::cc::Node::_T {
        void write(Ref<ostream> os, FmtFlags flags);
        void write(Ref<lang_rt::PrBufStream_T> pb);
        Vec_T<lang::cc::Node::Mod_T> mods_;
        lang::cc::Node::Expr_T type__;
        lang::cc::Node::Expr_T name_;
        Option_T<lang::cc::Node::Param::val_T> val_;
        _T();
        lang::cc::Node::Param_T with_id(Int id);
        lang::cc::Node::Param_T with_bounds(lang_rt::TokenBounds bounds);
        lang::cc::Node::Param_T with_is_top(bool is_top);
        lang::cc::Node::Param_T with_sym(lang_rt::ParserSymId sym);
        lang::cc::Node::Param_T with_attr(lang_rt::ParserAttrMask attr);
        lang::cc::Node::Param_T with_first_k(lang_rt::ParserLookahead first_k);
        lang::cc::Node::Param_T with_mods(Vec_T<lang::cc::Node::Mod_T> mods);
        lang::cc::Node::Param_T with_type_(lang::cc::Node::Expr_T type_);
        lang::cc::Node::Param_T with_name(lang::cc::Node::Expr_T name);
        lang::cc::Node::Param_T with_val(Option_T<lang::cc::Node::Param::val_T> val);
        void hash_ser_acc_lang_cc_Node_Param(SerBuf& buf) const;
        virtual void hash_ser_acc(SerBuf& buf) const;
    };
}

void pr_debug(ostream& os, FmtFlags flags, lang::cc::Node::Block_T x);

namespace lang::cc::Node::Block {
    lang::cc::Node::Block_T make(Int id, lang_rt::TokenBounds bounds, bool is_top, lang_rt::ParserSymId sym, lang_rt::ParserAttrMask attr, lang_rt::ParserLookahead first_k, Vec_T<lang::cc::Node::Stmt_T> stmts);
}

namespace lang::cc::Node::Block {
    lang::cc::Node::Block_T make_ext(ArenaPtr arena, Int id, lang_rt::TokenBounds bounds, bool is_top, lang_rt::ParserSymId sym, lang_rt::ParserAttrMask attr, lang_rt::ParserLookahead first_k, Vec_T<lang::cc::Node::Stmt_T> stmts);
}

namespace lang::cc::Node::Block {
    struct _T: lang::cc::Node::_T {
        void write(Ref<ostream> os, FmtFlags flags);
        void write(Ref<lang_rt::PrBufStream_T> pb);
        Vec_T<lang::cc::Node::Stmt_T> stmts_;
        _T();
        lang::cc::Node::Block_T with_id(Int id);
        lang::cc::Node::Block_T with_bounds(lang_rt::TokenBounds bounds);
        lang::cc::Node::Block_T with_is_top(bool is_top);
        lang::cc::Node::Block_T with_sym(lang_rt::ParserSymId sym);
        lang::cc::Node::Block_T with_attr(lang_rt::ParserAttrMask attr);
        lang::cc::Node::Block_T with_first_k(lang_rt::ParserLookahead first_k);
        lang::cc::Node::Block_T with_stmts(Vec_T<lang::cc::Node::Stmt_T> stmts);
        void hash_ser_acc_lang_cc_Node_Block(SerBuf& buf) const;
        virtual void hash_ser_acc(SerBuf& buf) const;
    };
}

void pr_debug(ostream& os, FmtFlags flags, lang::cc::Node::TypedDecl_T x);

namespace lang::cc::Node::TypedDecl {
    lang::cc::Node::TypedDecl_T make(Int id, lang_rt::TokenBounds bounds, bool is_top, lang_rt::ParserSymId sym, lang_rt::ParserAttrMask attr, lang_rt::ParserLookahead first_k, Vec_T<lang::cc::Node::Mod_T> mods, lang::cc::Node::Expr_T type_, Vec_T<lang::cc::Node::TypedDecl::vars::item_T> vars);
}

namespace lang::cc::Node::TypedDecl {
    lang::cc::Node::TypedDecl_T make_ext(ArenaPtr arena, Int id, lang_rt::TokenBounds bounds, bool is_top, lang_rt::ParserSymId sym, lang_rt::ParserAttrMask attr, lang_rt::ParserLookahead first_k, Vec_T<lang::cc::Node::Mod_T> mods, lang::cc::Node::Expr_T type_, Vec_T<lang::cc::Node::TypedDecl::vars::item_T> vars);
}

namespace lang::cc::Node::TypedDecl {
    struct _T: lang::cc::Node::_T {
        void write(Ref<ostream> os, FmtFlags flags);
        void write(Ref<lang_rt::PrBufStream_T> pb);
        Vec_T<lang::cc::Node::Mod_T> mods_;
        lang::cc::Node::Expr_T type__;
        Vec_T<lang::cc::Node::TypedDecl::vars::item_T> vars_;
        _T();
        lang::cc::Node::TypedDecl_T with_id(Int id);
        lang::cc::Node::TypedDecl_T with_bounds(lang_rt::TokenBounds bounds);
        lang::cc::Node::TypedDecl_T with_is_top(bool is_top);
        lang::cc::Node::TypedDecl_T with_sym(lang_rt::ParserSymId sym);
        lang::cc::Node::TypedDecl_T with_attr(lang_rt::ParserAttrMask attr);
        lang::cc::Node::TypedDecl_T with_first_k(lang_rt::ParserLookahead first_k);
        lang::cc::Node::TypedDecl_T with_mods(Vec_T<lang::cc::Node::Mod_T> mods);
        lang::cc::Node::TypedDecl_T with_type_(lang::cc::Node::Expr_T type_);
        lang::cc::Node::TypedDecl_T with_vars(Vec_T<lang::cc::Node::TypedDecl::vars::item_T> vars);
        void hash_ser_acc_lang_cc_Node_TypedDecl(SerBuf& buf) const;
        virtual void hash_ser_acc(SerBuf& buf) const;
    };
}

void pr_debug(ostream& os, FmtFlags flags, lang::cc::Node::Decl_T x);

namespace lang::cc::Node::Decl {
    enum struct _W {
        Struct,
        EnumStruct,
        Fun,
        Namespace,
        UsingAlias,
        UsingNamespace,
        Include,
        PragmaOnce,
    };
}

namespace lang::cc::Node::Decl {
    struct _T: lang::cc::Node::_T {
        void write(Ref<ostream> os, FmtFlags flags);
        void write(Ref<lang_rt::PrBufStream_T> pb);
        lang::cc::Node::Decl::_W w_;
        virtual ~_T();
        _T(lang::cc::Node::Decl::_W w);
        bool is_Struct();
        bool is_EnumStruct();
        bool is_Fun();
        bool is_Namespace();
        bool is_UsingAlias();
        bool is_UsingNamespace();
        bool is_Include();
        bool is_PragmaOnce();
        lang::cc::Node::Decl::Struct_T as_Struct();
        lang::cc::Node::Decl::EnumStruct_T as_EnumStruct();
        lang::cc::Node::Decl::Fun_T as_Fun();
        lang::cc::Node::Decl::Namespace_T as_Namespace();
        lang::cc::Node::Decl::UsingAlias_T as_UsingAlias();
        lang::cc::Node::Decl::UsingNamespace_T as_UsingNamespace();
        lang::cc::Node::Decl::Include_T as_Include();
        lang::cc::Node::Decl::PragmaOnce_T as_PragmaOnce();
        void match(function<void(lang::cc::Node::Decl::Struct_T)> f_Struct, function<void(lang::cc::Node::Decl::EnumStruct_T)> f_EnumStruct, function<void(lang::cc::Node::Decl::Fun_T)> f_Fun, function<void(lang::cc::Node::Decl::Namespace_T)> f_Namespace, function<void(lang::cc::Node::Decl::UsingAlias_T)> f_UsingAlias, function<void(lang::cc::Node::Decl::UsingNamespace_T)> f_UsingNamespace, function<void(lang::cc::Node::Decl::Include_T)> f_Include, function<void(lang::cc::Node::Decl::PragmaOnce_T)> f_PragmaOnce);
        template<typename RetT> RetT match_expr(function<RetT(lang::cc::Node::Decl::Struct_T)> f_Struct, function<RetT(lang::cc::Node::Decl::EnumStruct_T)> f_EnumStruct, function<RetT(lang::cc::Node::Decl::Fun_T)> f_Fun, function<RetT(lang::cc::Node::Decl::Namespace_T)> f_Namespace, function<RetT(lang::cc::Node::Decl::UsingAlias_T)> f_UsingAlias, function<RetT(lang::cc::Node::Decl::UsingNamespace_T)> f_UsingNamespace, function<RetT(lang::cc::Node::Decl::Include_T)> f_Include, function<RetT(lang::cc::Node::Decl::PragmaOnce_T)> f_PragmaOnce);
        void hash_ser_acc_lang_cc_Node_Decl(SerBuf& buf) const;
        virtual void hash_ser_acc(SerBuf& buf) const = 0;
    };
}

template<typename RetT> RetT lang::cc::Node::Decl::_T::match_expr(function<RetT(lang::cc::Node::Decl::Struct_T)> f_Struct, function<RetT(lang::cc::Node::Decl::EnumStruct_T)> f_EnumStruct, function<RetT(lang::cc::Node::Decl::Fun_T)> f_Fun, function<RetT(lang::cc::Node::Decl::Namespace_T)> f_Namespace, function<RetT(lang::cc::Node::Decl::UsingAlias_T)> f_UsingAlias, function<RetT(lang::cc::Node::Decl::UsingNamespace_T)> f_UsingNamespace, function<RetT(lang::cc::Node::Decl::Include_T)> f_Include, function<RetT(lang::cc::Node::Decl::PragmaOnce_T)> f_PragmaOnce) {
    switch (this->w_) {
        case lang::cc::Node::Decl::_W::Struct: {
            return f_Struct(this->as_Struct());
            break;
        }
        case lang::cc::Node::Decl::_W::EnumStruct: {
            return f_EnumStruct(this->as_EnumStruct());
            break;
        }
        case lang::cc::Node::Decl::_W::Fun: {
            return f_Fun(this->as_Fun());
            break;
        }
        case lang::cc::Node::Decl::_W::Namespace: {
            return f_Namespace(this->as_Namespace());
            break;
        }
        case lang::cc::Node::Decl::_W::UsingAlias: {
            return f_UsingAlias(this->as_UsingAlias());
            break;
        }
        case lang::cc::Node::Decl::_W::UsingNamespace: {
            return f_UsingNamespace(this->as_UsingNamespace());
            break;
        }
        case lang::cc::Node::Decl::_W::Include: {
            return f_Include(this->as_Include());
            break;
        }
        case lang::cc::Node::Decl::_W::PragmaOnce: {
            return f_PragmaOnce(this->as_PragmaOnce());
            break;
        }
        default: {
            AX();
        }
    }
}

void pr_debug(ostream& os, FmtFlags flags, lang::cc::Node::StructDeclDef_T x);

namespace lang::cc::Node::StructDeclDef {
    enum struct _W {
        Decl,
        Def,
    };
}

namespace lang::cc::Node::StructDeclDef {
    struct _T: lang::cc::Node::_T {
        void write(Ref<ostream> os, FmtFlags flags);
        void write(Ref<lang_rt::PrBufStream_T> pb);
        lang::cc::Node::StructDeclDef::_W w_;
        virtual ~_T();
        _T(lang::cc::Node::StructDeclDef::_W w);
        bool is_Decl();
        bool is_Def();
        lang::cc::Node::StructDeclDef::Decl_T as_Decl();
        lang::cc::Node::StructDeclDef::Def_T as_Def();
        void match(function<void(lang::cc::Node::StructDeclDef::Decl_T)> f_Decl, function<void(lang::cc::Node::StructDeclDef::Def_T)> f_Def);
        template<typename RetT> RetT match_expr(function<RetT(lang::cc::Node::StructDeclDef::Decl_T)> f_Decl, function<RetT(lang::cc::Node::StructDeclDef::Def_T)> f_Def);
        void hash_ser_acc_lang_cc_Node_StructDeclDef(SerBuf& buf) const;
        virtual void hash_ser_acc(SerBuf& buf) const = 0;
    };
}

template<typename RetT> RetT lang::cc::Node::StructDeclDef::_T::match_expr(function<RetT(lang::cc::Node::StructDeclDef::Decl_T)> f_Decl, function<RetT(lang::cc::Node::StructDeclDef::Def_T)> f_Def) {
    switch (this->w_) {
        case lang::cc::Node::StructDeclDef::_W::Decl: {
            return f_Decl(this->as_Decl());
            break;
        }
        case lang::cc::Node::StructDeclDef::_W::Def: {
            return f_Def(this->as_Def());
            break;
        }
        default: {
            AX();
        }
    }
}

void pr_debug(ostream& os, FmtFlags flags, lang::cc::Node::Entry_T x);

namespace lang::cc::Node::Entry {
    enum struct _W {
        Field,
        Fun,
    };
}

namespace lang::cc::Node::Entry {
    struct _T: lang::cc::Node::_T {
        void write(Ref<ostream> os, FmtFlags flags);
        void write(Ref<lang_rt::PrBufStream_T> pb);
        lang::cc::Node::Entry::_W w_;
        virtual ~_T();
        _T(lang::cc::Node::Entry::_W w);
        bool is_Field();
        bool is_Fun();
        lang::cc::Node::Entry::Field_T as_Field();
        lang::cc::Node::Entry::Fun_T as_Fun();
        void match(function<void(lang::cc::Node::Entry::Field_T)> f_Field, function<void(lang::cc::Node::Entry::Fun_T)> f_Fun);
        template<typename RetT> RetT match_expr(function<RetT(lang::cc::Node::Entry::Field_T)> f_Field, function<RetT(lang::cc::Node::Entry::Fun_T)> f_Fun);
        void hash_ser_acc_lang_cc_Node_Entry(SerBuf& buf) const;
        virtual void hash_ser_acc(SerBuf& buf) const = 0;
    };
}

template<typename RetT> RetT lang::cc::Node::Entry::_T::match_expr(function<RetT(lang::cc::Node::Entry::Field_T)> f_Field, function<RetT(lang::cc::Node::Entry::Fun_T)> f_Fun) {
    switch (this->w_) {
        case lang::cc::Node::Entry::_W::Field: {
            return f_Field(this->as_Field());
            break;
        }
        case lang::cc::Node::Entry::_W::Fun: {
            return f_Fun(this->as_Fun());
            break;
        }
        default: {
            AX();
        }
    }
}

void pr_debug(ostream& os, FmtFlags flags, lang::cc::Node::FunDeclDef_T x);

namespace lang::cc::Node::FunDeclDef {
    enum struct _W {
        Decl,
        Def,
        Del,
        Zero,
    };
}

namespace lang::cc::Node::FunDeclDef {
    struct _T: lang::cc::Node::_T {
        void write(Ref<ostream> os, FmtFlags flags);
        void write(Ref<lang_rt::PrBufStream_T> pb);
        lang::cc::Node::FunDeclDef::_W w_;
        virtual ~_T();
        _T(lang::cc::Node::FunDeclDef::_W w);
        bool is_Decl();
        bool is_Def();
        bool is_Del();
        bool is_Zero();
        lang::cc::Node::FunDeclDef::Decl_T as_Decl();
        lang::cc::Node::FunDeclDef::Def_T as_Def();
        lang::cc::Node::FunDeclDef::Del_T as_Del();
        lang::cc::Node::FunDeclDef::Zero_T as_Zero();
        void match(function<void(lang::cc::Node::FunDeclDef::Decl_T)> f_Decl, function<void(lang::cc::Node::FunDeclDef::Def_T)> f_Def, function<void(lang::cc::Node::FunDeclDef::Del_T)> f_Del, function<void(lang::cc::Node::FunDeclDef::Zero_T)> f_Zero);
        template<typename RetT> RetT match_expr(function<RetT(lang::cc::Node::FunDeclDef::Decl_T)> f_Decl, function<RetT(lang::cc::Node::FunDeclDef::Def_T)> f_Def, function<RetT(lang::cc::Node::FunDeclDef::Del_T)> f_Del, function<RetT(lang::cc::Node::FunDeclDef::Zero_T)> f_Zero);
        void hash_ser_acc_lang_cc_Node_FunDeclDef(SerBuf& buf) const;
        virtual void hash_ser_acc(SerBuf& buf) const = 0;
    };
}

template<typename RetT> RetT lang::cc::Node::FunDeclDef::_T::match_expr(function<RetT(lang::cc::Node::FunDeclDef::Decl_T)> f_Decl, function<RetT(lang::cc::Node::FunDeclDef::Def_T)> f_Def, function<RetT(lang::cc::Node::FunDeclDef::Del_T)> f_Del, function<RetT(lang::cc::Node::FunDeclDef::Zero_T)> f_Zero) {
    switch (this->w_) {
        case lang::cc::Node::FunDeclDef::_W::Decl: {
            return f_Decl(this->as_Decl());
            break;
        }
        case lang::cc::Node::FunDeclDef::_W::Def: {
            return f_Def(this->as_Def());
            break;
        }
        case lang::cc::Node::FunDeclDef::_W::Del: {
            return f_Del(this->as_Del());
            break;
        }
        case lang::cc::Node::FunDeclDef::_W::Zero: {
            return f_Zero(this->as_Zero());
            break;
        }
        default: {
            AX();
        }
    }
}

void pr_debug(ostream& os, FmtFlags flags, lang::cc::Node::Mod_T x);

namespace lang::cc::Node::Mod {
    enum struct _W {
        Const,
        Inline,
        Static,
        Virtual,
        NoInline,
        AlwaysInline,
    };
}

namespace lang::cc::Node::Mod {
    struct _T: lang::cc::Node::_T {
        void write(Ref<ostream> os, FmtFlags flags);
        void write(Ref<lang_rt::PrBufStream_T> pb);
        lang::cc::Node::Mod::_W w_;
        virtual ~_T();
        _T(lang::cc::Node::Mod::_W w);
        bool is_Const();
        bool is_Inline();
        bool is_Static();
        bool is_Virtual();
        bool is_NoInline();
        bool is_AlwaysInline();
        lang::cc::Node::Mod::Const_T as_Const();
        lang::cc::Node::Mod::Inline_T as_Inline();
        lang::cc::Node::Mod::Static_T as_Static();
        lang::cc::Node::Mod::Virtual_T as_Virtual();
        lang::cc::Node::Mod::NoInline_T as_NoInline();
        lang::cc::Node::Mod::AlwaysInline_T as_AlwaysInline();
        void match(function<void(lang::cc::Node::Mod::Const_T)> f_Const, function<void(lang::cc::Node::Mod::Inline_T)> f_Inline, function<void(lang::cc::Node::Mod::Static_T)> f_Static, function<void(lang::cc::Node::Mod::Virtual_T)> f_Virtual, function<void(lang::cc::Node::Mod::NoInline_T)> f_NoInline, function<void(lang::cc::Node::Mod::AlwaysInline_T)> f_AlwaysInline);
        template<typename RetT> RetT match_expr(function<RetT(lang::cc::Node::Mod::Const_T)> f_Const, function<RetT(lang::cc::Node::Mod::Inline_T)> f_Inline, function<RetT(lang::cc::Node::Mod::Static_T)> f_Static, function<RetT(lang::cc::Node::Mod::Virtual_T)> f_Virtual, function<RetT(lang::cc::Node::Mod::NoInline_T)> f_NoInline, function<RetT(lang::cc::Node::Mod::AlwaysInline_T)> f_AlwaysInline);
        void hash_ser_acc_lang_cc_Node_Mod(SerBuf& buf) const;
        virtual void hash_ser_acc(SerBuf& buf) const = 0;
    };
}

template<typename RetT> RetT lang::cc::Node::Mod::_T::match_expr(function<RetT(lang::cc::Node::Mod::Const_T)> f_Const, function<RetT(lang::cc::Node::Mod::Inline_T)> f_Inline, function<RetT(lang::cc::Node::Mod::Static_T)> f_Static, function<RetT(lang::cc::Node::Mod::Virtual_T)> f_Virtual, function<RetT(lang::cc::Node::Mod::NoInline_T)> f_NoInline, function<RetT(lang::cc::Node::Mod::AlwaysInline_T)> f_AlwaysInline) {
    switch (this->w_) {
        case lang::cc::Node::Mod::_W::Const: {
            return f_Const(this->as_Const());
            break;
        }
        case lang::cc::Node::Mod::_W::Inline: {
            return f_Inline(this->as_Inline());
            break;
        }
        case lang::cc::Node::Mod::_W::Static: {
            return f_Static(this->as_Static());
            break;
        }
        case lang::cc::Node::Mod::_W::Virtual: {
            return f_Virtual(this->as_Virtual());
            break;
        }
        case lang::cc::Node::Mod::_W::NoInline: {
            return f_NoInline(this->as_NoInline());
            break;
        }
        case lang::cc::Node::Mod::_W::AlwaysInline: {
            return f_AlwaysInline(this->as_AlwaysInline());
            break;
        }
        default: {
            AX();
        }
    }
}

void pr_debug(ostream& os, FmtFlags flags, lang::cc::Node::Stmt_T x);

namespace lang::cc::Node::Stmt {
    enum struct _W {
        Decl,
        Expr,
        Block,
        If,
        IfElse,
        For,
        Switch,
        Break,
        Continue,
        Return,
    };
}

namespace lang::cc::Node::Stmt {
    struct _T: lang::cc::Node::_T {
        void write(Ref<ostream> os, FmtFlags flags);
        void write(Ref<lang_rt::PrBufStream_T> pb);
        lang::cc::Node::Stmt::_W w_;
        virtual ~_T();
        _T(lang::cc::Node::Stmt::_W w);
        bool is_Decl();
        bool is_Expr();
        bool is_Block();
        bool is_If();
        bool is_IfElse();
        bool is_For();
        bool is_Switch();
        bool is_Break();
        bool is_Continue();
        bool is_Return();
        lang::cc::Node::Stmt::Decl_T as_Decl();
        lang::cc::Node::Stmt::Expr_T as_Expr();
        lang::cc::Node::Stmt::Block_T as_Block();
        lang::cc::Node::Stmt::If_T as_If();
        lang::cc::Node::Stmt::IfElse_T as_IfElse();
        lang::cc::Node::Stmt::For_T as_For();
        lang::cc::Node::Stmt::Switch_T as_Switch();
        lang::cc::Node::Stmt::Break_T as_Break();
        lang::cc::Node::Stmt::Continue_T as_Continue();
        lang::cc::Node::Stmt::Return_T as_Return();
        void match(function<void(lang::cc::Node::Stmt::Decl_T)> f_Decl, function<void(lang::cc::Node::Stmt::Expr_T)> f_Expr, function<void(lang::cc::Node::Stmt::Block_T)> f_Block, function<void(lang::cc::Node::Stmt::If_T)> f_If, function<void(lang::cc::Node::Stmt::IfElse_T)> f_IfElse, function<void(lang::cc::Node::Stmt::For_T)> f_For, function<void(lang::cc::Node::Stmt::Switch_T)> f_Switch, function<void(lang::cc::Node::Stmt::Break_T)> f_Break, function<void(lang::cc::Node::Stmt::Continue_T)> f_Continue, function<void(lang::cc::Node::Stmt::Return_T)> f_Return);
        template<typename RetT> RetT match_expr(function<RetT(lang::cc::Node::Stmt::Decl_T)> f_Decl, function<RetT(lang::cc::Node::Stmt::Expr_T)> f_Expr, function<RetT(lang::cc::Node::Stmt::Block_T)> f_Block, function<RetT(lang::cc::Node::Stmt::If_T)> f_If, function<RetT(lang::cc::Node::Stmt::IfElse_T)> f_IfElse, function<RetT(lang::cc::Node::Stmt::For_T)> f_For, function<RetT(lang::cc::Node::Stmt::Switch_T)> f_Switch, function<RetT(lang::cc::Node::Stmt::Break_T)> f_Break, function<RetT(lang::cc::Node::Stmt::Continue_T)> f_Continue, function<RetT(lang::cc::Node::Stmt::Return_T)> f_Return);
        void hash_ser_acc_lang_cc_Node_Stmt(SerBuf& buf) const;
        virtual void hash_ser_acc(SerBuf& buf) const = 0;
    };
}

template<typename RetT> RetT lang::cc::Node::Stmt::_T::match_expr(function<RetT(lang::cc::Node::Stmt::Decl_T)> f_Decl, function<RetT(lang::cc::Node::Stmt::Expr_T)> f_Expr, function<RetT(lang::cc::Node::Stmt::Block_T)> f_Block, function<RetT(lang::cc::Node::Stmt::If_T)> f_If, function<RetT(lang::cc::Node::Stmt::IfElse_T)> f_IfElse, function<RetT(lang::cc::Node::Stmt::For_T)> f_For, function<RetT(lang::cc::Node::Stmt::Switch_T)> f_Switch, function<RetT(lang::cc::Node::Stmt::Break_T)> f_Break, function<RetT(lang::cc::Node::Stmt::Continue_T)> f_Continue, function<RetT(lang::cc::Node::Stmt::Return_T)> f_Return) {
    switch (this->w_) {
        case lang::cc::Node::Stmt::_W::Decl: {
            return f_Decl(this->as_Decl());
            break;
        }
        case lang::cc::Node::Stmt::_W::Expr: {
            return f_Expr(this->as_Expr());
            break;
        }
        case lang::cc::Node::Stmt::_W::Block: {
            return f_Block(this->as_Block());
            break;
        }
        case lang::cc::Node::Stmt::_W::If: {
            return f_If(this->as_If());
            break;
        }
        case lang::cc::Node::Stmt::_W::IfElse: {
            return f_IfElse(this->as_IfElse());
            break;
        }
        case lang::cc::Node::Stmt::_W::For: {
            return f_For(this->as_For());
            break;
        }
        case lang::cc::Node::Stmt::_W::Switch: {
            return f_Switch(this->as_Switch());
            break;
        }
        case lang::cc::Node::Stmt::_W::Break: {
            return f_Break(this->as_Break());
            break;
        }
        case lang::cc::Node::Stmt::_W::Continue: {
            return f_Continue(this->as_Continue());
            break;
        }
        case lang::cc::Node::Stmt::_W::Return: {
            return f_Return(this->as_Return());
            break;
        }
        default: {
            AX();
        }
    }
}

void pr_debug(ostream& os, FmtFlags flags, lang::cc::Node::ExprExt_T x);

namespace lang::cc::Node::ExprExt {
    enum struct _W {
        Expr,
        Decl,
    };
}

namespace lang::cc::Node::ExprExt {
    struct _T: lang::cc::Node::_T {
        void write(Ref<ostream> os, FmtFlags flags);
        void write(Ref<lang_rt::PrBufStream_T> pb);
        lang::cc::Node::ExprExt::_W w_;
        virtual ~_T();
        _T(lang::cc::Node::ExprExt::_W w);
        bool is_Expr();
        bool is_Decl();
        lang::cc::Node::ExprExt::Expr_T as_Expr();
        lang::cc::Node::ExprExt::Decl_T as_Decl();
        void match(function<void(lang::cc::Node::ExprExt::Expr_T)> f_Expr, function<void(lang::cc::Node::ExprExt::Decl_T)> f_Decl);
        template<typename RetT> RetT match_expr(function<RetT(lang::cc::Node::ExprExt::Expr_T)> f_Expr, function<RetT(lang::cc::Node::ExprExt::Decl_T)> f_Decl);
        void hash_ser_acc_lang_cc_Node_ExprExt(SerBuf& buf) const;
        virtual void hash_ser_acc(SerBuf& buf) const = 0;
    };
}

template<typename RetT> RetT lang::cc::Node::ExprExt::_T::match_expr(function<RetT(lang::cc::Node::ExprExt::Expr_T)> f_Expr, function<RetT(lang::cc::Node::ExprExt::Decl_T)> f_Decl) {
    switch (this->w_) {
        case lang::cc::Node::ExprExt::_W::Expr: {
            return f_Expr(this->as_Expr());
            break;
        }
        case lang::cc::Node::ExprExt::_W::Decl: {
            return f_Decl(this->as_Decl());
            break;
        }
        default: {
            AX();
        }
    }
}

void pr_debug(ostream& os, FmtFlags flags, lang::cc::Node::SwitchCase_T x);

namespace lang::cc::Node::SwitchCase {
    enum struct _W {
        Case,
        Default,
    };
}

namespace lang::cc::Node::SwitchCase {
    struct _T: lang::cc::Node::_T {
        void write(Ref<ostream> os, FmtFlags flags);
        void write(Ref<lang_rt::PrBufStream_T> pb);
        lang::cc::Node::SwitchCase::_W w_;
        virtual ~_T();
        _T(lang::cc::Node::SwitchCase::_W w);
        bool is_Case();
        bool is_Default();
        lang::cc::Node::SwitchCase::Case_T as_Case();
        lang::cc::Node::SwitchCase::Default_T as_Default();
        void match(function<void(lang::cc::Node::SwitchCase::Case_T)> f_Case, function<void(lang::cc::Node::SwitchCase::Default_T)> f_Default);
        template<typename RetT> RetT match_expr(function<RetT(lang::cc::Node::SwitchCase::Case_T)> f_Case, function<RetT(lang::cc::Node::SwitchCase::Default_T)> f_Default);
        void hash_ser_acc_lang_cc_Node_SwitchCase(SerBuf& buf) const;
        virtual void hash_ser_acc(SerBuf& buf) const = 0;
    };
}

template<typename RetT> RetT lang::cc::Node::SwitchCase::_T::match_expr(function<RetT(lang::cc::Node::SwitchCase::Case_T)> f_Case, function<RetT(lang::cc::Node::SwitchCase::Default_T)> f_Default) {
    switch (this->w_) {
        case lang::cc::Node::SwitchCase::_W::Case: {
            return f_Case(this->as_Case());
            break;
        }
        case lang::cc::Node::SwitchCase::_W::Default: {
            return f_Default(this->as_Default());
            break;
        }
        default: {
            AX();
        }
    }
}

void pr_debug(ostream& os, FmtFlags flags, lang::cc::Node::Expr_T x);

namespace lang::cc::Node::Expr {
    enum struct _W {
        Paren,
        Call,
        Index,
        IndexEmpty,
        Dot,
        Arrow,
        Ref_,
        AddrOf,
        Deref,
        UnaryPre,
        IncDecPre,
        IncDecPost,
        Assign,
        Bin1,
        Bin2,
        Bin3,
        Bin4,
        Bin5,
        Bin6,
        Template,
        New,
        Delete,
        Ellipsis,
        Tilde,
        Namespace,
        Id,
        Lit,
    };
}

namespace lang::cc::Node::Expr {
    struct _T: lang::cc::Node::_T {
        void write(Ref<ostream> os, FmtFlags flags);
        void write(Ref<lang_rt::PrBufStream_T> pb);
        lang::cc::Node::Expr::_W w_;
        virtual ~_T();
        _T(lang::cc::Node::Expr::_W w);
        bool is_Paren();
        bool is_Call();
        bool is_Index();
        bool is_IndexEmpty();
        bool is_Dot();
        bool is_Arrow();
        bool is_Ref_();
        bool is_AddrOf();
        bool is_Deref();
        bool is_UnaryPre();
        bool is_IncDecPre();
        bool is_IncDecPost();
        bool is_Assign();
        bool is_Bin1();
        bool is_Bin2();
        bool is_Bin3();
        bool is_Bin4();
        bool is_Bin5();
        bool is_Bin6();
        bool is_Template();
        bool is_New();
        bool is_Delete();
        bool is_Ellipsis();
        bool is_Tilde();
        bool is_Namespace();
        bool is_Id();
        bool is_Lit();
        lang::cc::Node::Expr::Paren_T as_Paren();
        lang::cc::Node::Expr::Call_T as_Call();
        lang::cc::Node::Expr::Index_T as_Index();
        lang::cc::Node::Expr::IndexEmpty_T as_IndexEmpty();
        lang::cc::Node::Expr::Dot_T as_Dot();
        lang::cc::Node::Expr::Arrow_T as_Arrow();
        lang::cc::Node::Expr::Ref__T as_Ref_();
        lang::cc::Node::Expr::AddrOf_T as_AddrOf();
        lang::cc::Node::Expr::Deref_T as_Deref();
        lang::cc::Node::Expr::UnaryPre_T as_UnaryPre();
        lang::cc::Node::Expr::IncDecPre_T as_IncDecPre();
        lang::cc::Node::Expr::IncDecPost_T as_IncDecPost();
        lang::cc::Node::Expr::Assign_T as_Assign();
        lang::cc::Node::Expr::Bin1_T as_Bin1();
        lang::cc::Node::Expr::Bin2_T as_Bin2();
        lang::cc::Node::Expr::Bin3_T as_Bin3();
        lang::cc::Node::Expr::Bin4_T as_Bin4();
        lang::cc::Node::Expr::Bin5_T as_Bin5();
        lang::cc::Node::Expr::Bin6_T as_Bin6();
        lang::cc::Node::Expr::Template_T as_Template();
        lang::cc::Node::Expr::New_T as_New();
        lang::cc::Node::Expr::Delete_T as_Delete();
        lang::cc::Node::Expr::Ellipsis_T as_Ellipsis();
        lang::cc::Node::Expr::Tilde_T as_Tilde();
        lang::cc::Node::Expr::Namespace_T as_Namespace();
        lang::cc::Node::Expr::Id_T as_Id();
        lang::cc::Node::Expr::Lit_T as_Lit();
        void match(function<void(lang::cc::Node::Expr::Paren_T)> f_Paren, function<void(lang::cc::Node::Expr::Call_T)> f_Call, function<void(lang::cc::Node::Expr::Index_T)> f_Index, function<void(lang::cc::Node::Expr::IndexEmpty_T)> f_IndexEmpty, function<void(lang::cc::Node::Expr::Dot_T)> f_Dot, function<void(lang::cc::Node::Expr::Arrow_T)> f_Arrow, function<void(lang::cc::Node::Expr::Ref__T)> f_Ref_, function<void(lang::cc::Node::Expr::AddrOf_T)> f_AddrOf, function<void(lang::cc::Node::Expr::Deref_T)> f_Deref, function<void(lang::cc::Node::Expr::UnaryPre_T)> f_UnaryPre, function<void(lang::cc::Node::Expr::IncDecPre_T)> f_IncDecPre, function<void(lang::cc::Node::Expr::IncDecPost_T)> f_IncDecPost, function<void(lang::cc::Node::Expr::Assign_T)> f_Assign, function<void(lang::cc::Node::Expr::Bin1_T)> f_Bin1, function<void(lang::cc::Node::Expr::Bin2_T)> f_Bin2, function<void(lang::cc::Node::Expr::Bin3_T)> f_Bin3, function<void(lang::cc::Node::Expr::Bin4_T)> f_Bin4, function<void(lang::cc::Node::Expr::Bin5_T)> f_Bin5, function<void(lang::cc::Node::Expr::Bin6_T)> f_Bin6, function<void(lang::cc::Node::Expr::Template_T)> f_Template, function<void(lang::cc::Node::Expr::New_T)> f_New, function<void(lang::cc::Node::Expr::Delete_T)> f_Delete, function<void(lang::cc::Node::Expr::Ellipsis_T)> f_Ellipsis, function<void(lang::cc::Node::Expr::Tilde_T)> f_Tilde, function<void(lang::cc::Node::Expr::Namespace_T)> f_Namespace, function<void(lang::cc::Node::Expr::Id_T)> f_Id, function<void(lang::cc::Node::Expr::Lit_T)> f_Lit);
        template<typename RetT> RetT match_expr(function<RetT(lang::cc::Node::Expr::Paren_T)> f_Paren, function<RetT(lang::cc::Node::Expr::Call_T)> f_Call, function<RetT(lang::cc::Node::Expr::Index_T)> f_Index, function<RetT(lang::cc::Node::Expr::IndexEmpty_T)> f_IndexEmpty, function<RetT(lang::cc::Node::Expr::Dot_T)> f_Dot, function<RetT(lang::cc::Node::Expr::Arrow_T)> f_Arrow, function<RetT(lang::cc::Node::Expr::Ref__T)> f_Ref_, function<RetT(lang::cc::Node::Expr::AddrOf_T)> f_AddrOf, function<RetT(lang::cc::Node::Expr::Deref_T)> f_Deref, function<RetT(lang::cc::Node::Expr::UnaryPre_T)> f_UnaryPre, function<RetT(lang::cc::Node::Expr::IncDecPre_T)> f_IncDecPre, function<RetT(lang::cc::Node::Expr::IncDecPost_T)> f_IncDecPost, function<RetT(lang::cc::Node::Expr::Assign_T)> f_Assign, function<RetT(lang::cc::Node::Expr::Bin1_T)> f_Bin1, function<RetT(lang::cc::Node::Expr::Bin2_T)> f_Bin2, function<RetT(lang::cc::Node::Expr::Bin3_T)> f_Bin3, function<RetT(lang::cc::Node::Expr::Bin4_T)> f_Bin4, function<RetT(lang::cc::Node::Expr::Bin5_T)> f_Bin5, function<RetT(lang::cc::Node::Expr::Bin6_T)> f_Bin6, function<RetT(lang::cc::Node::Expr::Template_T)> f_Template, function<RetT(lang::cc::Node::Expr::New_T)> f_New, function<RetT(lang::cc::Node::Expr::Delete_T)> f_Delete, function<RetT(lang::cc::Node::Expr::Ellipsis_T)> f_Ellipsis, function<RetT(lang::cc::Node::Expr::Tilde_T)> f_Tilde, function<RetT(lang::cc::Node::Expr::Namespace_T)> f_Namespace, function<RetT(lang::cc::Node::Expr::Id_T)> f_Id, function<RetT(lang::cc::Node::Expr::Lit_T)> f_Lit);
        void hash_ser_acc_lang_cc_Node_Expr(SerBuf& buf) const;
        virtual void hash_ser_acc(SerBuf& buf) const = 0;
    };
}

template<typename RetT> RetT lang::cc::Node::Expr::_T::match_expr(function<RetT(lang::cc::Node::Expr::Paren_T)> f_Paren, function<RetT(lang::cc::Node::Expr::Call_T)> f_Call, function<RetT(lang::cc::Node::Expr::Index_T)> f_Index, function<RetT(lang::cc::Node::Expr::IndexEmpty_T)> f_IndexEmpty, function<RetT(lang::cc::Node::Expr::Dot_T)> f_Dot, function<RetT(lang::cc::Node::Expr::Arrow_T)> f_Arrow, function<RetT(lang::cc::Node::Expr::Ref__T)> f_Ref_, function<RetT(lang::cc::Node::Expr::AddrOf_T)> f_AddrOf, function<RetT(lang::cc::Node::Expr::Deref_T)> f_Deref, function<RetT(lang::cc::Node::Expr::UnaryPre_T)> f_UnaryPre, function<RetT(lang::cc::Node::Expr::IncDecPre_T)> f_IncDecPre, function<RetT(lang::cc::Node::Expr::IncDecPost_T)> f_IncDecPost, function<RetT(lang::cc::Node::Expr::Assign_T)> f_Assign, function<RetT(lang::cc::Node::Expr::Bin1_T)> f_Bin1, function<RetT(lang::cc::Node::Expr::Bin2_T)> f_Bin2, function<RetT(lang::cc::Node::Expr::Bin3_T)> f_Bin3, function<RetT(lang::cc::Node::Expr::Bin4_T)> f_Bin4, function<RetT(lang::cc::Node::Expr::Bin5_T)> f_Bin5, function<RetT(lang::cc::Node::Expr::Bin6_T)> f_Bin6, function<RetT(lang::cc::Node::Expr::Template_T)> f_Template, function<RetT(lang::cc::Node::Expr::New_T)> f_New, function<RetT(lang::cc::Node::Expr::Delete_T)> f_Delete, function<RetT(lang::cc::Node::Expr::Ellipsis_T)> f_Ellipsis, function<RetT(lang::cc::Node::Expr::Tilde_T)> f_Tilde, function<RetT(lang::cc::Node::Expr::Namespace_T)> f_Namespace, function<RetT(lang::cc::Node::Expr::Id_T)> f_Id, function<RetT(lang::cc::Node::Expr::Lit_T)> f_Lit) {
    switch (this->w_) {
        case lang::cc::Node::Expr::_W::Paren: {
            return f_Paren(this->as_Paren());
            break;
        }
        case lang::cc::Node::Expr::_W::Call: {
            return f_Call(this->as_Call());
            break;
        }
        case lang::cc::Node::Expr::_W::Index: {
            return f_Index(this->as_Index());
            break;
        }
        case lang::cc::Node::Expr::_W::IndexEmpty: {
            return f_IndexEmpty(this->as_IndexEmpty());
            break;
        }
        case lang::cc::Node::Expr::_W::Dot: {
            return f_Dot(this->as_Dot());
            break;
        }
        case lang::cc::Node::Expr::_W::Arrow: {
            return f_Arrow(this->as_Arrow());
            break;
        }
        case lang::cc::Node::Expr::_W::Ref_: {
            return f_Ref_(this->as_Ref_());
            break;
        }
        case lang::cc::Node::Expr::_W::AddrOf: {
            return f_AddrOf(this->as_AddrOf());
            break;
        }
        case lang::cc::Node::Expr::_W::Deref: {
            return f_Deref(this->as_Deref());
            break;
        }
        case lang::cc::Node::Expr::_W::UnaryPre: {
            return f_UnaryPre(this->as_UnaryPre());
            break;
        }
        case lang::cc::Node::Expr::_W::IncDecPre: {
            return f_IncDecPre(this->as_IncDecPre());
            break;
        }
        case lang::cc::Node::Expr::_W::IncDecPost: {
            return f_IncDecPost(this->as_IncDecPost());
            break;
        }
        case lang::cc::Node::Expr::_W::Assign: {
            return f_Assign(this->as_Assign());
            break;
        }
        case lang::cc::Node::Expr::_W::Bin1: {
            return f_Bin1(this->as_Bin1());
            break;
        }
        case lang::cc::Node::Expr::_W::Bin2: {
            return f_Bin2(this->as_Bin2());
            break;
        }
        case lang::cc::Node::Expr::_W::Bin3: {
            return f_Bin3(this->as_Bin3());
            break;
        }
        case lang::cc::Node::Expr::_W::Bin4: {
            return f_Bin4(this->as_Bin4());
            break;
        }
        case lang::cc::Node::Expr::_W::Bin5: {
            return f_Bin5(this->as_Bin5());
            break;
        }
        case lang::cc::Node::Expr::_W::Bin6: {
            return f_Bin6(this->as_Bin6());
            break;
        }
        case lang::cc::Node::Expr::_W::Template: {
            return f_Template(this->as_Template());
            break;
        }
        case lang::cc::Node::Expr::_W::New: {
            return f_New(this->as_New());
            break;
        }
        case lang::cc::Node::Expr::_W::Delete: {
            return f_Delete(this->as_Delete());
            break;
        }
        case lang::cc::Node::Expr::_W::Ellipsis: {
            return f_Ellipsis(this->as_Ellipsis());
            break;
        }
        case lang::cc::Node::Expr::_W::Tilde: {
            return f_Tilde(this->as_Tilde());
            break;
        }
        case lang::cc::Node::Expr::_W::Namespace: {
            return f_Namespace(this->as_Namespace());
            break;
        }
        case lang::cc::Node::Expr::_W::Id: {
            return f_Id(this->as_Id());
            break;
        }
        case lang::cc::Node::Expr::_W::Lit: {
            return f_Lit(this->as_Lit());
            break;
        }
        default: {
            AX();
        }
    }
}

void pr_debug(ostream& os, FmtFlags flags, lang::cc::Node::Decl::Struct_T x);

namespace lang::cc::Node::Decl::Struct {
    lang::cc::Node::Decl::Struct_T make(Int id, lang_rt::TokenBounds bounds, bool is_top, lang_rt::ParserSymId sym, lang_rt::ParserAttrMask attr, lang_rt::ParserLookahead first_k, Option_T<lang::cc::Node::Decl::Struct::tmpl_T> tmpl, lang::cc::Node::Expr_T name, lang::cc::Node::StructDeclDef_T body);
}

namespace lang::cc::Node::Decl::Struct {
    lang::cc::Node::Decl::Struct_T make_ext(ArenaPtr arena, Int id, lang_rt::TokenBounds bounds, bool is_top, lang_rt::ParserSymId sym, lang_rt::ParserAttrMask attr, lang_rt::ParserLookahead first_k, Option_T<lang::cc::Node::Decl::Struct::tmpl_T> tmpl, lang::cc::Node::Expr_T name, lang::cc::Node::StructDeclDef_T body);
}

namespace lang::cc::Node::Decl::Struct {
    struct _T: lang::cc::Node::Decl::_T {
        void write(Ref<ostream> os, FmtFlags flags);
        void write(Ref<lang_rt::PrBufStream_T> pb);
        Option_T<lang::cc::Node::Decl::Struct::tmpl_T> tmpl_;
        lang::cc::Node::Expr_T name_;
        lang::cc::Node::StructDeclDef_T body_;
        _T();
        lang::cc::Node::Decl::Struct_T with_id(Int id);
        lang::cc::Node::Decl::Struct_T with_bounds(lang_rt::TokenBounds bounds);
        lang::cc::Node::Decl::Struct_T with_is_top(bool is_top);
        lang::cc::Node::Decl::Struct_T with_sym(lang_rt::ParserSymId sym);
        lang::cc::Node::Decl::Struct_T with_attr(lang_rt::ParserAttrMask attr);
        lang::cc::Node::Decl::Struct_T with_first_k(lang_rt::ParserLookahead first_k);
        lang::cc::Node::Decl::Struct_T with_tmpl(Option_T<lang::cc::Node::Decl::Struct::tmpl_T> tmpl);
        lang::cc::Node::Decl::Struct_T with_name(lang::cc::Node::Expr_T name);
        lang::cc::Node::Decl::Struct_T with_body(lang::cc::Node::StructDeclDef_T body);
        void hash_ser_acc_lang_cc_Node_Decl_Struct(SerBuf& buf) const;
        virtual void hash_ser_acc(SerBuf& buf) const;
    };
}

void pr_debug(ostream& os, FmtFlags flags, lang::cc::Node::StructDeclDef::Decl_T x);

namespace lang::cc::Node::StructDeclDef::Decl {
    lang::cc::Node::StructDeclDef::Decl_T make(Int id, lang_rt::TokenBounds bounds, bool is_top, lang_rt::ParserSymId sym, lang_rt::ParserAttrMask attr, lang_rt::ParserLookahead first_k);
}

namespace lang::cc::Node::StructDeclDef::Decl {
    lang::cc::Node::StructDeclDef::Decl_T make_ext(ArenaPtr arena, Int id, lang_rt::TokenBounds bounds, bool is_top, lang_rt::ParserSymId sym, lang_rt::ParserAttrMask attr, lang_rt::ParserLookahead first_k);
}

namespace lang::cc::Node::StructDeclDef::Decl {
    struct _T: lang::cc::Node::StructDeclDef::_T {
        void write(Ref<ostream> os, FmtFlags flags);
        void write(Ref<lang_rt::PrBufStream_T> pb);
        _T();
        lang::cc::Node::StructDeclDef::Decl_T with_id(Int id);
        lang::cc::Node::StructDeclDef::Decl_T with_bounds(lang_rt::TokenBounds bounds);
        lang::cc::Node::StructDeclDef::Decl_T with_is_top(bool is_top);
        lang::cc::Node::StructDeclDef::Decl_T with_sym(lang_rt::ParserSymId sym);
        lang::cc::Node::StructDeclDef::Decl_T with_attr(lang_rt::ParserAttrMask attr);
        lang::cc::Node::StructDeclDef::Decl_T with_first_k(lang_rt::ParserLookahead first_k);
        void hash_ser_acc_lang_cc_Node_StructDeclDef_Decl(SerBuf& buf) const;
        virtual void hash_ser_acc(SerBuf& buf) const;
    };
}

void pr_debug(ostream& os, FmtFlags flags, lang::cc::Node::StructDeclDef::Def_T x);

namespace lang::cc::Node::StructDeclDef::Def {
    lang::cc::Node::StructDeclDef::Def_T make(Int id, lang_rt::TokenBounds bounds, bool is_top, lang_rt::ParserSymId sym, lang_rt::ParserAttrMask attr, lang_rt::ParserLookahead first_k, Option_T<Vec_T<lang::cc::Node::Expr_T>> base, Vec_T<lang::cc::Node::Entry_T> entries);
}

namespace lang::cc::Node::StructDeclDef::Def {
    lang::cc::Node::StructDeclDef::Def_T make_ext(ArenaPtr arena, Int id, lang_rt::TokenBounds bounds, bool is_top, lang_rt::ParserSymId sym, lang_rt::ParserAttrMask attr, lang_rt::ParserLookahead first_k, Option_T<Vec_T<lang::cc::Node::Expr_T>> base, Vec_T<lang::cc::Node::Entry_T> entries);
}

namespace lang::cc::Node::StructDeclDef::Def {
    struct _T: lang::cc::Node::StructDeclDef::_T {
        void write(Ref<ostream> os, FmtFlags flags);
        void write(Ref<lang_rt::PrBufStream_T> pb);
        Option_T<Vec_T<lang::cc::Node::Expr_T>> base_;
        Vec_T<lang::cc::Node::Entry_T> entries_;
        _T();
        lang::cc::Node::StructDeclDef::Def_T with_id(Int id);
        lang::cc::Node::StructDeclDef::Def_T with_bounds(lang_rt::TokenBounds bounds);
        lang::cc::Node::StructDeclDef::Def_T with_is_top(bool is_top);
        lang::cc::Node::StructDeclDef::Def_T with_sym(lang_rt::ParserSymId sym);
        lang::cc::Node::StructDeclDef::Def_T with_attr(lang_rt::ParserAttrMask attr);
        lang::cc::Node::StructDeclDef::Def_T with_first_k(lang_rt::ParserLookahead first_k);
        lang::cc::Node::StructDeclDef::Def_T with_base(Option_T<Vec_T<lang::cc::Node::Expr_T>> base);
        lang::cc::Node::StructDeclDef::Def_T with_entries(Vec_T<lang::cc::Node::Entry_T> entries);
        void hash_ser_acc_lang_cc_Node_StructDeclDef_Def(SerBuf& buf) const;
        virtual void hash_ser_acc(SerBuf& buf) const;
    };
}

void pr_debug(ostream& os, FmtFlags flags, lang::cc::Node::Entry::Field_T x);

namespace lang::cc::Node::Entry::Field {
    lang::cc::Node::Entry::Field_T make(Int id, lang_rt::TokenBounds bounds, bool is_top, lang_rt::ParserSymId sym, lang_rt::ParserAttrMask attr, lang_rt::ParserLookahead first_k, lang::cc::Node::Expr_T type_, lang::cc::Node::Expr_T name);
}

namespace lang::cc::Node::Entry::Field {
    lang::cc::Node::Entry::Field_T make_ext(ArenaPtr arena, Int id, lang_rt::TokenBounds bounds, bool is_top, lang_rt::ParserSymId sym, lang_rt::ParserAttrMask attr, lang_rt::ParserLookahead first_k, lang::cc::Node::Expr_T type_, lang::cc::Node::Expr_T name);
}

namespace lang::cc::Node::Entry::Field {
    struct _T: lang::cc::Node::Entry::_T {
        void write(Ref<ostream> os, FmtFlags flags);
        void write(Ref<lang_rt::PrBufStream_T> pb);
        lang::cc::Node::Expr_T type__;
        lang::cc::Node::Expr_T name_;
        _T();
        lang::cc::Node::Entry::Field_T with_id(Int id);
        lang::cc::Node::Entry::Field_T with_bounds(lang_rt::TokenBounds bounds);
        lang::cc::Node::Entry::Field_T with_is_top(bool is_top);
        lang::cc::Node::Entry::Field_T with_sym(lang_rt::ParserSymId sym);
        lang::cc::Node::Entry::Field_T with_attr(lang_rt::ParserAttrMask attr);
        lang::cc::Node::Entry::Field_T with_first_k(lang_rt::ParserLookahead first_k);
        lang::cc::Node::Entry::Field_T with_type_(lang::cc::Node::Expr_T type_);
        lang::cc::Node::Entry::Field_T with_name(lang::cc::Node::Expr_T name);
        void hash_ser_acc_lang_cc_Node_Entry_Field(SerBuf& buf) const;
        virtual void hash_ser_acc(SerBuf& buf) const;
    };
}

void pr_debug(ostream& os, FmtFlags flags, lang::cc::Node::Entry::Fun_T x);

namespace lang::cc::Node::Entry::Fun {
    lang::cc::Node::Entry::Fun_T make(Int id, lang_rt::TokenBounds bounds, bool is_top, lang_rt::ParserSymId sym, lang_rt::ParserAttrMask attr, lang_rt::ParserLookahead first_k, Option_T<lang::cc::Node::Entry::Fun::tmpl_T> tmpl, Vec_T<lang::cc::Node::Mod_T> mods, Option_T<lang::cc::Node::Expr_T> ret_type, lang::cc::Node::Expr_T name, Vec_T<lang::cc::Node::Param_T> params, Vec_T<lang::cc::Node::Mod_T> mods_post, lang::cc::Node::FunDeclDef_T body);
}

namespace lang::cc::Node::Entry::Fun {
    lang::cc::Node::Entry::Fun_T make_ext(ArenaPtr arena, Int id, lang_rt::TokenBounds bounds, bool is_top, lang_rt::ParserSymId sym, lang_rt::ParserAttrMask attr, lang_rt::ParserLookahead first_k, Option_T<lang::cc::Node::Entry::Fun::tmpl_T> tmpl, Vec_T<lang::cc::Node::Mod_T> mods, Option_T<lang::cc::Node::Expr_T> ret_type, lang::cc::Node::Expr_T name, Vec_T<lang::cc::Node::Param_T> params, Vec_T<lang::cc::Node::Mod_T> mods_post, lang::cc::Node::FunDeclDef_T body);
}

namespace lang::cc::Node::Entry::Fun {
    struct _T: lang::cc::Node::Entry::_T {
        void write(Ref<ostream> os, FmtFlags flags);
        void write(Ref<lang_rt::PrBufStream_T> pb);
        Option_T<lang::cc::Node::Entry::Fun::tmpl_T> tmpl_;
        Vec_T<lang::cc::Node::Mod_T> mods_;
        Option_T<lang::cc::Node::Expr_T> ret_type_;
        lang::cc::Node::Expr_T name_;
        Vec_T<lang::cc::Node::Param_T> params_;
        Vec_T<lang::cc::Node::Mod_T> mods_post_;
        lang::cc::Node::FunDeclDef_T body_;
        _T();
        lang::cc::Node::Entry::Fun_T with_id(Int id);
        lang::cc::Node::Entry::Fun_T with_bounds(lang_rt::TokenBounds bounds);
        lang::cc::Node::Entry::Fun_T with_is_top(bool is_top);
        lang::cc::Node::Entry::Fun_T with_sym(lang_rt::ParserSymId sym);
        lang::cc::Node::Entry::Fun_T with_attr(lang_rt::ParserAttrMask attr);
        lang::cc::Node::Entry::Fun_T with_first_k(lang_rt::ParserLookahead first_k);
        lang::cc::Node::Entry::Fun_T with_tmpl(Option_T<lang::cc::Node::Entry::Fun::tmpl_T> tmpl);
        lang::cc::Node::Entry::Fun_T with_mods(Vec_T<lang::cc::Node::Mod_T> mods);
        lang::cc::Node::Entry::Fun_T with_ret_type(Option_T<lang::cc::Node::Expr_T> ret_type);
        lang::cc::Node::Entry::Fun_T with_name(lang::cc::Node::Expr_T name);
        lang::cc::Node::Entry::Fun_T with_params(Vec_T<lang::cc::Node::Param_T> params);
        lang::cc::Node::Entry::Fun_T with_mods_post(Vec_T<lang::cc::Node::Mod_T> mods_post);
        lang::cc::Node::Entry::Fun_T with_body(lang::cc::Node::FunDeclDef_T body);
        void hash_ser_acc_lang_cc_Node_Entry_Fun(SerBuf& buf) const;
        virtual void hash_ser_acc(SerBuf& buf) const;
    };
}

void pr_debug(ostream& os, FmtFlags flags, lang::cc::Node::Param::val_T x);

namespace lang::cc::Node::Param::val {
    lang::cc::Node::Param::val_T make(Int id, lang_rt::TokenBounds bounds, bool is_top, lang_rt::ParserSymId sym, lang_rt::ParserAttrMask attr, lang_rt::ParserLookahead first_k, lang::cc::Node::Expr_T init_val);
}

namespace lang::cc::Node::Param::val {
    lang::cc::Node::Param::val_T make_ext(ArenaPtr arena, Int id, lang_rt::TokenBounds bounds, bool is_top, lang_rt::ParserSymId sym, lang_rt::ParserAttrMask attr, lang_rt::ParserLookahead first_k, lang::cc::Node::Expr_T init_val);
}

namespace lang::cc::Node::Param::val {
    struct _T: lang::cc::Node::_T {
        void write(Ref<ostream> os, FmtFlags flags);
        void write(Ref<lang_rt::PrBufStream_T> pb);
        lang::cc::Node::Expr_T init_val_;
        _T();
        lang::cc::Node::Param::val_T with_id(Int id);
        lang::cc::Node::Param::val_T with_bounds(lang_rt::TokenBounds bounds);
        lang::cc::Node::Param::val_T with_is_top(bool is_top);
        lang::cc::Node::Param::val_T with_sym(lang_rt::ParserSymId sym);
        lang::cc::Node::Param::val_T with_attr(lang_rt::ParserAttrMask attr);
        lang::cc::Node::Param::val_T with_first_k(lang_rt::ParserLookahead first_k);
        lang::cc::Node::Param::val_T with_init_val(lang::cc::Node::Expr_T init_val);
        void hash_ser_acc_lang_cc_Node_Param_val(SerBuf& buf) const;
        virtual void hash_ser_acc(SerBuf& buf) const;
    };
}

void pr_debug(ostream& os, FmtFlags flags, lang::cc::Node::FunDeclDef::Decl_T x);

namespace lang::cc::Node::FunDeclDef::Decl {
    lang::cc::Node::FunDeclDef::Decl_T make(Int id, lang_rt::TokenBounds bounds, bool is_top, lang_rt::ParserSymId sym, lang_rt::ParserAttrMask attr, lang_rt::ParserLookahead first_k);
}

namespace lang::cc::Node::FunDeclDef::Decl {
    lang::cc::Node::FunDeclDef::Decl_T make_ext(ArenaPtr arena, Int id, lang_rt::TokenBounds bounds, bool is_top, lang_rt::ParserSymId sym, lang_rt::ParserAttrMask attr, lang_rt::ParserLookahead first_k);
}

namespace lang::cc::Node::FunDeclDef::Decl {
    struct _T: lang::cc::Node::FunDeclDef::_T {
        void write(Ref<ostream> os, FmtFlags flags);
        void write(Ref<lang_rt::PrBufStream_T> pb);
        _T();
        lang::cc::Node::FunDeclDef::Decl_T with_id(Int id);
        lang::cc::Node::FunDeclDef::Decl_T with_bounds(lang_rt::TokenBounds bounds);
        lang::cc::Node::FunDeclDef::Decl_T with_is_top(bool is_top);
        lang::cc::Node::FunDeclDef::Decl_T with_sym(lang_rt::ParserSymId sym);
        lang::cc::Node::FunDeclDef::Decl_T with_attr(lang_rt::ParserAttrMask attr);
        lang::cc::Node::FunDeclDef::Decl_T with_first_k(lang_rt::ParserLookahead first_k);
        void hash_ser_acc_lang_cc_Node_FunDeclDef_Decl(SerBuf& buf) const;
        virtual void hash_ser_acc(SerBuf& buf) const;
    };
}

void pr_debug(ostream& os, FmtFlags flags, lang::cc::Node::FunDeclDef::Def_T x);

namespace lang::cc::Node::FunDeclDef::Def {
    lang::cc::Node::FunDeclDef::Def_T make(Int id, lang_rt::TokenBounds bounds, bool is_top, lang_rt::ParserSymId sym, lang_rt::ParserAttrMask attr, lang_rt::ParserLookahead first_k, Option_T<Vec_T<lang::cc::Node::Expr_T>> init, lang::cc::Node::Block_T body);
}

namespace lang::cc::Node::FunDeclDef::Def {
    lang::cc::Node::FunDeclDef::Def_T make_ext(ArenaPtr arena, Int id, lang_rt::TokenBounds bounds, bool is_top, lang_rt::ParserSymId sym, lang_rt::ParserAttrMask attr, lang_rt::ParserLookahead first_k, Option_T<Vec_T<lang::cc::Node::Expr_T>> init, lang::cc::Node::Block_T body);
}

namespace lang::cc::Node::FunDeclDef::Def {
    struct _T: lang::cc::Node::FunDeclDef::_T {
        void write(Ref<ostream> os, FmtFlags flags);
        void write(Ref<lang_rt::PrBufStream_T> pb);
        Option_T<Vec_T<lang::cc::Node::Expr_T>> init_;
        lang::cc::Node::Block_T body_;
        _T();
        lang::cc::Node::FunDeclDef::Def_T with_id(Int id);
        lang::cc::Node::FunDeclDef::Def_T with_bounds(lang_rt::TokenBounds bounds);
        lang::cc::Node::FunDeclDef::Def_T with_is_top(bool is_top);
        lang::cc::Node::FunDeclDef::Def_T with_sym(lang_rt::ParserSymId sym);
        lang::cc::Node::FunDeclDef::Def_T with_attr(lang_rt::ParserAttrMask attr);
        lang::cc::Node::FunDeclDef::Def_T with_first_k(lang_rt::ParserLookahead first_k);
        lang::cc::Node::FunDeclDef::Def_T with_init(Option_T<Vec_T<lang::cc::Node::Expr_T>> init);
        lang::cc::Node::FunDeclDef::Def_T with_body(lang::cc::Node::Block_T body);
        void hash_ser_acc_lang_cc_Node_FunDeclDef_Def(SerBuf& buf) const;
        virtual void hash_ser_acc(SerBuf& buf) const;
    };
}

void pr_debug(ostream& os, FmtFlags flags, lang::cc::Node::FunDeclDef::Del_T x);

namespace lang::cc::Node::FunDeclDef::Del {
    lang::cc::Node::FunDeclDef::Del_T make(Int id, lang_rt::TokenBounds bounds, bool is_top, lang_rt::ParserSymId sym, lang_rt::ParserAttrMask attr, lang_rt::ParserLookahead first_k);
}

namespace lang::cc::Node::FunDeclDef::Del {
    lang::cc::Node::FunDeclDef::Del_T make_ext(ArenaPtr arena, Int id, lang_rt::TokenBounds bounds, bool is_top, lang_rt::ParserSymId sym, lang_rt::ParserAttrMask attr, lang_rt::ParserLookahead first_k);
}

namespace lang::cc::Node::FunDeclDef::Del {
    struct _T: lang::cc::Node::FunDeclDef::_T {
        void write(Ref<ostream> os, FmtFlags flags);
        void write(Ref<lang_rt::PrBufStream_T> pb);
        _T();
        lang::cc::Node::FunDeclDef::Del_T with_id(Int id);
        lang::cc::Node::FunDeclDef::Del_T with_bounds(lang_rt::TokenBounds bounds);
        lang::cc::Node::FunDeclDef::Del_T with_is_top(bool is_top);
        lang::cc::Node::FunDeclDef::Del_T with_sym(lang_rt::ParserSymId sym);
        lang::cc::Node::FunDeclDef::Del_T with_attr(lang_rt::ParserAttrMask attr);
        lang::cc::Node::FunDeclDef::Del_T with_first_k(lang_rt::ParserLookahead first_k);
        void hash_ser_acc_lang_cc_Node_FunDeclDef_Del(SerBuf& buf) const;
        virtual void hash_ser_acc(SerBuf& buf) const;
    };
}

void pr_debug(ostream& os, FmtFlags flags, lang::cc::Node::FunDeclDef::Zero_T x);

namespace lang::cc::Node::FunDeclDef::Zero {
    lang::cc::Node::FunDeclDef::Zero_T make(Int id, lang_rt::TokenBounds bounds, bool is_top, lang_rt::ParserSymId sym, lang_rt::ParserAttrMask attr, lang_rt::ParserLookahead first_k, StrSlice val);
}

namespace lang::cc::Node::FunDeclDef::Zero {
    lang::cc::Node::FunDeclDef::Zero_T make_ext(ArenaPtr arena, Int id, lang_rt::TokenBounds bounds, bool is_top, lang_rt::ParserSymId sym, lang_rt::ParserAttrMask attr, lang_rt::ParserLookahead first_k, StrSlice val);
}

namespace lang::cc::Node::FunDeclDef::Zero {
    struct _T: lang::cc::Node::FunDeclDef::_T {
        void write(Ref<ostream> os, FmtFlags flags);
        void write(Ref<lang_rt::PrBufStream_T> pb);
        StrSlice val_;
        _T();
        lang::cc::Node::FunDeclDef::Zero_T with_id(Int id);
        lang::cc::Node::FunDeclDef::Zero_T with_bounds(lang_rt::TokenBounds bounds);
        lang::cc::Node::FunDeclDef::Zero_T with_is_top(bool is_top);
        lang::cc::Node::FunDeclDef::Zero_T with_sym(lang_rt::ParserSymId sym);
        lang::cc::Node::FunDeclDef::Zero_T with_attr(lang_rt::ParserAttrMask attr);
        lang::cc::Node::FunDeclDef::Zero_T with_first_k(lang_rt::ParserLookahead first_k);
        lang::cc::Node::FunDeclDef::Zero_T with_val(StrSlice val);
        void hash_ser_acc_lang_cc_Node_FunDeclDef_Zero(SerBuf& buf) const;
        virtual void hash_ser_acc(SerBuf& buf) const;
    };
}

void pr_debug(ostream& os, FmtFlags flags, lang::cc::Node::Decl::EnumStruct_T x);

namespace lang::cc::Node::Decl::EnumStruct {
    lang::cc::Node::Decl::EnumStruct_T make(Int id, lang_rt::TokenBounds bounds, bool is_top, lang_rt::ParserSymId sym, lang_rt::ParserAttrMask attr, lang_rt::ParserLookahead first_k, lang::cc::Node::Expr_T name, Vec_T<lang::cc::Node::Expr_T> cases);
}

namespace lang::cc::Node::Decl::EnumStruct {
    lang::cc::Node::Decl::EnumStruct_T make_ext(ArenaPtr arena, Int id, lang_rt::TokenBounds bounds, bool is_top, lang_rt::ParserSymId sym, lang_rt::ParserAttrMask attr, lang_rt::ParserLookahead first_k, lang::cc::Node::Expr_T name, Vec_T<lang::cc::Node::Expr_T> cases);
}

namespace lang::cc::Node::Decl::EnumStruct {
    struct _T: lang::cc::Node::Decl::_T {
        void write(Ref<ostream> os, FmtFlags flags);
        void write(Ref<lang_rt::PrBufStream_T> pb);
        lang::cc::Node::Expr_T name_;
        Vec_T<lang::cc::Node::Expr_T> cases_;
        _T();
        lang::cc::Node::Decl::EnumStruct_T with_id(Int id);
        lang::cc::Node::Decl::EnumStruct_T with_bounds(lang_rt::TokenBounds bounds);
        lang::cc::Node::Decl::EnumStruct_T with_is_top(bool is_top);
        lang::cc::Node::Decl::EnumStruct_T with_sym(lang_rt::ParserSymId sym);
        lang::cc::Node::Decl::EnumStruct_T with_attr(lang_rt::ParserAttrMask attr);
        lang::cc::Node::Decl::EnumStruct_T with_first_k(lang_rt::ParserLookahead first_k);
        lang::cc::Node::Decl::EnumStruct_T with_name(lang::cc::Node::Expr_T name);
        lang::cc::Node::Decl::EnumStruct_T with_cases(Vec_T<lang::cc::Node::Expr_T> cases);
        void hash_ser_acc_lang_cc_Node_Decl_EnumStruct(SerBuf& buf) const;
        virtual void hash_ser_acc(SerBuf& buf) const;
    };
}

void pr_debug(ostream& os, FmtFlags flags, lang::cc::Node::Decl::Fun_T x);

namespace lang::cc::Node::Decl::Fun {
    lang::cc::Node::Decl::Fun_T make(Int id, lang_rt::TokenBounds bounds, bool is_top, lang_rt::ParserSymId sym, lang_rt::ParserAttrMask attr, lang_rt::ParserLookahead first_k, Option_T<lang::cc::Node::Decl::Fun::tmpl_T> tmpl, Vec_T<lang::cc::Node::Mod_T> mods, Option_T<lang::cc::Node::Expr_T> ret_type, lang::cc::Node::Expr_T name, Vec_T<lang::cc::Node::Param_T> params, Vec_T<lang::cc::Node::Mod_T> mods_post, lang::cc::Node::FunDeclDef_T body);
}

namespace lang::cc::Node::Decl::Fun {
    lang::cc::Node::Decl::Fun_T make_ext(ArenaPtr arena, Int id, lang_rt::TokenBounds bounds, bool is_top, lang_rt::ParserSymId sym, lang_rt::ParserAttrMask attr, lang_rt::ParserLookahead first_k, Option_T<lang::cc::Node::Decl::Fun::tmpl_T> tmpl, Vec_T<lang::cc::Node::Mod_T> mods, Option_T<lang::cc::Node::Expr_T> ret_type, lang::cc::Node::Expr_T name, Vec_T<lang::cc::Node::Param_T> params, Vec_T<lang::cc::Node::Mod_T> mods_post, lang::cc::Node::FunDeclDef_T body);
}

namespace lang::cc::Node::Decl::Fun {
    struct _T: lang::cc::Node::Decl::_T {
        void write(Ref<ostream> os, FmtFlags flags);
        void write(Ref<lang_rt::PrBufStream_T> pb);
        Option_T<lang::cc::Node::Decl::Fun::tmpl_T> tmpl_;
        Vec_T<lang::cc::Node::Mod_T> mods_;
        Option_T<lang::cc::Node::Expr_T> ret_type_;
        lang::cc::Node::Expr_T name_;
        Vec_T<lang::cc::Node::Param_T> params_;
        Vec_T<lang::cc::Node::Mod_T> mods_post_;
        lang::cc::Node::FunDeclDef_T body_;
        _T();
        lang::cc::Node::Decl::Fun_T with_id(Int id);
        lang::cc::Node::Decl::Fun_T with_bounds(lang_rt::TokenBounds bounds);
        lang::cc::Node::Decl::Fun_T with_is_top(bool is_top);
        lang::cc::Node::Decl::Fun_T with_sym(lang_rt::ParserSymId sym);
        lang::cc::Node::Decl::Fun_T with_attr(lang_rt::ParserAttrMask attr);
        lang::cc::Node::Decl::Fun_T with_first_k(lang_rt::ParserLookahead first_k);
        lang::cc::Node::Decl::Fun_T with_tmpl(Option_T<lang::cc::Node::Decl::Fun::tmpl_T> tmpl);
        lang::cc::Node::Decl::Fun_T with_mods(Vec_T<lang::cc::Node::Mod_T> mods);
        lang::cc::Node::Decl::Fun_T with_ret_type(Option_T<lang::cc::Node::Expr_T> ret_type);
        lang::cc::Node::Decl::Fun_T with_name(lang::cc::Node::Expr_T name);
        lang::cc::Node::Decl::Fun_T with_params(Vec_T<lang::cc::Node::Param_T> params);
        lang::cc::Node::Decl::Fun_T with_mods_post(Vec_T<lang::cc::Node::Mod_T> mods_post);
        lang::cc::Node::Decl::Fun_T with_body(lang::cc::Node::FunDeclDef_T body);
        void hash_ser_acc_lang_cc_Node_Decl_Fun(SerBuf& buf) const;
        virtual void hash_ser_acc(SerBuf& buf) const;
    };
}

void pr_debug(ostream& os, FmtFlags flags, lang::cc::Node::Mod::Const_T x);

namespace lang::cc::Node::Mod::Const {
    lang::cc::Node::Mod::Const_T make(Int id, lang_rt::TokenBounds bounds, bool is_top, lang_rt::ParserSymId sym, lang_rt::ParserAttrMask attr, lang_rt::ParserLookahead first_k);
}

namespace lang::cc::Node::Mod::Const {
    lang::cc::Node::Mod::Const_T make_ext(ArenaPtr arena, Int id, lang_rt::TokenBounds bounds, bool is_top, lang_rt::ParserSymId sym, lang_rt::ParserAttrMask attr, lang_rt::ParserLookahead first_k);
}

namespace lang::cc::Node::Mod::Const {
    struct _T: lang::cc::Node::Mod::_T {
        void write(Ref<ostream> os, FmtFlags flags);
        void write(Ref<lang_rt::PrBufStream_T> pb);
        _T();
        lang::cc::Node::Mod::Const_T with_id(Int id);
        lang::cc::Node::Mod::Const_T with_bounds(lang_rt::TokenBounds bounds);
        lang::cc::Node::Mod::Const_T with_is_top(bool is_top);
        lang::cc::Node::Mod::Const_T with_sym(lang_rt::ParserSymId sym);
        lang::cc::Node::Mod::Const_T with_attr(lang_rt::ParserAttrMask attr);
        lang::cc::Node::Mod::Const_T with_first_k(lang_rt::ParserLookahead first_k);
        void hash_ser_acc_lang_cc_Node_Mod_Const(SerBuf& buf) const;
        virtual void hash_ser_acc(SerBuf& buf) const;
    };
}

void pr_debug(ostream& os, FmtFlags flags, lang::cc::Node::Mod::Inline_T x);

namespace lang::cc::Node::Mod::Inline {
    lang::cc::Node::Mod::Inline_T make(Int id, lang_rt::TokenBounds bounds, bool is_top, lang_rt::ParserSymId sym, lang_rt::ParserAttrMask attr, lang_rt::ParserLookahead first_k);
}

namespace lang::cc::Node::Mod::Inline {
    lang::cc::Node::Mod::Inline_T make_ext(ArenaPtr arena, Int id, lang_rt::TokenBounds bounds, bool is_top, lang_rt::ParserSymId sym, lang_rt::ParserAttrMask attr, lang_rt::ParserLookahead first_k);
}

namespace lang::cc::Node::Mod::Inline {
    struct _T: lang::cc::Node::Mod::_T {
        void write(Ref<ostream> os, FmtFlags flags);
        void write(Ref<lang_rt::PrBufStream_T> pb);
        _T();
        lang::cc::Node::Mod::Inline_T with_id(Int id);
        lang::cc::Node::Mod::Inline_T with_bounds(lang_rt::TokenBounds bounds);
        lang::cc::Node::Mod::Inline_T with_is_top(bool is_top);
        lang::cc::Node::Mod::Inline_T with_sym(lang_rt::ParserSymId sym);
        lang::cc::Node::Mod::Inline_T with_attr(lang_rt::ParserAttrMask attr);
        lang::cc::Node::Mod::Inline_T with_first_k(lang_rt::ParserLookahead first_k);
        void hash_ser_acc_lang_cc_Node_Mod_Inline(SerBuf& buf) const;
        virtual void hash_ser_acc(SerBuf& buf) const;
    };
}

void pr_debug(ostream& os, FmtFlags flags, lang::cc::Node::Mod::Static_T x);

namespace lang::cc::Node::Mod::Static {
    lang::cc::Node::Mod::Static_T make(Int id, lang_rt::TokenBounds bounds, bool is_top, lang_rt::ParserSymId sym, lang_rt::ParserAttrMask attr, lang_rt::ParserLookahead first_k);
}

namespace lang::cc::Node::Mod::Static {
    lang::cc::Node::Mod::Static_T make_ext(ArenaPtr arena, Int id, lang_rt::TokenBounds bounds, bool is_top, lang_rt::ParserSymId sym, lang_rt::ParserAttrMask attr, lang_rt::ParserLookahead first_k);
}

namespace lang::cc::Node::Mod::Static {
    struct _T: lang::cc::Node::Mod::_T {
        void write(Ref<ostream> os, FmtFlags flags);
        void write(Ref<lang_rt::PrBufStream_T> pb);
        _T();
        lang::cc::Node::Mod::Static_T with_id(Int id);
        lang::cc::Node::Mod::Static_T with_bounds(lang_rt::TokenBounds bounds);
        lang::cc::Node::Mod::Static_T with_is_top(bool is_top);
        lang::cc::Node::Mod::Static_T with_sym(lang_rt::ParserSymId sym);
        lang::cc::Node::Mod::Static_T with_attr(lang_rt::ParserAttrMask attr);
        lang::cc::Node::Mod::Static_T with_first_k(lang_rt::ParserLookahead first_k);
        void hash_ser_acc_lang_cc_Node_Mod_Static(SerBuf& buf) const;
        virtual void hash_ser_acc(SerBuf& buf) const;
    };
}

void pr_debug(ostream& os, FmtFlags flags, lang::cc::Node::Mod::Virtual_T x);

namespace lang::cc::Node::Mod::Virtual {
    lang::cc::Node::Mod::Virtual_T make(Int id, lang_rt::TokenBounds bounds, bool is_top, lang_rt::ParserSymId sym, lang_rt::ParserAttrMask attr, lang_rt::ParserLookahead first_k);
}

namespace lang::cc::Node::Mod::Virtual {
    lang::cc::Node::Mod::Virtual_T make_ext(ArenaPtr arena, Int id, lang_rt::TokenBounds bounds, bool is_top, lang_rt::ParserSymId sym, lang_rt::ParserAttrMask attr, lang_rt::ParserLookahead first_k);
}

namespace lang::cc::Node::Mod::Virtual {
    struct _T: lang::cc::Node::Mod::_T {
        void write(Ref<ostream> os, FmtFlags flags);
        void write(Ref<lang_rt::PrBufStream_T> pb);
        _T();
        lang::cc::Node::Mod::Virtual_T with_id(Int id);
        lang::cc::Node::Mod::Virtual_T with_bounds(lang_rt::TokenBounds bounds);
        lang::cc::Node::Mod::Virtual_T with_is_top(bool is_top);
        lang::cc::Node::Mod::Virtual_T with_sym(lang_rt::ParserSymId sym);
        lang::cc::Node::Mod::Virtual_T with_attr(lang_rt::ParserAttrMask attr);
        lang::cc::Node::Mod::Virtual_T with_first_k(lang_rt::ParserLookahead first_k);
        void hash_ser_acc_lang_cc_Node_Mod_Virtual(SerBuf& buf) const;
        virtual void hash_ser_acc(SerBuf& buf) const;
    };
}

void pr_debug(ostream& os, FmtFlags flags, lang::cc::Node::Mod::NoInline_T x);

namespace lang::cc::Node::Mod::NoInline {
    lang::cc::Node::Mod::NoInline_T make(Int id, lang_rt::TokenBounds bounds, bool is_top, lang_rt::ParserSymId sym, lang_rt::ParserAttrMask attr, lang_rt::ParserLookahead first_k);
}

namespace lang::cc::Node::Mod::NoInline {
    lang::cc::Node::Mod::NoInline_T make_ext(ArenaPtr arena, Int id, lang_rt::TokenBounds bounds, bool is_top, lang_rt::ParserSymId sym, lang_rt::ParserAttrMask attr, lang_rt::ParserLookahead first_k);
}

namespace lang::cc::Node::Mod::NoInline {
    struct _T: lang::cc::Node::Mod::_T {
        void write(Ref<ostream> os, FmtFlags flags);
        void write(Ref<lang_rt::PrBufStream_T> pb);
        _T();
        lang::cc::Node::Mod::NoInline_T with_id(Int id);
        lang::cc::Node::Mod::NoInline_T with_bounds(lang_rt::TokenBounds bounds);
        lang::cc::Node::Mod::NoInline_T with_is_top(bool is_top);
        lang::cc::Node::Mod::NoInline_T with_sym(lang_rt::ParserSymId sym);
        lang::cc::Node::Mod::NoInline_T with_attr(lang_rt::ParserAttrMask attr);
        lang::cc::Node::Mod::NoInline_T with_first_k(lang_rt::ParserLookahead first_k);
        void hash_ser_acc_lang_cc_Node_Mod_NoInline(SerBuf& buf) const;
        virtual void hash_ser_acc(SerBuf& buf) const;
    };
}

void pr_debug(ostream& os, FmtFlags flags, lang::cc::Node::Mod::AlwaysInline_T x);

namespace lang::cc::Node::Mod::AlwaysInline {
    lang::cc::Node::Mod::AlwaysInline_T make(Int id, lang_rt::TokenBounds bounds, bool is_top, lang_rt::ParserSymId sym, lang_rt::ParserAttrMask attr, lang_rt::ParserLookahead first_k);
}

namespace lang::cc::Node::Mod::AlwaysInline {
    lang::cc::Node::Mod::AlwaysInline_T make_ext(ArenaPtr arena, Int id, lang_rt::TokenBounds bounds, bool is_top, lang_rt::ParserSymId sym, lang_rt::ParserAttrMask attr, lang_rt::ParserLookahead first_k);
}

namespace lang::cc::Node::Mod::AlwaysInline {
    struct _T: lang::cc::Node::Mod::_T {
        void write(Ref<ostream> os, FmtFlags flags);
        void write(Ref<lang_rt::PrBufStream_T> pb);
        _T();
        lang::cc::Node::Mod::AlwaysInline_T with_id(Int id);
        lang::cc::Node::Mod::AlwaysInline_T with_bounds(lang_rt::TokenBounds bounds);
        lang::cc::Node::Mod::AlwaysInline_T with_is_top(bool is_top);
        lang::cc::Node::Mod::AlwaysInline_T with_sym(lang_rt::ParserSymId sym);
        lang::cc::Node::Mod::AlwaysInline_T with_attr(lang_rt::ParserAttrMask attr);
        lang::cc::Node::Mod::AlwaysInline_T with_first_k(lang_rt::ParserLookahead first_k);
        void hash_ser_acc_lang_cc_Node_Mod_AlwaysInline(SerBuf& buf) const;
        virtual void hash_ser_acc(SerBuf& buf) const;
    };
}

void pr_debug(ostream& os, FmtFlags flags, lang::cc::Node::Decl::Namespace_T x);

namespace lang::cc::Node::Decl::Namespace {
    lang::cc::Node::Decl::Namespace_T make(Int id, lang_rt::TokenBounds bounds, bool is_top, lang_rt::ParserSymId sym, lang_rt::ParserAttrMask attr, lang_rt::ParserLookahead first_k, lang::cc::Node::Expr_T name, Vec_T<lang::cc::Node::Decl_T> body);
}

namespace lang::cc::Node::Decl::Namespace {
    lang::cc::Node::Decl::Namespace_T make_ext(ArenaPtr arena, Int id, lang_rt::TokenBounds bounds, bool is_top, lang_rt::ParserSymId sym, lang_rt::ParserAttrMask attr, lang_rt::ParserLookahead first_k, lang::cc::Node::Expr_T name, Vec_T<lang::cc::Node::Decl_T> body);
}

namespace lang::cc::Node::Decl::Namespace {
    struct _T: lang::cc::Node::Decl::_T {
        void write(Ref<ostream> os, FmtFlags flags);
        void write(Ref<lang_rt::PrBufStream_T> pb);
        lang::cc::Node::Expr_T name_;
        Vec_T<lang::cc::Node::Decl_T> body_;
        _T();
        lang::cc::Node::Decl::Namespace_T with_id(Int id);
        lang::cc::Node::Decl::Namespace_T with_bounds(lang_rt::TokenBounds bounds);
        lang::cc::Node::Decl::Namespace_T with_is_top(bool is_top);
        lang::cc::Node::Decl::Namespace_T with_sym(lang_rt::ParserSymId sym);
        lang::cc::Node::Decl::Namespace_T with_attr(lang_rt::ParserAttrMask attr);
        lang::cc::Node::Decl::Namespace_T with_first_k(lang_rt::ParserLookahead first_k);
        lang::cc::Node::Decl::Namespace_T with_name(lang::cc::Node::Expr_T name);
        lang::cc::Node::Decl::Namespace_T with_body(Vec_T<lang::cc::Node::Decl_T> body);
        void hash_ser_acc_lang_cc_Node_Decl_Namespace(SerBuf& buf) const;
        virtual void hash_ser_acc(SerBuf& buf) const;
    };
}

void pr_debug(ostream& os, FmtFlags flags, lang::cc::Node::Decl::UsingAlias_T x);

namespace lang::cc::Node::Decl::UsingAlias {
    lang::cc::Node::Decl::UsingAlias_T make(Int id, lang_rt::TokenBounds bounds, bool is_top, lang_rt::ParserSymId sym, lang_rt::ParserAttrMask attr, lang_rt::ParserLookahead first_k, Option_T<lang::cc::Node::Decl::UsingAlias::tmpl_T> tmpl, lang::cc::Node::Expr_T name, lang::cc::Node::Expr_T val);
}

namespace lang::cc::Node::Decl::UsingAlias {
    lang::cc::Node::Decl::UsingAlias_T make_ext(ArenaPtr arena, Int id, lang_rt::TokenBounds bounds, bool is_top, lang_rt::ParserSymId sym, lang_rt::ParserAttrMask attr, lang_rt::ParserLookahead first_k, Option_T<lang::cc::Node::Decl::UsingAlias::tmpl_T> tmpl, lang::cc::Node::Expr_T name, lang::cc::Node::Expr_T val);
}

namespace lang::cc::Node::Decl::UsingAlias {
    struct _T: lang::cc::Node::Decl::_T {
        void write(Ref<ostream> os, FmtFlags flags);
        void write(Ref<lang_rt::PrBufStream_T> pb);
        Option_T<lang::cc::Node::Decl::UsingAlias::tmpl_T> tmpl_;
        lang::cc::Node::Expr_T name_;
        lang::cc::Node::Expr_T val_;
        _T();
        lang::cc::Node::Decl::UsingAlias_T with_id(Int id);
        lang::cc::Node::Decl::UsingAlias_T with_bounds(lang_rt::TokenBounds bounds);
        lang::cc::Node::Decl::UsingAlias_T with_is_top(bool is_top);
        lang::cc::Node::Decl::UsingAlias_T with_sym(lang_rt::ParserSymId sym);
        lang::cc::Node::Decl::UsingAlias_T with_attr(lang_rt::ParserAttrMask attr);
        lang::cc::Node::Decl::UsingAlias_T with_first_k(lang_rt::ParserLookahead first_k);
        lang::cc::Node::Decl::UsingAlias_T with_tmpl(Option_T<lang::cc::Node::Decl::UsingAlias::tmpl_T> tmpl);
        lang::cc::Node::Decl::UsingAlias_T with_name(lang::cc::Node::Expr_T name);
        lang::cc::Node::Decl::UsingAlias_T with_val(lang::cc::Node::Expr_T val);
        void hash_ser_acc_lang_cc_Node_Decl_UsingAlias(SerBuf& buf) const;
        virtual void hash_ser_acc(SerBuf& buf) const;
    };
}

void pr_debug(ostream& os, FmtFlags flags, lang::cc::Node::Decl::UsingNamespace_T x);

namespace lang::cc::Node::Decl::UsingNamespace {
    lang::cc::Node::Decl::UsingNamespace_T make(Int id, lang_rt::TokenBounds bounds, bool is_top, lang_rt::ParserSymId sym, lang_rt::ParserAttrMask attr, lang_rt::ParserLookahead first_k, lang::cc::Node::Expr_T name);
}

namespace lang::cc::Node::Decl::UsingNamespace {
    lang::cc::Node::Decl::UsingNamespace_T make_ext(ArenaPtr arena, Int id, lang_rt::TokenBounds bounds, bool is_top, lang_rt::ParserSymId sym, lang_rt::ParserAttrMask attr, lang_rt::ParserLookahead first_k, lang::cc::Node::Expr_T name);
}

namespace lang::cc::Node::Decl::UsingNamespace {
    struct _T: lang::cc::Node::Decl::_T {
        void write(Ref<ostream> os, FmtFlags flags);
        void write(Ref<lang_rt::PrBufStream_T> pb);
        lang::cc::Node::Expr_T name_;
        _T();
        lang::cc::Node::Decl::UsingNamespace_T with_id(Int id);
        lang::cc::Node::Decl::UsingNamespace_T with_bounds(lang_rt::TokenBounds bounds);
        lang::cc::Node::Decl::UsingNamespace_T with_is_top(bool is_top);
        lang::cc::Node::Decl::UsingNamespace_T with_sym(lang_rt::ParserSymId sym);
        lang::cc::Node::Decl::UsingNamespace_T with_attr(lang_rt::ParserAttrMask attr);
        lang::cc::Node::Decl::UsingNamespace_T with_first_k(lang_rt::ParserLookahead first_k);
        lang::cc::Node::Decl::UsingNamespace_T with_name(lang::cc::Node::Expr_T name);
        void hash_ser_acc_lang_cc_Node_Decl_UsingNamespace(SerBuf& buf) const;
        virtual void hash_ser_acc(SerBuf& buf) const;
    };
}

void pr_debug(ostream& os, FmtFlags flags, lang::cc::Node::Decl::Include_T x);

namespace lang::cc::Node::Decl::Include {
    lang::cc::Node::Decl::Include_T make(Int id, lang_rt::TokenBounds bounds, bool is_top, lang_rt::ParserSymId sym, lang_rt::ParserAttrMask attr, lang_rt::ParserLookahead first_k, StrSlice x);
}

namespace lang::cc::Node::Decl::Include {
    lang::cc::Node::Decl::Include_T make_ext(ArenaPtr arena, Int id, lang_rt::TokenBounds bounds, bool is_top, lang_rt::ParserSymId sym, lang_rt::ParserAttrMask attr, lang_rt::ParserLookahead first_k, StrSlice x);
}

namespace lang::cc::Node::Decl::Include {
    struct _T: lang::cc::Node::Decl::_T {
        void write(Ref<ostream> os, FmtFlags flags);
        void write(Ref<lang_rt::PrBufStream_T> pb);
        StrSlice x_;
        _T();
        lang::cc::Node::Decl::Include_T with_id(Int id);
        lang::cc::Node::Decl::Include_T with_bounds(lang_rt::TokenBounds bounds);
        lang::cc::Node::Decl::Include_T with_is_top(bool is_top);
        lang::cc::Node::Decl::Include_T with_sym(lang_rt::ParserSymId sym);
        lang::cc::Node::Decl::Include_T with_attr(lang_rt::ParserAttrMask attr);
        lang::cc::Node::Decl::Include_T with_first_k(lang_rt::ParserLookahead first_k);
        lang::cc::Node::Decl::Include_T with_x(StrSlice x);
        void hash_ser_acc_lang_cc_Node_Decl_Include(SerBuf& buf) const;
        virtual void hash_ser_acc(SerBuf& buf) const;
    };
}

void pr_debug(ostream& os, FmtFlags flags, lang::cc::Node::Decl::PragmaOnce_T x);

namespace lang::cc::Node::Decl::PragmaOnce {
    lang::cc::Node::Decl::PragmaOnce_T make(Int id, lang_rt::TokenBounds bounds, bool is_top, lang_rt::ParserSymId sym, lang_rt::ParserAttrMask attr, lang_rt::ParserLookahead first_k, StrSlice x);
}

namespace lang::cc::Node::Decl::PragmaOnce {
    lang::cc::Node::Decl::PragmaOnce_T make_ext(ArenaPtr arena, Int id, lang_rt::TokenBounds bounds, bool is_top, lang_rt::ParserSymId sym, lang_rt::ParserAttrMask attr, lang_rt::ParserLookahead first_k, StrSlice x);
}

namespace lang::cc::Node::Decl::PragmaOnce {
    struct _T: lang::cc::Node::Decl::_T {
        void write(Ref<ostream> os, FmtFlags flags);
        void write(Ref<lang_rt::PrBufStream_T> pb);
        StrSlice x_;
        _T();
        lang::cc::Node::Decl::PragmaOnce_T with_id(Int id);
        lang::cc::Node::Decl::PragmaOnce_T with_bounds(lang_rt::TokenBounds bounds);
        lang::cc::Node::Decl::PragmaOnce_T with_is_top(bool is_top);
        lang::cc::Node::Decl::PragmaOnce_T with_sym(lang_rt::ParserSymId sym);
        lang::cc::Node::Decl::PragmaOnce_T with_attr(lang_rt::ParserAttrMask attr);
        lang::cc::Node::Decl::PragmaOnce_T with_first_k(lang_rt::ParserLookahead first_k);
        lang::cc::Node::Decl::PragmaOnce_T with_x(StrSlice x);
        void hash_ser_acc_lang_cc_Node_Decl_PragmaOnce(SerBuf& buf) const;
        virtual void hash_ser_acc(SerBuf& buf) const;
    };
}

void pr_debug(ostream& os, FmtFlags flags, lang::cc::Node::Stmt::Decl_T x);

namespace lang::cc::Node::Stmt::Decl {
    lang::cc::Node::Stmt::Decl_T make(Int id, lang_rt::TokenBounds bounds, bool is_top, lang_rt::ParserSymId sym, lang_rt::ParserAttrMask attr, lang_rt::ParserLookahead first_k, lang::cc::Node::TypedDecl_T decl);
}

namespace lang::cc::Node::Stmt::Decl {
    lang::cc::Node::Stmt::Decl_T make_ext(ArenaPtr arena, Int id, lang_rt::TokenBounds bounds, bool is_top, lang_rt::ParserSymId sym, lang_rt::ParserAttrMask attr, lang_rt::ParserLookahead first_k, lang::cc::Node::TypedDecl_T decl);
}

namespace lang::cc::Node::Stmt::Decl {
    struct _T: lang::cc::Node::Stmt::_T {
        void write(Ref<ostream> os, FmtFlags flags);
        void write(Ref<lang_rt::PrBufStream_T> pb);
        lang::cc::Node::TypedDecl_T decl_;
        _T();
        lang::cc::Node::Stmt::Decl_T with_id(Int id);
        lang::cc::Node::Stmt::Decl_T with_bounds(lang_rt::TokenBounds bounds);
        lang::cc::Node::Stmt::Decl_T with_is_top(bool is_top);
        lang::cc::Node::Stmt::Decl_T with_sym(lang_rt::ParserSymId sym);
        lang::cc::Node::Stmt::Decl_T with_attr(lang_rt::ParserAttrMask attr);
        lang::cc::Node::Stmt::Decl_T with_first_k(lang_rt::ParserLookahead first_k);
        lang::cc::Node::Stmt::Decl_T with_decl(lang::cc::Node::TypedDecl_T decl);
        void hash_ser_acc_lang_cc_Node_Stmt_Decl(SerBuf& buf) const;
        virtual void hash_ser_acc(SerBuf& buf) const;
    };
}

void pr_debug(ostream& os, FmtFlags flags, lang::cc::Node::Stmt::Expr_T x);

namespace lang::cc::Node::Stmt::Expr {
    lang::cc::Node::Stmt::Expr_T make(Int id, lang_rt::TokenBounds bounds, bool is_top, lang_rt::ParserSymId sym, lang_rt::ParserAttrMask attr, lang_rt::ParserLookahead first_k, lang::cc::Node::Expr_T e);
}

namespace lang::cc::Node::Stmt::Expr {
    lang::cc::Node::Stmt::Expr_T make_ext(ArenaPtr arena, Int id, lang_rt::TokenBounds bounds, bool is_top, lang_rt::ParserSymId sym, lang_rt::ParserAttrMask attr, lang_rt::ParserLookahead first_k, lang::cc::Node::Expr_T e);
}

namespace lang::cc::Node::Stmt::Expr {
    struct _T: lang::cc::Node::Stmt::_T {
        void write(Ref<ostream> os, FmtFlags flags);
        void write(Ref<lang_rt::PrBufStream_T> pb);
        lang::cc::Node::Expr_T e_;
        _T();
        lang::cc::Node::Stmt::Expr_T with_id(Int id);
        lang::cc::Node::Stmt::Expr_T with_bounds(lang_rt::TokenBounds bounds);
        lang::cc::Node::Stmt::Expr_T with_is_top(bool is_top);
        lang::cc::Node::Stmt::Expr_T with_sym(lang_rt::ParserSymId sym);
        lang::cc::Node::Stmt::Expr_T with_attr(lang_rt::ParserAttrMask attr);
        lang::cc::Node::Stmt::Expr_T with_first_k(lang_rt::ParserLookahead first_k);
        lang::cc::Node::Stmt::Expr_T with_e(lang::cc::Node::Expr_T e);
        void hash_ser_acc_lang_cc_Node_Stmt_Expr(SerBuf& buf) const;
        virtual void hash_ser_acc(SerBuf& buf) const;
    };
}

void pr_debug(ostream& os, FmtFlags flags, lang::cc::Node::Stmt::Block_T x);

namespace lang::cc::Node::Stmt::Block {
    lang::cc::Node::Stmt::Block_T make(Int id, lang_rt::TokenBounds bounds, bool is_top, lang_rt::ParserSymId sym, lang_rt::ParserAttrMask attr, lang_rt::ParserLookahead first_k, lang::cc::Node::Block_T block);
}

namespace lang::cc::Node::Stmt::Block {
    lang::cc::Node::Stmt::Block_T make_ext(ArenaPtr arena, Int id, lang_rt::TokenBounds bounds, bool is_top, lang_rt::ParserSymId sym, lang_rt::ParserAttrMask attr, lang_rt::ParserLookahead first_k, lang::cc::Node::Block_T block);
}

namespace lang::cc::Node::Stmt::Block {
    struct _T: lang::cc::Node::Stmt::_T {
        void write(Ref<ostream> os, FmtFlags flags);
        void write(Ref<lang_rt::PrBufStream_T> pb);
        lang::cc::Node::Block_T block_;
        _T();
        lang::cc::Node::Stmt::Block_T with_id(Int id);
        lang::cc::Node::Stmt::Block_T with_bounds(lang_rt::TokenBounds bounds);
        lang::cc::Node::Stmt::Block_T with_is_top(bool is_top);
        lang::cc::Node::Stmt::Block_T with_sym(lang_rt::ParserSymId sym);
        lang::cc::Node::Stmt::Block_T with_attr(lang_rt::ParserAttrMask attr);
        lang::cc::Node::Stmt::Block_T with_first_k(lang_rt::ParserLookahead first_k);
        lang::cc::Node::Stmt::Block_T with_block(lang::cc::Node::Block_T block);
        void hash_ser_acc_lang_cc_Node_Stmt_Block(SerBuf& buf) const;
        virtual void hash_ser_acc(SerBuf& buf) const;
    };
}

void pr_debug(ostream& os, FmtFlags flags, lang::cc::Node::Stmt::If_T x);

namespace lang::cc::Node::Stmt::If {
    lang::cc::Node::Stmt::If_T make(Int id, lang_rt::TokenBounds bounds, bool is_top, lang_rt::ParserSymId sym, lang_rt::ParserAttrMask attr, lang_rt::ParserLookahead first_k, lang::cc::Node::Expr_T cond, lang::cc::Node::Stmt_T xt);
}

namespace lang::cc::Node::Stmt::If {
    lang::cc::Node::Stmt::If_T make_ext(ArenaPtr arena, Int id, lang_rt::TokenBounds bounds, bool is_top, lang_rt::ParserSymId sym, lang_rt::ParserAttrMask attr, lang_rt::ParserLookahead first_k, lang::cc::Node::Expr_T cond, lang::cc::Node::Stmt_T xt);
}

namespace lang::cc::Node::Stmt::If {
    struct _T: lang::cc::Node::Stmt::_T {
        void write(Ref<ostream> os, FmtFlags flags);
        void write(Ref<lang_rt::PrBufStream_T> pb);
        lang::cc::Node::Expr_T cond_;
        lang::cc::Node::Stmt_T xt_;
        _T();
        lang::cc::Node::Stmt::If_T with_id(Int id);
        lang::cc::Node::Stmt::If_T with_bounds(lang_rt::TokenBounds bounds);
        lang::cc::Node::Stmt::If_T with_is_top(bool is_top);
        lang::cc::Node::Stmt::If_T with_sym(lang_rt::ParserSymId sym);
        lang::cc::Node::Stmt::If_T with_attr(lang_rt::ParserAttrMask attr);
        lang::cc::Node::Stmt::If_T with_first_k(lang_rt::ParserLookahead first_k);
        lang::cc::Node::Stmt::If_T with_cond(lang::cc::Node::Expr_T cond);
        lang::cc::Node::Stmt::If_T with_xt(lang::cc::Node::Stmt_T xt);
        void hash_ser_acc_lang_cc_Node_Stmt_If(SerBuf& buf) const;
        virtual void hash_ser_acc(SerBuf& buf) const;
    };
}

void pr_debug(ostream& os, FmtFlags flags, lang::cc::Node::Stmt::IfElse_T x);

namespace lang::cc::Node::Stmt::IfElse {
    lang::cc::Node::Stmt::IfElse_T make(Int id, lang_rt::TokenBounds bounds, bool is_top, lang_rt::ParserSymId sym, lang_rt::ParserAttrMask attr, lang_rt::ParserLookahead first_k, lang::cc::Node::Expr_T cond, lang::cc::Node::Stmt_T xt, lang::cc::Node::Stmt_T xf);
}

namespace lang::cc::Node::Stmt::IfElse {
    lang::cc::Node::Stmt::IfElse_T make_ext(ArenaPtr arena, Int id, lang_rt::TokenBounds bounds, bool is_top, lang_rt::ParserSymId sym, lang_rt::ParserAttrMask attr, lang_rt::ParserLookahead first_k, lang::cc::Node::Expr_T cond, lang::cc::Node::Stmt_T xt, lang::cc::Node::Stmt_T xf);
}

namespace lang::cc::Node::Stmt::IfElse {
    struct _T: lang::cc::Node::Stmt::_T {
        void write(Ref<ostream> os, FmtFlags flags);
        void write(Ref<lang_rt::PrBufStream_T> pb);
        lang::cc::Node::Expr_T cond_;
        lang::cc::Node::Stmt_T xt_;
        lang::cc::Node::Stmt_T xf_;
        _T();
        lang::cc::Node::Stmt::IfElse_T with_id(Int id);
        lang::cc::Node::Stmt::IfElse_T with_bounds(lang_rt::TokenBounds bounds);
        lang::cc::Node::Stmt::IfElse_T with_is_top(bool is_top);
        lang::cc::Node::Stmt::IfElse_T with_sym(lang_rt::ParserSymId sym);
        lang::cc::Node::Stmt::IfElse_T with_attr(lang_rt::ParserAttrMask attr);
        lang::cc::Node::Stmt::IfElse_T with_first_k(lang_rt::ParserLookahead first_k);
        lang::cc::Node::Stmt::IfElse_T with_cond(lang::cc::Node::Expr_T cond);
        lang::cc::Node::Stmt::IfElse_T with_xt(lang::cc::Node::Stmt_T xt);
        lang::cc::Node::Stmt::IfElse_T with_xf(lang::cc::Node::Stmt_T xf);
        void hash_ser_acc_lang_cc_Node_Stmt_IfElse(SerBuf& buf) const;
        virtual void hash_ser_acc(SerBuf& buf) const;
    };
}

void pr_debug(ostream& os, FmtFlags flags, lang::cc::Node::Stmt::For_T x);

namespace lang::cc::Node::Stmt::For {
    lang::cc::Node::Stmt::For_T make(Int id, lang_rt::TokenBounds bounds, bool is_top, lang_rt::ParserSymId sym, lang_rt::ParserAttrMask attr, lang_rt::ParserLookahead first_k, lang::cc::Node::ExprExt_T init, lang::cc::Node::Expr_T cond, lang::cc::Node::Expr_T incr, lang::cc::Node::Block_T body);
}

namespace lang::cc::Node::Stmt::For {
    lang::cc::Node::Stmt::For_T make_ext(ArenaPtr arena, Int id, lang_rt::TokenBounds bounds, bool is_top, lang_rt::ParserSymId sym, lang_rt::ParserAttrMask attr, lang_rt::ParserLookahead first_k, lang::cc::Node::ExprExt_T init, lang::cc::Node::Expr_T cond, lang::cc::Node::Expr_T incr, lang::cc::Node::Block_T body);
}

namespace lang::cc::Node::Stmt::For {
    struct _T: lang::cc::Node::Stmt::_T {
        void write(Ref<ostream> os, FmtFlags flags);
        void write(Ref<lang_rt::PrBufStream_T> pb);
        lang::cc::Node::ExprExt_T init_;
        lang::cc::Node::Expr_T cond_;
        lang::cc::Node::Expr_T incr_;
        lang::cc::Node::Block_T body_;
        _T();
        lang::cc::Node::Stmt::For_T with_id(Int id);
        lang::cc::Node::Stmt::For_T with_bounds(lang_rt::TokenBounds bounds);
        lang::cc::Node::Stmt::For_T with_is_top(bool is_top);
        lang::cc::Node::Stmt::For_T with_sym(lang_rt::ParserSymId sym);
        lang::cc::Node::Stmt::For_T with_attr(lang_rt::ParserAttrMask attr);
        lang::cc::Node::Stmt::For_T with_first_k(lang_rt::ParserLookahead first_k);
        lang::cc::Node::Stmt::For_T with_init(lang::cc::Node::ExprExt_T init);
        lang::cc::Node::Stmt::For_T with_cond(lang::cc::Node::Expr_T cond);
        lang::cc::Node::Stmt::For_T with_incr(lang::cc::Node::Expr_T incr);
        lang::cc::Node::Stmt::For_T with_body(lang::cc::Node::Block_T body);
        void hash_ser_acc_lang_cc_Node_Stmt_For(SerBuf& buf) const;
        virtual void hash_ser_acc(SerBuf& buf) const;
    };
}

void pr_debug(ostream& os, FmtFlags flags, lang::cc::Node::ExprExt::Expr_T x);

namespace lang::cc::Node::ExprExt::Expr {
    lang::cc::Node::ExprExt::Expr_T make(Int id, lang_rt::TokenBounds bounds, bool is_top, lang_rt::ParserSymId sym, lang_rt::ParserAttrMask attr, lang_rt::ParserLookahead first_k, lang::cc::Node::Expr_T e);
}

namespace lang::cc::Node::ExprExt::Expr {
    lang::cc::Node::ExprExt::Expr_T make_ext(ArenaPtr arena, Int id, lang_rt::TokenBounds bounds, bool is_top, lang_rt::ParserSymId sym, lang_rt::ParserAttrMask attr, lang_rt::ParserLookahead first_k, lang::cc::Node::Expr_T e);
}

namespace lang::cc::Node::ExprExt::Expr {
    struct _T: lang::cc::Node::ExprExt::_T {
        void write(Ref<ostream> os, FmtFlags flags);
        void write(Ref<lang_rt::PrBufStream_T> pb);
        lang::cc::Node::Expr_T e_;
        _T();
        lang::cc::Node::ExprExt::Expr_T with_id(Int id);
        lang::cc::Node::ExprExt::Expr_T with_bounds(lang_rt::TokenBounds bounds);
        lang::cc::Node::ExprExt::Expr_T with_is_top(bool is_top);
        lang::cc::Node::ExprExt::Expr_T with_sym(lang_rt::ParserSymId sym);
        lang::cc::Node::ExprExt::Expr_T with_attr(lang_rt::ParserAttrMask attr);
        lang::cc::Node::ExprExt::Expr_T with_first_k(lang_rt::ParserLookahead first_k);
        lang::cc::Node::ExprExt::Expr_T with_e(lang::cc::Node::Expr_T e);
        void hash_ser_acc_lang_cc_Node_ExprExt_Expr(SerBuf& buf) const;
        virtual void hash_ser_acc(SerBuf& buf) const;
    };
}

void pr_debug(ostream& os, FmtFlags flags, lang::cc::Node::ExprExt::Decl_T x);

namespace lang::cc::Node::ExprExt::Decl {
    lang::cc::Node::ExprExt::Decl_T make(Int id, lang_rt::TokenBounds bounds, bool is_top, lang_rt::ParserSymId sym, lang_rt::ParserAttrMask attr, lang_rt::ParserLookahead first_k, lang::cc::Node::TypedDecl_T decl);
}

namespace lang::cc::Node::ExprExt::Decl {
    lang::cc::Node::ExprExt::Decl_T make_ext(ArenaPtr arena, Int id, lang_rt::TokenBounds bounds, bool is_top, lang_rt::ParserSymId sym, lang_rt::ParserAttrMask attr, lang_rt::ParserLookahead first_k, lang::cc::Node::TypedDecl_T decl);
}

namespace lang::cc::Node::ExprExt::Decl {
    struct _T: lang::cc::Node::ExprExt::_T {
        void write(Ref<ostream> os, FmtFlags flags);
        void write(Ref<lang_rt::PrBufStream_T> pb);
        lang::cc::Node::TypedDecl_T decl_;
        _T();
        lang::cc::Node::ExprExt::Decl_T with_id(Int id);
        lang::cc::Node::ExprExt::Decl_T with_bounds(lang_rt::TokenBounds bounds);
        lang::cc::Node::ExprExt::Decl_T with_is_top(bool is_top);
        lang::cc::Node::ExprExt::Decl_T with_sym(lang_rt::ParserSymId sym);
        lang::cc::Node::ExprExt::Decl_T with_attr(lang_rt::ParserAttrMask attr);
        lang::cc::Node::ExprExt::Decl_T with_first_k(lang_rt::ParserLookahead first_k);
        lang::cc::Node::ExprExt::Decl_T with_decl(lang::cc::Node::TypedDecl_T decl);
        void hash_ser_acc_lang_cc_Node_ExprExt_Decl(SerBuf& buf) const;
        virtual void hash_ser_acc(SerBuf& buf) const;
    };
}

void pr_debug(ostream& os, FmtFlags flags, lang::cc::Node::Stmt::Switch_T x);

namespace lang::cc::Node::Stmt::Switch {
    lang::cc::Node::Stmt::Switch_T make(Int id, lang_rt::TokenBounds bounds, bool is_top, lang_rt::ParserSymId sym, lang_rt::ParserAttrMask attr, lang_rt::ParserLookahead first_k, lang::cc::Node::Expr_T val, Vec_T<lang::cc::Node::SwitchCase_T> cases);
}

namespace lang::cc::Node::Stmt::Switch {
    lang::cc::Node::Stmt::Switch_T make_ext(ArenaPtr arena, Int id, lang_rt::TokenBounds bounds, bool is_top, lang_rt::ParserSymId sym, lang_rt::ParserAttrMask attr, lang_rt::ParserLookahead first_k, lang::cc::Node::Expr_T val, Vec_T<lang::cc::Node::SwitchCase_T> cases);
}

namespace lang::cc::Node::Stmt::Switch {
    struct _T: lang::cc::Node::Stmt::_T {
        void write(Ref<ostream> os, FmtFlags flags);
        void write(Ref<lang_rt::PrBufStream_T> pb);
        lang::cc::Node::Expr_T val_;
        Vec_T<lang::cc::Node::SwitchCase_T> cases_;
        _T();
        lang::cc::Node::Stmt::Switch_T with_id(Int id);
        lang::cc::Node::Stmt::Switch_T with_bounds(lang_rt::TokenBounds bounds);
        lang::cc::Node::Stmt::Switch_T with_is_top(bool is_top);
        lang::cc::Node::Stmt::Switch_T with_sym(lang_rt::ParserSymId sym);
        lang::cc::Node::Stmt::Switch_T with_attr(lang_rt::ParserAttrMask attr);
        lang::cc::Node::Stmt::Switch_T with_first_k(lang_rt::ParserLookahead first_k);
        lang::cc::Node::Stmt::Switch_T with_val(lang::cc::Node::Expr_T val);
        lang::cc::Node::Stmt::Switch_T with_cases(Vec_T<lang::cc::Node::SwitchCase_T> cases);
        void hash_ser_acc_lang_cc_Node_Stmt_Switch(SerBuf& buf) const;
        virtual void hash_ser_acc(SerBuf& buf) const;
    };
}

void pr_debug(ostream& os, FmtFlags flags, lang::cc::Node::SwitchCase::Case_T x);

namespace lang::cc::Node::SwitchCase::Case {
    lang::cc::Node::SwitchCase::Case_T make(Int id, lang_rt::TokenBounds bounds, bool is_top, lang_rt::ParserSymId sym, lang_rt::ParserAttrMask attr, lang_rt::ParserLookahead first_k, lang::cc::Node::Expr_T val, lang::cc::Node::Block_T body);
}

namespace lang::cc::Node::SwitchCase::Case {
    lang::cc::Node::SwitchCase::Case_T make_ext(ArenaPtr arena, Int id, lang_rt::TokenBounds bounds, bool is_top, lang_rt::ParserSymId sym, lang_rt::ParserAttrMask attr, lang_rt::ParserLookahead first_k, lang::cc::Node::Expr_T val, lang::cc::Node::Block_T body);
}

namespace lang::cc::Node::SwitchCase::Case {
    struct _T: lang::cc::Node::SwitchCase::_T {
        void write(Ref<ostream> os, FmtFlags flags);
        void write(Ref<lang_rt::PrBufStream_T> pb);
        lang::cc::Node::Expr_T val_;
        lang::cc::Node::Block_T body_;
        _T();
        lang::cc::Node::SwitchCase::Case_T with_id(Int id);
        lang::cc::Node::SwitchCase::Case_T with_bounds(lang_rt::TokenBounds bounds);
        lang::cc::Node::SwitchCase::Case_T with_is_top(bool is_top);
        lang::cc::Node::SwitchCase::Case_T with_sym(lang_rt::ParserSymId sym);
        lang::cc::Node::SwitchCase::Case_T with_attr(lang_rt::ParserAttrMask attr);
        lang::cc::Node::SwitchCase::Case_T with_first_k(lang_rt::ParserLookahead first_k);
        lang::cc::Node::SwitchCase::Case_T with_val(lang::cc::Node::Expr_T val);
        lang::cc::Node::SwitchCase::Case_T with_body(lang::cc::Node::Block_T body);
        void hash_ser_acc_lang_cc_Node_SwitchCase_Case(SerBuf& buf) const;
        virtual void hash_ser_acc(SerBuf& buf) const;
    };
}

void pr_debug(ostream& os, FmtFlags flags, lang::cc::Node::SwitchCase::Default_T x);

namespace lang::cc::Node::SwitchCase::Default {
    lang::cc::Node::SwitchCase::Default_T make(Int id, lang_rt::TokenBounds bounds, bool is_top, lang_rt::ParserSymId sym, lang_rt::ParserAttrMask attr, lang_rt::ParserLookahead first_k, lang::cc::Node::Block_T body);
}

namespace lang::cc::Node::SwitchCase::Default {
    lang::cc::Node::SwitchCase::Default_T make_ext(ArenaPtr arena, Int id, lang_rt::TokenBounds bounds, bool is_top, lang_rt::ParserSymId sym, lang_rt::ParserAttrMask attr, lang_rt::ParserLookahead first_k, lang::cc::Node::Block_T body);
}

namespace lang::cc::Node::SwitchCase::Default {
    struct _T: lang::cc::Node::SwitchCase::_T {
        void write(Ref<ostream> os, FmtFlags flags);
        void write(Ref<lang_rt::PrBufStream_T> pb);
        lang::cc::Node::Block_T body_;
        _T();
        lang::cc::Node::SwitchCase::Default_T with_id(Int id);
        lang::cc::Node::SwitchCase::Default_T with_bounds(lang_rt::TokenBounds bounds);
        lang::cc::Node::SwitchCase::Default_T with_is_top(bool is_top);
        lang::cc::Node::SwitchCase::Default_T with_sym(lang_rt::ParserSymId sym);
        lang::cc::Node::SwitchCase::Default_T with_attr(lang_rt::ParserAttrMask attr);
        lang::cc::Node::SwitchCase::Default_T with_first_k(lang_rt::ParserLookahead first_k);
        lang::cc::Node::SwitchCase::Default_T with_body(lang::cc::Node::Block_T body);
        void hash_ser_acc_lang_cc_Node_SwitchCase_Default(SerBuf& buf) const;
        virtual void hash_ser_acc(SerBuf& buf) const;
    };
}

void pr_debug(ostream& os, FmtFlags flags, lang::cc::Node::Stmt::Break_T x);

namespace lang::cc::Node::Stmt::Break {
    lang::cc::Node::Stmt::Break_T make(Int id, lang_rt::TokenBounds bounds, bool is_top, lang_rt::ParserSymId sym, lang_rt::ParserAttrMask attr, lang_rt::ParserLookahead first_k);
}

namespace lang::cc::Node::Stmt::Break {
    lang::cc::Node::Stmt::Break_T make_ext(ArenaPtr arena, Int id, lang_rt::TokenBounds bounds, bool is_top, lang_rt::ParserSymId sym, lang_rt::ParserAttrMask attr, lang_rt::ParserLookahead first_k);
}

namespace lang::cc::Node::Stmt::Break {
    struct _T: lang::cc::Node::Stmt::_T {
        void write(Ref<ostream> os, FmtFlags flags);
        void write(Ref<lang_rt::PrBufStream_T> pb);
        _T();
        lang::cc::Node::Stmt::Break_T with_id(Int id);
        lang::cc::Node::Stmt::Break_T with_bounds(lang_rt::TokenBounds bounds);
        lang::cc::Node::Stmt::Break_T with_is_top(bool is_top);
        lang::cc::Node::Stmt::Break_T with_sym(lang_rt::ParserSymId sym);
        lang::cc::Node::Stmt::Break_T with_attr(lang_rt::ParserAttrMask attr);
        lang::cc::Node::Stmt::Break_T with_first_k(lang_rt::ParserLookahead first_k);
        void hash_ser_acc_lang_cc_Node_Stmt_Break(SerBuf& buf) const;
        virtual void hash_ser_acc(SerBuf& buf) const;
    };
}

void pr_debug(ostream& os, FmtFlags flags, lang::cc::Node::Stmt::Continue_T x);

namespace lang::cc::Node::Stmt::Continue {
    lang::cc::Node::Stmt::Continue_T make(Int id, lang_rt::TokenBounds bounds, bool is_top, lang_rt::ParserSymId sym, lang_rt::ParserAttrMask attr, lang_rt::ParserLookahead first_k);
}

namespace lang::cc::Node::Stmt::Continue {
    lang::cc::Node::Stmt::Continue_T make_ext(ArenaPtr arena, Int id, lang_rt::TokenBounds bounds, bool is_top, lang_rt::ParserSymId sym, lang_rt::ParserAttrMask attr, lang_rt::ParserLookahead first_k);
}

namespace lang::cc::Node::Stmt::Continue {
    struct _T: lang::cc::Node::Stmt::_T {
        void write(Ref<ostream> os, FmtFlags flags);
        void write(Ref<lang_rt::PrBufStream_T> pb);
        _T();
        lang::cc::Node::Stmt::Continue_T with_id(Int id);
        lang::cc::Node::Stmt::Continue_T with_bounds(lang_rt::TokenBounds bounds);
        lang::cc::Node::Stmt::Continue_T with_is_top(bool is_top);
        lang::cc::Node::Stmt::Continue_T with_sym(lang_rt::ParserSymId sym);
        lang::cc::Node::Stmt::Continue_T with_attr(lang_rt::ParserAttrMask attr);
        lang::cc::Node::Stmt::Continue_T with_first_k(lang_rt::ParserLookahead first_k);
        void hash_ser_acc_lang_cc_Node_Stmt_Continue(SerBuf& buf) const;
        virtual void hash_ser_acc(SerBuf& buf) const;
    };
}

void pr_debug(ostream& os, FmtFlags flags, lang::cc::Node::Stmt::Return_T x);

namespace lang::cc::Node::Stmt::Return {
    lang::cc::Node::Stmt::Return_T make(Int id, lang_rt::TokenBounds bounds, bool is_top, lang_rt::ParserSymId sym, lang_rt::ParserAttrMask attr, lang_rt::ParserLookahead first_k, Option_T<lang::cc::Node::Expr_T> val);
}

namespace lang::cc::Node::Stmt::Return {
    lang::cc::Node::Stmt::Return_T make_ext(ArenaPtr arena, Int id, lang_rt::TokenBounds bounds, bool is_top, lang_rt::ParserSymId sym, lang_rt::ParserAttrMask attr, lang_rt::ParserLookahead first_k, Option_T<lang::cc::Node::Expr_T> val);
}

namespace lang::cc::Node::Stmt::Return {
    struct _T: lang::cc::Node::Stmt::_T {
        void write(Ref<ostream> os, FmtFlags flags);
        void write(Ref<lang_rt::PrBufStream_T> pb);
        Option_T<lang::cc::Node::Expr_T> val_;
        _T();
        lang::cc::Node::Stmt::Return_T with_id(Int id);
        lang::cc::Node::Stmt::Return_T with_bounds(lang_rt::TokenBounds bounds);
        lang::cc::Node::Stmt::Return_T with_is_top(bool is_top);
        lang::cc::Node::Stmt::Return_T with_sym(lang_rt::ParserSymId sym);
        lang::cc::Node::Stmt::Return_T with_attr(lang_rt::ParserAttrMask attr);
        lang::cc::Node::Stmt::Return_T with_first_k(lang_rt::ParserLookahead first_k);
        lang::cc::Node::Stmt::Return_T with_val(Option_T<lang::cc::Node::Expr_T> val);
        void hash_ser_acc_lang_cc_Node_Stmt_Return(SerBuf& buf) const;
        virtual void hash_ser_acc(SerBuf& buf) const;
    };
}

void pr_debug(ostream& os, FmtFlags flags, lang::cc::Node::Expr::Paren_T x);

namespace lang::cc::Node::Expr::Paren {
    lang::cc::Node::Expr::Paren_T make(Int id, lang_rt::TokenBounds bounds, bool is_top, lang_rt::ParserSymId sym, lang_rt::ParserAttrMask attr, lang_rt::ParserLookahead first_k, lang::cc::Node::Expr_T x);
}

namespace lang::cc::Node::Expr::Paren {
    lang::cc::Node::Expr::Paren_T make_ext(ArenaPtr arena, Int id, lang_rt::TokenBounds bounds, bool is_top, lang_rt::ParserSymId sym, lang_rt::ParserAttrMask attr, lang_rt::ParserLookahead first_k, lang::cc::Node::Expr_T x);
}

namespace lang::cc::Node::Expr::Paren {
    struct _T: lang::cc::Node::Expr::_T {
        void write(Ref<ostream> os, FmtFlags flags);
        void write(Ref<lang_rt::PrBufStream_T> pb);
        lang::cc::Node::Expr_T x_;
        _T();
        lang::cc::Node::Expr::Paren_T with_id(Int id);
        lang::cc::Node::Expr::Paren_T with_bounds(lang_rt::TokenBounds bounds);
        lang::cc::Node::Expr::Paren_T with_is_top(bool is_top);
        lang::cc::Node::Expr::Paren_T with_sym(lang_rt::ParserSymId sym);
        lang::cc::Node::Expr::Paren_T with_attr(lang_rt::ParserAttrMask attr);
        lang::cc::Node::Expr::Paren_T with_first_k(lang_rt::ParserLookahead first_k);
        lang::cc::Node::Expr::Paren_T with_x(lang::cc::Node::Expr_T x);
        void hash_ser_acc_lang_cc_Node_Expr_Paren(SerBuf& buf) const;
        virtual void hash_ser_acc(SerBuf& buf) const;
    };
}

void pr_debug(ostream& os, FmtFlags flags, lang::cc::Node::Expr::Call_T x);

namespace lang::cc::Node::Expr::Call {
    lang::cc::Node::Expr::Call_T make(Int id, lang_rt::TokenBounds bounds, bool is_top, lang_rt::ParserSymId sym, lang_rt::ParserAttrMask attr, lang_rt::ParserLookahead first_k, lang::cc::Node::Expr_T f, Vec_T<lang::cc::Node::Expr_T> args);
}

namespace lang::cc::Node::Expr::Call {
    lang::cc::Node::Expr::Call_T make_ext(ArenaPtr arena, Int id, lang_rt::TokenBounds bounds, bool is_top, lang_rt::ParserSymId sym, lang_rt::ParserAttrMask attr, lang_rt::ParserLookahead first_k, lang::cc::Node::Expr_T f, Vec_T<lang::cc::Node::Expr_T> args);
}

namespace lang::cc::Node::Expr::Call {
    struct _T: lang::cc::Node::Expr::_T {
        void write(Ref<ostream> os, FmtFlags flags);
        void write(Ref<lang_rt::PrBufStream_T> pb);
        lang::cc::Node::Expr_T f_;
        Vec_T<lang::cc::Node::Expr_T> args_;
        _T();
        lang::cc::Node::Expr::Call_T with_id(Int id);
        lang::cc::Node::Expr::Call_T with_bounds(lang_rt::TokenBounds bounds);
        lang::cc::Node::Expr::Call_T with_is_top(bool is_top);
        lang::cc::Node::Expr::Call_T with_sym(lang_rt::ParserSymId sym);
        lang::cc::Node::Expr::Call_T with_attr(lang_rt::ParserAttrMask attr);
        lang::cc::Node::Expr::Call_T with_first_k(lang_rt::ParserLookahead first_k);
        lang::cc::Node::Expr::Call_T with_f(lang::cc::Node::Expr_T f);
        lang::cc::Node::Expr::Call_T with_args(Vec_T<lang::cc::Node::Expr_T> args);
        void hash_ser_acc_lang_cc_Node_Expr_Call(SerBuf& buf) const;
        virtual void hash_ser_acc(SerBuf& buf) const;
    };
}

void pr_debug(ostream& os, FmtFlags flags, lang::cc::Node::Expr::Index_T x);

namespace lang::cc::Node::Expr::Index {
    lang::cc::Node::Expr::Index_T make(Int id, lang_rt::TokenBounds bounds, bool is_top, lang_rt::ParserSymId sym, lang_rt::ParserAttrMask attr, lang_rt::ParserLookahead first_k, lang::cc::Node::Expr_T f, lang::cc::Node::Expr_T arg);
}

namespace lang::cc::Node::Expr::Index {
    lang::cc::Node::Expr::Index_T make_ext(ArenaPtr arena, Int id, lang_rt::TokenBounds bounds, bool is_top, lang_rt::ParserSymId sym, lang_rt::ParserAttrMask attr, lang_rt::ParserLookahead first_k, lang::cc::Node::Expr_T f, lang::cc::Node::Expr_T arg);
}

namespace lang::cc::Node::Expr::Index {
    struct _T: lang::cc::Node::Expr::_T {
        void write(Ref<ostream> os, FmtFlags flags);
        void write(Ref<lang_rt::PrBufStream_T> pb);
        lang::cc::Node::Expr_T f_;
        lang::cc::Node::Expr_T arg_;
        _T();
        lang::cc::Node::Expr::Index_T with_id(Int id);
        lang::cc::Node::Expr::Index_T with_bounds(lang_rt::TokenBounds bounds);
        lang::cc::Node::Expr::Index_T with_is_top(bool is_top);
        lang::cc::Node::Expr::Index_T with_sym(lang_rt::ParserSymId sym);
        lang::cc::Node::Expr::Index_T with_attr(lang_rt::ParserAttrMask attr);
        lang::cc::Node::Expr::Index_T with_first_k(lang_rt::ParserLookahead first_k);
        lang::cc::Node::Expr::Index_T with_f(lang::cc::Node::Expr_T f);
        lang::cc::Node::Expr::Index_T with_arg(lang::cc::Node::Expr_T arg);
        void hash_ser_acc_lang_cc_Node_Expr_Index(SerBuf& buf) const;
        virtual void hash_ser_acc(SerBuf& buf) const;
    };
}

void pr_debug(ostream& os, FmtFlags flags, lang::cc::Node::Expr::IndexEmpty_T x);

namespace lang::cc::Node::Expr::IndexEmpty {
    lang::cc::Node::Expr::IndexEmpty_T make(Int id, lang_rt::TokenBounds bounds, bool is_top, lang_rt::ParserSymId sym, lang_rt::ParserAttrMask attr, lang_rt::ParserLookahead first_k, lang::cc::Node::Expr_T f);
}

namespace lang::cc::Node::Expr::IndexEmpty {
    lang::cc::Node::Expr::IndexEmpty_T make_ext(ArenaPtr arena, Int id, lang_rt::TokenBounds bounds, bool is_top, lang_rt::ParserSymId sym, lang_rt::ParserAttrMask attr, lang_rt::ParserLookahead first_k, lang::cc::Node::Expr_T f);
}

namespace lang::cc::Node::Expr::IndexEmpty {
    struct _T: lang::cc::Node::Expr::_T {
        void write(Ref<ostream> os, FmtFlags flags);
        void write(Ref<lang_rt::PrBufStream_T> pb);
        lang::cc::Node::Expr_T f_;
        _T();
        lang::cc::Node::Expr::IndexEmpty_T with_id(Int id);
        lang::cc::Node::Expr::IndexEmpty_T with_bounds(lang_rt::TokenBounds bounds);
        lang::cc::Node::Expr::IndexEmpty_T with_is_top(bool is_top);
        lang::cc::Node::Expr::IndexEmpty_T with_sym(lang_rt::ParserSymId sym);
        lang::cc::Node::Expr::IndexEmpty_T with_attr(lang_rt::ParserAttrMask attr);
        lang::cc::Node::Expr::IndexEmpty_T with_first_k(lang_rt::ParserLookahead first_k);
        lang::cc::Node::Expr::IndexEmpty_T with_f(lang::cc::Node::Expr_T f);
        void hash_ser_acc_lang_cc_Node_Expr_IndexEmpty(SerBuf& buf) const;
        virtual void hash_ser_acc(SerBuf& buf) const;
    };
}

void pr_debug(ostream& os, FmtFlags flags, lang::cc::Node::Expr::Dot_T x);

namespace lang::cc::Node::Expr::Dot {
    lang::cc::Node::Expr::Dot_T make(Int id, lang_rt::TokenBounds bounds, bool is_top, lang_rt::ParserSymId sym, lang_rt::ParserAttrMask attr, lang_rt::ParserLookahead first_k, lang::cc::Node::Expr_T x, lang::cc::Node::Expr_T field);
}

namespace lang::cc::Node::Expr::Dot {
    lang::cc::Node::Expr::Dot_T make_ext(ArenaPtr arena, Int id, lang_rt::TokenBounds bounds, bool is_top, lang_rt::ParserSymId sym, lang_rt::ParserAttrMask attr, lang_rt::ParserLookahead first_k, lang::cc::Node::Expr_T x, lang::cc::Node::Expr_T field);
}

namespace lang::cc::Node::Expr::Dot {
    struct _T: lang::cc::Node::Expr::_T {
        void write(Ref<ostream> os, FmtFlags flags);
        void write(Ref<lang_rt::PrBufStream_T> pb);
        lang::cc::Node::Expr_T x_;
        lang::cc::Node::Expr_T field_;
        _T();
        lang::cc::Node::Expr::Dot_T with_id(Int id);
        lang::cc::Node::Expr::Dot_T with_bounds(lang_rt::TokenBounds bounds);
        lang::cc::Node::Expr::Dot_T with_is_top(bool is_top);
        lang::cc::Node::Expr::Dot_T with_sym(lang_rt::ParserSymId sym);
        lang::cc::Node::Expr::Dot_T with_attr(lang_rt::ParserAttrMask attr);
        lang::cc::Node::Expr::Dot_T with_first_k(lang_rt::ParserLookahead first_k);
        lang::cc::Node::Expr::Dot_T with_x(lang::cc::Node::Expr_T x);
        lang::cc::Node::Expr::Dot_T with_field(lang::cc::Node::Expr_T field);
        void hash_ser_acc_lang_cc_Node_Expr_Dot(SerBuf& buf) const;
        virtual void hash_ser_acc(SerBuf& buf) const;
    };
}

void pr_debug(ostream& os, FmtFlags flags, lang::cc::Node::Expr::Arrow_T x);

namespace lang::cc::Node::Expr::Arrow {
    lang::cc::Node::Expr::Arrow_T make(Int id, lang_rt::TokenBounds bounds, bool is_top, lang_rt::ParserSymId sym, lang_rt::ParserAttrMask attr, lang_rt::ParserLookahead first_k, lang::cc::Node::Expr_T x, lang::cc::Node::Expr_T field);
}

namespace lang::cc::Node::Expr::Arrow {
    lang::cc::Node::Expr::Arrow_T make_ext(ArenaPtr arena, Int id, lang_rt::TokenBounds bounds, bool is_top, lang_rt::ParserSymId sym, lang_rt::ParserAttrMask attr, lang_rt::ParserLookahead first_k, lang::cc::Node::Expr_T x, lang::cc::Node::Expr_T field);
}

namespace lang::cc::Node::Expr::Arrow {
    struct _T: lang::cc::Node::Expr::_T {
        void write(Ref<ostream> os, FmtFlags flags);
        void write(Ref<lang_rt::PrBufStream_T> pb);
        lang::cc::Node::Expr_T x_;
        lang::cc::Node::Expr_T field_;
        _T();
        lang::cc::Node::Expr::Arrow_T with_id(Int id);
        lang::cc::Node::Expr::Arrow_T with_bounds(lang_rt::TokenBounds bounds);
        lang::cc::Node::Expr::Arrow_T with_is_top(bool is_top);
        lang::cc::Node::Expr::Arrow_T with_sym(lang_rt::ParserSymId sym);
        lang::cc::Node::Expr::Arrow_T with_attr(lang_rt::ParserAttrMask attr);
        lang::cc::Node::Expr::Arrow_T with_first_k(lang_rt::ParserLookahead first_k);
        lang::cc::Node::Expr::Arrow_T with_x(lang::cc::Node::Expr_T x);
        lang::cc::Node::Expr::Arrow_T with_field(lang::cc::Node::Expr_T field);
        void hash_ser_acc_lang_cc_Node_Expr_Arrow(SerBuf& buf) const;
        virtual void hash_ser_acc(SerBuf& buf) const;
    };
}

void pr_debug(ostream& os, FmtFlags flags, lang::cc::Node::Expr::Ref__T x);

namespace lang::cc::Node::Expr::Ref_ {
    lang::cc::Node::Expr::Ref__T make(Int id, lang_rt::TokenBounds bounds, bool is_top, lang_rt::ParserSymId sym, lang_rt::ParserAttrMask attr, lang_rt::ParserLookahead first_k, lang::cc::Node::Expr_T x);
}

namespace lang::cc::Node::Expr::Ref_ {
    lang::cc::Node::Expr::Ref__T make_ext(ArenaPtr arena, Int id, lang_rt::TokenBounds bounds, bool is_top, lang_rt::ParserSymId sym, lang_rt::ParserAttrMask attr, lang_rt::ParserLookahead first_k, lang::cc::Node::Expr_T x);
}

namespace lang::cc::Node::Expr::Ref_ {
    struct _T: lang::cc::Node::Expr::_T {
        void write(Ref<ostream> os, FmtFlags flags);
        void write(Ref<lang_rt::PrBufStream_T> pb);
        lang::cc::Node::Expr_T x_;
        _T();
        lang::cc::Node::Expr::Ref__T with_id(Int id);
        lang::cc::Node::Expr::Ref__T with_bounds(lang_rt::TokenBounds bounds);
        lang::cc::Node::Expr::Ref__T with_is_top(bool is_top);
        lang::cc::Node::Expr::Ref__T with_sym(lang_rt::ParserSymId sym);
        lang::cc::Node::Expr::Ref__T with_attr(lang_rt::ParserAttrMask attr);
        lang::cc::Node::Expr::Ref__T with_first_k(lang_rt::ParserLookahead first_k);
        lang::cc::Node::Expr::Ref__T with_x(lang::cc::Node::Expr_T x);
        void hash_ser_acc_lang_cc_Node_Expr_Ref_(SerBuf& buf) const;
        virtual void hash_ser_acc(SerBuf& buf) const;
    };
}

void pr_debug(ostream& os, FmtFlags flags, lang::cc::Node::Expr::AddrOf_T x);

namespace lang::cc::Node::Expr::AddrOf {
    lang::cc::Node::Expr::AddrOf_T make(Int id, lang_rt::TokenBounds bounds, bool is_top, lang_rt::ParserSymId sym, lang_rt::ParserAttrMask attr, lang_rt::ParserLookahead first_k, lang::cc::Node::Expr_T x);
}

namespace lang::cc::Node::Expr::AddrOf {
    lang::cc::Node::Expr::AddrOf_T make_ext(ArenaPtr arena, Int id, lang_rt::TokenBounds bounds, bool is_top, lang_rt::ParserSymId sym, lang_rt::ParserAttrMask attr, lang_rt::ParserLookahead first_k, lang::cc::Node::Expr_T x);
}

namespace lang::cc::Node::Expr::AddrOf {
    struct _T: lang::cc::Node::Expr::_T {
        void write(Ref<ostream> os, FmtFlags flags);
        void write(Ref<lang_rt::PrBufStream_T> pb);
        lang::cc::Node::Expr_T x_;
        _T();
        lang::cc::Node::Expr::AddrOf_T with_id(Int id);
        lang::cc::Node::Expr::AddrOf_T with_bounds(lang_rt::TokenBounds bounds);
        lang::cc::Node::Expr::AddrOf_T with_is_top(bool is_top);
        lang::cc::Node::Expr::AddrOf_T with_sym(lang_rt::ParserSymId sym);
        lang::cc::Node::Expr::AddrOf_T with_attr(lang_rt::ParserAttrMask attr);
        lang::cc::Node::Expr::AddrOf_T with_first_k(lang_rt::ParserLookahead first_k);
        lang::cc::Node::Expr::AddrOf_T with_x(lang::cc::Node::Expr_T x);
        void hash_ser_acc_lang_cc_Node_Expr_AddrOf(SerBuf& buf) const;
        virtual void hash_ser_acc(SerBuf& buf) const;
    };
}

void pr_debug(ostream& os, FmtFlags flags, lang::cc::Node::Expr::Deref_T x);

namespace lang::cc::Node::Expr::Deref {
    lang::cc::Node::Expr::Deref_T make(Int id, lang_rt::TokenBounds bounds, bool is_top, lang_rt::ParserSymId sym, lang_rt::ParserAttrMask attr, lang_rt::ParserLookahead first_k, lang::cc::Node::Expr_T x);
}

namespace lang::cc::Node::Expr::Deref {
    lang::cc::Node::Expr::Deref_T make_ext(ArenaPtr arena, Int id, lang_rt::TokenBounds bounds, bool is_top, lang_rt::ParserSymId sym, lang_rt::ParserAttrMask attr, lang_rt::ParserLookahead first_k, lang::cc::Node::Expr_T x);
}

namespace lang::cc::Node::Expr::Deref {
    struct _T: lang::cc::Node::Expr::_T {
        void write(Ref<ostream> os, FmtFlags flags);
        void write(Ref<lang_rt::PrBufStream_T> pb);
        lang::cc::Node::Expr_T x_;
        _T();
        lang::cc::Node::Expr::Deref_T with_id(Int id);
        lang::cc::Node::Expr::Deref_T with_bounds(lang_rt::TokenBounds bounds);
        lang::cc::Node::Expr::Deref_T with_is_top(bool is_top);
        lang::cc::Node::Expr::Deref_T with_sym(lang_rt::ParserSymId sym);
        lang::cc::Node::Expr::Deref_T with_attr(lang_rt::ParserAttrMask attr);
        lang::cc::Node::Expr::Deref_T with_first_k(lang_rt::ParserLookahead first_k);
        lang::cc::Node::Expr::Deref_T with_x(lang::cc::Node::Expr_T x);
        void hash_ser_acc_lang_cc_Node_Expr_Deref(SerBuf& buf) const;
        virtual void hash_ser_acc(SerBuf& buf) const;
    };
}

void pr_debug(ostream& os, FmtFlags flags, lang::cc::Node::Expr::UnaryPre_T x);

namespace lang::cc::Node::Expr::UnaryPre {
    lang::cc::Node::Expr::UnaryPre_T make(Int id, lang_rt::TokenBounds bounds, bool is_top, lang_rt::ParserSymId sym, lang_rt::ParserAttrMask attr, lang_rt::ParserLookahead first_k, lang::cc::Node::Expr::UnaryPre::op_T op, lang::cc::Node::Expr_T x);
}

namespace lang::cc::Node::Expr::UnaryPre {
    lang::cc::Node::Expr::UnaryPre_T make_ext(ArenaPtr arena, Int id, lang_rt::TokenBounds bounds, bool is_top, lang_rt::ParserSymId sym, lang_rt::ParserAttrMask attr, lang_rt::ParserLookahead first_k, lang::cc::Node::Expr::UnaryPre::op_T op, lang::cc::Node::Expr_T x);
}

namespace lang::cc::Node::Expr::UnaryPre {
    struct _T: lang::cc::Node::Expr::_T {
        void write(Ref<ostream> os, FmtFlags flags);
        void write(Ref<lang_rt::PrBufStream_T> pb);
        lang::cc::Node::Expr::UnaryPre::op_T op_;
        lang::cc::Node::Expr_T x_;
        _T();
        lang::cc::Node::Expr::UnaryPre_T with_id(Int id);
        lang::cc::Node::Expr::UnaryPre_T with_bounds(lang_rt::TokenBounds bounds);
        lang::cc::Node::Expr::UnaryPre_T with_is_top(bool is_top);
        lang::cc::Node::Expr::UnaryPre_T with_sym(lang_rt::ParserSymId sym);
        lang::cc::Node::Expr::UnaryPre_T with_attr(lang_rt::ParserAttrMask attr);
        lang::cc::Node::Expr::UnaryPre_T with_first_k(lang_rt::ParserLookahead first_k);
        lang::cc::Node::Expr::UnaryPre_T with_op(lang::cc::Node::Expr::UnaryPre::op_T op);
        lang::cc::Node::Expr::UnaryPre_T with_x(lang::cc::Node::Expr_T x);
        void hash_ser_acc_lang_cc_Node_Expr_UnaryPre(SerBuf& buf) const;
        virtual void hash_ser_acc(SerBuf& buf) const;
    };
}

void pr_debug(ostream& os, FmtFlags flags, lang::cc::Node::Expr::IncDecPre_T x);

namespace lang::cc::Node::Expr::IncDecPre {
    lang::cc::Node::Expr::IncDecPre_T make(Int id, lang_rt::TokenBounds bounds, bool is_top, lang_rt::ParserSymId sym, lang_rt::ParserAttrMask attr, lang_rt::ParserLookahead first_k, lang::cc::Node::Expr::IncDecPre::op_T op, lang::cc::Node::Expr_T x);
}

namespace lang::cc::Node::Expr::IncDecPre {
    lang::cc::Node::Expr::IncDecPre_T make_ext(ArenaPtr arena, Int id, lang_rt::TokenBounds bounds, bool is_top, lang_rt::ParserSymId sym, lang_rt::ParserAttrMask attr, lang_rt::ParserLookahead first_k, lang::cc::Node::Expr::IncDecPre::op_T op, lang::cc::Node::Expr_T x);
}

namespace lang::cc::Node::Expr::IncDecPre {
    struct _T: lang::cc::Node::Expr::_T {
        void write(Ref<ostream> os, FmtFlags flags);
        void write(Ref<lang_rt::PrBufStream_T> pb);
        lang::cc::Node::Expr::IncDecPre::op_T op_;
        lang::cc::Node::Expr_T x_;
        _T();
        lang::cc::Node::Expr::IncDecPre_T with_id(Int id);
        lang::cc::Node::Expr::IncDecPre_T with_bounds(lang_rt::TokenBounds bounds);
        lang::cc::Node::Expr::IncDecPre_T with_is_top(bool is_top);
        lang::cc::Node::Expr::IncDecPre_T with_sym(lang_rt::ParserSymId sym);
        lang::cc::Node::Expr::IncDecPre_T with_attr(lang_rt::ParserAttrMask attr);
        lang::cc::Node::Expr::IncDecPre_T with_first_k(lang_rt::ParserLookahead first_k);
        lang::cc::Node::Expr::IncDecPre_T with_op(lang::cc::Node::Expr::IncDecPre::op_T op);
        lang::cc::Node::Expr::IncDecPre_T with_x(lang::cc::Node::Expr_T x);
        void hash_ser_acc_lang_cc_Node_Expr_IncDecPre(SerBuf& buf) const;
        virtual void hash_ser_acc(SerBuf& buf) const;
    };
}

void pr_debug(ostream& os, FmtFlags flags, lang::cc::Node::Expr::IncDecPost_T x);

namespace lang::cc::Node::Expr::IncDecPost {
    lang::cc::Node::Expr::IncDecPost_T make(Int id, lang_rt::TokenBounds bounds, bool is_top, lang_rt::ParserSymId sym, lang_rt::ParserAttrMask attr, lang_rt::ParserLookahead first_k, lang::cc::Node::Expr_T x, lang::cc::Node::Expr::IncDecPost::op_T op);
}

namespace lang::cc::Node::Expr::IncDecPost {
    lang::cc::Node::Expr::IncDecPost_T make_ext(ArenaPtr arena, Int id, lang_rt::TokenBounds bounds, bool is_top, lang_rt::ParserSymId sym, lang_rt::ParserAttrMask attr, lang_rt::ParserLookahead first_k, lang::cc::Node::Expr_T x, lang::cc::Node::Expr::IncDecPost::op_T op);
}

namespace lang::cc::Node::Expr::IncDecPost {
    struct _T: lang::cc::Node::Expr::_T {
        void write(Ref<ostream> os, FmtFlags flags);
        void write(Ref<lang_rt::PrBufStream_T> pb);
        lang::cc::Node::Expr_T x_;
        lang::cc::Node::Expr::IncDecPost::op_T op_;
        _T();
        lang::cc::Node::Expr::IncDecPost_T with_id(Int id);
        lang::cc::Node::Expr::IncDecPost_T with_bounds(lang_rt::TokenBounds bounds);
        lang::cc::Node::Expr::IncDecPost_T with_is_top(bool is_top);
        lang::cc::Node::Expr::IncDecPost_T with_sym(lang_rt::ParserSymId sym);
        lang::cc::Node::Expr::IncDecPost_T with_attr(lang_rt::ParserAttrMask attr);
        lang::cc::Node::Expr::IncDecPost_T with_first_k(lang_rt::ParserLookahead first_k);
        lang::cc::Node::Expr::IncDecPost_T with_x(lang::cc::Node::Expr_T x);
        lang::cc::Node::Expr::IncDecPost_T with_op(lang::cc::Node::Expr::IncDecPost::op_T op);
        void hash_ser_acc_lang_cc_Node_Expr_IncDecPost(SerBuf& buf) const;
        virtual void hash_ser_acc(SerBuf& buf) const;
    };
}

void pr_debug(ostream& os, FmtFlags flags, lang::cc::Node::Expr::Assign_T x);

namespace lang::cc::Node::Expr::Assign {
    lang::cc::Node::Expr::Assign_T make(Int id, lang_rt::TokenBounds bounds, bool is_top, lang_rt::ParserSymId sym, lang_rt::ParserAttrMask attr, lang_rt::ParserLookahead first_k, lang::cc::Node::Expr_T xl, lang::cc::Node::Expr_T xr);
}

namespace lang::cc::Node::Expr::Assign {
    lang::cc::Node::Expr::Assign_T make_ext(ArenaPtr arena, Int id, lang_rt::TokenBounds bounds, bool is_top, lang_rt::ParserSymId sym, lang_rt::ParserAttrMask attr, lang_rt::ParserLookahead first_k, lang::cc::Node::Expr_T xl, lang::cc::Node::Expr_T xr);
}

namespace lang::cc::Node::Expr::Assign {
    struct _T: lang::cc::Node::Expr::_T {
        void write(Ref<ostream> os, FmtFlags flags);
        void write(Ref<lang_rt::PrBufStream_T> pb);
        lang::cc::Node::Expr_T xl_;
        lang::cc::Node::Expr_T xr_;
        _T();
        lang::cc::Node::Expr::Assign_T with_id(Int id);
        lang::cc::Node::Expr::Assign_T with_bounds(lang_rt::TokenBounds bounds);
        lang::cc::Node::Expr::Assign_T with_is_top(bool is_top);
        lang::cc::Node::Expr::Assign_T with_sym(lang_rt::ParserSymId sym);
        lang::cc::Node::Expr::Assign_T with_attr(lang_rt::ParserAttrMask attr);
        lang::cc::Node::Expr::Assign_T with_first_k(lang_rt::ParserLookahead first_k);
        lang::cc::Node::Expr::Assign_T with_xl(lang::cc::Node::Expr_T xl);
        lang::cc::Node::Expr::Assign_T with_xr(lang::cc::Node::Expr_T xr);
        void hash_ser_acc_lang_cc_Node_Expr_Assign(SerBuf& buf) const;
        virtual void hash_ser_acc(SerBuf& buf) const;
    };
}

void pr_debug(ostream& os, FmtFlags flags, lang::cc::Node::Expr::Bin1_T x);

namespace lang::cc::Node::Expr::Bin1 {
    lang::cc::Node::Expr::Bin1_T make(Int id, lang_rt::TokenBounds bounds, bool is_top, lang_rt::ParserSymId sym, lang_rt::ParserAttrMask attr, lang_rt::ParserLookahead first_k, lang::cc::Node::Expr_T xl, lang::cc::Node::Expr::Bin1::op_T op, lang::cc::Node::Expr_T xr);
}

namespace lang::cc::Node::Expr::Bin1 {
    lang::cc::Node::Expr::Bin1_T make_ext(ArenaPtr arena, Int id, lang_rt::TokenBounds bounds, bool is_top, lang_rt::ParserSymId sym, lang_rt::ParserAttrMask attr, lang_rt::ParserLookahead first_k, lang::cc::Node::Expr_T xl, lang::cc::Node::Expr::Bin1::op_T op, lang::cc::Node::Expr_T xr);
}

namespace lang::cc::Node::Expr::Bin1 {
    struct _T: lang::cc::Node::Expr::_T {
        void write(Ref<ostream> os, FmtFlags flags);
        void write(Ref<lang_rt::PrBufStream_T> pb);
        lang::cc::Node::Expr_T xl_;
        lang::cc::Node::Expr::Bin1::op_T op_;
        lang::cc::Node::Expr_T xr_;
        _T();
        lang::cc::Node::Expr::Bin1_T with_id(Int id);
        lang::cc::Node::Expr::Bin1_T with_bounds(lang_rt::TokenBounds bounds);
        lang::cc::Node::Expr::Bin1_T with_is_top(bool is_top);
        lang::cc::Node::Expr::Bin1_T with_sym(lang_rt::ParserSymId sym);
        lang::cc::Node::Expr::Bin1_T with_attr(lang_rt::ParserAttrMask attr);
        lang::cc::Node::Expr::Bin1_T with_first_k(lang_rt::ParserLookahead first_k);
        lang::cc::Node::Expr::Bin1_T with_xl(lang::cc::Node::Expr_T xl);
        lang::cc::Node::Expr::Bin1_T with_op(lang::cc::Node::Expr::Bin1::op_T op);
        lang::cc::Node::Expr::Bin1_T with_xr(lang::cc::Node::Expr_T xr);
        void hash_ser_acc_lang_cc_Node_Expr_Bin1(SerBuf& buf) const;
        virtual void hash_ser_acc(SerBuf& buf) const;
    };
}

void pr_debug(ostream& os, FmtFlags flags, lang::cc::Node::Expr::Bin2_T x);

namespace lang::cc::Node::Expr::Bin2 {
    lang::cc::Node::Expr::Bin2_T make(Int id, lang_rt::TokenBounds bounds, bool is_top, lang_rt::ParserSymId sym, lang_rt::ParserAttrMask attr, lang_rt::ParserLookahead first_k, lang::cc::Node::Expr_T xl, lang::cc::Node::Expr::Bin2::op_T op, lang::cc::Node::Expr_T xr);
}

namespace lang::cc::Node::Expr::Bin2 {
    lang::cc::Node::Expr::Bin2_T make_ext(ArenaPtr arena, Int id, lang_rt::TokenBounds bounds, bool is_top, lang_rt::ParserSymId sym, lang_rt::ParserAttrMask attr, lang_rt::ParserLookahead first_k, lang::cc::Node::Expr_T xl, lang::cc::Node::Expr::Bin2::op_T op, lang::cc::Node::Expr_T xr);
}

namespace lang::cc::Node::Expr::Bin2 {
    struct _T: lang::cc::Node::Expr::_T {
        void write(Ref<ostream> os, FmtFlags flags);
        void write(Ref<lang_rt::PrBufStream_T> pb);
        lang::cc::Node::Expr_T xl_;
        lang::cc::Node::Expr::Bin2::op_T op_;
        lang::cc::Node::Expr_T xr_;
        _T();
        lang::cc::Node::Expr::Bin2_T with_id(Int id);
        lang::cc::Node::Expr::Bin2_T with_bounds(lang_rt::TokenBounds bounds);
        lang::cc::Node::Expr::Bin2_T with_is_top(bool is_top);
        lang::cc::Node::Expr::Bin2_T with_sym(lang_rt::ParserSymId sym);
        lang::cc::Node::Expr::Bin2_T with_attr(lang_rt::ParserAttrMask attr);
        lang::cc::Node::Expr::Bin2_T with_first_k(lang_rt::ParserLookahead first_k);
        lang::cc::Node::Expr::Bin2_T with_xl(lang::cc::Node::Expr_T xl);
        lang::cc::Node::Expr::Bin2_T with_op(lang::cc::Node::Expr::Bin2::op_T op);
        lang::cc::Node::Expr::Bin2_T with_xr(lang::cc::Node::Expr_T xr);
        void hash_ser_acc_lang_cc_Node_Expr_Bin2(SerBuf& buf) const;
        virtual void hash_ser_acc(SerBuf& buf) const;
    };
}

void pr_debug(ostream& os, FmtFlags flags, lang::cc::Node::Expr::Bin3_T x);

namespace lang::cc::Node::Expr::Bin3 {
    lang::cc::Node::Expr::Bin3_T make(Int id, lang_rt::TokenBounds bounds, bool is_top, lang_rt::ParserSymId sym, lang_rt::ParserAttrMask attr, lang_rt::ParserLookahead first_k, lang::cc::Node::Expr_T xl, lang::cc::Node::Expr::Bin3::op_T op, lang::cc::Node::Expr_T xr);
}

namespace lang::cc::Node::Expr::Bin3 {
    lang::cc::Node::Expr::Bin3_T make_ext(ArenaPtr arena, Int id, lang_rt::TokenBounds bounds, bool is_top, lang_rt::ParserSymId sym, lang_rt::ParserAttrMask attr, lang_rt::ParserLookahead first_k, lang::cc::Node::Expr_T xl, lang::cc::Node::Expr::Bin3::op_T op, lang::cc::Node::Expr_T xr);
}

namespace lang::cc::Node::Expr::Bin3 {
    struct _T: lang::cc::Node::Expr::_T {
        void write(Ref<ostream> os, FmtFlags flags);
        void write(Ref<lang_rt::PrBufStream_T> pb);
        lang::cc::Node::Expr_T xl_;
        lang::cc::Node::Expr::Bin3::op_T op_;
        lang::cc::Node::Expr_T xr_;
        _T();
        lang::cc::Node::Expr::Bin3_T with_id(Int id);
        lang::cc::Node::Expr::Bin3_T with_bounds(lang_rt::TokenBounds bounds);
        lang::cc::Node::Expr::Bin3_T with_is_top(bool is_top);
        lang::cc::Node::Expr::Bin3_T with_sym(lang_rt::ParserSymId sym);
        lang::cc::Node::Expr::Bin3_T with_attr(lang_rt::ParserAttrMask attr);
        lang::cc::Node::Expr::Bin3_T with_first_k(lang_rt::ParserLookahead first_k);
        lang::cc::Node::Expr::Bin3_T with_xl(lang::cc::Node::Expr_T xl);
        lang::cc::Node::Expr::Bin3_T with_op(lang::cc::Node::Expr::Bin3::op_T op);
        lang::cc::Node::Expr::Bin3_T with_xr(lang::cc::Node::Expr_T xr);
        void hash_ser_acc_lang_cc_Node_Expr_Bin3(SerBuf& buf) const;
        virtual void hash_ser_acc(SerBuf& buf) const;
    };
}

void pr_debug(ostream& os, FmtFlags flags, lang::cc::Node::Expr::Bin4_T x);

namespace lang::cc::Node::Expr::Bin4 {
    lang::cc::Node::Expr::Bin4_T make(Int id, lang_rt::TokenBounds bounds, bool is_top, lang_rt::ParserSymId sym, lang_rt::ParserAttrMask attr, lang_rt::ParserLookahead first_k, lang::cc::Node::Expr_T xl, lang::cc::Node::Expr::Bin4::op_T op, lang::cc::Node::Expr_T xr);
}

namespace lang::cc::Node::Expr::Bin4 {
    lang::cc::Node::Expr::Bin4_T make_ext(ArenaPtr arena, Int id, lang_rt::TokenBounds bounds, bool is_top, lang_rt::ParserSymId sym, lang_rt::ParserAttrMask attr, lang_rt::ParserLookahead first_k, lang::cc::Node::Expr_T xl, lang::cc::Node::Expr::Bin4::op_T op, lang::cc::Node::Expr_T xr);
}

namespace lang::cc::Node::Expr::Bin4 {
    struct _T: lang::cc::Node::Expr::_T {
        void write(Ref<ostream> os, FmtFlags flags);
        void write(Ref<lang_rt::PrBufStream_T> pb);
        lang::cc::Node::Expr_T xl_;
        lang::cc::Node::Expr::Bin4::op_T op_;
        lang::cc::Node::Expr_T xr_;
        _T();
        lang::cc::Node::Expr::Bin4_T with_id(Int id);
        lang::cc::Node::Expr::Bin4_T with_bounds(lang_rt::TokenBounds bounds);
        lang::cc::Node::Expr::Bin4_T with_is_top(bool is_top);
        lang::cc::Node::Expr::Bin4_T with_sym(lang_rt::ParserSymId sym);
        lang::cc::Node::Expr::Bin4_T with_attr(lang_rt::ParserAttrMask attr);
        lang::cc::Node::Expr::Bin4_T with_first_k(lang_rt::ParserLookahead first_k);
        lang::cc::Node::Expr::Bin4_T with_xl(lang::cc::Node::Expr_T xl);
        lang::cc::Node::Expr::Bin4_T with_op(lang::cc::Node::Expr::Bin4::op_T op);
        lang::cc::Node::Expr::Bin4_T with_xr(lang::cc::Node::Expr_T xr);
        void hash_ser_acc_lang_cc_Node_Expr_Bin4(SerBuf& buf) const;
        virtual void hash_ser_acc(SerBuf& buf) const;
    };
}

void pr_debug(ostream& os, FmtFlags flags, lang::cc::Node::Expr::Bin5_T x);

namespace lang::cc::Node::Expr::Bin5 {
    lang::cc::Node::Expr::Bin5_T make(Int id, lang_rt::TokenBounds bounds, bool is_top, lang_rt::ParserSymId sym, lang_rt::ParserAttrMask attr, lang_rt::ParserLookahead first_k, lang::cc::Node::Expr_T xl, lang::cc::Node::Expr::Bin5::op_T op, lang::cc::Node::Expr_T xr);
}

namespace lang::cc::Node::Expr::Bin5 {
    lang::cc::Node::Expr::Bin5_T make_ext(ArenaPtr arena, Int id, lang_rt::TokenBounds bounds, bool is_top, lang_rt::ParserSymId sym, lang_rt::ParserAttrMask attr, lang_rt::ParserLookahead first_k, lang::cc::Node::Expr_T xl, lang::cc::Node::Expr::Bin5::op_T op, lang::cc::Node::Expr_T xr);
}

namespace lang::cc::Node::Expr::Bin5 {
    struct _T: lang::cc::Node::Expr::_T {
        void write(Ref<ostream> os, FmtFlags flags);
        void write(Ref<lang_rt::PrBufStream_T> pb);
        lang::cc::Node::Expr_T xl_;
        lang::cc::Node::Expr::Bin5::op_T op_;
        lang::cc::Node::Expr_T xr_;
        _T();
        lang::cc::Node::Expr::Bin5_T with_id(Int id);
        lang::cc::Node::Expr::Bin5_T with_bounds(lang_rt::TokenBounds bounds);
        lang::cc::Node::Expr::Bin5_T with_is_top(bool is_top);
        lang::cc::Node::Expr::Bin5_T with_sym(lang_rt::ParserSymId sym);
        lang::cc::Node::Expr::Bin5_T with_attr(lang_rt::ParserAttrMask attr);
        lang::cc::Node::Expr::Bin5_T with_first_k(lang_rt::ParserLookahead first_k);
        lang::cc::Node::Expr::Bin5_T with_xl(lang::cc::Node::Expr_T xl);
        lang::cc::Node::Expr::Bin5_T with_op(lang::cc::Node::Expr::Bin5::op_T op);
        lang::cc::Node::Expr::Bin5_T with_xr(lang::cc::Node::Expr_T xr);
        void hash_ser_acc_lang_cc_Node_Expr_Bin5(SerBuf& buf) const;
        virtual void hash_ser_acc(SerBuf& buf) const;
    };
}

void pr_debug(ostream& os, FmtFlags flags, lang::cc::Node::Expr::Bin6_T x);

namespace lang::cc::Node::Expr::Bin6 {
    lang::cc::Node::Expr::Bin6_T make(Int id, lang_rt::TokenBounds bounds, bool is_top, lang_rt::ParserSymId sym, lang_rt::ParserAttrMask attr, lang_rt::ParserLookahead first_k, lang::cc::Node::Expr_T xl, lang::cc::Node::Expr::Bin6::op_T op, lang::cc::Node::Expr_T xr);
}

namespace lang::cc::Node::Expr::Bin6 {
    lang::cc::Node::Expr::Bin6_T make_ext(ArenaPtr arena, Int id, lang_rt::TokenBounds bounds, bool is_top, lang_rt::ParserSymId sym, lang_rt::ParserAttrMask attr, lang_rt::ParserLookahead first_k, lang::cc::Node::Expr_T xl, lang::cc::Node::Expr::Bin6::op_T op, lang::cc::Node::Expr_T xr);
}

namespace lang::cc::Node::Expr::Bin6 {
    struct _T: lang::cc::Node::Expr::_T {
        void write(Ref<ostream> os, FmtFlags flags);
        void write(Ref<lang_rt::PrBufStream_T> pb);
        lang::cc::Node::Expr_T xl_;
        lang::cc::Node::Expr::Bin6::op_T op_;
        lang::cc::Node::Expr_T xr_;
        _T();
        lang::cc::Node::Expr::Bin6_T with_id(Int id);
        lang::cc::Node::Expr::Bin6_T with_bounds(lang_rt::TokenBounds bounds);
        lang::cc::Node::Expr::Bin6_T with_is_top(bool is_top);
        lang::cc::Node::Expr::Bin6_T with_sym(lang_rt::ParserSymId sym);
        lang::cc::Node::Expr::Bin6_T with_attr(lang_rt::ParserAttrMask attr);
        lang::cc::Node::Expr::Bin6_T with_first_k(lang_rt::ParserLookahead first_k);
        lang::cc::Node::Expr::Bin6_T with_xl(lang::cc::Node::Expr_T xl);
        lang::cc::Node::Expr::Bin6_T with_op(lang::cc::Node::Expr::Bin6::op_T op);
        lang::cc::Node::Expr::Bin6_T with_xr(lang::cc::Node::Expr_T xr);
        void hash_ser_acc_lang_cc_Node_Expr_Bin6(SerBuf& buf) const;
        virtual void hash_ser_acc(SerBuf& buf) const;
    };
}

void pr_debug(ostream& os, FmtFlags flags, lang::cc::Node::Expr::Template_T x);

namespace lang::cc::Node::Expr::Template {
    lang::cc::Node::Expr::Template_T make(Int id, lang_rt::TokenBounds bounds, bool is_top, lang_rt::ParserSymId sym, lang_rt::ParserAttrMask attr, lang_rt::ParserLookahead first_k, lang::cc::Node::Expr_T x, Vec_T<lang::cc::Node::Expr_T> args);
}

namespace lang::cc::Node::Expr::Template {
    lang::cc::Node::Expr::Template_T make_ext(ArenaPtr arena, Int id, lang_rt::TokenBounds bounds, bool is_top, lang_rt::ParserSymId sym, lang_rt::ParserAttrMask attr, lang_rt::ParserLookahead first_k, lang::cc::Node::Expr_T x, Vec_T<lang::cc::Node::Expr_T> args);
}

namespace lang::cc::Node::Expr::Template {
    struct _T: lang::cc::Node::Expr::_T {
        void write(Ref<ostream> os, FmtFlags flags);
        void write(Ref<lang_rt::PrBufStream_T> pb);
        lang::cc::Node::Expr_T x_;
        Vec_T<lang::cc::Node::Expr_T> args_;
        _T();
        lang::cc::Node::Expr::Template_T with_id(Int id);
        lang::cc::Node::Expr::Template_T with_bounds(lang_rt::TokenBounds bounds);
        lang::cc::Node::Expr::Template_T with_is_top(bool is_top);
        lang::cc::Node::Expr::Template_T with_sym(lang_rt::ParserSymId sym);
        lang::cc::Node::Expr::Template_T with_attr(lang_rt::ParserAttrMask attr);
        lang::cc::Node::Expr::Template_T with_first_k(lang_rt::ParserLookahead first_k);
        lang::cc::Node::Expr::Template_T with_x(lang::cc::Node::Expr_T x);
        lang::cc::Node::Expr::Template_T with_args(Vec_T<lang::cc::Node::Expr_T> args);
        void hash_ser_acc_lang_cc_Node_Expr_Template(SerBuf& buf) const;
        virtual void hash_ser_acc(SerBuf& buf) const;
    };
}

void pr_debug(ostream& os, FmtFlags flags, lang::cc::Node::Expr::New_T x);

namespace lang::cc::Node::Expr::New {
    lang::cc::Node::Expr::New_T make(Int id, lang_rt::TokenBounds bounds, bool is_top, lang_rt::ParserSymId sym, lang_rt::ParserAttrMask attr, lang_rt::ParserLookahead first_k, lang::cc::Node::Expr_T x);
}

namespace lang::cc::Node::Expr::New {
    lang::cc::Node::Expr::New_T make_ext(ArenaPtr arena, Int id, lang_rt::TokenBounds bounds, bool is_top, lang_rt::ParserSymId sym, lang_rt::ParserAttrMask attr, lang_rt::ParserLookahead first_k, lang::cc::Node::Expr_T x);
}

namespace lang::cc::Node::Expr::New {
    struct _T: lang::cc::Node::Expr::_T {
        void write(Ref<ostream> os, FmtFlags flags);
        void write(Ref<lang_rt::PrBufStream_T> pb);
        lang::cc::Node::Expr_T x_;
        _T();
        lang::cc::Node::Expr::New_T with_id(Int id);
        lang::cc::Node::Expr::New_T with_bounds(lang_rt::TokenBounds bounds);
        lang::cc::Node::Expr::New_T with_is_top(bool is_top);
        lang::cc::Node::Expr::New_T with_sym(lang_rt::ParserSymId sym);
        lang::cc::Node::Expr::New_T with_attr(lang_rt::ParserAttrMask attr);
        lang::cc::Node::Expr::New_T with_first_k(lang_rt::ParserLookahead first_k);
        lang::cc::Node::Expr::New_T with_x(lang::cc::Node::Expr_T x);
        void hash_ser_acc_lang_cc_Node_Expr_New(SerBuf& buf) const;
        virtual void hash_ser_acc(SerBuf& buf) const;
    };
}

void pr_debug(ostream& os, FmtFlags flags, lang::cc::Node::Expr::Delete_T x);

namespace lang::cc::Node::Expr::Delete {
    lang::cc::Node::Expr::Delete_T make(Int id, lang_rt::TokenBounds bounds, bool is_top, lang_rt::ParserSymId sym, lang_rt::ParserAttrMask attr, lang_rt::ParserLookahead first_k, lang::cc::Node::Expr_T x);
}

namespace lang::cc::Node::Expr::Delete {
    lang::cc::Node::Expr::Delete_T make_ext(ArenaPtr arena, Int id, lang_rt::TokenBounds bounds, bool is_top, lang_rt::ParserSymId sym, lang_rt::ParserAttrMask attr, lang_rt::ParserLookahead first_k, lang::cc::Node::Expr_T x);
}

namespace lang::cc::Node::Expr::Delete {
    struct _T: lang::cc::Node::Expr::_T {
        void write(Ref<ostream> os, FmtFlags flags);
        void write(Ref<lang_rt::PrBufStream_T> pb);
        lang::cc::Node::Expr_T x_;
        _T();
        lang::cc::Node::Expr::Delete_T with_id(Int id);
        lang::cc::Node::Expr::Delete_T with_bounds(lang_rt::TokenBounds bounds);
        lang::cc::Node::Expr::Delete_T with_is_top(bool is_top);
        lang::cc::Node::Expr::Delete_T with_sym(lang_rt::ParserSymId sym);
        lang::cc::Node::Expr::Delete_T with_attr(lang_rt::ParserAttrMask attr);
        lang::cc::Node::Expr::Delete_T with_first_k(lang_rt::ParserLookahead first_k);
        lang::cc::Node::Expr::Delete_T with_x(lang::cc::Node::Expr_T x);
        void hash_ser_acc_lang_cc_Node_Expr_Delete(SerBuf& buf) const;
        virtual void hash_ser_acc(SerBuf& buf) const;
    };
}

void pr_debug(ostream& os, FmtFlags flags, lang::cc::Node::Expr::Ellipsis_T x);

namespace lang::cc::Node::Expr::Ellipsis {
    lang::cc::Node::Expr::Ellipsis_T make(Int id, lang_rt::TokenBounds bounds, bool is_top, lang_rt::ParserSymId sym, lang_rt::ParserAttrMask attr, lang_rt::ParserLookahead first_k, lang::cc::Node::Expr_T x);
}

namespace lang::cc::Node::Expr::Ellipsis {
    lang::cc::Node::Expr::Ellipsis_T make_ext(ArenaPtr arena, Int id, lang_rt::TokenBounds bounds, bool is_top, lang_rt::ParserSymId sym, lang_rt::ParserAttrMask attr, lang_rt::ParserLookahead first_k, lang::cc::Node::Expr_T x);
}

namespace lang::cc::Node::Expr::Ellipsis {
    struct _T: lang::cc::Node::Expr::_T {
        void write(Ref<ostream> os, FmtFlags flags);
        void write(Ref<lang_rt::PrBufStream_T> pb);
        lang::cc::Node::Expr_T x_;
        _T();
        lang::cc::Node::Expr::Ellipsis_T with_id(Int id);
        lang::cc::Node::Expr::Ellipsis_T with_bounds(lang_rt::TokenBounds bounds);
        lang::cc::Node::Expr::Ellipsis_T with_is_top(bool is_top);
        lang::cc::Node::Expr::Ellipsis_T with_sym(lang_rt::ParserSymId sym);
        lang::cc::Node::Expr::Ellipsis_T with_attr(lang_rt::ParserAttrMask attr);
        lang::cc::Node::Expr::Ellipsis_T with_first_k(lang_rt::ParserLookahead first_k);
        lang::cc::Node::Expr::Ellipsis_T with_x(lang::cc::Node::Expr_T x);
        void hash_ser_acc_lang_cc_Node_Expr_Ellipsis(SerBuf& buf) const;
        virtual void hash_ser_acc(SerBuf& buf) const;
    };
}

void pr_debug(ostream& os, FmtFlags flags, lang::cc::Node::Expr::Tilde_T x);

namespace lang::cc::Node::Expr::Tilde {
    lang::cc::Node::Expr::Tilde_T make(Int id, lang_rt::TokenBounds bounds, bool is_top, lang_rt::ParserSymId sym, lang_rt::ParserAttrMask attr, lang_rt::ParserLookahead first_k, lang::cc::Node::Expr_T x);
}

namespace lang::cc::Node::Expr::Tilde {
    lang::cc::Node::Expr::Tilde_T make_ext(ArenaPtr arena, Int id, lang_rt::TokenBounds bounds, bool is_top, lang_rt::ParserSymId sym, lang_rt::ParserAttrMask attr, lang_rt::ParserLookahead first_k, lang::cc::Node::Expr_T x);
}

namespace lang::cc::Node::Expr::Tilde {
    struct _T: lang::cc::Node::Expr::_T {
        void write(Ref<ostream> os, FmtFlags flags);
        void write(Ref<lang_rt::PrBufStream_T> pb);
        lang::cc::Node::Expr_T x_;
        _T();
        lang::cc::Node::Expr::Tilde_T with_id(Int id);
        lang::cc::Node::Expr::Tilde_T with_bounds(lang_rt::TokenBounds bounds);
        lang::cc::Node::Expr::Tilde_T with_is_top(bool is_top);
        lang::cc::Node::Expr::Tilde_T with_sym(lang_rt::ParserSymId sym);
        lang::cc::Node::Expr::Tilde_T with_attr(lang_rt::ParserAttrMask attr);
        lang::cc::Node::Expr::Tilde_T with_first_k(lang_rt::ParserLookahead first_k);
        lang::cc::Node::Expr::Tilde_T with_x(lang::cc::Node::Expr_T x);
        void hash_ser_acc_lang_cc_Node_Expr_Tilde(SerBuf& buf) const;
        virtual void hash_ser_acc(SerBuf& buf) const;
    };
}

void pr_debug(ostream& os, FmtFlags flags, lang::cc::Node::Expr::Namespace_T x);

namespace lang::cc::Node::Expr::Namespace {
    lang::cc::Node::Expr::Namespace_T make(Int id, lang_rt::TokenBounds bounds, bool is_top, lang_rt::ParserSymId sym, lang_rt::ParserAttrMask attr, lang_rt::ParserLookahead first_k, lang::cc::Node::Expr_T x, bool tilde, lang::cc::Node::Expr_T name);
}

namespace lang::cc::Node::Expr::Namespace {
    lang::cc::Node::Expr::Namespace_T make_ext(ArenaPtr arena, Int id, lang_rt::TokenBounds bounds, bool is_top, lang_rt::ParserSymId sym, lang_rt::ParserAttrMask attr, lang_rt::ParserLookahead first_k, lang::cc::Node::Expr_T x, bool tilde, lang::cc::Node::Expr_T name);
}

namespace lang::cc::Node::Expr::Namespace {
    struct _T: lang::cc::Node::Expr::_T {
        void write(Ref<ostream> os, FmtFlags flags);
        void write(Ref<lang_rt::PrBufStream_T> pb);
        lang::cc::Node::Expr_T x_;
        bool tilde_;
        lang::cc::Node::Expr_T name_;
        _T();
        lang::cc::Node::Expr::Namespace_T with_id(Int id);
        lang::cc::Node::Expr::Namespace_T with_bounds(lang_rt::TokenBounds bounds);
        lang::cc::Node::Expr::Namespace_T with_is_top(bool is_top);
        lang::cc::Node::Expr::Namespace_T with_sym(lang_rt::ParserSymId sym);
        lang::cc::Node::Expr::Namespace_T with_attr(lang_rt::ParserAttrMask attr);
        lang::cc::Node::Expr::Namespace_T with_first_k(lang_rt::ParserLookahead first_k);
        lang::cc::Node::Expr::Namespace_T with_x(lang::cc::Node::Expr_T x);
        lang::cc::Node::Expr::Namespace_T with_tilde(bool tilde);
        lang::cc::Node::Expr::Namespace_T with_name(lang::cc::Node::Expr_T name);
        void hash_ser_acc_lang_cc_Node_Expr_Namespace(SerBuf& buf) const;
        virtual void hash_ser_acc(SerBuf& buf) const;
    };
}

void pr_debug(ostream& os, FmtFlags flags, lang::cc::Node::Expr::Id_T x);

namespace lang::cc::Node::Expr::Id {
    lang::cc::Node::Expr::Id_T make(Int id, lang_rt::TokenBounds bounds, bool is_top, lang_rt::ParserSymId sym, lang_rt::ParserAttrMask attr, lang_rt::ParserLookahead first_k, StrSlice name);
}

namespace lang::cc::Node::Expr::Id {
    lang::cc::Node::Expr::Id_T make_ext(ArenaPtr arena, Int id, lang_rt::TokenBounds bounds, bool is_top, lang_rt::ParserSymId sym, lang_rt::ParserAttrMask attr, lang_rt::ParserLookahead first_k, StrSlice name);
}

namespace lang::cc::Node::Expr::Id {
    struct _T: lang::cc::Node::Expr::_T {
        void write(Ref<ostream> os, FmtFlags flags);
        void write(Ref<lang_rt::PrBufStream_T> pb);
        StrSlice name_;
        _T();
        lang::cc::Node::Expr::Id_T with_id(Int id);
        lang::cc::Node::Expr::Id_T with_bounds(lang_rt::TokenBounds bounds);
        lang::cc::Node::Expr::Id_T with_is_top(bool is_top);
        lang::cc::Node::Expr::Id_T with_sym(lang_rt::ParserSymId sym);
        lang::cc::Node::Expr::Id_T with_attr(lang_rt::ParserAttrMask attr);
        lang::cc::Node::Expr::Id_T with_first_k(lang_rt::ParserLookahead first_k);
        lang::cc::Node::Expr::Id_T with_name(StrSlice name);
        void hash_ser_acc_lang_cc_Node_Expr_Id(SerBuf& buf) const;
        virtual void hash_ser_acc(SerBuf& buf) const;
    };
}

void pr_debug(ostream& os, FmtFlags flags, lang::cc::Node::Expr::Lit_T x);

namespace lang::cc::Node::Expr::Lit {
    enum struct _W {
        Integer,
        Str_,
        Array,
    };
}

namespace lang::cc::Node::Expr::Lit {
    struct _T: lang::cc::Node::Expr::_T {
        void write(Ref<ostream> os, FmtFlags flags);
        void write(Ref<lang_rt::PrBufStream_T> pb);
        lang::cc::Node::Expr::Lit::_W w_;
        virtual ~_T();
        _T(lang::cc::Node::Expr::Lit::_W w);
        bool is_Integer();
        bool is_Str_();
        bool is_Array();
        lang::cc::Node::Expr::Lit::Integer_T as_Integer();
        lang::cc::Node::Expr::Lit::Str__T as_Str_();
        lang::cc::Node::Expr::Lit::Array_T as_Array();
        void match(function<void(lang::cc::Node::Expr::Lit::Integer_T)> f_Integer, function<void(lang::cc::Node::Expr::Lit::Str__T)> f_Str_, function<void(lang::cc::Node::Expr::Lit::Array_T)> f_Array);
        template<typename RetT> RetT match_expr(function<RetT(lang::cc::Node::Expr::Lit::Integer_T)> f_Integer, function<RetT(lang::cc::Node::Expr::Lit::Str__T)> f_Str_, function<RetT(lang::cc::Node::Expr::Lit::Array_T)> f_Array);
        void hash_ser_acc_lang_cc_Node_Expr_Lit(SerBuf& buf) const;
        virtual void hash_ser_acc(SerBuf& buf) const = 0;
    };
}

template<typename RetT> RetT lang::cc::Node::Expr::Lit::_T::match_expr(function<RetT(lang::cc::Node::Expr::Lit::Integer_T)> f_Integer, function<RetT(lang::cc::Node::Expr::Lit::Str__T)> f_Str_, function<RetT(lang::cc::Node::Expr::Lit::Array_T)> f_Array) {
    switch (this->w_) {
        case lang::cc::Node::Expr::Lit::_W::Integer: {
            return f_Integer(this->as_Integer());
            break;
        }
        case lang::cc::Node::Expr::Lit::_W::Str_: {
            return f_Str_(this->as_Str_());
            break;
        }
        case lang::cc::Node::Expr::Lit::_W::Array: {
            return f_Array(this->as_Array());
            break;
        }
        default: {
            AX();
        }
    }
}

void pr_debug(ostream& os, FmtFlags flags, lang::cc::Node::Decl::Struct::tmpl_T x);

namespace lang::cc::Node::Decl::Struct::tmpl {
    lang::cc::Node::Decl::Struct::tmpl_T make(Int id, lang_rt::TokenBounds bounds, bool is_top, lang_rt::ParserSymId sym, lang_rt::ParserAttrMask attr, lang_rt::ParserLookahead first_k, Vec_T<lang::cc::Node::Decl::Struct::tmpl::args::item_T> args);
}

namespace lang::cc::Node::Decl::Struct::tmpl {
    lang::cc::Node::Decl::Struct::tmpl_T make_ext(ArenaPtr arena, Int id, lang_rt::TokenBounds bounds, bool is_top, lang_rt::ParserSymId sym, lang_rt::ParserAttrMask attr, lang_rt::ParserLookahead first_k, Vec_T<lang::cc::Node::Decl::Struct::tmpl::args::item_T> args);
}

namespace lang::cc::Node::Decl::Struct::tmpl {
    struct _T: lang::cc::Node::_T {
        void write(Ref<ostream> os, FmtFlags flags);
        void write(Ref<lang_rt::PrBufStream_T> pb);
        Vec_T<lang::cc::Node::Decl::Struct::tmpl::args::item_T> args_;
        _T();
        lang::cc::Node::Decl::Struct::tmpl_T with_id(Int id);
        lang::cc::Node::Decl::Struct::tmpl_T with_bounds(lang_rt::TokenBounds bounds);
        lang::cc::Node::Decl::Struct::tmpl_T with_is_top(bool is_top);
        lang::cc::Node::Decl::Struct::tmpl_T with_sym(lang_rt::ParserSymId sym);
        lang::cc::Node::Decl::Struct::tmpl_T with_attr(lang_rt::ParserAttrMask attr);
        lang::cc::Node::Decl::Struct::tmpl_T with_first_k(lang_rt::ParserLookahead first_k);
        lang::cc::Node::Decl::Struct::tmpl_T with_args(Vec_T<lang::cc::Node::Decl::Struct::tmpl::args::item_T> args);
        void hash_ser_acc_lang_cc_Node_Decl_Struct_tmpl(SerBuf& buf) const;
        virtual void hash_ser_acc(SerBuf& buf) const;
    };
}

void pr_debug(ostream& os, FmtFlags flags, lang::cc::Node::Entry::Fun::tmpl_T x);

namespace lang::cc::Node::Entry::Fun::tmpl {
    lang::cc::Node::Entry::Fun::tmpl_T make(Int id, lang_rt::TokenBounds bounds, bool is_top, lang_rt::ParserSymId sym, lang_rt::ParserAttrMask attr, lang_rt::ParserLookahead first_k, Vec_T<lang::cc::Node::Entry::Fun::tmpl::args::item_T> args);
}

namespace lang::cc::Node::Entry::Fun::tmpl {
    lang::cc::Node::Entry::Fun::tmpl_T make_ext(ArenaPtr arena, Int id, lang_rt::TokenBounds bounds, bool is_top, lang_rt::ParserSymId sym, lang_rt::ParserAttrMask attr, lang_rt::ParserLookahead first_k, Vec_T<lang::cc::Node::Entry::Fun::tmpl::args::item_T> args);
}

namespace lang::cc::Node::Entry::Fun::tmpl {
    struct _T: lang::cc::Node::_T {
        void write(Ref<ostream> os, FmtFlags flags);
        void write(Ref<lang_rt::PrBufStream_T> pb);
        Vec_T<lang::cc::Node::Entry::Fun::tmpl::args::item_T> args_;
        _T();
        lang::cc::Node::Entry::Fun::tmpl_T with_id(Int id);
        lang::cc::Node::Entry::Fun::tmpl_T with_bounds(lang_rt::TokenBounds bounds);
        lang::cc::Node::Entry::Fun::tmpl_T with_is_top(bool is_top);
        lang::cc::Node::Entry::Fun::tmpl_T with_sym(lang_rt::ParserSymId sym);
        lang::cc::Node::Entry::Fun::tmpl_T with_attr(lang_rt::ParserAttrMask attr);
        lang::cc::Node::Entry::Fun::tmpl_T with_first_k(lang_rt::ParserLookahead first_k);
        lang::cc::Node::Entry::Fun::tmpl_T with_args(Vec_T<lang::cc::Node::Entry::Fun::tmpl::args::item_T> args);
        void hash_ser_acc_lang_cc_Node_Entry_Fun_tmpl(SerBuf& buf) const;
        virtual void hash_ser_acc(SerBuf& buf) const;
    };
}

void pr_debug(ostream& os, FmtFlags flags, lang::cc::Node::Decl::Fun::tmpl_T x);

namespace lang::cc::Node::Decl::Fun::tmpl {
    lang::cc::Node::Decl::Fun::tmpl_T make(Int id, lang_rt::TokenBounds bounds, bool is_top, lang_rt::ParserSymId sym, lang_rt::ParserAttrMask attr, lang_rt::ParserLookahead first_k, Vec_T<lang::cc::Node::Decl::Fun::tmpl::args::item_T> args);
}

namespace lang::cc::Node::Decl::Fun::tmpl {
    lang::cc::Node::Decl::Fun::tmpl_T make_ext(ArenaPtr arena, Int id, lang_rt::TokenBounds bounds, bool is_top, lang_rt::ParserSymId sym, lang_rt::ParserAttrMask attr, lang_rt::ParserLookahead first_k, Vec_T<lang::cc::Node::Decl::Fun::tmpl::args::item_T> args);
}

namespace lang::cc::Node::Decl::Fun::tmpl {
    struct _T: lang::cc::Node::_T {
        void write(Ref<ostream> os, FmtFlags flags);
        void write(Ref<lang_rt::PrBufStream_T> pb);
        Vec_T<lang::cc::Node::Decl::Fun::tmpl::args::item_T> args_;
        _T();
        lang::cc::Node::Decl::Fun::tmpl_T with_id(Int id);
        lang::cc::Node::Decl::Fun::tmpl_T with_bounds(lang_rt::TokenBounds bounds);
        lang::cc::Node::Decl::Fun::tmpl_T with_is_top(bool is_top);
        lang::cc::Node::Decl::Fun::tmpl_T with_sym(lang_rt::ParserSymId sym);
        lang::cc::Node::Decl::Fun::tmpl_T with_attr(lang_rt::ParserAttrMask attr);
        lang::cc::Node::Decl::Fun::tmpl_T with_first_k(lang_rt::ParserLookahead first_k);
        lang::cc::Node::Decl::Fun::tmpl_T with_args(Vec_T<lang::cc::Node::Decl::Fun::tmpl::args::item_T> args);
        void hash_ser_acc_lang_cc_Node_Decl_Fun_tmpl(SerBuf& buf) const;
        virtual void hash_ser_acc(SerBuf& buf) const;
    };
}

void pr_debug(ostream& os, FmtFlags flags, lang::cc::Node::Decl::UsingAlias::tmpl_T x);

namespace lang::cc::Node::Decl::UsingAlias::tmpl {
    lang::cc::Node::Decl::UsingAlias::tmpl_T make(Int id, lang_rt::TokenBounds bounds, bool is_top, lang_rt::ParserSymId sym, lang_rt::ParserAttrMask attr, lang_rt::ParserLookahead first_k, Vec_T<lang::cc::Node::Decl::UsingAlias::tmpl::args::item_T> args);
}

namespace lang::cc::Node::Decl::UsingAlias::tmpl {
    lang::cc::Node::Decl::UsingAlias::tmpl_T make_ext(ArenaPtr arena, Int id, lang_rt::TokenBounds bounds, bool is_top, lang_rt::ParserSymId sym, lang_rt::ParserAttrMask attr, lang_rt::ParserLookahead first_k, Vec_T<lang::cc::Node::Decl::UsingAlias::tmpl::args::item_T> args);
}

namespace lang::cc::Node::Decl::UsingAlias::tmpl {
    struct _T: lang::cc::Node::_T {
        void write(Ref<ostream> os, FmtFlags flags);
        void write(Ref<lang_rt::PrBufStream_T> pb);
        Vec_T<lang::cc::Node::Decl::UsingAlias::tmpl::args::item_T> args_;
        _T();
        lang::cc::Node::Decl::UsingAlias::tmpl_T with_id(Int id);
        lang::cc::Node::Decl::UsingAlias::tmpl_T with_bounds(lang_rt::TokenBounds bounds);
        lang::cc::Node::Decl::UsingAlias::tmpl_T with_is_top(bool is_top);
        lang::cc::Node::Decl::UsingAlias::tmpl_T with_sym(lang_rt::ParserSymId sym);
        lang::cc::Node::Decl::UsingAlias::tmpl_T with_attr(lang_rt::ParserAttrMask attr);
        lang::cc::Node::Decl::UsingAlias::tmpl_T with_first_k(lang_rt::ParserLookahead first_k);
        lang::cc::Node::Decl::UsingAlias::tmpl_T with_args(Vec_T<lang::cc::Node::Decl::UsingAlias::tmpl::args::item_T> args);
        void hash_ser_acc_lang_cc_Node_Decl_UsingAlias_tmpl(SerBuf& buf) const;
        virtual void hash_ser_acc(SerBuf& buf) const;
    };
}

void pr_debug(ostream& os, FmtFlags flags, lang::cc::Node::TypedDecl::vars::item_T x);

namespace lang::cc::Node::TypedDecl::vars::item {
    lang::cc::Node::TypedDecl::vars::item_T make(Int id, lang_rt::TokenBounds bounds, bool is_top, lang_rt::ParserSymId sym, lang_rt::ParserAttrMask attr, lang_rt::ParserLookahead first_k, lang::cc::Node::Expr_T name, Option_T<lang::cc::Node::TypedDecl::vars::item::val_T> val);
}

namespace lang::cc::Node::TypedDecl::vars::item {
    lang::cc::Node::TypedDecl::vars::item_T make_ext(ArenaPtr arena, Int id, lang_rt::TokenBounds bounds, bool is_top, lang_rt::ParserSymId sym, lang_rt::ParserAttrMask attr, lang_rt::ParserLookahead first_k, lang::cc::Node::Expr_T name, Option_T<lang::cc::Node::TypedDecl::vars::item::val_T> val);
}

namespace lang::cc::Node::TypedDecl::vars::item {
    struct _T: lang::cc::Node::_T {
        void write(Ref<ostream> os, FmtFlags flags);
        void write(Ref<lang_rt::PrBufStream_T> pb);
        lang::cc::Node::Expr_T name_;
        Option_T<lang::cc::Node::TypedDecl::vars::item::val_T> val_;
        _T();
        lang::cc::Node::TypedDecl::vars::item_T with_id(Int id);
        lang::cc::Node::TypedDecl::vars::item_T with_bounds(lang_rt::TokenBounds bounds);
        lang::cc::Node::TypedDecl::vars::item_T with_is_top(bool is_top);
        lang::cc::Node::TypedDecl::vars::item_T with_sym(lang_rt::ParserSymId sym);
        lang::cc::Node::TypedDecl::vars::item_T with_attr(lang_rt::ParserAttrMask attr);
        lang::cc::Node::TypedDecl::vars::item_T with_first_k(lang_rt::ParserLookahead first_k);
        lang::cc::Node::TypedDecl::vars::item_T with_name(lang::cc::Node::Expr_T name);
        lang::cc::Node::TypedDecl::vars::item_T with_val(Option_T<lang::cc::Node::TypedDecl::vars::item::val_T> val);
        void hash_ser_acc_lang_cc_Node_TypedDecl_vars_item(SerBuf& buf) const;
        virtual void hash_ser_acc(SerBuf& buf) const;
    };
}

void pr_debug(ostream& os, FmtFlags flags, lang::cc::Node::Expr::UnaryPre::op_T x);

namespace lang::cc::Node::Expr::UnaryPre::op {
    enum struct _W {
        NOT,
        NEG,
    };
}

namespace lang::cc::Node::Expr::UnaryPre::op {
    struct _T: lang::cc::Node::_T {
        void write(Ref<ostream> os, FmtFlags flags);
        void write(Ref<lang_rt::PrBufStream_T> pb);
        lang::cc::Node::Expr::UnaryPre::op::_W w_;
        virtual ~_T();
        _T(lang::cc::Node::Expr::UnaryPre::op::_W w);
        bool is_NOT();
        bool is_NEG();
        lang::cc::Node::Expr::UnaryPre::op::NOT_T as_NOT();
        lang::cc::Node::Expr::UnaryPre::op::NEG_T as_NEG();
        void match(function<void(lang::cc::Node::Expr::UnaryPre::op::NOT_T)> f_NOT, function<void(lang::cc::Node::Expr::UnaryPre::op::NEG_T)> f_NEG);
        template<typename RetT> RetT match_expr(function<RetT(lang::cc::Node::Expr::UnaryPre::op::NOT_T)> f_NOT, function<RetT(lang::cc::Node::Expr::UnaryPre::op::NEG_T)> f_NEG);
        void hash_ser_acc_lang_cc_Node_Expr_UnaryPre_op(SerBuf& buf) const;
        virtual void hash_ser_acc(SerBuf& buf) const = 0;
    };
}

template<typename RetT> RetT lang::cc::Node::Expr::UnaryPre::op::_T::match_expr(function<RetT(lang::cc::Node::Expr::UnaryPre::op::NOT_T)> f_NOT, function<RetT(lang::cc::Node::Expr::UnaryPre::op::NEG_T)> f_NEG) {
    switch (this->w_) {
        case lang::cc::Node::Expr::UnaryPre::op::_W::NOT: {
            return f_NOT(this->as_NOT());
            break;
        }
        case lang::cc::Node::Expr::UnaryPre::op::_W::NEG: {
            return f_NEG(this->as_NEG());
            break;
        }
        default: {
            AX();
        }
    }
}

void pr_debug(ostream& os, FmtFlags flags, lang::cc::Node::Expr::IncDecPre::op_T x);

namespace lang::cc::Node::Expr::IncDecPre::op {
    enum struct _W {
        INC,
        DEC,
    };
}

namespace lang::cc::Node::Expr::IncDecPre::op {
    struct _T: lang::cc::Node::_T {
        void write(Ref<ostream> os, FmtFlags flags);
        void write(Ref<lang_rt::PrBufStream_T> pb);
        lang::cc::Node::Expr::IncDecPre::op::_W w_;
        virtual ~_T();
        _T(lang::cc::Node::Expr::IncDecPre::op::_W w);
        bool is_INC();
        bool is_DEC();
        lang::cc::Node::Expr::IncDecPre::op::INC_T as_INC();
        lang::cc::Node::Expr::IncDecPre::op::DEC_T as_DEC();
        void match(function<void(lang::cc::Node::Expr::IncDecPre::op::INC_T)> f_INC, function<void(lang::cc::Node::Expr::IncDecPre::op::DEC_T)> f_DEC);
        template<typename RetT> RetT match_expr(function<RetT(lang::cc::Node::Expr::IncDecPre::op::INC_T)> f_INC, function<RetT(lang::cc::Node::Expr::IncDecPre::op::DEC_T)> f_DEC);
        void hash_ser_acc_lang_cc_Node_Expr_IncDecPre_op(SerBuf& buf) const;
        virtual void hash_ser_acc(SerBuf& buf) const = 0;
    };
}

template<typename RetT> RetT lang::cc::Node::Expr::IncDecPre::op::_T::match_expr(function<RetT(lang::cc::Node::Expr::IncDecPre::op::INC_T)> f_INC, function<RetT(lang::cc::Node::Expr::IncDecPre::op::DEC_T)> f_DEC) {
    switch (this->w_) {
        case lang::cc::Node::Expr::IncDecPre::op::_W::INC: {
            return f_INC(this->as_INC());
            break;
        }
        case lang::cc::Node::Expr::IncDecPre::op::_W::DEC: {
            return f_DEC(this->as_DEC());
            break;
        }
        default: {
            AX();
        }
    }
}

void pr_debug(ostream& os, FmtFlags flags, lang::cc::Node::Expr::IncDecPost::op_T x);

namespace lang::cc::Node::Expr::IncDecPost::op {
    enum struct _W {
        INC,
        DEC,
    };
}

namespace lang::cc::Node::Expr::IncDecPost::op {
    struct _T: lang::cc::Node::_T {
        void write(Ref<ostream> os, FmtFlags flags);
        void write(Ref<lang_rt::PrBufStream_T> pb);
        lang::cc::Node::Expr::IncDecPost::op::_W w_;
        virtual ~_T();
        _T(lang::cc::Node::Expr::IncDecPost::op::_W w);
        bool is_INC();
        bool is_DEC();
        lang::cc::Node::Expr::IncDecPost::op::INC_T as_INC();
        lang::cc::Node::Expr::IncDecPost::op::DEC_T as_DEC();
        void match(function<void(lang::cc::Node::Expr::IncDecPost::op::INC_T)> f_INC, function<void(lang::cc::Node::Expr::IncDecPost::op::DEC_T)> f_DEC);
        template<typename RetT> RetT match_expr(function<RetT(lang::cc::Node::Expr::IncDecPost::op::INC_T)> f_INC, function<RetT(lang::cc::Node::Expr::IncDecPost::op::DEC_T)> f_DEC);
        void hash_ser_acc_lang_cc_Node_Expr_IncDecPost_op(SerBuf& buf) const;
        virtual void hash_ser_acc(SerBuf& buf) const = 0;
    };
}

template<typename RetT> RetT lang::cc::Node::Expr::IncDecPost::op::_T::match_expr(function<RetT(lang::cc::Node::Expr::IncDecPost::op::INC_T)> f_INC, function<RetT(lang::cc::Node::Expr::IncDecPost::op::DEC_T)> f_DEC) {
    switch (this->w_) {
        case lang::cc::Node::Expr::IncDecPost::op::_W::INC: {
            return f_INC(this->as_INC());
            break;
        }
        case lang::cc::Node::Expr::IncDecPost::op::_W::DEC: {
            return f_DEC(this->as_DEC());
            break;
        }
        default: {
            AX();
        }
    }
}

void pr_debug(ostream& os, FmtFlags flags, lang::cc::Node::Expr::Bin1::op_T x);

namespace lang::cc::Node::Expr::Bin1::op {
    enum struct _W {
        LOR,
    };
}

namespace lang::cc::Node::Expr::Bin1::op {
    struct _T: lang::cc::Node::_T {
        void write(Ref<ostream> os, FmtFlags flags);
        void write(Ref<lang_rt::PrBufStream_T> pb);
        lang::cc::Node::Expr::Bin1::op::_W w_;
        virtual ~_T();
        _T(lang::cc::Node::Expr::Bin1::op::_W w);
        bool is_LOR();
        lang::cc::Node::Expr::Bin1::op::LOR_T as_LOR();
        void match(function<void(lang::cc::Node::Expr::Bin1::op::LOR_T)> f_LOR);
        template<typename RetT> RetT match_expr(function<RetT(lang::cc::Node::Expr::Bin1::op::LOR_T)> f_LOR);
        void hash_ser_acc_lang_cc_Node_Expr_Bin1_op(SerBuf& buf) const;
        virtual void hash_ser_acc(SerBuf& buf) const = 0;
    };
}

template<typename RetT> RetT lang::cc::Node::Expr::Bin1::op::_T::match_expr(function<RetT(lang::cc::Node::Expr::Bin1::op::LOR_T)> f_LOR) {
    switch (this->w_) {
        case lang::cc::Node::Expr::Bin1::op::_W::LOR: {
            return f_LOR(this->as_LOR());
            break;
        }
        default: {
            AX();
        }
    }
}

void pr_debug(ostream& os, FmtFlags flags, lang::cc::Node::Expr::Bin2::op_T x);

namespace lang::cc::Node::Expr::Bin2::op {
    enum struct _W {
        LAND,
    };
}

namespace lang::cc::Node::Expr::Bin2::op {
    struct _T: lang::cc::Node::_T {
        void write(Ref<ostream> os, FmtFlags flags);
        void write(Ref<lang_rt::PrBufStream_T> pb);
        lang::cc::Node::Expr::Bin2::op::_W w_;
        virtual ~_T();
        _T(lang::cc::Node::Expr::Bin2::op::_W w);
        bool is_LAND();
        lang::cc::Node::Expr::Bin2::op::LAND_T as_LAND();
        void match(function<void(lang::cc::Node::Expr::Bin2::op::LAND_T)> f_LAND);
        template<typename RetT> RetT match_expr(function<RetT(lang::cc::Node::Expr::Bin2::op::LAND_T)> f_LAND);
        void hash_ser_acc_lang_cc_Node_Expr_Bin2_op(SerBuf& buf) const;
        virtual void hash_ser_acc(SerBuf& buf) const = 0;
    };
}

template<typename RetT> RetT lang::cc::Node::Expr::Bin2::op::_T::match_expr(function<RetT(lang::cc::Node::Expr::Bin2::op::LAND_T)> f_LAND) {
    switch (this->w_) {
        case lang::cc::Node::Expr::Bin2::op::_W::LAND: {
            return f_LAND(this->as_LAND());
            break;
        }
        default: {
            AX();
        }
    }
}

void pr_debug(ostream& os, FmtFlags flags, lang::cc::Node::Expr::Bin3::op_T x);

namespace lang::cc::Node::Expr::Bin3::op {
    enum struct _W {
        EQ,
        NE,
        LE,
        GE,
        LT,
        GT,
    };
}

namespace lang::cc::Node::Expr::Bin3::op {
    struct _T: lang::cc::Node::_T {
        void write(Ref<ostream> os, FmtFlags flags);
        void write(Ref<lang_rt::PrBufStream_T> pb);
        lang::cc::Node::Expr::Bin3::op::_W w_;
        virtual ~_T();
        _T(lang::cc::Node::Expr::Bin3::op::_W w);
        bool is_EQ();
        bool is_NE();
        bool is_LE();
        bool is_GE();
        bool is_LT();
        bool is_GT();
        lang::cc::Node::Expr::Bin3::op::EQ_T as_EQ();
        lang::cc::Node::Expr::Bin3::op::NE_T as_NE();
        lang::cc::Node::Expr::Bin3::op::LE_T as_LE();
        lang::cc::Node::Expr::Bin3::op::GE_T as_GE();
        lang::cc::Node::Expr::Bin3::op::LT_T as_LT();
        lang::cc::Node::Expr::Bin3::op::GT_T as_GT();
        void match(function<void(lang::cc::Node::Expr::Bin3::op::EQ_T)> f_EQ, function<void(lang::cc::Node::Expr::Bin3::op::NE_T)> f_NE, function<void(lang::cc::Node::Expr::Bin3::op::LE_T)> f_LE, function<void(lang::cc::Node::Expr::Bin3::op::GE_T)> f_GE, function<void(lang::cc::Node::Expr::Bin3::op::LT_T)> f_LT, function<void(lang::cc::Node::Expr::Bin3::op::GT_T)> f_GT);
        template<typename RetT> RetT match_expr(function<RetT(lang::cc::Node::Expr::Bin3::op::EQ_T)> f_EQ, function<RetT(lang::cc::Node::Expr::Bin3::op::NE_T)> f_NE, function<RetT(lang::cc::Node::Expr::Bin3::op::LE_T)> f_LE, function<RetT(lang::cc::Node::Expr::Bin3::op::GE_T)> f_GE, function<RetT(lang::cc::Node::Expr::Bin3::op::LT_T)> f_LT, function<RetT(lang::cc::Node::Expr::Bin3::op::GT_T)> f_GT);
        void hash_ser_acc_lang_cc_Node_Expr_Bin3_op(SerBuf& buf) const;
        virtual void hash_ser_acc(SerBuf& buf) const = 0;
    };
}

template<typename RetT> RetT lang::cc::Node::Expr::Bin3::op::_T::match_expr(function<RetT(lang::cc::Node::Expr::Bin3::op::EQ_T)> f_EQ, function<RetT(lang::cc::Node::Expr::Bin3::op::NE_T)> f_NE, function<RetT(lang::cc::Node::Expr::Bin3::op::LE_T)> f_LE, function<RetT(lang::cc::Node::Expr::Bin3::op::GE_T)> f_GE, function<RetT(lang::cc::Node::Expr::Bin3::op::LT_T)> f_LT, function<RetT(lang::cc::Node::Expr::Bin3::op::GT_T)> f_GT) {
    switch (this->w_) {
        case lang::cc::Node::Expr::Bin3::op::_W::EQ: {
            return f_EQ(this->as_EQ());
            break;
        }
        case lang::cc::Node::Expr::Bin3::op::_W::NE: {
            return f_NE(this->as_NE());
            break;
        }
        case lang::cc::Node::Expr::Bin3::op::_W::LE: {
            return f_LE(this->as_LE());
            break;
        }
        case lang::cc::Node::Expr::Bin3::op::_W::GE: {
            return f_GE(this->as_GE());
            break;
        }
        case lang::cc::Node::Expr::Bin3::op::_W::LT: {
            return f_LT(this->as_LT());
            break;
        }
        case lang::cc::Node::Expr::Bin3::op::_W::GT: {
            return f_GT(this->as_GT());
            break;
        }
        default: {
            AX();
        }
    }
}

void pr_debug(ostream& os, FmtFlags flags, lang::cc::Node::Expr::Bin4::op_T x);

namespace lang::cc::Node::Expr::Bin4::op {
    enum struct _W {
        SHL,
    };
}

namespace lang::cc::Node::Expr::Bin4::op {
    struct _T: lang::cc::Node::_T {
        void write(Ref<ostream> os, FmtFlags flags);
        void write(Ref<lang_rt::PrBufStream_T> pb);
        lang::cc::Node::Expr::Bin4::op::_W w_;
        virtual ~_T();
        _T(lang::cc::Node::Expr::Bin4::op::_W w);
        bool is_SHL();
        lang::cc::Node::Expr::Bin4::op::SHL_T as_SHL();
        void match(function<void(lang::cc::Node::Expr::Bin4::op::SHL_T)> f_SHL);
        template<typename RetT> RetT match_expr(function<RetT(lang::cc::Node::Expr::Bin4::op::SHL_T)> f_SHL);
        void hash_ser_acc_lang_cc_Node_Expr_Bin4_op(SerBuf& buf) const;
        virtual void hash_ser_acc(SerBuf& buf) const = 0;
    };
}

template<typename RetT> RetT lang::cc::Node::Expr::Bin4::op::_T::match_expr(function<RetT(lang::cc::Node::Expr::Bin4::op::SHL_T)> f_SHL) {
    switch (this->w_) {
        case lang::cc::Node::Expr::Bin4::op::_W::SHL: {
            return f_SHL(this->as_SHL());
            break;
        }
        default: {
            AX();
        }
    }
}

void pr_debug(ostream& os, FmtFlags flags, lang::cc::Node::Expr::Bin5::op_T x);

namespace lang::cc::Node::Expr::Bin5::op {
    enum struct _W {
        PLUS,
        MINUS,
    };
}

namespace lang::cc::Node::Expr::Bin5::op {
    struct _T: lang::cc::Node::_T {
        void write(Ref<ostream> os, FmtFlags flags);
        void write(Ref<lang_rt::PrBufStream_T> pb);
        lang::cc::Node::Expr::Bin5::op::_W w_;
        virtual ~_T();
        _T(lang::cc::Node::Expr::Bin5::op::_W w);
        bool is_PLUS();
        bool is_MINUS();
        lang::cc::Node::Expr::Bin5::op::PLUS_T as_PLUS();
        lang::cc::Node::Expr::Bin5::op::MINUS_T as_MINUS();
        void match(function<void(lang::cc::Node::Expr::Bin5::op::PLUS_T)> f_PLUS, function<void(lang::cc::Node::Expr::Bin5::op::MINUS_T)> f_MINUS);
        template<typename RetT> RetT match_expr(function<RetT(lang::cc::Node::Expr::Bin5::op::PLUS_T)> f_PLUS, function<RetT(lang::cc::Node::Expr::Bin5::op::MINUS_T)> f_MINUS);
        void hash_ser_acc_lang_cc_Node_Expr_Bin5_op(SerBuf& buf) const;
        virtual void hash_ser_acc(SerBuf& buf) const = 0;
    };
}

template<typename RetT> RetT lang::cc::Node::Expr::Bin5::op::_T::match_expr(function<RetT(lang::cc::Node::Expr::Bin5::op::PLUS_T)> f_PLUS, function<RetT(lang::cc::Node::Expr::Bin5::op::MINUS_T)> f_MINUS) {
    switch (this->w_) {
        case lang::cc::Node::Expr::Bin5::op::_W::PLUS: {
            return f_PLUS(this->as_PLUS());
            break;
        }
        case lang::cc::Node::Expr::Bin5::op::_W::MINUS: {
            return f_MINUS(this->as_MINUS());
            break;
        }
        default: {
            AX();
        }
    }
}

void pr_debug(ostream& os, FmtFlags flags, lang::cc::Node::Expr::Bin6::op_T x);

namespace lang::cc::Node::Expr::Bin6::op {
    enum struct _W {
        TIMES,
        DIVIDE,
        MODULO,
    };
}

namespace lang::cc::Node::Expr::Bin6::op {
    struct _T: lang::cc::Node::_T {
        void write(Ref<ostream> os, FmtFlags flags);
        void write(Ref<lang_rt::PrBufStream_T> pb);
        lang::cc::Node::Expr::Bin6::op::_W w_;
        virtual ~_T();
        _T(lang::cc::Node::Expr::Bin6::op::_W w);
        bool is_TIMES();
        bool is_DIVIDE();
        bool is_MODULO();
        lang::cc::Node::Expr::Bin6::op::TIMES_T as_TIMES();
        lang::cc::Node::Expr::Bin6::op::DIVIDE_T as_DIVIDE();
        lang::cc::Node::Expr::Bin6::op::MODULO_T as_MODULO();
        void match(function<void(lang::cc::Node::Expr::Bin6::op::TIMES_T)> f_TIMES, function<void(lang::cc::Node::Expr::Bin6::op::DIVIDE_T)> f_DIVIDE, function<void(lang::cc::Node::Expr::Bin6::op::MODULO_T)> f_MODULO);
        template<typename RetT> RetT match_expr(function<RetT(lang::cc::Node::Expr::Bin6::op::TIMES_T)> f_TIMES, function<RetT(lang::cc::Node::Expr::Bin6::op::DIVIDE_T)> f_DIVIDE, function<RetT(lang::cc::Node::Expr::Bin6::op::MODULO_T)> f_MODULO);
        void hash_ser_acc_lang_cc_Node_Expr_Bin6_op(SerBuf& buf) const;
        virtual void hash_ser_acc(SerBuf& buf) const = 0;
    };
}

template<typename RetT> RetT lang::cc::Node::Expr::Bin6::op::_T::match_expr(function<RetT(lang::cc::Node::Expr::Bin6::op::TIMES_T)> f_TIMES, function<RetT(lang::cc::Node::Expr::Bin6::op::DIVIDE_T)> f_DIVIDE, function<RetT(lang::cc::Node::Expr::Bin6::op::MODULO_T)> f_MODULO) {
    switch (this->w_) {
        case lang::cc::Node::Expr::Bin6::op::_W::TIMES: {
            return f_TIMES(this->as_TIMES());
            break;
        }
        case lang::cc::Node::Expr::Bin6::op::_W::DIVIDE: {
            return f_DIVIDE(this->as_DIVIDE());
            break;
        }
        case lang::cc::Node::Expr::Bin6::op::_W::MODULO: {
            return f_MODULO(this->as_MODULO());
            break;
        }
        default: {
            AX();
        }
    }
}

void pr_debug(ostream& os, FmtFlags flags, lang::cc::Node::Expr::Lit::Integer_T x);

namespace lang::cc::Node::Expr::Lit::Integer {
    lang::cc::Node::Expr::Lit::Integer_T make(Int id, lang_rt::TokenBounds bounds, bool is_top, lang_rt::ParserSymId sym, lang_rt::ParserAttrMask attr, lang_rt::ParserLookahead first_k, StrSlice val);
}

namespace lang::cc::Node::Expr::Lit::Integer {
    lang::cc::Node::Expr::Lit::Integer_T make_ext(ArenaPtr arena, Int id, lang_rt::TokenBounds bounds, bool is_top, lang_rt::ParserSymId sym, lang_rt::ParserAttrMask attr, lang_rt::ParserLookahead first_k, StrSlice val);
}

namespace lang::cc::Node::Expr::Lit::Integer {
    struct _T: lang::cc::Node::Expr::Lit::_T {
        void write(Ref<ostream> os, FmtFlags flags);
        void write(Ref<lang_rt::PrBufStream_T> pb);
        StrSlice val_;
        _T();
        lang::cc::Node::Expr::Lit::Integer_T with_id(Int id);
        lang::cc::Node::Expr::Lit::Integer_T with_bounds(lang_rt::TokenBounds bounds);
        lang::cc::Node::Expr::Lit::Integer_T with_is_top(bool is_top);
        lang::cc::Node::Expr::Lit::Integer_T with_sym(lang_rt::ParserSymId sym);
        lang::cc::Node::Expr::Lit::Integer_T with_attr(lang_rt::ParserAttrMask attr);
        lang::cc::Node::Expr::Lit::Integer_T with_first_k(lang_rt::ParserLookahead first_k);
        lang::cc::Node::Expr::Lit::Integer_T with_val(StrSlice val);
        void hash_ser_acc_lang_cc_Node_Expr_Lit_Integer(SerBuf& buf) const;
        virtual void hash_ser_acc(SerBuf& buf) const;
    };
}

void pr_debug(ostream& os, FmtFlags flags, lang::cc::Node::Expr::Lit::Str__T x);

namespace lang::cc::Node::Expr::Lit::Str_ {
    lang::cc::Node::Expr::Lit::Str__T make(Int id, lang_rt::TokenBounds bounds, bool is_top, lang_rt::ParserSymId sym, lang_rt::ParserAttrMask attr, lang_rt::ParserLookahead first_k, StrSlice val);
}

namespace lang::cc::Node::Expr::Lit::Str_ {
    lang::cc::Node::Expr::Lit::Str__T make_ext(ArenaPtr arena, Int id, lang_rt::TokenBounds bounds, bool is_top, lang_rt::ParserSymId sym, lang_rt::ParserAttrMask attr, lang_rt::ParserLookahead first_k, StrSlice val);
}

namespace lang::cc::Node::Expr::Lit::Str_ {
    struct _T: lang::cc::Node::Expr::Lit::_T {
        void write(Ref<ostream> os, FmtFlags flags);
        void write(Ref<lang_rt::PrBufStream_T> pb);
        StrSlice val_;
        _T();
        lang::cc::Node::Expr::Lit::Str__T with_id(Int id);
        lang::cc::Node::Expr::Lit::Str__T with_bounds(lang_rt::TokenBounds bounds);
        lang::cc::Node::Expr::Lit::Str__T with_is_top(bool is_top);
        lang::cc::Node::Expr::Lit::Str__T with_sym(lang_rt::ParserSymId sym);
        lang::cc::Node::Expr::Lit::Str__T with_attr(lang_rt::ParserAttrMask attr);
        lang::cc::Node::Expr::Lit::Str__T with_first_k(lang_rt::ParserLookahead first_k);
        lang::cc::Node::Expr::Lit::Str__T with_val(StrSlice val);
        void hash_ser_acc_lang_cc_Node_Expr_Lit_Str_(SerBuf& buf) const;
        virtual void hash_ser_acc(SerBuf& buf) const;
    };
}

void pr_debug(ostream& os, FmtFlags flags, lang::cc::Node::Expr::Lit::Array_T x);

namespace lang::cc::Node::Expr::Lit::Array {
    lang::cc::Node::Expr::Lit::Array_T make(Int id, lang_rt::TokenBounds bounds, bool is_top, lang_rt::ParserSymId sym, lang_rt::ParserAttrMask attr, lang_rt::ParserLookahead first_k, Vec_T<lang::cc::Node::Expr_T> items);
}

namespace lang::cc::Node::Expr::Lit::Array {
    lang::cc::Node::Expr::Lit::Array_T make_ext(ArenaPtr arena, Int id, lang_rt::TokenBounds bounds, bool is_top, lang_rt::ParserSymId sym, lang_rt::ParserAttrMask attr, lang_rt::ParserLookahead first_k, Vec_T<lang::cc::Node::Expr_T> items);
}

namespace lang::cc::Node::Expr::Lit::Array {
    struct _T: lang::cc::Node::Expr::Lit::_T {
        void write(Ref<ostream> os, FmtFlags flags);
        void write(Ref<lang_rt::PrBufStream_T> pb);
        Vec_T<lang::cc::Node::Expr_T> items_;
        _T();
        lang::cc::Node::Expr::Lit::Array_T with_id(Int id);
        lang::cc::Node::Expr::Lit::Array_T with_bounds(lang_rt::TokenBounds bounds);
        lang::cc::Node::Expr::Lit::Array_T with_is_top(bool is_top);
        lang::cc::Node::Expr::Lit::Array_T with_sym(lang_rt::ParserSymId sym);
        lang::cc::Node::Expr::Lit::Array_T with_attr(lang_rt::ParserAttrMask attr);
        lang::cc::Node::Expr::Lit::Array_T with_first_k(lang_rt::ParserLookahead first_k);
        lang::cc::Node::Expr::Lit::Array_T with_items(Vec_T<lang::cc::Node::Expr_T> items);
        void hash_ser_acc_lang_cc_Node_Expr_Lit_Array(SerBuf& buf) const;
        virtual void hash_ser_acc(SerBuf& buf) const;
    };
}

void pr_debug(ostream& os, FmtFlags flags, lang::cc::Node::TypedDecl::vars::item::val_T x);

namespace lang::cc::Node::TypedDecl::vars::item::val {
    lang::cc::Node::TypedDecl::vars::item::val_T make(Int id, lang_rt::TokenBounds bounds, bool is_top, lang_rt::ParserSymId sym, lang_rt::ParserAttrMask attr, lang_rt::ParserLookahead first_k, lang::cc::Node::Expr_T init_val);
}

namespace lang::cc::Node::TypedDecl::vars::item::val {
    lang::cc::Node::TypedDecl::vars::item::val_T make_ext(ArenaPtr arena, Int id, lang_rt::TokenBounds bounds, bool is_top, lang_rt::ParserSymId sym, lang_rt::ParserAttrMask attr, lang_rt::ParserLookahead first_k, lang::cc::Node::Expr_T init_val);
}

namespace lang::cc::Node::TypedDecl::vars::item::val {
    struct _T: lang::cc::Node::_T {
        void write(Ref<ostream> os, FmtFlags flags);
        void write(Ref<lang_rt::PrBufStream_T> pb);
        lang::cc::Node::Expr_T init_val_;
        _T();
        lang::cc::Node::TypedDecl::vars::item::val_T with_id(Int id);
        lang::cc::Node::TypedDecl::vars::item::val_T with_bounds(lang_rt::TokenBounds bounds);
        lang::cc::Node::TypedDecl::vars::item::val_T with_is_top(bool is_top);
        lang::cc::Node::TypedDecl::vars::item::val_T with_sym(lang_rt::ParserSymId sym);
        lang::cc::Node::TypedDecl::vars::item::val_T with_attr(lang_rt::ParserAttrMask attr);
        lang::cc::Node::TypedDecl::vars::item::val_T with_first_k(lang_rt::ParserLookahead first_k);
        lang::cc::Node::TypedDecl::vars::item::val_T with_init_val(lang::cc::Node::Expr_T init_val);
        void hash_ser_acc_lang_cc_Node_TypedDecl_vars_item_val(SerBuf& buf) const;
        virtual void hash_ser_acc(SerBuf& buf) const;
    };
}

void pr_debug(ostream& os, FmtFlags flags, lang::cc::Node::Expr::UnaryPre::op::NOT_T x);

namespace lang::cc::Node::Expr::UnaryPre::op::NOT {
    lang::cc::Node::Expr::UnaryPre::op::NOT_T make(Int id, lang_rt::TokenBounds bounds, bool is_top, lang_rt::ParserSymId sym, lang_rt::ParserAttrMask attr, lang_rt::ParserLookahead first_k);
}

namespace lang::cc::Node::Expr::UnaryPre::op::NOT {
    lang::cc::Node::Expr::UnaryPre::op::NOT_T make_ext(ArenaPtr arena, Int id, lang_rt::TokenBounds bounds, bool is_top, lang_rt::ParserSymId sym, lang_rt::ParserAttrMask attr, lang_rt::ParserLookahead first_k);
}

namespace lang::cc::Node::Expr::UnaryPre::op::NOT {
    struct _T: lang::cc::Node::Expr::UnaryPre::op::_T {
        void write(Ref<ostream> os, FmtFlags flags);
        void write(Ref<lang_rt::PrBufStream_T> pb);
        _T();
        lang::cc::Node::Expr::UnaryPre::op::NOT_T with_id(Int id);
        lang::cc::Node::Expr::UnaryPre::op::NOT_T with_bounds(lang_rt::TokenBounds bounds);
        lang::cc::Node::Expr::UnaryPre::op::NOT_T with_is_top(bool is_top);
        lang::cc::Node::Expr::UnaryPre::op::NOT_T with_sym(lang_rt::ParserSymId sym);
        lang::cc::Node::Expr::UnaryPre::op::NOT_T with_attr(lang_rt::ParserAttrMask attr);
        lang::cc::Node::Expr::UnaryPre::op::NOT_T with_first_k(lang_rt::ParserLookahead first_k);
        void hash_ser_acc_lang_cc_Node_Expr_UnaryPre_op_NOT(SerBuf& buf) const;
        virtual void hash_ser_acc(SerBuf& buf) const;
    };
}

void pr_debug(ostream& os, FmtFlags flags, lang::cc::Node::Expr::UnaryPre::op::NEG_T x);

namespace lang::cc::Node::Expr::UnaryPre::op::NEG {
    lang::cc::Node::Expr::UnaryPre::op::NEG_T make(Int id, lang_rt::TokenBounds bounds, bool is_top, lang_rt::ParserSymId sym, lang_rt::ParserAttrMask attr, lang_rt::ParserLookahead first_k);
}

namespace lang::cc::Node::Expr::UnaryPre::op::NEG {
    lang::cc::Node::Expr::UnaryPre::op::NEG_T make_ext(ArenaPtr arena, Int id, lang_rt::TokenBounds bounds, bool is_top, lang_rt::ParserSymId sym, lang_rt::ParserAttrMask attr, lang_rt::ParserLookahead first_k);
}

namespace lang::cc::Node::Expr::UnaryPre::op::NEG {
    struct _T: lang::cc::Node::Expr::UnaryPre::op::_T {
        void write(Ref<ostream> os, FmtFlags flags);
        void write(Ref<lang_rt::PrBufStream_T> pb);
        _T();
        lang::cc::Node::Expr::UnaryPre::op::NEG_T with_id(Int id);
        lang::cc::Node::Expr::UnaryPre::op::NEG_T with_bounds(lang_rt::TokenBounds bounds);
        lang::cc::Node::Expr::UnaryPre::op::NEG_T with_is_top(bool is_top);
        lang::cc::Node::Expr::UnaryPre::op::NEG_T with_sym(lang_rt::ParserSymId sym);
        lang::cc::Node::Expr::UnaryPre::op::NEG_T with_attr(lang_rt::ParserAttrMask attr);
        lang::cc::Node::Expr::UnaryPre::op::NEG_T with_first_k(lang_rt::ParserLookahead first_k);
        void hash_ser_acc_lang_cc_Node_Expr_UnaryPre_op_NEG(SerBuf& buf) const;
        virtual void hash_ser_acc(SerBuf& buf) const;
    };
}

void pr_debug(ostream& os, FmtFlags flags, lang::cc::Node::Expr::IncDecPre::op::INC_T x);

namespace lang::cc::Node::Expr::IncDecPre::op::INC {
    lang::cc::Node::Expr::IncDecPre::op::INC_T make(Int id, lang_rt::TokenBounds bounds, bool is_top, lang_rt::ParserSymId sym, lang_rt::ParserAttrMask attr, lang_rt::ParserLookahead first_k);
}

namespace lang::cc::Node::Expr::IncDecPre::op::INC {
    lang::cc::Node::Expr::IncDecPre::op::INC_T make_ext(ArenaPtr arena, Int id, lang_rt::TokenBounds bounds, bool is_top, lang_rt::ParserSymId sym, lang_rt::ParserAttrMask attr, lang_rt::ParserLookahead first_k);
}

namespace lang::cc::Node::Expr::IncDecPre::op::INC {
    struct _T: lang::cc::Node::Expr::IncDecPre::op::_T {
        void write(Ref<ostream> os, FmtFlags flags);
        void write(Ref<lang_rt::PrBufStream_T> pb);
        _T();
        lang::cc::Node::Expr::IncDecPre::op::INC_T with_id(Int id);
        lang::cc::Node::Expr::IncDecPre::op::INC_T with_bounds(lang_rt::TokenBounds bounds);
        lang::cc::Node::Expr::IncDecPre::op::INC_T with_is_top(bool is_top);
        lang::cc::Node::Expr::IncDecPre::op::INC_T with_sym(lang_rt::ParserSymId sym);
        lang::cc::Node::Expr::IncDecPre::op::INC_T with_attr(lang_rt::ParserAttrMask attr);
        lang::cc::Node::Expr::IncDecPre::op::INC_T with_first_k(lang_rt::ParserLookahead first_k);
        void hash_ser_acc_lang_cc_Node_Expr_IncDecPre_op_INC(SerBuf& buf) const;
        virtual void hash_ser_acc(SerBuf& buf) const;
    };
}

void pr_debug(ostream& os, FmtFlags flags, lang::cc::Node::Expr::IncDecPre::op::DEC_T x);

namespace lang::cc::Node::Expr::IncDecPre::op::DEC {
    lang::cc::Node::Expr::IncDecPre::op::DEC_T make(Int id, lang_rt::TokenBounds bounds, bool is_top, lang_rt::ParserSymId sym, lang_rt::ParserAttrMask attr, lang_rt::ParserLookahead first_k);
}

namespace lang::cc::Node::Expr::IncDecPre::op::DEC {
    lang::cc::Node::Expr::IncDecPre::op::DEC_T make_ext(ArenaPtr arena, Int id, lang_rt::TokenBounds bounds, bool is_top, lang_rt::ParserSymId sym, lang_rt::ParserAttrMask attr, lang_rt::ParserLookahead first_k);
}

namespace lang::cc::Node::Expr::IncDecPre::op::DEC {
    struct _T: lang::cc::Node::Expr::IncDecPre::op::_T {
        void write(Ref<ostream> os, FmtFlags flags);
        void write(Ref<lang_rt::PrBufStream_T> pb);
        _T();
        lang::cc::Node::Expr::IncDecPre::op::DEC_T with_id(Int id);
        lang::cc::Node::Expr::IncDecPre::op::DEC_T with_bounds(lang_rt::TokenBounds bounds);
        lang::cc::Node::Expr::IncDecPre::op::DEC_T with_is_top(bool is_top);
        lang::cc::Node::Expr::IncDecPre::op::DEC_T with_sym(lang_rt::ParserSymId sym);
        lang::cc::Node::Expr::IncDecPre::op::DEC_T with_attr(lang_rt::ParserAttrMask attr);
        lang::cc::Node::Expr::IncDecPre::op::DEC_T with_first_k(lang_rt::ParserLookahead first_k);
        void hash_ser_acc_lang_cc_Node_Expr_IncDecPre_op_DEC(SerBuf& buf) const;
        virtual void hash_ser_acc(SerBuf& buf) const;
    };
}

void pr_debug(ostream& os, FmtFlags flags, lang::cc::Node::Expr::IncDecPost::op::INC_T x);

namespace lang::cc::Node::Expr::IncDecPost::op::INC {
    lang::cc::Node::Expr::IncDecPost::op::INC_T make(Int id, lang_rt::TokenBounds bounds, bool is_top, lang_rt::ParserSymId sym, lang_rt::ParserAttrMask attr, lang_rt::ParserLookahead first_k);
}

namespace lang::cc::Node::Expr::IncDecPost::op::INC {
    lang::cc::Node::Expr::IncDecPost::op::INC_T make_ext(ArenaPtr arena, Int id, lang_rt::TokenBounds bounds, bool is_top, lang_rt::ParserSymId sym, lang_rt::ParserAttrMask attr, lang_rt::ParserLookahead first_k);
}

namespace lang::cc::Node::Expr::IncDecPost::op::INC {
    struct _T: lang::cc::Node::Expr::IncDecPost::op::_T {
        void write(Ref<ostream> os, FmtFlags flags);
        void write(Ref<lang_rt::PrBufStream_T> pb);
        _T();
        lang::cc::Node::Expr::IncDecPost::op::INC_T with_id(Int id);
        lang::cc::Node::Expr::IncDecPost::op::INC_T with_bounds(lang_rt::TokenBounds bounds);
        lang::cc::Node::Expr::IncDecPost::op::INC_T with_is_top(bool is_top);
        lang::cc::Node::Expr::IncDecPost::op::INC_T with_sym(lang_rt::ParserSymId sym);
        lang::cc::Node::Expr::IncDecPost::op::INC_T with_attr(lang_rt::ParserAttrMask attr);
        lang::cc::Node::Expr::IncDecPost::op::INC_T with_first_k(lang_rt::ParserLookahead first_k);
        void hash_ser_acc_lang_cc_Node_Expr_IncDecPost_op_INC(SerBuf& buf) const;
        virtual void hash_ser_acc(SerBuf& buf) const;
    };
}

void pr_debug(ostream& os, FmtFlags flags, lang::cc::Node::Expr::IncDecPost::op::DEC_T x);

namespace lang::cc::Node::Expr::IncDecPost::op::DEC {
    lang::cc::Node::Expr::IncDecPost::op::DEC_T make(Int id, lang_rt::TokenBounds bounds, bool is_top, lang_rt::ParserSymId sym, lang_rt::ParserAttrMask attr, lang_rt::ParserLookahead first_k);
}

namespace lang::cc::Node::Expr::IncDecPost::op::DEC {
    lang::cc::Node::Expr::IncDecPost::op::DEC_T make_ext(ArenaPtr arena, Int id, lang_rt::TokenBounds bounds, bool is_top, lang_rt::ParserSymId sym, lang_rt::ParserAttrMask attr, lang_rt::ParserLookahead first_k);
}

namespace lang::cc::Node::Expr::IncDecPost::op::DEC {
    struct _T: lang::cc::Node::Expr::IncDecPost::op::_T {
        void write(Ref<ostream> os, FmtFlags flags);
        void write(Ref<lang_rt::PrBufStream_T> pb);
        _T();
        lang::cc::Node::Expr::IncDecPost::op::DEC_T with_id(Int id);
        lang::cc::Node::Expr::IncDecPost::op::DEC_T with_bounds(lang_rt::TokenBounds bounds);
        lang::cc::Node::Expr::IncDecPost::op::DEC_T with_is_top(bool is_top);
        lang::cc::Node::Expr::IncDecPost::op::DEC_T with_sym(lang_rt::ParserSymId sym);
        lang::cc::Node::Expr::IncDecPost::op::DEC_T with_attr(lang_rt::ParserAttrMask attr);
        lang::cc::Node::Expr::IncDecPost::op::DEC_T with_first_k(lang_rt::ParserLookahead first_k);
        void hash_ser_acc_lang_cc_Node_Expr_IncDecPost_op_DEC(SerBuf& buf) const;
        virtual void hash_ser_acc(SerBuf& buf) const;
    };
}

void pr_debug(ostream& os, FmtFlags flags, lang::cc::Node::Expr::Bin1::op::LOR_T x);

namespace lang::cc::Node::Expr::Bin1::op::LOR {
    lang::cc::Node::Expr::Bin1::op::LOR_T make(Int id, lang_rt::TokenBounds bounds, bool is_top, lang_rt::ParserSymId sym, lang_rt::ParserAttrMask attr, lang_rt::ParserLookahead first_k);
}

namespace lang::cc::Node::Expr::Bin1::op::LOR {
    lang::cc::Node::Expr::Bin1::op::LOR_T make_ext(ArenaPtr arena, Int id, lang_rt::TokenBounds bounds, bool is_top, lang_rt::ParserSymId sym, lang_rt::ParserAttrMask attr, lang_rt::ParserLookahead first_k);
}

namespace lang::cc::Node::Expr::Bin1::op::LOR {
    struct _T: lang::cc::Node::Expr::Bin1::op::_T {
        void write(Ref<ostream> os, FmtFlags flags);
        void write(Ref<lang_rt::PrBufStream_T> pb);
        _T();
        lang::cc::Node::Expr::Bin1::op::LOR_T with_id(Int id);
        lang::cc::Node::Expr::Bin1::op::LOR_T with_bounds(lang_rt::TokenBounds bounds);
        lang::cc::Node::Expr::Bin1::op::LOR_T with_is_top(bool is_top);
        lang::cc::Node::Expr::Bin1::op::LOR_T with_sym(lang_rt::ParserSymId sym);
        lang::cc::Node::Expr::Bin1::op::LOR_T with_attr(lang_rt::ParserAttrMask attr);
        lang::cc::Node::Expr::Bin1::op::LOR_T with_first_k(lang_rt::ParserLookahead first_k);
        void hash_ser_acc_lang_cc_Node_Expr_Bin1_op_LOR(SerBuf& buf) const;
        virtual void hash_ser_acc(SerBuf& buf) const;
    };
}

void pr_debug(ostream& os, FmtFlags flags, lang::cc::Node::Expr::Bin2::op::LAND_T x);

namespace lang::cc::Node::Expr::Bin2::op::LAND {
    lang::cc::Node::Expr::Bin2::op::LAND_T make(Int id, lang_rt::TokenBounds bounds, bool is_top, lang_rt::ParserSymId sym, lang_rt::ParserAttrMask attr, lang_rt::ParserLookahead first_k);
}

namespace lang::cc::Node::Expr::Bin2::op::LAND {
    lang::cc::Node::Expr::Bin2::op::LAND_T make_ext(ArenaPtr arena, Int id, lang_rt::TokenBounds bounds, bool is_top, lang_rt::ParserSymId sym, lang_rt::ParserAttrMask attr, lang_rt::ParserLookahead first_k);
}

namespace lang::cc::Node::Expr::Bin2::op::LAND {
    struct _T: lang::cc::Node::Expr::Bin2::op::_T {
        void write(Ref<ostream> os, FmtFlags flags);
        void write(Ref<lang_rt::PrBufStream_T> pb);
        _T();
        lang::cc::Node::Expr::Bin2::op::LAND_T with_id(Int id);
        lang::cc::Node::Expr::Bin2::op::LAND_T with_bounds(lang_rt::TokenBounds bounds);
        lang::cc::Node::Expr::Bin2::op::LAND_T with_is_top(bool is_top);
        lang::cc::Node::Expr::Bin2::op::LAND_T with_sym(lang_rt::ParserSymId sym);
        lang::cc::Node::Expr::Bin2::op::LAND_T with_attr(lang_rt::ParserAttrMask attr);
        lang::cc::Node::Expr::Bin2::op::LAND_T with_first_k(lang_rt::ParserLookahead first_k);
        void hash_ser_acc_lang_cc_Node_Expr_Bin2_op_LAND(SerBuf& buf) const;
        virtual void hash_ser_acc(SerBuf& buf) const;
    };
}

void pr_debug(ostream& os, FmtFlags flags, lang::cc::Node::Expr::Bin3::op::EQ_T x);

namespace lang::cc::Node::Expr::Bin3::op::EQ {
    lang::cc::Node::Expr::Bin3::op::EQ_T make(Int id, lang_rt::TokenBounds bounds, bool is_top, lang_rt::ParserSymId sym, lang_rt::ParserAttrMask attr, lang_rt::ParserLookahead first_k);
}

namespace lang::cc::Node::Expr::Bin3::op::EQ {
    lang::cc::Node::Expr::Bin3::op::EQ_T make_ext(ArenaPtr arena, Int id, lang_rt::TokenBounds bounds, bool is_top, lang_rt::ParserSymId sym, lang_rt::ParserAttrMask attr, lang_rt::ParserLookahead first_k);
}

namespace lang::cc::Node::Expr::Bin3::op::EQ {
    struct _T: lang::cc::Node::Expr::Bin3::op::_T {
        void write(Ref<ostream> os, FmtFlags flags);
        void write(Ref<lang_rt::PrBufStream_T> pb);
        _T();
        lang::cc::Node::Expr::Bin3::op::EQ_T with_id(Int id);
        lang::cc::Node::Expr::Bin3::op::EQ_T with_bounds(lang_rt::TokenBounds bounds);
        lang::cc::Node::Expr::Bin3::op::EQ_T with_is_top(bool is_top);
        lang::cc::Node::Expr::Bin3::op::EQ_T with_sym(lang_rt::ParserSymId sym);
        lang::cc::Node::Expr::Bin3::op::EQ_T with_attr(lang_rt::ParserAttrMask attr);
        lang::cc::Node::Expr::Bin3::op::EQ_T with_first_k(lang_rt::ParserLookahead first_k);
        void hash_ser_acc_lang_cc_Node_Expr_Bin3_op_EQ(SerBuf& buf) const;
        virtual void hash_ser_acc(SerBuf& buf) const;
    };
}

void pr_debug(ostream& os, FmtFlags flags, lang::cc::Node::Expr::Bin3::op::NE_T x);

namespace lang::cc::Node::Expr::Bin3::op::NE {
    lang::cc::Node::Expr::Bin3::op::NE_T make(Int id, lang_rt::TokenBounds bounds, bool is_top, lang_rt::ParserSymId sym, lang_rt::ParserAttrMask attr, lang_rt::ParserLookahead first_k);
}

namespace lang::cc::Node::Expr::Bin3::op::NE {
    lang::cc::Node::Expr::Bin3::op::NE_T make_ext(ArenaPtr arena, Int id, lang_rt::TokenBounds bounds, bool is_top, lang_rt::ParserSymId sym, lang_rt::ParserAttrMask attr, lang_rt::ParserLookahead first_k);
}

namespace lang::cc::Node::Expr::Bin3::op::NE {
    struct _T: lang::cc::Node::Expr::Bin3::op::_T {
        void write(Ref<ostream> os, FmtFlags flags);
        void write(Ref<lang_rt::PrBufStream_T> pb);
        _T();
        lang::cc::Node::Expr::Bin3::op::NE_T with_id(Int id);
        lang::cc::Node::Expr::Bin3::op::NE_T with_bounds(lang_rt::TokenBounds bounds);
        lang::cc::Node::Expr::Bin3::op::NE_T with_is_top(bool is_top);
        lang::cc::Node::Expr::Bin3::op::NE_T with_sym(lang_rt::ParserSymId sym);
        lang::cc::Node::Expr::Bin3::op::NE_T with_attr(lang_rt::ParserAttrMask attr);
        lang::cc::Node::Expr::Bin3::op::NE_T with_first_k(lang_rt::ParserLookahead first_k);
        void hash_ser_acc_lang_cc_Node_Expr_Bin3_op_NE(SerBuf& buf) const;
        virtual void hash_ser_acc(SerBuf& buf) const;
    };
}

void pr_debug(ostream& os, FmtFlags flags, lang::cc::Node::Expr::Bin3::op::LE_T x);

namespace lang::cc::Node::Expr::Bin3::op::LE {
    lang::cc::Node::Expr::Bin3::op::LE_T make(Int id, lang_rt::TokenBounds bounds, bool is_top, lang_rt::ParserSymId sym, lang_rt::ParserAttrMask attr, lang_rt::ParserLookahead first_k);
}

namespace lang::cc::Node::Expr::Bin3::op::LE {
    lang::cc::Node::Expr::Bin3::op::LE_T make_ext(ArenaPtr arena, Int id, lang_rt::TokenBounds bounds, bool is_top, lang_rt::ParserSymId sym, lang_rt::ParserAttrMask attr, lang_rt::ParserLookahead first_k);
}

namespace lang::cc::Node::Expr::Bin3::op::LE {
    struct _T: lang::cc::Node::Expr::Bin3::op::_T {
        void write(Ref<ostream> os, FmtFlags flags);
        void write(Ref<lang_rt::PrBufStream_T> pb);
        _T();
        lang::cc::Node::Expr::Bin3::op::LE_T with_id(Int id);
        lang::cc::Node::Expr::Bin3::op::LE_T with_bounds(lang_rt::TokenBounds bounds);
        lang::cc::Node::Expr::Bin3::op::LE_T with_is_top(bool is_top);
        lang::cc::Node::Expr::Bin3::op::LE_T with_sym(lang_rt::ParserSymId sym);
        lang::cc::Node::Expr::Bin3::op::LE_T with_attr(lang_rt::ParserAttrMask attr);
        lang::cc::Node::Expr::Bin3::op::LE_T with_first_k(lang_rt::ParserLookahead first_k);
        void hash_ser_acc_lang_cc_Node_Expr_Bin3_op_LE(SerBuf& buf) const;
        virtual void hash_ser_acc(SerBuf& buf) const;
    };
}

void pr_debug(ostream& os, FmtFlags flags, lang::cc::Node::Expr::Bin3::op::GE_T x);

namespace lang::cc::Node::Expr::Bin3::op::GE {
    lang::cc::Node::Expr::Bin3::op::GE_T make(Int id, lang_rt::TokenBounds bounds, bool is_top, lang_rt::ParserSymId sym, lang_rt::ParserAttrMask attr, lang_rt::ParserLookahead first_k);
}

namespace lang::cc::Node::Expr::Bin3::op::GE {
    lang::cc::Node::Expr::Bin3::op::GE_T make_ext(ArenaPtr arena, Int id, lang_rt::TokenBounds bounds, bool is_top, lang_rt::ParserSymId sym, lang_rt::ParserAttrMask attr, lang_rt::ParserLookahead first_k);
}

namespace lang::cc::Node::Expr::Bin3::op::GE {
    struct _T: lang::cc::Node::Expr::Bin3::op::_T {
        void write(Ref<ostream> os, FmtFlags flags);
        void write(Ref<lang_rt::PrBufStream_T> pb);
        _T();
        lang::cc::Node::Expr::Bin3::op::GE_T with_id(Int id);
        lang::cc::Node::Expr::Bin3::op::GE_T with_bounds(lang_rt::TokenBounds bounds);
        lang::cc::Node::Expr::Bin3::op::GE_T with_is_top(bool is_top);
        lang::cc::Node::Expr::Bin3::op::GE_T with_sym(lang_rt::ParserSymId sym);
        lang::cc::Node::Expr::Bin3::op::GE_T with_attr(lang_rt::ParserAttrMask attr);
        lang::cc::Node::Expr::Bin3::op::GE_T with_first_k(lang_rt::ParserLookahead first_k);
        void hash_ser_acc_lang_cc_Node_Expr_Bin3_op_GE(SerBuf& buf) const;
        virtual void hash_ser_acc(SerBuf& buf) const;
    };
}

void pr_debug(ostream& os, FmtFlags flags, lang::cc::Node::Expr::Bin3::op::LT_T x);

namespace lang::cc::Node::Expr::Bin3::op::LT {
    lang::cc::Node::Expr::Bin3::op::LT_T make(Int id, lang_rt::TokenBounds bounds, bool is_top, lang_rt::ParserSymId sym, lang_rt::ParserAttrMask attr, lang_rt::ParserLookahead first_k);
}

namespace lang::cc::Node::Expr::Bin3::op::LT {
    lang::cc::Node::Expr::Bin3::op::LT_T make_ext(ArenaPtr arena, Int id, lang_rt::TokenBounds bounds, bool is_top, lang_rt::ParserSymId sym, lang_rt::ParserAttrMask attr, lang_rt::ParserLookahead first_k);
}

namespace lang::cc::Node::Expr::Bin3::op::LT {
    struct _T: lang::cc::Node::Expr::Bin3::op::_T {
        void write(Ref<ostream> os, FmtFlags flags);
        void write(Ref<lang_rt::PrBufStream_T> pb);
        _T();
        lang::cc::Node::Expr::Bin3::op::LT_T with_id(Int id);
        lang::cc::Node::Expr::Bin3::op::LT_T with_bounds(lang_rt::TokenBounds bounds);
        lang::cc::Node::Expr::Bin3::op::LT_T with_is_top(bool is_top);
        lang::cc::Node::Expr::Bin3::op::LT_T with_sym(lang_rt::ParserSymId sym);
        lang::cc::Node::Expr::Bin3::op::LT_T with_attr(lang_rt::ParserAttrMask attr);
        lang::cc::Node::Expr::Bin3::op::LT_T with_first_k(lang_rt::ParserLookahead first_k);
        void hash_ser_acc_lang_cc_Node_Expr_Bin3_op_LT(SerBuf& buf) const;
        virtual void hash_ser_acc(SerBuf& buf) const;
    };
}

void pr_debug(ostream& os, FmtFlags flags, lang::cc::Node::Expr::Bin3::op::GT_T x);

namespace lang::cc::Node::Expr::Bin3::op::GT {
    lang::cc::Node::Expr::Bin3::op::GT_T make(Int id, lang_rt::TokenBounds bounds, bool is_top, lang_rt::ParserSymId sym, lang_rt::ParserAttrMask attr, lang_rt::ParserLookahead first_k);
}

namespace lang::cc::Node::Expr::Bin3::op::GT {
    lang::cc::Node::Expr::Bin3::op::GT_T make_ext(ArenaPtr arena, Int id, lang_rt::TokenBounds bounds, bool is_top, lang_rt::ParserSymId sym, lang_rt::ParserAttrMask attr, lang_rt::ParserLookahead first_k);
}

namespace lang::cc::Node::Expr::Bin3::op::GT {
    struct _T: lang::cc::Node::Expr::Bin3::op::_T {
        void write(Ref<ostream> os, FmtFlags flags);
        void write(Ref<lang_rt::PrBufStream_T> pb);
        _T();
        lang::cc::Node::Expr::Bin3::op::GT_T with_id(Int id);
        lang::cc::Node::Expr::Bin3::op::GT_T with_bounds(lang_rt::TokenBounds bounds);
        lang::cc::Node::Expr::Bin3::op::GT_T with_is_top(bool is_top);
        lang::cc::Node::Expr::Bin3::op::GT_T with_sym(lang_rt::ParserSymId sym);
        lang::cc::Node::Expr::Bin3::op::GT_T with_attr(lang_rt::ParserAttrMask attr);
        lang::cc::Node::Expr::Bin3::op::GT_T with_first_k(lang_rt::ParserLookahead first_k);
        void hash_ser_acc_lang_cc_Node_Expr_Bin3_op_GT(SerBuf& buf) const;
        virtual void hash_ser_acc(SerBuf& buf) const;
    };
}

void pr_debug(ostream& os, FmtFlags flags, lang::cc::Node::Expr::Bin4::op::SHL_T x);

namespace lang::cc::Node::Expr::Bin4::op::SHL {
    lang::cc::Node::Expr::Bin4::op::SHL_T make(Int id, lang_rt::TokenBounds bounds, bool is_top, lang_rt::ParserSymId sym, lang_rt::ParserAttrMask attr, lang_rt::ParserLookahead first_k);
}

namespace lang::cc::Node::Expr::Bin4::op::SHL {
    lang::cc::Node::Expr::Bin4::op::SHL_T make_ext(ArenaPtr arena, Int id, lang_rt::TokenBounds bounds, bool is_top, lang_rt::ParserSymId sym, lang_rt::ParserAttrMask attr, lang_rt::ParserLookahead first_k);
}

namespace lang::cc::Node::Expr::Bin4::op::SHL {
    struct _T: lang::cc::Node::Expr::Bin4::op::_T {
        void write(Ref<ostream> os, FmtFlags flags);
        void write(Ref<lang_rt::PrBufStream_T> pb);
        _T();
        lang::cc::Node::Expr::Bin4::op::SHL_T with_id(Int id);
        lang::cc::Node::Expr::Bin4::op::SHL_T with_bounds(lang_rt::TokenBounds bounds);
        lang::cc::Node::Expr::Bin4::op::SHL_T with_is_top(bool is_top);
        lang::cc::Node::Expr::Bin4::op::SHL_T with_sym(lang_rt::ParserSymId sym);
        lang::cc::Node::Expr::Bin4::op::SHL_T with_attr(lang_rt::ParserAttrMask attr);
        lang::cc::Node::Expr::Bin4::op::SHL_T with_first_k(lang_rt::ParserLookahead first_k);
        void hash_ser_acc_lang_cc_Node_Expr_Bin4_op_SHL(SerBuf& buf) const;
        virtual void hash_ser_acc(SerBuf& buf) const;
    };
}

void pr_debug(ostream& os, FmtFlags flags, lang::cc::Node::Expr::Bin5::op::PLUS_T x);

namespace lang::cc::Node::Expr::Bin5::op::PLUS {
    lang::cc::Node::Expr::Bin5::op::PLUS_T make(Int id, lang_rt::TokenBounds bounds, bool is_top, lang_rt::ParserSymId sym, lang_rt::ParserAttrMask attr, lang_rt::ParserLookahead first_k);
}

namespace lang::cc::Node::Expr::Bin5::op::PLUS {
    lang::cc::Node::Expr::Bin5::op::PLUS_T make_ext(ArenaPtr arena, Int id, lang_rt::TokenBounds bounds, bool is_top, lang_rt::ParserSymId sym, lang_rt::ParserAttrMask attr, lang_rt::ParserLookahead first_k);
}

namespace lang::cc::Node::Expr::Bin5::op::PLUS {
    struct _T: lang::cc::Node::Expr::Bin5::op::_T {
        void write(Ref<ostream> os, FmtFlags flags);
        void write(Ref<lang_rt::PrBufStream_T> pb);
        _T();
        lang::cc::Node::Expr::Bin5::op::PLUS_T with_id(Int id);
        lang::cc::Node::Expr::Bin5::op::PLUS_T with_bounds(lang_rt::TokenBounds bounds);
        lang::cc::Node::Expr::Bin5::op::PLUS_T with_is_top(bool is_top);
        lang::cc::Node::Expr::Bin5::op::PLUS_T with_sym(lang_rt::ParserSymId sym);
        lang::cc::Node::Expr::Bin5::op::PLUS_T with_attr(lang_rt::ParserAttrMask attr);
        lang::cc::Node::Expr::Bin5::op::PLUS_T with_first_k(lang_rt::ParserLookahead first_k);
        void hash_ser_acc_lang_cc_Node_Expr_Bin5_op_PLUS(SerBuf& buf) const;
        virtual void hash_ser_acc(SerBuf& buf) const;
    };
}

void pr_debug(ostream& os, FmtFlags flags, lang::cc::Node::Expr::Bin5::op::MINUS_T x);

namespace lang::cc::Node::Expr::Bin5::op::MINUS {
    lang::cc::Node::Expr::Bin5::op::MINUS_T make(Int id, lang_rt::TokenBounds bounds, bool is_top, lang_rt::ParserSymId sym, lang_rt::ParserAttrMask attr, lang_rt::ParserLookahead first_k);
}

namespace lang::cc::Node::Expr::Bin5::op::MINUS {
    lang::cc::Node::Expr::Bin5::op::MINUS_T make_ext(ArenaPtr arena, Int id, lang_rt::TokenBounds bounds, bool is_top, lang_rt::ParserSymId sym, lang_rt::ParserAttrMask attr, lang_rt::ParserLookahead first_k);
}

namespace lang::cc::Node::Expr::Bin5::op::MINUS {
    struct _T: lang::cc::Node::Expr::Bin5::op::_T {
        void write(Ref<ostream> os, FmtFlags flags);
        void write(Ref<lang_rt::PrBufStream_T> pb);
        _T();
        lang::cc::Node::Expr::Bin5::op::MINUS_T with_id(Int id);
        lang::cc::Node::Expr::Bin5::op::MINUS_T with_bounds(lang_rt::TokenBounds bounds);
        lang::cc::Node::Expr::Bin5::op::MINUS_T with_is_top(bool is_top);
        lang::cc::Node::Expr::Bin5::op::MINUS_T with_sym(lang_rt::ParserSymId sym);
        lang::cc::Node::Expr::Bin5::op::MINUS_T with_attr(lang_rt::ParserAttrMask attr);
        lang::cc::Node::Expr::Bin5::op::MINUS_T with_first_k(lang_rt::ParserLookahead first_k);
        void hash_ser_acc_lang_cc_Node_Expr_Bin5_op_MINUS(SerBuf& buf) const;
        virtual void hash_ser_acc(SerBuf& buf) const;
    };
}

void pr_debug(ostream& os, FmtFlags flags, lang::cc::Node::Expr::Bin6::op::TIMES_T x);

namespace lang::cc::Node::Expr::Bin6::op::TIMES {
    lang::cc::Node::Expr::Bin6::op::TIMES_T make(Int id, lang_rt::TokenBounds bounds, bool is_top, lang_rt::ParserSymId sym, lang_rt::ParserAttrMask attr, lang_rt::ParserLookahead first_k);
}

namespace lang::cc::Node::Expr::Bin6::op::TIMES {
    lang::cc::Node::Expr::Bin6::op::TIMES_T make_ext(ArenaPtr arena, Int id, lang_rt::TokenBounds bounds, bool is_top, lang_rt::ParserSymId sym, lang_rt::ParserAttrMask attr, lang_rt::ParserLookahead first_k);
}

namespace lang::cc::Node::Expr::Bin6::op::TIMES {
    struct _T: lang::cc::Node::Expr::Bin6::op::_T {
        void write(Ref<ostream> os, FmtFlags flags);
        void write(Ref<lang_rt::PrBufStream_T> pb);
        _T();
        lang::cc::Node::Expr::Bin6::op::TIMES_T with_id(Int id);
        lang::cc::Node::Expr::Bin6::op::TIMES_T with_bounds(lang_rt::TokenBounds bounds);
        lang::cc::Node::Expr::Bin6::op::TIMES_T with_is_top(bool is_top);
        lang::cc::Node::Expr::Bin6::op::TIMES_T with_sym(lang_rt::ParserSymId sym);
        lang::cc::Node::Expr::Bin6::op::TIMES_T with_attr(lang_rt::ParserAttrMask attr);
        lang::cc::Node::Expr::Bin6::op::TIMES_T with_first_k(lang_rt::ParserLookahead first_k);
        void hash_ser_acc_lang_cc_Node_Expr_Bin6_op_TIMES(SerBuf& buf) const;
        virtual void hash_ser_acc(SerBuf& buf) const;
    };
}

void pr_debug(ostream& os, FmtFlags flags, lang::cc::Node::Expr::Bin6::op::DIVIDE_T x);

namespace lang::cc::Node::Expr::Bin6::op::DIVIDE {
    lang::cc::Node::Expr::Bin6::op::DIVIDE_T make(Int id, lang_rt::TokenBounds bounds, bool is_top, lang_rt::ParserSymId sym, lang_rt::ParserAttrMask attr, lang_rt::ParserLookahead first_k);
}

namespace lang::cc::Node::Expr::Bin6::op::DIVIDE {
    lang::cc::Node::Expr::Bin6::op::DIVIDE_T make_ext(ArenaPtr arena, Int id, lang_rt::TokenBounds bounds, bool is_top, lang_rt::ParserSymId sym, lang_rt::ParserAttrMask attr, lang_rt::ParserLookahead first_k);
}

namespace lang::cc::Node::Expr::Bin6::op::DIVIDE {
    struct _T: lang::cc::Node::Expr::Bin6::op::_T {
        void write(Ref<ostream> os, FmtFlags flags);
        void write(Ref<lang_rt::PrBufStream_T> pb);
        _T();
        lang::cc::Node::Expr::Bin6::op::DIVIDE_T with_id(Int id);
        lang::cc::Node::Expr::Bin6::op::DIVIDE_T with_bounds(lang_rt::TokenBounds bounds);
        lang::cc::Node::Expr::Bin6::op::DIVIDE_T with_is_top(bool is_top);
        lang::cc::Node::Expr::Bin6::op::DIVIDE_T with_sym(lang_rt::ParserSymId sym);
        lang::cc::Node::Expr::Bin6::op::DIVIDE_T with_attr(lang_rt::ParserAttrMask attr);
        lang::cc::Node::Expr::Bin6::op::DIVIDE_T with_first_k(lang_rt::ParserLookahead first_k);
        void hash_ser_acc_lang_cc_Node_Expr_Bin6_op_DIVIDE(SerBuf& buf) const;
        virtual void hash_ser_acc(SerBuf& buf) const;
    };
}

void pr_debug(ostream& os, FmtFlags flags, lang::cc::Node::Expr::Bin6::op::MODULO_T x);

namespace lang::cc::Node::Expr::Bin6::op::MODULO {
    lang::cc::Node::Expr::Bin6::op::MODULO_T make(Int id, lang_rt::TokenBounds bounds, bool is_top, lang_rt::ParserSymId sym, lang_rt::ParserAttrMask attr, lang_rt::ParserLookahead first_k);
}

namespace lang::cc::Node::Expr::Bin6::op::MODULO {
    lang::cc::Node::Expr::Bin6::op::MODULO_T make_ext(ArenaPtr arena, Int id, lang_rt::TokenBounds bounds, bool is_top, lang_rt::ParserSymId sym, lang_rt::ParserAttrMask attr, lang_rt::ParserLookahead first_k);
}

namespace lang::cc::Node::Expr::Bin6::op::MODULO {
    struct _T: lang::cc::Node::Expr::Bin6::op::_T {
        void write(Ref<ostream> os, FmtFlags flags);
        void write(Ref<lang_rt::PrBufStream_T> pb);
        _T();
        lang::cc::Node::Expr::Bin6::op::MODULO_T with_id(Int id);
        lang::cc::Node::Expr::Bin6::op::MODULO_T with_bounds(lang_rt::TokenBounds bounds);
        lang::cc::Node::Expr::Bin6::op::MODULO_T with_is_top(bool is_top);
        lang::cc::Node::Expr::Bin6::op::MODULO_T with_sym(lang_rt::ParserSymId sym);
        lang::cc::Node::Expr::Bin6::op::MODULO_T with_attr(lang_rt::ParserAttrMask attr);
        lang::cc::Node::Expr::Bin6::op::MODULO_T with_first_k(lang_rt::ParserLookahead first_k);
        void hash_ser_acc_lang_cc_Node_Expr_Bin6_op_MODULO(SerBuf& buf) const;
        virtual void hash_ser_acc(SerBuf& buf) const;
    };
}

void pr_debug(ostream& os, FmtFlags flags, lang::cc::Node::Decl::Struct::tmpl::args::item_T x);

namespace lang::cc::Node::Decl::Struct::tmpl::args::item {
    lang::cc::Node::Decl::Struct::tmpl::args::item_T make(Int id, lang_rt::TokenBounds bounds, bool is_top, lang_rt::ParserSymId sym, lang_rt::ParserAttrMask attr, lang_rt::ParserLookahead first_k, bool dots, lang::cc::Node::Expr_T name);
}

namespace lang::cc::Node::Decl::Struct::tmpl::args::item {
    lang::cc::Node::Decl::Struct::tmpl::args::item_T make_ext(ArenaPtr arena, Int id, lang_rt::TokenBounds bounds, bool is_top, lang_rt::ParserSymId sym, lang_rt::ParserAttrMask attr, lang_rt::ParserLookahead first_k, bool dots, lang::cc::Node::Expr_T name);
}

namespace lang::cc::Node::Decl::Struct::tmpl::args::item {
    struct _T: lang::cc::Node::_T {
        void write(Ref<ostream> os, FmtFlags flags);
        void write(Ref<lang_rt::PrBufStream_T> pb);
        bool dots_;
        lang::cc::Node::Expr_T name_;
        _T();
        lang::cc::Node::Decl::Struct::tmpl::args::item_T with_id(Int id);
        lang::cc::Node::Decl::Struct::tmpl::args::item_T with_bounds(lang_rt::TokenBounds bounds);
        lang::cc::Node::Decl::Struct::tmpl::args::item_T with_is_top(bool is_top);
        lang::cc::Node::Decl::Struct::tmpl::args::item_T with_sym(lang_rt::ParserSymId sym);
        lang::cc::Node::Decl::Struct::tmpl::args::item_T with_attr(lang_rt::ParserAttrMask attr);
        lang::cc::Node::Decl::Struct::tmpl::args::item_T with_first_k(lang_rt::ParserLookahead first_k);
        lang::cc::Node::Decl::Struct::tmpl::args::item_T with_dots(bool dots);
        lang::cc::Node::Decl::Struct::tmpl::args::item_T with_name(lang::cc::Node::Expr_T name);
        void hash_ser_acc_lang_cc_Node_Decl_Struct_tmpl_args_item(SerBuf& buf) const;
        virtual void hash_ser_acc(SerBuf& buf) const;
    };
}

void pr_debug(ostream& os, FmtFlags flags, lang::cc::Node::Entry::Fun::tmpl::args::item_T x);

namespace lang::cc::Node::Entry::Fun::tmpl::args::item {
    lang::cc::Node::Entry::Fun::tmpl::args::item_T make(Int id, lang_rt::TokenBounds bounds, bool is_top, lang_rt::ParserSymId sym, lang_rt::ParserAttrMask attr, lang_rt::ParserLookahead first_k, bool dots, lang::cc::Node::Expr_T name);
}

namespace lang::cc::Node::Entry::Fun::tmpl::args::item {
    lang::cc::Node::Entry::Fun::tmpl::args::item_T make_ext(ArenaPtr arena, Int id, lang_rt::TokenBounds bounds, bool is_top, lang_rt::ParserSymId sym, lang_rt::ParserAttrMask attr, lang_rt::ParserLookahead first_k, bool dots, lang::cc::Node::Expr_T name);
}

namespace lang::cc::Node::Entry::Fun::tmpl::args::item {
    struct _T: lang::cc::Node::_T {
        void write(Ref<ostream> os, FmtFlags flags);
        void write(Ref<lang_rt::PrBufStream_T> pb);
        bool dots_;
        lang::cc::Node::Expr_T name_;
        _T();
        lang::cc::Node::Entry::Fun::tmpl::args::item_T with_id(Int id);
        lang::cc::Node::Entry::Fun::tmpl::args::item_T with_bounds(lang_rt::TokenBounds bounds);
        lang::cc::Node::Entry::Fun::tmpl::args::item_T with_is_top(bool is_top);
        lang::cc::Node::Entry::Fun::tmpl::args::item_T with_sym(lang_rt::ParserSymId sym);
        lang::cc::Node::Entry::Fun::tmpl::args::item_T with_attr(lang_rt::ParserAttrMask attr);
        lang::cc::Node::Entry::Fun::tmpl::args::item_T with_first_k(lang_rt::ParserLookahead first_k);
        lang::cc::Node::Entry::Fun::tmpl::args::item_T with_dots(bool dots);
        lang::cc::Node::Entry::Fun::tmpl::args::item_T with_name(lang::cc::Node::Expr_T name);
        void hash_ser_acc_lang_cc_Node_Entry_Fun_tmpl_args_item(SerBuf& buf) const;
        virtual void hash_ser_acc(SerBuf& buf) const;
    };
}

void pr_debug(ostream& os, FmtFlags flags, lang::cc::Node::Decl::Fun::tmpl::args::item_T x);

namespace lang::cc::Node::Decl::Fun::tmpl::args::item {
    lang::cc::Node::Decl::Fun::tmpl::args::item_T make(Int id, lang_rt::TokenBounds bounds, bool is_top, lang_rt::ParserSymId sym, lang_rt::ParserAttrMask attr, lang_rt::ParserLookahead first_k, bool dots, lang::cc::Node::Expr_T name);
}

namespace lang::cc::Node::Decl::Fun::tmpl::args::item {
    lang::cc::Node::Decl::Fun::tmpl::args::item_T make_ext(ArenaPtr arena, Int id, lang_rt::TokenBounds bounds, bool is_top, lang_rt::ParserSymId sym, lang_rt::ParserAttrMask attr, lang_rt::ParserLookahead first_k, bool dots, lang::cc::Node::Expr_T name);
}

namespace lang::cc::Node::Decl::Fun::tmpl::args::item {
    struct _T: lang::cc::Node::_T {
        void write(Ref<ostream> os, FmtFlags flags);
        void write(Ref<lang_rt::PrBufStream_T> pb);
        bool dots_;
        lang::cc::Node::Expr_T name_;
        _T();
        lang::cc::Node::Decl::Fun::tmpl::args::item_T with_id(Int id);
        lang::cc::Node::Decl::Fun::tmpl::args::item_T with_bounds(lang_rt::TokenBounds bounds);
        lang::cc::Node::Decl::Fun::tmpl::args::item_T with_is_top(bool is_top);
        lang::cc::Node::Decl::Fun::tmpl::args::item_T with_sym(lang_rt::ParserSymId sym);
        lang::cc::Node::Decl::Fun::tmpl::args::item_T with_attr(lang_rt::ParserAttrMask attr);
        lang::cc::Node::Decl::Fun::tmpl::args::item_T with_first_k(lang_rt::ParserLookahead first_k);
        lang::cc::Node::Decl::Fun::tmpl::args::item_T with_dots(bool dots);
        lang::cc::Node::Decl::Fun::tmpl::args::item_T with_name(lang::cc::Node::Expr_T name);
        void hash_ser_acc_lang_cc_Node_Decl_Fun_tmpl_args_item(SerBuf& buf) const;
        virtual void hash_ser_acc(SerBuf& buf) const;
    };
}

void pr_debug(ostream& os, FmtFlags flags, lang::cc::Node::Decl::UsingAlias::tmpl::args::item_T x);

namespace lang::cc::Node::Decl::UsingAlias::tmpl::args::item {
    lang::cc::Node::Decl::UsingAlias::tmpl::args::item_T make(Int id, lang_rt::TokenBounds bounds, bool is_top, lang_rt::ParserSymId sym, lang_rt::ParserAttrMask attr, lang_rt::ParserLookahead first_k, bool dots, lang::cc::Node::Expr_T name);
}

namespace lang::cc::Node::Decl::UsingAlias::tmpl::args::item {
    lang::cc::Node::Decl::UsingAlias::tmpl::args::item_T make_ext(ArenaPtr arena, Int id, lang_rt::TokenBounds bounds, bool is_top, lang_rt::ParserSymId sym, lang_rt::ParserAttrMask attr, lang_rt::ParserLookahead first_k, bool dots, lang::cc::Node::Expr_T name);
}

namespace lang::cc::Node::Decl::UsingAlias::tmpl::args::item {
    struct _T: lang::cc::Node::_T {
        void write(Ref<ostream> os, FmtFlags flags);
        void write(Ref<lang_rt::PrBufStream_T> pb);
        bool dots_;
        lang::cc::Node::Expr_T name_;
        _T();
        lang::cc::Node::Decl::UsingAlias::tmpl::args::item_T with_id(Int id);
        lang::cc::Node::Decl::UsingAlias::tmpl::args::item_T with_bounds(lang_rt::TokenBounds bounds);
        lang::cc::Node::Decl::UsingAlias::tmpl::args::item_T with_is_top(bool is_top);
        lang::cc::Node::Decl::UsingAlias::tmpl::args::item_T with_sym(lang_rt::ParserSymId sym);
        lang::cc::Node::Decl::UsingAlias::tmpl::args::item_T with_attr(lang_rt::ParserAttrMask attr);
        lang::cc::Node::Decl::UsingAlias::tmpl::args::item_T with_first_k(lang_rt::ParserLookahead first_k);
        lang::cc::Node::Decl::UsingAlias::tmpl::args::item_T with_dots(bool dots);
        lang::cc::Node::Decl::UsingAlias::tmpl::args::item_T with_name(lang::cc::Node::Expr_T name);
        void hash_ser_acc_lang_cc_Node_Decl_UsingAlias_tmpl_args_item(SerBuf& buf) const;
        virtual void hash_ser_acc(SerBuf& buf) const;
    };
}

void visit_lang_cc_Node(lang::cc::Node::Expr::Paren_T x, function<void(lang::cc::Node_T)> f);

void visit_lang_cc_Node(lang::cc::Node::Expr::Call_T x, function<void(lang::cc::Node_T)> f);

void visit_lang_cc_Node(lang::cc::Node::Expr::Index_T x, function<void(lang::cc::Node_T)> f);

void visit_lang_cc_Node(lang::cc::Node::Expr::IndexEmpty_T x, function<void(lang::cc::Node_T)> f);

void visit_lang_cc_Node(lang::cc::Node::Expr::Dot_T x, function<void(lang::cc::Node_T)> f);

void visit_lang_cc_Node(lang::cc::Node::Expr::Arrow_T x, function<void(lang::cc::Node_T)> f);

void visit_lang_cc_Node(lang::cc::Node::Expr::Ref__T x, function<void(lang::cc::Node_T)> f);

void visit_lang_cc_Node(lang::cc::Node::Expr::AddrOf_T x, function<void(lang::cc::Node_T)> f);

void visit_lang_cc_Node(lang::cc::Node::Expr::Deref_T x, function<void(lang::cc::Node_T)> f);

void visit_lang_cc_Node(lang::cc::Node::Expr::UnaryPre::op::NOT_T x, function<void(lang::cc::Node_T)> f);

void visit_lang_cc_Node(lang::cc::Node::Expr::UnaryPre::op::NEG_T x, function<void(lang::cc::Node_T)> f);

void visit_lang_cc_Node(lang::cc::Node::Expr::UnaryPre::op_T x, function<void(lang::cc::Node_T)> f);

void visit_lang_cc_Node(lang::cc::Node::Expr::UnaryPre_T x, function<void(lang::cc::Node_T)> f);

void visit_lang_cc_Node(lang::cc::Node::Expr::IncDecPre::op::INC_T x, function<void(lang::cc::Node_T)> f);

void visit_lang_cc_Node(lang::cc::Node::Expr::IncDecPre::op::DEC_T x, function<void(lang::cc::Node_T)> f);

void visit_lang_cc_Node(lang::cc::Node::Expr::IncDecPre::op_T x, function<void(lang::cc::Node_T)> f);

void visit_lang_cc_Node(lang::cc::Node::Expr::IncDecPre_T x, function<void(lang::cc::Node_T)> f);

void visit_lang_cc_Node(lang::cc::Node::Expr::IncDecPost::op::INC_T x, function<void(lang::cc::Node_T)> f);

void visit_lang_cc_Node(lang::cc::Node::Expr::IncDecPost::op::DEC_T x, function<void(lang::cc::Node_T)> f);

void visit_lang_cc_Node(lang::cc::Node::Expr::IncDecPost::op_T x, function<void(lang::cc::Node_T)> f);

void visit_lang_cc_Node(lang::cc::Node::Expr::IncDecPost_T x, function<void(lang::cc::Node_T)> f);

void visit_lang_cc_Node(lang::cc::Node::Expr::Assign_T x, function<void(lang::cc::Node_T)> f);

void visit_lang_cc_Node(lang::cc::Node::Expr::Bin1::op::LOR_T x, function<void(lang::cc::Node_T)> f);

void visit_lang_cc_Node(lang::cc::Node::Expr::Bin1::op_T x, function<void(lang::cc::Node_T)> f);

void visit_lang_cc_Node(lang::cc::Node::Expr::Bin1_T x, function<void(lang::cc::Node_T)> f);

void visit_lang_cc_Node(lang::cc::Node::Expr::Bin2::op::LAND_T x, function<void(lang::cc::Node_T)> f);

void visit_lang_cc_Node(lang::cc::Node::Expr::Bin2::op_T x, function<void(lang::cc::Node_T)> f);

void visit_lang_cc_Node(lang::cc::Node::Expr::Bin2_T x, function<void(lang::cc::Node_T)> f);

void visit_lang_cc_Node(lang::cc::Node::Expr::Bin3::op::EQ_T x, function<void(lang::cc::Node_T)> f);

void visit_lang_cc_Node(lang::cc::Node::Expr::Bin3::op::NE_T x, function<void(lang::cc::Node_T)> f);

void visit_lang_cc_Node(lang::cc::Node::Expr::Bin3::op::LE_T x, function<void(lang::cc::Node_T)> f);

void visit_lang_cc_Node(lang::cc::Node::Expr::Bin3::op::GE_T x, function<void(lang::cc::Node_T)> f);

void visit_lang_cc_Node(lang::cc::Node::Expr::Bin3::op::LT_T x, function<void(lang::cc::Node_T)> f);

void visit_lang_cc_Node(lang::cc::Node::Expr::Bin3::op::GT_T x, function<void(lang::cc::Node_T)> f);

void visit_lang_cc_Node(lang::cc::Node::Expr::Bin3::op_T x, function<void(lang::cc::Node_T)> f);

void visit_lang_cc_Node(lang::cc::Node::Expr::Bin3_T x, function<void(lang::cc::Node_T)> f);

void visit_lang_cc_Node(lang::cc::Node::Expr::Bin4::op::SHL_T x, function<void(lang::cc::Node_T)> f);

void visit_lang_cc_Node(lang::cc::Node::Expr::Bin4::op_T x, function<void(lang::cc::Node_T)> f);

void visit_lang_cc_Node(lang::cc::Node::Expr::Bin4_T x, function<void(lang::cc::Node_T)> f);

void visit_lang_cc_Node(lang::cc::Node::Expr::Bin5::op::PLUS_T x, function<void(lang::cc::Node_T)> f);

void visit_lang_cc_Node(lang::cc::Node::Expr::Bin5::op::MINUS_T x, function<void(lang::cc::Node_T)> f);

void visit_lang_cc_Node(lang::cc::Node::Expr::Bin5::op_T x, function<void(lang::cc::Node_T)> f);

void visit_lang_cc_Node(lang::cc::Node::Expr::Bin5_T x, function<void(lang::cc::Node_T)> f);

void visit_lang_cc_Node(lang::cc::Node::Expr::Bin6::op::TIMES_T x, function<void(lang::cc::Node_T)> f);

void visit_lang_cc_Node(lang::cc::Node::Expr::Bin6::op::DIVIDE_T x, function<void(lang::cc::Node_T)> f);

void visit_lang_cc_Node(lang::cc::Node::Expr::Bin6::op::MODULO_T x, function<void(lang::cc::Node_T)> f);

void visit_lang_cc_Node(lang::cc::Node::Expr::Bin6::op_T x, function<void(lang::cc::Node_T)> f);

void visit_lang_cc_Node(lang::cc::Node::Expr::Bin6_T x, function<void(lang::cc::Node_T)> f);

void visit_lang_cc_Node(lang::cc::Node::Expr::Template_T x, function<void(lang::cc::Node_T)> f);

void visit_lang_cc_Node(lang::cc::Node::Expr::New_T x, function<void(lang::cc::Node_T)> f);

void visit_lang_cc_Node(lang::cc::Node::Expr::Delete_T x, function<void(lang::cc::Node_T)> f);

void visit_lang_cc_Node(lang::cc::Node::Expr::Ellipsis_T x, function<void(lang::cc::Node_T)> f);

void visit_lang_cc_Node(lang::cc::Node::Expr::Tilde_T x, function<void(lang::cc::Node_T)> f);

void visit_lang_cc_Node(lang::cc::Node::Expr::Namespace_T x, function<void(lang::cc::Node_T)> f);

void visit_lang_cc_Node(lang::cc::Node::Expr::Id_T x, function<void(lang::cc::Node_T)> f);

void visit_lang_cc_Node(lang::cc::Node::Expr::Lit::Integer_T x, function<void(lang::cc::Node_T)> f);

void visit_lang_cc_Node(lang::cc::Node::Expr::Lit::Str__T x, function<void(lang::cc::Node_T)> f);

void visit_lang_cc_Node(lang::cc::Node::Expr::Lit::Array_T x, function<void(lang::cc::Node_T)> f);

void visit_lang_cc_Node(lang::cc::Node::Expr::Lit_T x, function<void(lang::cc::Node_T)> f);

void visit_lang_cc_Node(lang::cc::Node::Expr_T x, function<void(lang::cc::Node_T)> f);

void visit_lang_cc_Node(lang::cc::Node::Decl::Struct::tmpl::args::item_T x, function<void(lang::cc::Node_T)> f);

void visit_lang_cc_Node(lang::cc::Node::Decl::Struct::tmpl_T x, function<void(lang::cc::Node_T)> f);

void visit_lang_cc_Node(lang::cc::Node::StructDeclDef::Decl_T x, function<void(lang::cc::Node_T)> f);

void visit_lang_cc_Node(lang::cc::Node::Entry::Field_T x, function<void(lang::cc::Node_T)> f);

void visit_lang_cc_Node(lang::cc::Node::Entry::Fun::tmpl::args::item_T x, function<void(lang::cc::Node_T)> f);

void visit_lang_cc_Node(lang::cc::Node::Entry::Fun::tmpl_T x, function<void(lang::cc::Node_T)> f);

void visit_lang_cc_Node(lang::cc::Node::Mod::Const_T x, function<void(lang::cc::Node_T)> f);

void visit_lang_cc_Node(lang::cc::Node::Mod::Inline_T x, function<void(lang::cc::Node_T)> f);

void visit_lang_cc_Node(lang::cc::Node::Mod::Static_T x, function<void(lang::cc::Node_T)> f);

void visit_lang_cc_Node(lang::cc::Node::Mod::Virtual_T x, function<void(lang::cc::Node_T)> f);

void visit_lang_cc_Node(lang::cc::Node::Mod::NoInline_T x, function<void(lang::cc::Node_T)> f);

void visit_lang_cc_Node(lang::cc::Node::Mod::AlwaysInline_T x, function<void(lang::cc::Node_T)> f);

void visit_lang_cc_Node(lang::cc::Node::Mod_T x, function<void(lang::cc::Node_T)> f);

void visit_lang_cc_Node(lang::cc::Node::Param::val_T x, function<void(lang::cc::Node_T)> f);

void visit_lang_cc_Node(lang::cc::Node::Param_T x, function<void(lang::cc::Node_T)> f);

void visit_lang_cc_Node(lang::cc::Node::FunDeclDef::Decl_T x, function<void(lang::cc::Node_T)> f);

void visit_lang_cc_Node(lang::cc::Node::TypedDecl::vars::item::val_T x, function<void(lang::cc::Node_T)> f);

void visit_lang_cc_Node(lang::cc::Node::TypedDecl::vars::item_T x, function<void(lang::cc::Node_T)> f);

void visit_lang_cc_Node(lang::cc::Node::TypedDecl_T x, function<void(lang::cc::Node_T)> f);

void visit_lang_cc_Node(lang::cc::Node::Stmt::Decl_T x, function<void(lang::cc::Node_T)> f);

void visit_lang_cc_Node(lang::cc::Node::Stmt::Expr_T x, function<void(lang::cc::Node_T)> f);

void visit_lang_cc_Node(lang::cc::Node::Stmt::Block_T x, function<void(lang::cc::Node_T)> f);

void visit_lang_cc_Node(lang::cc::Node::Stmt::If_T x, function<void(lang::cc::Node_T)> f);

void visit_lang_cc_Node(lang::cc::Node::Stmt::IfElse_T x, function<void(lang::cc::Node_T)> f);

void visit_lang_cc_Node(lang::cc::Node::ExprExt::Expr_T x, function<void(lang::cc::Node_T)> f);

void visit_lang_cc_Node(lang::cc::Node::ExprExt::Decl_T x, function<void(lang::cc::Node_T)> f);

void visit_lang_cc_Node(lang::cc::Node::ExprExt_T x, function<void(lang::cc::Node_T)> f);

void visit_lang_cc_Node(lang::cc::Node::Stmt::For_T x, function<void(lang::cc::Node_T)> f);

void visit_lang_cc_Node(lang::cc::Node::SwitchCase::Case_T x, function<void(lang::cc::Node_T)> f);

void visit_lang_cc_Node(lang::cc::Node::SwitchCase::Default_T x, function<void(lang::cc::Node_T)> f);

void visit_lang_cc_Node(lang::cc::Node::SwitchCase_T x, function<void(lang::cc::Node_T)> f);

void visit_lang_cc_Node(lang::cc::Node::Stmt::Switch_T x, function<void(lang::cc::Node_T)> f);

void visit_lang_cc_Node(lang::cc::Node::Stmt::Break_T x, function<void(lang::cc::Node_T)> f);

void visit_lang_cc_Node(lang::cc::Node::Stmt::Continue_T x, function<void(lang::cc::Node_T)> f);

void visit_lang_cc_Node(lang::cc::Node::Stmt::Return_T x, function<void(lang::cc::Node_T)> f);

void visit_lang_cc_Node(lang::cc::Node::Stmt_T x, function<void(lang::cc::Node_T)> f);

void visit_lang_cc_Node(lang::cc::Node::Block_T x, function<void(lang::cc::Node_T)> f);

void visit_lang_cc_Node(lang::cc::Node::FunDeclDef::Def_T x, function<void(lang::cc::Node_T)> f);

void visit_lang_cc_Node(lang::cc::Node::FunDeclDef::Del_T x, function<void(lang::cc::Node_T)> f);

void visit_lang_cc_Node(lang::cc::Node::FunDeclDef::Zero_T x, function<void(lang::cc::Node_T)> f);

void visit_lang_cc_Node(lang::cc::Node::FunDeclDef_T x, function<void(lang::cc::Node_T)> f);

void visit_lang_cc_Node(lang::cc::Node::Entry::Fun_T x, function<void(lang::cc::Node_T)> f);

void visit_lang_cc_Node(lang::cc::Node::Entry_T x, function<void(lang::cc::Node_T)> f);

void visit_lang_cc_Node(lang::cc::Node::StructDeclDef::Def_T x, function<void(lang::cc::Node_T)> f);

void visit_lang_cc_Node(lang::cc::Node::StructDeclDef_T x, function<void(lang::cc::Node_T)> f);

void visit_lang_cc_Node(lang::cc::Node::Decl::Struct_T x, function<void(lang::cc::Node_T)> f);

void visit_lang_cc_Node(lang::cc::Node::Decl::EnumStruct_T x, function<void(lang::cc::Node_T)> f);

void visit_lang_cc_Node(lang::cc::Node::Decl::Fun::tmpl::args::item_T x, function<void(lang::cc::Node_T)> f);

void visit_lang_cc_Node(lang::cc::Node::Decl::Fun::tmpl_T x, function<void(lang::cc::Node_T)> f);

void visit_lang_cc_Node(lang::cc::Node::Decl::Fun_T x, function<void(lang::cc::Node_T)> f);

void visit_lang_cc_Node(lang::cc::Node::Decl::Namespace_T x, function<void(lang::cc::Node_T)> f);

void visit_lang_cc_Node(lang::cc::Node::Decl::UsingAlias::tmpl::args::item_T x, function<void(lang::cc::Node_T)> f);

void visit_lang_cc_Node(lang::cc::Node::Decl::UsingAlias::tmpl_T x, function<void(lang::cc::Node_T)> f);

void visit_lang_cc_Node(lang::cc::Node::Decl::UsingAlias_T x, function<void(lang::cc::Node_T)> f);

void visit_lang_cc_Node(lang::cc::Node::Decl::UsingNamespace_T x, function<void(lang::cc::Node_T)> f);

void visit_lang_cc_Node(lang::cc::Node::Decl::Include_T x, function<void(lang::cc::Node_T)> f);

void visit_lang_cc_Node(lang::cc::Node::Decl::PragmaOnce_T x, function<void(lang::cc::Node_T)> f);

void visit_lang_cc_Node(lang::cc::Node::Decl_T x, function<void(lang::cc::Node_T)> f);

void visit_lang_cc_Node(lang::cc::Node::Module_T x, function<void(lang::cc::Node_T)> f);

void visit_lang_cc_Node(lang::cc::Node_T x, function<void(lang::cc::Node_T)> f);

lang::cc::Node_T xformT_lang_cc_Node(lang::cc::Node::Expr::Paren_T x, function<lang::cc::Node_T(lang::cc::Node_T)> f);

lang::cc::Node_T xformT_lang_cc_Node(lang::cc::Node::Expr::Call_T x, function<lang::cc::Node_T(lang::cc::Node_T)> f);

lang::cc::Node_T xformT_lang_cc_Node(lang::cc::Node::Expr::Index_T x, function<lang::cc::Node_T(lang::cc::Node_T)> f);

lang::cc::Node_T xformT_lang_cc_Node(lang::cc::Node::Expr::IndexEmpty_T x, function<lang::cc::Node_T(lang::cc::Node_T)> f);

lang::cc::Node_T xformT_lang_cc_Node(lang::cc::Node::Expr::Dot_T x, function<lang::cc::Node_T(lang::cc::Node_T)> f);

lang::cc::Node_T xformT_lang_cc_Node(lang::cc::Node::Expr::Arrow_T x, function<lang::cc::Node_T(lang::cc::Node_T)> f);

lang::cc::Node_T xformT_lang_cc_Node(lang::cc::Node::Expr::Ref__T x, function<lang::cc::Node_T(lang::cc::Node_T)> f);

lang::cc::Node_T xformT_lang_cc_Node(lang::cc::Node::Expr::AddrOf_T x, function<lang::cc::Node_T(lang::cc::Node_T)> f);

lang::cc::Node_T xformT_lang_cc_Node(lang::cc::Node::Expr::Deref_T x, function<lang::cc::Node_T(lang::cc::Node_T)> f);

lang::cc::Node_T xformT_lang_cc_Node(lang::cc::Node::Expr::UnaryPre::op::NOT_T x, function<lang::cc::Node_T(lang::cc::Node_T)> f);

lang::cc::Node_T xformT_lang_cc_Node(lang::cc::Node::Expr::UnaryPre::op::NEG_T x, function<lang::cc::Node_T(lang::cc::Node_T)> f);

lang::cc::Node_T xformT_lang_cc_Node(lang::cc::Node::Expr::UnaryPre::op_T x, function<lang::cc::Node_T(lang::cc::Node_T)> f);

lang::cc::Node_T xformT_lang_cc_Node(lang::cc::Node::Expr::UnaryPre_T x, function<lang::cc::Node_T(lang::cc::Node_T)> f);

lang::cc::Node_T xformT_lang_cc_Node(lang::cc::Node::Expr::IncDecPre::op::INC_T x, function<lang::cc::Node_T(lang::cc::Node_T)> f);

lang::cc::Node_T xformT_lang_cc_Node(lang::cc::Node::Expr::IncDecPre::op::DEC_T x, function<lang::cc::Node_T(lang::cc::Node_T)> f);

lang::cc::Node_T xformT_lang_cc_Node(lang::cc::Node::Expr::IncDecPre::op_T x, function<lang::cc::Node_T(lang::cc::Node_T)> f);

lang::cc::Node_T xformT_lang_cc_Node(lang::cc::Node::Expr::IncDecPre_T x, function<lang::cc::Node_T(lang::cc::Node_T)> f);

lang::cc::Node_T xformT_lang_cc_Node(lang::cc::Node::Expr::IncDecPost::op::INC_T x, function<lang::cc::Node_T(lang::cc::Node_T)> f);

lang::cc::Node_T xformT_lang_cc_Node(lang::cc::Node::Expr::IncDecPost::op::DEC_T x, function<lang::cc::Node_T(lang::cc::Node_T)> f);

lang::cc::Node_T xformT_lang_cc_Node(lang::cc::Node::Expr::IncDecPost::op_T x, function<lang::cc::Node_T(lang::cc::Node_T)> f);

lang::cc::Node_T xformT_lang_cc_Node(lang::cc::Node::Expr::IncDecPost_T x, function<lang::cc::Node_T(lang::cc::Node_T)> f);

lang::cc::Node_T xformT_lang_cc_Node(lang::cc::Node::Expr::Assign_T x, function<lang::cc::Node_T(lang::cc::Node_T)> f);

lang::cc::Node_T xformT_lang_cc_Node(lang::cc::Node::Expr::Bin1::op::LOR_T x, function<lang::cc::Node_T(lang::cc::Node_T)> f);

lang::cc::Node_T xformT_lang_cc_Node(lang::cc::Node::Expr::Bin1::op_T x, function<lang::cc::Node_T(lang::cc::Node_T)> f);

lang::cc::Node_T xformT_lang_cc_Node(lang::cc::Node::Expr::Bin1_T x, function<lang::cc::Node_T(lang::cc::Node_T)> f);

lang::cc::Node_T xformT_lang_cc_Node(lang::cc::Node::Expr::Bin2::op::LAND_T x, function<lang::cc::Node_T(lang::cc::Node_T)> f);

lang::cc::Node_T xformT_lang_cc_Node(lang::cc::Node::Expr::Bin2::op_T x, function<lang::cc::Node_T(lang::cc::Node_T)> f);

lang::cc::Node_T xformT_lang_cc_Node(lang::cc::Node::Expr::Bin2_T x, function<lang::cc::Node_T(lang::cc::Node_T)> f);

lang::cc::Node_T xformT_lang_cc_Node(lang::cc::Node::Expr::Bin3::op::EQ_T x, function<lang::cc::Node_T(lang::cc::Node_T)> f);

lang::cc::Node_T xformT_lang_cc_Node(lang::cc::Node::Expr::Bin3::op::NE_T x, function<lang::cc::Node_T(lang::cc::Node_T)> f);

lang::cc::Node_T xformT_lang_cc_Node(lang::cc::Node::Expr::Bin3::op::LE_T x, function<lang::cc::Node_T(lang::cc::Node_T)> f);

lang::cc::Node_T xformT_lang_cc_Node(lang::cc::Node::Expr::Bin3::op::GE_T x, function<lang::cc::Node_T(lang::cc::Node_T)> f);

lang::cc::Node_T xformT_lang_cc_Node(lang::cc::Node::Expr::Bin3::op::LT_T x, function<lang::cc::Node_T(lang::cc::Node_T)> f);

lang::cc::Node_T xformT_lang_cc_Node(lang::cc::Node::Expr::Bin3::op::GT_T x, function<lang::cc::Node_T(lang::cc::Node_T)> f);

lang::cc::Node_T xformT_lang_cc_Node(lang::cc::Node::Expr::Bin3::op_T x, function<lang::cc::Node_T(lang::cc::Node_T)> f);

lang::cc::Node_T xformT_lang_cc_Node(lang::cc::Node::Expr::Bin3_T x, function<lang::cc::Node_T(lang::cc::Node_T)> f);

lang::cc::Node_T xformT_lang_cc_Node(lang::cc::Node::Expr::Bin4::op::SHL_T x, function<lang::cc::Node_T(lang::cc::Node_T)> f);

lang::cc::Node_T xformT_lang_cc_Node(lang::cc::Node::Expr::Bin4::op_T x, function<lang::cc::Node_T(lang::cc::Node_T)> f);

lang::cc::Node_T xformT_lang_cc_Node(lang::cc::Node::Expr::Bin4_T x, function<lang::cc::Node_T(lang::cc::Node_T)> f);

lang::cc::Node_T xformT_lang_cc_Node(lang::cc::Node::Expr::Bin5::op::PLUS_T x, function<lang::cc::Node_T(lang::cc::Node_T)> f);

lang::cc::Node_T xformT_lang_cc_Node(lang::cc::Node::Expr::Bin5::op::MINUS_T x, function<lang::cc::Node_T(lang::cc::Node_T)> f);

lang::cc::Node_T xformT_lang_cc_Node(lang::cc::Node::Expr::Bin5::op_T x, function<lang::cc::Node_T(lang::cc::Node_T)> f);

lang::cc::Node_T xformT_lang_cc_Node(lang::cc::Node::Expr::Bin5_T x, function<lang::cc::Node_T(lang::cc::Node_T)> f);

lang::cc::Node_T xformT_lang_cc_Node(lang::cc::Node::Expr::Bin6::op::TIMES_T x, function<lang::cc::Node_T(lang::cc::Node_T)> f);

lang::cc::Node_T xformT_lang_cc_Node(lang::cc::Node::Expr::Bin6::op::DIVIDE_T x, function<lang::cc::Node_T(lang::cc::Node_T)> f);

lang::cc::Node_T xformT_lang_cc_Node(lang::cc::Node::Expr::Bin6::op::MODULO_T x, function<lang::cc::Node_T(lang::cc::Node_T)> f);

lang::cc::Node_T xformT_lang_cc_Node(lang::cc::Node::Expr::Bin6::op_T x, function<lang::cc::Node_T(lang::cc::Node_T)> f);

lang::cc::Node_T xformT_lang_cc_Node(lang::cc::Node::Expr::Bin6_T x, function<lang::cc::Node_T(lang::cc::Node_T)> f);

lang::cc::Node_T xformT_lang_cc_Node(lang::cc::Node::Expr::Template_T x, function<lang::cc::Node_T(lang::cc::Node_T)> f);

lang::cc::Node_T xformT_lang_cc_Node(lang::cc::Node::Expr::New_T x, function<lang::cc::Node_T(lang::cc::Node_T)> f);

lang::cc::Node_T xformT_lang_cc_Node(lang::cc::Node::Expr::Delete_T x, function<lang::cc::Node_T(lang::cc::Node_T)> f);

lang::cc::Node_T xformT_lang_cc_Node(lang::cc::Node::Expr::Ellipsis_T x, function<lang::cc::Node_T(lang::cc::Node_T)> f);

lang::cc::Node_T xformT_lang_cc_Node(lang::cc::Node::Expr::Tilde_T x, function<lang::cc::Node_T(lang::cc::Node_T)> f);

lang::cc::Node_T xformT_lang_cc_Node(lang::cc::Node::Expr::Namespace_T x, function<lang::cc::Node_T(lang::cc::Node_T)> f);

lang::cc::Node_T xformT_lang_cc_Node(lang::cc::Node::Expr::Id_T x, function<lang::cc::Node_T(lang::cc::Node_T)> f);

lang::cc::Node_T xformT_lang_cc_Node(lang::cc::Node::Expr::Lit::Integer_T x, function<lang::cc::Node_T(lang::cc::Node_T)> f);

lang::cc::Node_T xformT_lang_cc_Node(lang::cc::Node::Expr::Lit::Str__T x, function<lang::cc::Node_T(lang::cc::Node_T)> f);

lang::cc::Node_T xformT_lang_cc_Node(lang::cc::Node::Expr::Lit::Array_T x, function<lang::cc::Node_T(lang::cc::Node_T)> f);

lang::cc::Node_T xformT_lang_cc_Node(lang::cc::Node::Expr::Lit_T x, function<lang::cc::Node_T(lang::cc::Node_T)> f);

lang::cc::Node_T xformT_lang_cc_Node(lang::cc::Node::Expr_T x, function<lang::cc::Node_T(lang::cc::Node_T)> f);

lang::cc::Node_T xformT_lang_cc_Node(lang::cc::Node::Decl::Struct::tmpl::args::item_T x, function<lang::cc::Node_T(lang::cc::Node_T)> f);

lang::cc::Node_T xformT_lang_cc_Node(lang::cc::Node::Decl::Struct::tmpl_T x, function<lang::cc::Node_T(lang::cc::Node_T)> f);

lang::cc::Node_T xformT_lang_cc_Node(lang::cc::Node::StructDeclDef::Decl_T x, function<lang::cc::Node_T(lang::cc::Node_T)> f);

lang::cc::Node_T xformT_lang_cc_Node(lang::cc::Node::Entry::Field_T x, function<lang::cc::Node_T(lang::cc::Node_T)> f);

lang::cc::Node_T xformT_lang_cc_Node(lang::cc::Node::Entry::Fun::tmpl::args::item_T x, function<lang::cc::Node_T(lang::cc::Node_T)> f);

lang::cc::Node_T xformT_lang_cc_Node(lang::cc::Node::Entry::Fun::tmpl_T x, function<lang::cc::Node_T(lang::cc::Node_T)> f);

lang::cc::Node_T xformT_lang_cc_Node(lang::cc::Node::Mod::Const_T x, function<lang::cc::Node_T(lang::cc::Node_T)> f);

lang::cc::Node_T xformT_lang_cc_Node(lang::cc::Node::Mod::Inline_T x, function<lang::cc::Node_T(lang::cc::Node_T)> f);

lang::cc::Node_T xformT_lang_cc_Node(lang::cc::Node::Mod::Static_T x, function<lang::cc::Node_T(lang::cc::Node_T)> f);

lang::cc::Node_T xformT_lang_cc_Node(lang::cc::Node::Mod::Virtual_T x, function<lang::cc::Node_T(lang::cc::Node_T)> f);

lang::cc::Node_T xformT_lang_cc_Node(lang::cc::Node::Mod::NoInline_T x, function<lang::cc::Node_T(lang::cc::Node_T)> f);

lang::cc::Node_T xformT_lang_cc_Node(lang::cc::Node::Mod::AlwaysInline_T x, function<lang::cc::Node_T(lang::cc::Node_T)> f);

lang::cc::Node_T xformT_lang_cc_Node(lang::cc::Node::Mod_T x, function<lang::cc::Node_T(lang::cc::Node_T)> f);

lang::cc::Node_T xformT_lang_cc_Node(lang::cc::Node::Param::val_T x, function<lang::cc::Node_T(lang::cc::Node_T)> f);

lang::cc::Node_T xformT_lang_cc_Node(lang::cc::Node::Param_T x, function<lang::cc::Node_T(lang::cc::Node_T)> f);

lang::cc::Node_T xformT_lang_cc_Node(lang::cc::Node::FunDeclDef::Decl_T x, function<lang::cc::Node_T(lang::cc::Node_T)> f);

lang::cc::Node_T xformT_lang_cc_Node(lang::cc::Node::TypedDecl::vars::item::val_T x, function<lang::cc::Node_T(lang::cc::Node_T)> f);

lang::cc::Node_T xformT_lang_cc_Node(lang::cc::Node::TypedDecl::vars::item_T x, function<lang::cc::Node_T(lang::cc::Node_T)> f);

lang::cc::Node_T xformT_lang_cc_Node(lang::cc::Node::TypedDecl_T x, function<lang::cc::Node_T(lang::cc::Node_T)> f);

lang::cc::Node_T xformT_lang_cc_Node(lang::cc::Node::Stmt::Decl_T x, function<lang::cc::Node_T(lang::cc::Node_T)> f);

lang::cc::Node_T xformT_lang_cc_Node(lang::cc::Node::Stmt::Expr_T x, function<lang::cc::Node_T(lang::cc::Node_T)> f);

lang::cc::Node_T xformT_lang_cc_Node(lang::cc::Node::Stmt::Block_T x, function<lang::cc::Node_T(lang::cc::Node_T)> f);

lang::cc::Node_T xformT_lang_cc_Node(lang::cc::Node::Stmt::If_T x, function<lang::cc::Node_T(lang::cc::Node_T)> f);

lang::cc::Node_T xformT_lang_cc_Node(lang::cc::Node::Stmt::IfElse_T x, function<lang::cc::Node_T(lang::cc::Node_T)> f);

lang::cc::Node_T xformT_lang_cc_Node(lang::cc::Node::ExprExt::Expr_T x, function<lang::cc::Node_T(lang::cc::Node_T)> f);

lang::cc::Node_T xformT_lang_cc_Node(lang::cc::Node::ExprExt::Decl_T x, function<lang::cc::Node_T(lang::cc::Node_T)> f);

lang::cc::Node_T xformT_lang_cc_Node(lang::cc::Node::ExprExt_T x, function<lang::cc::Node_T(lang::cc::Node_T)> f);

lang::cc::Node_T xformT_lang_cc_Node(lang::cc::Node::Stmt::For_T x, function<lang::cc::Node_T(lang::cc::Node_T)> f);

lang::cc::Node_T xformT_lang_cc_Node(lang::cc::Node::SwitchCase::Case_T x, function<lang::cc::Node_T(lang::cc::Node_T)> f);

lang::cc::Node_T xformT_lang_cc_Node(lang::cc::Node::SwitchCase::Default_T x, function<lang::cc::Node_T(lang::cc::Node_T)> f);

lang::cc::Node_T xformT_lang_cc_Node(lang::cc::Node::SwitchCase_T x, function<lang::cc::Node_T(lang::cc::Node_T)> f);

lang::cc::Node_T xformT_lang_cc_Node(lang::cc::Node::Stmt::Switch_T x, function<lang::cc::Node_T(lang::cc::Node_T)> f);

lang::cc::Node_T xformT_lang_cc_Node(lang::cc::Node::Stmt::Break_T x, function<lang::cc::Node_T(lang::cc::Node_T)> f);

lang::cc::Node_T xformT_lang_cc_Node(lang::cc::Node::Stmt::Continue_T x, function<lang::cc::Node_T(lang::cc::Node_T)> f);

lang::cc::Node_T xformT_lang_cc_Node(lang::cc::Node::Stmt::Return_T x, function<lang::cc::Node_T(lang::cc::Node_T)> f);

lang::cc::Node_T xformT_lang_cc_Node(lang::cc::Node::Stmt_T x, function<lang::cc::Node_T(lang::cc::Node_T)> f);

lang::cc::Node_T xformT_lang_cc_Node(lang::cc::Node::Block_T x, function<lang::cc::Node_T(lang::cc::Node_T)> f);

lang::cc::Node_T xformT_lang_cc_Node(lang::cc::Node::FunDeclDef::Def_T x, function<lang::cc::Node_T(lang::cc::Node_T)> f);

lang::cc::Node_T xformT_lang_cc_Node(lang::cc::Node::FunDeclDef::Del_T x, function<lang::cc::Node_T(lang::cc::Node_T)> f);

lang::cc::Node_T xformT_lang_cc_Node(lang::cc::Node::FunDeclDef::Zero_T x, function<lang::cc::Node_T(lang::cc::Node_T)> f);

lang::cc::Node_T xformT_lang_cc_Node(lang::cc::Node::FunDeclDef_T x, function<lang::cc::Node_T(lang::cc::Node_T)> f);

lang::cc::Node_T xformT_lang_cc_Node(lang::cc::Node::Entry::Fun_T x, function<lang::cc::Node_T(lang::cc::Node_T)> f);

lang::cc::Node_T xformT_lang_cc_Node(lang::cc::Node::Entry_T x, function<lang::cc::Node_T(lang::cc::Node_T)> f);

lang::cc::Node_T xformT_lang_cc_Node(lang::cc::Node::StructDeclDef::Def_T x, function<lang::cc::Node_T(lang::cc::Node_T)> f);

lang::cc::Node_T xformT_lang_cc_Node(lang::cc::Node::StructDeclDef_T x, function<lang::cc::Node_T(lang::cc::Node_T)> f);

lang::cc::Node_T xformT_lang_cc_Node(lang::cc::Node::Decl::Struct_T x, function<lang::cc::Node_T(lang::cc::Node_T)> f);

lang::cc::Node_T xformT_lang_cc_Node(lang::cc::Node::Decl::EnumStruct_T x, function<lang::cc::Node_T(lang::cc::Node_T)> f);

lang::cc::Node_T xformT_lang_cc_Node(lang::cc::Node::Decl::Fun::tmpl::args::item_T x, function<lang::cc::Node_T(lang::cc::Node_T)> f);

lang::cc::Node_T xformT_lang_cc_Node(lang::cc::Node::Decl::Fun::tmpl_T x, function<lang::cc::Node_T(lang::cc::Node_T)> f);

lang::cc::Node_T xformT_lang_cc_Node(lang::cc::Node::Decl::Fun_T x, function<lang::cc::Node_T(lang::cc::Node_T)> f);

lang::cc::Node_T xformT_lang_cc_Node(lang::cc::Node::Decl::Namespace_T x, function<lang::cc::Node_T(lang::cc::Node_T)> f);

lang::cc::Node_T xformT_lang_cc_Node(lang::cc::Node::Decl::UsingAlias::tmpl::args::item_T x, function<lang::cc::Node_T(lang::cc::Node_T)> f);

lang::cc::Node_T xformT_lang_cc_Node(lang::cc::Node::Decl::UsingAlias::tmpl_T x, function<lang::cc::Node_T(lang::cc::Node_T)> f);

lang::cc::Node_T xformT_lang_cc_Node(lang::cc::Node::Decl::UsingAlias_T x, function<lang::cc::Node_T(lang::cc::Node_T)> f);

lang::cc::Node_T xformT_lang_cc_Node(lang::cc::Node::Decl::UsingNamespace_T x, function<lang::cc::Node_T(lang::cc::Node_T)> f);

lang::cc::Node_T xformT_lang_cc_Node(lang::cc::Node::Decl::Include_T x, function<lang::cc::Node_T(lang::cc::Node_T)> f);

lang::cc::Node_T xformT_lang_cc_Node(lang::cc::Node::Decl::PragmaOnce_T x, function<lang::cc::Node_T(lang::cc::Node_T)> f);

lang::cc::Node_T xformT_lang_cc_Node(lang::cc::Node::Decl_T x, function<lang::cc::Node_T(lang::cc::Node_T)> f);

lang::cc::Node_T xformT_lang_cc_Node(lang::cc::Node::Module_T x, function<lang::cc::Node_T(lang::cc::Node_T)> f);

lang::cc::Node_T xformT_lang_cc_Node(lang::cc::Node_T x, function<lang::cc::Node_T(lang::cc::Node_T)> f);

lang::cc::Node_T xform_lang_cc_Node(lang::cc::Node_T x, function<lang::cc::Node_T(lang::cc::Node_T)> f);

lang::cc::Node::Module_T xform_lang_cc_Node(lang::cc::Node::Module_T x, function<lang::cc::Node_T(lang::cc::Node_T)> f);

lang::cc::Node::Decl_T xform_lang_cc_Node(lang::cc::Node::Decl_T x, function<lang::cc::Node_T(lang::cc::Node_T)> f);

lang::cc::Node::Decl::Struct_T xform_lang_cc_Node(lang::cc::Node::Decl::Struct_T x, function<lang::cc::Node_T(lang::cc::Node_T)> f);

lang::cc::Node::Decl::Struct::tmpl_T xform_lang_cc_Node(lang::cc::Node::Decl::Struct::tmpl_T x, function<lang::cc::Node_T(lang::cc::Node_T)> f);

lang::cc::Node::Decl::Struct::tmpl::args::item_T xform_lang_cc_Node(lang::cc::Node::Decl::Struct::tmpl::args::item_T x, function<lang::cc::Node_T(lang::cc::Node_T)> f);

lang::cc::Node::Expr_T xform_lang_cc_Node(lang::cc::Node::Expr_T x, function<lang::cc::Node_T(lang::cc::Node_T)> f);

lang::cc::Node::Expr::Paren_T xform_lang_cc_Node(lang::cc::Node::Expr::Paren_T x, function<lang::cc::Node_T(lang::cc::Node_T)> f);

lang::cc::Node::Expr::Call_T xform_lang_cc_Node(lang::cc::Node::Expr::Call_T x, function<lang::cc::Node_T(lang::cc::Node_T)> f);

lang::cc::Node::Expr::Index_T xform_lang_cc_Node(lang::cc::Node::Expr::Index_T x, function<lang::cc::Node_T(lang::cc::Node_T)> f);

lang::cc::Node::Expr::IndexEmpty_T xform_lang_cc_Node(lang::cc::Node::Expr::IndexEmpty_T x, function<lang::cc::Node_T(lang::cc::Node_T)> f);

lang::cc::Node::Expr::Dot_T xform_lang_cc_Node(lang::cc::Node::Expr::Dot_T x, function<lang::cc::Node_T(lang::cc::Node_T)> f);

lang::cc::Node::Expr::Arrow_T xform_lang_cc_Node(lang::cc::Node::Expr::Arrow_T x, function<lang::cc::Node_T(lang::cc::Node_T)> f);

lang::cc::Node::Expr::Ref__T xform_lang_cc_Node(lang::cc::Node::Expr::Ref__T x, function<lang::cc::Node_T(lang::cc::Node_T)> f);

lang::cc::Node::Expr::AddrOf_T xform_lang_cc_Node(lang::cc::Node::Expr::AddrOf_T x, function<lang::cc::Node_T(lang::cc::Node_T)> f);

lang::cc::Node::Expr::Deref_T xform_lang_cc_Node(lang::cc::Node::Expr::Deref_T x, function<lang::cc::Node_T(lang::cc::Node_T)> f);

lang::cc::Node::Expr::UnaryPre_T xform_lang_cc_Node(lang::cc::Node::Expr::UnaryPre_T x, function<lang::cc::Node_T(lang::cc::Node_T)> f);

lang::cc::Node::Expr::UnaryPre::op_T xform_lang_cc_Node(lang::cc::Node::Expr::UnaryPre::op_T x, function<lang::cc::Node_T(lang::cc::Node_T)> f);

lang::cc::Node::Expr::UnaryPre::op::NOT_T xform_lang_cc_Node(lang::cc::Node::Expr::UnaryPre::op::NOT_T x, function<lang::cc::Node_T(lang::cc::Node_T)> f);

lang::cc::Node::Expr::UnaryPre::op::NEG_T xform_lang_cc_Node(lang::cc::Node::Expr::UnaryPre::op::NEG_T x, function<lang::cc::Node_T(lang::cc::Node_T)> f);

lang::cc::Node::Expr::IncDecPre_T xform_lang_cc_Node(lang::cc::Node::Expr::IncDecPre_T x, function<lang::cc::Node_T(lang::cc::Node_T)> f);

lang::cc::Node::Expr::IncDecPre::op_T xform_lang_cc_Node(lang::cc::Node::Expr::IncDecPre::op_T x, function<lang::cc::Node_T(lang::cc::Node_T)> f);

lang::cc::Node::Expr::IncDecPre::op::INC_T xform_lang_cc_Node(lang::cc::Node::Expr::IncDecPre::op::INC_T x, function<lang::cc::Node_T(lang::cc::Node_T)> f);

lang::cc::Node::Expr::IncDecPre::op::DEC_T xform_lang_cc_Node(lang::cc::Node::Expr::IncDecPre::op::DEC_T x, function<lang::cc::Node_T(lang::cc::Node_T)> f);

lang::cc::Node::Expr::IncDecPost_T xform_lang_cc_Node(lang::cc::Node::Expr::IncDecPost_T x, function<lang::cc::Node_T(lang::cc::Node_T)> f);

lang::cc::Node::Expr::IncDecPost::op_T xform_lang_cc_Node(lang::cc::Node::Expr::IncDecPost::op_T x, function<lang::cc::Node_T(lang::cc::Node_T)> f);

lang::cc::Node::Expr::IncDecPost::op::INC_T xform_lang_cc_Node(lang::cc::Node::Expr::IncDecPost::op::INC_T x, function<lang::cc::Node_T(lang::cc::Node_T)> f);

lang::cc::Node::Expr::IncDecPost::op::DEC_T xform_lang_cc_Node(lang::cc::Node::Expr::IncDecPost::op::DEC_T x, function<lang::cc::Node_T(lang::cc::Node_T)> f);

lang::cc::Node::Expr::Assign_T xform_lang_cc_Node(lang::cc::Node::Expr::Assign_T x, function<lang::cc::Node_T(lang::cc::Node_T)> f);

lang::cc::Node::Expr::Bin1_T xform_lang_cc_Node(lang::cc::Node::Expr::Bin1_T x, function<lang::cc::Node_T(lang::cc::Node_T)> f);

lang::cc::Node::Expr::Bin1::op_T xform_lang_cc_Node(lang::cc::Node::Expr::Bin1::op_T x, function<lang::cc::Node_T(lang::cc::Node_T)> f);

lang::cc::Node::Expr::Bin1::op::LOR_T xform_lang_cc_Node(lang::cc::Node::Expr::Bin1::op::LOR_T x, function<lang::cc::Node_T(lang::cc::Node_T)> f);

lang::cc::Node::Expr::Bin2_T xform_lang_cc_Node(lang::cc::Node::Expr::Bin2_T x, function<lang::cc::Node_T(lang::cc::Node_T)> f);

lang::cc::Node::Expr::Bin2::op_T xform_lang_cc_Node(lang::cc::Node::Expr::Bin2::op_T x, function<lang::cc::Node_T(lang::cc::Node_T)> f);

lang::cc::Node::Expr::Bin2::op::LAND_T xform_lang_cc_Node(lang::cc::Node::Expr::Bin2::op::LAND_T x, function<lang::cc::Node_T(lang::cc::Node_T)> f);

lang::cc::Node::Expr::Bin3_T xform_lang_cc_Node(lang::cc::Node::Expr::Bin3_T x, function<lang::cc::Node_T(lang::cc::Node_T)> f);

lang::cc::Node::Expr::Bin3::op_T xform_lang_cc_Node(lang::cc::Node::Expr::Bin3::op_T x, function<lang::cc::Node_T(lang::cc::Node_T)> f);

lang::cc::Node::Expr::Bin3::op::EQ_T xform_lang_cc_Node(lang::cc::Node::Expr::Bin3::op::EQ_T x, function<lang::cc::Node_T(lang::cc::Node_T)> f);

lang::cc::Node::Expr::Bin3::op::NE_T xform_lang_cc_Node(lang::cc::Node::Expr::Bin3::op::NE_T x, function<lang::cc::Node_T(lang::cc::Node_T)> f);

lang::cc::Node::Expr::Bin3::op::LE_T xform_lang_cc_Node(lang::cc::Node::Expr::Bin3::op::LE_T x, function<lang::cc::Node_T(lang::cc::Node_T)> f);

lang::cc::Node::Expr::Bin3::op::GE_T xform_lang_cc_Node(lang::cc::Node::Expr::Bin3::op::GE_T x, function<lang::cc::Node_T(lang::cc::Node_T)> f);

lang::cc::Node::Expr::Bin3::op::LT_T xform_lang_cc_Node(lang::cc::Node::Expr::Bin3::op::LT_T x, function<lang::cc::Node_T(lang::cc::Node_T)> f);

lang::cc::Node::Expr::Bin3::op::GT_T xform_lang_cc_Node(lang::cc::Node::Expr::Bin3::op::GT_T x, function<lang::cc::Node_T(lang::cc::Node_T)> f);

lang::cc::Node::Expr::Bin4_T xform_lang_cc_Node(lang::cc::Node::Expr::Bin4_T x, function<lang::cc::Node_T(lang::cc::Node_T)> f);

lang::cc::Node::Expr::Bin4::op_T xform_lang_cc_Node(lang::cc::Node::Expr::Bin4::op_T x, function<lang::cc::Node_T(lang::cc::Node_T)> f);

lang::cc::Node::Expr::Bin4::op::SHL_T xform_lang_cc_Node(lang::cc::Node::Expr::Bin4::op::SHL_T x, function<lang::cc::Node_T(lang::cc::Node_T)> f);

lang::cc::Node::Expr::Bin5_T xform_lang_cc_Node(lang::cc::Node::Expr::Bin5_T x, function<lang::cc::Node_T(lang::cc::Node_T)> f);

lang::cc::Node::Expr::Bin5::op_T xform_lang_cc_Node(lang::cc::Node::Expr::Bin5::op_T x, function<lang::cc::Node_T(lang::cc::Node_T)> f);

lang::cc::Node::Expr::Bin5::op::PLUS_T xform_lang_cc_Node(lang::cc::Node::Expr::Bin5::op::PLUS_T x, function<lang::cc::Node_T(lang::cc::Node_T)> f);

lang::cc::Node::Expr::Bin5::op::MINUS_T xform_lang_cc_Node(lang::cc::Node::Expr::Bin5::op::MINUS_T x, function<lang::cc::Node_T(lang::cc::Node_T)> f);

lang::cc::Node::Expr::Bin6_T xform_lang_cc_Node(lang::cc::Node::Expr::Bin6_T x, function<lang::cc::Node_T(lang::cc::Node_T)> f);

lang::cc::Node::Expr::Bin6::op_T xform_lang_cc_Node(lang::cc::Node::Expr::Bin6::op_T x, function<lang::cc::Node_T(lang::cc::Node_T)> f);

lang::cc::Node::Expr::Bin6::op::TIMES_T xform_lang_cc_Node(lang::cc::Node::Expr::Bin6::op::TIMES_T x, function<lang::cc::Node_T(lang::cc::Node_T)> f);

lang::cc::Node::Expr::Bin6::op::DIVIDE_T xform_lang_cc_Node(lang::cc::Node::Expr::Bin6::op::DIVIDE_T x, function<lang::cc::Node_T(lang::cc::Node_T)> f);

lang::cc::Node::Expr::Bin6::op::MODULO_T xform_lang_cc_Node(lang::cc::Node::Expr::Bin6::op::MODULO_T x, function<lang::cc::Node_T(lang::cc::Node_T)> f);

lang::cc::Node::Expr::Template_T xform_lang_cc_Node(lang::cc::Node::Expr::Template_T x, function<lang::cc::Node_T(lang::cc::Node_T)> f);

lang::cc::Node::Expr::New_T xform_lang_cc_Node(lang::cc::Node::Expr::New_T x, function<lang::cc::Node_T(lang::cc::Node_T)> f);

lang::cc::Node::Expr::Delete_T xform_lang_cc_Node(lang::cc::Node::Expr::Delete_T x, function<lang::cc::Node_T(lang::cc::Node_T)> f);

lang::cc::Node::Expr::Ellipsis_T xform_lang_cc_Node(lang::cc::Node::Expr::Ellipsis_T x, function<lang::cc::Node_T(lang::cc::Node_T)> f);

lang::cc::Node::Expr::Tilde_T xform_lang_cc_Node(lang::cc::Node::Expr::Tilde_T x, function<lang::cc::Node_T(lang::cc::Node_T)> f);

lang::cc::Node::Expr::Namespace_T xform_lang_cc_Node(lang::cc::Node::Expr::Namespace_T x, function<lang::cc::Node_T(lang::cc::Node_T)> f);

lang::cc::Node::Expr::Id_T xform_lang_cc_Node(lang::cc::Node::Expr::Id_T x, function<lang::cc::Node_T(lang::cc::Node_T)> f);

lang::cc::Node::Expr::Lit_T xform_lang_cc_Node(lang::cc::Node::Expr::Lit_T x, function<lang::cc::Node_T(lang::cc::Node_T)> f);

lang::cc::Node::Expr::Lit::Integer_T xform_lang_cc_Node(lang::cc::Node::Expr::Lit::Integer_T x, function<lang::cc::Node_T(lang::cc::Node_T)> f);

lang::cc::Node::Expr::Lit::Str__T xform_lang_cc_Node(lang::cc::Node::Expr::Lit::Str__T x, function<lang::cc::Node_T(lang::cc::Node_T)> f);

lang::cc::Node::Expr::Lit::Array_T xform_lang_cc_Node(lang::cc::Node::Expr::Lit::Array_T x, function<lang::cc::Node_T(lang::cc::Node_T)> f);

lang::cc::Node::StructDeclDef_T xform_lang_cc_Node(lang::cc::Node::StructDeclDef_T x, function<lang::cc::Node_T(lang::cc::Node_T)> f);

lang::cc::Node::StructDeclDef::Decl_T xform_lang_cc_Node(lang::cc::Node::StructDeclDef::Decl_T x, function<lang::cc::Node_T(lang::cc::Node_T)> f);

lang::cc::Node::StructDeclDef::Def_T xform_lang_cc_Node(lang::cc::Node::StructDeclDef::Def_T x, function<lang::cc::Node_T(lang::cc::Node_T)> f);

lang::cc::Node::Entry_T xform_lang_cc_Node(lang::cc::Node::Entry_T x, function<lang::cc::Node_T(lang::cc::Node_T)> f);

lang::cc::Node::Entry::Field_T xform_lang_cc_Node(lang::cc::Node::Entry::Field_T x, function<lang::cc::Node_T(lang::cc::Node_T)> f);

lang::cc::Node::Entry::Fun_T xform_lang_cc_Node(lang::cc::Node::Entry::Fun_T x, function<lang::cc::Node_T(lang::cc::Node_T)> f);

lang::cc::Node::Entry::Fun::tmpl_T xform_lang_cc_Node(lang::cc::Node::Entry::Fun::tmpl_T x, function<lang::cc::Node_T(lang::cc::Node_T)> f);

lang::cc::Node::Entry::Fun::tmpl::args::item_T xform_lang_cc_Node(lang::cc::Node::Entry::Fun::tmpl::args::item_T x, function<lang::cc::Node_T(lang::cc::Node_T)> f);

lang::cc::Node::Mod_T xform_lang_cc_Node(lang::cc::Node::Mod_T x, function<lang::cc::Node_T(lang::cc::Node_T)> f);

lang::cc::Node::Mod::Const_T xform_lang_cc_Node(lang::cc::Node::Mod::Const_T x, function<lang::cc::Node_T(lang::cc::Node_T)> f);

lang::cc::Node::Mod::Inline_T xform_lang_cc_Node(lang::cc::Node::Mod::Inline_T x, function<lang::cc::Node_T(lang::cc::Node_T)> f);

lang::cc::Node::Mod::Static_T xform_lang_cc_Node(lang::cc::Node::Mod::Static_T x, function<lang::cc::Node_T(lang::cc::Node_T)> f);

lang::cc::Node::Mod::Virtual_T xform_lang_cc_Node(lang::cc::Node::Mod::Virtual_T x, function<lang::cc::Node_T(lang::cc::Node_T)> f);

lang::cc::Node::Mod::NoInline_T xform_lang_cc_Node(lang::cc::Node::Mod::NoInline_T x, function<lang::cc::Node_T(lang::cc::Node_T)> f);

lang::cc::Node::Mod::AlwaysInline_T xform_lang_cc_Node(lang::cc::Node::Mod::AlwaysInline_T x, function<lang::cc::Node_T(lang::cc::Node_T)> f);

lang::cc::Node::Param_T xform_lang_cc_Node(lang::cc::Node::Param_T x, function<lang::cc::Node_T(lang::cc::Node_T)> f);

lang::cc::Node::Param::val_T xform_lang_cc_Node(lang::cc::Node::Param::val_T x, function<lang::cc::Node_T(lang::cc::Node_T)> f);

lang::cc::Node::FunDeclDef_T xform_lang_cc_Node(lang::cc::Node::FunDeclDef_T x, function<lang::cc::Node_T(lang::cc::Node_T)> f);

lang::cc::Node::FunDeclDef::Decl_T xform_lang_cc_Node(lang::cc::Node::FunDeclDef::Decl_T x, function<lang::cc::Node_T(lang::cc::Node_T)> f);

lang::cc::Node::FunDeclDef::Def_T xform_lang_cc_Node(lang::cc::Node::FunDeclDef::Def_T x, function<lang::cc::Node_T(lang::cc::Node_T)> f);

lang::cc::Node::Block_T xform_lang_cc_Node(lang::cc::Node::Block_T x, function<lang::cc::Node_T(lang::cc::Node_T)> f);

lang::cc::Node::Stmt_T xform_lang_cc_Node(lang::cc::Node::Stmt_T x, function<lang::cc::Node_T(lang::cc::Node_T)> f);

lang::cc::Node::Stmt::Decl_T xform_lang_cc_Node(lang::cc::Node::Stmt::Decl_T x, function<lang::cc::Node_T(lang::cc::Node_T)> f);

lang::cc::Node::TypedDecl_T xform_lang_cc_Node(lang::cc::Node::TypedDecl_T x, function<lang::cc::Node_T(lang::cc::Node_T)> f);

lang::cc::Node::TypedDecl::vars::item_T xform_lang_cc_Node(lang::cc::Node::TypedDecl::vars::item_T x, function<lang::cc::Node_T(lang::cc::Node_T)> f);

lang::cc::Node::TypedDecl::vars::item::val_T xform_lang_cc_Node(lang::cc::Node::TypedDecl::vars::item::val_T x, function<lang::cc::Node_T(lang::cc::Node_T)> f);

lang::cc::Node::Stmt::Expr_T xform_lang_cc_Node(lang::cc::Node::Stmt::Expr_T x, function<lang::cc::Node_T(lang::cc::Node_T)> f);

lang::cc::Node::Stmt::Block_T xform_lang_cc_Node(lang::cc::Node::Stmt::Block_T x, function<lang::cc::Node_T(lang::cc::Node_T)> f);

lang::cc::Node::Stmt::If_T xform_lang_cc_Node(lang::cc::Node::Stmt::If_T x, function<lang::cc::Node_T(lang::cc::Node_T)> f);

lang::cc::Node::Stmt::IfElse_T xform_lang_cc_Node(lang::cc::Node::Stmt::IfElse_T x, function<lang::cc::Node_T(lang::cc::Node_T)> f);

lang::cc::Node::Stmt::For_T xform_lang_cc_Node(lang::cc::Node::Stmt::For_T x, function<lang::cc::Node_T(lang::cc::Node_T)> f);

lang::cc::Node::ExprExt_T xform_lang_cc_Node(lang::cc::Node::ExprExt_T x, function<lang::cc::Node_T(lang::cc::Node_T)> f);

lang::cc::Node::ExprExt::Expr_T xform_lang_cc_Node(lang::cc::Node::ExprExt::Expr_T x, function<lang::cc::Node_T(lang::cc::Node_T)> f);

lang::cc::Node::ExprExt::Decl_T xform_lang_cc_Node(lang::cc::Node::ExprExt::Decl_T x, function<lang::cc::Node_T(lang::cc::Node_T)> f);

lang::cc::Node::Stmt::Switch_T xform_lang_cc_Node(lang::cc::Node::Stmt::Switch_T x, function<lang::cc::Node_T(lang::cc::Node_T)> f);

lang::cc::Node::SwitchCase_T xform_lang_cc_Node(lang::cc::Node::SwitchCase_T x, function<lang::cc::Node_T(lang::cc::Node_T)> f);

lang::cc::Node::SwitchCase::Case_T xform_lang_cc_Node(lang::cc::Node::SwitchCase::Case_T x, function<lang::cc::Node_T(lang::cc::Node_T)> f);

lang::cc::Node::SwitchCase::Default_T xform_lang_cc_Node(lang::cc::Node::SwitchCase::Default_T x, function<lang::cc::Node_T(lang::cc::Node_T)> f);

lang::cc::Node::Stmt::Break_T xform_lang_cc_Node(lang::cc::Node::Stmt::Break_T x, function<lang::cc::Node_T(lang::cc::Node_T)> f);

lang::cc::Node::Stmt::Continue_T xform_lang_cc_Node(lang::cc::Node::Stmt::Continue_T x, function<lang::cc::Node_T(lang::cc::Node_T)> f);

lang::cc::Node::Stmt::Return_T xform_lang_cc_Node(lang::cc::Node::Stmt::Return_T x, function<lang::cc::Node_T(lang::cc::Node_T)> f);

lang::cc::Node::FunDeclDef::Del_T xform_lang_cc_Node(lang::cc::Node::FunDeclDef::Del_T x, function<lang::cc::Node_T(lang::cc::Node_T)> f);

lang::cc::Node::FunDeclDef::Zero_T xform_lang_cc_Node(lang::cc::Node::FunDeclDef::Zero_T x, function<lang::cc::Node_T(lang::cc::Node_T)> f);

lang::cc::Node::Decl::EnumStruct_T xform_lang_cc_Node(lang::cc::Node::Decl::EnumStruct_T x, function<lang::cc::Node_T(lang::cc::Node_T)> f);

lang::cc::Node::Decl::Fun_T xform_lang_cc_Node(lang::cc::Node::Decl::Fun_T x, function<lang::cc::Node_T(lang::cc::Node_T)> f);

lang::cc::Node::Decl::Fun::tmpl_T xform_lang_cc_Node(lang::cc::Node::Decl::Fun::tmpl_T x, function<lang::cc::Node_T(lang::cc::Node_T)> f);

lang::cc::Node::Decl::Fun::tmpl::args::item_T xform_lang_cc_Node(lang::cc::Node::Decl::Fun::tmpl::args::item_T x, function<lang::cc::Node_T(lang::cc::Node_T)> f);

lang::cc::Node::Decl::Namespace_T xform_lang_cc_Node(lang::cc::Node::Decl::Namespace_T x, function<lang::cc::Node_T(lang::cc::Node_T)> f);

lang::cc::Node::Decl::UsingAlias_T xform_lang_cc_Node(lang::cc::Node::Decl::UsingAlias_T x, function<lang::cc::Node_T(lang::cc::Node_T)> f);

lang::cc::Node::Decl::UsingAlias::tmpl_T xform_lang_cc_Node(lang::cc::Node::Decl::UsingAlias::tmpl_T x, function<lang::cc::Node_T(lang::cc::Node_T)> f);

lang::cc::Node::Decl::UsingAlias::tmpl::args::item_T xform_lang_cc_Node(lang::cc::Node::Decl::UsingAlias::tmpl::args::item_T x, function<lang::cc::Node_T(lang::cc::Node_T)> f);

lang::cc::Node::Decl::UsingNamespace_T xform_lang_cc_Node(lang::cc::Node::Decl::UsingNamespace_T x, function<lang::cc::Node_T(lang::cc::Node_T)> f);

lang::cc::Node::Decl::Include_T xform_lang_cc_Node(lang::cc::Node::Decl::Include_T x, function<lang::cc::Node_T(lang::cc::Node_T)> f);

lang::cc::Node::Decl::PragmaOnce_T xform_lang_cc_Node(lang::cc::Node::Decl::PragmaOnce_T x, function<lang::cc::Node_T(lang::cc::Node_T)> f);

namespace lang::cc::parser {
    IntPair action_by_vertex(lang_rt::ParserVertexId v, lang_rt::ParserLookahead la);
}

namespace lang::cc::parser {
    lang_rt::ParserVertexId vertex_dfa_step(lang_rt::ParserVertexId v, lang_rt::ParserSymId sym, lang_rt::ParserAttrMask attr);
}

namespace lang::cc::parser {
    lang_rt::ParserProcXforms proc_xform_by_prod_id();
}

namespace lang::cc::parser {
    lang_rt::ParserSymByName start_marker_by_name();
}

namespace lang::cc::parser {
    lang_rt::ParserSymId term_tok_to_sym(lang_rt::TokenId tok);
}

namespace lang::cc::parser {
    lang_rt::ParserSymId sym_to_recur_step(lang_rt::ParserSymId sym);
}

namespace lang::cc::parser {
    string sym_to_debug_string(lang_rt::ParserSymId sym);
}

namespace lang::cc::parser {
    Int sym_to_num_attrs(lang_rt::ParserSymId sym);
}

namespace lang::cc::parser {
    string attr_to_debug_string(lang_rt::ParserSymId sym, Int attr_ind);
}

namespace lang::cc {
    using LangDesc = lang_rt::LangDesc<Node::_T, parser::action_by_vertex, parser::vertex_dfa_step>;
}

namespace lang::cc {
    using LangDesc_T = lang_rt::LangDesc_T<Node::_T, parser::action_by_vertex, parser::vertex_dfa_step>;
}

namespace lang::cc {
    using QuoteEnv = lang_rt::QuoteEnv<Node::_T, parser::action_by_vertex, parser::vertex_dfa_step>;
}

namespace lang::cc {
    using QuoteEnv_T = lang_rt::QuoteEnv_T<Node::_T, parser::action_by_vertex, parser::vertex_dfa_step>;
}

namespace lang::cc {
    lang::cc::LangDesc_T init();
}

namespace lang::cc::lexer::body {
    inline __attribute__((always_inline)) Int proc_mode_loop_opt(Ptr<lang_rt::LexerModeDesc> mode, Ptr<lang_rt::LexerState> st, Ptr<lang_rt::SymItemVec> emit_dst, Int mode_start_pos, Int mode_buf_pos);
}

namespace lang::cc::lexer::comment_single {
    inline __attribute__((always_inline)) Int proc_mode_loop_opt(Ptr<lang_rt::LexerModeDesc> mode, Ptr<lang_rt::LexerState> st, Ptr<lang_rt::SymItemVec> emit_dst, Int mode_start_pos, Int mode_buf_pos);
}
