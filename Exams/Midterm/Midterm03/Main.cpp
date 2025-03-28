/**********************************************
 * Midterm 03
 * Written by Mark Bowman
 * DO NOT CHANGE 
 **********************************************/

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

#include "Train.h"

/**********************************************
 * main()
 **********************************************/
int main()
{ int pos;
  string fname,s;
  fstream f;
  train t;

// Open file

  cout << "Enter input file: ";
  cin >> fname;

  f.open(fname,ios::in);

// Load pods onto train

  while(!f.eof())
    { f >> s;
      if(f.good()) t.add(pod(s));
    };

// Close file

  f.close();

// Display

  t.display(cout);

// Find

  cout << "Enter data to find: ";
  cin >> s;
  cout << endl;

  pos = t.find(pod(s));

  if(pos>0)
    cout << s << " found on Car " << pos << endl;
  else
    cout << s << " not found on train" << endl;

// Success

  return 0;
}
