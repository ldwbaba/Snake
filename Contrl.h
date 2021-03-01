#pragma once

#include "Snake.h"
#include "Unit.h"
#include "Food.h"

class Contrl
{
public:
	Contrl();
	~Contrl();
	enum { UP = 'w', DOWN = 's', LEFT = 'a', RIGHT = 'd' ,SLEEP = ' ',UPUDP = 'i',
		DOWNUDP = 'k', LEFTUDP = 'j', RIGHTUDP = 'l'};
	//移动
	void move(char c, Snake* snake, Food* food, Unit* unit);
	void showGrade();//单人显示成绩
	void showGrade2();//双人显示成绩
	
	void change(Snake *snake, Food *food, Unit *unit);
	void changeX(Snake *snake, Food *food, Unit *unit);

	void selectMode(int t);
	//单机模式
	void playDANJI();
	//双人模式
	void playTwo();
	void playInter();

	void changeUdp(char uKey, Snake* snake, Unit* unit, Food* food);
	void changeUdp2(char uKey, Snake* snake, Unit* unit, Food* food);

	void allDiret(Snake* snake, Unit* unit, Food* food);
	void allDiretUdp(Snake* snake, Unit* unit, Food* food);
	

	

	int x;
	int y;
	int xUdp;
	int yUdp;
	Unit* unit = new Unit;
	Food* food = new Food;
	Snake* snake;
	
};
