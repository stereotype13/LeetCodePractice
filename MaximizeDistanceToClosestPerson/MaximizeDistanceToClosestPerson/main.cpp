/*
In a row of seats, 1 represents a person sitting in that seat, and 0 represents that the seat is empty.

There is at least one empty seat, and at least one person sitting.

Alex wants to sit in the seat such that the distance between him and the closest person to him is maximized.

Return that maximum distance to closest person.

Example 1:

Input: [1,0,0,0,1,0,1]
Output: 2
Explanation:
If Alex sits in the second open seat (seats[2]), then the closest person has distance 2.
If Alex sits in any other open seat, the closest person has distance 1.
Thus, the maximum distance to the closest person is 2.
Example 2:

Input: [1,0,0,0]
Output: 3
Explanation:
If Alex sits in the last seat, the closest person is 3 seats away.
This is the maximum distance possible, so the answer is 3.
Note:

1 <= seats.length <= 20000
seats contains only 0s or 1s, at least one 0, and at least one 1.
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	int maxDistToClosest(vector<int>& seats) {

		int minOne = INT_MAX, maxOne = 0;
		int prevOne = -1;
		int maxDistance = 0;
		for (int i = 0; i < (int)seats.size(); ++i) {
			int seat = seats[i];

			if (seat == 1) {
				minOne = min(minOne, i);
				maxOne = max(maxOne, i);

				if (prevOne == -1) {
					prevOne = i;
					continue;
				}

				int tempChosenSeat = (i - prevOne) / 2 + prevOne;
				int rightDistance = i - tempChosenSeat;
				int leftDistance = tempChosenSeat - prevOne;

				maxDistance = max(maxDistance, min(leftDistance, rightDistance));

				prevOne = i;
			}

		}

		maxDistance = max(maxDistance, minOne);
		maxDistance = max(maxDistance, (int)seats.size() - 1 - maxOne);

		return maxDistance;

	}
};

int main(int argc, const char* argv[]) {
	Solution solution;

	auto seats1 = vector<int>{ 1,0,0,0,1,0,1 };
	cout << solution.maxDistToClosest(seats1) << endl;

	auto seats2 = vector<int>{ 1, 0, 0, 0 };
	cout << solution.maxDistToClosest(seats2) << endl;

	auto seats3 = vector<int>{ 0,1 };// returns 0, but should be 1 ? !
	cout << solution.maxDistToClosest(seats3) << endl;

	cin.get();
	return 0;
}