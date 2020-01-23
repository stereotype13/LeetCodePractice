/*
Alice and Bob have candy bars of different sizes: A[i] is the size of the i-th bar of candy that Alice has, 
and B[j] is the size of the j-th bar of candy that Bob has.

Since they are friends, they would like to exchange one candy bar each so that after the exchange, they both 
have the same total amount of candy.  (The total amount of candy a person has is the sum of the sizes of candy bars they have.)

Return an integer array ans where ans[0] is the size of the candy bar that Alice must exchange, and ans[1] 
is the size of the candy bar that Bob must exchange.

If there are multiple answers, you may return any one of them.  It is guaranteed an answer exists.



Example 1:

Input: A = [1,1], B = [2,2]
Output: [1,2]
Example 2:

Input: A = [1,2], B = [2,3]
Output: [1,2]
Example 3:

Input: A = [2], B = [1,3]
Output: [2,3]
Example 4:

Input: A = [1,2,5], B = [2,4]
Output: [5,4]


Note:

1 <= A.length <= 10000
1 <= B.length <= 10000
1 <= A[i] <= 100000
1 <= B[i] <= 100000
It is guaranteed that Alice and Bob have different total amounts of candy.
It is guaranteed there exists an answer.
*/
#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>
#include <numeric>

using namespace std;

class Solution {
public:
	vector<int> fairCandySwap(vector<int>& A, vector<int>& B) {

		int totalA = 0, totalB = 0;
		unordered_set<int> setA, setB;

		for (const auto& i : A) {
			totalA += i;
			setA.emplace(i);
		}

		for (const auto& i : B) {
			totalB += i;
			setB.emplace(i);
		}

		int minTotal = min(totalA, totalB);
		int maxTotal = max(totalA, totalB);

		int average = minTotal + (maxTotal - minTotal) / 2;

		int deltaA = average - totalA;
		int deltaB = average - totalB;

		vector<int> result;
		for (const auto& i : A) {
		
			if (setB.find(i + deltaA) != setB.end())
				return { i, i + deltaA };
		

		}

		for (const auto& i : B) {

			if (setA.find(i + deltaB) != setA.end())
				return { i + deltaB, i };


		}

		return {};

	}
};

class Solution2 {
public:
	vector<int> fairCandySwap(vector<int>& A, vector<int>& B) {
		int sumA = accumulate(A.begin(), A.end(), 0);
		int sumB = accumulate(B.begin(), B.end(), 0);
		int diff = (sumA - sumB) / 2;

		unordered_set<int> setB(B.begin(), B.end());
		for (int i = 0; i < A.size(); i++) {
			int target = A[i] - diff;
			if (setB.find(target) != setB.end()) {
				return { A[i], target };
			}
		}

		return {};  // dummy
	}

};

int main() {
	Solution2 solution;

	vector<int> A1{ 1, 1 }, B1{ 2, 2 };
	auto result1 = solution.fairCandySwap(A1, B1);

	vector<int> A2{ 1, 2 }, B2{ 2, 3 };
	auto result2 = solution.fairCandySwap(A2, B2);

	vector<int> A3{ 2 }, B3{ 1, 3 };
	auto result3 = solution.fairCandySwap(A3, B3);

	cin.get();
	return 0;
}