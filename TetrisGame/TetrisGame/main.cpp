#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include <windows.h>
#include "Model.h"
#include "Minos.h"
#include "Coordinate.h"
#include <ctime>
#include<cstdlib>
#include <queue>
#include <fstream>
#include <sstream>

using namespace std;
static int score=0;
static int totalLines=0;
static int level=1;
static int piecesDrop=0;

std::vector <std::vector <int> > removeLine(Minos minos, std::vector <std::vector <int> > grid)
{
	minos.setBounds("down");
	int  newA[4];
	int counter=0;

	newA[0]=minos.getACoor().getYCoordinate();
	newA[1]=minos.getBCoor().getYCoordinate();
	newA[2]=minos.getCCoor().getYCoordinate();
	newA[3]=minos.getDCoor().getYCoordinate();

	int minH=newA[0], maxH=newA[0];
	for(int i=1;i<=3;i++)
	{
		if(newA[i]<minH)
			minH=newA[i];
		if(newA[i]>maxH)
			maxH=newA[i];
	}

	int number=maxH-minH+1;
	std::vector <bool> removable(number,true);

	int n=0;


	for(int i=minH;i<=maxH;i++)
	{		
		for(int j=0;j<10;j++)
		{			
			if(grid[j][i]==0 && removable[n] ==true)
			{
				removable[n]=false;
				/*cout<<"minH is"<<minH<<endl;
				cout<<"maxH is"<<maxH<<endl;
				cout<<" Checked till x="<<j<<"y"<<i<<endl;				
				cout<<endl;
				cout<<"line n= "<<n<< " is not removable"<<endl;*/

			}


		}
		n++;
		//cout<<endl;cout<<endl;cout<<endl;cout<<endl;
	}


	for(int i=0;i<=n;i++)// automatic line clear
	{
		if (removable[i]==true)//remove the line and move every line above the line down one line
		{   counter++;
		for (int j=minH+i;j>0;j--)
		{

			for(int m=0;m<10;m++)
			{
				grid[m][j]=grid[m][j-1];

			}
		}
		}

	}
	switch(counter)
	{
	case 1:
		score+=100;
		totalLines+=1;
		break;

	case 2:
		score+=300;
		totalLines+=2;
		break;
	case 3:
		score+=800;
		totalLines+=3;
		break;
	case 4:
		score+=1500;
		totalLines+=4;
		break;

	}

	//check likes cleared
	return grid;

}

//done goes in ctrl
bool canDrop(Minos minos, std::vector <std::vector <int> > grid){
	if(minos.isABound()){
		if (minos.getACoor().getYCoordinate()+1 >=20 ||grid[minos.getACoor().getXCoordinate()][minos.getACoor().getYCoordinate()+1]!=0)
			return false;
	}
	if(minos.isBBound()){
		if (minos.getBCoor().getYCoordinate()+1 >=20||grid[minos.getBCoor().getXCoordinate()][minos.getBCoor().getYCoordinate()+1]!=0)
			return false;
	}
	if(minos.isCBound()){
		if (minos.getCCoor().getYCoordinate()+1 >=20||grid[minos.getCCoor().getXCoordinate()][minos.getCCoor().getYCoordinate()+1]!=0)
			return false;
	}
	if(minos.isDBound()){		
		if (minos.getDCoor().getYCoordinate()+1 >=20||grid[minos.getDCoor().getXCoordinate()][minos.getDCoor().getYCoordinate()+1]!=0)
			return false;
	}


	return true;
}
//done goes in ctrl
bool canStrafe(Minos minos, std::string s,std::vector <std::vector <int> > grid){
	minos.setBounds(s);//set where bounds are

	//left check
	if (s=="left"){
		if(minos.isABound()){
			if (minos.getACoor().getXCoordinate()-1 <0|| grid[minos.getACoor().getXCoordinate()-1][minos.getACoor().getYCoordinate()]!=0)
				return false;
		}
		if(minos.isBBound()){
			if (minos.getBCoor().getXCoordinate()-1 <0|| grid[minos.getBCoor().getXCoordinate()-1][minos.getBCoor().getYCoordinate()]!=0)
				return false;
		}
		if(minos.isCBound()){
			if (minos.getCCoor().getXCoordinate()-1 <0|| grid[minos.getCCoor().getXCoordinate()-1][minos.getCCoor().getYCoordinate()]!=0)
				return false;
		}
		if(minos.isDBound()){
			if (minos.getDCoor().getXCoordinate()-1 <0|| grid[minos.getDCoor().getXCoordinate()-1][minos.getDCoor().getYCoordinate()]!=0)
				return false;
		}
	}else{

		if(minos.isABound()){
			if (minos.getACoor().getXCoordinate()+1 >=10|| grid[minos.getACoor().getXCoordinate()+1][minos.getACoor().getYCoordinate()]!=0)
				return false;
		}
		if(minos.isBBound()){
			if (minos.getBCoor().getXCoordinate()+1 >=10|| grid[minos.getBCoor().getXCoordinate()+1][minos.getBCoor().getYCoordinate()]!=0)
				return false;
		}
		if(minos.isCBound()){
			if (minos.getCCoor().getXCoordinate()+1 >=10|| grid[minos.getCCoor().getXCoordinate()+1][minos.getCCoor().getYCoordinate()]!=0)
				return false;
		}
		if(minos.isDBound()){
			if (minos.getDCoor().getXCoordinate()+1 >=10|| grid[minos.getDCoor().getXCoordinate()+1][minos.getDCoor().getYCoordinate()]!=0)
				return false;
		}



	}




	return true;
}
//done goes in ctrl

bool isGameOver(std::vector <std::vector <int> > grid){
	for(int i= 0;i<10;i++ ){
		if (grid[i][1]!=0)
			return true;	
	}
	return false;
}

float updateLevel()
{  
	piecesDrop++;
	/*cout<<"&&&&&&&&&&&& We have droped "<<piecesDrop<<endl;
	cout<<"&&&&&&&&&&&& We have level "<<level<<endl;*/
	if(piecesDrop%10==0)
	{level++;
	/*  cout<<level<<endl;*/
	return 0.8;  
	}
	return 1;
}

std::vector <string> splitLine(string line , char delimiter){
	std::stringstream ss(line);
	std::vector <string> elements;
	string element;
	while(std::getline(ss,element,delimiter)){
		elements.push_back(element);
	}
	return elements;
}


std::vector <std::vector <string>  > quickSort(std::vector <std::vector <string>  > scoreTable )
{   
	std::vector <std::vector <string>  > newArray(4,std::vector<string >(10));

	int max;
	int i=0;
	int n=0;
	int c=-1;

	for(int j=0;j<10;j++)
	{  

		max=atoi(scoreTable[0][j].c_str());
		for(i=0;i<10;i++)
		{  

			if (atoi(scoreTable[0][i].c_str())>max)
			{
				max=atoi(scoreTable[0][i].c_str());
				n=i;
			}

		}

		for(i=0;i<4;i++)
		{
			newArray[i][j]=scoreTable[i][n];
			cout<<newArray[0][j]<< endl;

		}
		scoreTable[0][n]=std::string("0");
	}
	return newArray;
}


void saveScore(int score, string name, int level, int lines)
{

	fstream newFile("highscores.txt",std::ios_base::in);
	string entry;
	bool highScore=false;
	std::vector <std::vector <string>  > line(10,std::vector<string >(4));
	if(newFile.is_open())
	{   
		for(int i=0;i<=9;i++)
		{
			getline(newFile,entry);
			string temp=splitLine(entry,',')[0];
			/*if(score <= atoi(line[i][0].c_str())&& score>=atoi(line[i+1][0].c_str())&&i<=8)
			highScore=true;
			else if(score>=atoi(line[0][0].c_str()))
			highScore=true;*/
			if(score>atoi(temp.c_str())){
				if(i==9){
					line[i][0]=std::to_string(score); //new high score to save
					line[i][1]=name;
					line[i][2]=std::to_string(level);
					line[i][3]=std::to_string(lines);
					//last place
				}else{// 
					line[i][0]=std::to_string(score); //new high score to save
					line[i][1]=name;
					line[i][2]=std::to_string(level);
					line[i][3]=std::to_string(lines);				

					for(i; i<=8;i++){
						line[i+1]=splitLine(entry,',');
						getline(newFile,entry);
					}




				}

			}else{
				line[i]=splitLine(entry,',');
			}
		}
	}
	newFile.close();

	fstream newWrite("highscores.txt", std::ios_base::out);
	if(newWrite.is_open()){
		for (int j= 0; j <10;j++){

			newWrite << line[j][0]<<",";
			newWrite << line[j][1]<<",";
			newWrite << line[j][2]<<",";
			newWrite << line[j][3]<<endl;
		}
	}
	newWrite.close();

}

bool isHighScore(int score)
{   
	fstream newFile("highscores.txt",std::ios_base::in);

	string entry;
	bool highScore=false;
	std::vector <std::vector <string>  > line(10,std::vector<string >(4));
	if(newFile.is_open())
	{   
		for(int i=0;i<=9;i++)
		{
			getline(newFile,entry);
			
		}

	}

	newFile.close();
string temp=splitLine(entry,',')[0];
	
	return(score>=atoi(temp.c_str()));
}




int main()
{   sf::Font font;
font.loadFromFile("font.ttf");
float GAMESPEED =1000; 
srand((unsigned)time(0));
Model m=Model() ;
queue <Minos> minosQ;
minosQ.push(Minos());
minosQ.push(Minos());


sf::Texture gameOverRes;
if (!gameOverRes.loadFromFile("gameover.png")||!font.loadFromFile("font.ttf")){	
	cout<<"holy crap cant find it";}
sf::Text scores;
sf::Text lines;
sf::Text levelTxt;
levelTxt.setString("Level "+std::to_string(level));
scores.setString("Score "+std::to_string(score));
lines.setString("Lines "+std::to_string(totalLines));
gameOverRes.setSmooth(true);
lines.setPosition(235,170);
lines.setFont(font);
lines.setCharacterSize(20);
levelTxt.setPosition(235,90);
levelTxt.setFont(font);
levelTxt.setCharacterSize(20);
scores.setPosition(235,130);
scores.setFont(font);
scores.setCharacterSize(20);
sf::Sprite gameOver;
gameOver.setTexture(gameOverRes);
gameOver.setScale(0.5,0.5);
gameOver.setPosition(18,100);

sf::Color palette[7]={sf::Color(87,95,217,255),
	sf::Color(55,222,78,255),
	sf::Color(232,121,225,255),
	sf::Color(247,28,10,255),
	sf::Color(247,247,16,255),
	sf::Color(16,247,247,255),
	sf::Color(247,189,16,255)};



float x_dir=200;
const float y_dir=400;
sf::RenderWindow window(sf::VideoMode(y_dir*0.5+170, y_dir), "SFML works!");


sf::RectangleShape shapey(sf::Vector2f(x_dir,1));
sf::RectangleShape shapex(sf::Vector2f(1,y_dir));
sf::RectangleShape panelWall(sf::Vector2f(5,y_dir));
sf::Color color(232,7,5,233);
// so now im messing with the master
shapey.setFillColor(sf::Color::Magenta);shapex.setFillColor(sf::Color::Magenta);
float scale=(float)window.getSize().y/20.0;
float squSize = 40;
//cout<< scale;
sf::RectangleShape squares(sf::Vector2f(scale-1,scale-1));

sf::Text newText;
newText.setFont(font);
newText.setColor(sf::Color::Yellow);
newText.setPosition(0,100);
newText.setCharacterSize(30);
string newString;
sf::Text text;
text.setFont(font);
text.setColor(sf::Color::Yellow);
text.setPosition(0,0);
text.setCharacterSize(30);
text.setString("New High Score! \nPlease enter your name: ");


squares.setFillColor(color);
double x=0;
double y=0;
sf::Clock dropClock;
sf::Time elapsed;
while (window.isOpen())
{
	///////////////////////////////////////////GAMEPLAY
	elapsed=dropClock.getElapsedTime();	
	if(elapsed.asMilliseconds()>=GAMESPEED){			
		if(canDrop(minosQ.front(), m.getGrid())){
			dropClock.restart();
			minosQ.front().movePivot(0,1);
			//cout<<minosQ.front().getACoor().getYCoordinate()<<endl;
		}else{
			//freeze and write to array
			m.claimOccupied(minosQ.front().getACoor(),minosQ.front().getBCoor(),minosQ.front().getCCoor(),minosQ.front().getDCoor(),minosQ.front().getType());

			m.setGrid(removeLine(minosQ.front(),m.getGrid()));
			GAMESPEED*=updateLevel();

			scores.setString("Score " + std::to_string(score));
			lines.setString("Lines "+ std::to_string(totalLines));
			levelTxt.setString("Level "+std::to_string(level));
			scores.setPosition(235,130);
			scores.setFont(font);
			scores.setCharacterSize(20);
			minosQ.pop();

			if(isGameOver(m.getGrid())){
				cout<<endl<<"Game Over"<<endl;	

				if(isHighScore(score))
				{
					bool isDone=false;
					sf::Event event;
					while(!isDone){     
						while( window.pollEvent(event)){

							if(event.type== sf::Event::KeyReleased){
								if(event.key.code == sf::Keyboard::Return){
									isDone=true;

								}
							}else if (event.type == sf::Event::TextEntered)      //if the user enters something from the keyboard
							{
								if (event.text.unicode < 128&& event.text.unicode!=13){
									newString+=static_cast<char>(event.text.unicode);
									newText.setString(newString);}
							}
						}

						window.clear();
						window.draw(gameOver);
						window.draw(text);
						window.draw(newText);						
						window.display();
						
					}
				}
				saveScore(score,newString,level,totalLines);
						//show scores
				system("pause");	
			}
			minosQ.push(Minos());//drop new piece
		}
	}


	////////////////////////////////HANDLERS
	sf::Event event;
	while( window.pollEvent(event)){

		if(event.type== sf::Event::Closed){
			window.close();}



		if (event.type== sf::Event::KeyReleased){
			if (event.key.code == sf::Keyboard::Up)
			{  minosQ.front().rotate(minosQ.front().getType(), m.getGrid());

			}
			if (event.key.code == sf::Keyboard::Return)
			{  system("pause");

			}
			if (event.key.code == sf::Keyboard::R)
			{  shapey.rotate(30);


			}
			if (event.key.code == sf::Keyboard::Down)
			{
				if(canDrop(minosQ.front(),m.getGrid()))
					minosQ.front().movePivot(0,1);
			}
			if (event.key.code == sf::Keyboard::Left)
			{
				if (canStrafe(minosQ.front(),"left",m.getGrid()))
					minosQ.front().movePivot(-1,0);
			}
			if (event.key.code == sf::Keyboard::Right)
			{
				if (canStrafe(minosQ.front(),"right",m.getGrid()))
					minosQ.front().movePivot(1,0);
			}
		}


	}


	window.clear();
	window.draw(panelWall);
	//shape preview
	sf::RectangleShape border(sf::Vector2f(120,60));
	border.setOutlineThickness(2);
	border.setOutlineColor(sf::Color::Yellow);
	border.setPosition(225,15);
	border.setFillColor(sf::Color(0,0,0,0));
	window.draw(border);
	//level
	border.setSize(sf::Vector2f(120,30));
	border.setOutlineThickness(2);
	border.setOutlineColor(sf::Color::Yellow);
	border.setPosition(225,85);
	border.setFillColor(sf::Color(0,0,0,0));
	window.draw(border);
	//points

	border.setOutlineThickness(2);
	border.setOutlineColor(sf::Color::Yellow);
	border.setPosition(225,125);
	border.setFillColor(sf::Color(0,0,0,0));
	window.draw(border);
	//lines

	border.setOutlineThickness(2);
	border.setOutlineColor(sf::Color::Yellow);
	border.setPosition(225,165);
	border.setFillColor(sf::Color(0,0,0,0));
	window.draw(border);


	//draw our falling minos 
	squares.setFillColor(palette[minosQ.front().getType()-1]);
	squares.setPosition((minosQ.front().getACoor().getXCoordinate())*scale,(minosQ.front().getACoor().getYCoordinate())*scale);
	window.draw(squares);
	squares.setPosition((minosQ.front().getBCoor().getXCoordinate())*scale,(minosQ.front().getBCoor().getYCoordinate())*scale);
	window.draw(squares);
	squares.setPosition((minosQ.front().getCCoor().getXCoordinate())*scale,(minosQ.front().getCCoor().getYCoordinate())*scale);
	window.draw(squares);
	squares.setPosition((minosQ.front().getDCoor().getXCoordinate())*scale,(minosQ.front().getDCoor().getYCoordinate())*scale);
	window.draw(squares);

	//draw our next minos 

	const int borderOffsetX = 180;
	const int borderOffsetY = 5;
	squares.setFillColor(palette[minosQ.back().getType()-1]);
	squares.setPosition(borderOffsetX+(minosQ.back().getACoor().getXCoordinate())*scale,borderOffsetY+(minosQ.back().getACoor().getYCoordinate())*scale);
	window.draw(squares);
	squares.setPosition(borderOffsetX+(minosQ.back().getBCoor().getXCoordinate())*scale,borderOffsetY+(minosQ.back().getBCoor().getYCoordinate())*scale);
	window.draw(squares);
	squares.setPosition(borderOffsetX+(minosQ.back().getCCoor().getXCoordinate())*scale,borderOffsetY+(minosQ.back().getCCoor().getYCoordinate())*scale);
	window.draw(squares);
	squares.setPosition(borderOffsetX+(minosQ.back().getDCoor().getXCoordinate())*scale,borderOffsetY+(minosQ.back().getDCoor().getYCoordinate())*scale);
	window.draw(squares);




	//draw whats already in grid
	for(int i=0;i<20;i++)
	{
		for(int j=0;j<10;j++)
		{
			if (m.getGrid()[j][i]!=0){
				squares.setPosition((j)*scale,(i)*scale);
				squares.setFillColor(palette[m.getGrid()[j][i]-1]);
				window.draw(squares);
			}
		}

	}

	panelWall.setPosition(y_dir*0.5,0);
	panelWall.setFillColor(sf::Color::White);




	window.draw(scores);
	window.draw(levelTxt);
	window.draw(lines);
	window.display();
}

return 0;
}
