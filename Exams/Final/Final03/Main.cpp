/*********************************
 * Main.cpp
 * DO NOT CHANGE 
 *********************************/
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

#include "List.h"

/*********************************
 * main()
 *********************************/
int main()
{ string fname,s,start,stop;
  fstream in;
  list a,b,c;

// Load data

  cout << "Enter file name A: ";
  cin >> fname;
  a.load(fname);

  cout << "Enter file name B: ";
  cin >> fname;
  b.load(fname);
  cout << endl;

// Display

  cout << "A = ";
  a.output(cout);

  cout << "B = ";
  b.output(cout);

// Combine

  c.combine(a,b);

// Display

  cout << "C = ";
  c.output(cout);

  return 0;
}


