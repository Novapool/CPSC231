/***********************************
 * Program 02
 * Written by Mark M Bowman
 ***********************************/ 

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
using namespace std;

#include "People.h"

/***********************************
 * Main
 * Test function - DO NOT CHANGE
 ***********************************/ 
int main()
{ int i;
  int list[4] = { 4732,1132,7437,6706 };
  string fname;
  person temp;
  people a;
  fstream infile;

// Get file name

  cout << "Enter data file name: ";
  cin >> fname;
  cout << endl;

// Read from file

  infile.open(fname,ios::in);
  while(temp.get(infile)) a.insert(temp);
  infile.close();

// Display list

  cout << "Initial List" << endl << endl;
  a.display(cout);

// Test find

  for(i=0;i<4;i++)
    { cout << "Find " << list[i] << " ";
      if(a.find(list[i]))
        cout << "Found";
      else
        cout << "Not Found";
      cout << endl;
    };
  cout << endl;

// Test remove

  for(i=0;i<4;i++) a.remove(list[i]);

// Display updated list

  cout << "Updated List" << endl << endl;
  a.display(cout);

/*** Extra Credit
// Dean's list

  cout << "Dean's List" << endl << endl;
  a.dean(cout);
***/

// Success

  return 0;
}
