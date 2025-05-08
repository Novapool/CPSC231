/************************************
 * Main.cpp
 * DO NOT CHANGE
 ************************************/
#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;

#define ARRAY_MAX  100

void quicksort(string map[],int n);

int counter_comp,counter_swap;

/******************************
 * main()
 ******************************/
int main()
{ int i,n;
  string fname,name,map[ARRAY_MAX];
  fstream in;

// Initialize

  n = counter_comp = counter_swap = 0;

// Get file name

  cout << "Enter file name: ";
  cin >> fname;

// Read from file

  in.open(fname.data(),ios::in);
  if(!in.is_open()) return -1;

  while(!in.eof())
    { in >> name;
      if(in.good()) map[n++] = name;
   };

  in.close();

// Display array

  cout << endl;
  cout << "Unsorted Array" << endl << "----------------" << endl;
  for(i=0;i<n;i++)
    cout << map[i] << " ";
  cout << endl;

// Sort

  quicksort(map,n);

// Display

  cout << endl;
  cout << "Sorted Array" << endl << "----------------" << endl;
  for(i=0;i<n;i++)
    cout << map[i] << " ";
  cout << endl;

// Stats

  cout << endl;
  cout << "       N = " << n << endl;
  cout << "Compares = " << counter_comp << endl;
  cout << "   Swaps = " << counter_swap << endl;

// Success

  return 0;
}
