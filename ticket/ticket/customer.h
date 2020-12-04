#pragma once
#include "str.h"

class customer
{
public:
	customer();
	customer(str name, str surname);

	void setName(const str& newName);
	void setSurname(const str& newSurname);

	str getName() const;
	str getSurname() const;

	friend std::ostream& operator<<(std::ostream& out, const customer& customer);
	friend std::istream& operator>>(std::istream& in, customer& customer);
	bool operator==(const customer& customer);
	bool operator!=(const customer& customer);

private:
	str name_;
	str surname_;
};
