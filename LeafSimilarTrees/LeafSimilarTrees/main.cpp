/*
Consider all the leaves of a binary tree.  From left to right order, the values of those leaves form a leaf value sequence.



For example, in the given tree above, the leaf value sequence is (6, 7, 4, 9, 8).

Two binary trees are considered leaf-similar if their leaf value sequence is the same.

Return true if and only if the two given trees with head nodes root1 and root2 are leaf-similar.



Note:

Both of the given trees will have between 1 and 100 nodes.
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
	void helper(TreeNode* node, vector<int>& sequence) {
		if (!node)
			return;

		if (node->left == nullptr && node->right == nullptr) {
			sequence.push_back(node->val);
			return;
		}
	
		helper(node->left, sequence);
		helper(node->right, sequence);

	}
public:
	bool leafSimilar(TreeNode* root1, TreeNode* root2) {
		vector<int> sequence1, sequence2;
		helper(root1, sequence1);
		helper(root2, sequence2);

		return sequence1 == sequence2;
	}
};

int main(int argc, const char* argv[]) {



	cin.get();
	return 0;
}