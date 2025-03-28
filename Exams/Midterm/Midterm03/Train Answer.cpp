/**********************************************
 * Train Answer.cpp
 * Updated by Laith Assaf
 **********************************************/
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

#include "Train.h"

/*****************************
 * Add
 * Adds a pod to the train
 * Returns true if successful, false otherwise
 *****************************/
bool train::add(pod arg)
{ 
  // If the train is empty, create a new car
  if (head == NULL)
  {
    head = new car(1);  // Start with car ID 1
    
    // Load the pod onto the new car
    return head->load(arg);
  }
  
  // Try to find a car with space
  car *current = head;
  int carID = 1;
  
  // Traverse to the last car
  while (current->next != NULL)
  {
    current = current->next;
    carID++;
  }
  
  // Try to load the pod onto the last car
  if (current->load(arg))
  {
    return true;
  }
  
  // If the last car is full, create a new car
  current->next = new car(carID + 1);
  
  // Load the pod onto the new car
  return current->next->load(arg);
}

/*****************************
 * Find
 * Finds a pod on the train
 * Returns the car ID where the pod is found, or 0 if not found
 *****************************/
int train::find(pod p)
{ 
  // Check if the train is empty
  if (head == NULL)
  {
    return 0;
  }
  
  // Start the search from the head car
  return head->find(p);
}