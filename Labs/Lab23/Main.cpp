/************************************
 * Lab23.cpp
 * Written by Laith Assaf
 ************************************/
#include <iostream>
#include <string>
using namespace std;

#include "Lab23.h2"

/******************************
 * showCityList()
 * Display the list of cities
 ******************************/
void showCityList()
{ int i;

  // Header
  
  cout << "City List" << endl;
  cout << "--------------" << endl;

  // Display cities
  
  for(i=0; i<CITY_MAX; i++)
  
  { cout << i << ") " << city[i] << endl;
  };
    
  cout << endl;
}

/******************************
 * invalidateReturnPath()
 * Set the return path to 0 to prevent going back
 ******************************/
void invalidateReturnPath(int map[][CITY_MAX], int from, int to)
{ 
  map[to][from] = 0;
}

/******************************
 * invalidateCity()
 * Set all paths from a city to 0 to prevent visiting again
 ******************************/
void invalidateCity(int map[][CITY_MAX], int cityIndex)
{ int i;

  // Mark all outgoing paths as invalid
  
  for(i=0; i<CITY_MAX; i++)
  
  { map[cityIndex][i] = 0;
  };

  // Mark all incoming paths as invalid
  
  for(i=0; i<CITY_MAX; i++)
  
  { map[i][cityIndex] = 0;
  };
}

/******************************
 * findPath()
 * Calculate the path from start to stop city
 ******************************/
void findPath(int start, int stop)
{ int pos, temp, i, j;
  int total = 0;
  int distance[CITY_MAX][CITY_MAX];
  bool reachedDestination = false;

  // Copy the map array since we'll be modifying it
  
  for(i=0; i<CITY_MAX; i++)
  
  { for(j=0; j<CITY_MAX; j++)
    
    { distance[i][j] = map[i][j];
    };
  };

  // Start at the specified city
  
  pos = start;

  // Loop until we reach destination or get stuck
  
  while(pos != stop && pos < CITY_MAX)
  
  {
    // Find the first available path from current city
    
    temp = 0;
    while(temp < CITY_MAX && distance[pos][temp] == 0)
    
    { temp++;
    };

    // If we found a path
    
    if(temp < CITY_MAX)
    
    {
      // Display and add the distance to total
      
      cout << city[pos] << " to " << city[temp] << " = " << distance[pos][temp] << endl;
      total += distance[pos][temp];

      // Invalidate the path we just took
      
      distance[pos][temp] = 0;
      
      // Invalidate the return path to prevent going back
      
      invalidateReturnPath(distance, pos, temp);
      
      // Invalidate the city we're leaving
      
      invalidateCity(distance, pos);
      
      // Move to the next city
      
      pos = temp;
      
      // Check if we reached the destination
      
      if(pos == stop)
      
      { reachedDestination = true;
      };
    }
    else
    
    {
      // No path found, we're stuck
      
      cout << "Can't get there from here" << endl;
      pos = CITY_MAX;  // Set pos to exit the loop 
    };
  };

  // Display total distance if we reached destination
  
  if(reachedDestination)
  
  { cout << "Total = " << total << endl;
  };
}

/******************************
 * main()
 * Main driver routine
 ******************************/
int main()
{ int start, stop;

  // Show list of cities
  
  showCityList();

  // Get starting and ending cities
  
  cout << "Enter start city: ";
  cin >> start;
  
  cout << "Enter stop city: ";
  cin >> stop;
  cout << endl;

  // Validate input
  
  if(start < 0 || start >= CITY_MAX || stop < 0 || stop >= CITY_MAX)
  
  {
    cout << "Invalid city selection" << endl;
    return 1;
  };

  // Find path between cities
  
  findPath(start, stop);

  // Success
  
  return 0;
}