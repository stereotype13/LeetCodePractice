/*
Given an array of integers, find if the array contains any duplicates.

Your function should return true if any value appears at least twice in the array, and it should return false if every element is distinct.

Example 1:

Input: [1,2,3,1]
Output: true
Example 2:

Input: [1,2,3,4]
Output: false
Example 3:

Input: [1,1,1,3,3,4,3,2,4,2]
Output: true
*/
#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
	bool containsDuplicate(vector<int>& nums) {
		unordered_set<int> seenNumbers;

		for (const auto& i : nums) {
			if (seenNumbers.find(i) != seenNumbers.end())
				return true;

			seenNumbers.emplace(i);
		}

		return false;
	}
};

int main(int argc, char* argv[]) { 
	Solution solution;

	vector<int> vec1{ 1,2,3,1 };
	cout << solution.containsDuplicate(vec1) << endl;

	vector<int> vec2{ 1,2,3,4 };
	cout << solution.containsDuplicate(vec2) << endl;

	cin.get();
	return 0;
}