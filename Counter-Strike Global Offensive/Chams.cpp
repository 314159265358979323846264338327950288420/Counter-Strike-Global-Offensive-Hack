#include "Includes.h"

cChams* Chams;

void cChams::Run( ) {
	if ( !Configuration::Visuals::Player::Chams::Enabled )
		return;

	static iMaterial* Material;

	if ( Material )
		Material->incrementReferenceCount( );

	Material = I::materialSystem->findMaterial( "chamsMaterial", "Model textures" );

	auto localPlayer = I::entityList->getClientEntity( I::Engine->getLocalPlayer( ) );
	for ( int i = 1; i < I::Engine->getMaxClients( ); i++ ) {
		auto Entity = I::entityList->getClientEntity( i );

		if ( !Entity || Entity->isDormant( ) || !Entity->isAlive( ) || Entity->Team( ) == localPlayer->Team( ) || !Entity->getActiveWeapon( ) || !Entity->getActiveWeapon( )->weaponInfo( ) )
			continue;

		if ( Configuration::Visuals::Player::Chams::XQZ ) {
			Material->setFlag( MATERIAL_VAR_WIREFRAME, Configuration::Visuals::Player::Chams::Wireframe );
			Material->setFlag( MATERIAL_VAR_IGNOREZ, true );
			Material->setColor( 244, 47, 5 );
			I::modelRender->overrideMaterial( Material );
			Entity->drawModel( 0x1, 255 );
			I::modelRender->overrideMaterial( nullptr );
		}

		Material->setFlag( MATERIAL_VAR_WIREFRAME, Configuration::Visuals::Player::Chams::Wireframe );
		Material->setFlag( MATERIAL_VAR_IGNOREZ, false );
		Material->setColor( 255, 255, 0 );
		I::modelRender->overrideMaterial( Material );
		Entity->drawModel( 0x1, 255 );
		I::modelRender->overrideMaterial( nullptr );
	}
}

void cChams::Initialize( ) {
	std::ofstream( "csgo/materials/chamsMaterial.vmt" ) << R"#("VertexLitGeneric" { "$basetexture" "vgui/white_additive" })#";
}