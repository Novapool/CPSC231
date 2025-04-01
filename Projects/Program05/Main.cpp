/***********************************
 * Program 05
 * Written by Mark M Bowman
 ***********************************/ 

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

#include "Tree.h"

/***********************************
 * Main
 * Test function - DO NOT CHANGE
 ***********************************/ 
int main()
{ tree t;
  string fname,s,order;
  fstream infile;

// Get file name

  cout << "Enter file name: ";
  cin >> fname;
  cout << endl;

// Open file

  infile.open(fname,ios::in);

// Loop through file

  while(!infile.eof())
    { infile >> s;
    
// Process if okay

      if(infile.good())
        t.insert(s);
    };

// Close

  infile.close();

// Display order
  
  order = "LMR";

// Display 

  cout << order << " Order\n--------------\n";
  t.show(order,cout);
  cout << endl;

// Find node

  cout << endl;
  cout << "Enter value to find: ";
  cin >> s;

  cout << endl << "Find: ";
  if(t.find(s))
    { cout << s << " found!" << endl;
    }
  else
    cout << s << " not found" << endl;

// Success

  return 0;
}
