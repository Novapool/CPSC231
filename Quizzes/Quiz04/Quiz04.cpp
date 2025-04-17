/***********************************
 * Quiz 04
 * Written by Laith Assaf
 ***********************************/ 

 #include <iostream>
 #include <iomanip>
 #include <string>
 using namespace std;
 
 #include "Tree.h"
 
 /**********************************
  * Insert
  * Insert a value into the tree
  **********************************/
 void tree::insert(int val)
 { 
   // If tree is empty, create a new root
   if(root == NULL)
     root = new node(val);
   else
     // Otherwise, delegate to the node's insert function
     root->insert(val);
 }
 
 /**********************************
  * Insert
  * Recursive function to insert a value into the tree
  **********************************/
 void node::insert(int val)
 { 
   int leftSum = 0;
   int rightSum = 0;
   
   // Calculate sum of left subtree
   if(left != NULL)
     leftSum = left->sum();
   
   // Calculate sum of right subtree
   if(right != NULL)
     rightSum = right->sum();
   
   // Add to left if it's empty or has a smaller sum (ties go to left)
   if(left == NULL || leftSum <= rightSum)
   { 
     if(left == NULL)
       left = new node(val);
     else
       left->insert(val);
   }
   // Add to right otherwise
   else
   { 
     if(right == NULL)
       right = new node(val);
     else
       right->insert(val);
   }
 }
 
 /**********************************
  * Sum
  * Calculate the sum of values in this subtree
  **********************************/
 int node::sum()
 { 
   int total = data;
   
   // Add sum of left subtree
   if(left != NULL)
     total += left->sum();
   
   // Add sum of right subtree
   if(right != NULL)
     total += right->sum();
   
   return total;
 }