/*************************************
 * Lab 03
 * Created by YOUR NAME HERE
 *************************************/

#include <iostream>
using namespace std;

#include "Bushel.h"

/***********************************
 * main()
 ***********************************/
int main()
{ 
  class bushel a,b,c;

//Declare numbers
  int comp_num1;


// Initialize bushels and ints
  
  a = bushel(3,8);
  b = bushel(2,6);

/* Step 9*/
// Get bushels

  cout << "Enter bushel A (apples,oranges):";
  a.get(cin);
  cout << "Enter bushel B (apples,oranges):";
  b.get(cin);


// Output bushels

  cout << "A: ";  a.put(cout);  cout << endl;
  cout << "B: ";  b.put(cout);  cout << endl;

/* Step 4*/
// Bushel compare 1

  if(a==b)
    cout << "Bushel A == B" << endl;
  else
    cout << "Bushel A != B" << endl;


/* Step 6 */
// Bushel compare 2

  if(a<b)
    cout << "Bushel A < B" << endl;
  else if(a>b)
    cout << "Bushel A > B" << endl;
  else
    cout << "Bushel A ? B" << endl;

/* Step 10 */

  cout << "Enter total:";
  cin >> comp_num1;

  if (a==comp_num1)
    cout << "Bushel A == " << comp_num1 << endl;
  else 
  {
    cout << "Bushel A != " << comp_num1 << endl;
    if (a<comp_num1)
      cout << "Bushel A < " << comp_num1 << endl;
    else
      cout << "Bushel A > " << comp_num1 << endl;
  }

  if (b==comp_num1)
    cout << "Bushel B == " << comp_num1 << endl;
  else 
  {
    cout << "Bushel B != " << comp_num1 << endl;
    if (b<comp_num1)
      cout << "Bushel B < " << comp_num1 << endl;
    else
      cout << "Bushel B > " << comp_num1 << endl;
  }
    

  


 

// Done

  return 0;
}