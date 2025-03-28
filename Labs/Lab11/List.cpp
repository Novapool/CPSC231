/**********************************************
 * List.cpp
 * Written by Mark M Bowman
 **********************************************/
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

#include "List.h"

/**********************************************
 * Constructor
 **********************************************/
list::list()
{ head = NULL;
}

/**********************************************
 * Destructor
 **********************************************/
list::~list()
{ node *p,*q;

// Check list

  if(head==NULL) return;

// Loop through list

  p = head;
  do { q = p;
       p = p->next;
       delete q;
     } while(p!=head);
}

/*****************************
 * Insert
 *****************************/
bool list::insert(string arg)
{ node *p;

// Create a node
  
  p = new node(arg);
  if(p==NULL) return false;

// Add to empty list

  if(head==NULL)
    { head = current = p;
      p->next = head;
      return true;
    };

// Add at current position

  p->next = current->next;
  current->next = p;
  current = p;
  return true;
}
