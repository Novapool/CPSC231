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
    return 2 * pos + 1;
}
/************************************
 * heap_right
 * Returns the right child of a node in a heap.
 ************************************/
inline int heap_right(int pos) 
{
    return 2 * pos + 2;
}
/************************************
 * heap_parent
 * Returns the parent of a node in a heap.
 ************************************/
inline int heap_parent(int pos) 
{
    return (pos - 1) / 2;
}
/************************************
 * heap_insert
 * Inserts a value into the heap and maintains the heap property.
 * Set map[n] = value
 * Set pos = n
 * Set parent = heap_parent(pos)
 * Loop while pos>0 and map[pos]>map[parent]
 * Swap map[pos] and map[parent]
 * Set pos = parent
 * Set parent = heap_parent(pos)
 * Increment n
 ************************************/
void heap_insert(string map[], int &n, string value)
{
    int pos;
    int parent;

    map[n] = value;
    pos = n;
    parent = heap_parent(pos);
    while (pos > 0 && map[pos] > map[parent]) 
    {
        swap(map[pos], map[parent]);
        pos = parent;
        parent = heap_parent(pos);
    }
    n++;
}
/************************************
 * heapify
 * Take an unordered array and turn it into a heap
 * Set i = 0
 * Loop while i<n
 * Call heap_insert(map,i,map[i]);
 ************************************/
void heapify(string map[], int n)
{
    int i = 0;
    int tempN = 0; 
    
    while (i < n) 
    {
        heap_insert(map, tempN, map[i]);
        i++;
    }
}
/************************************
 * heap_remove
 * Removes the root of the heap and maintains the heap property.
 * Set pos = 0
 * Decrement n
 * Swap map[0] and map[n]
 * Loop while pos<n
 * Set index = pos
 * Set left = heap_left(pos)
 * Set right = heap_right(pos)
 * If left<n and map[left]>map[index]
 * Set index = left
 * If right<n and map[right]>map[index]
 * Set index = right
 * If index ≠ pos
 * Swap map[pos] and map[index]
 * Set pos = index
 * Otherwise
 * Set pos = n
 * Return map[n]
 ************************************/
string heap_remove(string map[], int &n)
{
    int pos = 0;
    int index;
    int left;
    int right;
    string value = map[0];
    
    n--;
    swap(map[0], map[n]);
    
    while (pos < n) 
    {
        index = pos;
        left = heap_left(pos);
        right = heap_right(pos);
        
        if (left < n && map[left] > map[index]) 
            index = left;
        if (right < n && map[right] > map[index]) 
            index = right;
        
        if (index != pos) 
        {
            swap(map[pos], map[index]);
            pos = index;
        } 
        else 
        {
            pos = n;
        }
    }
    
    return value;
}
/************************************
 * heap_sort
 * Sorts an array using heap sort.
 * Loop while n>0
 * Call heap_remove(map,n);
 ************************************/
void heap_sort(string map[], int n)
{
    while (n > 0) 
    {
        heap_remove(map, n);
    }
}

