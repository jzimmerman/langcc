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

## Build
This build has been verified to work on Ubuntu 22.04 and MacOS 12.5.

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
Once ``langcc`` (and its companion ``datacc``) have been built, you can run the various provided examples:
- The most fully featured example is in ``examples/lox``, which includes a complete interpreter for a
full scripting language called Lox designed by Robert Nystrom at
[Crafting Interpreters](https://craftinginterpreters.com/). The Lox example is explored in detail in the
[user manual](https://github.com/jzimmerman/langcc/blob/main/MANUAL.md) and is the recommended way to learn
about ``langcc``'s feature set.
- ``examples/basic`` illustrates the basic syntax of a declarative language spec, while
``examples/calc`` implements a calculator for arithmetic expressions, including user-friendly error reporting.
- ``grammars/go.lang`` and ``grammars/py.lang`` provide complete specifications for the syntax of Golang 1.17.8 and
Python 3.9.12, respectively. They showcase the full feature set of ``langcc`` and are compiled during the main
build process itself, which produces tests ``build/go_standalone_test`` and ``build/py_standalone_test``. (Note: These binaries require repositories for Golang 1.17.8 and Python 3.9.12 located in the directories ``../go`` and ``../cpython``.)
- The language of datatypes, ``grammars/data.lang``, describes the input format expected by 
the standalone datatype compiler ``datacc`` for specifying algebraic datatypes.
- Finally, the language of languages itself, ``grammars/meta.lang``, describes the input format
expected by ``langcc``. This language also serves as basic documentation, as it enumerates all of
its own features.

## Documentation
For full documentation, please see the [user manual](https://github.com/jzimmerman/langcc/blob/main/MANUAL.md).
