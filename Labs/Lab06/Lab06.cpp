/*********************************
 * Lab 06
 * Created by Laith Assaf
 *********************************/

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

#include "List.h"

/*************************************
 * main()
 *************************************/
int main()
{ string name;
  fstream infile;
  city c;
  list state;

// Load from file

  cout << "Enter file name: ";
  cin >> name;
  cout << endl;

  infile.open(name,ios::in);
  if(!infile.is_open()) return -1;

  while(c.get(infile)) state.insert(c);

  infile.close();

// Display

  cout << state.size() << " Cities" << endl << endl;
  state.display(cout);


// Sort by closest to here and display

  cout << "Enter home city: ";
  cin >> name;
  cout << endl;

  state.sort(name);

  state.display(cout);


/* Steps 07.4-6
// Prompt for remove and display

  cout << "Enter city to remove: ";
  cin >> name;
  cout << endl;

  state.remove(name);

  cout << state.size() << " Cities" << endl << endl;
  state.display(cout);
*/

// Success

  return 0;
}
