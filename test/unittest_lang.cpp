
#include "langcc.hpp"
#include "test_common.hpp"

std::vector<std::filesystem::path> get_grammer_tests() {
  std::vector<std::filesystem::path> langfiles;
  for (const auto &entry :
       std::filesystem::directory_iterator(resolvePath("grammars/test"))) {
    if (!entry.is_regular_file()) {
      continue;
    }
    langfiles.push_back(entry);
  }
  return langfiles;
}

class GrammaersTests : public testing::TestWithParam<std::filesystem::path> {};
TEST_P(GrammaersTests, Tests) {
  const auto &langfile = GetParam();
  bool ok = langcc::test_lang(langfile, LANGCC_INCLUDE_PATH);
  EXPECT_TRUE(ok);
}
INSTANTIATE_TEST_SUITE_P(GrammaersTests, GrammaersTests,
                         testing::ValuesIn(get_grammer_tests()));
