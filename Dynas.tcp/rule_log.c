
#include "rule_log.h"
#if defined(OCE_LINUX) || defined(OCE_HPUX)
#include <sys/time.h>
#endif

#ifdef OCE_WIN32
#include <io.h>
#include <sys/stat.h>
#else
#include <sys/types.h>
#include <dirent.h>
#include <unistd.h>
#include <sys/time.h>
#include <utime.h>
#endif



//void WriteLog(int link_ID, logInfoStruct logInfo)
//{
//	    char fileNameBuf[256];
//		memset(fileNameBuf, 0x00, sizeof(fileNameBuf));
//		sprintf(fileNameBuf, "./log/%d_dynas.log", link_ID);
//		m_p_log_fp = NULL;
//		m_p_log_fp = fopen(fileNameBuf, "a+");
//		if (m_p_log_fp == NULL)
//		{
//
//#ifdef _MSC_VER
//			int error = 0;
//			error=GetLastError();
//			printf("\r\nlinkID=%d,error=%d\r\n",link_ID,error);
//#endif
//
//		}
//
//	//RWRecMutex::WLock autoLock(m_semLogFile);
//
//	BaseFileInfo fileInfo;
//
//
//	//GetFileInfo("./","dynas.log",fileInfo);
//	GetFileInfo("./log", fileNameBuf, fileInfo);
//
//	if (fileInfo.size > 1048576)	//日志文件大于1M则清空
//	{
//		SYSTEMTIME	systime;
//		memset(&systime, 0x00, sizeof(systime));
//		GetCurTime(&systime);
//		char buf[256];
//		memset(buf, 0x00, sizeof(buf));
//		//sprintf(buf,"G:\\dynas%d_%d_%d_%d_%d_%d_log.txt\n",
//		//cd.Year(),cd.Month(),cd.DayOfMonth(),ct.Hour(),ct.Minute(),ct.Second());
//		sprintf(buf, "./log/%d_dynas%4d_%02d_%02d_%02d_%02d_%02d_log.txt", link_ID,
//			systime.wYear, systime.wMonth, systime.wDay, systime.wHour, systime.wMinute, systime.wSecond);
//		printf("%s\r\n", buf);
//		//fclose(logFp);
//#ifdef _WIN32
//		//CopyFile("./dynas.log",buf);
//		CopyFile_Log(fileNameBuf, buf);
//		if (m_p_log_fp)
//			fclose(m_p_log_fp);
//		m_p_log_fp = fopen(fileNameBuf, "wb");
//
//		if (m_p_log_fp)
//			fclose(m_p_log_fp);
//		m_p_log_fp = fopen(fileNameBuf, "a+");
//
//#else
//		if (m_p_log_fp)
//			fclose(m_p_log_fp);
//
//		rename((const char*)fileNameBuf, (const char*)buf);
//		m_p_log_fp = fopen(fileNameBuf, "a+");
//#endif
//	}
//
//	char str[256];
//	memset(str, 0x00, sizeof(str));
//	SYSTEMTIME	systime;
//	memset(&systime, 0x00, sizeof(systime));
//	GetCurTime(&systime);
//
//
//	sprintf(str, "A: %04d-%02d-%02d %02d:%02d:%02d %03d- linkID=%d,logInfo:%s,val=%f\n", systime.wYear, systime.wMonth, systime.wDay,
//		systime.wHour, systime.wMinute, systime.wSecond, systime.wMilliseconds, link_ID, logInfo.logString, logInfo.val);
//
//	if (m_p_log_fp)
//	{
//		fprintf(m_p_log_fp, str);
//		//fflush(m_p_log_fp);
//	}
//}


void WriteLog(int link_ID, char* logStr)
	{
		char fileNameBuf[256];
		memset(fileNameBuf, 0x00, sizeof(fileNameBuf));
		sprintf(fileNameBuf, "./log/%d_dynas.log", link_ID);
		m_p_log_fp = NULL;
		m_p_log_fp = fopen(fileNameBuf, "a+");
		if (m_p_log_fp == NULL)
		{

#ifdef _MSC_VER
			int error = 0;
			error = GetLastError();
			printf("\r\nlinkID=%d,error=%d\r\n", link_ID, error);
#endif

		}
	//RWRecMutex::WLock autoLock(m_semLogFile);

	BaseFileInfo* fileInfo = (BaseFileInfo*)malloc(sizeof(BaseFileInfo));

	//GetFileInfo("./","dynas.log",fileInfo);
	GetFileInfo("./",fileNameBuf,fileInfo);

	if(fileInfo->size>1048576)	//日志文件大于1M则清空
		{
		printf("文件大于1M\n");
		SYSTEMTIME	systime;
		memset(&systime, 0x00, sizeof(systime));
		GetCurTime(&systime);
		char buf[256];
		memset(buf, 0x00, sizeof(buf));

		sprintf(buf, "./log/station%d/%d_dynas%4d_%02d_%02d_%02d_%02d_%02d_log.txt",link_ID, link_ID,
			systime.wYear, systime.wMonth, systime.wDay, systime.wHour, systime.wMinute, systime.wSecond);

		printf("%s\r\n",buf);
		//fclose(logFp);
#ifdef _WIN32
		//CopyFile("./dynas.log",buf);
		CopyFile_Log(fileNameBuf,buf);
		if(m_p_log_fp)
			fclose(m_p_log_fp);
		m_p_log_fp=fopen(fileNameBuf,"wb");

		if(m_p_log_fp)
			fclose(m_p_log_fp);
		m_p_log_fp=fopen(fileNameBuf,"a+");

#else
		if(m_p_log_fp)
			fclose(m_p_log_fp);

		rename((const char*)fileNameBuf,(const char*)buf);
		m_p_log_fp=fopen(fileNameBuf,"a+");
#endif
		}
	free(fileInfo);

	char str[256];
	memset(str,0x00,sizeof(str));
	SYSTEMTIME	systime;
	memset(&systime, 0x00, sizeof(systime));
	GetCurTime(&systime);

	sprintf(str, "C: %04d-%02d-%02d %02d:%02d:%02d %03d linkID=%d,logInfo:%s\n", systime.wYear, systime.wMonth, systime.wDay, 
		systime.wHour, systime.wMinute, systime.wSecond, systime.wMilliseconds,link_ID,logStr);  

	if(m_p_log_fp)
		{
		int count = fprintf(m_p_log_fp,"%s",str);
		fflush(m_p_log_fp);
		fclose(m_p_log_fp);
		}
	}



void WriteLog_Tele(int link_ID,unsigned char *buf,unsigned int byte2,int bRecv)
	{
		char fileNameBuf[256];
		memset(fileNameBuf, 0x00, sizeof(fileNameBuf));
		sprintf(fileNameBuf, "./log/%d_dynas.log", link_ID);
		m_p_log_fp = NULL;
		m_p_log_fp = fopen(fileNameBuf, "a+");
		if (m_p_log_fp == NULL)
		{

#ifdef _MSC_VER
			int error = 0;
			error = GetLastError();
			printf("\r\nlinkID=%d,error=%d\r\n", link_ID, error);
#endif

		}

	//RWRecMutex::WLock autoLock(m_semLogFile);

	BaseFileInfo* fileInfo = (BaseFileInfo*)malloc(sizeof(BaseFileInfo));

	//GetFileInfo("./","dynas.log",fileInfo);
	GetFileInfo("./",fileNameBuf,fileInfo);


	//if(fileInfo.size>208576)	//日志文件大于1M则清空
	if(fileInfo->size>1048576)	//日志文件大于1M则清空
		{
		SYSTEMTIME	systime;
		memset(&systime, 0x00, sizeof(systime));
		GetCurTime(&systime);
		char buf1[256];
		memset(buf1,0x00,sizeof(buf1));
		//sprintf(buf,"G:\\dynas%d_%d_%d_%d_%d_%d_log.txt\n",
		//cd.Year(),cd.Month(),cd.DayOfMonth(),ct.Hour(),ct.Minute(),ct.Second());
		sprintf(buf1,"./log/station%d/%d_dynas%4d_%02d_%02d_%02d_%02d_%02d_log.txt",link_ID, link_ID,
			systime.wYear, systime.wMonth, systime.wDay, systime.wHour, systime.wMinute, systime.wSecond);
	
	#ifdef _WIN32
		//CopyFile("./dynas.log",buf);
		CopyFile_Log(fileNameBuf,buf1);
		if(m_p_log_fp)
			fclose(m_p_log_fp);
		m_p_log_fp=fopen(fileNameBuf,"wb");

		if(m_p_log_fp)
			fclose(m_p_log_fp);
		m_p_log_fp=fopen(fileNameBuf,"a+");
		
		#else
		if(m_p_log_fp)
			fclose(m_p_log_fp);

			rename((const char*)fileNameBuf,(const char*)buf1);
			m_p_log_fp=fopen(fileNameBuf,"a+");
			
		#endif
		}
	free(fileInfo);

	//FILE *fp=fopen(fileNameBuf,"a");
	if(m_p_log_fp)
		{
		if ( byte2 <= 0)
			{
			return ;
			}

		SYSTEMTIME	systime;
		memset(&systime, 0x00, sizeof(systime));
		GetCurTime(&systime);
		int i =0;

		if(m_p_log_fp!=NULL)
			{
			//printf("bRecv=%d\r\n",bRecv);
			if(bRecv) //发送报文
				fprintf(m_p_log_fp,"\nA: linkID=%d,recv tele len=%d,%4d-%02d-%02d %02d:%02d:%02d:%03d   --\n",link_ID,byte2,systime.wYear,systime.wMonth,systime.wDay,systime.wHour, systime.wMinute, systime.wSecond, systime.wMilliseconds);
			else
				fprintf(m_p_log_fp,"\nB: linkID=%d,send tele len=%d,%4d-%02d-%02d %02d:%02d:%02d:%03d   --\n",link_ID,byte2,systime.wYear,systime.wMonth,systime.wDay,systime.wHour, systime.wMinute, systime.wSecond, systime.wMilliseconds);

			for(i = 0; i<byte2; i++)
				{
				if(m_p_log_fp)
					fprintf(m_p_log_fp,"%02X ",buf[i]);

				}
				fprintf(m_p_log_fp,"\n");
				fflush(m_p_log_fp);
				fclose(m_p_log_fp);

			}
		
		}
}


void WriteTele_to_Console(int link_ID,unsigned char *buf,unsigned int byte2,int bRecv)
	{
		char fileNameBuf[256];
		memset(fileNameBuf, 0x00, sizeof(fileNameBuf));
		sprintf(fileNameBuf, "./log/%d_dynas.log", link_ID);
		m_p_log_fp = NULL;
		m_p_log_fp = fopen(fileNameBuf, "a+");
		if (m_p_log_fp == NULL)
		{

#ifdef _MSC_VER
			int error = 0;
			error = GetLastError();
			printf("\r\nlinkID=%d,error=%d\r\n", link_ID, error);
#endif

		}
	int i = 0;
	SYSTEMTIME	systime;
	memset(&systime, 0x00, sizeof(systime));
	GetCurTime(&systime);
	if ( byte2 <= 0)
		{
		return ;
		}

	if(bRecv) //发送报文
		printf("\r\nlinkID=%d,recv tele len=%d,%4d-%02d-%02d %02d:%02d:%02d:%03d   --\n",link_ID,byte2,systime.wYear,systime.wMonth,systime.wDay,systime.wHour, systime.wMinute, systime.wSecond, systime.wMilliseconds);
	else
		printf("\r\nlinkID=%d,send tele len=%d,%4d-%02d-%02d %02d:%02d:%02d:%03d   --\n",link_ID,byte2,systime.wYear,systime.wMonth,systime.wDay,systime.wHour, systime.wMinute, systime.wSecond, systime.wMilliseconds);
	for(i = 0; i<byte2; i++)
		{
		
			printf("%02X ",buf[i]);

		}
	printf("\r\n");


	}
void GetCurTime(SYSTEMTIME *systime)
	{
#ifdef _MSC_VER
	GetLocalTime(systime);
#else

	time_t tt;
	struct timeval tp;

	tt = time(NULL);
	gettimeofday(&tp,NULL);
	struct tm *stm;
	stm =  localtime(&tt);
	systime->wYear = stm->tm_year+1900;
	systime->wMonth = stm->tm_mon+1;
	systime->wDay = stm->tm_mday;
	systime->wHour = stm->tm_hour;
	systime->wMinute = stm->tm_min;
	systime->wSecond = stm->tm_sec;
	systime->wMilliseconds = tp.tv_usec/1000;
	systime->wDayOfWeek = stm->tm_wday;
#endif

	}

/*获取文件信息
dir:		目录,不含后斜线,如"./page"
fileName:	文件名,不含路径,如"report.xml"
fileInfo: 文件信息
*/
int GetFileInfo(const char *dir,char *fileName,BaseFileInfo* fileInfo)
	{

#ifdef _WIN32

	HANDLE hFile;
	char filePath[_MAX_PATH];
	WIN32_FIND_DATA filedata;
	FILETIME lfiletime;
	SYSTEMTIME systime;

	sprintf(filePath,"%s/%s",dir,fileName);

	hFile = FindFirstFile (filePath, &filedata);
	if ( INVALID_HANDLE_VALUE==hFile )  //判断句柄是否有效
		{
		return DCO_NoSuchFile;		//no file
		}
	FindClose (hFile);

	fileInfo->fileName=fileName;
	fileInfo->size=filedata.nFileSizeLow;	//在此忽略了filedata.nFileSizeHigh

	//created time
	FileTimeToLocalFileTime(&filedata.ftCreationTime,&lfiletime);
	FileTimeToSystemTime(&lfiletime,&systime);

	fileInfo->createTime = systime;

	//last modified time
	FileTimeToLocalFileTime(&filedata.ftLastWriteTime,&lfiletime);
	FileTimeToSystemTime(&lfiletime,&systime);

	fileInfo->modifyTime = systime;

#else

	//char szFile[_MAX_PATH];
	char szFile[250];

	int iret;
	struct stat statbuf;
	struct tm *stm;
	char day,month,hour,minute,second;
	short year;

	sprintf( szFile ,"%s/%s",dir,fileName );
	iret = stat(szFile , &statbuf );

	if(-1==iret) 
		return DCO_NoSuchFile;

	//SAFETY_STRCPY(fileInfo.fileName,fileName,MAX_FILENAME_LENGTH)
	fileInfo.fileName=fileName;
	fileInfo.size = statbuf.st_size;

	//created time
	stm =  localtime(&statbuf.st_ctime);

	year  = (short)( stm->tm_year+1900);
	month = (char)(stm->tm_mon+1);
	day   = (char)stm->tm_mday;

	hour   = (char) stm->tm_hour;
	minute = (char)stm->tm_min;
	second = (char)stm->tm_sec;

	pdt=new CxDate(day,month,year);
	ptm=new CxTime(*pdt,hour,minute,second);
	fileInfo.createTime = ptm->Seconds();

	//last modified time
	stm =  localtime(&statbuf.st_mtime);

	year  = (short)( stm->tm_year+1900);
	month = (char)(stm->tm_mon+1);
	day   = (char)stm->tm_mday;

	hour   = (char) stm->tm_hour;
	minute = (char)stm->tm_min;
	second = (char)stm->tm_sec;

	//wcsbull add 20070803
	delete pdt;
	delete ptm;

	pdt=new CxDate(day,month,year);
	ptm=new CxTime(*pdt,hour,minute,second);
	fileInfo.modifyTime = ptm->Seconds();

	//wcsbull add 20070803
	delete pdt;
	delete ptm;

#endif	//_WIN32

	return DCO_SUCCESS;
	}

//复制文件,文件名含全路径
int CopyFile_Log(char *fileNameS,char *fileNameD)
	{
	int ret;

#ifdef _WIN32
	if(CopyFile(fileNameS,fileNameD,FALSE))
		ret=DCO_SUCCESS;
	else
		{
#ifdef _MSC_VER
		int error =0;
		error=GetLastError();
		printf("\r\n,error=%d\r\n",error);
#endif;
		ret=DCO_FileErr;
		}

#else
	//ret=rename(fileNameS,fileNameD);
#ifdef ALPHA
	ret=ucpfile(fileNameS,fileNameD);	//wcsbull modified 200412
#else //HP-UX
	BaseFileInfo fileInfo;
	//char dirs[_MAX_PATH],dird[_MAX_PATH],*ps=NULL,*pd=NULL;
	char dirs[250],dird[250],*ps=NULL,*pd=NULL;

	strcpy(dirs,fileNameS);
	strcpy(dird,fileNameD);

	ps=strrchr(dirs,'/');
	if(NULL!=ps)
		{
		*ps='\0';
		ps++;	//指向文件名
		}
	else 
		ps=dirs;

	pd=strrchr(dird,'/');
	if(NULL!=pd)
		{
		*pd='\0';
		pd++;
		}
	else
		pd=dird;

	GetFileInfo(dirs,ps,fileInfo);		//rename会修改文件时间
	ret=rename(fileNameS,fileNameD);	//TODO:并非复制
	ChgFileTime(dird,&fileInfo);
#endif
#endif

	//<<add 20040419
#ifdef _WIN32
	if(0==(_access(fileNameD,0)))	// file already exist
		{
		//if( (_access(fileNameD,2)) !=0) //no write permission
		_chmod(fileNameD,_S_IREAD | _S_IWRITE);
		}
#else
	if(0==(access(fileNameD,F_OK )))	// file already exist
		{
		//if( ( access(fileNameD,W_OK)) !=0) //no write permission
		chmod(fileNameD,S_IRWXU | S_IRWXG | S_IRWXO );
		}
#endif //_WIN32
	//>>add 20040419

	return ret;
	}

/*删除文件
dir:			目录,不含后斜线,如"./page"
fileName:		文件名
*/
int DelFile(char *dir,char *fileName)
	{
#ifdef DCODEMO
	return DCO_SUCCESS;
#endif
	char pathname[80];

	//sprintf(pathname,"%s/%s",dir,fileName);
	//sprintf(pathname,"%s/%s",dir,fileName);
	sprintf(pathname,"%s\\%s",dir,fileName);

	printf("name=%s\r\n",pathname);
	if(-1==remove(pathname))
		//if(-1==remove(fileName))
		{
#ifdef _MSC_VER
		int error =0;
		error=GetLastError();
		printf("\r\n,error=%d\r\n",error);
#endif
		return DCO_FileErr;		//fail del file
		}

	else
		return DCO_SUCCESS;		//success del file
	}




