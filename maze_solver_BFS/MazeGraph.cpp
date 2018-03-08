// Jon Hays
// mightyfancy@gmail.com
// jhays
// assignment 8: Breadth-First Search
// last modified: 5/4/17
// MazeGraph.cpp
// MazeGraph class implementation file
// working/tested

#include <iostream>
#include <string>
#include <cmath>
#include <queue>
#include <vector>
#include <climits>
#include "MazeGraph.h"

using std::cout;
using std::endl;
using std::to_string;

const int MazeGraph::wallValues[] = {right, left, top, bottom};

MazeGraph::MazeGraph(const std::vector<char>& mazeArray) { 
  numVertices = mazeArray.size();
  n = int(sqrt(numVertices));
  Adj = new int[numVertices];
  Parent = new int[numVertices];
  Color = new int[numVertices];
  Distance = new int[numVertices];
  for (int i = 0; i < numVertices; i++) {
    if (mazeArray[i] > 57)  //ascii hex conversions..
      Adj[i] = tolower(mazeArray[i]) - 87;
    else
      Adj[i] = mazeArray[i] - 48;
  } 
}

MazeGraph::~MazeGraph() {
  delete [] Adj;
  delete [] Parent;
  delete [] Color;
  delete [] Distance;
}

void MazeGraph::printPath(int s, int v) {
  BFS();
  std::string coordStr;
  // vector containing reversed coordinates--used to 
  // print coordinates in order from beginning to end
  std::vector<std::string> coordArray;
  int row;
  int col;
  while(v != s) {
    row = v / n;
    col = v % n;
    coordStr = '(' + to_string(col) + ", " + to_string(row) + ')';
    coordArray.push_back(coordStr);
    v = Parent[v];
  }
  // add source coordinate to coordArray vector
  //  v = Parent[v];
  row = v / n;
  col = v % n;
  coordStr = '(' + to_string(col) + ", " + to_string(row) + ')';
  coordArray.push_back(coordStr);
  int size = coordArray.size();
  for (int i = size-1; i>=0; i--) {
    cout << coordArray[i] << endl;
  }
}


void MazeGraph::BFS() {
  int s = 0;
  for (int i = s; i < numVertices; i++) {
    Color[i] = white;
    Parent[i] = -1;  // -1 represents "null" flag value
    Distance[i] = INT_MAX; //infinity
  }
  Color[s] = gray;
  Parent[s] = -1;
  Distance[s] = 0;
  Q.push(s);
  int u;
  int v;
  int wall;
  while (!Q.empty()) {
    u = Q.front(); Q.pop();
    for (int i = 0; i < maxAdjacencies; i++) {
      wall = wallValues[i];
      if (hasAdjacent(u, wall)) {
	v = adjacent(u, wall);
	if (Color[v] == white) {
	  Color[v] = gray;
	  Distance[v] = Distance[u] + 1;
	  Parent[v] = u;
	  Q.push(v);
	  }//if
      }//if
    } //for i
    Color[u] = black;
  } //while
}//BFS
  
  
bool MazeGraph::hasAdjacent(int u, int wall) {        // IS THIS BOUNDS CHECK NEEDED??
  //if last vertex, no adjacency at right wall
  // if first vertex, no adjacency at left wall
  if ((u == numVertices-1 && wall == right) || (u == 0 && wall == left))     
    return false;
  int adjID = Adj[u];
  if ((adjID & wall))
    return false;
  return true;
}

int MazeGraph::adjacent(int u, int wall) {
  if (wall == right)
    return u + 1;
  if (wall == left)
    return u - 1;
  if (wall == top)
    return u - n;
  if (wall == bottom)
    return u + n;
}
  

