/*
Given a binary tree, you need to compute the length of the diameter of the tree. The diameter of a binary tree is the length of the longest path between any two nodes in a tree. This path may or may not pass through the root.

Example:
Given a binary tree
		  1
		 / \
		2   3
	   / \
	  4   5
Return 3, which is the length of the path [4,2,1,3] or [5,2,1,3].

Note: The length of path between two nodes is represented by the number of edges between them.
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
	int diameter;
	int helper(TreeNode* root) {
		if (!root)
			return 0;

		int leftPathLength = helper(root->left);
		int rightPathLength = helper(root->right);

		diameter = max(diameter, leftPathLength + rightPathLength);
		return max(leftPathLength + 1, rightPathLength + 1);
	}
public:
	int diameterOfBinaryTree(TreeNode* root) {
		diameter = 0;
		helper(root);

		return diameter;
	}
};

int main(int argc, const char* argv[]) {
	Solution solution;
	auto tree1 = buildTree("[1, 2, 3, 4, 5, null, null]");
	cout << solution.diameterOfBinaryTree(tree1) << endl;

	cin.get();
	return 0;
}