/*
On a N * N grid, we place some 1 * 1 * 1 cubes.

Each value v = grid[i][j] represents a tower of v cubes placed on top of grid cell (i, j).

Return the total surface area of the resulting shapes.



Example 1:

Input: [[2]]
Output: 10
Example 2:

Input: [[1,2],[3,4]]
Output: 34
Example 3:

Input: [[1,0],[0,2]]
Output: 16
Example 4:

Input: [[1,1,1],[1,0,1],[1,1,1]]
Output: 32
Example 5:

Input: [[2,2,2],[2,1,2],[2,2,2]]
Output: 46


Note:

1 <= N <= 50
0 <= grid[i][j] <= 50
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	int surfaceArea(vector<vector<int>>& grid) {
		if (grid.empty())
			return 0;

		unsigned int rows = grid.size();
		unsigned int cols = grid[0].size();

		int zeroCount = 0;
		int area = 0;
		for (unsigned int i = 0; i < rows; ++i) {

			area += grid[i][0];
			for (unsigned int j = 0; j < cols - 1; ++j) {
				area += abs(grid[i][j] - grid[i][j + 1]);
				
				if (grid[i][j] == 0)
					++zeroCount;
			}
			if (grid[i][cols - 1] == 0)
				++zeroCount;
			else
				area += grid[i][cols - 1];

		}

		for (unsigned int j = 0; j < cols; ++j) {

			area += grid[0][j];
			for (unsigned int i = 0; i < rows - 1; ++i)
				area += abs(grid[i][j] - grid[i + 1][j]);
			area += grid[rows - 1][j];

		}

		area += 2 * (rows * cols - zeroCount);

		return area;
	}
};

int main() {
	Solution solution;

	vector<vector<int>> grid1{ {1, 1, 1}, {1, 0, 1}, {1, 1, 1} };
	cout << solution.surfaceArea(grid1) << endl;

	vector<vector<int>> grid2{ {2, 2, 2}, {2, 1, 2}, {2, 2, 2} };
	cout << solution.surfaceArea(grid2) << endl;

	vector<vector<int>> grid3{ {1, 0}, {0, 2} };
	cout << solution.surfaceArea(grid3) << endl;

	cin.get();

	return 0;
}