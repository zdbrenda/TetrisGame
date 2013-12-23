#include "Model.h"
#include "iostream"
using namespace std;



Model::Model()
{
	grid=std::vector <std::vector <int> > (10,std::vector<int>(20));
	
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

}
