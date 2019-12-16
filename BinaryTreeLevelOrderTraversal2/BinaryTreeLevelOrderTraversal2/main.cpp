/*/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };


 Given a binary tree, return the bottom-up level order traversal of its nodes' values. (ie, from left to right, level by level from leaf to root).

For example:
Given binary tree [3,9,20,null,null,15,7],
	3
   / \
  9  20
	/  \
   15   7
return its bottom-up level order traversal as:
[
  [15,7],
  [9,20],
  [3]
]

 */
#include <iostream>
#include "..//..//LeetCodeTree.hpp"
#include <vector>
#include "LeetCodeTest.hpp"

using namespace std;

class Solution {
	vector<vector<int>> treeArray{ {} };
	int maxLevel = 0;

	void helper(TreeNode* root, int level) {
		if (level > maxLevel)
			treeArray.push_back({});

		maxLevel = max(level, maxLevel);

		if (!root->right && !root->left) {
			treeArray[level].push_back(root->val);
			return;
		}
			
		if (root->left)
			helper(root->left, level + 1);

		if (root->right)
			helper(root->right, level + 1);

		treeArray[level].push_back(root->val);
	}

public:
	vector<vector<int>> levelOrderBottom(TreeNode* root) {
		if (!root)
			return {};

		helper(root, 0);
		std::reverse(treeArray.begin(), treeArray.end());
		return treeArray;
	}
};

void printArray(const vector<vector<int>> arrayTree) {
	cout << "[";
	for (const auto& i : arrayTree) {
		cout << "[";
		for (const auto& j : i) {  
			cout << j << '\t';
		}
		cout << "]" << endl;;
	}
	cout << "]" << endl;;
}

int main(int argc, char* argv[]) {
	Solution solution;
	auto tree1 = buildTree("[3, 9, 20, null, null, 15, 7]");
	printArray(solution.levelOrderBottom(tree1));

	Solution solution2;
	auto tree2 = buildTree("[1,2,3,4,null,null,5]");
	printArray(solution2.levelOrderBottom(tree2));

	//LeetCodeTest<Solution, string, TreeNode*> test1;
	//test1.AssertEqual((void*)Solution::levelOrderBottom, "asdf", nullptr);

	cin.get();
	return 0;
}