/*
Given a list of dominoes, dominoes[i] = [a, b] is equivalent to dominoes[j] = [c, d] if and only 
if either (a==c and b==d), or (a==d and b==c) - that is, one domino can be rotated to be equal to another domino.

Return the number of pairs (i, j) for which 0 <= i < j < dominoes.length, and dominoes[i] is equivalent to dominoes[j].



Example 1:

Input: dominoes = [[1,2],[2,1],[3,4],[5,6]]
Output: 1



Constraints:

	1 <= dominoes.length <= 40000
	1 <= dominoes[i][j] <= 9

*/
#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

namespace std {
	template <> struct hash<std::pair<int, int>> {
		inline size_t operator()(const std::pair<int, int> &v) const {
			std::hash<int> int_hasher;
			return int_hasher(v.first) ^ int_hasher(v.second);
		}
	};

}

class Solution {
public:
	int numEquivDominoPairs(vector<vector<int>>& dominoes) {
		unordered_map<pair<int, int>, int> need;

		int count = 0;
		for (auto& p : dominoes) {

			if (p[0] > p[1])
				swap(p[0], p[1]);

			need[pair<int, int>{p[0], p[1]}]++;
			
		}

		for (const auto& p : need) {
			if (p.second == 1)
				continue;

			int clusterCount = 0;
			for (int i = 1; i < p.second; ++i) {
				clusterCount += i;
			}
			count += clusterCount;
		}

		return count;
	}
};

int main() {
	Solution solution;

	vector<vector<int>> dominoes1{{1, 2}, {2, 1}, {3, 4}, {5, 6}};
	cout << solution.numEquivDominoPairs(dominoes1) << endl;

	//[[1,2],[1,2],[1,1],[1,2],[2,2]] should be 3. got 2
	vector<vector<int>> dominoes2{{1, 2}, {1, 2}, {1, 1}, {1, 2}, {2, 2}};
	cout << solution.numEquivDominoPairs(dominoes2) << endl;
	cin.get();
	return 0;
}