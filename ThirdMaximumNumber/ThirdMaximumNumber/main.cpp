/*
Given a non-empty array of integers, return the third maximum number in this array. If it does not exist, return the maximum number. 
The time complexity must be in O(n).

Example 1:
Input: [3, 2, 1]

Output: 1

Explanation: The third maximum is 1.
Example 2:
Input: [1, 2]

Output: 2

Explanation: The third maximum does not exist, so the maximum (2) is returned instead.
Example 3:
Input: [2, 2, 3, 1]

Output: 1

Explanation: Note that the third maximum here means the third maximum distinct number.
Both numbers with value 2 are both considered as second maximum.
*/
#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

class Solution {
public:
	int thirdMax(vector<int>& nums) {
		set<int> highestThree;
		
		for (const auto& i : nums) {
			highestThree.emplace(i);

			if (highestThree.size() > 3)
				highestThree.erase(highestThree.begin());
		}

		if (highestThree.size() == 3)
			return *(highestThree.begin());

		return *(highestThree.rbegin());

	}
};

int main(int argc, char* argv[]) {
	Solution solution;
	vector<int> vec1{ 3, 2, 1 };
	cout << solution.thirdMax(vec1) << endl;

	vector<int> vec2{ 1, 2 };
	cout << solution.thirdMax(vec2) << endl;

	vector<int> vec3{ 2, 2, 3, 1 };
	cout << solution.thirdMax(vec3) << endl;

	cin.get();
	return 0;
}