/*
You are playing the following Bulls and Cows game with your friend: You write down a number and ask your friend to guess what the number is. 
Each time your friend makes a guess, you provide a hint that indicates how many digits in said guess match your secret number exactly 
in both digit and position (called "bulls") and how many digits match the secret number but locate in the wrong position 
(called "cows"). Your friend will use successive guesses and hints to eventually derive the secret number.

Write a function to return a hint according to the secret number and friend's guess, use A to indicate the bulls and B to indicate the cows.

Please note that both secret number and friend's guess may contain duplicate digits.

Example 1:

Input: secret = "1807", guess = "7810"

Output: "1A3B"

Explanation: 1 bull and 3 cows. The bull is 8, the cows are 0, 1 and 7.
Example 2:

Input: secret = "1123", guess = "0111"

Output: "1A1B"

Explanation: The 1st 1 in friend's guess is a bull, the 2nd or 3rd 1 is a cow.
Note: You may assume that the secret number and your friend's guess only contain digits, and their lengths are always equal.
*/
#include <iostream>
#include <string>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
	string getHint(string secret, string guess) {
		string result = "";
		int bullCount = 0, cowCount = 0;

		unordered_map<char, int> secretCharCount, guessCharCount;

		for (int i = 0; i < secret.size(); ++i) {
			if (secret[i] == guess[i]) {
				++bullCount;
				continue;
			}

			secretCharCount[secret[i]]++;
			guessCharCount[guess[i]]++;
			
		}

		for (const auto& p : guessCharCount) {
			cowCount += min(p.second, secretCharCount[p.first]);
				
		}

		result += to_string(bullCount) + "A" + to_string(cowCount) + "B";
		return result;
	}
};

int main(int argc, char* argv[]) {
	Solution solution;

	string secret1{ "1807" };
	string guess1{ "7810" };
	cout << solution.getHint(secret1, guess1) << endl;

	string secret2{ "1123" };
	string guess2{  "0111" };
	cout << solution.getHint(secret2, guess2) << endl;

	string secret3{ "1122" };
	string guess3{ "2211" };
	cout << solution.getHint(secret3, guess3) << endl;

	cin.get();
	return 0;
}