#include "DevilPK.h"
HANDLE TimerHandle;
bool Flash=false;
int FlashDelay;
int Missled;
int Delay=0;
bool CastMissles=false;
bool D2Inited=false;
int D2Delay=0;

void TimerTick() 
{
    ChickenCheck();
    Delay++;
	if(TakeNextTP)
	{
		if(IsTownLevel(GetPlayerArea()))
		TakeNextTP=false;
	}
	if(CampOn)
	{
		D2CLIENT_clickMap(3,Camp.x,Camp.y,8);
	}
	if(CampUnitOn)
	{
		D2CLIENT_clickMap(3,Camp.x,Camp.y,8);
	}
	if(Flash)
	{
		if(FindUnit(Auto.GetPlayerID(),0)!=NULL)
		{
			FlashPlayer(Auto.GetPlayerID());						
			FlashDelay=0;
		}
		if(FindUnit(Auto.GetPlayerID(),0)==NULL)
		{
			FlashDelay=-1;
		}
	}
}
DWORD WINAPI TimerTickThread(LPVOID P)
{
	while(TRUE)
	{
		if(!v_GameInit && Myself)
			OnGameEvent(FALSE);
		else if(v_GameInit && !Myself)
			OnGameEvent(TRUE);

		if(D2Inited) 
			if(D2Delay<20)
				D2Delay++;
			else
			{
				if(GetGameInfo()->szCharName!=NULL)
				TimerTick();	
				else
				{
					Flash=false; D2Inited=false; D2Delay=0;
				}
			}
		Sleep(50);
	}
	return true;
}
void TimerTick2()
{
    Delay++;

	if(EnchBot)
	{
		EnchListedPlayers(); EnchListedUnits(); ChantTimerCheck();
	}
}
DWORD WINAPI TimerTickThread2(LPVOID P)
{
	while(TRUE)
	{
		BOOL wPlayer=false;
		BOOL wMonster=false;
		BOOL wVector=false;
		BOOL wLevelNames=false;
		BOOL wPlayerLine=false;

		if(D2Inited) 
		if(D2Delay<20)
		D2Delay++;
		else
		{
			if(GetGameInfo()->szCharName!=NULL)
			{
				TimerTick2();
			}	
			else
			{
				D2Inited=false; D2Delay=0;
			}
		}
		
		if (cfg.CleanShot)
		{
			if (GetAsyncKeyState(VK_SNAPSHOT))
			{
				if(cfg.PlayerInfo)
				{
					cfg.PlayerInfo=false;
					wPlayer=true;
				}
				if(cfg.DrawMonsters)
				{
					cfg.DrawMonsters=false;
					wMonster=true;
				}
				if(cfg.DrawVectors)
				{
					cfg.DrawVectors=false;
					wVector=true;
				}
				if(cfg.LevelNames)
				{
					cfg.LevelNames=false;
					wLevelNames=true;
				}
				if(cfg.PlayerLine)
				{
					cfg.PlayerLine=false;
					wPlayerLine=true;
				}

				while (GetAsyncKeyState(VK_SNAPSHOT))
				Sleep(500);

				if(!cfg.PlayerInfo && wPlayer) cfg.PlayerInfo=true;
				if(!cfg.DrawVectors && wVector) cfg.DrawVectors=true;
				if(!cfg.DrawMonsters && wMonster) cfg.DrawMonsters=true;
				if(!cfg.LevelNames && wLevelNames) cfg.LevelNames=true;
				if(!cfg.PlayerLine && wPlayerLine) cfg.PlayerLine=true;
			}
		}
		Sleep(50);
	}
	return true;
}
DWORD GetUnitDist(UnitAny* pUnit1, UnitAny* pUnit2)
{
	DWORD dwDist[4] = {0};

	switch(pUnit1->dwType)
	{
	case UNIT_TYPE_PLAYER:
	case UNIT_TYPE_MISSILE:
	case UNIT_TYPE_ITEM:
		dwDist[0] = pUnit1->pPath->xPos;
		dwDist[1] = pUnit1->pPath->yPos;
		break;

	case UNIT_TYPE_OBJECT:
		dwDist[0] = pUnit1->pObjectPath->dwPosX;
		dwDist[1] = pUnit1->pObjectPath->dwPosY;
		break;
	}

	switch(pUnit2->dwType)
	{
	case UNIT_TYPE_PLAYER:
	case UNIT_TYPE_MISSILE:
	case UNIT_TYPE_ITEM:
		dwDist[2] = pUnit2->pPath->xPos;
		dwDist[3] = pUnit2->pPath->yPos;
		break;

	case UNIT_TYPE_OBJECT:
		dwDist[2] = pUnit2->pObjectPath->dwPosX;
		dwDist[3] = pUnit2->pObjectPath->dwPosY;
		break;
	}

	for(int x = 0; x < 4; x++)
		if(!dwDist[x])
			return INFINITE;

	return (DWORD)CalculateDistance(dwDist[0], dwDist[1], dwDist[2], dwDist[3]);
}

VOID CheckAntiTppk()
{
	if(IsTownLevel(GetPlayerArea()))
	{
		v_AntiTppkBusy=false; return;
	}

	if(v_AntiTppkBusy)
	{
		for(Room1* pRoom = Myself->pAct->pRoom1; pRoom && v_AntiTppkBusy; pRoom = pRoom->pRoomNext)
		{
			for(UnitAny* pUnit = pRoom->pUnitFirst; pUnit && v_AntiTppkBusy; pUnit = pUnit->pListNext)
			{
				if(pUnit->dwType == UNIT_TYPE_OBJECT && pUnit->dwTxtFileNo == 59)
				{
					if(!stricmp(pUnit->pObjectData->szOwner, Myself->pPlayerData->szName))
					{
						if(GetUnitDist(Myself, pUnit) < 12)
						{
							for(INT i = 0; i < 20; i++)
							{
								if(!GameReady() || IsTownLevel(GetPlayerArea()) ||
									Myself->dwMode==PLAYER_MODE_DEATH || Myself->dwMode==PLAYER_MODE_DEAD ||
									!TakeNextTP)
								{
									v_AntiTppkBusy = false;
									break;
								}

								Interact(pUnit->dwUnitId, UNIT_TYPE_OBJECT, TRUE);
								Sleep(50);
							}
						}
					}
				}
			}
		}
	}
}


DWORD WINAPI TimerTickThread3(LPVOID P)
{
	while(TRUE)
	{
		if(D2Inited) 
			if(D2Delay<20)
				D2Delay++;
			else
			{
				if(GetGameInfo()->szCharName!=NULL)
				CheckAntiTppk();	
			}
		Sleep(50);
	}
	return true;
}