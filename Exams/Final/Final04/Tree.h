/************************************
 * Tree.h
 ************************************/

#include "Node.h"

class tree
{ public:
    tree();                           // Constructor
    ~tree();                          // Destructor
    void insert(string);              // Insert single string
    void insert(string map[],int n);  // Insert array
    void insert_balanced(string map[], int low, int high); // Helper for balanced insertion
    void show();                      // Display
    int dump(string map[]);           // Dump to array
  private:
    node *root;                       // Pointer to root node
};