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
     // Check if tree is empty
     if (Root == nullptr)
         return;
     
     // Perform traversal based on the specified order
     if (order == "LMR")
         Root->LMR(out);
     else if (order == "MLR")
         Root->MLR(out);
     else if (order == "RML")
         Root->RML(out);
     
     // Output count and depth
     out << endl << endl;
     
     out << "Count: " << count() << endl;
     out << "Depth: " << depth() << endl;
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
 
/***********************************
  * remove
  * Remove a value from the tree, return true/false if successful
  ***********************************/
 bool tree::remove(string s)
 {
     node* current;            // Pointer for traversal
     node* parent;             // Parent of current node
     node* replacement;        // Node to replace the removed node
     
     // Start at the root
     current = Root;
     parent = nullptr;
     
     // Find the node to remove
     while (current != nullptr && current->Value != s)
     {
         parent = current;
         if (s < current->Value)
             current = current->Left;
         else
             current = current->Right;
     }
     
     // If the value was not found, return false
     if (current == nullptr)
         return false;
     
     // Case 1: Node has no children (leaf node)
     if (current->Left == nullptr && current->Right == nullptr)
     {
         if (parent == nullptr) // Removing root node
             Root = nullptr;
         else if (parent->Left == current)
             parent->Left = nullptr;
         else
             parent->Right = nullptr;
         
         delete current; // Free memory
         return true;
     }
     // Case 2: Node has one child
     else if (current->Left == nullptr || current->Right == nullptr)
     {
         // Determine which child to keep
         replacement = (current->Left != nullptr) ? current->Left : current->Right;
         
         if (parent == nullptr) // Removing root node
             Root = replacement;
         else if (parent->Left == current)
             parent->Left = replacement;
         else
             parent->Right = replacement;
         
         delete current; // Free memory
         return true;
     }
     // Case 3: Node has two children
     else
     {
         // Find the in-order successor (smallest value in the right subtree)
         replacement = current->Right;
         parent = current;
         
         while (replacement->Left != nullptr)
         {
             parent = replacement;
             replacement = replacement->Left;
         }
         
         // Replace current node's value with the in-order successor's value
         current->Value = replacement->Value;
         
         // Remove the in-order successor
         if (parent->Left == replacement)
             parent->Left = replacement->Right;
         else
             parent->Right = replacement->Right;
         
         delete replacement; // Free memory
         return true;
     }
 }
 /***********************************
  * depth
  * Return the maximum depth from the root to a leaf node
  ***********************************/
 int tree::depth()
 {
     // If tree is empty, return 0
     if (Root == nullptr)
         return 0;
     
     // Call the depth function on the root node
     return Root->depth();
 }
 /***********************************
  * count
  * Return the total count of nodes in the tree
  ***********************************/
 int tree::count()
 {
     // If tree is empty, return 0
     if (Root == nullptr)
         return 0;
     
     // Call the count function on the root node
     return Root->count();
 }