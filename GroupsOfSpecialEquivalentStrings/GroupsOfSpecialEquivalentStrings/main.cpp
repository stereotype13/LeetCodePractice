/*
You are given an array A of strings.

A move onto S consists of swapping any two even indexed characters of S, or any two odd indexed characters of S.

Two strings S and T are special-equivalent if after any number of moves onto S, S == T.

For example, S = "zzxy" and T = "xyzz" are special-equivalent because we may make the moves "zzxy" -> "xzzy" -> "xyzz" that swap S[0] and S[2], then S[1] and S[3].

Now, a group of special-equivalent strings from A is a non-empty subset of A such that:

Every pair of strings in the group are special equivalent, and;
The group is the largest size possible (ie., there isn't a string S not in the group such that S is special equivalent to every string in the group)
Return the number of groups of special-equivalent strings from A.


Example 1:

Input: ["abcd","cdab","cbad","xyzz","zzxy","zzyx"]
Output: 3
Explanation:
One group is ["abcd", "cdab", "cbad"], since they are all pairwise special equivalent, and none of the other strings are all pairwise special equivalent to these.

The other two groups are ["xyzz", "zzxy"] and ["zzyx"].  Note that in particular, "zzxy" is not special equivalent to "zzyx".
Example 2:

Input: ["abc","acb","bac","bca","cab","cba"] // [abc, cba], [acb, bca], [bac, cab]
Output: 3


Note:

1 <= A.length <= 1000
1 <= A[i].length <= 20
All A[i] have the same length.
All A[i] consist of only lowercase letters.
*/
#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
#include <algorithm>

using namespace std;

namespace std {
	template <>
	struct hash<std::vector<int>> {
		size_t operator()(const vector<int>& v) const {
			std::hash<int> hasher;
			size_t seed = 0;
			for (int i : v) {
				seed ^= hasher(i) + 0x9e3779b9 + (seed << 6) + (seed >> 2);
			}
			return seed;
		}
	};
}

class Solution {
	
public:
	int numSpecialEquivGroups(vector<string>& A) {

		unordered_set<vector<int>> hashSet;
		for (const auto& a : A) {
			vector<int> vec(52, 0);

			for (int i = 0; i < (int)a.size(); ++i) {
				if (i % 2 == 0)
					vec[a[i] - 'a']++;
				else
					vec[a[i] - 'a' + 26]++;
			}

			hashSet.emplace(vec);
		}

		return (int)hashSet.size();
	}
};

int main() {
	Solution solution;

	vector<string> A1{ "abcd", "cdab", "cbad", "xyzz", "zzxy", "zzyx" };
	cout << solution.numSpecialEquivGroups(A1) << endl;

	vector<string> A2{"abc", "acb", "bac", "bca", "cab", "cba"};
	cout << solution.numSpecialEquivGroups(A2) << endl;

	cin.get();
	return 0;
}