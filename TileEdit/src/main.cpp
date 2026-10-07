#include "Application.h"

#include "application/tilemap/MapConstants.h"

int main()
{
	Application* app = Application::CreateApplication(MapConstants::ScreenWidth, MapConstants::ScreenHeight, "Map Editor v1.0");
	app->Run();

	delete app;

	return 0;
}
