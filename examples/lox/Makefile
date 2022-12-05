default: all

BUILD = build

all: \
	$(BUILD)/lox_test

clean:
	rm -rf $(BUILD) gen

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

	CFLAGS_EXTRA = -isystem /usr/local/include -D__MACOS_SDKROOT__=$(SDKROOT) -D__HOMEBREW_BASE__=$(HOMEBREW_BASE) -mmacosx-version-min=12.0
	LFLAGS_EXTRA = -L/opt/local/lib -L$(HOMEBREW_BASE)/opt/gperftools/lib -L/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/lib -ldl
	CC = clang++
	DSYMUTIL_MAYBE = dsymutil
else
	CFLAGS_EXTRA =
	LFLAGS_EXTRA = -ldl
	CC = clang++
	DSYMUTIL_MAYBE = true
endif

CFLAGS = -I./gen -I. -g -ggdb -g3 -O3 -std=c++17 -fno-omit-frame-pointer $(CFLAGS_EXTRA)   # -fsanitize=address 
LFLAGS = $(LFLAGS_EXTRA) $(LFLAGS_TCMALLOC)

HPP_SRC = $(wildcard src/*.hpp) $(wildcard *.hpp)

IMPLICIT_SRC = $(HPP_SRC) gen/lox__gen.hpp gen/lox_pre__gen.hpp gen/lox__data_gen.hpp gen/lox_error__data_gen.hpp

gen/lox__gen.hpp: lox.lang gen/lox__data_gen.hpp Makefile
	mkdir -p gen
	langcc -h lox.lang gen

gen/lox_pre__gen.hpp: lox_pre.lang gen/lox__data_gen.hpp Makefile
	mkdir -p gen
	langcc -h lox_pre.lang gen

gen/lox__data_gen.hpp: lox.data Makefile
	mkdir -p gen
	datacc -h lox.data gen

gen/lox_error__data_gen.hpp: lox_error.data Makefile
	mkdir -p gen
	datacc -h lox_error.data gen

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
