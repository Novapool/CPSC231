#include <iostream>
#include <string>
using namespace std;

#include "Queue.h"

/**************************************
 * Constructor
 * construct the queue
 **************************************/
Queue::Queue()
{ head = tail = NULL;
}

/**************************************
 * Destructor
 * destruct the queue
 **************************************/
Queue::~Queue()
{ if(head!=NULL) delete head;
}

/**************************************
 * Push
 * create a new node and add it to the queue
 * if the queue is empty, set head and tail to the new node
 * otherwise, set the next pointer of the tail to the new node
 **************************************/
void Queue::push(string arg)
{ 
  node *p;
  p = new node(arg);
  if(head == NULL)
  {
    head = p;
    tail = p;
  }
  else
  {
    tail->next = p;
    tail = p;
  }

}

/**************************************
 * Pop
 * return if the first node is NULL
 * set the head to the next node and delete the first node
 * if the queue is empty, set tail to NULL since it is empty
 **************************************/
void Queue::pop()
{ 
  node *p;
  if(head == NULL) return;  // Handle empty queue case
  
  p = head;
  head = head->next;
  p->next = NULL;
  
  delete p;  
  if(head == NULL) tail = NULL;  // Update tail if queue is now empty
}

/**************************************
 * Front
 * return the value of the first node
 **************************************/
string Queue::front()
{ 
  return head->value;
}

/**************************************
 * Empty
 * return true if the queue is empty
 **************************************/
bool Queue::empty()
{ 
  return (head == NULL && tail == NULL);
}

/**************************************
 * Node Constructor
 * construct the node
 **************************************/
node::node(string arg)
{ value = arg;
  next = NULL;
}

/**************************************
 * Node Destructor
 * destruct the node
 **************************************/
node::~node()
{ if(next!=NULL) delete next;
}
