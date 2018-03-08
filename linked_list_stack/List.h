// Jon Hays
// jhays
// mightyfancy@gmail.com
// List.h
// assignment 1 (Linked List)
// List class interface file
// working/tested

#ifndef LIST_H
#define LIST_H

#include <string>
#include "LinkNode.h"

// Partially adapted from MonsterList.h by Jon Hays
class List {
  
 public:
  List(); 
  ~List();
  // inserts string at the front of the list
  void insertFront(std::string);
  // removes string from the front of the list and returns the 
  // string that has been removed
  std::string removeFront();  
  int getSize() const {return size;}

 private:
  LinkNode* first;
  int size;
};


#endif
