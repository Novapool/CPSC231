/***********************************
 * Graph.h
 * Written by Laith
 * All functions implmented by Laith Assaf
 ***********************************/ 

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
     // Pointer to the first node in the linked list of nodes
     node* Head;
 
     // Pointer to the array of edge pointers
     edge** Edges;
 
     // Counter for the current number of edges
     int count;
 
     // Capacity of the edge array
     int capacity;
 
     // Find a node with a given value, returns NULL if not found
     node* find_node(std::string value);
 
     // Insert a new node into the linked list
     node* insert_node(std::string value);
 
     // Resize the edge array when it reaches capacity
     void resize_edges();
 
     // Clear all visit flags in the node list
     void clear_visits();
 
     // Recursive function to traverse the graph in depth-first order
     void depth_traverse(std::ostream& out, node* current);
 
     // Helper function to find the shortest unvisited path
     edge* find_shortest_edge(node* current);
 
 public:
     // Constructor - Initialize the graph with an empty node list
     // and an edge array of 4 elements
     graph();
 
     // Destructor - Delete the node list and edge array
     ~graph();
 
     // Insert an edge into the graph
     // Takes three parameters: source node value, target node value,
     // and weight of the edge
     // If either node does not exist, it will be added to the node list
     void insert(std::string source, std::string target, int weight);
 
     // Display the list of nodes and their edges
     void show(std::ostream& out);
 
     // Display the values of a depth-first search
     // Takes two parameters: output stream and start node value
     void depth(std::ostream& out, std::string start);
 
     // Display the values of a breadth-first search
     // Takes two parameters: output stream and start node value
     void breadth(std::ostream& out, std::string start);
 
     // Display the path from start node to finish node
     // Takes three parameters: output stream, start node value, finish node value
     // Uses the greedy shortest edge first method
     void path(std::ostream& out, std::string start, std::string finish);
 };
 
 #endif // GRAPH_H