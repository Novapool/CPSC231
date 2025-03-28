#include <iostream>
#include <iomanip>
using namespace std;

#include "List.h"

/*************************************
 * list()
 * Constructor for the list class
 * Initializes an empty list and allocates memory for cities
 *************************************/
list::list()
{ 
  // Initialize the list
  length = capacity = 0;

  // Allocate memory
  map = new city[LIST_SIZE];

  // Update if successful
  if(map!=NULL) capacity = LIST_SIZE;
}

/*************************************
 * ~list()
 * Destructor for the list class
 * Deallocates memory used by the city map
 *************************************/
list::~list()
{ 
  if(map!=NULL) delete [] map;
}

/*************************************
 * insert()
 * Adds a new city to the list
 * Returns false if list is full or city already exists
 *************************************/
bool list::insert(city arg)
{
    bool success;

    // Check for room and duplicates
    if (len >= LIST_SIZE || cityExists(arg))
    {
        success = false;
    }
    else
    {
        map[len++] = arg;
        success = true;
    }

    return success;
}

/*************************************
 * remove()
 * Removes a city from the list by name
 * Shifts remaining cities forward to fill the gap
 *************************************/
void list::remove(string arg)
{
    bool found;
    int i, j;
    
    found = false;
    i = 0;
    
    // Find the city with the matching name
    while (i < len && !found) 
    {
        if(map[i].name == arg) 
        {
            // Shift all elements after i forward by one position
            for(j = i; j < len - 1; j++)
            {
                map[j] = map[j + 1];
            }
            len--;  // Decrease the length since we removed a city
            found = true;
        }
        i++;
    }
}

/*************************************
 * display()
 * Outputs formatted list of cities to the stream
 * Shows city names, coordinates, and distances
 *************************************/
void list::display(ostream &out)
{
    int i;
    
    // Print header
    out << "City               Lat    Long    Dist" << endl;
    out << "--------------  ------  ------  ------" << endl;
    
    // Print data rows
    for(i = 0; i < len; i++) {
        // City name with padding to 17 characters
        out << left << setw(17) << map[i].name;
        
        // Latitude with padding to 5 characters
        out << fixed << setprecision(2) << setw(5) << map[i].latitude;
        
        // Longitude with padding to 8 characters
        out << "  " << fixed << setprecision(2) << setw(8) << map[i].longitude;
        
        // Distance to first city on same line
        out << "  " << fixed << setprecision(2) << dist(0, i) << endl;
    }
    out << endl;
}

/*************************************
 * dist()
 * Calculates Euclidean distance between two cities
 * Uses latitude and longitude coordinates
 *************************************/
float list::dist(int src, int dst)
{
    float distance;
    
    // Calculate the distance
    distance = sqrt(pow(map[src].latitude - map[dst].latitude, 2) + 
                   pow(map[src].longitude - map[dst].longitude, 2));
    
    return distance;
}

/*************************************
 * size()
 * Returns the current number of cities in the list
 * Provides access to private length variable
 *************************************/
int list::size()
{ 
    int currentLen;
    currentLen = len;
    return currentLen;
}

/*************************************
 * sort()
 * Search for the matching city name in the list. Swap that city with the first element in the list.
 * Use a bubble or to order the cities in ascending order based on the distance from the home city (map index 0).
 *************************************/
void list::sort(string arg)
{
    bool found;
    int i, j;
    city temp;
    
    found = false;
    i = 0;
    
    // Find the city with the matching name
    while (i < len && !found) 
    {
        if(map[i].name == arg) 
        {
            // Swap the city with the first city
            temp = map[0];
            map[0] = map[i];
            map[i] = temp;
            found = true;
        }
        i++;
    }
    
    // Bubble sort the cities based on the distance from the home city
    for(i = 0; i < len; i++) 
    {
        for(j = 0; j < len - 1; j++) 
        {
            if(dist(0, j) > dist(0, j + 1)) 
            {
                temp = map[j];
                map[j] = map[j + 1];
                map[j + 1] = temp;
            }
        }
    }
}

/*************************************
 * cityExists()
 * Checks if a given city is already in the list
 * Returns true if city name is found, false otherwise
 *************************************/
bool list::cityExists(city arg)
{
    bool found;
    int i;
    
    found = false;
    i = 0;
    
    while (i < len && !found)
    {
        if (map[i].name == arg.name)
        {
            found = true;
        }
        i++;
    }
    
    return found;
}