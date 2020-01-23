/*
A 3 x 3 magic square is a 3 x 3 grid filled with distinct numbers from 1 to 9 such that each row, column, and both diagonals all have the same sum.

Given an grid of integers, how many 3 x 3 "magic square" subgrids are there?  (Each subgrid is contiguous).



Example 1:

Input: [[4,3,8,4],
		[9,5,1,9],
		[2,7,6,2]]
Output: 1
Explanation:
The following subgrid is a 3 x 3 magic square:
438
951
276

while this one is not:
384
519
762

In total, there is only one magic square inside the given grid.
Note:

1 <= grid.length <= 10
1 <= grid[0].length <= 10
0 <= grid[i][j] <= 15
*/
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	int numMagicSquaresInside(vector<vector<int>>& grid) {
		if (grid.empty() || grid.size() < 3 || grid[0].size() < 3)
			return 0;

		
		int magicSquareCount = 0;
		for (int row = 0; row < grid.size() - 2; ++row) {
		
			for (int col = 0; col < grid[0].size() - 2; ++col) {

				bool isMagicSquare = true;
				vector<bool> seenNumbers(9, false); //all numbers must be unique and be between 1 and 9
				for (int i = 0; i < 3; ++i) {
					for (int j = 0; j < 3; ++j) {
						int tempNumber = grid[row + i][col + j];
						if (tempNumber < 1 || tempNumber > 9 || seenNumbers[tempNumber - 1]) {
							isMagicSquare = false;
							break;
						}
						seenNumbers[tempNumber - 1] = true;
					}
					if (!isMagicSquare)
						break;
				}

				if (!isMagicSquare)
					continue;
				
				int r1 = grid[row][col] + grid[row][col + 1] + grid[row][col + 2];
				int r2 = grid[row + 1][col] + grid[row + 1][col + 1] + grid[row + 1][col + 2];
				int r3 = grid[row + 2][col] + grid[row + 2][col + 1] + grid[row + 2][col + 2];

				int c1 = grid[row][col] + grid[row + 1][col] + grid[row + 2][col];
				int c2 = grid[row][col + 1] + grid[row + 1][col + 1] + grid[row + 2][col + 1];
				int c3 = grid[row][col + 2] + grid[row + 1][col + 2] + grid[row + 2][col + 2];

				int d1 = grid[row][col] + grid[row + 1][col + 1] + grid[row + 2][col + 2];
				int d2 = grid[row][col + 2] + grid[row + 1][col + 1] + grid[row + 2][col];

				if (r1 == r2 && r2 == r3 && r3 == c1 && c1 == c2 && c2 == c3 && c3 == d1 && d1 == d2)
					++magicSquareCount;

				

			}
		
		}

		return magicSquareCount;
	}
};

int main(int argc, const char* argv[]) {
	Solution solution;

	vector<vector<int>> m1{
		{4,3,8,4},
		{9,5,1,9},
		{2,7,6,2}
	};

	cout << solution.numMagicSquaresInside(m1) << endl;

	vector<vector<int>> m2{
		{5,5,5},
		{5,5,5},
		{5,5,5}
	};// Got 1, but expected 0 ? !

	cout << solution.numMagicSquaresInside(m2) << endl;

	/*
	{
	{7,  6,  2,  2,  4},
	{4,  4,  9,  2, 10},
	{9,  7,  8,  3, 10},
	{8,  1,  9,  7,  5},
	{7, 10,  4, 11,  6}}
	*/

	vector<vector<int>> m3{
		{7,  6,  2,  2,  4},
		{4,  4,  9,  2, 10},
		{9,  7,  8,  3, 10},
		{8,  1,  9,  7,  5},
		{7, 10,  4, 11,  6}
	};
	cout << solution.numMagicSquaresInside(m3) << endl;

	cin.get();
	return 0;
}