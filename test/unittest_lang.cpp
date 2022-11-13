#include "langcc.hpp"
#include "test_common.hpp"

std::vector<std::filesystem::path> get_grammar_tests() {
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

class GrammarsTests : public testing::TestWithParam<std::filesystem::path> {};
TEST_P(GrammarsTests, Tests) {
  const auto &langfile = GetParam();
  bool ok = langcc::test_lang(langfile, LANGCC_INCLUDE_PATH);
  EXPECT_TRUE(ok);
}
INSTANTIATE_TEST_SUITE_P(GrammarsTests, GrammarsTests,
                         testing::ValuesIn(get_grammar_tests()));
