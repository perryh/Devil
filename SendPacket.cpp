#include "DevilPK.h"
#include <iostream>
#include <fstream>
using namespace std;

DWORD AA,LeftAA;

bool AddSpam(char *Name);

bool InputMessage(char** Msg, int argc) 
{
	if(!strcmpi(Msg[0],"exp")) 
	{
		Speak("?exp");
		PrintExp=true;
		return true;
	}
	if(!strcmpi(Msg[0],"help")) 
	{
		PrintString("ÿc2:: ÿc4COMMANDS");
		PrintString(".AimBox <on/off>");
		PrintString(".CleanShot <on/off>");
		PrintString(".DeathMessage <on/off>");
		PrintString(".Enchant <on/off>");
		PrintString(".Messages <on/off>");
		PrintString(".Speed <on/off>");
		PrintString(".AddSpammer <char name>");
		PrintString(".Blind <1-5>");
		PrintString(".CheckSafe");
		PrintString(".Chicken");
		PrintString(".Maphooks");
		PrintString(".Reload");
		PrintString(".Screenhooks");
		return true;
	}
	if(!strcmpi(Msg[0], "chicken") && argc == 1)
	{
		PrintString("ÿc2:: ÿc4CHICKEN COMMANDS");
		PrintString(".Drink <on/off>");
		PrintString(".Drink Life <%%>");
		PrintString(".Drink Mana <%%>");
		PrintString(".Drink LifeRej <%%>");
		PrintString(".Drink ManaRej <%%>");
		PrintString(".Town Life <%%>");
		PrintString(".Town Mana <%%>");
		PrintString(".Quit Life <%%>");
		PrintString(".Quit Mana <%%>");
		PrintString(".On Aim <0-4>");
		PrintString(".On Host <0-4>");
		return true;
	}
	if((!strcmpi(Msg[0], "drink")) && argc == 1)
	{
		PrintString("ÿc2:: ÿc4DRINK COMMANDS");
		PrintString(".Drink <on/off>");
		PrintString(".Drink Life <%%>");
		PrintString(".Drink Mana <%%>");
		PrintString(".Drink LifeRej <%%>");
		PrintString(".Drink ManaRej <%%>");
		return true;
	}
	if(!strcmpi(Msg[0], "town") && argc == 1)
	{
		PrintString("ÿc2:: ÿc4CHICKEN TOWN COMMANDS");
		PrintString(".Town Life <%%>");
		PrintString(".Town Mana <%%>");
		return true;
	}
	if(!strcmpi(Msg[0], "quit") && argc == 1)
	{

		PrintString("ÿc2:: ÿc4CHICKEN QUIT COMMANDS");
		PrintString(".Quit Life <%%>");
		PrintString(".Quit Mana <%%>");
		return true;		
	}
	if(!strcmpi(Msg[0], "CheckSafe") && argc == 1)
	{

		PrintString("ÿc2:: ÿc4CHECKSAFE COMMANDS");
		PrintString(".CheckSafe Rejuv  <on/off>");
		PrintString(".CheckSafe Town <on/off>");
		return true;		
	}
	if(!strcmpi(Msg[0], "maphooks") && argc == 1) 
	{
		PrintString("ÿc2:: ÿc4MAPHOOKS COMMANDS");
		PrintString(".Maphooks <on/off>");
		PrintString(".AimVector <on/off>");
		PrintString(".Missiles <on/off>");
		PrintString(".Monsters <on/off>");
		PrintString(".Vectors <on/off>");
		return true;
	}
	if(!strcmpi(Msg[0], "screenhooks") && argc == 1) 
	{
		PrintString("ÿc2:: ÿc4SCREENHOOKS COMMANDS");
		PrintString(".Extra <on/off>");
		PrintString(".Tag <on/off>");
		PrintString(".Info <on/off>");
		PrintString(".Orbs <on/off>");
		PrintString(".TimeStamp <on/off>");
		return true;
	}
	if((!strcmpi(Msg[0], "drink")) && (!strcmpi(Msg[1], "life")) && argc == 2)
	{
		if(cfg.PrintCommands)
		{
			PrintString("ÿc1::ÿc0 Syntax is .Drink Life <%%>");
		}
		return true;
	}
	if((!strcmpi(Msg[0], "drink")) && (!strcmpi(Msg[1], "mana")) && argc == 2)
	{
		if(cfg.PrintCommands)
		{
			PrintString("ÿc1::ÿc0 Syntax is .Drink Mana <%%>");
		}
		return true;
	}
	if((!strcmpi(Msg[0], "drink")) && (!strcmpi(Msg[1], "liferej")) && argc == 2)
	{
		if(cfg.PrintCommands)
		{
			PrintString("ÿc1::ÿc0 Syntax is .Drink LifeRej <%%>");
		}
		return true;
	}
	if((!strcmpi(Msg[0], "drink")) && (!strcmpi(Msg[1], "mana")) && argc == 2)
	{
		if(cfg.PrintCommands)
		{
			PrintString("ÿc1::ÿc0 Syntax is .Drink ManaRej <%%>");
		}
		return true;
	}
	if((!strcmpi(Msg[0], "town")) && (!strcmpi(Msg[1], "life")) && argc == 2)
	{
		if(cfg.PrintCommands)
		{
			PrintString("ÿc1::ÿc0 Syntax is .Town Life <%%>");
		}
		return true;
	}
	if((!strcmpi(Msg[0], "town")) && (!strcmpi(Msg[1], "mana")) && argc == 2)
	{
		if(cfg.PrintCommands)
		{
			PrintString("ÿc1::ÿc0 Syntax is .Town Mana <%%>",0);
		}
		return true;
	}
	if((!strcmpi(Msg[0], "quit")) && (!strcmpi(Msg[1], "life")) && argc == 2)
	{
		if(cfg.PrintCommands)
		{
			PrintString("ÿc1::ÿc0 Syntax is .Quit Life <%%>");
		}
		return true;
	}
	if((!strcmpi(Msg[0], "quit")) && (!strcmpi(Msg[1], "mana")) && argc == 2)
	{
		if(cfg.PrintCommands)
		{
			PrintString("ÿc1::ÿc0 Syntax is .Quit Mana <%%>");
		}
		return true;
	}
	if(!strcmpi(Msg[0], "on") && (!strcmpi(Msg[1], "host") && argc == 2)) 
	{
		if(cfg.PrintCommands)
		{
			PrintString("ÿc1::ÿc0 Syntax is .On Host <0-4>");
		}
		return true;
	}
	if(!strcmpi(Msg[0], "on") && (!strcmpi(Msg[1], "aim") && argc == 2)) 
	{
		if(cfg.PrintCommands)
		{
			PrintString("ÿc1::ÿc0 Syntax is .On Aim <0-4>");
		}
		return true;
	}
	if(!strcmpi(Msg[0], "overhead") && argc == 1) 
	{
		if(cfg.PrintCommands)
		{
			PrintString("ÿc1::ÿc0 Syntax is .Overhead <on/off>");
		}
		return true;
	}
	if(!strcmpi(Msg[0], "invitemembers") && argc == 1) 
	{
		if(cfg.PrintCommands)
		{
			PrintString("ÿc1::ÿc0 Syntax is .InviteMembers <on/off>");
		}
		return true;
	}
	if(!strcmpi(Msg[0], "cleanshot") && argc == 1) 
	{
		if(cfg.PrintCommands)
		{
			PrintString("ÿc1::ÿc0 Syntax is .CleanShot <on/off>");
		}
		return true;
	}
	if(!strcmpi(Msg[0], "lootmembers") && argc == 1) 
	{
		if(cfg.PrintCommands)
		{
			PrintString("ÿc1::ÿc0 Syntax is .LootMembers <on/off>");
		}
		return true;
	}
	if(!strcmpi(Msg[0], "monsters") && argc == 1) 
	{
		if(cfg.PrintCommands)
		{
			PrintString("ÿc1::ÿc0 Syntax is .Monsters <on/off>");
		}
		return true;
	}
	if(!strcmpi(Msg[0], "vectors") && argc == 1) 
	{
		if(cfg.PrintCommands)
		{
			PrintString("ÿc1::ÿc0 Syntax is .Vectors <on/off>");
		}
		return true;
	}
	if(!strcmpi(Msg[0], "missiles") && argc == 1) 
	{
		if(cfg.PrintCommands)
		{
			PrintString("ÿc1::ÿc0 Syntax is .Missiles <on/off>");
		}
		return true;
	}
	if(!strcmpi(Msg[0],"aimbox") && argc == 1) 
	{
		if(cfg.PrintCommands)
		{
			PrintString("ÿc1::ÿc0 Syntax is .AimBox <on/off>");
		}
		return true;
	}
	if(!strcmpi(Msg[0],"DeathMessage") && argc == 1) 
	{
		if(cfg.PrintCommands)
		{
			PrintString("ÿc1::ÿc0 Syntax is .DeathMessage <on/off>");
		}
		return true;
	}
	if(!strcmpi(Msg[0], "enchant") && argc == 1) 
	{
		if(cfg.PrintCommands)
		{
			PrintString("ÿc1::ÿc0 Syntax is .Enchant <on/off>");
		}
		return true;
	}
	if(!strcmpi(Msg[0], "orbs") && argc == 1) 
	{
		if(cfg.PrintCommands)
		{
			PrintString("ÿc1::ÿc0 Syntax is .Orbs <on/off>");
		}
		return true;
	}
	if(!strcmpi(Msg[0], "info") && argc == 1)  
	{
		if(cfg.PrintCommands)
		{
			PrintString("ÿc1::ÿc0 Syntax is .Info <on/off>");
		}
		return true;
	}
	if(!strcmpi(Msg[0], "addspammer") && argc == 1) 
	{
		if(cfg.PrintCommands)
		{
			PrintString("ÿc1::ÿc0 Syntax is .AddSpammer <char name>");
		}
		return true;
	}
	//reload
	if(!strcmpi(Msg[0], "reload"))
	{
		ReadConfig();	
			
		if(cfg.PrintCommands)
		{
			PrintString("ÿc2:: ÿc0Reloaded Config");
		}
		return true;
	}
	if(!strcmpi(Msg[0], "drink"))
	{
		if(!strcmpi(Msg[1], "on"))
		{
			if(!cfg.Drink) 
			{
				if(cfg.PrintCommands)
				{
					PrintString("ÿc2::ÿc0 Auto Potion Enabled");
				}
				cfg.Drink = 1;
				return true;
			}
			else if(cfg.Drink) 
			{
				return true;
			}
		}
		else if(!strcmpi(Msg[1], "off"))
		{
			if(cfg.Drink) 
			{
				if(cfg.PrintCommands)
				{
					PrintString("ÿc1::ÿc0 Auto Potion Disabled");
				}
				cfg.Drink = 0;

				return true;
			}
			else if(!cfg.Drink) 
			{
				return true;
			}
		}
		if(!strcmpi(Msg[1], "Life") && argc == 3)
        {
			char Buffer[20];

			cfg.DrinkLife = atoi(Msg[2]);
			
			if(cfg.PrintCommands)
			{
				PrintString("ÿc2::ÿc0 Drink Life is set to %i", cfg.DrinkLife);
			}

			return true;
		}

		if(!strcmpi(Msg[1] ,"Mana") && argc == 3)
        {
			char Buffer[20];

			cfg.DrinkMana = atoi(Msg[2]);
			
			if(cfg.PrintCommands)
			{
				PrintString("ÿc2::ÿc0 Drink Mana is set to %i", cfg.DrinkMana);
			}

			return true;
		}

		if(!strcmpi(Msg[1], "liferej") && argc == 3)
        {
			char Buffer[20];

			cfg.DrinkLifeRej=atoi(Msg[2]);
			
			if(cfg.PrintCommands)
			{
				PrintString("ÿc2::ÿc0 Drink LifeRej is set to %i", cfg.DrinkLifeRej);
			}

			return true;
		}

		if(!strcmpi(Msg[1], "manarej") && argc == 3)
        {
			char Buffer[20];

			cfg.DrinkManaRej = atoi(Msg[2]);
			
			if(cfg.PrintCommands)
			{
				PrintString("ÿc2::ÿc0 Drink ManaRej is set to %i", cfg.DrinkManaRej);
			}

			return true;
		}
	}

	if(!strcmpi(Msg[0], "town"))
    {
		if(!strcmpi(Msg[1], "life") && argc == 3)
        {
			char Buffer[20];

			cfg.TownLifeChicken = atoi(Msg[2]);
			
			if(cfg.PrintCommands)
			{
				PrintString("ÿc2::ÿc0 Town Life is set to %i", cfg.TownLifeChicken);
			}

			return true;
		}

		if(!strcmpi(Msg[1], "mana") && argc == 3)
        {
			char Buffer[20];

			cfg.TownManaChicken = atoi(Msg[2]);
			
			if(cfg.PrintCommands)
			{
				PrintString("ÿc2::ÿc0 Town Mana is set to %i", cfg.TownManaChicken);
			}

			return true;
		}
	}

	if(!strcmpi(Msg[0], "quit"))
    {
		if(!strcmpi(Msg[1], "life") && argc == 3)
        {
			char Buffer[20];

			cfg.QuitLife = atoi(Msg[2]);
			
			if(cfg.PrintCommands)
			{
				PrintString("ÿc2::ÿc0 Quit Life is set to %i", cfg.QuitLife);
			}

			return true;
		}

		if(!strcmpi(Msg[1], "Mana") && argc == 3)
        {
			char Buffer[20];

			cfg.QuitMana = atoi(Msg[2]);
			
			if(cfg.PrintCommands)
			{
				PrintString("ÿc2::ÿc0 Quit Mana is set to %i", cfg.QuitMana);
			}

			return true;
		}
	}

	if(!strcmpi(Msg[0], "On") && !strcmpi(Msg[1], "Host")&& argc == 3)
    {
		if(atoi(Msg[2]) <0 || atoi(Msg[2]) > 4)
			return true;

		cfg.ChickenOnHostile = atoi(Msg[2]);

		if(cfg.PrintCommands)
		{
			if(cfg.ChickenOnHostile == 0) 
			PrintString("ÿc1::ÿc0 Hostile Chicken is set to OFF");

			if(cfg.ChickenOnHostile == 1) 
			PrintString("ÿc2::ÿc0 Hostile Chicken is set to TP");

			if(cfg.ChickenOnHostile == 2) 
			PrintString("ÿc2::ÿc0 Hostile Chicken is set to TELE");

			if(cfg.ChickenOnHostile == 3) 
			PrintString("ÿc2::ÿc0 Hostile Chicken is set to EXIT",0);

			if(cfg.ChickenOnHostile == 4) 
			PrintString("ÿc2::ÿc0 Hostile Chicken is set to WARN");
		}
		return true;
	}

	if(!strcmpi(Msg[0], "On") && !strcmpi(Msg[1], "Aim") && argc == 3)
	{
		if(atoi(Msg[2]) <0 || atoi(Msg[2]) > 4)
			return true;

		cfg.ChickenOnAim = atoi(Msg[2]);

		if(cfg.PrintCommands)
		{
			if(cfg.ChickenOnAim == 0)
			PrintString("ÿc1::ÿc0 Aim Chicken is set to Off");

			if(cfg.ChickenOnAim == 1)
			PrintString("ÿc2::ÿc0 Aim Chicken is set to TP");

			if(cfg.ChickenOnAim == 2)
			PrintString("ÿc2::ÿc0 Aim Chicken is set to Tele");

			if(cfg.ChickenOnAim == 3)
			PrintString("ÿc2::ÿc0 Aim Chicken is set to Exit");

			if(cfg.ChickenOnAim == 4)
			PrintString("ÿc2::ÿc0 Aim Chicken is set to Warn");
		}
		return true;
	}

	if(!strcmpi(Msg[0], "Messages")) 
	{
		if(!strcmpi(Msg[1], "on"))
		{
			cfg.PrintCommands = 1;
			return true;
		}

		if(!strcmpi(Msg[1], "off"))
		{
			cfg.PrintCommands = 0;
			return true;
		}
	}

	if(!strcmpi(Msg[0], "Overhead")) 
	{
		if(!strcmpi(Msg[1], "on"))
		{
			cfg.PrintOverhead = 1;
			return true;
		}

		if(!strcmpi(Msg[1], "off"))
		{
			cfg.PrintOverhead = 0;
			return true;
		}
	}

	if(!strcmpi(Msg[0], "blind")) 
	{
		if(!strcmpi(Msg[1], "5"))
		{
			if(cfg.PrintCommands)
			{
				PrintString("Blindspot: ÿc25 (Silent Aim)",0);
			}
			cfg.BlindSpot = 5;
			return true;
		}
		if(!strcmpi(Msg[1], "4"))
		{
			if(cfg.PrintCommands)
			{
				PrintString("Blindspot: ÿc24",0);
			}
			cfg.BlindSpot = 4;
			return true;
		}
		if(!strcmpi(Msg[1], "3"))
		{
			if(cfg.PrintCommands)
			{
				PrintString("Blindspot: ÿc23",0);
			}
			cfg.BlindSpot = 3;
			return true;
		}
		if(!strcmpi(Msg[1], "2"))
		{
			if(cfg.PrintCommands)
			{
				PrintString("Blindspot: ÿc22",0);
			}
			cfg.BlindSpot = 2;
			return true;
		}
		if(!strcmpi(Msg[1], "1"))
		{
			if(cfg.PrintCommands)
			{
				PrintString("Blindspot: ÿc21",0);
			}
			cfg.BlindSpot = 1;
			return true;
		}
	}

	//if(!strcmpi(Msg[0], "fcr") && argc == 2)
	//{
	//	cfg.FCR = atoi(Msg[1]);
	//	{
	//		MaximizeFCR();
	//	}
	//	return true;
	//}
	//if(!strcmpi(Msg[0], "fhr") && argc == 2)
	//{
	//	cfg.FHR = atoi(Msg[1]);
	//	{
	//		MaximizeFHR();
	//	}
	//	return true;
	//}
	//if(!strcmpi(Msg[0], "fbr") && argc == 2)
	//{
	//	cfg.FBR = atoi(Msg[1]);
	//	{
	//		MaximizeFBR();
	//	}
	//	return true;
	//}
	//if(!strcmpi(Msg[0], "ias") && argc == 2)
	//{
	//	cfg.IAS = atoi(Msg[1]);
	//	{
	//		MaximizeIAS();
	//	}
	//	return true;

	//}

	if(!strcmpi(Msg[0], "deathmessage")) 
	{
		if(!strcmpi(Msg[1], "on"))

		{
			cfg.PKMessage = 1;
				if(cfg.PrintCommands)
				{
			PrintString("ÿc2::ÿc0 Death Message Enabled");
				}
			return true;
		}
		if(!strcmpi(Msg[1], "off"))
		{
			cfg.PKMessage = 0;
				if(cfg.PrintCommands)
				{
			PrintString("ÿc1::ÿc0 Death Message Disabled");
				}
			return true;
		}
	}

	/* HIDE HACK */
	if(!strcmpi(Msg[0], "hide")) 
	{
		cfg.PrintMessages = 0;
		cfg.PrintIHPKMessages = 0;
		cfg.PrintCommands = 0;
		cfg.PrintOverhead=0;
		cfg.PrintJoinMessages = 0;
		cfg.PrintTargetMessages = 0;

		cfg.DrawVectors = 0;
		cfg.PlayerInfo = 0;
		cfg.LevelNames = 0;
		cfg.DrawMonsters = 0;
		cfg.DrawMissiles = 0;
		return true;
	}

	/* SHOW HACK */
	if(!strcmpi(Msg[0], "show")) 
	{
		cfg.PrintMessages = 1;
		cfg.PrintIHPKMessages = 1;
		cfg.PrintCommands = 1;
		cfg.PrintOverhead=1;
		cfg.PrintJoinMessages = 1;

		cfg.DrawVectors = 1;
		cfg.PlayerInfo = 1;
		cfg.LevelNames = 1;
		cfg.DrawMonsters = 1;
		cfg.DrawMissiles = 1;
		return true;
	}
	//Auto Invite and Loot
	if(!strcmpi(Msg[0], "InviteMembers")) 
	{
		if(!strcmpi(Msg[1], "on")) 
		{
			cfg.InviteMembers = 1;
			if(cfg.PrintCommands)
			{
				PrintString("ÿc2::ÿc0 Auto Member Invite Enabled");
			}
			return true;
		}
		if(!strcmpi(Msg[1], "off")) 
		{
			cfg.InviteMembers = 0;
			if(cfg.PrintCommands)
			{
				PrintString("ÿc1::ÿc0 Auto Member Invite Disabled");
			}
			return true;
		}
	}

	if(!strcmpi(Msg[0], "LootMembers")) 
	{
		if(!strcmpi(Msg[1], "on"))
		{
			cfg.LootMembers = 1;
			if(cfg.PrintCommands)
			{
				PrintString("ÿc2::ÿc0 Auto Member Loot Enabled");
			}
			return true;
		}

		if(!strcmpi(Msg[1], "off")) 
		{
			cfg.LootMembers = 0;
			if(cfg.PrintCommands)
			{
				PrintString("ÿc1::ÿc0 Auto Member Loot Disabled");
			}
			return true;
		}
	}
	//Maphooks
	if(!strcmpi(Msg[0], "Monsters")) 
	{
		if(!strcmpi(Msg[1], "on")) 
		{
			cfg.DrawMonsters = 1;
			if(cfg.PrintCommands)
			{
				PrintString("ÿc2::ÿc0 Monster Blob Drawing Enabled");
			}
			return true;
		}
		if(!strcmpi(Msg[1], "off")) 
		{
			cfg.DrawMonsters = 0;
			if(cfg.PrintCommands)
			{
				PrintString("ÿc1::ÿc0 Monster Blob Drawing Disabled");
			}
			return true;
		}
	}
	if(!strcmpi(Msg[0], "Vectors")) 
	{
		if(!strcmpi(Msg[1], "on"))
		{
			cfg.DrawVectors = 1;
			if(cfg.PrintCommands)
			{
				PrintString("ÿc2::ÿc0 Vector Drawing Enabled");
			}
			return true;
		}

		if(!strcmpi(Msg[1], "off")) 
		{
			cfg.DrawVectors = 0;
			if(cfg.PrintCommands)
			{
				PrintString("ÿc1::ÿc0 Vector Drawing Disabled");
			}
			return true;
		}
	}
	if(!strcmpi(Msg[0], "Missiles")) 
	{
		if(!strcmpi(Msg[1], "on"))
		{
			cfg.DrawMissiles = 1;
			if(cfg.PrintCommands)
			{
				PrintString("ÿc2::ÿc0 Missile Drawing Enabled");
			}
			return true;
		}

		if(!strcmpi(Msg[1], "off")) 
		{
			cfg.DrawMissiles = 0;
			if(cfg.PrintCommands)
			{
				PrintString("ÿc1::ÿc0 Missile Drawing Disabled");
			}
			return true;
		}
	}
	if(!strcmpi(Msg[0], "AimVector")) 
	{
		if(!strcmpi(Msg[1], "on"))
		{
			cfg.PlayerLine = 1;
			if(cfg.PrintCommands)
			{
				PrintString("ÿc2::ÿc0 Aim Vector Enabled");
			}
			return true;
		}

		if(!strcmpi(Msg[1], "off")) 
		{
			cfg.PlayerLine = 0;
			if(cfg.PrintCommands)
			{
				PrintString("ÿc1::ÿc0 Aim Vector Disabled");
			}
			return true;
		}
	}
	if(!strcmpi(Msg[0], "maphooks")) 
	{
		if(!strcmpi(Msg[1], "on"))
		{
			cfg.DrawVectors=1;
			cfg.DrawMonsters=1;
			cfg.DrawMissiles=1;
			cfg.PlayerLine=1;
			if(cfg.PrintCommands)
			{
				PrintString("ÿc2::ÿc0 Map Hooks Enabled");
			}
			return true;
		}

		if(!strcmpi(Msg[1], "off")) 
		{
			cfg.DrawVectors=0;
			cfg.DrawMonsters=0;
			cfg.DrawMissiles=0;
			cfg.PlayerLine=0;
			if(cfg.PrintCommands)
			{
				PrintString("ÿc1::ÿc0 Map Hooks Disabled");
			}
			return true;
		}
	}
	if(!strcmpi(Msg[0], "drop")) 
	{
		TerminateProcess(GetCurrentProcess(),0);
	}
	if(!strcmpi(Msg[0], "breakpoint"))
	{
		ReadConfig3();
		return true;
	}
	//AimBox
	if(!strcmpi(Msg[0], "AimBox")) 
	{
		if(!strcmpi(Msg[1], "on")) 
		{
			cfg.AimBoxEnabled = 1;
			if(cfg.PrintCommands)
			{
				PrintString("ÿc2::ÿc0 Aim Box Enabled");
			}
			return true;
		}

		if(!strcmpi(Msg[1], "off")) 
		{
			cfg.AimBoxEnabled = 0;
			if(cfg.PrintCommands)
			{
				PrintString("ÿc1::ÿc0 Aim Box Disabled");
			}
			return true;
		}
	}
	//Custom Screenhooks
	if(!strcmpi(Msg[0], "Extra")) 
	{
		if(!strcmpi(Msg[1], "on")) 
		{
			cfg.ExtraInfo = 1;
			if(cfg.PrintCommands)
			{
				PrintString("ÿc2::ÿc0 Extra Info Enabled");
			}
			return true;
		}

		if(!strcmpi(Msg[1], "off")) 
		{
			cfg.ExtraInfo = 0;
			if(cfg.PrintCommands)
			{
				PrintString("ÿc1::ÿc0 Extra Info Disabled");
			}
			return true;
		}
	}
	if(!strcmpi(Msg[0], "Timestamp")) 
	{
		if(!strcmpi(Msg[1], "on")) 
		{
			cfg.TimeStamp = 1;
			if(cfg.PrintCommands)
			{
				PrintString("ÿc2::ÿc0 Time Stamp Enabled");
			}
			return true;
		}

		if(!strcmpi(Msg[1], "off")) 
		{
			cfg.TimeStamp = 0;
			if(cfg.PrintCommands)
			{
				PrintString("ÿc1::ÿc0 Time Stamp Disabled");
			}
			return true;
		}
	}
	if(!strcmpi(Msg[0], "tag")) 
	{
		if(!strcmpi(Msg[1], "on")) 
		{
			cfg.IHPKTag = 1;
			if(cfg.PrintCommands)
			{
				PrintString("ÿc2::ÿc0 Tag Enabled");
			}
			return true;
		}

		if(!strcmpi(Msg[1], "off")) 
		{
			cfg.IHPKTag = 0;
			if(cfg.PrintCommands)
			{
				PrintString("ÿc1::ÿc0 Tag Disabled");
			}
			return true;
		}
	}

	if(!strcmpi(Msg[0], "orbs"))
	{
		if(!strcmpi(Msg[1], "on"))
		{
			cfg.ShowLifeManaPer = 1;
			if(cfg.PrintCommands)
			{
				PrintString("ÿc2::ÿc0 Orb Percents Enabled");
			}
			return true;
		}	
		if(!strcmpi(Msg[1], "off"))
		{
			cfg.ShowLifeManaPer = 0;
			if(cfg.PrintCommands)
			{
				PrintString("ÿc1::ÿc0 Orb Percents Disabled");
			}
			return true;
		}
	}
	if(!strcmpi(Msg[0], "info")) 
	{
		if(!strcmpi(Msg[1], "on")) 
		{
			cfg.ShowInfoBox = 1;
			if(cfg.PrintCommands)
			{
				PrintString("ÿc2::ÿc0 Extra Info Enabled");
			}
			return true;
		}
		if(!strcmpi(Msg[1], "off")) 
		{
			cfg.ShowInfoBox = 0;
			if(cfg.PrintCommands)
			{
				PrintString("ÿc1::ÿc0 Extra Info Disabled");
			}
			return true;
		}
	}
	if(!strcmpi(Msg[0], "cleanshot")) 
	{
		if(!strcmpi(Msg[1], "on")) 
		{
			cfg.CleanShot = 1;
			if(cfg.PrintCommands)
			{
				PrintString("ÿc2::ÿc0 Clean Screenshot Enabled");
			}
			return true;
		}
		if(!strcmpi(Msg[1], "off")) 
		{
			cfg.CleanShot = 0;
			if(cfg.PrintCommands)
			{
				PrintString("ÿc1::ÿc0 Clean Screenshot Disabled");
			}
			return true;
		}
	}
	if(!strcmpi(Msg[0], "checksafe")) 
	{
		if(!strcmpi(Msg[1], "rejuv")) 
		{
			if(!strcmpi(Msg[2], "on")) 
			{
				cfg.QuitOnJuvRunOut = 1;
				if(cfg.PrintCommands)
				{
					PrintString("ÿc2::ÿc0 Checksafe Rejuv Enabled");
				}
				return true;
			}
			if(!strcmpi(Msg[2], "off")) 
			{
				cfg.QuitOnJuvRunOut = 0;
				if(cfg.PrintCommands)
				{
					PrintString("ÿc1::ÿc0 Checksafe Rejuv Disabled");
				}
				return true;
			}
		}
		if(!strcmpi(Msg[1], "town")) 
		{
			if(!strcmpi(Msg[2], "on")) 
			{
				cfg.QuitOnFailedTP = 1;
				if(cfg.PrintCommands)
				{
					PrintString("ÿc2::ÿc0 Checksafe Town Enabled");
				}
				return true;
			}
			if(!strcmpi(Msg[2], "off")) 
			{
				cfg.QuitOnFailedTP = 0;
				if(cfg.PrintCommands)
				{
					PrintString("ÿc1::ÿc0 Checksafe Town Disabled");
				}
				return true;
			}
		}
	}
	//Enchant Bot
	if(!strcmpi(Msg[0], "Enchant")) 
	{
		if(!strcmpi(Msg[1], "on")) 
		{
			char Buffer[200];
			if(!EnchBot) 
			{
				EnchBot=true;		
				if(cfg.PrintOverhead) OverheadMessage("Ench Bot Activated");

				Speak("Enchant Bot has been Activated! Commands: <%s> <%s> <%s>", cfg.EnchMe, cfg.EnchMerc, cfg.EnchAll);

				CreateThread(0,0,AutoPartyThread,0,0,0);
				return true;
			}
			else return false;
		}

		if(!strcmpi(Msg[1], "off")) 
		{
			if(EnchBot)
			{
				if(cfg.PrintOverhead) OverheadMessage("Ench Bot ÿc1Deactivated");

				Speak("Enchant Bot has been Deactivated!");

				TerminateThread(AutoPartyThread,0); EnchBot = false;
				return true;
			}
			else return false;
		}
	}
	//Auto Squelch
	if(!strcmpi(Msg[0], "addspammer"))
	{
		char Buffer[100];
		if(AddSpam(Msg[1]))
		{
			if(cfg.PrintCommands)
			{
				sprintf(Buffer, "ÿc2:: ÿc0Added %s to Spammer List!", Msg[1]);
				PrintString(Buffer);
			}
			return true;
		}
		if(cfg.PrintCommands)
		{
			sprintf(Buffer, "ÿc2:: ÿc0Failed to Add %s to Spammer List!", Msg[1]);
			PrintString(Buffer);
		}
	}
	//Ping, Version, Time...
	if(!strcmpi(Msg[0], "ping"))
	{
		Speak("?ping");
		Speak("FPS: %i, Skip: %i, Ping: %i",D2CLIENT_FPS,*p_D2CLIENT_Skip,D2CLIENT_Ping);
		return true;
	}
	if(!strcmpi(Msg[0], "ping2"))
	{
		Speak("?ping");
		// Speak("FPS: %i, Skip: %i, Ping: %i",D2CLIENT_FPS,*p_D2CLIENT_Skip,D2CLIENT_Ping);
		Speak("FPS: %i, Skip: %i, Ping: %i",D2CLIENT_FPS,*p_D2CLIENT_Skip,D2CLIENT_Ping*10);
		return true;
	}
	if(!strcmpi(Msg[0], "ver"))
	{
		Speak("?info");
		Speak("Team jEFF");
		return true;
	}
	// added by Perry
	if(!strcmpi(Msg[0], "jeff"))
	{
		Speak("?time");
		Speak("Current Time: It's time to get Jeffy.");
		return true;
	}
	if(!strcmpi(Msg[0], "sexy"))
	{
		Speak("?time");
		Speak("Current Time: It's sexy time!");
		return true;
	}
	if(!strcmpi(Msg[0], "random"))
	{
		char Buffer[100];
		if((Msg[1]!=NULL))
		{
			Speak("/whois %s",Msg[1]);
			Speak("<Battle.Net> %s is unknown.",Msg[1]);
			Speak("<Battle.Net> Random Detected!");
			return true;
		}
	}
	if(!strcmpi(Msg[0], "time"))
	{
		SYSTEMTIME T;
		GetLocalTime(&T);

		char CurrentTime[200];
		char CurrentTime2[200];

		if(T.wHour == 0) sprintf(CurrentTime,"%.2d:%.2d:%.2d AM", T.wHour + 12, T.wMinute, T.wSecond);
		if(T.wHour >= 1 && T.wHour <= 11) sprintf(CurrentTime,"%.2d:%.2d:%.2d AM", T.wHour, T.wMinute, T.wSecond);
		if(T.wHour == 12) sprintf(CurrentTime,"%.2d:%.2d:%.2d PM", T.wHour, T.wMinute, T.wSecond);
		if(T.wHour >= 13 && T.wHour <= 23) sprintf(CurrentTime,"%.2d:%.2d:%.2d PM", T.wHour - 12, T.wMinute, T.wSecond);

		sprintf(CurrentTime2,"%d/%d/%d", T.wMonth, T.wDay, T.wYear);

		Speak("?time");
		Speak("Current Time: %s - %s",CurrentTime2,CurrentTime);
		return true;
	}
	//Fake Kill
	if(!strcmpi(Msg[0], "fake1"))
	{
		char Buffer[100];
		if((Msg[1]!=NULL && Msg[2]!=NULL))
		{
			sprintf(Buffer, "ÿc4%s was slain by %s", Msg[1], GetGameInfo()->szCharName);
			PrintString(Buffer);
			sprintf(Buffer, "ÿc4%s(%s) left our world. Diablo's minions weaken.", Msg[1], Msg[2]);
			PrintString(Buffer);
			return true;
		}
	}
	if(!strcmpi(Msg[0], "fake2"))
	{
		char Buffer[100];
		if((Msg[1]!=NULL))
		{
			sprintf(Buffer, "ÿc4%s was slain by %s", Msg[1], GetGameInfo()->szCharName);
			PrintString(Buffer);
			//Speak("/whois %s",Msg[1]);
			//Speak("<BattleNet> %s is ownt",Msg[1]);
			return true;
		}
	}
	return false;
}

bool AddSpam(char *Name)
{	
	char mypath[266]={0};
	char Buffer[100];

	sprintf_s(mypath,"%s\\%s",szModulePath,"Spammers.txt");
	sprintf_s(Buffer, "%s\n", Name);
	ofstream myfile(mypath, ios::app);
	if (myfile.is_open())
	{
		myfile << Buffer;
		myfile.close();
		return true;
	}
	if(cfg.PrintCommands)
	{
		PrintString("ÿc1::ÿc0 Failed to Open Spammer List");
	}
	return false;
}

bool Input(char* Text) 
{
	char* argv[32];
	char Buffer2[100];
	bool Called = false;

	if (Text[0] == cfg.Trigger)  
	{
		strcpy(Buffer2,Text+1);
		int argc = MakeParameter(Buffer2,argv,' ',FALSE);
		if(InputMessage(argv,argc)) 
		return false;
		if(cfg.PrintCommands)
		{
			PrintString("ÿc1:: ÿc0Not a valid command!"); 
		}
		return false; // Return false, so it wont print
		return false;
		return false;
	}
	return true;
}
BOOL BadSkillRight()
{
	WORD Right=GetCurrentSkillRight();

	if(Right==D2S_TELEPORT || Right==D2S_BATTLEORDERS ||
		Right==D2S_BATTLECOMMAND || Right==D2S_SHOUT ||
		Right==D2S_HOLYSHIELD || Right==D2S_ENERGYSHIELD)
		return TRUE;

	return FALSE;
}
BOOL BadSkillLeft()
{
	WORD Left=GetCurrentSkillLeft();

	if(Left==D2S_TELEPORT || Left==D2S_BATTLEORDERS ||
		Left==D2S_BATTLECOMMAND || Left==D2S_SHOUT ||
		Left==D2S_HOLYSHIELD || Left==D2S_ENERGYSHIELD)
		return TRUE;

	return FALSE;
}

BOOL __fastcall SendPacket(byte* data, DWORD aLen) 
{
	if(data[0]==0x15) 
	{
		char* bdata = (char*)data+3;

		if(strlen(bdata)>1)
			if(!Input(bdata))
				return FALSE;
	}
	
	if(data[0]==0x05||data[0]==0x08)
	{

		//if(!UnMaxed && BadSkillLeft())
		//	UnMax();
		//else if(UnMaxed && !BadSkillLeft())
		//	MaxBPS(Myself->dwTxtFileNo);
	}

	if(data[0]==0x0c||data[0]==0x0e||data[0]==0x0f) 
	{

		//if(!UnMaxed && BadSkillRight())
		//	UnMax();
		//else if(UnMaxed && !BadSkillRight())
		//	MaxBPS(Myself->dwTxtFileNo);
	}

	if(AA) 
	{
		if(GameReady())
		{
			WORD LeftSkill = GetCurrentSkillLeft();
			WORD RightSkill = GetCurrentSkillRight();
			if(LeftAA)
			{
				if(!BlindToggled || BlindToggled && cfg.BlindSpot != 5 &&  LeftSkill != D2S_TELEPORT)
				{
					if(data[0]==0x05||data[0]==0x08) 
					{
						byte Packet[9] = {0x07,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00};
						*(DWORD*)&Packet[5] = Auto.GetPlayerID();
						SendGAMEPacket(Packet,9);
						return FALSE;
					}
				}
			}
			if(!LeftAA)
			{
				if(!BlindToggled || BlindToggled && cfg.BlindSpot != 5 &&  RightSkill != D2S_TELEPORT)
				{
					if(data[0]==0x0c||data[0]==0x0e||data[0]==0x0f) 
					{
						byte Packet[9] = {0x0d,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00};
						*(DWORD*)&Packet[5] = Auto.GetPlayerID();
						SendGAMEPacket(Packet,9);
						return FALSE;
					}
				}
			}
		}
	}
	return TRUE;
}