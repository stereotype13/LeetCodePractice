/*
Given a paragraph and a list of banned words, return the most frequent word that is not in the list of banned words. 
It is guaranteed there is at least one word that isn't banned, and that the answer is unique.

Words in the list of banned words are given in lowercase, and free of punctuation.  Words in the paragraph are not case sensitive.  
The answer is in lowercase.



Example:

Input:
paragraph = "Bob hit a ball, the hit BALL flew far after it was hit."
banned = ["hit"]
Output: "ball"
Explanation:
"hit" occurs 3 times, but it is a banned word.
"ball" occurs twice (and no other word does), so it is the most frequent non-banned word in the paragraph.
Note that words in the paragraph are not case sensitive,
that punctuation is ignored (even if adjacent to words, such as "ball,"),
and that "hit" isn't the answer even though it occurs more because it is banned.


Note:

1 <= paragraph.length <= 1000.
0 <= banned.length <= 100.
1 <= banned[i].length <= 10.
The answer is unique, and written in lowercase (even if its occurrences in paragraph may have uppercase symbols, and even if it is a proper noun.)
paragraph only consists of letters, spaces, or the punctuation symbols !?',;.
There are no hyphens or hyphenated words.
Words only consist of letters, never apostrophes or other punctuation symbols.
*/
#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
#include <unordered_map>

using namespace std;

class Solution {
public:
	string mostCommonWord(string paragraph, vector<string>& banned) {
		if (paragraph.empty())
			return "";

		string word = "";
		vector<string> words;
		for (auto& c : paragraph) {
			c = tolower(c);

			if ((c < 'a' || c > 'z') && word.size() > 0) {
				words.push_back(word);
				word = "";
				continue;
			}

			if(c >= 'a' && c <= 'z')
				word += c;
		}
		if(word.size() > 0)
			words.push_back(word);

		unordered_set<string> bannedWordSet;
		for (auto& word : banned)
			bannedWordSet.emplace(word);

		int maxWordCount = 0;
		string mostFrequenWord;

		unordered_map<string, int> wordFrequencies;
		for (auto& word : words) {
			if (bannedWordSet.find(word) == bannedWordSet.end())
				wordFrequencies[word]++;
		}

		for(auto& p : wordFrequencies)
			if (p.second > maxWordCount) {
				mostFrequenWord = p.first;
				maxWordCount = p.second;
			}

		return mostFrequenWord;
		
	}
};

int main() {
	Solution solution;
	string p1 = "Bob hit a ball, the hit BALL flew far after it was hit.";
	vector<string> banned1{ "hit" };
	cout << solution.mostCommonWord(p1, banned1) << endl;

	string p2 = "a.";
	vector<string> banned2{};
	cout << solution.mostCommonWord(p2, banned2) << endl;

	string p3 = "Bob. hIt, baLl";
	vector<string> banned3{"bob", "hit"};
	cout << solution.mostCommonWord(p3, banned3) << endl;


	cin.get();
	return 0;
}