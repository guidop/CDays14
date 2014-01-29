// CDays14.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <Windows.h>
#include <string>
#include <iostream>
#include "..\DummyOne\DummyOne.h"
using namespace std;

void func1()
{

}
#pragma deprecated (func1)



typedef int(*pfunc)(int, int);
int _tmain(int argc, _TCHAR* argv[])
{
	//int a;
//	int b=a*2; //C4700
//	func1(); //C4995
	
	//unsigned int u = (-5 + 4U);  //C4308
	string dllName = "Girovaga";
	char * aPath = "J:\\Progetti\\";
	SetDllDirectoryA(aPath);
	CallSleep();
	auto h = LoadLibraryA(dllName.c_str());
	pfunc p;
	int a = 0;
	if (h)
	{
		void *pp = GetProcAddress(h, "Calculate");
		p = (pfunc)pp;
		a = p(1, 4);
	}
	cout << a << endl;
	return 0;
}

