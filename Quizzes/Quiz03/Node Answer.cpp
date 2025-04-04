/************************************
 * Quiz03 Node Answer
 * Updated by Laith Assaf
 ************************************/

 #include <iostream>
 #include <string>
 using namespace std;
 
 #include "Node.h"
 
 /*******************************************
  * path()
  * Display path to node
  * Examples: Path to G = M F J H G
  *           Path to T = M R V S Not Found
  *******************************************/
 void node::path(string arg)
 { string path_str;
   node* current;
   
   // Create a string to store the path
   path_str = "Path to " + arg + " = ";
   
   // Create a temporary node pointer to track the path
   current = this;
   
   // Initially add the root node's value
   path_str += current->val + " ";
   
   // Traverse the tree to find the target node
   while (current != NULL)
   { 
     // If we found the target node
     if (current->val == arg)
     { cout << path_str << endl;
       return;
     }
     
     // If target is less than current value, go left
     if (arg < current->val)
     { 
       if (current->left != NULL)
       { current = current->left;
         path_str += current->val + " ";
       }
       else
       { 
         // Node not found
         cout << path_str << "Not Found" << endl;
         return;
       }
     }
     // If target is greater than current value, go right
     else if (arg > current->val)
     { 
       if (current->right != NULL)
       { current = current->right;
         path_str += current->val + " ";
       }
       else
       { 
         // Node not found
         cout << path_str << "Not Found" << endl;
         return;
       }
     }
   }
   
   // If we exit the loop without finding the node
   cout << path_str << "Not Found" << endl;
 }