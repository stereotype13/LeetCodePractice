/*
Given an integer, write a function to determine if it is a power of two.

Example 1:

Input: 1
Output: true
Explanation: 20 = 1
Example 2:

Input: 16
Output: true
Explanation: 24 = 16
Example 3:

Input: 218
Output: false
*/
#include <iostream>
#include <bitset>

using namespace std;

class Solution {
public:
	bool isPowerOfTwo(int n) {
		if (n <= 0)
			return false;

		bitset<64> num{ (unsigned int)n };

		int sum = 0;
		for (unsigned int i = 0; i < num.size(); ++i) {
			sum += num[i];
			if (sum > 1)
				return false;
		}

		return true;
	}
};

int main(int argc, char* argv[]) {
	Solution solution;
	cout << solution.isPowerOfTwo(0) << endl;
	cout << solution.isPowerOfTwo(1) << endl;
	cout << solution.isPowerOfTwo(2) << endl;
	cout << solution.isPowerOfTwo(3) << endl;
	cout << solution.isPowerOfTwo(4) << endl;
	cout << solution.isPowerOfTwo(5) << endl;
	cout << solution.isPowerOfTwo(6) << endl;
	cout << solution.isPowerOfTwo(7) << endl;
	cout << solution.isPowerOfTwo(8) << endl;
	cout << solution.isPowerOfTwo(9) << endl;
	cout << solution.isPowerOfTwo(10) << endl;
	cout << solution.isPowerOfTwo(11) << endl;
	cout << solution.isPowerOfTwo(12) << endl;

	cin.get();
	return 0;
}