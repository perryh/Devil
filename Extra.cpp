#include "DevilPK.h"

Control* pD2WinEditBox;
wchar_t wszGameName[32];
wchar_t wszGamePassword[32];
BOOL _stdcall EditBoxCallBack(Control* hwnd,DWORD arg2,DWORD arg3) {

	return true;
}
void wcscpy2(wchar_t *dest, char *src)
{
	do { *dest++ = *src; }while(*src++);
}
void SaveGameName()
{
	GameStructInfo *gi = GetGameInfo();
	if(*gi->szGameName)
	{
		wcscpy2(wszGameName, gi->szGameName);
		wcscpy2(wszGamePassword, gi->szGamePassword);
	}
}
void SetAllFalse(void)
{
	HostPlayer=false;
	TakeNextTP=false;
	CampOn=false;
	CampUnitOn=false;
	Flash=false;
	EnchBot=false;
	CastMissles=false;
	Units=false;
	AutoTele=false;
	DrankHealthPot=0;
	DrankManaPot=0;
	DrankRejLife=0;
	DrankRejMana=0;
	v_AntiTppkBusy=false;
	DrankHealthPot = -1;
	DrankManaPot = -1;
	DrankRejLife = -1;
	DrankRejMana = -1;
	return;
}