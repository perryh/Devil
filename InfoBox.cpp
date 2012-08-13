#include "DevilPK.h"
DWORD CurrentExp;
DWORD nGameTimer;
bool PrintExp=false;
int AreaLocaleIds2[] = {0, 5055, 5054, 5053, 5052, 5051, 5050, 5049, 3714, 5047, 5046, 5045, 5044, 5043, 5042, 5041, 5040, 5039, 5038, 5037, 5036, 5035, 5034, 5033, 5032, 5031, 5030, 5029, 5028, 5027, 5026, 5025, 5024, 5023, 5022, 5021, 5020, 5019, 5018, 788, 852, 851, 850, 849, 848, 847, 846, 845, 844, 843, 842, 841, 840, 839, 838, 837, 836, 835, 834, 833, 832, 831, 830, 829, 828, 827, 826, 826, 826, 826, 826, 826, 826, 825, 824, 820, 819, 818, 817, 816, 815, 814, 813, 812, 810, 811, 809, 808, 806, 805, 807, 804, 845, 844, 803, 802, 801, 800, 799, 798, 797, 796, 795, 790, 792, 793, 794, 791, 789, 22646, 22647, 22648, 22649, 22650, 22651, 22652, 22653, 22654, 22655, 22656, 22657, 22660, 21865, 21866, 21867, 22658, 22659, 22662, 22663, 22664, 22665, 22667, 22666, 11155, 11156, 11157, 5018};

unsigned long int nLevelExp[] = {0, 500, 1500, 3750, 7875, 14175, 22680, 32886, 44396, 57715, 72144, 90180, 112725, 140906, 176132, 220165, 275207, 344008, 
		430010, 537513, 671891, 839864, 1049830, 1312287, 1640359, 2050449, 2563061, 3203826, 3902260, 4663553, 5493363, 
		6397855, 7383752, 8458379, 9629723, 10906488, 12298162, 13815086, 15468534, 17270791, 19235252, 21376515, 23710491, 
		26254525, 29027522, 32050088, 35344686, 38935798, 42850109, 47116709, 51767302, 56836449, 62361819, 68384473, 74949165, 
		82104680, 89904191, 98405658, 107672256, 117772849, 128782495, 140783010, 153863570, 168121381, 183662396, 200602101, 
		219066380, 239192444, 261129853, 285041630, 311105466, 339515048, 370481492, 404234916, 441026148, 481128591, 524840254, 
		572485967, 624419793, 681027665, 742730244, 809986056, 883294891, 963201521, 1050299747, 1145236814, 1248718217, 
		1361512946, 1484459201, 1618470619, 1764543065, 1923762030, 2097310703, 2286478756, 2492671933, 2717422497, 2962400612, 
		3229426756, 3520485254, 0};

//////////////////////////////////////////////////////////////////////
// Unit Affection ID Definition
//////////////////////////////////////////////////////////////////////
#define AFFECT_NONE                                                  0
#define AFFECT_FREEZE                                                1
#define AFFECT_POISON                                                2
#define AFFECT_RESISTFIRE                                            3
#define AFFECT_RESISTCOLD                                            4
#define AFFECT_RESISTLIGHT                                           5
#define AFFECT_RESISTMAGIC                                           6
#define AFFECT_PLAYERBODY                                            7
#define AFFECT_RESISTALL                                             8
#define AFFECT_AMPLIFYDAMAGE                                         9
#define AFFECT_FROZENARMOR                                           10
#define AFFECT_COLD                                                  11
#define AFFECT_INFERNO                                               12
#define AFFECT_BLAZE                                                 13
#define AFFECT_BONEARMOR                                             14
#define AFFECT_CONCENTRATE                                           15
#define AFFECT_ENCHANT                                               16
#define AFFECT_INNERSIGHT                                            17
#define AFFECT_SKILL_MOVE                                            18
#define AFFECT_WEAKEN                                                19
#define AFFECT_CHILLINGARMOR                                         20
#define AFFECT_STUNNED                                               21
#define AFFECT_SPIDERLAY                                             22
#define AFFECT_DIMVISION                                             23
#define AFFECT_SLOWED                                                24
#define AFFECT_FETISHAURA                                            25
#define AFFECT_SHOUT                                                 26
#define AFFECT_TAUNT                                                 27
#define AFFECT_CONVICTION                                            28
#define AFFECT_CONVICTED                                             29
#define AFFECT_ENERGYSHIELD                                          30
#define AFFECT_VENOMCLAWS                                            31
#define AFFECT_BATTLEORDERS                                          32
#define AFFECT_MIGHT                                                 33
#define AFFECT_PRAYER                                                34
#define AFFECT_HOLYFIRE                                              35
#define AFFECT_THORNS                                                36
#define AFFECT_DEFIANCE                                              37
#define AFFECT_THUNDERSTORM                                          38
#define AFFECT_LIGHTNINGBOLT                                         39
#define AFFECT_BLESSEDAIM                                            40
#define AFFECT_VIGOR	                                                41
#define AFFECT_CONCENTRATION                                         42
#define AFFECT_HOLYFREEZE                                            43
#define AFFECT_HOLYFREEZECHILL                                       44
#define AFFECT_CLEANSING                                             45
#define AFFECT_HOLYSHOCK                                             46
#define AFFECT_SANCTUARY                                             47
#define AFFECT_MEDITATION                                            48
#define AFFECT_FANATICISM                                            49
#define AFFECT_REDEMPTION                                            50
#define AFFECT_BATTLECOMMAND                                         51
#define AFFECT_PREVENTHEAL                                           52
#define AFFECT_CONVERSION                                            53
#define AFFECT_UNINTERRUPTABLE                                       54
#define AFFECT_IRONMAIDEN                                            55
#define AFFECT_TERROR                                                56
#define AFFECT_ATTRACT                                               57
#define AFFECT_LIFETAP                                               58
#define AFFECT_CONFUSE                                               59
#define AFFECT_DECREPIFY                                             60
#define AFFECT_LOWERRESIST                                           61
#define AFFECT_OPENWOUNDS                                            62
#define AFFECT_DOPPLEZON                                             63
#define AFFECT_CRITICALSTRIKE                                        64
#define AFFECT_DODGE                                                 65
#define AFFECT_AVOID                                                 66
#define AFFECT_PENETRATE                                             67
#define AFFECT_EVADE                                                 68
#define AFFECT_PIERCE                                                69
#define AFFECT_WARMTH                                                70
#define AFFECT_FIREMASTERY                                           71
#define AFFECT_LIGHTNINGMASTERY                                      72
#define AFFECT_COLDMASTERY                                           73
#define AFFECT_SWORDMASTERY                                          74
#define AFFECT_AXEMASTERY                                            75
#define AFFECT_MACEMASTERY                                           76
#define AFFECT_POLEARMMASTERY                                        77
#define AFFECT_THROWINGMASTERY                                       78
#define AFFECT_SPEARMASTERY                                          79
#define AFFECT_INCREASEDSTAMINA                                      80
#define AFFECT_IRONSKIN                                              81
#define AFFECT_INCREASEDSPEED                                        82
#define AFFECT_NATURALRESISTANCE                                     83
#define AFFECT_FINGERMAGECURSE                                       84
#define AFFECT_NOMANAREGEN                                           85
#define AFFECT_JUSTHIT                                               86
#define AFFECT_SLOWMISSILES                                          87
#define AFFECT_SHIVERARMOR                                           88
#define AFFECT_BATTLECRY                                             89
#define AFFECT_BLUE                                                  90
#define AFFECT_RED                                                   91
#define AFFECT_DEATH_DELAY                                           92
#define AFFECT_VALKYRIE                                              93
#define AFFECT_FRENZY                                                94
#define AFFECT_BERSERK                                               95
#define AFFECT_REVIVE                                                96
#define AFFECT_ITEMFULLSET                                           97
#define AFFECT_SOURCEUNIT                                            98
#define AFFECT_REDEEMED                                              99
#define AFFECT_HEALTHPOT                                             100
#define AFFECT_HOLYSHIELD                                            101
#define AFFECT_JUST_PORTALED                                         102
#define AFFECT_MONFRENZY                                             103
#define AFFECT_CORPSE_NODRAW                                         104
#define AFFECT_ALIGNMENT                                             105
#define AFFECT_MANAPOT                                               106
#define AFFECT_SHATTER                                               107
#define AFFECT_SYNC_WARPED                                           108
#define AFFECT_CONVERSION_SAVE                                       109
#define AFFECT_PREGNANT                                              110
#define AFFECT_111                                                   111
#define AFFECT_RABIES                                                112
#define AFFECT_DEFENSE_CURSE                                         113
#define AFFECT_BLOOD_MANA                                            114
#define AFFECT_BURNING                                               115
#define AFFECT_DRAGONFLIGHT                                          116
#define AFFECT_MAUL                                                  117
#define AFFECT_CORPSE_NOSELECT                                       118
#define AFFECT_SHADOWWARRIOR                                         119
#define AFFECT_FERALRAGE                                             120
#define AFFECT_SKILLDELAY                                            121
#define AFFECT_PROGRESSIVE_DAMAGE                                    122
#define AFFECT_PROGRESSIVE_STEAL                                     123
#define AFFECT_PROGRESSIVE_OTHER                                     124
#define AFFECT_PROGRESSIVE_FIRE                                      125
#define AFFECT_PROGRESSIVE_COLD                                      126
#define AFFECT_PROGRESSIVE_LIGHTNING                                 127
#define AFFECT_SHRINE_ARMOR                                          128
#define AFFECT_SHRINE_COMBAT                                         129
#define AFFECT_SHRINE_RESIST_LIGHTNING                               130
#define AFFECT_SHRINE_RESIST_FIRE                                    131
#define AFFECT_SHRINE_RESIST_COLD                                    132
#define AFFECT_SHRINE_RESIST_POISON                                  133
#define AFFECT_SHRINE_SKILL                                          134
#define AFFECT_SHRINE_MANA_REGEN                                     135
#define AFFECT_SHRINE_STAMINA                                        136
#define AFFECT_SHRINE_EXPERIENCE                                     137
#define AFFECT_FENRIS_RAGE                                           138
#define AFFECT_WOLF                                                  139
#define AFFECT_BEAR                                                  140
#define AFFECT_BLOODLUST                                             141
#define AFFECT_CHANGECLASS                                           142
#define AFFECT_ATTACHED                                              143
#define AFFECT_HURRICANE                                             144
#define AFFECT_ARMAGEDDON                                            145
#define AFFECT_INVIS                                                 146
#define AFFECT_BARBS                                                 147
#define AFFECT_WOLVERINE                                             148
#define AFFECT_OAKSAGE                                               149
#define AFFECT_VINE_BEAST                                            150
#define AFFECT_CYCLONEARMOR                                          151
#define AFFECT_CLAWMASTERY                                           152
#define AFFECT_CLOAK_OF_SHADOWS                                      153
#define AFFECT_RECYCLED                                              154
#define AFFECT_WEAPONBLOCK                                           155
#define AFFECT_CLOAKED                                               156
#define AFFECT_BURSTOFSPEED                                          157
#define AFFECT_BLADESHIELD                                           158
#define AFFECT_FADE                                                  159

void DrawOriginal(void)
{
	GameStructInfo *pInfo = D2CLIENT_GetGameInfo();
	BnetData *pInfo2 = *p_D2LAUNCH_BnData;
	UnitAny *pUnit = D2CLIENT_GetPlayerUnit ();
	wchar_t* pLocaleText;
 
	DWORD CurrentExpierences=D2COMMON_GetUnitStat((UnitAny*)*(DWORD*)0x6FBCC3D0,13,0)-CurrentExp;
	DWORD MaxExp=GetExpLeft()-D2COMMON_GetUnitStat((UnitAny*)*(DWORD*)0x6FBCC3D0,13,0);
	DWORD GamesLeft=0;
	
	char nLevelName[50];
	pLocaleText = D2LANG_GetLocaleText(AreaLocaleIds2[pUnit->pPath->pRoom1->pRoom2->pLevel->dwLevelNo]);
	WToC(pLocaleText, nLevelName);

	char nGame[15];
	pLocaleText = D2LANG_GetLocaleText(4181);
	WToC(pLocaleText, nGame);
	strcat_s(nGame, "%s");

	char nPass[15];
	pLocaleText = D2LANG_GetLocaleText(4182);
	WToC(pLocaleText, nPass);
	strcat_s(nPass, "%s");

	char nDiffName[25];
	pLocaleText = D2LANG_GetLocaleText(4183);
	WToC(pLocaleText, nDiffName);

	int DiffIds[] = {5156, 5155, 5154};
	char nDiff[25];
	pLocaleText = D2LANG_GetLocaleText(DiffIds[D2CLIENT_GetDifficulty()]);
	WToC(pLocaleText, nDiff);
	
	char szTime[200];
	int nTime = ((GetTickCount () - nGameTimer) / 1000);
	sprintf_s(szTime, 200, "%.2d:%.2d:%.2d", nTime/3600, (nTime/60)%60, nTime%60);

	char nExpPercent[50];
	int nLevel = D2COMMON_GetUnitStat(pUnit, 12, 0);
	unsigned long int nExp = D2COMMON_GetUnitStat(pUnit, 13, 0);
	int nExpPer = abs((float)((double)(nExp - nLevelExp[nLevel - 1]) / (double)(nLevelExp[nLevel] - nLevelExp[nLevel - 1])) * 100);
	int nExpDec1 = abs((float)((double)(nExp - nLevelExp[nLevel - 1]) / (double)(nLevelExp[nLevel] - nLevelExp[nLevel - 1])) * 1000);
	int nExpDec2 = (nExpDec1 - (nExpPer * 10));
	if(nExpPer <100)
	{
		if(nExpDec2 != 0) sprintf_s(nExpPercent, sizeof(nExpPercent), "%i.%i", nExpPer,nExpDec2);
		else sprintf_s(nExpPercent, sizeof(nExpPercent), "%i", nExpPer);
	}
	else
	{
		nExpPer=0;
		sprintf_s(nExpPercent, sizeof(nExpPercent), "%i", nExpPer);
	}
	
	char curTime[200];
	time_t ttTime;
	time(&ttTime);
	strftime(curTime, 100, "%m/%d/%Y",localtime(&ttTime));

	char curTime2[200];
	time(&ttTime);
	strftime(curTime2, 100, "%H:%M:%S",localtime(&ttTime));

	SYSTEMTIME T;
	GetLocalTime(&T);

	char CurrentTime[200]; char CurrentTime2[200];

	if(T.wHour == 0) sprintf(CurrentTime,"%.2d:%.2d:%.2d AM", T.wHour + 12, T.wMinute, T.wSecond);
	if(T.wHour >= 1 && T.wHour <= 11) sprintf(CurrentTime,"%.2d:%.2d:%.2d AM", T.wHour, T.wMinute, T.wSecond);
	if(T.wHour == 12) sprintf(CurrentTime,"%.2d:%.2d:%.2d PM", T.wHour, T.wMinute, T.wSecond);
	if(T.wHour >= 13 && T.wHour <= 23) sprintf(CurrentTime,"%.2d:%.2d:%.2d PM", T.wHour - 12, T.wMinute, T.wSecond);
	sprintf(CurrentTime2,"%d/%d/%d", T.wMonth, T.wDay, T.wYear);


	char ServerIP[200];	
	char* sip = ((char*)((DWORD)GetModuleHandle("D2Client.dll")+0xDFFB0));
	sprintf_s(ServerIP, 200, "%s",sip);

	char FPS[200];
	int fps = D2CLIENT_FPS;
	sprintf_s(FPS, 200, "%i", fps);

	char Ping[200];
	int ping = D2CLIENT_Ping;
	sprintf_s(Ping, 200, "%i",ping);

	char FPSPing[200];
	sprintf_s(FPSPing, 200, "%i FPS, Ping: %i", fps, ping);

	char GainedExp[200];
	DWORD gExp=0;
	if(D2COMMON_GetUnitStat((UnitAny*)*(DWORD*)0x6FBCC3D0,13,0)-CurrentExp!=NULL)
	gExp = D2COMMON_GetUnitStat((UnitAny*)*(DWORD*)0x6FBCC3D0,13,0)-CurrentExp;
	if(gExp != NULL) sprintf_s(GainedExp, 200, "%i",gExp);
	else sprintf_s(GainedExp, 200, "0",gExp);
	char* GainedExpFormat = FormatOutput(GainedExp);

	char RemainExp[200];
	int RExp = nLevelExp[nLevel] - nExp;
	if(nLevelExp[nLevel] != NULL) sprintf_s(RemainExp, sizeof(RemainExp), "%i", RExp);
	else sprintf_s(RemainExp, sizeof(RemainExp), "0", RExp);
	char* RemainExpFormat = FormatOutput(RemainExp);

	DWORD GamesLe=0;
	char GamesL[200];
	if(MaxExp!=NULL&&CurrentExpierences!=NULL)
	GamesLe=MaxExp/CurrentExpierences;
	if(CurrentExpierences=0) sprintf_s(GamesL, 200, "0");
	else sprintf_s(GamesL, 200, "%d",GamesLe);	
	char* RemainGameFormat = FormatOutput(GamesL);

	char Type[50];
	int C1=4;

	if(IsExpansion()) strcpy(Type,"EXPANSION");
	else strcpy(Type,"");

	AutomapInfo Automap[] = 
	{
		{nGame, pInfo->szGameName},
		{nPass, pInfo->szGamePassword},
		{"%s", nLevelName},
		{"v 1.12", "v 1.12"},
		{nDiffName, nDiff},
		{"%s", Type},
	};	
	AutomapInfo Automap2[] = 
	{
		{nGame, pInfo->szGameName},
		{nPass, pInfo->szGamePassword},
		{nDiffName, nDiff},
		{"%s", ServerIP},
		{"%s", nLevelName},
	};
	InfoBox Info[] = 
	{
		//{"Remaining Exp: %s", RemainExpFormat},
		//{"Gained Exp: %s", GainedExpFormat},
		//{"Games Left: %s", RemainGameFormat},
		//{"Total Exp: %s%%", nExpPercent},
		{"FPS: %s", FPS},
		//{"Skip: %i", *p_D2CLIENT_Skip},
		{"Ping: %s", Ping},
	};
	int yLen = 8;

	if(cfg.PlayerInfo && cfg.ShowInfoBox)
	{
		for (int i = 0; i < ArraySize(Automap2); i++)
		{
			if(strncmp(nDiff,"Normal",strlen("Normal")) == 0) strcpy(nDiff,"");

			if (strlen(Automap2[i].Data) == 0) continue;

			yLen += 16;

			TextHook(780, yLen, 4, false, 1, 0, Automap2[i].Message, Automap2[i].Data);
		}
	}
	else
	{
		for (int i = 0; i < ArraySize(Automap); i++)
		{
			if(strncmp(nDiff,"Normal",strlen("Normal")) == 0) strcpy(nDiff,"");

			if (strlen(Automap[i].Data) == 0) continue;

			yLen += 16;
			
			TextHook(780, yLen, 4, false, 1, 0, Automap[i].Message, Automap[i].Data);
		}
	}
	yLen=yLen+16;
	for (int i=0;i < ArraySize(Info);i++)
	{
		if (strlen(Info[i].Data) == 0) continue;

		yLen += 16;

		if(cfg.PlayerInfo && cfg.ShowInfoBox) TextHook(780, yLen, C1, false, 1, 0, Info[i].Message, Info[i].Data);
	}
	if(PrintExp)
	{
		PrintExp=false;

		Speak("Remaining Exp: %s", RemainExpFormat);
		Speak("Gained Exp: %s", GainedExpFormat);
		Speak("Games Left: %s", RemainGameFormat);
		Speak("Total Exp: %s%%", nExpPercent);
	}
}
char* FormatOutput(char * String)
{
	int	x,c,d,i;
	char Work[20];

	x = strlen(String)-1;

	for (i=1,c=x+(x/3)+1,d=x; c>0; --c,--d,++i)
	{
		if(i%4==0)
		{
			*(Work+(--c)) = ',';
			i=1;
		}
		*(Work+(c-1)) = *(String+d);
	}

	Work[x+(x/3)+1] = '\0';

	strcpy(String, Work);

	return String;
}

