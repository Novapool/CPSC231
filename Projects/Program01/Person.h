/***********************************
 * Person Class Declaration
 * Written by Laith Assaf
 ***********************************/

#include <iostream>
#include <string>
using namespace std;


class person
{ 
  public:
    person();    // Null constructor
    bool get(istream &in);   // Input first name, last name, and age
    void put(ostream &out) const; // output first name, last name, and age
    
    // Comparison operators
    bool operator>(const person& other) const;  // Greater than
    bool operator<(const person& other) const;  // Less than
    bool operator==(const person& other) const; // Equal to
    
  private:
    string first_name; //first name
    string last_name; //last name
    int age; //age
};