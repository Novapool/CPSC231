/***********************************
 * Person Class Definitions
 * Written by Laith Assaf
 ***********************************/

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

#include "Person.h"

/**************************************
 * Constructor - no parameters
 **************************************/
person::person()
{
    first_name = "";
    last_name = "";
    age = 0;
}

/**************************************
 * get()
 * Input first name, last name, and age from stream
 * Return: true if successful, false if failed
 **************************************/
bool person::get(istream &in)
{
    in >> first_name >> last_name >> age;
    return(in.good());
}

/**************************************
 * put()
 * Output last name, first name, and age to stream
 **************************************/
void person::put(ostream &out) const
{
    out << left << setw(12) << last_name  // Last name field: 12 characters
        << "  "                           // 2 spaces after last name
        << setw(8) << first_name          // First name field: 8 characters
        << "  "                           // 2 spaces after first name
        << right << setw(3) << age;       // Age field: 3 characters
}


/**************************************
 * operator>
 * Compare if greater than another person
 * Return: true if greater than, false otherwise
 **************************************/
bool person::operator>(const person& other) const
{
    if (last_name != other.last_name)
        return last_name > other.last_name;
    if (first_name != other.first_name)
        return first_name > other.first_name;
    return age > other.age;
}

/**************************************
 * operator<
 * Compare if less than another person
 * Return: true if less than, false otherwise
 **************************************/
bool person::operator<(const person& other) const
{
    if (last_name != other.last_name)
        return last_name < other.last_name;
    if (first_name != other.first_name)
        return first_name < other.first_name;
    return age < other.age;
}

/**************************************
 * operator==
 * Compare if equal to another person
 * Return: true if equal to, false otherwise
 **************************************/
bool person::operator==(const person& other) const
{
    return (last_name == other.last_name &&
            first_name == other.first_name &&
            age == other.age);
}