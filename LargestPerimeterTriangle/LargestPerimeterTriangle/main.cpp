/*
Given an array A of positive lengths, return the largest perimeter of a triangle with non-zero area, formed from 3 of these lengths.

If it is impossible to form any triangle of non-zero area, return 0.



Example 1:

Input: [2,1,2]
Output: 5
Example 2:

Input: [1,2,1]
Output: 0
Example 3:

Input: [3,2,3,4]
Output: 10
Example 4:

Input: [3,6,2,3]
Output: 8


Note:

3 <= A.length <= 10000
1 <= A[i] <= 10^6
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
	bool sidesCanFormTriangle(int a, int b, int c) {
		return b + c > a; 
	}
public:
	int largestPerimeter(vector<int>& A) {

		size_t length = A.size();

		sort(A.begin(), A.end(), [](const auto& x, const auto& y) {
			return x > y;
		});

		for (int i = 0; i < length - 2; ++i) {
			int a = A[i], b = A[i + 1], c = A[i + 2];
			if (sidesCanFormTriangle(a, b, c))
				return a + b + c;
		}

		return 0;
			
	}
};

int main() {
	Solution solution;

	vector<int> vec1{ 2, 1, 2 };
	cout << solution.largestPerimeter(vec1) << endl; //5

	vector<int> vec2{ 1, 2, 1 };
	cout << solution.largestPerimeter(vec2) << endl; //0

	vector<int> vec3{ 3, 2, 3, 4 };
	cout << solution.largestPerimeter(vec3) << endl; //10

	vector<int> vec4{ 3, 6, 2, 3 };
	cout << solution.largestPerimeter(vec4) << endl; //8

	vector<int> vec5{ 26,46,88,38,22,2,31,11,36,18,123 };
	cout << solution.largestPerimeter(vec5) << endl;

	cin.get();
	return 0;
}