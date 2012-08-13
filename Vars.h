#ifdef _VARS

#define DEFINEVAR(type, name)		type name;
CArrayEx<LevelNameInfo*, LevelNameInfo*> LevelNames;
DEFINEVAR(CHAR, szLastGameName[1024])

#else

#define DEFINEVAR(type, name)		extern type name;
extern CArrayEx<LevelNameInfo*, LevelNameInfo*> LevelNames;

#endif

#undef _VARS

DEFINEVAR(CHAR, szOrigWinName[1024])
DEFINEVAR(WNDPROC,OldWNDPROC)

#ifdef _DEFINE_VARS

#define MYVAR(type, name)			type v##_##name;
#define MYCARRAY(type, name)		CArrayEx<type, type> v_##name;
#define MYTOGGLE(name)				BOOL v_##name; INT vK_##name;
#define MYKEY(name)					INT vK_##name;

#else

#define MYVAR(d1, v1)				extern d1 v_##v1;
#define MYCARRAY(type, name)		extern CArrayEx<type, type> v_##name;
#define MYTOGGLE(name)				extern BOOL v_##name; extern INT vK_##name;
#define MYKEY(name)					extern INT vK_##name;

#endif

MYVAR(CMap *, GlobalMap)
MYVAR(LPVECTOR, CurrentVector)
MYVAR(BOOL, GameInit)
MYVAR(DWORD, BoTimer)
MYVAR(DWORD, OakTimer)
MYVAR(BOOL, AntiTppkBusy)

MYCARRAY(LPVECTOR, CurrentVectors)
MYCARRAY(POINT, TeleportQueue)

#undef MYVAR
#undef MYCARRAY
#undef MYTOGGLE
#undef MYKEY