#include "Includes.h"

cHitmarker* Hitmarker;

void cHitmarker::Run( ) {
	/*
	* Disabled until i set up a proper event listener ( you can do that yourself :) )
	*/

	auto localPlayer = I::entityList->getClientEntity( I::Engine->getLocalPlayer( ) );

	if ( !localPlayer ) {
		Globals::gameEvents::playerHurtTriggered = false;
		return;
	}

	int screenWidth, screenHeight;
	I::Engine->getScreenSize( screenWidth, screenHeight );

	int startingPointX = screenWidth / 2, startingPointY = screenHeight / 2;

	if ( Globals::gameEvents::playerHurtTriggered ) {

		Draw->Line( startingPointX - 10, startingPointY - 10, startingPointX - 5, startingPointY - 5, Color( 255, 255, 255 ) ); // Top left
		Draw->Line( startingPointX + 10, startingPointY - 10, startingPointX + 5, startingPointY - 5, Color( 255, 255, 255 ) ); // Top Right
		Draw->Line( startingPointX - 10, startingPointY + 10, startingPointX - 5, startingPointY + 5, Color( 255, 255, 255 ) ); // Bottom left
		Draw->Line( startingPointX + 10, startingPointY + 10, startingPointX + 5, startingPointY + 5, Color( 255, 255, 255 ) ); // Bottom Right
	}

	if ( I::globalVars->curTime - Globals::gameEvents::timeHit > 0.5 ) {
		Globals::gameEvents::playerHurtTriggered = false;
	}
}