
#include "datacc.hpp"

int main(int argc, char** argv) {
    global_init();
    set_log_level(1);

    if (argc != 3) {
        fmt(cerr, "Usage: datacc src.data dst_dir\n");
        return 1;
    }

    string src_path = argv[1];
    string dst_path = argv[2];

    auto src_comps = str_split(src_path, "/");
    auto src_base_comps = str_split(src_comps.at(src_comps.size() - 1), ".");
    if (src_base_comps.size() != 2 || src_base_comps[1] != "data") {
        fmt(cerr, "Usage: datacc src.data dst_dir\n");
        return 1;
    }
    auto src_base_name = src_base_comps[0];

    auto src_str = read_file_shared(src_path);

    auto gen_data = make_rc<Gensym>();
    auto L_data = lang::data::init();
    auto parse = L_data->parse(src_str, gen_data);
    if (!parse->is_success()) {
        fmt(cerr, "{}\n", parse->err_.as_some());
        return 1;
    }

    auto src = parse->res_.as_some();

    auto ret = compile_data_defs(
        src, Some(fmt_str("{}__data_gen.hpp", src_base_name)), false);

    auto dst_path_cpp = fmt_str("{}/{}__data_gen.cpp", dst_path, src_base_name);
    auto dst_path_hpp = fmt_str("{}/{}__data_gen.hpp", dst_path, src_base_name);

    if (ret.hpp_decls.is_some()) {
        write_file(dst_path_hpp, fmt_str("{}", ret.hpp_decls.as_some()));
    } else {
        write_file(dst_path_hpp, "");
    }

    if (ret.cpp_decls.is_some()) {
        write_file(dst_path_cpp, fmt_str("{}", ret.cpp_decls.as_some()));
    } else {
        write_file(dst_path_cpp, "");
    }

    return 0;
}
