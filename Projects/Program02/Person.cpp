
/***********************************
 * Person Class Implementation
 * Written by Laith Assaf
 ***********************************/

#include "Person.h"
#include <iomanip>
#include <iostream>
#include <string>
using namespace std;

/***********************************
 * Constructor: person
 * Parameters: none
 * Return: none
 * Initializes empty person object
 ***********************************/
person::person()
{
    firstName = "";
    lastName = "";
    age = 0;
    id = 0;
    gpa = 0.0;
}

/***********************************
 * Constructor: person
 * Parameters: string last - last name
 *            string first - first name
 *            int a - age
 *            int i - id
 *            double g - gpa
 * Return: none
 * Creates person with given values
 ***********************************/
person::person(string last, string first, int a, int i, double g)
{
    lastName = last;
    firstName = first;
    age = a;
    id = i;
    gpa = g;
}

/***********************************
 * Function: get
 * Parameters: istream& in - input stream
 * Return: bool - true if successful
 * Reads person data from input stream
 ***********************************/
bool person::get(istream& in)
{
    bool success;                        // Return value

    // Read ID first
    in >> id;
    if (in.fail())
    {
        success = false;
    }
    else
    {
        // Read first and last name
        in >> firstName >> lastName;
        
        if (in.fail())
        {
            success = false;
        }
        else
        {
            // Read age and GPA
            in >> age >> gpa;
            success = !in.fail();
        }
    }

    return success;
}

/***********************************
 * Function: put
 * Parameters: ostream& out - output stream
 * Return: none
 * Outputs formatted person data
 ***********************************/
void person::put(ostream& out) const
{
    out << setw(4) << id << "  "
        << setw(14) << lastName << "  "
        << setw(8) << firstName << "  "
        << setw(3) << age << "  "
        << fixed << setprecision(2) << setw(4) << gpa;
}

/***********************************
 * Function: operator<<
 * Parameters: ostream& out - output stream
 *            const person& p - person to output
 * Return: ostream& - output stream
 * Stream insertion operator
 ***********************************/
ostream& operator<<(ostream& out, const person& p)
{
    p.put(out);
    return out;
}

/***********************************
 * Function: operator>>
 * Parameters: istream& in - input stream
 *            person& p - person to input
 * Return: istream& - input stream
 * Stream extraction operator
 ***********************************/
istream& operator>>(istream& in, person& p)
{
    p.get(in);
    return in;
}

/***********************************
 * Function: operator>
 * Parameters: const person& other - person to compare
 * Return: bool - true if lastName greater
 * Greater than comparison operator
 ***********************************/
bool person::operator>(const person& other) const
{
    return lastName > other.lastName;
}

/***********************************
 * Function: operator<
 * Parameters: const person& other - person to compare
 * Return: bool - true if this lastName less
 * Less than comparison operator
 ***********************************/
bool person::operator<(const person& other) const
{
    return lastName < other.lastName;
}

/***********************************
 * Function: operator==
 * Parameters: const person& other - person to compare
 * Return: bool - true if last names equal
 * Equality comparison operator for two persons
 ***********************************/
bool person::operator==(const person& other) const
{
    return lastName == other.lastName;
}

/***********************************
 * Function: operator==
 * Parameters: int searchId - ID to compare
 * Return: bool - true if IDs equal
 * ID equality comparison operator (keep this one as is)
 ***********************************/
bool person::operator==(int searchId) const
{
    return id == searchId;  
}

/***********************************
 * Function: getGPA
 * Parameters: none
 * Return: double - person's GPA
 * Returns the person's GPA
 ***********************************/
double person::getGPA() const
{
    return gpa;
}

/***********************************
 * Function: getAge
 * Parameters: none
 * Return: int - person's age
 * Returns the person's age
 ***********************************/
int person::getAge() const
{
    return age;
}