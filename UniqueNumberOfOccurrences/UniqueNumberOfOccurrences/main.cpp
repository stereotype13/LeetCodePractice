/*
Given an array of integers arr, write a function that returns true if and only if the number of occurrences of each value in the array is unique.



Example 1:

Input: arr = [1,2,2,1,1,3]
Output: true
Explanation: The value 1 has 3 occurrences, 2 has 2 and 3 has 1. No two values have the same number of occurrences.

Example 2:

Input: arr = [1,2]
Output: false

Example 3:

Input: arr = [-3,0,1,-3,1,1,1,-3,10,0]
Output: true



Constraints:

	1 <= arr.length <= 1000
	-1000 <= arr[i] <= 1000


*/
#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class Solution {
public:
	bool uniqueOccurrences(vector<int>& arr) {
		unordered_map<int, int> frequencies;
		unordered_set<int> frequencyOfFrequencies;

		for (const auto& i : arr)
			frequencies[i]++;

		for (const auto& p : frequencies)
			if (frequencyOfFrequencies.find(p.second) != frequencyOfFrequencies.end())
				return false;
			else
				frequencyOfFrequencies.emplace(p.second);

		return true;

	}
};

int main() {
	Solution solution;

	vector<int> arr1{ 1,2,2,1,1,3 };
	cout << boolalpha << solution.uniqueOccurrences(arr1) << endl;

	vector<int> arr2{ 1,2 };
	cout << boolalpha << solution.uniqueOccurrences(arr2) << endl;

	vector<int> arr3{ -3,0,1,-3,1,1,1,-3,10,0 };
	cout << boolalpha << solution.uniqueOccurrences(arr3) << endl;

	cin.get();
	return 0;
}