#include <iostream>
#include <SFML/Graphics.hpp>
#include <windows.h>
#include "Model.h"


using namespace std;


int main()
{   Model m=Model() ;
	m.display();
	float x_dir=200;
    float y_dir=400;
	sf::RenderWindow window(sf::VideoMode(y_dir*0.5, y_dir), "SFML works!");
    sf::RectangleShape shapey(sf::Vector2f(x_dir,1));
	sf::RectangleShape shapex(sf::Vector2f(1,y_dir));
	sf::Color color(232,7,5,233);
	
	// so now im messing with the master
	shapey.setFillColor(sf::Color::Magenta);shapex.setFillColor(sf::Color::Magenta);
	float scale=(float)window.getSize().y/20.0;
	cout<< scale;
	sf::RectangleShape squares(sf::Vector2f(scale-1,scale-1));
	sf::RectangleShape OShape(sf::Vector2f(2*scale-1,2*scale-1));
	squares.setFillColor(color);
	double x=0;
	double y=0;
    while (window.isOpen())
    {
		
		sf::Event event;
		while( window.pollEvent(event)){
			
			if(event.type== sf::Event::Closed){
			window.close();}
			if (event.type== sf::Event::KeyReleased){
			if (event.key.code == sf::Keyboard::Up)
    {  y-=1;
       
			}if (event.key.code == sf::Keyboard::R)
    {  shapey.rotate(30);
       
    }
		if (event.key.code == sf::Keyboard::Down)
    {
       y+=1;
    }
		if (event.key.code == sf::Keyboard::Left)
    {
       x-=1;
    }
		if (event.key.code == sf::Keyboard::Right)
    {
       x+=1;
    }
			}
		
		
		}


        window.clear();
    
	squares.setPosition(1+x*scale,1+y*scale);	
		
	
	
	
	for(int m=scale;m<window.getSize().y;m+=scale)
	{
		shapey.setPosition(0,m);
		window.draw(shapey);
	}

		window.draw(OShape);
		for(int m=scale;m<window.getSize().x;m+=scale)
	{
		shapex.setPosition(m,0);
		window.draw(squares);
		window.draw(shapex);
		
	}
        window.display();
		/*x+=0.35;
		if(x>=sf::VideoMode::getDesktopMode().width-20)
			{x=0;
		y+=100;}

		if(y>=sf::VideoMode::getDesktopMode().height-90)
			{y=0;
		x=0;}*/
		
    }

    return 0;
}

void outputter(){

cout<<"im anonymous"<<endl;
system("pause");

 }
void intputter(){

cout<<"im anonymous"<<endl;
system("pause");

 }
