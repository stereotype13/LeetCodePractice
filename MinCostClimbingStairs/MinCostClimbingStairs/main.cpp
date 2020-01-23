/*
On a staircase, the i-th step has some non-negative cost cost[i] assigned (0 indexed).

Once you pay the cost, you can either climb one or two steps. You need to find minimum cost to reach the top of the floor, and you can either start from the step with index 0, or the step with index 1.

Example 1:
Input: cost = [10, 15, 20]
Output: 15
Explanation: Cheapest is start on cost[1], pay that cost and go to the top.
Example 2:
Input: cost = [1, 100, 1, 1, 1, 100, 1, 1, 100, 1]
Output: 6
Explanation: Cheapest is start on cost[0], and only step on 1s, skipping cost[3].
Note:
cost will have a length in the range [2, 1000].
Every cost[i] will be an integer in the range [0, 999].
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
	vector<int> runningCost;
	int helper(vector<int>& cost, vector<int>& runningCost, int step) {

		int oneStep;
		if (step + 1 < (int)cost.size()) {
			if (runningCost[step + 1] == -1)
				oneStep = helper(cost, runningCost, step + 1);
			else
				oneStep = runningCost[step + 1];
		}
		else {
			runningCost[step] = cost[step];
			return runningCost[step];
		}

		int twoStep;
		if (step + 2 < (int)cost.size()) {
			if (runningCost[step + 2] == -1)
				twoStep = helper(cost, runningCost, step + 2);
			else
				twoStep = runningCost[step + 2];
		}
		else {
			runningCost[step] = cost[step];
			return runningCost[step];
		}

		runningCost[step] = cost[step] + min(oneStep, twoStep);
		return runningCost[step];
	}
public:
	int minCostClimbingStairs(vector<int>& cost) {
		vector<int> runningCost(cost.size(), -1);
		return min(helper(cost, runningCost, 0), helper(cost, runningCost, 1));
	}
};

int main() {
	Solution solution;

	auto vec1 = vector<int>{ 0, 2, 4, 1, 3, 8 };
	cout << solution.minCostClimbingStairs(vec1) << endl; //6

	auto vec2 = vector<int>{ 10, 15, 20 };
	cout << solution.minCostClimbingStairs(vec2) << endl;

	auto vec3 = vector<int>{ 1, 100, 1, 1, 1, 100, 1, 1, 100, 1 };
	cout << solution.minCostClimbingStairs(vec3) << endl;

	cin.get();
}