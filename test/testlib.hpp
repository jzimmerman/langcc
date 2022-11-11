#include <utility>

#include "langcc_util.hpp"
namespace langcc {

inline void kill_child_proc(pid_t pid) {
  kill(pid, SIGQUIT);
  usleep(1000);
  i32 status_unused;
  pid_t pid_res = waitpid(pid, &status_unused, WNOHANG);
  if (pid_res <= 0) {
    kill(pid, SIGKILL);
    usleep(1000);
    waitpid(pid, &status_unused, WNOHANG);
  }
}

////////////////////////////////////////////////////////////////////////////////
// Unit testing
////////////////////////////////////////////////////////////////////////////////

struct UnitTest {
  string name_;
  function<void()> f_;

  UnitTest(string name, function<void()> f)
      : name_(std::move(name)), f_(std::move(f)) {}
};

struct UnitTestRun {
  UnitTest desc_;
  pid_t pid_;
  Time start_time_;
  Time end_time_;
  string stdout_filename_;
  string stderr_filename_;
  string stdout_;
  string stderr_;
  Option_T<Int> ret_;

  inline bool is_success() { return ret_.is_some() && ret_.as_some() == 0; }

  inline string ret_desc() {
    if (this->is_success()) {
      return "success";
    } else if (ret_.is_none()) {
      return "timeout";
    } else {
      return fmt_str("ret={}", ret_.as_some());
    }
  }

  UnitTestRun(UnitTest desc, pid_t pid, string stdout_filename,
              string stderr_filename)
      : desc_(desc), pid_(pid), start_time_(now()),
        stdout_filename_(stdout_filename), stderr_filename_(stderr_filename) {}
};

vector<UnitTest> &get_unit_tests();
map<pid_t, UnitTestRun> &get_unit_tests_running();
map<string, UnitTestRun> &get_unit_tests_terminated();

inline void register_unit_test(string test_name,
                               function<void()> test_function);

#define TEST(test_name)                                                        \
  void _test_##test_name();                                                    \
  static Int _test_##test_name##_init __attribute((unused)) =                  \
      (register_unit_test(#test_name, _test_##test_name), 0);                  \
  void _test_##test_name()

inline vector<UnitTest> &get_unit_tests() {
  static vector<UnitTest> _unit_tests;
  return _unit_tests;
}

inline map<pid_t, UnitTestRun> &get_unit_tests_running() {
  static map<pid_t, UnitTestRun> _unit_tests_running;
  return _unit_tests_running;
}

inline map<string, UnitTestRun> &get_unit_tests_terminated() {
  static map<string, UnitTestRun> _unit_tests_terminated;
  return _unit_tests_terminated;
}

inline void register_unit_test(string test_name,
                               function<void()> test_function) {
  get_unit_tests().push_back(UnitTest(test_name, test_function));
}

inline void dispatch_unit_test(UnitTest &test) {
  string stdout_filename =
      (std::filesystem::temp_directory_path() / "stdout_XXXXXX.txt").string();
  string stderr_filename =
      (std::filesystem::temp_directory_path() / "stderr_XXXXXX.txt").string();
  {
    auto stdout_file =
        sys_chk_nonneg(mkstemps(stdout_filename.data(), 4), "mkstemps stdout");
    auto stderr_file =
        sys_chk_nonneg(mkstemps(stderr_filename.data(), 4), "mkstemps stderr");
    close(stdout_file);
    close(stderr_file);
  }

  pid_t pid = fork();

  AT(pid >= 0);
  if (pid == 0) {
    auto stdout_file =
        sys_chk_nonneg(open(stdout_filename.c_str(), O_WRONLY), "open stdout");
    auto stderr_file =
        sys_chk_nonneg(open(stderr_filename.c_str(), O_WRONLY), "open stderr");
    { sys_chk_nonneg(dup2(stdout_file, STDOUT_FILENO), "dup2 stdout"); }
    { sys_chk_nonneg(dup2(stderr_file, STDERR_FILENO), "dup2 stderr"); }
    close(stdout_file);
    close(stderr_file);
    test.f_();
    exit(0);
  } else {
    get_unit_tests_running().insert(make_pair(
        pid, UnitTestRun(test, pid, stdout_filename, stderr_filename)));
  }
}

inline bool run_unit_tests() {
  fmt(cerr, "Running {} unit test(s).\n", len(get_unit_tests()));

  set<string> test_names;
  for (auto &test : get_unit_tests()) {
    if (test_names.find(test.name_) != test_names.end()) {
      fmt(cerr, " *** Duplicate test name: {}\n", test.name_);
      AX();
    }
    test_names.insert(test.name_);
  }

  u64 unit_tests_max_concurrent = std::thread::hardware_concurrency();

  auto ts = get_unit_tests();
  u64 test_dispatch_i = 0;

  LG_ERR(">>> Launching {} tests ({} concurrently)", len(get_unit_tests()),
         unit_tests_max_concurrent);

  Time monitor_start = now();
  Time timeout = 1800L * G_;

  while (test_dispatch_i < ts.size() || get_unit_tests_running().size() > 0) {
    if (test_dispatch_i < ts.size()) {
      while (test_dispatch_i < ts.size() &&
             get_unit_tests_running().size() < unit_tests_max_concurrent) {
        dispatch_unit_test(ts[test_dispatch_i]);
        ++test_dispatch_i;
        usleep(1000);
      }
    }

    i32 status = -1;
    pid_t pid = waitpid(-1, &status, WNOHANG);
    if (pid == 0) {
      usleep(1);
      continue;
    }
    AT(pid != -1);
    UnitTestRun test = get_unit_tests_running().at(pid);
    test.ret_ = Some<Int>(static_cast<Int>(status));
    AT(test.ret_.is_some());
    test.end_time_ = now();
    test.stdout_ = read_file(test.stdout_filename_);
    test.stderr_ = read_file(test.stderr_filename_);
    std::filesystem::remove(test.stdout_filename_);
    std::filesystem::remove(test.stderr_filename_);
    AT(test.ret_.is_some());
    get_unit_tests_terminated().insert(make_pair(test.desc_.name_, test));
    AT(test.ret_.is_some());
    auto &m = get_unit_tests_running();
    auto it = m.find(test.pid_);
    AT(it != m.end());
    m.erase(it);
    AT(test.ret_.is_some());
    if (test.is_success()) {
      LOG(0, "\033[32m[success]\033[0m {}", test.desc_.name_);
    } else {
      LOG(0, "\033[31m[FAILURE]\033[0m [{}] {}", test.ret_desc(),
          test.desc_.name_);
    }

    if (now() - monitor_start > timeout) {
      for (auto &p : get_unit_tests_running()) {
        auto test = p.second;
        fmt(cerr, "[TIMEOUT] {}", test.desc_.name_);
        kill_child_proc(test.pid_);
        test.ret_ = None<Int>();
        test.end_time_ = now();
        test.stdout_ = read_file(test.stdout_filename_);
        test.stderr_ = read_file(test.stderr_filename_);
        get_unit_tests_terminated().insert(make_pair(test.desc_.name_, test));
      }
      get_unit_tests_running().clear();
      break;
    }
  }

  set<string> res_succ;
  set<string> res_fail;
  for (auto p : get_unit_tests_terminated()) {
    auto test = p.second;
    if (test.is_success()) {
      res_succ.insert(test.desc_.name_);
    } else {
      res_fail.insert(test.desc_.name_);
    }
  }

  if (res_fail.size() > 0) {
    LOG(0, "\n ===== Summary: {} succeeded, {} failed.\n", Int(res_succ.size()),
        Int(res_fail.size()));
    for (auto name : res_fail) {
      auto test = get_unit_tests_terminated().at(name);
      LOG(1, " ===== Failure({}): {}\n", test.ret_desc(), test.desc_.name_);
      LOG(1, " ===== Begin stdout[{}]\n{}", test.desc_.name_, test.stdout_);
      LOG(1, " ===== End stdout[{}]", test.desc_.name_);
      LOG(1, " ===== Begin stderr[{}]\n{}", test.desc_.name_, test.stderr_);
      LOG(1, " ===== End stderr[{}]", test.desc_.name_);
    }
  }

  LOG(0, "\n ===== Summary: {} succeeded, {} failed.\n", Int(res_succ.size()),
      Int(res_fail.size()));

  if (res_fail.size() > 0) {
    LOG(0, "Succeeded:");
    for (auto x : res_succ) {
      LOG(0, "  {}", x);
    }
    LOG(0, "\nFailed:");
    for (auto x : res_fail) {
      LOG(0, "  {}", x);
    }
  }

  return res_fail.size() == 0;
}
} // namespace langcc
