/*
In a list of songs, the i-th song has a duration of time[i] seconds.

Return the number of pairs of songs for which their total duration in seconds is divisible by 60.  Formally, we want 
the number of indices i < j with (time[i] + time[j]) % 60 == 0.



Example 1:

Input: [30,20,150,100,40]
Output: 3
Explanation: Three pairs have a total duration divisible by 60:
(time[0] = 30, time[2] = 150): total duration 180
(time[1] = 20, time[3] = 100): total duration 120
(time[1] = 20, time[4] = 40): total duration 60

Example 2:

Input: [60,60,60]
Output: 3
Explanation: All three pairs have a total duration of 120, which is divisible by 60.



Note:

	1 <= time.length <= 60000
	1 <= time[i] <= 500

*/
#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
	int numPairsDivisibleBy60(vector<int>& time) {
		vector<int> possibleTotalTimes;

		for (int i = 60; i < 1000; i += 60)
			possibleTotalTimes.push_back(i);

		unordered_map<int, int> numbersNeeded;

		int pairCount = 0;
		for (const auto& t : time) {
			if (numbersNeeded.find(t) != numbersNeeded.end()) {
				pairCount += numbersNeeded[t];
			}

			for (const auto& totalTime : possibleTotalTimes) {
				int timeNeeded = totalTime - t;

				if(timeNeeded > 0)
					numbersNeeded[totalTime - t]++;
			}
		}

		return pairCount;
	}
};

int main() {
	Solution solution;

	vector<int> times1{ 30,20,150,100,40 };
	cout << solution.numPairsDivisibleBy60(times1) << endl;

	vector<int> times2{ 60, 60, 60 };
	cout << solution.numPairsDivisibleBy60(times2) << endl;

	vector<int> times3{ 15,63,451,213,37,209,343,319 };
	cout << solution.numPairsDivisibleBy60(times3) << endl;

	cin.get();
	return 0;
}