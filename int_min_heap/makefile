p2: main.o intMinHeap.o
	g++ -o p2 main.o intMinHeap.o

main.o: main.cpp intMinHeap.h
	g++ -c -std=c++11 main.cpp

intMinHeap.o: intMinHeap.cpp intMinHeap.h
	g++ -c -std=c++11 intMinHeap.cpp

clean: 
	rm -f p2 *.o *~
