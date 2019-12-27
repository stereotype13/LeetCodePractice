/*
The Hamming distance between two integers is the number of positions at which the corresponding bits are different.

Given two integers x and y, calculate the Hamming distance.

Note:
0 ≤ x, y < 231.

Example:

Input: x = 1, y = 4

Output: 2

Explanation:
1   (0 0 0 1)
4   (0 1 0 0)
	   ↑   ↑

The above arrows point to positions where the corresponding bits are different.
*/
#include <iostream>

using namespace std;

class Solution {
public:
	int hammingDistance(int x, int y) {
		int resultant = x ^ y;

		int differenceCount = 0;
		for (int i = 0; i < 32; ++i) {
			if (resultant & (1 << i))
				++differenceCount;
		}

		return differenceCount;
	}
};

int main(int argc, const char* argv[]) {
	Solution solution;

	cout << solution.hammingDistance(1, 4) << endl;

	cin.get();
	return 0;
}