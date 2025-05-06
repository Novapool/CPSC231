/***********************************
 * Node.cpp
 * Written by Josh Lamb
 * All functions implemented by Josh Lamb
 ***********************************/ 

 #include "Node.h"

 /******************************
  * node default constructor
  ******************************/
 node::node()
 {
     value = "";         // value is empty string
     visit = false;      // not visited yet
     next = nullptr;     // no next node yet
 }
 
 /*******************************
  * node constructor with string value
  ******************************/
 node::node(string value)
 {
     this->value = value;  // set value to passed in string
     visit = false;        // not visited yet
     next = nullptr;       // no next node yet
 }
 
 /******************************
  * node destructor
  * delete any following nodes
  ******************************/
 node::~node()
 {
     delete next;        // delete the next node (if any)
 }