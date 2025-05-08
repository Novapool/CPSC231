/*********************************
 * List.cpp
 * DO NOT CHANGE
 *********************************/
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

#include "List.h"

/*********************************
 * Constructor
 *********************************/
list::list()
{ head = NULL;
}

/*********************************
 * Destructor
 *********************************/
list::~list()
{ if(head!=NULL) delete head;
}

/*********************************
 * load()
 *********************************/
bool list::load(string fname)
{ string s;
  fstream in;
  node *p;

  in.open(fname,ios::in);
  if(!in.is_open()) return false;

  while(!in.eof())
    { in >> s;
      if(in.good())
        { p = new node(s);
          if(head==NULL)
            head = p;
          else
            head->append(p);
        };
    };

  in.close();
  return true;
}

/*********************************
 * Output
 *********************************/
void list::output(ostream &out)
{ if(head!=NULL) head->output(out);  
  out << endl;
}
