#pragma once
#include "Coordinate.h"
#include <string>
#include <vector>
class Minos
{

public:
	Minos();
	Minos(int shapeType);
	~Minos();
	void rotate(int shapeType,  std::vector<std::vector <int> > grid );
	Coordinate getACoor(){return aCoor;}
	Coordinate getBCoor(){return bCoor;}
	Coordinate getCCoor(){return cCoor;}
	Coordinate getDCoor(){return dCoor;}
	bool isABound(){return aBound;}
	bool isBBound(){return bBound;}
	bool isCBound(){return cBound;}
	bool isDBound(){return dBound;}
	void movePivot(int difx, int dify);
	int getHeight();
	int getWidth();
	void setBounds(std::string);
	int getType(){return type;}

private:
	int type;
	int nextPosition;
	int pivotM;
	int getPivot();
	Coordinate aCoor;
	Coordinate bCoor;
	Coordinate cCoor;
	Coordinate dCoor;
	bool aBound;
	bool bBound;
	bool cBound;
	bool dBound;

};

