/*
Given a non-empty array of integers, every element appears twice except for one. Find that single one.

Note:

Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?

Example 1:

Input: [2,2,1]
Output: 1
Example 2:

Input: [4,1,2,1,2]
Output: 4
*/
#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
	unordered_set<int> seenNumbers;
public:
	int singleNumber(vector<int>& nums) {
		seenNumbers.clear();

		for (const auto& num : nums) {
			if (seenNumbers.find(num) != seenNumbers.end()) {
				seenNumbers.erase(num);
				continue;
			}

			seenNumbers.emplace(num);
		}

		return *seenNumbers.begin();
	}
};

int main(int argc, char* argv[]) {
	Solution solution;
	vector<int> array1{ 2,2,1 };
	cout << solution.singleNumber(array1) << endl;

	vector<int> array2{ 4,1,2,1,2 };
	cout << solution.singleNumber(array2) << endl;

	cin.get();
	return 0;
}