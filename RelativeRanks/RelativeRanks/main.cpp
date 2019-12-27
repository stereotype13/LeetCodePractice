/*
Given scores of N athletes, find their relative ranks and the people with the top three highest scores, who will be awarded medals: "Gold Medal", "Silver Medal" and "Bronze Medal".

Example 1:
Input: [5, 4, 3, 2, 1]
Output: ["Gold Medal", "Silver Medal", "Bronze Medal", "4", "5"]
Explanation: The first three athletes got the top three highest scores, so they got "Gold Medal", "Silver Medal" and "Bronze Medal".
For the left two athletes, you just need to output their relative ranks according to their scores.
Note:
N is a positive integer and won't exceed 10,000.
All the scores of athletes are guaranteed to be unique.
*/
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>

using namespace std;

class Solution {
public:
	vector<string> findRelativeRanks(vector<int>& nums) {
		if (nums.empty())
			return {};

		vector<int> sortedNums = nums;
		sort(sortedNums.begin(), sortedNums.end(), greater<int>());

		unordered_map<int, string> ranker;
		for (int i = 0; i < sortedNums.size(); ++i) {
			if (i == 0) {
				ranker[sortedNums[i]] = "Gold Medal";
				continue;
			}

			if (i == 1) {
				ranker[sortedNums[i]] = "Silver Medal";
				continue;
			}

			if (i == 2) {
				ranker[sortedNums[i]] = "Bronze Medal";
				continue;
			}

			ranker[sortedNums[i]] = to_string(i + 1);
				
		}

		vector<string> result;
		for (const auto& i : nums)
			result.push_back(ranker[i]);

		return result;
	}
};

int main(int argc, const char* argv[]) {
	Solution solution;
	vector<int> nums1{ 5, 4, 3, 2, 1 };
	auto result1 = solution.findRelativeRanks(nums1);

	cin.get();
	return 0;
}