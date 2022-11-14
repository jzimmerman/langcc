
#include "py__gen.hpp"
#include "test_common.hpp"

using namespace langcc;
namespace langcc {
void pr(std::ostream &os, FmtFlags flags, lang::py::Node_T x) {
  x->write(os, flags);
}
} // namespace langcc

static const std::filesystem::path CPYTHON_PATH = resolvePath("../cpython");

std::vector<std::filesystem::path> get_python_files() {
  auto mn = read_file(resolvePath("data/py_manifest_gen.txt"));
  auto mn_ls = str_split(mn.substr(0, len(mn) - 1), "\n");
  std::vector<std::filesystem::path> pyfiles{};
  std::transform(mn_ls.begin(), mn_ls.end(), std::back_inserter(pyfiles),
                 [](const auto &x) { return resolvePath(x); });
  return pyfiles;
}
static const std::vector<std::filesystem::path> PYFILES = get_python_files();

TEST(PyStandaloneTest, ParserTest) {
  for (const auto &pyfile : PYFILES) {
    auto L = lang::py::init();
    auto A = make_rc<Arena>();
    auto input = read_file_shared(pyfile, A.get());
    auto gen = make_rc<Gensym>();
    auto parse = L->parse_ext(input, None<std::string>(), gen, A.get());
    EXPECT_TRUE(parse->is_success());
  }
}

TEST(PyStandaloneTest, BidirectionalTest) {
  for (const auto &pyfile : PYFILES) {
    auto L = lang::py::init();
    auto Q = L->quote_env();
    auto input = read_file(pyfile);

    auto parse = Q->L_->parse_ext(vec_from_std_string(input),
                                  None<std::string>(), Q->gen_, nullptr);
    EXPECT_TRUE(parse->is_success());
    auto prog = parse->res_.as_some();
    auto s = fmt_str("{}", prog);

    auto parse_chk = Q->L_->parse_ext(vec_from_std_string(s),
                                      None<std::string>(), Q->gen_, nullptr);
    EXPECT_TRUE(parse_chk->is_success());
    auto prog_chk = parse_chk->res_.as_some();
    auto s_chk = fmt_str("{}", prog_chk);

    EXPECT_EQ(val_hash(prog), val_hash(prog_chk));
    EXPECT_EQ(s, s_chk);
  }
}
