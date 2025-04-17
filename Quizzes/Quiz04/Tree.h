/***********************************
 * Tree class declaration
 * DO NOT CHANGE 
 ***********************************/

#include "Node.h"

class tree
{ public:
    tree();                      // Null constructor
    ~tree();                     // Destructor 
    void insert(int);            // Insert data
    void display(ostream &out);  // Display
  private:
    node *root;
};
