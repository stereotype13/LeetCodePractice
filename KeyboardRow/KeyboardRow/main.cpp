/*
Given a List of words, return the words that can be typed using letters of alphabet on only one row's of American keyboard like the image below.






Example:

Input: ["Hello", "Alaska", "Dad", "Peace"]
Output: ["Alaska", "Dad"]


Note:

You may use one character in the keyboard more than once.
You may assume the input string will only contain letters of alphabet.
*/
#include <iostream>
#include <vector>
#include <unordered_set>
#include <string>

using namespace std;

class Solution {
public:
	vector<string> findWords(vector<string>& words) {
		unordered_set<char> firstRow{ 'q', 'w', 'e', 'r', 't', 'y', 'u', 'i', 'o', 'p' };
		unordered_set<char> secondRow{ 'a', 's', 'd', 'f', 'g', 'h', 'j', 'k', 'l' };
		unordered_set<char> thirdRow{ 'z', 'x', 'c', 'v', 'b', 'n', 'm' };

		vector<unordered_set<char>> keyboard;
		keyboard.push_back(firstRow);
		keyboard.push_back(secondRow);
		keyboard.push_back(thirdRow);

		vector<string> result;
		for (int i = 0; i < keyboard.size(); ++i) {
			auto row = keyboard[i];
			for (const auto& word : words) {
				bool rowContains = true;
				for (const auto& c : word) {
					if (row.find(tolower(c)) == row.end()) {
						rowContains = false;
						break;
					}
						
				}
				if (rowContains)
					result.push_back(word);
			}
		}

		return result;
	}
};

void print(vector<string>& words) {
	for (const auto& word : words)
		cout << word << endl;
}

int main(int argc, const char* argv[]) {
	Solution solution;
	vector<string> input1{ "Hello", "Alaska", "Dad", "Peace" };
	auto result1 = solution.findWords(input1);
	print(result1);

	vector<string> input2{ "a", "b" };
	auto result2 = solution.findWords(input2);
	print(result2);
	

	cin.get();
	return 0;
}