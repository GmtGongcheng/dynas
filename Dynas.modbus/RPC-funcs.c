// RPC-funcs.cpp
//
//	Remote procedures that are linked with the server side of RPC
//	distributed application
#define    WIN32_LEAN_AND_MEAN
#include <windows.h>
#include <stdlib.h>
#include <stdio.h>
#include <dos.h>
//#include <dir.h>
#include <time.h>
//#include <sys/timeb.h>


#include "pansi.h"    // header file generated by MIDL compiler
#include "panserver2.h"

#define PS_DEBUG

int no_random(int num)
{
	return 0;
}

#define random no_random


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
// RPC setup & cleanup routine
//==========================================================================

LRESULT WINAPI RPCSetup (LPVOID lp)
{
	RPC_STATUS status;
    unsigned char *pszProtocolSequence = (unsigned char *)DEFAULT_PROT_SEQ;
    unsigned char *pszSecurity         = NULL;
    unsigned char *pszEndpoint         = (unsigned char *)DEFAULT_ENDPOINT;
    unsigned int   cMinCalls           = 1;
    unsigned int   cMaxCalls           = 20;
    unsigned int   fDontWait           = FALSE;
    char *errtitle = "Error";
    char errstr[80];

    status = RpcServerUseProtseqEp (pszProtocolSequence,
                                    cMaxCalls,
                                    pszEndpoint,
                                    pszSecurity);  // Security descriptor

    if (status)
    {
    	//sprintf (errstr, "RpcServerUseProtseqEp returned 0x%x\n", status);
	    //MessageBox (NULL, errstr, errtitle, MB_OK|MB_ICONEXCLAMATION);
    	DebugPrintf("ERROR: RpcServerUseProtseqEp returned 0x%x\n", status);
        return status;
    }

    status = RpcServerRegisterIf (pansi_ServerIfHandle, // interface to register
                                  NULL,   // MgrTypeUuid
                                  NULL);  // MgrEpv; null means use default
    if (status)
    {
    	//sprintf(errstr, "RpcServerRegisterIf returned 0x%x\n", status);
	    //MessageBox (NULL, errstr, errtitle, MB_OK|MB_ICONEXCLAMATION);
        DebugPrintf("ERROR: RpcServerRegisterIf returned 0x%x\n", status);
		return status;
    }

    status = RpcServerListen (cMinCalls, cMaxCalls, fDontWait);
    if (status)
    {
    	//sprintf(errstr, "RpcServerListen returned: 0x%x\n", status);
    	//MessageBox (NULL, errstr, errtitle, MB_OK|MB_ICONEXCLAMATION);
		DebugPrintf("ERROR: RpcServerListen returned: 0x%x\n", status);
        return status;
    }

    if (fDontWait)
    {
        status = RpcMgmtWaitServerListen();  //  wait operation

        if (status)
        {
        	//sprintf (errstr, "RpcMgmtWaitServerListen returned: 0x%x\n", status);
            //MessageBox (NULL, errstr, errtitle, MB_OK|MB_ICONEXCLAMATION);
			DebugPrintf("ERROR: RpcMgmtWaitServerListen returned: 0x%x\n", status);
	        return status;
        }
    }

    return 0;
}

LRESULT WINAPI RPCCleanup (LPVOID lp)
{
    RPC_STATUS status;

    status = RpcMgmtStopServerListening(NULL);
    if (status)
	    return status;

    status = RpcServerUnregisterIf(NULL, NULL, FALSE);
    if (status)
	    return status;

    return 0;
}

//==========================================================================
// RPC functions
//==========================================================================

void RPC_TestProc () // unsigned char *pszString)
{
#ifdef PS_DEBUG
	//SendMessage (g_hMainDlg, UWM_SETDEBUGSTRING, 0, (LPARAM)pszString);
	//DebugPrintln(pszString);
#endif // PS_DEBUG
}

// RPC_UserRegister

int RPC_UserRegister (PS_USERITEM *pUserItem)
{
	//pUserItem->priority = 0;
}

int RPC_UserLogon (PS_USERITEM *pUserItem)
{
	if ( strcmp (pUserItem->regname, "abc") )
    	pUserItem->priority = URERROR_USERCANCELED;
    else if ( strcmp (pUserItem->password, "123") )
		pUserItem->priority = URERROR_PASSWORD;
    else
    {
    	strcpy (pUserItem->username, "西电/端怡科技");
    	pUserItem->priority = USERPRIORITY_ALL;
    }
    return 1;
}

int RPC_UserLogoff (PS_USERITEM *pUserItem)
{
}

// RPC_GetPageFileNum

int RPC_GetPageFileNum ()
{
	int n;
    HANDLE hFile;
    char filename[MAX_PATH];
    WIN32_FIND_DATA filedata;

#ifdef PS_DEBUG
	//SendMessage (g_hMainDlg, UWM_SETDEBUGSTRING, 0, (LPARAM)"GetPageFileNum");
	DebugPrintln("GetPageFileNum");
#endif // PS_DEBUG

    sprintf (filename, "page\\*.x?f");
	hFile = FindFirstFile (filename, &filedata);
    if ( hFile == INVALID_HANDLE_VALUE )
    	return 0;		// error or no file

    for (n = 1; FindNextFile (hFile, &filedata); n++);
	FindClose (hFile);

	return n;
}

// RPC_GetPageFilesData
//
//	Returns:
//		The file number. The returned num is always < n

int RPC_GetPageFilesData (PS_FILEDATA *pfd, int nfile)
{
	HANDLE hFile;
    char filename[MAX_PATH];
    WIN32_FIND_DATA filedata;
    int n;

#ifdef PS_DEBUG
	//SendMessage (g_hMainDlg, UWM_SETDEBUGSTRING, 0, (LPARAM)"GetPageFilesData");
	DebugPrintln("GetPageFilesData");
#endif // PS_DEBUG

    sprintf (filename, "page\\*.x?f");
	hFile = FindFirstFile (filename, &filedata);
    if ( hFile == INVALID_HANDLE_VALUE )
    	return 0;		// error or no file

    for (n = 0; n < nfile; n++)
    {
    	char file[_MAX_FNAME];
    	char ext[_MAX_EXT];
        WORD dosdate, dostime;

        _splitpath (filedata.cFileName, NULL, NULL, file, ext);
        sprintf (pfd[n].filename, "%s%s", file, ext);

        FileTimeToDosDateTime (&filedata.ftLastWriteTime, &dosdate, &dostime);

        pfd[n].date.year  = (short)(1980 + (dosdate >> 9));
        pfd[n].date.month = (short)((dosdate & 0x01E0) >> 5);
        pfd[n].date.day   = (short)(dosdate & 0x001F);

        pfd[n].time.hour   = (short)(dostime >> 11);
        pfd[n].time.minute = (short)((dostime & 0x07E0) >> 5);
        pfd[n].time.second = (short)(2*(dostime & 0x001F));

        pfd[n].size = filedata.nFileSizeLow;

        if ( FindNextFile (hFile, &filedata) == FALSE )
        	break;
    }
	FindClose (hFile);

	return n+1;
}

// RPC_GetPageFile

int RPC_GetPageFile (PS_FILEDATA *pfd, long size, char *pdata)
{
	char filename[_MAX_PATH];
    FILE *fp;
/*
#ifdef PS_DEBUG
	SendMessage (g_hMainDlg, UWM_SETDEBUGSTRING, 0, (LPARAM)"RPC_GetPageFile");
#endif // PS_DEBUG
*/
    sprintf (filename, "page\\%s", pfd->filename);

    fp = fopen (filename, "rb");
    if ( !fp )
    	return 0;	// fail

   	fread (pdata, size, 1, fp);

    fclose (fp);

    return 1;		// success
}

// RPC_SavePageFile

int RPC_SavePageFile (PS_FILEDATA *pfd, long size, char *pdata, char *regname)
{
	char filename[_MAX_PATH];
    FILE *fp;
/*
#ifdef PS_DEBUG
	SendMessage (g_hMainDlg, UWM_SETDEBUGSTRING, 0, (LPARAM)"RPC_GetPageFile");
#endif // PS_DEBUG
*/
    sprintf (filename, "page\\%s", pfd->filename);

    fp = fopen (filename, "wb");
    if ( !fp )
    	return 0;	// fail

   	fwrite (pdata, size, 1, fp);

    fclose (fp);

    return 1;		// success
}

//==========================================================================
// VDT releated functions
//==========================================================================

long RPC_GetVDTlid ()
{
#ifdef PS_DEBUG
	//SendMessage (g_hMainDlg, UWM_SETDEBUGSTRING, 0, (LPARAM)"RPC_GetVDTlid");
	DebugPrintln("RPC_GetVDTlid");
#endif // PS_DEBUG

	return 0;
}

int RPC_GetSystemStruct (EN_ssystem *psystem)
{
#ifdef PS_DEBUG
	//SendMessage (g_hMainDlg, UWM_SETDEBUGSTRING, 0, (LPARAM)"RPC_GetSystemStruct");
	DebugPrintln("RPC_GetSystemStruct");
#endif // PS_DEBUG

	memcpy(psystem, &System, sizeof(EN_ssystem));
	/*
	strcpy (psystem->name, System.name);

	psystem->nstation = System.nstation;

	psystem->nYX = System.nYX;
	psystem->nYC = System.nYC;
	psystem->nYD = System.nYD;
	psystem->nYT = System.nYT;

	psystem->nCON = System.nCON;
	psystem->nCAL = System.nCAL;
	psystem->nCUM = System.nCUM;

	psystem->samplerate = System.samplerate;
	psystem->ykTimeout = System.ykTimeout;

    strcpy (psystem->HomePage, System.HomePage);
	*/

    return 1;	// OK
}

int RPC_GetStationStruct (char *pstations, int size)
{
#ifdef PS_DEBUG
	//SendMessage (g_hMainDlg, UWM_SETDEBUGSTRING, 0, (LPARAM)"RPC_GetStationStruct");
	DebugPrintln("RPC_GetStationStruct");
#endif // PS_DEBUG

	memcpy((EN_sstation *)pstations, pStation, size);

	/*
	int nstation = size/sizeof(EN_sstation);
    EN_sstation *pStations = (EN_sstation *)pstations;
    int i;

	memset (pstations, 0, size);

	for ( i=0; i<nstation; i++ )
    {
		if (i)
		{
			char defname[21];
			char keyname[21];
			sprintf(defname, "第 %d 站", i);
			sprintf(keyname, "station_%d", i);
			GetPrivateProfileString("station", keyname, defname, pStations[i].name, 21, GetIniFileName());
		}
        else
        	strcpy (pStations[i].name, "[计算点]");
		strcpy (pStations[i].pagefile, "gyb.xpf");
    }
	*/

    return 1;	// OK
}

int RPC_GetYXStruct (char *pyyx, int size, int station)
{

#ifdef PS_DEBUG
	//SendMessage (g_hMainDlg, UWM_SETDEBUGSTRING, 0, (LPARAM)"RPC_GetYXStruct");
	DebugPrintln("RPC_GetYXStruct");
#endif // PS_DEBUG

	waitfor_mutex(Mutex_RT);
	memcpy((EN_yyx *)pyyx, ppYX[station], size);
	release_mutex(Mutex_RT);

	/*
	int nyx = size/sizeof(EN_yyx);
    EN_yyx *pYX = (EN_yyx *)pyyx;		// cast
    int i;

    memset (pyyx, 0, size);    		// reset

    for ( i=0; i<nyx; i++ )
    {
    	if ( station )
        {
			if (i)
			{
				char defname[41];
				char keyname[41];
				sprintf(defname, "YX_%d_%04d", station, i);
				sprintf(keyname, "YX_%d_%d", station, i);
				GetPrivateProfileString("point", keyname, defname, pYX[i].name, 41, GetIniFileName());
				//sprintf(pYX[i].name, "YX%d, %04d", station - 1, i - 1);
			}
            else
            	strcpy (pYX[i].name, "RTU状态");
        }
        else	// station == 0
        {
        	if ( i )
        		sprintf (pYX[i].name, "CON, %04d", i);
            else
            	strcpy (pYX[i].name, "网络状态");
        }
        pYX[i].alevel = 3;
        pYX[i].ykno = -1;
        pYX[i].flag.fAlarmCount = 1;
    }
	*/

    return 1;	// OK
}

int RPC_GetYCStruct (char *pyyc, int size, int station)
{
#ifdef PS_DEBUG
	//SendMessage (g_hMainDlg, UWM_SETDEBUGSTRING, 0, (LPARAM)"RPC_GetYCStruct");
#endif // PS_DEBUG

	waitfor_mutex(Mutex_RT);
	memcpy((EN_yyc *)pyyc, ppYC[station], size);
	release_mutex(Mutex_RT);
	
	/*
 	int nyc = size/sizeof(EN_yyc);
    EN_yyc *pYC = (EN_yyc *)pyyc;		// cast
    int i;

    memset (pyyc, 0, size);    		// reset

    for ( i=0; i<nyc; i++ )
    {
    	if ( station )
        {
			if (i)
			{
				char defname[41];
				char keyname[41];
				sprintf(defname, "YC_%d_%04d", station, i);
				sprintf(keyname, "YC_%d_%d", station, i);
				GetPrivateProfileString("point", keyname, defname, pYC[i].name, 41, GetIniFileName());
				//sprintf (pYC[i].name, "YC%d, %04d", station-1, i-1);
			}
        		
            else
            	strcpy (pYC[i].name, "电网频率");
        }
        else	// station == 0
        {
        	if ( i )
        		sprintf (pYC[i].name, "CAL, %04d", i);
            else
            	strcpy (pYC[i].name, "电网频率");
        }
        pYC[i].precision = 0;
        pYC[i].alevel = 2;
        pYC[i].k = 1;

        pYC[i].flog = 1;
        pYC[i].fplan = 1;
        pYC[i].fcache = 1;

        pYC[i].flag.fMax = 1;
        pYC[i].flag.fMin = 1;
        pYC[i].flag.fAvrg = 1;
        pYC[i].flag.fMaxTime = 1;
        pYC[i].flag.fMinTime = 1;
        pYC[i].flag.fRatio = 1;
    }
	*/

    return 1;	// OK
}

int RPC_GetYDStruct (char *pyyd, int size, int station)
{
	int nyd = size/sizeof(EN_yyd);
    EN_yyd *pYD = (EN_yyd *)pyyd;		// cast
    int i;

#ifdef PS_DEBUG
	//SendMessage (g_hMainDlg, UWM_SETDEBUGSTRING, 0, (LPARAM)"RPC_GetYDStruct");
#endif // PS_DEBUG

    memset (pyyd, 0, size);    		// reset

    for ( i=0; i<nyd; i++ )
    {
    	if ( station )
        {
        	if ( i )
        		sprintf (pYD[i].name, "YD%d, %04d", station, i);
            else
            	strcpy (pYD[i].name, "误码数");
        }
        else	// station == 0
        {
        	if ( i )
        		sprintf (pYD[i].name, "CUM, %04d", i);
            else
            	strcpy (pYD[i].name, "误码总数");
        }
        pYD[i].k = 1;
        pYD[i].flog = 1;

        pYD[i].flag.fHourSum = 1;
        pYD[i].flag.fDaySum = 1;
        pYD[i].flag.fFF = 1;
        pYD[i].flag.fGG = 1;
    }

    return 1;	// OK
}

int RPC_GetYTStruct (char *pyyt, int size, int station)
{
	int nyt = size/sizeof(EN_yyt);
    EN_yyt *pYT = (EN_yyt *)pyyt;		// cast
    int i;

#ifdef PS_DEBUG
	//SendMessage (g_hMainDlg, UWM_SETDEBUGSTRING, 0, (LPARAM)"RPC_GetYTStruct");
#endif // PS_DEBUG

    memset (pyyt, 0, size);    		// reset

    for ( i=0; i<nyt; i++ )
    {
    	if ( station )
        {
        	if ( i )
        		sprintf (pYT[i].name, "YT%d, %04d", station, i);
            else
            	strcpy (pYT[i].name, "(未用)");
        }
        else	// station == 0
        {
        	if ( i )
        		sprintf (pYT[i].name, "XXX, %04d", i);
            else
            	strcpy (pYT[i].name, "(未用)");
        }
        pYT[i].uppergrade = 20;
        pYT[i].lowergrade = 1;
    }

    return 1;	// OK
}

int RPC_GetExprStruct (char *expr, int size, int vtype)
{
	int nexpr = size/sizeof(EN_expression);
    EN_expression *pExpr = (EN_expression *)expr;		// cast
    int i;

#ifdef PS_DEBUG
	//SendMessage (g_hMainDlg, UWM_SETDEBUGSTRING, 0, (LPARAM)"RPC_GetExprStruct");
#endif // PS_DEBUG

	//if ( vtype == VARTYPE_YX )
    memset (pExpr, 0, size);    		// reset

    return 1;	// OK
}

void RPC_GetSysTime (PS_DATE *psdate, PS_TIME *pstime)
{
	struct date d;
	struct time t;

    getdate(&d);
    psdate->year = d.da_year;
    psdate->day = d.da_day;
    psdate->month = d.da_mon;

   	gettime(&t);
    pstime->hour = t.ti_hour;
    pstime-> minute = t.ti_min;
    pstime->second = t.ti_sec;
    pstime->hundsec = t.ti_hund;
	/*
	struct tm *pt;
    time_t long_time;
 	struct _timeb timebuffer;

	time( &long_time );          
    pt = localtime(&long_time); 

    psdate->year = pt->tm_year;
    psdate->day = pt->tm_mday;
    psdate->month = pt->tm_mon;

    pstime->hour = pt->tm_hour;
    pstime-> minute = pt->tm_min;
    pstime->second = pt->tm_sec;

	_ftime(&timebuffer);

    pstime->hundsec = timebuffer.millitm / 10;
	*/
}

int RPC_GetNewEvents (char *pEvents, int size)
{
	int n = size/sizeof(ENEVENT);
    ENEVENT *p = (ENEVENT *)pEvents;

	char datafile[256];
	FILE *fp;
	PS_DATE dt;
	//struct date d;
	struct tm *pt;
    time_t long_time;


	if (pEvents == NULL || size == 0)
		return Num_Event;

	if (Num_Event)
	{
		char infostr[80];
		sprintf(infostr, "：Num=%d, n=%d size=%d", Num_Event, n, size);
		//SendMessage(g_hMainDlg, UWM_SETDEBUGSTRING, 0, (LPARAM)infostr);
		DebugPrintln(infostr);
	}

	waitfor_mutex(Mutex_EVENT);
	if (n > Num_Event)
		n = Num_Event;
	memcpy(pEvents, pEventBuf, n * sizeof(ENEVENT));
	Num_Event = Num_Event - n;
	release_mutex(Mutex_EVENT);

	/*
	getdate(&d);
	dt.year = d.da_year; dt.month = d.da_mon; dt.day = d.da_day;
	*/
	time( &long_time );          
    pt = localtime(&long_time); 
	dt.year = pt->tm_year; dt.month = pt->tm_mon; dt.day = pt->tm_mday;

	sprintf(datafile, ".\\facdata\\%04d%02d%02d.ev", dt.year, dt.month, dt.day);

	fp = fopen(datafile, "a+b");
	if (fp == NULL)
		return 0;

	fwrite(pEvents, sizeof(ENEVENT), n, fp);
	fclose(fp);
	return n;
	
	/*
    struct date d;
	struct time t;

    int rdm;
    p->note[0] = 0;
	p->optor[0] = 0;

	rdm = -1; //random(100);
    switch (rdm)
    {
	case EVENTTYPE_ALARM:
    	p->type = rdm;
        p->subtype = EVENTTYPE_alarm0+random(EVENTTYPE_alarm1-EVENTTYPE_alarm0+1);
        if ( p->subtype == EVENTSUBTYPE_OVERFLOW )
        	p->dtype = VARTYPE_YC;
        else
        	p->dtype = VARTYPE_YX;
    	break;
	case EVENTTYPE_OPERATION:
    	p->type = rdm;
        p->subtype = EVENTTYPE_operation0+random(EVENTTYPE_operation1-EVENTTYPE_operation0+1);
        if ( p->subtype == EVENTSUBTYPE_YK )
        	p->dtype = VARTYPE_YX;
        else
        	p->dtype = random(NUM_VARTYPE);
        strcpy (p->optor, "Somebody");
        break;
	case EVENTTYPE_SYSTEM:
    	p->type = rdm;
        p->subtype = EVENTTYPE_system0+random(EVENTTYPE_system1-EVENTTYPE_system0+1);
        if ( p->subtype !=  EVENTSUBTYPE_STARTUP )
        	strcpy (p->optor, "(Who?)");
        break;
    default:
    	return 0;
    }

    switch (p->subtype)
	{
    case EVENTSUBTYPE_RTU:
		p->status == random(2)?EVENTSTATUS_RESET:EVENTSTATUS_RTUSET;
        break;
	case EVENTSUBTYPE_SWITCH:
		p->status = EVENTSTATUS_RESET + random(5);
        break;
	case EVENTSUBTYPE_SOE:
    	p->status = EVENTSTATUS_SOE0 + random(2);
        strcpy (p->note, "08:32:17:582");
        break;
	case EVENTSUBTYPE_OVERFLOW:
    	p->status = EVENTSTATUS_RESET + random(3);
        strcpy (p->note, "12.34 (U)");
        break;
	case EVENTSUBTYPE_LOCK:
    	p->status = EVENTSTATUS_RESET + random(2);
        break;
	case EVENTSUBTYPE_MANSET:
    	p->status = EVENTSTATUS_RESET + random(4);
        if ( p->subtype != VARTYPE_YX )
			strcpy (p->note, "56.78 (U)");
        break;
	case EVENTSUBTYPE_YK:
    	p->status = EVENTSTATUS_RESET + random(5);
        break;
	case EVENTSUBTYPE_STARTUP:
    	p->status = EVENTSTATUS_RESET + random(2);
        strcpy (p->note, "Athens");
        break;
	case EVENTSUBTYPE_LOGON:
    	p->status = EVENTSTATUS_RESET + random(2);
        strcpy (p->note, "Guiyang");
        break;
	case EVENTSUBTYPE_SYSTEMOP:
    	p->status = EVENTSTATUS_RESET + random(4);
        if ( p->status == EVENTSTATUS_DATABASE )
        	strcpy (p->note, "10/05/1997");
        else if ( p->status == EVENTSTATUS_PAGE )
        	strcpy (p->note, "gyb.xpf");
        break;
	}

    getdate(&d);
    p->date.year = d.da_year;
    p->date.day = d.da_day;
    p->date.month = d.da_mon;

   	gettime(&t);
    p->time.hour = t.ti_hour;
    p->time.minute = t.ti_min;
    p->time.second = t.ti_sec;
    p->time.hundsec = t.ti_hund;

	p->station = random(16);
	p->point = random(100);
    //strcpy (p->note, "Note");
	//strcpy (p->optor, "Somebody");
	p->flag = 0;

    return 1;
	*/
}

int RPC_GetRealtimeData (long *pIDs, PS_rt_gen *data, int n)
{
	int i;
	waitfor_mutex(Mutex_RT);
	for ( i=0; i<n; i++ )
    {
    	int station = GetVarStation(pIDs[i]);
		int point = GetVarPoint(pIDs[i]);
		int vtype = GetVarType(pIDs[i]);

		if (station < 0 || station >= System.nstation)
			continue;

		if (vtype == VARTYPE_YX)
		{
			if (point < 0 || point >= System.nYX)
				continue;
			data[i].value = ppYX[station][point].yx.value;
			data[i].status = ppYX[station][point].yx.status;
			data[i].rtuflag = ppYX[station][point].yx.rtuflag;
		}
		else if (vtype == VARTYPE_YC)
		{
			if (point < 0 || point >= System.nYC)
				continue;
			data[i].value = ppYC[station][point].yc.value;
			data[i].status = ppYC[station][point].yc.status;
			data[i].rtuflag = ppYC[station][point].yc.rtuflag;
		}
    }
	release_mutex(Mutex_RT);
	return 1;
}

int RPC_GetRealtimeYXData (long *pIDs, PS_rt_yx *data, int n)
{
	int i;
	waitfor_mutex(Mutex_RT);
	for ( i=0; i<n; i++ )
    {
	    int station = GetVarStation(pIDs[i]);
		int point = GetVarPoint(pIDs[i]);
		if (station < 0 || station >= System.nstation)
			continue;
		if (point < 0 || point >= System.nYX)
			continue;
		memcpy(data+i, &ppYX[station][point].yx, sizeof(PS_rt_yx));
    }
	release_mutex(Mutex_RT);
	return 1;
}

int RPC_GetRealtimeYCData (long *pIDs, PS_rt_yc *data, int n)
{
	int i;
	waitfor_mutex(Mutex_RT);
	for (i = 0; i<n; i++)
	{
		int station = GetVarStation(pIDs[i]);
		int point = GetVarPoint(pIDs[i]);
		if (station < 0 || station >= System.nstation)
			continue;
		if (point < 0 || point >= System.nYX)
			continue;
		memcpy(data + i, &ppYC[station][point].yc, sizeof(PS_rt_yc));
	}
	release_mutex(Mutex_RT);

	return 1;
}

int RPC_GetRealtimeYDData (long *pIDs, PS_rt_yd *data, int n)
{
	int i;
	for ( i=0; i<n; i++ )
    {
    	int station = GetVarStation(pIDs[i]);
        if ( station >= 2 && station <= 5 )
			data[i].rtuflag = 1;
        else
        	data[i].rtuflag = 0;

    	data[i].status = random(VARSTATUS_LOWER+1);	//VARSTATUS_NORMAL;
        data[i].value = 1.23*random (1000);
		data[i].dayvalue = 1.23*random (1000);
        data[i].hourvalue = 1.23*random (1000);
        data[i].ffsum = random (100);
        data[i].ggsum = (float)GetVarPoint(pIDs[i]);
    }
	return 1;
}

int RPC_GetDayYXData (char *datetime, long *pIDs, PS_rt_yx *data, int n)
{
	int i;
	for ( i=0; i<n; i++ )
    {
    	data[i].status = random(VARSTATUS_LOWER+1);	//VARSTATUS_NORMAL;
        //data[i].value = random(2);
        data[i].alarmcount = GetVarPoint(pIDs[i]);	//random (100);
    }
	return 1;
}

int RPC_GetDayYCData (char *datetime, long *pIDs, PS_rt_yc *data, int n)
{
	int i;
    PS_rt_yc tmpData;
    tmpData.status = VARSTATUS_NORMAL;
    tmpData.value = 100;
    tmpData.daymax = 300;
    tmpData.daymin = 200;
    tmpData.dayavrg = 80;
    tmpData.okratio = 80;
    tmpData.maxtime = (float)(12*3600);
    tmpData.mintime = (float)(16*3600);
	for ( i=0; i<n; i++ )
    {
    	if ( random(10) )
			memcpy (&data[i], &tmpData, sizeof(PS_rt_yc));
        else
        {
    	data[i].status = random(VARSTATUS_LOWER+1);	//VARSTATUS_NORMAL;
        data[i].value = 1.23*random (10000);
        data[i].daymax = 1.23*random (1000);
        data[i].daymin = 1.23*random (1000);
        data[i].dayavrg = random (100);
        data[i].okratio = random (100);
        data[i].maxtime = (float)(random(24)*3600+random(60)*60+random(60));
        data[i].mintime = (float)(random(24)*3600+random(60)*60+random(60));
        }
        data[i].okratio = (float)GetVarPoint(pIDs[i]);
    }
	return 1;
}

int RPC_GetDayYDData (char *datetime, long *pIDs, PS_rt_yd *data, int n)
{
	int i;
	for ( i=0; i<n; i++ )
    {
    	data[i].status = random(VARSTATUS_LOWER+1);	//VARSTATUS_NORMAL;
        data[i].value = 1.23*random (1000);
		data[i].dayvalue = 1.23*random (1000);
        data[i].hourvalue = 1.23*random (1000);
        data[i].ffsum = random (100);
        data[i].ggsum = (float)GetVarPoint(pIDs[i]);
    }
	return 1;
}

void RPC_ManSetValue (long varID, float value, char *regname)
{
}

void RPC_DontCareValue (long varID, char *regname)
{
}

void RPC_FreshValue (long varID, char *regname)
{
}

void RPC_YKRequest (long varID, float tovalue, char *regname)
{
	
	char infostr[240];
	long vid;
	
	//set_var(VarID_OPER, varID);
	//Var_OPER = tovalue;

	int station = GetVarStation(varID);
	pStation[station].oper_point = GetVarPoint(varID);
	pStation[station].oper_value = tovalue;
	pStation[station].oper_type = GetVarType(varID);

	//vid = get_var(VarID_OPER);
	sprintf(infostr, "RPC_YKRequest：%d (%d, %d) = %.2f", GetVarType(varID), GetVarStation(varID), GetVarPoint(varID), tovalue);
	//SendMessage(g_hMainDlg, UWM_SETDEBUGSTRING, 0, (LPARAM)infostr);
	DebugPrintln(infostr);
}

void RPC_YKConfirm (long varID, float tovalue, char *regname)
{
}

void RPC_YKExecute (long varID, float tostate, char *regname)
{
}

void RPC_RTUReset (long varID, char *regname)
{
}

// 旁路替代
void RPC_SetSide (long varID, long dwP, long dwQ, long dwI, char *regname)
{
}

void RPC_ResetSide (long varID, long dwP, long dwQ, long dwI, char *regname)
{
}

int RPC_GetEventNum (PS_DATE *pDate)
{
	char datafile[256];
	FILE *fp;
   int len;
	sprintf (datafile, ".\\facdata\\%04d%02d%02d.ev", pDate->year, pDate->month, pDate->day);

	fp = fopen(datafile, "rb");
	if (fp == NULL)
		return 0;

	len = filelength(fileno(fp));
	fclose(fp);

	return len <= 0 ? 0 : len / sizeof(ENEVENT);
}

int RPC_LoadEventBase (char *p, int size, PS_DATE *pDate)
{
	int i;
	int n = size/sizeof(ENEVENT);
	ENEVENT *pEvents = (ENEVENT *)p;

	char datafile[256];
	FILE *fp;
	sprintf(datafile, ".\\facdata\\%04d%02d%02d.ev", pDate->year, pDate->month, pDate->day);

	fp = fopen(datafile, "rb");
	if (fp == NULL)
		return 0;

	n = fread(pEvents, sizeof(ENEVENT), n, fp);
	fclose(fp);

	if (n <= 0)
		return 0;

	/*
    for ( i=0; i<n; i++ )
    {
    	memcpy (&pEvents[i].date, pDate, sizeof(PS_DATE));
    	pEvents[i].type = random(NUM_EVENTTYPE);
		pEvents[i].subtype = random(NUM_EVENTSUBTYPE);
		pEvents[i].status = random(2);
		//pEvents[i].fv = 1.1*random(100);
		pEvents[i].time.hour = random(24);
        pEvents[i].time.minute = random(60);
        pEvents[i].time.second = random(60);
		pEvents[i].dtype = random(NUM_VARTYPE);
		pEvents[i].station = 1+random(3);
		pEvents[i].point = 1+random(64);
        strcpy (pEvents[i].note, "note");
		strcpy (pEvents[i].optor, "(未知)");	// 操作者
        pEvents[i].flag = random(2);
    }
	*/

    return n;
}

int RPC_GetVarEventNum (long vid, PS_DATE *pDate)
{
	return random(100);
}

int RPC_LoadVarEventBase (long vid, char *p, int size, PS_DATE *pDate)
{
	int i;
	int n = size/sizeof(ENEVENT);
	ENEVENT *pEvents = (ENEVENT *)p;

    for ( i=0; i<n; i++ )
    {
    	pEvents[i].type = random(2)?EVENTTYPE_OPERATION:EVENTTYPE_ALARM;
		pEvents[i].subtype = random(NUM_EVENTSUBTYPE);
		pEvents[i].status = random(2);
        pEvents[i].dtype = GetVarType(vid);
		pEvents[i].station = GetVarStation(vid);
		pEvents[i].point = GetVarPoint(vid);
		//pEvents[i].fv = 1.1*random(100);
		pEvents[i].time.hour = random(24);
        pEvents[i].time.minute = random(60);
        pEvents[i].time.second = random(60);
        strcpy (pEvents[i].note, "Note");
		strcpy (pEvents[i].optor, "(Uncertain)");	// 操作者
    }

    return n;
}

int RPC_GetRecordNum (long varID, char *datetime0, char *datetime1)
{
	int func = GetVarExtType(varID);
	if (func)
    	return 31;
    else
    {
    	int year0, year1;
        int month0, month1;
        int day0, day1;
        int hour0, hour1;
        int min0, min1;
        int sec0, sec1;
        int t0, t1;

    	sscanf(datetime0, "%02d/%02d/%d %02d:%02d:%02d",
        					&month0, &day0, &year0, &hour0, &min0, &sec0);
        sscanf(datetime1, "%02d/%02d/%d %02d:%02d:%02d",
        					&month1, &day1, &year1, &hour1, &min1, &sec1);

        t0 = 3600*hour0 + 60*min0 + sec0;
        t1 = 3600*hour1 + 60*min1 + sec1;
        if (day0 != day1)
        	t1 += 86400;

        return t1 - t0;
    	//return 86401;
    }
}

int RPC_LoadRecordData (long varID, char *datetime0, char *datetime1,
					PS_BASEDATA *pBasedata, int n)
{
	int func = GetVarExtType(varID);
    int i;

    /*
    DWORD tick0 = GetTickCount();
    while ( GetTickCount()-tick0 < 300) {}
    */

    if ( func )
    {
    	for ( i=0; i<n; i++ )
        {
        	pBasedata[i].day = i+1;
        	pBasedata[i].hour = 0;
            pBasedata[i].minute = 0;
            pBasedata[i].second = 0;
            pBasedata[i].value = 200+random(100);
            pBasedata[i].status = 0;
        }
    }
    else
    {
    	//int day = 10*(datetime0[3]-'0') + (datetime0[4] - '0');
        int year0, year1;
        int month0, month1;
        int day0, day1;
        int hour0, hour1;
        int min0, min1;
        int sec0, sec1;
        int t0, t1;

    	sscanf(datetime0, "%02d/%02d/%d %02d:%02d:%02d",
        					&month0, &day0, &year0, &hour0, &min0, &sec0);
        sscanf(datetime1, "%02d/%02d/%d %02d:%02d:%02d",
        					&month1, &day1, &year1, &hour1, &min1, &sec1);

        t0 = 3600*hour0 + 60*min0 + sec0;

    	for ( i=0; i<n; i++ )
        {
        	pBasedata[i].day = day0;
            pBasedata[i].hour = (t0+i)/3600;	//i/12;
	        pBasedata[i].minute = ((t0+i)%3600)/60;	//5*(i%360);
            pBasedata[i].second = ((t0+i)%3600)%60;//+random(9);
            pBasedata[i].hundsec = random(9);
            pBasedata[i].value = 200+(t0+i)/1000+random(20)-10;
            pBasedata[i].status = 0;
        }
        /*
        pBasedata[i].day = day1;
		pBasedata[i].hour = hour1;
		pBasedata[i].minute = min1;
        pBasedata[i].second = sec1;
        pBasedata[i].hundsec = 9;
		pBasedata[i].value = 200+random(100);
		pBasedata[i].status = 0;
        */
    }

	return n;
}

int RPC_GetPlanRecNum (long varID, char *datetime0, char *datetime1)
{
	return 48;
}

int RPC_LoadPlanRecData (long varID, char *datetime0, char *datetime1,
					PS_BASEDATA *pBasedata, int n)
{
    int i;

   	int day = 10*(datetime0[3]-'0') + (datetime0[4] - '0');
   	for ( i=0; i<n; i++ )
    {
      	pBasedata[i].day = day;
       	pBasedata[i].hour = i/2;
        pBasedata[i].minute = 30*(i%2);
        pBasedata[i].value = 200+random(100);
        pBasedata[i].status = 0;
    }

	return n;
}

float RPC_EvaluateExpression (char *pExpr, int *errcode)
{
	errcode = 0;
	return 100.0;
}

int RPC_LockPage (char *pagefile, char *regname)
{
	return 1;	// OK
}

int RPC_UnlockPage (char *pagefile, char *regname)
{
	return 1;	// OK
}

int RPC_LockVDT (char *regname)
{
	return 1;	// OK
}

int RPC_UnlockVDT (char *regname)
{
	return 1;	// OK
}

int RPC_LockSysParams (char *regname)
{
	return 1;	// OK
}

int RPC_UnlockSysParams (char *regname)
{
	return 1;	// OK
}

int RPC_LockUserList (char *regname)
{
	return 1;	// OK
}

int RPC_UnlockUserList (char *regname)
{
	return 1;	// OK
}

int RPC_LockDatabase (long varID, char *regname)
{
	return 1;	// OK
}

int RPC_UnlockDatabase (long varID, char *regname)
{
	return 1;	// OK
}

int RPC_LockPlanbase (long varID, char *regname)
{
	return 1;	// OK
}

int RPC_UnlockPlanbase (long varID, char *regname)
{
	return 1;	// OK
}

int RPC_LockOperation (long varID, char *regname)
{
	if (get_var(VarID_OPER))
		return 0;

	//set_var(VarID_OPER, GetVarStation(varID));
	return 1;	// OK
}

int RPC_UnlockOperation (long varID, char *regname)
{
	//set_var(VarID_OPER, 0);
	return 1;	// OK
}

int RPC_GetSignalVarNum (char *datetime, long yxvid, int *nrec)
{
	*nrec = 20;
	return 5;
}

int RPC_GetSignalVarID (char *datetime, long yxvid, long *ycvids, int n)
{
	int i;
	for (i=0; i<n; i++ )
    	ycvids[i] = MergeVarID (VARTYPE_YC,1, i+1, 0);

    return n;
}

int RPC_LoadSignalVarData (char *datetime, long yxvid, long ycvid,
						   float *pData, int *pInterval, int nrec)
{
	int i;
    int n31 = nrec/3;
	for ( i=0; i<nrec; i++ )
    {
    	pData[i] = random(100) - 50;
		pInterval[i] = 3*(i-n31);
    }
    
	return nrec;
}

int RPC_LoadPlanningData (long varID, float *pData, int n)
{
	int i;
	for ( i=0; i<n; i++ )
    	pData[i] = random(100);
	return n;
}

int RPC_SetPlanningData (long varID, float *pData, int n)
{
	return n;
}

int RPC_GetUserNum ()
{
	return random(10)+1;
}

static void randomstr (char *str, int len)
{
	int i;
	str[0] = 'A' + random(26);
	for ( i=1; i<len; i++ )
    	str[i] = 'a' + random(26);
    str[len] = 0;
}

int RPC_LoadUserList (PS_USERITEM *pUserItem, int n)
{
	int i;
	for ( i=0; i<n; i++ )
    {
		randomstr (pUserItem[i].computername, random(10)+2);
        randomstr (pUserItem[i].username, random(8)+2);
    }
	return n;
}

int RPC_InsertEvent (char pEvents[], int size)
{
	int n = size/sizeof(ENEVENT);
	ENEVENT *p = (ENEVENT *)pEvents;

    return 1;
}

int RPC_DeleteEvent (char pEvents[], int size)
{
	int n = size/sizeof(ENEVENT);
	ENEVENT *p = (ENEVENT *)pEvents;

    return 1;
}


// end of file -- RPC-funcs.cpp

