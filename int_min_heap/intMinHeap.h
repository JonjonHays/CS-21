// Jon Hays
// mightyfancy@gmail.com
// jhays
// assigment #2: Integer Minimum Heap and Priority Queue
// last modified: 2/20/17
// filename: intMinHeap.h
// purpose: intMinHeap class interface file
// status: working/tested

#ifndef INTMINHEAP_H
#define INTMINHEAP_H

#include <string>

using std::string;

// This class implements a minimum heap priority queue.
// Objects of this class store integers in a ZERO-BASED
// (root at A[0]) heap—-the minimum heap property is 
// always maintained.
class intMinHeap {

 public:
  // create an empty heap wth capacity c, size 0
  intMinHeap(int c);  
  
  // clean up allocated memory  
  ~intMinHeap();  
  
  // Returns sorted array from heap. Maintains original heap and returns
  // pointer to newly allocated sorted array. NOTE: this function 
  // allocates an array using the "new" keyword; user is responsible for
  // deallocating the array using the "delete []" keyword. Returns empty 
  // array when called on empty heap.
  int *heapsort(); 

  // returns string containing heap values in order in a comma separated 
  // list, as well as heap size. returns "heap size 0: " if called on empty
  // heap.
  string toString();  

  // add element to heap; return success
  bool heapinsert(int); 

  // return value of A[root]
  int minimum();
  
  // return and remove A[root]
  int extractmin(); 

  // A[i] decreased to k
  void decreasekey(int i, int k);

  // check for empty heap  
  bool isEmpty(){return size==0;}

  // check if array is full/heap is at capacity
  bool isFull(){return size==capacity;}

  // return size of heap
  int getSize() const {return size;}   

 private:
  int minOf3(int i, int l, int r); // index of lowest value of A[i], A[l], and A[r] 
  void swap(int i, int n); //swap array elements with indices i and n
  int left(int); // index of left
  int right(int); // index of right
  int parent(int); // index of parent
  void buildheap();  // convert array to a heap
  void heapify(int i);  // heapify at position i  
  int *A;  // array of integers - data
  int capacity; // size of array A
  int size; // data size in array


};

#endif 
