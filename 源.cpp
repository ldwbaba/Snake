
#include "Snake.h"
#include "Unit.h"
#include "Food.h"
#include "Contrl.h"
#include <iostream>
using namespace std;

//定义为全局


int main()
{
	Contrl cPlay;
	Unit uPlay;
	
	cPlay.selectMode(uPlay.startGame());

	////实现一些蛇
	//contrl.snake = &snake1;

	//contrl.selectMode(unit.startGame());
	//contrl.food->creatFood();
	//contrl.snake->initSnake();
	//contrl.unit->p = contrl.snake->pHead;
	//contrl.x = contrl.snake->pHead->x;
	//contrl.y = contrl.snake->pHead->y;
	//contrl.showGrade();

	//创建线程，创建完了之后，线程函数开始之心，且与主线程同事执行
	
	
	//控制光标
	cPlay.unit->setPos(0, 30);
	//cout << "GAME OVER!" << endl;
	system("pause");
	return 0;
}
