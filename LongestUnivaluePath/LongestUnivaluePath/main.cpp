/*
Given a binary tree, find the length of the longest path where each node in the path has the same value. This path may or may not pass through the root.

The length of path between two nodes is represented by the number of edges between them.



Example 1:

Input:

			  5
			 / \
			4   5
		   / \   \
		  1   1   5
Output: 2



Example 2:

Input:

			  1
			 / \
			4   5
		   / \   \
		  4   4   5
Output: 2



Note: The given binary tree has not more than 10000 nodes. The height of the tree is not more than 1000.
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
#include "..//..//LeetCodeTree.hpp"

using namespace std;

class Solution {
	int dfs(TreeNode* node, int parentVal, int& maxLength) {
		if (!node)
			return 0;


		int leftLength = dfs(node->left, node->val, maxLength);
		int rightLength = dfs(node->right, node->val, maxLength);

		maxLength = max(maxLength, leftLength + rightLength);
		
		if (node->val != parentVal)
			return 0;

		return max(leftLength, rightLength) + 1;
	}
public:
	int longestUnivaluePath(TreeNode* root) {
		if (!root)
			return 0;

		int maxLength = 0;
		dfs(root, root->val, maxLength);
		return maxLength;

	}
};

int main() {
	Solution solution;
	auto tree1 = buildTree("[5, 4, 5, 1, 1, 5]");
	cout << solution.longestUnivaluePath(tree1) << endl;

	cin.get();
	return 0;
}