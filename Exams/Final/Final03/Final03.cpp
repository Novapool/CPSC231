/*********************************
 * Final 03
 * Written by Laith Assaf
 * Source: Chapter Notes 20, Program 3, Lab14
 *********************************/
#include <iostream>
#include <string>
using namespace std;

#include "List.h"

/*********************************
 * node::copy()
 * Create a copy of node
 *********************************/
node * node::copy()
{ node *p;

  // Create new node
  p = new node(data);
  
  // Copy next if it exists
  if(next != NULL)
    p->next = next->copy();
    
  // Return pointer
  return p;
}

/*********************************
 * list::combine()
 * Combine two sorted lists into one
 * without duplicates
 *********************************/
void list::combine(list &a, list &b)
{ node *pa, *pb, *current;

  // Initialize pointers
  pa = a.head;
  pb = b.head;
  head = NULL;
  current = NULL;
  
  // Continue until we've gone through both lists
  while(pa != NULL || pb != NULL)
  { 
    // If one list is empty, take from the other
    if(pa == NULL)
    {
      // Take from list B
      if(current == NULL || current->data != pb->data)
      {
        // Create a new node
        node *temp = new node(pb->data);
        
        // Add to our list
        if(head == NULL)
          head = temp;
        else
          current->next = temp;
          
        // Update current
        current = temp;
      }
      
      // Move to next node in list B
      pb = pb->next;
    }
    else if(pb == NULL)
    {
      // Take from list A
      if(current == NULL || current->data != pa->data)
      {
        // Create a new node
        node *temp = new node(pa->data);
        
        // Add to our list
        if(head == NULL)
          head = temp;
        else
          current->next = temp;
          
        // Update current
        current = temp;
      }
      
      // Move to next node in list A
      pa = pa->next;
    }
    else if(pa->data < pb->data)
    {
      // Take from list A
      if(current == NULL || current->data != pa->data)
      {
        // Create a new node
        node *temp = new node(pa->data);
        
        // Add to our list
        if(head == NULL)
          head = temp;
        else
          current->next = temp;
          
        // Update current
        current = temp;
      }
      
      // Move to next node in list A
      pa = pa->next;
    }
    else if(pb->data < pa->data)
    {
      // Take from list B
      if(current == NULL || current->data != pb->data)
      {
        // Create a new node
        node *temp = new node(pb->data);
        
        // Add to our list
        if(head == NULL)
          head = temp;
        else
          current->next = temp;
          
        // Update current
        current = temp;
      }
      
      // Move to next node in list B
      pb = pb->next;
    }
    else
    {
      // Equal items, take one and skip both
      if(current == NULL || current->data != pa->data)
      {
        // Create a new node
        node *temp = new node(pa->data);
        
        // Add to our list
        if(head == NULL)
          head = temp;
        else
          current->next = temp;
          
        // Update current
        current = temp;
      }
      
      // Move to next node in both lists
      pa = pa->next;
      pb = pb->next;
    }
  }
}