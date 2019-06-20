class iEngineClient {
public:
	int getLocalPlayer( ) {
		typedef int( __thiscall * vFuncFn )( void* );
		return vFunc<vFuncFn>( this, 12 )( this );
	}

	void getScreenSize( int& Width, int& Height ) {
		typedef void ( __thiscall *vFuncFn )( void*, int&, int& );
		return vFunc<vFuncFn>( this, 5 )( this, Width, Height );
	}

	int getMaxClients( void )
	{
		typedef int( __thiscall * vFuncFn )( PVOID );
		return vFunc<vFuncFn>( this, 20 )( this );
	}

	int getPlayerForUserID( int userId )
	{
		typedef int ( __thiscall *vFuncFn )( void*, int );
		return vFunc<vFuncFn>( this, 9 )( this, userId );
	}

	void getPlayerInfo( int ent_num, player_info_t* pinfo )
	{
		typedef void( __thiscall * vFuncFn )( void*, int ent_num, player_info_t * pinfo );
		vFunc<vFuncFn>( this, 8 )( this, ent_num, pinfo );
	}
};