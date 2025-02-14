CC=g++
FLAGS=-std=c++20 -Wall -Werror -Wextra -Wno-unused-variable

all: tests_bin

tests_bin: piramid_sort.o tests.o
	$(CC) $(FLAGS) -o tests piramid_sort.o tests.o -lgtest_main -lgtest -lpthread

alloc.o: piramid_sort.cpp piramid_sort.hpp
	$(CC) $(FLAGS) -c alloc.cpp

tests.o: tests.cpp
	$(CC) $(FLAGS) -c tests.cpp -lgtest_main -lgtest -lpthread

test:
	./tests

clean:
	rm -rf *.o tests