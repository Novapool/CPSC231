/**********************************************
 * Node Answers.cpp
 * Updated by Laith Assaf
 **********************************************/
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

#include "Node.h"

/*****************************
 * Fore
 * display the node, 
 * then recurse if its next pointer 
 * isn’t the same as the argument pointer.
 *****************************/
void node::fore(ostream &out,node *arg)
{ 
  out << setw(12) << this;
  out << setw(8) << name;
  out << setw(10) << next << endl;
  if(next!=arg) next->fore(out,arg);
}

/**********************************************
 * Back
 * display the node, 
 * then recurse if its previous pointer 
 * isn't the same as the argument pointer.
 **********************************************/
void node::back(ostream &out, node *arg)
{ 
  out << setw(12) << this;
  out << setw(8) << name;
  out << setw(10) << prev << endl;
  if(prev != arg) prev->back(out, arg);
}