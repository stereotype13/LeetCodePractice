/*
The set S originally contains numbers from 1 to n. But unfortunately, due to the data error, one of the numbers in the set got 
duplicated to another number in the set, which results in repetition of one number and loss of another number.

Given an array nums representing the data status of this set after the error. Your task is to firstly find the number occurs 
twice and then find the number that is missing. Return them in the form of an array.

Example 1:
Input: nums = [1,2,2,4]
Output: [2,3]
Note:
The given array size will in the range [2, 10000].
The given array's numbers won't have any order.
*/
#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
	vector<int> findErrorNums(vector<int>& nums) {
		unordered_set<int> seen;

		int repeatedNumber = 0;
		for (const auto& i : nums) {
			if (seen.find(i) != seen.end()) {
				repeatedNumber = i;
				continue;
			}
				

			seen.emplace(i);
		}

		for (int i = 1; i < nums.size() + 1; ++i) {
			if (seen.find(i) == seen.end())
				return { repeatedNumber, i };
		}

		return {};
	}
};

int main(int argc, const char* argv[]) {
	Solution solution;
	vector<int> num1{ 1, 2, 2, 4 };
	auto result1 = solution.findErrorNums(num1);
	cout << "[" << result1[0] << ", " << result1[1] << "]\n";

	vector<int> num2{ 1, 2, 4, 4, 5 };
	auto result2 = solution.findErrorNums(num2);
	cout << "[" << result2[0] << ", " << result2[1] << "]\n";

	cin.get();

	return 0;
}