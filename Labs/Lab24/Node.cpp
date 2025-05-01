/*********************************
 * Node class definitions
 *********************************/
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

#include "Node.h"

/*********************************
 * node()
 *********************************/
node::node()
{ id = 0;
  first = last = "";
  flag = false;
}

/*********************************
 * node()
 *********************************/
bool node::get(istream &in)
{ in >> id >> first >> last;
  flag = in.good();
  return flag;
}

/*********************************
 * put()
 *********************************/
void node::put(ostream &out)
{ if(!flag) return;
  out << left;
  out << setw(6) << id;
  out << setw(8) << first;
  out << setw(16) << last;
}
