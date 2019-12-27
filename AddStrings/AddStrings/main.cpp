/*
Given two non-negative integers num1 and num2 represented as string, return the sum of num1 and num2.

Note:

The length of both num1 and num2 is < 5100.
Both num1 and num2 contains only digits 0-9.
Both num1 and num2 does not contain any leading zero.
You must not use any built-in BigInteger library or convert the inputs to integer directly.
*/
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	string addStrings(string num1, string num2) {
		int length = max(num1.size(), num2.size());
		
		if (num2.size() > num1.size())
			swap(num1, num2);

		vector<int> num1Vector(length, 0);
		vector<int> num2Vector(length, 0);
		vector<int> result;

		for (int i = 0; i < num1.size(); ++i) 
			num1Vector[i] = num1[i] - '0';

		int offset = length - num2.size();
		for (int i = 0; i < num2.size(); ++i)
			num2Vector[i + offset] = num2[i] - '0';

		reverse(num1Vector.begin(), num1Vector.end());
		reverse(num2Vector.begin(), num2Vector.end());
		int carry = 0;
		for (int i = 0; i < length; ++i) {
			int sum = num1Vector[i] + num2Vector[i] + carry;
			int digit = sum % 10;
			result.push_back(digit);
			carry = sum / 10;
		}

		if (carry != 0)
			result.push_back(carry);

		string resultString = "";
		for (int i = result.size() - 1; i > -1; --i) {
			if (result[i] == 0 && resultString == "")
				continue;

			resultString += '0' + result[i];
		}
		if (resultString == "")
			resultString = "0";

		return resultString;
	}
};

int main(int argc, char* argv[]) {
	Solution solution;
	cout << solution.addStrings("8", "5") << endl;
	cout << solution.addStrings("999", "999") << endl;
	cout << solution.addStrings("98", "9") << endl;
	cout << solution.addStrings("9999999999999999999999999", "1") << endl;
	cin.get();
	return 0;
}