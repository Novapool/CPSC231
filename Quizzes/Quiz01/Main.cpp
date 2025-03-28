/*********************************
 * Quiz 01
 * Created by Mark Bowman
 *********************************/

#include <iostream>
#include <fstream>
using namespace std;

#define BAG_MAX 10

#include "Bag.h"

/*********************************
 * main()
 *********************************/
int main()
{ int i,j,n;
  string fname;
  ifstream f;
  class bag map[BAG_MAX],sum;

// Initialize

  n = 0;
  
// Read data from file

  cout << "Enter file name: ";
  cin >> fname;

  f.open(fname);
  if(!f.is_open()) return 1;

  while(!f.eof() && n<BAG_MAX)
    if(map[n].get(f)) n++;

  f.close();

// Sort array

  for(i=0;i<n;i++)
    for(j=0;j<n-1;j++)
      if(map[j]<map[j+1])
        swap(map[j],map[j+1]);

// Display array

  for(i=0;i<n;i++)
    map[i].put(cout);

// Sum up

  for(i=0;i<n;i++)
    sum = sum + map[i];

  cout << endl;
  sum.put(cout);

// Success

  return 0;
}