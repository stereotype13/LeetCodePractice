/*
Count the number of prime numbers less than a non-negative number, n.

Example:

Input: 10
Output: 4
Explanation: There are 4 prime numbers less than 10, they are 2, 3, 5, 7.
*/
#include <iostream>
#include <list>

using namespace std;

class Solution {
public:
	int countPrimes(int n) {
		if (n <= 2)
			return 0;

		if (n < 4)
			return 1;

		list<int> primes;

		
		for (int i = 3; i <= n; i += 2) {
			bool isPrime = true;
			for (const auto& p : primes) {
				if (i % p == 0) {
					isPrime = false;
					break;
				}

			}

			

			if (isPrime)
				primes.push_back(i);
		}

		if (n == primes.back())
			return primes.size();

		return primes.size() + 1;
	}
};

class Solution2 {
public:
	int countPrimes(int n) {
		if (n < 3)
			return 0;

		int* sieve = new int[n];
		fill_n(sieve, n, 1);

		sieve[0] = 0;
		sieve[1] = 0;

		for (int i = 2; i < n; ++i) {
			if (sieve[i] == 0) {
				continue;
			}

			for (int j = i * 2; j < n; j += i) {
				sieve[j] = 0;
			}
				
		}

		int sum = 0;
		for (int i = 0; i < n; ++i) {
			sum += sieve[i];
		}

		delete [] sieve;
		return sum;
	}
};

int main(int argc, char* argv[]) {
	Solution2 solution;

	cout << solution.countPrimes(0) << endl;

	cin.get();

	return 0;
}