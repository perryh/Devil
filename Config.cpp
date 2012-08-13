#include "DevilPK.h"
#define _CFGFILE_ "devilpk.cfg"
#define _CFGFILE2_ "screenhooks.cfg"
#define _CFGFILE3_ "bpmanager.cfg"
char cfgPath[259]={0};

tConfig cfg;
tBreakpoint bp;

int MakeParameter(char* szInput, char** argv, char splitchar, bool bSkipQuote);
char* GetRandomeMsg(char* tCharName, int tlevel);
char* GetConfigString(char* szSection, char* Item);
DWORD GetKeyConfig(char* szSection,char* Item);
BOOL GetBoolConfig(char* szSection,char* szItem);
char* GetRandomeKillMsg(char* tCharName);
int GetConfigInt(char* Section,char* szItem);

bool GetConfigEntry(char* cfgfile,char* Buffer,char* Section,char* szVar)
{
	char mypath[266]={0};
	char var[512],
	value[512],
	line[512],
	mszVar[512];
	sprintf_s(mypath,"%s\\%s",szModulePath,cfgfile);
	sprintf_s(mszVar,"%s[%s]",Section,szVar);
    FILE *fp = fopen(mypath, "r");

    if(fp)
	{
        while (fgets(line, sizeof(line), fp))
		{
			memset(var, 0, sizeof(var));
			memset(value, 0, sizeof(value));
			if (sscanf(line, "%[^ \t=]%*[\t ]=%*[\t ]%[^\n]", var, value) == 2)
			{
				if(!_strcmpi(mszVar,var))
				{
					strcpy(Buffer,value);
					Buffer[strlen(value)]='\0';
					return true;
				}
			}
		}
		fclose(fp);
	}
	strcpy(Buffer,'\0'); 
	return false;
}
char BufferStr[512]={0};

char* GetConfigStr(char* Section,char* szItem)
{
	GetConfigEntry(_CFGFILE_,BufferStr,Section,szItem);
	if(!BufferStr)
		return "";
	else
		return BufferStr;
}

bool getBool(char* Section, char* szItem)
{
	char Buf[10];
	GetConfigEntry(_CFGFILE_, Buf, Section, szItem);
	if ((_stricmp(Buf, "1") == 0) || (_stricmp(Buf, "y") == 0) || (_stricmp(Buf, "yes") == 0) || (_stricmp(Buf, "true") == 0))
		return true;
	return false;
}
bool getBool2(char* Section, char* szItem)
{
	char Buf[10];
	GetConfigEntry(_CFGFILE2_, Buf, Section, szItem);
	if ((_stricmp(Buf, "1") == 0) || (_stricmp(Buf, "y") == 0) || (_stricmp(Buf, "yes") == 0) || (_stricmp(Buf, "true") == 0))
		return true;
	return false;
}

bool getBool3(char* Section, char* szItem)
{
	char Buf[10];
	GetConfigEntry(_CFGFILE3_, Buf, Section, szItem);
	if ((_stricmp(Buf, "1") == 0) || (_stricmp(Buf, "y") == 0) || (_stricmp(Buf, "yes") == 0) || (_stricmp(Buf, "true") == 0))
		return true;
	return false;
}

int GetConfigInt(char* Section, char* szItem) 
{
	char Buf[10];
	GetConfigEntry(_CFGFILE_, Buf, Section, szItem);
	int szReturn = atoi(Buf);
	return szReturn;
}
int GetConfigInt2(char* Section, char* szItem) 
{
	char Buf[10];
	GetConfigEntry(_CFGFILE2_, Buf, Section, szItem);
	int szReturn = atoi(Buf);
	return szReturn;
}
int GetConfigInt3(char* Section, char* szItem) 
{
	char Buf[10];
	GetConfigEntry(_CFGFILE3_, Buf, Section, szItem);
	int szReturn = atoi(Buf);
	return szReturn;
}

DWORD GetKeyConfig(char* szSection,char* Item) 
{
	char mypath[300];
	char Buffer[300];
	GetConfigEntry(_CFGFILE_,Buffer,szSection,Item);

	if(!_strcmpi("~",Buffer)) return '~';
	if(!_strcmpi("\\",Buffer)) return '\\';
	if(!_strcmpi(";",Buffer)) return ';';
	if(!_strcmpi("`",Buffer)) return '`';
	if(!_strcmpi("´",Buffer)) return '´';
	if(!_strcmpi("'",Buffer)) return '\'';
	if(!_strcmpi("[",Buffer)) return '[';
	if(!_strcmpi("]",Buffer)) return ']';
	if(!_strcmpi("A",Buffer)) return 'A';
	if(!_strcmpi("B",Buffer)) return 'B';
	if(!_strcmpi("C",Buffer)) return 'C';
	if(!_strcmpi("D",Buffer)) return 'D';
	if(!_strcmpi("E",Buffer)) return 'E';
	if(!_strcmpi("F",Buffer)) return 'F';
	if(!_strcmpi("G",Buffer)) return 'G';
	if(!_strcmpi("H",Buffer)) return 'H';
	if(!_strcmpi("I",Buffer)) return 'I';
	if(!_strcmpi("J",Buffer)) return 'J';
	if(!_strcmpi("K",Buffer)) return 'K';
	if(!_strcmpi("L",Buffer)) return 'L';
	if(!_strcmpi("M",Buffer)) return 'M';
	if(!_strcmpi("N",Buffer)) return 'N';
	if(!_strcmpi("O",Buffer)) return 'O';
	if(!_strcmpi("P",Buffer)) return 'P';
	if(!_strcmpi("Q",Buffer)) return 'Q';
	if(!_strcmpi("R",Buffer)) return 'R';
	if(!_strcmpi("S",Buffer)) return 'S';
	if(!_strcmpi("T",Buffer)) return 'T';
	if(!_strcmpi("U",Buffer)) return 'U';
	if(!_strcmpi("V",Buffer)) return 'V';
	if(!_strcmpi("W",Buffer)) return 'W';
	if(!_strcmpi("X",Buffer)) return 'X';
	if(!_strcmpi("Y",Buffer)) return 'Y';
	if(!_strcmpi("Z",Buffer)) return 'Z';
	if(!_strcmpi("+",Buffer)) return '+';
	if(!_strcmpi("#",Buffer)) return '#';

	if(!_strcmpi("<",Buffer)) return '<';
	if(!_strcmpi(">",Buffer)) return '>';

	if(!_strcmpi("VK_0",Buffer)) return '0';
	if(!_strcmpi("VK_1",Buffer)) return '1';
	if(!_strcmpi("VK_2",Buffer)) return '2';
	if(!_strcmpi("VK_3",Buffer)) return '3';
	if(!_strcmpi("VK_4",Buffer)) return '4';
	if(!_strcmpi("VK_5",Buffer)) return '5';
	if(!_strcmpi("VK_6",Buffer)) return '6';
	if(!_strcmpi("VK_7",Buffer)) return '7';
	if(!_strcmpi("VK_8",Buffer)) return '8';
	if(!_strcmpi("VK_9",Buffer)) return '9';
	if(!_strcmpi("VK_NUMPAD0",Buffer)) return VK_NUMPAD0;
	if(!_strcmpi("VK_NUMPAD1",Buffer)) return VK_NUMPAD1;
	if(!_strcmpi("VK_NUMPAD2",Buffer)) return VK_NUMPAD2;
	if(!_strcmpi("VK_NUMPAD3",Buffer)) return VK_NUMPAD3;
	if(!_strcmpi("VK_NUMPAD4",Buffer)) return VK_NUMPAD4;
	if(!_strcmpi("VK_NUMPAD5",Buffer)) return VK_NUMPAD5;
	if(!_strcmpi("VK_NUMPAD6",Buffer)) return VK_NUMPAD6;
	if(!_strcmpi("VK_NUMPAD7",Buffer)) return VK_NUMPAD7;
	if(!_strcmpi("VK_NUMPAD8",Buffer)) return VK_NUMPAD8;
	if(!_strcmpi("VK_NUMPAD9",Buffer)) return VK_NUMPAD9;
	if(!_strcmpi("VK_F1",Buffer)) return VK_F1;
	if(!_strcmpi("VK_F2",Buffer)) return VK_F2;
	if(!_strcmpi("VK_F3",Buffer)) return VK_F3;
	if(!_strcmpi("VK_F4",Buffer)) return VK_F4;
	if(!_strcmpi("VK_F5",Buffer)) return VK_F5;
	if(!_strcmpi("VK_F6",Buffer)) return VK_F6;
	if(!_strcmpi("VK_F7",Buffer)) return VK_F7;
	if(!_strcmpi("VK_F8",Buffer)) return VK_F8;
	if(!_strcmpi("VK_F9",Buffer)) return VK_F9;
	if(!_strcmpi("VK_F10",Buffer)) return VK_F10;
	if(!_strcmpi("VK_F11",Buffer)) return VK_F11;
	if(!_strcmpi("VK_F12",Buffer)) return VK_F12;
	if(!_strcmpi("VK_HOME",Buffer)) return VK_HOME;
	if(!_strcmpi("VK_DELETE",Buffer)) return VK_DELETE;
	if(!_strcmpi("VK_PAGEDOWN",Buffer)) return VK_NEXT;
	if(!_strcmpi("VK_PAGEUP",Buffer)) return VK_PRIOR;
	if(!_strcmpi("VK_INSERT",Buffer)) return VK_INSERT;
	if(!_strcmpi("VK_END",Buffer)) return VK_END;
	if(!_strcmpi("VK_TAB",Buffer)) return VK_TAB;
	if(!_strcmpi("VK_SHIFT",Buffer)) return VK_SHIFT;
	if(!_strcmpi("VK_RETURN",Buffer)) return VK_RETURN;
	if(!_strcmpi("VK_CONTROL",Buffer)) return VK_CONTROL;
	if(!_strcmpi("VK_ESCAPE",Buffer)) return VK_ESCAPE;
	if(!_strcmpi("VK_SPACE",Buffer)) return VK_SPACE;
	if(!_strcmpi("VK_LEFT",Buffer)) return VK_LEFT;
	if(!_strcmpi("VK_UP",Buffer)) return VK_UP;
	if(!_strcmpi("VK_RIGHT",Buffer)) return VK_RIGHT;
	if(!_strcmpi("VK_DOWN",Buffer)) return VK_DOWN;
	if(!_strcmpi("VK_MULTIPLY",Buffer)) return VK_MULTIPLY;
	if(!_strcmpi("VK_ADD",Buffer)) return VK_ADD;
	if(!_strcmpi("VK_SUBTRACT",Buffer)) return VK_SUBTRACT;
	if(!_strcmpi("VK_DECIMAL",Buffer)) return VK_DECIMAL;
	if(!_strcmpi("VK_DIVIDE",Buffer)) return VK_DIVIDE;
	if(!_strcmpi("VK_ALT",Buffer)) return VK_MENU;
	if(!_strcmpi("VK_LMENU",Buffer)) return VK_LMENU;
	if(!_strcmpi("VK_RMENU",Buffer)) return VK_RMENU;
	if(!_strcmpi("VK_OEM_3",Buffer)) return VK_OEM_3;
	if(!_strcmpi("VK_PERIOD",Buffer)) return VK_OEM_PERIOD;

	if(!_strcmpi(".",Buffer)) return '.';
	if(!_strcmpi(",",Buffer)) return ',';

	return -1;
}

BOOL ReadConfig() 
{
	cfg.ChickenOnHostile=GetConfigInt("Chicken","Hostile");
	cfg.ChickenOnAim=GetConfigInt("Chicken","Aim");

	cfg.TownLifeChicken=GetConfigInt("Chicken","TownLifeChicken");
	cfg.TownManaChicken=GetConfigInt("Chicken","TownManaChicken");
	cfg.QuitLife=GetConfigInt("Chicken","QuitLife");
	cfg.QuitMana=GetConfigInt("Chicken","QuitMana");

	cfg.Drink=getBool("Chicken","Drink");

	cfg.DrinkLifeTimer=GetConfigInt("Chicken","DrinkLifeTimer");
	cfg.DrinkManaTimer=GetConfigInt("Chicken","DrinkManaTimer");
	cfg.DrinkRejuTimer=GetConfigInt("Chicken","DrinkRejuTimer");

	cfg.DrinkLife=GetConfigInt("Chicken","DrinkLife");
	cfg.DrinkMana=GetConfigInt("Chicken","DrinkMana");
    cfg.DrinkLifeRej=GetConfigInt("Chicken","DrinkLifeRej");
	cfg.DrinkManaRej=GetConfigInt("Chicken","DrinkManaRej");

	cfg.QuitOnJuvRunOut=getBool("Chicken","CheckSafeRejuv");
	cfg.QuitOnFailedTP=getBool("Chicken","CheckSafeTown");

	cfg.Trigger=GetKeyConfig("KeySettings","Trigger");
	cfg.FastTP=GetKeyConfig("KeySettings","FastTP");
	cfg.TPPK=GetKeyConfig("KeySettings","TPPK");
	cfg.MoveBox=GetKeyConfig("KeySettings","MoveBox");
	cfg.NextTarget=GetKeyConfig("KeySettings","NextTarget");
	cfg.Camp=GetKeyConfig("KeySettings","Camp");
	cfg.CampUnit=GetKeyConfig("KeySettings","CampUnit");
	cfg.ItemViewer=GetKeyConfig("KeySettings","ItemViewer");
	cfg.AimToggle=GetKeyConfig("KeySettings","AimToggle");
	cfg.AttackPlayer=GetKeyConfig("KeySettings","AttackPlayer");
	cfg.AimSlotToggle=GetKeyConfig("KeySettings","AimSlotToggle");
	cfg.BlindAAToggle=GetKeyConfig("KeySettings","BlindAAToggle");
    cfg.ADKey=GetKeyConfig("KeySettings","Spam");
    cfg.FlashKey=GetKeyConfig("KeySettings","Flash");
    cfg.SilentExit=GetKeyConfig("KeySettings","SilentExit");
    cfg.Hostile=GetKeyConfig("KeySettings","Hostile");
    cfg.FastExit=GetKeyConfig("KeySettings","FastExit");
    cfg.TeleToPlayer=GetKeyConfig("KeySettings","TeleToPlayer");
    cfg.TeleToPlayerHost=GetKeyConfig("KeySettings","TeleToPlayerHost");
    cfg.StashKey=GetKeyConfig("KeySettings","StashKey");
	
	cfg.Maphack=getBool("Maphack","RevealMap");
	cfg.MonsterColor=GetConfigInt("Maphack","MonsterColor");
	cfg.ChampionMonsterColor=GetConfigInt("Maphack","ChampionMonsterColor");
    cfg.DrawImunities=getBool("Maphack","DrawImunities");
	cfg.DrawMonsters=getBool("Maphack","DrawMonsters");

	cfg.DrawMissiles=getBool("Maphack","DrawMissiles");
    cfg.FriendMissile=GetConfigInt("Maphack","FriendMissile");
    cfg.NeutralMissile=GetConfigInt("Maphack","NeutralMissile");
    cfg.EnemyMissile=GetConfigInt("Maphack","EnemyMissile");
    cfg.MyMissile=GetConfigInt("Maphack","MyMissile");

    cfg.LevelNames=getBool("Maphack","DrawLevelNames");
    cfg.DrawVectors=getBool("Maphack","DrawVectors");
    cfg.PlayerLine=getBool("Maphack","DrawAimVector");

    cfg.NextColor=GetConfigInt("Vectors","NextColor");
    cfg.PrevColor=GetConfigInt("Vectors","LastColor");
    cfg.WaypointColor=GetConfigInt("Vectors","WPColor");
    cfg.SpecialColor=GetConfigInt("Vectors","SpecialColor");

	cfg.PlayerInfoToggle=GetKeyConfig("KeySettings","ScreenhooksToggle");
	cfg.PlayerInfo=getBool2("ScreenHooks","Toggled");

	cfg.IHPKTag=getBool2("ScreenHooks","ShowTag");
	cfg.ExtraInfo=getBool2("ScreenHooks","ShowExtraInfo");
	cfg.TimeStamp=getBool2("ScreenHooks","ShowTimeStamp");
	cfg.ShowInfoBox=getBool2("ScreenHooks","ShowGameInfo");
	cfg.ShowLifeManaPer=getBool2("ScreenHooks","ShowLifeManaPer");

	cfg.ShowTabsAlways=getBool2("ScreenHooks","ShowTabsAlways");
	cfg.ShowBoxCoordinates=getBool2("ScreenHooks","ShowBoxCoordinates");

	cfg.EnchBotToggle=GetKeyConfig("Enchbot","Toggle");
	strcpy(cfg.EnchMe,GetConfigStr("Enchbot","EnchMe"));
	strcpy(cfg.EnchMerc,GetConfigStr("Enchbot","EnchMerc"));
	strcpy(cfg.EnchAll,GetConfigStr("Enchbot","EnchAll"));
    cfg.PMOnJoin=getBool("Enchbot","PMOnJoin");
    cfg.AutoParty=getBool("Enchbot","Autoparty");
	
    cfg.PrintMessages=getBool("Messages","PrintMessages");
    cfg.PrintIHPKMessages=getBool("Messages","PrintDevilPKMessages");
    cfg.PrintCommands=getBool("Messages","PrintCommands");
	cfg.PrintOverhead=getBool("Messages","UseOverheadMessages");
    cfg.PrintJoinMessages=getBool("Messages","PrintJoinMessages");
    cfg.PrintTargetMessages=getBool("Messages","PrintTargetMessages");

	cfg.FastTele=getBool("Settings","FastTele");
	cfg.ItemLevel=getBool("Settings","ItemLevel");
    cfg.ItemSockets=getBool("Settings","ItemSockets");
    cfg.ItemEth=getBool("Settings","ItemEth");
	cfg.RemovePortalDelay=getBool("Settings","QuickPortalOpen");
	cfg.HostileTarget=getBool("Settings","HostileTargetOnly");
	cfg.AntiMinimize=getBool("Settings","AntiMinimize");
    cfg.FlashDelay=GetConfigInt("Settings","FlashDelay");
    cfg.PKMessage=getBool("Settings","MessageOnKill");
    cfg.BlindSpot=GetConfigInt("Settings","BlindSpot");
    cfg.CleanShot=getBool("Settings","CleanScreenshots");

    strcpy(cfg.ADMessage,GetConfigStr("Settings","SpamMessage"));
    strcpy(cfg.ADMessage2,GetConfigStr("Settings","SpamMessage2"));
    strcpy(cfg.ADMessage3,GetConfigStr("Settings","SpamMessage3"));
    strcpy(cfg.ADMessage4,GetConfigStr("Settings","SpamMessage4"));
    strcpy(cfg.ADMessage5,GetConfigStr("Settings","SpamMessage5"));
    strcpy(cfg.ADMessage6,GetConfigStr("Settings","SpamMessage6"));
    strcpy(cfg.ADMessage7,GetConfigStr("Settings","SpamMessage7"));
    strcpy(cfg.ADMessage8,GetConfigStr("Settings","SpamMessage8"));
    strcpy(cfg.ADMessage9,GetConfigStr("Settings","SpamMessage9"));
    strcpy(cfg.ADMessage10,GetConfigStr("Settings","SpamMessage10"));
    strcpy(cfg.ADMessage11,GetConfigStr("Settings","SpamMessage11"));
    strcpy(cfg.ADMessage12,GetConfigStr("Settings","SpamMessage12"));
    strcpy(cfg.ADMessage13,GetConfigStr("Settings","SpamMessage13"));
    strcpy(cfg.ADMessage14,GetConfigStr("Settings","SpamMessage14"));
    strcpy(cfg.ADMessage15,GetConfigStr("Settings","SpamMessage15"));
    strcpy(cfg.ADMessage16,GetConfigStr("Settings","SpamMessage16"));
    strcpy(cfg.ADMessage17,GetConfigStr("Settings","SpamMessage17"));
    strcpy(cfg.ADMessage18,GetConfigStr("Settings","SpamMessage18"));

	strcpy(cfg.Message,GetConfigStr("Settings","OnKillMessage"));
	strcpy(cfg.Message2,GetConfigStr("Settings","OnKillMessage2"));
	strcpy(cfg.Message3,GetConfigStr("Settings","OnKillMessage3"));
	strcpy(cfg.Message4,GetConfigStr("Settings","OnKillMessage4"));
	strcpy(cfg.Message5,GetConfigStr("Settings","OnKillMessage5"));
	strcpy(cfg.Message6,GetConfigStr("Settings","OnKillMessage6"));
	strcpy(cfg.Message7,GetConfigStr("Settings","OnKillMessage7"));
	strcpy(cfg.Message8,GetConfigStr("Settings","OnKillMessage8"));
	strcpy(cfg.Message9,GetConfigStr("Settings","OnKillMessage9"));
	strcpy(cfg.Message10,GetConfigStr("Settings","OnKillMessage10"));
	strcpy(cfg.Message11,GetConfigStr("Settings","OnKillMessage11"));
	strcpy(cfg.Message12,GetConfigStr("Settings","OnKillMessage12"));
	strcpy(cfg.Message13,GetConfigStr("Settings","OnKillMessage13"));
	strcpy(cfg.Message14,GetConfigStr("Settings","OnKillMessage14"));
	strcpy(cfg.Message15,GetConfigStr("Settings","OnKillMessage15"));
	strcpy(cfg.Message16,GetConfigStr("Settings","OnKillMessage16"));
	strcpy(cfg.Message17,GetConfigStr("Settings","OnKillMessage17"));
	strcpy(cfg.Message18,GetConfigStr("Settings","OnKillMessage18"));

	cfg.AimBoxEnabled=getBool2("AimBox","Enabled");
	cfg.AimBoxColor=GetConfigInt2("Aimbox","Color");

	cfg.NextLevelPath=GetKeyConfig("AutoTele","NextLevel");
	cfg.LastLevelPath=GetKeyConfig("AutoTele","LastLevel");
	cfg.WPPath=GetKeyConfig("AutoTele","WP");
	cfg.SpecialPath=GetKeyConfig("AutoTele","Special");

    cfg.WStop=GetKeyConfig("Winamp","Stop");
    cfg.WPlay=GetKeyConfig("Winamp","Play");
    cfg.WNext=GetKeyConfig("Winamp","Next");
    cfg.WPrev=GetKeyConfig("Winamp","Prev");
    cfg.WSong=GetKeyConfig("Winamp","PrintTitle");

//Config Errors

	if(cfg.BlindSpot <1 || cfg.BlindSpot>5) cfg.BlindSpot=1;
	if(cfg.TownLifeChicken < 0 || cfg.TownLifeChicken > 99) cfg.TownLifeChicken = 0;
	if(cfg.QuitLife < 0 || cfg.QuitLife > 99) cfg.QuitLife = 0;
	if(cfg.TownManaChicken < 0 || cfg.TownManaChicken > 99) cfg.TownManaChicken = 0;
	if(cfg.QuitMana < 0 || cfg.QuitMana > 99) cfg.QuitMana = 0;
	if(cfg.Drink < 0 || cfg.Drink > 1) cfg.Drink = 0;
	if(cfg.DrinkLife < 0 || cfg.DrinkLife >99) cfg.DrinkLife = 0;
	if(cfg.DrinkLifeRej < 0 || cfg.DrinkLifeRej >99) cfg.DrinkLifeRej = 0;
	if(cfg.DrinkMana < 0 || cfg.DrinkMana >99) cfg.DrinkMana = 0;
	if(cfg.DrinkManaRej < 0 || cfg.DrinkManaRej >99) cfg.DrinkManaRej = 0;

	if(cfg.ItemLevel) 
	{
		InstallItemlvl(); ItemLevel=true;
	}
	else UninstallItemlvl();

	return TRUE;
}

BOOL ReadConfig2() 
{

    cfg.DrinkBoxX=GetConfigInt2("BoxPosition","DrinkBoxX");
    cfg.DrinkBoxY=GetConfigInt2("BoxPosition","DrinkBoxY");
    cfg.TargetBoxX=GetConfigInt2("BoxPosition","TargetBoxX");
    cfg.TargetBoxY=GetConfigInt2("BoxPosition","TargetBoxY");
    cfg.ChickenBoxX=GetConfigInt2("BoxPosition","ChickenBoxX");
    cfg.ChickenBoxY=GetConfigInt2("BoxPosition","ChickenBoxY");
    cfg.StatBoxX=GetConfigInt2("BoxPosition","StatBoxX");
    cfg.StatBoxY=GetConfigInt2("BoxPosition","StatBoxY");
    cfg.AmpBoxX=GetConfigInt2("BoxPosition","WinampBoxX");
    cfg.AmpBoxY=GetConfigInt2("BoxPosition","WinampBoxY");

	if(cfg.PlayerInfo)
	{
		TargetToggled=true; DrinkToggled=true; ChickenToggled=true;
		StatToggled=true; WinampToggled=true;
	}
	if(!cfg.PlayerInfo)
	{
		TargetToggled=false; DrinkToggled=false; ChickenToggled=false;
		StatToggled=false; WinampToggled=false;
	}

	return TRUE;
}

BOOL ReadConfig3() 
{
	bp.FCR1=GetConfigInt3("Amazon","FCR");
	bp.FHR1=GetConfigInt3("Amazon","FHR");
	bp.FBR1=GetConfigInt3("Amazon","FBR");
	bp.IAS1=GetConfigInt3("Amazon","IAS");
	
	bp.FCR2=GetConfigInt3("Assassin","FCR");
	bp.FHR2=GetConfigInt3("Assassin","FHR");
	bp.FBR2=GetConfigInt3("Assassin","FBR");
	bp.IAS2=GetConfigInt3("Assassin","IAS");
	
	bp.FCR3=GetConfigInt3("Barbarian","FCR");
	bp.FHR3=GetConfigInt3("Barbarian","FHR");
	bp.FBR3=GetConfigInt3("Barbarian","FBR");
	bp.IAS3=GetConfigInt3("Barbarian","IAS");
	
	bp.FCR4=GetConfigInt3("Druid","FCR");
	bp.FHR4=GetConfigInt3("Druid","FHR");
	bp.FBR4=GetConfigInt3("Druid","FBR");
	bp.IAS4=GetConfigInt3("Druid","IAS");
	
	bp.FCR5=GetConfigInt3("Necromancer","FCR");
	bp.FHR5=GetConfigInt3("Necromancer","FHR");
	bp.FBR5=GetConfigInt3("Necromancer","FBR");
	bp.IAS5=GetConfigInt3("Necromancer","IAS");
	
	bp.FCR6=GetConfigInt3("Paladin","FCR");
	bp.FHR6=GetConfigInt3("Paladin","FHR");
	bp.FBR6=GetConfigInt3("Paladin","FBR");
	bp.IAS6=GetConfigInt3("Paladin","IAS");
	
	bp.FCR7=GetConfigInt3("Sorceress","FCR");
	bp.FHR7=GetConfigInt3("Sorceress","FHR");
	bp.FBR7=GetConfigInt3("Sorceress","FBR");
	bp.IAS7=GetConfigInt3("Sorceress","IAS");

	return TRUE;
}