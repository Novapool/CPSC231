/*********************************
 * Hash class declaration
 *********************************/

#include "Node.h"

class hash_table
{ public:
    hash_table(int arg=11);    // Constructor
    ~hash_table();             // Destructor
    bool insert(node);         // Insert data
    node find(int);            // Retrieve data
    void dump(ostream &);      // Output entire table
    int collisions();          // Collisions
  private:
    int hash(int);             // Hash function
    int len,cap;               // Array sizes
    int count;                 // Count of collisions
    node *map;                 // Dynamic array of nodes
};
