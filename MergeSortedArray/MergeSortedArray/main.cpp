/*
Given two sorted integer arrays nums1 and nums2, merge nums2 into nums1 as one sorted array.

Note:

The number of elements initialized in nums1 and nums2 are m and n respectively.
You may assume that nums1 has enough space (size that is greater or equal to m + n) to hold additional elements from nums2.
Example:

Input:
nums1 = [1,2,3,0,0,0], m = 3
nums2 = [2,5,6],       n = 3

Output: [1,2,2,3,5,6]
*/
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
		if (nums1.empty()) {
			nums1 = nums2;
			return;
		}

		int mIndex = 0, nIndex = 0;
		vector<int> result;
		while (mIndex < m  || nIndex < n) {
			if (mIndex >= m) {
				result.push_back(nums2[nIndex]);
				++nIndex;
				continue;
			}

			if (nIndex >= n) {
				result.push_back(nums1[mIndex]);
				++mIndex;
				continue;
			}

			if (nums1[mIndex] < nums2[nIndex]) {
				result.push_back(nums1[mIndex]);
				++mIndex;
				continue;
			}

			result.push_back(nums2[nIndex]);
			++nIndex;
				
		}

		memcpy(&nums1[0], &result[0], sizeof(int) * (m + n));

	}
};

void print(const vector<int>& vec) {
	for (const auto& i : vec) {
		cout << i << '\t';
	}
	cout << endl;
}

int main(int argc, char* argv[]) {
	Solution solution;

	vector<int> a1{ 1,2,3,0,0,0 };
	vector<int> a2{ 2,5,6 };
	solution.merge(a1, 3, a2, 3);
	print(a1);

	cin.get();
	return 0;
}