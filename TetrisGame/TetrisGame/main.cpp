#include <iostream>
#include <SFML/Graphics.hpp>
using namespace std;
int main()
{
	sf::RenderWindow window(sf::VideoMode(sf::VideoMode::getDesktopMode().width-20, sf::VideoMode::getDesktopMode().height-90), "SFML works!");
    sf::CircleShape shape(100.f);
	// so now im messing with the master
	shape.setFillColor(sf::Color::Magenta);
	double x=0;
	double y=0;
    while (window.isOpen())
    {
		
		sf::Event event;
		while( window.pollEvent(event)){
			if(event.type== sf::Event::Closed){
			window.close();}

			if (event.key.code == sf::Keyboard::Up)
    {  y-=50;
       
    }
		if (event.key.code == sf::Keyboard::Down)
    {
       y+=50;
    }
		if (event.key.code == sf::Keyboard::Left)
    {
       x-=50;
    }
		if (event.key.code == sf::Keyboard::Right)
    {
       x+=50;
    }
		
		
		
		}


		shape.setPosition(x,y);
        window.clear();
        window.draw(shape);
        window.display();
		x+=0.35;
		if(x>=sf::VideoMode::getDesktopMode().width-20)
			{x=0;
		y+=100;}

		if(y>=sf::VideoMode::getDesktopMode().height-90)
			{y=0;
		x=0;}
		
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
