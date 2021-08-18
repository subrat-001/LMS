#include "books.h"
#include"add.h"
#include "get.h"
#include "lend.h"
#include "files.h"
#include<sstream>
using namespace std;
using namespace sf;
books::books(string *book_name,int *books_qty,int no,string name,int indi,int code)
{

	indicator=indi;
	book_code=code;
	number=no;
	name_set=name;
	files f;

for (int i=0;i<no;i++)
{

	
		name_arr[i]=*(book_name+i);
		qty_arr[i]=*(books_qty+i);
	
}
initialize();
initwindow();
}
void books::run()
{
	while(this->window->isOpen())
	{
		while(this->window->pollEvent(this->event))
		{
			switch (this->event.type)
			{
				case Event::Closed:
							activity("forced log out");
					this->window->close();
					break;
				case Event::KeyPressed:
					if(this->event.key.code==Keyboard::Escape)
						activity("forced log out");
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
						this ->window->close();
					if(indicator==0)
					{
						student std(0);
					}
					else
					{
						student std(1);
					
					}
					}
				}
				if (indicator==1)
				{
					//shows and executes these buttons functions only if entered as a librarian 
				float x,y;	
				if (Mouse::isButtonPressed(Mouse::Left))
					{
					Vector2i mousePos =Mouse::getPosition(*window);
					x=(float)mousePos.x;
					y=(float)mousePos.y;
					if (x>=500&&x<=550&&y>=680&&y<=710)
						{
						this ->window->close();
					//button for add book function
							addbook a(book_code);
						}
						
					else if (x>=430&&x<=480&&y>=680&&y<=710)
						{
							//button for getting back book function
						this ->window->close();
							get g(book_code);
						}
					
					else if (x>=570&&x<=620&&y>=680&&y<=710)
						{
								//button for lending book function
						this ->window->close();
						lend l(book_code);
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
					else
					{
							back.setFillColor(Color(70,70,70));
					}
						if (indicator==1)
				{
					//shows and executes these buttons functions only if entered as a librarian 
			
					if (x>=500&&x<=550&&y>=680&&y<=710)
						{
						add.setFillColor(Color(170,170,170));
						}
						
					else if (x>=430&&x<=480&&y>=680&&y<=710)
						{
							//button for getting back book function
						getback.setFillColor(Color(170,170,170));
						}
					
					else if (x>=570&&x<=620&&y>=680&&y<=710)
						{
								//button for lending book function
						lend1.setFillColor(Color(170,170,170));
						}
						else
						{
							lend1.setFillColor(Color(70,70,70));
							getback.setFillColor(Color(70,70,70));
							add.setFillColor(Color(70,70,70));
						}
					
					}
					
				
				
this->window->clear(Color(70,100,100));
this->window->draw(text2);
this->window->draw(text3);
this->window->draw(text4);
this->window->draw(text5);
for (int i=0;i<=number;i++)
{
	this->window->draw(text[i]);
	this->window->draw(text1[i]);
	this->window->draw(texta[i]);
}
if(indicator!=0)
{
	//executes only as a librarian
	this->window->draw(add);
	this->window->draw(text_add);
	this->window->draw(getback);
	this->window->draw(text_getback);
	this->window->draw(lend1);
	this->window->draw(text_lend);
	files f;
//	cout<<sifi_books[2]<<"hallaaA";
}
	this->window->draw(back);
	this->window->draw(back1);
this->window->display();
}
}
books::~books()
{
	delete this->window;
}
void books::initialize()
{
	font.loadFromFile("times-new-roman.ttf");
	text2.setFont(font);
	text2.setCharacterSize(24);
	text2.setFillColor(Color::White);
	text2.setString(name_set);
	text2.setPosition(572.5f,50.0f);
	text3.setFont(font);
	text3.setCharacterSize(24);
	text3.setFillColor(Color::White);
	text3.setString("Book Code");
	text3.setPosition(75.0f,150.0f);
	text4.setFont(font);
	text4.setCharacterSize(24);
	text4.setFillColor(Color::White);
	text4.setString("Name");
	text4.setPosition(225.0f,150.0f);
	text5.setFont(font);
	text5.setCharacterSize(24);
	text5.setFillColor(Color::White);
	text5.setString("Quantity");
	text5.setPosition(800.0f,150.0f);
	for(int i=0;i<number;i++)
	{
	float j=(float)i*30;
	text[i].setFont(font);
	text[i].setCharacterSize(24);
	text[i].setFillColor(Color::White);
	text[i].setString(name_arr[i]);
	text[i].setPosition(225.0f,200.0f+j);
	text1[i].setFont(font);
	text1[i].setCharacterSize(24);
	text1[i].setFillColor(Color::White);
	//intiger to string
	stringstream ss;
	ss << qty_arr[i];
	string str = ss.str();
	text1[i].setString(str);
	text1[i].setPosition(800.0f,200.0f+j);
	texta[i].setFont(font);
	texta[i].setCharacterSize(24);
	texta[i].setFillColor(Color::White);
	//intiger to string
	stringstream s;
	s << i+1;
	string st = s.str();
	texta[i].setString(st);
	texta[i].setPosition(75.0f,200.0f+j);
}
			back1.setFont(font);
			back1.setString("<");
			back1.setFillColor(Color::White);
			back1.setCharacterSize(16);
			back1.setPosition(25.0f,25.0f);
			back.setSize(Vector2f(25.0f,25.0f));back.setFillColor(Color(70,70,70));back.setPosition(20.0f,20.0f);
			back.setOutlineThickness(1.0f);
			back.setOutlineColor(Color(425,425,425));
			text_add.setFont(font);
			text_add.setString("Add");
			text_add.setFillColor(Color::White);
			text_add.setCharacterSize(20);
			text_add.setPosition(502.0f,682.0f);
			text_getback.setFont(font);
			text_getback.setString("Get");
			text_getback.setFillColor(Color::White);
			text_getback.setCharacterSize(20);
			text_getback.setPosition(432.0f,682.0f);
			text_lend.setFont(font);
			text_lend.setString("Lend");
			text_lend.setFillColor(Color::White);
			text_lend.setCharacterSize(20);
			text_lend.setPosition(572.0f,682.0f);
			add.setSize(Vector2f(50.0f,30.0f));add.setFillColor(Color(70,70,70));add.setPosition(500.0f,680.0f);
			add.setOutlineThickness(1.5f);
			add.setOutlineColor(Color(425,425,425));
			getback.setSize(Vector2f(50.0f,30.0f));getback.setFillColor(Color(70,70,70));getback.setPosition(430.0f,680.0f);
			getback.setOutlineThickness(1.5f);
			getback.setOutlineColor(Color(425,425,425));
			lend1.setSize(Vector2f(50.0f,30.0f));lend1.setFillColor(Color(70,70,70));lend1.setPosition(570.0f,680.0f);
			lend1.setOutlineThickness(1.5f);
			lend1.setOutlineColor(Color(425,425,425));
}
void books::initwindow()
{
	this->window=new RenderWindow(VideoMode(1080,720),"show",Style::Titlebar|Style::Close);
}
