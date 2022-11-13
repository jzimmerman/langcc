#pragma once

////////////////////////////////////////////////////////////////////////////////
// Common includes
////////////////////////////////////////////////////////////////////////////////
#include <algorithm>
#include <atomic>
#include <chrono>
#include <climits>
#include <cmath>
#include <cstring>
#include <ctime>
#include <deque>
#include <filesystem>
#include <fstream>
#include <functional>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <thread>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>

#ifdef WIN32
#define always_inlines msvc::forceinline
#define noinlines msvc::noinline
#define __builtin_expect(expr, x) (expr)
#else
#define always_inlines gnu::always_inline
#define noinlines gnu::noinline
#endif

namespace langcc {

////////////////////////////////////////////////////////////////////////////////
// Common definitions
////////////////////////////////////////////////////////////////////////////////

void init_time_system();

inline void global_init() { init_time_system(); }

using i8 = int8_t;
using u8 = uint8_t;
using i16 = int16_t;
using u16 = uint16_t;
using i32 = int32_t;
using u32 = uint32_t;
using i64 = int64_t;
using u64 = uint64_t;
using Int = i64;

using f32 = float;
using f64 = double;

using u16_array = u16[];
using u32_array = u32[];

using Ch = char32_t;

struct Unit {};

using IntPair = std::pair<Int, Int>;

template <typename T> using Ptr = T *;
template <typename T> using Ref = T &;

inline void cc_nop() {}

#define _LT_ <
#define _GT_ >

template <typename T> inline T *addr_of(T &t) { return &t; }

inline Int len(const std::string &x) { return static_cast<Int>(x.size()); }

template <typename T> inline Int len(const std::vector<T> &x) {
  return static_cast<Int>(x.size());
}

template <typename T> inline Int len(const std::deque<T> &x) {
  return static_cast<Int>(x.size());
}

constexpr Int K_ = 1000;
constexpr Int M_ = 1000000;
constexpr Int G_ = 1000000000;

////////////////////////////////////////////////////////////////////////////////
// Forward declarations
////////////////////////////////////////////////////////////////////////////////

template <typename... Ts>
inline void AT(bool cond, const std::string &s, Ts... ts);

inline void AT(bool cond);

template <typename... Ts>
[[noreturn]] inline void AX(const std::string &s, Ts... ts);

[[noreturn]] inline void AX();

template <typename T, typename U> inline void AR_eq(T t, U u);

template <typename T, typename U> inline void AR_ne(T t, U u);

template <typename T, typename U> inline void AR_ge(T t, U u);

template <typename T, typename U> inline void AR_gt(T t, U u);

template <typename T, typename U> inline void AR_lt(T t, U u);

template <typename T, typename U> inline void AR_le(T t, U u);

inline void check_range(Int i, Int n);

struct Arena;

namespace Option {
template <typename T> struct _T;
}
template <typename T> using Option_T = Option::_T<T>;

namespace Option {
enum struct _W {
  _UNINIT_,
  Some,
  None,
};
}

namespace Option {
template <typename T> struct _T {
  Option::_W w_;
  u8 t_[sizeof(T)];

  _T(const _T &);
  _T &operator=(const _T &);

  Option::_W w();
  _T();
  _T(Option::_W w, const T &t);
  ~_T();

  bool is_some() const;
  T &as_some();
  const T &as_some() const;
  bool is_none() const;
};
} // namespace Option

template <typename T> Option_T<T> Some(const T &);
template <typename T> Option_T<T> None();

using Time = Int;

Time now();

inline std::string str_repeat(const std::string &s, Int count);

template <typename... Ts>
void fmt(std::ostream &os, const std::string &s, const Ts &...ts);

template <typename... Ts>
inline std::string fmt_str(const std::string &s, const Ts &...ts);

template <typename... Ts> inline std::string fmt_strs_var(const Ts &...ts);

void *malloc_ext(Int size, Arena *A);

void *realloc_ext(void *x, Int size, Arena *A);

void free_ext(void *x, Arena *A);

////////////////////////////////////////////////////////////////////////////////
// Reference-counted pointers
////////////////////////////////////////////////////////////////////////////////

template <typename T> struct rc_ptr {
  void *v_;

  // If rc_ == 0, this is an arena-allocated pointer (not ref-counted).
  std::atomic<Int> *rc_;

  inline T &operator*() { return *reinterpret_cast<T *>(v_); }

  inline T *operator->() { return reinterpret_cast<T *>(v_); }

  inline const T &operator*() const { return *reinterpret_cast<T *>(v_); }

  inline const T *operator->() const { return reinterpret_cast<T *>(v_); }

  inline T *get() const { return reinterpret_cast<T *>(v_); }

  inline rc_ptr() : v_(nullptr), rc_(nullptr) {}

  inline void incref() const;
  inline void decref();

  static rc_ptr from_alloc(void *v);

  inline static rc_ptr from_contents(void *v, std::atomic<Int> *rc) {
    rc_ptr ret;
    ret.v_ = v;
    ret.rc_ = rc;
    ret.incref();
    return ret;
  }

  inline rc_ptr(const rc_ptr<T> &x) : v_(x.v_), rc_(x.rc_) { this->incref(); }

  inline rc_ptr(nullptr_t) : v_(nullptr), rc_(nullptr) {}

  template <typename U, typename std::enable_if<
                            std::is_base_of<T, U>::value>::type * = nullptr>
  rc_ptr(const rc_ptr<U> &x) : v_(x.v_), rc_(x.rc_) {

    this->incref();
  }

  inline rc_ptr<T> &operator=(const rc_ptr<T> &x) {
    x.incref();
    this->decref();
    v_ = x.v_;
    rc_ = x.rc_;
    return *this;
  }

  inline ~rc_ptr() { this->decref(); }
};

#define STRINGIFY(x) STRINGIFY_INNER(x)
#define STRINGIFY_INNER(x) #x

template <typename T> T take_ptr(T *x) {
  T ret = *x;
  delete x;
  return ret;
}

template <typename T> T drop_ptr(T *x) { delete x; }

template <
    typename U, typename T,
    typename std::enable_if<std::is_base_of<T, U>::value>::type * = nullptr>
rc_ptr<U> downcast_unchecked(const rc_ptr<T> &x) {
  return rc_ptr<U>::from_contents(x.v_, x.rc_);
}

struct _enable_rc_from_this {};

struct enable_rc_from_this_poly : _enable_rc_from_this {
  void *_rc_contents_v_;
  std::atomic<Int> *_rc_contents_rc_;

  template <typename U> rc_ptr<U> rc_from_this_poly() {
    return rc_ptr<U>::from_contents(_rc_contents_v_, _rc_contents_rc_);
  }

  template <typename U> const rc_ptr<U> rc_from_this_poly() const {
    return rc_ptr<U>::from_contents(_rc_contents_v_, _rc_contents_rc_);
  }
};

template <typename T> struct enable_rc_from_this : _enable_rc_from_this {
  void *_rc_contents_v_;
  std::atomic<Int> *_rc_contents_rc_;

  rc_ptr<T> rc_from_this() {
    return rc_ptr<T>::from_contents(_rc_contents_v_, _rc_contents_rc_);
  }
};

template <typename T> rc_ptr<T> rc_from_ptr_std(T *x) {
  auto *xw = reinterpret_cast<Int *>(x);
  return rc_ptr<T>::from_contents(xw,
                                  reinterpret_cast<std::atomic<Int> *>(xw - 1));
}

template <typename T> rc_ptr<T> rc_from_ptr_std_dec(void *x) {
  auto *xw = reinterpret_cast<Int *>(x);
  auto ret = rc_ptr<T>::from_contents(
      xw, reinterpret_cast<std::atomic<Int> *>(xw - 1));
  ret.decref();
  return ret;
}

template <typename T> T rc_from_ptr_std_take(T *x) {
  auto ret_rc = rc_from_ptr_std(x);
  auto ret = *x;
  ret_rc.decref();
  return ret;
}

template <typename T, typename std::enable_if<std::is_base_of<
                          _enable_rc_from_this, T>::value>::type * = nullptr>
void init_rc_contents(T *x, void *v, std::atomic<Int> *rc) {
  x->_rc_contents_v_ = v;
  x->_rc_contents_rc_ = rc;
}

template <typename T, typename std::enable_if<!std::is_base_of<
                          _enable_rc_from_this, T>::value>::type * = nullptr>
void init_rc_contents(T * /*x*/, void * /*v*/, std::atomic<Int> * /*rc*/) {}

template <typename T, typename... Ts> rc_ptr<T> make_rc(Ts... args) {
  static_assert(sizeof(Int) == 8);
  static_assert(sizeof(std::atomic<Int>) == 8);
  auto *mem =
      reinterpret_cast<Int *>(malloc(sizeof(std::atomic<Int>) + sizeof(T)));
  rc_ptr<T> ret;
  ret.rc_ = reinterpret_cast<std::atomic<Int> *>(mem);
  new (ret.rc_) std::atomic<Int>(1);
  ret.v_ = mem + 1;
  new (ret.v_) T(args...);
  init_rc_contents(reinterpret_cast<T *>(ret.v_), ret.v_, ret.rc_);
  return ret;
}

template <typename T, typename... Ts> T *make_rc_inc(Ts... args) {
  auto ret = make_rc<T>(args...);
  ret.incref();
  auto ret_ptr = ret.get();
  return ret_ptr;
}

template <typename T> [[always_inlines]] inline void rc_ptr<T>::incref() const {
  if (__builtin_expect(!!rc_, 0)) {
    if (__builtin_expect(!!v_, 1)) {
      rc_->fetch_add(1);
    }
  }
}

template <typename T> [[always_inlines]] inline void rc_ptr<T>::decref() {
  if (__builtin_expect(!!rc_, 0)) {
    if (__builtin_expect(!!v_, 1)) {
      Int rc_new = rc_->fetch_sub(1) - 1;

      if (__builtin_expect(rc_new == 0, 0)) {
        rc_->~atomic<Int>();
        reinterpret_cast<T *>(v_)->~T();
        free(rc_); // NOTE: also frees block with v_
        v_ = nullptr;
      }
    }
  }
}

////////////////////////////////////////////////////////////////////////////////
// std::string utilities
////////////////////////////////////////////////////////////////////////////////

template <typename... Ts>
inline std::string cc_sprintf(const char *fmt_str, Ts... ts);

inline bool str_starts_with(const std::string &x, const std::string &prefix) {
  if (len(x) < len(prefix)) {
    return false;
  }
  return x.substr(0, len(prefix)) == prefix;
}

inline std::string str_with_replace_all(const std::string &x,
                                        const std::string &a,
                                        const std::string &b) {

  std::string ret;

  size_t pos_curr = 0;

  while (true) {
    size_t pos_next = x.find(a, pos_curr);
    if (pos_next == std::string::npos) {
      ret += x.substr(pos_curr, x.length() - pos_curr);
      return ret;
    }
    ret += x.substr(pos_curr, pos_next - pos_curr);
    ret += b;
    pos_curr = pos_next + a.length();
  }
}

inline std::string str_reindent_inner(const std::string &x,
                                      const std::string &delim) {
  return str_with_replace_all(x, "\n", "\n" + delim);
}

inline std::string str_reindent(const std::string &x, Int count) {
  std::string ret;
  std::string sp = str_repeat(" ", count);
  if (!str_starts_with(x, "\n")) {
    ret += sp;
  }
  ret += str_reindent_inner(x, sp);
  return ret;
}

inline std::string duration_fmt_str(Int t) {
  t += 500;
  t /= 1000;
  Int micros = t % 1000000;
  t /= 1000000;
  Int sec = t % 60;
  t /= 60;
  Int min = t % 60;
  t /= 60;
  Int hours = t;
  std::string ret;
  ret += cc_sprintf("%03d", hours);
  ret += ":";
  ret += cc_sprintf("%02d", min);
  ret += ":";
  ret += cc_sprintf("%02d", sec);
  ret += ".";
  ret += cc_sprintf("%06d", micros);
  return ret;
}

inline std::string utf8_encode(Ch ch) {
  std::string ret;
  if (ch < 0x80) {
    ret += static_cast<char>(ch);
    return ret;
  } else if (ch < 0x800) {
    char f1 = ch & 0x3f;
    char ch1 = f1 | 0x80;
    ch >>= 6;
    char f0 = ch & 0x1f;
    char ch0 = f0 | 0xc0;
    ch >>= 5;
    AT(ch == 0);
    ret += ch0;
    ret += ch1;
    return ret;
  } else if (ch < 0x10000) {
    char f2 = ch & 0x3f;
    char ch2 = f2 | 0x80;
    ch >>= 6;
    char f1 = ch & 0x3f;
    char ch1 = f1 | 0x80;
    ch >>= 6;
    char f0 = ch & 0x0f;
    char ch0 = f0 | 0xe0;
    ch >>= 4;
    AT(ch == 0);
    ret += ch0;
    ret += ch1;
    ret += ch2;
    return ret;
  } else if (ch < 0x110000) {
    char f3 = ch & 0x3f;
    char ch3 = f3 | 0x80;
    ch >>= 6;
    char f2 = ch & 0x3f;
    char ch2 = f2 | 0x80;
    ch >>= 6;
    char f1 = ch & 0x3f;
    char ch1 = f1 | 0x80;
    ch >>= 6;
    char f0 = ch & 0x07;
    char ch0 = f0 | 0xf0;
    ch >>= 3;
    AT(ch == 0);
    ret += ch0;
    ret += ch1;
    ret += ch2;
    ret += ch3;
    return ret;
  } else {
    AX();
  }
}

inline std::string utf8_encode(const std::vector<Ch> &chs) {
  std::string ret;
  for (auto ch : chs) {
    ret += utf8_encode(ch);
  }
  return ret;
}

inline Option_T<std::vector<Ch>> utf8_decode(std::string s) {
  std::vector<Ch> ret;
  u64 i = 0;
  while (i < s.length()) {
    auto c = static_cast<u8>(s[i]);
    if (c < 0x80) {
      ret.push_back(c);
      ++i;
    } else if ((c & 0xe0) == 0xc0) {
      if (i + 1 >= s.length() || (s[i + 1] & 0xc0) != 0x80) {
        return None<std::vector<Ch>>();
      }
      Ch ch = c & 0x1f;
      ch <<= 6;
      ch |= s[i + 1] & 0x3f;
      ret.push_back(ch);
      i += 2;
    } else if ((c & 0xf0) == 0xe0) {
      if (i + 2 >= s.length() || (s[i + 1] & 0xc0) != 0x80 ||
          (s[i + 2] & 0xc0) != 0x80) {
        return None<std::vector<Ch>>();
      }
      Ch ch = c & 0x0f;
      ch <<= 6;
      ch |= s[i + 1] & 0x3f;
      ch <<= 6;
      ch |= s[i + 2] & 0x3f;
      ret.push_back(ch);
      i += 3;
    } else if ((c & 0xf8) == 0xf0) {
      if (i + 3 >= s.length() || (s[i + 1] & 0xc0) != 0x80 ||
          (s[i + 2] & 0xc0) != 0x80 || (s[i + 3] & 0xc0) != 0x80) {
        return None<std::vector<Ch>>();
      }
      Ch ch = c & 0x07;
      ch <<= 6;
      ch |= s[i + 1] & 0x3f;
      ch <<= 6;
      ch |= s[i + 2] & 0x3f;
      ch <<= 6;
      ch |= s[i + 3] & 0x3f;
      ret.push_back(ch);
      i += 4;
    } else {
      return None<std::vector<Ch>>();
    }
  }
  return Some<std::vector<Ch>>(ret);
}

inline std::string hex_nybble_display(u8 c) {
  std::string ret;
  if (c < 10) {
    ret += (static_cast<char>(c) + '0');
  } else if (c < 16) {
    ret += (static_cast<char>(c) + 'a' - 10);
  } else {
    AX();
  }
  return ret;
}

inline std::string hex_byte_display(u8 c) {
  return hex_nybble_display(c >> 4) + hex_nybble_display(c & 0xf);
}

inline std::string oct_byte_display(u8 c) {
  return hex_nybble_display((c >> 6) & 0x7) +
         hex_nybble_display((c >> 3) & 0x7) +
         hex_nybble_display((c >> 6) & 0x7);
}

inline std::string hex_u16_display(u32 c) {
  std::string ret;
  for (Int i = 0; i < 4; i++) {
    ret += hex_nybble_display((c >> ((3 - i) * 4)) & 0xf);
  }
  return ret;
}

inline std::string hex_u32_display(u32 c) {
  std::string ret;
  for (Int i = 0; i < 8; i++) {
    ret += hex_nybble_display((c >> ((7 - i) * 4)) & 0xf);
  }
  return ret;
}

inline std::string hex_u64_display(u64 x) {
  std::string ret;
  for (Int i = 0; i < 16; i++) {
    ret += hex_nybble_display((x >> ((15 - i) * 4)) & 0xf);
  }
  return ret;
}

inline u8 hex_nybble_to_u8(char x) {
  if (x >= '0' && x <= '9') {
    return static_cast<u8>(x - '0');
  } else if (x >= 'a' && x <= 'f') {
    return static_cast<u8>(10) + static_cast<u8>(x - 'a');
  } else {
    AX();
  }
}

inline u8 hex_byte_to_u8(std::string x) {
  AT(x.length() == 2);
  return (hex_nybble_to_u8(x[0]) << 4) | hex_nybble_to_u8(x[1]);
}

inline Option_T<Int> string_to_int(const std::string &x) {
  Int ret = atoll(x.c_str());
  if (x == fmt_str("{}", ret)) {
    return Some<Int>(ret);
  }
  return None<Int>();
}

inline Option_T<Int> string_to_int_hex(const std::string &x) {
  u64 ret = 0;
  for (const auto &c : x) {
    ret <<= 4;
    ret |= hex_nybble_to_u8(c);
  }
  return Some<Int>(static_cast<Int>(ret));
}

inline Option_T<f64> string_to_f64(std::string x) {
  f64 ret = strtod(x.data(), nullptr);
  if (ret == 0.0) {
    std::string negx = "-" + x;
    if (str_starts_with(x, "-")) {
      negx = x.substr(1);
    }
    f64 ret_alt = stod(negx, nullptr);
    if (std::signbit(ret_alt) == std::signbit(ret)) {
      return None<f64>();
    }
  }
  return Some<f64>(ret);
}

inline Option_T<f32> string_to_f32(std::string x) {
  auto ret = string_to_f64(std::move(x));
  if (ret.is_none()) {
    return None<f32>();
  } else {
    return Some<f32>(static_cast<f32>(ret.as_some()));
  }
}

inline std::string escape_string_char(Ch ch) {
  if (ch == '\n') {
    return "\\n";
  } else if (ch == '\r') {
    return "\\r";
  } else if (ch == '\t') {
    return "\\t";
  } else if (ch == '\f') {
    return "\\f";
  } else if (ch == '"') {
    return "\\\"";
  } else if (ch == '\'') {
    return "\\\'";
  } else if (ch == '\\') {
    return "\\\\";
  } else if (ch == ' ') {
    return " ";
  } else if (ch >= 0 && ch < 128 && (isalnum(ch) || ispunct(ch))) {
    return std::string("") + static_cast<char>(ch);
  } else if (ch >= 0 && ch < 128) {
    return fmt_str("\\{}", oct_byte_display(static_cast<u8>(ch)));
  } else if (ch >= 0 && ch < 65536) {
    return utf8_encode(ch);
  } else if (ch >= 0 && ch < 0x110000) {
    return utf8_encode(ch);
  } else {
    AX();
  }
}

inline std::string escape_string_chars(const std::vector<Ch> &chs) {
  std::string ret;
  for (auto ch : chs) {
    ret += escape_string_char(ch);
  }
  return ret;
}

inline std::string escape_string(std::string s) {
  auto chs = utf8_decode(std::move(s)).as_some();
  return escape_string_chars(chs);
}

inline std::string u8_char_display(u8 c) {
  if (isalnum(c) || ispunct(c) || c == ' ') {
    return fmt_str("`{}`", static_cast<char>(c));
  } else if (c == '\n') {
    return "`\\n`";
  } else if (c == '\r') {
    return "`\\r`";
  } else if (c == '\t') {
    return "`\\t`";
  } else {
    return fmt_str("`\\x{}`", hex_byte_display(c));
  }
}

inline std::string char_display(Ch c) {
  if (c < Ch(256)) {
    return u8_char_display(static_cast<u8>(c));
  } else {
    return fmt_str("`\\U{}`", hex_u32_display(c));
  }
}

enum struct Align {
  LEFT,
  RIGHT,
};

inline std::string str_align_left(const std::string &x, Int w) {
  std::string ret;
  ret += x;
  for (Int j = 0; j < w - len(x); j++) {
    ret += ' ';
  }
  return ret;
}

inline std::string str_align_right(const std::string &x, Int w) {
  std::string ret;
  for (Int j = 0; j < w - len(x); j++) {
    ret += ' ';
  }
  ret += x;
  return ret;
}

inline std::string str_align(const std::string &x, Align align, Int w,
                             bool strict) {
  switch (align) {
  case Align::LEFT: {
    if (strict) {
      return str_align_left(x, w);
    } else {
      return x;
    }
    break;
  }
  case Align::RIGHT: {
    return str_align_right(x, w);
    break;
  }
  default: {
    AX();
  }
  }
}

inline std::vector<std::string> str_split(const std::string &x,
                                          const std::string &delim) {
  std::vector<std::string> ret;
  std::string curr = x;
  while (true) {
    u64 pos = curr.find(delim);
    if (pos == std::string::npos) {
      ret.push_back(curr);
      break;
    }
    ret.push_back(curr.substr(0, pos));
    curr = curr.substr(pos + len(delim));
  }
  return ret;
}

inline std::string str_repeat(const std::string &s, Int count) {
  std::string ret;
  for (Int i = 0; i < count; i++) {
    ret += s;
  }
  return ret;
}

inline bool u8_is_ws(u8 x) { return isspace(x); }

inline std::string string_ws_strip(std::string x) {
  u64 i;
  for (i = 0; i < x.length(); i++) {
    if (!u8_is_ws(x[i])) {
      break;
    }
  }
  u64 j;
  for (j = x.length(); j >= 0; j--) {
    if (j == 0 || !u8_is_ws(x[j - 1])) {
      break;
    }
  }
  AR_ge(j, i);
  return x.substr(i, j - i);
}

template <typename... Ts>
inline std::string cc_sprintf(const char *fmt_str, Ts... ts) {

  Int n = 64;
  while (true) {
    std::vector<char> buf(n);
    auto res = snprintf(buf.data(), n, fmt_str, ts...);
    if (res == n) {
      n *= 2;
      continue;
    }
    AR_ge(res, 0);
    AR_lt(res, n);
    return std::string(buf.data(), res);
  }
}

////////////////////////////////////////////////////////////////////////////////
// Formatting utilities
////////////////////////////////////////////////////////////////////////////////

struct FmtFlags {
  Int indent_width_;
  Int indent_curr_;
  Int prec_curr_;

  inline static FmtFlags default_() {
    FmtFlags ret;
    ret.indent_width_ = 4;
    ret.indent_curr_ = 0;
    ret.prec_curr_ = 0;
    return ret;
  }

  inline FmtFlags sub_lo() {
    FmtFlags ret;
    ret.indent_width_ = indent_width_;
    ret.indent_curr_ = indent_curr_ + 1;
    ret.prec_curr_ = 0;
    return ret;
  }

  inline void indent_single(std::ostream &os) {
    AT(indent_width_ >= 0);
    os << str_repeat(" ", indent_width_);
  }

  inline void write_indent(std::ostream &os) {
    AT(indent_curr_ >= 0);
    AT(indent_width_ >= 0);
    auto k = indent_curr_ * indent_width_;
    os << str_repeat(" ", k);
  }

  inline void advance_lines(Int n, std::ostream &os) {
    if (n == 0) {
      return;
    }
    for (Int i = 0; i < n - 1; i++) {
      os << "\n";
    }
    os << "\n";
    this->write_indent(os);
  }
};

inline void pr(std::ostream &os, FmtFlags /*flags*/, const std::string &x) {
  os << x;
}

inline void pr_debug(std::ostream &os, FmtFlags /*flags*/,
                     const std::string &x) {
  os << "\"" << x << "\"";
}

inline void pr(std::ostream &os, FmtFlags /*flags*/,
               const std::filesystem::path &x) {
  os << x;
}

inline void pr_debug(std::ostream &os, FmtFlags /*flags*/,
                     const std::filesystem::path &x) {
  os << "\"" << x << "\"";
}

inline void pr(std::ostream &os, FmtFlags /*flags*/, const char *x) { os << x; }

inline void pr_debug(std::ostream &os, FmtFlags /*flags*/, const char *x) {
  os << "\"" << x << "\"";
}

template <typename T>
inline void pr(std::ostream &os, FmtFlags /*flags*/, T *x) {
  os << "0x" << hex_u64_display(reinterpret_cast<u64>(x));
}

template <typename T>
inline void pr_debug(std::ostream &os, FmtFlags /*flags*/, T *x) {
  os << "0x" << hex_u64_display(reinterpret_cast<u64>(x));
}

inline void pr(std::ostream &os, FmtFlags /*flags*/, Int x) { os << x; }

inline void pr_debug(std::ostream &os, FmtFlags flags, Int x) {
  pr(os, flags, x);
}

inline void pr(std::ostream &os, FmtFlags /*flags*/, u32 x) { os << x; }

inline void pr_debug(std::ostream &os, FmtFlags flags, u32 x) {
  pr(os, flags, x);
}

inline void pr(std::ostream &os, FmtFlags /*flags*/, u64 x) { os << x; }

inline void pr_debug(std::ostream &os, FmtFlags flags, u64 x) {
  pr(os, flags, x);
}

inline void pr(std::ostream &os, FmtFlags /*flags*/, f32 x) { os << x; }

inline void pr_debug(std::ostream &os, FmtFlags flags, f32 x) {
  pr(os, flags, x);
}

inline void pr(std::ostream &os, FmtFlags /*flags*/, f64 x) { os << x; }

inline void pr_debug(std::ostream &os, FmtFlags flags, f64 x) {
  pr(os, flags, x);
}

inline void pr(std::ostream &os, FmtFlags /*flags*/, bool x) {
  os << (x ? "true" : "false");
}

inline void pr_debug(std::ostream &os, FmtFlags /*flags*/, bool x) {
  os << (x ? "true" : "false");
}

inline void pr(std::ostream &os, FmtFlags /*flags*/, Ch x) {
  os << static_cast<uint32_t>(x);
}

inline void pr_debug(std::ostream &os, FmtFlags /*flags*/, Ch x) {
  os << "\"" << escape_string_char(x) << "\"";
}

inline void pr(std::ostream &os, FmtFlags /*flags*/, i32 x) { os << x; }

inline void pr(std::ostream &os, FmtFlags /*flags*/, char c) { os << c; }

inline void pr(std::ostream &os, FmtFlags /*flags*/, Unit /*x*/) { os << "()"; }

inline void pr_debug(std::ostream &os, FmtFlags /*flags*/, Unit /*x*/) {
  os << "()";
}

template <typename T>
inline void pr(std::ostream &os, FmtFlags flags, const std::vector<T> &x) {
  os << "{";
  for (Int i = 0; i < len(x); i++) {
    if (i > 0) {
      os << ", ";
    }
    pr(os, flags, x[i]);
  }
  os << "}";
}

template <typename K, typename V>
inline void pr(std::ostream &os, FmtFlags flags, const std::map<K, V> &x) {
  os << "{";
  bool fresh = true;
  for (auto p : x) {
    if (!fresh) {
      os << ", ";
    }
    fresh = false;
    pr(os, flags, p.first);
    os << ": ";
    pr(os, flags, p.second);
  }
  os << "}";
}

template <typename T, typename U>
inline void pr(std::ostream &os, FmtFlags flags, const std::pair<T, U> &x) {
  os << "(";
  pr(os, flags, x.first);
  os << ", ";
  pr(os, flags, x.second);
  os << ")";
}

template <typename T, typename U>
inline void pr_debug(std::ostream &os, FmtFlags flags,
                     const std::pair<T, U> &x) {
  os << "(";
  pr_debug(os, flags, x.first);
  os << ", ";
  pr_debug(os, flags, x.second);
  os << ")";
}

template <typename T, typename U, typename V>
inline void pr(std::ostream &os, FmtFlags flags, const std::tuple<T, U, V> &x) {
  os << "(";
  pr(os, flags, std::get<0>(x));
  os << ", ";
  pr(os, flags, std::get<1>(x));
  os << ", ";
  pr(os, flags, std::get<2>(x));
  os << ")";
}

template <typename T, typename U, typename V>
inline void pr_debug(std::ostream &os, FmtFlags flags,
                     const std::tuple<T, U, V> &x) {
  os << "(";
  pr_debug(os, flags, std::get<0>(x));
  os << ", ";
  pr_debug(os, flags, std::get<1>(x));
  os << ", ";
  pr_debug(os, flags, std::get<2>(x));
  os << ")";
}

template <typename T, typename U, typename V, typename W>
inline void pr(std::ostream &os, FmtFlags flags,
               const std::tuple<T, U, V, W> &x) {
  os << "(";
  pr(os, flags, std::get<0>(x));
  os << ", ";
  pr(os, flags, std::get<1>(x));
  os << ", ";
  pr(os, flags, std::get<2>(x));
  os << ", ";
  pr(os, flags, std::get<3>(x));
  os << ")";
}

template <typename T, typename U, typename V, typename W>
inline void pr_debug(std::ostream &os, FmtFlags flags,
                     const std::tuple<T, U, V, W> &x) {
  os << "(";
  pr_debug(os, flags, std::get<0>(x));
  os << ", ";
  pr_debug(os, flags, std::get<1>(x));
  os << ", ";
  pr_debug(os, flags, std::get<2>(x));
  os << ", ";
  pr_debug(os, flags, std::get<3>(x));
  os << ")";
}

template <typename T> inline std::string pr_str(const T &t) {
  std::ostringstream os;
  pr(os, FmtFlags::default_(), t);
  return os.str();
}

inline void fmt_flat(std::ostream &os, const std::string &s,
                     const std::vector<std::string> &args) {
  Int a = 0;
  Int i = 0;
  while (i < len(s)) {
    if (s[i] == '{') {
      if (i + 1 < len(s) && s[i + 1] == '{') {
        os << "{";
        i += 2;
      } else {
        if (i + 1 >= len(s) || s[i + 1] != '}') {
          AX("fmt error: open brace must be followed by close brace");
        }
        if (a >= len(args)) {
          AX("fmt error: extra format strings");
        }
        os << args[a];
        i += 2;
        ++a;
      }
    } else if (s[i] == '}') {
      if (i + 1 < len(s) && s[i + 1] == '}') {
        os << "}";
        i += 2;
      } else {
        AX("fmt error: unmatched close brace; literal close brace must be "
           "escaped");
      }
    } else {
      os << s[i];
      ++i;
    }
  }
  if (a != len(args)) {
    AX("fmt error: extra format args");
  }
}

inline void fmt_acc(std::vector<std::string> & /*args_acc*/) {}

template <typename T, typename... Ts>
inline void fmt_acc(std::vector<std::string> &args_acc, const T &t,
                    const Ts &...ts) {
  args_acc.push_back(pr_str(t));
  fmt_acc(args_acc, ts...);
}

template <typename... Ts>
inline void fmt(std::ostream &os, const std::string &s, const Ts &...ts) {
  std::vector<std::string> args;
  fmt_acc(args, ts...);
  fmt_flat(os, s, args);
}

template <typename... Ts>
inline std::string fmt_str(const std::string &s, const Ts &...ts) {
  std::ostringstream os;
  fmt(os, s, ts...);
  return os.str();
}

template <typename... Ts> inline std::string fmt_strs_var(const Ts &...ts) {
  std::vector<std::string> ret_vs;
  fmt_acc(ret_vs, ts...);
  std::string ret;
  for (const auto &ret_v : ret_vs) {
    ret += ret_v;
  }
  return ret;
}

////////////////////////////////////////////////////////////////////////////////
// Logging
////////////////////////////////////////////////////////////////////////////////

inline Int &get_init_time_inner() {
  static Int _init_time = -1;
  return _init_time;
}

inline void init_time_system() {
  if (get_init_time_inner() != -1) {
    return;
  }
  get_init_time_inner() = now();
}

inline Int get_init_time() {
  Int ret = get_init_time_inner();
  if (ret == -1) {
    init_time_system();
    ret = get_init_time_inner();
  }
  return ret;
}

inline Int &get_log_level() {
  static Int _log_level = 1;
  return _log_level;
}

inline void set_log_level(Int log_level_new) {
  get_log_level() = log_level_new;
}

// -1: Error messages user must see
//  0: Messages user should see
//  1: Progress updates
//  2: High-level result data
//  3: Intermediate result data
//  4: Unwieldy intermediate results/debug prints

template <typename... Ts> void log_inner(Int level, const Ts &...args) {
  static Int prev_level = -1;

  Int tab_len = 4;
  Int num_sp = tab_len * std::max<Int>(0L, level - 1);
  std::string sp = str_repeat(" ", num_sp);
  std::string prefix_prim = " ";
  if (level > 0) {
    prefix_prim = " -- ";
  }
  std::string prefix_prim_sp = str_repeat(" ", len(prefix_prim));

  auto time_since = now() - get_init_time();
  auto time_str_res = duration_fmt_str(time_since);
  auto prefix_total = fmt_str("[{}]{}{}", time_str_res, sp, prefix_prim);
  auto prefix_total_inner =
      fmt_str("[{}]{}{}", time_str_res, sp, prefix_prim_sp);

  auto args_str_raw = fmt_str(args...);
  auto args_str = str_reindent_inner(args_str_raw, prefix_total_inner);
  auto ret_str = fmt_str("{}{}", prefix_total, args_str);
  if (prev_level != -1 && prev_level != level) {
    ret_str = fmt_str("[{}]\n", time_str_res) + ret_str;
  }

  std::cout << ret_str << std::endl;

  prev_level = level;
}

template <typename... Ts> void LOG(Int level, const Ts &...args) {
  if ((level) <= (get_log_level())) {
    log_inner(level, args...);
  }
}
template <typename... Ts> void LG_ERR(const Ts &...args) { LOG(-1, args...); }
template <typename... Ts> void LG(const Ts &...args) { LOG(-1, args...); }
////////////////////////////////////////////////////////////////////////////////
// Assertions
////////////////////////////////////////////////////////////////////////////////

template <typename... Ts>
inline void AT(bool cond, const std::string &s, Ts... ts) {
  if (__builtin_expect(!cond, 0)) {
    LG("Assertion failed");
    if (len(s) > 0) {
      LG(": ");
      LG(s, ts...);
    }
    LG("\n");
    if (!cond) {
      throw std::runtime_error("Assertion failed");
    }
  }
}

inline void AT(bool cond) {
  if (__builtin_expect(!cond, 0)) {
    LG("Assertion failed\n");
    if (!cond) {
      throw std::runtime_error("Assertion failed");
    }
  }
}

template <typename... Ts>
[[noreturn]] inline void AX(const std::string &s, Ts... ts) {
  AT(false, s, ts...);
  throw std::runtime_error("Assertion failed");
}

[[noreturn]] inline void AX() {
  AT(false);
  throw std::runtime_error("Assertion failed");
}

template <typename T, typename U> inline void AR_eq(T t, U u) {
  if (!(t == u)) {
    AT(false, "equality check\nExpected: {}\nReceived: {}\n", u, t);
  }
}

template <typename T, typename U> inline void AR_ne(T t, U u) {
  if (!(t != u)) {
    AT(false, "comparison\nExpected: != {}\nReceived: {}\n", u, t);
  }
}

template <typename T, typename U> inline void AR_ge(T t, U u) {
  if (!(t >= u)) {
    AT(false, "comparison\nExpected: >= {}\nReceived: {}\n", u, t);
  }
}

template <typename T, typename U> inline void AR_gt(T t, U u) {
  if (!(t > u)) {
    AT(false, "comparison\nExpected: > {}\nReceived: {}\n", u, t);
  }
}

template <typename T, typename U> inline void AR_lt(T t, U u) {
  if (!(t < u)) {
    AT(false, "comparison\nExpected: < {}\nReceived: {}\n", u, t);
  }
}

template <typename T, typename U> inline void AR_le(T t, U u) {
  if (!(t <= u)) {
    AT(false, "comparison\nExpected: <= {}\nReceived: {}\n", u, t);
  }
}

inline void check_range(Int i, Int n) {
  AR_ge(i, 0);
  AR_lt(i, n);
}

[[noreturn]] inline void todo() { AX("Not yet implemented"); }

template <typename... Ts>
[[noreturn]] inline void todo(const std::string &msg, const Ts &...ts) {
  AX("Not yet implemented: " + msg, ts...);
}

////////////////////////////////////////////////////////////////////////////////
// Option types
////////////////////////////////////////////////////////////////////////////////

namespace Option {
template <typename T> Option_T<T> make_none();
template <typename T> Option_T<T> make_some(T t);
} // namespace Option

template <typename T> inline bool Option::_T<T>::is_some() const {
  return this->w_ == Option::_W::Some;
}

template <typename T> inline bool Option::_T<T>::is_none() const {
  return this->w_ == Option::_W::None;
}

template <typename T> inline T &Option::_T<T>::as_some() {
  AT(this->is_some());
  return *reinterpret_cast<T *>(this->t_);
}

template <typename T> inline const T &Option::_T<T>::as_some() const {
  AT(this->is_some());
  return *reinterpret_cast<const T *>(this->t_);
}

template <typename T> Option::_T<T>::_T(const Option::_T<T> &x) : w_(x.w_) {
  if (x.is_some()) {
    new (t_) T(x.as_some());
  }
}

template <typename T>
Option::_T<T> &Option::_T<T>::operator=(const Option::_T<T> &x) {
  if (this->is_some()) {
    reinterpret_cast<T *>(t_)->~T();
  }

  w_ = x.w_;
  if (this->is_some()) {
    new (t_) T(x.as_some());
  }

  return *this;
}

template <typename T> Option::_T<T>::_T() : w_(Option::_W::None) {}

template <typename T> Option::_T<T>::_T(Option::_W w, const T &t) : w_(w) {
  new (t_) T(t);
}

namespace Option {
template <typename T> _T<T>::~_T() {
  if (this->is_some()) {
    reinterpret_cast<T *>(t_)->~T();
  }
}
} // namespace Option

template <typename T> Option::_W Option::_T<T>::w() { return this->w_; }

template <typename T> Option_T<T> None() { return Option::_T<T>(); }

template <typename T> Option_T<T> Some(const T &t) {
  return Option::_T(Option::_W::Some, t);
}

template <typename T>
inline void pr(std::ostream &os, FmtFlags flags, const Option_T<T> &x) {
  if (x.is_some()) {
    os << "Some(";
    pr(os, flags, x.as_some());
    os << ")";
  } else {
    os << "None";
  }
}

template <typename T>
inline void pr_debug(std::ostream &os, FmtFlags flags, const Option_T<T> &x) {
  if (x.is_some()) {
    os << "Some(";
    pr_debug(os, flags, x.as_some());
    os << ")";
  } else {
    os << "None";
  }
}

////////////////////////////////////////////////////////////////////////////////
// Vectors
////////////////////////////////////////////////////////////////////////////////

struct _Vec_constr_internal {};

template <typename T> struct Vec;

template <typename T> struct Vec : enable_rc_from_this<Vec<T>> {
  Arena *A_;
  T *arr_;
  Int begin_;
  Int end_;
  Int len_;
  Int cap_;

  Vec<T> operator=(const Vec<T> &) = delete;
  Vec(const Vec<T> &) = delete;
  Vec(Vec<T> &&) = delete;

  inline void _init() {
    arr_ = reinterpret_cast<T *>(malloc_ext(cap_ * sizeof(T), A_));
  }

  inline void _deinit() {
    if (__builtin_expect(arr_ == nullptr, 0)) {
      return;
    }

    for (Int i = 0; i < len_; i++) {
      this->at_unchecked(i).~T();
    }

    free_ext(arr_, A_);
  }

  inline Vec() : A_(nullptr), begin_(0), end_(0), len_(0), cap_(1) {
    this->_init();
  }

  inline ~Vec() { this->_deinit(); }

  inline T *alloc_addr() const { return arr_; }

  inline Vec(Arena *A, Int len, Int cap, _Vec_constr_internal)
      : A_(A), len_(len), cap_(cap) {
    this->_init();
    begin_ = (cap_ - len_) / 2;
    end_ = begin_ + len_;
  }

  template <typename... Us> inline void _init_fill(Us... args) {
    begin_ = (cap_ - len_) / 2;
    end_ = begin_ + len_;
    for (Int i = 0; i < len_; i++) {
      new (&this->at_unchecked(i)) T(args...);
    }
  }

  template <typename... Us>
  inline Vec(Int len, Int cap, _Vec_constr_internal, Us... args)
      : A_(nullptr), len_(len), cap_(cap) {
    this->_init();
    this->_init_fill(args...);
  }

  inline static rc_ptr<Vec<T>> repeat(const T &x, Int n) {
    return make_rc<Vec<T>>(n, n, _Vec_constr_internal{}, x);
  }

  inline rc_ptr<Vec<T>> slice(Int lo, Int hi) const {
    AR_le(0, lo);
    AR_le(lo, hi);
    AR_le(hi, this->length());

    auto ret = make_rc<Vec<T>>();
    for (Int i = lo; i < hi; i++) {
      ret->push_back(this->at_unchecked(i));
    }
    return ret;
  }

  inline void extend(rc_ptr<Vec<T>> x) {
    for (const auto &xi : *x) {
      this->push(xi);
    }
  }

  inline rc_ptr<Vec<T>> clone_rc() const {
    auto ret = make_rc<Vec<T>>();
    for (const auto &xi : *this) {
      ret->push_back(xi);
    }
    return ret;
  }

  inline void clear() {
    Int n = this->length();
    for (Int i = 0; i < n; i++) {
      this->pop();
    }
  }

  inline rc_ptr<Vec<T>> with_append_rc(const T &x) const {
    auto ret = make_rc<Vec<T>>();
    for (const auto &si : *this) {
      ret->push_back(si);
    }
    ret->push_back(x);
    return ret;
  }

  inline rc_ptr<Vec<T>> with_extend(rc_ptr<Vec<T>> x) const {
    auto ret = make_rc<Vec<T>>();
    for (const auto &si : *this) {
      ret->push_back(si);
    }
    for (const auto &xi : *x) {
      ret->push_back(xi);
    }
    return ret;
  }

  [[always_inlines]] inline void reserve_unchecked(Int cap_new) {
    auto addr_old = this->alloc_addr();
    auto addr_new = reinterpret_cast<T *>(malloc_ext(cap_new * sizeof(T), A_));

    Int begin_new = (cap_new - len_) / 2;
    Int end_new = begin_new + len_;
    for (Int i = 0; i < len_; i++) {
      new (addr_new + begin_new + i) T(this->at_unchecked(i));
      this->at_unchecked(i).~T();
    }
    arr_ = addr_new;

    free_ext(addr_old, A_);
    cap_ = cap_new;
    begin_ = begin_new;
    end_ = end_new;
  }

  [[always_inlines]] inline void adjust_len_inplace_unchecked(Int len_new) {
    end_ = begin_ + len_new;
    len_ = len_new;
  }

  inline T *begin() const { return this->alloc_addr() + begin_; }

  inline T *end() const { return this->alloc_addr() + end_; }

  inline void push_back_unchecked(const T &t) {
    new (this->end()) T(t);
    ++end_;
    ++len_;
  }

  inline void push_back(const T &t) {
    while (__builtin_expect(end_ == cap_, 0)) {
      this->reserve_unchecked(cap_ * 2);
    }
    this->push_back_unchecked(t);
  }

  inline void push(const T &t) { this->push_back(t); }

  inline void pop_back_unchecked() {
    --end_;
    --len_;
    this->end()->~T();
  }

  inline void pop_back() {
    AR_ge(len_, 1);
    this->pop_back_unchecked();
  }

  inline void pop() { this->pop_back(); }

  inline T pop_back_val_unchecked() {
    T ret = *(this->end() - 1);
    this->pop_back_unchecked();
    return ret;
  }

  inline T pop_back_val() {
    AR_ge(len_, 1);
    return this->pop_back_val_unchecked();
  }

  inline T &front() {
    AR_ge(len_, 1);
    return this->at_unchecked(0);
  }

  inline T &back() {
    AR_ge(len_, 1);
    return this->at_unchecked(len_ - 1);
  }

  inline const T &front() const {
    AR_ge(len_, 1);
    return this->at_unchecked(0);
  }

  inline const T &back() const {
    AR_ge(len_, 1);
    return this->at_unchecked(len_ - 1);
  }

  inline void push_front_unchecked(const T &t) {
    new (this->begin() - 1) T(t);
    --begin_;
    ++len_;
  }

  inline void push_front(const T &t) {
    while (__builtin_expect(begin_ == 0, 0)) {
      this->reserve_unchecked(cap_ * 2);
    }
    this->push_front_unchecked(t);
  }

  inline void pop_front_unchecked() {
    this->begin()->~T();
    ++begin_;
    --len_;
  }

  inline void pop_front() {
    AR_ge(len_, 1);
    this->pop_front_unchecked();
  }

  inline T pop_front_val_unchecked() {
    T ret = *(this->begin());
    this->pop_front_unchecked();
    return ret;
  }

  inline T pop_front_val() {
    AR_ge(len_, 1);
    return this->pop_front_val_unchecked();
  }

  inline T &at_unchecked(Int i) { return *(this->alloc_addr() + begin_ + i); }

  inline const T &at_unchecked(Int i) const {
    return *(this->alloc_addr() + begin_ + i);
  }

  inline T &operator[](Int i) {
    AR_ge(i, 0);
    AR_lt(i, this->length());
    return this->at_unchecked(i);
  }

  inline const T &operator[](Int i) const {
    AR_ge(i, 0);
    AR_lt(i, this->length());
    return this->at_unchecked(i);
  }

  inline T &only() {
    AR_eq(this->length(), 1);
    return this->operator[](0);
  }

  inline const T &only() const {
    AR_eq(this->length(), 1);
    return this->operator[](0);
  }

  inline Int length() const { return len_; }

  inline bool empty() const { return len_ == 0; }

  inline void reverse() {
    for (Int i = 0; i < this->length() / 2; i++) {
      auto t = this->at_unchecked(i);
      this->at_unchecked(i) = this->at_unchecked(this->length() - 1 - i);
      this->at_unchecked(this->length() - 1 - i) = t;
    }
  }

  inline rc_ptr<Vec<T>> with_subst(Int i, const T &x) {
    AT(i >= 0);
    AT(i < this->length());
    auto ret = make_rc<Vec<T>>();
    for (Int j = 0; j < this->length(); j++) {
      if (j == i) {
        ret->push(x);
      } else {
        ret->push(this->operator[](j));
      }
    }
    return ret;
  }
};

template <typename T> using Vec_T = rc_ptr<Vec<T>>;

inline std::string vec_to_std_string(const Vec_T<char> &v) {
  return std::string(&v->at_unchecked(0), v->len_);
}

template <typename T> inline Int len(const Vec<T> &v) { return v.length(); }

template <typename T> inline Int len(const Vec_T<T> &v) { return v->length(); }

template <typename T>
inline void pr(std::ostream &os, FmtFlags flags, const Vec<T> &x) {
  os << "[";
  for (Int i = 0; i < len(x); i++) {
    if (i > 0) {
      os << ", ";
    }
    pr(os, flags, x[i]);
  }
  os << "]";
}

template <typename T>
inline void pr(std::ostream &os, FmtFlags flags, const rc_ptr<Vec<T>> &x) {
  os << "[";
  for (Int i = 0; i < len(*x); i++) {
    if (i > 0) {
      os << ", ";
    }
    pr(os, flags, (*x)[i]);
  }
  os << "]";
}

template <typename T>
inline void pr_debug(std::ostream &os, FmtFlags flags, const Vec<T> &x) {
  if (x.length() == 0) {
    os << "[]";
    return;
  }

  os << "[";
  for (Int i = 0; i < x.length(); i++) {
    flags.sub_lo().advance_lines(1, os);
    pr_debug(os, flags.sub_lo(), x[i]);
    os << ",";
  }
  flags.advance_lines(1, os);
  os << "]";
}

template <typename T>
inline void pr_debug(std::ostream &os, FmtFlags flags,
                     const rc_ptr<Vec<T>> &x) {
  if (x->length() == 0) {
    os << "[]";
    return;
  }

  os << "[";
  for (Int i = 0; i < x->length(); i++) {
    flags.sub_lo().advance_lines(1, os);
    pr_debug(os, flags.sub_lo(), (*x)[i]);
    os << ",";
  }
  flags.advance_lines(1, os);
  os << "]";
}

using Str = Vec<char>;
using Str_T = Vec_T<char>;

inline Str_T vec_from_std_string(const std::string &x) {
  auto ret = make_rc<Str>(len(x), len(x), _Vec_constr_internal{});
  memcpy(ret->begin(), x.c_str(), len(x));
  return ret;
}

struct StrSlice {
  Str_T base_;
  Int lo_;
  Int hi_;

  StrSlice(const Str_T &base, Int lo, Int hi) : base_(base), lo_(lo), hi_(hi) {}

  // Note: default constructor for internal use only; does not produce a valid
  // StrSlice instance.
  StrSlice() : base_(nullptr), lo_(0), hi_(0) {}

  static inline StrSlice from_std_string(const std::string &x) {
    Int lo = 0;
    Int hi = x.length();
    Str_T xb = vec_from_std_string(x);
    return StrSlice(xb, lo, hi);
  }

  inline std::string to_std_string() const {
    return std::string(&base_->at_unchecked(lo_), hi_ - lo_);
  }
};

inline void pr_debug(std::ostream &os, FmtFlags flags, const StrSlice &x) {
  pr_debug(os, flags, x.to_std_string());
}

inline void pr(std::ostream &os, FmtFlags /*flags*/, StrSlice x) {
  auto base_ptr = x.base_->begin();
  for (Int i = x.lo_; i < x.hi_; i++) {
    os << base_ptr[i];
  }
}

inline Vec_T<u8> byte_vec_from_string(const std::string &x) {
  auto ret = make_rc<Vec<u8>>();
  for (auto c : x) {
    ret->push(static_cast<u8>(c));
  }
  return ret;
}

inline std::string string_from_byte_vec(Vec_T<u8> x) {
  std::string ret;
  for (auto xi : *x) {
    ret += static_cast<char>(xi);
  }
  return ret;
}

////////////////////////////////////////////////////////////////////////////////
// Pool-based allocation
////////////////////////////////////////////////////////////////////////////////

struct Arena;
using Arena_T = rc_ptr<Arena>;

template <typename T> rc_ptr<T> rc_from_ptr_arena(void *x) {
  rc_ptr<T> ret;
  ret.rc_ = nullptr;
  ret.v_ = x;
  return ret;
}

template <typename T> T rc_from_ptr_arena_take(void *x) {
  return *rc_from_ptr_arena<T>(reinterpret_cast<T *>(x));
}

template <typename T> rc_ptr<T> rc_from_ptr_ext(void *x, Arena *A) {
  if (!!A) {
    return rc_from_ptr_arena<T>(x);
  } else {
    return rc_from_ptr_std(reinterpret_cast<T *>(x));
  }
}

template <typename T> rc_ptr<T> rc_from_ptr_ext_dec(void *x, Arena *A) {
  if (!!A) {
    return rc_from_ptr_arena<T>(x);
  } else {
    return rc_from_ptr_std_dec<T>(reinterpret_cast<T *>(x));
  }
}

template <typename T> T rc_from_ptr_ext_take(void *x, Arena *A) {
  if (!!A) {
    return rc_from_ptr_arena_take<T>(x);
  } else {
    return rc_from_ptr_std_take<T>(reinterpret_cast<T *>(x));
  }
}

struct Page {
  u8 *addr_;
  Int size_;

  static inline Page make_alloc(Int size) {
    Page ret;
    ret.addr_ = reinterpret_cast<u8 *>(malloc(size));
    ret.size_ = size;
    return ret;
  }
};

struct Arena : enable_rc_from_this<Arena> {
  Vec<Page> pages_;
  Page curr_page_;
  Int curr_offset_;
  Int page_size_default_;

  inline Arena(Int page_size_default = 4194304)
      : page_size_default_(page_size_default) {

    pages_.push(Page::make_alloc(page_size_default_));
    curr_page_ = pages_[0];
    curr_offset_ = 0;
  }

  inline ~Arena() {
    for (auto page : pages_) {
      free(page.addr_);
    }
  }

  inline void *alloc(Int size) {
    if (__builtin_expect(curr_offset_ + size > page_size_default_, 0)) {
      pages_.push(Page::make_alloc(std::max<Int>(size, page_size_default_)));
      curr_page_ = pages_[pages_.length() - 1];
      curr_offset_ = 0;
    }

    u8 *ret = curr_page_.addr_ + curr_offset_;
    curr_offset_ += size;
    return ret;
  }

  template <typename T, typename... Ts>
  [[always_inlines]] rc_ptr<T> make_new(Ts... args) {
    auto new_addr = this->alloc(sizeof(T));
    new (new_addr) T(args...);
    rc_ptr<T> ret;
    ret.rc_ = nullptr;
    ret.v_ = new_addr;
    init_rc_contents(reinterpret_cast<T *>(ret.v_), ret.v_, ret.rc_);
    return ret;
  }
};

using ArenaPtr = Arena *;

template <typename T, typename... Ts>
[[always_inlines]] inline rc_ptr<T> make_rc_ext(Arena *A, Ts... args) {
  if (__builtin_expect(!!A, 1)) {
    return A->make_new<T>(args...);
  } else {
    return make_rc<T>(args...);
  }
}

template <typename T, typename... Ts>
[[always_inlines]] inline T *make_rc_inc_ext(Arena *A, Ts... args) {
  if (__builtin_expect(!!A, 1)) {
    return reinterpret_cast<T *>(A->make_new<T>(args...).v_);
  }
  auto ret = make_rc<T>(args...);
  ret.incref();
  return reinterpret_cast<T *>(ret.v_);
}

inline void *malloc_ext(Int size, Arena *A) {
  if (__builtin_expect(!!A, 1)) {
    return A->alloc(size);
  }
  return malloc(size);
}

inline void *realloc_ext(void *x, Int size, Arena *A) {
  if (__builtin_expect(!!A, 1)) {
    auto ret = A->alloc(size);
    memcpy(ret, x, size);
    return ret;
  }
  return realloc(x, size);
}

inline void free_ext(void *x, Arena *A) {
  if (!A) {
    free(x);
  }
}

////////////////////////////////////////////////////////////////////////////////
// External code: picosha2
//
// The following delimited block is external code from the picosha2 project,
// distributed under the MIT license, with minor modifications.
////////////////////////////////////////////////////////////////////////////////

/*
The MIT License (MIT)

Copyright (C) 2017 okdshin

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in
all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
THE SOFTWARE.
*/
// picosha2:20140213

constexpr int PICOSHA2_BUFFER_SIZE_FOR_INPUT_ITERATOR = 1048576;

namespace picosha2 {
using word_t = unsigned long;
using byte_t = unsigned char;

static const size_t k_digest_size = 32;

namespace detail {
inline byte_t mask_8bit(byte_t x) { return x & 0xff; }

inline word_t mask_32bit(word_t x) { return x & 0xffffffff; }

const word_t add_constant[64] = {
    0x428a2f98, 0x71374491, 0xb5c0fbcf, 0xe9b5dba5, 0x3956c25b, 0x59f111f1,
    0x923f82a4, 0xab1c5ed5, 0xd807aa98, 0x12835b01, 0x243185be, 0x550c7dc3,
    0x72be5d74, 0x80deb1fe, 0x9bdc06a7, 0xc19bf174, 0xe49b69c1, 0xefbe4786,
    0x0fc19dc6, 0x240ca1cc, 0x2de92c6f, 0x4a7484aa, 0x5cb0a9dc, 0x76f988da,
    0x983e5152, 0xa831c66d, 0xb00327c8, 0xbf597fc7, 0xc6e00bf3, 0xd5a79147,
    0x06ca6351, 0x14292967, 0x27b70a85, 0x2e1b2138, 0x4d2c6dfc, 0x53380d13,
    0x650a7354, 0x766a0abb, 0x81c2c92e, 0x92722c85, 0xa2bfe8a1, 0xa81a664b,
    0xc24b8b70, 0xc76c51a3, 0xd192e819, 0xd6990624, 0xf40e3585, 0x106aa070,
    0x19a4c116, 0x1e376c08, 0x2748774c, 0x34b0bcb5, 0x391c0cb3, 0x4ed8aa4a,
    0x5b9cca4f, 0x682e6ff3, 0x748f82ee, 0x78a5636f, 0x84c87814, 0x8cc70208,
    0x90befffa, 0xa4506ceb, 0xbef9a3f7, 0xc67178f2};

const word_t initial_message_digest[8] = {0x6a09e667, 0xbb67ae85, 0x3c6ef372,
                                          0xa54ff53a, 0x510e527f, 0x9b05688c,
                                          0x1f83d9ab, 0x5be0cd19};

inline word_t ch(word_t x, word_t y, word_t z) { return (x & y) ^ ((~x) & z); }

inline word_t maj(word_t x, word_t y, word_t z) {
  return (x & y) ^ (x & z) ^ (y & z);
}

inline word_t rotr(word_t x, std::size_t n) {
  if (n >= 32) {
    throw std::runtime_error("Assertion failed");
  }
  return mask_32bit((x >> n) | (x << (32 - n)));
}

inline word_t bsig0(word_t x) { return rotr(x, 2) ^ rotr(x, 13) ^ rotr(x, 22); }

inline word_t bsig1(word_t x) { return rotr(x, 6) ^ rotr(x, 11) ^ rotr(x, 25); }

inline word_t shr(word_t x, std::size_t n) {
  if (n >= 32) {
    throw std::runtime_error("Assertion failed");
  }
  return x >> n;
}

inline word_t ssig0(word_t x) { return rotr(x, 7) ^ rotr(x, 18) ^ shr(x, 3); }

inline word_t ssig1(word_t x) { return rotr(x, 17) ^ rotr(x, 19) ^ shr(x, 10); }

template <typename RaIter1, typename RaIter2>
void hash256_block(RaIter1 message_digest, RaIter2 first, RaIter2 last) {
  if (first + 64 != last) {
    throw std::runtime_error("Assertion failed");
  }
  static_cast<void>(last); // for avoiding unused-variable warning
  word_t w[64];
  std::fill(w, w + 64, word_t(0));
  for (std::size_t i = 0; i < 16; ++i) {
    w[i] = (static_cast<word_t>(mask_8bit(*(first + i * 4))) << 24) |
           (static_cast<word_t>(mask_8bit(*(first + i * 4 + 1))) << 16) |
           (static_cast<word_t>(mask_8bit(*(first + i * 4 + 2))) << 8) |
           (static_cast<word_t>(mask_8bit(*(first + i * 4 + 3))));
  }
  for (std::size_t i = 16; i < 64; ++i) {
    w[i] =
        mask_32bit(ssig1(w[i - 2]) + w[i - 7] + ssig0(w[i - 15]) + w[i - 16]);
  }

  word_t a = *message_digest;
  word_t b = *(message_digest + 1);
  word_t c = *(message_digest + 2);
  word_t d = *(message_digest + 3);
  word_t e = *(message_digest + 4);
  word_t f = *(message_digest + 5);
  word_t g = *(message_digest + 6);
  word_t h = *(message_digest + 7);

  for (std::size_t i = 0; i < 64; ++i) {
    word_t temp1 = h + bsig1(e) + ch(e, f, g) + add_constant[i] + w[i];
    word_t temp2 = bsig0(a) + maj(a, b, c);
    h = g;
    g = f;
    f = e;
    e = mask_32bit(d + temp1);
    d = c;
    c = b;
    b = a;
    a = mask_32bit(temp1 + temp2);
  }
  *message_digest += a;
  *(message_digest + 1) += b;
  *(message_digest + 2) += c;
  *(message_digest + 3) += d;
  *(message_digest + 4) += e;
  *(message_digest + 5) += f;
  *(message_digest + 6) += g;
  *(message_digest + 7) += h;
  for (std::size_t i = 0; i < 8; ++i) {
    *(message_digest + i) = mask_32bit(*(message_digest + i));
  }
}

} // namespace detail

template <typename InIter>
void output_hex(InIter first, InIter last, std::ostream &os) {
  os.setf(std::ios::hex, std::ios::basefield);
  while (first != last) {
    os.width(2);
    os.fill('0');
    os << static_cast<unsigned int>(*first);
    ++first;
  }
  os.setf(std::ios::dec, std::ios::basefield);
}

template <typename InIter>
void bytes_to_hex_string(InIter first, InIter last, std::string &hex_str) {
  std::ostringstream oss;
  output_hex(first, last, oss);
  hex_str.assign(oss.str());
}

template <typename InContainer>
void bytes_to_hex_string(const InContainer &bytes, std::string &hex_str) {
  bytes_to_hex_string(bytes.begin(), bytes.end(), hex_str);
}

template <typename InIter>
std::string bytes_to_hex_string(InIter first, InIter last) {
  std::string hex_str;
  bytes_to_hex_string(first, last, hex_str);
  return hex_str;
}

template <typename InContainer>
std::string bytes_to_hex_string(const InContainer &bytes) {
  std::string hex_str;
  bytes_to_hex_string(bytes, hex_str);
  return hex_str;
}

class hash256_one_by_one {
public:
  hash256_one_by_one() { init(); }

  void init() {
    buffer_.clear();
    std::fill(data_length_digits_, data_length_digits_ + 4, word_t(0));
    std::copy(detail::initial_message_digest,
              detail::initial_message_digest + 8, h_);
  }

  template <typename RaIter> void process(RaIter first, RaIter last) {
    add_to_data_length(static_cast<word_t>(std::distance(first, last)));
    std::copy(first, last, std::back_inserter(buffer_));
    std::size_t i = 0;
    for (; i + 64 <= buffer_.size(); i += 64) {
      detail::hash256_block(h_, buffer_.begin() + i, buffer_.begin() + i + 64);
    }
    buffer_.erase(buffer_.begin(), buffer_.begin() + i);
  }

  void finish() {
    byte_t temp[64];
    std::fill(temp, temp + 64, byte_t(0));
    std::size_t remains = buffer_.size();
    std::copy(buffer_.begin(), buffer_.end(), temp);
    temp[remains] = 0x80;

    if (remains > 55) {
      std::fill(temp + remains + 1, temp + 64, byte_t(0));
      detail::hash256_block(h_, temp, temp + 64);
      std::fill(temp, temp + 64 - 4, byte_t(0));
    } else {
      std::fill(temp + remains + 1, temp + 64 - 4, byte_t(0));
    }

    write_data_bit_length(&(temp[56]));
    detail::hash256_block(h_, temp, temp + 64);
  }

  template <typename OutIter>
  void get_hash_bytes(OutIter first, OutIter last) const {
    for (const word_t *iter = h_; iter != h_ + 8; ++iter) {
      for (std::size_t i = 0; i < 4 && first != last; ++i) {
        *(first++) =
            detail::mask_8bit(static_cast<byte_t>((*iter >> (24 - 8 * i))));
      }
    }
  }

private:
  void add_to_data_length(word_t n) {
    word_t carry = 0;
    data_length_digits_[0] += n;
    for (std::size_t i = 0; i < 4; ++i) {
      data_length_digits_[i] += carry;
      if (data_length_digits_[i] >= 65536u) {
        carry = data_length_digits_[i] >> 16;
        data_length_digits_[i] &= 65535u;
      } else {
        break;
      }
    }
  }
  void write_data_bit_length(byte_t *begin) {
    word_t data_bit_length_digits[4];
    std::copy(data_length_digits_, data_length_digits_ + 4,
              data_bit_length_digits);

    // convert byte length to bit length (multiply 8 or shift 3 times left)
    word_t carry = 0;
    for (std::size_t i = 0; i < 4; ++i) {
      word_t before_val = data_bit_length_digits[i];
      data_bit_length_digits[i] <<= 3;
      data_bit_length_digits[i] |= carry;
      data_bit_length_digits[i] &= 65535u;
      carry = (before_val >> (16 - 3)) & 65535u;
    }

    // write data_bit_length
    for (int i = 3; i >= 0; --i) {
      (*begin++) = static_cast<byte_t>(data_bit_length_digits[i] >> 8);
      (*begin++) = static_cast<byte_t>(data_bit_length_digits[i]);
    }
  }
  std::vector<byte_t> buffer_;
  word_t data_length_digits_[4]; // as 64bit integer (16bit x 4 integer)
  word_t h_[8];
};

inline void get_hash_hex_string(const hash256_one_by_one &hasher,
                                std::string &hex_str) {
  byte_t hash[k_digest_size];
  hasher.get_hash_bytes(hash, hash + k_digest_size);
  return bytes_to_hex_string(hash, hash + k_digest_size, hex_str);
}

inline std::string get_hash_hex_string(const hash256_one_by_one &hasher) {
  std::string hex_str;
  get_hash_hex_string(hasher, hex_str);
  return hex_str;
}

namespace impl {
template <typename RaIter, typename OutIter>
void hash256_impl(RaIter first, RaIter last, OutIter first2, OutIter last2, int,
                  std::random_access_iterator_tag) {
  hash256_one_by_one hasher;
  // hasher.init();
  hasher.process(first, last);
  hasher.finish();
  hasher.get_hash_bytes(first2, last2);
}

template <typename InputIter, typename OutIter>
void hash256_impl(InputIter first, InputIter last, OutIter first2,
                  OutIter last2, int buffer_size, std::input_iterator_tag) {
  std::vector<byte_t> buffer(buffer_size);
  hash256_one_by_one hasher;
  // hasher.init();
  while (first != last) {
    int size = buffer_size;
    for (int i = 0; i != buffer_size; ++i, ++first) {
      if (first == last) {
        size = i;
        break;
      }
      buffer[i] = *first;
    }
    hasher.process(buffer.begin(), buffer.begin() + size);
  }
  hasher.finish();
  hasher.get_hash_bytes(first2, last2);
}
} // namespace impl

template <typename InIter, typename OutIter>
void hash256(InIter first, InIter last, OutIter first2, OutIter last2,
             int buffer_size = PICOSHA2_BUFFER_SIZE_FOR_INPUT_ITERATOR) {
  picosha2::impl::hash256_impl(
      first, last, first2, last2, buffer_size,
      typename std::iterator_traits<InIter>::iterator_category());
}

template <typename InIter, typename OutContainer>
void hash256(InIter first, InIter last, OutContainer &dst) {
  hash256(first, last, dst.begin(), dst.end());
}

template <typename InContainer, typename OutIter>
void hash256(const InContainer &src, OutIter first, OutIter last) {
  hash256(src.begin(), src.end(), first, last);
}

template <typename InContainer, typename OutContainer>
void hash256(const InContainer &src, OutContainer &dst) {
  hash256(src.begin(), src.end(), dst.begin(), dst.end());
}

template <typename InIter>
void hash256_hex_string(InIter first, InIter last, std::string &hex_str) {
  byte_t hashed[k_digest_size];
  hash256(first, last, hashed, hashed + k_digest_size);
  std::ostringstream oss;
  output_hex(hashed, hashed + k_digest_size, oss);
  hex_str.assign(oss.str());
}

template <typename InIter>
std::string hash256_hex_string(InIter first, InIter last) {
  std::string hex_str;
  hash256_hex_string(first, last, hex_str);
  return hex_str;
}

inline void hash256_hex_string(const std::string &src, std::string &hex_str) {
  hash256_hex_string(src.begin(), src.end(), hex_str);
}

template <typename InContainer>
void hash256_hex_string(const InContainer &src, std::string &hex_str) {
  hash256_hex_string(src.begin(), src.end(), hex_str);
}

template <typename InContainer>
std::string hash256_hex_string(const InContainer &src) {
  return hash256_hex_string(src.begin(), src.end());
}
template <typename OutIter>
void hash256(std::ifstream &f, OutIter first, OutIter last) {
  hash256(std::istreambuf_iterator<char>(f), std::istreambuf_iterator<char>(),
          first, last);
}
} // namespace picosha2

////////////////////////////////////////////////////////////////////////////////
// Hashing
////////////////////////////////////////////////////////////////////////////////

using SerBuf = Vec<u8>;

struct HashVal {
  u8 v_[32];

  inline bool operator==(const HashVal &x) const {
    return !memcmp(&v_[0], &x.v_[0], 32);
  }

  inline bool operator!=(const HashVal &x) const { return !(*this == x); }

  inline bool operator<(const HashVal &x) const {
    for (Int i = 0; i < 32; i++) {
      if (v_[i] < x.v_[i]) {
        return true;
      } else if (v_[i] > x.v_[i]) {
        return false;
      }
    }
    return false;
  }
};

} // namespace langcc

namespace std {
template <> struct hash<langcc::HashVal> {
  inline std::size_t operator()(const langcc::HashVal &x) const {
    return *reinterpret_cast<const size_t *>(&x.v_);
  }
};
} // namespace std

namespace langcc {

struct hash_obj {
  Option_T<HashVal> _hash_val_cached_;

  inline void update_hash_val_cached(const HashVal &hv) const {
    const_cast<hash_obj *>(this)->_hash_val_cached_ = Some(hv);
  }
};

inline void ser_bytes(SerBuf &buf, Int len, const u8 *data) {
  for (Int i = 0; i < len; i++) {
    buf.push(data[i]);
  }
}

inline void ser_int(SerBuf &buf, Int x) {
  ser_bytes(buf, 8, reinterpret_cast<u8 *>(&x));
}

inline void ser(SerBuf &buf, const HashVal &x) { ser_bytes(buf, 32, x.v_); }

// Note: Use for value-based hashing only; do not use for cryptographic
// or security-critical applications.
inline HashVal hash_data(const u8 *data, Int len) {
  HashVal ret;
  AR_eq(Int(picosha2::k_digest_size), 32);
  std::vector<char> dst(32, 0);
  picosha2::hash256(std::string(reinterpret_cast<const char *>(data), len),
                    dst);
  memcpy(&ret.v_[0], dst.data(), 32);
  return ret;
}

template <typename T,
          typename std::enable_if<std::is_base_of<hash_obj, T>::value>::type * =
              nullptr>
inline HashVal val_hash(const rc_ptr<T> &x) {
  if (x->_hash_val_cached_.is_some()) {
    return x->_hash_val_cached_.as_some();
  }
  SerBuf buf;
  x->hash_ser_acc(buf);
  auto ret = hash_data(&buf[0], buf.length());
  x->update_hash_val_cached(ret);
  return ret;
}

template <typename T> inline HashVal val_hash_base(const T &x) {
  SerBuf buf;
  hash_ser(buf, x);
  return hash_data(&buf[0], buf.length());
}

inline void hash_ser(SerBuf &buf, const Int &x) { ser_int(buf, x); }

inline HashVal val_hash(Int x) { return val_hash_base(x); }

inline void hash_ser(SerBuf &buf, const Unit & /*x*/) { ser_int(buf, 0); }

inline HashVal val_hash(Unit x) { return val_hash_base(x); }

template <typename T,
          typename std::enable_if<std::is_base_of<hash_obj, T>::value>::type * =
              nullptr>
inline void hash_ser(SerBuf &buf, const rc_ptr<T> &t) {
  ser(buf, val_hash(t));
}

template <typename T> inline void hash_ser(SerBuf &buf, const Vec<T> &v) {
  ser_int(buf, v.length());
  for (const auto &vi : v) {
    hash_ser(buf, vi);
  }
}

template <typename T> inline HashVal val_hash(const Vec<T> &v) {
  return val_hash_base(v);
}

template <typename T> inline void hash_ser(SerBuf &buf, const Vec_T<T> &v) {
  ser_int(buf, v->length());
  for (const auto &vi : *v) {
    hash_ser(buf, vi);
  }
}

template <typename T> inline HashVal val_hash(const Vec_T<T> &v) {
  return val_hash_base(v);
}

template <typename T> inline void hash_ser(SerBuf &buf, const Option_T<T> &v) {
  if (v.is_some()) {
    ser_int(buf, 1);
    hash_ser(buf, v.as_some());
  } else {
    ser_int(buf, 0);
  }
}

template <typename T> inline HashVal val_hash(const Option_T<T> &v) {
  return val_hash_base(v);
}

template <typename T, typename U>
inline void hash_ser(SerBuf &buf, const std::pair<T, U> &v) {
  hash_ser(buf, v.first);
  hash_ser(buf, v.second);
}

template <typename T, typename U>
inline HashVal val_hash(const std::pair<T, U> &v) {
  return val_hash_base(v);
}

template <typename T, typename U, typename V>
inline void hash_ser(SerBuf &buf, const std::tuple<T, U, V> &x) {

  auto [t, u, v] = x;
  hash_ser(buf, t);
  hash_ser(buf, u);
  hash_ser(buf, v);
}

template <typename T, typename U, typename V>
inline HashVal val_hash(const std::tuple<T, U, V> &x) {
  return val_hash_base(x);
}

template <typename T, typename U, typename V, typename W>
inline void hash_ser(SerBuf &buf, const std::tuple<T, U, V, W> &x) {

  auto [t, u, v, w] = x;
  hash_ser(buf, t);
  hash_ser(buf, u);
  hash_ser(buf, v);
  hash_ser(buf, w);
}

template <typename T, typename U, typename V, typename W>
inline HashVal val_hash(const std::tuple<T, U, V, W> &x) {

  return val_hash_base(x);
}

template <typename T, typename U, typename V, typename W, typename X>
inline void hash_ser(SerBuf &buf, const std::tuple<T, U, V, W, X> &a) {

  auto [t, u, v, w, x] = a;
  hash_ser(buf, t);
  hash_ser(buf, u);
  hash_ser(buf, v);
  hash_ser(buf, w);
  hash_ser(buf, x);
}

template <typename T, typename U, typename V, typename W, typename X>
inline HashVal val_hash(const std::tuple<T, U, V, W, X> &a) {

  return val_hash_base(a);
}

template <typename T, typename U, typename V, typename W, typename X,
          typename Y>
inline void hash_ser(SerBuf &buf, const std::tuple<T, U, V, W, X, Y> &a) {

  auto [t, u, v, w, x, y] = a;
  hash_ser(buf, t);
  hash_ser(buf, u);
  hash_ser(buf, v);
  hash_ser(buf, w);
  hash_ser(buf, x);
  hash_ser(buf, y);
}

template <typename T, typename U, typename V, typename W, typename X,
          typename Y>
inline HashVal val_hash(const std::tuple<T, U, V, W, X, Y> &a) {

  return val_hash_base(a);
}

inline void hash_ser(SerBuf &buf, const std::string &s) {
  ser_int(buf, s.length());
  ser_bytes(buf, s.length(), reinterpret_cast<const u8 *>(s.c_str()));
}

inline HashVal val_hash(const std::string &s) { return val_hash_base(s); }

inline void hash_ser(SerBuf &buf, const StrSlice &s) {
  hash_ser(buf, s.to_std_string());
}

inline HashVal val_hash(const StrSlice &s) { return val_hash_base(s); }

inline void pr(std::ostream &os, FmtFlags /*flags*/, HashVal hv) {
  for (Int i = 0; i < 32; i++) {
    os << hex_byte_display(hv.v_[i]);
  }
}

////////////////////////////////////////////////////////////////////////////////
// Map/Set/VecUniq
////////////////////////////////////////////////////////////////////////////////

template <typename K, typename V> struct Map;

template <typename K, typename V> struct MapIterator {
  Map<K, V> *m_;
  Int i_;

  inline void catchup();

  inline MapIterator<K, V> &operator++();
  inline bool operator==(const MapIterator<K, V> &x);
  inline bool operator!=(const MapIterator<K, V> &x) { return !(*this == x); }

  inline std::pair<K, V> &operator*() { return m_->vs_[i_]; }

  inline const std::pair<K, V> &operator*() const { return m_->vs_[i_]; }
};

template <typename K, typename V> struct Map;
template <typename K, typename V> using Map_T = rc_ptr<Map<K, V>>;

template <typename K, typename V> struct Map : enable_rc_from_this<Map<K, V>> {
  std::unordered_map<HashVal, Int> m_;
  Vec<bool> live_;
  Vec<std::pair<K, V>> vs_;

  inline void insert(const K &k, const V &v) {
    auto hk = val_hash(k);
    auto n = vs_.length();
    auto k2 = K(k);
    auto v2 = V(v);
    vs_.push(std::make_pair<K, V>(std::move(k2), std::move(v2)));
    live_.push(true);
    if (m_.find(hk) != m_.end()) {
      auto i = m_[hk];
      live_[i] = false;
    }
    m_[hk] = n;
  }

  inline Int length() const { return m_.size(); }

  inline bool contains_key(const K &k) {
    auto hk = val_hash(k);
    return m_.find(hk) != m_.end();
  }

  inline V &operator[](const K &k) {
    auto hk = val_hash(k);
    AT(m_.find(hk) != m_.end());
    auto i = m_[hk];
    return vs_[i].second;
  }

  inline const V &operator[](const K &k) const {
    auto hk = val_hash(k);
    auto it = m_.find(hk);
    AT(it != m_.end());
    auto i = it->second;
    return vs_[i].second;
  }

  inline V &at_create(const K &k) {
    if (!this->contains_key(k)) {
      this->insert(k, V());
    }
    return this->operator[](k);
  }

  template <typename Vi> inline rc_ptr<Vi> &at_create_shared(const K &k) {
    if (!this->contains_key(k)) {
      this->insert(k, make_rc<Vi>());
    }
    return this->operator[](k);
  }

  inline void insert_strict(const K &k, const V &v) {
    AT(!this->contains_key(k));
    this->insert(k, v);
  }

  inline void remove(const K &k) {
    auto hk = val_hash(k);
    auto it = m_.find(hk);
    if (it == m_.end()) {
      return;
    }
    auto i = it->second;
    live_[i] = false;
    m_.erase(it);
  }

  inline MapIterator<K, V> begin() {
    MapIterator<K, V> ret;
    ret.m_ = this;
    ret.i_ = 0;
    ret.catchup();
    return ret;
  }

  inline MapIterator<K, V> end() {
    MapIterator<K, V> ret;
    ret.m_ = this;
    ret.i_ = vs_.length();
    return ret;
  }

  inline const MapIterator<K, V> begin() const {
    MapIterator<K, V> ret;
    ret.m_ = const_cast<Map<K, V> *>(this);
    ret.i_ = 0;
    ret.catchup();
    return ret;
  }

  inline const MapIterator<K, V> end() const {
    MapIterator<K, V> ret;
    ret.m_ = const_cast<Map<K, V> *>(this);
    ret.i_ = vs_.length();
    return ret;
  }

  inline Map_T<K, V> clone_rc() const {
    auto ret = make_rc<Map<K, V>>();
    for (auto [k, v] : *this) {
      ret->insert(k, v);
    }
    return ret;
  }

  inline Vec_T<std::pair<K, V>> items_to_vec() const {
    auto ret = make_rc<Vec<std::pair<K, V>>>();
    for (auto [k, v] : *this) {
      ret->push_back(std::make_pair(k, v));
    }
    return ret;
  }
};

template <typename K, typename V>
inline MapIterator<K, V> &MapIterator<K, V>::operator++() {
  if (*this == m_->end()) {
    return *this;
  }
  ++i_;
  this->catchup();
  return *this;
}

template <typename K, typename V> inline void MapIterator<K, V>::catchup() {
  while (i_ < m_->vs_.length()) {
    if (m_->live_[i_]) {
      return;
    }
    ++i_;
  }
}

template <typename K, typename V>
inline bool MapIterator<K, V>::operator==(const MapIterator<K, V> &x) {
  return i_ == x.i_;
}

template <typename K, typename V>
inline void hash_ser(SerBuf &buf, const Map<K, V> &m) {
  ser_int(buf, m.length());
  Vec<HashVal> vv;
  for (const auto &p : m) {
    vv.push(val_hash(p));
  }
  std::sort(vv.begin(), vv.end());
  for (const auto &vh : vv) {
    ser(buf, vh);
  }
}

template <typename K, typename V>
inline void hash_ser(SerBuf &buf, const Map_T<K, V> &m) {
  hash_ser(buf, *m);
}

template <typename K, typename V> inline HashVal val_hash(const Map<K, V> &m) {
  return val_hash_base(m);
}

template <typename K, typename V>
inline HashVal val_hash(const Map_T<K, V> &m) {
  return val_hash_base(m);
}

template <typename K, typename V>
inline void pr_debug(std::ostream &os, FmtFlags flags, const Map<K, V> &x) {
  if (x.length() == 0) {
    os << "{}";
    return;
  }

  os << "{";
  for (auto p : x) {
    flags.sub_lo().advance_lines(1, os);
    pr_debug(os, flags.sub_lo(), p.first);
    os << ": ";
    pr_debug(os, flags.sub_lo(), p.second);
    os << ",";
  }
  flags.advance_lines(1, os);
  os << "}";
}

template <typename K, typename V>
inline void pr_debug(std::ostream &os, FmtFlags flags, const Map_T<K, V> &x) {
  pr_debug(os, flags, *x);
}

template <typename K, typename V>
inline void pr(std::ostream &os, FmtFlags flags, const Map<K, V> &x) {
  if (x.length() == 0) {
    os << "{}";
    return;
  }

  os << "{";
  for (const auto &p : x) {
    flags.sub_lo().advance_lines(1, os);
    pr(os, flags.sub_lo(), p.first);
    os << ": ";
    pr(os, flags.sub_lo(), p.second);
    os << ",";
  }
  flags.advance_lines(1, os);
  os << "}";
}

template <typename K, typename V>
inline void pr(std::ostream &os, FmtFlags flags, const Map_T<K, V> &x) {
  pr(os, flags, *x);
}

template <typename T> struct Set;

template <typename T> using Set_T = rc_ptr<Set<T>>;

template <typename T> inline void hash_ser(SerBuf &buf, const Set<T> &v) {
  ser_int(buf, v.length());
  Vec<HashVal> vv;
  for (const auto &vi : v) {
    vv.push(val_hash(vi));
  }
  std::sort(vv.begin(), vv.end());
  for (const auto &vh : vv) {
    ser(buf, vh);
  }
}

template <typename T> inline void hash_ser(SerBuf &buf, const Set_T<T> &v) {
  hash_ser(buf, *v);
}

template <typename T> inline HashVal val_hash(const Set<T> &v) {
  return val_hash_base(v);
}

template <typename T> inline HashVal val_hash(const Set_T<T> &v) {
  return val_hash_base(v);
}

template <typename T> struct SetIterator {
  Set<T> *s_;
  Int i_;

  inline void catchup();

  inline SetIterator<T> &operator++();

  inline bool operator==(const SetIterator<T> &x) { return i_ == x.i_; }

  inline bool operator!=(const SetIterator<T> &x) { return !(*this == x); }

  inline T &operator*() { return s_->vs_[i_]; }

  inline const T &operator*() const { return s_->vs_[i_]; }
};

template <typename T> struct Set : enable_rc_from_this<Set<T>> {
  std::unordered_map<HashVal, Int> m_;
  Vec<bool> live_;
  Vec<T> vs_;

  inline void insert(const T &x) {
    auto hk = val_hash(x);
    if (m_.find(hk) != m_.end()) {
      return;
    }
    auto n = vs_.length();
    vs_.push(x);
    live_.push(true);
    m_[hk] = n;
  }

  static inline Set_T<T> singleton(const T &x) {
    auto ret = make_rc<Set<T>>();
    ret->insert(x);
    return ret;
  }

  inline bool contains(const T &x) {
    auto hk = val_hash(x);
    return m_.find(hk) != m_.end();
  }

  inline void insert_strict(const T &x) {
    if (this->contains(x)) {
      LG("Element already present in set: {}\n", x);
      AX();
    }
    this->insert(x);
  }

  inline void remove(const T &x) {
    auto hk = val_hash(x);
    auto it = m_.find(hk);
    if (it == m_.end()) {
      return;
    }
    auto i = it->second;
    live_[i] = false;
    m_.erase(it);
  }

  inline SetIterator<T> begin() const {
    SetIterator<T> ret;
    ret.s_ = const_cast<Set<T> *>(this);
    ret.i_ = 0;
    ret.catchup();
    return ret;
  }

  inline SetIterator<T> end() const {
    SetIterator<T> ret;
    ret.s_ = const_cast<Set<T> *>(this);
    ret.i_ = vs_.length();
    return ret;
  }

  inline Set_T<T> clone_rc() const {
    auto ret = make_rc<Set<T>>();
    for (auto x : *this) {
      ret->insert(x);
    }
    return ret;
  }

  inline Set_T<T> with_union(const Set_T<T> &x) const {
    auto ret = make_rc<Set<T>>();
    for (const auto vi : *this) {
      ret->insert(vi);
    }
    for (const auto vi : *x) {
      ret->insert(vi);
    }
    return ret;
  }

  inline Int length() const { return vs_.length(); }

  inline T &only() {
    AT(this->length() == 1);
    return *this->begin();
  }

  inline Vec_T<T> to_vec() const {
    auto ret = make_rc<Vec<T>>();
    for (auto x : *this) {
      ret->push(x);
    }
    return ret;
  }
};

template <typename T> inline SetIterator<T> &SetIterator<T>::operator++() {
  if (*this == s_->end()) {
    return *this;
  }
  ++i_;
  this->catchup();
  return *this;
}

template <typename T> inline void SetIterator<T>::catchup() {
  while (i_ < s_->vs_.length()) {
    if (s_->live_[i_]) {
      return;
    }
    ++i_;
  }
}

template <typename T>
inline void pr(std::ostream &os, FmtFlags flags, const Set<T> &x) {
  if (x.length() == 0) {
    os << "{}";
    return;
  }
  os << "{";
  for (auto xi : x) {
    flags.sub_lo().advance_lines(1, os);
    pr(os, flags.sub_lo(), xi);
    os << ",";
  }
  flags.advance_lines(1, os);
  os << "}";
}

template <typename T>
inline void pr(std::ostream &os, FmtFlags flags, const Set_T<T> &x) {
  pr(os, flags, *x);
}

template <typename T>
inline void pr_debug(std::ostream &os, FmtFlags flags, const Set<T> &x) {
  if (x.length() == 0) {
    os << "{}";
    return;
  }
  os << "{";
  for (auto xi : x) {
    flags.sub_lo().advance_lines(1, os);
    pr_debug(os, flags.sub_lo(), xi);
    os << ",";
  }
  flags.advance_lines(1, os);
  os << "}";
}

template <typename T>
inline void pr_debug(std::ostream &os, FmtFlags flags, const Set_T<T> &x) {
  pr_debug(os, flags, *x);
}

template <typename K, typename V>
inline Map_T<V, Set_T<K>> key_value_rev(Map_T<K, V> m) {
  auto ret = make_rc<Map<V, Set_T<K>>>();
  for (auto [k, v] : *m) {
    if (!ret->contains_key(v)) {
      ret->insert(v, make_rc<Set<K>>());
    }
    ret->operator[](v)->insert(k);
  }
  return ret;
}

template <typename T> struct VecUniq;

template <typename T> using VecUniq_T = rc_ptr<VecUniq<T>>;

template <typename T> struct VecUniq : enable_rc_from_this<VecUniq<T>> {
  Vec<T> items_;
  Map<T, Int> inds_;

  VecUniq<T> operator=(const VecUniq<T> &) = delete;
  VecUniq(const VecUniq<T> &) = delete;
  VecUniq(VecUniq<T> &&) = delete;

  inline VecUniq() {}

  inline ~VecUniq() {}

  inline Int length() const { return items_.length(); }

  inline bool contains(const T &x) { return inds_.contains_key(x); }

  inline Int insert(const T &x) {
    if (inds_.contains_key(x)) {
      return inds_[x];
    }
    Int n = items_.length();
    items_.push_back(x);
    inds_.insert(x, n);
    return n;
  }

  inline Int insert_strict(const T &x) {
    AT(!this->contains(x));
    return this->insert(x);
  }

  inline Option_T<Int> index_of_maybe(const T &x) {
    if (!inds_.contains_key(x)) {
      return None<Int>();
    }
    return Some<Int>(inds_[x]);
  }

  inline T &at_index(Int i) {
    check_range(i, this->length());
    return items_[i];
  }

  inline const T &at_index(Int i) const {
    check_range(i, this->length());
    return items_[i];
  }

  inline T &operator[](Int i) { return this->at_index(i); }

  inline const T &operator[](Int i) const { return this->at_index(i); }

  inline VecUniq_T<T> with_union(const VecUniq_T<T> &x) const {
    auto ret = make_rc<VecUniq<T>>();
    for (const auto vi : *this) {
      ret->insert(vi);
    }
    for (const auto vi : *x) {
      ret->insert(vi);
    }
    return ret;
  }

  inline T *begin() { return items_.begin(); }

  inline const T *begin() const { return items_.begin(); }

  inline T *end() { return items_.end(); }

  inline const T *end() const { return items_.end(); }
};

template <typename T> inline void hash_ser(SerBuf &buf, const VecUniq<T> &x) {
  ser_int(buf, x.length());
  Vec<HashVal> vv;
  for (const auto &xi : x) {
    vv.push(val_hash(xi));
  }
  // NOTE: Do not sort
  for (const auto &vh : vv) {
    ser(buf, vh);
  }
}

template <typename T> inline void hash_ser(SerBuf &buf, const VecUniq_T<T> &x) {
  hash_ser(buf, *x);
}

template <typename T>
inline void pr_debug(std::ostream &os, FmtFlags flags, const VecUniq<T> &x) {
  if (x.length() == 0) {
    os << "[]";
    return;
  }

  os << "[";
  for (Int i = 0; i < x.length(); i++) {
    flags.sub_lo().advance_lines(1, os);
    pr_debug(os, flags.sub_lo(), x[i]);
    os << ",";
  }
  flags.advance_lines(1, os);
  os << "]";
}

template <typename T>
inline void pr_debug(std::ostream &os, FmtFlags flags, const VecUniq_T<T> &x) {
  pr_debug(os, flags, *x);
}

template <typename T>
inline void pr(std::ostream &os, FmtFlags flags, const VecUniq<T> &x) {
  if (x.length() == 0) {
    os << "[]";
    return;
  }

  os << "[";
  for (Int i = 0; i < x.length(); i++) {
    flags.sub_lo().advance_lines(1, os);
    pr(os, flags.sub_lo(), x[i]);
    os << ",";
  }
  flags.advance_lines(1, os);
  os << "]";
}

template <typename T>
inline void pr(std::ostream &os, FmtFlags flags, const VecUniq_T<T> &x) {
  pr(os, flags, *x);
}

////////////////////////////////////////////////////////////////////////////////
// Miscellaneous utilities
////////////////////////////////////////////////////////////////////////////////

template <typename T> std::vector<T> vec_repeat(T t, Int n) {
  return std::vector<T>(n, t);
}

template <typename T> std::vector<T> vec_reversed(const std::vector<T> &v) {
  std::vector<T> w;
  for (Int i = len(v) - 1; i >= 0; i--) {
    w.push_back(v[i]);
  }
  return w;
}

inline Int div_ceil(Int a, Int b) {
  AR_gt(b, 0);
  return (a + b - 1) / b;
}

inline Int align_to(Int x, Int a) { return div_ceil(x, a) * a; }

struct Gensym;
using Gensym_T = rc_ptr<Gensym>;

struct Gensym {
  Int next_;

  Gensym(const Gensym &) = delete;
  Gensym &operator=(const Gensym &) = delete;

  inline Int gen() {
    auto ret = next_;
    ++next_;
    return ret;
  }

  inline Gensym() : next_(0) {}
};

using PrintTableRow = std::vector<std::string>;

struct PrintTable;
using PrintTable_T = rc_ptr<PrintTable>;

struct PrintTable {
  std::vector<std::tuple<std::string, Align>> col_;
  std::vector<std::vector<PrintTableRow>> items_;
  std::vector<std::deque<std::string>> buffer_;
  Int buffer_cursor_{};
  bool buffer_active_{};
  std::vector<Int> widths_;

  inline static PrintTable_T
  make_ext(const std::vector<std::tuple<std::string, Align>> &col) {
    auto ret = make_rc<PrintTable>();
    AT(len(col) > 0);
    ret->col_ = col;
    for (Int i = 0; i < len(col); i++) {
      ret->buffer_.emplace_back();
    }
    ret->buffer_cursor_ = 0;
    ret->buffer_active_ = false;
    ret->widths_ = vec_repeat<Int>(0L, len(col));
    return ret;
  }

  inline static PrintTable_T
  make(const std::vector<std::tuple<Int, Align>> &col) {
    std::vector<std::tuple<std::string, Align>> col_ext;
    for (auto [count_, align] : col) {
      col_ext.emplace_back(str_repeat(" ", count_), align);
    }
    return make_ext(col_ext);
  }

  inline static PrintTable_T new_var(Int n_col, Align align, Int spacing) {
    std::tuple<Int, Align> p = {spacing, align};
    auto cols = vec_repeat(p, n_col);
    return make(cols);
  }

  inline Int num_col() { return len(col_); }

  inline Int num_rows() {
    AT(!buffer_active_);
    return len(items_);
  }

  inline Int get_buffer_cursor() {
    check_range(buffer_cursor_, this->num_col());
    return buffer_cursor_;
  }

  inline void flush_inner() {
    if (!buffer_active_) {
      return;
    }

    std::vector<std::vector<std::string>> curr_item;

    while (true) {
      std::vector<std::string> curr_row;
      bool trivial = true;
      for (Int j = 0; j < this->num_col(); j++) {
        if (len(buffer_[j]) == 0) {
          curr_row.emplace_back("");
        } else {
          auto x = buffer_[j].front();
          buffer_[j].pop_front();
          if (len(x) > widths_[j]) {
            widths_[j] = len(x);
          }
          curr_row.push_back(x);
          trivial = false;
        }
      }

      if (trivial) {
        break;
      }

      curr_item.push_back(curr_row);
    }

    items_.push_back(curr_item);
    buffer_active_ = false;
    buffer_cursor_ = 0;
  }

  inline void flush_check() {
    if (buffer_cursor_ == this->num_col()) {
      this->flush_inner();
    }
  }

  template <typename T> inline void push_buffer_direct(Int j, T entry) {
    auto x = fmt_str("{}", entry);
    check_range(j, this->num_col());
    buffer_[j].push_back(x);
    buffer_active_ = true;
  }

  template <typename T> inline void push(T entry) {
    auto x = fmt_str("{}", entry);
    auto xs = str_split(x, "\n");
    Int j = this->get_buffer_cursor();
    for (const auto &xi : xs) {
      buffer_[j].push_back(xi);
    }
    buffer_active_ = true;
    buffer_cursor_++;
    this->flush_check();
  }

  inline void push_blank_item() { this->push(""); }

  inline void push_blank_line() {
    AR_eq(this->get_buffer_cursor(), 0);
    for (Int j = 0; j < this->num_col(); j++) {
      this->push_blank_item();
    }
  }

  inline void write_row(std::ostream &os, Int i) {
    check_range(i, len(items_));
    for (auto row : items_[i]) {
      for (Int j = 0; j < this->num_col(); j++) {
        auto [prefix, align] = col_[j];
        fmt(os, "{}", prefix);
        auto strict = (j != this->num_col() - 1);
        fmt(os, "{}", str_align(row[j], align, widths_[j], strict));
      }
      fmt(os, "\n");
    }
  }
};

inline void pr(std::ostream &os, FmtFlags /*flags*/, PrintTable_T td) {
  AT(!td->buffer_active_, "buffer active");
  for (Int i = 0; i < td->num_rows(); i++) {
    td->write_row(os, i);
  }
}

////////////////////////////////////////////////////////////////////////////////
// System utilities
////////////////////////////////////////////////////////////////////////////////

inline Option_T<std::string> stdin_readline() {
  std::string ret;
  std::getline(std::cin, ret);
  if (!std::cin.good()) {
    return None<std::string>();
  }
  return Some<std::string>(ret + "\n");
}

inline Time now() {
  auto ret_duration = std::chrono::steady_clock::now().time_since_epoch();
  Time ret = std::chrono::duration_cast<std::chrono::nanoseconds>(ret_duration)
                 .count();
  return ret;
}

inline i32 sys_chk(i32 ret, const std::string &desc) {
  if (ret == 0) {
    return ret;
  }
  LG(" *** Return code: {}: {}\n", desc, ret);
  perror(desc.c_str());
  AX();
}

inline i32 sys_chk_nonneg(i32 ret, const std::string &desc) {
  if (ret >= 0) {
    return ret;
  }
  LG(" *** Return code: {}: {}\n", desc, ret);
  perror(desc.c_str());
  AX();
}

inline std::string read_file(const std::filesystem::path &filename) {
  std::ifstream inFile(filename, std::ios_base::binary);
  if (!inFile.good()) {
    LG_ERR("Error opening for reading: {}", filename);
    AX();
  }
  std::stringstream strStream;
  strStream << inFile.rdbuf();
  return strStream.str();
}

inline Str_T read_file_shared(const std::filesystem::path &filename,
                              Arena *A = nullptr) {
  Int len = std::filesystem::file_size(filename);
  std::ifstream inFile(filename, std::ios_base::binary);
  if (!inFile.good()) {
    LG_ERR("Error opening for reading: {}", filename.string());
    AX();
  }
  auto ret = make_rc<Str>(A, 0, len * 2, _Vec_constr_internal{});
  inFile.read(&ret->at_unchecked(0), len);
  AR_eq(static_cast<Int>(inFile.gcount()), len);
  ret->adjust_len_inplace_unchecked(len);
  return ret;
}

inline void write_file(const std::filesystem::path &filename_dst,
                       const std::string &contents) {
  std::ofstream fout(filename_dst);
  if (!fout.good()) {
    LG_ERR("Error opening for writing: {}", filename_dst);
    AX();
  }
  fout << contents;
  fout.close();
}

} // namespace langcc
