#include "customer.h"
#include "str.h"
#include <iostream>

// Конструкторы

customer::customer() :
	name_(nullptr),
	surname_(nullptr)
{}
customer::customer(str name, str surname) :
	name_(name),
	surname_(surname_)
{}

// Сеттеры

void customer::setName(const str& newName)
{
	name_ = newName;
}
void customer::setSurname(const str& newSurname)
{
	surname_ = newSurname;
}

// Геттеры

str customer::getName() const
{
	return name_;
}
str customer::getSurname() const
{
	return surname_;
}

// Операторы

std::ostream& operator<<(std::ostream& stream, const customer& customer)
{
	stream << customer.name_ << " " << customer.surname_;
}
std::istream& operator>>(std::istream& input, customer& customer)
{
	input >> customer.name_ >> customer.surname_;
}
bool customer::operator==(const customer& customer)
{
	return name_ == customer.name_ && surname_ == customer.surname_;
}
bool customer::operator!=(const customer& customer)
{
	return !operator==(nas);
}