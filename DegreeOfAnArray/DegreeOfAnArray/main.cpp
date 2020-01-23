/*
Given a non-empty array of non-negative integers nums, the degree of this array is defined as the maximum frequency of any one of its elements.

Your task is to find the smallest possible length of a (contiguous) subarray of nums, that has the same degree as nums.

Example 1:
Input: [1, 2, 2, 3, 1]
Output: 2
Explanation:
The input array has a degree of 2 because both elements 1 and 2 appear twice.
Of the subarrays that have the same degree:
[1, 2, 2, 3, 1], [1, 2, 2, 3], [2, 2, 3, 1], [1, 2, 2], [2, 2, 3], [2, 2]
The shortest length is 2. So return 2.
Example 2:
Input: [1,2,2,3,1,4,2]
Output: 6
Note:

nums.length will be between 1 and 50,000.
nums[i] will be an integer between 0 and 49,999.
*/
#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
	int findShortestSubArray(vector<int>& nums) {
		unordered_map<int, int> numIndexMap;
		unordered_map<int, int> numFrequencyMap;

		int length = nums.size();
		int maxFrequency = 1;
		for (int i = 0; i < (int)nums.size(); ++i) {
			if (numIndexMap.find(nums[i]) != numIndexMap.end()) {
				numFrequencyMap[nums[i]]++;

				if (numFrequencyMap[nums[i]] > maxFrequency) {
					++maxFrequency;
					length = i - numIndexMap[nums[i]] + 1;
				}
				else if(numFrequencyMap[nums[i]] == maxFrequency) {
					length = min(length, i - numIndexMap[nums[i]] + 1);
				}
				
				continue;
			}
			numIndexMap[nums[i]] = i;
			numFrequencyMap[nums[i]] = 1;
		}

		if (maxFrequency == 1)
			return 1;

		return length;
	}
};

int main(int argc, const char* argv[]) {
	Solution solution;
	auto vec1 = vector<int>{ 1, 2, 2, 3, 1 };
	cout << solution.findShortestSubArray(vec1) << endl;

	auto vec2 = vector<int>{ 1,2,2,3,1,4,2 };
	cout << solution.findShortestSubArray(vec2) << endl;

	auto vec3 = vector<int>{ 1,2,2,3,1,4,2,4,5,9,9,9,10,10 };
	cout << solution.findShortestSubArray(vec3) << endl;

	auto vec4 = vector<int>{ 1, 1, 2, 2, 2, 1 };
	cout << solution.findShortestSubArray(vec4) << endl;

	auto vec5 = vector<int>{ 1, 2, 2, 3, 1 };
	cout << solution.findShortestSubArray(vec5) << endl;

	cin.get();
	return 0;
}