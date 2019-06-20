#include "Includes.h"

std::string cBaseEntity::playerName( )
{
	return this->getPlayerInfo( this->Index( ) ).name;
}

player_info_t cBaseEntity::getPlayerInfo( int Index ) {
	player_info_t pinfo;
	I::Engine->getPlayerInfo( Index, &pinfo );
	return pinfo;
}

cBaseCombatWeapon* cBaseEntity::getActiveWeapon( ) {
	return reinterpret_cast< cBaseCombatWeapon* >( I::entityList->getClientEntityFromHandle( this->getActiveWeaponHandle( ) ) );
}

Vector cBaseEntity::eyePosition( ) {
		Vector ret;
		typedef void( __thiscall * OrigFn )( void*, Vector& );
		vFunc<OrigFn>( this, 281 )( this, ret );
		return ret;
}