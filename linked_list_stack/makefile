p1: main.o List.o Stack.o 
	g++ -o p1 main.o List.o Stack.o

main.o: main.cpp Stack.h List.h LinkNode.h
	g++ -c main.cpp

List.o: List.cpp List.h LinkNode.h
	g++ -c List.cpp

Stack.o: Stack.cpp List.h 
	g++ -c Stack.cpp

clean:
	rm -f p1 *.o *~ 

