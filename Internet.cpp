#include "DevilPK.h"

bool ListOnce=false;
bool GainOnce=false;

PKInfoStruct PKInfo;
AUTHNUMBER Authn;

#define INTERNET_OPEN_TYPE_PRECONFIG      0

typedef void* (WINAPI * __InternetOpen) (char*,DWORD,DWORD,DWORD,DWORD);
typedef void* (WINAPI * __InternetOpenUrl) (void*,char*,DWORD,DWORD,DWORD,DWORD);
typedef void  (WINAPI * __InternetCloseHandle) (HANDLE);
typedef BOOL  (WINAPI * __InternetReadFileA) ( HANDLE, LPVOID ,DWORD ,LPDWORD);

char* GetSiteText(char* Addr ,char* Para)
{
  HANDLE hInternet = NULL;
  HANDLE hInternetUrl = NULL;
  char szString[2049]={0};
  char szSite[1024]={0};
  sprintf(szSite,"%s?%s",Addr,Para);


   HANDLE gHandle = LoadLibrary("wininet");
   if(!gHandle)
      return 0;

   __InternetOpen fp1;
   fp1=(__InternetOpen)(DWORD)GetProcAddress((HINSTANCE)gHandle,"InternetOpenA");
   __InternetOpenUrl fp2;
   fp2=(__InternetOpenUrl)(DWORD)GetProcAddress((HINSTANCE)gHandle,"InternetOpenUrlA");
   __InternetCloseHandle fp3;
   fp3=(__InternetCloseHandle)(DWORD)GetProcAddress((HINSTANCE)gHandle,"InternetCloseHandle");
   __InternetReadFileA fp4;
   fp4=(__InternetReadFileA)(DWORD)GetProcAddress((HINSTANCE)gHandle,"InternetReadFile");
   if(!fp1 || !fp2 || !fp3 || !fp4)
      return 0;

  DWORD dwBytes = 0;
  hInternet = fp1(0,INTERNET_OPEN_TYPE_PRECONFIG,0,0,0);
  if(hInternet == NULL) return 0;
  hInternetUrl = fp2(hInternet,szSite,NULL,0,INTERNET_FLAG_EXISTING_CONNECT,0);
  if(hInternetUrl == NULL) return 0;
  fp4(hInternetUrl,&szString,2048,&dwBytes);
  if(hInternetUrl == NULL) return NULL;

  fp3(hInternetUrl);
  fp3(hInternet);
  return szString;
}

typedef void* (WINAPI * __InternetOpen) (char*,DWORD,DWORD,DWORD,DWORD);
typedef void* (WINAPI * __InternetOpenUrl) (void*,char*,DWORD,DWORD,DWORD,DWORD);

BOOL ConnectURL(char* szURL)
{
   HANDLE hURL;
   HANDLE hInternetSession;

   HANDLE gHandle = LoadLibrary("wininet");
   if(!gHandle)
      return 0;

   __InternetOpen fp1;
   fp1=(__InternetOpen)(DWORD)GetProcAddress((HINSTANCE)gHandle,"InternetOpenA");
   __InternetOpenUrl fp2;
   fp2=(__InternetOpenUrl)(DWORD)GetProcAddress((HINSTANCE)gHandle,"InternetOpenUrlA");
   
   if(!fp1 || !fp2)
      return 0;

   hInternetSession = fp1("Microsoft Internet Explorer",INTERNET_OPEN_TYPE_PRECONFIG,NULL,NULL,0);
   hURL = fp2(hInternetSession,szURL,NULL,0,0,0);
   CloseHandle(hURL);
   CloseHandle(hInternetSession);
   return (BOOL)FreeLibrary((HINSTANCE)gHandle);
}

void Decrypt(char* buffer, char* String,int xorer)
{
	for(int i=0;i<strlen(String);i++)
	{
		buffer[i] = ((char)String[i])-xorer;
	}
}

char* AuthURL()
{
	char* Buffer=(char*)malloc(512);
	for(int i=0;i<512;i++)
	Buffer[i] = 0x00;
	Decrypt(Buffer,"s{E::ÇÇÇ9ts{v9yp:TS[VL?sWt~9{s{",11);

	return Buffer;
}
char* GetKey()
{
	char* Buffer=(char*)malloc(512);
	for(int i=0;i<512;i++)
	Buffer[i] = 0x00;
	Decrypt(Buffer,"1vpÑH>AArl>É|>rÅ<<=An>{q>oDD",11);
	return Buffer;
}
char* HcpkURL()
{
	char* Buffer=(char*)malloc(512);
	for(int i=0;i<512;i++)
		Buffer[i] = 0x00;
	Decrypt(Buffer,"ùÅÅÖœ⁄⁄ÇÇÇ€ùñÖû€õêÅ⁄ÕÕÃ∑¬∂∂ππÃ∆∆∆«∑≈¬¿«≥¿Ã∆€ÖùÖ",11);
	return Buffer;
}
char* IhpkURL()
{
	char* Buffer=(char*)malloc(512);
	for(int i=0;i<512;i++)
		Buffer[i] = 0x00;
	Decrypt(Buffer,"s{E::ÇÇÇ9ts{v9yp:TS[VL?sWt~9{s{",11);

	return Buffer;
}

bool CheckIfAllowed()
{
	GainOnce=false;
	if(GainOnce)
	return TRUE;
	char Parameter[512];
	char Buffer[512];
	sprintf(Parameter,"action=check&a=%s&r=%s",GetGameInfo()->szAccountName,GetGameInfo()->szRealmName);
	sprintf(Buffer,"%s",GetSiteText(AuthURL(),Parameter));
	if(Buffer[0]=='N'&&Buffer[1]=='A'&&Buffer[2]=='H') 
	return true;
	return false;
}


void GA(void)
{
	if(ListOnce)
	return;
	char Buffer[2048]={0};
	char Parameter[1024];
	char* argv[1024];
	sprintf(Parameter,"action=version");
	strcpy(Buffer,GetSiteText(AuthURL(),Parameter));
	DWORD argc=MakeParameter(Buffer,argv,'|',true);
	Authn.LifeAddr1=atoi(argv[1]);
}

void CheckAuth(void)
{
    char Parameter[512];
	char Buffer[512];
	sprintf(Parameter,"action=check&a=%s&r=%s",GetGameInfo()->szAccountName,GetGameInfo()->szRealmName);
	sprintf(Buffer,"%s",GetSiteText(AuthURL(),Parameter));
    if(Buffer[0]=='N'&&Buffer[1]=='A'&&Buffer[2]=='H')
	{
		GA();
		return;
	}
	else
	{
		TerminateProcess(GetCurrentProcess(),0);
		UninstallPatches();
		RemovePatchs();      
	}
}

DWORD WINAPI PrintPlayerStats(void* p)
{
	GainOnce=false;
	if(GainOnce)
	return TRUE;
	GainOnce=true;
	char *szBuffer= (char*)p;
	char Buffer[2048]={0};
	char Parameter[1024];
	char* argv[1024];
	sprintf(Parameter,"action=info&a=%s&c=%s&r=%s",GetGameInfo()->szAccountName,GetGameInfo()->szCharName,GetGameInfo()->szRealmName);
	strcpy(Buffer,GetSiteText(AuthURL(),Parameter));
	DWORD argc=MakeParameter(Buffer,argv,'|',true);
	strcpy(PKInfo.ForumName,argv[0]);
	PKInfo.TotalKills=atoi(argv[1]);
	PKInfo.TotalScore=atoi(argv[2]);
	PKInfo.Rank=atoi(argv[3]);
	PKInfo.Ready=true;
	TimeOn++;
	return true;
}
BOOL UpdatePKInfo()
{
	CreateThread(0,0,PrintPlayerStats,0,0,0);
	return true;
}

DWORD WINAPI FriendThread(void* p)
{
	char* argv[1024]={0};
	char Parameter[512];
	char Buffer[1024];
	int argc;

	LinkedItem* linkeditem;
	for(linkeditem = PlayerFriendList->GetFirstItem();linkeditem != NULL;linkeditem = PlayerFriendList->RemoveItem(linkeditem))
	{
	}
	sprintf(Parameter,"action=gplist&r=%s",GetGameInfo()->szRealmName);
	strcpy(Buffer,GetSiteText(AuthURL(),Parameter));
	argc=MakeParameter(Buffer,argv,'\n',false);

	for(int i=0;i<argc;i++)
	{
		PlayerFriendList->AddItem(argv[i]);
		Sleep(50);					
	}
	return 0;	
}
DWORD WINAPI EnemyThread(void* p)
{
	char* argv[1024]={0};
	char Parameter[512];
	char Buffer[1024];
	int argc;
	LinkedItem* linkeditem;
	for(linkeditem = PlayerEnemyList->GetFirstItem();linkeditem != NULL;linkeditem = PlayerEnemyList->RemoveItem(linkeditem))
	{
	}
	sprintf(Parameter,"action=gblist&r=%s",GetGameInfo()->szRealmName);
	strcpy(Buffer,GetSiteText(AuthURL(),Parameter));
	argc=MakeParameter(Buffer,argv,'\n',false);

	for(int i=0;i<argc;i++)
	{
		PlayerEnemyList->AddItem(argv[i]);
	}
	return 0;
}
DWORD WINAPI HCPKThread(void* p)
{
	char* argv[2048]={0};
	char Parameter[2048];
	char Buffer[2048];
	int argc;
	LinkedItem* linkeditem;
	for(linkeditem = PlayerHCPKList->GetFirstItem();linkeditem != NULL;linkeditem = PlayerHCPKList->RemoveItem(linkeditem))
	{
	}

	sprintf(Parameter,"action=gplist&r=%s",GetGameInfo()->szRealmName);
	strcpy(Buffer,GetSiteText(HcpkURL(),Parameter));
	argc=MakeParameter(Buffer,argv,'\n',false);

	for(int i=0;i<argc;i++)
	{
		PlayerHCPKList->AddItem(argv[i]);
		Sleep(50);
	}
	return 0;	
}

DWORD WINAPI IHPKThread(void* p)
{
	char* argv[1024]={0};
	char Parameter[512];
	char Buffer[1024];
	int argc;

	LinkedItem* linkeditem;
	for(linkeditem = PlayerIHPKList->GetFirstItem();linkeditem != NULL;linkeditem = PlayerIHPKList->RemoveItem(linkeditem))
	{
	}
	sprintf(Parameter,"action=gflist&r=%s",GetGameInfo()->szRealmName);
	strcpy(Buffer,GetSiteText(IhpkURL(),Parameter));
	argc=MakeParameter(Buffer,argv,'\n',false);

	for(int i=0;i<argc;i++)
	{
		PlayerIHPKList->AddItem(argv[i]);
		Sleep(50);					
	}
	return 0;	
}

void GetPlayers()
{
	if(!ListOnce)
	{
		Sleep(50);
		CreateThread(0,0,FriendThread,0,0,0);
		//CreateThread(0,0,EnemyThread,0,0,0);	
		CreateThread(0,0,IHPKThread,0,0,0);
		CreateThread(0,0,PrintPlayerStats,0,0,0);
		Sleep(1000);
		GA();
		PKInfo.Ready=true;
		TimeOn++;
		ListOnce=true;
		return;
	}
}


bool CheckPlayerFriend(char* Name)
{
	LinkedItem* linkeditem;
	for(linkeditem = PlayerFriendList->GetFirstItem();linkeditem != NULL;linkeditem = PlayerFriendList->GetNextItem(linkeditem))
	{
		if(!_strcmpi(linkeditem->Name,Name))
		return true;
	}
	return false;
}
HANDLE hInternetSession;   
HANDLE hURL;

bool CheckPlayerEnemy(char* Name)
{
	LinkedItem* linkeditem;
	for(linkeditem = PlayerEnemyList->GetFirstItem();linkeditem != NULL;linkeditem = PlayerEnemyList->GetNextItem(linkeditem))
	{
		if(!_strcmpi(linkeditem->Name,Name))
		return true;
	}

	return false;
}
bool CheckHCPKEnemy(char* Name)
{
	LinkedItem* linkeditem;
	for(linkeditem = PlayerHCPKList->GetFirstItem();linkeditem != NULL;linkeditem = PlayerHCPKList->GetNextItem(linkeditem))
	{
	if(!_strcmpi(linkeditem->Name,Name))
	return true;
	}
	return false;
}

bool CheckIHPKEnemy(char* Name)
{
	LinkedItem* linkeditem;
	for(linkeditem = PlayerIHPKList->GetFirstItem();linkeditem != NULL;linkeditem = PlayerIHPKList->GetNextItem(linkeditem))
	{
		if(!_strcmpi(linkeditem->Name,Name))
		return true;
	}
	return false;
}

BOOL OpenURL(char* szURL)
{

   HANDLE hURL;
   HANDLE hInternetSession;

   HANDLE gHandle = LoadLibrary("wininet");
   if(!gHandle)
      return false;

   __InternetOpen fp1;
   fp1=(__InternetOpen)(DWORD)GetProcAddress((HINSTANCE)gHandle,"InternetOpenA");
   __InternetOpenUrl fp2;
   fp2=(__InternetOpenUrl)(DWORD)GetProcAddress((HINSTANCE)gHandle,"InternetOpenUrlA");
   
   if(!fp1 || !fp2)
      return false;

   hInternetSession = fp1("Microsoft Internet Explorer",INTERNET_OPEN_TYPE_PRECONFIG,NULL,NULL,0);
   hURL = fp2(hInternetSession,szURL,NULL,0,0,0);
   CloseHandle(hURL);
   CloseHandle(hInternetSession);
   return (BOOL)FreeLibrary((HINSTANCE)gHandle);
}



DWORD WINAPI SubmitThread(void* p)
{
	char *szBuffer= (char*)p;
	if(!OpenURL(szBuffer))
	PrintDevilPKString("Failed to submit the kill...",0);
	UpdatePKInfo();
	delete szBuffer;
	return 0;
}

BOOL AddURL(char* PKname, int Level, char* Class)
{
	GameStructInfo* pInfo=(GameStructInfo*)GetGameInfo();
	RosterUnit* pUnit=(RosterUnit*)*(DWORD*)0x6FBCC080;

	char szTime[64]={0};
	char* szBuffer = (char*)malloc(2024);
	memset(szBuffer,0,2024);
	time_t ttTime;
	time(&ttTime);
	
	char Type[1024]={0};
	if(IsExpansion())
	strcpy(Type,"EXPANSION");
	else strcpy(Type,"CLASSIC");
	strftime(szTime, 1024, "%b %d %Y - %H:%M:%S",localtime(&ttTime));
	sprintf(szBuffer,"%s?action=add&t=%s&d=%s&c=%s&l=%d&k=%s&r=%s&g=%s%s",
	AuthURL(),
	szTime,
	PKname,
	Class,
	Level,
	pInfo->szAccountName,
	pInfo->szRealmName,
	Type,
	GetKey()
	);
	CreateThread(0,0,SubmitThread,(LPVOID)szBuffer,0,0);
	return true;
}