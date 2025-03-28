/*******************************
 * Box Class Definitions
 * Written by Laith Assaf 01-Jan-16
 *******************************/

#include <iostream>
using namespace std;

#include "Box.h"

/**************************************
 * Constructor - no parameters
 **************************************/
box::box()
{ cout << "Box " << this << " created\n";
  height = 0;
  width = 0;
  depth = 0;
}

/**************************************
 * Constructor - all parameters
 **************************************/
box::box(int h,int w,int d)
{ cout << "Box " << this << " created\n";
  height = h;
  width = w;
  depth = d;
}

/**************************************
 * Destructor - optional
 **************************************/
box::~box()
{ cout << "Box " << this << " destroyed\n";
}

/**************************************
 * Get
 **************************************/
bool box::get(istream &in)
{ in >> height;
  in >> width;
  in >> depth;
  return in.good();
}

/**************************************
 * Put
 * Display box dimensions/Share member object member variables
 **************************************/
void box::put(ostream &out)
{
  cout << height << " x " << width << " x " << depth;
}

/**************************************
 * Volume
 * Calculate volume
 **************************************/
int box::volume()
{ 
  return height * width * depth;
}

/**************************************
 * Surface
 * Calculate surface area
 **************************************/
int box::surface()
{ 
  return 2 * (height * width + height * depth + width * depth);
}
