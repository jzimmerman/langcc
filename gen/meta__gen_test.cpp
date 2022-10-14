#include "meta__gen.hpp"

int main() {
    langcc::global_init();
    bool ok = true;
    auto L = lang::meta::init();
    ok = ok && L->test_example(langcc::Some<std::string>("ParseExpr"), "~x:y", -1, true);
    ok = ok && L->test_example(langcc::Some<std::string>("ParseExpr"), "id newline indent id newline dedent id newline", -1, true);
    return !ok;
}
