default: all

BUILD = build

LANGCC = ../../build/langcc
DATACC = ../../build/datacc

all: \
	$(LANGCC) \
	$(DATACC) \
	$(BUILD)/lox_test

clean:
	rm -rf $(BUILD) gen

$(LANGCC):
	+make -C ../.. build/datacc build/langcc

$(DATACC): $(LANGCC)
	/bin/true

test: $(BUILD)/lox_test
	$(BUILD)/lox_test

CFLAGS_EXTRA =
LFLAGS_EXTRA =
CC =
DSYMUTIL_MAYBE =

LFLAGS_TCMALLOC = -ltcmalloc

ifeq ($(shell uname), Darwin)
	SDKROOT = $(shell xcrun --show-sdk-path)
	export SDKROOT = $(shell xcrun --show-sdk-path)

	HOMEBREW_BASE = /usr/local
	ifeq ($(shell uname -m), arm64)
		HOMEBREW_BASE = /opt/homebrew
	endif

	CFLAGS_EXTRA = -isystem ../../src -isystem /usr/local/include -D__MACOS_SDKROOT__=$(SDKROOT) -D__HOMEBREW_BASE__=$(HOMEBREW_BASE) -mmacosx-version-min=12.0
	LFLAGS_EXTRA = -L/opt/local/lib -L$(HOMEBREW_BASE)/opt/gperftools/lib -L/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/lib -ldl
	CC = clang++
	DSYMUTIL_MAYBE = dsymutil
else
	CFLAGS_EXTRA = -isystem ../../src
	LFLAGS_EXTRA = -ldl
	CC = clang++
	DSYMUTIL_MAYBE = true
endif

CFLAGS = -I./gen -I. -g -ggdb -g3 -O3 -std=c++17 -fno-omit-frame-pointer $(CFLAGS_EXTRA)
LFLAGS = $(LFLAGS_EXTRA) $(LFLAGS_TCMALLOC)

HPP_SRC = $(wildcard src/*.hpp) $(wildcard *.hpp)

IMPLICIT_SRC = $(HPP_SRC) gen/lox__gen.hpp gen/lox_pre__gen.hpp gen/lox__data_gen.hpp gen/lox_error__data_gen.hpp

gen/lox__gen.hpp: lox.lang gen/lox__data_gen.hpp Makefile $(LANGCC)
	mkdir -p gen
	$(LANGCC) -h -i ../../src lox.lang gen

gen/lox_pre__gen.hpp: lox_pre.lang gen/lox__data_gen.hpp Makefile $(LANGCC)
	mkdir -p gen
	$(LANGCC) -h -i ../../src lox_pre.lang gen

gen/lox__data_gen.hpp: lox.data Makefile $(DATACC)
	mkdir -p gen
	$(DATACC) -h lox.data gen

gen/lox_error__data_gen.hpp: lox_error.data Makefile $(DATACC)
	mkdir -p gen
	$(DATACC) -h lox_error.data gen

$(BUILD)/%.o: %.cpp $(IMPLICIT_SRC) Makefile
	mkdir -p $(BUILD)
	$(CC) $(CFLAGS) -c -o $@ $<

$(BUILD)/%.o: gen/%.cpp $(IMPLICIT_SRC) Makefile
	mkdir -p $(BUILD)
	$(CC) $(CFLAGS) -c -o $@ $<

build/lox_test: $(BUILD)/lox_test_main.o $(BUILD)/lox.o gen/lox__gen.hpp gen/lox_pre__gen.hpp gen/lox__data_gen.hpp gen/lox_error__data_gen.hpp Makefile
	mkdir -p $(BUILD)
	$(CC) $(CFLAGS) -o $(BUILD)/lox_test $(BUILD)/lox_test_main.o $(BUILD)/lox.o $(LFLAGS)
	$(DSYMUTIL_MAYBE) $@
