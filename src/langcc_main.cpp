
#include "langcc.hpp"

#include "common.hpp"

int main(int argc, char** argv) {
    global_init();
    set_log_level(0);

    auto args = make_rc<Vec<string>>();
    auto params = make_rc<Vec<string>>();
    for (Int i = 1; i < argc; i++) {
        if (str_starts_with(argv[i], "-")) {
            params->push(argv[i]);
        } else {
            args->push(argv[i]);
        }
    }

    if (args->length() != 2) {
        fmt(cerr, "Usage: langcc [options] src.lang dst_dir\n");
        return 1;
    }

    Int log_level = 1;
    for (auto param : *params) {
        if (param == "-q") {
            log_level = 0;
        } else if (param == "-v") {
            log_level = 1;
        } else if (param == "-vv") {
            log_level = 2;
        } else if (param == "-vvv") {
            log_level = 3;
        } else if (param == "-vvvv") {
            log_level = 4;
        } else {
            LG_ERR("Parameter not recognized: {}", param);
            return 1;
        }
    }
    set_log_level(log_level);

    string src_path = args->operator[](0);
    string dst_path = args->operator[](1);

    auto stat = compile_lang_full(src_path, dst_path, true);
    if (stat->is_Error()) {
        LG_ERR("langcc compile error:\n\n{}\n\n", stat->as_Error());
        return 1;
    }

    return 0;
}
