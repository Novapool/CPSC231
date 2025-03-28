/**********************************************
 * Lab 16
 * Written by Mark M Bowman
 **********************************************/

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

#include "Tree.h"

/**********************************************
 * main
 **********************************************/
int main()
{ int pos;
  string fname,s;
  fstream infile;
  tree t;

// Open file

  cout << "Enter file name: ";
  cin >> fname;
  infile.open(fname.data(),ios::in);

// Loop through file

  while(!infile.eof())
    { infile >> s;
      if(infile.good()) t.insert(s);
    };

// Close file

  infile.close();

// Display tree dump

  cout << "Depth = " << t.depth() << endl << endl;
  t.dump();
  cout << endl;


// Display tree in LMR order

  t.show("LMR");
  cout << endl;


/* STEP 6
// Display tree in order

  cout << "Enter display order (LMR,RML,MLR): ";
  cin >> s;

  t.show(s);
  cout << endl;
*/

/* STEP 8
// Find

  cout << "Enter string to find: ";
  cin >> s;
  
  pos = t.find(s);
  if(pos!=TREE_ERR)
    cout << s << " found at position " << pos << endl;
  else  
    cout << s << " not found" << endl;
*/

// Success

  return 0;
}
