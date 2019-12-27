/*

*/

// Forward declaration of guess API.
// @param num, your guess
// @return -1 if my number is lower, 1 if my number is higher, otherwise return 0
#include <iostream>

using namespace std;

int guess(int num) {
	//test code
	if (num < 5)
		return 1;

	if (num > 5)
		return -1;

	return 0;
}

class Solution {
public:
	int guessNumber(int n) {
		int low = 1, high = INT_MAX;

		int mid;
		while (low <= high) {
			mid = low + (high - low) / 2;

			if (guess(mid) == -1) {
				high = mid - 1;
				continue;
			}
			else if (guess(mid) == 1) {
				low = mid + 1;
				continue;
			}

			break;
		}
		return mid;
	}
};

int main() {

	Solution solution;

	cout << solution.guessNumber(0) << endl;
	cin.get();
}

