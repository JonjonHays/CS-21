// Jon Hays
// mightyfancy@gmail.com
// jhays
// assignment #2: integer minimum heap and priority queue
// date modified: 2/20/17
// filename: intMinHeap.cpp
// purpose: intMinHeap class implementation file
// status: working/tested

#include <iostream>
#include "intMinHeap.h"

using std::to_string;
using std::cout;
using std::cerr;
using std::endl;

intMinHeap::intMinHeap(int c) {
  size = 0;
  capacity = c;
  A = new int[capacity];
}

intMinHeap::~intMinHeap() {
  delete [] A;
}

int* intMinHeap::heapsort() {
  buildheap();
  int* sortCopy = new int[size];
  int heapSize = size; //maintain original heap size
  for (int i = 0; i < size; i++)   //hard copy
    sortCopy[i] = A[i];
  int* temp = A;
  A = sortCopy;
  for (int i = size - 1; i > 0; i--) {
    swap(0, i);
    size--;
    heapify(0);
  }
  A = temp;
  size = heapSize;
  return sortCopy;
 }

string intMinHeap::toString() {
  string str = "heap size " + to_string(size) + ": ";
  for (int i = 0; i < size - 1; i++) 
    str += (to_string(A[i]) + ", ");
  str += to_string(A[size - 1]);
  return str;
}

bool intMinHeap::heapinsert(int key) {
  if (isFull()) return false;
  A[size] = key + 1;
  size++;
  decreasekey(size-1, key);
  return true;
}

int intMinHeap::minimum() {
  if (isEmpty()) return 0;
  return A[0];
}

int intMinHeap::extractmin() {
  if (isEmpty()) {
    cerr << "Warning: extractmin() called on empty heap; 0 returned" << endl;
    return 0;
  }
  int min = A[0];
  A[0] = A[size - 1];
  size--;
  heapify(0);
  return min;
}

void intMinHeap::decreasekey(int index, int key) {
  if (index >= size) {
    cerr << "Warning: index out of range—No element exists " 
    "at specified index." << endl;
    return;
  }
  if (A[index] <= key) return; 
  A[index] = key;
  while (index > 0 && A[parent(index)] > A[index]) {
    swap(index, parent(index));
    index = parent(index);
  }
}

int intMinHeap::minOf3(int index, int left, int right) {
  int minIndex = index;
  if (left <= (size - 1) && A[left] < A[minIndex])
    minIndex = left;
  if (right <= (size - 1) && A[right] < A[minIndex])
    minIndex = right;
  return minIndex;
}

void intMinHeap::swap(int i, int n) {
  int temp = A[i];
  A[i] = A[n];
  A[n] = temp;
}

int intMinHeap::left(int index) {
  return 2*index + 1;
}

int intMinHeap::right(int index) {
  return 2*index + 2;
}

int intMinHeap::parent(int index) {
  return (index - 1)/2;
}

void intMinHeap::buildheap() {
  for (int i = size/2 - 1; i >= 0; i--)
    heapify(i);
}

void intMinHeap::heapify(int index) {
  int minIndex = minOf3(index, left(index), right(index));
  if (index != minIndex) {
    swap(index, minIndex);
    heapify(minIndex);
  } 
}



