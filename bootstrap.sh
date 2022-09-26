#!/bin/bash
set -e
set -u

make clean
make -j16 build/datacc
make -j16 build/langcc
make -j16 build/unittest_lang
build/unittest_lang

build/langcc grammars/data.lang gen
build/langcc grammars/cc.lang gen
build/langcc grammars/meta.lang gen

make clean
make -j16

build/unittest_lang || (echo 'Failure: unittest_lang' && false)
echo 'Running go_standalone_test'
build/go_standalone_test 1 || (echo 'Failure: go_standalone_test' && false)
echo 'Running py_standalone_test'
build/py_standalone_test 1 || (echo 'Failure: py_standalone_test' && false)
echo 'Running go_standalone_bidir_test'
build/go_standalone_bidir_test 1 || (echo 'Failure: go_standalone_bidir_test' && false)
echo 'Running py_standalone_bidir_test'
build/py_standalone_bidir_test 1 || (echo 'Failure: py_standalone_bidir_test' && false)
