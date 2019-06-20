class cCollideable {
public:
	Vector& Mins( ) {
		typedef Vector& ( __thiscall * vFuncFn )( void* );
		return vFunc<vFuncFn>( this, 1 )( this );
	}
	Vector& Maxs( ) {
		typedef Vector& ( __thiscall * vFuncFn )( void* );
		return vFunc<vFuncFn>( this, 2 )( this );
	}
};

typedef struct player_info_s
{
	char _pad1[ 0x10 ];
	char name[ 80 ];//80
	char _pad2[ 0x64 ];
	char guid[ 32 + 1 ];
	char _pad3[ 0x17B ];

} player_info_t;

class cBaseEntity {
public:
	int Health( ) {
		return *reinterpret_cast< int* >( uintptr_t( this ) + 0x100 /*m_iHealth*/ );
	}

	int Armor( ) {
		return *reinterpret_cast< int* >( uintptr_t( this ) + 0xB340 /*m_ArmorValue*/ );
	}

	byte lifeState( ) {
		return *reinterpret_cast< byte* >( uintptr_t( this ) + 0x25F /*m_lifeState*/ );
	}

	int Team( ) {
		return *reinterpret_cast< int* >( uintptr_t( this ) + 0xF4 /*m_iTeamNum*/ );
	}

	bool isAlive( ) {
		return this->lifeState( ) == 0;
	}

	bool isDormant( ) {
		return *reinterpret_cast< bool* >( uintptr_t( this ) + 0xED /*m_bDormant*/ );
	}

	Vector& absOrigin( ) {
		typedef Vector& ( __thiscall * vFuncFn )( void* );
		return vFunc<vFuncFn>( this, 10 )( this );
	}

	Vector& absAngles( ) {
		typedef Vector& ( __thiscall * vFuncFn )( void* );
		return vFunc<vFuncFn>( this, 11 )( this );
	}

	void* Animating( ) {
		return reinterpret_cast< void* >( uintptr_t( this ) + 0x4 );
	}

	int drawModel( int Flags, uint8_t Alpha ) {
		typedef int& ( __thiscall * vFuncFn )( void*, int, uint8_t );
		return vFunc<vFuncFn>( Animating( ), 9 )( Animating( ), Flags, Alpha );
	}

	cCollideable* Collideable( ) {
		typedef cCollideable* ( __thiscall * vFuncFn )( void* );
		return vFunc<vFuncFn>( this, 3 )( this );
	}

	Matrix3x4& coordinateFrame( ) {
		return *reinterpret_cast< Matrix3x4* >( reinterpret_cast< uintptr_t >( this ) + ( 0x474 /*m_CollisionGroup*/ - 0x30 ) );
	}

	Vector vecMins( ) {
		return *reinterpret_cast< Vector* >( uintptr_t( this ) + 0x31c /*m_Collision*/ + 0x320 );
	}

	Vector vecMaxs( ) {
		return *reinterpret_cast< Vector* >( uintptr_t( this ) + 0x31c /*m_Collision*/ + 0x32C );
	}

	int Index( ) {
		return *reinterpret_cast< int* >( uintptr_t( this ) + 0x64 );
	}

	HANDLE getActiveWeaponHandle( ) {
		return *reinterpret_cast< HANDLE* >( uintptr_t( this ) + 0x2EF8 /*m_hActiveWeapon*/ );
	}

	Vector& Maxs( ) {
		typedef Vector& ( __thiscall * vFuncFn )( void* );
		return vFunc<vFuncFn>( this, 2 )( this );
	}

	Vector Origin( ) {
		return *reinterpret_cast< Vector* >( uintptr_t( this ) + 0x138 );
	}

	Vector viewOffset( ) {
		float x = *reinterpret_cast< float* >( uintptr_t( this ) + 0x108 );
		float y = *reinterpret_cast< float* >( uintptr_t( this ) + 0x10c );
		float z = *reinterpret_cast< float* >( uintptr_t( this ) + 0x110 );

		Vector ret = Vector( x, y, z );
		return ret;
	}

	std::string playerName( );
	player_info_t getPlayerInfo( int Index );
	cBaseCombatWeapon* getActiveWeapon( );
	Vector eyePosition( );
};