/*********************************
 * Bag code
 * Updated by Laith Assaf
 *********************************/

#include <iostream>
using namespace std;

#include "Bag.h"

/*********************************
 * Constructor
 *********************************/
bag::bag(int g,int s,int c)
{ gold = g;
  silver = s;
  copper = c;
}

/*********************************
 * Input
 *********************************/
bool bag::get(istream &in)
{ in >> gold >> silver >> copper;
  return in.good();
}

/*********************************
 * Calculate total amount
 * Return the total amount in copper
 *********************************/
int bag::total()
{ 
  return gold*20 + silver*5 + copper;
}

/*********************************
 * Put
 * Output the bag
 *********************************/
void bag::put(ostream &out)
{ 
  out << gold << "g + ";
  out << silver << "s + ";
  out << copper << "c = ";
  out << total(); 
  out << endl;
}

/*********************************
 * Less than operator
 * Compare two bags
 *********************************/
bool bag::operator < (bag &rhs)  
{
  return total() < rhs.total();
}

/*********************************
 * Add two bags
 * Return the sum of the two bags
 *********************************/
bag bag::operator + (bag &rhs)   
{
    int g = gold + rhs.gold;
    int s = silver + rhs.silver;
    int c = copper + rhs.copper;
    return bag(g,s,c);
}