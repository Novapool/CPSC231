/************************************
 * Main.cpp
 * Written by Mark M Bowman
 ************************************/

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

#include "Tree.h"

/*******************************
  Main program
 *******************************/
int main()
{ int i,n;
  string fname,s;
  string map[100];
  fstream in;
  tree t,u;

// Get user input

  cout << "Enter file name: ";
  cin >> fname;
  cout << endl;

// Open file

  in.open(fname.data(),ios::in);

// Loop through file

  while(!in.eof())
    { in >> s;
      if(in.good()) t.insert(s);
    };

// Close file

  in.close();

// Display tree

  cout << "Unbalanced Tree MLR\n-------------------" << endl;
  t.show();
  cout << endl;

// Dump to array

  n = t.dump(map);

  cout << "Array\n-------------------" << endl;
  for(i=0;i<n;i++)
    cout << map[i] << " ";
  cout << endl << endl;

// Insert array

  u.insert(map,n);

// Display tree

  cout << "Balanced Tree MLR\n-------------------" << endl;
  u.show();
  cout << endl;

// Success

  return 0;
}
