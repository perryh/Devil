#include "DevilPK.h"

DWORD WINAPI AutoPartyThread(LPVOID lpParameter)
{
	while(!GameReady ())
		SleepEx(10, true);

	while(true)
	{
		SleepEx(10, true);
        if(!EnchBot)
            continue;
        if (!cfg.AutoParty)
			continue;

		BnetData *pData = *p_D2LAUNCH_BnData;

		if (!GameReady ())
			continue;

		UnitAny *pPlayer = D2CLIENT_GetPlayerUnit ();

		for (RosterUnit* pUnit = *p_D2CLIENT_PlayerList; pUnit; pUnit = pUnit->pNext)
		{
			if (pUnit->dwUnitId == pPlayer->dwUnitId)
				continue;

			switch(pUnit->dwPartyFlags)
			{
				case PARTY_INVITED_YOU:
					D2CLIENT_clickParty(pUnit, clickParty_Accept);
				break;
				case PARTY_NOT_IN_PARTY:
					D2CLIENT_clickParty(pUnit, clickParty_Invite);
				break;
			}
		}
    }
}