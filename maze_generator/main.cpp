// Jon Hays
// mightyfancy@gmail.com
// jhays
// assignment 6: amazing Union-Find
// last modified 4/8/17
// main.cpp
// maze generation i/o file
// working/tested

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include "DisjointSet.h"
#include "Maze.h"

using std::cout;
using std::cerr;
using std::endl;

int main(int argc, char *argv[]) {
  std::string err = "Please enter a valid maze dimension (must be "
    "greater than 3) at the command line.";
  if (argc < 2) {
    cerr << err << endl;
    exit(1);
  }
  int n = atoi(argv[1]);
  if (n < 3) {
    cerr << err << endl;
    exit(1);
  }
  srand(time(0));
  Maze M(n);
  M.printMaze();
}
