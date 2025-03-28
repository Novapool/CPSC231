/*********************************
 * Bushel code
 * Created by Mark Bowman
 *********************************/

#include <iostream>
using namespace std;

#include "Bushel.h"

/**************************************
 * Constructor - no parameters
 **************************************/
bushel::bushel()
{ apples = 0;
  oranges = 0;
}

/**************************************
 * Constructor - all parameters
 **************************************/
bushel::bushel(int a,int o)
{ apples = a;
  oranges = o;
}

/**************************************
 * get()
 **************************************/
bool bushel::get(istream &in)
{ in >> apples >> oranges;
  return(in.good());
}

/**************************************
 * put()
 **************************************/
void bushel::put(ostream &out)
{ out << apples << " Apples ";
  out << oranges << " Oranges";
}

/**************************************
 * equal()
 **************************************/
bool bushel::operator ==(bushel b)
{ 
  if(apples==b.apples && oranges==b.oranges)
    return true;
  else
    return false;
}

/**************************************
 * lesser()
 * Compare if less than another bushel
 * Return: true if less than, false otherwise
 * Uses Operator <
 **************************************/
bool bushel::operator <(bushel b)
{
  if(apples < b.apples && oranges < b.oranges)
    return true;
  else
    return false;
}

/**************************************
 * greater()
 * Compare if greater than another bushel
 * Return: true if greater than, false otherwise
 * Uses Operator >
 **************************************/
bool bushel::operator >(bushel b)
{
  if(apples > b.apples && oranges > b.oranges)
    return true;
  else
    return false;
}

/**************************************
 * equal()
 * Compare if equal to an integer
 * Return: true if equal to, false otherwise
 * Uses Operator ==
 **************************************/
bool bushel::operator ==(int i)
{
  if(apples + oranges == i)
    return true;
  else
    return false;
}

/**************************************
 * lesser()
 * Compare if less than an integer
 * Return: true if less than, false otherwise
 * Uses Operator <
 **************************************/
bool bushel::operator <(int i)
{
  if((apples + oranges) < i)
    return true;
  else
    return false;
}

/**************************************
 * greater()
 * Compare if greater than an integer
 * Return: true if greater than, false otherwise
 * Uses Operator >
 **************************************/
bool bushel::operator >(int i)
{
  if((apples + oranges) > i)
    return true;
  else
    return false;
}

