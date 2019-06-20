class iRenderView {
private:
	virtual void __pad0( );
	virtual void __pad1( );
	virtual void __pad2( );
	virtual void __pad3( );

public:
	virtual void setBlend( float blend ) = 0;
	virtual float getBlend( void ) = 0;
	virtual void setColor( float const* blend ) = 0;
	virtual void getColor( float* blend ) = 0;
};