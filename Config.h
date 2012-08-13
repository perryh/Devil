struct tConfig {
	//chicken
	int DrinkLifeTimer;
	int DrinkManaTimer;
	int DrinkRejuTimer;
	bool Drink;
	int DrinkLife;
	int DrinkMana;
	int DrinkLifeRej;
	int DrinkManaRej;
	int TownLifeChicken;
	int QuitLife;
	int TownManaChicken;
	int QuitMana;
	int ChickenOnHostile;
	int ChickenOnAim;
	bool QuitOnFailedTP;
	bool QuitOnJuvRunOut;
	//enchbot
    byte EnchBotToggle;
    char EnchMe[512];
    char EnchMerc[512];
    char EnchAll[512];
    bool AutoParty;
    bool PMOnJoin;
	//settings
	bool AntiMinimize;
    bool FastTele;
    bool ItemLevel;
    bool ItemSockets;
    bool ItemEth;
    bool InviteMembers;
    bool LootMembers;
	bool CleanShot;
	bool ScreenshotPKs;
	int BlindSpot;
    int FlashDelay;
    int LogPKsOver;
	bool RemovePortalDelay;
	bool HostileTarget;
	//playerlists
    bool GetFriends;
    bool GetEnemys;
    bool GetIHPK;
	//messages
    bool PrintMessages;
	bool PrintOverhead;
	bool PrintJoinMessages;
	bool PrintTargetMessages;
	bool PrintIHPKMessages;
	bool PrintCommands;
	//key settings
    byte Trigger;
    byte FastTP;
    byte TPPK;
    byte NextTarget;
    byte Camp;
    byte CampUnit;
    byte PlayerInfoToggle;
    byte MoveBox;
    byte ItemViewer;
    byte TeleToPlayerHost;
    byte TeleToPlayer;
    byte FastExit;
    byte Hostile;
    byte SilentExit;
    byte AimToggle;
    byte AttackPlayer;
    byte AimSlotToggle;
	byte BlindAAToggle;
    byte LastLevelPath;
    byte NextLevelPath;
    byte SpecialPath;
    byte WPPath;
    byte StashKey;
    byte TargetInfo;
    byte FlashKey;
	//aim box
    bool AimBoxEnabled;
    int AimBoxColor;
	//maphack
	bool Maphack;
	bool LevelNames;
    bool DrawMonsters;
    bool DrawImunities;
    bool DrawMissiles;
	bool DrawVectors;
	bool PlayerLine;
    int MonsterColor;
    int ChampionMonsterColor;
    int MyMissile;
    int FriendMissile;
    int NeutralMissile;
    int EnemyMissile;
	//vector colors	
	int NextColor;
	int PrevColor;
	int WaypointColor;
	int SpecialColor;
	//AD
    char ADMessage[5120];
    char ADMessage2[5120];
    char ADMessage3[5120];
    char ADMessage4[5120];
    char ADMessage5[5120];
    char ADMessage6[5120];
    char ADMessage7[5120];
    char ADMessage8[5120];
    char ADMessage9[5120];
    char ADMessage10[5120];
    char ADMessage11[5120];
    char ADMessage12[5120];
    char ADMessage13[5120];
    char ADMessage14[5120];
    char ADMessage15[5120];
    char ADMessage16[5120];
    char ADMessage17[5120];
    char ADMessage18[5120];
    byte ADKey;
	//death message
    int PKMessage;
    char Message[512];
    char Message2[512];
    char Message3[512];
    char Message4[512];
    char Message5[512];
    char Message6[512];
    char Message7[512];
    char Message8[512];
    char Message9[512];
    char Message10[512];
    char Message11[512];
    char Message12[512];
    char Message13[512];
    char Message14[512];
    char Message15[512];
    char Message16[512];
    char Message17[512];
    char Message18[512];
	//winamp
    BYTE WNext;
    BYTE WPrev;
    BYTE WSong;
    BYTE WPlay;
    BYTE WStop;
	//screenHooks
	bool PlayerInfo;
	bool MoveBoxes;

	bool ShowInfoBox;
	bool TimeStamp;
	bool IHPKTag;
	bool ExtraInfo;
	bool ShowLifeManaPer;

	int DrinkBoxX;
	int DrinkBoxY;
	int TargetBoxX;
	int TargetBoxY;
	int ChickenBoxX;
	int ChickenBoxY;
	int PlayerBoxX;
	int PlayerBoxY;
	int StatBoxX;
	int StatBoxY;
	int AmpBoxX;
	int AmpBoxY;

	int oldMouseX;
	int oldMouseY;
	int oldBoxX;
	int oldBoxY;

	int oldMouse2X;
	int oldMouse2Y;
	int oldBox2X;
	int oldBox2Y;

	int oldMouse3X;
	int oldMouse3Y;
	int oldBox3X;
	int oldBox3Y;

	int oldMouse4X;
	int oldMouse4Y;
	int oldBox4X;
	int oldBox4Y;

	int oldMouse5X;
	int oldMouse5Y;
	int oldBox5X;
	int oldBox5Y;

	int oldMouse6X;
	int oldMouse6Y;
	int oldBox6X;
	int oldBox6Y;

	int TargetX;
	int TargetY;

	bool ShowBoxCoordinates;
	bool ShowTabsAlways;

	int RealTombX;
	int ScreenShotTimer;
};
struct tBreakpoint{

	//Create Missile



	//Amazon
    int FCR1;
    int FHR1;
    int FBR1;
    int IAS1;

	//Assassin
    int FCR2;
    int FHR2;
    int FBR2;
    int IAS2;

	//Barbarian
    int FCR3;
    int FHR3;
    int FBR3;
    int IAS3;

	//Druid
    int FCR4;
    int FHR4;
    int FBR4;
    int IAS4;

	//Necromancer
    int FCR5;
    int FHR5;
    int FBR5;
    int IAS5;

	//Paladin
    int FCR6;
    int FHR6;
    int FBR6;
    int IAS6;

	//Sorceress
    int FCR7;
    int FHR7;
    int FBR7;
    int IAS7;
};

extern tConfig cfg;
extern tBreakpoint bp;
BOOL ReadConfig();
BOOL ReadConfig2();
BOOL ReadConfig3();