/*
Given a column title as appear in an Excel sheet, return its corresponding column number.

For example:

	A -> 1
	B -> 2
	C -> 3
	...
	Z -> 26
	AA -> 27
	AB -> 28
	...
Example 1:

Input: "A"
Output: 1
Example 2:

Input: "AB"
Output: 28
Example 3:

Input: "ZY"
Output: 701

*/
#include <iostream>
#include <string>
#include <math.h>

using namespace std;

class Solution {
public:
	int titleToNumber(string s) {
		int total = 0;

		int power = 0;
		for (int i = s.size() - 1; i > -1; --i) {
			char c = s[i];
			total += (c - 'A' + 1) * pow(26, power);
			++power;
		}
		return total;
	}
};

int main(int argc, char* argv[]) {
	Solution solution;
	string s1{ "AAA" };
	cout << solution.titleToNumber(s1) << endl;

	string s2{ "A" };
	cout << solution.titleToNumber(s2) << endl;

	cin.get();

	return 0;
}

