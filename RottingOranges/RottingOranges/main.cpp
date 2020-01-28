/*
In a given grid, each cell can have one of three values:

	the value 0 representing an empty cell;
	the value 1 representing a fresh orange;
	the value 2 representing a rotten orange.

Every minute, any fresh orange that is adjacent (4-directionally) to a rotten orange becomes rotten.

Return the minimum number of minutes that must elapse until no cell has a fresh orange.  If this is impossible, return -1 instead.



Example 1:

Input: [[2,1,1],
		[1,1,0],
		[0,1,1]]
Output: 4

Example 2:

Input: [[2,1,1],[0,1,1],[1,0,1]]
Output: -1
Explanation:  The orange in the bottom left corner (row 2, column 0) is never rotten, because rotting only happens 4-directionally.

Example 3:

Input: [[0,2]]
Output: 0
Explanation:  Since there are already no fresh oranges at minute 0, the answer is just 0.



Note:

	1 <= grid.length <= 10
	1 <= grid[0].length <= 10
	grid[i][j] is only 0, 1, or 2.


*/
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
	int orangesRotting(vector<vector<int>>& grid) {
		pair<int, int> firstRottenOrage{ -1, -1 };
		int freshCount = 0, rottenCount = 1;

		if (grid.size() < 2 && grid[0].size() < 2) {
			if (grid[0][0] == 0 || grid[0][0] == 2)
				return 0;

			return -1;
		}
			
		queue<pair<int, int>> freshOranges;
		for (int i = 0; i < (int)grid.size(); ++i) {
		
			for (int j = 0; j < (int)grid[0].size(); ++j) {
				if (grid[i][j] == 2) {
				
					firstRottenOrage.first = i;
					firstRottenOrage.second = j;
					freshOranges.push({i, j});
					continue;
				}
				if (grid[i][j] == 1)
					++freshCount;
			}
			
		}

		if (freshOranges.empty())
			return -1;


		int minutes = 0;
		while(!freshOranges.empty()) {
			bool incrementMinute = false;
			auto orange = freshOranges.front();
			freshOranges.pop();

			int row = 0, col = 0;

			//up

			row = orange.first - 1;
			col = orange.second;

			if (row >= 0 && grid[row][col] == 1) {
				grid[row][col] = 2;
				++rottenCount;
				freshOranges.push({row, col});
				incrementMinute = true;
			}

			//right

			row = orange.first;
			col = orange.second + 1;

			if (col < (int)grid[0].size() && grid[row][col] == 1) {
				grid[row][col] = 2;
				++rottenCount;
				freshOranges.push({ row, col });
				incrementMinute = true;
			}

			//down

			row = orange.first + 1;
			col = orange.second;

			if (row < (int)grid.size() && grid[row][col] == 1) {
				grid[row][col] = 2;
				++rottenCount;
				freshOranges.push({ row, col });
				incrementMinute = true;
			}

			//left

			row = orange.first;
			col = orange.second - 1;

			if (col >= 0 && grid[row][col] == 1) {
				grid[row][col] = 2;
				++rottenCount;
				freshOranges.push({ row, col });
				incrementMinute = true;
			}

			if(incrementMinute)
				++minutes;
		}

		if (rottenCount == freshCount + 1)
			return minutes;

		return -1;

	}
};

int main() {
	Solution solution;

	vector<vector<int>> grid1
		{{2, 1, 1},
		 {1, 1, 0},
		 {0, 1, 1}};

	cout << solution.orangesRotting(grid1) << endl;

	vector<vector<int>> grid2
	{ {0} };

	cout << solution.orangesRotting(grid2) << endl;

	vector<vector<int>> grid3
	{ {1}, {2}, {2} };

	cout << solution.orangesRotting(grid3) << endl;

	cin.get();
	return 0;
}