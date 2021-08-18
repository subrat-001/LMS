#ifndef STUDENTID_H
#define STUDENTID_H
#include<SFML/graphics.hpp>
#include<SFML/window.hpp>
#include<SFML/network.hpp>
#include<iostream>
#include<string>
#include "menu.h"
#include "files.h"
#include "student.h"
using namespace std;
using namespace sf;
class studentid:public files
{
	public:
		int indicator;
		studentid();
		studentid(int);
		virtual ~studentid();
		string str,display,roll,no,name;
		Font font;
		RectangleShape textbox,back,proceed;
		Text text,text_back,text_proceed,id;
		RenderWindow *window;
		Event event;
		void run();
	protected:
		void initialize();
		void initwindow();
};

#endif
