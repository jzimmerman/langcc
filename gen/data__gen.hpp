#pragma once

#include <langcc_rt.hpp>

namespace lang::data::lexer {
    langcc::rc_ptr<langcc::DFALabelIdVec> label_ids_ascii();

    langcc::rc_ptr<langcc::DFALabelIdMap> label_ids_unicode();
}

namespace lang::data::lexer::body {
    langcc::DFAVertexId step(langcc::DFAVertexId v, langcc::DFALabelId lbl);

    __attribute__((always_inline)) langcc::DFAActionWithToken acc(langcc::DFAVertexId v);

    __attribute__((always_inline)) langcc::IntPair step_exec(langcc::Ptr<langcc::LexerState> st, langcc::Ptr<langcc::SymItemVec> emit_dst, langcc::Ptr<langcc::LexWhitespaceState> ws_state, langcc::DFAActionId acc, langcc::TokenId tok, langcc::Int& in_i, langcc::Int& tok_lo, langcc::Int& tok_hi);

    langcc::Int proc_mode_loop(langcc::Ptr<langcc::LexerState> st, langcc::Ptr<langcc::SymItemVec> emit_dst, langcc::Int mode_start_pos, langcc::Int mode_buf_pos);
}

namespace lang::data::lexer::comment_single {
    langcc::DFAVertexId step(langcc::DFAVertexId v, langcc::DFALabelId lbl);

    __attribute__((always_inline)) langcc::DFAActionWithToken acc(langcc::DFAVertexId v);

    __attribute__((always_inline)) langcc::IntPair step_exec(langcc::Ptr<langcc::LexerState> st, langcc::Ptr<langcc::SymItemVec> emit_dst, langcc::Ptr<langcc::LexWhitespaceState> ws_state, langcc::DFAActionId acc, langcc::TokenId tok, langcc::Int& in_i, langcc::Int& tok_lo, langcc::Int& tok_hi);

    langcc::Int proc_mode_loop(langcc::Ptr<langcc::LexerState> st, langcc::Ptr<langcc::SymItemVec> emit_dst, langcc::Int mode_start_pos, langcc::Int mode_buf_pos);
}

#pragma once

#include <langcc_util.hpp>

namespace lang::data::Node::Module {
    struct _T;
}

namespace lang::data::Node {
    using Module_T = langcc::rc_ptr<lang::data::Node::Module::_T>;
}

namespace lang::data::Node::Decl::Include {
    struct _T;
}

namespace lang::data::Node::Decl {
    using Include_T = langcc::rc_ptr<lang::data::Node::Decl::Include::_T>;
}

namespace lang::data::Node::Decl::Namespace {
    struct _T;
}

namespace lang::data::Node::Decl {
    using Namespace_T = langcc::rc_ptr<lang::data::Node::Decl::Namespace::_T>;
}

namespace lang::data::Node::Decl::Data {
    struct _T;
}

namespace lang::data::Node::Decl {
    using Data_T = langcc::rc_ptr<lang::data::Node::Decl::Data::_T>;
}

namespace lang::data::Node::Decl::Enum {
    struct _T;
}

namespace lang::data::Node::Decl {
    using Enum_T = langcc::rc_ptr<lang::data::Node::Decl::Enum::_T>;
}

namespace lang::data::Node::Mod::Mut {
    struct _T;
}

namespace lang::data::Node::Mod {
    using Mut_T = langcc::rc_ptr<lang::data::Node::Mod::Mut::_T>;
}

namespace lang::data::Node::Mod::Xform {
    struct _T;
}

namespace lang::data::Node::Mod {
    using Xform_T = langcc::rc_ptr<lang::data::Node::Mod::Xform::_T>;
}

namespace lang::data::Node::Mod::Visit {
    struct _T;
}

namespace lang::data::Node::Mod {
    using Visit_T = langcc::rc_ptr<lang::data::Node::Mod::Visit::_T>;
}

namespace lang::data::Node::Param {
    struct _T;
}

namespace lang::data::Node {
    using Param_T = langcc::rc_ptr<lang::data::Node::Param::_T>;
}

namespace lang::data::Node::Entry::Field {
    struct _T;
}

namespace lang::data::Node::Entry {
    using Field_T = langcc::rc_ptr<lang::data::Node::Entry::Field::_T>;
}

namespace lang::data::Node::Entry::Method {
    struct _T;
}

namespace lang::data::Node::Entry {
    using Method_T = langcc::rc_ptr<lang::data::Node::Entry::Method::_T>;
}

namespace lang::data::Node::Expr::Id {
    struct _T;
}

namespace lang::data::Node::Expr {
    using Id_T = langcc::rc_ptr<lang::data::Node::Expr::Id::_T>;
}

namespace lang::data::Node::Expr::App {
    struct _T;
}

namespace lang::data::Node::Expr {
    using App_T = langcc::rc_ptr<lang::data::Node::Expr::App::_T>;
}

namespace lang::data::Node::Expr::Type_ {
    struct _T;
}

namespace lang::data::Node::Expr {
    using Type__T = langcc::rc_ptr<lang::data::Node::Expr::Type_::_T>;
}

namespace lang::data::Node::SumId {
    struct _T;
}

namespace lang::data::Node {
    using SumId_T = langcc::rc_ptr<lang::data::Node::SumId::_T>;
}

namespace lang::data::Node::Id {
    struct _T;
}

namespace lang::data::Node {
    using Id_T = langcc::rc_ptr<lang::data::Node::Id::_T>;
}

namespace lang::data::Node::Decl {
    struct _T;
}

namespace lang::data::Node {
    using Decl_T = langcc::rc_ptr<lang::data::Node::Decl::_T>;
}

namespace lang::data::Node::Mod {
    struct _T;
}

namespace lang::data::Node {
    using Mod_T = langcc::rc_ptr<lang::data::Node::Mod::_T>;
}

namespace lang::data::Node::Entry {
    struct _T;
}

namespace lang::data::Node {
    using Entry_T = langcc::rc_ptr<lang::data::Node::Entry::_T>;
}

namespace lang::data::Node::Expr {
    struct _T;
}

namespace lang::data::Node {
    using Expr_T = langcc::rc_ptr<lang::data::Node::Expr::_T>;
}

namespace lang::data::Node {
    struct _T;
}

namespace lang::data {
    using Node_T = langcc::rc_ptr<lang::data::Node::_T>;
}

namespace langcc {
    void pr_debug(ostream& os, FmtFlags flags, lang::data::Node_T x);
}

namespace lang::data::Node {
    enum struct _W {
        Module,
        Param,
        SumId,
        Id,
        Decl,
        Mod,
        Entry,
        Expr,
    };
}

namespace lang::data::Node {
    struct _T: langcc::hash_obj, langcc::enable_rc_from_this_poly {
        void write(langcc::Ref<std::ostream> os, langcc::FmtFlags flags);
        void write(langcc::Ref<langcc::PrBufStream_T> pb);
        lang::data::Node::_W w_;
        virtual ~_T();
        langcc::Int id_;
        langcc::TokenBounds bounds_;
        bool is_top_;
        langcc::ParserSymId sym_;
        langcc::ParserAttrMask attr_;
        langcc::ParserLookahead first_k_;
        _T(lang::data::Node::_W w);
        bool is_Module();
        bool is_Param();
        bool is_SumId();
        bool is_Id();
        bool is_Decl();
        bool is_Mod();
        bool is_Entry();
        bool is_Expr();
        lang::data::Node::Module_T as_Module();
        lang::data::Node::Param_T as_Param();
        lang::data::Node::SumId_T as_SumId();
        lang::data::Node::Id_T as_Id();
        lang::data::Node::Decl_T as_Decl();
        lang::data::Node::Mod_T as_Mod();
        lang::data::Node::Entry_T as_Entry();
        lang::data::Node::Expr_T as_Expr();
        void match(std::function<void(lang::data::Node::Module_T)> f_Module, std::function<void(lang::data::Node::Param_T)> f_Param, std::function<void(lang::data::Node::SumId_T)> f_SumId, std::function<void(lang::data::Node::Id_T)> f_Id, std::function<void(lang::data::Node::Decl_T)> f_Decl, std::function<void(lang::data::Node::Mod_T)> f_Mod, std::function<void(lang::data::Node::Entry_T)> f_Entry, std::function<void(lang::data::Node::Expr_T)> f_Expr);
        template<typename RetT> RetT match_expr(std::function<RetT(lang::data::Node::Module_T)> f_Module, std::function<RetT(lang::data::Node::Param_T)> f_Param, std::function<RetT(lang::data::Node::SumId_T)> f_SumId, std::function<RetT(lang::data::Node::Id_T)> f_Id, std::function<RetT(lang::data::Node::Decl_T)> f_Decl, std::function<RetT(lang::data::Node::Mod_T)> f_Mod, std::function<RetT(lang::data::Node::Entry_T)> f_Entry, std::function<RetT(lang::data::Node::Expr_T)> f_Expr);
        void hash_ser_acc_lang_data_Node(langcc::SerBuf& buf) const;
        virtual void hash_ser_acc(langcc::SerBuf& buf) const = 0;
    };
}

template<typename RetT> RetT lang::data::Node::_T::match_expr(std::function<RetT(lang::data::Node::Module_T)> f_Module, std::function<RetT(lang::data::Node::Param_T)> f_Param, std::function<RetT(lang::data::Node::SumId_T)> f_SumId, std::function<RetT(lang::data::Node::Id_T)> f_Id, std::function<RetT(lang::data::Node::Decl_T)> f_Decl, std::function<RetT(lang::data::Node::Mod_T)> f_Mod, std::function<RetT(lang::data::Node::Entry_T)> f_Entry, std::function<RetT(lang::data::Node::Expr_T)> f_Expr) {
    switch (this->w_) {
        case lang::data::Node::_W::Module: {
            return f_Module(this->as_Module());
            break;
        }
        case lang::data::Node::_W::Param: {
            return f_Param(this->as_Param());
            break;
        }
        case lang::data::Node::_W::SumId: {
            return f_SumId(this->as_SumId());
            break;
        }
        case lang::data::Node::_W::Id: {
            return f_Id(this->as_Id());
            break;
        }
        case lang::data::Node::_W::Decl: {
            return f_Decl(this->as_Decl());
            break;
        }
        case lang::data::Node::_W::Mod: {
            return f_Mod(this->as_Mod());
            break;
        }
        case lang::data::Node::_W::Entry: {
            return f_Entry(this->as_Entry());
            break;
        }
        case lang::data::Node::_W::Expr: {
            return f_Expr(this->as_Expr());
            break;
        }
        default: {
            langcc::AX();
        }
    }
}

namespace langcc {
    void pr_debug(ostream& os, FmtFlags flags, lang::data::Node::Module_T x);
}

namespace lang::data::Node::Module {
    lang::data::Node::Module_T make(langcc::Int id, langcc::TokenBounds bounds, bool is_top, langcc::ParserSymId sym, langcc::ParserAttrMask attr, langcc::ParserLookahead first_k, langcc::Vec_T<lang::data::Node::Decl_T> decls);
}

namespace lang::data::Node::Module {
    lang::data::Node::Module_T make_ext(langcc::ArenaPtr arena, langcc::Int id, langcc::TokenBounds bounds, bool is_top, langcc::ParserSymId sym, langcc::ParserAttrMask attr, langcc::ParserLookahead first_k, langcc::Vec_T<lang::data::Node::Decl_T> decls);
}

namespace lang::data::Node::Module {
    struct _T: lang::data::Node::_T {
        void write(langcc::Ref<std::ostream> os, langcc::FmtFlags flags);
        void write(langcc::Ref<langcc::PrBufStream_T> pb);
        langcc::Vec_T<lang::data::Node::Decl_T> decls_;
        _T();
        lang::data::Node::Module_T with_id(langcc::Int id);
        lang::data::Node::Module_T with_bounds(langcc::TokenBounds bounds);
        lang::data::Node::Module_T with_is_top(bool is_top);
        lang::data::Node::Module_T with_sym(langcc::ParserSymId sym);
        lang::data::Node::Module_T with_attr(langcc::ParserAttrMask attr);
        lang::data::Node::Module_T with_first_k(langcc::ParserLookahead first_k);
        lang::data::Node::Module_T with_decls(langcc::Vec_T<lang::data::Node::Decl_T> decls);
        void hash_ser_acc_lang_data_Node_Module(langcc::SerBuf& buf) const;
        virtual void hash_ser_acc(langcc::SerBuf& buf) const;
    };
}

namespace langcc {
    void pr_debug(ostream& os, FmtFlags flags, lang::data::Node::Param_T x);
}

namespace lang::data::Node::Param {
    lang::data::Node::Param_T make(langcc::Int id, langcc::TokenBounds bounds, bool is_top, langcc::ParserSymId sym, langcc::ParserAttrMask attr, langcc::ParserLookahead first_k, langcc::StrSlice name, lang::data::Node::Expr_T type_);
}

namespace lang::data::Node::Param {
    lang::data::Node::Param_T make_ext(langcc::ArenaPtr arena, langcc::Int id, langcc::TokenBounds bounds, bool is_top, langcc::ParserSymId sym, langcc::ParserAttrMask attr, langcc::ParserLookahead first_k, langcc::StrSlice name, lang::data::Node::Expr_T type_);
}

namespace lang::data::Node::Param {
    struct _T: lang::data::Node::_T {
        void write(langcc::Ref<std::ostream> os, langcc::FmtFlags flags);
        void write(langcc::Ref<langcc::PrBufStream_T> pb);
        langcc::StrSlice name_;
        lang::data::Node::Expr_T type__;
        _T();
        lang::data::Node::Param_T with_id(langcc::Int id);
        lang::data::Node::Param_T with_bounds(langcc::TokenBounds bounds);
        lang::data::Node::Param_T with_is_top(bool is_top);
        lang::data::Node::Param_T with_sym(langcc::ParserSymId sym);
        lang::data::Node::Param_T with_attr(langcc::ParserAttrMask attr);
        lang::data::Node::Param_T with_first_k(langcc::ParserLookahead first_k);
        lang::data::Node::Param_T with_name(langcc::StrSlice name);
        lang::data::Node::Param_T with_type_(lang::data::Node::Expr_T type_);
        void hash_ser_acc_lang_data_Node_Param(langcc::SerBuf& buf) const;
        virtual void hash_ser_acc(langcc::SerBuf& buf) const;
    };
}

namespace langcc {
    void pr_debug(ostream& os, FmtFlags flags, lang::data::Node::SumId_T x);
}

namespace lang::data::Node::SumId {
    lang::data::Node::SumId_T make(langcc::Int id, langcc::TokenBounds bounds, bool is_top, langcc::ParserSymId sym, langcc::ParserAttrMask attr, langcc::ParserLookahead first_k, langcc::Vec_T<langcc::StrSlice> items);
}

namespace lang::data::Node::SumId {
    lang::data::Node::SumId_T make_ext(langcc::ArenaPtr arena, langcc::Int id, langcc::TokenBounds bounds, bool is_top, langcc::ParserSymId sym, langcc::ParserAttrMask attr, langcc::ParserLookahead first_k, langcc::Vec_T<langcc::StrSlice> items);
}

namespace lang::data::Node::SumId {
    struct _T: lang::data::Node::_T {
        void write(langcc::Ref<std::ostream> os, langcc::FmtFlags flags);
        void write(langcc::Ref<langcc::PrBufStream_T> pb);
        langcc::Vec_T<langcc::StrSlice> items_;
        _T();
        lang::data::Node::SumId_T with_id(langcc::Int id);
        lang::data::Node::SumId_T with_bounds(langcc::TokenBounds bounds);
        lang::data::Node::SumId_T with_is_top(bool is_top);
        lang::data::Node::SumId_T with_sym(langcc::ParserSymId sym);
        lang::data::Node::SumId_T with_attr(langcc::ParserAttrMask attr);
        lang::data::Node::SumId_T with_first_k(langcc::ParserLookahead first_k);
        lang::data::Node::SumId_T with_items(langcc::Vec_T<langcc::StrSlice> items);
        void hash_ser_acc_lang_data_Node_SumId(langcc::SerBuf& buf) const;
        virtual void hash_ser_acc(langcc::SerBuf& buf) const;
    };
}

namespace langcc {
    void pr_debug(ostream& os, FmtFlags flags, lang::data::Node::Id_T x);
}

namespace lang::data::Node::Id {
    lang::data::Node::Id_T make(langcc::Int id, langcc::TokenBounds bounds, bool is_top, langcc::ParserSymId sym, langcc::ParserAttrMask attr, langcc::ParserLookahead first_k, langcc::Vec_T<langcc::StrSlice> items);
}

namespace lang::data::Node::Id {
    lang::data::Node::Id_T make_ext(langcc::ArenaPtr arena, langcc::Int id, langcc::TokenBounds bounds, bool is_top, langcc::ParserSymId sym, langcc::ParserAttrMask attr, langcc::ParserLookahead first_k, langcc::Vec_T<langcc::StrSlice> items);
}

namespace lang::data::Node::Id {
    struct _T: lang::data::Node::_T {
        void write(langcc::Ref<std::ostream> os, langcc::FmtFlags flags);
        void write(langcc::Ref<langcc::PrBufStream_T> pb);
        langcc::Vec_T<langcc::StrSlice> items_;
        _T();
        lang::data::Node::Id_T with_id(langcc::Int id);
        lang::data::Node::Id_T with_bounds(langcc::TokenBounds bounds);
        lang::data::Node::Id_T with_is_top(bool is_top);
        lang::data::Node::Id_T with_sym(langcc::ParserSymId sym);
        lang::data::Node::Id_T with_attr(langcc::ParserAttrMask attr);
        lang::data::Node::Id_T with_first_k(langcc::ParserLookahead first_k);
        lang::data::Node::Id_T with_items(langcc::Vec_T<langcc::StrSlice> items);
        void hash_ser_acc_lang_data_Node_Id(langcc::SerBuf& buf) const;
        virtual void hash_ser_acc(langcc::SerBuf& buf) const;
    };
}

namespace langcc {
    void pr_debug(ostream& os, FmtFlags flags, lang::data::Node::Decl_T x);
}

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
        void write(langcc::Ref<std::ostream> os, langcc::FmtFlags flags);
        void write(langcc::Ref<langcc::PrBufStream_T> pb);
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
        void match(std::function<void(lang::data::Node::Decl::Include_T)> f_Include, std::function<void(lang::data::Node::Decl::Namespace_T)> f_Namespace, std::function<void(lang::data::Node::Decl::Data_T)> f_Data, std::function<void(lang::data::Node::Decl::Enum_T)> f_Enum);
        template<typename RetT> RetT match_expr(std::function<RetT(lang::data::Node::Decl::Include_T)> f_Include, std::function<RetT(lang::data::Node::Decl::Namespace_T)> f_Namespace, std::function<RetT(lang::data::Node::Decl::Data_T)> f_Data, std::function<RetT(lang::data::Node::Decl::Enum_T)> f_Enum);
        void hash_ser_acc_lang_data_Node_Decl(langcc::SerBuf& buf) const;
        virtual void hash_ser_acc(langcc::SerBuf& buf) const = 0;
    };
}

template<typename RetT> RetT lang::data::Node::Decl::_T::match_expr(std::function<RetT(lang::data::Node::Decl::Include_T)> f_Include, std::function<RetT(lang::data::Node::Decl::Namespace_T)> f_Namespace, std::function<RetT(lang::data::Node::Decl::Data_T)> f_Data, std::function<RetT(lang::data::Node::Decl::Enum_T)> f_Enum) {
    switch (this->w_) {
        case lang::data::Node::Decl::_W::Include: {
            return f_Include(this->as_Include());
            break;
        }
        case lang::data::Node::Decl::_W::Namespace: {
            return f_Namespace(this->as_Namespace());
            break;
        }
        case lang::data::Node::Decl::_W::Data: {
            return f_Data(this->as_Data());
            break;
        }
        case lang::data::Node::Decl::_W::Enum: {
            return f_Enum(this->as_Enum());
            break;
        }
        default: {
            langcc::AX();
        }
    }
}

namespace langcc {
    void pr_debug(ostream& os, FmtFlags flags, lang::data::Node::Mod_T x);
}

namespace lang::data::Node::Mod {
    enum struct _W {
        Mut,
        Xform,
        Visit,
    };
}

namespace lang::data::Node::Mod {
    struct _T: lang::data::Node::_T {
        void write(langcc::Ref<std::ostream> os, langcc::FmtFlags flags);
        void write(langcc::Ref<langcc::PrBufStream_T> pb);
        lang::data::Node::Mod::_W w_;
        virtual ~_T();
        _T(lang::data::Node::Mod::_W w);
        bool is_Mut();
        bool is_Xform();
        bool is_Visit();
        lang::data::Node::Mod::Mut_T as_Mut();
        lang::data::Node::Mod::Xform_T as_Xform();
        lang::data::Node::Mod::Visit_T as_Visit();
        void match(std::function<void(lang::data::Node::Mod::Mut_T)> f_Mut, std::function<void(lang::data::Node::Mod::Xform_T)> f_Xform, std::function<void(lang::data::Node::Mod::Visit_T)> f_Visit);
        template<typename RetT> RetT match_expr(std::function<RetT(lang::data::Node::Mod::Mut_T)> f_Mut, std::function<RetT(lang::data::Node::Mod::Xform_T)> f_Xform, std::function<RetT(lang::data::Node::Mod::Visit_T)> f_Visit);
        void hash_ser_acc_lang_data_Node_Mod(langcc::SerBuf& buf) const;
        virtual void hash_ser_acc(langcc::SerBuf& buf) const = 0;
    };
}

template<typename RetT> RetT lang::data::Node::Mod::_T::match_expr(std::function<RetT(lang::data::Node::Mod::Mut_T)> f_Mut, std::function<RetT(lang::data::Node::Mod::Xform_T)> f_Xform, std::function<RetT(lang::data::Node::Mod::Visit_T)> f_Visit) {
    switch (this->w_) {
        case lang::data::Node::Mod::_W::Mut: {
            return f_Mut(this->as_Mut());
            break;
        }
        case lang::data::Node::Mod::_W::Xform: {
            return f_Xform(this->as_Xform());
            break;
        }
        case lang::data::Node::Mod::_W::Visit: {
            return f_Visit(this->as_Visit());
            break;
        }
        default: {
            langcc::AX();
        }
    }
}

namespace langcc {
    void pr_debug(ostream& os, FmtFlags flags, lang::data::Node::Entry_T x);
}

namespace lang::data::Node::Entry {
    enum struct _W {
        Field,
        Method,
    };
}

namespace lang::data::Node::Entry {
    struct _T: lang::data::Node::_T {
        void write(langcc::Ref<std::ostream> os, langcc::FmtFlags flags);
        void write(langcc::Ref<langcc::PrBufStream_T> pb);
        lang::data::Node::Entry::_W w_;
        virtual ~_T();
        _T(lang::data::Node::Entry::_W w);
        bool is_Field();
        bool is_Method();
        lang::data::Node::Entry::Field_T as_Field();
        lang::data::Node::Entry::Method_T as_Method();
        void match(std::function<void(lang::data::Node::Entry::Field_T)> f_Field, std::function<void(lang::data::Node::Entry::Method_T)> f_Method);
        template<typename RetT> RetT match_expr(std::function<RetT(lang::data::Node::Entry::Field_T)> f_Field, std::function<RetT(lang::data::Node::Entry::Method_T)> f_Method);
        void hash_ser_acc_lang_data_Node_Entry(langcc::SerBuf& buf) const;
        virtual void hash_ser_acc(langcc::SerBuf& buf) const = 0;
    };
}

template<typename RetT> RetT lang::data::Node::Entry::_T::match_expr(std::function<RetT(lang::data::Node::Entry::Field_T)> f_Field, std::function<RetT(lang::data::Node::Entry::Method_T)> f_Method) {
    switch (this->w_) {
        case lang::data::Node::Entry::_W::Field: {
            return f_Field(this->as_Field());
            break;
        }
        case lang::data::Node::Entry::_W::Method: {
            return f_Method(this->as_Method());
            break;
        }
        default: {
            langcc::AX();
        }
    }
}

namespace langcc {
    void pr_debug(ostream& os, FmtFlags flags, lang::data::Node::Expr_T x);
}

namespace lang::data::Node::Expr {
    enum struct _W {
        Id,
        App,
        Type_,
    };
}

namespace lang::data::Node::Expr {
    struct _T: lang::data::Node::_T {
        void write(langcc::Ref<std::ostream> os, langcc::FmtFlags flags);
        void write(langcc::Ref<langcc::PrBufStream_T> pb);
        lang::data::Node::Expr::_W w_;
        virtual ~_T();
        _T(lang::data::Node::Expr::_W w);
        bool is_Id();
        bool is_App();
        bool is_Type_();
        lang::data::Node::Expr::Id_T as_Id();
        lang::data::Node::Expr::App_T as_App();
        lang::data::Node::Expr::Type__T as_Type_();
        void match(std::function<void(lang::data::Node::Expr::Id_T)> f_Id, std::function<void(lang::data::Node::Expr::App_T)> f_App, std::function<void(lang::data::Node::Expr::Type__T)> f_Type_);
        template<typename RetT> RetT match_expr(std::function<RetT(lang::data::Node::Expr::Id_T)> f_Id, std::function<RetT(lang::data::Node::Expr::App_T)> f_App, std::function<RetT(lang::data::Node::Expr::Type__T)> f_Type_);
        void hash_ser_acc_lang_data_Node_Expr(langcc::SerBuf& buf) const;
        virtual void hash_ser_acc(langcc::SerBuf& buf) const = 0;
    };
}

template<typename RetT> RetT lang::data::Node::Expr::_T::match_expr(std::function<RetT(lang::data::Node::Expr::Id_T)> f_Id, std::function<RetT(lang::data::Node::Expr::App_T)> f_App, std::function<RetT(lang::data::Node::Expr::Type__T)> f_Type_) {
    switch (this->w_) {
        case lang::data::Node::Expr::_W::Id: {
            return f_Id(this->as_Id());
            break;
        }
        case lang::data::Node::Expr::_W::App: {
            return f_App(this->as_App());
            break;
        }
        case lang::data::Node::Expr::_W::Type_: {
            return f_Type_(this->as_Type_());
            break;
        }
        default: {
            langcc::AX();
        }
    }
}

namespace langcc {
    void pr_debug(ostream& os, FmtFlags flags, lang::data::Node::Decl::Include_T x);
}

namespace lang::data::Node::Decl::Include {
    lang::data::Node::Decl::Include_T make(langcc::Int id, langcc::TokenBounds bounds, bool is_top, langcc::ParserSymId sym, langcc::ParserAttrMask attr, langcc::ParserLookahead first_k, langcc::StrSlice path);
}

namespace lang::data::Node::Decl::Include {
    lang::data::Node::Decl::Include_T make_ext(langcc::ArenaPtr arena, langcc::Int id, langcc::TokenBounds bounds, bool is_top, langcc::ParserSymId sym, langcc::ParserAttrMask attr, langcc::ParserLookahead first_k, langcc::StrSlice path);
}

namespace lang::data::Node::Decl::Include {
    struct _T: lang::data::Node::Decl::_T {
        void write(langcc::Ref<std::ostream> os, langcc::FmtFlags flags);
        void write(langcc::Ref<langcc::PrBufStream_T> pb);
        langcc::StrSlice path_;
        _T();
        lang::data::Node::Decl::Include_T with_id(langcc::Int id);
        lang::data::Node::Decl::Include_T with_bounds(langcc::TokenBounds bounds);
        lang::data::Node::Decl::Include_T with_is_top(bool is_top);
        lang::data::Node::Decl::Include_T with_sym(langcc::ParserSymId sym);
        lang::data::Node::Decl::Include_T with_attr(langcc::ParserAttrMask attr);
        lang::data::Node::Decl::Include_T with_first_k(langcc::ParserLookahead first_k);
        lang::data::Node::Decl::Include_T with_path(langcc::StrSlice path);
        void hash_ser_acc_lang_data_Node_Decl_Include(langcc::SerBuf& buf) const;
        virtual void hash_ser_acc(langcc::SerBuf& buf) const;
    };
}

namespace langcc {
    void pr_debug(ostream& os, FmtFlags flags, lang::data::Node::Decl::Namespace_T x);
}

namespace lang::data::Node::Decl::Namespace {
    lang::data::Node::Decl::Namespace_T make(langcc::Int id, langcc::TokenBounds bounds, bool is_top, langcc::ParserSymId sym, langcc::ParserAttrMask attr, langcc::ParserLookahead first_k, lang::data::Node::Id_T name, langcc::Vec_T<lang::data::Node::Decl_T> body);
}

namespace lang::data::Node::Decl::Namespace {
    lang::data::Node::Decl::Namespace_T make_ext(langcc::ArenaPtr arena, langcc::Int id, langcc::TokenBounds bounds, bool is_top, langcc::ParserSymId sym, langcc::ParserAttrMask attr, langcc::ParserLookahead first_k, lang::data::Node::Id_T name, langcc::Vec_T<lang::data::Node::Decl_T> body);
}

namespace lang::data::Node::Decl::Namespace {
    struct _T: lang::data::Node::Decl::_T {
        void write(langcc::Ref<std::ostream> os, langcc::FmtFlags flags);
        void write(langcc::Ref<langcc::PrBufStream_T> pb);
        lang::data::Node::Id_T name_;
        langcc::Vec_T<lang::data::Node::Decl_T> body_;
        _T();
        lang::data::Node::Decl::Namespace_T with_id(langcc::Int id);
        lang::data::Node::Decl::Namespace_T with_bounds(langcc::TokenBounds bounds);
        lang::data::Node::Decl::Namespace_T with_is_top(bool is_top);
        lang::data::Node::Decl::Namespace_T with_sym(langcc::ParserSymId sym);
        lang::data::Node::Decl::Namespace_T with_attr(langcc::ParserAttrMask attr);
        lang::data::Node::Decl::Namespace_T with_first_k(langcc::ParserLookahead first_k);
        lang::data::Node::Decl::Namespace_T with_name(lang::data::Node::Id_T name);
        lang::data::Node::Decl::Namespace_T with_body(langcc::Vec_T<lang::data::Node::Decl_T> body);
        void hash_ser_acc_lang_data_Node_Decl_Namespace(langcc::SerBuf& buf) const;
        virtual void hash_ser_acc(langcc::SerBuf& buf) const;
    };
}

namespace langcc {
    void pr_debug(ostream& os, FmtFlags flags, lang::data::Node::Decl::Data_T x);
}

namespace lang::data::Node::Decl::Data {
    lang::data::Node::Decl::Data_T make(langcc::Int id, langcc::TokenBounds bounds, bool is_top, langcc::ParserSymId sym, langcc::ParserAttrMask attr, langcc::ParserLookahead first_k, lang::data::Node::SumId_T name, langcc::Option_T<lang::data::Node::SumId_T> base, langcc::Option_T<langcc::Vec_T<lang::data::Node::Param_T>> params, langcc::Vec_T<lang::data::Node::Mod_T> mods, langcc::Vec_T<lang::data::Node::Entry_T> entries);
}

namespace lang::data::Node::Decl::Data {
    lang::data::Node::Decl::Data_T make_ext(langcc::ArenaPtr arena, langcc::Int id, langcc::TokenBounds bounds, bool is_top, langcc::ParserSymId sym, langcc::ParserAttrMask attr, langcc::ParserLookahead first_k, lang::data::Node::SumId_T name, langcc::Option_T<lang::data::Node::SumId_T> base, langcc::Option_T<langcc::Vec_T<lang::data::Node::Param_T>> params, langcc::Vec_T<lang::data::Node::Mod_T> mods, langcc::Vec_T<lang::data::Node::Entry_T> entries);
}

namespace lang::data::Node::Decl::Data {
    struct _T: lang::data::Node::Decl::_T {
        void write(langcc::Ref<std::ostream> os, langcc::FmtFlags flags);
        void write(langcc::Ref<langcc::PrBufStream_T> pb);
        lang::data::Node::SumId_T name_;
        langcc::Option_T<lang::data::Node::SumId_T> base_;
        langcc::Option_T<langcc::Vec_T<lang::data::Node::Param_T>> params_;
        langcc::Vec_T<lang::data::Node::Mod_T> mods_;
        langcc::Vec_T<lang::data::Node::Entry_T> entries_;
        _T();
        lang::data::Node::Decl::Data_T with_id(langcc::Int id);
        lang::data::Node::Decl::Data_T with_bounds(langcc::TokenBounds bounds);
        lang::data::Node::Decl::Data_T with_is_top(bool is_top);
        lang::data::Node::Decl::Data_T with_sym(langcc::ParserSymId sym);
        lang::data::Node::Decl::Data_T with_attr(langcc::ParserAttrMask attr);
        lang::data::Node::Decl::Data_T with_first_k(langcc::ParserLookahead first_k);
        lang::data::Node::Decl::Data_T with_name(lang::data::Node::SumId_T name);
        lang::data::Node::Decl::Data_T with_base(langcc::Option_T<lang::data::Node::SumId_T> base);
        lang::data::Node::Decl::Data_T with_params(langcc::Option_T<langcc::Vec_T<lang::data::Node::Param_T>> params);
        lang::data::Node::Decl::Data_T with_mods(langcc::Vec_T<lang::data::Node::Mod_T> mods);
        lang::data::Node::Decl::Data_T with_entries(langcc::Vec_T<lang::data::Node::Entry_T> entries);
        void hash_ser_acc_lang_data_Node_Decl_Data(langcc::SerBuf& buf) const;
        virtual void hash_ser_acc(langcc::SerBuf& buf) const;
    };
}

namespace langcc {
    void pr_debug(ostream& os, FmtFlags flags, lang::data::Node::Decl::Enum_T x);
}

namespace lang::data::Node::Decl::Enum {
    lang::data::Node::Decl::Enum_T make(langcc::Int id, langcc::TokenBounds bounds, bool is_top, langcc::ParserSymId sym, langcc::ParserAttrMask attr, langcc::ParserLookahead first_k, lang::data::Node::Id_T name, langcc::Vec_T<langcc::StrSlice> cases);
}

namespace lang::data::Node::Decl::Enum {
    lang::data::Node::Decl::Enum_T make_ext(langcc::ArenaPtr arena, langcc::Int id, langcc::TokenBounds bounds, bool is_top, langcc::ParserSymId sym, langcc::ParserAttrMask attr, langcc::ParserLookahead first_k, lang::data::Node::Id_T name, langcc::Vec_T<langcc::StrSlice> cases);
}

namespace lang::data::Node::Decl::Enum {
    struct _T: lang::data::Node::Decl::_T {
        void write(langcc::Ref<std::ostream> os, langcc::FmtFlags flags);
        void write(langcc::Ref<langcc::PrBufStream_T> pb);
        lang::data::Node::Id_T name_;
        langcc::Vec_T<langcc::StrSlice> cases_;
        _T();
        lang::data::Node::Decl::Enum_T with_id(langcc::Int id);
        lang::data::Node::Decl::Enum_T with_bounds(langcc::TokenBounds bounds);
        lang::data::Node::Decl::Enum_T with_is_top(bool is_top);
        lang::data::Node::Decl::Enum_T with_sym(langcc::ParserSymId sym);
        lang::data::Node::Decl::Enum_T with_attr(langcc::ParserAttrMask attr);
        lang::data::Node::Decl::Enum_T with_first_k(langcc::ParserLookahead first_k);
        lang::data::Node::Decl::Enum_T with_name(lang::data::Node::Id_T name);
        lang::data::Node::Decl::Enum_T with_cases(langcc::Vec_T<langcc::StrSlice> cases);
        void hash_ser_acc_lang_data_Node_Decl_Enum(langcc::SerBuf& buf) const;
        virtual void hash_ser_acc(langcc::SerBuf& buf) const;
    };
}

namespace langcc {
    void pr_debug(ostream& os, FmtFlags flags, lang::data::Node::Mod::Mut_T x);
}

namespace lang::data::Node::Mod::Mut {
    lang::data::Node::Mod::Mut_T make(langcc::Int id, langcc::TokenBounds bounds, bool is_top, langcc::ParserSymId sym, langcc::ParserAttrMask attr, langcc::ParserLookahead first_k);
}

namespace lang::data::Node::Mod::Mut {
    lang::data::Node::Mod::Mut_T make_ext(langcc::ArenaPtr arena, langcc::Int id, langcc::TokenBounds bounds, bool is_top, langcc::ParserSymId sym, langcc::ParserAttrMask attr, langcc::ParserLookahead first_k);
}

namespace lang::data::Node::Mod::Mut {
    struct _T: lang::data::Node::Mod::_T {
        void write(langcc::Ref<std::ostream> os, langcc::FmtFlags flags);
        void write(langcc::Ref<langcc::PrBufStream_T> pb);
        _T();
        lang::data::Node::Mod::Mut_T with_id(langcc::Int id);
        lang::data::Node::Mod::Mut_T with_bounds(langcc::TokenBounds bounds);
        lang::data::Node::Mod::Mut_T with_is_top(bool is_top);
        lang::data::Node::Mod::Mut_T with_sym(langcc::ParserSymId sym);
        lang::data::Node::Mod::Mut_T with_attr(langcc::ParserAttrMask attr);
        lang::data::Node::Mod::Mut_T with_first_k(langcc::ParserLookahead first_k);
        void hash_ser_acc_lang_data_Node_Mod_Mut(langcc::SerBuf& buf) const;
        virtual void hash_ser_acc(langcc::SerBuf& buf) const;
    };
}

namespace langcc {
    void pr_debug(ostream& os, FmtFlags flags, lang::data::Node::Mod::Xform_T x);
}

namespace lang::data::Node::Mod::Xform {
    lang::data::Node::Mod::Xform_T make(langcc::Int id, langcc::TokenBounds bounds, bool is_top, langcc::ParserSymId sym, langcc::ParserAttrMask attr, langcc::ParserLookahead first_k);
}

namespace lang::data::Node::Mod::Xform {
    lang::data::Node::Mod::Xform_T make_ext(langcc::ArenaPtr arena, langcc::Int id, langcc::TokenBounds bounds, bool is_top, langcc::ParserSymId sym, langcc::ParserAttrMask attr, langcc::ParserLookahead first_k);
}

namespace lang::data::Node::Mod::Xform {
    struct _T: lang::data::Node::Mod::_T {
        void write(langcc::Ref<std::ostream> os, langcc::FmtFlags flags);
        void write(langcc::Ref<langcc::PrBufStream_T> pb);
        _T();
        lang::data::Node::Mod::Xform_T with_id(langcc::Int id);
        lang::data::Node::Mod::Xform_T with_bounds(langcc::TokenBounds bounds);
        lang::data::Node::Mod::Xform_T with_is_top(bool is_top);
        lang::data::Node::Mod::Xform_T with_sym(langcc::ParserSymId sym);
        lang::data::Node::Mod::Xform_T with_attr(langcc::ParserAttrMask attr);
        lang::data::Node::Mod::Xform_T with_first_k(langcc::ParserLookahead first_k);
        void hash_ser_acc_lang_data_Node_Mod_Xform(langcc::SerBuf& buf) const;
        virtual void hash_ser_acc(langcc::SerBuf& buf) const;
    };
}

namespace langcc {
    void pr_debug(ostream& os, FmtFlags flags, lang::data::Node::Mod::Visit_T x);
}

namespace lang::data::Node::Mod::Visit {
    lang::data::Node::Mod::Visit_T make(langcc::Int id, langcc::TokenBounds bounds, bool is_top, langcc::ParserSymId sym, langcc::ParserAttrMask attr, langcc::ParserLookahead first_k);
}

namespace lang::data::Node::Mod::Visit {
    lang::data::Node::Mod::Visit_T make_ext(langcc::ArenaPtr arena, langcc::Int id, langcc::TokenBounds bounds, bool is_top, langcc::ParserSymId sym, langcc::ParserAttrMask attr, langcc::ParserLookahead first_k);
}

namespace lang::data::Node::Mod::Visit {
    struct _T: lang::data::Node::Mod::_T {
        void write(langcc::Ref<std::ostream> os, langcc::FmtFlags flags);
        void write(langcc::Ref<langcc::PrBufStream_T> pb);
        _T();
        lang::data::Node::Mod::Visit_T with_id(langcc::Int id);
        lang::data::Node::Mod::Visit_T with_bounds(langcc::TokenBounds bounds);
        lang::data::Node::Mod::Visit_T with_is_top(bool is_top);
        lang::data::Node::Mod::Visit_T with_sym(langcc::ParserSymId sym);
        lang::data::Node::Mod::Visit_T with_attr(langcc::ParserAttrMask attr);
        lang::data::Node::Mod::Visit_T with_first_k(langcc::ParserLookahead first_k);
        void hash_ser_acc_lang_data_Node_Mod_Visit(langcc::SerBuf& buf) const;
        virtual void hash_ser_acc(langcc::SerBuf& buf) const;
    };
}

namespace langcc {
    void pr_debug(ostream& os, FmtFlags flags, lang::data::Node::Entry::Field_T x);
}

namespace lang::data::Node::Entry::Field {
    lang::data::Node::Entry::Field_T make(langcc::Int id, langcc::TokenBounds bounds, bool is_top, langcc::ParserSymId sym, langcc::ParserAttrMask attr, langcc::ParserLookahead first_k, langcc::StrSlice name, bool no_hash_, lang::data::Node::Expr_T type_);
}

namespace lang::data::Node::Entry::Field {
    lang::data::Node::Entry::Field_T make_ext(langcc::ArenaPtr arena, langcc::Int id, langcc::TokenBounds bounds, bool is_top, langcc::ParserSymId sym, langcc::ParserAttrMask attr, langcc::ParserLookahead first_k, langcc::StrSlice name, bool no_hash_, lang::data::Node::Expr_T type_);
}

namespace lang::data::Node::Entry::Field {
    struct _T: lang::data::Node::Entry::_T {
        void write(langcc::Ref<std::ostream> os, langcc::FmtFlags flags);
        void write(langcc::Ref<langcc::PrBufStream_T> pb);
        langcc::StrSlice name_;
        bool no_hash__;
        lang::data::Node::Expr_T type__;
        _T();
        lang::data::Node::Entry::Field_T with_id(langcc::Int id);
        lang::data::Node::Entry::Field_T with_bounds(langcc::TokenBounds bounds);
        lang::data::Node::Entry::Field_T with_is_top(bool is_top);
        lang::data::Node::Entry::Field_T with_sym(langcc::ParserSymId sym);
        lang::data::Node::Entry::Field_T with_attr(langcc::ParserAttrMask attr);
        lang::data::Node::Entry::Field_T with_first_k(langcc::ParserLookahead first_k);
        lang::data::Node::Entry::Field_T with_name(langcc::StrSlice name);
        lang::data::Node::Entry::Field_T with_no_hash_(bool no_hash_);
        lang::data::Node::Entry::Field_T with_type_(lang::data::Node::Expr_T type_);
        void hash_ser_acc_lang_data_Node_Entry_Field(langcc::SerBuf& buf) const;
        virtual void hash_ser_acc(langcc::SerBuf& buf) const;
    };
}

namespace langcc {
    void pr_debug(ostream& os, FmtFlags flags, lang::data::Node::Entry::Method_T x);
}

namespace lang::data::Node::Entry::Method {
    lang::data::Node::Entry::Method_T make(langcc::Int id, langcc::TokenBounds bounds, bool is_top, langcc::ParserSymId sym, langcc::ParserAttrMask attr, langcc::ParserLookahead first_k, bool virtual_, bool interface_, langcc::StrSlice name, langcc::Vec_T<lang::data::Node::Param_T> params, lang::data::Node::Expr_T ret_type);
}

namespace lang::data::Node::Entry::Method {
    lang::data::Node::Entry::Method_T make_ext(langcc::ArenaPtr arena, langcc::Int id, langcc::TokenBounds bounds, bool is_top, langcc::ParserSymId sym, langcc::ParserAttrMask attr, langcc::ParserLookahead first_k, bool virtual_, bool interface_, langcc::StrSlice name, langcc::Vec_T<lang::data::Node::Param_T> params, lang::data::Node::Expr_T ret_type);
}

namespace lang::data::Node::Entry::Method {
    struct _T: lang::data::Node::Entry::_T {
        void write(langcc::Ref<std::ostream> os, langcc::FmtFlags flags);
        void write(langcc::Ref<langcc::PrBufStream_T> pb);
        bool virtual__;
        bool interface__;
        langcc::StrSlice name_;
        langcc::Vec_T<lang::data::Node::Param_T> params_;
        lang::data::Node::Expr_T ret_type_;
        _T();
        lang::data::Node::Entry::Method_T with_id(langcc::Int id);
        lang::data::Node::Entry::Method_T with_bounds(langcc::TokenBounds bounds);
        lang::data::Node::Entry::Method_T with_is_top(bool is_top);
        lang::data::Node::Entry::Method_T with_sym(langcc::ParserSymId sym);
        lang::data::Node::Entry::Method_T with_attr(langcc::ParserAttrMask attr);
        lang::data::Node::Entry::Method_T with_first_k(langcc::ParserLookahead first_k);
        lang::data::Node::Entry::Method_T with_virtual_(bool virtual_);
        lang::data::Node::Entry::Method_T with_interface_(bool interface_);
        lang::data::Node::Entry::Method_T with_name(langcc::StrSlice name);
        lang::data::Node::Entry::Method_T with_params(langcc::Vec_T<lang::data::Node::Param_T> params);
        lang::data::Node::Entry::Method_T with_ret_type(lang::data::Node::Expr_T ret_type);
        void hash_ser_acc_lang_data_Node_Entry_Method(langcc::SerBuf& buf) const;
        virtual void hash_ser_acc(langcc::SerBuf& buf) const;
    };
}

namespace langcc {
    void pr_debug(ostream& os, FmtFlags flags, lang::data::Node::Expr::Id_T x);
}

namespace lang::data::Node::Expr::Id {
    lang::data::Node::Expr::Id_T make(langcc::Int id, langcc::TokenBounds bounds, bool is_top, langcc::ParserSymId sym, langcc::ParserAttrMask attr, langcc::ParserLookahead first_k, bool ext, lang::data::Node::Id_T x);
}

namespace lang::data::Node::Expr::Id {
    lang::data::Node::Expr::Id_T make_ext(langcc::ArenaPtr arena, langcc::Int id, langcc::TokenBounds bounds, bool is_top, langcc::ParserSymId sym, langcc::ParserAttrMask attr, langcc::ParserLookahead first_k, bool ext, lang::data::Node::Id_T x);
}

namespace lang::data::Node::Expr::Id {
    struct _T: lang::data::Node::Expr::_T {
        void write(langcc::Ref<std::ostream> os, langcc::FmtFlags flags);
        void write(langcc::Ref<langcc::PrBufStream_T> pb);
        bool ext_;
        lang::data::Node::Id_T x_;
        _T();
        lang::data::Node::Expr::Id_T with_id(langcc::Int id);
        lang::data::Node::Expr::Id_T with_bounds(langcc::TokenBounds bounds);
        lang::data::Node::Expr::Id_T with_is_top(bool is_top);
        lang::data::Node::Expr::Id_T with_sym(langcc::ParserSymId sym);
        lang::data::Node::Expr::Id_T with_attr(langcc::ParserAttrMask attr);
        lang::data::Node::Expr::Id_T with_first_k(langcc::ParserLookahead first_k);
        lang::data::Node::Expr::Id_T with_ext(bool ext);
        lang::data::Node::Expr::Id_T with_x(lang::data::Node::Id_T x);
        void hash_ser_acc_lang_data_Node_Expr_Id(langcc::SerBuf& buf) const;
        virtual void hash_ser_acc(langcc::SerBuf& buf) const;
    };
}

namespace langcc {
    void pr_debug(ostream& os, FmtFlags flags, lang::data::Node::Expr::App_T x);
}

namespace lang::data::Node::Expr::App {
    lang::data::Node::Expr::App_T make(langcc::Int id, langcc::TokenBounds bounds, bool is_top, langcc::ParserSymId sym, langcc::ParserAttrMask attr, langcc::ParserLookahead first_k, lang::data::Node::Expr_T f, langcc::Vec_T<lang::data::Node::Expr_T> args);
}

namespace lang::data::Node::Expr::App {
    lang::data::Node::Expr::App_T make_ext(langcc::ArenaPtr arena, langcc::Int id, langcc::TokenBounds bounds, bool is_top, langcc::ParserSymId sym, langcc::ParserAttrMask attr, langcc::ParserLookahead first_k, lang::data::Node::Expr_T f, langcc::Vec_T<lang::data::Node::Expr_T> args);
}

namespace lang::data::Node::Expr::App {
    struct _T: lang::data::Node::Expr::_T {
        void write(langcc::Ref<std::ostream> os, langcc::FmtFlags flags);
        void write(langcc::Ref<langcc::PrBufStream_T> pb);
        lang::data::Node::Expr_T f_;
        langcc::Vec_T<lang::data::Node::Expr_T> args_;
        _T();
        lang::data::Node::Expr::App_T with_id(langcc::Int id);
        lang::data::Node::Expr::App_T with_bounds(langcc::TokenBounds bounds);
        lang::data::Node::Expr::App_T with_is_top(bool is_top);
        lang::data::Node::Expr::App_T with_sym(langcc::ParserSymId sym);
        lang::data::Node::Expr::App_T with_attr(langcc::ParserAttrMask attr);
        lang::data::Node::Expr::App_T with_first_k(langcc::ParserLookahead first_k);
        lang::data::Node::Expr::App_T with_f(lang::data::Node::Expr_T f);
        lang::data::Node::Expr::App_T with_args(langcc::Vec_T<lang::data::Node::Expr_T> args);
        void hash_ser_acc_lang_data_Node_Expr_App(langcc::SerBuf& buf) const;
        virtual void hash_ser_acc(langcc::SerBuf& buf) const;
    };
}

namespace langcc {
    void pr_debug(ostream& os, FmtFlags flags, lang::data::Node::Expr::Type__T x);
}

namespace lang::data::Node::Expr::Type_ {
    lang::data::Node::Expr::Type__T make(langcc::Int id, langcc::TokenBounds bounds, bool is_top, langcc::ParserSymId sym, langcc::ParserAttrMask attr, langcc::ParserLookahead first_k);
}

namespace lang::data::Node::Expr::Type_ {
    lang::data::Node::Expr::Type__T make_ext(langcc::ArenaPtr arena, langcc::Int id, langcc::TokenBounds bounds, bool is_top, langcc::ParserSymId sym, langcc::ParserAttrMask attr, langcc::ParserLookahead first_k);
}

namespace lang::data::Node::Expr::Type_ {
    struct _T: lang::data::Node::Expr::_T {
        void write(langcc::Ref<std::ostream> os, langcc::FmtFlags flags);
        void write(langcc::Ref<langcc::PrBufStream_T> pb);
        _T();
        lang::data::Node::Expr::Type__T with_id(langcc::Int id);
        lang::data::Node::Expr::Type__T with_bounds(langcc::TokenBounds bounds);
        lang::data::Node::Expr::Type__T with_is_top(bool is_top);
        lang::data::Node::Expr::Type__T with_sym(langcc::ParserSymId sym);
        lang::data::Node::Expr::Type__T with_attr(langcc::ParserAttrMask attr);
        lang::data::Node::Expr::Type__T with_first_k(langcc::ParserLookahead first_k);
        void hash_ser_acc_lang_data_Node_Expr_Type_(langcc::SerBuf& buf) const;
        virtual void hash_ser_acc(langcc::SerBuf& buf) const;
    };
}

void visit_lang_data_Node(lang::data::Node::Decl::Include_T x, std::function<void(lang::data::Node_T)> f);

void visit_lang_data_Node(lang::data::Node::Id_T x, std::function<void(lang::data::Node_T)> f);

void visit_lang_data_Node(lang::data::Node::Decl::Namespace_T x, std::function<void(lang::data::Node_T)> f);

void visit_lang_data_Node(lang::data::Node::SumId_T x, std::function<void(lang::data::Node_T)> f);

void visit_lang_data_Node(lang::data::Node::Expr::Id_T x, std::function<void(lang::data::Node_T)> f);

void visit_lang_data_Node(lang::data::Node::Expr::App_T x, std::function<void(lang::data::Node_T)> f);

void visit_lang_data_Node(lang::data::Node::Expr::Type__T x, std::function<void(lang::data::Node_T)> f);

void visit_lang_data_Node(lang::data::Node::Expr_T x, std::function<void(lang::data::Node_T)> f);

void visit_lang_data_Node(lang::data::Node::Param_T x, std::function<void(lang::data::Node_T)> f);

void visit_lang_data_Node(lang::data::Node::Mod::Mut_T x, std::function<void(lang::data::Node_T)> f);

void visit_lang_data_Node(lang::data::Node::Mod::Xform_T x, std::function<void(lang::data::Node_T)> f);

void visit_lang_data_Node(lang::data::Node::Mod::Visit_T x, std::function<void(lang::data::Node_T)> f);

void visit_lang_data_Node(lang::data::Node::Mod_T x, std::function<void(lang::data::Node_T)> f);

void visit_lang_data_Node(lang::data::Node::Entry::Field_T x, std::function<void(lang::data::Node_T)> f);

void visit_lang_data_Node(lang::data::Node::Entry::Method_T x, std::function<void(lang::data::Node_T)> f);

void visit_lang_data_Node(lang::data::Node::Entry_T x, std::function<void(lang::data::Node_T)> f);

void visit_lang_data_Node(lang::data::Node::Decl::Data_T x, std::function<void(lang::data::Node_T)> f);

void visit_lang_data_Node(lang::data::Node::Decl::Enum_T x, std::function<void(lang::data::Node_T)> f);

void visit_lang_data_Node(lang::data::Node::Decl_T x, std::function<void(lang::data::Node_T)> f);

void visit_lang_data_Node(lang::data::Node::Module_T x, std::function<void(lang::data::Node_T)> f);

void visit_lang_data_Node(lang::data::Node_T x, std::function<void(lang::data::Node_T)> f);

lang::data::Node_T xformT_lang_data_Node(lang::data::Node::Decl::Include_T x, std::function<lang::data::Node_T(lang::data::Node_T)> f);

lang::data::Node_T xformT_lang_data_Node(lang::data::Node::Id_T x, std::function<lang::data::Node_T(lang::data::Node_T)> f);

lang::data::Node_T xformT_lang_data_Node(lang::data::Node::Decl::Namespace_T x, std::function<lang::data::Node_T(lang::data::Node_T)> f);

lang::data::Node_T xformT_lang_data_Node(lang::data::Node::SumId_T x, std::function<lang::data::Node_T(lang::data::Node_T)> f);

lang::data::Node_T xformT_lang_data_Node(lang::data::Node::Expr::Id_T x, std::function<lang::data::Node_T(lang::data::Node_T)> f);

lang::data::Node_T xformT_lang_data_Node(lang::data::Node::Expr::App_T x, std::function<lang::data::Node_T(lang::data::Node_T)> f);

lang::data::Node_T xformT_lang_data_Node(lang::data::Node::Expr::Type__T x, std::function<lang::data::Node_T(lang::data::Node_T)> f);

lang::data::Node_T xformT_lang_data_Node(lang::data::Node::Expr_T x, std::function<lang::data::Node_T(lang::data::Node_T)> f);

lang::data::Node_T xformT_lang_data_Node(lang::data::Node::Param_T x, std::function<lang::data::Node_T(lang::data::Node_T)> f);

lang::data::Node_T xformT_lang_data_Node(lang::data::Node::Mod::Mut_T x, std::function<lang::data::Node_T(lang::data::Node_T)> f);

lang::data::Node_T xformT_lang_data_Node(lang::data::Node::Mod::Xform_T x, std::function<lang::data::Node_T(lang::data::Node_T)> f);

lang::data::Node_T xformT_lang_data_Node(lang::data::Node::Mod::Visit_T x, std::function<lang::data::Node_T(lang::data::Node_T)> f);

lang::data::Node_T xformT_lang_data_Node(lang::data::Node::Mod_T x, std::function<lang::data::Node_T(lang::data::Node_T)> f);

lang::data::Node_T xformT_lang_data_Node(lang::data::Node::Entry::Field_T x, std::function<lang::data::Node_T(lang::data::Node_T)> f);

lang::data::Node_T xformT_lang_data_Node(lang::data::Node::Entry::Method_T x, std::function<lang::data::Node_T(lang::data::Node_T)> f);

lang::data::Node_T xformT_lang_data_Node(lang::data::Node::Entry_T x, std::function<lang::data::Node_T(lang::data::Node_T)> f);

lang::data::Node_T xformT_lang_data_Node(lang::data::Node::Decl::Data_T x, std::function<lang::data::Node_T(lang::data::Node_T)> f);

lang::data::Node_T xformT_lang_data_Node(lang::data::Node::Decl::Enum_T x, std::function<lang::data::Node_T(lang::data::Node_T)> f);

lang::data::Node_T xformT_lang_data_Node(lang::data::Node::Decl_T x, std::function<lang::data::Node_T(lang::data::Node_T)> f);

lang::data::Node_T xformT_lang_data_Node(lang::data::Node::Module_T x, std::function<lang::data::Node_T(lang::data::Node_T)> f);

lang::data::Node_T xformT_lang_data_Node(lang::data::Node_T x, std::function<lang::data::Node_T(lang::data::Node_T)> f);

lang::data::Node_T xform_lang_data_Node(lang::data::Node_T x, std::function<lang::data::Node_T(lang::data::Node_T)> f);

lang::data::Node::Module_T xform_lang_data_Node(lang::data::Node::Module_T x, std::function<lang::data::Node_T(lang::data::Node_T)> f);

lang::data::Node::Decl_T xform_lang_data_Node(lang::data::Node::Decl_T x, std::function<lang::data::Node_T(lang::data::Node_T)> f);

lang::data::Node::Decl::Include_T xform_lang_data_Node(lang::data::Node::Decl::Include_T x, std::function<lang::data::Node_T(lang::data::Node_T)> f);

lang::data::Node::Decl::Namespace_T xform_lang_data_Node(lang::data::Node::Decl::Namespace_T x, std::function<lang::data::Node_T(lang::data::Node_T)> f);

lang::data::Node::Id_T xform_lang_data_Node(lang::data::Node::Id_T x, std::function<lang::data::Node_T(lang::data::Node_T)> f);

lang::data::Node::Decl::Data_T xform_lang_data_Node(lang::data::Node::Decl::Data_T x, std::function<lang::data::Node_T(lang::data::Node_T)> f);

lang::data::Node::SumId_T xform_lang_data_Node(lang::data::Node::SumId_T x, std::function<lang::data::Node_T(lang::data::Node_T)> f);

lang::data::Node::Param_T xform_lang_data_Node(lang::data::Node::Param_T x, std::function<lang::data::Node_T(lang::data::Node_T)> f);

lang::data::Node::Expr_T xform_lang_data_Node(lang::data::Node::Expr_T x, std::function<lang::data::Node_T(lang::data::Node_T)> f);

lang::data::Node::Expr::Id_T xform_lang_data_Node(lang::data::Node::Expr::Id_T x, std::function<lang::data::Node_T(lang::data::Node_T)> f);

lang::data::Node::Expr::App_T xform_lang_data_Node(lang::data::Node::Expr::App_T x, std::function<lang::data::Node_T(lang::data::Node_T)> f);

lang::data::Node::Expr::Type__T xform_lang_data_Node(lang::data::Node::Expr::Type__T x, std::function<lang::data::Node_T(lang::data::Node_T)> f);

lang::data::Node::Mod_T xform_lang_data_Node(lang::data::Node::Mod_T x, std::function<lang::data::Node_T(lang::data::Node_T)> f);

lang::data::Node::Mod::Mut_T xform_lang_data_Node(lang::data::Node::Mod::Mut_T x, std::function<lang::data::Node_T(lang::data::Node_T)> f);

lang::data::Node::Mod::Xform_T xform_lang_data_Node(lang::data::Node::Mod::Xform_T x, std::function<lang::data::Node_T(lang::data::Node_T)> f);

lang::data::Node::Mod::Visit_T xform_lang_data_Node(lang::data::Node::Mod::Visit_T x, std::function<lang::data::Node_T(lang::data::Node_T)> f);

lang::data::Node::Entry_T xform_lang_data_Node(lang::data::Node::Entry_T x, std::function<lang::data::Node_T(lang::data::Node_T)> f);

lang::data::Node::Entry::Field_T xform_lang_data_Node(lang::data::Node::Entry::Field_T x, std::function<lang::data::Node_T(lang::data::Node_T)> f);

lang::data::Node::Entry::Method_T xform_lang_data_Node(lang::data::Node::Entry::Method_T x, std::function<lang::data::Node_T(lang::data::Node_T)> f);

lang::data::Node::Decl::Enum_T xform_lang_data_Node(lang::data::Node::Decl::Enum_T x, std::function<lang::data::Node_T(lang::data::Node_T)> f);

namespace lang::data::parser {
    langcc::IntPair action_by_vertex(langcc::ParserVertexId v, langcc::ParserLookahead la);
}

namespace lang::data::parser {
    langcc::ParserVertexId vertex_dfa_step(langcc::ParserVertexId v, langcc::ParserSymId sym, langcc::ParserAttrMask attr);
}

namespace lang::data::parser {
    langcc::ParserProcXforms proc_xform_by_prod_id();
}

namespace lang::data::parser {
    langcc::ParserSymByName start_marker_by_name();
}

namespace lang::data::parser {
    langcc::ParserSymId term_tok_to_sym(langcc::TokenId tok);
}

namespace lang::data::parser {
    langcc::ParserSymId sym_to_recur_step(langcc::ParserSymId sym);
}

namespace lang::data::parser {
    std::string sym_to_debug_string(langcc::ParserSymId sym);
}

namespace lang::data::parser {
    langcc::Int sym_to_num_attrs(langcc::ParserSymId sym);
}

namespace lang::data::parser {
    std::string attr_to_debug_string(langcc::ParserSymId sym, langcc::Int attr_ind);
}

namespace lang::data {
    using LangDesc = langcc::LangDesc<Node::_T, parser::action_by_vertex, parser::vertex_dfa_step>;
}

namespace lang::data {
    using LangDesc_T = langcc::LangDesc_T<Node::_T, parser::action_by_vertex, parser::vertex_dfa_step>;
}

namespace lang::data {
    using QuoteEnv = langcc::QuoteEnv<Node::_T, parser::action_by_vertex, parser::vertex_dfa_step>;
}

namespace lang::data {
    using QuoteEnv_T = langcc::QuoteEnv_T<Node::_T, parser::action_by_vertex, parser::vertex_dfa_step>;
}

namespace lang::data {
    lang::data::LangDesc_T init();
}

namespace lang::data::lexer::body {
    inline __attribute__((always_inline)) langcc::Int proc_mode_loop_opt(langcc::Ptr<langcc::LexerModeDesc> mode, langcc::Ptr<langcc::LexerState> st, langcc::Ptr<langcc::SymItemVec> emit_dst, langcc::Int mode_start_pos, langcc::Int mode_buf_pos);
}

namespace lang::data::lexer::comment_single {
    inline __attribute__((always_inline)) langcc::Int proc_mode_loop_opt(langcc::Ptr<langcc::LexerModeDesc> mode, langcc::Ptr<langcc::LexerState> st, langcc::Ptr<langcc::SymItemVec> emit_dst, langcc::Int mode_start_pos, langcc::Int mode_buf_pos);
}
