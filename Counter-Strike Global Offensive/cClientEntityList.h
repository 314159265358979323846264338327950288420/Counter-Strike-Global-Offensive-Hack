class cBaseHandle;
class iClientNetworkable;

class cClientEntityList {
public:
	virtual iClientNetworkable* getClientNetworkable( int index ) = 0;
	virtual iClientNetworkable* getClientNetworkableFromHandle( unsigned long Handle ) = 0;
	virtual iClientNetworkable* getClientUnknownFromHandle( unsigned long Handle ) = 0;
	virtual cBaseEntity* getClientEntity( int entindex ) = 0;
	virtual cBaseEntity* getClientEntityFromHandle( void* Handle ) = 0;
	virtual int numberOfEntities( bool unk1 ) = 0;
	virtual int getHighestEntityIndex( void ) = 0;
	virtual void setMaxEntities( int unk2 ) = 0;
	virtual int setMaxEntities( ) = 0;
};