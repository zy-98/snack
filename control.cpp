//#include "food.h"
//#include "snack.h"
//#include<vector>
//#include "unit.h"
#include <conio.h>
#include "control.h"
using namespace std;
const int control::KLEFT = 5;
const int control::KUP = 2;
const int control::KWIDTH = 120;
const int control::KHEIGHT = 30;
const int control::KSCORE_OFFSET = 0;
const int control::KLEVEL_OFFSET = 0;


control::control()
{
	this->m_pFood = new food();    //初始化一个食物对象；
	this->m_pSnake = new snack();     //初始化一个蛇对象；
	this->m_iScore = 0;    //初始化分数为0；
	this->m_iLevel = 1;     //初始化当前等级为1；
	drawGameArea();   //画地图
	drawGameInfo();  //初始化基本信息
}

control::~control()
{
	delete m_pFood;
	delete m_pSnake;
	m_pFood = NULL;
	m_pSnake = NULL;
}
void control::run()
{
	
	int choice;
	control game;
	gotomap(92, 13);
	cout << "请输入你的选择:";
	game.choices();
	cin >> choice;
	
		switch (choice)
		{
		case 1:
		{  
		system("cls");              //清屏
		
		char foodstation = 'n';    //定义一个标志，判定当前地图内有无食物
		int key = 75;              //定义游戏开始的初始化方向为左
		
		control game;             //创建一个控制类的对象game
		game.d();
		m_pSnake->showsnack();
		while (true)
		{
			if (_kbhit() && _getch() == 32) //蛇最初是静止的，按空格开始移动
				break;

		}
		while (true)
		{
			
			if (_kbhit())   //检测键盘的输入来改变方向
			{
				if (_getch() == 224)
					key = _getch();
				else if (_getch() == 32)   //实现按空格暂停
				{
					while (true)
					{
						if (_getch() == 224)
							key = _getch();
						break;
					}
				}
			}
			
			if (foodstation == 'n')
			{
				m_pFood->location(&m_pSnake->vec);   //随机出现食物
				m_pFood->print();
				foodstation = 'y';

			}
			m_pSnake->changedirections(key);    //改变蛇的前进方向
			m_pSnake->move();//蛇移动
			if (game.checkFailed(m_pSnake) == 0)   //检测是否碰壁和咬到自己
			{
				break;
			}

			if (m_pSnake->eatfood(m_pFood) == true)   //判断是否吃到食物
			{
				game.changeInfo(m_pSnake);           //吃到食物后要改变分数
				game.checkLevel();                //到达一定分数后改变等级
				m_pSnake->changespeed();//吃到一个食物加快一点速度
				/*system("cls");
				game.drawGameArea();*/
				game.drawGameInfo();             //吃到食物后重新更新地图上的信息
				foodstation = 'n';               ////吃到食物后将标志变为n;
			}

		}
		}
		case 2:
			break;
		case 3:
			gotomap(50, 16);
			cout << "上下左右键移动，空格暂停";
			

		}
	
	//char foodstation = 'n';    //定义一个标志，判定当前地图内有无食物
	//int key = 75;              //定义游戏开始的初始化方向为左
	//control game;             //创建一个控制类的对象game
	//while (true)
	//{

	//	if (_kbhit())   //检测键盘的输入来改变方向
	//	{
	//		if (_getch() == 224)
	//			key = _getch();
	//		else if (_getch() == 32)
	//		{
	//			while (true)
	//			{
	//				if(_getch() == 224)
	//					key = _getch();
	//				break;
	//			}
	//		}
	//	}

	//	if (foodstation == 'n')
	//	{
	//		m_pFood->location(&m_pSnake->vec);   //随机出现食物
	//		m_pFood->print();
	//		foodstation = 'y';

	//	}
	//	m_pSnake->changedirections(key);    //改变蛇的前进方向
	//	m_pSnake->move();                   //蛇移动
	//	if (game.checkFailed(m_pSnake) == 0)   //检测是否碰壁和咬到自己
	//	{
	//		break;
	//	}
	//	
	//	if (m_pSnake->eatfood(m_pFood) == true)   //判断是否吃到食物
	//	{
	//		game.changeInfo(m_pSnake);           //吃到食物后要改变分数
	//		game.checkLevel();                //到达一定分数后改变等级
	//		m_pSnake->changespeed();//吃到一个食物加快一点速度
	//		/*system("cls");
	//		game.drawGameArea();*/
	//		game.drawGameInfo();             //吃到食物后重新更新地图上的信息
	//		foodstation = 'n';               ////吃到食物后将标志变为n;
	//	}
	//	
	//}


}

void control::drawGameArea()     //画地图
{
	
	/*char game[30][120];
	for (int i = 0; i < 30; i++)
		for (int j = 0; j < 120; j++) 
		{
			if (i == 0 || i==5 ||i == 28 || j == 0 || j == 119)
				  game[i][j] = '-';
			else game[i][j] = ' ';
		
		}
	for (int i = 0; i < 30; i++)
		for (int j = 0; j < 120; j++)
			cout << game[i][j];*/
	
	for (int i = 1; i < KHEIGHT-1; i++)     //遍历每一行
	{	
		if (i==1||i == 5 || i == 28)       //找到满足条件的行
		{
			gotomap(0, i);
			for (int j = 0; j < KWIDTH/2-4; j++)    //你要输出的个数
			{
				cout << "- ";
			}
		}
		else
		{
			gotomap(0,i);
			cout << "|";
			gotomap(90, i);
			cout << "|";
			gotomap(110,i);
			cout << "|";
		}
		
	}
	drawGameInfo();
	gotomap(1, 32);
}
	


void control::drawGameInfo()        //初始化基本信息
{
	gotomap(10, 3);
		cout << "游戏名称：贪吃蛇";
	gotomap(36, 3);
		cout << "编写者：张洋";
	gotomap(56, 3);
		cout << "当前得分："<< m_iScore;
	gotomap(76, 3);
		cout << "当前等级："<< m_iLevel;
	

}

void control::choices()
{
	gotomap(92, 15);
	cout << "1.开始游戏";
	gotomap(92, 16);
	cout << "2.退出游戏";
	gotomap(92, 17);
	cout << "3.帮助-操作说明";
	gotomap(106, 13);
}
bool control::changeInfo(snack *pSnake)                //改变分数
{
	
	   m_iScore = pSnake->vec.size() - 4;         //分数等于当前蛇的长度-蛇的初始长度
	   return m_iScore;
	

}

int control::checkFailed(snack *pSnake)      //检测是否碰墙和咬到自己
{
	
	for (int i = 1; i < pSnake->vec.size(); i++)
	{
		if ((pSnake->vec[0].x == pSnake->vec[i].x) && (pSnake->vec[0].y == pSnake->vec[i].y))   //检查蛇是否咬到自己，游戏结束
		{
			gotomap(45, 15);
			cout << "您撞到自己了,游戏结束!";
			gotomap(45, 17);
			cout << "当前得分：" << m_iScore;
			gotomap(45, 35);
			
			return 0;
			break;
		}
		
	}
	if ((pSnake->vec[0].x == 1) || (pSnake->vec[0].y == 5) || (pSnake->vec[0].x == 90) || (pSnake->vec[0].y == 28))  //检测蛇是否碰墙，游戏结束
	{
		gotomap(45, 15);
		cout << "您撞墙了,游戏结束!";
		gotomap(45, 17);
		cout << "当前得分：" << m_iScore;
		gotomap(45, 30);
		return 0;
	}
	else
		return 1;
}

int control::checkLevel()         //通过吃食物获得分数，改变当前等级
{
	
	if (m_iScore ==5)
	{
		m_iLevel = 2 + KLEVEL_OFFSET;
		gotomap(45, 15);
		cout << "恭喜进入下一关";
		Sleep(300);
		gotomap(45, 15);
		cout << "              ";


	}
	if (m_iScore == 10)
	{
		m_iLevel = 3 + KLEVEL_OFFSET;
		gotomap(45, 15);
		cout << "恭喜进入下一关";
		Sleep(300);
		gotomap(45, 15);
		cout << "              ";
	
	}
	if (m_iScore == 20)
	{
		m_iLevel = 4 + KLEVEL_OFFSET;
		gotomap(45, 15);
		cout << "恭喜进入下一关";
		Sleep(200);
		gotomap(45, 15);
		cout << "              ";
	}
	if (m_iScore ==30)
	{
		m_iLevel = 5 + KLEVEL_OFFSET;
		gotomap(45, 15);
		cout << "恭喜进入下一关";
		Sleep(200);
		gotomap(45, 15);
		cout << "              ";
	}
	if (m_iScore == 40)
	{
		m_iLevel = 6 + KLEVEL_OFFSET;
		gotomap(45, 15);
		cout << "恭喜进入下一关";
		gotomap(45, 15);
		cout << "              ";

	}
	return m_iLevel;
	
}
void control::gotomap(int x, int y)    //这是一个跳转函数，可以跳转到指定位置
{
	COORD coor;
	coor.X = x;
	coor.Y = y;
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(handle, coor);
}
void control::d()    //这是一个跳转函数，可以跳转到指定位置
{
	gotomap(94,3);
	cout << "操作信息";
	gotomap(94, 20);
	cout << "上下左右键移动";
	gotomap(94, 22);
	cout << "空格暂停";
}
