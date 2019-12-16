/*
Given a binary tree, return all root-to-leaf paths.

Note: A leaf is a node with no children.

Example:

Input:

   1
 /   \
2     3
 \
  5

Output: ["1->2->5", "1->3"]

Explanation: All root-to-leaf paths are: 1->2->5, 1->3
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
	vector<string> result;

	void helper(string currentString, TreeNode* root) {
		if (currentString.empty())
			currentString = to_string(root->val);
		else
			currentString += "->" + to_string(root->val);

		if (root->left == nullptr && root->right == nullptr) {
			result.push_back(currentString);
			return;
		}

		if(root->left)
			helper(currentString, root->left);

		if(root->right)
			helper(currentString, root->right);

	}
public:
	vector<string> binaryTreePaths(TreeNode* root) {
		if (!root)
			return {};
		
		result.clear();
		helper(string{}, root);

		return result;
	}
};

int main(int argc, char* argv[]) {
	Solution solution;
	auto tree1 = buildTree("[1, 2, 3, null, 5]");

	vector<string> result = solution.binaryTreePaths(tree1);

	for (const auto& s : result)
		cout << s << endl;

	cin.get();

	return 0;
}