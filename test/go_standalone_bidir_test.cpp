
#include "go__gen.hpp"

using namespace langcc;

namespace langcc {
    void pr(ostream& os, FmtFlags flags, lang::go::Node_T x) {
        x->write(os, flags);
    }
}

lang::go::Node_T parse_string(lang::go::QuoteEnv_T Q, string input, string input_path) {
    {
        auto parse = Q->L_->parse_ext(
            vec_from_std_string(input), None<string>(), Q->gen_, nullptr);
        if (!parse->is_success()) {
            LG_ERR("Input path: {}", input_path);
            LG_ERR("{}\n", parse->err_.as_some());
            AX();
        }
        return parse->res_.as_some();
    }
}

lang::go::Node_T parse_file(lang::go::QuoteEnv_T Q, string input_path) {
    auto input = read_file(input_path);
    return parse_string(Q, input, input_path);
}

int main(int argc, char** argv) {
    global_init();

    auto L = lang::go::init();
    auto Q = L->quote_env();

    if (!std::filesystem::exists("../go")) {
        LG_ERR("Requires Golang 1.17.8 sources in ../go directory");
        exit(1);
    }

    auto mn = read_file("data/golang_manifest_gen.txt");
    auto mn_ls = str_split(mn.substr(0, len(mn)-1), "\n");

    for (const auto& arg : mn_ls) {
        auto prog = parse_file(Q, arg);
        auto s = fmt_str("{}", prog);
        auto prog_chk = parse_string(Q, s, arg);
        if (val_hash(prog) != val_hash(prog_chk)) {
            LG_ERR("=====");
            cerr << s << endl;
            LG_ERR("=====");
            LG_ERR("Re-parse mismatch: {}", arg);
            AX();
        }
        auto s_chk = fmt_str("{}", prog_chk);
        if (s != s_chk) {
            LG_ERR("Re-print mismatch: {}", arg);
            AX();
        }
    }

    return 0;
}
