/*
Given an array containing n distinct numbers taken from 0, 1, 2, ..., n, find the one that is missing from the array.

Example 1:

Input: [3,0,1]
Output: 2
Example 2:

Input: [9,6,4,2,3,5,7,0,1]
Output: 8
Note:
Your algorithm should run in linear runtime complexity. Could you implement it using only constant extra space complexity?
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	int missingNumber(vector<int>& nums) {
		if (nums.empty())
			return 0;

		if (nums.size() == 1 && nums[0] == 0)
			return 1;

		int sum = 0;
		int maxFound = INT_MIN;

		bool zeroFound = false;
		for (const auto& i : nums) {
			if (i == 0)
				zeroFound = true;

			sum += i;
			maxFound = max(maxFound, i);
		}

		if (!zeroFound)
			return 0;

		int result = maxFound * (maxFound + 1) / 2 - sum;
		if (result == 0)
			return nums.size();

		return result;
	}
};

int main(int argc, char* argv[]) {
	Solution solution;
	vector<int> vec1{3, 0, 1};
	cout << solution.missingNumber(vec1) << endl;

	vector<int> vec2{ 9,6,4,2,3,5,7,0,1 };
	cout << solution.missingNumber(vec2) << endl;

	cin.get();
	return 0;
}