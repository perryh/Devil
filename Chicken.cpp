#include "DevilPK.h"

int DrankHealthPot;
int DrankManaPot;
int DrankRejLife;
int DrankRejMana;

void ChickenCheck(void)
{
	if(GameReady())
	{
		UnitAny *pUnit = D2CLIENT_GetPlayerUnit();
		
		if(pUnit)
		{		
			int LifePercent=((GetCurrentLife())*100)/(GetMaxLife());
			int ManaPercent=((GetCurrentMana())*100)/(GetMaxMana());
			int CurrentLife=GetCurrentLife();
			
			if(pUnit->dwMode == PLAYER_MODE_DEAD || pUnit->dwMode == PLAYER_MODE_DEATH) return;

			if(cfg.Drink && cfg.DrinkLife > 0 && LifePercent <= cfg.DrinkLife && CurrentLife > 0)
			{
				if(IsTownLevel(GetPlayerArea())) return;

				if(DrankHealthPot == -1 || GetTickCount() - DrankHealthPot > cfg.DrinkLifeTimer
					&& !D2COMMON_GetUnitState(Myself,AFFECT_HEALTHPOT))
				{
					if(SupplyHealth())
					{
						DrankHealthPot = GetTickCount(); Sleep(50);
					}
				}	
			}
			if(cfg.Drink && cfg.DrinkMana > 0 && ManaPercent <= cfg.DrinkMana && CurrentLife > 0)
			{
				if(IsTownLevel(GetPlayerArea())) return;

				if(DrankManaPot == -1 || GetTickCount() - DrankManaPot > cfg.DrinkManaTimer
					&& !D2COMMON_GetUnitState(Myself,AFFECT_MANAPOT))
				{
					if(SupplyMana())
					{
						DrankManaPot = GetTickCount(); Sleep(50);
					}
				}
			}
			if(cfg.Drink && cfg.DrinkLifeRej > 0 && LifePercent <= cfg.DrinkLifeRej && CurrentLife > 0)
			{
				if(IsTownLevel(GetPlayerArea())) return;

				if(DrankRejLife == -1 || GetTickCount() - DrankRejLife > cfg.DrinkRejuTimer)
				{
					if(SupplyJuv())
					{
						DrankRejLife = GetTickCount(); Sleep(50);
					}
					else if(cfg.QuitOnJuvRunOut) D2CLIENT_ExitGame();
				}
			}
			if(cfg.Drink && cfg.DrinkManaRej > 0 && ManaPercent <= cfg.DrinkManaRej && CurrentLife > 0)
			{
				if(IsTownLevel(GetPlayerArea())) return;

				if(DrankRejMana == -1 || GetTickCount() - DrankRejMana > cfg.DrinkRejuTimer)
				{
					if(SupplyJuv())
					{
						DrankRejMana = GetTickCount(); Sleep(50);
					}
					else if(cfg.QuitOnJuvRunOut) D2CLIENT_ExitGame();
				}
			}

			if(cfg.TownLifeChicken!=0 && LifePercent<=cfg.TownLifeChicken && CurrentLife > 0)
			{
				if(IsTownLevel(GetPlayerArea())) return;
				else TownLife();
			}
			if(cfg.TownManaChicken!=0 && ManaPercent<=cfg.TownManaChicken && CurrentLife > 0)
			{
				if(IsTownLevel(GetPlayerArea())) return;
				else TownMana();
			}

			if(cfg.QuitLife!=0 && LifePercent <= cfg.QuitLife && CurrentLife > 0)
			{
				if(IsTownLevel(GetPlayerArea())) return;
				else D2CLIENT_ExitGame();
			}
			if(cfg.QuitMana!=0 && ManaPercent<=cfg.QuitMana && CurrentLife > 0)
			{
				if(IsTownLevel(GetPlayerArea())) return;
				else D2CLIENT_ExitGame();
			}
		}
	}
}

void TownLife()
{
	int LifePercent=((GetCurrentLife())*100)/(GetMaxLife());
	int ManaPercent=((GetCurrentMana())*100)/(GetMaxMana());
	int CurrentLife=GetCurrentLife();

	TakeNextTP=true; v_AntiTppkBusy=true; 

	if(MakeTP())
	{
		Sleep(250);

		if(cfg.QuitOnFailedTP && !IsTownLevel(GetPlayerArea()) && LifePercent <= cfg.TownLifeChicken
			&& CurrentLife > 0) D2CLIENT_ExitGame();
		else return;
	}
	else
	{
		 v_AntiTppkBusy=false; D2CLIENT_ExitGame();
	}
}

void TownMana()
{
	int LifePercent=((GetCurrentLife())*100)/(GetMaxLife());
	int ManaPercent=((GetCurrentMana())*100)/(GetMaxMana());
	int CurrentLife=GetCurrentLife();

	TakeNextTP=true; v_AntiTppkBusy=true; 

	if(MakeTP())
	{
		Sleep(250);

		if(cfg.QuitOnFailedTP && !IsTownLevel(GetPlayerArea()) && ManaPercent<=cfg.TownManaChicken
			&& CurrentLife > 0) D2CLIENT_ExitGame();
		else return;
	}
	else
	{
		v_AntiTppkBusy=false; D2CLIENT_ExitGame();
	}
}

char* PotionName(DWORD dwTxtFileNo)
{
	switch(dwTxtFileNo)
	{
	case 515:
		{
			return "Rejuvenation";
		}
	case 516:
		{
			return "Full Rejuvenation";
		}
	case 587:
		{
			return "Minor Healing";
		}
	case 588:
		{
			return "Light Healing";
		}
	case 589:
		{
			return "Healing";
		}
	case 590:
		{
			return "Greater Healing";
		}
	case 591:
		{
			return "Super Healing";
		}
	case 592:
		{
			return "Minor Mana";
		}
	case 593:
		{
			return "Light Mana";
		}
	case 594:
		{
			return "Mana";
		}
	case 595:
		{
			return "Greater Mana";
		}
	case 596:
		{
			return "Super Mana";
		}
	default:
		{
			return "Unknown";
		}
	}
}
BOOL SupplyHealth()
{
	LPSTR szItemCodes[] = {"hp5", "hp4", "hp3", "hp2", "hp1"};
	UnitAny* pItem;

	for(INT i = 0; i < ArraySize(szItemCodes); i++)
	{
		pItem = FindItem(szItemCodes[i], STORAGE_BELT);

		if(!pItem) pItem = FindItem(szItemCodes[i], STORAGE_INVENTORY);

		if(!pItem) continue;

		UseItem(pItem);
		
		if(cfg.PrintIHPKMessages) PrintDevilPKString("Auto Potion drank a %s potion!",PotionName(pItem->dwTxtFileNo));

		return TRUE;
	}

	return FALSE;
}
BOOL SupplyMana()
{
	LPSTR szItemCodes[] = {"mp5", "mp4", "mp3", "mp2", "mp1"};
	UnitAny* pItem;

	for(INT i = 0; i < ArraySize(szItemCodes); i++)
	{
		pItem = FindItem(szItemCodes[i], STORAGE_BELT);

		if(!pItem) pItem = FindItem(szItemCodes[i], STORAGE_INVENTORY);

		if(!pItem) continue;

		UseItem(pItem);

		if(cfg.PrintIHPKMessages) PrintDevilPKString("Auto Potion drank a %s potion!",PotionName(pItem->dwTxtFileNo));

		return TRUE;
	}

	return FALSE;
}

BOOL SupplyJuv()
{
	LPSTR szItemCodes[] = {"rvl", "rvs"};
	UnitAny* pItem;

	for(INT i = 0; i < ArraySize(szItemCodes); i++)
	{
		pItem = FindItem(szItemCodes[i], STORAGE_BELT);

		if(!pItem) pItem = FindItem(szItemCodes[i], STORAGE_INVENTORY);

		if(!pItem) continue;

		UseItem(pItem);

		if(cfg.PrintIHPKMessages) PrintDevilPKString("Auto Potion drank a %s potion!",PotionName(pItem->dwTxtFileNo));

		return TRUE;
	}

	return FALSE;
}