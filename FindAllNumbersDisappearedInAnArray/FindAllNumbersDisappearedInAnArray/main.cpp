/*
Given an array of integers where 1 ≤ a[i] ≤ n (n = size of array), some elements appear twice and others appear once.

Find all the elements of [1, n] inclusive that do not appear in this array.

Could you do it without extra space and in O(n) runtime? You may assume the returned list does not count as extra space.

Example:

Input:
[4,3,2,7,8,2,3,1]

Output:
[5,6]
*/
#include <iostream>
#include <unordered_set>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	vector<int> findDisappearedNumbers(vector<int>& nums) {
		vector<int> seen(nums.size(), 0);

		for (const auto& i : nums) {
			seen[i - 1] = i;
		}

		vector<int> result;
		for (int i = 0; i < seen.size(); ++i) {
			if (seen[i] == 0)
				result.push_back(i + 1);
		}
		return result;
	}
};

int main(int argc, char* argv[]) {
	Solution solution;

	vector<int> input1{ 4, 3, 2, 7, 8, 2, 3, 1 };
	//vector<int> input1{ 1, 1 };
	auto result1 = solution.findDisappearedNumbers(input1);

	cin.get();
	return 0;
}