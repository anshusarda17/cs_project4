all: test.o

test.o: test_bst_example.o usecase.o
	g++ test_bst_example.cpp bst.cpp -o test

usecase.o: bst.cpp bst.h usecase.cpp
	g++ usecase.cpp -o bst