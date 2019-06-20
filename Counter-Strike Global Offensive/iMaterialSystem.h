

using materialHandleT = unsigned short;
class iMaterial {
public:

	const char* getName( ) {
		typedef const char* ( __thiscall * vFuncFn )( void* );
		return vFunc<vFuncFn>( this, 0 )( this );
	}

	const char* getGroupName( ) {
		typedef const char* ( __thiscall * vFuncFn )( void* );
		return vFunc<vFuncFn>( this, 1 )( this );
	}


	void setAlpha( float alpha ) {
		typedef void( __thiscall * vFuncFn )( void*, float );
		return vFunc<vFuncFn>( this, 27 )( this, alpha );
	}

	void setAlpha( int alpha ) {
		typedef void( __thiscall * vFuncFn )( void*, float );
		return vFunc<vFuncFn>( this, 27 )( this, alpha / 255.f );
	}

	void setColorRGB( Color color ) {
		typedef void( __thiscall * vFuncFn )( void*, float, float, float );
		return vFunc<vFuncFn>( this, 29 )( this, color.r, color.g, color.b );
	}

	void setColor( float r, float g, float b ) {
		typedef void( __thiscall * vFuncFn )( void*, float, float, float );
		return vFunc<vFuncFn>( this, 28 )( this, r / 255.f, g / 255.f, b / 255.f );
	}

	void setColor( int color32 ) {
		int r1 = ( color32 >> 16 ) & 0xff;
		int g1 = ( color32 >> 8 ) & 0xff;
		int b1 = color32 & 0xff;
		iMaterial::setColor( r1, g1, b1 );
	}

	void incrementReferenceCount( ) {
		typedef void( __thiscall * vFuncFn )( void* );
		return vFunc<vFuncFn>( this, 12 )( this );
	}

	void setFlag( int flag, bool on ) {
		typedef void( __thiscall * vFuncFn )( void*, int, bool );
		return vFunc<vFuncFn>( this, 29 )( this, flag, on );
	}
};

class iMaterialSystem {
public:

	iMaterial* findMaterial( char const* material_name, const char* group_name, bool complain = true, const char* complain_prefix = 0 ) {
		typedef iMaterial* ( __thiscall * vFuncFn )( void*, char const*, const char*, bool, const char* );
		return vFunc<vFuncFn>( this, 84 )( this, material_name, group_name, complain, complain_prefix );
	}

	materialHandleT firstMaterial( ) {
		typedef materialHandleT( __thiscall * vFuncFn )( void* );
		return vFunc<vFuncFn>( this, 86 )( this );
	}

	materialHandleT nextMaterial( materialHandleT handle ) {
		typedef materialHandleT( __thiscall * vFuncFn )( void*, materialHandleT );
		return vFunc<vFuncFn>( this, 87 )( this, handle );
	}

	materialHandleT invalidMaterialHandle( ) {
		typedef materialHandleT( __thiscall * vFuncFn )( void* );
		return vFunc<vFuncFn>( this, 88 )( this );
	}

	iMaterial* getMaterial( materialHandleT handle ) {
		typedef iMaterial* ( __thiscall * vFuncFn )( void*, materialHandleT );
		return vFunc<vFuncFn>( this, 89 )( this, handle );
	}

	int	getMaterialsCount( ) {
		typedef int( __thiscall * vFuncFn )( void* );
		return vFunc<vFuncFn>( this, 90 )( this );
	}
};

enum MaterialVarFlags_t
{
	MATERIAL_VAR_DEBUG = ( 1 << 0 ),
	MATERIAL_VAR_NO_DEBUG_OVERRIDE = ( 1 << 1 ),
	MATERIAL_VAR_NO_DRAW = ( 1 << 2 ),
	MATERIAL_VAR_USE_IN_FILLRATE_MODE = ( 1 << 3 ),

	MATERIAL_VAR_VERTEXCOLOR = ( 1 << 4 ),
	MATERIAL_VAR_VERTEXALPHA = ( 1 << 5 ),
	MATERIAL_VAR_SELFILLUM = ( 1 << 6 ),
	MATERIAL_VAR_ADDITIVE = ( 1 << 7 ),
	MATERIAL_VAR_ALPHATEST = ( 1 << 8 ),
	MATERIAL_VAR_MULTIPASS = ( 1 << 9 ),
	MATERIAL_VAR_ZNEARER = ( 1 << 10 ),
	MATERIAL_VAR_MODEL = ( 1 << 11 ),
	MATERIAL_VAR_FLAT = ( 1 << 12 ),
	MATERIAL_VAR_NOCULL = ( 1 << 13 ),
	MATERIAL_VAR_NOFOG = ( 1 << 14 ),
	MATERIAL_VAR_IGNOREZ = ( 1 << 15 ),
	MATERIAL_VAR_DECAL = ( 1 << 16 ),
	MATERIAL_VAR_ENVMAPSPHERE = ( 1 << 17 ),
	MATERIAL_VAR_NOALPHAMOD = ( 1 << 18 ),
	MATERIAL_VAR_ENVMAPCAMERASPACE = ( 1 << 19 ),
	MATERIAL_VAR_BASEALPHAENVMAPMASK = ( 1 << 20 ),
	MATERIAL_VAR_TRANSLUCENT = ( 1 << 21 ),
	MATERIAL_VAR_NORMALMAPALPHAENVMAPMASK = ( 1 << 22 ),
	MATERIAL_VAR_NEEDS_SOFTWARE_SKINNING = ( 1 << 23 ),
	MATERIAL_VAR_OPAQUETEXTURE = ( 1 << 24 ),
	MATERIAL_VAR_ENVMAPMODE = ( 1 << 25 ),
	MATERIAL_VAR_SUPPRESS_DECALS = ( 1 << 26 ),
	MATERIAL_VAR_HALFLAMBERT = ( 1 << 27 ),
	MATERIAL_VAR_WIREFRAME = ( 1 << 28 ),
	MATERIAL_VAR_ALLOWALPHATOCOVERAGE = ( 1 << 29 ),
	MATERIAL_VAR_IGNORE_ALPHA_MODULATION = ( 1 << 30 ),

	// NOTE: Only add flags here that either should be read from
	// .vmts or can be set directly from client code. Other, internal
	// flags should to into the flag enum in imaterialinternal.h
};
