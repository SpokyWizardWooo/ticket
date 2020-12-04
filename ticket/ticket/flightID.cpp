#include "flightID.h"
#include <iostream>

// Конструкторы

flightID::flightID() :
	letters_(nullptr),
	figures_(nullptr)
{}
flightID::flightID(str letters, str figures) :
	letters_(letters),
	figures_(figures)
{}

// Геттеры

str flightID::getLetters(flightID ID)
{
	return letters_;
}
str flightID::getFigures(flightID ID)
{
	return figures_;
}

// Сеттеры

str flightID::setLetters(flightID ID, str letters)
{
	letters_ = letters;
}
str flightID::setFigures(flightID ID, str figures)
{
	figures_ = figures;
}
str flightID::setFlightID(flightID ID, str letters, str figures)
{
	letters_ = letters;
	figures_ = figures;
}
str flightID::setFlightID(flightID ID, str figures, str letters)
{
	figures_ = figures;
	letters_ = letters;
}

// Операторы

bool flightID::operator==(const flightID& ID)
{
		return this->letters_ == letters_ && this->figures_ == ID.figures_;
}
bool flightID::operator!=(const flightID& number)
{
	return !operator==(number);
}