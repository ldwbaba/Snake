#include "TcpServer.h"
#include "Contrl.h"

Contrl::Contrl()
{
	

}
Contrl::~Contrl()
{

}
unsigned long RecvProc(void* lpParameter);
unsigned long RecvProc2(void* data);
void selectSoct(int sock, Contrl* contrl);



//定义全局
bool sFlag = true;
bool sFlag2 = true;
SOCKET sockTemp;
SOCKET socketClient;
sockaddr_in clientMsg;
int len = sizeof(clientMsg);
int s;//接受套接字
Contrl contrl;
Contrl contrlUdp;
Unit unitUdp;

Food foodUdp;
Snake snakeUdp(foodUdp);





//开局往左跑
void Contrl::move(char c, Snake* snake, Food* food, Unit* unit)
{
	switch (c)
	{
		case UP:
				y--;
				if (y == 3)
				{
					snake->life = FALSE;
				}
				allDiret(snake, unit, food);
			
			return;
		case DOWN:
				y++;
				if (y == 29)
				{
					snake->life = FALSE;
				}
				allDiret(snake, unit, food);
			
			return;
		case LEFT:
				x--;
				if (x == 1)
				{
					snake->life = FALSE;
				}
				allDiret(snake, unit, food);
			
			return;
		case RIGHT:
				x++;
				if (x == 59)
				{
					snake->life = FALSE;
				}
				allDiret(snake, unit, food);
				return;
		case UPUDP:
			yUdp--;
			if (yUdp == 3)
			{
				snake->lifeUdp = FALSE;
			}
			allDiretUdp(snake, unit, food);
			return;
		case DOWNUDP:
			yUdp++;
			if (yUdp == 29)
			{
				snake->lifeUdp = FALSE;
			}
			allDiretUdp(snake, unit, food);
			return;
		case LEFTUDP:
			xUdp--;
			if (xUdp == 1)
			{
				snake->lifeUdp = FALSE;
			}
			allDiretUdp(snake, unit, food);
			return;
		case RIGHTUDP:
			xUdp++;
			if (xUdp == 59)
			{
				snake->lifeUdp = FALSE;
			}
			allDiretUdp(snake, unit, food);
			return;
		case SLEEP:
				system("pause");
			return;
		default:
			break;
	}
}

void Contrl::showGrade()
{
	unit->setPos(65, 15);
	
	cout << "分数：" << unit->grade;
}
void Contrl::showGrade2()
{
	unit->setPos(65, 12);

	cout << "分数：" << unit->grade;

	unit->setPos(65, 17);
	cout << "分数：" << unit->grade2;
}
void Contrl::change(Snake* snake, Food* food, Unit* unit)
{
	
	char key, tempKey = RIGHT, temp1Key; 
	while (snake->life)
	{
		temp1Key = tempKey;
		
		if (!_kbhit())
		{
			move(tempKey, snake, food, unit);
			
		}
		
		else
		{
			key = _getch();
			if (key == UP || key == RIGHT || key == LEFT || key == DOWN || key == SLEEP)
			{
				move(key, snake, food, unit);
				if (key == ' ')
				{
					tempKey = temp1Key;
				}
				else
				{
					tempKey = key;
				}
			}
			
		}
	}
}
void Contrl::changeX(Snake* snake, Food* food, Unit* unit)
{
	char key, tempKey = RIGHT, temp1Key, tempKeyUdp = RIGHTUDP, temp2Key;
	while (snake->life && snake->lifeUdp)
	{
		temp1Key = tempKey;
		temp2Key = tempKeyUdp;
		if (!_kbhit())
		{
			move(tempKey, snake, food, unit);
			move(tempKeyUdp, snake, food, unit);
		}

		else
		{
			key = _getch();
			if (key == UP || key == RIGHT || key == LEFT || key == DOWN || key == SLEEP)
			{
				move(key, snake, food, unit);
				if (key == ' ')
				{
					tempKey = temp1Key;
				}
				else
				{
					tempKey = key;
				}
			}

			if (key == UPUDP || key == RIGHTUDP || key == LEFTUDP || key == DOWNUDP || key == SLEEP)
			{
				move(key, snake, food, unit);
				if (key == ' ')
				{
					tempKeyUdp = temp2Key;
				}
				else
				{
					tempKeyUdp = key;
				}
			}
		}
	}
}

void Contrl::selectMode(int t)
{
	
	
	//实现一些蛇
	//snake = &snake1;
	switch (t)
	{
	case 1:
		playDANJI();
		return;
	case 2:
		playTwo();
		return;
	case 3:
		playInter();
		
		return;


	default:
		break;
	}
}
void Contrl::playDANJI()
{
	system("cls");
	
	unit = &unitUdp;
	food = &foodUdp;
	snake = &snakeUdp;
	unit->setName();
	system("cls");

	
	unit->creatMap();
	food->creatFood();
	snake->initSnake(snake->pHead);
	unit->p = snake->pHead;
	x = snake->pHead->x;
	y = snake->pHead->y;
	showGrade();
	
	change(snake, food, unit);
	snake->destroySnake(snake->pHead);
	unit->setPos(0, 30);
	cout << "GAME OVER!" << endl;
}
//双人模式
void Contrl::playTwo()
{
	system("cls");
	contrlUdp.unit = &unitUdp;
	contrlUdp.food = &foodUdp;
	contrlUdp.snake = &snakeUdp;
	contrlUdp.unit->setName2();
	contrlUdp.unit->creatMapTwo();
	contrlUdp.food->creatFood();
	contrlUdp.snake->initSnake(contrlUdp.snake->pHead);
	contrlUdp.snake->initSnakeUdp(contrlUdp.snake->pHeadUdp);
	contrlUdp.unit->p = contrlUdp.snake->pHead;
	contrlUdp.unit->pUdp = contrlUdp.snake->pHeadUdp;
	contrlUdp.x = contrlUdp.snake->pHead->x;
	contrlUdp.y = contrlUdp.snake->pHead->y;

	contrlUdp.xUdp = contrlUdp.snake->pHeadUdp->x;
	contrlUdp.yUdp = contrlUdp.snake->pHeadUdp->y;
	contrlUdp.showGrade2();
	//CreateThread(0, 0, (LPTHREAD_START_ROUTINE)&changeProc, (void*)&contrlUdp, 0, 0);
	contrlUdp.changeX(contrlUdp.snake, contrlUdp.food, contrlUdp.unit);
	
	contrlUdp.snake->destroySnake(contrlUdp.snake->pHead);
	contrlUdp.snake->destroySnake(contrlUdp.snake->pHeadUdp);
	contrlUdp.unit->setPos(0, 30);
	cout << "GAME OVER!" << endl;
}
void Contrl::playInter()
{
	system("cls");
	initializeSocket();
	s = bindSocketPort(8090);

	contrlUdp.unit = &unitUdp;
	contrlUdp.food = &foodUdp;
	contrlUdp.snake = &snakeUdp;
	//contrlUdp.unit->setName2();
	contrlUdp.unit->setPos(25, 15);
	cout << "等待连接。。。";
	contrlUdp.unit->setPos(25, 16);
	system("pause");

	contrlUdp.unit->creatMapTwo();
	contrlUdp.food->creatFood();
	contrlUdp.snake->initSnake(contrlUdp.snake->pHead);
	contrlUdp.snake->initSnakeUdp(contrlUdp.snake->pHeadUdp);
	contrlUdp.unit->p = contrlUdp.snake->pHead;
	contrlUdp.unit->pUdp = contrlUdp.snake->pHeadUdp;
	contrlUdp.x = contrlUdp.snake->pHead->x;
	contrlUdp.y = contrlUdp.snake->pHead->y;

	contrlUdp.xUdp = contrlUdp.snake->pHeadUdp->x;
	contrlUdp.yUdp = contrlUdp.snake->pHeadUdp->y;
	contrlUdp.showGrade2();

	selectSoct(s, &contrlUdp);

	contrlUdp.snake->destroySnake(contrlUdp.snake->pHead);
	contrlUdp.snake->destroySnake(contrlUdp.snake->pHeadUdp);
	contrlUdp.unit->setPos(0, 30);
	cout << "GAME OVER!" << endl;
}


void Contrl::changeUdp2(char uKey, Snake* snake, Unit* unit, Food* food)
{
	if (uKey == UPUDP || uKey == RIGHTUDP || uKey == LEFTUDP || uKey == DOWNUDP)
	{
		move(uKey, snake, food, unit);
	}
	else
	{
		return;
	}
}

void Contrl::changeUdp(char uKey, Snake *snake, Unit *unit, Food *food)
{
	/*char tempKey = RIGHT;
	while(!uKey == tempKey)
	{
		move(uKey, snake, food, unit);
		tempKey = uKey;
	}*/
	if (uKey == UP || uKey == RIGHT || uKey == LEFT || uKey == DOWN)
	{
		move(uKey, snake, food, unit);
	}
	else
	{
		return;
	}
	return;
}



//线程函数
unsigned long RecvProc(void* lpParameter)
{
	//SOCKET temp;
	int sock = *(int*)lpParameter;//套接字的参数传过来
	//sockTemp = sock;
	
	//创建客户端连接信息
	sockaddr_in clientMsg;
	int len = sizeof(clientMsg);
	char recvBuf[1024] = { 0 };
	recv(sock, recvBuf, 1024, 0);//接受数据 阻塞函数
	if (sFlag)
	{
		contrlUdp.unit->palyName = recvBuf;
		contrlUdp.unit->showName1(contrlUdp.unit->palyName);
		sFlag = false;
	}
	else
	{
		char key = recvBuf[0];
		contrlUdp.changeUdp(key, contrlUdp.snake, contrlUdp.unit, contrlUdp.food);
	}
	//contrl.change(c);
	return 0;
}
//线程函数
unsigned long RecvProc2(void *data)
{
	//SOCKET temp;
	int sock = *(int*)data;//套接字的参数传过来
	//sockTemp = sock;

	//创建客户端连接信息
	sockaddr_in clientMsg;
	int len = sizeof(clientMsg);
	char recvBuf[1024] = { 0 };
	if (sFlag2)
	{
		contrlUdp.unit->palyName2 = recvBuf;
		contrlUdp.unit->showName2(contrlUdp.unit->palyName2);
		sFlag2 = false;
	}
	else
	{
		char key = recvBuf[0];
		contrlUdp.changeUdp(key, contrlUdp.snake, contrlUdp.unit, contrlUdp.food);
	}
	//contrl.change(c);
	return 0;
}

//封装一下move函数
void Contrl::allDiret(Snake *snake, Unit *unit, Food *food)
{
	//判断咬到自己
	snake->bitSelf(x, y, snake->pHead);

	if (snake->eatFood(x, y))
	{
		snake->addPoint(x, y);
		unit->grade += 50;
		snake->addSpeed(unit->grade);
		showGrade();
		food->destroyFood();
		food->creatFood();
		snake->showSnake(snake->pHead);
	}
	else
	{
		snake->addPoint(x, y);
		snake->delPoint(snake->pHead);
	}
	//p节点归位
	unit->p = snake->pHead;
	//将光标放到后面
	unit->setPos(0, 30);
	unit->p = snake->pHead;
	Sleep(snake->speed);

}
void Contrl::allDiretUdp(Snake* snake, Unit* unit, Food* food)
{
	//判断咬到自己
	snake->bitSelf(xUdp, yUdp, snake->pHeadUdp);

	if (snake->eatFood(xUdp, yUdp))
	{
		snake->addPointUdp(xUdp, yUdp);
		unit->grade2 += 50;
		snake->addSpeed(unit->grade2);
		showGrade2();
		food->destroyFood();
		food->creatFood();
		snake->showSnake(snake->pHeadUdp);
	}
	else
	{
		snake->addPointUdp(xUdp, yUdp);
		snake->delPoint(snake->pHeadUdp);
	}
	//p节点归位
	unit->pUdp = snake->pHeadUdp;
	//将光标放到后面
	unit->setPos(0, 30);
	unit->pUdp = snake->pHeadUdp;
	Sleep(snake->speed);

}
void selectSoct(int sock, Contrl* contrl)
{
	//select 模型
	fd_set allSockets;
	//清零
	FD_ZERO(&allSockets);

	FD_SET(sock, &allSockets);

	while (1)
	{
		fd_set readSockets = allSockets;
		fd_set writeSockets = allSockets;
		FD_CLR(sock, &writeSockets);


		struct timeval st;
		st.tv_sec = 3;
		st.tv_usec = 0;
		int nRes = select(0, &readSockets, &writeSockets, NULL, &st);

		if (0 == nRes)
		{
			//没有相应的socket
			continue;
		}
		else if (nRes > 0)
		{
			for (u_int i = 0; i < readSockets.fd_count; i++)
			{
				if (SOCKET_ERROR == send(readSockets.fd_array[i], "ok", 2, 0))
				{
					int a = WSAGetLastError();
				}

			}


			//有相应
			for (u_int i = 0; i < readSockets.fd_count; i++)
			{
				if (readSockets.fd_array[i] == sock)
				{
					//accept 创建一个客户端socket
					SOCKET socketClient = accept(sock, NULL, NULL);
					if (INVALID_SOCKET == socketClient)
					{
						//连接出错
						continue;
					}
					FD_SET(socketClient, &allSockets);
					//send

				}
				else
				{
					if (i == 0)
					{
						CreateThread(0, 0, (LPTHREAD_START_ROUTINE)&RecvProc, (void*)&readSockets.fd_array[i], 0, 0);

					}

					if (i == 1)//CreateThread(0, 0, (LPTHREAD_START_ROUTINE)&RecvProc, (void*)&readSockets.fd_array[0], 0, 0);
					{
						CreateThread(0, 0, (LPTHREAD_START_ROUTINE)&RecvProc2, (void*)&readSockets.fd_array[i], 0, 0);

					}
				}
			}
		}
	}
}