#include "Includes.h"

cVisuals* Visuals;

int x, y, w, h;

void cVisuals::Name( cBaseEntity* Entity ) {
	Draw->String( x + ( w / 2 ), y - 14, Fonts::mainFont, Color( 255, 255, 255, 255 ), Entity->playerName( ).c_str( ), true );
}

void cVisuals::Box( cBaseEntity* Entity ) {
	Draw->outlinedRectangle( x, y, w, h, Color( 255, 239, 4, 255 ) );
	Draw->outlinedRectangle( x - 1, y - 1, w + 2, h + 2, Color( 0, 0, 0, 255 ) );
	Draw->outlinedRectangle( x + 1, y + 1, w - 2, h - 2, Color( 0, 0, 0, 255 ) );
}

void cVisuals::healthBar( cBaseEntity* Entity ) {
	int healthbarHeight = ( Entity->Health() * h ) / 100;
	Draw->filledRectangle( x - 6, y, 4, h, Color( 0, 0, 0, 185 ) );
	Draw->filledRectangle( x - 6, y + ( h - healthbarHeight ), 4, healthbarHeight, Color( 0, 255, 0, 255 ) );
	Draw->outlinedRectangle( x - 6, y - 1, 4, h + 2, Color( 0, 0, 0, 255 ) );
}

void cVisuals::visibilityWarning( cBaseEntity* Entity ) {
	/*
	* Todo: Count number of players not visible and display them
	*/
}

void cVisuals::Weapon( cBaseEntity* Entity ) {
	int yOffsetAddition = Configuration::Visuals::Player::Ammo && Entity->getActiveWeapon( )->Ammo( ) > 0 ? 6 : 1;
	auto weaponInfo = Entity->getActiveWeapon( )->weaponInfo( );
	std::string weaponName;
	weaponName.append( weaponInfo->m_szWeaponName );
	weaponName.erase( 0, 7 );

	std::transform( weaponName.begin( ), weaponName.end( ), weaponName.begin( ), std::toupper );

	Draw->String( x + ( w / 2 ), y + h + yOffsetAddition, Fonts::weaponFont, Color( 255, 255, 255, 230 ), weaponName.c_str( ), true );
}

void cVisuals::armorBar( cBaseEntity* Entity ) {
	int armorBarHeight = ( Entity->Armor( ) * h ) / 100;
	Draw->filledRectangle( x + w + 2, y, 4, h, Color( 0, 0, 0, 185 ) );
	Draw->filledRectangle( x + w + 2, y + ( h - armorBarHeight ), 4, armorBarHeight, Color( 70, 130, 180, 255 ) );
	Draw->outlinedRectangle( x + w + 2, y - 1, 4, h + 2, Color( 0, 0, 0, 255 ) );
}

void cVisuals::ammoBar( cBaseEntity* Entity ) {
	if ( Entity->getActiveWeapon( )->Ammo( ) <= 0 )
		return;

	Draw->filledRectangle( x, y + h + 2, w, 4, Color( 0, 0, 0, 185 ) );
	Draw->filledRectangle( x, y + h + 2, ( Entity->getActiveWeapon( )->Ammo( ) * w ) / Entity->getActiveWeapon( )->weaponInfo( )->m_iMaxClip, 4, Color( 255, 255, 255, 255 ) );
	Draw->outlinedRectangle( x - 1, y + h + 2, w + 2, 4, Color( 0, 0, 0, 255 ) );
}

void cVisuals::runPlayers( ) {
	auto localPlayer = I::entityList->getClientEntity( I::Engine->getLocalPlayer( ) );
	for ( int i = 1; i < I::Engine->getMaxClients( ); i++ ) {
		auto Entity = I::entityList->getClientEntity( i );

		if ( !Entity || Entity->isDormant( ) || !Entity->isAlive( ) || Entity->Team( ) == localPlayer->Team( ) || !Entity->getActiveWeapon( ) || !Entity->getActiveWeapon( )->weaponInfo( ) )
			continue;

		if ( Math->calculateBoxBounds( Entity, x, y, w, h ) ) {
			if ( Configuration::Visuals::Player::Name ) Name( Entity );
			if ( Configuration::Visuals::Player::Box ) Box( Entity );
			if ( Configuration::Visuals::Player::Health ) healthBar( Entity );
			if ( Configuration::Visuals::Player::Weapon ) Weapon( Entity );
			if ( Configuration::Visuals::Player::Armor ) armorBar( Entity );
			if ( Configuration::Visuals::Player::Ammo ) ammoBar( Entity );
		}
		else {
			visibilityWarning( Entity );
		}
	}
}

void cVisuals::espPreview( ) {

	if ( !menuInfo::menuActive || menuInfo::currentTab != 0 )
		return;

	static Vector2D Size = Vector2D( 216, 260 );

	int xPos = menuInfo::menuPosition.x - 222, yPos = menuInfo::menuPosition.y + 50;
	int boxXPos = xPos + 60, boxYPos = yPos + 25, boxWidth = 100, boxHeight = 200;

	Draw->filledRectangle( xPos, yPos, Size.x, Size.y, Color( 30, 30, 30, 255 ) );
	Draw->outlinedRectangle( xPos, yPos, Size.x, Size.y, Color( 0, 0, 0, 255 ) );
	Draw->filledRectangle( xPos + 9, yPos + 9, Size.x - 18, Size.y - 18, Color( 50, 50, 50, 255 ) ); // Inner background
	Draw->outlinedRectangle( xPos + 9, yPos + 9, Size.x - 18, Size.y - 18, Color( 0, 0, 0, 255 ) );


	if ( Configuration::Visuals::Player::Name )
		Draw->String( boxXPos + ( boxWidth / 2 ), boxYPos - 14, Fonts::mainFont, Color( 255, 255, 255 ), "Uber_", true );

	if ( Configuration::Visuals::Player::Box ) {
		Draw->outlinedRectangle( boxXPos - 1, boxYPos - 1, boxWidth + 2, boxHeight + 2, Color( 0, 0, 0 ) );
		Draw->outlinedRectangle( boxXPos, boxYPos, boxWidth, boxHeight, Color( 255, 239, 4, 255 ) );
		Draw->outlinedRectangle( boxXPos + 1, boxYPos + 1, boxWidth - 2, boxHeight - 2, Color( 0, 0, 0 ) );
	}

	if ( Configuration::Visuals::Player::Health ) {
		int healthbarHeight = ( 25 * boxHeight ) / 100;
		Draw->filledRectangle( boxXPos - 6, boxYPos, 4, boxHeight, Color( 0, 0, 0, 185 ) );
		Draw->filledRectangle( boxXPos - 6, boxYPos + (boxHeight - healthbarHeight), 4, healthbarHeight, Color( 0, 255, 0, 255 ) );
		Draw->outlinedRectangle( boxXPos - 6, boxYPos - 1, 4, boxHeight + 2, Color( 0, 0, 0, 255 ) );
	}

	if ( Configuration::Visuals::Player::Armor ) {
		int armorBarHeight = ( 75 * boxHeight ) / 100;
		Draw->filledRectangle( boxXPos + boxWidth + 2, boxYPos, 4, boxHeight, Color( 0, 0, 0, 185 ) );
		Draw->filledRectangle( boxXPos + boxWidth + 2, boxYPos + ( boxHeight - armorBarHeight), 4, armorBarHeight, Color( 70, 130, 180, 255 ) );
		Draw->outlinedRectangle( boxXPos + boxWidth + 2, boxYPos - 1, 4, boxHeight + 2, Color( 0, 0, 0, 255 ) );
	}

	if ( Configuration::Visuals::Player::Ammo ) {
		Draw->filledRectangle( boxXPos, boxYPos + boxHeight + 2, boxWidth, 4, Color( 0, 0, 0, 185 ) );
		Draw->filledRectangle( boxXPos, boxYPos + boxHeight + 2, ( 8 * boxWidth ) / 13, 4, Color( 255, 255, 255, 255 ) );
		Draw->outlinedRectangle( boxXPos - 1, boxYPos + boxHeight + 2, boxWidth + 2, 4, Color( 0, 0, 0, 255 ) );
	}

	if ( Configuration::Visuals::Player::Weapon ) {
		std::string weaponName;
		weaponName.append( "hkp2000" );

		int yOffsetAddition = Configuration::Visuals::Player::Ammo ? 6 : 1;

		std::transform( weaponName.begin( ), weaponName.end( ), weaponName.begin( ), std::toupper );

		Draw->String( boxXPos + ( boxWidth / 2 ), boxYPos + boxHeight + yOffsetAddition, Fonts::weaponFont, Color( 255, 255, 255, 230 ), weaponName.c_str( ), true );
	}
}

void cVisuals::Run( ) {
	this->runPlayers( );
	this->espPreview( );
}

