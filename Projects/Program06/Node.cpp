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
     out << Value << " ";  // Changed to output horizontally with a space
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
 
 /***********************************
  * MLR
  * Output the current node and all children values in MLR order
  * (Middle, Left, Right - preorder traversal)
  ***********************************/
 void node::MLR(ostream& out)
 {
     // Output the current node value (Middle) first
     put(out);
     
     // Traverse left subtree if it exists
     if (Left != nullptr)
         Left->MLR(out);
     
     // Traverse right subtree last if it exists
     if (Right != nullptr)
         Right->MLR(out);
 }
 
 /***********************************
  * RML
  * Output the current node and all children values in RML order
  * (Right, Middle, Left - reverse preorder traversal)
  ***********************************/
 void node::RML(ostream& out)
 {
     // Traverse right subtree first if it exists
     if (Right != nullptr)
         Right->RML(out);
     
     // Output the current node value (Middle)
     put(out);
     
     // Traverse left subtree last if it exists
     if (Left != nullptr)
         Left->RML(out);
 }
 
 /***********************************
 * depth
 * Return the maximum depth from this node to a leaf node
 * (counting edges, not nodes)
 ***********************************/
int node::depth()
{
    int leftDepth = 0;      // Initialize to 0 for leaf nodes
    int rightDepth = 0;     // Initialize to 0 for leaf nodes
    
    // Calculate depth of left subtree if it exists
    if (Left != nullptr)
        leftDepth = Left->depth() + 1;  // Add 1 for this edge
    
    // Calculate depth of right subtree if it exists
    if (Right != nullptr)
        rightDepth = Right->depth() + 1;  // Add 1 for this edge
    
    // Return the maximum of left and right depths
    return (leftDepth > rightDepth) ? leftDepth : rightDepth;
}
 
 /***********************************
  * count
  * Count the number of nodes in this subtree (including this node)
  ***********************************/
 int node::count()
 {
     int total = 1;           // Start with 1 for this node
     
     // Add count of left subtree if it exists
     if (Left != nullptr)
         total += Left->count();
     
     // Add count of right subtree if it exists
     if (Right != nullptr)
         total += Right->count();
     
     // Return the total count
     return total;
 }