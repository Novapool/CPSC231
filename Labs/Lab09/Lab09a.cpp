/***************************************
 * Lab 09a - Recursion
 * Written by Laith Assaf
 ***************************************/

#include <iostream>
#include <string>
using namespace std;

void apple(string s);

int counter = 0;

/***************************************
 * main()
 ***************************************/
int main()
{ string name;

// Get user input

  cout << "Enter your last name: ";
  cin >> name;

// Call recursive function

  cout << endl;
  apple(name);
  cout << endl;

// Output results
 
  cout << counter << " recursions\n";

// Success

  return 0;
}

/***************************************
 * apple()
 ***************************************/
void apple(string s)
{ int i;

// Increment counter

  counter++;

// Return if at end of characters

  if(s.length()==0) return;

// Get ascii value

  i = (int)s[0];


// Recurse on next char

apple(s.substr(1,s.length()-1));

// Output value

  cout << s[0];


}
