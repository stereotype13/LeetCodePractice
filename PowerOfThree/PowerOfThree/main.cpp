/*
Given an integer, write a function to determine if it is a power of three.

Example 1:

Input: 27
Output: true
Example 2:

Input: 0
Output: false
Example 3:

Input: 9
Output: true
Example 4:

Input: 45
Output: false
Follow up:
Could you do it without using any loop / recursion?
*/
#include <iostream>

using namespace std;

class Solution {
public:
	bool isPowerOfThree(int n) {
		long long int result = 1;

		do {
			if (result == n)
				return true;

			result *= 3;
		} while (result <= n);

		return false;
	}
};

int main(int argc, char* argv[]) {
	Solution solution;
	cout << solution.isPowerOfThree(3) << endl;
	cout << solution.isPowerOfThree(5) << endl;
	cout << solution.isPowerOfThree(27) << endl;

	cin.get();
	return 0;
}