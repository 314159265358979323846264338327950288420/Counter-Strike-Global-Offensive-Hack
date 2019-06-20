struct vertexT
{
	Vector2D	m_Position;
	Vector2D	m_TexCoord;

	vertexT( ) {}
	vertexT( const Vector2D& pos, const Vector2D& coord = Vector2D( 0, 0 ) )
	{
		m_Position = pos;
		m_TexCoord = coord;
	}
	void Initialize( const Vector2D& pos, const Vector2D& coord = Vector2D( 0, 0 ) )
	{
		m_Position = pos;
		m_TexCoord = coord;
	}
};


class iSurface {
public:
	void unlockCursor( ) {
		typedef void( __thiscall * vFuncFn )( void* );
		return vFunc<vFuncFn>( this, 66 )( this );
	}

	void drawFilledRectangle( int x, int y, int w, int h ) {
		typedef void( __thiscall * vFuncFn )( void*, int, int, int, int );
		return vFunc<vFuncFn>( this, 16 )( this, x, y, w, h );
	}

	void drawLine( int x, int y, int x2, int y2 ) {
		typedef void( __thiscall * vFuncFn )( void*, int, int, int, int );
		return vFunc<vFuncFn>( this, 19 )( this, x, y, x2, y2 );
	}

	void drawSetColor( int r, int g, int b, int a = 255 ) {
		typedef void( __thiscall * vFuncFn )( void*, int, int, int, int );
		return vFunc<vFuncFn>( this, 15 )( this, r, g, b, a );
	}

	void drawSetTextFont( DWORD font ) {
		typedef void( __thiscall * vFuncFn )( void*, unsigned );
		return vFunc<vFuncFn>( this, 23 )( this, font );
	}

	void drawSetTextColor( int r, int g, int b, int a = 255 ) {
		typedef void( __thiscall * vFuncFn )( void*, int, int, int, int );
		return vFunc<vFuncFn>( this, 25 )( this, r, g, b, a );
	}

	void drawSetTextPosition( int x, int y ) {
		typedef void( __thiscall * vFuncFn )( void*, int, int );
		return vFunc<vFuncFn>( this, 26 )( this, x, y );
	}

	void drawPrintText( const wchar_t* text, int length, int drawType = 0 ) {
		typedef void( __thiscall * vFuncFn )( void*, const wchar_t*, int, int );
		return vFunc<vFuncFn>( this, 28 )( this, text, length, drawType );
	}

	bool drawSetFontGlyphSet( DWORD font, const char* fontName, int tall, int weight, int flags ) {
		typedef bool( __thiscall * vFuncFn )( void*, unsigned, const char*, int, int, int, int, int, int, int );
		return vFunc<vFuncFn>( this, 72 )( this, font, fontName, tall, weight, 0, 0, flags, 0, 0 );
	}

	void drawOutlinedRectangle( int x, int y, int x2, int y2 ) {
		typedef void( __thiscall * vFuncFn )( void*, int, int, int, int );
		vFunc<vFuncFn>( this, 18 )( this, x, y, x2, y2 );
	}

	void getTextSize( DWORD font, const wchar_t* text, int& wide, int& tall ) {
		typedef void( __thiscall * OriginalFn )( void*, DWORD, const wchar_t*, int&, int& );
		return vFunc< OriginalFn >( this, 79 )( this, font, text, wide, tall );
	}

	unsigned long createFont( ) {
		typedef unsigned long( __thiscall * vFuncFn )( void* );
		return vFunc<vFuncFn>( this, 71 )( this );
	}

	void drawTexturedPolygon( int vtxCount, vertexT* vtx, bool bClipVertices = true ) {
		typedef void( __thiscall * vFuncFn )( void*, int, vertexT*, bool );
		return vFunc< vFuncFn >( this, 106 )( this, vtxCount, vtx, bClipVertices );
	}

	int createNewTexture( bool unk1 = true ) {
		typedef int( __thiscall * vFuncFn )( void*, bool );
		return vFunc< vFuncFn >( this, 43 )( this, unk1 );
	}

	void drawSetTextureColor( int textureID, unsigned char const* colors, int w, int h ) {
		typedef void( __thiscall * vFuncFn )( void*, int, unsigned char  const*, int, int );
		return vFunc< vFuncFn >( this, 37 )( this, textureID, colors, w, h );
	}

	void drawSetTexture( int textureID ) {
		typedef void( __thiscall * vFuncFn )( void*, int );
		return vFunc< vFuncFn >( this, 38 )( this, textureID );
	}
};

class iEnginevGui {
public:

};

enum paintModeT
{
	PAINT_UIPANELS = ( 1 << 0 ),
	PAINT_INGAMEPANELS = ( 1 << 1 ),
	PAINT_CURSOR = ( 1 << 2 )
};
