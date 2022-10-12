#include "calc__gen.hpp"

using namespace lang::calc;
using namespace lang::calc::Node;

struct CalcError {
    string desc_;
    Node_T e_blame_;
    CalcError(string desc, Node_T e_blame) : desc_(desc), e_blame_(e_blame) {}
};

Int expr_eval(Expr_T e, const unordered_map<string, Int>& env) {
    return e->match_expr<Int>(
        [&](Expr::Id_T cc) {
            auto name = e->as_Id()->name_.to_std_string();
            if (env.find(name) == env.end()) {
                throw CalcError(fmt_str("Name not bound: {}", name), e);
            }
            return env.at(name);
        },
        [&](Expr::UnaryPre_T cc) {
            auto xr = expr_eval(cc->x_, env);
            if (cc->op_->is_Neg()) {
                return - xr;
            } else {
                AX();
            }
        },
        [&](Expr::BinOp1_T cc) {
            auto xr = expr_eval(cc->x_, env);
            auto yr = expr_eval(cc->y_, env);
            if (cc->op_->is_Add()) {
                return xr + yr;
            } else if (cc->op_->is_Sub()) {
                return xr - yr;
            } else {
                AX();
            }
        },
        [&](Expr::BinOp2_T cc) {
            auto xr = expr_eval(cc->x_, env);
            auto yr = expr_eval(cc->y_, env);
            if (cc->op_->is_Mul()) {
                return xr * yr;
            } else if (cc->op_->is_Div()) {
                if (yr == 0) {
                    throw CalcError(fmt_str("Division by zero"), cc->op_);
                }
                return xr / yr;
            } else {
                AX();
            }
        },
        [&](Expr::BinOp3_T cc) {
            auto xr = expr_eval(cc->x_, env);
            auto yr = expr_eval(cc->y_, env);
            if (cc->op_->is_Pow()) {
                return static_cast<Int>(pow(xr, yr) + 0.5);
            } else {
                AX();
            }
        },
        [&](Expr::Paren_T cc) {
            return expr_eval(cc->x_, env);
        },
        [&](Expr::Lit_T cc) {
            auto val_str = cc->as_Int_()->val_.to_std_string();
            return string_to_int(val_str).as_some();
        });
}

Int stmt_eval(Stmt_T stmt, unordered_map<string, Int>& env) {
    if (stmt->is_Assign()) {
        auto name = stmt->as_Assign()->x_->as_Id()->name_.to_std_string();
        auto val = expr_eval(stmt->as_Assign()->y_, env);
        env[name] = val;
        return val;
    } else if (stmt->is_Expr()) {
        return expr_eval(stmt->as_Expr()->x_, env);
    } else {
        AX();
    }
}

bool is_const_zero(Expr_T e) {
    if (e->is_Lit() && e->as_Lit()->is_Int_()) {
        return string_to_int(e->as_Lit()->as_Int_()->val_.to_std_string()).as_some() == 0;
    }
    return false;
}

Expr_T expr_simpl(Expr_T e, QuoteEnv_T Q) {
    unordered_map<string, Int> empty_env;
    try {
        return xform_lang_calc_Node(e, [&](Node_T node) -> Node_T {
            if (node->is_Expr()) {
                auto cc = node->as_Expr();
                if (cc->is_BinOp1()) {
                    auto cr = cc->as_BinOp1();
                    if (cr->x_->is_Lit() && cr->y_->is_Lit()) {
                        return Q->qq("Expr", fmt_str("{}", expr_eval(cc, empty_env)));
                    }
                    if (cr->op_->is_Add() && is_const_zero(cr->x_)) {
                        return cr->y_;
                    }
                    if (cr->op_->is_Add() && is_const_zero(cr->y_)) {
                        return cr->x_;
                    }
                    if (cr->op_->is_Sub() && is_const_zero(cr->y_)) {
                        return cr->x_;
                    }
                } else if (cc->is_BinOp2()) {
                    auto cr = cc->as_BinOp2();
                    if (cr->x_->is_Lit() && cr->y_->is_Lit()) {
                        return Q->qq("Expr", fmt_str("{}", expr_eval(cc, empty_env)));
                    }
                    if (cr->op_->is_Mul() && is_const_zero(cr->x_)) {
                        return cr->x_;
                    }
                    if (cr->op_->is_Mul() && is_const_zero(cr->y_)) {
                        return cr->y_;
                    }
                } else if (cc->is_BinOp3()) {
                    if (cc->as_BinOp3()->x_->is_Lit() && cc->as_BinOp3()->x_->is_Lit()) {
                        return Q->qq("Expr", fmt_str("{}", expr_eval(cc, empty_env)));
                    }
                }
            }
            return node;
        });
    } catch (const CalcError& err) {
        return e;
    }
}

int main(int argc, char** argv) {
    global_init();
    set_log_level(1);

    bool simpl = false;
    if (argc == 2) {
        if (string(argv[1]) == "-s") {
            simpl = true;
        }
    }

    auto L = lang::calc::init();
    auto Q = L->quote_env();
    unordered_map<string, Int> env;
    string l;

    while (true) {
        getline(cin, l);
        if (!cin.good()) {
            return 0;
        }

        auto gen = make_rc<Gensym>();
        auto parse = L->parse_ext(
            vec_from_std_string(l), None<string>(), gen, nullptr);

        if (!parse->is_success()) {
            LG_ERR("\nParse error: {}\n", parse->err_.as_some());
            continue;
        }

        auto stmt = parse->res_.as_some()->as_Stmt();

        if (simpl) {
            if (!stmt->is_Expr()) {
                LG_ERR("\nError: statements not supported in simplification mode: {}",
                    parse->lex_->location_fmt_str(stmt->bounds_));
            }
            auto e = stmt->as_Expr()->x_;
            Node_T r = expr_simpl(e, Q);
            r->write(cout, FmtFlags{});
            cout << endl;
        } else {
            try {
                fmt(cout, "{}\n", stmt_eval(stmt, env));
            } catch (const CalcError& err) {
                LG_ERR("\nError: {}\n{}",
                    err.desc_,
                    parse->lex_->location_fmt_str(err.e_blame_->bounds_));
                continue;
            }
        }
    }

    return 0;
}
