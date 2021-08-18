#include "lend.h"
#include "files.h"
using namespace sf;
using namespace std;
lend::lend(int code)
{
	book_code=code;
	initialize();
	initwindow();
	run();
}

lend::~lend()
{
}
void lend::initialize()
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
		text_back.setFont(font);
	text_back.setString("<");
	text_back.setFillColor(Color::White);
	text_back.setCharacterSize(16);
	text_back.setPosition(25.0f,25.0f);
	back.setOutlineColor(Color(425,425,425));
	lendbox.setSize(Vector2f(40.0f,40.0f));lendbox.setFillColor(Color(70,70,70));lendbox.setPosition(610.0f,380.0f);
	lendbox.setOutlineThickness(1.0f);
	lendbox.setOutlineColor(Color(425,425,425));
	text_lend.setFont(font);
	text_lend.setString(">");
	text_lend.setFillColor(Color::White);
	text_lend.setCharacterSize(20);
	text_lend.setPosition(615.0f,385.0f);
		text.setFont(font);
	text.setCharacterSize(24);
	text.setFillColor(Color::Black);
	text.setPosition(300.0f,390.0f);
}
void lend::initwindow()
{
		this->window=new RenderWindow(VideoMode(1080,720),"Add Books",Style::Titlebar|Style::Close);
}
void lend::run()
{

//	cout<<sifi_books[2];
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
					else if (this->event.key.code==Keyboard::Return)
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

        		}
        		if(word.length()==12)
							{
								roll="";
								no="";
								name="";
								int quan(0);
								for(int j=0;j<12;j++)
								{
									if(j<=9)
									{roll+=toupper(word[j]);}
									else
									{
										no=word[j];
											 stringstream geek(no);
 												 int x = 0;
  								 				 geek >> x;
  								 				 quan=quan*10+x;
									
									}
								
								}
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
							appendsifi(0,quan);
							if(sifi_quantity[quan-1]!=0 &&roll=="THA076BCT0" && quan>=1 &&quan<=48)
							{
								//when the quantity of a book is not zero it is lent out and stored in lend ,and the quantity is decreased in sifi files
								//similar for other genra as well
								//qiam represents book code
								lending();
								//here 1 is indicator for sifi
								addlending(1,quan,name);
								string write;
								write="Lent out: "+sifi_books[quan-1]+ " to: "+name;
								activity(write);
							}
					
							books book(&sifi_books[0],&sifi_quantity[0],sifi_size,"Si-fi",1,1);
						book.run();
						}
						else if(book_code==2)
						{
							fantasy();
							appendfan(0,quan);
							if(fantasy_quantity[quan-1]!=0&&roll=="THA076BCT0" && quan>=1 &&quan<=48)
							{
								lending();
								addlending(2,quan,name);
								string write;
								write="Lent out: "+fantasy_books[quan-1]+" to: "+name;
								activity(write);
							}
							books book(&fantasy_books[0],&fantasy_quantity[0],fan_size,"Fantasy",1,2);
					
							book.run();
						}
						else if(book_code==3)
						{
							sh();
							appendsh(0,quan);
						
							if(sh_quantity[quan-1]!=0&&roll=="THA076BCT0" && quan>=1 &&quan<=48)
							{
								lending();
								addlending(3,quan,name);
								string write;
								write="Lent out: "+sh_books[quan-1]+" to: "+name;
								activity(write);
							}
							books book(&sh_books[0],&sh_quantity[0],sh_size,"Self Help",1,3);
							book.run();
						}
						else if(book_code==4)
						{
							philo();
							appendphilo(0,quan);
							if(philo_quantity[quan-1]!=0&&roll=="THA076BCT0" && quan>=1 &&quan<=48)
							{
								lending();
								addlending(4,quan,name);
								string write;
								write="Lent out: "+philo_books[quan-1]+" to: "+name;
								activity(write);
							}
						
							books book(&philo_books[0],&philo_quantity[0],philo_size,"Philosophy",1,4);
							book.run();
						}
						else if(book_code==5)
						{
							bio();
							appendbio(0,quan);
						
							if(bio_quantity[quan-1]!=0&&roll=="THA076BCT0" && quan>=1 &&quan<=48)
							{
								lending();
								addlending(5,quan,name);
								string write;
								write="Lent out: "+bio_books[quan-1]+" to: "+name;
								activity(write);
							}
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
						
							sh();
						
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

        		}
        		if(word.length()==12)
							{
								roll="";
								no="";
								name="";
								int quan(0);
								for(int j=0;j<12;j++)
								{
									if(j<=9)
									{roll+=toupper(word[j]);}
									else
									{
										no=word[j];
											 stringstream geek(no);
 												 int x = 0;
  								 				 geek >> x;
  								 				 quan=quan*10+x;
									
									}
								
								}
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
							appendsifi(0,quan);
							if(sifi_quantity[quan-1]!=0 &&roll=="THA076BCT0" && quan>=1 &&quan<=48)
							{
								//when the quantity of a book is not zero it is lent out and stored in lend ,and the quantity is decreased in sifi files
								//similar for other genra as well
								//qiam represents book code
								lending();
								//here 1 is indicator for sifi
								addlending(1,quan,name);
								string write;
								write="Lent out: "+sifi_books[quan-1]+ ", to: "+name;
								activity(write);
							}
					
							books book(&sifi_books[0],&sifi_quantity[0],sifi_size,"Si-fi",1,1);
						book.run();
						}
						else if(book_code==2)
						{
							fantasy();
							appendfan(0,quan);
							if(fantasy_quantity[quan-1]!=0&&roll=="THA076BCT0" && quan>=1 &&quan<=48)
							{
								lending();
								addlending(2,quan,name);
								string write;
								write="Lent out: "+fantasy_books[quan-1]+", to: "+name;
								activity(write);
							}
							books book(&fantasy_books[0],&fantasy_quantity[0],fan_size,"Fantasy",1,2);
					
							book.run();
						}
						else if(book_code==3)
						{
							sh();
							appendsh(0,quan);
						
							if(sh_quantity[quan-1]!=0&&roll=="THA076BCT0" && quan>=1 &&quan<=48)
							{
								lending();
								addlending(3,quan,name);
								string write;
								write="Lent out: "+sh_books[quan-1]+", to: "+name;
								activity(write);
							}
							books book(&sh_books[0],&sh_quantity[0],sh_size,"Self Help",1,3);
							book.run();
						}
						else if(book_code==4)
						{
							philo();
							appendphilo(0,quan);
							if(philo_quantity[quan-1]!=0&&roll=="THA076BCT0" && quan>=1 &&quan<=48)
							{
								lending();
								addlending(4,quan,name);
								string write;
								write="Lent out: "+philo_books[quan-1]+", to: "+name;
								activity(write);
							}
						
							books book(&philo_books[0],&philo_quantity[0],philo_size,"Philosophy",1,4);
							book.run();
						}
						else if(book_code==5)
						{
							bio();
							appendbio(0,quan);
						
							if(bio_quantity[quan-1]!=0&&roll=="THA076BCT0" && quan>=1 &&quan<=48)
							{
								lending();
								addlending(5,quan,name);
								string write;
								write="Lent out: "+bio_books[quan-1]+", to: "+name;
								activity(write);
							}
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
							lendbox.setFillColor(Color(170,170,170));		
					}
					
					else
					{
						
					
							back.setFillColor(Color(70,70,70));
							lendbox.setFillColor(Color(70,70,70));
					
					}
	this->window->clear(Color(70,100,100));
	this->window->draw(textbox);
	this->window->draw(text);
	this->window->draw(back);
	this->window->draw(text_back);
	this->window->draw(lendbox);
	this->window->draw(text_lend);
	this->window->draw(info);
	this->window->display();

}}
