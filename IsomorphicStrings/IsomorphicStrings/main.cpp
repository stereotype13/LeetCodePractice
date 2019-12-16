/*
Given two strings s and t, determine if they are isomorphic.

Two strings are isomorphic if the characters in s can be replaced to get t.

All occurrences of a character must be replaced with another character while preserving the order of characters. No two characters may map to the same character but a character may map to itself.

Example 1:

Input: s = "egg", t = "add"
Output: true
Example 2:

Input: s = "foo", t = "bar"
Output: false
Example 3:

Input: s = "paper", t = "title"
Output: true
Note:
You may assume both s and t have the same length.
*/
#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
	bool isIsomorphic(string s, string t) {
		if (s.size() != t.size())
			return false;

		unordered_map<char, char> charMap;
		for (int i = 0; i < s.size(); ++i) {
			if (charMap.find(s[i]) == charMap.end()) {
				charMap[s[i]] = t[i];
				continue;
			}

			if (charMap[s[i]] != t[i])
				return false;
		}

		return true;
	}
};

int main(int argc, char* argv[]) {
	Solution solution;
	cout << solution.isIsomorphic("egg", "add") << endl;
	cout << solution.isIsomorphic("foo", "bar") << endl;

	cin.get();
	return 0;
}