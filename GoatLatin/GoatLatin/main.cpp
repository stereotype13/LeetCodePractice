/*
A sentence S is given, composed of words separated by spaces. Each word consists of lowercase and uppercase letters only.

We would like to convert the sentence to "Goat Latin" (a made-up language similar to Pig Latin.)

The rules of Goat Latin are as follows:

If a word begins with a vowel (a, e, i, o, or u), append "ma" to the end of the word.
For example, the word 'apple' becomes 'applema'.

If a word begins with a consonant (i.e. not a vowel), remove the first letter and append it to the end, then add "ma".
For example, the word "goat" becomes "oatgma".

Add one letter 'a' to the end of each word per its word index in the sentence, starting with 1.
For example, the first word gets "a" added to the end, the second word gets "aa" added to the end and so on.
Return the final sentence representing the conversion from S to Goat Latin.



Example 1:

Input: "I speak Goat Latin"
Output: "Imaa peaksmaaa oatGmaaaa atinLmaaaaa"
Example 2:

Input: "The quick brown fox jumped over the lazy dog"
Output: "heTmaa uickqmaaa rownbmaaaa oxfmaaaaa umpedjmaaaaaa overmaaaaaaa hetmaaaaaaaa azylmaaaaaaaaa ogdmaaaaaaaaaa"


Notes:

S contains only uppercase, lowercase and spaces. Exactly one space between each word.
1 <= S.length <= 150.
*/
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
	string toGoatLatin(string S) {
		if (S.size() == 0)
			return "";

		string word = "";
		vector<string> words;
		for (auto& c : S) {
			if (c == ' ' && word.size() > 0) {
				words.push_back(word);
				word = "";
				continue;
			}

			word += c;
		}
		if (word.size() > 0)
			words.push_back(word);

		for (unsigned int i = 0; i < words.size(); ++i) {
			string& word = words[i];
			string newWord = "";
			
			char c = word[0];
			if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U') {
				word += "ma";
				
			}
			else {
				newWord += word.substr(1, word.size() - 1);
				newWord += c;
				newWord += "ma";
				word = newWord;
			}

			for (int j = 0; j < i + 1; ++j)
				word += 'a';
		}

		string result = "";
		for (int i = 0; i < (int)words.size() - 1; ++i) {
			result += words[i];
			result += ' ';
		}
		result += words.back();

		return result;
	}
};

int main(int argc, const char* argv[]) {
	Solution solution;

	string S1 = "I speak Goat Latin";
	cout << solution.toGoatLatin(S1) << endl;

	cin.get();
	return 0;
}