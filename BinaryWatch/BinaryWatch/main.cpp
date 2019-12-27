/*
A binary watch has 4 LEDs on the top which represent the hours (0-11), and the 6 LEDs on the bottom represent the minutes (0-59).

Each LED represents a zero or one, with the least significant bit on the right.


For example, the above binary watch reads "3:25".

Given a non-negative integer n which represents the number of LEDs that are currently on, return all possible times the watch could represent.

Example:

Input: n = 1
Return: ["1:00", "2:00", "4:00", "8:00", "0:01", "0:02", "0:04", "0:08", "0:16", "0:32"]
Note:
The order of output does not matter.
The hour must not contain a leading zero, for example "01:00" is not valid, it should be "1:00".
The minute must be consist of two digits and may contain a leading zero, for example "10:2" is not valid, it should be "10:02".
*/
#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <string>
#include <sstream>
#include <iomanip>

using namespace std;

class Solution {
	unordered_map<int, int> numbersDigits;
public:
	Solution() {
		for (int i = 0; i < 60; ++i) {
			int number = i;
			int digits = 0;
			while(number > 0) {
				int remainder = number % 2;
				number /= 2;
				digits += remainder;
			}
			numbersDigits[i] = digits;
		}
	}
	vector<string> readBinaryWatch(int num) {
		if (!num)
			return {"0:00"};

		int maxHoursDigits = min(3, num);
		vector<string> result;
		
		for (int hoursDigits = 0; hoursDigits <= maxHoursDigits; ++hoursDigits) {
			for (int minutesDigits = 0; minutesDigits <= num - hoursDigits; ++minutesDigits) {
				if (hoursDigits + minutesDigits != num)
					continue;
				for (int hour = 0; hour < 12; ++hour) {
					if (numbersDigits[hour] != hoursDigits)
						continue;

					for (int minute = 0; minute < 60; ++minute) {
						

						if (numbersDigits[minute] != minutesDigits)
							continue;

						

						string hourString = to_string(hour);
						stringstream ss;
						ss << setw(2) << setfill('0') << minute;
						string minuteString = ss.str();
						string temp = to_string(hour) + ":" + minuteString;
						result.push_back(temp);
					}
				}
			}
		}

		return result;
	}
};

void print(vector<string>& vec) {
	for (const auto& s : vec)
		cout << s << '\t';
}

int main() {
	Solution solution;
	auto result = solution.readBinaryWatch(1);
	print(result);

	result = solution.readBinaryWatch(2);
	print(result);

	cin.get();
}