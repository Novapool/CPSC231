/************************************
 * Set.cpp
 * Written by Laith Assaf
 ************************************/
#include <iostream>
using namespace std;

#include "Set.h"

/**************************************
 * Constructor
 **************************************/
template <class item>
set<item>::set()
{ n = 0;
}

/**************************************
 * Put
 **************************************/
template <class item>
void set<item>::put(ostream &out)
{ int i;
  cout << "(";
  if(n>0) cout << data[0];
  for(i=1;i<n;i++)
    out << ',' << data[i];
  cout << ")";
}

/**************************************
 * Operator +=
 **************************************/
template <class item>
bool set<item>::insert(item arg)
{ int i,j;

// No room

  if(n>=SET_MAX) return false;

// Find position

  for(i=0;i<n && arg>data[i];i++);
  if(i<n && arg==data[i]) return false;

// Shift

  for(j=n;j>i;j--) data[j] = data[j-1];

// Add element

  data[i] = arg;
  n++;

// Success

  return true;
}


/**************************************
 * Operator +
 * Creates a new set containing all elements
 * from both sets without duplicates
 **************************************/
template <class item>
set<item> set<item>::operator +(const set<item> &arg)
{
    set<item> result;
    int i;
    
    // Insert all elements from first set
    
    for (i = 0; i < n; i++)
    {
        result.insert(data[i]);
    }
    
    // Insert all elements from second set
    // insert() will maintain order and eliminate duplicates
    
    for (i = 0; i < arg.n; i++)
    {
        result.insert(arg.data[i]);
    }
    
    // Return combined set
    
    return result;
}
