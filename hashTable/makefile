p5: main.o hashTable.o 
	g++ -o p5 main.o hashTable.o 

main.o: main.cpp hashTable.h #record.h
	g++ -c -std=c++11 main.cpp

hashTable.o: hashTable.cpp hashTable.h #record.h
	g++ -c -std=c++11 hashTable.cpp

#record.o: record.cpp record.h
#	g++ -c record.cpp

clean:
	rm -f p5 *.o *~
