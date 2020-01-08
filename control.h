#pragma once

#include "food.h"
#include "snack.h"
//#include "food.h"
//#include "snack.h"
#include<vector>
#include "unit.h"
class control
{
 public:
	control();
	virtual ~control();

	void run();
	int checkFailed(snack *pSnake);
	int checkLevel();
	void drawGameArea();
	void drawGameInfo();
	void choices();
	bool changeInfo(snack *pSnake);
	void gotomap(int a,int b);
	void d();
public:
	static const int KLEFT;
	static const int KUP;
	static const int KWIDTH;
	static const int KHEIGHT;
	static const int KSCORE_OFFSET;
	static const int KLEVEL_OFFSET;

public:
	food *m_pFood;
	snack *m_pSnake;
	int m_iScore;
	int m_iLevel;
};
