#pragma once

#ifdef E42_PLATFORM_WINDOWS

extern	Engine42::Application* Engine42::CreateApplication(void);

int	main(void)
{
	auto app = Engine42::CreateApplication();
	app->Run();
	delete app;
	return (0);
}

#endif