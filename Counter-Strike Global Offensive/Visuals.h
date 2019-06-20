class cVisuals {
public:
	void Run( );
private:
	void Name( cBaseEntity* Entity );
	void Box( cBaseEntity* Entity );
	void healthBar( cBaseEntity* Entity );
	void armorBar( cBaseEntity* Entity );
	void ammoBar( cBaseEntity* Entity );
	void visibilityWarning( cBaseEntity* Entity );
	void Weapon( cBaseEntity* Entity );
	void runPlayers( );
	void espPreview( );
}; extern cVisuals* Visuals;