/************************************
 * Midterm 02
 * Written by Mark M Bowman
 ************************************/

#include <iostream>
using namespace std;

#include "Set.cpp"

/*******************************
 * main()
 *******************************/
int main()
{ int i;
  char amap[6] = { "HELLO" };
  char bmap[9] = { "COMPUTER" };
  set<char> a,b,c;

// Fill a

  for(i=0;i<5;i++)  a.insert(amap[i]);
  cout << "a = "; a.put(cout);
  cout << endl;
  
// Fill b

  for(i=0;i<8;i++) b.insert(bmap[i]);
  cout << "b = "; b.put(cout);
  cout << endl;

// Fill c and subtract

  c = a+b;

  cout << "c = "; c.put(cout);
  cout << endl;

// Success

  return 0;
}
