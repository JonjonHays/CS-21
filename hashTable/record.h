//Jon Hays
//mightyfancy@gmail.com
//jhays
//assignment 5--Hash Table
//last modified 5/28/17
//record.h
//record class interface/implementation file (complete class)
//working/tested

#ifndef RECORD_H
#define RECORD_H

#include <iostream>
#include <string>

//The record class is designed to hold "records" that begin with a 9 digit
//integer (the key--possibly containing leading or trailing zeros) followed
//by unspecified information. Data for record objects is contained in a string.
class record {

 public:
  record(std::string str) {data = str;}
  //copy constructor--straight copy of data
  record(const record& R) {data = R.data;}
  //returns 9-digit ID at the beginning of each record as an integer
  int getID() const {return std::stoi(data.substr(0, 9));}
  //returns a pointer to a copy of the record which clone() is invoked upon
  record* clone() {return new record(*this);}
  //set data
  void setRecord(std::string str) {data = str;}
  //get data
  std::string getRecord() const {return data;}

 private:
  std::string data;
};

#endif
