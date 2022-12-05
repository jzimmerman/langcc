#include "lox.hpp"

using namespace langcc;
using namespace lox;

int main(i32 argc, char** argv) {
    global_init();
    set_log_level(1);

    if (argc > 1) {
        AT(argc == 2);
        string test_name = argv[1];
        bool ok = lox_proc_file(test_name);
        return ok ? 0 : 1;
    }

    vector<string> ss;
    try {
        for (const auto& entry : std::filesystem::directory_iterator("test")) {
            for (const auto& entry2 : std::filesystem::directory_iterator(entry.path())) {
                if (!entry2.is_regular_file()) {
                    AX("Tests must be exactly two levels deep");
                }
                string path = entry2.path();
                ss.push_back(path);
            }
        }
    } catch (std::exception& exn) {
        LG_ERR("Exception: {}", exn.what());
        AX();
    }

    for (auto s : ss) {
        register_unit_test(s, [s]() {
            bool file_success = lox_proc_file(s);
            AT(file_success);
        });
    }

    bool success = run_unit_tests(60*G_);
    return success ? 0 : 1;
}
