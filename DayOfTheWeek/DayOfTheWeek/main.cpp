/*
Given a date, return the corresponding day of the week for that date.

The input is given as three integers representing the day, month and year respectively.

Return the answer as one of the following values {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"}.



Example 1:

Input: day = 31, month = 8, year = 2019
Output: "Saturday"

Example 2:

Input: day = 18, month = 7, year = 1999
Output: "Sunday"

Example 3:

Input: day = 15, month = 8, year = 1993
Output: "Sunday"



Constraints:

	The given dates are valid dates between the years 1971 and 2100.

*/
#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
	string dayOfTheWeek(int day, int month, int year) {
		//1/1/1971 was a Friday

		auto isLeapYear = [](int& year) {return year % 4 == 0 && (year % 100 != 0 || year % 400 == 0); };

		int numberOfDays = 0;
		for (int i = 1971; i < year; ++i) {
			if (isLeapYear(i))
				numberOfDays += 366;
			else
				numberOfDays += 365;
		}

		int days[12]{ 0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334 };
		int daysLeapYear[12]{ 0, 31, 60, 91, 121, 152, 182, 213, 244, 274, 305, 335 };

		if (isLeapYear(year))
			numberOfDays += daysLeapYear[month - 1];
		else
			numberOfDays += days[month - 1];

		numberOfDays += day;

		const char* daysOfWeekArray[7]{ "Thursday", "Friday", "Saturday", "Sunday", "Monday", "Tuesday", "Wednesday" };

		return daysOfWeekArray[numberOfDays % 7];
	}
};

int main() {
	Solution solution;

	//cout << solution.dayOfTheWeek(1, 1, 1971) << endl;
	//cout << solution.dayOfTheWeek(2, 1, 1971) << endl;
	//cout << solution.dayOfTheWeek(1, 1, 1972) << endl;
	//cout << solution.dayOfTheWeek(1, 1, 1999) << endl;
	cout << solution.dayOfTheWeek(1, 1, 2000) << ". Should be Saturday" << endl;
	cout << solution.dayOfTheWeek(1, 2, 2000) << ". Should be Tuesday" << endl;
	cout << solution.dayOfTheWeek(31, 12, 2000) << ". Should be Sunday" << endl;
	cout << solution.dayOfTheWeek(1, 1, 2001) << ". Should be Monday" << endl;

	cout << solution.dayOfTheWeek(3, 3, 2020) << endl;

	cin.get();
	return 0;
}