/*
Tic-tac-toe is played by two players A and B on a 3 x 3 grid.

Here are the rules of Tic-Tac-Toe:

	Players take turns placing characters into empty squares (" ").
	The first player A always places "X" characters, while the second player B always places "O" characters.
	"X" and "O" characters are always placed into empty squares, never on filled ones.
	The game ends when there are 3 of the same (non-empty) character filling any row, column, or diagonal.
	The game also ends if all squares are non-empty.
	No more moves can be played if the game is over.

Given an array moves where each element is another array of size 2 corresponding to the row and column of the grid where 
they mark their respective character in the order in which A and B play.

Return the winner of the game if it exists (A or B), in case the game ends in a draw return "Draw", if there are still 
movements to play return "Pending".

You can assume that moves is valid (It follows the rules of Tic-Tac-Toe), the grid is initially empty and A will play first.



Example 1:

Input: moves = [[0,0],[2,0],[1,1],[2,1],[2,2]]
Output: "A"
Explanation: "A" wins, he always plays first.
"X  "    "X  "    "X  "    "X  "    "X  "
"   " -> "   " -> " X " -> " X " -> " X "
"   "    "O  "    "O  "    "OO "    "OOX"

Example 2:

Input: moves = [[0,0],[1,1],[0,1],[0,2],[1,0],[2,0]]
Output: "B"
Explanation: "B" wins.
"X  "    "X  "    "XX "    "XXO"    "XXO"    "XXO"
"   " -> " O " -> " O " -> " O " -> "XO " -> "XO "
"   "    "   "    "   "    "   "    "   "    "O  "

Example 3:

Input: moves = [[0,0],[1,1],[2,0],[1,0],[1,2],[2,1],[0,1],[0,2],[2,2]]
Output: "Draw"
Explanation: The game ends in a draw since there are no moves to make.
"XXO"
"OOX"
"XOX"

Example 4:

Input: moves = [[0,0],[1,1]]
Output: "Pending"
Explanation: The game has not finished yet.
"X  "
" O "
"   "



Constraints:

	1 <= moves.length <= 9
	moves[i].length == 2
	0 <= moves[i][j] <= 2
	There are no repeated elements on moves.
	moves follow the rules of tic tac toe.

*/
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
	string tictactoe(vector<vector<int>>& moves) {
		vector<int> row( 3, 0 );
		vector<vector<int>> grid(3, row);

		for (int i = 0; i < (int)moves.size(); ++i) 
			grid[moves[i][0]][moves[i][1]] = i % 2 == 0 ? 1 : 2;
		
		for (int i = 0; i < 3; ++i) {
			if (grid[i][0] == grid[i][1] && grid[i][1] == grid[i][2] && grid[i][0] != 0) 
				return grid[i][0] == 1 ? "A" : "B";	
		}

		for (int i = 0; i < 3; ++i) {
			if (grid[0][i] == grid[1][i] && grid[1][i] == grid[2][i] && grid[0][i] != 0)
				return grid[0][i] == 1 ? "A" : "B";
		}

		if (grid[0][0] == grid[1][1] && grid[1][1] == grid[2][2] && grid[0][0] != 0)
			return grid[0][0] == 1 ? "A" : "B";

		if (grid[0][2] == grid[1][1] && grid[1][1] == grid[2][0] && grid[0][2] != 0)
			return grid[0][2] == 1 ? "A" : "B";

		return moves.size() == 9 ? "Draw" : "Pending";
	}
};

int main() {
	Solution solution;

	vector<vector<int>> moves1{{0, 0}, {2, 0}, {1, 1}, {2, 1}, {2, 2}};
	cout << solution.tictactoe(moves1) << endl;

	vector<vector<int>> moves2{{0, 0}, {1, 1}, {0, 1}, {0, 2}, {1, 0}, {2, 0}};
	cout << solution.tictactoe(moves2) << endl;

	vector<vector<int>> moves3{{0, 0}, {1, 1}, {2, 0}, {1, 0}, {1, 2}, {2, 1}, {0, 1}, {0, 2}, {2, 2}};
	cout << solution.tictactoe(moves3) << endl;

	cin.get();
	return 0;
}