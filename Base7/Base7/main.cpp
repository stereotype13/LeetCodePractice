/*
Given an integer, return its base 7 string representation.

Example 1:
Input: 100
Output: "202"
Example 2:
Input: -7
Output: "-10"
Note: The input will be in range of [-1e7, 1e7].
*/
#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
	string convertToBase7(int num) {
		if (num == 0)
			return "0";

		string result = "";
		bool isNegative = num < 0;
		num = abs(num);
		while (num > 0) {
			int digit = num % 7;
			num /= 7;
			result += to_string(digit);
		}
		

		if (isNegative)
			result.push_back('-');

		reverse(result.begin(), result.end());

		return result;
	}
};

int main(int argc, const char* argv[]) {
	Solution solution;
	cout << solution.convertToBase7(100) << endl;
	cout << solution.convertToBase7(-7) << endl;

	cin.get();
	return 0;
}