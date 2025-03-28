#define LIST_SIZE  20

#include "City.h"

/*************************************
 * list class
 * Manages a collection of cities with operations for 
 * insertion, removal, sorting, and display
 *************************************/
class list
{
    public:
        list();                      // Constructor - empty list - dynamic memory
        ~list();                     // Destructor
        bool insert(city arg);       // Add a city if not already present
        void remove(string arg);     // Remove a city
        void display(ostream& out);  // Output data
        void sort(string arg);       // Sort by distance from arg
        int size();                  // Return number of cities
    private:
        int len;                     // Number of used cities
        city *map;                   // Data set 
        float dist(int src, int dst);// Distance to another city
        int length, capacity;        // Sizes
        bool cityExists(city arg);   // Check if city already exists
};