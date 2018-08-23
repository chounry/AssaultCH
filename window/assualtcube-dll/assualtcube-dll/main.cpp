#include<Windows.h>


extern int UImain();

DWORD WINAPI Main_Thread(LPVOID) {
	UImain();
	return S_OK;
}

BOOL APIENTRY DllMain(HMODULE hModule,
	DWORD _reason,
	LPVOID lpReserved)
{
	if (_reason == DLL_PROCESS_ATTACH) {
		CreateThread(0, 0x1000, &Main_Thread, 0, 0, NULL);
	}
	return TRUE;
}