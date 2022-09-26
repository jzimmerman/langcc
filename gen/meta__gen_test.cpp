#include "meta__gen.hpp"

int main() {
    global_init();
    bool ok = true;
    auto L = lang::meta::init();
    ok = ok && L->test_example(Some<string>("ParseExpr"), "~x:y", -1, true);
    ok = ok && L->test_example(Some<string>("ParseExpr"), "id newline indent id newline dedent id newline", -1, true);
    return !ok;
}
