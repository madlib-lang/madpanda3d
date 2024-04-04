# Inputs
CXX ?= clang++
AR ?= llvm-ar


INCLUDEDIR := include
BUILDDIR := build
SRCDIR := src
OBJS :=\
  $(BUILDDIR)/madpanda.o

MADLIB_RUNTIME_HEADERS_PATH := "$(shell madlib config runtime-headers-path)"
MADLIB_RUNTIME_LIB_HEADERS_PATH := "$(shell madlib config runtime-lib-headers-path)"

build: prepare build/libmadpanda.a print_done

prepare:
	@mkdir -p build

print_done:
	@echo "build done.\noutput: build/libmadpanda.a"

$(BUILDDIR)/%.o: $(SRCDIR)/%.cpp
	clang++ -I"$(INCLUDEDIR)" -I$(MADLIB_RUNTIME_HEADERS_PATH) -I$(MADLIB_RUNTIME_LIB_HEADERS_PATH) -std=c++17 -O1 -fPIC $(CXXFLAGS) -c $< -o $@

build/libmadpanda.a: $(OBJS)
	$(AR) rc $@ $^
