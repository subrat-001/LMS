#include "outbook.h"

outbook::outbook()
{
//	cout<<"here";
	initialize();
	initwindow();
//	cout<<" 1";
	run();
}

outbook::~outbook()
{
	delete this->window;
}
void outbook::initwindow()
{
	this->window=new RenderWindow(VideoMode(1080,720),"Lent Out",Style::Titlebar|Style::Close);
}
void outbook::initialize()
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
	//open ad get indicator and book code of different books in lent.txt to display
	ifstream fin;
	string lin("");
			fin.open("lent.txt");
				getline(fin,lin);
				text_main.setFont(font);
					text_main.setString("Out Books:");
					text_main.setFillColor(Color::White);
					text_main.setCharacterSize(25);
					text_main.setPosition(45.0f,45.0f);

    int i,mark=0;
    //string fantasy_books[fan_size];
    string word(""),q,line,check=",",check1("|");
    int j=1;
    //cout<<" 2";
    while (fin)//loops till end of the file
    {
        string apple,ball,cat;
        getline(fin,line);
        mark=0;
        string word="";
        int quan_indi(0),quan_code(0),a(0);
        i=line.length();
        while(a<i)
        {
            q=line[a];
            if (q==check)//quantity and book's name is seperated by comma
            {
                mark=1;
            }
            else if (q==check1)
            {
            	mark=2;
			}
            else
            {
                if (mark==0)
                {
                    ball=q;
                    stringstream a2(ball);//used to convert string to intiger
                    int v=0;
                    a2>>v;
                    quan_indi=quan_indi*10+v;
                    //cout<<endl<<quan_indi<<endl;
                }
                else if (mark==2)
                {
                	word+=q;
				}
                else
                {
                    apple=q;
                    stringstream a1(apple);//used to convert string to intiger
                    int u=0;
                    a1>>u;
                    quan_code=quan_code*10+u;


                }
            }

          a++;
         // cout<<" loop";
          //cout<<endl<<q<<endl;

        }
        //cout<" outa loop";
       
        string one;
        float star(18);
        float set=(float)j*star;
        if(quan_indi==1)
        {
        	sifi();
        	one="SI-FI "+sifi_books[quan_code-1]+" by "+word;
		}
		else if(quan_indi==2)
        {
        	fantasy();
        	one="FANTASY "+ fantasy_books[quan_code-1]+" by "+word;
		}
			else if(quan_indi==3)
        {
        	sh();
        	one="SELF HELP "+sh_books[quan_code-1]+" by "+word;
		}
			else if(quan_indi==4)
        {
        	philo();
        	one="PHILOSOPHY "+philo_books[quan_code-1]+" by "+word;
		}
			else if(quan_indi==2)
        {
        	bio();
        	one="BIOGRAPHY "+bio_books[quan_code-1]+" by "+word;
		}
	//	cout<<"this loop "<<one<<" "<<j<<endl;;
		
					text[j].setFont(font);
					text[j].setString(one);
					text[j].setFillColor(Color::White);
					text[j].setCharacterSize(16);
					text[j].setPosition(65.0f,85.0f+set);
		j++;			
		if (!fin.good()){ break;}
		
    }
	looping=j;
}

void outbook::run()
{
	while(this->window->isOpen())
	{
		while(this->window->pollEvent(this->event))
		{
			switch (this->event.type)
			{
				case Event::Closed:
					activity("forced log out");
				;
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
	int k=1;
	while(k<looping)
	{
	this->window->draw(text[k]);
	k++;
	}
	this->window->draw(text_main);
	this->window->draw(back);
	this->window->draw(text_back);				
	this->window->display();			
}
}

