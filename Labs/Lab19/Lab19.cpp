/************************************
 * Lab19.cpp
 * Merge Sort Implementation
 * Updated by Laith Assaf
 ************************************/

 #include <iostream>
 #include <fstream>
 #include <string>
 using namespace std;
 
 // Constants
 #define ARRAY_MAX 10000
 
 // Function headers
 void merge(string map[], int n);
 void merge_sort(string map[], int n);
 
 /************************************
  * merge()
  * Merge two halves of an array in sorted order
  ************************************/
 void merge(string map[], int n)
 {
     int pos1, pos2, pos3;      // Indices for first half, second half, and temp array
     string temp[ARRAY_MAX];    // Temporary array to hold merged results
     
     // Initialize indices
     pos1 = 0;                  // Start of first half
     pos2 = n/2;                // Start of second half
     pos3 = 0;                  // Start of temp array
     
     // Loop while both halves have elements
     while(pos1 < n/2 && pos2 < n)
     {
         // Compare elements from both halves
         if(map[pos1] < map[pos2])
             temp[pos3++] = map[pos1++];    // Copy from first half
         else
             temp[pos3++] = map[pos2++];    // Copy from second half
     }
     
     // Copy remaining elements from first half, if any
     while(pos1 < n/2)
         temp[pos3++] = map[pos1++];
     
     // Copy remaining elements from second half, if any
     while(pos2 < n)
         temp[pos3++] = map[pos2++];
     
     // Copy temp array back to original array
     for(pos1 = 0; pos1 < n; pos1++)
         map[pos1] = temp[pos1];
 }
 
 /************************************
  * merge_sort()
  * Sort an array using the merge sort algorithm
  ************************************/
 void merge_sort(string map[], int n)
 {
     // Temporary array for merging
     string temp[ARRAY_MAX]; 
     // Base case: if array has 1 or fewer elements, it's already sorted
     if(n <= 1)
         return;
     
     // Base case: if array has exactly 2 elements, check if they need swapping
     if(n == 2)
     {
         // Swap if in wrong order
         if(map[0] > map[1])
         {
             string temp = map[0];
             map[0] = map[1];
             map[1] = temp;
         }
         return;
     }
     
     // Recursive case: divide and conquer
     // Sort first half
     merge_sort(map, n/2);
     
     // Sort second half
     merge_sort(map + n/2, n - n/2);
     
     // Merge the sorted halves
     merge(map, n);
 }
 
 /************************************
  * main()
  * Program entry point
  ************************************/
 int main()
 {   int i, n;                  
     string map[ARRAY_MAX];     
     string fname;              
     fstream infile;            
     
    // Initialize

     n = 0;
     
    // Open file

     cout << "Enter data file name: ";
     cin >> fname;
     infile.open(fname.data(), ios::in);
     if(!infile.is_open())
         return -1;
     
    // Loop through file

     while(!infile.eof())
     {
         infile >> map[n];
         
    // Update index if valid input

         if(infile.good())
             n++;
     }
     
    // Close file

     infile.close();
     
    // Sort the array

     merge_sort(map, n);
     
    // Output map
    
     cout << endl;
     for(i = 0; i < n; i++)
         cout << map[i] << endl;
     
    // Success

     return 0;
 }