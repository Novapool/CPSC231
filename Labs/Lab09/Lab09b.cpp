/***************************************
 * Lab 09b � Recursive Coin Changer
 * Written by Laith Assaf
 ***************************************/

#include <iostream>
using namespace std;

int coins(int);

/***************************************
 * main()
 ***************************************/
int main()
{ int cents,n;

// Get user input

  cout << "Enter an amount in cents: ";
  cin >> cents;

// Call recursive function

  n = coins(cents);
  cout << endl;

// Output results
 
  cout << n << " coins" << endl;

// Success

  return 0;
}


/***************************************
 * coins()
 * Recursive function to determine the
 * minimum number of each coin needed to
 * make change for a given amount.
 * It adds 1 + coin(n-coin) to the total 
 * because it is counting the coin it is
 * using to make change and the recursive.
 ***************************************/
int coins(int n)
{
    // Base case - when no amount left to process
    if (n == 0) 
        return 0;
    
    // Handle quarters (25¢)
    if (n >= 25) 
    {
        cout << "25 ";
        return 1 + coins(n - 25);
    }
    
    // Handle dimes (10¢)
    if (n >= 10) 
    {
        cout << "10 ";
        return 1 + coins(n - 10);
    }
    
    // Handle nickels (5¢)
    if (n >= 5) 
    {
        cout << "5 ";
        return 1 + coins(n - 5);
    }
    
    // Handle pennies (1¢)
    cout << "1 ";
    return 1 + coins(n - 1);
}