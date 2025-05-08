/************************************
 * Node.cpp
 * Written by Mark M Bowman
 ************************************/

#include <iostream>
#include <string>
using namespace std;

#include "Tree.h"

/*******************************
 * Constructor
 *******************************/
tree::tree()
{ root = NULL;
}

/*******************************
 * Destructor
 *******************************/
tree::~tree()
{ if(root!=NULL) delete root;
}

/*******************************
 * insert()
 *******************************/
void tree::insert(string arg)
{ node *p;

// Create node

  p = new node(arg);
  if(p==NULL) return;

// Add

  if(root==NULL)
    root = p;
  else
    root->insert(p);
}

/*******************************
 * show()
 *******************************/
void tree::show()
{ if(root==NULL) return;

// LMR display

  root->mlr();
  cout << endl;

// Stats

  cout << "Count: " << root->count() << endl; 
  cout << "Depth: " << root->depth()-1 << endl; 
}

