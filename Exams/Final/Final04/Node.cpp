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
void node::insert(node *p)
{

// Left side

  if(p->val<=val)
    { if(left!=NULL)            // Recurse left
        left->insert(p);
      else                      // Add node here
        left = p;
     }

// Right side

   else
     { if(right!=NULL)          // Recurse right
         right->insert(p);
       else                     // Add node here
         right = p; 
     };
}

/*******************************
 * lmr()
 *******************************/
void node::mlr()
{ cout << val << " ";
  if(left!=NULL) left->mlr();
  if(right!=NULL) right->mlr();
}

/*******************************
 * count()
 *******************************/
int node::count()
{ int val = 1;
  if(left!=NULL) val += left->count();
  if(right!=NULL) val += right->count();
  return val;
}

/*******************************
 * depth()
 *******************************/
int node::depth()
{ int l,r;
  l = r = 0;
  if(left!=NULL) l = left->depth();
  if(right!=NULL) r = right->depth();
  return max(l,r)+1;
}
