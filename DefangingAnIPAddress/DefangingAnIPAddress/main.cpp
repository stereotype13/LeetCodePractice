/*
Given a valid (IPv4) IP address, return a defanged version of that IP address.

A defanged IP address replaces every period "." with "[.]".



Example 1:

Input: address = "1.1.1.1"
Output: "1[.]1[.]1[.]1"

Example 2:

Input: address = "255.100.50.0"
Output: "255[.]100[.]50[.]0"



Constraints:

	The given address is a valid IPv4 address.

*/
#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
	string defangIPaddr(string address) {
		string answer = "";
		for (const auto& c : address) {
			if (c == '.') {
				answer += "[.]";
				continue;
			}
			answer += c;
		}
		return answer;
	}
};

int main(int argc, const char* argv[]) {
	Solution solution;

	string input1 = "255.100.50.0";
	cout << solution.defangIPaddr(input1) << endl;

	cin.get();
	return 0;
}