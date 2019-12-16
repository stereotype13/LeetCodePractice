/*
Given a string s, find the longest palindromic substring in s. You may assume that the maximum length of s is 1000.

Example 1:

Input: "babad"
Output: "bab"
Note: "aba" is also a valid answer.
Example 2:

Input: "cbbd"
Output: "bb"
*/

#include <iostream>
#include <string>

using namespace std;

class Solution {
	bool isPalindrome(string& s, int lowIndex, int highIndex) {
		while (lowIndex <= highIndex) {
			if (s.at(lowIndex) != s.at(highIndex))
				return false;
			++lowIndex;
			--highIndex;
		}

		return true;
	}

public:
	string longestPalindrome(string s) {
		int windowSize = s.length();

		if (windowSize == 0)
			return "";

	
		for (int windowSize = s.length(); windowSize > 1; --windowSize) {
			
			for (int j = 0; j < s.length() - windowSize + 1; ++j) {
				if (isPalindrome(s, j, j + windowSize - 1))
					return s.substr(j, windowSize);
			}	
		}

		return s.substr(0, 1);
	}
};

int main(int argc, char* argv[]) {
	Solution solution;

	string s1{"babad"};
	string s2{ "cbbd" };
	string s3{ "ab" };
	string s4{ "a" };
	string s5{ "" };

	cout << "The longest palindrom of " << s1 << " is " << solution.longestPalindrome(s1) << endl;
	cout << "The longest palindrom of " << s2 << " is " << solution.longestPalindrome(s2) << endl;
	cout << "The longest palindrom of " << s3 << " is " << solution.longestPalindrome(s3) << endl;
	cout << "The longest palindrom of " << s4 << " is " << solution.longestPalindrome(s4) << endl;
	cout << "The longest palindrom of " << s5 << " is " << solution.longestPalindrome(s5) << endl;

	cin.get();
	return 0;
}