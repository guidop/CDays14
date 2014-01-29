#include "stdafx.h"
#include "CppUnitTest.h"
#include <Windows.h>

using namespace std;

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace DllPluginTest
{		
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(LoadLib)
		{
			string dllName = "DllPlugin";
			typedef int (*pfunc)(int, int);
			HMODULE moduleHandle = GetModuleHandle(TEXT("DllPluginTest"));
			wchar_t buffer[MAX_PATH];
			GetModuleFileName(moduleHandle, buffer, MAX_PATH);
			
			auto h = LoadLibraryA(dllName.c_str());			
			int a = 0;
			pfunc p;
			if (h)
			{
				void *pp = GetProcAddress(h, "Calculate");
				p = (pfunc)pp;
				a = p(1, 4);
			}

			Assert::AreEqual(a, 5);
		}

	};
}