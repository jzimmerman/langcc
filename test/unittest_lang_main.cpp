
#include "langcc.hpp"
#include "testlib.hpp"

using namespace langcc;

int main(i32 argc, char **argv) {
  global_init();
  set_log_level(1);

  if (argc > 1) {
    AT(argc == 2);
    std::string test_name = argv[1];
    bool ok = test_lang(test_name);
    return ok ? 0 : 1;
  }

  std::vector<std::string> ss;
  try {
    for (const auto &entry :
         std::filesystem::directory_iterator("grammars/test")) {
      if (!entry.is_regular_file()) {
        continue;
      }
      auto filename = entry.path().filename().string();
      auto w = str_split(filename, ".lang");
      AR_eq(static_cast<Int>(w.size()), 2);
      std::string s = w[0];
      ss.push_back(s);
    }
  } catch (std::exception &exn) {
    LG_ERR("Exception: {}", exn.what());
    AX();
  }

  for (const auto &s : ss) {
    register_unit_test(s, [s]() {
      try {
        bool ok = test_lang(s);
        return ok ? 0 : 1;
      } catch (const std::exception &ex) {
        LG_ERR("Test raised exception: {}", ex.what());
        return 1;
      }
    });
  }

  bool success = run_unit_tests();
  return success ? 0 : 1;
}
