/************************************
 * Heapsort.cpp
 * Written by Laith Assaf
 ************************************/

 #include "Heapsort.h"

 /************************************
  * heap_left
  * Returns the left child of a node in a heap.
  ************************************/
 inline int heap_left(int pos) 
 {
     // Return the left child index (2 * pos + 1)
     return 2 * pos + 1;
 }
 
 /************************************
  * heap_right
  * Returns the right child of a node in a heap.
  ************************************/
 inline int heap_right(int pos) 
 {
     // Return the right child index (2 * pos + 2)
     return 2 * pos + 2;
 }
 
 /************************************
  * heap_parent
  * Returns the parent of a node in a heap.
  ************************************/
 inline int heap_parent(int pos) 
 {
     // Return the parent index ((pos - 1) / 2)
     return (pos - 1) / 2;
 }
 
 /************************************
  * heap_insert
  * Inserts a value into the heap and maintains the heap property.
  ************************************/
 void heap_insert(string map[], int &n, string value)
 {
     int pos;
     int parent;
 
     // Set map[n] = value
     map[n] = value;
     
     // Set pos = n
     pos = n;
     
     // Set parent = heap_parent(pos)
     parent = heap_parent(pos);
     
     // Loop while pos>0 and map[pos]>map[parent]
     while (pos > 0 && map[pos] > map[parent]) 
     {
         // Swap map[pos] and map[parent]
         swap(map[pos], map[parent]);
         
         // Set pos = parent
         pos = parent;
         
         // Set parent = heap_parent(pos)
         parent = heap_parent(pos);
     }
     
     // Increment n
     n++;
 }
 
 /************************************
  * heapify
  * Take an unordered array and turn it into a heap
  ************************************/
 void heapify(string map[], int n)
 {
     // Set i = 0
     int i = 0;
     int tempN = 0; 
     
     // Loop while i<n
     while (i < n) 
     {
         // Call heap_insert(map,i,map[i])
         heap_insert(map, tempN, map[i]);
         i++;
     }
 }
 
 /************************************
  * heap_remove
  * Removes the root of the heap and maintains the heap property.
  ************************************/
 string heap_remove(string map[], int &n)
 {
     // Set pos = 0
     int pos = 0;
     int index;
     int left;
     int right;
     string value = map[0];
     
     // Decrement n
     n--;
     
     // Swap map[0] and map[n]
     swap(map[0], map[n]);
     
     // Loop while pos<n
     while (pos < n) 
     {
         // Set index = pos
         index = pos;
         
         // Set left = heap_left(pos)
         left = heap_left(pos);
         
         // Set right = heap_right(pos)
         right = heap_right(pos);
         
         // If left<n and map[left]>map[index], set index = left
         if (left < n && map[left] > map[index]) 
             index = left;
             
         // If right<n and map[right]>map[index], set index = right
         if (right < n && map[right] > map[index]) 
             index = right;
         
         // If index ≠ pos
         if (index != pos) 
         {
             // Swap map[pos] and map[index]
             swap(map[pos], map[index]);
             
             // Set pos = index
             pos = index;
         } 
         else 
         {
             // Otherwise, set pos = n
             pos = n;
         }
     }
     
     // Return map[n]
     return value;
 }
 
 /************************************
  * heap_sort
  * Sorts an array using heap sort.
  ************************************/
 void heap_sort(string map[], int n)
 {
     // Loop while n>0
     while (n > 0) 
     {
         // Call heap_remove(map,n)
         heap_remove(map, n);
     }
 }