#pragma once
#include <WinSock2.h>
#include <iostream>
#include <Windows.h>
using namespace std;

#pragma comment (lib, "ws2_32.lib")
//��ʼ�������
int initializeSocket();
//�󶨶˿�
int bindSocketPort(short port);

