/*
Students are asked to stand in non-decreasing order of heights for an annual photo.

Return the minimum number of students that must move in order for all students to be standing in non-decreasing order of height.



Example 1:

Input: heights = [1,1,4,2,1,3]
Output: 3



Constraints:

	1 <= heights.length <= 100
	1 <= heights[i] <= 100


*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	int heightChecker(vector<int>& heights) {
		auto original = heights;
		sort(heights.begin(), heights.end());

		int count = 0;
		for (unsigned int i = 0; i < heights.size(); ++i) {
			if (original[i] != heights[i])
				++count;
		}

		return count;
	}
};

int main(int argc, const char* argv[]) {
	Solution solution;

	vector<int> input1{ 1,1,4,2,1,3 };
	cout << solution.heightChecker(input1) << endl;

	cin.get();
	return 0;
}