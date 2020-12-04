#pragma once
#include "str.h"

class flightID
{
public:
	flightID();
	flightID(str letters, str figures);

	str getLetters(flightID ID);
	str getFigures(flightID ID);

	str setLetters(flightID ID, str letters);
	str setFigures(flightID ID, str figures);
	str setFlightID(flightID ID, str letters, str figures);
	str setFlightID(flightID ID, str figures, str letters);

	bool operator==(const flightID& ID);
	bool operator!=(const flightID& ID);

private:
	str letters_;
	str figures_;
};