#include "meta__gen.hpp"

int main() {
    global_init();
    bool ok = true;
    auto L = lang::meta::init();
    ok = ok && L->test_example(Some<string>("ParseExpr"), "~x:y", -1, true);
    ok = ok && L->test_example(Some<string>("ParseExpr"), "id\040newline\040indent\040id\040newline\040dedent\040id\040newline", -1, true);
    return !ok;
}
