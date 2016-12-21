// ConsoleApplication3.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "InputHandler.h"
#include <winsock2.h>
#include <Windows.h>
#include <iostream>
#include <WS2tcpip.h>
#pragma comment(lib,"ws2_32.lib")

using namespace std;

static InputHandler handlerInstance = InputHandler();

char ipsw[] = {"666666"};

typedef struct sConnection{
	SOCKET soc;
	SOCKADDR_IN addr;
}sct;

DWORD WINAPI handleClient(void* connection)
{

	sConnection* sc = (sConnection*)connection;

	SOCKADDR_IN saddr_ClientSocket = sc->addr;
	SOCKET s_ClientSocket = sc->soc;

	//获得连接数据
	char addrClient[16] = { 0 };
	inet_ntop(AF_INET, &saddr_ClientSocket.sin_addr, addrClient, 16);
	//cout << "[";
	//for (char c : addrClient)
	//{
	//	if (c == '\0')
	//		break;
	//	cout << c ;
	//}
	//cout << ":" << ntohs(saddr_ClientSocket.sin_port) << "] is connected." << endl;

	char logo[] = "\n\r    ____                      \n\r  / ___/____  ___  _________  \n\r  \\__ \\/_  / / _ \\/ ___/ __ \\ \n\r ___/ / / /_/  __/ /  / /_/ / \n\r/____/ /___/\\___/_/   \\____/  ";
	send(s_ClientSocket, logo, sizeof(logo), 0);
	char welcome[] = "\n\rSzero System is open.\n\r[$0]Please enter password: ";
	send(s_ClientSocket, welcome, sizeof(welcome), 0);

	char password[6] = { 0 };

	int nowInputlength = 0;
	char inputWords[512] = { 0 };

	//取得信息
	char recvbuf[1] = { 0 };
	int c = 0;

	bool vefed = false;
	while (recv(s_ClientSocket, recvbuf, 1, 0))
	{
		//验证密码
		if (!vefed)
		{
			password[c] = recvbuf[0];
			send(s_ClientSocket, "*", 1, 0);
			++c;
			if (c == 6)
			{
				char msg[] = "\n\r[$0]System is verifying your password.";
				send(s_ClientSocket, msg, sizeof(msg), 0);

				bool flag = false;
				for (int i = 0; i<sizeof(password); i++)
				{
					if (password[i] == ipsw[i])
					{
						continue;
					}
					else
					{
						flag = true;
						break;
					}
				}
				if (!flag)
				{
					char msg[] = "\n\r[$0]Welcome to Szero System!\n\r<$0>";
					send(s_ClientSocket, msg, sizeof(msg), 0);
					vefed = true;
				}
				else
				{
					char msg[] = "\n\r[$0]Verification failed.";
					send(s_ClientSocket, msg, sizeof(msg), 0);
					vefed = false;

					char re[] = "\n\r[$0]Please re enter password: ";
					send(s_ClientSocket, re, sizeof(re), 0);
					c = 0;
				}
			}
		}
		else//已通过验证
		{
			if (recvbuf[0] == '\b')
			{
				if (nowInputlength <= 0)
				{
					continue;
				}
				else
				{
					nowInputlength -= 1;
					inputWords[nowInputlength] = 0;
					send(s_ClientSocket, &recvbuf[0], 1, 0);
					continue;
				}
			}
			if (recvbuf[0] == '\n' || recvbuf[0] == '\r')
			{
				if (nowInputlength == 0)
				{
					continue;
				}
				else
				{
					char msg[] = "\n\r[$0]Handling command - ";
					char next[] = "\n\r";
					send(s_ClientSocket, msg, sizeof(msg), 0);
					send(s_ClientSocket, inputWords, sizeof(inputWords), 0);
					send(s_ClientSocket, next, sizeof(next), 0);

					handlerInstance.handle(inputWords, &s_ClientSocket);

					char nw[] = "<$0>";
					send(s_ClientSocket, nw, sizeof(nw), 0);

					//数据初始化
					memset(inputWords, 0, 512);
					nowInputlength = 0;
				}
			}
			else
			{
				inputWords[nowInputlength] = recvbuf[0];
				++nowInputlength;
				send(s_ClientSocket, &recvbuf[0], 1, 0);
			}
		}
	}
	return 0;
}

void remove_scrollbar()
{
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO info;
	GetConsoleScreenBufferInfo(handle, &info);
	COORD new_size =
	{
		info.srWindow.Right - info.srWindow.Left + 1,
		info.srWindow.Bottom - info.srWindow.Top + 1
	};
	SetConsoleScreenBufferSize(handle, new_size);
}

int _tmain(int argc, _TCHAR* argv[])
{

	HWND hwnd = GetForegroundWindow();
	int x = GetSystemMetrics(SM_CXSCREEN) + 300;
	int y = GetSystemMetrics(SM_CYSCREEN) + 300;
	SetWindowPos(hwnd, HWND_TOPMOST, 0, 0, x , y , NULL);




	::SendMessage(::GetConsoleWindow(), WM_SYSKEYDOWN, VK_RETURN, 0x20000000);


	remove_scrollbar();
	//HWND hwnd;
	//hwnd = FindWindow(_T("ConsoleWindowClass"), NULL); //处理顶级窗口的类名和窗口名称匹配指定的字符串,不搜索子窗口。  
	if (hwnd)
	{
		ShowWindow(hwnd, SW_HIDE);               //设置指定窗口的显示状态  
	}

	int lastref;

	//WSA初始化
	WSADATA wsaDATA;
	WORD wVersion = MAKEWORD(2, 0);//记录版本号
	lastref = WSAStartup(wVersion, &wsaDATA);//初始化
	if (lastref == SOCKET_ERROR)
	{
		cout << "Oops!" << endl;
		return 1;
	}

	//服务端SOCKET绑定
	SOCKET s_ServerSocket = socket(AF_INET,SOCK_STREAM,0);//新建SOCKET
	SOCKADDR_IN saddr_ServerSocket;
	saddr_ServerSocket.sin_addr.S_un.S_addr = htonl(INADDR_ANY);//接受任何IP
	saddr_ServerSocket.sin_family = AF_INET;//IPv4 网络协议
	saddr_ServerSocket.sin_port = htons(6666);//绑定开放端口
	lastref = bind(s_ServerSocket, (sockaddr*)&saddr_ServerSocket, sizeof(saddr_ServerSocket));//SOCKET绑定
	if (lastref == SOCKET_ERROR)
	{
		cout << "Oops!" << endl;
		return 1;
	}

	//cout <<R"(
 //                  ____                       
 //                / ___/____  ___  _________   
 //                \__ \/_  / / _ \/ ___/ __ \  
 //               ___/ / / /_/  __/ /  / /_/ /  
 //              /____/ /___/\___/_/   \____/   
//)" << endl<<endl;

	listen(s_ServerSocket, 10);//初始化监听


	//监听
	while (true)
	{
		SOCKET s_ClientSocket;//客户端的SOCKET
		SOCKADDR_IN saddr_ClientSocket;//客户端的SOCKET地址
		int saddr_ncslen = sizeof(saddr_ClientSocket);//客户端地址长度
		s_ClientSocket = accept(s_ServerSocket, (sockaddr*)&saddr_ClientSocket, &saddr_ncslen);//堵塞线程等待接入

		//整合参数
		sConnection nc ;
		nc.addr = saddr_ClientSocket;
		nc.soc = s_ClientSocket;

		::CreateThread(0, 0, handleClient, &nc, 0, NULL);
	}
	WSACleanup();
	return 0;
}

