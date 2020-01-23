/*
In a string S of lowercase letters, these letters form consecutive groups of the same character.

For example, a string like S = "abbxxxxzyy" has the groups "a", "bb", "xxxx", "z" and "yy".

Call a group large if it has 3 or more characters.  We would like the starting and ending positions of every large group.

The final answer should be in lexicographic order.



Example 1:

Input: "abbxxxxzzy"
Output: [[3,6]]
Explanation: "xxxx" is the single large group with starting  3 and ending positions 6.
Example 2:

Input: "abc"
Output: []
Explanation: We have "a","b" and "c" but no large group.
Example 3:

Input: "abcdddeeeeaabbbcd"
Output: [[3,5],[6,9],[12,14]]


Note:  1 <= S.length <= 1000
*/
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
	vector<vector<int>> largeGroupPositions(string S) {
		if (S.empty())
			return {};

		vector<vector<int>> result;

		int start = 0;
		int characterCount = 1;
		for (int i = 1; i < (int)S.size(); ++i) {
			if (S[i] != S[i - 1]) {
				if (characterCount > 2) {
					result.push_back({start, i - 1});
				}
				characterCount = 0;
				start = i;
			}
			++characterCount;
		}
		if (characterCount > 2)
			result.push_back({start, (int)S.size() - 1});

		return result;
	}
};

int main(int argc, const char* argv[]) {
	Solution solution;

	string S1 = "abbxxxxzzy";
	auto result1 = solution.largeGroupPositions(S1);

	string S2 = "abc";
	auto result2 = solution.largeGroupPositions(S2);

	string S3 = "abcdddeeeeaabbbcd";
	auto result3 = solution.largeGroupPositions(S3);

	string S4 = "aaa";
	auto result4 = solution.largeGroupPositions(S4);

	cin.get();
	return 0;
}