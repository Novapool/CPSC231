/***********************************
 * Program 06
 * DO NOT CHANGE
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

// Get order
  
  cout << "Order to display (LMR,MLR,RML): ";
  cin >> order;
  cout << endl;

// Display 

  cout << order << " Order\n--------------\n";
  t.show(order,cout);
  cout << endl;

// Find node

  cout << "Enter value to find: ";
  cin >> s;

  cout << endl << "Find: ";
  if(t.find(s))
    { cout << s << " found!" << endl;
    }
  else
    cout << s << " not found" << endl;

// Remove node

  cout << "Remove: ";
  if(t.remove(s))
    cout << s << " removed" << endl;
  else
    cout << s << " not removed" << endl;
  cout << endl;

// Display again

  cout << order << " Order\n--------------\n";
  t.show(order,cout);

// Success

  return 0;
}