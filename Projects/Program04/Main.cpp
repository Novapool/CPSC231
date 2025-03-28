/***********************************
 * Program 04
 * Written by Mark M Bowman
 ***********************************/ 

#include <iostream>
#include <string>
using namespace std;

#include "MiniList.h"
#include "MiniQueue.h"
#include "MiniStack.h"

void test_queue();
void test_stack();
void test_string();

/***********************************
 * Main
 ***********************************/ 
int main()
{ test_queue();
  test_stack();
  test_string();
  return 0;
}

/***********************************
 * test_queue()
 ***********************************/ 
void test_queue()
{ int i;
  miniqueue<int> a;

// Header

  cout << "Integer Queue\n--------------------\n";

// Push onto list

  for(i=0;i<12;i++) a.push(i);
  cout << endl;

// Pop off stack

  while(a.size()>0)
    { cout << a.front() << " ";
      a.pop();
    };
  cout << endl << endl;

// Check underflow

  a.pop();
  i = a.front();
  cout << endl;
}

/***********************************
 * test_stack()
 ***********************************/ 
void test_stack()
{ int i;
  ministack<int> a;

// Header

  cout << "Integer Stack\n--------------------\n";

// Push onto list

  for(i=0;i<12;i++) a.push(i);
  cout << endl;

// Pop off stack

  while(a.size()>0)
    { cout << a.top() << " ";
      a.pop();
    };
  cout << endl << endl;

// Check underflow

  a.pop();
  i = a.top();
  cout << endl;
}

/***********************************
 * test_string()
 ***********************************/ 
void test_string()
{ int i;
  string val[7] = { "Richard","David","Mark","Frank","Susan","Kathy","John" };
  miniqueue<string> q;
  ministack<string> s;

// Header

  cout << "String Queue & Stack\n--------------------\n";

// Push onto list

  for(i=0;i<7;i++)
    { q.push(val[i]);
      s.push(val[i]);
    };

// Pop off queue

  while(q.size()>0)
    { cout << q.front() << " ";
      q.pop();
    };
  cout << endl;

// Pop off stack

  while(s.size()>0)
    { cout << s.top() << " ";
      s.pop();
    };
  cout << endl << endl;
}
