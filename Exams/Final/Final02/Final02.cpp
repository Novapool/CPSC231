/************************************
 * Final 02
 * Written by Laith Assaf
 ************************************/
#include <iostream>
using namespace std;

// External variables - defined in Main.cpp
extern int counter_comp, counter_swap;

/************************************
 * quicksort()
 * Sorts a string array using quicksort algorithm
 ************************************/
void quicksort(string map[], int n)
{ int pos1, pos2;
  string pivot, temp;
  
  // If N>2
  if(n > 2)
  { 
    // Initialize indices pos1 = 0, pos2 = N-1
    pos1 = 0;
    pos2 = n - 1;
    
    // Set pivot value = map[0]
    pivot = map[0];
    
    // Loop while pos1 < pos2
    while(pos1 < pos2)
    { 
      // Loop while map[pos1] < pivot value and pos1 < pos2
      while(map[pos1] < pivot && pos1 < pos2)
      { 
        counter_comp++;
        pos1++;
      }
      
      // Loop while map[pos2] ≥ pivot value and pos2 > pos1
      while(map[pos2] >= pivot && pos2 > pos1)
      { 
        counter_comp++;
        pos2--;
      }
      
      // If pos1 < pos2
      if(pos1 < pos2)
      { 
        // Swap map[pos1] and map[pos2]
        temp = map[pos1];
        map[pos1] = map[pos2];
        map[pos2] = temp;
        counter_swap++;
      }
    }
    
    // If pos1=0, increment pos1
    if(pos1 == 0)
      pos1++;
      
    // If pos2=N-1, decrement pos2
    if(pos2 == n - 1)
      pos2--;
    
    // Call Quick Sort and pass first half of map with a length of pos1
    quicksort(map, pos1);
    
    // Call Quick Sort and pass second half of map, with a length N-pos1
    quicksort(map + pos1, n - pos1);
  }
  // Otherwise if N=2 and map[0] > map[1]
  else if(n == 2)
  { 
    counter_comp++;
    if(map[0] > map[1])
    { 
      // Swap map[0] and map[1]
      temp = map[0];
      map[0] = map[1];
      map[1] = temp;
      counter_swap++;
    }
  }
  // Implicit case: If N<=1, do nothing as the array is already sorted
}