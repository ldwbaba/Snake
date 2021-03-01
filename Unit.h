#pragma once
#include <Windows.h>
#include <iostream>
#include <conio.h>
using namespace std;

class Unit
{
public:
	Unit();
	~Unit();
	int grade = 0, grade2 = 0;
	string palyName, palyName2;
	struct Point
	{
		int x;
		int y;
		char c;
		Point* next;
	};
	Point* pHead, *fHead, *p,*pHeadUdp, *fHeadUdp, *pUdp;

	//¶¨Î»
	void setPos(int a, int b);
	void creatMap();
	int startGame();
	void setName();
	void setName2();
	void creatMapTwo();
	void showName1(string& sName);
	void showName2(string& sName);
};