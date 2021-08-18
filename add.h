#ifndef ADD_H
#define ADD_H


#include<iostream>
#include<sstream>
#include "student.h"
#include "books.h"
#include "files.h"
using namespace std;
using namespace sf;
class addbook: public files
{
	public:
		void run();
		addbook(int);
		virtual ~addbook();
		RenderWindow *window;
		Event event;
	protected:
		Font font;
		int book_code,qty;
		string str,display;
		Text text,info,text_back,text_add;
		RectangleShape textbox,back,add1;
		void initialize();
		void initwindow();
		
		
};

#endif
