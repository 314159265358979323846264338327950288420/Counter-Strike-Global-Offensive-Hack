#include "Includes.h"
cInterfaces* interfaceUtils;

cHookManager* Utilities::hookManager = new cHookManager;

cClient* I::Client = nullptr;
IDirect3DDevice9* I::directX = nullptr;
iSurface* I::Surface = nullptr;
iEnginevGui* I::enginevGui = nullptr;
cClientEntityList* I::entityList = nullptr;
iEngineClient* I::Engine = nullptr;
cDebugOverlay* I::debugOverlay = nullptr;
iRenderView* I::renderView = nullptr;
iMaterialSystem* I::materialSystem = nullptr;
ivModelRender* I::modelRender = nullptr;
void* I::clientMode = nullptr;
iGameEventManager2* I::gameEventManager = nullptr;
cGlobalVars* I::globalVars = nullptr;

void cInterfaces::findInterfaces( ) {
	I::Client = captureInterface<cClient>( "client_panorama", "VClient" );
	I::directX = **(IDirect3DDevice9 * ** )( Utilities::hookManager->getSignature( "shaderapidx9.dll", "A1 ?? ?? ?? ?? 50 8B 08 FF 51 0C" ) + 1 );
	I::Surface = captureInterface<iSurface>( "vguimatsurface", "VGUI_Surface" );
	I::enginevGui = captureInterface<iEnginevGui>( "engine", "VEngineVGui" );
	I::entityList = captureInterface<cClientEntityList>( "client_panorama", "VClientEntityList" );
	I::Engine = captureInterface<iEngineClient>( "engine", "VEngineClient" );
	I::debugOverlay = captureInterface<cDebugOverlay>( "engine", "VDebugOverlay" );
	I::renderView = captureInterface<iRenderView>( "engine", "VEngineRenderView" );
	I::materialSystem = captureInterface<iMaterialSystem>( "materialsystem", "VMaterialSystem" );
	I::modelRender = captureInterface<ivModelRender>( "engine", "VEngineModel" );
	I::clientMode = **(void*** )( ( *(DWORD * * )I::Client )[ 10 ] + 5 );
	I::gameEventManager = captureInterface<iGameEventManager2>( "engine", "GAMEEVENTSMANAGER002", true );
	I::globalVars = **(cGlobalVars*** )( ( *(DWORD * * )( I::Client ) )[ 0 ] + 0x1B );
}