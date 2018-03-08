// Jon Hays
// jhays
// mightyfancy@gmail.com
// List.cpp
// assignment 1 (Linked List)
// List class implementation file
// working/tested

#include <iostream>
#include <string>
#include "List.h"

using std::cout;
using std::endl;
using std::string;

List::List() : first(0), size(0) {}

List::~List() {
  LinkNode* temp = first;
  while(first) {
    temp = first;
    first = first->next;
    delete temp;
  }
}

void List::insertFront(string str) {
  LinkNode* temp = new LinkNode();
  temp->data = str;
  temp->next = first;
  first = temp;
  size++;
}

string List::removeFront() { 
  LinkNode* temp = first;
  string str = "";
  if (temp) {
    first = first->next;
    str = temp->data;
    delete temp;
    size--;
  }
  return str;
}


