#pragma once

#include "langcc_util.hpp"

#include "data__gen.hpp"

namespace langcc {

using namespace lang;

inline void pr(ostream& os, FmtFlags flags, lang::data::Node_T x) {
    x->write(os, flags);
}


struct DataGenContext {
    data::LangDesc_T L_data_;

    data::QuoteEnv_T Q_;

    Vec_T<data::Node_T> dst_;

    inline DataGenContext() {
        L_data_ = lang::data::init();
        Q_ = L_data_->quote_env();
        dst_ = make_rc<Vec<data::Node_T>>();
    }

    template<typename ...Ts>
    inline data::Node_T qq(const Ts&... args) {
        return Q_->qq(args...);
    }
};

}
