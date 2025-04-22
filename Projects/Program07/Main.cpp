/***********************************
 * Program 07
 * Written by Mark M Bowman
 ***********************************/ 

#include <iostream>
#include <string>
#include <fstream>
using namespace std;

#include "Graph.h"

/****************************
 * main()
 ****************************/
int main()
{ int dist;
  string fname,s,t;
  char method;
  fstream in;
  graph g;

// Open file

  cout << "Enter file name: ";
  cin >> fname;
  in.open(fname.data(),ios::in);

// Load file

  while(!in.eof())
    { in >> s >> t >> dist;
      if(in.good()) g.insert(s,t,dist);
    };

// Close file

  in.close();
  cout << endl;

// Loop to display graph

  method = 0;

  while(method!='Q')
    {

// Menu

      cout << "S)how, D)epth, B)readth, P)ath, Q)uit: ";
      cin >> s;
      method = toupper(s[0]);

// Show

      if(method=='S') g.show(cout);

// Depth

      if(method=='D')
        { cout << "Enter node: ";
          cin >> s;
          g.depth(cout,s);
        };

// Breadth

      if(method=='B')
        { cout << "Enter node: ";
          cin >> s;
          g.breadth(cout,s);
        };

// Path

      if(method=='P')
        { cout << "Enter start node: ";
          cin >> s;
          cout << "Enter finish node: ";
          cin >> t;
          g.path(cout,s,t);
        };

// End of main loop

//      cout << endl;
    };

// Done

  cout << "Thank you!" << endl;

}
