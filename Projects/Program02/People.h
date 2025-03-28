/***********************************
 * People Class Declaration
 * Written by Laith Assaf
 ***********************************/


#include "Person.h"

class people
{
private:
    person* map;        // Pointer to dynamic array of person objects
    int len;            // Number of persons currently in the array
    static const int MAX_SIZE = 20;  // Maximum size of the array

public:
    // Constructor and Destructor
    people();           // Null constructor - creates storage for array
    ~people();          // Destructor - deletes array storage

    // Array operations
    bool insert(const person& p);  // Add person to array in ascending order
    bool remove(int searchId);     // Remove person with given ID
    bool find(int searchId) const; // Find person with given ID

    // Display operations
    void display(ostream& out) const;  // Display array with statistics
    void dean() const;                 // Display persons with GPA >= 3.75
};
 
