class Coordinate
{
	public :
		Coordinate();
		Coordinate(int,int);
		Coordinate* getCoordinate();
		int getXCoordinate();
		int getYCoordinate();
		void setXCoordinate(int);
		void setYCoordinate(int);
private :
	int x,y;

};

