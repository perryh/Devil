#define _VARS
#define INITVAB(n,a) n=n+(DWORD)LoadLibraryA(a);
#include "DevilPK.h"
char szModulePath[259];

AutoAim Auto;
LinkedList* PlayerFriendList;
LinkedList* PlayerEnemyList;
LinkedList* PlayerHCPKList;
LinkedList* PlayerIHPKList;
LinkedList* EnchList;

BOOL WINAPI DllMain(HINSTANCE hDll,DWORD dwReason,LPVOID lpReserved) 
{
	if(dwReason==DLL_PROCESS_ATTACH) 
	{
		PlayerFriendList=new LinkedList;
		PlayerEnemyList=new LinkedList;
		PlayerHCPKList=new LinkedList;
		PlayerIHPKList=new LinkedList;
		EnchList=new LinkedList;
		DefineOffsets ();
		InstallPatchs ();
		MessageBeep(-1);

		GetModuleFileName(hDll,szModulePath,249); *(strrchr(szModulePath,'\\')+1) = 0;

		INITVAB(DontBreak,"D2NET.dll") 
		INITVAB(BreakItUp,"D2NET.dll") 
		INITVAB(PlayerRoster,"D2CLIENT.dll")
		INITVAB(p_D2CLIENT_pUnitTableM,"D2CLIENT.dll")
		INITVAB(D2CLIENT_GetUnitFromId_M,"D2CLIENT.dll")
		INITVAB(D2CLIENT_TestPvpFlag_M,"D2CLIENT.dll")  
	
		InitItemViewer();
		ReadConfig();
		ReadConfig2();
		ReadConfig3();

		if(D2GFX_GetHwnd())
		{
			GetWindowText(D2GFX_GetHwnd (), szOrigWinName, sizeof(szOrigWinName));
			OldWNDPROC = (WNDPROC)GetWindowLong(D2GFX_GetHwnd(),GWL_WNDPROC);
			SetWindowLong(D2GFX_GetHwnd(),GWL_WNDPROC,(LONG)GameWindowEvent);
		}

		CreateThread(0,0,TimerTickThread,0,0,0);
		CreateThread(0,0,TimerTickThread2,0,0,0);
		CreateThread(0,0,TimerTickThread3,0,0,0);

		if(*(DWORD*)0x6FBCC3D0!=NULL) 
		{
			if (GameReady())
			D2Inited=true;
			D2Delay=21;
			TimeOn++;
			RevealAct();
			SaveGameName();
			LevelNames.RemoveAll();
			SetAllFalse();
			nGameTimer = GetTickCount ();     
		}
	};
	if(dwReason==DLL_PROCESS_DETACH)
	{

	}
	return true;
	
};
