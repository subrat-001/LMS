#include "alog.h"
#include<string>
#include<fstream>
using namespace sf;
using namespace std;
alog::alog()
{
	initialize();
	initwindow();
	run();
}

alog::~alog()
{
	delete this->window;	
}
void alog::initialize()
{
	font.loadFromFile("times-new-roman.ttf");
		back.setSize(Vector2f(25.0f,25.0f));back.setFillColor(Color(70,70,70));back.setPosition(20.0f,20.0f);
			back.setOutlineThickness(1.0f);
			back.setOutlineColor(Color(425,425,425));
			text_back.setFont(font);
	text_back.setString("<");
	text_back.setFillColor(Color::White);
	text_back.setCharacterSize(16);
	text_back.setPosition(25.0f,25.0f);
	ifstream fin;
	//opens activity to get the data present there
				fin.open("activity.txt");
				string line("");
				int i=1;
				float j=20;
				getline(fin,line);
				text_main.setFont(font);
					text_main.setString(line);
					text_main.setFillColor(Color::White);
					text_main.setCharacterSize(25);
					text_main.setPosition(45.0f,45.0f);
				while(fin)
				{
					line="";
					float k=(float)i*j;
					getline(fin,line);
				
					text[i].setFont(font);
					text[i].setString(line);
					text[i].setFillColor(Color::White);
					text[i].setCharacterSize(16);
					text[i].setPosition(65.0f,85.0f+k);
					i++;
			
					if(!fin.good()){break;}
				}
				looping=i;
	
}
void alog::initwindow()
{
	this->window=new RenderWindow(VideoMode(1080,720),"Activity",Style::Titlebar|Style::Close);
}
void alog::run()
{
	while(this->window->isOpen())
	{
		while(this->window->pollEvent(this->event))
		{
			switch (this->event.type)
			{
				case Event::Closed:
					activity("forced log out");
					clearactivity();
					this->window->close();
					
					break;
				case Event::KeyPressed:
					if(this->event.key.code==Keyboard::Escape)
						activity("forced log out");
						clearactivity();
					this->window->close();
			
					break;
			}
		}
				float x,y;
					if (Mouse::isButtonPressed(Mouse::Left))
				{
					Vector2i mousePos =Mouse::getPosition(*window);
					x=(float)mousePos.x;
					y=(float)mousePos.y;
					if (x>=20&&x<=45&&y>=20&&y<=45)
					{
						clearactivity();
						this ->window->close();
						
						
							student std(1);
					
					}
				}
	Vector2i mousePos =Mouse::getPosition(*window);
					x=(float)mousePos.x;
					y=(float)mousePos.y;
					if (x>=20&&x<=45&&y>=20&&y<=45)
					{
							back.setFillColor(Color(170,170,170));
					}
						else
					{
						back.setFillColor(Color(70,70,70));
					}		
				
this->window->clear(Color(70,100,100));
	int j=1;
	while(j<looping)
	{
	this->window->draw(text[j]);
	j++;
	}
	this->window->draw(text_main);
	this->window->draw(back);
	this->window->draw(text_back);				
	this->window->display();			
}
}
