/*
Given a positive integer, output its complement number. The complement strategy is to flip the bits of its binary representation.

Note:
The given integer is guaranteed to fit within the range of a 32-bit signed integer.
You could assume no leading zero bit in the integer’s binary representation.
Example 1:
Input: 5
Output: 2
Explanation: The binary representation of 5 is 101 (no leading zero bits), and its complement is 010. So you need to output 2.
Example 2:
Input: 1
Output: 0
Explanation: The binary representation of 1 is 1 (no leading zero bits), and its complement is 0. So you need to output 0.
*/
#include <iostream>
#include <bitset>

using namespace std;

class Solution {
public:
	int findComplement(int num) {
		bitset<32> bits(num);

		bool foundFirstOne = false;
		for (int i = 31; i > 0; --i) {
			if (!foundFirstOne && bits[i] == 0) 
				continue;

			foundFirstOne = true;
			bits.flip(i);
			
		}
		bits.flip(0);

		return (int)bits.to_ulong();
	}
};

int main(int argc, const char* argv[]) {
	Solution solution;
	cout << solution.findComplement(5) << endl;
	cout << solution.findComplement(1) << endl;

	cin.get();
	return 0;
}