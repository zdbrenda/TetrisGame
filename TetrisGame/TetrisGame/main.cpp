#include <iostream>
#include <SFML/Graphics.hpp>
using namespace std;
int main()
{
	sf::RenderWindow window(sf::VideoMode(sf::VideoMode::getDesktopMode().width-20, sf::VideoMode::getDesktopMode().height-90), "SFML works!");
    sf::CircleShape shape(100.f);
	// so now im messing with the master
    shape.setFillColor(sf::Color::Green);
	// this is a comment!ifovhkhvgrvr
	hgceikvc 
    while (window.isOpen())
    {
		//handles loops
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        window.draw(shape);
        window.display();
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
