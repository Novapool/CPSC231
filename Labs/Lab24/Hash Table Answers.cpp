/*************************************
 * Hash Table Answers.cpp
 * Created by Laith Assaf
 *************************************/
#include <iostream>
using namespace std;

#include "Hash Table.h"

/****************************
 * hash()
 * Hash function implementation
 ****************************/
int hash_table::hash(int key)
{ int index;
  
  // Calculate index
  
  index = (key * 215 + 37) % cap;
  
  // Return hash index
  
  return index;
}

/****************************
 * insert()
 * Insert data into hash table
 * Handles collisions with linear probing
 ****************************/
bool hash_table::insert(node n)
{ int index;
  int original;
  
  // Get hash index
  
  index = original = hash(n.id);
  
  // Check if entry is in use
  
  while(map[index].flag)
  { 
    // Increment index
    
    index = (index + 1) % cap;
    
    // Update collision counter
    
    count++;
    
    // Check if we've wrapped around completely
    
    if(index == original) return false;
  };
  
  // Insert at open index
  
  map[index] = n;
  len++;
  
  return true;
}

/****************************
 * find()
 * Find data in hash table based on id
 * Returns matching node or default node if not found
 ****************************/
node hash_table::find(int id)
{ int index;
  int original;
  node empty;
  
  // Reset collision counter
  
  count = 0;
  
  // Get hash index
  
  index = original = hash(id);
  
  // Loop until we find a match or an empty slot
  
  while(map[index].flag)
  { 
    // Check if this is the one we're looking for
    
    if(map[index].id == id)
      return map[index];
      
    // Increment index
    
    index = (index + 1) % cap;
    
    // Update collision counter
    
    count++;
    
    // Check if we've wrapped around completely
    
    if(index == original) return empty;
  };
  
  // Not found, return default node
  
  return empty;
}