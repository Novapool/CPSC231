/**********************************************
 * Train.h
 * Written by Mark M Bowman
 * DO NOT CHANGE
 **********************************************/

#include "Car.h"

class train
{ public:
    train();                     // Constructor
    ~train();                    // Destructor
    bool add(pod arg);           // Add a pod to train
    int  find(pod arg);          // Find a pod
    void display(ostream &out);  // Display the train
  private:
    car *head;                   // Head car
};
