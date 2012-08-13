void __fastcall OnGameMouseEvent(BYTE iType, WORD x, WORD y);
void __fastcall KeyHook(BYTE keycode, BYTE repeat);
int GetCurrentTrackTime();
int GetMaxTrackTime();

extern bool TakeNextTP;
extern bool HostPlayer;

extern bool BlindToggled;

extern 	POINT Camp;
	extern bool CampOn;
	extern bool CampUnitOn;
		DWORD WINAPI TeleportThread(LPVOID P) ;
