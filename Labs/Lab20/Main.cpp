/************************************
 * Lab20.cpp
 * Updated by Laith Assaf
 ************************************/
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

#define ARRAY_MAX  1000

#include "Heapsort.h"

/******************************
 * main()
 ******************************/
int main()
{ int i,n;
  string fname,name,map[ARRAY_MAX];
  fstream in;

// Initialize
  n = 0;

// Get file name
  cout << "Enter file name: ";
  cin >> fname;

// Read from file
  in.open(fname.data(),ios::in);
  if(!in.is_open()) return -1;

// Loop through file - store in original order
  while(!in.eof())
    { in >> name;
      if(in.good()) map[n++] = name;
   };

// Close file
  in.close();

// Display array before heapify
  cout << endl;
  cout << "Array before heapify" << endl << "----------------" << endl;
  for(i=0;i<n;i++)
    cout << map[i] << " ";
  cout << endl << endl;

// Call heapify
  heapify(map, n);

// Display array after heapify
  cout << "Array after heapify" << endl << "----------------" << endl;
  for(i=0;i<n;i++)
    cout << map[i] << " ";
  cout << endl << endl;

// Call heap_sort
  heap_sort(map, n);

// Display array after heap_sort
  cout << "After Sort" << endl << "----------------" << endl;
  for(i=0;i<n;i++)
    cout << map[i] << " ";
  cout << endl;

// Success
  return 0;
}