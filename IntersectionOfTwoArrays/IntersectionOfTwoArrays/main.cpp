/*
Given two arrays, write a function to compute their intersection.

Example 1:

Input: nums1 = [1,2,2,1], nums2 = [2,2]
Output: [2]
Example 2:

Input: nums1 = [4,9,5], nums2 = [9,4,9,8,4]
Output: [9,4]
Note:

Each element in the result must be unique.
The result can be in any order.
*/

#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
	vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
		unordered_set<int> first;
		unordered_set<int> result;
		vector<int> resultVec;

		for (const auto& i : nums1) {
			first.emplace(i);
		}

		for (const auto& i : nums2) {
			if (first.find(i) != first.end())
				result.emplace(i);
		}

		for (const auto& i : result) {
			resultVec.push_back(i);
		}

		return resultVec;
	}
};

int main() {}