/*************************************
 * Lab 00
 * Written by Laith Assaf 01-Jan-25
 *************************************/

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
using namespace std;

#define ARRAY_MAX  20

/***********************************
 * sort()
 * This function implements bubble sort to arrange strings
 * in alphabetical order. It compares adjacent elements and
 * swaps them if they are in the wrong order.
 ***********************************/
void sort(string map[], int n)
{
    string temp;
    int i;
    int j;
    
    
    for (i = 0; i < n - 1; i++)
    {
        for ( j = 0; j < n - i - 1; j++)
        {
            if (map[j] > map[j+1])
            {
                temp = map[j];
                map[j] = map[j+1];
                map[j+1] = temp;
            }
        }
    }
    
}

/***********************************
 * Main()
 * The main function will read in a list of strings from a file and print them.
 * Then it will sort those same words using the sort function and print them.
 ***********************************/
int main()
{ 
    string map[ARRAY_MAX];  
    int count;          
    string file;
    int i;
    
    count = 0;
    
    cout << "Enter file name: ";
    cin >> file;
    cout << endl;
    
    ifstream fin(file);  
    
    while (fin >> map[count] && count < ARRAY_MAX) 
    {
        count++;
    }

    cout << "Unsorted Array" << endl;
    cout << "----------------" << endl;
    
    for (i = 0; i < count; i++) 
    {
        cout << map[i] << " ";
    }
    cout << endl << endl;

    sort(map, count);

    cout << "Sorted Array" << endl;
    cout << "------------------------" << endl;
    
    for (i = 0; i < count; i += 2) 
    {
        cout << left << setw(12) << map[i];
        
        if (i + 1 < count)
        {
            cout << map[i + 1];
        }
        cout << endl;
    }

    fin.close();  
    return 0;
}