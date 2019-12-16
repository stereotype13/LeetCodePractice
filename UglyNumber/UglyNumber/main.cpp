/*
Write a program to check whether a given number is an ugly number.

Ugly numbers are positive numbers whose prime factors only include 2, 3, 5.

Example 1:

Input: 6
Output: true
Explanation: 6 = 2 × 3
Example 2:

Input: 8
Output: true
Explanation: 8 = 2 × 2 × 2
Example 3:

Input: 14
Output: false
Explanation: 14 is not ugly since it includes another prime factor 7.
Note:

1 is typically treated as an ugly number.
Input is within the 32-bit signed integer range: [−2^31,  2^31 − 1].
*/
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	bool isUgly(int num) {
		if (num < 1)
			return false;

		if (num == 1 || num == 4)
			return true;

		vector<int> primeFactors{ 2, 3, 5 };

		while (num > 5) {
			bool isDivisible = false;
			for (const auto& p : primeFactors) {
				if (num % p == 0) {
					num /= p;
					isDivisible = true;
					break;
				}
			}
			if (isDivisible)
				continue;

			return false;
		}
		return true;
	}
};

int main(int argc, char* argv[]) {
	Solution solution;
	cout << solution.isUgly(6) << endl;
	cout << solution.isUgly(8) << endl;
	cout << solution.isUgly(14) << endl;

	cin.get();
	return 0;
}