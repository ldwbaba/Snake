
#include "Snake.h"
#include "Unit.h"
#include "Food.h"
#include "Contrl.h"
#include <iostream>
using namespace std;

//����Ϊȫ��


int main()
{
	Contrl cPlay;
	Unit uPlay;
	
	cPlay.selectMode(uPlay.startGame());

	////ʵ��һЩ��
	//contrl.snake = &snake1;

	//contrl.selectMode(unit.startGame());
	//contrl.food->creatFood();
	//contrl.snake->initSnake();
	//contrl.unit->p = contrl.snake->pHead;
	//contrl.x = contrl.snake->pHead->x;
	//contrl.y = contrl.snake->pHead->y;
	//contrl.showGrade();

	//�����̣߳���������֮���̺߳�����ʼ֮�ģ��������߳�ͬ��ִ��
	
	
	//���ƹ��
	cPlay.unit->setPos(0, 30);
	//cout << "GAME OVER!" << endl;
	system("pause");
	return 0;
}
