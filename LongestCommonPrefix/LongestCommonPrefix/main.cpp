/*
Write a function to find the longest common prefix string amongst an array of strings.

If there is no common prefix, return an empty string "".

Example 1:

Input: ["flower","flow","flight"]
Output: "fl"
Example 2:

Input: ["dog","racecar","car"]
Output: ""
Explanation: There is no common prefix among the input strings.
Note:

All given inputs are in lowercase letters a-z.
*/

#include <string>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	string longestCommonPrefix(vector<string>& strs) {

		if (strs.size() == 0)
			return "";

		if (strs.size() == 1)
			return strs[0];

		string firstString = strs[0];
		string result = "";

		for (int i = 0; i < firstString.size(); ++i) {
			char c = firstString.at(i);
			for (int j = 1; j < strs.size(); ++j) {
				if (strs[j].size() == 0 || i >= strs[j].size() || strs[j].at(i) != c)
					return result;

			}
			result += c;
		}

		return result;
	}
};

class Solution2 {
public:
	string longestCommonPrefix(vector<string>& strs) {
		string result;
		if (strs.size() == 0) {
			return result;
		}
		string str = strs[0];

		for (int i = 0; i < str.size(); i++) {
			for (int j = 0; j < strs.size(); j++) {
				if (strs[j][i] != str[i]) {
					return result;
				}
			}
			result += str[i];
		}
		return result;
	}
};

int main() {
	Solution2 solution;
	vector<string> v1{ "flower","flow","flight" };
	vector<string> v2{ "dog","racecar","car" };

	vector<string> v3{ "aa", "a"};

	cout << solution.longestCommonPrefix(v1) << endl;
	cout << solution.longestCommonPrefix(v3) << endl;

	//test
	string s1 = "aa";

	for (int i = 0; i < 3; ++i) {
		cout << s1[i] << endl;
	}

	cin.get();
}