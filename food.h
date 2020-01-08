#pragma once
#include "unit.h"
#include <cstdlib>
#include <ctime>
#include<vector>
class food :public unit
{
	   
public:

	food(int a = 0, int b = 0, char c = '*');
	virtual  ~food();
	void location(vector<unit>*vec);   
	void print();
	
};
