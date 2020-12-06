#include "flightID.h"
#include <iostream>

// ������������

flightID::flightID() :
	letters_(nullptr),
	figures_(nullptr)
{}
flightID::flightID(str letters, str figures) :
	letters_(letters),
	figures_(figures)
{}

// �������

str flightID::getLetters(flightID ID)
{
	return letters_;
}
str flightID::getFigures(flightID ID)
{
	return figures_;
}

// �������

void flightID::setLetters(flightID ID, str letters)
{
	letters_ = letters;
}
void flightID::setFigures(flightID ID, str figures)
{
	figures_ = figures;
}
void flightID::setFlightID(flightID ID, str letters, str figures)
{
	letters_ = letters;
	figures_ = figures;
}

// ���������

bool flightID::operator==(const flightID& ID)
{
		return this->letters_ == letters_ && this->figures_ == ID.figures_;
}
bool flightID::operator!=(const flightID& number)
{
	return !operator==(number);
}