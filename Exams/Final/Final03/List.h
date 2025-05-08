/*********************************
 * List.h
 * DO NOT CHANGE
 *********************************/

#include "Node.h"

class list
{ public:
    list();                         // Constructor
    ~list();                        // Destructor
    bool load(string fname);        // Load from file
    void output(ostream &);         // Output
    void combine(list &a,list &b);  // Combine lists
  private:
    node *head;                     // Head
};
