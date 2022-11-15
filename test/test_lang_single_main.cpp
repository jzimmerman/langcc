
#include "langcc_util.hpp"

#include "langcc.hpp"

i32 main(i32 argc, char **argv) {
  langcc::global_init();
  langcc::set_log_level(3);

  AR_eq(argc, 2);
  std::string lang_name = argv[1];

  langcc::test_lang(lang_name, "");
  return 0;
}
