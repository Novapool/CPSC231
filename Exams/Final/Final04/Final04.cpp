/************************************
 * Final04.cpp
 * Updated by Laith Assaf
 ************************************/

#include <iostream>
#include <string>
using namespace std;

#include "Tree.h"

/*******************************
 * tree::insert(string map[], int n)
 * Insert array into balanced tree
 *******************************/
void tree::insert(string map[], int n)
{ 
  // Use recursive balanced insertion
  insert_balanced(map, 0, n-1);
}

/*******************************
 * tree::insert_balanced()
 * Helper function for balanced insertion
 *******************************/
void tree::insert_balanced(string map[], int low, int high)
{ 
  // Base case
  if(low > high) 
    return;
  
  // Find the middle element
  int mid = (low + high) / 2;
  
  // Insert the middle element
  insert(map[mid]);
  
  // Recursively insert left half first
  insert_balanced(map, low, mid-1);
  
  // Then insert right half
  insert_balanced(map, mid+1, high);
}

/*******************************
 * tree::dump()
 * Dump tree elements to array in sorted order
 *******************************/
int tree::dump(string map[])
{ 
  // If tree is empty, return 0
  if(root == NULL) 
    return 0;
    
  // Otherwise traverse in-order and fill array
  return root->dump(map, 0);
}

/*******************************
 * node::dump()
 * Add this node and children to array in reverse order
 *******************************/
int node::dump(string map[], int n)
{ 
  int pos = n;
  
  // Traverse right subtree first (reverse in-order)
  if(right != NULL)
    pos = right->dump(map, pos);
  
  // Add this node's value
  map[pos++] = val;
  
  // Then traverse left subtree
  if(left != NULL)
    pos = left->dump(map, pos);
  
  // Return final position
  return pos;
}