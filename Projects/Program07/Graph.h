/***********************************************
 * Graph.h
 * Written by Laith
 ***********************************************/

 #ifndef GRAPH_H
 #define GRAPH_H
 
 #include <iostream>
 #include <string>
 #include "Node.h"
 #include "Edge.h"
 
 // Graph class declaration
 class graph
 {
 private:
     // Head pointer to the first node in the linked list of nodes
     node* Head;
     
     // Pointer to the array of edges
     edge* Edges;
     
     // Size of edge list (number of edges)
     int EdgeSize;
     
     // Capacity of edge array
     int EdgeCapacity;
     
     // Find a node by value, return NULL if not found
     // Implemented by: [Group member name]
     node* find_node(std::string value);
     
     // Insert a new node with given value
     // Implemented by: [Group member name]
     node* insert_node(std::string value);
     
     // Resize edge array when necessary
     // Implemented by: [Group member name]
     void resize_edges();
     
     // Clear visit flags on all nodes
     // Implemented by: [Group member name]
     void clear_visits();
     
     // Find the next unvisited node to visit in path algorithm
     // Implemented by: [Group member name]
     node* find_next(node* current);
 
 public:
     // Constructor - Initialize graph with empty node list and edge array of 4 elements
     // Implemented by: [Group member name]
     graph();
     
     // Destructor - Delete node list and edge array
     // Implemented by: [Group member name]
     ~graph();
     
     // Insert an edge into the graph
     // If source or target nodes don't exist, add them to the node list
     // Implemented by: [Group member name]
     void insert(std::string source, std::string target, int weight);
     
     // Display the list of nodes and their edges
     // Implemented by: [Group member name]
     void show(std::ostream& out);
     
     // Display the values of a depth-first search starting from given node
     // Implemented by: [Group member name]
     void depth(std::ostream& out, std::string start);
     
     // Display the values of a breadth-first search starting from given node
     // Implemented by: [Group member name]
     void breadth(std::ostream& out, std::string start);
     
     // Display the path from start node to finish node using greedy shortest edge algorithm
     // Implemented by: [Group member name]
     void path(std::ostream& out, std::string start, std::string finish);
 
     // Friend classes
     friend class node;
     friend class edge;
 };
 
 #endif // GRAPH_H