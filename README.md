# ``langcc``: A Next-Generation Compiler Compiler

``langcc`` can serve as a replacement for
[lex](https://en.wikipedia.org/wiki/Lex_(software))+[yacc](https://en.wikipedia.org/wiki/Yacc), but is much more powerful:
- ``langcc`` generates efficient, linear-time parsers for a much more general class of grammars
  than lex+yacc. Specifically, ``langcc`` implements novel extensions of canonical
  LR parsing (described in the
  [companion technical report](https://arxiv.org/pdf/2209.08383.pdf)
  which we believe encompass virtually all languages that are "easy to parse" for humans.
- Unlike lex+yacc, ``langcc`` is general enough for real industrial languages
  ([Python 3.9.12](https://github.com/jzimmerman/langcc/blob/main/grammars/py.lang),
  [Golang 1.17.8](https://github.com/jzimmerman/langcc/blob/main/grammars/go.lang)),
  and its generated parsers are extremely fast
  (1.2x faster than the standard Golang parser, 4.3x faster than CPython's).
- ``langcc`` generates a full compiler frontend,
  including AST struct definitions and associated traversals,
  hashing, pretty-printing, and automatic integration with the generated parser
  (no need to sprinkle C++ code into your grammar as in lex+yacc).
- ``langcc`` provides a convenient "conflict tracing" algorithm which traces LR
  conflicts back to an explicit "confusing input pair", rather than the opaque
  shift/reduce errors of lex+yacc.
- ``langcc`` also ships with a standalone _datatype compiler_, ``datacc``,
  which generates C++ definitions of algebraic datatypes (including sum types!)
  from a simple declarative spec language
  ([data.lang](https://github.com/jzimmerman/langcc/blob/main/grammars/data.lang)).
- ``langcc`` is _self-hosting_:
  it generates its own compiler frontend from a declarative BNF spec
  of the "language of languages"
  ([meta.lang](https://github.com/jzimmerman/langcc/blob/main/grammars/meta.lang)).

``langcc`` also serves as the software implementation for the following
technical reports, which describe several innovations on the classic
LR parsing paradigm:
- Zimmerman, Joe.
[Practical LR Parser Generation.](https://arxiv.org/pdf/2209.08383.pdf)
arXiv, 2022.
- Zimmerman, Joe.
[langcc: A Next-Generation Compiler Compiler.](https://arxiv.org/pdf/2209.08385.pdf)
arXiv, 2022.

``langcc`` is a research prototype and has not yet been used extensively
in production. However, we believe it is essentially stable and
feature-complete, and can be used as a standalone tool to facilitate
rapid exploration of new compilers and programming languages.

## Build
The build has been tested on Ubuntu 22.04 and macOS 12.5,
but should also run on some other versions of Ubuntu
and macOS with minor adaptations.

![Ubuntu CI](https://github.com/jzimmerman/langcc/actions/workflows/ci-ubuntu.yml/badge.svg?event=push) &nbsp; ![macOS CI](https://github.com/jzimmerman/langcc/actions/workflows/ci-macos.yml/badge.svg?event=push)

For Ubuntu 22.04:
```
./deps_ubuntu.sh
make -j8
sudo make install
```
For macOS 12.5 (requires Homebrew):
```
./deps_macos.sh
make -j8
sudo make install
```

And, in order to bootstrap the ``langcc`` front-end itself, subsequently run:
```
./bootstrap.sh
```

## Examples
Once ``langcc`` (and its companion, ``datacc``) have been installed,
one can run various examples:
- In the ``examples`` directory, there are two examples: ``basic`` and
  ``calc``. Each has its own local Makefile.
- The main build process itself compiles ``grammars/py.lang`` and
  ``grammars/go.lang``, producing tests ``build/go_standalone_test`` and
  ``build/py_standalone_test``. (Note: These binaries require, respectively,
  repositories for Golang 1.17.8 located in the directory ``../go``,
  and Python 3.9.12 located in the directory ``../cpython``.)
- There is the language of datatypes, ``grammars/data.lang``, which describes
  the input of the additional standalone tool ``datacc`` (used by ``langcc``
  to automatically generate C++ implementations of algebraic datatypes).
- Finally, there is the language of languages itself, ``grammars/meta.lang``.
  This language also serves as basic documentation, as it enumerates all of
  its own features.

## Documentation
For full documentation, please see the [user manual](https://github.com/jzimmerman/langcc/blob/main/MANUAL.md),
as well as the [technical report](https://arxiv.org/pdf/2209.08383.pdf) which describes the theoretical development.
