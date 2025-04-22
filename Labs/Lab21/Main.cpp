/************************************
 * Lab21.cpp
 * Updated by Laith Assaf
 * Extra Credit: Add new nodes and edges
 ************************************/

 #include <iostream>
 #include <iomanip>
 #include <fstream>
 #include <string>
 using namespace std;
 
 // Constants
 #define GRAPH_MAX 10
 
 // Function headers
 void display(int n);
 void add_node(int &n);
 void add_edge(int n);
 
 // Global data
 string name[GRAPH_MAX] = { "A","B","C","D","E" };
 float edge[GRAPH_MAX][GRAPH_MAX] = 
 { { -1.00, 2.00, 1.70,-1.00,-1.00 },
   { -1.00,-1.00, 3.50, 1.50,-1.00 },
   { -1.00,-1.00,-1.00, 2.40,-1.00 },
   { -1.00,-1.00,-1.00,-1.00, 4.10 },
   {  9.99,-1.00,-1.00,-1.00,-1.00 }
 };
 
 /******************************
  * main()
  ******************************/
 int main()
 { int i, n;
   int source_index, target_index;
   string source, target, choice;
   float distance, total;
   bool done;
 
   // Initialize
   n = 5;
   total = 0.0;
   done = false;
 
   // Main program loop
   while(!done)
   { 
     // Display current graph
     display(n);
     cout << endl;
 
     // Display menu
     cout << "Select an option:" << endl;
     cout << "1. Find distance between nodes" << endl;
     cout << "2. Travel through multiple nodes" << endl;
     cout << "3. Add a new node" << endl;
     cout << "4. Add a new edge" << endl;
     cout << "5. Exit" << endl;
     cout << "Enter choice (1-5): ";
     cin >> choice;
     cout << endl;
 
     // Process menu selection
     if(choice == "1")
     { 
       // Find distance between two nodes
       cout << "Enter source: ";
       cin >> source;
 
       // Find source index
       source_index = -1;
       for(i = 0; i < n; i++)
       { 
         if(name[i] == source)
         { 
           source_index = i;
         }
       }
 
       // Get target
       cout << "Enter target: ";
       cin >> target;
 
       // Find target index
       target_index = -1;
       for(i = 0; i < n; i++)
       { 
         if(name[i] == target)
         { 
           target_index = i;
         }
       }
 
       // Check if edge exists
       if(source_index != -1 && target_index != -1 && edge[source_index][target_index] != -1.0)
       { 
         // Display distance
         distance = edge[source_index][target_index];
         cout << name[source_index] << " to " << name[target_index] << " = " 
              << fixed << setprecision(2) << distance << endl;
       }
       else
       { 
         // Display error if no edge exists
         cout << "No edge from " << source << " to " << target << endl;
       }
     }
     else if(choice == "2")
     { 
       // Travel through multiple nodes
       total = 0.0;
       
       cout << "Enter source: ";
       cin >> source;
 
       // Find source index
       source_index = -1;
       for(i = 0; i < n; i++)
       { 
         if(name[i] == source)
         { 
           source_index = i;
         }
       }
 
       // Loop until user enters "Quit"
       target = "";
       while(target != "Quit")
       { 
         // Prompt user for target node
         cout << "Enter target: ";
         cin >> target;
         
         // Exit loop if "Quit" is entered
         if(target == "Quit")
         { 
           cout << "Total distance = " << fixed << setprecision(2) << total << endl;
           continue;
         }
         
         // Find target index
         target_index = -1;
         for(i = 0; i < n; i++)
         { 
           if(name[i] == target)
           { 
             target_index = i;
           }
         }
         
         // Check if edge exists
         if(source_index != -1 && target_index != -1 && edge[source_index][target_index] != -1.0)
         { 
           // Display and update distance
           distance = edge[source_index][target_index];
           cout << name[source_index] << " to " << name[target_index] << " = " 
                << fixed << setprecision(2) << distance << endl;
           
           // Add to total distance
           total += distance;
           
           // Update source for next iteration
           source_index = target_index;
         }
         else
         { 
           // Display error if no edge exists
           cout << "No edge from " << name[source_index] << " to " << target << endl;
         }
       }
     }
     else if(choice == "3")
     { 
       // Add a new node
       add_node(n);
     }
     else if(choice == "4")
     { 
       // Add a new edge
       add_edge(n);
     }
     else if(choice == "5")
     { 
       // Exit program
       done = true;
     }
     else
     { 
       cout << "Invalid choice. Please try again." << endl;
     }
     
     cout << endl;
   }
 
   // Success
   return 0;
 }
 
 /******************************
  * display()
  * Display the current graph
  ******************************/
 void display(int n)
 { int i, j;
 
   // Initialize
   cout << fixed << setprecision(2);
 
   // Target row
   for(j = 0; j < n; j++)
     cout << setw(7) << name[j];
   cout << endl;
 
   // Loop through Sources
   for(i = 0; i < n; i++)
   { 
     cout << setw(2) << name[i];       // Name
     for(j = 0; j < n; j++)
       cout << setw(7) << edge[i][j];  // Edge distance
     cout << endl;
   }
 }
 
 /******************************
  * add_node()
  * Add a new node to the graph
  ******************************/
 void add_node(int &n)
 { int i;
   string new_node;
 
   // Check if maximum size reached
   if(n >= GRAPH_MAX)
   { 
     cout << "Maximum number of nodes reached." << endl;
     return;
   }
 
   // Get new node name
   cout << "Enter new node name: ";
   cin >> new_node;
 
   // Check if node already exists
   for(i = 0; i < n; i++)
   { 
     if(name[i] == new_node)
     { 
       cout << "Node already exists." << endl;
       return;
     }
   }
 
   // Add new node
   name[n] = new_node;
 
   // Initialize all edges for the new node to -1.0 (no connection)
   for(i = 0; i < GRAPH_MAX; i++)
   { 
     edge[n][i] = -1.0;
     edge[i][n] = -1.0;
   }
 
   // Increment node count
   n++;
 
   cout << "Node " << new_node << " added successfully." << endl;
 }
 
 /******************************
  * add_edge()
  * Add a new edge to the graph
  ******************************/
 void add_edge(int n)
 { int i, source_index, target_index;
   string source, target;
   float weight;
 
   // Get source node
   cout << "Enter source node: ";
   cin >> source;
 
   // Find source index
   source_index = -1;
   for(i = 0; i < n; i++)
   { 
     if(name[i] == source)
     { 
       source_index = i;
     }
   }
 
   // Check if source exists
   if(source_index == -1)
   { 
     cout << "Source node does not exist." << endl;
     return;
   }
 
   // Get target node
   cout << "Enter target node: ";
   cin >> target;
 
   // Find target index
   target_index = -1;
   for(i = 0; i < n; i++)
   { 
     if(name[i] == target)
     { 
       target_index = i;
     }
   }
 
   // Check if target exists
   if(target_index == -1)
   { 
     cout << "Target node does not exist." << endl;
     return;
   }
 
   // Get edge weight
   cout << "Enter edge weight: ";
   cin >> weight;
 
   // Add edge
   edge[source_index][target_index] = weight;
 
   cout << "Edge from " << source << " to " << target 
        << " with weight " << fixed << setprecision(2) << weight 
        << " added successfully." << endl;
 }