/* this ALWAYS GENERATED file contains the definitions for the interfaces */


/* File created by MIDL compiler version 5.01.0164 */
/* at Tue Jul 31 11:34:59 2018
 */
/* Compiler settings for .\PANSI.IDL:
    Os (OptLev=s), W1, Zp1, env=Win32, ms_ext, c_ext, oldnames
    error checks: allocation ref bounds_check enum stub_data 
*/
//@@MIDL_FILE_HEADING(  )


/* verify that the <rpcndr.h> version is high enough to compile this file*/
#ifndef __REQUIRED_RPCNDR_H_VERSION__
#define __REQUIRED_RPCNDR_H_VERSION__ 440
#endif

#include "rpc.h"
#include "rpcndr.h"

#ifndef __PANSI_h__
#define __PANSI_h__

#ifdef __cplusplus
extern "C"{
#endif 

/* Forward Declarations */ 

void __RPC_FAR * __RPC_USER MIDL_user_allocate(size_t);
void __RPC_USER MIDL_user_free( void __RPC_FAR * ); 

#ifndef __pansi_INTERFACE_DEFINED__
#define __pansi_INTERFACE_DEFINED__

/* interface pansi */
/* [implicit_handle][unique][version][uuid] */ 

#define	DEFAULT_ENDPOINT	( "9999" )

#define	DEFAULT_PROT_SEQ	( "ncacn_ip_tcp" )

#define	PS_MAXFILENAME	( 80 )

#define	MAXCOMPUTERNAME	( 16 )

#define	MAXUSERNAME	( 20 )

#define	MAXPASSWORD	( 20 )

#define	MAXSYSTEMNAME	( 80 )

#define	MAXSTATIONNAME	( 21 )

#define	MAXPOINTNAME	( 41 )

#define	MAXUNITNAME	( 11 )

#define	MAXEXPRESSION	( 80 )

#define	MAXNUMPARAM	( MAXEXPRESSION / 4 )

#define	MAXEVENTNOTE	( 21 )


enum __MIDL_pansi_0001
    {	URERROR_TOMANYUSER	= -1,
	URERROR_SAMECOMPUTER	= -2,
	URERROR_SAMEUSERNAME	= -3,
	URERROR_USERCANCELED	= -4,
	URERROR_PASSWORD	= -5,
	URERROR_PROHIBITED	= -6,
	URERROR_NETWORK	= -20
    };

enum __MIDL_pansi_0002
    {	EXPRERROR_NONE	= 0,
	EXPRERROR_NOEXPRESSION	= EXPRERROR_NONE + 1,
	EXPRERROR_VARIABLE	= EXPRERROR_NOEXPRESSION + 1,
	EXPRERROR_SYNTAX	= EXPRERROR_VARIABLE + 1,
	EXPRERROR_PARENTHESES	= EXPRERROR_SYNTAX + 1,
	EXPRERROR_OVERFLOW	= EXPRERROR_PARENTHESES + 1,
	NUM_EXPRERROR	= EXPRERROR_OVERFLOW + 1
    };

enum __MIDL_pansi_0003
    {	USERPRIORITY_NONE	= 0,
	USERPRIORITY_SYSPARAMS	= 0x8,
	USERPRIORITY_VDT	= 0x1,
	USERPRIORITY_USERLIST	= 0x10,
	USERPRIORITY_DADABASE	= 0x4,
	USERPRIORITY_PAGE	= 0x20,
	USERPRIORITY_PLAN	= 0x40,
	USERPRIORITY_OPERATION	= 0x2,
	USERPRIORITY_CONTROL	= 0x80,
	USERPRIORITY_ALL	= 0xfff
    };

enum __MIDL_pansi_0004
    {	VARTYPE_NONE	= -1,
	VARTYPE_YX	= 0,
	VARTYPE_YC	= VARTYPE_YX + 1,
	VARTYPE_YD	= VARTYPE_YC + 1,
	NUM_VARTYPE	= VARTYPE_YD + 1,
	VARTYPE_YT	= VARTYPE_YD + 1,
	NUM_VARTYPE_EX	= VARTYPE_YT + 1
    };

enum __MIDL_pansi_0005
    {	VARTYPEX_NONE	= 0,
	YXTYPEX_ALARMCOUNT	= 1,
	NUM_YXTYPEX	= YXTYPEX_ALARMCOUNT + 1,
	YCTYPEX_DAYMAX	= 1,
	YCTYPEX_DAYMIN	= YCTYPEX_DAYMAX + 1,
	YCTYPEX_DAYAVRG	= YCTYPEX_DAYMIN + 1,
	YCTYPEX_OKPERCENT	= YCTYPEX_DAYAVRG + 1,
	NUM_YCTYPEX2	= YCTYPEX_OKPERCENT + 1,
	YCTYPEX_DAYMAXTIME	= NUM_YCTYPEX2,
	YCTYPEX_DAYMINTIME	= YCTYPEX_DAYMAXTIME + 1,
	NUM_YCTYPEX	= YCTYPEX_DAYMINTIME + 1,
	YDTYPEX_HOURSUM	= 1,
	YDTYPEX_DAYSUM	= YDTYPEX_HOURSUM + 1,
	YDTYPEX_FF	= YDTYPEX_DAYSUM + 1,
	YDTYPEX_GG	= YDTYPEX_FF + 1,
	NUM_YDTYPEX	= YDTYPEX_GG + 1,
	NUM_YTTYPEX	= 1,
	CONTYPEX_BOOLS	= 1,
	CONTYPEX_DIGIT	= CONTYPEX_BOOLS + 1,
	NUM_CONTYPEX	= CONTYPEX_DIGIT + 1,
	CALTYPEX_SUM	= 1,
	CALTYPEX_FACTOR	= CALTYPEX_SUM + 1,
	CALTYPEX_BALANCE	= CALTYPEX_FACTOR + 1,
	NUM_CALTYPEX	= CALTYPEX_BALANCE + 1,
	CUMTYPEX_SUM	= 1,
	CUMTYPEX_AVERAGE	= CUMTYPEX_SUM + 1,
	CUMTYPEX_RIGHTAVRG	= CUMTYPEX_AVERAGE + 1,
	NUM_CUMTYPEX	= CUMTYPEX_RIGHTAVRG + 1
    };

enum __MIDL_pansi_0006
    {	VARSTATUS_ERROR	= -1,
	VARSTATUS_NORMAL	= 0,
	VARSTATUS_LOCK	= VARSTATUS_NORMAL + 1,
	VARSTATUS_MANSET	= VARSTATUS_LOCK + 1,
	VARSTATUS_YK	= VARSTATUS_MANSET + 1,
	VARSTATUS_ALARM	= VARSTATUS_YK + 1,
	VARSTATUS_UPPER	= VARSTATUS_ALARM,
	VARSTATUS_LOWER	= VARSTATUS_UPPER + 1,
	VARSTATUS_SETSIDE	= VARSTATUS_LOWER + 1,
	VARSTATUS_UPGRADE	= VARSTATUS_SETSIDE + 1,
	VARSTATUS_DOWNGRADE	= VARSTATUS_UPGRADE + 1,
	VARSTATUS_bad	= 0x80
    };

enum __MIDL_pansi_0007
    {	ALARMLEVEL_1	= 0,
	ALARMLEVEL_2	= ALARMLEVEL_1 + 1,
	ALARMLEVEL_3	= ALARMLEVEL_2 + 1,
	ALARMLEVEL_4	= ALARMLEVEL_3 + 1,
	NUM_ALARMLEVEL	= ALARMLEVEL_4 + 1
    };

enum __MIDL_pansi_0008
    {	EVENTTYPE_ALARM	= 0,
	EVENTTYPE_OPERATION	= EVENTTYPE_ALARM + 1,
	EVENTTYPE_SYSTEM	= EVENTTYPE_OPERATION + 1,
	NUM_EVENTTYPE	= EVENTTYPE_SYSTEM + 1
    };

enum __MIDL_pansi_0009
    {	EVENTSUBTYPE_RTU	= 0,
	EVENTSUBTYPE_SWITCH	= EVENTSUBTYPE_RTU + 1,
	EVENTSUBTYPE_SOE	= EVENTSUBTYPE_SWITCH + 1,
	EVENTSUBTYPE_SIGNAL	= EVENTSUBTYPE_SOE + 1,
	EVENTSUBTYPE_OVERFLOW	= EVENTSUBTYPE_SIGNAL + 1,
	EVENTSUBTYPE_LOCK	= EVENTSUBTYPE_OVERFLOW + 1,
	EVENTSUBTYPE_MANSET	= EVENTSUBTYPE_LOCK + 1,
	EVENTSUBTYPE_SETSIDE	= EVENTSUBTYPE_MANSET + 1,
	EVENTSUBTYPE_YK	= EVENTSUBTYPE_SETSIDE + 1,
	EVENTSUBTYPE_YT	= EVENTSUBTYPE_YK + 1,
	EVENTSUBTYPE_RTURESET	= EVENTSUBTYPE_YT + 1,
	EVENTSUBTYPE_STARTUP	= EVENTSUBTYPE_RTURESET + 1,
	EVENTSUBTYPE_LOGON	= EVENTSUBTYPE_STARTUP + 1,
	EVENTSUBTYPE_SYSTEMOP	= EVENTSUBTYPE_LOGON + 1,
	NUM_EVENTSUBTYPE	= EVENTSUBTYPE_SYSTEMOP + 1,
	EVENTTYPE_alarm0	= EVENTSUBTYPE_RTU,
	EVENTTYPE_alarm1	= EVENTSUBTYPE_OVERFLOW,
	EVENTTYPE_operation0	= EVENTSUBTYPE_LOCK,
	EVENTTYPE_operation1	= EVENTSUBTYPE_RTURESET,
	EVENTTYPE_system0	= EVENTSUBTYPE_STARTUP,
	EVENTTYPE_system1	= EVENTSUBTYPE_SYSTEMOP
    };

enum __MIDL_pansi_0010
    {	EVENTSTATUS_RESET	= 0,
	EVENTSTATUS_RTUSET	= 1,
	EVENTSTATUS_YXSET0	= 1,
	EVENTSTATUS_YXSET1	= EVENTSTATUS_YXSET0 + 1,
	EVENTSTATUS_YXCHANGE0	= EVENTSTATUS_YXSET1 + 1,
	EVENTSTATUS_YXCHANGE1	= EVENTSTATUS_YXCHANGE0 + 1,
	EVENTSTATUS_SOE0	= 1,
	EVENTSTATUS_SOE1	= EVENTSTATUS_SOE0 + 1,
	EVENTSTATUS_YCLOWER	= 1,
	EVENTSTATUS_YCUPPER	= EVENTSTATUS_YCLOWER + 1,
	EVENTSTATUS_LOCK	= 1,
	EVENTSTATUS_MANSETX	= 1,
	EVENTSTATUS_MANSET0	= EVENTSTATUS_MANSETX + 1,
	EVENTSTATUS_MANSET1	= EVENTSTATUS_MANSET0 + 1,
	EVENTSTATUS_SETSIDE	= 1,
	EVENTSTATUS_YKTIMEOUT	= 1,
	EVENTSTATUS_YKFAIL	= EVENTSTATUS_YKTIMEOUT + 1,
	EVENTSTATUS_YKSUCCESS	= EVENTSTATUS_YKFAIL + 1,
	EVENTSTATUS_YKEXEC	= EVENTSTATUS_YKSUCCESS + 1,
	EVENTSTATUS_YKREADY	= EVENTSTATUS_YKEXEC + 1,
	EVENTSTATUS_YKCOMFIRM	= EVENTSTATUS_YKREADY + 1,
	EVENTSTATUS_YKREQUEST	= EVENTSTATUS_YKCOMFIRM + 1,
	EVENTSTATUS_POWERON	= 1,
	EVENTSTATUS_LOGON	= 1,
	EVENTSTATUS_VDT	= 1,
	EVENTSTATUS_DATABASE	= EVENTSTATUS_VDT + 1,
	EVENTSTATUS_PLAN	= EVENTSTATUS_DATABASE + 1,
	EVENTSTATUS_PAGE	= EVENTSTATUS_PLAN + 1
    };
typedef struct  tagPS_DATE
    {
    short year;
    char month;
    char day;
    }	PS_DATE;

typedef struct  tagPS_TIME
    {
    char hour;
    char minute;
    char second;
    char hundsec;
    }	PS_TIME;

typedef struct  tagPS_DATETIME
    {
    short year;
    char month;
    char day;
    char hour;
    char minute;
    char second;
    char hundsec;
    }	PS_DATETIME;

typedef struct  tagPS_FILEDATA
    {
    char filename[ 80 ];
    PS_DATE date;
    PS_TIME time;
    long size;
    }	PS_FILEDATA;

typedef struct  tagPS_USERITEM
    {
    char computername[ 16 ];
    char regname[ 20 ];
    char username[ 20 ];
    char password[ 20 ];
    long priority;
    }	PS_USERITEM;

typedef struct  tagEN_ssystem
    {
    char name[ 80 ];
    short nstation;
    short nYX;
    short nYC;
    short nYD;
    short nYT;
    short nCON;
    short nCAL;
    short nCUM;
    short samplerate;
    short ykTimeout;
    PS_TIME fftime[ 4 ];
    PS_TIME ggtime[ 4 ];
    char HomePage[ 80 ];
    }	EN_ssystem;

typedef struct  tagEN_sstation
    {
    char name[ 21 ];
    char protocol[ 21 ];
    char addr1[ 16 ];
    char addr2[ 16 ];
    unsigned short port;
    unsigned short yk_begin;
    unsigned short yk_end;
    unsigned short yt_begin;
    unsigned short yt_end;
    unsigned short oper_type;
    unsigned short oper_point;
    float oper_value;
    char pagefile[ 80 ];
    long reserved;
    }	EN_sstation;

typedef struct  tagPS_rt_gen
    {
    short status;
    short rtuflag;
    float value;
    }	PS_rt_gen;

typedef struct  tagPS_rt_yx
    {
    short status;
    short rtuflag;
    short value;
    unsigned short alarmcount;
    }	PS_rt_yx;

typedef struct  tagPS_rt_yc
    {
    short status;
    short rtuflag;
    float value;
    float daymax;
    float daymin;
    long maxtime;
    long mintime;
    float dayavrg;
    float okratio;
    }	PS_rt_yc;

typedef struct  tagPS_rt_yd
    {
    short status;
    short rtuflag;
    float value;
    float hourvalue;
    float dayvalue;
    float ffsum;
    float ggsum;
    }	PS_rt_yd;

typedef struct  tagEN_yyx
    {
    char name[ 41 ];
    struct  
        {
        unsigned int fAlarm	: 1;
        unsigned int fAlarmCount	: 1;
        unsigned int type	: 2;
        unsigned int unused	: 8;
        unsigned int padding	: 16;
        }	flag;
    short ykno;
    short alarmtype;
    short alevel;
    PS_rt_yx yx;
    }	EN_yyx;

typedef struct  tagEN_yyc
    {
    char name[ 41 ];
    char unit[ 11 ];
    float k;
    float b;
    short precision;
    float fullvalue;
    float mindelta;
    float zerovalue;
    short flog;
    short fplan;
    short fcache;
    struct  
        {
        unsigned int fTrans	: 1;
        unsigned int fMin	: 1;
        unsigned int fMax	: 1;
        unsigned int fAvrg	: 1;
        unsigned int fRatio	: 1;
        unsigned int fUpper	: 1;
        unsigned int fLower	: 1;
        unsigned int fUpper2	: 1;
        unsigned int fLower2	: 1;
        unsigned int fMinTime	: 1;
        unsigned int fMaxTime	: 1;
        unsigned int padding	: 16;
        unsigned int fMax2	: 1;
        unsigned int fMaxTime2	: 1;
        }	flag;
    short yxno;
    short alevel;
    float uppervalue;
    float lowervalue;
    float uppervalue2;
    float lowervalue2;
    PS_rt_yc yc;
    }	EN_yyc;

typedef struct  tagEN_yyd
    {
    char name[ 41 ];
    char unit[ 11 ];
    float k;
    float b;
    short precision;
    short flog;
    struct  
        {
        unsigned int fTrans	: 1;
        unsigned int fHourSum	: 1;
        unsigned int fDaySum	: 1;
        unsigned int fFF	: 1;
        unsigned int fGG	: 1;
        unsigned int unused	: 8;
        unsigned int padding	: 16;
        }	flag;
    PS_rt_yd yd;
    }	EN_yyd;

typedef struct  tagEN_yyt
    {
    char name[ 41 ];
    short ytno;
    short uppergrade;
    short lowergrade;
    }	EN_yyt;

typedef struct  tagPS_BASEDATA
    {
    short year;
    char month;
    char day;
    char hour;
    char minute;
    char second;
    char hundsec;
    float value;
    short status;
    }	PS_BASEDATA;

typedef union tagUNIONVALUE
    {
    long lv;
    float fv;
    }	UNIONVALUE;

typedef struct  tagEN_expression
    {
    short type;
    union 
        {
        char str[ 80 ];
        UNIONVALUE param[ 20 ];
        }	;
    }	EN_expression;

typedef struct  tagENEVENT
    {
    char type;
    char subtype;
    char status;
    PS_DATE date;
    PS_TIME time;
    char dtype;
    short station;
    short point;
    char note[ 21 ];
    char optor[ 20 ];
    char flag;
    }	ENEVENT;

void RPC_TestProc( void);

int RPC_GetPageFileNum( void);

int RPC_GetPageFilesData( 
    /* [size_is][out][in] */ PS_FILEDATA __RPC_FAR pfd[  ],
    /* [in] */ int n);

int RPC_GetPageFile( 
    /* [in] */ PS_FILEDATA __RPC_FAR *pfd,
    /* [in] */ long size,
    /* [size_is][out] */ char __RPC_FAR pdata[  ]);

int RPC_SavePageFile( 
    /* [in] */ PS_FILEDATA __RPC_FAR *pfd,
    /* [in] */ long size,
    /* [size_is][in] */ char __RPC_FAR pdata[  ],
    /* [string][in] */ char __RPC_FAR *regname);

long RPC_GetVDTlid( void);

int RPC_GetSystemStruct( 
    /* [size_is][out] */ EN_ssystem __RPC_FAR *psystem);

int RPC_GetStationStruct( 
    /* [size_is][out] */ char __RPC_FAR pstations[  ],
    /* [in] */ int size);

int RPC_GetYXStruct( 
    /* [size_is][out] */ char __RPC_FAR pyyx[  ],
    /* [in] */ int size,
    /* [in] */ int station);

int RPC_GetYCStruct( 
    /* [size_is][out] */ char __RPC_FAR pyyc[  ],
    /* [in] */ int size,
    /* [in] */ int station);

int RPC_GetYDStruct( 
    /* [size_is][out] */ char __RPC_FAR pyyd[  ],
    /* [in] */ int size,
    /* [in] */ int station);

int RPC_GetYTStruct( 
    /* [size_is][out] */ char __RPC_FAR pyyt[  ],
    /* [in] */ int size,
    /* [in] */ int station);

int RPC_GetExprStruct( 
    /* [size_is][out] */ char __RPC_FAR expr[  ],
    /* [in] */ int size,
    /* [in] */ int vtype);

int RPC_UserRegister( 
    /* [size_is][out][in] */ PS_USERITEM __RPC_FAR *pUserItem);

int RPC_UserLogon( 
    /* [size_is][out][in] */ PS_USERITEM __RPC_FAR *pUserItem);

int RPC_UserLogoff( 
    /* [size_is][in] */ PS_USERITEM __RPC_FAR *pUserItem);

void RPC_GetSysTime( 
    /* [size_is][out] */ PS_DATE __RPC_FAR psdate[  ],
    /* [size_is][out] */ PS_TIME __RPC_FAR pstime[  ]);

int RPC_GetNewEvents( 
    /* [size_is][out][in] */ char __RPC_FAR pEvents[  ],
    /* [in] */ int size);

int RPC_GetRealtimeData( 
    /* [size_is][in] */ long __RPC_FAR pIDs[  ],
    /* [size_is][out] */ PS_rt_gen __RPC_FAR data[  ],
    /* [in] */ int n);

int RPC_GetRealtimeYXData( 
    /* [size_is][in] */ long __RPC_FAR pIDs[  ],
    /* [size_is][out] */ PS_rt_yx __RPC_FAR data[  ],
    /* [in] */ int n);

int RPC_GetRealtimeYCData( 
    /* [size_is][in] */ long __RPC_FAR pIDs[  ],
    /* [size_is][out] */ PS_rt_yc __RPC_FAR data[  ],
    /* [in] */ int n);

int RPC_GetRealtimeYDData( 
    /* [size_is][in] */ long __RPC_FAR pIDs[  ],
    /* [size_is][out] */ PS_rt_yd __RPC_FAR data[  ],
    /* [in] */ int n);

int RPC_GetDayYXData( 
    /* [string][in] */ char __RPC_FAR *datetime,
    /* [size_is][in] */ long __RPC_FAR pIDs[  ],
    /* [size_is][out] */ PS_rt_yx __RPC_FAR data[  ],
    /* [in] */ int n);

int RPC_GetDayYCData( 
    /* [string][in] */ char __RPC_FAR *datetime,
    /* [size_is][in] */ long __RPC_FAR pIDs[  ],
    /* [size_is][out] */ PS_rt_yc __RPC_FAR data[  ],
    /* [in] */ int n);

int RPC_GetDayYDData( 
    /* [string][in] */ char __RPC_FAR *datetime,
    /* [size_is][in] */ long __RPC_FAR pIDs[  ],
    /* [size_is][out] */ PS_rt_yd __RPC_FAR data[  ],
    /* [in] */ int n);

void RPC_ManSetValue( 
    /* [in] */ long varID,
    /* [in] */ float value,
    /* [string][in] */ char __RPC_FAR *regname);

void RPC_DontCareValue( 
    /* [in] */ long varID,
    /* [string][in] */ char __RPC_FAR *regname);

void RPC_FreshValue( 
    /* [in] */ long varID,
    /* [string][in] */ char __RPC_FAR *regname);

void RPC_YKRequest( 
    /* [in] */ long varID,
    /* [in] */ float tovalue,
    /* [string][in] */ char __RPC_FAR *regname);

void RPC_YKConfirm( 
    /* [in] */ long varID,
    /* [in] */ float tovalue,
    /* [string][in] */ char __RPC_FAR *regname);

void RPC_YKExecute( 
    /* [in] */ long varID,
    /* [in] */ float tovalue,
    /* [string][in] */ char __RPC_FAR *regname);

void RPC_RTUReset( 
    /* [in] */ long varID,
    /* [string][in] */ char __RPC_FAR *regname);

void RPC_SetSide( 
    /* [in] */ long varID,
    /* [in] */ long dwP,
    /* [in] */ long dwQ,
    /* [in] */ long dwI,
    /* [string][in] */ char __RPC_FAR *regname);

void RPC_ResetSide( 
    /* [in] */ long varID,
    /* [in] */ long dwP,
    /* [in] */ long dwQ,
    /* [in] */ long dwI,
    /* [string][in] */ char __RPC_FAR *regname);

int RPC_GetEventNum( 
    /* [in] */ PS_DATE __RPC_FAR *pDate);

int RPC_LoadEventBase( 
    /* [size_is][out] */ char __RPC_FAR pEvents[  ],
    /* [in] */ int size,
    /* [in] */ PS_DATE __RPC_FAR *pDate);

int RPC_GetVarEventNum( 
    /* [in] */ long vid,
    /* [in] */ PS_DATE __RPC_FAR *pDate);

int RPC_LoadVarEventBase( 
    /* [in] */ long vid,
    /* [size_is][out] */ char __RPC_FAR pEvents[  ],
    /* [in] */ int size,
    /* [in] */ PS_DATE __RPC_FAR *pDate);

float RPC_EvaluateExpression( 
    /* [size_is][in] */ char __RPC_FAR pExpr[  ],
    /* [out] */ int __RPC_FAR *errcode);

int RPC_GetRecordNum( 
    /* [in] */ long varID,
    /* [string][in] */ char __RPC_FAR *datetime0,
    /* [string][in] */ char __RPC_FAR *datetime1);

int RPC_LoadRecordData( 
    /* [in] */ long varID,
    /* [string][in] */ char __RPC_FAR *datetime0,
    /* [string][in] */ char __RPC_FAR *datetime1,
    /* [size_is][out] */ PS_BASEDATA __RPC_FAR pBasedata[  ],
    /* [in] */ int n);

int RPC_GetPlanRecNum( 
    /* [in] */ long varID,
    /* [string][in] */ char __RPC_FAR *datetime0,
    /* [string][in] */ char __RPC_FAR *datetime1);

int RPC_LoadPlanRecData( 
    /* [in] */ long varID,
    /* [string][in] */ char __RPC_FAR *datetime0,
    /* [string][in] */ char __RPC_FAR *datetime1,
    /* [size_is][out] */ PS_BASEDATA __RPC_FAR pBasedata[  ],
    /* [in] */ int n);

int RPC_LockPage( 
    /* [string][in] */ char __RPC_FAR *pagefile,
    /* [string][in] */ char __RPC_FAR *regname);

int RPC_UnlockPage( 
    /* [string][in] */ char __RPC_FAR *pagefile,
    /* [string][in] */ char __RPC_FAR *regname);

int RPC_LockVDT( 
    /* [string][in] */ char __RPC_FAR *regname);

int RPC_UnlockVDT( 
    /* [string][in] */ char __RPC_FAR *regname);

int RPC_LockSysParams( 
    /* [string][in] */ char __RPC_FAR *regname);

int RPC_UnlockSysParams( 
    /* [string][in] */ char __RPC_FAR *regname);

int RPC_LockUserList( 
    /* [string][in] */ char __RPC_FAR *regname);

int RPC_UnlockUserList( 
    /* [string][in] */ char __RPC_FAR *regname);

int RPC_LockDatabase( 
    /* [in] */ long varID,
    /* [string][in] */ char __RPC_FAR *regname);

int RPC_UnlockDatabase( 
    /* [in] */ long varID,
    /* [string][in] */ char __RPC_FAR *regname);

int RPC_LockPlanbase( 
    /* [in] */ long varID,
    /* [string][in] */ char __RPC_FAR *regname);

int RPC_UnlockPlanbase( 
    /* [in] */ long varID,
    /* [string][in] */ char __RPC_FAR *regname);

int RPC_LockOperation( 
    /* [in] */ long varID,
    /* [string][in] */ char __RPC_FAR *regname);

int RPC_UnlockOperation( 
    /* [in] */ long varID,
    /* [string][in] */ char __RPC_FAR *regname);

int RPC_GetSignalVarNum( 
    /* [string][in] */ char __RPC_FAR *datetime,
    /* [in] */ long yxvid,
    /* [out] */ int __RPC_FAR *nrec);

int RPC_GetSignalVarID( 
    /* [string][in] */ char __RPC_FAR *datetime,
    /* [in] */ long yxvid,
    /* [size_is][out] */ long __RPC_FAR ycvids[  ],
    /* [in] */ int n);

int RPC_LoadSignalVarData( 
    /* [string][in] */ char __RPC_FAR *datetime,
    /* [in] */ long yxvid,
    /* [in] */ long ycvid,
    /* [size_is][out] */ float __RPC_FAR pData[  ],
    /* [size_is][out] */ int __RPC_FAR pInterval[  ],
    /* [in] */ int nrec);

int RPC_LoadPlanningData( 
    /* [in] */ long varID,
    /* [size_is][out] */ float __RPC_FAR pData[  ],
    /* [in] */ int n);

int RPC_SetPlanningData( 
    /* [in] */ long varID,
    /* [size_is][in] */ float __RPC_FAR pData[  ],
    /* [in] */ int n);

int RPC_GetUserNum( void);

int RPC_LoadUserList( 
    /* [size_is][out] */ PS_USERITEM __RPC_FAR pUserItem[  ],
    /* [in] */ int n);

int RPC_InsertEvent( 
    /* [size_is][in] */ char __RPC_FAR pEvents[  ],
    /* [in] */ int size);

int RPC_DeleteEvent( 
    /* [size_is][in] */ char __RPC_FAR pEvents[  ],
    /* [in] */ int size);


extern handle_t hPansi;


extern RPC_IF_HANDLE pansi_ClientIfHandle;
extern RPC_IF_HANDLE pansi_ServerIfHandle;
#endif /* __pansi_INTERFACE_DEFINED__ */

/* Additional Prototypes for ALL interfaces */

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif
