/*
Given an array, rotate the array to the right by k steps, where k is non-negative.

Example 1:

Input: [1,2,3,4,5,6,7] and k = 3
Output: [5,6,7,1,2,3,4]
Explanation:
rotate 1 steps to the right: [7,1,2,3,4,5,6]
rotate 2 steps to the right: [6,7,1,2,3,4,5]
rotate 3 steps to the right: [5,6,7,1,2,3,4]
Example 2:

Input: [-1,-100,3,99] and k = 2
Output: [3,99,-1,-100]
Explanation:
rotate 1 steps to the right: [99,-1,-100,3]
rotate 2 steps to the right: [3,99,-1,-100]
Note:

Try to come up as many solutions as you can, there are at least 3 different ways to solve this problem.
Could you do it in-place with O(1) extra space?
*/
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	void rotate(vector<int>& nums, int k) {
		if (k % nums.size() == 0)
			return;
		
		for (int i = 0; i < nums.size() - k % nums.size(); ++i) {
			nums.push_back(nums[0]);
			nums.assign(nums.begin() + 1, nums.end());
		}
		
	}
};

class Solution2 {
public:
	void rotate(vector<int>& nums, int k) {
		if (k % nums.size() == 0)
			return;

		reverse(nums.begin(), nums.end());
		reverse(nums.begin(), nums.begin() + k);
		reverse(nums.begin() + k, nums.end());

	}
};

int main(int argc, char* argv[]) {
	
	Solution2 solution;
	vector<int> vec1{ 1,2,3,4,5,6,7 };
	solution.rotate(vec1, 3);

	return 0;
}