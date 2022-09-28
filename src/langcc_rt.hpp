#pragma once

#include "langcc_util.hpp"

namespace lang_rt {

constexpr bool EXPENSIVE_ASSERT = false;

////////////////////////////////////////////////////////////////////////////////
// Forward declarations
////////////////////////////////////////////////////////////////////////////////

RC_STRUCT(LexerModeDesc);
RC_STRUCT(ParserDesc);

RC_STRUCT(LexError);
RC_STRUCT(LexInput);
RC_STRUCT(LexOutput);
RC_STRUCT(CommentMap);

RC_STRUCT(ParseError);

struct LexerState;
struct LexWhitespaceState;
struct ParserProcState;

using LexerModeId = Int;

using TokenId = Int;
constexpr TokenId NO_TOKEN = -1;

using DFAVertexId = Int;
using DFALabelId = Int;
using DFAActionId = Int;
using DFALabelIdVec = Vec<DFALabelId>;
using DFALabelIdMap = map<Ch, DFALabelId>;
using DFAActionWithToken = pair<DFAActionId, TokenId>;

using ParserSymId = Int;
constexpr ParserSymId NO_SYM = -1;

using ParserVertexId = Int;

struct NodeAllocDecrefInterface {
    virtual void decref_contents() = 0;
    virtual inline ~NodeAllocDecrefInterface() {}
};

#define PARSER_ATTR_MASK_MAX 16
#define PARSER_ATTR_MASK_SENTINEL 255

#define PARSER_LOOKAHEAD_LEN_MAX 8
#define PARSER_LOOKAHEAD_SENTINEL -1

using TermTokToSymFn = ParserSymId(*)(TokenId);

struct ParserAttrMask {
    u8 v_[PARSER_ATTR_MASK_MAX];
    ParserAttrMask() {
        for (Int j = 0; j < PARSER_ATTR_MASK_MAX; j++) {
            v_[j] = PARSER_ATTR_MASK_SENTINEL;
        }
    }
};

ParserAttrMask attr_mask_trivial();

struct ParserLookahead {
    i16 v_[PARSER_LOOKAHEAD_LEN_MAX];
    ParserLookahead() {
        for (Int j = 0; j < PARSER_LOOKAHEAD_LEN_MAX; j++) {
            v_[j] = PARSER_LOOKAHEAD_SENTINEL;
        }
    }
};

using ParserSymByName = map<string, Int>;

using ParserProdId = Int;

constexpr ParserVertexId NO_VERTEX = -1;

struct TokenBounds {
    i32 lo_;
    i32 hi_;
    inline TokenBounds() : lo_(0), hi_(0) {}
    inline TokenBounds(i32 lo, i32 hi) : lo_(lo), hi_(hi) {}
};

struct Result_T {
    void* v_;
    TokenBounds bounds_;
    inline Result_T(void* v, TokenBounds bounds) : v_(v), bounds_(bounds) {}
    inline Result_T() : v_(nullptr), bounds_(-1, -1) {}
};

inline Result_T result_encode_placeholder() {
    return Result_T(nullptr, TokenBounds(-1, -1));
}

inline TokenBounds result_decode_token_bounds(Result_T x) {
    return x.bounds_;
}

struct SymItem {
    TokenId tok_;  // NO_TOKEN for non-lexer items
    ParserSymId id_;
    ParserAttrMask attr_;
    Int start_pos_;  // lexer output index
    Int tok_in_lo_;
        // lexer input index (or -1 if quoted or non-lexer item). NOTE: in char, not u8
    Int tok_in_hi_;
        // lexer input index (or -1 if quoted or non-lexer item). NOTE: in char, not u8
    Result_T res_;

    ParserLookahead first_k_;

    inline SymItem() : tok_(NO_TOKEN), id_(NO_SYM), start_pos_(-1), attr_(attr_mask_trivial()) {}

    inline SymItem(ParserSymId id, Int start_pos) : tok_(NO_TOKEN),
        id_(id), start_pos_(start_pos), attr_(attr_mask_trivial()),
        tok_in_lo_(-1), tok_in_hi_(-1) {}

    static inline SymItem make_lex_token_parse_sym(
        TokenId tok, ParserSymId sym,
        Int tok_i,
        Int tok_in_lo, Int tok_in_hi) {

        SymItem ret;
        ret.tok_ = tok;
        ret.id_ = sym;
        ret.attr_ = attr_mask_trivial();
        ret.start_pos_ = tok_i;
        ret.tok_in_lo_ = tok_in_lo;
        ret.tok_in_hi_ = tok_in_hi;
        ret.res_ = result_encode_placeholder();
        return ret;
    }

    static inline SymItem make_lex_token(
        TokenId tok, TermTokToSymFn tok_to_sym, Int tok_in_lo, Int tok_in_hi) {
        return SymItem::make_lex_token_parse_sym(tok, tok_to_sym(tok),
            -2, // sentinel (-1 is start sym marker)
            tok_in_lo, tok_in_hi);
    }
};

using SymItemVec = Vec<SymItem>;

inline void pr(ostream& os, FmtFlags flags, SymItem item) {
    fmt(os, "<SymItem: sym={}, attr={}, tok={}, res={} ({}, {}), first_k={}>",
        item.id_, item.attr_, item.tok_, !!item.res_.v_, item.res_.bounds_.lo_,
        item.res_.bounds_.hi_, item.first_k_);
}

using LexerStepFn = lang_rt::DFAVertexId (*)(lang_rt::DFAVertexId, lang_rt::DFALabelId);
using LexerAccFn = lang_rt::DFAActionWithToken (*)(lang_rt::DFAVertexId);
using LexerStepExecFn = IntPair (*)(
    Ptr<lang_rt::LexerState> st, Ptr<lang_rt::SymItemVec> emit_dst,
    Ptr<lang_rt::LexWhitespaceState> ws_state, lang_rt::DFAActionId acc,
    lang_rt::TokenId tok, Int& in_i, Int& tok_lo, Int& tok_hi);

using ParserProcStatePtr = ParserProcState*;
using ParserProcXformDyn = SymItem(*)(Int, ParserProcStatePtr);
using ParserProcXform = SymItem(*)(ParserProcStatePtr);
using ParserProcXforms = Vec_T<ParserProcXform>;
using ParserProcAcc = IntPair(*)(ParserVertexId, ParserLookahead);
using ParserProcStep = ParserVertexId(*)(ParserVertexId, ParserSymId, ParserAttrMask);

#define LANG_META_PARAMS \
    typename Node, ParserProcAcc FAcc, ParserProcStep FStep

#define LANG_META_ARGS Node, FAcc, FStep

struct LexOutput: enable_rc_from_this<LexOutput> {
    bool quoted_;

    Vec_T<SymItem> items_internal_;
    Option_T<LexError_T> err_;

    // If not quoted
    Option_T<LexInput_T> in_;
    Option_T<CommentMap_T> comment_map_;

    // If quoted
    Option_T<Str_T> str_input_;
    Option_T<Vec_T<i32>> str_input_char_pos_;
    Option_T<Vec_T<rc_ptr<NodeAllocDecrefInterface>>> nodes_alloc_;

    inline static LexOutput_T make_text(LexInput_T in);

    inline static LexOutput_T make_quoted();

    inline IntPair lookup_pos(Int tok_i);

    inline StrSlice fetch_token(Int tok_i);

    inline bool allows_quoted_symbols();

    inline string location_fmt_str(TokenBounds bounds);

    inline bool is_success();

    inline ParserLookahead first_k(Int lr_k);

    inline void clear_alloc();
    inline void push_item(SymItem item);
};

template<LANG_META_PARAMS> struct ParseOutput;
template<LANG_META_PARAMS> using ParseOutput_T = rc_ptr<ParseOutput<LANG_META_ARGS>>;

template<LANG_META_PARAMS>
struct ParseOutput : enable_rc_from_this<ParseOutput<LANG_META_ARGS>> {
    Option_T<rc_ptr<Node>> res_;
    LexOutput_T lex_;
    ParserSymId sym_final_ = NO_SYM;
    ParserAttrMask attr_final_ = attr_mask_trivial();
    Option_T<ParseError_T> err_;
    Int num_steps_;

    inline bool is_success() {
        return err_.is_none();
    }

    static ParseOutput_T<LANG_META_ARGS> make_success(
        LexOutput_T lex, ParserSymId final_sym, ParserAttrMask final_attr,
        rc_ptr<Node> res, Int num_steps);

    static inline ParseOutput_T<LANG_META_ARGS> make_error(
        LexOutput_T lex, ParseError_T err);
};

inline Ch lex_decode_utf8(const char* x, Int& i, Int n);

template<LANG_META_PARAMS>
struct NodeAllocDecrefObj: NodeAllocDecrefInterface {
    Node* x_;

    inline NodeAllocDecrefObj(Node* x): x_(x) {}
    virtual inline void decref_contents() override {
        Arena* A = nullptr;
        rc_from_ptr_ext<Node>(x_, A).decref();
    }
};





////////////////////////////////////////////////////////////////////////////////
// Language description data
////////////////////////////////////////////////////////////////////////////////

template<LANG_META_PARAMS> struct LangDesc;
template<LANG_META_PARAMS> using LangDesc_T = rc_ptr<LangDesc<LANG_META_ARGS>>;

template<LANG_META_PARAMS> struct QuoteEnv;
template<LANG_META_PARAMS> using QuoteEnv_T = rc_ptr<QuoteEnv<LANG_META_ARGS>>;


struct ParserDesc {
    ParserVertexId start_vertex_;
    string main_sym_;
    ParserSymByName start_marker_by_name_;
    ParserSymId start_full_sym_;
    ParserSymId right_end_marker_;
    Int lr_k_;
    TermTokToSymFn term_tok_to_sym_;
    Int cps_flat_diff_max_;
    ParserSymId (*sym_to_recur_step_)(ParserSymId);
    ParserProcXforms proc_xform_by_prod_id_;
    string (*sym_to_debug_string_)(ParserSymId);
    string (*attr_to_debug_string_)(ParserSymId, Int);
    Int (*sym_to_num_attrs_)(ParserSymId);
};


template<LANG_META_PARAMS>
struct LangDesc : enable_rc_from_this<LangDesc<LANG_META_ARGS>> {
    Vec_T<LexerModeDesc_T> lexer_mode_descs_;
    rc_ptr<DFALabelIdVec> label_ids_ascii_;
    rc_ptr<DFALabelIdMap> label_ids_unicode_;
    LexerModeId lexer_main_mode_;

    ParserDesc_T parser_desc_;

    LexOutput_T lex(const Str_T& input, Arena* A);

    template<bool LR_K1, bool NO_QUOTE>
    ParseOutput_T<LANG_META_ARGS> parse_from_lex_specialized(
        LexOutput_T lex_out, Option_T<string> sym_target, Gensym_T gen, Arena* A);

    inline ParseOutput_T<LANG_META_ARGS> parse_from_lex(
        LexOutput_T lex_out, Option_T<string> sym_target, Gensym_T gen, Arena* A) {

        if (parser_desc_->lr_k_ == 1 && !lex_out->allows_quoted_symbols()) {
            return this->parse_from_lex_specialized<true, true>(lex_out, sym_target, gen, A);
        } else {
            return this->parse_from_lex_specialized<false, false>(lex_out, sym_target, gen, A);
        }
    }

    inline ParseOutput_T<LANG_META_ARGS> parse_ext(
        const Str_T& input, Option_T<string> sym_target, Gensym_T gen, Arena* A) {

        auto lex_out = this->lex(input, A);
        auto parse_out = this->parse_from_lex(lex_out, sym_target, gen, A);
        return parse_out;
    }

    inline ParseOutput_T<LANG_META_ARGS> parse(const Str_T& input, Gensym_T gen) {
        return this->parse_ext(input, None<string>(), gen, nullptr);
    }

    inline void debug_example(string sym_target, string input);

    inline bool test_example(
        Option_T<string> sym_target, const Str_T& input, Arena* A, Int error_pos_maybe,
        bool test_write);

    inline bool test_example(
        Option_T<string> sym_target, const char* input, Int error_pos_maybe, bool test_write);

    inline QuoteEnv_T<LANG_META_ARGS> quote_env(const string& sym_id, const string& ns_tok);
    inline QuoteEnv_T<LANG_META_ARGS> quote_env();
};


template<LANG_META_PARAMS>
struct QuoteEnv {
    LangDesc_T<LANG_META_ARGS> L_;
    Gensym_T gen_;

    inline rc_ptr<Node> qq_inner(Option_T<string> sym_target, LexOutput_T& lex) {
        AT(lex->quoted_);

        Arena* A = nullptr;
        auto parse_out = L_->parse_from_lex(lex, sym_target, gen_, A);
        if (!parse_out->is_success()) {
            fmt(cerr, "Input sequence: {}", lex);
            fmt(cerr, "{}\n", parse_out->err_.as_some());
            lex->clear_alloc();
            throw parse_out->err_.as_some();
        }

        return parse_out->res_.as_some();
    }

    inline void qq_args_acc(LexOutput_T& lex) {}

    template<typename ...Args>
    inline void qq_args_acc(LexOutput_T& lex,
        string arg, const Args&... args) {

        AT(lex->quoted_);
        Arena* A = nullptr;

        auto input = vec_from_std_string(arg);
        auto lex_sub = L_->lex(input, A);
        if (!lex_sub->is_success()) {
            LG_ERR("Lex error:\n{}\n\n", lex_sub->err_.as_some());
            throw lex_sub->err_.as_some();
        }
        auto char_offset = lex->str_input_char_pos_.as_some()->length();
        auto u8_offset = lex->str_input_.as_some()->length();
        for (SymItem item : *lex_sub->items_internal_) {
            AT(item.res_.v_ == nullptr);
            item.tok_in_lo_ += char_offset;
            item.tok_in_hi_ += char_offset;
            lex->push_item(item);
        }
        for (Int char_i = 0; char_i < lex_sub->in_.as_some()->char_pos_.length(); char_i++) {
            i32 char_pos = lex_sub->in_.as_some()->char_pos_.operator[](char_i);
            lex->str_input_char_pos_.as_some()->push(char_pos + u8_offset);
        }
        lex->str_input_.as_some()->extend(vec_from_std_string(arg));
        this->qq_args_acc(lex, args...);
    }

    template<typename ...Args>
    inline void qq_args_acc(LexOutput_T& lex,
        const rc_ptr<Node>& arg, const Args&... args) {

        AT(lex->quoted_);
        AT(arg->is_top_);
        AT(arg->sym_ != NO_SYM);
        arg.incref();
        lex->nodes_alloc_.as_some()->push(
            make_rc<NodeAllocDecrefObj<LANG_META_ARGS>>(arg.get()));
        SymItem item;
        item.res_.v_ = arg.get();
        item.id_ = arg->sym_;
        item.attr_ = arg->attr_;
        item.first_k_ = arg->first_k_;
        item.start_pos_ = -1;
        item.tok_ = NO_TOKEN;
        lex->push_item(item);
        this->qq_args_acc(lex, args...);
    }

    template<typename ...Args>
    inline void qq_args_acc(LexOutput_T& lex,
        const Vec<rc_ptr<Node>>& arg_v, const Args&... args) {

        for (const auto& arg : arg_v) {
            this->qq_args_acc(lex, arg);
        }
        this->qq_args_acc(lex, args...);
    }

    template<typename ...Args>
    inline void qq_args_acc(LexOutput_T& lex,
        const Vec<string>& arg_v, const Args&... args) {

        AT(lex->quoted_);

        for (const auto& arg : arg_v) {
            this->qq_args_acc(lex, arg);
        }
        this->qq_args_acc(lex, args...);
    }

    inline LexOutput_T make_lex_builder() {
        return LexOutput::make_quoted();
    }

    template<typename ...Args>
    inline rc_ptr<Node> qq_ext(Option_T<string> sym_target, const Args&... args) {
        auto lex = this->make_lex_builder();
        try {
            this->qq_args_acc(lex, args...);
            return this->qq_inner(sym_target, lex);
        } catch (const string& err) {
            fmt(cerr, "Input sequence: {}", lex);
            fmt(cerr, "{}\n", err);
            throw;
        }
    }

    template<typename ...Args>
    inline rc_ptr<Node> qq(const string& sym_target, const Args&... args) {
        return this->qq_ext(Some<string>(sym_target), args...);
    }

    template<typename ...Args>
    inline rc_ptr<Node> qq_def(const Args&... args) {
        return this->qq_ext(None<string>(), args...);
    }
};


template<LANG_META_PARAMS>
inline QuoteEnv_T<LANG_META_ARGS> LangDesc<LANG_META_ARGS>::quote_env(
    const string& id_sym, const string& ns_tok) {

    auto ret = make_rc<QuoteEnv<LANG_META_ARGS>>();
    ret->L_ = this->rc_from_this();
    ret->gen_ = make_rc<Gensym>();
    return ret;
}


template<LANG_META_PARAMS>
inline QuoteEnv_T<LANG_META_ARGS> LangDesc<LANG_META_ARGS>::quote_env() {
    auto ret = make_rc<QuoteEnv<LANG_META_ARGS>>();
    ret->L_ = this->rc_from_this();
    ret->gen_ = make_rc<Gensym>();
    return ret;
}





////////////////////////////////////////////////////////////////////////////////
// Lexer
////////////////////////////////////////////////////////////////////////////////

inline void pr_debug(ostream& os, FmtFlags flags, TokenBounds x) {
    pr_debug(os, flags, IntPair(x.lo_, x.hi_));
}

struct CommentMap {
    Vec_T<pair<StrSlice, Int>> items_;
    inline CommentMap() : items_(make_rc<Vec<pair<StrSlice, Int>>>()) {}
};

struct LexError: enable_rc_from_this<LexError> {
    LexInput_T in_;
    Int i_;
    string desc_;

    inline static LexError_T make(LexInput_T in, Int i, string desc) {
        auto ret = make_rc<LexError>();
        ret->in_ = in;
        ret->i_ = i;
        ret->desc_ = desc;
        return ret;
    }
};

inline void pr(ostream& os, FmtFlags flags, LexError_T err) {
    fmt(os, "{}", err->desc_);
}

struct LineMap: enable_rc_from_this<LineMap> {
    Vec<Int> lines_start_pos_;

    inline Int num_lines() {
        return len(lines_start_pos_);
    }
};
using LineMap_T = rc_ptr<LineMap>;

static constexpr Ch NO_CHAR = Ch(-1);

struct LexInput: enable_rc_from_this<LexInput> {
    Str_T input_;
    Vec<Ch> data_;
    Vec<i32> char_pos_;
    Int data_len_;
    LineMap_T line_map_;
    Option_T<LexError_T> err_;

    inline static LexInput_T make_from_str(const Str_T& x) {
        auto line_map = make_rc<LineMap>();
        auto ret = make_rc<LexInput>();
        ret->input_ = x;
        ret->line_map_ = line_map;
        ret->err_ = None<LexError_T>();

        Int n = x->length();
        Int ret_n = 0;

        ret->data_.reserve_unchecked(2*(n+1));
        ret->char_pos_.reserve_unchecked(2*(n+1));
        ret->data_.adjust_len_inplace_unchecked(n+1);
        ret->char_pos_.adjust_len_inplace_unchecked(n+1);

        auto ret_data_buf = &ret->data_.at_unchecked(0);
        auto ret_char_pos_buf = &ret->char_pos_.at_unchecked(0);

        const char* x_str = x->begin();

        line_map->lines_start_pos_.push(0);

        Int i = 0;

        while (i < n) {
            auto ch = x_str[i];
            auto ch_full = static_cast<Ch>(ch);

            ret_char_pos_buf[ret_n] = i;

            if (__builtin_expect(ch < 0, 0)) {
                Int i_new = i;
                ch_full = lex_decode_utf8(x_str, i_new, n);
                i = i_new;

                if (ch_full == -1) {
                    auto utf8_err = Some(LexError::make(
                        ret, len(ret->data_), "UTF-8 decoding error"));
                    ret->err_ = utf8_err;
                    return ret;
                }

                if (ch_full == 0xfeff) {
                    // byte-order marker
                    ++i;
                    continue;
                }
            }

            ret_data_buf[ret_n++] = ch_full;

            if (ch == '\n') {
                line_map->lines_start_pos_.push(ret_n);
            }

            ++i;
        }

        ret_char_pos_buf[ret_n] = n;

        ret->data_[ret_n] = NO_CHAR;  // NOTE: used by lexer runtime (accesses raw buffer)

        ret->data_.adjust_len_inplace_unchecked(ret_n);
        ret->data_len_ = ret_n;

        ret->char_pos_.adjust_len_inplace_unchecked(ret_n + 1);

        return ret;
    }

    IntPair line_bounds(Int line_index) {
        const auto& sp = line_map_->lines_start_pos_;
        auto sp_lo = sp[line_index];
        auto sp_hi = data_.length();
        if (line_index+1 < sp.length()) {
            sp_hi = sp[line_index+1] - 1;
        }
        return make_pair(sp_lo, sp_hi);
    }

    Int pos_resolve_line(Int pos) {
        AR_ge(pos, 0);
        AR_le(pos, data_.length());

        const auto& sp = line_map_->lines_start_pos_;
        Int i;
        for (i = 1; i < sp.length(); i++) {
            if (sp[i] > pos) {
                break;
            }
        }
        --i;
        auto [sp_lo, sp_hi] = this->line_bounds(i);
        AR_ge(pos, sp_lo);
        AR_le(pos, sp_hi);
        return i;
    }

    string location_fmt_str(Int pos_lo, Int pos_hi) {
        auto pos_lo_line = this->pos_resolve_line(pos_lo);
        auto [pos_lo_line_a, _] = this->line_bounds(pos_lo_line);
        auto pos_hi_line = this->pos_resolve_line(pos_hi);

        ostringstream os;
        os << "Line " << (pos_lo_line+1) << ", column " << (pos_lo - pos_lo_line_a + 1) << ":\n\n";
        Int n_non_sp_prev = 0;
        for (Int line = pos_lo_line; line <= pos_hi_line; line++) {
            Int disp = 2;
            if (line >= pos_lo_line + disp && line <= pos_hi_line - disp) {
                if (line == pos_lo_line + disp) {
                    os << "  ";
                    for (Int r = 0; r < n_non_sp_prev; r++) {
                        os << " ";
                    }
                    os << "...\n";
                }
                continue;
            }

            bool seen_non_sp = false;
            n_non_sp_prev = 0;

            os << "  ";
            auto [sp_lo, sp_hi] = this->line_bounds(line);
            for (Int j = sp_lo; j < sp_hi; j++) {
                os << utf8_encode(data_[j]);
            }
            os << "\n  ";
            for (Int j = sp_lo; j <= sp_hi; j++) {
                if (j < sp_hi && data_[j] != static_cast<Ch>(' ') &&
                    data_[j] != static_cast<Ch>('\t')) {
                    if (!seen_non_sp) {
                        n_non_sp_prev = j - sp_lo;
                    }
                    seen_non_sp = true;
                }

                if (j == pos_lo) {
                    os << "^";
                } else if (j > pos_lo && j < pos_hi && j < sp_hi && seen_non_sp) {
                    os << "~";
                } else {
                    if (j < sp_hi && data_[j] == static_cast<Ch>('\t')) {
                        os << "\t";
                    } else {
                        os << " ";
                    }
                }
            }
            os << "\n";
        }
        return os.str();
    }

    // NOTE: u8 offsets as input
    inline StrSlice fetch_string_site(Int ind_lo, Int ind_hi) {
        return StrSlice(input_, ind_lo, ind_hi);
    }

    LexError_T lex_error_val(string desc, Int pos) {
        auto err_str = desc + "\n" + this->location_fmt_str(pos, pos);
        return LexError::make(rc_from_this(), pos, err_str);
    }
};

inline void pr(ostream& os, FmtFlags flags, LexInput_T lex) {
    fmt(os, "LexInput: `{}`", vec_to_std_string(lex->input_));
}

inline LexOutput_T LexOutput::make_text(LexInput_T in) {
    auto ret = make_rc<LexOutput>();
    ret->quoted_ = false;

    ret->items_internal_ = make_rc<Vec<SymItem>>();
    ret->items_internal_->reserve_unchecked(65536);
    ret->err_ = None<LexError_T>();

    ret->in_ = Some<LexInput_T>(in);
    ret->comment_map_ = Some<CommentMap_T>(make_rc<CommentMap>());

    ret->str_input_ = None<Str_T>();
    ret->str_input_char_pos_ = None<Vec_T<i32>>();
    ret->nodes_alloc_ = None<Vec_T<rc_ptr<NodeAllocDecrefInterface>>>();
    return ret;
}

inline LexOutput_T LexOutput::make_quoted() {
    auto ret = make_rc<LexOutput>();
    ret->quoted_ = true;

    ret->items_internal_ = make_rc<Vec<SymItem>>();
    ret->items_internal_->reserve_unchecked(65536);
    ret->err_ = None<LexError_T>();

    ret->in_ = None<LexInput_T>();
    ret->comment_map_ = None<CommentMap_T>();

    ret->str_input_ = Some<Str_T>(make_rc<Str>());
    ret->str_input_char_pos_ = Some<Vec_T<i32>>(make_rc<Vec<i32>>());
    ret->nodes_alloc_ = Some<Vec_T<rc_ptr<NodeAllocDecrefInterface>>>(
        make_rc<Vec<rc_ptr<NodeAllocDecrefInterface>>>());
    return ret;
}

inline IntPair LexOutput::lookup_pos(Int tok_i) {
    AT(!quoted_, "lookup_pos");

    auto pos = make_pair(
        in_.as_some()->data_len_, in_.as_some()->data_len_);
    if (tok_i == -1) {
        pos = make_pair(0, 0);
    } else if (tok_i < items_internal_->length()) {
        pos = make_pair(
            items_internal_->operator[](tok_i).tok_in_lo_,
            items_internal_->operator[](tok_i).tok_in_hi_);
    }
    return pos;
}

inline StrSlice LexOutput::fetch_token(Int tok_i) {
    if (__builtin_expect(quoted_, 0)) {
        Int char_lo = items_internal_->operator[](tok_i).tok_in_lo_;
        Int char_hi = items_internal_->operator[](tok_i).tok_in_hi_;
        i32 u8_lo = str_input_char_pos_.as_some()->operator[](char_lo);
        i32 u8_hi = str_input_char_pos_.as_some()->operator[](char_hi);
        return StrSlice(str_input_.as_some(), u8_lo, u8_hi);
    }
    Int char_lo = items_internal_->operator[](tok_i).tok_in_lo_;
    Int char_hi = items_internal_->operator[](tok_i).tok_in_hi_;
    i32 u8_lo = in_.as_some()->char_pos_.at_unchecked(char_lo);
    i32 u8_hi = in_.as_some()->char_pos_.at_unchecked(char_hi);
    return in_.as_some()->fetch_string_site(u8_lo, u8_hi);
}

inline bool LexOutput::allows_quoted_symbols() {
    return quoted_;
}

inline string LexOutput::location_fmt_str(TokenBounds bounds) {
    if (quoted_) {
        string ret;
        Int tok_i_curr = 0;
        bool fresh = true;
        for (auto item : *this->items_internal_) {
            if (!fresh) {
                ret += " ";
            }
            fresh = false;
            if (tok_i_curr == bounds.lo_) {
                ret += "__##__ ";
            }
            if (item.tok_ == NO_TOKEN) {
                ret += "<QQ>";
            } else {
                auto s = this->fetch_token(tok_i_curr).to_std_string();
                ret += fmt_str("`{}`", s);
            }
            ++tok_i_curr;
        }
        return ret;
    }

    auto [pos_lo, _] = this->lookup_pos(bounds.lo_);
    auto [__, pos_hi] = this->lookup_pos(bounds.hi_ - 1);
    return in_.as_some()->location_fmt_str(pos_lo, pos_hi);
}

inline bool LexOutput::is_success() {
    return err_.is_none();
}

inline ParserLookahead LexOutput::first_k(Int lr_k) {
    if (__builtin_expect(quoted_, 0)) {
        ParserLookahead ret;
        Int item_i = 0;
        Int la_j = 0;
        while (la_j < lr_k && item_i < items_internal_->length()) {
            if (items_internal_->operator[](item_i).tok_ == NO_TOKEN) {
                Int r = 0;
                while (la_j < lr_k) {
                    auto la_item_curr = items_internal_->operator[](item_i).first_k_.v_[r];
                    if (la_item_curr == 0) {  // EndMarker
                        break;
                    }
                    ret.v_[la_j] = la_item_curr;
                    ++la_j;
                    ++r;
                }
                ++item_i;
            } else {
                ret.v_[la_j] = items_internal_->operator[](item_i).id_;
                ++la_j;
                ++item_i;
            }
        }
        while (la_j < lr_k) {
            ret.v_[la_j] = 0;  // EndMarker
            ++la_j;
        }
        return ret;
    }

    AR_le(lr_k, PARSER_LOOKAHEAD_LEN_MAX);
    ParserLookahead ret;
    Int item_i = 0;
    Int la_j = 0;
    while (la_j < lr_k && la_j < items_internal_->length()) {
        ret.v_[la_j] = items_internal_->operator[](item_i).id_;
        ++la_j;
        ++item_i;
    }
    while (la_j < lr_k) {
        ret.v_[la_j] = 0;  // EndMarker
        ++la_j;
    }
    return ret;
}

inline void LexOutput::clear_alloc() {
    if (quoted_) {
        for (auto x : *nodes_alloc_.as_some()) {
            x->decref_contents();
        }
    }
}

inline void LexOutput::push_item(SymItem item) {
    Int tok_i_curr = this->items_internal_->length();
    item.start_pos_ = tok_i_curr;
    item.res_.bounds_.lo_ = tok_i_curr;
    item.res_.bounds_.hi_ = tok_i_curr + 1;
    this->items_internal_->push(item);
}

inline void pr_debug(ostream& os, FmtFlags flags, LexOutput_T lex) {
    if (lex->quoted_) {
        os << "LexOutput(quoted):[";
        Int tok_i = 0;
        bool fresh = true;
        for (auto item : *lex->items_internal_) {
            if (!fresh) {
                fmt(os, " ");
            }
            fresh = false;
            if (item.tok_ == NO_TOKEN) {
                fmt(os, "<Q>");
            } else {
                auto s = lex->fetch_token(tok_i).to_std_string();
                fmt(os, "`{}`", s);
            }
            ++tok_i;
        }
        fmt(os, "]");
        return;
    }

    os << "LexOutput:[";
    Int tok_i = 0;
    bool fresh = true;
    for (auto item : *lex->items_internal_) {
        if (!fresh) {
            fmt(os, " ");
        }
        fresh = false;
        fmt(os, "{}(", item.id_);
        auto s = lex->fetch_token(tok_i).to_std_string();
        fmt(os, "`{}`", s);
        fmt(os, ")");
        ++tok_i;
    }
    fmt(os, "]");
}

inline void pr(ostream& os, FmtFlags flags, LexOutput_T lex) {
    pr_debug(os, flags, lex);
}

constexpr Int CMP_LT = -1;
constexpr Int CMP_EQ = 0;
constexpr Int CMP_GT = 1;
constexpr Int CMP_INCOMP = -2;

inline Int ws_compare(const Vec<Ch>& a, const Vec<Ch>& b) {
    Int i = 0;
    while (true) {
        if (i >= a.length() && i >= b.length()) {
            return CMP_EQ;
        } else if (i >= a.length()) {
            return CMP_LT;
        } else if (i >= b.length()) {
            return CMP_GT;
        } else if (a[i] == b[i]) {
            i += 1;
            continue;
        } else {
            return CMP_INCOMP;
        }
    }
}

namespace DFATable {
    static constexpr DFAActionId NO_ACTION = -1;

    static constexpr DFAVertexId NO_VERTEX = -1;

    static constexpr DFALabelId EOF_LABEL = 0;
    static constexpr DFALabelId NO_LABEL = -1;

    static constexpr Int NEW_MODE_NONE = -1;
    static constexpr Int NEW_MODE_POP = -2;
    static constexpr Int NEW_MODE_POP_EMIT = -3;
    static constexpr Int NEW_MODE_POP_EXTRACT = -4;
};

RC_STRUCT(LexerModeDesc); 
RC_STRUCT(LexerState);

using LexerStateRef = LexerState_T&;

struct LexerModeDesc: enable_rc_from_this<LexerModeDesc> {
    Int (*proc_mode_loop_opt_fn_)(
        LexerModeDesc* mode, LexerState* st, SymItemVec* emit_dst,
        Int mode_start_pos, Int mode_buf_pos);

    LexerStepFn step_fn_;
    LexerAccFn acc_fn_;
    LexerStepExecFn step_exec_fn_;

    bool ws_sig_;
    Int ws_newline_ind_;
    Int ws_indent_ind_;
    Int ws_dedent_ind_;
    Int ws_err_mixed_indent_ind_;
    Int ws_err_text_after_lc_ind_;
    Int ws_err_delim_mismatch_ind_;
};

struct LexerState: enable_rc_from_this<LexerState> {
    Vec_T<LexerModeDesc_T> mode_descs_;
    rc_ptr<DFALabelIdVec> label_ids_ascii_;
    rc_ptr<DFALabelIdMap> label_ids_unicode_;

    LexerModeId main_mode_;
    LexInput_T in_;
    LexOutput_T out_;

    TermTokToSymFn tok_to_sym_;

    bool consumed_;

    inline static LexerState_T make(TermTokToSymFn tok_to_sym,
        rc_ptr<DFALabelIdVec> label_ids_ascii,
        rc_ptr<DFALabelIdMap> label_ids_unicode,
        Vec_T<LexerModeDesc_T> mode_descs, LexerModeId main_mode, LexInput_T in) {

        auto ret = make_rc<LexerState>();
        ret->tok_to_sym_ = tok_to_sym;
        ret->mode_descs_ = mode_descs;
        ret->label_ids_ascii_ = label_ids_ascii;
        ret->label_ids_unicode_ = label_ids_unicode;
        ret->main_mode_ = main_mode;
        ret->in_ = in;
        ret->out_ = LexOutput::make_text(in);
        ret->consumed_ = false;
        return ret;
    }

    inline TokenId last_tok() {
        if (__builtin_expect(out_->items_internal_->length() == 0, 0)) {
            return NO_TOKEN;
        }
        auto& item = out_->items_internal_->at_unchecked(out_->items_internal_->length() - 1);
        return item.tok_;
    }

    inline void error_here_match_history(Int in_i) {
        throw this->in_->lex_error_val("Unexpected match history item", in_i);
    }

    inline __attribute__((always_inline)) void enqueue_emit_ext(
        Vec<SymItem>* dst, LexWhitespaceState* ws, TokenId tok, Int tok_lo, Int tok_hi,
        bool has_contents) {

        auto item = SymItem::make_lex_token(tok, tok_to_sym_, tok_lo, tok_hi);
        if (!!dst) {
            dst->push(item);
        } else {
            this->out_->push_item(item);
        }
    }

    inline void extract_comment(Int tok_lo, Int tok_hi) {
        auto tok_str = this->in_->fetch_string_site(tok_lo, tok_hi);
        out_->comment_map_.as_some()->items_->push(make_pair(tok_str, tok_lo));
    }
};

struct LexWhitespaceState {
    LexerState* st_;

    TermTokToSymFn tok_to_sym_;

    Ch* input_data_;
    Int scan_i_;
    Vec<Ch> delim_stack_;
    bool ws_buf_is_line_start_;
    bool ws_buf_is_lc_curr_;
    Vec_T<Ch> ws_buf_curr_;
    Vec<Vec_T<Ch>> ws_buf_stack_;

    TokenId tok_id_newline_;
    TokenId tok_id_indent_;
    TokenId tok_id_dedent_;
    TokenId tok_id_err_incons_;
    TokenId tok_id_err_text_after_lc_;
    TokenId tok_id_err_delim_mismatch_;

    constexpr static Int NO_ERR = -1;

    inline LexWhitespaceState(
        LexerState* st,
        TermTokToSymFn tok_to_sym,
        Int buf_pos, Ch* input_data,
        TokenId tok_id_newline, TokenId tok_id_indent, TokenId tok_id_dedent,
        TokenId tok_id_err_incons, TokenId tok_id_err_text_after_lc,
        TokenId tok_id_err_delim_mismatch) {

        st_ = st;

        tok_to_sym_ = tok_to_sym;

        scan_i_ = buf_pos;
        input_data_ = input_data;
        ws_buf_is_line_start_ = true;
        ws_buf_is_lc_curr_ = false;

        tok_id_newline_ = tok_id_newline;
        tok_id_indent_ = tok_id_indent;
        tok_id_dedent_ = tok_id_dedent;
        tok_id_err_incons_ = tok_id_err_incons;
        tok_id_err_text_after_lc_ = tok_id_err_text_after_lc;
        tok_id_err_delim_mismatch_ = tok_id_err_delim_mismatch;

        ws_buf_curr_ = make_rc<Vec<Ch>>();
        ws_buf_stack_.push(make_rc<Vec<Ch>>());
    }

    inline void dst_gen_push_item(SymItemVec* dst, SymItem item) {
        if (!!dst) {
            dst->push(item);
        } else {
            st_->out_->push_item(item);
        }
    }

    inline void jump_update(Int i) {
        scan_i_ = i;
    }

    inline bool active() {
        return delim_stack_.length() == 0;
    }

    inline void flush_buf(Int pos, SymItemVec* dst) {
        bool dedented = false;
        bool err_mismatch = false;
        bool err_incomp = false;

        Vec<SymItem> ret;

        while (true) {
            AR_ge(ws_buf_stack_.length(), 1);
            auto& buf_ref = ws_buf_stack_.back();
            auto cmp = ws_compare(*ws_buf_curr_, *buf_ref);

            if (cmp == CMP_LT) {
                ret.push(SymItem::make_lex_token(tok_id_dedent_, tok_to_sym_, pos, pos));
                ws_buf_stack_.pop();
                dedented = true;
                continue;
            } else if (cmp == CMP_EQ) {
                break;
            } else if (cmp == CMP_GT) {
                if (dedented) {
                    err_mismatch = true;
                    break;
                } else {
                    ret.push(SymItem::make_lex_token(tok_id_indent_, tok_to_sym_, pos, pos));
                    ws_buf_stack_.push(ws_buf_curr_->clone_rc());
                    break;
                }
            } else if (cmp == CMP_INCOMP) {
                err_incomp = true;
                break;
            } else {
                AX();
            }
        }

        if (err_mismatch || err_incomp) {
            this->dst_gen_push_item(
                dst, SymItem::make_lex_token(tok_id_err_incons_, tok_to_sym_, pos, pos));
            return;
        }

        for (auto ret_i : ret) {
            this->dst_gen_push_item(dst, ret_i);
        }
    }

    inline void finish(Int pos, SymItemVec* dst) {
        if (!this->active()) {
            return;
        }

        if (!ws_buf_is_line_start_) {
            this->dst_gen_push_item(
                dst, SymItem::make_lex_token(tok_id_newline_, tok_to_sym_, pos, pos));
            this->flush_buf(pos, dst);
        }

        while (ws_buf_stack_.length() > 1) {
            this->dst_gen_push_item(
                dst, SymItem::make_lex_token(tok_id_dedent_, tok_to_sym_, pos, pos));
            ws_buf_stack_.pop();
        }
    }

    inline void delim_update(Ch ch, SymItemVec* dst) {
        if (ch == '(' || ch == '[' || ch == '{') {
            delim_stack_.push(ch);
            return;
        }
        if (ch == ')' && delim_stack_.length() > 0 && delim_stack_.back() == '(') {
            delim_stack_.pop();
            return;
        }
        if (ch == ']' && delim_stack_.length() > 0 && delim_stack_.back() == '[') {
            delim_stack_.pop();
            return;
        }
        if (ch == '}' && delim_stack_.length() > 0 && delim_stack_.back() == '{') {
            delim_stack_.pop();
            return;
        }
        if (ch == ')' || ch == ']' || ch == '}') {
            this->dst_gen_push_item(
                dst, SymItem::make_lex_token(
                    tok_id_err_delim_mismatch_, tok_to_sym_, scan_i_, scan_i_+1));
        }
    }

    inline void non_ws_token(SymItemVec* dst) {
        if (ws_buf_is_lc_curr_) {
            this->dst_gen_push_item(
                dst, SymItem::make_lex_token(
                    tok_id_err_text_after_lc_, tok_to_sym_, scan_i_, scan_i_));
        }

        if (ws_buf_is_line_start_) {
            this->flush_buf(scan_i_, dst);
            ws_buf_is_line_start_ = false;
        }
    }

    inline void scan_update(Int tok_hi, SymItemVec* dst) {
        AR_le(scan_i_, tok_hi);

        while (scan_i_ < tok_hi) {
            Ch c = input_data_[scan_i_];

            if (!this->active()) {
                this->delim_update(c, dst);
                scan_i_ += 1;
                continue;
            }

            auto is_ws = (c == ' ' || c == '\t' || c == '\n' || c == '\r' || c == '\x0c');
            auto is_lc = (c == '\\');

            if (is_ws && (c != '\n')) {
                if (ws_buf_is_line_start_) {
                    if (c != '\r' && c != '\x0c') {
                        ws_buf_curr_->push(c);
                    }
                }

            } else if (is_ws && (c == '\n')) {
                if (!ws_buf_is_lc_curr_) {
                    if (!ws_buf_is_line_start_) {
                        this->dst_gen_push_item(dst,
                            SymItem::make_lex_token(
                                tok_id_newline_, tok_to_sym_, scan_i_, scan_i_+1));
                    }
                    ws_buf_curr_->clear();
                    ws_buf_is_line_start_ = true;
                }
                ws_buf_is_lc_curr_ = false;

            } else if (!is_ws) {
                this->delim_update(c, dst);

                if (is_lc) {
                    ws_buf_is_lc_curr_ = true;
                    if (ws_buf_is_line_start_) {
                        ws_buf_curr_->clear();
                    }
                }
            }

            scan_i_ += 1;
        }
    }

    inline void consume(Int tok_lo, Int tok_hi, SymItemVec* dst) {
        this->jump_update(tok_lo);
        this->scan_update(tok_hi, dst);
    }
};

inline void lex_queue_pull_sub(LexerState* st,
    SymItemVec* dst, SymItemVec* src,
    LexWhitespaceState* ws_state) {

    if (__builtin_expect(!!ws_state, 0)) {
        if (src->length() != 0) {
            ws_state->non_ws_token(dst);
        }
    }

    for (auto item : *src) {
        if (!!dst) {
            dst->push(item);
        } else {
            st->out_->push_item(item);
        }
    }
    src->clear();
}

inline __attribute__((always_inline)) void lexer_raise_nonempty_mode_stack(
    LexerState* st, Int in_i) {

    AX("Lexer definition error: nonempty mode stack at eof");
}

inline __attribute__((always_inline)) void lexer_raise_unexpected_eof(
    LexerState* st, Int in_i) {

    throw st->in_->lex_error_val("Unexpected end-of-file", in_i);
}

inline __attribute__((always_inline)) DFALabelId lexer_char_to_label(
    Ch* in_data, Int in_i, Int in_data_len,
    DFALabelId* label_ids_ascii,
    LexerState* st) {

    Ch c = in_data[in_i];

    DFALabelId cl;
    if (__builtin_expect(c <= Ch(0x7f), 1)) {
        cl = label_ids_ascii[static_cast<Int>(c)];
    } else {
        if (c == NO_CHAR) {  // NOTE: c is unsigned, so NO_CHAR is not <= 0x7f
            cl = DFATable::EOF_LABEL;
        } else {
            auto it = st->label_ids_unicode_->upper_bound(c);
            --it;
            cl = it->second;
        }
    }

    if (__builtin_expect(cl == DFATable::NO_LABEL, 0)) {
        throw st->in_->lex_error_val(
            fmt_str("Invalid character: {}", char_display(c)), in_i);
    }

    return cl;
}

inline __attribute__((always_inline)) void lexer_state_proc_update_pre(
    Int best_acc, Int best_tok,
    Int& tok_lo, Int& tok_hi, Int& in_i,
    bool read_eof, LexerState* st) {

    if (__builtin_expect(best_acc == DFATable::NO_ACTION, 0)) {
        throw st->in_->lex_error_val("Invalid token", in_i);
    }
}

inline __attribute__((always_inline)) void lexer_state_eof_fail(Int& in_i, LexerState* st) {
    throw st->in_->lex_error_val("Unexpected end-of-file", in_i);
}

inline __attribute__((always_inline)) Int lexer_proc_mode_loop(LexerModeDesc* mode,
    Ptr<lang_rt::LexerState> st, lang_rt::SymItemVec* emit_dst, Int mode_start_pos,
    Int mode_buf_pos) {

    return mode->proc_mode_loop_opt_fn_(mode, st, emit_dst, mode_start_pos, mode_buf_pos);
}

template<LANG_META_PARAMS>
inline LexOutput_T LangDesc<LANG_META_ARGS>::lex(const Str_T& input, Arena* A) {
    AT(input->length() < 0x7fffffff);

    auto in = LexInput::make_from_str(input);

    auto st = LexerState::make(parser_desc_->term_tok_to_sym_,
        label_ids_ascii_, label_ids_unicode_,
        lexer_mode_descs_, lexer_main_mode_, in);

    AT(this->rc_from_this().v_ != nullptr);

    Int pos = -1;
    try {
        auto desc = st->mode_descs_->operator[](st->main_mode_);
        pos = desc->proc_mode_loop_opt_fn_(desc.get(), st.get(), nullptr, 0, 0);
    } catch (LexError_T err) {
        st->out_->err_ = Some<LexError_T>(err);
    }

    if (st->out_->err_.is_none()) {
        if (pos < st->in_->data_len_) {
            st->out_->err_ = Some(
                st->in_->lex_error_val(
                    "Lexer definition error: empty mode stack before eof", pos));
        }
    }

    return st->out_;
}

inline __attribute__((noinline)) Ch lex_decode_utf8(const char* x, Int& i, Int n) {
    char ch = x[i];
    Ch ch_full = 0;
    if ((ch & 0xe0) == 0xc0) {
        // length 2
        if (i+1 >= n) {
            return -1;
        }

        auto ch1 = x[++i];
        if ((ch1 & 0xc0) != 0x80) {
            return -1;
        }
        ch_full |= (ch & 0x1f);
        ch_full <<= 6;
        ch_full |= (ch1 & 0x3f);

    } else if ((ch & 0xf0) == 0xe0) {
        // length 3
        if (i+2 >= n) {
            return -1;
        }
        auto ch1 = x[++i];
        if ((ch1 & 0xc0) != 0x80) {
            return -1;
        }
        auto ch2 = x[++i];
        if ((ch2 & 0xc0) != 0x80) {
            return -1;
        }
        ch_full |= (ch & 0x0f);
        ch_full <<= 6;
        ch_full |= (ch1 & 0x3f);
        ch_full <<= 6;
        ch_full |= (ch2 & 0x3f);

    } else if ((ch & 0xf8) == 0xf0) {
        // length 4
        if (i+3 >= n) {
            return -1;
        }
        auto ch1 = x[++i];
        if ((ch1 & 0xc0) != 0x80) {
            return -1;
        }
        auto ch2 = x[++i];
        if ((ch2 & 0xc0) != 0x80) {
            return -1;
        }
        auto ch3 = x[++i];
        if ((ch3 & 0xc0) != 0x80) {
            return -1;
        }
        ch_full |= (ch & 0x07);
        ch_full <<= 6;
        ch_full |= (ch1 & 0x3f);
        ch_full <<= 6;
        ch_full |= (ch2 & 0x3f);
        ch_full <<= 6;
        ch_full |= (ch3 & 0x3f);

    } else {
        return -1;
    }

    return ch_full;
}





////////////////////////////////////////////////////////////////////////////////
// Parser
////////////////////////////////////////////////////////////////////////////////

inline void pr_debug(ostream& os, FmtFlags flags, ParserAttrMask x) {
    pr_debug(os, flags, x.v_);
}

inline void pr_debug(ostream& os, FmtFlags flags, ParserLookahead x) {
    pr_debug(os, flags, x.v_);
}

inline void hash_ser(SerBuf& buf, const ParserAttrMask& x) {
    ser_bytes(buf, 16, x.v_);
}

inline void hash_ser(SerBuf& buf, const ParserLookahead& x) {
    ser_bytes(buf, 16, reinterpret_cast<const u8*>(x.v_));
}

struct ParserVertexStackItem {
    ParserVertexId v_;
    Int pos_;
};

struct ParseError;
using ParseError_T = rc_ptr<ParseError>;

struct ParseError: enable_rc_from_this<ParseError> {
    Option_T<LexOutput_T> lex_;
    Option_T<LexError_T> lex_err_;
    Option_T<Int> tok_i_;
    string desc_;

    inline static ParseError_T make(LexOutput_T lex, Int tok_i, string desc) {
        auto ret = make_rc<ParseError>();
        ret->lex_ = Some<LexOutput_T>(lex);
        ret->lex_err_ = None<LexError_T>();
        ret->tok_i_ = Some<Int>(tok_i);
        ret->desc_ = desc;
        return ret;
    }

    inline static ParseError_T make_from_lex_error(LexError_T lex_err) {
        auto ret = make_rc<ParseError>();
        ret->lex_ = None<LexOutput_T>();
        ret->lex_err_ = Some<LexError_T>(lex_err);
        ret->tok_i_ = None<Int>();
        ret->desc_ = lex_err->desc_;
        return ret;
    }
};

inline void pr(ostream& os, FmtFlags flags, lang_rt::ParseError_T err) {
    if (err->lex_err_.is_some()) {
        pr(os, flags, err->lex_err_.as_some());
        return;
    }
    auto err_str = err->desc_ + "\n" +
        err->lex_.as_some()->location_fmt_str(
            lang_rt::TokenBounds(err->tok_i_.as_some(), err->tok_i_.as_some()+1));
    os << err_str;
}

struct ParserProcState {
    LexOutput_T lex_res_;

    ParserProcXform* desc_proc_xform_;

    ParserVertexStackItem* Sv_addr_;
    Int Sv_len_;

    SymItem* Ss_addr_;
    Int Ss_len_;

    Result_T* Sr_addr_;
    Int Sr_len_;

    Result_T* Sb_addr_;
    Int Sb_len_;

    SymItem sym_final_;

    Gensym* unw_gen_;
    Arena* unw_arena_;

    inline __attribute__((noinline)) void destroy_arrays() {
        free_ext(this->Sv_addr_, this->unw_arena_);
        free_ext(this->Ss_addr_, this->unw_arena_);
        free_ext(this->Sr_addr_, this->unw_arena_);
        free_ext(this->Sb_addr_, this->unw_arena_);
    }

    inline __attribute__((always_inline)) StrSlice fetch_token(Int tok_i) {
        return lex_res_->fetch_token(tok_i);
    }

    inline __attribute__((always_inline)) Gensym* gen() {
        return unw_gen_;
    }

    inline __attribute__((always_inline)) Arena* arena() {
        return unw_arena_;
    }

    inline __attribute__((always_inline)) void enroll_final_sym(SymItem sym) {
        sym_final_ = sym;
    }

    inline __attribute__((always_inline)) ParserProcXform* desc_proc_xform() {
        return desc_proc_xform_;
    }
};

enum struct ParserActionData_W {
    NONE,
    REDUCE,
    RECUR,
    RET,
    SHIFT,
};

inline ParserLookahead parser_lookahead_trivial() {
    return ParserLookahead();
}

inline ParserAttrMask attr_mask_trivial() {
    ParserAttrMask ret;
    return ret;
}

template<LANG_META_PARAMS> struct ParseOutput;
template<LANG_META_PARAMS> using ParseOutput_T = rc_ptr<ParseOutput<LANG_META_ARGS>>;

inline void pr(ostream& os, FmtFlags flags, ParserAttrMask attr) {
    fmt(os, "{{");
    for (Int i = 0; i < 8; i++) {
        fmt(os, "{},", Int(attr.v_[i]));
    }
    fmt(os, "..}}");
}

inline void pr(ostream& os, FmtFlags flags, ParserLookahead la) {
    fmt(os, "{{");
    for (Int i = 0; i < 8; i++) {
        fmt(os, "{},", Int(la.v_[i]));
    }
    fmt(os, "}}");
}

__attribute__((always_inline)) inline SymItem parser_proc_sym_at(
    Int j, ParserDesc* desc_raw, SymItem* lex_out_items, Int n_lex_out_items,
    const string& sym_target) {

    if (EXPENSIVE_ASSERT) AR_ge(j, -1);

    if (__builtin_expect(j == -1, 0)) {
        auto ret_sym = desc_raw->start_marker_by_name_.at(sym_target);
        return SymItem::make_lex_token_parse_sym(NO_TOKEN, ret_sym, -1, -1, -1);
    }

    if (__builtin_expect(j >= n_lex_out_items, 0)) {
        auto ret_sym = desc_raw->right_end_marker_;
        return SymItem::make_lex_token_parse_sym(NO_TOKEN, ret_sym, j, -1, -1);
    }

    auto lex_item = lex_out_items[j];
    return lex_item;
}

inline string parser_format_sym(ParserDesc* desc_raw, ParserSymId sym, ParserAttrMask attr) {
    AT(!!desc_raw, "desc_raw");
    AT(!!desc_raw->sym_to_debug_string_, "desc_raw sym_to_debug_string");
    AT(!!desc_raw->attr_to_debug_string_, "desc_raw attr_to_debug_string");
    AT(!!desc_raw->sym_to_num_attrs_, "desc_raw sym_to_num_attrs");

    auto sym_str = desc_raw->sym_to_debug_string_(sym);
    auto n_attr = desc_raw->sym_to_num_attrs_(sym);
    auto attr_strs = make_rc<Vec<string>>();
    for (Int i = 0; i < n_attr; i++) {
        if (attr.v_[i] == PARSER_ATTR_MASK_SENTINEL) {
            AX();
        }
        auto attr_str = desc_raw->attr_to_debug_string_(sym, i);
        bool is_prec = (attr_str == "prL" || attr_str == "prR");
        if (attr.v_[i] == 0 && !is_prec) {
            continue;
        }
        if (is_prec) {
            attr_strs->push_back(fmt_str("{}={}", attr_str, attr.v_[i]));
        } else {
            AT(attr.v_[i] == 1);
            attr_strs->push_back(attr_str);
        }
    }
    auto ret = sym_str;
    if (attr_strs->length() == 0) {
        return ret;
    }
    ret += "[";
    bool fresh = true;
    for (auto attr_str : *attr_strs) {
        if (!fresh) {
            ret += ",";
        }
        fresh = false;
        ret += attr_str;
    }
    ret += "]";
    return ret;
}

template<LANG_META_PARAMS>
inline ParseOutput_T<LANG_META_ARGS> ParseOutput<LANG_META_ARGS>::make_success(
    LexOutput_T lex, ParserSymId sym_final, ParserAttrMask attr_final,
    rc_ptr<Node> res, Int num_steps) {

    auto ret = make_rc<ParseOutput<LANG_META_ARGS>>();
    ret->lex_ = lex;
    ret->sym_final_ = sym_final;
    ret->attr_final_ = attr_final;
    ret->res_ = Some<rc_ptr<Node>>(res);
    ret->err_ = None<ParseError_T>();
    ret->num_steps_ = num_steps;
    return ret;
}

template<LANG_META_PARAMS>
inline ParseOutput_T<LANG_META_ARGS> ParseOutput<LANG_META_ARGS>::make_error(
    LexOutput_T lex, ParseError_T err) {

    auto ret = make_rc<ParseOutput<LANG_META_ARGS>>();
    ret->lex_ = lex;
    ret->res_ = None<rc_ptr<Node>>();
    ret->err_ = Some<ParseError_T>(err);
    ret->num_steps_ = -1;
    return ret;
}

template<LANG_META_PARAMS>
__attribute__((always_inline)) inline ParseOutput_T<LANG_META_ARGS>
    parse_error_output_here(string desc, Int st_i, LexOutput_T lex_) {

    auto in_i = st_i;
    if (in_i < 0) {
        AT(in_i == -1);
        in_i = 0;
    }
    auto err = ParseError::make(lex_, in_i, desc);
    return ParseOutput<LANG_META_ARGS>::make_error(lex_, err);
}

template<typename T>
inline __attribute__((always_inline)) void parse_rt_check_realloc(
    T** addr, Int len, Int* cap, Arena* A) {

    Int cap_prev = *cap;

    if (__builtin_expect(len > cap_prev, 0)) {
        T* addr_prev = *addr;
        Int cap_new = cap_prev * 4;
        *cap = cap_new;
        auto addr_new = reinterpret_cast<T*>(malloc_ext(cap_new * sizeof(T), A));
        memcpy(addr_new, addr_prev, cap_prev * sizeof(T));
        *addr = addr_new;
        free_ext(addr_prev, A);
    }
}

template<LANG_META_PARAMS> template<bool LR_K1, bool NO_QUOTE>
inline ParseOutput_T<LANG_META_ARGS>
    LangDesc<LANG_META_ARGS>::parse_from_lex_specialized(
    LexOutput_T lex_out, Option_T<string> sym_target, Gensym_T gen, Arena* A) {

    if (lex_out->err_.is_some()) {
        return ParseOutput<LANG_META_ARGS>::make_error(
            lex_out, ParseError::make_from_lex_error(lex_out->err_.as_some()));
    }

    auto tgt = parser_desc_->main_sym_;
    if (sym_target.is_some()) {
        tgt = sym_target.as_some();
    }

    ParserVertexStackItem start_item;
    start_item.v_ = parser_desc_->start_vertex_;
    start_item.pos_ = 0;

    auto desc_raw = parser_desc_.get();

    ParserProcXform* st_desc_proc_xform_cached = parser_desc_->proc_xform_by_prod_id_->begin();

    SymItem* lex_out_items_cached = &lex_out->items_internal_->at_unchecked(0);
    Int n_lex_out_items_cached = lex_out->items_internal_->length();

    string st_sym_target = tgt;

    ParserProcState st_inline;

    st_inline.lex_res_ = lex_out;

    Int S_cap_init = 65536;

    Int Sv_cap = S_cap_init;
    st_inline.Sv_addr_ = reinterpret_cast<ParserVertexStackItem*>(
        malloc_ext(Sv_cap * sizeof(ParserVertexStackItem), A));
    st_inline.Sv_len_ = 0;

    Int cps_diff_max = parser_desc_->cps_flat_diff_max_;

    Int Ss_cap = S_cap_init;
    st_inline.Ss_addr_ = reinterpret_cast<SymItem*>(
        malloc_ext(Ss_cap * sizeof(SymItem), A));
    st_inline.Ss_len_ = 0;

    Int Sr_cap = S_cap_init;
    st_inline.Sr_addr_ = reinterpret_cast<Result_T*>(
        malloc_ext(Sr_cap * sizeof(Result_T), A));
    st_inline.Sr_len_ = 0;

    Int Sb_cap = S_cap_init;
    st_inline.Sb_addr_ = reinterpret_cast<Result_T*>(
        malloc_ext(Sb_cap * sizeof(Result_T), A));
    st_inline.Sb_len_ = 0;

    Int st_i = -1;

    Int st_num_steps = 0;

    parse_rt_check_realloc(&st_inline.Sv_addr_, st_inline.Sv_len_ + 1, &Sv_cap, A);
    st_inline.Sv_addr_[st_inline.Sv_len_] = start_item;
    ++st_inline.Sv_len_;

    st_inline.desc_proc_xform_ = st_desc_proc_xform_cached;

    st_inline.sym_final_.id_ = NO_SYM;
    st_inline.sym_final_.attr_ = attr_mask_trivial();

    st_inline.unw_gen_ = gen.get();
    st_inline.unw_arena_ = A;

    auto sym_curr = parser_proc_sym_at(
        st_i, desc_raw, lex_out_items_cached, n_lex_out_items_cached,
        st_sym_target);

    while (true) {
        ParserLookahead lookahead;

        if (LR_K1) {
            lookahead.v_[0] = static_cast<i16>(sym_curr.id_);
        } else {
            for (Int j = 0; j < desc_raw->lr_k_; j++) {
                auto la_j = parser_proc_sym_at(
                    st_i + j, desc_raw, lex_out_items_cached, n_lex_out_items_cached,
                    st_sym_target);
                if (la_j.tok_ == NO_TOKEN && st_i + j >= 0 &&
                    st_i + j < lex_out->items_internal_->length()) {
                    // Quoted symbol, rather than a lexed token; remaining lookahead is
                    // incorrect as given and must instead be read off of la_j's field.
                    for (Int r = 0; r < desc_raw->lr_k_ - j; r++) {
                        lookahead.v_[j + r] = la_j.first_k_.v_[r];
                    }
                    break;
                }
                lookahead.v_[j] = static_cast<i16>(la_j.id_);
            }
        }

        while (true) {
            Int v = st_inline.Sv_addr_[st_inline.Sv_len_ - 1].v_;

            auto ret_inds = FAcc(v, lookahead);
            auto acc_ind = ret_inds.first;
            auto arg_ind = ret_inds.second;

            Int pos = max<Int>(0, st_i);

            bool do_shift = acc_ind == static_cast<Int>(ParserActionData_W::SHIFT);

            if (!NO_QUOTE) {
                if (st_i >= 0 && st_i < lex_out->items_internal_->length()) {
                    if (sym_curr.tok_ == NO_TOKEN) {
                        // Quoted symbol; shift it if possible (otherwise we may incorrectly try to
                        // recur on a constituent subsymbol).
                        auto next = FStep(v, sym_curr.id_, sym_curr.attr_);
                        ++st_num_steps;
                        if (next != NO_VERTEX) {
                            if (acc_ind == static_cast<Int>(ParserActionData_W::RECUR) &&
                                arg_ind == sym_curr.id_) {
                                // Recur on the symbol we are about to scan; pass.
                            } else {
                                do_shift = true;
                            }
                        }
                    }
                }
            }

            if (__builtin_expect(do_shift, 1)) {
                if (__builtin_expect(st_i == n_lex_out_items_cached, 0)) {
                    st_inline.destroy_arrays();
                    return parse_error_output_here<LANG_META_ARGS>(
                        fmt_str("Unexpected end-of-file"), st_i, lex_out);
                }

                auto pos_prev = pos;

                Int v = st_inline.Sv_addr_[st_inline.Sv_len_ - 1].v_;

                auto next = FStep(v, sym_curr.id_, sym_curr.attr_);
                ++st_num_steps;

                if (next == NO_VERTEX) {
                    st_inline.destroy_arrays();
                    return parse_error_output_here<LANG_META_ARGS>(
                        fmt_str("Unexpected token: {}",
                            parser_format_sym(
                                desc_raw, sym_curr.id_, sym_curr.attr_)), st_i, lex_out);
                }

                ParserVertexStackItem new_item;
                new_item.v_ = next;
                new_item.pos_ = pos;

                parse_rt_check_realloc(&st_inline.Sv_addr_, st_inline.Sv_len_ + 1, &Sv_cap, A);
                st_inline.Sv_addr_[st_inline.Sv_len_] = new_item;
                ++st_inline.Sv_len_;


                parse_rt_check_realloc(&st_inline.Ss_addr_, st_inline.Ss_len_ + 1, &Ss_cap, A);
                st_inline.Ss_addr_[st_inline.Ss_len_] = sym_curr;
                ++st_inline.Ss_len_;

                auto buf_res = sym_curr.res_;

                parse_rt_check_realloc(&st_inline.Sr_addr_, st_inline.Sr_len_ + 1, &Sr_cap, A);
                st_inline.Sr_addr_[st_inline.Sr_len_] = buf_res;
                ++st_inline.Sr_len_;

                ++st_i;

                if (__builtin_expect(st_i >= n_lex_out_items_cached, 0)) {
                    auto ret_sym = desc_raw->right_end_marker_;
                    sym_curr = SymItem::make_lex_token_parse_sym(NO_TOKEN, ret_sym, st_i, -1, -1);
                } else {
                    sym_curr = lex_out_items_cached[st_i];
                }

                break;

            } else if (__builtin_expect(
                acc_ind == static_cast<Int>(ParserActionData_W::REDUCE), 1)) {

                auto prod_id = arg_ind;

                parse_rt_check_realloc(
                    &st_inline.Sb_addr_, st_inline.Sb_len_ + cps_diff_max, &Sb_cap, A);
                parse_rt_check_realloc(
                    &st_inline.Sr_addr_, st_inline.Sr_len_ + 1, &Sr_cap, A);
                auto buf_item = st_inline.desc_proc_xform_[prod_id](&st_inline);

                Int v = st_inline.Sv_addr_[st_inline.Sv_len_ - 1].v_;

                auto next = FStep(v, buf_item.id_, buf_item.attr_);

                ++st_num_steps;
                if (__builtin_expect(next == NO_VERTEX, 0)) {
                    st_inline.destroy_arrays();

                    return parse_error_output_here<LANG_META_ARGS>(
                        fmt_str("Unexpected symbol: {}",
                            parser_format_sym(desc_raw, buf_item.id_, buf_item.attr_)),
                            st_i, lex_out);
                }

                ParserVertexStackItem next_item;
                next_item.v_ = next;
                next_item.pos_ = pos;

                parse_rt_check_realloc(&st_inline.Sv_addr_, st_inline.Sv_len_ + 1, &Sv_cap, A);
                st_inline.Sv_addr_[st_inline.Sv_len_] = next_item;
                ++st_inline.Sv_len_;

                parse_rt_check_realloc(&st_inline.Ss_addr_, st_inline.Ss_len_ + 1, &Ss_cap, A);
                st_inline.Ss_addr_[st_inline.Ss_len_] = buf_item;
                ++st_inline.Ss_len_;

            } else if (__builtin_expect(
                acc_ind == static_cast<Int>(ParserActionData_W::RECUR), 1)) {

                auto step_sym = desc_raw->sym_to_recur_step_(arg_ind);

                Int v = st_inline.Sv_addr_[st_inline.Sv_len_ - 1].v_;

                auto next = FStep(v, step_sym, attr_mask_trivial());
                ++st_num_steps;

                if (__builtin_expect(next == NO_VERTEX, 0)) {
                    AX("Recur step failed: v={} sym={}\n", v, step_sym);
                }

                ParserVertexStackItem next_item;
                next_item.v_ = next;
                next_item.pos_ = pos;

                parse_rt_check_realloc(&st_inline.Sv_addr_, st_inline.Sv_len_ + 1, &Sv_cap, A);
                st_inline.Sv_addr_[st_inline.Sv_len_] = next_item;
                ++st_inline.Sv_len_;

            } else if (__builtin_expect(
                acc_ind == static_cast<Int>(ParserActionData_W::RET), 1)) {

                auto ret_sym = arg_ind;

                if (__builtin_expect(ret_sym == desc_raw->start_full_sym_, 0)) {
                    if (st_i == n_lex_out_items_cached) {
                        AR_eq(st_inline.Sv_len_, 2);
                        AR_eq(st_inline.Sr_len_, 1);

                        auto ret_res = st_inline.Sr_addr_[0];
                        --st_inline.Sr_len_;

                        auto ret_res_node = rc_from_ptr_ext_dec<Node>(ret_res.v_, A);

                        AR_eq(st_inline.Ss_len_, 1);
                        auto item_final = st_inline.Ss_addr_[0];
                        --st_inline.Ss_len_;

                        ret_res_node->is_top_ = true;
                        ret_res_node->sym_ = st_inline.sym_final_.id_;
                        ret_res_node->attr_ = st_inline.sym_final_.attr_;
                        ret_res_node->first_k_ = lex_out->first_k(parser_desc_->lr_k_);

                        st_inline.destroy_arrays();

                        return ParseOutput<LANG_META_ARGS>::make_success(
                            lex_out, ret_res_node->sym_, ret_res_node->attr_,
                            ret_res_node, st_num_steps);

                    } else {
                        st_inline.destroy_arrays();

                        return parse_error_output_here<LANG_META_ARGS>(
                            "Expected end-of-file", st_i, lex_out);
                    }
                }

                st_inline.Sv_len_ -= 2;  // end, start

                auto buf_item = st_inline.Ss_addr_[st_inline.Ss_len_ - 1];
                --st_inline.Ss_len_;

                Int v = st_inline.Sv_addr_[st_inline.Sv_len_ - 1].v_;

                auto next = FStep(v, buf_item.id_, buf_item.attr_);
                ++st_num_steps;
                if (next == NO_VERTEX) {
                    st_inline.destroy_arrays();
                    return parse_error_output_here<LANG_META_ARGS>(
                        fmt_str("Unexpected symbol: {}", buf_item), st_i, lex_out);
                }

                ParserVertexStackItem next_item;
                next_item.v_ = next;
                next_item.pos_ = pos;

                parse_rt_check_realloc(&st_inline.Sv_addr_, st_inline.Sv_len_ + 1, &Sv_cap, A);
                st_inline.Sv_addr_[st_inline.Sv_len_] = next_item;
                ++st_inline.Sv_len_;

                parse_rt_check_realloc(&st_inline.Ss_addr_, st_inline.Ss_len_ + 1, &Ss_cap, A);
                st_inline.Ss_addr_[st_inline.Ss_len_] = buf_item;
                ++st_inline.Ss_len_;

            } else if (__builtin_expect(
                acc_ind == static_cast<Int>(ParserActionData_W::NONE), 1)) {

                Int v = st_inline.Sv_addr_[st_inline.Sv_len_ - 1].v_;

                if (v == desc_raw->start_vertex_) {
                    st_inline.destroy_arrays();
                    return parse_error_output_here<LANG_META_ARGS>(
                        fmt_str("No action for state (empty language?)"), st_i, lex_out);
                } else {
                    AX();
                }

            } else {
                AX();
            }
        }
    }
}





////////////////////////////////////////////////////////////////////////////////
// Pretty-printer
////////////////////////////////////////////////////////////////////////////////

}  // namespace lang_rt

// namespace lang_rt {
//     def PrBufStreamItem {}
//         def PrBufStreamItem.String { x: Str; }
//         def PrBufStreamItem.Newline {}
//         def PrBufStreamItem.Indent {}
//         def PrBufStreamItem.Dedent {}
//
//     def PrBufStream {
//         items: Vec(PrBufStreamItem);
//         method distill(os: Ref(^ostream), flags: ^FmtFlags): void;
//         method push_string(x: Str): void;
//         method push_newline(): void;
//         method push_newlines(n: Int): void;
//         method push_indent(): void;
//         method push_dedent(): void;
//     }
// }

namespace lang_rt::PrBufStreamItem {
    struct _T;
}

namespace lang_rt {
    using PrBufStreamItem_T = rc_ptr<lang_rt::PrBufStreamItem::_T>;
}

namespace lang_rt::PrBufStreamItem::String {
    struct _T;
}

namespace lang_rt::PrBufStreamItem {
    using String_T = rc_ptr<lang_rt::PrBufStreamItem::String::_T>;
}

namespace lang_rt::PrBufStreamItem::Newline {
    struct _T;
}

namespace lang_rt::PrBufStreamItem {
    using Newline_T = rc_ptr<lang_rt::PrBufStreamItem::Newline::_T>;
}

namespace lang_rt::PrBufStreamItem::Indent {
    struct _T;
}

namespace lang_rt::PrBufStreamItem {
    using Indent_T = rc_ptr<lang_rt::PrBufStreamItem::Indent::_T>;
}

namespace lang_rt::PrBufStreamItem::Dedent {
    struct _T;
}

namespace lang_rt::PrBufStreamItem {
    using Dedent_T = rc_ptr<lang_rt::PrBufStreamItem::Dedent::_T>;
}

namespace lang_rt::PrBufStream {
    struct _T;
}

namespace lang_rt {
    using PrBufStream_T = rc_ptr<lang_rt::PrBufStream::_T>;
}

void pr_debug(ostream& os, FmtFlags flags, lang_rt::PrBufStreamItem_T x);

namespace lang_rt::PrBufStreamItem {
    enum struct _W {
        String,
        Newline,
        Indent,
        Dedent,
    };
}

namespace lang_rt::PrBufStreamItem {
    struct _T: hash_obj, enable_rc_from_this_poly {
        lang_rt::PrBufStreamItem::_W w_;
        virtual ~_T();
        _T(lang_rt::PrBufStreamItem::_W w);
        bool is_String();
        bool is_Newline();
        bool is_Indent();
        bool is_Dedent();
        lang_rt::PrBufStreamItem::String_T as_String();
        lang_rt::PrBufStreamItem::Newline_T as_Newline();
        lang_rt::PrBufStreamItem::Indent_T as_Indent();
        lang_rt::PrBufStreamItem::Dedent_T as_Dedent();
        void hash_ser_acc_lang_rt_PrBufStreamItem(SerBuf& buf) const;
        virtual void hash_ser_acc(SerBuf& buf) const = 0;
    };
}

void pr_debug(ostream& os, FmtFlags flags, lang_rt::PrBufStream_T x);

namespace lang_rt::PrBufStream {
    __attribute__((always_inline)) lang_rt::PrBufStream_T make(Vec_T<lang_rt::PrBufStreamItem_T> items);
}

namespace lang_rt::PrBufStream {
    __attribute__((always_inline)) lang_rt::PrBufStream_T make_ext(ArenaPtr arena, Vec_T<lang_rt::PrBufStreamItem_T> items);
}

namespace lang_rt::PrBufStream {
    struct _T: hash_obj, enable_rc_from_this_poly {
        void distill(Ref<ostream> os, FmtFlags flags);
        void push_string(string x);
        void push_newline();
        void push_newlines(Int n);
        void push_indent();
        void push_dedent();
        Vec_T<lang_rt::PrBufStreamItem_T> items_;
        _T();
        lang_rt::PrBufStream_T with_items(Vec_T<lang_rt::PrBufStreamItem_T> items);
        void hash_ser_acc_lang_rt_PrBufStream(SerBuf& buf) const;
        virtual void hash_ser_acc(SerBuf& buf) const;
    };
}

void pr_debug(ostream& os, FmtFlags flags, lang_rt::PrBufStreamItem::String_T x);

namespace lang_rt::PrBufStreamItem::String {
    __attribute__((always_inline)) lang_rt::PrBufStreamItem::String_T make(string x);
}

namespace lang_rt::PrBufStreamItem::String {
    __attribute__((always_inline)) lang_rt::PrBufStreamItem::String_T make_ext(ArenaPtr arena, string x);
}

namespace lang_rt::PrBufStreamItem::String {
    struct _T: lang_rt::PrBufStreamItem::_T {
        string x_;
        _T();
        lang_rt::PrBufStreamItem::String_T with_x(string x);
        void hash_ser_acc_lang_rt_PrBufStreamItem_String(SerBuf& buf) const;
        virtual void hash_ser_acc(SerBuf& buf) const;
    };
}

void pr_debug(ostream& os, FmtFlags flags, lang_rt::PrBufStreamItem::Newline_T x);

namespace lang_rt::PrBufStreamItem::Newline {
    __attribute__((always_inline)) lang_rt::PrBufStreamItem::Newline_T make();
}

namespace lang_rt::PrBufStreamItem::Newline {
    __attribute__((always_inline)) lang_rt::PrBufStreamItem::Newline_T make_ext(ArenaPtr arena);
}

namespace lang_rt::PrBufStreamItem::Newline {
    struct _T: lang_rt::PrBufStreamItem::_T {
        _T();
        void hash_ser_acc_lang_rt_PrBufStreamItem_Newline(SerBuf& buf) const;
        virtual void hash_ser_acc(SerBuf& buf) const;
    };
}

void pr_debug(ostream& os, FmtFlags flags, lang_rt::PrBufStreamItem::Indent_T x);

namespace lang_rt::PrBufStreamItem::Indent {
    __attribute__((always_inline)) lang_rt::PrBufStreamItem::Indent_T make();
}

namespace lang_rt::PrBufStreamItem::Indent {
    __attribute__((always_inline)) lang_rt::PrBufStreamItem::Indent_T make_ext(ArenaPtr arena);
}

namespace lang_rt::PrBufStreamItem::Indent {
    struct _T: lang_rt::PrBufStreamItem::_T {
        _T();
        void hash_ser_acc_lang_rt_PrBufStreamItem_Indent(SerBuf& buf) const;
        virtual void hash_ser_acc(SerBuf& buf) const;
    };
}

void pr_debug(ostream& os, FmtFlags flags, lang_rt::PrBufStreamItem::Dedent_T x);

namespace lang_rt::PrBufStreamItem::Dedent {
    __attribute__((always_inline)) lang_rt::PrBufStreamItem::Dedent_T make();
}

namespace lang_rt::PrBufStreamItem::Dedent {
    __attribute__((always_inline)) lang_rt::PrBufStreamItem::Dedent_T make_ext(ArenaPtr arena);
}

namespace lang_rt::PrBufStreamItem::Dedent {
    struct _T: lang_rt::PrBufStreamItem::_T {
        _T();
        void hash_ser_acc_lang_rt_PrBufStreamItem_Dedent(SerBuf& buf) const;
        virtual void hash_ser_acc(SerBuf& buf) const;
    };
}

inline void pr_debug(ostream& os, FmtFlags flags, lang_rt::PrBufStreamItem_T x) {
    switch (x->w_) {
        case lang_rt::PrBufStreamItem::_W::String: {
            pr_debug(os, flags, x->as_String());
            break;
        }
        case lang_rt::PrBufStreamItem::_W::Newline: {
            pr_debug(os, flags, x->as_Newline());
            break;
        }
        case lang_rt::PrBufStreamItem::_W::Indent: {
            pr_debug(os, flags, x->as_Indent());
            break;
        }
        case lang_rt::PrBufStreamItem::_W::Dedent: {
            pr_debug(os, flags, x->as_Dedent());
            break;
        }
        default: {
            AX();
        }
    }
}

inline lang_rt::PrBufStreamItem::_T::~_T() {
}

inline lang_rt::PrBufStreamItem::_T::_T(lang_rt::PrBufStreamItem::_W w) {
    w_ = w;
}

inline bool lang_rt::PrBufStreamItem::_T::is_String() {
    return w_ == lang_rt::PrBufStreamItem::_W::String;
}

inline bool lang_rt::PrBufStreamItem::_T::is_Newline() {
    return w_ == lang_rt::PrBufStreamItem::_W::Newline;
}

inline bool lang_rt::PrBufStreamItem::_T::is_Indent() {
    return w_ == lang_rt::PrBufStreamItem::_W::Indent;
}

inline bool lang_rt::PrBufStreamItem::_T::is_Dedent() {
    return w_ == lang_rt::PrBufStreamItem::_W::Dedent;
}

inline lang_rt::PrBufStreamItem::String_T lang_rt::PrBufStreamItem::_T::as_String() {
    AT(this->is_String());
    return this->rc_from_this_poly<lang_rt::PrBufStreamItem::String::_T>();
}

inline lang_rt::PrBufStreamItem::Newline_T lang_rt::PrBufStreamItem::_T::as_Newline() {
    AT(this->is_Newline());
    return this->rc_from_this_poly<lang_rt::PrBufStreamItem::Newline::_T>();
}

inline lang_rt::PrBufStreamItem::Indent_T lang_rt::PrBufStreamItem::_T::as_Indent() {
    AT(this->is_Indent());
    return this->rc_from_this_poly<lang_rt::PrBufStreamItem::Indent::_T>();
}

inline lang_rt::PrBufStreamItem::Dedent_T lang_rt::PrBufStreamItem::_T::as_Dedent() {
    AT(this->is_Dedent());
    return this->rc_from_this_poly<lang_rt::PrBufStreamItem::Dedent::_T>();
}

inline void lang_rt::PrBufStreamItem::_T::hash_ser_acc_lang_rt_PrBufStreamItem(SerBuf& buf) const {
    hash_ser(buf, static_cast<Int>(w_));
}

inline void pr_debug(ostream& os, FmtFlags flags, lang_rt::PrBufStream_T x) {
    os << "lang_rt::PrBufStream {";
    flags.sub_lo().advance_lines(1, os);
    os << "items: ";
    pr_debug(os, flags.sub_lo(), x->items_);
    os << ",";
    flags.advance_lines(1, os);
    os << "}";
}

inline lang_rt::PrBufStream::_T::_T() {
}

__attribute__((always_inline)) inline lang_rt::PrBufStream_T lang_rt::PrBufStream::make(Vec_T<lang_rt::PrBufStreamItem_T> items) {
    auto ret = make_rc<lang_rt::PrBufStream::_T>();
    ret->items_ = items;
    return ret;
}

__attribute__((always_inline)) inline lang_rt::PrBufStream_T lang_rt::PrBufStream::make_ext(ArenaPtr arena, Vec_T<lang_rt::PrBufStreamItem_T> items) {
    auto ret1 = make_rc_ext<lang_rt::PrBufStream::_T>(arena);
    ret1->items_ = items;
    return ret1;
}

inline lang_rt::PrBufStream_T lang_rt::PrBufStream::_T::with_items(Vec_T<lang_rt::PrBufStreamItem_T> items) {
    auto ret = make_rc<lang_rt::PrBufStream::_T>();
    ret->items_ = items;
    return ret;
}

inline void lang_rt::PrBufStream::_T::hash_ser_acc_lang_rt_PrBufStream(SerBuf& buf) const {
    hash_ser(buf, items_);
}

inline void lang_rt::PrBufStream::_T::hash_ser_acc(SerBuf& buf) const {
    this->lang_rt::PrBufStream::_T::hash_ser_acc_lang_rt_PrBufStream(buf);
}

inline void pr_debug(ostream& os, FmtFlags flags, lang_rt::PrBufStreamItem::String_T x) {
    os << "lang_rt::PrBufStreamItem::String {";
    flags.sub_lo().advance_lines(1, os);
    os << "x: ";
    pr_debug(os, flags.sub_lo(), x->x_);
    os << ",";
    flags.advance_lines(1, os);
    os << "}";
}

inline lang_rt::PrBufStreamItem::String::_T::_T() : lang_rt::PrBufStreamItem::_T(lang_rt::PrBufStreamItem::_W::String) {
}

__attribute__((always_inline)) inline lang_rt::PrBufStreamItem::String_T lang_rt::PrBufStreamItem::String::make(string x) {
    auto ret = make_rc<lang_rt::PrBufStreamItem::String::_T>();
    ret->x_ = x;
    return ret;
}

__attribute__((always_inline)) inline lang_rt::PrBufStreamItem::String_T lang_rt::PrBufStreamItem::String::make_ext(ArenaPtr arena, string x) {
    auto ret1 = make_rc_ext<lang_rt::PrBufStreamItem::String::_T>(arena);
    ret1->x_ = x;
    return ret1;
}

inline lang_rt::PrBufStreamItem::String_T lang_rt::PrBufStreamItem::String::_T::with_x(string x) {
    auto ret = make_rc<lang_rt::PrBufStreamItem::String::_T>();
    ret->x_ = x;
    return ret;
}

inline void lang_rt::PrBufStreamItem::String::_T::hash_ser_acc_lang_rt_PrBufStreamItem_String(SerBuf& buf) const {
    this->hash_ser_acc_lang_rt_PrBufStreamItem(buf);
    hash_ser(buf, x_);
}

inline void lang_rt::PrBufStreamItem::String::_T::hash_ser_acc(SerBuf& buf) const {
    this->lang_rt::PrBufStreamItem::String::_T::hash_ser_acc_lang_rt_PrBufStreamItem_String(buf);
}

inline void pr_debug(ostream& os, FmtFlags flags, lang_rt::PrBufStreamItem::Newline_T x) {
    os << "lang_rt::PrBufStreamItem::Newline {";
    os << "}";
}

inline lang_rt::PrBufStreamItem::Newline::_T::_T() : lang_rt::PrBufStreamItem::_T(lang_rt::PrBufStreamItem::_W::Newline) {
}

__attribute__((always_inline)) inline lang_rt::PrBufStreamItem::Newline_T lang_rt::PrBufStreamItem::Newline::make() {
    auto ret = make_rc<lang_rt::PrBufStreamItem::Newline::_T>();
    return ret;
}

__attribute__((always_inline)) inline lang_rt::PrBufStreamItem::Newline_T lang_rt::PrBufStreamItem::Newline::make_ext(ArenaPtr arena) {
    auto ret1 = make_rc_ext<lang_rt::PrBufStreamItem::Newline::_T>(arena);
    return ret1;
}

inline void lang_rt::PrBufStreamItem::Newline::_T::hash_ser_acc_lang_rt_PrBufStreamItem_Newline(SerBuf& buf) const {
    this->hash_ser_acc_lang_rt_PrBufStreamItem(buf);
}

inline void lang_rt::PrBufStreamItem::Newline::_T::hash_ser_acc(SerBuf& buf) const {
    this->lang_rt::PrBufStreamItem::Newline::_T::hash_ser_acc_lang_rt_PrBufStreamItem_Newline(buf);
}

inline void pr_debug(ostream& os, FmtFlags flags, lang_rt::PrBufStreamItem::Indent_T x) {
    os << "lang_rt::PrBufStreamItem::Indent {";
    os << "}";
}

inline lang_rt::PrBufStreamItem::Indent::_T::_T() : lang_rt::PrBufStreamItem::_T(lang_rt::PrBufStreamItem::_W::Indent) {
}

__attribute__((always_inline)) inline lang_rt::PrBufStreamItem::Indent_T lang_rt::PrBufStreamItem::Indent::make() {
    auto ret = make_rc<lang_rt::PrBufStreamItem::Indent::_T>();
    return ret;
}

__attribute__((always_inline)) inline lang_rt::PrBufStreamItem::Indent_T lang_rt::PrBufStreamItem::Indent::make_ext(ArenaPtr arena) {
    auto ret1 = make_rc_ext<lang_rt::PrBufStreamItem::Indent::_T>(arena);
    return ret1;
}

inline void lang_rt::PrBufStreamItem::Indent::_T::hash_ser_acc_lang_rt_PrBufStreamItem_Indent(SerBuf& buf) const {
    this->hash_ser_acc_lang_rt_PrBufStreamItem(buf);
}

inline void lang_rt::PrBufStreamItem::Indent::_T::hash_ser_acc(SerBuf& buf) const {
    this->lang_rt::PrBufStreamItem::Indent::_T::hash_ser_acc_lang_rt_PrBufStreamItem_Indent(buf);
}

inline void pr_debug(ostream& os, FmtFlags flags, lang_rt::PrBufStreamItem::Dedent_T x) {
    os << "lang_rt::PrBufStreamItem::Dedent {";
    os << "}";
}

inline lang_rt::PrBufStreamItem::Dedent::_T::_T() : lang_rt::PrBufStreamItem::_T(lang_rt::PrBufStreamItem::_W::Dedent) {
}

__attribute__((always_inline)) inline lang_rt::PrBufStreamItem::Dedent_T lang_rt::PrBufStreamItem::Dedent::make() {
    auto ret = make_rc<lang_rt::PrBufStreamItem::Dedent::_T>();
    return ret;
}

__attribute__((always_inline)) inline lang_rt::PrBufStreamItem::Dedent_T lang_rt::PrBufStreamItem::Dedent::make_ext(ArenaPtr arena) {
    auto ret1 = make_rc_ext<lang_rt::PrBufStreamItem::Dedent::_T>(arena);
    return ret1;
}

inline void lang_rt::PrBufStreamItem::Dedent::_T::hash_ser_acc_lang_rt_PrBufStreamItem_Dedent(SerBuf& buf) const {
    this->hash_ser_acc_lang_rt_PrBufStreamItem(buf);
}

inline void lang_rt::PrBufStreamItem::Dedent::_T::hash_ser_acc(SerBuf& buf) const {
    this->lang_rt::PrBufStreamItem::Dedent::_T::hash_ser_acc_lang_rt_PrBufStreamItem_Dedent(buf);
}

inline void lang_rt::PrBufStream::_T::push_string(string x) {
    items_->push(PrBufStreamItem::String::make(x));
}

inline void lang_rt::PrBufStream::_T::push_newline() {
    items_->push(PrBufStreamItem::Newline::make());
}

inline void lang_rt::PrBufStream::_T::push_newlines(Int n) {
    for (Int k = 0; k < n; k++) {
        this->push_newline();
    }
}

inline void lang_rt::PrBufStream::_T::push_indent() {
    items_->push(PrBufStreamItem::Indent::make());
}

inline void lang_rt::PrBufStream::_T::push_dedent() {
    items_->push(PrBufStreamItem::Dedent::make());
}

inline void lang_rt::PrBufStream::_T::distill(ostream& os, FmtFlags flags) {
    Int i = 0;
    while (i < items_->length()) {
        auto item = items_->operator[](i);
        if (item->is_String()) {
            os << item->as_String()->x_;
            ++i;

        } else if (item->is_Newline()) {
            Int num_nl = 0;
            Int num_indent_net = 0;

            Int j = i;
            while (true) {
                if (j >= items_->length()) {
                    break;
                }
                auto item_j = items_->operator[](j);
                if (item_j->is_Newline()) {
                    ++num_nl;
                } else if (item_j->is_Indent()) {
                    ++num_indent_net;
                } else if (item_j->is_Dedent()) {
                    --num_indent_net;
                } else if (item_j->is_String()) {
                    break;
                } else {
                    AX();
                }
                ++j;
            }
            AT(num_nl >= 1);
            for (Int k = 0; k < num_nl - 1; k++) {
                os << endl;
            }
            flags.indent_curr_ = max<Int>(0, flags.indent_curr_ + num_indent_net);
            flags.advance_lines(1, os);
            i = j;

        } else if (item->is_Indent()) {
            flags.indent_curr_ += 1;
            ++i;

        } else if (item->is_Dedent()) {
            flags.indent_curr_ = max<Int>(0, flags.indent_curr_ - 1);
            ++i;

        } else {
            AX();
        }
    }
}

namespace lang_rt {





////////////////////////////////////////////////////////////////////////////////
// Table decoding
////////////////////////////////////////////////////////////////////////////////

constexpr bool DECODE_EXPENSIVE_ASSERT = false;

template<typename UNum>
__attribute__((always_inline)) inline Int table_decode_offset(const UNum tt[], Int v) {
    auto b = *(reinterpret_cast<const u32*>(tt) + v);  // Note: assumes little-endian
    return b;
}

template<typename Num, typename UNum, typename Buf>
__attribute__((always_inline)) pair<Int, Int> table_decode_r1_vec_pair(
    const UNum tt[], Int x, Buf z) {

    tt += 3;
    Int offset = table_decode_offset<UNum>(tt, x);
    tt += offset;

    while (true) {
        if (__builtin_expect(tt[0], 0) == 0) {
            return make_pair(static_cast<Num>(tt[1]), static_cast<Num>(tt[2]));
        }

        if (DECODE_EXPENSIVE_ASSERT) {
            if (tt[0] != 1) {
                AX();
            }
        }

        Int id = tt[1];
        Int v = z.v_[id-1];

        Int n = tt[2];
        tt += 3;
        bool found = false;
        for (Int i = 0; i < n; i++) {
            if (v == tt[i]) {
                Int offset = tt[n+i];
                tt += offset;
                found = true;
                break;
            }
        }
        if (!found) {
            Int offset = tt[n+n];
            tt += offset;
        }
    }
}

template<typename Num, typename UNum, typename Buf>
__attribute__((always_inline)) Int table_decode_r2_vec(
    const UNum tt[], Int x, Int y, Buf z) {

    tt += 3;
    Int offset = table_decode_offset<UNum>(tt, x);
    tt += offset;

    {
        Int n = tt[2];
        tt += 3;
        bool found = false;
        for (Int i = 0; i < n; i++) {
            if (y == tt[i]) {
                Int offset = tt[n+i];
                tt += offset;
                found = true;
                break;
            }
        }
        if (!found) {
            Int offset = tt[n+n];
            tt += offset;
        }
    }

    while (true) {
        u64 tt_word = *reinterpret_cast<const u64*>(tt);
        u16 tt0 = tt_word & 0xffff;
        if (__builtin_expect(tt0 == 0, 1)) {
            return static_cast<Num>(tt[1]);
        }

        if (DECODE_EXPENSIVE_ASSERT) {
            if (tt0 != 1) {
                AX();
            }
        }

        tt_word >>= 16;
        u16 tt1 = tt_word & 0xffff;
        tt_word >>= 16;
        u16 tt2 = tt_word & 0xffff;

        Int id = tt1;
        Int v = z.v_[id-2];

        Int n = tt2;
        tt += 3;
        bool found = false;
        for (Int i = 0; i < n; i++) {
            if (v == tt[i]) {
                Int offset = tt[n+i];
                tt += offset;
                found = true;
                break;
            }
        }
        if (!found) {
            Int offset = tt[n+n];
            tt += offset;
        }
    }
}

template<typename Num, typename UNum>
__attribute__((always_inline)) inline Int table_decode_r2(const UNum tt[], Int x, Int y) {
    {
        Int n = tt[2];
        tt += 3;
        Int offset = table_decode_offset<UNum>(tt, x);
        tt += offset;
    }

    {
        Int n = tt[2];
        tt += 3;
        Int offset = table_decode_offset<UNum>(tt, y);
        tt += offset;
    }

    return static_cast<Num>(tt[1]);
}

__attribute__((always_inline)) inline const u8* table_u16_array_as_u8_array(const u16* x) {
    return reinterpret_cast<const u8*>(x);
}

__attribute__((always_inline)) inline const i16* table_u16_array_as_i16_array(const u16* x) {
    return reinterpret_cast<const i16*>(x);
}





////////////////////////////////////////////////////////////////////////////////
// Test/debug drivers
////////////////////////////////////////////////////////////////////////////////

template<LANG_META_PARAMS>
void LangDesc<LANG_META_ARGS>::debug_example(string sym_target, string input) {
    auto gen = make_rc<Gensym>();
    auto input_s = vec_from_std_string(input);
    auto parse = this->parse_ext(
        input_s, Some<string>(sym_target), gen, nullptr);
    if (!parse->is_success()) {
        if (parse->lex_->is_success()) {
            LG_ERR("Lexer output:\n{}\n\n", parse->lex_);
        }
        LG_ERR(" === Parse error\n{}\n\n", parse->err_.as_some());
    } else {
        auto res = parse->res_.as_some();
        LG_ERR("Success: {}\n",
            parser_format_sym(this->parser_desc_.get(),
                static_cast<ParserSymId>(res->sym_), res->attr_));
    }
}

template<LANG_META_PARAMS>
bool LangDesc<LANG_META_ARGS>::test_example(
    Option_T<string> sym_target, const Str_T& input, Arena* A, Int error_pos_maybe,
    bool test_write) {

    auto gen = make_rc<Gensym>();

    auto parse = this->parse_ext(input, sym_target, gen, A);

    if (error_pos_maybe == -1 && !parse->is_success()) {
        LG_ERR(" === Parse error\n{}\n\n", parse->err_.as_some());
        return false;
    }

    if (error_pos_maybe != -1 && parse->is_success()) {
        LG_ERR(" === Parse unexpected success\n");
        LG_ERR(" === Input: {}", vec_to_std_string(input));
        return false;
    }

    if (error_pos_maybe != -1 && !parse->is_success()) {
        auto err = parse->err_.as_some();
        Int error_pos_actual;
        if (parse->lex_->err_.is_none()) {
            auto tok_i = err->tok_i_.as_some();
            error_pos_actual = parse->lex_->lookup_pos(tok_i).first;
        } else {
            error_pos_actual = parse->lex_->err_.as_some()->i_;
        }
        if (error_pos_actual != error_pos_maybe) {
            fmt(cerr, " === Parse error at incorrect position (expected {}, received {})\n{}\n\n",
                error_pos_maybe, error_pos_actual, parse->err_.as_some());
            return false;
        }
    }

    if (parse->is_success()) {
        auto res = parse->res_.as_some();

        if (test_write) {
            ostringstream os;
            res->write(os, FmtFlags::default_());
            if (os.str() != vec_to_std_string(input)) {
                fmt(cerr, " === Mismatch on write:\n    Expected: `{}`\n    Received: `{}`\n",
                    vec_to_std_string(input), os.str());
                return false;
            }
        }
    }

    return true;
}

template<LANG_META_PARAMS>
bool LangDesc<LANG_META_ARGS>::test_example(
    Option_T<string> sym_target, const char* input, Int error_pos_maybe, bool test_write) {

    auto A = make_rc<Arena>();

    Int len = strlen(input);
    auto input_shared = make_rc_ext<Str>(A.get(), A.get(), len, len, _Vec_constr_internal());
    memcpy(&input_shared->at_unchecked(0), input, len);
    return this->test_example(sym_target, input_shared, A.get(), error_pos_maybe, test_write);
}

}
