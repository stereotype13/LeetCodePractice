/*
Given an array of characters, compress it in-place.

The length after compression must always be smaller than or equal to the original array.

Every element of the array should be a character (not int) of length 1.

After you are done modifying the input array in-place, return the new length of the array.


Follow up:
Could you solve it using only O(1) extra space?


Example 1:

Input:
["a","a","b","b","c","c","c"]

Output:
Return 6, and the first 6 characters of the input array should be: ["a","2","b","2","c","3"]

Explanation:
"aa" is replaced by "a2". "bb" is replaced by "b2". "ccc" is replaced by "c3".


Example 2:

Input:
["a"]

Output:
Return 1, and the first 1 characters of the input array should be: ["a"]

Explanation:
Nothing is replaced.


Example 3:

Input:
["a","b","b","b","b","b","b","b","b","b","b","b","b"]

Output:
Return 4, and the first 4 characters of the input array should be: ["a","b","1","2"].

Explanation:
Since the character "a" does not repeat, it is not compressed. "bbbbbbbbbbbb" is replaced by "b12".
Notice each digit has it's own entry in the array.


Note:

All characters have an ASCII value in [35, 126].
1 <= len(chars) <= 1000.
*/
#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <string>

using namespace std;

class Solution {
public:
	int compress(vector<char>& chars) {
		if (chars.empty())
			return 0;

		if (chars.size() == 1)
			return 1;

		vector<pair<char, int>> compressedStructure;

		int charClusterCount = 1;
		for (int i = 1; i < chars.size(); ++i) {
			char c = chars[i];
			char previous = chars[i - 1];
			
			if (c != previous) {
				compressedStructure.push_back({previous, charClusterCount});
				charClusterCount = 1;
				continue;
			}

			++charClusterCount;
				
		}
		compressedStructure.push_back({ chars.back(), charClusterCount });

		int charIndex = 0;
		for (const auto& p : compressedStructure) {
			if (p.second == 1) {
				chars[charIndex] = p.first;
				++charIndex;
			}
			else {
				chars[charIndex] = p.first;

				++charIndex;
				int temp = p.second;
				stack<char> tempDigits;
				while (temp > 0) {
					tempDigits.push((char)((temp % 10) + '0'));
					temp /= 10;
				}

				while (!tempDigits.empty()) {
					chars[charIndex] = tempDigits.top();
					tempDigits.pop();
					++charIndex;
				}
			}

		}
		return charIndex;
	}
};

class Solution2 {
public:
	int compress(vector<char>& chars) {
		if (chars.empty())
			return 0;

		if (chars.size() == 1)
			return 1;

		queue<char> printQueue;

		int clusterCount = 1;
		int cursorPos = 0;
		for (int i = 1; i < chars.size(); ++i) {
			char c = chars[i];
			char previous = chars[i - 1];

			if (c != previous) {
				printQueue.push(previous);
				if (clusterCount > 1) {
					string tempString = to_string(clusterCount);
					for (auto& tempChar : tempString)
						printQueue.push(tempChar);
				}
				clusterCount = 0;
				//continue;
			}
			while (!printQueue.empty()) {
				chars[cursorPos] = printQueue.front();
				printQueue.pop();
				++cursorPos;
			}
				
			++clusterCount;
		}
		printQueue.push(chars.back());
		if (clusterCount > 1) {
			string tempString = to_string(clusterCount);
			for (auto& tempChar : tempString)
				printQueue.push(tempChar);
		}
		while (!printQueue.empty()) {
			chars[cursorPos] = printQueue.front();
			printQueue.pop();
			++cursorPos;
		}
		return cursorPos;
	}
};

int main(int argc, char* argv[]) {
	Solution2 solution;
	vector<char> vec1{ 'a', 'a', 'b', 'b', 'b', 'c' };
	cout << solution.compress(vec1) << endl;

	vector<char> vec2{ 'a', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b' };
	cout << solution.compress(vec2) << endl;

	cin.get();
	return 0;
}