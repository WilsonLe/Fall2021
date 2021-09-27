main: main.o Node.o Set.o
	g++ main.o Node.o Set.o -o main
	rm *.o

main.o: main.cpp Node.h Set.h
	g++ -c main.cpp Node.cpp Set.cpp

Node.o: Node.cpp Node.h
	g++ -c Node.cpp

Set.o: Set.cpp Node.h Set.h
	g++ -c Node.cpp Set.cpp 

clean:
	rm -rf *.o test main