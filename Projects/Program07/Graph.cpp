/***********************************
 * Graph.cpp
 * Written by Laith Assaf, Faith Thomson, Josh Lamb
 ***********************************/ 

 #include "Graph.h"
 #include <iostream>
 #include <string>
 #include <vector>
 #include <queue>
 
 /******************************
  * graph constructor
  * Initialize the graph with an empty node list and edge array of 4 elements
  * Implemented by Laith Assaf
  ******************************/
 graph::graph()
 {
     Head = nullptr;        // initialize head pointer to null
     count = 0;             // no edges yet
     capacity = 4;          // initial capacity of 4 edges
     Edges = new edge*[capacity];  // allocate array of edge pointers
     
     // Initialize all edge pointers to nullptr
     for (int i = 0; i < capacity; i++)
     {
         Edges[i] = nullptr;
     }
 }
 
 /******************************
  * graph destructor
  * Delete the node list and edge array
  * Implemented by Laith Assaf
  ******************************/
 graph::~graph()
 {
     // Delete all edge objects
     for (int i = 0; i < count; i++)
     {
         delete Edges[i];
     }
     
     // Delete the edge array
     delete[] Edges;
     
     // Delete the linked list of nodes
     delete Head;
 }
 
 /******************************
  * find_node
  * Find a node with a given value, returns nullptr if not found
  * Implemented by Josh Lamb
  ******************************/
 node* graph::find_node(std::string value)
 {
     // Start at the head of the list
     node* current = Head;
     
     // Traverse the list
     while (current != nullptr)
     {
         // If current node has the value we're looking for, return it
         if (current->value == value)
         {
             return current;
         }
         
         // Move to the next node
         current = current->next;
     }
     
     // Node not found
     return nullptr;
 }
 
 /******************************
  * insert_node
  * Insert a new node into the linked list
  * Implemented by Josh Lamb
  ******************************/
 node* graph::insert_node(std::string value)
 {
     // Create a new node
     node* newNode = new node(value);
     
     // If the list is empty, make new node the head
     if (Head == nullptr)
     {
         Head = newNode;
         return newNode;
     }
     
     // Find the last node
     node* current = Head;
     while (current->next != nullptr)
     {
         current = current->next;
     }
     
     // Add new node at the end
     current->next = newNode;
     
     return newNode;
 }
 
 /******************************
  * resize_edges
  * Resize the edge array when it reaches capacity
  * Implemented by Laith Assaf
  ******************************/
 void graph::resize_edges()
 {
     // Calculate new capacity (double the current)
     int newCapacity = capacity * 2;
     
     // Output resize message
     std::cout << "Resizing edge list " << capacity << " to " << newCapacity << std::endl;
     
     // Create new array of edge pointers
     edge** newEdges = new edge*[newCapacity];
     
     // Initialize all edge pointers to nullptr
     for (int i = 0; i < newCapacity; i++)
     {
         newEdges[i] = nullptr;
     }
     
     // Copy existing edge pointers to the new array
     for (int i = 0; i < count; i++)
     {
         newEdges[i] = Edges[i];
     }
     
     // Delete old array (but not the edge objects it points to)
     delete[] Edges;
     
     // Update pointers and capacity
     Edges = newEdges;
     capacity = newCapacity;
 }
 
 /******************************
  * clear_visits
  * Clear all visit flags in the node list
  * Implemented by Josh Lamb
  ******************************/
 void graph::clear_visits()
 {
     // Start at the head of the list
     node* current = Head;
     
     // Traverse the list and reset all visit flags
     while (current != nullptr)
     {
         current->visit = false;
         current = current->next;
     }
 }
 
 /******************************
  * find_shortest_edge
  * Helper function to find the shortest unvisited path
  * Implemented by Laith Assaf
  ******************************/
 edge* graph::find_shortest_edge(node* current)
 {
     edge* shortest = nullptr;
     int min_weight = -1;
     
     // Look through all edges
     for (int i = 0; i < count; i++)
     {
         // If this edge starts at the current node and target is not visited
         if (Edges[i]->source == current && !Edges[i]->target->visit)
         {
             // If this is the first eligible edge or has a lower weight than current shortest
             if (min_weight == -1 || Edges[i]->weight < min_weight)
             {
                 shortest = Edges[i];
                 min_weight = Edges[i]->weight;
             }
         }
     }
     
     return shortest;
 }
 
 /******************************
  * insert
  * Insert an edge into the graph
  * Takes three parameters: source node value, target node value, and weight of the edge
  * If either node does not exist, it will be added to the node list
  * Implemented by Josh Lamb
  ******************************/
 void graph::insert(std::string source, std::string target, int weight)
 {
     // Find or create source node
     node* sourceNode = find_node(source);
     if (sourceNode == nullptr)
     {
         sourceNode = insert_node(source);
     }
     
     // Find or create target node
     node* targetNode = find_node(target);
     if (targetNode == nullptr)
     {
         targetNode = insert_node(target);
     }
     
     // Check if we need to resize the edge array
     if (count >= capacity)
     {
         resize_edges();
     }
     
     // Create a new edge and store its pointer in the array
     Edges[count] = new edge(sourceNode, targetNode, weight);
     count++;
 }
 
 /******************************
  * show
  * Display the list of nodes and their edges
  * Implemented by Laith Assaf
  ******************************/
 void graph::show(std::ostream& out)
 {
     // Start at the head of the list
     node* current = Head;
     
     // Traverse the list of nodes
     while (current != nullptr)
     {
         // Output the node value
         out << "Node " << current->value << std::endl;
         
         // Find all edges that start from this node
         for (int i = 0; i < count; i++)
         {
             if (Edges[i]->source == current)
             {
                 // Output the edge information
                 out << "Edge " << Edges[i]->target->value 
                     << " " << Edges[i]->weight << std::endl;
             }
         }
         
         // Move to next node
         current = current->next;
         
         // Add a blank line between nodes (except after the last node)
         if (current != nullptr)
         {
             out << std::endl;
         }
     }
 }
 
 /******************************
  * depth
  * Display the values of a depth-first search
  * Takes two parameters: output stream and start node value
  * Implemented by Faith Thomson
  ******************************/
 void graph::depth(std::ostream& out, std::string start)
 {
     
 }
 
 /******************************
  * depth_traverse
  * Recursive function to traverse the graph in depth-first order
  * Implemented by Faith Thomson
  ******************************/
 void graph::depth_traverse(std::ostream& out, node* current)
 {
     
 }
 
 /******************************
  * breadth
  * Display the values of a breadth-first search
  * Takes two parameters: output stream and start node value
  * Implemented by Faith Thomson
  ******************************/
 void graph::breadth(std::ostream& out, std::string start)
 {
     
 }
 
 /******************************
  * path
  * Display the path from start node to finish node
  * Takes three parameters: output stream, start node value, finish node value
  * Uses the greedy shortest edge first method
  * Implemented by Faith Thomson
  ******************************/
 void graph::path(std::ostream& out, std::string start, std::string finish)
 {
     
 }