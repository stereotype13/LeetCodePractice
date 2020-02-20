/*
You have N gardens, labelled 1 to N.  In each garden, you want to plant one of 4 types of flowers.

paths[i] = [x, y] describes the existence of a bidirectional path from garden x to garden y.

Also, there is no garden that has more than 3 paths coming into or leaving it.

Your task is to choose a flower type for each garden such that, for any two gardens connected by a path,
they have different types of flowers.

Return any such a choice as an array answer, where answer[i] is the type of flower planted in the (i+1)-th garden.  
The flower types are denoted 1, 2, 3, or 4.  It is guaranteed an answer exists.



Example 1:

Input: N = 3, paths = [[1,2],[2,3],[3,1]]
Output: [1,2,3]

Example 2:

Input: N = 4, paths = [[1,2],[3,4]]
Output: [1,2,1,2]

Example 3:

Input: N = 4, paths = [[1,2],[2,3],[3,4],[4,1],[1,3],[2,4]]
Output: [1,2,3,4]



Note:

	1 <= N <= 10000
	0 <= paths.size <= 20000
	No garden has 4 or more paths coming into or leaving it.
	It is guaranteed an answer exists.


*/
#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>

using namespace std;

class Solution {
public:
	vector<int> gardenNoAdj(int N, vector<vector<int>>& paths) {
		vector<vector<int>> connections(N);

		for (int i = 0; i < (int)paths.size(); ++i) {
			connections[paths[i][0] - 1].push_back(paths[i][1] - 1);
			connections[paths[i][1] - 1].push_back(paths[i][0] - 1);
		}

		vector<int> result(N, 0);

		for (int i = 0; i < N; ++i) {
			vector<int> colors(5, 0);

			for (int j = 0; j < (int)connections[i].size(); ++j) {
				int pointedTo = connections[i][j];
				int pointedToColor = result[pointedTo];
				colors[pointedToColor] = 1;
			}

			for (int k = 1; k < (int)colors.size(); ++k) {
				if (colors[k] == 0) {
					colors[k] = 1;
					result[i] = k;
					break;
				}
			}
		}
		return result;
	}

};

class Solution2 {
public:
	vector<int> gardenNoAdj(int N, vector<vector<int>>& paths) {
		vector<vector<int> > G(N);

		for (int i = 0; i < paths.size(); i++)
		{
			G[paths[i][0] - 1].push_back(paths[i][1] - 1);
			G[paths[i][1] - 1].push_back(paths[i][0] - 1);
		}

		//int* col = new int[N]();
		vector<int> col(N, 0);
		for (int i = 0; i < N; i++)
		{
			int c[] = { 0, 0, 0, 0, 0 };

			
			for (int j = 0; j < G[i].size(); j++) {
				int G_ij = G[i][j];
				int temp = col[G_ij];
				c[col[G[i][j]]] = 1;
			}
				
			int color = 0;
			for (int i = 1; i < 5; i++)
				if (c[i] == 0)
				{
					color = i;
					break;
				}
			col[i] = color;
		}
		vector<int> ans;
		for (int i = 0; i < N; i++)
			ans.push_back(col[i]);
		return ans;
	}
};

int main(int argc, const char* argv[]) {
	Solution solution;

	vector<vector<int>> input1{{1, 2}, {2, 3}, {3, 1}};
	auto result1 = solution.gardenNoAdj(3, input1);

	vector<vector<int>> input2{ {1, 2}, {3, 4} };
	auto result2 = solution.gardenNoAdj(4, input2);

	//[[1,2],[2,3],[3,4],[4,1],[1,3],[2,4]]
	vector<vector<int>> input3{{1, 2}, {2, 3}, {3, 4}, {4, 1}, {1, 3}, {2, 4}};
	auto result3 = solution.gardenNoAdj(4, input3);

	vector<vector<int>> input4{ {1, 2} };
	auto result4 = solution.gardenNoAdj(10, input4);

	cin.get();
	return 0;
}