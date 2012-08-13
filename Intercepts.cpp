#include "DevilPK.h"

int GeneralColor;

DWORD PlayerPatchJMP=0x6FB0CEC1;
DWORD CallOne=0x6FB0D5A0;
DWORD MoveOn=0x6FBCC1D8;
DWORD CSS;
DWORD BreakItUp=0x6F9B;
DWORD DontBreak=0x6F9E;

BOOL MaxAmazon()
{
	if(bp.FCR1 >= 0 && bp.FCR1 <= 200)
	{
		BYTE aPacket[3];
		aPacket[0] = 0x1D;
		aPacket[1] = 105;
		aPacket[2] = (bp.FCR1);
		D2NET_ReceivePacket(aPacket, sizeof(aPacket));
	}
    if(bp.FBR1 >= 0 && bp.FBR1 <= 200)
	{
		BYTE aPacket[3];
		aPacket[0] = 0x1D;
		aPacket[1] = 102;
		aPacket[2] = (bp.FBR1);
		D2NET_ReceivePacket(aPacket, sizeof(aPacket));
	}
    if(bp.FHR1 >= 0 && bp.FHR1 <= 200)
	{
		BYTE aPacket[3];
		aPacket[0] = 0x1D;
		aPacket[1] = 99;
		aPacket[2] = (bp.FHR1);
		D2NET_ReceivePacket(aPacket, sizeof(aPacket));
	}
	if(bp.IAS1 >= 0 && bp.IAS1 <= 200)
	{
		BYTE aPacket[3];
		aPacket[0] = 0x1D;
		aPacket[1] = 93;
		aPacket[2] = (bp.IAS1);
		D2NET_ReceivePacket(aPacket, sizeof(aPacket));
	}
	return TRUE;
}
BOOL MaxAssassin()
{
	if(bp.FCR2 >= 0 && bp.FCR2 <= 200)
	{
		BYTE aPacket[3];
		aPacket[0] = 0x1D;
		aPacket[1] = 105;
		aPacket[2] = (bp.FCR2);
		D2NET_ReceivePacket(aPacket, sizeof(aPacket));
	}
    if(bp.FBR2 >= 0 && bp.FBR2 <= 200)
	{
		BYTE aPacket[3];
		aPacket[0] = 0x1D;
		aPacket[1] = 102;
		aPacket[2] = (bp.FBR2);
		D2NET_ReceivePacket(aPacket, sizeof(aPacket));
	}
    if(bp.FHR2 >= 0 && bp.FHR2 <= 200)
	{
		BYTE aPacket[3];
		aPacket[0] = 0x1D;
		aPacket[1] = 99;
		aPacket[2] = (bp.FHR2);
		D2NET_ReceivePacket(aPacket, sizeof(aPacket));
	}
	if(bp.IAS2 >= 0 && bp.IAS2 <= 200)
	{
		BYTE aPacket[3];
		aPacket[0] = 0x1D;
		aPacket[1] = 93;
		aPacket[2] = (bp.IAS2);
		D2NET_ReceivePacket(aPacket, sizeof(aPacket));
	}
	return TRUE;
}
BOOL MaxBarbarian()
{
	if(bp.FCR3 >= 0 && bp.FCR3 <= 200)
	{
		BYTE aPacket[3];
		aPacket[0] = 0x1D;
		aPacket[1] = 105;
		aPacket[2] = (bp.FCR3);
		D2NET_ReceivePacket(aPacket, sizeof(aPacket));
	}
    if(bp.FBR3 >= 0 && bp.FBR3 <= 200)
	{
		BYTE aPacket[3];
		aPacket[0] = 0x1D;
		aPacket[1] = 102;
		aPacket[2] = (bp.FBR3);
		D2NET_ReceivePacket(aPacket, sizeof(aPacket));
	}
    if(bp.FHR3 >= 0 && bp.FHR3 <= 200)
	{
		BYTE aPacket[3];
		aPacket[0] = 0x1D;
		aPacket[1] = 99;
		aPacket[2] = (bp.FHR3);
		D2NET_ReceivePacket(aPacket, sizeof(aPacket));
	}
	if(bp.IAS3 >= 0 && bp.IAS3 <= 200)
	{
		BYTE aPacket[3];
		aPacket[0] = 0x1D;
		aPacket[1] = 93;
		aPacket[2] = (bp.IAS3);
		D2NET_ReceivePacket(aPacket, sizeof(aPacket));
	}
	return TRUE;
}
BOOL MaxDruid()
{
	if(bp.FCR4 >= 0 && bp.FCR4 <= 200)
	{
		BYTE aPacket[3];
		aPacket[0] = 0x1D;
		aPacket[1] = 105;
		aPacket[2] = (bp.FCR4);
		D2NET_ReceivePacket(aPacket, sizeof(aPacket));
	}
    if(bp.FBR4 >= 0 && bp.FBR4 <= 200)
	{
		BYTE aPacket[3];
		aPacket[0] = 0x1D;
		aPacket[1] = 102;
		aPacket[2] = (bp.FBR4);
		D2NET_ReceivePacket(aPacket, sizeof(aPacket));
	}
    if(bp.FHR4 >= 0 && bp.FHR4 <= 200)
	{
		BYTE aPacket[3];
		aPacket[0] = 0x1D;
		aPacket[1] = 99;
		aPacket[2] = (bp.FHR4);
		D2NET_ReceivePacket(aPacket, sizeof(aPacket));
	}
	if(bp.IAS4 >= 0 && bp.IAS4 <= 200)
	{
		BYTE aPacket[3];
		aPacket[0] = 0x1D;
		aPacket[1] = 93;
		aPacket[2] = (bp.IAS4);
		D2NET_ReceivePacket(aPacket, sizeof(aPacket));
	}
	return TRUE;
}
BOOL MaxNecromancer()
{
	if(bp.FCR5 >= 0 && bp.FCR5 <= 200)
	{
		BYTE aPacket[3];
		aPacket[0] = 0x1D;
		aPacket[1] = 105;
		aPacket[2] = (bp.FCR5);
		D2NET_ReceivePacket(aPacket, sizeof(aPacket));
	}
    if(bp.FBR5 >= 0 && bp.FBR5 <= 200)
	{
		BYTE aPacket[3];
		aPacket[0] = 0x1D;
		aPacket[1] = 102;
		aPacket[2] = (bp.FBR5);
		D2NET_ReceivePacket(aPacket, sizeof(aPacket));
	}
    if(bp.FHR5 >= 0 && bp.FHR5 <= 200)
	{
		BYTE aPacket[3];
		aPacket[0] = 0x1D;
		aPacket[1] = 99;
		aPacket[2] = (bp.FHR5);
		D2NET_ReceivePacket(aPacket, sizeof(aPacket));
	}
	if(bp.IAS5 >= 0 && bp.IAS5 <= 200)
	{
		BYTE aPacket[3];
		aPacket[0] = 0x1D;
		aPacket[1] = 93;
		aPacket[2] = (bp.IAS5);
		D2NET_ReceivePacket(aPacket, sizeof(aPacket));
	}
	return TRUE;
}
BOOL MaxPaladin()
{
	if(bp.FCR6 >= 0 && bp.FCR6 <= 200)
	{
		BYTE aPacket[3];
		aPacket[0] = 0x1D;
		aPacket[1] = 105;
		aPacket[2] = (bp.FCR6);
		D2NET_ReceivePacket(aPacket, sizeof(aPacket));
	}
    if(bp.FBR6 >= 0 && bp.FBR6 <= 200)
	{
		BYTE aPacket[3];
		aPacket[0] = 0x1D;
		aPacket[1] = 102;
		aPacket[2] = (bp.FBR6);
		D2NET_ReceivePacket(aPacket, sizeof(aPacket));
	}
    if(bp.FHR6 >= 0 && bp.FHR6 <= 200)
	{
		BYTE aPacket[3];
		aPacket[0] = 0x1D;
		aPacket[1] = 99;
		aPacket[2] = (bp.FHR6);
		D2NET_ReceivePacket(aPacket, sizeof(aPacket));
	}
	if(bp.IAS6 >= 0 && bp.IAS6 <= 200)
	{
		BYTE aPacket[3];
		aPacket[0] = 0x1D;
		aPacket[1] = 93;
		aPacket[2] = (bp.IAS6);
		D2NET_ReceivePacket(aPacket, sizeof(aPacket));
	}
	return TRUE;
}
BOOL MaxSorceress()
{
	if(bp.FCR7 >= 0 && bp.FCR7 <= 200)
	{
		BYTE aPacket[3];
		aPacket[0] = 0x1D;
		aPacket[1] = 105;
		aPacket[2] = (bp.FCR7);
		D2NET_ReceivePacket(aPacket, sizeof(aPacket));
	}
    if(bp.FBR7 >= 0 && bp.FBR7 <= 200)
	{
		BYTE aPacket[3];
		aPacket[0] = 0x1D;
		aPacket[1] = 102;
		aPacket[2] = (bp.FBR7);
		D2NET_ReceivePacket(aPacket, sizeof(aPacket));
	}
    if(bp.FHR7 >= 0 && bp.FHR7 <= 200)
	{
		BYTE aPacket[3];
		aPacket[0] = 0x1D;
		aPacket[1] = 99;
		aPacket[2] = (bp.FHR1);
		D2NET_ReceivePacket(aPacket, sizeof(aPacket));
	}
	if(bp.IAS7 >= 0 && bp.IAS7 <= 200)
	{
		BYTE aPacket[3];
		aPacket[0] = 0x1D;
		aPacket[1] = 93;
		aPacket[2] = (bp.IAS7);
		D2NET_ReceivePacket(aPacket, sizeof(aPacket));
	}
	return TRUE;
}










void __declspec(naked) ReceivePacketIntercept_STUB()
{
	__asm
	{
		pop ebp;
		pushad;

		call OnGamePacketReceived;
		test eax, eax;

		popad;
		jnz OldCode;

		mov edx, 0;

OldCode:
		call D2NET_ReceivePacket_I;

		push ebp;
		ret;
	}
}



void __declspec(naked) SendPacketIntercept_STUB()
{
   __asm
   {
      pushad;

      mov ecx, [esp + 0x20 + 0xC];
      mov edx, [esp + 0x20 + 0x4];
      call SendPacket;
      test eax, eax;

      popad;
      jnz OldCode;

      mov [esp + 0x4], 0;

OldCode:
      jmp D2NET_SendPacket;
   }
}


void __declspec(naked) KeyHookIntercept_STUB()
{
	__asm
	{
		__asm
		{
			mov cl,[edi+0x08]
			mov dl,[edi+0x0c+3]
			and dl,0x40
			call KeyHook

			test byte ptr [edi+0x0c+3],0x40
			ret
		}
	}
}

void __declspec(naked) GameLightRadius_STUB()
{
	__asm
	{
		cmp esi, 1;
		je OldCode;

		mov eax, 0xFF
			mov byte ptr [esp + 0x4], al;
		mov byte ptr [esp + 0x4 + 1], al;
		mov byte ptr [esp + 0x4 + 2], al;

		add dword ptr [esp], 0x82;
		ret;

OldCode:
		mov byte ptr [esp + 0x4 + 1], 0;
		ret;
	}
}


void __declspec(naked) GameDrawAutomapInfo_STUB()
{
	__asm
	{
		push eax;
		call DrawAutomapInfos;
		pop eax;
		pop edi;
		pop esi;
		ret;
	}
}

void __declspec(naked) GameDraw_STUB()
{
	__asm
	{
		call GameDraw2;
		POP ESI
		POP EBX
		POP ECX
		RETN 4
	}
}
void __fastcall FasterMissiles(UnitAny* pUnit)
{
}
void __fastcall FasterAttack()
{
}
void __declspec(naked) DrawEnteringLevelText_STUB()
{
	__asm
	{
		call ScreenHooks;
		call D2CLIENT_DrawEnteringLevelText;
		ret;
	}
}

void __declspec(naked) DrawManaOrb_STUB()
{
	__asm
	{
		call D2CLIENT_DrawManaOrb;
		call GameDraw;
		ret;
	}
}
void __declspec(naked) DrawStamina_STUB()
{
	__asm
	{
		call TabbedWindows;
		call D2CLIENT_DrawStamina;
		ret;
	}
}

void __declspec(naked) DrawStaminaA_STUB()
{
	__asm
	{
		call TabbedWindows;
		call D2CLIENT_DrawStaminaA;
		ret;
	}
}

DWORD GetCommonBase()
{
	return (DWORD)LoadLibrary("D2Common.dll");
}
int __fastcall PlayerMap(UnitAny* pUnit, DWORD color)
{
	if(pUnit && pUnit->dwUnitId!=GetPlayerID())
	{
		if(cfg.PlayerLine && pUnit->dwUnitId==Auto.GetPlayerID())
		{
			return 8;
		}  
		else
		{
			switch(GetPvPStatus(pUnit->dwUnitId))
			{
				case PVP_HOSTILE:
				{
					return 1;
				} 
				case PVP_FRIENDLY:
				{
					return 2;
				}
				case PVP_NEUTRAL:
				{
					return 1;
				}
			}
		}
	}
	return color;
}
void __declspec(naked) PlayerMapIntercept()
{
	__asm
	{
		// Saving return address
		pop edi
		pushad
		mov ecx, [esp+0x20]
		mov edx, [esp+0x20+0xc]
		Call PlayerMap
		lea esi, [esp+0x0c+0x20]
		mov [esi], eax // Overwriting Target Color .. :D
		lea esi, [esp+0x20+0x20]
		mov [esi], 120
		popad
		call GetCommonBase
		add eax, 0x56D80
		call eax
		push edi
		retn
	}
}

void __fastcall PlayerBlobHook(UnitAny* pUnit, DWORD color)
{
	if(pUnit!=NULL && pUnit->dwUnitId!=GetPlayerID())
	{
		if(cfg.PlayerLine && pUnit->dwUnitId==Auto.GetPlayerID())
		{
			GeneralColor=11;
		}
		else
		{
			switch(GetPvPStatus(pUnit->dwUnitId))
			{
				case PVP_HOSTILE:
				{
					GeneralColor=98;
				} 
				case PVP_FRIENDLY:
				{
					GeneralColor=132;
				}
				case PVP_NEUTRAL:
				{
					GeneralColor=98;
				}
			}
		}
	}
	return;
}
void __fastcall PlayPatch(WORD X,WORD Y)
{
	WORD LeftSkillID = GetCurrentSkillLeft();
	WORD SkillID = GetCurrentSkillRight();

	if(AA && LeftAA)
	{
		if(Auto.GetPlayerID()==GetPlayerID() && GetDistance(GetPlayerX(GetPlayerID()),GetPlayerY(GetPlayerID()),GetPlayerX(Auto.GetPlayerID()),GetPlayerY(Auto.GetPlayerID()))<2000)
		{
			DWORD xX=X;
			DWORD xY=Y;
			__asm
			{
				mov ecx, xX
				mov edx, xY
			}
			return;
		}
		DWORD mX=GetPlayerX(Auto.GetPlayerID());
		DWORD mY=GetPlayerY(Auto.GetPlayerID());

		if(!BlindToggled || BlindToggled && cfg.BlindSpot != 5 && LeftSkillID != D2S_TELEPORT)
		{
			mX=GetPlayerX(Auto.GetPlayerID());
			mY=GetPlayerY(Auto.GetPlayerID());
		}
		if(LeftSkillID == D2S_TELEPORT && BlindToggled && cfg.BlindSpot == 1)
		{
			mX=GetPlayerX(Auto.GetPlayerID());
			mX=mX+2;
			mY=GetPlayerY(Auto.GetPlayerID());
			mY=mY+2;
		}
		if(LeftSkillID == D2S_TELEPORT && BlindToggled && cfg.BlindSpot == 2)
		{
			mX=GetPlayerX(Auto.GetPlayerID());
			mX=mX+3;
			mY=GetPlayerY(Auto.GetPlayerID());
			mY=mY+2;
		}
		if(LeftSkillID == D2S_TELEPORT && BlindToggled && cfg.BlindSpot == 3)
		{
			mX=GetPlayerX(Auto.GetPlayerID());
			mX=mX-1;
			mY=GetPlayerY(Auto.GetPlayerID());
			mY=mY+3;
		}
		if(LeftSkillID == D2S_TELEPORT && BlindToggled && cfg.BlindSpot == 4)
		{
			mX=GetPlayerX(Auto.GetPlayerID());
			mX=mX+1;
			mY=GetPlayerY(Auto.GetPlayerID());
			mY=mY-1.2;
		}
		if(cfg.BlindSpot == 5 && BlindToggled )
		{
			mX=GetPlayerX(Auto.GetPlayerID());
			mY=GetPlayerY(Auto.GetPlayerID());
		}
		__asm
		{
			mov ecx, mX
			mov edx, mY
		}
	}
	else if (CSS)
	{
		__asm
		{
			mov ecx, ecx
			mov edx, edx
		}
	}
	if(AA && !LeftAA)
	{
		if(Auto.GetPlayerID()==GetPlayerID() && GetDistance(GetPlayerX(GetPlayerID()),GetPlayerY(GetPlayerID()),GetPlayerX(Auto.GetPlayerID()),GetPlayerY(Auto.GetPlayerID()))<2000)
		{
			DWORD xX=X;
			DWORD xY=Y;
			__asm 
			{
				mov ecx, xX
				mov edx, xY
			}
			return;
		}
		DWORD mX=GetPlayerX(Auto.GetPlayerID());
		DWORD mY=GetPlayerY(Auto.GetPlayerID());

		if(!BlindToggled || BlindToggled && cfg.BlindSpot != 5 && SkillID != D2S_TELEPORT)
		{
			mX=GetPlayerX(Auto.GetPlayerID());
			mY=GetPlayerY(Auto.GetPlayerID());
		}
		if(BlindToggled && SkillID == D2S_TELEPORT && cfg.BlindSpot == 1)
		{
			mX=GetPlayerX(Auto.GetPlayerID());
			mX=mX+2;
			mY=GetPlayerY(Auto.GetPlayerID());
			mY=mY+2;
		}
		if(BlindToggled && SkillID == D2S_TELEPORT && cfg.BlindSpot == 2)
		{
			mX=GetPlayerX(Auto.GetPlayerID());
			mX=mX+3;
			mY=GetPlayerY(Auto.GetPlayerID());
			mY=mY+2;
		}
		if(BlindToggled && SkillID == D2S_TELEPORT && cfg.BlindSpot == 3)
		{
			mX=GetPlayerX(Auto.GetPlayerID());
			mX=mX-1;
			mY=GetPlayerY(Auto.GetPlayerID());
			mY=mY+3;
		}
		if(BlindToggled && SkillID == D2S_TELEPORT && cfg.BlindSpot == 4)
		{
			mX=GetPlayerX(Auto.GetPlayerID());
			mX=mX+1;
			mY=GetPlayerY(Auto.GetPlayerID());
			mY=mY-1.2;
		}
		if(BlindToggled && cfg.BlindSpot == 5)
		{
			mX=GetPlayerX(Auto.GetPlayerID());
			mY=GetPlayerY(Auto.GetPlayerID());
		}
		__asm
		{
			mov ecx, mX
			mov edx, mY
		}
	}
	else if (CSS)
	{
		__asm
		{
			mov ecx, ecx
			mov edx, edx
		}
	}
}
void __declspec(naked) PlayerPatch() {
	__asm {
		MOV eax,DWORD PTR DS:[MoveOn]
		mov [eax],1
		call CallOne
  //      jmp jumpout 
		mov eax,[CSS]
		test eax,eax
		jne ChangeAim
		mov eax,[AA]
		test eax,eax
		je jumpout

ChangeAim:
		pushad

		MOV ECX, DWORD PTR SS:[ESP+0x58]
		MOV EDX, DWORD PTR SS:[ESP+0x5C]
		MOV EBX, DWORD PTR SS:[ESP+0x54]
		MOV EBP, DWORD PTR SS:[ESP+0x58+4+4]

		MOV EAX,LeftAA
		cmp eax, 1
		je Left

		cmp ebx, 0x03
		je da

		cmp ebx, 0x04
		je da
jmp weg
da:
		call PlayPatch
		MOV DWORD PTR SS:[ESP+0x58],ECX
		MOV DWORD PTR SS:[ESP+0x5C],EDX

		jmp weg
Left:

		cmp ebp, 0x0C
		jne weg

		cmp ebx, 0x0
		je keep
			
		cmp ebx, 0x01
		je keep



		jmp weg
keep:
		call PlayPatch
		MOV DWORD PTR SS:[ESP+0x58],ECX
		MOV DWORD PTR SS:[ESP+0x5c],EDX
weg:
		popad
jumpout:
		jmp PlayerPatchJMP
	}
}


void __declspec(naked) PlayerBlobIntercept()
{
	__asm
	{
		pop edi 
		pushad
		mov ecx, [esp+0x4+0x20]
		call PlayerBlobHook
		popad
		mov cl, byte ptr [GeneralColor]
		push edi
		retn
	}
}

void __declspec(naked) GameFailToJoin_STUB()
{
	__asm
	{
		cmp esi, 4000;
		ret;
	}
}
DWORD __declspec(naked) __fastcall GetUiVar(DWORD dwVarNo)
{
	__asm
	{
		mov eax, ecx;
		jmp D2CLIENT_GetUiVar_I;
	}
}
BOOL NotMoving()
{
	if(!MoveStat && !MoveAmp && !MoveTarget &&
		!MoveChicken && !MoveDrink)
		return TRUE;

	return FALSE;
}
LONG WINAPI GameWindowEvent(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	if(!(GetUiVar(UI_CHAT) || GetUiVar(UI_NPCMENU) || GetUiVar(UI_TRADE) ||
		GetUiVar(UI_INVENTORY) || GetUiVar(UI_STASH) || GetUiVar(UI_CUBE)))
	{
		if(uMsg == WM_ACTIVATEAPP && !wParam)
		{
			if(cfg.AntiMinimize) return FALSE;
		}

		if (uMsg == WM_LBUTTONDOWN)
		{
			if(cfg.MoveBoxes)
			{
				if(D2CLIENT_MouseX >= box.TargetX && D2CLIENT_MouseX <= box.TargetX2 &&
					D2CLIENT_MouseY >= box.TargetY && D2CLIENT_MouseY <= box.TargetY2)
				{
					if(NotMoving())
					{
						if(TargetToggled)
						{
							cfg.TargetX=D2CLIENT_MouseX; cfg.TargetY=D2CLIENT_MouseY;

							MoveTarget=true; return FALSE;
						}
					}
				}
				if(D2CLIENT_MouseX >= box.CurrentTargetX && D2CLIENT_MouseX <= box.CurrentTargetX2 &&
					D2CLIENT_MouseY >= box.CurrentTargetY && D2CLIENT_MouseY <= box.CurrentTargetY2)
				{
					if(NotMoving())
					{
						if(TargetToggled)
						{
							MoveTarget=true; return FALSE;
						}
					}
				}
				if(D2CLIENT_MouseX >= box.PlayerX && D2CLIENT_MouseX <= box.PlayerX2 &&
					D2CLIENT_MouseY >= box.PlayerY && D2CLIENT_MouseY <= box.PlayerY2)
				{					
					if(NotMoving())
					{
						if(PlayerToggled)
						{
							MovePlayer=true; return FALSE;
						}
					}
				}
				if(D2CLIENT_MouseX >= box.ChickenX && D2CLIENT_MouseX <= box.ChickenX2 &&
					D2CLIENT_MouseY >= box.ChickenY && D2CLIENT_MouseY <= box.ChickenY2)
				{
					if(NotMoving())
					{
						if(ChickenToggled)
						{
							MoveChicken=true; return FALSE;
						}
					}
				}
				if(D2CLIENT_MouseX >= box.DrinkX && D2CLIENT_MouseX <= box.DrinkX2 &&
					D2CLIENT_MouseY >= box.DrinkY && D2CLIENT_MouseY <= box.DrinkY2)
				{
					if(NotMoving())
					{
						if(DrinkToggled)
						{
							MoveDrink=true; return FALSE;
						}
					}
				}
				if(D2CLIENT_MouseX >= box.AmpX && D2CLIENT_MouseX <= box.AmpX2 &&
					D2CLIENT_MouseY >= box.AmpY && D2CLIENT_MouseY <= box.AmpY2)
				{
					if(NotMoving())
					{
						if(WinampToggled)
						{
							MoveAmp=true; return FALSE;
						}
					}
				}
				if(D2CLIENT_MouseX >= box.StatX && D2CLIENT_MouseX <= box.StatX2 &&
					D2CLIENT_MouseY >= box.StatY && D2CLIENT_MouseY <= box.StatY2)
				{
					if(NotMoving())
					{
						if(StatToggled)
						{
							MoveStat=true; return FALSE;
						}
					}
				}
				if(D2CLIENT_MouseX >= box.Tab1X && D2CLIENT_MouseX <= box.Tab5X2 &&
					D2CLIENT_MouseY >= box.Tab1Y && D2CLIENT_MouseY <= box.Tab1Y2)
				{
					if(cfg.ShowTabsAlways) cfg.ShowTabsAlways=false;
					else cfg.ShowTabsAlways=true;

					return FALSE;
				}
			}
		}
		if (uMsg == WM_RBUTTONDOWN)
		{
			if(cfg.MoveBoxes)
			{
				//Target Box
				if(D2CLIENT_MouseX >= box.TargetX && D2CLIENT_MouseX <= box.TargetX2 &&
					D2CLIENT_MouseY >= box.TargetY && D2CLIENT_MouseY <= box.TargetY2)
				{
					if(NotMoving())
					{
						if(TargetToggled)
						{
							TargetToggled=false; return FALSE;
						}
					}
				}
				//Current Target Box
				if(D2CLIENT_MouseX >= box.CurrentTargetX && D2CLIENT_MouseX <= box.CurrentTargetX2 &&
					D2CLIENT_MouseY >= box.CurrentTargetY && D2CLIENT_MouseY <= box.CurrentTargetY2)
				{
					if(NotMoving())
					{
						if(TargetToggled)
						{
							TargetToggled=false; return FALSE;
						}
					}
				}
				//Player Box
				if(D2CLIENT_MouseX >= box.PlayerX && D2CLIENT_MouseX <= box.PlayerX2 &&
					D2CLIENT_MouseY >= box.PlayerY && D2CLIENT_MouseY <= box.PlayerY2)
				{
					if(NotMoving())
					{
						if(PlayerToggled)
						{
							PlayerToggled=false; return FALSE;
						}
					}
				}
				//Stat Box
				if(D2CLIENT_MouseX >= box.StatX && D2CLIENT_MouseX <= box.StatX2 &&
					D2CLIENT_MouseY >= box.StatY && D2CLIENT_MouseY <= box.StatY2)
				{
					if(NotMoving())
					{
						if(StatToggled)
						{
							StatToggled=false; return FALSE;
						}
					}
				}
				//Winamp Box
				if(D2CLIENT_MouseX >= box.AmpX && D2CLIENT_MouseX <= box.AmpX2 &&
					D2CLIENT_MouseY >= box.AmpY && D2CLIENT_MouseY <= box.AmpY2)
				{
					if(NotMoving())
					{
						if(WinampToggled)
						{
							WinampToggled=false; return FALSE;
						}
					}
				}
				//Chicken Box
				if(D2CLIENT_MouseX >= box.ChickenX && D2CLIENT_MouseX <= box.ChickenX2 &&
					D2CLIENT_MouseY >= box.ChickenY && D2CLIENT_MouseY <= box.ChickenY2)
				{
					if(NotMoving())
					{
						if(ChickenToggled)
						{
							ChickenToggled=false; return FALSE;
						}
					}
				}
				//Drink Box
				if(D2CLIENT_MouseX >= box.DrinkX && D2CLIENT_MouseX <= box.DrinkX2 &&
					D2CLIENT_MouseY >= box.DrinkY && D2CLIENT_MouseY <= box.DrinkY2)
				{
					if(NotMoving())
					{
						if(DrinkToggled)
						{
							DrinkToggled=false; return FALSE;
						}
					}
				}
			}
		}
		if (uMsg == WM_RBUTTONDOWN)
		{
			if(cfg.MoveBoxes)
			{
				if(D2CLIENT_MouseX >= box.Tab1X && D2CLIENT_MouseX <= box.Tab1X2 &&
					D2CLIENT_MouseY >= box.Tab1Y && D2CLIENT_MouseY <= box.Tab1Y2)
				{
					if(NotMoving() && !TargetToggled)
					{
						TargetToggled=true; return FALSE;
					}
				}
				if(D2CLIENT_MouseX >= box.Tab2X && D2CLIENT_MouseX <= box.Tab2X2 &&
					D2CLIENT_MouseY >= box.Tab2Y && D2CLIENT_MouseY <= box.Tab2Y2)
				{
					if(NotMoving() && !ChickenToggled)
					{
						ChickenToggled=true; return FALSE;
					}
				}
				if(D2CLIENT_MouseX >= box.Tab3X && D2CLIENT_MouseX <= box.Tab3X2 &&
					D2CLIENT_MouseY >= box.Tab3Y && D2CLIENT_MouseY <= box.Tab3Y2)
				{
					if(NotMoving() && !DrinkToggled)
					{
						DrinkToggled=true; return FALSE;
					}
				}
				if(D2CLIENT_MouseX >= box.Tab4X && D2CLIENT_MouseX <= box.Tab4X2 &&
					D2CLIENT_MouseY >= box.Tab4Y && D2CLIENT_MouseY <= box.Tab4Y2)
				{
					if(NotMoving() && !WinampToggled)
					{
						WinampToggled=true; return FALSE;
					}
				}
				if(D2CLIENT_MouseX >= box.Tab5X && D2CLIENT_MouseX <= box.Tab5X2 &&
					D2CLIENT_MouseY >= box.Tab5Y && D2CLIENT_MouseY <= box.Tab5Y2)
				{
					if(NotMoving() && !StatToggled)
					{
						StatToggled=true; return FALSE;
					}
				}
			}
		}
		if (uMsg == WM_LBUTTONUP)
		{
			if(cfg.MoveBoxes && TargetToggled)
			{
				if(D2CLIENT_MouseX==cfg.TargetX && D2CLIENT_MouseY==cfg.TargetY)
				{
					if(D2CLIENT_MouseX >= box.TargetX && D2CLIENT_MouseX <= box.TargetX2)
					{
						if (Players() > 1)
						{
							if(D2CLIENT_MouseY > (cfg.TargetBoxY + 15) &&
								D2CLIENT_MouseY <= (cfg.TargetBoxY + 24))

							Auto.ChangeTarget(2); 
						}
						if (Players() > 2)
						{
							if(D2CLIENT_MouseY > (cfg.TargetBoxY + 25) &&
								D2CLIENT_MouseY <= (cfg.TargetBoxY + 34))
								
							Auto.ChangeTarget(3); 
						}
						if (Players() > 3)
						{
							if(D2CLIENT_MouseY > (cfg.TargetBoxY + 35) &&
								D2CLIENT_MouseY <= (cfg.TargetBoxY + 44))
								
							Auto.ChangeTarget(4); 
						}
						if (Players() > 4)
						{
							if(D2CLIENT_MouseY > (cfg.TargetBoxY + 45) &&
								D2CLIENT_MouseY <= (cfg.TargetBoxY + 54))
											
							Auto.ChangeTarget(5); 
						}
						if (Players() > 5)
						{
							if(D2CLIENT_MouseY > (cfg.TargetBoxY + 55) &&
								D2CLIENT_MouseY <= (cfg.TargetBoxY + 64))
								
							Auto.ChangeTarget(6); 
						}
						if (Players() > 6)
						{
							if(D2CLIENT_MouseY > (cfg.TargetBoxY + 65) &&
								D2CLIENT_MouseY <= (cfg.TargetBoxY + 74))
								
							Auto.ChangeTarget(7); 
						}
						if (Players() > 7)
						{
							if(D2CLIENT_MouseY > (cfg.TargetBoxY + 75) &&
								D2CLIENT_MouseY <= (cfg.TargetBoxY + 84))
								
							Auto.ChangeTarget(8); 
						}
					}
				}
			}
		}
		if(uMsg == WM_LBUTTONUP)
		{
			if(cfg.MoveBoxes)
			{
				if(MoveTarget) MoveTarget=false; if(MovePlayer) MovePlayer=false;
				if(MoveDrink) MoveDrink=false; if(MoveChicken) MoveChicken=false;
				if(MoveStat) MoveStat=false; if(MoveAmp) MoveAmp=false;
			}
		}
		if (uMsg==WM_KEYUP)
		{
			if(wParam==cfg.MoveBox)
			{
				if(cfg.MoveBoxes)
				{
					cfg.MoveBoxes=false;

					MoveTarget=false; MovePlayer=false; MoveDrink=false;
					MoveChicken=false; MoveStat=false; MoveAmp=false;
				}
			}
		}
		if (uMsg==WM_KEYDOWN)
		{
			if(wParam==cfg.MoveBox)
			{
				if(cfg.PlayerInfo&&!cfg.MoveBoxes) cfg.MoveBoxes=true;
			}
		}
				
		if(uMsg == WM_KEYDOWN)
		{
			if(wParam == cfg.AttackPlayer)
			{
				if(GameReady())
				{
					RosterUnit *pUnit=(RosterUnit*)*(DWORD*)PlayerRoster; 
					DWORD TargetID=Auto.GetPlayerID();

					if(pUnit!=NULL) AttackPlayer(TargetID);
					else AttackPlayer(Myself->dwUnitId);

					return FALSE;
				}
			}
		}
	}
	return (LONG)CallWindowProcA(OldWNDPROC, hWnd, uMsg, wParam, lParam);
}
