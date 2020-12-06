#pragma once
#include "str.h"

class flightID
{
public:
	flightID();
	flightID(str letters, str figures);

	str getLetters(flightID ID);
	str getFigures(flightID ID);

	void setLetters(flightID ID, str letters);
	void setFigures(flightID ID, str figures);
	void setFlightID(flightID ID, str letters, str figures);

	bool operator==(const flightID& ID);
	bool operator!=(const flightID& ID);

private:
	str letters_;
	str figures_;
};