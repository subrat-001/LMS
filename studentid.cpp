#include "studentid.h"
#include<SFML/Graphics.hpp>
#include <sstream>
using namespace std;
using namespace sf;
studentid::studentid()
{	
	//after selceting student
	indicator=0;
	initialize();
	initwindow();
	run();
}

studentid::~studentid()
{
	delete this->window;
}
studentid::studentid(int one)
{
	//after selceting librarian
	indicator=one;
	initialize();
	initwindow();
	run();
}
//iniitialzes variables
void studentid::initialize()
{
	str="";
	display="";
	font.loadFromFile("times-new-roman.ttf");
	text.setFont(font);
	text.setCharacterSize(24);
	text.setFillColor(Color::Black);
	text.setPosition(500.0f,590.0f);
	id.setFont(font);
	id.setCharacterSize(28);
	id.setFillColor(Color::Black);
	id.setPosition(430.0f,583.0f);
	id.setString("I.D");
	textbox.setSize(Vector2f(200.0f,40.0f));
	textbox.setFillColor(Color(425,425,425));
	textbox.setPosition(490.0f,580.0f);
	textbox.setOutlineThickness(2.0f);
	textbox.setOutlineColor(Color(500,500,500));
	text_back.setFont(font);
	text_back.setString("<");
	text_back.setFillColor(Color::White);
	text_back.setCharacterSize(16);
	text_back.setPosition(25.0f,25.0f);
		text_proceed.setFont(font);
	text_proceed.setString(">");
	text_proceed.setFillColor(Color::White);
	text_proceed.setCharacterSize(18);
	text_proceed.setPosition(710.0f,590.0f);
	back.setSize(Vector2f(25.0f,25.0f));back.setFillColor(Color(70,70,70));back.setPosition(20.0f,20.0f);
	back.setOutlineThickness(1.0f);
	back.setOutlineColor(Color(425,425,425));
	proceed.setSize(Vector2f(40.0f,40.0f));proceed.setFillColor(Color(70,70,70));proceed.setPosition(700.0f,580.0f);
	proceed.setOutlineThickness(2.0f);
	proceed.setOutlineColor(Color(425,425,425));
}
void studentid::initwindow()
{//initialize window
	this->window=new RenderWindow(VideoMode(1080,720),"ID",Style::Titlebar|Style::Close);
}
void studentid::run()
{
		while(this->window->isOpen())
	{
		while(this->window->pollEvent(this->event))
		{
			switch (this->event.type)
			{
				case Event::Closed:
					this->window->close();
					break;
				case Event::KeyPressed:
					if(this->event.key.code==Keyboard::Escape)
				{
					this->window->close();
				}
					
					else if(this->event.key.code==Keyboard::Return)
					{
						//enter to continue forward
						//everything here applies for forward button billow
							//indicator =0 indicats the user entered as a student
					//indicator =1 indicates user entered as the librarian
						if(indicator==0)
							{
								if(str=="")
								{
									//if m=nothing is entered
								this->window->close();
								studentid std;
								}
								else if(str.length()==12)
							{
								roll="";
								no="";
								name="";
								int quan(0);
								for(int j=0;j<12;j++)
								{
									if(j<=9)
									{roll+=toupper(str[j]);}
									else
									{
										no=str[j];
											 stringstream geek(no);
 												 int x = 0;
  								 				 geek >> x;
  								 				 quan=quan*10+x;
									
									}
								
								}
								for(int j=0;j<str.length();j++)
								{
									name+=toupper(str[j]);
								}
								if( roll=="THA076BCT0" && quan>=1 &&quan<=48)
   								{
								   
								   string write;
								write=name+" logged in";
									activity(write);
								this->window->close();
								//goes forward from here to displaying books genre
								student std(0);
								}
								else
									{
											this->window->close();
											studentid std;
								
									}
							}
							else
							{
									this->window->close();
								studentid std;
								
							}
							}
						else
						{
							if(str=="bond007")
							{
								activity("You logged in");
								this->window->close();
								//librarian goes forward only when pasword is correct password="bond007"
								student std(1);
							}
							else
							{
								this->window->close();
								studentid std(1);
							}
						}
					}
				break;
				
				case Event::TextEntered:
				if (indicator==0)
					{
						if (this->event.text.unicode == '\b')
    						{
    							//deleats a letter when backspace is entered
    							
    							if(str=="")
    							{
    								str="";
								}
								else
							{
							str.erase(str.size() - 1, 1);
							display=str;
							text.setString(display);}
						}
						else if(this->event.text.unicode<128)
							{
								//takes in string and sets it up for display on window
								str+=(char)this->event.text.unicode;
								display=str;
								text.setString(display);
							}
						}
						else 
							{
								if (this->event.text.unicode == '\b')
    						{
    							
    							if(str=="")
    							{
    								str="";
								}
								else
							{
							str.erase(str.size() - 1, 1);
							display.erase(display.size()-1,1);
							text.setString(display);}
						}
							else if(this->event.text.unicode<128)
								{
					
								str+=(char)this->event.text.unicode;
								display+="*";
								text.setString(display);
							}
							}
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
						//back button
						this ->window->close();
						menu menu_1;
						
					}
				else if(x>=700&&x<=740&&y>=580&&y<=620)
				{
					//indicator =0 indicats the user entered as a student
					//indicator =1 indicates user entered as the librarian
					//this is the forward button
					if(indicator==0)
							{
								if(str=="")
								{
										this->window->close();
					
										studentid std;
								}
								else
							{
									string write;
								write=str+" logged in";
							activity(write);
							this->window->close();
						
							
							student std(0);
							
							}}
						else
						{
							if(str=="bond007")
							{
							
								activity("You logged in");
								this->window->close();
								
								student std(1);
							}
							else
							{
								this->window->close();
								
								studentid std(1);
							}
						}	
				}
					}
				
				Vector2i mousePos =Mouse::getPosition(*window);//gets position of click on mouse
					x=(float)mousePos.x;
					y=(float)mousePos.y;
					if(x>=20.0f && x<=45.0f && y>=20.0f&& y<=45.0f)
					{
						back.setFillColor(Color(170,170,170));
					
					
					}
					else if(x>=700.0f && x<=740.0f && y>=580.0f&& y<=620.0f)
					{
					
							proceed.setFillColor(Color(170,170,170));
						
					
					}
					else
					{
							proceed.setFillColor(Color(70,70,70));
							back.setFillColor(Color(70,70,70));
						
					}
this->window->clear(Color(70,100,100));
this->window->draw(textbox);
	this->window->draw(text);
	this->window->draw(id);
	this->window->draw(back);
	this->window->draw(text_back);
	this->window->draw(proceed);
	this->window->draw(text_proceed);
	this->window->display();
}
}
