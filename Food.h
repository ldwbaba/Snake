#pragma once
#include "Unit.h"
#include <time.h>
#include <iostream>
using namespace std;

class Food:public Unit
{
public:
	Food();
	~Food();

	//创建食物
	void creatFood();

	//销毁空间
	void destroyFood();
};