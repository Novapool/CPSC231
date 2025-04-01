/************************************
 * Node Answers.cpp
 * Updated by Laith Assaf
 ************************************/

#include <iostream>
#include <iomanip>
using namespace std;

#include "Node.h"


/************************************
 * Node lmr()
 * Display LMR order
 ************************************/
void node::lmr()
{ 
    if(left!=NULL) left->lmr();              // Left

    cout << val << " ";                      // Middle

    if(right!=NULL) right->lmr();            // Right
}

/************************************
 * Node leaves()
 * Display leaves
 ************************************/
void node::leaves()
{ 
    if(left==NULL && right==NULL)             // Leaf
        cout << val << " ";
    else
    { 
        if(left!=NULL) left->leaves();        // Left
        if(right!=NULL) right->leaves();      // Right
    }
}

/************************************
 * Node leaves(int)
 * Display leaves and depth
 ************************************/
void node::leaves(int depth)
{ 
    if(left==NULL && right==NULL)                 // Leaf
        cout << setw(5) << val << setw(5) << depth << endl;
    else
    { 
        if(left!=NULL) left->leaves(depth+1);     // Left
        if(right!=NULL) right->leaves(depth+1);   // Right
    }
}
