// panserver2.h

#ifdef __cplusplus
extern "C"  {
#endif

#define	UWM_PANSERVER		0xC000
#define UWM_USERREGISTER		(UWM_PANSERVER+1)
#define UWM_SETDEBUGSTRING	(UWM_PANSERVER+2)

extern HWND g_hMainDlg;

extern EN_ssystem System;
extern EN_sstation *pStation;
extern EN_yyx **ppYX;
extern EN_yyc **ppYC;
extern EN_yyd **ppYD;
extern EN_yyt **ppYT;
extern EN_SOE **ppSOE;


void WINAPI DebugPrintf(char *fmt, ...);
void WINAPI DebugPrintln(char *str);

int WINAPI Routine_XD_FK(int station);
int WINAPI Routine_DY_SVG(int station);
int WINAPI Routine_Virtual();

char *WINAPI GetIniFileName();
char *WINAPI GetSubString(char *profstr, int fieldno);

long WINAPI MergeVarID(int dtype, int station, int point, int func);
void WINAPI SplitVarID(long varID, int *dtype, int *station, int *point, int *func);
int WINAPI GetVarType(long varID);
int WINAPI GetVarExtType(long varID);
int WINAPI GetVarStation(long varID);
int WINAPI GetVarPoint(long varID);

typedef HANDLE mutex_handle;
#define create_mutex(mutex)  (mutex = CreateSemaphore(NULL, 1, 1, NULL))
#define waitfor_mutex(mutex) WaitForSingleObject(mutex, INFINITE)
#define release_mutex(mutex) ReleaseSemaphore(mutex, 1, NULL)
#define close_mutex(mutex)   (CloseHandle(mutex), mutex = 0)

int WINAPI try_mutex(mutex_handle mutex);

#define DECL_VAR(x)		   extern int x; extern mutex_handle mutex_##x;
#define DEF_VAR(x)		   int x=0; mutex_handle mutex_##x;
#define DEF_STATICVAR(x)   static int x=0; static mutex_handle mutex_##x;
#define DEF_CLASSVAR(x)    int x; mutex_handle mutex_##x;

int  WINAPI _init_var(int *var, mutex_handle *mutex, int v0);
void WINAPI _close_var(mutex_handle mutex);
int  WINAPI _get_var(int *var, mutex_handle hm);
void WINAPI _set_var(int *var, mutex_handle hm, int v);
void WINAPI _inc_var(int *var, mutex_handle hm);
void WINAPI _dec_var(int *var, mutex_handle hm);

#define init_var(x,v0) _init_var(&x, &mutex_##x, v0)
#define close_var(x)   _close_var(mutex_##x)
#define get_var(x)     _get_var(&x, mutex_##x)
#define set_var(x,v)   _set_var(&x, mutex_##x, v)
#define inc_var(x)     _inc_var(&x, mutex_##x)
#define dec_var(x)     _dec_var(&x, mutex_##x)

DECL_VAR(Flag_FER)			// Front End Routine Flag. 1: routine running; 0: routine stopping; 
DECL_VAR(Count_FER)
DECL_VAR(VarID_OPER)		// 遥控遥调标志变量。0表示无遥控遥调，非零表示某站执行遥控遥调(值即为VarID
extern float Var_OPER;

extern mutex_handle Mutex_RT;
extern mutex_handle Mutex_EVENT;
extern ENEVENT pEventBuf[];
extern int Num_Event;
#define MAXNUM_EVENT 4096

//DECL_VAR(Flag_TFR)

#ifdef _MSC_VER

struct time {
   unsigned char ti_min;      /* minutes */
   unsigned char ti_hour;     /* hours */
   unsigned char ti_hund;     /* hundredths of seconds */
   unsigned char ti_sec;      /* seconds */
};

struct date {
   int da_year;     /* current year */
   char da_day;     /* day of the month */
   char da_mon;     /* month (1 = Jan) */
} ;

void gettime(struct time *timep);
void getdate(struct date *datep);

#endif

#ifdef __cplusplus
}
#endif

// end of file -- panserver2.h
