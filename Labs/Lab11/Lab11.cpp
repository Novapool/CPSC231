/**********************************************
 * Lab 11
 * Created by Mark M Bowman
 **********************************************/

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

#include "List.h"

/**********************************************
 * main()
 **********************************************/
int main()
{ int n;
  string name;
  fstream infile;
  list a;

// Open file

  cout << "Enter file name: ";
  cin >> name;
  cout << left << endl;
  infile.open(name,ios::in);

// Loop through file

  while(!infile.eof())
    { infile >> name;

// Process valid input

      if(infile.good())
        a.insert(name);
    };

// Close file

  infile.close();

 

  cout << "Enter rotations: ";
  cin >> n;
  cout << endl;
  a.rotate(n);



  a.display(cout);
  cout << endl;



  a.foreward(cout);
  cout << endl;
  
  a.backward(cout);
  cout << endl;

// Success

  return 0;
}