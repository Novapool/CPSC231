/***********************************
 * Main.cpp
 * DO NOT CHANGE
 ***********************************/ 

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

#include "Tree.h"

/***********************************
 * Main
 ***********************************/ 
int main()
{ int val;
  string fname;
  fstream f;
  tree t;

// Get file

  cout << "Enter file: ";
  cin >> fname;
  cout << endl;

// Read from file

  f.open(fname,ios::in);
  while(!f.eof())
    { f >> val;
      if(f.good()) t.insert(val);
    }
  f.close();

// Display

  t.display(cout);
  return 0;
}
