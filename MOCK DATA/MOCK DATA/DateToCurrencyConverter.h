#pragma once
#include<iostream>
#include<string>
#include<vector>
#include<regex>
#include"DateFormatInfo.h"
#include"String.h"

using namespace std;


class DateToCurrencyConverter
{
private:
	int _curPositive = 0;
public:
	string convert(string date);
	void SetcurrencyPositive(int currencyPositive);
};

