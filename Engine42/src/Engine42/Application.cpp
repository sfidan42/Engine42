#include "Application.h"
#include <iostream>

namespace Engine42
{
	Application::Application(void)
	{
	}
	Application::~Application(void)
	{
	}
	void	Application::Run(void)
	{
		std::cout << "app started" << std::endl;
		std::cout << "app stopped" << std::endl;
	}
}
