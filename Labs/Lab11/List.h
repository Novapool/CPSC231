/**********************************************
 * Node.h
 * Written by Mark M Bowman
 **********************************************/

#include "Node.h"

class list
{ public:
    list();                     // Constructor
    ~list();                    // Destructor
    bool insert(string args);   // Add a node to list
    void rotate(int);           // Rotate the list
    void display(ostream &);    // Display entire list
    void foreward(ostream &);   // Display forwards list
    void backward(ostream &);   // Display backwards list
  private:
    node* head;                 // Link to the head node
    node* current;              // Link to the current node
};
