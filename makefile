

#all: test.o bst.o

#test.o: test_bst_example.cpp bst.cpp
#	g++ test_bst_example.cpp bst.cpp -o test

#bst.o: bst.cpp bst.h
#	g++ bst.cpp -o bst

#

# run "make" then ./test or ./usecase 
# to clean run: "make clean"

all: test usecase

usecase: main.o usecase.o bst.o 
	g++ -std=c++11 -o usecase main.o usecase.o bst.o

test: test_bst_example.o bst.o
	g++ -std=c++11 -o test test_bst_example.o bst.o

test_bst_example.o: test_bst_example.cpp bst.h
	g++ -std=c++11 -c $<

bst.o: bst.cpp bst.h
	g++ -std=c++11 -c $<

main.o: main.cpp bst.h
	g++ -std=c++11 -c $<

usecase.o: usecase.cpp bst.h
	g++ -std=c++11 -c $<

clean:
	del *.o test usecase