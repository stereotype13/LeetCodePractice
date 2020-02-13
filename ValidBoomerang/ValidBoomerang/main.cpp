/*
A boomerang is a set of 3 points that are all distinct and not in a straight line.

Given a list of three points in the plane, return whether these points are a boomerang.



Example 1:

Input: [[1,1],[2,3],[3,2]]
Output: true

Example 2:

Input: [[1,1],[2,2],[3,3]]
Output: false



Note:

	points.length == 3
	points[i].length == 2
	0 <= points[i][j] <= 100

*/
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	bool isBoomerang(vector<vector<int>>& points) {

		double run = points[1][0] - points[0][0];

		if (run == 0) {
			if (points[2][0] == points[1][0] || (points[0][1] == points[1][1]))
				return false;

			return true;
		}

		double m = (points[1][1] - points[0][1]) / run;
		double b = points[0][1] - points[0][0] * m;

		if (points[2][1] == m * points[2][0] + b)
			return false;

		return true;
	}
};

int main(int argc, const char* argv[]) {
	Solution solution;

	vector<vector<int>> input1{ {1, 1}, {2, 3}, {3, 2} };
	cout << boolalpha << solution.isBoomerang(input1) << endl;

	vector<vector<int>> input2{{1, 1}, {2, 2}, {3, 3}};
	cout << boolalpha << solution.isBoomerang(input2) << endl;

	//[[0,0],[2,1],[2,1]] should be false
	vector<vector<int>> input3{{0, 0}, {2, 1}, {2, 1}};
	cout << boolalpha << solution.isBoomerang(input3) << endl;

	//[[0,1],[0,1],[2,1]] should be false
	vector<vector<int>> input4{ {0, 1}, {0, 1}, {2, 1} };
	cout << boolalpha << solution.isBoomerang(input4) << endl;

	//[[0,0],[0,2],[2,1]] should be true
	vector<vector<int>> input5{ {0, 0}, {0, 2}, {2, 1} };
	cout << boolalpha << solution.isBoomerang(input5) << endl;

	cin.get();
	return 0;
}