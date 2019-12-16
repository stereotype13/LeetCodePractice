/*
Roman numerals are represented by seven different symbols: I, V, X, L, C, D and M.

Symbol       Value
I             1
V             5
X             10
L             50
C             100
D             500
M             1000
For example, two is written as II in Roman numeral, just two one's added together. Twelve is written as, XII, which is simply X + II. The number twenty seven is written as XXVII, which is XX + V + II.

Roman numerals are usually written largest to smallest from left to right. However, the numeral for four is not IIII. Instead, the number four is written as IV. Because the one is before the five we subtract it making four. The same principle applies to the number nine, which is written as IX. There are six instances where subtraction is used:

I can be placed before V (5) and X (10) to make 4 and 9.
X can be placed before L (50) and C (100) to make 40 and 90.
C can be placed before D (500) and M (1000) to make 400 and 900.
Given a roman numeral, convert it to an integer. Input is guaranteed to be within the range from 1 to 3999.

Example 1:

Input: "III"
Output: 3
Example 2:

Input: "IV"
Output: 4
Example 3:

Input: "IX"
Output: 9
Example 4:

Input: "LVIII"
Output: 58
Explanation: L = 50, V= 5, III = 3.
Example 5:

Input: "MCMXCIV"
Output: 1994
Explanation: M = 1000, CM = 900, XC = 90 and IV = 4.
*/
#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
	int romanToInt(string s) {
		if (s.size() < 1)
			return 0;

		unordered_map<char, int> numeralMap;

		numeralMap['I'] = 1;
		numeralMap['V'] = 5;
		numeralMap['X'] = 10;
		numeralMap['L'] = 50;
		numeralMap['C'] = 100;
		numeralMap['D'] = 500;
		numeralMap['M'] = 1000;

		int result = 0;
		for (int i = 0; i < s.size(); ++i) {
			char c = s.at(i);

			switch (c) {
			case 'I':
				if (i < s.size() - 1 && (s.at(i + 1) == 'V' || s.at(i + 1) == 'X')) {
					result += numeralMap[s.at(i + 1)] - numeralMap[c];
					++i;
					continue;
				}
				result += numeralMap[c];
				continue;

			case 'X':
				if (i < s.size() - 1 && (s.at(i + 1) == 'L' || s.at(i + 1) == 'C')) {
					result += numeralMap[s.at(i + 1)] - numeralMap[c];
					++i;
					continue;
				}
				result += numeralMap[c];
				continue;

			case 'C':
				if (i < s.size() - 1 && (s.at(i + 1) == 'D' || s.at(i + 1) == 'M')) {
					result += numeralMap[s.at(i + 1)] - numeralMap[c];
					++i;
					continue;
				}
				result += numeralMap[c];
				continue;

			default:
				result += numeralMap[c];
			}
		}

		return result;
	}
};

int main() {
	Solution solution;

	string s1{ "III" };
	string s2{ "IV" };
	string s3{ "IX" };
	string s4{ "LVIII" };
	string s5{ "MCMXCIV" };

	cout << s1 << ": " << solution.romanToInt(s1) << endl;
	cout << s2 << ": " << solution.romanToInt(s2) << endl;
	cout << s3 << ": " << solution.romanToInt(s3) << endl;
	cout << s4 << ": " << solution.romanToInt(s4) << endl;
	cout << s5 << ": " << solution.romanToInt(s5) << endl;

	cin.get();
}