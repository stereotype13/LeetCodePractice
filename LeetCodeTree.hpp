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

	for (int i = 0; i <= (nodes.size() - 2) / 2; ++i) {
		auto currentNode = nodes[i];

		if (!currentNode)
			continue;

		currentNode->left = nodes[2 * i + 1];
		currentNode->right = nodes[2 * i + 2];
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

	if (nodes.size() == 1)
		return nodes[0];

	for (int i = 0; i < nodes.size(); ++i) {
		auto currentNode = nodes[i];

		if (!currentNode)
			continue;

		if (2 * i + 1 < nodes.size())
			currentNode->left = nodes[2 * i + 1];
		else
			break;

		if (2 * i + 2 < nodes.size())
			currentNode->right = nodes[2 * i + 2];
		else
			break;
	}

	return nodes[0];

}

