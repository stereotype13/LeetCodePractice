/*
Given an array nums of integers, return how many of them contain an even number of digits.


Example 1:

Input: nums = [12,345,2,6,7896]
Output: 2
Explanation:
12 contains 2 digits (even number of digits).
345 contains 3 digits (odd number of digits).
2 contains 1 digit (odd number of digits).
6 contains 1 digit (odd number of digits).
7896 contains 4 digits (even number of digits).
Therefore only 12 and 7896 contain an even number of digits.
Example 2:

Input: nums = [555,901,482,1771]
Output: 1
Explanation:
Only 1771 contains an even number of digits.


Constraints:

1 <= nums.length <= 500
1 <= nums[i] <= 10^5
*/
#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
	int findNumbers(vector<int>& nums) {
		
		int evenCount = 0;
		for (const auto& i : nums) {
			if ((to_string(i)).size() % 2 == 0)
				++evenCount;
		}
		return evenCount;
	}
};

int main() {
	Solution solution;

	vector<int> input1{ 12,345,2,6,7896 };
	cout << solution.findNumbers(input1) << endl;

	vector<int> input2{ 555,901,482,1771 };
	cout << solution.findNumbers(input2) << endl;

	cin.get();
	return 0;
}