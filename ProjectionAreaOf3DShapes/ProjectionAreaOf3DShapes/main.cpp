/*
On a N * N grid, we place some 1 * 1 * 1 cubes that are axis-aligned with the x, y, and z axes.

Each value v = grid[i][j] represents a tower of v cubes placed on top of grid cell (i, j).

Now we view the projection of these cubes onto the xy, yz, and zx planes.

A projection is like a shadow, that maps our 3 dimensional figure to a 2 dimensional plane.

Here, we are viewing the "shadow" when looking at the cubes from the top, the front, and the side.

Return the total area of all three projections.



Example 1:

Input: [[2]]
Output: 5
Example 2:

Input: [[1,2],[3,4]]
Output: 17
Explanation:
Here are the three projections ("shadows") of the shape made with each axis-aligned plane.

Example 3:

Input: [[1,0],[0,2]]
Output: 8
Example 4:

Input: [[1,1,1],[1,0,1],[1,1,1]]
Output: 14
Example 5:

Input: [[2,2,2],[2,1,2],[2,2,2]]
Output: 21


Note:

1 <= grid.length = grid[0].length <= 50
0 <= grid[i][j] <= 50
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	int projectionArea(vector<vector<int>>& grid) {
		//always N x N according to description
		size_t rows = grid.size();
		size_t cols = rows;
		int totalArea = 0;

		int zeroCount = 0;

		for (size_t row = 0; row < rows; ++row) {
			
			int area = 0;
			for (size_t col = 0; col < cols; ++col) {
				auto value = grid[row][col];

				if (value == 0) {
					++zeroCount;
					continue;
				}	

				area = max(area, grid[row][col]);
			}
				

			totalArea += area;
		}

		for (size_t col = 0; col < cols; ++col) {
			
			int area = 0;
			for (size_t row = 0; row < rows; ++row) 
				area = max(area, grid[row][col]);

			totalArea += area;
		}

		totalArea += (int)rows * (int)cols - zeroCount;

		return totalArea;
	}
};

int main() {
	Solution solution;
	
	vector<vector<int>> grid1{
		{1, 1, 1},
		{1, 0, 1},
		{1, 1, 1}
	};
	cout << solution.projectionArea(grid1) << endl; //should be 14

	vector<vector<int>> grid2{
		{2, 2, 2},
		{2, 1, 2},
		{2, 2, 2}
	};
	cout << solution.projectionArea(grid2) << endl; //should be 21

	cin.get();
	return 0;
}