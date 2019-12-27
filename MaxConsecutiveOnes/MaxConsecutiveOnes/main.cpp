/*
Given a binary array, find the maximum number of consecutive 1s in this array.

Example 1:
Input: [1,1,0,1,1,1]
Output: 3
Explanation: The first two digits or the last three digits are consecutive 1s.
	The maximum number of consecutive 1s is 3.
Note:

The input array will only contain 0 and 1.
The length of input array is a positive integer and will not exceed 10,000
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	int findMaxConsecutiveOnes(vector<int>& nums) {
		if (nums.empty())
			return 0;

		int maxConsecutiveOnes = 0;
		int onesCount = 0;

		for (const auto& i : nums) {
			if (!i) {
				maxConsecutiveOnes = max(maxConsecutiveOnes, onesCount);
				onesCount = 0;
				continue;
			}
			++onesCount;
		}
		maxConsecutiveOnes = max(maxConsecutiveOnes, onesCount);
		return maxConsecutiveOnes;
	}
};

int main(int argc, const char* argv[]) {
	Solution solution;

	vector<int> vec1{ 1,1,0,1,1,1 };
	cout << solution.findMaxConsecutiveOnes(vec1) << endl;

	vector<int> vec2{ 1,1,0,1,1,0 };
	cout << solution.findMaxConsecutiveOnes(vec2) << endl;

	vector<int> vec3{ 0, 0, 0 };
	cout << solution.findMaxConsecutiveOnes(vec3) << endl;

	cin.get();
	return 0;
}