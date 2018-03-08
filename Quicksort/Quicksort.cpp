// Jon Hays
// mightyfancy@gmail.com
// jhays
// assignment 3 - Quicksort
// last modified 3/3/17
// Implementation of Quicksort using both Lomuto and Hoare
// partitioning schemes
// code status: working/tested

#include <iostream>
#include <vector>
#include <iomanip>


using std::vector;
using std::cin;
using std::cout;
using std::endl;

const int MEDIANTHRESHOLD = 4;

void Quicksort(vector<int>&, int, int);
void hoareQuicksort(vector<int>&, int, int);
int hoarePartition(vector<int>&, int, int);
int partition(vector<int>&, int, int);
int medOf3(vector<int>&, int, int);
void swap(vector<int>&, int, int);


// Lomuto partitioning scheme Quicksort function
void Quicksort(vector<int>& A, int first, int last) {
  if (first < last) {
    //create hi and lo partitions
    //first and last (and q) refer to indices of array/partitions
    int divider = partition(A, first, last); 
    Quicksort(A, first, divider-1); //recursively sort lo partition
    Quicksort(A, divider+1, last); //recursively sort hi partition
  } //if
}


// Hoare partitioning scheme Quicksort function
void hoareQuicksort(vector<int>& A, int first, int last) {
  if (first < last) {
    int divider = hoarePartition(A, first, last);
    hoareQuicksort(A, first, divider);
    hoareQuicksort(A, divider + 1, last);
  } //if
}

// Lomuto partitioning function
int partition(vector<int>& A, int first, int last) {
  if (A.size() >= MEDIANTHRESHOLD) {
    int pivotIndex = medOf3(A, first, last); //assign pivot index
    swap(A, last, pivotIndex);
  }
  int pivot = A[last];
  int i = first - 1;
  for (int j = first; j < last; j++) {
    if (A[j] <= pivot) {
      i++;
      swap(A, i, j);
    }//if
  }//for
  swap(A, i+1, last);
  return i+1;
}//partition()


//Hoare partitioning function
int hoarePartition(vector<int>& A, int first, int last) {
  if (A.size() >= MEDIANTHRESHOLD) {
    int pivotIndex = medOf3(A, first, last); //assign pivot index
    swap(A, first, pivotIndex);
  }
  int pivot = A[first];
  int i = first - 1;
  int j = last + 1;
  while (true) {
    do { 
      i++;
    } while (A[i] < pivot);
    do {
      j--;
    } while (A[j] > pivot);
    if (i >= j) return j;
    swap(A, i, j);
  }
}

// Takes first, last, and 'midpoint' values of vector,
// and return index of the median value (to be used as pivot)
int medOf3(vector<int>& A, int first, int last) {
  int mid = first + (last-first)/2; // prevent int overflow
  if ((A[first] >= A[mid] && A[first] <= A[last])
      || (A[first] <= A[mid] && A[first] >= A[last]))
    mid = first;
  if ((A[last] >= A[mid] && A[last] <= A[first])
      || (A[last] <= A[mid] && A[last] >= A[first]))
    mid = last;
  return mid;
}

// swap two values of A at indices n and k
void swap(vector<int>& A, int n, int k) {
  int temp = A[n];
  A[n] = A[k];
  A[k] = temp;
}


// main program loop; takes in unspecified number of 9-digit zero
// padded positive integer inputs, and then sends 
// them to STDOUT in ascending order
int main(int argc, char **argv) {
  int data;
  vector<int> A;
  while (cin >> data)
    A.push_back(data);
  int size = A.size();
  if (argc >= 2)
    hoareQuicksort(A, 0, size - 1);
  else 
    Quicksort(A, 0, size - 1);
  for (int i = 0; i < size; i++)
    cout << std::setw(9) << std::setfill('0') << A[i] << endl;
}
