#pragma once

#include "langcc_util.hpp"

#include "common__data_gen.hpp"
#include "meta__gen.hpp"

#include "cc.hpp"

namespace langcc {

LangCompileResult_T compile_lang(lang::meta::Node_T src, Int k,
                                 Gensym_T gen_meta, std::string src_base_name,
                                 std::string dst_path, HeaderMode header_mode);

LangCompileResult_T compile_lang_path(std::string src_path,
                                      std::string dst_path, Option_T<Int> k,
                                      HeaderMode header_mode);

LangCompileResult_T compile_lang_full(std::string src_path,
                                      std::string dst_path, RunTests run_tests,
                                      HeaderMode header_mode);

bool test_lang(std::string test_name);
void test_lang_toplevel(std::string test_name);

} // namespace langcc
