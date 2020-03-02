/*
A bus has n stops numbered from 0 to n - 1 that form a circle. We know the distance between all pairs of neighboring stops 
where distance[i] is the distance between the stops number i and (i + 1) % n.

The bus goes along both directions i.e. clockwise and counterclockwise.

Return the shortest distance between the given start and destination stops.



Example 1:

Input: distance = [1,2,3,4], start = 0, destination = 1
Output: 1
Explanation: Distance between 0 and 1 is 1 or 9, minimum is 1.



Example 2:

Input: distance = [1,2,3,4], start = 0, destination = 2
Output: 3
Explanation: Distance between 0 and 2 is 3 or 7, minimum is 3.



Example 3:

Input: distance = [1,2,3,4], start = 0, destination = 3
Output: 4
Explanation: Distance between 0 and 3 is 6 or 4, minimum is 4.



Constraints:

	1 <= n <= 10^4
	distance.length == n
	0 <= start, destination < n
	0 <= distance[i] <= 10^4

*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	int distanceBetweenBusStops(vector<int>& distance, int start, int destination) {
		int upDistance = 0, downDistance = 0;

		int count = 0;
		for (int i = start; count < (int)distance.size(); ++i) {
			if (i == (int)distance.size())
				i = 0;

			upDistance += distance[i];
			
			if (i == destination - 1)
				break;

			++count;
		}

		count = 0;
		for (int i = start - 1; count < (int)distance.size(); --i) {
			if (i == -1)
				i = (int)distance.size() - 1;

			downDistance += distance[i];

			if (i == destination)
				break;

			++count;
		}

		return min(upDistance, downDistance);
	}
};

int main() {
	Solution solution;

	vector<int> distances1{ 1, 2, 3, 4 };
	cout << solution.distanceBetweenBusStops(distances1, 0, 2) << endl;
	cout << solution.distanceBetweenBusStops(distances1, 0, 3) << endl;

	cin.get();
	return 0;
}