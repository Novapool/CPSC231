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
  * depth
  * Return the maximum depth from the root to a leaf node
  ***********************************/
 int tree::depth()
 {
     // If tree is empty, depth is 0
     if (Root == nullptr)
         return 0;
     
     // Otherwise, get depth from root node
     return Root->depth();
 }
 
 /***********************************
  * count
  * Return the total count of nodes in the tree
  ***********************************/
 int tree::count()
 {
     // If tree is empty, count is 0
     if (Root == nullptr)
         return 0;
     
     // Otherwise, get count from root node
     return Root->count();
 }
 
 /***********************************
  * remove
  * Remove a value from the tree, return true/false if successful
  ***********************************/
 bool tree::remove(string s)
 {
     node* current;            // Pointer to node to be deleted
     node* parent;             // Parent of node to be deleted
     node* successor;          // Successor node for replacement
     node* succParent;         // Parent of successor node
     node* child;              // Child node for reconnection
     bool found = false;       // Flag to track if value was found
     
     // Check if tree is empty
     if (Root == nullptr)
         return false;
     
     // Search for the node to remove
     current = Root;
     parent = nullptr;
     
     // Loop until we find the value or reach a null pointer
     while (current != nullptr && !found)
     {
         if (s == current->Value)
             found = true;
         else
         {
             parent = current;
             if (s < current->Value)
                 current = current->Left;
             else
                 current = current->Right;
         }
     }
     
     // If the value was not found, return false
     if (!found)
         return false;
     
     // Case 1: Node has no children
     if (current->Left == nullptr && current->Right == nullptr)
     {
         // If it's the root, set Root to null
         if (current == Root)
             Root = nullptr;
         // Otherwise, update parent's pointer
         else if (parent->Left == current)
             parent->Left = nullptr;
         else
             parent->Right = nullptr;
         
         // Disconnect the node from the tree
         current->Left = nullptr;
         current->Right = nullptr;
         delete current;
         return true;
     }
     
     // Case 2: Node has one child
     if (current->Left == nullptr || current->Right == nullptr)
     {
         // Determine which child exists
         if (current->Left != nullptr)
             child = current->Left;
         else
             child = current->Right;
         
         // If it's the root, update Root
         if (current == Root)
             Root = child;
         // Otherwise, update parent's pointer
         else if (parent->Left == current)
             parent->Left = child;
         else
             parent->Right = child;
         
         // Disconnect the node from the tree
         current->Left = nullptr;
         current->Right = nullptr;
         delete current;
         return true;
     }
     
     // Case 3: Node has two children
     // Find the inorder successor (smallest node in right subtree)
     succParent = current;
     successor = current->Right;
     
     // Find leftmost node in right subtree
     while (successor->Left != nullptr)
     {
         succParent = successor;
         successor = successor->Left;
     }
     
     // Copy the successor's value to the current node
     current->Value = successor->Value;
     
     // Remove the successor node
     if (succParent == current)
         succParent->Right = successor->Right;
     else
         succParent->Left = successor->Right;
     
     // Disconnect the successor from the tree
     successor->Left = nullptr;
     successor->Right = nullptr;
     delete successor;
     
     return true;
 }