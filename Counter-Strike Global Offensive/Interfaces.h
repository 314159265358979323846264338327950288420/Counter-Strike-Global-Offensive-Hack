using interfaceFn = void* ( * )( );
class interfaceRegistration {
public:
	interfaceRegistration( ) = delete;

	interfaceFn            create_fn;
	const char* name;
	interfaceRegistration* next;
};

template<typename T>
static T* captureInterface( const char* Mod, const char* iFace, bool Exact = false ) {
	T* Interface = nullptr;
	interfaceRegistration* registerList;
	int partMatchLen = strlen( iFace );

	DWORD interfaceFn = reinterpret_cast< DWORD >( GetProcAddress( GetModuleHandleA( Mod ), "CreateInterface" ) );
	if ( !interfaceFn ) { return nullptr; }

	unsigned int jumpStart = (unsigned int )(interfaceFn )+4;
	unsigned int jumpTarget = jumpStart + *(unsigned int* )( jumpStart + 1 ) + 5;

	registerList = **reinterpret_cast< interfaceRegistration * ** >( jumpTarget + 6 );

	HANDLE hConsole = GetStdHandle( STD_OUTPUT_HANDLE );
	SetConsoleTextAttribute( hConsole, consoleColors::Cyan );

	for ( interfaceRegistration* Cur = registerList; Cur; Cur = Cur->next ) {
		if ( Exact ) {
			if ( strcmp( Cur->name, iFace ) == 0 ) {
				Interface = reinterpret_cast< T* >( Cur->create_fn( ) );
				std::cout << Mod << "->" << Cur->name << "\n";
			}
		}
		else {
			if ( !strncmp( Cur->name, iFace, partMatchLen ) && std::atoi( Cur->name + partMatchLen ) > 0 ) {
				Interface = reinterpret_cast< T* >( Cur->create_fn( ) );
				std::cout << Mod << "->" << Cur->name << "\n";
			}
		}
	}


	SetConsoleTextAttribute( hConsole, 15 );
	return Interface;
}

class cInterfaces {
public:
	void findInterfaces( );

private:
	void* retrieveInterface( const char* Module, const char* Name );
	typedef void* ( *retrieveInterfaceFn ) ( const char* name, int* return_code );

}; extern cInterfaces* interfaceUtils;

namespace I {
	extern cClient* Client;
	extern IDirect3DDevice9* directX;
	extern iSurface* Surface;
	extern iEnginevGui* enginevGui;
	extern cClientEntityList* entityList;
	extern iEngineClient* Engine;
	extern cDebugOverlay* debugOverlay;
	extern iRenderView* renderView;
	extern iMaterialSystem* materialSystem;
	extern ivModelRender* modelRender;
	extern void* clientMode;
	extern iGameEventManager2* gameEventManager;
	extern cGlobalVars* globalVars;
}

namespace Utilities {
	extern cHookManager* hookManager;
}