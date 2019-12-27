/*
Given a non-empty string check if it can be constructed by taking a substring of it and appending multiple copies of the substring together. 
You may assume the given string consists of lowercase English letters only and its length will not exceed 10000.



Example 1:

Input: "abab"
Output: True
Explanation: It's the substring "ab" twice.
Example 2:

Input: "aba"
Output: False
Example 3:

Input: "abcabcabcabc"
Output: True
Explanation: It's the substring "abc" four times. (And the substring "abcabc" twice.)
*/
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
	bool repeatedSubstringPattern(string s) {
		if (s.size() < 2)
			return false;

		vector<char> subString{s[0]};
		vector<char> temp;
		int subStringIndex = 0;
		for (int i = 1; i < s.size(); ++i) {
			if (s[i] == subString[subStringIndex % subString.size()]) {
				subStringIndex++;
				temp.push_back(s[i]);
				continue;
			}
			
			for (const auto& c : temp) {
				if (subString.size() < s.size() / 2)
					subString.push_back(c);
				else
					break;
			}
			temp.clear();

			if (subString.size() < s.size() / 2)
				subString.push_back(s[i]);
			else
				break;

			subStringIndex = 0;

		}

		if (subString.size() <= s.size() / 2 && subString.back() == s.back() && subString.size() > 1)
			return true;

		return false;
	}
};

class Solution2 {
public:
	bool repeatedSubstringPattern(string s) {
		if (s.size() < 2)
			return false;

		if (s.size() == 2)
			return s[0] == s[1];

		vector<char> subString;

		int divisor = 2;
		while (s.size() % divisor != 0 && divisor < s.size() / 2)
			++divisor;
		int subStringSize = s.size() / divisor;
		while (subStringSize >= 1) {
			for (int i = 0; i < subStringSize; ++i) {
				subString.push_back(s[i]);
			}

			int subStringIndex = 0;
			for (int i = subStringSize; i < s.size(); ++i) {

				if (i == s.size() - 1 && subString[subStringIndex % subStringSize] == s[i])
					return true;

				if (subString[subStringIndex % subStringSize] != s[i]) {
					++divisor;
					while (s.size() % divisor != 0 && divisor < s.size() / 2)
						++divisor;

					subStringSize = s.size() / divisor;
					subStringIndex = 0;
					subString.clear();
					break;
				}
				++subStringIndex;
			}
			
		}

		return false;
	
	}
};

class Solution3 {
public:
	bool repeatedSubstringPattern(string s) {
	
		for (int subStringLength = 1; subStringLength <= s.size() / 2; ++subStringLength) {
			if (s.size() % subStringLength == 0) {
				for (int j = subStringLength; j <= s.size(); j += subStringLength) {
					if (j == s.size())
						return true;

					if (s.substr(0, subStringLength) != s.substr(j, subStringLength))
						break;
				}
				
			}
		}
	
		return false;
	
	}
};

int main(int argc, const char* argv[]) {
	Solution3 solution;

	string s1 = "abab";
	cout << solution.repeatedSubstringPattern(s1) << endl;

	string s2 = "aba";
	cout << solution.repeatedSubstringPattern(s2) << endl;

	string s3 = "abcabcabc";
	cout << solution.repeatedSubstringPattern(s3) << endl;

	string s4 = "abcabcdabcabcd";
	cout << solution.repeatedSubstringPattern(s4) << endl;

	string s5 = "aaa";
	cout << solution.repeatedSubstringPattern(s5) << endl;

	string s6 = "abcabcdabcabce";
	cout << solution.repeatedSubstringPattern(s6) << endl;

	string s7 = "abaababaab";
	cout << solution.repeatedSubstringPattern(s7) << endl;

	string s8 = "abacababacab";
	cout << solution.repeatedSubstringPattern(s8) << endl;

	string s9 = "bb";
	cout << solution.repeatedSubstringPattern(s9) << endl;

	string s10 = "ababba";
	cout << solution.repeatedSubstringPattern(s10) << endl;

	string s11 = "zzz";
	cout << solution.repeatedSubstringPattern(s11) << endl;

	cin.get();

	return 0;
}