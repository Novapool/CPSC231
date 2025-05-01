/*********************************
 * Lab 24
 * Created by Mark Bowman
 *********************************/

 #include <iostream>
 #include <string>
 #include <fstream>
 using namespace std;
 
 #define TABLE_SIZE  21
 
 #include "Hash Table.h"
 
 /*********************************
  * main()
  *********************************/
 int main()
 { int id;
   string fname;
   fstream in;
   hash_table h(TABLE_SIZE);
   node p;
 
 // Open file
 
   cout << "Enter file name: ";
   cin >> fname;
   in.open(fname.data(),ios::in);
   if(!in.is_open()) return -1;
 
 // Load file
 
   while(p.get(in))
     { 
       h.insert(p);
     };
 
 // Close file
 
   in.close();
 
 // Display table
 
   cout << endl;
   h.dump(cout);
 
 // Collisions
 
   cout << "Insert collisions: " << h.collisions() << endl;
   cout << endl;
 
 // Find
 
   cout << "Enter ID to find ";
   cin >> id;
   
   p = h.find(id);
   p.put(cout);
   cout << endl;
 
 // Collisions
 
   cout << "Find collisions: " << h.collisions() << endl;
 
 // Success
 
   return 0;
 }