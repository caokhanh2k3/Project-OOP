#include"DateFormatInfo.h"



DateFormatInfo::DateFormatInfo()
{

}
DateFormatInfo::DateFormatInfo(int currencyPositive)
{
	_currencyPositive = currencyPositive;
}

int DateFormatInfo::currencyPositive()
{
	return _currencyPositive;
}
string DateFormatInfo::currencyPositiveFormat()
{
	if (_currencyPositive == 0)
	{
		_currencyPositiveFormat = "dd/mm//yyyy";
	}
	else if (_currencyPositive == 1)
	{
		_currencyPositiveFormat = "mm/dd//yyyy";
	}

	return  _currencyPositiveFormat;
}


string DateFormatInfo::toString()
{
	return " ";
}