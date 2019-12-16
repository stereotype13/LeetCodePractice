/*
Given an array of size n, find the majority element. The majority element is the element that appears more than n/2 times.

You may assume that the array is non-empty and the majority element always exist in the array.

Example 1:

Input: [3,2,3]
Output: 3
Example 2:

Input: [2,2,1,1,1,2,2]
Output: 2
*/
#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
	unordered_map<int, int> numberOfAppearances;
public:
	int majorityElement(vector<int>& nums) {
		numberOfAppearances.clear();
		unsigned int size = nums.size();

		for (const auto& i : nums) {
			if (numberOfAppearances[i] + 1 > size / 2)
				return i;

			numberOfAppearances[i]++;
		}

		return -1;
	}
};

int main(int argc, char* argv[]) {
	Solution solution;

	vector<int> vec1{ 3, 2, 3 };
	cout << solution.majorityElement(vec1) << endl;

	vector<int> vec2{ 2,2,1,1,1,2,2 };
	cout << solution.majorityElement(vec2) << endl;

	cin.get();
	return 0;
}