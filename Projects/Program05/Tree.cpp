/***********************************
 * Tree.cpp
 * Binary Search Tree Class Implementation
 * Written by Laith Assaf
 ***********************************/

 #include "Tree.h"
 #include <iostream>
 #include <string>
 using namespace std;
 
 /***********************************
  * Constructor
  * Initialize the empty tree
  ***********************************/
 tree::tree()
 {
     Root = nullptr;           // Set root to null (empty tree)
 }
 
 /***********************************
  * Destructor
  * Delete all the nodes in the tree
  ***********************************/
 tree::~tree()
 {
     // Root's destructor will recursively delete all nodes
     if (Root != nullptr)
         delete Root;
 }
 
 /***********************************
  * insert
  * Insert a new value into the tree
  ***********************************/
 void tree::insert(string s)
 {
     node* newNode;            // Pointer to new node
     node* current;            // Pointer for traversal
     node* parent;             // Parent of current node
     
     // Create a new node
     newNode = new node(s);
     
     // If tree is empty, make this the root
     if (Root == nullptr)
     {
         Root = newNode;
         return;
     }
     
     // Find the insertion point
     current = Root;
     parent = nullptr;
     
     while (current != nullptr)
     {
         parent = current;
         
         // Go left if the value is less than current node
         if (s < current->Value)
             current = current->Left;
         
         // Go right if the value is greater than or equal to current node
         else
             current = current->Right;
     }
     
     // Insert the new node
     if (s < parent->Value)
         parent->Left = newNode;
     else
         parent->Right = newNode;
 }
 
 /***********************************
  * show
  * Display all the values in the specified order
  ***********************************/
 void tree::show(string order, ostream& out)
 {
     // Currently only LMR (inorder) traversal is implemented
     if (Root != nullptr)
         Root->LMR(out);
 }
 
 /***********************************
  * find
  * Return true/false if the string is found in the tree
  ***********************************/
 bool tree::find(string s)
 {
     node* current;            // Pointer for traversal
     
     // Start at the root
     current = Root;
     
     // Loop until we find the value or reach a null pointer
     while (current != nullptr)
     {
         // Return true if we found the value
         if (s == current->Value)
             return true;
         
         // Go left if value is less than current node
         if (s < current->Value)
             current = current->Left;
         
         // Go right if value is greater than current node
         else
             current = current->Right;
     }
     
     // Value not found
     return false;
 }