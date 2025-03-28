/**********************************************
 * Node.cpp
 * Written by Mark M Bowman
 **********************************************/
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

#include "Node.h"

/**********************************************
 * Constructor
 **********************************************/
node::node(string arg)
{ name = arg;
  next = NULL;
}

/*****************************
 * Output
 *****************************/
void node::put(ostream &out)
{ out << setw(12) << this;
  out << setw(8) << name;
  out << setw(10) << next << endl;
}

