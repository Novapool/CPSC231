// Tree Functions

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

#include "Tree.h"

/****************************
 * tree()
 ****************************/
tree::tree()
{ int i;
  for(i=0;i<TREE_MAX;i++) map[i] = "";
}

/****************************
 * insert()
 ****************************/
bool tree::insert(string s)
{ int pos;

// Start at root

  pos = 0;

// Loop left/right

  while(pos<TREE_MAX && map[pos]!="")
    { if(s<=map[pos])
        pos = left(pos);
      else
        pos = right(pos);
    };

// Fail if past bottom

  if(pos>=TREE_MAX) return false;

// Set node

  map[pos] = s;
  return true;
}

/****************************
 * dump()
 ****************************/
void tree::dump()
{ int i,n;

// Get max position

  for(i=0;i<TREE_MAX;i++)
    if(map[i]>"")
      n = i;

// Display up to max

  cout << std::left;
  for(i=0;i<=n;i++)
    cout << setw(4) << i << map[i] << endl;
}

/****************************
 * show()
 ****************************/
void tree::show(string arg)
{ if(arg=="LMR") lmr(0);
//  if(arg=="RML") rml(0);
//  if(arg=="MLR") mlr(0);
}

/****************************
 * depth()
 ****************************/
int tree::depth()
{ return depth_recurse(0)-1;
}
