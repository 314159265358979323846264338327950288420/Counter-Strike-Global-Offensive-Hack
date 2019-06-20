#include "Includes.h"

cHooking* Hooking;

typedef void( __thiscall* lockCursorFn )( void* );
typedef HRESULT( __stdcall* endSceneFn )( LPDIRECT3DDEVICE9 Device );
typedef void( __thiscall* paintFn )( void*, int );
typedef long( __thiscall* resetFn )( IDirect3DDevice9* device, D3DPRESENT_PARAMETERS* pp );
typedef void( __thiscall* sceneEndFn )( void* );
typedef void( __thiscall* overrideViewFn )( void*, cViewSetup* );
typedef bool( __thiscall* createMoveFn )( void*, float, cUserCmd* );
typedef void( __thiscall* frameStageNotifyFn )( void*, int );
typedef float( __thiscall* getViewmodelFovFn )( void* );
typedef bool( __thiscall* isHltvFn )( void* );
typedef bool( __thiscall* shouldDrawFogFn )( void* );
typedef bool( __thiscall* fireEventClientSideFn )( void*, iGameEvent*, bool );


std::unique_ptr <VMT> directXHook;
std::unique_ptr <VMT> iSurfaceHook;
std::unique_ptr <VMT> vGuiHook;
std::unique_ptr <VMT> renderViewHook;
std::unique_ptr <VMT> clientModeHook;
std::unique_ptr <VMT> clientHook;
std::unique_ptr <VMT> engineHook;
std::unique_ptr <VMT> gameEventManagerHook;

WNDPROC originalWndproc;


extern IMGUI_API LRESULT ImGui_ImplDX9_WndProcHandler( HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam );

long __stdcall endScene( LPDIRECT3DDEVICE9 Device ) {
	static auto oEndScene = directXHook->getOriginal<endSceneFn>( 42 );

	static bool init = true;

	if ( init ) {
		ImGui_ImplDX9_Init( FindWindowW( L"Valve001", nullptr ), Device );
		Menu->Initialize( );
		init = false;
	}


	Device->SetRenderState( D3DRS_SRGBWRITEENABLE, false ); // Fix wack colors

	ImGui_ImplDX9_NewFrame( );
	Menu->Run( );
	ImGui::Render( );

	Device->SetRenderState( D3DRS_SRGBWRITEENABLE, true );

	return oEndScene( Device );
}

LRESULT __stdcall wndProc( HWND Hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam ) {
	if ( uMsg == WM_KEYDOWN && wParam == VK_INSERT )
		menuInfo::menuActive = !menuInfo::menuActive;


	if ( ImGui_ImplDX9_WndProcHandler( Hwnd, uMsg, wParam, lParam ) && menuInfo::menuActive && !( wParam == 0x57 /*W*/ || wParam == 0x41 /*A*/ || wParam == 0x53 /*S*/ || wParam == 0x44 /*D*/ ) ) { //if menu is visible
		return 1l;
	}

	return CallWindowProcA( originalWndproc, Hwnd, uMsg, wParam, lParam );
}

void lockCursor( ) {
	static auto oLockCursor = iSurfaceHook->getOriginal<lockCursorFn>( 67 );

	if ( menuInfo::menuActive )
		I::Surface->unlockCursor( );
	else
		oLockCursor( I::Surface );
}

void __fastcall Paint( void* Ecx, uintptr_t, int Mode ) {
	static auto oPaint = vGuiHook->getOriginal<paintFn>( 14 );
	oPaint( Ecx, Mode );

	static auto startDrawing = reinterpret_cast< void( __thiscall* )( void* ) >( Utilities::hookManager->getSignature( "vguimatsurface.dll", "55 8B EC 83 E4 C0 83 EC 38" ) );
	static auto finishDrawing = reinterpret_cast< void( __thiscall* )( void* ) >( Utilities::hookManager->getSignature( "vguimatsurface.dll", "8B 0D ? ? ? ? 56 C6" ) );

	if ( Mode & PAINT_UIPANELS ) {
		startDrawing( I::Surface );

		Draw->String( 0, 0, Fonts::mainFont, Color( 255, 255, 255 ), "WeebB0t" );
		Visuals->Run( );
		Hitmarker->Run( );
		finishDrawing( I::Surface );
	}
}

long __stdcall Reset( IDirect3DDevice9* pDevice, D3DPRESENT_PARAMETERS* pPresentationParameters ) {
	static auto oReset = directXHook->getOriginal<resetFn>( 16 );
	ImGui_ImplDX9_InvalidateDeviceObjects( );
	ImGui_ImplDX9_CreateDeviceObjects( );
	return oReset( pDevice, pPresentationParameters );
}

void __stdcall sceneEnd( ) {
	static auto oSceneEnd = renderViewHook->getOriginal<sceneEndFn>( 9 );
	oSceneEnd( I::renderView );
	Chams->Run( );
}

void __stdcall overrideView( cViewSetup* Setup ) {
	static auto oOverrideView = clientModeHook->getOriginal<overrideViewFn>( 18 );
	Setup->fov += Configuration::Visuals::View::Fov;
	oOverrideView( I::clientMode, Setup );
}

bool __stdcall createMove( float frameTime, cUserCmd* Cmd ) {
	static auto oCreateMove = clientModeHook->getOriginal<createMoveFn>( 24 );
	return oCreateMove( I::clientMode, frameTime, Cmd );
}

void __stdcall frameStageNotify( int Stage ) {
	static auto oFrameStageNotify = clientHook->getOriginal<frameStageNotifyFn>( 37 );
	oFrameStageNotify( I::Client, Stage );
}

float __stdcall getViewmodelFov( ) {
	static auto oGetViewmodelFov = clientModeHook->getOriginal<getViewmodelFovFn>( 35 );
	float Return = oGetViewmodelFov( I::clientMode ) + Configuration::Visuals::View::viewmodelFov;
	return Return;
}

bool __fastcall isHltv( void* Ecx, void* Edx ) {
	static auto oIsHltv = engineHook->getOriginal<isHltvFn>( 93 );
	return oIsHltv( Ecx );
}

bool __fastcall shouldDrawFog( void* Ecx, void* Edx ) {
	static auto oShouldDrawFov = clientModeHook->getOriginal<shouldDrawFogFn>( 17 );
	return oShouldDrawFov( Ecx );
}

bool __fastcall fireEventClientSide( void* Ecx, void* Edx, iGameEvent* Event, bool unk1 ) {
	static auto oFireEventClientSide = gameEventManagerHook->getOriginal<fireEventClientSideFn>( 8 );

	if ( !Event )
		return oFireEventClientSide( Ecx, Event, unk1 );

	return oFireEventClientSide( Ecx, Event, unk1 );
}

void cHooking::initializeHooks( ) {
	HANDLE hConsole = GetStdHandle( STD_OUTPUT_HANDLE );
	SetConsoleTextAttribute( hConsole, consoleColors::Yellow );

	directXHook = std::make_unique<VMT>( I::directX );
	directXHook->Hook( 42, endScene );
	directXHook->Hook( 16, Reset );

	iSurfaceHook = std::make_unique<VMT>( I::Surface );
	iSurfaceHook->Hook( 67, lockCursor );

	vGuiHook = std::make_unique<VMT>( I::enginevGui );
	vGuiHook->Hook( 14, Paint );

	renderViewHook = std::make_unique<VMT>( I::renderView );
	renderViewHook->Hook( 9, sceneEnd );

	clientModeHook = std::make_unique<VMT>( I::clientMode );
	clientModeHook->Hook( 17, shouldDrawFog );
	clientModeHook->Hook( 18, overrideView );
	clientModeHook->Hook( 24, createMove );
	clientModeHook->Hook( 35, getViewmodelFov );

	clientHook = std::make_unique<VMT>( I::Client );
	clientHook->Hook( 37, frameStageNotify );

	engineHook = std::make_unique<VMT>( I::Engine );
	engineHook->Hook( 93, isHltv );

	gameEventManagerHook = std::make_unique<VMT>( I::gameEventManager );
	gameEventManagerHook->Hook( 8, fireEventClientSide );

	std::cout << "Hooked endScene: " << endScene << "\n";
	std::cout << "Hooked Reset: " << Reset << "\n";

	std::cout << "Hooked lockCursor: " << lockCursor << "\n";

	std::cout << "Hooked Paint: " << Paint << "\n";

	std::cout << "Hooked sceneEnd: " << sceneEnd << "\n";

	std::cout << "Hooked shouldDrawFog: " << shouldDrawFog << "\n";
	std::cout << "Hooked overrideView: " << overrideView << "\n";
	std::cout << "Hooked createMove: " << createMove << "\n";
	std::cout << "Hooked getViewmodelFov: " << getViewmodelFov << "\n";

	std::cout << "Hooked frameStageNotify: " << frameStageNotify << "\n";

	std::cout << "Hooked isHltv: " << isHltv << "\n";

	std::cout << "Hooked fireEventClientSide: " << fireEventClientSide << "\n";

	if ( FindWindowW( L"Valve001", nullptr ) )
		originalWndproc = reinterpret_cast< WNDPROC >( SetWindowLongPtr( FindWindowW( L"Valve001", nullptr ), GWLP_WNDPROC, reinterpret_cast< LONG_PTR >( wndProc ) ) );

	std::cout << "Hooked wndProc: " << wndProc << "\n";

	SetConsoleTextAttribute( hConsole, 15 );
}

void cHooking::unhookHooks( ) {
	directXHook->unhook( 42 );
	directXHook->unhook( 16 );

	iSurfaceHook->unhook( 67 );

	vGuiHook->unhook( 14 );

	renderViewHook->unhook( 9 );
	clientModeHook->unhook( 18 );
	clientModeHook->unhook( 24 );

	clientHook->unhook( 37 );

	gameEventManagerHook->unhook( 9 );

	SetWindowLongPtr( FindWindowW( L"Valve001", nullptr ), GWLP_WNDPROC, reinterpret_cast< LONG_PTR >( originalWndproc ) );
}