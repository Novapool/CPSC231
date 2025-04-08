/***************************************
 * Lab 18
 * Written by Laith Assaf
 ***************************************/

#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
using namespace std;

#define NMAX 1000

int read_array(string fname,float x[],int n);
void bubble_sort(float x[],int n);
void selection_sort(float x[],int n);
void shift_sort(float x[],int n);

int count_comp,count_swap;

/***************************************
 * main()
 ***************************************/
int main()
{ int i,n;
  float x[NMAX];
  string fname;

// Get user input

  cout << "Enter file name: ";
  cin >> fname;

// Fill array

  n = read_array(fname,x,NMAX);
  cout << n << " values read" << endl;

// Sort
  bubble_sort(x,n);

// Output list

  cout << fixed << setprecision(2);
  for(i=0;i<n;i++)
    cout << setw(10) << x[i];
  cout << endl << "Comparisons: " << count_comp << " Swaps: " << count_swap << endl;

// Success

  return 0;
}

/***************************************
 * read_array()
 ***************************************/
int read_array(string fname,float x[],int n)
{ int i;
  fstream f;

// Open file

  f.open(fname,ios::in);
  if(!f.is_open()) return 0;

// Read from file

  i = 0;
  while(i<n && !f.eof())
    { f >> x[i];
      if(f.good()) i++;
    };

// Close and return

  f.close();
  return i;
}

/***************************************
 * bubble_sort()
 ***************************************/
void bubble_sort(float x[], int n)
{ 
  int i, j;
  float temp;
  count_comp = 0;
  count_swap = 0;
  
  for (i = 0; i < n - 1; i++)
  {
    for (j = 0; j < n - i - 1; j++)
    {
      count_comp++;
      if (x[j] > x[j + 1])
      {
        temp = x[j];
        x[j] = x[j + 1];
        x[j + 1] = temp;
        count_swap++;
      }
    }
  }
}

/***************************************
 * selection_sort()
 ***************************************/
void selection_sort(float x[],int n)
{ 
  int i, j, minIndex;
  float temp;
  count_comp = 0;
  count_swap = 0;

  for (i = 0; i < n - 1; i++)
  {
    minIndex = i;
    for (j = i + 1; j < n; j++)
    {
      count_comp++;
      if (x[j] < x[minIndex])
        minIndex = j;
    }
    if (minIndex != i)
    {
      temp = x[i];
      x[i] = x[minIndex];
      x[minIndex] = temp;
      count_swap++;
    }
  }
}

/***************************************
 * shift_sort()
 ***************************************/
void shift_sort(float x[], int n)
{ 
  int i, j;
  float key;
  count_comp = 0;
  count_swap = 0;

  for (i = 1; i < n; i++)
  {
    key = x[i];
    j = i - 1;
    
    // Count initial comparison
    count_comp++;
    
    while (j >= 0 && x[j] > key)
    {
      x[j + 1] = x[j];
      j--;
      count_swap++;
      
      // Count additional comparison for the next loop check
      if (j >= 0)
        count_comp++;
    }
    
    // Only count as a swap if it actually moved
    if (j + 1 != i)
      count_swap++;
      
    x[j + 1] = key;
  }
}
