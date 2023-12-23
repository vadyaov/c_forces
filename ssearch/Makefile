CXX = g++
CXXFLAGS = -Wall -Werror -Wextra -Wpedantic -std=c++17


all: test

test: tests/test1.cc ssearch.h
	@cmake -DCMAKE_CXX_FLAGS="$(CXXFLAGS)" -S ./tests/ -B ./tests/build
	@cmake --build ./tests/build
	@./tests/build/test_search
