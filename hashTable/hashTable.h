//Jon Hays
//mightyfancy@gmail.com
//jhays
//assignment 5--Hash Table
//last modified 3/28/17
//hashTable.h
//hashTable class interface file
//working/tested

#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <vector>
#include <string>
#include "record.h"

using std::vector;

//hashTable class implements a hash table built to contain "record" objects.
//implements standard hash operations (search, insert, delete) as well as 
//a function to write the table to an output file, and a function to clear
//the table. Default size is 100 slots.
class hashTable{

 public:
  //build a hashTable--default size is 100 slots
  hashTable(int=100); 
  ~hashTable();
  //insert a copy of record
  void insert(record* R); 
  //delete a single record with key "key"
  void deleteKey(int key); 
  //return pointer to a copy of found record, or 0
  record* search(int key); 
  //write table to file--one line per record
  void write(std::string filename);
  //clear hashTable
  void clearTable();

 private:
  //return chain index of first record found with key "key", -1 if not found
  int find(int key); 
  //returns hash value for record input
  int hash(record* R); 
  //returns hash value for key input
  int hash(int key); 
  //size of table
  const int m; 
  //hash table--Array of vectors containing pointers to record objects
  vector<record*>* A; 
  //reciprocal of golden ratio--used in hash function
  const double C = 0.618033989; 
};


#endif
