// panserver.h

extern "C" {
int  WINAPI FrontEndSetup();
//LRESULT WINAPI FrontEndRoutine(LPVOID);
unsigned __stdcall FrontEndRoutine(LPVOID);
void WINAPI FrontEndCleanup ();

//int  WINAPI TFR_Setup();
//LRESULT WINAPI TFR_Routine(LPVOID);
//void WINAPI TFR_Cleanup();

//LRESULT WINAPI RPCSetup (LPVOID);
unsigned __stdcall RPCSetup(LPVOID);
LRESULT WINAPI RPCCleanup (LPVOID);
}


