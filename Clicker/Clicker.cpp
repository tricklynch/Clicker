// Clicker.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <windows.h>
using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{	
	ShowWindow(GetConsoleWindow(), SW_HIDE);

	MOUSEINPUT mInput[2];
	mInput[0] = {};
	mInput[1] = {};
	(mInput[0]).dwFlags = 0x0002;
	(mInput[1]).dwFlags = 0x0004;
	
	INPUT input[2];
	input[0] = {};
	input[1] = {};
	(input[0]).type = 0;
	(input[1]).type = 0;
	(input[0]).mi = mInput[0];
	(input[1]).mi = mInput[1];
	
	int ks = 0;
	while (1)
	{
		if (ks) 
		{
			SendInput(2, input, sizeof(INPUT));
		}
		else
		{
			Sleep(500);
		}
		Sleep(25);
		if (GetAsyncKeyState(VK_RCONTROL))
		{
			ks ^= 1;
		}
		if (GetAsyncKeyState(VK_ESCAPE))
		{
			break;
		}
	}
	return 0;
}