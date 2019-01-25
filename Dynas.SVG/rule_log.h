#ifndef _RULE_LOG_H
#define _RULE_LOG_H

#include <stdlib.h>
#include <stdio.h>
#include <windows.h>


typedef struct BaseFileInfoR
	{
	char* fileName;
	SYSTEMTIME  createTime;
	SYSTEMTIME modifyTime;
	int size;
}BaseFileInfo;

enum DCOReturnCode
	{
	DCO_SUCCESS=0,							//调用成功
	DCO_FileErr,				//文件错误
	DCO_NoSuchFile,				//文件不存在
	DCO_Filter_Invalid,			//文件扩展名格式无效
	};

typedef struct logInfoStructR
	{
	char * logString;
	float val;
	int linkID;
}logInfoStruct;

	
	//char buf[256];
	char log_err_str[256];
	
	FILE * m_p_log_fp;//指向当前日志、报文记录文件的指针

	/*获取文件信息
	dir:		目录,不含后斜线,如"./page"
	fileName:	文件名,不含路径,如"report.xml"
	fileInfo: 文件信息
	*/
	extern int GetFileInfo(const char *dir, const char *fileName, BaseFileInfo* fileInfo);

	//复制文件,文件名含全路径
	extern int CopyFile_Log(char *fileNameS,char *fileNameD);


	/*删除文件
	dir:			目录,不含后斜线,如"./page"
	fileName:		文件名
	*/
	extern int DelFile(char *dir, char *fileName);

	extern void GetCurTime(SYSTEMTIME *systime);
	
		
	//extern void WriteLog(int link_ID, struct logInfoStruct logInfo);
	extern void WriteLog(int link_ID, char* logStr);
	extern void WriteLog_Tele(int link_ID, unsigned char *buf, unsigned int byte2, int bRecv);//存报文到文件
	
	extern void WriteTele_to_Console(int link_ID, unsigned char *buf, unsigned int byte2, int bRecv);

#endif