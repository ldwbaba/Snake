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

	//����ʳ��
	void creatFood();

	//���ٿռ�
	void destroyFood();
};