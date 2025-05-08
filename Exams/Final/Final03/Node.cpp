/*********************************
 * Node.cpp
 * DO NOT CHANGE
 *********************************/
#include <iostream>
#include <string>
using namespace std;

#include "Node.h"

/*********************************
 * Constructor
 *********************************/
node::node(string arg)
{ data = arg;
  next = NULL;
}

/*********************************
 * Destructor
 *********************************/
node::~node()
{ if(next!=NULL) delete next;
}

/*********************************
 * Append
 *********************************/
void node::append(node_ptr p)
{ if(next!=NULL)
    next->append(p);
  else
    next = p;
}

/*********************************
 * Output
 *********************************/
void node::output(ostream &out)
{ out << data << " ";
  if(next!=NULL) next->output(out);  
}

