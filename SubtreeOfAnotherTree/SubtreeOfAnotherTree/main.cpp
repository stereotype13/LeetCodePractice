/*
Given two non-empty binary trees s and t, check whether tree t has exactly the same structure and node values with a subtree of s. A subtree of s is a tree consists of a node in s and all of this node's descendants. The tree s could also be considered as a subtree of itself.

Example 1:
Given tree s:

	 3
	/ \
   4   5
  / \
 1   2
Given tree t:
   4
  / \
 1   2
Return true, because t has the same structure and node values with a subtree of s.
Example 2:
Given tree s:

	 3
	/ \
   4   5
  / \
 1   2
	/
   0
Given tree t:
   4
  / \
 1   2
Return false.
*/
#include <iostream>
#include "..//..//LeetCodeTree.hpp"

using namespace std;
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {

	bool subtreesAreEqual(TreeNode* sNode, TreeNode* t) {
		if (!sNode && !t)
			return true;
		
		if ((!sNode && t) || (sNode && !t))
			return false;

		return sNode->val == t->val && subtreesAreEqual(sNode->left, t->left) && subtreesAreEqual(sNode->right, t->right);
	}

	bool helper(TreeNode* s, TreeNode* t, int searchValue) {
		if (s->val == searchValue && subtreesAreEqual(s, t))
			return true;

		if (s->left && helper(s->left, t, searchValue))
			return true;

		if (s->right && helper(s->right, t, searchValue))
			return true;

		return false;
	}

public:
	bool isSubtree(TreeNode* s, TreeNode* t) {
		int searchValue = t->val;
		return helper(s, t, searchValue);
	}
};

int main(int argc, const char* argv[]) {
	Solution solution;
	auto s1 = buildTree("[3, 4, 5, 1, 2, null, null]");
	auto t1 = buildTree("[4, 1, 2]");
	cout << boolalpha << solution.isSubtree(s1, t1) << endl;

	auto s2 = buildTree("[3, 4, 5, 1, 2, null, null, null, null, 0, null]");
	auto t2 = t1;
	cout << boolalpha << solution.isSubtree(s2, t2) << endl;

	cin.get();
	return 0;
}