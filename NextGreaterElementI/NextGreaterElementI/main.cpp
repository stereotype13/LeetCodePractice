/*
You are given two arrays (without duplicates) nums1 and nums2 where nums1’s elements are subset of nums2. 
Find all the next greater numbers for nums1's elements in the corresponding places of nums2.

The Next Greater Number of a number x in nums1 is the first greater number to its right in nums2. If it does not exist, output -1 for this number.

Example 1:
Input: nums1 = [4,1,2], nums2 = [1,3,4,2].
Output: [-1,3,-1]
Explanation:
	For number 4 in the first array, you cannot find the next greater number for it in the second array, so output -1.
	For number 1 in the first array, the next greater number for it in the second array is 3.
	For number 2 in the first array, there is no next greater number for it in the second array, so output -1.
Example 2:
Input: nums1 = [2,4], nums2 = [1,2,3,4].
Output: [3,-1]
Explanation:
	For number 2 in the first array, the next greater number for it in the second array is 3.
	For number 4 in the first array, there is no next greater number for it in the second array, so output -1.
Note:
All elements in nums1 and nums2 are unique.
The length of both nums1 and nums2 would not exceed 1000.
*/
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
		if (nums1.empty() || nums2.empty())
			return {};

		vector<int> result(nums1.size(), -1);

		for (int i = 0; i < nums1.size(); ++i) {
			int temp = nums1[i];
			for (int j = 0; j < nums2.size(); ++j) {
				if (temp == nums2[j]) {

					for (int k = j + 1; k < nums2.size(); ++k) {
						if (temp < nums2[k]) {
							result[i] = nums2[k];
							break;
						}
					}
					//
					break;
				}
				//
				
			}
		}

		return result;
	}
};

void print(const vector<int>& vec) {
	cout << "[";
	for (const auto& i : vec) {
		cout << i << " ";
	}
	cout << "]" << endl;
}

int main(int argc, const char* argv[]) {
	Solution solution;
	vector<int> vec1a{ 4,1,2 }, vec1b{ 1,3,4,2 };
	print(solution.nextGreaterElement(vec1a, vec1b));

	vector<int> vec2a{ 2,4 }, vec2b{ 1,2,3,4 };
	print(solution.nextGreaterElement(vec2a, vec2b));

	cin.get();
	return 0;
}