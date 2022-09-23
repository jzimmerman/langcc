default: all

BUILD = build

all: \
	$(BUILD)/calc

CFLAGS_EXTRA =
LFLAGS_EXTRA =
CC =

LFLAGS_TCMALLOC = -ltcmalloc

ifeq ($(shell uname), Darwin)
	SDKROOT = $(shell xcrun --show-sdk-path)
	export SDKROOT = $(shell xcrun --show-sdk-path)

	HOMEBREW_BASE = /usr/local
	ifeq ($(shell uname -m), arm64)
		HOMEBREW_BASE = /opt/homebrew
	endif

	CFLAGS_EXTRA = -D__MACOS__ -D__MACOS_SDKROOT__=$(SDKROOT) -D__HOMEBREW_BASE__=$(HOMEBREW_BASE) -I/opt/local/include -I$(HOMEBREW_BASE)/opt/llvm@15/include -mmacosx-version-min=12.0
	LFLAGS_EXTRA = -L/opt/local/lib -L$(HOMEBREW_BASE)/opt/gperftools/lib -L$(HOMEBREW_BASE)/opt/llvm@15/lib -L$(HOMEBREW_BASE)/Cellar/ncurses/6.3/lib -L/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/lib
	CC = $(HOMEBREW_BASE)/opt/llvm@15/bin/clang++
else
	CFLAGS_EXTRA = -I/usr/include/llvm-c-14 -I/usr/include/llvm-14
	LFLAGS_EXTRA = -L/usr/lib/llvm-14/lib
	CC = clang++
endif

CFLAGS = -I./gen -I./include -g -ggdb -g3 -std=c++17 -fno-omit-frame-pointer $(CFLAGS_EXTRA)
LFLAGS = $(LFLAGS_EXTRA) \
	-lLLVMSymbolize -lLLVMDemangle -lLLVMSupport -lncurses $(LFLAGS_TCMALLOC)

gen/calc__gen.cpp: calc.lang Makefile
	langcc calc.lang gen

build/calc: gen/calc__gen.cpp calc_main.cpp Makefile
	mkdir -p $(BUILD)
	$(CC) $(CFLAGS) -o $(BUILD)/calc calc_main.cpp gen/calc__gen.cpp $(LFLAGS)
