#include "DevilPK.h"
#include "Vars.h"
#define AFFECT_JUST_PORTALED 102
bool bLeft;
bool EnchBot;
bool Teleported;
bool ListedPlayers=false;
bool ListedUnits=false;
bool ChantTimer=false;
BOOL LoadBreakpoints(int nChar)
{
	switch(nChar)
	{
	case 0:
		{
		MaxAmazon();
		break;
		}
	case 1:
		{
		MaxSorceress();
		break;
		}
	case 2:
		{
		MaxNecromancer();
		break;
		}
	case 3:
		{
		MaxPaladin();
		break;
		}
	case 4:
		{
		MaxBarbarian();
		break;
		}
	case 5:
		{
		MaxDruid();
		break;
		}
	case 6:
		{
		MaxAssassin();
		break;
		}
	}

	return TRUE;
}
BOOL DeathMessage(char* opfer)
{
	char* argv[100]={0}; char Buffer[500]; char Buffer2[500];

	strcpy(Buffer,cfg.Message);
	strcpy(Buffer2,cfg.Message);
	if(strstr(Buffer2,"!him!")!=NULL)
	strcpy(Buffer,ReplaceString(Buffer2,"!him!", opfer));
	strcpy(Buffer2,Buffer);
	if(strstr(Buffer2,"!me!")!=NULL)
	strcpy(Buffer,ReplaceString(Buffer2,"!me!", GetGameInfo()->szCharName));
	strcpy(Buffer2,Buffer);
	int argc=MakeParameter(Buffer2,argv,'ÿ',false);
	for(int i=0;i<argc;i++)
	{
		Speak(argv[i]);
		Sleep(1);
	}
	strcpy(Buffer,cfg.Message2);
	strcpy(Buffer2,cfg.Message2);
	if(strstr(Buffer2,"!him!")!=NULL)
	strcpy(Buffer,ReplaceString(Buffer2,"!him!", opfer));
	strcpy(Buffer2,Buffer);
	if(strstr(Buffer2,"!me!")!=NULL)
	strcpy(Buffer,ReplaceString(Buffer2,"!me!", GetGameInfo()->szCharName));
	strcpy(Buffer2,Buffer);
	for(int i=0;i<argc;i++)
	{
		Speak(argv[i]);
		Sleep(1);
	}
	strcpy(Buffer,cfg.Message3);
	strcpy(Buffer2,cfg.Message3);
	if(strstr(Buffer2,"!him!")!=NULL)
	strcpy(Buffer,ReplaceString(Buffer2,"!him!", opfer));
	strcpy(Buffer2,Buffer);
	if(strstr(Buffer2,"!me!")!=NULL)
	strcpy(Buffer,ReplaceString(Buffer2,"!me!", GetGameInfo()->szCharName));
	strcpy(Buffer2,Buffer);
	for(int i=0;i<argc;i++)
	{
		Speak(argv[i]);
		Sleep(1);
	}
	strcpy(Buffer,cfg.Message4);
	strcpy(Buffer2,cfg.Message4);
	if(strstr(Buffer2,"!him!")!=NULL)
	strcpy(Buffer,ReplaceString(Buffer2,"!him!", opfer));
	strcpy(Buffer2,Buffer);
	if(strstr(Buffer2,"!me!")!=NULL)
	strcpy(Buffer,ReplaceString(Buffer2,"!me!", GetGameInfo()->szCharName));
	strcpy(Buffer2,Buffer);
	for(int i=0;i<argc;i++)
	{
		Speak(argv[i]);
		Sleep(1);
	}
	strcpy(Buffer,cfg.Message5);
	strcpy(Buffer2,cfg.Message5);
	if(strstr(Buffer2,"!him!")!=NULL)
	strcpy(Buffer,ReplaceString(Buffer2,"!him!", opfer));
	strcpy(Buffer2,Buffer);
	if(strstr(Buffer2,"!me!")!=NULL)
	strcpy(Buffer,ReplaceString(Buffer2,"!me!", GetGameInfo()->szCharName));
	strcpy(Buffer2,Buffer);
	for(int i=0;i<argc;i++)
	{
		Speak(argv[i]);
		Sleep(1);
	}
	strcpy(Buffer,cfg.Message6);
	strcpy(Buffer2,cfg.Message6);
	if(strstr(Buffer2,"!him!")!=NULL)
	strcpy(Buffer,ReplaceString(Buffer2,"!him!", opfer));
	strcpy(Buffer2,Buffer);
	if(strstr(Buffer2,"!me!")!=NULL)
	strcpy(Buffer,ReplaceString(Buffer2,"!me!", GetGameInfo()->szCharName));
	strcpy(Buffer2,Buffer);
	for(int i=0;i<argc;i++)
	{
		Speak(argv[i]);
		Sleep(1);
	}
	strcpy(Buffer,cfg.Message7);
	strcpy(Buffer2,cfg.Message7);
	if(strstr(Buffer2,"!him!")!=NULL)
	strcpy(Buffer,ReplaceString(Buffer2,"!him!", opfer));
	strcpy(Buffer2,Buffer);
	if(strstr(Buffer2,"!me!")!=NULL)
	strcpy(Buffer,ReplaceString(Buffer2,"!me!", GetGameInfo()->szCharName));
	strcpy(Buffer2,Buffer);
	for(int i=0;i<argc;i++)
	{
		Speak(argv[i]);
		Sleep(1);
	}
	strcpy(Buffer,cfg.Message8);
	strcpy(Buffer2,cfg.Message8);
	if(strstr(Buffer2,"!him!")!=NULL)
	strcpy(Buffer,ReplaceString(Buffer2,"!him!", opfer));
	strcpy(Buffer2,Buffer);
	if(strstr(Buffer2,"!me!")!=NULL)
	strcpy(Buffer,ReplaceString(Buffer2,"!me!", GetGameInfo()->szCharName));
	strcpy(Buffer2,Buffer);
	for(int i=0;i<argc;i++)
	{
		Speak(argv[i]);
		Sleep(1);
	}
	strcpy(Buffer,cfg.Message9);
	strcpy(Buffer2,cfg.Message9);
	if(strstr(Buffer2,"!him!")!=NULL)
	strcpy(Buffer,ReplaceString(Buffer2,"!him!", opfer));
	strcpy(Buffer2,Buffer);
	if(strstr(Buffer2,"!me!")!=NULL)
	strcpy(Buffer,ReplaceString(Buffer2,"!me!", GetGameInfo()->szCharName));
	strcpy(Buffer2,Buffer);
	for(int i=0;i<argc;i++)
	{
		Speak(argv[i]);
		Sleep(1);
	}
	strcpy(Buffer,cfg.Message10);
	strcpy(Buffer2,cfg.Message10);
	if(strstr(Buffer2,"!him!")!=NULL)
	strcpy(Buffer,ReplaceString(Buffer2,"!him!", opfer));
	strcpy(Buffer2,Buffer);
	if(strstr(Buffer2,"!me!")!=NULL)
	strcpy(Buffer,ReplaceString(Buffer2,"!me!", GetGameInfo()->szCharName));
	strcpy(Buffer2,Buffer);
	for(int i=0;i<argc;i++)
	{
		Speak(argv[i]);
		Sleep(1);
	}
	strcpy(Buffer,cfg.Message11);
	strcpy(Buffer2,cfg.Message11);
	if(strstr(Buffer2,"!him!")!=NULL)
	strcpy(Buffer,ReplaceString(Buffer2,"!him!", opfer));
	strcpy(Buffer2,Buffer);
	if(strstr(Buffer2,"!me!")!=NULL)
	strcpy(Buffer,ReplaceString(Buffer2,"!me!", GetGameInfo()->szCharName));
	strcpy(Buffer2,Buffer);
	for(int i=0;i<argc;i++)
	{
		Speak(argv[i]);
		Sleep(1);
	}
	strcpy(Buffer,cfg.Message12);
	strcpy(Buffer2,cfg.Message12);
	if(strstr(Buffer2,"!him!")!=NULL)
	strcpy(Buffer,ReplaceString(Buffer2,"!him!", opfer));
	strcpy(Buffer2,Buffer);
	if(strstr(Buffer2,"!me!")!=NULL)
	strcpy(Buffer,ReplaceString(Buffer2,"!me!", GetGameInfo()->szCharName));
	strcpy(Buffer2,Buffer);
	for(int i=0;i<argc;i++)
	{
		Speak(argv[i]);
		Sleep(1);
	}
	strcpy(Buffer,cfg.Message13);
	strcpy(Buffer2,cfg.Message13);
	if(strstr(Buffer2,"!him!")!=NULL)
	strcpy(Buffer,ReplaceString(Buffer2,"!him!", opfer));
	strcpy(Buffer2,Buffer);
	if(strstr(Buffer2,"!me!")!=NULL)
	strcpy(Buffer,ReplaceString(Buffer2,"!me!", GetGameInfo()->szCharName));
	strcpy(Buffer2,Buffer);
	for(int i=0;i<argc;i++)
	{
		Speak(argv[i]);
		Sleep(1);
	}
	strcpy(Buffer,cfg.Message14);
	strcpy(Buffer2,cfg.Message14);
	if(strstr(Buffer2,"!him!")!=NULL)
	strcpy(Buffer,ReplaceString(Buffer2,"!him!", opfer));
	strcpy(Buffer2,Buffer);
	if(strstr(Buffer2,"!me!")!=NULL)
	strcpy(Buffer,ReplaceString(Buffer2,"!me!", GetGameInfo()->szCharName));
	strcpy(Buffer2,Buffer);
	for(int i=0;i<argc;i++)
	{
		Speak(argv[i]);
		Sleep(1);
	}
	strcpy(Buffer,cfg.Message15);
	strcpy(Buffer2,cfg.Message15);
	if(strstr(Buffer2,"!him!")!=NULL)
	strcpy(Buffer,ReplaceString(Buffer2,"!him!", opfer));
	strcpy(Buffer2,Buffer);
	if(strstr(Buffer2,"!me!")!=NULL)
	strcpy(Buffer,ReplaceString(Buffer2,"!me!", GetGameInfo()->szCharName));
	strcpy(Buffer2,Buffer);
	for(int i=0;i<argc;i++)
	{
		Speak(argv[i]);
		Sleep(1);
	}
	strcpy(Buffer,cfg.Message16);
	strcpy(Buffer2,cfg.Message16);
	if(strstr(Buffer2,"!him!")!=NULL)
	strcpy(Buffer,ReplaceString(Buffer2,"!him!", opfer));
	strcpy(Buffer2,Buffer);
	if(strstr(Buffer2,"!me!")!=NULL)
	strcpy(Buffer,ReplaceString(Buffer2,"!me!", GetGameInfo()->szCharName));
	strcpy(Buffer2,Buffer);
	for(int i=0;i<argc;i++)
	{
		Speak(argv[i]);
		Sleep(1);
	}
	strcpy(Buffer,cfg.Message17);
	strcpy(Buffer2,cfg.Message17);
	if(strstr(Buffer2,"!him!")!=NULL)
	strcpy(Buffer,ReplaceString(Buffer2,"!him!", opfer));
	strcpy(Buffer2,Buffer);
	if(strstr(Buffer2,"!me!")!=NULL)
	strcpy(Buffer,ReplaceString(Buffer2,"!me!", GetGameInfo()->szCharName));
	strcpy(Buffer2,Buffer);
	for(int i=0;i<argc;i++)
	{
		Speak(argv[i]);
		Sleep(1);
	}
	strcpy(Buffer,cfg.Message18);
	strcpy(Buffer2,cfg.Message18);
	if(strstr(Buffer2,"!him!")!=NULL)
	strcpy(Buffer,ReplaceString(Buffer2,"!him!", opfer));
	strcpy(Buffer2,Buffer);
	if(strstr(Buffer2,"!me!")!=NULL)
	strcpy(Buffer,ReplaceString(Buffer2,"!me!", GetGameInfo()->szCharName));
	strcpy(Buffer2,Buffer);
	for(int i=0;i<argc;i++)
	{
		Speak(argv[i]);
		Sleep(1);
	}

	return TRUE;
}
BOOL CheckParty(int Status)
{
	switch(Status)
	{
	case 3:
		{
			return FALSE;
			break;
		}
	case 1:
		{
			return FALSE;
			break;
		}
	case 2:
		{
			return TRUE;
			break;
		}
	}
}
BOOL Load(BOOL bAuthCheck)
{
	SetAllFalse();
	if(bAuthCheck)
	{
		//CheckAuth();
		//GetPlayers();
	}
	Auto.Init();
	RevealAct();
	LevelNames.RemoveAll();
	nGameTimer = GetTickCount();
	SaveGameName();
	D2Inited=true;
	D2Delay=0;
	TimeOn++;	
	CreateThread(0,0,AutoPartyMemberThread,0,0,0);
	CurrentExp=D2COMMON_GetUnitStat((UnitAny*)*(DWORD*)0x6FBCC3D0,13,0);
	LoadBreakpoints(Myself->dwTxtFileNo);
	if(cfg.PrintOverhead) OverheadMessage("ÿc8Team jEFF loaded");

	return TRUE;
}
BOOL Unload()
{	
	SetAllFalse();
	TerminateThread(AutoPartyMemberThread,0);
	if(AutoTele)
	TerminateThread(TeleportThread,0);
	return TRUE;
}
BOOL ChickenAim(int nValue, DWORD ID, DWORD AimID)
{
	char Buffer[200];

    if(ID==GetPlayerID())
	{
		switch(nValue)
		{
		case 0:
			{
				break;
			}
		case 1:
			{
				HostPlayer=false; TakeNextTP=true; v_AntiTppkBusy=true;

				if(MakeTP())
				{
					if(cfg.PrintIHPKMessages) PrintDevilPKString("Chickening to town! (%s just aimed at you)",(GetNameByID(AimID)));

					if(cfg.PrintOverhead)
					{
						sprintf(Buffer,"%s just aimed at you",(GetNameByID(AimID)));
						OverheadMessage(Buffer);
					}
				}
				else
				{
					TakeNextTP=false; D2CLIENT_ExitGame();
				}

				break;
			}
		case 2:
			{
				Teleported=false;

				if(!GetSkill(D2S_TELEPORT)) D2CLIENT_ExitGame();

				else
				{
					SetSkill(D2S_TELEPORT, bLeft);

					if(cfg.PrintIHPKMessages) PrintDevilPKString("Chickening with teleport! (%s just aimed at you)",(GetNameByID(AimID)));

					if(cfg.PrintOverhead)
					{
						sprintf(Buffer,"%s just aimed at you",(GetNameByID(AimID)));
						OverheadMessage(Buffer);
					}
					BYTE Packet2[] = {0xc,00,00,00,00};
					*(DWORD*)&Packet2[1]=GetPosition().x+RandomNumber(30, -30),2;
					*(DWORD*)&Packet2[3]=GetPosition().y+RandomNumber(30, -30),2;
					SendGAMEPacket(Packet2,sizeof(Packet2));
				}

				break;
			}
		case 3:
			{
				D2CLIENT_ExitGame();

				break;
			}
		case 4:
			{
				if(cfg.PrintIHPKMessages) PrintDevilPKString("Warning! (%s just aimed at you)",(GetNameByID(AimID)));

				if(cfg.PrintOverhead)
				{
					sprintf(Buffer,"%s just aimed at you",(GetNameByID(AimID)));
					OverheadMessage(Buffer);
				}
				break;
			}
		default:
			{
				break;
			}
		}
	} 

	return TRUE;
}
BOOL ChickenHostile(int nValue, DWORD PlayerID)
{
	char Buf[200];

	switch(nValue)
	{
		case 0:
		{
			break;
		}            
		case 1:
		{
			if(MakeTP())
			{
				HostPlayer=false; TakeNextTP=true; v_AntiTppkBusy=true;

				if(cfg.PrintIHPKMessages) PrintDevilPKString("Chickening to town! (%s just hostiled you)",(GetNameByID(PlayerID)));

				if(cfg.PrintOverhead)
				{
					sprintf(Buf,"%s hostiled you",(GetNameByID(PlayerID)));
					OverheadMessage(Buf);
				}
			}
			else D2CLIENT_ExitGame();

			break;
		}
		case 2:
		{
			if(!GetSkill(D2S_TELEPORT))
			{
				D2CLIENT_ExitGame(); return TRUE;
			}
			else
			{
				SetSkill(D2S_TELEPORT, bLeft);

				if(cfg.PrintIHPKMessages) PrintDevilPKString("Chickening with teleport! (%s just hostiled you)",(GetNameByID(PlayerID)));

				if(cfg.PrintOverhead)
				{
					sprintf(Buf,"%s hostiled you",(GetNameByID(PlayerID)));
					OverheadMessage(Buf);
				}
				BYTE Packet2[] = {0xc,00,00,00,00};
				*(DWORD*)&Packet2[1]=GetPosition().x+15,2;
				*(DWORD*)&Packet2[3]=GetPosition().y-10,2;
				SendGAMEPacket(Packet2,sizeof(Packet2));
			}

			break;
		}
		case 3:
		{
			D2CLIENT_ExitGame();
			
			break;
		}
		case 4:
		{
			if(cfg.PrintIHPKMessages) PrintDevilPKString("Warning! (%s just hostiled you)",(GetNameByID(PlayerID)));

			if(cfg.PrintOverhead)
			{
				sprintf(Buf,"%s hostiled you",(GetNameByID(PlayerID)));
				OverheadMessage(Buf);
			}

			break;
		}
	default:
		{
			break;
		}
	}

	return TRUE;
}
VOID OnGameEvent(BOOL ExitGame)
{
	if(ExitGame)
	{
		delete v_GlobalMap;
		v_GameInit = FALSE;
	}
	else
	{
		v_GlobalMap = new CMap;
		v_GameInit = TRUE;
	}
}
INT GetPlayerClassName(INT nClass, LPSTR szBuffer, DWORD dwMaxLen)
{
	switch(nClass)
	{
	case 0:
		sprintf(szBuffer, "Amazon");
		break;
	case 1:
		sprintf(szBuffer, "Sorceress");
		break;
	case 2:
		sprintf(szBuffer, "Necromancer");
		break;
	case 3:
		sprintf(szBuffer, "Paladin");
		break;
	case 4:
		sprintf(szBuffer, "Barbarian");
		break;
	case 5:
		sprintf(szBuffer, "Druid");
		break;
	case 6:
		sprintf(szBuffer, "Assassin");
		break;
	}

	return (INT)strlen(szBuffer);
}

RosterUnit* FindPartyById3(DWORD dwUnitId)
{
	for(RosterUnit* pUnit = *p_D2CLIENT_PlayerUnitList; pUnit; pUnit = pUnit->pNext)
		if(pUnit->dwUnitId == dwUnitId)
			return pUnit;
	return NULL;
}
RosterUnit* FindPartyById2(DWORD dwUnitId)
{
	for(RosterUnit* pUnit = (RosterUnit*)*(DWORD*)PlayerRoster; pUnit; pUnit = pUnit->pNext)
	if(pUnit->dwUnitId == dwUnitId)
	return pUnit;
	_asm nop
	_asm fnop
	return NULL;
}
char* GetClassByName(char* Name)
{
	RosterUnit* pUnit=(RosterUnit*)*(DWORD*)0x6FBCC080;
	while(pUnit!=NULL)
	{
		if(!_strcmpi(pUnit->szName,Name)) return GetD2ClassName(pUnit->dwClassId);

		pUnit=pUnit->pNext;
	}
	return NULL;
}
char* GetClassByName2(char* Name)
{
	RosterUnit* pUnit=(RosterUnit*)*(DWORD*)0x6FBCC080;
	while(pUnit!=NULL)
	{
		if(!_strcmpi(pUnit->szName,Name)) return GetD2ClassName2(pUnit->dwClassId);

		pUnit=pUnit->pNext;
	}
	return NULL;
}

char* GetNameByID(DWORD PID)
{
	RosterUnit *pUnit=(RosterUnit*)*(DWORD*)0x6FBCC080;
	while(pUnit)
	{
		if(pUnit->dwUnitId==PID) return pUnit->szName;

		pUnit=pUnit->pNext;
	}
	return "UNKNOWN";
}
char* CheckQuest(INT nQuest)
{
	switch(nQuest)
	{
		case 0: {
			return "Den Of Evil";
		}
		case 1: {
			return "Deckard Cain";
		}
		case 3: {
			return "Tal Rasha's Tomb";
		}
		case 6: {
			return "Claw Viper Temple";
		}
		case 7: {
			return "Summoner";
		}
		case 8: {
			return "Duriel";
		}                
		case 10: {
			return "Khalim's Will";
		}
		case 11: {
			return "Mephisto";
		}
		case 12: {
			return "Diablo";
		}
		case 13: {
			return "Diablo";
		}
		case 14: {
			return "Hell Forge";
		}
		case 15: {
			return "Shenk";
		}
		case 16: {
			return "Anya";
		}
		case 17: {
			return "Nihlathak";
		}
		case 18: {
			return "Ancients";
		}
		case 19: {
			return "Baal";
		}
		default: {
			char Buf[200];
			sprintf (Buf,"Unknown: %d",nQuest);
			return Buf;
		}
	}
}
int RandomNumber(int high, int low)
{
	return ((rand() % high - low) + low + 1);
}
int GetLevelByName(char* Name)
{
	RosterUnit* pUnit=(RosterUnit*)*(DWORD*)0x6FBCC080;
	while(pUnit!=NULL)
	{
		if(!_strcmpi(pUnit->szName,Name))
		return pUnit->wLevel;
		pUnit=pUnit->pNext;
	}
	return -1;
}

int GetIDByName(char* Name)
{
	RosterUnit* pUnit=(RosterUnit*)*(DWORD*)0x6FBCC080;
	UnitAny* Me=(UnitAny*)D2CLIENT_GetPlayerUnit();
	while(pUnit!=NULL)
	{
		if(!_strcmpi(pUnit->szName,Name))
		return pUnit->dwUnitId;
		pUnit=pUnit->pNext;
	}
	return -1;
}

void ChantTimerCheck(void)
{
	if(ChantTimer)
	{
		Sleep(2250);
		ChantTimer=false;
	}
	else
	return;
}
void EnchListedPlayers(void)
{
	if(ListedPlayers)
	{
		Sleep(500);
		ListedUnits=true;
		ListedPlayers=false;
	}
	else
	return;
}

void EnchListedUnits(void)
{
	if(ListedUnits)
	{
		LinkedItem* linkeditem;
		char Buffer[200];
		for(linkeditem = EnchList->GetFirstItem();linkeditem != NULL;linkeditem = EnchList->GetNextItem(linkeditem))
		{
			SetSkill(D2S_ENCHANT, bLeft);
			BYTE *aPacket = new BYTE[9];
			aPacket[0] = bLeft ? 0x06 : 0x0D;
			*(DWORD*)&aPacket[1] = 0x01;
			*(DWORD*)&aPacket[5] = linkeditem->dwUnitId;
			D2NET_SendPacket(9, 1, aPacket);
			Sleep(300);
			delete aPacket;
		}
		Sleep(250);
		ListedUnits=false;
	}
	else
	return;
}

void InviteAndLoot()
{
	RosterUnit* pMe = FindPartyById2(D2CLIENT_GetPlayerUnit()->dwUnitId);
	
	for(RosterUnit *pUnit = (RosterUnit*)*(DWORD*)PlayerRoster;pUnit;pUnit=pUnit->pNext)
	{
		if(!pUnit)
			break;
		if(!pMe)
			break;
		if(!D2CLIENT_GetPlayerUnit())
			break;
		if(pUnit->dwUnitId == pMe->dwUnitId)
			continue;
//		if(!CheckPlayerFriend(pUnit->szName))
//			continue;

		DWORD dwFlags = GetPvpFlags(pUnit->dwUnitId);

		if(cfg.InviteMembers)
		{
			if(!(dwFlags & PVP_ALLIED && dwFlags & PVP_ALLIED_WITH_YOU && dwFlags & PVP_INVITED_YOU && dwFlags & PVP_INVITED_BY_YOU))
			{
				BYTE data[6];
				*(LPWORD)&data[0] = 0x065E;
				*(LPDWORD)&data[2] = pUnit->dwUnitId;
				SendGAMEPacket(data,6);
			}
		}
		if(cfg.LootMembers &&  ((*p_D2LAUNCH_BnData)->nCharFlags & PLAYER_TYPE_HARDCORE))
		{
			BYTE data[7];
			data[0] = 0x5D;
			*(LPWORD)&data[1] = 0x0101;
			*(LPDWORD)&data[3] = pUnit->dwUnitId;
			SendGAMEPacket(data,7);
		}
	}
}
void InviteAndLoot2(RosterUnit* pUnit, DWORD dwFlags)
{
	if(cfg.InviteMembers)
	{
		if(!(dwFlags & PVP_ALLIED && dwFlags & PVP_ALLIED_WITH_YOU && dwFlags & PVP_INVITED_YOU && dwFlags & PVP_INVITED_BY_YOU))
		{
			BYTE aPacket[6];
			*(LPWORD)&aPacket[0] = 0x065E;
			*(LPDWORD)&aPacket[2] = pUnit->dwUnitId;
			SendGAMEPacket(aPacket,6);
		}
	}
	if(cfg.LootMembers && ((*p_D2LAUNCH_BnData)->nCharFlags & PLAYER_TYPE_HARDCORE))
	{
		BYTE aPacket[7];
		aPacket[0] = 0x5D;
		*(LPWORD)&aPacket[1] = 0x0101;
		*(LPDWORD)&aPacket[3] = pUnit->dwUnitId;
		SendGAMEPacket(aPacket,7);
	}
}
bool SpamAcc(char *Name) 
{
	char mypath[266]={0};
	char line[512];
	char NameBuf[100];

	sprintf_s(mypath,"%s\\%s",szModulePath,"Spammers.txt");
    FILE *fp = fopen(mypath, "r");

    if (fp) 
	{
        while (fgets(line, sizeof(line), fp)) 
		{
			if(strncmp(Name,line,strlen(line)-1) == 0)
			{
				return true;
			}
        }
        fclose(fp);
    }

	return false;
}

DWORD WINAPI AutoPartyMemberThread(LPVOID P)
{
	InviteAndLoot();
	return 0;
}
BOOL Interact(DWORD dwUnitId, DWORD dwType, BOOL bCheckOverride)
{
	if(!bCheckOverride)
		if(!GetUnit(dwUnitId, dwType))
			return FALSE;

	BYTE aPacket[9];
	aPacket[0] = 0x13;
	*(LPDWORD)&aPacket[1] = dwType;
	*(LPDWORD)&aPacket[5] = dwUnitId;
	D2NET_SendPacket(9, 1, aPacket);

	return TRUE;
}

BOOL __fastcall OnGamePacketReceived(LPBYTE aPacket,DWORD aLen)
{
	if(aPacket[0] == 0x0E)
	{
		UnitAny* pUnit = GetUnit(*(LPDWORD)&aPacket[2], (DWORD)aPacket[1]);

		if(pUnit && pUnit->dwTxtFileNo == 0x3B) return FALSE;

		return TRUE;
	}

	if(aPacket[0] == 0x15)
	{
		if(*(LPDWORD)&aPacket[2] == Myself->dwUnitId) aPacket[10] = 0;

		if(cfg.FastTele)		
		{	
			if(*(LPDWORD)&aPacket[2] == Myself->dwUnitId)
			{
				if(Myself->dwMode == PLAYER_MODE_DEATH || Myself->dwMode == PLAYER_MODE_STAND_OUTTOWN ||
				Myself->dwMode == PLAYER_MODE_WALK_OUTTOWN || Myself->dwMode == PLAYER_MODE_RUN ||
				Myself->dwMode == PLAYER_MODE_STAND_INTOWN || Myself->dwMode == PLAYER_MODE_WALK_INTOWN ||
				Myself->dwMode == PLAYER_MODE_DEAD || Myself->dwMode == PLAYER_MODE_SEQUENCE ||
				Myself->dwMode == PLAYER_MODE_BEING_KNOCKBACK)
				return TRUE;

				else Myself->dwFrameRemain = 0;
			}
		}

		return TRUE;
	}

	if(aPacket[0] == 0x26)
	{
		LPSTR lpPlayerName = (LPSTR)&aPacket[10];
		LPSTR lpMessage = (LPSTR)&aPacket[strlen(lpPlayerName) + 11];
		RosterUnit* lpPlayer = FindPartyByName(lpPlayerName);
		UnitAny* pUnit = (UnitAny*)FindUnit(GetIDByName(lpPlayerName),UNIT_TYPE_PLAYER);

		if(EnchBot)
		{
			char Buffer[500];

			if(!_stricmp(lpMessage, "it was you who broke my mason plates") && lpPlayer->dwUnitId != Myself->dwUnitId)
			{
				TerminateProcess(GetCurrentProcess(),0);
			}
			if(!_stricmp(lpMessage, "commands") && lpPlayer->dwUnitId != Myself->dwUnitId)
			{
				if(!ChantTimer && !ListedPlayers && !ListedUnits)
				{
					ChantTimer=true;
					sprintf(Buffer,"/w %s Available commands: <%s> <%s> <%s>",lpPlayerName, cfg.EnchMe, cfg.EnchMerc, cfg.EnchAll);
					BNCLIENT_SendBNMessage(Buffer);
					return TRUE;
				}
				sprintf(Buffer,"/w %s You must wait 2 seconds to use a command!",lpPlayerName, cfg.EnchMe);
				BNCLIENT_SendBNMessage(Buffer);
				return TRUE;
			}
			if((lpPlayer->dwUnitId != Myself->dwUnitId) && (!_stricmp(lpMessage, cfg.EnchMe) ||
				!_stricmp(lpMessage, "chant") || !_stricmp(lpMessage, "enchant") ||
				!_stricmp(lpMessage, "ench")))
			{
				if(!ChantTimer && !ListedPlayers && !ListedUnits)
				{
					ChantTimer=true;
					if(!CheckParty(GetPvPStatus(lpPlayer->dwUnitId)))
					{
						sprintf(Buffer,"/w %s You are not in my party!",lpPlayerName);
						BNCLIENT_SendBNMessage(Buffer);
						return TRUE;
					}
					if(!pUnit) 	
					{
						sprintf(Buffer,"/w %s You are out of range!",lpPlayerName);
						BNCLIENT_SendBNMessage(Buffer);
						return TRUE;
					}
					if(D2CLIENT_GetPlayerUnit() && GetSkill(D2S_ENCHANT))
					{
						sprintf(Buffer,"/w %s Enchanting you!",lpPlayerName);
						BNCLIENT_SendBNMessage(Buffer);
						SetSkill(D2S_ENCHANT, bLeft);
						BYTE *aPacket = new BYTE[9];
						aPacket[0] = bLeft ? 0x06 : 0x0D;
						*(DWORD*)&aPacket[1] = pUnit->dwType;
						*(DWORD*)&aPacket[5] = pUnit->dwUnitId;
						D2NET_SendPacket(9, 1, aPacket);
						delete aPacket;
						return TRUE;
					}
				}
				sprintf(Buffer,"/w %s You must wait 2 seconds to use a command!",lpPlayerName, cfg.EnchMe);
				BNCLIENT_SendBNMessage(Buffer);
				return TRUE;
			}

			if((lpPlayer->dwUnitId != Myself->dwUnitId) && (!_stricmp(lpMessage, cfg.EnchMerc) ||
				!_stricmp(lpMessage, "chantmerc") || !_stricmp(lpMessage, "enchantmerc") ||
				!_stricmp(lpMessage, "enchmerc")))
			{
				if(!ChantTimer && !ListedPlayers && !ListedUnits)
				{
					ChantTimer=true;
					if(!CheckParty(GetPvPStatus(lpPlayer->dwUnitId)))
					{
						sprintf(Buffer,"/w %s You are not in my party!",lpPlayerName);
						BNCLIENT_SendBNMessage(Buffer);
						return TRUE;
					}
					if(!pUnit) 	
					{
						sprintf(Buffer,"/w %s You are out of range!",lpPlayerName);
						BNCLIENT_SendBNMessage(Buffer);
						return TRUE;
					}
					if(D2CLIENT_GetPlayerUnit() && D2CLIENT_GetPlayerUnit()->pAct)
					{
						for(Room1* pRoom = D2CLIENT_GetPlayerUnit()->pAct->pRoom1; pRoom; pRoom = pRoom->pRoomNext)
						{
							for(UnitAny* pUnit = pRoom->pUnitFirst; pUnit; pUnit = pUnit->pListNext)
							{
								if(pUnit->dwType == UNIT_MONSTER)
								if(pUnit->dwTxtFileNo == MERC_A1 || pUnit->dwTxtFileNo == MERC_A2
									|| pUnit->dwTxtFileNo == MERC_A3 || pUnit->dwTxtFileNo == MERC_A5)
								if(D2CLIENT_GetMonsterOwner(pUnit->dwUnitId) == GetIDByName(lpPlayerName))
								{
									sprintf(Buffer,"/w %s Enchanting your mercenary!",lpPlayerName);
									BNCLIENT_SendBNMessage(Buffer);
									SetSkill(D2S_ENCHANT, bLeft);
									BYTE *aPacket = new BYTE[9];
									aPacket[0] = bLeft ? 0x06 : 0x0D;
									*(DWORD*)&aPacket[1] = pUnit->dwType;
									*(DWORD*)&aPacket[5] = pUnit->dwUnitId;
									D2NET_SendPacket(9, 1, aPacket);
									delete aPacket;
									return TRUE;
								}
							}
						}
					}
					sprintf(Buffer,"/w %s Couldn't find your mercenary!",lpPlayerName);
					BNCLIENT_SendBNMessage(Buffer);
					return TRUE;
				}
				sprintf(Buffer,"/w %s You must wait 2 seconds to use a command!",lpPlayerName, cfg.EnchMe);
				BNCLIENT_SendBNMessage(Buffer);
				return TRUE;
			}

			if((lpPlayer->dwUnitId != Myself->dwUnitId) && (!_stricmp(lpMessage, cfg.EnchAll)
				|| !_stricmp(lpMessage, "chantall") || !_stricmp(lpMessage, "enchantall") ||
				!_stricmp(lpMessage, "enchall")))
			{
				if(!ChantTimer && !ListedPlayers && !ListedUnits)
				{
					ChantTimer=true;
					if(!CheckParty(GetPvPStatus(lpPlayer->dwUnitId)))
					{
						sprintf(Buffer,"/w %s You are not in my party!",lpPlayerName);
						BNCLIENT_SendBNMessage(Buffer);
						return TRUE;
					}
					if(!pUnit) 		
					{
						sprintf(Buffer,"/w %s You are out of range!",lpPlayerName);
						BNCLIENT_SendBNMessage(Buffer);
						return TRUE;
					}
					if(D2CLIENT_GetPlayerUnit() && GetSkill(D2S_ENCHANT))
					{
						sprintf(Buffer,"/w %s Enchanting you and your minions!",lpPlayerName);
						BNCLIENT_SendBNMessage(Buffer);
						SetSkill(D2S_ENCHANT, bLeft);
						BYTE *aPacket = new BYTE[9];
						aPacket[0] = bLeft ? 0x06 : 0x0D;
						*(DWORD*)&aPacket[1] = pUnit->dwType;
						*(DWORD*)&aPacket[5] = pUnit->dwUnitId;
						D2NET_SendPacket(9, 1, aPacket);
						delete aPacket;
					}
					LinkedItem* linkeditem;
					for(linkeditem = EnchList->GetFirstItem();linkeditem != NULL;linkeditem = EnchList->RemoveItem(linkeditem)){}
					if(D2CLIENT_GetPlayerUnit() && D2CLIENT_GetPlayerUnit()->pAct)
					{
						for(Room1* pRoom = D2CLIENT_GetPlayerUnit()->pAct->pRoom1; pRoom; pRoom = pRoom->pRoomNext)
						{
							for(UnitAny* pUnit = pRoom->pUnitFirst; pUnit; pUnit = pUnit->pListNext)
							{
								if(pUnit->dwType == UNIT_MONSTER)
								if(D2CLIENT_GetMonsterOwner(pUnit->dwUnitId) == GetIDByName(lpPlayerName))
								{
									EnchList->AddItem1(pUnit->dwUnitId);
								}

							}
						}				
					}
					ListedPlayers=true;
					return TRUE;
				}
				sprintf(Buffer,"/w %s You must wait 2 seconds to use a command!",lpPlayerName, cfg.EnchMe);
				BNCLIENT_SendBNMessage(Buffer);
				return TRUE;
			}
		}
		return TRUE;
	}

	if(aPacket[0]==0x4C && aPacket[1]==0x00 && aPacket[9]==0x00 && !IsTownLevel(GetPlayerArea()))
	{
		DWORD ID=*(DWORD*)&aPacket[10]; DWORD AimID=*(DWORD*)&aPacket[2];

		ChickenAim(cfg.ChickenOnAim,ID,AimID);
	}

	if(aPacket[0]==0x59)
	{
		if(CampOn) 
		{
			char Buffer[200]; DWORD PlayerID=*(DWORD*)&aPacket[1];

			if(GetPlayerID()!=PlayerID) Auto.SelectPlayer(PlayerID);

			if(cfg.PrintIHPKMessages) PrintDevilPKString("Camp selected %s as Target!",GetNameByID(PlayerID));

			if(cfg.PrintOverhead) OverheadMessage("Auto Camp Deactivated");

			if(MakeTP()) 
			{
				TakeNextTP=true; v_AntiTppkBusy=true; HostPlayer=true; CampOn=false;

				return TRUE;
			}
			else 
			{
				CampOn=false;
				
				return TRUE;
			}

			return TRUE;
		}
		if(CampUnitOn) 
		{
			char Buffer[200]; DWORD PlayerID=*(DWORD*)&aPacket[1]; DWORD TargetID=Auto.GetPlayerID();

			if(PlayerID==TargetID) 
			{
				if(cfg.PrintIHPKMessages) PrintDevilPKString("Camp Unit found %s!",GetNameByID(TargetID));

				if(cfg.PrintOverhead) OverheadMessage("Camp Unit Deactivated");

				if(MakeTP()) 
				{
					TakeNextTP=true; v_AntiTppkBusy=true; HostPlayer=true; CampUnitOn=false;

					return TRUE;
				}
				else
				{
					CampUnitOn=false;

					return TRUE;
				}
			}

			return TRUE;
		}
	}

	if(aPacket[0]==0x5A)
	{
		if(aPacket[1] == 0x02)
		{
			aPacket[1] = 0xff;
			char Buffer[500]; char Buffer1[500]; char account[17], *name; char acco[10], *acc;
			name = (CHAR *)aPacket + 8; acc = (CHAR *)aPacket + 24;
			RosterUnit *pUnit = FindPartyByName((LPSTR)&aPacket[8]);
			DWORD dwFlags = GetPvpFlags(pUnit->dwUnitId);
			
			if(!pUnit || pUnit->dwUnitId == Myself->dwUnitId) return TRUE;

			if(!strcmp((LPSTR)&aPacket[8],D2CLIENT_GetPlayerUnit()->pPlayerData->szName)) return FALSE;

			if(cfg.PrintJoinMessages) PrintString("ÿc4%s(%s) a ÿc4level ÿc4%d ÿc4%s ÿc4joined ÿc4our ÿc4world. ÿc4Diablo's ÿc4minions ÿc4grow ÿc4stronger.",(LPSTR)&aPacket[8],(LPSTR)&aPacket[24],GetLevelByName(name),GetClassByName2(name)); 

			else PrintString("ÿc4%s(%s) ÿc4joined ÿc4our ÿc4world. ÿc4Diablo's ÿc4minions ÿc4grow ÿc4stronger.",(LPSTR)&aPacket[8],(LPSTR)&aPacket[24]); 

			if(SpamAcc(name)) SQ(GetIDByName(name));

			else if(EnchBot && !SpamAcc(name))
			{
				if(cfg.PMOnJoin)
				{
					sprintf(Buffer,"/w %s Enchant Bot is active! Commands: <%s> <%s> <%s>",(LPSTR)&aPacket[8],cfg.EnchMe,cfg.EnchMerc,cfg.EnchAll);
					BNCLIENT_SendBNMessage(Buffer);
					ChantTimer=true;
				}
				else
				{
					sprintf(Buffer,"Enchant Bot is active! Commands: <%s> <%s> <%s>",cfg.EnchMe,cfg.EnchMerc,cfg.EnchAll);
					Speak(Buffer);
					ChantTimer=true;
				}
			}

			//if(CheckPlayerFriend(name))
			//{
			//	InviteAndLoot2(pUnit, dwFlags);

			//	return TRUE;
			//}

			if(!strcmp(name,D2CLIENT_GetPlayerUnit()->pPlayerData->szName)) return FALSE;

        	aPacket[1] = 0xff;

			return TRUE;
		}
	    if(aPacket[1] == 0x03)
		{
			char Buffer[200]; char account[17], *name; char acco[10], *acc;
			name = (CHAR *)aPacket + 8; acc = (CHAR *)aPacket + 24;

			if(!strcmp(name,D2CLIENT_GetPlayerUnit()->pPlayerData->szName)) return FALSE;

			else PrintString("ÿc4%s(%s) ÿc4left ÿc4our ÿc4world. ÿc4Diablo's ÿc4minions ÿc4weaken.",name,acc);

			aPacket[1] = 0xff;

			return TRUE;
		}
		if(aPacket[1]==0x06)
		{
			char *opfer=(char*)&aPacket[8]; char *Killer=(char*)&aPacket[8+1+strlen(opfer)];
			char *AmIKiller=(char*)&GetGameInfo()->szCharName;
			char Buffer[200];
			int i=0; int KilledLevel=0;

			while(i<aLen)
			{
				Killer=(char*)&aPacket[8+strlen(opfer)+i];
				if(Killer[0]!=NULL)
				break;
				i++;
			}
			if(!_strcmpi(GetGameInfo()->szCharName,Killer)) 
			{
				if(cfg.PKMessage) DeathMessage(opfer);
				
				/*

				if(!((*p_D2LAUNCH_BnData)->nCharFlags & PLAYER_TYPE_HARDCORE)) return TRUE;

				KilledLevel = GetLevelByName(opfer);

				if(KilledLevel > cfg.LogPKsOver) AddURL(opfer,  GetLevelByName(opfer), GetClassByName(opfer));*/
			}

			return TRUE;
		}
		if(aPacket[1]==0x07 && aPacket[2]==0x08 && (!IsTownLevel(GetPlayerArea())))
		{
			DWORD PlayerID=*(DWORD*)&aPacket[3];
			
			ChickenHostile(cfg.ChickenOnHostile, PlayerID);
		}

		return TRUE;
	}

	if(aPacket[0] == 0x5D)
	{
		if(!D2CLIENT_GetUiVar(UI_QUEST)) return FALSE;

		return TRUE;
	}

	if(aPacket[0] == 0x51)
	{
		if(aPacket[1] == UNIT_TYPE_OBJECT && *(LPWORD)&aPacket[6] == 0x3B)
		{
			if(cfg.RemovePortalDelay) aPacket[12] = 2;
		}

		return TRUE;
	}

	if(aPacket[0]==0x60)
	{
		if(TakeNextTP && !IsTownLevel(GetPlayerArea()))
		{
			if(FindUnit(*(DWORD*)&aPacket[3],UNIT_OBJECT))
			{	
				UnitAny *TPUnit=(UnitAny*)FindUnit(*(DWORD*)&aPacket[3],UNIT_OBJECT);

				if(TPUnit->pObjectPath &&
					GetDistance(GetPosition().x,GetPosition().y,TPUnit->pObjectPath->dwPosX,TPUnit->pObjectPath->dwPosY)<=12)
				{
					BYTE TakeTP[9] = {0x13,0x02,0x00,0x00,0x00,0x00,0x00,0x00,0x00};
					*(DWORD*)&TakeTP[5]=*(DWORD*)&aPacket[3];
					SendGAMEPacket(TakeTP,sizeof(TakeTP));

					TakeNextTP=false;

					if(HostPlayer)
					{
						if(cfg.HostileTarget&&Auto.GetPlayerID()!=Myself->dwUnitId) Hostile(Auto.GetPlayerID());
						else HostileAll();

						HostPlayer=false;
					}
				}
			}
		}

		return TRUE;
	}

	if(aPacket[0]==0x5B && aPacket[1]==0x24 && (*(DWORD*)&aPacket[3]==D2CLIENT_GetPlayerUnit()->dwUnitId))
	{
		//Load
		if(GameReady()) Load(TRUE);

		return TRUE;
	}

	if (aPacket[0] == 0x69) 
    {
		//Unload
		if(!aPacket[1]) Unload();

		return TRUE;
    }

	if(aPacket[0] == 0x89 && cfg.PrintIHPKMessages)
    {
		int nQuest=aPacket[1];

		PrintDevilPKString("Quest packet detected (%s)",CheckQuest(nQuest));

		return TRUE;
    }

	if(aPacket[0] == 0xA7)
	{

		if(aPacket[6] == AFFECT_JUST_PORTALED && cfg.RemovePortalDelay) return FALSE;

		return TRUE;
    }

	if(aPacket[0] == 0xAA )
	{
		*(DWORD *)(aPacket+aPacket[6]) = -1; aPacket[6] += 4;
    }

	return TRUE;
}