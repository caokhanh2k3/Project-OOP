#include "Date.h"
#include <iostream>
#include <sstream>
#include <iomanip>
#include <vector>
using namespace std;


int Date::year() {
	return _year;
}

Date::Date() {
	time_t info = time(NULL);
	tm now;
	localtime_s(&now, &info);

	_year = now.tm_year + 1900;
	_month = now.tm_mon + 1;
	_day = now.tm_mday;
}

Date::Date(int day, int month, int year) {
	this->_day = day;
	this->_month = month;
	this->_year = year;
}

Date Date::Now() {
	return Date();
}

string Date::toString() {
	stringstream builder;

	builder << setw(2) << setfill('0') << _day << "/"
		<< setw(2) << setfill('0') << _month << "/"
		<< _year;

	string result = builder.str();
	return result;
}

bool Date::isLeapYear(int year) {
	bool result = (year % 400 == 0) ||
		((year % 4 == 0) && (year % 100 != 0));
	return result;
}

vector<int> Date::maxDaysInMonth(int year) {
	vector<int> result = { -1,
		31, 28, 31, 30, 31, 30, 31,
		31, 30, 31, 30, 31
	};

	if (isLeapYear(year)) {
		result[2] = 29;
	}

	return result;
}