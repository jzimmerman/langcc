#include "data__gen.hpp"

int main() {
    global_init();
    bool ok = true;
    auto L = lang::data::init();
    ok = ok && L->test_example(None<string>(), "def Foo {\n    bar: Int;\n    baz: Int;\n}\n", -1, true);
    ok = ok && L->test_example(None<string>(), "def Foo(T: Type) {\n    bar: Vec(Vec(T));\n}\n", -1, true);
    ok = ok && L->test_example(None<string>(), "def Foo(T: Type) {\n    x: Int;\n}\n\ndef Bar(T: Type) {\n    foo: Foo(Vec(T));\n}\n", -1, true);
    ok = ok && L->test_example(None<string>(), "namespace NS {\n    def Foo(T: Type) {\n        x: Int;\n    }\n}\n\ndef Bar(T: Type) {\n    foo: NS::Foo(Vec(T));\n}\n", -1, true);
    ok = ok && L->test_example(None<string>(), "namespace lang::expr {\n    def E.Id {\n        x: string;\n    }\n\n    def BinOp {\n    }\n\n    def BinOp.Add {\n    }\n\n    def BinOp.Mul {\n    }\n\n    def E.BinOp {\n        lhs: E;\n        op: BinOp;\n        rhs: E;\n    }\n}\n", -1, true);
    return !ok;
}
