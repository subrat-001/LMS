#include "get.h"
#include "files.h"
using namespace sf;
using namespace std;
get::get(int code)
{
	book_code=code;
	initialize();
	initwindow();
	run();
}

get::~get()
{
	
}
void get::initialize()
{	
	font.loadFromFile("times-new-roman.ttf");
	textbox.setSize(Vector2f(300.0f,40.0f));
	textbox.setFillColor(Color(425,425,425));
	textbox.setPosition(290.0f,380.0f);
	textbox.setOutlineThickness(2.0f);
	textbox.setOutlineColor(Color(500,500,500));
	info.setFont(font);
	info.setCharacterSize(22);
	info.setString("R.N , B.C");
	info.setFillColor(Color::White);
	info.setPosition(130.0f,390.0f);
	back.setSize(Vector2f(25.0f,25.0f));back.setFillColor(Color(70,70,70));back.setPosition(20.0f,20.0f);
	back.setOutlineThickness(1.0f);
	back.setOutlineColor(Color(425,425,425));
		text_back.setFont(font);
	text_back.setString("<");
	text_back.setFillColor(Color::White);
	text_back.setCharacterSize(16);
	text_back.setPosition(25.0f,25.0f);
	getbox.setSize(Vector2f(40.0f,40.0f));getbox.setFillColor(Color(70,70,70));getbox.setPosition(610.0f,380.0f);
	getbox.setOutlineThickness(1.0f);
	getbox.setOutlineColor(Color(425,425,425));
	text_get.setFont(font);
	text_get.setString(">");
	text_get.setFillColor(Color::White);
	text_get.setCharacterSize(20);
	text_get.setPosition(615.0f,385.0f);
		text.setFont(font);
	text.setCharacterSize(24);
	text.setFillColor(Color::Black);
	text.setPosition(300.0f,390.0f);
}
void get::initwindow()
{
		this->window=new RenderWindow(VideoMode(1080,720),"Add Books",Style::Titlebar|Style::Close);
}
void get::run()
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
					{
						activity("forced log out");
					this->window->close();
					}
					else if(this->event.key.code==Keyboard::Return)
					{
							string apple,word("");
						int i,a(0),mark(0),quan(0);
						string q,q1("");
						string check=",";
						i=str.length();
						while(a<i)
        				{
    		 	 	      q=str[a];
        	    			if (q==check)//quantity and book's name is seperated by comma
            			{
                			mark=1;
            			}
            			else
            			{
                			if (mark==0)
                		{
                    		word+=q;
                		}
                		else
                		{
                    		apple=q;
                    		stringstream a1(apple);//used to convert string to intiger
                    		int u=0;
                    		a1>>u;
                    		quan=quan*10+u;
                    	


                		}
          		  }

         			 a++;

        		}			if(word.length()==12)
						{
						
								for(int j=0;j<word.length();j++)
								{
									name+=toupper(word[j]);
								}
							}
						
        		//here
				this ->window->close();
						if(book_code==1)
						{
							sifi();
							lending();
							int loop=0;
							while(loop<lending_size)
							{
								if(lending_indicator[loop]==1 && lending_bookcode[loop]==quan &&lending_rollnumber[loop]==name)
								{
									//gets back returned books quan representing book code,1 is indiacator for sifi
									//gets back lent out books and deleats entry from lent.txt
									//similar for forward button billow
										appendsifi(1,quan);
										appendlending(1,quan,name);
										string write;
								write="Returned : "+sifi_books[quan-1]+" by:"+name;
								activity(write);
										goto a6;
								}
								loop++;
							}
							a6:
						
							//sifi();
							books book(&sifi_books[0],&sifi_quantity[0],sifi_size,"Si-fi",1,1);
						book.run();
						}
						else if(book_code==2)
						{
							fantasy();
						lending();
							int loop=0;
							while(loop<lending_size)
							{
								if(lending_indicator[loop]==2 && lending_bookcode[loop]==quan&&lending_rollnumber[loop]==name)
								{
										appendfan(1,quan);
										appendlending(2,quan,name);
										string write;
								write="Returned : "+fantasy_books[quan-1]+"by: "+name;
								activity(write);
										goto a7;
								}
								loop++;
							}
							a7:
							books book(&fantasy_books[0],&fantasy_quantity[0],fan_size,"Fantasy",1,2);
						
							book.run();
						}
						else if(book_code==3)
						{
							sh();
						lending();
							int loop=0;
							while(loop<lending_size)
							{
								if(lending_indicator[loop]==3 && lending_bookcode[loop]==quan&&lending_rollnumber[loop]==name)
								{
										appendsh(1,quan);
										appendlending(3,quan,name);
										string write;
								write="Returned : "+sh_books[quan-1]+"by: "+name;
								activity(write);
										goto a8;
								}
								loop++;
							}
							a8:
							books book(&sh_books[0],&sh_quantity[0],sh_size,"Self Help",1,3);
							book.run();
						}
						else if(book_code==4)
						{
						philo();
							lending();
							int loop=0;
							while(loop<lending_size)
							{
								if(lending_indicator[loop]==4 && lending_bookcode[loop]==quan&&lending_rollnumber[loop]==name)
								{
										appendphilo(1,quan);
										appendlending(4,quan,name);
										string write;
								write="Returned : "+philo_books[quan-1]+"by: "+name;
								activity(write);
										goto a9;
								}
								loop++;
							}
							a9:
							books book(&philo_books[0],&philo_quantity[0],philo_size,"Philosophy",1,4);
							book.run();
						}
						else if(book_code==5)
						{
							bio();
							lending();
							int loop=0;
							while(loop<lending_size)
							{
								if(lending_indicator[loop]==5 && lending_bookcode[loop]==quan&&lending_rollnumber[loop]==name)
								{
										appendbio(1,quan);
										appendlending(5,quan,name);
										string write;
								write="Returned : "+bio_books[quan-1]+"by: "+name;
								activity(write);
										goto a10;
								}
								loop++;
							}
							a10:
							books book(&bio_books[0],&bio_quantity[0],bio_size,"Biography",1,5);
						book.run();
						}
			}
					
					break;
					case Event::TextEntered:
						if (this->event.text.unicode == '\b')
    						{
    							if(str=="")
    							{
    								str="";
								}
								else
							{
							str.erase(str.size() - 1, 1);
							display=str;
							text.setString(display);
						}
						}
					else if(this->event.text.unicode<128)
							{
								str+=(char)this->event.text.unicode;
								display=str;
								text.setString(display);
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
					
						this ->window->close();
						if(book_code==1)
						{
					
							sifi();
							books book(&sifi_books[0],&sifi_quantity[0],sifi_size,"Si-fi",1,1);
						book.run();
						}
						else if(book_code==2)
						{
					
							fantasy();
							books book(&fantasy_books[0],&fantasy_quantity[0],fan_size,"Fantasy",1,2);
							book.run();
						}
						else if(book_code==3)
						{
					
						
							books book(&sh_books[0],&sh_quantity[0],sh_size,"Self Help",1,3);
							book.run();
						}
						else if(book_code==4)
						{
							
							philo();
						
							
							books book(&philo_books[0],&philo_quantity[0],philo_size,"Philosophy",1,4);
							book.run();
						}
						else if(book_code==5)
						{
						
							bio();
							books book(&bio_books[0],&bio_quantity[0],bio_size,"Biography",1,5);
						book.run();
						}
						
						
					}
					else if(x>=610&&x<=650&&y>=380&&y<=420)
					{
						string apple,word("");
						int i,a(0),mark(0),quan(0);
						string q,q1("");
						string check=",";
						i=str.length();
						while(a<i)
        				{
    		 	 	      q=str[a];
        	    			if (q==check)//quantity and book's name is seperated by comma
            			{
                			mark=1;
            			}
            			else
            			{
                			if (mark==0)
                		{
                    		word+=q;
                		}
                		else
                		{
                    		apple=q;
                    		stringstream a1(apple);//used to convert string to intiger
                    		int u=0;
                    		a1>>u;
                    		quan=quan*10+u;
                    	


                		}
          		  }

         			 a++;

        		}			if(word.length()==12)
						{
						
								for(int j=0;j<word.length();j++)
								{
									name+=toupper(word[j]);
								}
							}
						
        		//here
				this ->window->close();
						if(book_code==1)
						{
							sifi();
							lending();
							int loop=0;
							while(loop<lending_size)
							{
								if(lending_indicator[loop]==1 && lending_bookcode[loop]==quan &&lending_rollnumber[loop]==name)
								{
									//gets back returned books quan representing book code,1 is indiacator for sifi
									//gets back lent out books and deleats entry from lent.txt
									//similar for forward button billow
										appendsifi(1,quan);
										appendlending(1,quan,name);
										string write;
								write="Returned : "+sifi_books[quan-1]+", by: "+name;
								activity(write);
										goto a1;
								}
								loop++;
							}
							a1:
						
							//sifi();
							books book(&sifi_books[0],&sifi_quantity[0],sifi_size,"Si-fi",1,1);
						book.run();
						}
						else if(book_code==2)
						{
							fantasy();
						lending();
							int loop=0;
							while(loop<lending_size)
							{
								if(lending_indicator[loop]==2 && lending_bookcode[loop]==quan&&lending_rollnumber[loop]==name)
								{
										appendfan(1,quan);
										appendlending(2,quan,name);
										string write;
								write="Returned : "+fantasy_books[quan-1]+", by: "+name;
								activity(write);
										goto a2;
								}
								loop++;
							}
							a2:
							books book(&fantasy_books[0],&fantasy_quantity[0],fan_size,"Fantasy",1,2);
						
							book.run();
						}
						else if(book_code==3)
						{
							sh();
						lending();
							int loop=0;
							while(loop<lending_size)
							{
								if(lending_indicator[loop]==3 && lending_bookcode[loop]==quan&&lending_rollnumber[loop]==name)
								{
										appendsh(1,quan);
										appendlending(3,quan,name);
										string write;
								write="Returned : "+sh_books[quan-1]+", by: "+name;
								activity(write);
										goto a3;
								}
								loop++;
							}
							a3:
							books book(&sh_books[0],&sh_quantity[0],sh_size,"Self Help",1,3);
							book.run();
						}
						else if(book_code==4)
						{
						philo();
							lending();
							int loop=0;
							while(loop<lending_size)
							{
								if(lending_indicator[loop]==4 && lending_bookcode[loop]==quan&&lending_rollnumber[loop]==name)
								{
										appendphilo(1,quan);
										appendlending(4,quan,name);
										string write;
								write="Returned : "+philo_books[quan-1]+", by: "+name;
								activity(write);
										goto a4;
								}
								loop++;
							}
							a4:
							books book(&philo_books[0],&philo_quantity[0],philo_size,"Philosophy",1,4);
							book.run();
						}
						else if(book_code==5)
						{
							bio();
							lending();
							int loop=0;
							while(loop<lending_size)
							{
								if(lending_indicator[loop]==5 && lending_bookcode[loop]==quan&&lending_rollnumber[loop]==name)
								{
										appendbio(1,quan);
										appendlending(5,quan,name);
										string write;
								write="Returned : "+bio_books[quan-1]+", by: "+name;
								activity(write);
										goto a5;
								}
								loop++;
							}
							a5:
							books book(&bio_books[0],&bio_quantity[0],bio_size,"Biography",1,5);
						book.run();
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
					else if(x>=610&&x<=650&&y>=380&&y<=420)
					{
							getbox.setFillColor(Color(170,170,170));		
					}
					
					else
					{
						
					
							back.setFillColor(Color(70,70,70));
							getbox.setFillColor(Color(70,70,70));
					
					}
	this->window->clear(Color(70,100,100));
	this->window->draw(textbox);
	this->window->draw(text);
	this->window->draw(back);
	this->window->draw(text_back);
	this->window->draw(getbox);
	this->window->draw(text_get);
	this->window->draw(info);
	this->window->display();
}}
