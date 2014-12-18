#pragma once
#include "Model.h"
#include "iostream"
#include "Coordinate.h"

using namespace std;



Model::Model()
{
	grid=std::vector <std::vector <int> > (10,std::vector<int>(20));

}

void Model::claimOccupied(Coordinate a, Coordinate b, Coordinate c, Coordinate d,int type)
{
	grid[a.getXCoordinate()][a.getYCoordinate()]=type;
	grid[b.getXCoordinate()][b.getYCoordinate()]=type;
	grid[c.getXCoordinate()][c.getYCoordinate()]=type;
	grid[d.getXCoordinate()][d.getYCoordinate()]=type;
	
}



void Model::display()
{
	int i=0,j=0;
	for(i=0;i<grid[0].size();i++)
	{
		for(j=0;j<grid.size();j++)
		{
			std::cout<<grid[j][i];

		}
		std::cout<<endl;
	}
	cout<<endl;
}
