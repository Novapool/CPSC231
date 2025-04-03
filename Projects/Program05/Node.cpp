/***********************************
 * Node.cpp
 * Binary Search Tree Node Class Implementation
 * Written by Laith Assaf
 ***********************************/

 #include "Node.h"
 #include <iostream>
 #include <string>
 using namespace std;
 
 /***********************************
  * Constructor
  * Create a new node with the given value
  ***********************************/
 node::node(string s)
 {
     Value = s;
     Left = nullptr;           // Initialize left child pointer
     Right = nullptr;          // Initialize right child pointer
 }
 
 /***********************************
  * Destructor
  * Delete all children of this node
  ***********************************/
 node::~node()
 {
     // Delete left subtree if it exists
     if (Left != nullptr)
         delete Left;
     
     // Delete right subtree if it exists
     if (Right != nullptr)
         delete Right;
 }
 
 /***********************************
  * put
  * Output the value to the specified stream
  ***********************************/
 void node::put(ostream& out)
 {
     out << Value << endl;
 }
 
 /***********************************
  * LMR
  * Output the current node and all children values in LMR order
  * (Left, Middle, Right - inorder traversal)
  ***********************************/
 void node::LMR(ostream& out)
 {
     // Traverse left subtree first if it exists
     if (Left != nullptr)
         Left->LMR(out);
     
     // Output the current node value (Middle)
     put(out);
     
     // Traverse right subtree last if it exists
     if (Right != nullptr)
         Right->LMR(out);
 }