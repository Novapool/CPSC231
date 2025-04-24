/************************************
 * Lab22.cpp
 * Written by Laith Assaf
 ************************************/
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
using namespace std;

#include "Node.h"

/******************************
 * main()
 ******************************/
int main()
{ int i,n;
  int source_index,target_index,distance;
  string fname,source_name,target_name;
  fstream in;
  node map[NODE_MAX];

// Initialize

  n = 0;
  cout << left;

// Get file name

  cout << "Enter file name: ";
  cin >> fname;

// Open file

  in.open(fname,ios::in);

// Loop through file

  while(!in.eof())
    { in >> source_name >> target_name >> distance;
      
// Add to array 

      if(in.good())
        { 
          // Find source node or add it if it doesn't exist
          source_index = -1;
          for(i=0; i<n; i++)
            { 
              if(map[i].get_value() == source_name)
                { 
                  source_index = i;
                  break;
                }
            }
          
          if(source_index == -1)
            { 
              map[n].set_value(source_name);
              source_index = n;
              n++;
            }
          
          // Find target node or add it if it doesn't exist
          target_index = -1;
          for(i=0; i<n; i++)
            { 
              if(map[i].get_value() == target_name)
                { 
                  target_index = i;
                  break;
                }
            }
          
          if(target_index == -1)
            { 
              map[n].set_value(target_name);
              target_index = n;
              n++;
            }
          
          // Connect the nodes
          map[source_index].connect(&map[target_index], distance);
        }; 
    };
 
// Close file

  in.close();

// Display array

  for(i=0; i<n; i++)
    map[i].put();

// Success

  return 0;
}