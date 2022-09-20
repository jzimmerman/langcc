#pragma once

#include "langcc_util.hpp"

#include "meta__gen.hpp"
#include "common__data_gen.hpp"

using namespace common;

LangCompileResult_T compile_lang(
    lang::meta::Node_T src, Int k, Gensym_T gen_meta, string src_base_name, string dst_path);

LangCompileResult_T compile_lang_path(string src_path, string dst_path, Option_T<Int> k);

LangCompileResult_T compile_lang_full(string src_path, string dst_path, bool run_tests);

bool test_lang(string test_name);
void test_lang_toplevel(string test_name);
