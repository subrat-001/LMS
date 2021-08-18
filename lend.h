#ifndef LEND_H
#define LEND_H
#include<iostream>
#include<sstream>
#include "student.h"
#include "books.h"
#include "files.h"
class lend:public files
{
	public:
		lend(int);
	virtual	~lend();
	RenderWindow *window;
		Event event;
		void run();
	protected:
		Font font;
		Text text,text_lend,info,text_back;
		int book_code;
		RectangleShape textbox,lendbox,back;
		string str,display,roll,no,name;
		void initialize();
		void initwindow();
};

#endif
