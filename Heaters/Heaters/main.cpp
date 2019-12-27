/*
Winter is coming! Your first job during the contest is to design a standard heater with fixed warm radius to warm all the houses.

Now, you are given positions of houses and heaters on a horizontal line, find out minimum radius of heaters so that all houses could be covered by those heaters.

So, your input will be the positions of houses and heaters seperately, and your expected output will be the minimum radius standard of heaters.

Note:

Numbers of houses and heaters you are given are non-negative and will not exceed 25000.
Positions of houses and heaters you are given are non-negative and will not exceed 10^9.
As long as a house is in the heaters' warm radius range, it can be warmed.
All the heaters follow your radius standard and the warm radius will the same.


Example 1:

Input: [1,2,3],[2]
Output: 1
Explanation: The only heater was placed in the position 2, and if we use the radius 1 standard, then all the houses can be warmed.


Example 2:

Input: [1,2,3,4],[1,4]
Output: 1
Explanation: The two heater was placed in the position 1 and 4. We need to use radius 1 standard, then all the houses can be warmed.
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	int findRadius(vector<int>& houses, vector<int>& heaters) {
		if (houses.empty())
			return 0;

		sort(houses.begin(), houses.end());
		sort(heaters.begin(), heaters.end());

		int maximumMinimumDistance = 0;
		for (const auto& house : houses) {
			int minDistance = INT_MAX;
			for (const auto& heater : heaters) {
				int distance = abs(heater - house);
				if (distance > minDistance)
					break;

				minDistance = distance;
			}
			maximumMinimumDistance = max(maximumMinimumDistance, minDistance);
		}

		return maximumMinimumDistance;
	}
};

class Solution2 {
public:
	int findRadius(vector<int>& houses, vector<int>& heaters) {
		sort(heaters.begin(), heaters.end());

		int radius = 0;

		for (const auto& house : houses) {
			auto it = lower_bound(heaters.begin(), heaters.end(), house);

			if (it == heaters.begin()) {
				radius = max(radius, heaters.front() - house);
			}
			else if (it == heaters.end()) {
				radius = max(radius, house - heaters.back());
			}
			else {
				int temp = min(*it - house, house - *(it - 1));
				radius = max(radius, temp);
			}
		}

		return radius;
	}
};

int main(int argc, const char* argv[]) {
	Solution2 solution;

	vector<int> houses1{ 1, 2, 3 }, heaters1{ 2 };
	cout << solution.findRadius(houses1, heaters1) << endl;

	vector<int> houses2{ 1, 2, 3 }, heaters2{ 1, 4 };
	cout << solution.findRadius(houses2, heaters2) << endl;

	vector<int> houses3{ 1, 5 }, heaters3{ 2 };
	cout << solution.findRadius(houses3, heaters3) << endl;

	vector<int> houses4{ 4, 5, 3, 7, 8, 1 }, heaters4{ 5, 2, 3 };
	cout << solution.findRadius(houses4, heaters4) << endl;

	cin.get();
	return 0;
}