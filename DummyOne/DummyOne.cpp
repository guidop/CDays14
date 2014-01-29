#include "DummyOne.h"
#include <Windows.h>

DUMMY1EXPORTAPI void CallSleep()
{
	Sleep(5000);

	for (int i = 0; i < 1000000; i++)
	{

	}
}