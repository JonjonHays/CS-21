p6: main.o Maze.o DisjointSet.o 
	g++ -o p6 main.o Maze.o DisjointSet.o

Maze.o: Maze.cpp Maze.h DisjointSet.h
	g++ -c Maze.cpp

DisjointSet.o: DisjointSet.cpp DisjointSet.h
	g++ -c DisjointSet.cpp

clean:
	rm -f p6 *.o *~
