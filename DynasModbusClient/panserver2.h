// panserver2.h
#ifndef _PANSERVER2_H_
#define _PANSERVER2_H_

#ifdef _MSC_VER

typedef struct  tagMod_System
	{
		int nYC;
		int nYX;
		int nYK;
		int nYT;
	}	Modbus_SYSTEM;
typedef struct  tagMod_YX
{
	char station;
	int point;
	int addr;
	short value;
}	Modbus_YX;
typedef struct  tagMod_YC
{
	char station;
	int point;
	float k;
	int addr;
	float value;
}	Modbus_YC;
typedef struct  tagMod_YK
{
	char station;
	int point;
	int addr;
}	Modbus_YK;
typedef struct  tagMod_YT
{
	char station;
	int point;
	int addr;
	float k;
}	Modbus_YT;
extern Modbus_SYSTEM System;
extern Modbus_YC *ppModYC;
extern Modbus_YX *ppModYX;
extern Modbus_YK *ppModYK;
extern Modbus_YT *ppModYT;
BOOL connectA;
extern int  WINAPI FrontEndSetup();
extern void WINAPI FrontEndCleanup();
char *WINAPI GetIniFileName();
char *WINAPI GetSubString(char *profstr, int fieldno);

#endif
#endif
// end of file -- panserver2.h
