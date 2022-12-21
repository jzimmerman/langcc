#include "lox__gen.hpp"
#include "lox_pre__gen.hpp"

using namespace langcc;

using namespace lang::lox;
using namespace lang::lox::Node;

using Node_S = Node::_T*;
using Block_S = Node::Block::_T*;
using Prog_S = Node::Prog::_T*;
using Stmt_S = Node::Stmt::_T*;
using Expr_S = Node::Expr::_T*;

#include "lox_error__data_gen.hpp"



////////////////////////////////////////////////////////////////////////////////
// Formatting utilities
////////////////////////////////////////////////////////////////////////////////

namespace langcc {
    void pr(ostream& os, FmtFlags flags, lang::lox::Node_T n) {
        n->write(os, flags);
    }

    void pr(ostream& os, FmtFlags flags, lox::EnvOrigin x) {
        pr_debug(os, flags, x);
    }

    inline void pr(ostream& os, FmtFlags flags, ::lox::BuiltinId x) {
        pr_debug(os, flags, x);
    }

    void pr_debug(ostream& os, FmtFlags flags, lox::Env::_T<Int, lox::Val>* x) {
        if (!x) {
            os << "nullptr";
            return;
        }
        os << "lox::Env {";
        flags.sub_lo().advance_lines(1, os);
        os << "env: ";
        langcc::pr_debug(os, flags.sub_lo(), x->env_);
        os << ",";
        flags.sub_lo().advance_lines(1, os);
        os << "at_this: ";
        langcc::pr_debug(os, flags.sub_lo(), x->at_this_);
        os << ",";
        flags.sub_lo().advance_lines(1, os);
        os << "at_super: ";
        langcc::pr_debug(os, flags.sub_lo(), x->at_super_);
        os << ",";
        flags.sub_lo().advance_lines(1, os);
        os << "parent: ";
        langcc::pr_debug(os, flags.sub_lo(), x->parent_);
        os << ",";
        flags.sub_lo().advance_lines(1, os);
        os << "origin: ";
        langcc::pr_debug(os, flags.sub_lo(), x->origin_);
        os << ",";
        flags.sub_lo().advance_lines(1, os);
        os << "fwd_loc: ";
        langcc::pr_debug(os, flags.sub_lo(), x->fwd_loc_);
        os << ",";
        flags.sub_lo().advance_lines(1, os);
        os << "mark: ";
        langcc::pr_debug(os, flags.sub_lo(), x->mark_);
        os << ",";
        flags.advance_lines(1, os);
        os << "}";
    }

    void pr(ostream& os, FmtFlags flags, lox::Env::_T<Int, lox::Val>* env) {
        pr_debug(os, flags, env);
    }
}



////////////////////////////////////////////////////////////////////////////////
// Environment methods
////////////////////////////////////////////////////////////////////////////////

namespace lox {
    template<typename K, typename V>
    V Env::_T<K, V>::lookup(K name, Int depth) {
        if (depth == 0) {
            auto it = env_.find(name);
            if (it != env_.end()) {
                return it->second;
            } else {
                return V();
            }
        } else {
            if (!parent_) {
                return V();
            }
            return parent_->lookup(name, depth - 1);
        }
    }

    template<typename K, typename V>
    Option_T<pair<V, Int>> Env::_T<K, V>::lookup_depth(K name) {
        auto it = env_.find(name);
        if (it != env_.end()) {
            return Some<pair<V, Int>>(make_pair(it->second, 0));
        }
        if (!parent_) {
            return None<pair<V, Int>>();
        }

        auto ret = parent_->lookup_depth(name);
        if (ret.is_none()) {
            return None<pair<V, Int>>();
        }
        auto [v, depth] = ret.as_some();
        return Some<pair<V, Int>>(make_pair(v, depth + 1));
    }

    template<typename K, typename V>
    bool Env::_T<K, V>::is_global() {
        return !parent_;
    }

    template<typename K, typename V>
    Int Env::_T<K, V>::global_env_depth() {
        if (this->is_global()) {
            return 0;
        } else {
            return 1 + parent_->global_env_depth();
        }
    }

    template<typename K, typename V>
    Env_T<K, V> Env::_T<K, V>::new_scope(lox::EnvOrigin origin) {
        auto ret = Env::make<K, V>(
            unordered_map<K, V>(), V(), V(), this, origin, 0, lox::GCMark::White);
        return ret;
    }
}

using LoxValEnv_T = lox::Env_T<Int, lox::Val>;
using LoxStatusEnv_T = lox::Env_T<string, lox::SymStatus>;

using LoxValEnv_P = lox::Env::_T<Int, lox::Val>*;

void lox_env_assign_strict(LoxValEnv_P env, Int name, lox::Val val, Int depth,
    Node_S e_blame) {

    if (depth == 0) {
        auto it = env->env_.find(name);
        if (it == env->env_.end()) {
            throw lox::Error::make("Cannot assign to unbound variable", node_lift(e_blame));
        }
        env->env_[name] = val;
    } else {
        lox_env_assign_strict(env->parent_, name, val, depth-1, e_blame);
    }
}

void env_set_strict(LoxStatusEnv_T& env, string name, lox::SymStatus val, Node_T e_blame) {
    auto it = env->env_.find(name);
    if (it != env->env_.end()) {
        throw lox::Error::make(fmt_str("Name already bound: {}", name), e_blame);
    }
    env->env_[name] = val;
}

void env_set_relaxed(LoxStatusEnv_T& env, string name, lox::SymStatus val) {
    env->env_[name] = val;
}

inline __attribute__((always_inline)) void env_set_relaxed(
    LoxValEnv_P env, Int name, lox::Val val) {

    env->env_[name] = val;
}

void add_val_builtins(LoxValEnv_P env) {
    env_set_relaxed(env, static_cast<Int>(lox::BuiltinId::Clock),
        lox::val_make_Builtin(lox::BuiltinId::Clock));
}

void add_status_builtins(LoxStatusEnv_T& env, Node_T e_blame) {
    env_set_strict(env, "clock", lox::SymStatus::Bound, e_blame);
}

void init_env(LoxValEnv_P env, LoxValEnv_P parent, lox::EnvOrigin origin) {
    env->parent_ = parent;
    env->origin_ = origin;
    env->fwd_loc_ = 0;
}



////////////////////////////////////////////////////////////////////////////////
// Static analysis
////////////////////////////////////////////////////////////////////////////////

struct PreprocInfo {
    Vec_T<string> output_dirs_;
    Option_T<lang::lox_pre::Node::Dir::Error_T> error_dir_;

    PreprocInfo() : output_dirs_(make_rc<Vec<string>>()) {}
};

struct Resolver {
    unordered_map<Int, Int> depths_;
    unordered_map<string, Int> str_ids_;
    Gensym_T gen_;

    bool is_inside_get_ { false };
    bool is_inside_class_ { false };
    bool is_inside_class_direct_ { false };
    bool is_inside_function_ { false };
    bool is_inside_init_direct_ { false };

    Resolver() {
        gen_ = make_rc<Gensym>();
    }

    void bind(lang::lox::Node::Expr::Id_T cc) {
        auto name = cc->name_.to_std_string();
        if (str_ids_.find(name) == str_ids_.end()) {
            auto str_id = gen_->gen();
            str_ids_[name] = str_id;
        }
        cc->extra_data_.str_id_ = str_ids_[name];
    }
};

void env_set_strict_ext(
    LoxStatusEnv_T& env, string name, lox::SymStatus val, Node_T e_blame) {

    auto it = env->env_.find(name);
    if (it != env->env_.end()) {
        throw lox::Error::make(fmt_str("Name already bound: {}", name), e_blame);
    }
    if (env->origin_ == lox::EnvOrigin::Block) {
        if (!!env->parent_ && env->parent_->origin_ == lox::EnvOrigin::Function) {
            if (env->parent_->env_.find(name) != env->parent_->env_.end()) {
                throw lox::Error::make(fmt_str("Name already bound: {}", name), e_blame);
            }
        }
    }
    env->env_[name] = val;
}

void resolve_stmt(Resolver& resolver, LoxStatusEnv_T& sym_env, Node::Stmt_T stmt);

void resolve_id_general(Resolver& resolver, LoxStatusEnv_T& sym_env, Node::Expr_T cc) {
    string name;
    if (cc->is_This()) {
        name = "this";
    } else if (cc->is_SuperField()) {
        name = "super";
    } else if (cc->is_Id()) {
        name = cc->as_Id()->name_.to_std_string();
    } else {
        AX();
    }

    auto res = sym_env->lookup_depth(name);
    if (res.is_none()) {
        if (name == "super") {
            throw lox::Error::make("`super` only valid in a class that inherits", cc);
        }
        // Attempt to match behavior of jlox (unbound ids are assumed global).
        resolver.depths_[cc->id_] = sym_env->global_env_depth();
    } else {
        auto [status, depth] = res.as_some();
        if (status == lox::SymStatus::Binding) {
            throw lox::Error::make(fmt_str("Can't use symbol in its own declaration: {}",
                name), cc);
        } else if (status == lox::SymStatus::Bound) {
            resolver.depths_[cc->id_] = depth;
        } else {
            AX();
        }
    }
}

void resolve_expr(Resolver& resolver, LoxStatusEnv_T& sym_env, Node::Expr_T expr) {
    expr->match(
        [&](Expr::Assign_T cc) {
            if (cc->x_->is_This()) {
                throw lox::Error::make("Can't assign to `this`", cc);
            }
            auto curr = cc->x_;
            while (curr->is_Get()) {
                curr = curr->as_Get()->x_;
            }
            if (curr->is_SuperField()) {
                throw lox::Error::make("Can't assign to field of `super`", cc);
            }
            resolve_expr(resolver, sym_env, cc->x_);
            resolve_expr(resolver, sym_env, cc->val_);
        },
        [&](Expr::LogOp_T cc) {
            if (cc->is_Or()) {
                resolve_expr(resolver, sym_env, cc->as_Or()->x_);
                resolve_expr(resolver, sym_env, cc->as_Or()->y_);
            } else if (cc->is_And()) {
                resolve_expr(resolver, sym_env, cc->as_And()->x_);
                resolve_expr(resolver, sym_env, cc->as_And()->y_);
            } else {
                AX();
            }
        },
        [&](Expr::BinOp_T cc_binop) {
            cc_binop->match(
                [&](Expr::BinOp::Eq_T cc) {
                    resolve_expr(resolver, sym_env, cc->x_);
                    resolve_expr(resolver, sym_env, cc->y_);
                },
                [&](Expr::BinOp::Cmp_T cc) {
                    resolve_expr(resolver, sym_env, cc->x_);
                    resolve_expr(resolver, sym_env, cc->y_);
                },
                [&](Expr::BinOp::AddSub_T cc) {
                    resolve_expr(resolver, sym_env, cc->x_);
                    resolve_expr(resolver, sym_env, cc->y_);
                },
                [&](Expr::BinOp::MulDiv_T cc) {
                    resolve_expr(resolver, sym_env, cc->x_);
                    resolve_expr(resolver, sym_env, cc->y_);
                }
            );
        },
        [&](Expr::UnaryPre_T cc) {
            resolve_expr(resolver, sym_env, cc->x_);
        },
        [&](Expr::Call_T cc) {
            resolve_expr(resolver, sym_env, cc->f_);
            for (auto arg : *cc->args_) {
                resolve_expr(resolver, sym_env, arg);
            }
        },
        [&](Expr::Get_T cc) {
            auto is_inside_get_prev = resolver.is_inside_get_;
            resolver.is_inside_get_ = true;
            resolve_expr(resolver, sym_env, cc->x_);
            resolver.is_inside_get_ = is_inside_get_prev;
            resolver.bind(cc->name_->as_Id());
        },
        [&](Expr::Id_T cc) {
            resolver.bind(cc);
            resolve_id_general(resolver, sym_env, cc);
        },
        [&](Expr::This_T cc) {
            if (!resolver.is_inside_class_) {
                throw lox::Error::make("Can't use `this` from outside of a class", cc);
            }
            resolve_id_general(resolver, sym_env, cc);
        },
        [&](Expr::SuperField_T cc) {
            resolve_id_general(resolver, sym_env, cc);
            resolver.bind(cc->name_->as_Id());
        },
        [&](Expr::Lit_T cc) {
            // pass
        },
        [&](Expr::Paren_T cc) {
            resolve_expr(resolver, sym_env, cc->x_);
        }
    );
}

void resolve_block(Resolver& resolver, LoxStatusEnv_T& sym_env, Node::Block_T block) {
    LoxStatusEnv_T sym_env_sub = sym_env->new_scope(lox::EnvOrigin::Block);
    for (auto decl : *block->decls_) {
        resolve_stmt(resolver, sym_env_sub, decl);
    }
}

void resolve_fun_body(Resolver& resolver, LoxStatusEnv_T& sym_env, Node::FunBody_T f) {
    auto name = f->name_->as_Id()->name_.to_std_string();
    bool is_init = false;
    if (name == "init" && resolver.is_inside_class_direct_) {
        is_init = true;
        f->extra_data_.is_class_init_ = true;
    }
    env_set_strict_ext(sym_env, name, lox::SymStatus::Bound, f);
    auto sym_env_sub = sym_env->new_scope(lox::EnvOrigin::Function);
    for (auto param : *f->params_) {
        env_set_strict_ext(
            sym_env_sub, param->as_Id()->name_.to_std_string(), lox::SymStatus::Bound, f);
        resolver.bind(param->as_Id());
    }
    resolver.bind(f->name_->as_Id());

    auto is_inside_class_direct_prev = resolver.is_inside_class_direct_;
    auto is_inside_function_prev = resolver.is_inside_function_;
    auto is_inside_init_direct_prev = resolver.is_inside_init_direct_;
    resolver.is_inside_class_direct_ = false;
    resolver.is_inside_function_ = true;
    resolver.is_inside_init_direct_ = is_init;
    resolve_block(resolver, sym_env_sub, f->body_);
    resolver.is_inside_class_direct_ = is_inside_class_direct_prev;
    resolver.is_inside_function_ = is_inside_function_prev;
    resolver.is_inside_init_direct_ = is_inside_init_direct_prev;
}

void resolve_stmt(Resolver& resolver, LoxStatusEnv_T& sym_env, Node::Stmt_T stmt) {
    stmt->match(
        [&](Stmt::Var_T cc) {
            auto name = cc->name_->as_Id()->name_.to_std_string();
            auto it = sym_env->env_.find(name);
            if (it != sym_env->env_.end() && !sym_env->is_global()) {
                throw lox::Error::make(fmt_str("Can't re-bind identifiers in local scopes: {}", 
                    cc->name_), cc);
            }

            if (sym_env->is_global()) {
                env_set_relaxed(sym_env, name, lox::SymStatus::Bound);
            } else {
                env_set_strict_ext(sym_env, name, lox::SymStatus::Binding, stmt);
            }
            if (cc->val_.is_some()) {
                resolve_expr(resolver, sym_env, cc->val_.as_some());
            }
            if (!sym_env->is_global()) {
                sym_env->env_[name] = lox::SymStatus::Bound;
            }

            resolver.bind(cc->name_->as_Id());
        },
        [&](Stmt::Class_T cc) {
            if (cc->base_.is_some()) {
                resolve_expr(resolver, sym_env, cc->base_.as_some());
            }

            if (cc->base_.is_some()) {
                if (cc->base_.as_some()->as_Id()->name_.to_std_string() ==
                    cc->name_->as_Id()->name_.to_std_string()) {

                    throw lox::Error::make("Class cannot inherit from itself", cc);
                }
            }

            env_set_strict_ext(
                sym_env, cc->name_->as_Id()->name_.to_std_string(), lox::SymStatus::Bound, stmt);
            resolver.bind(cc->name_->as_Id());
            if (cc->base_.is_some()) {
                resolver.bind(cc->base_.as_some()->as_Id());
            }

            auto sym_env_sub = sym_env->new_scope(lox::EnvOrigin::Class);
            env_set_strict_ext(sym_env_sub, "this", lox::SymStatus::Bound, stmt);
            if (cc->base_.is_some()) {
                env_set_strict_ext(sym_env_sub, "super", lox::SymStatus::Bound, stmt);
            }

            auto is_inside_class_prev = resolver.is_inside_class_;
            auto is_inside_class_direct_prev = resolver.is_inside_class_direct_;
            resolver.is_inside_class_ = true;
            resolver.is_inside_class_direct_ = true;
            for (auto f : *cc->funs_) {
                resolve_fun_body(resolver, sym_env_sub, f);
            }
            resolver.is_inside_class_ = is_inside_class_prev;
            resolver.is_inside_class_direct_ = is_inside_class_direct_prev;
        },
        [&](Stmt::Fun_T cc) {
            resolve_fun_body(resolver, sym_env, cc->item_);
        },
        [&](Stmt::Expr_T cc) {
            resolve_expr(resolver, sym_env, cc->x_);
        },
        [&](Stmt::Print_T cc) {
            resolve_expr(resolver, sym_env, cc->x_);
        },
        [&](Stmt::Block_T cc) {
            resolve_block(resolver, sym_env, cc->b_);
        },
        [&](Stmt::If_T cc) {
            resolve_expr(resolver, sym_env, cc->cond_);
            resolve_stmt(resolver, sym_env, cc->xt_);
        },
        [&](Stmt::IfElse_T cc) {
            resolve_expr(resolver, sym_env, cc->cond_);
            resolve_stmt(resolver, sym_env, cc->xt_);
            resolve_stmt(resolver, sym_env, cc->xf_);
        },
        [&](Stmt::While_T cc) {
            resolve_expr(resolver, sym_env, cc->cond_);
            resolve_stmt(resolver, sym_env, cc->body_);
        },
        [&](Stmt::For_T cc) {
            auto sym_env_sub = sym_env->new_scope(lox::EnvOrigin::For);

            if (cc->init_->is_Var()) {
                resolve_stmt(resolver, sym_env_sub, cc->init_->as_Var()->item_);
            } else if (cc->init_->is_Expr()) {
                resolve_expr(resolver, sym_env_sub, cc->init_->as_Expr()->item_);
            } else if (cc->init_->is_Empty()) {
                // pass
            } else {
                AX();
            }

            if (cc->cond_.is_some()) {
                resolve_expr(resolver, sym_env_sub, cc->cond_.as_some());
            }
            if (cc->incr_.is_some()) {
                resolve_expr(resolver, sym_env_sub, cc->incr_.as_some());
            }

            resolve_stmt(resolver, sym_env_sub, cc->body_);
        },
        [&](Stmt::Return_T cc) {
            if (!resolver.is_inside_function_) {
                throw lox::Error::make("Can't return from outside of a function", cc);
            }
            if (resolver.is_inside_init_direct_ && cc->v_.is_some()) {
                throw lox::Error::make("Can't return explicit value from constructor", cc);
            }
            if (cc->v_.is_some()) {
                resolve_expr(resolver, sym_env, cc->v_.as_some());
            }
        }
    );
}

void resolve_prog(Resolver& resolver, LoxStatusEnv_T& sym_env, Node::Prog_T prog) {
    for (auto decl : *prog->decls_) {
        resolve_stmt(resolver, sym_env, decl);
    }
}



////////////////////////////////////////////////////////////////////////////////
// Interpreter
////////////////////////////////////////////////////////////////////////////////

struct EvalContext {
    Resolver resolver_;
    HeapManager hm_;
    vector<lox::Val> val_stack_;
    vector<lox::Val> val_perm_;
    vector<LoxValEnv_P> env_stack_;
    vector<string> print_outputs_;

    inline void val_push(lox::Val v) {
        val_stack_.push_back(v);
    }

    inline void val_pop() {
        val_stack_.pop_back();
    }

    inline void env_push(LoxValEnv_P env) {
        env_stack_.push_back(env);
    }

    inline void env_pop() {
        env_stack_.pop_back();
    }
};

struct ScopedStackRef {
    EvalContext* ctx_;
    ScopedStackRef(EvalContext& ctx, lox::Val v): ctx_(&ctx) {
        ctx_->val_push(v);
    }
    ~ScopedStackRef() {
        ctx_->val_pop();
    }
};

void gc_heap(EvalContext* ctx) {
    for (auto p : ctx->hm_.alloc_envs_) {
        auto curr = reinterpret_cast<LoxValEnv_P>(p);
        curr->mark_ = lox::GCMark::White;
    }

    for (auto p : ctx->hm_.alloc_vals_) {
        auto curr = reinterpret_cast<lox::ValBoxed*>(p);
        curr->mark_ = lox::GCMark::White;
    }

    vector<LoxValEnv_P> Q_env;
    vector<lox::ValBoxed*> Q_val;
    for (auto curr : ctx->env_stack_) {
        if (!!curr->fwd_loc_) {
            curr = reinterpret_cast<LoxValEnv_P>(curr->fwd_loc_);
        }
        curr->mark_ = lox::GCMark::Gray;
        Q_env.push_back(curr);
    }
    for (auto curr : ctx->val_stack_) {
        if (curr.is_Boxed()) {
            curr.extract_Boxed()->mark_ = lox::GCMark::Gray;
            Q_val.push_back(curr.extract_Boxed());
        }
    }
    for (auto curr : ctx->val_perm_) {
        if (curr.is_Boxed()) {
            curr.extract_Boxed()->mark_ = lox::GCMark::Gray;
            Q_val.push_back(curr.extract_Boxed());
        }
    }

    while (!Q_env.empty() || !Q_val.empty()) {
        if (!Q_env.empty()) {
            auto curr = Q_env.back();
            Q_env.pop_back();
            curr->mark_ = lox::GCMark::Black;
            auto parent = curr->parent_;
            if (!!parent && !!parent->fwd_loc_) {
                parent = reinterpret_cast<LoxValEnv_P>(parent->fwd_loc_);
            }
            if (!!parent && parent->mark_ == lox::GCMark::White) {
                parent->mark_ = lox::GCMark::Gray;
                Q_env.push_back(parent);
            }
            for (auto [_, v] : curr->env_) {
                if (__builtin_expect(!v.is_Boxed(), 1)) {
                    continue;
                }
                auto vb = v.extract_Boxed();
                if (vb->mark_ == lox::GCMark::White) {
                    vb->mark_ = lox::GCMark::Gray;
                    Q_val.push_back(vb);
                }
            }
            if (curr->at_this_.is_Boxed()) {
                auto this_c = curr->at_this_.extract_Boxed();
                if (this_c->mark_ == lox::GCMark::White) {
                    this_c->mark_ = lox::GCMark::Gray;
                    Q_val.push_back(this_c);
                }
            }
            if (curr->at_super_.is_Boxed()) {
                auto super_c = curr->at_super_.extract_Boxed();
                if (super_c->mark_ == lox::GCMark::White) {
                    super_c->mark_ = lox::GCMark::Gray;
                    Q_val.push_back(super_c);
                }
            }
        } else if (!Q_val.empty()) {
            auto curr = Q_val.back();
            Q_val.pop_back();
            curr->mark_ = lox::GCMark::Black;
            switch (curr->w_) {
                case lox::ValBoxedWhich::String: {
                    break;
                }
                case lox::ValBoxedWhich::Closure: {
                    auto cc = curr->as_Closure_unchecked();
                    if (cc->env_->mark_ == lox::GCMark::White) {
                        cc->env_->mark_ = lox::GCMark::Gray;
                        Q_env.push_back(cc->env_);
                    }
                    if (cc->super_.w_ == lox::ValWhich::Boxed) {
                        auto super_c = cc->super_.extract_Boxed();
                        if (super_c->mark_ == lox::GCMark::White) {
                            super_c->mark_ = lox::GCMark::Gray;
                            Q_val.push_back(super_c);
                        }
                    }
                    break;
                }
                case lox::ValBoxedWhich::Class: {
                    auto cc = curr->as_Class_unchecked();
                    if (cc->super_.w_ == lox::ValWhich::Boxed) {
                        auto super_c = cc->super_.extract_Boxed();
                        if (super_c->mark_ == lox::GCMark::White) {
                            super_c->mark_ = lox::GCMark::Gray;
                            Q_val.push_back(super_c);
                        }
                    }
                    for (auto [_, v] : cc->methods_) {
                        if (v.w_ == lox::ValWhich::Boxed) {
                            auto v_c = v.extract_Boxed();
                            if (v_c->mark_ == lox::GCMark::White) {
                                v_c->mark_ = lox::GCMark::Gray;
                                Q_val.push_back(v_c);
                            }
                        }
                    }
                    break;
                }
                case lox::ValBoxedWhich::Object: {
                    auto cc = curr->as_Object_unchecked();
                    if (cc->klass_.w_ == lox::ValWhich::Boxed) {
                        auto klass_c = cc->klass_.extract_Boxed();
                        if (klass_c->mark_ == lox::GCMark::White) {
                            klass_c->mark_ = lox::GCMark::Gray;
                            Q_val.push_back(klass_c);
                        }
                    }
                    for (auto [_, v] : cc->fields_) {
                        if (v.w_ == lox::ValWhich::Boxed) {
                            auto v_c = v.extract_Boxed();
                            if (v_c->mark_ == lox::GCMark::White) {
                                v_c->mark_ = lox::GCMark::Gray;
                                Q_val.push_back(v_c);
                            }
                        }
                    }
                    break;
                }
                default: {
                    AX();
                }
            }
            if (__builtin_expect(curr->w_ != lox::ValBoxedWhich::Closure, 1)) {
                continue;
            }
        } else {
            AX();
        }
    }

    vector<void*> alloc_envs_new;
    for (auto p : ctx->hm_.alloc_envs_) {
        auto curr = reinterpret_cast<LoxValEnv_P>(p);
        if (curr->mark_ == lox::GCMark::White) {
            ctx->hm_.dealloc(curr);
        } else if (curr->mark_ == lox::GCMark::Black) {
            alloc_envs_new.push_back(p);
        } else {
            AX();
        }
    }
    ctx->hm_.alloc_envs_ = alloc_envs_new;

    vector<void*> alloc_vals_new;
    for (auto p : ctx->hm_.alloc_vals_) {
        auto curr = reinterpret_cast<lox::ValBoxed*>(p);
        if (curr->mark_ == lox::GCMark::White) {
            switch (curr->w_) {
                case lox::ValBoxedWhich::Class: {
                    ctx->hm_.dealloc(reinterpret_cast<lox::ValBoxedClass*>(p));
                    break;
                }
                case lox::ValBoxedWhich::Object: {
                    ctx->hm_.dealloc(reinterpret_cast<lox::ValBoxedObject*>(p));
                    break;
                }
                case lox::ValBoxedWhich::Closure: {
                    ctx->hm_.dealloc(reinterpret_cast<lox::ValBoxedClosure*>(p));
                    break;
                }
                case lox::ValBoxedWhich::String: {
                    ctx->hm_.dealloc(reinterpret_cast<lox::ValBoxedString*>(p));
                    break;
                }
                default: {
                    AX();
                }
            }
        } else if (curr->mark_ == lox::GCMark::Black) {
            alloc_vals_new.push_back(p);
        } else {
            AX();
        }
    }
    ctx->hm_.alloc_vals_ = alloc_vals_new;
}

LoxValEnv_P heapify_env(LoxValEnv_P env, EvalContext& ctx) {
    if (env->fwd_loc_ != 0) {
        return reinterpret_cast<LoxValEnv_P>(env->fwd_loc_);
    }
    if (!!env->parent_) {
        env->parent_ = heapify_env(env->parent_, ctx);
    }
    auto env_heap = ctx.hm_.alloc_env<lox::Env::_T<Int, lox::Val>>();
    env_heap->parent_ = env->parent_;
    env_heap->origin_ = env->origin_;
    env_heap->env_ = env->env_;
    env_heap->fwd_loc_ = reinterpret_cast<Int>(env_heap);
    env->fwd_loc_ = env_heap->fwd_loc_;
    return env_heap;
}

inline __attribute__((always_inline)) bool lox_val_eq(lox::Val x, lox::Val y, Node_S e_blame) {
    if (x.w_ != y.w_) {
        return false;
    }

    switch (x.w_) {
        case lox::ValWhich::Boolean: {
            return x.extract_Boolean() == y.extract_Boolean();
        }
        case lox::ValWhich::Nil: {
            return true;
        }
        case lox::ValWhich::Number: {
            return x.extract_Number() == y.extract_Number();
        }
        case lox::ValWhich::Builtin: {
            return val_extract_builtin(x) == val_extract_builtin(y);
        }
        case lox::ValWhich::Boxed: {
            auto xc = x.extract_Boxed();
            auto yc = y.extract_Boxed();
            if (xc->w_ != yc->w_) {
                return false;
            }
            switch (xc->w_) {
                case lox::ValBoxedWhich::String: {
                    return xc->as_String_unchecked()->s_ == yc->as_String_unchecked()->s_;
                }
                case lox::ValBoxedWhich::Closure: {
                    // Attempt to match jlox (pointer equality)
                    return reinterpret_cast<Int>(xc) == reinterpret_cast<Int>(yc);
                }
                case lox::ValBoxedWhich::Class: {
                    // Attempt to match jlox (pointer equality)
                    return reinterpret_cast<Int>(xc) == reinterpret_cast<Int>(yc);
                }
                case lox::ValBoxedWhich::Object: {
                    throw lox::Error::make(
                        "Can't compare objects for equality", node_lift(e_blame));
                }
                default: {
                    AX();
                }
            }
        }
        default: {
            AX();
        }
    }
}

using RetVal = pair<lox::Val, bool>;  // [val, is_explicit]

void stmts_eval(Vec_T<Node::Stmt_T> stmts, LoxValEnv_P env, RetVal& ret_val, Int stack_depth,
    EvalContext& ctx);
void stmt_eval(Stmt_S stmt, LoxValEnv_P env, RetVal& ret_val, Int stack_depth,
    EvalContext& ctx);
void block_eval(Block_S block, LoxValEnv_P env, RetVal& ret_val, Int stack_depth,
    EvalContext& ctx);

inline __attribute__((always_inline)) void lookup_name_check_fail(lox::Val ret_val,
    Int name, Int depth, LoxValEnv_P env, Node_S e_blame, EvalContext& ctx) {

    if (__builtin_expect(ret_val.w_ == lox::ValWhich::Uninitialized, 0)) {
        LG(" === Name lookup failure ===");
        LG("name: {}", name);
        LG("depth: {}", depth);
        LG("env: {}", env);
        auto m = ctx.resolver_.str_ids_;
        LG("names: {}", m);
        throw lox::Error::make(
            fmt_str("Identifier not bound: {}", name), node_lift(e_blame));
    }
}

inline __attribute__((always_inline)) Int lookup_id_depth(Node::_T* cc, EvalContext& ctx) {
    auto it = ctx.resolver_.depths_.find(cc->id_);
    if (it == ctx.resolver_.depths_.end()) {
        AX("Depth not found for: {}", cc);
    }
    auto depth = it->second;
    return depth;
}

inline __attribute__((always_inline)) lox::Val lookup_id_strict(
    Node::Expr::Id::_T* cc, LoxValEnv_P env, Node_S e_blame, EvalContext& ctx) {

    auto name = cc->extra_data_.str_id_;
    auto depth = lookup_id_depth(cc, ctx);
    auto curr = env;
    for (Int i = 0; i < depth; i++) {
        curr = curr->parent_;
    }
    lox::Val ret_val;
    {
        auto it = curr->env_.find(name);
        if (it != curr->env_.end()) {
            ret_val = it->second;
        }
    }
    lookup_name_check_fail(ret_val, name, depth, env, e_blame, ctx);
    return ret_val;
}

inline __attribute__((always_inline)) lox::Val lookup_this(
    Node::Expr::This::_T* cc_this, LoxValEnv_P env, Node_S e_blame,
    EvalContext& ctx) {

    auto depth = lookup_id_depth(cc_this, ctx);
    auto curr = env;
    for (Int i = 0; i < depth; i++) {
        curr = curr->parent_;
    }
    auto ret_this = curr->at_this_;
    lookup_name_check_fail(
        ret_this, static_cast<Int>(lox::BuiltinId::This), depth, env, e_blame, ctx);
    return ret_this;
}

inline __attribute__((always_inline)) pair<lox::Val, lox::Val> lookup_this_super(
    Node::Expr::SuperField::_T* cc_super, LoxValEnv_P env, Node_S e_blame,
    EvalContext& ctx) {

    auto depth = lookup_id_depth(cc_super, ctx);
    auto curr = env;
    for (Int i = 0; i < depth; i++) {
        curr = curr->parent_;
    }
    auto ret_super = curr->at_super_;
    auto ret_this = curr->at_this_;
    lookup_name_check_fail(
        ret_super, static_cast<Int>(lox::BuiltinId::Super), depth, env, e_blame, ctx);
    lookup_name_check_fail(
        ret_this, static_cast<Int>(lox::BuiltinId::This), depth, env, e_blame, ctx);
    return make_pair(ret_this, ret_super);
}

lox::ValBoxedClosure* method_search(
    lox::ValBoxedClass* val_k_search, Int name, Node_S e_blame) {

    auto it_m = val_k_search->methods_.find(name);
    while (it_m == val_k_search->methods_.end()) {
        if (val_k_search->super_.w_ == lox::ValWhich::Uninitialized) {
            throw lox::Error::make(
                fmt_str("Tried to get unbound field/method {} on object", name),
                node_lift(e_blame));
        }
        val_k_search = lox::val_extract_Class(val_k_search->super_);
        it_m = val_k_search->methods_.find(name);
    }
    auto m_raw = it_m->second;
    if (!lox::val_is_Closure(m_raw)) {
        throw lox::Error::make("Method bound to non-closure", node_lift(e_blame));
    }
    auto m_raw_c = lox::val_extract_Closure(m_raw);
    return m_raw_c;
}

lox::Val expr_eval(Expr_S expr, LoxValEnv_P env, Int stack_depth, EvalContext& ctx) {
    if (__builtin_expect(stack_depth > lox::STACK_LIMIT, 0)) {
        throw lox::Error::make("Stack overflow", node_lift(expr));
    }

    if (expr->is_Id()) {
        return lookup_id_strict(expr->as_Id_unchecked(), env, expr, ctx);

    } else if (expr->is_This()) {
        return lookup_this(expr->as_This_unchecked(), env, expr, ctx);

    } else if (expr->is_Lit()) {
        if (__builtin_expect(expr->extra_data_.v_.w_ != lox::ValWhich::Uninitialized, 1)) {
            return expr->extra_data_.v_;
        }

        auto cc = expr->as_Lit_unchecked();

        lox::Val ret;

        if (cc->is_Number()) {
            auto v = string_to_f64(cc->as_Number()->item_.to_std_string());
            ret = lox::Val::make_Number(v.as_some());

        } else if (cc->is_String()) {
            auto s = cc->as_String_unchecked()->item_.to_std_string();
            ret = lox::ValBoxedString::make(s.substr(1, s.length()-2), ctx.hm_);
            ctx.val_perm_.push_back(ret);

        } else if (cc->is_Bool()) {
            auto lit_cc = cc->as_Bool();
            if (lit_cc->is_False()) {
                ret = lox::Val::make_Boolean(false);
            } else if (lit_cc->is_True()) {
                ret = lox::Val::make_Boolean(true);
            } else {
                AX();
            }

        } else if (cc->is_Nil()) {
            ret = lox::Val::make_Nil();

        } else {
            AX();
        }

        expr->extra_data_.v_ = ret;
        return ret;

    } else if (expr->is_BinOp() && expr->as_BinOp_unchecked()->is_Eq()) {
        auto cc = expr->as_BinOp_unchecked()->as_Eq_unchecked();
        auto xv = expr_eval(cc->x_.get(), env, stack_depth+1, ctx);
        auto xv_hold = ScopedStackRef(ctx, xv);
        auto yv = expr_eval(cc->y_.get(), env, stack_depth+1, ctx);
        auto yv_hold = ScopedStackRef(ctx, yv);
        bool ret = lox_val_eq(xv, yv, cc);
        if (cc->op_->is_Eq()) {
            return lox::Val::make_Boolean(ret);
        } else if (cc->op_->is_Neq()) {
            return lox::Val::make_Boolean(!ret);
        } else {
            AX();
        }

    } else if (expr->is_BinOp() && expr->as_BinOp_unchecked()->is_Cmp()) {
        auto cc = expr->as_BinOp_unchecked()->as_Cmp_unchecked();
        auto xv = expr_eval(cc->x_.get(), env, stack_depth+1, ctx);
        auto xv_hold = ScopedStackRef(ctx, xv);
        auto yv = expr_eval(cc->y_.get(), env, stack_depth+1, ctx);
        auto yv_hold = ScopedStackRef(ctx, yv);

        if (xv.w_ != lox::ValWhich::Number || yv.w_ != lox::ValWhich::Number) {
            throw lox::Error::make(fmt_str("Can't compare non-numeric operands: {} {}", xv, yv),
                node_lift(cc));
        }

        bool ret;
        f64 xf = xv.extract_Number();
        f64 yf = yv.extract_Number();
        if (cc->op_->is_Gt()) {
            ret = xf > yf;
        } else if (cc->op_->is_Gte()) {
            ret = xf >= yf;
        } else if (cc->op_->is_Lt()) {
            ret = xf < yf;
        } else if (cc->op_->is_Lte()) {
            ret = xf <= yf;
        } else {
            AX();
        }
        return lox::Val::make_Boolean(ret);

    } else if (expr->is_BinOp() && expr->as_BinOp_unchecked()->is_AddSub()) {
        auto cc = expr->as_BinOp_unchecked()->as_AddSub_unchecked();
        auto xv = expr_eval(cc->x_.get(), env, stack_depth+1, ctx);
        auto xv_hold = ScopedStackRef(ctx, xv);
        auto yv = expr_eval(cc->y_.get(), env, stack_depth+1, ctx);
        auto yv_hold = ScopedStackRef(ctx, yv);

        if (cc->op_->is_Sub()) {
            if (xv.w_ != lox::ValWhich::Number || yv.w_ != lox::ValWhich::Number) {
                throw lox::Error::make(fmt_str("Can't subtract non-numeric operands: {} {}", xv, yv),
                    node_lift(cc));
            }
            return lox::Val::make_Number(xv.extract_Number() - yv.extract_Number());

        } else if (cc->op_->is_Add()) {
            if (xv.w_ == lox::ValWhich::Number && yv.w_ == lox::ValWhich::Number) {
                return lox::Val::make_Number(xv.extract_Number() + yv.extract_Number());
            } else if (val_is_string(xv) && val_is_string(yv)) {
                auto xs = val_extract_string(xv);
                auto ys = val_extract_string(yv);
                return lox::ValBoxedString::make(xs + ys, ctx.hm_);
            } else {
                throw lox::Error::make(fmt_str("Can't add operands that aren't either both numbers or both " +
                    string("strings: {} {}"), xv, yv), node_lift(cc));
            }

        } else {
            AX();
        }

    } else if (expr->is_BinOp() && expr->as_BinOp_unchecked()->is_MulDiv()) {
        auto cc = expr->as_BinOp_unchecked()->as_MulDiv_unchecked();
        auto xv = expr_eval(cc->x_.get(), env, stack_depth+1, ctx);
        auto xv_hold = ScopedStackRef(ctx, xv);
        auto yv = expr_eval(cc->y_.get(), env, stack_depth+1, ctx);
        auto yv_hold = ScopedStackRef(ctx, yv);

        if (cc->op_->is_Mul()) {
            if (xv.w_ != lox::ValWhich::Number || yv.w_ != lox::ValWhich::Number) {
                throw lox::Error::make(fmt_str("Can't multiply non-numeric operands: {} {}", xv, yv),
                    node_lift(cc));
            }
            return lox::Val::make_Number(xv.extract_Number() * yv.extract_Number());

        } else if (cc->op_->is_Div()) {
            if (xv.w_ != lox::ValWhich::Number || yv.w_ != lox::ValWhich::Number) {
                throw lox::Error::make(fmt_str("Can't divide non-numeric operands: {} {}", xv, yv),
                    node_lift(cc));
            }
            return lox::Val::make_Number(xv.extract_Number() / yv.extract_Number());

        } else {
            AX();
        }

    } else if (expr->is_Assign()) {
        auto cc = expr->as_Assign_unchecked();
        auto val = expr_eval(cc->val_.get(), env, stack_depth+1, ctx);
        auto val_hold = ScopedStackRef(ctx, val);
        if (cc->x_->is_Id()) {
            auto name = cc->x_->as_Id();
            lox_env_assign_strict(
                env, name->extra_data_.str_id_, val, ctx.resolver_.depths_.at(name->id_), cc);
        } else {
            auto xc = cc->x_->as_Get();
            auto v_base = expr_eval(xc->x_.get(), env, stack_depth+1, ctx);
            if (!lox::val_is_Object(v_base)) {
                throw lox::Error::make(
                    fmt_str("Tried to set field {} on non-object",
                        xc->name_->as_Id()->name_.to_std_string()), node_lift(cc));
            }
            auto v_base_c = lox::val_extract_Object(v_base);
            v_base_c->fields_[xc->name_->as_Id()->extra_data_.str_id_] = val;
        }
        return val;

    } else if (expr->is_LogOp()) {
        auto cc = expr->as_LogOp_unchecked();
        if (cc->is_Or()) {
            auto xv = expr_eval(cc->as_Or_unchecked()->x_.get(), env, stack_depth+1, ctx);
            auto xv_hold = ScopedStackRef(ctx, xv);
            if (!val_is_truthy(xv)) {
                auto yv = expr_eval(cc->as_Or_unchecked()->y_.get(), env, stack_depth+1, ctx);
                auto yv_hold = ScopedStackRef(ctx, yv);
                return yv;
            } else {
                return xv;
            }
        } else if (cc->is_And()) {
            auto xv = expr_eval(cc->as_And_unchecked()->x_.get(), env, stack_depth+1, ctx);
            auto xv_hold = ScopedStackRef(ctx, xv);
            if (val_is_truthy(xv)) {
                auto yv = expr_eval(cc->as_And_unchecked()->y_.get(), env, stack_depth+1, ctx);
                auto yv_hold = ScopedStackRef(ctx, yv);
                return yv;
            } else {
                return xv;
            }
        } else {
            AX();
        }

    } else if (expr->is_Call()) {
        auto cc = expr->as_Call_unchecked();
        
        auto f = expr_eval(cc->f_.get(), env, stack_depth+1, ctx);
        auto f_hold = ScopedStackRef(ctx, f);

        bool is_closure = val_is_Closure(f);
        bool is_builtin = f.is_Builtin();
        bool is_class = val_is_Class(f);

        if (!is_closure && !is_builtin && !is_class) {
            throw lox::Error::make(fmt_str("Can only call functions, builtins, and constructors;"
                " given instead: {}", f), node_lift(cc));
        }

        if (is_builtin) {
            auto ff = val_extract_builtin(f);
            if (ff == lox::BuiltinId::Clock) {
                if (cc->args_->length() != 0) {
                    throw lox::Error::make(fmt_str("Passed {} arguments to builtin 'clock', should be 0",
                        cc->args_->length()), node_lift(cc));
                }
                auto t = now() / 1e6;
                return lox::Val::make_Number(t);
            } else {
                AX();
            }
        }

        if (is_class) {
            auto v = lox::ValBoxedObject::make(f, ctx.hm_);
            auto fc = lox::val_extract_Class(f);
            lox::Val init_fn;
            auto curr = fc;
            while (true) {
                auto it = curr->methods_.find(static_cast<Int>(lox::BuiltinId::Init));
                if (it != curr->methods_.end()) {
                    init_fn = it->second;
                    break;
                }
                if (curr->super_.w_ == lox::ValWhich::Uninitialized) {
                    break;
                }
                curr = lox::val_extract_Class(curr->super_);
            }

            Int arity = 0;
            if (init_fn.w_ != lox::ValWhich::Uninitialized) {
                if (!lox::val_is_Closure(init_fn)) {
                    throw lox::Error::make(fmt_str("init function {} is not a closure", init_fn),
                        node_lift(cc));
                }
                auto init_fn_c = lox::val_extract_Closure(init_fn);
                arity = init_fn_c->f_->params_->length();
            }
            if (cc->args_->length() != arity) {
                throw lox::Error::make(fmt_str("Passed {} arguments to constructor, should be {}",
                    cc->args_->length(), arity), node_lift(cc));
            }

            if (init_fn.w_ != lox::ValWhich::Uninitialized) {
                auto init_fn_c = lox::val_extract_Closure(init_fn);
                lox::Env::_T<Int, lox::Val> env_sub;
                init_env(&env_sub, init_fn_c->env_, lox::EnvOrigin::Class);
                ctx.env_push(&env_sub);
                env_sub.at_this_ = v;
                if (init_fn_c->super_.w_ != lox::ValWhich::Uninitialized) {
                    env_sub.at_super_ = init_fn_c->super_;
                }

                lox::Env::_T<Int, lox::Val> env_sub2;
                init_env(&env_sub2, &env_sub, lox::EnvOrigin::Function);
                ctx.env_push(&env_sub2);
                for (int i = 0; i < init_fn_c->f_->params_->length(); i++) {
                    auto val = expr_eval(cc->args_->at_unchecked(i).get(), env, stack_depth+1, ctx);
                    env_set_relaxed(&env_sub2,
                        init_fn_c->f_->params_->at_unchecked(i)->extra_data_.str_id_, val);
                }

                RetVal ret_val;
                block_eval(init_fn_c->f_->body_.get(), &env_sub2, ret_val, stack_depth+1, ctx);

                ctx.env_pop();
                ctx.env_pop();
            }

            return v;
        }

        auto fc = val_extract_Closure(f);
        if (fc->f_->params_->length() != cc->args_->length()) {
            throw lox::Error::make(fmt_str("Expected {} arguments. given {}",
                fc->f_->params_->length(), cc->args_->length()), node_lift(cc));
        }

        lox::Env::_T<Int, lox::Val> env_sub;
        auto env_sub_addr = &env_sub;
        init_env(env_sub_addr, fc->env_, lox::EnvOrigin::Function);
        ctx.env_push(env_sub_addr);

        for (int i = 0; i < fc->f_->params_->length(); i++) {
            auto val = expr_eval(cc->args_->at_unchecked(i).get(), env, stack_depth+1, ctx);
            env_set_relaxed(
                env_sub_addr, fc->f_->params_->at_unchecked(i)->extra_data_.str_id_, val);
        }

        RetVal ret_val;
        block_eval(fc->f_->body_.get(), env_sub_addr, ret_val, stack_depth+1, ctx);
        if (!!env_sub_addr->fwd_loc_) {
            env_sub_addr = reinterpret_cast<LoxValEnv_P>(env_sub_addr->fwd_loc_);
        }

        if (fc->f_->extra_data_.is_class_init_) {
            if (ret_val.first.w_ != lox::ValWhich::Uninitialized &&
                ret_val.second == true) {
                throw lox::Error::make(
                    "Cannot explicitly return from class initializer", node_lift(cc));
            }

            auto v = fc->env_->at_this_;
            if (__builtin_expect(v.w_ == lox::ValWhich::Uninitialized, 0)) {
                throw lox::Error::make(
                    "Tried to implicit-return from init without `this` object bound",
                    node_lift(cc));
            }
            ret_val = make_pair(v, false);
        }

        ctx.env_pop();

        if (ret_val.first.w_ == lox::ValWhich::Uninitialized) {
            return lox::Val::make_Nil();
        } else {
            return ret_val.first;
        }

    } else if (expr->is_SuperField()) {
        auto cc = expr->as_SuperField_unchecked();

        auto [val_r, val_k_search_r] = lookup_this_super(cc, env, cc, ctx);
        auto val = val_r;
        auto val_k_search = lox::val_extract_Class(val_k_search_r);

        auto name = cc->name_->extra_data_.str_id_;

        auto m_raw_c = method_search(val_k_search, name, cc);

        auto env_sub = ctx.hm_.alloc_env<lox::Env::_T<Int, lox::Val>>();
        env_sub->parent_ = m_raw_c->env_;
        env_sub->origin_ = lox::EnvOrigin::Class;
        env_sub->fwd_loc_ = reinterpret_cast<Int>(env_sub);
        env_sub->at_this_ = val;
        if (m_raw_c->super_.w_ != lox::ValWhich::Uninitialized) {
            env_sub->at_super_ = m_raw_c->super_;
        }
        return lox::ValBoxedClosure::make(m_raw_c->f_, lox::Val(), env_sub, ctx.hm_);

    } else if (expr->is_Get()) {
        auto cc = expr->as_Get_unchecked();

        lox::Val val = expr_eval(cc->x_.get(), env, stack_depth+1, ctx);
        auto val_hold = ScopedStackRef(ctx, val);

        if (!lox::val_is_Object(val)) {
            throw lox::Error::make(
                fmt_str("Tried to get field {} on non-object",
                    cc->name_->as_Id()->name_.to_std_string()), node_lift(cc));
        }
        auto val_c = lox::val_extract_Object(val);
        auto val_k_search = lox::val_extract_Class(val_c->klass_);

        auto name = cc->name_->extra_data_.str_id_;
        auto it = val_c->fields_.find(name);
        if (it != val_c->fields_.end()) {
            return it->second;
        }

        auto m_raw_c = method_search(val_k_search, name, cc);

        auto env_sub = ctx.hm_.alloc_env<lox::Env::_T<Int, lox::Val>>();
        env_sub->parent_ = m_raw_c->env_;
        env_sub->origin_ = lox::EnvOrigin::Class;
        env_sub->fwd_loc_ = reinterpret_cast<Int>(env_sub);
        env_sub->at_this_ = val;
        if (m_raw_c->super_.w_ != lox::ValWhich::Uninitialized) {
            env_sub->at_super_ = m_raw_c->super_;
        }
        return lox::ValBoxedClosure::make(m_raw_c->f_, lox::Val(), env_sub, ctx.hm_);

    } else if (expr->is_UnaryPre()) {
        auto cc = expr->as_UnaryPre_unchecked();
        auto val = expr_eval(cc->x_.get(), env, stack_depth+1, ctx);
        auto val_hold = ScopedStackRef(ctx, val);
        if (cc->op_->is_Neg()) {
            if (val.w_ != lox::ValWhich::Number) {
                throw lox::Error::make(fmt_str("Can't negate non-numeric Val: {}", val),
                    node_lift(cc));
            }
            return lox::Val::make_Number(-val.extract_Number());
        } else if (cc->op_->is_Not()) {
            return lox::Val::make_Boolean(!val_is_truthy(val));
        } else {
            AX();
        }

    } else if (expr->is_Paren()) {
        auto cc = expr->as_Paren_unchecked();
        return expr_eval(cc->x_.get(), env, stack_depth+1, ctx);

    } else {
        AX("expr_eval: {}", node_lift(expr));
    }
}

inline __attribute__((always_inline)) void block_eval(
    Block_S block, LoxValEnv_P env, RetVal& ret_val, Int stack_depth, EvalContext& ctx) {

    if (__builtin_expect(stack_depth > lox::STACK_LIMIT, 0)) {
        throw lox::Error::make("Stack overflow", node_lift(block));
    }

    lox::Env::_T<Int, lox::Val> env_sub;
    auto env_sub_addr = &env_sub;
    init_env(env_sub_addr, env, lox::EnvOrigin::Block);
    ctx.env_push(env_sub_addr);
    stmts_eval(block->decls_, env_sub_addr, ret_val, stack_depth+1, ctx);
    ctx.env_pop();
}

void stmt_eval(Stmt_S stmt, LoxValEnv_P env, RetVal& ret_val, Int stack_depth,
    EvalContext& ctx) {

    if (__builtin_expect(stack_depth > lox::STACK_LIMIT, 0)) {
        throw lox::Error::make("Stack overflow", node_lift(stmt));
    }

    if (stmt->is_Expr()) {
        auto cc = stmt->as_Expr_unchecked();
        expr_eval(cc->x_.get(), env, stack_depth+1, ctx);

    } else if (stmt->is_Block()) {
        auto cc = stmt->as_Block_unchecked();
        block_eval(cc->b_.get(), env, ret_val, stack_depth+1, ctx);

    } else if (stmt->is_Print()) {
        auto cc = stmt->as_Print_unchecked();
        auto v = expr_eval(cc->x_.get(), env, stack_depth+1, ctx);
        ScopedStackRef v_hold(ctx, v);
        auto s = fmt_str("{}", v);
        for (auto si : str_split(s, "\n")) {
            ctx.print_outputs_.push_back(si);
        }
        fmt(cerr, "{}\n", s);

    } else if (stmt->is_If()) {
        auto cc = stmt->as_If_unchecked();
        auto cond = expr_eval(cc->cond_.get(), env, stack_depth+1, ctx);
        if (val_is_truthy(cond)) {
            stmt_eval(cc->xt_.get(), env, ret_val, stack_depth+1, ctx);
        }

    } else if (stmt->is_IfElse()) {
        auto cc = stmt->as_IfElse_unchecked();
        auto cond = expr_eval(cc->cond_.get(), env, stack_depth+1, ctx);
        if (val_is_truthy(cond)) {
            stmt_eval(cc->xt_.get(), env, ret_val, stack_depth+1, ctx);
        } else {
            stmt_eval(cc->xf_.get(), env, ret_val, stack_depth+1, ctx);
        }

    } else if (stmt->is_While()) {
        auto cc = stmt->as_While_unchecked();
        auto cond = expr_eval(cc->cond_.get(), env, stack_depth+1, ctx);
        while (val_is_truthy(cond)) {
            stmt_eval(cc->body_.get(), env, ret_val, stack_depth+1, ctx);
            if (!!env->fwd_loc_) {
                env = reinterpret_cast<LoxValEnv_P>(env->fwd_loc_);
            }
            if (ret_val.first.w_ != lox::ValWhich::Uninitialized) {
                return;
            }
            cond = expr_eval(cc->cond_.get(), env, stack_depth+1, ctx);
        }

    } else if (stmt->is_For()) {
        auto cc = stmt->as_For_unchecked();

        lox::Env::_T<Int, lox::Val> env_sub;
        auto env_sub_addr = &env_sub;
        init_env(env_sub_addr, env, lox::EnvOrigin::For);
        ctx.env_push(env_sub_addr);
        
        if (cc->init_->is_Var()) {
            stmt_eval(cc->init_->as_Var()->item_.get(), &env_sub, ret_val, stack_depth+1, ctx);
            if (!!env_sub_addr->fwd_loc_) {
                env_sub_addr = reinterpret_cast<LoxValEnv_P>(env_sub_addr->fwd_loc_);
            }
            // Note: no need to check ret_val because a Var Decl cannot return.
        } else if (cc->init_->is_Expr()) {
            expr_eval(cc->init_->as_Expr()->item_.get(), env_sub_addr, stack_depth+1, ctx);
        } else if (cc->init_->is_Empty()) {
            // pass
        } else {
            AX();
        }

        while (true) {
            if (cc->cond_.is_some()) {
                auto cond = expr_eval(cc->cond_.as_some().get(), env_sub_addr, stack_depth+1, ctx);
                if (!val_is_truthy(cond)) {
                    break;
                }
            }
            stmt_eval(cc->body_.get(), env_sub_addr, ret_val, stack_depth+1, ctx);
            if (!!env_sub_addr->fwd_loc_) {
                env_sub_addr = reinterpret_cast<LoxValEnv_P>(env_sub_addr->fwd_loc_);
            }
            if (ret_val.first.w_ != lox::ValWhich::Uninitialized) {
                ctx.env_pop();
                return;
            }
            if (cc->incr_.is_some()) {
                expr_eval(cc->incr_.as_some().get(), env_sub_addr, stack_depth+1, ctx);
            }
        }

        ctx.env_pop();

    } else if (stmt->is_Return()) {
        auto cc = stmt->as_Return();
        if (cc->v_.is_some()) {
            auto v = expr_eval(cc->v_.as_some().get(), env, stack_depth+1, ctx);
            ret_val = make_pair(v, true);
        } else {
            ret_val = make_pair(lox::Val::make_Nil(), false);
        }

    } else if (stmt->is_Var()) {
        auto cc = stmt->as_Var();
        auto name = cc->name_->extra_data_.str_id_;
        auto it = env->env_.find(name);
        if (it != env->env_.end() && !env->is_global()) {
            throw lox::Error::make(fmt_str("Var name already bound: {}", name), node_lift(stmt));
        }
        if (cc->val_.is_some()) {
            auto val = expr_eval(cc->val_.as_some().get(), env, stack_depth+1, ctx);
            env_set_relaxed(env, name, val);
        } else {
            env_set_relaxed(env, name, lox::Val::make_Nil());
        }

    } else if (stmt->is_Fun()) {
        auto cc = stmt->as_Fun();
        auto name = cc->item_->name_->extra_data_.str_id_;
        auto it = env->env_.find(name);
        if (it != env->env_.end()) {
            throw lox::Error::make(fmt_str("Function name already bound: {}", name), node_lift(stmt));
        }

        env = heapify_env(env, ctx);
        auto v = lox::ValBoxedClosure::make(cc->item_, lox::Val(), env, ctx.hm_);
        env_set_relaxed(env, name, v);

    } else if (stmt->is_Class()) {
        auto cc = stmt->as_Class_unchecked();
        auto name = cc->name_->extra_data_.str_id_;
        auto it = env->env_.find(name);
        if (it != env->env_.end()) {
            throw lox::Error::make(fmt_str("Class name already bound: {}", name), node_lift(stmt));
        }
        env = heapify_env(env, ctx);
        lox::Val super;
        if (cc->base_.is_some()) {
            super = lookup_id_strict(cc->base_.as_some()->as_Id_unchecked(), env, cc, ctx);
        }
        if (super.w_ != lox::ValWhich::Uninitialized && !lox::val_is_Class(super)) {
            throw lox::Error::make("Superclass must be a class", node_lift(stmt));
        }
        unordered_map<Int, lox::Val> methods;
        for (auto f : *cc->funs_) {
            auto name = f->name_->as_Id()->extra_data_.str_id_;
            auto fv = lox::ValBoxedClosure::make(f, super, env, ctx.hm_);
            methods[name] = fv;
        }
        auto v = lox::ValBoxedClass::make(
            cc->name_->as_Id()->name_.to_std_string(), super, methods, ctx.hm_);
        env_set_relaxed(env, name, v);

    } else {
        AX("stmt_eval: {}", node_lift(stmt));
    }

    if (ret_val.first.w_ == lox::ValWhich::Uninitialized) {
        ctx.hm_.check_gc();
    }
}

inline __attribute__((always_inline)) void stmts_eval(
    Vec_T<Node::Stmt_T> stmts, LoxValEnv_P env, RetVal& ret_val, Int stack_depth,
    EvalContext& ctx) {

    for (auto& stmt : *stmts) {
        if (__builtin_expect(stmt->is_Expr(), 1)) {
            expr_eval(stmt->as_Expr_unchecked()->x_.get(), env, stack_depth+1, ctx);
            if (!!env->fwd_loc_) {
                env = reinterpret_cast<LoxValEnv_P>(env->fwd_loc_);
            }
            continue;
        }

        stmt_eval(stmt.get(), env, ret_val, stack_depth+1, ctx);
        if (!!env->fwd_loc_) {
            env = reinterpret_cast<LoxValEnv_P>(env->fwd_loc_);
        }
        if (ret_val.first.w_ != lox::ValWhich::Uninitialized) {
            return;
        }
    }
}



////////////////////////////////////////////////////////////////////////////////
// Main processing function
////////////////////////////////////////////////////////////////////////////////

bool lox_proc_file(string filename) {
    auto A = make_rc<Arena>();

    auto input = read_file_shared(filename, A.get());
    PreprocInfo pre;

    langcc::ParseOutput_T<
        lang::lox_pre::Node::_T, lang::lox_pre::parser::action_by_vertex,
        lang::lox_pre::parser::vertex_dfa_step> parse_pre;
    try {
        auto L_pre = lang::lox_pre::init();
        auto Q_pre = L_pre->quote_env();
        parse_pre = L_pre->parse_ext(input, None<string>(), Q_pre->gen_, A.get());

        if (!parse_pre->is_success()) {
            LG("\nPreprocessor parse error: {}\n", parse_pre->err_.as_some());
            return false;
        }

        visit_lang_lox_pre_Node(parse_pre->res_.as_some(), [&](lang::lox_pre::Node_T x) {
            if (!x->is_Dir()) {
                return;
            }
            auto cc = x->as_Dir();
            if (cc->is_Output()) {
                auto s = cc->as_Output()->item_.to_std_string();
                auto kl = string("// expect: ").length();
                auto kr = string("\n").length();
                auto x = s.substr(kl, s.size()-kl-kr);
                pre.output_dirs_->push(x);
            } else if (cc->is_Error()) {
                if (pre.error_dir_.is_some()) {
                    throw lox::ErrorPre::make("Multiple error directives in single file", cc);
                }
                pre.error_dir_ = Some<lang::lox_pre::Node::Dir::Error_T>(cc->as_Error());
            } else {
                AX();
            }
        });
    } catch (lox::ErrorPre_T err) {
        LG("\nPreprocessor error: {}\n{}",
            err->desc_,
            parse_pre->lex_->location_fmt_str(err->e_blame_->bounds_));
        return false;
    }

    auto L = lang::lox::init();
    auto Q = L->quote_env();
    auto parse = L->parse_ext(input, None<string>(), Q->gen_, A.get());

    if (!parse->is_success()) {
        LG_ERR("\nParse error: {}\n", parse->err_.as_some());
        if (pre.error_dir_.is_some()) {
            return pre.error_dir_.as_some()->is_Static();
        } else {
            return false;
        }
    }

    EvalContext ctx;
    ctx.hm_.eval_ctx_ = &ctx;

    auto prog = parse->res_.as_some()->as_Prog();

    ctx.resolver_.gen_->gen();  // Uninitialized
    ctx.resolver_.str_ids_["init"] = static_cast<Int>(lox::BuiltinId::Init);
    ctx.resolver_.gen_->gen();
    ctx.resolver_.str_ids_["this"] = static_cast<Int>(lox::BuiltinId::This);
    ctx.resolver_.gen_->gen();
    ctx.resolver_.str_ids_["super"] = static_cast<Int>(lox::BuiltinId::Super);
    ctx.resolver_.gen_->gen();
    ctx.resolver_.str_ids_["clock"] = static_cast<Int>(lox::BuiltinId::Clock);
    ctx.resolver_.gen_->gen();

    try {
        auto sym_env = lox::Env::make_ext<string, lox::SymStatus>(
            nullptr,
            unordered_map<string, lox::SymStatus>(),
            lox::SymStatus::Unbound,
            lox::SymStatus::Unbound,
            nullptr,
            lox::EnvOrigin::Global,
            0,
            lox::GCMark::White);
        sym_env->fwd_loc_ = reinterpret_cast<Int>(sym_env.get());
        add_status_builtins(sym_env, prog);
        resolve_prog(ctx.resolver_, sym_env, prog);

    } catch (const lox::Error_T& err) {
        LG("\nError (static): {}\n{}",
            err->desc_,
            parse->lex_->location_fmt_str(err->e_blame_->bounds_));

        if (pre.error_dir_.is_some()) {
            return pre.error_dir_.as_some()->is_Static();
        } else {
            return false;
        }
    }

    try {
        lox::Env::_T<Int, lox::Val> global_env;
        init_env(&global_env, nullptr, lox::EnvOrigin::Global);
        add_val_builtins(&global_env);
        ctx.env_push(&global_env);
        RetVal ret_val;
        stmts_eval(prog->decls_, &global_env, ret_val, 0, ctx);
        ctx.env_pop();
        ctx.val_perm_.clear();
        AT(ctx.val_stack_.size() == 0);
        ctx.hm_.do_gc();

    } catch (const lox::Error_T& err) {
        LG("\nError (dynamic): {}\n{}",
            err->desc_,
            parse->lex_->location_fmt_str(err->e_blame_->bounds_));

        ctx.env_stack_.clear();
        ctx.val_perm_.clear();
        ctx.val_stack_.clear();
        ctx.hm_.do_gc();

        if (pre.error_dir_.is_some()) {
            return pre.error_dir_.as_some()->is_Dynamic();
        } else {
            return false;
        }
    }

    if (pre.error_dir_.is_none() && pre.output_dirs_->length() == 0) {
        return true;
    }

    if (pre.error_dir_.is_some()) {
        LG("Unexpected success");
        return false;
    }

    auto out_exp = pre.output_dirs_;
    if (ctx.print_outputs_.size() != out_exp->length()) {
        LG("Error: expected {} print outputs, received {}", out_exp->length(),
            ctx.print_outputs_.size());
        return false;
    }

    for (Int i = 0; i < ctx.print_outputs_.size(); i++) {
        if (ctx.print_outputs_[i] != out_exp->operator[](i)) {
            LG("Error: expected print output `{}`, received `{}` ({})",
                out_exp->operator[](i), ctx.print_outputs_[i], i);
            return false;
        }
    }

    return true;
}
