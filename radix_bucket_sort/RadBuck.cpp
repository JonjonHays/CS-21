// Jon Hays
// mightyfancy@gmail.com
// jhays
// Assignment 4 -- Radix/Bucket Sort Hybrid
// last modified: 3/5/2017
// RadBuck.cpp
// Sorts unspecified number of 9-digit zero padded entries in 
// linear (O(n)) time.
// Status: working/tested

#include <iostream>
#include <iomanip>
#include <cmath>
#include <vector>

using std::vector;
using std::cin;
using std::cout;
using std::endl;


// This function implements an O(n) combination Radix/Bucket sort.
// Inputs vector, A, by reference, radix value, and number 
// of digits per entry. (radix is the number of possibilities 
// per digit--i.e. if digits can be 0-9, radix == 10)
void RadixBucketSort(vector<int>& A, int radix, int ndigits) {
  int dataSize = A.size();
  int index;
  int digit;
  int size = 0;
  for (int i=1; i <= ndigits; i++) {
    vector<int>* buckets = new vector<int>[radix];
    index = 0;
    for (int j=0; j < dataSize; j++) {
      digit = int(A[j]/pow(10, i-1)) % 10; //ith digit of A[j]
      buckets[digit].push_back(A[j]); //insert A[j] to end of buckets[digit]
    } //for j_1
    for (int j=0; j < radix; j++) { //add items from bucket[j] into A
      size = buckets[j].size();
      for (int k = 0; k < size; k++) {
	A[index] = buckets[j][k];
	index++;
      } //for k
    } //for j_2
    delete [] buckets;
  } //for i
}

// Main program loop--takes unspecified number of input values (9-digit,
// zero padded, one per line) from STDIN, and outputs sorted values 
// (one per line) to STDOUT.
int main() {
  const int D = 9;
  const int R = 10;
  int data;
  vector<int> A;
  while (cin >> data)
    A.push_back(data);
  int size = A.size();
  RadixBucketSort(A, R, D);
  for (int i = 0; i < size; i++)
    cout << std::setw(9) << std::setfill('0') << A[i] << endl;
}
