// DLL-injector.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>
#include<Windows.h>
#include<TlHelp32.h>

using namespace std;
bool injectDll(DWORD processId);

char fileToInject[] = "assualtcube-dll.dll";
char processName[] = "ac_client.exe";
typedef HINSTANCE(*fpLoadLibrary)(char*);

int main()
{
	DWORD processId = NULL;
	PROCESSENTRY32 pe32 = { sizeof(PROCESSENTRY32) };
	HANDLE hProcSnap;
	
	while (!processId) {
		system("cls");
		cout << "Searching for " << processName << endl;
		cout << "Make sure the game is running..";
		hProcSnap = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
		
		if (Process32First(hProcSnap, &pe32)) {
			do {
				if (!strcmp(pe32.szExeFile, processName)) {
					processId = pe32.th32ProcessID;
					break;
				}
			} while (Process32Next(hProcSnap, &pe32));
		}
		Sleep(1000);
	}

	while (!injectDll(processId)) {
		system("cls");
		cout << "DLL is fail to inject.\n ";
		Sleep(1000);
	}
	cout << "Inject Successfully.\n\n";
	cout << "Closing in 5s";
	CloseHandle(hProcSnap);
	Sleep(5000);

    return 0;
}

bool injectDll(DWORD processId) {
	HANDLE hProc;
	LPVOID paramAddr;

	HINSTANCE hDll = LoadLibrary("KERNEL32");
	fpLoadLibrary loadLibraryAddr = (fpLoadLibrary)GetProcAddress(hDll, "LoadLibraryA");
	
	hProc = OpenProcess(PROCESS_ALL_ACCESS, false, processId);
	
	char dllPath[250] = "C:\\HACKS\\";
	
	strcat_s(dllPath, fileToInject);

	paramAddr = VirtualAllocEx(hProc, 0, strlen(dllPath) + 1, MEM_COMMIT, PAGE_READWRITE);
	
	bool memoryWritten = WriteProcessMemory(hProc, paramAddr, dllPath, strlen(dllPath) + 1, NULL);

	CreateRemoteThread(hProc, 0, 0, (LPTHREAD_START_ROUTINE)LoadLibrary, paramAddr, 0, 0);

	CloseHandle(hProc);

	return memoryWritten;
}
