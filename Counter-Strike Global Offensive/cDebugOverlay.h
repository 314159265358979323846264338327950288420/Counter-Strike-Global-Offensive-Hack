class OverlayText_t;

class cDebugOverlay {
public:
	virtual void            __unkn( ) = 0;
	virtual void            addEntityTextOverlay( int ent_index, int line_offset, float duration, int r, int g, int b, int a, const char* format, ... ) = 0;
	virtual void            addBoxOverlay( const Vector& origin, const Vector& mins, const Vector& max, Vector const& orientation, int r, int g, int b, int a, float duration ) = 0;
	virtual void            addSphereOverlay( const Vector& vOrigin, float flRadius, int nTheta, int nPhi, int r, int g, int b, int a, float flDuration ) = 0;
	virtual void            addTriangleOverlay( const Vector& p1, const Vector& p2, const Vector& p3, int r, int g, int b, int a, bool noDepthTest, float duration ) = 0;
	virtual void            addLineOverlay( const Vector& origin, const Vector& dest, int r, int g, int b, bool noDepthTest, float duration ) = 0;
	virtual void            addTextOverlay( const Vector& origin, float duration, const char* format, ... ) = 0;
	virtual void            addTextOverlay( const Vector& origin, int line_offset, float duration, const char* format, ... ) = 0;
	virtual void            addScreenTextOverlay( float flXPos, float flYPos, float flDuration, int r, int g, int b, int a, const char* text ) = 0;
	virtual void            addSweptBoxOverlay( const Vector& start, const Vector& end, const Vector& mins, const Vector& max, const Vector& angles, int r, int g, int b, int a, float flDuration ) = 0;
	virtual void            addGridOverlay( const Vector& origin ) = 0;
	virtual void            addCoordFrameOverlay( const Matrix3x4& frame, float flScale, int vColorTable[ 3 ][ 3 ] = NULL ) = 0;
	virtual int             screenPosition( const Vector& point, Vector& screen ) = 0;
	virtual int             screenPosition( float flXPos, float flYPos, Vector& screen ) = 0;
	virtual OverlayText_t* getFirst( void ) = 0;
	virtual OverlayText_t* getNext( OverlayText_t* current ) = 0;
	virtual void            clearDeadOverlays( void ) = 0;
	virtual void			clearAllOverlays( ) = 0;
	virtual void            addTextOverlayRGB( const Vector& origin, int line_offset, float duration, float r, float g, float b, float alpha, const char* format, ... ) = 0;
	virtual void            addTextOverlayRGB( const Vector& origin, int line_offset, float duration, int r, int g, int b, int a, const char* format, ... ) = 0;
	virtual void            addLineOverlayAlpha( const Vector& origin, const Vector& dest, int r, int g, int b, int a, bool noDepthTest, float duration ) = 0;
	virtual void            addBoxOverlay2( const Vector& origin, const Vector& mins, const Vector& max, Vector const& orientation, const uint8_t* faceColor, const uint8_t* edgeColor, float duration ) = 0;
	virtual void            purgeTextOverlays( ) = 0;
	virtual void            drawPill( const Vector& mins, const Vector& max, float& diameter, int r, int g, int b, int a, float duration ) = 0;
};