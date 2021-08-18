#ifndef OUTBOOK_H
#define OUTBOOK_H

#include<SFML/graphics.hpp>
#include<SFML/window.hpp>
#include<SFML/network.hpp>
#include<iostream>
#include "files.h"
#include "student.h"
#include "studentid.h"
#include "books.h"
using namespace sf;
using namespace std;


class outbook:public files
{
	public:
		outbook();
	virtual	~outbook();
		Font font;
		Text text[500],text_back,text_main;
		RectangleShape back;
		RenderWindow *window;
		Event event;
		void run();
		int looping;
	protected:
			void initialize();
		void initwindow();
};

#endif
