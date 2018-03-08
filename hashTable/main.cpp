//Jon Hays
//mightyfancy@gmail.com
//jhays
//assignment 5--Hash Table
//last modified 5/28/17
//main.cpp
//main program test loop--contains menu for utilizing hashTable operations
//working/tested

#include <string>
#include <iostream>
#include <fstream>
#include <iomanip>
#include "record.h"
#include "hashTable.h"


using std::string;
using std::cin;
using std::cout;
using std::cerr;
using std::endl;
using std::ifstream;
using std::ofstream;


int main() {
  int choice;            // user menu option
  string inputStr = "";  // general input string for various operations in menu
  int inputInt;         // general input integer for various operations in menu
  const int tableSize = 178000;
  hashTable T(tableSize);
  while (true) {
    cout << "(1)load (2)insert (3)delete (4)search (5)clear "
      "(6)save (7)quit -- Your choice? ";
    cin >> choice;
    switch(choice) { 
    case 1 : { 
      cout << "read hash table - filename? ";
      record* R = new record(""); // empty record
      ifstream fin;
      cin >> inputStr; 
      fin.open(inputStr);
      if (fin.fail()) {
	cerr << "input file failed to open" << endl;
	break;
      }
      while(getline(fin, inputStr)) {
	R->setRecord(inputStr);
	T.insert(R);
      }
      fin.close(); 
      delete R; R = 0;
      break;
    } //case 1
    case 2 : {
      cout << "input new record: " << endl;
      record* R = new record(""); // empty record
      cin.ignore(); 
      getline(cin, inputStr); 
      R->setRecord(inputStr); 
      T.insert(R);
      delete R; R = 0;
      break;
    } //case 2
    case 3 : { 
      cout << "delete record - key? ";
      record* R;
      cin >> inputInt; cout << endl;
      R = T.search(inputInt);
      if (R != 0) {
	T.deleteKey(inputInt);
	cout << "Delete: " << R->getRecord() << endl;
      }
      else {
	cout << "Delete not found: " << std::setw(9) << std::setfill('0')
	     << inputInt << endl ;
      }
      delete R; R = 0;
      break;
    } //case 3
    case 4 : { 
      record* R;      
      cout << "search for record - key? ";
      cin >> inputInt; cout << endl;
      R = T.search(inputInt);
      if (R != 0) 
	cout << "Found: " << R->getRecord() << endl;
      else
	cout << "Search not found: " << std::setw(9) << std::setfill('0')
	     << inputInt << endl;
      delete R; R = 0;
      break;
    } //case 4
    case 5 : {
      cout << "clearing hash table." << endl;
      T.clearTable();
      break;
    } //case 5

    case 6 : {
      cout << "write hash table - filename? ";
      cin >> inputStr;
      T.write(inputStr);
      break;
    } //case 6

    case 7 : {
      exit(EXIT_SUCCESS);
    } //case 7
    default: {
      cin.clear();
      cin.ignore();
      cerr << "invalid input--please select a valid entry." << endl;
      break; 
    } //default
    } //switch
  } //while
} //main()
