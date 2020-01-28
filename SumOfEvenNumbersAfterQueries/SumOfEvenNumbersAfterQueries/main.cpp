/*
We have an array A of integers, and an array queries of queries.

For the i-th query val = queries[i][0], index = queries[i][1], we add val to A[index].  
Then, the answer to the i-th query is the sum of the even values of A.

(Here, the given index = queries[i][1] is a 0-based index, and each query permanently modifies the array A.)

Return the answer to all queries.  Your answer array should have answer[i] as the answer to the i-th query.



Example 1:

Input: A = [1,2,3,4], queries = [[1,0],[-3,1],[-4,0],[2,3]]
Output: [8,6,2,4]
Explanation:
At the beginning, the array is [1,2,3,4].
After adding 1 to A[0], the array is [2,2,3,4], and the sum of even values is 2 + 2 + 4 = 8.
After adding -3 to A[1], the array is [2,-1,3,4], and the sum of even values is 2 + 4 = 6.
After adding -4 to A[0], the array is [-2,-1,3,4], and the sum of even values is -2 + 4 = 2.
After adding 2 to A[3], the array is [-2,-1,3,6], and the sum of even values is -2 + 6 = 4.


Note:

1 <= A.length <= 10000
-10000 <= A[i] <= 10000
1 <= queries.length <= 10000
-10000 <= queries[i][0] <= 10000
0 <= queries[i][1] < A.length
*/
#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
	vector<int> sumEvenAfterQueries(vector<int>& A, vector<vector<int>>& queries) {
		vector<int> result(A.size(), 0);
		unordered_set<int> evenIndices;


		for (int i = 0; i < (int)A.size(); ++i) {
			if (A[i] % 2 == 0)
				evenIndices.emplace(i);
		}

		for (int i = 0; i < (int)queries.size(); ++i) {
			auto& query = queries[i];

			A[query[1]] += query[0];
			if (A[query[1]] % 2 == 0)
				evenIndices.emplace(query[1]);
			else
				evenIndices.erase(query[1]);

			int evenSum = 0;
			for (const auto& index : evenIndices) {
				evenSum += A[index];
					
			}
				

			result[i] = evenSum;
		}

		return result;
	}
};

class Solution2 {
public:
	vector<int> sumEvenAfterQueries(vector<int>& A, vector<vector<int>>& queries) {
		vector<int> result(A.size(), 0);

		int evenSum = 0;
		for (const auto& i : A) {
			if (i % 2 == 0)
				evenSum += i;
		}

		for (int i = 0; i < (int)queries.size(); ++i) {
			auto& query = queries[i];
			int queryValue = query[0], queryIndex = query[1];

			if (A[queryIndex] % 2 == 1) {
				
				if (abs(queryValue) % 2 == 1) {
					//odd to even
					A[queryIndex] += queryValue;
					evenSum += A[queryIndex];
				}
				else {
					//odd to odd
					A[queryIndex] += queryValue;
				}
			
			}
			else {
				if (abs(queryValue) % 2 == 1) {
					//even to odd
					evenSum -= A[queryIndex];
					A[queryIndex] += queryValue;
					
				}
				else {
					//even to even
					A[queryIndex] += queryValue;
					evenSum += queryValue;
				}
			}
				
						
			result[i] = evenSum;
		}
		return result;
	}
};

int main() {
	Solution2 solution;

	auto A1 = vector<int>{ 1, 2, 3, 4 }; auto queries1 = vector<vector<int>>{{1, 0}, {-3, 1}, {-4, 0}, {2, 3}};
	auto result1 = solution.sumEvenAfterQueries(A1, queries1); //[8,6,2,4]

	auto A2 = vector<int>{ 4 }; auto queries2 = vector<vector<int>>{ {5, 0} };
	auto result2 = solution.sumEvenAfterQueries(A2, queries2);

	cin.get();
	return 0;
}