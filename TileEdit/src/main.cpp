#include "Application.h"

#include "application/tilemap/MapConstants.h"

int main()
{
	Application* app = Application::CreateApplication(MapConstants::ScreenWidth, MapConstants::ScreenHeight, "SFML3-Game-Framework");
	app->Run();

	delete app;

	return 0;
}
