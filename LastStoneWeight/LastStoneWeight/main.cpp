/*
We have a collection of rocks, each rock has a positive integer weight.

Each turn, we choose the two heaviest rocks and smash them together.  Suppose the stones have weights x and y with x <= y.  The result of this smash is:

	If x == y, both stones are totally destroyed;
	If x != y, the stone of weight x is totally destroyed, and the stone of weight y has new weight y-x.

At the end, there is at most 1 stone left.  Return the weight of this stone (or 0 if there are no stones left.)



Example 1:

Input: [2,7,4,1,8,1]
Output: 1
Explanation:
We combine 7 and 8 to get 1 so the array converts to [2,4,1,1,1] then,
we combine 2 and 4 to get 2 so the array converts to [2,1,1,1] then,
we combine 2 and 1 to get 1 so the array converts to [1,1,1] then,
we combine 1 and 1 to get 0 so the array converts to [1] then that's the value of last stone.



Note:

	1 <= stones.length <= 30
	1 <= stones[i] <= 1000

*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	int lastStoneWeight(vector<int>& stones) {
		

		while (stones.size() > 1) {
			sort(stones.begin(), stones.end());
			int y = stones.back();
			stones.pop_back();

			int x = stones.back();
			stones.pop_back();

			if (x == y)
				continue;

			stones.push_back(y - x);
		}

		if (stones.empty())
			return 0;

		return stones[0];
	}
};



int main() {
	Solution solution;

	vector<int> input1{ 2,7,4,1,8,1 };
	cout << solution.lastStoneWeight(input1) << endl;

	vector<int> input2{ 1, 1 };
	cout << solution.lastStoneWeight(input2) << endl;

	vector<int> input3{ 7 };
	cout << solution.lastStoneWeight(input3) << endl;

	cin.get();
	return 0;
}