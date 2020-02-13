/*
We are given a matrix with R rows and C columns has cells with integer coordinates (r, c), where 0 <= r < R and 0 <= c < C.

Additionally, we are given a cell in that matrix with coordinates (r0, c0).

Return the coordinates of all cells in the matrix, sorted by their distance from (r0, c0) from smallest distance to largest distance.  
Here, the distance between two cells (r1, c1) and (r2, c2) is the Manhattan distance, |r1 - r2| + |c1 - c2|.  (You may return the answer 
in any order that satisfies this condition.)



Example 1:

Input: R = 1, C = 2, r0 = 0, c0 = 0
Output: [[0,0],[0,1]]
Explanation: The distances from (r0, c0) to other cells are: [0,1]

Example 2:

Input: R = 2, C = 2, r0 = 0, c0 = 1
Output: [[0,1],[0,0],[1,1],[1,0]]
Explanation: The distances from (r0, c0) to other cells are: [0,1,1,2]
The answer [[0,1],[1,1],[0,0],[1,0]] would also be accepted as correct.

Example 3:

Input: R = 2, C = 3, r0 = 1, c0 = 2
Output: [[1,2],[0,2],[1,1],[0,1],[1,0],[0,0]]
Explanation: The distances from (r0, c0) to other cells are: [0,1,1,2,2,3]
There are other answers that would also be accepted as correct, such as [[1,2],[1,1],[0,2],[1,0],[0,1],[0,0]].



Note:

	1 <= R <= 100
	1 <= C <= 100
	0 <= r0 < R
	0 <= c0 < C


*/
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
	vector<vector<int>> allCellsDistOrder(int R, int C, int r0, int c0) {
		vector<int> row(C, 0);
		vector<vector<int>> matrix(R, row), result;
		queue<pair<int, int>> coordsToCheck;

		coordsToCheck.push({ r0, c0 });
		matrix[r0][c0] = 1;

		while (!coordsToCheck.empty()) {
			auto point = coordsToCheck.front();
			
			result.push_back({ point.first, point.second });
			coordsToCheck.pop();

			if (point.first - 1 > -1 && matrix[point.first - 1][point.second] != 1) {
				coordsToCheck.push({ point.first - 1, point.second });
				matrix[point.first - 1][point.second] = 1;
			}
				

			if (point.first + 1 < R && matrix[point.first + 1][point.second] != 1) {
				coordsToCheck.push({ point.first + 1, point.second });
				matrix[point.first + 1][point.second] = 1;
			}
				

			if (point.second - 1 > -1 && matrix[point.first][point.second - 1] != 1) {
				coordsToCheck.push({ point.first, point.second - 1 });
				matrix[point.first][point.second - 1] = 1;
			}
				

			if (point.second + 1 < C && matrix[point.first][point.second + 1] != 1) {
				coordsToCheck.push({ point.first, point.second + 1 });
				matrix[point.first][point.second + 1] = 1;
			}
				
		}

		return result;

	}
};

int main() {
	Solution solution;

	/*
	Input: R = 1, C = 2, r0 = 0, c0 = 0
	Output: [[0,0],[0,1]]
	*/
	auto result1 = solution.allCellsDistOrder(1, 2, 0, 0);

	/*
	Input: R = 2, C = 2, r0 = 0, c0 = 1
	Output: [[0,1],[0,0],[1,1],[1,0]]
	*/
	auto result2 = solution.allCellsDistOrder(2, 2, 0, 1);

	cin.get();
	return 0;
}