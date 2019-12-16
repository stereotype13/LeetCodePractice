/*
Given a sorted array and a target value, return the index if the target is found. If not, return the index where it would be if it were inserted in order.

You may assume no duplicates in the array.

Example 1:

Input: [1,3,5,6], 5
Output: 2
Example 2:

Input: [1,3,5,6], 2
Output: 1
Example 3:

Input: [1,3,5,6], 7
Output: 4
Example 4:

Input: [1,3,5,6], 0
Output: 0
*/

#include <vector>
#include <iostream>

using namespace std;

class Solution {
	int binarySearch(const vector<int>& nums, int target, int low, int high) {
		if (low > high)
			return low;

		int mid = (low + high) / 2;
		if (nums[mid] == target)
			return mid;

		if (target < nums[mid])
			return binarySearch(nums, target, low, mid - 1);

		return binarySearch(nums, target, mid + 1, high);
	}
public:
	

	int searchInsert(vector<int>& nums, int target) {
		if (nums.size() == 0)
			return 0;

		return binarySearch(nums, target, 0, nums.size() - 1);
	}
};

int main(int argc, char* argv[]) {
	Solution solution;

	vector<int> nums1{ 1,3,5,6 }; int target1 = 5;
	cout << solution.searchInsert(nums1, target1) << endl;

	vector<int> nums2{ 1,3,5,6 }; int target2 = 2;
	cout << solution.searchInsert(nums2, target2) << endl;

	vector<int> nums3{ 1,3,5,6 }; int target3 = 7;
	cout << solution.searchInsert(nums3, target3) << endl;

	vector<int> nums4{ 1,3,5,6 }; int target4 = 0;
	cout << solution.searchInsert(nums4, target4) << endl;

	cin.get();
	return 0;
}