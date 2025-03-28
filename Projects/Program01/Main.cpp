/***************************************
 * Program 01
 * Written by Laith Assaf
 ***************************************/ 

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

#include "Person.h"


/***********************************
 * sortArray()
 * Sorts an array of people using bubble sort
 ***********************************/
void sortArray(person arr[], int size) 
{
  bool swapped = true; // Flag to indicate when a swap occurs
  person temp; // Temporary person object for swapping
  for (int i = 0; i < size - 1 && swapped; i++)
  {
    swapped = false;
    for (int j = 0; j < size - i - 1; j++)
    {
      if (arr[j] > arr[j + 1])
      {
        temp = arr[j];
        arr[j] = arr[j + 1];
        arr[j + 1] = temp;
        swapped = true;
      }
    }
  }
}

/***********************************
 * displayArray()
 * Displays an array of people
 ***********************************/
void displayArray(const person arr[], int size)
{
  for (int i = 0; i < size; i++)
  {
    arr[i].put(cout);
    cout << endl;
  }
}



/***********************************
 * main()
 ***********************************/ 
int main()
{ 
  const int MAX_SIZE = 20; // Maximum number of people
  person people[MAX_SIZE]; // Array of people
  int count_of_people = 0; // Counter for number of people read
  string filename; // Name of input file 
  ifstream fin; // File input stream

  // Prompt for file
  cout << "Enter file name: ";
  cin >> filename;

  // Open file
  fin.open(filename);
  // Check for error
  if (!fin)
  {
    cout << "Error opening file " << filename << endl;
    return 1;
  }

  // Read data into array using loop and get function
  while (count_of_people < MAX_SIZE && people[count_of_people].get(fin))
    count_of_people++; 

  // Close file
  fin.close();

  //Sort array using bubble sort

  sortArray(people, count_of_people);

  //Display header
  cout << "\nLast          First      Age\n";
  cout << "------------  --------   ---\n";

  // Display array using display function
  displayArray(people, count_of_people);



// Success

  return 0;
}
