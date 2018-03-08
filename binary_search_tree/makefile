p7: main.o BST.o 
	g++ -o p7 main.o BST.o

main.o: main.cpp BST.h
	g++ -c -std=c++11 main.cpp

BST.o: BST.cpp BST.h TreeNode.h
	g++ -c -std=c++11 BST.cpp

clean:
	rm -f p7 *.o *~
