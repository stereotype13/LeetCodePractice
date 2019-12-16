/*
Given a binary tree, check whether it is a mirror of itself (ie, symmetric around its center).

For example, this binary tree [1,2,2,3,4,4,3] is symmetric:

	1
   / \
  2   2
 / \ / \
3  4 4  3


But the following [1,2,2,null,3,null,3] is not:

	1
   / \
  2   2
   \   \
   3    3
*/

#include <iostream>
#include <queue>
#include <stack>
#include "..//..//LeetCodeTree.hpp"

using namespace std;

class Solution {
private:
	queue<TreeNode*> _nodesToCheck, _nodesToCheckMirror;
	vector<TreeNode*> _array, _arrayMirror;
	
public:
	bool isSymmetric(TreeNode* root) {
		if (!root)
			return true;

		_array.clear();
		_arrayMirror.clear();
		while (!_nodesToCheck.empty())
			_nodesToCheck.pop();

		while (!_nodesToCheckMirror.empty())
			_nodesToCheckMirror.pop();
		
		_nodesToCheck.push(root);
		

		while (!_nodesToCheck.empty()) {
			auto node = _nodesToCheck.front();
			_nodesToCheck.pop();

			_array.push_back(node);

			if (!node)
				continue;

			if (node->left)
				_nodesToCheck.push(node->left);
			else
				_nodesToCheck.push(nullptr);

			if (node->right)
				_nodesToCheck.push(node->right);
			else
				_nodesToCheck.push(nullptr);
		}

		_nodesToCheckMirror.push(root);
		while (!_nodesToCheckMirror.empty()) {
			auto node = _nodesToCheckMirror.front();
			_nodesToCheckMirror.pop();

			_arrayMirror.push_back(node);

			if (!node)
				continue;

			if (node->right)
				_nodesToCheckMirror.push(node->right);
			else
				_nodesToCheckMirror.push(nullptr);

			if (node->left)
				_nodesToCheckMirror.push(node->left);
			else
				_nodesToCheckMirror.push(nullptr);
		}

		for (int i = 0; i < _array.size(); ++i) {
			if (_array[i] == nullptr && _arrayMirror[i] == nullptr)
				continue;

			if (_array[i] == nullptr && _arrayMirror[i] != nullptr)
				return false;

			if (_array[i] != nullptr && _arrayMirror[i] == nullptr)
				return false;

			if (_array[i]->val != _arrayMirror[i]->val)
				return false;
		}

		return true;
	}
};

class Solution2 {
public:
	bool isSymmetricUtils(TreeNode *root1, TreeNode *root2) {
		if (!root1 && !root2) {
			return true;
		}
		if (!root1 || !root2) {
			return false;
		}
		if (root1->val != root2->val) {
			return false;
		}
		bool x = isSymmetricUtils(root1->left, root2->right);
		bool y = isSymmetricUtils(root1->right, root2->left);
		return x && y;
	}
	bool isSymmetric(TreeNode* root) {
		return isSymmetricUtils(root, root);

	}
};

class Solution3 {
	bool helper(TreeNode* left, TreeNode* right) {
		if (left == nullptr && right == nullptr)
			return true;

		if (left == nullptr || right == nullptr)
			return false;

		if (left->val != right->val)
			return false;

		bool x = helper(left->left, right->right);
		bool y = helper(left->right, right->left);

		return x && y;
	}
public:
	bool isSymmetric(TreeNode* root) {
		return helper(root, root);

	}

};

int main(int argc, char* argv[]) {
	Solution solution;
	Solution2 solution2;
	Solution3 solution3;

	auto tree1 = buildTree("[1,2,2,3,4,4,3]");
	cout << solution.isSymmetric(tree1) << endl;
	cout << solution2.isSymmetric(tree1) << endl; 
	cout << solution3.isSymmetric(tree1) << endl;

	auto tree2 = buildTree("[1,2,2,null,3,null,3]");
	cout << solution.isSymmetric(tree2) << endl;
	
	auto tree3 = buildTree("[1, 2, 2, null, 3, null, 3]");
	cout << solution.isSymmetric(tree3) << endl;

	auto tree4 = buildTree("[1,2,2,2,null,2]");
	cout << solution.isSymmetric(tree4) << endl;

	auto tree5 = buildTree("[1,2,2,3,null,null,3]");
	cout << solution.isSymmetric(tree5) << endl;

	auto tree6 = buildTree("[1, 0]");
	cout << solution.isSymmetric(tree6) << endl;

	cin.get();

	return 0;
}