/*
In a binary tree, the root node is at depth 0, and children of each depth k node are at depth k+1.

Two nodes of a binary tree are cousins if they have the same depth, but have different parents.

We are given the root of a binary tree with unique values, and the values x and y of two different nodes in the tree.

Return true if and only if the nodes corresponding to the values x and y are cousins.



Example 1:


Input: root = [1,2,3,4], x = 4, y = 3
Output: false
Example 2:


Input: root = [1,2,3,null,4,null,5], x = 5, y = 4
Output: true
Example 3:



Input: root = [1,2,3,null,4], x = 2, y = 3
Output: false


Note:

The number of nodes in the tree will be between 2 and 100.
Each node has a unique integer value from 1 to 100.
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
#include <queue>
#include "..//..//LeetCodeTree.hpp"

using namespace std;

class Solution {
	struct Node {
		TreeNode* me = nullptr;
		TreeNode* parent = nullptr;
		int level = -1;
	};
public:
	bool isCousins(TreeNode* root, int x, int y) {
		if (!root)
			return false;

		queue<Node> searchQueue;

		searchQueue.push({ root, nullptr, 0 });

		Node firstNodeFound{nullptr, nullptr, -1};

		while (!searchQueue.empty()) {
			auto node = searchQueue.front();
			searchQueue.pop();

			if (node.me->val == x || node.me->val == y) {
				if (!firstNodeFound.me) {
					firstNodeFound = { node.me, node.parent, node.level};
					continue;
				}

				if (firstNodeFound.level == node.level && firstNodeFound.parent != node.parent)
					return true;

				return false;
			}
			
			if (node.me->left)
				searchQueue.push({node.me->left, node.me, node.level + 1});

			if (node.me->right)
				searchQueue.push({ node.me->right, node.me, node.level + 1 });
		}

		return false;

	}
};

int main() {
	Solution solution;

	auto tree1 = buildTree("[1,2,3,4]");
	cout << boolalpha << solution.isCousins(tree1, 4, 3) << endl; //false

	auto tree2 = buildTree("[1,2,3,null,4,null,5]");
	cout << boolalpha << solution.isCousins(tree2, 5, 4) << endl; //true

	auto tree3 = buildTree("[1,2,3,null,4]");
	cout << boolalpha << solution.isCousins(tree3, 2, 3) << endl; //false

	/*
	[1,2,3,null,4,null,5]
	5
	4
	expect true
	*/

	auto tree4 = buildTree("[1,2,3,null,4,null,5]");
	cout << boolalpha << solution.isCousins(tree4, 5, 4) << endl; //true


	cin.get();
	return 0;
}