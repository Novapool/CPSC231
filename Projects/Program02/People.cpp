
/***********************************
 * People Class Implementation
 * Written by Laith Assaf
 ***********************************/

#include "People.h"
#include <iomanip>

/***********************************
 * Constructor: people
 * Parameters: none
 * Return: none
 * Creates dynamic array storage
 ***********************************/
people::people()
{
    map = new person[MAX_SIZE];
    len = 0;
}

/***********************************
 * Destructor: ~people
 * Parameters: none
 * Return: none
 * Deallocates dynamic array storage
 ***********************************/
people::~people()
{
    delete[] map;
}

/***********************************
 * Function: insert
 * Parameters: const person& p - person to insert
 * Return: bool - true if successful
 * Inserts person in ascending ID order
 ***********************************/
bool people::insert(const person& p)
{
    int i;                              // Loop counter
    bool success;                       // Return value

    // Check if array is full
    if (len >= MAX_SIZE)
    {
        success = false;
    }
    else
    {
        // Find insertion point while shifting larger elements
        for (i = len - 1; i >= 0 && map[i] > p; i--)
        {
            map[i + 1] = map[i];
        }
        
        // Insert at correct position
        map[i + 1] = p;
        len++;
        success = true;
    }

    return success;
}

/***********************************
 * Function: remove
 * Parameters: int searchId - ID to remove
 * Return: bool - true if found and removed
 * Removes person with matching ID
 ***********************************/
bool people::remove(int searchId)
{
    int i;                              // Loop counter
    bool found;                         // Return value

    found = false;
    
    // Find person with matching ID
    for (i = 0; i < len && !found; i++)
    {
        if (map[i] == searchId)
        {
            // Shift remaining elements left
            for (int j = i; j < len - 1; j++)
            {
                map[j] = map[j + 1];
            }
            len--;
            found = true;
        }
    }

    return found;
}

/***********************************
 * Function: find
 * Parameters: int searchId - ID to find
 * Return: bool - true if found
 * Searches for person with matching ID
 ***********************************/
bool people::find(int searchId) const
{
    int i;                              // Loop counter
    bool found;                         // Return value

    found = false;
    
    // Search array for matching ID
    for (i = 0; i < len && !found; i++)
    {
        if (map[i] == searchId)
        {
            found = true;
        }
    }

    return found;
}

/***********************************
 * Function: display
 * Parameters: ostream& out - output stream
 * Return: none
 * Displays list with statistics
 ***********************************/
void people::display(ostream& out) const
{
    int i;                              // Loop counter
    double totalAge;                    // Sum of ages
    double totalGPA;                    // Sum of GPAs
    double avgAge;                      // Average age
    double avgGPA;                      // Average GPA

    // Initialize accumulator variables
    totalAge = 0;
    totalGPA = 0;

    // Display header
    out << "\nID    Last            First     Age  GPA\n"
        << "----  --------------  --------  ---  ----\n";

    // Display each person
    for (i = 0; i < len; i++)
    {
        map[i].put(out);
        out << endl;

        // Accumulate totals
        totalAge += map[i].getAge();
        totalGPA += map[i].getGPA();
    }

    // Display footer line
    out << "----  --------------  --------  ---  ----\n";

    // Calculate and display averages
    if (len > 0)
    {
        avgAge = totalAge / len;
        avgGPA = totalGPA / len;
    }
    else
    {
        avgAge = 0;
        avgGPA = 0;
    }

    out << setw(12) << len << " Persons   "
        << "Average   " << setw(2) << static_cast<int>(avgAge) << "  "
        << fixed << setprecision(2) << avgGPA << endl << endl;
        
}