/*
Given a non-negative integer c, your task is to decide whether there're two integers a and b such that a2 + b2 = c.

Example 1:

Input: 5
Output: True
Explanation: 1 * 1 + 2 * 2 = 5


Example 2:

Input: 3
Output: False
*/
#include <iostream>

using namespace std;

class Solution {
public:
	bool judgeSquareSum(int c) {
	

		for (int i = 0; i <= sqrt(c); ++i) {
			if (i * i + pow(floor(sqrt(c - i * i)), 2) == c)
				return true;

		}
		return false;
	}
};

int main(int argc, const char* argv[]) {
	Solution solution;
	cout << boolalpha << solution.judgeSquareSum(5) << endl;
	cout << boolalpha << solution.judgeSquareSum(3) << endl;
	cout << boolalpha << solution.judgeSquareSum(999999999) << endl;
	cout << boolalpha << solution.judgeSquareSum(8) << endl;

	cin.get();
	return 0;
}