/************************************
 * Node.cpp
 * Written by Mark M Bowman
 ************************************/

#include <iostream>
#include <string>
using namespace std;

#include "Node.h"

/*******************************
 * Constructor
 *******************************/
node::node(string arg)
{ val = arg;
  left = right = NULL;
}

/*******************************
 * Destructor
 *******************************/
node::~node()
{ if(left!=NULL) delete left;
  if(right!=NULL) delete right;
}

/*******************************
 * insert()
 *******************************/
void node::insert(string arg)
{

// Left side

  if(arg<=val)
    { if(left!=NULL)            // Recurse left
        left->insert(arg);
      else                      // Add node here
        left = new node(arg);
     }

// Right side

   else
     { if(right!=NULL)          // Recurse right
         right->insert(arg);
       else                     // Add node here
         right = new node(arg); 
     };
}

/*******************************
 * lmr()
 *******************************/
void node::lmr()
{ if(left!=NULL) left->lmr();
  cout << val << endl;
  if(right!=NULL) right->lmr();
}
