/*
On an 8 x 8 chessboard, there is one white rook.  There also may be empty squares, white bishops, and black pawns.  
These are given as characters 'R', '.', 'B', and 'p' respectively. Uppercase characters represent white pieces, and 
lowercase characters represent black pieces.

The rook moves as in the rules of Chess: it chooses one of four cardinal directions (north, east, west, and south), 
then moves in that direction until it chooses to stop, reaches the edge of the board, or captures an opposite colored 
pawn by moving to the same square it occupies.  Also, rooks cannot move into the same square as other friendly bishops.

Return the number of pawns the rook can capture in one move.



Example 1:

Input: 
[
[".",".",".",".",".",".",".","."],
[".",".",".","p",".",".",".","."],
[".",".",".","R",".",".",".","p"],
[".",".",".",".",".",".",".","."],
[".",".",".",".",".",".",".","."],
[".",".",".","p",".",".",".","."],
[".",".",".",".",".",".",".","."],
[".",".",".",".",".",".",".","."]]
Output: 3
Explanation:
In this example the rook is able to capture all the pawns.

Example 2:

Input: [
[".",".",".",".",".",".",".","."],
[".","p","p","p","p","p",".","."],
[".","p","p","B","p","p",".","."],
[".","p","B","R","B","p",".","."],
[".","p","p","B","p","p",".","."],
[".","p","p","p","p","p",".","."],
[".",".",".",".",".",".",".","."],
[".",".",".",".",".",".",".","."]]
Output: 0
Explanation:
Bishops are blocking the rook to capture any pawn.

Example 3:

Input: [
[".",".",".",".",".",".",".","."],
[".",".",".","p",".",".",".","."],
[".",".",".","p",".",".",".","."],
["p","p",".","R",".","p","B","."],
[".",".",".",".",".",".",".","."],
[".",".",".","B",".",".",".","."],
[".",".",".","p",".",".",".","."],
[".",".",".",".",".",".",".","."]]
Output: 3
Explanation:
The rook can capture the pawns at positions b5, d6 and f5.



Note:

	board.length == board[i].length == 8
	board[i][j] is either 'R', '.', 'B', or 'p'
	There is exactly one cell with board[i][j] == 'R'


*/
#include <iostream>
#include <vector>

using namespace std;

class Solution {
	enum direction {UP, RIGHT, DOWN, LEFT};
	pair<int, int> findRook(const vector<vector<char>>& board) {
		for (int row = 0; row < 8; ++row) {
			for (int col = 0; col < 8; ++col) {
				if (board[row][col] == 'R') {
					return { row, col };
				}
			}
		}
		return { -1, -1 };
	}

	bool canCapturePawn(const pair<int, int>& rookPosition, const vector<vector<char>>& board, int d) {
		int row = rookPosition.first, col = rookPosition.second;
		switch (d) {
		case direction::UP:
			while (row > -1) {
				if (board[row][col] == 'p')
					return true;

				if (board[row][col] == 'B')
					return false;

				--row;
			}
			break;

		case direction::RIGHT:
			while (col < 8) {
				if (board[row][col] == 'p')
					return true;

				if (board[row][col] == 'B')
					return false;

				++col;
			}
			break;

		case direction::DOWN:
			while (row < 8) {
				if (board[row][col] == 'p')
					return true;

				if (board[row][col] == 'B')
					return false;

				++row;
			}
			break;

		case direction::LEFT:
			while (col > -1) {
				if (board[row][col] == 'p')
					return true;

				if (board[row][col] == 'B')
					return false;

				--col;
			}
			break;
		}
		return false;
	}
public:
	int numRookCaptures(vector<vector<char>>& board) {

		auto rookPosition = findRook(board);

		int pawnCount = 0;

		if (canCapturePawn(rookPosition, board, direction::UP))
			++pawnCount;

		if (canCapturePawn(rookPosition, board, direction::RIGHT))
			++pawnCount;

		if (canCapturePawn(rookPosition, board, direction::DOWN))
			++pawnCount;

		if (canCapturePawn(rookPosition, board, direction::LEFT))
			++pawnCount;

		return pawnCount;

	}
};

int main() {
	Solution solution;

	vector<vector<char>> board1{
		{'.', '.', '.', '.', '.', '.', '.', '.'},
		{'.', '.', '.', 'p', '.', '.', '.', '.'},
		{'.', '.', '.', 'R', '.', '.', '.', 'p'},
		{'.', '.', '.', '.', '.', '.', '.', '.'},
		{'.', '.', '.', '.', '.', '.', '.', '.'},
		{'.', '.', '.', 'p', '.', '.', '.', '.'},
		{'.', '.', '.', '.', '.', '.', '.', '.'},
		{'.', '.', '.', '.', '.', '.', '.', '.'}
	};
	cout << solution.numRookCaptures(board1) << endl;

	cin.get();
	return 0;
}