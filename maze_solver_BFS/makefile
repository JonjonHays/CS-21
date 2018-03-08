p8: main.o MazeGraph.o
	g++ -pg -o p8 main.o MazeGraph.o 

main.o: main.cpp MazeGraph.h
	g++ -pg -c -std=c++11 main.cpp 

MazeGraph.o: MazeGraph.cpp MazeGraph.h
	g++ -pg -c -std=c++11 MazeGraph.cpp 

clean:
	rm -f p8 gmon.out *.o *~
