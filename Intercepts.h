#define FindUnit D2CLIENT_GetUnitFromId_STUB
void OnGamePacketReceived_STUB();
void SendPacketIntercept_STUB();
void PlayerJoinMsgPatch_ASM();

extern DWORD BreakItUp;
extern DWORD DontBreak;
void ReceivePacketIntercept_STUB();
void OnGameMouseEvent_STUB();
void KeyHookIntercept_STUB();
void DrawIntercept_STUB();
LONG WINAPI GameWindowEvent(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
extern DWORD DrawCall;
void GameLightRadius_STUB();
void GameFailToJoin_STUB();
void GameDraw_STUB();
void DrawEnteringLevelText_STUB();
void DrawManaOrb_STUB();
void DrawStamina_STUB();
void DrawStaminaA_STUB();
void GameDrawAutomapInfo_STUB();


void PlayerMapIntercept();
void PlayerBlobIntercept();
void PlayerPatch();

BOOL MaxAmazon();
BOOL MaxAssassin();
BOOL MaxBarbarian();
BOOL MaxDruid();
BOOL MaxNecromancer(); 
BOOL MaxPaladin();   
BOOL MaxSorceress();

