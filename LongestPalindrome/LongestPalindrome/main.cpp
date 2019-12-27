/*
Given a string which consists of lowercase or uppercase letters, find the length of the longest palindromes that can be built with those letters.

This is case sensitive, for example "Aa" is not considered a palindrome here.

Note:
Assume the length of given string will not exceed 1,010.

Example:

Input:
"abccccdd"

Output:
7

Explanation:
One longest palindrome that can be built is "dccaccd", whose length is 7.
*/
#include <iostream>
#include <string>
#include <unordered_map>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
	int longestPalindrome(string s) {
		if (s.empty())
			return 0;

		if (s.size() == 1)
			return 1;

		unordered_map<char, int> charCount;
		for (const auto& c : s)
			charCount[c]++;

		int longestPalindromeLength = 0;
		vector<int> vectorOfOdds;
		for (const auto& p : charCount) {
			if (p.second % 2 == 0)
				longestPalindromeLength += p.second;
			else
				vectorOfOdds.push_back(p.second);
		}

		sort(vectorOfOdds.begin(), vectorOfOdds.end());

		if (!vectorOfOdds.empty()) {
			for (int i = 0; i < vectorOfOdds.size() - 1; ++i)
				longestPalindromeLength += (vectorOfOdds[i] - 1);
			longestPalindromeLength += vectorOfOdds.back();
		}

		return longestPalindromeLength;
	}
};

int main(int argc, char* argv[]) {
	Solution solution;
	cout << solution.longestPalindrome("bb") << endl;
	cout << solution.longestPalindrome("abccccdd") << endl;
	cout << solution.longestPalindrome("abccccddeeeee") << endl;

	cin.get();
	return 0;
}