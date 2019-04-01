#ifndef _DYNACLIENT_H_
#define _DYNACLIENT_H_


/*�����õ����ݵ��ID��
dtype:DTYPE_YX,DTYPE_YC�ֱ��ʾң�ź�ң�⡣
station:��ʾ��վ�š���Ϊֻ��һ����վ����1���С�
point:��Ŵ�1��ʼ���͵���е����һ�¡�
func����ֱ����0
*/
DWORD MergeVarID(int dtype, int station, int point, int func)
{
	return MAKELONG((point & 0x0fff) | ((func << 12) & 0xf000),
		(station & 0x0fff) | ((dtype << 12) & 0xf000));
}
//void  SplitVarID (DWORD varID, int &dtype, int &station,
//									 int &point, int &func);
int   GetVarType (DWORD varID);
int   GetVarExtType (DWORD varID);
int   GetVarStation (DWORD varID);
int   GetVarPoint (DWORD varID);

#endif  // #ifndef _DYNACLIENT_H_

