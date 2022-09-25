# ``langcc``: A Next-Generation Compiler Compiler

``langcc`` is a tool that takes the formal description of a language,
in a standard BNF-style format, and automatically generates a compiler
front-end, including data structure definitions for the language's
abstract syntax trees (AST) and traversals,
a lexer, a parser, and a pretty-printer.
``langcc`` also serves as the companion software implementation to the following
technical reports, which describe several innovations on the classic
LR parsing paradigm:
- Zimmerman, Joe.
[Practical LR Parser Generation.](https://arxiv.org/abs/2209.08383)
arXiv, 2022.
- Zimmerman, Joe.
[langcc: A Next-Generation Compiler Compiler.](https://arxiv.org/abs/2209.08385)
arXiv, 2022.

``langcc`` can be used as a replacement for the combination of ``lex``
and ``yacc`` (or ``flex`` and ``bison``). However, ``langcc`` provides many
additional features, including:
- Automatic generation of AST data structures, via a standalone datatype
compiler (``datacc``).
- Full LR parser generation as the default, rather than the more restrictive
LALR.
- Clear presentation of LR conflicts via explicit "confusing input pairs",
rather than opaque shift/reduce errors.
- Novel efficiency optimizations for LR automata.
- An extension of the LR paradigm to include recursive-descent (RD)
parsing actions, resulting in significantly smaller and more intuitive
automata.
- An extension of the LR paradigm to include per-symbol attributes,
which are vital for the efficient implementation of many industrial language
constructs.
- A general transformation for LR grammars (CPS), which significantly
expands the class of grammars the tool can support.

Unlike previous compiler compilers, ``langcc`` is general enough to capture
full industrial programming languages, for which existing parsers are
typically written by hand or generated from procedural descriptions.
Examples include Python 3.9.12 (``grammars/py.lang``) and Golang 1.17.8
(``grammars/go.lang``). In both cases, ``langcc`` automatically generates
a parser that is faster than the standard library parser for each language.
In fact, the class of grammars supported by ``langcc`` is general enough
that the tool is _self-hosting_: that is, one can express the "language
of languages" in the "language of languages" itself, and use ``langcc``
to generate its own compiler front-end. We do this in the canonical
implementation; see the files ``bootstrap.sh`` and ``grammars/meta.lang``
for more details.

``langcc`` is a research prototype and has not yet been used extensively
in production. However, we believe it is essentially stable and
feature-complete, and can be used as a standalone tool to facilitate
rapid exploration of new compilers and programming languages.

## Build
The build has been tested on Ubuntu 22.04 and macOS 12.5,
but should also run on some other versions of Ubuntu
and macOS with minor adaptations.

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
For full documentation, see the accompanying technical report:
- Zimmerman, Joe.
[langcc: A Next-Generation Compiler Compiler.](https://arxiv.org/abs/2209.08385)
arXiv, 2022.

as well as the theoretical development:
- Zimmerman, Joe.
[Practical LR Parser Generation.](https://arxiv.org/abs/2209.08383)
arXiv, 2022.

For convenience, one may view the documentation [in the source repo](./2209.08385.adoc)
