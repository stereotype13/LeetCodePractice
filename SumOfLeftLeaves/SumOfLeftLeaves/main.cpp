/*
Find the sum of all left leaves in a given binary tree.

Example:

	3
   / \
  9  20
	/  \
   15   7

There are two left leaves in the binary tree, with values 9 and 15 respectively. Return 24.
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
	bool isLeaf(TreeNode* node) {
		if (!node)
			return false;

		return !node->left && !node->right;
	}	

	void helper(TreeNode* root, int& sum) {
		bool leftIsLeaf = isLeaf(root->left);

		if (leftIsLeaf) 
			sum += root->left->val;

		if (root->left && !leftIsLeaf)
			helper(root->left, sum);

		if (root->right)
			helper(root->right, sum);
			
	}
public:
	int sumOfLeftLeaves(TreeNode* root) {
		if (!root)
			return 0;

		if (!root->left && !root->right)
			return 0;

		int sum = 0;
		helper(root, sum);
		return sum;
	}
};

int main() {
	Solution solution;
	auto root1 = buildTree("[3, 9, 20, null, null, 15, 7]");
	cout << solution.sumOfLeftLeaves(root1) << endl;

	auto root2 = buildTree("[1,2,3,4,5]");
	cout << solution.sumOfLeftLeaves(root2) << endl;

	cin.get();
}