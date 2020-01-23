/*
Find the minimum length word from a given dictionary words, which has all the letters from the string licensePlate. 
Such a word is said to complete the given string licensePlate

Here, for letters we ignore case. For example, "P" on the licensePlate still matches "p" on the word.

It is guaranteed an answer exists. If there are multiple answers, return the one that occurs first in the array.

The license plate might have the same letter occurring multiple times. For example, given a licensePlate of "PP", 
the word "pair" does not complete the licensePlate, but the word "supper" does.

Example 1:
Input: licensePlate = "1s3 PSt", words = ["step", "steps", "stripe", "stepple"]
Output: "steps"
Explanation: The smallest length word that contains the letters "S", "P", "S", and "T".
Note that the answer is not "step", because the letter "s" must occur in the word twice.
Also note that we ignored case for the purposes of comparing whether a letter exists in the word.
Example 2:
Input: licensePlate = "1s3 456", words = ["looks", "pest", "stew", "show"]
Output: "pest"
Explanation: There are 3 smallest length words that contains the letters "s".
We return the one that occurred first.
Note:
licensePlate will be a string with length in range [1, 7].
licensePlate will contain digits, spaces, or letters (uppercase or lowercase).
words will have a length in the range [10, 1000].
Every words[i] will consist of lowercase letters, and have length in range [1, 15].
*/
#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
	string shortestCompletingWord(string licensePlate, vector<string>& words) {
		string lowerCase = "";

		for (const auto& c : licensePlate) {
			if (isalpha(c) && !isspace(c))
				lowerCase += tolower(c);
		}

		unordered_map<char, int> licensePlateCharCount;

		for (const auto& c : lowerCase) 
			licensePlateCharCount[c]++;

		int minLength = INT_MAX;
		string result = "";

		for (const auto& word : words) {
			unordered_map<char, int> wordCharCount;
			wordCharCount.clear();

			for (const auto& c : word)
				wordCharCount[c]++;

			bool completesLicensePlate = true;
			for (const auto& p : licensePlateCharCount) {
				if (!(wordCharCount.find(p.first) != wordCharCount.end() && wordCharCount[p.first] >= p.second)) {
					completesLicensePlate = false;
					break;
				}

			}

			if (completesLicensePlate && (int)word.size() < minLength) {
				result = word;
				minLength = (int)word.size();
			}
				

		}

		return result;
	}
};

class Solution2 {
public:
	string shortestCompletingWord(string licensePlate, vector<string>& words) {
		string lowerCase = "";

		for (const auto& c : licensePlate) {
			if (isalpha(c) && !isspace(c))
				lowerCase += tolower(c);
		}

		//unordered_map<char, int> licensePlateCharCount;
		int licensePlateCharCount[26];
		memset(licensePlateCharCount, 0, sizeof(int) * 26);

		for (const auto& c : lowerCase)
			licensePlateCharCount[c - 'a']++;

		int minLength = INT_MAX;
		string result = "";

		for (const auto& word : words) {
			//unordered_map<char, int> wordCharCount;
			int wordCharCount[26];
			memset(wordCharCount, 0, sizeof(int) * 26);

			for (const auto& c : word)
				wordCharCount[c - 'a']++;

			bool completesLicensePlate = true;
			for (int i = 0; i < 26; ++i) {
				if (wordCharCount[i] < licensePlateCharCount[i]) {
					completesLicensePlate = false;
					break;
				}

			}

			if (completesLicensePlate && (int)word.size() < minLength) {
				result = word;
				minLength = (int)word.size();
			}


		}

		return result;
	}
};

int main(int argc, const char* argv[]) {
	Solution2 solution;

	string lp1 = "1s3 PSt";
	auto vec1 = vector<string>{ "step", "steps", "stripe", "stepple" };
	cout << solution.shortestCompletingWord(lp1, vec1) << endl;

	string lp2 = "1s3 456";
	auto vec2 = vector<string>{ "looks", "pest", "stew", "show" };
	cout << solution.shortestCompletingWord(lp2, vec2) << endl;

	string lp3 = "GrC8950";
	auto vec3 = vector<string>{ "measure", "other", "every", "base", "according", "level", "meeting", "none", "marriage", "rest" };
	cout << solution.shortestCompletingWord(lp3, vec3) << endl;

	cin.get();
	return 0;
}