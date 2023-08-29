#pragma once
#include <string>
#include <vector>
using namespace std;

class Date {
private:
	int _day;
	int _month;
	int _year;
public:
	Date();
	Date(int, int, int);
	static Date Now();
public:
	int year();
	string toString();
public:
	static bool isLeapYear(int year);
	static vector<int> maxDaysInMonth(int year);
};
