#include "DevilPK.h"


VOID AutoAim::GetNextPlayer()
{
	int i=0;
	int B=Current;
	Init();
	while(i<B&&pUnit!=NULL)
	{
		pUnit=pUnit->pNext;
		i++;
	}
	if(pUnit==NULL)
	{
		Current=1; Init();
	}
	else 
	Current=B+1;
	char Buffer[200];
}
long AutoAim::GetPlayerX()
{
	if(pUnit==NULL)  Init();
	return pUnit->Xpos;
}
long AutoAim::GetPlayerY()
{
	if(pUnit==NULL)  Init();
	return pUnit->Ypos;
}
INT AutoAim::GetPlayerLevel()
{
	if(pUnit==NULL) Init();
	return pUnit->wLevel;
}
BOOL AutoAim::SelectPlayer(DWORD PID)
{
	pUnit=(RosterUnit*)*(DWORD*)0x6FBCC080; 
	while(pUnit)
	{
		if(pUnit->dwUnitId==PID) 
		return true;
		pUnit=pUnit->pNext;
	}
return false;
}
VOID AutoAim::Init()
{
	pUnit=(RosterUnit*)*(DWORD*)0x6FBCC080;
	Current=1;
}
VOID AutoAim::ChangeTarget(INT nPlayer)
{
	pUnit=(RosterUnit*)*(DWORD*)0x6FBCC080;

	switch (nPlayer)
	{
	case 2:
		{
			pUnit=pUnit->pNext;
			break;
		}
	case 3:
		{
			pUnit=pUnit->pNext;
			pUnit=pUnit->pNext;
			break;
		}
	case 4:
		{
			pUnit=pUnit->pNext;
			pUnit=pUnit->pNext;
			pUnit=pUnit->pNext;
			break;
		}
	case 5:
		{
			pUnit=pUnit->pNext;
			pUnit=pUnit->pNext;
			pUnit=pUnit->pNext;
			pUnit=pUnit->pNext;
			break;
		}
	case 6:
		{
			pUnit=pUnit->pNext;
			pUnit=pUnit->pNext;
			pUnit=pUnit->pNext;
			pUnit=pUnit->pNext;
			pUnit=pUnit->pNext;
			break;
		}
	case 7:
		{
			pUnit=pUnit->pNext;
			pUnit=pUnit->pNext;
			pUnit=pUnit->pNext;
			pUnit=pUnit->pNext;
			pUnit=pUnit->pNext;
			pUnit=pUnit->pNext;
			break;
		}
	case 8:
		{
			pUnit=pUnit->pNext;
			pUnit=pUnit->pNext;
			pUnit=pUnit->pNext;
			pUnit=pUnit->pNext;
			pUnit=pUnit->pNext;
			pUnit=pUnit->pNext;
			pUnit=pUnit->pNext;
			break;
		}
	}
	Current=nPlayer;
}
DWORD AutoAim::GetPlayerID()
{
	if(pUnit==NULL)
	{
		Init(); 
		return pUnit->dwUnitId;
	}
	return pUnit->dwUnitId;
}
char* AutoAim::GetPlayerNAME()
{
	if(pUnit==NULL)  Init();
	return pUnit->szName2;
}
DWORD AutoAim::GetPlayerCLASS()
{
	if(pUnit==NULL) Init();
	return pUnit->dwClassId;
}
BOOL AutoAim::IsPlayerFriend()
{
	//if(pUnit==NULL) Init();
	//return CheckPlayerFriend(GetPlayerNAME());
	return FALSE;
}
BOOL AttackPlayer(DWORD dwUnitId)
{
	if(!GameReady() || IsTownLevel(GetPlayerArea()))
		return FALSE;

	UnitAny* pTarget = GetUnit(dwUnitId, UNIT_TYPE_PLAYER);

	if(!LeftAA)
	{
		WORD SkillID = GetCurrentSkillRight();

		if(!pTarget || pTarget->dwMode == PLAYER_MODE_DEAD)
			return FALSE;

		if(SkillID == D2S_CHARGEDSTRIKE || SkillID == D2S_ENCHANT || SkillID == D2S_BONEPRISON)
		{
			BYTE aPacket[9];
			aPacket[0] = LeftAA ? 0x0A : 0x11;
			*(LPDWORD)&aPacket[1] = UNIT_TYPE_PLAYER;
			*(LPDWORD)&aPacket[5] = dwUnitId;

			D2NET_SendPacket(9, 1, aPacket);
			return TRUE;
		}

		else
		{
			AttackStruct Attack;
			D2SpellInfo Spell;

			Attack.dwAttackType = ATTACKTYPE_SHIFTRIGHT;
			GetSkillInfo(SkillID, &Spell);

			if(SkillID != D2S_TELEPORT)
			{
				Attack.dwTargetX = pTarget->pPath->xPos;
				Attack.dwTargetY = pTarget->pPath->yPos;
			}

			if(pTarget->dwMode == PLAYER_MODE_RUN && !BlindToggled  && SkillID == D2S_TELEPORT)
			{
				Attack.dwTargetX = pTarget->pPath->xTarget;
				Attack.dwTargetX = pTarget->pPath->yTarget;
			}
			if(SkillID == D2S_TELEPORT && !BlindToggled)
			{
				Attack.dwTargetX = pTarget->pPath->xPos;
				Attack.dwTargetY = pTarget->pPath->yPos;
			}
			if(BlindToggled && SkillID == D2S_TELEPORT && cfg.BlindSpot == 1)
			{
				Attack.dwTargetX = pTarget->pPath->xPos + 2;
				Attack.dwTargetY = pTarget->pPath->yPos + 2;
			}
			if(BlindToggled && SkillID == D2S_TELEPORT && cfg.BlindSpot == 2)
			{
				Attack.dwTargetX = pTarget->pPath->xPos + 3;
				Attack.dwTargetY = pTarget->pPath->yPos + 2;
			}
			if(BlindToggled && SkillID == D2S_TELEPORT && cfg.BlindSpot == 3)
			{
				Attack.dwTargetX = pTarget->pPath->xPos - 1;
				Attack.dwTargetY = pTarget->pPath->yPos + 3;
			}
			if(BlindToggled && SkillID == D2S_TELEPORT && cfg.BlindSpot == 4)
			{
				Attack.dwTargetX = pTarget->pPath->xPos + 1;
				Attack.dwTargetY = pTarget->pPath->yPos - 1.2;
			}
			if(BlindToggled && cfg.BlindSpot == 5)
			{
				Attack.dwTargetX = pTarget->pPath->xPos;
				Attack.dwTargetY = pTarget->pPath->yPos;
			}

			Attack.lpPlayerUnit = Myself;

			if(Spell.dwSpellInfoFlag & DSI_GUIDED)
			{
				Attack.dwAttackType = LeftAA ? ATTACKTYPE_UNITLEFT : ATTACKTYPE_RIGHT;
				Attack.lpTargetUnit = GetUnit(dwUnitId, UNIT_TYPE_PLAYER);
			}
			else
				Attack.lpTargetUnit = NULL;

			Attack._1 = 3;
			Attack._2 = 4;

			D2CLIENT_Attack(&Attack, (Spell.dwSpellInfoFlag & DSI_GUIDED) ? TRUE : FALSE);

			return TRUE;
		}
	}

	if(LeftAA)
	{
		WORD SkillID = GetCurrentSkillLeft();

		if(!pTarget || pTarget->dwMode == PLAYER_MODE_DEAD)
			return FALSE;

		if(SkillID == D2S_CHARGEDSTRIKE || SkillID == D2S_ENCHANT || SkillID == D2S_BONEPRISON)
		{
			BYTE aPacket[9];
			aPacket[0] = LeftAA ? 0x0A : 0x11;
			*(LPDWORD)&aPacket[1] = UNIT_TYPE_PLAYER;
			*(LPDWORD)&aPacket[5] = dwUnitId;

			D2NET_SendPacket(9, 1, aPacket);
			return TRUE;
		}

		else
		{
			AttackStruct Attack;
			D2SpellInfo Spell;

			Attack.dwAttackType = ATTACKTYPE_SHIFTLEFT;
			GetSkillInfo(SkillID, &Spell);

			if(SkillID != D2S_TELEPORT)
			{
				Attack.dwTargetX = pTarget->pPath->xPos;
				Attack.dwTargetY = pTarget->pPath->yPos;
			}

			if(pTarget->dwMode == PLAYER_MODE_RUN && !BlindToggled && SkillID == D2S_TELEPORT)
			{
				Attack.dwTargetX = pTarget->pPath->xTarget;
				Attack.dwTargetX = pTarget->pPath->yTarget;
			}

			if(SkillID == D2S_TELEPORT && !BlindToggled)
			{
				Attack.dwTargetX = pTarget->pPath->xPos;
				Attack.dwTargetY = pTarget->pPath->yPos;
			}
			if(BlindToggled && SkillID == D2S_TELEPORT && cfg.BlindSpot == 1)
			{
				Attack.dwTargetX = pTarget->pPath->xPos + 2;
				Attack.dwTargetY = pTarget->pPath->yPos + 2;
			}
			if(BlindToggled && SkillID == D2S_TELEPORT && cfg.BlindSpot == 2)
			{
				Attack.dwTargetX = pTarget->pPath->xPos + 3;
				Attack.dwTargetY = pTarget->pPath->yPos + 2;
			}
			if(BlindToggled && SkillID == D2S_TELEPORT && cfg.BlindSpot == 3)
			{
				Attack.dwTargetX = pTarget->pPath->xPos - 1;
				Attack.dwTargetY = pTarget->pPath->yPos + 3;
			}
			if(BlindToggled && SkillID == D2S_TELEPORT && cfg.BlindSpot == 4)
			{
				Attack.dwTargetX = pTarget->pPath->xPos + 1;
				Attack.dwTargetY = pTarget->pPath->yPos - 1.2;
			}
			if(BlindToggled && cfg.BlindSpot == 5)
			{
				Attack.dwTargetX = pTarget->pPath->xPos;
				Attack.dwTargetY = pTarget->pPath->yPos;
			}

			Attack.lpPlayerUnit = Myself;

			if(Spell.dwSpellInfoFlag & DSI_GUIDED)
			{
				Attack.dwAttackType = LeftAA ? ATTACKTYPE_UNITLEFT : ATTACKTYPE_RIGHT;
				Attack.lpTargetUnit = GetUnit(dwUnitId, UNIT_TYPE_PLAYER);
			}
			else
				Attack.lpTargetUnit = NULL;

			Attack._1 = 3;
			Attack._2 = 4;

			D2CLIENT_Attack(&Attack, (Spell.dwSpellInfoFlag & DSI_GUIDED) ? TRUE : FALSE);

			return TRUE;
		}
	}

	return FALSE;
}