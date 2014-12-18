#pragma once
#include "Minos.h"
#include "Coordinate.h"
#include <string>
#include <vector>
#include <iostream>
#include <SFML\System.hpp>

Minos::Minos()// wil randomly generate type
{   const int RANGE=7;
type = (rand()%RANGE)+1;
nextPosition=2;

aCoor = Coordinate(4,1);//always 4,1
if(type==1){
	//T shape
	bCoor = Coordinate(3,1);
	cCoor = Coordinate(5,1);
	dCoor = Coordinate(4,2);
	aBound=false;
	bBound=true;
	cBound=true;
	dBound=true;

}else if(type==2){
	//I shape		
	bCoor = Coordinate(3,1);
	cCoor = Coordinate(5,1);
	dCoor = Coordinate(6,1);
	aBound=true;
	bBound=true;
	cBound=true;
	dBound=true;}
else if (type==3){
	//O shape
	bCoor = Coordinate(5,1);
	cCoor = Coordinate(4,2);
	dCoor = Coordinate(5,2);
	aBound=true;
	bBound=true;
	cBound=true;
	dBound=true;
}
else if (type==4){
	//J shape
	bCoor = Coordinate(3,1);
	cCoor = Coordinate(5,1);
	dCoor = Coordinate(5,2);
	aBound=true;
	bBound=true;
	cBound=true;
	dBound=true;
}
else if (type==5){
	//L shape
	bCoor = Coordinate(3,1);
	cCoor = Coordinate(5,1);
	dCoor = Coordinate(3,2);
	aBound=true;
	bBound=true;
	cBound=true;
	dBound=true;
}
else if (type==6){
	//Z shape
	bCoor = Coordinate(3,1);
	cCoor = Coordinate(4,2);
	dCoor = Coordinate(5,2);
	aBound=true;
	bBound=true;
	cBound=true;
	dBound=true;
}
else if (type==7){
	//S shape
	bCoor = Coordinate(3,2);
	cCoor = Coordinate(4,2);
	dCoor = Coordinate(5,1);
	aBound=true;
	bBound=true;
	cBound=true;
	dBound=true;
}

}

Minos::Minos(int shapeType)// get prefered type
{   



}




int Minos::getHeight()
{   int  newA[4];
newA[0]=aCoor.getYCoordinate();
newA[1]=bCoor.getYCoordinate();
newA[2]=cCoor.getYCoordinate();
newA[3]=dCoor.getYCoordinate();

int min=newA[0], max=newA[0];
for(int i=1;i<=3;i++)
{
	if(newA[i]<min)
		min=newA[i];
	if(newA[i]>max)
		max=newA[i];
}
return (max-min);
}


void Minos::setBounds(std::string s)
{  
	//finds height
	int  newA[4];
	newA[0]=aCoor.getYCoordinate();
	newA[1]=bCoor.getYCoordinate();
	newA[2]=cCoor.getYCoordinate();
	newA[3]=dCoor.getYCoordinate();

	int minH=newA[0], maxH=newA[0];
	for(int i=1;i<=3;i++)
	{
		if(newA[i]<minH)
			minH=newA[i];
		if(newA[i]>maxH)
			maxH=newA[i];
	}

	int  newB[4];
	newB[0]=aCoor.getXCoordinate();
	newB[1]=bCoor.getXCoordinate();
	newB[2]=cCoor.getXCoordinate();
	newB[3]=dCoor.getXCoordinate();
	int minW=newB[0], maxW=newB[0];
	for(int i=1;i<=3;i++)
	{
		if(newB[i]<minW)
			minW=newB[i];
		if(newB[i]>maxW)
			maxW=newB[i];
	}
	dBound=cBound=bBound=aBound=false;

	for(int m = minW;m<=maxW;m++){
		for (int n = minH;n<=maxH;n++){
			if(m==aCoor.getXCoordinate()&&n==aCoor.getYCoordinate())
				aBound=true;
			else if (m==bCoor.getXCoordinate()&&n==bCoor.getYCoordinate())
				bBound=true;
			else if(m==cCoor.getXCoordinate()&&n==cCoor.getYCoordinate())
				cBound=true;
			else if(m==dCoor.getXCoordinate()&&n==dCoor.getYCoordinate())
				dBound=true;

		}

	}
}

Minos::~Minos(){}

void Minos::movePivot(int x, int y){
	aCoor.setXCoordinate(aCoor.getXCoordinate()+x);
	aCoor.setYCoordinate(aCoor.getYCoordinate()+y);
	bCoor.setXCoordinate(bCoor.getXCoordinate()+x);
	bCoor.setYCoordinate(bCoor.getYCoordinate()+y);
	cCoor.setXCoordinate(cCoor.getXCoordinate()+x);
	cCoor.setYCoordinate(cCoor.getYCoordinate()+y);
	dCoor.setXCoordinate(dCoor.getXCoordinate()+x);
	dCoor.setYCoordinate(dCoor.getYCoordinate()+y);
}

void Minos::rotate(int type, std::vector <std::vector <int> > grid )
{
	int m=aCoor.getXCoordinate();
	int n=aCoor.getYCoordinate();


	if (type==1){//T
		switch(nextPosition)
		{case  1:
		{
			bCoor.setXCoordinate(m-1);
			bCoor.setYCoordinate(n);
			cCoor.setXCoordinate(m+1);
			cCoor.setYCoordinate(n);
			dCoor.setXCoordinate(m);
			dCoor.setYCoordinate(n+1);
			aBound=false;
			bBound=true;
			cBound=true;
			dBound=true;
			nextPosition=2;
			break;
		}
		case  2:
			{
				bCoor.setXCoordinate(m);
				bCoor.setYCoordinate(n-1);
				cCoor.setXCoordinate(m);
				cCoor.setYCoordinate(n+1);
				dCoor.setXCoordinate(m-1);
				dCoor.setYCoordinate(n);
				nextPosition=3;


				aBound=false;
				bBound=false;
				cBound=true;
				dBound=true;
				break;
			}

		case  3:
			{


				bCoor.setXCoordinate(m+1);
				bCoor.setYCoordinate(n);
				cCoor.setXCoordinate(m-1);
				cCoor.setYCoordinate(n);
				dCoor.setXCoordinate(m);
				dCoor.setYCoordinate(n-1);
				aBound=true;
				bBound=true;
				cBound=true;
				dBound=false;
				nextPosition=4;

				break;

			}
		case  4:

			{
				bCoor.setXCoordinate(m);
				bCoor.setYCoordinate(n+1);
				cCoor.setXCoordinate(m);
				cCoor.setYCoordinate(n-1);
				dCoor.setXCoordinate(m+1);
				dCoor.setYCoordinate(n);
				cBound=false;
				aBound=false;
				dBound=true;
				bBound=true;
				nextPosition=1;
				break;
			}
		}
	}
	else if(type==2){//I
		switch(nextPosition)
		{case  1:
		{
			bCoor.setXCoordinate(m-1);
			bCoor.setYCoordinate(n);
			cCoor.setXCoordinate(m+1);
			cCoor.setYCoordinate(n);
			dCoor.setXCoordinate(m+2);
			dCoor.setYCoordinate(n);
			aBound=true;
			bBound=true;
			cBound=true;
			dBound=true;
			nextPosition=2;
			break;
		}
		case  2:
			{
				bCoor.setXCoordinate(m);
				bCoor.setYCoordinate(n-1);
				cCoor.setXCoordinate(m);
				cCoor.setYCoordinate(n+1);
				dCoor.setXCoordinate(m);
				dCoor.setYCoordinate(n+2);
				nextPosition=3;


				aBound=true;
				bBound=true;
				cBound=true;
				dBound=true;
				break;
			}

		case  3:
			{


				bCoor.setXCoordinate(m+1);
				bCoor.setYCoordinate(n);
				cCoor.setXCoordinate(m-1);
				cCoor.setYCoordinate(n);
				dCoor.setXCoordinate(m-2);
				dCoor.setYCoordinate(n);
				aBound=true;
				bBound=true;
				cBound=true;
				dBound=true;
				nextPosition=4;

				break;

			}
		case  4:

			{
				bCoor.setXCoordinate(m);
				bCoor.setYCoordinate(n+1);
				cCoor.setXCoordinate(m);
				cCoor.setYCoordinate(n-1);
				dCoor.setXCoordinate(m);
				dCoor.setYCoordinate(n-2);
				aBound=true;
				bBound=true;
				cBound=true;
				dBound=true;
				nextPosition=1;
				break;
			}
		}
	}else if(type==4){//J piece
		switch(nextPosition)
		{case  1:
		{
			bCoor.setXCoordinate(m-1);
			bCoor.setYCoordinate(n);
			cCoor.setXCoordinate(m+1);
			cCoor.setYCoordinate(n);
			dCoor.setXCoordinate(m+1);
			dCoor.setYCoordinate(n+1);
			aBound=true;
			bBound=true;
			cBound=true;
			dBound=true;
			nextPosition=2;
			break;
		}
		case  2:
			{
				bCoor.setXCoordinate(m);
				bCoor.setYCoordinate(n-1);
				cCoor.setXCoordinate(m);
				cCoor.setYCoordinate(n+1);
				dCoor.setXCoordinate(m-1);
				dCoor.setYCoordinate(n+1);
				nextPosition=3;

				aBound=true;
				bBound=true;
				cBound=true;
				dBound=true;
				break;
			}

		case  3:
			{


				bCoor.setXCoordinate(m+1);
				bCoor.setYCoordinate(n);
				cCoor.setXCoordinate(m-1);
				cCoor.setYCoordinate(n);
				dCoor.setXCoordinate(m-1);
				dCoor.setYCoordinate(n-1);
				aBound=true;
				bBound=true;
				cBound=true;
				dBound=true;
				nextPosition=4;

				break;

			}
		case  4:

			{
				bCoor.setXCoordinate(m);
				bCoor.setYCoordinate(n+1);
				cCoor.setXCoordinate(m);
				cCoor.setYCoordinate(n-1);
				dCoor.setXCoordinate(m+1);
				dCoor.setYCoordinate(n-1);
				aBound=true;
				bBound=true;
				cBound=true;
				dBound=true;
				nextPosition=1;
				break;
			}
		}

	}
	else if(type==5){//L
		switch(nextPosition)
		{case  1:
		{
			bCoor.setXCoordinate(m-1);
			bCoor.setYCoordinate(n);
			cCoor.setXCoordinate(m+1);
			cCoor.setYCoordinate(n);
			dCoor.setXCoordinate(m-1);
			dCoor.setYCoordinate(n+1);
			aBound=true;
			bBound=true;
			cBound=true;
			dBound=true;
			nextPosition=2;
			break;
		}
		case  2:
			{
				bCoor.setXCoordinate(m);
				bCoor.setYCoordinate(n-1);
				cCoor.setXCoordinate(m);
				cCoor.setYCoordinate(n+1);
				dCoor.setXCoordinate(m-1);
				dCoor.setYCoordinate(n-1);
				nextPosition=3;

				aBound=true;
				bBound=true;
				cBound=true;
				dBound=true;
				break;
			}

		case  3:
			{


				bCoor.setXCoordinate(m+1);
				bCoor.setYCoordinate(n);
				cCoor.setXCoordinate(m-1);
				cCoor.setYCoordinate(n);
				dCoor.setXCoordinate(m+1);
				dCoor.setYCoordinate(n-1);
				aBound=true;
				bBound=true;
				cBound=true;
				dBound=true;
				nextPosition=4;

				break;

			}
		case  4:

			{
				bCoor.setXCoordinate(m);
				bCoor.setYCoordinate(n+1);
				cCoor.setXCoordinate(m);
				cCoor.setYCoordinate(n-1);
				dCoor.setXCoordinate(m+1);
				dCoor.setYCoordinate(n+1);
				aBound=true;
				bBound=true;
				cBound=true;
				dBound=true;
				nextPosition=1;
				break;
			}
		}

	}
else if(type==6){//Z piece
		switch(nextPosition)
		{case  1:
		{
			bCoor.setXCoordinate(m-1);
			bCoor.setYCoordinate(n);
			cCoor.setXCoordinate(m);
			cCoor.setYCoordinate(n+1);
			dCoor.setXCoordinate(m+1);
			dCoor.setYCoordinate(n+1);
			aBound=true;
			bBound=true;
			cBound=true;
			dBound=true;
			nextPosition=2;
			break;
		}
		case  2:
			{
				bCoor.setXCoordinate(m);
				bCoor.setYCoordinate(n-1);
				cCoor.setXCoordinate(m-1);
				cCoor.setYCoordinate(n);
				dCoor.setXCoordinate(m-1);
				dCoor.setYCoordinate(n+1);
				nextPosition=3;

				aBound=true;
				bBound=true;
				cBound=true;
				dBound=true;
				break;
			}

		case  3:
			{


				bCoor.setXCoordinate(m+1);
				bCoor.setYCoordinate(n);
				cCoor.setXCoordinate(m);
				cCoor.setYCoordinate(n-1);
				dCoor.setXCoordinate(m-1);
				dCoor.setYCoordinate(n-1);
				aBound=true;
				bBound=true;
				cBound=true;
				dBound=true;
				nextPosition=4;

				break;

			}
		case  4:

			{
				bCoor.setXCoordinate(m);
				bCoor.setYCoordinate(n+1);
				cCoor.setXCoordinate(m+1);
				cCoor.setYCoordinate(n);
				dCoor.setXCoordinate(m+1);
				dCoor.setYCoordinate(n-1);
				aBound=true;
				bBound=true;
				cBound=true;
				dBound=true;
				nextPosition=1;
				break;
			}
		}

	}else if(type==7){//S piece
		switch(nextPosition)
		{case  1:
		{
			bCoor.setXCoordinate(m+1);
			bCoor.setYCoordinate(n);
			cCoor.setXCoordinate(m);
			cCoor.setYCoordinate(n+1);
			dCoor.setXCoordinate(m-1);
			dCoor.setYCoordinate(n+1);
			aBound=true;
			bBound=true;
			cBound=true;
			dBound=true;
			nextPosition=2;
			break;
		}
		case  2:
			{
				bCoor.setXCoordinate(m);
				bCoor.setYCoordinate(n+1);
				cCoor.setXCoordinate(m-1);
				cCoor.setYCoordinate(n);
				dCoor.setXCoordinate(m-1);
				dCoor.setYCoordinate(n-1);
				nextPosition=3;

				aBound=true;
				bBound=true;
				cBound=true;
				dBound=true;
				break;
			}

		case  3:
			{


				bCoor.setXCoordinate(m-1);
				bCoor.setYCoordinate(n);
				cCoor.setXCoordinate(m);
				cCoor.setYCoordinate(n-1);
				dCoor.setXCoordinate(m+1);
				dCoor.setYCoordinate(n-1);
				aBound=true;
				bBound=true;
				cBound=true;
				dBound=true;
				nextPosition=4;

				break;

			}
		case  4:

			{
				bCoor.setXCoordinate(m);
				bCoor.setYCoordinate(n-1);
				cCoor.setXCoordinate(m+1);
				cCoor.setYCoordinate(n);
				dCoor.setXCoordinate(m+1);
				dCoor.setYCoordinate(n+1);
				aBound=true;
				bBound=true;
				cBound=true;
				dBound=true;
				nextPosition=1;
				break;
			}
		}

	}


	if(bCoor.getXCoordinate()<0||cCoor.getXCoordinate()<0||dCoor.getXCoordinate()<0){			

		nextPosition= ((nextPosition+5)%4)+1;
		
		rotate(type,grid);

	}
	if(bCoor.getXCoordinate()>9||cCoor.getXCoordinate()>9||dCoor.getXCoordinate()>9){			

		nextPosition= ((nextPosition+5)%4)+1;
		
		rotate(type,grid);

	}

	if(grid[aCoor.getXCoordinate()][aCoor.getYCoordinate()]!=0
		||grid[bCoor.getXCoordinate()][bCoor.getYCoordinate()]!=0
		||grid[cCoor.getXCoordinate()][cCoor.getYCoordinate()]!=0
		||grid[dCoor.getXCoordinate()][dCoor.getYCoordinate()]!=0)
	{
		nextPosition= ((nextPosition+5)%4)+1;
		
		rotate(type,grid);
	}

	
}