/*
In a given integer array nums, there is always exactly one largest element.

Find whether the largest element in the array is at least twice as much as every other number in the array.

If it is, return the index of the largest element, otherwise return -1.

Example 1:

Input: nums = [3, 6, 1, 0]
Output: 1
Explanation: 6 is the largest integer, and for every other number in the array x,
6 is more than twice as big as x.  The index of value 6 is 1, so we return 1.


Example 2:

Input: nums = [1, 2, 3, 4]
Output: -1
Explanation: 4 isn't at least as big as twice the value of 3, so we return -1.


Note:

nums will have a length in the range [1, 50].
Every nums[i] will be an integer in the range [0, 99].
*/
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	int dominantIndex(vector<int>& nums) {
		if (nums.empty())
			return -1;

		int largestValue = INT_MIN;
		int secondLargest = INT_MIN;
		int largestValueIndex = 0;

		for (int i = 0; i < (int)nums.size(); ++i) {
			int num = nums[i];
			if (num > largestValue) {
				secondLargest = largestValue;
				largestValue = num;
				largestValueIndex = i;
			}

			
		}
		
		if (secondLargest * 2 <= largestValue)
			return largestValueIndex;

		return -1;
	}
};

int main(int argc, const char* argv[]) {
	Solution solution;

	auto vec1 = vector<int>{ 3, 6, 1, 0 };
	cout << solution.dominantIndex(vec1) << endl;

	auto vec2 = vector<int>{ 1, 2, 3, 4 };
	cout << solution.dominantIndex(vec2) << endl;

	cin.get();
	return 0;
}