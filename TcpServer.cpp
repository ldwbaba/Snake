#include "TcpServer.h"
unsigned long RecvProc(void* lpParameter);
int initializeSocket()
{
	WORD wdRquVirtion = MAKEWORD(2, 2);
	WSADATA wsaData;

	int nRes = WSAStartup(wdRquVirtion, &wsaData);
	if (0 != nRes)
	{
		//������
		int a = WSAGetLastError();
		cout << "������ʧ��" << a << endl;
		return 0;
	}

	if (2 != HIBYTE(wsaData.wHighVersion) || 2 != LOBYTE(wsaData.wVersion))
	{
		cout << "ʵ�ʴ򿪵İ汾��һ����" << endl;
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
		//������
		int a = WSAGetLastError();
		cout << "������ʧ��" << a << endl;
		WSACleanup();
		system("pause");
		return 0;
	}
	struct sockaddr_in si;
	si.sin_family = AF_INET;
	si.sin_port = htons(port);
	//si.sin_addr.S_un.S_addr = 0;//Ը���ڱ���������IP�����������
	si.sin_addr.S_un.S_un_b.s_b1 = 127;
	si.sin_addr.S_un.S_un_b.s_b2 = 0;
	si.sin_addr.S_un.S_un_b.s_b3 = 0;
	si.sin_addr.S_un.S_un_b.s_b4 = 1;

	if (SOCKET_ERROR == bind(socketServer, (const struct sockaddr*) & si, sizeof(si)))
	{
		//������
		int a = WSAGetLastError();
		cout << "������ʧ��" << a << endl;
		WSACleanup();
		system("pause");
		return 0;
	}
	if (SOCKET_ERROR == listen(socketServer, SOMAXCONN))
	{
		//������
		int a = WSAGetLastError();
		//�ͷ�

		closesocket(socketServer);
		WSACleanup();
		return 0;
	}
	
	return socketServer;

}
