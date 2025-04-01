/************************************
 * Node.cpp
 * Written by Mark M Bowman
 ************************************/

#include <iostream>
using namespace std;

#include "Node.h"

/*******************************
 * Constructor
 *******************************/
node::node(int arg1)
{ val = arg1;
  left = right = NULL;
}

/*******************************
 * Destructor
 *******************************/
node::~node()
{ if(left!=NULL) delete left;
  if(right!=NULL) delete right;
}
