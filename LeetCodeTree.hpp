#pragma once
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <regex>

std::vector<std::string> split(std::string& s, char delimiter)
{
	s.erase(std::remove_if(s.begin(), s.end(), isspace), s.end());
	s.erase(std::remove(s.begin(), s.end(), '['), s.end());
	s.erase(std::remove(s.begin(), s.end(), ']'), s.end());


	std::vector<std::string> tokens;
	std::string token;
	std::istringstream tokenStream(s);
	while (std::getline(tokenStream, token, delimiter))
	{
		tokens.push_back(token);
	}
	return tokens;
}

struct TreeNode {
	int val;

	TreeNode* left;
	TreeNode* right;
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

	~TreeNode() {
		if (left)
			delete left;

		if (right)
			delete right;
	}
};

TreeNode* buildTree(std::string& s) {
	std::vector<std::string> nodesAsString = split(s, ',');

	//convert them to integers
	std::vector<TreeNode*> nodes;
	for (const auto& number : nodesAsString) {

		TreeNode* node;
		try {
			node = new TreeNode(std::stoi(number));
		}
		catch (std::invalid_argument& e) {
			node = nullptr;
		}

		nodes.push_back(node);
	}

	for (int i = 0; i < (int)nodes.size(); ++i) {
		auto node = nodes[i];

		if (node) {
			int leftIndex = 2 * i + 1;
			int rightIndex = 2 * i + 2;

			if (leftIndex < (int)nodes.size())
				node->left = nodes[leftIndex];

			if (rightIndex < (int)nodes.size())
				node->right = nodes[rightIndex];
		}
	}

	return nodes[0];

}

TreeNode* buildTree(std::string&& s) {
	std::vector<std::string> nodesAsString = split(s, ',');

	//convert them to integers
	std::vector<TreeNode*> nodes;
	for (const auto& number : nodesAsString) {

		TreeNode* node;
		try {
			node = new TreeNode(std::stoi(number));
		}
		catch (std::invalid_argument& e) {
			node = nullptr;
		}

		nodes.push_back(node);
	}


	int offset = 0;
	for (int i = 0; i < (int)nodes.size(); ++i) {
		auto node = nodes[i];

		if (node == nullptr)
			offset -= 2;

		if (node) {
			int leftIndex = 2 * i + 1 + offset;
			int rightIndex = 2 * i + 2 + offset;

			if (leftIndex < (int)nodes.size())
				node->left = nodes[leftIndex];

			if (rightIndex < (int)nodes.size())
				node->right = nodes[rightIndex];
		}
	}

	return nodes[0];

}

