#include "Food.h"
Food::Food()
{

}
Food::~Food()
{

}

//����ʳ��
void Food::creatFood()
{
	srand((unsigned)time(NULL));
	Point* pFood = new Point;
	pFood->x = rand() % 57 + 1;
	pFood->y = rand() % 24 + 4;
	pFood->c = '#';
	pFood->next = NULL;
	setPos(pFood->x, pFood->y);
	cout << pFood->c;
	fHead = pFood;
	
	
}
//���ٿռ�
void Food::destroyFood()
{
	if (fHead == NULL)
	{
		return;
	}
	delete fHead;
	fHead = NULL;
}