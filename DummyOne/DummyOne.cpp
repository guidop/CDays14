#include "DummyOne.h"
#include <Windows.h>

DUMMY1EXPORTAPI void CallSleep()
{
	Sleep(5000);

	for (int i = 0; i < 1000000; i++)
	{

	}
}

class TestOne
{
private:
	
public:
	TestOne();
	const int m_a;
	const int m_b;
};

TestOne::TestOne() :m_a(0), m_b(0)
{
	
}

void TestClass()
{
	TestOne t;

	
}