/*
Given a string, find the first non-repeating character in it and return it's index. If it doesn't exist, return -1.

Examples:

s = "leetcode"
return 0.

s = "loveleetcode",
return 2.
Note: You may assume the string contain only lowercase letters.
*/
#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>

using namespace std;

class Solution {
public:
	int firstUniqChar(string s) {
		unordered_map<char, int> charPositionMap;
		unordered_set<char> seenLetters;

		for (int i = 0; i < s.size(); ++i) {
			auto c = s[i];
			if (seenLetters.find(c) != seenLetters.end()) {
				charPositionMap.erase(c);
				continue;
			}
			seenLetters.emplace(c);
			charPositionMap[c] = i;
		}

		if (charPositionMap.empty())
			return -1;

		int firstPosition = INT_MAX;
		for (const auto& p : charPositionMap) {
			firstPosition = min(firstPosition, p.second);
		}
		return firstPosition;
	}
};

int main(int argc, char* argv[]) {
	Solution solution;
	cout << solution.firstUniqChar("leetcode") << endl;
	cout << solution.firstUniqChar("loveleetcode") << endl;
	cout << solution.firstUniqChar("aaaaa") << endl;

	cin.get();
	return 0;
}