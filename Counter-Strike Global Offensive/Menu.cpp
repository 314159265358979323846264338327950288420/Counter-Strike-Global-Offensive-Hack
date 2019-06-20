#include "Includes.h"

cMenu* Menu;
ImFont* Icon;
ImFont* regularFont;

bool menuInfo::menuActive = true;
ImVec2 menuInfo::menuPosition;
int menuInfo::currentTab;

static bool gay2;
void cMenu::Initialize( ) {
	ImGuiStyle& Style = ImGui::GetStyle( );
	ImGuiIO& io = ImGui::GetIO( );

	Style.Colors[ ImGuiCol_WindowBg ] = ImColor( 30, 30, 30, 255 );
	Style.Colors[ ImGuiCol_TitleBg ] = ImColor( 60, 60, 60, 255 );
	Style.Colors[ ImGuiCol_TitleBgActive ] = ImColor( 60, 60, 60, 255 );
	Style.Colors[ ImGuiCol_Border ] = ImColor( 0, 0, 0, 255 );
	Style.Colors[ ImGuiCol_BorderShadow ] = ImColor( 0, 0, 0, 45 );
	Style.Colors[ ImGuiCol_SliderGrabActive ] = ImColor( 185, 185, 185, 255 );
	Style.Colors[ ImGuiCol_FrameBgHovered ] = ImColor( 125, 125, 125, 255 );
	Style.Colors[ ImGuiCol_FrameBgActive ] = ImColor( 125, 125, 125, 255 );
	Style.Colors[ ImGuiCol_ChildWindowBg ] = ImColor( 50, 50, 50, 255 );

	Style.Colors[ ImGuiCol_Button ] = ImColor( 70, 70, 70, 255 );
	Style.Colors[ ImGuiCol_ButtonActive ] = ImColor( 90, 90, 90, 255 );
	Style.Colors[ ImGuiCol_ButtonHovered ] = ImColor( 90, 90, 90, 255 );

	Style.Alpha = 1;
	Style.WindowRounding = 0;
	Style.FrameRounding = 0;
	Style.ScrollbarRounding = 0;

	Icon = io.Fonts->AddFontFromFileTTF( "C:\\Windows\\Fonts\\hack-font.ttf", 28 );
	regularFont = io.Fonts->AddFontFromFileTTF( "C:\\Windows\\Fonts\\arial.ttf", 12 );
}
ImFont* Font;

void doTabs( ) {

	ImGuiIO& io = ImGui::GetIO( );

	float Equation = ( 430 /*Window Width*/ / 1 /*Tab Amount*/ ) - 16 /*Compensate for padding*/;
	if ( ImGui::BeginChild( "##Tabs", ImVec2( 0, 0 ), true ) ) {
		if ( ImGui::Button( "B", ImVec2( Equation, 35 ) ) )
			menuInfo::currentTab = 0;

	}ImGui::EndChild( );
}

void cMenu::Run( ) {


	if ( !menuInfo::menuActive )
		return;

	ImVec2 Position;

	ImGui::SetNextWindowSize( ImVec2( 430, 5 ) );

	if ( ImGui::Begin( "##Title", NULL, ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_ShowBorders | ImGuiWindowFlags_NoTitleBar ) ) {

		ImGui::PushFont( regularFont );
		ImGui::Text( "WeebB0t" );
		ImGui::PopFont( );

		Position = ImGui::GetWindowPos( );
	} ImGui::End( );

	ImGui::SetNextWindowSize( ImVec2( 430, 65 ) );
	ImGui::SetNextWindowPos( ImVec2( Position.x, Position.y + 39 ) );

	if ( ImGui::Begin( "##Tabs", NULL, ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_ShowBorders | ImGuiWindowFlags_NoTitleBar ) ) {

		ImGui::PushFont( Icon );
		doTabs( );

		ImGui::PopFont( );
	} ImGui::End( );

	ImGui::PushFont( regularFont );

	ImGui::SetNextWindowSize( ImVec2( 430, 350 ) );
	ImGui::SetNextWindowPos( ImVec2( Position.x, Position.y + 110 ) );

	if ( ImGui::Begin( "WeebB0t", NULL, ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_ShowBorders | ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoMove ) ) {
		ImGui::SetCursorPos( ImVec2( 8, 8 ) );
		menuInfo::menuPosition = ImGui::GetWindowPos( );

		if ( ImGui::BeginChild( "##Options", ImVec2( 0, 0 ), true ) ) {

			ImGui::PushItemWidth( 100 );
			switch ( menuInfo::currentTab ) {
			case 0: {
				ImGui::Checkbox( "Name", &Configuration::Visuals::Player::Name );
				ImGui::Checkbox( "Box", &Configuration::Visuals::Player::Box );
				ImGui::Checkbox( "Health", &Configuration::Visuals::Player::Health );
				ImGui::Checkbox( "Armor", &Configuration::Visuals::Player::Armor );
				ImGui::Checkbox( "Weapon", &Configuration::Visuals::Player::Weapon ); ImGui::SameLine( ); ImGui::Checkbox( "Ammo", &Configuration::Visuals::Player::Ammo );
				ImGui::Checkbox( "Chams", &Configuration::Visuals::Player::Chams::Enabled ); ImGui::SameLine( ); ImGui::Checkbox( "XQZ", &Configuration::Visuals::Player::Chams::XQZ ); ImGui::SameLine( ); ImGui::Checkbox( "Wireframe", &Configuration::Visuals::Player::Chams::Wireframe );
				ImGui::SliderInt( "Field Of View", &Configuration::Visuals::View::Fov, 0, 45 );
				ImGui::SliderInt( "Viewmodel Field Of View", &Configuration::Visuals::View::viewmodelFov, 0, 60 );
			} break;
			case 2: {
				if ( ImGui::Button( "Save" ) ) {
					configurationSystem->Save( );
				}
			}break;
			}
			ImGui::PopItemWidth( );
		}ImGui::EndChild( );


	}ImGui::End( );

	ImGui::PopFont( );
}