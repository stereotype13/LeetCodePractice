/*
Given a string date representing a Gregorian calendar date formatted as YYYY-MM-DD, return the day number of the year.



Example 1:

Input: date = "2019-01-09"
Output: 9
Explanation: Given date is the 9th day of the year in 2019.

Example 2:

Input: date = "2019-02-10"
Output: 41

Example 3:

Input: date = "2003-03-01"
Output: 60

Example 4:

Input: date = "2004-03-01"
Output: 61



Constraints:

	date.length == 10
	date[4] == date[7] == '-', and all other date[i]'s are digits
	date represents a calendar date between Jan 1st, 1900 and Dec 31, 2019.

*/
#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
	int dayOfYear(string date) {
		int year = stoi(date.substr(0, 4));
		int month = stoi(date.substr(5, 2));
		int day = stoi(date.substr(8, 2));

		bool isLeapYear = (year % 4 == 0 && year % 100 != 0) ? true : false;

		int daysInMonth[12];
		daysInMonth[0] =  0;
		daysInMonth[1] =  31;
		daysInMonth[2] =  59;
		daysInMonth[3] =  90;
		daysInMonth[4] =  120;
		daysInMonth[5] =  151;
		daysInMonth[6] =  181;
		daysInMonth[7] =  212;
		daysInMonth[8] =  243;
		daysInMonth[9] =  273;
		daysInMonth[10] = 304;
		daysInMonth[11] = 334;

		int answer = daysInMonth[month - 1];
		answer += day;

		answer += isLeapYear && month > 2 ? 1 : 0;

		return answer;
	}
};

int main() {
	Solution solution;

	string date1 = "2019-01-09";
	cout << solution.dayOfYear(date1) << endl;

	string date2 = "2019-02-10";
	cout << solution.dayOfYear(date2) << endl;

	string date3 = "2003-03-01";
	cout << solution.dayOfYear(date3) << endl;

	string date4 = "2004-03-01";
	cout << solution.dayOfYear(date4) << endl;

	cin.get();
	return 0;
}