/*
The count-and-say sequence is the sequence of integers with the first five terms as following:

1.     1
2.     11
3.     21
4.     1211
5.     111221
1 is read off as "one 1" or 11.
11 is read off as "two 1s" or 21.
21 is read off as "one 2, then one 1" or 1211.

Given an integer n where 1 ≤ n ≤ 30, generate the nth term of the count-and-say sequence.

Note: Each term of the sequence of integers will be represented as a string.



Example 1:

Input: 1
Output: "1"
Example 2:

Input: 4
Output: "1211"
*/
#include <string>
#include <iostream>

using namespace std;

class Solution {
public:
	string countAndSay(int n) {
		string s = "1";

		for (int j = 1; j < n; ++j) {
			
			char c = s[0];
			int currentCount = 0;
			string temp = "";
			for (int i = 0; i < s.size(); ++i) {
				if (c == s[i]) {
					++currentCount;
					continue;
				}

				temp += to_string(currentCount);
				temp += c;
				c = s[i];
				currentCount = 1;
			}
			temp += to_string(currentCount);
			temp += c;
			
			s = temp;
		}

		return s;
		
	}
};

int main(int argc, char* argv[]) {
	Solution solution;

	cout << solution.countAndSay(1) << endl;
	cout << solution.countAndSay(2) << endl;
	cout << solution.countAndSay(3) << endl;
	cout << solution.countAndSay(4) << endl;
	cout << solution.countAndSay(5) << endl;
	cout << solution.countAndSay(6) << endl;

	cin.get();
}