/***********************************
 * Program 03
 * Written by Mark M Bowman
 ***********************************/ 

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

#include "List.h"

/***********************************
 * Main
 * Test function - DO NOT CHANGE
 ***********************************/ 
int main()
{ int id,age;
  float gpa;
  list a;
  node *p;
  string fname,first,last;
  fstream infile;

// Get file name

  cout << "Enter file name: ";
  cin >> fname;

// Open file

  infile.open(fname,ios::in);

// Loop through file

  while(!infile.eof())
    { infile >> id >> first >> last >> age >> gpa;
    
// Process if okay

      if(infile.good())
        a.insert(id,first,last,age,gpa);
    };

// Close

  infile.close();
  cout << endl << a.length() << " nodes" << endl;

// Find node

  cout << endl;
  cout << "Enter ID: ";
  cin >> id;

  p = a.find(id);
  if(p!=NULL)
    p->put(cout);
  else
    cout << "Not found" << endl;

// Remove from list

  cout << endl << "Remove: ";
  if(a.remove(id))
    { cout << "Success!" << endl;
      cout << a.length() << " nodes" << endl;
    }
  else
    cout << "Fail" << endl;

// Display forwards

  cout << endl;
  cout << "Forwards List\n--------------\n";
  a.forwards(cout);
  cout << endl;

// Display backwards

  cout << "Backwards List\n--------------\n";
  a.backwards(cout);
  cout << endl;

// Success

  return 0;
}
