/*
he string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: (you may want to display this pattern in a fixed font for better legibility)

P   A   H   N
A P L S I I G
Y   I   R
And then read line by line: "PAHNAPLSIIGYIR"

Write the code that will take a string and make this conversion given a number of rows:

string convert(string s, int numRows);
Example 1:

Input: s = "PAYPALISHIRING", numRows = 3
Output: "PAHNAPLSIIGYIR"
Example 2:

Input: s = "PAYPALISHIRING", numRows = 4
Output: "PINALSIGYAHRPI"
Explanation:

P     I    N
A   L S  I G
Y A   H R
P     I
*/
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution {
public:
	string convert(string s, int numRows) {
		if (numRows == 1)
			return s;

		numRows = min(numRows, (int)s.size());
		vector<vector<int>> rowIndices;

		for (int i = 0; i < numRows; ++i) {
			rowIndices.push_back({});
		}

		int rowIndex = 0;
		int rowIncrement = 1;
		for (unsigned int i = 0; i < s.size(); ++i) {
			if (rowIndex == 0) 
				rowIncrement = 1;
			else if (rowIndex == numRows - 1) 
				rowIncrement = -1;

			rowIndices[rowIndex].push_back(i);

			rowIndex += rowIncrement;
		}

		string result;

		for (int i = 0; i < numRows; ++i) {
			for (unsigned j = 0; j < rowIndices[i].size(); ++j) {
				result.push_back(s.at(rowIndices[i][j]));
			}
		}

		return result;
		
	}
};

int main() {
	string s = "PAYPALISHIRING";
	Solution solution;
	cout << solution.convert(s, 4) << endl;
	cin.get();
}