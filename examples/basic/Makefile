default: all

LANGCC = ../../build/langcc

all: \
	$(LANGCC) \
	gen/basic__gen.cpp

clean:
	rm -rf gen

$(LANGCC):
	+make -C ../.. build/datacc build/langcc

gen/basic__gen.cpp: basic.lang Makefile $(LANGCC)
	$(LANGCC) -i ../../src basic.lang gen
