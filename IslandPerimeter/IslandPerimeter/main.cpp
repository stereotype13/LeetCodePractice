/*
You are given a map in form of a two-dimensional integer grid where 1 represents land and 0 represents water.

Grid cells are connected horizontally/vertically (not diagonally). The grid is completely surrounded by water, and there is exactly one island (i.e., one or more connected land cells).

The island doesn't have "lakes" (water inside that isn't connected to the water around the island). One cell is a square with side length 1. The grid is rectangular, width and height don't exceed 100. Determine the perimeter of the island.



Example:

Input:
[[0,1,0,0],
 [1,1,1,0],
 [0,1,0,0],
 [1,1,0,0]]

Output: 16

Explanation: The perimeter is the 16 yellow stripes in the image below:


*/
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
	int search(int startX, int startY, vector<vector<int>>& grid) {
		int perimeter = 0;
		queue<pair<int, int>> squaresToSearch;
		squaresToSearch.push({ startX, startY });

		while (!squaresToSearch.empty()) {
			auto coordinate = squaresToSearch.front();
			squaresToSearch.pop();

			int x = coordinate.first;
			int y = coordinate.second;

			if (grid[y][x] == -1)
				continue;

			int sidesWithWater = 4;

			for (int i = -1; i < 2; ++i) {
				if (i == 0)
					continue;

				int row = y + i;
				if (row > -1 && row < grid.size()) {
					if (grid[row][x] == 1) {
						squaresToSearch.push({ x, row });
						
						--sidesWithWater;
					}

					if (grid[row][x] == -1) {
						--sidesWithWater;
					}
					
				}
					
			}

			for (int j = -1; j < 2; ++j) {
				if (j == 0)
					continue;

				int column = x + j;
				if (column > -1 && column < grid[0].size()) {
					

					if (grid[y][column] == 1) {
						squaresToSearch.push({ column, y });
						
						--sidesWithWater;
					}

					if (grid[y][column] == -1) {
						--sidesWithWater;
					}
				}
					
			}

			perimeter += sidesWithWater;
			grid[coordinate.second][coordinate.first] = -1;
		}
		

		return perimeter;
	}
public:
	int islandPerimeter(vector<vector<int>>& grid) {
		int startX, startY;
		for (int i = 0; i < grid.size(); ++i) {
			for (int j = 0; j < grid[0].size(); ++j) {
				if (grid[i][j] == 1) {
					return search(j, i, grid);
				}
			}
		}
		return 0;
	}
};

int main(int argc, const char* argv[]) {
	Solution solution;

	vector<vector<int>> grid1{
		{0,1,0,0},
		{1,1,1,0},
		{0,1,0,0},
		{1,1,0,0}
	};
	cout << solution.islandPerimeter(grid1) << endl;

	vector<vector<int>> grid2{
		{0,0,0,0},
		{0,0,0,0},
		{0,1,0,0},
		{0,0,0,0}
	};
	cout << solution.islandPerimeter(grid2) << endl;

	vector<vector<int>> grid3{
		{0,0,0,0},
		{0,0,0,0},
		{0,1,1,0},
		{0,0,0,0}
	};
	cout << solution.islandPerimeter(grid3) << endl;

	vector<vector<int>> grid4{
		{1,1},
		{1,1},
	
	};
	cout << solution.islandPerimeter(grid4) << endl;

	cin.get();
	return 0;
}