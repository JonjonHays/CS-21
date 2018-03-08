// Jon Hays
// jhays
// mightyfancy@gmail.com
// main.cpp
// assignment 1 (Linked List)
// main project file 
// working/tested

#include <iostream>
#include <string>
#include "Stack.h"

using std::cin;
using std::cout;
using std::endl;

int main() {
  Stack stack1;
  std::string inString;
  while(getline(cin, inString)) {
    stack1.push(inString);
  }
  while (!stack1.isEmpty()) {
    cout << stack1.pop() << endl;
  }
}


