#pragma once

#include <condition_variable>
#include <mutex>
#include <optional>
#include <queue>
#include <utility>

#include "langcc_util.hpp"

////////////////////////////////////////////////////////////////////////////////
// Unit testing
////////////////////////////////////////////////////////////////////////////////

namespace langcc {
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
  std::string name_;
  std::function<int()> f_;

  UnitTest(std::string name, std::function<int()> testfunc)
      : name_(std::move(name)), f_(std::move(testfunc)) {}
};

struct UnitTestRun {
  UnitTest desc_;
  std::thread testthread_;
  Time start_time_;
  Time end_time_{};
  std::shared_ptr<std::stringstream> stdout_stream_;
  std::shared_ptr<std::stringstream> stderr_stream_;
  Option_T<Int> ret_{};

  inline bool is_success() const {
    return ret_.is_some() && ret_.as_some() == 0;
  }

  inline std::string ret_desc() const {
    if (this->is_success()) {
      return "success";
    } else if (ret_.is_none()) {
      return "timeout";
    } else {
      return fmt_str("ret={}", ret_.as_some());
    }
  }

  UnitTestRun(UnitTest desc, std::thread testthread,
              std::shared_ptr<std::stringstream> stdout_stream,
              std::shared_ptr<std::stringstream> stderr_stream)
      : desc_(std::move(desc)), testthread_(std::move(testthread)),
        start_time_(now()), stdout_stream_(std::move(stdout_stream)),
        stderr_stream_(std::move(stderr_stream)) {}
};

std::vector<UnitTest> &get_unit_tests();
std::map<std::thread::id, UnitTestRun> &get_unit_tests_running();
std::map<std::string, UnitTestRun> &get_unit_tests_terminated();
SafeQueue<std::pair<std::thread::id, int>> &get_finished_tests_queue();

inline void register_unit_test(std::string test_name,
                               std::function<int()> test_function);

#define TEST(test_name)                                                        \
  void _test_##test_name();                                                    \
  static Int _test_##test_name##_init __attribute((unused)) =                  \
      (register_unit_test(#test_name, _test_##test_name), 0);                  \
  void _test_##test_name()

inline std::vector<UnitTest> &get_unit_tests() {
  static std::vector<UnitTest> _unit_tests;
  return _unit_tests;
}

inline std::map<std::thread::id, UnitTestRun> &get_unit_tests_running() {
  static std::map<std::thread::id, UnitTestRun> _unit_tests_running;
  return _unit_tests_running;
}

inline std::map<std::string, UnitTestRun> &get_unit_tests_terminated() {
  static std::map<std::string, UnitTestRun> _unit_tests_terminated;
  return _unit_tests_terminated;
}

inline SafeQueue<std::pair<std::thread::id, int>> &get_finished_tests_queue() {
  static SafeQueue<std::pair<std::thread::id, int>> _finished_tests_queue;
  return _finished_tests_queue;
}

inline void register_unit_test(std::string test_name,
                               std::function<int()> test_function) {
  get_unit_tests().emplace_back(std::move(test_name), std::move(test_function));
}

inline void dispatch_unit_test(UnitTest &test) {
  std::shared_ptr<std::stringstream> new_stdout =
      std::make_shared<std::stringstream>();
  std::shared_ptr<std::stringstream> new_stderr =
      std::make_shared<std::stringstream>();
  std::thread testthread = std::thread([=] {
    set_stdout(new_stdout.get());
    set_stderr(new_stderr.get());
    int status = test.f_();
    get_finished_tests_queue().enqueue(
        std::make_pair(std::this_thread::get_id(), status));
  });
  auto testthread_id = testthread.get_id();
  get_unit_tests_running().insert(
      make_pair(testthread_id, UnitTestRun(test, std::move(testthread),
                                           new_stdout, new_stderr)));
}

inline bool run_unit_tests() {
  LG("Running {} unit test(s).\n", len(get_unit_tests()));

  std::set<std::string> test_names;
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

  while (test_dispatch_i < ts.size() || !get_unit_tests_running().empty()) {
    if (test_dispatch_i < ts.size()) {
      while (test_dispatch_i < ts.size() &&
             get_unit_tests_running().size() < unit_tests_max_concurrent) {
        dispatch_unit_test(ts[test_dispatch_i]);
        ++test_dispatch_i;
        std::this_thread::sleep_for(std::chrono::microseconds(1000));
      }
    }

    auto finished_test = get_finished_tests_queue().dequeue_nowait();
    if (finished_test.has_value()) {
      auto [finished_thread_id, status] = finished_test.value();
      auto test_elem = get_unit_tests_running().extract(finished_thread_id);
      UnitTestRun test = std::move(test_elem.mapped());
      test.testthread_.join();
      test.ret_ = Some<Int>(static_cast<Int>(status));
      test.end_time_ = now();
      double test_duration = (test.end_time_ - test.start_time_) / 1000000000.0;
      if (test.is_success()) {
        LOG(0, "\033[32m[success]\033[0m [{}s] {}", test_duration,
            test.desc_.name_);
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
        get_unit_tests_terminated().insert(
            make_pair(test.desc_.name_, std::move(test)));
      }
      get_unit_tests_running().clear();
      break;
    }
    std::this_thread::sleep_for(std::chrono::microseconds(1000));
  }

  std::set<std::string> res_succ;
  std::set<std::string> res_fail;
  for (const auto &term_test_elem : get_unit_tests_terminated()) {
    const auto &test = term_test_elem.second;
    if (test.is_success()) {
      res_succ.insert(test.desc_.name_);
    } else {
      res_fail.insert(test.desc_.name_);
    }
  }

  if (!res_fail.empty()) {
    LOG(0, "\n ===== Summary: {} succeeded, {} failed.\n",
        static_cast<Int>(res_succ.size()), static_cast<Int>(res_fail.size()));
    for (const auto &name : res_fail) {
      const auto &test = get_unit_tests_terminated().at(name);
      LOG(1, " ===== Failure({}): {}\n", test.ret_desc(), test.desc_.name_);
      LOG(1, " ===== Begin stdout[{}]\n{}", test.desc_.name_,
          test.stdout_stream_->str());
      LOG(1, " ===== End stdout[{}]", test.desc_.name_);
      LOG(1, " ===== Begin stderr[{}]\n{}", test.desc_.name_,
          test.stderr_stream_->str());
      LOG(1, " ===== End stderr[{}]", test.desc_.name_);
    }
  }

  LOG(0, "\n ===== Summary: {} succeeded, {} failed.\n",
      static_cast<Int>(res_succ.size()), static_cast<Int>(res_fail.size()));

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
