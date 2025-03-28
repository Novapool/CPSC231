/*********************************
 * Lab 14
 * Edited by Laith Assaf
 *********************************/

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

#include "Queue.h"

/*********************************
 * main()
 *********************************/
int main()
{ string s;
  fstream infile;
  Queue q;

// Open file

  cout << "Enter file name: ";
  cin >> s;
  infile.open(s,ios::in);
  if(!infile.is_open()) return -1;

// Read data from file

  while(!infile.eof())
    { infile >> s;
      if(infile.good())
        q.push(s);
    };
  cout << endl;

// Close file

  infile.close();

  while(!q.empty())
    { cout << q.front() << " ";
      q.pop();
    };
  cout << endl;

// Output

  if(q.empty())
    cout << "The queue is empty" << endl;
  else
    cout << "The queue is not empty" << endl;

// Success

  return 0;
}
