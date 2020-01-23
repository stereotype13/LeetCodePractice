/*
Given two integers L and R, find the count of numbers in the range [L, R] (inclusive) having a prime number of set bits in their binary representation.

(Recall that the number of set bits an integer has is the number of 1s present when written in binary. 
For example, 21 written in binary is 10101 which has 3 set bits. Also, 1 is not a prime.)

Example 1:

Input: L = 6, R = 10
Output: 4
Explanation:
6 -> 110 (2 set bits, 2 is prime)
7 -> 111 (3 set bits, 3 is prime)
9 -> 1001 (2 set bits , 2 is prime)
10->1010 (2 set bits , 2 is prime)
Example 2:

Input: L = 10, R = 15
Output: 5
Explanation:
10 -> 1010 (2 set bits, 2 is prime)
11 -> 1011 (3 set bits, 3 is prime)
12 -> 1100 (2 set bits, 2 is prime)
13 -> 1101 (3 set bits, 3 is prime)
14 -> 1110 (3 set bits, 3 is prime)
15 -> 1111 (4 set bits, 4 is not prime)
Note:

L, R will be integers L <= R in the range [1, 10^6].
R - L will be at most 10000.
*/
#include <iostream>
#include <unordered_set>

using namespace std;

class Solution {
	bool isPrime(int n) {
		if (n < 2)
			return false;

		if (n < 4)
			return true;

		for (int i = 2; i * i <= n; ++i) {
			if (n % i == 0)
				return false;
		}

		return true;
	}
public:
	int countPrimeSetBits(int L, int R) {

		int numberOfPrimes = 0;
		for (int i = L; i <= R; ++i) {
			
			int bitCount = 0;
			for (int j = 0; j < 32; ++j) {
				if (i & (1 << j))
					++bitCount;
			}
			if (isPrime(bitCount))
				++numberOfPrimes;
		}
		return numberOfPrimes;
	}
};

class Solution2 {
public:
	int countPrimeSetBits(int L, int R) {

		unordered_set<int> primes{ 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31 };

		int numberOfPrimes = 0;
		for (int i = L; i <= R; ++i) {

			int bitCount = 0;
			int temp = i;
			while (temp) {
				++bitCount;
				temp &= temp - 1;
			}
			if (primes.find(bitCount) != primes.end())
				++numberOfPrimes;
		}
		return numberOfPrimes;
	}
};

int main() {
	Solution2 solution;

	cout << solution.countPrimeSetBits(6, 10) << endl;
	cout << solution.countPrimeSetBits(10, 15) << endl;

	cin.get();
	return 0;
}