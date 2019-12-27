/*
Given an integer, write an algorithm to convert it to hexadecimal. For negative integer, two’s complement method is used.

Note:

All letters in hexadecimal (a-f) must be in lowercase.
The hexadecimal string must not contain extra leading 0s. If the number is zero, it is represented by a single zero character '0'; otherwise, 
the first character in the hexadecimal string will not be the zero character.
The given number is guaranteed to fit within the range of a 32-bit signed integer.
You must not use any method provided by the library which converts/formats the number to hex directly.
Example 1:

Input:
26

Output:
"1a"
Example 2:

Input:
-1

Output:
"ffffffff"
*/
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
	unordered_map<int, char> hexDigitMap{
				{0, '0'},
				{1, '1'},
				{2, '2'},
				{3, '3'},
				{4, '4'},
				{5, '5'},
				{6, '6'},
				{7, '7'},
				{8, '8'},
				{9, '9'},
				{10, 'a'},
				{11, 'b'},
				{12, 'c'},
				{13, 'd'},
				{14, 'e'},
				{15, 'f'}

	};

	void toHex(vector<char>& vec, int num) {
		int place = 7;
		while (num > 0) {
			vec[place] = hexDigitMap[num % 16];
			num /= 16;
			--place;
		}
	}

	void toHex(vector<char>& vec, unsigned num) {
		int place = 7;
		while (num > 0) {
			vec[place] = hexDigitMap[num % 16];
			num /= 16;
			--place;
		}
	}

	string vecToString(vector<char>& vec) {
		string result = "";
		for (const auto& c : vec) {
			if (c == '0' && result == "")
				continue;

			result += c;
		}
		if (result == "")
			return "0";

		return result;
	}
public:
	string toHex(int num) {
		bool isNegative = num < 0;
		unsigned int unsignedNum;
		if (isNegative)
			unsignedNum = -(unsigned int)num;
		else
			unsignedNum = num;



		vector<char> resultVector{ '0', '0', '0', '0', '0', '0', '0', '0' };
		int place = 7;
		toHex(resultVector, unsignedNum);



		if (isNegative) {
			unsigned tempNumber = UINT_MAX - unsignedNum + 1;

			toHex(resultVector, tempNumber);

			return vecToString(resultVector);
		}

		return vecToString(resultVector);
	}
};

int main(int argc, char* argv[]) {
	Solution solution;
	cout << solution.toHex(0) << endl;
	cout << solution.toHex(16) << endl;
	cout << solution.toHex(26) << endl;
	cout << solution.toHex(-1) << endl;
	cout << solution.toHex(-2) << endl;
	cout << solution.toHex(-2147483648) << endl;
	cin.get();

	return 0;
}