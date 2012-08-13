typedef bool (_stdcall *fpp)(PresetUnit* pUnit);
BOOL GetPositionByClassID(DWORD ID,POINT* p);
class CTele {
private:
	CHAR PathList[250][250];
	DWORD PathSize;

	DWORD CheckVaildObject(CHAR* List);
public:
	BOOL DefinePathList(char* List);
	BOOL StartTeleport();
	BOOL Teleport(long x,long y);
};