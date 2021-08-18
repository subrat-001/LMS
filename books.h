#ifndef BOOKS_H
#define BOOKS_H
#include<SFML/graphics.hpp>
#include<SFML/window.hpp>
#include<SFML/network.hpp>
#include<iostream>
#include "student.h"
#include "files.h"
using namespace std;
using namespace sf;
class books:public files
{
	public:
		books(string*,int*,int,string,int,int);
		~books();
		void run();
	protected:
			RectangleShape back,add,lend1,getback;
			Text text[50],text1[50],texta[50],text2,back1,text_add,text_lend,text_getback,text3,text4,text5;
			Font font;
			int number,indicator,book_code;
			string name_arr[50],name_set;
			int qty_arr[50];
			void initialize();
			void initwindow();
			RenderWindow *window;
			Event event;
};

#endif
