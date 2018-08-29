#include <stdio.h>

#include "pansi.h"    // header file generated by MIDL compiler

extern BOOL g_fNetConnected;
LRESULT WINAPI NetSetupThread (LPVOID lp);

int main()
{
	DWORD id;
	CreateThread (NULL, 0, (LPTHREAD_START_ROUTINE)NetSetupThread, 0, 0, &id);

	BOOL connect = 0;
	while (1)
    {
        __try
        {
			RPC_TestProc();
			if (connect == 0)	printf("RPC connected!\n");
			connect = 1;
       	}
        __except(1)
        {
			if (connect == 1)	printf("RPC terminated!\n");
			connect = 0;
        }

        Sleep (200);
    }

	return 0;
}