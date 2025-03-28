/*********************************
 * Lab 05
 * Created by Laith Assaf
 * Purpose: This program reads data from a file, sorts it,
 * and displays the sorted results.
 *********************************/

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

/*************************************
 * sort function
 * Parameters:
 *   str_array - array of strings to be sorted
 *   int_array - array of integers to be sorted in parallel
 *   n - size of both arrays
 * Returns: void
 * Purpose: Sorts arrays using bubble sort algorithm,
 * keeping string and integer pairs together
 *************************************/
void sort(string *str_array,int *int_array,int n)
{ 
  int i,j;
  string temp_str;
  int temp_int;
  
  for(i = 0; i < n-1; i++)
  {
      for(j = 0; j < n-i-1; j++)
      {
          // Compare adjacent strings and swap if needed
          if(str_array[j] > str_array[j+1])
          {
              // Swap strings
              temp_str = str_array[j];
              str_array[j] = str_array[j+1];
              str_array[j+1] = temp_str;
              
              // Swap corresponding integers
              temp_int = int_array[j];
              int_array[j] = int_array[j+1];
              int_array[j+1] = temp_int;
          }
      }
  }
}

/*************************************
 * main()
 * Purpose: Main driver of the program
 * Returns: 0 for successful execution
 *************************************/

int main() {
    int n, count;              // n: number of items, count: value from file
    string * str_array;        // Dynamic array for strings
    int * int_array;          // Dynamic array for integers
    string name;              // For file name and string input
    fstream infile;           // File stream object
    int i = 0;               // Loop counter

    // Prompt user for input file name and open file
    cout << "Enter file name: ";
    cin >> name;
    infile.open(name, ios::in);

    // Read number of lines from first line of file
    infile >> n;
    cout << n << " lines in file" << endl << endl;

    // Dynamically allocate arrays based on file size
    str_array = new string[n];
    int_array = new int[n];

    // Read data from file into arrays
    while(infile >> name >> count && i < n) {
        if(infile.good()) {
            str_array[i] = name;
            int_array[i] = count;
            i++;
        }
    }

    // Close input file
    infile.close();

    // Sort both arrays based on string values
    sort(str_array, int_array, n);
    
    // Display sorted results
    for(i = 0; i < n; i++) {
        cout << str_array[i] << " " << int_array[i] << endl;
    }

    // Free dynamically allocated memory
    delete [] str_array;
    delete [] int_array;

    // Return success
    return 0;
}