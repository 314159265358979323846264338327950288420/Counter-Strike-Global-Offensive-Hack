class cGlobalVars
{
public:
	float     realTime;                     // 0x0000
	int       frameCount;                   // 0x0004
	float     absoluteFrametime;            // 0x0008
	float     absoluteFrameStartTimeStdDev; // 0x000C
	float     curTime;                      // 0x0010
	float     frameTime;                    // 0x0014
	int       maxClients;                   // 0x0018
	int       tickCount;                    // 0x001C
	float     intervalPerTick;            // 0x0020
	float     interpolationAmount;         // 0x0024
	int       simTicksThisFrame;            // 0x0028
	int       networkProtocol;             // 0x002C
	void* pSaveData;                    // 0x0030
	bool      m_bClient;                    // 0x0031
	bool      m_bRemoteClient;              // 0x0032
};