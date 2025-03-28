#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

#include "City.h"

/**************************************
 * Constructor - no parameters
 **************************************/
city::city()
{ name = "";
  latitude = longitude = 0.0F;
}

/**************************************
 * Get
 **************************************/
bool city::get(istream &in)
{ in >> name;
in >> latitude;
in >> longitude;
return in.good();
}

/**************************************
 * Put
 **************************************/
void city::put(ostream &out)
{ out << left;
  out << setw(14) << name;
  out << right << fixed << setprecision(2);
  out << setw(8) << latitude;
  out << setw(8) << longitude;
}
