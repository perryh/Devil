#define WIN32_LEAN_AND_MEAN
#define _WIN32_WINNT 0x0500

#define ArraySize(x) (sizeof(x) / sizeof(x[0]))
#define _CRT_SECURE_NO_DEPRECATE
extern char szModulePath[259];

#include <windows.h>
#include <wininet.h>
#include <time.h>
#include <stdio.h>
#include <ctime>
#include <Winbase.h>
#include <stdlib.h>
#include <limits.h>
#include <stdio.h>
#include <tlhelp32.h>
#include <tchar.h>
#include <shlwapi.h>
#include <ctime>
#include <math.h>
#include <direct.h>
#include <stdlib.h>
#include <errno.h>
#include <io.h>
#include <string.h>
//Header Files
#include "D2Ptrs.h"
#include "D2Structs.h"
#include "Constants.h"
#include "Intercepts.h"
#include "Winamp.h"
#include "asm.h"
#include "Area.h"
#include "ArrayEx.h"

#include "AutoAim.h"
#include "Autoparty.h"
#include "BoxHook.h"
#include "Chicken.h"
#include "CMapIncludes.h"
#include "Common.h"
#include "Config.h"
#include "D2Helpers.h"
#include "DrawHook.h"
#include "Extra.h"
#include "InfoBox.h"
#include "ItemLevel.h"
#include "ItemViewer.h"
#include "KeyHook.h"
#include "LinkedList.h"
#include "Maphack.h"
#include "Matrix.h"
#include "Monsters.h"
#include "Offset.h"
#include "PathFinder.h"
#include "ReceivePacket.h"
#include "SendPacket.h"
#include "Skill.h"
#include "Team.h"
#include "Timer.h"
#include "Vars.h"


#define CToW(szString, wString)				(MultiByteToWideChar(CP_ACP, MB_PRECOMPOSED, szString, (int)strlen(szString), wString, (int)strlen(szString)+1))
#define	WToC(wString, szString)				(WideCharToMultiByte(CP_ACP, 0, wString, -1, szString, (int)sizeof(szString), 0, 0));


#define FONTCOLOR_WHITE		0
#define FONTCOLOR_RED		1
#define FONTCOLOR_GREEN		2
#define FONTCOLOR_BLUE		3
#define FONTCOLOR_GOLD		4
#define FONTCOLOR_GREY		5
#define FONTCOLOR_BLACK		6
#define FONTCOLOR_BROWN		7
#define FONTCOLOR_ORANGE	8
#define FONTCOLOR_YELLOW	9
#define FONTCOLOR_PURPLE	10

extern AutoAim Auto;
extern LinkedList* PlayerFriendList;
extern LinkedList* PlayerEnemyList;
extern LinkedList* PlayerHCPKList;
extern LinkedList* PlayerIHPKList;
extern LinkedList* EnchList;
