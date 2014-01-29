#include "DllPluginSource.h"

int Calculate(int a, int b)
{
	return a + b;
}

struct aStruct
{
	int a;
};

void toTriggerStaticAnalysis()
{

	int aa;
	int *p = new int[10]; 
	delete p; //  Warning C6283
	aStruct *as = nullptr;
	as->a = 1;  //Warning C6011

	aa = 1; aa;
	{
		int aa;  //Warning C6246
			aa = 2;
	}
}