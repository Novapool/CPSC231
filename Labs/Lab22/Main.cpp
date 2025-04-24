/************************************
 * Lab22.cpp
 * Written by YOUR NAME GOES HERE
 ************************************/
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
using namespace std;

#include "Node.h"

/******************************
 * main()
 ******************************/
int main()
{ int i,n;
  int source_index,target_index,distance;
  string fname,source_name,target_name;
  fstream in;
  node map[NODE_MAX];

// Initialize

  n = 0;
  cout << left;

// Get file name

  cout << "Enter file name: ";
  cin >> fname;

// Open file

  in.open(fname,ios::in);

// Loop through file

  while(!in.eof())
    { in >> source_name >> target_name >> distance;
      
// Add to array 

      if(in.good())
        { cout << setw(12) << source_name;
          cout << setw(12) << target_name;
          cout << setw(4) << distance;
          cout << endl;
        }; 
    };
 
// Close file

  in.close();

// Display array

  for(i=0;i<n;i++)
    cout << map[i].get_value() << endl;

// Success

  return 0;
}
