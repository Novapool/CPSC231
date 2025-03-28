/*********************************
 * Lab 07
 * Created by Laith Assaf
 *********************************/
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

#include "List.h"

/*************************************
 * main()
 * Program entry point that manages a list of cities
 * Reads city data from two user-specified files
 * Allows sorting cities by distance from a home city
 * Supports removal of cities and displays formatted results
 *************************************/
int main()
{
    string name, secondFileName;
    fstream infile;
    city c;
    list state;

    // Load from first file
    cout << "Enter first file name: ";
    cin >> name;
    cout << endl;

    infile.open(name, ios::in);
    if(!infile.is_open()) return -1;

    while(c.get(infile)) state.insert(c);

    infile.close();

    // Load from second file
    cout << "Enter second file name: ";
    cin >> secondFileName;
    cout << endl;

    infile.open(secondFileName, ios::in);
    if(!infile.is_open()) return -1;

    while(c.get(infile)) state.insert(c);

    infile.close();

    // Display initial state
    cout << state.size() << " Cities" << endl << endl;
    state.display(cout);

    // Sort by closest to here and display
    cout << "Enter home city: ";
    cin >> name;
    cout << endl;

    state.sort(name);
    state.display(cout);

    // Prompt for remove and display
    cout << "Enter city to remove: ";
    cin >> name;
    cout << endl;

    state.remove(name);

    cout << state.size() << " Cities" << endl << endl;
    state.display(cout);

    return 0;
}