// Jon Hays
// mightyfancy@gmail.com
// jhays
// assignment 6: amazing Union-Find
// last modified 4/8/17
// Maze.cpp
// Maze generation class implementation file
// working/tested

#include <iostream>
#include <cstdlib>
#include <cmath>
#include <utility>
#include "Maze.h"

using std::cout;
using std::cerr;
using std::endl;
using std::hex;
using std::swap;

Maze::Maze(int m) {
  if (m < 3) {
    cerr << "Maze dimension must be greater than 3; please try again." << endl;
    exit(1);
}
  n = m;
  mazeSize = int(pow(n,2));
  S = new DisjointSet(mazeSize);
  M = new int[mazeSize];
  M[0] = 11;          // Initialize starting point of maze ('B')
  M[mazeSize-1] = 14; //Initialize end point of maze ('E') (see HexMaze_info.pdf)
  for (int i = 1; i < mazeSize-1; i++)
    M[i] = 15;        // Initialize all other spaces as blocks with all 4 walls ('F')
  indexArray = new int[mazeSize];
  for (int i = 0; i < mazeSize; i++) 
    indexArray[i] = i;
  render();          // build maze
}

Maze::~Maze() {
  delete [] M;
  delete [] indexArray;
  delete S;
}

void Maze::printMaze() {
  for (int i = 0; i < mazeSize; i++) {
    cout << hex << M[i];
    if ((i + 1) % n == 0)
      cout << endl;
  }
}


void Maze::render() {
  shuffleIndices();
  int i = 0;
  while(S->getNumSets() > 1) {
    clearWall(indexArray[i]);
    i++;
    if (i == mazeSize) i = 0;
  }
}

void Maze::clearWall(int i) {
  int wall;
  int adj;
  for (int j = 0; j < 2; j++) { //try to clear a wall twice before moving on
    wall = randWall(i);
    adj = adjacent(i, wall);
    if(!S->sameComponent(i, adj)) {
      M[i] = M[i] - wall;
      M[adj] = M[adj] - opposite(wall);
      S->Union(i, adj);
      return;
    }
  }
}

int Maze::randWall(int i) {
  int wall;
  do {
    wall = wallValues[rand() % 4];
  } while (!hasAdjacent(i, wall));
  return wall;
}

int Maze::adjacent(int i, int wall) {
  if (wall == right)
    return i + 1;
  if (wall == left)
    return i - 1;
  if (wall == top)
    return i - n; 
  if (wall == bottom)
    return i + n;
}

bool Maze::hasAdjacent(int i, int wall) {
  if ((wall == right && i + 1 < mazeSize && (i + 1) % n != 0)
      || (wall == left && i - 1 >= 0 && i % n != 0)
      || (wall == top && i - n >= 0)
      || (wall == bottom && i + n < mazeSize))
      return true;
  return false;
}

int Maze::opposite(int wall) { //returns value of opposite wall
  if (wall == right)
    return left;
  if (wall == left)
    return right;
  if (wall == top)
    return bottom;
  if (wall == bottom)
    return top;
}

void Maze::shuffleIndices() {
  int randIndex;
  for (int i = 0; i < mazeSize; i++) {
    randIndex = rand() % mazeSize;
    swap(indexArray[i], indexArray[randIndex]);
  } 
}

const int Maze::wallValues[] = {right, left, top, bottom};

