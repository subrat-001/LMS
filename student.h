#ifndef STUDENT_H
#define STUDENT_H
#include<SFML/graphics.hpp>
#include<SFML/window.hpp>
#include<SFML/network.hpp>
#include<iostream>
#include "files.h"
#include "alog.h"
#include "outbook.h"
using namespace sf;
using namespace std;

class student:public files
{
	public:
		int indicator;
		student(int);
		virtual ~student();
		void run_student();
		void update();
		RenderWindow *window;
		Event event;
		RectangleShape sifi1,fantasy1,selfhelp1,philo1,bio1,back,log,out;
		Text text_sifi,text_fantasy,text_selfhelp,text_philo,text_bio,text_back,text_log,text_out;
		Font font;
		void initialize();
		void initwindow();
};

#endif
