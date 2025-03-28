/************************************
 * List Answers.cpp
 * Written by Laith Assaf
 ************************************/
#include <iostream>
#include <string>
using namespace std;

#include "List.h"

/**************************************
 * Insert
 * Adds a string to the end of the list if space is available
 * Parameters:
 *     s - string to add to the list
 * Returns: none
 **************************************/
void list::insert(string s)
{
    // Check if there's room to add another element
    
    if (len < ARRAY_MAX)
    {
        data[len] = s;
        len++;
    }
}

/**************************************
 * Remove
 * Removes all occurrences of a string from the list
 * Parameters:
 *     s - string to remove from the list
 * Returns: number of instances removed from the list
 **************************************/
int list::remove(string s)
{
    int i;
    int j;
    int removed = 0;
    
    // Search for all instances of string in the list
    
    for (i = 0; i < len; i++)
    {
        if (data[i] == s)
        {
            // Shift remaining elements left
            
            for (j = i; j < len - 1; j++)
            {
                data[j] = data[j + 1];
            }
            len--;
            removed++;
            i--;    // Check the same position again since elements shifted
        }
    }
    
    return removed;
}