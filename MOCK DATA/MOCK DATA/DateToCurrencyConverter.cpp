#include"DateToCurrencyConverter.h"

string DateToCurrencyConverter::convert(string date)
{
	DateFormatInfo info(_curPositive);

	auto token = Utils::String::split(date, "/");
	string day = token[0];
	string month = token[1];
	string year = token[2];

	string format = info.currencyPositiveFormat();  // "dd/mm//yyyy" ==> "24/05/2003"

	string result = regex_replace(format, regex("dd"), day);
	result = regex_replace(result, regex("mm"), month);
	result = regex_replace(result, regex("yyyy"), year);

	return result;
}


void DateToCurrencyConverter::SetcurrencyPositive(int currencyPositive)
{
	_curPositive = currencyPositive;
}