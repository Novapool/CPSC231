/*********************************
 * Bushel header
 * Created by Mark Bowman
 *********************************/

#include <iostream>
using namespace std;

class bushel
{ public:
    bushel();              // Constructor - empty
    bushel(int,int);       // Constructor with counts
    bool get(istream &);   // Input
    void put(ostream &);   // Output
    bool operator == (bushel);        // Compare to another bushel
    bool operator <(bushel);       // Compare if less than another bushel
    bool operator >(bushel);      // Compare if greater than another bushel
    bool operator == (int);       // Compare if equal to an integer
    bool operator <(int);      // Compare if less than an integer
    bool operator >(int);     // Compare if greater than an integer
  private:
    int apples;            // Apples in bushel
    int oranges;           // Oranges in bushel 
};
