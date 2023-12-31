


# run "make" then ./test or ./usecase 
# to clean run: "make clean"

all: test usecase

usecase: main.o usecase.o bst.o
	g++ -std=c++11 -o usecase main.o usecase.o bst.o 

test: test_bst.o bst.o
	g++ -std=c++11 -o test test_bst.o bst.o

test_bst.o: test_bst.cpp bst.h
	g++ -std=c++11 -c test_bst.cpp

bst.o: bst.cpp bst.h
	g++ -std=c++11 -c bst.cpp

main.o: main.cpp bst.h
	g++ -std=c++11 -c main.cpp 

usecase.o: usecase.cpp bst.h
	g++ -std=c++11 -c usecase.cpp

clean:
	rm -f *.o test usecase