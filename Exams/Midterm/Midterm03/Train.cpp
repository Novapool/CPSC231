/**********************************************
 * Train.cpp
 * Written by Mark Bowman
 * DO NOT CHANGE 
 **********************************************/
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

#include "Train.h"

/**********************************************
 * Constructor
 **********************************************/
train::train()
{ head = NULL;
}

/**********************************************
 * Destructor
 **********************************************/
train::~train()
{ if(head!=NULL) delete head;
}

/*****************************
 * Display
 *****************************/
void train::display(ostream &out)
{ out << endl;
  if(head!=NULL) head->fore(out);
  out << endl;
}
