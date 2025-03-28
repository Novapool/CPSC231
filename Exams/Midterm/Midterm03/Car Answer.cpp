/**********************************************
 * Car Answer.cpp
 * Updated by Laith Assaf
 **********************************************/
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

#include "Car.h"

/*****************************
 * load
 * Loads a pod onto the car if there is space
 * Returns true if successful, false otherwise
 *****************************/
bool car::load(pod arg)
{ 
  // Check if there's space in the current car
  if (n < POD_MAX)
  {
    // Add the pod to the car
    map[n] = arg;
    n++;
    return true;
  }
  
  return false;
}

/*****************************
 * Find
 * Locates a pod on this car or its connected cars
 * Returns the car ID where the pod is found, or 0 if not found
 *****************************/
int car::find(pod p)
{ 
  // Check if the pod is in the current car
  for (int i = 0; i < n; i++)
  {
    if (map[i] == p)
    {
      return id;
    }
  }
  
  // If the pod is not in this car, check the next car
  if (next != NULL)
  {
    return next->find(p);
  }
  
  // Not found in this or any following car
  return 0;
}