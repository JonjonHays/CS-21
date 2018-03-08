// Jon Hays
// mightyfancy@gmail.com
// jhays
// assignment #2: integer minimum heap and priority queue
// date modified: 2/20/17
// filename: main.cpp
// purpose: main program testing for intMinHeap class
// status: working/tested

#include <iostream>
#include "intMinHeap.h"

using std::cin;
using std::cout;
using std::endl;

int main() {
  intMinHeap testHeap(2400000);
  int* testSort;
  int size;
  int input;
  while (cin >> input) {
    if (input > 0) {
      testHeap.heapinsert(input);
      cout << "insert: " << input << endl;
    }
    if (input==0)
      cout << testHeap.toString() << endl;
    if (input == -1) 
      cout << "extract min: " << testHeap.extractmin() << endl;
    if (input == -2) {
      testSort = testHeap.heapsort();
      size = testHeap.getSize();
      cout << "sorted array: [";
      for (int i = 0; i < size-1; i++) 
	cout << testSort[i] << ", ";
      cout << testSort[size-1] << "]" << endl;
      delete [] testSort;
    }
  }
}

