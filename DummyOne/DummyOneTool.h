#ifdef DUMMY1EXPORT
#define DUMMY1EXPORTAPI __declspec(dllexport) 
#else
#define DUMMY1EXPORTAPI __declspec(dllimport) 
#endif