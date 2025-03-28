/**********************************************
 * List Answers.cpp
 * Updated by Laith Assaf
 **********************************************/
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

#include "List.h"

/*****************************
 * Display
 *****************************/
void list::display(ostream &out)
{ node *p;

  // Check list

  if(head==NULL) return;

  // Loop through list

  p = head;
  do { 
       p->put(out);
       p = p->next;
     } while(p!=head);
     
  // Print empty line and then show current pointer
  out << endl;
  current->put(out);
}

/*****************************
 * Rotate
 *****************************/
void list::rotate(int n)
{ 
  int i;

  if (head==NULL) return;

  for (i=0; i<n; i++)
  {
    current = current->next;
  }
}

/*****************************
 * Forward
 *****************************/
void list::foreward(ostream &out)
{ out << "Forwards" << endl;
  out << "--------" << endl;

// Check list

  if(head!=NULL) current->fore(out,current);
}

/*****************************
 * Backward
 *****************************/
void list::backward(ostream &out)
{ out << "Backwards" << endl;
  out << "---------" << endl;

  // Check list
  if(head!=NULL) current->back(out,current);
}