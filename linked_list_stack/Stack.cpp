// Jon Hays
// jhays
// mightyfancy@gmail.com
// Stack.cpp
// assignment 1
// Stack class implementation file (bulk of implementation inherited
// from List class)
// working/tested 

#include <iostream>
#include <cstdlib>
#include "Stack.h"

using std::cerr;
using std::endl;

Stack::Stack() : List() { ; }

bool Stack::isEmpty() const {
  if (getSize() == 0)
    return true;
  return false;
}

void Stack::push(std::string str) {insertFront(str);}

string Stack::pop() {
  if (isEmpty()) {
    cerr << "Error: pop() called on empty stack" << endl;
    exit(EXIT_FAILURE);
  }
  return removeFront();
}
