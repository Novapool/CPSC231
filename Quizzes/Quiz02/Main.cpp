/************************************
 * Quiz 02
 * Written by Mark M Bowman
 ************************************/

#include <iostream>
#include <fstream>
using namespace std;

#include "List.h"

/*******************************
 * main()
 *******************************/
int main()
{ int i;
  string fname,s;
  fstream f;
  list a;

// Open data file

  cout << "Enter data file: ";
  cin >> fname;
  f.open(fname,ios::in);
  if(!f.is_open()) return -1;

// Insert data into list

  while(!f.eof())
    { f >> s;
      if(f.good()) a.insert(s);
    };

// Close file

  f.close();

// Display list

  cout << "Before\n------\n";
  a.display(cout);
  cout << endl;

// Remove matching strings from list

  cout << "Enter string to remove: ";
  cin >> s;

  i = a.remove(s);

  cout << i << " strings removed" << endl << endl;

// Display list

  cout << "After\n------\n";
  a.display(cout);

// Success

  return 0;
}
