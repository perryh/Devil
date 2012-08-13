#include "DevilPK.h"
#include "Automap.h"

bool ShowVectors=true;
bool Units=false;
int LastLvl=0;
int LastLvl1=0;
DWORD TimeOn;
DWORD BookTimer;
Vector GlobalVectors;

#define QUESTCOLOR	155
#define OTHER		152
#define WP			132
#define SPECIAL		109
#define DRAW(f,c) if(fileno==f){\
    if(c==QUESTCOLOR){GlobalVectors.QuestID=ObjID;}\
    if(c==OTHER){GlobalVectors.OtherID=ObjID;}\
	if(c==SPECIAL){GlobalVectors.SpecialID=ObjID;}}
INT nLastLevel = 0;
INT nWaypoints[] = {119, 157, 156, 402, 323, 288, 237, 324, 238, 496, 511, 494};
INT D2GetScreenSizeX()
{
	INT Sizes[2] = {640, 800};
	return Sizes[D2GFX_GetScreenSize() / 2];
}

INT D2GetScreenSizeY()
{
	INT Sizes[] = {480, 600};
	return Sizes[D2GFX_GetScreenSize() / 2];
}

DWORD GetUnitIDByXY(LONG Wx,LONG Wy, Room2* pRoom2)
{
	UnitAny* pUnit;
	if(!pRoom2)
	return 0;
	if(!pRoom2->pRoom1)
	return 0;
	if(!pRoom2->pRoom1->pUnitFirst)
	return 0;
	pUnit=pRoom2->pRoom1->pUnitFirst;
	if(!pUnit->pObjectPath)
	return 0;
	while(pUnit)
	{
		if(pUnit->dwType!=UNIT_PLAYER)
		if(Wx==pUnit->pObjectPath->dwPosX)
		if(Wy==pUnit->pObjectPath->dwPosY)
		return pUnit->dwUnitId;
		pUnit=pUnit->pListNext;
	}
	return 0;
}
PresetUnit* FindPresetUnit(DWORD dwTxtFileNo, DWORD dwType, Room2* *pRoom)
{
	for(Room2* pRoom2 = GetUnitLevel(Myself)->pRoom2First; pRoom2; pRoom2 = pRoom2->pRoom2Other)
	{
		for(PresetUnit* pUnit = pRoom2->pPreset; pUnit; pUnit = pUnit->pPresetNext)
		{
			if(pUnit->dwType == dwType && pUnit->dwTxtFileNo == dwTxtFileNo)
			{
				*pRoom = pRoom2;
				return pUnit;
			}
		}
	}

	return NULL;
}
Level* GetLevelPointerD(ActMisc *pActMisc, int nLevel)
{
	if ((!pActMisc) || (nLevel < 0))
	return false;
	for (Level *pLevel = pActMisc->pLevelFirst; pLevel; pLevel = pLevel->pNextLevel)
	{
		if (!pLevel)
		continue;
		if ((pLevel->dwLevelNo == nLevel) && (pLevel->dwSizeX > 0))
		return pLevel;
	}
	return D2COMMON_GetLevel(pActMisc, nLevel);
}
Level* GetUnitLevel(UnitAny* pUnit)
{
	if(pUnit)
		if(pUnit->pPath)
			if(pUnit->pPath->pRoom1)
				if(pUnit->pPath->pRoom1->pRoom2)
					return pUnit->pPath->pRoom1->pRoom2->pLevel;

	return NULL;
}

VOID GetPlayerPosition(LPPOINT ptPlayer)
{
	ScreenToAutomapRelative(ptPlayer, D2GetScreenSizeX()/2, (D2GetScreenSizeY()-48)/2);
}
VOID GetVectorArrows()
{

		LPLEVELEXIT pLevels[0x40] = {NULL};

		for(INT i = 0; i < v_CurrentVectors.GetSize(); i++)
			delete v_CurrentVectors[i];

		v_CurrentVectors.RemoveAll();

		if(IsTownLevel(GetPlayerArea()))
			return;

		v_GlobalMap->CreateCollisionMap();
		v_GlobalMap->GetLevelExits(pLevels, 0x40);

		for(INT i = 0; i < ArraySize(nWaypoints); i++)
		{
			Room2* pRoom;
			PresetUnit* pUnit = FindPresetUnit(nWaypoints[i], UNIT_TYPE_OBJECT, &pRoom);
			if(!pUnit)
				continue;

			LPVECTOR pVect = new VECTOR;
			pVect->nType = VECTOR_WAYPOINT;
			pVect->ptPos.x = ((pRoom->dwPosX * 5) + pUnit->dwPosX) * 32;
			pVect->ptPos.y = ((pRoom->dwPosY * 5) + pUnit->dwPosY) * 32;
			pVect->dwTarget = nWaypoints[i];
			pVect->dwTargetType = UNIT_TYPE_OBJECT;


			POINT Calc; 
			Calc.x = pVect->ptPos.x; 
			Calc.y = pVect->ptPos.y; 
			DWORD UnitID = pVect->dwTarget; 

			POINT DrawCalc; 
			MapToScreenCoords(Calc); 
			ScreenToAutomapRelative(&DrawCalc,Calc.x,Calc.y);

			GlobalVectors.WPID=UnitID;
			GlobalVectors.WPPos.x=DrawCalc.x;
			GlobalVectors.WPPos.y=DrawCalc.y;

			v_CurrentVectors.Add(pVect);
			break;
		}

		for(INT j = 0; j < ArraySize(MapVectors); j++)
		{
			if(MapVectors[j].dwCurrentLevel != GetUnitLevel(Myself)->dwLevelNo)
				continue;

			if(MapVectors[j].dwTargetType == TARGET_LEVEL)
			{
				for(INT i = 0; i < 0x40; i++)
				{
					if(!pLevels[i])
						break;

					if(MapVectors[j].dwTarget != pLevels[i]->dwTargetLevel)
						continue;

					for(INT k = 0; k < v_CurrentVectors.GetSize(); k++)
					{
						if(v_CurrentVectors[k]->nType == MapVectors[j].dwVectorType)
							goto ContinueIt;
					}

					LPVECTOR pVect = new VECTOR;
					pVect->ptPos.x = pLevels[i]->ptPos.x * 32;
					pVect->ptPos.y = pLevels[i]->ptPos.y * 32;
					pVect->nType = MapVectors[j].dwVectorType;
					pVect->dwTarget = MapVectors[j].dwTarget;
					pVect->dwTargetType = MapVectors[j].dwTargetType;
					v_CurrentVectors.Add(pVect);
				}
			}
			else
			{
				Room2* pRoom;
				PresetUnit* pUnit = FindPresetUnit(MapVectors[j].dwTarget, MapVectors[j].dwTargetType, &pRoom);
				UnitAny *Me = D2CLIENT_GetPlayerUnit();
				if(!pUnit)
					continue;
				if(MapVectors[j].dwCurrentLevel==MAP_A2_CANYON_OF_THE_MAGI)
				{
					for (int i = 0; i < LevelNames.GetSize(); i++)
					{
						LevelNameInfo* pInfo = LevelNames.ElementAt(i);

						if (pInfo->nAct != Me->dwAct)
							continue;

						if(pInfo->nLevelId== Me->pAct->pMisc->dwStaffTombLevel)
						{			
							cfg.RealTombX=0;
							if(pInfo->nX==12508)
							{
								cfg.RealTombX=1;
							}
							if(pInfo->nX==12514)
							{
								cfg.RealTombX=2;
							}
							if(pInfo->nX==12513)
							{
								cfg.RealTombX=3;
							}
							if(pInfo->nX==12519)
							{
								cfg.RealTombX=4;
							}
							if(pInfo->nX==12617)
							{
								cfg.RealTombX=5;
							}
							if(pInfo->nX==12698)
							{
								cfg.RealTombX=6;
							}
							if(pInfo->nX==12779)
							{
								cfg.RealTombX=7;
							}
						}
					}
					if(pUnit->dwTxtFileNo==41 && cfg.RealTombX == 1||
					pUnit->dwTxtFileNo==40 && cfg.RealTombX == 2||
					pUnit->dwTxtFileNo==39 && cfg.RealTombX == 3||
					pUnit->dwTxtFileNo==38 && cfg.RealTombX == 4||
					pUnit->dwTxtFileNo==42 && cfg.RealTombX == 5||
					pUnit->dwTxtFileNo==43 && cfg.RealTombX == 6||
					pUnit->dwTxtFileNo==44 && cfg.RealTombX == 7)	
					{
						LPVECTOR pVect = new VECTOR;
						pVect->ptPos.x = ((pRoom->dwPosX * 5) + pUnit->dwPosX) * 32;
						pVect->ptPos.y = ((pRoom->dwPosY * 5) + pUnit->dwPosY) * 32;
						pVect->nType = MapVectors[j].dwVectorType;
						pVect->dwTargetType = MapVectors[j].dwTargetType;
						v_CurrentVectors.Add(pVect);
					}
				}
				for(INT k = 0; k < v_CurrentVectors.GetSize(); k++)
				{
					if(v_CurrentVectors[k]->nType == MapVectors[j].dwVectorType && MapVectors[j].dwCurrentLevel != MAP_A2_CANYON_OF_THE_MAGI)
						goto ContinueIt;
				}

				
				if(MapVectors[j].dwCurrentLevel!=MAP_A2_CANYON_OF_THE_MAGI)
				{
					LPVECTOR pVect = new VECTOR;
					pVect->ptPos.x = ((pRoom->dwPosX * 5) + pUnit->dwPosX) * 32;
					pVect->ptPos.y = ((pRoom->dwPosY * 5) + pUnit->dwPosY) * 32;
					pVect->nType = MapVectors[j].dwVectorType;
					pVect->dwTargetType = MapVectors[j].dwTargetType;
					v_CurrentVectors.Add(pVect);
				}
			}
ContinueIt:
			continue;
		}
}
VOID DrawVectorArrows()
{
	if(!GameReady() || IsTownLevel(GetPlayerArea()))
		return;

	INT nColors[] = {cfg.NextColor, cfg.PrevColor, cfg.WaypointColor, cfg.SpecialColor};

	POINT ptPlayer, ptPos;
	GetPlayerPosition(&ptPlayer);

	for(INT i = 0; i < v_CurrentVectors.GetSize(); i++)
	{
		ScreenToAutomap(&ptPos, v_CurrentVectors[i]->ptPos.x, v_CurrentVectors[i]->ptPos.y);
		DrawPlayerBlob(ptPos.x, ptPos.y, nColors[v_CurrentVectors[i]->nType - 1]);
	}

	return;
}
void D2DrawLine(int x,int y,int x2, int y2, DWORD color)
{
	D2GFX_DrawLine(x,y,x2,y2,color,0xff);
}

void DrawPlayerBlob(int xpos, int ypos,int col)
{
	static char blines[][2] = {0,-2, 4,-4, 8,-2, 4,0, 8,2, 4,4, 0,2, -4,4, -8,2, -4,0, -8,-2, -4,-4, 0,-2};
	for (int i = 0; i < ARRAYSIZE(blines)-1; i++)
	{
		D2GFX_DrawLine(xpos+blines[i][0], ypos+blines[i][1], xpos+blines[i+1][0], ypos+blines[i+1][1], col, 0xff);
	}
	POINT Player;
	Player.x=GetPlayerX(GetPlayerID());
	Player.y=GetPlayerY(GetPlayerID());
	POINT DrawCalc;
	MapToScreenCoords(Player);
	ScreenToAutomapRelative(&DrawCalc,Player.x,Player.y);
	D2GFX_DrawLine(DrawCalc.x,DrawCalc.y,xpos,ypos,col,0xff);

}
void MiniMapCell(int xpos, int ypos, int actnum,int lvlnum, int fileno, long rx, long ry,DWORD ObjID)
{

	lvlnum = D2CLIENT_GetPlayerUnit()->pAct->pRoom1->pRoom2->pLevel->dwLevelNo;	

	if(GetPlayerArea()==LEVEL_CATACOMBS_LEVEL_4)
	{
		DRAW(17,OTHER);
	}
	if(GetPlayerArea()==LEVEL_FAR_OASIS)
	{
		DRAW(47,QUESTCOLOR);
	}
	if(GetPlayerArea()==LEVEL_HAREM_LEVEL_1)
	{
		DRAW(25,OTHER);
		DRAW(29,QUESTCOLOR);
	}
	if(GetPlayerArea()==LEVEL_HAREM_LEVEL_2)
	{
		DRAW(27,OTHER);
		DRAW(29,QUESTCOLOR);
	}
	if(GetPlayerArea()==LEVEL_PALACE_CELLAR_LEVEL_1)
	{
		DRAW(27,OTHER);
		DRAW(32,QUESTCOLOR);
	}
	if(GetPlayerArea()==LEVEL_PALACE_CELLAR_LEVEL_2)
	{
		DRAW(31,OTHER);
		DRAW(32,QUESTCOLOR);
	}
	if(GetPlayerArea()==LEVEL_PALACE_CELLAR_LEVEL_3)
	{
		DRAW(31,OTHER);
	}
	if(GetPlayerArea()==LEVEL_CANYON_OF_THE_MAGI)
	{
		if(cfg.RealTombX==1)
		{
			DRAW(41,QUESTCOLOR);
		}
		if(cfg.RealTombX==2)
		{
			DRAW(40,QUESTCOLOR);
		}
		if(cfg.RealTombX==3)
		{
			DRAW(39,QUESTCOLOR);
		}
		if(cfg.RealTombX==4)
		{
			DRAW(38,QUESTCOLOR);
		}
		if(cfg.RealTombX==5)
		{
			DRAW(42,QUESTCOLOR);
		}
		if(cfg.RealTombX==6)
		{
			DRAW(43,QUESTCOLOR);
		}
		if(cfg.RealTombX==7)
		{
			DRAW(44,QUESTCOLOR);
		}
	}
	if(GetPlayerArea()==LEVEL_TAL_RASHAS_TOMB1||GetPlayerArea()==LEVEL_TAL_RASHAS_TOMB2||GetPlayerArea()==LEVEL_TAL_RASHAS_TOMB3||GetPlayerArea()==LEVEL_TAL_RASHAS_TOMB4||GetPlayerArea()==LEVEL_TAL_RASHAS_TOMB5||GetPlayerArea()==LEVEL_TAL_RASHAS_TOMB6||GetPlayerArea()==LEVEL_TAL_RASHAS_TOMB7)
	{
		DRAW(45,OTHER)
	}
	if(GetPlayerArea()==LEVEL_TRAVINCAL)
	{
		DRAW(64,QUESTCOLOR);
	}
}



void NewEnum() 
{ 
	UnitAny *pUnit = D2CLIENT_GetPlayerUnit(); 
	Level *pLevel = GetLevelPointerD(pUnit->pAct->pMisc, GetPlayerArea()); 

	bool FoundTile=false;

	for(Room2 *pRoom2 = pLevel->pRoom2First;pRoom2;pRoom2=(Room2*)pRoom2->pRoom2Other) 
	{ 
		for(PresetUnit *unit = pRoom2->pPreset;unit;unit=unit->pPresetNext) 
		{ 
			if(unit->dwType != UNIT_TYPE_TILE && unit->dwType!=UNIT_TYPE_OBJECT &&  unit->dwType!=UNIT_TYPE_NPC)
				continue;
			if(unit->dwTxtFileNo==580 && unit->dwType == UNIT_TYPE_OBJECT && GetPlayerArea()==LEVEL_BLOOD_MOOR)
				continue;
			if(unit->dwTxtFileNo==37 && unit->dwType == UNIT_TYPE_OBJECT && GetPlayerArea()==LEVEL_LOST_CITY)
				continue;
			if(unit->dwTxtFileNo==13 && unit->dwType == UNIT_TYPE_OBJECT)
				continue;
			if(unit->dwTxtFileNo==14 && unit->dwType == UNIT_TYPE_OBJECT)
				continue;
			if(unit->dwTxtFileNo==15 && unit->dwType == UNIT_TYPE_OBJECT)
				continue;
			if(unit->dwTxtFileNo==16 && unit->dwType == UNIT_TYPE_OBJECT)
				continue;
			if(unit->dwTxtFileNo==2 && unit->dwType == UNIT_TYPE_OBJECT)
				continue;
			if(unit->dwTxtFileNo==32 && unit->dwType == UNIT_TYPE_TILE && FoundTile)
				continue;
			if(unit->dwTxtFileNo==32 && unit->dwType == UNIT_TYPE_TILE && !FoundTile)
				FoundTile=true;

			PresetUnit pu; 
			pu.dwTxtFileNo = unit->dwTxtFileNo; 
			pu.dwType = unit->dwType; 
			pu.dwPosX = unit->dwPosX+pRoom2->dwPosX*5; 
			pu.dwPosY = unit->dwPosY+pRoom2->dwPosY*5; 
			POINT Calc; 
			Calc.x = pu.dwPosX; 
			Calc.y = pu.dwPosY; 
			DWORD UnitID=GetUnitIDByXY(pu.dwPosX,pu.dwPosY,pRoom2); 
			POINT DrawCalc; 
			MapToScreenCoords(Calc); 
			ScreenToAutomapRelative(&DrawCalc,Calc.x,Calc.y);
			
 			if(!IsTownLevel(GetPlayerArea()))				
			MiniMapCell(DrawCalc.x,DrawCalc.y,D2CLIENT_GetPlayerUnit()->dwAct+1,GetPlayerArea(),pu.dwTxtFileNo,pu.dwPosX,pu.dwPosY,UnitID); 

			//DrawTextToScreen(mitoa(unit->dwTxtFileNo),Calc.x,Calc.y,1,4); // Prints Unit Text
			//DrawTextToScreen(mitoa(unit->dwType),Calc.x,Calc.y+10,4,4);; // Prints Unit Type
		}
	}
}
void DrawPlines(void)
{
	POINT Player;
	POINT Target;
	if(Auto.GetPlayerID()!=GetPlayerID()) 
	if(FindUnit(Auto.GetPlayerID(),0))
	if(((UnitAny*)FindUnit(Auto.GetPlayerID(),0))->pPath)
	{
		UnitAny* NearstPlayer=(UnitAny*)FindUnit(Auto.GetPlayerID(),0);
		if(NearstPlayer->pPlayerData)
		{			
			Player.x=GetPlayerX(GetPlayerID());
			Player.y=GetPlayerY(GetPlayerID());
			Target.x=NearstPlayer->pPath->xPos;
			Target.y=NearstPlayer->pPath->yPos;
			POINT DrawCalc,TargetCalc;
			MapToScreenCoords(Player);
			ScreenToAutomapRelative(&DrawCalc,Player.x,Player.y);
			MapToScreenCoords(Target);
			ScreenToAutomapRelative(&TargetCalc,Target.x,Target.y);
			D2DrawLine(DrawCalc.x,DrawCalc.y,TargetCalc.x,TargetCalc.y,11);
			//DrawPlayerBlob(TargetCalc.x,TargetCalc.y,11);
		}
	}
}
void AbsToScreenCoords(POINT& rMapPosition)
{
	D2COMMON_AbsScreenToMap(&rMapPosition.x, &rMapPosition.y);
	rMapPosition.x -= D2CLIENT_GetMouseXOffset();
	rMapPosition.y -= D2CLIENT_GetMouseYOffset();
}
void DrawYonTarget(void) 
{
	if(Auto.GetPlayerID()!=GetPlayerID()||Auto.GetPlayerID()!=NULL)
	{
		if(FindUnit(Auto.GetPlayerID(),0))
		{
			POINT PlayerPos;
			UnitAny* TargetUnit = (UnitAny*)FindUnit(Auto.GetPlayerID(),0);
			RosterUnit *pUnit=(RosterUnit*)*(DWORD*)0x6FBCC080;
			pUnit=pUnit->pNext;
			if(TargetUnit->dwUnitId!=GetPlayerID())
			{
				PlayerPos.x=TargetUnit->pPath->xPos;
				PlayerPos.y=TargetUnit->pPath->yPos;
				MapToScreenCoords(PlayerPos);
				if(PlayerPos.x!=NULL&&PlayerPos.y!=NULL)
				{
					D2GFX_DrawRectangle(PlayerPos.x-30,PlayerPos.y-55,PlayerPos.x+20,PlayerPos.y+35,cfg.AimBoxColor,0);
					D2DrawRectFrame(PlayerPos.x-30,PlayerPos.y-55,PlayerPos.x+20,PlayerPos.y+35);
					DrawTextToScreen("¿",PlayerPos.x-11,PlayerPos.y+11,4,3);
					if(Units)
					{
						DrawTextToScreen(mitoa(GetUnitStat(TargetUnit, STAT_COLDABSORBPERCENT)),PlayerPos.x-25,PlayerPos.y-55,3,4);
						DrawTextToScreen(mitoa(GetUnitStat(TargetUnit, STAT_FIREABSORBPERCENT)),PlayerPos.x-10,PlayerPos.y-55,1,4);
						DrawTextToScreen(mitoa(GetUnitStat(TargetUnit, STAT_LIGHTNINGABSORBPERCENT)),PlayerPos.x+5,PlayerPos.y-55,9,4);
					}
				}
			}
		}
	}
}


void LifeManaPercents(void) 
{
	char Buffer[100];
	DWORD MaxLife= GetMaxLife();
	DWORD MaxMana= GetMaxMana();
	DWORD CurrentLife=GetCurrentLife();
	DWORD CurrentMana=GetCurrentMana();

	DWORD LifePercent= GetPercent(CurrentLife,MaxLife);
	if(LifePercent > 100)
		LifePercent = 100;

	DWORD ManaPercent=GetPercent(CurrentMana,MaxMana);
	if(ManaPercent > 100)
		ManaPercent = 100;

	int x = 59;
	int x2 = 715;
	int y = 535;

	D2GFX_DrawRectangle(x,y,x+35,y+18,0,7);
	D2DrawRectFrame(x,y,x+35,y+18);

	D2GFX_DrawRectangle(x2,y,x2+35,y+18,0,7); 
	D2DrawRectFrame(x2,y,x2+35,y+18); 

	sprintf(Buffer,"%i%",LifePercent);
	DrawTextToScreenCenter(Buffer,x+17,y+14,1,0);

	sprintf(Buffer,"%i%",ManaPercent);
	DrawTextToScreenCenter(Buffer,x2+17,y+14,3,0);
}

void RevealActOnce(void) 
{
	if(GetPlayerArea()!=LastLvl) 
	{
		UnitAny *pUnit = D2CLIENT_GetPlayerUnit (); 
		Level *pLevel = GetLevelPointerD(pUnit->pAct->pMisc, GetPlayerArea());
		RevealLevel(pLevel);
		LastLvl=GetPlayerArea();
		GlobalVectors.OtherPos.x=0;
		GlobalVectors.OtherPos.y=0;
		GlobalVectors.QuestPos.x=0;
		GlobalVectors.QuestPos.y=0;
		GlobalVectors.WPPos.x=0;
		GlobalVectors.WPPos.y=0;
		GlobalVectors.SpecialPos.x=0;
		GlobalVectors.SpecialPos.y=0;
	}
}

void ScreenToAutomap(POINT *ptPos, int x, int y)
{
	ptPos->x = ((x - y)/2/(*(INT*)p_D2CLIENT_Divisor))-(*p_D2CLIENT_Offset).x+8;
	ptPos->y = ((x + y)/4/(*(INT*)p_D2CLIENT_Divisor))-(*p_D2CLIENT_Offset).y-8;
	if(D2CLIENT_GetAutomapSize())
	{
		--ptPos->x;
		ptPos->y += 5;
	}
}

void DrawCross(INT nX, INT nY, DWORD dwColor, BOOL Automap)
{
	POINT nPos = {nX, nY};
	if (Automap)
	{
		if (!p_D2CLIENT_AutomapOn)
			return;
		ScreenToAutomap(&nPos, nX * 32, nY * 32);
	}

	CHAR szLines[][2] = {0,-2, 4,-4, 8,-2, 4,0, 8,2, 4,4, 0,2, -4,4, -8,2, -4,0, -8,-2, -4,-4, 0,-2};
	for(INT x = 0; x < ArraySize(szLines) - 1; x++)
		D2GFX_DrawLine(nPos.x + szLines[x][0], nPos.y + szLines[x][1], nPos.x + szLines[x+1][0], nPos.y + szLines[x+1][1], dwColor, -1);
}

void TextHook(INT xPos, INT yPos, DWORD dwColor, BOOL Automap, INT dwFont, INT dwCenter, LPSTR Text,...)
{
	POINT nPos = {xPos, yPos};
	DWORD dwOldSize, wWidth, dwFileNo;

	if (Automap)
	{
		if (!p_D2CLIENT_AutomapOn)
		return;
		ScreenToAutomap(&nPos, xPos * 32, yPos * 32);
	}

	CHAR szBuffer[800] = "";
	va_list Args;
	va_start(Args, Text);
	vsprintf_s(szBuffer, Text, Args);
	va_end(Args);

	wchar_t wBuffer[0x130];
	MultiByteToWideChar(0, 1, szBuffer, 100, wBuffer, 100);

	dwOldSize = D2WIN_SetTextSize(dwFont);
	if (dwCenter != -1)
	{
		D2WIN_GetTextWidthFileNo(wBuffer, &wWidth, &dwFileNo);
		nPos.x -= (wWidth >> dwCenter);
	}
	
	D2WIN_DrawText (wBuffer,nPos.x, nPos.y,dwColor,-1);
	D2WIN_SetTextSize(dwOldSize);
} 

void BoxHook(INT x, INT y, INT xSize, INT ySize, DWORD dwColor, DWORD Trans, BOOL Automap)
{
	POINT Start = {x, y};
	POINT End = {xSize, ySize};
	if (Automap) 
	{
		if (!p_D2CLIENT_AutomapOn)
		return;
		ScreenToAutomap(&Start, x * 32, y * 32);
	}
	return D2GFX_DrawRectangle(Start.x, Start.y, End.x + Start.x, End.y + Start.y, dwColor, Trans);
}


void Information()
{
	int x_2=750; int y_2=495; int font_2=4; int space_2=-16; // added
	char* color1_2="4"; char* color2_2="1"; char* color3_2="2"; // added
	int a_2=150; int b_2=542; // added
	char szTime[200];
	int nTime = ((GetTickCount () - nGameTimer) / 1000);
	sprintf_s(szTime, 200, "%.2d:%.2d:%.2d", nTime/3600, (nTime/60)%60, nTime%60);
	//TextHook(a_2,b_2,0,0,font_2,-1,"ÿc%s%.2d:%.2d:%.2d", color2_2, nTime/3600, (nTime/60)%60, nTime%60);
	char curTime[200]; time_t ttTime; time(&ttTime);
	strftime(curTime, 100, "%m/%d/%y",localtime(&ttTime));
	//TextHook(a_2,b_2,0,0,font_2,-1,"ÿc%s%s", color2_2,szTime);
	
	char curTime2[200]; time(&ttTime);
	strftime(curTime2, 100, "%H:%M:%S",localtime(&ttTime));
	
	//TIME
	if(cfg.TimeStamp)
	{
		TextHook(120,520,4, false, font_2, -1, "%s", szTime);
		TextHook(120,540,4, false, font_2, -1, "%s - %s", curTime, curTime2);
	}

	int x=750; int y=495; int font=4; int space=-16;
	char* color1="4"; char* color2="1"; char* color3="2";

	if(cfg.ExtraInfo)
	{
		//int a=305; int b=13;
		//375
		int a=275; int b=542;
		TextHook(a,b,0,0,font,0,"ÿc%sAim: ",color1);

			if(AA && LeftAA) TextHook(a,b,0,0,font,-1,"ÿc%sLeft",color3);
			else if(AA && !LeftAA) TextHook(a,b,0,0,font,-1,"ÿc%sRight",color3);
			else if(!AA && LeftAA) TextHook(a,b,0,0,font,-1,"ÿc%sLeft",color2);
			else TextHook(a,b,0,0,font,-1,"ÿc%sRight",color2);

		a+=105;
	
		TextHook(a,b,0,0,font,0,"ÿc%sBlind: ",color1);

			if(BlindToggled) TextHook(a,b,0,0,font,-1,"ÿc%s%i",color3,cfg.BlindSpot);
			else TextHook(a,b,0,0,font,-1,"ÿc%sOFF",color2);

		a+=95;
	
		TextHook(a,b,0,0,font,0,"ÿc%sFlash: ",color1);
			if(Flash) TextHook(a,b,0,0,font,-1,"ÿc%sON",color3);
			else TextHook(a,b,0,0,font,-1,"ÿc%sOFF",color2);
	}
}
void DrawAutomapInfos(void)
{
	DrawAutomapText(); DrawMonsters(); NewEnum();
	if(cfg.DrawVectors) DrawVectorArrows();
	if(cfg.PlayerLine) DrawPlines();
	if(cfg.PlayerInfo&&cfg.IHPKTag) TextHook(780,13,0,0,0,0,"ÿc3Team jEFF");
	DrawOriginal();
}

void ScreenHooks(void)
{
	if(cfg.AimBoxEnabled && AA) DrawYonTarget();

	if(cfg.PlayerInfo)
	{		
		Information();
		if(TargetToggled) TargetWindow();
		if(DrinkToggled) DrinkWindow();
		if(StatToggled) StatWindow(GetPlayerID());
		//if(WinampToggled) WinampWindow();
		if(ChickenToggled) ChickenWindow();
	}
}

void GameDraw(void)
{
	RevealActOnce();

	if(cfg.PlayerInfo && cfg.ShowLifeManaPer) LifeManaPercents();

	if(DrawPlayerInventory) 
	{
		UnitAny* PlayerUnit=(UnitAny*)FindUnit(Auto.GetPlayerID(),0);

		int xPlayer=565; int yPlayer=310;

		if(!PlayerUnit || PlayerUnit->pPath && GetDistanceSquared(PlayerX(),PlayerY(),PlayerUnit->pPath->xPos,PlayerUnit->pPath->yPos)>2000) 
		{ 
			DrawPlayerInventory=false; ToggleInventory(false); UninstallPatches();
		} 
		else 
		{
			if(IsInventoryOpen()==false) 
			{
				UninstallPatches(); DrawPlayerInventory=false;
			}

			DrawTextToScreenCenter(Auto.GetPlayerNAME(),xPlayer,yPlayer,8,0);
		}
	}
}
void GameDraw2(void)
{
	if(GetUnitLevel(Myself)->dwLevelNo != nLastLevel)
	{
		GetVectorArrows(); nLastLevel = GetUnitLevel(Myself)->dwLevelNo;
	}
}