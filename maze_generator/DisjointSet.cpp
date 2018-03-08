// Jon Hays
// mightyfancy@gmail.com
// jhays
// assignment 6: amazing union-find
// last modified 4/8/17
// DisjointSet.cpp
// DisjointSet class implementation file
// working/tested

#include <iostream>
#include <cstdlib>
#include "DisjointSet.h"

using std::cout;
using std::endl;
using std::cerr;

DisjointSet::DisjointSet(int size) {
  if (size < 0) {
    cout << "Disjoint set size must be greater than or equal to 0." << endl;
    exit(1);
  }
  rank = new int[size];
  parent = new int[size];
  for (int i = 0; i < size; i++) 
    makeSet(i);
  numSets = size;
  popSize = size;
}

DisjointSet::~DisjointSet() {
  delete [] rank;
  delete [] parent;
} 

void DisjointSet::Union(int x, int y) {
  if (x < 0 || x >= popSize || y < 0 || y >= popSize) return;
  link(FindSet(x), FindSet(y));
}

int DisjointSet::FindSet(int x) {
  if (x < 0 || x >= popSize) return -1;
  if (x != parent[x])
    parent[x] = FindSet(parent[x]);
  return parent[x];
}

bool DisjointSet::sameComponent(int x, int y) {
  return (FindSet(x) == FindSet(y));
}

void DisjointSet::printSets() {
  for (int i = 0; i < popSize; i++) {
    cout << '{'; 
    for (int j = 0; j < popSize; j++) {
      if (parent[j] == i) {
	cout << j << ", ";
      }
    }
    cout << '}' << endl;
    
  }
}

void DisjointSet::link(int x, int y) {
  if (x==y) return;
  if (rank[x] > rank[y]) 
    parent[y] = x;
  else {
    parent[x] = y;
    if (rank[x] == rank[y])
      rank[y]++;
  }
  numSets--;
}

void DisjointSet::makeSet(int x) {
  parent[x] = x;
  rank[x] = 0;
}
