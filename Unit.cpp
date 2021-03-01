#include "Unit.h"
Unit::Unit()
{
    
    //this->pic = p;
    pHead = NULL;
    fHead = NULL;
	p = NULL;
	pHeadUdp = NULL;
	fHeadUdp = NULL;
	pUdp = NULL;
    
}
Unit::~Unit()
{

}

void Unit::setPos(int a, int b)
{
    COORD c;

    c.X = a;
    c.Y = b;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
	
}

void Unit::creatMap()
{
	system("cls");
	setPos(10, 0);
	cout << "***************贪吃蛇游戏************** " << endl;
	setPos(12, 1);
	cout << "上 W      下 S      左 A       右 D" << endl;
	for (int i = 0; i < 60; i++)
	{
		for (int j = 3; j < 30; j++)
		{
			if (i != 0 && i != 59 && j != 3 && j != 29)
			{
				setPos(i, j);
				cout << " ";
			}
			else 
			{
				setPos(i, j);
				cout << "=";
			}

		}
	}
	setPos(65, 13);
	cout << "Player ： " << palyName;
}
int Unit::startGame()
{
	int temp;
	setPos(25, 13);
	cout << "小**小**贪**吃**蛇";
	cout << endl;
	setPos(29, 15);
	cout << "1.单人模式";
	setPos(29, 16);
	cout << "2.双人模式";
	setPos(29, 17);
	cout << "3.联网模式";
	setPos(29, 21);
	cout << "请选择：[ ]";
	setPos(38, 21);
	cin >> temp;
	return temp;

}
void Unit::setName()
{
	setPos(25, 15);
	cout << "请输入你的名字：" << endl;
	setPos(25, 16);
	cin >> palyName;
}
void Unit::creatMapTwo()
{
	system("cls");
	setPos(10, 0);
	cout << "***************贪吃蛇游戏************** " << endl;
	setPos(8, 1);
	cout << "Play1: 上 W      下 S      左 A       右 D" << endl;
	setPos(8, 2);
	cout << "Play2: 上 I      下 K      左 J       右 L" << endl;
	//setPos(3, 3);
	for (int i = 0; i < 60; i++)
	{
		for (int j = 3; j < 30; j++)
		{
			if (i != 0 && i != 59 && j != 3 && j != 29)
			{
				setPos(i, j);
				cout << " ";
			}
			else
			{
				setPos(i, j);
				cout << "=";
			}

		}
	}
	setPos(65, 10);
	cout << "Player1 ： " << palyName;
	setPos(65, 15);
	cout << "Player2 ：" << palyName2;
}
void Unit::setName2()
{
	setPos(25, 15);
	cout << "请输入Play1的名字：" << endl;
	setPos(25, 16);
	cin >> palyName;
	system("cls");
	setPos(25, 15);
	cout << "请输入Play2的名字：" << endl;
	setPos(25, 16);
	cin >> palyName2;
}
void Unit::showName1(string &sName)
{
	setPos(75, 10);
	cout << sName;
}
void Unit::showName2(string& sName)
{
	setPos(75, 15);
	cout << sName;
}