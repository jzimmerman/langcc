
#include "common.hpp"

#include "util_test.hpp"

int main() {
    global_init();
    set_log_level(1);
    bool success = run_unit_tests();
    return success ? 0 : 1;
}
