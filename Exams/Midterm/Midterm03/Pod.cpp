/**********************************************
 * Pod.cpp
 * Written by Mark Bowman
 * DO NOT CHANGE 
 **********************************************/
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

#include "Pod.h"

/*******************************
 * Constructor
 ******************************/
pod::pod(string arg)
{ value = arg;
}

/*****************************
 * Output
 *****************************/
void pod::put(ostream &out)
{ out << setw(12) << value;
}

/*****************************
 * Equal
 *****************************/
bool pod::operator ==(pod &other)
{ return value==other.value;
}
