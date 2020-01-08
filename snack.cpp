#include "snack.h"
#include<vector>
#include"food.h"
#include"unit.h"
#include<Windows.h>
#include <conio.h>
//#include"control.h"
//vector<class unit> vec;

snack::snack(int x, int y, int length, Directions direction, int speed, char pic)
{
	
		s_x = x;
		s_y = y;
		s_length = length;
		s_found = direction;
		s_speed = speed;
		s_pic = pic;

		int tempX = 0;
		int tempY = 0;

		for (int i = 0; i < s_length; i++)
		{
			switch (s_found)
			{
			case UP:
				tempX = s_x;
				tempY = s_y + i;
				break;
			case DOWN:
				tempX = s_x;
				tempY = s_y - i;
				break;
			case LEFT:
				tempX = s_x + i;
				tempY = s_y;
				break;
			case RIGHT:
				tempX = s_x - i;
				tempY = s_y;
				break;
			}
			unit unit(tempX, tempY);
			vec.push_back(unit);
		}
	}

snack::~snack()
{

}

void snack::showsnack()  //输出蛇身
{

	for (int i = 0; i < s_length; i++)
	{
		vec[i].show();
	}
}

void snack::erasesnack()  //清除蛇身
{

	for (int i = 0; i < s_length; i++)
	{
		vec[i].erouse();
	}
}
void snack::move()     //蛇身移动
{
	erasesnack(); //清除蛇身
	for (int i = s_length - 2; i >= 0; i--)
	{
		vec[i + 1].x = vec[i].x;
		vec[i + 1].y = vec[i].y;
	}
	switch (s_found)
	{
	case UP:
		vec[0].y--;
		break;
	case DOWN:
		vec[0].y++;
		break;
	case LEFT:
		vec[0].x--;
		break;
	case RIGHT:
		vec[0].x++;
		break;
	}
	
	showsnack();
	Sleep(s_speed);
	
}

	
bool snack::eatfood(food *pfood)   //判断蛇是否吃到了食物
{
	
	if (vec[0].x == pfood->x && vec[0].y == pfood->y)
	{
		groupsnack();
		return true;
	}
	
}
void snack::groupsnack()     //吃到食物后，蛇的长度加一
{

	vec.push_back(unit(vec[s_length - 1].x, vec[s_length - 1].y));
	s_length = vec.size();
}
void snack::changedirections(int key)    //改变蛇移动的方向
{
	
	   switch (key)
			{
			      /*case 'W':
					 if(s_found!=DOWN)
					  s_found = UP;
					  break;
				  case 'A':
					  if (s_found != RIGHT)
					  s_found = LEFT;
					  break;
				  case 'S':
					  if (s_found != UP)
					  s_found = DOWN;
					  break;
				  case  'D':
					  if (s_found != LEFT)
					  s_found = RIGHT;
					  break;*/
			case 72:                               //向上
				if (s_found != DOWN)
				{
					s_found = UP;
				}
				break; 
			case 75:                                //向左
				if (s_found != RIGHT)
				{
					s_found = LEFT;
				}
				break;
			case 80:                               //向下
				if (s_found !=UP)
				{
					s_found = DOWN;
				}
				break;
			case  77:                              //向右
				if (s_found != LEFT)
				{
					s_found = RIGHT;
				}
				break;
			case 32:
				while (true)
				{
					
						if (_getch() == 32)
						{
							break;
						}
					
				};
				break;
			default:
				break;
			}


}

void snack::changespeed()    //达到一定等级改变速度
{
	s_speed -=15;
}
