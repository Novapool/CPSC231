/***********************************
 * Tree.h
 * Binary Search Tree Class Declaration
 * Written by Laith Assaf
 ***********************************/

 #ifndef TREE_H
 #define TREE_H
 
 #include <iostream>
 #include <string>
 #include "Node.h"
 
 class tree
 {
 private:
     // Pointer to the root node of the tree
     node* Root;
 
 public:
     // Constructor: Initialize the empty tree
     tree();
 
     // Destructor: Delete all the nodes in the tree
     ~tree();
 
     // Insert a new value into the tree
     void insert(std::string s);
 
     // Display all the values in the specified order
     void show(std::string order, std::ostream& out);
 
     // Return true/false if the string is found in the tree
     bool find(std::string s);
 };
 
 #endif // TREE_H