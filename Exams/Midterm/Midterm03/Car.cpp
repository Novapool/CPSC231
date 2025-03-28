/**********************************************
 * Car.cpp
 * Written by Mark Bowman
 * DO NOT CHANGE 
 **********************************************/
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

#include "Car.h"

/*******************************
 * Constructor
 ******************************/
car::car(int arg)
{ id = arg;
  n = 0;
  next = NULL;
}

/*******************************
 * Destructor
 ******************************/
car::~car()
{ if(next!=NULL) delete next;
}

/*****************************
 * Put
 *****************************/
void car::put(ostream &out)
{ int i;
  out << left << setw(4) << id;
  out << setw(12) << this;
  for(i=0;i<n;i++) map[i].put(out);
  out << setw(10) << next << endl;
}

/*****************************
 * Fore
 *****************************/
void car::fore(ostream &out)
{ put(out);
  if(next!=NULL) next->fore(out);
}
