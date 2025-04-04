/************************************
 * Quiz03.cpp
 * Written by Mark M Bowman
 ************************************/

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

#include "Node.h"

/*******************************
  Main program
 *******************************/
int main()
{ string fname,s;
  fstream in;
  node *root;

// Initialize

  root = NULL;

// Get user input

  cout << "Enter file name: ";
  cin >> fname;
  cout << endl;

// Open file

  in.open(fname.data(),ios::in);

// Loop through file

  while(!in.eof())
    { in >> s;
      if(in.good())
        { if(root==NULL)
            root = new node(s);
          else
            root->insert(s);
        };
    };

// Close file

  in.close();

// Display tree

  cout << "Entire Tree" << endl;
  root->lmr();
  cout << endl << endl;

// Find

  cout << "Enter string to find: ";
  cin >> s;
  root->path(s);

// Success

  return 0;
}
