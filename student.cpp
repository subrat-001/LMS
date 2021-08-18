#include "student.h"
#include "studentid.h"
#include "books.h"
#include "files.h"
using namespace std;
using namespace sf;
student::student(int one)
{
	indicator=one;
	//indicator =1 as librarian and 0 as student
	this->initialize();
	this->initwindow();
	this->run_student();
	
}
student::~student()
{
	delete this->window;
}
void student::run_student()
{
	
	
	while(this->window->isOpen())
	{
		while(this->window->pollEvent(this->event))
		{
			switch (this->event.type)
			{
				//closing
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
					
					if(x>=400.0f && x<=500.0f && y>=200.0f&& y<=240.0f)
					{
						//buttons  clicked leads to displaying sifi books  and similarly functions billow lead to different genra of books
						this->window->close();
						activity("viewed sifi");
					
						sifi();
					if (indicator==0)
						
						{	
					
						books book(&sifi_books[0],&sifi_quantity[0],sifi_size,"Si-fi",indicator,1);
					
						
						book.run();
					}
					else
					{
						initmax(1);
						
							books book(&sifi_books[0],&sifi_quantity[0],sifi_size,"Si-fi",indicator,1);
					
						book.run();
					}
					
					}
					else if(x>=540.0f && x<=640.0f && y>=200.0f&& y<=240.0f)
					{
					
						this->window->close();
						activity("viewed fantasy");
						fantasy();
					
						if (indicator==0)
						
						{
							books book(&fantasy_books[0],&fantasy_quantity[0],fan_size,"Fantasy",indicator,2);
							book.run();
						}
						else
						{	initmax(2);
							books book(&fantasy_books[0],&fantasy_quantity[0],fan_size,"Fantasy",indicator,2);
							int i=0;
						
							book.run();
						}
					}
					else if(x>=400.0f && x<=500.0f && y>=260.0f&& y<=300.0f)
					{
					
						this->window->close();
						
						sh();
					
						activity("viewed self help");
					
						if(indicator==0)
						{
							
							books book(&sh_books[0],&sh_quantity[0],sh_size,"Self Help",indicator,3);
						
							book.run();
						}
						else
						{	initmax(3);
							books book(&sh_books[0],&sh_quantity[0],sh_size,"Self Help",indicator,3);
							
							book.run();
						}
					}
					else if(x>=540.0f && x<=640.0f && y>=260.0f&& y<=300.0f)
					{
						this->window->close();	
					
						philo();
					activity("viewed philo");
						if(indicator==0)
						{						
							books book(&philo_books[0],&philo_quantity[0],philo_size,"Philosophy",indicator,4);
							book.run();
						}
						else
						{			initmax(4);
							books book(&philo_books[0],&philo_quantity[0],philo_size,"Philosophy",indicator,4);
							book.run();
						}
					}
					else if(x>=400.0f && x<=500.0f && y>=320.0f&& y<=360.0f)
					{
					
						this->window->close();
						bio();
						activity("viewed bio");
						
						if(indicator==0)
						{
							books book(&bio_books[0],&bio_quantity[0],bio_size,"Biography",indicator,5);
							book.run();
						}
						else
						{initmax(5);
							books book(&bio_books[0],&bio_quantity[0],bio_size,"Biography",indicator,5);
						book.run();
						}
					}
					else if (x>=20&&x<=45&&y>=20&&y<=45)
					{
						activity("logged out");
						this ->window->close();
						
						if (indicator==0)
						{
							studentid std;
						}
						else
						{
							studentid std(1);
						}
					}
					else if (x>=1000&&x<=1025&&y>=20&&y<=45)
					{
						if (indicator==1)
						{
						//if user enters as librarian this displays a button for seeing activity log
						activity("Viewing Activity log");
						this ->window->close();
						
						
							alog a;
						}
					}
					else if (x>=950&&x<=975&&y>=20&&y<=45)
					{
						if (indicator==1)
						{
						//if user enters as librarian this displays a button for seeing activity log
						activity("Viewed Lent Books");
						this ->window->close();
						
						
							outbook a;
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
					else if(x>=400.0f && x<=500.0f && y>=200.0f&& y<=240.0f)
					{
					
							sifi1.setFillColor(Color(170,170,170));
						
					
					}
							else if(x>=540.0f && x<=640.0f && y>=200.0f&& y<=240.0f)
					{
					
							fantasy1.setFillColor(Color(170,170,170));
						
					
					}
							else if(x>=400.0f && x<=500.0f && y>=260.0f&& y<=300.0f)
					{
					
							selfhelp1.setFillColor(Color(170,170,170));
						
					
					}
							else if(x>=540.0f && x<=640.0f && y>=260.0f&& y<=300.0f)
					{
					
							philo1.setFillColor(Color(170,170,170));
						
					
					}
							else if(x>=400.0f && x<=500.0f && y>=320.0f&& y<=360.0f)
					{
					
							bio1.setFillColor(Color(170,170,170));
						
					
					}
					else
					{
							philo1.setFillColor(Color(70,70,70));
							bio1.setFillColor(Color(70,70,70));
							fantasy1.setFillColor(Color(70,70,70));
							selfhelp1.setFillColor(Color(70,70,70));
							sifi1.setFillColor(Color(70,70,70));
						
						
					}
					if(indicator==1)
					{
						 if (x>=1000&&x<=1025&&y>=20&&y<=45)
					{
						log.setFillColor(Color(170,170,170));
					}
					else if (x>=950&&x<=975&&y>=20&&y<=45)
					{
						out.setFillColor(Color(170,170,170));
					}
					else
					{
						log.setFillColor(Color(70,70,70));
						
						out.setFillColor(Color(70,70,70));
					}
					}
		
		update();
	}
	
}
void student::update()
{
	this->window->clear(Color(70,100,100));
	this->window->draw(philo1);
	this->window->draw(back);
	this->window->draw(selfhelp1);
	this->window->draw(sifi1);
	this->window->draw(bio1);
	this->window->draw(fantasy1);
	this->window->draw(text_fantasy);
	this->window->draw(text_bio);
	this->window->draw(text_sifi);
	this->window->draw(text_selfhelp);
	this->window->draw(text_philo);
	this->window->draw(text_back);
	if(indicator!=0)
	{
		//displays activity log button only if entered as a librarian
		this->window->draw(log);
	this->window->draw(text_log);
		this->window->draw(out);
	this->window->draw(text_out);	
	}
	this->window->display();
	
	
}
void student::initialize()
{
	//initialize buttons
	font.loadFromFile("times-new-roman.ttf");
								text_sifi.setFont(font);
								text_sifi.setString("Si-Fi");
								text_sifi.setFillColor(Color::White);
								text_sifi.setCharacterSize(16);
								text_sifi.setPosition(405.0f,205.0f);
								text_fantasy.setFont(font);
								text_fantasy.setString("Fantasy");
								text_fantasy.setFillColor(Color::White);
								text_fantasy.setCharacterSize(16);
								text_fantasy.setPosition(545.0f,205.0f);
								text_selfhelp.setFont(font);
								text_selfhelp.setString("Self Help");
								text_selfhelp.setFillColor(Color::White);
								text_selfhelp.setCharacterSize(16);
								text_selfhelp.setPosition(405.0f,265.0f);
								text_philo.setFont(font);
								text_philo.setString("Philosophy");
								text_philo.setFillColor(Color::White);
								text_philo.setCharacterSize(16);
								text_philo.setPosition(545.0f,265.0f);
								text_bio.setFont(font);
								text_bio.setString("Biography");
								text_bio.setFillColor(Color::White);
								text_bio.setCharacterSize(16);
								text_bio.setPosition(405.0f,325.0f);
								text_back.setFont(font);
								text_back.setString("<");
								text_back.setFillColor(Color::White);
								text_back.setCharacterSize(16);
								text_back.setPosition(25.0f,25.0f);
								text_log.setFont(font);
								text_log.setString("i");
								text_log.setFillColor(Color::White);
								text_log.setCharacterSize(16);
								text_log.setPosition(1005.0f,25.0f);
								text_out.setFont(font);
								text_out.setString("o");
								text_out.setFillColor(Color::White);
								text_out.setCharacterSize(16);
								text_out.setPosition(955.0f,25.0f);
								
						sifi1.setSize(Vector2f(100.0f,40.0f));sifi1.setFillColor(Color(70,70,70));sifi1.setPosition(400.0f,200.0f);
						fantasy1.setSize(Vector2f(100.0f,40.0f));fantasy1.setFillColor(Color(70,70,70));fantasy1.setPosition(540.0f,200.0f);
						selfhelp1.setSize(Vector2f(100.0f,40.0f));selfhelp1.setFillColor(Color(70,70,70));selfhelp1.setPosition(400.0f,260.0f);
						philo1.setSize(Vector2f(100.0f,40.0f));philo1.setFillColor(Color(70,70,70));philo1.setPosition(540.0f,260.0f);
						bio1.setSize(Vector2f(100.0f,40.0f));bio1.setFillColor(Color(70,70,70));bio1.setPosition(400.0f,320.0f);
						sifi1.setOutlineThickness(1.0f);
						sifi1.setOutlineColor(Color(425,425,425));
						philo1.setOutlineThickness(1.0f);
						philo1.setOutlineColor(Color(425,425,425));
						selfhelp1.setOutlineThickness(1.0f);
						selfhelp1.setOutlineColor(Color(425,425,425));
						bio1.setOutlineThickness(1.0f);
						bio1.setOutlineColor(Color(425,425,425));
						fantasy1.setOutlineThickness(1.0f);
						fantasy1.setOutlineColor(Color(425,425,425));
						back.setSize(Vector2f(25.0f,25.0f));back.setFillColor(Color(70,70,70));back.setPosition(20.0f,20.0f);
						back.setOutlineThickness(1.0f);
						back.setOutlineColor(Color(425,425,425));
						log.setSize(Vector2f(25.0f,25.0f));log.setFillColor(Color(70,70,70));log.setPosition(1000.0f,20.0f);
						log.setOutlineThickness(1.0f);
						log.setOutlineColor(Color(425,425,425));
						out.setSize(Vector2f(25.0f,25.0f));out.setFillColor(Color(70,70,70));out.setPosition(950.0f,20.0f);
						out.setOutlineThickness(1.0f);
						out.setOutlineColor(Color(425,425,425));
						
}
void student::initwindow()
{
	this->window=new RenderWindow(VideoMode(1080,720),"catagories",Style::Titlebar|Style::Close);
}
