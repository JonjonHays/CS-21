// Jon Hays
// mightyfancy@gmail.com
// jhays
// assignment 8: Breadth-First Search
// last modified: 5/4/17
// MazeGraph.h
// MazeGraph class interface file
// working/tested

#ifndef __MAZEGRAPH_H
#define __MAZEGRAPH_H

#include <queue>
#include <vector>

// This class implements a graph along with a custom breadth-first search
// used to find the shortest path from the start to finish of square 
// nxn mazes. Public functions include a contructor which requires 
// a 1D char vector containing the maze data, and a function printPath which
// prints the shortest path in the form of (x,y) coordinates, one per line.
class MazeGraph {

 public:
  // Constructor takes a 1D char vector containing the hex values
  // that make up an nxn legal maze
  MazeGraph(const std::vector<char>& mazeArray);
  ~MazeGraph();
  // print shortest path from beginning (top left) to end (bottom right) of 
  // maze. Path is printed as "(x,y)" coordinates--one per line 
  void printPath() {printPath(0, numVertices - 1);}

 private:
  // Breadth-first search to find shortest path from start to finish of maze.
  // Shortest path is stored in the "parent[]" array
  void BFS();
  // private version of printPath; uses recursion to print path starting
  // at s and ending at v
  void printPath(int s, int v);
  // gives index of vertex that is adjacent to wall "wall", at
  // the vertex with index, u. 
  int adjacent(int u, int wall);
  // returns true if vertex at index u has an adjacent maze element at
  // wall, "wall".
  bool hasAdjacent(int u, int wall);
  // Array that holds adjacency data--constructor converts maze characters
  // into integers (1-15) that are stored in this array
  int* Adj;
  // Contains the graph's parent values
  int* Parent;
  // Contains the graph's color values
  int* Color;
  // Contains the graph's distance values
  int* Distance;
  // Queue object used in BFS
  std::queue<int> Q;
  int numVertices;
  int n;
  static const int white = 0;
  static const int gray = 1;
  static const int black = 2;
  static const int maxAdjacencies = 4; 
  static const int right = 1;
  static const int left = 4;
  static const int top = 8;
  static const int bottom = 2;
  static const int wallValues[];

};


#endif
