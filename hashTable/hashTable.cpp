//Jon Hays
//mightyfancy@gmail.com
//jhays
//assignment 5--Hash Table
//last modified 3/28/17
//hashTable.cpp
//hashTable class implementation file
//working/tested

#include <string>
#include <cmath>
#include <fstream>
#include <iostream>
#include "record.h"
#include "hashTable.h"

hashTable::hashTable(int tableSize) : m(tableSize) {
  A = new vector<record*>[m];
}

hashTable::~hashTable() {
  clearTable();
  delete [] A; A = 0;
}

void hashTable::insert(record* R) {
  A[hash(R)].push_back(R->clone()); //add copy of record to end of "chain" at 
}                                    //position/key hash(R)

void hashTable::deleteKey(int key) {
  int hashVal = hash(key);
  int size = A[hashVal].size();
  int found = find(key);
  if (found == -1 || size == 0) return; // empty chain or key not found--return
  delete A[hashVal][found];             // delete found record object
  A[hashVal][found] = A[hashVal][size-1]; // set found pointer  to last elem
  A[hashVal][size-1] = 0; // set last elem pointer to NULL
  A[hashVal].pop_back();                  
}

record* hashTable::search(int key) { //fix if find returns int!
  int hashVal = hash(key);
  int size = A[hashVal].size();
  for (int i = 0; i < size; i++) {
    if (A[hashVal][i]->getID() == key)
      return A[hashVal][i]->clone(); // returns COPY of found record
  }
  return 0; // returns NULL if key not found
}

int hashTable::find(int key) {
  int hashVal = hash(key);
  int size = A[hashVal].size();
  record* R;
  for (int i = 0; i < size; i++) {
    if (A[hashVal][i]->getID() == key)
      return i; // return index of found record
  }
  return -1; // returns -1 if key not found
}

void hashTable::write(std::string filename) {
  std::ofstream fout;
  fout.open(filename);
  if (fout.fail()) {
    std::cerr << "output file failed to open" << std::endl;
    return;
  }
  int chainSize;
  for (int i = 0; i < m; i++) {
    chainSize = A[i].size();
    for (int j = 0; j < chainSize; j++) {
      fout << A[i][j]->getRecord() << '\n';
    } //for i
  } //for j
  fout.close();
}

void hashTable::clearTable() {
  int chainSize;
  for (int i = 0; i < m; i++) {
    chainSize = A[i].size();
    for (int j = 0; j < chainSize; j++) {
      delete A[i][j]; A[i][j] = 0;
    }
    A[i].clear();
  }
} 

int hashTable::hash(int key) {
  return m*(key*C - floor(key*C));
}

int hashTable::hash(record* R) {
  return hash(R->getID());
}
