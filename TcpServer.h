#pragma once
#include <WinSock2.h>
#include <iostream>
#include <Windows.h>
using namespace std;

#pragma comment (lib, "ws2_32.lib")
//初始化网络库
int initializeSocket();
//绑定端口
int bindSocketPort(short port);

