#include "TcpServer.h"
unsigned long RecvProc(void* lpParameter);
int initializeSocket()
{
	WORD wdRquVirtion = MAKEWORD(2, 2);
	WSADATA wsaData;

	int nRes = WSAStartup(wdRquVirtion, &wsaData);
	if (0 != nRes)
	{
		//出错了
		int a = WSAGetLastError();
		cout << "网络库打开失败" << a << endl;
		return 0;
	}

	if (2 != HIBYTE(wsaData.wHighVersion) || 2 != LOBYTE(wsaData.wVersion))
	{
		cout << "实际打开的版本不一样！" << endl;
		WSACleanup();
		system("pause");
		return 0;
	}
	return 0;
}

int bindSocketPort(short port)
{

	SOCKET socketServer = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	if (INVALID_SOCKET == socketServer)
	{
		//出错了
		int a = WSAGetLastError();
		cout << "网络库打开失败" << a << endl;
		WSACleanup();
		system("pause");
		return 0;
	}
	struct sockaddr_in si;
	si.sin_family = AF_INET;
	si.sin_port = htons(port);
	//si.sin_addr.S_un.S_addr = 0;//愿意在本机的任意IP上面接受数据
	si.sin_addr.S_un.S_un_b.s_b1 = 127;
	si.sin_addr.S_un.S_un_b.s_b2 = 0;
	si.sin_addr.S_un.S_un_b.s_b3 = 0;
	si.sin_addr.S_un.S_un_b.s_b4 = 1;

	if (SOCKET_ERROR == bind(socketServer, (const struct sockaddr*) & si, sizeof(si)))
	{
		//出错了
		int a = WSAGetLastError();
		cout << "网络库打开失败" << a << endl;
		WSACleanup();
		system("pause");
		return 0;
	}
	if (SOCKET_ERROR == listen(socketServer, SOMAXCONN))
	{
		//出错了
		int a = WSAGetLastError();
		//释放

		closesocket(socketServer);
		WSACleanup();
		return 0;
	}
	
	return socketServer;

}
