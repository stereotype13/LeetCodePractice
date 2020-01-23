/*
Given a non-empty binary tree, return the average value of the nodes on each level in the form of an array.
Example 1:
Input:
	3
   / \
  9  20
	/  \
   15   7
Output: [3, 14.5, 11]
Explanation:
The average value of nodes on level 0 is 3,  on level 1 is 14.5, and on level 2 is 11. Hence return [3, 14.5, 11].
Note:
The range of node's value is in the range of 32-bit signed integer.
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
#include <iostream>
#include <vector>
#include "..//..//LeetCodeTree.hpp"

using namespace std;

class Solution {
	void helper(TreeNode* node, int level, vector<vector<int>>& vec) {
		if (!node)
			return;

		if (level == vec.size())
			vec.push_back({});

		vec[level].push_back(node->val);
		helper(node->left, level + 1, vec);
		helper(node->right, level + 1, vec);
	}
public:
	vector<double> averageOfLevels(TreeNode* root) {
		vector<vector<int>> vec{ {} };
		helper(root, 0, vec);

		vector<double> result;
		for (const auto& row : vec) {
			long long int sum = 0;
			double rowSize = (double)row.size();
			for (const auto& num : row)
				sum += num;

			result.push_back(sum / rowSize);
		}
		return result;
	}
};

int main(int argc, const char* argv[]) {
	Solution solution;

	auto tree1 = buildTree("[3, 9, 20, null, null, 15, 7]");
	auto result1 = solution.averageOfLevels(tree1);

	cin.get();
	return 0;
}