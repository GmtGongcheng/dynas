/* this ALWAYS GENERATED file contains the RPC client stubs */


/* File created by MIDL compiler version 5.01.0164 */
/* at Wed Aug 08 16:39:06 2018
 */
/* Compiler settings for PANSI.IDL:
    Os (OptLev=s), W1, Zp1, env=Win32, ms_ext, c_ext, oldnames
    error checks: allocation ref bounds_check enum stub_data 
*/
//@@MIDL_FILE_HEADING(  )

#include <string.h>
#if defined( _ALPHA_ )
#include <stdarg.h>
#endif

#include "PANSI.h"

#define TYPE_FORMAT_STRING_SIZE   479                               
#define PROC_FORMAT_STRING_SIZE   409                               

typedef struct _MIDL_TYPE_FORMAT_STRING
    {
    short          Pad;
    unsigned char  Format[ TYPE_FORMAT_STRING_SIZE ];
    } MIDL_TYPE_FORMAT_STRING;

typedef struct _MIDL_PROC_FORMAT_STRING
    {
    short          Pad;
    unsigned char  Format[ PROC_FORMAT_STRING_SIZE ];
    } MIDL_PROC_FORMAT_STRING;


extern const MIDL_TYPE_FORMAT_STRING __MIDL_TypeFormatString;
extern const MIDL_PROC_FORMAT_STRING __MIDL_ProcFormatString;

/* Standard interface: pansi, ver. 1.0,
   GUID={0x2F5F6520,0xCA46,0x1067,{0xB3,0x19,0x00,0xDD,0x01,0x06,0x62,0xDA}} */

handle_t hPansi;


static const RPC_CLIENT_INTERFACE pansi___RpcClientInterface =
    {
    sizeof(RPC_CLIENT_INTERFACE),
    {{0x2F5F6520,0xCA46,0x1067,{0xB3,0x19,0x00,0xDD,0x01,0x06,0x62,0xDA}},{1,0}},
    {{0x8A885D04,0x1CEB,0x11C9,{0x9F,0xE8,0x08,0x00,0x2B,0x10,0x48,0x60}},{2,0}},
    0,
    0,
    0,
    0,
    0,
    0
    };
RPC_IF_HANDLE pansi_ClientIfHandle = (RPC_IF_HANDLE)& pansi___RpcClientInterface;

extern const MIDL_STUB_DESC pansi_StubDesc;

static RPC_BINDING_HANDLE pansi__MIDL_AutoBindHandle;


void RPC_TestProc( void)
{

    RPC_BINDING_HANDLE _Handle	=	0;
    
    RPC_MESSAGE _RpcMessage;
    
    MIDL_STUB_MESSAGE _StubMsg;
    
    RpcTryFinally
        {
        NdrClientInitializeNew(
                          ( PRPC_MESSAGE  )&_RpcMessage,
                          ( PMIDL_STUB_MESSAGE  )&_StubMsg,
                          ( PMIDL_STUB_DESC  )&pansi_StubDesc,
                          0);
        
        
        _Handle = hPansi;
        
        
        _StubMsg.BufferLength = 0U;
        NdrGetBuffer( (PMIDL_STUB_MESSAGE) &_StubMsg, _StubMsg.BufferLength, _Handle );
        
        NdrSendReceive( (PMIDL_STUB_MESSAGE) &_StubMsg, (unsigned char __RPC_FAR *) _StubMsg.Buffer );
        
        }
    RpcFinally
        {
        NdrFreeBuffer( (PMIDL_STUB_MESSAGE) &_StubMsg );
        
        }
    RpcEndFinally
    
}


int RPC_GetPageFileNum( void)
{

    RPC_BINDING_HANDLE _Handle	=	0;
    
    int _RetVal;
    
    RPC_MESSAGE _RpcMessage;
    
    MIDL_STUB_MESSAGE _StubMsg;
    
    RpcTryFinally
        {
        NdrClientInitializeNew(
                          ( PRPC_MESSAGE  )&_RpcMessage,
                          ( PMIDL_STUB_MESSAGE  )&_StubMsg,
                          ( PMIDL_STUB_DESC  )&pansi_StubDesc,
                          1);
        
        
        _Handle = hPansi;
        
        
        _StubMsg.BufferLength = 0U;
        NdrGetBuffer( (PMIDL_STUB_MESSAGE) &_StubMsg, _StubMsg.BufferLength, _Handle );
        
        NdrSendReceive( (PMIDL_STUB_MESSAGE) &_StubMsg, (unsigned char __RPC_FAR *) _StubMsg.Buffer );
        
        if ( (_RpcMessage.DataRepresentation & 0X0000FFFFUL) != NDR_LOCAL_DATA_REPRESENTATION )
            NdrConvert( (PMIDL_STUB_MESSAGE) &_StubMsg, (PFORMAT_STRING) &__MIDL_ProcFormatString.Format[2] );
        
        _RetVal = *(( int __RPC_FAR * )_StubMsg.Buffer)++;
        
        }
    RpcFinally
        {
        NdrFreeBuffer( (PMIDL_STUB_MESSAGE) &_StubMsg );
        
        }
    RpcEndFinally
    
    return _RetVal;
}


int RPC_GetPageFilesData( 
    /* [size_is][out][in] */ PS_FILEDATA __RPC_FAR pfd[  ],
    /* [in] */ int n)
{

    RPC_BINDING_HANDLE _Handle	=	0;
    
    int _RetVal;
    
    RPC_MESSAGE _RpcMessage;
    
    MIDL_STUB_MESSAGE _StubMsg;
    
    RpcTryFinally
        {
        NdrClientInitializeNew(
                          ( PRPC_MESSAGE  )&_RpcMessage,
                          ( PMIDL_STUB_MESSAGE  )&_StubMsg,
                          ( PMIDL_STUB_DESC  )&pansi_StubDesc,
                          2);
        
        
        _Handle = hPansi;
        
        
        _StubMsg.BufferLength = 4U + 7U;
        _StubMsg.MaxCount = n;
        
        NdrConformantArrayBufferSize( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                      (unsigned char __RPC_FAR *)pfd,
                                      (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[44] );
        
        NdrGetBuffer( (PMIDL_STUB_MESSAGE) &_StubMsg, _StubMsg.BufferLength, _Handle );
        
        _StubMsg.MaxCount = n;
        
        NdrConformantArrayMarshall( (PMIDL_STUB_MESSAGE)& _StubMsg,
                                    (unsigned char __RPC_FAR *)pfd,
                                    (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[44] );
        
        *(( int __RPC_FAR * )_StubMsg.Buffer)++ = n;
        
        NdrSendReceive( (PMIDL_STUB_MESSAGE) &_StubMsg, (unsigned char __RPC_FAR *) _StubMsg.Buffer );
        
        if ( (_RpcMessage.DataRepresentation & 0X0000FFFFUL) != NDR_LOCAL_DATA_REPRESENTATION )
            NdrConvert( (PMIDL_STUB_MESSAGE) &_StubMsg, (PFORMAT_STRING) &__MIDL_ProcFormatString.Format[4] );
        
        NdrConformantArrayUnmarshall( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                      (unsigned char __RPC_FAR * __RPC_FAR *)&pfd,
                                      (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[44],
                                      (unsigned char)0 );
        
        _RetVal = *(( int __RPC_FAR * )_StubMsg.Buffer)++;
        
        }
    RpcFinally
        {
        NdrFreeBuffer( (PMIDL_STUB_MESSAGE) &_StubMsg );
        
        }
    RpcEndFinally
    
    return _RetVal;
}


int RPC_GetPageFile( 
    /* [in] */ PS_FILEDATA __RPC_FAR *pfd,
    /* [in] */ long size,
    /* [size_is][out] */ char __RPC_FAR pdata[  ])
{

    RPC_BINDING_HANDLE _Handle	=	0;
    
    int _RetVal;
    
    RPC_MESSAGE _RpcMessage;
    
    MIDL_STUB_MESSAGE _StubMsg;
    
    if(!pfd)
        {
        RpcRaiseException(RPC_X_NULL_REF_POINTER);
        }
    RpcTryFinally
        {
        NdrClientInitializeNew(
                          ( PRPC_MESSAGE  )&_RpcMessage,
                          ( PMIDL_STUB_MESSAGE  )&_StubMsg,
                          ( PMIDL_STUB_DESC  )&pansi_StubDesc,
                          3);
        
        
        _Handle = hPansi;
        
        
        _StubMsg.BufferLength = 0U + 11U;
        NdrSimpleStructBufferSize( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                   (unsigned char __RPC_FAR *)pfd,
                                   (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[26] );
        
        NdrGetBuffer( (PMIDL_STUB_MESSAGE) &_StubMsg, _StubMsg.BufferLength, _Handle );
        
        NdrSimpleStructMarshall( (PMIDL_STUB_MESSAGE)& _StubMsg,
                                 (unsigned char __RPC_FAR *)pfd,
                                 (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[26] );
        
        *(( long __RPC_FAR * )_StubMsg.Buffer)++ = size;
        
        NdrSendReceive( (PMIDL_STUB_MESSAGE) &_StubMsg, (unsigned char __RPC_FAR *) _StubMsg.Buffer );
        
        if ( (_RpcMessage.DataRepresentation & 0X0000FFFFUL) != NDR_LOCAL_DATA_REPRESENTATION )
            NdrConvert( (PMIDL_STUB_MESSAGE) &_StubMsg, (PFORMAT_STRING) &__MIDL_ProcFormatString.Format[12] );
        
        NdrConformantArrayUnmarshall( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                      (unsigned char __RPC_FAR * __RPC_FAR *)&pdata,
                                      (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[62],
                                      (unsigned char)0 );
        
        _StubMsg.Buffer = (unsigned char __RPC_FAR *)(((long)_StubMsg.Buffer + 3) & ~ 0x3);
        _RetVal = *(( int __RPC_FAR * )_StubMsg.Buffer)++;
        
        }
    RpcFinally
        {
        NdrFreeBuffer( (PMIDL_STUB_MESSAGE) &_StubMsg );
        
        }
    RpcEndFinally
    
    return _RetVal;
}


int RPC_SavePageFile( 
    /* [in] */ PS_FILEDATA __RPC_FAR *pfd,
    /* [in] */ long size,
    /* [size_is][in] */ char __RPC_FAR pdata[  ],
    /* [string][in] */ char __RPC_FAR *regname)
{

    RPC_BINDING_HANDLE _Handle	=	0;
    
    int _RetVal;
    
    RPC_MESSAGE _RpcMessage;
    
    MIDL_STUB_MESSAGE _StubMsg;
    
    if(!pfd)
        {
        RpcRaiseException(RPC_X_NULL_REF_POINTER);
        }
    if(!regname)
        {
        RpcRaiseException(RPC_X_NULL_REF_POINTER);
        }
    RpcTryFinally
        {
        NdrClientInitializeNew(
                          ( PRPC_MESSAGE  )&_RpcMessage,
                          ( PMIDL_STUB_MESSAGE  )&_StubMsg,
                          ( PMIDL_STUB_DESC  )&pansi_StubDesc,
                          4);
        
        
        _Handle = hPansi;
        
        
        _StubMsg.BufferLength = 0U + 11U + 7U + 13U;
        NdrSimpleStructBufferSize( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                   (unsigned char __RPC_FAR *)pfd,
                                   (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[26] );
        
        _StubMsg.MaxCount = size;
        
        NdrConformantArrayBufferSize( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                      (unsigned char __RPC_FAR *)pdata,
                                      (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[62] );
        
        NdrConformantStringBufferSize( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                       (unsigned char __RPC_FAR *)regname,
                                       (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[74] );
        
        NdrGetBuffer( (PMIDL_STUB_MESSAGE) &_StubMsg, _StubMsg.BufferLength, _Handle );
        
        NdrSimpleStructMarshall( (PMIDL_STUB_MESSAGE)& _StubMsg,
                                 (unsigned char __RPC_FAR *)pfd,
                                 (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[26] );
        
        *(( long __RPC_FAR * )_StubMsg.Buffer)++ = size;
        
        _StubMsg.MaxCount = size;
        
        NdrConformantArrayMarshall( (PMIDL_STUB_MESSAGE)& _StubMsg,
                                    (unsigned char __RPC_FAR *)pdata,
                                    (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[62] );
        
        NdrConformantStringMarshall( (PMIDL_STUB_MESSAGE)& _StubMsg,
                                     (unsigned char __RPC_FAR *)regname,
                                     (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[74] );
        
        NdrSendReceive( (PMIDL_STUB_MESSAGE) &_StubMsg, (unsigned char __RPC_FAR *) _StubMsg.Buffer );
        
        if ( (_RpcMessage.DataRepresentation & 0X0000FFFFUL) != NDR_LOCAL_DATA_REPRESENTATION )
            NdrConvert( (PMIDL_STUB_MESSAGE) &_StubMsg, (PFORMAT_STRING) &__MIDL_ProcFormatString.Format[24] );
        
        _RetVal = *(( int __RPC_FAR * )_StubMsg.Buffer)++;
        
        }
    RpcFinally
        {
        NdrFreeBuffer( (PMIDL_STUB_MESSAGE) &_StubMsg );
        
        }
    RpcEndFinally
    
    return _RetVal;
}


long RPC_GetVDTlid( void)
{

    RPC_BINDING_HANDLE _Handle	=	0;
    
    long _RetVal;
    
    RPC_MESSAGE _RpcMessage;
    
    MIDL_STUB_MESSAGE _StubMsg;
    
    RpcTryFinally
        {
        NdrClientInitializeNew(
                          ( PRPC_MESSAGE  )&_RpcMessage,
                          ( PMIDL_STUB_MESSAGE  )&_StubMsg,
                          ( PMIDL_STUB_DESC  )&pansi_StubDesc,
                          5);
        
        
        _Handle = hPansi;
        
        
        _StubMsg.BufferLength = 0U;
        NdrGetBuffer( (PMIDL_STUB_MESSAGE) &_StubMsg, _StubMsg.BufferLength, _Handle );
        
        NdrSendReceive( (PMIDL_STUB_MESSAGE) &_StubMsg, (unsigned char __RPC_FAR *) _StubMsg.Buffer );
        
        if ( (_RpcMessage.DataRepresentation & 0X0000FFFFUL) != NDR_LOCAL_DATA_REPRESENTATION )
            NdrConvert( (PMIDL_STUB_MESSAGE) &_StubMsg, (PFORMAT_STRING) &__MIDL_ProcFormatString.Format[2] );
        
        _RetVal = *(( long __RPC_FAR * )_StubMsg.Buffer)++;
        
        }
    RpcFinally
        {
        NdrFreeBuffer( (PMIDL_STUB_MESSAGE) &_StubMsg );
        
        }
    RpcEndFinally
    
    return _RetVal;
}


int RPC_GetSystemStruct( 
    /* [size_is][out] */ EN_ssystem __RPC_FAR *psystem)
{

    RPC_BINDING_HANDLE _Handle	=	0;
    
    int _RetVal;
    
    RPC_MESSAGE _RpcMessage;
    
    MIDL_STUB_MESSAGE _StubMsg;
    
    if(!psystem)
        {
        RpcRaiseException(RPC_X_NULL_REF_POINTER);
        }
    RpcTryFinally
        {
        NdrClientInitializeNew(
                          ( PRPC_MESSAGE  )&_RpcMessage,
                          ( PMIDL_STUB_MESSAGE  )&_StubMsg,
                          ( PMIDL_STUB_DESC  )&pansi_StubDesc,
                          6);
        
        
        _Handle = hPansi;
        
        
        _StubMsg.BufferLength = 0U;
        NdrGetBuffer( (PMIDL_STUB_MESSAGE) &_StubMsg, _StubMsg.BufferLength, _Handle );
        
        NdrSendReceive( (PMIDL_STUB_MESSAGE) &_StubMsg, (unsigned char __RPC_FAR *) _StubMsg.Buffer );
        
        if ( (_RpcMessage.DataRepresentation & 0X0000FFFFUL) != NDR_LOCAL_DATA_REPRESENTATION )
            NdrConvert( (PMIDL_STUB_MESSAGE) &_StubMsg, (PFORMAT_STRING) &__MIDL_ProcFormatString.Format[40] );
        
        NdrConformantArrayUnmarshall( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                      (unsigned char __RPC_FAR * __RPC_FAR *)&psystem,
                                      (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[122],
                                      (unsigned char)0 );
        
        _StubMsg.Buffer = (unsigned char __RPC_FAR *)(((long)_StubMsg.Buffer + 3) & ~ 0x3);
        _RetVal = *(( int __RPC_FAR * )_StubMsg.Buffer)++;
        
        }
    RpcFinally
        {
        NdrFreeBuffer( (PMIDL_STUB_MESSAGE) &_StubMsg );
        
        }
    RpcEndFinally
    
    return _RetVal;
}


int RPC_GetStationStruct( 
    /* [size_is][out] */ char __RPC_FAR pstations[  ],
    /* [in] */ int size)
{

    RPC_BINDING_HANDLE _Handle	=	0;
    
    int _RetVal;
    
    RPC_MESSAGE _RpcMessage;
    
    MIDL_STUB_MESSAGE _StubMsg;
    
    RpcTryFinally
        {
        NdrClientInitializeNew(
                          ( PRPC_MESSAGE  )&_RpcMessage,
                          ( PMIDL_STUB_MESSAGE  )&_StubMsg,
                          ( PMIDL_STUB_DESC  )&pansi_StubDesc,
                          7);
        
        
        _Handle = hPansi;
        
        
        _StubMsg.BufferLength = 4U;
        NdrGetBuffer( (PMIDL_STUB_MESSAGE) &_StubMsg, _StubMsg.BufferLength, _Handle );
        
        *(( int __RPC_FAR * )_StubMsg.Buffer)++ = size;
        
        NdrSendReceive( (PMIDL_STUB_MESSAGE) &_StubMsg, (unsigned char __RPC_FAR *) _StubMsg.Buffer );
        
        if ( (_RpcMessage.DataRepresentation & 0X0000FFFFUL) != NDR_LOCAL_DATA_REPRESENTATION )
            NdrConvert( (PMIDL_STUB_MESSAGE) &_StubMsg, (PFORMAT_STRING) &__MIDL_ProcFormatString.Format[46] );
        
        NdrConformantArrayUnmarshall( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                      (unsigned char __RPC_FAR * __RPC_FAR *)&pstations,
                                      (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[62],
                                      (unsigned char)0 );
        
        _StubMsg.Buffer = (unsigned char __RPC_FAR *)(((long)_StubMsg.Buffer + 3) & ~ 0x3);
        _RetVal = *(( int __RPC_FAR * )_StubMsg.Buffer)++;
        
        }
    RpcFinally
        {
        NdrFreeBuffer( (PMIDL_STUB_MESSAGE) &_StubMsg );
        
        }
    RpcEndFinally
    
    return _RetVal;
}


int RPC_GetYXStruct( 
    /* [size_is][out] */ char __RPC_FAR pyyx[  ],
    /* [in] */ int size,
    /* [in] */ int station)
{

    RPC_BINDING_HANDLE _Handle	=	0;
    
    int _RetVal;
    
    RPC_MESSAGE _RpcMessage;
    
    MIDL_STUB_MESSAGE _StubMsg;
    
    RpcTryFinally
        {
        NdrClientInitializeNew(
                          ( PRPC_MESSAGE  )&_RpcMessage,
                          ( PMIDL_STUB_MESSAGE  )&_StubMsg,
                          ( PMIDL_STUB_DESC  )&pansi_StubDesc,
                          8);
        
        
        _Handle = hPansi;
        
        
        _StubMsg.BufferLength = 4U + 4U;
        NdrGetBuffer( (PMIDL_STUB_MESSAGE) &_StubMsg, _StubMsg.BufferLength, _Handle );
        
        *(( int __RPC_FAR * )_StubMsg.Buffer)++ = size;
        
        *(( int __RPC_FAR * )_StubMsg.Buffer)++ = station;
        
        NdrSendReceive( (PMIDL_STUB_MESSAGE) &_StubMsg, (unsigned char __RPC_FAR *) _StubMsg.Buffer );
        
        if ( (_RpcMessage.DataRepresentation & 0X0000FFFFUL) != NDR_LOCAL_DATA_REPRESENTATION )
            NdrConvert( (PMIDL_STUB_MESSAGE) &_StubMsg, (PFORMAT_STRING) &__MIDL_ProcFormatString.Format[54] );
        
        NdrConformantArrayUnmarshall( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                      (unsigned char __RPC_FAR * __RPC_FAR *)&pyyx,
                                      (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[62],
                                      (unsigned char)0 );
        
        _StubMsg.Buffer = (unsigned char __RPC_FAR *)(((long)_StubMsg.Buffer + 3) & ~ 0x3);
        _RetVal = *(( int __RPC_FAR * )_StubMsg.Buffer)++;
        
        }
    RpcFinally
        {
        NdrFreeBuffer( (PMIDL_STUB_MESSAGE) &_StubMsg );
        
        }
    RpcEndFinally
    
    return _RetVal;
}


int RPC_GetYCStruct( 
    /* [size_is][out] */ char __RPC_FAR pyyc[  ],
    /* [in] */ int size,
    /* [in] */ int station)
{

    RPC_BINDING_HANDLE _Handle	=	0;
    
    int _RetVal;
    
    RPC_MESSAGE _RpcMessage;
    
    MIDL_STUB_MESSAGE _StubMsg;
    
    RpcTryFinally
        {
        NdrClientInitializeNew(
                          ( PRPC_MESSAGE  )&_RpcMessage,
                          ( PMIDL_STUB_MESSAGE  )&_StubMsg,
                          ( PMIDL_STUB_DESC  )&pansi_StubDesc,
                          9);
        
        
        _Handle = hPansi;
        
        
        _StubMsg.BufferLength = 4U + 4U;
        NdrGetBuffer( (PMIDL_STUB_MESSAGE) &_StubMsg, _StubMsg.BufferLength, _Handle );
        
        *(( int __RPC_FAR * )_StubMsg.Buffer)++ = size;
        
        *(( int __RPC_FAR * )_StubMsg.Buffer)++ = station;
        
        NdrSendReceive( (PMIDL_STUB_MESSAGE) &_StubMsg, (unsigned char __RPC_FAR *) _StubMsg.Buffer );
        
        if ( (_RpcMessage.DataRepresentation & 0X0000FFFFUL) != NDR_LOCAL_DATA_REPRESENTATION )
            NdrConvert( (PMIDL_STUB_MESSAGE) &_StubMsg, (PFORMAT_STRING) &__MIDL_ProcFormatString.Format[54] );
        
        NdrConformantArrayUnmarshall( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                      (unsigned char __RPC_FAR * __RPC_FAR *)&pyyc,
                                      (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[62],
                                      (unsigned char)0 );
        
        _StubMsg.Buffer = (unsigned char __RPC_FAR *)(((long)_StubMsg.Buffer + 3) & ~ 0x3);
        _RetVal = *(( int __RPC_FAR * )_StubMsg.Buffer)++;
        
        }
    RpcFinally
        {
        NdrFreeBuffer( (PMIDL_STUB_MESSAGE) &_StubMsg );
        
        }
    RpcEndFinally
    
    return _RetVal;
}


int RPC_GetYDStruct( 
    /* [size_is][out] */ char __RPC_FAR pyyd[  ],
    /* [in] */ int size,
    /* [in] */ int station)
{

    RPC_BINDING_HANDLE _Handle	=	0;
    
    int _RetVal;
    
    RPC_MESSAGE _RpcMessage;
    
    MIDL_STUB_MESSAGE _StubMsg;
    
    RpcTryFinally
        {
        NdrClientInitializeNew(
                          ( PRPC_MESSAGE  )&_RpcMessage,
                          ( PMIDL_STUB_MESSAGE  )&_StubMsg,
                          ( PMIDL_STUB_DESC  )&pansi_StubDesc,
                          10);
        
        
        _Handle = hPansi;
        
        
        _StubMsg.BufferLength = 4U + 4U;
        NdrGetBuffer( (PMIDL_STUB_MESSAGE) &_StubMsg, _StubMsg.BufferLength, _Handle );
        
        *(( int __RPC_FAR * )_StubMsg.Buffer)++ = size;
        
        *(( int __RPC_FAR * )_StubMsg.Buffer)++ = station;
        
        NdrSendReceive( (PMIDL_STUB_MESSAGE) &_StubMsg, (unsigned char __RPC_FAR *) _StubMsg.Buffer );
        
        if ( (_RpcMessage.DataRepresentation & 0X0000FFFFUL) != NDR_LOCAL_DATA_REPRESENTATION )
            NdrConvert( (PMIDL_STUB_MESSAGE) &_StubMsg, (PFORMAT_STRING) &__MIDL_ProcFormatString.Format[54] );
        
        NdrConformantArrayUnmarshall( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                      (unsigned char __RPC_FAR * __RPC_FAR *)&pyyd,
                                      (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[62],
                                      (unsigned char)0 );
        
        _StubMsg.Buffer = (unsigned char __RPC_FAR *)(((long)_StubMsg.Buffer + 3) & ~ 0x3);
        _RetVal = *(( int __RPC_FAR * )_StubMsg.Buffer)++;
        
        }
    RpcFinally
        {
        NdrFreeBuffer( (PMIDL_STUB_MESSAGE) &_StubMsg );
        
        }
    RpcEndFinally
    
    return _RetVal;
}


int RPC_GetYTStruct( 
    /* [size_is][out] */ char __RPC_FAR pyyt[  ],
    /* [in] */ int size,
    /* [in] */ int station)
{

    RPC_BINDING_HANDLE _Handle	=	0;
    
    int _RetVal;
    
    RPC_MESSAGE _RpcMessage;
    
    MIDL_STUB_MESSAGE _StubMsg;
    
    RpcTryFinally
        {
        NdrClientInitializeNew(
                          ( PRPC_MESSAGE  )&_RpcMessage,
                          ( PMIDL_STUB_MESSAGE  )&_StubMsg,
                          ( PMIDL_STUB_DESC  )&pansi_StubDesc,
                          11);
        
        
        _Handle = hPansi;
        
        
        _StubMsg.BufferLength = 4U + 4U;
        NdrGetBuffer( (PMIDL_STUB_MESSAGE) &_StubMsg, _StubMsg.BufferLength, _Handle );
        
        *(( int __RPC_FAR * )_StubMsg.Buffer)++ = size;
        
        *(( int __RPC_FAR * )_StubMsg.Buffer)++ = station;
        
        NdrSendReceive( (PMIDL_STUB_MESSAGE) &_StubMsg, (unsigned char __RPC_FAR *) _StubMsg.Buffer );
        
        if ( (_RpcMessage.DataRepresentation & 0X0000FFFFUL) != NDR_LOCAL_DATA_REPRESENTATION )
            NdrConvert( (PMIDL_STUB_MESSAGE) &_StubMsg, (PFORMAT_STRING) &__MIDL_ProcFormatString.Format[54] );
        
        NdrConformantArrayUnmarshall( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                      (unsigned char __RPC_FAR * __RPC_FAR *)&pyyt,
                                      (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[62],
                                      (unsigned char)0 );
        
        _StubMsg.Buffer = (unsigned char __RPC_FAR *)(((long)_StubMsg.Buffer + 3) & ~ 0x3);
        _RetVal = *(( int __RPC_FAR * )_StubMsg.Buffer)++;
        
        }
    RpcFinally
        {
        NdrFreeBuffer( (PMIDL_STUB_MESSAGE) &_StubMsg );
        
        }
    RpcEndFinally
    
    return _RetVal;
}


int RPC_GetExprStruct( 
    /* [size_is][out] */ char __RPC_FAR expr[  ],
    /* [in] */ int size,
    /* [in] */ int vtype)
{

    RPC_BINDING_HANDLE _Handle	=	0;
    
    int _RetVal;
    
    RPC_MESSAGE _RpcMessage;
    
    MIDL_STUB_MESSAGE _StubMsg;
    
    RpcTryFinally
        {
        NdrClientInitializeNew(
                          ( PRPC_MESSAGE  )&_RpcMessage,
                          ( PMIDL_STUB_MESSAGE  )&_StubMsg,
                          ( PMIDL_STUB_DESC  )&pansi_StubDesc,
                          12);
        
        
        _Handle = hPansi;
        
        
        _StubMsg.BufferLength = 4U + 4U;
        NdrGetBuffer( (PMIDL_STUB_MESSAGE) &_StubMsg, _StubMsg.BufferLength, _Handle );
        
        *(( int __RPC_FAR * )_StubMsg.Buffer)++ = size;
        
        *(( int __RPC_FAR * )_StubMsg.Buffer)++ = vtype;
        
        NdrSendReceive( (PMIDL_STUB_MESSAGE) &_StubMsg, (unsigned char __RPC_FAR *) _StubMsg.Buffer );
        
        if ( (_RpcMessage.DataRepresentation & 0X0000FFFFUL) != NDR_LOCAL_DATA_REPRESENTATION )
            NdrConvert( (PMIDL_STUB_MESSAGE) &_StubMsg, (PFORMAT_STRING) &__MIDL_ProcFormatString.Format[54] );
        
        NdrConformantArrayUnmarshall( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                      (unsigned char __RPC_FAR * __RPC_FAR *)&expr,
                                      (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[62],
                                      (unsigned char)0 );
        
        _StubMsg.Buffer = (unsigned char __RPC_FAR *)(((long)_StubMsg.Buffer + 3) & ~ 0x3);
        _RetVal = *(( int __RPC_FAR * )_StubMsg.Buffer)++;
        
        }
    RpcFinally
        {
        NdrFreeBuffer( (PMIDL_STUB_MESSAGE) &_StubMsg );
        
        }
    RpcEndFinally
    
    return _RetVal;
}


int RPC_UserRegister( 
    /* [size_is][out][in] */ PS_USERITEM __RPC_FAR *pUserItem)
{

    RPC_BINDING_HANDLE _Handle	=	0;
    
    int _RetVal;
    
    RPC_MESSAGE _RpcMessage;
    
    MIDL_STUB_MESSAGE _StubMsg;
    
    if(!pUserItem)
        {
        RpcRaiseException(RPC_X_NULL_REF_POINTER);
        }
    RpcTryFinally
        {
        NdrClientInitializeNew(
                          ( PRPC_MESSAGE  )&_RpcMessage,
                          ( PMIDL_STUB_MESSAGE  )&_StubMsg,
                          ( PMIDL_STUB_DESC  )&pansi_StubDesc,
                          13);
        
        
        _Handle = hPansi;
        
        
        _StubMsg.BufferLength = 4U;
        _StubMsg.MaxCount = 1;
        
        NdrConformantArrayBufferSize( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                      (unsigned char __RPC_FAR *)pUserItem,
                                      (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[174] );
        
        NdrGetBuffer( (PMIDL_STUB_MESSAGE) &_StubMsg, _StubMsg.BufferLength, _Handle );
        
        _StubMsg.MaxCount = 1;
        
        NdrConformantArrayMarshall( (PMIDL_STUB_MESSAGE)& _StubMsg,
                                    (unsigned char __RPC_FAR *)pUserItem,
                                    (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[174] );
        
        NdrSendReceive( (PMIDL_STUB_MESSAGE) &_StubMsg, (unsigned char __RPC_FAR *) _StubMsg.Buffer );
        
        if ( (_RpcMessage.DataRepresentation & 0X0000FFFFUL) != NDR_LOCAL_DATA_REPRESENTATION )
            NdrConvert( (PMIDL_STUB_MESSAGE) &_StubMsg, (PFORMAT_STRING) &__MIDL_ProcFormatString.Format[64] );
        
        NdrConformantArrayUnmarshall( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                      (unsigned char __RPC_FAR * __RPC_FAR *)&pUserItem,
                                      (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[174],
                                      (unsigned char)0 );
        
        _RetVal = *(( int __RPC_FAR * )_StubMsg.Buffer)++;
        
        }
    RpcFinally
        {
        NdrFreeBuffer( (PMIDL_STUB_MESSAGE) &_StubMsg );
        
        }
    RpcEndFinally
    
    return _RetVal;
}


int RPC_UserLogon( 
    /* [size_is][out][in] */ PS_USERITEM __RPC_FAR *pUserItem)
{

    RPC_BINDING_HANDLE _Handle	=	0;
    
    int _RetVal;
    
    RPC_MESSAGE _RpcMessage;
    
    MIDL_STUB_MESSAGE _StubMsg;
    
    if(!pUserItem)
        {
        RpcRaiseException(RPC_X_NULL_REF_POINTER);
        }
    RpcTryFinally
        {
        NdrClientInitializeNew(
                          ( PRPC_MESSAGE  )&_RpcMessage,
                          ( PMIDL_STUB_MESSAGE  )&_StubMsg,
                          ( PMIDL_STUB_DESC  )&pansi_StubDesc,
                          14);
        
        
        _Handle = hPansi;
        
        
        _StubMsg.BufferLength = 4U;
        _StubMsg.MaxCount = 1;
        
        NdrConformantArrayBufferSize( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                      (unsigned char __RPC_FAR *)pUserItem,
                                      (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[174] );
        
        NdrGetBuffer( (PMIDL_STUB_MESSAGE) &_StubMsg, _StubMsg.BufferLength, _Handle );
        
        _StubMsg.MaxCount = 1;
        
        NdrConformantArrayMarshall( (PMIDL_STUB_MESSAGE)& _StubMsg,
                                    (unsigned char __RPC_FAR *)pUserItem,
                                    (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[174] );
        
        NdrSendReceive( (PMIDL_STUB_MESSAGE) &_StubMsg, (unsigned char __RPC_FAR *) _StubMsg.Buffer );
        
        if ( (_RpcMessage.DataRepresentation & 0X0000FFFFUL) != NDR_LOCAL_DATA_REPRESENTATION )
            NdrConvert( (PMIDL_STUB_MESSAGE) &_StubMsg, (PFORMAT_STRING) &__MIDL_ProcFormatString.Format[64] );
        
        NdrConformantArrayUnmarshall( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                      (unsigned char __RPC_FAR * __RPC_FAR *)&pUserItem,
                                      (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[174],
                                      (unsigned char)0 );
        
        _RetVal = *(( int __RPC_FAR * )_StubMsg.Buffer)++;
        
        }
    RpcFinally
        {
        NdrFreeBuffer( (PMIDL_STUB_MESSAGE) &_StubMsg );
        
        }
    RpcEndFinally
    
    return _RetVal;
}


int RPC_UserLogoff( 
    /* [size_is][in] */ PS_USERITEM __RPC_FAR *pUserItem)
{

    RPC_BINDING_HANDLE _Handle	=	0;
    
    int _RetVal;
    
    RPC_MESSAGE _RpcMessage;
    
    MIDL_STUB_MESSAGE _StubMsg;
    
    if(!pUserItem)
        {
        RpcRaiseException(RPC_X_NULL_REF_POINTER);
        }
    RpcTryFinally
        {
        NdrClientInitializeNew(
                          ( PRPC_MESSAGE  )&_RpcMessage,
                          ( PMIDL_STUB_MESSAGE  )&_StubMsg,
                          ( PMIDL_STUB_DESC  )&pansi_StubDesc,
                          15);
        
        
        _Handle = hPansi;
        
        
        _StubMsg.BufferLength = 4U;
        _StubMsg.MaxCount = 1;
        
        NdrConformantArrayBufferSize( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                      (unsigned char __RPC_FAR *)pUserItem,
                                      (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[174] );
        
        NdrGetBuffer( (PMIDL_STUB_MESSAGE) &_StubMsg, _StubMsg.BufferLength, _Handle );
        
        _StubMsg.MaxCount = 1;
        
        NdrConformantArrayMarshall( (PMIDL_STUB_MESSAGE)& _StubMsg,
                                    (unsigned char __RPC_FAR *)pUserItem,
                                    (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[174] );
        
        NdrSendReceive( (PMIDL_STUB_MESSAGE) &_StubMsg, (unsigned char __RPC_FAR *) _StubMsg.Buffer );
        
        if ( (_RpcMessage.DataRepresentation & 0X0000FFFFUL) != NDR_LOCAL_DATA_REPRESENTATION )
            NdrConvert( (PMIDL_STUB_MESSAGE) &_StubMsg, (PFORMAT_STRING) &__MIDL_ProcFormatString.Format[70] );
        
        _RetVal = *(( int __RPC_FAR * )_StubMsg.Buffer)++;
        
        }
    RpcFinally
        {
        NdrFreeBuffer( (PMIDL_STUB_MESSAGE) &_StubMsg );
        
        }
    RpcEndFinally
    
    return _RetVal;
}


void RPC_GetSysTime( 
    /* [size_is][out] */ PS_DATE __RPC_FAR psdate[  ],
    /* [size_is][out] */ PS_TIME __RPC_FAR pstime[  ])
{

    RPC_BINDING_HANDLE _Handle	=	0;
    
    RPC_MESSAGE _RpcMessage;
    
    MIDL_STUB_MESSAGE _StubMsg;
    
    RpcTryFinally
        {
        NdrClientInitializeNew(
                          ( PRPC_MESSAGE  )&_RpcMessage,
                          ( PMIDL_STUB_MESSAGE  )&_StubMsg,
                          ( PMIDL_STUB_DESC  )&pansi_StubDesc,
                          16);
        
        
        _Handle = hPansi;
        
        
        _StubMsg.BufferLength = 0U;
        NdrGetBuffer( (PMIDL_STUB_MESSAGE) &_StubMsg, _StubMsg.BufferLength, _Handle );
        
        NdrSendReceive( (PMIDL_STUB_MESSAGE) &_StubMsg, (unsigned char __RPC_FAR *) _StubMsg.Buffer );
        
        if ( (_RpcMessage.DataRepresentation & 0X0000FFFFUL) != NDR_LOCAL_DATA_REPRESENTATION )
            NdrConvert( (PMIDL_STUB_MESSAGE) &_StubMsg, (PFORMAT_STRING) &__MIDL_ProcFormatString.Format[76] );
        
        NdrConformantArrayUnmarshall( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                      (unsigned char __RPC_FAR * __RPC_FAR *)&psdate,
                                      (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[188],
                                      (unsigned char)0 );
        
        NdrConformantArrayUnmarshall( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                      (unsigned char __RPC_FAR * __RPC_FAR *)&pstime,
                                      (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[202],
                                      (unsigned char)0 );
        
        }
    RpcFinally
        {
        NdrFreeBuffer( (PMIDL_STUB_MESSAGE) &_StubMsg );
        
        }
    RpcEndFinally
    
}


int RPC_GetNewEvents( 
    /* [size_is][out][in] */ char __RPC_FAR pEvents[  ],
    /* [in] */ int size)
{

    RPC_BINDING_HANDLE _Handle	=	0;
    
    int _RetVal;
    
    RPC_MESSAGE _RpcMessage;
    
    MIDL_STUB_MESSAGE _StubMsg;
    
    RpcTryFinally
        {
        NdrClientInitializeNew(
                          ( PRPC_MESSAGE  )&_RpcMessage,
                          ( PMIDL_STUB_MESSAGE  )&_StubMsg,
                          ( PMIDL_STUB_DESC  )&pansi_StubDesc,
                          17);
        
        
        _Handle = hPansi;
        
        
        _StubMsg.BufferLength = 4U + 11U;
        _StubMsg.MaxCount = size;
        
        NdrConformantArrayBufferSize( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                      (unsigned char __RPC_FAR *)pEvents,
                                      (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[62] );
        
        NdrGetBuffer( (PMIDL_STUB_MESSAGE) &_StubMsg, _StubMsg.BufferLength, _Handle );
        
        _StubMsg.MaxCount = size;
        
        NdrConformantArrayMarshall( (PMIDL_STUB_MESSAGE)& _StubMsg,
                                    (unsigned char __RPC_FAR *)pEvents,
                                    (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[62] );
        
        _StubMsg.Buffer = (unsigned char __RPC_FAR *)(((long)_StubMsg.Buffer + 3) & ~ 0x3);
        *(( int __RPC_FAR * )_StubMsg.Buffer)++ = size;
        
        NdrSendReceive( (PMIDL_STUB_MESSAGE) &_StubMsg, (unsigned char __RPC_FAR *) _StubMsg.Buffer );
        
        if ( (_RpcMessage.DataRepresentation & 0X0000FFFFUL) != NDR_LOCAL_DATA_REPRESENTATION )
            NdrConvert( (PMIDL_STUB_MESSAGE) &_StubMsg, (PFORMAT_STRING) &__MIDL_ProcFormatString.Format[86] );
        
        NdrConformantArrayUnmarshall( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                      (unsigned char __RPC_FAR * __RPC_FAR *)&pEvents,
                                      (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[62],
                                      (unsigned char)0 );
        
        _StubMsg.Buffer = (unsigned char __RPC_FAR *)(((long)_StubMsg.Buffer + 3) & ~ 0x3);
        _RetVal = *(( int __RPC_FAR * )_StubMsg.Buffer)++;
        
        }
    RpcFinally
        {
        NdrFreeBuffer( (PMIDL_STUB_MESSAGE) &_StubMsg );
        
        }
    RpcEndFinally
    
    return _RetVal;
}


int RPC_GetRealtimeData( 
    /* [size_is][in] */ long __RPC_FAR pIDs[  ],
    /* [size_is][out] */ PS_rt_gen __RPC_FAR data[  ],
    /* [in] */ int n)
{

    RPC_BINDING_HANDLE _Handle	=	0;
    
    int _RetVal;
    
    RPC_MESSAGE _RpcMessage;
    
    MIDL_STUB_MESSAGE _StubMsg;
    
    RpcTryFinally
        {
        NdrClientInitializeNew(
                          ( PRPC_MESSAGE  )&_RpcMessage,
                          ( PMIDL_STUB_MESSAGE  )&_StubMsg,
                          ( PMIDL_STUB_DESC  )&pansi_StubDesc,
                          18);
        
        
        _Handle = hPansi;
        
        
        _StubMsg.BufferLength = 4U + 7U;
        _StubMsg.MaxCount = n;
        
        NdrConformantArrayBufferSize( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                      (unsigned char __RPC_FAR *)pIDs,
                                      (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[216] );
        
        NdrGetBuffer( (PMIDL_STUB_MESSAGE) &_StubMsg, _StubMsg.BufferLength, _Handle );
        
        _StubMsg.MaxCount = n;
        
        NdrConformantArrayMarshall( (PMIDL_STUB_MESSAGE)& _StubMsg,
                                    (unsigned char __RPC_FAR *)pIDs,
                                    (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[216] );
        
        *(( int __RPC_FAR * )_StubMsg.Buffer)++ = n;
        
        NdrSendReceive( (PMIDL_STUB_MESSAGE) &_StubMsg, (unsigned char __RPC_FAR *) _StubMsg.Buffer );
        
        if ( (_RpcMessage.DataRepresentation & 0X0000FFFFUL) != NDR_LOCAL_DATA_REPRESENTATION )
            NdrConvert( (PMIDL_STUB_MESSAGE) &_StubMsg, (PFORMAT_STRING) &__MIDL_ProcFormatString.Format[94] );
        
        NdrConformantArrayUnmarshall( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                      (unsigned char __RPC_FAR * __RPC_FAR *)&data,
                                      (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[234],
                                      (unsigned char)0 );
        
        _RetVal = *(( int __RPC_FAR * )_StubMsg.Buffer)++;
        
        }
    RpcFinally
        {
        NdrFreeBuffer( (PMIDL_STUB_MESSAGE) &_StubMsg );
        
        }
    RpcEndFinally
    
    return _RetVal;
}


int RPC_GetRealtimeYXData( 
    /* [size_is][in] */ long __RPC_FAR pIDs[  ],
    /* [size_is][out] */ PS_rt_yx __RPC_FAR data[  ],
    /* [in] */ int n)
{

    RPC_BINDING_HANDLE _Handle	=	0;
    
    int _RetVal;
    
    RPC_MESSAGE _RpcMessage;
    
    MIDL_STUB_MESSAGE _StubMsg;
    
    RpcTryFinally
        {
        NdrClientInitializeNew(
                          ( PRPC_MESSAGE  )&_RpcMessage,
                          ( PMIDL_STUB_MESSAGE  )&_StubMsg,
                          ( PMIDL_STUB_DESC  )&pansi_StubDesc,
                          19);
        
        
        _Handle = hPansi;
        
        
        _StubMsg.BufferLength = 4U + 7U;
        _StubMsg.MaxCount = n;
        
        NdrConformantArrayBufferSize( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                      (unsigned char __RPC_FAR *)pIDs,
                                      (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[216] );
        
        NdrGetBuffer( (PMIDL_STUB_MESSAGE) &_StubMsg, _StubMsg.BufferLength, _Handle );
        
        _StubMsg.MaxCount = n;
        
        NdrConformantArrayMarshall( (PMIDL_STUB_MESSAGE)& _StubMsg,
                                    (unsigned char __RPC_FAR *)pIDs,
                                    (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[216] );
        
        *(( int __RPC_FAR * )_StubMsg.Buffer)++ = n;
        
        NdrSendReceive( (PMIDL_STUB_MESSAGE) &_StubMsg, (unsigned char __RPC_FAR *) _StubMsg.Buffer );
        
        if ( (_RpcMessage.DataRepresentation & 0X0000FFFFUL) != NDR_LOCAL_DATA_REPRESENTATION )
            NdrConvert( (PMIDL_STUB_MESSAGE) &_StubMsg, (PFORMAT_STRING) &__MIDL_ProcFormatString.Format[106] );
        
        NdrConformantArrayUnmarshall( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                      (unsigned char __RPC_FAR * __RPC_FAR *)&data,
                                      (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[258],
                                      (unsigned char)0 );
        
        _RetVal = *(( int __RPC_FAR * )_StubMsg.Buffer)++;
        
        }
    RpcFinally
        {
        NdrFreeBuffer( (PMIDL_STUB_MESSAGE) &_StubMsg );
        
        }
    RpcEndFinally
    
    return _RetVal;
}


int RPC_GetRealtimeYCData( 
    /* [size_is][in] */ long __RPC_FAR pIDs[  ],
    /* [size_is][out] */ PS_rt_yc __RPC_FAR data[  ],
    /* [in] */ int n)
{

    RPC_BINDING_HANDLE _Handle	=	0;
    
    int _RetVal;
    
    RPC_MESSAGE _RpcMessage;
    
    MIDL_STUB_MESSAGE _StubMsg;
    
    RpcTryFinally
        {
        NdrClientInitializeNew(
                          ( PRPC_MESSAGE  )&_RpcMessage,
                          ( PMIDL_STUB_MESSAGE  )&_StubMsg,
                          ( PMIDL_STUB_DESC  )&pansi_StubDesc,
                          20);
        
        
        _Handle = hPansi;
        
        
        _StubMsg.BufferLength = 4U + 7U;
        _StubMsg.MaxCount = n;
        
        NdrConformantArrayBufferSize( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                      (unsigned char __RPC_FAR *)pIDs,
                                      (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[216] );
        
        NdrGetBuffer( (PMIDL_STUB_MESSAGE) &_StubMsg, _StubMsg.BufferLength, _Handle );
        
        _StubMsg.MaxCount = n;
        
        NdrConformantArrayMarshall( (PMIDL_STUB_MESSAGE)& _StubMsg,
                                    (unsigned char __RPC_FAR *)pIDs,
                                    (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[216] );
        
        *(( int __RPC_FAR * )_StubMsg.Buffer)++ = n;
        
        NdrSendReceive( (PMIDL_STUB_MESSAGE) &_StubMsg, (unsigned char __RPC_FAR *) _StubMsg.Buffer );
        
        if ( (_RpcMessage.DataRepresentation & 0X0000FFFFUL) != NDR_LOCAL_DATA_REPRESENTATION )
            NdrConvert( (PMIDL_STUB_MESSAGE) &_StubMsg, (PFORMAT_STRING) &__MIDL_ProcFormatString.Format[118] );
        
        NdrConformantArrayUnmarshall( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                      (unsigned char __RPC_FAR * __RPC_FAR *)&data,
                                      (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[286],
                                      (unsigned char)0 );
        
        _RetVal = *(( int __RPC_FAR * )_StubMsg.Buffer)++;
        
        }
    RpcFinally
        {
        NdrFreeBuffer( (PMIDL_STUB_MESSAGE) &_StubMsg );
        
        }
    RpcEndFinally
    
    return _RetVal;
}


int RPC_GetRealtimeYDData( 
    /* [size_is][in] */ long __RPC_FAR pIDs[  ],
    /* [size_is][out] */ PS_rt_yd __RPC_FAR data[  ],
    /* [in] */ int n)
{

    RPC_BINDING_HANDLE _Handle	=	0;
    
    int _RetVal;
    
    RPC_MESSAGE _RpcMessage;
    
    MIDL_STUB_MESSAGE _StubMsg;
    
    RpcTryFinally
        {
        NdrClientInitializeNew(
                          ( PRPC_MESSAGE  )&_RpcMessage,
                          ( PMIDL_STUB_MESSAGE  )&_StubMsg,
                          ( PMIDL_STUB_DESC  )&pansi_StubDesc,
                          21);
        
        
        _Handle = hPansi;
        
        
        _StubMsg.BufferLength = 4U + 7U;
        _StubMsg.MaxCount = n;
        
        NdrConformantArrayBufferSize( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                      (unsigned char __RPC_FAR *)pIDs,
                                      (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[216] );
        
        NdrGetBuffer( (PMIDL_STUB_MESSAGE) &_StubMsg, _StubMsg.BufferLength, _Handle );
        
        _StubMsg.MaxCount = n;
        
        NdrConformantArrayMarshall( (PMIDL_STUB_MESSAGE)& _StubMsg,
                                    (unsigned char __RPC_FAR *)pIDs,
                                    (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[216] );
        
        *(( int __RPC_FAR * )_StubMsg.Buffer)++ = n;
        
        NdrSendReceive( (PMIDL_STUB_MESSAGE) &_StubMsg, (unsigned char __RPC_FAR *) _StubMsg.Buffer );
        
        if ( (_RpcMessage.DataRepresentation & 0X0000FFFFUL) != NDR_LOCAL_DATA_REPRESENTATION )
            NdrConvert( (PMIDL_STUB_MESSAGE) &_StubMsg, (PFORMAT_STRING) &__MIDL_ProcFormatString.Format[130] );
        
        NdrConformantArrayUnmarshall( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                      (unsigned char __RPC_FAR * __RPC_FAR *)&data,
                                      (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[312],
                                      (unsigned char)0 );
        
        _RetVal = *(( int __RPC_FAR * )_StubMsg.Buffer)++;
        
        }
    RpcFinally
        {
        NdrFreeBuffer( (PMIDL_STUB_MESSAGE) &_StubMsg );
        
        }
    RpcEndFinally
    
    return _RetVal;
}


int RPC_GetDayYXData( 
    /* [string][in] */ char __RPC_FAR *datetime,
    /* [size_is][in] */ long __RPC_FAR pIDs[  ],
    /* [size_is][out] */ PS_rt_yx __RPC_FAR data[  ],
    /* [in] */ int n)
{

    RPC_BINDING_HANDLE _Handle	=	0;
    
    int _RetVal;
    
    RPC_MESSAGE _RpcMessage;
    
    MIDL_STUB_MESSAGE _StubMsg;
    
    if(!datetime)
        {
        RpcRaiseException(RPC_X_NULL_REF_POINTER);
        }
    RpcTryFinally
        {
        NdrClientInitializeNew(
                          ( PRPC_MESSAGE  )&_RpcMessage,
                          ( PMIDL_STUB_MESSAGE  )&_StubMsg,
                          ( PMIDL_STUB_DESC  )&pansi_StubDesc,
                          22);
        
        
        _Handle = hPansi;
        
        
        _StubMsg.BufferLength = 12U + 11U + 7U;
        NdrConformantStringBufferSize( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                       (unsigned char __RPC_FAR *)datetime,
                                       (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[74] );
        
        _StubMsg.MaxCount = n;
        
        NdrConformantArrayBufferSize( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                      (unsigned char __RPC_FAR *)pIDs,
                                      (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[326] );
        
        NdrGetBuffer( (PMIDL_STUB_MESSAGE) &_StubMsg, _StubMsg.BufferLength, _Handle );
        
        NdrConformantStringMarshall( (PMIDL_STUB_MESSAGE)& _StubMsg,
                                     (unsigned char __RPC_FAR *)datetime,
                                     (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[74] );
        
        _StubMsg.MaxCount = n;
        
        NdrConformantArrayMarshall( (PMIDL_STUB_MESSAGE)& _StubMsg,
                                    (unsigned char __RPC_FAR *)pIDs,
                                    (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[326] );
        
        *(( int __RPC_FAR * )_StubMsg.Buffer)++ = n;
        
        NdrSendReceive( (PMIDL_STUB_MESSAGE) &_StubMsg, (unsigned char __RPC_FAR *) _StubMsg.Buffer );
        
        if ( (_RpcMessage.DataRepresentation & 0X0000FFFFUL) != NDR_LOCAL_DATA_REPRESENTATION )
            NdrConvert( (PMIDL_STUB_MESSAGE) &_StubMsg, (PFORMAT_STRING) &__MIDL_ProcFormatString.Format[142] );
        
        NdrConformantArrayUnmarshall( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                      (unsigned char __RPC_FAR * __RPC_FAR *)&data,
                                      (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[336],
                                      (unsigned char)0 );
        
        _RetVal = *(( int __RPC_FAR * )_StubMsg.Buffer)++;
        
        }
    RpcFinally
        {
        NdrFreeBuffer( (PMIDL_STUB_MESSAGE) &_StubMsg );
        
        }
    RpcEndFinally
    
    return _RetVal;
}


int RPC_GetDayYCData( 
    /* [string][in] */ char __RPC_FAR *datetime,
    /* [size_is][in] */ long __RPC_FAR pIDs[  ],
    /* [size_is][out] */ PS_rt_yc __RPC_FAR data[  ],
    /* [in] */ int n)
{

    RPC_BINDING_HANDLE _Handle	=	0;
    
    int _RetVal;
    
    RPC_MESSAGE _RpcMessage;
    
    MIDL_STUB_MESSAGE _StubMsg;
    
    if(!datetime)
        {
        RpcRaiseException(RPC_X_NULL_REF_POINTER);
        }
    RpcTryFinally
        {
        NdrClientInitializeNew(
                          ( PRPC_MESSAGE  )&_RpcMessage,
                          ( PMIDL_STUB_MESSAGE  )&_StubMsg,
                          ( PMIDL_STUB_DESC  )&pansi_StubDesc,
                          23);
        
        
        _Handle = hPansi;
        
        
        _StubMsg.BufferLength = 12U + 11U + 7U;
        NdrConformantStringBufferSize( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                       (unsigned char __RPC_FAR *)datetime,
                                       (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[74] );
        
        _StubMsg.MaxCount = n;
        
        NdrConformantArrayBufferSize( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                      (unsigned char __RPC_FAR *)pIDs,
                                      (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[326] );
        
        NdrGetBuffer( (PMIDL_STUB_MESSAGE) &_StubMsg, _StubMsg.BufferLength, _Handle );
        
        NdrConformantStringMarshall( (PMIDL_STUB_MESSAGE)& _StubMsg,
                                     (unsigned char __RPC_FAR *)datetime,
                                     (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[74] );
        
        _StubMsg.MaxCount = n;
        
        NdrConformantArrayMarshall( (PMIDL_STUB_MESSAGE)& _StubMsg,
                                    (unsigned char __RPC_FAR *)pIDs,
                                    (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[326] );
        
        *(( int __RPC_FAR * )_StubMsg.Buffer)++ = n;
        
        NdrSendReceive( (PMIDL_STUB_MESSAGE) &_StubMsg, (unsigned char __RPC_FAR *) _StubMsg.Buffer );
        
        if ( (_RpcMessage.DataRepresentation & 0X0000FFFFUL) != NDR_LOCAL_DATA_REPRESENTATION )
            NdrConvert( (PMIDL_STUB_MESSAGE) &_StubMsg, (PFORMAT_STRING) &__MIDL_ProcFormatString.Format[158] );
        
        NdrConformantArrayUnmarshall( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                      (unsigned char __RPC_FAR * __RPC_FAR *)&data,
                                      (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[350],
                                      (unsigned char)0 );
        
        _RetVal = *(( int __RPC_FAR * )_StubMsg.Buffer)++;
        
        }
    RpcFinally
        {
        NdrFreeBuffer( (PMIDL_STUB_MESSAGE) &_StubMsg );
        
        }
    RpcEndFinally
    
    return _RetVal;
}


int RPC_GetDayYDData( 
    /* [string][in] */ char __RPC_FAR *datetime,
    /* [size_is][in] */ long __RPC_FAR pIDs[  ],
    /* [size_is][out] */ PS_rt_yd __RPC_FAR data[  ],
    /* [in] */ int n)
{

    RPC_BINDING_HANDLE _Handle	=	0;
    
    int _RetVal;
    
    RPC_MESSAGE _RpcMessage;
    
    MIDL_STUB_MESSAGE _StubMsg;
    
    if(!datetime)
        {
        RpcRaiseException(RPC_X_NULL_REF_POINTER);
        }
    RpcTryFinally
        {
        NdrClientInitializeNew(
                          ( PRPC_MESSAGE  )&_RpcMessage,
                          ( PMIDL_STUB_MESSAGE  )&_StubMsg,
                          ( PMIDL_STUB_DESC  )&pansi_StubDesc,
                          24);
        
        
        _Handle = hPansi;
        
        
        _StubMsg.BufferLength = 12U + 11U + 7U;
        NdrConformantStringBufferSize( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                       (unsigned char __RPC_FAR *)datetime,
                                       (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[74] );
        
        _StubMsg.MaxCount = n;
        
        NdrConformantArrayBufferSize( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                      (unsigned char __RPC_FAR *)pIDs,
                                      (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[326] );
        
        NdrGetBuffer( (PMIDL_STUB_MESSAGE) &_StubMsg, _StubMsg.BufferLength, _Handle );
        
        NdrConformantStringMarshall( (PMIDL_STUB_MESSAGE)& _StubMsg,
                                     (unsigned char __RPC_FAR *)datetime,
                                     (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[74] );
        
        _StubMsg.MaxCount = n;
        
        NdrConformantArrayMarshall( (PMIDL_STUB_MESSAGE)& _StubMsg,
                                    (unsigned char __RPC_FAR *)pIDs,
                                    (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[326] );
        
        *(( int __RPC_FAR * )_StubMsg.Buffer)++ = n;
        
        NdrSendReceive( (PMIDL_STUB_MESSAGE) &_StubMsg, (unsigned char __RPC_FAR *) _StubMsg.Buffer );
        
        if ( (_RpcMessage.DataRepresentation & 0X0000FFFFUL) != NDR_LOCAL_DATA_REPRESENTATION )
            NdrConvert( (PMIDL_STUB_MESSAGE) &_StubMsg, (PFORMAT_STRING) &__MIDL_ProcFormatString.Format[174] );
        
        NdrConformantArrayUnmarshall( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                      (unsigned char __RPC_FAR * __RPC_FAR *)&data,
                                      (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[364],
                                      (unsigned char)0 );
        
        _RetVal = *(( int __RPC_FAR * )_StubMsg.Buffer)++;
        
        }
    RpcFinally
        {
        NdrFreeBuffer( (PMIDL_STUB_MESSAGE) &_StubMsg );
        
        }
    RpcEndFinally
    
    return _RetVal;
}


void RPC_ManSetValue( 
    /* [in] */ long varID,
    /* [in] */ float value,
    /* [string][in] */ char __RPC_FAR *regname)
{

    RPC_BINDING_HANDLE _Handle	=	0;
    
    RPC_MESSAGE _RpcMessage;
    
    MIDL_STUB_MESSAGE _StubMsg;
    
    if(!regname)
        {
        RpcRaiseException(RPC_X_NULL_REF_POINTER);
        }
    RpcTryFinally
        {
        NdrClientInitializeNew(
                          ( PRPC_MESSAGE  )&_RpcMessage,
                          ( PMIDL_STUB_MESSAGE  )&_StubMsg,
                          ( PMIDL_STUB_DESC  )&pansi_StubDesc,
                          25);
        
        
        _Handle = hPansi;
        
        
        _StubMsg.BufferLength = 4U + 4U + 12U;
        NdrConformantStringBufferSize( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                       (unsigned char __RPC_FAR *)regname,
                                       (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[74] );
        
        NdrGetBuffer( (PMIDL_STUB_MESSAGE) &_StubMsg, _StubMsg.BufferLength, _Handle );
        
        *(( long __RPC_FAR * )_StubMsg.Buffer)++ = varID;
        
        *(( float __RPC_FAR * )_StubMsg.Buffer)++ = value;
        
        NdrConformantStringMarshall( (PMIDL_STUB_MESSAGE)& _StubMsg,
                                     (unsigned char __RPC_FAR *)regname,
                                     (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[74] );
        
        NdrSendReceive( (PMIDL_STUB_MESSAGE) &_StubMsg, (unsigned char __RPC_FAR *) _StubMsg.Buffer );
        
        }
    RpcFinally
        {
        NdrFreeBuffer( (PMIDL_STUB_MESSAGE) &_StubMsg );
        
        }
    RpcEndFinally
    
}


void RPC_DontCareValue( 
    /* [in] */ long varID,
    /* [string][in] */ char __RPC_FAR *regname)
{

    RPC_BINDING_HANDLE _Handle	=	0;
    
    RPC_MESSAGE _RpcMessage;
    
    MIDL_STUB_MESSAGE _StubMsg;
    
    if(!regname)
        {
        RpcRaiseException(RPC_X_NULL_REF_POINTER);
        }
    RpcTryFinally
        {
        NdrClientInitializeNew(
                          ( PRPC_MESSAGE  )&_RpcMessage,
                          ( PMIDL_STUB_MESSAGE  )&_StubMsg,
                          ( PMIDL_STUB_DESC  )&pansi_StubDesc,
                          26);
        
        
        _Handle = hPansi;
        
        
        _StubMsg.BufferLength = 4U + 12U;
        NdrConformantStringBufferSize( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                       (unsigned char __RPC_FAR *)regname,
                                       (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[74] );
        
        NdrGetBuffer( (PMIDL_STUB_MESSAGE) &_StubMsg, _StubMsg.BufferLength, _Handle );
        
        *(( long __RPC_FAR * )_StubMsg.Buffer)++ = varID;
        
        NdrConformantStringMarshall( (PMIDL_STUB_MESSAGE)& _StubMsg,
                                     (unsigned char __RPC_FAR *)regname,
                                     (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[74] );
        
        NdrSendReceive( (PMIDL_STUB_MESSAGE) &_StubMsg, (unsigned char __RPC_FAR *) _StubMsg.Buffer );
        
        }
    RpcFinally
        {
        NdrFreeBuffer( (PMIDL_STUB_MESSAGE) &_StubMsg );
        
        }
    RpcEndFinally
    
}


void RPC_FreshValue( 
    /* [in] */ long varID,
    /* [string][in] */ char __RPC_FAR *regname)
{

    RPC_BINDING_HANDLE _Handle	=	0;
    
    RPC_MESSAGE _RpcMessage;
    
    MIDL_STUB_MESSAGE _StubMsg;
    
    if(!regname)
        {
        RpcRaiseException(RPC_X_NULL_REF_POINTER);
        }
    RpcTryFinally
        {
        NdrClientInitializeNew(
                          ( PRPC_MESSAGE  )&_RpcMessage,
                          ( PMIDL_STUB_MESSAGE  )&_StubMsg,
                          ( PMIDL_STUB_DESC  )&pansi_StubDesc,
                          27);
        
        
        _Handle = hPansi;
        
        
        _StubMsg.BufferLength = 4U + 12U;
        NdrConformantStringBufferSize( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                       (unsigned char __RPC_FAR *)regname,
                                       (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[74] );
        
        NdrGetBuffer( (PMIDL_STUB_MESSAGE) &_StubMsg, _StubMsg.BufferLength, _Handle );
        
        *(( long __RPC_FAR * )_StubMsg.Buffer)++ = varID;
        
        NdrConformantStringMarshall( (PMIDL_STUB_MESSAGE)& _StubMsg,
                                     (unsigned char __RPC_FAR *)regname,
                                     (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[74] );
        
        NdrSendReceive( (PMIDL_STUB_MESSAGE) &_StubMsg, (unsigned char __RPC_FAR *) _StubMsg.Buffer );
        
        }
    RpcFinally
        {
        NdrFreeBuffer( (PMIDL_STUB_MESSAGE) &_StubMsg );
        
        }
    RpcEndFinally
    
}


void RPC_YKRequest( 
    /* [in] */ long varID,
    /* [in] */ float tovalue,
    /* [string][in] */ char __RPC_FAR *regname)
{

    RPC_BINDING_HANDLE _Handle	=	0;
    
    RPC_MESSAGE _RpcMessage;
    
    MIDL_STUB_MESSAGE _StubMsg;
    
    if(!regname)
        {
        RpcRaiseException(RPC_X_NULL_REF_POINTER);
        }
    RpcTryFinally
        {
        NdrClientInitializeNew(
                          ( PRPC_MESSAGE  )&_RpcMessage,
                          ( PMIDL_STUB_MESSAGE  )&_StubMsg,
                          ( PMIDL_STUB_DESC  )&pansi_StubDesc,
                          28);
        
        
        _Handle = hPansi;
        
        
        _StubMsg.BufferLength = 4U + 4U + 12U;
        NdrConformantStringBufferSize( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                       (unsigned char __RPC_FAR *)regname,
                                       (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[74] );
        
        NdrGetBuffer( (PMIDL_STUB_MESSAGE) &_StubMsg, _StubMsg.BufferLength, _Handle );
        
        *(( long __RPC_FAR * )_StubMsg.Buffer)++ = varID;
        
        *(( float __RPC_FAR * )_StubMsg.Buffer)++ = tovalue;
        
        NdrConformantStringMarshall( (PMIDL_STUB_MESSAGE)& _StubMsg,
                                     (unsigned char __RPC_FAR *)regname,
                                     (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[74] );
        
        NdrSendReceive( (PMIDL_STUB_MESSAGE) &_StubMsg, (unsigned char __RPC_FAR *) _StubMsg.Buffer );
        
        }
    RpcFinally
        {
        NdrFreeBuffer( (PMIDL_STUB_MESSAGE) &_StubMsg );
        
        }
    RpcEndFinally
    
}


void RPC_YKConfirm( 
    /* [in] */ long varID,
    /* [in] */ float tovalue,
    /* [string][in] */ char __RPC_FAR *regname)
{

    RPC_BINDING_HANDLE _Handle	=	0;
    
    RPC_MESSAGE _RpcMessage;
    
    MIDL_STUB_MESSAGE _StubMsg;
    
    if(!regname)
        {
        RpcRaiseException(RPC_X_NULL_REF_POINTER);
        }
    RpcTryFinally
        {
        NdrClientInitializeNew(
                          ( PRPC_MESSAGE  )&_RpcMessage,
                          ( PMIDL_STUB_MESSAGE  )&_StubMsg,
                          ( PMIDL_STUB_DESC  )&pansi_StubDesc,
                          29);
        
        
        _Handle = hPansi;
        
        
        _StubMsg.BufferLength = 4U + 4U + 12U;
        NdrConformantStringBufferSize( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                       (unsigned char __RPC_FAR *)regname,
                                       (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[74] );
        
        NdrGetBuffer( (PMIDL_STUB_MESSAGE) &_StubMsg, _StubMsg.BufferLength, _Handle );
        
        *(( long __RPC_FAR * )_StubMsg.Buffer)++ = varID;
        
        *(( float __RPC_FAR * )_StubMsg.Buffer)++ = tovalue;
        
        NdrConformantStringMarshall( (PMIDL_STUB_MESSAGE)& _StubMsg,
                                     (unsigned char __RPC_FAR *)regname,
                                     (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[74] );
        
        NdrSendReceive( (PMIDL_STUB_MESSAGE) &_StubMsg, (unsigned char __RPC_FAR *) _StubMsg.Buffer );
        
        }
    RpcFinally
        {
        NdrFreeBuffer( (PMIDL_STUB_MESSAGE) &_StubMsg );
        
        }
    RpcEndFinally
    
}


void RPC_YKExecute( 
    /* [in] */ long varID,
    /* [in] */ float tovalue,
    /* [string][in] */ char __RPC_FAR *regname)
{

    RPC_BINDING_HANDLE _Handle	=	0;
    
    RPC_MESSAGE _RpcMessage;
    
    MIDL_STUB_MESSAGE _StubMsg;
    
    if(!regname)
        {
        RpcRaiseException(RPC_X_NULL_REF_POINTER);
        }
    RpcTryFinally
        {
        NdrClientInitializeNew(
                          ( PRPC_MESSAGE  )&_RpcMessage,
                          ( PMIDL_STUB_MESSAGE  )&_StubMsg,
                          ( PMIDL_STUB_DESC  )&pansi_StubDesc,
                          30);
        
        
        _Handle = hPansi;
        
        
        _StubMsg.BufferLength = 4U + 4U + 12U;
        NdrConformantStringBufferSize( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                       (unsigned char __RPC_FAR *)regname,
                                       (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[74] );
        
        NdrGetBuffer( (PMIDL_STUB_MESSAGE) &_StubMsg, _StubMsg.BufferLength, _Handle );
        
        *(( long __RPC_FAR * )_StubMsg.Buffer)++ = varID;
        
        *(( float __RPC_FAR * )_StubMsg.Buffer)++ = tovalue;
        
        NdrConformantStringMarshall( (PMIDL_STUB_MESSAGE)& _StubMsg,
                                     (unsigned char __RPC_FAR *)regname,
                                     (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[74] );
        
        NdrSendReceive( (PMIDL_STUB_MESSAGE) &_StubMsg, (unsigned char __RPC_FAR *) _StubMsg.Buffer );
        
        }
    RpcFinally
        {
        NdrFreeBuffer( (PMIDL_STUB_MESSAGE) &_StubMsg );
        
        }
    RpcEndFinally
    
}


void RPC_RTUReset( 
    /* [in] */ long varID,
    /* [string][in] */ char __RPC_FAR *regname)
{

    RPC_BINDING_HANDLE _Handle	=	0;
    
    RPC_MESSAGE _RpcMessage;
    
    MIDL_STUB_MESSAGE _StubMsg;
    
    if(!regname)
        {
        RpcRaiseException(RPC_X_NULL_REF_POINTER);
        }
    RpcTryFinally
        {
        NdrClientInitializeNew(
                          ( PRPC_MESSAGE  )&_RpcMessage,
                          ( PMIDL_STUB_MESSAGE  )&_StubMsg,
                          ( PMIDL_STUB_DESC  )&pansi_StubDesc,
                          31);
        
        
        _Handle = hPansi;
        
        
        _StubMsg.BufferLength = 4U + 12U;
        NdrConformantStringBufferSize( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                       (unsigned char __RPC_FAR *)regname,
                                       (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[74] );
        
        NdrGetBuffer( (PMIDL_STUB_MESSAGE) &_StubMsg, _StubMsg.BufferLength, _Handle );
        
        *(( long __RPC_FAR * )_StubMsg.Buffer)++ = varID;
        
        NdrConformantStringMarshall( (PMIDL_STUB_MESSAGE)& _StubMsg,
                                     (unsigned char __RPC_FAR *)regname,
                                     (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[74] );
        
        NdrSendReceive( (PMIDL_STUB_MESSAGE) &_StubMsg, (unsigned char __RPC_FAR *) _StubMsg.Buffer );
        
        }
    RpcFinally
        {
        NdrFreeBuffer( (PMIDL_STUB_MESSAGE) &_StubMsg );
        
        }
    RpcEndFinally
    
}


void RPC_SetSide( 
    /* [in] */ long varID,
    /* [in] */ long dwP,
    /* [in] */ long dwQ,
    /* [in] */ long dwI,
    /* [string][in] */ char __RPC_FAR *regname)
{

    RPC_BINDING_HANDLE _Handle	=	0;
    
    RPC_MESSAGE _RpcMessage;
    
    MIDL_STUB_MESSAGE _StubMsg;
    
    if(!regname)
        {
        RpcRaiseException(RPC_X_NULL_REF_POINTER);
        }
    RpcTryFinally
        {
        NdrClientInitializeNew(
                          ( PRPC_MESSAGE  )&_RpcMessage,
                          ( PMIDL_STUB_MESSAGE  )&_StubMsg,
                          ( PMIDL_STUB_DESC  )&pansi_StubDesc,
                          32);
        
        
        _Handle = hPansi;
        
        
        _StubMsg.BufferLength = 4U + 4U + 4U + 4U + 12U;
        NdrConformantStringBufferSize( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                       (unsigned char __RPC_FAR *)regname,
                                       (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[74] );
        
        NdrGetBuffer( (PMIDL_STUB_MESSAGE) &_StubMsg, _StubMsg.BufferLength, _Handle );
        
        *(( long __RPC_FAR * )_StubMsg.Buffer)++ = varID;
        
        *(( long __RPC_FAR * )_StubMsg.Buffer)++ = dwP;
        
        *(( long __RPC_FAR * )_StubMsg.Buffer)++ = dwQ;
        
        *(( long __RPC_FAR * )_StubMsg.Buffer)++ = dwI;
        
        NdrConformantStringMarshall( (PMIDL_STUB_MESSAGE)& _StubMsg,
                                     (unsigned char __RPC_FAR *)regname,
                                     (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[74] );
        
        NdrSendReceive( (PMIDL_STUB_MESSAGE) &_StubMsg, (unsigned char __RPC_FAR *) _StubMsg.Buffer );
        
        }
    RpcFinally
        {
        NdrFreeBuffer( (PMIDL_STUB_MESSAGE) &_StubMsg );
        
        }
    RpcEndFinally
    
}


void RPC_ResetSide( 
    /* [in] */ long varID,
    /* [in] */ long dwP,
    /* [in] */ long dwQ,
    /* [in] */ long dwI,
    /* [string][in] */ char __RPC_FAR *regname)
{

    RPC_BINDING_HANDLE _Handle	=	0;
    
    RPC_MESSAGE _RpcMessage;
    
    MIDL_STUB_MESSAGE _StubMsg;
    
    if(!regname)
        {
        RpcRaiseException(RPC_X_NULL_REF_POINTER);
        }
    RpcTryFinally
        {
        NdrClientInitializeNew(
                          ( PRPC_MESSAGE  )&_RpcMessage,
                          ( PMIDL_STUB_MESSAGE  )&_StubMsg,
                          ( PMIDL_STUB_DESC  )&pansi_StubDesc,
                          33);
        
        
        _Handle = hPansi;
        
        
        _StubMsg.BufferLength = 4U + 4U + 4U + 4U + 12U;
        NdrConformantStringBufferSize( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                       (unsigned char __RPC_FAR *)regname,
                                       (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[74] );
        
        NdrGetBuffer( (PMIDL_STUB_MESSAGE) &_StubMsg, _StubMsg.BufferLength, _Handle );
        
        *(( long __RPC_FAR * )_StubMsg.Buffer)++ = varID;
        
        *(( long __RPC_FAR * )_StubMsg.Buffer)++ = dwP;
        
        *(( long __RPC_FAR * )_StubMsg.Buffer)++ = dwQ;
        
        *(( long __RPC_FAR * )_StubMsg.Buffer)++ = dwI;
        
        NdrConformantStringMarshall( (PMIDL_STUB_MESSAGE)& _StubMsg,
                                     (unsigned char __RPC_FAR *)regname,
                                     (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[74] );
        
        NdrSendReceive( (PMIDL_STUB_MESSAGE) &_StubMsg, (unsigned char __RPC_FAR *) _StubMsg.Buffer );
        
        }
    RpcFinally
        {
        NdrFreeBuffer( (PMIDL_STUB_MESSAGE) &_StubMsg );
        
        }
    RpcEndFinally
    
}


int RPC_GetEventNum( 
    /* [in] */ PS_DATE __RPC_FAR *pDate)
{

    RPC_BINDING_HANDLE _Handle	=	0;
    
    int _RetVal;
    
    RPC_MESSAGE _RpcMessage;
    
    MIDL_STUB_MESSAGE _StubMsg;
    
    if(!pDate)
        {
        RpcRaiseException(RPC_X_NULL_REF_POINTER);
        }
    RpcTryFinally
        {
        NdrClientInitializeNew(
                          ( PRPC_MESSAGE  )&_RpcMessage,
                          ( PMIDL_STUB_MESSAGE  )&_StubMsg,
                          ( PMIDL_STUB_DESC  )&pansi_StubDesc,
                          34);
        
        
        _Handle = hPansi;
        
        
        _StubMsg.BufferLength = 0U;
        NdrSimpleStructBufferSize( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                   (unsigned char __RPC_FAR *)pDate,
                                   (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[8] );
        
        NdrGetBuffer( (PMIDL_STUB_MESSAGE) &_StubMsg, _StubMsg.BufferLength, _Handle );
        
        NdrSimpleStructMarshall( (PMIDL_STUB_MESSAGE)& _StubMsg,
                                 (unsigned char __RPC_FAR *)pDate,
                                 (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[8] );
        
        NdrSendReceive( (PMIDL_STUB_MESSAGE) &_StubMsg, (unsigned char __RPC_FAR *) _StubMsg.Buffer );
        
        if ( (_RpcMessage.DataRepresentation & 0X0000FFFFUL) != NDR_LOCAL_DATA_REPRESENTATION )
            NdrConvert( (PMIDL_STUB_MESSAGE) &_StubMsg, (PFORMAT_STRING) &__MIDL_ProcFormatString.Format[222] );
        
        _RetVal = *(( int __RPC_FAR * )_StubMsg.Buffer)++;
        
        }
    RpcFinally
        {
        NdrFreeBuffer( (PMIDL_STUB_MESSAGE) &_StubMsg );
        
        }
    RpcEndFinally
    
    return _RetVal;
}


int RPC_LoadEventBase( 
    /* [size_is][out] */ char __RPC_FAR pEvents[  ],
    /* [in] */ int size,
    /* [in] */ PS_DATE __RPC_FAR *pDate)
{

    RPC_BINDING_HANDLE _Handle	=	0;
    
    int _RetVal;
    
    RPC_MESSAGE _RpcMessage;
    
    MIDL_STUB_MESSAGE _StubMsg;
    
    if(!pDate)
        {
        RpcRaiseException(RPC_X_NULL_REF_POINTER);
        }
    RpcTryFinally
        {
        NdrClientInitializeNew(
                          ( PRPC_MESSAGE  )&_RpcMessage,
                          ( PMIDL_STUB_MESSAGE  )&_StubMsg,
                          ( PMIDL_STUB_DESC  )&pansi_StubDesc,
                          35);
        
        
        _Handle = hPansi;
        
        
        _StubMsg.BufferLength = 4U + 4U;
        NdrSimpleStructBufferSize( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                   (unsigned char __RPC_FAR *)pDate,
                                   (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[8] );
        
        NdrGetBuffer( (PMIDL_STUB_MESSAGE) &_StubMsg, _StubMsg.BufferLength, _Handle );
        
        *(( int __RPC_FAR * )_StubMsg.Buffer)++ = size;
        
        NdrSimpleStructMarshall( (PMIDL_STUB_MESSAGE)& _StubMsg,
                                 (unsigned char __RPC_FAR *)pDate,
                                 (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[8] );
        
        NdrSendReceive( (PMIDL_STUB_MESSAGE) &_StubMsg, (unsigned char __RPC_FAR *) _StubMsg.Buffer );
        
        if ( (_RpcMessage.DataRepresentation & 0X0000FFFFUL) != NDR_LOCAL_DATA_REPRESENTATION )
            NdrConvert( (PMIDL_STUB_MESSAGE) &_StubMsg, (PFORMAT_STRING) &__MIDL_ProcFormatString.Format[228] );
        
        NdrConformantArrayUnmarshall( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                      (unsigned char __RPC_FAR * __RPC_FAR *)&pEvents,
                                      (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[62],
                                      (unsigned char)0 );
        
        _StubMsg.Buffer = (unsigned char __RPC_FAR *)(((long)_StubMsg.Buffer + 3) & ~ 0x3);
        _RetVal = *(( int __RPC_FAR * )_StubMsg.Buffer)++;
        
        }
    RpcFinally
        {
        NdrFreeBuffer( (PMIDL_STUB_MESSAGE) &_StubMsg );
        
        }
    RpcEndFinally
    
    return _RetVal;
}


int RPC_GetVarEventNum( 
    /* [in] */ long vid,
    /* [in] */ PS_DATE __RPC_FAR *pDate)
{

    RPC_BINDING_HANDLE _Handle	=	0;
    
    int _RetVal;
    
    RPC_MESSAGE _RpcMessage;
    
    MIDL_STUB_MESSAGE _StubMsg;
    
    if(!pDate)
        {
        RpcRaiseException(RPC_X_NULL_REF_POINTER);
        }
    RpcTryFinally
        {
        NdrClientInitializeNew(
                          ( PRPC_MESSAGE  )&_RpcMessage,
                          ( PMIDL_STUB_MESSAGE  )&_StubMsg,
                          ( PMIDL_STUB_DESC  )&pansi_StubDesc,
                          36);
        
        
        _Handle = hPansi;
        
        
        _StubMsg.BufferLength = 4U + 4U;
        NdrSimpleStructBufferSize( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                   (unsigned char __RPC_FAR *)pDate,
                                   (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[8] );
        
        NdrGetBuffer( (PMIDL_STUB_MESSAGE) &_StubMsg, _StubMsg.BufferLength, _Handle );
        
        *(( long __RPC_FAR * )_StubMsg.Buffer)++ = vid;
        
        NdrSimpleStructMarshall( (PMIDL_STUB_MESSAGE)& _StubMsg,
                                 (unsigned char __RPC_FAR *)pDate,
                                 (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[8] );
        
        NdrSendReceive( (PMIDL_STUB_MESSAGE) &_StubMsg, (unsigned char __RPC_FAR *) _StubMsg.Buffer );
        
        if ( (_RpcMessage.DataRepresentation & 0X0000FFFFUL) != NDR_LOCAL_DATA_REPRESENTATION )
            NdrConvert( (PMIDL_STUB_MESSAGE) &_StubMsg, (PFORMAT_STRING) &__MIDL_ProcFormatString.Format[240] );
        
        _RetVal = *(( int __RPC_FAR * )_StubMsg.Buffer)++;
        
        }
    RpcFinally
        {
        NdrFreeBuffer( (PMIDL_STUB_MESSAGE) &_StubMsg );
        
        }
    RpcEndFinally
    
    return _RetVal;
}


int RPC_LoadVarEventBase( 
    /* [in] */ long vid,
    /* [size_is][out] */ char __RPC_FAR pEvents[  ],
    /* [in] */ int size,
    /* [in] */ PS_DATE __RPC_FAR *pDate)
{

    RPC_BINDING_HANDLE _Handle	=	0;
    
    int _RetVal;
    
    RPC_MESSAGE _RpcMessage;
    
    MIDL_STUB_MESSAGE _StubMsg;
    
    if(!pDate)
        {
        RpcRaiseException(RPC_X_NULL_REF_POINTER);
        }
    RpcTryFinally
        {
        NdrClientInitializeNew(
                          ( PRPC_MESSAGE  )&_RpcMessage,
                          ( PMIDL_STUB_MESSAGE  )&_StubMsg,
                          ( PMIDL_STUB_DESC  )&pansi_StubDesc,
                          37);
        
        
        _Handle = hPansi;
        
        
        _StubMsg.BufferLength = 4U + 4U + 0U;
        NdrSimpleStructBufferSize( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                   (unsigned char __RPC_FAR *)pDate,
                                   (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[8] );
        
        NdrGetBuffer( (PMIDL_STUB_MESSAGE) &_StubMsg, _StubMsg.BufferLength, _Handle );
        
        *(( long __RPC_FAR * )_StubMsg.Buffer)++ = vid;
        
        *(( int __RPC_FAR * )_StubMsg.Buffer)++ = size;
        
        NdrSimpleStructMarshall( (PMIDL_STUB_MESSAGE)& _StubMsg,
                                 (unsigned char __RPC_FAR *)pDate,
                                 (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[8] );
        
        NdrSendReceive( (PMIDL_STUB_MESSAGE) &_StubMsg, (unsigned char __RPC_FAR *) _StubMsg.Buffer );
        
        if ( (_RpcMessage.DataRepresentation & 0X0000FFFFUL) != NDR_LOCAL_DATA_REPRESENTATION )
            NdrConvert( (PMIDL_STUB_MESSAGE) &_StubMsg, (PFORMAT_STRING) &__MIDL_ProcFormatString.Format[248] );
        
        NdrConformantArrayUnmarshall( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                      (unsigned char __RPC_FAR * __RPC_FAR *)&pEvents,
                                      (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[382],
                                      (unsigned char)0 );
        
        _StubMsg.Buffer = (unsigned char __RPC_FAR *)(((long)_StubMsg.Buffer + 3) & ~ 0x3);
        _RetVal = *(( int __RPC_FAR * )_StubMsg.Buffer)++;
        
        }
    RpcFinally
        {
        NdrFreeBuffer( (PMIDL_STUB_MESSAGE) &_StubMsg );
        
        }
    RpcEndFinally
    
    return _RetVal;
}


float RPC_EvaluateExpression( 
    /* [size_is][in] */ char __RPC_FAR pExpr[  ],
    /* [out] */ int __RPC_FAR *errcode)
{

    RPC_BINDING_HANDLE _Handle	=	0;
    
    float _RetVal;
    
    RPC_MESSAGE _RpcMessage;
    
    MIDL_STUB_MESSAGE _StubMsg;
    
    if(!errcode)
        {
        RpcRaiseException(RPC_X_NULL_REF_POINTER);
        }
    RpcTryFinally
        {
        NdrClientInitializeNew(
                          ( PRPC_MESSAGE  )&_RpcMessage,
                          ( PMIDL_STUB_MESSAGE  )&_StubMsg,
                          ( PMIDL_STUB_DESC  )&pansi_StubDesc,
                          38);
        
        
        _Handle = hPansi;
        
        
        _StubMsg.BufferLength = 4U;
        _StubMsg.MaxCount = MAXEXPRESSION + 2;
        
        NdrConformantArrayBufferSize( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                      (unsigned char __RPC_FAR *)pExpr,
                                      (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[392] );
        
        NdrGetBuffer( (PMIDL_STUB_MESSAGE) &_StubMsg, _StubMsg.BufferLength, _Handle );
        
        _StubMsg.MaxCount = MAXEXPRESSION + 2;
        
        NdrConformantArrayMarshall( (PMIDL_STUB_MESSAGE)& _StubMsg,
                                    (unsigned char __RPC_FAR *)pExpr,
                                    (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[392] );
        
        NdrSendReceive( (PMIDL_STUB_MESSAGE) &_StubMsg, (unsigned char __RPC_FAR *) _StubMsg.Buffer );
        
        if ( (_RpcMessage.DataRepresentation & 0X0000FFFFUL) != NDR_LOCAL_DATA_REPRESENTATION )
            NdrConvert( (PMIDL_STUB_MESSAGE) &_StubMsg, (PFORMAT_STRING) &__MIDL_ProcFormatString.Format[262] );
        
        *errcode = *(( int __RPC_FAR * )_StubMsg.Buffer)++;
        
        _RetVal = *(( float __RPC_FAR * )_StubMsg.Buffer)++;
        
        }
    RpcFinally
        {
        NdrFreeBuffer( (PMIDL_STUB_MESSAGE) &_StubMsg );
        
        }
    RpcEndFinally
    
    return _RetVal;
}


int RPC_GetRecordNum( 
    /* [in] */ long varID,
    /* [string][in] */ char __RPC_FAR *datetime0,
    /* [string][in] */ char __RPC_FAR *datetime1)
{

    RPC_BINDING_HANDLE _Handle	=	0;
    
    int _RetVal;
    
    RPC_MESSAGE _RpcMessage;
    
    MIDL_STUB_MESSAGE _StubMsg;
    
    if(!datetime0)
        {
        RpcRaiseException(RPC_X_NULL_REF_POINTER);
        }
    if(!datetime1)
        {
        RpcRaiseException(RPC_X_NULL_REF_POINTER);
        }
    RpcTryFinally
        {
        NdrClientInitializeNew(
                          ( PRPC_MESSAGE  )&_RpcMessage,
                          ( PMIDL_STUB_MESSAGE  )&_StubMsg,
                          ( PMIDL_STUB_DESC  )&pansi_StubDesc,
                          39);
        
        
        _Handle = hPansi;
        
        
        _StubMsg.BufferLength = 4U + 12U + 13U;
        NdrConformantStringBufferSize( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                       (unsigned char __RPC_FAR *)datetime0,
                                       (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[74] );
        
        NdrConformantStringBufferSize( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                       (unsigned char __RPC_FAR *)datetime1,
                                       (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[74] );
        
        NdrGetBuffer( (PMIDL_STUB_MESSAGE) &_StubMsg, _StubMsg.BufferLength, _Handle );
        
        *(( long __RPC_FAR * )_StubMsg.Buffer)++ = varID;
        
        NdrConformantStringMarshall( (PMIDL_STUB_MESSAGE)& _StubMsg,
                                     (unsigned char __RPC_FAR *)datetime0,
                                     (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[74] );
        
        NdrConformantStringMarshall( (PMIDL_STUB_MESSAGE)& _StubMsg,
                                     (unsigned char __RPC_FAR *)datetime1,
                                     (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[74] );
        
        NdrSendReceive( (PMIDL_STUB_MESSAGE) &_StubMsg, (unsigned char __RPC_FAR *) _StubMsg.Buffer );
        
        if ( (_RpcMessage.DataRepresentation & 0X0000FFFFUL) != NDR_LOCAL_DATA_REPRESENTATION )
            NdrConvert( (PMIDL_STUB_MESSAGE) &_StubMsg, (PFORMAT_STRING) &__MIDL_ProcFormatString.Format[272] );
        
        _RetVal = *(( int __RPC_FAR * )_StubMsg.Buffer)++;
        
        }
    RpcFinally
        {
        NdrFreeBuffer( (PMIDL_STUB_MESSAGE) &_StubMsg );
        
        }
    RpcEndFinally
    
    return _RetVal;
}


int RPC_LoadRecordData( 
    /* [in] */ long varID,
    /* [string][in] */ char __RPC_FAR *datetime0,
    /* [string][in] */ char __RPC_FAR *datetime1,
    /* [size_is][out] */ PS_BASEDATA __RPC_FAR pBasedata[  ],
    /* [in] */ int n)
{

    RPC_BINDING_HANDLE _Handle	=	0;
    
    int _RetVal;
    
    RPC_MESSAGE _RpcMessage;
    
    MIDL_STUB_MESSAGE _StubMsg;
    
    if(!datetime0)
        {
        RpcRaiseException(RPC_X_NULL_REF_POINTER);
        }
    if(!datetime1)
        {
        RpcRaiseException(RPC_X_NULL_REF_POINTER);
        }
    RpcTryFinally
        {
        NdrClientInitializeNew(
                          ( PRPC_MESSAGE  )&_RpcMessage,
                          ( PMIDL_STUB_MESSAGE  )&_StubMsg,
                          ( PMIDL_STUB_DESC  )&pansi_StubDesc,
                          40);
        
        
        _Handle = hPansi;
        
        
        _StubMsg.BufferLength = 4U + 12U + 13U + 11U;
        NdrConformantStringBufferSize( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                       (unsigned char __RPC_FAR *)datetime0,
                                       (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[74] );
        
        NdrConformantStringBufferSize( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                       (unsigned char __RPC_FAR *)datetime1,
                                       (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[74] );
        
        NdrGetBuffer( (PMIDL_STUB_MESSAGE) &_StubMsg, _StubMsg.BufferLength, _Handle );
        
        *(( long __RPC_FAR * )_StubMsg.Buffer)++ = varID;
        
        NdrConformantStringMarshall( (PMIDL_STUB_MESSAGE)& _StubMsg,
                                     (unsigned char __RPC_FAR *)datetime0,
                                     (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[74] );
        
        NdrConformantStringMarshall( (PMIDL_STUB_MESSAGE)& _StubMsg,
                                     (unsigned char __RPC_FAR *)datetime1,
                                     (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[74] );
        
        _StubMsg.Buffer = (unsigned char __RPC_FAR *)(((long)_StubMsg.Buffer + 3) & ~ 0x3);
        *(( int __RPC_FAR * )_StubMsg.Buffer)++ = n;
        
        NdrSendReceive( (PMIDL_STUB_MESSAGE) &_StubMsg, (unsigned char __RPC_FAR *) _StubMsg.Buffer );
        
        if ( (_RpcMessage.DataRepresentation & 0X0000FFFFUL) != NDR_LOCAL_DATA_REPRESENTATION )
            NdrConvert( (PMIDL_STUB_MESSAGE) &_StubMsg, (PFORMAT_STRING) &__MIDL_ProcFormatString.Format[284] );
        
        NdrConformantArrayUnmarshall( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                      (unsigned char __RPC_FAR * __RPC_FAR *)&pBasedata,
                                      (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[420],
                                      (unsigned char)0 );
        
        _StubMsg.Buffer = (unsigned char __RPC_FAR *)(((long)_StubMsg.Buffer + 3) & ~ 0x3);
        _RetVal = *(( int __RPC_FAR * )_StubMsg.Buffer)++;
        
        }
    RpcFinally
        {
        NdrFreeBuffer( (PMIDL_STUB_MESSAGE) &_StubMsg );
        
        }
    RpcEndFinally
    
    return _RetVal;
}


int RPC_GetPlanRecNum( 
    /* [in] */ long varID,
    /* [string][in] */ char __RPC_FAR *datetime0,
    /* [string][in] */ char __RPC_FAR *datetime1)
{

    RPC_BINDING_HANDLE _Handle	=	0;
    
    int _RetVal;
    
    RPC_MESSAGE _RpcMessage;
    
    MIDL_STUB_MESSAGE _StubMsg;
    
    if(!datetime0)
        {
        RpcRaiseException(RPC_X_NULL_REF_POINTER);
        }
    if(!datetime1)
        {
        RpcRaiseException(RPC_X_NULL_REF_POINTER);
        }
    RpcTryFinally
        {
        NdrClientInitializeNew(
                          ( PRPC_MESSAGE  )&_RpcMessage,
                          ( PMIDL_STUB_MESSAGE  )&_StubMsg,
                          ( PMIDL_STUB_DESC  )&pansi_StubDesc,
                          41);
        
        
        _Handle = hPansi;
        
        
        _StubMsg.BufferLength = 4U + 12U + 13U;
        NdrConformantStringBufferSize( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                       (unsigned char __RPC_FAR *)datetime0,
                                       (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[74] );
        
        NdrConformantStringBufferSize( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                       (unsigned char __RPC_FAR *)datetime1,
                                       (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[74] );
        
        NdrGetBuffer( (PMIDL_STUB_MESSAGE) &_StubMsg, _StubMsg.BufferLength, _Handle );
        
        *(( long __RPC_FAR * )_StubMsg.Buffer)++ = varID;
        
        NdrConformantStringMarshall( (PMIDL_STUB_MESSAGE)& _StubMsg,
                                     (unsigned char __RPC_FAR *)datetime0,
                                     (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[74] );
        
        NdrConformantStringMarshall( (PMIDL_STUB_MESSAGE)& _StubMsg,
                                     (unsigned char __RPC_FAR *)datetime1,
                                     (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[74] );
        
        NdrSendReceive( (PMIDL_STUB_MESSAGE) &_StubMsg, (unsigned char __RPC_FAR *) _StubMsg.Buffer );
        
        if ( (_RpcMessage.DataRepresentation & 0X0000FFFFUL) != NDR_LOCAL_DATA_REPRESENTATION )
            NdrConvert( (PMIDL_STUB_MESSAGE) &_StubMsg, (PFORMAT_STRING) &__MIDL_ProcFormatString.Format[272] );
        
        _RetVal = *(( int __RPC_FAR * )_StubMsg.Buffer)++;
        
        }
    RpcFinally
        {
        NdrFreeBuffer( (PMIDL_STUB_MESSAGE) &_StubMsg );
        
        }
    RpcEndFinally
    
    return _RetVal;
}


int RPC_LoadPlanRecData( 
    /* [in] */ long varID,
    /* [string][in] */ char __RPC_FAR *datetime0,
    /* [string][in] */ char __RPC_FAR *datetime1,
    /* [size_is][out] */ PS_BASEDATA __RPC_FAR pBasedata[  ],
    /* [in] */ int n)
{

    RPC_BINDING_HANDLE _Handle	=	0;
    
    int _RetVal;
    
    RPC_MESSAGE _RpcMessage;
    
    MIDL_STUB_MESSAGE _StubMsg;
    
    if(!datetime0)
        {
        RpcRaiseException(RPC_X_NULL_REF_POINTER);
        }
    if(!datetime1)
        {
        RpcRaiseException(RPC_X_NULL_REF_POINTER);
        }
    RpcTryFinally
        {
        NdrClientInitializeNew(
                          ( PRPC_MESSAGE  )&_RpcMessage,
                          ( PMIDL_STUB_MESSAGE  )&_StubMsg,
                          ( PMIDL_STUB_DESC  )&pansi_StubDesc,
                          42);
        
        
        _Handle = hPansi;
        
        
        _StubMsg.BufferLength = 4U + 12U + 13U + 11U;
        NdrConformantStringBufferSize( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                       (unsigned char __RPC_FAR *)datetime0,
                                       (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[74] );
        
        NdrConformantStringBufferSize( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                       (unsigned char __RPC_FAR *)datetime1,
                                       (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[74] );
        
        NdrGetBuffer( (PMIDL_STUB_MESSAGE) &_StubMsg, _StubMsg.BufferLength, _Handle );
        
        *(( long __RPC_FAR * )_StubMsg.Buffer)++ = varID;
        
        NdrConformantStringMarshall( (PMIDL_STUB_MESSAGE)& _StubMsg,
                                     (unsigned char __RPC_FAR *)datetime0,
                                     (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[74] );
        
        NdrConformantStringMarshall( (PMIDL_STUB_MESSAGE)& _StubMsg,
                                     (unsigned char __RPC_FAR *)datetime1,
                                     (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[74] );
        
        _StubMsg.Buffer = (unsigned char __RPC_FAR *)(((long)_StubMsg.Buffer + 3) & ~ 0x3);
        *(( int __RPC_FAR * )_StubMsg.Buffer)++ = n;
        
        NdrSendReceive( (PMIDL_STUB_MESSAGE) &_StubMsg, (unsigned char __RPC_FAR *) _StubMsg.Buffer );
        
        if ( (_RpcMessage.DataRepresentation & 0X0000FFFFUL) != NDR_LOCAL_DATA_REPRESENTATION )
            NdrConvert( (PMIDL_STUB_MESSAGE) &_StubMsg, (PFORMAT_STRING) &__MIDL_ProcFormatString.Format[284] );
        
        NdrConformantArrayUnmarshall( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                      (unsigned char __RPC_FAR * __RPC_FAR *)&pBasedata,
                                      (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[420],
                                      (unsigned char)0 );
        
        _StubMsg.Buffer = (unsigned char __RPC_FAR *)(((long)_StubMsg.Buffer + 3) & ~ 0x3);
        _RetVal = *(( int __RPC_FAR * )_StubMsg.Buffer)++;
        
        }
    RpcFinally
        {
        NdrFreeBuffer( (PMIDL_STUB_MESSAGE) &_StubMsg );
        
        }
    RpcEndFinally
    
    return _RetVal;
}


int RPC_LockPage( 
    /* [string][in] */ char __RPC_FAR *pagefile,
    /* [string][in] */ char __RPC_FAR *regname)
{

    RPC_BINDING_HANDLE _Handle	=	0;
    
    int _RetVal;
    
    RPC_MESSAGE _RpcMessage;
    
    MIDL_STUB_MESSAGE _StubMsg;
    
    if(!pagefile)
        {
        RpcRaiseException(RPC_X_NULL_REF_POINTER);
        }
    if(!regname)
        {
        RpcRaiseException(RPC_X_NULL_REF_POINTER);
        }
    RpcTryFinally
        {
        NdrClientInitializeNew(
                          ( PRPC_MESSAGE  )&_RpcMessage,
                          ( PMIDL_STUB_MESSAGE  )&_StubMsg,
                          ( PMIDL_STUB_DESC  )&pansi_StubDesc,
                          43);
        
        
        _Handle = hPansi;
        
        
        _StubMsg.BufferLength = 12U + 13U;
        NdrConformantStringBufferSize( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                       (unsigned char __RPC_FAR *)pagefile,
                                       (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[74] );
        
        NdrConformantStringBufferSize( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                       (unsigned char __RPC_FAR *)regname,
                                       (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[74] );
        
        NdrGetBuffer( (PMIDL_STUB_MESSAGE) &_StubMsg, _StubMsg.BufferLength, _Handle );
        
        NdrConformantStringMarshall( (PMIDL_STUB_MESSAGE)& _StubMsg,
                                     (unsigned char __RPC_FAR *)pagefile,
                                     (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[74] );
        
        NdrConformantStringMarshall( (PMIDL_STUB_MESSAGE)& _StubMsg,
                                     (unsigned char __RPC_FAR *)regname,
                                     (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[74] );
        
        NdrSendReceive( (PMIDL_STUB_MESSAGE) &_StubMsg, (unsigned char __RPC_FAR *) _StubMsg.Buffer );
        
        if ( (_RpcMessage.DataRepresentation & 0X0000FFFFUL) != NDR_LOCAL_DATA_REPRESENTATION )
            NdrConvert( (PMIDL_STUB_MESSAGE) &_StubMsg, (PFORMAT_STRING) &__MIDL_ProcFormatString.Format[302] );
        
        _RetVal = *(( int __RPC_FAR * )_StubMsg.Buffer)++;
        
        }
    RpcFinally
        {
        NdrFreeBuffer( (PMIDL_STUB_MESSAGE) &_StubMsg );
        
        }
    RpcEndFinally
    
    return _RetVal;
}


int RPC_UnlockPage( 
    /* [string][in] */ char __RPC_FAR *pagefile,
    /* [string][in] */ char __RPC_FAR *regname)
{

    RPC_BINDING_HANDLE _Handle	=	0;
    
    int _RetVal;
    
    RPC_MESSAGE _RpcMessage;
    
    MIDL_STUB_MESSAGE _StubMsg;
    
    if(!pagefile)
        {
        RpcRaiseException(RPC_X_NULL_REF_POINTER);
        }
    if(!regname)
        {
        RpcRaiseException(RPC_X_NULL_REF_POINTER);
        }
    RpcTryFinally
        {
        NdrClientInitializeNew(
                          ( PRPC_MESSAGE  )&_RpcMessage,
                          ( PMIDL_STUB_MESSAGE  )&_StubMsg,
                          ( PMIDL_STUB_DESC  )&pansi_StubDesc,
                          44);
        
        
        _Handle = hPansi;
        
        
        _StubMsg.BufferLength = 12U + 13U;
        NdrConformantStringBufferSize( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                       (unsigned char __RPC_FAR *)pagefile,
                                       (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[74] );
        
        NdrConformantStringBufferSize( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                       (unsigned char __RPC_FAR *)regname,
                                       (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[74] );
        
        NdrGetBuffer( (PMIDL_STUB_MESSAGE) &_StubMsg, _StubMsg.BufferLength, _Handle );
        
        NdrConformantStringMarshall( (PMIDL_STUB_MESSAGE)& _StubMsg,
                                     (unsigned char __RPC_FAR *)pagefile,
                                     (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[74] );
        
        NdrConformantStringMarshall( (PMIDL_STUB_MESSAGE)& _StubMsg,
                                     (unsigned char __RPC_FAR *)regname,
                                     (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[74] );
        
        NdrSendReceive( (PMIDL_STUB_MESSAGE) &_StubMsg, (unsigned char __RPC_FAR *) _StubMsg.Buffer );
        
        if ( (_RpcMessage.DataRepresentation & 0X0000FFFFUL) != NDR_LOCAL_DATA_REPRESENTATION )
            NdrConvert( (PMIDL_STUB_MESSAGE) &_StubMsg, (PFORMAT_STRING) &__MIDL_ProcFormatString.Format[302] );
        
        _RetVal = *(( int __RPC_FAR * )_StubMsg.Buffer)++;
        
        }
    RpcFinally
        {
        NdrFreeBuffer( (PMIDL_STUB_MESSAGE) &_StubMsg );
        
        }
    RpcEndFinally
    
    return _RetVal;
}


int RPC_LockVDT( 
    /* [string][in] */ char __RPC_FAR *regname)
{

    RPC_BINDING_HANDLE _Handle	=	0;
    
    int _RetVal;
    
    RPC_MESSAGE _RpcMessage;
    
    MIDL_STUB_MESSAGE _StubMsg;
    
    if(!regname)
        {
        RpcRaiseException(RPC_X_NULL_REF_POINTER);
        }
    RpcTryFinally
        {
        NdrClientInitializeNew(
                          ( PRPC_MESSAGE  )&_RpcMessage,
                          ( PMIDL_STUB_MESSAGE  )&_StubMsg,
                          ( PMIDL_STUB_DESC  )&pansi_StubDesc,
                          45);
        
        
        _Handle = hPansi;
        
        
        _StubMsg.BufferLength = 12U;
        NdrConformantStringBufferSize( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                       (unsigned char __RPC_FAR *)regname,
                                       (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[74] );
        
        NdrGetBuffer( (PMIDL_STUB_MESSAGE) &_StubMsg, _StubMsg.BufferLength, _Handle );
        
        NdrConformantStringMarshall( (PMIDL_STUB_MESSAGE)& _StubMsg,
                                     (unsigned char __RPC_FAR *)regname,
                                     (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[74] );
        
        NdrSendReceive( (PMIDL_STUB_MESSAGE) &_StubMsg, (unsigned char __RPC_FAR *) _StubMsg.Buffer );
        
        if ( (_RpcMessage.DataRepresentation & 0X0000FFFFUL) != NDR_LOCAL_DATA_REPRESENTATION )
            NdrConvert( (PMIDL_STUB_MESSAGE) &_StubMsg, (PFORMAT_STRING) &__MIDL_ProcFormatString.Format[312] );
        
        _RetVal = *(( int __RPC_FAR * )_StubMsg.Buffer)++;
        
        }
    RpcFinally
        {
        NdrFreeBuffer( (PMIDL_STUB_MESSAGE) &_StubMsg );
        
        }
    RpcEndFinally
    
    return _RetVal;
}


int RPC_UnlockVDT( 
    /* [string][in] */ char __RPC_FAR *regname)
{

    RPC_BINDING_HANDLE _Handle	=	0;
    
    int _RetVal;
    
    RPC_MESSAGE _RpcMessage;
    
    MIDL_STUB_MESSAGE _StubMsg;
    
    if(!regname)
        {
        RpcRaiseException(RPC_X_NULL_REF_POINTER);
        }
    RpcTryFinally
        {
        NdrClientInitializeNew(
                          ( PRPC_MESSAGE  )&_RpcMessage,
                          ( PMIDL_STUB_MESSAGE  )&_StubMsg,
                          ( PMIDL_STUB_DESC  )&pansi_StubDesc,
                          46);
        
        
        _Handle = hPansi;
        
        
        _StubMsg.BufferLength = 12U;
        NdrConformantStringBufferSize( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                       (unsigned char __RPC_FAR *)regname,
                                       (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[74] );
        
        NdrGetBuffer( (PMIDL_STUB_MESSAGE) &_StubMsg, _StubMsg.BufferLength, _Handle );
        
        NdrConformantStringMarshall( (PMIDL_STUB_MESSAGE)& _StubMsg,
                                     (unsigned char __RPC_FAR *)regname,
                                     (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[74] );
        
        NdrSendReceive( (PMIDL_STUB_MESSAGE) &_StubMsg, (unsigned char __RPC_FAR *) _StubMsg.Buffer );
        
        if ( (_RpcMessage.DataRepresentation & 0X0000FFFFUL) != NDR_LOCAL_DATA_REPRESENTATION )
            NdrConvert( (PMIDL_STUB_MESSAGE) &_StubMsg, (PFORMAT_STRING) &__MIDL_ProcFormatString.Format[312] );
        
        _RetVal = *(( int __RPC_FAR * )_StubMsg.Buffer)++;
        
        }
    RpcFinally
        {
        NdrFreeBuffer( (PMIDL_STUB_MESSAGE) &_StubMsg );
        
        }
    RpcEndFinally
    
    return _RetVal;
}


int RPC_LockSysParams( 
    /* [string][in] */ char __RPC_FAR *regname)
{

    RPC_BINDING_HANDLE _Handle	=	0;
    
    int _RetVal;
    
    RPC_MESSAGE _RpcMessage;
    
    MIDL_STUB_MESSAGE _StubMsg;
    
    if(!regname)
        {
        RpcRaiseException(RPC_X_NULL_REF_POINTER);
        }
    RpcTryFinally
        {
        NdrClientInitializeNew(
                          ( PRPC_MESSAGE  )&_RpcMessage,
                          ( PMIDL_STUB_MESSAGE  )&_StubMsg,
                          ( PMIDL_STUB_DESC  )&pansi_StubDesc,
                          47);
        
        
        _Handle = hPansi;
        
        
        _StubMsg.BufferLength = 12U;
        NdrConformantStringBufferSize( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                       (unsigned char __RPC_FAR *)regname,
                                       (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[74] );
        
        NdrGetBuffer( (PMIDL_STUB_MESSAGE) &_StubMsg, _StubMsg.BufferLength, _Handle );
        
        NdrConformantStringMarshall( (PMIDL_STUB_MESSAGE)& _StubMsg,
                                     (unsigned char __RPC_FAR *)regname,
                                     (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[74] );
        
        NdrSendReceive( (PMIDL_STUB_MESSAGE) &_StubMsg, (unsigned char __RPC_FAR *) _StubMsg.Buffer );
        
        if ( (_RpcMessage.DataRepresentation & 0X0000FFFFUL) != NDR_LOCAL_DATA_REPRESENTATION )
            NdrConvert( (PMIDL_STUB_MESSAGE) &_StubMsg, (PFORMAT_STRING) &__MIDL_ProcFormatString.Format[312] );
        
        _RetVal = *(( int __RPC_FAR * )_StubMsg.Buffer)++;
        
        }
    RpcFinally
        {
        NdrFreeBuffer( (PMIDL_STUB_MESSAGE) &_StubMsg );
        
        }
    RpcEndFinally
    
    return _RetVal;
}


int RPC_UnlockSysParams( 
    /* [string][in] */ char __RPC_FAR *regname)
{

    RPC_BINDING_HANDLE _Handle	=	0;
    
    int _RetVal;
    
    RPC_MESSAGE _RpcMessage;
    
    MIDL_STUB_MESSAGE _StubMsg;
    
    if(!regname)
        {
        RpcRaiseException(RPC_X_NULL_REF_POINTER);
        }
    RpcTryFinally
        {
        NdrClientInitializeNew(
                          ( PRPC_MESSAGE  )&_RpcMessage,
                          ( PMIDL_STUB_MESSAGE  )&_StubMsg,
                          ( PMIDL_STUB_DESC  )&pansi_StubDesc,
                          48);
        
        
        _Handle = hPansi;
        
        
        _StubMsg.BufferLength = 12U;
        NdrConformantStringBufferSize( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                       (unsigned char __RPC_FAR *)regname,
                                       (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[74] );
        
        NdrGetBuffer( (PMIDL_STUB_MESSAGE) &_StubMsg, _StubMsg.BufferLength, _Handle );
        
        NdrConformantStringMarshall( (PMIDL_STUB_MESSAGE)& _StubMsg,
                                     (unsigned char __RPC_FAR *)regname,
                                     (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[74] );
        
        NdrSendReceive( (PMIDL_STUB_MESSAGE) &_StubMsg, (unsigned char __RPC_FAR *) _StubMsg.Buffer );
        
        if ( (_RpcMessage.DataRepresentation & 0X0000FFFFUL) != NDR_LOCAL_DATA_REPRESENTATION )
            NdrConvert( (PMIDL_STUB_MESSAGE) &_StubMsg, (PFORMAT_STRING) &__MIDL_ProcFormatString.Format[312] );
        
        _RetVal = *(( int __RPC_FAR * )_StubMsg.Buffer)++;
        
        }
    RpcFinally
        {
        NdrFreeBuffer( (PMIDL_STUB_MESSAGE) &_StubMsg );
        
        }
    RpcEndFinally
    
    return _RetVal;
}


int RPC_LockUserList( 
    /* [string][in] */ char __RPC_FAR *regname)
{

    RPC_BINDING_HANDLE _Handle	=	0;
    
    int _RetVal;
    
    RPC_MESSAGE _RpcMessage;
    
    MIDL_STUB_MESSAGE _StubMsg;
    
    if(!regname)
        {
        RpcRaiseException(RPC_X_NULL_REF_POINTER);
        }
    RpcTryFinally
        {
        NdrClientInitializeNew(
                          ( PRPC_MESSAGE  )&_RpcMessage,
                          ( PMIDL_STUB_MESSAGE  )&_StubMsg,
                          ( PMIDL_STUB_DESC  )&pansi_StubDesc,
                          49);
        
        
        _Handle = hPansi;
        
        
        _StubMsg.BufferLength = 12U;
        NdrConformantStringBufferSize( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                       (unsigned char __RPC_FAR *)regname,
                                       (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[74] );
        
        NdrGetBuffer( (PMIDL_STUB_MESSAGE) &_StubMsg, _StubMsg.BufferLength, _Handle );
        
        NdrConformantStringMarshall( (PMIDL_STUB_MESSAGE)& _StubMsg,
                                     (unsigned char __RPC_FAR *)regname,
                                     (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[74] );
        
        NdrSendReceive( (PMIDL_STUB_MESSAGE) &_StubMsg, (unsigned char __RPC_FAR *) _StubMsg.Buffer );
        
        if ( (_RpcMessage.DataRepresentation & 0X0000FFFFUL) != NDR_LOCAL_DATA_REPRESENTATION )
            NdrConvert( (PMIDL_STUB_MESSAGE) &_StubMsg, (PFORMAT_STRING) &__MIDL_ProcFormatString.Format[312] );
        
        _RetVal = *(( int __RPC_FAR * )_StubMsg.Buffer)++;
        
        }
    RpcFinally
        {
        NdrFreeBuffer( (PMIDL_STUB_MESSAGE) &_StubMsg );
        
        }
    RpcEndFinally
    
    return _RetVal;
}


int RPC_UnlockUserList( 
    /* [string][in] */ char __RPC_FAR *regname)
{

    RPC_BINDING_HANDLE _Handle	=	0;
    
    int _RetVal;
    
    RPC_MESSAGE _RpcMessage;
    
    MIDL_STUB_MESSAGE _StubMsg;
    
    if(!regname)
        {
        RpcRaiseException(RPC_X_NULL_REF_POINTER);
        }
    RpcTryFinally
        {
        NdrClientInitializeNew(
                          ( PRPC_MESSAGE  )&_RpcMessage,
                          ( PMIDL_STUB_MESSAGE  )&_StubMsg,
                          ( PMIDL_STUB_DESC  )&pansi_StubDesc,
                          50);
        
        
        _Handle = hPansi;
        
        
        _StubMsg.BufferLength = 12U;
        NdrConformantStringBufferSize( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                       (unsigned char __RPC_FAR *)regname,
                                       (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[74] );
        
        NdrGetBuffer( (PMIDL_STUB_MESSAGE) &_StubMsg, _StubMsg.BufferLength, _Handle );
        
        NdrConformantStringMarshall( (PMIDL_STUB_MESSAGE)& _StubMsg,
                                     (unsigned char __RPC_FAR *)regname,
                                     (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[74] );
        
        NdrSendReceive( (PMIDL_STUB_MESSAGE) &_StubMsg, (unsigned char __RPC_FAR *) _StubMsg.Buffer );
        
        if ( (_RpcMessage.DataRepresentation & 0X0000FFFFUL) != NDR_LOCAL_DATA_REPRESENTATION )
            NdrConvert( (PMIDL_STUB_MESSAGE) &_StubMsg, (PFORMAT_STRING) &__MIDL_ProcFormatString.Format[312] );
        
        _RetVal = *(( int __RPC_FAR * )_StubMsg.Buffer)++;
        
        }
    RpcFinally
        {
        NdrFreeBuffer( (PMIDL_STUB_MESSAGE) &_StubMsg );
        
        }
    RpcEndFinally
    
    return _RetVal;
}


int RPC_LockDatabase( 
    /* [in] */ long varID,
    /* [string][in] */ char __RPC_FAR *regname)
{

    RPC_BINDING_HANDLE _Handle	=	0;
    
    int _RetVal;
    
    RPC_MESSAGE _RpcMessage;
    
    MIDL_STUB_MESSAGE _StubMsg;
    
    if(!regname)
        {
        RpcRaiseException(RPC_X_NULL_REF_POINTER);
        }
    RpcTryFinally
        {
        NdrClientInitializeNew(
                          ( PRPC_MESSAGE  )&_RpcMessage,
                          ( PMIDL_STUB_MESSAGE  )&_StubMsg,
                          ( PMIDL_STUB_DESC  )&pansi_StubDesc,
                          51);
        
        
        _Handle = hPansi;
        
        
        _StubMsg.BufferLength = 4U + 12U;
        NdrConformantStringBufferSize( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                       (unsigned char __RPC_FAR *)regname,
                                       (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[74] );
        
        NdrGetBuffer( (PMIDL_STUB_MESSAGE) &_StubMsg, _StubMsg.BufferLength, _Handle );
        
        *(( long __RPC_FAR * )_StubMsg.Buffer)++ = varID;
        
        NdrConformantStringMarshall( (PMIDL_STUB_MESSAGE)& _StubMsg,
                                     (unsigned char __RPC_FAR *)regname,
                                     (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[74] );
        
        NdrSendReceive( (PMIDL_STUB_MESSAGE) &_StubMsg, (unsigned char __RPC_FAR *) _StubMsg.Buffer );
        
        if ( (_RpcMessage.DataRepresentation & 0X0000FFFFUL) != NDR_LOCAL_DATA_REPRESENTATION )
            NdrConvert( (PMIDL_STUB_MESSAGE) &_StubMsg, (PFORMAT_STRING) &__MIDL_ProcFormatString.Format[318] );
        
        _RetVal = *(( int __RPC_FAR * )_StubMsg.Buffer)++;
        
        }
    RpcFinally
        {
        NdrFreeBuffer( (PMIDL_STUB_MESSAGE) &_StubMsg );
        
        }
    RpcEndFinally
    
    return _RetVal;
}


int RPC_UnlockDatabase( 
    /* [in] */ long varID,
    /* [string][in] */ char __RPC_FAR *regname)
{

    RPC_BINDING_HANDLE _Handle	=	0;
    
    int _RetVal;
    
    RPC_MESSAGE _RpcMessage;
    
    MIDL_STUB_MESSAGE _StubMsg;
    
    if(!regname)
        {
        RpcRaiseException(RPC_X_NULL_REF_POINTER);
        }
    RpcTryFinally
        {
        NdrClientInitializeNew(
                          ( PRPC_MESSAGE  )&_RpcMessage,
                          ( PMIDL_STUB_MESSAGE  )&_StubMsg,
                          ( PMIDL_STUB_DESC  )&pansi_StubDesc,
                          52);
        
        
        _Handle = hPansi;
        
        
        _StubMsg.BufferLength = 4U + 12U;
        NdrConformantStringBufferSize( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                       (unsigned char __RPC_FAR *)regname,
                                       (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[74] );
        
        NdrGetBuffer( (PMIDL_STUB_MESSAGE) &_StubMsg, _StubMsg.BufferLength, _Handle );
        
        *(( long __RPC_FAR * )_StubMsg.Buffer)++ = varID;
        
        NdrConformantStringMarshall( (PMIDL_STUB_MESSAGE)& _StubMsg,
                                     (unsigned char __RPC_FAR *)regname,
                                     (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[74] );
        
        NdrSendReceive( (PMIDL_STUB_MESSAGE) &_StubMsg, (unsigned char __RPC_FAR *) _StubMsg.Buffer );
        
        if ( (_RpcMessage.DataRepresentation & 0X0000FFFFUL) != NDR_LOCAL_DATA_REPRESENTATION )
            NdrConvert( (PMIDL_STUB_MESSAGE) &_StubMsg, (PFORMAT_STRING) &__MIDL_ProcFormatString.Format[318] );
        
        _RetVal = *(( int __RPC_FAR * )_StubMsg.Buffer)++;
        
        }
    RpcFinally
        {
        NdrFreeBuffer( (PMIDL_STUB_MESSAGE) &_StubMsg );
        
        }
    RpcEndFinally
    
    return _RetVal;
}


int RPC_LockPlanbase( 
    /* [in] */ long varID,
    /* [string][in] */ char __RPC_FAR *regname)
{

    RPC_BINDING_HANDLE _Handle	=	0;
    
    int _RetVal;
    
    RPC_MESSAGE _RpcMessage;
    
    MIDL_STUB_MESSAGE _StubMsg;
    
    if(!regname)
        {
        RpcRaiseException(RPC_X_NULL_REF_POINTER);
        }
    RpcTryFinally
        {
        NdrClientInitializeNew(
                          ( PRPC_MESSAGE  )&_RpcMessage,
                          ( PMIDL_STUB_MESSAGE  )&_StubMsg,
                          ( PMIDL_STUB_DESC  )&pansi_StubDesc,
                          53);
        
        
        _Handle = hPansi;
        
        
        _StubMsg.BufferLength = 4U + 12U;
        NdrConformantStringBufferSize( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                       (unsigned char __RPC_FAR *)regname,
                                       (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[74] );
        
        NdrGetBuffer( (PMIDL_STUB_MESSAGE) &_StubMsg, _StubMsg.BufferLength, _Handle );
        
        *(( long __RPC_FAR * )_StubMsg.Buffer)++ = varID;
        
        NdrConformantStringMarshall( (PMIDL_STUB_MESSAGE)& _StubMsg,
                                     (unsigned char __RPC_FAR *)regname,
                                     (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[74] );
        
        NdrSendReceive( (PMIDL_STUB_MESSAGE) &_StubMsg, (unsigned char __RPC_FAR *) _StubMsg.Buffer );
        
        if ( (_RpcMessage.DataRepresentation & 0X0000FFFFUL) != NDR_LOCAL_DATA_REPRESENTATION )
            NdrConvert( (PMIDL_STUB_MESSAGE) &_StubMsg, (PFORMAT_STRING) &__MIDL_ProcFormatString.Format[318] );
        
        _RetVal = *(( int __RPC_FAR * )_StubMsg.Buffer)++;
        
        }
    RpcFinally
        {
        NdrFreeBuffer( (PMIDL_STUB_MESSAGE) &_StubMsg );
        
        }
    RpcEndFinally
    
    return _RetVal;
}


int RPC_UnlockPlanbase( 
    /* [in] */ long varID,
    /* [string][in] */ char __RPC_FAR *regname)
{

    RPC_BINDING_HANDLE _Handle	=	0;
    
    int _RetVal;
    
    RPC_MESSAGE _RpcMessage;
    
    MIDL_STUB_MESSAGE _StubMsg;
    
    if(!regname)
        {
        RpcRaiseException(RPC_X_NULL_REF_POINTER);
        }
    RpcTryFinally
        {
        NdrClientInitializeNew(
                          ( PRPC_MESSAGE  )&_RpcMessage,
                          ( PMIDL_STUB_MESSAGE  )&_StubMsg,
                          ( PMIDL_STUB_DESC  )&pansi_StubDesc,
                          54);
        
        
        _Handle = hPansi;
        
        
        _StubMsg.BufferLength = 4U + 12U;
        NdrConformantStringBufferSize( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                       (unsigned char __RPC_FAR *)regname,
                                       (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[74] );
        
        NdrGetBuffer( (PMIDL_STUB_MESSAGE) &_StubMsg, _StubMsg.BufferLength, _Handle );
        
        *(( long __RPC_FAR * )_StubMsg.Buffer)++ = varID;
        
        NdrConformantStringMarshall( (PMIDL_STUB_MESSAGE)& _StubMsg,
                                     (unsigned char __RPC_FAR *)regname,
                                     (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[74] );
        
        NdrSendReceive( (PMIDL_STUB_MESSAGE) &_StubMsg, (unsigned char __RPC_FAR *) _StubMsg.Buffer );
        
        if ( (_RpcMessage.DataRepresentation & 0X0000FFFFUL) != NDR_LOCAL_DATA_REPRESENTATION )
            NdrConvert( (PMIDL_STUB_MESSAGE) &_StubMsg, (PFORMAT_STRING) &__MIDL_ProcFormatString.Format[318] );
        
        _RetVal = *(( int __RPC_FAR * )_StubMsg.Buffer)++;
        
        }
    RpcFinally
        {
        NdrFreeBuffer( (PMIDL_STUB_MESSAGE) &_StubMsg );
        
        }
    RpcEndFinally
    
    return _RetVal;
}


int RPC_LockOperation( 
    /* [in] */ long varID,
    /* [string][in] */ char __RPC_FAR *regname)
{

    RPC_BINDING_HANDLE _Handle	=	0;
    
    int _RetVal;
    
    RPC_MESSAGE _RpcMessage;
    
    MIDL_STUB_MESSAGE _StubMsg;
    
    if(!regname)
        {
        RpcRaiseException(RPC_X_NULL_REF_POINTER);
        }
    RpcTryFinally
        {
        NdrClientInitializeNew(
                          ( PRPC_MESSAGE  )&_RpcMessage,
                          ( PMIDL_STUB_MESSAGE  )&_StubMsg,
                          ( PMIDL_STUB_DESC  )&pansi_StubDesc,
                          55);
        
        
        _Handle = hPansi;
        
        
        _StubMsg.BufferLength = 4U + 12U;
        NdrConformantStringBufferSize( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                       (unsigned char __RPC_FAR *)regname,
                                       (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[74] );
        
        NdrGetBuffer( (PMIDL_STUB_MESSAGE) &_StubMsg, _StubMsg.BufferLength, _Handle );
        
        *(( long __RPC_FAR * )_StubMsg.Buffer)++ = varID;
        
        NdrConformantStringMarshall( (PMIDL_STUB_MESSAGE)& _StubMsg,
                                     (unsigned char __RPC_FAR *)regname,
                                     (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[74] );
        
        NdrSendReceive( (PMIDL_STUB_MESSAGE) &_StubMsg, (unsigned char __RPC_FAR *) _StubMsg.Buffer );
        
        if ( (_RpcMessage.DataRepresentation & 0X0000FFFFUL) != NDR_LOCAL_DATA_REPRESENTATION )
            NdrConvert( (PMIDL_STUB_MESSAGE) &_StubMsg, (PFORMAT_STRING) &__MIDL_ProcFormatString.Format[318] );
        
        _RetVal = *(( int __RPC_FAR * )_StubMsg.Buffer)++;
        
        }
    RpcFinally
        {
        NdrFreeBuffer( (PMIDL_STUB_MESSAGE) &_StubMsg );
        
        }
    RpcEndFinally
    
    return _RetVal;
}


int RPC_UnlockOperation( 
    /* [in] */ long varID,
    /* [string][in] */ char __RPC_FAR *regname)
{

    RPC_BINDING_HANDLE _Handle	=	0;
    
    int _RetVal;
    
    RPC_MESSAGE _RpcMessage;
    
    MIDL_STUB_MESSAGE _StubMsg;
    
    if(!regname)
        {
        RpcRaiseException(RPC_X_NULL_REF_POINTER);
        }
    RpcTryFinally
        {
        NdrClientInitializeNew(
                          ( PRPC_MESSAGE  )&_RpcMessage,
                          ( PMIDL_STUB_MESSAGE  )&_StubMsg,
                          ( PMIDL_STUB_DESC  )&pansi_StubDesc,
                          56);
        
        
        _Handle = hPansi;
        
        
        _StubMsg.BufferLength = 4U + 12U;
        NdrConformantStringBufferSize( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                       (unsigned char __RPC_FAR *)regname,
                                       (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[74] );
        
        NdrGetBuffer( (PMIDL_STUB_MESSAGE) &_StubMsg, _StubMsg.BufferLength, _Handle );
        
        *(( long __RPC_FAR * )_StubMsg.Buffer)++ = varID;
        
        NdrConformantStringMarshall( (PMIDL_STUB_MESSAGE)& _StubMsg,
                                     (unsigned char __RPC_FAR *)regname,
                                     (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[74] );
        
        NdrSendReceive( (PMIDL_STUB_MESSAGE) &_StubMsg, (unsigned char __RPC_FAR *) _StubMsg.Buffer );
        
        if ( (_RpcMessage.DataRepresentation & 0X0000FFFFUL) != NDR_LOCAL_DATA_REPRESENTATION )
            NdrConvert( (PMIDL_STUB_MESSAGE) &_StubMsg, (PFORMAT_STRING) &__MIDL_ProcFormatString.Format[318] );
        
        _RetVal = *(( int __RPC_FAR * )_StubMsg.Buffer)++;
        
        }
    RpcFinally
        {
        NdrFreeBuffer( (PMIDL_STUB_MESSAGE) &_StubMsg );
        
        }
    RpcEndFinally
    
    return _RetVal;
}


int RPC_GetSignalVarNum( 
    /* [string][in] */ char __RPC_FAR *datetime,
    /* [in] */ long yxvid,
    /* [out] */ int __RPC_FAR *nrec)
{

    RPC_BINDING_HANDLE _Handle	=	0;
    
    int _RetVal;
    
    RPC_MESSAGE _RpcMessage;
    
    MIDL_STUB_MESSAGE _StubMsg;
    
    if(!datetime)
        {
        RpcRaiseException(RPC_X_NULL_REF_POINTER);
        }
    if(!nrec)
        {
        RpcRaiseException(RPC_X_NULL_REF_POINTER);
        }
    RpcTryFinally
        {
        NdrClientInitializeNew(
                          ( PRPC_MESSAGE  )&_RpcMessage,
                          ( PMIDL_STUB_MESSAGE  )&_StubMsg,
                          ( PMIDL_STUB_DESC  )&pansi_StubDesc,
                          57);
        
        
        _Handle = hPansi;
        
        
        _StubMsg.BufferLength = 12U + 11U;
        NdrConformantStringBufferSize( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                       (unsigned char __RPC_FAR *)datetime,
                                       (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[74] );
        
        NdrGetBuffer( (PMIDL_STUB_MESSAGE) &_StubMsg, _StubMsg.BufferLength, _Handle );
        
        NdrConformantStringMarshall( (PMIDL_STUB_MESSAGE)& _StubMsg,
                                     (unsigned char __RPC_FAR *)datetime,
                                     (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[74] );
        
        _StubMsg.Buffer = (unsigned char __RPC_FAR *)(((long)_StubMsg.Buffer + 3) & ~ 0x3);
        *(( long __RPC_FAR * )_StubMsg.Buffer)++ = yxvid;
        
        NdrSendReceive( (PMIDL_STUB_MESSAGE) &_StubMsg, (unsigned char __RPC_FAR *) _StubMsg.Buffer );
        
        if ( (_RpcMessage.DataRepresentation & 0X0000FFFFUL) != NDR_LOCAL_DATA_REPRESENTATION )
            NdrConvert( (PMIDL_STUB_MESSAGE) &_StubMsg, (PFORMAT_STRING) &__MIDL_ProcFormatString.Format[326] );
        
        *nrec = *(( int __RPC_FAR * )_StubMsg.Buffer)++;
        
        _RetVal = *(( int __RPC_FAR * )_StubMsg.Buffer)++;
        
        }
    RpcFinally
        {
        NdrFreeBuffer( (PMIDL_STUB_MESSAGE) &_StubMsg );
        
        }
    RpcEndFinally
    
    return _RetVal;
}


int RPC_GetSignalVarID( 
    /* [string][in] */ char __RPC_FAR *datetime,
    /* [in] */ long yxvid,
    /* [size_is][out] */ long __RPC_FAR ycvids[  ],
    /* [in] */ int n)
{

    RPC_BINDING_HANDLE _Handle	=	0;
    
    int _RetVal;
    
    RPC_MESSAGE _RpcMessage;
    
    MIDL_STUB_MESSAGE _StubMsg;
    
    if(!datetime)
        {
        RpcRaiseException(RPC_X_NULL_REF_POINTER);
        }
    RpcTryFinally
        {
        NdrClientInitializeNew(
                          ( PRPC_MESSAGE  )&_RpcMessage,
                          ( PMIDL_STUB_MESSAGE  )&_StubMsg,
                          ( PMIDL_STUB_DESC  )&pansi_StubDesc,
                          58);
        
        
        _Handle = hPansi;
        
        
        _StubMsg.BufferLength = 12U + 11U + 7U;
        NdrConformantStringBufferSize( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                       (unsigned char __RPC_FAR *)datetime,
                                       (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[74] );
        
        NdrGetBuffer( (PMIDL_STUB_MESSAGE) &_StubMsg, _StubMsg.BufferLength, _Handle );
        
        NdrConformantStringMarshall( (PMIDL_STUB_MESSAGE)& _StubMsg,
                                     (unsigned char __RPC_FAR *)datetime,
                                     (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[74] );
        
        _StubMsg.Buffer = (unsigned char __RPC_FAR *)(((long)_StubMsg.Buffer + 3) & ~ 0x3);
        *(( long __RPC_FAR * )_StubMsg.Buffer)++ = yxvid;
        
        *(( int __RPC_FAR * )_StubMsg.Buffer)++ = n;
        
        NdrSendReceive( (PMIDL_STUB_MESSAGE) &_StubMsg, (unsigned char __RPC_FAR *) _StubMsg.Buffer );
        
        if ( (_RpcMessage.DataRepresentation & 0X0000FFFFUL) != NDR_LOCAL_DATA_REPRESENTATION )
            NdrConvert( (PMIDL_STUB_MESSAGE) &_StubMsg, (PFORMAT_STRING) &__MIDL_ProcFormatString.Format[338] );
        
        NdrConformantArrayUnmarshall( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                      (unsigned char __RPC_FAR * __RPC_FAR *)&ycvids,
                                      (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[326],
                                      (unsigned char)0 );
        
        _RetVal = *(( int __RPC_FAR * )_StubMsg.Buffer)++;
        
        }
    RpcFinally
        {
        NdrFreeBuffer( (PMIDL_STUB_MESSAGE) &_StubMsg );
        
        }
    RpcEndFinally
    
    return _RetVal;
}


int RPC_LoadSignalVarData( 
    /* [string][in] */ char __RPC_FAR *datetime,
    /* [in] */ long yxvid,
    /* [in] */ long ycvid,
    /* [size_is][out] */ float __RPC_FAR pData[  ],
    /* [size_is][out] */ int __RPC_FAR pInterval[  ],
    /* [in] */ int nrec)
{

    RPC_BINDING_HANDLE _Handle	=	0;
    
    int _RetVal;
    
    RPC_MESSAGE _RpcMessage;
    
    MIDL_STUB_MESSAGE _StubMsg;
    
    if(!datetime)
        {
        RpcRaiseException(RPC_X_NULL_REF_POINTER);
        }
    RpcTryFinally
        {
        NdrClientInitializeNew(
                          ( PRPC_MESSAGE  )&_RpcMessage,
                          ( PMIDL_STUB_MESSAGE  )&_StubMsg,
                          ( PMIDL_STUB_DESC  )&pansi_StubDesc,
                          59);
        
        
        _Handle = hPansi;
        
        
        _StubMsg.BufferLength = 12U + 11U + 7U + 7U;
        NdrConformantStringBufferSize( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                       (unsigned char __RPC_FAR *)datetime,
                                       (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[74] );
        
        NdrGetBuffer( (PMIDL_STUB_MESSAGE) &_StubMsg, _StubMsg.BufferLength, _Handle );
        
        NdrConformantStringMarshall( (PMIDL_STUB_MESSAGE)& _StubMsg,
                                     (unsigned char __RPC_FAR *)datetime,
                                     (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[74] );
        
        _StubMsg.Buffer = (unsigned char __RPC_FAR *)(((long)_StubMsg.Buffer + 3) & ~ 0x3);
        *(( long __RPC_FAR * )_StubMsg.Buffer)++ = yxvid;
        
        *(( long __RPC_FAR * )_StubMsg.Buffer)++ = ycvid;
        
        *(( int __RPC_FAR * )_StubMsg.Buffer)++ = nrec;
        
        NdrSendReceive( (PMIDL_STUB_MESSAGE) &_StubMsg, (unsigned char __RPC_FAR *) _StubMsg.Buffer );
        
        if ( (_RpcMessage.DataRepresentation & 0X0000FFFFUL) != NDR_LOCAL_DATA_REPRESENTATION )
            NdrConvert( (PMIDL_STUB_MESSAGE) &_StubMsg, (PFORMAT_STRING) &__MIDL_ProcFormatString.Format[352] );
        
        NdrConformantArrayUnmarshall( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                      (unsigned char __RPC_FAR * __RPC_FAR *)&pData,
                                      (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[434],
                                      (unsigned char)0 );
        
        NdrConformantArrayUnmarshall( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                      (unsigned char __RPC_FAR * __RPC_FAR *)&pInterval,
                                      (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[444],
                                      (unsigned char)0 );
        
        _RetVal = *(( int __RPC_FAR * )_StubMsg.Buffer)++;
        
        }
    RpcFinally
        {
        NdrFreeBuffer( (PMIDL_STUB_MESSAGE) &_StubMsg );
        
        }
    RpcEndFinally
    
    return _RetVal;
}


int RPC_LoadPlanningData( 
    /* [in] */ long varID,
    /* [size_is][out] */ float __RPC_FAR pData[  ],
    /* [in] */ int n)
{

    RPC_BINDING_HANDLE _Handle	=	0;
    
    int _RetVal;
    
    RPC_MESSAGE _RpcMessage;
    
    MIDL_STUB_MESSAGE _StubMsg;
    
    RpcTryFinally
        {
        NdrClientInitializeNew(
                          ( PRPC_MESSAGE  )&_RpcMessage,
                          ( PMIDL_STUB_MESSAGE  )&_StubMsg,
                          ( PMIDL_STUB_DESC  )&pansi_StubDesc,
                          60);
        
        
        _Handle = hPansi;
        
        
        _StubMsg.BufferLength = 4U + 4U;
        NdrGetBuffer( (PMIDL_STUB_MESSAGE) &_StubMsg, _StubMsg.BufferLength, _Handle );
        
        *(( long __RPC_FAR * )_StubMsg.Buffer)++ = varID;
        
        *(( int __RPC_FAR * )_StubMsg.Buffer)++ = n;
        
        NdrSendReceive( (PMIDL_STUB_MESSAGE) &_StubMsg, (unsigned char __RPC_FAR *) _StubMsg.Buffer );
        
        if ( (_RpcMessage.DataRepresentation & 0X0000FFFFUL) != NDR_LOCAL_DATA_REPRESENTATION )
            NdrConvert( (PMIDL_STUB_MESSAGE) &_StubMsg, (PFORMAT_STRING) &__MIDL_ProcFormatString.Format[372] );
        
        NdrConformantArrayUnmarshall( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                      (unsigned char __RPC_FAR * __RPC_FAR *)&pData,
                                      (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[454],
                                      (unsigned char)0 );
        
        _RetVal = *(( int __RPC_FAR * )_StubMsg.Buffer)++;
        
        }
    RpcFinally
        {
        NdrFreeBuffer( (PMIDL_STUB_MESSAGE) &_StubMsg );
        
        }
    RpcEndFinally
    
    return _RetVal;
}


int RPC_SetPlanningData( 
    /* [in] */ long varID,
    /* [size_is][in] */ float __RPC_FAR pData[  ],
    /* [in] */ int n)
{

    RPC_BINDING_HANDLE _Handle	=	0;
    
    int _RetVal;
    
    RPC_MESSAGE _RpcMessage;
    
    MIDL_STUB_MESSAGE _StubMsg;
    
    RpcTryFinally
        {
        NdrClientInitializeNew(
                          ( PRPC_MESSAGE  )&_RpcMessage,
                          ( PMIDL_STUB_MESSAGE  )&_StubMsg,
                          ( PMIDL_STUB_DESC  )&pansi_StubDesc,
                          61);
        
        
        _Handle = hPansi;
        
        
        _StubMsg.BufferLength = 4U + 4U + 7U;
        _StubMsg.MaxCount = n;
        
        NdrConformantArrayBufferSize( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                      (unsigned char __RPC_FAR *)pData,
                                      (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[454] );
        
        NdrGetBuffer( (PMIDL_STUB_MESSAGE) &_StubMsg, _StubMsg.BufferLength, _Handle );
        
        *(( long __RPC_FAR * )_StubMsg.Buffer)++ = varID;
        
        _StubMsg.MaxCount = n;
        
        NdrConformantArrayMarshall( (PMIDL_STUB_MESSAGE)& _StubMsg,
                                    (unsigned char __RPC_FAR *)pData,
                                    (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[454] );
        
        *(( int __RPC_FAR * )_StubMsg.Buffer)++ = n;
        
        NdrSendReceive( (PMIDL_STUB_MESSAGE) &_StubMsg, (unsigned char __RPC_FAR *) _StubMsg.Buffer );
        
        if ( (_RpcMessage.DataRepresentation & 0X0000FFFFUL) != NDR_LOCAL_DATA_REPRESENTATION )
            NdrConvert( (PMIDL_STUB_MESSAGE) &_StubMsg, (PFORMAT_STRING) &__MIDL_ProcFormatString.Format[382] );
        
        _RetVal = *(( int __RPC_FAR * )_StubMsg.Buffer)++;
        
        }
    RpcFinally
        {
        NdrFreeBuffer( (PMIDL_STUB_MESSAGE) &_StubMsg );
        
        }
    RpcEndFinally
    
    return _RetVal;
}


int RPC_GetUserNum( void)
{

    RPC_BINDING_HANDLE _Handle	=	0;
    
    int _RetVal;
    
    RPC_MESSAGE _RpcMessage;
    
    MIDL_STUB_MESSAGE _StubMsg;
    
    RpcTryFinally
        {
        NdrClientInitializeNew(
                          ( PRPC_MESSAGE  )&_RpcMessage,
                          ( PMIDL_STUB_MESSAGE  )&_StubMsg,
                          ( PMIDL_STUB_DESC  )&pansi_StubDesc,
                          62);
        
        
        _Handle = hPansi;
        
        
        _StubMsg.BufferLength = 0U;
        NdrGetBuffer( (PMIDL_STUB_MESSAGE) &_StubMsg, _StubMsg.BufferLength, _Handle );
        
        NdrSendReceive( (PMIDL_STUB_MESSAGE) &_StubMsg, (unsigned char __RPC_FAR *) _StubMsg.Buffer );
        
        if ( (_RpcMessage.DataRepresentation & 0X0000FFFFUL) != NDR_LOCAL_DATA_REPRESENTATION )
            NdrConvert( (PMIDL_STUB_MESSAGE) &_StubMsg, (PFORMAT_STRING) &__MIDL_ProcFormatString.Format[2] );
        
        _RetVal = *(( int __RPC_FAR * )_StubMsg.Buffer)++;
        
        }
    RpcFinally
        {
        NdrFreeBuffer( (PMIDL_STUB_MESSAGE) &_StubMsg );
        
        }
    RpcEndFinally
    
    return _RetVal;
}


int RPC_LoadUserList( 
    /* [size_is][out] */ PS_USERITEM __RPC_FAR pUserItem[  ],
    /* [in] */ int n)
{

    RPC_BINDING_HANDLE _Handle	=	0;
    
    int _RetVal;
    
    RPC_MESSAGE _RpcMessage;
    
    MIDL_STUB_MESSAGE _StubMsg;
    
    RpcTryFinally
        {
        NdrClientInitializeNew(
                          ( PRPC_MESSAGE  )&_RpcMessage,
                          ( PMIDL_STUB_MESSAGE  )&_StubMsg,
                          ( PMIDL_STUB_DESC  )&pansi_StubDesc,
                          63);
        
        
        _Handle = hPansi;
        
        
        _StubMsg.BufferLength = 4U;
        NdrGetBuffer( (PMIDL_STUB_MESSAGE) &_StubMsg, _StubMsg.BufferLength, _Handle );
        
        *(( int __RPC_FAR * )_StubMsg.Buffer)++ = n;
        
        NdrSendReceive( (PMIDL_STUB_MESSAGE) &_StubMsg, (unsigned char __RPC_FAR *) _StubMsg.Buffer );
        
        if ( (_RpcMessage.DataRepresentation & 0X0000FFFFUL) != NDR_LOCAL_DATA_REPRESENTATION )
            NdrConvert( (PMIDL_STUB_MESSAGE) &_StubMsg, (PFORMAT_STRING) &__MIDL_ProcFormatString.Format[392] );
        
        NdrConformantArrayUnmarshall( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                      (unsigned char __RPC_FAR * __RPC_FAR *)&pUserItem,
                                      (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[464],
                                      (unsigned char)0 );
        
        _RetVal = *(( int __RPC_FAR * )_StubMsg.Buffer)++;
        
        }
    RpcFinally
        {
        NdrFreeBuffer( (PMIDL_STUB_MESSAGE) &_StubMsg );
        
        }
    RpcEndFinally
    
    return _RetVal;
}


int RPC_InsertEvent( 
    /* [size_is][in] */ char __RPC_FAR pEvents[  ],
    /* [in] */ int size)
{

    RPC_BINDING_HANDLE _Handle	=	0;
    
    int _RetVal;
    
    RPC_MESSAGE _RpcMessage;
    
    MIDL_STUB_MESSAGE _StubMsg;
    
    RpcTryFinally
        {
        NdrClientInitializeNew(
                          ( PRPC_MESSAGE  )&_RpcMessage,
                          ( PMIDL_STUB_MESSAGE  )&_StubMsg,
                          ( PMIDL_STUB_DESC  )&pansi_StubDesc,
                          64);
        
        
        _Handle = hPansi;
        
        
        _StubMsg.BufferLength = 4U + 11U;
        _StubMsg.MaxCount = size;
        
        NdrConformantArrayBufferSize( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                      (unsigned char __RPC_FAR *)pEvents,
                                      (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[62] );
        
        NdrGetBuffer( (PMIDL_STUB_MESSAGE) &_StubMsg, _StubMsg.BufferLength, _Handle );
        
        _StubMsg.MaxCount = size;
        
        NdrConformantArrayMarshall( (PMIDL_STUB_MESSAGE)& _StubMsg,
                                    (unsigned char __RPC_FAR *)pEvents,
                                    (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[62] );
        
        _StubMsg.Buffer = (unsigned char __RPC_FAR *)(((long)_StubMsg.Buffer + 3) & ~ 0x3);
        *(( int __RPC_FAR * )_StubMsg.Buffer)++ = size;
        
        NdrSendReceive( (PMIDL_STUB_MESSAGE) &_StubMsg, (unsigned char __RPC_FAR *) _StubMsg.Buffer );
        
        if ( (_RpcMessage.DataRepresentation & 0X0000FFFFUL) != NDR_LOCAL_DATA_REPRESENTATION )
            NdrConvert( (PMIDL_STUB_MESSAGE) &_StubMsg, (PFORMAT_STRING) &__MIDL_ProcFormatString.Format[400] );
        
        _RetVal = *(( int __RPC_FAR * )_StubMsg.Buffer)++;
        
        }
    RpcFinally
        {
        NdrFreeBuffer( (PMIDL_STUB_MESSAGE) &_StubMsg );
        
        }
    RpcEndFinally
    
    return _RetVal;
}


int RPC_DeleteEvent( 
    /* [size_is][in] */ char __RPC_FAR pEvents[  ],
    /* [in] */ int size)
{

    RPC_BINDING_HANDLE _Handle	=	0;
    
    int _RetVal;
    
    RPC_MESSAGE _RpcMessage;
    
    MIDL_STUB_MESSAGE _StubMsg;
    
    RpcTryFinally
        {
        NdrClientInitializeNew(
                          ( PRPC_MESSAGE  )&_RpcMessage,
                          ( PMIDL_STUB_MESSAGE  )&_StubMsg,
                          ( PMIDL_STUB_DESC  )&pansi_StubDesc,
                          65);
        
        
        _Handle = hPansi;
        
        
        _StubMsg.BufferLength = 4U + 11U;
        _StubMsg.MaxCount = size;
        
        NdrConformantArrayBufferSize( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                      (unsigned char __RPC_FAR *)pEvents,
                                      (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[62] );
        
        NdrGetBuffer( (PMIDL_STUB_MESSAGE) &_StubMsg, _StubMsg.BufferLength, _Handle );
        
        _StubMsg.MaxCount = size;
        
        NdrConformantArrayMarshall( (PMIDL_STUB_MESSAGE)& _StubMsg,
                                    (unsigned char __RPC_FAR *)pEvents,
                                    (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[62] );
        
        _StubMsg.Buffer = (unsigned char __RPC_FAR *)(((long)_StubMsg.Buffer + 3) & ~ 0x3);
        *(( int __RPC_FAR * )_StubMsg.Buffer)++ = size;
        
        NdrSendReceive( (PMIDL_STUB_MESSAGE) &_StubMsg, (unsigned char __RPC_FAR *) _StubMsg.Buffer );
        
        if ( (_RpcMessage.DataRepresentation & 0X0000FFFFUL) != NDR_LOCAL_DATA_REPRESENTATION )
            NdrConvert( (PMIDL_STUB_MESSAGE) &_StubMsg, (PFORMAT_STRING) &__MIDL_ProcFormatString.Format[400] );
        
        _RetVal = *(( int __RPC_FAR * )_StubMsg.Buffer)++;
        
        }
    RpcFinally
        {
        NdrFreeBuffer( (PMIDL_STUB_MESSAGE) &_StubMsg );
        
        }
    RpcEndFinally
    
    return _RetVal;
}


static const MIDL_STUB_DESC pansi_StubDesc = 
    {
    (void __RPC_FAR *)& pansi___RpcClientInterface,
    MIDL_user_allocate,
    MIDL_user_free,
    &hPansi,
    0,
    0,
    0,
    0,
    __MIDL_TypeFormatString.Format,
    1, /* -error bounds_check flag */
    0x10001, /* Ndr library version */
    0,
    0x50100a4, /* MIDL Version 5.1.164 */
    0,
    0,
    0,  /* notify & notify_flag routine table */
    1,  /* Flags */
    0,  /* Reserved3 */
    0,  /* Reserved4 */
    0   /* Reserved5 */
    };

#if !defined(__RPC_WIN32__)
#error  Invalid build platform for this stub.
#endif

static const MIDL_PROC_FORMAT_STRING __MIDL_ProcFormatString =
    {
        0,
        {
			0x5b,		/* FC_END */
			0x5c,		/* FC_PAD */
/*  2 */	0x53,		/* FC_RETURN_PARAM_BASETYPE */
			0x8,		/* FC_LONG */
/*  4 */	
			0x50,		/* FC_IN_OUT_PARAM */
#ifndef _ALPHA_
			0x1,		/* x86, MIPS & PPC Stack size = 1 */
#else
			0x2,		/* Alpha Stack size = 2 */
#endif
/*  6 */	NdrFcShort( 0x2c ),	/* Type Offset=44 */
/*  8 */	0x4e,		/* FC_IN_PARAM_BASETYPE */
			0x8,		/* FC_LONG */
/* 10 */	0x53,		/* FC_RETURN_PARAM_BASETYPE */
			0x8,		/* FC_LONG */
/* 12 */	
			0x4d,		/* FC_IN_PARAM */
#ifndef _ALPHA_
			0x1,		/* x86, MIPS & PPC Stack size = 1 */
#else
			0x2,		/* Alpha Stack size = 2 */
#endif
/* 14 */	NdrFcShort( 0x3a ),	/* Type Offset=58 */
/* 16 */	0x4e,		/* FC_IN_PARAM_BASETYPE */
			0x8,		/* FC_LONG */
/* 18 */	
			0x51,		/* FC_OUT_PARAM */
#ifndef _ALPHA_
			0x1,		/* x86, MIPS & PPC Stack size = 1 */
#else
			0x2,		/* Alpha Stack size = 2 */
#endif
/* 20 */	NdrFcShort( 0x3e ),	/* Type Offset=62 */
/* 22 */	0x53,		/* FC_RETURN_PARAM_BASETYPE */
			0x8,		/* FC_LONG */
/* 24 */	
			0x4d,		/* FC_IN_PARAM */
#ifndef _ALPHA_
			0x1,		/* x86, MIPS & PPC Stack size = 1 */
#else
			0x2,		/* Alpha Stack size = 2 */
#endif
/* 26 */	NdrFcShort( 0x3a ),	/* Type Offset=58 */
/* 28 */	0x4e,		/* FC_IN_PARAM_BASETYPE */
			0x8,		/* FC_LONG */
/* 30 */	
			0x4d,		/* FC_IN_PARAM */
#ifndef _ALPHA_
			0x1,		/* x86, MIPS & PPC Stack size = 1 */
#else
			0x2,		/* Alpha Stack size = 2 */
#endif
/* 32 */	NdrFcShort( 0x3e ),	/* Type Offset=62 */
/* 34 */	
			0x4d,		/* FC_IN_PARAM */
#ifndef _ALPHA_
			0x1,		/* x86, MIPS & PPC Stack size = 1 */
#else
			0x2,		/* Alpha Stack size = 2 */
#endif
/* 36 */	NdrFcShort( 0x48 ),	/* Type Offset=72 */
/* 38 */	0x53,		/* FC_RETURN_PARAM_BASETYPE */
			0x8,		/* FC_LONG */
/* 40 */	
			0x51,		/* FC_OUT_PARAM */
#ifndef _ALPHA_
			0x1,		/* x86, MIPS & PPC Stack size = 1 */
#else
			0x2,		/* Alpha Stack size = 2 */
#endif
/* 42 */	NdrFcShort( 0x4c ),	/* Type Offset=76 */
/* 44 */	0x53,		/* FC_RETURN_PARAM_BASETYPE */
			0x8,		/* FC_LONG */
/* 46 */	
			0x51,		/* FC_OUT_PARAM */
#ifndef _ALPHA_
			0x1,		/* x86, MIPS & PPC Stack size = 1 */
#else
			0x2,		/* Alpha Stack size = 2 */
#endif
/* 48 */	NdrFcShort( 0x3e ),	/* Type Offset=62 */
/* 50 */	0x4e,		/* FC_IN_PARAM_BASETYPE */
			0x8,		/* FC_LONG */
/* 52 */	0x53,		/* FC_RETURN_PARAM_BASETYPE */
			0x8,		/* FC_LONG */
/* 54 */	
			0x51,		/* FC_OUT_PARAM */
#ifndef _ALPHA_
			0x1,		/* x86, MIPS & PPC Stack size = 1 */
#else
			0x2,		/* Alpha Stack size = 2 */
#endif
/* 56 */	NdrFcShort( 0x3e ),	/* Type Offset=62 */
/* 58 */	0x4e,		/* FC_IN_PARAM_BASETYPE */
			0x8,		/* FC_LONG */
/* 60 */	0x4e,		/* FC_IN_PARAM_BASETYPE */
			0x8,		/* FC_LONG */
/* 62 */	0x53,		/* FC_RETURN_PARAM_BASETYPE */
			0x8,		/* FC_LONG */
/* 64 */	
			0x50,		/* FC_IN_OUT_PARAM */
#ifndef _ALPHA_
			0x1,		/* x86, MIPS & PPC Stack size = 1 */
#else
			0x2,		/* Alpha Stack size = 2 */
#endif
/* 66 */	NdrFcShort( 0x88 ),	/* Type Offset=136 */
/* 68 */	0x53,		/* FC_RETURN_PARAM_BASETYPE */
			0x8,		/* FC_LONG */
/* 70 */	
			0x4d,		/* FC_IN_PARAM */
#ifndef _ALPHA_
			0x1,		/* x86, MIPS & PPC Stack size = 1 */
#else
			0x2,		/* Alpha Stack size = 2 */
#endif
/* 72 */	NdrFcShort( 0x88 ),	/* Type Offset=136 */
/* 74 */	0x53,		/* FC_RETURN_PARAM_BASETYPE */
			0x8,		/* FC_LONG */
/* 76 */	
			0x51,		/* FC_OUT_PARAM */
#ifndef _ALPHA_
			0x1,		/* x86, MIPS & PPC Stack size = 1 */
#else
			0x2,		/* Alpha Stack size = 2 */
#endif
/* 78 */	NdrFcShort( 0xbc ),	/* Type Offset=188 */
/* 80 */	
			0x51,		/* FC_OUT_PARAM */
#ifndef _ALPHA_
			0x1,		/* x86, MIPS & PPC Stack size = 1 */
#else
			0x2,		/* Alpha Stack size = 2 */
#endif
/* 82 */	NdrFcShort( 0xca ),	/* Type Offset=202 */
/* 84 */	0x5b,		/* FC_END */
			0x5c,		/* FC_PAD */
/* 86 */	
			0x50,		/* FC_IN_OUT_PARAM */
#ifndef _ALPHA_
			0x1,		/* x86, MIPS & PPC Stack size = 1 */
#else
			0x2,		/* Alpha Stack size = 2 */
#endif
/* 88 */	NdrFcShort( 0x3e ),	/* Type Offset=62 */
/* 90 */	0x4e,		/* FC_IN_PARAM_BASETYPE */
			0x8,		/* FC_LONG */
/* 92 */	0x53,		/* FC_RETURN_PARAM_BASETYPE */
			0x8,		/* FC_LONG */
/* 94 */	
			0x4d,		/* FC_IN_PARAM */
#ifndef _ALPHA_
			0x1,		/* x86, MIPS & PPC Stack size = 1 */
#else
			0x2,		/* Alpha Stack size = 2 */
#endif
/* 96 */	NdrFcShort( 0xd8 ),	/* Type Offset=216 */
/* 98 */	
			0x51,		/* FC_OUT_PARAM */
#ifndef _ALPHA_
			0x1,		/* x86, MIPS & PPC Stack size = 1 */
#else
			0x2,		/* Alpha Stack size = 2 */
#endif
/* 100 */	NdrFcShort( 0xea ),	/* Type Offset=234 */
/* 102 */	0x4e,		/* FC_IN_PARAM_BASETYPE */
			0x8,		/* FC_LONG */
/* 104 */	0x53,		/* FC_RETURN_PARAM_BASETYPE */
			0x8,		/* FC_LONG */
/* 106 */	
			0x4d,		/* FC_IN_PARAM */
#ifndef _ALPHA_
			0x1,		/* x86, MIPS & PPC Stack size = 1 */
#else
			0x2,		/* Alpha Stack size = 2 */
#endif
/* 108 */	NdrFcShort( 0xd8 ),	/* Type Offset=216 */
/* 110 */	
			0x51,		/* FC_OUT_PARAM */
#ifndef _ALPHA_
			0x1,		/* x86, MIPS & PPC Stack size = 1 */
#else
			0x2,		/* Alpha Stack size = 2 */
#endif
/* 112 */	NdrFcShort( 0x102 ),	/* Type Offset=258 */
/* 114 */	0x4e,		/* FC_IN_PARAM_BASETYPE */
			0x8,		/* FC_LONG */
/* 116 */	0x53,		/* FC_RETURN_PARAM_BASETYPE */
			0x8,		/* FC_LONG */
/* 118 */	
			0x4d,		/* FC_IN_PARAM */
#ifndef _ALPHA_
			0x1,		/* x86, MIPS & PPC Stack size = 1 */
#else
			0x2,		/* Alpha Stack size = 2 */
#endif
/* 120 */	NdrFcShort( 0xd8 ),	/* Type Offset=216 */
/* 122 */	
			0x51,		/* FC_OUT_PARAM */
#ifndef _ALPHA_
			0x1,		/* x86, MIPS & PPC Stack size = 1 */
#else
			0x2,		/* Alpha Stack size = 2 */
#endif
/* 124 */	NdrFcShort( 0x11e ),	/* Type Offset=286 */
/* 126 */	0x4e,		/* FC_IN_PARAM_BASETYPE */
			0x8,		/* FC_LONG */
/* 128 */	0x53,		/* FC_RETURN_PARAM_BASETYPE */
			0x8,		/* FC_LONG */
/* 130 */	
			0x4d,		/* FC_IN_PARAM */
#ifndef _ALPHA_
			0x1,		/* x86, MIPS & PPC Stack size = 1 */
#else
			0x2,		/* Alpha Stack size = 2 */
#endif
/* 132 */	NdrFcShort( 0xd8 ),	/* Type Offset=216 */
/* 134 */	
			0x51,		/* FC_OUT_PARAM */
#ifndef _ALPHA_
			0x1,		/* x86, MIPS & PPC Stack size = 1 */
#else
			0x2,		/* Alpha Stack size = 2 */
#endif
/* 136 */	NdrFcShort( 0x138 ),	/* Type Offset=312 */
/* 138 */	0x4e,		/* FC_IN_PARAM_BASETYPE */
			0x8,		/* FC_LONG */
/* 140 */	0x53,		/* FC_RETURN_PARAM_BASETYPE */
			0x8,		/* FC_LONG */
/* 142 */	
			0x4d,		/* FC_IN_PARAM */
#ifndef _ALPHA_
			0x1,		/* x86, MIPS & PPC Stack size = 1 */
#else
			0x2,		/* Alpha Stack size = 2 */
#endif
/* 144 */	NdrFcShort( 0x48 ),	/* Type Offset=72 */
/* 146 */	
			0x4d,		/* FC_IN_PARAM */
#ifndef _ALPHA_
			0x1,		/* x86, MIPS & PPC Stack size = 1 */
#else
			0x2,		/* Alpha Stack size = 2 */
#endif
/* 148 */	NdrFcShort( 0x146 ),	/* Type Offset=326 */
/* 150 */	
			0x51,		/* FC_OUT_PARAM */
#ifndef _ALPHA_
			0x1,		/* x86, MIPS & PPC Stack size = 1 */
#else
			0x2,		/* Alpha Stack size = 2 */
#endif
/* 152 */	NdrFcShort( 0x150 ),	/* Type Offset=336 */
/* 154 */	0x4e,		/* FC_IN_PARAM_BASETYPE */
			0x8,		/* FC_LONG */
/* 156 */	0x53,		/* FC_RETURN_PARAM_BASETYPE */
			0x8,		/* FC_LONG */
/* 158 */	
			0x4d,		/* FC_IN_PARAM */
#ifndef _ALPHA_
			0x1,		/* x86, MIPS & PPC Stack size = 1 */
#else
			0x2,		/* Alpha Stack size = 2 */
#endif
/* 160 */	NdrFcShort( 0x48 ),	/* Type Offset=72 */
/* 162 */	
			0x4d,		/* FC_IN_PARAM */
#ifndef _ALPHA_
			0x1,		/* x86, MIPS & PPC Stack size = 1 */
#else
			0x2,		/* Alpha Stack size = 2 */
#endif
/* 164 */	NdrFcShort( 0x146 ),	/* Type Offset=326 */
/* 166 */	
			0x51,		/* FC_OUT_PARAM */
#ifndef _ALPHA_
			0x1,		/* x86, MIPS & PPC Stack size = 1 */
#else
			0x2,		/* Alpha Stack size = 2 */
#endif
/* 168 */	NdrFcShort( 0x15e ),	/* Type Offset=350 */
/* 170 */	0x4e,		/* FC_IN_PARAM_BASETYPE */
			0x8,		/* FC_LONG */
/* 172 */	0x53,		/* FC_RETURN_PARAM_BASETYPE */
			0x8,		/* FC_LONG */
/* 174 */	
			0x4d,		/* FC_IN_PARAM */
#ifndef _ALPHA_
			0x1,		/* x86, MIPS & PPC Stack size = 1 */
#else
			0x2,		/* Alpha Stack size = 2 */
#endif
/* 176 */	NdrFcShort( 0x48 ),	/* Type Offset=72 */
/* 178 */	
			0x4d,		/* FC_IN_PARAM */
#ifndef _ALPHA_
			0x1,		/* x86, MIPS & PPC Stack size = 1 */
#else
			0x2,		/* Alpha Stack size = 2 */
#endif
/* 180 */	NdrFcShort( 0x146 ),	/* Type Offset=326 */
/* 182 */	
			0x51,		/* FC_OUT_PARAM */
#ifndef _ALPHA_
			0x1,		/* x86, MIPS & PPC Stack size = 1 */
#else
			0x2,		/* Alpha Stack size = 2 */
#endif
/* 184 */	NdrFcShort( 0x16c ),	/* Type Offset=364 */
/* 186 */	0x4e,		/* FC_IN_PARAM_BASETYPE */
			0x8,		/* FC_LONG */
/* 188 */	0x53,		/* FC_RETURN_PARAM_BASETYPE */
			0x8,		/* FC_LONG */
/* 190 */	0x4e,		/* FC_IN_PARAM_BASETYPE */
			0x8,		/* FC_LONG */
/* 192 */	0x4e,		/* FC_IN_PARAM_BASETYPE */
			0xa,		/* FC_FLOAT */
/* 194 */	
			0x4d,		/* FC_IN_PARAM */
#ifndef _ALPHA_
			0x1,		/* x86, MIPS & PPC Stack size = 1 */
#else
			0x2,		/* Alpha Stack size = 2 */
#endif
/* 196 */	NdrFcShort( 0x48 ),	/* Type Offset=72 */
/* 198 */	0x5b,		/* FC_END */
			0x5c,		/* FC_PAD */
/* 200 */	0x4e,		/* FC_IN_PARAM_BASETYPE */
			0x8,		/* FC_LONG */
/* 202 */	
			0x4d,		/* FC_IN_PARAM */
#ifndef _ALPHA_
			0x1,		/* x86, MIPS & PPC Stack size = 1 */
#else
			0x2,		/* Alpha Stack size = 2 */
#endif
/* 204 */	NdrFcShort( 0x48 ),	/* Type Offset=72 */
/* 206 */	0x5b,		/* FC_END */
			0x5c,		/* FC_PAD */
/* 208 */	0x4e,		/* FC_IN_PARAM_BASETYPE */
			0x8,		/* FC_LONG */
/* 210 */	0x4e,		/* FC_IN_PARAM_BASETYPE */
			0x8,		/* FC_LONG */
/* 212 */	0x4e,		/* FC_IN_PARAM_BASETYPE */
			0x8,		/* FC_LONG */
/* 214 */	0x4e,		/* FC_IN_PARAM_BASETYPE */
			0x8,		/* FC_LONG */
/* 216 */	
			0x4d,		/* FC_IN_PARAM */
#ifndef _ALPHA_
			0x1,		/* x86, MIPS & PPC Stack size = 1 */
#else
			0x2,		/* Alpha Stack size = 2 */
#endif
/* 218 */	NdrFcShort( 0x48 ),	/* Type Offset=72 */
/* 220 */	0x5b,		/* FC_END */
			0x5c,		/* FC_PAD */
/* 222 */	
			0x4d,		/* FC_IN_PARAM */
#ifndef _ALPHA_
			0x1,		/* x86, MIPS & PPC Stack size = 1 */
#else
			0x2,		/* Alpha Stack size = 2 */
#endif
/* 224 */	NdrFcShort( 0x17a ),	/* Type Offset=378 */
/* 226 */	0x53,		/* FC_RETURN_PARAM_BASETYPE */
			0x8,		/* FC_LONG */
/* 228 */	
			0x51,		/* FC_OUT_PARAM */
#ifndef _ALPHA_
			0x1,		/* x86, MIPS & PPC Stack size = 1 */
#else
			0x2,		/* Alpha Stack size = 2 */
#endif
/* 230 */	NdrFcShort( 0x3e ),	/* Type Offset=62 */
/* 232 */	0x4e,		/* FC_IN_PARAM_BASETYPE */
			0x8,		/* FC_LONG */
/* 234 */	
			0x4d,		/* FC_IN_PARAM */
#ifndef _ALPHA_
			0x1,		/* x86, MIPS & PPC Stack size = 1 */
#else
			0x2,		/* Alpha Stack size = 2 */
#endif
/* 236 */	NdrFcShort( 0x17a ),	/* Type Offset=378 */
/* 238 */	0x53,		/* FC_RETURN_PARAM_BASETYPE */
			0x8,		/* FC_LONG */
/* 240 */	0x4e,		/* FC_IN_PARAM_BASETYPE */
			0x8,		/* FC_LONG */
/* 242 */	
			0x4d,		/* FC_IN_PARAM */
#ifndef _ALPHA_
			0x1,		/* x86, MIPS & PPC Stack size = 1 */
#else
			0x2,		/* Alpha Stack size = 2 */
#endif
/* 244 */	NdrFcShort( 0x17a ),	/* Type Offset=378 */
/* 246 */	0x53,		/* FC_RETURN_PARAM_BASETYPE */
			0x8,		/* FC_LONG */
/* 248 */	0x4e,		/* FC_IN_PARAM_BASETYPE */
			0x8,		/* FC_LONG */
/* 250 */	
			0x51,		/* FC_OUT_PARAM */
#ifndef _ALPHA_
			0x1,		/* x86, MIPS & PPC Stack size = 1 */
#else
			0x2,		/* Alpha Stack size = 2 */
#endif
/* 252 */	NdrFcShort( 0x17e ),	/* Type Offset=382 */
/* 254 */	0x4e,		/* FC_IN_PARAM_BASETYPE */
			0x8,		/* FC_LONG */
/* 256 */	
			0x4d,		/* FC_IN_PARAM */
#ifndef _ALPHA_
			0x1,		/* x86, MIPS & PPC Stack size = 1 */
#else
			0x2,		/* Alpha Stack size = 2 */
#endif
/* 258 */	NdrFcShort( 0x17a ),	/* Type Offset=378 */
/* 260 */	0x53,		/* FC_RETURN_PARAM_BASETYPE */
			0x8,		/* FC_LONG */
/* 262 */	
			0x4d,		/* FC_IN_PARAM */
#ifndef _ALPHA_
			0x1,		/* x86, MIPS & PPC Stack size = 1 */
#else
			0x2,		/* Alpha Stack size = 2 */
#endif
/* 264 */	NdrFcShort( 0x188 ),	/* Type Offset=392 */
/* 266 */	
			0x51,		/* FC_OUT_PARAM */
#ifndef _ALPHA_
			0x1,		/* x86, MIPS & PPC Stack size = 1 */
#else
			0x2,		/* Alpha Stack size = 2 */
#endif
/* 268 */	NdrFcShort( 0x192 ),	/* Type Offset=402 */
/* 270 */	0x53,		/* FC_RETURN_PARAM_BASETYPE */
			0xa,		/* FC_FLOAT */
/* 272 */	0x4e,		/* FC_IN_PARAM_BASETYPE */
			0x8,		/* FC_LONG */
/* 274 */	
			0x4d,		/* FC_IN_PARAM */
#ifndef _ALPHA_
			0x1,		/* x86, MIPS & PPC Stack size = 1 */
#else
			0x2,		/* Alpha Stack size = 2 */
#endif
/* 276 */	NdrFcShort( 0x48 ),	/* Type Offset=72 */
/* 278 */	
			0x4d,		/* FC_IN_PARAM */
#ifndef _ALPHA_
			0x1,		/* x86, MIPS & PPC Stack size = 1 */
#else
			0x2,		/* Alpha Stack size = 2 */
#endif
/* 280 */	NdrFcShort( 0x48 ),	/* Type Offset=72 */
/* 282 */	0x53,		/* FC_RETURN_PARAM_BASETYPE */
			0x8,		/* FC_LONG */
/* 284 */	0x4e,		/* FC_IN_PARAM_BASETYPE */
			0x8,		/* FC_LONG */
/* 286 */	
			0x4d,		/* FC_IN_PARAM */
#ifndef _ALPHA_
			0x1,		/* x86, MIPS & PPC Stack size = 1 */
#else
			0x2,		/* Alpha Stack size = 2 */
#endif
/* 288 */	NdrFcShort( 0x48 ),	/* Type Offset=72 */
/* 290 */	
			0x4d,		/* FC_IN_PARAM */
#ifndef _ALPHA_
			0x1,		/* x86, MIPS & PPC Stack size = 1 */
#else
			0x2,		/* Alpha Stack size = 2 */
#endif
/* 292 */	NdrFcShort( 0x48 ),	/* Type Offset=72 */
/* 294 */	
			0x51,		/* FC_OUT_PARAM */
#ifndef _ALPHA_
			0x1,		/* x86, MIPS & PPC Stack size = 1 */
#else
			0x2,		/* Alpha Stack size = 2 */
#endif
/* 296 */	NdrFcShort( 0x1a4 ),	/* Type Offset=420 */
/* 298 */	0x4e,		/* FC_IN_PARAM_BASETYPE */
			0x8,		/* FC_LONG */
/* 300 */	0x53,		/* FC_RETURN_PARAM_BASETYPE */
			0x8,		/* FC_LONG */
/* 302 */	
			0x4d,		/* FC_IN_PARAM */
#ifndef _ALPHA_
			0x1,		/* x86, MIPS & PPC Stack size = 1 */
#else
			0x2,		/* Alpha Stack size = 2 */
#endif
/* 304 */	NdrFcShort( 0x48 ),	/* Type Offset=72 */
/* 306 */	
			0x4d,		/* FC_IN_PARAM */
#ifndef _ALPHA_
			0x1,		/* x86, MIPS & PPC Stack size = 1 */
#else
			0x2,		/* Alpha Stack size = 2 */
#endif
/* 308 */	NdrFcShort( 0x48 ),	/* Type Offset=72 */
/* 310 */	0x53,		/* FC_RETURN_PARAM_BASETYPE */
			0x8,		/* FC_LONG */
/* 312 */	
			0x4d,		/* FC_IN_PARAM */
#ifndef _ALPHA_
			0x1,		/* x86, MIPS & PPC Stack size = 1 */
#else
			0x2,		/* Alpha Stack size = 2 */
#endif
/* 314 */	NdrFcShort( 0x48 ),	/* Type Offset=72 */
/* 316 */	0x53,		/* FC_RETURN_PARAM_BASETYPE */
			0x8,		/* FC_LONG */
/* 318 */	0x4e,		/* FC_IN_PARAM_BASETYPE */
			0x8,		/* FC_LONG */
/* 320 */	
			0x4d,		/* FC_IN_PARAM */
#ifndef _ALPHA_
			0x1,		/* x86, MIPS & PPC Stack size = 1 */
#else
			0x2,		/* Alpha Stack size = 2 */
#endif
/* 322 */	NdrFcShort( 0x48 ),	/* Type Offset=72 */
/* 324 */	0x53,		/* FC_RETURN_PARAM_BASETYPE */
			0x8,		/* FC_LONG */
/* 326 */	
			0x4d,		/* FC_IN_PARAM */
#ifndef _ALPHA_
			0x1,		/* x86, MIPS & PPC Stack size = 1 */
#else
			0x2,		/* Alpha Stack size = 2 */
#endif
/* 328 */	NdrFcShort( 0x48 ),	/* Type Offset=72 */
/* 330 */	0x4e,		/* FC_IN_PARAM_BASETYPE */
			0x8,		/* FC_LONG */
/* 332 */	
			0x51,		/* FC_OUT_PARAM */
#ifndef _ALPHA_
			0x1,		/* x86, MIPS & PPC Stack size = 1 */
#else
			0x2,		/* Alpha Stack size = 2 */
#endif
/* 334 */	NdrFcShort( 0x192 ),	/* Type Offset=402 */
/* 336 */	0x53,		/* FC_RETURN_PARAM_BASETYPE */
			0x8,		/* FC_LONG */
/* 338 */	
			0x4d,		/* FC_IN_PARAM */
#ifndef _ALPHA_
			0x1,		/* x86, MIPS & PPC Stack size = 1 */
#else
			0x2,		/* Alpha Stack size = 2 */
#endif
/* 340 */	NdrFcShort( 0x48 ),	/* Type Offset=72 */
/* 342 */	0x4e,		/* FC_IN_PARAM_BASETYPE */
			0x8,		/* FC_LONG */
/* 344 */	
			0x51,		/* FC_OUT_PARAM */
#ifndef _ALPHA_
			0x1,		/* x86, MIPS & PPC Stack size = 1 */
#else
			0x2,		/* Alpha Stack size = 2 */
#endif
/* 346 */	NdrFcShort( 0x146 ),	/* Type Offset=326 */
/* 348 */	0x4e,		/* FC_IN_PARAM_BASETYPE */
			0x8,		/* FC_LONG */
/* 350 */	0x53,		/* FC_RETURN_PARAM_BASETYPE */
			0x8,		/* FC_LONG */
/* 352 */	
			0x4d,		/* FC_IN_PARAM */
#ifndef _ALPHA_
			0x1,		/* x86, MIPS & PPC Stack size = 1 */
#else
			0x2,		/* Alpha Stack size = 2 */
#endif
/* 354 */	NdrFcShort( 0x48 ),	/* Type Offset=72 */
/* 356 */	0x4e,		/* FC_IN_PARAM_BASETYPE */
			0x8,		/* FC_LONG */
/* 358 */	0x4e,		/* FC_IN_PARAM_BASETYPE */
			0x8,		/* FC_LONG */
/* 360 */	
			0x51,		/* FC_OUT_PARAM */
#ifndef _ALPHA_
			0x1,		/* x86, MIPS & PPC Stack size = 1 */
#else
			0x2,		/* Alpha Stack size = 2 */
#endif
/* 362 */	NdrFcShort( 0x1b2 ),	/* Type Offset=434 */
/* 364 */	
			0x51,		/* FC_OUT_PARAM */
#ifndef _ALPHA_
			0x1,		/* x86, MIPS & PPC Stack size = 1 */
#else
			0x2,		/* Alpha Stack size = 2 */
#endif
/* 366 */	NdrFcShort( 0x1bc ),	/* Type Offset=444 */
/* 368 */	0x4e,		/* FC_IN_PARAM_BASETYPE */
			0x8,		/* FC_LONG */
/* 370 */	0x53,		/* FC_RETURN_PARAM_BASETYPE */
			0x8,		/* FC_LONG */
/* 372 */	0x4e,		/* FC_IN_PARAM_BASETYPE */
			0x8,		/* FC_LONG */
/* 374 */	
			0x51,		/* FC_OUT_PARAM */
#ifndef _ALPHA_
			0x1,		/* x86, MIPS & PPC Stack size = 1 */
#else
			0x2,		/* Alpha Stack size = 2 */
#endif
/* 376 */	NdrFcShort( 0x1c6 ),	/* Type Offset=454 */
/* 378 */	0x4e,		/* FC_IN_PARAM_BASETYPE */
			0x8,		/* FC_LONG */
/* 380 */	0x53,		/* FC_RETURN_PARAM_BASETYPE */
			0x8,		/* FC_LONG */
/* 382 */	0x4e,		/* FC_IN_PARAM_BASETYPE */
			0x8,		/* FC_LONG */
/* 384 */	
			0x4d,		/* FC_IN_PARAM */
#ifndef _ALPHA_
			0x1,		/* x86, MIPS & PPC Stack size = 1 */
#else
			0x2,		/* Alpha Stack size = 2 */
#endif
/* 386 */	NdrFcShort( 0x1c6 ),	/* Type Offset=454 */
/* 388 */	0x4e,		/* FC_IN_PARAM_BASETYPE */
			0x8,		/* FC_LONG */
/* 390 */	0x53,		/* FC_RETURN_PARAM_BASETYPE */
			0x8,		/* FC_LONG */
/* 392 */	
			0x51,		/* FC_OUT_PARAM */
#ifndef _ALPHA_
			0x1,		/* x86, MIPS & PPC Stack size = 1 */
#else
			0x2,		/* Alpha Stack size = 2 */
#endif
/* 394 */	NdrFcShort( 0x1d0 ),	/* Type Offset=464 */
/* 396 */	0x4e,		/* FC_IN_PARAM_BASETYPE */
			0x8,		/* FC_LONG */
/* 398 */	0x53,		/* FC_RETURN_PARAM_BASETYPE */
			0x8,		/* FC_LONG */
/* 400 */	
			0x4d,		/* FC_IN_PARAM */
#ifndef _ALPHA_
			0x1,		/* x86, MIPS & PPC Stack size = 1 */
#else
			0x2,		/* Alpha Stack size = 2 */
#endif
/* 402 */	NdrFcShort( 0x3e ),	/* Type Offset=62 */
/* 404 */	0x4e,		/* FC_IN_PARAM_BASETYPE */
			0x8,		/* FC_LONG */
/* 406 */	0x53,		/* FC_RETURN_PARAM_BASETYPE */
			0x8,		/* FC_LONG */

			0x0
        }
    };

static const MIDL_TYPE_FORMAT_STRING __MIDL_TypeFormatString =
    {
        0,
        {
			NdrFcShort( 0x0 ),	/* 0 */
/*  2 */	
			0x1d,		/* FC_SMFARRAY */
			0x0,		/* 0 */
/*  4 */	NdrFcShort( 0x50 ),	/* 80 */
/*  6 */	0x2,		/* FC_CHAR */
			0x5b,		/* FC_END */
/*  8 */	
			0x15,		/* FC_STRUCT */
			0x1,		/* 1 */
/* 10 */	NdrFcShort( 0x4 ),	/* 4 */
/* 12 */	0x6,		/* FC_SHORT */
			0x2,		/* FC_CHAR */
/* 14 */	0x2,		/* FC_CHAR */
			0x5b,		/* FC_END */
/* 16 */	
			0x15,		/* FC_STRUCT */
			0x0,		/* 0 */
/* 18 */	NdrFcShort( 0x4 ),	/* 4 */
/* 20 */	0x2,		/* FC_CHAR */
			0x2,		/* FC_CHAR */
/* 22 */	0x2,		/* FC_CHAR */
			0x2,		/* FC_CHAR */
/* 24 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 26 */	
			0x15,		/* FC_STRUCT */
			0x3,		/* 3 */
/* 28 */	NdrFcShort( 0x5c ),	/* 92 */
/* 30 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 32 */	NdrFcShort( 0xffffffe2 ),	/* Offset= -30 (2) */
/* 34 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 36 */	NdrFcShort( 0xffffffe4 ),	/* Offset= -28 (8) */
/* 38 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 40 */	NdrFcShort( 0xffffffe8 ),	/* Offset= -24 (16) */
/* 42 */	0x8,		/* FC_LONG */
			0x5b,		/* FC_END */
/* 44 */	
			0x1b,		/* FC_CARRAY */
			0x3,		/* 3 */
/* 46 */	NdrFcShort( 0x5c ),	/* 92 */
/* 48 */	0x28,		/* Corr desc:  parameter, FC_LONG */
			0x0,		/*  */
#ifndef _ALPHA_
/* 50 */	NdrFcShort( 0x4 ),	/* x86, MIPS, PPC Stack size/offset = 4 */
#else
			NdrFcShort( 0x8 ),	/* Alpha Stack size/offset = 8 */
#endif
/* 52 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 54 */	NdrFcShort( 0xffffffe4 ),	/* Offset= -28 (26) */
/* 56 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 58 */	
			0x11, 0x0,	/* FC_RP */
/* 60 */	NdrFcShort( 0xffffffde ),	/* Offset= -34 (26) */
/* 62 */	
			0x1b,		/* FC_CARRAY */
			0x0,		/* 0 */
/* 64 */	NdrFcShort( 0x1 ),	/* 1 */
/* 66 */	0x28,		/* Corr desc:  parameter, FC_LONG */
			0x0,		/*  */
#ifndef _ALPHA_
/* 68 */	NdrFcShort( 0x4 ),	/* x86, MIPS, PPC Stack size/offset = 4 */
#else
			NdrFcShort( 0x8 ),	/* Alpha Stack size/offset = 8 */
#endif
/* 70 */	0x2,		/* FC_CHAR */
			0x5b,		/* FC_END */
/* 72 */	
			0x11, 0x8,	/* FC_RP [simple_pointer] */
/* 74 */	
			0x22,		/* FC_C_CSTRING */
			0x5c,		/* FC_PAD */
/* 76 */	
			0x11, 0x0,	/* FC_RP */
/* 78 */	NdrFcShort( 0x2c ),	/* Offset= 44 (122) */
/* 80 */	
			0x1d,		/* FC_SMFARRAY */
			0x0,		/* 0 */
/* 82 */	NdrFcShort( 0x10 ),	/* 16 */
/* 84 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 86 */	NdrFcShort( 0xffffffba ),	/* Offset= -70 (16) */
/* 88 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 90 */	
			0x15,		/* FC_STRUCT */
			0x1,		/* 1 */
/* 92 */	NdrFcShort( 0xd4 ),	/* 212 */
/* 94 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 96 */	NdrFcShort( 0xffffffa2 ),	/* Offset= -94 (2) */
/* 98 */	0x6,		/* FC_SHORT */
			0x6,		/* FC_SHORT */
/* 100 */	0x6,		/* FC_SHORT */
			0x6,		/* FC_SHORT */
/* 102 */	0x6,		/* FC_SHORT */
			0x6,		/* FC_SHORT */
/* 104 */	0x6,		/* FC_SHORT */
			0x6,		/* FC_SHORT */
/* 106 */	0x6,		/* FC_SHORT */
			0x6,		/* FC_SHORT */
/* 108 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 110 */	NdrFcShort( 0xffffffe2 ),	/* Offset= -30 (80) */
/* 112 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 114 */	NdrFcShort( 0xffffffde ),	/* Offset= -34 (80) */
/* 116 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 118 */	NdrFcShort( 0xffffff8c ),	/* Offset= -116 (2) */
/* 120 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 122 */	
			0x1b,		/* FC_CARRAY */
			0x1,		/* 1 */
/* 124 */	NdrFcShort( 0xd4 ),	/* 212 */
/* 126 */	0x40,		/* Corr desc:  constant, val=256 */
			0x0,		/* 0 */
/* 128 */	NdrFcShort( 0x1 ),	/* 1 */
/* 130 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 132 */	NdrFcShort( 0xffffffd6 ),	/* Offset= -42 (90) */
/* 134 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 136 */	
			0x11, 0x0,	/* FC_RP */
/* 138 */	NdrFcShort( 0x24 ),	/* Offset= 36 (174) */
/* 140 */	
			0x1d,		/* FC_SMFARRAY */
			0x0,		/* 0 */
/* 142 */	NdrFcShort( 0x10 ),	/* 16 */
/* 144 */	0x2,		/* FC_CHAR */
			0x5b,		/* FC_END */
/* 146 */	
			0x1d,		/* FC_SMFARRAY */
			0x0,		/* 0 */
/* 148 */	NdrFcShort( 0x14 ),	/* 20 */
/* 150 */	0x2,		/* FC_CHAR */
			0x5b,		/* FC_END */
/* 152 */	
			0x15,		/* FC_STRUCT */
			0x3,		/* 3 */
/* 154 */	NdrFcShort( 0x50 ),	/* 80 */
/* 156 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 158 */	NdrFcShort( 0xffffffee ),	/* Offset= -18 (140) */
/* 160 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 162 */	NdrFcShort( 0xfffffff0 ),	/* Offset= -16 (146) */
/* 164 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 166 */	NdrFcShort( 0xffffffec ),	/* Offset= -20 (146) */
/* 168 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 170 */	NdrFcShort( 0xffffffe8 ),	/* Offset= -24 (146) */
/* 172 */	0x8,		/* FC_LONG */
			0x5b,		/* FC_END */
/* 174 */	
			0x1b,		/* FC_CARRAY */
			0x3,		/* 3 */
/* 176 */	NdrFcShort( 0x50 ),	/* 80 */
/* 178 */	0x40,		/* Corr desc:  constant, val=256 */
			0x0,		/* 0 */
/* 180 */	NdrFcShort( 0x1 ),	/* 1 */
/* 182 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 184 */	NdrFcShort( 0xffffffe0 ),	/* Offset= -32 (152) */
/* 186 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 188 */	
			0x1b,		/* FC_CARRAY */
			0x1,		/* 1 */
/* 190 */	NdrFcShort( 0x4 ),	/* 4 */
/* 192 */	0x40,		/* Corr desc:  constant, val=256 */
			0x0,		/* 0 */
/* 194 */	NdrFcShort( 0x1 ),	/* 1 */
/* 196 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 198 */	NdrFcShort( 0xffffff42 ),	/* Offset= -190 (8) */
/* 200 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 202 */	
			0x1b,		/* FC_CARRAY */
			0x0,		/* 0 */
/* 204 */	NdrFcShort( 0x4 ),	/* 4 */
/* 206 */	0x40,		/* Corr desc:  constant, val=256 */
			0x0,		/* 0 */
/* 208 */	NdrFcShort( 0x1 ),	/* 1 */
/* 210 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 212 */	NdrFcShort( 0xffffff3c ),	/* Offset= -196 (16) */
/* 214 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 216 */	
			0x1b,		/* FC_CARRAY */
			0x3,		/* 3 */
/* 218 */	NdrFcShort( 0x4 ),	/* 4 */
/* 220 */	0x28,		/* Corr desc:  parameter, FC_LONG */
			0x0,		/*  */
#ifndef _ALPHA_
/* 222 */	NdrFcShort( 0x8 ),	/* x86, MIPS, PPC Stack size/offset = 8 */
#else
			NdrFcShort( 0x10 ),	/* Alpha Stack size/offset = 16 */
#endif
/* 224 */	0x8,		/* FC_LONG */
			0x5b,		/* FC_END */
/* 226 */	
			0x15,		/* FC_STRUCT */
			0x3,		/* 3 */
/* 228 */	NdrFcShort( 0x8 ),	/* 8 */
/* 230 */	0x6,		/* FC_SHORT */
			0x6,		/* FC_SHORT */
/* 232 */	0xa,		/* FC_FLOAT */
			0x5b,		/* FC_END */
/* 234 */	
			0x1b,		/* FC_CARRAY */
			0x3,		/* 3 */
/* 236 */	NdrFcShort( 0x8 ),	/* 8 */
/* 238 */	0x28,		/* Corr desc:  parameter, FC_LONG */
			0x0,		/*  */
#ifndef _ALPHA_
/* 240 */	NdrFcShort( 0x8 ),	/* x86, MIPS, PPC Stack size/offset = 8 */
#else
			NdrFcShort( 0x10 ),	/* Alpha Stack size/offset = 16 */
#endif
/* 242 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 244 */	NdrFcShort( 0xffffffee ),	/* Offset= -18 (226) */
/* 246 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 248 */	
			0x15,		/* FC_STRUCT */
			0x1,		/* 1 */
/* 250 */	NdrFcShort( 0x8 ),	/* 8 */
/* 252 */	0x6,		/* FC_SHORT */
			0x6,		/* FC_SHORT */
/* 254 */	0x6,		/* FC_SHORT */
			0x6,		/* FC_SHORT */
/* 256 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 258 */	
			0x1b,		/* FC_CARRAY */
			0x1,		/* 1 */
/* 260 */	NdrFcShort( 0x8 ),	/* 8 */
/* 262 */	0x28,		/* Corr desc:  parameter, FC_LONG */
			0x0,		/*  */
#ifndef _ALPHA_
/* 264 */	NdrFcShort( 0x8 ),	/* x86, MIPS, PPC Stack size/offset = 8 */
#else
			NdrFcShort( 0x10 ),	/* Alpha Stack size/offset = 16 */
#endif
/* 266 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 268 */	NdrFcShort( 0xffffffec ),	/* Offset= -20 (248) */
/* 270 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 272 */	
			0x15,		/* FC_STRUCT */
			0x3,		/* 3 */
/* 274 */	NdrFcShort( 0x20 ),	/* 32 */
/* 276 */	0x6,		/* FC_SHORT */
			0x6,		/* FC_SHORT */
/* 278 */	0xa,		/* FC_FLOAT */
			0xa,		/* FC_FLOAT */
/* 280 */	0xa,		/* FC_FLOAT */
			0x8,		/* FC_LONG */
/* 282 */	0x8,		/* FC_LONG */
			0xa,		/* FC_FLOAT */
/* 284 */	0xa,		/* FC_FLOAT */
			0x5b,		/* FC_END */
/* 286 */	
			0x1b,		/* FC_CARRAY */
			0x3,		/* 3 */
/* 288 */	NdrFcShort( 0x20 ),	/* 32 */
/* 290 */	0x28,		/* Corr desc:  parameter, FC_LONG */
			0x0,		/*  */
#ifndef _ALPHA_
/* 292 */	NdrFcShort( 0x8 ),	/* x86, MIPS, PPC Stack size/offset = 8 */
#else
			NdrFcShort( 0x10 ),	/* Alpha Stack size/offset = 16 */
#endif
/* 294 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 296 */	NdrFcShort( 0xffffffe8 ),	/* Offset= -24 (272) */
/* 298 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 300 */	
			0x15,		/* FC_STRUCT */
			0x3,		/* 3 */
/* 302 */	NdrFcShort( 0x18 ),	/* 24 */
/* 304 */	0x6,		/* FC_SHORT */
			0x6,		/* FC_SHORT */
/* 306 */	0xa,		/* FC_FLOAT */
			0xa,		/* FC_FLOAT */
/* 308 */	0xa,		/* FC_FLOAT */
			0xa,		/* FC_FLOAT */
/* 310 */	0xa,		/* FC_FLOAT */
			0x5b,		/* FC_END */
/* 312 */	
			0x1b,		/* FC_CARRAY */
			0x3,		/* 3 */
/* 314 */	NdrFcShort( 0x18 ),	/* 24 */
/* 316 */	0x28,		/* Corr desc:  parameter, FC_LONG */
			0x0,		/*  */
#ifndef _ALPHA_
/* 318 */	NdrFcShort( 0x8 ),	/* x86, MIPS, PPC Stack size/offset = 8 */
#else
			NdrFcShort( 0x10 ),	/* Alpha Stack size/offset = 16 */
#endif
/* 320 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 322 */	NdrFcShort( 0xffffffea ),	/* Offset= -22 (300) */
/* 324 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 326 */	
			0x1b,		/* FC_CARRAY */
			0x3,		/* 3 */
/* 328 */	NdrFcShort( 0x4 ),	/* 4 */
/* 330 */	0x28,		/* Corr desc:  parameter, FC_LONG */
			0x0,		/*  */
#ifndef _ALPHA_
/* 332 */	NdrFcShort( 0xc ),	/* x86, MIPS, PPC Stack size/offset = 12 */
#else
			NdrFcShort( 0x18 ),	/* Alpha Stack size/offset = 24 */
#endif
/* 334 */	0x8,		/* FC_LONG */
			0x5b,		/* FC_END */
/* 336 */	
			0x1b,		/* FC_CARRAY */
			0x1,		/* 1 */
/* 338 */	NdrFcShort( 0x8 ),	/* 8 */
/* 340 */	0x28,		/* Corr desc:  parameter, FC_LONG */
			0x0,		/*  */
#ifndef _ALPHA_
/* 342 */	NdrFcShort( 0xc ),	/* x86, MIPS, PPC Stack size/offset = 12 */
#else
			NdrFcShort( 0x18 ),	/* Alpha Stack size/offset = 24 */
#endif
/* 344 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 346 */	NdrFcShort( 0xffffff9e ),	/* Offset= -98 (248) */
/* 348 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 350 */	
			0x1b,		/* FC_CARRAY */
			0x3,		/* 3 */
/* 352 */	NdrFcShort( 0x20 ),	/* 32 */
/* 354 */	0x28,		/* Corr desc:  parameter, FC_LONG */
			0x0,		/*  */
#ifndef _ALPHA_
/* 356 */	NdrFcShort( 0xc ),	/* x86, MIPS, PPC Stack size/offset = 12 */
#else
			NdrFcShort( 0x18 ),	/* Alpha Stack size/offset = 24 */
#endif
/* 358 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 360 */	NdrFcShort( 0xffffffa8 ),	/* Offset= -88 (272) */
/* 362 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 364 */	
			0x1b,		/* FC_CARRAY */
			0x3,		/* 3 */
/* 366 */	NdrFcShort( 0x18 ),	/* 24 */
/* 368 */	0x28,		/* Corr desc:  parameter, FC_LONG */
			0x0,		/*  */
#ifndef _ALPHA_
/* 370 */	NdrFcShort( 0xc ),	/* x86, MIPS, PPC Stack size/offset = 12 */
#else
			NdrFcShort( 0x18 ),	/* Alpha Stack size/offset = 24 */
#endif
/* 372 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 374 */	NdrFcShort( 0xffffffb6 ),	/* Offset= -74 (300) */
/* 376 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 378 */	
			0x11, 0x0,	/* FC_RP */
/* 380 */	NdrFcShort( 0xfffffe8c ),	/* Offset= -372 (8) */
/* 382 */	
			0x1b,		/* FC_CARRAY */
			0x0,		/* 0 */
/* 384 */	NdrFcShort( 0x1 ),	/* 1 */
/* 386 */	0x28,		/* Corr desc:  parameter, FC_LONG */
			0x0,		/*  */
#ifndef _ALPHA_
/* 388 */	NdrFcShort( 0x8 ),	/* x86, MIPS, PPC Stack size/offset = 8 */
#else
			NdrFcShort( 0x10 ),	/* Alpha Stack size/offset = 16 */
#endif
/* 390 */	0x2,		/* FC_CHAR */
			0x5b,		/* FC_END */
/* 392 */	
			0x1b,		/* FC_CARRAY */
			0x0,		/* 0 */
/* 394 */	NdrFcShort( 0x1 ),	/* 1 */
/* 396 */	0x40,		/* Corr desc:  constant, val=20992 */
			0x0,		/* 0 */
/* 398 */	NdrFcShort( 0x52 ),	/* 82 */
/* 400 */	0x2,		/* FC_CHAR */
			0x5b,		/* FC_END */
/* 402 */	
			0x11, 0xc,	/* FC_RP [alloced_on_stack] [simple_pointer] */
/* 404 */	0x8,		/* FC_LONG */
			0x5c,		/* FC_PAD */
/* 406 */	
			0x15,		/* FC_STRUCT */
			0x3,		/* 3 */
/* 408 */	NdrFcShort( 0xe ),	/* 14 */
/* 410 */	0x6,		/* FC_SHORT */
			0x2,		/* FC_CHAR */
/* 412 */	0x2,		/* FC_CHAR */
			0x2,		/* FC_CHAR */
/* 414 */	0x2,		/* FC_CHAR */
			0x2,		/* FC_CHAR */
/* 416 */	0x2,		/* FC_CHAR */
			0xa,		/* FC_FLOAT */
/* 418 */	0x6,		/* FC_SHORT */
			0x5b,		/* FC_END */
/* 420 */	
			0x1b,		/* FC_CARRAY */
			0x3,		/* 3 */
/* 422 */	NdrFcShort( 0xe ),	/* 14 */
/* 424 */	0x28,		/* Corr desc:  parameter, FC_LONG */
			0x0,		/*  */
#ifndef _ALPHA_
/* 426 */	NdrFcShort( 0x10 ),	/* x86, MIPS, PPC Stack size/offset = 16 */
#else
			NdrFcShort( 0x20 ),	/* Alpha Stack size/offset = 32 */
#endif
/* 428 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 430 */	NdrFcShort( 0xffffffe8 ),	/* Offset= -24 (406) */
/* 432 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 434 */	
			0x1b,		/* FC_CARRAY */
			0x3,		/* 3 */
/* 436 */	NdrFcShort( 0x4 ),	/* 4 */
/* 438 */	0x28,		/* Corr desc:  parameter, FC_LONG */
			0x0,		/*  */
#ifndef _ALPHA_
/* 440 */	NdrFcShort( 0x14 ),	/* x86, MIPS, PPC Stack size/offset = 20 */
#else
			NdrFcShort( 0x28 ),	/* Alpha Stack size/offset = 40 */
#endif
/* 442 */	0xa,		/* FC_FLOAT */
			0x5b,		/* FC_END */
/* 444 */	
			0x1b,		/* FC_CARRAY */
			0x3,		/* 3 */
/* 446 */	NdrFcShort( 0x4 ),	/* 4 */
/* 448 */	0x28,		/* Corr desc:  parameter, FC_LONG */
			0x0,		/*  */
#ifndef _ALPHA_
/* 450 */	NdrFcShort( 0x14 ),	/* x86, MIPS, PPC Stack size/offset = 20 */
#else
			NdrFcShort( 0x28 ),	/* Alpha Stack size/offset = 40 */
#endif
/* 452 */	0x8,		/* FC_LONG */
			0x5b,		/* FC_END */
/* 454 */	
			0x1b,		/* FC_CARRAY */
			0x3,		/* 3 */
/* 456 */	NdrFcShort( 0x4 ),	/* 4 */
/* 458 */	0x28,		/* Corr desc:  parameter, FC_LONG */
			0x0,		/*  */
#ifndef _ALPHA_
/* 460 */	NdrFcShort( 0x8 ),	/* x86, MIPS, PPC Stack size/offset = 8 */
#else
			NdrFcShort( 0x10 ),	/* Alpha Stack size/offset = 16 */
#endif
/* 462 */	0xa,		/* FC_FLOAT */
			0x5b,		/* FC_END */
/* 464 */	
			0x1b,		/* FC_CARRAY */
			0x3,		/* 3 */
/* 466 */	NdrFcShort( 0x50 ),	/* 80 */
/* 468 */	0x28,		/* Corr desc:  parameter, FC_LONG */
			0x0,		/*  */
#ifndef _ALPHA_
/* 470 */	NdrFcShort( 0x4 ),	/* x86, MIPS, PPC Stack size/offset = 4 */
#else
			NdrFcShort( 0x8 ),	/* Alpha Stack size/offset = 8 */
#endif
/* 472 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 474 */	NdrFcShort( 0xfffffebe ),	/* Offset= -322 (152) */
/* 476 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */

			0x0
        }
    };
