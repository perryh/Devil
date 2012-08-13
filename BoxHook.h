struct tBoxes {

int Color;
int Trans;
int TextFont;
int TextColor;

int DrinkX;
int DrinkY;
int DrinkX2;
int DrinkY2;

int TargetX;
int TargetY;
int TargetX2;
int TargetY2;

int CurrentTargetX;
int CurrentTargetY;
int CurrentTargetX2;
int CurrentTargetY2;

int StatX;
int StatY;
int StatX2;
int StatY2;

int ChickenX;
int ChickenY;
int ChickenX2;
int ChickenY2;

int AmpX;
int AmpY;
int AmpX2;
int AmpY2;

int PlayerX;
int PlayerY;
int PlayerX2;
int PlayerY2;

int Tab1X;
int Tab1Y;
int Tab1X2;
int Tab1Y2;

int Tab2X;
int Tab2Y;
int Tab2X2;
int Tab2Y2;

int Tab3X;
int Tab3Y;
int Tab3X2;
int Tab3Y2;

int Tab4X;
int Tab4Y;
int Tab4X2;
int Tab4Y2;

int Tab5X;
int Tab5Y;
int Tab5X2;
int Tab5Y2;

int Tab6X;
int Tab6Y;
int Tab6X2;
int Tab6Y2;
};

extern tBoxes box;


extern bool MovePlayer;
extern bool MoveDrink;
extern bool MoveTarget;
extern bool MoveChicken;
extern bool MoveAmp;
extern bool MoveStat;

extern bool PlayerToggled;
extern bool DrinkToggled;
extern bool TargetToggled;
extern bool ChickenToggled;
extern bool WinampToggled;
extern bool StatToggled;

struct StatBox {
	int Statnumber;
	char StatInfo[50];
	char StringColor;
	char StatColor;
	bool shift;
};
int Players();
void TabbedWindows();
void DrinkWindow();
void InfoWindow();
void TargetWindow();
void ChickenWindow();
void WinampWindow();
void StatWindow(DWORD UnitID);
