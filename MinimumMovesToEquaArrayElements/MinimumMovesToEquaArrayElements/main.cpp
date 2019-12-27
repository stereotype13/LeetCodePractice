/*
Given a non-empty integer array of size n, find the minimum number of moves required to make all array elements equal, where a move is incrementing n - 1 elements by 1.

Example:

Input:
[1,2,3]

Output:
3

Explanation:
Only three moves are needed (remember each move increments two elements):

[1,2,3]  =>  [2,3,3]  =>  [3,4,3]  =>  [4,4,4]
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	int minMoves(vector<int>& nums) {
		int maxNumber = *max_element(nums.begin(), nums.end());

		int moveCount = 0;
		vector<int> maxNumberIndices;
		while (adjacent_find(nums.begin(), nums.end(), not_equal_to<>()) != nums.end()) {
			
			for (int i = 0; i < nums.size(); ++i) {
				if (nums[i] < maxNumber)
					nums[i]++;
				else if (nums[i] == maxNumber) {
					maxNumberIndices.push_back(i);
				}
			}

			if (maxNumberIndices.size() > 1) {
				for (int i = 0; i < maxNumberIndices.size() - 1; ++i)
					nums[i]++;
			}
			
			maxNumberIndices.clear();
			maxNumber = *max_element(nums.begin(), nums.end());
			++moveCount;
		}

		return moveCount;
	}
};

int main(int argc, char* argv[]) {
	Solution solution;
	vector<int> nums1{ 1, 2, 3 };
	cout << solution.minMoves(nums1) << endl;

	cin.get();

	return 0;
}