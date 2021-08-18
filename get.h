#ifndef GET_H
#define GET_H
#include<iostream>
#include<sstream>
#include "student.h"
#include "books.h"
#include "files.h"
using namespace sf;
using namespace std;
class get: public files
{
	public:
		get(int);
		virtual ~get();
		RenderWindow *window;
		Event event;
		void run();
	protected:
		Font font;
		Text text,text_get,info,text_back;
		int book_code;
		RectangleShape textbox,getbox,back;
		string str,display,name;
		void initialize();
		void initwindow();
};

#endif
