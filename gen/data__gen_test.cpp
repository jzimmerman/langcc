#include "data__gen.hpp"

int main() {
    global_init();
    bool ok = true;
    auto L = lang::data::init();
    ok = ok && L->test_example(None<string>(), "def\040Foo\040{\n\040\040\040\040bar:\040Int;\n\040\040\040\040baz:\040Int;\n}\n", -1, true);
    ok = ok && L->test_example(None<string>(), "def\040Foo(T:\040Type)\040{\n\040\040\040\040bar:\040Vec(Vec(T));\n}\n", -1, true);
    ok = ok && L->test_example(None<string>(), "def\040Foo(T:\040Type)\040{\n\040\040\040\040x:\040Int;\n}\n\ndef\040Bar(T:\040Type)\040{\n\040\040\040\040foo:\040Foo(Vec(T));\n}\n", -1, true);
    ok = ok && L->test_example(None<string>(), "namespace\040NS\040{\n\040\040\040\040def\040Foo(T:\040Type)\040{\n\040\040\040\040\040\040\040\040x:\040Int;\n\040\040\040\040}\n}\n\ndef\040Bar(T:\040Type)\040{\n\040\040\040\040foo:\040NS::Foo(Vec(T));\n}\n", -1, true);
    ok = ok && L->test_example(None<string>(), "namespace\040lang::expr\040{\n\040\040\040\040def\040E.Id\040{\n\040\040\040\040\040\040\040\040x:\040string;\n\040\040\040\040}\n\n\040\040\040\040def\040BinOp\040{\n\040\040\040\040}\n\n\040\040\040\040def\040BinOp.Add\040{\n\040\040\040\040}\n\n\040\040\040\040def\040BinOp.Mul\040{\n\040\040\040\040}\n\n\040\040\040\040def\040E.BinOp\040{\n\040\040\040\040\040\040\040\040lhs:\040E;\n\040\040\040\040\040\040\040\040op:\040BinOp;\n\040\040\040\040\040\040\040\040rhs:\040E;\n\040\040\040\040}\n}\n", -1, true);
    return !ok;
}
