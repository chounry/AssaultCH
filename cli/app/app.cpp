// app.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>
#include<ctime>
#include<string>
#include<Windows.h>
#include <tlhelp32.h>
#include <tchar.h>

using namespace std;
DWORD  findAdd(int pointerLevel, HANDLE hProcHandle, DWORD offsets[], DWORD baseAddr);
void writeToMemory(HANDLE hProcHandle);
DWORD GetModuleBaseAddress(DWORD dwProcID, const TCHAR *szModuleName);

string GameName = "AssaultCube";
LPCSTR GameWindow = "AssaultCube";
string gameStatus;
DWORD dwProcID = NULL;
TCHAR acModuleName ;

bool isGameAvail;
bool updateOnNextRun;

// Amo Vars
bool ammoStatus;
BYTE ammoValues[] = { 0xA3,0x1c,0x0,0x0 };
DWORD ammoBaseAddr = { 0x0051e20c };
DWORD ammoOffsets[] = { 0x384, 0x14, 0x0 };

// Healt Vars
bool healthStatus;
BYTE healthValues[] = { 0x1,0x3a, 0x0,0x0 };
DWORD healthBaseAddr;
DWORD healthOffsets[] = {0xf8 };


int main()
{
	
	HWND hGameWindow = NULL;
	int timeSinceLastUpdate = clock();
	int gameAvailTMR = clock();
	int onePressTMR = clock();
	HANDLE hProcHandle = NULL;
	updateOnNextRun = true;
	string sAmmoStatus = "OFF";
	string sHealthstatus = "OFF";
	while (!GetAsyncKeyState(VK_INSERT)) {
		if (clock() - gameAvailTMR > 100) {
			gameAvailTMR = clock();
			isGameAvail = false;
			
			hGameWindow = FindWindow(NULL, GameWindow);
			if (hGameWindow) {
				GetWindowThreadProcessId(hGameWindow, &dwProcID);
				if (dwProcID != 0) {
					healthBaseAddr =  GetModuleBaseAddress(dwProcID, _T("ac_client.exe")) + 0x00109B74;
					hProcHandle = OpenProcess(PROCESS_ALL_ACCESS, FALSE, dwProcID);
					if (hProcHandle == INVALID_HANDLE_VALUE || hProcHandle == NULL) {
						gameStatus = "Fail to open process for valid handle";
					}
					else {
						gameStatus = "Assault is ready to hack";
						isGameAvail = true;
					}
				}
				else {
					gameStatus = "Fail to get process id";
				}
			}
			else {
				gameStatus = "Can't find the window";
			}

			if (updateOnNextRun || clock() - timeSinceLastUpdate > 5000) {
				system("cls");
				cout << "---------------------------------------------------\n";
				cout << "        AssaultCube Trainer | Ammo & Health\n";
				cout << "---------------------------------------------------\n";
				cout << "Game Status : " << gameStatus << endl;
				cout << "[F1] Unlimited Ammo Status : " << sAmmoStatus << endl;
				cout << "[F2] Unlimited Health : " << sHealthstatus << endl;
				cout << "[INSERT] Quit\n";
				updateOnNextRun = false;
				timeSinceLastUpdate = clock();

			}

			if (isGameAvail) {
				writeToMemory(hProcHandle);
			}
		}
		if (clock() - onePressTMR > 400) {
			if (isGameAvail) {
				// ammo
				if (GetAsyncKeyState(VK_F1)) {
					onePressTMR = clock();
					ammoStatus = !ammoStatus;
					sAmmoStatus = ammoStatus ? "ON" : "OFF";
				}
				else if (GetAsyncKeyState(VK_F2)) {
					onePressTMR = clock();
					healthStatus = !healthStatus;
					sHealthstatus = healthStatus ? "ON" : "OFF";

				}

			}
		}
	}
	CloseHandle(hProcHandle);
	CloseHandle(hGameWindow);
    return 0;
}

DWORD  findAdd(int pointerLevel, HANDLE hProcHandle, DWORD offsets[], DWORD baseAddr) {
	DWORD pTMP;
	DWORD pointerAddr;
	for (int c = 0; c < pointerLevel; c++) {
		if (c == 0) {
			ReadProcessMemory(hProcHandle, (LPCVOID)baseAddr, &pTMP, sizeof(pTMP), NULL);
		}
		pointerAddr = pTMP + offsets[c];
		ReadProcessMemory(hProcHandle, (LPCVOID)pointerAddr, &pTMP, sizeof(pTMP), NULL);
	}
	return pointerAddr;
}

void writeToMemory(HANDLE hProcHandle) {

	DWORD addrToWrite;
	if (ammoStatus) {
		addrToWrite = findAdd(3, hProcHandle, ammoOffsets, ammoBaseAddr);
		WriteProcessMemory(hProcHandle, (BYTE*)addrToWrite, &ammoValues, sizeof(ammoValues), NULL);
	}
	if (healthStatus) {
		addrToWrite = findAdd(1, hProcHandle, healthOffsets, healthBaseAddr);
		WriteProcessMemory(hProcHandle, (BYTE*)addrToWrite, &healthValues, sizeof(healthValues), NULL);
	}
}

DWORD GetModuleBaseAddress(DWORD dwProcID, const TCHAR *szModuleName)
{
	//uintptr_t
	DWORD ModuleBaseAddress = 0;
	HANDLE hSnapshot = CreateToolhelp32Snapshot(TH32CS_SNAPMODULE | TH32CS_SNAPMODULE32, dwProcID);
	if (hSnapshot != INVALID_HANDLE_VALUE)
	{
		MODULEENTRY32 ModuleEntry32;
		ModuleEntry32.dwSize = sizeof(MODULEENTRY32);
		if (Module32First(hSnapshot, &ModuleEntry32))
		{
			do
			{
				if (_tcsicmp(ModuleEntry32.szModule, szModuleName) == 0)
				{
					ModuleBaseAddress = (DWORD)ModuleEntry32.modBaseAddr;
					break;
				}
			} while (Module32Next(hSnapshot, &ModuleEntry32));
		}
		CloseHandle(hSnapshot);
	}
	return ModuleBaseAddress;
}


