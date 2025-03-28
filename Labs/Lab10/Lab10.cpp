/**********************************************
 * Lab 10
 * Updated by YOUR NAME GOES HERE
 **********************************************/

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

#include "Node.h"

/**********************************************
 * main()
 **********************************************/
int main()
{ string name;
  fstream infile;
  node *head,*p,*q;
  head = NULL;

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
      { p = new node(name);
        if(head==NULL)
          head = p;
        else
          head->add(p);
      };
    
    };

// Close file

  infile.close();
  cout << endl;

  p = head;

  cout << "Forwards" << endl;
  if(head!=NULL) head->forwards(cout);
  cout << endl;

  cout << "Backwards" << endl;
  if(head!=NULL) head->backwards(cout);
  cout << endl;



  if(head !=NULL) delete head;
// Success

  return 0;
}
