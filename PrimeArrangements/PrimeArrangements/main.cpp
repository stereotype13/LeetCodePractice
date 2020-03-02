/*
Return the number of permutations of 1 to n so that prime numbers are at prime indices (1-indexed.)

(Recall that an integer is prime if and only if it is greater than 1, and cannot be written as a product of two positive integers both smaller than it.)

Since the answer may be large, return the answer modulo 10^9 + 7.



Example 1:

Input: n = 5
Output: 12
Explanation: For example [1,2,5,4,3] is a valid permutation, but [5,2,3,4,1] is not because the prime number 5 is at index 1.

Example 2:

Input: n = 100
Output: 682289015



Constraints:

	1 <= n <= 100


*/
#include <iostream>
#include <math.h>

using namespace std;

class Solution {
public:
	int numPrimeArrangements(int n) {
		unsigned sieve[100];
		
		sieve[0] = 0;

		for (int i = 1; i < 100; ++i) 
			sieve[i] = 1;
		

		for (int i = 1; i < n; ++i) {
			
			for (int j = i + (i + 1); j < n; j += (i + 1)) {
				sieve[j] = 0;
			}
		}

		int numberOfPrimes = 0;
		for (int i = 0; i < n; ++i) {
			if (sieve[i])
				++numberOfPrimes;
		}

		int numberOfNonPrimes = n - numberOfPrimes;

		if (numberOfNonPrimes < numberOfPrimes)
			swap(numberOfNonPrimes, numberOfPrimes);

		unsigned int long long primeFact = 1;

		unsigned int long long temp = 1;
		for (unsigned int long long i = 1; i <= (unsigned int long long)numberOfNonPrimes; ++i) {
			temp = (temp * i) % (unsigned int long long)(pow(10, 9) + 7);
			if (i == numberOfPrimes)
				primeFact = temp;
		}

		return (temp * primeFact) % int(pow(10, 9) + 7);
	}
};

int main(int argc, const char* argv[]) {
	Solution solution;

	cout << solution.numPrimeArrangements(5) << endl;
	cout << solution.numPrimeArrangements(100) << endl;

	cin.get();
	return 0;
}