#include "calc__gen.hpp"

using namespace lang::calc;
using namespace lang::calc::Node;

struct CalcError {
    string desc_;
    Node_T e_blame_;
    CalcError(string desc, Node_T e_blame) : desc_(desc), e_blame_(e_blame) {}
};

Int expr_eval(Expr_T e, const unordered_map<string, Int>& env) {
    if (e->is_Lit()) {
        auto val_str = e->as_Lit()->as_Int_()->val_.to_std_string();
        return string_to_int(val_str).as_some();
    } else if (e->is_Id()) {
        auto name = e->as_Id()->name_.to_std_string();
        if (env.find(name) == env.end()) {
            throw CalcError(fmt_str("Name not bound: {}", name), e);
        }
        return env.at(name);
    } else if (e->is_BinOp1()) {
        auto cc = e->as_BinOp1();
        auto xr = expr_eval(cc->x_, env);
        auto yr = expr_eval(cc->y_, env);
        if (cc->op_->is_Add()) {
            return xr + yr;
        } else if (cc->op_->is_Sub()) {
            return xr - yr;
        } else {
            AX();
        }
    } else if (e->is_BinOp2()) {
        auto cc = e->as_BinOp2();
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
    } else if (e->is_BinOp3()) {
        auto cc = e->as_BinOp3();
        auto xr = expr_eval(cc->x_, env);
        auto yr = expr_eval(cc->y_, env);
        if (cc->op_->is_Pow()) {
            return static_cast<Int>(pow(xr, yr) + 0.5);
        } else {
            AX();
        }
    } else if (e->is_UnaryPre()) {
        auto cc = e->as_UnaryPre();
        auto xr = expr_eval(cc->x_, env);
        if (cc->op_->is_Neg()) {
            return - xr;
        } else {
            AX();
        }
    } else if (e->is_Paren()) {
        return expr_eval(e->as_Paren()->x_, env);
    } else {
        AX();
    }
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

int main() {
    global_init();
    set_log_level(1);

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
        try {
            fmt(cerr, "{}\n", stmt_eval(stmt, env));
        } catch (const CalcError& err) {
            LG_ERR("\nError: {}\n{}",
                err.desc_,
                parse->lex_->location_fmt_str(err.e_blame_->bounds_));
            continue;
        }
    }

    return 0;
}
