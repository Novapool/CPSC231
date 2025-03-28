/***********************************
 * Linked List Class Implementation
 * Written by Laith Assaf
 ***********************************/

 #include <iostream>
 #include <string>
 using namespace std;
 
 #include "List.h"
 
 /***********************************
  * Constructor
  * Initialize an empty list
  ***********************************/
 list::list()
 {
     head = nullptr;
 }
 
 /***********************************
  * Destructor
  * Delete all nodes in the list
  ***********************************/
 list::~list()
 {
     if (head != nullptr)
     {
         // This will cascade and delete all nodes in the list
         
         delete head;
         head = nullptr;
     }
 }
 
 /***********************************
  * Insert
  * Insert a new node into the list in sorted order
  ***********************************/
 bool list::insert(int id, const string& firstName, const string& lastName, 
                   int age, double gpa)
 {
     node* newNode;
     node* current;
     
     // Create a new node
     
     newNode = new node(id, firstName, lastName, age, gpa);
     
     // If the list is empty or the new node should be the new head
     
     if (head == nullptr || *newNode < *head)
     {
         newNode->next = head;
         head = newNode;
         return true;
     }
     
     // Find the correct position to insert the new node
     
     current = head;
     while (current->next != nullptr && *newNode > *(current->next))
     {
         current = current->next;
     }
     
     // Insert the new node
     
     newNode->next = current->next;
     current->next = newNode;
     
     return true;
 }
 
 /***********************************
  * Find
  * Find a node with the given id
  ***********************************/
 node* list::find(int id) const
 {
     node* current;
     
     current = head;
     
     // Traverse the list to find the node with matching id
     
     while (current != nullptr)
     {
         if (*current == id)
         {
             return current;
         }
         current = current->next;
     }
     
     // Node not found
     
     return nullptr;
 }
 
 /***********************************
  * Remove
  * Remove a node with the given id from the list
  ***********************************/
 bool list::remove(int id)
 {
     node* current;
     node* temp;
     
     // If the list is empty
     
     if (head == nullptr)
     {
         return false;
     }
     
     // If the head node is the one to remove
     
     if (*head == id)
     {
         temp = head;
         head = head->next;
         
         // Disconnect to prevent cascade deletion
         
         temp->next = nullptr;
         delete temp;
         return true;
     }
     
     // Find the node to remove
     
     current = head;
     while (current->next != nullptr && !(*current->next == id))
     {
         current = current->next;
     }
     
     // If node was not found
     
     if (current->next == nullptr)
     {
         return false;
     }
     
     // Remove the node
     
     temp = current->next;
     current->next = temp->next;
     
     // Disconnect to prevent cascade deletion
     
     temp->next = nullptr;
     delete temp;
     
     return true;
 }
 
 /***********************************
  * Forwards
  * Output the list in forward order
  ***********************************/
 void list::forwards(ostream& out) const
 {
     if (head != nullptr)
     {
         head->fore(out);
     }
 }
 
 /***********************************
  * Backwards
  * Output the list in reverse order
  ***********************************/
 void list::backwards(ostream& out) const
 {
     if (head != nullptr)
     {
         head->back(out);
     }
 }
 
 /***********************************
  * Length
  * Return the number of nodes in the list
  ***********************************/
 int list::length() const
 {
     int count;
     node* current;
     
     count = 0;
     current = head;
     
     // Count each node in the list
     
     while (current != nullptr)
     {
         count++;
         current = current->next;
     }
     
     return count;
 }