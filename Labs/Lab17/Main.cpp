/************************************
 * Lab 17
 * Written by Mark M Bowman
 ************************************/

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

#include "Node.h"

node * build_tree();

/*******************************
 * main()
 *******************************/
int main()
{ node *root;

// Initialize

  root = build_tree();

/* PART 1*/
// Display tree

  cout << "Entire Tree" << endl;
  if(root!=NULL) root->lmr();
  cout << endl << endl;


/* PART 2 */
// Display leaves

  cout << "Leaves" << endl;
  root->leaves();
  cout << endl << endl;


/* PART 3 */
// Display leaves and depth

  cout << "Leaf   Depth" << endl;
  cout << "-----  -----" << endl;
  root->leaves(0);
  cout << endl;


// Clean up

  if(root!=NULL) delete root;

// Success

  return 0;
}

/*******************************
 * build_tree()
 *******************************/
node * build_tree()
{ int i;
  int list[17] = { 10,2,25,1,4,17,34,1,2,3,7,13,20,2,5,8,21 };
  node *map[17];
  
  for(i=0;i<17;i++)
    map[i] = new node(list[i]);

  map[0]->left = map[1];    map[0]->right = map[2];
  map[1]->left = map[3];    map[1]->right = map[4];
  map[2]->left = map[5];    map[2]->right = map[6];
  map[3]->left = map[7];    map[3]->right = map[8];
  map[4]->left = map[9];    map[4]->right = map[10];
  map[5]->left = map[11];   map[5]->right = map[12];
  map[8]->left = map[13];
  map[10]->left = map[14];  map[10]->right = map[15];
  map[12]->right = map[16];
 
  return map[0];
}
