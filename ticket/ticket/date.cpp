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

void pareserToInt(str* date_)
{
	int i = 0;
	int counter = 0;
	while (date_[i])
	{
		if ()
	}
}

std::istream& operator>>(std::istream& in, date& date)
{
	in >> 
}