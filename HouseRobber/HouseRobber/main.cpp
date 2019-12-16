/*
You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed, 
the only constraint stopping you from robbing each of them is that adjacent houses have security system connected and it
will automatically contact the police if two adjacent houses were broken into on the same night.

Given a list of non-negative integers representing the amount of money of each house, determine the maximum amount of 
money you can rob tonight without alerting the police.

Example 1:

Input: [1,2,3,1]
Output: 4
Explanation: Rob house 1 (money = 1) and then rob house 3 (money = 3).
			 Total amount you can rob = 1 + 3 = 4.
Example 2:

Input: [2,7,9,3,1]
Output: 12
Explanation: Rob house 1 (money = 2), rob house 3 (money = 9) and rob house 5 (money = 1).
			 Total amount you can rob = 2 + 9 + 1 = 12.
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
	vector<int> maxProfit;

	int helper(vector<int>& nums, int index) {
		if (index >= nums.size())
			return 0;

		if (maxProfit[index] > -1)
			return maxProfit[index];

		int profit = nums[index] + max(helper(nums, index + 2), helper(nums, index + 3));
		maxProfit[index] = profit;
		return profit;
	}

public:
	int rob(vector<int>& nums) {
		if (nums.size() == 0)
			return 0;

		if (nums.size() == 1)
			return nums[0];

		maxProfit = vector<int>(nums.size(), -1);

		return max(helper(nums, 0), helper(nums, 1));
	}
};

int main(int argc, char* argv[]) {
	Solution solution;

	vector<int> vec1{ 1,2,3,1 };
	cout << solution.rob(vec1) << endl;

	vector<int> vec2{ 2,7,9,3,1 };
	cout << solution.rob(vec2) << endl;

	cin.get();

	return 0;
}