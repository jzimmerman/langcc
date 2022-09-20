default: all

.PHONY: clean install

BUILD = build

clean:
	rm -rf $(BUILD) gen/go__* gen/py__* gen/common__* gost

DATACC = $(BUILD)/datacc
LANGCC = $(BUILD)/langcc

install: $(DATACC) $(LANGCC)
	cp $(DATACC) /usr/local/bin/
	cp $(LANGCC) /usr/local/bin/
	cp src/langcc_util.hpp /usr/local/include/
	cp src/langcc_rt.hpp /usr/local/include/

all: \
	$(DATACC) \
	$(LANGCC) \
	$(BUILD)/unittest_lib \
	$(BUILD)/unittest_lang \
	$(BUILD)/go_standalone_test \
	$(BUILD)/py_standalone_test

# debug
# CFLAGS = -I./src -I./gen  -g -ggdb -g3 -std=c++17 -I/usr/include/llvm-c-14 \
#   -I/usr/include/llvm-14 -fno-omit-frame-pointer -fsanitize=address 
# LFLAGS = -L/usr/lib/llvm-14/lib \
# 	-lLLVMSymbolize -lLLVMDemangle -lLLVMSupport -lcryptopp -lncurses -lpthread

# release
CFLAGS = -I./src -I./gen -g -ggdb -g3 -O3 -std=c++17 -I/usr/include/llvm-c-14 \
	-I/usr/include/llvm-14 -fno-omit-frame-pointer
LFLAGS = -L/usr/lib/llvm-14/lib \
	-lLLVMSymbolize -lLLVMDemangle -lLLVMSupport -lcryptopp -lncurses -lpthread -ltcmalloc

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
	clang++ $(CFLAGS) -c -o $@ $<

$(BUILD)/datacc.o: src/datacc.cpp $(IMPLICIT_SRC_DATACC) Makefile
	mkdir -p $(BUILD)
	clang++ $(CFLAGS) -c -o $@ $<

$(BUILD)/cc__gen.o: gen/cc__gen.cpp $(IMPLICIT_SRC_DATACC) Makefile
	mkdir -p $(BUILD)
	clang++ $(CFLAGS) -c -o $@ $<

$(BUILD)/data__gen.o: gen/data__gen.cpp $(IMPLICIT_SRC_DATACC) Makefile
	mkdir -p $(BUILD)
	clang++ $(CFLAGS) -c -o $@ $<

$(BUILD)/%.o: src/%.cpp $(IMPLICIT_SRC) Makefile
	mkdir -p $(BUILD)
	clang++ $(CFLAGS) -c -o $@ $<

$(BUILD)/%.o: gen/%.cpp $(IMPLICIT_SRC) Makefile
	mkdir -p $(BUILD)
	clang++ $(CFLAGS) -c -o $@ $<

$(BUILD)/unittest_lib: $(BUILD)/unittest_lib_main.o Makefile
	clang++ $(CFLAGS) -o $@ $< $(LFLAGS)

$(BUILD)/unittest_lang: $(BUILD)/unittest_lang_main.o $(LANGCC_OBJ) Makefile
	clang++ $(CFLAGS) -o $@ $< $(LANGCC_OBJ) $(LFLAGS)

$(BUILD)/test_lang_single_main: $(BUILD)/test_lang_single_main.o $(LANGCC_OBJ) Makefile
	mkdir -p $(BUILD)
	clang++ $(CFLAGS) -o $@ $< $(LANGCC_OBJ) $(LFLAGS)

$(DATACC): $(BUILD)/datacc_main.o $(DATACC_OBJ) Makefile
	clang++ $(CFLAGS) -o $@ $< $(DATACC_OBJ) $(LFLAGS)

$(LANGCC): $(BUILD)/langcc_main.o $(LANGCC_OBJ) Makefile
	clang++ $(CFLAGS) -o $@ $< $(LANGCC_OBJ) $(LFLAGS)

gen/common__data_gen.cpp: $(DATACC) src/common.data
	$(DATACC) src/common.data gen

# Golang example

gen/go__gen.cpp: $(LANGCC) grammars/go.lang Makefile
	$(LANGCC) grammars/go.lang gen

gen/go__gen_debug.cpp: gen/go__gen.cpp
	/bin/true

$(BUILD)/go__gen.o: gen/go__gen.cpp $(IMPLICIT_SRC)  Makefile
	mkdir -p $(BUILD)
	clang++ -c -o $(BUILD)/go__gen.o $(CFLAGS) gen/go__gen.cpp

$(BUILD)/go_standalone_test: $(BUILD)/go__gen.o $(IMPLICIT_SRC) Makefile
	mkdir -p $(BUILD)
	clang++ -o $(BUILD)/go_standalone_test $(CFLAGS) src/go_standalone_test.cpp $(BUILD)/go__gen.o $(LFLAGS)

$(BUILD)/go_debug: gen/go__gen_debug.cpp $(BUILD)/go__gen.o $(IMPLICIT_SRC) Makefile
	mkdir -p $(BUILD)
	clang++ -o $(BUILD)/go_debug $(CFLAGS) gen/go__gen_debug.cpp $(BUILD)/go__gen.o $(LFLAGS)

gost: src/gost.go Makefile
	go build src/gost.go

# Python example

gen/py__gen.cpp: $(LANGCC) grammars/py.lang Makefile
	$(LANGCC) grammars/py.lang gen

gen/py__gen_debug.cpp: gen/py__gen.cpp
	/bin/true

$(BUILD)/py__gen.o: gen/py__gen.cpp $(IMPLICIT_SRC) Makefile
	mkdir -p $(BUILD)
	clang++ -c -o $(BUILD)/py__gen.o $(CFLAGS) gen/py__gen.cpp

$(BUILD)/py__gen_debug.o: gen/py__gen_debug.cpp $(IMPLICIT_SRC) Makefile
	mkdir -p $(BUILD)
	clang++ -c -o $(BUILD)/py__gen_debug.o $(CFLAGS) gen/py__gen_debug.cpp

$(BUILD)/py_standalone_test: $(BUILD)/py__gen.o $(IMPLICIT_SRC) Makefile
	mkdir -p $(BUILD)
	clang++ -o $(BUILD)/py_standalone_test $(CFLAGS) src/py_standalone_test.cpp $(BUILD)/py__gen.o $(LFLAGS)

$(BUILD)/py_debug: $(BUILD)/py__gen_debug.o $(BUILD)/py__gen.o $(IMPLICIT_SRC) Makefile
	mkdir -p $(BUILD)
	clang++ -o $(BUILD)/py_debug $(CFLAGS) gen/py__gen_debug.cpp $(BUILD)/py__gen.o $(LFLAGS)
