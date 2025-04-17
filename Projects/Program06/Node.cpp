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
 * find the max depth starting from this node
 ***********************************/
int node::depth()
{
    int leftBranch = 0;
    int rightBranch = 0;

    if (Left == nullptr && Right == nullptr)  // for no children
        return 0;

    // go down entire tree
    if (Left != nullptr)
        leftBranch = Left->depth();
    if (Right != nullptr)
        rightBranch = Right->depth();

    return 1 + max(leftBranch, rightBranch);
}

/***********************************
 * count
 * return the total number of nodes in the tree
 ***********************************/
int node::count()
{
    int count = 1;

    // go down entire tree and add one for each node
    if (Right != nullptr)
        count += Right->count();
    if (Left != nullptr)
        count += Left->count();

    return count;
}
