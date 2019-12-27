/*
Count the number of segments in a string, where a segment is defined to be a contiguous sequence of non-space characters.

Please note that the string does not contain any non-printable characters.

Example:

Input: "Hello, my name is John"
Output: 5
*/
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
	int countSegments(string s) {
		if (s == "")
			return 0;

		int segments = 0;
		bool previousWasASpace = true;

		for (const auto& c : s) {

			if (previousWasASpace && !(c == ' ' || c == '\t' || c == '\n')) {
				previousWasASpace = false;
				++segments;
			}
			else if (c == ' ' || c == '\t' || c == '\n')
				previousWasASpace = true;
		}
		
		return segments;
	}
};

int main(int argc, char* argv[]) {
	Solution solution;

	cout << solution.countSegments("Of all the gin joints in all the towns in all the world,   ") << endl;

	cin.get();
	return 0;
}