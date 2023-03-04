#include "date.h"
#include <iostream>
#include <exception>

Date::Date ()
{
	int m_day = 1;
	int m_month = 1;
	int m_year = 1900;
}

Date::Date (const std::string& date)
{
	std::string dateExample = "01-01-1900";
	char dateSymbol = '-';
	const int count = 2;
	int symbolIndex[count] = {2,5};
	int size = date.size();
	int convert = 0;

	if (size > dateExample.size())
	{
		throw std::invalid_argument("!Inconsistent parameter:");
	}

	for (int i = 0; i < size; ++i)
	{
		if (date[i] >= '0' && date[i] <= '9')
		{
			char ch = date[i];
			convert *= 10;
			convert += ch - 48;
		}
		else if (i != symbolIndex[0] && i != symbolIndex[1])
		{
			throw std::invalid_argument("!Inconsistent parameter:");
		}
		else if (date[i] != dateSymbol)
		{
			throw std::invalid_argument("!Inconsistent parameter:");
		}
		
		if (i == symbolIndex[0])
		{
			this->setDay(convert);
			convert = 0; 
		}
		else if (i == symbolIndex[1])
		{
			this->setMonth(convert);
			convert = 0;
		}
		
		if (i == size - 1)
		{
			this->setYear(convert);
		}
	}

}

void Date::setDay (int day)
{
	if (day < 1 || day > 31)
	{
		throw std::invalid_argument("!Inconsistent parameter:");  
	}
	else
	{
		m_day = day;
	}
}

void Date::setMonth (int month)
{
	if (month < 1 || month > 12)
	{
		throw std::invalid_argument("!Inconsistent parameter:");
	}
	else
	{
		m_month = month;
	}

}

void Date::setYear (int year)
{
	if (year < 1900)
	{
		throw std::invalid_argument("!Inconsistent parameter:");
	}
	else
	{
		m_year = year;
	}
}

int Date::getDay ()
{
	return m_day;
}

int Date::getMonth ()
{
	return m_month;
}

int Date::getYear ()
{
	return m_year;
}
