/*
Determine whether an integer is a palindrome. An integer is a palindrome when it reads the same backward as forward.

Example 1:

Input: 121
Output: true
Example 2:

Input: -121
Output: false
Explanation: From left to right, it reads -121. From right to left, it becomes 121-. Therefore it is not a palindrome.
Example 3:

Input: 10
Output: false
Explanation: Reads 01 from right to left. Therefore it is not a palindrome.
*/

#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
	bool isPalindrome(int x) {
		if (x < 0)
			return false;

		string number = to_string(x);

		int length = (int)number.length();

		int lowIndex = 0, highIndex = length - 1;
		while (lowIndex < highIndex) {
			if (number.at(lowIndex) != number.at(highIndex))
				return false;

			++lowIndex;
			--highIndex;
		}

		return true;
	}
};

int main() {
	Solution solution;
	int number1 = 121;
	int number2 = -121;

	cout << solution.isPalindrome(number1) << endl;
	cout << solution.isPalindrome(number2) << endl;
	cin.get();
}