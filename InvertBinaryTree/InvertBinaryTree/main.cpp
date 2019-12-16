/*
Invert a binary tree.

Example:

Input:

	 4
   /   \
  2     7
 / \   / \
1   3 6   9
Output:

	 4
   /   \
  7     2
 / \   / \
9   6 3   1
*/
#include <iostream>
#include "..//..//LeetCodeTree.hpp"

using namespace std;

class Solution {
public:
	TreeNode* invertTree(TreeNode* root) {
		if (!root)
			return nullptr;

		swap(root->left, root->right);
		invertTree(root->left);
		invertTree(root->right);

		return root;
	}
};

int main(int argc, char* argv[]) {
	TreeNode* tree1 = buildTree("[4, 2, 7, 1, 3, 6, 9]");

	Solution solution;
	tree1 = solution.invertTree(tree1);

	cin.get();
	return 0;
}