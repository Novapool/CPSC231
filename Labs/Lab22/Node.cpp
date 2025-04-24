/************************************
 * Node.cpp
 * Written by Laith Assaf
 ************************************/
#include <iostream>
#include <string>
using namespace std;

#include "Node.h"

/******************************
 * Null constructor
 ******************************/
node::node()
{ int i;
  value = "";
  for(i=0; i<EDGE_MAX; i++)
    edge[i] = NULL;
}

/******************************
 * set_value()
 ******************************/
void node::set_value(string arg)
{ value = arg;
}

/******************************
 * get_value()
 ******************************/
string node::get_value()
{ return value;
}

/******************************
 * connect()
 * Add an edge to a node
 ******************************/
void node::connect(node* target, int dist)
{ int i;

  // Find first available edge slot
  for(i=0; i<EDGE_MAX; i++)
    { 
      if(edge[i] == NULL)
        { 
          edge[i] = target;
          distance[i] = dist;
          return;
        }
    }
}

/******************************
 * put()
 * Display node and its neighbors
 ******************************/
void node::put()
{ int i;

  // Display the node value
  cout << value << endl;
  
  // Display all connected nodes
  for(i=0; i<EDGE_MAX; i++)
    { 
      if(edge[i] != NULL)
        cout << "  " << edge[i]->get_value() << endl;
    }
}