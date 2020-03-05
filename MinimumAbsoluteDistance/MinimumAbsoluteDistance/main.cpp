/*
Given an array of distinct integers arr, find all pairs of elements with the minimum absolute difference of any two elements.

Return a list of pairs in ascending order(with respect to pairs), each pair [a, b] follows

	a, b are from arr
	a < b
	b - a equals to the minimum absolute difference of any two elements in arr



Example 1:

Input: arr = [4,2,1,3]
Output: [[1,2],[2,3],[3,4]]
Explanation: The minimum absolute difference is 1. List all pairs with difference equal to 1 in ascending order.

Example 2:

Input: arr = [1,3,6,10,15]
Output: [[1,3]]

Example 3:

Input: arr = [3,8,-10,23,19,-4,-14,27]
Output: [[-14,-10],[19,23],[23,27]]



Constraints:

	2 <= arr.length <= 10^5
	-10^6 <= arr[i] <= 10^6


*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
		sort(arr.begin(), arr.end());

		vector<int> differences(arr.size() - 1, -1);
		for (int i = 1; i < (int)arr.size(); ++i) 
			differences[i - 1] = abs(arr[i] - arr[i - 1]);
		

		int smallestDistance = *min_element(differences.begin(), differences.end());

		vector<vector<int>> result;
		for (int i = 0; i < (int)differences.size(); ++i) {
			if (differences[i] == smallestDistance)
				result.push_back({arr[i], arr[i + 1]});
		}

		return result;
	}
};

int main() {
	Solution solution;

	vector<int> arr1{ 4, 2, 1, 3 };
	auto result1 = solution.minimumAbsDifference(arr1);

	vector<int> arr2{ 1,3,6,10,15 };
	auto result2 = solution.minimumAbsDifference(arr2);

	vector<int> arr3{ 3,8,-10,23,19,-4,-14,27 };
	auto result3 = solution.minimumAbsDifference(arr3);

	cin.get();
	return 0;
}