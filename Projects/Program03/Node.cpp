/***********************************
 * Node Class Implementation
 * Written by Laith Assaf
 ***********************************/

 #include <iostream>
 #include <string>
 #include <iomanip>
 using namespace std;
 
 #include "Node.h"
 
 /***********************************
  * Constructor
  * Initialize a node with given parameters
  ***********************************/
 node::node(int newId, const string& newFirstName, const string& newLastName, 
            int newAge, double newGpa, node* newNext)
 {
     id = newId;
     firstName = newFirstName;
     lastName = newLastName;
     age = newAge;
     gpa = newGpa;
     next = newNext;
 }
 
 /***********************************
  * Destructor
  * Delete the next node (which cascades to delete all following nodes)
  ***********************************/
 node::~node()
 {
     if (next != nullptr)
     {
         // This will cascade and delete all following nodes
         
         delete next;
         next = nullptr;
     }
 }
 
 /***********************************
  * Put
  * Output the node's data to the given output stream
  ***********************************/
 void node::put(ostream& out) const
 {
     out << id << "  " 
         << left << setw(15) << lastName 
         << left << setw(10) << firstName 
         << right << setw(3) << age 
         << "  " << fixed << setprecision(2) << gpa 
         << endl;
 }
 
 /***********************************
  * Fore
  * Output the current node and all following nodes
  ***********************************/
 void node::fore(ostream& out) const
 {
     // Output current node
     
     put(out);
     
     // Output all following nodes
     
     if (next != nullptr)
     {
         next->fore(out);
     }
 }
 
 /***********************************
  * Back
  * Output all following nodes and then the current node
  ***********************************/
 void node::back(ostream& out) const
 {
     // First output all following nodes
     
     if (next != nullptr)
     {
         next->back(out);
     }
     
     // Then output the current node
     
     put(out);
 }
 
 /***********************************
  * Overloaded == operator
  * Compare node's id with given integer
  ***********************************/
 bool node::operator==(int compareId) const
 {
     return (id == compareId);
 }
 
 /***********************************
  * Overloaded > operator
  * Compare this node with another node using name and age
  ***********************************/
 bool node::operator>(const node& other) const
 {
     // First compare by last name
     
     if (lastName > other.lastName)
     {
         return true;
     }
     
     // If last names are equal, compare by first name
     
     if (lastName == other.lastName && firstName > other.firstName)
     {
         return true;
     }
     
     // If both names are equal, compare by age
     
     if (lastName == other.lastName && firstName == other.firstName && age > other.age)
     {
         return true;
     }
     
     return false;
 }
 
 /***********************************
  * Overloaded < operator
  * Compare this node with another node using name and age
  ***********************************/
 bool node::operator<(const node& other) const
 {
     // First compare by last name
     
     if (lastName < other.lastName)
     {
         return true;
     }
     
     // If last names are equal, compare by first name
     
     if (lastName == other.lastName && firstName < other.firstName)
     {
         return true;
     }
     
     // If both names are equal, compare by age
     
     if (lastName == other.lastName && firstName == other.firstName && age < other.age)
     {
         return true;
     }
     
     return false;
 }