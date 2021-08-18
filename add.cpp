#include "add.h"
#include "files.h"
addbook::addbook(int code)
{
	
	book_code=code;
	//cout<<book_code;
	initialize();
//	cout<<"ver init";
	initwindow();
//	cout<<"init win";
	run();
	
}

addbook::~addbook()
{
	delete this->window;	
}
void addbook::initialize()
{
	font.loadFromFile("times-new-roman.ttf");
	textbox.setSize(Vector2f(500.0f,40.0f));
	textbox.setFillColor(Color(425,425,425));
	textbox.setPosition(290.0f,380.0f);
	textbox.setOutlineThickness(2.0f);
	textbox.setOutlineColor(Color(500,500,500));
	add1.setSize(Vector2f(40.0f,40.0f));add1.setFillColor(Color(70,70,70));add1.setPosition(810.0f,380.0f);
	add1.setOutlineThickness(1.0f);
	add1.setOutlineColor(Color(425,425,425));
	text_add.setFont(font);
	text_add.setString(">");
	text_add.setFillColor(Color::White);
	text_add.setCharacterSize(20);
	text_add.setPosition(815.0f,385.0f);
	text_back.setFont(font);
	text_back.setString("<");
	text_back.setFillColor(Color::White);
	text_back.setCharacterSize(16);
	text_back.setPosition(25.0f,25.0f);
	text.setFont(font);
	text.setCharacterSize(24);
	text.setFillColor(Color::Black);
	text.setPosition(300.0f,390.0f);
	info.setFont(font);
	info.setCharacterSize(22);
	info.setString("Book Name,qty");
	info.setFillColor(Color::White);
	info.setPosition(100.0f,390.0f);
	back.setSize(Vector2f(25.0f,25.0f));back.setFillColor(Color(70,70,70));back.setPosition(20.0f,20.0f);
	back.setOutlineThickness(1.0f);
	back.setOutlineColor(Color(425,425,425));
}
void addbook::initwindow()
{
		this->window=new RenderWindow(VideoMode(1080,720),"Add Books",Style::Titlebar|Style::Close);
}
void addbook::run()
{
	
//running
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
                    		q1+=q;


                		}
          		  }

         			 a++;

        		}
        			if (quan==0)
        		{
        				this ->window->close();
        			
					
						addbook a(book_code);
			}
				else
        		{
				
        		string write;
        		write="Book added: "+word+" in amount of: "+q1;
        		activity(write);
				this ->window->close();
						if(book_code==1)
						{
						//adds the book enterd and its quantity to sifi files and billow functinons do the same for other genra
							sifi();
							addsifi(word,quan);
					
							books book(&sifi_books[0],&sifi_quantity[0],sifi_size,"Si-fi",1,1);
						book.run();
						}
						else if(book_code==2)
						{
							fantasy();
							addfan(word,quan);
						
							books book(&fantasy_books[0],&fantasy_quantity[0],fan_size,"Fantasy",1,2);
							book.run();
						}
						else if(book_code==3)
						{
							sh();
							addsh(word,quan);
							
							books book(&sh_books[0],&sh_quantity[0],sh_size,"Self Help",1,3);
							book.run();
						}
						else if(book_code==4)
						{
							philo();
						
							addphilo(word,quan);
						
							books book(&philo_books[0],&philo_quantity[0],philo_size,"Philosophy",1,4);
							book.run();
						}
						else if(book_code==5)
						{
							bio();
							addbio(word,quan);
						
							books book(&bio_books[0],&bio_quantity[0],bio_size,"Biography",1,5);
						book.run();
						}
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
				
						
					//	back buttons to go back to books withing different genra
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
					else if(x>=810&&x<=850&&y>=380&&y<=420)
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
                    		q1+=q;


                		}
          		  }

         			 a++;

        		}
        		if (quan==0)
        		{
        				addbook a(book_code);
        		}
				else{
				
        			string write;
        		write="Book added: "+word+" in amount of"+q1;
        		activity(write);
        		//here
				this ->window->close();
						if(book_code==1)
						{
							//similar to functions in return
							addsifi(word,quan);
						
							books book(&sifi_books[0],&sifi_quantity[0],sifi_size,"Si-fi",1,1);
						book.run();
						}
						else if(book_code==2)
						{
							addfan(word,quan);
						
							books book(&fantasy_books[0],&fantasy_quantity[0],fan_size,"Fantasy",1,2);
						
							book.run();
						}
						else if(book_code==3)
						{
							addsh(word,quan);
						
							books book(&sh_books[0],&sh_quantity[0],sh_size,"Self Help",1,3);
							book.run();
						}
						else if(book_code==4)
						{
							addphilo(word,quan);
						
							books book(&philo_books[0],&philo_quantity[0],philo_size,"Philosophy",1,4);
							book.run();
						}
						else if(book_code==5)
						{
							addbio(word,quan);
						
							books book(&bio_books[0],&bio_quantity[0],bio_size,"Biography",1,5);
						book.run();
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
					else if(x>=810&&x<=850&&y>=380&&y<=420)
					{
							add1.setFillColor(Color(170,170,170));		
					}
					
					else
					{
						
					
							back.setFillColor(Color(70,70,70));
							add1.setFillColor(Color(70,70,70));
					
					}
	this->window->clear(Color(70,100,100));
	this->window->draw(textbox);
	this->window->draw(text);
	this->window->draw(back);
	this->window->draw(text_back);
	this->window->draw(add1);
	this->window->draw(text_add);
	this->window->draw(info);
	this->window->display();
}
}
