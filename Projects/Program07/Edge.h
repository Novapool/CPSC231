/************************************
 * Edge.h
 * Written by Faith Thomson
 ************************************/

 #ifndef EDGE_H
 #define EDGE_H
 
 // Forward declaration to resolve circular dependency
 class node;
 class graph;
 
 // Edge class declaration
 class edge
 {
     friend class graph;
     
     public:
         // Constructor - Create an edge with pointers to source and target nodes, and distance
         edge(node* source, node* target, int distance);
         
     private:
         node* source;    // Pointer to the source node
         node* target;    // Pointer to the target node
         int weight;      // Distance to the target node
 };
 
 #endif // EDGE_H