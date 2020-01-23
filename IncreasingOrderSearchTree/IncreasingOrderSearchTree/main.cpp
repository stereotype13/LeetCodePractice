/*
Given a binary search tree, rearrange the tree in in-order so that the leftmost node in the tree is now the root of the tree, 
and every node has no left child and only 1 right child.

Example 1:
Input: [5,3,6,2,4,null,8,1,null,null,null,7,9]

	   5
	  / \
	3    6
   / \    \
  2   4    8
 /        / \
1        7   9

Output: [1,null,2,null,3,null,4,null,5,null,6,null,7,null,8,null,9]

 1
  \
   2
	\
	 3
	  \
	   4
		\
		 5
		  \
		   6
			\
			 7
			  \
			   8
				\
				 9
Note:

The number of nodes in the given tree will be between 1 and 100.
Each node will have a unique integer value from 0 to 1000.
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
	TreeNode* head;
	TreeNode* tail;

	void helper(TreeNode* node) {

		if (!node->left && !head) {
			head = node;
			tail = node;
			//return;
		}

		if (!node->left && !node->right) {
			tail->right = node;
			tail = node;
			return;
		}

		if (node->left) {
			helper(node->left);
			tail->right = node;
		}
			

		tail = node;
		tail->left = nullptr;

		if (node->right)
			helper(node->right);

	}

public:
	TreeNode* increasingBST(TreeNode* root) {
		head = nullptr;
		tail = nullptr;
		if (!root)
			return nullptr;

		helper(root);

		return head;
	}
};

int main() {
	Solution solution;

	auto tree1 = buildTree("[5,3,6,2,4,null,8,1,null,null,null,7,9]");
	auto result1 = solution.increasingBST(tree1);

	auto tree2 = buildTree("[106,null,783]");
	auto result2 = solution.increasingBST(tree2);

	auto tree3 = buildTree("[256,null,519,605]");
	auto result3 = solution.increasingBST(tree3);

	//[5, 3, 6, 2, 4, null, 8, 1, null, null, null, 7, 9]

	cin.get();
	return 0;
}