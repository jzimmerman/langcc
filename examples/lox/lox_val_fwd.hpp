#pragma once

#include <langcc_util.hpp>

using namespace langcc;

struct EvalContext;

void gc_heap(EvalContext*);

struct HeapManager {
    EvalContext* eval_ctx_;
    vector<void*> alloc_envs_;
    vector<void*> alloc_vals_;
    Int alloc_ { 0 };
    Int n_alloc_total_ { 0 };
    constexpr static Int FOOTPRINT_TGT_MIN = 1048576;
    Int footprint_tgt_ { FOOTPRINT_TGT_MIN };
    bool triggered_ { false };

    inline __attribute__((always_inline)) void do_gc() {
        gc_heap(eval_ctx_);
    }

    inline __attribute__((always_inline)) void check_gc() {
        // stress test:
        // this->do_gc();
        // return;

        if (triggered_) {
            this->do_gc();
            footprint_tgt_ = FOOTPRINT_TGT_MIN;
            while (footprint_tgt_ < 2*alloc_) {
                footprint_tgt_ *= 2;
            }
            triggered_ = false;
        }
    }

    template<typename T, typename...Ts> __attribute__((always_inline)) inline T* alloc_raw(
        Ts... ts) {

        ++n_alloc_total_;

        if (__builtin_expect(n_alloc_total_ % 1024 == 0, 0)) {
            if (alloc_ >= footprint_tgt_) {
                triggered_ = true;
            }
        }

        alloc_ += sizeof(T);
        auto ret = new T(ts...);
        return ret;
    }

    template<typename T, typename...Ts> inline T* alloc_env(Ts... ts) {
        auto ret = this->alloc_raw<T, Ts...>(ts...);
        alloc_envs_.push_back(ret);
        return ret;
    }

    template<typename T, typename...Ts> inline T* alloc_val(Ts... ts) {
        auto ret = this->alloc_raw<T, Ts...>(ts...);
        alloc_vals_.push_back(ret);
        return ret;
    }

    template<typename T> void dealloc(T* t) {
        delete t;
        alloc_ -= sizeof(T);
    }
};

namespace lox {
    constexpr Int STACK_LIMIT = 16384;

    enum struct ValWhich {
        Uninitialized,
        Nil,
        Boolean,
        Number,
        Builtin,
        Boxed,
    };

    enum struct ValBoxedWhich {
        Uninitialized,
        String,
        Class,
        Object,
        Closure,
    };

    enum struct GCMark {
        White,
        Gray,
        Black,
    };

    struct ValBoxedString;
    struct ValBoxedClass;
    struct ValBoxedObject;
    struct ValBoxedClosure;

    struct ValBoxed {
        ValBoxedWhich w_;
        GCMark mark_;

        inline ValBoxed(ValBoxedWhich w) : w_(w), mark_(GCMark::White) {}
        virtual inline ~ValBoxed() {}

        inline __attribute__((always_inline)) bool is_String() {
            return w_ == ValBoxedWhich::String;
        }

        inline __attribute__((always_inline)) bool is_Class() {
            return w_ == ValBoxedWhich::Class;
        }

        inline __attribute__((always_inline)) bool is_Object() {
            return w_ == ValBoxedWhich::Object;
        }

        inline __attribute__((always_inline)) bool is_Closure() {
            return w_ == ValBoxedWhich::Closure;
        }

        inline __attribute__((always_inline)) ValBoxedString* as_String_unchecked();
        inline __attribute__((always_inline)) ValBoxedClass* as_Class_unchecked();
        inline __attribute__((always_inline)) ValBoxedObject* as_Object_unchecked();
        inline __attribute__((always_inline)) ValBoxedClosure* as_Closure_unchecked();
    };

    struct Val {
        ValWhich w_;
        Int data_;

        inline Val();
        inline Val(ValWhich w);
        inline Val(ValWhich w, ValBoxed* v);
        static inline __attribute__((always_inline)) Val make_Nil();
        static inline __attribute__((always_inline)) Val make_Boolean(bool b);
        static inline __attribute__((always_inline)) Val make_Number(f64 x);
        static inline __attribute__((always_inline)) Val make_Boxed(ValBoxed* h);
        inline __attribute__((always_inline)) bool is_Nil();
        inline __attribute__((always_inline)) bool is_Boolean();
        inline __attribute__((always_inline)) bool is_Number();
        inline __attribute__((always_inline)) bool is_Builtin();
        inline __attribute__((always_inline)) bool is_Boxed();
        inline __attribute__((always_inline)) bool extract_Boolean();
        inline __attribute__((always_inline)) f64 extract_Number();
        inline __attribute__((always_inline)) ValBoxed* extract_Boxed();
    };

    struct AstData {
        Val v_;
        Int str_id_ { 0 };
        bool is_class_init_ { false };
    };
}

namespace langcc {
    inline void pr_debug(ostream& os, FmtFlags flags, ::lox::Val v);
    inline void pr_debug(ostream& os, FmtFlags flags, ::lox::AstData v);
    inline void pr_debug(ostream& os, FmtFlags flags, ::lox::GCMark x);
}



////////////////////////////////////////////////////////////////////////////////
// Forward declarations for generated code
////////////////////////////////////////////////////////////////////////////////

namespace lang::lox_pre::Node {
    struct _T;
}

namespace lang::lox_pre {
    using Node_T = rc_ptr<lang::lox_pre::Node::_T>;
}

namespace lang::lox::Node {
    struct _T;
}

namespace lang::lox {
    using Node_T = rc_ptr<lang::lox::Node::_T>;
}

using Node_S = lang::lox::Node::_T*;
using Node_T = lang::lox::Node_T;
inline Node_T node_lift(Node_S x);

namespace lang::lox::Node::Block {
    struct _T;
}

namespace lang::lox::Node {
    using Block_T = rc_ptr<lang::lox::Node::Block::_T>;
}

namespace lang::lox::Node::Stmt::Fun {
    struct _T;
}

namespace lang::lox::Node::Stmt {
    using Fun_T = rc_ptr<lang::lox::Node::Stmt::Fun::_T>;
}

namespace lox::Env {
    template<typename K, typename V> struct _T;
}

namespace lox {
    template<typename K, typename V> using Env_T = rc_ptr<Env::_T<K, V>>;
}
