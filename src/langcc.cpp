
#include "langcc_common.hpp"

#include "langcc_rt.hpp"

namespace langcc {

LangCompileResult_T compile_lang_inner(
    lang::meta::Node_T src, Int k, Gensym_T gen_meta, LexOutput_T lex_res,
    string src_base_name, string dst_path, HeaderMode header_mode) {

    AR_ge(k, 0);

    auto L = src->as_Lang();
    LangCompileContext ctx(L, gen_meta, lex_res, src_base_name, dst_path, k);

    LOG(1, "Performing initial validation and tabulation");

    lang_init_validate(ctx);

    lang_emit_preambles(ctx);

    LOG(1, "Compiling lexer");

    if (!ctx.parser_allow_unreach_) {
        auto unreach_err = lexer_check_all_reach(ctx);
        if (unreach_err.is_some()) {
            return unreach_err.as_some();
        }
    }

    auto lexer_mode_dfas = lexer_compile_dfas(ctx);

    lexer_gen_cpp_defs(ctx, ctx.cc_, src_base_name, lexer_mode_dfas);

    LOG(1, "Compiling parser: tabulating symbols");

    parser_tabulate_syms_top(ctx);

    LOG(1, "Compiling parser: inferring attributes");

    parser_infer_attrs_top(ctx);

    LOG(2, " === Constrs by rule:\n{}\n\n", ctx.parser_attr_constr_by_rule_);

    LOG(3, " === Top-level attr domains:\n{}\n\n", ctx.parser_attr_domains_);

    parser_flatten_grammar_rules(ctx);

    LOG(2, " === Flattened grammar:\n\n{}\n\n", ctx.Gr_flat_);

    LOG(4, " === wr_map={}\n\ndt_map={}\n\nparent_map={}\n\nrd_map={}\n\n",
        ctx.gen_wr_map_, ctx.gen_dt_map_, ctx.gen_dt_parent_mapping_, ctx.gen_rd_map_);

    if (!ctx.parser_allow_unreach_) {
        auto unreach_err = parser_check_all_reach(ctx);
        if (unreach_err.is_some()) {
            return unreach_err.as_some();
        }
    }

    auto lr_conflicts = parser_lr_analysis(ctx);

    if (lr_conflicts->length() > 0) {
        auto res = LangCompileResult::Error::LRConf::make(lr_conflicts);
        return res;
    }

    LOG(1, "Generating AST datatype definitions");

    lang_emit_datatype_defs(ctx, header_mode);

    LOG(1, "Generating AST writer definitions");

    lang_emit_writer_defs(ctx);

    LOG(1, "Generating AST parser definitions");

    lang_emit_parser_defs(ctx);

    LOG(1, "Generating global definitions");

    lang_emit_global_defs(ctx);
    lang_emit_test_defs(ctx);
    lang_emit_debug_defs(ctx);

    lang_emit_extract_final(ctx, header_mode);

    return LangCompileResult::Ok::make(
        ctx.hpp_path_, ctx.cpp_path_, ctx.cpp_test_path_, ctx.cpp_debug_path_);
}


LangCompileResult_T compile_lang(
    lang::meta::Node_T src, Int k, Gensym_T gen_meta, LexOutput_T lex_res,
    string src_base_name, string dst_path, HeaderMode header_mode) {

    try {
        return compile_lang_inner(src, k, gen_meta, lex_res, src_base_name, dst_path, header_mode);
    } catch (const LangCompileResult::Error_T& res) {
        return res;
    }
}


tuple<meta::Node::Lang_T, Gensym_T, LexOutput_T> load_lang_path(string src_path) {
    auto src_str = read_file_shared(src_path);

    auto gen_meta = make_rc<Gensym>();
    auto L_meta = lang::meta::init();
    auto parse = L_meta->parse(src_str, gen_meta);
    if (!parse->is_success()) {
        LG_ERR("{}", parse->err_.as_some());
        AX();
    }

    auto src = parse->res_.as_some()->as_Lang();

    return make_tuple(src, gen_meta, parse->lex_);
}


string lang_get_src_base_name(string src_path) {
    auto src_comps = str_split(src_path, "/");
    auto src_base_comps = str_split(src_comps.at(src_comps.size() - 1), ".");
    if (src_base_comps.size() != 2 || src_base_comps[1] != "lang") {
        LG_ERR("Incorrect format for source filename");
        AX();
    }
    auto src_base_name = src_base_comps[0];
    return src_base_name;
}


LangCompileResult_T compile_lang_path(
    string src_path, string dst_path, Option_T<Int> k, HeaderMode header_mode) {

    auto src_base_name = lang_get_src_base_name(src_path);
    auto [src, gen_meta, lex_res] = load_lang_path(src_path);

    auto kr = lang_get_k_default(src);
    if (k.is_some()) {
        kr = k.as_some();
    }

    return compile_lang(src, kr, gen_meta, lex_res, src_base_name, dst_path, header_mode);
}


LangCompileResult_T compile_lang_full(
    string src_path, string dst_path, RunTests run_tests, HeaderMode header_mode) {

    makedirs(dst_path);

    auto [src, _, __] = load_lang_path(src_path);
    auto compile_tests = lang_get_compile_test_stanza(src);
    if (compile_tests.is_some()) {
        for (auto test : *compile_tests.as_some()->items_) {
            auto test_k = string_to_int(test->k_.to_std_string()).as_some();
            auto test_res = compile_lang_path(src_path, dst_path, Some<Int>(test_k), header_mode);
            if (test_res->is_Ok()) {
                if (test->neg_) {
                    LG_ERR("Unexpected compilation success: k={}", test_k);
                    AX();
                }
            } else if (test_res->is_Error()) {
                if (!test->neg_) {
                    LG_ERR("Lang compile error:\n{}\n\n", test_res->as_Error());
                    AX();
                }
            } else {
                AX();
            }
        }
    }

    auto res = compile_lang_path(src_path, dst_path, None<Int>(), header_mode);
    if (res->is_Error()) {
        return res;
    }

    if (run_tests == RunTests::Y) {
        makedirs("build/gen_test_bin");

#ifdef __APPLE__
        string sdkroot = STRINGIFY(__MACOS_SDKROOT__);
        setenv("SDKROOT", sdkroot.c_str(), 1);
#endif

        Vec<string> cmds;
        string cc = STRINGIFY(__CC__);
        cmds.push(cc);

#ifndef __APPLE__
        cmds.push("-Wno-attributes");
#endif

#ifdef __APPLE__
        cmds.push("-D");
        cmds.push(fmt_str("__MACOS_SDKROOT__={}", sdkroot));
        cmds.push("-isystem");
        cmds.push("/usr/local/include");
#endif

        cmds.push("-o");
        auto tgt_path = fmt_str("build/gen_test_bin/{}__gen_test",
            lang_get_src_base_name(src_path));
        cmds.push(tgt_path);
        cmds.push("-g");
        cmds.push("-ggdb");
        cmds.push("-g3");
        cmds.push("-std=c++17");
        cmds.push("-fno-omit-frame-pointer");
#ifdef __APPLE__
        cmds.push("-mmacosx-version-min=12.0");
#endif
        cmds.push("-I");
        cmds.push(fmt_str("./{}", dst_path));
        cmds.push("-I");
        cmds.push("./src");
        if (header_mode == HeaderMode::N) {
            cmds.push(res->as_Ok()->cpp_path_);
        }
        cmds.push(res->as_Ok()->cpp_test_path_);
#ifndef __APPLE__
        cmds.push("-lunwind");
#endif
        cmds.push("-ldl");

        string cmd;
        for (auto cmd_i : cmds) {
            cmd += cmd_i + " ";
        }
        LOG(1, "Running: {}", cmd);
        {
            auto rc = system(cmd.c_str());
            if (rc != 0) {
                LG_ERR("Failure: {}", cmd);
                AX();
            }
        }

        LOG(1, "Running: {}", tgt_path);
        {
            auto rc = system(tgt_path.c_str());
            if (rc != 0) {
                LG_ERR("Failure: {}", tgt_path);
                AX();
            }
        }
    }

    return res;
}


bool test_lang(string test_name) {
    string src_path = fmt_str("grammars/test/{}.lang", test_name);
    string dst_path = "build/gen_test_src";
    auto [src, _, __] = load_lang_path(src_path);
    auto stat = compile_lang_full(src_path, dst_path, RunTests::Y, HeaderMode::N);
    if (stat->is_Error() && !lang_is_expected_fail(src)) {
        LG_ERR("Error:\n\n{}\n\n", stat->as_Error());
        return false;
    } else if (stat->is_Ok() && lang_is_expected_fail(src)) {
        LG_ERR("Unexpected compilation success");
        return false;
    } else if (stat->is_Error() && lang_is_expected_fail(src)) {
        LOG(1, "Error (expected error):\n\n{}\n\n", stat->as_Error());
        return true;
    }
    return true;
}


void test_lang_toplevel(string test_name) {
    bool ok = test_lang(test_name);
    if (!ok) {
        AX();
    }
}

}
