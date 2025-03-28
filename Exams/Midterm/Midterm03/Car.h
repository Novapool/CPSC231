/**********************************************
 * Car.h
 * Written by Mark M Bowman
 **********************************************/

#include "Pod.h"

#define POD_MAX  4

//class train;

class car
{ friend class train;
  public:
    car(int arg=0);           // Constructor
    ~car();                   // Destructor
    bool load(pod p);         // Load pod onto car
    void put(ostream& out);   // Output node
    void fore(ostream& out);  // Recurse forwards
    int  find(pod arg);       // Find a pod
  private:
    int id,n;                 // ID and number of pods
    pod map[POD_MAX];         // Array
    car *next;                // Link to the next car
};
