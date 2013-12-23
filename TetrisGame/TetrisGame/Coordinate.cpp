#include "Coordinate.h";

Coordinate::Coordinate()
{
	x=0;
	y=0;
}

Coordinate::Coordinate(int m, int n)
{
	x=m;
	y=n;
}

int Coordinate::getXCoordinate()
{
	return x;
}

int Coordinate::getYCoordinate()
{
	return y;
}


void Coordinate::setXCoordinate(int m)
{
	x=m;
}

void Coordinate::setYCoordinate(int n)
{
	y=n;
}
Coordinate* Coordinate::getCoordinate()
{
	return this;
}

