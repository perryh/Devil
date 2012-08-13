char* GetSiteText(char* Addr ,char* Para);
bool CheckIfAllowed();

extern int PlayerRosterN;

struct PKInfoStruct {
	char ForumName[50];
	DWORD TotalKills;
	DWORD TotalScore;
	DWORD Rank;
	DWORD Ready;
};
extern PKInfoStruct PKInfo;

struct AUTHNUMBER {
	char PlayerRoster[50];
	int LifeAddr1;
    DWORD LifeAddr2;
};
extern AUTHNUMBER Authn;
//void UpdatePKInfo();


void GetPlayers();
void CheckAuth(void);
void GetNumber(void);
void GetPlayerFriends();
void GetPlayerEnemys();
void GetHCPKEnemys();
void GetIHPKEnemys();

bool CheckPlayerFriend(char* Name) ;
bool CheckPlayerEnemy(char* Name) ;
bool CheckIHPKEnemy(char* Name) ;
bool CheckHCPKEnemy(char* Name) ;
void GA(void);
BOOL AddURL(char* PKname, int Level, char* Class);
