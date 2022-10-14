
#include "langcc_util.hpp"

#include "langcc.hpp"

using namespace langcc;

i32 main(i32 argc, char** argv) {
    global_init();
    set_log_level(3);

    AR_eq(argc, 2);
    string lang_name = argv[1];

    test_lang(lang_name);
    return 0;
}
