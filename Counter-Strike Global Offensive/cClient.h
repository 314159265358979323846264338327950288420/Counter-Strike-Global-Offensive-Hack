enum ClassId {

};

struct clientClass {

};

class cClient {
public:
	clientClass* getAllClasses( ) {
		typedef clientClass* ( __thiscall * vFuncFn )( void* );
		return vFunc<vFuncFn>( this, 8 )( this );
	}
};