/***********************************
 * Linked List Class Declaration
 * Written by Laith Assaf
 ***********************************/

#include "Node.h"

class list
{
private:
    node* head;         // Pointer to the first node in the list

public:
    // Constructor
    // Initializes an empty list with head set to nullptr
    list();

    // Destructor
    // Deletes all nodes in the list to prevent memory leaks
    ~list();

    // Insert function
    // Creates a new node with the given parameters and inserts it into the list in sorted order
    // Returns true if successful, false otherwise
    bool insert(int id, const string& firstName, const string& lastName, 
                int age, double gpa);

    // Find function
    // Searches for a node with the given id
    // Returns a pointer to the node if found, nullptr otherwise
    node* find(int id) const;

    // Remove function
    // Removes the node with the given id from the list
    // Returns true if successful, false if the node was not found
    bool remove(int id);

    // Forwards function
    // Outputs the entire list to the given output stream in forward order
    void forwards(ostream& out) const;

    // Backwards function
    // Outputs the entire list to the given output stream in reverse order
    void backwards(ostream& out) const;

    // Length function
    // Returns the number of nodes in the list
    int length() const;
};