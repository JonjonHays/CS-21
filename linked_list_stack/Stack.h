// Jon Hays
// jhays
// mightyfancy@gmail.com
// Stack.h
// assignment 1 (Linked List)
// Stack class interface/implementation file (derived from List class)
// working/tested

#ifndef STACK_H
#define STACK_H

#include <string>
#include "List.h"

using std::string;

// This class is derived from the List class. It serves as a 
// basic Stack object with FIFO utility
class Stack : public List {

 public:
  Stack();
  // Inserts string to front of stack (wrapper function simply
  // calls function from its parent class "List")
  void push(std::string str);
  // Removes string from front of stack, and returns 
  // the string that has been removed (wrapper function simply 
  // calls function from its parent class "List")
  string pop();
  // Returns true if stack is empty; false if not
  bool isEmpty() const;
  
};


#endif
