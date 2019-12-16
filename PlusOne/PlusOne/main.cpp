/*
Given a non-empty array of digits representing a non-negative integer, plus one to the integer.

The digits are stored such that the most significant digit is at the head of the list, and each element in the array contain a single digit.

You may assume the integer does not contain any leading zero, except the number 0 itself.

Example 1:

Input: [1,2,3]
Output: [1,2,4]
Explanation: The array represents the integer 123.
Example 2:

Input: [4,3,2,1]
Output: [4,3,2,2]
Explanation: The array represents the integer 4321.
*/
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	vector<int> plusOne(vector<int>& digits) {
		

		for (int i = digits.size() - 1; i > -1; --i) {
			if ((digits[i] + 1) % 10) {
				digits[i]++;
				return digits;
			}
			digits[i] = 0;
		}

		vector<int> result{ 1 };
		for (int i = 0; i < digits.size(); ++i) {
			result.push_back(0);
		}
		return result;
	}
};

void printDigits(const vector<int>& digits) {
	for (const auto& d : digits) {
		cout << d << "\t";
	}
	cout << endl;
}

int main(int argc, char* argv[]) {
	Solution solution;

	vector<int> digits1{ 1, 2, 3 };
	printDigits(solution.plusOne(digits1));

	vector<int> digits2{ 9, 8, 9 };
	printDigits(solution.plusOne(digits2));

	vector<int> digits3{ 9, 9, 9 };
	printDigits(solution.plusOne(digits3));

	vector<int> digits4{ 0 };
	printDigits(solution.plusOne(digits4));

	vector<int> digits5{ 9 };
	printDigits(solution.plusOne(digits5));

	cin.get();

	return 0;
}