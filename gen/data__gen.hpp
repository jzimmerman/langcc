#pragma once

#include "langcc_rt.hpp"

namespace lang::data::lexer {
    rc_ptr<lang_rt::DFALabelIdVec> label_ids_ascii();

    rc_ptr<lang_rt::DFALabelIdMap> label_ids_unicode();
}

namespace lang::data::lexer::body {
    lang_rt::DFAVertexId step(lang_rt::DFAVertexId v, lang_rt::DFALabelId lbl);

    __attribute__((always_inline)) lang_rt::DFAActionWithToken acc(lang_rt::DFAVertexId v);

    __attribute__((always_inline)) IntPair step_exec(ptr<lang_rt::LexerState> st, ptr<lang_rt::SymItemVec> emit_dst, ptr<lang_rt::LexWhitespaceState> ws_state, lang_rt::DFAActionId acc, lang_rt::TokenId tok, Int& in_i, Int& tok_lo, Int& tok_hi);

    Int proc_mode_loop(ptr<lang_rt::LexerState> st, ptr<lang_rt::SymItemVec> emit_dst, Int mode_start_pos, Int mode_buf_pos);
}

namespace lang::data::lexer::comment_single {
    lang_rt::DFAVertexId step(lang_rt::DFAVertexId v, lang_rt::DFALabelId lbl);

    __attribute__((always_inline)) lang_rt::DFAActionWithToken acc(lang_rt::DFAVertexId v);

    __attribute__((always_inline)) IntPair step_exec(ptr<lang_rt::LexerState> st, ptr<lang_rt::SymItemVec> emit_dst, ptr<lang_rt::LexWhitespaceState> ws_state, lang_rt::DFAActionId acc, lang_rt::TokenId tok, Int& in_i, Int& tok_lo, Int& tok_hi);

    Int proc_mode_loop(ptr<lang_rt::LexerState> st, ptr<lang_rt::SymItemVec> emit_dst, Int mode_start_pos, Int mode_buf_pos);
}

#pragma once

#include "langcc_util.hpp"

namespace lang::data::Node::Module {
    struct _T;
}

namespace lang::data::Node {
    using Module_T = rc_ptr<lang::data::Node::Module::_T>;
}

namespace lang::data::Node::Decl::Include {
    struct _T;
}

namespace lang::data::Node::Decl {
    using Include_T = rc_ptr<lang::data::Node::Decl::Include::_T>;
}

namespace lang::data::Node::Decl::Namespace {
    struct _T;
}

namespace lang::data::Node::Decl {
    using Namespace_T = rc_ptr<lang::data::Node::Decl::Namespace::_T>;
}

namespace lang::data::Node::Decl::Data {
    struct _T;
}

namespace lang::data::Node::Decl {
    using Data_T = rc_ptr<lang::data::Node::Decl::Data::_T>;
}

namespace lang::data::Node::Decl::Enum {
    struct _T;
}

namespace lang::data::Node::Decl {
    using Enum_T = rc_ptr<lang::data::Node::Decl::Enum::_T>;
}

namespace lang::data::Node::Mod::Mut {
    struct _T;
}

namespace lang::data::Node::Mod {
    using Mut_T = rc_ptr<lang::data::Node::Mod::Mut::_T>;
}

namespace lang::data::Node::Mod::Xform {
    struct _T;
}

namespace lang::data::Node::Mod {
    using Xform_T = rc_ptr<lang::data::Node::Mod::Xform::_T>;
}

namespace lang::data::Node::Mod::Visit {
    struct _T;
}

namespace lang::data::Node::Mod {
    using Visit_T = rc_ptr<lang::data::Node::Mod::Visit::_T>;
}

namespace lang::data::Node::Param {
    struct _T;
}

namespace lang::data::Node {
    using Param_T = rc_ptr<lang::data::Node::Param::_T>;
}

namespace lang::data::Node::Field {
    struct _T;
}

namespace lang::data::Node {
    using Field_T = rc_ptr<lang::data::Node::Field::_T>;
}

namespace lang::data::Node::Expr::Id {
    struct _T;
}

namespace lang::data::Node::Expr {
    using Id_T = rc_ptr<lang::data::Node::Expr::Id::_T>;
}

namespace lang::data::Node::Expr::App {
    struct _T;
}

namespace lang::data::Node::Expr {
    using App_T = rc_ptr<lang::data::Node::Expr::App::_T>;
}

namespace lang::data::Node::Expr::Type_ {
    struct _T;
}

namespace lang::data::Node::Expr {
    using Type__T = rc_ptr<lang::data::Node::Expr::Type_::_T>;
}

namespace lang::data::Node::SumId {
    struct _T;
}

namespace lang::data::Node {
    using SumId_T = rc_ptr<lang::data::Node::SumId::_T>;
}

namespace lang::data::Node::Id {
    struct _T;
}

namespace lang::data::Node {
    using Id_T = rc_ptr<lang::data::Node::Id::_T>;
}

namespace lang::data::Node::Decl {
    struct _T;
}

namespace lang::data::Node {
    using Decl_T = rc_ptr<lang::data::Node::Decl::_T>;
}

namespace lang::data::Node::Mod {
    struct _T;
}

namespace lang::data::Node {
    using Mod_T = rc_ptr<lang::data::Node::Mod::_T>;
}

namespace lang::data::Node::Expr {
    struct _T;
}

namespace lang::data::Node {
    using Expr_T = rc_ptr<lang::data::Node::Expr::_T>;
}

namespace lang::data::Node {
    struct _T;
}

namespace lang::data {
    using Node_T = rc_ptr<lang::data::Node::_T>;
}

void pr_debug(ostream& os, FmtFlags flags, lang::data::Node_T x);

namespace lang::data::Node {
    enum struct _W {
        Module,
        Param,
        Field,
        SumId,
        Id,
        Decl,
        Mod,
        Expr,
    };
}

namespace lang::data::Node {
    struct _T: hash_obj, enable_rc_from_this_poly {
        void write(ostream& os, FmtFlags flags);
        lang::data::Node::_W w_;
        virtual ~_T();
        Int id_;
        lang_rt::TokenBounds bounds_;
        bool is_top_;
        lang_rt::ParserSymId sym_;
        lang_rt::ParserAttrMask attr_;
        lang_rt::ParserLookahead first_k_;
        _T(lang::data::Node::_W w);
        bool is_Module();
        bool is_Param();
        bool is_Field();
        bool is_SumId();
        bool is_Id();
        bool is_Decl();
        bool is_Mod();
        bool is_Expr();
        lang::data::Node::Module_T as_Module();
        lang::data::Node::Param_T as_Param();
        lang::data::Node::Field_T as_Field();
        lang::data::Node::SumId_T as_SumId();
        lang::data::Node::Id_T as_Id();
        lang::data::Node::Decl_T as_Decl();
        lang::data::Node::Mod_T as_Mod();
        lang::data::Node::Expr_T as_Expr();
        void hash_ser_acc_lang_data_Node(SerBuf& buf) const;
        virtual void hash_ser_acc(SerBuf& buf) const = 0;
    };
}

void pr_debug(ostream& os, FmtFlags flags, lang::data::Node::Module_T x);

namespace lang::data::Node::Module {
    __attribute__((always_inline)) lang::data::Node::Module_T make(Int id, lang_rt::TokenBounds bounds, bool is_top, lang_rt::ParserSymId sym, lang_rt::ParserAttrMask attr, lang_rt::ParserLookahead first_k, Vec_T<lang::data::Node::Decl_T> decls);
}

namespace lang::data::Node::Module {
    __attribute__((always_inline)) lang::data::Node::Module_T make_ext(ArenaPtr arena, Int id, lang_rt::TokenBounds bounds, bool is_top, lang_rt::ParserSymId sym, lang_rt::ParserAttrMask attr, lang_rt::ParserLookahead first_k, Vec_T<lang::data::Node::Decl_T> decls);
}

namespace lang::data::Node::Module {
    struct _T: lang::data::Node::_T {
        void write(ostream& os, FmtFlags flags);
        Vec_T<lang::data::Node::Decl_T> decls_;
        _T();
        lang::data::Node::Module_T with_id(Int id);
        lang::data::Node::Module_T with_bounds(lang_rt::TokenBounds bounds);
        lang::data::Node::Module_T with_is_top(bool is_top);
        lang::data::Node::Module_T with_sym(lang_rt::ParserSymId sym);
        lang::data::Node::Module_T with_attr(lang_rt::ParserAttrMask attr);
        lang::data::Node::Module_T with_first_k(lang_rt::ParserLookahead first_k);
        lang::data::Node::Module_T with_decls(Vec_T<lang::data::Node::Decl_T> decls);
        void hash_ser_acc_lang_data_Node_Module(SerBuf& buf) const;
        virtual void hash_ser_acc(SerBuf& buf) const;
    };
}

void pr_debug(ostream& os, FmtFlags flags, lang::data::Node::Param_T x);

namespace lang::data::Node::Param {
    __attribute__((always_inline)) lang::data::Node::Param_T make(Int id, lang_rt::TokenBounds bounds, bool is_top, lang_rt::ParserSymId sym, lang_rt::ParserAttrMask attr, lang_rt::ParserLookahead first_k, StrSlice name, lang::data::Node::Expr_T type_);
}

namespace lang::data::Node::Param {
    __attribute__((always_inline)) lang::data::Node::Param_T make_ext(ArenaPtr arena, Int id, lang_rt::TokenBounds bounds, bool is_top, lang_rt::ParserSymId sym, lang_rt::ParserAttrMask attr, lang_rt::ParserLookahead first_k, StrSlice name, lang::data::Node::Expr_T type_);
}

namespace lang::data::Node::Param {
    struct _T: lang::data::Node::_T {
        void write(ostream& os, FmtFlags flags);
        StrSlice name_;
        lang::data::Node::Expr_T type__;
        _T();
        lang::data::Node::Param_T with_id(Int id);
        lang::data::Node::Param_T with_bounds(lang_rt::TokenBounds bounds);
        lang::data::Node::Param_T with_is_top(bool is_top);
        lang::data::Node::Param_T with_sym(lang_rt::ParserSymId sym);
        lang::data::Node::Param_T with_attr(lang_rt::ParserAttrMask attr);
        lang::data::Node::Param_T with_first_k(lang_rt::ParserLookahead first_k);
        lang::data::Node::Param_T with_name(StrSlice name);
        lang::data::Node::Param_T with_type_(lang::data::Node::Expr_T type_);
        void hash_ser_acc_lang_data_Node_Param(SerBuf& buf) const;
        virtual void hash_ser_acc(SerBuf& buf) const;
    };
}

void pr_debug(ostream& os, FmtFlags flags, lang::data::Node::Field_T x);

namespace lang::data::Node::Field {
    __attribute__((always_inline)) lang::data::Node::Field_T make(Int id, lang_rt::TokenBounds bounds, bool is_top, lang_rt::ParserSymId sym, lang_rt::ParserAttrMask attr, lang_rt::ParserLookahead first_k, StrSlice name, bool no_hash_, lang::data::Node::Expr_T type_);
}

namespace lang::data::Node::Field {
    __attribute__((always_inline)) lang::data::Node::Field_T make_ext(ArenaPtr arena, Int id, lang_rt::TokenBounds bounds, bool is_top, lang_rt::ParserSymId sym, lang_rt::ParserAttrMask attr, lang_rt::ParserLookahead first_k, StrSlice name, bool no_hash_, lang::data::Node::Expr_T type_);
}

namespace lang::data::Node::Field {
    struct _T: lang::data::Node::_T {
        void write(ostream& os, FmtFlags flags);
        StrSlice name_;
        bool no_hash__;
        lang::data::Node::Expr_T type__;
        _T();
        lang::data::Node::Field_T with_id(Int id);
        lang::data::Node::Field_T with_bounds(lang_rt::TokenBounds bounds);
        lang::data::Node::Field_T with_is_top(bool is_top);
        lang::data::Node::Field_T with_sym(lang_rt::ParserSymId sym);
        lang::data::Node::Field_T with_attr(lang_rt::ParserAttrMask attr);
        lang::data::Node::Field_T with_first_k(lang_rt::ParserLookahead first_k);
        lang::data::Node::Field_T with_name(StrSlice name);
        lang::data::Node::Field_T with_no_hash_(bool no_hash_);
        lang::data::Node::Field_T with_type_(lang::data::Node::Expr_T type_);
        void hash_ser_acc_lang_data_Node_Field(SerBuf& buf) const;
        virtual void hash_ser_acc(SerBuf& buf) const;
    };
}

void pr_debug(ostream& os, FmtFlags flags, lang::data::Node::SumId_T x);

namespace lang::data::Node::SumId {
    __attribute__((always_inline)) lang::data::Node::SumId_T make(Int id, lang_rt::TokenBounds bounds, bool is_top, lang_rt::ParserSymId sym, lang_rt::ParserAttrMask attr, lang_rt::ParserLookahead first_k, Vec_T<StrSlice> items);
}

namespace lang::data::Node::SumId {
    __attribute__((always_inline)) lang::data::Node::SumId_T make_ext(ArenaPtr arena, Int id, lang_rt::TokenBounds bounds, bool is_top, lang_rt::ParserSymId sym, lang_rt::ParserAttrMask attr, lang_rt::ParserLookahead first_k, Vec_T<StrSlice> items);
}

namespace lang::data::Node::SumId {
    struct _T: lang::data::Node::_T {
        void write(ostream& os, FmtFlags flags);
        Vec_T<StrSlice> items_;
        _T();
        lang::data::Node::SumId_T with_id(Int id);
        lang::data::Node::SumId_T with_bounds(lang_rt::TokenBounds bounds);
        lang::data::Node::SumId_T with_is_top(bool is_top);
        lang::data::Node::SumId_T with_sym(lang_rt::ParserSymId sym);
        lang::data::Node::SumId_T with_attr(lang_rt::ParserAttrMask attr);
        lang::data::Node::SumId_T with_first_k(lang_rt::ParserLookahead first_k);
        lang::data::Node::SumId_T with_items(Vec_T<StrSlice> items);
        void hash_ser_acc_lang_data_Node_SumId(SerBuf& buf) const;
        virtual void hash_ser_acc(SerBuf& buf) const;
    };
}

void pr_debug(ostream& os, FmtFlags flags, lang::data::Node::Id_T x);

namespace lang::data::Node::Id {
    __attribute__((always_inline)) lang::data::Node::Id_T make(Int id, lang_rt::TokenBounds bounds, bool is_top, lang_rt::ParserSymId sym, lang_rt::ParserAttrMask attr, lang_rt::ParserLookahead first_k, Vec_T<StrSlice> items);
}

namespace lang::data::Node::Id {
    __attribute__((always_inline)) lang::data::Node::Id_T make_ext(ArenaPtr arena, Int id, lang_rt::TokenBounds bounds, bool is_top, lang_rt::ParserSymId sym, lang_rt::ParserAttrMask attr, lang_rt::ParserLookahead first_k, Vec_T<StrSlice> items);
}

namespace lang::data::Node::Id {
    struct _T: lang::data::Node::_T {
        void write(ostream& os, FmtFlags flags);
        Vec_T<StrSlice> items_;
        _T();
        lang::data::Node::Id_T with_id(Int id);
        lang::data::Node::Id_T with_bounds(lang_rt::TokenBounds bounds);
        lang::data::Node::Id_T with_is_top(bool is_top);
        lang::data::Node::Id_T with_sym(lang_rt::ParserSymId sym);
        lang::data::Node::Id_T with_attr(lang_rt::ParserAttrMask attr);
        lang::data::Node::Id_T with_first_k(lang_rt::ParserLookahead first_k);
        lang::data::Node::Id_T with_items(Vec_T<StrSlice> items);
        void hash_ser_acc_lang_data_Node_Id(SerBuf& buf) const;
        virtual void hash_ser_acc(SerBuf& buf) const;
    };
}

void pr_debug(ostream& os, FmtFlags flags, lang::data::Node::Decl_T x);

namespace lang::data::Node::Decl {
    enum struct _W {
        Include,
        Namespace,
        Data,
        Enum,
    };
}

namespace lang::data::Node::Decl {
    struct _T: lang::data::Node::_T {
        void write(ostream& os, FmtFlags flags);
        lang::data::Node::Decl::_W w_;
        virtual ~_T();
        _T(lang::data::Node::Decl::_W w);
        bool is_Include();
        bool is_Namespace();
        bool is_Data();
        bool is_Enum();
        lang::data::Node::Decl::Include_T as_Include();
        lang::data::Node::Decl::Namespace_T as_Namespace();
        lang::data::Node::Decl::Data_T as_Data();
        lang::data::Node::Decl::Enum_T as_Enum();
        void hash_ser_acc_lang_data_Node_Decl(SerBuf& buf) const;
        virtual void hash_ser_acc(SerBuf& buf) const = 0;
    };
}

void pr_debug(ostream& os, FmtFlags flags, lang::data::Node::Mod_T x);

namespace lang::data::Node::Mod {
    enum struct _W {
        Mut,
        Xform,
        Visit,
    };
}

namespace lang::data::Node::Mod {
    struct _T: lang::data::Node::_T {
        void write(ostream& os, FmtFlags flags);
        lang::data::Node::Mod::_W w_;
        virtual ~_T();
        _T(lang::data::Node::Mod::_W w);
        bool is_Mut();
        bool is_Xform();
        bool is_Visit();
        lang::data::Node::Mod::Mut_T as_Mut();
        lang::data::Node::Mod::Xform_T as_Xform();
        lang::data::Node::Mod::Visit_T as_Visit();
        void hash_ser_acc_lang_data_Node_Mod(SerBuf& buf) const;
        virtual void hash_ser_acc(SerBuf& buf) const = 0;
    };
}

void pr_debug(ostream& os, FmtFlags flags, lang::data::Node::Expr_T x);

namespace lang::data::Node::Expr {
    enum struct _W {
        Id,
        App,
        Type_,
    };
}

namespace lang::data::Node::Expr {
    struct _T: lang::data::Node::_T {
        void write(ostream& os, FmtFlags flags);
        lang::data::Node::Expr::_W w_;
        virtual ~_T();
        _T(lang::data::Node::Expr::_W w);
        bool is_Id();
        bool is_App();
        bool is_Type_();
        lang::data::Node::Expr::Id_T as_Id();
        lang::data::Node::Expr::App_T as_App();
        lang::data::Node::Expr::Type__T as_Type_();
        void hash_ser_acc_lang_data_Node_Expr(SerBuf& buf) const;
        virtual void hash_ser_acc(SerBuf& buf) const = 0;
    };
}

void pr_debug(ostream& os, FmtFlags flags, lang::data::Node::Decl::Include_T x);

namespace lang::data::Node::Decl::Include {
    __attribute__((always_inline)) lang::data::Node::Decl::Include_T make(Int id, lang_rt::TokenBounds bounds, bool is_top, lang_rt::ParserSymId sym, lang_rt::ParserAttrMask attr, lang_rt::ParserLookahead first_k, StrSlice path);
}

namespace lang::data::Node::Decl::Include {
    __attribute__((always_inline)) lang::data::Node::Decl::Include_T make_ext(ArenaPtr arena, Int id, lang_rt::TokenBounds bounds, bool is_top, lang_rt::ParserSymId sym, lang_rt::ParserAttrMask attr, lang_rt::ParserLookahead first_k, StrSlice path);
}

namespace lang::data::Node::Decl::Include {
    struct _T: lang::data::Node::Decl::_T {
        void write(ostream& os, FmtFlags flags);
        StrSlice path_;
        _T();
        lang::data::Node::Decl::Include_T with_id(Int id);
        lang::data::Node::Decl::Include_T with_bounds(lang_rt::TokenBounds bounds);
        lang::data::Node::Decl::Include_T with_is_top(bool is_top);
        lang::data::Node::Decl::Include_T with_sym(lang_rt::ParserSymId sym);
        lang::data::Node::Decl::Include_T with_attr(lang_rt::ParserAttrMask attr);
        lang::data::Node::Decl::Include_T with_first_k(lang_rt::ParserLookahead first_k);
        lang::data::Node::Decl::Include_T with_path(StrSlice path);
        void hash_ser_acc_lang_data_Node_Decl_Include(SerBuf& buf) const;
        virtual void hash_ser_acc(SerBuf& buf) const;
    };
}

void pr_debug(ostream& os, FmtFlags flags, lang::data::Node::Decl::Namespace_T x);

namespace lang::data::Node::Decl::Namespace {
    __attribute__((always_inline)) lang::data::Node::Decl::Namespace_T make(Int id, lang_rt::TokenBounds bounds, bool is_top, lang_rt::ParserSymId sym, lang_rt::ParserAttrMask attr, lang_rt::ParserLookahead first_k, lang::data::Node::Id_T name, Vec_T<lang::data::Node::Decl_T> body);
}

namespace lang::data::Node::Decl::Namespace {
    __attribute__((always_inline)) lang::data::Node::Decl::Namespace_T make_ext(ArenaPtr arena, Int id, lang_rt::TokenBounds bounds, bool is_top, lang_rt::ParserSymId sym, lang_rt::ParserAttrMask attr, lang_rt::ParserLookahead first_k, lang::data::Node::Id_T name, Vec_T<lang::data::Node::Decl_T> body);
}

namespace lang::data::Node::Decl::Namespace {
    struct _T: lang::data::Node::Decl::_T {
        void write(ostream& os, FmtFlags flags);
        lang::data::Node::Id_T name_;
        Vec_T<lang::data::Node::Decl_T> body_;
        _T();
        lang::data::Node::Decl::Namespace_T with_id(Int id);
        lang::data::Node::Decl::Namespace_T with_bounds(lang_rt::TokenBounds bounds);
        lang::data::Node::Decl::Namespace_T with_is_top(bool is_top);
        lang::data::Node::Decl::Namespace_T with_sym(lang_rt::ParserSymId sym);
        lang::data::Node::Decl::Namespace_T with_attr(lang_rt::ParserAttrMask attr);
        lang::data::Node::Decl::Namespace_T with_first_k(lang_rt::ParserLookahead first_k);
        lang::data::Node::Decl::Namespace_T with_name(lang::data::Node::Id_T name);
        lang::data::Node::Decl::Namespace_T with_body(Vec_T<lang::data::Node::Decl_T> body);
        void hash_ser_acc_lang_data_Node_Decl_Namespace(SerBuf& buf) const;
        virtual void hash_ser_acc(SerBuf& buf) const;
    };
}

void pr_debug(ostream& os, FmtFlags flags, lang::data::Node::Decl::Data_T x);

namespace lang::data::Node::Decl::Data {
    __attribute__((always_inline)) lang::data::Node::Decl::Data_T make(Int id, lang_rt::TokenBounds bounds, bool is_top, lang_rt::ParserSymId sym, lang_rt::ParserAttrMask attr, lang_rt::ParserLookahead first_k, lang::data::Node::SumId_T name, Option_T<lang::data::Node::SumId_T> base, Option_T<Vec_T<lang::data::Node::Param_T>> params, Vec_T<lang::data::Node::Mod_T> mods, Vec_T<lang::data::Node::Field_T> fields);
}

namespace lang::data::Node::Decl::Data {
    __attribute__((always_inline)) lang::data::Node::Decl::Data_T make_ext(ArenaPtr arena, Int id, lang_rt::TokenBounds bounds, bool is_top, lang_rt::ParserSymId sym, lang_rt::ParserAttrMask attr, lang_rt::ParserLookahead first_k, lang::data::Node::SumId_T name, Option_T<lang::data::Node::SumId_T> base, Option_T<Vec_T<lang::data::Node::Param_T>> params, Vec_T<lang::data::Node::Mod_T> mods, Vec_T<lang::data::Node::Field_T> fields);
}

namespace lang::data::Node::Decl::Data {
    struct _T: lang::data::Node::Decl::_T {
        void write(ostream& os, FmtFlags flags);
        lang::data::Node::SumId_T name_;
        Option_T<lang::data::Node::SumId_T> base_;
        Option_T<Vec_T<lang::data::Node::Param_T>> params_;
        Vec_T<lang::data::Node::Mod_T> mods_;
        Vec_T<lang::data::Node::Field_T> fields_;
        _T();
        lang::data::Node::Decl::Data_T with_id(Int id);
        lang::data::Node::Decl::Data_T with_bounds(lang_rt::TokenBounds bounds);
        lang::data::Node::Decl::Data_T with_is_top(bool is_top);
        lang::data::Node::Decl::Data_T with_sym(lang_rt::ParserSymId sym);
        lang::data::Node::Decl::Data_T with_attr(lang_rt::ParserAttrMask attr);
        lang::data::Node::Decl::Data_T with_first_k(lang_rt::ParserLookahead first_k);
        lang::data::Node::Decl::Data_T with_name(lang::data::Node::SumId_T name);
        lang::data::Node::Decl::Data_T with_base(Option_T<lang::data::Node::SumId_T> base);
        lang::data::Node::Decl::Data_T with_params(Option_T<Vec_T<lang::data::Node::Param_T>> params);
        lang::data::Node::Decl::Data_T with_mods(Vec_T<lang::data::Node::Mod_T> mods);
        lang::data::Node::Decl::Data_T with_fields(Vec_T<lang::data::Node::Field_T> fields);
        void hash_ser_acc_lang_data_Node_Decl_Data(SerBuf& buf) const;
        virtual void hash_ser_acc(SerBuf& buf) const;
    };
}

void pr_debug(ostream& os, FmtFlags flags, lang::data::Node::Decl::Enum_T x);

namespace lang::data::Node::Decl::Enum {
    __attribute__((always_inline)) lang::data::Node::Decl::Enum_T make(Int id, lang_rt::TokenBounds bounds, bool is_top, lang_rt::ParserSymId sym, lang_rt::ParserAttrMask attr, lang_rt::ParserLookahead first_k, lang::data::Node::Id_T name, Vec_T<StrSlice> cases);
}

namespace lang::data::Node::Decl::Enum {
    __attribute__((always_inline)) lang::data::Node::Decl::Enum_T make_ext(ArenaPtr arena, Int id, lang_rt::TokenBounds bounds, bool is_top, lang_rt::ParserSymId sym, lang_rt::ParserAttrMask attr, lang_rt::ParserLookahead first_k, lang::data::Node::Id_T name, Vec_T<StrSlice> cases);
}

namespace lang::data::Node::Decl::Enum {
    struct _T: lang::data::Node::Decl::_T {
        void write(ostream& os, FmtFlags flags);
        lang::data::Node::Id_T name_;
        Vec_T<StrSlice> cases_;
        _T();
        lang::data::Node::Decl::Enum_T with_id(Int id);
        lang::data::Node::Decl::Enum_T with_bounds(lang_rt::TokenBounds bounds);
        lang::data::Node::Decl::Enum_T with_is_top(bool is_top);
        lang::data::Node::Decl::Enum_T with_sym(lang_rt::ParserSymId sym);
        lang::data::Node::Decl::Enum_T with_attr(lang_rt::ParserAttrMask attr);
        lang::data::Node::Decl::Enum_T with_first_k(lang_rt::ParserLookahead first_k);
        lang::data::Node::Decl::Enum_T with_name(lang::data::Node::Id_T name);
        lang::data::Node::Decl::Enum_T with_cases(Vec_T<StrSlice> cases);
        void hash_ser_acc_lang_data_Node_Decl_Enum(SerBuf& buf) const;
        virtual void hash_ser_acc(SerBuf& buf) const;
    };
}

void pr_debug(ostream& os, FmtFlags flags, lang::data::Node::Mod::Mut_T x);

namespace lang::data::Node::Mod::Mut {
    __attribute__((always_inline)) lang::data::Node::Mod::Mut_T make(Int id, lang_rt::TokenBounds bounds, bool is_top, lang_rt::ParserSymId sym, lang_rt::ParserAttrMask attr, lang_rt::ParserLookahead first_k);
}

namespace lang::data::Node::Mod::Mut {
    __attribute__((always_inline)) lang::data::Node::Mod::Mut_T make_ext(ArenaPtr arena, Int id, lang_rt::TokenBounds bounds, bool is_top, lang_rt::ParserSymId sym, lang_rt::ParserAttrMask attr, lang_rt::ParserLookahead first_k);
}

namespace lang::data::Node::Mod::Mut {
    struct _T: lang::data::Node::Mod::_T {
        void write(ostream& os, FmtFlags flags);
        _T();
        lang::data::Node::Mod::Mut_T with_id(Int id);
        lang::data::Node::Mod::Mut_T with_bounds(lang_rt::TokenBounds bounds);
        lang::data::Node::Mod::Mut_T with_is_top(bool is_top);
        lang::data::Node::Mod::Mut_T with_sym(lang_rt::ParserSymId sym);
        lang::data::Node::Mod::Mut_T with_attr(lang_rt::ParserAttrMask attr);
        lang::data::Node::Mod::Mut_T with_first_k(lang_rt::ParserLookahead first_k);
        void hash_ser_acc_lang_data_Node_Mod_Mut(SerBuf& buf) const;
        virtual void hash_ser_acc(SerBuf& buf) const;
    };
}

void pr_debug(ostream& os, FmtFlags flags, lang::data::Node::Mod::Xform_T x);

namespace lang::data::Node::Mod::Xform {
    __attribute__((always_inline)) lang::data::Node::Mod::Xform_T make(Int id, lang_rt::TokenBounds bounds, bool is_top, lang_rt::ParserSymId sym, lang_rt::ParserAttrMask attr, lang_rt::ParserLookahead first_k);
}

namespace lang::data::Node::Mod::Xform {
    __attribute__((always_inline)) lang::data::Node::Mod::Xform_T make_ext(ArenaPtr arena, Int id, lang_rt::TokenBounds bounds, bool is_top, lang_rt::ParserSymId sym, lang_rt::ParserAttrMask attr, lang_rt::ParserLookahead first_k);
}

namespace lang::data::Node::Mod::Xform {
    struct _T: lang::data::Node::Mod::_T {
        void write(ostream& os, FmtFlags flags);
        _T();
        lang::data::Node::Mod::Xform_T with_id(Int id);
        lang::data::Node::Mod::Xform_T with_bounds(lang_rt::TokenBounds bounds);
        lang::data::Node::Mod::Xform_T with_is_top(bool is_top);
        lang::data::Node::Mod::Xform_T with_sym(lang_rt::ParserSymId sym);
        lang::data::Node::Mod::Xform_T with_attr(lang_rt::ParserAttrMask attr);
        lang::data::Node::Mod::Xform_T with_first_k(lang_rt::ParserLookahead first_k);
        void hash_ser_acc_lang_data_Node_Mod_Xform(SerBuf& buf) const;
        virtual void hash_ser_acc(SerBuf& buf) const;
    };
}

void pr_debug(ostream& os, FmtFlags flags, lang::data::Node::Mod::Visit_T x);

namespace lang::data::Node::Mod::Visit {
    __attribute__((always_inline)) lang::data::Node::Mod::Visit_T make(Int id, lang_rt::TokenBounds bounds, bool is_top, lang_rt::ParserSymId sym, lang_rt::ParserAttrMask attr, lang_rt::ParserLookahead first_k);
}

namespace lang::data::Node::Mod::Visit {
    __attribute__((always_inline)) lang::data::Node::Mod::Visit_T make_ext(ArenaPtr arena, Int id, lang_rt::TokenBounds bounds, bool is_top, lang_rt::ParserSymId sym, lang_rt::ParserAttrMask attr, lang_rt::ParserLookahead first_k);
}

namespace lang::data::Node::Mod::Visit {
    struct _T: lang::data::Node::Mod::_T {
        void write(ostream& os, FmtFlags flags);
        _T();
        lang::data::Node::Mod::Visit_T with_id(Int id);
        lang::data::Node::Mod::Visit_T with_bounds(lang_rt::TokenBounds bounds);
        lang::data::Node::Mod::Visit_T with_is_top(bool is_top);
        lang::data::Node::Mod::Visit_T with_sym(lang_rt::ParserSymId sym);
        lang::data::Node::Mod::Visit_T with_attr(lang_rt::ParserAttrMask attr);
        lang::data::Node::Mod::Visit_T with_first_k(lang_rt::ParserLookahead first_k);
        void hash_ser_acc_lang_data_Node_Mod_Visit(SerBuf& buf) const;
        virtual void hash_ser_acc(SerBuf& buf) const;
    };
}

void pr_debug(ostream& os, FmtFlags flags, lang::data::Node::Expr::Id_T x);

namespace lang::data::Node::Expr::Id {
    __attribute__((always_inline)) lang::data::Node::Expr::Id_T make(Int id, lang_rt::TokenBounds bounds, bool is_top, lang_rt::ParserSymId sym, lang_rt::ParserAttrMask attr, lang_rt::ParserLookahead first_k, bool ext, lang::data::Node::Id_T x);
}

namespace lang::data::Node::Expr::Id {
    __attribute__((always_inline)) lang::data::Node::Expr::Id_T make_ext(ArenaPtr arena, Int id, lang_rt::TokenBounds bounds, bool is_top, lang_rt::ParserSymId sym, lang_rt::ParserAttrMask attr, lang_rt::ParserLookahead first_k, bool ext, lang::data::Node::Id_T x);
}

namespace lang::data::Node::Expr::Id {
    struct _T: lang::data::Node::Expr::_T {
        void write(ostream& os, FmtFlags flags);
        bool ext_;
        lang::data::Node::Id_T x_;
        _T();
        lang::data::Node::Expr::Id_T with_id(Int id);
        lang::data::Node::Expr::Id_T with_bounds(lang_rt::TokenBounds bounds);
        lang::data::Node::Expr::Id_T with_is_top(bool is_top);
        lang::data::Node::Expr::Id_T with_sym(lang_rt::ParserSymId sym);
        lang::data::Node::Expr::Id_T with_attr(lang_rt::ParserAttrMask attr);
        lang::data::Node::Expr::Id_T with_first_k(lang_rt::ParserLookahead first_k);
        lang::data::Node::Expr::Id_T with_ext(bool ext);
        lang::data::Node::Expr::Id_T with_x(lang::data::Node::Id_T x);
        void hash_ser_acc_lang_data_Node_Expr_Id(SerBuf& buf) const;
        virtual void hash_ser_acc(SerBuf& buf) const;
    };
}

void pr_debug(ostream& os, FmtFlags flags, lang::data::Node::Expr::App_T x);

namespace lang::data::Node::Expr::App {
    __attribute__((always_inline)) lang::data::Node::Expr::App_T make(Int id, lang_rt::TokenBounds bounds, bool is_top, lang_rt::ParserSymId sym, lang_rt::ParserAttrMask attr, lang_rt::ParserLookahead first_k, lang::data::Node::Expr_T f, Vec_T<lang::data::Node::Expr_T> args);
}

namespace lang::data::Node::Expr::App {
    __attribute__((always_inline)) lang::data::Node::Expr::App_T make_ext(ArenaPtr arena, Int id, lang_rt::TokenBounds bounds, bool is_top, lang_rt::ParserSymId sym, lang_rt::ParserAttrMask attr, lang_rt::ParserLookahead first_k, lang::data::Node::Expr_T f, Vec_T<lang::data::Node::Expr_T> args);
}

namespace lang::data::Node::Expr::App {
    struct _T: lang::data::Node::Expr::_T {
        void write(ostream& os, FmtFlags flags);
        lang::data::Node::Expr_T f_;
        Vec_T<lang::data::Node::Expr_T> args_;
        _T();
        lang::data::Node::Expr::App_T with_id(Int id);
        lang::data::Node::Expr::App_T with_bounds(lang_rt::TokenBounds bounds);
        lang::data::Node::Expr::App_T with_is_top(bool is_top);
        lang::data::Node::Expr::App_T with_sym(lang_rt::ParserSymId sym);
        lang::data::Node::Expr::App_T with_attr(lang_rt::ParserAttrMask attr);
        lang::data::Node::Expr::App_T with_first_k(lang_rt::ParserLookahead first_k);
        lang::data::Node::Expr::App_T with_f(lang::data::Node::Expr_T f);
        lang::data::Node::Expr::App_T with_args(Vec_T<lang::data::Node::Expr_T> args);
        void hash_ser_acc_lang_data_Node_Expr_App(SerBuf& buf) const;
        virtual void hash_ser_acc(SerBuf& buf) const;
    };
}

void pr_debug(ostream& os, FmtFlags flags, lang::data::Node::Expr::Type__T x);

namespace lang::data::Node::Expr::Type_ {
    __attribute__((always_inline)) lang::data::Node::Expr::Type__T make(Int id, lang_rt::TokenBounds bounds, bool is_top, lang_rt::ParserSymId sym, lang_rt::ParserAttrMask attr, lang_rt::ParserLookahead first_k);
}

namespace lang::data::Node::Expr::Type_ {
    __attribute__((always_inline)) lang::data::Node::Expr::Type__T make_ext(ArenaPtr arena, Int id, lang_rt::TokenBounds bounds, bool is_top, lang_rt::ParserSymId sym, lang_rt::ParserAttrMask attr, lang_rt::ParserLookahead first_k);
}

namespace lang::data::Node::Expr::Type_ {
    struct _T: lang::data::Node::Expr::_T {
        void write(ostream& os, FmtFlags flags);
        _T();
        lang::data::Node::Expr::Type__T with_id(Int id);
        lang::data::Node::Expr::Type__T with_bounds(lang_rt::TokenBounds bounds);
        lang::data::Node::Expr::Type__T with_is_top(bool is_top);
        lang::data::Node::Expr::Type__T with_sym(lang_rt::ParserSymId sym);
        lang::data::Node::Expr::Type__T with_attr(lang_rt::ParserAttrMask attr);
        lang::data::Node::Expr::Type__T with_first_k(lang_rt::ParserLookahead first_k);
        void hash_ser_acc_lang_data_Node_Expr_Type_(SerBuf& buf) const;
        virtual void hash_ser_acc(SerBuf& buf) const;
    };
}

void visit_lang_data_Node(lang::data::Node::Decl::Include_T x, function<void(lang::data::Node_T)> f);

void visit_lang_data_Node(lang::data::Node::Id_T x, function<void(lang::data::Node_T)> f);

void visit_lang_data_Node(lang::data::Node::Decl::Namespace_T x, function<void(lang::data::Node_T)> f);

void visit_lang_data_Node(lang::data::Node::SumId_T x, function<void(lang::data::Node_T)> f);

void visit_lang_data_Node(lang::data::Node::Expr::Id_T x, function<void(lang::data::Node_T)> f);

void visit_lang_data_Node(lang::data::Node::Expr::App_T x, function<void(lang::data::Node_T)> f);

void visit_lang_data_Node(lang::data::Node::Expr::Type__T x, function<void(lang::data::Node_T)> f);

void visit_lang_data_Node(lang::data::Node::Expr_T x, function<void(lang::data::Node_T)> f);

void visit_lang_data_Node(lang::data::Node::Param_T x, function<void(lang::data::Node_T)> f);

void visit_lang_data_Node(lang::data::Node::Mod::Mut_T x, function<void(lang::data::Node_T)> f);

void visit_lang_data_Node(lang::data::Node::Mod::Xform_T x, function<void(lang::data::Node_T)> f);

void visit_lang_data_Node(lang::data::Node::Mod::Visit_T x, function<void(lang::data::Node_T)> f);

void visit_lang_data_Node(lang::data::Node::Mod_T x, function<void(lang::data::Node_T)> f);

void visit_lang_data_Node(lang::data::Node::Field_T x, function<void(lang::data::Node_T)> f);

void visit_lang_data_Node(lang::data::Node::Decl::Data_T x, function<void(lang::data::Node_T)> f);

void visit_lang_data_Node(lang::data::Node::Decl::Enum_T x, function<void(lang::data::Node_T)> f);

void visit_lang_data_Node(lang::data::Node::Decl_T x, function<void(lang::data::Node_T)> f);

void visit_lang_data_Node(lang::data::Node::Module_T x, function<void(lang::data::Node_T)> f);

void visit_lang_data_Node(lang::data::Node_T x, function<void(lang::data::Node_T)> f);

lang::data::Node_T xformT_lang_data_Node(lang::data::Node::Decl::Include_T x, function<lang::data::Node_T(lang::data::Node_T)> f);

lang::data::Node_T xformT_lang_data_Node(lang::data::Node::Id_T x, function<lang::data::Node_T(lang::data::Node_T)> f);

lang::data::Node_T xformT_lang_data_Node(lang::data::Node::Decl::Namespace_T x, function<lang::data::Node_T(lang::data::Node_T)> f);

lang::data::Node_T xformT_lang_data_Node(lang::data::Node::SumId_T x, function<lang::data::Node_T(lang::data::Node_T)> f);

lang::data::Node_T xformT_lang_data_Node(lang::data::Node::Expr::Id_T x, function<lang::data::Node_T(lang::data::Node_T)> f);

lang::data::Node_T xformT_lang_data_Node(lang::data::Node::Expr::App_T x, function<lang::data::Node_T(lang::data::Node_T)> f);

lang::data::Node_T xformT_lang_data_Node(lang::data::Node::Expr::Type__T x, function<lang::data::Node_T(lang::data::Node_T)> f);

lang::data::Node_T xformT_lang_data_Node(lang::data::Node::Expr_T x, function<lang::data::Node_T(lang::data::Node_T)> f);

lang::data::Node_T xformT_lang_data_Node(lang::data::Node::Param_T x, function<lang::data::Node_T(lang::data::Node_T)> f);

lang::data::Node_T xformT_lang_data_Node(lang::data::Node::Mod::Mut_T x, function<lang::data::Node_T(lang::data::Node_T)> f);

lang::data::Node_T xformT_lang_data_Node(lang::data::Node::Mod::Xform_T x, function<lang::data::Node_T(lang::data::Node_T)> f);

lang::data::Node_T xformT_lang_data_Node(lang::data::Node::Mod::Visit_T x, function<lang::data::Node_T(lang::data::Node_T)> f);

lang::data::Node_T xformT_lang_data_Node(lang::data::Node::Mod_T x, function<lang::data::Node_T(lang::data::Node_T)> f);

lang::data::Node_T xformT_lang_data_Node(lang::data::Node::Field_T x, function<lang::data::Node_T(lang::data::Node_T)> f);

lang::data::Node_T xformT_lang_data_Node(lang::data::Node::Decl::Data_T x, function<lang::data::Node_T(lang::data::Node_T)> f);

lang::data::Node_T xformT_lang_data_Node(lang::data::Node::Decl::Enum_T x, function<lang::data::Node_T(lang::data::Node_T)> f);

lang::data::Node_T xformT_lang_data_Node(lang::data::Node::Decl_T x, function<lang::data::Node_T(lang::data::Node_T)> f);

lang::data::Node_T xformT_lang_data_Node(lang::data::Node::Module_T x, function<lang::data::Node_T(lang::data::Node_T)> f);

lang::data::Node_T xformT_lang_data_Node(lang::data::Node_T x, function<lang::data::Node_T(lang::data::Node_T)> f);

lang::data::Node_T xform_lang_data_Node(lang::data::Node_T x, function<lang::data::Node_T(lang::data::Node_T)> f);

lang::data::Node::Module_T xform_lang_data_Node(lang::data::Node::Module_T x, function<lang::data::Node_T(lang::data::Node_T)> f);

lang::data::Node::Decl_T xform_lang_data_Node(lang::data::Node::Decl_T x, function<lang::data::Node_T(lang::data::Node_T)> f);

lang::data::Node::Decl::Include_T xform_lang_data_Node(lang::data::Node::Decl::Include_T x, function<lang::data::Node_T(lang::data::Node_T)> f);

lang::data::Node::Decl::Namespace_T xform_lang_data_Node(lang::data::Node::Decl::Namespace_T x, function<lang::data::Node_T(lang::data::Node_T)> f);

lang::data::Node::Id_T xform_lang_data_Node(lang::data::Node::Id_T x, function<lang::data::Node_T(lang::data::Node_T)> f);

lang::data::Node::Decl::Data_T xform_lang_data_Node(lang::data::Node::Decl::Data_T x, function<lang::data::Node_T(lang::data::Node_T)> f);

lang::data::Node::SumId_T xform_lang_data_Node(lang::data::Node::SumId_T x, function<lang::data::Node_T(lang::data::Node_T)> f);

lang::data::Node::Param_T xform_lang_data_Node(lang::data::Node::Param_T x, function<lang::data::Node_T(lang::data::Node_T)> f);

lang::data::Node::Expr_T xform_lang_data_Node(lang::data::Node::Expr_T x, function<lang::data::Node_T(lang::data::Node_T)> f);

lang::data::Node::Expr::Id_T xform_lang_data_Node(lang::data::Node::Expr::Id_T x, function<lang::data::Node_T(lang::data::Node_T)> f);

lang::data::Node::Expr::App_T xform_lang_data_Node(lang::data::Node::Expr::App_T x, function<lang::data::Node_T(lang::data::Node_T)> f);

lang::data::Node::Expr::Type__T xform_lang_data_Node(lang::data::Node::Expr::Type__T x, function<lang::data::Node_T(lang::data::Node_T)> f);

lang::data::Node::Mod_T xform_lang_data_Node(lang::data::Node::Mod_T x, function<lang::data::Node_T(lang::data::Node_T)> f);

lang::data::Node::Mod::Mut_T xform_lang_data_Node(lang::data::Node::Mod::Mut_T x, function<lang::data::Node_T(lang::data::Node_T)> f);

lang::data::Node::Mod::Xform_T xform_lang_data_Node(lang::data::Node::Mod::Xform_T x, function<lang::data::Node_T(lang::data::Node_T)> f);

lang::data::Node::Mod::Visit_T xform_lang_data_Node(lang::data::Node::Mod::Visit_T x, function<lang::data::Node_T(lang::data::Node_T)> f);

lang::data::Node::Field_T xform_lang_data_Node(lang::data::Node::Field_T x, function<lang::data::Node_T(lang::data::Node_T)> f);

lang::data::Node::Decl::Enum_T xform_lang_data_Node(lang::data::Node::Decl::Enum_T x, function<lang::data::Node_T(lang::data::Node_T)> f);

namespace lang::data::parser {
    __attribute__((always_inline)) IntPair action_by_vertex(lang_rt::ParserVertexId v, lang_rt::ParserLookahead la);
}

namespace lang::data::parser {
    __attribute__((always_inline)) lang_rt::ParserVertexId vertex_dfa_step(lang_rt::ParserVertexId v, lang_rt::ParserSymId sym, lang_rt::ParserAttrMask attr);
}

namespace lang::data::parser {
    lang_rt::ParserProcXforms proc_xform_by_prod_id();
}

namespace lang::data::parser {
    lang_rt::ParserSymByName start_marker_by_name();
}

namespace lang::data::parser {
    lang_rt::ParserSymId term_tok_to_sym(lang_rt::TokenId tok);
}

namespace lang::data::parser {
    lang_rt::ParserSymId sym_to_recur_step(lang_rt::ParserSymId sym);
}

namespace lang::data::parser {
    string sym_to_debug_string(lang_rt::ParserSymId sym);
}

namespace lang::data::parser {
    Int sym_to_num_attrs(lang_rt::ParserSymId sym);
}

namespace lang::data::parser {
    string attr_to_debug_string(lang_rt::ParserSymId sym, Int attr_ind);
}

namespace lang::data {
    using LangDesc = lang_rt::LangDesc<Node::_T, parser::action_by_vertex, parser::vertex_dfa_step>;
}

namespace lang::data {
    using LangDesc_T = lang_rt::LangDesc_T<Node::_T, parser::action_by_vertex, parser::vertex_dfa_step>;
}

namespace lang::data {
    using QuoteEnv = lang_rt::QuoteEnv<Node::_T, parser::action_by_vertex, parser::vertex_dfa_step>;
}

namespace lang::data {
    using QuoteEnv_T = lang_rt::QuoteEnv_T<Node::_T, parser::action_by_vertex, parser::vertex_dfa_step>;
}

namespace lang::data {
    lang::data::LangDesc_T init();
}

namespace lang::data::lexer::body {
    inline __attribute__((always_inline)) Int proc_mode_loop_opt(ptr<lang_rt::LexerModeDesc> mode, ptr<lang_rt::LexerState> st, ptr<lang_rt::SymItemVec> emit_dst, Int mode_start_pos, Int mode_buf_pos);
}

namespace lang::data::lexer::comment_single {
    inline __attribute__((always_inline)) Int proc_mode_loop_opt(ptr<lang_rt::LexerModeDesc> mode, ptr<lang_rt::LexerState> st, ptr<lang_rt::SymItemVec> emit_dst, Int mode_start_pos, Int mode_buf_pos);
}
