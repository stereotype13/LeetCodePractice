/*
You have a total of n coins that you want to form in a staircase shape, where every k-th row must have exactly k coins.

Given n, find the total number of full staircase rows that can be formed.

n is a non-negative integer and fits within the range of a 32-bit signed integer.

Example 1:

n = 5

The coins can form the following rows:
¤
¤ ¤
¤ ¤

Because the 3rd row is incomplete, we return 2.
Example 2:

n = 8

The coins can form the following rows:
¤
¤ ¤
¤ ¤ ¤
¤ ¤

Because the 4th row is incomplete, we return 3.
*/
#include <iostream>

using namespace std;

class Solution {
public:
	int arrangeCoins(int n) {
		if (n < 2)
			return n;

		long long int sum = 0;

		int steps = 0;
		while (sum < n) {
			++steps;
			sum += steps;
			
		}
		if (n == sum)
			return steps;

		return steps - 1;
	}
};

int main(int argc, char* argv[]) {
	Solution solution;

	cout << solution.arrangeCoins(0) << endl;
	cout << solution.arrangeCoins(1) << endl;
	cout << solution.arrangeCoins(2) << endl;
	cout << solution.arrangeCoins(3) << endl;
	cout << solution.arrangeCoins(4) << endl;
	cout << solution.arrangeCoins(5) << endl;
	cout << solution.arrangeCoins(8) << endl;

	cin.get();
	return 0;
}