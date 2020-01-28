/*
Given an array of integers A sorted in non-decreasing order, return an array of the squares of each number, also in sorted non-decreasing order.



Example 1:

Input: [-4,-1,0,3,10]
Output: [0,1,9,16,100]
Example 2:

Input: [-7,-3,2,3,11]
Output: [4,9,9,49,121]


Note:

1 <= A.length <= 10000
-10000 <= A[i] <= 10000
A is sorted in non-decreasing order.
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	vector<int> sortedSquares(vector<int>& A) {
		vector<int> result(A.size(), 0);

		for (int i = 0; i < (int)A.size(); ++i)
			result[i] = A[i] * A[i];

		sort(result.begin(), result.end());

		return result;
	}
};

class Solution2 {
public:
	vector<int> sortedSquares(vector<int>& A) {
		vector<int> result(A.size(), 0);

		int crossPoint = 0;
		while (crossPoint < (int)A.size()) {
			if (A[crossPoint] >= 0)
				break;

			++crossPoint;
		}

		int upperIndex = min(crossPoint, (int)A.size() - 1);
		int lowerIndex = upperIndex - 1;

		for (int resultIndex = 0; resultIndex < (int)A.size(); ++resultIndex) {
			if (lowerIndex > -1 && upperIndex < (int)A.size()) {
				int a = A[upperIndex], b = A[lowerIndex];
				if (abs(a) < abs(b)) {
					result[resultIndex] = a * a;
					++upperIndex;
				}
				else {
					result[resultIndex] = b * b;
					--lowerIndex;
				}
			}
			else if (lowerIndex == -1) {
				int a = A[upperIndex];
				result[resultIndex] = a * a;
				++upperIndex;
			}
			else {
				int b = A[lowerIndex];
				result[resultIndex] = b * b;
				--lowerIndex;
			}

		}
		return result;
	}

};

class Solution3 {
public:
	vector<int> sortedSquares(vector<int>& A) {
		vector<int> result(A.size(), 0);

		int frontIndex = 0, backIndex = (int)A.size() - 1;

		int resultIndex = (int)A.size() - 1;
		while (frontIndex <= backIndex) {
			int front = A[frontIndex], back = A[backIndex];
			if (abs(front) > abs(back)) {
				result[resultIndex] = front * front;
				++frontIndex;
			}
			else {
				result[resultIndex] = back * back;
				--backIndex;
			}
			--resultIndex;
		}
		return result;
	}
};

int main() {
	Solution3 solution;

	vector<int> vec1{ -4,-1,0,3,10 };
	auto result1 = solution.sortedSquares(vec1);

	vector<int> vec2{ 0, 1, 2, 3, 4, 5 };
	auto result2 = solution.sortedSquares(vec2);

	vector<int> vec3{ -6, -5, -4, -3, -2, -1 };
	auto result3 = solution.sortedSquares(vec3);

	cin.get();
	return 0;
}