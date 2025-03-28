/**********************************************
 * Pod.h
 * Written by Mark M Bowman
 * DO NOT CHANGE 
 **********************************************/

class pod
{ public:
    pod(string arg="");             // Constructor
    void put(ostream& out);         // Output value
    bool operator == (pod &other);  // Equal
  private:
    string value;                   // Data
};
