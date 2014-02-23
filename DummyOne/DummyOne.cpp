#include "DummyOne.h"



inline int StageValidation1()
{
	return 1;
}
inline int StageValidation2()
{
	return 2;
}

void Validatadata(int err)
{
	if ((err=StageValidation1()) != 0)
		goto Error;
	goto Error;
	if ((err = StageValidation2()) != 0)
		goto Error;

Error:
	err = -1;
}


DUMMY1EXPORTAPI void CallSleep()
{
	int err=0;
	Validatadata(err);
}