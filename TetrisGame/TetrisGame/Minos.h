#include "Coordinate.h"


class Minos
{
public:
	Minos();
	~ Minos();
	int rotate();
	

private:
int position;
int pivotM;
int getPivot();
Coordinate aCoor;
Coordinate bCoor;
Coordinate cCoor;
Coordinate dCoor;
};

 