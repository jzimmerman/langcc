
#pragma once

#include "data__gen.hpp"

#include "cc.hpp"

using namespace lang;
using namespace lang_rt;


enum struct LowerTy {
    DIRECT,
    STRUCT,
    STRUCT_RC_ALIAS,
    CTOR_BASE,
    CTOR_FULL,
    MAKE_FULL,
    MAKE_EXT_FULL,
    WHICH_ENUM,
    WITH_BASE,
    WITH_FULL,
    SUM_IS_BASE,
    SUM_IS_FULL,
    SUM_AS_BASE,
    SUM_AS_FULL,
    HASH_SER_ACC_INST_BASE,
    HASH_SER_ACC_INST_FULL,
    HASH_SER_ACC_BASE,
    HASH_SER_ACC_FULL,
    VISIT_INST_FULL,
    WRITE_BASE,
};


GenName lower_name(LowerTy lt, const GenName& name, Option_T<GenName> name_aux = None<GenName>());


struct DataDefsResult {
    Option_T<lang::cc::Node_T> hpp_decls;
    Option_T<lang::cc::Node_T> cpp_decls;
};


DataDefsResult compile_data_defs(lang::data::Node_T src, Option_T<string> header_name,
    bool gen_write_proto);
