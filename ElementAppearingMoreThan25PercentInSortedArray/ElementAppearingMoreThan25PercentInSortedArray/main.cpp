/*
Given an integer array sorted in non-decreasing order, there is exactly one integer in the array that occurs more than 25% of the time.

Return that integer.



Example 1:

Input: arr = [1,2,2,6,6,6,6,7,10]
Output: 6



Constraints:

	1 <= arr.length <= 10^4
	0 <= arr[i] <= 10^5

*/
#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
	int findSpecialInteger(vector<int>& arr) {
		unordered_map<int, int> frequencies;

		for (const auto& i : arr)
			frequencies[i]++;

		auto& p = *max_element(frequencies.begin(), frequencies.end(), [](const auto& p1, const auto& p2) {
			return p1.second < p2.second;
		});

		return p.first;
	}
};

int main() {
	Solution solution;

	vector<int> input1{ 1,2,2,6,6,6,6,7,10 };
	cout << solution.findSpecialInteger(input1) << endl;

	cin.get();
	return 0;
}