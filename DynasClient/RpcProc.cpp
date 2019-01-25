#include "pansi.h"    // header file generated by MIDL compiler
#include <stdio.h>

//==========================================================================
// MIDL allocate and free
//==========================================================================

void __RPC_FAR * __RPC_API midl_user_allocate(size_t len)
{
    return(malloc(len));
}

void __RPC_API midl_user_free(void __RPC_FAR * ptr)
{
    free(ptr);
}

//==========================================================================
// NetSetupThread
//==========================================================================

BOOL g_fNetConnected= FALSE;
LRESULT WINAPI NetTickThread (LPVOID lp);
long BindRPC ();

//void NetSetupThread (void *)
LRESULT WINAPI NetSetupThread (LPVOID lp)
{
	while ( !g_fNetConnected )
    {
    	if (BindRPC())
        {
            Sleep(10);

        	continue;
        }

        g_fNetConnected = TRUE;
    }

	DWORD id;
    CreateThread (NULL, 0, (LPTHREAD_START_ROUTINE)NetTickThread, 0, 0, &id);
	return 0L;
}

//==========================================================================
// NetTickThread
//==========================================================================

//void NetTickThread (void *)
LRESULT WINAPI NetTickThread (LPVOID lp)
{
	BOOL connect = 0;
	while ( g_fNetConnected )
    {
        __try
        {
			RPC_TestProc();
			if (connect == 0)	printf("RPC connected!\n");
			connect = 1;

       	}
        __except(1)
        {
        	g_fNetConnected = FALSE;
			if (connect == 1)	printf("RPC terminated!\n");
			connect = 0;

        }

        Sleep (200);
    }

	DWORD id;
    CreateThread (NULL, 0, (LPTHREAD_START_ROUTINE)NetSetupThread, 0, 0, &id);

    return 0L;
}

//==========================================================================
// BindRPC
//==========================================================================

long BindRPC ()
{
	long status;

    unsigned char *pszNetworkAddr = (unsigned char *)"127.0.0.1";
    unsigned char *pszProtocolSeq = (unsigned char *)DEFAULT_PROT_SEQ;
    unsigned char *pszEndpoint 	  = (unsigned char *)DEFAULT_ENDPOINT;
    unsigned char *pszUuid          = NULL;
    unsigned char *pszOptions       = NULL;
    unsigned char *pszStringBinding = NULL;

    static BOOL fBound = FALSE;

    if ( fBound )		 // unbind only if bound
    {
        status = RpcStringFree(&pszStringBinding);
        if (status)
            goto BindEnd;

        status = RpcBindingFree(&hPansi);
        if (status)
            goto BindEnd;

        fBound = FALSE;  // unbind successful; reset flag
    }

    status = RpcStringBindingCompose(pszUuid,
                                     pszProtocolSeq,
                                     pszNetworkAddr,
                                     pszEndpoint,
                                     pszOptions,
                                     &pszStringBinding);
    if (status)
        goto BindEnd;

    status = RpcBindingFromStringBinding(pszStringBinding,
                                         &hPansi);
    if (status)
        goto BindEnd;

    fBound = TRUE;  // bind successful; reset flag

BindEnd:
    return status;
}