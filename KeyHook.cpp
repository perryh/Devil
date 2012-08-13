#include "DevilPK.h"
#include "ArrayEX.h"

bool HostPlayer=false;
bool TakeNextTP=false;
bool FastPortal=false;
bool CampOn=false;
bool CampUnitOn=false;
bool BlindToggled=false;

POINT Camp;
POINT aPath[255];
POINT WalkPath[255];
POINT Safed;
DWORD dwCount;
DWORD QuestID;
int telex=0;

int GetMaxTrackTime() 
{ 
   HWND win = FindWindowA("Winamp v1.x",NULL); 
   if(win) 
   return SendMessage(win,WM_USER,1,105); 

   return 0; 
} 

int GetCurrentTrackTime() 
{ 
   HWND win = FindWindowA("Winamp v1.x",NULL); 
   if(win) 
   return SendMessage(win,WM_USER,0,105); 

   return 0; 
} 

DWORD WINAPI AdThread(void* p)
{
	char* argv[500]={0};
	char Buffer[500];
	sprintf(Buffer,cfg.ADMessage);

		Speak(Buffer);
		Sleep(1);

	sprintf(Buffer,cfg.ADMessage2);

		Speak(Buffer);
		Sleep(1);

	sprintf(Buffer,cfg.ADMessage3);

		Speak(Buffer);
		Sleep(1);

	sprintf(Buffer,cfg.ADMessage4);

		Speak(Buffer);
		Sleep(1);

	sprintf(Buffer,cfg.ADMessage5);

		Speak(Buffer);
		Sleep(1);

	sprintf(Buffer,cfg.ADMessage6);

		Speak(Buffer);
		Sleep(1);

	sprintf(Buffer,cfg.ADMessage7);

		Speak(Buffer);
		Sleep(1);

	sprintf(Buffer,cfg.ADMessage8);

		Speak(Buffer);
		Sleep(1);

	sprintf(Buffer,cfg.ADMessage9);

		Speak(Buffer);
		Sleep(1);

	sprintf(Buffer,cfg.ADMessage10);

		Speak(Buffer);
		Sleep(1);

	sprintf(Buffer,cfg.ADMessage11);

		Speak(Buffer);
		Sleep(1);

	sprintf(Buffer,cfg.ADMessage12);

		Speak(Buffer);
		Sleep(1);

	sprintf(Buffer,cfg.ADMessage13);

		Speak(Buffer);
		Sleep(1);

	sprintf(Buffer,cfg.ADMessage14);

		Speak(Buffer);
		Sleep(1);

	sprintf(Buffer,cfg.ADMessage15);

		Speak(Buffer);
		Sleep(1);

	sprintf(Buffer,cfg.ADMessage16);

		Speak(Buffer);
		Sleep(1);

	sprintf(Buffer,cfg.ADMessage17);

		Speak(Buffer);
		Sleep(1);

	sprintf(Buffer,cfg.ADMessage18);

		Speak(Buffer);
		Sleep(1);

	return 0;	
}

void __fastcall KeyHook(BYTE keycode, BYTE repeat)
{ 	
	if(repeat) return;

	if( keycode ==  cfg.SilentExit)
	{
		if(!GetSkill(D2S_CONFUSE)) SetSkill(D2S_CONFUSE, FALSE);

		else SetSkill(D2S_HOLYSHIELD, FALSE);
	}

	if(keycode==cfg.PlayerInfoToggle)
	{
		if(!cfg.PlayerInfo) cfg.PlayerInfo=true;

		else cfg.PlayerInfo=false;
	}

	if( keycode == cfg.FastExit)
	{
		D2CLIENT_ExitGame();
	}

	if(keycode == cfg.Hostile) 
	{
		if(IsTownLevel(GetPlayerArea())) 
		{
			char Buffer[200];

			if(cfg.HostileTarget) Hostile(Auto.GetPlayerID());

			else HostileAll();

			if(cfg.PrintOverhead) OverheadMessage("Hostiled");
		}
	}
	if(keycode == cfg.TeleToPlayer)
	{
		char Buffer[200];

		if(FindUnit(Auto.GetPlayerID(),0)!=NULL)
		{
			Tele(GetPlayerX(Auto.GetPlayerID()),GetPlayerY(Auto.GetPlayerID()));
		}

		if(FindUnit(Auto.GetPlayerID(),0)==NULL) return;
	}
	if( keycode == cfg.BlindAAToggle)
	{
		char Buf[200];

		if(!BlindToggled)
		{
			BlindToggled=true;

			if(cfg.PrintMessages) PrintString("Blind Aim: ÿc2ON (%i)",cfg.BlindSpot);

			if(cfg.PrintOverhead)
			{
				sprintf(Buf,"Blind ON (%i)",cfg.BlindSpot);
				OverheadMessage(Buf);
			}
		}
		else
		{
			BlindToggled=false;

			if(cfg.PrintMessages) PrintString("Blind Aim: ÿc1OFF");

			if(cfg.PrintOverhead) OverheadMessage("Blind OFF");
		}
	}
	if( keycode == cfg.TeleToPlayerHost)
	{
		char Buffer[200];

		if(FindUnit(Auto.GetPlayerID(),0)!=NULL)
		{
			if(IsTownLevel(GetPlayerArea()))
			{
				HostPlayer=true;
				Hostile(Auto.GetPlayerID());
				Tele(GetPlayerX(Auto.GetPlayerID()),GetPlayerY(Auto.GetPlayerID()));
			}
			if(!IsTownLevel(GetPlayerArea()))
			{
				HostPlayer=false;
				Tele(GetPlayerX(Auto.GetPlayerID()),GetPlayerY(Auto.GetPlayerID()));
			}

			if(FindUnit(Auto.GetPlayerID(),0)==NULL) return;
		}
	}
	if(keycode==cfg.FlashKey)
	{
		char Buffer[200];

		if(Auto.IsPlayerFriend()) return;

		else if(!Flash)
		{				
			if(cfg.PrintMessages) PrintString("ÿc2Flashing %s",GetNameByID(Auto.GetPlayerID()));

			if(cfg.PrintOverhead)
			{
				sprintf(Buffer,"Flashing %s",GetNameByID(Auto.GetPlayerID()));
				OverheadMessage(Buffer);
			}
			Flash=true;
		}
		else if(Flash)
		{
			if(cfg.PrintMessages) PrintString("ÿc2Stopped Flashing %s",GetNameByID(Auto.GetPlayerID()));

			if(cfg.PrintOverhead)
			{
				sprintf(Buffer,"Stopped Flashing %s",GetNameByID(Auto.GetPlayerID()));
				OverheadMessage(Buffer);
			}
			Flash=false;
		}
	}
	if(keycode==cfg.FastTP)
	{
		TakeNextTP=true; v_AntiTppkBusy=true; HostPlayer=false;

		if(IsTownLevel(GetPlayerArea()))
		{ 
			TakeNextTP=false; return;
		}
		if(MakeTP())
		{
			CampOn=false; CampUnitOn=false;

			if(cfg.PrintOverhead) OverheadMessage("Escaping to town!");

			return;
		}

		else TakeNextTP=false;
	}

	if(keycode==cfg.TPPK)
	{
		TakeNextTP=true; v_AntiTppkBusy=true; HostPlayer=true;

		if(IsTownLevel(GetPlayerArea()))
		{ 
			TakeNextTP=false; HostPlayer=false; return;
		}
		if(MakeTP())
		{
			CampOn=false; CampUnitOn=false;

			if(cfg.PrintOverhead) OverheadMessage("TPPK'ing this bitch!");

			return;
		}
		else
		{
			TakeNextTP=false; HostPlayer=false;
		}
	}

	if(keycode == cfg.NextTarget)
	{		
		Auto.GetNextPlayer();
		if(Auto.GetPlayerID()==GetPlayerID()) Auto.GetNextPlayer();
	}

	if(keycode==cfg.AimToggle)
	{
		if(AA)
		{
			AA=false;
			if(cfg.PrintMessages) PrintString("Auto Aim: ÿc1OFF");

			if(cfg.PrintOverhead) OverheadMessage("Auto Aim OFF");
		}
		else
		{
			AA=true;
			if(cfg.PrintMessages) PrintString("Auto Aim: ÿc2ON");

			if(cfg.PrintOverhead) OverheadMessage("Auto Aim ON");
		}
	}

	if(keycode==cfg.AimSlotToggle)
	{
		if(LeftAA)
		{
			LeftAA=0;

			if(cfg.PrintMessages) PrintString("ÿc0Auto Aim switched to: ÿc2Right!");

			if(cfg.PrintOverhead) OverheadMessage("Aim switched to ÿc2Right!");
		}
		else
		{ 
			LeftAA=1;

			if(cfg.PrintMessages) PrintString("ÿc0Auto Aim switched to: ÿc2Left!");

			if(cfg.PrintOverhead) OverheadMessage("Aim switched to ÿc2Left!");
		}
	}

	if(keycode==cfg.Camp)
	{
		if(CampUnitOn) return;

		if(IsTownLevel(GetPlayerArea())) return;

		if(!CampOn)
		{
			GetD2MousePos(Camp); char Buf[100]; CampOn=true;

			if(cfg.PrintOverhead) OverheadMessage("Auto Camp Activated");

			return;
		}
		if(CampOn)
		{
			CampOn=false;

			if(cfg.PrintOverhead) OverheadMessage("Auto Camp Deactivated");

			HoldRightUp(Camp.x,Camp.y);
		}
	}

	if(keycode==cfg.CampUnit)
	{
		if(CampUnitOn)
		{
			CampUnitOn=false;
			if(cfg.PrintOverhead) OverheadMessage("Camp Unit Deactivated");

			HoldRightUp(Camp.x,Camp.y);

			return;
		}

		if(CampOn) return;

		if(IsTownLevel(GetPlayerArea())) return; 

		if(Auto.IsPlayerFriend()) return;

		if(!CampUnitOn)
		{
			GetD2MousePos(Camp);
			char Buf[100];
			CampUnitOn=true;
			if(cfg.PrintOverhead) OverheadMessage("Camp Unit Activated");
		}
	}

	if(keycode==cfg.WPPath)
	{
		if(!IsTownLevel(GetPlayerArea()) && GetSkill(0x36)!=NULL) 
		{					
			QuestID=0;
			PathToVector(3);

			if(cfg.PrintOverhead) OverheadMessage("Auto Tele Activated");
		}
	}
	if(keycode==cfg.SpecialPath)
	{
		if(!IsTownLevel(GetPlayerArea()) && GetSkill(0x36)!=NULL) 
		{					
			QuestID=3;
			PathToVector(4);

			if(cfg.PrintOverhead) OverheadMessage("Auto Tele Activated");
		}
	}
	if(keycode==cfg.NextLevelPath)
	{
		if(!IsTownLevel(GetPlayerArea()) && GetSkill(0x36)!=NULL) 
		{					
			QuestID=1;
			PathToVector(1);

			if(cfg.PrintOverhead) OverheadMessage("Auto Tele Activated");
		}
	}
	if(keycode==cfg.LastLevelPath)
	{
		if(!IsTownLevel(GetPlayerArea()) && GetSkill(0x36)!=NULL) 
		{					
			QuestID=2;
			PathToVector(2);

			if(cfg.PrintOverhead) OverheadMessage("Auto Tele Activated");
		}
	}

	if(keycode==cfg.EnchBotToggle)
	{
		char Buffer[100];
		if(!EnchBot)
		{
			EnchBot=true;
			if(cfg.PrintOverhead) OverheadMessage("Ench Bot Activated");

			sprintf(Buffer,"Enchant Bot has been Activated! Commands: <%s> <%s> <%s>",cfg.EnchMe,cfg.EnchMerc,cfg.EnchAll);		
			Speak(Buffer);
			CreateThread(0,0,AutoPartyThread,0,0,0);
		}	
		else
		{
			EnchBot=false;
			if(cfg.PrintOverhead) OverheadMessage("Ench Bot Deactivated");

			Speak("Enchant Bot has been Deactivated!");
			TerminateThread(AutoPartyThread,0);
		}
	}

	if(keycode==cfg.ItemViewer)
	{
		char Buffer[200];
		if(FindUnit(Auto.GetPlayerID(),0)!=NULL)
		{
			DrawPlayerInventory=true;
			InstallPatches();
			ToggleInventory(true); 
		}
		else return;
	}

	if(keycode==cfg.ADKey)
	{
		CreateThread(0,0,AdThread,0,0,0);
	}

	if(keycode==cfg.WNext)
	{
		NextSong();
	}
	if(keycode==cfg.WPrev)
	{
		PrevSong();
	}
	if(keycode==cfg.WStop)
	{ 
		StopSong();
	}
	if(keycode==cfg.WPlay)
	{
		PlayPause();
	}
	if(keycode==cfg.WSong)
	{
		HWND win = FindWindowA("Winamp v1.x",NULL);
		char Buffer[200];
		int ct = GetCurrentTrackTime(); 
		int mt = GetMaxTrackTime(); 

		if(win)
		{
			if((mt)%60 == -1)
			{
				Speak("Current Track: %s <%02d:%02d:%02d>",GetCurrentWinampTrack(),ct/(1000*60*60),ct/(1000*60)%60, (ct/1000)%60);
			}
			else
			{
				Speak("Current Track: %s <%02d:%02d:%02d/%02d:%02d:%02d>",GetCurrentWinampTrack(),ct/(1000*60*60),ct/(1000*60)%60, (ct/1000)%60,mt/(60*60),mt/(60)%60, (mt)%60);
			}
		}
		else
		{	
			Speak("Current Track: %s",GetCurrentWinampTrack());
		}
	}

	if(keycode==cfg.StashKey)
	{
		if(D2CLIENT_GetUiVar(0x19))
		{
			D2CLIENT_SetUIVar(0x19, 1, 0);
		}
		else
		{
			BYTE data[2] = {0x77, 0x10};
			D2NET_ReceivePacket(data, 2);
		}
	}
}

DWORD WINAPI TeleportThread(LPVOID P)
{
	if(v_TeleportQueue.IsEmpty())
	{
		return 0;

		while(TRUE) Sleep(1);
	}
	DWORD WQuestID;
	DWORD Type;

	v_TeleportQueue.Lock();
	while(!v_TeleportQueue.IsEmpty())
	{
		AutoTele=true;

		BOOL bArrived = FALSE;
		INT nIterations = 0;

		if(GetCurrentSkill(FALSE) != D2S_TELEPORT)
			SetSkill(D2S_TELEPORT, FALSE);

		while(GetCurrentSkill(FALSE) != D2S_TELEPORT)
			Sleep(1);

		BYTE aPacket[5];
		aPacket[0] = 0x0C;
		*(LPWORD)&aPacket[1] = (WORD)v_TeleportQueue[0].x;
		*(LPWORD)&aPacket[3] = (WORD)v_TeleportQueue[0].y;
		D2NET_SendPacket(5, 1, aPacket);


		while(nIterations < 1000 && AutoTele)
		{
			if(!GameReady() || IsTownLevel(GetPlayerArea()))
			{
				AutoTele=false;
				break;
			}

			if(CalculateDistance(Myself->pPath->xPos, Myself->pPath->yPos, v_TeleportQueue[0].x, v_TeleportQueue[0].y) <= 5)
			{
				bArrived = TRUE;
				break;
			}

			Sleep(1);
			nIterations++;
		}

		if(!bArrived)
		{
			v_TeleportQueue.RemoveAll();
			v_TeleportQueue.Unlock();
			return 0;
		}

		v_TeleportQueue.RemoveAt(0);
		v_TeleportQueue.FreeExtra();
	}

	Sleep(50);

	if(QuestID==1)
	{
		WQuestID=GlobalVectors.QuestID;
		Type=0x05;
	}
	if(QuestID==2)
	{
		WQuestID=GlobalVectors.OtherID;
		Type=0x05;
	}
	if(QuestID==3)
	{
		WQuestID=GlobalVectors.SpecialID;
		Type=0x05;
	}

	
	if(WQuestID && v_CurrentVector->dwTargetType != -1 && v_CurrentVector->nType != 3)
	{
		BYTE EnterPacket[]={0x13,0x05,0,0,0, 0x00,0x00,0x00,0x00};
		*(DWORD*)&EnterPacket[1]=Type;
		*(DWORD*)&EnterPacket[5]=WQuestID;
		SendGAMEPacket(EnterPacket,sizeof(EnterPacket));
		goto EndLoop;
	}	

	if(v_CurrentVector)
	{
		for(Room1* pRoom = Myself->pAct->pRoom1; pRoom; pRoom = pRoom->pRoomNext)
		{
			for(UnitAny* pUnit = pRoom->pUnitFirst; pUnit; pUnit = pUnit->pListNext)
			{
				if(pUnit->dwType == UNIT_TYPE_TILE && v_CurrentVector->dwTargetType == -1)
				{
					if(v_GlobalMap->GetTileLevelNo(pRoom->pRoom2, pUnit->dwTxtFileNo) == v_CurrentVector->dwTarget)
					{
						Interact(pUnit->dwUnitId, pUnit->dwType, FALSE);
						goto EndLoop;
					}
				}
				if(pUnit->dwType == UNIT_TYPE_OBJECT && v_CurrentVector->nType == 3)
				{
					if(pUnit->dwTxtFileNo == v_CurrentVector->dwTarget)
					{
						Interact(pUnit->dwUnitId, pUnit->dwType, FALSE);
						goto EndLoop;
					}
				}
			}
		}
EndLoop:;
	}

	AutoTele=false;

	v_TeleportQueue.Unlock();	

	if(cfg.PrintOverhead) OverheadMessage("Auto Tele Deactivated");

	return 0;
}