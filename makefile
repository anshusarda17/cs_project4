all: test.o bst.o

test.o: test_bst_example.cpp bst.cpp
	g++ test_bst_example.cpp bst.cpp -o test

bst.o: bst.cpp bst.h
	g++ bst.cpp -o bst