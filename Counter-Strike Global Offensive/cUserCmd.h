class cUserCmd
{
public:
	int     commandNumer;
	int     tickCount;
	Vector  viewAngles;
	Vector  aimDirection;
	float   forwardMove;
	float   sideMove;
	float   upMove;
	int     Buttons;
	char    Impulse;
	int     weaponSelect;
	int     weaponSubtype;
	int     randomSeed;
	short   mousedX;
	short   mousedY;
	bool    Predicted;
	char    pad_0x4C[ 0x18 ];
};
