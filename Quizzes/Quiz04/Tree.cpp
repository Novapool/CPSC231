/***********************************
 * Tree function definitions
 * DO NOT CHANGE
 ***********************************/ 

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

#include "Tree.h"

/**********************************
 * Empty constructor
 **********************************/
tree::tree()
{ root = NULL;
}

/**********************************
 * Destructor
 **********************************/
tree::~tree()
{ if(root!=NULL) delete root;
}

/**********************************
 * Display
 **********************************/
void tree::display(ostream &out)
{ 
// Nothing to do

  if(root==NULL) return;

// LMR

  cout << "LMR: ";
  root->lmr(out);
  cout << endl;

// MLR

  cout << "MLR: ";
  root->mlr(out);
  cout << endl;

// RML

  cout << "RML: ";
  root->rml(out);
  cout << endl;
}
