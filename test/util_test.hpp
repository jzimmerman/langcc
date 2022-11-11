
#include "langcc_util.hpp"

namespace langcc {

TEST(str_split1) {
  std::string input = "ABC\nDEF\n\nG\n";
  std::vector<std::string> output_exp = {
      "ABC", "DEF", "", "G", "",
  };
  auto output_act = str_split(input, "\n");
  AR_eq(output_exp, output_act);
}

TEST(print_table1) {
  std::vector<std::tuple<Int, Align>> aligns = {{2, Align::RIGHT},
                                                {1, Align::LEFT}};

  std::string output_exp;
  std::string output_act;

  auto td = PrintTable::make(aligns);

  LG("table rc: {}\n", *td.rc_);

  td->push("A\nBCD\n\nEF");
  td->push("G");
  td->push("HI");
  td->push("JKL");

  LG("table rc: {}\n", *td.rc_);

  output_exp = std::string("") + "    A G\n" + "  BCD \n" + "      \n" +
               "   EF \n" + "   HI JKL\n";
  output_act = fmt_str("{}", td);

  AR_eq(output_exp, output_act);
}

TEST(char_display1) {
  auto output_exp = "`a`";
  auto output_act = char_display('a');
  AR_eq(output_exp, output_act);
}

TEST(char_display2) {
  auto output_exp = "`\\U0000feff`";
  auto output_act = char_display(0xfeff);
  AR_eq(output_exp, output_act);
}

TEST(vec1) {
  auto Q = make_shared<Vec<Int>>();
  Q->push_back(1);
  Q->push_back(2);
  Q->push_front(3);
  Q->push_front(4);
  AR_eq(Q->pop_back_val(), 2);
  AR_eq(Q->pop_back_val(), 1);
  AR_eq(Q->pop_back_val(), 3);
  AR_eq(Q->pop_back_val(), 4);
}

struct test_vec2_struct {
  shared_ptr<Int> v_;
  inline test_vec2_struct(Int x) : v_(make_shared<Int>(x)) {}
};

TEST(vec2) {
  auto Q = make_shared<Vec<test_vec2_struct>>();
  Q->push_back(test_vec2_struct{1});
  Q->push_back(test_vec2_struct{2});
  Q->push_front(test_vec2_struct{3});
  Q->push_front(test_vec2_struct{4});
  Q->pop_back();
  Q->pop_front();
}

TEST(utf8_encode1) {
  std::vector<Ch> v = {0x12,     0x34, 0x56,     0x123, 0x5678,
                       0x101234, 0x12, 0x10ffff, 0x34};
  std::string s = utf8_encode(v);

  for (auto c : s) {
    LG("{} ", hex_byte_display(static_cast<u8>(c)));
  }
  LG("\n");

  auto r = utf8_decode(s);
  AT(r.is_some());
  AR_eq(r.as_some(), v);
}

} // namespace langcc
