#include "menu.h"
#include "student.h"
#include "studentid.h"
using namespace sf;
using namespace std;

//constructor called to launch menu
menu::menu()
{
	this->initvariables();
	this->initwindow();
	while(run())
	{

	
		update();
		render();
	}
}
menu:: ~menu()
{
	delete this->window;	
}
//initiation of variables
void menu::initvariables()
{
//initiates fonts texts and rextangle
		font.loadFromFile("times-new-roman.ttf");
			text_librarian.setFont(font);
			text_librarian.setString("Librarian");
			text_librarian.setFillColor(Color::White);
			text_librarian.setCharacterSize(24);
			text_librarian.setPosition(450.0f,290.0f);
			text_student.setFont(font);
			text_student.setString("Student");
			text_student.setFillColor(Color::White);
			text_student.setCharacterSize(24);
			text_student.setPosition(450.0f,210.0f);
			lms.setFont(font);
			lms.setString("L.M.S");
			lms.setFillColor(Color::White);
			lms.setCharacterSize(40);
			lms.setPosition(450.0f,100.0f);
			librarian.setSize(Vector2f(150.0f,60.0f));
			librarian.setFillColor(Color(70,70,70));
			librarian.setPosition(425.0f,280.0f);
			librarian.setOutlineThickness(2.0f);
			librarian.setOutlineColor(Color(425,425,425));
			student1.setSize(Vector2f(150.0f,60.0f));
			student1.setFillColor(Color(70,70,70));
			student1.setPosition(425.0f,200.0f);
			student1.setOutlineThickness(2.0f);
			student1.setOutlineColor(Color(425,425,425));
			

		
}
//makes a window
void menu::initwindow()
{
	this->window=new RenderWindow(VideoMode(1080,720),"Main",Style::Titlebar|Style::Close);
	
}
//accessor
const bool menu::run() const
 {
 	return this->window->isOpen();
 }
 //functions
void menu::update()
{

	
		
			while(window->pollEvent(this->event))
		{
			switch (this->event.type)
			{
				case Event::Closed:
					//closes window
					this->window->close();
					break;
				case Event::KeyPressed:
					if(this->event.key.code==Keyboard::Escape)
				
					this->window->close();
					break;
			}
			
			float x,y;	
			if (Mouse::isButtonPressed(Mouse::Left))
				{
					Vector2i mousePos =Mouse::getPosition(*window);//gets position of click on mouse
					x=(float)mousePos.x;
					y=(float)mousePos.y;
					if(x>=425.0f && x<=575.0f && y>=200.0f&& y<=260.0f)
					{
					
						this->window->close();
						//if student button is clicked
						studentid std;
					
					}
					else	if(x>=425.0f && x<=575.0f && y>=280.0f&& y<=340.0f)
					{
					
						this->window->close();
						//if librarian is clicked
						studentid std(1);
					
					}
				}
				Vector2i mousePos =Mouse::getPosition(*window);//gets position of click on mouse
					x=(float)mousePos.x;
					y=(float)mousePos.y;
					if(x>=425.0f && x<=575.0f && y>=200.0f&& y<=260.0f)
					{
						student1.setFillColor(Color(170,170,170));
					
					
					}
					else if(x>=425.0f && x<=575.0f && y>=280.0f&& y<=340.0f)
					{
					
							librarian.setFillColor(Color(170,170,170));
						
					
					}
					else
					{
							student1.setFillColor(Color(70,70,70));
							librarian.setFillColor(Color(70,70,70));
						
					}
				}
}

//draw items
void menu::render()
{
	this->window->clear(Color(70,100,100));
	this->window->draw(librarian);
	this->window->draw(lms);
	this->window->draw(student1);
	this->window->draw(text_librarian);
	this->window->draw(text_student);
	this->window->display();
}

