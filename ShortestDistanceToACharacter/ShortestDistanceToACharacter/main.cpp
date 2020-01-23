/*
Given a string S and a character C, return an array of integers representing the shortest distance from the character C in the string.

Example 1:

Input: S = "loveleetcode", C = 'e'
Output: [3, 2, 1, 0, 1, 0, 0, 1, 2, 2, 1, 0]


Note:

S string length is in [1, 10000].
C is a single character, and guaranteed to be in string S.
All letters in S and C are lowercase.
*/
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
	vector<int> shortestToChar(string S, char C) {
		vector<int> indicesC;

		for (int i = 0; i < (int)S.size(); ++i) {
			char c = S[i];
			if (c == C)
				indicesC.push_back(i);
		}

		vector<int> result;
		for (int i = 0; i < (int)S.size(); ++i) {
			
			int d = INT_MAX;
			for (const auto& c : indicesC) {
				d = min(d, abs(c - i));
			}
			result.push_back(d);
		}

		return result;
	}
};

int main() {
	Solution solution;
	
	string S1 = "loveleetcode";
	char C1 = 'e';

	auto result1 = solution.shortestToChar(S1, C1);

	cin.get();
	return 0;
}