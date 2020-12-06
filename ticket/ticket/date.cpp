#include "date.h"

date::date(int day, int month, int year) :
	day_(day),
	month_(month),
	year_(year)
{}

void date::setDay(int day)
{
	day_ = day;
}
void date::setMonth(int month)
{
	month_ = month;
}
void date::setYear(int year)
{
	year_ = year;
}

int date::getDay()
{
	return day_;
}
int date::getMonth()
{
	return month_;
}
int date::getYear()
{
	return year_;
}

void date::dateParseToInt(str date_)   
{
	char* day = new char[2];
	char* month = new char[2];
	char* year = new char[4];
	for (int i = 0; date_.get_length(); i++)
	{
		if (date_[i] == '/')
		{
			continue;
		}
		if (i < 2)
		{
			day[i] = date_[i];
		}
		if (i > 3 && i < 5)
		{
			month[i] = date_[i];
		}
		if (i > 5 && i < 10)
		{
			year[i] = date_[i];
		}
	}
	day_ = std::atoi(day);
	month_ = std::atoi(month);
	year_ = std::atoi(year);
	delete[] day;
	delete[] month;
	delete[] year;
}

std::istream& operator>>(std::istream& in, date& date)
{
	return in >> date.date_;
}