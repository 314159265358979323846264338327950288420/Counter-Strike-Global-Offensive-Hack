enum cCSWeaponType {
	WEAPONTYPE_KNIFE = 0,
	WEAPONTYPE_PISTOL,
	WEAPONTYPE_SUBMACHINEGUN,
	WEAPONTYPE_RIFLE,
	WEAPONTYPE_SHOTGUN,
	WEAPONTYPE_SNIPER_RIFLE,
	WEAPONTYPE_MACHINEGUN,
	WEAPONTYPE_C4,
	WEAPONTYPE_PLACEHOLDER,
	WEAPONTYPE_GRENADE,
	WEAPONTYPE_UNKNOWN
};

class cCSWeaponInfo {
private:
	char _0x0000[ 20 ];
public:
	int m_iMaxClip; //0x0014
private:
	char _0x0018[ 12 ];
public:
	int m_iMaxReservedAmmo;    //0x0024
private:
	char _0x0028[ 88 ];
public:
	char* m_szAmmoType; // 0x0080
private:
	char _0x0084[ 4 ]; // 0x0084
public:
	char* m_szHudName; //0x0088
	char* m_szWeaponName; //0x008C
private:
	char _0x0090[ 56 ];
public:
	cCSWeaponType m_iType; //0x00C8
private:
	char _0x00CC[ 4 ];
	int m_iPrice; //0x00D0
	int m_iReward; //0x00D4
private:
	char _0x00D8[ 20 ];
public:
	bool m_bFullAuto; //0x00EC
private:
	char _0x00ED[ 3 ];
public:
	int m_iDamage; //0x00F0
	float m_iArmorRatio; //0x00F4
	int m_iBullets; //0x00F8
	float m_flPenetration; //0x00FC
private:
	char _0x0100[ 8 ];
public:
	float m_flRange; //0x0108
	float m_flRangeModifier; //0x010C
private:
	char _0x0110[ 16 ];
public:
	bool m_bSilencer; //0x0120
private:
	char _0x0121[ 15 ];
public:
	float m_flMaxSpeed; //0x0130
	float m_flMaxSpeedAlt; //0x0134
private:
	char _0x0138[ 76 ];
public:
	int m_iRecoilSeed; //0x0184
private:
	char _0x0188[ 32 ];
};

class cBaseCombatWeapon {
public:
	int Ammo( ) {
		return *reinterpret_cast< int* >( uintptr_t( this ) + 0x3244 /*m_iClip1*/ );
	}

	float GetSpread( ) {
		typedef float( __thiscall * vFuncFn )( void* );
		return vFunc<vFuncFn>( this, 446 )( this );
	}

	cCSWeaponInfo* weaponInfo( ) {
		typedef cCSWeaponInfo* ( __thiscall * vFuncFn )( void* );
		return vFunc<vFuncFn>( this, 454 )( this );
	}

	float getCone( ) {
		typedef float( __thiscall * vFuncFn )( void* );
		return vFunc<vFuncFn>( this, 476 )( this );
	}

	void updateAccuracyPenalty( ) {
		typedef void( __thiscall * vFuncFn )( void* );
		return vFunc<vFuncFn>( this, 477 )( this );
	}

	float getInaccuracy( ) {
		typedef float( __thiscall * vFuncFn )( void* );
		return vFunc<vFuncFn>( this, 484 )( this );
	}
};