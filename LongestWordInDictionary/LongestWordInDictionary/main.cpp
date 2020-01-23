/*
Given a list of strings words representing an English Dictionary, find the longest word in words that can be built one character at a time by other words in words. If there is more than one possible answer, return the longest word with the smallest lexicographical order.

If there is no answer, return the empty string.
Example 1:
Input:
words = ["w","wo","wor","worl", "world"]
Output: "world"
Explanation:
The word "world" can be built one character at a time by "w", "wo", "wor", and "worl".
Example 2:
Input:
words = ["a", "banana", "app", "appl", "ap", "apply", "apple"]
Output: "apple"
Explanation:
Both "apply" and "apple" can be built from other words in the dictionary. However, "apple" is lexicographically smaller than "apply".
Note:

All the strings in the input will only contain lowercase letters.
The length of words will be in the range [1, 1000].
The length of words[i] will be in the range [1, 30].
*/
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:

	struct Trie {
		char value;

		Trie* children[26];

		void init() {
			for (int i = 0; i < 26; ++i)
				children[i] = nullptr;
		}

		Trie() {
			init();
		}

		Trie(char c) : value{ c } {
			init();
		}

		void insert(const string& s, int index) {
			if (index >= s.size())
				return;

			char c = s[index];
			this->value = c;

			if (children[c - 'a']) {
				auto t = children[c - 'a'];
				t->insert(s, index + 1);
			}
			else {
				children[c - 'a'] = new Trie(c);
			}
		}

		~Trie() {
			for (const auto& child : children) {
				if (child)
					delete child;
			}
		}
	};

	int dfs(Trie* root, int depth = 0) {
		int length = depth;
		for (const auto& t : root->children) {
			if (t) {
				int newLength = dfs(t, depth + 1);
				if (newLength > length) {
					length = newLength;
				}
				length = max(length, dfs(t, depth + 1));
			}
		}
		return length;
	}

	string longestWord(vector<string>& words) {
		auto root = new Trie();

		for (const auto& word : words) {
			root->insert(word);
		}
		
		int maxDepth = dfs(root);
		delete root;

		return maxDepth;
	}
};

int main(int argc, const char* argv[]) {



	cin.get();
	return 0;
}