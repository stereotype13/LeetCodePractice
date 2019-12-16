/*
Given two binary strings, return their sum (also a binary string).

The input strings are both non-empty and contains only characters 1 or 0.

Example 1:

Input: a = "11", b = "1"
Output: "100"
Example 2:

Input: a = "1010", b = "1011"
Output: "10101"
*/
#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
	string addBinary(string a, string b) {
		int indexA = a.size() - 1;
		int indexB = b.size() - 1;

		string result = "";
		int carry = 0;
		while (indexA > -1 || indexB > -1 || carry == 1) {
			int aDigit = 0;
			int bDigit = 0;
			
			if (indexA > -1 && a[indexA] == '1')
				aDigit = 1;

			if (indexB > -1 && b[indexB] == '1')
				bDigit = 1;

			int sum = carry + aDigit + bDigit;

			switch (sum) {
			case 0:
				result.push_back('0');
				carry = 0;
				break;

			case 1:
				result.push_back('1');
				carry = 0;
				break;

			case 2:
				result.push_back('0');
				carry = 1;
				break;

			case 3:
				result.push_back('1');
				carry = 1;
			}
			
			--indexA;
			--indexB;
		}

		reverse(result.begin(), result.end());
		return result;
	}
};

int main(int argc, char* argv[]) {
	Solution solution;

	string a1{ "11" };
	string b1{ "1" };
	cout << solution.addBinary(a1, b1) << endl;

	string a2{ "1010" };
	string b2{ "1011" };
	cout << solution.addBinary(a2, b2) << endl;

	cin.get();
	return 0;
}