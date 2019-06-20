#include "Includes.h"

cDraw* Draw;

unsigned long Fonts::mainFont;
unsigned long Fonts::weaponFont;

void cDraw::intializeFonts( ) {
	Fonts::mainFont = I::Surface->createFont( );
	Fonts::weaponFont = I::Surface->createFont( );

	I::Surface->drawSetFontGlyphSet( Fonts::mainFont, "Verdana", 12, 400, FONTFLAG_DROPSHADOW );
	I::Surface->drawSetFontGlyphSet( Fonts::weaponFont, "Small Fonts", 9, 400, FONTFLAG_OUTLINE );
	
}

void cDraw::outlinedRectangle( int x, int y, int w, int h, Color color ) {
	I::Surface->drawSetColor( color.r, color.g, color.b, color.a );
	I::Surface->drawOutlinedRectangle( x, y, x + w, y + h );
}

void cDraw::filledRectangle( int x, int y, int w, int h, Color color ) {
	I::Surface->drawSetColor( color.r, color.g, color.b, color.a );
	I::Surface->drawFilledRectangle( x, y, x + w, y + h );
}

void cDraw::Line( int x, int y, int x2, int y2, Color color ) {
	I::Surface->drawSetColor( color.r, color.g, color.b, color.a );
	I::Surface->drawLine( x, y, x2, y2 );
}

void cDraw::String( int x, int y, unsigned long font, Color color, const char* text, bool centered ) {
	size_t o_Size = strlen( text ) + 1;
	const size_t n_Size = 1024;
	size_t convertedChars = 0;
	wchar_t wcstring[ n_Size ];
	mbstowcs_s( &convertedChars, wcstring, o_Size, text, _TRUNCATE );

	int width, height;
	I::Surface->getTextSize( font, wcstring, width, height );

	if ( centered )
		x -= width / 2;


	I::Surface->drawSetTextFont( font );
	I::Surface->drawSetTextColor( color.r, color.g, color.b, color.a );
	I::Surface->drawSetTextPosition( x, y );
	I::Surface->drawPrintText( wcstring, wcslen( wcstring ) );
}

void cDraw::verticalGradient( int x, int y, int w, int h, Color startColor, Color endColor ) // Credits: Synraw
{
	filledRectangle( x, y, w, h, startColor );
	BYTE first = endColor.r;
	BYTE second = endColor.g;
	BYTE third = endColor.b;
	for ( float i = 0; i < h; i++ )
	{
		float fi = i, fh = h;
		float a = fi / fh;
		DWORD ia = a * 255;
		filledRectangle( x, y + i, w, 1, Color( first, second, third, ia ) );
	}
}


void cDraw::Polygon( int count, vertexT* Vertexes, Color color ) { // Credits: Synraw
	static int Texture = I::Surface->createNewTexture( );
	unsigned char buffer[ 4 ] = { 255, 255, 255, 255 };
	I::Surface->drawSetTextureColor( Texture, buffer, 1, 1 );
	I::Surface->drawSetColor( color.r, color.g, color.b, color.a );
	I::Surface->drawSetTexture( Texture );
	I::Surface->drawTexturedPolygon( count, Vertexes );
}
