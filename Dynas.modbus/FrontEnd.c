#define    WIN32_LEAN_AND_MEAN
#include <windows.h>
#include <winsock2.h>
//#include <ws2tcpip.h>
#include <stdlib.h>
#include <stdio.h>
#include <dos.h>
//#include <dir.h>

#include "pansi.h"    // header file generated by MIDL compiler
#include "panserver2.h"

// Need to link with Ws2_32.lib, Mswsock.lib, and Advapi32.lib
#pragma comment (lib, "Ws2_32.lib")
#pragma comment (lib, "Mswsock.lib")
//#pragma comment (lib, "AdvApi32.lib")

//==========================================================================
// ���ݲɼ��߳�
//==========================================================================

int WINAPI FrontEndSetup()
{
	int npoint;
	int size;
	int i, j;
	char profstr[256];
	char keystr[256];
	char *p;

	WSADATA wsaData;

	// System
	//
	strcpy(System.name, "ϵͳ");

	System.nstation = GetPrivateProfileInt("system", "nstation", 1, GetIniFileName()) + 1; 	// ��һ���鳧 system�ǽڣ�nstation�Ǽ�

	System.nYX = GetPrivateProfileInt("system", "nYX", 512, GetIniFileName()) + 1;	   	// ��һ��V��
	System.nYC = GetPrivateProfileInt("system", "nYC", 256, GetIniFileName()) + 1;	   	// ��һ��V��
	System.nYD = GetPrivateProfileInt("system", "nYD", 64, GetIniFileName()) + 1;    	// ��һ��V��
	System.nYT = GetPrivateProfileInt("system", "nYT", 20, GetIniFileName()) + 1;

	System.nCON = System.nYX;
	System.nCAL = System.nYC;
	System.nCUM = System.nYD;

	System.samplerate = 5;	// minute
	System.ykTimeout = 30; 	// sec

	strcpy(System.HomePage, "_index.xpf");

	// Stations
	//
	size = System.nstation * sizeof(EN_sstation);
	pStation = (EN_sstation *)malloc(size);
	if (pStation == NULL)
	{
		//MessageBox(g_hMainDlg, "Cannot allocate for Station.", "Error", MB_OK | MB_ICONERROR);
		DebugPrintln("ERROR: Cannot allocate for Station.");
		return -1;
	}

	memset(pStation, 0, size);

	for (i = 0; i < System.nstation; i++)
	{
		if (i)
		{
			char keyname[21];
			sprintf(keyname, "station_%d", i);
			GetPrivateProfileString("station", keyname, "", profstr, 256, GetIniFileName());

			p = GetSubString(profstr, 1);
			if (*p)
				strncpy(pStation[i].name, p, MAXSTATIONNAME);     //վ��
			else
				sprintf(pStation[i].name, "�� %d վ",   i);

			p = GetSubString(profstr, 2);
			strncpy(pStation[i].protocol, p, MAXSTATIONNAME);    //��Լ����

			p = GetSubString(profstr, 3);
			pStation[i].slaveAddr = atoi(p);

			p = GetSubString(profstr, 4);
			strncpy(pStation[i].devName, p, 32);

			p = GetSubString(profstr, 5);
			pStation[i].baud = atoi(p);

			p = GetSubString(profstr, 6);
			pStation[i].dataBits = atoi(p);

			p = GetSubString(profstr, 7);
			pStation[i].stopBits = atoi(p);

			p = GetSubString(profstr, 8);
			pStation[i].parity = *p;

			p = GetSubString(profstr, 9);
			pStation[i].yk_begin = atoi(p);

			p = GetSubString(profstr, 10);
			pStation[i].yk_end = atoi(p);

			p = GetSubString(profstr, 11);
			pStation[i].yt_begin = atoi(p);

			p = GetSubString(profstr, 12);
			pStation[i].yt_end = atoi(p);


			//p = GetSubString(profstr, 3);                        
			//strncpy(pStation[i].addr1, p, 16);                   //IP_1
			//p = GetSubString(profstr, 4);						 
			//strncpy(pStation[i].addr2, p, 16);                  //IP_2

			//p = GetSubString(profstr, 5);                        
			//pStation[i].port = atoi(p);                         //�˿ں�

			//p = GetSubString(profstr, 6);
			//pStation[i].yk_begin = atoi(p);					
			//p = GetSubString(profstr, 7);
			//pStation[i].yk_end = atoi(p);

			//p = GetSubString(profstr, 8);
			//pStation[i].yt_begin = atoi(p);
			//p = GetSubString(profstr, 9);
			//pStation[i].yt_end = atoi(p);

			//p = GetSubString(profstr, 10);
			//strncpy(pStation[i].pagefile, p, PS_MAXFILENAME);
		}
		else
			strcpy(pStation[i].name, "[�����]");
	}

	// YX
	//
	ppYX = (EN_yyx **)malloc(System.nstation * sizeof(EN_yyx *));
	for (i = 0; i < System.nstation; i++)
	{
		npoint = i ? System.nYX : System.nCON;
		size = npoint * sizeof(EN_yyx);
		ppYX[i] = (EN_yyx *)malloc(size);

		memset(ppYX[i], 0, size);    		// reset

		for (j = 0; j < npoint; j++)
		{
			if (i)
			{
				if (j)
				{
					char defname[41];
					char keyname[41];
					sprintf(defname, "YX_%d_%04d", i, j);
					sprintf(keyname, "YX_%d_%d", i, j);
					//GetPrivateProfileString("point", keyname, defname, ppYX[i][j].name, 41, GetIniFileName());

					GetPrivateProfileString("point", keyname, "", keystr, 256, GetIniFileName());

					p = GetSubString(keystr, 1);
					strncpy(ppYX[i][j].name, p, 41);

					p = GetSubString(keystr, 2);
					ppYX[i][j].addr = strtol(p, NULL, 16);

					//sprintf(ppYX[i][j].name, "YX%d, %04d", station - 1, i - 1);
				}
				else
					strcpy(ppYX[i][j].name, "ͨ��״̬");
			}
			else	// station == 0
			{
				if (j)
					sprintf(ppYX[i][j].name, "CON, %04d", j);
				else
					strcpy(ppYX[i][j].name, "����״̬");
			}
			ppYX[i][j].alevel = 3;
			ppYX[i][j].ykno = j;
			ppYX[i][j].flag.fAlarmCount = 1;
		}
	}

	// YC
	//
	ppYC = (EN_yyc **)malloc(System.nstation * sizeof(EN_yyc *));
	for (i = 0; i < System.nstation; i++)
	{
		npoint = (i ? System.nYC : System.nCAL);
		size = npoint * sizeof(EN_yyc);
		ppYC[i] = (EN_yyc *)malloc(size);

		memset(ppYC[i], 0, size);    		// reset

		for (j = 0; j < npoint; j++)
		{
			if (i)
			{
				if (j)
				{
					char defname[41];
					char keyname[41];
					sprintf(defname, "YC_%d_%04d", i, j);
					sprintf(keyname, "YC_%d_%d", i, j);
					//GetPrivateProfileString("point", keyname, defname, ppYC[i][j].name, 41, GetIniFileName());
					GetPrivateProfileString("point", keyname, "", keystr, 256, GetIniFileName());

					p = GetSubString(keystr, 1);
					strncpy(ppYC[i][j].name, p, 41);

					p = GetSubString(keystr, 2);
					ppYC[i][j].addr = strtol(p, NULL, 16);
					//sprintf (ppYC[i][j].name, "YC%d, %04d", station-1, i-1);
				}

				else
					strcpy(ppYC[i][j].name, "ͨ������");
			}
			else	// station == 0
			{
				if (j)
					sprintf(ppYC[i][j].name, "CAL, %04d", j);
				else
					strcpy(ppYC[i][j].name, "ͨ��������");
			}
			ppYC[i][j].precision = 2;
			ppYC[i][j].alevel = 2;
			ppYC[i][j].k = 1;

			ppYC[i][j].flog = 1;
			ppYC[i][j].fplan = 1;
			ppYC[i][j].fcache = 1;

			ppYC[i][j].flag.fMax = 1;
			ppYC[i][j].flag.fMin = 1;
			ppYC[i][j].flag.fAvrg = 1;
			ppYC[i][j].flag.fMaxTime = 1;
			ppYC[i][j].flag.fMinTime = 1;
			ppYC[i][j].flag.fRatio = 1;
		}
	}

	// YD
	//
	ppYD = (EN_yyd **)malloc(System.nstation * sizeof(EN_yyd *));
	for (i = 0; i < System.nstation; i++)
	{
		size = (i ? System.nYD : System.nCUM) * sizeof(EN_yyd);
		ppYD[i] = (EN_yyd *)malloc(size);
	}

	// YT
	//
	ppYT = (EN_yyt **)malloc(System.nstation * sizeof(EN_yyt *));
	for (i = 0; i < System.nstation; i++)
	{
		size = System.nYT * sizeof(EN_yyt);
		ppYT[i] = (EN_yyt *)malloc(size);
	}

#ifdef INITVALUES
	// YX YC ��ʼֵ
	for (i = 1; i < System.nstation; i++)
	{
		char datafile[256];
		FILE *fp;
		int j;

		sprintf(datafile, ".\\facdata\\Lastvalues_%d.dat", i);

		fp = fopen(datafile, "rb");
		if (fp)
		{
			for (j = 1; j < System.nYX; j++)
			{
				short sv;
				if (fread(&sv, sizeof(short), 1, fp) <= 0)
					break;
				ppYX[i][j].yx.value = sv;
			}
			for (j = 1; j < System.nYC; j++)
			{
				float fv;
				if (fread(&fv, sizeof(float), 1, fp) <= 0)
					break;
				ppYC[i][j].yc.value = fv;
			}
			fclose(fp);
		}
	}
#endif // INITVALUES

	create_mutex(Mutex_RT);

	init_var(Flag_FER, 1);
	init_var(Count_FER, 0);
	init_var(VarID_OPER, 0);

	create_mutex(Mutex_EVENT);

	// Initialize Winsock
	if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0)
	{
		//MessageBox(g_hMainDlg, "WSAStartup ����ʧ�ܣ�", "Error", MB_OK | MB_ICONERROR);
		DebugPrintln("ERROR: WSAStartup ����ʧ�ܣ�");
		return -1;
	}

	return 0;
}



LRESULT WINAPI FrontEndRoutine(LPVOID lp)
{
	int station = (int)lp;
	char *protocol = pStation[station].protocol;
	if (station == 0)
		Routine_Virtual();
	//else if (stricmp(protocol, "XD_FK") == 0)
	//	Routine_XD_FK(station);
	//else if (stricmp(protocol, "DY_SVG") == 0)
	//	Routine_DY_SVG(station);
	else if (stricmp(protocol, "DY_MODBUS") == 0)
		Routine_DY_MODBUS(station);

	return 0L;
}


void WINAPI FrontEndCleanup()
{
	int i;

	set_var(Flag_FER, 0);
	for (i = 0; i < 20; i++)
	{
		if (get_var(Count_FER) == 0)
			break;
		Sleep(100);
	}

	if (ppYX)
	{
		for (i = 0; i < System.nstation; i++)
			if (ppYX[i])	free(ppYX[i]);
		free(ppYX);
	}
	if (ppYC)
	{
		for (i = 0; i < System.nstation; i++)
			if (ppYC[i])	free(ppYC[i]);
		free(ppYC);
	}
	if (ppYD)
	{
		for (i = 0; i < System.nstation; i++)
			if (ppYD[i])	free(ppYD[i]);
		free(ppYD);
	}
	if (ppYT)
	{
		for (i = 0; i < System.nstation; i++)
			if (ppYT[i])	free(ppYT[i]);
		free(ppYT);
	}
	if (pStation)
		free(pStation);

	close_mutex(Mutex_RT);
	close_var(Flag_FER);
	close_var(Count_FER);
	close_var(VarID_OPER);

	close_mutex(Mutex_EVENT);

	WSACleanup();

	return;
}