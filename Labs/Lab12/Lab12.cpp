/**********************************************
 * Lab 12
 * Laith Assaf
 **********************************************/
#include <iostream>
#include <string>
using namespace std;

// Include the bin class
#include "Bin.h"

/**************************************
 * mini_sort
 * Template function to sort three items
 **************************************/
template <class T>
void mini_sort(T &a, T &b, T &c)
{
  if (a > b)
    swap(a, b);
  if (a > c)
    swap(a, c);
  if (b > c)
    swap(b, c);
}

/**********************************************
 * main()
 **********************************************/
int main()
{ 
  int i, j, k;
  string a, b, c;
  bin bin1, bin2, bin3;

  // Get 1st user entry
  cout << "Enter three integers: ";
  cin >> i >> j >> k;

  // Mini-sort
  mini_sort(i, j, k);

  // Display
  cout << i << " < ";
  cout << j << " < ";
  cout << k << endl << endl;

  // Get 2nd user entry
  cout << "Enter three names: ";
  cin >> a >> b >> c;

  // Mini-sort
  mini_sort(a, b, c);

  // Display
  cout << a << " < ";
  cout << b << " < ";
  cout << c << endl << endl;

  // Get 3rd user entry (bins)
  cout << "Enter bin 1: ";
  bin1.get(cin);
  
  cout << "Enter bin 2: ";
  bin2.get(cin);
  
  cout << "Enter bin 3: ";
  bin3.get(cin);

  // Mini-sort
  mini_sort(bin1, bin2, bin3);

  // Display using bin::put()
  bin1.put(cout);
  cout << " < ";
  bin2.put(cout);
  cout << " < ";
  bin3.put(cout);
  cout << endl;

  // Success
  return 0;
}