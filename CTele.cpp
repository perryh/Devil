#include "DevilPK.h"

Level* GetLevelPointerE(ActMisc *pActMisc, int nLevel)
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

void fpEnumPresetUnits(fpp EnumFunctions) {
	UnitAny *pUnit = D2CLIENT_GetPlayerUnit (); 
	Level *pLevel = GetLevelPointerE(pUnit->pAct->pMisc, GetPlayerArea()); 

	for(Room2 *curRoom2 = pLevel->pRoom2First;curRoom2;curRoom2=(Room2*)curRoom2->dwRoomsNear/*pRoom2Other*/) {
	//	for(Room1 * pRoom1 = 
		BOOL bAdded = FALSE;
		BOOL bEnding = FALSE; 
		if(!curRoom2->pRoom1) {
			//D2COMMON_AddRoomData(D2CLIENT_GetPlayerUnit()->pAct, pLevel->dwLevelNo, curRoom2->dwPosX, curRoom2->dwPosY, D2CLIENT_GetPlayerUnit()->pPath->pRoom1);
			D2COMMON_AddRoomData(pLevel->pMisc->pAct,pLevel->dwLevelNo, curRoom2->dwPosX, curRoom2->dwPosY, pUnit->pPath->pRoom1);
			bAdded = TRUE;
		}
		for(PresetUnit *unit = curRoom2->pPreset;unit;unit=unit->pPresetNext) {
			PresetUnit pu; 
			pu.pPresetNext = 0;
			pu.dwTxtFileNo = unit->dwTxtFileNo;
			pu.dwType = unit->dwType;
			pu.dwPosX = unit->dwPosX+curRoom2->dwPosX*5;
			pu.dwPosY = unit->dwPosY+curRoom2->dwPosY*5;
			if (bEnding = !EnumFunctions(&pu)) break;
		}
		if(bAdded)
			//D2COMMON_RemoveRoomData(D2CLIENT_GetPlayerUnit()->pAct, pLevel->dwLevelNo, curRoom2->dwPosX, curRoom2->dwPosY, D2CLIENT_GetPlayerUnit()->pPath->pRoom1);
		D2COMMON_RemoveRoomData(pLevel->pMisc->pAct, pLevel->dwLevelNo, curRoom2->dwPosX, curRoom2->dwPosY, D2CLIENT_GetPlayerUnit()->pPath->pRoom1);
		if (bEnding) break;
	}
}




PresetUnit* PresentGlobal;
DWORD GlobalClassID;
bool _stdcall PosEnum(PresetUnit* pUnit) {
	if(pUnit->dwTxtFileNo==GlobalClassID) {
		PresentGlobal=pUnit;
		return FALSE;
	}
	return TRUE;
}

BOOL GetPositionByClassID(DWORD ID,POINT* p) {
	PresentGlobal=0;
	GlobalClassID=ID;
	fpEnumPresetUnits(PosEnum);
	if(!PresentGlobal)
	return FALSE;
	p->x=PresentGlobal->dwPosX;
	p->y=PresentGlobal->dwPosY;
	return TRUE;
}


POINT GlobalPos;
UnitAny* GlobalUnit;
bool _stdcall ObjEnum(UnitAny* pUnit) {
	if(pUnit->pObjectPath)
		if(pUnit->pObjectPath->dwPosX==GlobalPos.x && pUnit->pObjectPath->dwPosY==GlobalPos.y) {
			GlobalUnit=pUnit;
			return FALSE;
		}
	if(pUnit->pPath)
		if(pUnit->pPath->xPos==GlobalPos.x && pUnit->pPath->yPos == GlobalPos.y) {
			GlobalUnit=pUnit;
			return FALSE;
		}
	return TRUE;
}

UnitAny* GetUnitByPosition(long x,long y) {
	GlobalUnit=0;
	GlobalPos.x=x;
	GlobalPos.y=y;
	fpEnumUnits(ObjEnum,UNIT_ALL);
	return GlobalUnit;
}

BOOL CTele::DefinePathList(char* List) {
	CHAR *Buffer[1024];
	CHAR szList[1024];
	
	strcpy(szList,List);

	CTele::PathSize = MakeParameter(szList,Buffer,',',true);

	if(!CTele::PathSize)
		return FALSE;

	for(int i=0;i<CTele::PathSize;i++) {
			strcpy(CTele::PathList[i],Buffer[i]);
	}

	return TRUE;
}

DWORD CTele::CheckVaildObject(CHAR* List) {
	CHAR *Buffer[1024];
	CHAR szBuffer[1024];
	POINT Position;
	strcpy(szBuffer,List);
	DWORD argv = MakeParameter(szBuffer,Buffer,'/',true);
	for(int i=0;i<argv;i++)
		if(GetPositionByClassID(atoi(Buffer[i]),&Position))
			return atoi(Buffer[i]);
	return 0;
}

BOOL CTele::StartTeleport() {
	// Going throught every PathList
	for(int i=0; i < CTele::PathSize; i++) {
		POINT Path[255] = {0};
		POINT ObjectPosition;
		DWORD Current = 0;
		DWORD Time = 0;
		DWORD pID;
			if(!GetPositionByClassID(CheckVaildObject(CTele::PathList[i]),&ObjectPosition))
				return FALSE;
		WORD PathAmount = fpCalculateTeleportPath(ObjectPosition.x,ObjectPosition.y,Path,255);
			if(!PathAmount)
				return FALSE;
		
			while(Current<PathAmount) {
				if(Time == 0)
					TeleportTo(Path[Current].x,Path[Current].y);
				else if(Time >= 10) {
					Time = 0;
					Current = 0;
					PathAmount = fpCalculateTeleportPath(ObjectPosition.x,ObjectPosition.y,Path,255);
					continue;
				}
				if(GetDistanceSquared(GetPosition().x,GetPosition().y,Path[Current].x,Path[Current].y) <= 5) {
					Current ++;
					Time = 0;
					continue;
				}
				Time ++;
			Sleep(50);
			}
		DWORD OldArea=GetPlayerArea();
		
		//Log(1,"adfgadfg");
		UnitAny* pObject;
		while(!GetUnitByPosition(ObjectPosition.x,ObjectPosition.y)) 
			Sleep(100);
		while(OldArea==GetPlayerArea() && i!=CTele::PathSize - 1) {
			pObject = GetUnitByPosition(ObjectPosition.x,ObjectPosition.y);
			if(pObject) {
				pID=pObject->dwUnitId;			
			}
			else return FALSE;	
			Interact(pID,5);
			Sleep(300);
		}
		Sleep(300);
		
	}
	return TRUE;
}

BOOL CTele::Teleport(long x,long y) {
		POINT Path[255] = {0};	
		DWORD Current=0;
		DWORD Time=0;
		WORD PathAmount = fpCalculateTeleportPath(x,y,Path,255);
			if(!PathAmount)
				return FALSE;
		
			while(Current<PathAmount) {
				if(Time == 0)
					TeleportTo(Path[Current].x,Path[Current].y);
				else if(Time >= 10) {
					Time = 0;
					continue;
				}
				if(GetDistanceSquared(GetPosition().x,GetPosition().y,Path[Current].x,Path[Current].y) <= 5) {
					Current ++;
					Time = 0;
					continue;
				}
				Time ++;
			Sleep(50);
			}
			Sleep(100);
		return TRUE;
}