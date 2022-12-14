#pragma once

#include "langcc_util.hpp"

#include "meta__gen.hpp"
#include "common__data_gen.hpp"

#include "cc.hpp"

namespace langcc {

LangCompileResult_T compile_lang(
    lang::meta::Node_T src, Int k, Gensym_T gen_meta, string src_base_name, string dst_path,
    HeaderMode header_mode);

LangCompileResult_T compile_lang_path(
    string src_path, string dst_path, Option_T<Int> k, HeaderMode header_mode);

LangCompileResult_T compile_lang_full(string src_path, string dst_path, RunTests run_tests,
    HeaderMode header_mode, Vec_T<string> extra_includes);

bool test_lang(string test_name);
void test_lang_toplevel(string test_name);

}