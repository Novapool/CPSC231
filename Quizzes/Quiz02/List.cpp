/************************************
 * List.cpp
 * Written by Mark Bowman
 ************************************/
#include <iostream>
using namespace std;

#include "List.h"

/**************************************
 * Constructor
 **************************************/
list::list()
{ len = 0;
  data = new string[ARRAY_MAX];
}

/**************************************
 * Constructor
 **************************************/
list::~list()
{ if(data!=NULL) delete [] data;
}

/**************************************
 * Put
 **************************************/
void list::display(ostream &out)
{ int i;
  for(i=0;i<len;i++)
    out << data[i] << " ";
  cout << endl;
}
