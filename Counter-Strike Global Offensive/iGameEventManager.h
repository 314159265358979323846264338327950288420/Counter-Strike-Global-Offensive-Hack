#pragma once

#define EVENT_DEBUG_ID_INIT 42 
#define EVENT_DEBUG_ID_SHUTDOWN 13  

class bfWrite;
class bfRead;
class iGameEvent
{
public:
	virtual ~iGameEvent( ) = 0;
	virtual const char* getName( ) const = 0;

	virtual bool            isReliable( ) const = 0;
	virtual bool            isLocal( ) const = 0;
	virtual bool            isEmpty( const char* keyName = nullptr ) = 0;

	virtual bool            getBool( const char* keyName = nullptr, bool defaultValue = false ) = 0;
	virtual int             getInt( const char* keyName = nullptr, int defaultValue = 0 ) = 0;
	virtual uint64_t        getUint64( const char* keyName = nullptr, unsigned long defaultValue = 0 ) = 0;
	virtual float			getFloat( const char* keyName = nullptr, float defaultValue = 0.0f ) = 0;
	virtual const char* getString( const char* keyName = nullptr, const char* defaultValue = "" ) = 0;
	virtual const wchar_t* getWString( const char* keyName, const wchar_t* defaultValue = L"" ) = 0;

	virtual void            setBool( const char* keyName, bool value ) = 0;
	virtual void            setInt( const char* keyName, int value ) = 0;
	virtual void            setUint64( const char* keyName, unsigned long value ) = 0;
	virtual void            setFloat( const char* keyName, float value ) = 0;
	virtual void            setString( const char* keyName, const char* value ) = 0;
	virtual void            setWString( const char* keyName, const wchar_t* value ) = 0;
};

class iGameEventListener2
{
public:
	virtual ~iGameEventListener2( void ) {}

	virtual void fireGameEvent( iGameEvent* event ) = 0;
	virtual int  getEventDebugID( void ) = 0;

public:
	int m_iDebugId;
};

class iGameEventManager2
{
public:
	virtual             ~iGameEventManager2( ) = 0;
	virtual int         loadEventsFromFile( const char* filename ) = 0;
	virtual void        reset( ) = 0;
	virtual bool        addListener( iGameEventListener2* listener, const char* name, bool bServerSide ) = 0;
	virtual bool        findListener( iGameEventListener2* listener, const char* name ) = 0;
	virtual int         removeListener( iGameEventListener2* listener ) = 0;
	virtual iGameEvent* createEvent( const char* name, bool bForce, unsigned int dwUnknown ) = 0;
	virtual bool        fireEvent( iGameEvent* event, bool bDontBroadcast = false ) = 0;
	virtual bool        fireEventClientSide( iGameEvent* event ) = 0;
	virtual iGameEvent* duplicateEvent( iGameEvent* event ) = 0;
	virtual void        freeEvent( iGameEvent* event ) = 0;
	virtual bool        serializeEvent( iGameEvent* event, bfWrite* buf ) = 0;
	virtual iGameEvent* unserializeEvent( bfRead* buf ) = 0;
};