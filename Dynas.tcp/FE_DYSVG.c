#include <windows.h>
#include <winsock.h>
//#include <ws2tcpip.h>
#include <stdlib.h>
#include <stdio.h>
#include <dos.h>
//#include <dir.h>
#include "rule_log.h"
#include "pansi.h"    // header file generated by MIDL compiler
#include "panserver2.h"

#define BUFLEN 2048

//static int com_operation(SOCKET sock, long vid, float fv)
static int com_operation(SOCKET sock, int station, int point, int vtype, float fv)
{
	unsigned char sndbuf[BUFLEN];
	unsigned short len_snd;

	//int station = GetVarStation(vid);
	//int point = GetVarPoint(vid);
	//int vtype = GetVarType(vid);

	//if (vid == 0)
	//	return -1;

	memset(sndbuf, 0, BUFLEN);

	sndbuf[0] = sndbuf[1] = 0x68;

	if (vtype == VARTYPE_YX)
	{
		len_snd = 15;
		sndbuf[2] = LOBYTE(len_snd);
		sndbuf[3] = HIBYTE(len_snd);
		sndbuf[4] = sndbuf[5] = 0x01;
		sndbuf[6] = (point - pStation[station].yk_begin)/16;
		sndbuf[7] = (point - pStation[station].yk_begin)%16;
		sndbuf[8] = fv ? 1 : 0;

		sndbuf[13] = sndbuf[14] = 0x86;
	}
	else
	{
		int num_yk = pStation[station].yt_end - pStation[station].yt_begin + 1;
		int i;
      char infostr[256];
      
		len_snd = 4 * num_yk + 14;
		sndbuf[2] = LOBYTE(len_snd);
		sndbuf[3] = HIBYTE(len_snd);
		sndbuf[4] = sndbuf[5] = 0x02;
		sndbuf[6] = LOBYTE(num_yk);
		sndbuf[7] = HIBYTE(num_yk);
		for (i = 0; i < num_yk; i++)
		{
			union {
				float f;
				char c[4];
			} v;
			if (point == pStation[station].yt_begin + i)
				v.f = fv;
			else
				v.f = ppYC[station][pStation[station].yt_begin+i].yc.value;

			sndbuf[8 + 4 * i] = v.c[0];
			sndbuf[8 + 4 * i + 1] = v.c[1];
			sndbuf[8 + 4 * i + 2] = v.c[2];
			sndbuf[8 + 4 * i + 3] = v.c[3];
		}
		sndbuf[4*num_yk + 12] = sndbuf[4*num_yk + 13] = 0x86;

		sprintf(infostr, "YK (%d, %d)\n", num_yk, point);
		//SendMessage(g_hMainDlg, UWM_SETDEBUGSTRING, 0, (LPARAM)infostr);
		DebugPrintln(infostr);
	}

	if (send(sock, sndbuf, len_snd, 0) == SOCKET_ERROR)
	{
		//sprintf(infostr, "Opearation send failed. Error#%d\n", WSAGetLastError());
		//SendMessage(g_hMainDlg, UWM_SETDEBUGSTRING, 0, (LPARAM)infostr);
		//set_var(VarID_OPER, 0);
		return -1;
	}
	WriteLog_Tele(station,sndbuf,len_snd,0);
	//recv(sock, sndbuf, BUFLEN, 0);

	return 0;
}


int WINAPI Routine_DY_SVG(int station)
{
	ppYX[station][0].yx.value = 0;
	SOCKET ConnectSocket;	// = INVALID_SOCKET;
							//struct addrinfo *result = NULL, hints;
	struct sockaddr_in addr;
	struct timeval timeout;
	int iResult;
	char *ipstr;

	char infostr[240];
	char datafile[256];

	if (pStation[station].addr1[0] == 0 && pStation[station].addr2[0] == 0 && pStation[station].port == 0)
	{
		sprintf(infostr, "station(%d): 地址错误 (%s, %s, %d)\n", station,
			pStation[station].addr1, pStation[station].addr2, pStation[station].port);
		//SendMessage(g_hMainDlg, UWM_SETDEBUGSTRING, 0, (LPARAM)infostr);
		DebugPrintln(infostr);
		return -1;
	}

	ipstr = pStation[station].addr2[0] ? pStation[station].addr2 : pStation[station].addr1;		


	sprintf(datafile, ".\\facdata\\Lastvalues_%d.dat", station);

	sprintf(infostr, "#%d线程启动", station);

	//SendMessage(g_hMainDlg, UWM_SETDEBUGSTRING, 0, (LPARAM)infostr);
	DebugPrintln(infostr);

	//set_var(Flag_FER, 1);	
	inc_var(Count_FER);
	while (get_var(Flag_FER))
	{
		int fComStateChange;

		pStation[station].oper_point = 0;  //set_var(VarID_OPER, 0);
		fComStateChange = 0;

		// Connect to server.
		// Create a SOCKET for connecting to server
		ConnectSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
		if (ConnectSocket == INVALID_SOCKET) {
			sprintf(infostr, "station(%d): socket failed (%ld)", station, WSAGetLastError());
			//SendMessage(g_hMainDlg, UWM_SETDEBUGSTRING, 0, (LPARAM)infostr);
			DebugPrintln(infostr);
			return -1;
		}

		// 设置连接超时时间
		timeout.tv_sec = 5;
		timeout.tv_usec = 0;
		setsockopt(ConnectSocket, SOL_SOCKET, SO_RCVTIMEO, (char *)&timeout, sizeof(timeout));
		setsockopt(ConnectSocket, SOL_SOCKET, SO_SNDTIMEO, (char *)&timeout, sizeof(timeout));

		addr.sin_family = AF_INET;
		addr.sin_port = htons(pStation[station].port);
		
		if (ipstr == pStation[station].addr1)
		{
			if (pStation[station].addr2[0])
				ipstr == pStation[station].addr2;
		}
		else
		{
			if (pStation[station].addr1[0])
				ipstr == pStation[station].addr1;
		}
		addr.sin_addr.s_addr = inet_addr(ipstr);

		//sprintf(infostr, "#%d连接:%s", station, ipstr);
		//SendMessage(g_hMainDlg, UWM_SETDEBUGSTRING, 0, (LPARAM)infostr);

		iResult = connect(ConnectSocket, (SOCKADDR*)&addr, sizeof(addr));
		if (iResult == SOCKET_ERROR) // 通道连接失败
		{
			closesocket(ConnectSocket);
			ConnectSocket = SOCKET_ERROR;

			if (ppYX[station][0].yx.value == 1)
			{
				//FILE *fp;
				
				waitfor_mutex(Mutex_RT);

				ppYX[station][0].yx.value = 0;
				
				release_mutex(Mutex_RT);

				sprintf(infostr, "#%d站连接中断!", station);
				WriteLog(station, "#%d站连接中断!\r\n");
				//SendMessage(g_hMainDlg, UWM_SETDEBUGSTRING, 0, (LPARAM)infostr);
				DebugPrintln(infostr);
			}

			Sleep(100);
			continue;
		}
		else	// 通道连接成功
		{
			sprintf(infostr, "#%d站连接成功!", station);
			WriteLog(station, "#%d站连接成功!\r\n");
			//SendMessage(g_hMainDlg, UWM_SETDEBUGSTRING, 0, (LPARAM)infostr);
			DebugPrintln(infostr);

			waitfor_mutex(Mutex_RT);
			if (ppYX[station][0].yx.value == 0)
			{
				fComStateChange = 1;
				ppYX[station][0].yx.value = 1;
			}
			release_mutex(Mutex_RT);
		}

		while (get_var(Flag_FER))
		{
			unsigned char sndbuf[BUFLEN];
			unsigned char rcvbuf[BUFLEN];
			int len_snd, len_rcv;
			unsigned int n_yx, n_yc, n_event;
			unsigned int yx_offset, yc_offset, event_offset;
			unsigned int end_offset;

			union {
				float f;
				char c[4];
			} fv;

			int i;
			int vid_oper;

			struct EVENTNO {
				unsigned short fault_no;
				unsigned short info_no;
			} *confirm_events;

			/* 
			vid_oper = get_var(VarID_OPER);
			if (0)		//vid_oper)
			{
				sprintf(infostr, "Station %d, YK：%04X", GetVarStation(vid_oper), pStation[station].oper_value);	//Var_OPER);
				SendMessage(g_hMainDlg, UWM_SETDEBUGSTRING, 0, (LPARAM)infostr);
			}
			*/
			//if (vid_oper && GetVarStation(vid_oper) == station)
			if (pStation[station].oper_point > 0)
			{
				int point = pStation[station].oper_point;	//GetVarPoint(vid_oper);
				int vtype = pStation[station].oper_type;	//GetVarType(vid_oper);

				sprintf(infostr, "控制操作：%s (%d, %d) = %.2f", vtype == VARTYPE_YC ? "遥调" : "遥控", station, point, pStation[station].oper_value);	//Var_OPER);
				//SendMessage(g_hMainDlg, UWM_SETDEBUGSTRING, 0, (LPARAM)infostr);
				DebugPrintln(infostr);

				//com_operation(ConnectSocket, vid_oper, Var_OPER);
				com_operation(ConnectSocket, station, point, vtype, pStation[station].oper_value);	//Var_OPER);

				pStation[station].oper_point = 0;  //set_var(VarID_OPER, 0);
			}

			if (fComStateChange)
			{
				fComStateChange = 0;

				// 【连接成功后代码在此】。。。
			}

			iResult = recv(ConnectSocket, rcvbuf, BUFLEN, 0);
			if (iResult == SOCKET_ERROR)
			{
				sprintf(infostr, "SOCKET_ERROR recv()返回 %d, WSAGetLastError() = %d", iResult, WSAGetLastError());
				DebugPrintln(infostr);
				WriteLog(station, "SOCKET_ERROR recv()返回0\r\n");
				ppYX[station][0].yx.value = 0;
				closesocket(ConnectSocket);
				Sleep(2000);
				//printf("send failed with error: %d\n", WSAGetLastError());
				break;
			}
			//if (iResult < 22)
			//{
			//	Sleep(10);
			//	continue;
			//}

			len_rcv = iResult;
			if (len_rcv == 0)
			{
				sprintf(infostr, "对端关闭连接，recv()返回 %d, WSAGetLastError() = %d", len_rcv, WSAGetLastError());
				WriteLog(station, "对端关闭连接，recv()返回0\r\n");
				//sprintf(infostr, "接受：(%d, %d，%d，%d, %d)", yx_offset, yc_offset, event_offset, n_event, end_offset);
				//SendMessage(g_hMainDlg, UWM_SETDEBUGSTRING, 0, (LPARAM)infostr);
				DebugPrintln(infostr);

				ppYX[station][0].yx.value = 0;
				closesocket(ConnectSocket);
				Sleep(2000);
				break;
			}
			
			WriteLog_Tele(station, rcvbuf, len_rcv, 1);

// 			printf("len_rcv = %d ", len_rcv);
// 			for (int i = 0; i < len_rcv; i++)
// 			{
// 				printf("%02x ", rcvbuf[i]);
// 			}
// 			printf("\n");
			end_offset = len_rcv - 4;
			yx_offset = rcvbuf[4] + 256 * rcvbuf[5];
			yc_offset = rcvbuf[6] + 256 * rcvbuf[7];

			event_offset = rcvbuf[8] + 256 * rcvbuf[9];
			n_event = rcvbuf[10] + 256 * rcvbuf[11];

			if (event_offset)
				end_offset = event_offset;

			if (yc_offset)
			{
				n_yc = (end_offset - yc_offset) / 4;
				end_offset = yc_offset;
			}
			if (yx_offset)
			{
				n_yx = (end_offset - yx_offset)*16;
				end_offset = yx_offset;
			}

			waitfor_mutex(Mutex_RT);

			for (i = 0; i < n_yx; i++)
			{
				unsigned short c;				
				short new_value;

				if (i >= System.nYX - 1)
					break;

				c = rcvbuf[yx_offset + 2*(i / 16)] + 256 * rcvbuf[yx_offset + 2*(i / 16) + 1];
				//new_value = (c<<(i%16)) & 0x8000U ? 1 : 0;
				new_value = (c>>(i%16)) & 0x0001U ? 1 : 0;

				if (new_value == ppYX[station][i + 1].yx.value)
					continue;
				ppYX[station][i + 1].yx.value = new_value;
			}
			for (i = 0; i < n_yc; i++)
			{
				if (i >= System.nYC - 1)
					break;
				fv.c[0] = rcvbuf[yc_offset + 4 * i];
				fv.c[1] = rcvbuf[yc_offset + 4 * i + 1];
				fv.c[2] = rcvbuf[yc_offset + 4 * i + 2];
				fv.c[3] = rcvbuf[yc_offset + 4 * i + 3];
				ppYC[station][i + 1].yc.value = fv.f;
			}

			release_mutex(Mutex_RT);

			// 处理事件
			confirm_events = NULL;
			if (n_event)
				confirm_events = (struct EVENTNO *)malloc(sizeof(struct EVENTNO)*n_event);
			for (i = 0; i < n_event; i++)
			{
				struct SOE_DATA {
					unsigned char TYP;
					unsigned char NUM;
					unsigned char COT;
					unsigned char ADDR;
					unsigned char FUNC;
					unsigned char INF;
					unsigned char ST;
					unsigned char msL1;
					unsigned char msL2;
					unsigned char msH1;
					unsigned char msH2;
					unsigned char FANL;
					unsigned char FANH;
					unsigned char msL;
					unsigned char msH;
					unsigned char min;
					unsigned char hour;
					unsigned char day;
					unsigned char mon;
					unsigned char year;
					unsigned char SIN;
					unsigned char FLTTYP;
				} SOE_data;

				int num_fv;
				struct date d;
				struct time t;
				unsigned short ms, ms_1, ms_2;
				ENEVENT event;

				//int j;

				memcpy(&SOE_data, rcvbuf + event_offset, 22);
				num_fv = SOE_data.NUM - 1;
				event_offset += 22 + num_fv * 4;

				memset(&event, 0, sizeof(ENEVENT));

				event.type = EVENTTYPE_ALARM;
				if (SOE_data.TYP == 70)
					event.subtype = EVENTSUBTYPE_SIGNAL;
				else
					event.subtype = EVENTSUBTYPE_SOE;
				event.status = SOE_data.ST ? EVENTSTATUS_SOE1 : EVENTSTATUS_SOE0;

				event.dtype = VARTYPE_YX;
				event.station = station;
				event.point = SOE_data.INF;

				getdate(&d);
				event.date.year = d.da_year;
				event.date.day = d.da_day;
				event.date.month = d.da_mon;
				gettime(&t);
				event.time.hour = t.ti_hour;
				event.time.minute = t.ti_min;
				event.time.second = t.ti_sec;
				event.time.hundsec = t.ti_hund;

				ms = SOE_data.msH * 256 + SOE_data.msL;
				ms_1 = SOE_data.msH1 * 256 + SOE_data.msL1;
				ms_2 = SOE_data.msH2 * 256 + SOE_data.msL2;

				d.da_year = SOE_data.year;
				d.da_mon = SOE_data.mon;
				d.da_day = SOE_data.day;

				t.ti_hour = SOE_data.hour;
				t.ti_min = SOE_data.min;
				t.ti_sec = ms / 1000;

				ms = ms % 1000;
				ms_1 = ms_1 % 1000;
				ms_2 = ms_2 % 1000;

				if (SOE_data.TYP == 70)
				{
					sprintf(event.note, "%02u:%2u:%02u/%03u,%03u", t.ti_hour, t.ti_min, t.ti_sec, ms_1, ms_2);
					sprintf(infostr, "保护动作：(%d, %d) (%d) [%d]", station, event.point, SOE_data.ST, num_fv);
				}
				else
				{
					sprintf(event.note, "%02u:%2u:%02u.%03u", t.ti_hour, t.ti_min, t.ti_sec, ms);
					sprintf(infostr, "SOE事件：(%d, %d) (%d)", station, event.point, SOE_data.ST);
				}
				//SendMessage(g_hMainDlg, UWM_SETDEBUGSTRING, 0, (LPARAM)infostr);
				DebugPrintln(infostr);

				waitfor_mutex(Mutex_EVENT);
				memcpy(pEventBuf + Num_Event, &event, sizeof(ENEVENT));
				Num_Event++;
				if (Num_Event == MAXNUM_EVENT)
					memcpy(pEventBuf, pEventBuf + 1, sizeof(ENEVENT)*(Num_Event - 1));
				release_mutex(Mutex_EVENT);

				confirm_events[i].fault_no = SOE_data.FANL + 256 * SOE_data.FANH;
				confirm_events[i].info_no = SOE_data.INF + 256 * SOE_data.FUNC;
			}

			if (confirm_events)
			{
				len_snd = 4 * n_event + 14;
				memset(sndbuf, 0, len_snd);
				sndbuf[0] = sndbuf[1] = 0x68;
				sndbuf[2] = LOBYTE(len_snd);
				sndbuf[3] = HIBYTE(len_snd);
				sndbuf[4] = sndbuf[5] = 0x03;
				sndbuf[6] = LOBYTE(n_event);
				sndbuf[7] = HIBYTE(n_event);
				for (i = 0; i < n_event; i++)
				{
					sndbuf[8+4*i]   = LOBYTE(confirm_events[i].fault_no);
					sndbuf[8+4*i+1] = HIBYTE(confirm_events[i].fault_no);
					sndbuf[8+4*i+2] = LOBYTE(confirm_events[i].info_no);
					sndbuf[8+4*i+3] = HIBYTE(confirm_events[i].info_no);
				}
				sndbuf[len_snd-2] = sndbuf[len_snd-1] = 0x86;
				free(confirm_events);
				//if (send(ConnectSocket, sndbuf, len_snd, 0) == SOCKET_ERROR)
				{
					// do nothing
				}
			}

			Sleep(200);
		}

		Sleep(10);
	}

	if (ConnectSocket != SOCKET_ERROR)
		closesocket(ConnectSocket);

	sprintf(infostr, "#%d线程结束", station);
	//SendMessage(g_hMainDlg, UWM_SETDEBUGSTRING, 0, (LPARAM)infostr);
	DebugPrintln(infostr);

	//set_var(Flag_FER, -1);
	dec_var(Count_FER);

	return 0L;
}