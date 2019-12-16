/*
Given a binary tree, find its minimum depth.

The minimum depth is the number of nodes along the shortest path from the root node down to the nearest leaf node.

Note: A leaf is a node with no children.

Example:

Given binary tree [3,9,20,null,null,15,7],

	3
   / \
  9  20
	/  \
   15   7
return its minimum depth = 2.
*/
#include<iostream>
#include <queue>
#include "..//..//LeetCodeTree.hpp"

using namespace std;

class Solution {
public:
	int minDepth(TreeNode* root) {
		if (!root)
			return 0;

		queue<pair<TreeNode*, int>> nodesToCheck;
		nodesToCheck.push({root, 1});

		while (!nodesToCheck.empty()) {
			auto nodeLevelPair = nodesToCheck.front();
			auto node = nodeLevelPair.first;
			auto level = nodeLevelPair.second;

			nodesToCheck.pop();

			if (!node->left && !node->right)
				return level;

			if (node->left)
				nodesToCheck.push({node->left, level + 1});

			if (node->right)
				nodesToCheck.push({ node->right, level + 1 });
		}
		return 0;
	}
};

int main(int argc, char* argv[]) {
	Solution solution;

	auto tree1 = buildTree("[3,9,20,null,null,15,7]");
	cout << solution.minDepth(tree1) << endl;

	auto tree2 = buildTree("[2]");
	cout << solution.minDepth(tree2) << endl;


	delete tree1;
	delete tree2;
	cin.get();
	return 0;
}