/**********************************************
 * Node.cpp
 * Updated by YOUR NAME GOES HERE
 **********************************************/
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

#include "Node.h"

/**********************************************
 * Constructor
 **********************************************/
node::node(string args)
{ cerr << this << " Constructed" << endl;
  name = args;
  next = NULL;
}

/**********************************************
 * Destructor
 **********************************************/
node::~node()
{ cerr << this << " Destructed" << endl;
  if(next!=NULL) delete next;
}

/*****************************
 * Add node link
 *****************************/
void node::add(node *argp)
{ 
  if(next!=NULL) 
    next->add(argp);
  else
    next = argp;

}

/*****************************
 * Output
 *****************************/
void node::put(ostream &out)
{ 
  out << setw(13) << this;
  out << setw(8) << name;
  out << setw(10) << next << endl;
}

/**********************************************
 * Forwards traversal with output
 **********************************************/
void node::forwards(ostream &out)
{ 
  // Output current node's name
  put(out);
  
  // Recursively call forwards on the next node if it exists
  if(next != NULL)
    next->forwards(out);
}

/**********************************************
 * Backwards traversal with output
 **********************************************/
void node::backwards(ostream &out)
{ 
  // Recursively call backwards on the next node if it exists
  if(next != NULL)
    next->backwards(out);
  
  // Output current node's name
  put(out);
}