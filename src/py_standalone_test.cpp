
#include "py__gen.hpp"

using namespace langcc;

void parse_file(lang::py::LangDesc_T L, string input_path) {
    {
        auto A = make_rc<Arena>();
        auto input = read_file_shared(input_path, A.get());
        auto gen = make_rc<Gensym>();
        auto parse = L->parse_ext(input, None<string>(), gen, A.get());
        if (!parse->is_success()) {
            LG_ERR("Input path: {}", input_path);
            LG_ERR("{}\n", parse->err_.as_some());
            AX();
        }
    }
}

int main(int argc, char** argv) {
    global_init();

    auto L = lang::py::init();

    Int num_iter = 1;
    if (argc == 1) {
        num_iter = 1;
    } else if (argc == 2) {
        string num_iter_str = argv[1];
        num_iter = string_to_int(num_iter_str).as_some();
    } else {
        LG_ERR("Usage: py_standalone_test [num_iter]");
        exit(1);
    }

    AR_ge(num_iter, 1);

    if (!std::filesystem::exists("../cpython")) {
        LG_ERR("Requires Python (CPython) 3.9.12 sources in ../cpython directory");
        exit(1);
    }

    auto mn = read_file("data/py_manifest_gen.txt");
    auto mn_ls = str_split(mn.substr(0, len(mn)-1), "\n");

    for (const auto& arg : mn_ls) {
        for (Int j = 0; j < num_iter; j++) {
            parse_file(L, arg);
        }
    }

    return 0;
}
