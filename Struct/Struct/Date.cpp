#include "Date.h"

#include <iostream>
#include <ctime>
using namespace std;

void InitDate(Date& date, uint day, uint month, uint year)
{
	if (day > 31) {
		cout << "Day is incorrect" << endl;
		return;
	}

	if (month > 12) {
		cout << "Month is incorrect" << endl;
		return;
	}

	date.day = day;
	date.month = month;
	date.year = year;
}

void PrintDate(Date date)
{
	cout << "Date: " << date.day << "."
		<< date.month << "." << date.year << endl;
}

Date GetToday()
{
	time_t t = time(0);
	tm localTm;
	localtime_s(&localTm, &t);

	Date date;
	date.day = localTm.tm_mday;
	date.month = localTm.tm_mon + 1;
	date.year = localTm.tm_year + 1900;

	return date;
}