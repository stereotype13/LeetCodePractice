/*
Given two positive integers x and y, an integer is powerful if it is equal to x^i + y^j for some integers i >= 0 and j >= 0.

Return a list of all powerful integers that have value less than or equal to bound.

You may return the answer in any order.  In your answer, each value should occur at most once.



Example 1:

Input: x = 2, y = 3, bound = 10
Output: [2,3,4,5,7,9,10]
Explanation:
2 = 2^0 + 3^0
3 = 2^1 + 3^0
4 = 2^0 + 3^1
5 = 2^1 + 3^1
7 = 2^2 + 3^1
9 = 2^3 + 3^0
10 = 2^0 + 3^2
Example 2:

Input: x = 3, y = 5, bound = 15
Output: [2,4,6,8,10,14]


Note:

1 <= x <= 100
1 <= y <= 100
0 <= bound <= 10^6
*/
#include <iostream>
#include <vector>
#include <math.h>
#include <unordered_set>
#include <algorithm>

using namespace std;

class Solution {
public:
	vector<int> powerfulIntegers(int x, int y, int bound) {
		if (bound == 0 || (x == 0 && y == 0))
			return {};

		if ((x > y && y != 0 && y != 1) || x == 1)
			swap(x, y);

		int largestExponent = max(1, (int)ceil(log(bound) / log(x)));

		unordered_set<unsigned long long> seenNumbers;
		vector<int> result;

		for (int i = 0; i < largestExponent; ++i) {
			for (int j = 0; j < largestExponent; ++j) {
				unsigned long long temp = pow(x, i) + pow(y, j);
				if (temp <= (unsigned long long)bound && seenNumbers.find(temp) == seenNumbers.end())
				{
					result.push_back((int)temp);
					seenNumbers.emplace(temp);
				}
			}
		}

		
		return result;
		
	}
};

int main(int argc, const char* argv[]) {
	Solution solution;

	auto result1 = solution.powerfulIntegers(2, 3, 10);
	auto result2 = solution.powerfulIntegers(1, 1, 2);
	auto result3 = solution.powerfulIntegers(2, 4, 12); //[2,3,5,6,8,9,12]
	auto result4 = solution.powerfulIntegers(2, 1, 10); //[9,2,3,5]
	auto result5 = solution.powerfulIntegers(1, 2, 100); //[33, 2, 3, 5, 65, 9, 17]

	cin.get();
	return 0;
}