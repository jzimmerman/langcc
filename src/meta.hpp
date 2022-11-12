#pragma once

#include "langcc_util.hpp"

#include "meta__gen.hpp"

#include "common.hpp"

namespace langcc {

using namespace lang;

using meta::Node::AttrClause_T;
using meta::Node::AttrClauseExpr_T;
using meta::Node::ParseExpr_T;
using meta::Node::ParserDecl::Rule_T;

inline ParseExpr_Base_T parse_expr_base_from_token(TokenBase_T x) {
  return ParseExpr_Base::make(x, None<meta::Node::ParseExpr_T>());
}

inline meta::Node::Stanza::Tokens_T
lang_get_tokens_stanza(meta::Node::Lang_T L) {
  for (auto &stanza : *L->stanzas_) {
    if (stanza->is_Tokens()) {
      return stanza->as_Tokens();
    }
  }
  AX();
}

inline meta::Node::Stanza::Lexer_T lang_get_lexer_stanza(meta::Node::Lang_T L) {
  for (auto &stanza : *L->stanzas_) {
    if (stanza->is_Lexer()) {
      return stanza->as_Lexer();
    }
  }
  AX();
}

inline meta::Node::Stanza::Parser_T
lang_get_parser_stanza(meta::Node::Lang_T L) {
  for (auto &stanza : *L->stanzas_) {
    if (stanza->is_Parser()) {
      return stanza->as_Parser();
    }
  }
  AX();
}

inline bool lang_is_expected_fail(meta::Node::Lang_T L) {
  auto parser = lang_get_parser_stanza(L);
  for (auto decl : *parser->decls_) {
    if (decl->is_Prop()) {
      for (auto prop : *decl->as_Prop()->props_) {
        if (prop->is_Err_()) {
          return true;
        }
      }
    }
  }
  return false;
}

inline Option_T<meta::Node::Stanza::Test_T>
lang_get_test_stanza(meta::Node::Lang_T L) {
  Option_T<meta::Node::Stanza::Test_T> ret = None<meta::Node::Stanza::Test_T>();
  for (auto &stanza : *L->stanzas_) {
    if (stanza->is_Test()) {
      if (ret.is_some()) {
        AX();
      }
      ret = Some<meta::Node::Stanza::Test_T>(stanza->as_Test());
    }
  }
  return ret;
}

inline Option_T<meta::Node::Stanza::CompileTest_T>
lang_get_compile_test_stanza(meta::Node::Lang_T L) {

  Option_T<meta::Node::Stanza::CompileTest_T> ret =
      None<meta::Node::Stanza::CompileTest_T>();
  for (auto &stanza : *L->stanzas_) {
    if (stanza->is_CompileTest()) {
      if (ret.is_some()) {
        AX();
      }
      ret = Some<meta::Node::Stanza::CompileTest_T>(stanza->as_CompileTest());
    }
  }
  return ret;
}

inline Int lang_get_k_default(meta::Node::Lang_T L) {
  Int ret = -1;
  auto parser = lang_get_parser_stanza(L);
  for (auto decl : *parser->decls_) {
    if (decl->is_Prop()) {
      for (auto prop : *decl->as_Prop()->props_) {
        if (prop->is_LRSpec()) {
          auto prop_k =
              string_to_int(prop->as_LRSpec()->k_.to_std_string()).as_some();
          AR_ge(prop_k, 0);
          ret = prop_k;
        }
      }
    }
  }
  if (ret == -1) {
    ret = 1;
  }
  AT(ret >= 0);
  return ret;
}

inline Ident_T parse_expr_id_to_ident(meta::Node::Id_T id) {
  auto ret_names = make_rc<Vec<IdentBase_T>>();
  for (const auto &name : *id->names_) {
    ret_names->push_back(IdentBase::User::make(name.to_std_string()));
  }
  return Ident::make(ret_names);
}

inline Option_T<std::vector<Ch>>
string_extract_lang_char_seq(std::string s_raw) {
  AT(s_raw.length() >= 2);
  AT(s_raw[0] == '`');
  AT(s_raw[s_raw.length() - 1] == '`');
  std::string s = s_raw.substr(1, s_raw.length() - 2);
  auto sc_maybe = utf8_decode(s);
  if (sc_maybe.is_none()) {
    return None<std::vector<Ch>>();
  }
  auto sc = sc_maybe.as_some();

  Int i = 0;
  std::vector<Ch> ret;
  while (i < sc.size()) {
    if (sc[i] == '\\') {
      if (i + 1 >= sc.size()) {
        return None<std::vector<Ch>>();
      }
      if (sc[i + 1] == 'x') {
        if (i + 3 >= sc.size()) {
          return None<std::vector<Ch>>();
        }
        std::string sc_code;
        sc_code += sc[i + 2];
        sc_code += sc[i + 3];
        auto sc_val = hex_byte_to_u8(sc_code);
        ret.push_back(static_cast<Ch>(sc_val));
        i += 4;
      } else {
        if (sc[i + 1] == 'n') {
          ret.push_back('\n');
        } else if (sc[i + 1] == 'r') {
          ret.push_back('\r');
        } else if (sc[i + 1] == 't') {
          ret.push_back('\t');
        } else if (sc[i + 1] == 'f') {
          ret.push_back('\f');
        } else if (sc[i + 1] == '\\') {
          ret.push_back('\\');
        } else if (sc[i + 1] == '`') {
          ret.push_back('`');
        } else {
          return None<std::vector<Ch>>();
        }
        i += 2;
      }
    } else {
      ret.push_back(sc[i]);
      i += 1;
    }
  }
  return Some<std::vector<Ch>>(ret);
}

inline bool lexer_instr_has_emit_match(meta::Node::LexerInstr_T instr) {
  if (instr->is_Emit()) {
    if (instr->as_Emit()->arg_.is_none()) {
      return true;
    } else {
      return false;
    }
  } else if (instr->is_Pass() || instr->is_Push() || instr->is_Pop() ||
             instr->is_PopExtract() || instr->is_PopEmit()) {
    return false;
  } else if (instr->is_MatchHistory()) {
    auto ic = instr->as_MatchHistory();
    for (auto case_ : *ic->cases_) {
      for (const auto &instr_sub : *case_->instrs_) {
        if (lexer_instr_has_emit_match(instr_sub)) {
          return true;
        }
      }
    }
    return false;
  } else {
    AX();
  }
}

inline bool
lexer_instrs_has_emit_match(Vec_T<meta::Node::LexerInstr_T> instrs) {
  for (const auto &instr : *instrs) {
    if (lexer_instr_has_emit_match(instr)) {
      return true;
    }
  }
  return false;
}

inline Option_T<ParseExpr_Base_T> parse_expr_to_base_maybe(ParseExpr_T e) {
  if (e->is_Id()) {
    auto cc = e->as_Id();
    auto id = parse_expr_id_to_ident(cc->id__);
    auto ret = TokenBase::Id::make(id, false);
    return Some(ParseExpr_Base::make(ret, Some<ParseExpr_T>(e)));

  } else if (e->is_StrLit()) {
    auto cc = e->as_StrLit();
    auto cs = string_extract_lang_char_seq(cc->s_.to_std_string());
    if (cs.is_none()) {
      // utf8 decode error
      AX();
    }
    auto cs_v = make_rc<Vec<Ch>>();
    for (auto c : cs.as_some()) {
      cs_v->push_back(c);
    }
    auto ret = TokenBase::LitStr::make(cs_v);
    return Some(ParseExpr_Base::make(ret, Some<ParseExpr_T>(e)));

  } else if (e->is_CharRange()) {
    auto cc = e->as_CharRange();
    auto x_min_cs = string_extract_lang_char_seq(cc->min__.to_std_string());
    auto x_max_cs = string_extract_lang_char_seq(cc->max__.to_std_string());
    if (x_min_cs.is_none() || x_max_cs.is_none()) {
      AX("Bad char sequence in CharRange");
    }
    if (x_min_cs.as_some().size() != 1 || x_max_cs.as_some().size() != 1) {
      AX("Multi-char sequence in CharRange");
    }
    auto x_min = x_min_cs.as_some()[0];
    auto x_max = x_max_cs.as_some()[0];
    auto ret = TokenBase::LitCharRange::make(x_min, x_max);
    return Some(ParseExpr_Base::make(ret, Some<ParseExpr_T>(e)));

  } else if (e->is_UnicodeAny() || e->is_AsciiBaseAny()) {
    return None<ParseExpr_Base_T>();

  } else if (e->is_Alt() || e->is_AltExplicit()) {
    return None<ParseExpr_Base_T>();

  } else if (e->is_Optional()) {
    return None<ParseExpr_Base_T>();

  } else if (e->is_Rep()) {
    return None<ParseExpr_Base_T>();

  } else if (e->is_RepCount()) {
    return None<ParseExpr_Base_T>();

  } else if (e->is_RepNonzero()) {
    return None<ParseExpr_Base_T>();

  } else if (e->is_List()) {
    return None<ParseExpr_Base_T>();

  } else if (e->is_Eof()) {
    auto ret = TokenBase::LitEof::make();
    return Some(ParseExpr_Base::make(ret, Some<ParseExpr_T>(e)));

  } else if (e->is_False()) {
    return None<ParseExpr_Base_T>();

  } else if (e->is_Underscore()) {
    return None<ParseExpr_Base_T>();

  } else if (e->is_Concat()) {
    return None<ParseExpr_Base_T>();

  } else if (e->is_Paren()) {
    return None<ParseExpr_Base_T>();

  } else if (e->is_Pass()) {
    return None<ParseExpr_Base_T>();

  } else if (e->is_Indent()) {
    auto ret = TokenBase::Special::make(TokenBaseSpecial::Indent);
    return Some(ParseExpr_Base::make(ret, Some<ParseExpr_T>(e)));

  } else if (e->is_Dedent()) {
    auto ret = TokenBase::Special::make(TokenBaseSpecial::Dedent);
    return Some(ParseExpr_Base::make(ret, Some<ParseExpr_T>(e)));

  } else if (e->is_Newline()) {
    auto ret = TokenBase::Special::make(TokenBaseSpecial::Newline);
    return Some(ParseExpr_Base::make(ret, Some<ParseExpr_T>(e)));

  } else if (e->is_Minus()) {
    return None<ParseExpr_Base_T>();

  } else {
    LG_ERR("{}", e);
    AX();
  }
}

inline meta::Node::ParseExpr_T
xform_parse_expr_freshen_rec(meta::Node::ParseExpr_T e, Gensym_T gen,
                             TokenBounds bounds) {

  meta::Node::ParseExpr_T ret;

  if (e->is_Unfold()) {
    auto cc = e->as_Unfold();
    ret = meta::Node::ParseExpr::Unfold::make(
        gen->gen(), bounds, e->is_top_, e->sym_, e->attr_, e->first_k_,
        xform_parse_expr_freshen_rec(cc->e_, gen, bounds));

  } else if (e->is_Name()) {
    auto cc = e->as_Name();
    ret = meta::Node::ParseExpr::Name::make(
        gen->gen(), bounds, e->is_top_, e->sym_, e->attr_, e->first_k_,
        cc->name_, xform_parse_expr_freshen_rec(cc->e_, gen, bounds));

  } else if (e->is_AttrReq()) {
    auto cc = e->as_AttrReq();
    ret = meta::Node::ParseExpr::AttrReq::make(
        gen->gen(), bounds, e->is_top_, e->sym_, e->attr_, e->first_k_,
        xform_parse_expr_freshen_rec(cc->e_, gen, bounds), cc->attrs_);

  } else if (e->is_Id()) {
    auto cc = e->as_Id();
    ret =
        meta::Node::ParseExpr::Id::make(gen->gen(), bounds, e->is_top_, e->sym_,
                                        e->attr_, e->first_k_, cc->id__);

  } else if (e->is_Eps()) {
    ret = meta::Node::ParseExpr::Eps::make(gen->gen(), bounds, e->is_top_,
                                           e->sym_, e->attr_, e->first_k_);

  } else if (e->is_Pass()) {
    auto cc = e->as_Pass();
    ret = meta::Node::ParseExpr::Pass::make(
        gen->gen(), bounds, e->is_top_, e->sym_, e->attr_, e->first_k_, cc->s_);

  } else if (e->is_Underscore()) {
    ret = meta::Node::ParseExpr::Underscore::make(
        gen->gen(), bounds, e->is_top_, e->sym_, e->attr_, e->first_k_);

  } else if (e->is_Indent()) {
    ret = meta::Node::ParseExpr::Indent::make(gen->gen(), bounds, e->is_top_,
                                              e->sym_, e->attr_, e->first_k_);

  } else if (e->is_Dedent()) {
    ret = meta::Node::ParseExpr::Dedent::make(gen->gen(), bounds, e->is_top_,
                                              e->sym_, e->attr_, e->first_k_);

  } else if (e->is_Newline()) {
    ret = meta::Node::ParseExpr::Newline::make(gen->gen(), bounds, e->is_top_,
                                               e->sym_, e->attr_, e->first_k_);

  } else if (e->is_AltExplicit()) {
    auto cc = e->as_AltExplicit();
    ret = meta::Node::ParseExpr::AltExplicit::make(
        gen->gen(), bounds, e->is_top_, e->sym_, e->attr_, e->first_k_,
        xform_parse_expr_freshen_rec(cc->e_, gen, bounds));

  } else if (e->is_Alt()) {
    auto cc = e->as_Alt();
    auto xs_new = make_rc<Vec<meta::Node::ParseExpr_T>>();
    for (const auto &x : *cc->xs_) {
      xs_new->push_back(xform_parse_expr_freshen_rec(x, gen, bounds));
    }
    ret = meta::Node::ParseExpr::Alt::make(
        gen->gen(), bounds, e->is_top_, e->sym_, e->attr_, e->first_k_, xs_new);

  } else if (e->is_Concat()) {
    auto cc = e->as_Concat();
    auto xs_new = make_rc<Vec<meta::Node::ParseExpr_T>>();
    for (const auto &x : *cc->xs_) {
      xs_new->push_back(xform_parse_expr_freshen_rec(x, gen, bounds));
    }
    ret = meta::Node::ParseExpr::Concat::make(
        gen->gen(), bounds, e->is_top_, e->sym_, e->attr_, e->first_k_, xs_new);

  } else if (e->is_Optional()) {
    auto cc = e->as_Optional();
    ret = meta::Node::ParseExpr::Optional::make(
        gen->gen(), bounds, e->is_top_, e->sym_, e->attr_, e->first_k_,
        xform_parse_expr_freshen_rec(cc->x_, gen, bounds));

  } else if (e->is_List()) {
    auto cc = e->as_List();
    ret = meta::Node::ParseExpr::List::make(
        gen->gen(), bounds, e->is_top_, e->sym_, e->attr_, e->first_k_, cc->ty_,
        xform_parse_expr_freshen_rec(cc->elem_, gen, bounds), cc->num_,
        xform_parse_expr_freshen_rec(cc->delim_, gen, bounds), cc->end_delim_);

  } else if (e->is_Rep()) {
    auto cc = e->as_Rep();
    ret = meta::Node::ParseExpr::Rep::make(
        gen->gen(), bounds, e->is_top_, e->sym_, e->attr_, e->first_k_,
        xform_parse_expr_freshen_rec(cc->x_, gen, bounds));

  } else if (e->is_RepNonzero()) {
    auto cc = e->as_RepNonzero();
    ret = meta::Node::ParseExpr::RepNonzero::make(
        gen->gen(), bounds, e->is_top_, e->sym_, e->attr_, e->first_k_,
        xform_parse_expr_freshen_rec(cc->x_, gen, bounds));

  } else if (e->is_Paren()) {
    auto cc = e->as_Paren();
    ret = meta::Node::ParseExpr::Paren::make(
        gen->gen(), bounds, e->is_top_, e->sym_, e->attr_, e->first_k_,
        xform_parse_expr_freshen_rec(cc->x_, gen, bounds));

  } else if (e->is_StrLit()) {
    auto cc = e->as_StrLit();
    ret = meta::Node::ParseExpr::StrLit::make(
        gen->gen(), bounds, e->is_top_, e->sym_, e->attr_, e->first_k_, cc->s_);

  } else {
    LG_ERR("{}", e);
    AX();
  }

  return ret;
}

inline Option_T<std::string>
parse_expr_extract_write_phase_const_ext(ParseExpr_T e) {
  if (e->is_StrLit()) {
    auto cs = string_extract_lang_char_seq(e->as_StrLit()->s_.to_std_string())
                  .as_some();
    std::string ret = "";
    for (auto c : cs) {
      ret += utf8_encode(c);
    }
    return Some<std::string>(ret);

  } else if (e->is_Pass()) {
    auto cs = string_extract_lang_char_seq(e->as_Pass()->s_.to_std_string())
                  .as_some();
    std::string ret = "";
    for (auto c : cs) {
      ret += utf8_encode(c);
    }
    return Some<std::string>(ret);

  } else if (e->is_Underscore()) {
    return Some<std::string>(" ");

  } else if (e->is_Eps()) {
    return Some<std::string>("");

  } else if (e->is_Concat()) {
    std::string ret = "";
    for (const auto &x : *e->as_Concat()->xs_) {
      auto rx = parse_expr_extract_write_phase_const_ext(x);
      if (rx.is_none()) {
        return None<std::string>();
      } else {
        ret += rx.as_some();
      }
    }
    return Some<std::string>(ret);

  } else if (e->is_Paren()) {
    return parse_expr_extract_write_phase_const_ext(e->as_Paren()->x_);

  } else if (e->is_Name()) {
    return parse_expr_extract_write_phase_const_ext(e->as_Name()->e_);

  } else if (e->is_Indent() || e->is_Dedent() || e->is_Newline()) {
    return None<std::string>();

  } else {
    return None<std::string>();
  }
}

inline std::string parse_expr_extract_write_phase_const(ParseExpr_T e) {
  auto ret = parse_expr_extract_write_phase_const_ext(e);
  if (ret.is_none()) {
    LG_ERR("parse_expr_extract_write_phase_const: {}", e);
    AX();
  }
  return ret.as_some();
}

inline bool parse_expr_is_parse_phase_const(ParseExpr_T e) {
  if (e->is_StrLit() || e->is_Pass() || e->is_Underscore() || e->is_Eps() ||
      e->is_Newline() || e->is_Indent() || e->is_Dedent()) {

    return true;
  } else if (e->is_Concat()) {
    for (const auto &x : *e->as_Concat()->xs_) {
      if (!parse_expr_is_parse_phase_const(x)) {
        return false;
      }
    }
    return true;
  } else if (e->is_Id() || e->is_Alt() || e->is_List() || e->is_Rep() ||
             e->is_RepNonzero() || e->is_Optional()) {
    return false;
  } else if (e->is_Paren()) {
    return parse_expr_is_parse_phase_const(e->as_Paren()->x_);
  } else {
    LG_ERR("parse_expr_is_parse_phase_const: {}", e);
    AX();
  }
}

inline bool parse_expr_is_parse_phase_empty_base(ParseExpr_T e) {
  if (e->is_Pass() || e->is_Underscore()) {
    return true;
  } else if (e->is_Indent() || e->is_Dedent() || e->is_Newline()) {
    return false;
  } else {
    auto ret = parse_expr_extract_write_phase_const_ext(e);
    if (ret.is_some()) {
      if (ret.as_some().length() == 0) {
        return true;
      }
    }
    return false;
  }
}

inline Option_T<AttrLeaf_T> attr_leaf_lift_expr(Option_T<ParseExpr_T> e) {
  if (e.is_none()) {
    return None<AttrLeaf_T>();
  }
  return Some<AttrLeaf_T>(AttrLeaf::Id::make(e.as_some(), e.as_some()->id_));
}

namespace ParseExprProps {
struct _T {
  Option_T<Vec_T<meta::Node::AttrReq_T>> attr_req_;
  Option_T<IdentBase_T> name_;
  bool unfold_;

  inline _T() {
    attr_req_ = None<Vec_T<meta::Node::AttrReq_T>>();
    name_ = None<IdentBase_T>();
    unfold_ = false;
  }
};

inline rc_ptr<_T> empty() { return make_rc<_T>(); }
} // namespace ParseExprProps

using ParseExprProps_T = rc_ptr<ParseExprProps::_T>;
using ParseExprPropsMap_T = Map_T<Int, ParseExprProps_T>; // By gen_id

} // namespace langcc
