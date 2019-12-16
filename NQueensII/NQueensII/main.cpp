#include <iostream>
#include <list>
#include <math.h>
#include <vector>

using namespace std;

class Solution {
	int n;
	int successes(int startingRowNumber, list<int>& availableRows, int columnNumber) {
		if (columnNumber == this->n)
			return 1;

		int numberOfSuccesses = 0;
		bool couldPlaceAQueen = false;
		for (const auto& row : availableRows) {
			if (abs(startingRowNumber - row) >= 2) {
				couldPlaceAQueen = true;
				list<int> newAvailableRows(availableRows.begin(), availableRows.end());
				newAvailableRows.remove(row);
				numberOfSuccesses += successes(row, newAvailableRows, columnNumber + 1);
				
			}
		}

		if (couldPlaceAQueen)
			return numberOfSuccesses;

		return 0;
	}

public:
	int totalNQueens(int n) {
		this->n = n;

		list<int> availableRows;
		for (int j = 0; j < this->n; ++j) {
			availableRows.push_back(j);
		}

		int totalSuccesses = 0;

		for (int i = 0; i < n; ++i) {
			list<int> newAvailableRows(availableRows.begin(), availableRows.end());
			newAvailableRows.remove(i);
			totalSuccesses += successes(i, newAvailableRows, 1);
			newAvailableRows.clear();
		}

		return totalSuccesses;
	}
};

/*
class Solution:
	def solveNQueens(self, n):

			def recurse(queens, xy_dif, xy_sum):
				#print(queens)
				# check if we places all queens
				p = len(queens)
				if p == n:
					result.append(queens)
				else:
				  # let's check all available variants
				  for q in range(n):
					  # if we have not checked all variants - give it a shot
					  if q not in queens and p-q not in xy_dif and p+q not in xy_sum:
						  recurse(queens + [q], xy_dif + [p-q], xy_sum + [p + q])

			result = []

			recurse([],[],[])
			print(result)

			return [["." * i + "Q" +"." * (n - i - 1) for i in res] for res in result]
*/

class Solution2 {
	int n = 0;
	int waysToPlaceQueens;

	void helper(vector<int>& columnsOccupiedByQueens, list<int>& leftDiagonalsToAvoid, list<int>& rightDiagonalsToAvoid) {
		unsigned int numberOfQueensPlaced = columnsOccupiedByQueens.size();

		if (numberOfQueensPlaced == this->n) {
			(this->waysToPlaceQueens)++;
		}
			 

		for (int column = 0; column < this->n; ++column) {
			

			if (find(columnsOccupiedByQueens.begin(), columnsOccupiedByQueens.end(), column) == columnsOccupiedByQueens.end() && find(rightDiagonalsToAvoid.begin(), rightDiagonalsToAvoid.end(), numberOfQueensPlaced - column) == rightDiagonalsToAvoid.end() && find(leftDiagonalsToAvoid.begin(), leftDiagonalsToAvoid.end(), numberOfQueensPlaced + column) == leftDiagonalsToAvoid.end()) {
				//we can place a queen on this column
				vector<int> newColumnsOccupedByQueens(columnsOccupiedByQueens.begin(), columnsOccupiedByQueens.end());
				list<int> newLeftDiagonalsToAvoid(leftDiagonalsToAvoid.begin(), leftDiagonalsToAvoid.end());
				list<int> newRightDiagonalsToAvoid(rightDiagonalsToAvoid.begin(), rightDiagonalsToAvoid.end());

				newColumnsOccupedByQueens.push_back(column);
				newRightDiagonalsToAvoid.push_back(numberOfQueensPlaced - column);
				newLeftDiagonalsToAvoid.push_back(numberOfQueensPlaced + column);

				helper(newColumnsOccupedByQueens, newLeftDiagonalsToAvoid, newRightDiagonalsToAvoid);
			}
		}

		return;
	}
	
public:
	int totalNQueens(int n) {
		this->waysToPlaceQueens = 0;
		this->n = n;

		//Place a queen on each column of the first row and recurse from there.
		for (int column = 0; column < this->n; ++column) {
			vector<int> columnsOccupiedByQueens{ column };
			list<int> leftDiagonalsToAvoid{column};
			list<int> rightDiagonalsToAvoid{ -column };
			
			helper(columnsOccupiedByQueens, leftDiagonalsToAvoid, rightDiagonalsToAvoid);

			columnsOccupiedByQueens.clear();
			leftDiagonalsToAvoid.clear();
			rightDiagonalsToAvoid.clear();
		}

		return this->waysToPlaceQueens;
	}


};

class Solution3 {
public:
	int totalNQueens(int n) {
		int ans = 0;
		vector<int> queens = vector<int>(n, 0);
		DFS(ans, queens, 0);
		return ans;
	}

	void DFS(int& ans, vector<int>& queens, int i) {
		if (i == queens.size())
		{
			ans++;
			return;
		}
		for (int j = 0; j < queens.size(); j++) {
			if (IsValid(queens, i, j)) {
				queens[i] = j;
				DFS(ans, queens, i + 1);
				queens[i] = 0;
			}
		}
	}

	bool IsValid(vector<int>& queens, int i, int j) {
		int n = queens.size();
		for (int q = 0; q < i; q++) {
			if (j == queens[q]) return false;
			if (i - j == q - queens[q]) return false;
			if (i + j == q + queens[q]) return false;
		}
		return true;
	}
};

int main(int argc, char* argv[]) {
	Solution3 solution;


	

	int n = 1;
	cout << "n = " << n << " ; possibilities = " << solution.totalNQueens(n) << endl;
	
	++n;
	cout << "n = " << n << " ; possibilities = " << solution.totalNQueens(n) << endl;

	++n;
	cout << "n = " << n << " ; possibilities = " << solution.totalNQueens(n) << endl;

	++n;
	cout << "n = " << n << " ; possibilities = " << solution.totalNQueens(n) << endl;

	++n;
	cout << "n = " << n << " ; possibilities = " << solution.totalNQueens(n) << endl;

	++n;
	cout << "n = " << n << " ; possibilities = " << solution.totalNQueens(n) << endl;

	++n;
	cout << "n = " << n << " ; possibilities = " << solution.totalNQueens(n) << endl;

	cin.get();
	return 0;
}