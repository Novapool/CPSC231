/*********************************
 * Lab 13
 * Edited by Laith Assaf
 *********************************/

 #include <iostream>    // For input/output operations
 #include <fstream>     // For file operations
 #include <string>      // For string operations
 #include <vector>      // For using vector data structure
 #include <queue>       // For using queue data structure
 #include <stack>       // For using stack data structure
 using namespace std;
 
 /*********************************
  * main()
  *********************************/
 int main()
 { string s;            // String to store input filename and words
   fstream infile;      // File stream for input operations
   vector<string> a;    // Vector to store words from file
   queue<string> b;     // Queue to store certain words from vector
   stack<string> c;     // Stack to store every third word from vector
   int i;               // Loop counter variable
 
 // Open file
 
   cout << "Enter file name: ";
   cin >> s;            // Get filename from user
   cout << endl;
   infile.open(s,ios::in);  // Open file in input mode
   if(!infile.is_open()) return -1;  // Exit if file cannot be opened
 
 // Read data from file
 
   cout << "Input:  ";
 
   while(infile >> s)   // Read each word from file
   {
     cout << s << " ";  // Display each word
     a.push_back(s);    // Add each word to vector
   }
   
 
 // Close file
 
   infile.close();      // Close the input file
 
 // Display vector
 
   cout << endl << "Vector: ";
   for(int i=0; i<a.size(); i++)  // Loop through all elements in vector
   {
     cout << a[i] << " ";         // Display each element
   }
   cout << endl;
 
 
 // Copy vector data
 
   for(int i=0; i<a.size(); i++)  // Loop through all elements in vector
   {
     if ((i + 1)% 3 == 0) c.push(a[i]);  // Push every third word to stack
     else b.push(a[i]);                   // Push other words to queue
   }
 
 // Display queue
 
   cout << "Queue:  ";
   while(!b.empty())    // Loop until queue is empty
   {
     cout << b.front() << " ";  // Display front element of queue
     b.pop();                   // Remove front element
   }
   cout << endl;
 
 // Display stack
   
     cout << "Stack:  ";
     while(!c.empty())    // Loop until stack is empty
     {
       cout << c.top() << " ";  // Display top element of stack
       c.pop();                 // Remove top element
     }
     cout << endl;
 
 
 // Success
 
   return 0; 
 }