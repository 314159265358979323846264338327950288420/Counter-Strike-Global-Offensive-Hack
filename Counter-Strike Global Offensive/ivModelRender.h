class ivModelRender {
public:
	void overrideMaterial( iMaterial* material ) {
		typedef void( __thiscall * vFuncFn )( void*, iMaterial*, int, int );
		return vFunc<vFuncFn>( this, 1 )( this, material, 0, 0 );
	}
};