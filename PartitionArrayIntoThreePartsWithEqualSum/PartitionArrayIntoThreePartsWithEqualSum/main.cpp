/*
Given an array A of integers, return true if and only if we can partition the array into three non-empty parts with equal sums.

Formally, we can partition the array if we can find indexes 
i+1 < j with (A[0] + A[1] + ... + A[i] == A[i+1] + A[i+2] + ... + A[j-1] == A[j] + A[j-1] + ... + A[A.length - 1])



Example 1:

Input: [0,2,1,-6,6,-7,9,1,2,0,1]
Output: true
Explanation: 0 + 2 + 1 = -6 + 6 - 7 + 9 + 1 = 2 + 0 + 1

Example 2:

Input: [0,2,1,-6,6,7,9,-1,2,0,1]
Output: false

Example 3:

Input: [3,3,6,5,-2,2,5,1,-9,4]
Output: true
Explanation: 3 + 3 = 6 = 5 - 2 + 2 + 5 + 1 - 9 + 4



Note:

	3 <= A.length <= 50000
	-10000 <= A[i] <= 10000

*/
#include <iostream>
#include <vector>
#include <numeric>
#include <unordered_set>
#include <unordered_map>

using namespace std;

/*works for when we are allowed to choose out of order. much more complicated*/
class Solution {
public:
	bool canThreePartsEqualSum(vector<int>& A) {
	
		int sum = accumulate(A.begin(), A.end(), 0);

		if (sum % 3 != 0)
			return false;

		int need = sum / 3;

		unordered_set<int> indicesUsed;
		unordered_map<int, int> numbersNeeded;

		int numberOfGroups = 0;
		for (int i = 0; i < (int)A.size(); ++i) {

			if (numberOfGroups == 2) {
				int lastGroupSum = 0;
				for (int j = 0; j < (int)A.size(); ++j) {
					if (indicesUsed.find(j) != indicesUsed.end())
						continue;

					lastGroupSum += A[j];
				}
				if (lastGroupSum == need)
					return true;

				return false;
			}

			auto& number = A[i];

			if (numbersNeeded.find(number) != numbersNeeded.end()) {
				
				indicesUsed.emplace(i);
				indicesUsed.emplace(numbersNeeded[number]);
				numbersNeeded.erase(number);
				++numberOfGroups;
				continue;
			}

			numbersNeeded[need - number] = i;
				
		}
		return false;
	}
};

class Solution2 {
public:
	bool canThreePartsEqualSum(vector<int>& A) {
		int sum = accumulate(A.begin(), A.end(), 0);

		if (sum % 3 != 0)
			return false;

		int need = sum / 3;

		int partitionSum = 0, partitionCount = 0;
		for (int i = 0; i < (int)A.size(); ++i) {
			const auto& number = A[i];
			if (partitionSum == need) {
				++partitionCount;

				if (partitionCount == 2 && accumulate(A.begin() + i, A.end(), 0) == need) {
					return true;

					return false;
				}

				partitionSum = 0;
			}

			partitionSum += number;
		}

		return false;

	}
};

int main() {
	Solution2 solution;

	vector<int> input1{ 0, 2, 1, -6, 6, -7, 9, 1, 2, 0, 1 };
	cout << boolalpha << solution.canThreePartsEqualSum(input1) << endl;

	vector<int> input2{ 0, 2, 1, -6, 6, 7, 9, -1, 2, 0, 1 };
	cout << boolalpha << solution.canThreePartsEqualSum(input2) << endl;

	vector<int> input3{ 12, -4, 16, -5, 9, -3, 3, 8, 0 };
	cout << boolalpha << solution.canThreePartsEqualSum(input3) << endl;

	cin.get();
	return 0;
}