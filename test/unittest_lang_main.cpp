
#include "langcc.hpp"
#include "testlib.hpp"

using namespace langcc;

int main(i32 argc, char **argv) {
  global_init();
  set_log_level(1);

  if (argc > 1) {
    AT(argc == 2);
    string test_name = argv[1];
    bool ok = test_lang(test_name);
    return ok ? 0 : 1;
  }

  vector<string> ss;
  try {
    for (const auto &entry :
         std::filesystem::directory_iterator("grammars/test")) {
      if (!entry.is_regular_file()) {
        continue;
      }
      string path = entry.path().string();
      auto v = str_split(path, "/");
      auto path_last = v.operator[](v.size() - 1);
      auto w = str_split(path_last, ".lang");
      AR_eq(static_cast<Int>(w.size()), 2);
      string s = w[0];
      ss.push_back(s);
    }
  } catch (std::exception &exn) {
    LG_ERR("Exception: {}", exn.what());
    AX();
  }

  for (const auto &s : ss) {
    register_unit_test(s, [s]() {
      bool ok = test_lang(s);
      return ok ? 0 : 1;
    });
  }

  bool success = run_unit_tests();
  return success ? 0 : 1;
}
