default: all

BUILD = build

LANGCC = ../../build/langcc
DATACC = ../../build/datacc

all: \
	$(LANGCC) \
	$(DATACC) \
	$(BUILD)/calc

clean:
	rm -rf $(BUILD) gen

$(LANGCC):
	+make -C ../.. build/langcc

$(DATACC): $(LANGCC)

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

CFLAGS = -I./gen -I./include -g -ggdb -g3 -std=c++17 -fno-omit-frame-pointer $(CFLAGS_EXTRA)
LFLAGS = $(LFLAGS_EXTRA) $(LFLAGS_TCMALLOC)

HPP_SRC = $(wildcard src/*.hpp)

IMPLICIT_SRC = $(HPP_SRC) gen/calc__gen.hpp

gen/calc__gen.hpp: calc.lang Makefile $(LANGCC)
	$(LANGCC) -h -i ../../src calc.lang gen

$(BUILD)/%.o: %.cpp $(IMPLICIT_SRC) Makefile
	mkdir -p $(BUILD)
	$(CC) $(CFLAGS) -c -o $@ $<

$(BUILD)/%.o: gen/%.cpp $(IMPLICIT_SRC) Makefile
	mkdir -p $(BUILD)
	$(CC) $(CFLAGS) -c -o $@ $<

build/calc: $(BUILD)/calc_main.o gen/calc__gen.hpp Makefile
	mkdir -p $(BUILD)
	$(CC) $(CFLAGS) -o $(BUILD)/calc $(BUILD)/calc_main.o $(LFLAGS)
	$(DSYMUTIL_MAYBE) $@
