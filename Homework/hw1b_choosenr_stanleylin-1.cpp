/*
	Author: Stanley Lin
	I pledge my honor that I have abided by the Stevens Honor System.
*/

#include <iostream>
#include <iomanip>
using namespace std;
 
double choose(int n, int r) 
{
    double memo[n+1][r+1]; //create multidimensional array to hold values, memoization
  
    for (int a = 0; a <= n; a++)  //loop as many times as number of objects to choose from (n) 
    { 
        for (int b = 0; b <= r; b++) // loop until number of all choices (r) are done
        { 
            if (b != 0 && b != a) //make sure n is not 0 and b is not equal to itself because both of these result in 1
                memo[a][b] = memo[a-1][b-1] + memo[a-1][b]; //formula for binomial recursive 
			else //if r is equal to 0 or n is equal to itself the result is 1
				memo[a][b] = 1;
        } 
    } 
    return memo[n][r]; 
} 

int main() 
{ 	
	cout << "This program will calculate choose(n,r)" << "\n" << "The result will output the number of combinations of r items that can be selected from a set of n items" << endl;
	int n,r;
	cout << "Enter number of items in the set(n):" << endl;
	cin >> n;
	cout << "Enter number of items selected from the set(r): " << endl;
	cin >> r;
	cout << setprecision(20);
	cout <<  "\n" << "Result: " << choose(n,r);
    return 0; 
}

