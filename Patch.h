PatchHook pHooks[] = {
	{PatchJmp, GetDllOffset("D2Client.dll", 0x40609), (DWORD)GameDrawAutomapInfo_STUB, 5},
	{PatchJmp, GetDllOffset("D2Client.dll", 0x90524), (DWORD)GameDraw_STUB, 6},
	{PatchCall, GetDllOffset("D2CLIENT.dll", 0x90211), (DWORD)DrawEnteringLevelText_STUB, 5},
	{PatchCall, GetDllOffset("D2CLIENT.dll", 0x836FE), (DWORD)DrawManaOrb_STUB, 5},
	{PatchCall, GetDllOffset("D2CLIENT.dll", 0x9035F), (DWORD)DrawStamina_STUB, 5},
	{PatchCall, GetDllOffset("D2CLIENT.dll", 0x90358), (DWORD)DrawStaminaA_STUB, 5},
	{PatchCall, GetDllOffset("D2Client.dll", 0x9F7A5), (DWORD)KeyHookIntercept_STUB, 7},
	{PatchCall, GetDllOffset("D2Client.dll", 0x5F8F7),(DWORD)GameLightRadius_STUB, 5},
	{PatchJmp, GetDllOffset("D2Client.dll", 0xD21C), (DWORD)SendPacketIntercept_STUB, 6},
    {PatchCall, GetDllOffset("D2Client.dll", 0x65111),(DWORD)ReceivePacketIntercept_STUB, 5},
	{PatchCall, GetDllOffset("D2Client.dll", 0xBB5B6), (DWORD)GameShake1_STUB, 6},
	{PatchCall, GetDllOffset("D2Client.dll", 0x7CA82), (DWORD)GameShake, 5},
	//{PatchCall, GetDllOffset("D2Client.dll", 0x3FC1E),(DWORD)PlayerMapIntercept, 5},
	{PatchCall, GetDllOffset("D2Client.dll", 0x3F69D),(DWORD)PlayerBlobIntercept, 6},
    {PatchJmp, GetDllOffset("D2Client.dll",  0x5CEB7), (DWORD)PlayerPatch, 15},
	{PatchCall, GetDllOffset("D2Client.dll", 0x7BB5E), (DWORD)GameFailToJoin_STUB, 6},
    {PatchCall, GetDllOffset("D2Multi.dll", 0x1463B), (DWORD)NextGameNamePatch, 5},
	{PatchCall, GetDllOffset("D2Multi.dll", 0x14676), (DWORD)NextGamePasswordPatch, 5},
	{PatchCall, GetDllOffset("D2Multi.dll", 0x14959), (DWORD)NextGameNamePatch, 5},
    {PatchCall, GetDllOffset("D2Multi.dll", 0x14994), (DWORD)NextGamePasswordPatch, 5},
    {PatchBytes, GetDllOffset("D2Client.dll", 0x58EF4),0xEB, 1},
};