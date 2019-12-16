/*
There are two sorted arrays nums1 and nums2 of size m and n respectively.

Find the median of the two sorted arrays. The overall run time complexity should be O(log (m+n)).

You may assume nums1 and nums2 cannot be both empty.

Example 1:

nums1 = [1, 3]
nums2 = [2]

The median is 2.0
Example 2:

nums1 = [1, 2]
nums2 = [3, 4]

The median is (2 + 3)/2 = 2.5

*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
		vector<int> combinedArray;

		unsigned int nums1Count = 0, nums2Count = 0;
		while (nums1Count < nums1.size() || nums2Count < nums2.size()) {
			
			if (nums1Count < nums1.size() && nums2Count < nums2.size()) {
				if (nums1[nums1Count] < nums2[nums2Count]) {
					combinedArray.push_back(nums1[nums1Count]);
					++nums1Count;
				}
				else {
					combinedArray.push_back(nums2[nums2Count]);
					++nums2Count;
				}
			}

			if (nums1Count == nums1.size()) {
				while (nums2Count < nums2.size()) {
					combinedArray.push_back(nums2[nums2Count]);
					++nums2Count;
				}
			}

			if (nums2Count == nums2.size()) {
				while (nums1Count < nums1.size()) {
					combinedArray.push_back(nums1[nums1Count]);
					++nums1Count;
				}
			}
			
		}

		if ((int)combinedArray.size() % 2) {
			//It's odd
			return (double)combinedArray[(int)combinedArray.size() / 2];
		}

		return (combinedArray[(int)combinedArray.size() / 2] + combinedArray[(int)combinedArray.size() / 2 - 1]) / 2.0;


	}
};

class Solution2 {
	void findMedian(vector<int> &nums1, vector<int> &nums2, int imin, int imax, double & median)
	{
		int i = (imin + imax) / 2;
		int m = nums1.size();
		int n = nums2.size();
		int j = (m + n + 1) / 2 - i;
		if ((i == 0 || j == n || (nums1[i - 1] <= nums2[j])) && (j == 0 || i == m || (nums2[j - 1] <= nums1[i])))
		{
			int max_left = 0;
			if (i == 0)
			{
				max_left = nums2[j - 1];
			}
			else if (j == 0)
			{
				max_left = nums1[i - 1];
			}
			else
			{
				max_left = max(nums1[i - 1], nums2[j - 1]);
			}
			if ((m + n) % 2 == 1)
			{

				median = max_left;
			}
			else
			{
				int min_right;
				if (i == m)
				{
					min_right = nums2[j];
				}
				else if (j == n)
				{
					min_right = nums1[i];
				}
				else
				{
					min_right = min(nums2[j], nums1[i]);
				}
				median = (min_right + max_left + 0.0) / 2;
			}
			return;
		}
		else if ((i > imin) && (nums1[i - 1] > nums2[j]))
		{
			findMedian(nums1, nums2, imin, i - 1, median);
		}
		else if ((i < imax) && (nums2[j - 1] > nums1[i]))
		{
			findMedian(nums1, nums2, i + 1, imax, median);
		}
		return;
	}
public:
	double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2)
	{

		int m = nums1.size();
		int n = nums2.size();
		//n >= m 
		if (n < m)
		{
			vector<int> temp = nums1;
			nums1 = nums2;
			nums2 = temp;
			int temp2 = n;
			n = m;
			m = temp2;
		}
		double median = 0;
		findMedian(nums1, nums2, 0, m, median);
		return median;
	}
};

int main(int argc, char* argv[]) {
	
	vector<int> nums11{ 1, 2 };
	vector<int> nums12{ 3, 4 };

	Solution2 solution;
	cout << "The median is " << solution.findMedianSortedArrays(nums11, nums12) << endl;

	vector<int> nums21{ 1, 3 };
	vector<int> nums22{ 2 };

	cout << "The median is " << solution.findMedianSortedArrays(nums21, nums22) << endl;

	cin.get();
	return 0;
}