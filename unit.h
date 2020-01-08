#pragma once
#include <iostream>
#include<Windows.h>
using namespace std;
class unit
{
public: 
	   int x;
	   int y;
	   char picture;
public:
	    unit(int a,int b);
		unit();
	   void init(int a=0, int b=0);
	   void show();
	   void erouse();
	   void gotoxy(int a, int b);
};
