/*********************************
 * Midterm 01
 * Written by Mark M Bowman
 *********************************/
#include <iostream>
#include <string>
using namespace std;

/*************************************
 * minimum()
 * Template function to find the minimum 
 * value in an array
 * Written by Laith Assaf
 *************************************/
template <class T>
T minimum(T array[], int size)
{ 
    T min = array[0];
    
    for (int i = 1; i < size; i++)
    {
        if (array[i] < min)
        {
            min = array[i];
        }
    }
    
    return min;
}

/*************************************
 * maximum()
 * Template function to find the maximum 
 * value in an array
 * Written by Laith Assaf
 *************************************/
template <class T>
T maximum(T array[], int size)
{ 
    T max = array[0];
    
    for (int i = 1; i < size; i++)
    {
        if (array[i] > max)
        {
            max = array[i];
        }
    }
    
    return max;
}

/*************************************
 * main()
 * Program entry point that demonstrates
 * the minimum and maximum functions
 *************************************/
int main()
{
    int imap[10] = { 5,1,7,8,6,7,5,3,0,9 };
    float fmap[5] = { 3.14F,2.13F,6.02F,9.88F,1.46F };
    string smap[7] = { "Richard","David","Mark","Frank","Susan","Kathy","John" };

    // Display minimums
    
    cout << "Minimums: ";
    cout << minimum(imap,10) << ", ";
    cout << minimum(fmap,5) << ", ";
    cout << minimum(smap,7) << endl;

    // Display maximums
    
    cout << "Maximums: ";
    cout << maximum(imap,10) << ", ";
    cout << maximum(fmap,5) << ", ";
    cout << maximum(smap,7) << endl;

    // Success
    
    return 0;
}