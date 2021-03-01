#pragma once
#include <Windows.h>
#include "Unit.h"
#include "Food.h"
#include <iostream>
using namespace std;

class Snake:public Food
{
public:
	
	Snake(Food& food, int x = 400);
	~Snake();
	int speed;
	bool life = TRUE;
	bool lifeUdp = TRUE;
    typedef struct snake 		//蛇身的一个节点
    {
        int x;
        int y;
        struct snake* next;
    }snake;
	//增加节点
	void addPoint(int a, int b);
	void addPointUdp(int a, int b);
	//吃到食物
	bool eatFood(int x, int y);

	//初始化蛇身
	void initSnake(Point *tempP);

	void initSnakeUdp(Point* tempP);

	//展示蛇
	void showSnake(Point* tempP);
	//删除尾结点
	void delPoint(Point* tempP);

	//咬到自己
	void bitSelf(int x,int y, Point* tempP);

	//摧毁
	void destroySnake(Point* tempP);

	

	void addSpeed(int grade);

	//Unit& unit;
	Food& sFood;
	
};