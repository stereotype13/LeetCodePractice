/*
You have a list of points in the plane. Return the area of the largest triangle that can be formed by any 3 of the points.

Example:
Input: points = [[0,0],[0,1],[1,0],[0,2],[2,0]]
Output: 2
Explanation:
The five points are show in the figure below. The red triangle is the largest.


Notes:

3 <= points.length <= 50.
No points will be duplicated.
 -50 <= points[i][j] <= 50.
Answers within 10^-6 of the true value will be accepted as correct.

*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
	double distance(vector<int>& p1, vector<int>& p2) {
		int xDiff = p1[0] - p2[0];
		int yDiff = p1[1] - p2[1];
		return sqrt(xDiff * xDiff + yDiff * yDiff);
	}
public:
	double largestTriangleArea(vector<vector<int>>& points) {
		if (points.empty())
			return 0;

		vector<vector<unsigned int>> pointIndices;
		
		double maxArea = 0;

		for (unsigned int i = 0; i < points.size() - 2; ++i) {
			for (unsigned int j = i + 1; j < points.size() - 1; ++j) {
				for (unsigned int k = j + 1; k < points.size(); ++k) {
					pointIndices.push_back({ i, j, k });
				}
			}
		}

		for (auto& vec : pointIndices) {
			auto p1 = points[vec[0]];
			auto p2 = points[vec[1]];
			auto p3 = points[vec[2]];

			double a = distance(p1, p2);
			double b = distance(p2, p3);
			double c = distance(p3, p1);

			double s = 0.5 * (a + b + c);

			double area = sqrt(s * (s - a) * (s - b) * (s - c));
			maxArea = max(maxArea, area);
		}

		return maxArea;
	}
};

int main() {
	Solution solution;

	vector<vector<int>> points1{{0, 0}, {0, 1}, {1, 0}, {0, 2}, {2, 0}};
	cout << solution.largestTriangleArea(points1) << endl;


	cin.get();
	return 0;
}