class cMenu {
public:
	void Initialize( );
	void Run( );
}; extern cMenu* Menu;

namespace menuInfo {
	extern bool menuActive;
	extern ImVec2 menuPosition;
	extern int currentTab;
}