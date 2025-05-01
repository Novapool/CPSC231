#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

#include "Hash Table.h"

/****************************
 * Constructor
 ****************************/
hash_table::hash_table(int arg)
{ len = cap = count = 0;
  map = new node[arg];
  if(map!=NULL)  cap = arg;
}

/****************************
 * Destructor
 ****************************/
hash_table::~hash_table()
{ if(map!=NULL) delete [] map;
}

/****************************
 * dump()
 ****************************/
void hash_table::dump(ostream &out)
{ int i;
  for(i=0;i<cap;i++)
    { out << right << setw(3) << i << " | ";
      if(map[i].flag) map[i].put(out);
      out << endl;
    };
  out << endl;
}

/****************************
 * dump()
 ****************************/
int hash_table::collisions()
{ return count;
}
