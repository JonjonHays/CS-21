// Jon Hays
// mightyfancy@gmail.com
// jhays
// assign. 6: Amazing Union-Find
// last modified 4/8/17
// DisjointSet.h
// DisjointSet class interface file
// working/tested

#ifndef _DISJOINTSET_H
#define _DISJOINTSET_H

// This class implements a disjoint set data structure using two arrays:
// rank and parent. This implementation uses path compression as well as
// representation by rank in order to increase efficiency of the Union-Find
// data structure
class DisjointSet {

 public:
  // default constructor; does nothing
  DisjointSet() { ; }
  // make disjoint set ranging from 0 to size-1
  DisjointSet(int size);
  // destructor -- deallocates rank and parent arrays
  ~DisjointSet();
  // merges two disjoint sets with representative elems x and y 
  void Union(int x, int y);
  // finds set containing x, and returns x's representative element.
  // (this function uses path compression to reduce height of the trees)
  int FindSet(int x);
  // returns true if elements x and y are in the same disjoint set
  bool sameComponent(int x, int y);
  int getNumSets() const {return numSets;}
  void printSets();

 private:
  void link(int x, int y); // takes two roots as input--helper func for Union
  void makeSet(int x);
  int popSize; // total population size 
  int numSets;
  int* rank;
  int* parent;
};


#endif
