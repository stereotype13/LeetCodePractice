/*
The problem differs from finding common substrings. Unlike substrings, subsequences are not required to occupy consecutive positions within the original sequences.

X: ABCBDAB
Y: BDCABA

The length of LCS is 4
BDAB, BCAB, BCBA
*/

#include <iostream>
#include <string>
#include <unordered_map>
#include <algorithm>

using namespace std;


class Solution {
public:
	int findLengthOfLCS(string& s1, string& s2) {
		if (s1.empty() || s2.empty())
			return 0;

		if (s2.size() > s1.size())
			swap(s1, s2);

		unordered_map<char, int> charsSeenBys1, charsSeenBys2;

		int characterCount = 0;
		int s1MinIndex = -1, s2MinIndex = -1;

		for (unsigned int i = 0; i < s1.size(); ++i) {
			char s1Char = s1[i];
			charsSeenBys1[s1Char] = i;

			char s2Char;
			if (i < s2.size()) {
				s2Char = s2[i];
				charsSeenBys2[s2Char] = i;
			}

			if (charsSeenBys2.find(s1Char) != charsSeenBys2.end() && charsSeenBys2[s1Char] > s2MinIndex) {
				//found s1Char in s2
				s2MinIndex = charsSeenBys2[s1Char];
				s1MinIndex = i;
				++characterCount;
				if (s2MinIndex == s2.size() - 1)
					return characterCount;

				continue;
			}

			if (charsSeenBys1.find(s2Char) != charsSeenBys1.end() && charsSeenBys1[s2Char] > s1MinIndex) {
				s1MinIndex = charsSeenBys1[s2Char];
				s2MinIndex = i;
				++characterCount;
			}
		}
		return characterCount;
	}

};

int main(int argc, char* argv[]) {
	Solution solution1;
	string s1 = "ABCBDAB";
	string s2 = "BDCABA";
	cout << solution1.findLengthOfLCS(s1, s2) << endl;

	s1 = "XXXXBCA";
	s2 = "ABDCA";
	cout << solution1.findLengthOfLCS(s1, s2) << endl;

	s1 = "AAA";
	s2 = "AAAA";
	cout << solution1.findLengthOfLCS(s1, s2) << endl;

	s1 = "ABC";
	s2 = "DEF";
	cout << solution1.findLengthOfLCS(s1, s2) << endl;

	s1 = "XXXXXXXXXXAXXXXX";
	s2 = "AAAA";
	cout << solution1.findLengthOfLCS(s1, s2) << endl;

	s1 = "AAAA";
	s2 = "XXXXXXXXXXAXXXXX";
	cout << solution1.findLengthOfLCS(s1, s2) << endl;



	cin.get();

	return 0;
}