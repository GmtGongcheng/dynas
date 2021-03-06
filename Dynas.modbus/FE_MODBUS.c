#define    WIN32_LEAN_AND_MEAN
#include <windows.h>
#include <winsock2.h>
//#include <ws2tcpip.h>
#include <stdlib.h>
#include <stdio.h>
#include <dos.h>
//#include <dir.h>
#include "modbus.h"
//#include "mod_common.h"
#include "pansi.h"    // header file generated by MIDL compiler
#include "panserver2.h"

#define BUFLEN 2048

//static int com_operation(SOCKET sock, long vid, float fv)
static int com_operation(modbus_t * ctx, int station, int point, int vtype, float fv)
{
	int ret = -1;

	//int station = GetVarStation(vid);
	//int point = GetVarPoint(vid);
	//int vtype = GetVarType(vid);

	//if (vid == 0)
	//	return -1;


	if (vtype == VARTYPE_YX)
	{
		ret = modbus_write_bit(ctx, ppYX[station][point].addr, 0xFF00);
	}
	else
	{
		uint16_t data16_YT[256];
		if (point == 195)
		{
			if (fv > 0)
			{
				data16_YT[0] = (unsigned short)(65536 - 100 * fv);

			}
			else
			{
				data16_YT[0] = (unsigned short)(-100 * fv);
			}

		}
		else if (point == 196)
		{
			data16_YT[0] = (unsigned short)(fv * 100);
		}
		else
		{
			data16_YT[0] = (unsigned short)fv;

		}

		ret = modbus_write_registers(ctx, ppYC[station][point].addr, 1, data16_YT);
	}
	return 0;
}

int WINAPI Routine_DY_MODBUS(int station)
{
	int debug = 1;
	modbus_t * ctx = modbus_new_rtu(pStation[station].devName, pStation[station].baud,
		pStation[station].parity, pStation[station].dataBits, pStation[station].stopBits);

 	modbus_set_debug(ctx, debug);
	modbus_set_slave(ctx, pStation[station].slaveAddr);

	//issue the request
	int ret = -1;
	if (modbus_connect(ctx) == -1)
	{
		fprintf(stderr, "Connection failed: %s\n",
			modbus_strerror(errno));
		modbus_free(ctx);
		return -1;
	}
	else
	{
		ppYX[station][0].yx.value = 1;
		while (1)
		{
			char infostr[240];
			if (pStation[station].oper_point > 0)
			{
				int point = pStation[station].oper_point;	//GetVarPoint(vid_oper);
				int vtype = pStation[station].oper_type;	//GetVarType(vid_oper);

				sprintf(infostr, "控制操作：%s (%d, %d) = %.2f", vtype == VARTYPE_YC ? "遥调" : "遥控", station, point, pStation[station].oper_value);	//Var_OPER);
				//SendMessage(g_hMainDlg, UWM_SETDEBUGSTRING, 0, (LPARAM)infostr);
				DebugPrintln(infostr);

				//com_operation(ConnectSocket, vid_oper, Var_OPER);
				com_operation(ctx, station, point, vtype, pStation[station].oper_value);	//Var_OPER);

				pStation[station].oper_point = 0;  //set_var(VarID_OPER, 0);

			}
			//YC
			int n = 1;
			int indexYC = 0;//循环次数
			//int ncountYC = pStation[station].yt_begin - 1;
			int ncountYC = 190;
			int ncountYX = pStation[station].yk_begin - 1;
			if (ncountYC % 44)
			{
				indexYC = ncountYC / 44 + 1;
			}
			else
			{
				indexYC = ncountYC / 44;
			}


			for (int i = 1; i <= indexYC; i++)
			{
				uint16_t data16_YC[256];
				if (n + 44 > ncountYC + 1)
				{
					ret = modbus_read_registers(ctx, ppYC[station][n].addr, ncountYC % 44, data16_YC);
					for (int j = 0; j < ncountYC % 44; j++)
					{
						ppYC[station][n].yc.value = ppYC[station][n].k * data16_YC[j] + ppYC[station][n].b;
// 						printf("%d:%lf\n", n, ppYC[station][n].yc.value);
						n++;
					}

					Sleep(250);
					ret = modbus_read_registers(ctx, ppYC[station][191].addr, 3, data16_YC);

					ppYC[station][191].yc.value = data16_YC[0];
					if (data16_YC[1] > 32768)
					{
						ppYC[station][192].yc.value = (65536 - (data16_YC[1])) * 0.01;
					}
					else
					{
						ppYC[station][192].yc.value = -data16_YC[1];
					}
					ppYC[station][193].yc.value = data16_YC[2] * 0.01;
					i++;
					Sleep(250);
				}
				else
				{
					ret = modbus_read_registers(ctx, ppYC[station][n].addr, 44, data16_YC);
					for (int j = 0; j < 44; j++)
					{
						ppYC[station][n].yc.value  = ppYC[station][n].k * data16_YC[j] + ppYC[station][n].b;
// 						printf("%d:%lf\n", n, ppYC[station][n].yc.value);
						n++;

					}
				}
				Sleep(250);
			}

			//YX
 			uint16_t data16_YX[256];
 			ret = modbus_read_input_registers(ctx, ppYX[station][1].addr, ncountYX / 16, data16_YX);
 			for (int i = 0; i < ret; i++)
 			{
				for (int j = 0; j < 16;  j++)
				{
					ppYX[station][16 * i + j + 1].yx.value = (data16_YX[i] >> (j % 16)) & 0x0001u ? 1 : 0;
				}
 			}
 			Sleep(250);
		}
	}
	modbus_close(ctx);
	modbus_free(ctx);
	return 0L;
}