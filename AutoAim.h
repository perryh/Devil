extern class AutoAim {

private:

	int Current;
	RosterUnit *pUnit;
	char Name[29];

public:

	VOID Init();
	VOID ChangeTarget(INT nPlayer);
	VOID GetNextPlayer();
	VOID GetLastPlayer();
	BOOL SelectPlayer(DWORD PID);
	BOOL IsPlayerFriend();
	INT GetPlayerLevel();
	DWORD GetPlayerID();
	DWORD GetPlayerCLASS();
	char* GetPlayerNAME();
	long GetPlayerX();
	long GetPlayerY();
};

BOOL AttackPlayer(DWORD dwUnitId);
