/*
Given an integer array nums, find the contiguous subarray (containing at least one number) which has the largest sum and return its sum.

Example:

Input: [-2,1,-3,4,-1,2,1,-5,4],
Output: 6
Explanation: [4,-1,2,1] has the largest sum = 6.
Follow up:

If you have figured out the O(n) solution, try coding another solution using the divide and conquer approach, which is more subtle.
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	int maxSubArray(vector<int>& nums) {
		if (nums.empty())
			return 0;

		if (nums.size() == 1)
			return nums[0];

		int maxSubArrayTotal = nums[0];
		int subArrayTotal = 0;
		for (int i = 0; i < nums.size(); ++i) {
			if (nums[i] + subArrayTotal < 0) {
				subArrayTotal = 0;
				maxSubArrayTotal = max(maxSubArrayTotal, nums[i]);
				continue;
			}
				
			maxSubArrayTotal = max(maxSubArrayTotal, subArrayTotal + nums[i]);
			subArrayTotal += nums[i];
		}

		return maxSubArrayTotal;
	}
};

int main(int argc, char* argv[]) {
	Solution solution;

	vector<int> nums1{ -2,1,-3,4,-1,2,1,-5,4 };
	cout << solution.maxSubArray(nums1) << endl;

	vector<int> nums2{ -2,-3, -5, -7 };
	cout << solution.maxSubArray(nums2) << endl;

	vector<int> nums3{ 1, 2, -100, 3, 4 };
	cout << solution.maxSubArray(nums3) << endl;

	vector<int> nums4{ -2, 1 };
	cout << solution.maxSubArray(nums4) << endl;

	vector<int> nums5{ -2, -1 };
	cout << solution.maxSubArray(nums5) << endl;

	cin.get();

	return 0;
}