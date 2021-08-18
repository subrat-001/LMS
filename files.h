#ifndef FILES_H
#define FILES_H
#include <iostream>
#include <stdio.h>
#include <fstream>
#include <stdlib.h>
#include <sstream>
#include <conio.h>
#include <string>
using namespace std;

class files
{
		public:
    string fantasy_books[50],bio_books[50],sifi_books[50],philo_books[50],sh_books[50];//these store name of books in an array
    int fantasy_quantity[50],bio_quantity[50],sifi_quantity[50],philo_quantity[50],sh_quantity[50];//these store the amount of books in an array
    //book in fantasy_books[3] has its equivalent no of books in fantasy_quantity[3]
    int mfantasy_quantity[50],mbio_quantity[50],msifi_quantity[50],mphilo_quantity[50],msh_quantity[50];
    int fan_size,bio_size,sifi_size,philo_size,sh_size;;//these store total no of books in a genre
    void fantasy();void displayfan();void appendfan(int,int);void addfan(string,int);
    void bio();void displaybio();void appendbio(int, int);void addbio(string,int);
    void philo();void displayphilo();void appendphilo(int, int);void addphilo(string ,int);
    void sifi();void displaysifi();void appendsifi(int, int);void addsifi(string,int);
    void sh();void displaysh();void appendsh(int ,int);void addsh(string,int);
    //functions fantasy(),bio(),sifi() etc open the file and store info in the arrays mentioned above
    //appendbio(),appendfan(),append() sifi etc is used to change data in files
        /*if a book is returned we send values of weather the (book was returned (1) and if book was burrowed(1))
                these function also update the data stored in fantasy_books[],sifi_books[] as well;
    various add functions can be used to add books(name of book as string ,number of books),it updates the data in the program as well
    display functions are only being used to check results, it needs to be changed*/
    
    void lending();void addlending(int,int,string);void appendlending(int,int,string);
    int lending_indicator[200], lending_bookcode[200],lending_size;
    string lending_rollnumber[200];
    //similar to above functions lending functions stores ,updates and adds,books lent out by the librarian,in a file "lent.txt"
    void initmax(int);
    void activity(string);
    void clearactivity();
    //activity stores different activity,and clearactivity clears activity log after boing back or closing from activity log
    //indicator for sifi,fantasy,self help,philosophy and biology are 1,2,3,4,5 respectively
    

};

#endif
