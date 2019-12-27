/*
Given an integer (signed 32 bits), write a function to check whether it is a power of 4.

Example 1:

Input: 16
Output: true
Example 2:

Input: 5
Output: false
Follow up: Could you solve it without loops/recursion?
*/
#include <iostream>

using namespace std;

class Solution {
public:
	bool isPowerOfFour(int num) {
		for (int n = 0; n <= 32; n += 2) 
			if ((4 << n) == num)
			return true;

		return false;
	}
};

int main(int argc, char* argv[]) {
	Solution solution;

	cout << 2 << " " << solution.isPowerOfFour(2) << endl;
	cout << 4 << " " << solution.isPowerOfFour(4) << endl;
	cout << 6 << " " << solution.isPowerOfFour(6) << endl;
	cout << 8 << " " << solution.isPowerOfFour(8) << endl;
	cout << 16 << " " << solution.isPowerOfFour(16) << endl;
	
	cin.get();
	return 0;
}