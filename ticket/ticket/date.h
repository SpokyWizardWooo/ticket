#pragma once
#include "str.h"
#include <iostream>

class date
{
public:
	date(int day, int month, int year);

	void setDay(int day);
	void setMonth(int month);
	void setYear(int year);

	int getDay();
	int getMonth();
	int getYear();

	void dateParseToInt(str date_);

	friend std::istream& operator>>(std::istream& in, date& date);

private:
	str date_; 
	int day_;
	int month_;
	int year_;
	
};