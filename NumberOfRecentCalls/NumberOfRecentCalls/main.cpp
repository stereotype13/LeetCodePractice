/*
Write a class RecentCounter to count recent requests.

It has only one method: ping(int t), where t represents some time in milliseconds.

Return the number of pings that have been made from 3000 milliseconds ago until now.

Any ping with time in [t - 3000, t] will count, including the current ping.

It is guaranteed that every call to ping uses a strictly larger value of t than before.



Example 1:

Input: inputs = ["RecentCounter","ping","ping","ping","ping"], inputs = [[],[1],[100],[3001],[3002]]
Output: [null,1,2,3,3]


Note:

Each test case will have at most 10000 calls to ping.
Each test case will call ping with strictly increasing values of t.
Each call to ping will have 1 <= t <= 10^9.
*/
#include <iostream>
#include <queue>

using namespace std;

class RecentCounter {
	queue<int> pings;
public:
	RecentCounter() {
		while (!pings.empty())
			pings.pop();
	}

	int ping(int t) {
		if (pings.empty()) {
			pings.push(t);
			return 1;
		}

		pings.push(t);
		auto& time = pings.front();
		while (t - time > 3000) {
			pings.pop();

			if (pings.empty())
				break;

			time = pings.front();
		}

		return (int)pings.size();
	}
};

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */

int main() {
	RecentCounter recentCounter;

	vector<int> pings{ 1, 100, 3001, 3002 };

	for (const auto& i : pings)
		cout << recentCounter.ping(i) << " ";

	cout << endl;


	cin.get();
	return 0;
}