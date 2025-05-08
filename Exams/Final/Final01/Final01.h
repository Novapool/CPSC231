/*********************************
 * Final 01
 * Created by Laith Assaf
 * Sources: Chapter Notes 15.03, 21
 *********************************/

 #ifndef FINAL01_H
 #define FINAL01_H
 
 /***********************************
  * reverse()
  * Recursively reverses the elements of an array
  * Template function that works with any array type
  ***********************************/
 template <typename T>
 void reverse(T arr[], int n)
 { 
   // Base case - if array is empty or only has one element
   if (n <= 1)
     return;
     
   // Swap the first and last elements
   T temp = arr[0];
   arr[0] = arr[n-1];
   arr[n-1] = temp;
   
   // Recursively reverse the rest of the array (excluding first and last elements)
   reverse(arr+1, n-2);
 }
 
 #endif // FINAL01_H