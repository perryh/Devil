extern DWORD TimeOn;
extern DWORD BookTimer;
extern bool Units;
extern bool WelcomedOnce;
void GameDraw();
void GameDraw2();
void DrawConsole();
void DrawUIVars();
void DrawAutomapInfos();
void ScreenHooks();
void RevealActOnce();
void DrawMonsters();
void DrawPos();
void DrawPlines();
void DrawYonTarget();
void AutoTeleDraw();
void LifeManaPercents();
void PlayerInfo();
void VectorsDraw();
void EnumObjects();
void DrawAbsAboveTarget();
DWORD __fastcall D2CLIENT_GetUnitName_STUB(DWORD UnitAny);
VOID ScreenToAutomap(POINT *ptPos, int x, int y);
VOID DrawCross(INT nX, INT nY, DWORD dwColor, BOOL Automap);
void TextHook(INT xPos, INT yPos, DWORD dwColor, BOOL Automap, INT dwFont, BOOL dwCenter, LPSTR Text,...);
void BoxHook(INT x, INT y, INT xSize, INT ySize, DWORD dwColor, DWORD Trans, BOOL Automap);
void TestDraw(void);
void MiniMapCell(int xpos, int ypos, int actnum,int lvlnum, int fileno, long rx, long ry,DWORD ObjID);

void DrawPlayerBlob(int xpos, int ypos,int col);

Level* GetUnitLevel(UnitAny* pUnit);
VOID DrawVectorArrows();
VOID GetPlayerPosition(LPPOINT ptPlayer);
BOOL IsScreenClear(INT nScreen);
VOID GetPlayerPosition2(LPPOINT ptPlayer);
VOID ScreenToAutomapRelative2(LPPOINT ptPos, INT x, INT y);
VOID GetVectorArrows();
INT D2GetScreenSizeX();
INT D2GetScreenSizeY();
Level* GetLevelPointerD(ActMisc *pActMisc, int nLevel);
typedef struct VectorTarget_t
{
	POINT ptPos;
	INT nType;
	DWORD dwTarget;
	DWORD dwTargetType;
} VECTOR, *LPVECTOR;


struct Vector {
POINT WPPos;
POINT OtherPos;
POINT QuestPos;
POINT SpecialPos;


DWORD WPID;
DWORD OtherID;
DWORD QuestID;
DWORD SpecialID;

};
extern Vector GlobalVectors;