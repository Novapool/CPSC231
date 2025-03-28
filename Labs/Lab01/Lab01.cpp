/*******************************
 * Lab 01
 * Written by Mark Bowman
 *******************************/

#include <iostream>
using namespace std;

#include "Box.h"

/*******************************
 * Main()
 *******************************/
int main()
{ class box a,b,c;


// Display empty boxes

  cout << "a = ";
  a.put(cout);
  cout << endl;
 
  cout << "b = ";
  b.put(cout);
  cout << endl;
 
  cout << "c = ";
  c.put(cout);
  cout << endl;



// Cin new boxes with get

  cout << "Enter box a: ";
  a.get(cin);

  cout << "Enter box b: ";
  b.get(cin);



// Calculate volumes

  int a_volume = a.volume();
  int b_volume = b.volume();


// Calculate surface areas

  int a_surface = a.surface();
  int b_surface = b.surface();


// Display boxes

  cout << "a = ";
  a.put(cout);
  cout << " volume = " << a_volume << " surface = " << a_surface << endl;


  cout << "b = ";
  b.put(cout);
  cout << " volume = " << b_volume << " surface = " << b_surface << endl;

  return 0;
}
