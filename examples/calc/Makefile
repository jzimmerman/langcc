default: all

BUILD = build

all: \
	$(BUILD)/calc

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

	CFLAGS_EXTRA = -D__MACOS__ -D__MACOS_SDKROOT__=$(SDKROOT) -D__HOMEBREW_BASE__=$(HOMEBREW_BASE) -mmacosx-version-min=12.0
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

CFLAGS = -I./gen -I./include -g -ggdb -g3 -std=c++17 -fno-omit-frame-pointer $(CFLAGS_LLVM_SYM) $(CFLAGS_EXTRA)
LFLAGS = $(LFLAGS_EXTRA) $(LFLAGS_TCMALLOC)

gen/calc__gen.cpp: calc.lang Makefile
	langcc calc.lang gen

build/calc: gen/calc__gen.cpp calc_main.cpp Makefile
	mkdir -p $(BUILD)
	$(CC) $(CFLAGS) -o $(BUILD)/calc calc_main.cpp gen/calc__gen.cpp $(LFLAGS)
	$(DSYMUTIL_MAYBE) $@
