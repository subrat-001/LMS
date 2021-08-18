#ifndef MENU_H
#define MENU_H
#include<SFML/graphics.hpp>
#include<SFML/window.hpp>
#include<SFML/network.hpp>
#include<iostream>
using namespace sf;
using namespace std;
class menu
{
	public:
		menu();
	virtual	~menu();
		//accessor
		const bool run() const;
		//functions
		void update();
		void render();
	protected:
		//enlements of this window
		RectangleShape librarian,student1;
		Font font;
		Text text_librarian,text_student,lms;
		//initiations	
		void initvariables();
		void initwindow();
		//render window
		RenderWindow *window;
		Event event;
};

#endif
