#include "unit.h"
void unit::init(int a,int b)
{
	x = a;
	y = b;
}
unit::unit(int a, int b)
{
	x = a;
	y = b;
}
unit::unit()
{

}
void  unit::show()  //显示蛇身
{
	 gotoxy(x,y);
	 cout << "*";
 
 }

void unit::erouse()   //清除蛇身
{
	gotoxy(x, y);
	cout << " ";
}

void unit::gotoxy(int x, int y)   //跳转到任意位置
{
	COORD coor;
	coor.X = x;
	coor.Y = y;
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(handle, coor);
}
