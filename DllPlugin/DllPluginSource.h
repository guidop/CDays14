#ifdef DLLPLUGINAPIEXPORT
#define DLLPLUGINAPI __declspec(dllexport)
#else 
#define DLLPLUGINAPI __declspec(dllimport) 
#endif

extern "C"
{
	DLLPLUGINAPI int Calculate(int a, int b);
}