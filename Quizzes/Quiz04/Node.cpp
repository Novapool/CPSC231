/***********************************
 * Node function definitions
 * DO NOT CHANGE
 ***********************************/ 

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

#include "Node.h"

/**********************************
 * Constructor
 **********************************/
node::node(int arg)
{ data = arg;
  left = right = NULL;
}

/**********************************
 * Destructor
 **********************************/
node::~node()
{ if(left!=NULL) delete left;
  if(right!=NULL) delete right;
}

/**********************************
 * Put
 **********************************/
void node::put(ostream &out)
{ out << setw(4) << data;
}

/**********************************
 * LMR
 **********************************/
void node::lmr(ostream &out)
{ if(left!=NULL) left->lmr(out);
  put(out);
  if(right!=NULL) right->lmr(out);
}

/**********************************
 * MLR
 **********************************/
void node::mlr(ostream &out)
{ put(out);
  if(left!=NULL) left->mlr(out);
  if(right!=NULL) right->mlr(out);
}

/**********************************
 * RML
 **********************************/
void node::rml(ostream &out)
{ if(right!=NULL) right->rml(out);
  put(out);
  if(left!=NULL) left->rml(out);
}
