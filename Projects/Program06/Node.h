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
     // Constructor: Create an empty node
     node(string s);
 
     // Destructor: Delete all children of this node
     ~node();
 
     // Output the value
     void put(ostream& out);
 
     // Output the current node and all children values in LMR order
     void LMR(ostream& out);
 
     // Declare the tree class as a friend to allow access to private members
     friend class tree;
 };
 
 #endif // NODE_H