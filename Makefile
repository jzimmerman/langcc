default: all

.PHONY: clean install

BUILD = build

clean:
	rm -rf $(BUILD) gen/go__* gen/py__* gen/common__* gost

DATACC = $(BUILD)/datacc
LANGCC = $(BUILD)/langcc

INSTALL_BASE = /usr/local

install: $(DATACC) $(LANGCC)
	mkdir -p $(INSTALL_BASE)/bin
	mkdir -p $(INSTALL_BASE)/include
	cp $(DATACC) $(INSTALL_BASE)/bin/
	cp $(LANGCC) $(INSTALL_BASE)/bin/
ifeq ($(shell uname), Darwin)
	rm -rf $(INSTALL_BASE)/bin/langcc.dSYM
	rm -rf $(INSTALL_BASE)/bin/datacc.dSYM
	cp -r $(DATACC).dSYM $(INSTALL_BASE)/bin/
	cp -r $(LANGCC).dSYM $(INSTALL_BASE)/bin/
endif
	cp src/langcc_util.hpp $(INSTALL_BASE)/include/
	cp src/langcc_rt.hpp $(INSTALL_BASE)/include/

uninstall:
	rm -f $(INSTALL_BASE)/bin/datacc
	rm -f $(INSTALL_BASE)/bin/langcc
	rm -f $(INSTALL_BASE)/include/langcc_util.hpp
	rm -f $(INSTALL_BASE)/include/langcc_rt.hpp

all: \
	$(DATACC) \
	$(LANGCC) \
	$(BUILD)/unittest_lib \
	$(BUILD)/unittest_lang \
	$(BUILD)/go_standalone_test \
	$(BUILD)/py_standalone_test

CFLAGS_EXTRA =
LFLAGS_EXTRA =
CC =
DSYMUTIL_MAYBE =
LLVM_SYM_PATH =

LFLAGS_TCMALLOC = -ltcmalloc

ifeq ($(shell uname), Darwin)
	SDKROOT = $(shell xcrun --show-sdk-path)
	export SDKROOT = $(shell xcrun --show-sdk-path)

	HOMEBREW_BASE = /usr/local
	ifeq ($(shell uname -m), arm64)
		HOMEBREW_BASE = /opt/homebrew
	endif

	CFLAGS_EXTRA = -D__MACOS__ -D__MACOS_SDKROOT__=$(SDKROOT) -mmacosx-version-min=12.0
	LFLAGS_EXTRA = -L/opt/local/lib -L$(HOMEBREW_BASE)/opt/gperftools/lib -L/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/lib -ldl
	CC = clang++
	DSYMUTIL_MAYBE = dsymutil
	LLVM_SYM_PATH = $(HOMEBREW_BASE)/opt/llvm/bin/llvm-symbolizer
else
	CFLAGS_EXTRA =
	LFLAGS_EXTRA = -lunwind -ldl
	CC = clang++
	DSYMUTIL_MAYBE = true
	LLVM_SYM_PATH = /usr/bin/llvm-symbolizer
endif

CFLAGS_LLVM_SYM =

ifeq ($(shell test -e $(LLVM_SYM_PATH) && echo 'yes'), yes)
	CFLAGS_LLVM_SYM = -D__HAS_LLVM_SYMBOLIZER__ -D__LLVM_SYMBOLIZER_PATH__=$(LLVM_SYM_PATH)
endif

CFLAGS = -I./src -I./gen -g -ggdb -g3 -O3 -std=c++17 -fno-omit-frame-pointer $(CFLAGS_LLVM_SYM) $(CFLAGS_EXTRA)
LFLAGS = $(LFLAGS_EXTRA) $(LFLAGS_TCMALLOC)

HPP_SRC = $(wildcard src/*.hpp)

DATACC_OBJ = \
	$(BUILD)/datacc.o \
	$(BUILD)/cc__gen.o \
	$(BUILD)/data__gen.o \

LANGCC_OBJ = \
	$(BUILD)/langcc.o \
	$(BUILD)/langcc_lexer.o \
	$(BUILD)/langcc_parser_flatten.o \
	$(BUILD)/langcc_parser_attr.o \
	$(BUILD)/langcc_parser_cps.o \
	$(BUILD)/langcc_parser_lr.o \
	$(BUILD)/langcc_encode.o \
	$(BUILD)/langcc_normalize.o \
	$(BUILD)/langcc_emit.o \
	$(BUILD)/cc__gen.o \
	$(BUILD)/data__gen.o \
	$(BUILD)/meta__gen.o \
	$(BUILD)/common__data_gen.o \
	$(BUILD)/datacc.o \

GEN_LIB_SRC = \
	gen/common__data_gen.cpp \
	gen/cc__gen.cpp \
	gen/meta__gen.cpp \
	gen/data__gen.cpp \

IMPLICIT_SRC = $(HPP_SRC) $(GEN_LIB_SRC)

IMPLICIT_SRC_DATACC = $(HPP_SRC) gen/cc__gen.cpp gen/data__gen.cpp

$(BUILD)/datacc_main.o: src/datacc_main.cpp $(IMPLICIT_SRC_DATACC) Makefile
	mkdir -p $(BUILD)
	$(CC) $(CFLAGS) -c -o $@ $<

$(BUILD)/datacc.o: src/datacc.cpp $(IMPLICIT_SRC_DATACC) Makefile
	mkdir -p $(BUILD)
	$(CC) $(CFLAGS) -c -o $@ $<

$(BUILD)/cc__gen.o: gen/cc__gen.cpp $(IMPLICIT_SRC_DATACC) Makefile
	mkdir -p $(BUILD)
	$(CC) $(CFLAGS) -c -o $@ $<

$(BUILD)/data__gen.o: gen/data__gen.cpp $(IMPLICIT_SRC_DATACC) Makefile
	mkdir -p $(BUILD)
	$(CC) $(CFLAGS) -c -o $@ $<

$(BUILD)/go_standalone_test.o: src/go_standalone_test.cpp gen/go__gen.cpp Makefile
	mkdir -p $(BUILD)
	$(CC) $(CFLAGS) -c -o $@ $<

$(BUILD)/py_standalone_test.o: src/py_standalone_test.cpp gen/py__gen.cpp Makefile
	mkdir -p $(BUILD)
	$(CC) $(CFLAGS) -c -o $@ $<

$(BUILD)/%.o: src/%.cpp $(IMPLICIT_SRC) Makefile
	mkdir -p $(BUILD)
	$(CC) $(CFLAGS) -c -o $@ $<

$(BUILD)/%.o: gen/%.cpp $(IMPLICIT_SRC) Makefile
	mkdir -p $(BUILD)
	$(CC) $(CFLAGS) -c -o $@ $<

$(BUILD)/unittest_lib: $(BUILD)/unittest_lib_main.o Makefile
	$(CC) $(CFLAGS) -o $@ $< $(LFLAGS)

$(BUILD)/unittest_lang: $(BUILD)/unittest_lang_main.o $(LANGCC_OBJ) Makefile
	$(CC) $(CFLAGS) -o $@ $< $(LANGCC_OBJ) $(LFLAGS)

$(BUILD)/test_lang_single_main: $(BUILD)/test_lang_single_main.o $(LANGCC_OBJ) Makefile
	mkdir -p $(BUILD)
	$(CC) $(CFLAGS) -o $@ $< $(LANGCC_OBJ) $(LFLAGS)

$(DATACC): $(BUILD)/datacc_main.o $(DATACC_OBJ) Makefile
	$(CC) $(CFLAGS) -o $@ $< $(DATACC_OBJ) $(LFLAGS)
	$(DSYMUTIL_MAYBE) $@

$(LANGCC): $(BUILD)/langcc_main.o $(LANGCC_OBJ) Makefile
	$(CC) $(CFLAGS) -o $@ $< $(LANGCC_OBJ) $(LFLAGS)
	$(DSYMUTIL_MAYBE) $@

gen/common__data_gen.cpp: $(DATACC) src/common.data
	$(DATACC) src/common.data gen

# Golang example

gen/go__gen.cpp: $(LANGCC) grammars/go.lang Makefile
	$(LANGCC) grammars/go.lang gen

gen/go__gen_debug.cpp: gen/go__gen.cpp
	/bin/true

$(BUILD)/go__gen.o: gen/go__gen.cpp $(IMPLICIT_SRC)  Makefile
	mkdir -p $(BUILD)
	$(CC) -c -o $(BUILD)/go__gen.o $(CFLAGS) gen/go__gen.cpp

$(BUILD)/go_standalone_test: $(BUILD)/go_standalone_test.o $(BUILD)/go__gen.o $(IMPLICIT_SRC) Makefile
	mkdir -p $(BUILD)
	$(CC) -o $(BUILD)/go_standalone_test $(CFLAGS) $(BUILD)/go_standalone_test.o $(BUILD)/go__gen.o $(LFLAGS)
	$(DSYMUTIL_MAYBE) $@

$(BUILD)/go_debug: gen/go__gen_debug.cpp $(BUILD)/go__gen.o $(IMPLICIT_SRC) Makefile
	mkdir -p $(BUILD)
	$(CC) -o $(BUILD)/go_debug $(CFLAGS) gen/go__gen_debug.cpp $(BUILD)/go__gen.o $(LFLAGS)
	$(DSYMUTIL_MAYBE) $@

gost: src/gost.go Makefile
	go build src/gost.go

# Python example

gen/py__gen.cpp: $(LANGCC) grammars/py.lang Makefile
	$(LANGCC) grammars/py.lang gen

gen/py__gen_debug.cpp: gen/py__gen.cpp
	/bin/true

$(BUILD)/py__gen.o: gen/py__gen.cpp $(IMPLICIT_SRC) Makefile
	mkdir -p $(BUILD)
	$(CC) -c -o $(BUILD)/py__gen.o $(CFLAGS) gen/py__gen.cpp

$(BUILD)/py__gen_debug.o: gen/py__gen_debug.cpp $(IMPLICIT_SRC) Makefile
	mkdir -p $(BUILD)
	$(CC) -c -o $(BUILD)/py__gen_debug.o $(CFLAGS) gen/py__gen_debug.cpp

$(BUILD)/py_standalone_test: $(BUILD)/py_standalone_test.o $(BUILD)/py__gen.o $(IMPLICIT_SRC) Makefile
	mkdir -p $(BUILD)
	$(CC) -o $(BUILD)/py_standalone_test $(CFLAGS) $(BUILD)/py_standalone_test.o $(BUILD)/py__gen.o $(LFLAGS)
	$(DSYMUTIL_MAYBE) $@

$(BUILD)/py_debug: $(BUILD)/py__gen_debug.o $(BUILD)/py__gen.o $(IMPLICIT_SRC) Makefile
	mkdir -p $(BUILD)
	$(CC) -o $(BUILD)/py_debug $(CFLAGS) gen/py__gen_debug.cpp $(BUILD)/py__gen.o $(LFLAGS)
	$(DSYMUTIL_MAYBE) $@
