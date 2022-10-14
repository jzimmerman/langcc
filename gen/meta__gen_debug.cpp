#include "meta__gen.hpp"

int main() {
    langcc::global_init();
    auto L = lang::meta::init();
    {
        std::string sym_name = langcc::string_ws_strip(langcc::stdin_readline().as_some());
        std::string body = "";
        for (langcc::cc_nop(); true; langcc::cc_nop()) {
            auto si = langcc::stdin_readline();
            if (si.is_none()) {
                break;
            }
            body = body + si.as_some();
        }
        L->debug_example(sym_name, body);
        return 0;
    }
}
