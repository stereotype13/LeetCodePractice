/*
	Given a 32-bit signed integer, reverse digits of an integer.

Example 1:

Input: 123
Output: 321
Example 2:

Input: -123
Output: -321
Example 3:

Input: 120
Output: 21
Note:
Assume we are dealing with an environment which could only store integers within the 32-bit signed integer range: [−231,  231 − 1]. For the purpose of this problem, assume that your function returns 0 when the reversed integer overflows.
*/

#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
	int reverse(int x) {
		string number;
		if (x < 0)
			number.push_back('-');

		while (true) {
			number += to_string(abs(x % 10));
			x /= 10;

			if (x == 0)
				break;
		}

		try {
			return stoi(number);
		}
		catch (exception& e) {
			return 0;
		}

	}
};

int main() {
	Solution solution;

	int number = 123;
	cout << solution.reverse(number) << endl;
	
	number = -321;
	cout << solution.reverse(number) << endl;
	cin.get();
}