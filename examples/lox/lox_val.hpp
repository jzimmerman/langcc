#pragma once

#include <langcc_util.hpp>

using namespace langcc;

#include "lox_val_fwd.hpp"

#include "lox__data_gen.hpp"

namespace lox {
    inline Val::Val() : w_(ValWhich::Uninitialized) {}
    inline Val::Val(ValWhich w) : w_(w) {}
    inline Val::Val(ValWhich w, ValBoxed* v)
        : w_(w), data_(reinterpret_cast<Int>(v)) {

        AT(!!data_);
    }

    inline __attribute__((always_inline)) bool Val::is_Nil() {
        return this->w_ == ValWhich::Nil;
    }

    inline __attribute__((always_inline)) bool Val::is_Boolean() {
        return this->w_ == ValWhich::Boolean;
    }

    inline __attribute__((always_inline)) bool Val::is_Number() {
        return this->w_ == ValWhich::Number;
    }

    inline __attribute__((always_inline)) bool Val::is_Builtin() {
        return this->w_ == ValWhich::Builtin;
    }

    inline __attribute__((always_inline)) bool Val::is_Boxed() {
        return this->w_ == ValWhich::Boxed;
    }

    inline __attribute__((always_inline)) Val Val::make_Nil() {
        return Val(ValWhich::Nil);
    }

    inline __attribute__((always_inline)) Val Val::make_Boolean(bool b) {
        auto ret = Val(ValWhich::Boolean);
        ret.data_ = b;
        return ret;
    }

    inline __attribute__((always_inline)) Val Val::make_Number(f64 x) {
        auto ret = Val(ValWhich::Number);
        *reinterpret_cast<f64*>(&ret.data_) = x;
        return ret;
    }

    inline __attribute__((always_inline)) Val Val::make_Boxed(ValBoxed* x) {
        return Val(ValWhich::Boxed, x);
    }

    inline __attribute__((always_inline)) bool Val::extract_Boolean() {
        return static_cast<bool>(this->data_);
    }

    inline __attribute__((always_inline)) f64 Val::extract_Number() {
        return *reinterpret_cast<f64*>(&this->data_);
    }

    inline __attribute__((always_inline)) ValBoxed* Val::extract_Boxed() {
        return reinterpret_cast<ValBoxed*>(this->data_);
    }

    struct ValBoxedString : ValBoxed {
        string s_;

        inline ValBoxedString(string s) : ValBoxed(ValBoxedWhich::String), s_(s) {}

        inline static Val make(string s, HeapManager& hm) {
            auto ret = hm.alloc_val<ValBoxedString>(s);
            return Val::make_Boxed(ret);
        }
    };

    struct ValBoxedClass : ValBoxed {
        string name_;
        Val super_;  // May be Uninitialized
        unordered_map<Int, Val> methods_;

        inline ValBoxedClass(string name, Val super, unordered_map<Int, Val> methods)
            : ValBoxed(ValBoxedWhich::Class), name_(name), super_(super), methods_(methods) {}

        inline static Val make(
            string name, Val super, unordered_map<Int, Val> methods, HeapManager& hm) {

            auto ret = hm.alloc_val<ValBoxedClass>(name, super, methods);
            return Val::make_Boxed(ret);
        }
    };

    struct ValBoxedObject : ValBoxed {
        Val klass_;
        unordered_map<Int, Val> fields_;

        inline ValBoxedObject(Val klass)
            : ValBoxed(ValBoxedWhich::Object), klass_(klass) {}

        inline static Val make(Val klass, HeapManager& hm) {
            auto ret = hm.alloc_val<ValBoxedObject>(klass);
            return Val::make_Boxed(ret);
        }
    };

    struct ValBoxedClosure : ValBoxed {
        lang::lox::Node::FunBody_T f_;
        Val super_;
        lox::Env::_T<Int, Val>* env_;

        inline ValBoxedClosure(lang::lox::Node::FunBody_T f, Val super,
            lox::Env::_T<Int, Val>* env)
            : ValBoxed(ValBoxedWhich::Closure), f_(f), super_(super), env_(env) {}

        inline static Val make(lang::lox::Node::FunBody_T f, Val super,
            lox::Env::_T<Int, Val>* env, HeapManager& hm) {

            auto ret = hm.alloc_val<ValBoxedClosure>(f, super, env);
            return Val::make_Boxed(ret);
        }
    };

    inline __attribute__((always_inline)) ValBoxedString* ValBoxed::as_String_unchecked() {
        return reinterpret_cast<ValBoxedString*>(this);
    }

    inline __attribute__((always_inline)) ValBoxedClass* ValBoxed::as_Class_unchecked() {
        return reinterpret_cast<ValBoxedClass*>(this);
    }

    inline __attribute__((always_inline)) ValBoxedObject* ValBoxed::as_Object_unchecked() {
        return reinterpret_cast<ValBoxedObject*>(this);
    }

    inline __attribute__((always_inline)) ValBoxedClosure* ValBoxed::as_Closure_unchecked() {
        return reinterpret_cast<ValBoxedClosure*>(this);
    }
}

namespace langcc {
    inline void pr(ostream& os, FmtFlags flags, ::lox::Val v) {
        switch (v.w_) {
            case lox::ValWhich::Uninitialized: {
                fmt(os, "[uninitialized]");
                break;
            }
            case lox::ValWhich::Nil: {
                fmt(os, "nil");
                break;
            }
            case lox::ValWhich::Boolean: {
                fmt(os, v.extract_Boolean() ? "true" : "false");
                break;
            }
            case lox::ValWhich::Number: {
                fmt(os, "{}", v.extract_Number());
                break;
            }
            case lox::ValWhich::Builtin: {
                fmt(os, "<native fn>");
                break;
            }
            case lox::ValWhich::Boxed: {
                auto cc = v.extract_Boxed();
                switch (cc->w_) {
                    case lox::ValBoxedWhich::String: {
                        // Attempt to match jlox behavior (no double quotes for printed string)
                        fmt(os, "{}", cc->as_String_unchecked()->s_);
                        break;
                    }
                    case lox::ValBoxedWhich::Class: {
                        fmt(os, "{}", cc->as_Class_unchecked()->name_);
                        break;
                    }
                    case lox::ValBoxedWhich::Object: {
                        fmt(os, "{} instance", cc->as_Object_unchecked()->klass_);
                        break;
                    }
                    case lox::ValBoxedWhich::Closure: {
                        fmt(os, "<fn {}>",
                            cc->as_Closure_unchecked()->f_->name_->as_Id()->name_.to_std_string());
                        break;
                    }
                    default: {
                        AX("pr(Val) ValBoxedWhich: {}", static_cast<Int>(cc->w_));
                    }
                }
                break;
            }
            default: {
                AX("pr(Val) ValWhich: {}", static_cast<Int>(v.w_));
            }
        }
    }

    inline void pr_debug(ostream& os, FmtFlags flags, ::lox::Val v) {
        pr(os, flags, v);
    }
    
    inline void pr_debug(ostream& os, FmtFlags flags, ::lox::AstData x) {
        fmt(os, "[lox::AstData]");
    }
}

namespace lox {
    inline __attribute__((always_inline)) Val val_make_Builtin(lox::BuiltinId builtin_id) {
        auto ret = Val(ValWhich::Builtin);
        ret.data_ = static_cast<Int>(builtin_id);
        return ret;
    }

    inline __attribute__((always_inline)) bool val_is_string(lox::Val v) {
        return v.is_Boxed() && v.extract_Boxed()->is_String();
    }

    inline __attribute__((always_inline)) bool val_is_Closure(lox::Val v) {
        return v.is_Boxed() && v.extract_Boxed()->is_Closure();
    }

    inline __attribute__((always_inline)) bool val_is_Class(lox::Val v) {
        return v.is_Boxed() && v.extract_Boxed()->is_Class();
    }

    inline __attribute__((always_inline)) bool val_is_Object(lox::Val v) {
        return v.is_Boxed() && v.extract_Boxed()->is_Object();
    }

    inline __attribute__((always_inline)) BuiltinId val_extract_builtin(lox::Val v) {
        return static_cast<BuiltinId>(v.data_);
    }

    inline __attribute__((always_inline)) string val_extract_string(lox::Val v) {
        return v.extract_Boxed()->as_String_unchecked()->s_;
    }

    inline __attribute__((always_inline)) ValBoxedClosure* val_extract_Closure(lox::Val v) {
        return v.extract_Boxed()->as_Closure_unchecked();
    }

    inline __attribute__((always_inline)) ValBoxedClass* val_extract_Class(lox::Val v) {
        return v.extract_Boxed()->as_Class_unchecked();
    }

    inline __attribute__((always_inline)) ValBoxedObject* val_extract_Object(lox::Val v) {
        return v.extract_Boxed()->as_Object_unchecked();
    }

    inline __attribute__((always_inline)) bool val_is_truthy(lox::Val v) {
        switch (v.w_) {
            case lox::ValWhich::Nil: {
                return false;
            }
            case lox::ValWhich::Boolean: {
                return v.extract_Boolean();
            }
            case lox::ValWhich::Number: {
                return true;
            }
            case lox::ValWhich::Builtin: {
                return true;
            }
            case lox::ValWhich::Boxed: {
                return true;
            }
            default: {
                AX();
            }
        }
    }
}

inline Node_T node_lift(Node_S x) {
    return x->rc_from_this_poly<lang::lox::Node::_T>();
}

namespace langcc {
    inline void pr_debug(ostream& os, FmtFlags flags, ::lox::GCMark x) {
        pr_debug(os, flags, static_cast<Int>(x));
    }
}
