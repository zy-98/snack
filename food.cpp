#include "food.h"
food::food(int a,int b,char c)
{
	x = a;
	y = b;
	picture = c;
}

food::~food()
{
}

void food::location(vector<unit>*vec)  //随机出现食物，不会出现在边框和蛇身上，都是伪随机
{
	vector<unit>::iterator it;
	srand((unsigned)time(NULL));
	for (it = vec->begin(); it != vec->end(); it++)
	{

		x = 1 + rand() % (89 - 3 + 1);
		y = 6 + rand() % (23 - 2 + 1);
		if (it->x == x && it->y == y)
			continue;
		else
			break;
		
	}
	
}
void food::print()
{
	/*gotoxy(x, y);
	cout << '$' << endl;*/
	gotoxy(x, y);
	cout << '$' << endl;
}
