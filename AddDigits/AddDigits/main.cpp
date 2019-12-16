/*
Given a non-negative integer num, repeatedly add all its digits until the result has only one digit.

Example:

Input: 38
Output: 2
Explanation: The process is like: 3 + 8 = 11, 1 + 1 = 2.
			 Since 2 has only one digit, return it.
Follow up:
Could you do it without any loop/recursion in O(1) runtime?
*/
#include <iostream>

using namespace std;

class Solution {
public:
	int addDigits(int num) {
		int result = 0;
		
		while (num > 9) {
			long long int powerOfTen = 1;
			while (num / powerOfTen) {
				result += (num / powerOfTen) % 10;
				powerOfTen *= 10;
			}
			num = result;
			result = 0;
		}
		return num;
	}
};

int main(int argc, char* argv[]) {
	Solution solution;
	cout << solution.addDigits(38) << endl;
	cout << solution.addDigits(7) << endl;
	cout << solution.addDigits(12) << endl;
	cout << solution.addDigits(103) << endl;

	cin.get();
	return 0;
}