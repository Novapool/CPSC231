/************************************
 * Lab22.cpp
 * Written by YOUR NAME GOES HERE
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
  for(i=0;i<EDGE_MAX;i++)
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
