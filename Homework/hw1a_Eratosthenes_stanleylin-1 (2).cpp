/*
	Author: Stanley Lin
	I pledge my honor that I have abided by the Stevens Honor System.
*/
#include <iostream>
#include <vector>

using namespace std;

int improvedEratosthenes(int n) //O(nlog(n))
{
	vector<bool> isPrime(n + 1, 1); //vector boolean
	isPrime[0, 1] = 0;				//0 and 1 are not prime (base cases)

	for (int j = 4; j <= n; j += 2)
	{					//remove 4 and add two, 4 6 8 etc
		isPrime[j] = 0; //set these as not prime because multiples of 2
		for (int i = 3; i <= n; i += 2)
		{ //from 3 to n
			if (isPrime[i] == 1)
			{ //if it is prime
				for (int k = i * i; k <= n; k += 2 * i)
				{					//remove i^2 of the prime because it is not prime
					isPrime[k] = 0; //set it to not prime
				}
			}
		}
	}
	int count = 0;
	for (int s = 1; s <= n; s++)
	{
		if (isPrime[s] == 1)
		{
			count++;
		}
	}
	return count;
}

int main()
{
	int n;
	cout << "Improved Eratosthenes"
		 << "\n"
		 << "This program will output the number of primes between 1 and the number chosen(n) including n"
		 << "\n"
		 << "Enter number:" << endl;
	cin >> n;
	cout << "---" << endl;
	cout << improvedEratosthenes(n);
}