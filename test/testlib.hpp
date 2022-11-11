#pragma once

#include <condition_variable>
#include <mutex>
#include <optional>
#include <queue>
#include <utility>

#include "langcc_util.hpp"

#ifdef WIN32
#define OPTIONAL
#include <errno.h>
#include <process.h> /* for _cwait, WAIT_CHILD */
#include <stdio.h>
#include <stdlib.h>
#include <winnt.h>
#include <winternl.h>
#undef OPTIONAL

#define STDIN_FILENO _fileno(stdin)
#define STDOUT_FILENO _fileno(stdout)
#define STDERR_FILENO _fileno(stderr)

/* Generate a temporary file name based on TMPL.  TMPL must match the
   rules for mk[s]temp (i.e. end in "XXXXXX").  The name constructed
   does not exist at the time of the call to mkstemp.  TMPL is
   overwritten with the result.  */
inline int mkstemps(char *tmpl, int suffix_len) {
  static const char letters[] =
      "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";

  size_t len;
  char *XXXXXX;
  static unsigned long long value;
  unsigned long long random_time_bits;
  unsigned int count;
  int fd = -1;
  int save_errno = errno;

  /* A lower bound on the number of temporary files to attempt to
     generate.  The maximum total number of temporary file names that
     can exist for a given template is 62**6.  It should never be
     necessary to try all these combinations.  Instead if a reasonable
     number of names is tried (we define reasonable as 62**3) fail to
     give the system administrator the chance to remove the problems.  */
#define ATTEMPTS_MIN (62 * 62 * 62)

  /* The number of times to attempt to generate a temporary file.  To
     conform to POSIX, this must be no smaller than TMP_MAX.  */
#if ATTEMPTS_MIN < TMP_MAX
  unsigned int attempts = TMP_MAX;
#else
  unsigned int attempts = ATTEMPTS_MIN;
#endif

  len = strlen(tmpl);
  if (len < 6 + suffix_len ||
      strncmp(&tmpl[len - 6 - suffix_len], "XXXXXX", 6)) {
    errno = EINVAL;
    return -1;
  }

  /* This is where the Xs start.  */
  XXXXXX = &tmpl[len - 6 - suffix_len];

  /* Get some more or less random data.  */
  {
    SYSTEMTIME stNow;
    FILETIME ftNow;

    // get system time
    GetSystemTime(&stNow);
    stNow.wMilliseconds = 500;
    if (!SystemTimeToFileTime(&stNow, &ftNow)) {
      errno = -1;
      return -1;
    }

    random_time_bits = (((unsigned long long)ftNow.dwHighDateTime << 32) |
                        (unsigned long long)ftNow.dwLowDateTime);
  }
  value += random_time_bits ^ (unsigned long long)GetCurrentThreadId();

  for (count = 0; count < attempts; value += 7777, ++count) {
    unsigned long long v = value;

    /* Fill in the random bits.  */
    XXXXXX[0] = letters[v % 62];
    v /= 62;
    XXXXXX[1] = letters[v % 62];
    v /= 62;
    XXXXXX[2] = letters[v % 62];
    v /= 62;
    XXXXXX[3] = letters[v % 62];
    v /= 62;
    XXXXXX[4] = letters[v % 62];
    v /= 62;
    XXXXXX[5] = letters[v % 62];

    fd = open(tmpl, O_RDWR | O_CREAT | O_EXCL, _S_IREAD | _S_IWRITE);
    if (fd >= 0) {
      errno = save_errno;
      return fd;
    } else if (errno != EEXIST)
      return -1;
  }

  /* We got out of the loop because we ran out of combinations to try.  */
  errno = EEXIST;
  return -1;
}
#endif

namespace langcc {

inline void kill_child_proc(pid_t pid) {
  kill(pid, SIGQUIT);
  usleep(1000);
  i32 status_unused = 0;
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

// A threadsafe-queue.
template <class T> class SafeQueue {
public:
  // Add an element to the queue.
  void enqueue(T elem) {
    std::lock_guard<std::mutex> lock(m);
    q.push(elem);
    c.notify_one();
  }

  // Get the "front"-element.
  // If the queue is empty, wait till a element is avaiable.
  T dequeue() {
    std::unique_lock<std::mutex> lock(m);
    while (q.empty()) {
      // release lock as long as the wait and reaquire it afterwards.
      c.wait(lock);
    }
    T val = q.front();
    q.pop();
    return val;
  }
  std::optional<T> dequeue_nowait() {
    std::unique_lock<std::mutex> lock(m);
    if (q.empty()) {
      return std::nullopt;
    }
    T val = q.front();
    q.pop();
    return val;
  }

private:
  std::queue<T> q{};
  mutable std::mutex m{};
  std::condition_variable c{};
};

struct UnitTest {
  string name_;
  function<int()> f_;

  UnitTest(string name, function<int()> testfunc)
      : name_(std::move(name)), f_(std::move(testfunc)) {}
};

struct UnitTestRun {
  UnitTest desc_;
  std::thread testthread_;
  Time start_time_;
  Time end_time_{};
  string stdout_filename_;
  string stderr_filename_;
  string stdout_;
  string stderr_;
  Option_T<Int> ret_;

  inline bool is_success() const {
    return ret_.is_some() && ret_.as_some() == 0;
  }

  inline string ret_desc() const {
    if (this->is_success()) {
      return "success";
    } else if (ret_.is_none()) {
      return "timeout";
    } else {
      return fmt_str("ret={}", ret_.as_some());
    }
  }

  UnitTestRun(UnitTest desc, std::thread testthread, string stdout_filename,
              string stderr_filename)
      : desc_(std::move(desc)), testthread_(std::move(testthread)),
        start_time_(now()), stdout_filename_(std::move(stdout_filename)),
        stderr_filename_(std::move(stderr_filename)) {}
};

vector<UnitTest> &get_unit_tests();
map<std::thread::id, UnitTestRun> &get_unit_tests_running();
map<string, UnitTestRun> &get_unit_tests_terminated();
SafeQueue<std::pair<std::thread::id, int>> &get_finished_tests_queue();

inline void register_unit_test(string test_name, function<int()> test_function);

#define TEST(test_name)                                                        \
  void _test_##test_name();                                                    \
  static Int _test_##test_name##_init __attribute((unused)) =                  \
      (register_unit_test(#test_name, _test_##test_name), 0);                  \
  void _test_##test_name()

inline vector<UnitTest> &get_unit_tests() {
  static vector<UnitTest> _unit_tests;
  return _unit_tests;
}

inline map<std::thread::id, UnitTestRun> &get_unit_tests_running() {
  static map<std::thread::id, UnitTestRun> _unit_tests_running;
  return _unit_tests_running;
}

inline map<string, UnitTestRun> &get_unit_tests_terminated() {
  static map<string, UnitTestRun> _unit_tests_terminated;
  return _unit_tests_terminated;
}

inline SafeQueue<std::pair<std::thread::id, int>> &get_finished_tests_queue() {
  static SafeQueue<std::pair<std::thread::id, int>> _finished_tests_queue;
  return _finished_tests_queue;
}

inline void register_unit_test(string test_name,
                               function<int()> test_function) {
  get_unit_tests().emplace_back(std::move(test_name), std::move(test_function));
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
  std::thread testthread = std::thread([=] {
    auto stdout_file =
        sys_chk_nonneg(open(stdout_filename.c_str(), O_WRONLY), "open stdout");
    auto stderr_file =
        sys_chk_nonneg(open(stderr_filename.c_str(), O_WRONLY), "open stderr");
    { sys_chk_nonneg(dup2(stdout_file, STDOUT_FILENO), "dup2 stdout"); }
    { sys_chk_nonneg(dup2(stderr_file, STDERR_FILENO), "dup2 stderr"); }
    close(stdout_file);
    close(stderr_file);
    int status = test.f_();
    get_finished_tests_queue().enqueue(
        std::make_pair(std::this_thread::get_id(), status));
  });
  auto testthread_id = testthread.get_id();
  get_unit_tests_running().insert(
      make_pair(testthread_id, UnitTestRun(test, std::move(testthread),
                                           stdout_filename, stderr_filename)));
}

inline bool run_unit_tests() {
  LG("Running {} unit test(s).\n", len(get_unit_tests()));

  set<string> test_names;
  for (auto &test : get_unit_tests()) {
    if (test_names.find(test.name_) != test_names.end()) {
      LG(" *** Duplicate test name: {}\n", test.name_);
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

    auto finished_test = get_finished_tests_queue().dequeue_nowait();
    if (finished_test.has_value()) {
      auto [finished_thread_id, status] = finished_test.value();
      auto test_elem = get_unit_tests_running().extract(finished_thread_id);
      UnitTestRun test = std::move(test_elem.mapped());
      test.ret_ = Some<Int>(static_cast<Int>(status));
      test.end_time_ = now();
      test.stdout_ = read_file(test.stdout_filename_);
      test.stderr_ = read_file(test.stderr_filename_);
      std::filesystem::remove(test.stdout_filename_);
      std::filesystem::remove(test.stderr_filename_);
      if (test.is_success()) {
        LOG(0, "\033[32m[success]\033[0m {}", test.desc_.name_);
      } else {
        LOG(0, "\033[31m[FAILURE]\033[0m [{}] {}", test.ret_desc(),
            test.desc_.name_);
      }
      get_unit_tests_terminated().insert(
          make_pair(test.desc_.name_, std::move(test)));
    }

    if (now() - monitor_start > timeout) {
      std::vector<std::thread::id> keys;
      for (const auto &map_elem : get_unit_tests_running()) {
        keys.push_back(map_elem.first);
      }
      for (const auto &key : keys) {
        auto test_elem = get_unit_tests_running().extract(key);
        UnitTestRun test = std::move(test_elem.mapped());
        LG("[TIMEOUT] {}", test.desc_.name_);
        // kill_child_proc(test.pid_);
        test.ret_ = None<Int>();
        test.end_time_ = now();
        test.stdout_ = read_file(test.stdout_filename_);
        test.stderr_ = read_file(test.stderr_filename_);
        get_unit_tests_terminated().insert(
            make_pair(test.desc_.name_, std::move(test)));
      }
      get_unit_tests_running().clear();
      break;
    }
    usleep(1000);
  }

  set<string> res_succ;
  set<string> res_fail;
  for (const auto &term_test_elem : get_unit_tests_terminated()) {
    const auto &test = term_test_elem.second;
    if (test.is_success()) {
      res_succ.insert(test.desc_.name_);
    } else {
      res_fail.insert(test.desc_.name_);
    }
  }

  if (!res_fail.empty()) {
    LOG(0, "\n ===== Summary: {} succeeded, {} failed.\n", Int(res_succ.size()),
        Int(res_fail.size()));
    for (const auto &name : res_fail) {
      const auto &test = get_unit_tests_terminated().at(name);
      LOG(1, " ===== Failure({}): {}\n", test.ret_desc(), test.desc_.name_);
      LOG(1, " ===== Begin stdout[{}]\n{}", test.desc_.name_, test.stdout_);
      LOG(1, " ===== End stdout[{}]", test.desc_.name_);
      LOG(1, " ===== Begin stderr[{}]\n{}", test.desc_.name_, test.stderr_);
      LOG(1, " ===== End stderr[{}]", test.desc_.name_);
    }
  }

  LOG(0, "\n ===== Summary: {} succeeded, {} failed.\n", Int(res_succ.size()),
      Int(res_fail.size()));

  if (!res_fail.empty()) {
    LOG(0, "Succeeded:");
    for (const auto &success : res_succ) {
      LOG(0, "  {}", success);
    }
    LOG(0, "\nFailed:");
    for (const auto &fail : res_fail) {
      LOG(0, "  {}", fail);
    }
  }

  return res_fail.empty();
}
} // namespace langcc
