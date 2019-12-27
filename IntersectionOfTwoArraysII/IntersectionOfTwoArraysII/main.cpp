/*
Given two arrays, write a function to compute their intersection.

Example 1:

Input: nums1 = [1,2,2,1], nums2 = [2,2]
Output: [2,2]
Example 2:

Input: nums1 = [4,9,5], nums2 = [9,4,9,8,4]
Output: [4,9]
Note:

Each element in the result should appear as many times as it shows in both arrays.
The result can be in any order.
Follow up:

What if the given array is already sorted? How would you optimize your algorithm?
What if nums1's size is small compared to nums2's size? Which algorithm is better?
What if elements of nums2 are stored on disk, and the memory is limited such that you cannot load all elements into the memory at once?
*/
#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
	vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
		if (nums1.empty() || nums2.empty())
			return {};

		if (nums1.size() > nums2.size())
			swap(nums1, nums2);

		unordered_map<int, int> nums1Map;
		unordered_map<int, int> outputMap;
		vector<int> result;

		for (const auto& i : nums1)
			nums1Map[i]++;

		for (const auto& i : nums2) {
			if (nums1Map[i] > 0 && outputMap[i] < nums1Map[i]) {
				result.push_back(i);
				outputMap[i]++;
			}
		}

		return result;
	}
};

int main(int argc, char* argv[]) {
	Solution solution;

	vector<int> vec1a{ 1, 2, 2, 1 };
	vector<int> vec2a{ 2, 2 };

	auto resultA = solution.intersect(vec1a, vec2a);

	vector<int> vec1b{ 4, 9, 5 };
	vector<int> vec2b{ 9, 4, 9, 8, 4 };

	auto resultB = solution.intersect(vec1b, vec2b);

	cin.get();
	return 0;
}