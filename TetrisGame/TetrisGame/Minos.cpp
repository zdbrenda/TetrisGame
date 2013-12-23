#include "Minos.h"

Minos::Minos()
{   position=1;
	pivotM = 5;
}



int Minos::getPivot(){
	return 5;


}
int Minos::rotate()
{ int m=aCoor.getXCoordinate();
  int n=aCoor.getYCoordinate();
	
	switch(position)
   {case  1:
     {
		 bCoor.setXCoordinate(m-1);
		 bCoor.setYCoordinate(n);
		 cCoor.setXCoordinate(m);
		 cCoor.setYCoordinate(n+1);
		 dCoor.setXCoordinate(m+1);
		 dCoor.setYCoordinate(n);
		 position=2;
     }
    case  2:
		{
            bCoor.setXCoordinate(m);
			bCoor.setYCoordinate(n-1);
			cCoor.setXCoordinate(m-1);
			cCoor.setYCoordinate(n);
			dCoor.setXCoordinate(m);
			dCoor.setYCoordinate(n+1);
			position=3;
		}

	case  3:
		{


			bCoor.setXCoordinate(m+1);
			bCoor.setYCoordinate(n);
			cCoor.setXCoordinate(m);
			cCoor.setYCoordinate(n-1);
			dCoor.setXCoordinate(m-1);
			dCoor.setYCoordinate(n);
			position=4;



		}
	case  4:
   
		{
			bCoor.setXCoordinate(m);
			bCoor.setYCoordinate(n+1);
			cCoor.setXCoordinate(m+1);
			cCoor.setYCoordinate(n);
			dCoor.setXCoordinate(m);
			dCoor.setYCoordinate(n-1);
			position=1;
    }

}