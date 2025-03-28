/***********************************
 * Program 04 Test
 * Written by Mark M Bowman
 ***********************************/ 

#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>
using namespace std;

#include "MiniList.h"
#include "MiniVector.h"

/***********************************
 * Main
 ***********************************/ 
int main()
{ int i;
  float x;
  minivector<float> v;

// Add contents

  for(i=0;i<10;i++)
    { x = (float)sqrt(i);
      v.push_back(x);
    };

// Display

  cout << showpoint << setprecision(4) << endl;

  for(i=0;i<v.size();i++)
    cout << i << setw(8) << v[i] << endl;
  cout << endl;

// Test over/under

  v.push_back(3.14F);
  x = v.at(20);
  cout << endl;

// Success

  return 0;
}
