/*
A binary tree is univalued if every node in the tree has the same value.

Return true if and only if the given tree is univalued.



Example 1:


Input: [1,1,1,1,1,null,1]
Output: true
Example 2:


Input: [2,2,2,5,2]
Output: false


Note:

The number of nodes in the given tree will be in the range [1, 100].
Each node's value will be an integer in the range [0, 99].
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
	bool helper(TreeNode* node, int value) {
		if (!node)
			return true;

		if (node->val != value)
			return false;

		return helper(node->left, value) && helper(node->right, value);

	}
public:
	bool isUnivalTree(TreeNode* root) {
		if (!root)
			return true;

		return helper(root, root->val);
	}
};

int main(int argc, const char* argv[]) {
	Solution solution;

	auto tree1 = buildTree("[1,1,1,1,1,null,1]");
	cout << boolalpha << solution.isUnivalTree(tree1) << endl;

	auto tree2 = buildTree("[2,2,2,5,2]");
	cout << boolalpha << solution.isUnivalTree(tree2) << endl;

	cin.get();
	return 0;
}