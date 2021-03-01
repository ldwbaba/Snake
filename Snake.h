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
    typedef struct snake 		//�����һ���ڵ�
    {
        int x;
        int y;
        struct snake* next;
    }snake;
	//���ӽڵ�
	void addPoint(int a, int b);
	void addPointUdp(int a, int b);
	//�Ե�ʳ��
	bool eatFood(int x, int y);

	//��ʼ������
	void initSnake(Point *tempP);

	void initSnakeUdp(Point* tempP);

	//չʾ��
	void showSnake(Point* tempP);
	//ɾ��β���
	void delPoint(Point* tempP);

	//ҧ���Լ�
	void bitSelf(int x,int y, Point* tempP);

	//�ݻ�
	void destroySnake(Point* tempP);

	

	void addSpeed(int grade);

	//Unit& unit;
	Food& sFood;
	
};