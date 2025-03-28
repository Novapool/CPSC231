/***********************************
 * Person Class Declaration
 * Written by Laith Assaf
 ***********************************/



#include <iostream>
#include <string>
using namespace std;
 

class people;

class person
{
private:
    string lastName;     // Person's last name
    string firstName;    // Person's first name
    int age;            // Person's age
    int id;             // Person's unique identifier
    double gpa;         // Person's grade point average

public:
    // Constructors
    person();                   // Null constructor
    person(string last, string first, int age, int id, double gpa);  // Parameterized constructor

    // Input/Output methods
    bool get(istream& in);      // Input person data
    void put(ostream& out) const;  // Output person data

    // Stream operators
    friend ostream& operator<<(ostream& out, const person& p);
    friend istream& operator>>(istream& in, person& p);

    // Comparison operators
    bool operator>(const person& other) const;  // Greater than
    bool operator<(const person& other) const;  // Less than
    bool operator==(const person& other) const; // Equal to
    bool operator==(int searchId) const;        // Compare with ID

    // Accessor methods
    double getGPA() const;    // Returns person's GPA
    int getAge() const;       // Returns person's age

    // Friend class declaration
    friend class people;      // Give people class access to private members
};


