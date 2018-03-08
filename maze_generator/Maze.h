// Jon Hays
// mightyfancy@gmail.com
// jhays
// assignment 6: amazing Union-Find
// last modified 4/8/17
// Maze.h
// Maze generation class interface file
// working/tested

#ifndef _MAZE_H 
#define _MAZE_H

#include <utility>
#include "DisjointSet.h"

// This class randomly generates square mazes with only one path from start to finish.
// Mazes are output in the form of an nxn hex matrix, which must be input into a maze 
// viewer to view the finished maze. The class allows for regenartion of mazes of the 
// original size or a new size using the overloaded buildMaze functions.
class Maze {
  
 public:
  // Contructor firstinitializes maze array (M), indexArray, and the disjoint 
  // set object (S), generates nxn maze, where n is the integer input parameter.
  // (Generates 10x10 maze by default)
  Maze(int=10);           
  // destructor de-allocates M and indexArray
  ~Maze(); 
  // prints maze in the form of an nxn hex matrix
  void printMaze();
  // returns pointer to maze in the form of an n^2 sized integer (0-15) array
  int* getMaze() const {return M;}

 private:
  // helper function--generates maze 
  void render();         
  // clear/attempt to clear maze wall at ith element; tries twice and then continues
  void clearWall(int i);
  // selects a random wall of element i that definitely has an adjacent element.
  // returns int value of wall (1, 2, 4, or 8) 
  int randWall(int i); 
  // returns index of element that is adjacent to element with index i at 
  // the specified wall, where wall is an int value 1, 2, 4, or 8.
  int adjacent(int i, int wall);
  // returns true if the element at index i has an adjacent element at the specified wall.
  bool hasAdjacent(int i, int wall);
  // returns value of opposite wall (if wall is 1, returns 4, etc.)
  int opposite(int wall); 
  // shuffles elements in indexArray; used to create randomness in maze
  void shuffleIndices();
  // Array of size n^2 that holds maze values (0-15)
  int* M; 
  // ptr to disjoint set object that holds information about how the maze is connected
  DisjointSet* S; 
  // Array that contains all possible indice values for maze
  int* indexArray; 
  // Order of current maze (nxn)
  int n; 
  // equal to n^2
  int mazeSize;
  // values that represent the 4 possible walls a maze element can have; useful
  // for carrying out "maze arithmetic" 
  static const int right = 1;
  static const int left = 4;
  static const int top = 8;
  static const int bottom = 2;
  // array containing the four wall values as seen above (right, left, top, bottom)
  static const int wallValues[];
};


#endif
