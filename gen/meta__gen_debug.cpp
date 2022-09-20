#include "meta__gen.hpp"

int main() {
    global_init();
    auto L = lang::meta::init();
    {
        string sym_name = string_ws_strip(stdin_readline().as_some());
        string body = "";
        for (cc_nop(); true; cc_nop()) {
            auto si = stdin_readline();
            if (si.is_none()) {
                break;
            }
            body = body + si.as_some();
        }
        L->debug_example(sym_name, body);
        return 0;
    }
}
