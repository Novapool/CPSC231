/***********************************
 * Edge.cpp
 * Written by Faith Thomson
 * All functions implemented by Faith Thomson
 ***********************************/ 

 #include "Edge.h"
 #include "Node.h"
 
 /******************************
  * edge constructor
  * Creates an edge with pointers to source and target nodes, and distance
  * Implemented by Faith Thomson
  ******************************/
 edge::edge(node* src, node* tgt, int distance)
 {
     source = src;      // set source node pointer
     target = tgt;      // set target node pointer
     weight = distance; // set edge weight/distance
 }