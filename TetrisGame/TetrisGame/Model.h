#pragma once
#include <vector>
#include "Coordinate.h"
class Model
{
public:
Model();
void display();
void claimOccupied(Coordinate a, Coordinate b, Coordinate c, Coordinate d,int type);
std:: vector  <std::vector  <int> > getGrid(){return grid;}
void setGrid(std:: vector  <std::vector  <int> > newGrid){ grid= newGrid;}
 
private:
	std:: vector  <std::vector  <int> > grid;

};