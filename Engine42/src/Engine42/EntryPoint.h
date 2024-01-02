#pragma once

#ifdef E42_PLATFORM_WINDOWS

extern	Engine42::Application* Engine42::CreateApplication(void);

int	main(void)
{
	Engine42::Log::Init();
	ENGINE_WARN("Initialized Log!");
	APP_INFO("Hello Var = {}", 5);

	auto app = Engine42::CreateApplication();
	app->Run();
	delete app;
	return (0);
}

#endif