/*********************************
 * Main.cpp
 * DO NOT CHANGE
 *********************************/
#include <iostream>
using namespace std;

#include "Final01.h"

/*********************************
 * main()
 *********************************/
int main()
{ int i;
  int imap[] = { 1,2,3,4,5,6,7,8,9 };
  char cmap[] = { "ABCDEFGHIJKLMNOPQRSTUVWXYZ" };
  string smap[] = { "One","Two","Three","Four","Five","Six","Seven","Eight","Nine","Ten" };

// Display forwards

  for(i=0;i<9;i++) cout << imap[i] << " ";
  cout << endl;
  cout << cmap << endl;
  for(i=0;i<10;i++) cout << smap[i] << " ";
  cout << endl << endl;

// Reverse

  reverse(imap,9);
  reverse(cmap,26);
  reverse(smap,10);

// Display reverse

  for(i=0;i<9;i++) cout << imap[i] << " ";
  cout << endl;
  cout << cmap << endl;
  for(i=0;i<10;i++) cout << smap[i] << " ";
  cout << endl;

// Success

  return 0;
}
