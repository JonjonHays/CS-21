// Jon Hays
// mightyfancy@gmail.com
// jhays
// assignment 8: Breadth-First Search
// last modified: 5/4/17
// main.cpp
// MazeGraph main program file--prints shortest path
// working/tested

#include <string>
#include <iostream>
#include <vector>
#include "MazeGraph.h"

int main() {
  char c;
  std::vector<char> mazeArray; 
  while (std::cin.get(c)) {
    if (c != '\n')
      mazeArray.push_back(c);
  }
  if (mazeArray.size() == 0) {
    std::cerr << "Must enter a valid maze. Please try again." << std::endl;
    exit(0);
  }
  MazeGraph M(mazeArray);
  M.printPath();
}



