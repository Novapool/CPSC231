/*********************************
 * Bag header
 * Created by Mark Bowman
 *********************************/

class bag
{ public:
    bag(int g=0,int s=0,int c=0);  // Constructor with defaults
    bool get(istream &);                   // Input
    void put(ostream &);                   // Output
    bool operator < (bag &b);              // Compare two bags
    bag operator + (bag &b);               // Add two bags
  private:
    int total();                           // Calculate total amount
    int gold,silver,copper;         // Coins in bag
};
