/*
Given n points in the plane that are all pairwise distinct, a "boomerang" is a tuple of points (i, j, k) such that the distance between i and j equals the 
distance between i and k (the order of the tuple matters).

Find the number of boomerangs. You may assume that n will be at most 500 and coordinates of points are all in the range [-10000, 10000] (inclusive).

Example:

Input:
[[0,0],[1,0],[2,0]]

Output:
2

Explanation:
The two boomerangs are [[1,0],[0,0],[2,0]] and [[1,0],[2,0],[0,0]]
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <set>
#include <string>

using namespace std;

class Solution1 {
	double distance(const vector<int>& a, const vector<int>& b) {
		return (pow(a[0] - b[0], 2) + pow(a[1] - b[1], 2));
	}
public:
	int numberOfBoomerangs(vector<vector<int>>& points) {
		/*sort(points.begin(), points.end(), [](const vector<int>& a, const vector<int>& b) {
			if (a[0] < b[0]) return true;
			if (a[0] > b[0]) return false;

			if (a[1] < b[1]) return true;
			return false;
		});*/
		if (points.size() < 3)
			return 0;

		int boomerangCount = 0;
		
		for (int i = 0; i < points.size(); ++i) {
			auto center = points[i];
			for (int j = 0; j < points.size(); ++j) {
				if (i == j)
					continue;
				auto left = points[j];
				auto centerLeftDistance = distance(center, left);
				for (int k = 0; k < points.size(); ++k) {
					if (j == k)
						continue;
					auto right = points[k];
					auto centerRightDistance = distance(center, right);
					if (centerLeftDistance == centerRightDistance) {
						++boomerangCount;
						cout << "[[" + to_string(center[0]) + ", " + to_string(center[1]) + "], " +
							"[" + to_string(left[0]) + ", " + to_string(left[1]) + "], " +
							"[" + to_string(right[0]) + ", " + to_string(right[1]) + "]]" << endl;
					}
						
				}
			}
		}
		return boomerangCount;

	}
};

class Solution2 {
public:
	int numberOfBoomerangs(vector<vector<int>>& points) {
		if (points.size() < 3)
			return 0;

		int boomerangCount = 0;

		unordered_map<int, unordered_map<int, vector<int>>> pointHash;

		for (const auto& v : points) {
			pointHash[v[0]][v[1]] = v;
		}

		for (int i = 0; i < points.size(); ++i) {
			for (int j = 0; j < points.size(); ++j) {
				if (i == j)
					continue;

				auto center = points[i];
				auto leg = points[j];

				auto xDisplacement = center[0] - leg[0];
				auto yDisplacement = center[1] - leg[1];

				set<pair<int, int>> pointsToCheck;
				vector<int> temp{ -1, 1 };
				for (const auto& k : temp) {
					for (const auto& l : temp) {
						auto newX1 = center[0] + k * xDisplacement;
						auto newY1 = center[1] + l * yDisplacement;

						auto newX2 = center[0] + k * yDisplacement;
						auto newY2 = center[1] + l * xDisplacement;

						
						auto p1 = pair<int, int>{ newX1, newY1 };
						auto p2 = pair<int, int>{ newX2, newY2 };

						if (!(newX1 == leg[0] && newY1 == leg[1]))
							pointsToCheck.emplace(p1);
						
						if (!(newX2 == leg[0] && newY2 == leg[1]))
							pointsToCheck.emplace(p2);
						
					}
				}

				for (const auto& p : pointsToCheck) {
					if (pointHash.find(p.first) != pointHash.end()) {
						if (pointHash[p.first].find(p.second) != pointHash[p.first].end()) {
							++boomerangCount;
							cout << "[[" + to_string(center[0]) + ", " + to_string(center[1]) + "], " +
								"[" + to_string(leg[0]) + ", " + to_string(leg[1]) + "], " +
								"[" + to_string(p.first) + ", " + to_string(p.second) + "]]" << endl;
						}
							
					}
				}

				pointsToCheck.clear();
			}
		}

		return boomerangCount;

	}
};

class Solution3 {
public:
	int numberOfBoomerangs(vector<vector<int>>& points) {
		if (points.size() < 3)
			return 0;

		int boomerangCount = 0;
		unordered_map<long long int, int> distanceCount;

		for (const auto& a : points) {
			for (const auto& b : points) {
				if (a == b)
					continue;

				long long int d = (a[0] - b[0]) * (a[0] - b[0]) + (a[1] - b[1]) * (a[1] - b[1]);
				distanceCount[d]++;
			}

			for (const auto& p : distanceCount) {
				if (p.second > 1) {
					boomerangCount += p.second * (p.second - 1);
				}
			}
			distanceCount.clear();
		}

		
		return boomerangCount;
	}
};

int main(int argc, char* argv[]) {
	/*
	Solution2 solution;
	vector<vector<int>> input1{ {0, 0}, {1, 0}, {2, 0} };
	cout << solution.numberOfBoomerangs(input1) << endl;

	vector<vector<int>> input2{ {0,0},{1,0},{-1,0},{0,1},{0,-1} };
	cout << solution.numberOfBoomerangs(input2) << endl;

	Solution1 solution1;
	vector<vector<int>> input3{ {1, 8}, {7, 9}, {2, 0}, {2, 3}, {7, 5}, {9, 2}, {2, 8}, {9, 7}, {3, 6}, {1, 2} }; //should be 12, get 10
	cout << solution1.numberOfBoomerangs(input3) << endl;

	cout << endl << endl;

	*/
	Solution3 solution3;
	vector<vector<int>> input4{ {1, 8}, {7, 9}, {2, 0}, {2, 3}, {7, 5}, {9, 2}, {2, 8}, {9, 7}, {3, 6}, {1, 2} }; //should be 12, get 10
	cout << solution3.numberOfBoomerangs(input4) << endl;

	cin.get();

	return 0;
}