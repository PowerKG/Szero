#pragma once
#include <WinSock2.h>
#ifndef Inputhdr_H
#define Inputhdr_H

class InputHandler
{
public:
	//���캯��
	InputHandler();
	
	//��������
	char* handle(const char[], SOCKET*);
};

#endif