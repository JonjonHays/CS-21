// Jon Hays
// mightyfancy@gmail.com
// jhays
// assignment 7: Binary Search Tree
// last modified: 4/16/17
// main.cpp
// Binary Search Tree program i/o
// working/tested

#include <string>
#include <vector>
#include <sstream>
#include <iostream>
#include "BST.h"

using std::string;
using std::vector;
using std::cin;
using std::cout;
using std::endl;

int main() {
  BST T;
  string line;
  string command;
  int key;
  std::stringstream ss;
  int* temp = 0; 
  while (getline(cin, line)) {   
    std::size_t found = line.find('#'); // position of found character;
    line = line.substr(0, found);       // if found == string::npos, substr
    if (line != "") {                   // returns unaltered string. 
      ss.clear();
      ss.str("");
      ss << line;
      ss >> command;
      if (command == "search") {
	ss >> key;
	if (T.Search(key))
	  cout << key << " found." << endl;
	else 
	  cout << key << " not found." << endl;
      }
      if (command == "insert") {
	ss >> key;
	T.Insert(key);
	cout << "inserted " << key << '.' << endl;
      }
      if (command == "delete") {
	ss >> key;
	if (T.Delete(key))
	  cout << "deleted " << key << '.' << endl;
	else
	  cout << "delete " << key << " - not found." << endl;
      }
      if (command == "min") {
	temp = T.Min();
	if (temp == 0)
	  cout << "tree empty." << endl;
	else {
	  cout << "min is " << *temp << '.' << endl;
	  delete temp; temp = 0;
	} //else
      }
      if (command == "max") {
	temp = T.Max();
	if (temp == 0) 
	  cout << "tree empty." << endl;
	else {
	  cout << "max is " << *temp << '.' << endl;
	  delete temp; temp = 0;
	} //else
      }
      if (command == "predecessor") {
	ss >> key;
	if (!T.Search(key))
	  cout << key << " not in tree." << endl;
	else {
	  temp = T.Predecessor(key);
	  if (temp == 0) 
	    cout << "no predecessor for " << key << '.' << endl;
	  else {
	    cout << key << " predecessor is " << *temp << '.' << endl;
	    delete temp; temp = 0;
	  } //else
	}
      }
      if (command == "successor") {
	ss >> key;
	if (!T.Search(key))
	  cout << key << " not in tree." << endl;
	else {
	  temp = T.Successor(key);
	  if (temp == 0) 
	    cout << "no successor for " << key << '.' << endl;
	  else {
	    cout << key << " successor is " << *temp << '.' << endl;
	    delete temp; temp = 0;
	  } //else
	}
      }
      if (command == "inorder") {
	cout << "inorder traversal:" << endl;
	T.InorderTraversal();
      }
      if (command == "preorder") {
	cout << "preorder traversal:" << endl;
	T.PreorderTraversal();
      }
      if (command == "postorder") {
	cout << "postorder traversal:" << endl;
	T.PostorderTraversal();
      }
    } // if-1 
  } // while
} // main()
