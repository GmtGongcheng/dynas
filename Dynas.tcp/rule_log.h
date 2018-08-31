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
	DCO_SUCCESS=0,							//���óɹ�
	DCO_FileErr,				//�ļ�����
	DCO_NoSuchFile,				//�ļ�������
	DCO_Filter_Invalid,			//�ļ���չ����ʽ��Ч
	};

typedef struct logInfoStructR
	{
	char * logString;
	float val;
	int linkID;
}logInfoStruct;

	
	//char buf[256];
	char log_err_str[256];
	
	FILE * m_p_log_fp;//ָ��ǰ��־�����ļ�¼�ļ���ָ��

	/*��ȡ�ļ���Ϣ
	dir:		Ŀ¼,������б��,��"./page"
	fileName:	�ļ���,����·��,��"report.xml"
	fileInfo: �ļ���Ϣ
	*/
	extern int GetFileInfo(const char *dir, const char *fileName, BaseFileInfo* fileInfo);

	//�����ļ�,�ļ�����ȫ·��
	extern int CopyFile_Log(char *fileNameS,char *fileNameD);


	/*ɾ���ļ�
	dir:			Ŀ¼,������б��,��"./page"
	fileName:		�ļ���
	*/
	extern int DelFile(char *dir, char *fileName);

	extern void GetCurTime(SYSTEMTIME *systime);
	
		
	//extern void WriteLog(int link_ID, struct logInfoStruct logInfo);
	extern void WriteLog(int link_ID, char* logStr);
	extern void WriteLog_Tele(int link_ID, unsigned char *buf, unsigned int byte2, int bRecv);//�汨�ĵ��ļ�
	
	extern void WriteTele_to_Console(int link_ID, unsigned char *buf, unsigned int byte2, int bRecv);

#endif