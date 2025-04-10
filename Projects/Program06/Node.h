/***********************************
 * Node.h
 * Binary Search Tree Node Class Declaration
 * Written by Laith Assaf
 ***********************************/

 #ifndef NODE_H
 #define NODE_H
 
 #include <iostream>
 #include <string>
 using namespace std;
 
 class tree; // Forward declaration
 
 class node
 {
 private:
     // Stored value
     string Value;
 
     // Pointer to left child node
     node* Left;
 
     // Pointer to right child node
     node* Right;
 
 public:
     // Constructor: Create a new node with the given value
     node(string s);
 
     // Destructor: Delete all children of this node
     ~node();
 
     // Output the value to the specified stream
     void put(ostream& out);
 
     // Output the current node and all children values in LMR order (inorder)
     void LMR(ostream& out);
     
     // Output the current node and all children values in MLR order (preorder)
     void MLR(ostream& out);
     
     // Output the current node and all children values in RML order (reverse preorder)
     void RML(ostream& out);
     
     // Return the maximum depth from this node to a leaf node
     int depth();
     
     // Count the number of nodes in this subtree (including this node)
     int count();
 
     // Declare the tree class as a friend to allow access to private members
     friend class tree;
 };
 
 #endif // NODE_H