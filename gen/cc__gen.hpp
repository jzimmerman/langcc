#pragma once

#include <langcc_rt.hpp>

namespace lang::cc::lexer {
    langcc::rc_ptr<langcc::DFALabelIdVec> label_ids_ascii();

    langcc::rc_ptr<langcc::DFALabelIdMap> label_ids_unicode();
}

namespace lang::cc::lexer::body {
    langcc::DFAVertexId step(langcc::DFAVertexId v, langcc::DFALabelId lbl);

    [[always_inlines]] inline langcc::DFAActionWithToken acc(langcc::DFAVertexId v);

    [[always_inlines]] inline langcc::IntPair step_exec(langcc::Ptr<langcc::LexerState> st, langcc::Ptr<langcc::SymItemVec> emit_dst, langcc::Ptr<langcc::LexWhitespaceState> ws_state, langcc::DFAActionId acc, langcc::TokenId tok, langcc::Int& in_i, langcc::Int& tok_lo, langcc::Int& tok_hi);

    langcc::Int proc_mode_loop(langcc::Ptr<langcc::LexerState> st, langcc::Ptr<langcc::SymItemVec> emit_dst, langcc::Int mode_start_pos, langcc::Int mode_buf_pos);
}

namespace lang::cc::lexer::comment_single {
    langcc::DFAVertexId step(langcc::DFAVertexId v, langcc::DFALabelId lbl);

    [[always_inlines]] inline langcc::DFAActionWithToken acc(langcc::DFAVertexId v);

    [[always_inlines]] inline langcc::IntPair step_exec(langcc::Ptr<langcc::LexerState> st, langcc::Ptr<langcc::SymItemVec> emit_dst, langcc::Ptr<langcc::LexWhitespaceState> ws_state, langcc::DFAActionId acc, langcc::TokenId tok, langcc::Int& in_i, langcc::Int& tok_lo, langcc::Int& tok_hi);

    langcc::Int proc_mode_loop(langcc::Ptr<langcc::LexerState> st, langcc::Ptr<langcc::SymItemVec> emit_dst, langcc::Int mode_start_pos, langcc::Int mode_buf_pos);
}

#pragma once

#include <langcc_util.hpp>

namespace lang::cc::Node::Module {
    struct _T;
}

namespace lang::cc::Node {
    using Module_T = langcc::rc_ptr<lang::cc::Node::Module::_T>;
}

namespace lang::cc::Node::Decl::Struct::tmpl::item::args::item {
    struct _T;
}

namespace lang::cc::Node::Decl::Struct::tmpl::item::args {
    using item_T = langcc::rc_ptr<lang::cc::Node::Decl::Struct::tmpl::item::args::item::_T>;
}

namespace lang::cc::Node::Decl::Struct::tmpl::item {
    struct _T;
}

namespace lang::cc::Node::Decl::Struct::tmpl {
    using item_T = langcc::rc_ptr<lang::cc::Node::Decl::Struct::tmpl::item::_T>;
}

namespace lang::cc::Node::Decl::Struct {
    struct _T;
}

namespace lang::cc::Node::Decl {
    using Struct_T = langcc::rc_ptr<lang::cc::Node::Decl::Struct::_T>;
}

namespace lang::cc::Node::StructDeclDef::Decl {
    struct _T;
}

namespace lang::cc::Node::StructDeclDef {
    using Decl_T = langcc::rc_ptr<lang::cc::Node::StructDeclDef::Decl::_T>;
}

namespace lang::cc::Node::StructDeclDef::Def {
    struct _T;
}

namespace lang::cc::Node::StructDeclDef {
    using Def_T = langcc::rc_ptr<lang::cc::Node::StructDeclDef::Def::_T>;
}

namespace lang::cc::Node::Entry::Field {
    struct _T;
}

namespace lang::cc::Node::Entry {
    using Field_T = langcc::rc_ptr<lang::cc::Node::Entry::Field::_T>;
}

namespace lang::cc::Node::Entry::Fun::tmpl::item::args::item {
    struct _T;
}

namespace lang::cc::Node::Entry::Fun::tmpl::item::args {
    using item_T = langcc::rc_ptr<lang::cc::Node::Entry::Fun::tmpl::item::args::item::_T>;
}

namespace lang::cc::Node::Entry::Fun::tmpl::item {
    struct _T;
}

namespace lang::cc::Node::Entry::Fun::tmpl {
    using item_T = langcc::rc_ptr<lang::cc::Node::Entry::Fun::tmpl::item::_T>;
}

namespace lang::cc::Node::Entry::Fun {
    struct _T;
}

namespace lang::cc::Node::Entry {
    using Fun_T = langcc::rc_ptr<lang::cc::Node::Entry::Fun::_T>;
}

namespace lang::cc::Node::Param::val {
    struct _T;
}

namespace lang::cc::Node::Param {
    using val_T = langcc::rc_ptr<lang::cc::Node::Param::val::_T>;
}

namespace lang::cc::Node::Param {
    struct _T;
}

namespace lang::cc::Node {
    using Param_T = langcc::rc_ptr<lang::cc::Node::Param::_T>;
}

namespace lang::cc::Node::FunDeclDef::Decl {
    struct _T;
}

namespace lang::cc::Node::FunDeclDef {
    using Decl_T = langcc::rc_ptr<lang::cc::Node::FunDeclDef::Decl::_T>;
}

namespace lang::cc::Node::FunDeclDef::Def {
    struct _T;
}

namespace lang::cc::Node::FunDeclDef {
    using Def_T = langcc::rc_ptr<lang::cc::Node::FunDeclDef::Def::_T>;
}

namespace lang::cc::Node::FunDeclDef::Del {
    struct _T;
}

namespace lang::cc::Node::FunDeclDef {
    using Del_T = langcc::rc_ptr<lang::cc::Node::FunDeclDef::Del::_T>;
}

namespace lang::cc::Node::FunDeclDef::Zero {
    struct _T;
}

namespace lang::cc::Node::FunDeclDef {
    using Zero_T = langcc::rc_ptr<lang::cc::Node::FunDeclDef::Zero::_T>;
}

namespace lang::cc::Node::Decl::EnumStruct {
    struct _T;
}

namespace lang::cc::Node::Decl {
    using EnumStruct_T = langcc::rc_ptr<lang::cc::Node::Decl::EnumStruct::_T>;
}

namespace lang::cc::Node::Decl::Fun::tmpl::item::args::item {
    struct _T;
}

namespace lang::cc::Node::Decl::Fun::tmpl::item::args {
    using item_T = langcc::rc_ptr<lang::cc::Node::Decl::Fun::tmpl::item::args::item::_T>;
}

namespace lang::cc::Node::Decl::Fun::tmpl::item {
    struct _T;
}

namespace lang::cc::Node::Decl::Fun::tmpl {
    using item_T = langcc::rc_ptr<lang::cc::Node::Decl::Fun::tmpl::item::_T>;
}

namespace lang::cc::Node::Decl::Fun {
    struct _T;
}

namespace lang::cc::Node::Decl {
    using Fun_T = langcc::rc_ptr<lang::cc::Node::Decl::Fun::_T>;
}

namespace lang::cc::Node::Mod::Const {
    struct _T;
}

namespace lang::cc::Node::Mod {
    using Const_T = langcc::rc_ptr<lang::cc::Node::Mod::Const::_T>;
}

namespace lang::cc::Node::Mod::Inline {
    struct _T;
}

namespace lang::cc::Node::Mod {
    using Inline_T = langcc::rc_ptr<lang::cc::Node::Mod::Inline::_T>;
}

namespace lang::cc::Node::Mod::Static {
    struct _T;
}

namespace lang::cc::Node::Mod {
    using Static_T = langcc::rc_ptr<lang::cc::Node::Mod::Static::_T>;
}

namespace lang::cc::Node::Mod::Virtual {
    struct _T;
}

namespace lang::cc::Node::Mod {
    using Virtual_T = langcc::rc_ptr<lang::cc::Node::Mod::Virtual::_T>;
}

namespace lang::cc::Node::Mod::NoInline {
    struct _T;
}

namespace lang::cc::Node::Mod {
    using NoInline_T = langcc::rc_ptr<lang::cc::Node::Mod::NoInline::_T>;
}

namespace lang::cc::Node::Mod::AlwaysInline {
    struct _T;
}

namespace lang::cc::Node::Mod {
    using AlwaysInline_T = langcc::rc_ptr<lang::cc::Node::Mod::AlwaysInline::_T>;
}

namespace lang::cc::Node::Mod::Attribute {
    struct _T;
}

namespace lang::cc::Node::Mod {
    using Attribute_T = langcc::rc_ptr<lang::cc::Node::Mod::Attribute::_T>;
}

namespace lang::cc::Node::Attribute::Simple {
    struct _T;
}

namespace lang::cc::Node::Attribute {
    using Simple_T = langcc::rc_ptr<lang::cc::Node::Attribute::Simple::_T>;
}

namespace lang::cc::Node::Attribute::Namespaced {
    struct _T;
}

namespace lang::cc::Node::Attribute {
    using Namespaced_T = langcc::rc_ptr<lang::cc::Node::Attribute::Namespaced::_T>;
}

namespace lang::cc::Node::Decl::Namespace {
    struct _T;
}

namespace lang::cc::Node::Decl {
    using Namespace_T = langcc::rc_ptr<lang::cc::Node::Decl::Namespace::_T>;
}

namespace lang::cc::Node::Decl::UsingAlias::tmpl::item::args::item {
    struct _T;
}

namespace lang::cc::Node::Decl::UsingAlias::tmpl::item::args {
    using item_T = langcc::rc_ptr<lang::cc::Node::Decl::UsingAlias::tmpl::item::args::item::_T>;
}

namespace lang::cc::Node::Decl::UsingAlias::tmpl::item {
    struct _T;
}

namespace lang::cc::Node::Decl::UsingAlias::tmpl {
    using item_T = langcc::rc_ptr<lang::cc::Node::Decl::UsingAlias::tmpl::item::_T>;
}

namespace lang::cc::Node::Decl::UsingAlias {
    struct _T;
}

namespace lang::cc::Node::Decl {
    using UsingAlias_T = langcc::rc_ptr<lang::cc::Node::Decl::UsingAlias::_T>;
}

namespace lang::cc::Node::Decl::UsingNamespace {
    struct _T;
}

namespace lang::cc::Node::Decl {
    using UsingNamespace_T = langcc::rc_ptr<lang::cc::Node::Decl::UsingNamespace::_T>;
}

namespace lang::cc::Node::Decl::Include {
    struct _T;
}

namespace lang::cc::Node::Decl {
    using Include_T = langcc::rc_ptr<lang::cc::Node::Decl::Include::_T>;
}

namespace lang::cc::Node::Decl::PragmaOnce {
    struct _T;
}

namespace lang::cc::Node::Decl {
    using PragmaOnce_T = langcc::rc_ptr<lang::cc::Node::Decl::PragmaOnce::_T>;
}

namespace lang::cc::Node::Block {
    struct _T;
}

namespace lang::cc::Node {
    using Block_T = langcc::rc_ptr<lang::cc::Node::Block::_T>;
}

namespace lang::cc::Node::Stmt::Decl {
    struct _T;
}

namespace lang::cc::Node::Stmt {
    using Decl_T = langcc::rc_ptr<lang::cc::Node::Stmt::Decl::_T>;
}

namespace lang::cc::Node::TypedDecl::vars::item::val {
    struct _T;
}

namespace lang::cc::Node::TypedDecl::vars::item {
    using val_T = langcc::rc_ptr<lang::cc::Node::TypedDecl::vars::item::val::_T>;
}

namespace lang::cc::Node::TypedDecl::vars::item {
    struct _T;
}

namespace lang::cc::Node::TypedDecl::vars {
    using item_T = langcc::rc_ptr<lang::cc::Node::TypedDecl::vars::item::_T>;
}

namespace lang::cc::Node::TypedDecl {
    struct _T;
}

namespace lang::cc::Node {
    using TypedDecl_T = langcc::rc_ptr<lang::cc::Node::TypedDecl::_T>;
}

namespace lang::cc::Node::Stmt::Expr {
    struct _T;
}

namespace lang::cc::Node::Stmt {
    using Expr_T = langcc::rc_ptr<lang::cc::Node::Stmt::Expr::_T>;
}

namespace lang::cc::Node::Stmt::Block {
    struct _T;
}

namespace lang::cc::Node::Stmt {
    using Block_T = langcc::rc_ptr<lang::cc::Node::Stmt::Block::_T>;
}

namespace lang::cc::Node::Stmt::If {
    struct _T;
}

namespace lang::cc::Node::Stmt {
    using If_T = langcc::rc_ptr<lang::cc::Node::Stmt::If::_T>;
}

namespace lang::cc::Node::Stmt::IfElse {
    struct _T;
}

namespace lang::cc::Node::Stmt {
    using IfElse_T = langcc::rc_ptr<lang::cc::Node::Stmt::IfElse::_T>;
}

namespace lang::cc::Node::Stmt::For {
    struct _T;
}

namespace lang::cc::Node::Stmt {
    using For_T = langcc::rc_ptr<lang::cc::Node::Stmt::For::_T>;
}

namespace lang::cc::Node::ExprExt::Expr {
    struct _T;
}

namespace lang::cc::Node::ExprExt {
    using Expr_T = langcc::rc_ptr<lang::cc::Node::ExprExt::Expr::_T>;
}

namespace lang::cc::Node::ExprExt::Decl {
    struct _T;
}

namespace lang::cc::Node::ExprExt {
    using Decl_T = langcc::rc_ptr<lang::cc::Node::ExprExt::Decl::_T>;
}

namespace lang::cc::Node::Stmt::Switch {
    struct _T;
}

namespace lang::cc::Node::Stmt {
    using Switch_T = langcc::rc_ptr<lang::cc::Node::Stmt::Switch::_T>;
}

namespace lang::cc::Node::SwitchCase::Case {
    struct _T;
}

namespace lang::cc::Node::SwitchCase {
    using Case_T = langcc::rc_ptr<lang::cc::Node::SwitchCase::Case::_T>;
}

namespace lang::cc::Node::SwitchCase::Default {
    struct _T;
}

namespace lang::cc::Node::SwitchCase {
    using Default_T = langcc::rc_ptr<lang::cc::Node::SwitchCase::Default::_T>;
}

namespace lang::cc::Node::Stmt::Break {
    struct _T;
}

namespace lang::cc::Node::Stmt {
    using Break_T = langcc::rc_ptr<lang::cc::Node::Stmt::Break::_T>;
}

namespace lang::cc::Node::Stmt::Continue {
    struct _T;
}

namespace lang::cc::Node::Stmt {
    using Continue_T = langcc::rc_ptr<lang::cc::Node::Stmt::Continue::_T>;
}

namespace lang::cc::Node::Stmt::Return {
    struct _T;
}

namespace lang::cc::Node::Stmt {
    using Return_T = langcc::rc_ptr<lang::cc::Node::Stmt::Return::_T>;
}

namespace lang::cc::Node::Expr::Paren {
    struct _T;
}

namespace lang::cc::Node::Expr {
    using Paren_T = langcc::rc_ptr<lang::cc::Node::Expr::Paren::_T>;
}

namespace lang::cc::Node::Expr::Call {
    struct _T;
}

namespace lang::cc::Node::Expr {
    using Call_T = langcc::rc_ptr<lang::cc::Node::Expr::Call::_T>;
}

namespace lang::cc::Node::Expr::Index {
    struct _T;
}

namespace lang::cc::Node::Expr {
    using Index_T = langcc::rc_ptr<lang::cc::Node::Expr::Index::_T>;
}

namespace lang::cc::Node::Expr::IndexEmpty {
    struct _T;
}

namespace lang::cc::Node::Expr {
    using IndexEmpty_T = langcc::rc_ptr<lang::cc::Node::Expr::IndexEmpty::_T>;
}

namespace lang::cc::Node::Expr::Dot {
    struct _T;
}

namespace lang::cc::Node::Expr {
    using Dot_T = langcc::rc_ptr<lang::cc::Node::Expr::Dot::_T>;
}

namespace lang::cc::Node::Expr::Arrow {
    struct _T;
}

namespace lang::cc::Node::Expr {
    using Arrow_T = langcc::rc_ptr<lang::cc::Node::Expr::Arrow::_T>;
}

namespace lang::cc::Node::Expr::Ref_ {
    struct _T;
}

namespace lang::cc::Node::Expr {
    using Ref__T = langcc::rc_ptr<lang::cc::Node::Expr::Ref_::_T>;
}

namespace lang::cc::Node::Expr::AddrOf {
    struct _T;
}

namespace lang::cc::Node::Expr {
    using AddrOf_T = langcc::rc_ptr<lang::cc::Node::Expr::AddrOf::_T>;
}

namespace lang::cc::Node::Expr::Deref {
    struct _T;
}

namespace lang::cc::Node::Expr {
    using Deref_T = langcc::rc_ptr<lang::cc::Node::Expr::Deref::_T>;
}

namespace lang::cc::Node::Expr::UnaryPre::op::NOT {
    struct _T;
}

namespace lang::cc::Node::Expr::UnaryPre::op {
    using NOT_T = langcc::rc_ptr<lang::cc::Node::Expr::UnaryPre::op::NOT::_T>;
}

namespace lang::cc::Node::Expr::UnaryPre::op::NEG {
    struct _T;
}

namespace lang::cc::Node::Expr::UnaryPre::op {
    using NEG_T = langcc::rc_ptr<lang::cc::Node::Expr::UnaryPre::op::NEG::_T>;
}

namespace lang::cc::Node::Expr::UnaryPre::op {
    struct _T;
}

namespace lang::cc::Node::Expr::UnaryPre {
    using op_T = langcc::rc_ptr<lang::cc::Node::Expr::UnaryPre::op::_T>;
}

namespace lang::cc::Node::Expr::UnaryPre {
    struct _T;
}

namespace lang::cc::Node::Expr {
    using UnaryPre_T = langcc::rc_ptr<lang::cc::Node::Expr::UnaryPre::_T>;
}

namespace lang::cc::Node::Expr::IncDecPre::op::INC {
    struct _T;
}

namespace lang::cc::Node::Expr::IncDecPre::op {
    using INC_T = langcc::rc_ptr<lang::cc::Node::Expr::IncDecPre::op::INC::_T>;
}

namespace lang::cc::Node::Expr::IncDecPre::op::DEC {
    struct _T;
}

namespace lang::cc::Node::Expr::IncDecPre::op {
    using DEC_T = langcc::rc_ptr<lang::cc::Node::Expr::IncDecPre::op::DEC::_T>;
}

namespace lang::cc::Node::Expr::IncDecPre::op {
    struct _T;
}

namespace lang::cc::Node::Expr::IncDecPre {
    using op_T = langcc::rc_ptr<lang::cc::Node::Expr::IncDecPre::op::_T>;
}

namespace lang::cc::Node::Expr::IncDecPre {
    struct _T;
}

namespace lang::cc::Node::Expr {
    using IncDecPre_T = langcc::rc_ptr<lang::cc::Node::Expr::IncDecPre::_T>;
}

namespace lang::cc::Node::Expr::IncDecPost::op::INC {
    struct _T;
}

namespace lang::cc::Node::Expr::IncDecPost::op {
    using INC_T = langcc::rc_ptr<lang::cc::Node::Expr::IncDecPost::op::INC::_T>;
}

namespace lang::cc::Node::Expr::IncDecPost::op::DEC {
    struct _T;
}

namespace lang::cc::Node::Expr::IncDecPost::op {
    using DEC_T = langcc::rc_ptr<lang::cc::Node::Expr::IncDecPost::op::DEC::_T>;
}

namespace lang::cc::Node::Expr::IncDecPost::op {
    struct _T;
}

namespace lang::cc::Node::Expr::IncDecPost {
    using op_T = langcc::rc_ptr<lang::cc::Node::Expr::IncDecPost::op::_T>;
}

namespace lang::cc::Node::Expr::IncDecPost {
    struct _T;
}

namespace lang::cc::Node::Expr {
    using IncDecPost_T = langcc::rc_ptr<lang::cc::Node::Expr::IncDecPost::_T>;
}

namespace lang::cc::Node::Expr::Assign {
    struct _T;
}

namespace lang::cc::Node::Expr {
    using Assign_T = langcc::rc_ptr<lang::cc::Node::Expr::Assign::_T>;
}

namespace lang::cc::Node::Expr::Bin1::op::LOR {
    struct _T;
}

namespace lang::cc::Node::Expr::Bin1::op {
    using LOR_T = langcc::rc_ptr<lang::cc::Node::Expr::Bin1::op::LOR::_T>;
}

namespace lang::cc::Node::Expr::Bin1::op {
    struct _T;
}

namespace lang::cc::Node::Expr::Bin1 {
    using op_T = langcc::rc_ptr<lang::cc::Node::Expr::Bin1::op::_T>;
}

namespace lang::cc::Node::Expr::Bin1 {
    struct _T;
}

namespace lang::cc::Node::Expr {
    using Bin1_T = langcc::rc_ptr<lang::cc::Node::Expr::Bin1::_T>;
}

namespace lang::cc::Node::Expr::Bin2::op::LAND {
    struct _T;
}

namespace lang::cc::Node::Expr::Bin2::op {
    using LAND_T = langcc::rc_ptr<lang::cc::Node::Expr::Bin2::op::LAND::_T>;
}

namespace lang::cc::Node::Expr::Bin2::op {
    struct _T;
}

namespace lang::cc::Node::Expr::Bin2 {
    using op_T = langcc::rc_ptr<lang::cc::Node::Expr::Bin2::op::_T>;
}

namespace lang::cc::Node::Expr::Bin2 {
    struct _T;
}

namespace lang::cc::Node::Expr {
    using Bin2_T = langcc::rc_ptr<lang::cc::Node::Expr::Bin2::_T>;
}

namespace lang::cc::Node::Expr::Bin3::op::EQ {
    struct _T;
}

namespace lang::cc::Node::Expr::Bin3::op {
    using EQ_T = langcc::rc_ptr<lang::cc::Node::Expr::Bin3::op::EQ::_T>;
}

namespace lang::cc::Node::Expr::Bin3::op::NE {
    struct _T;
}

namespace lang::cc::Node::Expr::Bin3::op {
    using NE_T = langcc::rc_ptr<lang::cc::Node::Expr::Bin3::op::NE::_T>;
}

namespace lang::cc::Node::Expr::Bin3::op::LE {
    struct _T;
}

namespace lang::cc::Node::Expr::Bin3::op {
    using LE_T = langcc::rc_ptr<lang::cc::Node::Expr::Bin3::op::LE::_T>;
}

namespace lang::cc::Node::Expr::Bin3::op::GE {
    struct _T;
}

namespace lang::cc::Node::Expr::Bin3::op {
    using GE_T = langcc::rc_ptr<lang::cc::Node::Expr::Bin3::op::GE::_T>;
}

namespace lang::cc::Node::Expr::Bin3::op::LT {
    struct _T;
}

namespace lang::cc::Node::Expr::Bin3::op {
    using LT_T = langcc::rc_ptr<lang::cc::Node::Expr::Bin3::op::LT::_T>;
}

namespace lang::cc::Node::Expr::Bin3::op::GT {
    struct _T;
}

namespace lang::cc::Node::Expr::Bin3::op {
    using GT_T = langcc::rc_ptr<lang::cc::Node::Expr::Bin3::op::GT::_T>;
}

namespace lang::cc::Node::Expr::Bin3::op {
    struct _T;
}

namespace lang::cc::Node::Expr::Bin3 {
    using op_T = langcc::rc_ptr<lang::cc::Node::Expr::Bin3::op::_T>;
}

namespace lang::cc::Node::Expr::Bin3 {
    struct _T;
}

namespace lang::cc::Node::Expr {
    using Bin3_T = langcc::rc_ptr<lang::cc::Node::Expr::Bin3::_T>;
}

namespace lang::cc::Node::Expr::Bin4::op::SHL {
    struct _T;
}

namespace lang::cc::Node::Expr::Bin4::op {
    using SHL_T = langcc::rc_ptr<lang::cc::Node::Expr::Bin4::op::SHL::_T>;
}

namespace lang::cc::Node::Expr::Bin4::op {
    struct _T;
}

namespace lang::cc::Node::Expr::Bin4 {
    using op_T = langcc::rc_ptr<lang::cc::Node::Expr::Bin4::op::_T>;
}

namespace lang::cc::Node::Expr::Bin4 {
    struct _T;
}

namespace lang::cc::Node::Expr {
    using Bin4_T = langcc::rc_ptr<lang::cc::Node::Expr::Bin4::_T>;
}

namespace lang::cc::Node::Expr::Bin5::op::PLUS {
    struct _T;
}

namespace lang::cc::Node::Expr::Bin5::op {
    using PLUS_T = langcc::rc_ptr<lang::cc::Node::Expr::Bin5::op::PLUS::_T>;
}

namespace lang::cc::Node::Expr::Bin5::op::MINUS {
    struct _T;
}

namespace lang::cc::Node::Expr::Bin5::op {
    using MINUS_T = langcc::rc_ptr<lang::cc::Node::Expr::Bin5::op::MINUS::_T>;
}

namespace lang::cc::Node::Expr::Bin5::op {
    struct _T;
}

namespace lang::cc::Node::Expr::Bin5 {
    using op_T = langcc::rc_ptr<lang::cc::Node::Expr::Bin5::op::_T>;
}

namespace lang::cc::Node::Expr::Bin5 {
    struct _T;
}

namespace lang::cc::Node::Expr {
    using Bin5_T = langcc::rc_ptr<lang::cc::Node::Expr::Bin5::_T>;
}

namespace lang::cc::Node::Expr::Bin6::op::TIMES {
    struct _T;
}

namespace lang::cc::Node::Expr::Bin6::op {
    using TIMES_T = langcc::rc_ptr<lang::cc::Node::Expr::Bin6::op::TIMES::_T>;
}

namespace lang::cc::Node::Expr::Bin6::op::DIVIDE {
    struct _T;
}

namespace lang::cc::Node::Expr::Bin6::op {
    using DIVIDE_T = langcc::rc_ptr<lang::cc::Node::Expr::Bin6::op::DIVIDE::_T>;
}

namespace lang::cc::Node::Expr::Bin6::op::MODULO {
    struct _T;
}

namespace lang::cc::Node::Expr::Bin6::op {
    using MODULO_T = langcc::rc_ptr<lang::cc::Node::Expr::Bin6::op::MODULO::_T>;
}

namespace lang::cc::Node::Expr::Bin6::op {
    struct _T;
}

namespace lang::cc::Node::Expr::Bin6 {
    using op_T = langcc::rc_ptr<lang::cc::Node::Expr::Bin6::op::_T>;
}

namespace lang::cc::Node::Expr::Bin6 {
    struct _T;
}

namespace lang::cc::Node::Expr {
    using Bin6_T = langcc::rc_ptr<lang::cc::Node::Expr::Bin6::_T>;
}

namespace lang::cc::Node::Expr::Template {
    struct _T;
}

namespace lang::cc::Node::Expr {
    using Template_T = langcc::rc_ptr<lang::cc::Node::Expr::Template::_T>;
}

namespace lang::cc::Node::Expr::New {
    struct _T;
}

namespace lang::cc::Node::Expr {
    using New_T = langcc::rc_ptr<lang::cc::Node::Expr::New::_T>;
}

namespace lang::cc::Node::Expr::Delete {
    struct _T;
}

namespace lang::cc::Node::Expr {
    using Delete_T = langcc::rc_ptr<lang::cc::Node::Expr::Delete::_T>;
}

namespace lang::cc::Node::Expr::Ellipsis {
    struct _T;
}

namespace lang::cc::Node::Expr {
    using Ellipsis_T = langcc::rc_ptr<lang::cc::Node::Expr::Ellipsis::_T>;
}

namespace lang::cc::Node::Expr::Tilde {
    struct _T;
}

namespace lang::cc::Node::Expr {
    using Tilde_T = langcc::rc_ptr<lang::cc::Node::Expr::Tilde::_T>;
}

namespace lang::cc::Node::Expr::Namespace {
    struct _T;
}

namespace lang::cc::Node::Expr {
    using Namespace_T = langcc::rc_ptr<lang::cc::Node::Expr::Namespace::_T>;
}

namespace lang::cc::Node::Expr::Id {
    struct _T;
}

namespace lang::cc::Node::Expr {
    using Id_T = langcc::rc_ptr<lang::cc::Node::Expr::Id::_T>;
}

namespace lang::cc::Node::Expr::Lit::Integer {
    struct _T;
}

namespace lang::cc::Node::Expr::Lit {
    using Integer_T = langcc::rc_ptr<lang::cc::Node::Expr::Lit::Integer::_T>;
}

namespace lang::cc::Node::Expr::Lit::Str_ {
    struct _T;
}

namespace lang::cc::Node::Expr::Lit {
    using Str__T = langcc::rc_ptr<lang::cc::Node::Expr::Lit::Str_::_T>;
}

namespace lang::cc::Node::Expr::Lit::Array {
    struct _T;
}

namespace lang::cc::Node::Expr::Lit {
    using Array_T = langcc::rc_ptr<lang::cc::Node::Expr::Lit::Array::_T>;
}

namespace lang::cc::Node::Decl {
    struct _T;
}

namespace lang::cc::Node {
    using Decl_T = langcc::rc_ptr<lang::cc::Node::Decl::_T>;
}

namespace lang::cc::Node::StructDeclDef {
    struct _T;
}

namespace lang::cc::Node {
    using StructDeclDef_T = langcc::rc_ptr<lang::cc::Node::StructDeclDef::_T>;
}

namespace lang::cc::Node::Entry {
    struct _T;
}

namespace lang::cc::Node {
    using Entry_T = langcc::rc_ptr<lang::cc::Node::Entry::_T>;
}

namespace lang::cc::Node::FunDeclDef {
    struct _T;
}

namespace lang::cc::Node {
    using FunDeclDef_T = langcc::rc_ptr<lang::cc::Node::FunDeclDef::_T>;
}

namespace lang::cc::Node::Mod {
    struct _T;
}

namespace lang::cc::Node {
    using Mod_T = langcc::rc_ptr<lang::cc::Node::Mod::_T>;
}

namespace lang::cc::Node::Attribute {
    struct _T;
}

namespace lang::cc::Node {
    using Attribute_T = langcc::rc_ptr<lang::cc::Node::Attribute::_T>;
}

namespace lang::cc::Node::Stmt {
    struct _T;
}

namespace lang::cc::Node {
    using Stmt_T = langcc::rc_ptr<lang::cc::Node::Stmt::_T>;
}

namespace lang::cc::Node::ExprExt {
    struct _T;
}

namespace lang::cc::Node {
    using ExprExt_T = langcc::rc_ptr<lang::cc::Node::ExprExt::_T>;
}

namespace lang::cc::Node::SwitchCase {
    struct _T;
}

namespace lang::cc::Node {
    using SwitchCase_T = langcc::rc_ptr<lang::cc::Node::SwitchCase::_T>;
}

namespace lang::cc::Node::Expr {
    struct _T;
}

namespace lang::cc::Node {
    using Expr_T = langcc::rc_ptr<lang::cc::Node::Expr::_T>;
}

namespace lang::cc::Node::Expr::Lit {
    struct _T;
}

namespace lang::cc::Node::Expr {
    using Lit_T = langcc::rc_ptr<lang::cc::Node::Expr::Lit::_T>;
}

namespace lang::cc::Node {
    struct _T;
}

namespace lang::cc {
    using Node_T = langcc::rc_ptr<lang::cc::Node::_T>;
}

namespace langcc {
    void pr_debug(ostream& os, FmtFlags flags, lang::cc::Node_T x);
}

namespace lang::cc::Node {
    enum struct _W {
        Module,
        Decl__Struct__tmpl__item__args__item,
        Decl__Struct__tmpl__item,
        Entry__Fun__tmpl__item__args__item,
        Entry__Fun__tmpl__item,
        Param__val,
        Param,
        Decl__Fun__tmpl__item__args__item,
        Decl__Fun__tmpl__item,
        Decl__UsingAlias__tmpl__item__args__item,
        Decl__UsingAlias__tmpl__item,
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
        Attribute,
        Stmt,
        ExprExt,
        SwitchCase,
        Expr,
    };
}

namespace lang::cc::Node {
    struct _T: langcc::hash_obj, langcc::enable_rc_from_this_poly {
        void write(langcc::Ref<std::ostream> os, langcc::FmtFlags flags);
        void write(langcc::Ref<langcc::PrBufStream_T> pb);
        lang::cc::Node::_W w_;
        virtual ~_T();
        langcc::Int id_;
        langcc::TokenBounds bounds_;
        bool is_top_;
        langcc::ParserSymId sym_;
        langcc::ParserAttrMask attr_;
        langcc::ParserLookahead first_k_;
        _T(lang::cc::Node::_W w);
        bool is_Module() const;
        bool is_Decl__Struct__tmpl__item__args__item() const;
        bool is_Decl__Struct__tmpl__item() const;
        bool is_Entry__Fun__tmpl__item__args__item() const;
        bool is_Entry__Fun__tmpl__item() const;
        bool is_Param__val() const;
        bool is_Param() const;
        bool is_Decl__Fun__tmpl__item__args__item() const;
        bool is_Decl__Fun__tmpl__item() const;
        bool is_Decl__UsingAlias__tmpl__item__args__item() const;
        bool is_Decl__UsingAlias__tmpl__item() const;
        bool is_Block() const;
        bool is_TypedDecl__vars__item__val() const;
        bool is_TypedDecl__vars__item() const;
        bool is_TypedDecl() const;
        bool is_Expr__UnaryPre__op() const;
        bool is_Expr__IncDecPre__op() const;
        bool is_Expr__IncDecPost__op() const;
        bool is_Expr__Bin1__op() const;
        bool is_Expr__Bin2__op() const;
        bool is_Expr__Bin3__op() const;
        bool is_Expr__Bin4__op() const;
        bool is_Expr__Bin5__op() const;
        bool is_Expr__Bin6__op() const;
        bool is_Decl() const;
        bool is_StructDeclDef() const;
        bool is_Entry() const;
        bool is_FunDeclDef() const;
        bool is_Mod() const;
        bool is_Attribute() const;
        bool is_Stmt() const;
        bool is_ExprExt() const;
        bool is_SwitchCase() const;
        bool is_Expr() const;
        lang::cc::Node::Module_T as_Module();
        const lang::cc::Node::Module_T as_Module() const;
        lang::cc::Node::Decl::Struct::tmpl::item::args::item_T as_Decl__Struct__tmpl__item__args__item();
        const lang::cc::Node::Decl::Struct::tmpl::item::args::item_T as_Decl__Struct__tmpl__item__args__item() const;
        lang::cc::Node::Decl::Struct::tmpl::item_T as_Decl__Struct__tmpl__item();
        const lang::cc::Node::Decl::Struct::tmpl::item_T as_Decl__Struct__tmpl__item() const;
        lang::cc::Node::Entry::Fun::tmpl::item::args::item_T as_Entry__Fun__tmpl__item__args__item();
        const lang::cc::Node::Entry::Fun::tmpl::item::args::item_T as_Entry__Fun__tmpl__item__args__item() const;
        lang::cc::Node::Entry::Fun::tmpl::item_T as_Entry__Fun__tmpl__item();
        const lang::cc::Node::Entry::Fun::tmpl::item_T as_Entry__Fun__tmpl__item() const;
        lang::cc::Node::Param::val_T as_Param__val();
        const lang::cc::Node::Param::val_T as_Param__val() const;
        lang::cc::Node::Param_T as_Param();
        const lang::cc::Node::Param_T as_Param() const;
        lang::cc::Node::Decl::Fun::tmpl::item::args::item_T as_Decl__Fun__tmpl__item__args__item();
        const lang::cc::Node::Decl::Fun::tmpl::item::args::item_T as_Decl__Fun__tmpl__item__args__item() const;
        lang::cc::Node::Decl::Fun::tmpl::item_T as_Decl__Fun__tmpl__item();
        const lang::cc::Node::Decl::Fun::tmpl::item_T as_Decl__Fun__tmpl__item() const;
        lang::cc::Node::Decl::UsingAlias::tmpl::item::args::item_T as_Decl__UsingAlias__tmpl__item__args__item();
        const lang::cc::Node::Decl::UsingAlias::tmpl::item::args::item_T as_Decl__UsingAlias__tmpl__item__args__item() const;
        lang::cc::Node::Decl::UsingAlias::tmpl::item_T as_Decl__UsingAlias__tmpl__item();
        const lang::cc::Node::Decl::UsingAlias::tmpl::item_T as_Decl__UsingAlias__tmpl__item() const;
        lang::cc::Node::Block_T as_Block();
        const lang::cc::Node::Block_T as_Block() const;
        lang::cc::Node::TypedDecl::vars::item::val_T as_TypedDecl__vars__item__val();
        const lang::cc::Node::TypedDecl::vars::item::val_T as_TypedDecl__vars__item__val() const;
        lang::cc::Node::TypedDecl::vars::item_T as_TypedDecl__vars__item();
        const lang::cc::Node::TypedDecl::vars::item_T as_TypedDecl__vars__item() const;
        lang::cc::Node::TypedDecl_T as_TypedDecl();
        const lang::cc::Node::TypedDecl_T as_TypedDecl() const;
        lang::cc::Node::Expr::UnaryPre::op_T as_Expr__UnaryPre__op();
        const lang::cc::Node::Expr::UnaryPre::op_T as_Expr__UnaryPre__op() const;
        lang::cc::Node::Expr::IncDecPre::op_T as_Expr__IncDecPre__op();
        const lang::cc::Node::Expr::IncDecPre::op_T as_Expr__IncDecPre__op() const;
        lang::cc::Node::Expr::IncDecPost::op_T as_Expr__IncDecPost__op();
        const lang::cc::Node::Expr::IncDecPost::op_T as_Expr__IncDecPost__op() const;
        lang::cc::Node::Expr::Bin1::op_T as_Expr__Bin1__op();
        const lang::cc::Node::Expr::Bin1::op_T as_Expr__Bin1__op() const;
        lang::cc::Node::Expr::Bin2::op_T as_Expr__Bin2__op();
        const lang::cc::Node::Expr::Bin2::op_T as_Expr__Bin2__op() const;
        lang::cc::Node::Expr::Bin3::op_T as_Expr__Bin3__op();
        const lang::cc::Node::Expr::Bin3::op_T as_Expr__Bin3__op() const;
        lang::cc::Node::Expr::Bin4::op_T as_Expr__Bin4__op();
        const lang::cc::Node::Expr::Bin4::op_T as_Expr__Bin4__op() const;
        lang::cc::Node::Expr::Bin5::op_T as_Expr__Bin5__op();
        const lang::cc::Node::Expr::Bin5::op_T as_Expr__Bin5__op() const;
        lang::cc::Node::Expr::Bin6::op_T as_Expr__Bin6__op();
        const lang::cc::Node::Expr::Bin6::op_T as_Expr__Bin6__op() const;
        lang::cc::Node::Decl_T as_Decl();
        const lang::cc::Node::Decl_T as_Decl() const;
        lang::cc::Node::StructDeclDef_T as_StructDeclDef();
        const lang::cc::Node::StructDeclDef_T as_StructDeclDef() const;
        lang::cc::Node::Entry_T as_Entry();
        const lang::cc::Node::Entry_T as_Entry() const;
        lang::cc::Node::FunDeclDef_T as_FunDeclDef();
        const lang::cc::Node::FunDeclDef_T as_FunDeclDef() const;
        lang::cc::Node::Mod_T as_Mod();
        const lang::cc::Node::Mod_T as_Mod() const;
        lang::cc::Node::Attribute_T as_Attribute();
        const lang::cc::Node::Attribute_T as_Attribute() const;
        lang::cc::Node::Stmt_T as_Stmt();
        const lang::cc::Node::Stmt_T as_Stmt() const;
        lang::cc::Node::ExprExt_T as_ExprExt();
        const lang::cc::Node::ExprExt_T as_ExprExt() const;
        lang::cc::Node::SwitchCase_T as_SwitchCase();
        const lang::cc::Node::SwitchCase_T as_SwitchCase() const;
        lang::cc::Node::Expr_T as_Expr();
        const lang::cc::Node::Expr_T as_Expr() const;
        void match(std::function<void(lang::cc::Node::Module_T)> f_Module, std::function<void(lang::cc::Node::Decl::Struct::tmpl::item::args::item_T)> f_Decl__Struct__tmpl__item__args__item, std::function<void(lang::cc::Node::Decl::Struct::tmpl::item_T)> f_Decl__Struct__tmpl__item, std::function<void(lang::cc::Node::Entry::Fun::tmpl::item::args::item_T)> f_Entry__Fun__tmpl__item__args__item, std::function<void(lang::cc::Node::Entry::Fun::tmpl::item_T)> f_Entry__Fun__tmpl__item, std::function<void(lang::cc::Node::Param::val_T)> f_Param__val, std::function<void(lang::cc::Node::Param_T)> f_Param, std::function<void(lang::cc::Node::Decl::Fun::tmpl::item::args::item_T)> f_Decl__Fun__tmpl__item__args__item, std::function<void(lang::cc::Node::Decl::Fun::tmpl::item_T)> f_Decl__Fun__tmpl__item, std::function<void(lang::cc::Node::Decl::UsingAlias::tmpl::item::args::item_T)> f_Decl__UsingAlias__tmpl__item__args__item, std::function<void(lang::cc::Node::Decl::UsingAlias::tmpl::item_T)> f_Decl__UsingAlias__tmpl__item, std::function<void(lang::cc::Node::Block_T)> f_Block, std::function<void(lang::cc::Node::TypedDecl::vars::item::val_T)> f_TypedDecl__vars__item__val, std::function<void(lang::cc::Node::TypedDecl::vars::item_T)> f_TypedDecl__vars__item, std::function<void(lang::cc::Node::TypedDecl_T)> f_TypedDecl, std::function<void(lang::cc::Node::Expr::UnaryPre::op_T)> f_Expr__UnaryPre__op, std::function<void(lang::cc::Node::Expr::IncDecPre::op_T)> f_Expr__IncDecPre__op, std::function<void(lang::cc::Node::Expr::IncDecPost::op_T)> f_Expr__IncDecPost__op, std::function<void(lang::cc::Node::Expr::Bin1::op_T)> f_Expr__Bin1__op, std::function<void(lang::cc::Node::Expr::Bin2::op_T)> f_Expr__Bin2__op, std::function<void(lang::cc::Node::Expr::Bin3::op_T)> f_Expr__Bin3__op, std::function<void(lang::cc::Node::Expr::Bin4::op_T)> f_Expr__Bin4__op, std::function<void(lang::cc::Node::Expr::Bin5::op_T)> f_Expr__Bin5__op, std::function<void(lang::cc::Node::Expr::Bin6::op_T)> f_Expr__Bin6__op, std::function<void(lang::cc::Node::Decl_T)> f_Decl, std::function<void(lang::cc::Node::StructDeclDef_T)> f_StructDeclDef, std::function<void(lang::cc::Node::Entry_T)> f_Entry, std::function<void(lang::cc::Node::FunDeclDef_T)> f_FunDeclDef, std::function<void(lang::cc::Node::Mod_T)> f_Mod, std::function<void(lang::cc::Node::Attribute_T)> f_Attribute, std::function<void(lang::cc::Node::Stmt_T)> f_Stmt, std::function<void(lang::cc::Node::ExprExt_T)> f_ExprExt, std::function<void(lang::cc::Node::SwitchCase_T)> f_SwitchCase, std::function<void(lang::cc::Node::Expr_T)> f_Expr);
        template<typename RetT> RetT match_expr(std::function<RetT(lang::cc::Node::Module_T)> f_Module, std::function<RetT(lang::cc::Node::Decl::Struct::tmpl::item::args::item_T)> f_Decl__Struct__tmpl__item__args__item, std::function<RetT(lang::cc::Node::Decl::Struct::tmpl::item_T)> f_Decl__Struct__tmpl__item, std::function<RetT(lang::cc::Node::Entry::Fun::tmpl::item::args::item_T)> f_Entry__Fun__tmpl__item__args__item, std::function<RetT(lang::cc::Node::Entry::Fun::tmpl::item_T)> f_Entry__Fun__tmpl__item, std::function<RetT(lang::cc::Node::Param::val_T)> f_Param__val, std::function<RetT(lang::cc::Node::Param_T)> f_Param, std::function<RetT(lang::cc::Node::Decl::Fun::tmpl::item::args::item_T)> f_Decl__Fun__tmpl__item__args__item, std::function<RetT(lang::cc::Node::Decl::Fun::tmpl::item_T)> f_Decl__Fun__tmpl__item, std::function<RetT(lang::cc::Node::Decl::UsingAlias::tmpl::item::args::item_T)> f_Decl__UsingAlias__tmpl__item__args__item, std::function<RetT(lang::cc::Node::Decl::UsingAlias::tmpl::item_T)> f_Decl__UsingAlias__tmpl__item, std::function<RetT(lang::cc::Node::Block_T)> f_Block, std::function<RetT(lang::cc::Node::TypedDecl::vars::item::val_T)> f_TypedDecl__vars__item__val, std::function<RetT(lang::cc::Node::TypedDecl::vars::item_T)> f_TypedDecl__vars__item, std::function<RetT(lang::cc::Node::TypedDecl_T)> f_TypedDecl, std::function<RetT(lang::cc::Node::Expr::UnaryPre::op_T)> f_Expr__UnaryPre__op, std::function<RetT(lang::cc::Node::Expr::IncDecPre::op_T)> f_Expr__IncDecPre__op, std::function<RetT(lang::cc::Node::Expr::IncDecPost::op_T)> f_Expr__IncDecPost__op, std::function<RetT(lang::cc::Node::Expr::Bin1::op_T)> f_Expr__Bin1__op, std::function<RetT(lang::cc::Node::Expr::Bin2::op_T)> f_Expr__Bin2__op, std::function<RetT(lang::cc::Node::Expr::Bin3::op_T)> f_Expr__Bin3__op, std::function<RetT(lang::cc::Node::Expr::Bin4::op_T)> f_Expr__Bin4__op, std::function<RetT(lang::cc::Node::Expr::Bin5::op_T)> f_Expr__Bin5__op, std::function<RetT(lang::cc::Node::Expr::Bin6::op_T)> f_Expr__Bin6__op, std::function<RetT(lang::cc::Node::Decl_T)> f_Decl, std::function<RetT(lang::cc::Node::StructDeclDef_T)> f_StructDeclDef, std::function<RetT(lang::cc::Node::Entry_T)> f_Entry, std::function<RetT(lang::cc::Node::FunDeclDef_T)> f_FunDeclDef, std::function<RetT(lang::cc::Node::Mod_T)> f_Mod, std::function<RetT(lang::cc::Node::Attribute_T)> f_Attribute, std::function<RetT(lang::cc::Node::Stmt_T)> f_Stmt, std::function<RetT(lang::cc::Node::ExprExt_T)> f_ExprExt, std::function<RetT(lang::cc::Node::SwitchCase_T)> f_SwitchCase, std::function<RetT(lang::cc::Node::Expr_T)> f_Expr);
        void hash_ser_acc_lang_cc_Node(langcc::SerBuf& buf) const;
        virtual void hash_ser_acc(langcc::SerBuf& buf) const = 0;
    };
}

template<typename RetT> RetT lang::cc::Node::_T::match_expr(std::function<RetT(lang::cc::Node::Module_T)> f_Module, std::function<RetT(lang::cc::Node::Decl::Struct::tmpl::item::args::item_T)> f_Decl__Struct__tmpl__item__args__item, std::function<RetT(lang::cc::Node::Decl::Struct::tmpl::item_T)> f_Decl__Struct__tmpl__item, std::function<RetT(lang::cc::Node::Entry::Fun::tmpl::item::args::item_T)> f_Entry__Fun__tmpl__item__args__item, std::function<RetT(lang::cc::Node::Entry::Fun::tmpl::item_T)> f_Entry__Fun__tmpl__item, std::function<RetT(lang::cc::Node::Param::val_T)> f_Param__val, std::function<RetT(lang::cc::Node::Param_T)> f_Param, std::function<RetT(lang::cc::Node::Decl::Fun::tmpl::item::args::item_T)> f_Decl__Fun__tmpl__item__args__item, std::function<RetT(lang::cc::Node::Decl::Fun::tmpl::item_T)> f_Decl__Fun__tmpl__item, std::function<RetT(lang::cc::Node::Decl::UsingAlias::tmpl::item::args::item_T)> f_Decl__UsingAlias__tmpl__item__args__item, std::function<RetT(lang::cc::Node::Decl::UsingAlias::tmpl::item_T)> f_Decl__UsingAlias__tmpl__item, std::function<RetT(lang::cc::Node::Block_T)> f_Block, std::function<RetT(lang::cc::Node::TypedDecl::vars::item::val_T)> f_TypedDecl__vars__item__val, std::function<RetT(lang::cc::Node::TypedDecl::vars::item_T)> f_TypedDecl__vars__item, std::function<RetT(lang::cc::Node::TypedDecl_T)> f_TypedDecl, std::function<RetT(lang::cc::Node::Expr::UnaryPre::op_T)> f_Expr__UnaryPre__op, std::function<RetT(lang::cc::Node::Expr::IncDecPre::op_T)> f_Expr__IncDecPre__op, std::function<RetT(lang::cc::Node::Expr::IncDecPost::op_T)> f_Expr__IncDecPost__op, std::function<RetT(lang::cc::Node::Expr::Bin1::op_T)> f_Expr__Bin1__op, std::function<RetT(lang::cc::Node::Expr::Bin2::op_T)> f_Expr__Bin2__op, std::function<RetT(lang::cc::Node::Expr::Bin3::op_T)> f_Expr__Bin3__op, std::function<RetT(lang::cc::Node::Expr::Bin4::op_T)> f_Expr__Bin4__op, std::function<RetT(lang::cc::Node::Expr::Bin5::op_T)> f_Expr__Bin5__op, std::function<RetT(lang::cc::Node::Expr::Bin6::op_T)> f_Expr__Bin6__op, std::function<RetT(lang::cc::Node::Decl_T)> f_Decl, std::function<RetT(lang::cc::Node::StructDeclDef_T)> f_StructDeclDef, std::function<RetT(lang::cc::Node::Entry_T)> f_Entry, std::function<RetT(lang::cc::Node::FunDeclDef_T)> f_FunDeclDef, std::function<RetT(lang::cc::Node::Mod_T)> f_Mod, std::function<RetT(lang::cc::Node::Attribute_T)> f_Attribute, std::function<RetT(lang::cc::Node::Stmt_T)> f_Stmt, std::function<RetT(lang::cc::Node::ExprExt_T)> f_ExprExt, std::function<RetT(lang::cc::Node::SwitchCase_T)> f_SwitchCase, std::function<RetT(lang::cc::Node::Expr_T)> f_Expr) {
    switch (this->w_) {
        case lang::cc::Node::_W::Module: {
            return f_Module(this->as_Module());
            break;
        }
        case lang::cc::Node::_W::Decl__Struct__tmpl__item__args__item: {
            return f_Decl__Struct__tmpl__item__args__item(this->as_Decl__Struct__tmpl__item__args__item());
            break;
        }
        case lang::cc::Node::_W::Decl__Struct__tmpl__item: {
            return f_Decl__Struct__tmpl__item(this->as_Decl__Struct__tmpl__item());
            break;
        }
        case lang::cc::Node::_W::Entry__Fun__tmpl__item__args__item: {
            return f_Entry__Fun__tmpl__item__args__item(this->as_Entry__Fun__tmpl__item__args__item());
            break;
        }
        case lang::cc::Node::_W::Entry__Fun__tmpl__item: {
            return f_Entry__Fun__tmpl__item(this->as_Entry__Fun__tmpl__item());
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
        case lang::cc::Node::_W::Decl__Fun__tmpl__item__args__item: {
            return f_Decl__Fun__tmpl__item__args__item(this->as_Decl__Fun__tmpl__item__args__item());
            break;
        }
        case lang::cc::Node::_W::Decl__Fun__tmpl__item: {
            return f_Decl__Fun__tmpl__item(this->as_Decl__Fun__tmpl__item());
            break;
        }
        case lang::cc::Node::_W::Decl__UsingAlias__tmpl__item__args__item: {
            return f_Decl__UsingAlias__tmpl__item__args__item(this->as_Decl__UsingAlias__tmpl__item__args__item());
            break;
        }
        case lang::cc::Node::_W::Decl__UsingAlias__tmpl__item: {
            return f_Decl__UsingAlias__tmpl__item(this->as_Decl__UsingAlias__tmpl__item());
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
        case lang::cc::Node::_W::Attribute: {
            return f_Attribute(this->as_Attribute());
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
            langcc::AX();
        }
    }
}

namespace langcc {
    void pr_debug(ostream& os, FmtFlags flags, lang::cc::Node::Module_T x);
}

namespace lang::cc::Node::Module {
    lang::cc::Node::Module_T make(langcc::Int id, langcc::TokenBounds bounds, bool is_top, langcc::ParserSymId sym, langcc::ParserAttrMask attr, langcc::ParserLookahead first_k, langcc::Vec_T<lang::cc::Node::Decl_T> decls);
}

namespace lang::cc::Node::Module {
    lang::cc::Node::Module_T make_ext(langcc::ArenaPtr arena, langcc::Int id, langcc::TokenBounds bounds, bool is_top, langcc::ParserSymId sym, langcc::ParserAttrMask attr, langcc::ParserLookahead first_k, langcc::Vec_T<lang::cc::Node::Decl_T> decls);
}

namespace lang::cc::Node::Module {
    struct _T: lang::cc::Node::_T {
        void write(langcc::Ref<std::ostream> os, langcc::FmtFlags flags);
        void write(langcc::Ref<langcc::PrBufStream_T> pb);
        langcc::Vec_T<lang::cc::Node::Decl_T> decls_;
        _T();
        lang::cc::Node::Module_T with_id(langcc::Int id);
        lang::cc::Node::Module_T with_bounds(langcc::TokenBounds bounds);
        lang::cc::Node::Module_T with_is_top(bool is_top);
        lang::cc::Node::Module_T with_sym(langcc::ParserSymId sym);
        lang::cc::Node::Module_T with_attr(langcc::ParserAttrMask attr);
        lang::cc::Node::Module_T with_first_k(langcc::ParserLookahead first_k);
        lang::cc::Node::Module_T with_decls(langcc::Vec_T<lang::cc::Node::Decl_T> decls);
        void hash_ser_acc_lang_cc_Node_Module(langcc::SerBuf& buf) const;
        virtual void hash_ser_acc(langcc::SerBuf& buf) const;
    };
}

namespace langcc {
    void pr_debug(ostream& os, FmtFlags flags, lang::cc::Node::Param_T x);
}

namespace lang::cc::Node::Param {
    lang::cc::Node::Param_T make(langcc::Int id, langcc::TokenBounds bounds, bool is_top, langcc::ParserSymId sym, langcc::ParserAttrMask attr, langcc::ParserLookahead first_k, langcc::Vec_T<lang::cc::Node::Mod_T> mods, lang::cc::Node::Expr_T type_, lang::cc::Node::Expr_T name, langcc::Option_T<lang::cc::Node::Param::val_T> val);
}

namespace lang::cc::Node::Param {
    lang::cc::Node::Param_T make_ext(langcc::ArenaPtr arena, langcc::Int id, langcc::TokenBounds bounds, bool is_top, langcc::ParserSymId sym, langcc::ParserAttrMask attr, langcc::ParserLookahead first_k, langcc::Vec_T<lang::cc::Node::Mod_T> mods, lang::cc::Node::Expr_T type_, lang::cc::Node::Expr_T name, langcc::Option_T<lang::cc::Node::Param::val_T> val);
}

namespace lang::cc::Node::Param {
    struct _T: lang::cc::Node::_T {
        void write(langcc::Ref<std::ostream> os, langcc::FmtFlags flags);
        void write(langcc::Ref<langcc::PrBufStream_T> pb);
        langcc::Vec_T<lang::cc::Node::Mod_T> mods_;
        lang::cc::Node::Expr_T type__;
        lang::cc::Node::Expr_T name_;
        langcc::Option_T<lang::cc::Node::Param::val_T> val_;
        _T();
        lang::cc::Node::Param_T with_id(langcc::Int id);
        lang::cc::Node::Param_T with_bounds(langcc::TokenBounds bounds);
        lang::cc::Node::Param_T with_is_top(bool is_top);
        lang::cc::Node::Param_T with_sym(langcc::ParserSymId sym);
        lang::cc::Node::Param_T with_attr(langcc::ParserAttrMask attr);
        lang::cc::Node::Param_T with_first_k(langcc::ParserLookahead first_k);
        lang::cc::Node::Param_T with_mods(langcc::Vec_T<lang::cc::Node::Mod_T> mods);
        lang::cc::Node::Param_T with_type_(lang::cc::Node::Expr_T type_);
        lang::cc::Node::Param_T with_name(lang::cc::Node::Expr_T name);
        lang::cc::Node::Param_T with_val(langcc::Option_T<lang::cc::Node::Param::val_T> val);
        void hash_ser_acc_lang_cc_Node_Param(langcc::SerBuf& buf) const;
        virtual void hash_ser_acc(langcc::SerBuf& buf) const;
    };
}

namespace langcc {
    void pr_debug(ostream& os, FmtFlags flags, lang::cc::Node::Block_T x);
}

namespace lang::cc::Node::Block {
    lang::cc::Node::Block_T make(langcc::Int id, langcc::TokenBounds bounds, bool is_top, langcc::ParserSymId sym, langcc::ParserAttrMask attr, langcc::ParserLookahead first_k, langcc::Vec_T<lang::cc::Node::Stmt_T> stmts);
}

namespace lang::cc::Node::Block {
    lang::cc::Node::Block_T make_ext(langcc::ArenaPtr arena, langcc::Int id, langcc::TokenBounds bounds, bool is_top, langcc::ParserSymId sym, langcc::ParserAttrMask attr, langcc::ParserLookahead first_k, langcc::Vec_T<lang::cc::Node::Stmt_T> stmts);
}

namespace lang::cc::Node::Block {
    struct _T: lang::cc::Node::_T {
        void write(langcc::Ref<std::ostream> os, langcc::FmtFlags flags);
        void write(langcc::Ref<langcc::PrBufStream_T> pb);
        langcc::Vec_T<lang::cc::Node::Stmt_T> stmts_;
        _T();
        lang::cc::Node::Block_T with_id(langcc::Int id);
        lang::cc::Node::Block_T with_bounds(langcc::TokenBounds bounds);
        lang::cc::Node::Block_T with_is_top(bool is_top);
        lang::cc::Node::Block_T with_sym(langcc::ParserSymId sym);
        lang::cc::Node::Block_T with_attr(langcc::ParserAttrMask attr);
        lang::cc::Node::Block_T with_first_k(langcc::ParserLookahead first_k);
        lang::cc::Node::Block_T with_stmts(langcc::Vec_T<lang::cc::Node::Stmt_T> stmts);
        void hash_ser_acc_lang_cc_Node_Block(langcc::SerBuf& buf) const;
        virtual void hash_ser_acc(langcc::SerBuf& buf) const;
    };
}

namespace langcc {
    void pr_debug(ostream& os, FmtFlags flags, lang::cc::Node::TypedDecl_T x);
}

namespace lang::cc::Node::TypedDecl {
    lang::cc::Node::TypedDecl_T make(langcc::Int id, langcc::TokenBounds bounds, bool is_top, langcc::ParserSymId sym, langcc::ParserAttrMask attr, langcc::ParserLookahead first_k, langcc::Vec_T<lang::cc::Node::Mod_T> mods, lang::cc::Node::Expr_T type_, langcc::Vec_T<lang::cc::Node::TypedDecl::vars::item_T> vars);
}

namespace lang::cc::Node::TypedDecl {
    lang::cc::Node::TypedDecl_T make_ext(langcc::ArenaPtr arena, langcc::Int id, langcc::TokenBounds bounds, bool is_top, langcc::ParserSymId sym, langcc::ParserAttrMask attr, langcc::ParserLookahead first_k, langcc::Vec_T<lang::cc::Node::Mod_T> mods, lang::cc::Node::Expr_T type_, langcc::Vec_T<lang::cc::Node::TypedDecl::vars::item_T> vars);
}

namespace lang::cc::Node::TypedDecl {
    struct _T: lang::cc::Node::_T {
        void write(langcc::Ref<std::ostream> os, langcc::FmtFlags flags);
        void write(langcc::Ref<langcc::PrBufStream_T> pb);
        langcc::Vec_T<lang::cc::Node::Mod_T> mods_;
        lang::cc::Node::Expr_T type__;
        langcc::Vec_T<lang::cc::Node::TypedDecl::vars::item_T> vars_;
        _T();
        lang::cc::Node::TypedDecl_T with_id(langcc::Int id);
        lang::cc::Node::TypedDecl_T with_bounds(langcc::TokenBounds bounds);
        lang::cc::Node::TypedDecl_T with_is_top(bool is_top);
        lang::cc::Node::TypedDecl_T with_sym(langcc::ParserSymId sym);
        lang::cc::Node::TypedDecl_T with_attr(langcc::ParserAttrMask attr);
        lang::cc::Node::TypedDecl_T with_first_k(langcc::ParserLookahead first_k);
        lang::cc::Node::TypedDecl_T with_mods(langcc::Vec_T<lang::cc::Node::Mod_T> mods);
        lang::cc::Node::TypedDecl_T with_type_(lang::cc::Node::Expr_T type_);
        lang::cc::Node::TypedDecl_T with_vars(langcc::Vec_T<lang::cc::Node::TypedDecl::vars::item_T> vars);
        void hash_ser_acc_lang_cc_Node_TypedDecl(langcc::SerBuf& buf) const;
        virtual void hash_ser_acc(langcc::SerBuf& buf) const;
    };
}

namespace langcc {
    void pr_debug(ostream& os, FmtFlags flags, lang::cc::Node::Decl_T x);
}

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
        void write(langcc::Ref<std::ostream> os, langcc::FmtFlags flags);
        void write(langcc::Ref<langcc::PrBufStream_T> pb);
        lang::cc::Node::Decl::_W w_;
        virtual ~_T();
        _T(lang::cc::Node::Decl::_W w);
        bool is_Struct() const;
        bool is_EnumStruct() const;
        bool is_Fun() const;
        bool is_Namespace() const;
        bool is_UsingAlias() const;
        bool is_UsingNamespace() const;
        bool is_Include() const;
        bool is_PragmaOnce() const;
        lang::cc::Node::Decl::Struct_T as_Struct();
        const lang::cc::Node::Decl::Struct_T as_Struct() const;
        lang::cc::Node::Decl::EnumStruct_T as_EnumStruct();
        const lang::cc::Node::Decl::EnumStruct_T as_EnumStruct() const;
        lang::cc::Node::Decl::Fun_T as_Fun();
        const lang::cc::Node::Decl::Fun_T as_Fun() const;
        lang::cc::Node::Decl::Namespace_T as_Namespace();
        const lang::cc::Node::Decl::Namespace_T as_Namespace() const;
        lang::cc::Node::Decl::UsingAlias_T as_UsingAlias();
        const lang::cc::Node::Decl::UsingAlias_T as_UsingAlias() const;
        lang::cc::Node::Decl::UsingNamespace_T as_UsingNamespace();
        const lang::cc::Node::Decl::UsingNamespace_T as_UsingNamespace() const;
        lang::cc::Node::Decl::Include_T as_Include();
        const lang::cc::Node::Decl::Include_T as_Include() const;
        lang::cc::Node::Decl::PragmaOnce_T as_PragmaOnce();
        const lang::cc::Node::Decl::PragmaOnce_T as_PragmaOnce() const;
        void match(std::function<void(lang::cc::Node::Decl::Struct_T)> f_Struct, std::function<void(lang::cc::Node::Decl::EnumStruct_T)> f_EnumStruct, std::function<void(lang::cc::Node::Decl::Fun_T)> f_Fun, std::function<void(lang::cc::Node::Decl::Namespace_T)> f_Namespace, std::function<void(lang::cc::Node::Decl::UsingAlias_T)> f_UsingAlias, std::function<void(lang::cc::Node::Decl::UsingNamespace_T)> f_UsingNamespace, std::function<void(lang::cc::Node::Decl::Include_T)> f_Include, std::function<void(lang::cc::Node::Decl::PragmaOnce_T)> f_PragmaOnce);
        template<typename RetT> RetT match_expr(std::function<RetT(lang::cc::Node::Decl::Struct_T)> f_Struct, std::function<RetT(lang::cc::Node::Decl::EnumStruct_T)> f_EnumStruct, std::function<RetT(lang::cc::Node::Decl::Fun_T)> f_Fun, std::function<RetT(lang::cc::Node::Decl::Namespace_T)> f_Namespace, std::function<RetT(lang::cc::Node::Decl::UsingAlias_T)> f_UsingAlias, std::function<RetT(lang::cc::Node::Decl::UsingNamespace_T)> f_UsingNamespace, std::function<RetT(lang::cc::Node::Decl::Include_T)> f_Include, std::function<RetT(lang::cc::Node::Decl::PragmaOnce_T)> f_PragmaOnce);
        void hash_ser_acc_lang_cc_Node_Decl(langcc::SerBuf& buf) const;
        virtual void hash_ser_acc(langcc::SerBuf& buf) const = 0;
    };
}

template<typename RetT> RetT lang::cc::Node::Decl::_T::match_expr(std::function<RetT(lang::cc::Node::Decl::Struct_T)> f_Struct, std::function<RetT(lang::cc::Node::Decl::EnumStruct_T)> f_EnumStruct, std::function<RetT(lang::cc::Node::Decl::Fun_T)> f_Fun, std::function<RetT(lang::cc::Node::Decl::Namespace_T)> f_Namespace, std::function<RetT(lang::cc::Node::Decl::UsingAlias_T)> f_UsingAlias, std::function<RetT(lang::cc::Node::Decl::UsingNamespace_T)> f_UsingNamespace, std::function<RetT(lang::cc::Node::Decl::Include_T)> f_Include, std::function<RetT(lang::cc::Node::Decl::PragmaOnce_T)> f_PragmaOnce) {
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
            langcc::AX();
        }
    }
}

namespace langcc {
    void pr_debug(ostream& os, FmtFlags flags, lang::cc::Node::StructDeclDef_T x);
}

namespace lang::cc::Node::StructDeclDef {
    enum struct _W {
        Decl,
        Def,
    };
}

namespace lang::cc::Node::StructDeclDef {
    struct _T: lang::cc::Node::_T {
        void write(langcc::Ref<std::ostream> os, langcc::FmtFlags flags);
        void write(langcc::Ref<langcc::PrBufStream_T> pb);
        lang::cc::Node::StructDeclDef::_W w_;
        virtual ~_T();
        _T(lang::cc::Node::StructDeclDef::_W w);
        bool is_Decl() const;
        bool is_Def() const;
        lang::cc::Node::StructDeclDef::Decl_T as_Decl();
        const lang::cc::Node::StructDeclDef::Decl_T as_Decl() const;
        lang::cc::Node::StructDeclDef::Def_T as_Def();
        const lang::cc::Node::StructDeclDef::Def_T as_Def() const;
        void match(std::function<void(lang::cc::Node::StructDeclDef::Decl_T)> f_Decl, std::function<void(lang::cc::Node::StructDeclDef::Def_T)> f_Def);
        template<typename RetT> RetT match_expr(std::function<RetT(lang::cc::Node::StructDeclDef::Decl_T)> f_Decl, std::function<RetT(lang::cc::Node::StructDeclDef::Def_T)> f_Def);
        void hash_ser_acc_lang_cc_Node_StructDeclDef(langcc::SerBuf& buf) const;
        virtual void hash_ser_acc(langcc::SerBuf& buf) const = 0;
    };
}

template<typename RetT> RetT lang::cc::Node::StructDeclDef::_T::match_expr(std::function<RetT(lang::cc::Node::StructDeclDef::Decl_T)> f_Decl, std::function<RetT(lang::cc::Node::StructDeclDef::Def_T)> f_Def) {
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
            langcc::AX();
        }
    }
}

namespace langcc {
    void pr_debug(ostream& os, FmtFlags flags, lang::cc::Node::Entry_T x);
}

namespace lang::cc::Node::Entry {
    enum struct _W {
        Field,
        Fun,
    };
}

namespace lang::cc::Node::Entry {
    struct _T: lang::cc::Node::_T {
        void write(langcc::Ref<std::ostream> os, langcc::FmtFlags flags);
        void write(langcc::Ref<langcc::PrBufStream_T> pb);
        lang::cc::Node::Entry::_W w_;
        virtual ~_T();
        _T(lang::cc::Node::Entry::_W w);
        bool is_Field() const;
        bool is_Fun() const;
        lang::cc::Node::Entry::Field_T as_Field();
        const lang::cc::Node::Entry::Field_T as_Field() const;
        lang::cc::Node::Entry::Fun_T as_Fun();
        const lang::cc::Node::Entry::Fun_T as_Fun() const;
        void match(std::function<void(lang::cc::Node::Entry::Field_T)> f_Field, std::function<void(lang::cc::Node::Entry::Fun_T)> f_Fun);
        template<typename RetT> RetT match_expr(std::function<RetT(lang::cc::Node::Entry::Field_T)> f_Field, std::function<RetT(lang::cc::Node::Entry::Fun_T)> f_Fun);
        void hash_ser_acc_lang_cc_Node_Entry(langcc::SerBuf& buf) const;
        virtual void hash_ser_acc(langcc::SerBuf& buf) const = 0;
    };
}

template<typename RetT> RetT lang::cc::Node::Entry::_T::match_expr(std::function<RetT(lang::cc::Node::Entry::Field_T)> f_Field, std::function<RetT(lang::cc::Node::Entry::Fun_T)> f_Fun) {
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
            langcc::AX();
        }
    }
}

namespace langcc {
    void pr_debug(ostream& os, FmtFlags flags, lang::cc::Node::FunDeclDef_T x);
}

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
        void write(langcc::Ref<std::ostream> os, langcc::FmtFlags flags);
        void write(langcc::Ref<langcc::PrBufStream_T> pb);
        lang::cc::Node::FunDeclDef::_W w_;
        virtual ~_T();
        _T(lang::cc::Node::FunDeclDef::_W w);
        bool is_Decl() const;
        bool is_Def() const;
        bool is_Del() const;
        bool is_Zero() const;
        lang::cc::Node::FunDeclDef::Decl_T as_Decl();
        const lang::cc::Node::FunDeclDef::Decl_T as_Decl() const;
        lang::cc::Node::FunDeclDef::Def_T as_Def();
        const lang::cc::Node::FunDeclDef::Def_T as_Def() const;
        lang::cc::Node::FunDeclDef::Del_T as_Del();
        const lang::cc::Node::FunDeclDef::Del_T as_Del() const;
        lang::cc::Node::FunDeclDef::Zero_T as_Zero();
        const lang::cc::Node::FunDeclDef::Zero_T as_Zero() const;
        void match(std::function<void(lang::cc::Node::FunDeclDef::Decl_T)> f_Decl, std::function<void(lang::cc::Node::FunDeclDef::Def_T)> f_Def, std::function<void(lang::cc::Node::FunDeclDef::Del_T)> f_Del, std::function<void(lang::cc::Node::FunDeclDef::Zero_T)> f_Zero);
        template<typename RetT> RetT match_expr(std::function<RetT(lang::cc::Node::FunDeclDef::Decl_T)> f_Decl, std::function<RetT(lang::cc::Node::FunDeclDef::Def_T)> f_Def, std::function<RetT(lang::cc::Node::FunDeclDef::Del_T)> f_Del, std::function<RetT(lang::cc::Node::FunDeclDef::Zero_T)> f_Zero);
        void hash_ser_acc_lang_cc_Node_FunDeclDef(langcc::SerBuf& buf) const;
        virtual void hash_ser_acc(langcc::SerBuf& buf) const = 0;
    };
}

template<typename RetT> RetT lang::cc::Node::FunDeclDef::_T::match_expr(std::function<RetT(lang::cc::Node::FunDeclDef::Decl_T)> f_Decl, std::function<RetT(lang::cc::Node::FunDeclDef::Def_T)> f_Def, std::function<RetT(lang::cc::Node::FunDeclDef::Del_T)> f_Del, std::function<RetT(lang::cc::Node::FunDeclDef::Zero_T)> f_Zero) {
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
            langcc::AX();
        }
    }
}

namespace langcc {
    void pr_debug(ostream& os, FmtFlags flags, lang::cc::Node::Mod_T x);
}

namespace lang::cc::Node::Mod {
    enum struct _W {
        Const,
        Inline,
        Static,
        Virtual,
        NoInline,
        AlwaysInline,
        Attribute,
    };
}

namespace lang::cc::Node::Mod {
    struct _T: lang::cc::Node::_T {
        void write(langcc::Ref<std::ostream> os, langcc::FmtFlags flags);
        void write(langcc::Ref<langcc::PrBufStream_T> pb);
        lang::cc::Node::Mod::_W w_;
        virtual ~_T();
        _T(lang::cc::Node::Mod::_W w);
        bool is_Const() const;
        bool is_Inline() const;
        bool is_Static() const;
        bool is_Virtual() const;
        bool is_NoInline() const;
        bool is_AlwaysInline() const;
        bool is_Attribute() const;
        lang::cc::Node::Mod::Const_T as_Const();
        const lang::cc::Node::Mod::Const_T as_Const() const;
        lang::cc::Node::Mod::Inline_T as_Inline();
        const lang::cc::Node::Mod::Inline_T as_Inline() const;
        lang::cc::Node::Mod::Static_T as_Static();
        const lang::cc::Node::Mod::Static_T as_Static() const;
        lang::cc::Node::Mod::Virtual_T as_Virtual();
        const lang::cc::Node::Mod::Virtual_T as_Virtual() const;
        lang::cc::Node::Mod::NoInline_T as_NoInline();
        const lang::cc::Node::Mod::NoInline_T as_NoInline() const;
        lang::cc::Node::Mod::AlwaysInline_T as_AlwaysInline();
        const lang::cc::Node::Mod::AlwaysInline_T as_AlwaysInline() const;
        lang::cc::Node::Mod::Attribute_T as_Attribute();
        const lang::cc::Node::Mod::Attribute_T as_Attribute() const;
        void match(std::function<void(lang::cc::Node::Mod::Const_T)> f_Const, std::function<void(lang::cc::Node::Mod::Inline_T)> f_Inline, std::function<void(lang::cc::Node::Mod::Static_T)> f_Static, std::function<void(lang::cc::Node::Mod::Virtual_T)> f_Virtual, std::function<void(lang::cc::Node::Mod::NoInline_T)> f_NoInline, std::function<void(lang::cc::Node::Mod::AlwaysInline_T)> f_AlwaysInline, std::function<void(lang::cc::Node::Mod::Attribute_T)> f_Attribute);
        template<typename RetT> RetT match_expr(std::function<RetT(lang::cc::Node::Mod::Const_T)> f_Const, std::function<RetT(lang::cc::Node::Mod::Inline_T)> f_Inline, std::function<RetT(lang::cc::Node::Mod::Static_T)> f_Static, std::function<RetT(lang::cc::Node::Mod::Virtual_T)> f_Virtual, std::function<RetT(lang::cc::Node::Mod::NoInline_T)> f_NoInline, std::function<RetT(lang::cc::Node::Mod::AlwaysInline_T)> f_AlwaysInline, std::function<RetT(lang::cc::Node::Mod::Attribute_T)> f_Attribute);
        void hash_ser_acc_lang_cc_Node_Mod(langcc::SerBuf& buf) const;
        virtual void hash_ser_acc(langcc::SerBuf& buf) const = 0;
    };
}

template<typename RetT> RetT lang::cc::Node::Mod::_T::match_expr(std::function<RetT(lang::cc::Node::Mod::Const_T)> f_Const, std::function<RetT(lang::cc::Node::Mod::Inline_T)> f_Inline, std::function<RetT(lang::cc::Node::Mod::Static_T)> f_Static, std::function<RetT(lang::cc::Node::Mod::Virtual_T)> f_Virtual, std::function<RetT(lang::cc::Node::Mod::NoInline_T)> f_NoInline, std::function<RetT(lang::cc::Node::Mod::AlwaysInline_T)> f_AlwaysInline, std::function<RetT(lang::cc::Node::Mod::Attribute_T)> f_Attribute) {
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
        case lang::cc::Node::Mod::_W::Attribute: {
            return f_Attribute(this->as_Attribute());
            break;
        }
        default: {
            langcc::AX();
        }
    }
}

namespace langcc {
    void pr_debug(ostream& os, FmtFlags flags, lang::cc::Node::Attribute_T x);
}

namespace lang::cc::Node::Attribute {
    enum struct _W {
        Simple,
        Namespaced,
    };
}

namespace lang::cc::Node::Attribute {
    struct _T: lang::cc::Node::_T {
        void write(langcc::Ref<std::ostream> os, langcc::FmtFlags flags);
        void write(langcc::Ref<langcc::PrBufStream_T> pb);
        lang::cc::Node::Attribute::_W w_;
        virtual ~_T();
        _T(lang::cc::Node::Attribute::_W w);
        bool is_Simple() const;
        bool is_Namespaced() const;
        lang::cc::Node::Attribute::Simple_T as_Simple();
        const lang::cc::Node::Attribute::Simple_T as_Simple() const;
        lang::cc::Node::Attribute::Namespaced_T as_Namespaced();
        const lang::cc::Node::Attribute::Namespaced_T as_Namespaced() const;
        void match(std::function<void(lang::cc::Node::Attribute::Simple_T)> f_Simple, std::function<void(lang::cc::Node::Attribute::Namespaced_T)> f_Namespaced);
        template<typename RetT> RetT match_expr(std::function<RetT(lang::cc::Node::Attribute::Simple_T)> f_Simple, std::function<RetT(lang::cc::Node::Attribute::Namespaced_T)> f_Namespaced);
        void hash_ser_acc_lang_cc_Node_Attribute(langcc::SerBuf& buf) const;
        virtual void hash_ser_acc(langcc::SerBuf& buf) const = 0;
    };
}

template<typename RetT> RetT lang::cc::Node::Attribute::_T::match_expr(std::function<RetT(lang::cc::Node::Attribute::Simple_T)> f_Simple, std::function<RetT(lang::cc::Node::Attribute::Namespaced_T)> f_Namespaced) {
    switch (this->w_) {
        case lang::cc::Node::Attribute::_W::Simple: {
            return f_Simple(this->as_Simple());
            break;
        }
        case lang::cc::Node::Attribute::_W::Namespaced: {
            return f_Namespaced(this->as_Namespaced());
            break;
        }
        default: {
            langcc::AX();
        }
    }
}

namespace langcc {
    void pr_debug(ostream& os, FmtFlags flags, lang::cc::Node::Stmt_T x);
}

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
        void write(langcc::Ref<std::ostream> os, langcc::FmtFlags flags);
        void write(langcc::Ref<langcc::PrBufStream_T> pb);
        lang::cc::Node::Stmt::_W w_;
        virtual ~_T();
        _T(lang::cc::Node::Stmt::_W w);
        bool is_Decl() const;
        bool is_Expr() const;
        bool is_Block() const;
        bool is_If() const;
        bool is_IfElse() const;
        bool is_For() const;
        bool is_Switch() const;
        bool is_Break() const;
        bool is_Continue() const;
        bool is_Return() const;
        lang::cc::Node::Stmt::Decl_T as_Decl();
        const lang::cc::Node::Stmt::Decl_T as_Decl() const;
        lang::cc::Node::Stmt::Expr_T as_Expr();
        const lang::cc::Node::Stmt::Expr_T as_Expr() const;
        lang::cc::Node::Stmt::Block_T as_Block();
        const lang::cc::Node::Stmt::Block_T as_Block() const;
        lang::cc::Node::Stmt::If_T as_If();
        const lang::cc::Node::Stmt::If_T as_If() const;
        lang::cc::Node::Stmt::IfElse_T as_IfElse();
        const lang::cc::Node::Stmt::IfElse_T as_IfElse() const;
        lang::cc::Node::Stmt::For_T as_For();
        const lang::cc::Node::Stmt::For_T as_For() const;
        lang::cc::Node::Stmt::Switch_T as_Switch();
        const lang::cc::Node::Stmt::Switch_T as_Switch() const;
        lang::cc::Node::Stmt::Break_T as_Break();
        const lang::cc::Node::Stmt::Break_T as_Break() const;
        lang::cc::Node::Stmt::Continue_T as_Continue();
        const lang::cc::Node::Stmt::Continue_T as_Continue() const;
        lang::cc::Node::Stmt::Return_T as_Return();
        const lang::cc::Node::Stmt::Return_T as_Return() const;
        void match(std::function<void(lang::cc::Node::Stmt::Decl_T)> f_Decl, std::function<void(lang::cc::Node::Stmt::Expr_T)> f_Expr, std::function<void(lang::cc::Node::Stmt::Block_T)> f_Block, std::function<void(lang::cc::Node::Stmt::If_T)> f_If, std::function<void(lang::cc::Node::Stmt::IfElse_T)> f_IfElse, std::function<void(lang::cc::Node::Stmt::For_T)> f_For, std::function<void(lang::cc::Node::Stmt::Switch_T)> f_Switch, std::function<void(lang::cc::Node::Stmt::Break_T)> f_Break, std::function<void(lang::cc::Node::Stmt::Continue_T)> f_Continue, std::function<void(lang::cc::Node::Stmt::Return_T)> f_Return);
        template<typename RetT> RetT match_expr(std::function<RetT(lang::cc::Node::Stmt::Decl_T)> f_Decl, std::function<RetT(lang::cc::Node::Stmt::Expr_T)> f_Expr, std::function<RetT(lang::cc::Node::Stmt::Block_T)> f_Block, std::function<RetT(lang::cc::Node::Stmt::If_T)> f_If, std::function<RetT(lang::cc::Node::Stmt::IfElse_T)> f_IfElse, std::function<RetT(lang::cc::Node::Stmt::For_T)> f_For, std::function<RetT(lang::cc::Node::Stmt::Switch_T)> f_Switch, std::function<RetT(lang::cc::Node::Stmt::Break_T)> f_Break, std::function<RetT(lang::cc::Node::Stmt::Continue_T)> f_Continue, std::function<RetT(lang::cc::Node::Stmt::Return_T)> f_Return);
        void hash_ser_acc_lang_cc_Node_Stmt(langcc::SerBuf& buf) const;
        virtual void hash_ser_acc(langcc::SerBuf& buf) const = 0;
    };
}

template<typename RetT> RetT lang::cc::Node::Stmt::_T::match_expr(std::function<RetT(lang::cc::Node::Stmt::Decl_T)> f_Decl, std::function<RetT(lang::cc::Node::Stmt::Expr_T)> f_Expr, std::function<RetT(lang::cc::Node::Stmt::Block_T)> f_Block, std::function<RetT(lang::cc::Node::Stmt::If_T)> f_If, std::function<RetT(lang::cc::Node::Stmt::IfElse_T)> f_IfElse, std::function<RetT(lang::cc::Node::Stmt::For_T)> f_For, std::function<RetT(lang::cc::Node::Stmt::Switch_T)> f_Switch, std::function<RetT(lang::cc::Node::Stmt::Break_T)> f_Break, std::function<RetT(lang::cc::Node::Stmt::Continue_T)> f_Continue, std::function<RetT(lang::cc::Node::Stmt::Return_T)> f_Return) {
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
            langcc::AX();
        }
    }
}

namespace langcc {
    void pr_debug(ostream& os, FmtFlags flags, lang::cc::Node::ExprExt_T x);
}

namespace lang::cc::Node::ExprExt {
    enum struct _W {
        Expr,
        Decl,
    };
}

namespace lang::cc::Node::ExprExt {
    struct _T: lang::cc::Node::_T {
        void write(langcc::Ref<std::ostream> os, langcc::FmtFlags flags);
        void write(langcc::Ref<langcc::PrBufStream_T> pb);
        lang::cc::Node::ExprExt::_W w_;
        virtual ~_T();
        _T(lang::cc::Node::ExprExt::_W w);
        bool is_Expr() const;
        bool is_Decl() const;
        lang::cc::Node::ExprExt::Expr_T as_Expr();
        const lang::cc::Node::ExprExt::Expr_T as_Expr() const;
        lang::cc::Node::ExprExt::Decl_T as_Decl();
        const lang::cc::Node::ExprExt::Decl_T as_Decl() const;
        void match(std::function<void(lang::cc::Node::ExprExt::Expr_T)> f_Expr, std::function<void(lang::cc::Node::ExprExt::Decl_T)> f_Decl);
        template<typename RetT> RetT match_expr(std::function<RetT(lang::cc::Node::ExprExt::Expr_T)> f_Expr, std::function<RetT(lang::cc::Node::ExprExt::Decl_T)> f_Decl);
        void hash_ser_acc_lang_cc_Node_ExprExt(langcc::SerBuf& buf) const;
        virtual void hash_ser_acc(langcc::SerBuf& buf) const = 0;
    };
}

template<typename RetT> RetT lang::cc::Node::ExprExt::_T::match_expr(std::function<RetT(lang::cc::Node::ExprExt::Expr_T)> f_Expr, std::function<RetT(lang::cc::Node::ExprExt::Decl_T)> f_Decl) {
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
            langcc::AX();
        }
    }
}

namespace langcc {
    void pr_debug(ostream& os, FmtFlags flags, lang::cc::Node::SwitchCase_T x);
}

namespace lang::cc::Node::SwitchCase {
    enum struct _W {
        Case,
        Default,
    };
}

namespace lang::cc::Node::SwitchCase {
    struct _T: lang::cc::Node::_T {
        void write(langcc::Ref<std::ostream> os, langcc::FmtFlags flags);
        void write(langcc::Ref<langcc::PrBufStream_T> pb);
        lang::cc::Node::SwitchCase::_W w_;
        virtual ~_T();
        _T(lang::cc::Node::SwitchCase::_W w);
        bool is_Case() const;
        bool is_Default() const;
        lang::cc::Node::SwitchCase::Case_T as_Case();
        const lang::cc::Node::SwitchCase::Case_T as_Case() const;
        lang::cc::Node::SwitchCase::Default_T as_Default();
        const lang::cc::Node::SwitchCase::Default_T as_Default() const;
        void match(std::function<void(lang::cc::Node::SwitchCase::Case_T)> f_Case, std::function<void(lang::cc::Node::SwitchCase::Default_T)> f_Default);
        template<typename RetT> RetT match_expr(std::function<RetT(lang::cc::Node::SwitchCase::Case_T)> f_Case, std::function<RetT(lang::cc::Node::SwitchCase::Default_T)> f_Default);
        void hash_ser_acc_lang_cc_Node_SwitchCase(langcc::SerBuf& buf) const;
        virtual void hash_ser_acc(langcc::SerBuf& buf) const = 0;
    };
}

template<typename RetT> RetT lang::cc::Node::SwitchCase::_T::match_expr(std::function<RetT(lang::cc::Node::SwitchCase::Case_T)> f_Case, std::function<RetT(lang::cc::Node::SwitchCase::Default_T)> f_Default) {
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
            langcc::AX();
        }
    }
}

namespace langcc {
    void pr_debug(ostream& os, FmtFlags flags, lang::cc::Node::Expr_T x);
}

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
        void write(langcc::Ref<std::ostream> os, langcc::FmtFlags flags);
        void write(langcc::Ref<langcc::PrBufStream_T> pb);
        lang::cc::Node::Expr::_W w_;
        virtual ~_T();
        _T(lang::cc::Node::Expr::_W w);
        bool is_Paren() const;
        bool is_Call() const;
        bool is_Index() const;
        bool is_IndexEmpty() const;
        bool is_Dot() const;
        bool is_Arrow() const;
        bool is_Ref_() const;
        bool is_AddrOf() const;
        bool is_Deref() const;
        bool is_UnaryPre() const;
        bool is_IncDecPre() const;
        bool is_IncDecPost() const;
        bool is_Assign() const;
        bool is_Bin1() const;
        bool is_Bin2() const;
        bool is_Bin3() const;
        bool is_Bin4() const;
        bool is_Bin5() const;
        bool is_Bin6() const;
        bool is_Template() const;
        bool is_New() const;
        bool is_Delete() const;
        bool is_Ellipsis() const;
        bool is_Tilde() const;
        bool is_Namespace() const;
        bool is_Id() const;
        bool is_Lit() const;
        lang::cc::Node::Expr::Paren_T as_Paren();
        const lang::cc::Node::Expr::Paren_T as_Paren() const;
        lang::cc::Node::Expr::Call_T as_Call();
        const lang::cc::Node::Expr::Call_T as_Call() const;
        lang::cc::Node::Expr::Index_T as_Index();
        const lang::cc::Node::Expr::Index_T as_Index() const;
        lang::cc::Node::Expr::IndexEmpty_T as_IndexEmpty();
        const lang::cc::Node::Expr::IndexEmpty_T as_IndexEmpty() const;
        lang::cc::Node::Expr::Dot_T as_Dot();
        const lang::cc::Node::Expr::Dot_T as_Dot() const;
        lang::cc::Node::Expr::Arrow_T as_Arrow();
        const lang::cc::Node::Expr::Arrow_T as_Arrow() const;
        lang::cc::Node::Expr::Ref__T as_Ref_();
        const lang::cc::Node::Expr::Ref__T as_Ref_() const;
        lang::cc::Node::Expr::AddrOf_T as_AddrOf();
        const lang::cc::Node::Expr::AddrOf_T as_AddrOf() const;
        lang::cc::Node::Expr::Deref_T as_Deref();
        const lang::cc::Node::Expr::Deref_T as_Deref() const;
        lang::cc::Node::Expr::UnaryPre_T as_UnaryPre();
        const lang::cc::Node::Expr::UnaryPre_T as_UnaryPre() const;
        lang::cc::Node::Expr::IncDecPre_T as_IncDecPre();
        const lang::cc::Node::Expr::IncDecPre_T as_IncDecPre() const;
        lang::cc::Node::Expr::IncDecPost_T as_IncDecPost();
        const lang::cc::Node::Expr::IncDecPost_T as_IncDecPost() const;
        lang::cc::Node::Expr::Assign_T as_Assign();
        const lang::cc::Node::Expr::Assign_T as_Assign() const;
        lang::cc::Node::Expr::Bin1_T as_Bin1();
        const lang::cc::Node::Expr::Bin1_T as_Bin1() const;
        lang::cc::Node::Expr::Bin2_T as_Bin2();
        const lang::cc::Node::Expr::Bin2_T as_Bin2() const;
        lang::cc::Node::Expr::Bin3_T as_Bin3();
        const lang::cc::Node::Expr::Bin3_T as_Bin3() const;
        lang::cc::Node::Expr::Bin4_T as_Bin4();
        const lang::cc::Node::Expr::Bin4_T as_Bin4() const;
        lang::cc::Node::Expr::Bin5_T as_Bin5();
        const lang::cc::Node::Expr::Bin5_T as_Bin5() const;
        lang::cc::Node::Expr::Bin6_T as_Bin6();
        const lang::cc::Node::Expr::Bin6_T as_Bin6() const;
        lang::cc::Node::Expr::Template_T as_Template();
        const lang::cc::Node::Expr::Template_T as_Template() const;
        lang::cc::Node::Expr::New_T as_New();
        const lang::cc::Node::Expr::New_T as_New() const;
        lang::cc::Node::Expr::Delete_T as_Delete();
        const lang::cc::Node::Expr::Delete_T as_Delete() const;
        lang::cc::Node::Expr::Ellipsis_T as_Ellipsis();
        const lang::cc::Node::Expr::Ellipsis_T as_Ellipsis() const;
        lang::cc::Node::Expr::Tilde_T as_Tilde();
        const lang::cc::Node::Expr::Tilde_T as_Tilde() const;
        lang::cc::Node::Expr::Namespace_T as_Namespace();
        const lang::cc::Node::Expr::Namespace_T as_Namespace() const;
        lang::cc::Node::Expr::Id_T as_Id();
        const lang::cc::Node::Expr::Id_T as_Id() const;
        lang::cc::Node::Expr::Lit_T as_Lit();
        const lang::cc::Node::Expr::Lit_T as_Lit() const;
        void match(std::function<void(lang::cc::Node::Expr::Paren_T)> f_Paren, std::function<void(lang::cc::Node::Expr::Call_T)> f_Call, std::function<void(lang::cc::Node::Expr::Index_T)> f_Index, std::function<void(lang::cc::Node::Expr::IndexEmpty_T)> f_IndexEmpty, std::function<void(lang::cc::Node::Expr::Dot_T)> f_Dot, std::function<void(lang::cc::Node::Expr::Arrow_T)> f_Arrow, std::function<void(lang::cc::Node::Expr::Ref__T)> f_Ref_, std::function<void(lang::cc::Node::Expr::AddrOf_T)> f_AddrOf, std::function<void(lang::cc::Node::Expr::Deref_T)> f_Deref, std::function<void(lang::cc::Node::Expr::UnaryPre_T)> f_UnaryPre, std::function<void(lang::cc::Node::Expr::IncDecPre_T)> f_IncDecPre, std::function<void(lang::cc::Node::Expr::IncDecPost_T)> f_IncDecPost, std::function<void(lang::cc::Node::Expr::Assign_T)> f_Assign, std::function<void(lang::cc::Node::Expr::Bin1_T)> f_Bin1, std::function<void(lang::cc::Node::Expr::Bin2_T)> f_Bin2, std::function<void(lang::cc::Node::Expr::Bin3_T)> f_Bin3, std::function<void(lang::cc::Node::Expr::Bin4_T)> f_Bin4, std::function<void(lang::cc::Node::Expr::Bin5_T)> f_Bin5, std::function<void(lang::cc::Node::Expr::Bin6_T)> f_Bin6, std::function<void(lang::cc::Node::Expr::Template_T)> f_Template, std::function<void(lang::cc::Node::Expr::New_T)> f_New, std::function<void(lang::cc::Node::Expr::Delete_T)> f_Delete, std::function<void(lang::cc::Node::Expr::Ellipsis_T)> f_Ellipsis, std::function<void(lang::cc::Node::Expr::Tilde_T)> f_Tilde, std::function<void(lang::cc::Node::Expr::Namespace_T)> f_Namespace, std::function<void(lang::cc::Node::Expr::Id_T)> f_Id, std::function<void(lang::cc::Node::Expr::Lit_T)> f_Lit);
        template<typename RetT> RetT match_expr(std::function<RetT(lang::cc::Node::Expr::Paren_T)> f_Paren, std::function<RetT(lang::cc::Node::Expr::Call_T)> f_Call, std::function<RetT(lang::cc::Node::Expr::Index_T)> f_Index, std::function<RetT(lang::cc::Node::Expr::IndexEmpty_T)> f_IndexEmpty, std::function<RetT(lang::cc::Node::Expr::Dot_T)> f_Dot, std::function<RetT(lang::cc::Node::Expr::Arrow_T)> f_Arrow, std::function<RetT(lang::cc::Node::Expr::Ref__T)> f_Ref_, std::function<RetT(lang::cc::Node::Expr::AddrOf_T)> f_AddrOf, std::function<RetT(lang::cc::Node::Expr::Deref_T)> f_Deref, std::function<RetT(lang::cc::Node::Expr::UnaryPre_T)> f_UnaryPre, std::function<RetT(lang::cc::Node::Expr::IncDecPre_T)> f_IncDecPre, std::function<RetT(lang::cc::Node::Expr::IncDecPost_T)> f_IncDecPost, std::function<RetT(lang::cc::Node::Expr::Assign_T)> f_Assign, std::function<RetT(lang::cc::Node::Expr::Bin1_T)> f_Bin1, std::function<RetT(lang::cc::Node::Expr::Bin2_T)> f_Bin2, std::function<RetT(lang::cc::Node::Expr::Bin3_T)> f_Bin3, std::function<RetT(lang::cc::Node::Expr::Bin4_T)> f_Bin4, std::function<RetT(lang::cc::Node::Expr::Bin5_T)> f_Bin5, std::function<RetT(lang::cc::Node::Expr::Bin6_T)> f_Bin6, std::function<RetT(lang::cc::Node::Expr::Template_T)> f_Template, std::function<RetT(lang::cc::Node::Expr::New_T)> f_New, std::function<RetT(lang::cc::Node::Expr::Delete_T)> f_Delete, std::function<RetT(lang::cc::Node::Expr::Ellipsis_T)> f_Ellipsis, std::function<RetT(lang::cc::Node::Expr::Tilde_T)> f_Tilde, std::function<RetT(lang::cc::Node::Expr::Namespace_T)> f_Namespace, std::function<RetT(lang::cc::Node::Expr::Id_T)> f_Id, std::function<RetT(lang::cc::Node::Expr::Lit_T)> f_Lit);
        void hash_ser_acc_lang_cc_Node_Expr(langcc::SerBuf& buf) const;
        virtual void hash_ser_acc(langcc::SerBuf& buf) const = 0;
    };
}

template<typename RetT> RetT lang::cc::Node::Expr::_T::match_expr(std::function<RetT(lang::cc::Node::Expr::Paren_T)> f_Paren, std::function<RetT(lang::cc::Node::Expr::Call_T)> f_Call, std::function<RetT(lang::cc::Node::Expr::Index_T)> f_Index, std::function<RetT(lang::cc::Node::Expr::IndexEmpty_T)> f_IndexEmpty, std::function<RetT(lang::cc::Node::Expr::Dot_T)> f_Dot, std::function<RetT(lang::cc::Node::Expr::Arrow_T)> f_Arrow, std::function<RetT(lang::cc::Node::Expr::Ref__T)> f_Ref_, std::function<RetT(lang::cc::Node::Expr::AddrOf_T)> f_AddrOf, std::function<RetT(lang::cc::Node::Expr::Deref_T)> f_Deref, std::function<RetT(lang::cc::Node::Expr::UnaryPre_T)> f_UnaryPre, std::function<RetT(lang::cc::Node::Expr::IncDecPre_T)> f_IncDecPre, std::function<RetT(lang::cc::Node::Expr::IncDecPost_T)> f_IncDecPost, std::function<RetT(lang::cc::Node::Expr::Assign_T)> f_Assign, std::function<RetT(lang::cc::Node::Expr::Bin1_T)> f_Bin1, std::function<RetT(lang::cc::Node::Expr::Bin2_T)> f_Bin2, std::function<RetT(lang::cc::Node::Expr::Bin3_T)> f_Bin3, std::function<RetT(lang::cc::Node::Expr::Bin4_T)> f_Bin4, std::function<RetT(lang::cc::Node::Expr::Bin5_T)> f_Bin5, std::function<RetT(lang::cc::Node::Expr::Bin6_T)> f_Bin6, std::function<RetT(lang::cc::Node::Expr::Template_T)> f_Template, std::function<RetT(lang::cc::Node::Expr::New_T)> f_New, std::function<RetT(lang::cc::Node::Expr::Delete_T)> f_Delete, std::function<RetT(lang::cc::Node::Expr::Ellipsis_T)> f_Ellipsis, std::function<RetT(lang::cc::Node::Expr::Tilde_T)> f_Tilde, std::function<RetT(lang::cc::Node::Expr::Namespace_T)> f_Namespace, std::function<RetT(lang::cc::Node::Expr::Id_T)> f_Id, std::function<RetT(lang::cc::Node::Expr::Lit_T)> f_Lit) {
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
            langcc::AX();
        }
    }
}

namespace langcc {
    void pr_debug(ostream& os, FmtFlags flags, lang::cc::Node::Decl::Struct_T x);
}

namespace lang::cc::Node::Decl::Struct {
    lang::cc::Node::Decl::Struct_T make(langcc::Int id, langcc::TokenBounds bounds, bool is_top, langcc::ParserSymId sym, langcc::ParserAttrMask attr, langcc::ParserLookahead first_k, langcc::Vec_T<lang::cc::Node::Decl::Struct::tmpl::item_T> tmpl, lang::cc::Node::Expr_T name, lang::cc::Node::StructDeclDef_T body);
}

namespace lang::cc::Node::Decl::Struct {
    lang::cc::Node::Decl::Struct_T make_ext(langcc::ArenaPtr arena, langcc::Int id, langcc::TokenBounds bounds, bool is_top, langcc::ParserSymId sym, langcc::ParserAttrMask attr, langcc::ParserLookahead first_k, langcc::Vec_T<lang::cc::Node::Decl::Struct::tmpl::item_T> tmpl, lang::cc::Node::Expr_T name, lang::cc::Node::StructDeclDef_T body);
}

namespace lang::cc::Node::Decl::Struct {
    struct _T: lang::cc::Node::Decl::_T {
        void write(langcc::Ref<std::ostream> os, langcc::FmtFlags flags);
        void write(langcc::Ref<langcc::PrBufStream_T> pb);
        langcc::Vec_T<lang::cc::Node::Decl::Struct::tmpl::item_T> tmpl_;
        lang::cc::Node::Expr_T name_;
        lang::cc::Node::StructDeclDef_T body_;
        _T();
        lang::cc::Node::Decl::Struct_T with_id(langcc::Int id);
        lang::cc::Node::Decl::Struct_T with_bounds(langcc::TokenBounds bounds);
        lang::cc::Node::Decl::Struct_T with_is_top(bool is_top);
        lang::cc::Node::Decl::Struct_T with_sym(langcc::ParserSymId sym);
        lang::cc::Node::Decl::Struct_T with_attr(langcc::ParserAttrMask attr);
        lang::cc::Node::Decl::Struct_T with_first_k(langcc::ParserLookahead first_k);
        lang::cc::Node::Decl::Struct_T with_tmpl(langcc::Vec_T<lang::cc::Node::Decl::Struct::tmpl::item_T> tmpl);
        lang::cc::Node::Decl::Struct_T with_name(lang::cc::Node::Expr_T name);
        lang::cc::Node::Decl::Struct_T with_body(lang::cc::Node::StructDeclDef_T body);
        void hash_ser_acc_lang_cc_Node_Decl_Struct(langcc::SerBuf& buf) const;
        virtual void hash_ser_acc(langcc::SerBuf& buf) const;
    };
}

namespace langcc {
    void pr_debug(ostream& os, FmtFlags flags, lang::cc::Node::StructDeclDef::Decl_T x);
}

namespace lang::cc::Node::StructDeclDef::Decl {
    lang::cc::Node::StructDeclDef::Decl_T make(langcc::Int id, langcc::TokenBounds bounds, bool is_top, langcc::ParserSymId sym, langcc::ParserAttrMask attr, langcc::ParserLookahead first_k);
}

namespace lang::cc::Node::StructDeclDef::Decl {
    lang::cc::Node::StructDeclDef::Decl_T make_ext(langcc::ArenaPtr arena, langcc::Int id, langcc::TokenBounds bounds, bool is_top, langcc::ParserSymId sym, langcc::ParserAttrMask attr, langcc::ParserLookahead first_k);
}

namespace lang::cc::Node::StructDeclDef::Decl {
    struct _T: lang::cc::Node::StructDeclDef::_T {
        void write(langcc::Ref<std::ostream> os, langcc::FmtFlags flags);
        void write(langcc::Ref<langcc::PrBufStream_T> pb);
        _T();
        lang::cc::Node::StructDeclDef::Decl_T with_id(langcc::Int id);
        lang::cc::Node::StructDeclDef::Decl_T with_bounds(langcc::TokenBounds bounds);
        lang::cc::Node::StructDeclDef::Decl_T with_is_top(bool is_top);
        lang::cc::Node::StructDeclDef::Decl_T with_sym(langcc::ParserSymId sym);
        lang::cc::Node::StructDeclDef::Decl_T with_attr(langcc::ParserAttrMask attr);
        lang::cc::Node::StructDeclDef::Decl_T with_first_k(langcc::ParserLookahead first_k);
        void hash_ser_acc_lang_cc_Node_StructDeclDef_Decl(langcc::SerBuf& buf) const;
        virtual void hash_ser_acc(langcc::SerBuf& buf) const;
    };
}

namespace langcc {
    void pr_debug(ostream& os, FmtFlags flags, lang::cc::Node::StructDeclDef::Def_T x);
}

namespace lang::cc::Node::StructDeclDef::Def {
    lang::cc::Node::StructDeclDef::Def_T make(langcc::Int id, langcc::TokenBounds bounds, bool is_top, langcc::ParserSymId sym, langcc::ParserAttrMask attr, langcc::ParserLookahead first_k, langcc::Option_T<langcc::Vec_T<lang::cc::Node::Expr_T>> base, langcc::Vec_T<lang::cc::Node::Entry_T> entries);
}

namespace lang::cc::Node::StructDeclDef::Def {
    lang::cc::Node::StructDeclDef::Def_T make_ext(langcc::ArenaPtr arena, langcc::Int id, langcc::TokenBounds bounds, bool is_top, langcc::ParserSymId sym, langcc::ParserAttrMask attr, langcc::ParserLookahead first_k, langcc::Option_T<langcc::Vec_T<lang::cc::Node::Expr_T>> base, langcc::Vec_T<lang::cc::Node::Entry_T> entries);
}

namespace lang::cc::Node::StructDeclDef::Def {
    struct _T: lang::cc::Node::StructDeclDef::_T {
        void write(langcc::Ref<std::ostream> os, langcc::FmtFlags flags);
        void write(langcc::Ref<langcc::PrBufStream_T> pb);
        langcc::Option_T<langcc::Vec_T<lang::cc::Node::Expr_T>> base_;
        langcc::Vec_T<lang::cc::Node::Entry_T> entries_;
        _T();
        lang::cc::Node::StructDeclDef::Def_T with_id(langcc::Int id);
        lang::cc::Node::StructDeclDef::Def_T with_bounds(langcc::TokenBounds bounds);
        lang::cc::Node::StructDeclDef::Def_T with_is_top(bool is_top);
        lang::cc::Node::StructDeclDef::Def_T with_sym(langcc::ParserSymId sym);
        lang::cc::Node::StructDeclDef::Def_T with_attr(langcc::ParserAttrMask attr);
        lang::cc::Node::StructDeclDef::Def_T with_first_k(langcc::ParserLookahead first_k);
        lang::cc::Node::StructDeclDef::Def_T with_base(langcc::Option_T<langcc::Vec_T<lang::cc::Node::Expr_T>> base);
        lang::cc::Node::StructDeclDef::Def_T with_entries(langcc::Vec_T<lang::cc::Node::Entry_T> entries);
        void hash_ser_acc_lang_cc_Node_StructDeclDef_Def(langcc::SerBuf& buf) const;
        virtual void hash_ser_acc(langcc::SerBuf& buf) const;
    };
}

namespace langcc {
    void pr_debug(ostream& os, FmtFlags flags, lang::cc::Node::Entry::Field_T x);
}

namespace lang::cc::Node::Entry::Field {
    lang::cc::Node::Entry::Field_T make(langcc::Int id, langcc::TokenBounds bounds, bool is_top, langcc::ParserSymId sym, langcc::ParserAttrMask attr, langcc::ParserLookahead first_k, lang::cc::Node::Expr_T type_, lang::cc::Node::Expr_T name);
}

namespace lang::cc::Node::Entry::Field {
    lang::cc::Node::Entry::Field_T make_ext(langcc::ArenaPtr arena, langcc::Int id, langcc::TokenBounds bounds, bool is_top, langcc::ParserSymId sym, langcc::ParserAttrMask attr, langcc::ParserLookahead first_k, lang::cc::Node::Expr_T type_, lang::cc::Node::Expr_T name);
}

namespace lang::cc::Node::Entry::Field {
    struct _T: lang::cc::Node::Entry::_T {
        void write(langcc::Ref<std::ostream> os, langcc::FmtFlags flags);
        void write(langcc::Ref<langcc::PrBufStream_T> pb);
        lang::cc::Node::Expr_T type__;
        lang::cc::Node::Expr_T name_;
        _T();
        lang::cc::Node::Entry::Field_T with_id(langcc::Int id);
        lang::cc::Node::Entry::Field_T with_bounds(langcc::TokenBounds bounds);
        lang::cc::Node::Entry::Field_T with_is_top(bool is_top);
        lang::cc::Node::Entry::Field_T with_sym(langcc::ParserSymId sym);
        lang::cc::Node::Entry::Field_T with_attr(langcc::ParserAttrMask attr);
        lang::cc::Node::Entry::Field_T with_first_k(langcc::ParserLookahead first_k);
        lang::cc::Node::Entry::Field_T with_type_(lang::cc::Node::Expr_T type_);
        lang::cc::Node::Entry::Field_T with_name(lang::cc::Node::Expr_T name);
        void hash_ser_acc_lang_cc_Node_Entry_Field(langcc::SerBuf& buf) const;
        virtual void hash_ser_acc(langcc::SerBuf& buf) const;
    };
}

namespace langcc {
    void pr_debug(ostream& os, FmtFlags flags, lang::cc::Node::Entry::Fun_T x);
}

namespace lang::cc::Node::Entry::Fun {
    lang::cc::Node::Entry::Fun_T make(langcc::Int id, langcc::TokenBounds bounds, bool is_top, langcc::ParserSymId sym, langcc::ParserAttrMask attr, langcc::ParserLookahead first_k, langcc::Vec_T<lang::cc::Node::Entry::Fun::tmpl::item_T> tmpl, langcc::Vec_T<lang::cc::Node::Mod_T> mods, langcc::Option_T<lang::cc::Node::Expr_T> ret_type, lang::cc::Node::Expr_T name, langcc::Vec_T<lang::cc::Node::Param_T> params, langcc::Vec_T<lang::cc::Node::Mod_T> mods_post, lang::cc::Node::FunDeclDef_T body);
}

namespace lang::cc::Node::Entry::Fun {
    lang::cc::Node::Entry::Fun_T make_ext(langcc::ArenaPtr arena, langcc::Int id, langcc::TokenBounds bounds, bool is_top, langcc::ParserSymId sym, langcc::ParserAttrMask attr, langcc::ParserLookahead first_k, langcc::Vec_T<lang::cc::Node::Entry::Fun::tmpl::item_T> tmpl, langcc::Vec_T<lang::cc::Node::Mod_T> mods, langcc::Option_T<lang::cc::Node::Expr_T> ret_type, lang::cc::Node::Expr_T name, langcc::Vec_T<lang::cc::Node::Param_T> params, langcc::Vec_T<lang::cc::Node::Mod_T> mods_post, lang::cc::Node::FunDeclDef_T body);
}

namespace lang::cc::Node::Entry::Fun {
    struct _T: lang::cc::Node::Entry::_T {
        void write(langcc::Ref<std::ostream> os, langcc::FmtFlags flags);
        void write(langcc::Ref<langcc::PrBufStream_T> pb);
        langcc::Vec_T<lang::cc::Node::Entry::Fun::tmpl::item_T> tmpl_;
        langcc::Vec_T<lang::cc::Node::Mod_T> mods_;
        langcc::Option_T<lang::cc::Node::Expr_T> ret_type_;
        lang::cc::Node::Expr_T name_;
        langcc::Vec_T<lang::cc::Node::Param_T> params_;
        langcc::Vec_T<lang::cc::Node::Mod_T> mods_post_;
        lang::cc::Node::FunDeclDef_T body_;
        _T();
        lang::cc::Node::Entry::Fun_T with_id(langcc::Int id);
        lang::cc::Node::Entry::Fun_T with_bounds(langcc::TokenBounds bounds);
        lang::cc::Node::Entry::Fun_T with_is_top(bool is_top);
        lang::cc::Node::Entry::Fun_T with_sym(langcc::ParserSymId sym);
        lang::cc::Node::Entry::Fun_T with_attr(langcc::ParserAttrMask attr);
        lang::cc::Node::Entry::Fun_T with_first_k(langcc::ParserLookahead first_k);
        lang::cc::Node::Entry::Fun_T with_tmpl(langcc::Vec_T<lang::cc::Node::Entry::Fun::tmpl::item_T> tmpl);
        lang::cc::Node::Entry::Fun_T with_mods(langcc::Vec_T<lang::cc::Node::Mod_T> mods);
        lang::cc::Node::Entry::Fun_T with_ret_type(langcc::Option_T<lang::cc::Node::Expr_T> ret_type);
        lang::cc::Node::Entry::Fun_T with_name(lang::cc::Node::Expr_T name);
        lang::cc::Node::Entry::Fun_T with_params(langcc::Vec_T<lang::cc::Node::Param_T> params);
        lang::cc::Node::Entry::Fun_T with_mods_post(langcc::Vec_T<lang::cc::Node::Mod_T> mods_post);
        lang::cc::Node::Entry::Fun_T with_body(lang::cc::Node::FunDeclDef_T body);
        void hash_ser_acc_lang_cc_Node_Entry_Fun(langcc::SerBuf& buf) const;
        virtual void hash_ser_acc(langcc::SerBuf& buf) const;
    };
}

namespace langcc {
    void pr_debug(ostream& os, FmtFlags flags, lang::cc::Node::Param::val_T x);
}

namespace lang::cc::Node::Param::val {
    lang::cc::Node::Param::val_T make(langcc::Int id, langcc::TokenBounds bounds, bool is_top, langcc::ParserSymId sym, langcc::ParserAttrMask attr, langcc::ParserLookahead first_k, lang::cc::Node::Expr_T init_val);
}

namespace lang::cc::Node::Param::val {
    lang::cc::Node::Param::val_T make_ext(langcc::ArenaPtr arena, langcc::Int id, langcc::TokenBounds bounds, bool is_top, langcc::ParserSymId sym, langcc::ParserAttrMask attr, langcc::ParserLookahead first_k, lang::cc::Node::Expr_T init_val);
}

namespace lang::cc::Node::Param::val {
    struct _T: lang::cc::Node::_T {
        void write(langcc::Ref<std::ostream> os, langcc::FmtFlags flags);
        void write(langcc::Ref<langcc::PrBufStream_T> pb);
        lang::cc::Node::Expr_T init_val_;
        _T();
        lang::cc::Node::Param::val_T with_id(langcc::Int id);
        lang::cc::Node::Param::val_T with_bounds(langcc::TokenBounds bounds);
        lang::cc::Node::Param::val_T with_is_top(bool is_top);
        lang::cc::Node::Param::val_T with_sym(langcc::ParserSymId sym);
        lang::cc::Node::Param::val_T with_attr(langcc::ParserAttrMask attr);
        lang::cc::Node::Param::val_T with_first_k(langcc::ParserLookahead first_k);
        lang::cc::Node::Param::val_T with_init_val(lang::cc::Node::Expr_T init_val);
        void hash_ser_acc_lang_cc_Node_Param_val(langcc::SerBuf& buf) const;
        virtual void hash_ser_acc(langcc::SerBuf& buf) const;
    };
}

namespace langcc {
    void pr_debug(ostream& os, FmtFlags flags, lang::cc::Node::FunDeclDef::Decl_T x);
}

namespace lang::cc::Node::FunDeclDef::Decl {
    lang::cc::Node::FunDeclDef::Decl_T make(langcc::Int id, langcc::TokenBounds bounds, bool is_top, langcc::ParserSymId sym, langcc::ParserAttrMask attr, langcc::ParserLookahead first_k);
}

namespace lang::cc::Node::FunDeclDef::Decl {
    lang::cc::Node::FunDeclDef::Decl_T make_ext(langcc::ArenaPtr arena, langcc::Int id, langcc::TokenBounds bounds, bool is_top, langcc::ParserSymId sym, langcc::ParserAttrMask attr, langcc::ParserLookahead first_k);
}

namespace lang::cc::Node::FunDeclDef::Decl {
    struct _T: lang::cc::Node::FunDeclDef::_T {
        void write(langcc::Ref<std::ostream> os, langcc::FmtFlags flags);
        void write(langcc::Ref<langcc::PrBufStream_T> pb);
        _T();
        lang::cc::Node::FunDeclDef::Decl_T with_id(langcc::Int id);
        lang::cc::Node::FunDeclDef::Decl_T with_bounds(langcc::TokenBounds bounds);
        lang::cc::Node::FunDeclDef::Decl_T with_is_top(bool is_top);
        lang::cc::Node::FunDeclDef::Decl_T with_sym(langcc::ParserSymId sym);
        lang::cc::Node::FunDeclDef::Decl_T with_attr(langcc::ParserAttrMask attr);
        lang::cc::Node::FunDeclDef::Decl_T with_first_k(langcc::ParserLookahead first_k);
        void hash_ser_acc_lang_cc_Node_FunDeclDef_Decl(langcc::SerBuf& buf) const;
        virtual void hash_ser_acc(langcc::SerBuf& buf) const;
    };
}

namespace langcc {
    void pr_debug(ostream& os, FmtFlags flags, lang::cc::Node::FunDeclDef::Def_T x);
}

namespace lang::cc::Node::FunDeclDef::Def {
    lang::cc::Node::FunDeclDef::Def_T make(langcc::Int id, langcc::TokenBounds bounds, bool is_top, langcc::ParserSymId sym, langcc::ParserAttrMask attr, langcc::ParserLookahead first_k, langcc::Option_T<langcc::Vec_T<lang::cc::Node::Expr_T>> init, lang::cc::Node::Block_T body);
}

namespace lang::cc::Node::FunDeclDef::Def {
    lang::cc::Node::FunDeclDef::Def_T make_ext(langcc::ArenaPtr arena, langcc::Int id, langcc::TokenBounds bounds, bool is_top, langcc::ParserSymId sym, langcc::ParserAttrMask attr, langcc::ParserLookahead first_k, langcc::Option_T<langcc::Vec_T<lang::cc::Node::Expr_T>> init, lang::cc::Node::Block_T body);
}

namespace lang::cc::Node::FunDeclDef::Def {
    struct _T: lang::cc::Node::FunDeclDef::_T {
        void write(langcc::Ref<std::ostream> os, langcc::FmtFlags flags);
        void write(langcc::Ref<langcc::PrBufStream_T> pb);
        langcc::Option_T<langcc::Vec_T<lang::cc::Node::Expr_T>> init_;
        lang::cc::Node::Block_T body_;
        _T();
        lang::cc::Node::FunDeclDef::Def_T with_id(langcc::Int id);
        lang::cc::Node::FunDeclDef::Def_T with_bounds(langcc::TokenBounds bounds);
        lang::cc::Node::FunDeclDef::Def_T with_is_top(bool is_top);
        lang::cc::Node::FunDeclDef::Def_T with_sym(langcc::ParserSymId sym);
        lang::cc::Node::FunDeclDef::Def_T with_attr(langcc::ParserAttrMask attr);
        lang::cc::Node::FunDeclDef::Def_T with_first_k(langcc::ParserLookahead first_k);
        lang::cc::Node::FunDeclDef::Def_T with_init(langcc::Option_T<langcc::Vec_T<lang::cc::Node::Expr_T>> init);
        lang::cc::Node::FunDeclDef::Def_T with_body(lang::cc::Node::Block_T body);
        void hash_ser_acc_lang_cc_Node_FunDeclDef_Def(langcc::SerBuf& buf) const;
        virtual void hash_ser_acc(langcc::SerBuf& buf) const;
    };
}

namespace langcc {
    void pr_debug(ostream& os, FmtFlags flags, lang::cc::Node::FunDeclDef::Del_T x);
}

namespace lang::cc::Node::FunDeclDef::Del {
    lang::cc::Node::FunDeclDef::Del_T make(langcc::Int id, langcc::TokenBounds bounds, bool is_top, langcc::ParserSymId sym, langcc::ParserAttrMask attr, langcc::ParserLookahead first_k);
}

namespace lang::cc::Node::FunDeclDef::Del {
    lang::cc::Node::FunDeclDef::Del_T make_ext(langcc::ArenaPtr arena, langcc::Int id, langcc::TokenBounds bounds, bool is_top, langcc::ParserSymId sym, langcc::ParserAttrMask attr, langcc::ParserLookahead first_k);
}

namespace lang::cc::Node::FunDeclDef::Del {
    struct _T: lang::cc::Node::FunDeclDef::_T {
        void write(langcc::Ref<std::ostream> os, langcc::FmtFlags flags);
        void write(langcc::Ref<langcc::PrBufStream_T> pb);
        _T();
        lang::cc::Node::FunDeclDef::Del_T with_id(langcc::Int id);
        lang::cc::Node::FunDeclDef::Del_T with_bounds(langcc::TokenBounds bounds);
        lang::cc::Node::FunDeclDef::Del_T with_is_top(bool is_top);
        lang::cc::Node::FunDeclDef::Del_T with_sym(langcc::ParserSymId sym);
        lang::cc::Node::FunDeclDef::Del_T with_attr(langcc::ParserAttrMask attr);
        lang::cc::Node::FunDeclDef::Del_T with_first_k(langcc::ParserLookahead first_k);
        void hash_ser_acc_lang_cc_Node_FunDeclDef_Del(langcc::SerBuf& buf) const;
        virtual void hash_ser_acc(langcc::SerBuf& buf) const;
    };
}

namespace langcc {
    void pr_debug(ostream& os, FmtFlags flags, lang::cc::Node::FunDeclDef::Zero_T x);
}

namespace lang::cc::Node::FunDeclDef::Zero {
    lang::cc::Node::FunDeclDef::Zero_T make(langcc::Int id, langcc::TokenBounds bounds, bool is_top, langcc::ParserSymId sym, langcc::ParserAttrMask attr, langcc::ParserLookahead first_k, langcc::StrSlice val);
}

namespace lang::cc::Node::FunDeclDef::Zero {
    lang::cc::Node::FunDeclDef::Zero_T make_ext(langcc::ArenaPtr arena, langcc::Int id, langcc::TokenBounds bounds, bool is_top, langcc::ParserSymId sym, langcc::ParserAttrMask attr, langcc::ParserLookahead first_k, langcc::StrSlice val);
}

namespace lang::cc::Node::FunDeclDef::Zero {
    struct _T: lang::cc::Node::FunDeclDef::_T {
        void write(langcc::Ref<std::ostream> os, langcc::FmtFlags flags);
        void write(langcc::Ref<langcc::PrBufStream_T> pb);
        langcc::StrSlice val_;
        _T();
        lang::cc::Node::FunDeclDef::Zero_T with_id(langcc::Int id);
        lang::cc::Node::FunDeclDef::Zero_T with_bounds(langcc::TokenBounds bounds);
        lang::cc::Node::FunDeclDef::Zero_T with_is_top(bool is_top);
        lang::cc::Node::FunDeclDef::Zero_T with_sym(langcc::ParserSymId sym);
        lang::cc::Node::FunDeclDef::Zero_T with_attr(langcc::ParserAttrMask attr);
        lang::cc::Node::FunDeclDef::Zero_T with_first_k(langcc::ParserLookahead first_k);
        lang::cc::Node::FunDeclDef::Zero_T with_val(langcc::StrSlice val);
        void hash_ser_acc_lang_cc_Node_FunDeclDef_Zero(langcc::SerBuf& buf) const;
        virtual void hash_ser_acc(langcc::SerBuf& buf) const;
    };
}

namespace langcc {
    void pr_debug(ostream& os, FmtFlags flags, lang::cc::Node::Decl::EnumStruct_T x);
}

namespace lang::cc::Node::Decl::EnumStruct {
    lang::cc::Node::Decl::EnumStruct_T make(langcc::Int id, langcc::TokenBounds bounds, bool is_top, langcc::ParserSymId sym, langcc::ParserAttrMask attr, langcc::ParserLookahead first_k, lang::cc::Node::Expr_T name, langcc::Vec_T<lang::cc::Node::Expr_T> cases);
}

namespace lang::cc::Node::Decl::EnumStruct {
    lang::cc::Node::Decl::EnumStruct_T make_ext(langcc::ArenaPtr arena, langcc::Int id, langcc::TokenBounds bounds, bool is_top, langcc::ParserSymId sym, langcc::ParserAttrMask attr, langcc::ParserLookahead first_k, lang::cc::Node::Expr_T name, langcc::Vec_T<lang::cc::Node::Expr_T> cases);
}

namespace lang::cc::Node::Decl::EnumStruct {
    struct _T: lang::cc::Node::Decl::_T {
        void write(langcc::Ref<std::ostream> os, langcc::FmtFlags flags);
        void write(langcc::Ref<langcc::PrBufStream_T> pb);
        lang::cc::Node::Expr_T name_;
        langcc::Vec_T<lang::cc::Node::Expr_T> cases_;
        _T();
        lang::cc::Node::Decl::EnumStruct_T with_id(langcc::Int id);
        lang::cc::Node::Decl::EnumStruct_T with_bounds(langcc::TokenBounds bounds);
        lang::cc::Node::Decl::EnumStruct_T with_is_top(bool is_top);
        lang::cc::Node::Decl::EnumStruct_T with_sym(langcc::ParserSymId sym);
        lang::cc::Node::Decl::EnumStruct_T with_attr(langcc::ParserAttrMask attr);
        lang::cc::Node::Decl::EnumStruct_T with_first_k(langcc::ParserLookahead first_k);
        lang::cc::Node::Decl::EnumStruct_T with_name(lang::cc::Node::Expr_T name);
        lang::cc::Node::Decl::EnumStruct_T with_cases(langcc::Vec_T<lang::cc::Node::Expr_T> cases);
        void hash_ser_acc_lang_cc_Node_Decl_EnumStruct(langcc::SerBuf& buf) const;
        virtual void hash_ser_acc(langcc::SerBuf& buf) const;
    };
}

namespace langcc {
    void pr_debug(ostream& os, FmtFlags flags, lang::cc::Node::Decl::Fun_T x);
}

namespace lang::cc::Node::Decl::Fun {
    lang::cc::Node::Decl::Fun_T make(langcc::Int id, langcc::TokenBounds bounds, bool is_top, langcc::ParserSymId sym, langcc::ParserAttrMask attr, langcc::ParserLookahead first_k, langcc::Vec_T<lang::cc::Node::Decl::Fun::tmpl::item_T> tmpl, langcc::Vec_T<lang::cc::Node::Mod_T> mods, langcc::Option_T<lang::cc::Node::Expr_T> ret_type, lang::cc::Node::Expr_T name, langcc::Vec_T<lang::cc::Node::Param_T> params, langcc::Vec_T<lang::cc::Node::Mod_T> mods_post, lang::cc::Node::FunDeclDef_T body);
}

namespace lang::cc::Node::Decl::Fun {
    lang::cc::Node::Decl::Fun_T make_ext(langcc::ArenaPtr arena, langcc::Int id, langcc::TokenBounds bounds, bool is_top, langcc::ParserSymId sym, langcc::ParserAttrMask attr, langcc::ParserLookahead first_k, langcc::Vec_T<lang::cc::Node::Decl::Fun::tmpl::item_T> tmpl, langcc::Vec_T<lang::cc::Node::Mod_T> mods, langcc::Option_T<lang::cc::Node::Expr_T> ret_type, lang::cc::Node::Expr_T name, langcc::Vec_T<lang::cc::Node::Param_T> params, langcc::Vec_T<lang::cc::Node::Mod_T> mods_post, lang::cc::Node::FunDeclDef_T body);
}

namespace lang::cc::Node::Decl::Fun {
    struct _T: lang::cc::Node::Decl::_T {
        void write(langcc::Ref<std::ostream> os, langcc::FmtFlags flags);
        void write(langcc::Ref<langcc::PrBufStream_T> pb);
        langcc::Vec_T<lang::cc::Node::Decl::Fun::tmpl::item_T> tmpl_;
        langcc::Vec_T<lang::cc::Node::Mod_T> mods_;
        langcc::Option_T<lang::cc::Node::Expr_T> ret_type_;
        lang::cc::Node::Expr_T name_;
        langcc::Vec_T<lang::cc::Node::Param_T> params_;
        langcc::Vec_T<lang::cc::Node::Mod_T> mods_post_;
        lang::cc::Node::FunDeclDef_T body_;
        _T();
        lang::cc::Node::Decl::Fun_T with_id(langcc::Int id);
        lang::cc::Node::Decl::Fun_T with_bounds(langcc::TokenBounds bounds);
        lang::cc::Node::Decl::Fun_T with_is_top(bool is_top);
        lang::cc::Node::Decl::Fun_T with_sym(langcc::ParserSymId sym);
        lang::cc::Node::Decl::Fun_T with_attr(langcc::ParserAttrMask attr);
        lang::cc::Node::Decl::Fun_T with_first_k(langcc::ParserLookahead first_k);
        lang::cc::Node::Decl::Fun_T with_tmpl(langcc::Vec_T<lang::cc::Node::Decl::Fun::tmpl::item_T> tmpl);
        lang::cc::Node::Decl::Fun_T with_mods(langcc::Vec_T<lang::cc::Node::Mod_T> mods);
        lang::cc::Node::Decl::Fun_T with_ret_type(langcc::Option_T<lang::cc::Node::Expr_T> ret_type);
        lang::cc::Node::Decl::Fun_T with_name(lang::cc::Node::Expr_T name);
        lang::cc::Node::Decl::Fun_T with_params(langcc::Vec_T<lang::cc::Node::Param_T> params);
        lang::cc::Node::Decl::Fun_T with_mods_post(langcc::Vec_T<lang::cc::Node::Mod_T> mods_post);
        lang::cc::Node::Decl::Fun_T with_body(lang::cc::Node::FunDeclDef_T body);
        void hash_ser_acc_lang_cc_Node_Decl_Fun(langcc::SerBuf& buf) const;
        virtual void hash_ser_acc(langcc::SerBuf& buf) const;
    };
}

namespace langcc {
    void pr_debug(ostream& os, FmtFlags flags, lang::cc::Node::Mod::Const_T x);
}

namespace lang::cc::Node::Mod::Const {
    lang::cc::Node::Mod::Const_T make(langcc::Int id, langcc::TokenBounds bounds, bool is_top, langcc::ParserSymId sym, langcc::ParserAttrMask attr, langcc::ParserLookahead first_k);
}

namespace lang::cc::Node::Mod::Const {
    lang::cc::Node::Mod::Const_T make_ext(langcc::ArenaPtr arena, langcc::Int id, langcc::TokenBounds bounds, bool is_top, langcc::ParserSymId sym, langcc::ParserAttrMask attr, langcc::ParserLookahead first_k);
}

namespace lang::cc::Node::Mod::Const {
    struct _T: lang::cc::Node::Mod::_T {
        void write(langcc::Ref<std::ostream> os, langcc::FmtFlags flags);
        void write(langcc::Ref<langcc::PrBufStream_T> pb);
        _T();
        lang::cc::Node::Mod::Const_T with_id(langcc::Int id);
        lang::cc::Node::Mod::Const_T with_bounds(langcc::TokenBounds bounds);
        lang::cc::Node::Mod::Const_T with_is_top(bool is_top);
        lang::cc::Node::Mod::Const_T with_sym(langcc::ParserSymId sym);
        lang::cc::Node::Mod::Const_T with_attr(langcc::ParserAttrMask attr);
        lang::cc::Node::Mod::Const_T with_first_k(langcc::ParserLookahead first_k);
        void hash_ser_acc_lang_cc_Node_Mod_Const(langcc::SerBuf& buf) const;
        virtual void hash_ser_acc(langcc::SerBuf& buf) const;
    };
}

namespace langcc {
    void pr_debug(ostream& os, FmtFlags flags, lang::cc::Node::Mod::Inline_T x);
}

namespace lang::cc::Node::Mod::Inline {
    lang::cc::Node::Mod::Inline_T make(langcc::Int id, langcc::TokenBounds bounds, bool is_top, langcc::ParserSymId sym, langcc::ParserAttrMask attr, langcc::ParserLookahead first_k);
}

namespace lang::cc::Node::Mod::Inline {
    lang::cc::Node::Mod::Inline_T make_ext(langcc::ArenaPtr arena, langcc::Int id, langcc::TokenBounds bounds, bool is_top, langcc::ParserSymId sym, langcc::ParserAttrMask attr, langcc::ParserLookahead first_k);
}

namespace lang::cc::Node::Mod::Inline {
    struct _T: lang::cc::Node::Mod::_T {
        void write(langcc::Ref<std::ostream> os, langcc::FmtFlags flags);
        void write(langcc::Ref<langcc::PrBufStream_T> pb);
        _T();
        lang::cc::Node::Mod::Inline_T with_id(langcc::Int id);
        lang::cc::Node::Mod::Inline_T with_bounds(langcc::TokenBounds bounds);
        lang::cc::Node::Mod::Inline_T with_is_top(bool is_top);
        lang::cc::Node::Mod::Inline_T with_sym(langcc::ParserSymId sym);
        lang::cc::Node::Mod::Inline_T with_attr(langcc::ParserAttrMask attr);
        lang::cc::Node::Mod::Inline_T with_first_k(langcc::ParserLookahead first_k);
        void hash_ser_acc_lang_cc_Node_Mod_Inline(langcc::SerBuf& buf) const;
        virtual void hash_ser_acc(langcc::SerBuf& buf) const;
    };
}

namespace langcc {
    void pr_debug(ostream& os, FmtFlags flags, lang::cc::Node::Mod::Static_T x);
}

namespace lang::cc::Node::Mod::Static {
    lang::cc::Node::Mod::Static_T make(langcc::Int id, langcc::TokenBounds bounds, bool is_top, langcc::ParserSymId sym, langcc::ParserAttrMask attr, langcc::ParserLookahead first_k);
}

namespace lang::cc::Node::Mod::Static {
    lang::cc::Node::Mod::Static_T make_ext(langcc::ArenaPtr arena, langcc::Int id, langcc::TokenBounds bounds, bool is_top, langcc::ParserSymId sym, langcc::ParserAttrMask attr, langcc::ParserLookahead first_k);
}

namespace lang::cc::Node::Mod::Static {
    struct _T: lang::cc::Node::Mod::_T {
        void write(langcc::Ref<std::ostream> os, langcc::FmtFlags flags);
        void write(langcc::Ref<langcc::PrBufStream_T> pb);
        _T();
        lang::cc::Node::Mod::Static_T with_id(langcc::Int id);
        lang::cc::Node::Mod::Static_T with_bounds(langcc::TokenBounds bounds);
        lang::cc::Node::Mod::Static_T with_is_top(bool is_top);
        lang::cc::Node::Mod::Static_T with_sym(langcc::ParserSymId sym);
        lang::cc::Node::Mod::Static_T with_attr(langcc::ParserAttrMask attr);
        lang::cc::Node::Mod::Static_T with_first_k(langcc::ParserLookahead first_k);
        void hash_ser_acc_lang_cc_Node_Mod_Static(langcc::SerBuf& buf) const;
        virtual void hash_ser_acc(langcc::SerBuf& buf) const;
    };
}

namespace langcc {
    void pr_debug(ostream& os, FmtFlags flags, lang::cc::Node::Mod::Virtual_T x);
}

namespace lang::cc::Node::Mod::Virtual {
    lang::cc::Node::Mod::Virtual_T make(langcc::Int id, langcc::TokenBounds bounds, bool is_top, langcc::ParserSymId sym, langcc::ParserAttrMask attr, langcc::ParserLookahead first_k);
}

namespace lang::cc::Node::Mod::Virtual {
    lang::cc::Node::Mod::Virtual_T make_ext(langcc::ArenaPtr arena, langcc::Int id, langcc::TokenBounds bounds, bool is_top, langcc::ParserSymId sym, langcc::ParserAttrMask attr, langcc::ParserLookahead first_k);
}

namespace lang::cc::Node::Mod::Virtual {
    struct _T: lang::cc::Node::Mod::_T {
        void write(langcc::Ref<std::ostream> os, langcc::FmtFlags flags);
        void write(langcc::Ref<langcc::PrBufStream_T> pb);
        _T();
        lang::cc::Node::Mod::Virtual_T with_id(langcc::Int id);
        lang::cc::Node::Mod::Virtual_T with_bounds(langcc::TokenBounds bounds);
        lang::cc::Node::Mod::Virtual_T with_is_top(bool is_top);
        lang::cc::Node::Mod::Virtual_T with_sym(langcc::ParserSymId sym);
        lang::cc::Node::Mod::Virtual_T with_attr(langcc::ParserAttrMask attr);
        lang::cc::Node::Mod::Virtual_T with_first_k(langcc::ParserLookahead first_k);
        void hash_ser_acc_lang_cc_Node_Mod_Virtual(langcc::SerBuf& buf) const;
        virtual void hash_ser_acc(langcc::SerBuf& buf) const;
    };
}

namespace langcc {
    void pr_debug(ostream& os, FmtFlags flags, lang::cc::Node::Mod::NoInline_T x);
}

namespace lang::cc::Node::Mod::NoInline {
    lang::cc::Node::Mod::NoInline_T make(langcc::Int id, langcc::TokenBounds bounds, bool is_top, langcc::ParserSymId sym, langcc::ParserAttrMask attr, langcc::ParserLookahead first_k);
}

namespace lang::cc::Node::Mod::NoInline {
    lang::cc::Node::Mod::NoInline_T make_ext(langcc::ArenaPtr arena, langcc::Int id, langcc::TokenBounds bounds, bool is_top, langcc::ParserSymId sym, langcc::ParserAttrMask attr, langcc::ParserLookahead first_k);
}

namespace lang::cc::Node::Mod::NoInline {
    struct _T: lang::cc::Node::Mod::_T {
        void write(langcc::Ref<std::ostream> os, langcc::FmtFlags flags);
        void write(langcc::Ref<langcc::PrBufStream_T> pb);
        _T();
        lang::cc::Node::Mod::NoInline_T with_id(langcc::Int id);
        lang::cc::Node::Mod::NoInline_T with_bounds(langcc::TokenBounds bounds);
        lang::cc::Node::Mod::NoInline_T with_is_top(bool is_top);
        lang::cc::Node::Mod::NoInline_T with_sym(langcc::ParserSymId sym);
        lang::cc::Node::Mod::NoInline_T with_attr(langcc::ParserAttrMask attr);
        lang::cc::Node::Mod::NoInline_T with_first_k(langcc::ParserLookahead first_k);
        void hash_ser_acc_lang_cc_Node_Mod_NoInline(langcc::SerBuf& buf) const;
        virtual void hash_ser_acc(langcc::SerBuf& buf) const;
    };
}

namespace langcc {
    void pr_debug(ostream& os, FmtFlags flags, lang::cc::Node::Mod::AlwaysInline_T x);
}

namespace lang::cc::Node::Mod::AlwaysInline {
    lang::cc::Node::Mod::AlwaysInline_T make(langcc::Int id, langcc::TokenBounds bounds, bool is_top, langcc::ParserSymId sym, langcc::ParserAttrMask attr, langcc::ParserLookahead first_k);
}

namespace lang::cc::Node::Mod::AlwaysInline {
    lang::cc::Node::Mod::AlwaysInline_T make_ext(langcc::ArenaPtr arena, langcc::Int id, langcc::TokenBounds bounds, bool is_top, langcc::ParserSymId sym, langcc::ParserAttrMask attr, langcc::ParserLookahead first_k);
}

namespace lang::cc::Node::Mod::AlwaysInline {
    struct _T: lang::cc::Node::Mod::_T {
        void write(langcc::Ref<std::ostream> os, langcc::FmtFlags flags);
        void write(langcc::Ref<langcc::PrBufStream_T> pb);
        _T();
        lang::cc::Node::Mod::AlwaysInline_T with_id(langcc::Int id);
        lang::cc::Node::Mod::AlwaysInline_T with_bounds(langcc::TokenBounds bounds);
        lang::cc::Node::Mod::AlwaysInline_T with_is_top(bool is_top);
        lang::cc::Node::Mod::AlwaysInline_T with_sym(langcc::ParserSymId sym);
        lang::cc::Node::Mod::AlwaysInline_T with_attr(langcc::ParserAttrMask attr);
        lang::cc::Node::Mod::AlwaysInline_T with_first_k(langcc::ParserLookahead first_k);
        void hash_ser_acc_lang_cc_Node_Mod_AlwaysInline(langcc::SerBuf& buf) const;
        virtual void hash_ser_acc(langcc::SerBuf& buf) const;
    };
}

namespace langcc {
    void pr_debug(ostream& os, FmtFlags flags, lang::cc::Node::Mod::Attribute_T x);
}

namespace lang::cc::Node::Mod::Attribute {
    lang::cc::Node::Mod::Attribute_T make(langcc::Int id, langcc::TokenBounds bounds, bool is_top, langcc::ParserSymId sym, langcc::ParserAttrMask attr, langcc::ParserLookahead first_k, langcc::Vec_T<lang::cc::Node::Attribute_T> attrs);
}

namespace lang::cc::Node::Mod::Attribute {
    lang::cc::Node::Mod::Attribute_T make_ext(langcc::ArenaPtr arena, langcc::Int id, langcc::TokenBounds bounds, bool is_top, langcc::ParserSymId sym, langcc::ParserAttrMask attr, langcc::ParserLookahead first_k, langcc::Vec_T<lang::cc::Node::Attribute_T> attrs);
}

namespace lang::cc::Node::Mod::Attribute {
    struct _T: lang::cc::Node::Mod::_T {
        void write(langcc::Ref<std::ostream> os, langcc::FmtFlags flags);
        void write(langcc::Ref<langcc::PrBufStream_T> pb);
        langcc::Vec_T<lang::cc::Node::Attribute_T> attrs_;
        _T();
        lang::cc::Node::Mod::Attribute_T with_id(langcc::Int id);
        lang::cc::Node::Mod::Attribute_T with_bounds(langcc::TokenBounds bounds);
        lang::cc::Node::Mod::Attribute_T with_is_top(bool is_top);
        lang::cc::Node::Mod::Attribute_T with_sym(langcc::ParserSymId sym);
        lang::cc::Node::Mod::Attribute_T with_attr(langcc::ParserAttrMask attr);
        lang::cc::Node::Mod::Attribute_T with_first_k(langcc::ParserLookahead first_k);
        lang::cc::Node::Mod::Attribute_T with_attrs(langcc::Vec_T<lang::cc::Node::Attribute_T> attrs);
        void hash_ser_acc_lang_cc_Node_Mod_Attribute(langcc::SerBuf& buf) const;
        virtual void hash_ser_acc(langcc::SerBuf& buf) const;
    };
}

namespace langcc {
    void pr_debug(ostream& os, FmtFlags flags, lang::cc::Node::Attribute::Simple_T x);
}

namespace lang::cc::Node::Attribute::Simple {
    lang::cc::Node::Attribute::Simple_T make(langcc::Int id, langcc::TokenBounds bounds, bool is_top, langcc::ParserSymId sym, langcc::ParserAttrMask attr, langcc::ParserLookahead first_k, lang::cc::Node::Expr_T name);
}

namespace lang::cc::Node::Attribute::Simple {
    lang::cc::Node::Attribute::Simple_T make_ext(langcc::ArenaPtr arena, langcc::Int id, langcc::TokenBounds bounds, bool is_top, langcc::ParserSymId sym, langcc::ParserAttrMask attr, langcc::ParserLookahead first_k, lang::cc::Node::Expr_T name);
}

namespace lang::cc::Node::Attribute::Simple {
    struct _T: lang::cc::Node::Attribute::_T {
        void write(langcc::Ref<std::ostream> os, langcc::FmtFlags flags);
        void write(langcc::Ref<langcc::PrBufStream_T> pb);
        lang::cc::Node::Expr_T name_;
        _T();
        lang::cc::Node::Attribute::Simple_T with_id(langcc::Int id);
        lang::cc::Node::Attribute::Simple_T with_bounds(langcc::TokenBounds bounds);
        lang::cc::Node::Attribute::Simple_T with_is_top(bool is_top);
        lang::cc::Node::Attribute::Simple_T with_sym(langcc::ParserSymId sym);
        lang::cc::Node::Attribute::Simple_T with_attr(langcc::ParserAttrMask attr);
        lang::cc::Node::Attribute::Simple_T with_first_k(langcc::ParserLookahead first_k);
        lang::cc::Node::Attribute::Simple_T with_name(lang::cc::Node::Expr_T name);
        void hash_ser_acc_lang_cc_Node_Attribute_Simple(langcc::SerBuf& buf) const;
        virtual void hash_ser_acc(langcc::SerBuf& buf) const;
    };
}

namespace langcc {
    void pr_debug(ostream& os, FmtFlags flags, lang::cc::Node::Attribute::Namespaced_T x);
}

namespace lang::cc::Node::Attribute::Namespaced {
    lang::cc::Node::Attribute::Namespaced_T make(langcc::Int id, langcc::TokenBounds bounds, bool is_top, langcc::ParserSymId sym, langcc::ParserAttrMask attr, langcc::ParserLookahead first_k, lang::cc::Node::Expr_T ns, lang::cc::Node::Expr_T name);
}

namespace lang::cc::Node::Attribute::Namespaced {
    lang::cc::Node::Attribute::Namespaced_T make_ext(langcc::ArenaPtr arena, langcc::Int id, langcc::TokenBounds bounds, bool is_top, langcc::ParserSymId sym, langcc::ParserAttrMask attr, langcc::ParserLookahead first_k, lang::cc::Node::Expr_T ns, lang::cc::Node::Expr_T name);
}

namespace lang::cc::Node::Attribute::Namespaced {
    struct _T: lang::cc::Node::Attribute::_T {
        void write(langcc::Ref<std::ostream> os, langcc::FmtFlags flags);
        void write(langcc::Ref<langcc::PrBufStream_T> pb);
        lang::cc::Node::Expr_T ns_;
        lang::cc::Node::Expr_T name_;
        _T();
        lang::cc::Node::Attribute::Namespaced_T with_id(langcc::Int id);
        lang::cc::Node::Attribute::Namespaced_T with_bounds(langcc::TokenBounds bounds);
        lang::cc::Node::Attribute::Namespaced_T with_is_top(bool is_top);
        lang::cc::Node::Attribute::Namespaced_T with_sym(langcc::ParserSymId sym);
        lang::cc::Node::Attribute::Namespaced_T with_attr(langcc::ParserAttrMask attr);
        lang::cc::Node::Attribute::Namespaced_T with_first_k(langcc::ParserLookahead first_k);
        lang::cc::Node::Attribute::Namespaced_T with_ns(lang::cc::Node::Expr_T ns);
        lang::cc::Node::Attribute::Namespaced_T with_name(lang::cc::Node::Expr_T name);
        void hash_ser_acc_lang_cc_Node_Attribute_Namespaced(langcc::SerBuf& buf) const;
        virtual void hash_ser_acc(langcc::SerBuf& buf) const;
    };
}

namespace langcc {
    void pr_debug(ostream& os, FmtFlags flags, lang::cc::Node::Decl::Namespace_T x);
}

namespace lang::cc::Node::Decl::Namespace {
    lang::cc::Node::Decl::Namespace_T make(langcc::Int id, langcc::TokenBounds bounds, bool is_top, langcc::ParserSymId sym, langcc::ParserAttrMask attr, langcc::ParserLookahead first_k, lang::cc::Node::Expr_T name, langcc::Vec_T<lang::cc::Node::Decl_T> body);
}

namespace lang::cc::Node::Decl::Namespace {
    lang::cc::Node::Decl::Namespace_T make_ext(langcc::ArenaPtr arena, langcc::Int id, langcc::TokenBounds bounds, bool is_top, langcc::ParserSymId sym, langcc::ParserAttrMask attr, langcc::ParserLookahead first_k, lang::cc::Node::Expr_T name, langcc::Vec_T<lang::cc::Node::Decl_T> body);
}

namespace lang::cc::Node::Decl::Namespace {
    struct _T: lang::cc::Node::Decl::_T {
        void write(langcc::Ref<std::ostream> os, langcc::FmtFlags flags);
        void write(langcc::Ref<langcc::PrBufStream_T> pb);
        lang::cc::Node::Expr_T name_;
        langcc::Vec_T<lang::cc::Node::Decl_T> body_;
        _T();
        lang::cc::Node::Decl::Namespace_T with_id(langcc::Int id);
        lang::cc::Node::Decl::Namespace_T with_bounds(langcc::TokenBounds bounds);
        lang::cc::Node::Decl::Namespace_T with_is_top(bool is_top);
        lang::cc::Node::Decl::Namespace_T with_sym(langcc::ParserSymId sym);
        lang::cc::Node::Decl::Namespace_T with_attr(langcc::ParserAttrMask attr);
        lang::cc::Node::Decl::Namespace_T with_first_k(langcc::ParserLookahead first_k);
        lang::cc::Node::Decl::Namespace_T with_name(lang::cc::Node::Expr_T name);
        lang::cc::Node::Decl::Namespace_T with_body(langcc::Vec_T<lang::cc::Node::Decl_T> body);
        void hash_ser_acc_lang_cc_Node_Decl_Namespace(langcc::SerBuf& buf) const;
        virtual void hash_ser_acc(langcc::SerBuf& buf) const;
    };
}

namespace langcc {
    void pr_debug(ostream& os, FmtFlags flags, lang::cc::Node::Decl::UsingAlias_T x);
}

namespace lang::cc::Node::Decl::UsingAlias {
    lang::cc::Node::Decl::UsingAlias_T make(langcc::Int id, langcc::TokenBounds bounds, bool is_top, langcc::ParserSymId sym, langcc::ParserAttrMask attr, langcc::ParserLookahead first_k, langcc::Vec_T<lang::cc::Node::Decl::UsingAlias::tmpl::item_T> tmpl, lang::cc::Node::Expr_T name, lang::cc::Node::Expr_T val);
}

namespace lang::cc::Node::Decl::UsingAlias {
    lang::cc::Node::Decl::UsingAlias_T make_ext(langcc::ArenaPtr arena, langcc::Int id, langcc::TokenBounds bounds, bool is_top, langcc::ParserSymId sym, langcc::ParserAttrMask attr, langcc::ParserLookahead first_k, langcc::Vec_T<lang::cc::Node::Decl::UsingAlias::tmpl::item_T> tmpl, lang::cc::Node::Expr_T name, lang::cc::Node::Expr_T val);
}

namespace lang::cc::Node::Decl::UsingAlias {
    struct _T: lang::cc::Node::Decl::_T {
        void write(langcc::Ref<std::ostream> os, langcc::FmtFlags flags);
        void write(langcc::Ref<langcc::PrBufStream_T> pb);
        langcc::Vec_T<lang::cc::Node::Decl::UsingAlias::tmpl::item_T> tmpl_;
        lang::cc::Node::Expr_T name_;
        lang::cc::Node::Expr_T val_;
        _T();
        lang::cc::Node::Decl::UsingAlias_T with_id(langcc::Int id);
        lang::cc::Node::Decl::UsingAlias_T with_bounds(langcc::TokenBounds bounds);
        lang::cc::Node::Decl::UsingAlias_T with_is_top(bool is_top);
        lang::cc::Node::Decl::UsingAlias_T with_sym(langcc::ParserSymId sym);
        lang::cc::Node::Decl::UsingAlias_T with_attr(langcc::ParserAttrMask attr);
        lang::cc::Node::Decl::UsingAlias_T with_first_k(langcc::ParserLookahead first_k);
        lang::cc::Node::Decl::UsingAlias_T with_tmpl(langcc::Vec_T<lang::cc::Node::Decl::UsingAlias::tmpl::item_T> tmpl);
        lang::cc::Node::Decl::UsingAlias_T with_name(lang::cc::Node::Expr_T name);
        lang::cc::Node::Decl::UsingAlias_T with_val(lang::cc::Node::Expr_T val);
        void hash_ser_acc_lang_cc_Node_Decl_UsingAlias(langcc::SerBuf& buf) const;
        virtual void hash_ser_acc(langcc::SerBuf& buf) const;
    };
}

namespace langcc {
    void pr_debug(ostream& os, FmtFlags flags, lang::cc::Node::Decl::UsingNamespace_T x);
}

namespace lang::cc::Node::Decl::UsingNamespace {
    lang::cc::Node::Decl::UsingNamespace_T make(langcc::Int id, langcc::TokenBounds bounds, bool is_top, langcc::ParserSymId sym, langcc::ParserAttrMask attr, langcc::ParserLookahead first_k, lang::cc::Node::Expr_T name);
}

namespace lang::cc::Node::Decl::UsingNamespace {
    lang::cc::Node::Decl::UsingNamespace_T make_ext(langcc::ArenaPtr arena, langcc::Int id, langcc::TokenBounds bounds, bool is_top, langcc::ParserSymId sym, langcc::ParserAttrMask attr, langcc::ParserLookahead first_k, lang::cc::Node::Expr_T name);
}

namespace lang::cc::Node::Decl::UsingNamespace {
    struct _T: lang::cc::Node::Decl::_T {
        void write(langcc::Ref<std::ostream> os, langcc::FmtFlags flags);
        void write(langcc::Ref<langcc::PrBufStream_T> pb);
        lang::cc::Node::Expr_T name_;
        _T();
        lang::cc::Node::Decl::UsingNamespace_T with_id(langcc::Int id);
        lang::cc::Node::Decl::UsingNamespace_T with_bounds(langcc::TokenBounds bounds);
        lang::cc::Node::Decl::UsingNamespace_T with_is_top(bool is_top);
        lang::cc::Node::Decl::UsingNamespace_T with_sym(langcc::ParserSymId sym);
        lang::cc::Node::Decl::UsingNamespace_T with_attr(langcc::ParserAttrMask attr);
        lang::cc::Node::Decl::UsingNamespace_T with_first_k(langcc::ParserLookahead first_k);
        lang::cc::Node::Decl::UsingNamespace_T with_name(lang::cc::Node::Expr_T name);
        void hash_ser_acc_lang_cc_Node_Decl_UsingNamespace(langcc::SerBuf& buf) const;
        virtual void hash_ser_acc(langcc::SerBuf& buf) const;
    };
}

namespace langcc {
    void pr_debug(ostream& os, FmtFlags flags, lang::cc::Node::Decl::Include_T x);
}

namespace lang::cc::Node::Decl::Include {
    lang::cc::Node::Decl::Include_T make(langcc::Int id, langcc::TokenBounds bounds, bool is_top, langcc::ParserSymId sym, langcc::ParserAttrMask attr, langcc::ParserLookahead first_k, langcc::StrSlice x);
}

namespace lang::cc::Node::Decl::Include {
    lang::cc::Node::Decl::Include_T make_ext(langcc::ArenaPtr arena, langcc::Int id, langcc::TokenBounds bounds, bool is_top, langcc::ParserSymId sym, langcc::ParserAttrMask attr, langcc::ParserLookahead first_k, langcc::StrSlice x);
}

namespace lang::cc::Node::Decl::Include {
    struct _T: lang::cc::Node::Decl::_T {
        void write(langcc::Ref<std::ostream> os, langcc::FmtFlags flags);
        void write(langcc::Ref<langcc::PrBufStream_T> pb);
        langcc::StrSlice x_;
        _T();
        lang::cc::Node::Decl::Include_T with_id(langcc::Int id);
        lang::cc::Node::Decl::Include_T with_bounds(langcc::TokenBounds bounds);
        lang::cc::Node::Decl::Include_T with_is_top(bool is_top);
        lang::cc::Node::Decl::Include_T with_sym(langcc::ParserSymId sym);
        lang::cc::Node::Decl::Include_T with_attr(langcc::ParserAttrMask attr);
        lang::cc::Node::Decl::Include_T with_first_k(langcc::ParserLookahead first_k);
        lang::cc::Node::Decl::Include_T with_x(langcc::StrSlice x);
        void hash_ser_acc_lang_cc_Node_Decl_Include(langcc::SerBuf& buf) const;
        virtual void hash_ser_acc(langcc::SerBuf& buf) const;
    };
}

namespace langcc {
    void pr_debug(ostream& os, FmtFlags flags, lang::cc::Node::Decl::PragmaOnce_T x);
}

namespace lang::cc::Node::Decl::PragmaOnce {
    lang::cc::Node::Decl::PragmaOnce_T make(langcc::Int id, langcc::TokenBounds bounds, bool is_top, langcc::ParserSymId sym, langcc::ParserAttrMask attr, langcc::ParserLookahead first_k, langcc::StrSlice x);
}

namespace lang::cc::Node::Decl::PragmaOnce {
    lang::cc::Node::Decl::PragmaOnce_T make_ext(langcc::ArenaPtr arena, langcc::Int id, langcc::TokenBounds bounds, bool is_top, langcc::ParserSymId sym, langcc::ParserAttrMask attr, langcc::ParserLookahead first_k, langcc::StrSlice x);
}

namespace lang::cc::Node::Decl::PragmaOnce {
    struct _T: lang::cc::Node::Decl::_T {
        void write(langcc::Ref<std::ostream> os, langcc::FmtFlags flags);
        void write(langcc::Ref<langcc::PrBufStream_T> pb);
        langcc::StrSlice x_;
        _T();
        lang::cc::Node::Decl::PragmaOnce_T with_id(langcc::Int id);
        lang::cc::Node::Decl::PragmaOnce_T with_bounds(langcc::TokenBounds bounds);
        lang::cc::Node::Decl::PragmaOnce_T with_is_top(bool is_top);
        lang::cc::Node::Decl::PragmaOnce_T with_sym(langcc::ParserSymId sym);
        lang::cc::Node::Decl::PragmaOnce_T with_attr(langcc::ParserAttrMask attr);
        lang::cc::Node::Decl::PragmaOnce_T with_first_k(langcc::ParserLookahead first_k);
        lang::cc::Node::Decl::PragmaOnce_T with_x(langcc::StrSlice x);
        void hash_ser_acc_lang_cc_Node_Decl_PragmaOnce(langcc::SerBuf& buf) const;
        virtual void hash_ser_acc(langcc::SerBuf& buf) const;
    };
}

namespace langcc {
    void pr_debug(ostream& os, FmtFlags flags, lang::cc::Node::Stmt::Decl_T x);
}

namespace lang::cc::Node::Stmt::Decl {
    lang::cc::Node::Stmt::Decl_T make(langcc::Int id, langcc::TokenBounds bounds, bool is_top, langcc::ParserSymId sym, langcc::ParserAttrMask attr, langcc::ParserLookahead first_k, lang::cc::Node::TypedDecl_T decl);
}

namespace lang::cc::Node::Stmt::Decl {
    lang::cc::Node::Stmt::Decl_T make_ext(langcc::ArenaPtr arena, langcc::Int id, langcc::TokenBounds bounds, bool is_top, langcc::ParserSymId sym, langcc::ParserAttrMask attr, langcc::ParserLookahead first_k, lang::cc::Node::TypedDecl_T decl);
}

namespace lang::cc::Node::Stmt::Decl {
    struct _T: lang::cc::Node::Stmt::_T {
        void write(langcc::Ref<std::ostream> os, langcc::FmtFlags flags);
        void write(langcc::Ref<langcc::PrBufStream_T> pb);
        lang::cc::Node::TypedDecl_T decl_;
        _T();
        lang::cc::Node::Stmt::Decl_T with_id(langcc::Int id);
        lang::cc::Node::Stmt::Decl_T with_bounds(langcc::TokenBounds bounds);
        lang::cc::Node::Stmt::Decl_T with_is_top(bool is_top);
        lang::cc::Node::Stmt::Decl_T with_sym(langcc::ParserSymId sym);
        lang::cc::Node::Stmt::Decl_T with_attr(langcc::ParserAttrMask attr);
        lang::cc::Node::Stmt::Decl_T with_first_k(langcc::ParserLookahead first_k);
        lang::cc::Node::Stmt::Decl_T with_decl(lang::cc::Node::TypedDecl_T decl);
        void hash_ser_acc_lang_cc_Node_Stmt_Decl(langcc::SerBuf& buf) const;
        virtual void hash_ser_acc(langcc::SerBuf& buf) const;
    };
}

namespace langcc {
    void pr_debug(ostream& os, FmtFlags flags, lang::cc::Node::Stmt::Expr_T x);
}

namespace lang::cc::Node::Stmt::Expr {
    lang::cc::Node::Stmt::Expr_T make(langcc::Int id, langcc::TokenBounds bounds, bool is_top, langcc::ParserSymId sym, langcc::ParserAttrMask attr, langcc::ParserLookahead first_k, lang::cc::Node::Expr_T e);
}

namespace lang::cc::Node::Stmt::Expr {
    lang::cc::Node::Stmt::Expr_T make_ext(langcc::ArenaPtr arena, langcc::Int id, langcc::TokenBounds bounds, bool is_top, langcc::ParserSymId sym, langcc::ParserAttrMask attr, langcc::ParserLookahead first_k, lang::cc::Node::Expr_T e);
}

namespace lang::cc::Node::Stmt::Expr {
    struct _T: lang::cc::Node::Stmt::_T {
        void write(langcc::Ref<std::ostream> os, langcc::FmtFlags flags);
        void write(langcc::Ref<langcc::PrBufStream_T> pb);
        lang::cc::Node::Expr_T e_;
        _T();
        lang::cc::Node::Stmt::Expr_T with_id(langcc::Int id);
        lang::cc::Node::Stmt::Expr_T with_bounds(langcc::TokenBounds bounds);
        lang::cc::Node::Stmt::Expr_T with_is_top(bool is_top);
        lang::cc::Node::Stmt::Expr_T with_sym(langcc::ParserSymId sym);
        lang::cc::Node::Stmt::Expr_T with_attr(langcc::ParserAttrMask attr);
        lang::cc::Node::Stmt::Expr_T with_first_k(langcc::ParserLookahead first_k);
        lang::cc::Node::Stmt::Expr_T with_e(lang::cc::Node::Expr_T e);
        void hash_ser_acc_lang_cc_Node_Stmt_Expr(langcc::SerBuf& buf) const;
        virtual void hash_ser_acc(langcc::SerBuf& buf) const;
    };
}

namespace langcc {
    void pr_debug(ostream& os, FmtFlags flags, lang::cc::Node::Stmt::Block_T x);
}

namespace lang::cc::Node::Stmt::Block {
    lang::cc::Node::Stmt::Block_T make(langcc::Int id, langcc::TokenBounds bounds, bool is_top, langcc::ParserSymId sym, langcc::ParserAttrMask attr, langcc::ParserLookahead first_k, lang::cc::Node::Block_T block);
}

namespace lang::cc::Node::Stmt::Block {
    lang::cc::Node::Stmt::Block_T make_ext(langcc::ArenaPtr arena, langcc::Int id, langcc::TokenBounds bounds, bool is_top, langcc::ParserSymId sym, langcc::ParserAttrMask attr, langcc::ParserLookahead first_k, lang::cc::Node::Block_T block);
}

namespace lang::cc::Node::Stmt::Block {
    struct _T: lang::cc::Node::Stmt::_T {
        void write(langcc::Ref<std::ostream> os, langcc::FmtFlags flags);
        void write(langcc::Ref<langcc::PrBufStream_T> pb);
        lang::cc::Node::Block_T block_;
        _T();
        lang::cc::Node::Stmt::Block_T with_id(langcc::Int id);
        lang::cc::Node::Stmt::Block_T with_bounds(langcc::TokenBounds bounds);
        lang::cc::Node::Stmt::Block_T with_is_top(bool is_top);
        lang::cc::Node::Stmt::Block_T with_sym(langcc::ParserSymId sym);
        lang::cc::Node::Stmt::Block_T with_attr(langcc::ParserAttrMask attr);
        lang::cc::Node::Stmt::Block_T with_first_k(langcc::ParserLookahead first_k);
        lang::cc::Node::Stmt::Block_T with_block(lang::cc::Node::Block_T block);
        void hash_ser_acc_lang_cc_Node_Stmt_Block(langcc::SerBuf& buf) const;
        virtual void hash_ser_acc(langcc::SerBuf& buf) const;
    };
}

namespace langcc {
    void pr_debug(ostream& os, FmtFlags flags, lang::cc::Node::Stmt::If_T x);
}

namespace lang::cc::Node::Stmt::If {
    lang::cc::Node::Stmt::If_T make(langcc::Int id, langcc::TokenBounds bounds, bool is_top, langcc::ParserSymId sym, langcc::ParserAttrMask attr, langcc::ParserLookahead first_k, lang::cc::Node::Expr_T cond, lang::cc::Node::Stmt_T xt);
}

namespace lang::cc::Node::Stmt::If {
    lang::cc::Node::Stmt::If_T make_ext(langcc::ArenaPtr arena, langcc::Int id, langcc::TokenBounds bounds, bool is_top, langcc::ParserSymId sym, langcc::ParserAttrMask attr, langcc::ParserLookahead first_k, lang::cc::Node::Expr_T cond, lang::cc::Node::Stmt_T xt);
}

namespace lang::cc::Node::Stmt::If {
    struct _T: lang::cc::Node::Stmt::_T {
        void write(langcc::Ref<std::ostream> os, langcc::FmtFlags flags);
        void write(langcc::Ref<langcc::PrBufStream_T> pb);
        lang::cc::Node::Expr_T cond_;
        lang::cc::Node::Stmt_T xt_;
        _T();
        lang::cc::Node::Stmt::If_T with_id(langcc::Int id);
        lang::cc::Node::Stmt::If_T with_bounds(langcc::TokenBounds bounds);
        lang::cc::Node::Stmt::If_T with_is_top(bool is_top);
        lang::cc::Node::Stmt::If_T with_sym(langcc::ParserSymId sym);
        lang::cc::Node::Stmt::If_T with_attr(langcc::ParserAttrMask attr);
        lang::cc::Node::Stmt::If_T with_first_k(langcc::ParserLookahead first_k);
        lang::cc::Node::Stmt::If_T with_cond(lang::cc::Node::Expr_T cond);
        lang::cc::Node::Stmt::If_T with_xt(lang::cc::Node::Stmt_T xt);
        void hash_ser_acc_lang_cc_Node_Stmt_If(langcc::SerBuf& buf) const;
        virtual void hash_ser_acc(langcc::SerBuf& buf) const;
    };
}

namespace langcc {
    void pr_debug(ostream& os, FmtFlags flags, lang::cc::Node::Stmt::IfElse_T x);
}

namespace lang::cc::Node::Stmt::IfElse {
    lang::cc::Node::Stmt::IfElse_T make(langcc::Int id, langcc::TokenBounds bounds, bool is_top, langcc::ParserSymId sym, langcc::ParserAttrMask attr, langcc::ParserLookahead first_k, lang::cc::Node::Expr_T cond, lang::cc::Node::Stmt_T xt, lang::cc::Node::Stmt_T xf);
}

namespace lang::cc::Node::Stmt::IfElse {
    lang::cc::Node::Stmt::IfElse_T make_ext(langcc::ArenaPtr arena, langcc::Int id, langcc::TokenBounds bounds, bool is_top, langcc::ParserSymId sym, langcc::ParserAttrMask attr, langcc::ParserLookahead first_k, lang::cc::Node::Expr_T cond, lang::cc::Node::Stmt_T xt, lang::cc::Node::Stmt_T xf);
}

namespace lang::cc::Node::Stmt::IfElse {
    struct _T: lang::cc::Node::Stmt::_T {
        void write(langcc::Ref<std::ostream> os, langcc::FmtFlags flags);
        void write(langcc::Ref<langcc::PrBufStream_T> pb);
        lang::cc::Node::Expr_T cond_;
        lang::cc::Node::Stmt_T xt_;
        lang::cc::Node::Stmt_T xf_;
        _T();
        lang::cc::Node::Stmt::IfElse_T with_id(langcc::Int id);
        lang::cc::Node::Stmt::IfElse_T with_bounds(langcc::TokenBounds bounds);
        lang::cc::Node::Stmt::IfElse_T with_is_top(bool is_top);
        lang::cc::Node::Stmt::IfElse_T with_sym(langcc::ParserSymId sym);
        lang::cc::Node::Stmt::IfElse_T with_attr(langcc::ParserAttrMask attr);
        lang::cc::Node::Stmt::IfElse_T with_first_k(langcc::ParserLookahead first_k);
        lang::cc::Node::Stmt::IfElse_T with_cond(lang::cc::Node::Expr_T cond);
        lang::cc::Node::Stmt::IfElse_T with_xt(lang::cc::Node::Stmt_T xt);
        lang::cc::Node::Stmt::IfElse_T with_xf(lang::cc::Node::Stmt_T xf);
        void hash_ser_acc_lang_cc_Node_Stmt_IfElse(langcc::SerBuf& buf) const;
        virtual void hash_ser_acc(langcc::SerBuf& buf) const;
    };
}

namespace langcc {
    void pr_debug(ostream& os, FmtFlags flags, lang::cc::Node::Stmt::For_T x);
}

namespace lang::cc::Node::Stmt::For {
    lang::cc::Node::Stmt::For_T make(langcc::Int id, langcc::TokenBounds bounds, bool is_top, langcc::ParserSymId sym, langcc::ParserAttrMask attr, langcc::ParserLookahead first_k, lang::cc::Node::ExprExt_T init, lang::cc::Node::Expr_T cond, lang::cc::Node::Expr_T incr, lang::cc::Node::Block_T body);
}

namespace lang::cc::Node::Stmt::For {
    lang::cc::Node::Stmt::For_T make_ext(langcc::ArenaPtr arena, langcc::Int id, langcc::TokenBounds bounds, bool is_top, langcc::ParserSymId sym, langcc::ParserAttrMask attr, langcc::ParserLookahead first_k, lang::cc::Node::ExprExt_T init, lang::cc::Node::Expr_T cond, lang::cc::Node::Expr_T incr, lang::cc::Node::Block_T body);
}

namespace lang::cc::Node::Stmt::For {
    struct _T: lang::cc::Node::Stmt::_T {
        void write(langcc::Ref<std::ostream> os, langcc::FmtFlags flags);
        void write(langcc::Ref<langcc::PrBufStream_T> pb);
        lang::cc::Node::ExprExt_T init_;
        lang::cc::Node::Expr_T cond_;
        lang::cc::Node::Expr_T incr_;
        lang::cc::Node::Block_T body_;
        _T();
        lang::cc::Node::Stmt::For_T with_id(langcc::Int id);
        lang::cc::Node::Stmt::For_T with_bounds(langcc::TokenBounds bounds);
        lang::cc::Node::Stmt::For_T with_is_top(bool is_top);
        lang::cc::Node::Stmt::For_T with_sym(langcc::ParserSymId sym);
        lang::cc::Node::Stmt::For_T with_attr(langcc::ParserAttrMask attr);
        lang::cc::Node::Stmt::For_T with_first_k(langcc::ParserLookahead first_k);
        lang::cc::Node::Stmt::For_T with_init(lang::cc::Node::ExprExt_T init);
        lang::cc::Node::Stmt::For_T with_cond(lang::cc::Node::Expr_T cond);
        lang::cc::Node::Stmt::For_T with_incr(lang::cc::Node::Expr_T incr);
        lang::cc::Node::Stmt::For_T with_body(lang::cc::Node::Block_T body);
        void hash_ser_acc_lang_cc_Node_Stmt_For(langcc::SerBuf& buf) const;
        virtual void hash_ser_acc(langcc::SerBuf& buf) const;
    };
}

namespace langcc {
    void pr_debug(ostream& os, FmtFlags flags, lang::cc::Node::ExprExt::Expr_T x);
}

namespace lang::cc::Node::ExprExt::Expr {
    lang::cc::Node::ExprExt::Expr_T make(langcc::Int id, langcc::TokenBounds bounds, bool is_top, langcc::ParserSymId sym, langcc::ParserAttrMask attr, langcc::ParserLookahead first_k, lang::cc::Node::Expr_T e);
}

namespace lang::cc::Node::ExprExt::Expr {
    lang::cc::Node::ExprExt::Expr_T make_ext(langcc::ArenaPtr arena, langcc::Int id, langcc::TokenBounds bounds, bool is_top, langcc::ParserSymId sym, langcc::ParserAttrMask attr, langcc::ParserLookahead first_k, lang::cc::Node::Expr_T e);
}

namespace lang::cc::Node::ExprExt::Expr {
    struct _T: lang::cc::Node::ExprExt::_T {
        void write(langcc::Ref<std::ostream> os, langcc::FmtFlags flags);
        void write(langcc::Ref<langcc::PrBufStream_T> pb);
        lang::cc::Node::Expr_T e_;
        _T();
        lang::cc::Node::ExprExt::Expr_T with_id(langcc::Int id);
        lang::cc::Node::ExprExt::Expr_T with_bounds(langcc::TokenBounds bounds);
        lang::cc::Node::ExprExt::Expr_T with_is_top(bool is_top);
        lang::cc::Node::ExprExt::Expr_T with_sym(langcc::ParserSymId sym);
        lang::cc::Node::ExprExt::Expr_T with_attr(langcc::ParserAttrMask attr);
        lang::cc::Node::ExprExt::Expr_T with_first_k(langcc::ParserLookahead first_k);
        lang::cc::Node::ExprExt::Expr_T with_e(lang::cc::Node::Expr_T e);
        void hash_ser_acc_lang_cc_Node_ExprExt_Expr(langcc::SerBuf& buf) const;
        virtual void hash_ser_acc(langcc::SerBuf& buf) const;
    };
}

namespace langcc {
    void pr_debug(ostream& os, FmtFlags flags, lang::cc::Node::ExprExt::Decl_T x);
}

namespace lang::cc::Node::ExprExt::Decl {
    lang::cc::Node::ExprExt::Decl_T make(langcc::Int id, langcc::TokenBounds bounds, bool is_top, langcc::ParserSymId sym, langcc::ParserAttrMask attr, langcc::ParserLookahead first_k, lang::cc::Node::TypedDecl_T decl);
}

namespace lang::cc::Node::ExprExt::Decl {
    lang::cc::Node::ExprExt::Decl_T make_ext(langcc::ArenaPtr arena, langcc::Int id, langcc::TokenBounds bounds, bool is_top, langcc::ParserSymId sym, langcc::ParserAttrMask attr, langcc::ParserLookahead first_k, lang::cc::Node::TypedDecl_T decl);
}

namespace lang::cc::Node::ExprExt::Decl {
    struct _T: lang::cc::Node::ExprExt::_T {
        void write(langcc::Ref<std::ostream> os, langcc::FmtFlags flags);
        void write(langcc::Ref<langcc::PrBufStream_T> pb);
        lang::cc::Node::TypedDecl_T decl_;
        _T();
        lang::cc::Node::ExprExt::Decl_T with_id(langcc::Int id);
        lang::cc::Node::ExprExt::Decl_T with_bounds(langcc::TokenBounds bounds);
        lang::cc::Node::ExprExt::Decl_T with_is_top(bool is_top);
        lang::cc::Node::ExprExt::Decl_T with_sym(langcc::ParserSymId sym);
        lang::cc::Node::ExprExt::Decl_T with_attr(langcc::ParserAttrMask attr);
        lang::cc::Node::ExprExt::Decl_T with_first_k(langcc::ParserLookahead first_k);
        lang::cc::Node::ExprExt::Decl_T with_decl(lang::cc::Node::TypedDecl_T decl);
        void hash_ser_acc_lang_cc_Node_ExprExt_Decl(langcc::SerBuf& buf) const;
        virtual void hash_ser_acc(langcc::SerBuf& buf) const;
    };
}

namespace langcc {
    void pr_debug(ostream& os, FmtFlags flags, lang::cc::Node::Stmt::Switch_T x);
}

namespace lang::cc::Node::Stmt::Switch {
    lang::cc::Node::Stmt::Switch_T make(langcc::Int id, langcc::TokenBounds bounds, bool is_top, langcc::ParserSymId sym, langcc::ParserAttrMask attr, langcc::ParserLookahead first_k, lang::cc::Node::Expr_T val, langcc::Vec_T<lang::cc::Node::SwitchCase_T> cases);
}

namespace lang::cc::Node::Stmt::Switch {
    lang::cc::Node::Stmt::Switch_T make_ext(langcc::ArenaPtr arena, langcc::Int id, langcc::TokenBounds bounds, bool is_top, langcc::ParserSymId sym, langcc::ParserAttrMask attr, langcc::ParserLookahead first_k, lang::cc::Node::Expr_T val, langcc::Vec_T<lang::cc::Node::SwitchCase_T> cases);
}

namespace lang::cc::Node::Stmt::Switch {
    struct _T: lang::cc::Node::Stmt::_T {
        void write(langcc::Ref<std::ostream> os, langcc::FmtFlags flags);
        void write(langcc::Ref<langcc::PrBufStream_T> pb);
        lang::cc::Node::Expr_T val_;
        langcc::Vec_T<lang::cc::Node::SwitchCase_T> cases_;
        _T();
        lang::cc::Node::Stmt::Switch_T with_id(langcc::Int id);
        lang::cc::Node::Stmt::Switch_T with_bounds(langcc::TokenBounds bounds);
        lang::cc::Node::Stmt::Switch_T with_is_top(bool is_top);
        lang::cc::Node::Stmt::Switch_T with_sym(langcc::ParserSymId sym);
        lang::cc::Node::Stmt::Switch_T with_attr(langcc::ParserAttrMask attr);
        lang::cc::Node::Stmt::Switch_T with_first_k(langcc::ParserLookahead first_k);
        lang::cc::Node::Stmt::Switch_T with_val(lang::cc::Node::Expr_T val);
        lang::cc::Node::Stmt::Switch_T with_cases(langcc::Vec_T<lang::cc::Node::SwitchCase_T> cases);
        void hash_ser_acc_lang_cc_Node_Stmt_Switch(langcc::SerBuf& buf) const;
        virtual void hash_ser_acc(langcc::SerBuf& buf) const;
    };
}

namespace langcc {
    void pr_debug(ostream& os, FmtFlags flags, lang::cc::Node::SwitchCase::Case_T x);
}

namespace lang::cc::Node::SwitchCase::Case {
    lang::cc::Node::SwitchCase::Case_T make(langcc::Int id, langcc::TokenBounds bounds, bool is_top, langcc::ParserSymId sym, langcc::ParserAttrMask attr, langcc::ParserLookahead first_k, lang::cc::Node::Expr_T val, lang::cc::Node::Block_T body);
}

namespace lang::cc::Node::SwitchCase::Case {
    lang::cc::Node::SwitchCase::Case_T make_ext(langcc::ArenaPtr arena, langcc::Int id, langcc::TokenBounds bounds, bool is_top, langcc::ParserSymId sym, langcc::ParserAttrMask attr, langcc::ParserLookahead first_k, lang::cc::Node::Expr_T val, lang::cc::Node::Block_T body);
}

namespace lang::cc::Node::SwitchCase::Case {
    struct _T: lang::cc::Node::SwitchCase::_T {
        void write(langcc::Ref<std::ostream> os, langcc::FmtFlags flags);
        void write(langcc::Ref<langcc::PrBufStream_T> pb);
        lang::cc::Node::Expr_T val_;
        lang::cc::Node::Block_T body_;
        _T();
        lang::cc::Node::SwitchCase::Case_T with_id(langcc::Int id);
        lang::cc::Node::SwitchCase::Case_T with_bounds(langcc::TokenBounds bounds);
        lang::cc::Node::SwitchCase::Case_T with_is_top(bool is_top);
        lang::cc::Node::SwitchCase::Case_T with_sym(langcc::ParserSymId sym);
        lang::cc::Node::SwitchCase::Case_T with_attr(langcc::ParserAttrMask attr);
        lang::cc::Node::SwitchCase::Case_T with_first_k(langcc::ParserLookahead first_k);
        lang::cc::Node::SwitchCase::Case_T with_val(lang::cc::Node::Expr_T val);
        lang::cc::Node::SwitchCase::Case_T with_body(lang::cc::Node::Block_T body);
        void hash_ser_acc_lang_cc_Node_SwitchCase_Case(langcc::SerBuf& buf) const;
        virtual void hash_ser_acc(langcc::SerBuf& buf) const;
    };
}

namespace langcc {
    void pr_debug(ostream& os, FmtFlags flags, lang::cc::Node::SwitchCase::Default_T x);
}

namespace lang::cc::Node::SwitchCase::Default {
    lang::cc::Node::SwitchCase::Default_T make(langcc::Int id, langcc::TokenBounds bounds, bool is_top, langcc::ParserSymId sym, langcc::ParserAttrMask attr, langcc::ParserLookahead first_k, lang::cc::Node::Block_T body);
}

namespace lang::cc::Node::SwitchCase::Default {
    lang::cc::Node::SwitchCase::Default_T make_ext(langcc::ArenaPtr arena, langcc::Int id, langcc::TokenBounds bounds, bool is_top, langcc::ParserSymId sym, langcc::ParserAttrMask attr, langcc::ParserLookahead first_k, lang::cc::Node::Block_T body);
}

namespace lang::cc::Node::SwitchCase::Default {
    struct _T: lang::cc::Node::SwitchCase::_T {
        void write(langcc::Ref<std::ostream> os, langcc::FmtFlags flags);
        void write(langcc::Ref<langcc::PrBufStream_T> pb);
        lang::cc::Node::Block_T body_;
        _T();
        lang::cc::Node::SwitchCase::Default_T with_id(langcc::Int id);
        lang::cc::Node::SwitchCase::Default_T with_bounds(langcc::TokenBounds bounds);
        lang::cc::Node::SwitchCase::Default_T with_is_top(bool is_top);
        lang::cc::Node::SwitchCase::Default_T with_sym(langcc::ParserSymId sym);
        lang::cc::Node::SwitchCase::Default_T with_attr(langcc::ParserAttrMask attr);
        lang::cc::Node::SwitchCase::Default_T with_first_k(langcc::ParserLookahead first_k);
        lang::cc::Node::SwitchCase::Default_T with_body(lang::cc::Node::Block_T body);
        void hash_ser_acc_lang_cc_Node_SwitchCase_Default(langcc::SerBuf& buf) const;
        virtual void hash_ser_acc(langcc::SerBuf& buf) const;
    };
}

namespace langcc {
    void pr_debug(ostream& os, FmtFlags flags, lang::cc::Node::Stmt::Break_T x);
}

namespace lang::cc::Node::Stmt::Break {
    lang::cc::Node::Stmt::Break_T make(langcc::Int id, langcc::TokenBounds bounds, bool is_top, langcc::ParserSymId sym, langcc::ParserAttrMask attr, langcc::ParserLookahead first_k);
}

namespace lang::cc::Node::Stmt::Break {
    lang::cc::Node::Stmt::Break_T make_ext(langcc::ArenaPtr arena, langcc::Int id, langcc::TokenBounds bounds, bool is_top, langcc::ParserSymId sym, langcc::ParserAttrMask attr, langcc::ParserLookahead first_k);
}

namespace lang::cc::Node::Stmt::Break {
    struct _T: lang::cc::Node::Stmt::_T {
        void write(langcc::Ref<std::ostream> os, langcc::FmtFlags flags);
        void write(langcc::Ref<langcc::PrBufStream_T> pb);
        _T();
        lang::cc::Node::Stmt::Break_T with_id(langcc::Int id);
        lang::cc::Node::Stmt::Break_T with_bounds(langcc::TokenBounds bounds);
        lang::cc::Node::Stmt::Break_T with_is_top(bool is_top);
        lang::cc::Node::Stmt::Break_T with_sym(langcc::ParserSymId sym);
        lang::cc::Node::Stmt::Break_T with_attr(langcc::ParserAttrMask attr);
        lang::cc::Node::Stmt::Break_T with_first_k(langcc::ParserLookahead first_k);
        void hash_ser_acc_lang_cc_Node_Stmt_Break(langcc::SerBuf& buf) const;
        virtual void hash_ser_acc(langcc::SerBuf& buf) const;
    };
}

namespace langcc {
    void pr_debug(ostream& os, FmtFlags flags, lang::cc::Node::Stmt::Continue_T x);
}

namespace lang::cc::Node::Stmt::Continue {
    lang::cc::Node::Stmt::Continue_T make(langcc::Int id, langcc::TokenBounds bounds, bool is_top, langcc::ParserSymId sym, langcc::ParserAttrMask attr, langcc::ParserLookahead first_k);
}

namespace lang::cc::Node::Stmt::Continue {
    lang::cc::Node::Stmt::Continue_T make_ext(langcc::ArenaPtr arena, langcc::Int id, langcc::TokenBounds bounds, bool is_top, langcc::ParserSymId sym, langcc::ParserAttrMask attr, langcc::ParserLookahead first_k);
}

namespace lang::cc::Node::Stmt::Continue {
    struct _T: lang::cc::Node::Stmt::_T {
        void write(langcc::Ref<std::ostream> os, langcc::FmtFlags flags);
        void write(langcc::Ref<langcc::PrBufStream_T> pb);
        _T();
        lang::cc::Node::Stmt::Continue_T with_id(langcc::Int id);
        lang::cc::Node::Stmt::Continue_T with_bounds(langcc::TokenBounds bounds);
        lang::cc::Node::Stmt::Continue_T with_is_top(bool is_top);
        lang::cc::Node::Stmt::Continue_T with_sym(langcc::ParserSymId sym);
        lang::cc::Node::Stmt::Continue_T with_attr(langcc::ParserAttrMask attr);
        lang::cc::Node::Stmt::Continue_T with_first_k(langcc::ParserLookahead first_k);
        void hash_ser_acc_lang_cc_Node_Stmt_Continue(langcc::SerBuf& buf) const;
        virtual void hash_ser_acc(langcc::SerBuf& buf) const;
    };
}

namespace langcc {
    void pr_debug(ostream& os, FmtFlags flags, lang::cc::Node::Stmt::Return_T x);
}

namespace lang::cc::Node::Stmt::Return {
    lang::cc::Node::Stmt::Return_T make(langcc::Int id, langcc::TokenBounds bounds, bool is_top, langcc::ParserSymId sym, langcc::ParserAttrMask attr, langcc::ParserLookahead first_k, langcc::Option_T<lang::cc::Node::Expr_T> val);
}

namespace lang::cc::Node::Stmt::Return {
    lang::cc::Node::Stmt::Return_T make_ext(langcc::ArenaPtr arena, langcc::Int id, langcc::TokenBounds bounds, bool is_top, langcc::ParserSymId sym, langcc::ParserAttrMask attr, langcc::ParserLookahead first_k, langcc::Option_T<lang::cc::Node::Expr_T> val);
}

namespace lang::cc::Node::Stmt::Return {
    struct _T: lang::cc::Node::Stmt::_T {
        void write(langcc::Ref<std::ostream> os, langcc::FmtFlags flags);
        void write(langcc::Ref<langcc::PrBufStream_T> pb);
        langcc::Option_T<lang::cc::Node::Expr_T> val_;
        _T();
        lang::cc::Node::Stmt::Return_T with_id(langcc::Int id);
        lang::cc::Node::Stmt::Return_T with_bounds(langcc::TokenBounds bounds);
        lang::cc::Node::Stmt::Return_T with_is_top(bool is_top);
        lang::cc::Node::Stmt::Return_T with_sym(langcc::ParserSymId sym);
        lang::cc::Node::Stmt::Return_T with_attr(langcc::ParserAttrMask attr);
        lang::cc::Node::Stmt::Return_T with_first_k(langcc::ParserLookahead first_k);
        lang::cc::Node::Stmt::Return_T with_val(langcc::Option_T<lang::cc::Node::Expr_T> val);
        void hash_ser_acc_lang_cc_Node_Stmt_Return(langcc::SerBuf& buf) const;
        virtual void hash_ser_acc(langcc::SerBuf& buf) const;
    };
}

namespace langcc {
    void pr_debug(ostream& os, FmtFlags flags, lang::cc::Node::Expr::Paren_T x);
}

namespace lang::cc::Node::Expr::Paren {
    lang::cc::Node::Expr::Paren_T make(langcc::Int id, langcc::TokenBounds bounds, bool is_top, langcc::ParserSymId sym, langcc::ParserAttrMask attr, langcc::ParserLookahead first_k, lang::cc::Node::Expr_T x);
}

namespace lang::cc::Node::Expr::Paren {
    lang::cc::Node::Expr::Paren_T make_ext(langcc::ArenaPtr arena, langcc::Int id, langcc::TokenBounds bounds, bool is_top, langcc::ParserSymId sym, langcc::ParserAttrMask attr, langcc::ParserLookahead first_k, lang::cc::Node::Expr_T x);
}

namespace lang::cc::Node::Expr::Paren {
    struct _T: lang::cc::Node::Expr::_T {
        void write(langcc::Ref<std::ostream> os, langcc::FmtFlags flags);
        void write(langcc::Ref<langcc::PrBufStream_T> pb);
        lang::cc::Node::Expr_T x_;
        _T();
        lang::cc::Node::Expr::Paren_T with_id(langcc::Int id);
        lang::cc::Node::Expr::Paren_T with_bounds(langcc::TokenBounds bounds);
        lang::cc::Node::Expr::Paren_T with_is_top(bool is_top);
        lang::cc::Node::Expr::Paren_T with_sym(langcc::ParserSymId sym);
        lang::cc::Node::Expr::Paren_T with_attr(langcc::ParserAttrMask attr);
        lang::cc::Node::Expr::Paren_T with_first_k(langcc::ParserLookahead first_k);
        lang::cc::Node::Expr::Paren_T with_x(lang::cc::Node::Expr_T x);
        void hash_ser_acc_lang_cc_Node_Expr_Paren(langcc::SerBuf& buf) const;
        virtual void hash_ser_acc(langcc::SerBuf& buf) const;
    };
}

namespace langcc {
    void pr_debug(ostream& os, FmtFlags flags, lang::cc::Node::Expr::Call_T x);
}

namespace lang::cc::Node::Expr::Call {
    lang::cc::Node::Expr::Call_T make(langcc::Int id, langcc::TokenBounds bounds, bool is_top, langcc::ParserSymId sym, langcc::ParserAttrMask attr, langcc::ParserLookahead first_k, lang::cc::Node::Expr_T f, langcc::Vec_T<lang::cc::Node::Expr_T> args);
}

namespace lang::cc::Node::Expr::Call {
    lang::cc::Node::Expr::Call_T make_ext(langcc::ArenaPtr arena, langcc::Int id, langcc::TokenBounds bounds, bool is_top, langcc::ParserSymId sym, langcc::ParserAttrMask attr, langcc::ParserLookahead first_k, lang::cc::Node::Expr_T f, langcc::Vec_T<lang::cc::Node::Expr_T> args);
}

namespace lang::cc::Node::Expr::Call {
    struct _T: lang::cc::Node::Expr::_T {
        void write(langcc::Ref<std::ostream> os, langcc::FmtFlags flags);
        void write(langcc::Ref<langcc::PrBufStream_T> pb);
        lang::cc::Node::Expr_T f_;
        langcc::Vec_T<lang::cc::Node::Expr_T> args_;
        _T();
        lang::cc::Node::Expr::Call_T with_id(langcc::Int id);
        lang::cc::Node::Expr::Call_T with_bounds(langcc::TokenBounds bounds);
        lang::cc::Node::Expr::Call_T with_is_top(bool is_top);
        lang::cc::Node::Expr::Call_T with_sym(langcc::ParserSymId sym);
        lang::cc::Node::Expr::Call_T with_attr(langcc::ParserAttrMask attr);
        lang::cc::Node::Expr::Call_T with_first_k(langcc::ParserLookahead first_k);
        lang::cc::Node::Expr::Call_T with_f(lang::cc::Node::Expr_T f);
        lang::cc::Node::Expr::Call_T with_args(langcc::Vec_T<lang::cc::Node::Expr_T> args);
        void hash_ser_acc_lang_cc_Node_Expr_Call(langcc::SerBuf& buf) const;
        virtual void hash_ser_acc(langcc::SerBuf& buf) const;
    };
}

namespace langcc {
    void pr_debug(ostream& os, FmtFlags flags, lang::cc::Node::Expr::Index_T x);
}

namespace lang::cc::Node::Expr::Index {
    lang::cc::Node::Expr::Index_T make(langcc::Int id, langcc::TokenBounds bounds, bool is_top, langcc::ParserSymId sym, langcc::ParserAttrMask attr, langcc::ParserLookahead first_k, lang::cc::Node::Expr_T f, lang::cc::Node::Expr_T arg);
}

namespace lang::cc::Node::Expr::Index {
    lang::cc::Node::Expr::Index_T make_ext(langcc::ArenaPtr arena, langcc::Int id, langcc::TokenBounds bounds, bool is_top, langcc::ParserSymId sym, langcc::ParserAttrMask attr, langcc::ParserLookahead first_k, lang::cc::Node::Expr_T f, lang::cc::Node::Expr_T arg);
}

namespace lang::cc::Node::Expr::Index {
    struct _T: lang::cc::Node::Expr::_T {
        void write(langcc::Ref<std::ostream> os, langcc::FmtFlags flags);
        void write(langcc::Ref<langcc::PrBufStream_T> pb);
        lang::cc::Node::Expr_T f_;
        lang::cc::Node::Expr_T arg_;
        _T();
        lang::cc::Node::Expr::Index_T with_id(langcc::Int id);
        lang::cc::Node::Expr::Index_T with_bounds(langcc::TokenBounds bounds);
        lang::cc::Node::Expr::Index_T with_is_top(bool is_top);
        lang::cc::Node::Expr::Index_T with_sym(langcc::ParserSymId sym);
        lang::cc::Node::Expr::Index_T with_attr(langcc::ParserAttrMask attr);
        lang::cc::Node::Expr::Index_T with_first_k(langcc::ParserLookahead first_k);
        lang::cc::Node::Expr::Index_T with_f(lang::cc::Node::Expr_T f);
        lang::cc::Node::Expr::Index_T with_arg(lang::cc::Node::Expr_T arg);
        void hash_ser_acc_lang_cc_Node_Expr_Index(langcc::SerBuf& buf) const;
        virtual void hash_ser_acc(langcc::SerBuf& buf) const;
    };
}

namespace langcc {
    void pr_debug(ostream& os, FmtFlags flags, lang::cc::Node::Expr::IndexEmpty_T x);
}

namespace lang::cc::Node::Expr::IndexEmpty {
    lang::cc::Node::Expr::IndexEmpty_T make(langcc::Int id, langcc::TokenBounds bounds, bool is_top, langcc::ParserSymId sym, langcc::ParserAttrMask attr, langcc::ParserLookahead first_k, lang::cc::Node::Expr_T f);
}

namespace lang::cc::Node::Expr::IndexEmpty {
    lang::cc::Node::Expr::IndexEmpty_T make_ext(langcc::ArenaPtr arena, langcc::Int id, langcc::TokenBounds bounds, bool is_top, langcc::ParserSymId sym, langcc::ParserAttrMask attr, langcc::ParserLookahead first_k, lang::cc::Node::Expr_T f);
}

namespace lang::cc::Node::Expr::IndexEmpty {
    struct _T: lang::cc::Node::Expr::_T {
        void write(langcc::Ref<std::ostream> os, langcc::FmtFlags flags);
        void write(langcc::Ref<langcc::PrBufStream_T> pb);
        lang::cc::Node::Expr_T f_;
        _T();
        lang::cc::Node::Expr::IndexEmpty_T with_id(langcc::Int id);
        lang::cc::Node::Expr::IndexEmpty_T with_bounds(langcc::TokenBounds bounds);
        lang::cc::Node::Expr::IndexEmpty_T with_is_top(bool is_top);
        lang::cc::Node::Expr::IndexEmpty_T with_sym(langcc::ParserSymId sym);
        lang::cc::Node::Expr::IndexEmpty_T with_attr(langcc::ParserAttrMask attr);
        lang::cc::Node::Expr::IndexEmpty_T with_first_k(langcc::ParserLookahead first_k);
        lang::cc::Node::Expr::IndexEmpty_T with_f(lang::cc::Node::Expr_T f);
        void hash_ser_acc_lang_cc_Node_Expr_IndexEmpty(langcc::SerBuf& buf) const;
        virtual void hash_ser_acc(langcc::SerBuf& buf) const;
    };
}

namespace langcc {
    void pr_debug(ostream& os, FmtFlags flags, lang::cc::Node::Expr::Dot_T x);
}

namespace lang::cc::Node::Expr::Dot {
    lang::cc::Node::Expr::Dot_T make(langcc::Int id, langcc::TokenBounds bounds, bool is_top, langcc::ParserSymId sym, langcc::ParserAttrMask attr, langcc::ParserLookahead first_k, lang::cc::Node::Expr_T x, lang::cc::Node::Expr_T field);
}

namespace lang::cc::Node::Expr::Dot {
    lang::cc::Node::Expr::Dot_T make_ext(langcc::ArenaPtr arena, langcc::Int id, langcc::TokenBounds bounds, bool is_top, langcc::ParserSymId sym, langcc::ParserAttrMask attr, langcc::ParserLookahead first_k, lang::cc::Node::Expr_T x, lang::cc::Node::Expr_T field);
}

namespace lang::cc::Node::Expr::Dot {
    struct _T: lang::cc::Node::Expr::_T {
        void write(langcc::Ref<std::ostream> os, langcc::FmtFlags flags);
        void write(langcc::Ref<langcc::PrBufStream_T> pb);
        lang::cc::Node::Expr_T x_;
        lang::cc::Node::Expr_T field_;
        _T();
        lang::cc::Node::Expr::Dot_T with_id(langcc::Int id);
        lang::cc::Node::Expr::Dot_T with_bounds(langcc::TokenBounds bounds);
        lang::cc::Node::Expr::Dot_T with_is_top(bool is_top);
        lang::cc::Node::Expr::Dot_T with_sym(langcc::ParserSymId sym);
        lang::cc::Node::Expr::Dot_T with_attr(langcc::ParserAttrMask attr);
        lang::cc::Node::Expr::Dot_T with_first_k(langcc::ParserLookahead first_k);
        lang::cc::Node::Expr::Dot_T with_x(lang::cc::Node::Expr_T x);
        lang::cc::Node::Expr::Dot_T with_field(lang::cc::Node::Expr_T field);
        void hash_ser_acc_lang_cc_Node_Expr_Dot(langcc::SerBuf& buf) const;
        virtual void hash_ser_acc(langcc::SerBuf& buf) const;
    };
}

namespace langcc {
    void pr_debug(ostream& os, FmtFlags flags, lang::cc::Node::Expr::Arrow_T x);
}

namespace lang::cc::Node::Expr::Arrow {
    lang::cc::Node::Expr::Arrow_T make(langcc::Int id, langcc::TokenBounds bounds, bool is_top, langcc::ParserSymId sym, langcc::ParserAttrMask attr, langcc::ParserLookahead first_k, lang::cc::Node::Expr_T x, lang::cc::Node::Expr_T field);
}

namespace lang::cc::Node::Expr::Arrow {
    lang::cc::Node::Expr::Arrow_T make_ext(langcc::ArenaPtr arena, langcc::Int id, langcc::TokenBounds bounds, bool is_top, langcc::ParserSymId sym, langcc::ParserAttrMask attr, langcc::ParserLookahead first_k, lang::cc::Node::Expr_T x, lang::cc::Node::Expr_T field);
}

namespace lang::cc::Node::Expr::Arrow {
    struct _T: lang::cc::Node::Expr::_T {
        void write(langcc::Ref<std::ostream> os, langcc::FmtFlags flags);
        void write(langcc::Ref<langcc::PrBufStream_T> pb);
        lang::cc::Node::Expr_T x_;
        lang::cc::Node::Expr_T field_;
        _T();
        lang::cc::Node::Expr::Arrow_T with_id(langcc::Int id);
        lang::cc::Node::Expr::Arrow_T with_bounds(langcc::TokenBounds bounds);
        lang::cc::Node::Expr::Arrow_T with_is_top(bool is_top);
        lang::cc::Node::Expr::Arrow_T with_sym(langcc::ParserSymId sym);
        lang::cc::Node::Expr::Arrow_T with_attr(langcc::ParserAttrMask attr);
        lang::cc::Node::Expr::Arrow_T with_first_k(langcc::ParserLookahead first_k);
        lang::cc::Node::Expr::Arrow_T with_x(lang::cc::Node::Expr_T x);
        lang::cc::Node::Expr::Arrow_T with_field(lang::cc::Node::Expr_T field);
        void hash_ser_acc_lang_cc_Node_Expr_Arrow(langcc::SerBuf& buf) const;
        virtual void hash_ser_acc(langcc::SerBuf& buf) const;
    };
}

namespace langcc {
    void pr_debug(ostream& os, FmtFlags flags, lang::cc::Node::Expr::Ref__T x);
}

namespace lang::cc::Node::Expr::Ref_ {
    lang::cc::Node::Expr::Ref__T make(langcc::Int id, langcc::TokenBounds bounds, bool is_top, langcc::ParserSymId sym, langcc::ParserAttrMask attr, langcc::ParserLookahead first_k, lang::cc::Node::Expr_T x);
}

namespace lang::cc::Node::Expr::Ref_ {
    lang::cc::Node::Expr::Ref__T make_ext(langcc::ArenaPtr arena, langcc::Int id, langcc::TokenBounds bounds, bool is_top, langcc::ParserSymId sym, langcc::ParserAttrMask attr, langcc::ParserLookahead first_k, lang::cc::Node::Expr_T x);
}

namespace lang::cc::Node::Expr::Ref_ {
    struct _T: lang::cc::Node::Expr::_T {
        void write(langcc::Ref<std::ostream> os, langcc::FmtFlags flags);
        void write(langcc::Ref<langcc::PrBufStream_T> pb);
        lang::cc::Node::Expr_T x_;
        _T();
        lang::cc::Node::Expr::Ref__T with_id(langcc::Int id);
        lang::cc::Node::Expr::Ref__T with_bounds(langcc::TokenBounds bounds);
        lang::cc::Node::Expr::Ref__T with_is_top(bool is_top);
        lang::cc::Node::Expr::Ref__T with_sym(langcc::ParserSymId sym);
        lang::cc::Node::Expr::Ref__T with_attr(langcc::ParserAttrMask attr);
        lang::cc::Node::Expr::Ref__T with_first_k(langcc::ParserLookahead first_k);
        lang::cc::Node::Expr::Ref__T with_x(lang::cc::Node::Expr_T x);
        void hash_ser_acc_lang_cc_Node_Expr_Ref_(langcc::SerBuf& buf) const;
        virtual void hash_ser_acc(langcc::SerBuf& buf) const;
    };
}

namespace langcc {
    void pr_debug(ostream& os, FmtFlags flags, lang::cc::Node::Expr::AddrOf_T x);
}

namespace lang::cc::Node::Expr::AddrOf {
    lang::cc::Node::Expr::AddrOf_T make(langcc::Int id, langcc::TokenBounds bounds, bool is_top, langcc::ParserSymId sym, langcc::ParserAttrMask attr, langcc::ParserLookahead first_k, lang::cc::Node::Expr_T x);
}

namespace lang::cc::Node::Expr::AddrOf {
    lang::cc::Node::Expr::AddrOf_T make_ext(langcc::ArenaPtr arena, langcc::Int id, langcc::TokenBounds bounds, bool is_top, langcc::ParserSymId sym, langcc::ParserAttrMask attr, langcc::ParserLookahead first_k, lang::cc::Node::Expr_T x);
}

namespace lang::cc::Node::Expr::AddrOf {
    struct _T: lang::cc::Node::Expr::_T {
        void write(langcc::Ref<std::ostream> os, langcc::FmtFlags flags);
        void write(langcc::Ref<langcc::PrBufStream_T> pb);
        lang::cc::Node::Expr_T x_;
        _T();
        lang::cc::Node::Expr::AddrOf_T with_id(langcc::Int id);
        lang::cc::Node::Expr::AddrOf_T with_bounds(langcc::TokenBounds bounds);
        lang::cc::Node::Expr::AddrOf_T with_is_top(bool is_top);
        lang::cc::Node::Expr::AddrOf_T with_sym(langcc::ParserSymId sym);
        lang::cc::Node::Expr::AddrOf_T with_attr(langcc::ParserAttrMask attr);
        lang::cc::Node::Expr::AddrOf_T with_first_k(langcc::ParserLookahead first_k);
        lang::cc::Node::Expr::AddrOf_T with_x(lang::cc::Node::Expr_T x);
        void hash_ser_acc_lang_cc_Node_Expr_AddrOf(langcc::SerBuf& buf) const;
        virtual void hash_ser_acc(langcc::SerBuf& buf) const;
    };
}

namespace langcc {
    void pr_debug(ostream& os, FmtFlags flags, lang::cc::Node::Expr::Deref_T x);
}

namespace lang::cc::Node::Expr::Deref {
    lang::cc::Node::Expr::Deref_T make(langcc::Int id, langcc::TokenBounds bounds, bool is_top, langcc::ParserSymId sym, langcc::ParserAttrMask attr, langcc::ParserLookahead first_k, lang::cc::Node::Expr_T x);
}

namespace lang::cc::Node::Expr::Deref {
    lang::cc::Node::Expr::Deref_T make_ext(langcc::ArenaPtr arena, langcc::Int id, langcc::TokenBounds bounds, bool is_top, langcc::ParserSymId sym, langcc::ParserAttrMask attr, langcc::ParserLookahead first_k, lang::cc::Node::Expr_T x);
}

namespace lang::cc::Node::Expr::Deref {
    struct _T: lang::cc::Node::Expr::_T {
        void write(langcc::Ref<std::ostream> os, langcc::FmtFlags flags);
        void write(langcc::Ref<langcc::PrBufStream_T> pb);
        lang::cc::Node::Expr_T x_;
        _T();
        lang::cc::Node::Expr::Deref_T with_id(langcc::Int id);
        lang::cc::Node::Expr::Deref_T with_bounds(langcc::TokenBounds bounds);
        lang::cc::Node::Expr::Deref_T with_is_top(bool is_top);
        lang::cc::Node::Expr::Deref_T with_sym(langcc::ParserSymId sym);
        lang::cc::Node::Expr::Deref_T with_attr(langcc::ParserAttrMask attr);
        lang::cc::Node::Expr::Deref_T with_first_k(langcc::ParserLookahead first_k);
        lang::cc::Node::Expr::Deref_T with_x(lang::cc::Node::Expr_T x);
        void hash_ser_acc_lang_cc_Node_Expr_Deref(langcc::SerBuf& buf) const;
        virtual void hash_ser_acc(langcc::SerBuf& buf) const;
    };
}

namespace langcc {
    void pr_debug(ostream& os, FmtFlags flags, lang::cc::Node::Expr::UnaryPre_T x);
}

namespace lang::cc::Node::Expr::UnaryPre {
    lang::cc::Node::Expr::UnaryPre_T make(langcc::Int id, langcc::TokenBounds bounds, bool is_top, langcc::ParserSymId sym, langcc::ParserAttrMask attr, langcc::ParserLookahead first_k, lang::cc::Node::Expr::UnaryPre::op_T op, lang::cc::Node::Expr_T x);
}

namespace lang::cc::Node::Expr::UnaryPre {
    lang::cc::Node::Expr::UnaryPre_T make_ext(langcc::ArenaPtr arena, langcc::Int id, langcc::TokenBounds bounds, bool is_top, langcc::ParserSymId sym, langcc::ParserAttrMask attr, langcc::ParserLookahead first_k, lang::cc::Node::Expr::UnaryPre::op_T op, lang::cc::Node::Expr_T x);
}

namespace lang::cc::Node::Expr::UnaryPre {
    struct _T: lang::cc::Node::Expr::_T {
        void write(langcc::Ref<std::ostream> os, langcc::FmtFlags flags);
        void write(langcc::Ref<langcc::PrBufStream_T> pb);
        lang::cc::Node::Expr::UnaryPre::op_T op_;
        lang::cc::Node::Expr_T x_;
        _T();
        lang::cc::Node::Expr::UnaryPre_T with_id(langcc::Int id);
        lang::cc::Node::Expr::UnaryPre_T with_bounds(langcc::TokenBounds bounds);
        lang::cc::Node::Expr::UnaryPre_T with_is_top(bool is_top);
        lang::cc::Node::Expr::UnaryPre_T with_sym(langcc::ParserSymId sym);
        lang::cc::Node::Expr::UnaryPre_T with_attr(langcc::ParserAttrMask attr);
        lang::cc::Node::Expr::UnaryPre_T with_first_k(langcc::ParserLookahead first_k);
        lang::cc::Node::Expr::UnaryPre_T with_op(lang::cc::Node::Expr::UnaryPre::op_T op);
        lang::cc::Node::Expr::UnaryPre_T with_x(lang::cc::Node::Expr_T x);
        void hash_ser_acc_lang_cc_Node_Expr_UnaryPre(langcc::SerBuf& buf) const;
        virtual void hash_ser_acc(langcc::SerBuf& buf) const;
    };
}

namespace langcc {
    void pr_debug(ostream& os, FmtFlags flags, lang::cc::Node::Expr::IncDecPre_T x);
}

namespace lang::cc::Node::Expr::IncDecPre {
    lang::cc::Node::Expr::IncDecPre_T make(langcc::Int id, langcc::TokenBounds bounds, bool is_top, langcc::ParserSymId sym, langcc::ParserAttrMask attr, langcc::ParserLookahead first_k, lang::cc::Node::Expr::IncDecPre::op_T op, lang::cc::Node::Expr_T x);
}

namespace lang::cc::Node::Expr::IncDecPre {
    lang::cc::Node::Expr::IncDecPre_T make_ext(langcc::ArenaPtr arena, langcc::Int id, langcc::TokenBounds bounds, bool is_top, langcc::ParserSymId sym, langcc::ParserAttrMask attr, langcc::ParserLookahead first_k, lang::cc::Node::Expr::IncDecPre::op_T op, lang::cc::Node::Expr_T x);
}

namespace lang::cc::Node::Expr::IncDecPre {
    struct _T: lang::cc::Node::Expr::_T {
        void write(langcc::Ref<std::ostream> os, langcc::FmtFlags flags);
        void write(langcc::Ref<langcc::PrBufStream_T> pb);
        lang::cc::Node::Expr::IncDecPre::op_T op_;
        lang::cc::Node::Expr_T x_;
        _T();
        lang::cc::Node::Expr::IncDecPre_T with_id(langcc::Int id);
        lang::cc::Node::Expr::IncDecPre_T with_bounds(langcc::TokenBounds bounds);
        lang::cc::Node::Expr::IncDecPre_T with_is_top(bool is_top);
        lang::cc::Node::Expr::IncDecPre_T with_sym(langcc::ParserSymId sym);
        lang::cc::Node::Expr::IncDecPre_T with_attr(langcc::ParserAttrMask attr);
        lang::cc::Node::Expr::IncDecPre_T with_first_k(langcc::ParserLookahead first_k);
        lang::cc::Node::Expr::IncDecPre_T with_op(lang::cc::Node::Expr::IncDecPre::op_T op);
        lang::cc::Node::Expr::IncDecPre_T with_x(lang::cc::Node::Expr_T x);
        void hash_ser_acc_lang_cc_Node_Expr_IncDecPre(langcc::SerBuf& buf) const;
        virtual void hash_ser_acc(langcc::SerBuf& buf) const;
    };
}

namespace langcc {
    void pr_debug(ostream& os, FmtFlags flags, lang::cc::Node::Expr::IncDecPost_T x);
}

namespace lang::cc::Node::Expr::IncDecPost {
    lang::cc::Node::Expr::IncDecPost_T make(langcc::Int id, langcc::TokenBounds bounds, bool is_top, langcc::ParserSymId sym, langcc::ParserAttrMask attr, langcc::ParserLookahead first_k, lang::cc::Node::Expr_T x, lang::cc::Node::Expr::IncDecPost::op_T op);
}

namespace lang::cc::Node::Expr::IncDecPost {
    lang::cc::Node::Expr::IncDecPost_T make_ext(langcc::ArenaPtr arena, langcc::Int id, langcc::TokenBounds bounds, bool is_top, langcc::ParserSymId sym, langcc::ParserAttrMask attr, langcc::ParserLookahead first_k, lang::cc::Node::Expr_T x, lang::cc::Node::Expr::IncDecPost::op_T op);
}

namespace lang::cc::Node::Expr::IncDecPost {
    struct _T: lang::cc::Node::Expr::_T {
        void write(langcc::Ref<std::ostream> os, langcc::FmtFlags flags);
        void write(langcc::Ref<langcc::PrBufStream_T> pb);
        lang::cc::Node::Expr_T x_;
        lang::cc::Node::Expr::IncDecPost::op_T op_;
        _T();
        lang::cc::Node::Expr::IncDecPost_T with_id(langcc::Int id);
        lang::cc::Node::Expr::IncDecPost_T with_bounds(langcc::TokenBounds bounds);
        lang::cc::Node::Expr::IncDecPost_T with_is_top(bool is_top);
        lang::cc::Node::Expr::IncDecPost_T with_sym(langcc::ParserSymId sym);
        lang::cc::Node::Expr::IncDecPost_T with_attr(langcc::ParserAttrMask attr);
        lang::cc::Node::Expr::IncDecPost_T with_first_k(langcc::ParserLookahead first_k);
        lang::cc::Node::Expr::IncDecPost_T with_x(lang::cc::Node::Expr_T x);
        lang::cc::Node::Expr::IncDecPost_T with_op(lang::cc::Node::Expr::IncDecPost::op_T op);
        void hash_ser_acc_lang_cc_Node_Expr_IncDecPost(langcc::SerBuf& buf) const;
        virtual void hash_ser_acc(langcc::SerBuf& buf) const;
    };
}

namespace langcc {
    void pr_debug(ostream& os, FmtFlags flags, lang::cc::Node::Expr::Assign_T x);
}

namespace lang::cc::Node::Expr::Assign {
    lang::cc::Node::Expr::Assign_T make(langcc::Int id, langcc::TokenBounds bounds, bool is_top, langcc::ParserSymId sym, langcc::ParserAttrMask attr, langcc::ParserLookahead first_k, lang::cc::Node::Expr_T xl, lang::cc::Node::Expr_T xr);
}

namespace lang::cc::Node::Expr::Assign {
    lang::cc::Node::Expr::Assign_T make_ext(langcc::ArenaPtr arena, langcc::Int id, langcc::TokenBounds bounds, bool is_top, langcc::ParserSymId sym, langcc::ParserAttrMask attr, langcc::ParserLookahead first_k, lang::cc::Node::Expr_T xl, lang::cc::Node::Expr_T xr);
}

namespace lang::cc::Node::Expr::Assign {
    struct _T: lang::cc::Node::Expr::_T {
        void write(langcc::Ref<std::ostream> os, langcc::FmtFlags flags);
        void write(langcc::Ref<langcc::PrBufStream_T> pb);
        lang::cc::Node::Expr_T xl_;
        lang::cc::Node::Expr_T xr_;
        _T();
        lang::cc::Node::Expr::Assign_T with_id(langcc::Int id);
        lang::cc::Node::Expr::Assign_T with_bounds(langcc::TokenBounds bounds);
        lang::cc::Node::Expr::Assign_T with_is_top(bool is_top);
        lang::cc::Node::Expr::Assign_T with_sym(langcc::ParserSymId sym);
        lang::cc::Node::Expr::Assign_T with_attr(langcc::ParserAttrMask attr);
        lang::cc::Node::Expr::Assign_T with_first_k(langcc::ParserLookahead first_k);
        lang::cc::Node::Expr::Assign_T with_xl(lang::cc::Node::Expr_T xl);
        lang::cc::Node::Expr::Assign_T with_xr(lang::cc::Node::Expr_T xr);
        void hash_ser_acc_lang_cc_Node_Expr_Assign(langcc::SerBuf& buf) const;
        virtual void hash_ser_acc(langcc::SerBuf& buf) const;
    };
}

namespace langcc {
    void pr_debug(ostream& os, FmtFlags flags, lang::cc::Node::Expr::Bin1_T x);
}

namespace lang::cc::Node::Expr::Bin1 {
    lang::cc::Node::Expr::Bin1_T make(langcc::Int id, langcc::TokenBounds bounds, bool is_top, langcc::ParserSymId sym, langcc::ParserAttrMask attr, langcc::ParserLookahead first_k, lang::cc::Node::Expr_T xl, lang::cc::Node::Expr::Bin1::op_T op, lang::cc::Node::Expr_T xr);
}

namespace lang::cc::Node::Expr::Bin1 {
    lang::cc::Node::Expr::Bin1_T make_ext(langcc::ArenaPtr arena, langcc::Int id, langcc::TokenBounds bounds, bool is_top, langcc::ParserSymId sym, langcc::ParserAttrMask attr, langcc::ParserLookahead first_k, lang::cc::Node::Expr_T xl, lang::cc::Node::Expr::Bin1::op_T op, lang::cc::Node::Expr_T xr);
}

namespace lang::cc::Node::Expr::Bin1 {
    struct _T: lang::cc::Node::Expr::_T {
        void write(langcc::Ref<std::ostream> os, langcc::FmtFlags flags);
        void write(langcc::Ref<langcc::PrBufStream_T> pb);
        lang::cc::Node::Expr_T xl_;
        lang::cc::Node::Expr::Bin1::op_T op_;
        lang::cc::Node::Expr_T xr_;
        _T();
        lang::cc::Node::Expr::Bin1_T with_id(langcc::Int id);
        lang::cc::Node::Expr::Bin1_T with_bounds(langcc::TokenBounds bounds);
        lang::cc::Node::Expr::Bin1_T with_is_top(bool is_top);
        lang::cc::Node::Expr::Bin1_T with_sym(langcc::ParserSymId sym);
        lang::cc::Node::Expr::Bin1_T with_attr(langcc::ParserAttrMask attr);
        lang::cc::Node::Expr::Bin1_T with_first_k(langcc::ParserLookahead first_k);
        lang::cc::Node::Expr::Bin1_T with_xl(lang::cc::Node::Expr_T xl);
        lang::cc::Node::Expr::Bin1_T with_op(lang::cc::Node::Expr::Bin1::op_T op);
        lang::cc::Node::Expr::Bin1_T with_xr(lang::cc::Node::Expr_T xr);
        void hash_ser_acc_lang_cc_Node_Expr_Bin1(langcc::SerBuf& buf) const;
        virtual void hash_ser_acc(langcc::SerBuf& buf) const;
    };
}

namespace langcc {
    void pr_debug(ostream& os, FmtFlags flags, lang::cc::Node::Expr::Bin2_T x);
}

namespace lang::cc::Node::Expr::Bin2 {
    lang::cc::Node::Expr::Bin2_T make(langcc::Int id, langcc::TokenBounds bounds, bool is_top, langcc::ParserSymId sym, langcc::ParserAttrMask attr, langcc::ParserLookahead first_k, lang::cc::Node::Expr_T xl, lang::cc::Node::Expr::Bin2::op_T op, lang::cc::Node::Expr_T xr);
}

namespace lang::cc::Node::Expr::Bin2 {
    lang::cc::Node::Expr::Bin2_T make_ext(langcc::ArenaPtr arena, langcc::Int id, langcc::TokenBounds bounds, bool is_top, langcc::ParserSymId sym, langcc::ParserAttrMask attr, langcc::ParserLookahead first_k, lang::cc::Node::Expr_T xl, lang::cc::Node::Expr::Bin2::op_T op, lang::cc::Node::Expr_T xr);
}

namespace lang::cc::Node::Expr::Bin2 {
    struct _T: lang::cc::Node::Expr::_T {
        void write(langcc::Ref<std::ostream> os, langcc::FmtFlags flags);
        void write(langcc::Ref<langcc::PrBufStream_T> pb);
        lang::cc::Node::Expr_T xl_;
        lang::cc::Node::Expr::Bin2::op_T op_;
        lang::cc::Node::Expr_T xr_;
        _T();
        lang::cc::Node::Expr::Bin2_T with_id(langcc::Int id);
        lang::cc::Node::Expr::Bin2_T with_bounds(langcc::TokenBounds bounds);
        lang::cc::Node::Expr::Bin2_T with_is_top(bool is_top);
        lang::cc::Node::Expr::Bin2_T with_sym(langcc::ParserSymId sym);
        lang::cc::Node::Expr::Bin2_T with_attr(langcc::ParserAttrMask attr);
        lang::cc::Node::Expr::Bin2_T with_first_k(langcc::ParserLookahead first_k);
        lang::cc::Node::Expr::Bin2_T with_xl(lang::cc::Node::Expr_T xl);
        lang::cc::Node::Expr::Bin2_T with_op(lang::cc::Node::Expr::Bin2::op_T op);
        lang::cc::Node::Expr::Bin2_T with_xr(lang::cc::Node::Expr_T xr);
        void hash_ser_acc_lang_cc_Node_Expr_Bin2(langcc::SerBuf& buf) const;
        virtual void hash_ser_acc(langcc::SerBuf& buf) const;
    };
}

namespace langcc {
    void pr_debug(ostream& os, FmtFlags flags, lang::cc::Node::Expr::Bin3_T x);
}

namespace lang::cc::Node::Expr::Bin3 {
    lang::cc::Node::Expr::Bin3_T make(langcc::Int id, langcc::TokenBounds bounds, bool is_top, langcc::ParserSymId sym, langcc::ParserAttrMask attr, langcc::ParserLookahead first_k, lang::cc::Node::Expr_T xl, lang::cc::Node::Expr::Bin3::op_T op, lang::cc::Node::Expr_T xr);
}

namespace lang::cc::Node::Expr::Bin3 {
    lang::cc::Node::Expr::Bin3_T make_ext(langcc::ArenaPtr arena, langcc::Int id, langcc::TokenBounds bounds, bool is_top, langcc::ParserSymId sym, langcc::ParserAttrMask attr, langcc::ParserLookahead first_k, lang::cc::Node::Expr_T xl, lang::cc::Node::Expr::Bin3::op_T op, lang::cc::Node::Expr_T xr);
}

namespace lang::cc::Node::Expr::Bin3 {
    struct _T: lang::cc::Node::Expr::_T {
        void write(langcc::Ref<std::ostream> os, langcc::FmtFlags flags);
        void write(langcc::Ref<langcc::PrBufStream_T> pb);
        lang::cc::Node::Expr_T xl_;
        lang::cc::Node::Expr::Bin3::op_T op_;
        lang::cc::Node::Expr_T xr_;
        _T();
        lang::cc::Node::Expr::Bin3_T with_id(langcc::Int id);
        lang::cc::Node::Expr::Bin3_T with_bounds(langcc::TokenBounds bounds);
        lang::cc::Node::Expr::Bin3_T with_is_top(bool is_top);
        lang::cc::Node::Expr::Bin3_T with_sym(langcc::ParserSymId sym);
        lang::cc::Node::Expr::Bin3_T with_attr(langcc::ParserAttrMask attr);
        lang::cc::Node::Expr::Bin3_T with_first_k(langcc::ParserLookahead first_k);
        lang::cc::Node::Expr::Bin3_T with_xl(lang::cc::Node::Expr_T xl);
        lang::cc::Node::Expr::Bin3_T with_op(lang::cc::Node::Expr::Bin3::op_T op);
        lang::cc::Node::Expr::Bin3_T with_xr(lang::cc::Node::Expr_T xr);
        void hash_ser_acc_lang_cc_Node_Expr_Bin3(langcc::SerBuf& buf) const;
        virtual void hash_ser_acc(langcc::SerBuf& buf) const;
    };
}

namespace langcc {
    void pr_debug(ostream& os, FmtFlags flags, lang::cc::Node::Expr::Bin4_T x);
}

namespace lang::cc::Node::Expr::Bin4 {
    lang::cc::Node::Expr::Bin4_T make(langcc::Int id, langcc::TokenBounds bounds, bool is_top, langcc::ParserSymId sym, langcc::ParserAttrMask attr, langcc::ParserLookahead first_k, lang::cc::Node::Expr_T xl, lang::cc::Node::Expr::Bin4::op_T op, lang::cc::Node::Expr_T xr);
}

namespace lang::cc::Node::Expr::Bin4 {
    lang::cc::Node::Expr::Bin4_T make_ext(langcc::ArenaPtr arena, langcc::Int id, langcc::TokenBounds bounds, bool is_top, langcc::ParserSymId sym, langcc::ParserAttrMask attr, langcc::ParserLookahead first_k, lang::cc::Node::Expr_T xl, lang::cc::Node::Expr::Bin4::op_T op, lang::cc::Node::Expr_T xr);
}

namespace lang::cc::Node::Expr::Bin4 {
    struct _T: lang::cc::Node::Expr::_T {
        void write(langcc::Ref<std::ostream> os, langcc::FmtFlags flags);
        void write(langcc::Ref<langcc::PrBufStream_T> pb);
        lang::cc::Node::Expr_T xl_;
        lang::cc::Node::Expr::Bin4::op_T op_;
        lang::cc::Node::Expr_T xr_;
        _T();
        lang::cc::Node::Expr::Bin4_T with_id(langcc::Int id);
        lang::cc::Node::Expr::Bin4_T with_bounds(langcc::TokenBounds bounds);
        lang::cc::Node::Expr::Bin4_T with_is_top(bool is_top);
        lang::cc::Node::Expr::Bin4_T with_sym(langcc::ParserSymId sym);
        lang::cc::Node::Expr::Bin4_T with_attr(langcc::ParserAttrMask attr);
        lang::cc::Node::Expr::Bin4_T with_first_k(langcc::ParserLookahead first_k);
        lang::cc::Node::Expr::Bin4_T with_xl(lang::cc::Node::Expr_T xl);
        lang::cc::Node::Expr::Bin4_T with_op(lang::cc::Node::Expr::Bin4::op_T op);
        lang::cc::Node::Expr::Bin4_T with_xr(lang::cc::Node::Expr_T xr);
        void hash_ser_acc_lang_cc_Node_Expr_Bin4(langcc::SerBuf& buf) const;
        virtual void hash_ser_acc(langcc::SerBuf& buf) const;
    };
}

namespace langcc {
    void pr_debug(ostream& os, FmtFlags flags, lang::cc::Node::Expr::Bin5_T x);
}

namespace lang::cc::Node::Expr::Bin5 {
    lang::cc::Node::Expr::Bin5_T make(langcc::Int id, langcc::TokenBounds bounds, bool is_top, langcc::ParserSymId sym, langcc::ParserAttrMask attr, langcc::ParserLookahead first_k, lang::cc::Node::Expr_T xl, lang::cc::Node::Expr::Bin5::op_T op, lang::cc::Node::Expr_T xr);
}

namespace lang::cc::Node::Expr::Bin5 {
    lang::cc::Node::Expr::Bin5_T make_ext(langcc::ArenaPtr arena, langcc::Int id, langcc::TokenBounds bounds, bool is_top, langcc::ParserSymId sym, langcc::ParserAttrMask attr, langcc::ParserLookahead first_k, lang::cc::Node::Expr_T xl, lang::cc::Node::Expr::Bin5::op_T op, lang::cc::Node::Expr_T xr);
}

namespace lang::cc::Node::Expr::Bin5 {
    struct _T: lang::cc::Node::Expr::_T {
        void write(langcc::Ref<std::ostream> os, langcc::FmtFlags flags);
        void write(langcc::Ref<langcc::PrBufStream_T> pb);
        lang::cc::Node::Expr_T xl_;
        lang::cc::Node::Expr::Bin5::op_T op_;
        lang::cc::Node::Expr_T xr_;
        _T();
        lang::cc::Node::Expr::Bin5_T with_id(langcc::Int id);
        lang::cc::Node::Expr::Bin5_T with_bounds(langcc::TokenBounds bounds);
        lang::cc::Node::Expr::Bin5_T with_is_top(bool is_top);
        lang::cc::Node::Expr::Bin5_T with_sym(langcc::ParserSymId sym);
        lang::cc::Node::Expr::Bin5_T with_attr(langcc::ParserAttrMask attr);
        lang::cc::Node::Expr::Bin5_T with_first_k(langcc::ParserLookahead first_k);
        lang::cc::Node::Expr::Bin5_T with_xl(lang::cc::Node::Expr_T xl);
        lang::cc::Node::Expr::Bin5_T with_op(lang::cc::Node::Expr::Bin5::op_T op);
        lang::cc::Node::Expr::Bin5_T with_xr(lang::cc::Node::Expr_T xr);
        void hash_ser_acc_lang_cc_Node_Expr_Bin5(langcc::SerBuf& buf) const;
        virtual void hash_ser_acc(langcc::SerBuf& buf) const;
    };
}

namespace langcc {
    void pr_debug(ostream& os, FmtFlags flags, lang::cc::Node::Expr::Bin6_T x);
}

namespace lang::cc::Node::Expr::Bin6 {
    lang::cc::Node::Expr::Bin6_T make(langcc::Int id, langcc::TokenBounds bounds, bool is_top, langcc::ParserSymId sym, langcc::ParserAttrMask attr, langcc::ParserLookahead first_k, lang::cc::Node::Expr_T xl, lang::cc::Node::Expr::Bin6::op_T op, lang::cc::Node::Expr_T xr);
}

namespace lang::cc::Node::Expr::Bin6 {
    lang::cc::Node::Expr::Bin6_T make_ext(langcc::ArenaPtr arena, langcc::Int id, langcc::TokenBounds bounds, bool is_top, langcc::ParserSymId sym, langcc::ParserAttrMask attr, langcc::ParserLookahead first_k, lang::cc::Node::Expr_T xl, lang::cc::Node::Expr::Bin6::op_T op, lang::cc::Node::Expr_T xr);
}

namespace lang::cc::Node::Expr::Bin6 {
    struct _T: lang::cc::Node::Expr::_T {
        void write(langcc::Ref<std::ostream> os, langcc::FmtFlags flags);
        void write(langcc::Ref<langcc::PrBufStream_T> pb);
        lang::cc::Node::Expr_T xl_;
        lang::cc::Node::Expr::Bin6::op_T op_;
        lang::cc::Node::Expr_T xr_;
        _T();
        lang::cc::Node::Expr::Bin6_T with_id(langcc::Int id);
        lang::cc::Node::Expr::Bin6_T with_bounds(langcc::TokenBounds bounds);
        lang::cc::Node::Expr::Bin6_T with_is_top(bool is_top);
        lang::cc::Node::Expr::Bin6_T with_sym(langcc::ParserSymId sym);
        lang::cc::Node::Expr::Bin6_T with_attr(langcc::ParserAttrMask attr);
        lang::cc::Node::Expr::Bin6_T with_first_k(langcc::ParserLookahead first_k);
        lang::cc::Node::Expr::Bin6_T with_xl(lang::cc::Node::Expr_T xl);
        lang::cc::Node::Expr::Bin6_T with_op(lang::cc::Node::Expr::Bin6::op_T op);
        lang::cc::Node::Expr::Bin6_T with_xr(lang::cc::Node::Expr_T xr);
        void hash_ser_acc_lang_cc_Node_Expr_Bin6(langcc::SerBuf& buf) const;
        virtual void hash_ser_acc(langcc::SerBuf& buf) const;
    };
}

namespace langcc {
    void pr_debug(ostream& os, FmtFlags flags, lang::cc::Node::Expr::Template_T x);
}

namespace lang::cc::Node::Expr::Template {
    lang::cc::Node::Expr::Template_T make(langcc::Int id, langcc::TokenBounds bounds, bool is_top, langcc::ParserSymId sym, langcc::ParserAttrMask attr, langcc::ParserLookahead first_k, lang::cc::Node::Expr_T x, langcc::Vec_T<lang::cc::Node::Expr_T> args);
}

namespace lang::cc::Node::Expr::Template {
    lang::cc::Node::Expr::Template_T make_ext(langcc::ArenaPtr arena, langcc::Int id, langcc::TokenBounds bounds, bool is_top, langcc::ParserSymId sym, langcc::ParserAttrMask attr, langcc::ParserLookahead first_k, lang::cc::Node::Expr_T x, langcc::Vec_T<lang::cc::Node::Expr_T> args);
}

namespace lang::cc::Node::Expr::Template {
    struct _T: lang::cc::Node::Expr::_T {
        void write(langcc::Ref<std::ostream> os, langcc::FmtFlags flags);
        void write(langcc::Ref<langcc::PrBufStream_T> pb);
        lang::cc::Node::Expr_T x_;
        langcc::Vec_T<lang::cc::Node::Expr_T> args_;
        _T();
        lang::cc::Node::Expr::Template_T with_id(langcc::Int id);
        lang::cc::Node::Expr::Template_T with_bounds(langcc::TokenBounds bounds);
        lang::cc::Node::Expr::Template_T with_is_top(bool is_top);
        lang::cc::Node::Expr::Template_T with_sym(langcc::ParserSymId sym);
        lang::cc::Node::Expr::Template_T with_attr(langcc::ParserAttrMask attr);
        lang::cc::Node::Expr::Template_T with_first_k(langcc::ParserLookahead first_k);
        lang::cc::Node::Expr::Template_T with_x(lang::cc::Node::Expr_T x);
        lang::cc::Node::Expr::Template_T with_args(langcc::Vec_T<lang::cc::Node::Expr_T> args);
        void hash_ser_acc_lang_cc_Node_Expr_Template(langcc::SerBuf& buf) const;
        virtual void hash_ser_acc(langcc::SerBuf& buf) const;
    };
}

namespace langcc {
    void pr_debug(ostream& os, FmtFlags flags, lang::cc::Node::Expr::New_T x);
}

namespace lang::cc::Node::Expr::New {
    lang::cc::Node::Expr::New_T make(langcc::Int id, langcc::TokenBounds bounds, bool is_top, langcc::ParserSymId sym, langcc::ParserAttrMask attr, langcc::ParserLookahead first_k, lang::cc::Node::Expr_T x);
}

namespace lang::cc::Node::Expr::New {
    lang::cc::Node::Expr::New_T make_ext(langcc::ArenaPtr arena, langcc::Int id, langcc::TokenBounds bounds, bool is_top, langcc::ParserSymId sym, langcc::ParserAttrMask attr, langcc::ParserLookahead first_k, lang::cc::Node::Expr_T x);
}

namespace lang::cc::Node::Expr::New {
    struct _T: lang::cc::Node::Expr::_T {
        void write(langcc::Ref<std::ostream> os, langcc::FmtFlags flags);
        void write(langcc::Ref<langcc::PrBufStream_T> pb);
        lang::cc::Node::Expr_T x_;
        _T();
        lang::cc::Node::Expr::New_T with_id(langcc::Int id);
        lang::cc::Node::Expr::New_T with_bounds(langcc::TokenBounds bounds);
        lang::cc::Node::Expr::New_T with_is_top(bool is_top);
        lang::cc::Node::Expr::New_T with_sym(langcc::ParserSymId sym);
        lang::cc::Node::Expr::New_T with_attr(langcc::ParserAttrMask attr);
        lang::cc::Node::Expr::New_T with_first_k(langcc::ParserLookahead first_k);
        lang::cc::Node::Expr::New_T with_x(lang::cc::Node::Expr_T x);
        void hash_ser_acc_lang_cc_Node_Expr_New(langcc::SerBuf& buf) const;
        virtual void hash_ser_acc(langcc::SerBuf& buf) const;
    };
}

namespace langcc {
    void pr_debug(ostream& os, FmtFlags flags, lang::cc::Node::Expr::Delete_T x);
}

namespace lang::cc::Node::Expr::Delete {
    lang::cc::Node::Expr::Delete_T make(langcc::Int id, langcc::TokenBounds bounds, bool is_top, langcc::ParserSymId sym, langcc::ParserAttrMask attr, langcc::ParserLookahead first_k, lang::cc::Node::Expr_T x);
}

namespace lang::cc::Node::Expr::Delete {
    lang::cc::Node::Expr::Delete_T make_ext(langcc::ArenaPtr arena, langcc::Int id, langcc::TokenBounds bounds, bool is_top, langcc::ParserSymId sym, langcc::ParserAttrMask attr, langcc::ParserLookahead first_k, lang::cc::Node::Expr_T x);
}

namespace lang::cc::Node::Expr::Delete {
    struct _T: lang::cc::Node::Expr::_T {
        void write(langcc::Ref<std::ostream> os, langcc::FmtFlags flags);
        void write(langcc::Ref<langcc::PrBufStream_T> pb);
        lang::cc::Node::Expr_T x_;
        _T();
        lang::cc::Node::Expr::Delete_T with_id(langcc::Int id);
        lang::cc::Node::Expr::Delete_T with_bounds(langcc::TokenBounds bounds);
        lang::cc::Node::Expr::Delete_T with_is_top(bool is_top);
        lang::cc::Node::Expr::Delete_T with_sym(langcc::ParserSymId sym);
        lang::cc::Node::Expr::Delete_T with_attr(langcc::ParserAttrMask attr);
        lang::cc::Node::Expr::Delete_T with_first_k(langcc::ParserLookahead first_k);
        lang::cc::Node::Expr::Delete_T with_x(lang::cc::Node::Expr_T x);
        void hash_ser_acc_lang_cc_Node_Expr_Delete(langcc::SerBuf& buf) const;
        virtual void hash_ser_acc(langcc::SerBuf& buf) const;
    };
}

namespace langcc {
    void pr_debug(ostream& os, FmtFlags flags, lang::cc::Node::Expr::Ellipsis_T x);
}

namespace lang::cc::Node::Expr::Ellipsis {
    lang::cc::Node::Expr::Ellipsis_T make(langcc::Int id, langcc::TokenBounds bounds, bool is_top, langcc::ParserSymId sym, langcc::ParserAttrMask attr, langcc::ParserLookahead first_k, lang::cc::Node::Expr_T x);
}

namespace lang::cc::Node::Expr::Ellipsis {
    lang::cc::Node::Expr::Ellipsis_T make_ext(langcc::ArenaPtr arena, langcc::Int id, langcc::TokenBounds bounds, bool is_top, langcc::ParserSymId sym, langcc::ParserAttrMask attr, langcc::ParserLookahead first_k, lang::cc::Node::Expr_T x);
}

namespace lang::cc::Node::Expr::Ellipsis {
    struct _T: lang::cc::Node::Expr::_T {
        void write(langcc::Ref<std::ostream> os, langcc::FmtFlags flags);
        void write(langcc::Ref<langcc::PrBufStream_T> pb);
        lang::cc::Node::Expr_T x_;
        _T();
        lang::cc::Node::Expr::Ellipsis_T with_id(langcc::Int id);
        lang::cc::Node::Expr::Ellipsis_T with_bounds(langcc::TokenBounds bounds);
        lang::cc::Node::Expr::Ellipsis_T with_is_top(bool is_top);
        lang::cc::Node::Expr::Ellipsis_T with_sym(langcc::ParserSymId sym);
        lang::cc::Node::Expr::Ellipsis_T with_attr(langcc::ParserAttrMask attr);
        lang::cc::Node::Expr::Ellipsis_T with_first_k(langcc::ParserLookahead first_k);
        lang::cc::Node::Expr::Ellipsis_T with_x(lang::cc::Node::Expr_T x);
        void hash_ser_acc_lang_cc_Node_Expr_Ellipsis(langcc::SerBuf& buf) const;
        virtual void hash_ser_acc(langcc::SerBuf& buf) const;
    };
}

namespace langcc {
    void pr_debug(ostream& os, FmtFlags flags, lang::cc::Node::Expr::Tilde_T x);
}

namespace lang::cc::Node::Expr::Tilde {
    lang::cc::Node::Expr::Tilde_T make(langcc::Int id, langcc::TokenBounds bounds, bool is_top, langcc::ParserSymId sym, langcc::ParserAttrMask attr, langcc::ParserLookahead first_k, lang::cc::Node::Expr_T x);
}

namespace lang::cc::Node::Expr::Tilde {
    lang::cc::Node::Expr::Tilde_T make_ext(langcc::ArenaPtr arena, langcc::Int id, langcc::TokenBounds bounds, bool is_top, langcc::ParserSymId sym, langcc::ParserAttrMask attr, langcc::ParserLookahead first_k, lang::cc::Node::Expr_T x);
}

namespace lang::cc::Node::Expr::Tilde {
    struct _T: lang::cc::Node::Expr::_T {
        void write(langcc::Ref<std::ostream> os, langcc::FmtFlags flags);
        void write(langcc::Ref<langcc::PrBufStream_T> pb);
        lang::cc::Node::Expr_T x_;
        _T();
        lang::cc::Node::Expr::Tilde_T with_id(langcc::Int id);
        lang::cc::Node::Expr::Tilde_T with_bounds(langcc::TokenBounds bounds);
        lang::cc::Node::Expr::Tilde_T with_is_top(bool is_top);
        lang::cc::Node::Expr::Tilde_T with_sym(langcc::ParserSymId sym);
        lang::cc::Node::Expr::Tilde_T with_attr(langcc::ParserAttrMask attr);
        lang::cc::Node::Expr::Tilde_T with_first_k(langcc::ParserLookahead first_k);
        lang::cc::Node::Expr::Tilde_T with_x(lang::cc::Node::Expr_T x);
        void hash_ser_acc_lang_cc_Node_Expr_Tilde(langcc::SerBuf& buf) const;
        virtual void hash_ser_acc(langcc::SerBuf& buf) const;
    };
}

namespace langcc {
    void pr_debug(ostream& os, FmtFlags flags, lang::cc::Node::Expr::Namespace_T x);
}

namespace lang::cc::Node::Expr::Namespace {
    lang::cc::Node::Expr::Namespace_T make(langcc::Int id, langcc::TokenBounds bounds, bool is_top, langcc::ParserSymId sym, langcc::ParserAttrMask attr, langcc::ParserLookahead first_k, lang::cc::Node::Expr_T x, bool tilde, lang::cc::Node::Expr_T name);
}

namespace lang::cc::Node::Expr::Namespace {
    lang::cc::Node::Expr::Namespace_T make_ext(langcc::ArenaPtr arena, langcc::Int id, langcc::TokenBounds bounds, bool is_top, langcc::ParserSymId sym, langcc::ParserAttrMask attr, langcc::ParserLookahead first_k, lang::cc::Node::Expr_T x, bool tilde, lang::cc::Node::Expr_T name);
}

namespace lang::cc::Node::Expr::Namespace {
    struct _T: lang::cc::Node::Expr::_T {
        void write(langcc::Ref<std::ostream> os, langcc::FmtFlags flags);
        void write(langcc::Ref<langcc::PrBufStream_T> pb);
        lang::cc::Node::Expr_T x_;
        bool tilde_;
        lang::cc::Node::Expr_T name_;
        _T();
        lang::cc::Node::Expr::Namespace_T with_id(langcc::Int id);
        lang::cc::Node::Expr::Namespace_T with_bounds(langcc::TokenBounds bounds);
        lang::cc::Node::Expr::Namespace_T with_is_top(bool is_top);
        lang::cc::Node::Expr::Namespace_T with_sym(langcc::ParserSymId sym);
        lang::cc::Node::Expr::Namespace_T with_attr(langcc::ParserAttrMask attr);
        lang::cc::Node::Expr::Namespace_T with_first_k(langcc::ParserLookahead first_k);
        lang::cc::Node::Expr::Namespace_T with_x(lang::cc::Node::Expr_T x);
        lang::cc::Node::Expr::Namespace_T with_tilde(bool tilde);
        lang::cc::Node::Expr::Namespace_T with_name(lang::cc::Node::Expr_T name);
        void hash_ser_acc_lang_cc_Node_Expr_Namespace(langcc::SerBuf& buf) const;
        virtual void hash_ser_acc(langcc::SerBuf& buf) const;
    };
}

namespace langcc {
    void pr_debug(ostream& os, FmtFlags flags, lang::cc::Node::Expr::Id_T x);
}

namespace lang::cc::Node::Expr::Id {
    lang::cc::Node::Expr::Id_T make(langcc::Int id, langcc::TokenBounds bounds, bool is_top, langcc::ParserSymId sym, langcc::ParserAttrMask attr, langcc::ParserLookahead first_k, langcc::StrSlice name);
}

namespace lang::cc::Node::Expr::Id {
    lang::cc::Node::Expr::Id_T make_ext(langcc::ArenaPtr arena, langcc::Int id, langcc::TokenBounds bounds, bool is_top, langcc::ParserSymId sym, langcc::ParserAttrMask attr, langcc::ParserLookahead first_k, langcc::StrSlice name);
}

namespace lang::cc::Node::Expr::Id {
    struct _T: lang::cc::Node::Expr::_T {
        void write(langcc::Ref<std::ostream> os, langcc::FmtFlags flags);
        void write(langcc::Ref<langcc::PrBufStream_T> pb);
        langcc::StrSlice name_;
        _T();
        lang::cc::Node::Expr::Id_T with_id(langcc::Int id);
        lang::cc::Node::Expr::Id_T with_bounds(langcc::TokenBounds bounds);
        lang::cc::Node::Expr::Id_T with_is_top(bool is_top);
        lang::cc::Node::Expr::Id_T with_sym(langcc::ParserSymId sym);
        lang::cc::Node::Expr::Id_T with_attr(langcc::ParserAttrMask attr);
        lang::cc::Node::Expr::Id_T with_first_k(langcc::ParserLookahead first_k);
        lang::cc::Node::Expr::Id_T with_name(langcc::StrSlice name);
        void hash_ser_acc_lang_cc_Node_Expr_Id(langcc::SerBuf& buf) const;
        virtual void hash_ser_acc(langcc::SerBuf& buf) const;
    };
}

namespace langcc {
    void pr_debug(ostream& os, FmtFlags flags, lang::cc::Node::Expr::Lit_T x);
}

namespace lang::cc::Node::Expr::Lit {
    enum struct _W {
        Integer,
        Str_,
        Array,
    };
}

namespace lang::cc::Node::Expr::Lit {
    struct _T: lang::cc::Node::Expr::_T {
        void write(langcc::Ref<std::ostream> os, langcc::FmtFlags flags);
        void write(langcc::Ref<langcc::PrBufStream_T> pb);
        lang::cc::Node::Expr::Lit::_W w_;
        virtual ~_T();
        _T(lang::cc::Node::Expr::Lit::_W w);
        bool is_Integer() const;
        bool is_Str_() const;
        bool is_Array() const;
        lang::cc::Node::Expr::Lit::Integer_T as_Integer();
        const lang::cc::Node::Expr::Lit::Integer_T as_Integer() const;
        lang::cc::Node::Expr::Lit::Str__T as_Str_();
        const lang::cc::Node::Expr::Lit::Str__T as_Str_() const;
        lang::cc::Node::Expr::Lit::Array_T as_Array();
        const lang::cc::Node::Expr::Lit::Array_T as_Array() const;
        void match(std::function<void(lang::cc::Node::Expr::Lit::Integer_T)> f_Integer, std::function<void(lang::cc::Node::Expr::Lit::Str__T)> f_Str_, std::function<void(lang::cc::Node::Expr::Lit::Array_T)> f_Array);
        template<typename RetT> RetT match_expr(std::function<RetT(lang::cc::Node::Expr::Lit::Integer_T)> f_Integer, std::function<RetT(lang::cc::Node::Expr::Lit::Str__T)> f_Str_, std::function<RetT(lang::cc::Node::Expr::Lit::Array_T)> f_Array);
        void hash_ser_acc_lang_cc_Node_Expr_Lit(langcc::SerBuf& buf) const;
        virtual void hash_ser_acc(langcc::SerBuf& buf) const = 0;
    };
}

template<typename RetT> RetT lang::cc::Node::Expr::Lit::_T::match_expr(std::function<RetT(lang::cc::Node::Expr::Lit::Integer_T)> f_Integer, std::function<RetT(lang::cc::Node::Expr::Lit::Str__T)> f_Str_, std::function<RetT(lang::cc::Node::Expr::Lit::Array_T)> f_Array) {
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
            langcc::AX();
        }
    }
}

namespace langcc {
    void pr_debug(ostream& os, FmtFlags flags, lang::cc::Node::TypedDecl::vars::item_T x);
}

namespace lang::cc::Node::TypedDecl::vars::item {
    lang::cc::Node::TypedDecl::vars::item_T make(langcc::Int id, langcc::TokenBounds bounds, bool is_top, langcc::ParserSymId sym, langcc::ParserAttrMask attr, langcc::ParserLookahead first_k, lang::cc::Node::Expr_T name, langcc::Option_T<lang::cc::Node::TypedDecl::vars::item::val_T> val);
}

namespace lang::cc::Node::TypedDecl::vars::item {
    lang::cc::Node::TypedDecl::vars::item_T make_ext(langcc::ArenaPtr arena, langcc::Int id, langcc::TokenBounds bounds, bool is_top, langcc::ParserSymId sym, langcc::ParserAttrMask attr, langcc::ParserLookahead first_k, lang::cc::Node::Expr_T name, langcc::Option_T<lang::cc::Node::TypedDecl::vars::item::val_T> val);
}

namespace lang::cc::Node::TypedDecl::vars::item {
    struct _T: lang::cc::Node::_T {
        void write(langcc::Ref<std::ostream> os, langcc::FmtFlags flags);
        void write(langcc::Ref<langcc::PrBufStream_T> pb);
        lang::cc::Node::Expr_T name_;
        langcc::Option_T<lang::cc::Node::TypedDecl::vars::item::val_T> val_;
        _T();
        lang::cc::Node::TypedDecl::vars::item_T with_id(langcc::Int id);
        lang::cc::Node::TypedDecl::vars::item_T with_bounds(langcc::TokenBounds bounds);
        lang::cc::Node::TypedDecl::vars::item_T with_is_top(bool is_top);
        lang::cc::Node::TypedDecl::vars::item_T with_sym(langcc::ParserSymId sym);
        lang::cc::Node::TypedDecl::vars::item_T with_attr(langcc::ParserAttrMask attr);
        lang::cc::Node::TypedDecl::vars::item_T with_first_k(langcc::ParserLookahead first_k);
        lang::cc::Node::TypedDecl::vars::item_T with_name(lang::cc::Node::Expr_T name);
        lang::cc::Node::TypedDecl::vars::item_T with_val(langcc::Option_T<lang::cc::Node::TypedDecl::vars::item::val_T> val);
        void hash_ser_acc_lang_cc_Node_TypedDecl_vars_item(langcc::SerBuf& buf) const;
        virtual void hash_ser_acc(langcc::SerBuf& buf) const;
    };
}

namespace langcc {
    void pr_debug(ostream& os, FmtFlags flags, lang::cc::Node::Expr::UnaryPre::op_T x);
}

namespace lang::cc::Node::Expr::UnaryPre::op {
    enum struct _W {
        NOT,
        NEG,
    };
}

namespace lang::cc::Node::Expr::UnaryPre::op {
    struct _T: lang::cc::Node::_T {
        void write(langcc::Ref<std::ostream> os, langcc::FmtFlags flags);
        void write(langcc::Ref<langcc::PrBufStream_T> pb);
        lang::cc::Node::Expr::UnaryPre::op::_W w_;
        virtual ~_T();
        _T(lang::cc::Node::Expr::UnaryPre::op::_W w);
        bool is_NOT() const;
        bool is_NEG() const;
        lang::cc::Node::Expr::UnaryPre::op::NOT_T as_NOT();
        const lang::cc::Node::Expr::UnaryPre::op::NOT_T as_NOT() const;
        lang::cc::Node::Expr::UnaryPre::op::NEG_T as_NEG();
        const lang::cc::Node::Expr::UnaryPre::op::NEG_T as_NEG() const;
        void match(std::function<void(lang::cc::Node::Expr::UnaryPre::op::NOT_T)> f_NOT, std::function<void(lang::cc::Node::Expr::UnaryPre::op::NEG_T)> f_NEG);
        template<typename RetT> RetT match_expr(std::function<RetT(lang::cc::Node::Expr::UnaryPre::op::NOT_T)> f_NOT, std::function<RetT(lang::cc::Node::Expr::UnaryPre::op::NEG_T)> f_NEG);
        void hash_ser_acc_lang_cc_Node_Expr_UnaryPre_op(langcc::SerBuf& buf) const;
        virtual void hash_ser_acc(langcc::SerBuf& buf) const = 0;
    };
}

template<typename RetT> RetT lang::cc::Node::Expr::UnaryPre::op::_T::match_expr(std::function<RetT(lang::cc::Node::Expr::UnaryPre::op::NOT_T)> f_NOT, std::function<RetT(lang::cc::Node::Expr::UnaryPre::op::NEG_T)> f_NEG) {
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
            langcc::AX();
        }
    }
}

namespace langcc {
    void pr_debug(ostream& os, FmtFlags flags, lang::cc::Node::Expr::IncDecPre::op_T x);
}

namespace lang::cc::Node::Expr::IncDecPre::op {
    enum struct _W {
        INC,
        DEC,
    };
}

namespace lang::cc::Node::Expr::IncDecPre::op {
    struct _T: lang::cc::Node::_T {
        void write(langcc::Ref<std::ostream> os, langcc::FmtFlags flags);
        void write(langcc::Ref<langcc::PrBufStream_T> pb);
        lang::cc::Node::Expr::IncDecPre::op::_W w_;
        virtual ~_T();
        _T(lang::cc::Node::Expr::IncDecPre::op::_W w);
        bool is_INC() const;
        bool is_DEC() const;
        lang::cc::Node::Expr::IncDecPre::op::INC_T as_INC();
        const lang::cc::Node::Expr::IncDecPre::op::INC_T as_INC() const;
        lang::cc::Node::Expr::IncDecPre::op::DEC_T as_DEC();
        const lang::cc::Node::Expr::IncDecPre::op::DEC_T as_DEC() const;
        void match(std::function<void(lang::cc::Node::Expr::IncDecPre::op::INC_T)> f_INC, std::function<void(lang::cc::Node::Expr::IncDecPre::op::DEC_T)> f_DEC);
        template<typename RetT> RetT match_expr(std::function<RetT(lang::cc::Node::Expr::IncDecPre::op::INC_T)> f_INC, std::function<RetT(lang::cc::Node::Expr::IncDecPre::op::DEC_T)> f_DEC);
        void hash_ser_acc_lang_cc_Node_Expr_IncDecPre_op(langcc::SerBuf& buf) const;
        virtual void hash_ser_acc(langcc::SerBuf& buf) const = 0;
    };
}

template<typename RetT> RetT lang::cc::Node::Expr::IncDecPre::op::_T::match_expr(std::function<RetT(lang::cc::Node::Expr::IncDecPre::op::INC_T)> f_INC, std::function<RetT(lang::cc::Node::Expr::IncDecPre::op::DEC_T)> f_DEC) {
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
            langcc::AX();
        }
    }
}

namespace langcc {
    void pr_debug(ostream& os, FmtFlags flags, lang::cc::Node::Expr::IncDecPost::op_T x);
}

namespace lang::cc::Node::Expr::IncDecPost::op {
    enum struct _W {
        INC,
        DEC,
    };
}

namespace lang::cc::Node::Expr::IncDecPost::op {
    struct _T: lang::cc::Node::_T {
        void write(langcc::Ref<std::ostream> os, langcc::FmtFlags flags);
        void write(langcc::Ref<langcc::PrBufStream_T> pb);
        lang::cc::Node::Expr::IncDecPost::op::_W w_;
        virtual ~_T();
        _T(lang::cc::Node::Expr::IncDecPost::op::_W w);
        bool is_INC() const;
        bool is_DEC() const;
        lang::cc::Node::Expr::IncDecPost::op::INC_T as_INC();
        const lang::cc::Node::Expr::IncDecPost::op::INC_T as_INC() const;
        lang::cc::Node::Expr::IncDecPost::op::DEC_T as_DEC();
        const lang::cc::Node::Expr::IncDecPost::op::DEC_T as_DEC() const;
        void match(std::function<void(lang::cc::Node::Expr::IncDecPost::op::INC_T)> f_INC, std::function<void(lang::cc::Node::Expr::IncDecPost::op::DEC_T)> f_DEC);
        template<typename RetT> RetT match_expr(std::function<RetT(lang::cc::Node::Expr::IncDecPost::op::INC_T)> f_INC, std::function<RetT(lang::cc::Node::Expr::IncDecPost::op::DEC_T)> f_DEC);
        void hash_ser_acc_lang_cc_Node_Expr_IncDecPost_op(langcc::SerBuf& buf) const;
        virtual void hash_ser_acc(langcc::SerBuf& buf) const = 0;
    };
}

template<typename RetT> RetT lang::cc::Node::Expr::IncDecPost::op::_T::match_expr(std::function<RetT(lang::cc::Node::Expr::IncDecPost::op::INC_T)> f_INC, std::function<RetT(lang::cc::Node::Expr::IncDecPost::op::DEC_T)> f_DEC) {
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
            langcc::AX();
        }
    }
}

namespace langcc {
    void pr_debug(ostream& os, FmtFlags flags, lang::cc::Node::Expr::Bin1::op_T x);
}

namespace lang::cc::Node::Expr::Bin1::op {
    enum struct _W {
        LOR,
    };
}

namespace lang::cc::Node::Expr::Bin1::op {
    struct _T: lang::cc::Node::_T {
        void write(langcc::Ref<std::ostream> os, langcc::FmtFlags flags);
        void write(langcc::Ref<langcc::PrBufStream_T> pb);
        lang::cc::Node::Expr::Bin1::op::_W w_;
        virtual ~_T();
        _T(lang::cc::Node::Expr::Bin1::op::_W w);
        bool is_LOR() const;
        lang::cc::Node::Expr::Bin1::op::LOR_T as_LOR();
        const lang::cc::Node::Expr::Bin1::op::LOR_T as_LOR() const;
        void match(std::function<void(lang::cc::Node::Expr::Bin1::op::LOR_T)> f_LOR);
        template<typename RetT> RetT match_expr(std::function<RetT(lang::cc::Node::Expr::Bin1::op::LOR_T)> f_LOR);
        void hash_ser_acc_lang_cc_Node_Expr_Bin1_op(langcc::SerBuf& buf) const;
        virtual void hash_ser_acc(langcc::SerBuf& buf) const = 0;
    };
}

template<typename RetT> RetT lang::cc::Node::Expr::Bin1::op::_T::match_expr(std::function<RetT(lang::cc::Node::Expr::Bin1::op::LOR_T)> f_LOR) {
    switch (this->w_) {
        case lang::cc::Node::Expr::Bin1::op::_W::LOR: {
            return f_LOR(this->as_LOR());
            break;
        }
        default: {
            langcc::AX();
        }
    }
}

namespace langcc {
    void pr_debug(ostream& os, FmtFlags flags, lang::cc::Node::Expr::Bin2::op_T x);
}

namespace lang::cc::Node::Expr::Bin2::op {
    enum struct _W {
        LAND,
    };
}

namespace lang::cc::Node::Expr::Bin2::op {
    struct _T: lang::cc::Node::_T {
        void write(langcc::Ref<std::ostream> os, langcc::FmtFlags flags);
        void write(langcc::Ref<langcc::PrBufStream_T> pb);
        lang::cc::Node::Expr::Bin2::op::_W w_;
        virtual ~_T();
        _T(lang::cc::Node::Expr::Bin2::op::_W w);
        bool is_LAND() const;
        lang::cc::Node::Expr::Bin2::op::LAND_T as_LAND();
        const lang::cc::Node::Expr::Bin2::op::LAND_T as_LAND() const;
        void match(std::function<void(lang::cc::Node::Expr::Bin2::op::LAND_T)> f_LAND);
        template<typename RetT> RetT match_expr(std::function<RetT(lang::cc::Node::Expr::Bin2::op::LAND_T)> f_LAND);
        void hash_ser_acc_lang_cc_Node_Expr_Bin2_op(langcc::SerBuf& buf) const;
        virtual void hash_ser_acc(langcc::SerBuf& buf) const = 0;
    };
}

template<typename RetT> RetT lang::cc::Node::Expr::Bin2::op::_T::match_expr(std::function<RetT(lang::cc::Node::Expr::Bin2::op::LAND_T)> f_LAND) {
    switch (this->w_) {
        case lang::cc::Node::Expr::Bin2::op::_W::LAND: {
            return f_LAND(this->as_LAND());
            break;
        }
        default: {
            langcc::AX();
        }
    }
}

namespace langcc {
    void pr_debug(ostream& os, FmtFlags flags, lang::cc::Node::Expr::Bin3::op_T x);
}

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
        void write(langcc::Ref<std::ostream> os, langcc::FmtFlags flags);
        void write(langcc::Ref<langcc::PrBufStream_T> pb);
        lang::cc::Node::Expr::Bin3::op::_W w_;
        virtual ~_T();
        _T(lang::cc::Node::Expr::Bin3::op::_W w);
        bool is_EQ() const;
        bool is_NE() const;
        bool is_LE() const;
        bool is_GE() const;
        bool is_LT() const;
        bool is_GT() const;
        lang::cc::Node::Expr::Bin3::op::EQ_T as_EQ();
        const lang::cc::Node::Expr::Bin3::op::EQ_T as_EQ() const;
        lang::cc::Node::Expr::Bin3::op::NE_T as_NE();
        const lang::cc::Node::Expr::Bin3::op::NE_T as_NE() const;
        lang::cc::Node::Expr::Bin3::op::LE_T as_LE();
        const lang::cc::Node::Expr::Bin3::op::LE_T as_LE() const;
        lang::cc::Node::Expr::Bin3::op::GE_T as_GE();
        const lang::cc::Node::Expr::Bin3::op::GE_T as_GE() const;
        lang::cc::Node::Expr::Bin3::op::LT_T as_LT();
        const lang::cc::Node::Expr::Bin3::op::LT_T as_LT() const;
        lang::cc::Node::Expr::Bin3::op::GT_T as_GT();
        const lang::cc::Node::Expr::Bin3::op::GT_T as_GT() const;
        void match(std::function<void(lang::cc::Node::Expr::Bin3::op::EQ_T)> f_EQ, std::function<void(lang::cc::Node::Expr::Bin3::op::NE_T)> f_NE, std::function<void(lang::cc::Node::Expr::Bin3::op::LE_T)> f_LE, std::function<void(lang::cc::Node::Expr::Bin3::op::GE_T)> f_GE, std::function<void(lang::cc::Node::Expr::Bin3::op::LT_T)> f_LT, std::function<void(lang::cc::Node::Expr::Bin3::op::GT_T)> f_GT);
        template<typename RetT> RetT match_expr(std::function<RetT(lang::cc::Node::Expr::Bin3::op::EQ_T)> f_EQ, std::function<RetT(lang::cc::Node::Expr::Bin3::op::NE_T)> f_NE, std::function<RetT(lang::cc::Node::Expr::Bin3::op::LE_T)> f_LE, std::function<RetT(lang::cc::Node::Expr::Bin3::op::GE_T)> f_GE, std::function<RetT(lang::cc::Node::Expr::Bin3::op::LT_T)> f_LT, std::function<RetT(lang::cc::Node::Expr::Bin3::op::GT_T)> f_GT);
        void hash_ser_acc_lang_cc_Node_Expr_Bin3_op(langcc::SerBuf& buf) const;
        virtual void hash_ser_acc(langcc::SerBuf& buf) const = 0;
    };
}

template<typename RetT> RetT lang::cc::Node::Expr::Bin3::op::_T::match_expr(std::function<RetT(lang::cc::Node::Expr::Bin3::op::EQ_T)> f_EQ, std::function<RetT(lang::cc::Node::Expr::Bin3::op::NE_T)> f_NE, std::function<RetT(lang::cc::Node::Expr::Bin3::op::LE_T)> f_LE, std::function<RetT(lang::cc::Node::Expr::Bin3::op::GE_T)> f_GE, std::function<RetT(lang::cc::Node::Expr::Bin3::op::LT_T)> f_LT, std::function<RetT(lang::cc::Node::Expr::Bin3::op::GT_T)> f_GT) {
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
            langcc::AX();
        }
    }
}

namespace langcc {
    void pr_debug(ostream& os, FmtFlags flags, lang::cc::Node::Expr::Bin4::op_T x);
}

namespace lang::cc::Node::Expr::Bin4::op {
    enum struct _W {
        SHL,
    };
}

namespace lang::cc::Node::Expr::Bin4::op {
    struct _T: lang::cc::Node::_T {
        void write(langcc::Ref<std::ostream> os, langcc::FmtFlags flags);
        void write(langcc::Ref<langcc::PrBufStream_T> pb);
        lang::cc::Node::Expr::Bin4::op::_W w_;
        virtual ~_T();
        _T(lang::cc::Node::Expr::Bin4::op::_W w);
        bool is_SHL() const;
        lang::cc::Node::Expr::Bin4::op::SHL_T as_SHL();
        const lang::cc::Node::Expr::Bin4::op::SHL_T as_SHL() const;
        void match(std::function<void(lang::cc::Node::Expr::Bin4::op::SHL_T)> f_SHL);
        template<typename RetT> RetT match_expr(std::function<RetT(lang::cc::Node::Expr::Bin4::op::SHL_T)> f_SHL);
        void hash_ser_acc_lang_cc_Node_Expr_Bin4_op(langcc::SerBuf& buf) const;
        virtual void hash_ser_acc(langcc::SerBuf& buf) const = 0;
    };
}

template<typename RetT> RetT lang::cc::Node::Expr::Bin4::op::_T::match_expr(std::function<RetT(lang::cc::Node::Expr::Bin4::op::SHL_T)> f_SHL) {
    switch (this->w_) {
        case lang::cc::Node::Expr::Bin4::op::_W::SHL: {
            return f_SHL(this->as_SHL());
            break;
        }
        default: {
            langcc::AX();
        }
    }
}

namespace langcc {
    void pr_debug(ostream& os, FmtFlags flags, lang::cc::Node::Expr::Bin5::op_T x);
}

namespace lang::cc::Node::Expr::Bin5::op {
    enum struct _W {
        PLUS,
        MINUS,
    };
}

namespace lang::cc::Node::Expr::Bin5::op {
    struct _T: lang::cc::Node::_T {
        void write(langcc::Ref<std::ostream> os, langcc::FmtFlags flags);
        void write(langcc::Ref<langcc::PrBufStream_T> pb);
        lang::cc::Node::Expr::Bin5::op::_W w_;
        virtual ~_T();
        _T(lang::cc::Node::Expr::Bin5::op::_W w);
        bool is_PLUS() const;
        bool is_MINUS() const;
        lang::cc::Node::Expr::Bin5::op::PLUS_T as_PLUS();
        const lang::cc::Node::Expr::Bin5::op::PLUS_T as_PLUS() const;
        lang::cc::Node::Expr::Bin5::op::MINUS_T as_MINUS();
        const lang::cc::Node::Expr::Bin5::op::MINUS_T as_MINUS() const;
        void match(std::function<void(lang::cc::Node::Expr::Bin5::op::PLUS_T)> f_PLUS, std::function<void(lang::cc::Node::Expr::Bin5::op::MINUS_T)> f_MINUS);
        template<typename RetT> RetT match_expr(std::function<RetT(lang::cc::Node::Expr::Bin5::op::PLUS_T)> f_PLUS, std::function<RetT(lang::cc::Node::Expr::Bin5::op::MINUS_T)> f_MINUS);
        void hash_ser_acc_lang_cc_Node_Expr_Bin5_op(langcc::SerBuf& buf) const;
        virtual void hash_ser_acc(langcc::SerBuf& buf) const = 0;
    };
}

template<typename RetT> RetT lang::cc::Node::Expr::Bin5::op::_T::match_expr(std::function<RetT(lang::cc::Node::Expr::Bin5::op::PLUS_T)> f_PLUS, std::function<RetT(lang::cc::Node::Expr::Bin5::op::MINUS_T)> f_MINUS) {
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
            langcc::AX();
        }
    }
}

namespace langcc {
    void pr_debug(ostream& os, FmtFlags flags, lang::cc::Node::Expr::Bin6::op_T x);
}

namespace lang::cc::Node::Expr::Bin6::op {
    enum struct _W {
        TIMES,
        DIVIDE,
        MODULO,
    };
}

namespace lang::cc::Node::Expr::Bin6::op {
    struct _T: lang::cc::Node::_T {
        void write(langcc::Ref<std::ostream> os, langcc::FmtFlags flags);
        void write(langcc::Ref<langcc::PrBufStream_T> pb);
        lang::cc::Node::Expr::Bin6::op::_W w_;
        virtual ~_T();
        _T(lang::cc::Node::Expr::Bin6::op::_W w);
        bool is_TIMES() const;
        bool is_DIVIDE() const;
        bool is_MODULO() const;
        lang::cc::Node::Expr::Bin6::op::TIMES_T as_TIMES();
        const lang::cc::Node::Expr::Bin6::op::TIMES_T as_TIMES() const;
        lang::cc::Node::Expr::Bin6::op::DIVIDE_T as_DIVIDE();
        const lang::cc::Node::Expr::Bin6::op::DIVIDE_T as_DIVIDE() const;
        lang::cc::Node::Expr::Bin6::op::MODULO_T as_MODULO();
        const lang::cc::Node::Expr::Bin6::op::MODULO_T as_MODULO() const;
        void match(std::function<void(lang::cc::Node::Expr::Bin6::op::TIMES_T)> f_TIMES, std::function<void(lang::cc::Node::Expr::Bin6::op::DIVIDE_T)> f_DIVIDE, std::function<void(lang::cc::Node::Expr::Bin6::op::MODULO_T)> f_MODULO);
        template<typename RetT> RetT match_expr(std::function<RetT(lang::cc::Node::Expr::Bin6::op::TIMES_T)> f_TIMES, std::function<RetT(lang::cc::Node::Expr::Bin6::op::DIVIDE_T)> f_DIVIDE, std::function<RetT(lang::cc::Node::Expr::Bin6::op::MODULO_T)> f_MODULO);
        void hash_ser_acc_lang_cc_Node_Expr_Bin6_op(langcc::SerBuf& buf) const;
        virtual void hash_ser_acc(langcc::SerBuf& buf) const = 0;
    };
}

template<typename RetT> RetT lang::cc::Node::Expr::Bin6::op::_T::match_expr(std::function<RetT(lang::cc::Node::Expr::Bin6::op::TIMES_T)> f_TIMES, std::function<RetT(lang::cc::Node::Expr::Bin6::op::DIVIDE_T)> f_DIVIDE, std::function<RetT(lang::cc::Node::Expr::Bin6::op::MODULO_T)> f_MODULO) {
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
            langcc::AX();
        }
    }
}

namespace langcc {
    void pr_debug(ostream& os, FmtFlags flags, lang::cc::Node::Expr::Lit::Integer_T x);
}

namespace lang::cc::Node::Expr::Lit::Integer {
    lang::cc::Node::Expr::Lit::Integer_T make(langcc::Int id, langcc::TokenBounds bounds, bool is_top, langcc::ParserSymId sym, langcc::ParserAttrMask attr, langcc::ParserLookahead first_k, langcc::StrSlice val);
}

namespace lang::cc::Node::Expr::Lit::Integer {
    lang::cc::Node::Expr::Lit::Integer_T make_ext(langcc::ArenaPtr arena, langcc::Int id, langcc::TokenBounds bounds, bool is_top, langcc::ParserSymId sym, langcc::ParserAttrMask attr, langcc::ParserLookahead first_k, langcc::StrSlice val);
}

namespace lang::cc::Node::Expr::Lit::Integer {
    struct _T: lang::cc::Node::Expr::Lit::_T {
        void write(langcc::Ref<std::ostream> os, langcc::FmtFlags flags);
        void write(langcc::Ref<langcc::PrBufStream_T> pb);
        langcc::StrSlice val_;
        _T();
        lang::cc::Node::Expr::Lit::Integer_T with_id(langcc::Int id);
        lang::cc::Node::Expr::Lit::Integer_T with_bounds(langcc::TokenBounds bounds);
        lang::cc::Node::Expr::Lit::Integer_T with_is_top(bool is_top);
        lang::cc::Node::Expr::Lit::Integer_T with_sym(langcc::ParserSymId sym);
        lang::cc::Node::Expr::Lit::Integer_T with_attr(langcc::ParserAttrMask attr);
        lang::cc::Node::Expr::Lit::Integer_T with_first_k(langcc::ParserLookahead first_k);
        lang::cc::Node::Expr::Lit::Integer_T with_val(langcc::StrSlice val);
        void hash_ser_acc_lang_cc_Node_Expr_Lit_Integer(langcc::SerBuf& buf) const;
        virtual void hash_ser_acc(langcc::SerBuf& buf) const;
    };
}

namespace langcc {
    void pr_debug(ostream& os, FmtFlags flags, lang::cc::Node::Expr::Lit::Str__T x);
}

namespace lang::cc::Node::Expr::Lit::Str_ {
    lang::cc::Node::Expr::Lit::Str__T make(langcc::Int id, langcc::TokenBounds bounds, bool is_top, langcc::ParserSymId sym, langcc::ParserAttrMask attr, langcc::ParserLookahead first_k, langcc::StrSlice val);
}

namespace lang::cc::Node::Expr::Lit::Str_ {
    lang::cc::Node::Expr::Lit::Str__T make_ext(langcc::ArenaPtr arena, langcc::Int id, langcc::TokenBounds bounds, bool is_top, langcc::ParserSymId sym, langcc::ParserAttrMask attr, langcc::ParserLookahead first_k, langcc::StrSlice val);
}

namespace lang::cc::Node::Expr::Lit::Str_ {
    struct _T: lang::cc::Node::Expr::Lit::_T {
        void write(langcc::Ref<std::ostream> os, langcc::FmtFlags flags);
        void write(langcc::Ref<langcc::PrBufStream_T> pb);
        langcc::StrSlice val_;
        _T();
        lang::cc::Node::Expr::Lit::Str__T with_id(langcc::Int id);
        lang::cc::Node::Expr::Lit::Str__T with_bounds(langcc::TokenBounds bounds);
        lang::cc::Node::Expr::Lit::Str__T with_is_top(bool is_top);
        lang::cc::Node::Expr::Lit::Str__T with_sym(langcc::ParserSymId sym);
        lang::cc::Node::Expr::Lit::Str__T with_attr(langcc::ParserAttrMask attr);
        lang::cc::Node::Expr::Lit::Str__T with_first_k(langcc::ParserLookahead first_k);
        lang::cc::Node::Expr::Lit::Str__T with_val(langcc::StrSlice val);
        void hash_ser_acc_lang_cc_Node_Expr_Lit_Str_(langcc::SerBuf& buf) const;
        virtual void hash_ser_acc(langcc::SerBuf& buf) const;
    };
}

namespace langcc {
    void pr_debug(ostream& os, FmtFlags flags, lang::cc::Node::Expr::Lit::Array_T x);
}

namespace lang::cc::Node::Expr::Lit::Array {
    lang::cc::Node::Expr::Lit::Array_T make(langcc::Int id, langcc::TokenBounds bounds, bool is_top, langcc::ParserSymId sym, langcc::ParserAttrMask attr, langcc::ParserLookahead first_k, langcc::Vec_T<lang::cc::Node::Expr_T> items);
}

namespace lang::cc::Node::Expr::Lit::Array {
    lang::cc::Node::Expr::Lit::Array_T make_ext(langcc::ArenaPtr arena, langcc::Int id, langcc::TokenBounds bounds, bool is_top, langcc::ParserSymId sym, langcc::ParserAttrMask attr, langcc::ParserLookahead first_k, langcc::Vec_T<lang::cc::Node::Expr_T> items);
}

namespace lang::cc::Node::Expr::Lit::Array {
    struct _T: lang::cc::Node::Expr::Lit::_T {
        void write(langcc::Ref<std::ostream> os, langcc::FmtFlags flags);
        void write(langcc::Ref<langcc::PrBufStream_T> pb);
        langcc::Vec_T<lang::cc::Node::Expr_T> items_;
        _T();
        lang::cc::Node::Expr::Lit::Array_T with_id(langcc::Int id);
        lang::cc::Node::Expr::Lit::Array_T with_bounds(langcc::TokenBounds bounds);
        lang::cc::Node::Expr::Lit::Array_T with_is_top(bool is_top);
        lang::cc::Node::Expr::Lit::Array_T with_sym(langcc::ParserSymId sym);
        lang::cc::Node::Expr::Lit::Array_T with_attr(langcc::ParserAttrMask attr);
        lang::cc::Node::Expr::Lit::Array_T with_first_k(langcc::ParserLookahead first_k);
        lang::cc::Node::Expr::Lit::Array_T with_items(langcc::Vec_T<lang::cc::Node::Expr_T> items);
        void hash_ser_acc_lang_cc_Node_Expr_Lit_Array(langcc::SerBuf& buf) const;
        virtual void hash_ser_acc(langcc::SerBuf& buf) const;
    };
}

namespace langcc {
    void pr_debug(ostream& os, FmtFlags flags, lang::cc::Node::Decl::Struct::tmpl::item_T x);
}

namespace lang::cc::Node::Decl::Struct::tmpl::item {
    lang::cc::Node::Decl::Struct::tmpl::item_T make(langcc::Int id, langcc::TokenBounds bounds, bool is_top, langcc::ParserSymId sym, langcc::ParserAttrMask attr, langcc::ParserLookahead first_k, langcc::Vec_T<lang::cc::Node::Decl::Struct::tmpl::item::args::item_T> args);
}

namespace lang::cc::Node::Decl::Struct::tmpl::item {
    lang::cc::Node::Decl::Struct::tmpl::item_T make_ext(langcc::ArenaPtr arena, langcc::Int id, langcc::TokenBounds bounds, bool is_top, langcc::ParserSymId sym, langcc::ParserAttrMask attr, langcc::ParserLookahead first_k, langcc::Vec_T<lang::cc::Node::Decl::Struct::tmpl::item::args::item_T> args);
}

namespace lang::cc::Node::Decl::Struct::tmpl::item {
    struct _T: lang::cc::Node::_T {
        void write(langcc::Ref<std::ostream> os, langcc::FmtFlags flags);
        void write(langcc::Ref<langcc::PrBufStream_T> pb);
        langcc::Vec_T<lang::cc::Node::Decl::Struct::tmpl::item::args::item_T> args_;
        _T();
        lang::cc::Node::Decl::Struct::tmpl::item_T with_id(langcc::Int id);
        lang::cc::Node::Decl::Struct::tmpl::item_T with_bounds(langcc::TokenBounds bounds);
        lang::cc::Node::Decl::Struct::tmpl::item_T with_is_top(bool is_top);
        lang::cc::Node::Decl::Struct::tmpl::item_T with_sym(langcc::ParserSymId sym);
        lang::cc::Node::Decl::Struct::tmpl::item_T with_attr(langcc::ParserAttrMask attr);
        lang::cc::Node::Decl::Struct::tmpl::item_T with_first_k(langcc::ParserLookahead first_k);
        lang::cc::Node::Decl::Struct::tmpl::item_T with_args(langcc::Vec_T<lang::cc::Node::Decl::Struct::tmpl::item::args::item_T> args);
        void hash_ser_acc_lang_cc_Node_Decl_Struct_tmpl_item(langcc::SerBuf& buf) const;
        virtual void hash_ser_acc(langcc::SerBuf& buf) const;
    };
}

namespace langcc {
    void pr_debug(ostream& os, FmtFlags flags, lang::cc::Node::Entry::Fun::tmpl::item_T x);
}

namespace lang::cc::Node::Entry::Fun::tmpl::item {
    lang::cc::Node::Entry::Fun::tmpl::item_T make(langcc::Int id, langcc::TokenBounds bounds, bool is_top, langcc::ParserSymId sym, langcc::ParserAttrMask attr, langcc::ParserLookahead first_k, langcc::Vec_T<lang::cc::Node::Entry::Fun::tmpl::item::args::item_T> args);
}

namespace lang::cc::Node::Entry::Fun::tmpl::item {
    lang::cc::Node::Entry::Fun::tmpl::item_T make_ext(langcc::ArenaPtr arena, langcc::Int id, langcc::TokenBounds bounds, bool is_top, langcc::ParserSymId sym, langcc::ParserAttrMask attr, langcc::ParserLookahead first_k, langcc::Vec_T<lang::cc::Node::Entry::Fun::tmpl::item::args::item_T> args);
}

namespace lang::cc::Node::Entry::Fun::tmpl::item {
    struct _T: lang::cc::Node::_T {
        void write(langcc::Ref<std::ostream> os, langcc::FmtFlags flags);
        void write(langcc::Ref<langcc::PrBufStream_T> pb);
        langcc::Vec_T<lang::cc::Node::Entry::Fun::tmpl::item::args::item_T> args_;
        _T();
        lang::cc::Node::Entry::Fun::tmpl::item_T with_id(langcc::Int id);
        lang::cc::Node::Entry::Fun::tmpl::item_T with_bounds(langcc::TokenBounds bounds);
        lang::cc::Node::Entry::Fun::tmpl::item_T with_is_top(bool is_top);
        lang::cc::Node::Entry::Fun::tmpl::item_T with_sym(langcc::ParserSymId sym);
        lang::cc::Node::Entry::Fun::tmpl::item_T with_attr(langcc::ParserAttrMask attr);
        lang::cc::Node::Entry::Fun::tmpl::item_T with_first_k(langcc::ParserLookahead first_k);
        lang::cc::Node::Entry::Fun::tmpl::item_T with_args(langcc::Vec_T<lang::cc::Node::Entry::Fun::tmpl::item::args::item_T> args);
        void hash_ser_acc_lang_cc_Node_Entry_Fun_tmpl_item(langcc::SerBuf& buf) const;
        virtual void hash_ser_acc(langcc::SerBuf& buf) const;
    };
}

namespace langcc {
    void pr_debug(ostream& os, FmtFlags flags, lang::cc::Node::Decl::Fun::tmpl::item_T x);
}

namespace lang::cc::Node::Decl::Fun::tmpl::item {
    lang::cc::Node::Decl::Fun::tmpl::item_T make(langcc::Int id, langcc::TokenBounds bounds, bool is_top, langcc::ParserSymId sym, langcc::ParserAttrMask attr, langcc::ParserLookahead first_k, langcc::Vec_T<lang::cc::Node::Decl::Fun::tmpl::item::args::item_T> args);
}

namespace lang::cc::Node::Decl::Fun::tmpl::item {
    lang::cc::Node::Decl::Fun::tmpl::item_T make_ext(langcc::ArenaPtr arena, langcc::Int id, langcc::TokenBounds bounds, bool is_top, langcc::ParserSymId sym, langcc::ParserAttrMask attr, langcc::ParserLookahead first_k, langcc::Vec_T<lang::cc::Node::Decl::Fun::tmpl::item::args::item_T> args);
}

namespace lang::cc::Node::Decl::Fun::tmpl::item {
    struct _T: lang::cc::Node::_T {
        void write(langcc::Ref<std::ostream> os, langcc::FmtFlags flags);
        void write(langcc::Ref<langcc::PrBufStream_T> pb);
        langcc::Vec_T<lang::cc::Node::Decl::Fun::tmpl::item::args::item_T> args_;
        _T();
        lang::cc::Node::Decl::Fun::tmpl::item_T with_id(langcc::Int id);
        lang::cc::Node::Decl::Fun::tmpl::item_T with_bounds(langcc::TokenBounds bounds);
        lang::cc::Node::Decl::Fun::tmpl::item_T with_is_top(bool is_top);
        lang::cc::Node::Decl::Fun::tmpl::item_T with_sym(langcc::ParserSymId sym);
        lang::cc::Node::Decl::Fun::tmpl::item_T with_attr(langcc::ParserAttrMask attr);
        lang::cc::Node::Decl::Fun::tmpl::item_T with_first_k(langcc::ParserLookahead first_k);
        lang::cc::Node::Decl::Fun::tmpl::item_T with_args(langcc::Vec_T<lang::cc::Node::Decl::Fun::tmpl::item::args::item_T> args);
        void hash_ser_acc_lang_cc_Node_Decl_Fun_tmpl_item(langcc::SerBuf& buf) const;
        virtual void hash_ser_acc(langcc::SerBuf& buf) const;
    };
}

namespace langcc {
    void pr_debug(ostream& os, FmtFlags flags, lang::cc::Node::Decl::UsingAlias::tmpl::item_T x);
}

namespace lang::cc::Node::Decl::UsingAlias::tmpl::item {
    lang::cc::Node::Decl::UsingAlias::tmpl::item_T make(langcc::Int id, langcc::TokenBounds bounds, bool is_top, langcc::ParserSymId sym, langcc::ParserAttrMask attr, langcc::ParserLookahead first_k, langcc::Vec_T<lang::cc::Node::Decl::UsingAlias::tmpl::item::args::item_T> args);
}

namespace lang::cc::Node::Decl::UsingAlias::tmpl::item {
    lang::cc::Node::Decl::UsingAlias::tmpl::item_T make_ext(langcc::ArenaPtr arena, langcc::Int id, langcc::TokenBounds bounds, bool is_top, langcc::ParserSymId sym, langcc::ParserAttrMask attr, langcc::ParserLookahead first_k, langcc::Vec_T<lang::cc::Node::Decl::UsingAlias::tmpl::item::args::item_T> args);
}

namespace lang::cc::Node::Decl::UsingAlias::tmpl::item {
    struct _T: lang::cc::Node::_T {
        void write(langcc::Ref<std::ostream> os, langcc::FmtFlags flags);
        void write(langcc::Ref<langcc::PrBufStream_T> pb);
        langcc::Vec_T<lang::cc::Node::Decl::UsingAlias::tmpl::item::args::item_T> args_;
        _T();
        lang::cc::Node::Decl::UsingAlias::tmpl::item_T with_id(langcc::Int id);
        lang::cc::Node::Decl::UsingAlias::tmpl::item_T with_bounds(langcc::TokenBounds bounds);
        lang::cc::Node::Decl::UsingAlias::tmpl::item_T with_is_top(bool is_top);
        lang::cc::Node::Decl::UsingAlias::tmpl::item_T with_sym(langcc::ParserSymId sym);
        lang::cc::Node::Decl::UsingAlias::tmpl::item_T with_attr(langcc::ParserAttrMask attr);
        lang::cc::Node::Decl::UsingAlias::tmpl::item_T with_first_k(langcc::ParserLookahead first_k);
        lang::cc::Node::Decl::UsingAlias::tmpl::item_T with_args(langcc::Vec_T<lang::cc::Node::Decl::UsingAlias::tmpl::item::args::item_T> args);
        void hash_ser_acc_lang_cc_Node_Decl_UsingAlias_tmpl_item(langcc::SerBuf& buf) const;
        virtual void hash_ser_acc(langcc::SerBuf& buf) const;
    };
}

namespace langcc {
    void pr_debug(ostream& os, FmtFlags flags, lang::cc::Node::TypedDecl::vars::item::val_T x);
}

namespace lang::cc::Node::TypedDecl::vars::item::val {
    lang::cc::Node::TypedDecl::vars::item::val_T make(langcc::Int id, langcc::TokenBounds bounds, bool is_top, langcc::ParserSymId sym, langcc::ParserAttrMask attr, langcc::ParserLookahead first_k, lang::cc::Node::Expr_T init_val);
}

namespace lang::cc::Node::TypedDecl::vars::item::val {
    lang::cc::Node::TypedDecl::vars::item::val_T make_ext(langcc::ArenaPtr arena, langcc::Int id, langcc::TokenBounds bounds, bool is_top, langcc::ParserSymId sym, langcc::ParserAttrMask attr, langcc::ParserLookahead first_k, lang::cc::Node::Expr_T init_val);
}

namespace lang::cc::Node::TypedDecl::vars::item::val {
    struct _T: lang::cc::Node::_T {
        void write(langcc::Ref<std::ostream> os, langcc::FmtFlags flags);
        void write(langcc::Ref<langcc::PrBufStream_T> pb);
        lang::cc::Node::Expr_T init_val_;
        _T();
        lang::cc::Node::TypedDecl::vars::item::val_T with_id(langcc::Int id);
        lang::cc::Node::TypedDecl::vars::item::val_T with_bounds(langcc::TokenBounds bounds);
        lang::cc::Node::TypedDecl::vars::item::val_T with_is_top(bool is_top);
        lang::cc::Node::TypedDecl::vars::item::val_T with_sym(langcc::ParserSymId sym);
        lang::cc::Node::TypedDecl::vars::item::val_T with_attr(langcc::ParserAttrMask attr);
        lang::cc::Node::TypedDecl::vars::item::val_T with_first_k(langcc::ParserLookahead first_k);
        lang::cc::Node::TypedDecl::vars::item::val_T with_init_val(lang::cc::Node::Expr_T init_val);
        void hash_ser_acc_lang_cc_Node_TypedDecl_vars_item_val(langcc::SerBuf& buf) const;
        virtual void hash_ser_acc(langcc::SerBuf& buf) const;
    };
}

namespace langcc {
    void pr_debug(ostream& os, FmtFlags flags, lang::cc::Node::Expr::UnaryPre::op::NOT_T x);
}

namespace lang::cc::Node::Expr::UnaryPre::op::NOT {
    lang::cc::Node::Expr::UnaryPre::op::NOT_T make(langcc::Int id, langcc::TokenBounds bounds, bool is_top, langcc::ParserSymId sym, langcc::ParserAttrMask attr, langcc::ParserLookahead first_k);
}

namespace lang::cc::Node::Expr::UnaryPre::op::NOT {
    lang::cc::Node::Expr::UnaryPre::op::NOT_T make_ext(langcc::ArenaPtr arena, langcc::Int id, langcc::TokenBounds bounds, bool is_top, langcc::ParserSymId sym, langcc::ParserAttrMask attr, langcc::ParserLookahead first_k);
}

namespace lang::cc::Node::Expr::UnaryPre::op::NOT {
    struct _T: lang::cc::Node::Expr::UnaryPre::op::_T {
        void write(langcc::Ref<std::ostream> os, langcc::FmtFlags flags);
        void write(langcc::Ref<langcc::PrBufStream_T> pb);
        _T();
        lang::cc::Node::Expr::UnaryPre::op::NOT_T with_id(langcc::Int id);
        lang::cc::Node::Expr::UnaryPre::op::NOT_T with_bounds(langcc::TokenBounds bounds);
        lang::cc::Node::Expr::UnaryPre::op::NOT_T with_is_top(bool is_top);
        lang::cc::Node::Expr::UnaryPre::op::NOT_T with_sym(langcc::ParserSymId sym);
        lang::cc::Node::Expr::UnaryPre::op::NOT_T with_attr(langcc::ParserAttrMask attr);
        lang::cc::Node::Expr::UnaryPre::op::NOT_T with_first_k(langcc::ParserLookahead first_k);
        void hash_ser_acc_lang_cc_Node_Expr_UnaryPre_op_NOT(langcc::SerBuf& buf) const;
        virtual void hash_ser_acc(langcc::SerBuf& buf) const;
    };
}

namespace langcc {
    void pr_debug(ostream& os, FmtFlags flags, lang::cc::Node::Expr::UnaryPre::op::NEG_T x);
}

namespace lang::cc::Node::Expr::UnaryPre::op::NEG {
    lang::cc::Node::Expr::UnaryPre::op::NEG_T make(langcc::Int id, langcc::TokenBounds bounds, bool is_top, langcc::ParserSymId sym, langcc::ParserAttrMask attr, langcc::ParserLookahead first_k);
}

namespace lang::cc::Node::Expr::UnaryPre::op::NEG {
    lang::cc::Node::Expr::UnaryPre::op::NEG_T make_ext(langcc::ArenaPtr arena, langcc::Int id, langcc::TokenBounds bounds, bool is_top, langcc::ParserSymId sym, langcc::ParserAttrMask attr, langcc::ParserLookahead first_k);
}

namespace lang::cc::Node::Expr::UnaryPre::op::NEG {
    struct _T: lang::cc::Node::Expr::UnaryPre::op::_T {
        void write(langcc::Ref<std::ostream> os, langcc::FmtFlags flags);
        void write(langcc::Ref<langcc::PrBufStream_T> pb);
        _T();
        lang::cc::Node::Expr::UnaryPre::op::NEG_T with_id(langcc::Int id);
        lang::cc::Node::Expr::UnaryPre::op::NEG_T with_bounds(langcc::TokenBounds bounds);
        lang::cc::Node::Expr::UnaryPre::op::NEG_T with_is_top(bool is_top);
        lang::cc::Node::Expr::UnaryPre::op::NEG_T with_sym(langcc::ParserSymId sym);
        lang::cc::Node::Expr::UnaryPre::op::NEG_T with_attr(langcc::ParserAttrMask attr);
        lang::cc::Node::Expr::UnaryPre::op::NEG_T with_first_k(langcc::ParserLookahead first_k);
        void hash_ser_acc_lang_cc_Node_Expr_UnaryPre_op_NEG(langcc::SerBuf& buf) const;
        virtual void hash_ser_acc(langcc::SerBuf& buf) const;
    };
}

namespace langcc {
    void pr_debug(ostream& os, FmtFlags flags, lang::cc::Node::Expr::IncDecPre::op::INC_T x);
}

namespace lang::cc::Node::Expr::IncDecPre::op::INC {
    lang::cc::Node::Expr::IncDecPre::op::INC_T make(langcc::Int id, langcc::TokenBounds bounds, bool is_top, langcc::ParserSymId sym, langcc::ParserAttrMask attr, langcc::ParserLookahead first_k);
}

namespace lang::cc::Node::Expr::IncDecPre::op::INC {
    lang::cc::Node::Expr::IncDecPre::op::INC_T make_ext(langcc::ArenaPtr arena, langcc::Int id, langcc::TokenBounds bounds, bool is_top, langcc::ParserSymId sym, langcc::ParserAttrMask attr, langcc::ParserLookahead first_k);
}

namespace lang::cc::Node::Expr::IncDecPre::op::INC {
    struct _T: lang::cc::Node::Expr::IncDecPre::op::_T {
        void write(langcc::Ref<std::ostream> os, langcc::FmtFlags flags);
        void write(langcc::Ref<langcc::PrBufStream_T> pb);
        _T();
        lang::cc::Node::Expr::IncDecPre::op::INC_T with_id(langcc::Int id);
        lang::cc::Node::Expr::IncDecPre::op::INC_T with_bounds(langcc::TokenBounds bounds);
        lang::cc::Node::Expr::IncDecPre::op::INC_T with_is_top(bool is_top);
        lang::cc::Node::Expr::IncDecPre::op::INC_T with_sym(langcc::ParserSymId sym);
        lang::cc::Node::Expr::IncDecPre::op::INC_T with_attr(langcc::ParserAttrMask attr);
        lang::cc::Node::Expr::IncDecPre::op::INC_T with_first_k(langcc::ParserLookahead first_k);
        void hash_ser_acc_lang_cc_Node_Expr_IncDecPre_op_INC(langcc::SerBuf& buf) const;
        virtual void hash_ser_acc(langcc::SerBuf& buf) const;
    };
}

namespace langcc {
    void pr_debug(ostream& os, FmtFlags flags, lang::cc::Node::Expr::IncDecPre::op::DEC_T x);
}

namespace lang::cc::Node::Expr::IncDecPre::op::DEC {
    lang::cc::Node::Expr::IncDecPre::op::DEC_T make(langcc::Int id, langcc::TokenBounds bounds, bool is_top, langcc::ParserSymId sym, langcc::ParserAttrMask attr, langcc::ParserLookahead first_k);
}

namespace lang::cc::Node::Expr::IncDecPre::op::DEC {
    lang::cc::Node::Expr::IncDecPre::op::DEC_T make_ext(langcc::ArenaPtr arena, langcc::Int id, langcc::TokenBounds bounds, bool is_top, langcc::ParserSymId sym, langcc::ParserAttrMask attr, langcc::ParserLookahead first_k);
}

namespace lang::cc::Node::Expr::IncDecPre::op::DEC {
    struct _T: lang::cc::Node::Expr::IncDecPre::op::_T {
        void write(langcc::Ref<std::ostream> os, langcc::FmtFlags flags);
        void write(langcc::Ref<langcc::PrBufStream_T> pb);
        _T();
        lang::cc::Node::Expr::IncDecPre::op::DEC_T with_id(langcc::Int id);
        lang::cc::Node::Expr::IncDecPre::op::DEC_T with_bounds(langcc::TokenBounds bounds);
        lang::cc::Node::Expr::IncDecPre::op::DEC_T with_is_top(bool is_top);
        lang::cc::Node::Expr::IncDecPre::op::DEC_T with_sym(langcc::ParserSymId sym);
        lang::cc::Node::Expr::IncDecPre::op::DEC_T with_attr(langcc::ParserAttrMask attr);
        lang::cc::Node::Expr::IncDecPre::op::DEC_T with_first_k(langcc::ParserLookahead first_k);
        void hash_ser_acc_lang_cc_Node_Expr_IncDecPre_op_DEC(langcc::SerBuf& buf) const;
        virtual void hash_ser_acc(langcc::SerBuf& buf) const;
    };
}

namespace langcc {
    void pr_debug(ostream& os, FmtFlags flags, lang::cc::Node::Expr::IncDecPost::op::INC_T x);
}

namespace lang::cc::Node::Expr::IncDecPost::op::INC {
    lang::cc::Node::Expr::IncDecPost::op::INC_T make(langcc::Int id, langcc::TokenBounds bounds, bool is_top, langcc::ParserSymId sym, langcc::ParserAttrMask attr, langcc::ParserLookahead first_k);
}

namespace lang::cc::Node::Expr::IncDecPost::op::INC {
    lang::cc::Node::Expr::IncDecPost::op::INC_T make_ext(langcc::ArenaPtr arena, langcc::Int id, langcc::TokenBounds bounds, bool is_top, langcc::ParserSymId sym, langcc::ParserAttrMask attr, langcc::ParserLookahead first_k);
}

namespace lang::cc::Node::Expr::IncDecPost::op::INC {
    struct _T: lang::cc::Node::Expr::IncDecPost::op::_T {
        void write(langcc::Ref<std::ostream> os, langcc::FmtFlags flags);
        void write(langcc::Ref<langcc::PrBufStream_T> pb);
        _T();
        lang::cc::Node::Expr::IncDecPost::op::INC_T with_id(langcc::Int id);
        lang::cc::Node::Expr::IncDecPost::op::INC_T with_bounds(langcc::TokenBounds bounds);
        lang::cc::Node::Expr::IncDecPost::op::INC_T with_is_top(bool is_top);
        lang::cc::Node::Expr::IncDecPost::op::INC_T with_sym(langcc::ParserSymId sym);
        lang::cc::Node::Expr::IncDecPost::op::INC_T with_attr(langcc::ParserAttrMask attr);
        lang::cc::Node::Expr::IncDecPost::op::INC_T with_first_k(langcc::ParserLookahead first_k);
        void hash_ser_acc_lang_cc_Node_Expr_IncDecPost_op_INC(langcc::SerBuf& buf) const;
        virtual void hash_ser_acc(langcc::SerBuf& buf) const;
    };
}

namespace langcc {
    void pr_debug(ostream& os, FmtFlags flags, lang::cc::Node::Expr::IncDecPost::op::DEC_T x);
}

namespace lang::cc::Node::Expr::IncDecPost::op::DEC {
    lang::cc::Node::Expr::IncDecPost::op::DEC_T make(langcc::Int id, langcc::TokenBounds bounds, bool is_top, langcc::ParserSymId sym, langcc::ParserAttrMask attr, langcc::ParserLookahead first_k);
}

namespace lang::cc::Node::Expr::IncDecPost::op::DEC {
    lang::cc::Node::Expr::IncDecPost::op::DEC_T make_ext(langcc::ArenaPtr arena, langcc::Int id, langcc::TokenBounds bounds, bool is_top, langcc::ParserSymId sym, langcc::ParserAttrMask attr, langcc::ParserLookahead first_k);
}

namespace lang::cc::Node::Expr::IncDecPost::op::DEC {
    struct _T: lang::cc::Node::Expr::IncDecPost::op::_T {
        void write(langcc::Ref<std::ostream> os, langcc::FmtFlags flags);
        void write(langcc::Ref<langcc::PrBufStream_T> pb);
        _T();
        lang::cc::Node::Expr::IncDecPost::op::DEC_T with_id(langcc::Int id);
        lang::cc::Node::Expr::IncDecPost::op::DEC_T with_bounds(langcc::TokenBounds bounds);
        lang::cc::Node::Expr::IncDecPost::op::DEC_T with_is_top(bool is_top);
        lang::cc::Node::Expr::IncDecPost::op::DEC_T with_sym(langcc::ParserSymId sym);
        lang::cc::Node::Expr::IncDecPost::op::DEC_T with_attr(langcc::ParserAttrMask attr);
        lang::cc::Node::Expr::IncDecPost::op::DEC_T with_first_k(langcc::ParserLookahead first_k);
        void hash_ser_acc_lang_cc_Node_Expr_IncDecPost_op_DEC(langcc::SerBuf& buf) const;
        virtual void hash_ser_acc(langcc::SerBuf& buf) const;
    };
}

namespace langcc {
    void pr_debug(ostream& os, FmtFlags flags, lang::cc::Node::Expr::Bin1::op::LOR_T x);
}

namespace lang::cc::Node::Expr::Bin1::op::LOR {
    lang::cc::Node::Expr::Bin1::op::LOR_T make(langcc::Int id, langcc::TokenBounds bounds, bool is_top, langcc::ParserSymId sym, langcc::ParserAttrMask attr, langcc::ParserLookahead first_k);
}

namespace lang::cc::Node::Expr::Bin1::op::LOR {
    lang::cc::Node::Expr::Bin1::op::LOR_T make_ext(langcc::ArenaPtr arena, langcc::Int id, langcc::TokenBounds bounds, bool is_top, langcc::ParserSymId sym, langcc::ParserAttrMask attr, langcc::ParserLookahead first_k);
}

namespace lang::cc::Node::Expr::Bin1::op::LOR {
    struct _T: lang::cc::Node::Expr::Bin1::op::_T {
        void write(langcc::Ref<std::ostream> os, langcc::FmtFlags flags);
        void write(langcc::Ref<langcc::PrBufStream_T> pb);
        _T();
        lang::cc::Node::Expr::Bin1::op::LOR_T with_id(langcc::Int id);
        lang::cc::Node::Expr::Bin1::op::LOR_T with_bounds(langcc::TokenBounds bounds);
        lang::cc::Node::Expr::Bin1::op::LOR_T with_is_top(bool is_top);
        lang::cc::Node::Expr::Bin1::op::LOR_T with_sym(langcc::ParserSymId sym);
        lang::cc::Node::Expr::Bin1::op::LOR_T with_attr(langcc::ParserAttrMask attr);
        lang::cc::Node::Expr::Bin1::op::LOR_T with_first_k(langcc::ParserLookahead first_k);
        void hash_ser_acc_lang_cc_Node_Expr_Bin1_op_LOR(langcc::SerBuf& buf) const;
        virtual void hash_ser_acc(langcc::SerBuf& buf) const;
    };
}

namespace langcc {
    void pr_debug(ostream& os, FmtFlags flags, lang::cc::Node::Expr::Bin2::op::LAND_T x);
}

namespace lang::cc::Node::Expr::Bin2::op::LAND {
    lang::cc::Node::Expr::Bin2::op::LAND_T make(langcc::Int id, langcc::TokenBounds bounds, bool is_top, langcc::ParserSymId sym, langcc::ParserAttrMask attr, langcc::ParserLookahead first_k);
}

namespace lang::cc::Node::Expr::Bin2::op::LAND {
    lang::cc::Node::Expr::Bin2::op::LAND_T make_ext(langcc::ArenaPtr arena, langcc::Int id, langcc::TokenBounds bounds, bool is_top, langcc::ParserSymId sym, langcc::ParserAttrMask attr, langcc::ParserLookahead first_k);
}

namespace lang::cc::Node::Expr::Bin2::op::LAND {
    struct _T: lang::cc::Node::Expr::Bin2::op::_T {
        void write(langcc::Ref<std::ostream> os, langcc::FmtFlags flags);
        void write(langcc::Ref<langcc::PrBufStream_T> pb);
        _T();
        lang::cc::Node::Expr::Bin2::op::LAND_T with_id(langcc::Int id);
        lang::cc::Node::Expr::Bin2::op::LAND_T with_bounds(langcc::TokenBounds bounds);
        lang::cc::Node::Expr::Bin2::op::LAND_T with_is_top(bool is_top);
        lang::cc::Node::Expr::Bin2::op::LAND_T with_sym(langcc::ParserSymId sym);
        lang::cc::Node::Expr::Bin2::op::LAND_T with_attr(langcc::ParserAttrMask attr);
        lang::cc::Node::Expr::Bin2::op::LAND_T with_first_k(langcc::ParserLookahead first_k);
        void hash_ser_acc_lang_cc_Node_Expr_Bin2_op_LAND(langcc::SerBuf& buf) const;
        virtual void hash_ser_acc(langcc::SerBuf& buf) const;
    };
}

namespace langcc {
    void pr_debug(ostream& os, FmtFlags flags, lang::cc::Node::Expr::Bin3::op::EQ_T x);
}

namespace lang::cc::Node::Expr::Bin3::op::EQ {
    lang::cc::Node::Expr::Bin3::op::EQ_T make(langcc::Int id, langcc::TokenBounds bounds, bool is_top, langcc::ParserSymId sym, langcc::ParserAttrMask attr, langcc::ParserLookahead first_k);
}

namespace lang::cc::Node::Expr::Bin3::op::EQ {
    lang::cc::Node::Expr::Bin3::op::EQ_T make_ext(langcc::ArenaPtr arena, langcc::Int id, langcc::TokenBounds bounds, bool is_top, langcc::ParserSymId sym, langcc::ParserAttrMask attr, langcc::ParserLookahead first_k);
}

namespace lang::cc::Node::Expr::Bin3::op::EQ {
    struct _T: lang::cc::Node::Expr::Bin3::op::_T {
        void write(langcc::Ref<std::ostream> os, langcc::FmtFlags flags);
        void write(langcc::Ref<langcc::PrBufStream_T> pb);
        _T();
        lang::cc::Node::Expr::Bin3::op::EQ_T with_id(langcc::Int id);
        lang::cc::Node::Expr::Bin3::op::EQ_T with_bounds(langcc::TokenBounds bounds);
        lang::cc::Node::Expr::Bin3::op::EQ_T with_is_top(bool is_top);
        lang::cc::Node::Expr::Bin3::op::EQ_T with_sym(langcc::ParserSymId sym);
        lang::cc::Node::Expr::Bin3::op::EQ_T with_attr(langcc::ParserAttrMask attr);
        lang::cc::Node::Expr::Bin3::op::EQ_T with_first_k(langcc::ParserLookahead first_k);
        void hash_ser_acc_lang_cc_Node_Expr_Bin3_op_EQ(langcc::SerBuf& buf) const;
        virtual void hash_ser_acc(langcc::SerBuf& buf) const;
    };
}

namespace langcc {
    void pr_debug(ostream& os, FmtFlags flags, lang::cc::Node::Expr::Bin3::op::NE_T x);
}

namespace lang::cc::Node::Expr::Bin3::op::NE {
    lang::cc::Node::Expr::Bin3::op::NE_T make(langcc::Int id, langcc::TokenBounds bounds, bool is_top, langcc::ParserSymId sym, langcc::ParserAttrMask attr, langcc::ParserLookahead first_k);
}

namespace lang::cc::Node::Expr::Bin3::op::NE {
    lang::cc::Node::Expr::Bin3::op::NE_T make_ext(langcc::ArenaPtr arena, langcc::Int id, langcc::TokenBounds bounds, bool is_top, langcc::ParserSymId sym, langcc::ParserAttrMask attr, langcc::ParserLookahead first_k);
}

namespace lang::cc::Node::Expr::Bin3::op::NE {
    struct _T: lang::cc::Node::Expr::Bin3::op::_T {
        void write(langcc::Ref<std::ostream> os, langcc::FmtFlags flags);
        void write(langcc::Ref<langcc::PrBufStream_T> pb);
        _T();
        lang::cc::Node::Expr::Bin3::op::NE_T with_id(langcc::Int id);
        lang::cc::Node::Expr::Bin3::op::NE_T with_bounds(langcc::TokenBounds bounds);
        lang::cc::Node::Expr::Bin3::op::NE_T with_is_top(bool is_top);
        lang::cc::Node::Expr::Bin3::op::NE_T with_sym(langcc::ParserSymId sym);
        lang::cc::Node::Expr::Bin3::op::NE_T with_attr(langcc::ParserAttrMask attr);
        lang::cc::Node::Expr::Bin3::op::NE_T with_first_k(langcc::ParserLookahead first_k);
        void hash_ser_acc_lang_cc_Node_Expr_Bin3_op_NE(langcc::SerBuf& buf) const;
        virtual void hash_ser_acc(langcc::SerBuf& buf) const;
    };
}

namespace langcc {
    void pr_debug(ostream& os, FmtFlags flags, lang::cc::Node::Expr::Bin3::op::LE_T x);
}

namespace lang::cc::Node::Expr::Bin3::op::LE {
    lang::cc::Node::Expr::Bin3::op::LE_T make(langcc::Int id, langcc::TokenBounds bounds, bool is_top, langcc::ParserSymId sym, langcc::ParserAttrMask attr, langcc::ParserLookahead first_k);
}

namespace lang::cc::Node::Expr::Bin3::op::LE {
    lang::cc::Node::Expr::Bin3::op::LE_T make_ext(langcc::ArenaPtr arena, langcc::Int id, langcc::TokenBounds bounds, bool is_top, langcc::ParserSymId sym, langcc::ParserAttrMask attr, langcc::ParserLookahead first_k);
}

namespace lang::cc::Node::Expr::Bin3::op::LE {
    struct _T: lang::cc::Node::Expr::Bin3::op::_T {
        void write(langcc::Ref<std::ostream> os, langcc::FmtFlags flags);
        void write(langcc::Ref<langcc::PrBufStream_T> pb);
        _T();
        lang::cc::Node::Expr::Bin3::op::LE_T with_id(langcc::Int id);
        lang::cc::Node::Expr::Bin3::op::LE_T with_bounds(langcc::TokenBounds bounds);
        lang::cc::Node::Expr::Bin3::op::LE_T with_is_top(bool is_top);
        lang::cc::Node::Expr::Bin3::op::LE_T with_sym(langcc::ParserSymId sym);
        lang::cc::Node::Expr::Bin3::op::LE_T with_attr(langcc::ParserAttrMask attr);
        lang::cc::Node::Expr::Bin3::op::LE_T with_first_k(langcc::ParserLookahead first_k);
        void hash_ser_acc_lang_cc_Node_Expr_Bin3_op_LE(langcc::SerBuf& buf) const;
        virtual void hash_ser_acc(langcc::SerBuf& buf) const;
    };
}

namespace langcc {
    void pr_debug(ostream& os, FmtFlags flags, lang::cc::Node::Expr::Bin3::op::GE_T x);
}

namespace lang::cc::Node::Expr::Bin3::op::GE {
    lang::cc::Node::Expr::Bin3::op::GE_T make(langcc::Int id, langcc::TokenBounds bounds, bool is_top, langcc::ParserSymId sym, langcc::ParserAttrMask attr, langcc::ParserLookahead first_k);
}

namespace lang::cc::Node::Expr::Bin3::op::GE {
    lang::cc::Node::Expr::Bin3::op::GE_T make_ext(langcc::ArenaPtr arena, langcc::Int id, langcc::TokenBounds bounds, bool is_top, langcc::ParserSymId sym, langcc::ParserAttrMask attr, langcc::ParserLookahead first_k);
}

namespace lang::cc::Node::Expr::Bin3::op::GE {
    struct _T: lang::cc::Node::Expr::Bin3::op::_T {
        void write(langcc::Ref<std::ostream> os, langcc::FmtFlags flags);
        void write(langcc::Ref<langcc::PrBufStream_T> pb);
        _T();
        lang::cc::Node::Expr::Bin3::op::GE_T with_id(langcc::Int id);
        lang::cc::Node::Expr::Bin3::op::GE_T with_bounds(langcc::TokenBounds bounds);
        lang::cc::Node::Expr::Bin3::op::GE_T with_is_top(bool is_top);
        lang::cc::Node::Expr::Bin3::op::GE_T with_sym(langcc::ParserSymId sym);
        lang::cc::Node::Expr::Bin3::op::GE_T with_attr(langcc::ParserAttrMask attr);
        lang::cc::Node::Expr::Bin3::op::GE_T with_first_k(langcc::ParserLookahead first_k);
        void hash_ser_acc_lang_cc_Node_Expr_Bin3_op_GE(langcc::SerBuf& buf) const;
        virtual void hash_ser_acc(langcc::SerBuf& buf) const;
    };
}

namespace langcc {
    void pr_debug(ostream& os, FmtFlags flags, lang::cc::Node::Expr::Bin3::op::LT_T x);
}

namespace lang::cc::Node::Expr::Bin3::op::LT {
    lang::cc::Node::Expr::Bin3::op::LT_T make(langcc::Int id, langcc::TokenBounds bounds, bool is_top, langcc::ParserSymId sym, langcc::ParserAttrMask attr, langcc::ParserLookahead first_k);
}

namespace lang::cc::Node::Expr::Bin3::op::LT {
    lang::cc::Node::Expr::Bin3::op::LT_T make_ext(langcc::ArenaPtr arena, langcc::Int id, langcc::TokenBounds bounds, bool is_top, langcc::ParserSymId sym, langcc::ParserAttrMask attr, langcc::ParserLookahead first_k);
}

namespace lang::cc::Node::Expr::Bin3::op::LT {
    struct _T: lang::cc::Node::Expr::Bin3::op::_T {
        void write(langcc::Ref<std::ostream> os, langcc::FmtFlags flags);
        void write(langcc::Ref<langcc::PrBufStream_T> pb);
        _T();
        lang::cc::Node::Expr::Bin3::op::LT_T with_id(langcc::Int id);
        lang::cc::Node::Expr::Bin3::op::LT_T with_bounds(langcc::TokenBounds bounds);
        lang::cc::Node::Expr::Bin3::op::LT_T with_is_top(bool is_top);
        lang::cc::Node::Expr::Bin3::op::LT_T with_sym(langcc::ParserSymId sym);
        lang::cc::Node::Expr::Bin3::op::LT_T with_attr(langcc::ParserAttrMask attr);
        lang::cc::Node::Expr::Bin3::op::LT_T with_first_k(langcc::ParserLookahead first_k);
        void hash_ser_acc_lang_cc_Node_Expr_Bin3_op_LT(langcc::SerBuf& buf) const;
        virtual void hash_ser_acc(langcc::SerBuf& buf) const;
    };
}

namespace langcc {
    void pr_debug(ostream& os, FmtFlags flags, lang::cc::Node::Expr::Bin3::op::GT_T x);
}

namespace lang::cc::Node::Expr::Bin3::op::GT {
    lang::cc::Node::Expr::Bin3::op::GT_T make(langcc::Int id, langcc::TokenBounds bounds, bool is_top, langcc::ParserSymId sym, langcc::ParserAttrMask attr, langcc::ParserLookahead first_k);
}

namespace lang::cc::Node::Expr::Bin3::op::GT {
    lang::cc::Node::Expr::Bin3::op::GT_T make_ext(langcc::ArenaPtr arena, langcc::Int id, langcc::TokenBounds bounds, bool is_top, langcc::ParserSymId sym, langcc::ParserAttrMask attr, langcc::ParserLookahead first_k);
}

namespace lang::cc::Node::Expr::Bin3::op::GT {
    struct _T: lang::cc::Node::Expr::Bin3::op::_T {
        void write(langcc::Ref<std::ostream> os, langcc::FmtFlags flags);
        void write(langcc::Ref<langcc::PrBufStream_T> pb);
        _T();
        lang::cc::Node::Expr::Bin3::op::GT_T with_id(langcc::Int id);
        lang::cc::Node::Expr::Bin3::op::GT_T with_bounds(langcc::TokenBounds bounds);
        lang::cc::Node::Expr::Bin3::op::GT_T with_is_top(bool is_top);
        lang::cc::Node::Expr::Bin3::op::GT_T with_sym(langcc::ParserSymId sym);
        lang::cc::Node::Expr::Bin3::op::GT_T with_attr(langcc::ParserAttrMask attr);
        lang::cc::Node::Expr::Bin3::op::GT_T with_first_k(langcc::ParserLookahead first_k);
        void hash_ser_acc_lang_cc_Node_Expr_Bin3_op_GT(langcc::SerBuf& buf) const;
        virtual void hash_ser_acc(langcc::SerBuf& buf) const;
    };
}

namespace langcc {
    void pr_debug(ostream& os, FmtFlags flags, lang::cc::Node::Expr::Bin4::op::SHL_T x);
}

namespace lang::cc::Node::Expr::Bin4::op::SHL {
    lang::cc::Node::Expr::Bin4::op::SHL_T make(langcc::Int id, langcc::TokenBounds bounds, bool is_top, langcc::ParserSymId sym, langcc::ParserAttrMask attr, langcc::ParserLookahead first_k);
}

namespace lang::cc::Node::Expr::Bin4::op::SHL {
    lang::cc::Node::Expr::Bin4::op::SHL_T make_ext(langcc::ArenaPtr arena, langcc::Int id, langcc::TokenBounds bounds, bool is_top, langcc::ParserSymId sym, langcc::ParserAttrMask attr, langcc::ParserLookahead first_k);
}

namespace lang::cc::Node::Expr::Bin4::op::SHL {
    struct _T: lang::cc::Node::Expr::Bin4::op::_T {
        void write(langcc::Ref<std::ostream> os, langcc::FmtFlags flags);
        void write(langcc::Ref<langcc::PrBufStream_T> pb);
        _T();
        lang::cc::Node::Expr::Bin4::op::SHL_T with_id(langcc::Int id);
        lang::cc::Node::Expr::Bin4::op::SHL_T with_bounds(langcc::TokenBounds bounds);
        lang::cc::Node::Expr::Bin4::op::SHL_T with_is_top(bool is_top);
        lang::cc::Node::Expr::Bin4::op::SHL_T with_sym(langcc::ParserSymId sym);
        lang::cc::Node::Expr::Bin4::op::SHL_T with_attr(langcc::ParserAttrMask attr);
        lang::cc::Node::Expr::Bin4::op::SHL_T with_first_k(langcc::ParserLookahead first_k);
        void hash_ser_acc_lang_cc_Node_Expr_Bin4_op_SHL(langcc::SerBuf& buf) const;
        virtual void hash_ser_acc(langcc::SerBuf& buf) const;
    };
}

namespace langcc {
    void pr_debug(ostream& os, FmtFlags flags, lang::cc::Node::Expr::Bin5::op::PLUS_T x);
}

namespace lang::cc::Node::Expr::Bin5::op::PLUS {
    lang::cc::Node::Expr::Bin5::op::PLUS_T make(langcc::Int id, langcc::TokenBounds bounds, bool is_top, langcc::ParserSymId sym, langcc::ParserAttrMask attr, langcc::ParserLookahead first_k);
}

namespace lang::cc::Node::Expr::Bin5::op::PLUS {
    lang::cc::Node::Expr::Bin5::op::PLUS_T make_ext(langcc::ArenaPtr arena, langcc::Int id, langcc::TokenBounds bounds, bool is_top, langcc::ParserSymId sym, langcc::ParserAttrMask attr, langcc::ParserLookahead first_k);
}

namespace lang::cc::Node::Expr::Bin5::op::PLUS {
    struct _T: lang::cc::Node::Expr::Bin5::op::_T {
        void write(langcc::Ref<std::ostream> os, langcc::FmtFlags flags);
        void write(langcc::Ref<langcc::PrBufStream_T> pb);
        _T();
        lang::cc::Node::Expr::Bin5::op::PLUS_T with_id(langcc::Int id);
        lang::cc::Node::Expr::Bin5::op::PLUS_T with_bounds(langcc::TokenBounds bounds);
        lang::cc::Node::Expr::Bin5::op::PLUS_T with_is_top(bool is_top);
        lang::cc::Node::Expr::Bin5::op::PLUS_T with_sym(langcc::ParserSymId sym);
        lang::cc::Node::Expr::Bin5::op::PLUS_T with_attr(langcc::ParserAttrMask attr);
        lang::cc::Node::Expr::Bin5::op::PLUS_T with_first_k(langcc::ParserLookahead first_k);
        void hash_ser_acc_lang_cc_Node_Expr_Bin5_op_PLUS(langcc::SerBuf& buf) const;
        virtual void hash_ser_acc(langcc::SerBuf& buf) const;
    };
}

namespace langcc {
    void pr_debug(ostream& os, FmtFlags flags, lang::cc::Node::Expr::Bin5::op::MINUS_T x);
}

namespace lang::cc::Node::Expr::Bin5::op::MINUS {
    lang::cc::Node::Expr::Bin5::op::MINUS_T make(langcc::Int id, langcc::TokenBounds bounds, bool is_top, langcc::ParserSymId sym, langcc::ParserAttrMask attr, langcc::ParserLookahead first_k);
}

namespace lang::cc::Node::Expr::Bin5::op::MINUS {
    lang::cc::Node::Expr::Bin5::op::MINUS_T make_ext(langcc::ArenaPtr arena, langcc::Int id, langcc::TokenBounds bounds, bool is_top, langcc::ParserSymId sym, langcc::ParserAttrMask attr, langcc::ParserLookahead first_k);
}

namespace lang::cc::Node::Expr::Bin5::op::MINUS {
    struct _T: lang::cc::Node::Expr::Bin5::op::_T {
        void write(langcc::Ref<std::ostream> os, langcc::FmtFlags flags);
        void write(langcc::Ref<langcc::PrBufStream_T> pb);
        _T();
        lang::cc::Node::Expr::Bin5::op::MINUS_T with_id(langcc::Int id);
        lang::cc::Node::Expr::Bin5::op::MINUS_T with_bounds(langcc::TokenBounds bounds);
        lang::cc::Node::Expr::Bin5::op::MINUS_T with_is_top(bool is_top);
        lang::cc::Node::Expr::Bin5::op::MINUS_T with_sym(langcc::ParserSymId sym);
        lang::cc::Node::Expr::Bin5::op::MINUS_T with_attr(langcc::ParserAttrMask attr);
        lang::cc::Node::Expr::Bin5::op::MINUS_T with_first_k(langcc::ParserLookahead first_k);
        void hash_ser_acc_lang_cc_Node_Expr_Bin5_op_MINUS(langcc::SerBuf& buf) const;
        virtual void hash_ser_acc(langcc::SerBuf& buf) const;
    };
}

namespace langcc {
    void pr_debug(ostream& os, FmtFlags flags, lang::cc::Node::Expr::Bin6::op::TIMES_T x);
}

namespace lang::cc::Node::Expr::Bin6::op::TIMES {
    lang::cc::Node::Expr::Bin6::op::TIMES_T make(langcc::Int id, langcc::TokenBounds bounds, bool is_top, langcc::ParserSymId sym, langcc::ParserAttrMask attr, langcc::ParserLookahead first_k);
}

namespace lang::cc::Node::Expr::Bin6::op::TIMES {
    lang::cc::Node::Expr::Bin6::op::TIMES_T make_ext(langcc::ArenaPtr arena, langcc::Int id, langcc::TokenBounds bounds, bool is_top, langcc::ParserSymId sym, langcc::ParserAttrMask attr, langcc::ParserLookahead first_k);
}

namespace lang::cc::Node::Expr::Bin6::op::TIMES {
    struct _T: lang::cc::Node::Expr::Bin6::op::_T {
        void write(langcc::Ref<std::ostream> os, langcc::FmtFlags flags);
        void write(langcc::Ref<langcc::PrBufStream_T> pb);
        _T();
        lang::cc::Node::Expr::Bin6::op::TIMES_T with_id(langcc::Int id);
        lang::cc::Node::Expr::Bin6::op::TIMES_T with_bounds(langcc::TokenBounds bounds);
        lang::cc::Node::Expr::Bin6::op::TIMES_T with_is_top(bool is_top);
        lang::cc::Node::Expr::Bin6::op::TIMES_T with_sym(langcc::ParserSymId sym);
        lang::cc::Node::Expr::Bin6::op::TIMES_T with_attr(langcc::ParserAttrMask attr);
        lang::cc::Node::Expr::Bin6::op::TIMES_T with_first_k(langcc::ParserLookahead first_k);
        void hash_ser_acc_lang_cc_Node_Expr_Bin6_op_TIMES(langcc::SerBuf& buf) const;
        virtual void hash_ser_acc(langcc::SerBuf& buf) const;
    };
}

namespace langcc {
    void pr_debug(ostream& os, FmtFlags flags, lang::cc::Node::Expr::Bin6::op::DIVIDE_T x);
}

namespace lang::cc::Node::Expr::Bin6::op::DIVIDE {
    lang::cc::Node::Expr::Bin6::op::DIVIDE_T make(langcc::Int id, langcc::TokenBounds bounds, bool is_top, langcc::ParserSymId sym, langcc::ParserAttrMask attr, langcc::ParserLookahead first_k);
}

namespace lang::cc::Node::Expr::Bin6::op::DIVIDE {
    lang::cc::Node::Expr::Bin6::op::DIVIDE_T make_ext(langcc::ArenaPtr arena, langcc::Int id, langcc::TokenBounds bounds, bool is_top, langcc::ParserSymId sym, langcc::ParserAttrMask attr, langcc::ParserLookahead first_k);
}

namespace lang::cc::Node::Expr::Bin6::op::DIVIDE {
    struct _T: lang::cc::Node::Expr::Bin6::op::_T {
        void write(langcc::Ref<std::ostream> os, langcc::FmtFlags flags);
        void write(langcc::Ref<langcc::PrBufStream_T> pb);
        _T();
        lang::cc::Node::Expr::Bin6::op::DIVIDE_T with_id(langcc::Int id);
        lang::cc::Node::Expr::Bin6::op::DIVIDE_T with_bounds(langcc::TokenBounds bounds);
        lang::cc::Node::Expr::Bin6::op::DIVIDE_T with_is_top(bool is_top);
        lang::cc::Node::Expr::Bin6::op::DIVIDE_T with_sym(langcc::ParserSymId sym);
        lang::cc::Node::Expr::Bin6::op::DIVIDE_T with_attr(langcc::ParserAttrMask attr);
        lang::cc::Node::Expr::Bin6::op::DIVIDE_T with_first_k(langcc::ParserLookahead first_k);
        void hash_ser_acc_lang_cc_Node_Expr_Bin6_op_DIVIDE(langcc::SerBuf& buf) const;
        virtual void hash_ser_acc(langcc::SerBuf& buf) const;
    };
}

namespace langcc {
    void pr_debug(ostream& os, FmtFlags flags, lang::cc::Node::Expr::Bin6::op::MODULO_T x);
}

namespace lang::cc::Node::Expr::Bin6::op::MODULO {
    lang::cc::Node::Expr::Bin6::op::MODULO_T make(langcc::Int id, langcc::TokenBounds bounds, bool is_top, langcc::ParserSymId sym, langcc::ParserAttrMask attr, langcc::ParserLookahead first_k);
}

namespace lang::cc::Node::Expr::Bin6::op::MODULO {
    lang::cc::Node::Expr::Bin6::op::MODULO_T make_ext(langcc::ArenaPtr arena, langcc::Int id, langcc::TokenBounds bounds, bool is_top, langcc::ParserSymId sym, langcc::ParserAttrMask attr, langcc::ParserLookahead first_k);
}

namespace lang::cc::Node::Expr::Bin6::op::MODULO {
    struct _T: lang::cc::Node::Expr::Bin6::op::_T {
        void write(langcc::Ref<std::ostream> os, langcc::FmtFlags flags);
        void write(langcc::Ref<langcc::PrBufStream_T> pb);
        _T();
        lang::cc::Node::Expr::Bin6::op::MODULO_T with_id(langcc::Int id);
        lang::cc::Node::Expr::Bin6::op::MODULO_T with_bounds(langcc::TokenBounds bounds);
        lang::cc::Node::Expr::Bin6::op::MODULO_T with_is_top(bool is_top);
        lang::cc::Node::Expr::Bin6::op::MODULO_T with_sym(langcc::ParserSymId sym);
        lang::cc::Node::Expr::Bin6::op::MODULO_T with_attr(langcc::ParserAttrMask attr);
        lang::cc::Node::Expr::Bin6::op::MODULO_T with_first_k(langcc::ParserLookahead first_k);
        void hash_ser_acc_lang_cc_Node_Expr_Bin6_op_MODULO(langcc::SerBuf& buf) const;
        virtual void hash_ser_acc(langcc::SerBuf& buf) const;
    };
}

namespace langcc {
    void pr_debug(ostream& os, FmtFlags flags, lang::cc::Node::Decl::Struct::tmpl::item::args::item_T x);
}

namespace lang::cc::Node::Decl::Struct::tmpl::item::args::item {
    lang::cc::Node::Decl::Struct::tmpl::item::args::item_T make(langcc::Int id, langcc::TokenBounds bounds, bool is_top, langcc::ParserSymId sym, langcc::ParserAttrMask attr, langcc::ParserLookahead first_k, bool dots, lang::cc::Node::Expr_T name);
}

namespace lang::cc::Node::Decl::Struct::tmpl::item::args::item {
    lang::cc::Node::Decl::Struct::tmpl::item::args::item_T make_ext(langcc::ArenaPtr arena, langcc::Int id, langcc::TokenBounds bounds, bool is_top, langcc::ParserSymId sym, langcc::ParserAttrMask attr, langcc::ParserLookahead first_k, bool dots, lang::cc::Node::Expr_T name);
}

namespace lang::cc::Node::Decl::Struct::tmpl::item::args::item {
    struct _T: lang::cc::Node::_T {
        void write(langcc::Ref<std::ostream> os, langcc::FmtFlags flags);
        void write(langcc::Ref<langcc::PrBufStream_T> pb);
        bool dots_;
        lang::cc::Node::Expr_T name_;
        _T();
        lang::cc::Node::Decl::Struct::tmpl::item::args::item_T with_id(langcc::Int id);
        lang::cc::Node::Decl::Struct::tmpl::item::args::item_T with_bounds(langcc::TokenBounds bounds);
        lang::cc::Node::Decl::Struct::tmpl::item::args::item_T with_is_top(bool is_top);
        lang::cc::Node::Decl::Struct::tmpl::item::args::item_T with_sym(langcc::ParserSymId sym);
        lang::cc::Node::Decl::Struct::tmpl::item::args::item_T with_attr(langcc::ParserAttrMask attr);
        lang::cc::Node::Decl::Struct::tmpl::item::args::item_T with_first_k(langcc::ParserLookahead first_k);
        lang::cc::Node::Decl::Struct::tmpl::item::args::item_T with_dots(bool dots);
        lang::cc::Node::Decl::Struct::tmpl::item::args::item_T with_name(lang::cc::Node::Expr_T name);
        void hash_ser_acc_lang_cc_Node_Decl_Struct_tmpl_item_args_item(langcc::SerBuf& buf) const;
        virtual void hash_ser_acc(langcc::SerBuf& buf) const;
    };
}

namespace langcc {
    void pr_debug(ostream& os, FmtFlags flags, lang::cc::Node::Entry::Fun::tmpl::item::args::item_T x);
}

namespace lang::cc::Node::Entry::Fun::tmpl::item::args::item {
    lang::cc::Node::Entry::Fun::tmpl::item::args::item_T make(langcc::Int id, langcc::TokenBounds bounds, bool is_top, langcc::ParserSymId sym, langcc::ParserAttrMask attr, langcc::ParserLookahead first_k, bool dots, lang::cc::Node::Expr_T name);
}

namespace lang::cc::Node::Entry::Fun::tmpl::item::args::item {
    lang::cc::Node::Entry::Fun::tmpl::item::args::item_T make_ext(langcc::ArenaPtr arena, langcc::Int id, langcc::TokenBounds bounds, bool is_top, langcc::ParserSymId sym, langcc::ParserAttrMask attr, langcc::ParserLookahead first_k, bool dots, lang::cc::Node::Expr_T name);
}

namespace lang::cc::Node::Entry::Fun::tmpl::item::args::item {
    struct _T: lang::cc::Node::_T {
        void write(langcc::Ref<std::ostream> os, langcc::FmtFlags flags);
        void write(langcc::Ref<langcc::PrBufStream_T> pb);
        bool dots_;
        lang::cc::Node::Expr_T name_;
        _T();
        lang::cc::Node::Entry::Fun::tmpl::item::args::item_T with_id(langcc::Int id);
        lang::cc::Node::Entry::Fun::tmpl::item::args::item_T with_bounds(langcc::TokenBounds bounds);
        lang::cc::Node::Entry::Fun::tmpl::item::args::item_T with_is_top(bool is_top);
        lang::cc::Node::Entry::Fun::tmpl::item::args::item_T with_sym(langcc::ParserSymId sym);
        lang::cc::Node::Entry::Fun::tmpl::item::args::item_T with_attr(langcc::ParserAttrMask attr);
        lang::cc::Node::Entry::Fun::tmpl::item::args::item_T with_first_k(langcc::ParserLookahead first_k);
        lang::cc::Node::Entry::Fun::tmpl::item::args::item_T with_dots(bool dots);
        lang::cc::Node::Entry::Fun::tmpl::item::args::item_T with_name(lang::cc::Node::Expr_T name);
        void hash_ser_acc_lang_cc_Node_Entry_Fun_tmpl_item_args_item(langcc::SerBuf& buf) const;
        virtual void hash_ser_acc(langcc::SerBuf& buf) const;
    };
}

namespace langcc {
    void pr_debug(ostream& os, FmtFlags flags, lang::cc::Node::Decl::Fun::tmpl::item::args::item_T x);
}

namespace lang::cc::Node::Decl::Fun::tmpl::item::args::item {
    lang::cc::Node::Decl::Fun::tmpl::item::args::item_T make(langcc::Int id, langcc::TokenBounds bounds, bool is_top, langcc::ParserSymId sym, langcc::ParserAttrMask attr, langcc::ParserLookahead first_k, bool dots, lang::cc::Node::Expr_T name);
}

namespace lang::cc::Node::Decl::Fun::tmpl::item::args::item {
    lang::cc::Node::Decl::Fun::tmpl::item::args::item_T make_ext(langcc::ArenaPtr arena, langcc::Int id, langcc::TokenBounds bounds, bool is_top, langcc::ParserSymId sym, langcc::ParserAttrMask attr, langcc::ParserLookahead first_k, bool dots, lang::cc::Node::Expr_T name);
}

namespace lang::cc::Node::Decl::Fun::tmpl::item::args::item {
    struct _T: lang::cc::Node::_T {
        void write(langcc::Ref<std::ostream> os, langcc::FmtFlags flags);
        void write(langcc::Ref<langcc::PrBufStream_T> pb);
        bool dots_;
        lang::cc::Node::Expr_T name_;
        _T();
        lang::cc::Node::Decl::Fun::tmpl::item::args::item_T with_id(langcc::Int id);
        lang::cc::Node::Decl::Fun::tmpl::item::args::item_T with_bounds(langcc::TokenBounds bounds);
        lang::cc::Node::Decl::Fun::tmpl::item::args::item_T with_is_top(bool is_top);
        lang::cc::Node::Decl::Fun::tmpl::item::args::item_T with_sym(langcc::ParserSymId sym);
        lang::cc::Node::Decl::Fun::tmpl::item::args::item_T with_attr(langcc::ParserAttrMask attr);
        lang::cc::Node::Decl::Fun::tmpl::item::args::item_T with_first_k(langcc::ParserLookahead first_k);
        lang::cc::Node::Decl::Fun::tmpl::item::args::item_T with_dots(bool dots);
        lang::cc::Node::Decl::Fun::tmpl::item::args::item_T with_name(lang::cc::Node::Expr_T name);
        void hash_ser_acc_lang_cc_Node_Decl_Fun_tmpl_item_args_item(langcc::SerBuf& buf) const;
        virtual void hash_ser_acc(langcc::SerBuf& buf) const;
    };
}

namespace langcc {
    void pr_debug(ostream& os, FmtFlags flags, lang::cc::Node::Decl::UsingAlias::tmpl::item::args::item_T x);
}

namespace lang::cc::Node::Decl::UsingAlias::tmpl::item::args::item {
    lang::cc::Node::Decl::UsingAlias::tmpl::item::args::item_T make(langcc::Int id, langcc::TokenBounds bounds, bool is_top, langcc::ParserSymId sym, langcc::ParserAttrMask attr, langcc::ParserLookahead first_k, bool dots, lang::cc::Node::Expr_T name);
}

namespace lang::cc::Node::Decl::UsingAlias::tmpl::item::args::item {
    lang::cc::Node::Decl::UsingAlias::tmpl::item::args::item_T make_ext(langcc::ArenaPtr arena, langcc::Int id, langcc::TokenBounds bounds, bool is_top, langcc::ParserSymId sym, langcc::ParserAttrMask attr, langcc::ParserLookahead first_k, bool dots, lang::cc::Node::Expr_T name);
}

namespace lang::cc::Node::Decl::UsingAlias::tmpl::item::args::item {
    struct _T: lang::cc::Node::_T {
        void write(langcc::Ref<std::ostream> os, langcc::FmtFlags flags);
        void write(langcc::Ref<langcc::PrBufStream_T> pb);
        bool dots_;
        lang::cc::Node::Expr_T name_;
        _T();
        lang::cc::Node::Decl::UsingAlias::tmpl::item::args::item_T with_id(langcc::Int id);
        lang::cc::Node::Decl::UsingAlias::tmpl::item::args::item_T with_bounds(langcc::TokenBounds bounds);
        lang::cc::Node::Decl::UsingAlias::tmpl::item::args::item_T with_is_top(bool is_top);
        lang::cc::Node::Decl::UsingAlias::tmpl::item::args::item_T with_sym(langcc::ParserSymId sym);
        lang::cc::Node::Decl::UsingAlias::tmpl::item::args::item_T with_attr(langcc::ParserAttrMask attr);
        lang::cc::Node::Decl::UsingAlias::tmpl::item::args::item_T with_first_k(langcc::ParserLookahead first_k);
        lang::cc::Node::Decl::UsingAlias::tmpl::item::args::item_T with_dots(bool dots);
        lang::cc::Node::Decl::UsingAlias::tmpl::item::args::item_T with_name(lang::cc::Node::Expr_T name);
        void hash_ser_acc_lang_cc_Node_Decl_UsingAlias_tmpl_item_args_item(langcc::SerBuf& buf) const;
        virtual void hash_ser_acc(langcc::SerBuf& buf) const;
    };
}

void visit_lang_cc_Node(lang::cc::Node::Expr::Paren_T x, std::function<void(lang::cc::Node_T)> f);

void visit_lang_cc_Node(lang::cc::Node::Expr::Call_T x, std::function<void(lang::cc::Node_T)> f);

void visit_lang_cc_Node(lang::cc::Node::Expr::Index_T x, std::function<void(lang::cc::Node_T)> f);

void visit_lang_cc_Node(lang::cc::Node::Expr::IndexEmpty_T x, std::function<void(lang::cc::Node_T)> f);

void visit_lang_cc_Node(lang::cc::Node::Expr::Dot_T x, std::function<void(lang::cc::Node_T)> f);

void visit_lang_cc_Node(lang::cc::Node::Expr::Arrow_T x, std::function<void(lang::cc::Node_T)> f);

void visit_lang_cc_Node(lang::cc::Node::Expr::Ref__T x, std::function<void(lang::cc::Node_T)> f);

void visit_lang_cc_Node(lang::cc::Node::Expr::AddrOf_T x, std::function<void(lang::cc::Node_T)> f);

void visit_lang_cc_Node(lang::cc::Node::Expr::Deref_T x, std::function<void(lang::cc::Node_T)> f);

void visit_lang_cc_Node(lang::cc::Node::Expr::UnaryPre::op::NOT_T x, std::function<void(lang::cc::Node_T)> f);

void visit_lang_cc_Node(lang::cc::Node::Expr::UnaryPre::op::NEG_T x, std::function<void(lang::cc::Node_T)> f);

void visit_lang_cc_Node(lang::cc::Node::Expr::UnaryPre::op_T x, std::function<void(lang::cc::Node_T)> f);

void visit_lang_cc_Node(lang::cc::Node::Expr::UnaryPre_T x, std::function<void(lang::cc::Node_T)> f);

void visit_lang_cc_Node(lang::cc::Node::Expr::IncDecPre::op::INC_T x, std::function<void(lang::cc::Node_T)> f);

void visit_lang_cc_Node(lang::cc::Node::Expr::IncDecPre::op::DEC_T x, std::function<void(lang::cc::Node_T)> f);

void visit_lang_cc_Node(lang::cc::Node::Expr::IncDecPre::op_T x, std::function<void(lang::cc::Node_T)> f);

void visit_lang_cc_Node(lang::cc::Node::Expr::IncDecPre_T x, std::function<void(lang::cc::Node_T)> f);

void visit_lang_cc_Node(lang::cc::Node::Expr::IncDecPost::op::INC_T x, std::function<void(lang::cc::Node_T)> f);

void visit_lang_cc_Node(lang::cc::Node::Expr::IncDecPost::op::DEC_T x, std::function<void(lang::cc::Node_T)> f);

void visit_lang_cc_Node(lang::cc::Node::Expr::IncDecPost::op_T x, std::function<void(lang::cc::Node_T)> f);

void visit_lang_cc_Node(lang::cc::Node::Expr::IncDecPost_T x, std::function<void(lang::cc::Node_T)> f);

void visit_lang_cc_Node(lang::cc::Node::Expr::Assign_T x, std::function<void(lang::cc::Node_T)> f);

void visit_lang_cc_Node(lang::cc::Node::Expr::Bin1::op::LOR_T x, std::function<void(lang::cc::Node_T)> f);

void visit_lang_cc_Node(lang::cc::Node::Expr::Bin1::op_T x, std::function<void(lang::cc::Node_T)> f);

void visit_lang_cc_Node(lang::cc::Node::Expr::Bin1_T x, std::function<void(lang::cc::Node_T)> f);

void visit_lang_cc_Node(lang::cc::Node::Expr::Bin2::op::LAND_T x, std::function<void(lang::cc::Node_T)> f);

void visit_lang_cc_Node(lang::cc::Node::Expr::Bin2::op_T x, std::function<void(lang::cc::Node_T)> f);

void visit_lang_cc_Node(lang::cc::Node::Expr::Bin2_T x, std::function<void(lang::cc::Node_T)> f);

void visit_lang_cc_Node(lang::cc::Node::Expr::Bin3::op::EQ_T x, std::function<void(lang::cc::Node_T)> f);

void visit_lang_cc_Node(lang::cc::Node::Expr::Bin3::op::NE_T x, std::function<void(lang::cc::Node_T)> f);

void visit_lang_cc_Node(lang::cc::Node::Expr::Bin3::op::LE_T x, std::function<void(lang::cc::Node_T)> f);

void visit_lang_cc_Node(lang::cc::Node::Expr::Bin3::op::GE_T x, std::function<void(lang::cc::Node_T)> f);

void visit_lang_cc_Node(lang::cc::Node::Expr::Bin3::op::LT_T x, std::function<void(lang::cc::Node_T)> f);

void visit_lang_cc_Node(lang::cc::Node::Expr::Bin3::op::GT_T x, std::function<void(lang::cc::Node_T)> f);

void visit_lang_cc_Node(lang::cc::Node::Expr::Bin3::op_T x, std::function<void(lang::cc::Node_T)> f);

void visit_lang_cc_Node(lang::cc::Node::Expr::Bin3_T x, std::function<void(lang::cc::Node_T)> f);

void visit_lang_cc_Node(lang::cc::Node::Expr::Bin4::op::SHL_T x, std::function<void(lang::cc::Node_T)> f);

void visit_lang_cc_Node(lang::cc::Node::Expr::Bin4::op_T x, std::function<void(lang::cc::Node_T)> f);

void visit_lang_cc_Node(lang::cc::Node::Expr::Bin4_T x, std::function<void(lang::cc::Node_T)> f);

void visit_lang_cc_Node(lang::cc::Node::Expr::Bin5::op::PLUS_T x, std::function<void(lang::cc::Node_T)> f);

void visit_lang_cc_Node(lang::cc::Node::Expr::Bin5::op::MINUS_T x, std::function<void(lang::cc::Node_T)> f);

void visit_lang_cc_Node(lang::cc::Node::Expr::Bin5::op_T x, std::function<void(lang::cc::Node_T)> f);

void visit_lang_cc_Node(lang::cc::Node::Expr::Bin5_T x, std::function<void(lang::cc::Node_T)> f);

void visit_lang_cc_Node(lang::cc::Node::Expr::Bin6::op::TIMES_T x, std::function<void(lang::cc::Node_T)> f);

void visit_lang_cc_Node(lang::cc::Node::Expr::Bin6::op::DIVIDE_T x, std::function<void(lang::cc::Node_T)> f);

void visit_lang_cc_Node(lang::cc::Node::Expr::Bin6::op::MODULO_T x, std::function<void(lang::cc::Node_T)> f);

void visit_lang_cc_Node(lang::cc::Node::Expr::Bin6::op_T x, std::function<void(lang::cc::Node_T)> f);

void visit_lang_cc_Node(lang::cc::Node::Expr::Bin6_T x, std::function<void(lang::cc::Node_T)> f);

void visit_lang_cc_Node(lang::cc::Node::Expr::Template_T x, std::function<void(lang::cc::Node_T)> f);

void visit_lang_cc_Node(lang::cc::Node::Expr::New_T x, std::function<void(lang::cc::Node_T)> f);

void visit_lang_cc_Node(lang::cc::Node::Expr::Delete_T x, std::function<void(lang::cc::Node_T)> f);

void visit_lang_cc_Node(lang::cc::Node::Expr::Ellipsis_T x, std::function<void(lang::cc::Node_T)> f);

void visit_lang_cc_Node(lang::cc::Node::Expr::Tilde_T x, std::function<void(lang::cc::Node_T)> f);

void visit_lang_cc_Node(lang::cc::Node::Expr::Namespace_T x, std::function<void(lang::cc::Node_T)> f);

void visit_lang_cc_Node(lang::cc::Node::Expr::Id_T x, std::function<void(lang::cc::Node_T)> f);

void visit_lang_cc_Node(lang::cc::Node::Expr::Lit::Integer_T x, std::function<void(lang::cc::Node_T)> f);

void visit_lang_cc_Node(lang::cc::Node::Expr::Lit::Str__T x, std::function<void(lang::cc::Node_T)> f);

void visit_lang_cc_Node(lang::cc::Node::Expr::Lit::Array_T x, std::function<void(lang::cc::Node_T)> f);

void visit_lang_cc_Node(lang::cc::Node::Expr::Lit_T x, std::function<void(lang::cc::Node_T)> f);

void visit_lang_cc_Node(lang::cc::Node::Expr_T x, std::function<void(lang::cc::Node_T)> f);

void visit_lang_cc_Node(lang::cc::Node::Decl::Struct::tmpl::item::args::item_T x, std::function<void(lang::cc::Node_T)> f);

void visit_lang_cc_Node(lang::cc::Node::Decl::Struct::tmpl::item_T x, std::function<void(lang::cc::Node_T)> f);

void visit_lang_cc_Node(lang::cc::Node::StructDeclDef::Decl_T x, std::function<void(lang::cc::Node_T)> f);

void visit_lang_cc_Node(lang::cc::Node::Entry::Field_T x, std::function<void(lang::cc::Node_T)> f);

void visit_lang_cc_Node(lang::cc::Node::Entry::Fun::tmpl::item::args::item_T x, std::function<void(lang::cc::Node_T)> f);

void visit_lang_cc_Node(lang::cc::Node::Entry::Fun::tmpl::item_T x, std::function<void(lang::cc::Node_T)> f);

void visit_lang_cc_Node(lang::cc::Node::Mod::Const_T x, std::function<void(lang::cc::Node_T)> f);

void visit_lang_cc_Node(lang::cc::Node::Mod::Inline_T x, std::function<void(lang::cc::Node_T)> f);

void visit_lang_cc_Node(lang::cc::Node::Mod::Static_T x, std::function<void(lang::cc::Node_T)> f);

void visit_lang_cc_Node(lang::cc::Node::Mod::Virtual_T x, std::function<void(lang::cc::Node_T)> f);

void visit_lang_cc_Node(lang::cc::Node::Mod::NoInline_T x, std::function<void(lang::cc::Node_T)> f);

void visit_lang_cc_Node(lang::cc::Node::Mod::AlwaysInline_T x, std::function<void(lang::cc::Node_T)> f);

void visit_lang_cc_Node(lang::cc::Node::Attribute::Simple_T x, std::function<void(lang::cc::Node_T)> f);

void visit_lang_cc_Node(lang::cc::Node::Attribute::Namespaced_T x, std::function<void(lang::cc::Node_T)> f);

void visit_lang_cc_Node(lang::cc::Node::Attribute_T x, std::function<void(lang::cc::Node_T)> f);

void visit_lang_cc_Node(lang::cc::Node::Mod::Attribute_T x, std::function<void(lang::cc::Node_T)> f);

void visit_lang_cc_Node(lang::cc::Node::Mod_T x, std::function<void(lang::cc::Node_T)> f);

void visit_lang_cc_Node(lang::cc::Node::Param::val_T x, std::function<void(lang::cc::Node_T)> f);

void visit_lang_cc_Node(lang::cc::Node::Param_T x, std::function<void(lang::cc::Node_T)> f);

void visit_lang_cc_Node(lang::cc::Node::FunDeclDef::Decl_T x, std::function<void(lang::cc::Node_T)> f);

void visit_lang_cc_Node(lang::cc::Node::TypedDecl::vars::item::val_T x, std::function<void(lang::cc::Node_T)> f);

void visit_lang_cc_Node(lang::cc::Node::TypedDecl::vars::item_T x, std::function<void(lang::cc::Node_T)> f);

void visit_lang_cc_Node(lang::cc::Node::TypedDecl_T x, std::function<void(lang::cc::Node_T)> f);

void visit_lang_cc_Node(lang::cc::Node::Stmt::Decl_T x, std::function<void(lang::cc::Node_T)> f);

void visit_lang_cc_Node(lang::cc::Node::Stmt::Expr_T x, std::function<void(lang::cc::Node_T)> f);

void visit_lang_cc_Node(lang::cc::Node::Stmt::Block_T x, std::function<void(lang::cc::Node_T)> f);

void visit_lang_cc_Node(lang::cc::Node::Stmt::If_T x, std::function<void(lang::cc::Node_T)> f);

void visit_lang_cc_Node(lang::cc::Node::Stmt::IfElse_T x, std::function<void(lang::cc::Node_T)> f);

void visit_lang_cc_Node(lang::cc::Node::ExprExt::Expr_T x, std::function<void(lang::cc::Node_T)> f);

void visit_lang_cc_Node(lang::cc::Node::ExprExt::Decl_T x, std::function<void(lang::cc::Node_T)> f);

void visit_lang_cc_Node(lang::cc::Node::ExprExt_T x, std::function<void(lang::cc::Node_T)> f);

void visit_lang_cc_Node(lang::cc::Node::Stmt::For_T x, std::function<void(lang::cc::Node_T)> f);

void visit_lang_cc_Node(lang::cc::Node::SwitchCase::Case_T x, std::function<void(lang::cc::Node_T)> f);

void visit_lang_cc_Node(lang::cc::Node::SwitchCase::Default_T x, std::function<void(lang::cc::Node_T)> f);

void visit_lang_cc_Node(lang::cc::Node::SwitchCase_T x, std::function<void(lang::cc::Node_T)> f);

void visit_lang_cc_Node(lang::cc::Node::Stmt::Switch_T x, std::function<void(lang::cc::Node_T)> f);

void visit_lang_cc_Node(lang::cc::Node::Stmt::Break_T x, std::function<void(lang::cc::Node_T)> f);

void visit_lang_cc_Node(lang::cc::Node::Stmt::Continue_T x, std::function<void(lang::cc::Node_T)> f);

void visit_lang_cc_Node(lang::cc::Node::Stmt::Return_T x, std::function<void(lang::cc::Node_T)> f);

void visit_lang_cc_Node(lang::cc::Node::Stmt_T x, std::function<void(lang::cc::Node_T)> f);

void visit_lang_cc_Node(lang::cc::Node::Block_T x, std::function<void(lang::cc::Node_T)> f);

void visit_lang_cc_Node(lang::cc::Node::FunDeclDef::Def_T x, std::function<void(lang::cc::Node_T)> f);

void visit_lang_cc_Node(lang::cc::Node::FunDeclDef::Del_T x, std::function<void(lang::cc::Node_T)> f);

void visit_lang_cc_Node(lang::cc::Node::FunDeclDef::Zero_T x, std::function<void(lang::cc::Node_T)> f);

void visit_lang_cc_Node(lang::cc::Node::FunDeclDef_T x, std::function<void(lang::cc::Node_T)> f);

void visit_lang_cc_Node(lang::cc::Node::Entry::Fun_T x, std::function<void(lang::cc::Node_T)> f);

void visit_lang_cc_Node(lang::cc::Node::Entry_T x, std::function<void(lang::cc::Node_T)> f);

void visit_lang_cc_Node(lang::cc::Node::StructDeclDef::Def_T x, std::function<void(lang::cc::Node_T)> f);

void visit_lang_cc_Node(lang::cc::Node::StructDeclDef_T x, std::function<void(lang::cc::Node_T)> f);

void visit_lang_cc_Node(lang::cc::Node::Decl::Struct_T x, std::function<void(lang::cc::Node_T)> f);

void visit_lang_cc_Node(lang::cc::Node::Decl::EnumStruct_T x, std::function<void(lang::cc::Node_T)> f);

void visit_lang_cc_Node(lang::cc::Node::Decl::Fun::tmpl::item::args::item_T x, std::function<void(lang::cc::Node_T)> f);

void visit_lang_cc_Node(lang::cc::Node::Decl::Fun::tmpl::item_T x, std::function<void(lang::cc::Node_T)> f);

void visit_lang_cc_Node(lang::cc::Node::Decl::Fun_T x, std::function<void(lang::cc::Node_T)> f);

void visit_lang_cc_Node(lang::cc::Node::Decl::Namespace_T x, std::function<void(lang::cc::Node_T)> f);

void visit_lang_cc_Node(lang::cc::Node::Decl::UsingAlias::tmpl::item::args::item_T x, std::function<void(lang::cc::Node_T)> f);

void visit_lang_cc_Node(lang::cc::Node::Decl::UsingAlias::tmpl::item_T x, std::function<void(lang::cc::Node_T)> f);

void visit_lang_cc_Node(lang::cc::Node::Decl::UsingAlias_T x, std::function<void(lang::cc::Node_T)> f);

void visit_lang_cc_Node(lang::cc::Node::Decl::UsingNamespace_T x, std::function<void(lang::cc::Node_T)> f);

void visit_lang_cc_Node(lang::cc::Node::Decl::Include_T x, std::function<void(lang::cc::Node_T)> f);

void visit_lang_cc_Node(lang::cc::Node::Decl::PragmaOnce_T x, std::function<void(lang::cc::Node_T)> f);

void visit_lang_cc_Node(lang::cc::Node::Decl_T x, std::function<void(lang::cc::Node_T)> f);

void visit_lang_cc_Node(lang::cc::Node::Module_T x, std::function<void(lang::cc::Node_T)> f);

void visit_lang_cc_Node(lang::cc::Node_T x, std::function<void(lang::cc::Node_T)> f);

lang::cc::Node_T xformT_lang_cc_Node(lang::cc::Node::Expr::Paren_T x, std::function<lang::cc::Node_T(lang::cc::Node_T)> f);

lang::cc::Node_T xformT_lang_cc_Node(lang::cc::Node::Expr::Call_T x, std::function<lang::cc::Node_T(lang::cc::Node_T)> f);

lang::cc::Node_T xformT_lang_cc_Node(lang::cc::Node::Expr::Index_T x, std::function<lang::cc::Node_T(lang::cc::Node_T)> f);

lang::cc::Node_T xformT_lang_cc_Node(lang::cc::Node::Expr::IndexEmpty_T x, std::function<lang::cc::Node_T(lang::cc::Node_T)> f);

lang::cc::Node_T xformT_lang_cc_Node(lang::cc::Node::Expr::Dot_T x, std::function<lang::cc::Node_T(lang::cc::Node_T)> f);

lang::cc::Node_T xformT_lang_cc_Node(lang::cc::Node::Expr::Arrow_T x, std::function<lang::cc::Node_T(lang::cc::Node_T)> f);

lang::cc::Node_T xformT_lang_cc_Node(lang::cc::Node::Expr::Ref__T x, std::function<lang::cc::Node_T(lang::cc::Node_T)> f);

lang::cc::Node_T xformT_lang_cc_Node(lang::cc::Node::Expr::AddrOf_T x, std::function<lang::cc::Node_T(lang::cc::Node_T)> f);

lang::cc::Node_T xformT_lang_cc_Node(lang::cc::Node::Expr::Deref_T x, std::function<lang::cc::Node_T(lang::cc::Node_T)> f);

lang::cc::Node_T xformT_lang_cc_Node(lang::cc::Node::Expr::UnaryPre::op::NOT_T x, std::function<lang::cc::Node_T(lang::cc::Node_T)> f);

lang::cc::Node_T xformT_lang_cc_Node(lang::cc::Node::Expr::UnaryPre::op::NEG_T x, std::function<lang::cc::Node_T(lang::cc::Node_T)> f);

lang::cc::Node_T xformT_lang_cc_Node(lang::cc::Node::Expr::UnaryPre::op_T x, std::function<lang::cc::Node_T(lang::cc::Node_T)> f);

lang::cc::Node_T xformT_lang_cc_Node(lang::cc::Node::Expr::UnaryPre_T x, std::function<lang::cc::Node_T(lang::cc::Node_T)> f);

lang::cc::Node_T xformT_lang_cc_Node(lang::cc::Node::Expr::IncDecPre::op::INC_T x, std::function<lang::cc::Node_T(lang::cc::Node_T)> f);

lang::cc::Node_T xformT_lang_cc_Node(lang::cc::Node::Expr::IncDecPre::op::DEC_T x, std::function<lang::cc::Node_T(lang::cc::Node_T)> f);

lang::cc::Node_T xformT_lang_cc_Node(lang::cc::Node::Expr::IncDecPre::op_T x, std::function<lang::cc::Node_T(lang::cc::Node_T)> f);

lang::cc::Node_T xformT_lang_cc_Node(lang::cc::Node::Expr::IncDecPre_T x, std::function<lang::cc::Node_T(lang::cc::Node_T)> f);

lang::cc::Node_T xformT_lang_cc_Node(lang::cc::Node::Expr::IncDecPost::op::INC_T x, std::function<lang::cc::Node_T(lang::cc::Node_T)> f);

lang::cc::Node_T xformT_lang_cc_Node(lang::cc::Node::Expr::IncDecPost::op::DEC_T x, std::function<lang::cc::Node_T(lang::cc::Node_T)> f);

lang::cc::Node_T xformT_lang_cc_Node(lang::cc::Node::Expr::IncDecPost::op_T x, std::function<lang::cc::Node_T(lang::cc::Node_T)> f);

lang::cc::Node_T xformT_lang_cc_Node(lang::cc::Node::Expr::IncDecPost_T x, std::function<lang::cc::Node_T(lang::cc::Node_T)> f);

lang::cc::Node_T xformT_lang_cc_Node(lang::cc::Node::Expr::Assign_T x, std::function<lang::cc::Node_T(lang::cc::Node_T)> f);

lang::cc::Node_T xformT_lang_cc_Node(lang::cc::Node::Expr::Bin1::op::LOR_T x, std::function<lang::cc::Node_T(lang::cc::Node_T)> f);

lang::cc::Node_T xformT_lang_cc_Node(lang::cc::Node::Expr::Bin1::op_T x, std::function<lang::cc::Node_T(lang::cc::Node_T)> f);

lang::cc::Node_T xformT_lang_cc_Node(lang::cc::Node::Expr::Bin1_T x, std::function<lang::cc::Node_T(lang::cc::Node_T)> f);

lang::cc::Node_T xformT_lang_cc_Node(lang::cc::Node::Expr::Bin2::op::LAND_T x, std::function<lang::cc::Node_T(lang::cc::Node_T)> f);

lang::cc::Node_T xformT_lang_cc_Node(lang::cc::Node::Expr::Bin2::op_T x, std::function<lang::cc::Node_T(lang::cc::Node_T)> f);

lang::cc::Node_T xformT_lang_cc_Node(lang::cc::Node::Expr::Bin2_T x, std::function<lang::cc::Node_T(lang::cc::Node_T)> f);

lang::cc::Node_T xformT_lang_cc_Node(lang::cc::Node::Expr::Bin3::op::EQ_T x, std::function<lang::cc::Node_T(lang::cc::Node_T)> f);

lang::cc::Node_T xformT_lang_cc_Node(lang::cc::Node::Expr::Bin3::op::NE_T x, std::function<lang::cc::Node_T(lang::cc::Node_T)> f);

lang::cc::Node_T xformT_lang_cc_Node(lang::cc::Node::Expr::Bin3::op::LE_T x, std::function<lang::cc::Node_T(lang::cc::Node_T)> f);

lang::cc::Node_T xformT_lang_cc_Node(lang::cc::Node::Expr::Bin3::op::GE_T x, std::function<lang::cc::Node_T(lang::cc::Node_T)> f);

lang::cc::Node_T xformT_lang_cc_Node(lang::cc::Node::Expr::Bin3::op::LT_T x, std::function<lang::cc::Node_T(lang::cc::Node_T)> f);

lang::cc::Node_T xformT_lang_cc_Node(lang::cc::Node::Expr::Bin3::op::GT_T x, std::function<lang::cc::Node_T(lang::cc::Node_T)> f);

lang::cc::Node_T xformT_lang_cc_Node(lang::cc::Node::Expr::Bin3::op_T x, std::function<lang::cc::Node_T(lang::cc::Node_T)> f);

lang::cc::Node_T xformT_lang_cc_Node(lang::cc::Node::Expr::Bin3_T x, std::function<lang::cc::Node_T(lang::cc::Node_T)> f);

lang::cc::Node_T xformT_lang_cc_Node(lang::cc::Node::Expr::Bin4::op::SHL_T x, std::function<lang::cc::Node_T(lang::cc::Node_T)> f);

lang::cc::Node_T xformT_lang_cc_Node(lang::cc::Node::Expr::Bin4::op_T x, std::function<lang::cc::Node_T(lang::cc::Node_T)> f);

lang::cc::Node_T xformT_lang_cc_Node(lang::cc::Node::Expr::Bin4_T x, std::function<lang::cc::Node_T(lang::cc::Node_T)> f);

lang::cc::Node_T xformT_lang_cc_Node(lang::cc::Node::Expr::Bin5::op::PLUS_T x, std::function<lang::cc::Node_T(lang::cc::Node_T)> f);

lang::cc::Node_T xformT_lang_cc_Node(lang::cc::Node::Expr::Bin5::op::MINUS_T x, std::function<lang::cc::Node_T(lang::cc::Node_T)> f);

lang::cc::Node_T xformT_lang_cc_Node(lang::cc::Node::Expr::Bin5::op_T x, std::function<lang::cc::Node_T(lang::cc::Node_T)> f);

lang::cc::Node_T xformT_lang_cc_Node(lang::cc::Node::Expr::Bin5_T x, std::function<lang::cc::Node_T(lang::cc::Node_T)> f);

lang::cc::Node_T xformT_lang_cc_Node(lang::cc::Node::Expr::Bin6::op::TIMES_T x, std::function<lang::cc::Node_T(lang::cc::Node_T)> f);

lang::cc::Node_T xformT_lang_cc_Node(lang::cc::Node::Expr::Bin6::op::DIVIDE_T x, std::function<lang::cc::Node_T(lang::cc::Node_T)> f);

lang::cc::Node_T xformT_lang_cc_Node(lang::cc::Node::Expr::Bin6::op::MODULO_T x, std::function<lang::cc::Node_T(lang::cc::Node_T)> f);

lang::cc::Node_T xformT_lang_cc_Node(lang::cc::Node::Expr::Bin6::op_T x, std::function<lang::cc::Node_T(lang::cc::Node_T)> f);

lang::cc::Node_T xformT_lang_cc_Node(lang::cc::Node::Expr::Bin6_T x, std::function<lang::cc::Node_T(lang::cc::Node_T)> f);

lang::cc::Node_T xformT_lang_cc_Node(lang::cc::Node::Expr::Template_T x, std::function<lang::cc::Node_T(lang::cc::Node_T)> f);

lang::cc::Node_T xformT_lang_cc_Node(lang::cc::Node::Expr::New_T x, std::function<lang::cc::Node_T(lang::cc::Node_T)> f);

lang::cc::Node_T xformT_lang_cc_Node(lang::cc::Node::Expr::Delete_T x, std::function<lang::cc::Node_T(lang::cc::Node_T)> f);

lang::cc::Node_T xformT_lang_cc_Node(lang::cc::Node::Expr::Ellipsis_T x, std::function<lang::cc::Node_T(lang::cc::Node_T)> f);

lang::cc::Node_T xformT_lang_cc_Node(lang::cc::Node::Expr::Tilde_T x, std::function<lang::cc::Node_T(lang::cc::Node_T)> f);

lang::cc::Node_T xformT_lang_cc_Node(lang::cc::Node::Expr::Namespace_T x, std::function<lang::cc::Node_T(lang::cc::Node_T)> f);

lang::cc::Node_T xformT_lang_cc_Node(lang::cc::Node::Expr::Id_T x, std::function<lang::cc::Node_T(lang::cc::Node_T)> f);

lang::cc::Node_T xformT_lang_cc_Node(lang::cc::Node::Expr::Lit::Integer_T x, std::function<lang::cc::Node_T(lang::cc::Node_T)> f);

lang::cc::Node_T xformT_lang_cc_Node(lang::cc::Node::Expr::Lit::Str__T x, std::function<lang::cc::Node_T(lang::cc::Node_T)> f);

lang::cc::Node_T xformT_lang_cc_Node(lang::cc::Node::Expr::Lit::Array_T x, std::function<lang::cc::Node_T(lang::cc::Node_T)> f);

lang::cc::Node_T xformT_lang_cc_Node(lang::cc::Node::Expr::Lit_T x, std::function<lang::cc::Node_T(lang::cc::Node_T)> f);

lang::cc::Node_T xformT_lang_cc_Node(lang::cc::Node::Expr_T x, std::function<lang::cc::Node_T(lang::cc::Node_T)> f);

lang::cc::Node_T xformT_lang_cc_Node(lang::cc::Node::Decl::Struct::tmpl::item::args::item_T x, std::function<lang::cc::Node_T(lang::cc::Node_T)> f);

lang::cc::Node_T xformT_lang_cc_Node(lang::cc::Node::Decl::Struct::tmpl::item_T x, std::function<lang::cc::Node_T(lang::cc::Node_T)> f);

lang::cc::Node_T xformT_lang_cc_Node(lang::cc::Node::StructDeclDef::Decl_T x, std::function<lang::cc::Node_T(lang::cc::Node_T)> f);

lang::cc::Node_T xformT_lang_cc_Node(lang::cc::Node::Entry::Field_T x, std::function<lang::cc::Node_T(lang::cc::Node_T)> f);

lang::cc::Node_T xformT_lang_cc_Node(lang::cc::Node::Entry::Fun::tmpl::item::args::item_T x, std::function<lang::cc::Node_T(lang::cc::Node_T)> f);

lang::cc::Node_T xformT_lang_cc_Node(lang::cc::Node::Entry::Fun::tmpl::item_T x, std::function<lang::cc::Node_T(lang::cc::Node_T)> f);

lang::cc::Node_T xformT_lang_cc_Node(lang::cc::Node::Mod::Const_T x, std::function<lang::cc::Node_T(lang::cc::Node_T)> f);

lang::cc::Node_T xformT_lang_cc_Node(lang::cc::Node::Mod::Inline_T x, std::function<lang::cc::Node_T(lang::cc::Node_T)> f);

lang::cc::Node_T xformT_lang_cc_Node(lang::cc::Node::Mod::Static_T x, std::function<lang::cc::Node_T(lang::cc::Node_T)> f);

lang::cc::Node_T xformT_lang_cc_Node(lang::cc::Node::Mod::Virtual_T x, std::function<lang::cc::Node_T(lang::cc::Node_T)> f);

lang::cc::Node_T xformT_lang_cc_Node(lang::cc::Node::Mod::NoInline_T x, std::function<lang::cc::Node_T(lang::cc::Node_T)> f);

lang::cc::Node_T xformT_lang_cc_Node(lang::cc::Node::Mod::AlwaysInline_T x, std::function<lang::cc::Node_T(lang::cc::Node_T)> f);

lang::cc::Node_T xformT_lang_cc_Node(lang::cc::Node::Attribute::Simple_T x, std::function<lang::cc::Node_T(lang::cc::Node_T)> f);

lang::cc::Node_T xformT_lang_cc_Node(lang::cc::Node::Attribute::Namespaced_T x, std::function<lang::cc::Node_T(lang::cc::Node_T)> f);

lang::cc::Node_T xformT_lang_cc_Node(lang::cc::Node::Attribute_T x, std::function<lang::cc::Node_T(lang::cc::Node_T)> f);

lang::cc::Node_T xformT_lang_cc_Node(lang::cc::Node::Mod::Attribute_T x, std::function<lang::cc::Node_T(lang::cc::Node_T)> f);

lang::cc::Node_T xformT_lang_cc_Node(lang::cc::Node::Mod_T x, std::function<lang::cc::Node_T(lang::cc::Node_T)> f);

lang::cc::Node_T xformT_lang_cc_Node(lang::cc::Node::Param::val_T x, std::function<lang::cc::Node_T(lang::cc::Node_T)> f);

lang::cc::Node_T xformT_lang_cc_Node(lang::cc::Node::Param_T x, std::function<lang::cc::Node_T(lang::cc::Node_T)> f);

lang::cc::Node_T xformT_lang_cc_Node(lang::cc::Node::FunDeclDef::Decl_T x, std::function<lang::cc::Node_T(lang::cc::Node_T)> f);

lang::cc::Node_T xformT_lang_cc_Node(lang::cc::Node::TypedDecl::vars::item::val_T x, std::function<lang::cc::Node_T(lang::cc::Node_T)> f);

lang::cc::Node_T xformT_lang_cc_Node(lang::cc::Node::TypedDecl::vars::item_T x, std::function<lang::cc::Node_T(lang::cc::Node_T)> f);

lang::cc::Node_T xformT_lang_cc_Node(lang::cc::Node::TypedDecl_T x, std::function<lang::cc::Node_T(lang::cc::Node_T)> f);

lang::cc::Node_T xformT_lang_cc_Node(lang::cc::Node::Stmt::Decl_T x, std::function<lang::cc::Node_T(lang::cc::Node_T)> f);

lang::cc::Node_T xformT_lang_cc_Node(lang::cc::Node::Stmt::Expr_T x, std::function<lang::cc::Node_T(lang::cc::Node_T)> f);

lang::cc::Node_T xformT_lang_cc_Node(lang::cc::Node::Stmt::Block_T x, std::function<lang::cc::Node_T(lang::cc::Node_T)> f);

lang::cc::Node_T xformT_lang_cc_Node(lang::cc::Node::Stmt::If_T x, std::function<lang::cc::Node_T(lang::cc::Node_T)> f);

lang::cc::Node_T xformT_lang_cc_Node(lang::cc::Node::Stmt::IfElse_T x, std::function<lang::cc::Node_T(lang::cc::Node_T)> f);

lang::cc::Node_T xformT_lang_cc_Node(lang::cc::Node::ExprExt::Expr_T x, std::function<lang::cc::Node_T(lang::cc::Node_T)> f);

lang::cc::Node_T xformT_lang_cc_Node(lang::cc::Node::ExprExt::Decl_T x, std::function<lang::cc::Node_T(lang::cc::Node_T)> f);

lang::cc::Node_T xformT_lang_cc_Node(lang::cc::Node::ExprExt_T x, std::function<lang::cc::Node_T(lang::cc::Node_T)> f);

lang::cc::Node_T xformT_lang_cc_Node(lang::cc::Node::Stmt::For_T x, std::function<lang::cc::Node_T(lang::cc::Node_T)> f);

lang::cc::Node_T xformT_lang_cc_Node(lang::cc::Node::SwitchCase::Case_T x, std::function<lang::cc::Node_T(lang::cc::Node_T)> f);

lang::cc::Node_T xformT_lang_cc_Node(lang::cc::Node::SwitchCase::Default_T x, std::function<lang::cc::Node_T(lang::cc::Node_T)> f);

lang::cc::Node_T xformT_lang_cc_Node(lang::cc::Node::SwitchCase_T x, std::function<lang::cc::Node_T(lang::cc::Node_T)> f);

lang::cc::Node_T xformT_lang_cc_Node(lang::cc::Node::Stmt::Switch_T x, std::function<lang::cc::Node_T(lang::cc::Node_T)> f);

lang::cc::Node_T xformT_lang_cc_Node(lang::cc::Node::Stmt::Break_T x, std::function<lang::cc::Node_T(lang::cc::Node_T)> f);

lang::cc::Node_T xformT_lang_cc_Node(lang::cc::Node::Stmt::Continue_T x, std::function<lang::cc::Node_T(lang::cc::Node_T)> f);

lang::cc::Node_T xformT_lang_cc_Node(lang::cc::Node::Stmt::Return_T x, std::function<lang::cc::Node_T(lang::cc::Node_T)> f);

lang::cc::Node_T xformT_lang_cc_Node(lang::cc::Node::Stmt_T x, std::function<lang::cc::Node_T(lang::cc::Node_T)> f);

lang::cc::Node_T xformT_lang_cc_Node(lang::cc::Node::Block_T x, std::function<lang::cc::Node_T(lang::cc::Node_T)> f);

lang::cc::Node_T xformT_lang_cc_Node(lang::cc::Node::FunDeclDef::Def_T x, std::function<lang::cc::Node_T(lang::cc::Node_T)> f);

lang::cc::Node_T xformT_lang_cc_Node(lang::cc::Node::FunDeclDef::Del_T x, std::function<lang::cc::Node_T(lang::cc::Node_T)> f);

lang::cc::Node_T xformT_lang_cc_Node(lang::cc::Node::FunDeclDef::Zero_T x, std::function<lang::cc::Node_T(lang::cc::Node_T)> f);

lang::cc::Node_T xformT_lang_cc_Node(lang::cc::Node::FunDeclDef_T x, std::function<lang::cc::Node_T(lang::cc::Node_T)> f);

lang::cc::Node_T xformT_lang_cc_Node(lang::cc::Node::Entry::Fun_T x, std::function<lang::cc::Node_T(lang::cc::Node_T)> f);

lang::cc::Node_T xformT_lang_cc_Node(lang::cc::Node::Entry_T x, std::function<lang::cc::Node_T(lang::cc::Node_T)> f);

lang::cc::Node_T xformT_lang_cc_Node(lang::cc::Node::StructDeclDef::Def_T x, std::function<lang::cc::Node_T(lang::cc::Node_T)> f);

lang::cc::Node_T xformT_lang_cc_Node(lang::cc::Node::StructDeclDef_T x, std::function<lang::cc::Node_T(lang::cc::Node_T)> f);

lang::cc::Node_T xformT_lang_cc_Node(lang::cc::Node::Decl::Struct_T x, std::function<lang::cc::Node_T(lang::cc::Node_T)> f);

lang::cc::Node_T xformT_lang_cc_Node(lang::cc::Node::Decl::EnumStruct_T x, std::function<lang::cc::Node_T(lang::cc::Node_T)> f);

lang::cc::Node_T xformT_lang_cc_Node(lang::cc::Node::Decl::Fun::tmpl::item::args::item_T x, std::function<lang::cc::Node_T(lang::cc::Node_T)> f);

lang::cc::Node_T xformT_lang_cc_Node(lang::cc::Node::Decl::Fun::tmpl::item_T x, std::function<lang::cc::Node_T(lang::cc::Node_T)> f);

lang::cc::Node_T xformT_lang_cc_Node(lang::cc::Node::Decl::Fun_T x, std::function<lang::cc::Node_T(lang::cc::Node_T)> f);

lang::cc::Node_T xformT_lang_cc_Node(lang::cc::Node::Decl::Namespace_T x, std::function<lang::cc::Node_T(lang::cc::Node_T)> f);

lang::cc::Node_T xformT_lang_cc_Node(lang::cc::Node::Decl::UsingAlias::tmpl::item::args::item_T x, std::function<lang::cc::Node_T(lang::cc::Node_T)> f);

lang::cc::Node_T xformT_lang_cc_Node(lang::cc::Node::Decl::UsingAlias::tmpl::item_T x, std::function<lang::cc::Node_T(lang::cc::Node_T)> f);

lang::cc::Node_T xformT_lang_cc_Node(lang::cc::Node::Decl::UsingAlias_T x, std::function<lang::cc::Node_T(lang::cc::Node_T)> f);

lang::cc::Node_T xformT_lang_cc_Node(lang::cc::Node::Decl::UsingNamespace_T x, std::function<lang::cc::Node_T(lang::cc::Node_T)> f);

lang::cc::Node_T xformT_lang_cc_Node(lang::cc::Node::Decl::Include_T x, std::function<lang::cc::Node_T(lang::cc::Node_T)> f);

lang::cc::Node_T xformT_lang_cc_Node(lang::cc::Node::Decl::PragmaOnce_T x, std::function<lang::cc::Node_T(lang::cc::Node_T)> f);

lang::cc::Node_T xformT_lang_cc_Node(lang::cc::Node::Decl_T x, std::function<lang::cc::Node_T(lang::cc::Node_T)> f);

lang::cc::Node_T xformT_lang_cc_Node(lang::cc::Node::Module_T x, std::function<lang::cc::Node_T(lang::cc::Node_T)> f);

lang::cc::Node_T xformT_lang_cc_Node(lang::cc::Node_T x, std::function<lang::cc::Node_T(lang::cc::Node_T)> f);

lang::cc::Node_T xform_lang_cc_Node(lang::cc::Node_T x, std::function<lang::cc::Node_T(lang::cc::Node_T)> f);

lang::cc::Node::Module_T xform_lang_cc_Node(lang::cc::Node::Module_T x, std::function<lang::cc::Node_T(lang::cc::Node_T)> f);

lang::cc::Node::Decl_T xform_lang_cc_Node(lang::cc::Node::Decl_T x, std::function<lang::cc::Node_T(lang::cc::Node_T)> f);

lang::cc::Node::Decl::Struct_T xform_lang_cc_Node(lang::cc::Node::Decl::Struct_T x, std::function<lang::cc::Node_T(lang::cc::Node_T)> f);

lang::cc::Node::Decl::Struct::tmpl::item_T xform_lang_cc_Node(lang::cc::Node::Decl::Struct::tmpl::item_T x, std::function<lang::cc::Node_T(lang::cc::Node_T)> f);

lang::cc::Node::Decl::Struct::tmpl::item::args::item_T xform_lang_cc_Node(lang::cc::Node::Decl::Struct::tmpl::item::args::item_T x, std::function<lang::cc::Node_T(lang::cc::Node_T)> f);

lang::cc::Node::Expr_T xform_lang_cc_Node(lang::cc::Node::Expr_T x, std::function<lang::cc::Node_T(lang::cc::Node_T)> f);

lang::cc::Node::Expr::Paren_T xform_lang_cc_Node(lang::cc::Node::Expr::Paren_T x, std::function<lang::cc::Node_T(lang::cc::Node_T)> f);

lang::cc::Node::Expr::Call_T xform_lang_cc_Node(lang::cc::Node::Expr::Call_T x, std::function<lang::cc::Node_T(lang::cc::Node_T)> f);

lang::cc::Node::Expr::Index_T xform_lang_cc_Node(lang::cc::Node::Expr::Index_T x, std::function<lang::cc::Node_T(lang::cc::Node_T)> f);

lang::cc::Node::Expr::IndexEmpty_T xform_lang_cc_Node(lang::cc::Node::Expr::IndexEmpty_T x, std::function<lang::cc::Node_T(lang::cc::Node_T)> f);

lang::cc::Node::Expr::Dot_T xform_lang_cc_Node(lang::cc::Node::Expr::Dot_T x, std::function<lang::cc::Node_T(lang::cc::Node_T)> f);

lang::cc::Node::Expr::Arrow_T xform_lang_cc_Node(lang::cc::Node::Expr::Arrow_T x, std::function<lang::cc::Node_T(lang::cc::Node_T)> f);

lang::cc::Node::Expr::Ref__T xform_lang_cc_Node(lang::cc::Node::Expr::Ref__T x, std::function<lang::cc::Node_T(lang::cc::Node_T)> f);

lang::cc::Node::Expr::AddrOf_T xform_lang_cc_Node(lang::cc::Node::Expr::AddrOf_T x, std::function<lang::cc::Node_T(lang::cc::Node_T)> f);

lang::cc::Node::Expr::Deref_T xform_lang_cc_Node(lang::cc::Node::Expr::Deref_T x, std::function<lang::cc::Node_T(lang::cc::Node_T)> f);

lang::cc::Node::Expr::UnaryPre_T xform_lang_cc_Node(lang::cc::Node::Expr::UnaryPre_T x, std::function<lang::cc::Node_T(lang::cc::Node_T)> f);

lang::cc::Node::Expr::UnaryPre::op_T xform_lang_cc_Node(lang::cc::Node::Expr::UnaryPre::op_T x, std::function<lang::cc::Node_T(lang::cc::Node_T)> f);

lang::cc::Node::Expr::UnaryPre::op::NOT_T xform_lang_cc_Node(lang::cc::Node::Expr::UnaryPre::op::NOT_T x, std::function<lang::cc::Node_T(lang::cc::Node_T)> f);

lang::cc::Node::Expr::UnaryPre::op::NEG_T xform_lang_cc_Node(lang::cc::Node::Expr::UnaryPre::op::NEG_T x, std::function<lang::cc::Node_T(lang::cc::Node_T)> f);

lang::cc::Node::Expr::IncDecPre_T xform_lang_cc_Node(lang::cc::Node::Expr::IncDecPre_T x, std::function<lang::cc::Node_T(lang::cc::Node_T)> f);

lang::cc::Node::Expr::IncDecPre::op_T xform_lang_cc_Node(lang::cc::Node::Expr::IncDecPre::op_T x, std::function<lang::cc::Node_T(lang::cc::Node_T)> f);

lang::cc::Node::Expr::IncDecPre::op::INC_T xform_lang_cc_Node(lang::cc::Node::Expr::IncDecPre::op::INC_T x, std::function<lang::cc::Node_T(lang::cc::Node_T)> f);

lang::cc::Node::Expr::IncDecPre::op::DEC_T xform_lang_cc_Node(lang::cc::Node::Expr::IncDecPre::op::DEC_T x, std::function<lang::cc::Node_T(lang::cc::Node_T)> f);

lang::cc::Node::Expr::IncDecPost_T xform_lang_cc_Node(lang::cc::Node::Expr::IncDecPost_T x, std::function<lang::cc::Node_T(lang::cc::Node_T)> f);

lang::cc::Node::Expr::IncDecPost::op_T xform_lang_cc_Node(lang::cc::Node::Expr::IncDecPost::op_T x, std::function<lang::cc::Node_T(lang::cc::Node_T)> f);

lang::cc::Node::Expr::IncDecPost::op::INC_T xform_lang_cc_Node(lang::cc::Node::Expr::IncDecPost::op::INC_T x, std::function<lang::cc::Node_T(lang::cc::Node_T)> f);

lang::cc::Node::Expr::IncDecPost::op::DEC_T xform_lang_cc_Node(lang::cc::Node::Expr::IncDecPost::op::DEC_T x, std::function<lang::cc::Node_T(lang::cc::Node_T)> f);

lang::cc::Node::Expr::Assign_T xform_lang_cc_Node(lang::cc::Node::Expr::Assign_T x, std::function<lang::cc::Node_T(lang::cc::Node_T)> f);

lang::cc::Node::Expr::Bin1_T xform_lang_cc_Node(lang::cc::Node::Expr::Bin1_T x, std::function<lang::cc::Node_T(lang::cc::Node_T)> f);

lang::cc::Node::Expr::Bin1::op_T xform_lang_cc_Node(lang::cc::Node::Expr::Bin1::op_T x, std::function<lang::cc::Node_T(lang::cc::Node_T)> f);

lang::cc::Node::Expr::Bin1::op::LOR_T xform_lang_cc_Node(lang::cc::Node::Expr::Bin1::op::LOR_T x, std::function<lang::cc::Node_T(lang::cc::Node_T)> f);

lang::cc::Node::Expr::Bin2_T xform_lang_cc_Node(lang::cc::Node::Expr::Bin2_T x, std::function<lang::cc::Node_T(lang::cc::Node_T)> f);

lang::cc::Node::Expr::Bin2::op_T xform_lang_cc_Node(lang::cc::Node::Expr::Bin2::op_T x, std::function<lang::cc::Node_T(lang::cc::Node_T)> f);

lang::cc::Node::Expr::Bin2::op::LAND_T xform_lang_cc_Node(lang::cc::Node::Expr::Bin2::op::LAND_T x, std::function<lang::cc::Node_T(lang::cc::Node_T)> f);

lang::cc::Node::Expr::Bin3_T xform_lang_cc_Node(lang::cc::Node::Expr::Bin3_T x, std::function<lang::cc::Node_T(lang::cc::Node_T)> f);

lang::cc::Node::Expr::Bin3::op_T xform_lang_cc_Node(lang::cc::Node::Expr::Bin3::op_T x, std::function<lang::cc::Node_T(lang::cc::Node_T)> f);

lang::cc::Node::Expr::Bin3::op::EQ_T xform_lang_cc_Node(lang::cc::Node::Expr::Bin3::op::EQ_T x, std::function<lang::cc::Node_T(lang::cc::Node_T)> f);

lang::cc::Node::Expr::Bin3::op::NE_T xform_lang_cc_Node(lang::cc::Node::Expr::Bin3::op::NE_T x, std::function<lang::cc::Node_T(lang::cc::Node_T)> f);

lang::cc::Node::Expr::Bin3::op::LE_T xform_lang_cc_Node(lang::cc::Node::Expr::Bin3::op::LE_T x, std::function<lang::cc::Node_T(lang::cc::Node_T)> f);

lang::cc::Node::Expr::Bin3::op::GE_T xform_lang_cc_Node(lang::cc::Node::Expr::Bin3::op::GE_T x, std::function<lang::cc::Node_T(lang::cc::Node_T)> f);

lang::cc::Node::Expr::Bin3::op::LT_T xform_lang_cc_Node(lang::cc::Node::Expr::Bin3::op::LT_T x, std::function<lang::cc::Node_T(lang::cc::Node_T)> f);

lang::cc::Node::Expr::Bin3::op::GT_T xform_lang_cc_Node(lang::cc::Node::Expr::Bin3::op::GT_T x, std::function<lang::cc::Node_T(lang::cc::Node_T)> f);

lang::cc::Node::Expr::Bin4_T xform_lang_cc_Node(lang::cc::Node::Expr::Bin4_T x, std::function<lang::cc::Node_T(lang::cc::Node_T)> f);

lang::cc::Node::Expr::Bin4::op_T xform_lang_cc_Node(lang::cc::Node::Expr::Bin4::op_T x, std::function<lang::cc::Node_T(lang::cc::Node_T)> f);

lang::cc::Node::Expr::Bin4::op::SHL_T xform_lang_cc_Node(lang::cc::Node::Expr::Bin4::op::SHL_T x, std::function<lang::cc::Node_T(lang::cc::Node_T)> f);

lang::cc::Node::Expr::Bin5_T xform_lang_cc_Node(lang::cc::Node::Expr::Bin5_T x, std::function<lang::cc::Node_T(lang::cc::Node_T)> f);

lang::cc::Node::Expr::Bin5::op_T xform_lang_cc_Node(lang::cc::Node::Expr::Bin5::op_T x, std::function<lang::cc::Node_T(lang::cc::Node_T)> f);

lang::cc::Node::Expr::Bin5::op::PLUS_T xform_lang_cc_Node(lang::cc::Node::Expr::Bin5::op::PLUS_T x, std::function<lang::cc::Node_T(lang::cc::Node_T)> f);

lang::cc::Node::Expr::Bin5::op::MINUS_T xform_lang_cc_Node(lang::cc::Node::Expr::Bin5::op::MINUS_T x, std::function<lang::cc::Node_T(lang::cc::Node_T)> f);

lang::cc::Node::Expr::Bin6_T xform_lang_cc_Node(lang::cc::Node::Expr::Bin6_T x, std::function<lang::cc::Node_T(lang::cc::Node_T)> f);

lang::cc::Node::Expr::Bin6::op_T xform_lang_cc_Node(lang::cc::Node::Expr::Bin6::op_T x, std::function<lang::cc::Node_T(lang::cc::Node_T)> f);

lang::cc::Node::Expr::Bin6::op::TIMES_T xform_lang_cc_Node(lang::cc::Node::Expr::Bin6::op::TIMES_T x, std::function<lang::cc::Node_T(lang::cc::Node_T)> f);

lang::cc::Node::Expr::Bin6::op::DIVIDE_T xform_lang_cc_Node(lang::cc::Node::Expr::Bin6::op::DIVIDE_T x, std::function<lang::cc::Node_T(lang::cc::Node_T)> f);

lang::cc::Node::Expr::Bin6::op::MODULO_T xform_lang_cc_Node(lang::cc::Node::Expr::Bin6::op::MODULO_T x, std::function<lang::cc::Node_T(lang::cc::Node_T)> f);

lang::cc::Node::Expr::Template_T xform_lang_cc_Node(lang::cc::Node::Expr::Template_T x, std::function<lang::cc::Node_T(lang::cc::Node_T)> f);

lang::cc::Node::Expr::New_T xform_lang_cc_Node(lang::cc::Node::Expr::New_T x, std::function<lang::cc::Node_T(lang::cc::Node_T)> f);

lang::cc::Node::Expr::Delete_T xform_lang_cc_Node(lang::cc::Node::Expr::Delete_T x, std::function<lang::cc::Node_T(lang::cc::Node_T)> f);

lang::cc::Node::Expr::Ellipsis_T xform_lang_cc_Node(lang::cc::Node::Expr::Ellipsis_T x, std::function<lang::cc::Node_T(lang::cc::Node_T)> f);

lang::cc::Node::Expr::Tilde_T xform_lang_cc_Node(lang::cc::Node::Expr::Tilde_T x, std::function<lang::cc::Node_T(lang::cc::Node_T)> f);

lang::cc::Node::Expr::Namespace_T xform_lang_cc_Node(lang::cc::Node::Expr::Namespace_T x, std::function<lang::cc::Node_T(lang::cc::Node_T)> f);

lang::cc::Node::Expr::Id_T xform_lang_cc_Node(lang::cc::Node::Expr::Id_T x, std::function<lang::cc::Node_T(lang::cc::Node_T)> f);

lang::cc::Node::Expr::Lit_T xform_lang_cc_Node(lang::cc::Node::Expr::Lit_T x, std::function<lang::cc::Node_T(lang::cc::Node_T)> f);

lang::cc::Node::Expr::Lit::Integer_T xform_lang_cc_Node(lang::cc::Node::Expr::Lit::Integer_T x, std::function<lang::cc::Node_T(lang::cc::Node_T)> f);

lang::cc::Node::Expr::Lit::Str__T xform_lang_cc_Node(lang::cc::Node::Expr::Lit::Str__T x, std::function<lang::cc::Node_T(lang::cc::Node_T)> f);

lang::cc::Node::Expr::Lit::Array_T xform_lang_cc_Node(lang::cc::Node::Expr::Lit::Array_T x, std::function<lang::cc::Node_T(lang::cc::Node_T)> f);

lang::cc::Node::StructDeclDef_T xform_lang_cc_Node(lang::cc::Node::StructDeclDef_T x, std::function<lang::cc::Node_T(lang::cc::Node_T)> f);

lang::cc::Node::StructDeclDef::Decl_T xform_lang_cc_Node(lang::cc::Node::StructDeclDef::Decl_T x, std::function<lang::cc::Node_T(lang::cc::Node_T)> f);

lang::cc::Node::StructDeclDef::Def_T xform_lang_cc_Node(lang::cc::Node::StructDeclDef::Def_T x, std::function<lang::cc::Node_T(lang::cc::Node_T)> f);

lang::cc::Node::Entry_T xform_lang_cc_Node(lang::cc::Node::Entry_T x, std::function<lang::cc::Node_T(lang::cc::Node_T)> f);

lang::cc::Node::Entry::Field_T xform_lang_cc_Node(lang::cc::Node::Entry::Field_T x, std::function<lang::cc::Node_T(lang::cc::Node_T)> f);

lang::cc::Node::Entry::Fun_T xform_lang_cc_Node(lang::cc::Node::Entry::Fun_T x, std::function<lang::cc::Node_T(lang::cc::Node_T)> f);

lang::cc::Node::Entry::Fun::tmpl::item_T xform_lang_cc_Node(lang::cc::Node::Entry::Fun::tmpl::item_T x, std::function<lang::cc::Node_T(lang::cc::Node_T)> f);

lang::cc::Node::Entry::Fun::tmpl::item::args::item_T xform_lang_cc_Node(lang::cc::Node::Entry::Fun::tmpl::item::args::item_T x, std::function<lang::cc::Node_T(lang::cc::Node_T)> f);

lang::cc::Node::Mod_T xform_lang_cc_Node(lang::cc::Node::Mod_T x, std::function<lang::cc::Node_T(lang::cc::Node_T)> f);

lang::cc::Node::Mod::Const_T xform_lang_cc_Node(lang::cc::Node::Mod::Const_T x, std::function<lang::cc::Node_T(lang::cc::Node_T)> f);

lang::cc::Node::Mod::Inline_T xform_lang_cc_Node(lang::cc::Node::Mod::Inline_T x, std::function<lang::cc::Node_T(lang::cc::Node_T)> f);

lang::cc::Node::Mod::Static_T xform_lang_cc_Node(lang::cc::Node::Mod::Static_T x, std::function<lang::cc::Node_T(lang::cc::Node_T)> f);

lang::cc::Node::Mod::Virtual_T xform_lang_cc_Node(lang::cc::Node::Mod::Virtual_T x, std::function<lang::cc::Node_T(lang::cc::Node_T)> f);

lang::cc::Node::Mod::NoInline_T xform_lang_cc_Node(lang::cc::Node::Mod::NoInline_T x, std::function<lang::cc::Node_T(lang::cc::Node_T)> f);

lang::cc::Node::Mod::AlwaysInline_T xform_lang_cc_Node(lang::cc::Node::Mod::AlwaysInline_T x, std::function<lang::cc::Node_T(lang::cc::Node_T)> f);

lang::cc::Node::Mod::Attribute_T xform_lang_cc_Node(lang::cc::Node::Mod::Attribute_T x, std::function<lang::cc::Node_T(lang::cc::Node_T)> f);

lang::cc::Node::Attribute_T xform_lang_cc_Node(lang::cc::Node::Attribute_T x, std::function<lang::cc::Node_T(lang::cc::Node_T)> f);

lang::cc::Node::Attribute::Simple_T xform_lang_cc_Node(lang::cc::Node::Attribute::Simple_T x, std::function<lang::cc::Node_T(lang::cc::Node_T)> f);

lang::cc::Node::Attribute::Namespaced_T xform_lang_cc_Node(lang::cc::Node::Attribute::Namespaced_T x, std::function<lang::cc::Node_T(lang::cc::Node_T)> f);

lang::cc::Node::Param_T xform_lang_cc_Node(lang::cc::Node::Param_T x, std::function<lang::cc::Node_T(lang::cc::Node_T)> f);

lang::cc::Node::Param::val_T xform_lang_cc_Node(lang::cc::Node::Param::val_T x, std::function<lang::cc::Node_T(lang::cc::Node_T)> f);

lang::cc::Node::FunDeclDef_T xform_lang_cc_Node(lang::cc::Node::FunDeclDef_T x, std::function<lang::cc::Node_T(lang::cc::Node_T)> f);

lang::cc::Node::FunDeclDef::Decl_T xform_lang_cc_Node(lang::cc::Node::FunDeclDef::Decl_T x, std::function<lang::cc::Node_T(lang::cc::Node_T)> f);

lang::cc::Node::FunDeclDef::Def_T xform_lang_cc_Node(lang::cc::Node::FunDeclDef::Def_T x, std::function<lang::cc::Node_T(lang::cc::Node_T)> f);

lang::cc::Node::Block_T xform_lang_cc_Node(lang::cc::Node::Block_T x, std::function<lang::cc::Node_T(lang::cc::Node_T)> f);

lang::cc::Node::Stmt_T xform_lang_cc_Node(lang::cc::Node::Stmt_T x, std::function<lang::cc::Node_T(lang::cc::Node_T)> f);

lang::cc::Node::Stmt::Decl_T xform_lang_cc_Node(lang::cc::Node::Stmt::Decl_T x, std::function<lang::cc::Node_T(lang::cc::Node_T)> f);

lang::cc::Node::TypedDecl_T xform_lang_cc_Node(lang::cc::Node::TypedDecl_T x, std::function<lang::cc::Node_T(lang::cc::Node_T)> f);

lang::cc::Node::TypedDecl::vars::item_T xform_lang_cc_Node(lang::cc::Node::TypedDecl::vars::item_T x, std::function<lang::cc::Node_T(lang::cc::Node_T)> f);

lang::cc::Node::TypedDecl::vars::item::val_T xform_lang_cc_Node(lang::cc::Node::TypedDecl::vars::item::val_T x, std::function<lang::cc::Node_T(lang::cc::Node_T)> f);

lang::cc::Node::Stmt::Expr_T xform_lang_cc_Node(lang::cc::Node::Stmt::Expr_T x, std::function<lang::cc::Node_T(lang::cc::Node_T)> f);

lang::cc::Node::Stmt::Block_T xform_lang_cc_Node(lang::cc::Node::Stmt::Block_T x, std::function<lang::cc::Node_T(lang::cc::Node_T)> f);

lang::cc::Node::Stmt::If_T xform_lang_cc_Node(lang::cc::Node::Stmt::If_T x, std::function<lang::cc::Node_T(lang::cc::Node_T)> f);

lang::cc::Node::Stmt::IfElse_T xform_lang_cc_Node(lang::cc::Node::Stmt::IfElse_T x, std::function<lang::cc::Node_T(lang::cc::Node_T)> f);

lang::cc::Node::Stmt::For_T xform_lang_cc_Node(lang::cc::Node::Stmt::For_T x, std::function<lang::cc::Node_T(lang::cc::Node_T)> f);

lang::cc::Node::ExprExt_T xform_lang_cc_Node(lang::cc::Node::ExprExt_T x, std::function<lang::cc::Node_T(lang::cc::Node_T)> f);

lang::cc::Node::ExprExt::Expr_T xform_lang_cc_Node(lang::cc::Node::ExprExt::Expr_T x, std::function<lang::cc::Node_T(lang::cc::Node_T)> f);

lang::cc::Node::ExprExt::Decl_T xform_lang_cc_Node(lang::cc::Node::ExprExt::Decl_T x, std::function<lang::cc::Node_T(lang::cc::Node_T)> f);

lang::cc::Node::Stmt::Switch_T xform_lang_cc_Node(lang::cc::Node::Stmt::Switch_T x, std::function<lang::cc::Node_T(lang::cc::Node_T)> f);

lang::cc::Node::SwitchCase_T xform_lang_cc_Node(lang::cc::Node::SwitchCase_T x, std::function<lang::cc::Node_T(lang::cc::Node_T)> f);

lang::cc::Node::SwitchCase::Case_T xform_lang_cc_Node(lang::cc::Node::SwitchCase::Case_T x, std::function<lang::cc::Node_T(lang::cc::Node_T)> f);

lang::cc::Node::SwitchCase::Default_T xform_lang_cc_Node(lang::cc::Node::SwitchCase::Default_T x, std::function<lang::cc::Node_T(lang::cc::Node_T)> f);

lang::cc::Node::Stmt::Break_T xform_lang_cc_Node(lang::cc::Node::Stmt::Break_T x, std::function<lang::cc::Node_T(lang::cc::Node_T)> f);

lang::cc::Node::Stmt::Continue_T xform_lang_cc_Node(lang::cc::Node::Stmt::Continue_T x, std::function<lang::cc::Node_T(lang::cc::Node_T)> f);

lang::cc::Node::Stmt::Return_T xform_lang_cc_Node(lang::cc::Node::Stmt::Return_T x, std::function<lang::cc::Node_T(lang::cc::Node_T)> f);

lang::cc::Node::FunDeclDef::Del_T xform_lang_cc_Node(lang::cc::Node::FunDeclDef::Del_T x, std::function<lang::cc::Node_T(lang::cc::Node_T)> f);

lang::cc::Node::FunDeclDef::Zero_T xform_lang_cc_Node(lang::cc::Node::FunDeclDef::Zero_T x, std::function<lang::cc::Node_T(lang::cc::Node_T)> f);

lang::cc::Node::Decl::EnumStruct_T xform_lang_cc_Node(lang::cc::Node::Decl::EnumStruct_T x, std::function<lang::cc::Node_T(lang::cc::Node_T)> f);

lang::cc::Node::Decl::Fun_T xform_lang_cc_Node(lang::cc::Node::Decl::Fun_T x, std::function<lang::cc::Node_T(lang::cc::Node_T)> f);

lang::cc::Node::Decl::Fun::tmpl::item_T xform_lang_cc_Node(lang::cc::Node::Decl::Fun::tmpl::item_T x, std::function<lang::cc::Node_T(lang::cc::Node_T)> f);

lang::cc::Node::Decl::Fun::tmpl::item::args::item_T xform_lang_cc_Node(lang::cc::Node::Decl::Fun::tmpl::item::args::item_T x, std::function<lang::cc::Node_T(lang::cc::Node_T)> f);

lang::cc::Node::Decl::Namespace_T xform_lang_cc_Node(lang::cc::Node::Decl::Namespace_T x, std::function<lang::cc::Node_T(lang::cc::Node_T)> f);

lang::cc::Node::Decl::UsingAlias_T xform_lang_cc_Node(lang::cc::Node::Decl::UsingAlias_T x, std::function<lang::cc::Node_T(lang::cc::Node_T)> f);

lang::cc::Node::Decl::UsingAlias::tmpl::item_T xform_lang_cc_Node(lang::cc::Node::Decl::UsingAlias::tmpl::item_T x, std::function<lang::cc::Node_T(lang::cc::Node_T)> f);

lang::cc::Node::Decl::UsingAlias::tmpl::item::args::item_T xform_lang_cc_Node(lang::cc::Node::Decl::UsingAlias::tmpl::item::args::item_T x, std::function<lang::cc::Node_T(lang::cc::Node_T)> f);

lang::cc::Node::Decl::UsingNamespace_T xform_lang_cc_Node(lang::cc::Node::Decl::UsingNamespace_T x, std::function<lang::cc::Node_T(lang::cc::Node_T)> f);

lang::cc::Node::Decl::Include_T xform_lang_cc_Node(lang::cc::Node::Decl::Include_T x, std::function<lang::cc::Node_T(lang::cc::Node_T)> f);

lang::cc::Node::Decl::PragmaOnce_T xform_lang_cc_Node(lang::cc::Node::Decl::PragmaOnce_T x, std::function<lang::cc::Node_T(lang::cc::Node_T)> f);

namespace lang::cc::parser {
    langcc::IntPair action_by_vertex(langcc::ParserVertexId v, langcc::ParserLookahead la);
}

namespace lang::cc::parser {
    langcc::ParserVertexId vertex_dfa_step(langcc::ParserVertexId v, langcc::ParserSymId sym, langcc::ParserAttrMask attr);
}

namespace lang::cc::parser {
    langcc::ParserProcXforms proc_xform_by_prod_id();
}

namespace lang::cc::parser {
    langcc::ParserSymByName start_marker_by_name();
}

namespace lang::cc::parser {
    langcc::ParserSymId term_tok_to_sym(langcc::TokenId tok);
}

namespace lang::cc::parser {
    langcc::ParserSymId sym_to_recur_step(langcc::ParserSymId sym);
}

namespace lang::cc::parser {
    std::string sym_to_debug_string(langcc::ParserSymId sym);
}

namespace lang::cc::parser {
    langcc::Int sym_to_num_attrs(langcc::ParserSymId sym);
}

namespace lang::cc::parser {
    std::string attr_to_debug_string(langcc::ParserSymId sym, langcc::Int attr_ind);
}

namespace lang::cc {
    using LangDesc = langcc::LangDesc<Node::_T, parser::action_by_vertex, parser::vertex_dfa_step>;
}

namespace lang::cc {
    using LangDesc_T = langcc::LangDesc_T<Node::_T, parser::action_by_vertex, parser::vertex_dfa_step>;
}

namespace lang::cc {
    using QuoteEnv = langcc::QuoteEnv<Node::_T, parser::action_by_vertex, parser::vertex_dfa_step>;
}

namespace lang::cc {
    using QuoteEnv_T = langcc::QuoteEnv_T<Node::_T, parser::action_by_vertex, parser::vertex_dfa_step>;
}

namespace lang::cc {
    lang::cc::LangDesc_T init();
}

namespace lang::cc::lexer::body {
    [[always_inlines]] inline langcc::Int proc_mode_loop_opt(langcc::Ptr<langcc::LexerModeDesc> mode, langcc::Ptr<langcc::LexerState> st, langcc::Ptr<langcc::SymItemVec> emit_dst, langcc::Int mode_start_pos, langcc::Int mode_buf_pos);
}

namespace lang::cc::lexer::comment_single {
    [[always_inlines]] inline langcc::Int proc_mode_loop_opt(langcc::Ptr<langcc::LexerModeDesc> mode, langcc::Ptr<langcc::LexerState> st, langcc::Ptr<langcc::SymItemVec> emit_dst, langcc::Int mode_start_pos, langcc::Int mode_buf_pos);
}
