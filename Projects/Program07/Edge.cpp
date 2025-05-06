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
 ******************************/
edge::edge(node* source, node* target, int distance)
{
    this->source = source;   // set source node pointer
    this->target = target;   // set target node pointer
    weight = distance;       // set edge weight/distance
}