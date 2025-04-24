/***********************************
 * Node.h
 * Written by Josh Lamb
 * All functions implmented by Josh Lamb
 ***********************************/

 #ifndef NODE_H
 #define NODE_H
 
 #include <string>
 using namespace std;
 
 // Node class declaration
 class node
 {
     friend class graph;
     
     public:
         node();                 // Default constructor
         node(string value);     // Constructor with string value
         ~node();                // Destructor
         
     private:
         string value;           // Stored value (a string)
         bool visit;             // Boolean indicator shows if node has been visited
         node* next;             // Pointer to the next node in the linked list
 };
 
 #endif // NODE_H