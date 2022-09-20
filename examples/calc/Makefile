default: all

BUILD = build

all: \
	$(BUILD)/calc

CFLAGS = -I./gen -I./include -g -ggdb -g3 -std=c++17 -I/usr/include/llvm-c-14 \
	-I/usr/include/llvm-14 -fno-omit-frame-pointer
LFLAGS = -L/usr/lib/llvm-14/lib \
	-lLLVMSymbolize -lLLVMDemangle -lLLVMSupport -lcryptopp -lncurses -lpthread -ltcmalloc

gen/calc__gen.cpp: calc.lang Makefile
	langcc calc.lang gen

build/calc: gen/calc__gen.cpp calc_main.cpp Makefile
	mkdir -p $(BUILD)
	clang++ $(CFLAGS) -o $(BUILD)/calc calc_main.cpp gen/calc__gen.cpp $(LFLAGS)
