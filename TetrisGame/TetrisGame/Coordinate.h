#pragma once
class Coordinate
{
	public:
		Coordinate();
		Coordinate(int,int);		
		int getXCoordinate();
		int getYCoordinate();
		void setXCoordinate(int);
		void setYCoordinate(int);
private:
	int x,y;

};

