#pragma once

#include "langcc_util.hpp"

#include "common__data_gen.hpp"
#include "meta__gen.hpp"

#include "cc.hpp"

namespace langcc {

LangCompileResult_T compile_lang(lang::meta::Node_T src, Int k,
                                 Gensym_T gen_meta,
                                 const std::string &src_base_name,
                                 const std::string &dst_path,
                                 HeaderMode header_mode);

LangCompileResult_T compile_lang_path(const std::string &src_path,
                                      const std::string &dst_path,
                                      Option_T<Int> k, HeaderMode header_mode);

LangCompileResult_T compile_lang_full(const std::string &src_path,
                                      const std::string &dst_path,
                                      RunTests run_tests,
                                      HeaderMode header_mode);

bool test_lang(const std::string &test_name);
void test_lang_toplevel(const std::string &test_name);

} // namespace langcc
