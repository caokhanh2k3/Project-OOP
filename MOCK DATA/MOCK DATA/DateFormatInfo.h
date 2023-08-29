#pragma once
#include<iostream>
#include<string>
#include<vector>
#include <sstream>
#include<regex>

using namespace std;


class DateFormatInfo 
{
private:
	
	int _currencyPositive = 0;				          // 0		        1		
	string _currencyPositiveFormat = "mm/dd/yyyy"; // "dd/mm/yy"     "mm/dd/yy"   
public:
	DateFormatInfo();
	DateFormatInfo(int currencyPositive);
	int currencyPositive();
	string currencyPositiveFormat();
public:
	string toString();

};
