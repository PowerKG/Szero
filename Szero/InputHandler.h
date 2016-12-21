#pragma once
#include <WinSock2.h>
#ifndef Inputhdr_H
#define Inputhdr_H

class InputHandler
{
public:
	//构造函数
	InputHandler();
	
	//方法函数
	char* handle(const char[], SOCKET*);
};

#endif