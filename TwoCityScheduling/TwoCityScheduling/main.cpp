/*
There are 2N people a company is planning to interview. The cost of flying the i-th person to city A is costs[i][0], 
and the cost of flying the i-th person to city B is costs[i][1].

Return the minimum cost to fly every person to a city such that exactly N people arrive in each city.



Example 1:

Input: [[10,20],[30,200],[400,50],[30,20]]
Output: 110
Explanation:
The first person goes to city A for a cost of 10.
The second person goes to city A for a cost of 30.
The third person goes to city B for a cost of 50.
The fourth person goes to city B for a cost of 20.

The total minimum cost is 10 + 30 + 50 + 20 = 110 to have half the people interviewing in each city.



Note:

	1 <= costs.length <= 100
	It is guaranteed that costs.length is even.
	1 <= costs[i][0], costs[i][1] <= 1000

*/
#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;



class Solution {
public:
	int twoCitySchedCost(vector<vector<int>>& costs) {
		int N = (int)costs.size() / 2;
		int total = 0;
		
		sort(costs.begin(), costs.end(), [](const vector<int>& x, const vector<int>& y) {
			return (x[0] - x[1]) < (y[0] - y[1]);
		});

		for (int i = 0; i < N; ++i)
			total += costs[i][0] + costs[i + N][1];
			
		return total;
	}
};

int main(int argc, const char* argv[]) {
	Solution solution;

	vector<vector<int>> costs1{{10, 20}, {30, 200}, {400, 50}, {30, 20}};
	cout << solution.twoCitySchedCost(costs1) << endl; //110

	cin.get();
	return 0;
}