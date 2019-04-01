#ifndef _DYNACLIENT_H_
#define _DYNACLIENT_H_


/*函数得到数据点的ID。
dtype:DTYPE_YX,DTYPE_YC分别表示遥信和遥测。
station:表示厂站号。因为只有一个厂站，用1就行。
point:点号从1开始，和点表中的序号一致。
func参数直接用0
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

