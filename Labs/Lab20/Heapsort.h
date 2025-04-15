/************************************
 * Heapsort.h
 * Written by YOUR NAME GOES HERE
 ************************************/

#include <iostream>
#include <string>
using namespace std;

// Heap sort functions

inline int heap_left(int pos);
inline int heap_right(int pos);
inline int heap_parent(int pos);

void heap_insert(string map[],int &n,string value);
string heap_remove(string map[],int &n);

void heapify(string map[],int n);
void heap_sort(string map[],int n);
