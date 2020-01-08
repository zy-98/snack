#pragma once
#include<vector>
#include "unit.h"
#include<Windows.h>
#include"food.h"


typedef enum 
{
	UP,
    DOWN,
	LEFT,
	RIGHT
}Directions;

class snack
{
public:
	int s_length;
	int s_x;
	int s_y;
	int s_speed;
	int  s_pic;
	char s_found;
	vector<class unit> vec;    //定义一个vector容器，里面是装的是unit类
	snack(int x = 40, int y = 10, int length = 15, Directions direction = LEFT, int speed = 300, char pic = '*');

	virtual ~snack();
	void move();   //蛇的移动
	void groupsnack(); //蛇的生长  
	void showsnack();//显示蛇
	void erasesnack();//清除蛇
	bool eatfood(food *pfood);   //吃食物
	void changedirections(int key);   //改变方向
	void changespeed();             //改变速度
};
