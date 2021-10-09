CPPOPTIONS = -std=c++11 -g

all: test_heap

test_heap: heap.h heap.cpp test_heap.cpp
	g++ $(CPPOPTIONS) -o test_heap test_heap.cpp

tidy:
	rm -f ,* .,* *~ core a.out *.err

clean: tidy
	rm -f *.o 