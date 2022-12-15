# ``langcc``: A Next-Generation Compiler Compiler

``langcc`` can serve as a replacement for
[lex](https://en.wikipedia.org/wiki/Lex_(software))+[yacc](https://en.wikipedia.org/wiki/Yacc), but is much more powerful. ``langcc`` enables a completely new paradigm for developing programming languages based on iteratively improving the intuitive declarative specification of your language instead of laboriously updating your hand-written compiler frontend for every grammar change.

- ``langcc`` generates efficient, linear-time parsers for an extremely broad class of grammars (a strict superset of
canonical LR). In particular, the project includes complete specifications of Python 3.9.12 
([grammars/py.lang](https://github.com/jzimmerman/langcc/blob/main/grammars/py.lang))
and Golang 1.17.8 ([grammars/go.lang](https://github.com/jzimmerman/langcc/blob/main/grammars/go.lang)),
and generates parsers for each language that are faster than their respective standard parsers (resp.,
1.2x and 4.3x faster).
- ``langcc`` requires only a single input file in its declarative ``.lang`` format to generate a full
compiler frontend, including AST struct definitions and associated traversals, hashing, pretty-printing,
and automatic integration with the generated parser (no need to sprinkle C++ code into your grammar as in lex+yacc).
- ``langcc`` provides a built-in "conflict tracing" algorithm which traces LR conflicts back to
"confusing input pairs", which provide explicit example strings instead of opaque shift/reduce conflicts.
- ``langcc`` extends the existing LR paradigm to include both recursive-descent parsing actions (which result in 
much smaller and more intuitive automata) and also per-symbol attribute constraints (which provide support for
many industrial language constructs).
- ``langcc`` implements a novel transformation for LR grammars we call "continuation-passing style", which
significantly expands the class of grammars the tool supports.
- Finally, ``langcc`` ships with a standalone _datatype compiler_ called ``datacc``, which
generates full C++ implementations of algebraic datatypes (including sum types) from a simple declarative
language whose spec is provided in 
[data.lang](https://github.com/jzimmerman/langcc/blob/main/grammars/data.lang).


``langcc`` is _self-hosting_. The file
[grammars/meta.lang](https://github.com/jzimmerman/langcc/blob/main/grammars/meta.lang) contains the
specification for the "language of languages" in which ``langcc`` expects ``.lang`` files to be written.
In this canonical implementation, the file
[bootstrap.sh](https://github.com/jzimmerman/langcc/blob/main/bootstrap.sh) uses ``langcc`` to
generate its own compiler front-end.

``langcc`` is stable and feature-complete. It is ready to be used as a research prototype to facilitate
rapid exploration of new compilers and programming languages. It is free and open-source and available under
the Apache 2.0 License.

``langcc`` is also described in the following companion technical reports, which provide the theoretical basis for
its functionality.
- Zimmerman, Joe.
[Practical LR Parser Generation.](https://arxiv.org/pdf/2209.08383.pdf)
arXiv, 2022.
- Zimmerman, Joe.
[langcc: A Next-Generation Compiler Compiler.](https://arxiv.org/pdf/2209.08385.pdf)
arXiv, 2022.

## Usage

### langcc

`langcc` is a standalone command-line tool,
which can be invoked as follows:

```
langcc [options] X.lang gen_path
```

to compile a BNF-style language specification (`X.lang`)
to a generated compiler front-end for that language (`gen_path/X__gen.hpp`, `gen_path/X__gen.cpp`).
The tool automatically generates data structures for the abstract syntax (AST),
a lexer, a parser, and a pretty-printer for terms in the language.
In order to use the generated code, simply include the file `gen_path/X__gen.hpp`
and compile and link against the file `gen_path/X__gen.cpp`.

The following are valid command-line options for `langcc`:
- `-h`: Generate a header-only implementation, instead of the usual (`.hpp`, `.cpp` pair).
- `-q`: Quiet mode.
- `-v`: Verbose level 1 (the default).
- `-vv`: Verbose level 2.
- `-vvv`: Verbose level 3.
- `-vvvv`: Verbose level 4.

`langcc` outputs code intended to be compiled with `clang++` using the C++'17 standard,
and the generated parsers accept input encoded in UTF-8.

### datacc

`datacc` is an internal component which `langcc` uses to generate many of its
data structures, but which can also be used as a standalone command-line tool.
It can be invoked as follows:

```
datacc [options] X.data gen_path
```

to compile a declarative specification of some algebraic datatypes (`X.data`)
to generated C++ code that implements those datatypes
(`gen_path/X__data_gen.hpp`, `gen_path/X__data_gen.cpp`).
`datacc` supports named product and sum types (with enums as a special case),
as well as datatypes with type parameters.
The generated code includes the (reference-counted) C++ implementations
of the corresponding algebraic datatypes as structs with inheritance,
as well as a number of other features: e.g.,
functions for testing and downcasting sum types,
functions for substituting fields of product types,
functions for debug-printing elements of each datatype,
and functions for cached value-based SHA-256 hashing of elements of each datatype.

The following are valid command-line options for `datacc`:
- `-h`: Generate a header-only implementation, instead of the usual (`.hpp`, `.cpp` pair).

## Input language

The input to `langcc` is a file `X.lang`,
written in the "language of languages"
([grammars/meta.lang](https://github.com/jzimmerman/langcc/blob/main/grammars/meta.lang)).
Such an input consists of several _stanzas_, as follows.

### `tokens` stanza

The `tokens` stanza describes the basic tokens that are to be
emitted by the lexer.
A token description is either an _opaque_ declaration `X <- e`
or an _alias_ declaration `X <= e`,
where `e` in either case is (roughly) a regular expression.
For instance, one can write:

```
int_lit <- `0` | (`1`..`9`) digit*;
digit <= `0`..`9`;
op <= `+` | `-` | `*` | `/`;
```

Backtick-quoted strings are used to represent
literal sequences of characters that appear in the tokens.
Expressions can be parenthesized,
and many standard regex operators
(e.g., concatenation, alternation, repetition,
parenthesization, character ranges)
are permitted.
Standard escapes such as `\n` and `\\`
are valid within backtick-quoted strings,
and the backtick itself can be escaped via `` \` ``;
however, single and double quotes do not need to be escaped.

Note that in the example above, `digit` is an alias,
and thus can be used in the definition of `int_lit`.
However, `int_lit`, as an opaque declaration,
cannot be used in the definition of other items in the lexer -- as opposed to the parser,
which does permit recursive structure.
The other key difference between alias and opaque token declarations
is that opaque tokens will be emitted as such by the lexer,
and can appear directly in parser expressions
(e.g., `Expr.Int <- n:int_lit`);
while if aliased tokens are emitted by the lexer,
then the item that is actually emitted is the underlying opaque token expression
(e.g., in the parser, below, we could write
``Expr.Add <- x:Expr `+` y:Expr``, but we could not write
``Expr.Binop <- x:Expr op y:Expr``, as `op` is not an
opaque token emitted by the lexer).

### `lexer` stanza

The `lexer` stanza describes the procedural operation of the lexer
as it processes an input string to emit tokens.
The lexer stanza consists of one or more _lexer modes_,
as well as a _main mode_ declaration.
For instance, the following is a lexer stanza:

```
lexer {
    main { body }

    mode body {
        top => { emit; }
        ws_inline => { pass; }
        `\n` => { pass; }
        `//` => { push comment_single; pass; }
        eof => { pop; }
    }

    mode comment_single {
        `\n` => { pop_extract; }
        eof => { pop_extract; }
        _ => { pass; }
    }
}
```

Here, the tokens `eof` and `\n` are built-in;
the underscore `_` is a wildcard matching an arbitrary unicode
code point;
and we assume that the aliases `top`, `ws_inline`
have been defined in the `tokens` section.
The main mode is the one called `body`,
and in this mode:

- If the lexer encounters a toplevel token
  (i.e., a character sequence matching one of
  the opaque constituents of the alias `top`),
  then it will emit that constituent, and proceed.

- If the lexer encounters inline whitespace,
  then it will pass over it and proceed.

- If the lexer encounters the newline character,
  then it will pass over it and proceed.

- If the lexer encounters the comment start sequence `//`,
  then it will push the mode `comment_single`
  onto its mode stack,
  pass over the `//`,
  and continue processing in the new mode.
  Note that the ordering of the two commands is significant.
  The second command, `pass`,
  means that the matched string `//`
  will be processed _after_ the lexer is already in the new mode
  `comment_single`.

- If the lexer encounters the end-of-file marker (`eof`),
  then it will pop the main mode off the stack.
  Note that if at any point, the mode stack is empty,
  then the lexer halts;
  and it declares success if and only if this happens at the end of the input -- if
  the mode stack is empty prematurely, this is a failure.
  Conversely, if the mode stack is nonempty at end-of-file,
  this is also a lexing failure.

while, in the mode `comment_single`:

- If the lexer encounters either a newline or the end-of-file marker,
  it will extract all of the characters that have been processed
  in the current mode (including those that have been passed over),
  attach the result as extra data (not part of the AST),
  and pop the current mode off of the mode stack.

- If the lexer encounters any other character,
  it will pass over it, and proceed.

Note that there are two possible types of pop commands:

- `pop_extract`, which is used above.
  This will extract the characters processed in the current mode,
  and attach the result as extra data (not part of the AST).

- `pop_emit tok`, where `tok` names an opaque token.
  This will extract the characters processed in the current mode,
  and emit an instance of the token `tok` (to be consumed by the parser),
  where the included string contents of `tok` are the extracted characters.

The generated lexer is implemented via the standard NFA/DFA subset construction,
and it will accept the _longest_ matching substring
starting at the current point in the input
(in other words, it will only consider performing an action if the subsequent character
would lead to a DFA state with no action).
By construction of the DFA, the action of a compiled lexer is always uniquely determined.
While some lexer/token definitions may lead to ambiguity,
this can be detected statically in the subset construction,
and this will generate an error during `langcc`'s compilation of `X.lang`
rather than producing an ambiguity at lexing time.

### `parser` stanza

The `parser` stanza describes the context-free grammar which should be used
by the generated parser,
defined in terms of the basic lexer tokens.
For instance, the following is a parser stanza:

```
parser {
    main { Stmt, Expr }

    prec {
        Expr.BinOp1 assoc_left;
        Expr.BinOp2 assoc_left;
        Expr.UnaryPre prefix;
        Expr.BinOp3 assoc_left;
        Expr.Id Expr.Lit.Int_ Expr.Paren;
    }

    prop { name_strict; }

    Stmt.Assign <- x:Expr[I] _ `=` _ y:Expr;
    Stmt.Expr <- x:Expr;

    Expr.Id[I] <- name:id;
    Expr.Lit.Int_ <- val:int_lit;
    Expr.UnaryPre <- op:#Alt[Neg:`-`] x:Expr;
    Expr.BinOp1 <- x:Expr _ op:(Add:`+` | Sub:`-`) _ y:Expr;
    Expr.BinOp2 <- x:Expr _ op:(Mul:`*` | Div:`/`) _ y:Expr;
    Expr.BinOp3 <- x:Expr op:#Alt[Pow:`^`] y:Expr;
    Expr.Paren <- `(` x:Expr[pr=*] `)`;
}
```

In addition to supplementary directives (e.g.,
`main`, `prec`, `prop`),
the parser stanza consists of a series of declarative, BNF-style _rules_
of the form `X <- e`,
where `X` is the name of the rule (possibly consisting of multiple components,
with dots), and `e` is the definition of the rule.
Note that rules of the form `X.A`, `X.B`, and `X.C.D`
all indicate the same nonterminal `X` for the left-hand side
of the resulting context-free grammar rules,
but in the generated ASTs, `X::A`, `X::B`, and `X::C::D`
will be subclasses of the sum type `X`.

We mention a number of additional features of the parser stanza:

- The `main` sub-stanza indicates a set of nonterminals
  that can be parsed at the top level,
  i.e., for which we can call `parse`
  in the generated API.
  Of these, the first one listed is the default
  if no nonterminal is specified at parsing time.

- The `prec` sub-stanza indicates a series of _precedence levels_
  for the rules.
  The details of precedence are detailed more fully in the original
  report [[Zim22, Sections 1.4, 3.5]](https://arxiv.org/pdf/2209.08383.pdf).
  Note that unlike tools such as `yacc`,
  our precedence spec operates at the level of _rules_,
  rather than at the level of operators.
  Concretely, it is implemented in terms of attribute constraints
  [[Zim22, Section 3.5]](https://arxiv.org/pdf/2209.08383.pdf).
  We also note that the subexpression `Expr[pr=*]` in the `Expr.Paren`
  rule indicates an expression of arbitrary precedence,
  overriding what would otherwise be a highest-precedence constraint.

- The `prop` sub-stanza determines the configuration of `langcc`
  when processing the language definition.
  In particular, `prop { name_strict; }`
  indicates that every subexpression that corresponds to a field or a sum case
  in the AST must have a name (e.g., in `x:Expr`, `x` is the name).
  Without the `name_strict` annotation,
  fields may be unnamed,
  which will cause `langcc` to automatically generate names
  in the resulting AST -- this is still valid,
  but makes it more difficult to write code against the generated API.

- The annotation `[I]` on `Expr.Id[I]` and `x:Expr[I]`
  indicates a boolean-valued _attribute_ named `I` [[Zim22, Sections 1.4, 3.5]](https://arxiv.org/pdf/2209.08383.pdf).
  Specifically, this means that only `Expr` instances arising from the `Expr.Id`
  rule will have the attribute `I`,
  and conversely, in the `Stmt.Assign` rule,
  only `Expr` nonterminals which bear this attribute are valid
  at the indicated point in the right-hand side.
  Attributes can also be constrained via a standalone `attr` sub-stanza,
  similar to the `prec` sub-stanza
  (see [grammars/go.lang](https://github.com/jzimmerman/langcc/blob/main/grammars/go.lang)
  for examples).
  When attributes are specified inline, however (as in the example above),
  we adopt the general convention that an attribute mentioned
  in the right-hand side of a rule is a requirement,
  and an attribute mentioned in the left-hand side
  is a declaration that the attribute is satisfied.
  Further details can be found in [[Zim22, Section 3.5]](https://arxiv.org/pdf/2209.08383.pdf).
    
- Many other features are available in parser BNF expressions, e.g.:

  - A literal string may be _passed over_ in the parser, written ``@(`contents`)``.
    At parse time, this subexpression is ignored,
    but at pretty-print time, the contents of the string are inserted.
    This is often used for formatting strings such as ``@(` `)`` (a space)
    or ``@(`\n`)`` (a newline);
    in fact, the former is so common that we have the special notation `_`
    (as used in the example above) to denote ``@(` `)``.
  
  - The special expression `eps` may be used to denote the empty concatenation.
  
  - The special expression `#Alt[e]` may be used to denote
    the singleton alternation. To the parser, this is equivalent to the
    expression `e`,
    but it may be important semantically for the generated AST.
  
  - The expression `e*` may be used to denote a repeated expression `e`.
    In the generated AST, this automatically produces a vector.
  
  - The expression `e+` may be used to denote a nonzero-repeated expression `e`.
    In the generated AST, this automatically produces a vector.
  
  - The expression `#L[e::delim]` may be used to denote a list of `e`,
    delimited by `delim`.
    In the generated AST, this automatically produces a vector.
    In addition, there are several variants of the list expression:
    
    - `#L[e::delim::]`, a list with a trailing delimiter.
    
    - `#L[e::delim:?]`, a list with an optional trailing delimiter.
    
    - `#L[e::+delim]`, a list with at least one element.
    
    - `#L[e::++delim]`, a list with at least two elements.
    
    - `#B[e::delim]`, a list which renders as an indented block in the pretty-printer.
    
    - `#B2[e::delim]`, a list which renders as an indented double-spaced block
      in the pretty-printer.
    
    - `#T[e::delim]`, a list which renders as a top-level block in the pretty-printer.
    
    - `#T2[e::delim]`, a list which renders as a top-level double-spaced block
      in the pretty-printer.

  - The expression `e?` may be used to denote an optional expression `e`;
    in the generated AST, this automatically produces an option type or a boolean,
    as appropriate.
  
  - The expression `~X` may be used to indicate that the nonterminal `X`
    should be _unfolded_, i.e., that its beginning does not need to be predicted
    in recursive-descent style.
    If all nonterminals in the right-hand side are unfolded,
    this results in LR-style parsing (shift/reduce); if no nonterminals are unfolded,
    it results in RD-style parsing (shift/reduce/recur/ret).
    For further details, see [[Zim22, Section 3.6]](https://arxiv.org/pdf/2209.08383.pdf).

### `compile_test` stanza (optional)

The `compile_test` stanza describes a series of compilation tests to be performed when `langcc`
compiles the language.
Compilation tests are of the form `LR(k)` (resp., `!LR(k)`), where `k`
is a nonnegative integer, indicating that LR compilation should succeed (resp., fail due to conflicts)
for the given value of `k`.

### `test` stanza (optional)

The `test` stanza describes a series of parsing tests to be performed when `langcc`
compiles the language.
Parsing tests are of the form `` `abc`; `` (resp., `` `abc##def;` ``),
indicating that parsing should succeed (resp., fail at the position indicated by `##`)
on the given string.
In addition, by default, parsing tests will verify that the pretty-printer outputs the same
string as was parsed.
If this is not desired for a given example, one may append the special marker `<<>>`,
as in `` `contents` <<>>; ``.


## Conflict tracing

The underlying parsing theory [[Zim22]](https://arxiv.org/pdf/2209.08383.pdf)
indicates that if `langcc` successfully compiles a language, then the behavior
of the parser is fully determined -- though it may produce a parse error on strings that are
not in the language,
it will not fail by virtue of ambiguity.
However, not all grammars reach this point; some have _LR conflicts_,
which `langcc` will report if it fails to compile a language for this reason.
When reporting LR conflicts, `langcc` endeavors to produce an exemplar,
a short "confusing input pair", that explains the conflict
in a way that is much more intuitive than the opaque shift/reduce errors produced by
tools such as `yacc`.
Further details of the conflict tracing procedure are described in [[Zim22, Section 3.4]](https://arxiv.org/pdf/2209.08383.pdf);
here we only provide a basic example.
The following is a conflict that arises if we attempt to run `langcc`
on a simple arithmetic expression language, without using the appropriate precedence declarations.

```
===== LR conflict 1 of 2

            &Expr                           &Expr    
                                  RecurStep(Expr)    
             Expr                              id    
   X0=(`+` | `-`)                             `+`    
             Expr                              id    
                                                     
                     Reduce(Expr -> Expr X0 Expr)    Shift
                                                     
                                              `+`    `+`
                                               id    id    
```

On the left side, we see the expression that produced the conflicting prefix
(`Expr X0 Expr`),
and on the right side, a concrete input that might correspond to this expression
(``id `+` id``).
Below this are the two conflicting actions, (1) `Reduce` by the indicated production
`Expr -> Expr X0 Expr`
and (2) `Shift` the next token.
Finally, there is a completion of the "confusing input pair",
showing that either action is possible with the given `k = 1` lookahead (`` `+` ``).
In this example, the grammar is actually ambiguous;
one cannot decide whether to parse `id+id+id` as `(id+id)+id` or as `id+(id+id)`.
However, a grammar need not be ambiguous in order to present LR conflicts -- in general,
all that is required is that the parser is unable to determine what LR action to take
with `k` tokens of lookahead.


## Output API

When a language `X.lang` is successfully compiled, `langcc` outputs
files `gen_path/X__gen.hpp` and `gen_path/X__gen.cpp`,
which contain the AST definitions, lexer, parser,
and pretty-printer, as well as miscellaneous utilities such as debug-printers and hashing functions.
The following is a basic example of how to use the generated API (from `examples/calc`):

```cpp
auto L = lang::calc::init();
auto Q = L->quote_env();
unordered_map<string, Int> env;
string l;

while (true) {
    getline(cin, l);
    if (!cin.good()) {
        return 0;
    }

    auto gen = make_rc<Gensym>();
    auto parse = L->parse_ext(
        vec_from_std_string(l), None<string>(), gen, nullptr);

    if (!parse->is_success()) {
        LG_ERR("\nParse error: {}\n", parse->err_.as_some());
        continue;
    }

    auto stmt = parse->res_.as_some()->as_Stmt();
    try {
        fmt(cerr, "{}\n", stmt_eval(stmt, env));
    } catch (const CalcError& err) {
        LG_ERR("\nError: {}\n{}",
            err.desc_,
            parse->lex_->location_fmt_str(err.e_blame_->bounds_));
        continue;
    }
}
```

Note that the generated parsing procedure returns a structure `parse`,
and if `!parse->is_success()`,
then `parse->err_` contains the parse error;
when formatted,
it can be printed in user-readable form, resulting in a message like the following:

```
Parse error: Unexpected token: `/`
Line 1, column 10:

  7 + (5 + / 3)
           ^   
```

If, on the other hand, parsing succeeds, then the resulting AST element
is given by `parse->res_`.
By default, it is a generic `lang::calc::Node_T` (a sum type),
but in this case, the toplevel parse is known to be a `Stmt`,
and we downcast it with `as_Stmt()`,
then call our function `stmt_eval`, which in turn calls `expr_eval`
on constituent expressions.
The following is excerpted from `expr_eval`:

```cpp
Int expr_eval(Expr_T e, const unordered_map<string, Int>& env) {
    if (e->is_Lit()) {
        auto val_str = e->as_Lit()->as_Int_()->val_.to_std_string();
        return string_to_int(val_str).as_some();
    // ...
    } else if (e->is_BinOp2()) {
        auto cc = e->as_BinOp2();
        auto xr = expr_eval(cc->x_, env);
        auto yr = expr_eval(cc->y_, env);
        if (cc->op_->is_Mul()) {
            return xr * yr;
        } else if (cc->op_->is_Div()) {
            if (yr == 0) {
                throw CalcError(fmt_str("Division by zero"), cc->op_);
            }
            return xr / yr;
        } else {
            AX();
        }
    // ...
```

As this example shows, it is straightforward to decompose the AST sum types
to obtain the values enclosed.
We mention one additional feature: note that in the case of division by zero,
we throw an error that includes the syntax element `cc->op_`.
In fact, this syntax element carries with it its position in the input,
which enables us to produce, at top level, error messages of the following form:

```
Error: Division by zero
Line 1, column 3:

  4 / (3 - (15 / 5))
    ^                
```

indicating precisely which division triggered the error.
Evidently, this functionality easily generalizes to source-position error reporting
in more complex languages.


## Bootstrapping

We finally mention one additional property of `langcc`: the class of grammars
is general enough that the tool is _self-hosting_ -- that is, one can express the "language
of languages" in the "language of languages" itself, and use `langcc`
to generate its own compiler front-end. In fact, we do this in the canonical
implementation; see the files [bootstrap.sh](https://github.com/jzimmerman/langcc/blob/main/bootstrap.sh)
and [grammars/meta.lang](https://github.com/jzimmerman/langcc/blob/main/grammars/meta.lang)
for more details.
The metalanguage is surprisingly concise, requiring only 192 lines of code.
The following is a brief excerpt:

```
    ParseExpr.Pass <- `@` `(` s:str_lit `)`;
    ParseExpr.Paren <- `(` x:ParseExpr[pr=*] `)`;
    ParseExpr.Name <- name:IdBase `:` e:ParseExpr;
    ParseExpr.List <- ty:~ParseExprListType
        `[`
        elem:ParseExpr[pr=*]
        num:ParseExprListNum
        delim:ParseExpr[pr=*]
        end_delim:(NONE:eps | OPTIONAL:`:?` | SOME:`::`)
        `]`;
    ParseExpr.Unfold <- `~` e:ParseExpr;
    ParseExpr.AttrReq <- e:ParseExpr `[` attrs:#L[AttrReq::`,`_] `]`;

        AttrReq.Base <- k:IdBase;
        AttrReq.PrecStar <- `pr` `=` `*`;

        ParseExprListType.List <- `#L`;
        ParseExprListType.Block <- `#B`;
        // ...
```

We note that the syntax is very compact,
and corresponds to little more than one would write on the whiteboard for an informal BNF grammar.

## Detailed Examples

### Lox

(Note: This section is under active construction.) The Lox scripting language was designed by Robert Nystrom at
[Crafting Interpreters](https://craftinginterpreters.com/). The example in ``examples/lox`` is a complete
implementation of an interpreter for Lox using ``langcc``, and is the recommended way for new users to
learn about ``langcc``'s feature set.

### ``lox.lang``

This file contains the specification for the Lox grammar.

### ``lox.data`` and ``lox_error.data``

These files contains specifications for several algebraic datatypes that our Lox interpreter uses, including
environments, several enumerations, and runtime errors.

### ``lox_val.hpp``

This file (along with its forward declarations in ``lox_val_fwd.hpp``, needed in ``lox.lang``) defines
the (performance-optimized) runtime representation we use for Lox values.

### ``lox.cpp``

This file contains the implementation of our Lox interpreter, which matches the behavior of Robert Nystrom's
``jlox`` interpreter in virtually all cases (one notable exception being that we do not currently limit the number of
arguments to a function or method call). Its performance matches or exceeds ``jlox``'s on all of the provided Lox
benchmarks.

This section will soon be greatly expanded to include commentary on the various approaches and features used to
accomplish this.

### ``lox.hpp`` and ``lox_test_main.cpp``

These files are used by the Lox test harness.