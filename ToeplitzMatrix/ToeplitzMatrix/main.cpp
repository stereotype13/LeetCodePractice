/*
A matrix is Toeplitz if every diagonal from top-left to bottom-right has the same element.

Now given an M x N matrix, return True if and only if the matrix is Toeplitz.


Example 1:

Input:
matrix = [
  [1,2,3,4],
  [5,1,2,3],
  [9,5,1,2]
]
Output: True
Explanation:
In the above grid, the diagonals are:
"[9]", "[5, 5]", "[1, 1, 1]", "[2, 2, 2]", "[3, 3]", "[4]".
In each diagonal all elements are the same, so the answer is True.
Example 2:

Input:
matrix = [
  [1,2],
  [2,2]
]
Output: False
Explanation:
The diagonal "[1, 2]" has different elements.

Note:

matrix will be a 2D array of integers.
matrix will have a number of rows and columns in range [1, 20].
matrix[i][j] will be integers in range [0, 99].

Follow up:

What if the matrix is stored on disk, and the memory is limited such that you can only load at most one row of the matrix into the memory at once?
What if the matrix is so large that you can only load up a partial row into the memory at once?
*/
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	bool isToeplitzMatrix(vector<vector<int>>& matrix) {
		int rows = (int)matrix.size();

		if (rows == 1)
			return true;

		int columns = (int)matrix[0].size();

		if (columns == 1)
			return true;

		//first row
		for (int c = 0; c < columns - 1; ++c) {
			int number = matrix[0][c];
			int temp_c = c + 1;
			for (int r = 1; r < rows && temp_c < columns; ++r) {
				
				if (matrix[r][temp_c] != number)
					return false;

				++temp_c;
			}
		}

		//remaining rows
		for (int r = 1; r < rows - 1; ++r) {
			int number = matrix[r][0];
			int temp_r = r + 1;
			for (int c = 1; c < columns && temp_r < rows; ++c) {
				if (matrix[temp_r][c] != number)
					return false;

				++temp_r;
			}
		}

		return true;
	}
};

int main() {
	Solution solution;
	
	auto matrix1 = vector<vector<int>>{
		{1,2,3,4},
		{5,1,2,3},
		{9,5,1,2}
	};
	cout << boolalpha << solution.isToeplitzMatrix(matrix1) << endl;

	auto matrix2 = vector<vector<int>>{
		{1, 2},
		{2, 2}
	};
	cout << boolalpha << solution.isToeplitzMatrix(matrix2) << endl;
	
	cin.get();
	return 0;
}